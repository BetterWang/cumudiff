

#include "../../style.h"
#include "theory.h"
#include "PbPb_header.h"

void plotFinal()
{
    TFile * fH  = new TFile("PbPb2018_H_corrected.root");
    TFile * fKs = new TFile("PbPb2018_Ks_corrected.root");
    TFile * fLm = new TFile("PbPb2018_Lm_corrected.root");

    QWCumu vH (fH,  0, true);
    QWCumu vKs(fKs, 1, true);
    QWCumu vLm(fLm, 2, true);

    LoadSPCorrected(true);

    vH .ReplaceX( ch_v2_PbPb );
    vKs.ReplaceX( Ks_v2_PbPb_Sig );
    vLm.ReplaceX( Lm_v2_PbPb_Sig );

    theory();

    string centBins[] = {"0-5\%", "5-10\%", "10-30\%", "30-50\%", "50-80\%"};

    TLatex latexS;
    latexS.SetTextFont(43);
    latexS.SetTextSize(22);
    latexS.SetTextAlign(13);

    TLine line1(0.1, 1., 8.5, 1.);

    TCanvas * cPbPbV2 = MakeCanvas("cPbPbV2", "cPbPbV2", 1400, 400);
    splitCanv4(cPbPbV2);

    TCanvas * cPbPbV2_1 = MakeCanvas("cPbPbV2_1", "cPbPbV2_1", 1400, 400);
    splitCanv4(cPbPbV2_1);

    TH2D * hframe_pt = new TH2D("hframe_pt", "hframe_pt", 1, 0.01, 8.5, 1, 0, 0.32);
    InitHist(hframe_pt, "p_{T}", "v_{2}");
    hframe_pt->GetYaxis()->SetTitleOffset(1.0);
    hframe_pt->GetXaxis()->SetTitleOffset(0.90);

    // Ch v2
    for ( int c = 1; c < 5; c++ ) {
        cPbPbV2->cd(c);
        hframe_pt->Draw();

        ch_v2_PbPb[c]   ->vn_MergedEta->SetMarkerStyle(kOpenCircle);
        ch_v2_PbPb[c]   ->vn_MergedEta->SetMarkerColor(kBlue);
        ch_v2_PbPb[c]   ->vn_MergedEta->SetLineColor  (kBlue);
        ch_v2_PbPb[c]   ->vn_MergedEta->SetMarkerSize(2.);

        ch_v2_sysPbPb[c]->vn_MergedEta->SetFillColor(3003);

        ch_v2_sysPbPb[c]->vn_MergedEta->Draw("[]2");
        ch_v2_PbPb[c]   ->vn_MergedEta->Draw("psame");

        //
        vH.grSig_pT[2][1][c] ->SetMarkerStyle(kOpenStar);
        vH.grSig_pT[2][1][c] ->SetMarkerColor(kBlue);
        vH.grSig_pT[2][1][c] ->SetLineColor  (kBlue);
        vH.grSig_pT[2][1][c] ->SetMarkerSize(2.);

        vH.grSig_pT[2][2][c] ->SetMarkerStyle(kFullCross);
        vH.grSig_pT[2][2][c] ->SetMarkerColor(kRed);
        vH.grSig_pT[2][2][c] ->SetLineColor  (kRed);
        vH.grSig_pT[2][2][c] ->SetMarkerSize(2.);

        vH.grSig_pT[2][3][c] ->SetMarkerStyle(kFullDiamond);
        vH.grSig_pT[2][3][c] ->SetMarkerColor(kGreen+2);
        vH.grSig_pT[2][3][c] ->SetLineColor  (kGreen+2);
        vH.grSig_pT[2][3][c] ->SetMarkerSize(2.);

        vH.grSysSig_pT[2][1][c] ->SetFillColor(3003);
        vH.grSysSig_pT[2][2][c] ->SetFillColor(3001);
        vH.grSysSig_pT[2][3][c] ->SetFillColor(3002);

        vH.grSysSig_pT[2][1][c] ->Draw("[]2");
        vH.grSysSig_pT[2][2][c] ->Draw("[]2");
        vH.grSysSig_pT[2][3][c] ->Draw("[]2");

        vH.grSig_pT[2][1][c]    ->Draw("psame");
        vH.grSig_pT[2][2][c]    ->Draw("psame");
        vH.grSig_pT[2][3][c]    ->Draw("psame");

        ampt  ->grCh_v22[c]->SetLineColor(kRed);
        ampt  ->grCh_v24[c]->SetLineColor(kBlue);

        trento->grCh_v22[c]->SetLineColor(kRed);
        trento->grCh_v24[c]->SetLineColor(kBlue);
        trento->grCh_v22[c]->SetLineStyle(kDashed);
        trento->grCh_v24[c]->SetLineStyle(kDashed);

        ampt  ->grCh_v22[c]->Draw("lsame");
        ampt  ->grCh_v24[c]->Draw("lsame");
        trento->grCh_v22[c]->Draw("lsame");
        trento->grCh_v24[c]->Draw("lsame");
    }
    cPbPbV2->cd(1);
    latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS} Charge hadron");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    TLegend * legCh = new TLegend(0.60, 0.55, 0.90, 0.90);
    legCh->SetFillColor(kWhite);
    legCh->SetTextFont(42);
    legCh->SetTextSize(0.05);
    legCh->SetBorderSize(0);

    legCh->AddEntry(ch_v2_PbPb[1]->vn_MergedEta, "v_{2}{SP}", "p");
    legCh->AddEntry(vH.grSig_pT[2][1][1], "v_{2}{4}", "p");
    legCh->AddEntry(vH.grSig_pT[2][2][1], "v_{2}{6}", "p");
    legCh->AddEntry(vH.grSig_pT[2][3][1], "v_{2}{8}", "p");

    legCh->Draw();

    cPbPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[2]).c_str());

    TLegend * legChTh = new TLegend(0.55, 0.62, 0.90, 0.92);
    legChTh->SetFillColor(kWhite);
    legChTh->SetTextFont(42);
    legChTh->SetTextSize(0.05);
    legChTh->SetBorderSize(0);
    legChTh->AddEntry(ampt  ->grCh_v22[2], "AMPT-IC v_{2}{2}", "l");
    legChTh->AddEntry(ampt  ->grCh_v24[2], "AMPT-IC v_{2}{4}", "l");
    legChTh->AddEntry(trento->grCh_v22[2], "Trento-IC v_{2}{2}", "l");
    legChTh->AddEntry(trento->grCh_v24[2], "Trento-IC v_{2}{4}", "l");
    legChTh->Draw();

    cPbPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[3]).c_str());
    cPbPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[4]).c_str());
    cPbPbV2->SaveAs("PbPbV2_Ch.pdf");

    // Ks v2
    for ( int c = 1; c < 5; c++ ) {
        cPbPbV2->cd(c);
        hframe_pt->Draw();

        Ks_v2_PbPb_Sig[c]   ->vn_MergedEta->SetMarkerStyle(kOpenCircle);
        Ks_v2_PbPb_Sig[c]   ->vn_MergedEta->SetMarkerColor(kBlue);
        Ks_v2_PbPb_Sig[c]   ->vn_MergedEta->SetLineColor  (kBlue);
        Ks_v2_PbPb_Sig[c]   ->vn_MergedEta->SetMarkerSize(2.);

        Ks_v2_sysPbPb_Sig[c]->vn_MergedEta->SetFillColor(3003);

        Ks_v2_sysPbPb_Sig[c]->vn_MergedEta->Draw("[]2");
        Ks_v2_PbPb_Sig[c]   ->vn_MergedEta->Draw("psame");

        //
        vKs.grSig_pT[2][1][c] ->SetMarkerStyle(kOpenStar);
        vKs.grSig_pT[2][1][c] ->SetMarkerColor(kBlue);
        vKs.grSig_pT[2][1][c] ->SetLineColor  (kBlue);
        vKs.grSig_pT[2][1][c] ->SetMarkerSize(2.);

        vKs.grSig_pT[2][2][c] ->SetMarkerStyle(kFullCross);
        vKs.grSig_pT[2][2][c] ->SetMarkerColor(kRed);
        vKs.grSig_pT[2][2][c] ->SetLineColor  (kRed);
        vKs.grSig_pT[2][2][c] ->SetMarkerSize(2.);

        vKs.grSig_pT[2][3][c] ->SetMarkerStyle(kFullDiamond);
        vKs.grSig_pT[2][3][c] ->SetMarkerColor(kGreen+2);
        vKs.grSig_pT[2][3][c] ->SetLineColor  (kGreen+2);
        vKs.grSig_pT[2][3][c] ->SetMarkerSize(2.);

        vKs.grSysSig_pT[2][1][c] ->SetFillColor(3003);
        vKs.grSysSig_pT[2][2][c] ->SetFillColor(3001);
        vKs.grSysSig_pT[2][3][c] ->SetFillColor(3002);

//        if ( c!=0 ) {
            ampt  ->grKs_v22[c]->SetLineColor(kRed);
            ampt  ->grKs_v24[c]->SetLineColor(kBlue);

            trento->grKs_v22[c]->SetLineColor(kRed);
            trento->grKs_v24[c]->SetLineColor(kBlue);
            trento->grKs_v22[c]->SetLineStyle(kDashed);
            trento->grKs_v24[c]->SetLineStyle(kDashed);

            ampt  ->grKs_v22[c]->Draw("lsame");
            ampt  ->grKs_v24[c]->Draw("lsame");
            trento->grKs_v22[c]->Draw("lsame");
            trento->grKs_v24[c]->Draw("lsame");
//        }

        vKs.grSysSig_pT[2][1][c] ->Draw("[]2");
        vKs.grSysSig_pT[2][2][c] ->Draw("[]2");
        vKs.grSysSig_pT[2][3][c] ->Draw("[]2");

        vKs.grSig_pT[2][1][c]    ->Draw("psame");
        vKs.grSig_pT[2][2][c]    ->Draw("psame");
        vKs.grSig_pT[2][3][c]    ->Draw("psame");

    }
    cPbPbV2->cd(1);
    latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS} K_{S}^{0}");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    TLegend * legKs = new TLegend(0.60, 0.60, 0.90, 0.92);
    legKs->SetFillColor(kWhite);
    legKs->SetTextFont(42);
    legKs->SetTextSize(0.05);
    legKs->SetBorderSize(0);

    legKs->AddEntry(Ks_v2_PbPb_Sig[1]->vn_MergedEta, "v_{2}{SP}", "p");
    legKs->AddEntry(vKs.grSig_pT[2][1][1], "v_{2}{4}", "p");
    legKs->AddEntry(vKs.grSig_pT[2][2][1], "v_{2}{6}", "p");
    legKs->AddEntry(vKs.grSig_pT[2][3][1], "v_{2}{8}", "p");

    legKs->Draw();

    cPbPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[2]).c_str());

    TLegend * legKsTh = new TLegend(0.55, 0.62, 0.90, 0.92);
    legKsTh->SetFillColor(kWhite);
    legKsTh->SetTextFont(42);
    legKsTh->SetTextSize(0.05);
    legKsTh->SetBorderSize(0);

    legKsTh->AddEntry(ampt  ->grKs_v22[2], "AMPT-IC v_{2}{2}", "l");
    legKsTh->AddEntry(ampt  ->grKs_v24[2], "AMPT-IC v_{2}{4}", "l");
    legKsTh->AddEntry(trento->grKs_v22[2], "Trento-IC v_{2}{2}", "l");
    legKsTh->AddEntry(trento->grKs_v24[2], "Trento-IC v_{2}{4}", "l");

    legKsTh->Draw();

    cPbPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[3]).c_str());
    cPbPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[4]).c_str());
    cPbPbV2->SaveAs("PbPbV2_Ks.pdf");


    // Lm v2
    for ( int c = 1; c < 5; c++ ) {
        cPbPbV2->cd(c);
        hframe_pt->Draw();

        Lm_v2_PbPb_Sig[c]   ->vn_MergedEta->SetMarkerStyle(kOpenCircle);
        Lm_v2_PbPb_Sig[c]   ->vn_MergedEta->SetMarkerColor(kBlue);
        Lm_v2_PbPb_Sig[c]   ->vn_MergedEta->SetLineColor  (kBlue);
        Lm_v2_PbPb_Sig[c]   ->vn_MergedEta->SetMarkerSize(2.);

        Lm_v2_sysPbPb_Sig[c]->vn_MergedEta->SetFillColor(3003);

        Lm_v2_sysPbPb_Sig[c]->vn_MergedEta->Draw("[]2");
        Lm_v2_PbPb_Sig[c]   ->vn_MergedEta->Draw("psame");

        //
        vLm.grSig_pT[2][1][c] ->SetMarkerStyle(kOpenStar);
        vLm.grSig_pT[2][1][c] ->SetMarkerColor(kBlue);
        vLm.grSig_pT[2][1][c] ->SetLineColor  (kBlue);
        vLm.grSig_pT[2][1][c] ->SetMarkerSize(2.);

        vLm.grSig_pT[2][2][c] ->SetMarkerStyle(kFullCross);
        vLm.grSig_pT[2][2][c] ->SetMarkerColor(kRed);
        vLm.grSig_pT[2][2][c] ->SetLineColor  (kRed);
        vLm.grSig_pT[2][2][c] ->SetMarkerSize(2.);

        vLm.grSig_pT[2][3][c] ->SetMarkerStyle(kFullDiamond);
        vLm.grSig_pT[2][3][c] ->SetMarkerColor(kGreen+2);
        vLm.grSig_pT[2][3][c] ->SetLineColor  (kGreen+2);
        vLm.grSig_pT[2][3][c] ->SetMarkerSize(2.);

        vLm.grSysSig_pT[2][1][c] ->SetFillColor(3003);
        vLm.grSysSig_pT[2][2][c] ->SetFillColor(3001);
        vLm.grSysSig_pT[2][3][c] ->SetFillColor(3002);

        if ( c!=0 ) {
            ampt  ->grLm_v22[c]->SetLineColor(kRed);
            ampt  ->grLm_v24[c]->SetLineColor(kBlue);

            trento->grLm_v22[c]->SetLineColor(kRed);
            trento->grLm_v24[c]->SetLineColor(kBlue);
            trento->grLm_v22[c]->SetLineStyle(kDashed);
            trento->grLm_v24[c]->SetLineStyle(kDashed);

            ampt  ->grLm_v22[c]->Draw("lsame");
            ampt  ->grLm_v24[c]->Draw("lsame");
            trento->grLm_v22[c]->Draw("lsame");
            trento->grLm_v24[c]->Draw("lsame");
        }


        vLm.grSysSig_pT[2][1][c] ->Draw("[]2");
        vLm.grSysSig_pT[2][2][c] ->Draw("[]2");
        vLm.grSysSig_pT[2][3][c] ->Draw("[]2");

        vLm.grSig_pT[2][1][c]    ->Draw("psame");
        vLm.grSig_pT[2][2][c]    ->Draw("psame");
        vLm.grSig_pT[2][3][c]    ->Draw("psame");
    }
    cPbPbV2->cd(1);
    latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS} #Lambda");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    TLegend * legLm = new TLegend(0.60, 0.60, 0.90, 0.92);
    legLm->SetFillColor(kWhite);
    legLm->SetTextFont(42);
    legLm->SetTextSize(0.05);
    legLm->SetBorderSize(0);

    legLm->AddEntry(Lm_v2_PbPb_Sig[1]->vn_MergedEta, "v_{2}{SP}", "p");
    legLm->AddEntry(vLm.grSig_pT[2][1][1], "v_{2}{4}", "p");
    legLm->AddEntry(vLm.grSig_pT[2][2][1], "v_{2}{6}", "p");
    legLm->AddEntry(vLm.grSig_pT[2][3][1], "v_{2}{8}", "p");

    legLm->Draw();

    cPbPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[2]).c_str());

    TLegend * legLmTh = new TLegend(0.40, 0.15, 0.75, 0.47);
    legLmTh->SetFillColor(kWhite);
    legLmTh->SetTextFont(42);
    legLmTh->SetTextSize(0.05);
    legLmTh->SetBorderSize(0);

    legLmTh->AddEntry(ampt  ->grLm_v22[2], "AMPT-IC v_{2}{2}", "l");
    legLmTh->AddEntry(ampt  ->grLm_v24[2], "AMPT-IC v_{2}{4}", "l");
    legLmTh->AddEntry(trento->grLm_v22[2], "Trento-IC v_{2}{2}", "l");
    legLmTh->AddEntry(trento->grLm_v24[2], "Trento-IC v_{2}{4}", "l");


    cPbPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[3]).c_str());
    legLmTh->Draw();
    cPbPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[4]).c_str());
    cPbPbV2->SaveAs("PbPbV2_Lm.pdf");

    // fluctuation
    TH2D * hframe_fluct = new TH2D("hframe_fluct", "hframe_fluct", 1, 0.01, 8.5, 1, 0.05, 0.9);
    InitHist(hframe_fluct, "p_{T}", "Fluctuation");
    hframe_fluct->GetYaxis()->SetTitleOffset(1.0);
    hframe_fluct->GetXaxis()->SetTitleOffset(0.90);

    TGraphErrors * gChF[5] = {};
    TGraphErrors * gKsF[5] = {};
    TGraphErrors * gLmF[5] = {};
    TGraphErrors * gChAmptF[5] = {};
    TGraphErrors * gKsAmptF[5] = {};
    TGraphErrors * gLmAmptF[5] = {};
    TGraphErrors * gChTrentoF[5] = {};
    TGraphErrors * gKsTrentoF[5] = {};
    TGraphErrors * gLmTrentoF[5] = {};

    for ( int c = 1; c < 5; c++ ) {
        cPbPbV2->cd(c);
        hframe_fluct->Draw();

        gChF[c] = getFluct( ch_v2_PbPb[c]->vn_MergedEta     , vH .grSig_pT[2][1][c] );
        gKsF[c] = getFluct( Ks_v2_PbPb_Sig[c]->vn_MergedEta , vKs.grSig_pT[2][1][c] );
        gLmF[c] = getFluct( Lm_v2_PbPb_Sig[c]->vn_MergedEta , vLm.grSig_pT[2][1][c] );

        gChF[c]->SetMarkerStyle(kOpenCircle);
        gChF[c]->SetMarkerColor(kBlack);
        gChF[c]->SetLineColor  (kBlack);
        gChF[c]->SetMarkerSize(2.);

        gKsF[c]->SetMarkerStyle(kOpenSquare);
        gKsF[c]->SetMarkerColor(kBlue);
        gKsF[c]->SetLineColor  (kBlue);
        gKsF[c]->SetMarkerSize(2.);

        gLmF[c]->SetMarkerStyle(kOpenCircle);
        gLmF[c]->SetMarkerColor(kRed);
        gLmF[c]->SetLineColor  (kRed);
        gLmF[c]->SetMarkerSize(2.);

        if ( c!=0 ) {
            gChAmptF[c] =   getFluct(ampt  ->grCh_v22[c], ampt  ->grCh_v24[c]);
            gChTrentoF[c] = getFluct(trento->grCh_v22[c], trento->grCh_v24[c]);
            gKsAmptF[c] =   getFluct(ampt  ->grKs_v22[c], ampt  ->grKs_v24[c]);
            gKsTrentoF[c] = getFluct(trento->grKs_v22[c], trento->grKs_v24[c]);
            gLmAmptF[c] =   getFluct(ampt  ->grLm_v22[c], ampt  ->grLm_v24[c]);
            gLmTrentoF[c] = getFluct(trento->grLm_v22[c], trento->grLm_v24[c]);

            gChAmptF[c]  ->SetLineColor(kBlack);
            gChTrentoF[c]->SetLineColor(kBlack);
            gKsAmptF[c]  ->SetLineColor(kBlue);
            gKsTrentoF[c]->SetLineColor(kBlue);
            gLmAmptF[c]  ->SetLineColor(kRed);
            gLmTrentoF[c]->SetLineColor(kRed);

            gChAmptF[c]  ->SetLineStyle(kSolid);
            gChTrentoF[c]->SetLineStyle(kDashed);
            gKsAmptF[c]  ->SetLineStyle(kSolid);
            gKsTrentoF[c]->SetLineStyle(kDashed);
            gLmAmptF[c]  ->SetLineStyle(kSolid);
            gLmTrentoF[c]->SetLineStyle(kDashed);

            gChAmptF[c]->Draw("lsame");
            gKsAmptF[c]->Draw("lsame");
            gLmAmptF[c]->Draw("lsame");
        }

        gChF[c]->Draw("psame");
        gKsF[c]->Draw("psame");
        gLmF[c]->Draw("psame");
    }

    cPbPbV2->cd(1);
    latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    TLegend * legFl = new TLegend(0.35, 0.65, 0.75, 0.92);
    legFl->SetFillColor(kWhite);
    legFl->SetTextFont(42);
    legFl->SetTextSize(0.05);
    legFl->SetBorderSize(0);

    legFl->AddEntry(gChF[1], "charge hadron", "p");
    legFl->AddEntry(gKsF[1], "K_{S}^{0}", "p");
    legFl->AddEntry(gLmF[1], "#Lambda", "p");

    cPbPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[2]).c_str());
    legFl->Draw();

    cPbPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[3]).c_str());

    cPbPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[4]).c_str());
    cPbPbV2->SaveAs("PbPbV2_Fluct.pdf");

    /***** Plot fluctuation separately ******/
    // Ch
    for ( int c = 1; c < 5; c++ ) {
        cPbPbV2->cd(c);
        hframe_fluct->Draw();
        gChAmptF[c]->SetLineColor(kRed);
        gChTrentoF[c]->SetLineColor(kBlue);
        gChAmptF[c]->Draw("lsame");
        gChTrentoF[c]->Draw("lsame");
        gChF[c]->Draw("psame");
    }
    cPbPbV2->cd(1);
    latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS} charge hadron");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    cPbPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[2]).c_str());
    TLegend * legFlCh = new TLegend(0.35, 0.65, 0.75, 0.92);
    legFlCh->SetFillColor(kWhite);
    legFlCh->SetTextFont(42);
    legFlCh->SetTextSize(0.05);
    legFlCh->SetBorderSize(0);

    legFlCh->AddEntry(gChF[1], "data", "p");
    legFlCh->AddEntry(gChAmptF[1], "AMPT-IC", "l");
    legFlCh->AddEntry(gChTrentoF[1], "Trento-IC", "l");

    legFlCh->Draw();

    cPbPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[3]).c_str());

    cPbPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[4]).c_str());
    cPbPbV2->SaveAs("PbPbV2_Fluct_Ch.pdf");

    // Ks
    for ( int c = 1; c < 5; c++ ) {
        cPbPbV2->cd(c);
        hframe_fluct->Draw();
        gKsAmptF[c]->SetLineColor(kRed);
        gKsTrentoF[c]->SetLineColor(kBlue);
        gKsAmptF[c]->Draw("lsame");
        gKsTrentoF[c]->Draw("lsame");
        gKsF[c]->Draw("psame");
    }
    cPbPbV2->cd(1);
    latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS} K_{S}^{0}");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    cPbPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[2]).c_str());
    TLegend * legFlKs = new TLegend(0.35, 0.65, 0.75, 0.92);
    legFlKs->SetFillColor(kWhite);
    legFlKs->SetTextFont(42);
    legFlKs->SetTextSize(0.05);
    legFlKs->SetBorderSize(0);

    legFlKs->AddEntry(gChF[1], "data", "p");
    legFlKs->AddEntry(gChAmptF[1], "AMPT-IC", "l");
    legFlKs->AddEntry(gChTrentoF[1], "Trento-IC", "l");

    legFlKs->Draw();

    cPbPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[3]).c_str());

    cPbPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[4]).c_str());
    cPbPbV2->SaveAs("PbPbV2_Fluct_Ks.pdf");

    // Lm
    for ( int c = 1; c < 5; c++ ) {
        cPbPbV2->cd(c);
        hframe_fluct->Draw();
        gLmAmptF[c]->SetLineColor(kRed);
        gLmTrentoF[c]->SetLineColor(kBlue);
        gLmAmptF[c]->Draw("lsame");
        gLmTrentoF[c]->Draw("lsame");
        gLmF[c]->Draw("psame");
    }
    cPbPbV2->cd(1);
    latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS} #Lambda");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    cPbPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[2]).c_str());
    TLegend * legFlLm = new TLegend(0.35, 0.65, 0.75, 0.92);
    legFlLm->SetFillColor(kWhite);
    legFlLm->SetTextFont(42);
    legFlLm->SetTextSize(0.05);
    legFlLm->SetBorderSize(0);

    legFlLm->AddEntry(gChF[1], "data", "p");
    legFlLm->AddEntry(gChAmptF[1], "AMPT-IC", "l");
    legFlLm->AddEntry(gChTrentoF[1], "Trento-IC", "l");

    legFlLm->Draw();

    cPbPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[3]).c_str());

    cPbPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[4]).c_str());
    cPbPbV2->SaveAs("PbPbV2_Fluct_Lm.pdf");
    /*****************/

    // sub-event ch
    for ( int c = 1; c < 5; c++ ) {
        cPbPbV2->cd(c);
        hframe_pt->Draw();

        ch_v2_PbPb[c]->vn_MergedEta->SetMarkerStyle(kFullCircle);
        ch_v2_PbPb[c]->vn_MergedEta->SetMarkerColor(kBlue);
        ch_v2_PbPb[c]->vn_MergedEta->SetLineColor  (kBlue);
        ch_v2_PbPb[c]->vn_MergedEta->SetMarkerSize(2.);

        ch_v2_PbPb[c]->vn_MergedEta_SubEvt->SetMarkerStyle(kOpenCircle);
        ch_v2_PbPb[c]->vn_MergedEta_SubEvt->SetMarkerColor(kRed);
        ch_v2_PbPb[c]->vn_MergedEta_SubEvt->SetLineColor  (kRed);
        ch_v2_PbPb[c]->vn_MergedEta_SubEvt->SetMarkerSize(2.);

        vH.grSig_pT[2][1][c]->SetMarkerStyle(kFullSquare);
        vH.grSig_pT[2][1][c]->SetMarkerColor(kBlue);
        vH.grSig_pT[2][1][c]->SetLineColor  (kBlue);
        vH.grSig_pT[2][1][c]->SetMarkerSize(2.);

        vH.grSig_V2sub4merge[c]->SetMarkerStyle(kOpenSquare);
        vH.grSig_V2sub4merge[c]->SetMarkerColor(kRed);
        vH.grSig_V2sub4merge[c]->SetLineColor  (kRed);
        vH.grSig_V2sub4merge[c]->SetMarkerSize(2.);

//        ch_v2_PbPb[c]->vn_MergedEta       ->Draw("psame");
//        ch_v2_PbPb[c]->vn_MergedEta_SubEvt->Draw("psame");
        vH.grSig_pT[2][1][c]->Draw("psame");
        vH.grSig_V2sub4merge[c]->Draw("psame");
    }

    cPbPbV2->cd(1);
    latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS} charge hadron");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    TLegend * legSubCh = new TLegend(0.55, 0.65, 0.95, 0.92);
    legSubCh->SetFillColor(kWhite);
    legSubCh->SetTextFont(42);
    legSubCh->SetTextSize(0.05);
    legSubCh->SetBorderSize(0);

