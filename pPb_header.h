#include "../cumudiff/Steve_SP.h"

TColor *red = new TColor(3001, 1, 0, 0, "red", 0.4);
TColor *green = new TColor(3002, 0, 0.5, 0, "green", 0.4);
TColor *blue = new TColor(3003, 0, 0, 1, "blue", 0.4);
TColor *gray = new TColor(3005, 0, 0, 0, "black", 0.4);

const double pPb_sysY = 0.025;
const double pPb_sysX = 0.35;


TGraphErrors* grSys(TGraphErrors* gr, double sysX = pPb_sysX, double sysY = pPb_sysY) {
    int N = gr->GetN();
    TGraphErrors* ret = new TGraphErrors(N);
    for ( int i = 0; i < N; i++ ) {
        ret->GetX()[i] = gr->GetX()[i];
        ret->GetY()[i] = gr->GetY()[i];
        ret->GetEX()[i] = sysX;
        ret->GetEY()[i] = sysY * gr->GetY()[i];
    }
    return ret;
}

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
TGraphErrors* getFluct(TGraphErrors* gr1, TGraphErrors* gr2, TGraphErrors*& grSys, double sys = pPb_sysY) {
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
        grSys->GetEX()[i] = pPb_sysX;
        grSys->GetY()[i] = ret->GetY()[i];

        double serr1 = (f1/g - t*g1/g/g)*sys*y1;
        grSys->GetEY()[i] = serr1 / 2. / sqrt(x);
    }
    return ret;
}

