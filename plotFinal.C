#include "../../style.h"
#include "theory.h"
#include "PbPb_header.h"

void plotFinal(bool bPre = false, bool bAmpt = true)
{
    TFile * fH  = new TFile("PbPb2018_H_corrected.root");
    TFile * fKs = new TFile("PbPb2018_Ks_corrected.root");
    TFile * fLm = new TFile("PbPb2018_Lm_corrected.root");

    TFile * fsave = new TFile("plotFinal.root", "recreate");
    SaveToFile s2f(fsave);

    TFile * fpPb = new TFile("plotFinalpPb.root");

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
    TLine line0(0.1, 0., 8.5, 0.);

    TCanvas * cPbPbV2 = MakeCanvas("cPbPbV2", "cPbPbV2", 1400, 400);
    splitCanv4(cPbPbV2);

    TCanvas * cPbPbV2_1 = MakeCanvas("cPbPbV2_1", "cPbPbV2_1", 1400, 400);
    splitCanv4(cPbPbV2_1);

    TH2D * hframe_pt = new TH2D("hframe_pt", "hframe_pt", 1, 0.01, 8.5, 1, 0, 0.36);
    InitHist(hframe_pt, "p_{T} (GeV)", "v_{2}");
    hframe_pt->GetYaxis()->SetTitleOffset(1.0);
    hframe_pt->GetXaxis()->SetTitleOffset(0.90);

    // Ch v2
    for ( int c = 1; c < 5; c++ ) {
        auto p = cPbPbV2->cd(c);
//        p->SetLogx();
        hframe_pt->Draw();

        ch_v2_PbPb[c]   ->vn_MergedEta->SetMarkerStyle(kOpenSquare);
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
        ampt  ->grCh_v22[c]->SetLineWidth(0);
        ampt  ->grCh_v24[c]->SetLineWidth(0);
        ampt  ->grCh_v22[c]->SetFillColor(3003);
        ampt  ->grCh_v24[c]->SetFillColor(3001);

        trento  ->grCh_v22[c]->SetLineColor(kRed);
        trento  ->grCh_v24[c]->SetLineColor(kBlue);
        trento  ->grCh_v22[c]->SetLineWidth(0);
        trento  ->grCh_v24[c]->SetLineWidth(0);
        trento  ->grCh_v22[c]->SetFillColor(3003);
        trento  ->grCh_v24[c]->SetFillColor(3001);

        if ( bAmpt ) {
            ampt  ->grCh_v22[c]->Draw("[]3");
            ampt  ->grCh_v24[c]->Draw("[]3");
        } else {
            trento->grCh_v22[c]->Draw("[]3");
            trento->grCh_v24[c]->Draw("[]3");
        }
//        trento->grCh_v22[c]->Draw("lsame");
//        trento->grCh_v24[c]->Draw("lsame");

        s2f.WriteGr(ch_v2_sysPbPb[c]->vn_MergedEta, Form("grChSysSig_v2sp_%i", c));
        s2f.WriteGr(ch_v2_PbPb[c]   ->vn_MergedEta, Form("grChSig_v2sp_%i", c));

        s2f.WriteGr(vH.grSysSig_pT[2][1][c], Form("grChSysSig_v24_%i", c));
        s2f.WriteGr(vH.grSysSig_pT[2][2][c], Form("grChSysSig_v26_%i", c));
        s2f.WriteGr(vH.grSysSig_pT[2][3][c], Form("grChSysSig_v28_%i", c));

        s2f.WriteGr(vH.grSig_pT[2][1][c], Form("grChSig_v24_%i", c));
        s2f.WriteGr(vH.grSig_pT[2][2][c], Form("grChSig_v26_%i", c));
        s2f.WriteGr(vH.grSig_pT[2][3][c], Form("grChSig_v28_%i", c));

        s2f.WriteGr(ampt  ->grCh_v22[c], Form("grChAMPT_v22_%i", c));
        s2f.WriteGr(ampt  ->grCh_v24[c], Form("grChAMPT_v24_%i", c));
        s2f.WriteGr(trento->grCh_v22[c], Form("grChTrento_v22_%i", c));
        s2f.WriteGr(trento->grCh_v24[c], Form("grChTrento_v24_%i", c));
    }
    cPbPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{Charge hadron}");
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

    TLegend * legChTh = new TLegend(0.55, 0.72, 0.90, 0.92);
    legChTh->SetFillColor(kWhite);
    legChTh->SetTextFont(42);
    legChTh->SetTextSize(0.05);
    legChTh->SetBorderSize(0);
    if ( bAmpt ) {
        legChTh->AddEntry(ampt  ->grCh_v22[2], "AMPT-IC v_{2}{2}", "f");
        legChTh->AddEntry(ampt  ->grCh_v24[2], "AMPT-IC v_{2}{4}", "f");
    } else {
        legChTh->AddEntry(trento->grCh_v22[2], "Trento-IC v_{2}{2}", "f");
        legChTh->AddEntry(trento->grCh_v24[2], "Trento-IC v_{2}{4}", "f");
    }
    legChTh->Draw();

    cPbPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[3]).c_str());
    cPbPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[4]).c_str());
    if ( bAmpt ) {
        cPbPbV2->SaveAs("PbPbV2_Ch.pdf");
    } else {
        cPbPbV2->SaveAs("PbPbV2_Ch_Trento.pdf");
    }

    // Ks v2
    for ( int c = 1; c < 5; c++ ) {
        cPbPbV2->cd(c);
        hframe_pt->Draw();

        Ks_v2_PbPb_Sig[c]   ->vn_MergedEta->SetMarkerStyle(kOpenSquare);
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

        ampt  ->grKs_v22[c]->SetLineColor(kRed);
        ampt  ->grKs_v24[c]->SetLineColor(kBlue);
        ampt  ->grKs_v22[c]->SetLineWidth(0);
        ampt  ->grKs_v24[c]->SetLineWidth(0);
        ampt  ->grKs_v22[c]->SetFillColor(3003);
        ampt  ->grKs_v24[c]->SetFillColor(3001);

        trento->grKs_v22[c]->SetLineColor(kRed);
        trento->grKs_v24[c]->SetLineColor(kBlue);
        trento->grKs_v22[c]->SetLineWidth(0);
        trento->grKs_v24[c]->SetLineWidth(0);
        trento->grKs_v22[c]->SetFillColor(3003);
        trento->grKs_v24[c]->SetFillColor(3001);

        if ( bAmpt ) {
            ampt  ->grKs_v22[c]->Draw("[]3");
            ampt  ->grKs_v24[c]->Draw("[]3");
        } else {
            trento->grKs_v22[c]->Draw("[]3");
            trento->grKs_v24[c]->Draw("[]3");
        }

        vKs.grSysSig_pT[2][1][c] ->Draw("[]2");
        vKs.grSysSig_pT[2][2][c] ->Draw("[]2");
        vKs.grSysSig_pT[2][3][c] ->Draw("[]2");

        vKs.grSig_pT[2][1][c]    ->Draw("psame");
        vKs.grSig_pT[2][2][c]    ->Draw("psame");
        vKs.grSig_pT[2][3][c]    ->Draw("psame");

        s2f.WriteGr(Ks_v2_sysPbPb_Sig[c]->vn_MergedEta, Form("grKsSysSig_v2sp_%i", c));
        s2f.WriteGr(Ks_v2_PbPb_Sig[c]   ->vn_MergedEta, Form("grKsSig_v2sp_%i", c));

        s2f.WriteGr(vKs.grSysSig_pT[2][1][c], Form("grKsSysSig_v24_%i", c));
        s2f.WriteGr(vKs.grSysSig_pT[2][2][c], Form("grKsSysSig_v26_%i", c));
        s2f.WriteGr(vKs.grSysSig_pT[2][3][c], Form("grKsSysSig_v28_%i", c));

        s2f.WriteGr(vKs.grSig_pT[2][1][c], Form("grKsSig_v24_%i", c));
        s2f.WriteGr(vKs.grSig_pT[2][2][c], Form("grKsSig_v26_%i", c));
        s2f.WriteGr(vKs.grSig_pT[2][3][c], Form("grKsSig_v28_%i", c));

        s2f.WriteGr(ampt  ->grKs_v22[c], Form("grKsAMPT_v22_%i", c));
        s2f.WriteGr(ampt  ->grKs_v24[c], Form("grKsAMPT_v24_%i", c));
        s2f.WriteGr(trento->grKs_v22[c], Form("grKsTrento_v22_%i", c));
        s2f.WriteGr(trento->grKs_v24[c], Form("grKsTrento_v24_%i", c));
    }
    cPbPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.82, "#bf{K_{S}^{0}}");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    TLegend * legKs = new TLegend(0.60, 0.55, 0.90, 0.90);
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

    TLegend * legKsTh = new TLegend(0.55, 0.72, 0.90, 0.92);
    legKsTh->SetFillColor(kWhite);
    legKsTh->SetTextFont(42);
    legKsTh->SetTextSize(0.05);
    legKsTh->SetBorderSize(0);

    if ( bAmpt ) {
        legKsTh->AddEntry(ampt  ->grKs_v22[2], "AMPT-IC v_{2}{2}", "f");
        legKsTh->AddEntry(ampt  ->grKs_v24[2], "AMPT-IC v_{2}{4}", "f");
    } else {
        legKsTh->AddEntry(trento->grKs_v22[2], "Trento-IC v_{2}{2}", "f");
        legKsTh->AddEntry(trento->grKs_v24[2], "Trento-IC v_{2}{4}", "f");
    }

    legKsTh->Draw();

    cPbPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[3]).c_str());
    cPbPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[4]).c_str());

    if ( bAmpt ) {
        cPbPbV2->SaveAs("PbPbV2_Ks.pdf");
    } else {
        cPbPbV2->SaveAs("PbPbV2_Ks_Trento.pdf");
    }


    // Lm v2
    for ( int c = 1; c < 5; c++ ) {
        cPbPbV2->cd(c);
        hframe_pt->Draw();

        Lm_v2_PbPb_Sig[c]   ->vn_MergedEta->SetMarkerStyle(kOpenSquare);
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

        ampt  ->grLm_v22[c]->SetLineColor(kRed);
        ampt  ->grLm_v24[c]->SetLineColor(kBlue);
        ampt  ->grLm_v22[c]->SetLineWidth(0);
        ampt  ->grLm_v24[c]->SetLineWidth(0);
        ampt  ->grLm_v22[c]->SetFillColor(3003);
        ampt  ->grLm_v24[c]->SetFillColor(3001);

        trento->grLm_v22[c]->SetLineColor(kRed);
        trento->grLm_v24[c]->SetLineColor(kBlue);
        trento->grLm_v22[c]->SetLineWidth(0);
        trento->grLm_v24[c]->SetLineWidth(0);
        trento->grLm_v22[c]->SetFillColor(3003);
        trento->grLm_v24[c]->SetFillColor(3001);

        if ( bAmpt ) {
            ampt  ->grLm_v22[c]->Draw("[]3");
            ampt  ->grLm_v24[c]->Draw("[]3");
        } else {
            trento->grLm_v22[c]->Draw("[]3");
            trento->grLm_v24[c]->Draw("[]3");
        }

        vLm.grSysSig_pT[2][1][c] ->Draw("[]2");
        vLm.grSysSig_pT[2][2][c] ->Draw("[]2");
        vLm.grSysSig_pT[2][3][c] ->Draw("[]2");

        vLm.grSig_pT[2][1][c]    ->Draw("psame");
        vLm.grSig_pT[2][2][c]    ->Draw("psame");
        vLm.grSig_pT[2][3][c]    ->Draw("psame");

        s2f.WriteGr(Lm_v2_sysPbPb_Sig[c]->vn_MergedEta, Form("grLmSysSig_v2sp_%i", c));
        s2f.WriteGr(Lm_v2_PbPb_Sig[c]   ->vn_MergedEta, Form("grLmSig_v2sp_%i", c));

        s2f.WriteGr(vLm.grSysSig_pT[2][1][c], Form("grLmSysSig_v24_%i", c));
        s2f.WriteGr(vLm.grSysSig_pT[2][2][c], Form("grLmSysSig_v26_%i", c));
        s2f.WriteGr(vLm.grSysSig_pT[2][3][c], Form("grLmSysSig_v28_%i", c));

        s2f.WriteGr(vLm.grSig_pT[2][1][c], Form("grLmSig_v24_%i", c));
        s2f.WriteGr(vLm.grSig_pT[2][2][c], Form("grLmSig_v26_%i", c));
        s2f.WriteGr(vLm.grSig_pT[2][3][c], Form("grLmSig_v28_%i", c));

        s2f.WriteGr(ampt  ->grLm_v22[c], Form("grLmAMPT_v22_%i", c));
        s2f.WriteGr(ampt  ->grLm_v24[c], Form("grLmAMPT_v24_%i", c));
        s2f.WriteGr(trento->grLm_v22[c], Form("grLmTrento_v22_%i", c));
        s2f.WriteGr(trento->grLm_v24[c], Form("grLmTrento_v24_%i", c));
    }
    cPbPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{#Lambda}");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    TLegend * legLm = new TLegend(0.60, 0.55, 0.90, 0.90);
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

//    TLegend * legLmTh = new TLegend(0.40, 0.15, 0.75, 0.47);
    TLegend * legLmTh = new TLegend(0.55, 0.72, 0.90, 0.92);
    legLmTh->SetFillColor(kWhite);
    legLmTh->SetTextFont(42);
    legLmTh->SetTextSize(0.05);
    legLmTh->SetBorderSize(0);

    if ( bAmpt ) {
        legLmTh->AddEntry(ampt  ->grLm_v22[2], "AMPT-IC v_{2}{2}", "f");
        legLmTh->AddEntry(ampt  ->grLm_v24[2], "AMPT-IC v_{2}{4}", "f");
    } else {
        legLmTh->AddEntry(trento->grLm_v22[2], "Trento-IC v_{2}{2}", "f");
        legLmTh->AddEntry(trento->grLm_v24[2], "Trento-IC v_{2}{4}", "f");
    }

    legLmTh->Draw();

    cPbPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[3]).c_str());
    cPbPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[4]).c_str());

    if ( bAmpt ) {
        cPbPbV2->SaveAs("PbPbV2_Lm.pdf");
    } else {
        cPbPbV2->SaveAs("PbPbV2_Lm_Trento.pdf");
    }

    // fluctuation
    TH2D * hframe_fluct = new TH2D("hframe_fluct", "hframe_fluct", 1, 0.01, 8.5, 1, 0.01, 1.3);
    InitHist(hframe_fluct, "p_{T} (GeV)", "#sigma / #LT v_{2} #GT");
    hframe_fluct->GetYaxis()->SetTitleOffset(1.0);
    hframe_fluct->GetXaxis()->SetTitleOffset(0.90);

    TGraphErrors * gChF[5] = {};
    TGraphErrors * gKsF[5] = {};
    TGraphErrors * gLmF[5] = {};

    TGraphErrors * gChF_sys[5] = {};
    TGraphErrors * gKsF_sys[5] = {};
    TGraphErrors * gLmF_sys[5] = {};

    TGraphErrors * gCh42[5] = {};
    TGraphErrors * gKs42[5] = {};
    TGraphErrors * gLm42[5] = {};

    TGraphErrors * gCh42_sys[5] = {};
    TGraphErrors * gKs42_sys[5] = {};
    TGraphErrors * gLm42_sys[5] = {};

    TGraphErrors * gChAmptF[5] = {};
    TGraphErrors * gKsAmptF[5] = {};
    TGraphErrors * gLmAmptF[5] = {};
    TGraphErrors * gChTrentoF[5] = {};
    TGraphErrors * gKsTrentoF[5] = {};
    TGraphErrors * gLmTrentoF[5] = {};

    for ( int c = 1; c < 5; c++ ) {
        cPbPbV2->cd(c);
        hframe_fluct->Draw();
        line1.Draw();

        gChF[c] = getFluct( ch_v2_PbPb[c]->vn_MergedEta     , vH .grSig_pT[2][1][c], gChF_sys[c], cumu_syst[0] );
        gKsF[c] = getFluct( Ks_v2_PbPb_Sig[c]->vn_MergedEta , vKs.grSig_pT[2][1][c], gKsF_sys[c], cumu_syst[1] );
        gLmF[c] = getFluct( Lm_v2_PbPb_Sig[c]->vn_MergedEta , vLm.grSig_pT[2][1][c], gLmF_sys[c], cumu_syst[2] );

        gCh42[c] = getRatio(vH .grSig_pT[2][1][c], ch_v2_PbPb[c]->vn_MergedEta     );
        gKs42[c] = getRatio(vKs.grSig_pT[2][1][c], Ks_v2_PbPb_Sig[c]->vn_MergedEta );
        gLm42[c] = getRatio(vLm.grSig_pT[2][1][c], Lm_v2_PbPb_Sig[c]->vn_MergedEta );

        gCh42_sys[c] = getRatio(vH .grSig_pT[2][1][c], ch_v2_PbPb[c]->vn_MergedEta     , 10);
        gKs42_sys[c] = getRatio(vKs.grSig_pT[2][1][c], Ks_v2_PbPb_Sig[c]->vn_MergedEta , 11);
        gLm42_sys[c] = getRatio(vLm.grSig_pT[2][1][c], Lm_v2_PbPb_Sig[c]->vn_MergedEta , 12);

        gChF[c]->SetMarkerStyle(kOpenSquare);
        gChF[c]->SetMarkerColor(kBlack);
        gChF[c]->SetLineColor  (kBlack);
        gChF[c]->SetMarkerSize(2.);

        gKsF[c]->SetMarkerStyle(kOpenSquare);
        gKsF[c]->SetMarkerColor(kBlue);
        gKsF[c]->SetLineColor  (kBlue);
        gKsF[c]->SetMarkerSize(2.);

        gLmF[c]->SetMarkerStyle(kOpenSquare);
        gLmF[c]->SetMarkerColor(kRed);
        gLmF[c]->SetLineColor  (kRed);
        gLmF[c]->SetMarkerSize(2.);

        gChF_sys[c]->SetFillColor(3005);
        gKsF_sys[c]->SetFillColor(3003);
        gLmF_sys[c]->SetFillColor(3001);

        /*
        gChAmptF[c] =   getFluct(ampt  ->grCh_v22[c], ampt  ->grCh_v24[c]);
        gChTrentoF[c] = getFluct(trento->grCh_v22[c], trento->grCh_v24[c]);
        gKsAmptF[c] =   getFluct(ampt  ->grKs_v22[c], ampt  ->grKs_v24[c]);
        gKsTrentoF[c] = getFluct(trento->grKs_v22[c], trento->grKs_v24[c]);
        gLmAmptF[c] =   getFluct(ampt  ->grLm_v22[c], ampt  ->grLm_v24[c]);
        gLmTrentoF[c] = getFluct(trento->grLm_v22[c], trento->grLm_v24[c]);
        */

        gChAmptF[c] =   ampt  ->grCh_Fv2[c];
        gChTrentoF[c] = trento->grCh_Fv2[c];
        gKsAmptF[c] =   ampt  ->grKs_Fv2[c];
        gKsTrentoF[c] = trento->grKs_Fv2[c];
        gLmAmptF[c] =   ampt  ->grLm_Fv2[c];
        gLmTrentoF[c] = trento->grLm_Fv2[c];

        if ( c == 0 ) {
        } else if ( c == 1 ) {
//            DropPoints( gLmF[c], -2 );
        } else if ( c == 2 ) {
        } else if ( c == 3 ) {
        } else if ( c == 4 ) {
//            DropPoints( gKsF[c], -1 );
//            DropPoints( gKsF_sys[c], -1 );
//            DropPoints( gLmF[c], -1 );
//            DropPoints( gLmF_sys[c], -1 );
        } else if ( c == 5 ) {
        }

        gChAmptF[c]  ->SetLineColor(kBlack);
        gChTrentoF[c]->SetLineColor(kBlack);
        gKsAmptF[c]  ->SetLineColor(kBlue);
        gKsTrentoF[c]->SetLineColor(kBlue);
        gLmAmptF[c]  ->SetLineColor(kRed);
        gLmTrentoF[c]->SetLineColor(kRed);

        gChAmptF[c]  ->SetFillColor(3005);
        gChTrentoF[c]->SetFillColor(3005);
        gKsAmptF[c]  ->SetFillColor(3003);
        gKsTrentoF[c]->SetFillColor(3003);
        gLmAmptF[c]  ->SetFillColor(3001);
        gLmTrentoF[c]->SetFillColor(3001);

        gChAmptF[c]  ->SetLineWidth(0);
        gChTrentoF[c]->SetLineWidth(0);
        gKsAmptF[c]  ->SetLineWidth(0);
        gKsTrentoF[c]->SetLineWidth(0);
        gLmAmptF[c]  ->SetLineWidth(0);
        gLmTrentoF[c]->SetLineWidth(0);

        gChAmptF[c]  ->SetLineStyle(kSolid);
        gChTrentoF[c]->SetLineStyle(kDashed);
        gKsAmptF[c]  ->SetLineStyle(kSolid);
        gKsTrentoF[c]->SetLineStyle(kDashed);
        gLmAmptF[c]  ->SetLineStyle(kSolid);
        gLmTrentoF[c]->SetLineStyle(kDashed);

        if ( bAmpt ) {
            gChAmptF[c]->Draw("[]3");
            gKsAmptF[c]->Draw("[]3");
            gLmAmptF[c]->Draw("[]3");
        } else {
            gChTrentoF[c]->Draw("[]3");
            gKsTrentoF[c]->Draw("[]3");
            gLmTrentoF[c]->Draw("[]3");
        }

//        gChF_sys[c]->Draw("[]2");
//        gKsF_sys[c]->Draw("[]2");
//        gLmF_sys[c]->Draw("[]2");

        gChF[c]->Draw("psame");
        gKsF[c]->Draw("psame");
        gLmF[c]->Draw("psame");

        s2f.WriteGr( gChAmptF[c], Form("grChAMPT_Fluct_%i", c) );
        s2f.WriteGr( gKsAmptF[c], Form("grKsAMPT_Fluct_%i", c) );
        s2f.WriteGr( gLmAmptF[c], Form("grLmAMPT_Fluct_%i", c) );

        s2f.WriteGr( gChTrentoF[c], Form("grChTrento_Fluct_%i", c) );
        s2f.WriteGr( gKsTrentoF[c], Form("grKsTrento_Fluct_%i", c) );
        s2f.WriteGr( gLmTrentoF[c], Form("grLmTrento_Fluct_%i", c) );

        s2f.WriteGr( gChF_sys[c], Form("grCh_Fluct_sys_%i", c) );
        s2f.WriteGr( gKsF_sys[c], Form("grKs_Fluct_sys_%i", c) );
        s2f.WriteGr( gLmF_sys[c], Form("grLm_Fluct_sys_%i", c) );

        s2f.WriteGr( gChF[c], Form("grCh_Fluct_%i", c) );
        s2f.WriteGr( gKsF[c], Form("grKs_Fluct_%i", c) );
        s2f.WriteGr( gLmF[c], Form("grLm_Fluct_%i", c) );
    }

    cPbPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
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

    TGraphErrors * grPACh_fluct = (TGraphErrors*) fpPb->Get("grCh_Fluct_8");
    TGraphErrors * grPAKs_fluct = (TGraphErrors*) fpPb->Get("grKs_Fluct_8");
    TGraphErrors * grPALm_fluct = (TGraphErrors*) fpPb->Get("grLm_Fluct_8");

    TGraphErrors * grPACh_fluct_sys = (TGraphErrors*) fpPb->Get("grCh_Fluct_sys_8");
    TGraphErrors * grPAKs_fluct_sys = (TGraphErrors*) fpPb->Get("grKs_Fluct_sys_8");
    TGraphErrors * grPALm_fluct_sys = (TGraphErrors*) fpPb->Get("grLm_Fluct_sys_8");

    setGr( grPACh_fluct, kFullCircle, kBlack, 2);
    setGr( grPAKs_fluct, kFullCircle, kBlue,  2);
    setGr( grPALm_fluct, kFullCircle, kRed,   2);

    grPACh_fluct->Draw("psame");
    grPAKs_fluct->Draw("psame");
    grPALm_fluct->Draw("psame");

    if ( bAmpt ) {
        cPbPbV2->SaveAs("PbPbV2_Fluct.pdf");
    }
    else {
        cPbPbV2->SaveAs("PbPbV2_Fluct_Trento.pdf");
    }

    /***** Plot fluctuation separately ******/
    // Ch
    for ( int c = 1; c < 5; c++ ) {
        cPbPbV2->cd(c);
        hframe_fluct->Draw();
        line1.Draw();
        gChAmptF[c]  ->SetFillColor(3001);
        gChTrentoF[c]->SetFillColor(3003);
        gChAmptF[c]->Draw("[]3");
        gChTrentoF[c]->Draw("[]3");
        gChF_sys[c]->Draw("[]2");
        gChF[c]->Draw("psame");
    }
    cPbPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{Charge hadron}");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    cPbPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[2]).c_str());
    TLegend * legFlCh = new TLegend(0.35, 0.75, 0.75, 0.92);
    legFlCh->SetFillColor(kWhite);
    legFlCh->SetTextFont(42);
    legFlCh->SetTextSize(0.05);
    legFlCh->SetBorderSize(0);

    legFlCh->AddEntry(grPACh_fluct, "pPb 185 #leq N_{trk}^{offline} < 250", "p");
    legFlCh->AddEntry(gChF[1], "PbPb", "p");

    TLegend * legFlCh1 = new TLegend(0.35, 0.75, 0.75, 0.92);
    legFlCh1->SetFillColor(kWhite);
    legFlCh1->SetTextFont(42);
    legFlCh1->SetTextSize(0.05);
    legFlCh1->SetBorderSize(0);
    legFlCh1->AddEntry(gChAmptF[1], "AMPT-IC (PbPb)", "f");
    legFlCh1->AddEntry(gChTrentoF[1], "Trento-IC (PbPb)", "f");

    legFlCh1->Draw();

    cPbPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[3]).c_str());

    cPbPbV2->cd(4);
    //latexS.DrawLatexNDC(0.55, 0.99, "PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.20, 0.99, "pPb 8.16 TeV PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[4]).c_str());
    legFlCh->Draw();

    grPACh_fluct_sys->Draw("[]2");
    grPACh_fluct->Draw("psame");

    cPbPbV2->SaveAs("PbPbV2_Fluct_Ch.pdf");

    // Ks
    for ( int c = 1; c < 5; c++ ) {
        cPbPbV2->cd(c);
        hframe_fluct->Draw();
        line1.Draw();
        gKsAmptF  [c]->SetFillColor(3001);
        gKsTrentoF[c]->SetFillColor(3003);
        gKsAmptF  [c]->Draw("[]3");
        gKsTrentoF[c]->Draw("[]3");
        gKsF_sys[c]->Draw("[]2");
        gKsF[c]->Draw("psame");
    }
    cPbPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.82, "#bf{K_{S}^{0}}");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    cPbPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[2]).c_str());
    TLegend * legFlKs = new TLegend(0.35, 0.75, 0.75, 0.92);
    legFlKs->SetFillColor(kWhite);
    legFlKs->SetTextFont(42);
    legFlKs->SetTextSize(0.05);
    legFlKs->SetBorderSize(0);

    legFlKs->AddEntry(gKsF[1], "PbPb", "p");
    legFlKs->AddEntry(grPAKs_fluct, "pPb 185 #leq N_{trk}^{offline} < 250", "p");

    TLegend * legFlKs1 = new TLegend(0.35, 0.75, 0.75, 0.92);
    legFlKs1->SetFillColor(kWhite);
    legFlKs1->SetTextFont(42);
    legFlKs1->SetTextSize(0.05);
    legFlKs1->SetBorderSize(0);

    legFlKs1->AddEntry(gKsAmptF[1], "AMPT-IC (PbPb)", "f");
    legFlKs1->AddEntry(gKsTrentoF[1], "Trento-IC (PbPb)", "f");

    legFlKs1->Draw();

    cPbPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[3]).c_str());

    cPbPbV2->cd(4);
    //latexS.DrawLatexNDC(0.55, 0.99, "PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.20, 0.99, "pPb 8.16 TeV PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[4]).c_str());
    legFlKs->Draw();

    grPAKs_fluct_sys->Draw("[]2");
    grPAKs_fluct->Draw("psame");

    cPbPbV2->SaveAs("PbPbV2_Fluct_Ks.pdf");

    // Lm
    for ( int c = 1; c < 5; c++ ) {
        cPbPbV2->cd(c);
        hframe_fluct->Draw();
        line1.Draw();
        gLmAmptF  [c]->SetFillColor(3001);
        gLmTrentoF[c]->SetFillColor(3003);
        gLmAmptF  [c]->Draw("[]3");
        gLmTrentoF[c]->Draw("[]3");
        gLmF_sys[c]->Draw("[]2");
        gLmF[c]->Draw("psame");
    }
    cPbPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{#Lambda}");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    cPbPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[2]).c_str());
    TLegend * legFlLm = new TLegend(0.35, 0.75, 0.75, 0.92);
    legFlLm->SetFillColor(kWhite);
    legFlLm->SetTextFont(42);
    legFlLm->SetTextSize(0.05);
    legFlLm->SetBorderSize(0);

    legFlLm->AddEntry(grPALm_fluct, "pPb 185 #leq N_{trk}^{offline} < 250", "p");
    legFlLm->AddEntry(gLmF[1], "PbPb", "p");

    TLegend * legFlLm1 = new TLegend(0.35, 0.75, 0.75, 0.92);
    legFlLm1->SetFillColor(kWhite);
    legFlLm1->SetTextFont(42);
    legFlLm1->SetTextSize(0.05);
    legFlLm1->SetBorderSize(0);
    legFlLm1->AddEntry(gLmAmptF[1], "AMPT-IC (PbPb)", "f");
    legFlLm1->AddEntry(gLmTrentoF[1], "Trento-IC (PbPb)", "f");

    legFlLm1->Draw();

    cPbPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[3]).c_str());

    cPbPbV2->cd(4);
    //latexS.DrawLatexNDC(0.55, 0.99, "PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.20, 0.99, "pPb 8.16 TeV PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[4]).c_str());
    legFlLm->Draw();

    grPALm_fluct_sys->Draw("[]2");
    grPALm_fluct->Draw("psame");

    cPbPbV2->SaveAs("PbPbV2_Fluct_Lm.pdf");

    /***** Plot v24/v22 ratio separately ******/
    // Ch
    TGraphErrors * grPACh42 = (TGraphErrors*) fpPb->Get("grCh42_8");
    TGraphErrors * grPAKs42 = (TGraphErrors*) fpPb->Get("grKs42_8");
    TGraphErrors * grPALm42 = (TGraphErrors*) fpPb->Get("grLm42_8");

    setGr( grPACh42, kFullCircle, kBlack, 2 );
    setGr( grPAKs42, kFullCircle, kBlue , 2 );
    setGr( grPALm42, kFullCircle, kRed  , 2 );

    TGraphErrors * grPACh42_sys = (TGraphErrors*) fpPb->Get("grCh42sys_8");
    TGraphErrors * grPAKs42_sys = (TGraphErrors*) fpPb->Get("grKs42sys_8");
    TGraphErrors * grPALm42_sys = (TGraphErrors*) fpPb->Get("grLm42sys_8");

    grPACh42_sys->SetFillColor(3005);
    grPAKs42_sys->SetFillColor(3003);
    grPALm42_sys->SetFillColor(3001);

    TH2D * hframe_ratio24 = new TH2D("hframe_ratio24", "hframe_ratio24", 1, 0.01, 8.5, 1, 0.01, 1.3);
    InitHist(hframe_ratio24, "p_{T} (GeV)", "v_{2}{4}/v_{2}{SP}");
    hframe_ratio24->GetYaxis()->SetTitleOffset(0.90);
    hframe_ratio24->GetYaxis()->CenterTitle(false);
    hframe_ratio24->GetXaxis()->SetTitleOffset(0.90);

    for ( int c = 1; c < 5; c++ ) {
        cPbPbV2->cd(c);
        hframe_ratio24->Draw();
        line1.Draw();

        setGr( gCh42[c], kOpenSquare, kBlack, 2 );
        setGr( gKs42[c], kOpenSquare, kBlue , 2 );
        setGr( gLm42[c], kOpenSquare, kRed  , 2 );

        gCh42_sys[c]->SetFillColor(3005);
        gKs42_sys[c]->SetFillColor(3003);
        gLm42_sys[c]->SetFillColor(3001);

        gCh42_sys[c]->Draw("[]2");
        gCh42[c]->Draw("psame");
    }

    cPbPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{Charge hadron}");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    cPbPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[2]).c_str());

    TLegend * legCh42 = new TLegend(0.35, 0.75, 0.75, 0.92);
    legCh42->SetFillColor(kWhite);
    legCh42->SetTextFont(42);
    legCh42->SetTextSize(0.05);
    legCh42->SetBorderSize(0);
    legCh42->AddEntry(gCh42[1], "PbPb", "p");
    legCh42->AddEntry(grPACh42, "pPb 185 #leq N_{trk}^{offline} < 250", "p");

    legCh42->Draw();

    cPbPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[3]).c_str());

    cPbPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[4]).c_str());


    grPACh42_sys->Draw("[]2");
    grPACh42->Draw("psame");

    cPbPbV2->SaveAs("PbPbV2_Ch42.pdf");

    // Ks
    for ( int c = 1; c < 5; c++ ) {
        cPbPbV2->cd(c);
        hframe_ratio24->Draw();
        line1.Draw();

        gKs42_sys[c]->Draw("[]2");
        gKs42[c]->Draw("psame");
    }

    cPbPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.82, "#bf{K_{S}^{0}}");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    cPbPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[2]).c_str());

    TLegend * legKs42 = new TLegend(0.35, 0.75, 0.75, 0.92);
    legKs42->SetFillColor(kWhite);
    legKs42->SetTextFont(42);
    legKs42->SetTextSize(0.05);
    legKs42->SetBorderSize(0);
    legKs42->AddEntry(gKs42[1], "PbPb", "p");
    legKs42->AddEntry(grPAKs42, "pPb 185 #leq N_{trk}^{offline} < 250", "p");

    legKs42->Draw();

    cPbPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[3]).c_str());

    cPbPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[4]).c_str());


    grPAKs42_sys->Draw("[]2");
    grPAKs42->Draw("psame");

    cPbPbV2->SaveAs("PbPbV2_Ks42.pdf");

    // Lm
    for ( int c = 1; c < 5; c++ ) {
        cPbPbV2->cd(c);
        hframe_ratio24->Draw();
        line1.Draw();

        gLm42_sys[c]->Draw("[]2");
        gLm42[c]->Draw("psame");
    }

    cPbPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{#Lambda}");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    cPbPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[2]).c_str());

    TLegend * legLm42 = new TLegend(0.35, 0.75, 0.75, 0.92);
    legLm42->SetFillColor(kWhite);
    legLm42->SetTextFont(42);
    legLm42->SetTextSize(0.05);
    legLm42->SetBorderSize(0);
    legLm42->AddEntry(gLm42[1], "PbPb", "p");
    legLm42->AddEntry(grPALm42, "pPb 185 #leq N_{trk}^{offline} < 250", "p");

    legLm42->Draw();

    cPbPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[3]).c_str());

    cPbPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[4]).c_str());

    grPALm42_sys->Draw("[]2");
    grPALm42->Draw("psame");

    cPbPbV2->SaveAs("PbPbV2_Lm42.pdf");



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

        vH.grSysSig_pT[2][1][c]->SetFillColor(3003);
        vH.grSysSig_V2sub4merge[c]->SetFillColor(3001);

        vH.grSysSig_pT[2][1][c]->Draw("[]2");
        vH.grSysSig_V2sub4merge[c]->Draw("[]2");

