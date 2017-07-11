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

	double dCGap[50][7][20];
	double wCGap[50][7][20];
	double dCpGap[50][7][24][20];
	double wCpGap[50][7][24][20];

	double dpCpGap[50][7][24][20];
	double wpCpGap[50][7][24][20];

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
			TH1D * h1 = (TH1D*) f->Get(Form("hCGap%i", n));
			TH1D * h2 = (TH1D*) f->Get(Form("hCGapw%i", n));
			for ( int c = 0; c < 20; c++ ) {
				dCGap[fn][n][c] = h1->GetBinContent(c+1);
				wCGap[fn][n][c] = h2->GetBinContent(c+1);
			}
			delete h1;
			delete h2;
			for ( int i = 0; i < 24; i++ ) {
				TH1D * h1 = (TH1D*) f->Get(Form("hCGapp%i_%i", n, i));
				TH1D * h2 = (TH1D*) f->Get(Form("hCGapwp%i_%i", n, i));
				for ( int c = 0; c < 20; c++ ) {
					dCpGap[fn][n][i][c] = h1->GetBinContent( c+1 );
					wCpGap[fn][n][i][c] = h2->GetBinContent( c+1 );
				}

				h1 = (TH1D*) f->Get(Form("hpCGapp%i_%i", n, i));
				h2 = (TH1D*) f->Get(Form("hpCGapwp%i_%i", n, i));
				for ( int c = 0; c < 20; c++ ) {
					dpCpGap[fn][n][i][c] = h1->GetBinContent( c+1 );
					wpCpGap[fn][n][i][c] = h2->GetBinContent( c+1 );
				}
			}
		}
	}

	// C->V
	double dV[50][7][4][20];
	double dVp[50][7][4][24][20];

	double dVGap[50][7][20];
	double dVpGap[50][7][24][20];

	double dpVpGap[50][7][24][20];

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

				double C2Gap = dCGap[fn][n][i];
				if ( C2Gap > 0 ) V2 = pow(C2Gap, 1./2); else V2 = -pow(-C2Gap, 1./2);
				dVGap[fn][n][i] = V2;

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

					double C2pGap = dCpGap[fn][n][j][i];
					if ( C2pGap >= 0 ) V2 =       C2pGap/pow(C2Gap, 1./2) ; else V2 = -fabs(C2pGap/pow(-C2Gap, 1./2));
					if ( C2Gap == 0. ) V2 = 0;
					dVpGap[fn][n][j][i] = V2;

					C2pGap = dpCpGap[fn][n][j][i];
					if ( C2pGap >= 0 ) V2 =       C2pGap/pow(C2Gap, 1./2) ; else V2 = -fabs(C2pGap/pow(-C2Gap, 1./2));
					if ( C2Gap == 0. ) V2 = 0;
					dpVpGap[fn][n][j][i] = V2;
				}
			}
		}
	}

	// Get Error
	double eC[7][4][20];
	double eCp[7][4][24][20];
	double eV[7][4][20];
	double eVp[7][4][24][20];

	double eCGap[7][20];
	double eCpGap[7][24][20];
	double eVGap[7][20];
	double eVpGap[7][24][20];

	double epCpGap[7][24][20];
	double epVpGap[7][24][20];

	for ( int n = 2; n < 7; n++ ) {
		for ( int i = 0; i < 20; i++ ) {
			double sumC = 0;
			for ( int fn = 0; fn < s3; fn++ ) {
				sumC += (dCGap[fn][n][i] - dCGap[s3][n][i]) * (dCGap[fn][n][i] - dCGap[s3][n][i]);
			}
			double errC = sqrt( sumC ) / s3;
			eCGap[n][i] = errC;

			double te = dVGap[s3][n][i]*errC/dCGap[s3][n][i]/2.;
			if ( te != te ) te = 9999;
			eVGap[n][i] = te;
			for ( int j = 0; j < 24; j++ ) {
				double sumCp = 0;
				for ( int fn = 0; fn < s3; fn++ ) {
					sumCp += (dCpGap[fn][n][j][i] - dCpGap[s3][n][j][i]) * (dCpGap[fn][n][j][i] - dCpGap[s3][n][j][i]);
				}
				double errCp = sqrt( sumCp ) /s3;
				eCpGap[n][j][i] = errCp;
				double te = sqrt( errCp*errCp/dCpGap[s3][n][j][i]/dCpGap[s3][n][j][i]
						+ 0.25*errC*errC/dCGap[s3][n][i]/dCGap[s3][n][i])*fabs(dVpGap[s3][n][j][i]);
				if ( te != te ) te = 9999;
				eVpGap[n][j][i] = te;


				sumCp = 0;
				for ( int fn = 0; fn < s3; fn++ ) {
					sumCp += (dpCpGap[fn][n][j][i] - dpCpGap[s3][n][j][i]) * (dpCpGap[fn][n][j][i] - dpCpGap[s3][n][j][i]);
				}
				errCp = sqrt( sumCp ) /s3;
				epCpGap[n][j][i] = errCp;
				te = sqrt( errCp*errCp/dCpGap[s3][n][j][i]/dpCpGap[s3][n][j][i]
						+ 0.25*errC*errC/dCGap[s3][n][i]/dCGap[s3][n][i])*fabs(dpVpGap[s3][n][j][i]);
				if ( te != te ) te = 9999;
				epVpGap[n][j][i] = te;
			}

			//
			for ( int np = 0; np < 4; np++ ) {
				double sumC = 0;
				for ( int fn = 0; fn < s3; fn++ ) {
					sumC += (dC[fn][n][np][i] - dC[s3][n][np][i]) * (dC[fn][n][np][i] - dC[s3][n][np][i]);
				}
				double errC = sqrt( sumC ) / s3;
				eC[n][np][i] = errC;

				double te = dV[s3][n][np][i]/(2+2*np)*errC/dC[s3][n][np][i];
				if ( te != te ) te = 9990;
				eV[n][np][i] = te;

				for ( int j = 0; j < 24; j++ ) {
					double sumCp = 0;
					for ( int fn = 0; fn < s3; fn++ ) {
						sumCp += (dCp[fn][n][np][j][i] - dCp[s3][n][np][j][i]) * (dCp[fn][n][np][j][i] - dCp[s3][n][np][j][i]);
					}

					double errCp = sqrt( sumCp ) /s3;
					eCp[n][np][j][i] = errCp;
					te = sqrt( errCp*errCp/dCp[s3][n][np][j][i]/dCp[s3][n][np][j][i]
						+ (1+2*np)*(1+2*np)/(2+2*np)/(2+2*np)*errC*errC/dC[s3][n][np][i]/dC[s3][n][np][i])*fabs(dVp[s3][n][np][j][i]);
					if ( np == 2 ) te /= pow(4., 1./6);
					if ( np == 3 ) te /= pow(33., 1./8);
					if ( te != te ) te = 9999;
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

	TH1D * fCGap[7];
	TH1D * fVGap[7];
	TH1D * fCpGap[7][24];
	TH1D * fVpGap[7][24];

	TH1D * fpCpGap[7][24];
	TH1D * fpVpGap[7][24];

	for ( int n = 2; n < 7; n++ ) {
		fCGap[n] = (TH1D*) fr[s3]->Get(Form("hCGap%i", n));
		fVGap[n] = new TH1D(Form("hVGap%i", n), "", 20, 0, 20);
		for ( int i = 0; i < 20; i++ ) {
			fCGap[n]->SetBinError( i+1, eCGap[n][i] );

			fVGap[n]->SetBinContent( i+1, dVGap[s3][n][i] );
			fVGap[n]->SetBinError( i+1, eVGap[n][i] );
		}

		for ( int j = 0; j < 24; j++ ) {
			fCpGap[n][j] = (TH1D*) fr[s3]->Get(Form("hCGapp%i_%i", n, j));
			fVpGap[n][j] = new TH1D(Form("hVpGap%i_%i", n, j), "", 20, 0, 20);

			fpCpGap[n][j] = (TH1D*) fr[s3]->Get(Form("hpCGapp%i_%i", n, j));
			fpVpGap[n][j] = new TH1D(Form("hpVpGap%i_%i", n, j), "", 20, 0, 20);
			for ( int i = 0; i < 20; i++ ) {
				fCpGap[n][j]->SetBinError(i+1, eCpGap[n][j][i]);
				fVpGap[n][j]->SetBinContent(i+1, dVpGap[s3][n][j][i]);
				fVpGap[n][j]->SetBinError(i+1, eVpGap[n][j][i]);

				fpCpGap[n][j]->SetBinError(i+1, epCpGap[n][j][i]);
				fpVpGap[n][j]->SetBinContent(i+1, dpVpGap[s3][n][j][i]);
				fpVpGap[n][j]->SetBinError(i+1, epVpGap[n][j][i]);
			}
		}

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
		fCGap[n]->Write();
		fVGap[n]->Write();
		for ( int i = 0; i < 24; i++ ) {
			fCpGap[n][i]->Write();
			fVpGap[n][i]->Write();

			fpCpGap[n][i]->Write();
			fpVpGap[n][i]->Write();
		}
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

