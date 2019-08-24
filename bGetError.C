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

    // subevent
    double dCPos2[50][20] = {};
    double dCNeg2[50][20] = {};
    double dCPos4[50][20] = {};
    double dCNeg4[50][20] = {};

    double wCPos2[50][20] = {};
    double wCNeg2[50][20] = {};
    double wCPos4[50][20] = {};
    double wCNeg4[50][20] = {};

    double dCpPos2[50][24][20] = {};
    double dCpNeg2[50][24][20] = {};
    double dCpPos4[50][24][20] = {};
    double dCpNeg4[50][24][20] = {};

    double wCpPos2[50][24][20] = {};
    double wCpNeg2[50][24][20] = {};
    double wCpPos4[50][24][20] = {};
    double wCpNeg4[50][24][20] = {};

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

        TH1D * hCPos2 = (TH1D*) f->Get("hCPos2");
        TH1D * hCNeg2 = (TH1D*) f->Get("hCNeg2");
        TH1D * hCPos4 = (TH1D*) f->Get("hCPos4");
        TH1D * hCNeg4 = (TH1D*) f->Get("hCNeg4");
        TH1D * hwCPos2 = (TH1D*) f->Get("hwCPos2");
        TH1D * hwCNeg2 = (TH1D*) f->Get("hwCNeg2");
        TH1D * hwCPos4 = (TH1D*) f->Get("hwCPos4");
        TH1D * hwCNeg4 = (TH1D*) f->Get("hwCNeg4");
        for ( int c = 0; c < 20; c++ ) {
            dCPos2[fn][c] = hCPos2->GetBinContent( c+1 );
            dCNeg2[fn][c] = hCNeg2->GetBinContent( c+1 );
            dCPos4[fn][c] = hCPos4->GetBinContent( c+1 );
            dCNeg4[fn][c] = hCNeg4->GetBinContent( c+1 );

            wCPos2[fn][c] = hwCPos2->GetBinContent( c+1 );
            wCNeg2[fn][c] = hwCNeg2->GetBinContent( c+1 );
            wCPos4[fn][c] = hwCPos4->GetBinContent( c+1 );
            wCNeg4[fn][c] = hwCNeg4->GetBinContent( c+1 );
        }

        for ( int i = 0; i < 24; i++ ) {
            TH1D * hCpPos2 = (TH1D*) f->Get(Form("hCpPos2%i", i));
            TH1D * hCpNeg2 = (TH1D*) f->Get(Form("hCpNeg2%i", i));
            TH1D * hCpPos4 = (TH1D*) f->Get(Form("hCpPos4%i", i));
            TH1D * hCpNeg4 = (TH1D*) f->Get(Form("hCpNeg4%i", i));
            TH1D * hwCpPos2 = (TH1D*) f->Get(Form("hwCpPos2%i", i));
            TH1D * hwCpNeg2 = (TH1D*) f->Get(Form("hwCpNeg2%i", i));
            TH1D * hwCpPos4 = (TH1D*) f->Get(Form("hwCpPos4%i", i));
            TH1D * hwCpNeg4 = (TH1D*) f->Get(Form("hwCpNeg4%i", i));
            for ( int c = 0; c < 20; c++ ) {
                dCpPos2[fn][i][c] = hCpPos2->GetBinContent( c+1 );
                dCpNeg2[fn][i][c] = hCpNeg2->GetBinContent( c+1 );
                dCpPos4[fn][i][c] = hCpPos4->GetBinContent( c+1 );
                dCpNeg4[fn][i][c] = hCpNeg4->GetBinContent( c+1 );
                wCpPos2[fn][i][c] = hwCpPos2->GetBinContent( c+1 );
                wCpNeg2[fn][i][c] = hwCpNeg2->GetBinContent( c+1 );
                wCpPos4[fn][i][c] = hwCpPos4->GetBinContent( c+1 );
                wCpNeg4[fn][i][c] = hwCpNeg4->GetBinContent( c+1 );
            }
        }
	}

	// C->V
	double dV[50][7][4][20];
	double dVp[50][7][4][24][20];

	double dVGap[50][7][20];
	double dVpGap[50][7][24][20];

	double dpVpGap[50][7][24][20];

    double dVsub2pos[50][20];
    double dVsub4pos[50][20];
    double dpVsub2pos[50][24][20];
    double dpVsub4pos[50][24][20];

    double dVsub2neg[50][20];
    double dVsub4neg[50][20];
    double dpVsub2neg[50][24][20];
    double dpVsub4neg[50][24][20];

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

        for ( int c = 0; c < 20; c++ ) {
            double C2p = dCPos2[fn][c];
            double C2n = dCNeg2[fn][c];
            double C4p = dCPos4[fn][c];
            double C4n = dCNeg4[fn][c];

            double V2p, V2n, V4p, V4n;

            if ( C2p > 0 ) V2p = pow(C2p, 1./2); else V2p = -pow(-C2p, 1./2);
            if ( C2n > 0 ) V2n = pow(C2n, 1./2); else V2n = -pow(-C2n, 1./2);
            if ( C4p > 0 ) V4p = -pow(C4p, 1./4); else V4p = pow(-C4p, 1./4);
            if ( C4n > 0 ) V4n = -pow(C4n, 1./4); else V4n = pow(-C4n, 1./4);

            dVsub2pos[fn][c] = V2p;
            dVsub4pos[fn][c] = V4p;
            dVsub2neg[fn][c] = V2n;
            dVsub4neg[fn][c] = V4n;

            for ( int i = 0; i < 24; i++ ) {
                double pC2p = dCpPos2[fn][i][c];
                double pC2n = dCpNeg2[fn][i][c];
                double pC4p = dCpPos4[fn][i][c];
                double pC4n = dCpNeg4[fn][i][c];

                if ( C2n > 0 ) V2p = pC2p/pow(C2n, 1./2); else V2p = -fabs( pC2p/pow(-C2n, 1./2) );
                if ( C2p > 0 ) V2n = pC2n/pow(C2p, 1./2); else V2n = -fabs( pC2n/pow(-C2p, 1./2) );
                if ( C4n > 0 ) V4p = -fabs(pC4p/pow(C4n, 3./4)); else V4p = -pC4p/pow(-C4n, 3./4);
                if ( C4p > 0 ) V4n = -fabs(pC4n/pow(C4p, 3./4)); else V4n = -pC4n/pow(-C4p, 3./4);

                if ( (V2p != V2p) or (abs(V2p)==std::numeric_limits<double>::infinity()) ) V2p = 0;
                if ( (V4p != V4p) or (abs(V4p)==std::numeric_limits<double>::infinity()) ) V4p = 0;
                if ( (V2n != V2n) or (abs(V2n)==std::numeric_limits<double>::infinity()) ) V2n = 0;
                if ( (V4n != V4n) or (abs(V4n)==std::numeric_limits<double>::infinity()) ) V4n = 0;

                dpVsub2pos[fn][i][c] = V2p;
                dpVsub4pos[fn][i][c] = V4p;
                dpVsub2neg[fn][i][c] = V2n;
                dpVsub4neg[fn][i][c] = V4n;
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

    double eCsub2pos[20];
    double eCsub4pos[20];
    double eCsub2neg[20];
    double eCsub4neg[20];

    double epCsub2pos[24][20];
    double epCsub4pos[24][20];
    double epCsub2neg[24][20];
    double epCsub4neg[24][20];

    for ( int c = 0; c < 20; c++ ) {
        double sumCp2 = 0;
        double sumCn2 = 0;
        double sumCp4 = 0;
        double sumCn4 = 0;
        for ( int fn = 0; fn < s3; fn++ ) {
            sumCp2 += (dCPos2[fn][c] - dCPos2[s3][c]) * (dCPos2[fn][c] - dCPos2[s3][c]);
            sumCn2 += (dCNeg2[fn][c] - dCNeg2[s3][c]) * (dCNeg2[fn][c] - dCNeg2[s3][c]);
            sumCp4 += (dCPos4[fn][c] - dCPos4[s3][c]) * (dCPos4[fn][c] - dCPos4[s3][c]);
            sumCn4 += (dCNeg4[fn][c] - dCNeg4[s3][c]) * (dCNeg4[fn][c] - dCNeg4[s3][c]);
        }
        double errCp2 = sqrt( sumCp2 ) / s3;
        double errCn2 = sqrt( sumCn2 ) / s3;
        double errCp4 = sqrt( sumCp4 ) / s3;
        double errCn4 = sqrt( sumCn4 ) / s3;
        eCsub2pos[c] = errCp2;
        eCsub2neg[c] = errCn2;
        eCsub4pos[c] = errCp4;
        eCsub4neg[c] = errCn4;

        for ( int i = 0; i < 24; i++ ) {
            double sumCp2 = 0;
            double sumCn2 = 0;
            double sumCp4 = 0;
            double sumCn4 = 0;
            for ( int fn = 0; fn < s3; fn++ ) {
                sumCp2 += (dCpPos2[fn][i][c] - dCpPos2[s3][i][c]) * (dCpPos2[fn][i][c] - dCpPos2[s3][i][c]);
                sumCn2 += (dCpNeg2[fn][i][c] - dCpNeg2[s3][i][c]) * (dCpNeg2[fn][i][c] - dCpNeg2[s3][i][c]);
                sumCp4 += (dCpPos4[fn][i][c] - dCpPos4[s3][i][c]) * (dCpPos4[fn][i][c] - dCpPos4[s3][i][c]);
                sumCn4 += (dCpNeg4[fn][i][c] - dCpNeg4[s3][i][c]) * (dCpNeg4[fn][i][c] - dCpNeg4[s3][i][c]);
            }
            double errCp2 = sqrt( sumCp2 ) / s3;
            double errCn2 = sqrt( sumCn2 ) / s3;
            double errCp4 = sqrt( sumCp4 ) / s3;
            double errCn4 = sqrt( sumCn4 ) / s3;

            epCsub2pos[i][c] = errCp2;
            epCsub2neg[i][c] = errCn2;
            epCsub4pos[i][c] = errCp4;
            epCsub4neg[i][c] = errCn4;
        }
    }

    double eVsub2pos[20];
    double eVsub4pos[20];
    double eVsub2neg[20];
    double eVsub4neg[20];

    double epVsub2pos[24][20];
    double epVsub4pos[24][20];
    double epVsub2neg[24][20];
    double epVsub4neg[24][20];

    for ( int c = 0; c < 20; c++ ) {
        double e = dVsub2pos[s3][c] * eCsub2pos[c] / 2. / dCPos2[s3][c];
        if ( e == e ) eVsub2pos[c] = e; else eVsub2pos[c] = 99999.;

        e = dVsub2neg[s3][c] * eCsub2neg[c] / 2. / dCNeg2[s3][c];
        if ( e == e ) eVsub2neg[c] = e; else eVsub2neg[c] = 99999.;

        e = dVsub4pos[s3][c] * eCsub4pos[c] / 4. / dCPos4[s3][c];
        if ( e == e ) eVsub4pos[c] = e; else eVsub4pos[c] = 99999.;

        e = dVsub4neg[s3][c] * eCsub4neg[c] / 4. / dCNeg4[s3][c];
        if ( e == e ) eVsub4neg[c] = e; else eVsub4neg[c] = 99999.;
    }

    for ( int c = 0; c < 20; c++ ) {
        for ( int i = 0; i < 24; i++ ) {
            double e = sqrt( epCsub2pos[i][c]*epCsub2pos[i][c]/dCpPos2[s3][i][c]/dCpPos2[s3][i][c] + eVsub2neg[c]*eVsub2neg[c]/dVsub2neg[s3][c]/dVsub2neg[s3][c] ) * fabs(dpVsub2pos[s3][i][c]);
            if ( e == e ) epVsub2pos[i][c] = e; else epVsub2pos[i][c] = 9999.;
            e = sqrt( epCsub2neg[i][c]*epCsub2neg[i][c]/dCpNeg2[s3][i][c]/dCpNeg2[s3][i][c] + eVsub2pos[c]*eVsub2pos[c]/dVsub2pos[s3][c]/dVsub2pos[s3][c] ) * fabs(dpVsub2neg[s3][i][c]);
            if ( e == e ) epVsub2neg[i][c] = e; else epVsub2neg[i][c] = 9999.;

            e = sqrt( epCsub4pos[i][c]*epCsub4pos[i][c]/dCpPos4[s3][i][c]/dCpPos4[s3][i][c] + 9./16.*eCsub4neg[c]*eCsub4neg[c]/dCNeg4[s3][c]/dCNeg4[s3][c] ) * fabs(dpVsub4pos[s3][i][c]);
            if ( e == e ) epVsub4pos[i][c] = e; else epVsub4pos[i][c] = 9999.;
            e = sqrt( epCsub4neg[i][c]*epCsub4neg[i][c]/dCpNeg4[s3][i][c]/dCpNeg4[s3][i][c] + 9./16.*eCsub4pos[c]*eCsub4pos[c]/dCPos4[s3][c]/dCPos4[s3][c] ) * fabs(dpVsub4pos[s3][i][c]);
            if ( e == e ) epVsub4neg[i][c] = e; else epVsub4neg[i][c] = 9999.;
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

    TH1D * hCsub2pos = new TH1D("hCsub2pos", "", 20, 0, 20);;
    TH1D * hCsub2neg = new TH1D("hCsub2neg", "", 20, 0, 20);;
    TH1D * hCsub4pos = new TH1D("hCsub4pos", "", 20, 0, 20);;
    TH1D * hCsub4neg = new TH1D("hCsub4neg", "", 20, 0, 20);;

    TH1D * hVsub2pos = new TH1D("hVsub2pos", "", 20, 0, 20);;
    TH1D * hVsub2neg = new TH1D("hVsub2neg", "", 20, 0, 20);;
    TH1D * hVsub4pos = new TH1D("hVsub4pos", "", 20, 0, 20);;
    TH1D * hVsub4neg = new TH1D("hVsub4neg", "", 20, 0, 20);;

    for ( int c = 0; c < 20; c++ ) {
        hCsub2pos->SetBinContent( c+1, dCPos2[s3][c] );
        hCsub2neg->SetBinContent( c+1, dCNeg2[s3][c] );
        hCsub4pos->SetBinContent( c+1, dCPos4[s3][c] );
        hCsub4neg->SetBinContent( c+1, dCNeg4[s3][c] );

        hVsub2pos->SetBinContent( c+1, dVsub2pos[s3][c] );
        hVsub2neg->SetBinContent( c+1, dVsub2neg[s3][c] );
        hVsub4pos->SetBinContent( c+1, dVsub4pos[s3][c] );
        hVsub4neg->SetBinContent( c+1, dVsub4neg[s3][c] );

        hCsub2pos->SetBinError( c+1, eCsub2pos[c] );
        hCsub2neg->SetBinError( c+1, eCsub2neg[c] );
        hCsub4pos->SetBinError( c+1, eCsub4pos[c] );
        hCsub4neg->SetBinError( c+1, eCsub4neg[c] );

        hVsub2pos->SetBinError( c+1, eVsub2pos[c] );
        hVsub2neg->SetBinError( c+1, eVsub2neg[c] );
        hVsub4pos->SetBinError( c+1, eVsub4pos[c] );
        hVsub4neg->SetBinError( c+1, eVsub4neg[c] );
    }

    TH1D * hpCsub2pos[24];
    TH1D * hpCsub2neg[24];
    TH1D * hpCsub4pos[24];
    TH1D * hpCsub4neg[24];

    TH1D * hpVsub2pos[24];
    TH1D * hpVsub2neg[24];
    TH1D * hpVsub4pos[24];
    TH1D * hpVsub4neg[24];

    for ( int i = 0; i < 24; i++ ) {
        hpCsub2pos[i] = new TH1D(Form("hpCsub2pos%i", i), "", 20, 0, 20);
        hpCsub2neg[i] = new TH1D(Form("hpCsub2neg%i", i), "", 20, 0, 20);
        hpCsub4pos[i] = new TH1D(Form("hpCsub4pos%i", i), "", 20, 0, 20);
        hpCsub4neg[i] = new TH1D(Form("hpCsub4neg%i", i), "", 20, 0, 20);

        hpVsub2pos[i] = new TH1D(Form("hpVsub2pos%i", i), "", 20, 0, 20);
        hpVsub2neg[i] = new TH1D(Form("hpVsub2neg%i", i), "", 20, 0, 20);
        hpVsub4pos[i] = new TH1D(Form("hpVsub4pos%i", i), "", 20, 0, 20);
        hpVsub4neg[i] = new TH1D(Form("hpVsub4neg%i", i), "", 20, 0, 20);

        for ( int c = 0; c < 20; c++ ) {
            hpCsub2pos[i]->SetBinContent( c+1, dCpPos2[s3][i][c] );
            hpCsub2neg[i]->SetBinContent( c+1, dCpNeg2[s3][i][c] );
            hpCsub4pos[i]->SetBinContent( c+1, dCpPos4[s3][i][c] );
            hpCsub4neg[i]->SetBinContent( c+1, dCpNeg4[s3][i][c] );

            hpCsub2pos[i]->SetBinError( c+1, epCsub2pos[i][c] );
            hpCsub2neg[i]->SetBinError( c+1, epCsub2neg[i][c] );
            hpCsub4pos[i]->SetBinError( c+1, epCsub4pos[i][c] );
            hpCsub4neg[i]->SetBinError( c+1, epCsub4neg[i][c] );

            hpVsub2pos[i]->SetBinContent( c+1, dpVsub2pos[s3][i][c] );
            hpVsub2neg[i]->SetBinContent( c+1, dpVsub2neg[s3][i][c] );
            hpVsub4pos[i]->SetBinContent( c+1, dpVsub4pos[s3][i][c] );
            hpVsub4neg[i]->SetBinContent( c+1, dpVsub4neg[s3][i][c] );

            hpVsub2pos[i]->SetBinError( c+1, epVsub2pos[i][c] );
            hpVsub2neg[i]->SetBinError( c+1, epVsub2neg[i][c] );
            hpVsub4pos[i]->SetBinError( c+1, epVsub4pos[i][c] );
            hpVsub4neg[i]->SetBinError( c+1, epVsub4neg[i][c] );
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

    hCsub2pos->Write();
    hCsub2neg->Write();
    hCsub4pos->Write();
    hCsub4neg->Write();

    hVsub2pos->Write();
    hVsub2neg->Write();
    hVsub4pos->Write();
    hVsub4neg->Write();

    for ( int i = 0; i < 24; i++ ) {
        hpCsub2pos[i]->Write();
        hpCsub2neg[i]->Write();
        hpCsub4pos[i]->Write();
        hpCsub4neg[i]->Write();

        hpVsub2pos[i]->Write();
        hpVsub2neg[i]->Write();
        hpVsub4pos[i]->Write();
        hpVsub4neg[i]->Write();
    }
}

