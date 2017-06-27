#include "label.h"
#include "noff.h"
#include <iostream>
#include <TFile.h>
#include <TH1.h>

void bGetError(int s1 = 1, int s3 = 10)
{

	std::cout << "s1 = " << s1 << "\ts3 = " << s3 << std::endl;

	// Get TFile
	TFile *fr[50];
	for ( int i = 0; i <= s3; i++ ) {
		fr[i] = new TFile(Form("%s/outputC_%i_%i.root", ftxt[s1], i, s3));
	}


	double dC[50][7][4][20];
	double wC[50][7][4][20];

	double dCp[50][7][4][24][20];
	double wCp[50][7][4][24][20];

	// Get
	for ( int fn = 0; fn <= s3; fn++ ) {
		TFile * f = fr[fn];
		for ( int n = 2; n < 7; n++ ) {
			for ( int np = 0; np < 4; np++ ) {
				TH1D * h1 = (TH1D*) f->Get(Form("hC%i%i", n, np));
				TH1D * h2 = (TH1D*) f->Get(Form("hCw%i%i", n, np));
				for ( int i = 0; i < 20; i++ ) {
					dC[fn][n][np][i] = h1->GetBinContent(i+1);
					wC[fn][n][np][i] = h2->GetBinContent(i+1);
				}
				delete h1;
				delete h2;

				for ( int j = 0; j < 24; j++ ) {
					TH1D * h1 = (TH1D*) f->Get(Form("hCp%i%i_%i", n, np, j));
					TH1D * h2 = (TH1D*) f->Get(Form("hCwp%i%i_%i", n, np, j));
					for ( int i = 0; i < 20; i++ ) {
						dCp[fn][n][np][j][i] = h1->GetBinContent(i+1);
						wCp[fn][n][np][j][i] = h2->GetBinContent(i+1);
					}
					delete h1;
					delete h2;
				}
			}
		}
	}

	// C->V
	double dV[50][7][4][20];
	double dVp[50][7][4][24][20];

	for ( int fn = 0; fn <= s3; fn++ ) {
		for ( int n = 2; n < 7; n++ ) {
			for ( int i = 0; i < 20; i++ ) {
				double C2 = dC[fn][n][0][i];
				double C4 = dC[fn][n][1][i];
				double C6 = dC[fn][n][2][i];
				double C8 = dC[fn][n][3][i];

				double V2, V4, V6, V8;

				if ( C2 > 0 ) V2 = pow(C2, 1./2); else V2 = -pow(-C2, 1./2);
				if ( C4 > 0 ) V4 = -pow(C4, 1./4); else V4 = pow(-C4, 1./4);
				if ( C6 > 0 ) V6 = pow(C6/4., 1./6); else V6 = -pow(-C6/4., 1./6);
				if ( C8 > 0 ) V8 = -pow(C8/33., 1./8); else V8 = pow(-C8/33., 1./8);

				dV[fn][n][0][i] = V2;
				dV[fn][n][1][i] = V4;
				dV[fn][n][2][i] = V6;
				dV[fn][n][3][i] = V8;
				for ( int j = 0; j < 24; j++ ) {
					double C2p = dCp[fn][n][0][j][i];
					double C4p = dCp[fn][n][1][j][i];
					double C6p = dCp[fn][n][2][j][i];
					double C8p = dCp[fn][n][3][j][i];

					if ( C2 > 0 ) V2 =       C2p/pow(C2, 1./2) ; else V2 = -fabs(C2p/pow(-C2, 1./2));
					if ( C4 > 0 ) V4 = -fabs(C4p/pow(C4, 3./4)); else V4 =      -C4p/pow(-C4, 3./4);
					if ( C6 > 0 ) V6 =       C6p/pow(C6/4., 5./6)/4. ; else V6 = -fabs(C6p/pow(-C6/4., 5./6))/4.;
					if ( C8 > 0 ) V8 = -fabs(C8p/pow(C8/33., 7./8))/33.; else V8 =      -C8p/pow(-C8/33., 7./8)/33.;

					if (V2 != V2 ) V2 = 0;
					if (V4 != V4 ) V4 = 0;
					if (V6 != V6 ) V6 = 0;
					if (V8 != V8 ) V8 = 0;

					dVp[fn][n][0][j][i] = V2;
					dVp[fn][n][1][j][i] = V4;
					dVp[fn][n][2][j][i] = V6;
					dVp[fn][n][3][j][i] = V8;
				}
			}
		}
	}

	// Get Error
	double eC[7][4][20];
	double eCp[7][4][24][20];

	double eV[7][4][20];
	double eVp[7][4][24][20];

	for ( int n = 2; n < 7; n++ ) {
		for ( int i = 0; i < 20; i++ ) {
			for ( int np = 0; np < 4; np++ ) {
				double sumC = 0;
				for ( int fn = 0; fn < s3; fn++ ) {
					sumC += (dC[fn][n][np][i] - dC[s3][n][np][i]) * (dC[fn][n][np][i] - dC[s3][n][np][i]);
				}
				double errC = sqrt( sumC ) / s3;
				eC[n][np][i] = errC;

				double te = dV[s3][n][np][i]/(2+2*np)*errC/dC[s3][n][np][i];
				if ( te != te ) te = 0;
				eV[n][np][i] = te;

				for ( int j = 0; j < 24; j++ ) {
					double sumCp = 0;
					for ( int fn = 0; fn < s3; fn++ ) {
						sumCp += (dCp[fn][n][np][j][i] - dCp[s3][n][np][j][i]) * (dCp[fn][n][np][j][i] - dCp[s3][n][np][j][i]);
					}

					double errCp = sqrt( sumC ) /s3;
					eCp[n][np][j][i] = errCp;
					te = sqrt( errCp*errCp/dCp[s3][n][np][j][i]/dCp[s3][n][np][j][i]
						+ (1+2*np)*(1+2*np)/(2+2*np)/(2+2*np)*errC*errC/dC[s3][n][np][i]/dC[s3][n][np][i])*fabs(dVp[s3][n][np][j][i]);
					if ( np == 2 ) te /= pow(4., 1./6);
					if ( np == 3 ) te /= pow(33., 1./8);
					if ( te != te ) te = 0;
					eVp[n][np][j][i] = te;
				}
			}
		}
	}


	// Histo

	TH1D * fC[7][4];
	TH1D * fV[7][4];
	TH1D * fCp[7][4][24];
	TH1D * fVp[7][4][24];

	for ( int n = 2; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			fC[n][np] = (TH1D*) fr[s3]->Get(Form("hC%i%i", n, np));
			fV[n][np] = new TH1D(Form("hV%i%i", n, np), "", 20, 0, 20);
			for ( int i = 0; i < 20; i++ ) {
				fC[n][np]->SetBinError(i+1, eC[n][np][i]);

				fV[n][np]->SetBinContent(i+1, dV[s3][n][np][i]);
				fV[n][np]->SetBinError(i+1, eV[n][np][i]);
			}
			for ( int j = 0; j < 24; j++ ) {
				fCp[n][np][j] = (TH1D*) fr[s3]->Get(Form("hCp%i%i_%i", n, np, j));
				fVp[n][np][j] = new TH1D(Form("hVp%i%i_%i", n, np, j), "", 20, 0, 20);
				for ( int i = 0; i < 20; i++ ) {
					fCp[n][np][j]->SetBinError(i+1, eCp[n][np][j][i]);

					fVp[n][np][j]->SetBinContent(i+1, dVp[s3][n][np][j][i]);
					fVp[n][np][j]->SetBinError(i+1, eVp[n][np][j][i]);
				}
			}
		}
	}


	// Save

        TFile * fwrite = new TFile(Form("%s/outputE.root", ftxt[s1]), "recreate");
	for ( int n = 2; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			fC[n][np]->Write();
			fV[n][np]->Write();
			for ( int i = 0; i < 24; i++ ) {
				fCp[n][np][i]->Write();
				fVp[n][np][i]->Write();
			}
		}
	}
}

