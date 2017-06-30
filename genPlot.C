#include "label.h"
#include "noff.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TH1.h"
#include "TGraphErrors.h"
#include "TMultiGraph.h"
#include "../../style.h"
#include "HIN-14-002.h"


void genPlot(int s1 = 1)
{
	TFile *f = new TFile(Form("%s/outputE.root", ftxt[s1]));

	int NCent = NCent8TeV4;

	double dVp[7][4][24][20];
	double eVp[7][4][24][20];

	double dVpGap[7][24][20];
	double eVpGap[7][24][20];

	HIN_14_002();
	for ( int n = 2; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			for ( int i = 0; i < 24; i++ ) {
				TH1D * h = (TH1D*) f->Get(Form("hVp%i%i_%i", n, np, i));
				for ( int c = 0; c < 20; c++ ) {
					dVp[n][np][i][c] = h->GetBinContent(c+1);
					eVp[n][np][i][c] = h->GetBinError(c+1);
				}
			}
		}
		for ( int i = 0; i < 24; i++ ) {
			TH1D * h = (TH1D*) f->Get(Form("hVpGap%i_%i", n, i));
			for ( int c = 0; c < 20; c++ ) {
				dVpGap[n][i][c] = h->GetBinContent(c+1);
				eVpGap[n][i][c] = h->GetBinError(c+1);
			}
		}
	}

	TGraphErrors * grV0pT[7][4][20] = {};
	TGraphErrors * grV0pTGap[7][20] = {};

	for ( int n = 2; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			for ( int c = 0; c < NCent; c++ ) {
				double y[24] = {};
				double e[24] = {};
				for ( int ipt = 0; ipt < NpT; ipt++ ) {
					y[ipt] = dVp[n][np][ipt][c];
					e[ipt] = eVp[n][np][ipt][c];
				}
				grV0pT[n][np][c] = new TGraphErrors(NpT, pTX, y, 0, e);
			}
		}
		for ( int c = 0; c < NCent; c++ ) {
			double y[24] = {};
			double e[24] = {};
			for ( int ipt = 0; ipt < NpT; ipt++ ) {
				y[ipt] = dVpGap[n][ipt][c];
				e[ipt] = eVpGap[n][ipt][c];
			}
			grV0pTGap[n][c] = new TGraphErrors(NpT, pTX, y, 0, e);
		}
	}

	for ( int n = 2; n < 7; n++ ) {
		for ( int c = 0; c < NCent; c++ ) {
			grV0pTGap[n][c]->SetMarkerStyle(kOpenCircle);
			grV0pTGap[n][c]->SetMarkerColor(kRed);
			grV0pTGap[n][c]->SetLineColor(kRed);

			grV0pT[n][0][c]->SetMarkerStyle(kFullCircle);
			grV0pT[n][0][c]->SetMarkerColor(kRed);
			grV0pT[n][0][c]->SetLineColor(kRed);

			grV0pT[n][1][c]->SetMarkerStyle(kFullSquare);
			grV0pT[n][1][c]->SetMarkerColor(kBlue);
			grV0pT[n][1][c]->SetLineColor(kBlue);

			grV0pT[n][2][c]->SetMarkerStyle(kOpenCross);
			grV0pT[n][2][c]->SetMarkerColor(kBlack);
			grV0pT[n][2][c]->SetLineColor(kBlack);

			grV0pT[n][3][c]->SetMarkerStyle(kOpenStar);
			grV0pT[n][3][c]->SetMarkerColor(kGreen);
			grV0pT[n][3][c]->SetLineColor(kGreen);
		}
	}

	TH2D * hframe_pt = new TH2D("hframe_pt", "", 1, 0, 10, 1, 0, 0.35);
	InitHist(hframe_pt, "p_{T} (GeV/c)", "v_{n}");
	TCanvas * cT = MakeCanvas("cT", "cT", 600, 500);

	for ( int n = 2; n < 7; n++ ) {
		hframe_pt->GetYaxis()->SetTitle(Form("v_{%i}",n));
		for ( int c = 6; c < 11; c++ ) {
			hframe_pt->Draw();

			TLegend * legPt = new TLegend(0.2, 0.7, 0.55, 0.9);
			legPt->SetFillColor(kWhite);
			legPt->SetTextFont(42);
			legPt->SetTextSize(0.03);
			legPt->SetBorderSize(0);

			grV0pTGap[n][c]->Draw("psame");
			grV0pT[n][1][c]->Draw("psame");
//			grV0pT[n][2][c]->Draw("psame");
//			grV0pT[n][3][c]->Draw("psame");

			legPt->AddEntry(grV0pTGap[n][c], Form("v_{%i}{2, |#Delta#eta|>2}", n), "p");
			legPt->AddEntry(grV0pT[n][1][c], Form("v_{%i}{4}", n), "p");
//			legPt->AddEntry(grV0pT[n][2][c], Form("v_{%i}{6}", n), "p");
//			legPt->AddEntry(grV0pT[n][3][c], Form("v_{%i}{8}", n), "p");

			if ( PID[s1] == Pid_Ks ) {
				if ( mgr_pPb_Ks_v22[c] and n==2 ) {
					mgr_pPb_Ks_v22[c]->Draw("psame");
					legPt->AddEntry(mgr_pPb_Ks_v22[c], Form("HIN14002 v_{%i}{2, |#Delta#eta|>2}", n), "p");
				}
			}

			if ( PID[s1] == Pid_Lambda ) {
				if ( mgr_pPb_Lambda_v22[c] and n==2 ) {
					mgr_pPb_Lambda_v22[c]->Draw("psame");
					legPt->AddEntry(mgr_pPb_Lambda_v22[c], Form("HIN14002 v_{%i}{2, |#Delta#eta|>2}", n), "p");
				}
			}

			legPt->Draw();

			cT->SaveAs(Form("%s/cPt_%i_%i.pdf", ftxt[s1],n, c));
			delete legPt;
		}
	}


	TFile * fwrite = new TFile(Form("%s/outGraph.root", ftxt[s1]), "recreate");
	for ( int n = 2; n < 7; n++ ) {
		for ( int c = 0; c < NCent; c++ ) {
			for ( int np = 0; np < 4; np++ ) {
				grV0pT[n][np][c]->Write(Form("grV0pT%i%i_%i", n, np, c));
			}
			grV0pTGap[n][c]->Write(Form("grV0pTGap%i_%i", n, c));
		}
	}
}