//        ch_v2_PbPb[c]->vn_MergedEta       ->Draw("psame");
//        ch_v2_PbPb[c]->vn_MergedEta_SubEvt->Draw("psame");
        vH.grSig_pT[2][1][c]->Draw("psame");
        vH.grSig_V2sub4merge[c]->Draw("psame");

        s2f.WriteGr( vH.grSig_V2sub4merge[c], Form("grCh_v24sub_%i", c) );
    }

    cPbPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{Charge hadron}");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    TLegend * legSubCh = new TLegend(0.55, 0.65, 0.95, 0.92);
    legSubCh->SetFillColor(kWhite);
    legSubCh->SetTextFont(42);
    legSubCh->SetTextSize(0.05);
    legSubCh->SetBorderSize(0);
    legSubCh->SetHeader("PbPb");

//    legSubCh->AddEntry(ch_v2_PbPb[1]->vn_MergedEta,        "v_{2}{SP}", "p");
//    legSubCh->AddEntry(ch_v2_PbPb[1]->vn_MergedEta_SubEvt, "v_{2}{SP,Sub}", "p");
    legSubCh->AddEntry(vH.grSig_pT[2][1][1], "v_{2}{4}", "p");
    legSubCh->AddEntry(vH.grSig_V2sub4merge[1], "v_{2}{4,Sub}", "p");


    cPbPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[2]).c_str());
    legSubCh->Draw();

    cPbPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[3]).c_str());

    cPbPbV2->cd(4);
    latexS.DrawLatexNDC(0.20, 0.99, "pPb 8.16 TeV PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[4]).c_str());

    TGraphErrors * grSysPACh_SubEvt = (TGraphErrors*) fpPb->Get("grSysCh_v24sub_8");
    TGraphErrors * grSysPAKs_SubEvt = (TGraphErrors*) fpPb->Get("grSysKs_v24sub_8");
    TGraphErrors * grSysPALm_SubEvt = (TGraphErrors*) fpPb->Get("grSysLm_v24sub_8");

    TGraphErrors * grPACh_SubEvt = (TGraphErrors*) fpPb->Get("grCh_v24sub_8");
    TGraphErrors * grPAKs_SubEvt = (TGraphErrors*) fpPb->Get("grKs_v24sub_8");
    TGraphErrors * grPALm_SubEvt = (TGraphErrors*) fpPb->Get("grLm_v24sub_8");

    TGraphErrors * grSysPACh_v24 = (TGraphErrors*) fpPb->Get("grChSys_v24_8");
    TGraphErrors * grSysPAKs_v24 = (TGraphErrors*) fpPb->Get("grKsSys_v24_8");
    TGraphErrors * grSysPALm_v24 = (TGraphErrors*) fpPb->Get("grLmSys_v24_8");

    TGraphErrors * grPACh_v24 = (TGraphErrors*) fpPb->Get("grCh_v24_8");
    TGraphErrors * grPAKs_v24 = (TGraphErrors*) fpPb->Get("grKs_v24_8");
    TGraphErrors * grPALm_v24 = (TGraphErrors*) fpPb->Get("grLm_v24_8");

    setGr(grPACh_v24, kFullCircle, kBlue);
    setGr(grPAKs_v24, kFullCircle, kBlue);
    setGr(grPALm_v24, kFullCircle, kBlue);

    setGr(grPACh_SubEvt, kOpenCircle, kRed);
    setGr(grPAKs_SubEvt, kOpenCircle, kRed);
    setGr(grPALm_SubEvt, kOpenCircle, kRed);

    grSysPACh_v24   ->Draw("[]2");
    grSysPACh_SubEvt->Draw("[]2");

    grPACh_v24   ->Draw("psame");
    grPACh_SubEvt->Draw("psame");

    TLegend * legPASubCh = new TLegend(0.35, 0.65, 0.95, 0.92);
    legPASubCh->SetFillColor(kWhite);
    legPASubCh->SetTextFont(42);
    legPASubCh->SetTextSize(0.05);
    legPASubCh->SetBorderSize(0);
    legPASubCh->SetHeader("pPb 185 #leq N_{trk}^{offline} < 250");

    legPASubCh->AddEntry(grPACh_v24,    "v_{2}{4}", "p");
    legPASubCh->AddEntry(grPACh_SubEvt, "v_{2}{4,Sub}", "p");

    legPASubCh->Draw();

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

        vKs.grSysSig_pT[2][1][c]->SetFillColor(3003);
        vKs.grSysSig_V2sub4merge[c]->SetFillColor(3001);

        vKs.grSysSig_pT[2][1][c]->Draw("[]2");
        vKs.grSysSig_V2sub4merge[c]->Draw("[]2");

//        Ks_v2_PbPb_Sig[c]->vn_MergedEta       ->Draw("psame");
//        Ks_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt->Draw("psame");
        vKs.grSig_pT[2][1][c]->Draw("psame");
        vKs.grSig_V2sub4merge[c]->Draw("psame");

        s2f.WriteGr( vKs.grSig_V2sub4merge[c], Form("grKs_v24sub_%i", c) );
    }

    cPbPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.82, "#bf{K_{S}^{0}}");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    TLegend * legSubKs = new TLegend(0.55, 0.65, 0.95, 0.92);
    legSubKs->SetFillColor(kWhite);
    legSubKs->SetTextFont(42);
    legSubKs->SetTextSize(0.05);
    legSubKs->SetBorderSize(0);
    legSubKs->SetHeader("PbPb");