//    legSubCh->AddEntry(ch_v2_PbPb[1]->vn_MergedEta,        "v_{2}{SP}", "p");
//    legSubCh->AddEntry(ch_v2_PbPb[1]->vn_MergedEta_SubEvt, "v_{2}{SP,Sub}", "p");
    legSubCh->AddEntry(vH.grSig_pT[2][1][1], "v_{2}{4}", "p");
    legSubCh->AddEntry(vH.grSig_V2sub4merge[1], "v_{2}{4,Sub}", "p");

    legSubCh->Draw();

    cPbPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[2]).c_str());

    cPbPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[3]).c_str());

    cPbPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[4]).c_str());
    cPbPbV2->SaveAs("PbPbV2_Subevt_Ch.pdf");

    // sub-event Ks
    for ( int c = 1; c < 5; c++ ) {
        cPbPbV2->cd(c);
        hframe_pt->Draw();

        Ks_v2_PbPb_Sig[c]->vn_MergedEta->SetMarkerStyle(kFullCircle);
        Ks_v2_PbPb_Sig[c]->vn_MergedEta->SetMarkerColor(kBlue);
        Ks_v2_PbPb_Sig[c]->vn_MergedEta->SetLineColor  (kBlue);
        Ks_v2_PbPb_Sig[c]->vn_MergedEta->SetMarkerSize(2.);

        Ks_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt->SetMarkerStyle(kOpenCircle);
        Ks_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt->SetMarkerColor(kRed);
        Ks_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt->SetLineColor  (kRed);
        Ks_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt->SetMarkerSize(2.);

        vKs.grSig_pT[2][1][c]->SetMarkerStyle(kFullSquare);
        vKs.grSig_pT[2][1][c]->SetMarkerColor(kBlue);
        vKs.grSig_pT[2][1][c]->SetLineColor  (kBlue);
        vKs.grSig_pT[2][1][c]->SetMarkerSize(2.);

        vKs.grSig_V2sub4merge[c]->SetMarkerStyle(kOpenSquare);
        vKs.grSig_V2sub4merge[c]->SetMarkerColor(kRed);
        vKs.grSig_V2sub4merge[c]->SetLineColor  (kRed);
        vKs.grSig_V2sub4merge[c]->SetMarkerSize(2.);

//        Ks_v2_PbPb_Sig[c]->vn_MergedEta       ->Draw("psame");
//        Ks_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt->Draw("psame");
        vKs.grSig_pT[2][1][c]->Draw("psame");
        vKs.grSig_V2sub4merge[c]->Draw("psame");
    }

    cPbPbV2->cd(1);
    latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS} K_{S}^{0}");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    TLegend * legSubKs = new TLegend(0.55, 0.65, 0.95, 0.92);
    legSubKs->SetFillColor(kWhite);
    legSubKs->SetTextFont(42);
    legSubKs->SetTextSize(0.05);
    legSubKs->SetBorderSize(0);

