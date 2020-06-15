

#include "../../style.h"
#include "theory.h"
#include "pPb_header.h"

void plotFinalpPb()
{
    SetStyle();

    TFile * fPA_Ks = new TFile("../cumudiff/pPb_Ks2_merged_corrected.root");
    TFile * fPA_Lm = new TFile("../cumudiff/pPb_Lm2_merged_corrected.root");
    TFile * fPA_H  = new TFile("../cumudiff/pPb_H_merged_corrected.root");
//    TFile * fPA_H  = new TFile("../cumudiff/pPb_H_veto10_merged2_corrected.root");

    CumuGraph grKs(fPA_Ks);
    CumuGraph grLm(fPA_Lm);
    CumuGraph grH (fPA_H);

    TFile * fPA_SP = new TFile("../cumudiff/V0SP.root");

    SteveGraphSP grSP(fPA_SP);
    grSP.SetSys();

    grH .ReplaceX(grSP.grSP_H);
    grKs.ReplaceX(grSP.grSP_Ks_Sig);
    grLm.ReplaceX(grSP.grSP_Lm_Sig);

    grH .SetSys();
    grKs.SetSys();
    grLm.SetSys();

    grSP.DropPoints();

    grH.DropPoints(1);
    grLm.DropPoints(3);

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

    TLatex latexS;
    latexS.SetTextFont(43);
    latexS.SetTextSize(22);
    latexS.SetTextAlign(13);

    TLine line1(0.01, 1., 8.5, 1.);

    TCanvas * cpPbV2 = MakeCanvas("cpPbV2", "cpPbV2", 1400, 400);
    splitCanv4(cpPbV2);

    TCanvas * cpPbV2_1 = MakeCanvas("cpPbV2_1", "cpPbV2_1", 1400, 400);
    splitCanv4(cpPbV2_1);

    TH2D * hframe_pt = new TH2D("hframe_pt", "hframe_pt", 1, 0.01, 8.5, 1, 0, 0.32);
    InitHist(hframe_pt, "p_{T}", "v_{2}");
    hframe_pt->GetYaxis()->SetTitleOffset(1.0);
    hframe_pt->GetXaxis()->SetTitleOffset(0.90);

    // ch v2
    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_pt->Draw();

        setGr(grSP.grSP_H[c]->vn_Full_PosEtaEP, kOpenCircle, kBlue, 2.);
        setGr(grSP.grSP_H[c]->vn_Full_NegEtaEP, kOpenCircle, kRed,  2.);

        grSP.grSP_H[c]->vn_sys_Full_PosEtaEP->SetFillColor(3003);
        grSP.grSP_H[c]->vn_sys_Full_NegEtaEP->SetFillColor(3001);

        grSP.grSP_H[c]->vn_sys_Full_PosEtaEP->Draw("[]2");
        grSP.grSP_H[c]->vn_sys_Full_NegEtaEP->Draw("[]2");

        grSP.grSP_H[c]->vn_Full_PosEtaEP->Draw("psame");
        grSP.grSP_H[c]->vn_Full_NegEtaEP->Draw("psame");

        setGr(grH.gr_v24[c], kOpenStar,  kBlue, 2.);
        setGr(grH.gr_v26[c], kFullCross, kRed,  2.);

        grH.grSys_v24[c]->SetFillColor(3003);
        grH.grSys_v26[c]->SetFillColor(3001);

        grH.grSys_v24[c]->Draw("[]2");
        grH.grSys_v26[c]->Draw("[]2");

        grH.gr_v24[c]->Draw("psame");
        grH.gr_v26[c]->Draw("psame");
    }
    cpPbV2->cd(1);
    latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS} Charge hadron");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);

    TLegend * legCh0 = new TLegend(0.16, 0.68, 0.50, 0.82);
    legCh0->SetFillColor(kWhite);
    legCh0->SetTextFont(42);
    legCh0->SetTextSize(0.05);
    legCh0->SetBorderSize(0);

    legCh0->AddEntry(grSP.grSP_H[6]->vn_Full_PosEtaEP, "v_{2}{p-SP}",  "p");
    legCh0->AddEntry(grSP.grSP_H[6]->vn_Full_NegEtaEP, "v_{2}{Pb-SP}", "p");

    TLegend * legCh1 = new TLegend(0.10, 0.68, 0.50, 0.82);
    legCh1->SetFillColor(kWhite);
    legCh1->SetTextFont(42);
    legCh1->SetTextSize(0.05);
    legCh1->SetBorderSize(0);

    legCh1->AddEntry(grH.gr_v24[6], "v_{2}{4}",     "p");
    legCh1->AddEntry(grH.gr_v26[6], "v_{2}{6}",     "p");

    legCh0->Draw();

    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);
    legCh1->Draw();
    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);
    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);

    cpPbV2->SaveAs("pPbV2_ch.pdf");

    // Ks v2
    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_pt->Draw();

        setGr(grSP.grSP_Ks_Sig[c]->vn_Full_PosEtaEP, kOpenCircle, kBlue, 2.);
        setGr(grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP, kOpenCircle, kRed,  2.);

        grSP.grSP_Ks_Sig[c]->vn_sys_Full_PosEtaEP->SetFillColor(3003);
        grSP.grSP_Ks_Sig[c]->vn_sys_Full_NegEtaEP->SetFillColor(3001);

        grSP.grSP_Ks_Sig[c]->vn_sys_Full_PosEtaEP->Draw("[]2");
        grSP.grSP_Ks_Sig[c]->vn_sys_Full_NegEtaEP->Draw("[]2");

        grSP.grSP_Ks_Sig[c]->vn_Full_PosEtaEP->Draw("psame");
        grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP->Draw("psame");

        setGr(grKs.gr_v24[c], kOpenStar,  kBlue, 2.);
        setGr(grKs.gr_v26[c], kFullCross, kRed,  2.);

        grKs.grSys_v24[c]->SetFillColor(3003);
        grKs.grSys_v26[c]->SetFillColor(3001);

        grKs.grSys_v24[c]->Draw("[]2");
        grKs.grSys_v26[c]->Draw("[]2");

        grKs.gr_v24[c]->Draw("psame");
        grKs.gr_v26[c]->Draw("psame");
    }
    cpPbV2->cd(1);
    latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS} K_{S}^{0}");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);

    TLegend * legKs0 = new TLegend(0.16, 0.68, 0.50, 0.82);
    legKs0->SetFillColor(kWhite);
    legKs0->SetTextFont(42);
    legKs0->SetTextSize(0.05);
    legKs0->SetBorderSize(0);

    legKs0->AddEntry(grSP.grSP_Ks_Sig[6]->vn_Full_PosEtaEP, "v_{2}{p-SP}",  "p");
    legKs0->AddEntry(grSP.grSP_Ks_Sig[6]->vn_Full_NegEtaEP, "v_{2}{Pb-SP}", "p");

    TLegend * legKs1 = new TLegend(0.10, 0.68, 0.50, 0.82);
    legKs1->SetFillColor(kWhite);
    legKs1->SetTextFont(42);
    legKs1->SetTextSize(0.05);
    legKs1->SetBorderSize(0);

    legKs1->AddEntry(grH.gr_v24[6], "v_{2}{4}",     "p");
    legKs1->AddEntry(grH.gr_v26[6], "v_{2}{6}",     "p");

    legKs0->Draw();

    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);
    legKs1->Draw();
    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);
    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);

    cpPbV2->SaveAs("pPbV2_Ks.pdf");

    // Lm v2
    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_pt->Draw();

        setGr(grSP.grSP_Lm_Sig[c]->vn_Full_PosEtaEP, kOpenCircle, kBlue, 2.);
        setGr(grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP, kOpenCircle, kRed,  2.);

        grSP.grSP_Lm_Sig[c]->vn_sys_Full_PosEtaEP->SetFillColor(3003);
        grSP.grSP_Lm_Sig[c]->vn_sys_Full_NegEtaEP->SetFillColor(3001);

        grSP.grSP_Lm_Sig[c]->vn_sys_Full_PosEtaEP->Draw("[]2");
        grSP.grSP_Lm_Sig[c]->vn_sys_Full_NegEtaEP->Draw("[]2");

        grSP.grSP_Lm_Sig[c]->vn_Full_PosEtaEP->Draw("psame");
        grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP->Draw("psame");

        setGr(grLm.gr_v24[c], kOpenStar,  kBlue, 2.);
        setGr(grLm.gr_v26[c], kFullCross, kRed,  2.);

        grLm.grSys_v24[c]->SetFillColor(3003);
        grLm.grSys_v26[c]->SetFillColor(3001);

        grLm.grSys_v24[c]->Draw("[]2");
        grLm.grSys_v26[c]->Draw("[]2");

        grLm.gr_v24[c]->Draw("psame");
        grLm.gr_v26[c]->Draw("psame");
    }

    cpPbV2->cd(1);
    latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS} #Lambda");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);

    TLegend * legLm0 = new TLegend(0.16, 0.68, 0.50, 0.82);
    legLm0->SetFillColor(kWhite);
    legLm0->SetTextFont(42);
    legLm0->SetTextSize(0.05);
    legLm0->SetBorderSize(0);

    legLm0->AddEntry(grSP.grSP_Lm_Sig[6]->vn_Full_PosEtaEP, "v_{2}{p-SP}",  "p");
    legLm0->AddEntry(grSP.grSP_Lm_Sig[6]->vn_Full_NegEtaEP, "v_{2}{Pb-SP}", "p");

    TLegend * legLm1 = new TLegend(0.10, 0.68, 0.40, 0.82);
    legLm1->SetFillColor(kWhite);
    legLm1->SetTextFont(42);
    legLm1->SetTextSize(0.05);
    legLm1->SetBorderSize(0);

    legLm1->AddEntry(grH.gr_v24[6], "v_{2}{4}",     "p");
    legLm1->AddEntry(grH.gr_v26[6], "v_{2}{6}",     "p");

    legLm0->Draw();

    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);
    legLm1->Draw();
    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);
    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);

    cpPbV2->SaveAs("pPbV2_Lm.pdf");

    // fluctuation
    TH2D * hframe_fluct = new TH2D("hframe_fluct", "hframe_fluct", 1, 0.01, 8.5, 1, 0.05, 1.5);
    InitHist(hframe_fluct, "p_{T}", "Fluctuation");
    hframe_fluct->GetYaxis()->SetTitleOffset(1.0);
    hframe_fluct->GetXaxis()->SetTitleOffset(0.90);

    TGraphErrors * gChF[10] = {};
    TGraphErrors * gKsF[10] = {};
    TGraphErrors * gLmF[10] = {};

    TGraphErrors * gCh6[10] = {};
    TGraphErrors * gKs6[10] = {};
    TGraphErrors * gLm6[10] = {};

    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_fluct->Draw();
        line1.Draw();

        gChF[c] = getFluct( grSP.grSP_H[c]->vn_Full_PosEtaEP     , grH .gr_v24[c] );
        gKsF[c] = getFluct( grSP.grSP_Ks_Sig[c]->vn_Full_PosEtaEP, grKs.gr_v24[c] );
        gLmF[c] = getFluct( grSP.grSP_Lm_Sig[c]->vn_Full_PosEtaEP, grLm.gr_v24[c] );

        gCh6[c] = getFluct( grSP.grSP_H[c]->vn_Full_PosEtaEP     , grH .gr_v26[c] );
        gKs6[c] = getFluct( grSP.grSP_Ks_Sig[c]->vn_Full_PosEtaEP, grKs.gr_v26[c] );
        gLm6[c] = getFluct( grSP.grSP_Lm_Sig[c]->vn_Full_PosEtaEP, grLm.gr_v26[c] );

        gChF[c]->SetMarkerStyle(kOpenCircle);
        gChF[c]->SetMarkerColor(kBlack);
        gChF[c]->SetLineColor  (kBlack);
        gChF[c]->SetMarkerSize(2.);

        gCh6[c]->SetMarkerStyle(kFullCircle);
        gCh6[c]->SetMarkerColor(kBlack);
        gCh6[c]->SetLineColor  (kBlack);
        gCh6[c]->SetMarkerSize(2.);

        gKsF[c]->SetMarkerStyle(kOpenSquare);
        gKsF[c]->SetMarkerColor(kBlue);
        gKsF[c]->SetLineColor  (kBlue);
        gKsF[c]->SetMarkerSize(2.);

        gKs6[c]->SetMarkerStyle(kFullSquare);
        gKs6[c]->SetMarkerColor(kBlue);
        gKs6[c]->SetLineColor  (kBlue);
        gKs6[c]->SetMarkerSize(2.);

        gLmF[c]->SetMarkerStyle(kOpenCircle);
        gLmF[c]->SetMarkerColor(kRed);
        gLmF[c]->SetLineColor  (kRed);
        gLmF[c]->SetMarkerSize(2.);

        gLm6[c]->SetMarkerStyle(kFullCircle);
        gLm6[c]->SetMarkerColor(kRed);
        gLm6[c]->SetLineColor  (kRed);
        gLm6[c]->SetMarkerSize(2.);

        gChF[c]->Draw("psame");
        gKsF[c]->Draw("psame");
        gLmF[c]->Draw("psame");

        cpPbV2_1->cd(c-5);
        hframe_fluct->Draw();
        line1.Draw();
        gChF[c]->Draw("psame");
        gCh6[c]->Draw("psame");
    }

    cpPbV2->cd(1);
    latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);

    TLegend * legFl = new TLegend(0.56, 0.18, 0.80, 0.42);
    legFl->SetFillColor(kWhite);
    legFl->SetTextFont(42);
    legFl->SetTextSize(0.05);
    legFl->SetBorderSize(0);

    legFl->AddEntry(gChF[6], "charge hadron", "p");
    legFl->AddEntry(gKsF[6], "K_{S}^{0}", "p");
    legFl->AddEntry(gLmF[6], "#Lambda", "p");

    legFl->Draw();

    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);

    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);

    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);

    cpPbV2->SaveAs("pPbV2_Fluct.pdf");

    //
    cpPbV2_1->cd(1);
    latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS} charge hadron");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);

    TLegend * legFl6 = new TLegend(0.16, 0.68, 0.50, 0.82);
    legFl6->SetFillColor(kWhite);
    legFl6->SetTextFont(42);
    legFl6->SetTextSize(0.05);
    legFl6->SetBorderSize(0);

    legFl6->AddEntry(gChF[6], "from v_{2}{4}", "p");
    legFl6->AddEntry(gCh6[6], "from v_{2}{6}", "p");

    legFl6->Draw();

    cpPbV2_1->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);

    cpPbV2_1->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);

    cpPbV2_1->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);

    cpPbV2_1->SaveAs("pPbV2_FluctCh6.pdf");

    // fulct 6
    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_fluct->Draw();
        line1.Draw();
        gKsF[c]->Draw("psame");
        gKs6[c]->Draw("psame");

        cpPbV2_1->cd(c-5);
        hframe_fluct->Draw();
        line1.Draw();
        gLmF[c]->Draw("psame");
        gLm6[c]->Draw("psame");
    }
    cpPbV2->cd(1);
    latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS} K_{S}^{0}");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);

    TLegend * legFlKs6 = new TLegend(0.16, 0.68, 0.50, 0.82);
    legFlKs6->SetFillColor(kWhite);
    legFlKs6->SetTextFont(42);
    legFlKs6->SetTextSize(0.05);
    legFlKs6->SetBorderSize(0);

    legFlKs6->AddEntry(gKsF[6], "from v_{2}{4}", "p");
    legFlKs6->AddEntry(gKs6[6], "from v_{2}{6}", "p");

    legFlKs6->Draw();

    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);

    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);

    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);

    cpPbV2->SaveAs("pPbV2_FluctKs6.pdf");

    //
    cpPbV2_1->cd(1);
    latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS} #Lambda");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);

    TLegend * legFlLm6 = new TLegend(0.16, 0.68, 0.50, 0.82);
    legFlLm6->SetFillColor(kWhite);
    legFlLm6->SetTextFont(42);
    legFlLm6->SetTextSize(0.05);
    legFlLm6->SetBorderSize(0);

    legFlLm6->AddEntry(gLmF[6], "from v_{2}{4}", "p");
    legFlLm6->AddEntry(gLm6[6], "from v_{2}{6}", "p");

    legFlLm6->Draw();

    cpPbV2_1->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);

    cpPbV2_1->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);

    cpPbV2_1->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);

    cpPbV2_1->SaveAs("pPbV2_FluctLm6.pdf");


    // ch v2 subevent
    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_pt->Draw();

        setGr( grSP.grSP_H[c]->vn_Full_NegEtaEP,          kFullCircle, kBlue,    2.);
        setGr( grSP.grSP_H[c]->vn_Full_NegEtaEP_SubEvt,   kOpenCircle, kRed,     2.);
        setGr( grSP.grSP_H[c]->vn_PosEta_NegEtaEP,        kOpenCircle, kBlack,   2.);
        setGr( grSP.grSP_H[c]->vn_PosEta_NegEtaEP_SubEvt, kOpenCircle, kGreen+2, 2.);

        setGr( grH.gr_v24[c],       kFullSquare,  kBlue,     2.);
        setGr( grH.gr_v24sub[c],    kOpenSquare,  kRed,      2.);
        setGr( grH.gr_v24subpos[c], kOpenSquare,  kBlack,    2.);
        setGr( grH.gr_v24subneg[c], kOpenSquare,  kGreen+2,  2.);

