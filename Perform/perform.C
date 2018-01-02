#include "../../../style.h"


void splitCanv(TCanvas *);
void InitHist2(TH1*, const char *xtit, const char *ytit  = "Number of Entries", EColor      color = kBlack);

const double Ks_mass_min = 0.45;
const double Ks_mass_max = 0.55;
const double Lm_mass_min = 1.1;
const double Lm_mass_max = 1.13;

//void perform(string fname = "pPb16_V0_HM2_v4.root",
//		string system = "pPb 8.16 TeV"
//		)
void perform(string fname = "PbPb15_V0_ppRecoGMO567_v4.root",
		string system = "PbPb 5.02 TeV"
		)
{
	using namespace RooFit;
	TFile * f = new TFile(fname.c_str());

	TFile * fsave = new TFile("fits.root", "recreate");

	TGaxis::SetMaxDigits(3);
	RooMsgService::instance().setStreamStatus(0,kFALSE);
	RooMsgService::instance().setStreamStatus(1,kFALSE);

	TLatex latexS;
	latexS.SetTextFont(43);
	latexS.SetTextSize(22);
	latexS.SetTextAlign(13);

//	string dir[] = {
//		"vectKsMassN120",
//		"vectKsMassN150",
//		"vectKsMassN185",
//		"vectKsMassN250",
//		"vectLmMassN120",
//		"vectLmMassN150",
//		"vectLmMassN185",
//		"vectLmMassN250",
//	};

	std::map<string, string> noff_map = {
		{"vectKsMassN120", "120 #leq N_{trk}^{offline} < 150"},
		{"vectKsMassN150", "150 #leq N_{trk}^{offline} < 185"},
		{"vectKsMassN185", "185 #leq N_{trk}^{offline} < 250"},
		{"vectKsMassN250", "250 #leq N_{trk}^{offline} < 320"},
		{"vectLmMassN120", "120 #leq N_{trk}^{offline} < 150"},
		{"vectLmMassN150", "150 #leq N_{trk}^{offline} < 185"},
		{"vectLmMassN185", "185 #leq N_{trk}^{offline} < 250"},
		{"vectLmMassN250", "250 #leq N_{trk}^{offline} < 320"},
	};

	vector<double> vpt{
		0.2, // 0
		0.4, // 1
		0.6, // 2
		0.8, // 3
		1.0, // 4
		1.4, // 5
		1.8, // 6
		2.2, // 7
		2.8, // 8
		3.6, // 9
		4.6, // 10
		6.0, // 11
		7.0, // 12
		8.5  // 13
	};

	TCanvas * cMass = MakeCanvas("cMass", "cMass", 600, 800);
	splitCanv(cMass);
//	TCanvas * cEta = MakeCanvas("cEta", "cEta", 500, 500);
//	TCanvas * cPhi = MakeCanvas("cPhi", "cPhi", 500, 500);
//	cMass->SetLogy();

	for ( auto item : noff_map ) {
		string s = item.first;
		TDirectory * dir = (TDirectory*) f->Get(s.c_str());
		if ( dir == nullptr ) continue;
		bool bKs = (s.find("Lm") == std::string::npos);
		TH2D * hframe_ratio;
		TH2D * hframe_pull;
		if ( bKs ) {
			hframe_ratio = new TH2D("hframe_ratio", "", 1, 0.43, 0.565, 1, 0.2, 1.8);
			InitHist2(hframe_ratio, "Mass", "Ratio");

			hframe_pull = new TH2D("hframe_pull", "", 1, 0.43, 0.565, 1, -25, 25);
			InitHist2(hframe_pull, "Mass #pi+#pi (GeV)", "Pull");
		} else {
			hframe_ratio = new TH2D("hframe_ratio", "", 1, 1.08, 1.16, 1, 0.2, 1.8);
			InitHist2(hframe_ratio, "Mass", "Ratio");

			hframe_pull = new TH2D("hframe_pull", "", 1, 1.08, 1.16, 1, -25, 25);
			InitHist2(hframe_pull, "Mass #pi+p (GeV)", "Pull");
		}
		for ( int i = 0; i < 13; i++ ) {
			if ( not bKs and i < 3 ) continue;
			std::ofstream myfile;
			myfile.open(s + "_" + to_string(i) + ".txt");
			TH3D * h3D = (TH3D*) f->Get(Form("%s/h3DPhi_%i", s.c_str(), i));
			// h3D(mass, phi, eta)
			//MakeHist(hMass, "Mass (GeV)", "count");
			TH1D * hMass = (TH1D*) h3D->ProjectionX(Form("hMass_%i", i));

			RooRealVar *x;
			RooRealVar *mean;

			if ( bKs ) {
				x = new RooRealVar("x","mass",0.43,0.565);
				x->setRange("cut",Ks_mass_min,Ks_mass_max);
				mean = new RooRealVar("mean","mean",0.4976,0.49,0.51);
			} else {
				x = new RooRealVar("x","mass",1.08,1.16);
				x->setRange("cut",Lm_mass_min,Lm_mass_max);

				mean = new RooRealVar("mean","mean",1.115,1.10,1.13);
			}

			RooRealVar sigma1("sigma1","sigma1",0.005,0.001,0.01);
			RooRealVar sigma2("sigma2","sigma2",0.005,0.0001,0.01);

			RooRealVar sig1("sig1","signal1",4e4,0,100000000);
			RooRealVar sig2("sig2","signal2",4e4,0,100000000);

			RooGaussian gaus1("gaus1","gaus1",*x,*mean,sigma1);
			RooGaussian gaus2("gaus2","gaus2",*x,*mean,sigma2);

			RooDataHist data("data","dataset",*x,hMass);

			RooRealVar ap("ap","ap",0   , -5, 5);
			RooRealVar bp("bp","bp",0.1 , -5, 5);
			RooRealVar cp("cp","cp",-0.1, -5, 5);
			RooRealVar dp("dp","dp",0.1 , -5, 5);
			RooChebychev poly("poly","poly",*x,RooArgList(ap,bp,cp,dp));

			RooRealVar polysig("polysig","polysig",4e6,0,10000000);

			RooAddPdf sum("sum","sum",RooArgList(gaus1,gaus2,poly),RooArgList(sig1,sig2,polysig));

			RooFitResult* r_ks = sum.fitTo(data,Save(),Minos(kTRUE),Range("cut"));

			RooPlot* xframe_ks = x->frame();
			data.plotOn(xframe_ks,Name("data"));
			sum.plotOn(xframe_ks,Components(gaus1),NormRange("cut"),LineStyle(kDashed),LineWidth(2),LineColor(kRed));
			sum.plotOn(xframe_ks,Components(gaus2),NormRange("cut"),LineStyle(kDashed),LineWidth(2),LineColor(kGreen));
			sum.plotOn(xframe_ks,Components(poly),NormRange("cut"),LineStyle(kDashed),LineWidth(2),LineColor(kBlue));
			sum.plotOn(xframe_ks,Name("sum"),NormRange("cut"),LineWidth(2),LineColor(kBlue));

			cMass->cd(1);
			xframe_ks->Draw();

			cMass->cd(2);
			RooPlot* frame_res = x->frame(Title("Ratio Distribution"));
			RooCurve * sumCurv = xframe_ks->getCurve("sum");

			for ( int i = 1; i <= hMass->GetNbinsX(); i++ ) {
				hMass->SetBinContent(i, hMass->GetBinContent(i)/sumCurv->Eval(hMass->GetBinCenter(i)));
			}
//			InitHist2(hMass, "Mass", "Ratio");
			hMass->SetMarkerStyle(kFullCircle);
//			hMass->SetMaximum(1.8);
			hframe_ratio->Draw();
			hMass->Draw("Psame");

//			RooHist* hresid = xframe_ks->residHist();
//			frame_res->addPlotable(hMass,"P");
//			frame_res->Draw();

			cMass->cd(3);
			RooHist* hpull = xframe_ks->pullHist() ;
//			RooPlot* frame_pull = x->frame(Title("Pull Distribution")) ;
//			MakeHist(hpull, "Mass (GeV)", "Pull");
//			hpull->SetMinimum(-25.);
//			hpull->SetMaximum(25.);
//			hpull->Draw("ap");
//			frame_pull->addPlotable(hpull,"P") ;
//			frame_pull->SetMinimum(-80);
//			frame_pull->SetMaximum(80);
//			frame_pull->Draw();

			hframe_pull->Draw();
			hpull->Draw("Psame");

			cMass->cd(1);
			latexS.DrawLatexNDC(0.18, 0.9, system.c_str());
			latexS.DrawLatexNDC(0.18, 0.8, item.second.c_str());
			latexS.DrawLatexNDC(0.18, 0.7, Form("%.1f< p_{T} < %.1f GeV", vpt[i], vpt[i+1]));

			cMass->SaveAs(Form("fit_%s_%d.pdf", s.c_str(), i));

			myfile << " =============== " << s << " ================ " << endl;
			myfile << "ipt = " << i << endl;
			myfile << "mean = " << mean->getVal() << endl;
			myfile << "sigma1 = " << sigma1.getVal() << endl;
			myfile << "sigma2 = " << sigma2.getVal() << endl;
			myfile << "sig1 = " << sig1.getVal() << endl;
			myfile << "sig2 = " << sig2.getVal() << endl;
			myfile << "ap = " << ap.getVal() << endl;
			myfile << "bp = " << bp.getVal() << endl;
			myfile << "cp = " << cp.getVal() << endl;
			myfile << "dp = " << dp.getVal() << endl;
			myfile << "polysig = " << polysig.getVal() << endl;
		}
	}

}

