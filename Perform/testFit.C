{
	gROOT->SetStyle("Plain");
	gStyle->SetPalette(1,0);
	using namespace RooFit;

const double Ks_mass_min = 0.45;
const double Ks_mass_max = 0.55;
const double Lm_mass_min = 1.1;
const double Lm_mass_max = 1.13;

	TGaxis::SetMaxDigits(3);
	RooMsgService::instance().setStreamStatus(0,kFALSE);
	RooMsgService::instance().setStreamStatus(1,kFALSE);

	TFile * f = new TFile("PbPb_Ks11_NoffAll.root");
	TH1D * hMass = (TH1D*) f->Get("hMass");

	TCanvas * cMass = new TCanvas("cMass", "cMass", 500, 500);
	TCanvas * cResd = new TCanvas("cResd", "cResd", 500, 500);
	TCanvas * cPull = new TCanvas("cPull", "cPull", 500, 500);

	bool bKs = (string(f->GetName()).find("Lm") == std::string::npos);

	RooRealVar *x;
	RooRealVar *mean;

	TH2D * hframe_ratio;
	TH2D * hframe_pull;

	if ( bKs ) {
		hframe_ratio = new TH2D("hframe_ratio", "", 1, 0.43, 0.565, 1, 0.2, 1.8);
//		InitHist2(hframe_ratio, "Mass", "Ratio");

		hframe_pull = new TH2D("hframe_pull", "", 1, 0.43, 0.565, 1, -25, 25);
//		InitHist2(hframe_pull, "Mass #pi+#pi (GeV)", "Pull");

		x = new RooRealVar("x","mass",0.43,0.565);
		x->setRange("cut",Ks_mass_min,Ks_mass_max);

		mean = new RooRealVar("mean","mean",0.497611,0.49,0.51);
	} else {
		hframe_ratio = new TH2D("hframe_ratio", "", 1, 1.08, 1.16, 1, 0.2, 1.8);
//		InitHist2(hframe_ratio, "Mass", "Ratio");

		hframe_pull = new TH2D("hframe_pull", "", 1, 1.08, 1.16, 1, -25, 25);
//		InitHist2(hframe_pull, "Mass #pi+p (GeV)", "Pull");

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
	//RooChebychev poly("poly","poly",*x,RooArgList(ap,bp));

	RooRealVar polysig("polysig","polysig",4e6,0,100000000);

	RooAddPdf sum("sum","sum",RooArgList(gaus1,gaus2,poly),RooArgList(sig1,sig2,polysig));

	RooFitResult* r_ks = sum.fitTo(data,Save(),Minos(kTRUE),Range("cut"));

	RooPlot* xframe_ks = x->frame();
	data.plotOn(xframe_ks,Name("data"));
	sum.plotOn(xframe_ks,Components(gaus1),NormRange("cut"),LineStyle(kDashed),LineWidth(2),LineColor(kRed));
	sum.plotOn(xframe_ks,Components(gaus2),NormRange("cut"),LineStyle(kDashed),LineWidth(2),LineColor(kGreen));
	sum.plotOn(xframe_ks,Components(poly),NormRange("cut"),LineStyle(kDashed),LineWidth(2),LineColor(kBlue));
	sum.plotOn(xframe_ks,Name("sum"),NormRange("cut"),LineWidth(2),LineColor(kBlue));

	cMass->cd();
	xframe_ks->Draw();

	cResd->cd();
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

	cPull->cd();
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

//	cMass->cd(1);
//	latexS.DrawLatexNDC(0.18, 0.9, system.c_str());
//	latexS.DrawLatexNDC(0.18, 0.8, item.second.c_str());
//	latexS.DrawLatexNDC(0.18, 0.7, Form("%.1f< p_{T} < %.1f GeV", vpt[i], vpt[i+1]));
//
//	latexS.DrawLatexNDC(0.6, 0.9, Form("#chi^{2}/ndf = %.1f/%d", chi2, hpull->GetN() - ndf + 1) );
//
//	cMass->SaveAs(Form("fit_%s_%d.pdf", s.c_str(), i));

	cout << "mean = " << mean->getVal() << endl;
	cout << "sigma1 = " << sigma1.getVal() << endl;
	cout << "sigma2 = " << sigma2.getVal() << endl;
	cout << "sig1 = " << sig1.getVal() << endl;
	cout << "sig2 = " << sig2.getVal() << endl;
	cout << "ap = " << ap.getVal() << endl;
	cout << "bp = " << bp.getVal() << endl;
	cout << "cp = " << cp.getVal() << endl;
	cout << "dp = " << dp.getVal() << endl;
	cout << "polysig = " << polysig.getVal() << endl;
	cout << "chi2 = " << chi2 << endl;

	x->setRange("peak", 0.492, 0.503);
	RooAbsReal* IntG1 = gaus1.createIntegral(*x, *x, "peak");
	RooAbsReal* IntG2 = gaus2.createIntegral(*x, *x, "peak");
	RooAbsReal* IntPl = poly.createIntegral(*x, *x, "peak");

	double yield = sig1.getVal() * IntG1->getVal() + sig2.getVal() * IntG2->getVal();
	double tot = sig1.getVal() * IntG1->getVal() + sig2.getVal() * IntG2->getVal() + polysig.getVal() * IntPl->getVal();

	cout << "yield = " << yield << endl;
	cout << "tot = " << tot << endl;
	cout << "Fsig = " << yield/tot << endl;
}