//        grSP.grSP_H[c]->vn_Full_NegEtaEP         ->Draw("psame");
//        grSP.grSP_H[c]->vn_Full_NegEtaEP_SubEvt  ->Draw("psame");
//        grSP.grSP_H[c]->vn_PosEta_NegEtaEP       ->Draw("psame");
//        grSP.grSP_H[c]->vn_PosEta_NegEtaEP_SubEvt->Draw("psame");

        grH.gr_v24[c]                          ->Draw("psame");
        grH.gr_v24sub[c]                       ->Draw("psame");
//        grH.gr_v24subpos[c]                    ->Draw("psame");
//        grH.gr_v24subneg[c]                    ->Draw("psame");
    }
    cpPbV2->cd(1);
    latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS} Charge hadron");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);

//    TLegend * legChSub0 = new TLegend(0.16, 0.58, 0.50, 0.82);
//    legChSub0->SetFillColor(kWhite);
//    legChSub0->SetTextFont(42);
//    legChSub0->SetTextSize(0.05);
//    legChSub0->SetBorderSize(0);
//
//    legChSub0->AddEntry( grSP.grSP_H[6]->vn_Full_NegEtaEP,          "v_{2}{Pb-SP} |#eta|<1.",     "p" );
//    legChSub0->AddEntry( grSP.grSP_H[6]->vn_Full_NegEtaEP_SubEvt,   "v_{2}{Pb-SP,Sub} |#eta|<1.", "p" );
//    legChSub0->AddEntry( grSP.grSP_H[6]->vn_PosEta_NegEtaEP,        "v_{2}{Pb-SP} 0.<#eta<1.",        "p" );
//    legChSub0->AddEntry( grSP.grSP_H[6]->vn_PosEta_NegEtaEP_SubEvt, "v_{2}{Pb-SP,Sub} 0.<#eta<1.",    "p" );
//
//    legChSub0->Draw();

    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);
    TLegend * legChSub1 = new TLegend(0.10, 0.58, 0.50, 0.82);
    legChSub1->SetFillColor(kWhite);
    legChSub1->SetTextFont(42);
    legChSub1->SetTextSize(0.05);
    legChSub1->SetBorderSize(0);

    legChSub1->AddEntry( grH.gr_v24[6],       "v_{2}{4} |#eta|<1.",     "p" );
    legChSub1->AddEntry( grH.gr_v24sub[6],    "v_{2}{4,Sub} |#eta|<1.", "p" );
