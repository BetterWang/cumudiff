#include "Steve_SP.h"

TColor *red = new TColor(3001, 1, 0, 0, "red", 0.4);
TColor *green = new TColor(3002, 0, 0.5, 0, "green", 0.4);
TColor *blue = new TColor(3003, 0, 0, 1, "blue", 0.4);
TColor *gray = new TColor(3005, 0, 0, 0, "black", 0.4);

// systematics
// 0 -- H   1.4
// 1 -- Ks  3.5
// 2 -- Lm  5.7
const double cumu_syst[3] = {0.014, 0.042, 0.055};
const double PbPb_sysX = 0.35;

struct QWCumu {
    TGraphErrors * grSig_pT[7][4][20] = {};
    TGraphErrors * grSig_pTGap[7][20] = {};

    TGraphErrors * grSig_V2sub2pos[20] = {};
    TGraphErrors * grSig_V2sub2neg[20] = {};
    TGraphErrors * grSig_V2sub2merge[20] = {};

    TGraphErrors * grSig_V2sub4pos[20] = {};
    TGraphErrors * grSig_V2sub4neg[20] = {};
    TGraphErrors * grSig_V2sub4merge[20] = {};

    // sys
    TGraphErrors * grSysSig_pT[7][4][20] = {};
    TGraphErrors * grSysSig_pTGap[7][20] = {};

    TGraphErrors * grSysSig_V2sub2pos[20] = {};
    TGraphErrors * grSysSig_V2sub2neg[20] = {};
    TGraphErrors * grSysSig_V2sub2merge[20] = {};

    TGraphErrors * grSysSig_V2sub4pos[20] = {};
    TGraphErrors * grSysSig_V2sub4neg[20] = {};
    TGraphErrors * grSysSig_V2sub4merge[20] = {};


    QWCumu(TFile *f, int pid, bool bTrim = false) {
        for ( int n = 2; n < 7; n++ ) {
            for ( int c = 0; c < 5; c++ ) {
                grSig_pTGap[n][c] = (TGraphErrors*) f->Get(Form("grSig_pTGap%i_%i", n, c));
                grSysSig_pTGap[n][c] = getSys( grSig_pTGap[n][c], cumu_syst[pid] );
                for ( int np = 0; np < 4; np++ ) {
                    grSig_pT[n][np][c] = (TGraphErrors*) f->Get( Form("grSig_pT%i_%i_%i", n, np, c) );
                    grSysSig_pT[n][np][c] = getSys( grSig_pT[n][np][c], cumu_syst[pid] );
                }
            }
        }

        for ( int c = 0; c < 5; c++ ) {
            grSig_V2sub2pos[c]      = (TGraphErrors*) f->Get( Form("grSig_V2sub2pos_%i", c) );
            grSig_V2sub2neg[c]      = (TGraphErrors*) f->Get( Form("grSig_V2sub2neg_%i", c) );
            grSig_V2sub2merge[c]    = (TGraphErrors*) f->Get( Form("grSig_V2sub2merge_%i", c) );

            grSig_V2sub4pos[c]      = (TGraphErrors*) f->Get( Form("grSig_V2sub4pos_%i", c) );
            grSig_V2sub4neg[c]      = (TGraphErrors*) f->Get( Form("grSig_V2sub4neg_%i", c) );
            grSig_V2sub4merge[c]    = (TGraphErrors*) f->Get( Form("grSig_V2sub4merge_%i", c) );

            grSysSig_V2sub2pos[c]      = getSys( grSig_V2sub2pos[c]   , cumu_syst[pid] );
            grSysSig_V2sub2neg[c]      = getSys( grSig_V2sub2neg[c]   , cumu_syst[pid] );
            grSysSig_V2sub2merge[c]    = getSys( grSig_V2sub2merge[c] , cumu_syst[pid] );

            grSysSig_V2sub4pos[c]      = getSys( grSig_V2sub4pos[c]   , cumu_syst[pid] );
            grSysSig_V2sub4neg[c]      = getSys( grSig_V2sub4neg[c]   , cumu_syst[pid] );
            grSysSig_V2sub4merge[c]    = getSys( grSig_V2sub4merge[c] , cumu_syst[pid] );
        }

        if ( bTrim ) {
            if ( pid == 0 ) dropPoints(2);
            else if ( pid == 1 ) dropPoints(4);
            else if ( pid == 2 ) dropPoints(6);
        }
    };

