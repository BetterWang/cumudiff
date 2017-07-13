#include "../../style.h"
#include "HIN-14-002.h"


void plot(TString s = "grVn_std.root")
{
	TFile * f = new TFile(s);
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


	TCanvas * cC = MakeCanvas("cC", "cC", 1500, 400);
	makeMultiPanelCanvas(cC, 5, 1);

	TH2D * hframePt = new TH2D("hframePt", "", 1, 0.01, 9.9, 1, 0.001, 0.29);
	InitHist(hframePt, "p_{T}", "v_{2}");

	cC->cd(1);
	hframePt->Draw();
	grVnKsGap[2][6]->Draw("psame");
	grVnLmGap[2][6]->Draw("psame");
	grVnGap  [2][6]->Draw("psame");
	grVnKs[2][1][6]->Draw("psame");
	grVnLm[2][1][6]->Draw("psame");

	cC->cd(2);
	hframePt->Draw();
	grVnKsGap[2][7]->Draw("psame");
	grVnLmGap[2][7]->Draw("psame");
	grVnGap  [2][7]->Draw("psame");
	grVnKs[2][1][7]->Draw("psame");
	grVnLm[2][1][7]->Draw("psame");

	cC->cd(3);
	hframePt->Draw();
	grVnKsGap[2][8]->Draw("psame");
	grVnLmGap[2][8]->Draw("psame");
	grVnGap  [2][8]->Draw("psame");
	grVnKs[2][1][8]->Draw("psame");
	grVnLm[2][1][8]->Draw("psame");

	cC->cd(4);
	hframePt->Draw();
	grVnKsGap[2][9]->Draw("psame");
	grVnLmGap[2][9]->Draw("psame");
	grVnGap  [2][9]->Draw("psame");
	grVnKs[2][1][9]->Draw("psame");
	grVnLm[2][1][9]->Draw("psame");

	cC->cd(5);
	hframePt->Draw();
	grVnKsGap[2][10]->Draw("psame");
	grVnLmGap[2][10]->Draw("psame");
	grVnGap  [2][10]->Draw("psame");
	grVnKs[2][1][10]->Draw("psame");
	grVnLm[2][1][10]->Draw("psame");

	////////
	TCanvas * cC8 = MakeCanvas("cC8", "cC8", 600, 500);
	hframePt->Draw();
	grVnKsGap[2][8]->Draw("psame");
	grVnLmGap[2][8]->Draw("psame");
	grVnGap  [2][8]->Draw("psame");
	grVnKs[2][1][8]->Draw("psame");
//	grVnKs[2][2][8]->Draw("psame");
	grVnLm[2][1][8]->Draw("psame");
//	grVnLm[2][2][8]->Draw("psame");
}