//    legChSub1->AddEntry( grH.gr_v24subpos[6], "v_{2}{4,Sub} 0.<#eta<1.", "p" );
//    legChSub1->AddEntry( grH.gr_v24subneg[6], "v_{2}{4,Sub} -1.<#eta<0.", "p" );

    legChSub1->Draw();

    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);

    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);

    cpPbV2->SaveAs("pPbV2_Subevt_Ch.pdf");;

    // ch ratio
    TH2D * hframe_ratio = new TH2D("hframe_ratio", "hframe_ratio", 1, 0.01, 8.5, 1, 0.05, 1.95);
    InitHist(hframe_ratio, "p_{T}", "Ratio");
    hframe_ratio->GetYaxis()->SetTitleOffset(1.0);
    hframe_ratio->GetXaxis()->SetTitleOffset(0.90);

    TGraphErrors* grChRatioSP1[10] = {};
    TGraphErrors* grChRatioSP2[10] = {};
    TGraphErrors* grChRatioSP3[10] = {};

    TGraphErrors* grChRatioCu1[10] = {};
    TGraphErrors* grChRatioCu2[10] = {};
    TGraphErrors* grChRatioCu3[10] = {};

    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_ratio->Draw();
        line1.Draw();

        grChRatioSP1[c] = getRatio( grSP.grSP_H[c]->vn_Full_NegEtaEP_SubEvt,   grSP.grSP_H[c]->vn_Full_NegEtaEP );
        grChRatioSP2[c] = getRatio( grSP.grSP_H[c]->vn_PosEta_NegEtaEP,        grSP.grSP_H[c]->vn_Full_NegEtaEP );
        grChRatioSP3[c] = getRatio( grSP.grSP_H[c]->vn_PosEta_NegEtaEP_SubEvt, grSP.grSP_H[c]->vn_Full_NegEtaEP );

        grChRatioCu1[c] = getRatio( grH.gr_v24sub[c],    grH.gr_v24[c] );
        grChRatioCu2[c] = getRatio( grH.gr_v24subpos[c], grH.gr_v24[c] );
        grChRatioCu3[c] = getRatio( grH.gr_v24subneg[c], grH.gr_v24[c] );

        setGr( grChRatioSP1[c], kOpenCircle, kRed, 2.);
        setGr( grChRatioSP2[c], kOpenCircle, kBlack, 2.);
        setGr( grChRatioSP3[c], kOpenCircle, kGreen+2, 2.);

        setGr( grChRatioCu1[c], kOpenSquare, kRed, 2.);
        setGr( grChRatioCu2[c], kOpenSquare, kBlack, 2.);
        setGr( grChRatioCu3[c], kOpenSquare, kGreen+2, 2.);