    TGraphErrors* getSys(TGraphErrors* gr, double sys)
    {
        int N = gr->GetN();
        TGraphErrors* g = new TGraphErrors(N);

        for ( int i = 0; i < N; i++ ) {
            g->GetX()[i] = gr->GetX()[i];
            g->GetY()[i] = gr->GetY()[i];
            g->GetEY()[i] = gr->GetY()[i] * sys;
            g->GetEX()[i] = PbPb_sysX;
        }
        return g;
    };

    void ReplaceX(SteveGraph** gr) {
        for ( int n = 2; n < 7; n++ ) {
            for ( int c = 0; c < 5; c++ ) {
                ReplaceX( grSig_pTGap[n][c],    gr[c]->vn_NegEta );
                ReplaceX( grSysSig_pTGap[n][c], gr[c]->vn_NegEta );
                for ( int np = 0; np < 4; np++ ) {
                    ReplaceX( grSig_pT[n][np][c],    gr[c]->vn_NegEta );
                    ReplaceX( grSysSig_pT[n][np][c], gr[c]->vn_NegEta );
                }
            }
        }
        for ( int c = 0; c < 5; c++ ) {
            ReplaceX( grSig_V2sub2pos[c],   gr[c]->vn_NegEta );
            ReplaceX( grSig_V2sub2neg[c],   gr[c]->vn_NegEta );
            ReplaceX( grSig_V2sub2merge[c], gr[c]->vn_NegEta );
            ReplaceX( grSig_V2sub4pos[c],   gr[c]->vn_NegEta );
            ReplaceX( grSig_V2sub4neg[c],   gr[c]->vn_NegEta );
            ReplaceX( grSig_V2sub4merge[c], gr[c]->vn_NegEta );

            ReplaceX( grSysSig_V2sub2pos[c],    gr[c]->vn_NegEta );
            ReplaceX( grSysSig_V2sub2neg[c],    gr[c]->vn_NegEta );
            ReplaceX( grSysSig_V2sub2merge[c],  gr[c]->vn_NegEta );
            ReplaceX( grSysSig_V2sub4pos[c],    gr[c]->vn_NegEta );
            ReplaceX( grSysSig_V2sub4neg[c],    gr[c]->vn_NegEta );
            ReplaceX( grSysSig_V2sub4merge[c],  gr[c]->vn_NegEta );
        }
    };

    void ReplaceX( TGraphErrors* gr1, TGraphErrors* gr2 ) {
        int N = gr1->GetN();
        if ( N != gr2->GetN() ) {
            cout << " --> inconsistent" << endl;
            return;
        }
        for ( int i = 0; i < N; i++ ) {
            gr1->GetX()[i] = gr2->GetX()[i];
        }
        return;
    };

    void dropPoints( int N ) {
        for ( int i = 0; i < N; i++ ) {
            for ( int n = 2; n < 7; n++ ) {
                for ( int c = 0; c < 5; c++ ) {
                    grSig_pTGap[n][c]   ->RemovePoint(0);
                    grSysSig_pTGap[n][c]->RemovePoint(0);
                    for ( int np = 0; np < 4; np++ ) {
                        grSig_pT[n][np][c]      ->RemovePoint(0);
                        grSysSig_pT[n][np][c]   ->RemovePoint(0);
                    }
                }
            }
            for ( int c = 0; c < 5; c++ ) {
                grSig_V2sub2pos[c]  ->RemovePoint(0);
                grSig_V2sub2neg[c]  ->RemovePoint(0);
                grSig_V2sub2merge[c]->RemovePoint(0);
                grSig_V2sub4pos[c]  ->RemovePoint(0);
                grSig_V2sub4neg[c]  ->RemovePoint(0);
                grSig_V2sub4merge[c]->RemovePoint(0);
                grSysSig_V2sub2pos[c]  ->RemovePoint(0);
                grSysSig_V2sub2neg[c]  ->RemovePoint(0);
                grSysSig_V2sub2merge[c]->RemovePoint(0);
                grSysSig_V2sub4pos[c]  ->RemovePoint(0);
                grSysSig_V2sub4neg[c]  ->RemovePoint(0);
                grSysSig_V2sub4merge[c]->RemovePoint(0);
            }
        }
    }
};

