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

	TH1D * hQGap[7] = {};
	TH1D * hQwGap[7] = {};
	TH1D * hV0QGap[7][24] = {};
	TH1D * hV0QwGap[7][24] = {};

	TH1D * hQpGap[7][24] = {};
	TH1D * hQpwGap[7][24] = {};

	for ( int n = 2; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			hQ[n][np] = (TH1D*) f->Get(Form("hQ%i%i", n, np));
			hQw[n][np] = (TH1D*) f->Get(Form("hQw%i%i", n, np));
			for ( int i = 0; i < 24; i++ ) {
				hQp[n][np][i] = (TH1D*) f->Get(Form("hQp%i%i_%i", n, np, i));
				hQwp[n][np][i] = (TH1D*) f->Get(Form("hQwp%i%i_%i", n, np, i));
			}
		}
		hQGap[n] = (TH1D*) f->Get(Form("hQGap%i", n));
		hQwGap[n] = (TH1D*) f->Get(Form("hQwGap%i", n));
		for ( int i = 0; i < 24; i++ ) {
			hV0QGap[n][i] = (TH1D*) f->Get(Form("hV0QGap%i_%i", n, i));
			hV0QwGap[n][i] = (TH1D*) f->Get(Form("hV0QwGap%i_%i", n, i));

			hQpGap[n][i] = (TH1D*) f->Get(Form("hQpGap%i_%i", n, i));
			hQpwGap[n][i] = (TH1D*) f->Get(Form("hQpwGap%i_%i", n, i));
		}
	}

    TH1D * hQpos2 = (TH1D*) f->Get("hQpos2");
    TH1D * hQneg2 = (TH1D*) f->Get("hQneg2");
    TH1D * hwQpos2 = (TH1D*) f->Get("hwQpos2");
    TH1D * hwQneg2 = (TH1D*) f->Get("hwQneg2");
    TH1D * hQpos4 = (TH1D*) f->Get("hQpos4");
    TH1D * hQneg4 = (TH1D*) f->Get("hQneg4");
    TH1D * hwQpos4 = (TH1D*) f->Get("hwQpos4");
    TH1D * hwQneg4 = (TH1D*) f->Get("hwQneg4");

    TH1D * hVpQpos2[24] = {};
    TH1D * hVpQneg2[24] = {};
    TH1D * hwVpQpos2[24] = {};
    TH1D * hwVpQneg2[24] = {};
    TH1D * hVpQpos4[24] = {};
    TH1D * hVpQneg4[24] = {};
    TH1D * hwVpQpos4[24] = {};
    TH1D * hwVpQneg4[24] = {};

    for ( int i = 0; i < 24; i++ ) {
        hVpQpos2[i] = (TH1D*) f->Get(Form("hVpQpos2%i", i));
        hVpQneg2[i] = (TH1D*) f->Get(Form("hVpQneg2%i", i));
        hVpQpos4[i] = (TH1D*) f->Get(Form("hVpQpos4%i", i));
        hVpQneg4[i] = (TH1D*) f->Get(Form("hVpQneg4%i", i));

        hwVpQpos2[i] = (TH1D*) f->Get(Form("hwVpQpos2%i", i));
        hwVpQneg2[i] = (TH1D*) f->Get(Form("hwVpQneg2%i", i));
        hwVpQpos4[i] = (TH1D*) f->Get(Form("hwVpQpos4%i", i));
        hwVpQneg4[i] = (TH1D*) f->Get(Form("hwVpQneg4%i", i));
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

	double dQGap[7][600] = {};
	double yQGap[7][600] = {};
	double dV0QGap[7][24][600] = {};
	double yV0QGap[7][24][600] = {};

	double dQpGap[7][24][600] = {};
	double yQpGap[7][24][600] = {};

	for ( int n = 2; n < 7; n++ ) {
		for ( int c = 0; c < 600; c++ ) {
			dQGap[n][c] = hQGap[n]->GetBinContent( c+1 );
			yQGap[n][c] = hQwGap[n]->GetBinContent( c+1 );
			if ( yQGap[n][c] > 0. ) dQGap[n][c] /= yQGap[n][c];
			for ( int i = 0; i < 24; i++ ) {
				dV0QGap[n][i][c] = hV0QGap[n][i]->GetBinContent( c+1 );
				yV0QGap[n][i][c] = hV0QwGap[n][i]->GetBinContent( c+1 );
				if ( yV0QGap[n][i][c] > 0. ) dV0QGap[n][i][c] /= yV0QGap[n][i][c];

				dQpGap[n][i][c] = hQpGap[n][i]->GetBinContent( c+1 );
				yQpGap[n][i][c] = hQpwGap[n][i]->GetBinContent( c+1 );
				if ( yQpGap[n][i][c] > 0. ) dQpGap[n][i][c] /= yQpGap[n][i][c];
			}
		}
	}

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

    for ( int c = 0; c < 600; c++ ) {
        dQpos2[c] = hQpos2->GetBinContent(c+1);
        dQneg2[c] = hQneg2->GetBinContent(c+1);
        yQpos2[c] = hwQpos2->GetBinContent(c+1);
        yQneg2[c] = hwQneg2->GetBinContent(c+1);

        dQpos4[c] = hQpos4->GetBinContent(c+1);
        dQneg4[c] = hQneg4->GetBinContent(c+1);
        yQpos4[c] = hwQpos4->GetBinContent(c+1);
        yQneg4[c] = hwQneg4->GetBinContent(c+1);

        if ( yQpos2[c] > 0 ) dQpos2[c] /= yQpos2[c];
        if ( yQneg2[c] > 0 ) dQneg2[c] /= yQneg2[c];
        if ( yQpos4[c] > 0 ) dQpos4[c] /= yQpos4[c];
        if ( yQneg4[c] > 0 ) dQneg4[c] /= yQneg4[c];

        for ( int i = 0; i < 24; i++ ) {
            dVpQpos2[i][c] = hVpQpos2[i]->GetBinContent(c+1);
            dVpQneg2[i][c] = hVpQneg2[i]->GetBinContent(c+1);
            yVpQpos2[i][c] = hwVpQpos2[i]->GetBinContent(c+1);
            yVpQneg2[i][c] = hwVpQneg2[i]->GetBinContent(c+1);

            dVpQpos4[i][c] = hVpQpos4[i]->GetBinContent(c+1);
            dVpQneg4[i][c] = hVpQneg4[i]->GetBinContent(c+1);
            yVpQpos4[i][c] = hwVpQpos4[i]->GetBinContent(c+1);
            yVpQneg4[i][c] = hwVpQneg4[i]->GetBinContent(c+1);

            if ( yVpQpos2[i][c] > 0. ) dVpQpos2[i][c] /= yVpQpos2[i][c];
            if ( yVpQneg2[i][c] > 0. ) dVpQneg2[i][c] /= yVpQneg2[i][c];
            if ( yVpQpos4[i][c] > 0. ) dVpQpos4[i][c] /= yVpQpos4[i][c];
            if ( yVpQneg4[i][c] > 0. ) dVpQneg4[i][c] /= yVpQneg4[i][c];
        }
    }

	double dCraw[7][4][600];
	double dCpraw[7][4][24][600];

	double dCGapRaw[7][600];
	double dCpGapRaw[7][24][600];
	double dpCpGapRaw[7][24][600];

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

			dCGapRaw[n][c] = dQGap[n][c];
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

				dCpGapRaw[n][i][c] = dV0QGap[n][i][c];
				dpCpGapRaw[n][i][c] = dQpGap[n][i][c];
			}
		}
	}

    // subevent
    double dCrawPos2[600];
    double dCrawNeg2[600];
    double dCrawPos4[600];
    double dCrawNeg4[600];
    double dCpRawPos2[24][600] = {};
    double dCpRawNeg2[24][600] = {};
    double dCpRawPos4[24][600] = {};
    double dCpRawNeg4[24][600] = {};

    for ( int c = 0; c < 600; c++ ) {
        double Q2pos = dQpos2[c];
        double Q2neg = dQneg2[c];
        double Q4pos = dQpos4[c];
        double Q4neg = dQneg4[c];

        dCrawPos2[c] = Q2pos;
        dCrawNeg2[c] = Q2neg;
        dCrawPos4[c] = Q4pos - 2*Q2pos*Q2pos;
        dCrawNeg4[c] = Q4neg - 2*Q2neg*Q2neg;
    }
    for ( int i = 0; i < 24; i++ ) {
        for ( int c = 0; c < 600; c++ ) {
            double Q2pos = dQpos2[c];
            double Q2neg = dQneg2[c];
            double Qp2pos = dVpQpos2[i][c];
            double Qp4pos = dVpQpos4[i][c];
            double Qp2neg = dVpQneg2[i][c];
            double Qp4neg = dVpQneg4[i][c];

            dCpRawPos2[i][c] = Qp2pos;
            dCpRawPos4[i][c] = Qp4pos - 2*Qp2pos*Q2neg;

            dCpRawNeg2[i][c] = Qp2neg;
            dCpRawNeg4[i][c] = Qp4neg - 2*Qp2neg*Q2pos;
        }
    }

	// rebin

	double dC[7][4][20];
	double wC[7][4][20];
	double dCp[7][4][24][20];
	double wCp[7][4][24][20];
	double dCGap[7][20];
	double wCGap[7][20];
	double dCpGap[7][24][20];
	double wCpGap[7][24][20];

	double dpCpGap[7][24][20];
	double wpCpGap[7][24][20];

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
					if ( weight > 0. ) sum /= weight;
					dCp[n][np][i][c] = sum;
					wCp[n][np][i][c] = weight;
				}
			}
		}
		for ( int c = 0; c < NCent; c++ ) {
			double sum = 0;
			double weight = 0;
			for ( int m = pCent[c]; m < pCent[c+1]; m++ ) {
				sum += dCGapRaw[n][m] * yQGap[n][m];
				weight += yQGap[n][m];
			}
			if ( weight > 0. ) sum /= weight;
			dCGap[n][c] = sum;
			wCGap[n][c] = weight;

			for ( int i = 0; i < 24; i++ ) {
				double sum = 0;
				double weight = 0;

				double sump = 0;
				double weightp = 0;
				for ( int m = pCent[c]; m < pCent[c+1]; m++ ) {
					sum += dCpGapRaw[n][i][m] * yV0QGap[n][i][m];
					weight += yV0QGap[n][i][m];

					sump += dpCpGapRaw[n][i][m] * yQpGap[n][i][m];
					weightp += yQpGap[n][i][m];
				}
				if ( weight > 0. ) sum /= weight;
				dCpGap[n][i][c] = sum;
				wCpGap[n][i][c] = weight;

				if ( weightp > 0. ) sump /= weightp;
				dpCpGap[n][i][c] = sump;
				wpCpGap[n][i][c] = weightp;
			}
		}
	}

    // rebin subevent
    double dCPos2[20] = {};
    double dCNeg2[20] = {};
    double dCPos4[20] = {};
    double dCNeg4[20] = {};

    double wCPos2[20] = {};
    double wCNeg2[20] = {};
    double wCPos4[20] = {};
    double wCNeg4[20] = {};

    double dCpPos2[24][20] = {};
    double dCpNeg2[24][20] = {};
    double dCpPos4[24][20] = {};
    double dCpNeg4[24][20] = {};

    double wCpPos2[24][20] = {};
    double wCpNeg2[24][20] = {};
    double wCpPos4[24][20] = {};
    double wCpNeg4[24][20] = {};

    for ( int c = 0; c < NCent; c++ ) {
        double sum2_p = 0;
        double sum2_n = 0;
        double sum4_p = 0;
        double sum4_n = 0;
        double weight2_p = 0;
        double weight2_n = 0;
        double weight4_p = 0;
        double weight4_n = 0;
        for ( int m = pCent[c]; m < pCent[c+1]; m++ ) {
            sum2_p += dCrawPos2[m] * yQpos2[m];
            sum2_n += dCrawNeg2[m] * yQneg2[m];
            sum4_p += dCrawPos4[m] * yQpos4[m];
            sum4_n += dCrawNeg4[m] * yQneg4[m];

            weight2_p += yQpos2[m];
            weight2_n += yQneg2[m];
            weight4_p += yQpos4[m];
            weight4_n += yQneg4[m];
        }
        if ( weight2_p > 0. ) sum2_p /= weight2_p;
        if ( weight2_n > 0. ) sum2_n /= weight2_n;
        if ( weight4_p > 0. ) sum4_p /= weight4_p;
        if ( weight4_n > 0. ) sum4_n /= weight4_n;

        dCPos2[c] = sum2_p;
        dCNeg2[c] = sum2_n;
        dCPos4[c] = sum4_p;
        dCNeg4[c] = sum4_n;

        wCPos2[c] = weight2_p;
        wCNeg2[c] = weight2_n;
        wCPos4[c] = weight4_p;
        wCNeg4[c] = weight4_n;

        for ( int i = 0; i < 24; i++ ) {
            double sum2_p = 0;
            double sum2_n = 0;
            double sum4_p = 0;
            double sum4_n = 0;
            double weight2_p = 0;
            double weight2_n = 0;
            double weight4_p = 0;
            double weight4_n = 0;

            for ( int cc = 0; cc < 600; cc++ ) {
                sum2_p += dCpRawPos2[i][cc] * yVpQpos2[i][cc];
                sum2_n += dCpRawNeg2[i][cc] * yVpQneg2[i][cc];
                sum4_p += dCpRawPos4[i][cc] * yVpQpos4[i][cc];
                sum4_n += dCpRawNeg4[i][cc] * yVpQneg4[i][cc];

                weight2_p += yVpQpos2[i][cc];
                weight2_n += yVpQneg2[i][cc];
                weight4_p += yVpQpos4[i][cc];
                weight4_n += yVpQneg4[i][cc];
            }

            if ( weight2_p > 0. ) sum2_p /= weight2_p;
            if ( weight2_n > 0. ) sum2_n /= weight2_n;
            if ( weight4_p > 0. ) sum4_p /= weight4_p;
            if ( weight4_n > 0. ) sum4_n /= weight4_n;

            dCpPos2[i][c] = sum2_p;
            dCpNeg2[i][c] = sum2_n;
            dCpPos4[i][c] = sum4_p;
            dCpNeg4[i][c] = sum4_n;

            wCpPos2[i][c] = weight2_p;
            wCpNeg2[i][c] = weight2_n;
            wCpPos4[i][c] = weight4_p;
            wCpNeg4[i][c] = weight4_n;
        }
    }

    // save
	TH1D * hCraw[7][4] = {};
	TH1D * hCwraw[7][4] = {};
	TH1D * hCpraw[7][4][24] = {};
	TH1D * hCwpraw[7][4][24] = {};

	TH1D * hC[7][4] = {};
	TH1D * hCw[7][4] = {};
	TH1D * hCp[7][4][24] = {};
	TH1D * hCwp[7][4][24] = {};

	TH1D * hCGapraw[7] = {};
	TH1D * hCGapwraw[7] = {};
	TH1D * hCGappraw[7][24] = {};
	TH1D * hCGapwpraw[7][24] = {};

	TH1D * hCGap[7] = {};
	TH1D * hCGapw[7] = {};
	TH1D * hCGapp[7][24] = {};
	TH1D * hCGapwp[7][24] = {};

	TH1D * hpCGapp[7][24] = {};
	TH1D * hpCGapwp[7][24] = {};

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

		hCGapraw[n] = new TH1D(Form("hCGapraw%i", n), "", 600, 0, 600);
		hCGapwraw[n] = new TH1D(Form("hCGapwraw%i", n), "", 600, 0, 600);
		hCGap[n] = new TH1D(Form("hCGap%i", n), "", 20, 0, 20);
		hCGapw[n] = new TH1D(Form("hCGapw%i", n), "", 20, 0, 20);
		for ( int i = 0; i < 24; i++ ) {
			hCGappraw[n][i] = new TH1D(Form("hCGappraw%i_%i", n, i), "", 600, 0, 600);
			hCGapwpraw[n][i] = new TH1D(Form("hCGapwpraw%i_%i", n, i), "", 600, 0, 600);

			hCGapp[n][i] = new TH1D(Form("hCGapp%i_%i", n, i), "", 20, 0, 20);
			hCGapwp[n][i] = new TH1D(Form("hCGapwp%i_%i", n, i), "", 20, 0, 20);

			hpCGapp[n][i] = new TH1D(Form("hpCGapp%i_%i", n, i), "", 20, 0, 20);
			hpCGapwp[n][i] = new TH1D(Form("hpCGapwp%i_%i", n, i), "", 20, 0, 20);
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
				}
			}
		}
		for ( int c = 0; c < 600; c++ ) {
			hCGapraw[n]->SetBinContent( c+1, dCGapRaw[n][c] );
			hCGapwraw[n]->SetBinContent( c+1, yQGap[n][c] );
			for ( int i = 0; i < 24; i++ ) {
				hCGappraw[n][i]->SetBinContent( c+1, dCpGapRaw[n][i][c] );
				hCGapwpraw[n][i]->SetBinContent( c+1, yV0QGap[n][i][c] );
			}
		}
		for ( int c = 0; c < 20; c++ ) {
			hCGap[n]->SetBinContent( c+1, dCGap[n][c] );
			hCGapw[n]->SetBinContent( c+1, wCGap[n][c] );
			for ( int i = 0; i < 24; i++ ) {
				hCGapp[n][i]->SetBinContent( c+1, dCpGap[n][i][c] );
				hCGapwp[n][i]->SetBinContent( c+1, wCpGap[n][i][c] );

				hpCGapp[n][i]->SetBinContent( c+1, dpCpGap[n][i][c] );
				hpCGapwp[n][i]->SetBinContent( c+1, wpCpGap[n][i][c] );
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

    //////////
    TH1D * hCrawPos2 = new TH1D("hCrawPos2", "", 600, 0, 600);
    TH1D * hCrawNeg2 = new TH1D("hCrawNeg2", "", 600, 0, 600);
    TH1D * hCrawPos4 = new TH1D("hCrawPos4", "", 600, 0, 600);
    TH1D * hCrawNeg4 = new TH1D("hCrawNeg4", "", 600, 0, 600);
    TH1D * hwCrawPos2 = new TH1D("hwCrawPos2", "", 600, 0, 600);
    TH1D * hwCrawNeg2 = new TH1D("hwCrawNeg2", "", 600, 0, 600);
    TH1D * hwCrawPos4 = new TH1D("hwCrawPos4", "", 600, 0, 600);
    TH1D * hwCrawNeg4 = new TH1D("hwCrawNeg4", "", 600, 0, 600);

    for ( int c = 0; c < 600; c++ ) {
        hCrawPos2->SetBinContent( c+1, dCrawPos2[c] );
        hCrawNeg2->SetBinContent( c+1, dCrawNeg2[c] );
        hCrawPos4->SetBinContent( c+1, dCrawPos4[c] );
        hCrawNeg4->SetBinContent( c+1, dCrawNeg4[c] );

        hwCrawPos2->SetBinContent( c+1, yQpos2[c] );
        hwCrawNeg2->SetBinContent( c+1, yQneg2[c] );
        hwCrawPos4->SetBinContent( c+1, yQpos4[c] );
        hwCrawNeg4->SetBinContent( c+1, yQneg4[c] );
    }

    TH1D * hCpRawPos2[24];
    TH1D * hCpRawNeg2[24];
    TH1D * hCpRawPos4[24];
    TH1D * hCpRawNeg4[24];
    TH1D * hwCpRawPos2[24];
    TH1D * hwCpRawNeg2[24];
    TH1D * hwCpRawPos4[24];
    TH1D * hwCpRawNeg4[24];

    for ( int i = 0; i < 24; i++ ) {
        hCpRawPos2[i] = new TH1D(Form("hCpRawPos2%i", i), "", 600, 0, 600);
        hCpRawNeg2[i] = new TH1D(Form("hCpRawNeg2%i", i), "", 600, 0, 600);
        hCpRawPos4[i] = new TH1D(Form("hCpRawPos4%i", i), "", 600, 0, 600);
        hCpRawNeg4[i] = new TH1D(Form("hCpRawNeg4%i", i), "", 600, 0, 600);

        hwCpRawPos2[i] = new TH1D(Form("hwCpRawPos2%i", i), "", 600, 0, 600);
        hwCpRawNeg2[i] = new TH1D(Form("hwCpRawNeg2%i", i), "", 600, 0, 600);
        hwCpRawPos4[i] = new TH1D(Form("hwCpRawPos4%i", i), "", 600, 0, 600);
        hwCpRawNeg4[i] = new TH1D(Form("hwCpRawNeg4%i", i), "", 600, 0, 600);

        for ( int c = 0; c < 600; c++ ) {
            hCpRawPos2[i]->SetBinContent( c+1, dCpRawPos2[i][c] );
            hCpRawNeg2[i]->SetBinContent( c+1, dCpRawNeg2[i][c] );
            hCpRawPos4[i]->SetBinContent( c+1, dCpRawPos4[i][c] );
            hCpRawNeg4[i]->SetBinContent( c+1, dCpRawNeg4[i][c] );

            hwCpRawPos2[i]->SetBinContent( c+1, yVpQpos2[i][c] );
            hwCpRawNeg2[i]->SetBinContent( c+1, yVpQneg2[i][c] );
            hwCpRawPos4[i]->SetBinContent( c+1, yVpQpos4[i][c] );
            hwCpRawNeg4[i]->SetBinContent( c+1, yVpQneg4[i][c] );
        }
    }



    // save rebin
    TH1D * hCPos2 = new TH1D("hCPos2", "", 20, 0, 20);
    TH1D * hCNeg2 = new TH1D("hCNeg2", "", 20, 0, 20);
    TH1D * hCPos4 = new TH1D("hCPos4", "", 20, 0, 20);
    TH1D * hCNeg4 = new TH1D("hCNeg4", "", 20, 0, 20);
    TH1D * hwCPos2 = new TH1D("hwCPos2", "", 20, 0, 20);
    TH1D * hwCNeg2 = new TH1D("hwCNeg2", "", 20, 0, 20);
    TH1D * hwCPos4 = new TH1D("hwCPos4", "", 20, 0, 20);
    TH1D * hwCNeg4 = new TH1D("hwCNeg4", "", 20, 0, 20);

    for ( int c = 0; c < 20; c++ ) {
        hCPos2->SetBinContent( c+1, dCPos2[c] );
        hCNeg2->SetBinContent( c+1, dCNeg2[c] );
        hCPos4->SetBinContent( c+1, dCPos4[c] );
        hCNeg4->SetBinContent( c+1, dCNeg4[c] );

        hwCPos2->SetBinContent( c+1, wCPos2[c] );
        hwCNeg2->SetBinContent( c+1, wCNeg2[c] );
        hwCPos4->SetBinContent( c+1, wCPos4[c] );
        hwCNeg4->SetBinContent( c+1, wCNeg4[c] );
    }


    TH1D * hCpPos2[24];
    TH1D * hCpNeg2[24];
    TH1D * hCpPos4[24];
    TH1D * hCpNeg4[24];

    TH1D * hwCpPos2[24];
    TH1D * hwCpNeg2[24];
    TH1D * hwCpPos4[24];
    TH1D * hwCpNeg4[24];

    for ( int i = 0; i < 24; i++ ) {
        hCpPos2[i] = new TH1D(Form("hCpPos2%i", i), "", 20, 0, 20);
        hCpNeg2[i] = new TH1D(Form("hCpNeg2%i", i), "", 20, 0, 20);
        hCpPos4[i] = new TH1D(Form("hCpPos4%i", i), "", 20, 0, 20);
        hCpNeg4[i] = new TH1D(Form("hCpNeg4%i", i), "", 20, 0, 20);

        hwCpPos2[i] = new TH1D(Form("hwCpPos2%i", i), "", 20, 0, 20);
        hwCpNeg2[i] = new TH1D(Form("hwCpNeg2%i", i), "", 20, 0, 20);
        hwCpPos4[i] = new TH1D(Form("hwCpPos4%i", i), "", 20, 0, 20);
        hwCpNeg4[i] = new TH1D(Form("hwCpNeg4%i", i), "", 20, 0, 20);

        for ( int c = 0; c < 20; c++ ) {
            hCpPos2[i]->SetBinContent( c+1, dCpPos2[i][c] );
            hCpNeg2[i]->SetBinContent( c+1, dCpNeg2[i][c] );
            hCpPos4[i]->SetBinContent( c+1, dCpPos4[i][c] );
            hCpNeg4[i]->SetBinContent( c+1, dCpNeg4[i][c] );

            hwCpPos2[i]->SetBinContent( c+1, wCpPos2[i][c] );
            hwCpNeg2[i]->SetBinContent( c+1, wCpNeg2[i][c] );
            hwCpPos4[i]->SetBinContent( c+1, wCpPos4[i][c] );
            hwCpNeg4[i]->SetBinContent( c+1, wCpNeg4[i][c] );
        }
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

		hCGapraw[n]->Write();
		hCGapwraw[n]->Write();
		hCGap[n]->Write();
		hCGapw[n]->Write();
		for ( int i = 0; i < 24; i++ ) {
			hCGappraw[n][i]->Write();
			hCGapwpraw[n][i]->Write();
			hCGapp[n][i]->Write();
			hCGapwp[n][i]->Write();
			hpCGapp[n][i]->Write();
			hpCGapwp[n][i]->Write();
		}
	}

    // subevent
    hCrawPos2->Write();
    hCrawNeg2->Write();
    hCrawPos4->Write();
    hCrawNeg4->Write();
    hwCrawPos2->Write();
    hwCrawNeg2->Write();
    hwCrawPos4->Write();
    hwCrawNeg4->Write();

    for ( int i = 0; i < 24; i++ ) {
        hCpRawPos2[i]->Write();
        hCpRawNeg2[i]->Write();
        hCpRawPos4[i]->Write();
        hCpRawNeg4[i]->Write();

        hwCpRawPos2[i]->Write();
        hwCpRawNeg2[i]->Write();
        hwCpRawPos4[i]->Write();
        hwCpRawNeg4[i]->Write();
    }

    hCPos2->Write();
    hCNeg2->Write();
    hCPos4->Write();
    hCNeg4->Write();
    hwCPos2->Write();
    hwCNeg2->Write();
    hwCPos4->Write();
    hwCNeg4->Write();

    for ( int i = 0; i < 24; i++ ) {
        hCpPos2[i]->Write();
        hCpNeg2[i]->Write();
        hCpPos4[i]->Write();
        hCpNeg4[i]->Write();

        hwCpPos2[i]->Write();
        hwCpNeg2[i]->Write();
        hwCpPos4[i]->Write();
        hwCpNeg4[i]->Write();
    }

	hNoff->Write();
	hMult->Write();
	hV0M->Write();
	hNoffR->Write();
}
