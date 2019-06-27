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
	double wQ[7][4];

	double rQGap[7];
	double wQGap[7];

	double rV0QGap[7][24];
	double wV0QGap[7][24];

	double rQpGap[7][24];
	double wQpGap[7][24];

	double rVQp[7][4][24];
	double wVQp[7][4][24];

    double rQpos2 = 0;
    double wQpos2 = 0;
    double rVpQpos2[24] = {};
    double wVpQpos2[24] = {};
    double rQpos4 = 0;
    double wQpos4 = 0;
    double rVpQpos4[24] = {};
    double wVpQpos4[24] = {};

    double rQneg2 = 0;
    double wQneg2 = 0;
    double rVpQneg2[24] = {};
    double wVpQneg2[24] = {};
    double rQneg4 = 0;
    double wQneg4 = 0;
    double rVpQneg4[24] = {};
    double wVpQneg4[24] = {};

    chV->SetBranchAddress("Noff", &gNoff);
    chV->SetBranchAddress("Mult", &gMult);
    chV->SetBranchAddress("NV0",  &gV0);

    chV->SetBranchAddress("wQGap2", &wQGap[2]);
    chV->SetBranchAddress("wV0QGap2", wV0QGap[2]);
    chV->SetBranchAddress("wQpGap2", wQpGap[2]);

	for ( int n = 2; n < 7; n++ ) {
		chV->SetBranchAddress(Form("rQGap%i", n), &rQGap[n]);
		chV->SetBranchAddress(Form("rV0QGap%i", n), rV0QGap[n]);
		chV->SetBranchAddress(Form("rQpGap%i", n), rQpGap[n]);
	}

	for ( int np = 0; np < 4; np++ ) {
		for ( int n = 2; n < 7; n++ ) {
			chV->SetBranchAddress( Form("rQ%i%i", n, 2+2*np), &rQ[n][np]);
			chV->SetBranchAddress( Form("rVQp%i%i", n, 2+2*np), &rVQp[n][np]);
		}
		int n = 2;
		chV->SetBranchAddress( Form("wQ%i%i", n, 2+2*np), &wQ[n][np]);
		chV->SetBranchAddress( Form("wVQp%i%i", n, 2+2*np), &wVQp[n][np]);
	}

    chV->SetBranchAddress("rQpos2", &rQpos2);
    chV->SetBranchAddress("wQpos2", &wQpos2);
    chV->SetBranchAddress("rVpQpos2", rVpQpos2);
    chV->SetBranchAddress("wVpQpos2", wVpQpos2);
    chV->SetBranchAddress("rQpos4", &rQpos4);
    chV->SetBranchAddress("wQpos4", &wQpos4);
    chV->SetBranchAddress("rVpQpos4", rVpQpos4);
    chV->SetBranchAddress("wVpQpos4", wVpQpos4);

    chV->SetBranchAddress("rQneg2", &rQneg2);
    chV->SetBranchAddress("wQneg2", &wQneg2);
    chV->SetBranchAddress("rVpQneg2", rVpQneg2);
    chV->SetBranchAddress("wVpQneg2", wVpQneg2);
    chV->SetBranchAddress("rQneg4", &rQneg4);
    chV->SetBranchAddress("wQneg4", &wQneg4);
    chV->SetBranchAddress("rVpQneg4", rVpQneg4);
    chV->SetBranchAddress("wVpQneg4", wVpQneg4);

	TH1D * hMult = new TH1D("hMult", "hMult", 1000, -0.5, 999.5);
	TH1D * hNoff = new TH1D("hNoff", "hNoff", 1000, -0.5, 999.5);
	TH1D * hV0M  = new TH1D("hV0M",  "hV0M",  1000, -0.5, 999.5);

	TH1D * hQ[7][4] = {};
	TH1D * hQw[7][4] = {};
	TH1D * hQp[7][4][24] = {};
	TH1D * hQwp[7][4][24] = {};

	TH1D * hQGap[7] = {};
	TH1D * hQwGap[7] = {};

	TH1D * hV0QGap[7][24] = {};
	TH1D * hV0QwGap[7][24] = {};

	TH1D * hQpGap[7][24] = {};
	TH1D * hQpwGap[7][24] = {};


	for ( int n = 2; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			hQ[n][np]  = new TH1D(Form("hQ%i%i", n, np), "", 600, 0, 600);
			hQw[n][np]  = new TH1D(Form("hQw%i%i", n, np), "", 600, 0, 600);
			for ( int i = 0; i < 24; i++ ) {
				hQp[n][np][i] = new TH1D(Form("hQp%i%i_%i", n, np, i), "", 600, 0, 600);
				hQwp[n][np][i] = new TH1D(Form("hQwp%i%i_%i", n, np, i), "", 600, 0, 600);
			}
		}
		hQGap[n] = new TH1D(Form("hQGap%i", n), "", 600, 0, 600);
		hQwGap[n] = new TH1D(Form("hQwGap%i", n), "", 600, 0, 600);
		for ( int i = 0; i < 24; i++ ) {
			hV0QGap[n][i] = new TH1D(Form("hV0QGap%i_%i", n, i), "", 600, 0, 600);
			hV0QwGap[n][i] = new TH1D(Form("hV0QwGap%i_%i", n, i), "", 600, 0, 600);

			hQpGap[n][i] = new TH1D(Form("hQpGap%i_%i", n, i), "", 600, 0, 600);
			hQpwGap[n][i] = new TH1D(Form("hQpwGap%i_%i", n, i), "", 600, 0, 600);
		}
	}

    TH1D * hQpos2 = new TH1D("hQpos2", "", 600, 0, 600);
    TH1D * hQneg2 = new TH1D("hQneg2", "", 600, 0, 600);
    TH1D * hwQpos2 = new TH1D("hwQpos2", "", 600, 0, 600);
    TH1D * hwQneg2 = new TH1D("hwQneg2", "", 600, 0, 600);
    TH1D * hQpos4 = new TH1D("hQpos4", "", 600, 0, 600);
    TH1D * hQneg4 = new TH1D("hQneg4", "", 600, 0, 600);
    TH1D * hwQpos4 = new TH1D("hwQpos4", "", 600, 0, 600);
    TH1D * hwQneg4 = new TH1D("hwQneg4", "", 600, 0, 600);

    TH1D * hVpQpos2[24] = {};
    TH1D * hVpQneg2[24] = {};
    TH1D * hwVpQpos2[24] = {};
    TH1D * hwVpQneg2[24] = {};
    TH1D * hVpQpos4[24] = {};
    TH1D * hVpQneg4[24] = {};
    TH1D * hwVpQpos4[24] = {};
    TH1D * hwVpQneg4[24] = {};

    for ( int i = 0; i < 24; i++ ) {
        hVpQpos2[i] = new TH1D(Form("hVpQpos2%i", i), "", 600, 0, 600);
        hVpQneg2[i] = new TH1D(Form("hVpQneg2%i", i), "", 600, 0, 600);
        hwVpQpos2[i] = new TH1D(Form("hwVpQpos2%i", i), "", 600, 0, 600);
        hwVpQneg2[i] = new TH1D(Form("hwVpQneg2%i", i), "", 600, 0, 600);

        hVpQpos4[i] = new TH1D(Form("hVpQpos4%i", i), "", 600, 0, 600);
        hVpQneg4[i] = new TH1D(Form("hVpQneg4%i", i), "", 600, 0, 600);
        hwVpQpos4[i] = new TH1D(Form("hwVpQpos4%i", i), "", 600, 0, 600);
        hwVpQneg4[i] = new TH1D(Form("hwVpQneg4%i", i), "", 600, 0, 600);
    }


	double dQ[7][4][600] = {};
	double yQ[7][4][600] = {};
	double dQp[7][4][24][600] = {};
	double yQp[7][4][24][600] = {};

	double dQGap[7][600] = {};
	double yQGap[7][600] = {};

	double dV0QGap[7][24][600] = {};
	double yV0QGap[7][24][600] = {};

	double dQpGap[7][24][600] = {};
	double yQpGap[7][24][600] = {};

    double dQpos2[600] = {};
    double yQpos2[600] = {};
    double dQneg2[600] = {};
    double yQneg2[600] = {};
    double dQpos4[600] = {};
    double yQpos4[600] = {};
    double dQneg4[600] = {};
    double yQneg4[600] = {};

    double dVpQpos2[24][600] = {};
    double yVpQpos2[24][600] = {};
    double dVpQneg2[24][600] = {};
    double yVpQneg2[24][600] = {};
    double dVpQpos4[24][600] = {};
    double yVpQpos4[24][600] = {};
    double dVpQneg4[24][600] = {};
    double yVpQneg4[24][600] = {};

	unsigned int ievt = 0;
	if ( s2 != s3 ) ievt = s2;
	while ( chV->GetEntry(ievt) ) {
		if ( !((ievt-s2)%100000) ) cout << "!! ievt = " << ievt << endl;
		if ( s2 == s3 ) ievt++;
		else ievt+= s3;

		if ( (gNoff>=600) or (gV0==0) ) {
			hNoff->Fill(gNoff);
			continue;
		}
		for ( int n = 3; n < 7; n++ ) {
			for ( int np = 0; np < 4; np++ ) {
				wQ[n][np] = wQ[2][np];
				for ( int i = 0; i < 24; i++ ) {
					wVQp[n][np][i] = wVQp[2][np][i];
				}
			}
			wQGap[n] = wQGap[2];
			for ( int i = 0; i < 24; i++ ) {
				wV0QGap[n][i] = wV0QGap[2][i];
				wQpGap[n][i] = wQpGap[2][i];
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
			dQGap[n][gNoff] += rQGap[n];
			yQGap[n][gNoff] += wQGap[n];
			for ( int i = 0; i < 24; i++ ) {
				dV0QGap[n][i][gNoff] += rV0QGap[n][i];
				yV0QGap[n][i][gNoff] += wV0QGap[n][i];

				dQpGap[n][i][gNoff] += rQpGap[n][i];
				yQpGap[n][i][gNoff] += wQpGap[n][i];
			}
		}

        dQpos2[gNoff] += rQpos2;
        yQpos2[gNoff] += wQpos2;
        dQneg2[gNoff] += rQneg2;
        yQneg2[gNoff] += wQneg2;
        dQpos4[gNoff] += rQpos4;
        yQpos4[gNoff] += wQpos4;
        dQneg4[gNoff] += rQneg4;
        yQneg4[gNoff] += wQneg4;
        for ( int i = 0; i < 24; i++ ) {
            dVpQpos2[i][gNoff] += rVpQpos2[i];
            yVpQpos2[i][gNoff] += wVpQpos2[i];
            dVpQneg2[i][gNoff] += rVpQneg2[i];
            yVpQneg2[i][gNoff] += wVpQneg2[i];

            dVpQpos4[i][gNoff] += rVpQpos4[i];
            yVpQpos4[i][gNoff] += wVpQpos4[i];
            dVpQneg4[i][gNoff] += rVpQneg4[i];
            yVpQneg4[i][gNoff] += wVpQneg4[i];
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
		for ( int c = 0; c < 600; c++ ) {
			hQGap[n]->SetBinContent( c+1, dQGap[n][c] );
			hQwGap[n]->SetBinContent( c+1, yQGap[n][c] );
			for ( int i = 0; i < 24; i++ ) {
				hV0QGap[n][i]->SetBinContent( c+1, dV0QGap[n][i][c] );
				hV0QwGap[n][i]->SetBinContent( c+1, yV0QGap[n][i][c] );

				hQpGap[n][i]->SetBinContent( c+1, dQpGap[n][i][c] );
				hQpwGap[n][i]->SetBinContent( c+1, yQpGap[n][i][c] );
			}
		}
	}

    for ( int c = 0; c < 600; c++ ) {
        hQpos2->SetBinContent( c+1, dQpos2[c] );
        hQneg2->SetBinContent( c+1, dQneg2[c] );
        hQpos4->SetBinContent( c+1, dQpos4[c] );
        hQneg4->SetBinContent( c+1, dQneg4[c] );

        hwQpos2->SetBinContent( c+1, yQpos2[c] );
        hwQneg2->SetBinContent( c+1, yQneg2[c] );
        hwQpos4->SetBinContent( c+1, yQpos4[c] );
        hwQneg4->SetBinContent( c+1, yQneg4[c] );

        for ( int i = 0; i < 24; i++ ) {
            hVpQpos2[i]->SetBinContent( c+1, dVpQpos2[i][c] );
            hVpQneg2[i]->SetBinContent( c+1, dVpQneg2[i][c] );
            hVpQpos4[i]->SetBinContent( c+1, dVpQpos4[i][c] );
            hVpQneg4[i]->SetBinContent( c+1, dVpQneg4[i][c] );

            hwVpQpos2[i]->SetBinContent( c+1, yVpQpos2[i][c] );
            hwVpQneg2[i]->SetBinContent( c+1, yVpQneg2[i][c] );
            hwVpQpos4[i]->SetBinContent( c+1, yVpQpos4[i][c] );
            hwVpQneg4[i]->SetBinContent( c+1, yVpQneg4[i][c] );
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
		hQGap[n]->Write();
		hQwGap[n]->Write();
		for ( int i = 0; i < 24; i++ ) {
			hV0QGap[n][i]->Write();
			hV0QwGap[n][i]->Write();

			hQpGap[n][i]->Write();
			hQpwGap[n][i]->Write();
		}
	}
    hQpos2->Write();
    hQneg2->Write();
    hwQpos2->Write();
    hwQneg2->Write();
    hQpos4->Write();
    hQneg4->Write();
    hwQpos4->Write();
    hwQneg4->Write();
    for ( int i = 0; i < 24; i++ ) {
        hVpQpos2[i]->Write();
        hVpQneg2[i]->Write();
        hVpQpos4[i]->Write();
        hVpQneg4[i]->Write();

        hwVpQpos2[i]->Write();
        hwVpQneg2[i]->Write();
        hwVpQpos4[i]->Write();
        hwVpQneg4[i]->Write();
    }

	hNoff->Write();
	hMult->Write();
	hV0M->Write();
}