TGraphErrors* getRatio(TGraphErrors* gr1, TGraphErrors* gr2, int option = 0)
    /*
     * 0 - errors are independent
     * 1 - use only gr1 error
     * 2 - use only gr2 error
     * 3 or 10, 11, 12 - use only pPb_sysY error
     */
{
    if ( gr1->GetN() != gr2->GetN() ) {
        cout << " --> Warning mismatch getRatio: N1 = " << gr1->GetN() << " N2 = " << gr2->GetN() << endl;
        //return nullptr;
    }
    int N = (gr1->GetN()<gr2->GetN()) ? gr1->GetN() : gr2->GetN();
    TGraphErrors * ret = new TGraphErrors(gr2->GetN());
    for ( int i = 0; i < N; i++ ) {
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
        ret->GetEY()[i] = sqrt( e1*e1/y1/y1 + e2*e2/y2/y2 );
        if ( (option == 3) or (option == 10) or (option == 11) or (option == 12) ) {
            ret->GetEY()[i] = pPb_sysY * ret->GetY()[i];
            ret->GetEX()[i] = pPb_sysX;
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
    p1->SetBottomMargin(0.12);
    p1->SetTopMargin(0.07);
    p1->Draw();
    p1->SetNumber(1);

    TPad * p2 = new TPad("pad2", "", 0.26, 0., 0.51, 1.);
    p2->SetLeftMargin(0.00);
    p2->SetRightMargin(0.00);
    p2->SetBottomMargin(0.12);
    p2->SetTopMargin(0.07);
    p2->Draw();
    p2->SetNumber(2);

    TPad * p3 = new TPad("pad3", "", 0.51, 0., 0.76, 1.);
    p3->SetLeftMargin(0.00);
    p3->SetRightMargin(0.00);
    p3->SetBottomMargin(0.12);
    p3->SetTopMargin(0.07);
    p3->Draw();
    p3->SetNumber(3);

    TPad * p4 = new TPad("pad4", "", 0.76, 0., 1.0, 1.);
    p4->SetLeftMargin(0.00);
    p4->SetRightMargin(0.00);
    p4->SetBottomMargin(0.12);
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
    TGraphErrors* gr6_v22Gap;
    TGraphErrors* gr7_v22Gap;
    TGraphErrors* gr8_v22Gap;
    TGraphErrors* gr9_v22Gap;

    TGraphErrors* gr6_v24;
    TGraphErrors* gr7_v24;
    TGraphErrors* gr8_v24;
    TGraphErrors* gr9_v24;

    TGraphErrors* gr6_v26;
    TGraphErrors* gr7_v26;
    TGraphErrors* gr8_v26;
    TGraphErrors* gr9_v26;

    TGraphErrors* gr6_v28;
    TGraphErrors* gr7_v28;
    TGraphErrors* gr8_v28;
    TGraphErrors* gr9_v28;

    TGraphErrors* gr6_v24sub;
    TGraphErrors* gr7_v24sub;
    TGraphErrors* gr8_v24sub;
    TGraphErrors* gr9_v24sub;

    TGraphErrors* gr6_v24subpos;
    TGraphErrors* gr7_v24subpos;
    TGraphErrors* gr8_v24subpos;
    TGraphErrors* gr9_v24subpos;

    TGraphErrors* gr6_v24subneg;
    TGraphErrors* gr7_v24subneg;
    TGraphErrors* gr8_v24subneg;
    TGraphErrors* gr9_v24subneg;

    // Obs
    TGraphErrors* grObs6_v22Gap;
    TGraphErrors* grObs7_v22Gap;
    TGraphErrors* grObs8_v22Gap;
    TGraphErrors* grObs9_v22Gap;

    TGraphErrors* grObs6_v24;
    TGraphErrors* grObs7_v24;
    TGraphErrors* grObs8_v24;
    TGraphErrors* grObs9_v24;

    TGraphErrors* grObs6_v26;
    TGraphErrors* grObs7_v26;
    TGraphErrors* grObs8_v26;
    TGraphErrors* grObs9_v26;

    TGraphErrors* grObs6_v28;
    TGraphErrors* grObs7_v28;
    TGraphErrors* grObs8_v28;
    TGraphErrors* grObs9_v28;

    TGraphErrors* grObs6_v24sub;
    TGraphErrors* grObs7_v24sub;
    TGraphErrors* grObs8_v24sub;
    TGraphErrors* grObs9_v24sub;

    // SB
    TGraphErrors* grSB6_v22Gap;
    TGraphErrors* grSB7_v22Gap;
    TGraphErrors* grSB8_v22Gap;
    TGraphErrors* grSB9_v22Gap;

    TGraphErrors* grSB6_v24;
    TGraphErrors* grSB7_v24;
    TGraphErrors* grSB8_v24;
    TGraphErrors* grSB9_v24;

    TGraphErrors* grSB6_v26;
    TGraphErrors* grSB7_v26;
    TGraphErrors* grSB8_v26;
    TGraphErrors* grSB9_v26;

    TGraphErrors* grSB6_v28;
    TGraphErrors* grSB7_v28;
    TGraphErrors* grSB8_v28;
    TGraphErrors* grSB9_v28;

    TGraphErrors* grSB6_v24sub;
    TGraphErrors* grSB7_v24sub;
    TGraphErrors* grSB8_v24sub;
    TGraphErrors* grSB9_v24sub;

    //
    TGraphErrors* gr_v22Gap   [10] = {};
    TGraphErrors* gr_v24      [10] = {};
    TGraphErrors* gr_v26      [10] = {};
    TGraphErrors* gr_v28      [10] = {};
    TGraphErrors* gr_v24sub   [10] = {};
    TGraphErrors* grObs_v22Gap[10] = {};
    TGraphErrors* grObs_v24   [10] = {};
    TGraphErrors* grObs_v26   [10] = {};
    TGraphErrors* grObs_v28   [10] = {};
    TGraphErrors* grObs_v24sub[10] = {};
    TGraphErrors* grSB_v22Gap [10] = {};
    TGraphErrors* grSB_v24    [10] = {};
    TGraphErrors* grSB_v26    [10] = {};
    TGraphErrors* grSB_v28    [10] = {};
    TGraphErrors* grSB_v24sub [10] = {};

    TGraphErrors* gr_v24subpos[10] = {};
    TGraphErrors* gr_v24subneg[10] = {};

    TGraphErrors* grSys_v22Gap[10] = {};
    TGraphErrors* grSys_v24   [10] = {};
    TGraphErrors* grSys_v26   [10] = {};
    TGraphErrors* grSys_v28   [10] = {};
    TGraphErrors* grSys_v24sub[10] = {};

    TGraphErrors* grSys_v24subpos[10] = {};
    TGraphErrors* grSys_v24subneg[10] = {};

    CumuGraph(TFile *f) {
        // Sig
        gr6_v22Gap = getGr( f, "grSig_pTGap2_6" , kOpenSquare, kBlue );
        gr7_v22Gap = getGr( f, "grSig_pTGap2_7" , kOpenSquare, kBlue );
        gr8_v22Gap = getGr( f, "grSig_pTGap2_8" , kOpenSquare, kBlue );
        gr9_v22Gap = getGr( f, "grSig_pTGap2_9" , kOpenSquare, kBlue );

        gr6_v24    = getGr( f, "grSig_pT2_1_6" , kOpenSquare, kBlue );
        gr7_v24    = getGr( f, "grSig_pT2_1_7" , kOpenSquare, kBlue );
        gr8_v24    = getGr( f, "grSig_pT2_1_8" , kOpenSquare, kBlue );
        gr9_v24    = getGr( f, "grSig_pT2_1_9" , kOpenSquare, kBlue );

        gr6_v26    = getGr( f, "grSig_pT2_2_6" , kOpenCross,  kRed  );
        gr7_v26    = getGr( f, "grSig_pT2_2_7" , kOpenCross,  kRed  );
        gr8_v26    = getGr( f, "grSig_pT2_2_8" , kOpenCross,  kRed  );
        gr9_v26    = getGr( f, "grSig_pT2_2_9" , kOpenCross,  kRed  );

        gr6_v28    = getGr( f, "grSig_pT2_3_6" , kFullDiamond,  kRed  );
        gr7_v28    = getGr( f, "grSig_pT2_3_7" , kFullDiamond,  kRed  );
        gr8_v28    = getGr( f, "grSig_pT2_3_8" , kFullDiamond,  kRed  );
        gr9_v28    = getGr( f, "grSig_pT2_3_9" , kFullDiamond,  kRed  );

        gr6_v24sub = getGr( f, "grSig_V2sub4_6", kOpenCircle, kBlue );
        gr7_v24sub = getGr( f, "grSig_V2sub4_7", kOpenCircle, kBlue );
        gr8_v24sub = getGr( f, "grSig_V2sub4_8", kOpenCircle, kBlue );
        gr9_v24sub = getGr( f, "grSig_V2sub4_9", kOpenCircle, kBlue );

        gr6_v24subneg = getGr( f, "grSig_V2sub4neg_6", kOpenCircle, kBlue );
        gr7_v24subneg = getGr( f, "grSig_V2sub4neg_7", kOpenCircle, kBlue );
        gr8_v24subneg = getGr( f, "grSig_V2sub4neg_8", kOpenCircle, kBlue );
        gr9_v24subneg = getGr( f, "grSig_V2sub4neg_9", kOpenCircle, kBlue );

        gr6_v24subpos = getGr( f, "grSig_V2sub4pos_6", kOpenCircle, kBlue );
        gr7_v24subpos = getGr( f, "grSig_V2sub4pos_7", kOpenCircle, kBlue );
        gr8_v24subpos = getGr( f, "grSig_V2sub4pos_8", kOpenCircle, kBlue );
        gr9_v24subpos = getGr( f, "grSig_V2sub4pos_9", kOpenCircle, kBlue );

        // Obs
        grObs6_v22Gap = getGr( f, "grObs_pTGap2_6" , kOpenSquare, kBlue );
        grObs7_v22Gap = getGr( f, "grObs_pTGap2_7" , kOpenSquare, kBlue );
        grObs8_v22Gap = getGr( f, "grObs_pTGap2_8" , kOpenSquare, kBlue );
        grObs9_v22Gap = getGr( f, "grObs_pTGap2_9" , kOpenSquare, kBlue );

        grObs6_v24    = getGr( f, "grObs_pT2_1_6" , kOpenSquare, kBlue );
        grObs7_v24    = getGr( f, "grObs_pT2_1_7" , kOpenSquare, kBlue );
        grObs8_v24    = getGr( f, "grObs_pT2_1_8" , kOpenSquare, kBlue );
        grObs9_v24    = getGr( f, "grObs_pT2_1_9" , kOpenSquare, kBlue );

        grObs6_v26    = getGr( f, "grObs_pT2_2_6" , kOpenCross,  kRed  );
        grObs7_v26    = getGr( f, "grObs_pT2_2_7" , kOpenCross,  kRed  );
        grObs8_v26    = getGr( f, "grObs_pT2_2_8" , kOpenCross,  kRed  );
        grObs9_v26    = getGr( f, "grObs_pT2_2_9" , kOpenCross,  kRed  );

        grObs6_v28    = getGr( f, "grObs_pT2_3_6" , kOpenCross,  kRed  );
        grObs7_v28    = getGr( f, "grObs_pT2_3_7" , kOpenCross,  kRed  );
        grObs8_v28    = getGr( f, "grObs_pT2_3_8" , kOpenCross,  kRed  );
        grObs9_v28    = getGr( f, "grObs_pT2_3_9" , kOpenCross,  kRed  );

        grObs6_v24sub = getGr( f, "grObs_V2sub4_6", kOpenCircle, kBlue );
        grObs7_v24sub = getGr( f, "grObs_V2sub4_7", kOpenCircle, kBlue );
        grObs8_v24sub = getGr( f, "grObs_V2sub4_8", kOpenCircle, kBlue );
        grObs9_v24sub = getGr( f, "grObs_V2sub4_9", kOpenCircle, kBlue );

        // SB
        grSB6_v22Gap = getGr( f, "grBkg_pTGap2_6" , kOpenSquare, kBlue );
        grSB7_v22Gap = getGr( f, "grBkg_pTGap2_7" , kOpenSquare, kBlue );
        grSB8_v22Gap = getGr( f, "grBkg_pTGap2_8" , kOpenSquare, kBlue );
        grSB9_v22Gap = getGr( f, "grBkg_pTGap2_9" , kOpenSquare, kBlue );

        grSB6_v24    = getGr( f, "grBkg_pT2_1_6" , kOpenSquare, kBlue );
        grSB7_v24    = getGr( f, "grBkg_pT2_1_7" , kOpenSquare, kBlue );
        grSB8_v24    = getGr( f, "grBkg_pT2_1_8" , kOpenSquare, kBlue );
        grSB9_v24    = getGr( f, "grBkg_pT2_1_9" , kOpenSquare, kBlue );

        grSB6_v26    = getGr( f, "grBkg_pT2_2_6" , kOpenCross,  kRed  );
        grSB7_v26    = getGr( f, "grBkg_pT2_2_7" , kOpenCross,  kRed  );
        grSB8_v26    = getGr( f, "grBkg_pT2_2_8" , kOpenCross,  kRed  );
        grSB9_v26    = getGr( f, "grBkg_pT2_2_9" , kOpenCross,  kRed  );

        grSB6_v28    = getGr( f, "grBkg_pT2_3_6" , kOpenCross,  kRed  );
        grSB7_v28    = getGr( f, "grBkg_pT2_3_7" , kOpenCross,  kRed  );
        grSB8_v28    = getGr( f, "grBkg_pT2_3_8" , kOpenCross,  kRed  );
        grSB9_v28    = getGr( f, "grBkg_pT2_3_9" , kOpenCross,  kRed  );

        grSB6_v24sub = getGr( f, "grBkg_V2sub4_6", kOpenCircle, kBlue );
        grSB7_v24sub = getGr( f, "grBkg_V2sub4_7", kOpenCircle, kBlue );
        grSB8_v24sub = getGr( f, "grBkg_V2sub4_8", kOpenCircle, kBlue );
        grSB9_v24sub = getGr( f, "grBkg_V2sub4_9", kOpenCircle, kBlue );

        //
        gr_v22Gap     [6] = gr6_v22Gap;
        gr_v22Gap     [7] = gr7_v22Gap;
        gr_v22Gap     [8] = gr8_v22Gap;
        gr_v22Gap     [9] = gr9_v22Gap;
        gr_v24        [6] = gr6_v24;
        gr_v24        [7] = gr7_v24;
        gr_v24        [8] = gr8_v24;
        gr_v24        [9] = gr9_v24;
        gr_v26        [6] = gr6_v26;
        gr_v26        [7] = gr7_v26;
        gr_v26        [8] = gr8_v26;
        gr_v26        [9] = gr9_v26;
        gr_v28        [6] = gr6_v28;
        gr_v28        [7] = gr7_v28;
        gr_v28        [8] = gr8_v28;
        gr_v28        [9] = gr9_v28;
        gr_v24sub     [6] = gr6_v24sub;
        gr_v24sub     [7] = gr7_v24sub;
        gr_v24sub     [8] = gr8_v24sub;
        gr_v24sub     [9] = gr9_v24sub;

        gr_v24subpos [6] = gr6_v24subpos;
        gr_v24subpos [7] = gr7_v24subpos;
        gr_v24subpos [8] = gr8_v24subpos;
        gr_v24subpos [9] = gr9_v24subpos;

        gr_v24subneg [6] = gr6_v24subneg;
        gr_v24subneg [7] = gr7_v24subneg;
        gr_v24subneg [8] = gr8_v24subneg;
        gr_v24subneg [9] = gr9_v24subneg;

        grObs_v22Gap  [6] = grObs6_v22Gap;
        grObs_v22Gap  [7] = grObs7_v22Gap;
        grObs_v22Gap  [8] = grObs8_v22Gap;
        grObs_v22Gap  [9] = grObs9_v22Gap;
        grObs_v24     [6] = grObs6_v24;
        grObs_v24     [7] = grObs7_v24;
        grObs_v24     [8] = grObs8_v24;
        grObs_v24     [9] = grObs9_v24;
        grObs_v26     [6] = grObs6_v26;
        grObs_v26     [7] = grObs7_v26;
        grObs_v26     [8] = grObs8_v26;
        grObs_v26     [9] = grObs9_v26;
        grObs_v28     [6] = grObs6_v28;
        grObs_v28     [7] = grObs7_v28;
        grObs_v28     [8] = grObs8_v28;
        grObs_v28     [9] = grObs9_v28;
        grObs_v24sub  [6] = grObs6_v24sub;
        grObs_v24sub  [7] = grObs7_v24sub;
        grObs_v24sub  [8] = grObs8_v24sub;
        grObs_v24sub  [9] = grObs9_v24sub;

        grSB_v22Gap   [6] = grSB6_v22Gap;
        grSB_v22Gap   [7] = grSB7_v22Gap;
        grSB_v22Gap   [8] = grSB8_v22Gap;
        grSB_v22Gap   [9] = grSB9_v22Gap;
        grSB_v24      [6] = grSB6_v24;
        grSB_v24      [7] = grSB7_v24;
        grSB_v24      [8] = grSB8_v24;
        grSB_v24      [9] = grSB9_v24;
        grSB_v26      [6] = grSB6_v26;
        grSB_v26      [7] = grSB7_v26;
        grSB_v26      [8] = grSB8_v26;
        grSB_v26      [9] = grSB9_v26;
        grSB_v28      [6] = grSB6_v28;
        grSB_v28      [7] = grSB7_v28;
        grSB_v28      [8] = grSB8_v28;
        grSB_v28      [9] = grSB9_v28;
        grSB_v24sub   [6] = grSB6_v24sub;
        grSB_v24sub   [7] = grSB7_v24sub;
        grSB_v24sub   [8] = grSB8_v24sub;
        grSB_v24sub   [9] = grSB9_v24sub;
    }

    void SetSys(double sysX = pPb_sysX, double sysY = pPb_sysY) {
        for ( int c = 6; c < 10; c++ ) {
            grSys_v22Gap[c] = grSys( gr_v22Gap[c], sysX, sysY);
            grSys_v24   [c] = grSys( gr_v24   [c], sysX, sysY);
            grSys_v26   [c] = grSys( gr_v26   [c], sysX, sysY);
            grSys_v28   [c] = grSys( gr_v28   [c], sysX, sysY);
            grSys_v24sub[c] = grSys( gr_v24sub[c], sysX, sysY);
            grSys_v24subpos[c] = grSys( gr_v24subpos[c], sysX, sysY);
            grSys_v24subneg[c] = grSys( gr_v24subneg[c], sysX, sysY);
        }
        return;
    }

    void DropPoints(int N) {
        for ( int c = 6; c < 10; c++ ) {
            grDropPoints( gr_v22Gap[c], N);
            grDropPoints( gr_v24[c],    N);
            grDropPoints( gr_v26[c],    N);
            grDropPoints( gr_v28[c],    N);
            grDropPoints( gr_v24sub[c], N);
            grDropPoints( gr_v24subpos[c], N);
            grDropPoints( gr_v24subneg[c], N);

            grDropPoints( grSys_v22Gap[c], N);
            grDropPoints( grSys_v24[c],    N);
            grDropPoints( grSys_v26[c],    N);
            grDropPoints( grSys_v28[c],    N);
            grDropPoints( grSys_v24sub[c], N);
            grDropPoints( grSys_v24subpos[c], N);
            grDropPoints( grSys_v24subneg[c], N);
        }
    }

    void ReplaceX(SteveGraph** sp) {
        for ( int c= 6; c < 10; c++ ) {
            grReplaceX( gr_v22Gap[c], sp[c]->vn_Full_PosEtaEP );
            grReplaceX( gr_v24[c],    sp[c]->vn_Full_PosEtaEP );
            grReplaceX( gr_v26[c],    sp[c]->vn_Full_PosEtaEP );
            grReplaceX( gr_v28[c],    sp[c]->vn_Full_PosEtaEP );
            grReplaceX( gr_v24sub[c], sp[c]->vn_Full_PosEtaEP );
            grReplaceX( gr_v24subpos[c], sp[c]->vn_NegEta_PosEtaEP );
            grReplaceX( gr_v24subneg[c], sp[c]->vn_PosEta_NegEtaEP );
        }
    }

private:
    void grDropPoints(TGraphErrors* gr, int N) {
        for ( int i = 0; i < N; i++ ) {
            gr->RemovePoint(0);
        }
    }
    void grReplaceX(TGraphErrors* gr1, TGraphErrors* gr2) {
        if ( gr1->GetN() != gr2->GetN() ) {
            cout << " !!! --> Mismatch N" << endl;
            return;
        }
        for ( int i = 0; i < gr1->GetN(); i++ ) {
            gr1->GetX()[i] = gr2->GetX()[i];
        }
        return;
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

    void SetSys(double sysX = pPb_sysX, double sysY = pPb_sysY) {
        for ( int c = 6; c < 10; c++ ) {
            grSP_H     [c]->SetSys(sysX, sysY);
            grSP_Ks_Obs[c]->SetSys(sysX, sysY);
            grSP_Ks_SB [c]->SetSys(sysX, sysY);
            grSP_Ks_Sig[c]->SetSys(sysX, sysY);
            grSP_Lm_Obs[c]->SetSys(sysX, sysY);
            grSP_Lm_SB [c]->SetSys(sysX, sysY);
            grSP_Lm_Sig[c]->SetSys(sysX, sysY);
        }
        return;
    }

    void DropPoints() {
        for ( int c = 6; c < 10; c++ ) {
            grSP_H[c]->DropPoints(1);
            grSP_Lm_Sig[c]->DropPoints(3);
        }
    }

private:

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
