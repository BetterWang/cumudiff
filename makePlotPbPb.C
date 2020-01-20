#include "../../style.h"

double sys_PbPb_Ks = 0.06;
double sys_PbPb_Lm = 0.06;

void FixAAKs(TGraphErrors*);
void FixAALm(TGraphErrors*);


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

void makePlotPbPb()
{
    SetStyle();

    TFile * fKs = new TFile("PbPb2018_Ks_corrected.root");
    TFile * fLm = new TFile("PbPb2018_Lm_corrected.root");

    // PA Ks Sig
    TGraphErrors * grPA_Ks0_v24    = getGr( fKs, "grSig_pT2_1_0" , kFullSquare, kBlue );
    TGraphErrors * grPA_Ks1_v24    = getGr( fKs, "grSig_pT2_1_1" , kFullSquare, kBlue );
    TGraphErrors * grPA_Ks2_v24    = getGr( fKs, "grSig_pT2_1_2" , kFullSquare, kBlue );
    TGraphErrors * grPA_Ks3_v24    = getGr( fKs, "grSig_pT2_1_3" , kFullSquare, kBlue );

    TGraphErrors * grPA_Ks0_v26    = getGr( fKs, "grSig_pT2_2_0" , kFullCross,  kRed  );
    TGraphErrors * grPA_Ks1_v26    = getGr( fKs, "grSig_pT2_2_1" , kFullCross,  kRed  );
    TGraphErrors * grPA_Ks2_v26    = getGr( fKs, "grSig_pT2_2_2" , kFullCross,  kRed  );
    TGraphErrors * grPA_Ks3_v26    = getGr( fKs, "grSig_pT2_2_3" , kFullCross,  kRed  );

    TGraphErrors * grPA_Ks0_v24sub = getGr( fKs, "grSig_V2sub4_0", kOpenCircle, kBlue );
    TGraphErrors * grPA_Ks1_v24sub = getGr( fKs, "grSig_V2sub4_1", kOpenCircle, kBlue );
    TGraphErrors * grPA_Ks2_v24sub = getGr( fKs, "grSig_V2sub4_2", kOpenCircle, kBlue );
    TGraphErrors * grPA_Ks3_v24sub = getGr( fKs, "grSig_V2sub4_3", kOpenCircle, kBlue );


    FixAAKs( grPA_Ks0_v24 );
    FixAAKs( grPA_Ks1_v24 );
    FixAAKs( grPA_Ks2_v24 );
    FixAAKs( grPA_Ks3_v24 );

    FixAAKs( grPA_Ks0_v26 );
    FixAAKs( grPA_Ks1_v26 );
    FixAAKs( grPA_Ks2_v26 );
    FixAAKs( grPA_Ks3_v26 );

    FixAAKs( grPA_Ks0_v24sub );
    FixAAKs( grPA_Ks1_v24sub );
    FixAAKs( grPA_Ks2_v24sub );
    FixAAKs( grPA_Ks3_v24sub );

    // Obs
    TGraphErrors * grPAObs_Ks0_v24    = getGr( fKs, "grObs_pT2_1_0" , kFullSquare, kBlue );
    TGraphErrors * grPAObs_Ks1_v24    = getGr( fKs, "grObs_pT2_1_1" , kFullSquare, kBlue );
    TGraphErrors * grPAObs_Ks2_v24    = getGr( fKs, "grObs_pT2_1_2" , kFullSquare, kBlue );
    TGraphErrors * grPAObs_Ks3_v24    = getGr( fKs, "grObs_pT2_1_3" , kFullSquare, kBlue );

    TGraphErrors * grPAObs_Ks0_v26    = getGr( fKs, "grObs_pT2_2_0" , kFullCross,  kRed  );
    TGraphErrors * grPAObs_Ks1_v26    = getGr( fKs, "grObs_pT2_2_1" , kFullCross,  kRed  );
    TGraphErrors * grPAObs_Ks2_v26    = getGr( fKs, "grObs_pT2_2_2" , kFullCross,  kRed  );
    TGraphErrors * grPAObs_Ks3_v26    = getGr( fKs, "grObs_pT2_2_3" , kFullCross,  kRed  );

    TGraphErrors * grPAObs_Ks0_v24sub = getGr( fKs, "grObs_V2sub4_0", kOpenCircle, kBlue );
    TGraphErrors * grPAObs_Ks1_v24sub = getGr( fKs, "grObs_V2sub4_1", kOpenCircle, kBlue );
    TGraphErrors * grPAObs_Ks2_v24sub = getGr( fKs, "grObs_V2sub4_2", kOpenCircle, kBlue );
    TGraphErrors * grPAObs_Ks3_v24sub = getGr( fKs, "grObs_V2sub4_3", kOpenCircle, kBlue );

    FixAAKs( grPAObs_Ks0_v24 );
    FixAAKs( grPAObs_Ks1_v24 );
    FixAAKs( grPAObs_Ks2_v24 );
    FixAAKs( grPAObs_Ks3_v24 );

    FixAAKs( grPAObs_Ks0_v26 );
    FixAAKs( grPAObs_Ks1_v26 );
    FixAAKs( grPAObs_Ks2_v26 );
    FixAAKs( grPAObs_Ks3_v26 );

    FixAAKs( grPAObs_Ks0_v24sub );
    FixAAKs( grPAObs_Ks1_v24sub );
    FixAAKs( grPAObs_Ks2_v24sub );
    FixAAKs( grPAObs_Ks3_v24sub );

    // Bkg
    TGraphErrors * grPABkg_Ks0_v24    = getGr( fKs, "grBkg_pT2_1_0" , kFullSquare, kBlue );
    TGraphErrors * grPABkg_Ks1_v24    = getGr( fKs, "grBkg_pT2_1_1" , kFullSquare, kBlue );
    TGraphErrors * grPABkg_Ks2_v24    = getGr( fKs, "grBkg_pT2_1_2" , kFullSquare, kBlue );
    TGraphErrors * grPABkg_Ks3_v24    = getGr( fKs, "grBkg_pT2_1_3" , kFullSquare, kBlue );

    TGraphErrors * grPABkg_Ks0_v26    = getGr( fKs, "grBkg_pT2_2_0" , kFullCross,  kRed  );
    TGraphErrors * grPABkg_Ks1_v26    = getGr( fKs, "grBkg_pT2_2_1" , kFullCross,  kRed  );
    TGraphErrors * grPABkg_Ks2_v26    = getGr( fKs, "grBkg_pT2_2_2" , kFullCross,  kRed  );
    TGraphErrors * grPABkg_Ks3_v26    = getGr( fKs, "grBkg_pT2_2_3" , kFullCross,  kRed  );

    TGraphErrors * grPABkg_Ks0_v24sub = getGr( fKs, "grBkg_V2sub4_0", kOpenCircle, kBlue );
    TGraphErrors * grPABkg_Ks1_v24sub = getGr( fKs, "grBkg_V2sub4_1", kOpenCircle, kBlue );
    TGraphErrors * grPABkg_Ks2_v24sub = getGr( fKs, "grBkg_V2sub4_2", kOpenCircle, kBlue );
    TGraphErrors * grPABkg_Ks3_v24sub = getGr( fKs, "grBkg_V2sub4_3", kOpenCircle, kBlue );


    FixAAKs( grPABkg_Ks0_v24 );
    FixAAKs( grPABkg_Ks1_v24 );
    FixAAKs( grPABkg_Ks2_v24 );
    FixAAKs( grPABkg_Ks3_v24 );

    FixAAKs( grPABkg_Ks0_v26 );
    FixAAKs( grPABkg_Ks1_v26 );
    FixAAKs( grPABkg_Ks2_v26 );
    FixAAKs( grPABkg_Ks3_v26 );

    FixAAKs( grPABkg_Ks0_v24sub );
    FixAAKs( grPABkg_Ks1_v24sub );
    FixAAKs( grPABkg_Ks2_v24sub );
    FixAAKs( grPABkg_Ks3_v24sub );



    // PA Lm Sig
    TGraphErrors * grPA_Lm0_v24    = getGr( fLm, "grSig_pT2_1_0" , kFullSquare, kBlue );
    TGraphErrors * grPA_Lm1_v24    = getGr( fLm, "grSig_pT2_1_1" , kFullSquare, kBlue );
    TGraphErrors * grPA_Lm2_v24    = getGr( fLm, "grSig_pT2_1_2" , kFullSquare, kBlue );
    TGraphErrors * grPA_Lm3_v24    = getGr( fLm, "grSig_pT2_1_3" , kFullSquare, kBlue );

    TGraphErrors * grPA_Lm0_v26    = getGr( fLm, "grSig_pT2_2_0" , kFullCross,  kRed  );
    TGraphErrors * grPA_Lm1_v26    = getGr( fLm, "grSig_pT2_2_1" , kFullCross,  kRed  );
    TGraphErrors * grPA_Lm2_v26    = getGr( fLm, "grSig_pT2_2_2" , kFullCross,  kRed  );
    TGraphErrors * grPA_Lm3_v26    = getGr( fLm, "grSig_pT2_2_3" , kFullCross,  kRed  );

    TGraphErrors * grPA_Lm0_v24sub = getGr( fLm, "grSig_V2sub4_0", kOpenCircle, kBlue );
    TGraphErrors * grPA_Lm1_v24sub = getGr( fLm, "grSig_V2sub4_1", kOpenCircle, kBlue );
    TGraphErrors * grPA_Lm2_v24sub = getGr( fLm, "grSig_V2sub4_2", kOpenCircle, kBlue );
    TGraphErrors * grPA_Lm3_v24sub = getGr( fLm, "grSig_V2sub4_3", kOpenCircle, kBlue );


    FixAALm( grPA_Lm0_v24 );
    FixAALm( grPA_Lm1_v24 );
    FixAALm( grPA_Lm2_v24 );
    FixAALm( grPA_Lm3_v24 );

    FixAALm( grPA_Lm0_v26 );
    FixAALm( grPA_Lm1_v26 );
    FixAALm( grPA_Lm2_v26 );
    FixAALm( grPA_Lm3_v26 );

    FixAALm( grPA_Lm0_v24sub );
    FixAALm( grPA_Lm1_v24sub );
    FixAALm( grPA_Lm2_v24sub );
    FixAALm( grPA_Lm3_v24sub );

    // Obs
    TGraphErrors * grPAObs_Lm0_v24    = getGr( fLm, "grObs_pT2_1_0" , kFullSquare, kBlue );
    TGraphErrors * grPAObs_Lm1_v24    = getGr( fLm, "grObs_pT2_1_1" , kFullSquare, kBlue );
    TGraphErrors * grPAObs_Lm2_v24    = getGr( fLm, "grObs_pT2_1_2" , kFullSquare, kBlue );
    TGraphErrors * grPAObs_Lm3_v24    = getGr( fLm, "grObs_pT2_1_3" , kFullSquare, kBlue );

    TGraphErrors * grPAObs_Lm0_v26    = getGr( fLm, "grObs_pT2_2_0" , kFullCross,  kRed  );
    TGraphErrors * grPAObs_Lm1_v26    = getGr( fLm, "grObs_pT2_2_1" , kFullCross,  kRed  );
    TGraphErrors * grPAObs_Lm2_v26    = getGr( fLm, "grObs_pT2_2_2" , kFullCross,  kRed  );
    TGraphErrors * grPAObs_Lm3_v26    = getGr( fLm, "grObs_pT2_2_3" , kFullCross,  kRed  );

    TGraphErrors * grPAObs_Lm0_v24sub = getGr( fLm, "grObs_V2sub4_0", kOpenCircle, kBlue );
    TGraphErrors * grPAObs_Lm1_v24sub = getGr( fLm, "grObs_V2sub4_1", kOpenCircle, kBlue );
    TGraphErrors * grPAObs_Lm2_v24sub = getGr( fLm, "grObs_V2sub4_2", kOpenCircle, kBlue );
    TGraphErrors * grPAObs_Lm3_v24sub = getGr( fLm, "grObs_V2sub4_3", kOpenCircle, kBlue );

    FixAALm( grPAObs_Lm0_v24 );
    FixAALm( grPAObs_Lm1_v24 );
    FixAALm( grPAObs_Lm2_v24 );
    FixAALm( grPAObs_Lm3_v24 );

    FixAALm( grPAObs_Lm0_v26 );
    FixAALm( grPAObs_Lm1_v26 );
    FixAALm( grPAObs_Lm2_v26 );
    FixAALm( grPAObs_Lm3_v26 );

    FixAALm( grPAObs_Lm0_v24sub );
    FixAALm( grPAObs_Lm1_v24sub );
    FixAALm( grPAObs_Lm2_v24sub );
    FixAALm( grPAObs_Lm3_v24sub );

    // Bkg
    TGraphErrors * grPABkg_Lm0_v24    = getGr( fLm, "grBkg_pT2_1_0" , kFullSquare, kBlue );
    TGraphErrors * grPABkg_Lm1_v24    = getGr( fLm, "grBkg_pT2_1_1" , kFullSquare, kBlue );
    TGraphErrors * grPABkg_Lm2_v24    = getGr( fLm, "grBkg_pT2_1_2" , kFullSquare, kBlue );
    TGraphErrors * grPABkg_Lm3_v24    = getGr( fLm, "grBkg_pT2_1_3" , kFullSquare, kBlue );

    TGraphErrors * grPABkg_Lm0_v26    = getGr( fLm, "grBkg_pT2_2_0" , kFullCross,  kRed  );
    TGraphErrors * grPABkg_Lm1_v26    = getGr( fLm, "grBkg_pT2_2_1" , kFullCross,  kRed  );
    TGraphErrors * grPABkg_Lm2_v26    = getGr( fLm, "grBkg_pT2_2_2" , kFullCross,  kRed  );
    TGraphErrors * grPABkg_Lm3_v26    = getGr( fLm, "grBkg_pT2_2_3" , kFullCross,  kRed  );

    TGraphErrors * grPABkg_Lm0_v24sub = getGr( fLm, "grBkg_V2sub4_0", kOpenCircle, kBlue );
    TGraphErrors * grPABkg_Lm1_v24sub = getGr( fLm, "grBkg_V2sub4_1", kOpenCircle, kBlue );
    TGraphErrors * grPABkg_Lm2_v24sub = getGr( fLm, "grBkg_V2sub4_2", kOpenCircle, kBlue );
    TGraphErrors * grPABkg_Lm3_v24sub = getGr( fLm, "grBkg_V2sub4_3", kOpenCircle, kBlue );


    FixAALm( grPABkg_Lm0_v24 );
    FixAALm( grPABkg_Lm1_v24 );
    FixAALm( grPABkg_Lm2_v24 );
    FixAALm( grPABkg_Lm3_v24 );

    FixAALm( grPABkg_Lm0_v26 );
    FixAALm( grPABkg_Lm1_v26 );
    FixAALm( grPABkg_Lm2_v26 );
    FixAALm( grPABkg_Lm3_v26 );

    FixAALm( grPABkg_Lm0_v24sub );
    FixAALm( grPABkg_Lm1_v24sub );
    FixAALm( grPABkg_Lm2_v24sub );
    FixAALm( grPABkg_Lm3_v24sub );


    grLeg = new std::map<TGraph*, std::string> {
        {grPA_Ks0_v24,       "K_{s}^{0} v_{2}^{sig}{4}"},
        {grPA_Ks0_v26,       "K_{s}^{0} v_{2}^{sig}{6}"},
        {grPA_Ks0_v24sub,    "K_{s}^{0} v_{2}^{sig}{4, sub-event}"},
        {grPA_Ks1_v24,       "K_{s}^{0} v_{2}^{sig}{4}"},
        {grPA_Ks1_v26,       "K_{s}^{0} v_{2}^{sig}{6}"},
        {grPA_Ks1_v24sub,    "K_{s}^{0} v_{2}^{sig}{4, sub-event}"},
        {grPA_Ks2_v24,       "K_{s}^{0} v_{2}^{sig}{4}"},
        {grPA_Ks2_v26,       "K_{s}^{0} v_{2}^{sig}{6}"},
        {grPA_Ks2_v24sub,    "K_{s}^{0} v_{2}^{sig}{4, sub-event}"},
        {grPA_Ks3_v24,       "K_{s}^{0} v_{2}^{sig}{4}"},
        {grPA_Ks3_v26,       "K_{s}^{0} v_{2}^{sig}{6}"},
        {grPA_Ks3_v24sub,    "K_{s}^{0} v_{2}^{sig}{4, sub-event}"},

        {grPAObs_Ks0_v24,    "K_{s}^{0} v_{2}^{obs}{4}"},
        {grPAObs_Ks0_v26,    "K_{s}^{0} v_{2}^{obs}{6}"},
        {grPAObs_Ks0_v24sub, "K_{s}^{0} v_{2}^{obs}{4, sub-event}"},
        {grPAObs_Ks1_v24,    "K_{s}^{0} v_{2}^{obs}{4}"},
        {grPAObs_Ks1_v26,    "K_{s}^{0} v_{2}^{obs}{6}"},
        {grPAObs_Ks1_v24sub, "K_{s}^{0} v_{2}^{obs}{4, sub-event}"},
        {grPAObs_Ks2_v24,    "K_{s}^{0} v_{2}^{obs}{4}"},
        {grPAObs_Ks2_v26,    "K_{s}^{0} v_{2}^{obs}{6}"},
        {grPAObs_Ks2_v24sub, "K_{s}^{0} v_{2}^{obs}{4, sub-event}"},
        {grPAObs_Ks3_v24,    "K_{s}^{0} v_{2}^{obs}{4}"},
        {grPAObs_Ks3_v26,    "K_{s}^{0} v_{2}^{obs}{6}"},
        {grPAObs_Ks3_v24sub, "K_{s}^{0} v_{2}^{obs}{4, sub-event}"},

        {grPABkg_Ks0_v24,    "K_{s}^{0} v_{2}^{bkg}{4}"},
        {grPABkg_Ks0_v26,    "K_{s}^{0} v_{2}^{bkg}{6}"},
        {grPABkg_Ks0_v24sub, "K_{s}^{0} v_{2}^{bkg}{4, sub-event}"},
        {grPABkg_Ks1_v24,    "K_{s}^{0} v_{2}^{bkg}{4}"},
        {grPABkg_Ks1_v26,    "K_{s}^{0} v_{2}^{bkg}{6}"},
        {grPABkg_Ks1_v24sub, "K_{s}^{0} v_{2}^{bkg}{4, sub-event}"},
        {grPABkg_Ks2_v24,    "K_{s}^{0} v_{2}^{bkg}{4}"},
        {grPABkg_Ks2_v26,    "K_{s}^{0} v_{2}^{bkg}{6}"},
        {grPABkg_Ks2_v24sub, "K_{s}^{0} v_{2}^{bkg}{4, sub-event}"},
        {grPABkg_Ks3_v24,    "K_{s}^{0} v_{2}^{bkg}{4}"},
        {grPABkg_Ks3_v26,    "K_{s}^{0} v_{2}^{bkg}{6}"},
        {grPABkg_Ks3_v24sub, "K_{s}^{0} v_{2}^{bkg}{4, sub-event}"},

        {grPA_Lm0_v24,       "#Lambda v_{2}^{sig}{4}"},
        {grPA_Lm0_v26,       "#Lambda v_{2}^{sig}{6}"},
        {grPA_Lm0_v24sub,    "#Lambda v_{2}^{sig}{4, sub-event}"},
        {grPA_Lm1_v24,       "#Lambda v_{2}^{sig}{4}"},
        {grPA_Lm1_v26,       "#Lambda v_{2}^{sig}{6}"},
        {grPA_Lm1_v24sub,    "#Lambda v_{2}^{sig}{4, sub-event}"},
        {grPA_Lm2_v24,       "#Lambda v_{2}^{sig}{4}"},
        {grPA_Lm2_v26,       "#Lambda v_{2}^{sig}{6}"},
        {grPA_Lm2_v24sub,    "#Lambda v_{2}^{sig}{4, sub-event}"},
        {grPA_Lm3_v24,       "#Lambda v_{2}^{sig}{4}"},
        {grPA_Lm3_v26,       "#Lambda v_{2}^{sig}{6}"},
        {grPA_Lm3_v24sub,    "#Lambda v_{2}^{sig}{4, sub-event}"},

        {grPAObs_Lm0_v24,    "#Lambda v_{2}^{obs}{4}"},
        {grPAObs_Lm0_v26,    "#Lambda v_{2}^{obs}{6}"},
        {grPAObs_Lm0_v24sub, "#Lambda v_{2}^{obs}{4, sub-event}"},
        {grPAObs_Lm1_v24,    "#Lambda v_{2}^{obs}{4}"},
        {grPAObs_Lm1_v26,    "#Lambda v_{2}^{obs}{6}"},
        {grPAObs_Lm1_v24sub, "#Lambda v_{2}^{obs}{4, sub-event}"},
        {grPAObs_Lm2_v24,    "#Lambda v_{2}^{obs}{4}"},
        {grPAObs_Lm2_v26,    "#Lambda v_{2}^{obs}{6}"},
        {grPAObs_Lm2_v24sub, "#Lambda v_{2}^{obs}{4, sub-event}"},
        {grPAObs_Lm3_v24,    "#Lambda v_{2}^{obs}{4}"},
        {grPAObs_Lm3_v26,    "#Lambda v_{2}^{obs}{6}"},
        {grPAObs_Lm3_v24sub, "#Lambda v_{2}^{obs}{4, sub-event}"},

        {grPABkg_Lm0_v24,    "#Lambda v_{2}^{bkg}{4}"},
        {grPABkg_Lm0_v26,    "#Lambda v_{2}^{bkg}{6}"},
        {grPABkg_Lm0_v24sub, "#Lambda v_{2}^{bkg}{4, sub-event}"},
        {grPABkg_Lm1_v24,    "#Lambda v_{2}^{bkg}{4}"},
        {grPABkg_Lm1_v26,    "#Lambda v_{2}^{bkg}{6}"},
        {grPABkg_Lm1_v24sub, "#Lambda v_{2}^{bkg}{4, sub-event}"},
        {grPABkg_Lm2_v24,    "#Lambda v_{2}^{bkg}{4}"},
        {grPABkg_Lm2_v26,    "#Lambda v_{2}^{bkg}{6}"},
        {grPABkg_Lm2_v24sub, "#Lambda v_{2}^{bkg}{4, sub-event}"},
        {grPABkg_Lm3_v24,    "#Lambda v_{2}^{bkg}{4}"},
        {grPABkg_Lm3_v26,    "#Lambda v_{2}^{bkg}{6}"},
        {grPABkg_Lm3_v24sub, "#Lambda v_{2}^{bkg}{4, sub-event}"},
    };
    const char* strNoff[] = {
        "0-10\%", // 0
        "10-30\%", // 1
        "30-50\%", // 2
        "50-80\%", // 3
        "80-100\%", // 4
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
    // PbPb Obs 6
    hframePt->Draw();
    legPA->Clear();
    setColor(grPAObs_Lm0_v24, kRed);

    drawGr(grPAObs_Ks0_v24, legPA);
    drawGr(grPAObs_Lm0_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[0]);
    cPA->SaveAs("PbPb_Obs0.pdf");

    // PbPb Obs 7
    hframePt->Draw();
    legPA->Clear();
    setColor(grPAObs_Lm1_v24, kRed);

    drawGr(grPAObs_Ks1_v24, legPA);
    drawGr(grPAObs_Lm1_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[1]);
    cPA->SaveAs("PbPb_Obs1.pdf");

    // PbPb Obs 8
    hframePt->Draw();
    legPA->Clear();
    setColor(grPAObs_Lm2_v24, kRed);

    drawGr(grPAObs_Ks2_v24, legPA);
    drawGr(grPAObs_Lm2_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[2]);
    cPA->SaveAs("PbPb_Obs2.pdf");

    // PbPb Obs 9
    hframePt->Draw();
    legPA->Clear();
    setColor(grPAObs_Lm3_v24, kRed);

    drawGr(grPAObs_Ks3_v24, legPA);
    drawGr(grPAObs_Lm3_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[3]);
    cPA->SaveAs("PbPb_Obs3.pdf");

    // PbPb Obs v24sub 6
    hframePt->GetYaxis()->SetTitle("v_{2}^{obs}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm0_v24sub, kRed);

    drawGr(grPAObs_Ks0_v24sub, legPA);
    drawGr(grPAObs_Lm0_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[0]);
    cPA->SaveAs("PbPb_Obs0_v24sub.pdf");

    // PbPb Obs v24sub 6
    hframePt->GetYaxis()->SetTitle("v_{2}^{obs}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm0_v24sub, kRed);

    drawGr(grPAObs_Ks0_v24sub, legPA);
    drawGr(grPAObs_Lm0_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[0]);
    cPA->SaveAs("PbPb_Obs0_v24sub.pdf");

    // PbPb Obs v24sub 7
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm1_v24sub, kRed);
    drawGr(grPAObs_Ks1_v24sub, legPA);
    drawGr(grPAObs_Lm1_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[1]);
    cPA->SaveAs("PbPb_Obs1_v24sub.pdf");

    // PbPb Obs v24sub 8
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm2_v24sub, kRed);
    drawGr(grPAObs_Ks2_v24sub, legPA);
    drawGr(grPAObs_Lm2_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[2]);
    cPA->SaveAs("PbPb_Obs2_v24sub.pdf");

    // PbPb Obs v24sub 9
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm3_v24sub, kRed);
    drawGr(grPAObs_Ks3_v24sub, legPA);
    drawGr(grPAObs_Lm3_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[3]);
    cPA->SaveAs("PbPb_Obs3_v24sub.pdf");

    // PbPb Obs v24 6
    hframePt->GetYaxis()->SetTitle("v_{2}^{bkg}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm0_v24sub, kRed);

    drawGr(grPAObs_Ks0_v24sub, legPA);
    drawGr(grPAObs_Lm0_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[0]);
    cPA->SaveAs("PbPb_Obs0_v24sub.pdf");


    // PbPb Bkg 6
    hframePt->GetYaxis()->SetTitle("v_{2}^{bkg}{4}");
    hframePt->Draw();
    legPA->Clear();
    setColor(grPABkg_Lm0_v24, kRed);

    drawGr(grPABkg_Ks0_v24, legPA);
    drawGr(grPABkg_Lm0_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[0]);
    cPA->SaveAs("PbPb_Bkg0.pdf");

    // PbPb Bkg 7
    hframePt->Draw();
    legPA->Clear();
    setColor(grPABkg_Lm1_v24, kRed);

    drawGr(grPABkg_Ks1_v24, legPA);
    drawGr(grPABkg_Lm1_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[1]);
    cPA->SaveAs("PbPb_Bkg1.pdf");

    // PbPb Bkg 8
    hframePt->Draw();
    legPA->Clear();
    setColor(grPABkg_Lm2_v24, kRed);

    drawGr(grPABkg_Ks2_v24, legPA);
    drawGr(grPABkg_Lm2_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[2]);
    cPA->SaveAs("PbPb_Bkg2.pdf");

    // PbPb Bkg 9
    hframePt->Draw();
    legPA->Clear();
    setColor(grPABkg_Lm3_v24, kRed);

    drawGr(grPABkg_Ks3_v24, legPA);
    drawGr(grPABkg_Lm3_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[3]);
    cPA->SaveAs("PbPb_Bkg3.pdf");

    // PbPb Bkg v24sub 6
    hframePt->GetYaxis()->SetTitle("v_{2}^{bkg}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPABkg_Lm0_v24sub, kRed);

    drawGr(grPABkg_Ks0_v24sub, legPA);
    drawGr(grPABkg_Lm0_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[0]);
    cPA->SaveAs("PbPb_Bkg0_v24sub.pdf");

    // PbPb Bkg v24sub 7
    hframePt->GetYaxis()->SetTitle("v_{2}^{bkg}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPABkg_Lm1_v24sub, kRed);

    drawGr(grPABkg_Ks1_v24sub, legPA);
    drawGr(grPABkg_Lm1_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[1]);
    cPA->SaveAs("PbPb_Bkg1_v24sub.pdf");

    // PbPb Bkg v24sub 8
    hframePt->GetYaxis()->SetTitle("v_{2}^{bkg}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPABkg_Lm2_v24sub, kRed);

    drawGr(grPABkg_Ks2_v24sub, legPA);
    drawGr(grPABkg_Lm2_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[2]);
    cPA->SaveAs("PbPb_Bkg2_v24sub.pdf");

    // PbPb Bkg v24sub 9
    hframePt->GetYaxis()->SetTitle("v_{2}^{bkg}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPABkg_Lm3_v24sub, kRed);

    drawGr(grPABkg_Ks3_v24sub, legPA);
    drawGr(grPABkg_Lm3_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[3]);
    cPA->SaveAs("PbPb_Bkg3_v24sub.pdf");

    // PbPb Ks 6
    hframePt->GetYaxis()->SetTitle("v_{2}{4}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Ks0_v24, kRed);
    setColor(grPABkg_Ks0_v24, kBlue);
    drawGr(grPAObs_Ks0_v24, legPA);
    drawGr(grPABkg_Ks0_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[0]);
    cPA->SaveAs("PbPb_Ks0_v24.pdf");

    // PbPb Ks 7
    hframePt->GetYaxis()->SetTitle("v_{2}{4}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Ks1_v24, kRed);
    setColor(grPABkg_Ks1_v24, kBlue);
    drawGr(grPAObs_Ks1_v24, legPA);
    drawGr(grPABkg_Ks1_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[1]);
    cPA->SaveAs("PbPb_Ks1_v24.pdf");

    // PbPb Ks 8
    hframePt->GetYaxis()->SetTitle("v_{2}{4}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Ks2_v24, kRed);
    setColor(grPABkg_Ks2_v24, kBlue);
    drawGr(grPAObs_Ks2_v24, legPA);
    drawGr(grPABkg_Ks2_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[2]);
    cPA->SaveAs("PbPb_Ks2_v24.pdf");

    // PbPb Ks 9
    hframePt->GetYaxis()->SetTitle("v_{2}{4}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Ks3_v24, kRed);
    setColor(grPABkg_Ks3_v24, kBlue);
    drawGr(grPAObs_Ks3_v24, legPA);
    drawGr(grPABkg_Ks3_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[3]);
    cPA->SaveAs("PbPb_Ks3_v24.pdf");

    // PbPb Ks sub 6
    hframePt->GetYaxis()->SetTitle("v_{2}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Ks0_v24sub, kRed);
    setColor(grPABkg_Ks0_v24sub, kBlue);
    drawGr(grPAObs_Ks0_v24sub, legPA);
    drawGr(grPABkg_Ks0_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[0]);
    cPA->SaveAs("PbPb_Ks0_v24sub.pdf");

    // PbPb Ks sub 7
    hframePt->GetYaxis()->SetTitle("v_{2}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Ks1_v24sub, kRed);
    setColor(grPABkg_Ks1_v24sub, kBlue);
    drawGr(grPAObs_Ks1_v24sub, legPA);
    drawGr(grPABkg_Ks1_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[1]);
    cPA->SaveAs("PbPb_Ks1_v24sub.pdf");

    // PbPb Ks sub 8
    hframePt->GetYaxis()->SetTitle("v_{2}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Ks2_v24sub, kRed);
    setColor(grPABkg_Ks2_v24sub, kBlue);
    drawGr(grPAObs_Ks2_v24sub, legPA);
    drawGr(grPABkg_Ks2_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[2]);
    cPA->SaveAs("PbPb_Ks2_v24sub.pdf");

    // PbPb Ks sub 9
    hframePt->GetYaxis()->SetTitle("v_{2}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Ks3_v24sub, kRed);
    setColor(grPABkg_Ks3_v24sub, kBlue);
    drawGr(grPAObs_Ks3_v24sub, legPA);
    drawGr(grPABkg_Ks3_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[3]);
    cPA->SaveAs("PbPb_Ks3_v24sub.pdf");

    // PbPb Lm 6
    hframePt->GetYaxis()->SetTitle("v_{2}{4}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm0_v24, kRed);
    setColor(grPABkg_Lm0_v24, kBlue);
    drawGr(grPAObs_Lm0_v24, legPA);
    drawGr(grPABkg_Lm0_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[0]);
    cPA->SaveAs("PbPb_Lm0_v24.pdf");

    // PbPb Lm 7
    hframePt->GetYaxis()->SetTitle("v_{2}{4}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm1_v24, kRed);
    setColor(grPABkg_Lm1_v24, kBlue);
    drawGr(grPAObs_Lm1_v24, legPA);
    drawGr(grPABkg_Lm1_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[1]);
    cPA->SaveAs("PbPb_Lm1_v24.pdf");

    // PbPb Lm 8
    hframePt->GetYaxis()->SetTitle("v_{2}{4}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm2_v24, kRed);
    setColor(grPABkg_Lm2_v24, kBlue);
    drawGr(grPAObs_Lm2_v24, legPA);
    drawGr(grPABkg_Lm2_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[2]);
    cPA->SaveAs("PbPb_Lm2_v24.pdf");

    // PbPb Lm 9
    hframePt->GetYaxis()->SetTitle("v_{2}{4}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm3_v24, kRed);
    setColor(grPABkg_Lm3_v24, kBlue);
    drawGr(grPAObs_Lm3_v24, legPA);
    drawGr(grPABkg_Lm3_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[3]);
    cPA->SaveAs("PbPb_Lm3_v24.pdf");

    // PbPb Lm sub 6
    hframePt->GetYaxis()->SetTitle("v_{2}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm0_v24sub, kRed);
    setColor(grPABkg_Lm0_v24sub, kBlue);
    drawGr(grPAObs_Lm0_v24sub, legPA);
    drawGr(grPABkg_Lm0_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[0]);
    cPA->SaveAs("PbPb_Lm0_v24sub.pdf");

    // PbPb Lm sub 7
    hframePt->GetYaxis()->SetTitle("v_{2}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm1_v24sub, kRed);
    setColor(grPABkg_Lm1_v24sub, kBlue);
    drawGr(grPAObs_Lm1_v24sub, legPA);
    drawGr(grPABkg_Lm1_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[1]);
    cPA->SaveAs("PbPb_Lm1_v24sub.pdf");

    // PbPb Lm sub 8
    hframePt->GetYaxis()->SetTitle("v_{2}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm2_v24sub, kRed);
    setColor(grPABkg_Lm2_v24sub, kBlue);
    drawGr(grPAObs_Lm2_v24sub, legPA);
    drawGr(grPABkg_Lm2_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[2]);
    cPA->SaveAs("PbPb_Lm2_v24sub.pdf");

    // PbPb Lm sub 9
    hframePt->GetYaxis()->SetTitle("v_{2}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm3_v24sub, kRed);
    setColor(grPABkg_Lm3_v24sub, kBlue);
    drawGr(grPAObs_Lm3_v24sub, legPA);
    drawGr(grPABkg_Lm3_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[3]);
    cPA->SaveAs("PbPb_Lm3_v24sub.pdf");

    // PbPb sig 6
    hframePt->GetYaxis()->SetTitle("v_{2}^{sig}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPA_Lm0_v24, kRed);
    drawGr(grPA_Ks0_v24, legPA);
    drawGr(grPA_Lm0_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[0]);
    cPA->SaveAs("PbPb_Sig0.pdf");

    // PbPb sig 7
    hframePt->GetYaxis()->SetTitle("v_{2}^{sig}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPA_Lm1_v24, kRed);
    drawGr(grPA_Ks1_v24, legPA);
    drawGr(grPA_Lm1_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[1]);
    cPA->SaveAs("PbPb_Sig1.pdf");

    // PbPb sig 8
    hframePt->GetYaxis()->SetTitle("v_{2}^{sig}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPA_Lm2_v24, kRed);
    drawGr(grPA_Ks2_v24, legPA);
    drawGr(grPA_Lm2_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[2]);
    cPA->SaveAs("PbPb_Sig2.pdf");

    // PbPb sig 9
    hframePt->GetYaxis()->SetTitle("v_{2}^{sig}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPA_Lm3_v24, kRed);
    drawGr(grPA_Ks3_v24, legPA);
    drawGr(grPA_Lm3_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[3]);
    cPA->SaveAs("PbPb_Sig3.pdf");




    //////////////////////////////////////// manual plot final results
    // PbPb Ks 8
    TCanvas * cResult= MakeCanvas("cResult", "cResult", 800, 600);;
    TH2D * hframePtResult = new TH2D("hframePtResult", "", 1, 0, 8.5, 1, -0.05, 0.38);
    InitHist(hframePtResult, "p_{T}", "v_{2}");

    hframePtResult->Draw();
    setColor(grPA_Ks2_v26, kRed);

    TGraphErrors * grPA_Ks2_v24subsys = getGrSys(grPA_Ks2_v24sub, sys_PbPb_Ks, 3003);
    TGraphErrors * grPA_Ks2_v24sys    = getGrSys(grPA_Ks2_v24,    sys_PbPb_Ks, 3003);
    TGraphErrors * grPA_Ks2_v26sys    = getGrSys(grPA_Ks2_v26,    sys_PbPb_Ks, 3001);


    grPA_Ks2_v24subsys->Draw("[]2");
    grPA_Ks2_v24sys->Draw("[]2");
    grPA_Ks2_v26sys->Draw("[]2");

    grPA_Ks2_v24sub->Draw("psame");
    grPA_Ks2_v24->Draw("psame");
    grPA_Ks2_v26->Draw("psame");

    TLegend * leg1 = new TLegend(0.16, 0.70, 0.35 , 0.94);
    leg1->SetFillColor(kWhite);
    leg1->SetTextFont(42);
    leg1->SetTextSize(0.04);
    leg1->SetBorderSize(0);

    leg1->AddEntry(grPA_Ks2_v24, "K_{s} v_{2}{4}", "p");
    leg1->AddEntry(grPA_Ks2_v24sub, "K_{s} v_{2}{4,sub-event}", "p");
    leg1->AddEntry(grPA_Ks2_v26, "K_{s} v_{2}{6}", "p");
    leg1->Draw("same");

	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[2]);
    cResult->SaveAs("F_PbPb_Ks2.pdf");

    // PbPb Ks 6
    hframePtResult->Draw();
    leg1->Clear();
    setColor(grPA_Ks0_v26, kRed);

    TGraphErrors * grPA_Ks0_v24subsys = getGrSys(grPA_Ks0_v24sub, sys_PbPb_Ks, 3003);
    TGraphErrors * grPA_Ks0_v24sys    = getGrSys(grPA_Ks0_v24,    sys_PbPb_Ks, 3003);
    TGraphErrors * grPA_Ks0_v26sys    = getGrSys(grPA_Ks0_v26,    sys_PbPb_Ks, 3001);

    grPA_Ks0_v24subsys->Draw("[]2");
    grPA_Ks0_v24sys->Draw("[]2");
    grPA_Ks0_v26sys->Draw("[]2");

    grPA_Ks0_v24sub->Draw("psame");
    grPA_Ks0_v24->Draw("psame");
    grPA_Ks0_v26->Draw("psame");

    leg1->AddEntry(grPA_Ks0_v24, "K_{s} v_{2}{4}", "p");
    leg1->AddEntry(grPA_Ks0_v24sub, "K_{s} v_{2}{4,sub-event}", "p");
    leg1->AddEntry(grPA_Ks0_v26, "K_{s} v_{2}{6}", "p");
    leg1->Draw("same");

	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[0]);
    cResult->SaveAs("F_PbPb_Ks0.pdf");

    // PbPb Ks 7
    hframePtResult->Draw();
    leg1->Clear();
    setColor(grPA_Ks1_v26, kRed);

    TGraphErrors * grPA_Ks1_v24subsys = getGrSys(grPA_Ks1_v24sub, sys_PbPb_Ks, 3003);
    TGraphErrors * grPA_Ks1_v24sys    = getGrSys(grPA_Ks1_v24,    sys_PbPb_Ks, 3003);
    TGraphErrors * grPA_Ks1_v26sys    = getGrSys(grPA_Ks1_v26,    sys_PbPb_Ks, 3001);

    grPA_Ks1_v24subsys->Draw("[]2");
    grPA_Ks1_v24sys->Draw("[]2");
    grPA_Ks1_v26sys->Draw("[]2");

    grPA_Ks1_v24sub->Draw("psame");
    grPA_Ks1_v24->Draw("psame");
    grPA_Ks1_v26->Draw("psame");

    leg1->AddEntry(grPA_Ks1_v24, "K_{s} v_{2}{4}", "p");
    leg1->AddEntry(grPA_Ks1_v24sub, "K_{s} v_{2}{4,sub-event}", "p");
    leg1->AddEntry(grPA_Ks1_v26, "K_{s} v_{2}{6}", "p");
    leg1->Draw("same");

	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[1]);
    cResult->SaveAs("F_PbPb_Ks1.pdf");

    // PbPb Ks 9
    hframePtResult->Draw();
    leg1->Clear();
    setColor(grPA_Ks3_v26, kRed);

    TGraphErrors * grPA_Ks3_v24subsys = getGrSys(grPA_Ks3_v24sub, sys_PbPb_Ks, 3003);
    TGraphErrors * grPA_Ks3_v24sys    = getGrSys(grPA_Ks3_v24,    sys_PbPb_Ks, 3003);
    TGraphErrors * grPA_Ks3_v26sys    = getGrSys(grPA_Ks3_v26,    sys_PbPb_Ks, 3001);

    grPA_Ks3_v24subsys->Draw("[]2");
    grPA_Ks3_v24sys->Draw("[]2");
    grPA_Ks3_v26sys->Draw("[]2");

    grPA_Ks3_v24sub->Draw("psame");
    grPA_Ks3_v24->Draw("psame");
    grPA_Ks3_v26->Draw("psame");

    leg1->AddEntry(grPA_Ks3_v24, "K_{s} v_{2}{4}", "p");
    leg1->AddEntry(grPA_Ks3_v24sub, "K_{s} v_{2}{4,sub-event}", "p");
    leg1->AddEntry(grPA_Ks3_v26, "K_{s} v_{2}{6}", "p");
    leg1->Draw("same");

	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[3]);
    cResult->SaveAs("F_PbPb_Ks3.pdf");

    // PbPb Lm 8
    leg1->Clear();
    hframePtResult->Draw();
    setColor(grPA_Lm2_v24, kBlue);
    setColor(grPA_Lm2_v26, kRed);

    TGraphErrors * grPA_Lm2_v24subsys = getGrSys(grPA_Lm2_v24sub, sys_PbPb_Lm, 3003);
    TGraphErrors * grPA_Lm2_v24sys    = getGrSys(grPA_Lm2_v24,    sys_PbPb_Lm, 3003);
    TGraphErrors * grPA_Lm2_v26sys    = getGrSys(grPA_Lm2_v26,    sys_PbPb_Lm, 3001);

    grPA_Lm2_v24subsys->Draw("[]2");
    grPA_Lm2_v24sys->Draw("[]2");
    grPA_Lm2_v26sys->Draw("[]2");

    setColor(grPA_Lm2_v24sub, kBlue);

    grPA_Lm2_v24sub->Draw("psame");
    grPA_Lm2_v24->Draw("psame");
    grPA_Lm2_v26->Draw("psame");

    leg1->AddEntry(grPA_Lm2_v24, "#Lambda v_{2}{4}", "p");
    leg1->AddEntry(grPA_Lm2_v24sub, "#Lambda v_{2}{4, sub-event}", "p");
    leg1->AddEntry(grPA_Lm2_v26, "#Lambda v_{2}{6}", "p");
    leg1->Draw("same");

	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[2]);
    cResult->SaveAs("F_PbPb_Lm2.pdf");

    // PbPb Lm 6
    leg1->Clear();
    hframePtResult->Draw();
    setColor(grPA_Lm0_v24, kBlue);
    setColor(grPA_Lm0_v26, kRed);

    TGraphErrors * grPA_Lm0_v24subsys = getGrSys(grPA_Lm0_v24sub, sys_PbPb_Lm, 3003);
    TGraphErrors * grPA_Lm0_v24sys    = getGrSys(grPA_Lm0_v24,    sys_PbPb_Lm, 3003);
    TGraphErrors * grPA_Lm0_v26sys    = getGrSys(grPA_Lm0_v26,    sys_PbPb_Lm, 3001);

    grPA_Lm0_v24subsys->Draw("[]2");
    grPA_Lm0_v24sys->Draw("[]2");
    grPA_Lm0_v26sys->Draw("[]2");

    setColor(grPA_Lm0_v24sub, kBlue);

    grPA_Lm0_v24sub->Draw("psame");
    grPA_Lm0_v24->Draw("psame");
    grPA_Lm0_v26->Draw("psame");

    leg1->AddEntry(grPA_Lm0_v24, "#Lambda v_{2}{4}", "p");
    leg1->AddEntry(grPA_Lm0_v24sub, "#Lambda v_{2}{4, sub-event}", "p");
    leg1->AddEntry(grPA_Lm0_v26, "#Lambda v_{2}{6}", "p");
    leg1->Draw("same");

	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[0]);
    cResult->SaveAs("F_PbPb_Lm0.pdf");

    // PbPb Lm 7
    leg1->Clear();
    hframePtResult->Draw();
    setColor(grPA_Lm1_v24, kBlue);
    setColor(grPA_Lm1_v26, kRed);

    TGraphErrors * grPA_Lm1_v24subsys = getGrSys(grPA_Lm1_v24sub, sys_PbPb_Lm, 3003);
    TGraphErrors * grPA_Lm1_v24sys    = getGrSys(grPA_Lm1_v24,    sys_PbPb_Lm, 3003);
    TGraphErrors * grPA_Lm1_v26sys    = getGrSys(grPA_Lm1_v26,    sys_PbPb_Lm, 3001);

    grPA_Lm1_v24subsys->Draw("[]2");
    grPA_Lm1_v24sys->Draw("[]2");
    grPA_Lm1_v26sys->Draw("[]2");

    setColor(grPA_Lm0_v24sub, kBlue);

    grPA_Lm1_v24sub->Draw("psame");
    grPA_Lm1_v24->Draw("psame");
    grPA_Lm1_v26->Draw("psame");

    leg1->AddEntry(grPA_Lm1_v24, "#Lambda v_{2}{4}", "p");
    leg1->AddEntry(grPA_Lm1_v24sub, "#Lambda v_{2}{4, sub-event}", "p");
    leg1->AddEntry(grPA_Lm1_v26, "#Lambda v_{2}{6}", "p");
    leg1->Draw("same");

	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[1]);
    cResult->SaveAs("F_PbPb_Lm1.pdf");

    // PbPb Lm 9
    leg1->Clear();
    hframePtResult->Draw();
    setColor(grPA_Lm3_v24, kBlue);
    setColor(grPA_Lm3_v26, kRed);

    TGraphErrors * grPA_Lm3_v24subsys = getGrSys(grPA_Lm3_v24sub, sys_PbPb_Lm, 3003);
    TGraphErrors * grPA_Lm3_v24sys    = getGrSys(grPA_Lm3_v24,    sys_PbPb_Lm, 3003);
    TGraphErrors * grPA_Lm3_v26sys    = getGrSys(grPA_Lm3_v26,    sys_PbPb_Lm, 3001);

    grPA_Lm3_v24subsys->Draw("[]2");
    grPA_Lm3_v24sys->Draw("[]2");
    grPA_Lm3_v26sys->Draw("[]2");

    setColor(grPA_Lm3_v24sub, kBlue);

    grPA_Lm3_v24sub->Draw("psame");
    grPA_Lm3_v24->Draw("psame");
    grPA_Lm3_v26->Draw("psame");

    leg1->AddEntry(grPA_Lm3_v24, "#Lambda v_{2}{4}", "p");
    leg1->AddEntry(grPA_Lm3_v24sub, "#Lambda v_{2}{4, sub-event}", "p");
    leg1->AddEntry(grPA_Lm3_v26, "#Lambda v_{2}{6}", "p");
    leg1->Draw("same");

	latexS.DrawLatexNDC(0.60, 0.90, "CMS PbPb 5.02 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, strNoff[3]);
    cResult->SaveAs("F_PbPb_Lm3.pdf");

}

void FixAAKs(TGraphErrors * gr)
{
}




void FixAALm(TGraphErrors * gr)
{
//    gr->RemovePoint(0);
//    gr->RemovePoint(0);
//    gr->RemovePoint(0);
}


void drawGr(TGraph* gr, TLegend* leg)
{
    gr->Draw("psame");
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