void splitCanv(TCanvas * c)
{
	if (!c) return;

	c->cd(0);
	TPad * p1 = new TPad("pad1", "", 0., 0.45, 1., 1.);
	p1->SetLeftMargin(0.15);
	p1->SetRightMargin(0.05);
	p1->SetBottomMargin(0.);
	p1->SetTopMargin(0.07);
	p1->Draw();
	p1->SetNumber(1);

	TPad * p2 = new TPad("pad2", "", 0., 0.25, 1., 0.45);
	p2->SetLeftMargin(0.15);
	p2->SetRightMargin(0.05);
	p2->SetBottomMargin(0.);
	p2->SetTopMargin(0.);
	p2->SetGrid();
	p2->Draw();
	p2->SetNumber(2);

	TPad * p3 = new TPad("pad3", "", 0., 0.0, 1., 0.25);
	p3->SetLeftMargin(0.15);
	p3->SetRightMargin(0.05);
	p3->SetBottomMargin(0.25);
	p3->SetTopMargin(0.);
	p3->SetGrid();
	p3->Draw();
	p3->SetNumber(3);
}

void InitHist2(TH1        *hist,
	      const char *xtit,
	      const char *ytit  = "Number of Entries",
	      EColor      color = kBlack)
{
  hist->SetXTitle(xtit);
  hist->SetYTitle(ytit);
  hist->SetLineColor(color);
  hist->SetMarkerStyle(20);
  hist->SetMarkerColor(color);
  hist->SetMarkerSize (1.);
  // Strangely enough this cannot be set anywhere else??
  hist->GetXaxis()->CenterTitle();
  hist->GetXaxis()->SetTitleFont(42);
  hist->GetXaxis()->SetTitleOffset(1.1);
  hist->GetXaxis()->SetTitleSize(0.1);
  hist->GetXaxis()->SetLabelOffset(0.03);
  hist->GetXaxis()->SetLabelSize(0.10);

  hist->GetYaxis()->CenterTitle();
  hist->GetYaxis()->SetTitleFont(42);
  hist->GetYaxis()->SetTitleOffset(0.7);
  hist->GetYaxis()->SetTitleSize(0.1);
  hist->GetYaxis()->SetLabelOffset(0.03);
  hist->GetYaxis()->SetLabelSize(0.10);

  hist->SetTitle("");
  return;
}

