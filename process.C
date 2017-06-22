#include "label.h"
#include <TFile.h>
#include <TTree.h>
#include <TH1.h>
#include <TMath.h>
using namespace std;
void process(int s1 = 0, int s2 = 10, int s3 = 10)
{
	cout << " s1 = " << s1 << " s2 = " << s2 << " s3 = " << s3 << endl;
	TH1::SetDefaultSumw2();
	addchain(s1);

	int gNoff;
	int gMult;
	int gV0;

	double rQ[7][4];
	double iQ[7][4];
	double wQ[7][4];

	double rVQp[7][4][24];
	double iVQp[7][4][24];
	double wVQp[7][4][24];

        chV->SetBranchAddress("Noff", &gNoff);
        chV->SetBranchAddress("Mult", &gMult);
        chV->SetBranchAddress("NV0",  &gV0);

	for ( int np = 0; np < 4; np++ ) {
		for ( int n = 2; n < 7; n++ ) {
			chV->SetBranchAddress( Form("rQ%i%i", n, 2+2*np), &rQ[n][np]);
			chV->SetBranchAddress( Form("iQ%i%i", n, 2+2*np), &iQ[n][np]);

			chV->SetBranchAddress( Form("rVQp%i%i", n, 2+2*np), &rVQp[n][np]);
			chV->SetBranchAddress( Form("iVQp%i%i", n, 2+2*np), &iVQp[n][np]);
		}
		int n = 2;
		chV->SetBranchAddress( Form("wQ%i%i", n, 2+2*np), &wQ[n][np]);
		chV->SetBranchAddress( Form("wVQp%i%i", n, 2+2*np), &wVQp[n][np]);
	}
	TH1D * hMult = new TH1D("hMult", "hMult", 1000, -0.5, 999.5);
	TH1D * hNoff = new TH1D("hNoff", "hNoff", 1000, -0.5, 999.5);
	TH1D * hV0M  = new TH1D("hV0M",  "hV0M",  1000, -0.5, 999.5);

	TH1D * hQ[7][4] = {};
	TH1D * hQw[7][4] = {};
	TH1D * hQp[7][4][24] = {};
	TH1D * hQwp[7][4][24] = {};

	for ( int n = 2; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			hQ[n][np]  = new TH1D(Form("hQ%i%i", n, np), "", 600, 0, 600);
			hQw[n][np]  = new TH1D(Form("hQw%i%i", n, np), "", 600, 0, 600);
			for ( int i = 0; i < 24; i++ ) {
				hQp[n][np][i] = new TH1D(Form("hQp%i%i_%i", n, np, i), "", 600, 0, 600);
				hQwp[n][np][i] = new TH1D(Form("hQwp%i%i_%i", n, np, i), "", 600, 0, 600);
			}
		}
	}

	double dQ[7][4][600] = {};
	double yQ[7][4][600] = {};
	double dQp[7][4][24][600] = {};
	double yQp[7][4][24][600] = {};

	unsigned int ievt = 0;
	if ( s2 != s3 ) ievt = s2;
	while ( chV->GetEntry(ievt) ) {
		if ( !((ievt-s2)%100000) ) cout << "!! ievt = " << ievt << endl;
		if ( s2 == s3 ) ievt++;
		else ievt+= s3;

		if ( (gNoff>=600) or (gV0==0) ) continue;
		for ( int n = 3; n < 7; n++ ) {
			for ( int np = 0; np < 4; np++ ) {
				wQ[n][np] = wQ[2][np];
				for ( int i = 0; i < 24; i++ ) {
					wVQp[n][np][i] = wVQp[2][np][i];
				}
			}
		}

		for ( int n = 2; n < 7; n++ ) {
			for ( int np = 0; np < 4; np++ ) {
				dQ[n][np][gNoff] += rQ[n][np];
				yQ[n][np][gNoff] += wQ[n][np];
				for ( int i = 0; i < 24; i++ ) {
					dQp[n][np][i][gNoff] += rVQp[n][np][i];
					yQp[n][np][i][gNoff] += wVQp[n][np][i];
				}
			}
		}
		hNoff->Fill(gNoff);
		hMult->Fill(gMult);
		hV0M->Fill(gV0);
	}

	for ( int n = 2; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			for ( int c = 0; c < 600; c++ ) {
				hQ[n][np]->SetBinContent( c+1, dQ[n][np][c] );
				hQw[n][np]->SetBinContent( c+1, yQ[n][np][c] );

				for ( int i = 0; i < 24; i++ ) {
					hQp[n][np][i]->SetBinContent( c+1, dQp[n][np][i][c] );
					hQwp[n][np][i]->SetBinContent( c+1, yQp[n][np][i][c] );
				}
			}
		}
	}

	TFile * fwrite = new TFile(Form("%s/output_%i_%i.root", ftxt[s1], s2, s3), "recreate");
	for ( int n = 2; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			hQ[n][np]->Write();
			hQw[n][np]->Write();
			for ( int i = 0; i < 24; i++ ) {
				hQp[n][np][i]->Write();
				hQwp[n][np][i]->Write();
			}
		}
	}
	hNoff->Write();
	hMult->Write();
	hV0M->Write();
}