TGraphErrors* getFluct(TGraphErrors* gr1, TGraphErrors* gr2 ) {
    if ( gr1->GetN() != gr2->GetN() ) {
        cout << " --> getFluct mismatch!!" << endl;
        return nullptr;
    }
    TGraphErrors* ret = new TGraphErrors(gr2->GetN());
    for ( int i = 0; i < gr1->GetN(); i++ ) {
        double y1 = gr1->GetY()[i];
        double ey1 = gr1->GetEY()[i];
        double y2 = gr2->GetY()[i];
        double ey2 = gr2->GetEY()[i];

        ret->GetX()[i] = gr1->GetX()[i];
        ret->GetY()[i] = sqrt( (y1*y1 - y2*y2)/(y1*y1 + y2*y2) );

        double t = y1*y1 - y2*y2;
        double g = y1*y1 + y2*y2;
        double f1 = 2*y1;
        double f2 = -2*y2;
        double g1 = 2*y1;
        double g2 = 2*y2;

        double err1 = (f1/g - t*g1/g/g)*(f1/g - t*g1/g/g)*ey1*ey1;
        double err2 = (f2/g - t*g2/g/g)*(f2/g - t*g2/g/g)*ey2*ey2;
        double x = t/g;
        double ex = sqrt(err1 + err2);

        ret->GetEY()[i] = ex/sqrt(x)/2;
    }
    return ret;
}
TGraphErrors* getFluct(TGraphErrors* gr1, TGraphErrors* gr2, TGraphErrors*& grSys, double sys = cumu_syst[0]) {
    if ( gr1->GetN() != gr2->GetN() ) {
        cout << " --> getFluct mismatch!!" << endl;
        return nullptr;
    }
    TGraphErrors* ret = new TGraphErrors(gr2->GetN());
    grSys = new TGraphErrors(gr2->GetN());
    for ( int i = 0; i < gr1->GetN(); i++ ) {
        double y1 = gr1->GetY()[i];
        double ey1 = gr1->GetEY()[i];
        double y2 = gr2->GetY()[i];
        double ey2 = gr2->GetEY()[i];

        ret->GetX()[i] = gr1->GetX()[i];
        ret->GetY()[i] = sqrt( (y1*y1 - y2*y2)/(y1*y1 + y2*y2) );


        double t = y1*y1 - y2*y2;
        double g = y1*y1 + y2*y2;
        double f1 = 2*y1;
        double f2 = -2*y2;
        double g1 = 2*y1;
        double g2 = 2*y2;

        double err1 = (f1/g - t*g1/g/g)*(f1/g - t*g1/g/g)*ey1*ey1;
        double err2 = (f2/g - t*g2/g/g)*(f2/g - t*g2/g/g)*ey2*ey2;
        double x = t/g;
        double ex = sqrt(err1 + err2);

        ret->GetEY()[i] = ex/sqrt(x)/2;

        grSys->GetX()[i] = ret->GetX()[i];
        grSys->GetEX()[i] = PbPb_sysX;
        grSys->GetY()[i] = ret->GetY()[i];

        double serr1 = (f1/g - t*g1/g/g)*sys*y1;
        grSys->GetEY()[i] = serr1 / 2. / sqrt(x);
    }
    return ret;
}