//        grChRatioSP1[c]->Draw("psame");
//        grChRatioSP2[c]->Draw("psame");
//        grChRatioSP3[c]->Draw("psame");

        grChRatioCu1[c]->Draw("psame");
        grChRatioCu2[c]->Draw("psame");
        grChRatioCu3[c]->Draw("psame");
    }
    cpPbV2->cd(1);
    latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS} Charge hadron");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);

    TLegend * legChRatio0 = new TLegend(0.16, 0.58, 0.50, 0.82);
    legChRatio0->SetFillColor(kWhite);
    legChRatio0->SetTextFont(42);
    legChRatio0->SetTextSize(0.05);
    legChRatio0->SetBorderSize(0);

    legChRatio0->AddEntry( grChRatioSP1[6], "v_{2}{Pb-SP,Sub} |#eta|<1.", "p" );
    legChRatio0->AddEntry( grChRatioSP2[6], "v_{2}{Pb-SP} 0.<#eta<1.",        "p" );
    legChRatio0->AddEntry( grChRatioSP3[6], "v_{2}{Pb-SP,Sub} 0.<#eta<1.",    "p" );

//    legChRatio0->Draw();

    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);

    TLegend * legChRatio1 = new TLegend(0.10, 0.58, 0.50, 0.82);
    legChRatio1->SetFillColor(kWhite);
    legChRatio1->SetTextFont(42);
    legChRatio1->SetTextSize(0.05);
    legChRatio1->SetBorderSize(0);

    legChRatio1->AddEntry( grChRatioCu1[6], "v_{2}{4,Sub} |#eta|<1.", "p" );
    legChRatio1->AddEntry( grChRatioCu2[6], "v_{2}{4,Sub} 0.<#eta<1.", "p" );
    legChRatio1->AddEntry( grChRatioCu3[6], "v_{2}{4,Sub} -1.<#eta<0.", "p" );

    legChRatio1->Draw();

    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);

    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);

    cpPbV2->SaveAs("pPbV2_Ratio_Ch.pdf");

    // Ks v2 subevent
    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_pt->Draw();

        setGr( grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP,          kFullCircle, kBlue,    2.);
        setGr( grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP_SubEvt,   kOpenCircle, kRed,     2.);
        setGr( grSP.grSP_Ks_Sig[c]->vn_PosEta_NegEtaEP,        kOpenCircle, kBlack,   2.);
        setGr( grSP.grSP_Ks_Sig[c]->vn_PosEta_NegEtaEP_SubEvt, kOpenCircle, kGreen+2, 2.);

        setGr( grKs.gr_v24[c],       kFullSquare,  kBlue,     2.);
        setGr( grKs.gr_v24sub[c],    kOpenSquare,  kRed,      2.);
        setGr( grKs.gr_v24subpos[c], kOpenSquare,  kBlack,    2.);
        setGr( grKs.gr_v24subneg[c], kOpenSquare,  kGreen+2,  2.);