//    legSubKs->AddEntry(Ks_v2_PbPb_Sig[1]->vn_MergedEta,        "v_{2}{SP}", "p");
//    legSubKs->AddEntry(Ks_v2_PbPb_Sig[1]->vn_MergedEta_SubEvt, "v_{2}{SP,Sub}", "p");
    legSubKs->AddEntry(vKs.grSig_pT[2][1][1], "v_{2}{4}", "p");
    legSubKs->AddEntry(vKs.grSig_V2sub4merge[1], "v_{2}{4,Sub}", "p");

    legSubKs->Draw();

    cPbPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[2]).c_str());

    cPbPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[3]).c_str());

    cPbPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[4]).c_str());
    cPbPbV2->SaveAs("PbPbV2_Subevt_Ks.pdf");

    // sub-event Lm
    for ( int c = 1; c < 5; c++ ) {
        cPbPbV2->cd(c);
        hframe_pt->Draw();

        Lm_v2_PbPb_Sig[c]->vn_MergedEta->SetMarkerStyle(kFullCircle);
        Lm_v2_PbPb_Sig[c]->vn_MergedEta->SetMarkerColor(kBlue);
        Lm_v2_PbPb_Sig[c]->vn_MergedEta->SetLineColor  (kBlue);
        Lm_v2_PbPb_Sig[c]->vn_MergedEta->SetMarkerSize(2.);

        Lm_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt->SetMarkerStyle(kOpenCircle);
        Lm_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt->SetMarkerColor(kRed);
        Lm_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt->SetLineColor  (kRed);
        Lm_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt->SetMarkerSize(2.);

        vLm.grSig_pT[2][1][c]->SetMarkerStyle(kFullSquare);
        vLm.grSig_pT[2][1][c]->SetMarkerColor(kBlue);
        vLm.grSig_pT[2][1][c]->SetLineColor  (kBlue);
        vLm.grSig_pT[2][1][c]->SetMarkerSize(2.);

        vLm.grSig_V2sub4merge[c]->SetMarkerStyle(kOpenSquare);
        vLm.grSig_V2sub4merge[c]->SetMarkerColor(kRed);
        vLm.grSig_V2sub4merge[c]->SetLineColor  (kRed);
        vLm.grSig_V2sub4merge[c]->SetMarkerSize(2.);

//        Lm_v2_PbPb_Sig[c]->vn_MergedEta       ->Draw("psame");
//        Lm_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt->Draw("psame");
        vLm.grSig_pT[2][1][c]->Draw("psame");
        vLm.grSig_V2sub4merge[c]->Draw("psame");
    }

    cPbPbV2->cd(1);
    latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS} #Lambda");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    TLegend * legSubLm = new TLegend(0.55, 0.65, 0.95, 0.92);
    legSubLm->SetFillColor(kWhite);
    legSubLm->SetTextFont(42);
    legSubLm->SetTextSize(0.05);
    legSubLm->SetBorderSize(0);