TGraphErrors* getDelta(TGraphErrors* gr1, TGraphErrors* gr2, int option = 0)
    /*
     * 0 - errors are independent
     * 1 - use only gr1 error
     * 2 - use only gr2 error
     * 3 - errors are correlated
     * 10 - use only cumu_syst[0] error Ch
     * 11 - use only cumu_syst[1] error Ks
     * 12 - use only cumu_syst[2] error Lm
     */
{
    if ( gr1->GetN() != gr2->GetN() ) {
        cout << " --> Warning mismatch getDelta" << endl;
        return nullptr;
    }
    TGraphErrors * ret = new TGraphErrors(gr2->GetN());
    for ( int i = 0; i < gr2->GetN(); i++ ) {
        if ( gr1->GetX()[i] != gr2->GetX()[i] ) cout << "--> Warning mismatch X" << endl;
        ret->GetX()[i] = gr2->GetX()[i];
        ret->GetEX()[i] = gr2->GetEX()[i];
        ret->GetY()[i] = gr1->GetY()[i] - gr2->GetY()[i];
        double y1 = gr1->GetY()[i];
        double y2 = gr2->GetY()[i];
        double e1 = gr1->GetEY()[i];
        double e2 = gr2->GetEY()[i];
        if ( option == 1 ) {
            e2 = 0;
        } else if ( option == 2 ) {
            e1 = 0;
        }
        ret->GetEY()[i] = sqrt( e1*e1 + e2*e2 );
        if ( option == 3 ) {
            ret->GetEY()[i] = sqrt( abs(e1*e1 - e2*e2) );
        }
        if ( option == 10 ) {
            ret->GetEY()[i] = cumu_syst[0] * ret->GetY()[i];
            ret->GetEX()[i] = PbPb_sysX;
        }
        if ( option == 11 ) {
            ret->GetEY()[i] = cumu_syst[1] * ret->GetY()[i];
            ret->GetEX()[i] = PbPb_sysX;
        }
        if ( option == 12 ) {
            ret->GetEY()[i] = cumu_syst[2] * ret->GetY()[i];
            ret->GetEX()[i] = PbPb_sysX;
        }
    }
    return ret;
}

TGraphErrors* getRatio(TGraphErrors* gr1, TGraphErrors* gr2, int option = 0)
    /*
     * 0 - errors are independent
     * 1 - use only gr1 error
     * 2 - use only gr2 error
     * 3 - errors are correlated
     * 10 - use only cumu_syst[0] error Ch
     * 11 - use only cumu_syst[1] error Ks
     * 12 - use only cumu_syst[2] error Lm
     */
{
    if ( gr1->GetN() != gr2->GetN() ) {
        cout << " --> Warning mismatch getRatio" << endl;
        return nullptr;
    }
    TGraphErrors * ret = new TGraphErrors(gr2->GetN());
    for ( int i = 0; i < gr2->GetN(); i++ ) {
        if ( gr1->GetX()[i] != gr2->GetX()[i] ) cout << "--> Warning mismatch X" << endl;
        ret->GetX()[i] = gr2->GetX()[i];
        ret->GetEX()[i] = gr2->GetEX()[i];
        ret->GetY()[i] = gr1->GetY()[i] / gr2->GetY()[i];
        double y1 = gr1->GetY()[i];
        double y2 = gr2->GetY()[i];
        double e1 = gr1->GetEY()[i];
        double e2 = gr2->GetEY()[i];
        if ( option == 1 ) {
            e2 = 0;
        } else if ( option == 2 ) {
            e1 = 0;
        }
        ret->GetEY()[i] = y1/y2*sqrt( e1*e1/y1/y1 + e2*e2/y2/y2 );
        if ( option == 3 ) {
            ret->GetEY()[i] = y1/y2*sqrt( abs(e1*e1/y1/y1 + e2*e2/y2/y2 - 2*e1*e1/y1/y2) );
        }
        if ( option == 10 ) {
            ret->GetEY()[i] = cumu_syst[0] * ret->GetY()[i];
            ret->GetEX()[i] = PbPb_sysX;
        }
        if ( option == 11 ) {
            ret->GetEY()[i] = cumu_syst[1] * ret->GetY()[i];
            ret->GetEX()[i] = PbPb_sysX;
        }
        if ( option == 12 ) {
            ret->GetEY()[i] = cumu_syst[2] * ret->GetY()[i];
            ret->GetEX()[i] = PbPb_sysX;
        }
    }
    return ret;
}


