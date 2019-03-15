#include "../../../style.h"
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooGaussian.h"
#include "RooPlot.h"

const double Ks_mass_min = 0.45;
const double Ks_mass_max = 0.55;
const double Lm_mass_min = 1.10;
const double Lm_mass_max = 1.14;

void splitCanv(TCanvas *);
void InitHist2(TH1*, const char *xtit, const char *ytit  = "Number of Entries", EColor      color = kBlack);

void HistPerform(TH1D* hMass)
{
	using namespace RooFit;
	RooMsgService::instance().setStreamStatus(0,kFALSE);
	RooMsgService::instance().setStreamStatus(1,kFALSE);

	TLatex latexS;
	latexS.SetTextFont(43);
	latexS.SetTextSize(22);
	latexS.SetTextAlign(13);

	TCanvas * cMass = MakeCanvas("cMass", "cMass", 600, 800);
	splitCanv(cMass);

	TH2D * hframe_ratio;
	TH2D * hframe_pull;

	hframe_ratio = new TH2D("hframe_ratio", "", 1, 1.08, 1.16, 1, 0.2, 1.8);
	InitHist2(hframe_ratio, "Mass", "Ratio");
	hframe_pull = new TH2D("hframe_pull", "", 1, 1.08, 1.16, 1, -25, 25);
	InitHist2(hframe_pull, "Mass #pi+p (GeV)", "Pull");

	// RooFit
	RooRealVar x("x","mass",1.08,1.16);
	RooRealVar mean("mean","mean",1.115683, 1.10, 1.13);
//	x.setRange("cut", Lm_mass_min, Lm_mass_max);
	x.setRange("cut", 1.08, 1.16);

	RooRealVar sigma1("sigma1", "sigma1", 0.0025, 0.00001, 0.1);
	RooRealVar sigma2("sigma2", "sigma2", 0.0012, 0.00001, 0.1);
	RooRealVar sig1("sig1", "signal1", 10., 0., 1000000);
	RooRealVar sig2("sig2", "signal2", 10., 0., 1000000);

	RooGaussian gaus1("gaus1", "gaus1", x, mean, sigma1);
	RooGaussian gaus2("gaus2", "gaus2", x, mean, sigma2);

	RooDataHist data("data", "dataset", x, Import(*hMass));

	RooRealVar ap("ap", "ap", 1. , -5, 5);
	RooRealVar bp("bp", "bp", 1. , -5, 5);
	RooRealVar cp("cp", "cp", 1. , -5, 5);
	RooRealVar dp("dp", "dp", 1. , -5, 5);
//	RooChebychev poly("poly", "poly", x, RooArgList(ap,bp,cp,dp));
	RooPolynomial poly("poly", "poly", x, RooArgList(ap,bp,cp));
	RooRealVar polysig("polysig", "polysig", 10, 0,10000000);

	RooAddPdf sum("sum", "sum", RooArgList(gaus1,gaus2,poly),RooArgList(sig1,sig2,polysig));

	RooFitResult* result = sum.fitTo(data,Save(),Minos(kTRUE),Range("cut"));

	RooPlot* xframe_ks = x.frame();
	data.plotOn(xframe_ks,Name("data"));
	sum.plotOn(xframe_ks,Components(gaus1),NormRange("cut"),LineStyle(kDashed),LineWidth(2),LineColor(kRed));
	sum.plotOn(xframe_ks,Components(gaus2),NormRange("cut"),LineStyle(kDashed),LineWidth(2),LineColor(kGreen));
	sum.plotOn(xframe_ks,Components(poly),NormRange("cut"),LineStyle(kDashed),LineWidth(2),LineColor(kBlue));
	sum.plotOn(xframe_ks,Name("sum"),NormRange("cut"),LineWidth(2),LineColor(kBlue));

	cMass->cd(1);
	xframe_ks->Draw();

	cMass->cd(2);
	RooPlot* frame_res = x.frame(Title("Ratio Distribution"));
	RooCurve * sumCurv = xframe_ks->getCurve("sum");

	for ( int i = 1; i <= hMass->GetNbinsX(); i++ ) {
		hMass->SetBinContent(i, hMass->GetBinContent(i)/sumCurv->Eval(hMass->GetBinCenter(i)));
	}
	hMass->SetMarkerStyle(kFullCircle);
	hframe_ratio->Draw();
	hMass->Draw("Psame");

	cMass->cd(3);
	RooHist* hpull = xframe_ks->pullHist() ;
	hframe_pull->Draw();
	hpull->Draw("Psame");
	double chi2 = 0.;
	for ( int ibin = 0; ibin < hpull->GetN(); ibin++ ) {
		chi2 += hpull->GetY()[ibin]*hpull->GetY()[ibin];
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