//        grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP         ->Draw("psame");
//        grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP_SubEvt  ->Draw("psame");
//        grSP.grSP_Ks_Sig[c]->vn_PosEta_NegEtaEP       ->Draw("psame");
//        grSP.grSP_Ks_Sig[c]->vn_PosEta_NegEtaEP_SubEvt->Draw("psame");

        grKs.gr_v24[c]      ->Draw("psame");
        grKs.gr_v24sub[c]   ->Draw("psame");
//        grKs.gr_v24subpos[c]->Draw("psame");
//        grKs.gr_v24subneg[c]->Draw("psame");
    }
    cpPbV2->cd(1);
    latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS} K_{S}^{0}");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);

    TLegend * legKsSub0 = new TLegend(0.16, 0.58, 0.50, 0.82);
    legKsSub0->SetFillColor(kWhite);
    legKsSub0->SetTextFont(42);
    legKsSub0->SetTextSize(0.05);
    legKsSub0->SetBorderSize(0);

    legKsSub0->AddEntry( grSP.grSP_Ks_Sig[6]->vn_Full_NegEtaEP,          "v_{2}{Pb-SP} |#eta|<1.",     "p" );
    legKsSub0->AddEntry( grSP.grSP_Ks_Sig[6]->vn_Full_NegEtaEP_SubEvt,   "v_{2}{Pb-SP,Sub} |#eta|<1.", "p" );
    legKsSub0->AddEntry( grSP.grSP_Ks_Sig[6]->vn_PosEta_NegEtaEP,        "v_{2}{Pb-SP} 0.<#eta<1.",        "p" );
    legKsSub0->AddEntry( grSP.grSP_Ks_Sig[6]->vn_PosEta_NegEtaEP_SubEvt, "v_{2}{Pb-SP,Sub} 0.<#eta<1.",    "p" );