void splitCanv4(TCanvas * c)
{
    if (!c) return;

    c->cd(0);
    TPad * p1 = new TPad("pad1", "", 0., 0., 0.26, 1.);
    p1->SetLeftMargin(0.12);
    p1->SetRightMargin(0.00);
    p1->SetBottomMargin(0.14);
    p1->SetTopMargin(0.07);
    p1->Draw();
    p1->SetNumber(1);

    TPad * p2 = new TPad("pad2", "", 0.26, 0., 0.51, 1.);
    p2->SetLeftMargin(0.00);
    p2->SetRightMargin(0.00);
    p2->SetBottomMargin(0.14);
    p2->SetTopMargin(0.07);
    p2->Draw();
    p2->SetNumber(2);

    TPad * p3 = new TPad("pad3", "", 0.51, 0., 0.76, 1.);
    p3->SetLeftMargin(0.00);
    p3->SetRightMargin(0.00);
    p3->SetBottomMargin(0.14);
    p3->SetTopMargin(0.07);
    p3->Draw();
    p3->SetNumber(3);

    TPad * p4 = new TPad("pad4", "", 0.76, 0., 1.0, 1.);
    p4->SetLeftMargin(0.00);
    p4->SetRightMargin(0.00);
    p4->SetBottomMargin(0.14);
    p4->SetTopMargin(0.07);
    p4->Draw();
    p4->SetNumber(4);
}

void setGr(TGraphErrors* gr, int kstyle, int kcolor, int ksz = 2)
{
    gr->SetMarkerStyle(kstyle);
    gr->SetMarkerColor(kcolor);
    gr->SetLineColor(kcolor);
    gr->SetMarkerSize(ksz);
}

TGraphErrors * getGr(TFile *f, string s, int kstyle, int kcolor, int ksz = 2)
{
    TGraphErrors * ret = (TGraphErrors*) f->Get(s.c_str());
    ret->SetMarkerStyle(kstyle);
    ret->SetMarkerColor(kcolor);
    ret->SetLineColor(kcolor);
    ret->SetMarkerSize(ksz);
    return ret;
}

