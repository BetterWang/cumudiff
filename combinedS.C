#include "label.h"


void combinedS(int sHM0Ks = 7, int sHM1Ks = 8, int sHM7Ks = 9) {
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
    grV0v2sub2[6] = (TGraphErrors*) fHM0Ks->Get( "grpTV2sub26" );
    grV0v2sub2[7] = (TGraphErrors*) fHM0Ks->Get( "grpTV2sub27" );
    grV0v2sub2[8] = (TGraphErrors*) fHM1Ks->Get( "grpTV2sub28" );
    grV0v2sub2[9] = (TGraphErrors*) fHM7Ks->Get( "grpTV2sub29" );
    grV0v2sub2[10]= (TGraphErrors*) fHM7Ks->Get( "grpTV2sub210" );

    grV0v2sub4[6] = (TGraphErrors*) fHM0Ks->Get( "grpTV2sub46" );
    grV0v2sub4[7] = (TGraphErrors*) fHM0Ks->Get( "grpTV2sub47" );
    grV0v2sub4[8] = (TGraphErrors*) fHM1Ks->Get( "grpTV2sub48" );
    grV0v2sub4[9] = (TGraphErrors*) fHM7Ks->Get( "grpTV2sub49" );
    grV0v2sub4[10]= (TGraphErrors*) fHM7Ks->Get( "grpTV2sub410" );

    grV0v2sub2pos[6] = (TGraphErrors*) fHM0Ks->Get( "grpTV2sub2pos6" );
    grV0v2sub2pos[7] = (TGraphErrors*) fHM0Ks->Get( "grpTV2sub2pos7" );
    grV0v2sub2pos[8] = (TGraphErrors*) fHM1Ks->Get( "grpTV2sub2pos8" );
    grV0v2sub2pos[9] = (TGraphErrors*) fHM7Ks->Get( "grpTV2sub2pos9" );
    grV0v2sub2pos[10]= (TGraphErrors*) fHM7Ks->Get( "grpTV2sub2pos10" );

    grV0v2sub4pos[6] = (TGraphErrors*) fHM0Ks->Get( "grpTV2sub4pos6" );
    grV0v2sub4pos[7] = (TGraphErrors*) fHM0Ks->Get( "grpTV2sub4pos7" );
    grV0v2sub4pos[8] = (TGraphErrors*) fHM1Ks->Get( "grpTV2sub4pos8" );
    grV0v2sub4pos[9] = (TGraphErrors*) fHM7Ks->Get( "grpTV2sub4pos9" );
    grV0v2sub4pos[10]= (TGraphErrors*) fHM7Ks->Get( "grpTV2sub4pos10" );

    grV0v2sub2neg[6] = (TGraphErrors*) fHM0Ks->Get( "grpTV2sub2neg6" );
    grV0v2sub2neg[7] = (TGraphErrors*) fHM0Ks->Get( "grpTV2sub2neg7" );
    grV0v2sub2neg[8] = (TGraphErrors*) fHM1Ks->Get( "grpTV2sub2neg8" );
    grV0v2sub2neg[9] = (TGraphErrors*) fHM7Ks->Get( "grpTV2sub2neg9" );
    grV0v2sub2neg[10]= (TGraphErrors*) fHM7Ks->Get( "grpTV2sub2neg10" );

    grV0v2sub4neg[6] = (TGraphErrors*) fHM0Ks->Get( "grpTV2sub4neg6" );
    grV0v2sub4neg[7] = (TGraphErrors*) fHM0Ks->Get( "grpTV2sub4neg7" );
    grV0v2sub4neg[8] = (TGraphErrors*) fHM1Ks->Get( "grpTV2sub4neg8" );
    grV0v2sub4neg[9] = (TGraphErrors*) fHM7Ks->Get( "grpTV2sub4neg9" );
    grV0v2sub4neg[10]= (TGraphErrors*) fHM7Ks->Get( "grpTV2sub4neg10" );

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
    if (grV0v2sub2[6] ) grV0v2sub2[6] ->Write(Form("grV0v2sub2_6"));
    if (grV0v2sub2[7] ) grV0v2sub2[7] ->Write(Form("grV0v2sub2_7"));
    if (grV0v2sub2[8] ) grV0v2sub2[8] ->Write(Form("grV0v2sub2_8"));
    if (grV0v2sub2[9] ) grV0v2sub2[9] ->Write(Form("grV0v2sub2_9"));
    if (grV0v2sub2[10]) grV0v2sub2[10]->Write(Form("grV0v2sub2_10"));

    if (grV0v2sub4[6] ) grV0v2sub4[6] ->Write(Form("grV0v2sub4_6"));
    if (grV0v2sub4[7] ) grV0v2sub4[7] ->Write(Form("grV0v2sub4_7"));
    if (grV0v2sub4[8] ) grV0v2sub4[8] ->Write(Form("grV0v2sub4_8"));
    if (grV0v2sub4[9] ) grV0v2sub4[9] ->Write(Form("grV0v2sub4_9"));
    if (grV0v2sub4[10]) grV0v2sub4[10]->Write(Form("grV0v2sub4_10"));

    if (grV0v2sub2pos[6] ) grV0v2sub2pos[6] ->Write(Form("grV0v2sub2pos_6"));
    if (grV0v2sub2pos[7] ) grV0v2sub2pos[7] ->Write(Form("grV0v2sub2pos_7"));
    if (grV0v2sub2pos[8] ) grV0v2sub2pos[8] ->Write(Form("grV0v2sub2pos_8"));
    if (grV0v2sub2pos[9] ) grV0v2sub2pos[9] ->Write(Form("grV0v2sub2pos_9"));
    if (grV0v2sub2pos[10]) grV0v2sub2pos[10]->Write(Form("grV0v2sub2pos_10"));

    if (grV0v2sub4pos[6] ) grV0v2sub4pos[6] ->Write(Form("grV0v2sub4pos_6"));
    if (grV0v2sub4pos[7] ) grV0v2sub4pos[7] ->Write(Form("grV0v2sub4pos_7"));
    if (grV0v2sub4pos[8] ) grV0v2sub4pos[8] ->Write(Form("grV0v2sub4pos_8"));
    if (grV0v2sub4pos[9] ) grV0v2sub4pos[9] ->Write(Form("grV0v2sub4pos_9"));
    if (grV0v2sub4pos[10]) grV0v2sub4pos[10]->Write(Form("grV0v2sub4pos_10"));

    if (grV0v2sub2neg[6] ) grV0v2sub2neg[6] ->Write(Form("grV0v2sub2neg_6"));
    if (grV0v2sub2neg[7] ) grV0v2sub2neg[7] ->Write(Form("grV0v2sub2neg_7"));
    if (grV0v2sub2neg[8] ) grV0v2sub2neg[8] ->Write(Form("grV0v2sub2neg_8"));
    if (grV0v2sub2neg[9] ) grV0v2sub2neg[9] ->Write(Form("grV0v2sub2neg_9"));
    if (grV0v2sub2neg[10]) grV0v2sub2neg[10]->Write(Form("grV0v2sub2neg_10"));

    if (grV0v2sub4neg[6] ) grV0v2sub4neg[6] ->Write(Form("grV0v2sub4neg_6"));
    if (grV0v2sub4neg[7] ) grV0v2sub4neg[7] ->Write(Form("grV0v2sub4neg_7"));
    if (grV0v2sub4neg[8] ) grV0v2sub4neg[8] ->Write(Form("grV0v2sub4neg_8"));
    if (grV0v2sub4neg[9] ) grV0v2sub4neg[9] ->Write(Form("grV0v2sub4neg_9"));
    if (grV0v2sub4neg[10]) grV0v2sub4neg[10]->Write(Form("grV0v2sub4neg_10"));
}
