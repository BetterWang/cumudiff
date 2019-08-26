#include "../../style.h"
#include "HIN-17-003.h"
#include "ALICE.h"

void FixPAKs(TGraphErrors*);
void FixPALm(TGraphErrors*);


void drawGr(TGraph*, TLegend*);

void setColor(TGraph*, int);

TGraphErrors* getRatio(TGraphErrors*, TGraphErrors*);

std::map<TGraph*, std::string> * grLeg = nullptr;

TColor *red = new TColor(3001, 1, 0, 0, "red", 0.4);
TColor *green = new TColor(3002, 0, 0.5, 0, "green", 0.4);
TColor *blue = new TColor(3003, 0, 0, 1, "blue", 0.4);
TColor *gray = new TColor(3005, 0, 0, 0, "black", 0.4);

TGraphErrors * getGrSys(TGraphErrors*, double, int);

TGraphErrors * getGr(TFile *f, string s, int kstyle, int kcolor, int ksz = 2);

void makePlot3()
{
    SetStyle();

    HIN_17_003();
    ALICE();

    TFile * fPA_Ks = new TFile("pPb_Ks2_corrected.root");
    TFile * fPA_Lm = new TFile("pPb_Lm2_corrected.root");

    // PA Ks Sig
    TGraphErrors * grPA_Ks6_v24    = getGr( fPA_Ks, "grSig_pT2_1_6" , kFullSquare, kBlue );
    TGraphErrors * grPA_Ks7_v24    = getGr( fPA_Ks, "grSig_pT2_1_7" , kFullSquare, kBlue );
    TGraphErrors * grPA_Ks8_v24    = getGr( fPA_Ks, "grSig_pT2_1_8" , kFullSquare, kBlue );
    TGraphErrors * grPA_Ks9_v24    = getGr( fPA_Ks, "grSig_pT2_1_9" , kFullSquare, kBlue );

    TGraphErrors * grPA_Ks6_v26    = getGr( fPA_Ks, "grSig_pT2_2_6" , kFullCross,  kRed  );
    TGraphErrors * grPA_Ks7_v26    = getGr( fPA_Ks, "grSig_pT2_2_7" , kFullCross,  kRed  );
    TGraphErrors * grPA_Ks8_v26    = getGr( fPA_Ks, "grSig_pT2_2_8" , kFullCross,  kRed  );
    TGraphErrors * grPA_Ks9_v26    = getGr( fPA_Ks, "grSig_pT2_2_9" , kFullCross,  kRed  );

    TGraphErrors * grPA_Ks6_v24sub = getGr( fPA_Ks, "grSig_V2sub4_6", kOpenCircle, kBlue );
    TGraphErrors * grPA_Ks7_v24sub = getGr( fPA_Ks, "grSig_V2sub4_7", kOpenCircle, kBlue );
    TGraphErrors * grPA_Ks8_v24sub = getGr( fPA_Ks, "grSig_V2sub4_8", kOpenCircle, kBlue );
    TGraphErrors * grPA_Ks9_v24sub = getGr( fPA_Ks, "grSig_V2sub4_9", kOpenCircle, kBlue );


    FixPAKs( grPA_Ks6_v24 );
    FixPAKs( grPA_Ks7_v24 );
    FixPAKs( grPA_Ks8_v24 );
    FixPAKs( grPA_Ks9_v24 );

    FixPAKs( grPA_Ks6_v26 );
    FixPAKs( grPA_Ks7_v26 );
    FixPAKs( grPA_Ks8_v26 );
    FixPAKs( grPA_Ks9_v26 );

    FixPAKs( grPA_Ks6_v24sub );
    FixPAKs( grPA_Ks7_v24sub );
    FixPAKs( grPA_Ks8_v24sub );
    FixPAKs( grPA_Ks9_v24sub );

    // Obs
    TGraphErrors * grPAObs_Ks6_v24    = getGr( fPA_Ks, "grObs_pT2_1_6" , kFullSquare, kBlue );
    TGraphErrors * grPAObs_Ks7_v24    = getGr( fPA_Ks, "grObs_pT2_1_7" , kFullSquare, kBlue );
    TGraphErrors * grPAObs_Ks8_v24    = getGr( fPA_Ks, "grObs_pT2_1_8" , kFullSquare, kBlue );
    TGraphErrors * grPAObs_Ks9_v24    = getGr( fPA_Ks, "grObs_pT2_1_9" , kFullSquare, kBlue );

    TGraphErrors * grPAObs_Ks6_v26    = getGr( fPA_Ks, "grObs_pT2_2_6" , kFullCross,  kRed  );
    TGraphErrors * grPAObs_Ks7_v26    = getGr( fPA_Ks, "grObs_pT2_2_7" , kFullCross,  kRed  );
    TGraphErrors * grPAObs_Ks8_v26    = getGr( fPA_Ks, "grObs_pT2_2_8" , kFullCross,  kRed  );
    TGraphErrors * grPAObs_Ks9_v26    = getGr( fPA_Ks, "grObs_pT2_2_9" , kFullCross,  kRed  );

    TGraphErrors * grPAObs_Ks6_v24sub = getGr( fPA_Ks, "grObs_V2sub4_6", kOpenCircle, kBlue );
    TGraphErrors * grPAObs_Ks7_v24sub = getGr( fPA_Ks, "grObs_V2sub4_7", kOpenCircle, kBlue );
    TGraphErrors * grPAObs_Ks8_v24sub = getGr( fPA_Ks, "grObs_V2sub4_8", kOpenCircle, kBlue );
    TGraphErrors * grPAObs_Ks9_v24sub = getGr( fPA_Ks, "grObs_V2sub4_9", kOpenCircle, kBlue );

    FixPAKs( grPAObs_Ks6_v24 );
    FixPAKs( grPAObs_Ks7_v24 );
    FixPAKs( grPAObs_Ks8_v24 );
    FixPAKs( grPAObs_Ks9_v24 );

    FixPAKs( grPAObs_Ks6_v26 );
    FixPAKs( grPAObs_Ks7_v26 );
    FixPAKs( grPAObs_Ks8_v26 );
    FixPAKs( grPAObs_Ks9_v26 );

    FixPAKs( grPAObs_Ks6_v24sub );
    FixPAKs( grPAObs_Ks7_v24sub );
    FixPAKs( grPAObs_Ks8_v24sub );
    FixPAKs( grPAObs_Ks9_v24sub );

    // Bkg
    TGraphErrors * grPABkg_Ks6_v24    = getGr( fPA_Ks, "grBkg_pT2_1_6" , kFullSquare, kBlue );
    TGraphErrors * grPABkg_Ks7_v24    = getGr( fPA_Ks, "grBkg_pT2_1_7" , kFullSquare, kBlue );
    TGraphErrors * grPABkg_Ks8_v24    = getGr( fPA_Ks, "grBkg_pT2_1_8" , kFullSquare, kBlue );
    TGraphErrors * grPABkg_Ks9_v24    = getGr( fPA_Ks, "grBkg_pT2_1_9" , kFullSquare, kBlue );

    TGraphErrors * grPABkg_Ks6_v26    = getGr( fPA_Ks, "grBkg_pT2_2_6" , kFullCross,  kRed  );
    TGraphErrors * grPABkg_Ks7_v26    = getGr( fPA_Ks, "grBkg_pT2_2_7" , kFullCross,  kRed  );
    TGraphErrors * grPABkg_Ks8_v26    = getGr( fPA_Ks, "grBkg_pT2_2_8" , kFullCross,  kRed  );
    TGraphErrors * grPABkg_Ks9_v26    = getGr( fPA_Ks, "grBkg_pT2_2_9" , kFullCross,  kRed  );

    TGraphErrors * grPABkg_Ks6_v24sub = getGr( fPA_Ks, "grBkg_V2sub4_6", kOpenCircle, kBlue );
    TGraphErrors * grPABkg_Ks7_v24sub = getGr( fPA_Ks, "grBkg_V2sub4_7", kOpenCircle, kBlue );
    TGraphErrors * grPABkg_Ks8_v24sub = getGr( fPA_Ks, "grBkg_V2sub4_8", kOpenCircle, kBlue );
    TGraphErrors * grPABkg_Ks9_v24sub = getGr( fPA_Ks, "grBkg_V2sub4_9", kOpenCircle, kBlue );


    FixPAKs( grPABkg_Ks6_v24 );
    FixPAKs( grPABkg_Ks7_v24 );
    FixPAKs( grPABkg_Ks8_v24 );
    FixPAKs( grPABkg_Ks9_v24 );

    FixPAKs( grPABkg_Ks6_v26 );
    FixPAKs( grPABkg_Ks7_v26 );
    FixPAKs( grPABkg_Ks8_v26 );
    FixPAKs( grPABkg_Ks9_v26 );

    FixPAKs( grPABkg_Ks6_v24sub );
    FixPAKs( grPABkg_Ks7_v24sub );
    FixPAKs( grPABkg_Ks8_v24sub );
    FixPAKs( grPABkg_Ks9_v24sub );



    // PA Lm Sig
    TGraphErrors * grPA_Lm6_v24    = getGr( fPA_Lm, "grSig_pT2_1_6" , kFullSquare, kBlue );
    TGraphErrors * grPA_Lm7_v24    = getGr( fPA_Lm, "grSig_pT2_1_7" , kFullSquare, kBlue );
    TGraphErrors * grPA_Lm8_v24    = getGr( fPA_Lm, "grSig_pT2_1_8" , kFullSquare, kBlue );
    TGraphErrors * grPA_Lm9_v24    = getGr( fPA_Lm, "grSig_pT2_1_9" , kFullSquare, kBlue );

    TGraphErrors * grPA_Lm6_v26    = getGr( fPA_Lm, "grSig_pT2_2_6" , kFullCross,  kRed  );
    TGraphErrors * grPA_Lm7_v26    = getGr( fPA_Lm, "grSig_pT2_2_7" , kFullCross,  kRed  );
    TGraphErrors * grPA_Lm8_v26    = getGr( fPA_Lm, "grSig_pT2_2_8" , kFullCross,  kRed  );
    TGraphErrors * grPA_Lm9_v26    = getGr( fPA_Lm, "grSig_pT2_2_9" , kFullCross,  kRed  );

    TGraphErrors * grPA_Lm6_v24sub = getGr( fPA_Lm, "grSig_V2sub4_6", kOpenCircle, kBlue );
    TGraphErrors * grPA_Lm7_v24sub = getGr( fPA_Lm, "grSig_V2sub4_7", kOpenCircle, kBlue );
    TGraphErrors * grPA_Lm8_v24sub = getGr( fPA_Lm, "grSig_V2sub4_8", kOpenCircle, kBlue );
    TGraphErrors * grPA_Lm9_v24sub = getGr( fPA_Lm, "grSig_V2sub4_9", kOpenCircle, kBlue );


    FixPALm( grPA_Lm6_v24 );
    FixPALm( grPA_Lm7_v24 );
    FixPALm( grPA_Lm8_v24 );
    FixPALm( grPA_Lm9_v24 );

    FixPALm( grPA_Lm6_v26 );
    FixPALm( grPA_Lm7_v26 );
    FixPALm( grPA_Lm8_v26 );
    FixPALm( grPA_Lm9_v26 );

    FixPALm( grPA_Lm6_v24sub );
    FixPALm( grPA_Lm7_v24sub );
    FixPALm( grPA_Lm8_v24sub );
    FixPALm( grPA_Lm9_v24sub );

    // Obs
    TGraphErrors * grPAObs_Lm6_v24    = getGr( fPA_Lm, "grObs_pT2_1_6" , kFullSquare, kBlue );
    TGraphErrors * grPAObs_Lm7_v24    = getGr( fPA_Lm, "grObs_pT2_1_7" , kFullSquare, kBlue );
    TGraphErrors * grPAObs_Lm8_v24    = getGr( fPA_Lm, "grObs_pT2_1_8" , kFullSquare, kBlue );
    TGraphErrors * grPAObs_Lm9_v24    = getGr( fPA_Lm, "grObs_pT2_1_9" , kFullSquare, kBlue );

    TGraphErrors * grPAObs_Lm6_v26    = getGr( fPA_Lm, "grObs_pT2_2_6" , kFullCross,  kRed  );
    TGraphErrors * grPAObs_Lm7_v26    = getGr( fPA_Lm, "grObs_pT2_2_7" , kFullCross,  kRed  );
    TGraphErrors * grPAObs_Lm8_v26    = getGr( fPA_Lm, "grObs_pT2_2_8" , kFullCross,  kRed  );
    TGraphErrors * grPAObs_Lm9_v26    = getGr( fPA_Lm, "grObs_pT2_2_9" , kFullCross,  kRed  );

    TGraphErrors * grPAObs_Lm6_v24sub = getGr( fPA_Lm, "grObs_V2sub4_6", kOpenCircle, kBlue );
    TGraphErrors * grPAObs_Lm7_v24sub = getGr( fPA_Lm, "grObs_V2sub4_7", kOpenCircle, kBlue );
    TGraphErrors * grPAObs_Lm8_v24sub = getGr( fPA_Lm, "grObs_V2sub4_8", kOpenCircle, kBlue );
    TGraphErrors * grPAObs_Lm9_v24sub = getGr( fPA_Lm, "grObs_V2sub4_9", kOpenCircle, kBlue );

    FixPALm( grPAObs_Lm6_v24 );
    FixPALm( grPAObs_Lm7_v24 );
    FixPALm( grPAObs_Lm8_v24 );
    FixPALm( grPAObs_Lm9_v24 );

    FixPALm( grPAObs_Lm6_v26 );
    FixPALm( grPAObs_Lm7_v26 );
    FixPALm( grPAObs_Lm8_v26 );
    FixPALm( grPAObs_Lm9_v26 );

    FixPALm( grPAObs_Lm6_v24sub );
    FixPALm( grPAObs_Lm7_v24sub );
    FixPALm( grPAObs_Lm8_v24sub );
    FixPALm( grPAObs_Lm9_v24sub );

    // Bkg
    TGraphErrors * grPABkg_Lm6_v24    = getGr( fPA_Lm, "grBkg_pT2_1_6" , kFullSquare, kBlue );
    TGraphErrors * grPABkg_Lm7_v24    = getGr( fPA_Lm, "grBkg_pT2_1_7" , kFullSquare, kBlue );
    TGraphErrors * grPABkg_Lm8_v24    = getGr( fPA_Lm, "grBkg_pT2_1_8" , kFullSquare, kBlue );
    TGraphErrors * grPABkg_Lm9_v24    = getGr( fPA_Lm, "grBkg_pT2_1_9" , kFullSquare, kBlue );

    TGraphErrors * grPABkg_Lm6_v26    = getGr( fPA_Lm, "grBkg_pT2_2_6" , kFullCross,  kRed  );
    TGraphErrors * grPABkg_Lm7_v26    = getGr( fPA_Lm, "grBkg_pT2_2_7" , kFullCross,  kRed  );
    TGraphErrors * grPABkg_Lm8_v26    = getGr( fPA_Lm, "grBkg_pT2_2_8" , kFullCross,  kRed  );
    TGraphErrors * grPABkg_Lm9_v26    = getGr( fPA_Lm, "grBkg_pT2_2_9" , kFullCross,  kRed  );

    TGraphErrors * grPABkg_Lm6_v24sub = getGr( fPA_Lm, "grBkg_V2sub4_6", kOpenCircle, kBlue );
    TGraphErrors * grPABkg_Lm7_v24sub = getGr( fPA_Lm, "grBkg_V2sub4_7", kOpenCircle, kBlue );
    TGraphErrors * grPABkg_Lm8_v24sub = getGr( fPA_Lm, "grBkg_V2sub4_8", kOpenCircle, kBlue );
    TGraphErrors * grPABkg_Lm9_v24sub = getGr( fPA_Lm, "grBkg_V2sub4_9", kOpenCircle, kBlue );


    FixPALm( grPABkg_Lm6_v24 );
    FixPALm( grPABkg_Lm7_v24 );
    FixPALm( grPABkg_Lm8_v24 );
    FixPALm( grPABkg_Lm9_v24 );

    FixPALm( grPABkg_Lm6_v26 );
    FixPALm( grPABkg_Lm7_v26 );
    FixPALm( grPABkg_Lm8_v26 );
    FixPALm( grPABkg_Lm9_v26 );

    FixPALm( grPABkg_Lm6_v24sub );
    FixPALm( grPABkg_Lm7_v24sub );
    FixPALm( grPABkg_Lm8_v24sub );
    FixPALm( grPABkg_Lm9_v24sub );


    // 17-003
    gr_HIN17_003_PbPb_v2sub_Ks->SetMarkerStyle(kOpenSquare);
    gr_HIN17_003_PbPb_v2sub_Ks->SetMarkerColor(kBlue);
    gr_HIN17_003_PbPb_v2sub_Ks->SetLineColor(kBlue);
    gr_sys_HIN17_003_PbPb_v2sub_Ks ->SetFillColor(3003);

    gr_HIN17_003_PbPb_v2sub_Lm->SetMarkerStyle(kOpenCircle);
    gr_HIN17_003_PbPb_v2sub_Lm->SetMarkerColor(kBlack);
    gr_HIN17_003_PbPb_v2sub_Lm->SetLineColor(kBlack);
    gr_sys_HIN17_003_PbPb_v2sub_Lm ->SetFillColor(3005);

    gr_HIN17_003_pPb_v2sub_Ks ->SetMarkerStyle(kOpenSquare);
    gr_HIN17_003_pPb_v2sub_Ks ->SetMarkerColor(kBlue);
    gr_HIN17_003_pPb_v2sub_Ks ->SetLineColor(kBlue);
    gr_sys_HIN17_003_pPb_v2sub_Ks ->SetFillColor(3003);

    gr_HIN17_003_pPb_v2sub_Lm ->SetMarkerStyle(kOpenCircle);
    gr_HIN17_003_pPb_v2sub_Lm ->SetMarkerColor(kBlack);
    gr_HIN17_003_pPb_v2sub_Lm ->SetLineColor(kBlack);
    gr_sys_HIN17_003_pPb_v2sub_Lm ->SetFillColor(3005);

    grLeg = new std::map<TGraph*, std::string> {
        {grPA_Ks6_v24,       "K_{s}^{0} v_{2}^{sig}{4}"},
        {grPA_Ks6_v26,       "K_{s}^{0} v_{2}^{sig}{6}"},
        {grPA_Ks6_v24sub,    "K_{s}^{0} v_{2}^{sig}{4, sub-event}"},
        {grPA_Ks7_v24,       "K_{s}^{0} v_{2}^{sig}{4}"},
        {grPA_Ks7_v26,       "K_{s}^{0} v_{2}^{sig}{6}"},
        {grPA_Ks7_v24sub,    "K_{s}^{0} v_{2}^{sig}{4, sub-event}"},
        {grPA_Ks8_v24,       "K_{s}^{0} v_{2}^{sig}{4}"},
        {grPA_Ks8_v26,       "K_{s}^{0} v_{2}^{sig}{6}"},
        {grPA_Ks8_v24sub,    "K_{s}^{0} v_{2}^{sig}{4, sub-event}"},
        {grPA_Ks9_v24,       "K_{s}^{0} v_{2}^{sig}{4}"},
        {grPA_Ks9_v26,       "K_{s}^{0} v_{2}^{sig}{6}"},
        {grPA_Ks9_v24sub,    "K_{s}^{0} v_{2}^{sig}{4, sub-event}"},

        {grPAObs_Ks6_v24,    "K_{s}^{0} v_{2}^{obs}{4}"},
        {grPAObs_Ks6_v26,    "K_{s}^{0} v_{2}^{obs}{6}"},
        {grPAObs_Ks6_v24sub, "K_{s}^{0} v_{2}^{obs}{4, sub-event}"},
        {grPAObs_Ks7_v24,    "K_{s}^{0} v_{2}^{obs}{4}"},
        {grPAObs_Ks7_v26,    "K_{s}^{0} v_{2}^{obs}{6}"},
        {grPAObs_Ks7_v24sub, "K_{s}^{0} v_{2}^{obs}{4, sub-event}"},
        {grPAObs_Ks8_v24,    "K_{s}^{0} v_{2}^{obs}{4}"},
        {grPAObs_Ks8_v26,    "K_{s}^{0} v_{2}^{obs}{6}"},
        {grPAObs_Ks8_v24sub, "K_{s}^{0} v_{2}^{obs}{4, sub-event}"},
        {grPAObs_Ks9_v24,    "K_{s}^{0} v_{2}^{obs}{4}"},
        {grPAObs_Ks9_v26,    "K_{s}^{0} v_{2}^{obs}{6}"},
        {grPAObs_Ks9_v24sub, "K_{s}^{0} v_{2}^{obs}{4, sub-event}"},

        {grPABkg_Ks6_v24,    "K_{s}^{0} v_{2}^{bkg}{4}"},
        {grPABkg_Ks6_v26,    "K_{s}^{0} v_{2}^{bkg}{6}"},
        {grPABkg_Ks6_v24sub, "K_{s}^{0} v_{2}^{bkg}{4, sub-event}"},
        {grPABkg_Ks7_v24,    "K_{s}^{0} v_{2}^{bkg}{4}"},
        {grPABkg_Ks7_v26,    "K_{s}^{0} v_{2}^{bkg}{6}"},
        {grPABkg_Ks7_v24sub, "K_{s}^{0} v_{2}^{bkg}{4, sub-event}"},
        {grPABkg_Ks8_v24,    "K_{s}^{0} v_{2}^{bkg}{4}"},
        {grPABkg_Ks8_v26,    "K_{s}^{0} v_{2}^{bkg}{6}"},
        {grPABkg_Ks8_v24sub, "K_{s}^{0} v_{2}^{bkg}{4, sub-event}"},
        {grPABkg_Ks9_v24,    "K_{s}^{0} v_{2}^{bkg}{4}"},
        {grPABkg_Ks9_v26,    "K_{s}^{0} v_{2}^{bkg}{6}"},
        {grPABkg_Ks9_v24sub, "K_{s}^{0} v_{2}^{bkg}{4, sub-event}"},

        {grPA_Lm6_v24,       "#Lambda v_{2}^{sig}{4}"},
        {grPA_Lm6_v26,       "#Lambda v_{2}^{sig}{6}"},
        {grPA_Lm6_v24sub,    "#Lambda v_{2}^{sig}{4, sub-event}"},
        {grPA_Lm7_v24,       "#Lambda v_{2}^{sig}{4}"},
        {grPA_Lm7_v26,       "#Lambda v_{2}^{sig}{6}"},
        {grPA_Lm7_v24sub,    "#Lambda v_{2}^{sig}{4, sub-event}"},
        {grPA_Lm8_v24,       "#Lambda v_{2}^{sig}{4}"},
        {grPA_Lm8_v26,       "#Lambda v_{2}^{sig}{6}"},
        {grPA_Lm8_v24sub,    "#Lambda v_{2}^{sig}{4, sub-event}"},
        {grPA_Lm9_v24,       "#Lambda v_{2}^{sig}{4}"},
        {grPA_Lm9_v26,       "#Lambda v_{2}^{sig}{6}"},
        {grPA_Lm9_v24sub,    "#Lambda v_{2}^{sig}{4, sub-event}"},

        {grPAObs_Lm6_v24,    "#Lambda v_{2}^{obs}{4}"},
        {grPAObs_Lm6_v26,    "#Lambda v_{2}^{obs}{6}"},
        {grPAObs_Lm6_v24sub, "#Lambda v_{2}^{obs}{4, sub-event}"},
        {grPAObs_Lm7_v24,    "#Lambda v_{2}^{obs}{4}"},
        {grPAObs_Lm7_v26,    "#Lambda v_{2}^{obs}{6}"},
        {grPAObs_Lm7_v24sub, "#Lambda v_{2}^{obs}{4, sub-event}"},
        {grPAObs_Lm8_v24,    "#Lambda v_{2}^{obs}{4}"},
        {grPAObs_Lm8_v26,    "#Lambda v_{2}^{obs}{6}"},
        {grPAObs_Lm8_v24sub, "#Lambda v_{2}^{obs}{4, sub-event}"},
        {grPAObs_Lm9_v24,    "#Lambda v_{2}^{obs}{4}"},
        {grPAObs_Lm9_v26,    "#Lambda v_{2}^{obs}{6}"},
        {grPAObs_Lm9_v24sub, "#Lambda v_{2}^{obs}{4, sub-event}"},

        {grPABkg_Lm6_v24,    "#Lambda v_{2}^{bkg}{4}"},
        {grPABkg_Lm6_v26,    "#Lambda v_{2}^{bkg}{6}"},
        {grPABkg_Lm6_v24sub, "#Lambda v_{2}^{bkg}{4, sub-event}"},
        {grPABkg_Lm7_v24,    "#Lambda v_{2}^{bkg}{4}"},
        {grPABkg_Lm7_v26,    "#Lambda v_{2}^{bkg}{6}"},
        {grPABkg_Lm7_v24sub, "#Lambda v_{2}^{bkg}{4, sub-event}"},
        {grPABkg_Lm8_v24,    "#Lambda v_{2}^{bkg}{4}"},
        {grPABkg_Lm8_v26,    "#Lambda v_{2}^{bkg}{6}"},
        {grPABkg_Lm8_v24sub, "#Lambda v_{2}^{bkg}{4, sub-event}"},
        {grPABkg_Lm9_v24,    "#Lambda v_{2}^{bkg}{4}"},
        {grPABkg_Lm9_v26,    "#Lambda v_{2}^{bkg}{6}"},
        {grPABkg_Lm9_v24sub, "#Lambda v_{2}^{bkg}{4, sub-event}"},

        {gr_HIN17_003_pPb_v2sub_Ks,  "K_{s}^{0} v_{2}^{sub} HIN-17-003"},
        {gr_HIN17_003_PbPb_v2sub_Ks, "K_{s}^{0} v_{2} HIN-17-003"},
        {gr_HIN17_003_pPb_v2sub_Lm,  "#Lambda v_{2}^{sub} HIN-17-003"},
        {gr_HIN17_003_PbPb_v2sub_Lm, "#Lambda v_{2} HIN-17-003"},

        {gr_ALICE_AA_v2_Ks_30_40,     "K_{s}^{0} ALICE v_{2} 30-40%"},
        {gr_ALICE_AA_v2_Ks_40_50,     "K_{s}^{0} ALICE v_{2} 40-50%"},
        {gr_ALICE_AA_v2_Lm_30_40,     "#Lambda ALICE v_{2} 30-40%"},
        {gr_ALICE_AA_v2_Lm_40_50,     "#Lambda ALICE v_{2} 40-50%"},
    };
    const char* strNoff[] = {
        "", // 0
        "", // 1
        "", // 2
        "", // 3
        "", // 4
        "", // 5
        "120 #leq N_{trk}^{offline} < 150", // 6
        "150 #leq N_{trk}^{offline} < 185", // 7
        "185 #leq N_{trk}^{offline} < 250", // 8
        "N_{trk}^{offline} #geq 250", // 9
    };
    ////
    TCanvas * cPA = MakeCanvas("cPA", "cPA", 800, 600);;
    TH2D * hframePt = new TH2D("hframePt", "", 1, 0, 8.5, 1, -0.05, 0.45);
    InitHist(hframePt, "p_{T}", "v_{2}");

	TLatex latexS;
	latexS.SetTextFont(43);
	latexS.SetTextSize(28);
	latexS.SetTextAlign(13);

    TLegend * legPA = new TLegend(0.16, 0.70, 0.35 , 0.94);
    legPA->SetFillColor(kWhite);
    legPA->SetTextFont(42);
    legPA->SetTextSize(0.05);
    legPA->SetBorderSize(0);

    hframePt->GetYaxis()->SetTitle("v_{2}^{obs}{4}");
    // pPb Obs 6
    hframePt->Draw();
    legPA->Clear();
    setColor(grPAObs_Lm6_v24, kRed);

    drawGr(grPAObs_Ks6_v24, legPA);
    drawGr(grPAObs_Lm6_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[6]);
    cPA->SaveAs("pPb_Obs6.pdf");

    // pPb Obs 7
    hframePt->Draw();
    legPA->Clear();
    setColor(grPAObs_Lm7_v24, kRed);

    drawGr(grPAObs_Ks7_v24, legPA);
    drawGr(grPAObs_Lm7_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[7]);
    cPA->SaveAs("pPb_Obs7.pdf");

    // pPb Obs 8
    hframePt->Draw();
    legPA->Clear();
    setColor(grPAObs_Lm8_v24, kRed);

    drawGr(grPAObs_Ks8_v24, legPA);
    drawGr(grPAObs_Lm8_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[8]);
    cPA->SaveAs("pPb_Obs8.pdf");

    // pPb Obs 9
    hframePt->Draw();
    legPA->Clear();
    setColor(grPAObs_Lm9_v24, kRed);

    drawGr(grPAObs_Ks9_v24, legPA);
    drawGr(grPAObs_Lm9_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[9]);
    cPA->SaveAs("pPb_Obs9.pdf");

    // pPb Obs v24sub 6
    hframePt->GetYaxis()->SetTitle("v_{2}^{obs}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm6_v24sub, kRed);

    drawGr(grPAObs_Ks6_v24sub, legPA);
    drawGr(grPAObs_Lm6_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[6]);
    cPA->SaveAs("pPb_Obs6_v24sub.pdf");

    // pPb Obs v24sub 6
    hframePt->GetYaxis()->SetTitle("v_{2}^{obs}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm6_v24sub, kRed);

    drawGr(grPAObs_Ks6_v24sub, legPA);
    drawGr(grPAObs_Lm6_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[6]);
    cPA->SaveAs("pPb_Obs6_v24sub.pdf");

    // pPb Obs v24sub 7
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm7_v24sub, kRed);
    drawGr(grPAObs_Ks7_v24sub, legPA);
    drawGr(grPAObs_Lm7_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[7]);
    cPA->SaveAs("pPb_Obs7_v24sub.pdf");

    // pPb Obs v24sub 8
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm8_v24sub, kRed);
    drawGr(grPAObs_Ks8_v24sub, legPA);
    drawGr(grPAObs_Lm8_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[8]);
    cPA->SaveAs("pPb_Obs8_v24sub.pdf");

    // pPb Obs v24sub 9
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm9_v24sub, kRed);
    drawGr(grPAObs_Ks9_v24sub, legPA);
    drawGr(grPAObs_Lm9_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[9]);
    cPA->SaveAs("pPb_Obs9_v24sub.pdf");

    // pPb Obs v24 6
    hframePt->GetYaxis()->SetTitle("v_{2}^{bkg}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm6_v24sub, kRed);

    drawGr(grPAObs_Ks6_v24sub, legPA);
    drawGr(grPAObs_Lm6_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[6]);
    cPA->SaveAs("pPb_Obs6_v24sub.pdf");


    // pPb Bkg 6
    hframePt->GetYaxis()->SetTitle("v_{2}^{bkg}{4}");
    hframePt->Draw();
    legPA->Clear();
    setColor(grPABkg_Lm6_v24, kRed);

    drawGr(grPABkg_Ks6_v24, legPA);
    drawGr(grPABkg_Lm6_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[6]);
    cPA->SaveAs("pPb_Bkg6.pdf");

    // pPb Bkg 7
    hframePt->Draw();
    legPA->Clear();
    setColor(grPABkg_Lm7_v24, kRed);

    drawGr(grPABkg_Ks7_v24, legPA);
    drawGr(grPABkg_Lm7_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[7]);
    cPA->SaveAs("pPb_Bkg7.pdf");

    // pPb Bkg 8
    hframePt->Draw();
    legPA->Clear();
    setColor(grPABkg_Lm8_v24, kRed);

    drawGr(grPABkg_Ks8_v24, legPA);
    drawGr(grPABkg_Lm8_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[8]);
    cPA->SaveAs("pPb_Bkg8.pdf");

    // pPb Bkg 9
    hframePt->Draw();
    legPA->Clear();
    setColor(grPABkg_Lm9_v24, kRed);

    drawGr(grPABkg_Ks9_v24, legPA);
    drawGr(grPABkg_Lm9_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[9]);
    cPA->SaveAs("pPb_Bkg9.pdf");

    // pPb Bkg v24sub 6
    hframePt->GetYaxis()->SetTitle("v_{2}^{bkg}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPABkg_Lm6_v24sub, kRed);

    drawGr(grPABkg_Ks6_v24sub, legPA);
    drawGr(grPABkg_Lm6_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[6]);
    cPA->SaveAs("pPb_Bkg6_v24sub.pdf");

    // pPb Bkg v24sub 7
    hframePt->GetYaxis()->SetTitle("v_{2}^{bkg}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPABkg_Lm7_v24sub, kRed);

    drawGr(grPABkg_Ks7_v24sub, legPA);
    drawGr(grPABkg_Lm7_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[7]);
    cPA->SaveAs("pPb_Bkg7_v24sub.pdf");

    // pPb Bkg v24sub 8
    hframePt->GetYaxis()->SetTitle("v_{2}^{bkg}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPABkg_Lm8_v24sub, kRed);

    drawGr(grPABkg_Ks8_v24sub, legPA);
    drawGr(grPABkg_Lm8_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[8]);
    cPA->SaveAs("pPb_Bkg8_v24sub.pdf");

    // pPb Bkg v24sub 9
    hframePt->GetYaxis()->SetTitle("v_{2}^{bkg}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPABkg_Lm9_v24sub, kRed);

    drawGr(grPABkg_Ks9_v24sub, legPA);
    drawGr(grPABkg_Lm9_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[9]);
    cPA->SaveAs("pPb_Bkg9_v24sub.pdf");

    // pPb Ks 6
    hframePt->GetYaxis()->SetTitle("v_{2}{4}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Ks6_v24, kRed);
    setColor(grPABkg_Ks6_v24, kBlue);
    drawGr(grPAObs_Ks6_v24, legPA);
    drawGr(grPABkg_Ks6_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[6]);
    cPA->SaveAs("pPb_Ks6_v24.pdf");

    // pPb Ks 7
    hframePt->GetYaxis()->SetTitle("v_{2}{4}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Ks7_v24, kRed);
    setColor(grPABkg_Ks7_v24, kBlue);
    drawGr(grPAObs_Ks7_v24, legPA);
    drawGr(grPABkg_Ks7_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[7]);
    cPA->SaveAs("pPb_Ks7_v24.pdf");

    // pPb Ks 8
    hframePt->GetYaxis()->SetTitle("v_{2}{4}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Ks8_v24, kRed);
    setColor(grPABkg_Ks8_v24, kBlue);
    drawGr(grPAObs_Ks8_v24, legPA);
    drawGr(grPABkg_Ks8_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[8]);
    cPA->SaveAs("pPb_Ks8_v24.pdf");

    // pPb Ks 9
    hframePt->GetYaxis()->SetTitle("v_{2}{4}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Ks9_v24, kRed);
    setColor(grPABkg_Ks9_v24, kBlue);
    drawGr(grPAObs_Ks9_v24, legPA);
    drawGr(grPABkg_Ks9_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[9]);
    cPA->SaveAs("pPb_Ks9_v24.pdf");

    // pPb Ks sub 6
    hframePt->GetYaxis()->SetTitle("v_{2}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Ks6_v24sub, kRed);
    setColor(grPABkg_Ks6_v24sub, kBlue);
    drawGr(grPAObs_Ks6_v24sub, legPA);
    drawGr(grPABkg_Ks6_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[6]);
    cPA->SaveAs("pPb_Ks6_v24sub.pdf");

    // pPb Ks sub 7
    hframePt->GetYaxis()->SetTitle("v_{2}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Ks7_v24sub, kRed);
    setColor(grPABkg_Ks7_v24sub, kBlue);
    drawGr(grPAObs_Ks7_v24sub, legPA);
    drawGr(grPABkg_Ks7_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[7]);
    cPA->SaveAs("pPb_Ks7_v24sub.pdf");

    // pPb Ks sub 8
    hframePt->GetYaxis()->SetTitle("v_{2}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Ks8_v24sub, kRed);
    setColor(grPABkg_Ks8_v24sub, kBlue);
    drawGr(grPAObs_Ks8_v24sub, legPA);
    drawGr(grPABkg_Ks8_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[8]);
    cPA->SaveAs("pPb_Ks8_v24sub.pdf");

    // pPb Ks sub 9
    hframePt->GetYaxis()->SetTitle("v_{2}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Ks9_v24sub, kRed);
    setColor(grPABkg_Ks9_v24sub, kBlue);
    drawGr(grPAObs_Ks9_v24sub, legPA);
    drawGr(grPABkg_Ks9_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[9]);
    cPA->SaveAs("pPb_Ks9_v24sub.pdf");

    // pPb Lm 6
    hframePt->GetYaxis()->SetTitle("v_{2}{4}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm6_v24, kRed);
    setColor(grPABkg_Lm6_v24, kBlue);
    drawGr(grPAObs_Lm6_v24, legPA);
    drawGr(grPABkg_Lm6_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[6]);
    cPA->SaveAs("pPb_Lm6_v24.pdf");

    // pPb Lm 7
    hframePt->GetYaxis()->SetTitle("v_{2}{4}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm7_v24, kRed);
    setColor(grPABkg_Lm7_v24, kBlue);
    drawGr(grPAObs_Lm7_v24, legPA);
    drawGr(grPABkg_Lm7_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[7]);
    cPA->SaveAs("pPb_Lm7_v24.pdf");

    // pPb Lm 8
    hframePt->GetYaxis()->SetTitle("v_{2}{4}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm8_v24, kRed);
    setColor(grPABkg_Lm8_v24, kBlue);
    drawGr(grPAObs_Lm8_v24, legPA);
    drawGr(grPABkg_Lm8_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[8]);
    cPA->SaveAs("pPb_Lm8_v24.pdf");

    // pPb Lm 9
    hframePt->GetYaxis()->SetTitle("v_{2}{4}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm9_v24, kRed);
    setColor(grPABkg_Lm9_v24, kBlue);
    drawGr(grPAObs_Lm9_v24, legPA);
    drawGr(grPABkg_Lm9_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[9]);
    cPA->SaveAs("pPb_Lm9_v24.pdf");

    // pPb Lm sub 6
    hframePt->GetYaxis()->SetTitle("v_{2}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm6_v24sub, kRed);
    setColor(grPABkg_Lm6_v24sub, kBlue);
    drawGr(grPAObs_Lm6_v24sub, legPA);
    drawGr(grPABkg_Lm6_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[6]);
    cPA->SaveAs("pPb_Lm6_v24sub.pdf");

    // pPb Lm sub 7
    hframePt->GetYaxis()->SetTitle("v_{2}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm7_v24sub, kRed);
    setColor(grPABkg_Lm7_v24sub, kBlue);
    drawGr(grPAObs_Lm7_v24sub, legPA);
    drawGr(grPABkg_Lm7_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[7]);
    cPA->SaveAs("pPb_Lm7_v24sub.pdf");

    // pPb Lm sub 8
    hframePt->GetYaxis()->SetTitle("v_{2}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm8_v24sub, kRed);
    setColor(grPABkg_Lm8_v24sub, kBlue);
    drawGr(grPAObs_Lm8_v24sub, legPA);
    drawGr(grPABkg_Lm8_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[8]);
    cPA->SaveAs("pPb_Lm8_v24sub.pdf");

    // pPb Lm sub 9
    hframePt->GetYaxis()->SetTitle("v_{2}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm9_v24sub, kRed);
    setColor(grPABkg_Lm9_v24sub, kBlue);
    drawGr(grPAObs_Lm9_v24sub, legPA);
    drawGr(grPABkg_Lm9_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[9]);
    cPA->SaveAs("pPb_Lm9_v24sub.pdf");

    // pPb sig 6
    hframePt->GetYaxis()->SetTitle("v_{2}^{sig}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPA_Lm6_v24, kRed);
    drawGr(grPA_Ks6_v24, legPA);
    drawGr(grPA_Lm6_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[6]);
    cPA->SaveAs("pPb_Sig6.pdf");

    // pPb sig 7
    hframePt->GetYaxis()->SetTitle("v_{2}^{sig}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPA_Lm7_v24, kRed);
    drawGr(grPA_Ks7_v24, legPA);
    drawGr(grPA_Lm7_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[7]);
    cPA->SaveAs("pPb_Sig7.pdf");

    // pPb sig 8
    hframePt->GetYaxis()->SetTitle("v_{2}^{sig}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPA_Lm8_v24, kRed);
    drawGr(grPA_Ks8_v24, legPA);
    drawGr(grPA_Lm8_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[8]);
    cPA->SaveAs("pPb_Sig8.pdf");

    // pPb sig 9
    hframePt->GetYaxis()->SetTitle("v_{2}^{sig}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPA_Lm9_v24, kRed);
    drawGr(grPA_Ks9_v24, legPA);
    drawGr(grPA_Lm9_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[9]);
    cPA->SaveAs("pPb_Sig9.pdf");




    //////////////////////////////////////// manual plot final results
    // pPb Ks 8
    TCanvas * cResult= MakeCanvas("cResult", "cResult", 800, 600);;
    TH2D * hframePtResult = new TH2D("hframePtResult", "", 1, 0, 8.5, 1, -0.05, 0.38);
    InitHist(hframePtResult, "p_{T}", "v_{2}");

    hframePtResult->Draw();
    setColor(grPA_Ks8_v26, kRed);

    TGraphErrors * grPA_Ks8_v24subsys = getGrSys(grPA_Ks8_v24sub, sys_pPb_Ks, 3003);
    TGraphErrors * grPA_Ks8_v24sys    = getGrSys(grPA_Ks8_v24,    sys_pPb_Ks, 3003);
    TGraphErrors * grPA_Ks8_v26sys    = getGrSys(grPA_Ks8_v26,    sys_pPb_Ks, 3001);

    gr_sys_HIN17_003_pPb_v2sub_Ks->SetFillColor(3005);
    setColor(gr_HIN17_003_pPb_v2sub_Ks, kBlack);

    gr_sys_HIN17_003_pPb_v2sub_Ks->Draw("[]2");
    grPA_Ks8_v24subsys->Draw("[]2");
    grPA_Ks8_v24sys->Draw("[]2");
    grPA_Ks8_v26sys->Draw("[]2");

    gr_HIN17_003_pPb_v2sub_Ks->Draw("psame");
    grPA_Ks8_v24sub->Draw("psame");
    grPA_Ks8_v24->Draw("psame");
    grPA_Ks8_v26->Draw("psame");

    TLegend * leg1 = new TLegend(0.16, 0.70, 0.35 , 0.94);
    leg1->SetFillColor(kWhite);
    leg1->SetTextFont(42);
    leg1->SetTextSize(0.04);
    leg1->SetBorderSize(0);

    leg1->AddEntry(gr_HIN17_003_pPb_v2sub_Ks, "K_{s} v_{2}^{sub}", "p");
    leg1->AddEntry(grPA_Ks8_v24, "K_{s} v_{2}{4}", "p");
    leg1->AddEntry(grPA_Ks8_v24sub, "K_{s} v_{2}{4,sub-event}", "p");
    leg1->AddEntry(grPA_Ks8_v26, "K_{s} v_{2}{6}", "p");
    leg1->Draw("same");

	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[8]);
    cResult->SaveAs("F_pPb_Ks8.pdf");

    // pPb Ks 6
    hframePtResult->Draw();
    leg1->Clear();
    setColor(grPA_Ks6_v26, kRed);

    TGraphErrors * grPA_Ks6_v24subsys = getGrSys(grPA_Ks6_v24sub, sys_pPb_Ks, 3003);
    TGraphErrors * grPA_Ks6_v24sys    = getGrSys(grPA_Ks6_v24,    sys_pPb_Ks, 3003);
    TGraphErrors * grPA_Ks6_v26sys    = getGrSys(grPA_Ks6_v26,    sys_pPb_Ks, 3001);

    grPA_Ks6_v24subsys->Draw("[]2");
    grPA_Ks6_v24sys->Draw("[]2");
    grPA_Ks6_v26sys->Draw("[]2");

    grPA_Ks6_v24sub->Draw("psame");
    grPA_Ks6_v24->Draw("psame");
    grPA_Ks6_v26->Draw("psame");

    leg1->AddEntry(grPA_Ks6_v24, "K_{s} v_{2}{4}", "p");
    leg1->AddEntry(grPA_Ks6_v24sub, "K_{s} v_{2}{4,sub-event}", "p");
    leg1->AddEntry(grPA_Ks6_v26, "K_{s} v_{2}{6}", "p");
    leg1->Draw("same");

	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[6]);
    cResult->SaveAs("F_pPb_Ks6.pdf");

    // pPb Ks 7
    hframePtResult->Draw();
    leg1->Clear();
    setColor(grPA_Ks7_v26, kRed);

    TGraphErrors * grPA_Ks7_v24subsys = getGrSys(grPA_Ks7_v24sub, sys_pPb_Ks, 3003);
    TGraphErrors * grPA_Ks7_v24sys    = getGrSys(grPA_Ks7_v24,    sys_pPb_Ks, 3003);
    TGraphErrors * grPA_Ks7_v26sys    = getGrSys(grPA_Ks7_v26,    sys_pPb_Ks, 3001);

    grPA_Ks7_v24subsys->Draw("[]2");
    grPA_Ks7_v24sys->Draw("[]2");
    grPA_Ks7_v26sys->Draw("[]2");

    grPA_Ks7_v24sub->Draw("psame");
    grPA_Ks7_v24->Draw("psame");
    grPA_Ks7_v26->Draw("psame");

    leg1->AddEntry(grPA_Ks7_v24, "K_{s} v_{2}{4}", "p");
    leg1->AddEntry(grPA_Ks7_v24sub, "K_{s} v_{2}{4,sub-event}", "p");
    leg1->AddEntry(grPA_Ks7_v26, "K_{s} v_{2}{6}", "p");
    leg1->Draw("same");

	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[7]);
    cResult->SaveAs("F_pPb_Ks7.pdf");

    // pPb Ks 9
    hframePtResult->Draw();
    leg1->Clear();
    setColor(grPA_Ks9_v26, kRed);

    TGraphErrors * grPA_Ks9_v24subsys = getGrSys(grPA_Ks9_v24sub, sys_pPb_Ks, 3003);
    TGraphErrors * grPA_Ks9_v24sys    = getGrSys(grPA_Ks9_v24,    sys_pPb_Ks, 3003);
    TGraphErrors * grPA_Ks9_v26sys    = getGrSys(grPA_Ks9_v26,    sys_pPb_Ks, 3001);

    grPA_Ks9_v24subsys->Draw("[]2");
    grPA_Ks9_v24sys->Draw("[]2");
    grPA_Ks9_v26sys->Draw("[]2");

    grPA_Ks9_v24sub->Draw("psame");
    grPA_Ks9_v24->Draw("psame");
    grPA_Ks9_v26->Draw("psame");

    leg1->AddEntry(grPA_Ks9_v24, "K_{s} v_{2}{4}", "p");
    leg1->AddEntry(grPA_Ks9_v24sub, "K_{s} v_{2}{4,sub-event}", "p");
    leg1->AddEntry(grPA_Ks9_v26, "K_{s} v_{2}{6}", "p");
    leg1->Draw("same");

	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[9]);
    cResult->SaveAs("F_pPb_Ks9.pdf");

    // pPb Lm 8
    leg1->Clear();
    hframePtResult->Draw();
    setColor(grPA_Lm8_v24, kBlue);
    setColor(grPA_Lm8_v26, kRed);

    TGraphErrors * grPA_Lm8_v24subsys = getGrSys(grPA_Lm8_v24sub, sys_pPb_Lm, 3003);
    TGraphErrors * grPA_Lm8_v24sys    = getGrSys(grPA_Lm8_v24,    sys_pPb_Lm, 3003);
    TGraphErrors * grPA_Lm8_v26sys    = getGrSys(grPA_Lm8_v26,    sys_pPb_Lm, 3001);

    gr_sys_HIN17_003_pPb_v2sub_Lm->Draw("[]2");
    grPA_Lm8_v24subsys->Draw("[]2");
    grPA_Lm8_v24sys->Draw("[]2");
    grPA_Lm8_v26sys->Draw("[]2");

    setColor(grPA_Lm8_v24sub, kBlue);

    gr_HIN17_003_pPb_v2sub_Lm->Draw("psame");
    grPA_Lm8_v24sub->Draw("psame");
    grPA_Lm8_v24->Draw("psame");
    grPA_Lm8_v26->Draw("psame");

    leg1->AddEntry(gr_HIN17_003_pPb_v2sub_Lm, "#Lambda v_{2}^{sub}", "p");
    leg1->AddEntry(grPA_Lm8_v24, "#Lambda v_{2}{4}", "p");
    leg1->AddEntry(grPA_Lm8_v24sub, "#Lambda v_{2}{4, sub-event}", "p");
    leg1->AddEntry(grPA_Lm8_v26, "#Lambda v_{2}{6}", "p");
    leg1->Draw("same");

	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[8]);
    cResult->SaveAs("F_pPb_Lm8.pdf");

    // pPb Lm 6
    leg1->Clear();
    hframePtResult->Draw();
    setColor(grPA_Lm6_v24, kBlue);
    setColor(grPA_Lm6_v26, kRed);

    TGraphErrors * grPA_Lm6_v24subsys = getGrSys(grPA_Lm6_v24sub, sys_pPb_Lm, 3003);
    TGraphErrors * grPA_Lm6_v24sys    = getGrSys(grPA_Lm6_v24,    sys_pPb_Lm, 3003);
    TGraphErrors * grPA_Lm6_v26sys    = getGrSys(grPA_Lm6_v26,    sys_pPb_Lm, 3001);

    grPA_Lm6_v24subsys->Draw("[]2");
    grPA_Lm6_v24sys->Draw("[]2");
    grPA_Lm6_v26sys->Draw("[]2");

    setColor(grPA_Lm6_v24sub, kBlue);

    grPA_Lm6_v24sub->Draw("psame");
    grPA_Lm6_v24->Draw("psame");
    grPA_Lm6_v26->Draw("psame");

    leg1->AddEntry(grPA_Lm6_v24, "#Lambda v_{2}{4}", "p");
    leg1->AddEntry(grPA_Lm6_v24sub, "#Lambda v_{2}{4, sub-event}", "p");
    leg1->AddEntry(grPA_Lm6_v26, "#Lambda v_{2}{6}", "p");
    leg1->Draw("same");

	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[6]);
    cResult->SaveAs("F_pPb_Lm6.pdf");

    // pPb Lm 7
    leg1->Clear();
    hframePtResult->Draw();
    setColor(grPA_Lm7_v24, kBlue);
    setColor(grPA_Lm7_v26, kRed);

    TGraphErrors * grPA_Lm7_v24subsys = getGrSys(grPA_Lm7_v24sub, sys_pPb_Lm, 3003);
    TGraphErrors * grPA_Lm7_v24sys    = getGrSys(grPA_Lm7_v24,    sys_pPb_Lm, 3003);
    TGraphErrors * grPA_Lm7_v26sys    = getGrSys(grPA_Lm7_v26,    sys_pPb_Lm, 3001);

    grPA_Lm7_v24subsys->Draw("[]2");
    grPA_Lm7_v24sys->Draw("[]2");
    grPA_Lm7_v26sys->Draw("[]2");

    setColor(grPA_Lm6_v24sub, kBlue);

    grPA_Lm7_v24sub->Draw("psame");
    grPA_Lm7_v24->Draw("psame");
    grPA_Lm7_v26->Draw("psame");

    leg1->AddEntry(grPA_Lm7_v24, "#Lambda v_{2}{4}", "p");
    leg1->AddEntry(grPA_Lm7_v24sub, "#Lambda v_{2}{4, sub-event}", "p");
    leg1->AddEntry(grPA_Lm7_v26, "#Lambda v_{2}{6}", "p");
    leg1->Draw("same");

	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[7]);
    cResult->SaveAs("F_pPb_Lm7.pdf");

    // pPb Lm 9
    leg1->Clear();
    hframePtResult->Draw();
    setColor(grPA_Lm9_v24, kBlue);
    setColor(grPA_Lm9_v26, kRed);

    TGraphErrors * grPA_Lm9_v24subsys = getGrSys(grPA_Lm9_v24sub, sys_pPb_Lm, 3003);
    TGraphErrors * grPA_Lm9_v24sys    = getGrSys(grPA_Lm9_v24,    sys_pPb_Lm, 3003);
    TGraphErrors * grPA_Lm9_v26sys    = getGrSys(grPA_Lm9_v26,    sys_pPb_Lm, 3001);

    grPA_Lm9_v24subsys->Draw("[]2");
    grPA_Lm9_v24sys->Draw("[]2");
    grPA_Lm9_v26sys->Draw("[]2");

    setColor(grPA_Lm9_v24sub, kBlue);

    grPA_Lm9_v24sub->Draw("psame");
    grPA_Lm9_v24->Draw("psame");
    grPA_Lm9_v26->Draw("psame");

    leg1->AddEntry(grPA_Lm9_v24, "#Lambda v_{2}{4}", "p");
    leg1->AddEntry(grPA_Lm9_v24sub, "#Lambda v_{2}{4, sub-event}", "p");
    leg1->AddEntry(grPA_Lm9_v26, "#Lambda v_{2}{6}", "p");
    leg1->Draw("same");

	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[9]);
    cResult->SaveAs("F_pPb_Lm9.pdf");

    // pPb Ks v24/v22
    leg1->Clear();

    TH2D * hframeRatioResult = new TH2D("hframeRatioResult", "", 1, 0, 8.5, 1, -0.05, 1.9);
    InitHist(hframeRatioResult, "p_{T}", "Ratio");
    hframeRatioResult->Draw();

    TGraphErrors* grPA_Ks8_ratio = getRatio( grPA_Ks8_v24, gr_HIN17_003_pPb_v2sub_Ks);
    TGraphErrors* grPA_Ks8_ratio_sys = getGrSys( grPA_Ks8_ratio, sys_pPb_Ks, 3003 );

    TGraphErrors* grPA_Ks8_sub_ratio = getRatio( grPA_Ks8_v24sub, gr_HIN17_003_pPb_v2sub_Ks);
    setColor(grPA_Ks8_sub_ratio, kRed);
    TGraphErrors* grPA_Ks8_sub_ratio_sys = getGrSys( grPA_Ks8_sub_ratio, sys_pPb_Ks, 3001 );

    grPA_Ks8_ratio_sys->Draw("[]2");
    grPA_Ks8_sub_ratio_sys->Draw("[]2");
    grPA_Ks8_ratio->Draw("psame");
    grPA_Ks8_sub_ratio->Draw("psame");

    leg1->AddEntry(grPA_Ks8_ratio, "K_{s}^{0} v_{2}{4}/v_{2}{|#Delta#eta|>2}", "p");
    leg1->AddEntry(grPA_Ks8_sub_ratio, "K_{s}^{0} v_{2}{4, sub-event}/v_{2}{|#Delta#eta|>2}", "p");
    leg1->Draw("same");

    cResult->SaveAs("F_pPb_Ks8_ratio.pdf");

    // pPb Lm ratio v24/v22
    leg1->Clear();
    hframeRatioResult->Draw();

    TGraphErrors* grPA_Lm8_ratio = getRatio( grPA_Lm8_v24, gr_HIN17_003_pPb_v2sub_Lm);
    TGraphErrors* grPA_Lm8_ratio_sys = getGrSys( grPA_Lm8_ratio, sys_pPb_Lm, 3003 );

    TGraphErrors* grPA_Lm8_sub_ratio = getRatio( grPA_Lm8_v24sub, gr_HIN17_003_pPb_v2sub_Lm);
    setColor(grPA_Lm8_sub_ratio, kRed);
    TGraphErrors* grPA_Lm8_sub_ratio_sys = getGrSys( grPA_Lm8_sub_ratio, sys_pPb_Lm, 3001 );

    grPA_Lm8_ratio_sys->Draw("[]2");
    grPA_Lm8_sub_ratio_sys->Draw("[]2");

    grPA_Lm8_ratio->Draw("psame");
    grPA_Lm8_sub_ratio->Draw("psame");

    leg1->AddEntry(grPA_Lm8_ratio, "#Lambda v_{2}{4}/v_{2}{|#Delta#eta|>2}", "p");
    leg1->AddEntry(grPA_Lm8_sub_ratio, "#Lambda v_{2}{4, sub-event}/v_{2}{|#Delta#eta|>2}", "p");
    leg1->Draw("same");

    cResult->SaveAs("F_pPb_Lm8_ratio.pdf");
}

void FixPAKs(TGraphErrors * gr)
{
    for ( int i = 0; i < 13; i++ ) {
        gr->GetX()[i] = pT_pPb_Ks[i];
    }
}




void FixPALm(TGraphErrors * gr)
{
    gr->RemovePoint(0);
    gr->RemovePoint(0);
    gr->RemovePoint(0);
    for ( int i = 0; i < 10; i++ ) {
        gr->GetX()[i] = pT_pPb_Lm[i];
    }
}


void drawGr(TGraph* gr, TLegend* leg)
{
    gr->Draw("psame");
//    cout << (*grLeg)[gr] << endl;
    leg->AddEntry(gr, (*grLeg)[gr].c_str() , "p");
}

void setColor(TGraph* gr, int c)
{
    gr->SetMarkerColor(c);
    gr->SetLineColor(c);
}


TGraphErrors * getGrSys(TGraphErrors * gr, double sys, int color)
{
    TGraphErrors * ret = (TGraphErrors*) gr->Clone();

    for ( int i = 0; i < gr->GetN(); i++ ) {
        ret->GetEX()[i] = 0.15;
        ret->GetEY()[i] = sys * gr->GetY()[i];
    }

    ret->SetFillColor(color);
    return ret;
}


TGraphErrors * getRatio(TGraphErrors* v24, TGraphErrors* v22)
{
    TGraphErrors * ret = (TGraphErrors*) v24->Clone();

    for ( int i = 0; i < v24->GetN(); i++ ) {
        ret->GetY()[i] = v24->GetY()[i] / v22->GetY()[i];

        ret->GetEY()[i] = sqrt( v24->GetEY()[i]*v24->GetEY()[i]/v24->GetY()[i]/v24->GetY()[i] + v22->GetEY()[i]*v22->GetEY()[i]/v22->GetY()[i]/v22->GetY()[i] ) * ret->GetY()[i];
    }

    return ret;
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