typedef struct CumuGraph
{
    // Sig
    TGraphErrors* gr6_v24;
    TGraphErrors* gr7_v24;
    TGraphErrors* gr8_v24;
    TGraphErrors* gr9_v24;

    TGraphErrors* gr6_v26;
    TGraphErrors* gr7_v26;
    TGraphErrors* gr8_v26;
    TGraphErrors* gr9_v26;

    TGraphErrors* gr6_v24sub;
    TGraphErrors* gr7_v24sub;
    TGraphErrors* gr8_v24sub;
    TGraphErrors* gr9_v24sub;

    // Obs
    TGraphErrors* grObs6_v24;
    TGraphErrors* grObs7_v24;
    TGraphErrors* grObs8_v24;
    TGraphErrors* grObs9_v24;

    TGraphErrors* grObs6_v26;
    TGraphErrors* grObs7_v26;
    TGraphErrors* grObs8_v26;
    TGraphErrors* grObs9_v26;

    TGraphErrors* grObs6_v24sub;
    TGraphErrors* grObs7_v24sub;
    TGraphErrors* grObs8_v24sub;
    TGraphErrors* grObs9_v24sub;

    // SB
    TGraphErrors* grSB6_v24;
    TGraphErrors* grSB7_v24;
    TGraphErrors* grSB8_v24;
    TGraphErrors* grSB9_v24;

    TGraphErrors* grSB6_v26;
    TGraphErrors* grSB7_v26;
    TGraphErrors* grSB8_v26;
    TGraphErrors* grSB9_v26;

    TGraphErrors* grSB6_v24sub;
    TGraphErrors* grSB7_v24sub;
    TGraphErrors* grSB8_v24sub;
    TGraphErrors* grSB9_v24sub;

    //
    TGraphErrors* gr_v24      [10] = {};
    TGraphErrors* gr_v26      [10] = {};
    TGraphErrors* gr_v24sub   [10] = {};
    TGraphErrors* grObs_v24   [10] = {};
    TGraphErrors* grObs_v26   [10] = {};
    TGraphErrors* grObs_v24sub[10] = {};
    TGraphErrors* grSB_v24    [10] = {};
    TGraphErrors* grSB_v26    [10] = {};
    TGraphErrors* grSB_v24sub [10] = {};

    CumuGraph(TFile *f) {
        // Sig
        gr6_v24    = getGr( f, "grSig_pT2_1_6" , kOpenSquare, kBlue );
        gr7_v24    = getGr( f, "grSig_pT2_1_7" , kOpenSquare, kBlue );
        gr8_v24    = getGr( f, "grSig_pT2_1_8" , kOpenSquare, kBlue );
        gr9_v24    = getGr( f, "grSig_pT2_1_9" , kOpenSquare, kBlue );

        gr6_v26    = getGr( f, "grSig_pT2_2_6" , kOpenCross,  kRed  );
        gr7_v26    = getGr( f, "grSig_pT2_2_7" , kOpenCross,  kRed  );
        gr8_v26    = getGr( f, "grSig_pT2_2_8" , kOpenCross,  kRed  );
        gr9_v26    = getGr( f, "grSig_pT2_2_9" , kOpenCross,  kRed  );

        gr6_v24sub = getGr( f, "grSig_V2sub4_6", kOpenCircle, kBlue );
        gr7_v24sub = getGr( f, "grSig_V2sub4_7", kOpenCircle, kBlue );
        gr8_v24sub = getGr( f, "grSig_V2sub4_8", kOpenCircle, kBlue );
        gr9_v24sub = getGr( f, "grSig_V2sub4_9", kOpenCircle, kBlue );

        // Obs
        grObs6_v24    = getGr( f, "grObs_pT2_1_6" , kOpenSquare, kBlue );
        grObs7_v24    = getGr( f, "grObs_pT2_1_7" , kOpenSquare, kBlue );
        grObs8_v24    = getGr( f, "grObs_pT2_1_8" , kOpenSquare, kBlue );
        grObs9_v24    = getGr( f, "grObs_pT2_1_9" , kOpenSquare, kBlue );

        grObs6_v26    = getGr( f, "grObs_pT2_2_6" , kOpenCross,  kRed  );
        grObs7_v26    = getGr( f, "grObs_pT2_2_7" , kOpenCross,  kRed  );
        grObs8_v26    = getGr( f, "grObs_pT2_2_8" , kOpenCross,  kRed  );
        grObs9_v26    = getGr( f, "grObs_pT2_2_9" , kOpenCross,  kRed  );

        grObs6_v24sub = getGr( f, "grObs_V2sub4_6", kOpenCircle, kBlue );
        grObs7_v24sub = getGr( f, "grObs_V2sub4_7", kOpenCircle, kBlue );
        grObs8_v24sub = getGr( f, "grObs_V2sub4_8", kOpenCircle, kBlue );
        grObs9_v24sub = getGr( f, "grObs_V2sub4_9", kOpenCircle, kBlue );

        // SB
        grSB6_v24    = getGr( f, "grBkg_pT2_1_6" , kOpenSquare, kBlue );
        grSB7_v24    = getGr( f, "grBkg_pT2_1_7" , kOpenSquare, kBlue );
        grSB8_v24    = getGr( f, "grBkg_pT2_1_8" , kOpenSquare, kBlue );
        grSB9_v24    = getGr( f, "grBkg_pT2_1_9" , kOpenSquare, kBlue );

        grSB6_v26    = getGr( f, "grBkg_pT2_2_6" , kOpenCross,  kRed  );
        grSB7_v26    = getGr( f, "grBkg_pT2_2_7" , kOpenCross,  kRed  );
        grSB8_v26    = getGr( f, "grBkg_pT2_2_8" , kOpenCross,  kRed  );
        grSB9_v26    = getGr( f, "grBkg_pT2_2_9" , kOpenCross,  kRed  );

        grSB6_v24sub = getGr( f, "grBkg_V2sub4_6", kOpenCircle, kBlue );
        grSB7_v24sub = getGr( f, "grBkg_V2sub4_7", kOpenCircle, kBlue );
        grSB8_v24sub = getGr( f, "grBkg_V2sub4_8", kOpenCircle, kBlue );
        grSB9_v24sub = getGr( f, "grBkg_V2sub4_9", kOpenCircle, kBlue );

        //
        gr_v24        [6] = gr6_v24;
        gr_v24        [7] = gr7_v24;
        gr_v24        [8] = gr8_v24;
        gr_v24        [9] = gr9_v24;
        gr_v26        [6] = gr6_v26;
        gr_v26        [7] = gr7_v26;
        gr_v26        [8] = gr8_v26;
        gr_v26        [9] = gr9_v26;
        gr_v24sub     [6] = gr6_v24sub;
        gr_v24sub     [7] = gr7_v24sub;
        gr_v24sub     [8] = gr8_v24sub;
        gr_v24sub     [9] = gr9_v24sub;

        grObs_v24     [6] = grObs6_v24;
        grObs_v24     [7] = grObs7_v24;
        grObs_v24     [8] = grObs8_v24;
        grObs_v24     [9] = grObs9_v24;
        grObs_v26     [6] = grObs6_v26;
        grObs_v26     [7] = grObs7_v26;
        grObs_v26     [8] = grObs8_v26;
        grObs_v26     [9] = grObs9_v26;
        grObs_v24sub  [6] = grObs6_v24sub;
        grObs_v24sub  [7] = grObs7_v24sub;
        grObs_v24sub  [8] = grObs8_v24sub;
        grObs_v24sub  [9] = grObs9_v24sub;

        grSB_v24      [6] = grSB6_v24;
        grSB_v24      [7] = grSB7_v24;
        grSB_v24      [8] = grSB8_v24;
        grSB_v24      [9] = grSB9_v24;
        grSB_v26      [6] = grSB6_v26;
        grSB_v26      [7] = grSB7_v26;
        grSB_v26      [8] = grSB8_v26;
        grSB_v26      [9] = grSB9_v26;
        grSB_v24sub   [6] = grSB6_v24sub;
        grSB_v24sub   [7] = grSB7_v24sub;
        grSB_v24sub   [8] = grSB8_v24sub;
        grSB_v24sub   [9] = grSB9_v24sub;
    }

} CumuGraph;

