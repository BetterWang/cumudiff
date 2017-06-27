#include "label.h"
#include "noff.h"

#include <TFile.h>
#include <TH1.h>
using namespace std;
void bGet(int s1 = 1, int s2 = 10, int s3 = 10)
{
	cout << " s1 = " << s1 << " s2 = " << s2 << " s3 = " << s3 << endl;
	TH1::SetDefaultSumw2();
	int NCent = NCent8TeV4;
	const int * pCent = CentNoffCutPA8TeV4;

	TFile * f = new TFile(Form("%s/output_%i_%i.root", ftxt[s1], s2, s3));

	TH1D * hNoff = (TH1D*) f->Get("hNoff");
	TH1D * hMult = (TH1D*) f->Get("hMult");
	TH1D * hV0M  = (TH1D*) f->Get("hV0M");

	TH1D * hQ[7][4] = {};
	TH1D * hQw[7][4] = {};
	TH1D * hQp[7][4][24] = {};
	TH1D * hQwp[7][4][24] = {};

	for ( int n = 2; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			hQ[n][np] = (TH1D*) f->Get(Form("hQ%i%i", n, np));
			hQw[n][np] = (TH1D*) f->Get(Form("hQw%i%i", n, np));
			for ( int i = 0; i < 24; i++ ) {
				hQp[n][np][i] = (TH1D*) f->Get(Form("hQp%i%i_%i", n, np, i));
				hQwp[n][np][i] = (TH1D*) f->Get(Form("hQwp%i%i_%i", n, np, i));
			}
		}
	}

	double dQ[7][4][600];
	double wQ[7][4][600];
	double dQp[7][4][24][600];
	double wQp[7][4][24][600];

	for ( int n = 2; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			for ( int c = 0; c < 600; c++ ) {
				dQ[n][np][c] = hQ[n][np]->GetBinContent( c+1 );
				wQ[n][np][c] = hQw[n][np]->GetBinContent( c+1 );
				if ( wQ[n][np][c] > 0. ) dQ[n][np][c] /= wQ[n][np][c];

				for ( int i = 0; i < 24; i++ ) {
					dQp[n][np][i][c] = hQp[n][np][i]->GetBinContent( c+1 );
					wQp[n][np][i][c] = hQwp[n][np][i]->GetBinContent( c+1 );
					if ( wQp[n][np][i][c] > 0. ) dQp[n][np][i][c] /= wQp[n][np][i][c];
					//cout << " dQp[" << n << "][" << np << "][" << i << "][" << c << "] = " << dQp[n][np][i][c] << endl;
				}
			}
		}
	}


	double dCraw[7][4][600];
	double dCpraw[7][4][24][600];

	for ( int n = 2; n < 7; n++ ) {
		for ( int c = 0; c < 600; c++ ) {
			double Q2 = dQ[n][0][c];
			double Q4 = dQ[n][1][c];
			double Q6 = dQ[n][2][c];
			double Q8 = dQ[n][3][c];

			dCraw[n][0][c] = Q2;
			dCraw[n][1][c] = Q4 - 2*Q2*Q2;
			dCraw[n][2][c] = Q6 - 9*Q2*Q4 + 12*Q2*Q2*Q2;
			dCraw[n][3][c] = Q8 - 16*Q6*Q2 - 18*Q4*Q4 + 144*Q4*Q2*Q2 -144*Q2*Q2*Q2*Q2;
		}
		for ( int i = 0; i < 24; i++ ) {
			for ( int c = 0; c < 600; c++ ) {
				double Q2p = dQp[n][0][i][c];
				double Q4p = dQp[n][1][i][c];
				double Q6p = dQp[n][2][i][c];
				double Q8p = dQp[n][3][i][c];

				double Q2 = dQ[n][0][c];
				double Q4 = dQ[n][1][c];
				double Q6 = dQ[n][2][c];
				double Q8 = dQ[n][3][c];

				dCpraw[n][0][i][c] = Q2p;
				dCpraw[n][1][i][c] = Q4p - 2*Q2*Q2p;
				dCpraw[n][2][i][c] = Q6p - 6*Q2*Q4p - 3*Q2p*Q4 + 12*Q2p*Q2*Q2;
				dCpraw[n][3][i][c] = Q8p - 12*Q2*Q6p - 4*Q2p*Q6 - 18*Q4p*Q4 + 72*Q4p*Q2*Q2 + 72*Q4*Q2p*Q2 - 144*Q2p*Q2*Q2*Q2;
			}
		}
	}

	// rebin

	double dC[7][4][20];
	double wC[7][4][20];
	double dCp[7][4][24][20];
	double wCp[7][4][24][20];

	for ( int n = 2; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			for ( int c = 0; c < NCent; c++ ) {
				double sum = 0;
				double weight = 0;
				for ( int m = pCent[c]; m < pCent[c+1]; m++ ) {
					sum += dCraw[n][np][m] * wQ[n][np][m];
					weight += wQ[n][np][m];
				}
				if ( weight > 0. ) sum /= weight;
				dC[n][np][c] = sum;
				wC[n][np][c] = weight;
			}
			for ( int i = 0; i < 24; i++ ) {
				for ( int c = 0; c < NCent; c++ ) {
					double sum = 0;
					double weight = 0;
					for ( int m = pCent[c]; m < pCent[c+1]; m++ ) {
						sum += dCpraw[n][np][i][m] * wQp[n][np][i][m];
						weight += wQp[n][np][i][m];
					}
					//cout << " i = " << i << "\tc = " << c << "\tsum = " << sum << "\tweight = " << weight << endl;
					if ( weight > 0. ) sum /= weight;
					dCp[n][np][i][c] = sum;
					wCp[n][np][i][c] = weight;
				}
			}
		}
	}



	TH1D * hCraw[7][4] = {};
	TH1D * hCwraw[7][4] = {};
	TH1D * hCpraw[7][4][24] = {};
	TH1D * hCwpraw[7][4][24] = {};

	TH1D * hC[7][4] = {};
	TH1D * hCw[7][4] = {};
	TH1D * hCp[7][4][24] = {};
	TH1D * hCwp[7][4][24] = {};

	for ( int n = 2; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			hCraw[n][np] = new TH1D(Form("hCraw%i%i", n, np), "", 600, 0, 600);
			hCwraw[n][np] = new TH1D(Form("hCwraw%i%i", n, np), "", 600, 0, 600);

			hC[n][np] = new TH1D(Form("hC%i%i", n, np), "", 20, 0, 20);
			hCw[n][np] = new TH1D(Form("hCw%i%i", n, np), "", 20, 0, 20);

			for ( int i = 0; i < 24; i++ ) {
				hCpraw[n][np][i] = new TH1D(Form("hCpraw%i%i_%i", n, np, i), "", 600, 0, 600);
				hCwpraw[n][np][i] = new TH1D(Form("hCwpraw%i%i_%i", n, np, i), "", 600, 0, 600);

				hCp[n][np][i] = new TH1D(Form("hCp%i%i_%i", n, np, i), "", 20, 0, 20);
				hCwp[n][np][i] = new TH1D(Form("hCwp%i%i_%i", n, np, i), "", 20, 0, 20);
			}
		}
	}

	for ( int n = 2; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			for ( int c = 0; c < 600; c++ ) {
				hCraw[n][np]->SetBinContent(c+1, dCraw[n][np][c]);
				hCwraw[n][np]->SetBinContent(c+1, wQ[n][np][c]);
			}
			for ( int c = 0; c < 20; c++ ) {
				hC[n][np]->SetBinContent(c+1, dC[n][np][c]);
				hCw[n][np]->SetBinContent(c+1, wC[n][np][c]);
			}
			for ( int i = 0; i < 24; i++ ) {
				for ( int c = 0; c < 600; c++ ) {
					hCpraw[n][np][i]->SetBinContent(c+1, dCpraw[n][np][i][c]);
					hCwpraw[n][np][i]->SetBinContent(c+1, wQp[n][np][i][c]);
				}
				for ( int c = 0; c < 20; c++ ) {
					hCp[n][np][i]->SetBinContent(c+1, dCp[n][np][i][c]);
					hCwp[n][np][i]->SetBinContent(c+1, wCp[n][np][i][c]);
					//cout << " dCp[" << n << "][" << np << "][" << i << "][" << c << "] = " << wCp[n][np][i][c] << endl;
				}
			}
		}
	}

	TH1D * hNoffR = new TH1D("hNoffR", "hNoffR", 20, 0, 20);
	for ( int c = 0; c < NCent; c++ ) {
		double sum = 0;
		for ( int m = pCent[c]; m < pCent[c+1]; m++ ) {
			sum += hNoff->GetBinContent(m+1);
		}
		hNoffR->SetBinContent(c+1, sum);
	}


	TFile * fsave = new TFile(Form("%s/outputC_%i_%i.root", ftxt[s1], s2, s3), "recreate");
	for ( int n = 2; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			hCraw[n][np]->Write();
			hCwraw[n][np]->Write();

			hC[n][np]->Write();
			hCw[n][np]->Write();
			for ( int i = 0; i < 24; i++ ) {
				hCpraw[n][np][i]->Write();
				hCwpraw[n][np][i]->Write();

				hCp[n][np][i]->Write();
				hCwp[n][np][i]->Write();
			}
		}
	}

	hNoff->Write();
	hMult->Write();
	hV0M->Write();
	hNoffR->Write();
}
