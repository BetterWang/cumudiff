#include "label.h"
#include "noff.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TH1.h"
#include "TGraphErrors.h"
#include "TMultiGraph.h"
#include "../../style.h"


void genPlot(int s1 = 1)
{
	TFile *f = new TFile(Form("%s/outputE.root", ftxt[s1]));

	int NCent = NCent8TeV4;

	double dVp[7][4][24][20];
	double eVp[7][4][24][20];

	for ( int n = 2; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			for ( int i = 0; i < 24; i++ ) {
				TH1D * h = (TH1D*) f->Get(Form("hVp%i%i_%i", n, np, i));
				for ( int c = 0; c < 20; c++ ) {
					dVp[n][np][i][c] = h->GetBinContent(c+1);
					eVp[n][np][i][c] = h->GetBinError(c+1);
					cout << " -> dVp[" << n << "][" << np<< "][" << i << "][" << c << "] = " << dVp[n][np][i][c] << endl;
				}
			}
		}
	}

	TGraphErrors * grV0pT[7][4][20] = {};
	for ( int n = 2; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			for ( int c = 0; c < NCent; c++ ) {
				double y[24] = {};
				double e[24] = {};
				for ( int ipt = 0; ipt < NpT; ipt++ ) {
					//cout << " -> dVp[" << n << "][" << np<< "][" << ipt << "][" << c << "] = " << dVp[n][np][ipt][c] << endl;
					y[ipt] = dVp[n][np][ipt][c];
					e[ipt] = eVp[n][np][ipt][c];
				}
				grV0pT[n][np][c] = new TGraphErrors(NpT, pTX, y, 0, e);
			}
		}
	}

	for ( int n = 2; n < 7; n++ ) {
		for ( int c = 0; c < NCent; c++ ) {
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

	TFile * fwrite = new TFile(Form("%s/ougGraph.root", ftxt[s1]), "recreate");
	for ( int n = 2; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			for ( int c = 0; c < NCent; c++ ) {
				grV0pT[n][np][c]->Write(Form("grV0pT%i%i_%i", n, np, c));
			}
		}
	}
}