//    legKsSub0->Draw();

    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);

    TLegend * legKsSub1 = new TLegend(0.10, 0.58, 0.50, 0.82);
    legKsSub1->SetFillColor(kWhite);
    legKsSub1->SetTextFont(42);
    legKsSub1->SetTextSize(0.05);
    legKsSub1->SetBorderSize(0);

    legKsSub1->AddEntry( grKs.gr_v24[6],       "v_{2}{4} |#eta|<1.",     "p" );
    legKsSub1->AddEntry( grKs.gr_v24sub[6],    "v_{2}{4,Sub} |#eta|<1.", "p" );
//    legKsSub1->AddEntry( grKs.gr_v24subpos[6], "v_{2}{4,Sub} 0.<#eta<1.", "p" );
//    legKsSub1->AddEntry( grKs.gr_v24subneg[6], "v_{2}{4,Sub} -1.<#eta<0.", "p" );

    legKsSub1->Draw();

    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);

    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);

    cpPbV2->SaveAs("pPbV2_Subevt_Ks.pdf");

    // Ks subevent ratio
    TGraphErrors* grKsRatioSP1[10] = {};
    TGraphErrors* grKsRatioSP2[10] = {};
    TGraphErrors* grKsRatioSP3[10] = {};

    TGraphErrors* grKsRatioCu1[10] = {};
    TGraphErrors* grKsRatioCu2[10] = {};
    TGraphErrors* grKsRatioCu3[10] = {};

    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_ratio->Draw();
        line1.Draw();

        grKsRatioSP1[c] = getRatio( grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP_SubEvt,   grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP );
        grKsRatioSP2[c] = getRatio( grSP.grSP_Ks_Sig[c]->vn_PosEta_NegEtaEP,        grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP );
        grKsRatioSP3[c] = getRatio( grSP.grSP_Ks_Sig[c]->vn_PosEta_NegEtaEP_SubEvt, grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP );

        grKsRatioCu1[c] = getRatio( grKs.gr_v24sub[c],    grKs.gr_v24[c] );
        grKsRatioCu2[c] = getRatio( grKs.gr_v24subpos[c], grKs.gr_v24[c] );
        grKsRatioCu3[c] = getRatio( grKs.gr_v24subneg[c], grKs.gr_v24[c] );

        setGr( grKsRatioSP1[c], kOpenCircle, kRed, 2.);
        setGr( grKsRatioSP2[c], kOpenCircle, kBlack, 2.);
        setGr( grKsRatioSP3[c], kOpenCircle, kGreen+2, 2.);

        setGr( grKsRatioCu1[c], kOpenSquare, kRed, 2.);
        setGr( grKsRatioCu2[c], kOpenSquare, kBlack, 2.);
        setGr( grKsRatioCu3[c], kOpenSquare, kGreen+2, 2.);

