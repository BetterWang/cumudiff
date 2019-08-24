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

void makePlot3()
{
    SetStyle();

    HIN_17_003();
    ALICE();

    TFile * fPA_Ks = new TFile("pPb_Ks2_corrected.root");
    TFile * fPA_Lm = new TFile("pPb_Lm2_corrected.root");

    // PA Ks
    TGraphErrors * grPA_Ks_v22    = (TGraphErrors*) fPA_Ks ->Get("grSig_pT2_0_8");
    TGraphErrors * grPA_Ks_v24    = (TGraphErrors*) fPA_Ks ->Get("grSig_pT2_1_8");
    TGraphErrors * grPA_Ks_v26    = (TGraphErrors*) fPA_Ks ->Get("grSig_pT2_2_8");
    TGraphErrors * grPA_Ks_v22sub = (TGraphErrors*) fPA_Ks ->Get("grSig_V2sub2_8");
    TGraphErrors * grPA_Ks_v24sub = (TGraphErrors*) fPA_Ks ->Get("grSig_V2sub4_8");
    TGraphErrors * grPA_Ks_v2Gap  = (TGraphErrors*) fPA_Ks ->Get("grSig_pTGap2_8");

    grPA_Ks_v24   ->SetMarkerStyle(kFullSquare);
    grPA_Ks_v26   ->SetMarkerStyle(kFullCross);
    grPA_Ks_v24sub->SetMarkerStyle(kOpenCircle);
    grPA_Ks_v24   ->SetMarkerSize(2);
    grPA_Ks_v26   ->SetMarkerSize(2);
    grPA_Ks_v24sub->SetMarkerSize(2);

    grPA_Ks_v24   ->SetMarkerColor(kBlue);
    grPA_Ks_v26   ->SetMarkerColor(kBlue);
    grPA_Ks_v24sub->SetMarkerColor(kBlue);
    grPA_Ks_v24   ->SetLineColor(kBlue);
    grPA_Ks_v26   ->SetLineColor(kBlue);
    grPA_Ks_v24sub->SetLineColor(kBlue);

    grPA_Ks_v2Gap ->SetMarkerStyle(kOpenSquare);
    grPA_Ks_v2Gap ->SetMarkerSize(2);
    grPA_Ks_v2Gap ->SetMarkerColor(kRed);
    grPA_Ks_v2Gap ->SetLineColor(kRed);

    FixPAKs( grPA_Ks_v22 );
    FixPAKs( grPA_Ks_v24 );
    FixPAKs( grPA_Ks_v26 );
    FixPAKs( grPA_Ks_v22sub );
    FixPAKs( grPA_Ks_v24sub );
    FixPAKs( grPA_Ks_v2Gap  );

    TGraphErrors * grPAObs_Ks_v22    = (TGraphErrors*) fPA_Ks ->Get("grObs_pT2_0_8");
    TGraphErrors * grPAObs_Ks_v24    = (TGraphErrors*) fPA_Ks ->Get("grObs_pT2_1_8");
    TGraphErrors * grPAObs_Ks_v26    = (TGraphErrors*) fPA_Ks ->Get("grObs_pT2_2_8");
    TGraphErrors * grPAObs_Ks_v22sub = (TGraphErrors*) fPA_Ks ->Get("grObs_V2sub2_8");
    TGraphErrors * grPAObs_Ks_v24sub = (TGraphErrors*) fPA_Ks ->Get("grObs_V2sub4_8");
    TGraphErrors * grPAObs_Ks_v2Gap  = (TGraphErrors*) fPA_Ks ->Get("grObs_pTGap2_8");

    grPAObs_Ks_v24   ->SetMarkerStyle(kFullSquare);
    grPAObs_Ks_v26   ->SetMarkerStyle(kFullCross);
    grPAObs_Ks_v24sub->SetMarkerStyle(kOpenSquare);

    grPAObs_Ks_v24   ->SetMarkerSize(2);
    grPAObs_Ks_v26   ->SetMarkerSize(2);
    grPAObs_Ks_v24sub->SetMarkerSize(2);

    grPAObs_Ks_v24   ->SetMarkerColor(kBlue);
    grPAObs_Ks_v26   ->SetMarkerColor(kBlue);
    grPAObs_Ks_v24sub->SetMarkerColor(kBlue);
    grPAObs_Ks_v24   ->SetLineColor(kBlue);
    grPAObs_Ks_v26   ->SetLineColor(kBlue);
    grPAObs_Ks_v24sub->SetLineColor(kBlue);

    FixPAKs( grPAObs_Ks_v22 );
    FixPAKs( grPAObs_Ks_v24 );
    FixPAKs( grPAObs_Ks_v26 );
    FixPAKs( grPAObs_Ks_v22sub );
    FixPAKs( grPAObs_Ks_v24sub );
    FixPAKs( grPAObs_Ks_v2Gap  );


    TGraphErrors * grPABkg_Ks_v22    = (TGraphErrors*) fPA_Ks ->Get("grBkg_pT2_0_8");
    TGraphErrors * grPABkg_Ks_v24    = (TGraphErrors*) fPA_Ks ->Get("grBkg_pT2_1_8");
    TGraphErrors * grPABkg_Ks_v26    = (TGraphErrors*) fPA_Ks ->Get("grBkg_pT2_2_8");
    TGraphErrors * grPABkg_Ks_v22sub = (TGraphErrors*) fPA_Ks ->Get("grBkg_V2sub2_8");
    TGraphErrors * grPABkg_Ks_v24sub = (TGraphErrors*) fPA_Ks ->Get("grBkg_V2sub4_8");
    TGraphErrors * grPABkg_Ks_v2Gap  = (TGraphErrors*) fPA_Ks ->Get("grBkg_pTGap2_8");

    grPABkg_Ks_v24   ->SetMarkerStyle(kFullSquare);
    grPABkg_Ks_v26   ->SetMarkerStyle(kFullCross);
    grPABkg_Ks_v24sub->SetMarkerStyle(kOpenSquare);
    grPABkg_Ks_v24   ->SetMarkerSize(2);
    grPABkg_Ks_v26   ->SetMarkerSize(2);
    grPABkg_Ks_v24sub->SetMarkerSize(2);

    grPABkg_Ks_v24   ->SetMarkerColor(kBlue);
    grPABkg_Ks_v26   ->SetMarkerColor(kBlue);
    grPABkg_Ks_v24sub->SetMarkerColor(kBlue);
    grPABkg_Ks_v24   ->SetLineColor(kBlue);
    grPABkg_Ks_v26   ->SetLineColor(kBlue);
    grPABkg_Ks_v24sub->SetLineColor(kBlue);

    FixPAKs( grPABkg_Ks_v22 );
    FixPAKs( grPABkg_Ks_v24 );
    FixPAKs( grPABkg_Ks_v26 );
    FixPAKs( grPABkg_Ks_v22sub );
    FixPAKs( grPABkg_Ks_v24sub );
    FixPAKs( grPABkg_Ks_v2Gap  );



    // PA Lm
    TGraphErrors * grPA_Lm_v22    = (TGraphErrors*) fPA_Lm ->Get("grSig_pT2_0_8");
    TGraphErrors * grPA_Lm_v24    = (TGraphErrors*) fPA_Lm ->Get("grSig_pT2_1_8");
    TGraphErrors * grPA_Lm_v26    = (TGraphErrors*) fPA_Lm ->Get("grSig_pT2_2_8");
    TGraphErrors * grPA_Lm_v22sub = (TGraphErrors*) fPA_Lm ->Get("grSig_V2sub2_8");
    TGraphErrors * grPA_Lm_v24sub = (TGraphErrors*) fPA_Lm ->Get("grSig_V2sub4_8");
    TGraphErrors * grPA_Lm_v2Gap  = (TGraphErrors*) fPA_Lm ->Get("grSig_pTGap2_8");

    grPA_Lm_v24   ->SetMarkerStyle(kFullSquare);
    grPA_Lm_v26   ->SetMarkerStyle(kFullCross);
    grPA_Lm_v24sub->SetMarkerStyle(kOpenCircle);
    grPA_Lm_v24   ->SetMarkerSize(2);
    grPA_Lm_v26   ->SetMarkerSize(2);
    grPA_Lm_v24sub->SetMarkerSize(2);


    grPA_Lm_v24   ->SetMarkerColor(kRed);
    grPA_Lm_v26   ->SetMarkerColor(kRed);
    grPA_Lm_v24sub->SetMarkerColor(kRed);
    grPA_Lm_v24   ->SetLineColor(kRed);
    grPA_Lm_v26   ->SetLineColor(kRed);
    grPA_Lm_v24sub->SetLineColor(kRed);

    grPA_Lm_v2Gap ->SetMarkerStyle(kOpenCircle);
    grPA_Lm_v2Gap ->SetMarkerSize(2);
    grPA_Lm_v2Gap ->SetMarkerColor(kRed);
    grPA_Lm_v2Gap ->SetLineColor(kRed);

    FixPALm( grPA_Lm_v22 );
    FixPALm( grPA_Lm_v24 );
    FixPALm( grPA_Lm_v26 );
    FixPALm( grPA_Lm_v22sub );
    FixPALm( grPA_Lm_v24sub );
    FixPALm( grPA_Lm_v2Gap  );

    TGraphErrors * grPAObs_Lm_v22    = (TGraphErrors*) fPA_Lm ->Get("grObs_pT2_0_8");
    TGraphErrors * grPAObs_Lm_v24    = (TGraphErrors*) fPA_Lm ->Get("grObs_pT2_1_8");
    TGraphErrors * grPAObs_Lm_v26    = (TGraphErrors*) fPA_Lm ->Get("grObs_pT2_2_8");
    TGraphErrors * grPAObs_Lm_v22sub = (TGraphErrors*) fPA_Lm ->Get("grObs_V2sub2_8");
    TGraphErrors * grPAObs_Lm_v24sub = (TGraphErrors*) fPA_Lm ->Get("grObs_V2sub4_8");
    TGraphErrors * grPAObs_Lm_v2Gap  = (TGraphErrors*) fPA_Lm ->Get("grObs_pTGap2_8");

    grPAObs_Lm_v24   ->SetMarkerStyle(kFullSquare);
    grPAObs_Lm_v26   ->SetMarkerStyle(kFullCross);
    grPAObs_Lm_v24sub->SetMarkerStyle(kOpenSquare);
    grPAObs_Lm_v24   ->SetMarkerSize(2);
    grPAObs_Lm_v26   ->SetMarkerSize(2);
    grPAObs_Lm_v24sub->SetMarkerSize(2);

    grPAObs_Lm_v24   ->SetMarkerColor(kRed);
    grPAObs_Lm_v26   ->SetMarkerColor(kRed);
    grPAObs_Lm_v24sub->SetMarkerColor(kRed);
    grPAObs_Lm_v24   ->SetLineColor(kRed);
    grPAObs_Lm_v26   ->SetLineColor(kRed);
    grPAObs_Lm_v24sub->SetLineColor(kRed);

    FixPALm( grPAObs_Lm_v22 );
    FixPALm( grPAObs_Lm_v24 );
    FixPALm( grPAObs_Lm_v26 );
    FixPALm( grPAObs_Lm_v22sub );
    FixPALm( grPAObs_Lm_v24sub );
    FixPALm( grPAObs_Lm_v2Gap  );

    TGraphErrors * grPABkg_Lm_v22    = (TGraphErrors*) fPA_Lm ->Get("grBkg_pT2_0_8");
    TGraphErrors * grPABkg_Lm_v24    = (TGraphErrors*) fPA_Lm ->Get("grBkg_pT2_1_8");
    TGraphErrors * grPABkg_Lm_v26    = (TGraphErrors*) fPA_Lm ->Get("grBkg_pT2_2_8");
    TGraphErrors * grPABkg_Lm_v22sub = (TGraphErrors*) fPA_Lm ->Get("grBkg_V2sub2_8");
    TGraphErrors * grPABkg_Lm_v24sub = (TGraphErrors*) fPA_Lm ->Get("grBkg_V2sub4_8");
    TGraphErrors * grPABkg_Lm_v2Gap  = (TGraphErrors*) fPA_Lm ->Get("grBkg_pTGap2_8");

    grPABkg_Lm_v24   ->SetMarkerStyle(kFullSquare);
    grPABkg_Lm_v26   ->SetMarkerStyle(kFullCross);
    grPABkg_Lm_v24sub->SetMarkerStyle(kOpenSquare);
    grPABkg_Lm_v24   ->SetMarkerSize(2);
    grPABkg_Lm_v26   ->SetMarkerSize(2);
    grPABkg_Lm_v24sub->SetMarkerSize(2);

    grPABkg_Lm_v24   ->SetMarkerColor(kRed);
    grPABkg_Lm_v26   ->SetMarkerColor(kRed);
    grPABkg_Lm_v24sub->SetMarkerColor(kRed);
    grPABkg_Lm_v24   ->SetLineColor(kRed);
    grPABkg_Lm_v26   ->SetLineColor(kRed);
    grPABkg_Lm_v24sub->SetLineColor(kRed);

    FixPALm( grPABkg_Lm_v22 );
    FixPALm( grPABkg_Lm_v24 );
    FixPALm( grPABkg_Lm_v26 );
    FixPALm( grPABkg_Lm_v22sub );
    FixPALm( grPABkg_Lm_v24sub );
    FixPALm( grPABkg_Lm_v2Gap  );

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
        {grPA_Ks_v22,       "K_{s}^{0} v_{2}^{sig}{2}"},
        {grPA_Ks_v24,       "K_{s}^{0} v_{2}^{sig}{4}"},
        {grPA_Ks_v26,       "K_{s}^{0} v_{2}^{sig}{6}"},
        {grPA_Ks_v22sub,    "K_{s}^{0} v_{2}^{sig}{2, sub-event}"},
        {grPA_Ks_v24sub,    "K_{s}^{0} v_{2}^{sig}{4, sub-event}"},
        {grPA_Ks_v2Gap,     "K_{s}^{0} v_{2}^{sig}{2, |#Delta#eta|>2.}"},

        {grPAObs_Ks_v22,    "K_{s}^{0} v_{2}^{obs}{2}"},
        {grPAObs_Ks_v24,    "K_{s}^{0} v_{2}^{obs}{4}"},
        {grPAObs_Ks_v26,    "K_{s}^{0} v_{2}^{obs}{6}"},
        {grPAObs_Ks_v22sub, "K_{s}^{0} v_{2}^{obs}{2, sub-event}"},
        {grPAObs_Ks_v24sub, "K_{s}^{0} v_{2}^{obs}{4, sub-event}"},
        {grPAObs_Ks_v2Gap,  "K_{s}^{0} v_{2}^{obs}{2, |#Delta#eta|>2.}"},

        {grPABkg_Ks_v22,    "K_{s}^{0} v_{2}^{bkg}{2}"},
        {grPABkg_Ks_v24,    "K_{s}^{0} v_{2}^{bkg}{4}"},
        {grPABkg_Ks_v26,    "K_{s}^{0} v_{2}^{bkg}{6}"},
        {grPABkg_Ks_v22sub, "K_{s}^{0} v_{2}^{bkg}{2, sub-event}"},
        {grPABkg_Ks_v24sub, "K_{s}^{0} v_{2}^{bkg}{4, sub-event}"},
        {grPABkg_Ks_v2Gap,  "K_{s}^{0} v_{2}^{bkg}{2, |#Delta#eta|>2.}"},

        {grPA_Lm_v22,       "#Lambda v_{2}^{sig}{2}"},
        {grPA_Lm_v24,       "#Lambda v_{2}^{sig}{4}"},
        {grPA_Lm_v26,       "#Lambda v_{2}^{sig}{6}"},
        {grPA_Lm_v22sub,    "#Lambda v_{2}^{sig}{2, sub-event}"},
        {grPA_Lm_v24sub,    "#Lambda v_{2}^{sig}{4, sub-event}"},
        {grPA_Lm_v2Gap,     "#Lambda v_{2}^{sig}{2, |#Delta#eta|>2.}"},

        {grPAObs_Lm_v22,    "#Lambda v_{2}^{obs}{2}"},
        {grPAObs_Lm_v24,    "#Lambda v_{2}^{obs}{4}"},
        {grPAObs_Lm_v26,    "#Lambda v_{2}^{obs}{6}"},
        {grPAObs_Lm_v22sub, "#Lambda v_{2}^{obs}{2, sub-event}"},
        {grPAObs_Lm_v24sub, "#Lambda v_{2}^{obs}{4, sub-event}"},
        {grPAObs_Lm_v2Gap,  "#Lambda v_{2}^{obs}{2, |#Delta#eta|>2.}"},

        {grPABkg_Lm_v22,    "#Lambda v_{2}^{bkg}{2}"},
        {grPABkg_Lm_v24,    "#Lambda v_{2}^{bkg}{4}"},
        {grPABkg_Lm_v26,    "#Lambda v_{2}^{bkg}{6}"},
        {grPABkg_Lm_v22sub, "#Lambda v_{2}^{bkg}{2, sub-event}"},
        {grPABkg_Lm_v24sub, "#Lambda v_{2}^{bkg}{4, sub-event}"},
        {grPABkg_Lm_v2Gap,  "#Lambda v_{2}^{bkg}{2, |#Delta#eta|>2.}"},

        {gr_HIN17_003_pPb_v2sub_Ks,  "K_{s}^{0} v_{2}^{sub} HIN-17-003"},
        {gr_HIN17_003_PbPb_v2sub_Ks, "K_{s}^{0} v_{2} HIN-17-003"},
        {gr_HIN17_003_pPb_v2sub_Lm,  "#Lambda v_{2}^{sub} HIN-17-003"},
        {gr_HIN17_003_PbPb_v2sub_Lm, "#Lambda v_{2} HIN-17-003"},

        {gr_ALICE_AA_v2_Ks_30_40,     "K_{s}^{0} ALICE v_{2} 30-40%"},
        {gr_ALICE_AA_v2_Ks_40_50,     "K_{s}^{0} ALICE v_{2} 40-50%"},
        {gr_ALICE_AA_v2_Lm_30_40,     "#Lambda ALICE v_{2} 30-40%"},
        {gr_ALICE_AA_v2_Lm_40_50,     "#Lambda ALICE v_{2} 40-50%"},
    };
    ////
    TCanvas * cPA = MakeCanvas("cPA", "cPA", 800, 600);;
    TH2D * hframePt = new TH2D("hframePt", "", 1, 0, 8.5, 1, -0.05, 0.75);
    InitHist(hframePt, "p_{T}", "v_{2}");

	TLatex latexS;
	latexS.SetTextFont(43);
	latexS.SetTextSize(28);
	latexS.SetTextAlign(13);

    // pPb Obs
    hframePt->GetYaxis()->SetTitle("v_{2}^{obs}{4}");
    hframePt->Draw();

    TLegend * legPA = new TLegend(0.16, 0.70, 0.35 , 0.94);
    legPA->SetFillColor(kWhite);
    legPA->SetTextFont(42);
    legPA->SetTextSize(0.05);
    legPA->SetBorderSize(0);

    drawGr(grPAObs_Ks_v24, legPA);
    drawGr(grPAObs_Lm_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, "185 #leq N_{trk}^{offline} < 250");
    cPA->SaveAs("pPb_Obs.pdf");
    //
    // pPb Obs v24sub
    hframePt->GetYaxis()->SetTitle("v_{2}^{obs}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    drawGr(grPAObs_Ks_v24sub, legPA);
    drawGr(grPAObs_Lm_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, "185 #leq N_{trk}^{offline} < 250");
    cPA->SaveAs("pPb_Obs_v24sub.pdf");

    // pPb Ks 2part
    hframePt->GetYaxis()->SetTitle("v_{2}{2, |#Delta#eta|>2.}");
    hframePt->Draw();
    legPA->Clear();

    drawGr(gr_HIN17_003_pPb_v2sub_Ks, legPA);
    drawGr(grPA_Ks_v2Gap, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, "185 #leq N_{trk}^{offline} < 250");
    cPA->SaveAs("pPb_Ks_2part.pdf");

    // pPb Lm 2part
    hframePt->GetYaxis()->SetTitle("v_{2}{2, |#Delta#eta|>2.}");
    hframePt->Draw();
    legPA->Clear();

    drawGr(gr_HIN17_003_pPb_v2sub_Lm, legPA);
    drawGr(grPA_Lm_v2Gap, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, "185 #leq N_{trk}^{offline} < 250");
    cPA->SaveAs("pPb_Lm_2part.pdf");

    // pPb Bkg
    hframePt->GetYaxis()->SetTitle("v_{2}^{bkg}");
    hframePt->Draw();
    legPA->Clear();

    drawGr(grPABkg_Ks_v24, legPA);
    drawGr(grPABkg_Lm_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, "185 #leq N_{trk}^{offline} < 250");
    cPA->SaveAs("pPb_Bkg.pdf");

    // pPb Bkg sub
    hframePt->GetYaxis()->SetTitle("v_{2}^{bkg}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    drawGr(grPABkg_Ks_v24sub, legPA);
    drawGr(grPABkg_Lm_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, "185 #leq N_{trk}^{offline} < 250");
    cPA->SaveAs("pPb_Bkg_v24sub.pdf");

    // pPb Ks
    hframePt->GetYaxis()->SetTitle("v_{2}{4}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Ks_v24, kRed);
    setColor(grPABkg_Ks_v24, kBlue);
    drawGr(grPAObs_Ks_v24, legPA);
    drawGr(grPABkg_Ks_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, "185 #leq N_{trk}^{offline} < 250");
    cPA->SaveAs("pPb_Ks_v24.pdf");

    // pPb Ks sub
    hframePt->GetYaxis()->SetTitle("v_{2}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Ks_v24sub, kRed);
    setColor(grPABkg_Ks_v24sub, kBlue);
    drawGr(grPAObs_Ks_v24sub, legPA);
    drawGr(grPABkg_Ks_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, "185 #leq N_{trk}^{offline} < 250");
    cPA->SaveAs("pPb_Ks_v24sub.pdf");

    // pPb Lm
    hframePt->GetYaxis()->SetTitle("v_{2}{4}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm_v24, kRed);
    setColor(grPABkg_Lm_v24, kBlue);
    drawGr(grPAObs_Lm_v24, legPA);
    drawGr(grPABkg_Lm_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, "185 #leq N_{trk}^{offline} < 250");
    cPA->SaveAs("pPb_Lm_v24.pdf");

    // pPb Lm sub
    hframePt->GetYaxis()->SetTitle("v_{2}{4, sub-event}");
    hframePt->Draw();
    legPA->Clear();

    setColor(grPAObs_Lm_v24sub, kRed);
    setColor(grPABkg_Lm_v24sub, kBlue);
    drawGr(grPAObs_Lm_v24sub, legPA);
    drawGr(grPABkg_Lm_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, "185 #leq N_{trk}^{offline} < 250");
    cPA->SaveAs("pPb_Lm_v24sub.pdf");

    // pPb sig
    hframePt->GetYaxis()->SetTitle("v_{2}^{sig}");
    hframePt->Draw();
    legPA->Clear();

    drawGr(grPA_Ks_v24, legPA);
    drawGr(grPA_Lm_v24, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, "185 #leq N_{trk}^{offline} < 250");
    cPA->SaveAs("pPb_Sig.pdf");

    // pPb sig sub
    hframePt->GetYaxis()->SetTitle("v_{2}^{sig}");
    hframePt->Draw();
    legPA->Clear();

    drawGr(grPA_Ks_v24sub, legPA);
    drawGr(grPA_Lm_v24sub, legPA);
    legPA->Draw();
	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, "185 #leq N_{trk}^{offline} < 250");
    cPA->SaveAs("pPb_Sig_v24sub.pdf");

    //////////////////////////////////////// manual plot final results
    // pPb Ks
    TCanvas * cResult= MakeCanvas("cResult", "cResult", 800, 600);;
    TH2D * hframePtResult = new TH2D("hframePtResult", "", 1, 0, 8.5, 1, -0.05, 0.38);
    InitHist(hframePtResult, "p_{T}", "v_{2}");

    hframePtResult->Draw();
    setColor(grPA_Ks_v26, kRed);

    TGraphErrors * grPA_Ks_v24subsys = getGrSys(grPA_Ks_v24sub, sys_pPb_Ks, 3003);
    TGraphErrors * grPA_Ks_v24sys = getGrSys(grPA_Ks_v24, sys_pPb_Ks, 3003);
    TGraphErrors * grPA_Ks_v26sys = getGrSys(grPA_Ks_v26, sys_pPb_Ks, 3001);

    gr_sys_HIN17_003_pPb_v2sub_Ks->SetFillColor(3005);
    setColor(gr_HIN17_003_pPb_v2sub_Ks, kBlack);

    gr_sys_HIN17_003_pPb_v2sub_Ks->Draw("[]2");
    grPA_Ks_v24subsys->Draw("[]2");
    grPA_Ks_v24sys->Draw("[]2");
    grPA_Ks_v26sys->Draw("[]2");

    gr_HIN17_003_pPb_v2sub_Ks->Draw("psame");
    grPA_Ks_v24sub->Draw("psame");
    grPA_Ks_v24->Draw("psame");
    grPA_Ks_v26->Draw("psame");

    TLegend * leg1 = new TLegend(0.16, 0.70, 0.35 , 0.94);
    leg1->SetFillColor(kWhite);
    leg1->SetTextFont(42);
    leg1->SetTextSize(0.04);
    leg1->SetBorderSize(0);

    leg1->AddEntry(gr_HIN17_003_pPb_v2sub_Ks, "K_{s} v_{2}^{sub}", "p");
    leg1->AddEntry(grPA_Ks_v24, "K_{s} v_{2}{4}", "p");
    leg1->AddEntry(grPA_Ks_v24sub, "K_{s} v_{2}{4,sub-event}", "p");
    leg1->AddEntry(grPA_Ks_v26, "K_{s} v_{2}{6}", "p");
    leg1->Draw("same");

	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, "185 #leq N_{trk}^{offline} < 250");
    cResult->SaveAs("F_pPb_Ks.pdf");

    // pPb Ks v24/v22
    leg1->Clear();

    TH2D * hframeRatioResult = new TH2D("hframeRatioResult", "", 1, 0, 8.5, 1, -0.05, 1.9);
    InitHist(hframeRatioResult, "p_{T}", "Ratio");
    hframeRatioResult->Draw();

    TGraphErrors* grPA_Ks_ratio = getRatio( grPA_Ks_v24, gr_HIN17_003_pPb_v2sub_Ks);
    TGraphErrors* grPA_Ks_ratio_sys = getGrSys( grPA_Ks_ratio, sys_pPb_Ks, 3003 );

    TGraphErrors* grPA_Ks_sub_ratio = getRatio( grPA_Ks_v24sub, gr_HIN17_003_pPb_v2sub_Ks);
    setColor(grPA_Ks_sub_ratio, kRed);
    TGraphErrors* grPA_Ks_sub_ratio_sys = getGrSys( grPA_Ks_sub_ratio, sys_pPb_Ks, 3001 );

    grPA_Ks_ratio_sys->Draw("[]2");
    grPA_Ks_sub_ratio_sys->Draw("[]2");
    grPA_Ks_ratio->Draw("psame");
    grPA_Ks_sub_ratio->Draw("psame");

    leg1->AddEntry(grPA_Ks_ratio, "K_{s}^{0} v_{2}{4}/v_{2}{|#Delta#eta|>2}", "p");
    leg1->AddEntry(grPA_Ks_sub_ratio, "K_{s}^{0} v_{2}{4, sub-event}/v_{2}{|#Delta#eta|>2}", "p");
    leg1->Draw("same");

    cResult->SaveAs("F_pPb_Ks_ratio.pdf");

    // pPb Lm
    leg1->Clear();
    hframePtResult->Draw();
    setColor(grPA_Lm_v24, kBlue);
    setColor(grPA_Lm_v26, kRed);


    TGraphErrors * grPA_Lm_v24subsys = getGrSys(grPA_Lm_v24sub, sys_pPb_Lm, 3003);
    TGraphErrors * grPA_Lm_v24sys = getGrSys(grPA_Lm_v24, sys_pPb_Lm, 3003);
    TGraphErrors * grPA_Lm_v26sys = getGrSys(grPA_Lm_v26, sys_pPb_Lm, 3001);

    gr_sys_HIN17_003_pPb_v2sub_Lm->Draw("[]2");
    grPA_Lm_v24subsys->Draw("[]2");
    grPA_Lm_v24sys->Draw("[]2");
    grPA_Lm_v26sys->Draw("[]2");

    setColor(grPA_Lm_v24sub, kBlue);

    gr_HIN17_003_pPb_v2sub_Lm->Draw("psame");
    grPA_Lm_v24sub->Draw("psame");
    grPA_Lm_v24->Draw("psame");
    grPA_Lm_v26->Draw("psame");

    leg1->AddEntry(gr_HIN17_003_pPb_v2sub_Lm, "#Lambda v_{2}^{sub}", "p");
    leg1->AddEntry(grPA_Lm_v24, "#Lambda v_{2}{4}", "p");
    leg1->AddEntry(grPA_Lm_v24sub, "#Lambda v_{2}{4, sub-event}", "p");
    leg1->AddEntry(grPA_Lm_v26, "#Lambda v_{2}{6}", "p");
    leg1->Draw("same");

	latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
	latexS.DrawLatexNDC(0.60, 0.80, "185 #leq N_{trk}^{offline} < 250");
    cResult->SaveAs("F_pPb_Lm.pdf");

    // pPb Lm ratio v24/v22
    leg1->Clear();
    hframeRatioResult->Draw();

    TGraphErrors* grPA_Lm_ratio = getRatio( grPA_Lm_v24, gr_HIN17_003_pPb_v2sub_Lm);
    TGraphErrors* grPA_Lm_ratio_sys = getGrSys( grPA_Lm_ratio, sys_pPb_Lm, 3003 );

    TGraphErrors* grPA_Lm_sub_ratio = getRatio( grPA_Lm_v24sub, gr_HIN17_003_pPb_v2sub_Lm);
    setColor(grPA_Lm_sub_ratio, kRed);
    TGraphErrors* grPA_Lm_sub_ratio_sys = getGrSys( grPA_Lm_sub_ratio, sys_pPb_Lm, 3001 );

    grPA_Lm_ratio_sys->Draw("[]2");
    grPA_Lm_sub_ratio_sys->Draw("[]2");

    grPA_Lm_ratio->Draw("psame");
    grPA_Lm_sub_ratio->Draw("psame");

    leg1->AddEntry(grPA_Lm_ratio, "#Lambda v_{2}{4}/v_{2}{|#Delta#eta|>2}", "p");
    leg1->AddEntry(grPA_Lm_sub_ratio, "#Lambda v_{2}{4, sub-event}/v_{2}{|#Delta#eta|>2}", "p");
    leg1->Draw("same");

    cResult->SaveAs("F_pPb_Lm_ratio.pdf");

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