//    legSubKs->AddEntry(Ks_v2_PbPb_Sig[1]->vn_MergedEta,        "v_{2}{SP}", "p");
//    legSubKs->AddEntry(Ks_v2_PbPb_Sig[1]->vn_MergedEta_SubEvt, "v_{2}{SP,Sub}", "p");
    legSubKs->AddEntry(vKs.grSig_pT[2][1][1],    "v_{2}{4}", "p");
    legSubKs->AddEntry(vKs.grSig_V2sub4merge[1], "v_{2}{4,Sub}", "p");
//    legSubKs->AddEntry(grPAKs_v24,    "pPb v_{2}{4}", "p");
//    legSubKs->AddEntry(grPAKs_SubEvt, "pPb v_{2}{4,Sub}", "p");


    cPbPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[2]).c_str());
    legSubKs->Draw();

    cPbPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[3]).c_str());

    cPbPbV2->cd(4);
    latexS.DrawLatexNDC(0.20, 0.99, "pPb 8.16 TeV PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[4]).c_str());

    grSysPAKs_v24   ->SetFillColor(3003);
    grSysPAKs_SubEvt->SetFillColor(3001);

    grSysPAKs_v24   ->Draw("[]2");
    grSysPAKs_SubEvt->Draw("[]2");

    grPAKs_v24   ->Draw("psame");
    grPAKs_SubEvt->Draw("psame");

    TLegend * legPASubKs = new TLegend(0.35, 0.65, 0.95, 0.92);
    legPASubKs->SetFillColor(kWhite);
    legPASubKs->SetTextFont(42);
    legPASubKs->SetTextSize(0.05);
    legPASubKs->SetBorderSize(0);
    legPASubKs->SetHeader("pPb 185 #leq N_{trk}^{offline} < 250");

    legPASubKs->AddEntry(grPAKs_v24,    "v_{2}{4}", "p");
    legPASubKs->AddEntry(grPAKs_SubEvt, "v_{2}{4,Sub}", "p");

    legPASubKs->Draw();

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

        vLm.grSysSig_pT[2][1][c]->SetFillColor(3003);
        vLm.grSysSig_V2sub4merge[c]->SetFillColor(3001);

        vLm.grSysSig_pT[2][1][c]->Draw("[]2");
        vLm.grSysSig_V2sub4merge[c]->Draw("[]2");

//        Lm_v2_PbPb_Sig[c]->vn_MergedEta       ->Draw("psame");
//        Lm_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt->Draw("psame");
        vLm.grSig_pT[2][1][c]->Draw("psame");
        vLm.grSig_V2sub4merge[c]->Draw("psame");

        s2f.WriteGr( vLm.grSig_V2sub4merge[c], Form("grLm_v24sub_%i", c) );
    }

    cPbPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{#Lambda}");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    TLegend * legSubLm = new TLegend(0.55, 0.65, 0.95, 0.92);
    legSubLm->SetFillColor(kWhite);
    legSubLm->SetTextFont(42);
    legSubLm->SetTextSize(0.05);
    legSubLm->SetBorderSize(0);
    legSubLm->SetHeader("PbPb");

//    legSubLm->AddEntry(Lm_v2_PbPb_Sig[1]->vn_MergedEta,        "v_{2}{SP}", "p");
//    legSubLm->AddEntry(Lm_v2_PbPb_Sig[1]->vn_MergedEta_SubEvt, "v_{2}{SP,Sub}", "p");
    legSubLm->AddEntry(vLm.grSig_pT[2][1][1],    "PbPb v_{2}{4}", "p");
    legSubLm->AddEntry(vLm.grSig_V2sub4merge[1], "PbPb v_{2}{4,Sub}", "p");


    cPbPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[2]).c_str());
    legSubLm->Draw();

    cPbPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[3]).c_str());

    cPbPbV2->cd(4);
    latexS.DrawLatexNDC(0.20, 0.99, "pPb 8.16 TeV PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[4]).c_str());

    grSysPALm_v24   ->SetFillColor(3003);
    grSysPALm_SubEvt->SetFillColor(3001);

    grSysPALm_v24   ->Draw("[]2");
    grSysPALm_SubEvt->Draw("[]2");

    grPALm_v24   ->Draw("psame");
    grPALm_SubEvt->Draw("psame");

    TLegend * legPASubLm = new TLegend(0.35, 0.65, 0.95, 0.92);
    legPASubLm->SetFillColor(kWhite);
    legPASubLm->SetTextFont(42);
    legPASubLm->SetTextSize(0.05);
    legPASubLm->SetBorderSize(0);
    legPASubLm->SetHeader("pPb 185 #leq N_{trk}^{offline} < 250");

    legPASubLm->AddEntry(grPALm_v24,    "v_{2}{4}", "p");
    legPASubLm->AddEntry(grPALm_SubEvt, "v_{2}{4,Sub}", "p");

    legPASubLm->Draw();

    cPbPbV2->SaveAs("PbPbV2_Subevt_Lm.pdf");

    // sub-event ratio
    TH2D * hframe_ratio = new TH2D("hframe_ratio", "hframe_ratio", 1, 0.01, 8.5, 1, 0.2, 1.75);
    InitHist(hframe_ratio, "p_{T} (GeV)", "Ratio");
    hframe_ratio->GetYaxis()->SetTitleOffset(1.0);
    hframe_ratio->GetXaxis()->SetTitleOffset(0.90);

    TGraphErrors* gChRatioCu[5] = {};
    TGraphErrors* gKsRatioCu[5] = {};
    TGraphErrors* gLmRatioCu[5] = {};
    TGraphErrors* gChRatioCuSys[5] = {};
    TGraphErrors* gKsRatioCuSys[5] = {};
    TGraphErrors* gLmRatioCuSys[5] = {};

    TGraphErrors* gChDeltaCu[5] = {};
    TGraphErrors* gKsDeltaCu[5] = {};
    TGraphErrors* gLmDeltaCu[5] = {};
    TGraphErrors* gChDeltaCuSys[5] = {};
    TGraphErrors* gKsDeltaCuSys[5] = {};
    TGraphErrors* gLmDeltaCuSys[5] = {};


    TGraphErrors* gChRatioSP[5] = {};
    TGraphErrors* gKsRatioSP[5] = {};
    TGraphErrors* gLmRatioSP[5] = {};

    for ( int c = 1; c < 5; c++ ) {
        cPbPbV2->cd(c);
        hframe_ratio->Draw();
        line1.Draw();

        gChRatioSP[c]= getRatio( ch_v2_PbPb[c]->vn_MergedEta_SubEvt,     ch_v2_PbPb[c]->vn_MergedEta    , 3 );
        gKsRatioSP[c]= getRatio( Ks_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt, Ks_v2_PbPb_Sig[c]->vn_MergedEta, 3 );
        gLmRatioSP[c]= getRatio( Lm_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt, Lm_v2_PbPb_Sig[c]->vn_MergedEta, 3 );

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
        hframe_ratio->Draw();
        line1.Draw();

        gChRatioCuSys[c]= getRatio( vH.grSig_V2sub4merge[c],  vH.grSig_pT[2][1][c] , 10 );
        gKsRatioCuSys[c]= getRatio( vKs.grSig_V2sub4merge[c], vKs.grSig_pT[2][1][c], 11 );
        gLmRatioCuSys[c]= getRatio( vLm.grSig_V2sub4merge[c], vLm.grSig_pT[2][1][c], 12 );

        gChRatioCuSys[c]->SetFillColor(3005);
        gKsRatioCuSys[c]->SetFillColor(3003);
        gLmRatioCuSys[c]->SetFillColor(3001);

        gChRatioCu[c]= getRatio( vH.grSig_V2sub4merge[c],  vH.grSig_pT[2][1][c] , 3 );
        gKsRatioCu[c]= getRatio( vKs.grSig_V2sub4merge[c], vKs.grSig_pT[2][1][c], 3 );
        gLmRatioCu[c]= getRatio( vLm.grSig_V2sub4merge[c], vLm.grSig_pT[2][1][c], 3 );

        gChRatioCu[c]->SetMarkerStyle(kOpenSquare);
        gChRatioCu[c]->SetMarkerColor(kBlack);
        gChRatioCu[c]->SetLineColor  (kBlack);
        gChRatioCu[c]->SetMarkerSize(2.);

        gKsRatioCu[c]->SetMarkerStyle(kOpenSquare);
        gKsRatioCu[c]->SetMarkerColor(kBlue);
        gKsRatioCu[c]->SetLineColor  (kBlue);
        gKsRatioCu[c]->SetMarkerSize(2.);

        gLmRatioCu[c]->SetMarkerStyle(kOpenSquare);
        gLmRatioCu[c]->SetMarkerColor(kRed);
        gLmRatioCu[c]->SetLineColor  (kRed);
        gLmRatioCu[c]->SetMarkerSize(2.);


        //
        gChDeltaCuSys[c]= getDelta( vH.grSig_V2sub4merge[c],  vH.grSig_pT[2][1][c] , 10 );
        gKsDeltaCuSys[c]= getDelta( vKs.grSig_V2sub4merge[c], vKs.grSig_pT[2][1][c], 11 );
        gLmDeltaCuSys[c]= getDelta( vLm.grSig_V2sub4merge[c], vLm.grSig_pT[2][1][c], 12 );

        gChDeltaCuSys[c]->SetFillColor(3005);
        gKsDeltaCuSys[c]->SetFillColor(3003);
        gLmDeltaCuSys[c]->SetFillColor(3001);

        gChDeltaCu[c]= getDelta( vH.grSig_V2sub4merge[c],  vH.grSig_pT[2][1][c] , 3 );
        gKsDeltaCu[c]= getDelta( vKs.grSig_V2sub4merge[c], vKs.grSig_pT[2][1][c], 3 );
        gLmDeltaCu[c]= getDelta( vLm.grSig_V2sub4merge[c], vLm.grSig_pT[2][1][c], 3 );

        gChDeltaCu[c]->SetMarkerStyle(kOpenSquare);
        gChDeltaCu[c]->SetMarkerColor(kBlack);
        gChDeltaCu[c]->SetLineColor  (kBlack);
        gChDeltaCu[c]->SetMarkerSize(2.);

        gKsDeltaCu[c]->SetMarkerStyle(kOpenSquare);
        gKsDeltaCu[c]->SetMarkerColor(kBlue);
        gKsDeltaCu[c]->SetLineColor  (kBlue);
        gKsDeltaCu[c]->SetMarkerSize(2.);

        gLmDeltaCu[c]->SetMarkerStyle(kOpenSquare);
        gLmDeltaCu[c]->SetMarkerColor(kRed);
        gLmDeltaCu[c]->SetLineColor  (kRed);
        gLmDeltaCu[c]->SetMarkerSize(2.);

        if ( c == 0 ) {
        } else if ( c == 1 ) {
        } else if ( c == 2 ) {
        } else if ( c == 3 ) {
        } else if ( c == 4 ) {
        } else if ( c == 5 ) {
        }

        s2f.WriteGr( gChRatioCu[c], Form("grCh_v24subratio_%i", c) );
        s2f.WriteGr( gKsRatioCu[c], Form("grKs_v24subratio_%i", c) );
        s2f.WriteGr( gLmRatioCu[c], Form("grLm_v24subratio_%i", c) );
    }
    cPbPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "v_{2}{SP,Sub}/v_{2}{SP}");
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
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "v_{2}{4,Sub}/v_{2}{4}");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    gChRatioCuSys[1]->Draw("[]2");
    gKsRatioCuSys[1]->Draw("[]2");
    gLmRatioCuSys[1]->Draw("[]2");

    gChRatioCu[1]->Draw("psame");
    gKsRatioCu[1]->Draw("psame");
    gLmRatioCu[1]->Draw("psame");

    TLegend * legCu_R = new TLegend(0.50, 0.68, 0.98, 0.92);
    legCu_R->SetFillColor(kWhite);
    legCu_R->SetTextFont(42);
    legCu_R->SetTextSize(0.05);
    legCu_R->SetBorderSize(0);

    legCu_R->AddEntry(gChRatioCu[1], "charge hadron", "p");
    legCu_R->AddEntry(gKsRatioCu[1], "K_{S}^{0}", "p");
    legCu_R->AddEntry(gLmRatioCu[1], "#Lambda", "p");

    cPbPbV2_1->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[2]).c_str());

    gChRatioCuSys[2]->Draw("[]2");
    gKsRatioCuSys[2]->Draw("[]2");
    gLmRatioCuSys[2]->Draw("[]2");

    gChRatioCu[2]->Draw("psame");
    gKsRatioCu[2]->Draw("psame");
    gLmRatioCu[2]->Draw("psame");

    cPbPbV2_1->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[3]).c_str());

    gChRatioCuSys[3]->Draw("[]2");
    gKsRatioCuSys[3]->Draw("[]2");
    gLmRatioCuSys[3]->Draw("[]2");

    gChRatioCu[3]->Draw("psame");
    gKsRatioCu[3]->Draw("psame");
    gLmRatioCu[3]->Draw("psame");

    cPbPbV2_1->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[4]).c_str());

    legCu_R->Draw();

    gChRatioCuSys[4]->Draw("[]2");
    gKsRatioCuSys[4]->Draw("[]2");
    gLmRatioCuSys[4]->Draw("[]2");

    gChRatioCu[4]->Draw("psame");
    gKsRatioCu[4]->Draw("psame");
    gLmRatioCu[4]->Draw("psame");

    cPbPbV2_1->SaveAs("PbPbV2_SubevtCu_Ratio.pdf");

    // sub-event delta
    TH2D * hframe_pt_delta = new TH2D("hframe_pt_delta", "hframe_pt_delta", 1, 0.01, 8.5, 1, -0.08, 0.12);
    InitHist(hframe_pt_delta, "p_{T} (GeV)", "#Deltav_{2}");
    hframe_pt_delta->GetYaxis()->SetTitleOffset(1.0);
    hframe_pt_delta->GetXaxis()->SetTitleOffset(0.90);

    cPbPbV2_1->cd(1);
    hframe_pt_delta->Draw();
    line0.Draw();
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "v_{2}{4,Sub} - v_{2}{4}");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    gChDeltaCuSys[1]->Draw("[]2");
    gKsDeltaCuSys[1]->Draw("[]2");
    gLmDeltaCuSys[1]->Draw("[]2");

    gChDeltaCu[1]->Draw("psame");
    gKsDeltaCu[1]->Draw("psame");
    gLmDeltaCu[1]->Draw("psame");

    TLegend * legCu_D = new TLegend(0.50, 0.68, 0.98, 0.92);
    legCu_D->SetFillColor(kWhite);
    legCu_D->SetTextFont(42);
    legCu_D->SetTextSize(0.05);
    legCu_D->SetBorderSize(0);

    legCu_D->AddEntry(gChDeltaCu[1], "charge hadron", "p");
    legCu_D->AddEntry(gKsDeltaCu[1], "K_{S}^{0}", "p");
    legCu_D->AddEntry(gLmDeltaCu[1], "#Lambda", "p");

    cPbPbV2_1->cd(2);
    hframe_pt_delta->Draw();
    line0.Draw();
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[2]).c_str());

    gChDeltaCuSys[2]->Draw("[]2");
    gKsDeltaCuSys[2]->Draw("[]2");
    gLmDeltaCuSys[2]->Draw("[]2");

    gChDeltaCu[2]->Draw("psame");
    gKsDeltaCu[2]->Draw("psame");
    gLmDeltaCu[2]->Draw("psame");

    cPbPbV2_1->cd(3);
    hframe_pt_delta->Draw();
    line0.Draw();
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[3]).c_str());

    gChDeltaCuSys[3]->Draw("[]2");
    gKsDeltaCuSys[3]->Draw("[]2");
    gLmDeltaCuSys[3]->Draw("[]2");

    gChDeltaCu[3]->Draw("psame");
    gKsDeltaCu[3]->Draw("psame");
    gLmDeltaCu[3]->Draw("psame");

    cPbPbV2_1->cd(4);
    hframe_pt_delta->Draw();
    line0.Draw();
    latexS.DrawLatexNDC(0.55, 0.99, "PbPb 5.02 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[4]).c_str());

    legCu_D->Draw();

    gChDeltaCuSys[4]->Draw("[]2");
    gKsDeltaCuSys[4]->Draw("[]2");
    gLmDeltaCuSys[4]->Draw("[]2");

    gChDeltaCu[4]->Draw("psame");
    gKsDeltaCu[4]->Draw("psame");
    gLmDeltaCu[4]->Draw("psame");

    cPbPbV2_1->SaveAs("PbPbV2_SubevtCu_Delta.pdf");

    //
    // v26/v24 v28/v24 ratio

    TGraphErrors* gCh64Ratio[5] = {};
    TGraphErrors* gKs64Ratio[5] = {};
    TGraphErrors* gLm64Ratio[5] = {};

    TGraphErrors* gCh84Ratio[5] = {};
    TGraphErrors* gKs84Ratio[5] = {};
    TGraphErrors* gLm84Ratio[5] = {};

    TGraphErrors* gCh64RatioSys[5] = {};
    TGraphErrors* gKs64RatioSys[5] = {};
    TGraphErrors* gLm64RatioSys[5] = {};

    TGraphErrors* gCh84RatioSys[5] = {};
    TGraphErrors* gKs84RatioSys[5] = {};
    TGraphErrors* gLm84RatioSys[5] = {};

    TH2D * hframe_ratio1 = new TH2D("hframe_ratio1", "hframe_ratio1", 1, 0.01, 8.5, 1, 0.68, 1.42);
    InitHist(hframe_ratio1, "p_{T} (GeV)", "Ratio");
    hframe_ratio1->GetYaxis()->SetTitleOffset(1.0);
    hframe_ratio1->GetXaxis()->SetTitleOffset(0.90);

    for ( int c = 1; c < 5; c++ ) {
        cPbPbV2->cd(c);
        hframe_ratio1->Draw();
        line1.Draw();

        gCh64RatioSys[c] = getRatio( vH .grSig_pT[2][2][c], vH .grSig_pT[2][1][c], 10 );
        gKs64RatioSys[c] = getRatio( vKs.grSig_pT[2][2][c], vKs.grSig_pT[2][1][c], 11 );
        gLm64RatioSys[c] = getRatio( vLm.grSig_pT[2][2][c], vLm.grSig_pT[2][1][c], 12 );
        gCh84RatioSys[c] = getRatio( vH .grSig_pT[2][3][c], vH .grSig_pT[2][1][c], 10 );
        gKs84RatioSys[c] = getRatio( vKs.grSig_pT[2][3][c], vKs.grSig_pT[2][1][c], 11 );
        gLm84RatioSys[c] = getRatio( vLm.grSig_pT[2][3][c], vLm.grSig_pT[2][1][c], 12 );

        gCh64RatioSys[c]->SetFillColor(3005);
        gKs64RatioSys[c]->SetFillColor(3003);
        gLm64RatioSys[c]->SetFillColor(3001);
        gCh84RatioSys[c]->SetFillColor(3005);
        gKs84RatioSys[c]->SetFillColor(3003);
        gLm84RatioSys[c]->SetFillColor(3001);

        gCh64Ratio[c] = getRatio( vH .grSig_pT[2][2][c], vH .grSig_pT[2][1][c], 0 );
        gKs64Ratio[c] = getRatio( vKs.grSig_pT[2][2][c], vKs.grSig_pT[2][1][c], 0 );
        gLm64Ratio[c] = getRatio( vLm.grSig_pT[2][2][c], vLm.grSig_pT[2][1][c], 0 );
        gCh84Ratio[c] = getRatio( vH .grSig_pT[2][3][c], vH .grSig_pT[2][1][c], 0 );
        gKs84Ratio[c] = getRatio( vKs.grSig_pT[2][3][c], vKs.grSig_pT[2][1][c], 0 );
        gLm84Ratio[c] = getRatio( vLm.grSig_pT[2][3][c], vLm.grSig_pT[2][1][c], 0 );

//        gCh64Ratio[c] = getRatio( vH .grSig_pT[2][2][c], vH .grSig_pT[2][1][c], 3 );
//        gKs64Ratio[c] = getRatio( vKs.grSig_pT[2][2][c], vKs.grSig_pT[2][1][c], 3 );
//        gLm64Ratio[c] = getRatio( vLm.grSig_pT[2][2][c], vLm.grSig_pT[2][1][c], 3 );
//        gCh84Ratio[c] = getRatio( vH .grSig_pT[2][3][c], vH .grSig_pT[2][1][c], 3 );
//        gKs84Ratio[c] = getRatio( vKs.grSig_pT[2][3][c], vKs.grSig_pT[2][1][c], 3 );
//        gLm84Ratio[c] = getRatio( vLm.grSig_pT[2][3][c], vLm.grSig_pT[2][1][c], 3 );

        gCh64Ratio[c]->SetMarkerStyle(kOpenSquare);
        gKs64Ratio[c]->SetMarkerStyle(kOpenSquare);
        gLm64Ratio[c]->SetMarkerStyle(kOpenSquare);
        gCh64Ratio[c]->SetMarkerSize(2.);
        gKs64Ratio[c]->SetMarkerSize(2.);
        gLm64Ratio[c]->SetMarkerSize(2.);

        gCh64Ratio[c]->SetMarkerColor(kBlack);
        gKs64Ratio[c]->SetMarkerColor(kBlue);
        gLm64Ratio[c]->SetMarkerColor(kRed);

        gCh64Ratio[c]->SetLineColor(kBlack);
        gKs64Ratio[c]->SetLineColor(kBlue);
        gLm64Ratio[c]->SetLineColor(kRed);

        gCh84Ratio[c]->SetMarkerStyle(kOpenSquare);
        gKs84Ratio[c]->SetMarkerStyle(kOpenSquare);
        gLm84Ratio[c]->SetMarkerStyle(kOpenSquare);
        gCh84Ratio[c]->SetMarkerSize(2.);
        gKs84Ratio[c]->SetMarkerSize(2.);
        gLm84Ratio[c]->SetMarkerSize(2.);

        gCh84Ratio[c]->SetMarkerColor(kBlack);
        gKs84Ratio[c]->SetMarkerColor(kBlue);
        gLm84Ratio[c]->SetMarkerColor(kRed);

        gCh84Ratio[c]->SetLineColor(kBlack);
        gKs84Ratio[c]->SetLineColor(kBlue);
        gLm84Ratio[c]->SetLineColor(kRed);

        if ( c == 0 ) {
        } else if ( c == 1 ) {
            DropPoints( gKs64RatioSys[c], -2 );
            DropPoints( gLm64RatioSys[c], -1 );
            DropPoints( gKs84RatioSys[c], -2 );
            DropPoints( gLm84RatioSys[c], -1 );

            DropPoints( gKs64Ratio[c], -2 );
            DropPoints( gLm64Ratio[c], -1 );
            DropPoints( gKs84Ratio[c], -2 );
            DropPoints( gLm84Ratio[c], -1 );
        } else if ( c == 2 ) {
        } else if ( c == 3 ) {
        } else if ( c == 4 ) {
        } else if ( c == 5 ) {
        }

//        gCh64RatioSys[c]->Draw("[]2");
//        gKs64RatioSys[c]->Draw("[]2");
//        gLm64RatioSys[c]->Draw("[]2");
//
        gCh64Ratio[c]->Draw("psame");
        gKs64Ratio[c]->Draw("psame");
        gLm64Ratio[c]->Draw("psame");

        //
        cPbPbV2_1->cd(c);
        hframe_ratio1->Draw();
        line1.Draw();

//        gCh84RatioSys[c]->Draw("[]2");
//        gKs84RatioSys[c]->Draw("[]2");
//        gLm84RatioSys[c]->Draw("[]2");
//
        gCh84Ratio[c]->Draw("psame");
        gKs84Ratio[c]->Draw("psame");
        gLm84Ratio[c]->Draw("psame");

        s2f.WriteGr( gCh64RatioSys[c], Form("grChSys_r64_%i", c) );
        s2f.WriteGr( gKs64RatioSys[c], Form("grKsSys_r64_%i", c) );
        s2f.WriteGr( gLm64RatioSys[c], Form("grLmSys_r64_%i", c) );
        s2f.WriteGr( gCh84RatioSys[c], Form("grChSys_r84_%i", c) );
        s2f.WriteGr( gKs84RatioSys[c], Form("grKsSys_r84_%i", c) );
        s2f.WriteGr( gLm84RatioSys[c], Form("grLmSys_r84_%i", c) );

        s2f.WriteGr( gCh64Ratio[c], Form("grCh_r64_%i", c) );
        s2f.WriteGr( gKs64Ratio[c], Form("grKs_r64_%i", c) );
        s2f.WriteGr( gLm64Ratio[c], Form("grLm_r64_%i", c) );
        s2f.WriteGr( gCh84Ratio[c], Form("grCh_r84_%i", c) );
        s2f.WriteGr( gKs84Ratio[c], Form("grKs_r84_%i", c) );
        s2f.WriteGr( gLm84Ratio[c], Form("grLm_r84_%i", c) );
    }
    cPbPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "v_{2}{6}/v_{2}{4}");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    cPbPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[2]).c_str());

    TLegend * leg64 = new TLegend(0.35, 0.66, 0.75, 0.92);
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

    auto t = (TGraphErrors*) fpPb->Get("grLm_v24_8");
    DropPoints(t, 1);