//    legSubLm->AddEntry(Lm_v2_PbPb_Sig[1]->vn_MergedEta,        "v_{2}{SP}", "p");
//    legSubLm->AddEntry(Lm_v2_PbPb_Sig[1]->vn_MergedEta_SubEvt, "v_{2}{SP,Sub}", "p");
    legSubLm->AddEntry(vLm.grSig_pT[2][1][1], "v_{2}{4}", "p");
    legSubLm->AddEntry(vLm.grSig_V2sub4merge[1], "v_{2}{4,Sub}", "p");

    legSubLm->Draw();

    cPbPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[2]).c_str());

    cPbPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[3]).c_str());

    cPbPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[4]).c_str());
    cPbPbV2->SaveAs("PbPbV2_Subevt_Lm.pdf");

    // sub-event ratio
    TH2D * hframe_ratio = new TH2D("hframe_ratio", "hframe_ratio", 1, 0.01, 8.5, 1, 0.95, 1.05);
    InitHist(hframe_ratio, "p_{T}", "Ratio");
    hframe_ratio->GetYaxis()->SetTitleOffset(1.0);
    hframe_ratio->GetXaxis()->SetTitleOffset(0.90);

    TH2D * hframe_ratio1 = new TH2D("hframe_ratio1", "hframe_ratio1", 1, 0.01, 8.5, 1, 0.8, 1.25);
    InitHist(hframe_ratio1, "p_{T}", "Ratio");
    hframe_ratio1->GetYaxis()->SetTitleOffset(1.0);
    hframe_ratio1->GetXaxis()->SetTitleOffset(0.90);

    TGraphErrors* gChRatioCu[5] = {};
    TGraphErrors* gKsRatioCu[5] = {};
    TGraphErrors* gLmRatioCu[5] = {};

    TGraphErrors* gChRatioSP[5] = {};
    TGraphErrors* gKsRatioSP[5] = {};
    TGraphErrors* gLmRatioSP[5] = {};

    for ( int c = 1; c < 5; c++ ) {
        cPbPbV2->cd(c);
        hframe_ratio->Draw();
        line1.Draw();

        gChRatioSP[c]= getRatio( ch_v2_PbPb[c]->vn_MergedEta_SubEvt,     ch_v2_PbPb[c]->vn_MergedEta );
        gKsRatioSP[c]= getRatio( Ks_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt, Ks_v2_PbPb_Sig[c]->vn_MergedEta );
        gLmRatioSP[c]= getRatio( Lm_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt, Lm_v2_PbPb_Sig[c]->vn_MergedEta );

        gChRatioSP[c]->SetMarkerStyle(kOpenSquare);
        gChRatioSP[c]->SetMarkerColor(kBlue);
        gChRatioSP[c]->SetLineColor  (kBlue);
        gChRatioSP[c]->SetMarkerSize(2.);

        gKsRatioSP[c]->SetMarkerStyle(kOpenCircle);
        gKsRatioSP[c]->SetMarkerColor(kBlack);
        gKsRatioSP[c]->SetLineColor  (kBlack);
        gKsRatioSP[c]->SetMarkerSize(2.);

        gLmRatioSP[c]->SetMarkerStyle(kOpenDiamond);
        gLmRatioSP[c]->SetMarkerColor(kRed);
        gLmRatioSP[c]->SetLineColor  (kRed);
        gLmRatioSP[c]->SetMarkerSize(2.);

        gChRatioSP[c]->Draw("psame");
        gKsRatioSP[c]->Draw("psame");
        gLmRatioSP[c]->Draw("psame");

        //
        cPbPbV2_1->cd(c);
        hframe_ratio1->Draw();
        line1.Draw();

        gChRatioCu[c]= getRatio( vH.grSig_V2sub4merge[c],  vH.grSig_pT[2][1][c] );
        gKsRatioCu[c]= getRatio( vKs.grSig_V2sub4merge[c], vKs.grSig_pT[2][1][c] );
        gLmRatioCu[c]= getRatio( vLm.grSig_V2sub4merge[c], vLm.grSig_pT[2][1][c] );

        gChRatioCu[c]->SetMarkerStyle(kOpenSquare);
        gChRatioCu[c]->SetMarkerColor(kBlue);
        gChRatioCu[c]->SetLineColor  (kBlue);
        gChRatioCu[c]->SetMarkerSize(2.);

        gKsRatioCu[c]->SetMarkerStyle(kOpenCircle);
        gKsRatioCu[c]->SetMarkerColor(kBlack);
        gKsRatioCu[c]->SetLineColor  (kBlack);
        gKsRatioCu[c]->SetMarkerSize(2.);

        gLmRatioCu[c]->SetMarkerStyle(kOpenDiamond);
        gLmRatioCu[c]->SetMarkerColor(kRed);
        gLmRatioCu[c]->SetLineColor  (kRed);
        gLmRatioCu[c]->SetMarkerSize(2.);

        gChRatioCu[c]->Draw("psame");
        gKsRatioCu[c]->Draw("psame");
        gLmRatioCu[c]->Draw("psame");
    }
    cPbPbV2->cd(1);
    latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS} v_{2}{SP,Sub}/v_{2}{SP}");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    TLegend * legSP_R = new TLegend(0.10, 0.60, 0.40, 0.85);
    legSP_R->SetFillColor(kWhite);
    legSP_R->SetTextFont(42);
    legSP_R->SetTextSize(0.05);
    legSP_R->SetBorderSize(0);

    legSP_R->AddEntry(gChRatioSP[1], "charge hadron", "p");
    legSP_R->AddEntry(gKsRatioSP[1], "K_{S}^{0}", "p");
    legSP_R->AddEntry(gLmRatioSP[1], "#Lambda", "p");

    cPbPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[2]).c_str());
    legSP_R->Draw();

    cPbPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[3]).c_str());

    cPbPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[4]).c_str());

