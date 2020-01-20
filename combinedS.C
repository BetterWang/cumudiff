#include "label.h"


void combinedS(int sHM0Ks = 7 ) {
	TGraphErrors * grKs_pT[7][4][20] = {};
	TGraphErrors * grKs_pTGap[7][20] = {};
	TGraphErrors * grHKs_pTGap[7][20] = {};

    TGraphErrors * grV0v2sub2[20] = {};
    TGraphErrors * grV0v2sub4[20] = {};

    TGraphErrors * grV0v2sub2pos[20] = {};
    TGraphErrors * grV0v2sub4pos[20] = {};

    TGraphErrors * grV0v2sub2neg[20] = {};
    TGraphErrors * grV0v2sub4neg[20] = {};

	TFile * fHM0Ks = new TFile( Form("%s/outGraph.root", ftxt[sHM0Ks]) );

	for ( int n = 2; n < 7; n++ ) {
        for ( int c = 0; c < 5; c++ ) {
            grKs_pTGap[n][c] = (TGraphErrors*) fHM0Ks->Get( Form("grV0pTGap%i_%i", n, c) );
            grHKs_pTGap[n][c]= (TGraphErrors*) fHM0Ks->Get( Form("grpTGap%i_%i", n, c));

            for ( int np = 0; np < 4; np++ ) {
                grKs_pT[n][np][c] = (TGraphErrors*) fHM0Ks->Get( Form("grV0pT%i%i_%i", n, np, c) );
            }
        }
	}
    for ( int c = 0; c < 5; c++ ) {
        grV0v2sub2[c] = (TGraphErrors*) fHM0Ks->Get( Form("grpTV2sub2%i", c) );
        grV0v2sub4[c] = (TGraphErrors*) fHM0Ks->Get( Form("grpTV2sub4%i", c) );

        grV0v2sub2pos[c] = (TGraphErrors*) fHM0Ks->Get( Form("grpTV2sub2pos%i", c) );
        grV0v2sub4pos[c] = (TGraphErrors*) fHM0Ks->Get( Form("grpTV2sub4pos%i", c) );

        grV0v2sub2neg[c] = (TGraphErrors*) fHM0Ks->Get( Form("grpTV2sub2neg%i", c) );
        grV0v2sub4neg[c] = (TGraphErrors*) fHM0Ks->Get( Form("grpTV2sub4neg%i", c) );
    }

	TFile * fwrite = new TFile(Form("combinedS_%i.root", sHM0Ks), "recreate");
	for ( int n = 2; n < 7; n++ ) {
		for ( int c = 0; c < 5; c++ ) {
			grKs_pTGap[n][c]->Write(Form("grV0Gap%i_%i", n, c));
			grHKs_pTGap[n][c]->Write(Form("grHV0Gap%i_%i", n, c));
			for ( int np = 0; np < 4; np++ ) {
				grKs_pT[n][np][c]->Write(Form("grV0%i%i_%i", n, np, c));
			}
		}
	}
    for ( int c = 0; c < 5; c++ ) {
        if (grV0v2sub2[c] ) grV0v2sub2[c] ->Write(Form("grV0v2sub2_%i", c));
        if (grV0v2sub4[c] ) grV0v2sub4[c] ->Write(Form("grV0v2sub4_%i", c));
        if (grV0v2sub2pos[c] ) grV0v2sub2pos[c] ->Write(Form("grV0v2sub2pos_%i", c));
        if (grV0v2sub4pos[c] ) grV0v2sub4pos[c] ->Write(Form("grV0v2sub4pos_%i", c));
        if (grV0v2sub2neg[c] ) grV0v2sub2neg[c] ->Write(Form("grV0v2sub2neg_%i", c));
        if (grV0v2sub4neg[c] ) grV0v2sub4neg[c] ->Write(Form("grV0v2sub4neg_%i", c));
    }
}
