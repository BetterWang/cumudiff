#include "label.h"


void combined(int sHM0Ks = 7, int sHM1Ks = 8, int sHM7Ks = 9, int sHM0Lambda = 16, int sHM1Lambda = 17, int sHM7Lambda = 18) {
	TGraphErrors * grKs_pT[7][4][20] = {};
	TGraphErrors * grLm_pT[7][4][20] = {};

	TGraphErrors * grKs_pTGap[7][20] = {};
	TGraphErrors * grLm_pTGap[7][20] = {};

	TGraphErrors * grHKs_pTGap[7][20] = {};
	TGraphErrors * grHLm_pTGap[7][20] = {};

	TFile * fHM0Ks = new TFile( Form("%s/outGraph.root", ftxt[sHM0Ks]) );
	TFile * fHM1Ks = new TFile( Form("%s/outGraph.root", ftxt[sHM1Ks]) );
	TFile * fHM7Ks = new TFile( Form("%s/outGraph.root", ftxt[sHM7Ks]) );

	TFile * fHM0Lm = new TFile( Form("%s/outGraph.root", ftxt[sHM0Lambda]) );
	TFile * fHM1Lm = new TFile( Form("%s/outGraph.root", ftxt[sHM1Lambda]) );
	TFile * fHM7Lm = new TFile( Form("%s/outGraph.root", ftxt[sHM7Lambda]) );

	for ( int n = 2; n < 7; n++ ) {
		grKs_pTGap[n][6] = (TGraphErrors*) fHM0Ks->Get( Form("grV0pTGap%i_%i", n, 6) );
		grKs_pTGap[n][7] = (TGraphErrors*) fHM0Ks->Get( Form("grV0pTGap%i_%i", n, 7) );
		grKs_pTGap[n][8] = (TGraphErrors*) fHM1Ks->Get( Form("grV0pTGap%i_%i", n, 8) );
		grKs_pTGap[n][9] = (TGraphErrors*) fHM1Ks->Get( Form("grV0pTGap%i_%i", n, 9) );
		grKs_pTGap[n][10]= (TGraphErrors*) fHM7Ks->Get( Form("grV0pTGap%i_%i", n, 10));

		grLm_pTGap[n][6] = (TGraphErrors*) fHM0Lm->Get( Form("grV0pTGap%i_%i", n, 6) );
		grLm_pTGap[n][7] = (TGraphErrors*) fHM0Lm->Get( Form("grV0pTGap%i_%i", n, 7) );
		grLm_pTGap[n][8] = (TGraphErrors*) fHM1Lm->Get( Form("grV0pTGap%i_%i", n, 8) );
		grLm_pTGap[n][9] = (TGraphErrors*) fHM1Lm->Get( Form("grV0pTGap%i_%i", n, 9) );
		grLm_pTGap[n][10]= (TGraphErrors*) fHM7Lm->Get( Form("grV0pTGap%i_%i", n, 10));

		grHKs_pTGap[n][6] = (TGraphErrors*) fHM0Ks->Get( Form("grpTGap%i_%i", n, 6) );
		grHKs_pTGap[n][7] = (TGraphErrors*) fHM0Ks->Get( Form("grpTGap%i_%i", n, 7) );
		grHKs_pTGap[n][8] = (TGraphErrors*) fHM1Ks->Get( Form("grpTGap%i_%i", n, 8) );
		grHKs_pTGap[n][9] = (TGraphErrors*) fHM1Ks->Get( Form("grpTGap%i_%i", n, 9) );
		grHKs_pTGap[n][10]= (TGraphErrors*) fHM7Ks->Get( Form("grpTGap%i_%i", n, 10));

		grHLm_pTGap[n][6] = (TGraphErrors*) fHM0Lm->Get( Form("grpTGap%i_%i", n, 6) );
		grHLm_pTGap[n][7] = (TGraphErrors*) fHM0Lm->Get( Form("grpTGap%i_%i", n, 7) );
		grHLm_pTGap[n][8] = (TGraphErrors*) fHM1Lm->Get( Form("grpTGap%i_%i", n, 8) );
		grHLm_pTGap[n][9] = (TGraphErrors*) fHM1Lm->Get( Form("grpTGap%i_%i", n, 9) );
		grHLm_pTGap[n][10]= (TGraphErrors*) fHM7Lm->Get( Form("grpTGap%i_%i", n, 10));

		for ( int np = 0; np < 4; np++ ) {
			grKs_pT[n][np][6] = (TGraphErrors*) fHM0Ks->Get( Form("grV0pT%i%i_%i", n, np, 6) );
			grKs_pT[n][np][7] = (TGraphErrors*) fHM0Ks->Get( Form("grV0pT%i%i_%i", n, np, 7) );
			grKs_pT[n][np][8] = (TGraphErrors*) fHM1Ks->Get( Form("grV0pT%i%i_%i", n, np, 8) );
			grKs_pT[n][np][9] = (TGraphErrors*) fHM1Ks->Get( Form("grV0pT%i%i_%i", n, np, 9) );
			grKs_pT[n][np][10]= (TGraphErrors*) fHM7Ks->Get( Form("grV0pT%i%i_%i", n, np, 10));

			grLm_pT[n][np][6] = (TGraphErrors*) fHM0Lm->Get( Form("grV0pT%i%i_%i", n, np, 6) );
			grLm_pT[n][np][7] = (TGraphErrors*) fHM0Lm->Get( Form("grV0pT%i%i_%i", n, np, 7) );
			grLm_pT[n][np][8] = (TGraphErrors*) fHM1Lm->Get( Form("grV0pT%i%i_%i", n, np, 8) );
			grLm_pT[n][np][9] = (TGraphErrors*) fHM1Lm->Get( Form("grV0pT%i%i_%i", n, np, 9) );
			grLm_pT[n][np][10]= (TGraphErrors*) fHM7Lm->Get( Form("grV0pT%i%i_%i", n, np, 10));
		}
	}

	TFile * fwrite = new TFile(Form("combined_%i_%i_%i_%i_%i_%i.root", sHM0Ks, sHM1Ks, sHM7Ks, sHM0Lambda, sHM1Lambda, sHM7Lambda), "recreate");
	for ( int n = 2; n < 7; n++ ) {
		for ( int c = 6; c < 11; c++ ) {
			grKs_pTGap[n][c]->Write(Form("grKsGap%i_%i", n, c));
			grLm_pTGap[n][c]->Write(Form("grLmGap%i_%i", n, c));

			grHKs_pTGap[n][c]->Write(Form("grHKsGap%i_%i", n, c));
			grHLm_pTGap[n][c]->Write(Form("grHLmGap%i_%i", n, c));
			for ( int np = 0; np < 4; np++ ) {
				grKs_pT[n][np][c]->Write(Form("grKs%i%i_%i", n, np, c));
				grLm_pT[n][np][c]->Write(Form("grLm%i%i_%i", n, np, c));
			}
		}
	}
}
