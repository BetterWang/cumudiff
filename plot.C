#include "../../style.h"
#include "HIN-14-002.h"


void plot(TString s = "grVn_std.root", int c = 6)
{
	TFile * f = new TFile(s);
	bool bPbPb = false;
	if ( s.Contains("PbPb") ) bPbPb = true;

	HIN_14_002();

	unordered_map<int, TString> sNoff = {
		{6, "120 #leq N_{trk}^{offline} < 150"},
		{7, "150 #leq N_{trk}^{offline} < 185"},
		{8, "185 #leq N_{trk}^{offline} < 220"},
		{9, "220 #leq N_{trk}^{offline} < 250"},
		{10, "250 #leq N_{trk}^{offline} < 300"},
	};
	TGraphErrors * grVnKsGap[7][20] = {};
	TGraphErrors * grVnLmGap[7][20] = {};
	TGraphErrors * grVnGap[7][20] = {};

	TGraphErrors * grVnKs[7][4][20] = {};
	TGraphErrors * grVnLm[7][4][20] = {};


	for ( int n = 2; n < 7; n++ ) {
		for ( int c = 6; c < 11; c++ ) {
			grVnKsGap[n][c] = (TGraphErrors*) f->Get(Form("grKsGap%i_%i", n, c));
			grVnLmGap[n][c] = (TGraphErrors*) f->Get(Form("grLmGap%i_%i", n, c));
			grVnGap[n][c] = (TGraphErrors*) f->Get(Form("grHKsGap%i_%i", n, c));

			grVnKsGap[n][c]->SetMarkerStyle(kOpenSquare);
			grVnKsGap[n][c]->SetMarkerColor(kBlue);
			grVnKsGap[n][c]->SetLineColor(kBlue);
			grVnKsGap[n][c]->SetMarkerSize(2);

			grVnLmGap[n][c]->SetMarkerStyle(kOpenCircle);
			grVnLmGap[n][c]->SetMarkerColor(kRed);
			grVnLmGap[n][c]->SetLineColor(kRed);
			grVnLmGap[n][c]->SetMarkerSize(2);

			grVnGap[n][c]->SetMarkerStyle(kOpenCross);
			grVnGap[n][c]->SetMarkerColor(kBlack);
			grVnGap[n][c]->SetLineColor(kBlack);
			grVnGap[n][c]->SetMarkerSize(2);

			for ( int np = 0; np < 4; np++ ) {
				grVnKs[n][np][c] = (TGraphErrors*) f->Get(Form("grKs%i%i_%i", n, np, c));
				grVnLm[n][np][c] = (TGraphErrors*) f->Get(Form("grLm%i%i_%i", n, np, c));

				grVnKs[n][np][c]->SetMarkerStyle(kFullSquare);
				grVnKs[n][np][c]->SetMarkerColor(kBlue);
				grVnKs[n][np][c]->SetLineColor(kBlue);
				grVnKs[n][np][c]->SetMarkerSize(2);

				grVnLm[n][np][c]->SetMarkerStyle(kFullCircle);
				grVnLm[n][np][c]->SetMarkerColor(kRed);
				grVnLm[n][np][c]->SetLineColor(kRed);
				grVnLm[n][np][c]->SetMarkerSize(2);
			}
		}
	}

	TLatex latexS;
	latexS.SetTextFont(43);
	latexS.SetTextSize(22);
	latexS.SetTextAlign(13);

//	TCanvas * cC = MakeCanvas("cC", "cC", 1500, 400);
//	makeMultiPanelCanvas(cC, 5, 1);
//
//	TH2D * hframePt = new TH2D("hframePt", "", 1, 0.01, 9.9, 1, 0.001, 0.32);
//	InitHist(hframePt, "p_{T}", "v_{2}");
//
//	cC->cd(1);
//	hframePt->Draw();
//	grVnKsGap[2][6]->Draw("psame");
//	grVnLmGap[2][6]->Draw("psame");
//	grVnGap  [2][6]->Draw("psame");
//	grVnKs[2][1][6]->Draw("psame");
//	grVnLm[2][1][6]->Draw("psame");
//
//	cC->cd(2);
//	hframePt->Draw();
//	grVnKsGap[2][7]->Draw("psame");
//	grVnLmGap[2][7]->Draw("psame");
//	grVnGap  [2][7]->Draw("psame");
//	grVnKs[2][1][7]->Draw("psame");
//	grVnLm[2][1][7]->Draw("psame");
//
//	cC->cd(3);
//	hframePt->Draw();
//	grVnKsGap[2][8]->Draw("psame");
//	grVnLmGap[2][8]->Draw("psame");
//	grVnGap  [2][8]->Draw("psame");
//	grVnKs[2][1][8]->Draw("psame");
//	grVnLm[2][1][8]->Draw("psame");
//
//	cC->cd(4);
//	hframePt->Draw();
//	grVnKsGap[2][9]->Draw("psame");
//	grVnLmGap[2][9]->Draw("psame");
//	grVnGap  [2][9]->Draw("psame");
//	grVnKs[2][1][9]->Draw("psame");
//	grVnLm[2][1][9]->Draw("psame");
//
//	cC->cd(5);
//	hframePt->Draw();
//	grVnKsGap[2][10]->Draw("psame");
//	grVnLmGap[2][10]->Draw("psame");
//	grVnGap  [2][10]->Draw("psame");
//	grVnKs[2][1][10]->Draw("psame");
//	grVnLm[2][1][10]->Draw("psame");

	////////
	TCanvas * cC8 = MakeCanvas("cC8", "cC8", 600, 500);
	TH2D * hframePt = new TH2D("hframePt", "", 1, 0.01, 9.9, 1, 0.001, 0.32);
	InitHist(hframePt, "p_{T}", "v_{2}");
	hframePt->Draw();

	grVnKsGap[2][c]->Draw("psame");
	grVnLmGap[2][c]->Draw("psame");
//	grVnGap  [2][c]->Draw("psame");
	grVnKs[2][1][c]->Draw("psame");
	grVnLm[2][1][c]->Draw("psame");

	TLegend * legPt = new TLegend(0.17, 0.75, 0.45, 0.94);
	legPt->SetFillColor(kWhite);
	legPt->SetTextFont(42);
	legPt->SetTextSize(0.03);
	legPt->SetBorderSize(0);

	legPt->AddEntry(grVnKsGap[2][c], "v_{2}{2, |#Delta#eta|>2} K_{s}", "p");
	legPt->AddEntry(grVnLmGap[2][c], "v_{2}{2, |#Delta#eta|>2} #Lambda", "p");
//	legPt->AddEntry(grVnGap  [2][c], "v_{2}{2, |#Delta#eta|>2} h#pm", "p");
	legPt->AddEntry(grVnKs[2][1][c], "v_{2}{4} K_{s}", "p");
	legPt->AddEntry(grVnLm[2][1][c], "v_{2}{4} #Lambda", "p");
	legPt->Draw();

	latexS.DrawLatexNDC(0.6, 0.9, sNoff[c].Data());

	TCanvas * cCKs = MakeCanvas("cCKs", "cCKs", 600, 500);
	hframePt->Draw();

	TLegend * legKs = new TLegend(0.17, 0.75, 0.45, 0.94);
	legKs->SetFillColor(kWhite);
	legKs->SetTextFont(42);
	legKs->SetTextSize(0.03);
	legKs->SetBorderSize(0);

	grVnKsGap[2][c]->Draw("psame");
	grVnKs[2][1][c]->Draw("psame");
	grVnKs[2][2][c]->SetMarkerStyle(kFullCross);
	grVnKs[2][2][c]->SetMarkerColor(kBlack);
	grVnKs[2][2][c]->SetLineColor(kBlack);
	grVnKs[2][2][c]->Draw("psame");

	grVnKs[2][3][c]->SetMarkerStyle(kFullDiamond);
	grVnKs[2][3][c]->SetMarkerColor(kGreen);
	grVnKs[2][3][c]->SetLineColor(kGreen);
	grVnKs[2][3][c]->Draw("psame");

	if ( bPbPb ) {
		if ( mgr_PbPb_Ks_v22[c] ) {
			mgr_PbPb_Ks_v22[c]->Draw("psame");
			legKs->AddEntry(mgr_PbPb_Ks_v22[c], "v_{2}{2, |#Delta#eta|>2} K_{s} PbPb 2.76 TeV", "p");
		}
		legKs->AddEntry(grVnKsGap[2][c], "v_{2}{2, |#Delta#eta|>2} K_{s} PbPb 5 TeV", "p");
		legKs->AddEntry(grVnKs[2][1][c], "v_{2}{4} K_{s} PbPb 5 TeV", "p");
	} else {
		if ( mgr_pPb_Ks_v22[c] ) {
			mgr_pPb_Ks_v22[c]->Draw("psame");
			legKs->AddEntry(mgr_pPb_Ks_v22[c], "v_{2}{2, |#Delta#eta|>2} K_{s} pPb 5 TeV", "p");
		}
		legKs->AddEntry(grVnKsGap[2][c], "v_{2}{2, |#Delta#eta|>2} K_{s} pPb 8 TeV", "p");
		legKs->AddEntry(grVnKs[2][1][c], "v_{2}{4} K_{s} pPb 8 TeV", "p");
	}

	legKs->Draw();
	latexS.DrawLatexNDC(0.6, 0.9, sNoff[c].Data());

////
	TCanvas * cCLm = MakeCanvas("cCLm", "cCLm", 600, 500);
	hframePt->Draw();

	TLegend * legLm = new TLegend(0.17, 0.75, 0.45, 0.94);
	legLm->SetFillColor(kWhite);
	legLm->SetTextFont(42);
	legLm->SetTextSize(0.03);
	legLm->SetBorderSize(0);

	grVnLmGap[2][c]->Draw("psame");
	grVnLm[2][1][c]->Draw("psame");
	grVnLm[2][2][c]->SetMarkerStyle(kFullCross);
	grVnLm[2][2][c]->SetMarkerColor(kBlack);
	grVnLm[2][2][c]->SetLineColor(kBlack);
	grVnLm[2][2][c]->Draw("psame");

	grVnLm[2][3][c]->SetMarkerStyle(kFullCross);
	grVnLm[2][3][c]->SetMarkerColor(kGreen);
	grVnLm[2][3][c]->SetLineColor(kGreen);
	grVnLm[2][3][c]->Draw("psame");

	if ( bPbPb ) {
		if ( mgr_PbPb_Lambda_v22[c] ) {
			mgr_PbPb_Lambda_v22[c]->Draw("psame");
			legLm->AddEntry(mgr_PbPb_Lambda_v22[c], "v_{2}{2, |#Delta#eta|>2} #Lambda PbPb 2.76 TeV", "p");
		}
		legLm->AddEntry(grVnLmGap[2][c], "v_{2}{2, |#Delta#eta|>2} #Lambda PbPb 5 TeV", "p");
		legLm->AddEntry(grVnLm[2][1][c], "v_{2}{4} #Lambda PbPb 5 TeV", "p");
	} else {
		if ( mgr_pPb_Lambda_v22[c] ) {
			mgr_pPb_Lambda_v22[c]->Draw("psame");
			legLm->AddEntry(mgr_pPb_Lambda_v22[c], "v_{2}{2, |#Delta#eta|>2} #Lambda pPb 5 TeV", "p");
		}
		legLm->AddEntry(grVnLmGap[2][c], "v_{2}{2, |#Delta#eta|>2} #Lambda pPb 8 TeV", "p");
		legLm->AddEntry(grVnLm[2][1][c], "v_{2}{4} #Lambda pPb 8 TeV", "p");
	}

	legLm->Draw();
	latexS.DrawLatexNDC(0.6, 0.9, sNoff[c].Data());




//	cC->SaveAs("v2.pdf");
	if ( bPbPb ) {
		cC8->SaveAs(Form("v2PbPb%i.pdf", c));
		cCKs->SaveAs(Form("v2PbPbKs%icomp.pdf", c));
		cCLm->SaveAs(Form("v2PbPbLm%icomp.pdf", c));
	} else {
		cC8->SaveAs(Form("v2%i.pdf", c));
		cCKs->SaveAs(Form("v2Ks%icomp.pdf", c));
		cCLm->SaveAs(Form("v2Lm%icomp.pdf", c));
	}
}
