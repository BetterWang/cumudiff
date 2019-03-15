#include "../../../style.h"


void splitCanv(TCanvas *);
void InitHist2(TH1*, const char *xtit, const char *ytit  = "Number of Entries", EColor      color = kBlack);

const double Ks_mass_min = 0.45;
const double Ks_mass_max = 0.55;
//const double Ks_mass_min = 0.43;
//const double Ks_mass_max = 0.565;
const double Lm_mass_min = 1.10;
const double Lm_mass_max = 1.14;


void perform2018(string fname = "PbPb15_V0_ppRecoGMO567_v4.root",
		string system = "PbPb 5.02 TeV",
		double etaMin = -2.4,
		double etaMax = 2.4,
		string ss = "all",
		int ipt = -1
		)
{
	int ndf = 10;
	const double * dbLm_sig1 ;
	const double * dbLm_sig2 ;
	const double * dbLm_sigp ;
	const double * dbLm_ap   ;
	const double * dbLm_bp   ;
	const double * dbLm_cp   ;
	const double * dbLm_dp   ;

	const double * dbKs_sig1 ;
	const double * dbKs_sig2 ;
	const double * dbKs_sigp ;
	const double * dbKs_ap   ;
	const double * dbKs_bp   ;
	const double * dbKs_cp   ;
	const double * dbKs_dp   ;

	gROOT->SetStyle("Plain");
	gStyle->SetPalette(1,0);
	using namespace RooFit;
	TFile * f = new TFile(fname.c_str());

	TGaxis::SetMaxDigits(3);
	RooMsgService::instance().setStreamStatus(0,kFALSE);
	RooMsgService::instance().setStreamStatus(1,kFALSE);

	TLatex latexS;
	latexS.SetTextFont(43);
	latexS.SetTextSize(22);
	latexS.SetTextAlign(13);

	std::map<string, string> noff_map = {
		{"vectKsMassN0",  "0-10%"},
		{"vectLmMassN0",  "0-10%"},
		{"vectKsMassN10", "10-30%"},
		{"vectLmMassN10", "10-30%"},
		{"vectKsMassN30", "30-50%"},
		{"vectLmMassN30", "30-50%"},
		{"vectKsMassN50", "50-70%"},
		{"vectLmMassN50", "50-70%"},
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
	TCanvas * cEtaPhi = MakeCanvas("cEtaPhi", "cEtaPhi", 500, 500);
	TCanvas * cM1 = MakeCanvas("cM", "cM", 600, 400);

	for ( auto item : noff_map ) {
		string s = item.first;
		if ( ss != "all" and s != ss ) continue;
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
//		fsave->mkdir(s.c_str());
//		fsave->cd(s.c_str());
//		TH1D * hmean = new TH1D("hmean", "hmean", 13, 0, 13);
//		TH1D * hsigma1 = new TH1D("hsigma1", "hsigma1", 13, 0, 13);
//		TH1D * hsigma2 = new TH1D("hsigma2", "hsigma2", 13, 0, 13);
//		TH1D * hsigmaS = new TH1D("hsigmaS", "hsigmaS", 13, 0, 13);
//		TH1D * hsig1 = new TH1D("hsig1", "hsig1", 13, 0, 13);
//		TH1D * hsig2 = new TH1D("hsig2", "hsig2", 13, 0, 13);
//		TH1D * hap = new TH1D("hap", "hap", 13, 0, 13);
//		TH1D * hbp = new TH1D("hbp", "hbp", 13, 0, 13);
//		TH1D * hcp = new TH1D("hcp", "hcp", 13, 0, 13);
//		TH1D * hdp = new TH1D("hdp", "hdp", 13, 0, 13);
//		TH1D * hpolysig = new TH1D("hpolysig", "hpolysig", 13, 0, 13);
		for ( int i = 0; i < 13; i++ ) {
			if ( ipt >= 0 and i != ipt ) continue;
			if ( not bKs and i < 3 ) continue;
			std::ofstream myfile;
			myfile.open(ss + ".csv", ios_base::app);
			TH3D * h3D = (TH3D*) f->Get(Form("%s/h3DPhi_%i", s.c_str(), i));
			// h3D(mass, phi, eta)
			//MakeHist(hMass, "Mass (GeV)", "count");
			TAxis * aEta = h3D->GetZaxis();
			TH1D * hMass = (TH1D*) h3D->ProjectionX(Form("hMass_%i", i), 0, -1, aEta->FindBin(etaMin), aEta->FindBin(etaMax)-1 );
			TH2D * hEtaPhi = (TH2D*) h3D->Project3D("yz");
			cEtaPhi->cd();
			hEtaPhi->Draw("colz");
			cEtaPhi->SaveAs(Form("acc_%s_%d.pdf", s.c_str(), i));

			cout << "  -->  " << __LINE__ << endl;

			RooRealVar x(Form("x_%i", i),"mass",bKs?0.43:1.08,bKs?0.565:1.16);
			RooRealVar mean(Form("mean_%i", i),"mean",bKs?0.497611:1.115683,bKs?0.49:1.10,bKs?0.51:1.13);
			x.setRange("cut", bKs?Ks_mass_min:Lm_mass_min, bKs?Ks_mass_max:Lm_mass_max);

			cout << "  -->  " << __LINE__ << endl;

			RooRealVar sigma1(Form("sigma1_%i", i),"sigma1",bKs?0.0075:0.0025,  0.001, 0.1);
			RooRealVar sigma2(Form("sigma2_%i", i),"sigma2",bKs?0.0035:0.0012, 0.0001, 0.1);

			cout << "  -->  " << __LINE__ << endl;
			RooRealVar sig1(Form("sig1_%i", i),"signal1", bKs?dbKs_sig1[i]:dbLm_sig1[i], 0, 100*(bKs?dbKs_sig1[i]:dbLm_sig1[i]));
			RooRealVar sig2(Form("sig2_%i", i),"signal2", bKs?dbKs_sig2[i]:dbLm_sig2[i], 0, 100*(bKs?dbKs_sig2[i]:dbLm_sig2[i]));

			cout << "  -->  " << __LINE__ << endl;
			RooGaussian gaus1(Form("gaus1_%i", i),"gaus1",x,mean,sigma1);
			RooGaussian gaus2(Form("gaus2_%i", i),"gaus2",x,mean,sigma2);

			cout << "  -->  " << __LINE__ << endl;
			RooDataHist data(Form("data_%i", i),"dataset",x,hMass);

			cout << "  -->  " << __LINE__ << endl;
			RooRealVar ap(Form("ap_%i", i),"ap", 1, -5, 5);
			RooRealVar bp(Form("bp_%i", i),"bp", 1, -5, 5);
			RooRealVar cp(Form("cp_%i", i),"cp", 1, -5, 5);
			RooRealVar dp(Form("dp_%i", i),"dp", 1, -5, 5);
			RooChebychev poly(Form("poly_%i", i),"poly",x,RooArgList(ap,bp,cp,dp));

			RooRealVar polysig(Form("polysig_%i", i),"polysig", 0,100000);

			cout << "  -->  " << __LINE__ << endl;
			RooAddPdf sum(Form("sum_%i", i),"sum",RooArgList(gaus1,gaus2,poly),RooArgList(sig1,sig2,polysig));

			cout << "  -->  " << __LINE__ << endl;
//			sum.fitTo(data,Save(kFALSE),Minos(kTRUE),Range("cut"));
			RooFitResult* result = sum.fitTo(data,Save(),Minos(kTRUE),Range("cut"));

			cout << "  -->  " << __LINE__ << endl;
			RooPlot* xframe_ks = x.frame();
			data.plotOn(xframe_ks,Name("data"));
			sum.plotOn(xframe_ks,Components(gaus1),NormRange("cut"),LineStyle(kDashed),LineWidth(2),LineColor(kRed));
			sum.plotOn(xframe_ks,Components(gaus2),NormRange("cut"),LineStyle(kDashed),LineWidth(2),LineColor(kGreen));
			sum.plotOn(xframe_ks,Components(poly),NormRange("cut"),LineStyle(kDashed),LineWidth(2),LineColor(kBlue));
			sum.plotOn(xframe_ks,Name("sum"),NormRange("cut"),LineWidth(2),LineColor(kBlue));

			cout << "  -->  " << __LINE__ << endl;
			cMass->cd(1);
			xframe_ks->Draw();

			cout << "  -->  " << __LINE__ << endl;
			cM1->cd();
			cM1->SetLeftMargin(0.12);
			xframe_ks->Draw();

			cout << "  -->  " << __LINE__ << endl;
			cMass->cd(2);
			RooPlot* frame_res = x.frame(Title("Ratio Distribution"));
			RooCurve * sumCurv = xframe_ks->getCurve("sum");

			cout << "  -->  " << __LINE__ << endl;
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
			double chi2 = 0.;
//			cout << " !!! hpull->GetN() = " << hpull->GetN() << endl;
			for ( int ibin = 0; ibin < hpull->GetN(); ibin++ ) {
				chi2 += hpull->GetY()[ibin]*hpull->GetY()[ibin];
			}

			cMass->cd(1);
			latexS.DrawLatexNDC(0.18, 0.9, system.c_str());
			latexS.DrawLatexNDC(0.18, 0.8, item.second.c_str());
			latexS.DrawLatexNDC(0.18, 0.7, Form("%.1f< p_{T} < %.1f GeV", vpt[i], vpt[i+1]));

			latexS.DrawLatexNDC(0.6, 0.9, Form("#chi^{2}/ndf = %.1f/%d", chi2, hpull->GetN() - ndf + 1) );
			latexS.DrawLatexNDC(0.6, 0.8, Form("covQual = %d", result->covQual()) );


			cM1->cd();
			latexS.DrawLatexNDC(0.16, 0.9, system.c_str());
			latexS.DrawLatexNDC(0.16, 0.8, item.second.c_str());
			latexS.DrawLatexNDC(0.16, 0.7, Form("%.1f< p_{T} < %.1f GeV", vpt[i], vpt[i+1]));

//			latexS.DrawLatexNDC(0.6, 0.9, Form("#chi^{2}/ndf = %.1f/%d", chi2, hpull->GetN() - ndf + 1) );
//			latexS.DrawLatexNDC(0.6, 0.8, Form("covQual = %d", result->covQual()) );

			cMass->cd(1);
			TLine *massl = new TLine(bKs?0.492:1.1115, 0, bKs?0.492:1.1115, 1000000);
			TLine *massh = new TLine(bKs?0.503:1.1200, 0, bKs?0.503:1.1200, 1000000);
			massl->Draw("same");
			massh->Draw("same");


			cMass->SaveAs(Form("fit_%s_%d.pdf", s.c_str(), i));
			cM1->SaveAs(Form("mass_%s_%d.pdf", s.c_str(), i));

			x.setRange("peak", bKs?0.492:1.1115, bKs?0.503:1.1200);

			RooAbsReal* IntG1 = gaus1.createIntegral(x, x, "peak");
			RooAbsReal* IntG2 = gaus2.createIntegral(x, x, "peak");
			RooAbsReal* IntPl = poly.createIntegral(x, x, "peak");

			double yield = sig1.getVal() * IntG1->getVal() + sig2.getVal() * IntG2->getVal();
			double tot = sig1.getVal() * IntG1->getVal() + sig2.getVal() * IntG2->getVal() + polysig.getVal() * IntPl->getVal();

			myfile << i << ",";
			myfile << mean.getVal() << ",";
			myfile << sigma1.getVal() << ",";
			myfile << sigma2.getVal() << ",";
			myfile << sig1.getVal() << ",";
			myfile << sig2.getVal() << ",";
			myfile << ap.getVal() << ",";
			myfile << bp.getVal() << ",";
			myfile << cp.getVal() << ",";
			myfile << dp.getVal() << ",";
			myfile << polysig.getVal() << ",";
			myfile << chi2 << ",";
			myfile << hpull->GetN() - ndf + 1<< ",";
			myfile << yield << ",";
			myfile << tot << ",";
			myfile << yield/tot << ",";
			myfile << result->covQual() << endl;
			myfile.close();

//			hmean->SetBinContent(i+1, mean.getVal());
//			hmean->SetBinError  (i+1, mean.getError());
//
//			if ( sig1.getVal() > sig2.getVal() ) {
//				hsigma1->SetBinContent(i+1, sigma1.getVal());
//				hsigma1->SetBinError  (i+1, sigma1.getError());
//				hsigma2->SetBinContent(i+1, sigma2.getVal());
//				hsigma2->SetBinError  (i+1, sigma2.getError());
//
//				hsig1->SetBinContent(i+1, sig1.getVal());
//				hsig1->SetBinError  (i+1, sig1.getError());
//				hsig2->SetBinContent(i+1, sig2.getVal());
//				hsig2->SetBinError  (i+1, sig2.getError());
//			} else {
//				hsigma1->SetBinContent(i+1, sigma2.getVal());
//				hsigma1->SetBinError  (i+1, sigma2.getError());
//				hsigma2->SetBinContent(i+1, sigma1.getVal());
//				hsigma2->SetBinError  (i+1, sigma1.getError());
//
//				hsig1->SetBinContent(i+1, sig2.getVal());
//				hsig1->SetBinError  (i+1, sig2.getError());
//				hsig2->SetBinContent(i+1, sig1.getVal());
//				hsig2->SetBinError  (i+1, sig1.getError());
//			}
//			hap->SetBinContent(i+1, ap.getVal());
//			hap->SetBinError  (i+1, ap.getError());
//			hbp->SetBinContent(i+1, bp.getVal());
//			hbp->SetBinError  (i+1, bp.getError());
//			hcp->SetBinContent(i+1, cp.getVal());
//			hcp->SetBinError  (i+1, cp.getError());
//			hdp->SetBinContent(i+1, dp.getVal());
//			hdp->SetBinError  (i+1, dp.getError());
//
//			hsigmaS->SetBinContent(i+1, sqrt( (sig1.getVal()*sigma1.getVal()*sigma1.getVal() + sig2.getVal()*sigma2.getVal()*sigma2.getVal())/(sig1.getVal() + sig2.getVal()) ) );
//
//			hpolysig->SetBinContent(i+1, polysig.getVal());
//			hpolysig->SetBinError  (i+1, polysig.getError());
		}
//		hmean->Write();
//		hsigma1->Write();
//		hsigma2->Write();
//		hsigmaS->Write();
//		hsig1->Write();
//		hsig2->Write();
//		hap->Write();
//		hbp->Write();
//		hcp->Write();
//		hdp->Write();
//		hpolysig->Write();
//		fsave->cd("/");
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
//	p1->SetLogy();
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