typedef struct SteveGraphSP
{
    SteveGraph * grSP_H[10] = {};
    SteveGraph * grSP_Ks_Obs[10] = {};
    SteveGraph * grSP_Ks_SB [10] = {};
    SteveGraph * grSP_Ks_Sig[10] = {};
    SteveGraph * grSP_Lm_Obs[10] = {};
    SteveGraph * grSP_Lm_SB [10] = {};
    SteveGraph * grSP_Lm_Sig[10] = {};

    SteveGraphSP(TFile *f) {
        for ( int c = 6; c < 10; c++ ) {
            grSP_H[c]        = new SteveGraph( (TDirectoryFile*) f->Get( (string("ch_pPb_corrected_") + to_string(c)).c_str() ) );

            grSP_Ks_Obs[c]   = new SteveGraph( (TDirectoryFile*) f->Get( (string("Ks_pPb_Obs_") + to_string(c)).c_str() ) );
            grSP_Ks_SB [c]   = new SteveGraph( (TDirectoryFile*) f->Get( (string("Ks_pPb_SB_") + to_string(c)).c_str() ) );
            grSP_Ks_Sig[c]   = new SteveGraph( (TDirectoryFile*) f->Get( (string("Ks_pPb_corrected_") + to_string(c)).c_str() ) );

            grSP_Lm_Obs[c]   = new SteveGraph( (TDirectoryFile*) f->Get( (string("Lm_pPb_Obs_") + to_string(c)).c_str() ) );
            grSP_Lm_SB [c]   = new SteveGraph( (TDirectoryFile*) f->Get( (string("Lm_pPb_SB_") + to_string(c)).c_str() ) );
            grSP_Lm_Sig[c]   = new SteveGraph( (TDirectoryFile*) f->Get( (string("Lm_pPb_corrected_") + to_string(c)).c_str() ) );
        }
    };

} SteveGraphSP;

struct SaveToFile
{
    TFile * fsave;
    SaveToFile(TFile *f) { fsave = f; };
    void WriteGr( TGraphErrors * gr, string name ) {
        fsave->cd();
        gr->Write(name.c_str());
    };
    ~SaveToFile() {fsave->Close();};
};

void DropPoints( TGraphErrors* gr, int N )
{
    if ( N > 0 ) {
        for ( int i = 0; i < N; i++ ) {
            gr->RemovePoint(0);
        }
    } else {
        for ( int i = 0; i < -N; i++ ) {
            gr->RemovePoint(gr->GetN()-1);
        }
    }
}
