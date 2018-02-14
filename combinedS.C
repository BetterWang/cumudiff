#include "label.h"


void combinedS(int sHM0Ks = 7, int sHM1Ks = 8, int sHM7Ks = 9) {
	TGraphErrors * grKs_pT[7][4][20] = {};
	TGraphErrors * grKs_pTGap[7][20] = {};
	TGraphErrors * grHKs_pTGap[7][20] = {};

	TFile * fHM0Ks = new TFile( Form("%s/outGraph.root", ftxt[sHM0Ks]) );
	TFile * fHM1Ks = new TFile( Form("%s/outGraph.root", ftxt[sHM1Ks]) );
	TFile * fHM7Ks = new TFile( Form("%s/outGraph.root", ftxt[sHM7Ks]) );

	for ( int n = 2; n < 7; n++ ) {
		grKs_pTGap[n][6] = (TGraphErrors*) fHM0Ks->Get( Form("grV0pTGap%i_%i", n, 6) );
		grKs_pTGap[n][7] = (TGraphErrors*) fHM0Ks->Get( Form("grV0pTGap%i_%i", n, 7) );
		grKs_pTGap[n][8] = (TGraphErrors*) fHM1Ks->Get( Form("grV0pTGap%i_%i", n, 8) );
		grKs_pTGap[n][9] = (TGraphErrors*) fHM7Ks->Get( Form("grV0pTGap%i_%i", n, 9) );
		grKs_pTGap[n][10]= (TGraphErrors*) fHM7Ks->Get( Form("grV0pTGap%i_%i", n, 10));

		grHKs_pTGap[n][6] = (TGraphErrors*) fHM0Ks->Get( Form("grpTGap%i_%i", n, 6) );
		grHKs_pTGap[n][7] = (TGraphErrors*) fHM0Ks->Get( Form("grpTGap%i_%i", n, 7) );
		grHKs_pTGap[n][8] = (TGraphErrors*) fHM1Ks->Get( Form("grpTGap%i_%i", n, 8) );
		grHKs_pTGap[n][9] = (TGraphErrors*) fHM7Ks->Get( Form("grpTGap%i_%i", n, 9) );
		grHKs_pTGap[n][10]= (TGraphErrors*) fHM7Ks->Get( Form("grpTGap%i_%i", n, 10));

		for ( int np = 0; np < 4; np++ ) {
			grKs_pT[n][np][6] = (TGraphErrors*) fHM0Ks->Get( Form("grV0pT%i%i_%i", n, np, 6) );
			grKs_pT[n][np][7] = (TGraphErrors*) fHM0Ks->Get( Form("grV0pT%i%i_%i", n, np, 7) );
			grKs_pT[n][np][8] = (TGraphErrors*) fHM1Ks->Get( Form("grV0pT%i%i_%i", n, np, 8) );
			grKs_pT[n][np][9] = (TGraphErrors*) fHM7Ks->Get( Form("grV0pT%i%i_%i", n, np, 9) );
			grKs_pT[n][np][10]= (TGraphErrors*) fHM7Ks->Get( Form("grV0pT%i%i_%i", n, np, 10));
		}
	}

	TFile * fwrite = new TFile(Form("combinedS_%i_%i_%i.root", sHM0Ks, sHM1Ks, sHM7Ks), "recreate");
	for ( int n = 2; n < 7; n++ ) {
		for ( int c = 6; c < 11; c++ ) {
			grKs_pTGap[n][c]->Write(Form("grV0Gap%i_%i", n, c));
			grHKs_pTGap[n][c]->Write(Form("grHV0Gap%i_%i", n, c));
			for ( int np = 0; np < 4; np++ ) {
				grKs_pT[n][np][c]->Write(Form("grV0%i%i_%i", n, np, c));
			}
		}
	}
}