//    cPbPbV2  ->SaveAs("PbPbV2_SubevtSP_Ratio.pdf");

    //
    cPbPbV2_1->cd(1);
    latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS} v_{2}{4,Sub}/v_{2}{4}");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    TLegend * legCu_R = new TLegend(0.10, 0.60, 0.40, 0.85);
    legCu_R->SetFillColor(kWhite);
    legCu_R->SetTextFont(42);
    legCu_R->SetTextSize(0.05);
    legCu_R->SetBorderSize(0);

    legCu_R->AddEntry(gChRatioCu[1], "charge hadron", "p");
    legCu_R->AddEntry(gKsRatioCu[1], "K_{S}^{0}", "p");
    legCu_R->AddEntry(gLmRatioCu[1], "#Lambda", "p");

    cPbPbV2_1->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[2]).c_str());
    legCu_R->Draw();

    cPbPbV2_1->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[3]).c_str());

    cPbPbV2_1->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[4]).c_str());

    cPbPbV2_1->SaveAs("PbPbV2_SubevtCu_Ratio.pdf");
    //
    // v26/v24 v28/v24 ratio

    TGraphErrors* gCh64Ratio[5] = {};
    TGraphErrors* gKs64Ratio[5] = {};
    TGraphErrors* gLm64Ratio[5] = {};

    TGraphErrors* gCh84Ratio[5] = {};
    TGraphErrors* gKs84Ratio[5] = {};
    TGraphErrors* gLm84Ratio[5] = {};

    for ( int c = 1; c < 5; c++ ) {
        cPbPbV2->cd(c);
        hframe_ratio1->Draw();
        line1.Draw();

        gCh64Ratio[c] = getRatio( vH .grSig_pT[2][2][c], vH .grSig_pT[2][1][c] );
        gKs64Ratio[c] = getRatio( vKs.grSig_pT[2][2][c], vKs.grSig_pT[2][1][c] );
        gLm64Ratio[c] = getRatio( vLm.grSig_pT[2][2][c], vLm.grSig_pT[2][1][c] );

        gCh84Ratio[c] = getRatio( vH .grSig_pT[2][3][c], vH .grSig_pT[2][1][c] );
        gKs84Ratio[c] = getRatio( vKs.grSig_pT[2][3][c], vKs.grSig_pT[2][1][c] );
        gLm84Ratio[c] = getRatio( vLm.grSig_pT[2][3][c], vLm.grSig_pT[2][1][c] );

        gCh64Ratio[c]->SetMarkerStyle(kOpenCircle);
        gKs64Ratio[c]->SetMarkerStyle(kOpenSquare);
        gLm64Ratio[c]->SetMarkerStyle(kOpenCircle);
        gCh64Ratio[c]->SetMarkerSize(2.);
        gKs64Ratio[c]->SetMarkerSize(2.);
        gLm64Ratio[c]->SetMarkerSize(2.);

        gCh64Ratio[c]->SetMarkerColor(kBlack);
        gKs64Ratio[c]->SetMarkerColor(kBlue);
        gLm64Ratio[c]->SetMarkerColor(kRed);

        gCh64Ratio[c]->SetLineColor(kBlack);
        gKs64Ratio[c]->SetLineColor(kBlue);
        gLm64Ratio[c]->SetLineColor(kRed);

        gCh84Ratio[c]->SetMarkerStyle(kOpenCircle);
        gKs84Ratio[c]->SetMarkerStyle(kOpenSquare);
        gLm84Ratio[c]->SetMarkerStyle(kOpenCircle);
        gCh84Ratio[c]->SetMarkerSize(2.);
        gKs84Ratio[c]->SetMarkerSize(2.);
        gLm84Ratio[c]->SetMarkerSize(2.);

        gCh84Ratio[c]->SetMarkerColor(kBlack);
        gKs84Ratio[c]->SetMarkerColor(kBlue);
        gLm84Ratio[c]->SetMarkerColor(kRed);

        gCh84Ratio[c]->SetLineColor(kBlack);
        gKs84Ratio[c]->SetLineColor(kBlue);
        gLm84Ratio[c]->SetLineColor(kRed);

        gCh64Ratio[c]->Draw("psame");
        gKs64Ratio[c]->Draw("psame");
        gLm64Ratio[c]->Draw("psame");

        //
        cPbPbV2_1->cd(c);
        hframe_ratio1->Draw();
        line1.Draw();

        gCh84Ratio[c]->Draw("psame");
        gKs84Ratio[c]->Draw("psame");
        gLm84Ratio[c]->Draw("psame");
    }
    cPbPbV2->cd(1);
    latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS} v_{2}{6}/v_{2}{4}");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    cPbPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[2]).c_str());

    TLegend * leg64 = new TLegend(0.35, 0.65, 0.75, 0.92);
    leg64->SetFillColor(kWhite);
    leg64->SetTextFont(42);
    leg64->SetTextSize(0.05);
    leg64->SetBorderSize(0);

    leg64->AddEntry(gCh64Ratio[1], "charged hadron", "p");
    leg64->AddEntry(gKs64Ratio[1], "K_{S}^{0}", "p");
    leg64->AddEntry(gLm64Ratio[1], "#Lambda", "p");
    leg64->Draw();

    cPbPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[3]).c_str());

    cPbPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[4]).c_str());

    cPbPbV2->SaveAs("PbPbV2_V64_ratio.pdf");

    //
    cPbPbV2_1->cd(1);
    latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS} v_{2}{8}/v_{2}{4}");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    cPbPbV2_1->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[2]).c_str());

    TLegend * leg86 = new TLegend(0.35, 0.65, 0.75, 0.92);
    leg86->SetFillColor(kWhite);
    leg86->SetTextFont(42);
    leg86->SetTextSize(0.05);
    leg86->SetBorderSize(0);

    leg86->AddEntry(gCh64Ratio[1], "charged hadron", "p");
    leg86->AddEntry(gKs64Ratio[1], "K_{S}^{0}", "p");
    leg86->AddEntry(gLm64Ratio[1], "#Lambda", "p");
    leg86->Draw();

    cPbPbV2_1->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[3]).c_str());

    cPbPbV2_1->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[4]).c_str());

    cPbPbV2_1->SaveAs("PbPbV2_V84_ratio.pdf");

}