//        grKsRatioSP1[c]->Draw("psame");
//        grKsRatioSP2[c]->Draw("psame");
//        grKsRatioSP3[c]->Draw("psame");

        grKsRatioCu1[c]->Draw("psame");
//        grKsRatioCu2[c]->Draw("psame");
//        grKsRatioCu3[c]->Draw("psame");
    }
    cpPbV2->cd(1);
    latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS} K_{S}^{0}");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);

    TLegend * legKsRatio0 = new TLegend(0.16, 0.58, 0.50, 0.82);
    legKsRatio0->SetFillColor(kWhite);
    legKsRatio0->SetTextFont(42);
    legKsRatio0->SetTextSize(0.05);
    legKsRatio0->SetBorderSize(0);

    legKsRatio0->AddEntry( grKsRatioSP1[6], "v_{2}{Pb-SP,Sub} |#eta|<1.", "p" );
    legKsRatio0->AddEntry( grKsRatioSP2[6], "v_{2}{Pb-SP} 0.<#eta<1.",        "p" );
    legKsRatio0->AddEntry( grKsRatioSP3[6], "v_{2}{Pb-SP,Sub} 0.<#eta<1.",    "p" );

//    legKsRatio0->Draw();

    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);

    TLegend * legKsRatio1 = new TLegend(0.10, 0.58, 0.50, 0.82);
    legKsRatio1->SetFillColor(kWhite);
    legKsRatio1->SetTextFont(42);
    legKsRatio1->SetTextSize(0.05);
    legKsRatio1->SetBorderSize(0);

    legKsRatio1->AddEntry( grKsRatioCu1[6], "v_{2}{4,Sub} |#eta|<1.", "p" );
//    legKsRatio1->AddEntry( grKsRatioCu2[6], "v_{2}{4,Sub} 0.<#eta<1.", "p" );
//    legKsRatio1->AddEntry( grKsRatioCu3[6], "v_{2}{4,Sub} -1.<#eta<0.", "p" );

    legKsRatio1->Draw();

    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);

    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);

    cpPbV2->SaveAs("pPbV2_Ratio_Ks.pdf");

    // Lm v2 subevent
    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_pt->Draw();

        setGr( grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP,          kFullCircle, kBlue,    2.);
        setGr( grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP_SubEvt,   kOpenCircle, kRed,     2.);
        setGr( grSP.grSP_Lm_Sig[c]->vn_PosEta_NegEtaEP,        kOpenCircle, kBlack,   2.);
        setGr( grSP.grSP_Lm_Sig[c]->vn_PosEta_NegEtaEP_SubEvt, kOpenCircle, kGreen+2, 2.);

        setGr( grLm.gr_v24[c],       kFullSquare,  kBlue,     2.);
        setGr( grLm.gr_v24sub[c],    kOpenSquare,  kRed,      2.);
        setGr( grLm.gr_v24subpos[c], kOpenSquare,  kBlack,    2.);
        setGr( grLm.gr_v24subneg[c], kOpenSquare,  kGreen+2,  2.);

//        grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP         ->Draw("psame");
//        grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP_SubEvt  ->Draw("psame");
//        grSP.grSP_Lm_Sig[c]->vn_PosEta_NegEtaEP       ->Draw("psame");
//        grSP.grSP_Lm_Sig[c]->vn_PosEta_NegEtaEP_SubEvt->Draw("psame");

        grLm.gr_v24[c]      ->Draw("psame");
        grLm.gr_v24sub[c]   ->Draw("psame");
//        grLm.gr_v24subpos[c]->Draw("psame");
//        grLm.gr_v24subneg[c]->Draw("psame");
    }
    cpPbV2->cd(1);
    latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS} #Lambda");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);

    TLegend * legLmSub0 = new TLegend(0.16, 0.58, 0.50, 0.82);
    legLmSub0->SetFillColor(kWhite);
    legLmSub0->SetTextFont(42);
    legLmSub0->SetTextSize(0.05);
    legLmSub0->SetBorderSize(0);

    legLmSub0->AddEntry( grSP.grSP_Lm_Sig[6]->vn_Full_NegEtaEP,          "v_{2}{Pb-SP} |#eta|<1.",     "p" );
    legLmSub0->AddEntry( grSP.grSP_Lm_Sig[6]->vn_Full_NegEtaEP_SubEvt,   "v_{2}{Pb-SP,Sub} |#eta|<1.", "p" );
    legLmSub0->AddEntry( grSP.grSP_Lm_Sig[6]->vn_PosEta_NegEtaEP,        "v_{2}{Pb-SP} 0.<#eta<1.",        "p" );
    legLmSub0->AddEntry( grSP.grSP_Lm_Sig[6]->vn_PosEta_NegEtaEP_SubEvt, "v_{2}{Pb-SP,Sub} 0.<#eta<1.",    "p" );