//    DropPoints(t, -1);

    cout << __LINE__ << endl;
    TGraphErrors* gpPbCh64Ratio = getRatio( (TGraphErrors*) fpPb->Get("grCh_v26_8"), (TGraphErrors*) fpPb->Get("grCh_v24_8"), 3);
    cout << __LINE__ << endl;
    TGraphErrors* gpPbKs64Ratio = getRatio( (TGraphErrors*) fpPb->Get("grKs_v26_8"), (TGraphErrors*) fpPb->Get("grKs_v24_8"), 3);
    cout << __LINE__ << " t->GetN() = " << t->GetN() << "\t" << ((TGraphErrors*) fpPb->Get("grLm_v26_8"))->GetN() << endl;
    TGraphErrors* gpPbLm64Ratio = getRatio( (TGraphErrors*) fpPb->Get("grLm_v26_8"), t , 3);
    cout << __LINE__ << endl;

    gpPbCh64Ratio->SetMarkerStyle(kFullCircle);
    gpPbKs64Ratio->SetMarkerStyle(kFullSquare);
    gpPbLm64Ratio->SetMarkerStyle(kFullCircle);
    gpPbCh64Ratio->SetMarkerSize(2.);
    gpPbKs64Ratio->SetMarkerSize(2.);
    gpPbLm64Ratio->SetMarkerSize(2.);

    gpPbCh64Ratio->SetMarkerColor(kBlack);
    gpPbKs64Ratio->SetMarkerColor(kBlue);
    gpPbLm64Ratio->SetMarkerColor(kRed);

    gpPbCh64Ratio->SetLineColor(kBlack);
    gpPbKs64Ratio->SetLineColor(kBlue);
    gpPbLm64Ratio->SetLineColor(kRed);

    s2f.WriteGr( gpPbCh64Ratio, Form("grpPbCh_r64_%i", 8) );
    s2f.WriteGr( gpPbKs64Ratio, Form("grpPbKs_r64_%i", 8) );
    s2f.WriteGr( gpPbLm64Ratio, Form("grpPbLm_r64_%i", 8) );

//    gpPbCh64Ratio->Draw("psame");
//    gpPbKs64Ratio->Draw("psame");
//    gpPbLm64Ratio->Draw("psame");

    cPbPbV2->SaveAs("PbPbV2_V64_ratio.pdf");

    //
    cPbPbV2_1->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "v_{2}{8}/v_{2}{4}");
    latexS.DrawLatexNDC(0.16, 0.90, (centBins[1]).c_str());

    cPbPbV2_1->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, (centBins[2]).c_str());

    TLegend * leg86 = new TLegend(0.35, 0.66, 0.75, 0.92);
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