//    legLmSub0->Draw();

    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);

    TLegend * legLmSub1 = new TLegend(0.10, 0.58, 0.50, 0.82);
    legLmSub1->SetFillColor(kWhite);
    legLmSub1->SetTextFont(42);
    legLmSub1->SetTextSize(0.05);
    legLmSub1->SetBorderSize(0);

    legLmSub1->AddEntry( grLm.gr_v24[6],       "v_{2}{4} |#eta|<1.",     "p" );
    legLmSub1->AddEntry( grLm.gr_v24sub[6],    "v_{2}{4,Sub} |#eta|<1.", "p" );
//    legLmSub1->AddEntry( grLm.gr_v24subpos[6], "v_{2}{4,Sub} 0.<#eta<1.", "p" );
//    legLmSub1->AddEntry( grLm.gr_v24subneg[6], "v_{2}{4,Sub} -1.<#eta<0.", "p" );

    legLmSub1->Draw();

    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);

    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);

    cpPbV2->SaveAs("pPbV2_Subevt_Lm.pdf");

    // Lm subevent ratio
    TGraphErrors* grLmRatioSP1[10] = {};
    TGraphErrors* grLmRatioSP2[10] = {};
    TGraphErrors* grLmRatioSP3[10] = {};

    TGraphErrors* grLmRatioCu1[10] = {};
    TGraphErrors* grLmRatioCu2[10] = {};
    TGraphErrors* grLmRatioCu3[10] = {};

    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_ratio->Draw();
        line1.Draw();

        grLmRatioSP1[c] = getRatio( grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP_SubEvt,   grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP );
        grLmRatioSP2[c] = getRatio( grSP.grSP_Lm_Sig[c]->vn_PosEta_NegEtaEP,        grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP );
        grLmRatioSP3[c] = getRatio( grSP.grSP_Lm_Sig[c]->vn_PosEta_NegEtaEP_SubEvt, grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP );

        grLmRatioCu1[c] = getRatio( grLm.gr_v24sub[c],    grLm.gr_v24[c] );
        grLmRatioCu2[c] = getRatio( grLm.gr_v24subpos[c], grLm.gr_v24[c] );
        grLmRatioCu3[c] = getRatio( grLm.gr_v24subneg[c], grLm.gr_v24[c] );

        setGr( grLmRatioSP1[c], kOpenCircle, kRed, 2.);
        setGr( grLmRatioSP2[c], kOpenCircle, kBlack, 2.);
        setGr( grLmRatioSP3[c], kOpenCircle, kGreen+2, 2.);

        setGr( grLmRatioCu1[c], kOpenSquare, kRed, 2.);
        setGr( grLmRatioCu2[c], kOpenSquare, kBlack, 2.);
        setGr( grLmRatioCu3[c], kOpenSquare, kGreen+2, 2.);

//        grLmRatioSP1[c]->Draw("psame");
//        grLmRatioSP2[c]->Draw("psame");
//        grLmRatioSP3[c]->Draw("psame");

        grLmRatioCu1[c]->Draw("psame");
//        grLmRatioCu2[c]->Draw("psame");
//        grLmRatioCu3[c]->Draw("psame");
    }
    cpPbV2->cd(1);
    latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS} #Lambda");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);

    TLegend * legLmRatio0 = new TLegend(0.16, 0.58, 0.50, 0.82);
    legLmRatio0->SetFillColor(kWhite);
    legLmRatio0->SetTextFont(42);
    legLmRatio0->SetTextSize(0.05);
    legLmRatio0->SetBorderSize(0);

    legLmRatio0->AddEntry( grLmRatioSP1[6], "v_{2}{Pb-SP,Sub} |#eta|<1.", "p" );
    legLmRatio0->AddEntry( grLmRatioSP2[6], "v_{2}{Pb-SP} 0.<#eta<1.",        "p" );
    legLmRatio0->AddEntry( grLmRatioSP3[6], "v_{2}{Pb-SP,Sub} 0.<#eta<1.",    "p" );

//    legLmRatio0->Draw();

    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);

    TLegend * legLmRatio1 = new TLegend(0.10, 0.58, 0.50, 0.82);
    legLmRatio1->SetFillColor(kWhite);
    legLmRatio1->SetTextFont(42);
    legLmRatio1->SetTextSize(0.05);
    legLmRatio1->SetBorderSize(0);

    legLmRatio1->AddEntry( grLmRatioCu1[6], "v_{2}{4,Sub} |#eta|<1.", "p" );
//    legLmRatio1->AddEntry( grLmRatioCu2[6], "v_{2}{4,Sub} 0.<#eta<1.", "p" );
//    legLmRatio1->AddEntry( grLmRatioCu3[6], "v_{2}{4,Sub} -1.<#eta<0.", "p" );

    legLmRatio1->Draw();

    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);

    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);

    cpPbV2->SaveAs("pPbV2_Ratio_Lm.pdf");
}
