#include "../../style.h"
#include "Steve_SP.h"


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


void makePlot4()
{
    SetStyle();

    TFile * fPA_Ks = new TFile("pPb_Ks2_merged_corrected.root");
    TFile * fPA_Lm = new TFile("pPb_Lm2_merged_corrected.root");
    TFile * fPA_H  = new TFile("pPb_H_merged_corrected.root");

    CumuGraph grKs(fPA_Ks);
    CumuGraph grLm(fPA_Lm);
    CumuGraph grH (fPA_H);

    TFile * fPA_SP = new TFile("V0SP.root");

    SteveGraphSP grSP(fPA_SP);

    // Start plotting
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
	latexS.SetTextSize(28);
	latexS.SetTextAlign(13);

    TCanvas * cPA = MakeCanvas("cPA", "cPA", 800, 600);;
    TH2D * hframePt = new TH2D("hframePt", "", 1, 0, 8.5, 1, -0.05, 0.45);
    InitHist(hframePt, "p_{T}", "v_{2}");

    TLegend * legPA = new TLegend(0.19, 0.60, 0.35 , 0.94);
    legPA->SetFillColor(kWhite);
    legPA->SetTextFont(42);
    legPA->SetTextSize(0.05);
    legPA->SetBorderSize(0);

    // Ks Obs
    for ( int c = 6; c < 10; c++ ) {
        hframePt->GetYaxis()->SetTitle("v_{2}^{obs}");
        hframePt->Draw();
        legPA->Clear();

        if ( grSP.grSP_Ks_Obs[c]->vn_Full_PosEtaEP ) {
            setGr(grSP.grSP_Ks_Obs[c]->vn_Full_PosEtaEP, kFullCircle, kRed);
            grSP.grSP_Ks_Obs [c]->vn_Full_PosEtaEP       ->Draw("psame");
            legPA->AddEntry(grSP.grSP_Ks_Obs[c]->vn_Full_PosEtaEP, "v_{2}^{obs}{SP+}", "p");
        }

        if ( grSP.grSP_Ks_Obs[c]->vn_Full_NegEtaEP ) {
            setGr(grSP.grSP_Ks_Obs[c]->vn_Full_NegEtaEP, kFullCircle, kBlue);
            grSP.grSP_Ks_Obs [c]->vn_Full_NegEtaEP       ->Draw("psame");
            legPA->AddEntry(grSP.grSP_Ks_Obs[c]->vn_Full_NegEtaEP, "v_{2}^{obs}{SP-}", "p");
        }

        grKs.grObs_v24   [c]->Draw("psame");
        grKs.grObs_v26   [c]->Draw("psame");
        grKs.grObs_v24sub[c]->Draw("psame");

        legPA->AddEntry(grKs.grObs_v24   [c], "v_{2}^{obs}{4}", "p");
        legPA->AddEntry(grKs.grObs_v24sub[c], "v_{2}^{obs}{4, sub-event}", "p");
        legPA->AddEntry(grKs.grObs_v26   [c], "v_{2}^{obs}{6}", "p");
        legPA->Draw();

        latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
        latexS.DrawLatexNDC(0.60, 0.80, strNoff[c]);

        cPA->SaveAs( (string("Ks_v2_Obs_")+to_string(c)+".pdf").c_str() );
    }

    // Ks SB
    for ( int c = 6; c < 10; c++ ) {
        hframePt->GetYaxis()->SetTitle("v_{2}^{sb}");
        hframePt->Draw();
        legPA->Clear();

        if ( grSP.grSP_Ks_SB[c]->vn_Full_PosEtaEP ) {
            setGr(grSP.grSP_Ks_SB[c]->vn_Full_PosEtaEP, kFullCircle, kRed);
            grSP.grSP_Ks_SB [c]->vn_Full_PosEtaEP       ->Draw("psame");
            legPA->AddEntry(grSP.grSP_Ks_SB[c]->vn_Full_PosEtaEP, "v_{2}^{sb}{SP+}", "p");
        }

        if ( grSP.grSP_Ks_SB[c]->vn_Full_NegEtaEP ) {
            setGr(grSP.grSP_Ks_SB[c]->vn_Full_NegEtaEP, kFullCircle, kBlue);
            grSP.grSP_Ks_SB [c]->vn_Full_NegEtaEP       ->Draw("psame");
            legPA->AddEntry(grSP.grSP_Ks_SB[c]->vn_Full_NegEtaEP, "v_{2}^{sb}{SP-}", "p");
        }

        grKs.grSB_v24   [c]->Draw("psame");
        grKs.grSB_v26   [c]->Draw("psame");
        grKs.grSB_v24sub[c]->Draw("psame");

        legPA->AddEntry(grKs.grSB_v24   [c], "v_{2}^{sb}{4}", "p");
        legPA->AddEntry(grKs.grSB_v24sub[c], "v_{2}^{sb}{4, sub-event}", "p");
        legPA->AddEntry(grKs.grSB_v26   [c], "v_{2}^{sb}{6}", "p");
        legPA->Draw();

        latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
        latexS.DrawLatexNDC(0.60, 0.80, strNoff[c]);
        cPA->SaveAs( (string("Ks_v2_SB_")+to_string(c)+".pdf").c_str() );
    }

    // Ks Sig
    for ( int c = 6; c < 10; c++ ) {
        hframePt->GetYaxis()->SetTitle("v_{2}");
        hframePt->Draw();
        legPA->Clear();

        if ( grSP.grSP_Ks_Sig[c]->vn_Full_PosEtaEP ) {
            setGr(grSP.grSP_Ks_Sig[c]->vn_Full_PosEtaEP, kFullCircle, kRed);
            grSP.grSP_Ks_Sig [c]->vn_Full_PosEtaEP       ->Draw("psame");
            legPA->AddEntry(grSP.grSP_Ks_Sig[c]->vn_Full_PosEtaEP, "v_{2}{SP+}", "p");
        }

        if ( grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP ) {
            setGr(grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP, kFullCircle, kBlue);
            grSP.grSP_Ks_Sig [c]->vn_Full_NegEtaEP       ->Draw("psame");
            legPA->AddEntry(grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP, "v_{2}{SP-}", "p");
        }

        grKs.gr_v24   [c]->Draw("psame");
        grKs.gr_v26   [c]->Draw("psame");
        grKs.gr_v24sub[c]->Draw("psame");

        legPA->AddEntry(grKs.gr_v24   [c], "v_{2}{4}", "p");
        legPA->AddEntry(grKs.gr_v24sub[c], "v_{2}{4, sub-event}", "p");
        legPA->AddEntry(grKs.gr_v26   [c], "v_{2}{6}", "p");
        legPA->Draw();

        latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
        latexS.DrawLatexNDC(0.60, 0.80, strNoff[c]);
        cPA->SaveAs( (string("Ks_v2_Sig_")+to_string(c)+".pdf").c_str() );
    }

    // Lm Obs
    for ( int c = 6; c < 10; c++ ) {
        hframePt->GetYaxis()->SetTitle("v_{2}^{obs}");
        hframePt->Draw();
        legPA->Clear();

        if ( grSP.grSP_Lm_Obs[c]->vn_Full_PosEtaEP ) {
            setGr(grSP.grSP_Lm_Obs[c]->vn_Full_PosEtaEP, kFullCircle, kRed);
            grSP.grSP_Lm_Obs [c]->vn_Full_PosEtaEP       ->Draw("psame");
            legPA->AddEntry(grSP.grSP_Lm_Obs[c]->vn_Full_PosEtaEP, "v_{2}^{obs}{SP+}", "p");
        }

        if ( grSP.grSP_Lm_Obs[c]->vn_Full_NegEtaEP ) {
            setGr(grSP.grSP_Lm_Obs[c]->vn_Full_NegEtaEP, kFullCircle, kBlue);
            grSP.grSP_Lm_Obs [c]->vn_Full_NegEtaEP       ->Draw("psame");
            legPA->AddEntry(grSP.grSP_Lm_Obs[c]->vn_Full_NegEtaEP, "v_{2}^{obs}{SP-}", "p");
        }

        grLm.grObs_v24   [c]->Draw("psame");
        grLm.grObs_v26   [c]->Draw("psame");
        grLm.grObs_v24sub[c]->Draw("psame");

        legPA->AddEntry(grLm.grObs_v24   [c], "v_{2}^{obs}{4}", "p");
        legPA->AddEntry(grLm.grObs_v24sub[c], "v_{2}^{obs}{4, sub-event}", "p");
        legPA->AddEntry(grLm.grObs_v26   [c], "v_{2}^{obs}{6}", "p");
        legPA->Draw();

        latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
        latexS.DrawLatexNDC(0.60, 0.80, strNoff[c]);
        cPA->SaveAs( (string("Lm_v2_Obs_")+to_string(c)+".pdf").c_str() );
    }

    // Lm SB
    for ( int c = 6; c < 10; c++ ) {
        hframePt->GetYaxis()->SetTitle("v_{2}^{sb}");
        hframePt->Draw();
        legPA->Clear();

        if ( grSP.grSP_Lm_SB[c]->vn_Full_PosEtaEP ) {
            setGr(grSP.grSP_Lm_SB[c]->vn_Full_PosEtaEP, kFullCircle, kRed);
            grSP.grSP_Lm_SB [c]->vn_Full_PosEtaEP       ->Draw("psame");
            legPA->AddEntry(grSP.grSP_Lm_SB[c]->vn_Full_PosEtaEP, "v_{2}^{sb}{SP+}", "p");
        }

        if ( grSP.grSP_Lm_SB[c]->vn_Full_NegEtaEP ) {
            setGr(grSP.grSP_Lm_SB[c]->vn_Full_NegEtaEP, kFullCircle, kBlue);
            grSP.grSP_Lm_SB [c]->vn_Full_NegEtaEP       ->Draw("psame");
            legPA->AddEntry(grSP.grSP_Lm_SB[c]->vn_Full_NegEtaEP, "v_{2}^{sb}{SP-}", "p");
        }

        grLm.grSB_v24   [c]->Draw("psame");
        grLm.grSB_v26   [c]->Draw("psame");
        grLm.grSB_v24sub[c]->Draw("psame");

        legPA->AddEntry(grLm.grSB_v24   [c], "v_{2}^{sb}{4}", "p");
        legPA->AddEntry(grLm.grSB_v24sub[c], "v_{2}^{sb}{4, sub-event}", "p");
        legPA->AddEntry(grLm.grSB_v26   [c], "v_{2}^{sb}{6}", "p");
        legPA->Draw();

        latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
        latexS.DrawLatexNDC(0.60, 0.80, strNoff[c]);
        cPA->SaveAs( (string("Lm_v2_SB_")+to_string(c)+".pdf").c_str() );
    }

    // Lm Sig
    for ( int c = 6; c < 10; c++ ) {
        hframePt->GetYaxis()->SetTitle("v_{2}");
        hframePt->Draw();
        legPA->Clear();

        if ( grSP.grSP_Lm_Sig[c]->vn_Full_PosEtaEP ) {
            setGr(grSP.grSP_Lm_Sig[c]->vn_Full_PosEtaEP, kFullCircle, kRed);
            grSP.grSP_Lm_Sig [c]->vn_Full_PosEtaEP       ->Draw("psame");
            legPA->AddEntry(grSP.grSP_Lm_Sig[c]->vn_Full_PosEtaEP, "v_{2}{SP+}", "p");
        }

        if ( grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP ) {
            setGr(grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP, kFullCircle, kBlue);
            grSP.grSP_Lm_Sig [c]->vn_Full_NegEtaEP       ->Draw("psame");
            legPA->AddEntry(grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP, "v_{2}{SP-}", "p");
        }

        grLm.gr_v24   [c]->Draw("psame");
        grLm.gr_v26   [c]->Draw("psame");
        grLm.gr_v24sub[c]->Draw("psame");

        legPA->AddEntry(grLm.gr_v24   [c], "v_{2}{4}", "p");
        legPA->AddEntry(grLm.gr_v24sub[c], "v_{2}{4, sub-event}", "p");
        legPA->AddEntry(grLm.gr_v26   [c], "v_{2}{6}", "p");
        legPA->Draw();

        latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
        latexS.DrawLatexNDC(0.60, 0.80, strNoff[c]);
        cPA->SaveAs( (string("Lm_v2_Sig_")+to_string(c)+".pdf").c_str() );
    }


    // Ks+Lm+H
    for ( int c = 6; c < 10; c++ ) {
        // SP
        hframePt->GetYaxis()->SetTitle("v_{2}{SP+}");
        hframePt->Draw();
        legPA->Clear();

        grSP.grSP_Ks_Sig[c]->vn_Full_PosEtaEP->SetMarkerStyle(kOpenCircle);
        grSP.grSP_Lm_Sig[c]->vn_Full_PosEtaEP->SetMarkerStyle(kOpenCircle);
        grSP.grSP_H     [c]->vn_Full_PosEtaEP->SetMarkerStyle(kOpenCircle);

        grSP.grSP_Ks_Sig[c]->vn_Full_PosEtaEP->SetMarkerSize(2.);
        grSP.grSP_Lm_Sig[c]->vn_Full_PosEtaEP->SetMarkerSize(2.);
        grSP.grSP_H     [c]->vn_Full_PosEtaEP->SetMarkerSize(2.);

        grSP.grSP_Ks_Sig[c]->vn_Full_PosEtaEP->SetMarkerColor(kRed);
        grSP.grSP_Lm_Sig[c]->vn_Full_PosEtaEP->SetMarkerColor(kBlue);
        grSP.grSP_H     [c]->vn_Full_PosEtaEP->SetMarkerColor(kBlack);

        grSP.grSP_Ks_Sig[c]->vn_Full_PosEtaEP->SetLineColor(kRed);
        grSP.grSP_Lm_Sig[c]->vn_Full_PosEtaEP->SetLineColor(kBlue);
        grSP.grSP_H     [c]->vn_Full_PosEtaEP->SetLineColor(kBlack);

        grSP.grSP_Ks_Sig[c]->vn_Full_PosEtaEP->Draw("psame");
        grSP.grSP_Lm_Sig[c]->vn_Full_PosEtaEP->Draw("psame");
        grSP.grSP_H     [c]->vn_Full_PosEtaEP->Draw("psame");

        legPA->AddEntry(grSP.grSP_Ks_Sig[c]->vn_Full_PosEtaEP, "K_{S}^{0}", "p");
        legPA->AddEntry(grSP.grSP_Lm_Sig[c]->vn_Full_PosEtaEP, "#Lambda", "p");
        legPA->AddEntry(grSP.grSP_H     [c]->vn_Full_PosEtaEP, "ch", "p");
        legPA->Draw();

        latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
        latexS.DrawLatexNDC(0.60, 0.80, strNoff[c]);
        cPA->SaveAs( (string("V2SP_")+to_string(c)+".pdf").c_str() );
    }


    for ( int c = 6; c < 10; c++ ) {
        // v24
        hframePt->GetYaxis()->SetTitle("v_{2}{4}");
        hframePt->Draw();
        legPA->Clear();

        grKs.gr_v24[c]->SetMarkerColor(kRed);
        grLm.gr_v24[c]->SetMarkerColor(kBlue);
        grH .gr_v24[c]->SetMarkerColor(kBlack);

        grKs.gr_v24[c]->SetLineColor(kRed);
        grLm.gr_v24[c]->SetLineColor(kBlue);
        grH .gr_v24[c]->SetLineColor(kBlack);

        grKs.gr_v24[c]->SetMarkerSize(2.);
        grLm.gr_v24[c]->SetMarkerSize(2.);
        grH .gr_v24[c]->SetMarkerSize(2.);

        grKs.gr_v24[c]->Draw("psame");
        grLm.gr_v24[c]->Draw("psame");
        grH .gr_v24[c]->Draw("psame");

        legPA->AddEntry(grKs.gr_v24[c], "K_{S}^{0}", "p");
        legPA->AddEntry(grLm.gr_v24[c], "#Lambda", "p");
        legPA->AddEntry(grH .gr_v24[c], "ch", "p");
        legPA->Draw();

        latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
        latexS.DrawLatexNDC(0.60, 0.80, strNoff[c]);
        cPA->SaveAs( (string("V24_")+to_string(c)+".pdf").c_str() );
    }

    for ( int c = 6; c < 10; c++ ) {
        // v24sub
        hframePt->GetYaxis()->SetTitle("v_{2}{4, sub-event}");
        hframePt->Draw();
        legPA->Clear();

        grKs.gr_v24sub[c]->SetMarkerColor(kRed);
        grLm.gr_v24sub[c]->SetMarkerColor(kBlue);
        grH .gr_v24sub[c]->SetMarkerColor(kBlack);

        grKs.gr_v24sub[c]->SetLineColor(kRed);
        grLm.gr_v24sub[c]->SetLineColor(kBlue);
        grH .gr_v24sub[c]->SetLineColor(kBlack);

        grKs.gr_v24sub[c]->SetMarkerSize(2.);
        grLm.gr_v24sub[c]->SetMarkerSize(2.);
        grH .gr_v24sub[c]->SetMarkerSize(2.);

        grKs.gr_v24sub[c]->Draw("psame");
        grLm.gr_v24sub[c]->Draw("psame");
        grH .gr_v24sub[c]->Draw("psame");

        legPA->AddEntry(grKs.gr_v24sub[c], "K_{S}^{0}", "p");
        legPA->AddEntry(grLm.gr_v24sub[c], "#Lambda", "p");
        legPA->AddEntry(grH .gr_v24sub[c], "ch", "p");
        legPA->Draw();

        latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
        latexS.DrawLatexNDC(0.60, 0.80, strNoff[c]);
        cPA->SaveAs( (string("V24SE_")+to_string(c)+".pdf").c_str() );
    }

    for ( int c = 6; c < 10; c++ ) {
        // v26
        hframePt->GetYaxis()->SetTitle("v_{2}{6}");
        hframePt->Draw();
        legPA->Clear();

        grKs.gr_v26[c]->SetMarkerColor(kRed);
        grLm.gr_v26[c]->SetMarkerColor(kBlue);
        grH .gr_v26[c]->SetMarkerColor(kBlack);

        grKs.gr_v26[c]->SetLineColor(kRed);
        grLm.gr_v26[c]->SetLineColor(kBlue);
        grH .gr_v26[c]->SetLineColor(kBlack);

        grKs.gr_v26[c]->SetMarkerSize(2.);
        grLm.gr_v26[c]->SetMarkerSize(2.);
        grH .gr_v26[c]->SetMarkerSize(2.);

        grKs.gr_v26[c]->Draw("psame");
        grLm.gr_v26[c]->Draw("psame");
        grH .gr_v26[c]->Draw("psame");

        legPA->AddEntry(grKs.gr_v26[c], "K_{S}^{0}", "p");
        legPA->AddEntry(grLm.gr_v26[c], "#Lambda", "p");
        legPA->AddEntry(grH .gr_v26[c], "ch", "p");
        legPA->Draw();

        latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
        latexS.DrawLatexNDC(0.60, 0.80, strNoff[c]);
        cPA->SaveAs( (string("V26_")+to_string(c)+".pdf").c_str() );
    }

    for ( int c = 6; c < 10; c++ ) {
        // SP
        hframePt->GetYaxis()->SetTitle("v_{2}{SP}");
        hframePt->Draw();
        legPA->Clear();

        grSP.grSP_Ks_Sig[c]->vn_Full_PosEtaEP->SetMarkerStyle(kOpenCircle);
        grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP->SetMarkerStyle(kOpenCircle);

        grSP.grSP_Ks_Sig[c]->vn_Full_PosEtaEP->SetMarkerColor(kRed);
        grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP->SetMarkerColor(kBlue);

        grSP.grSP_Ks_Sig[c]->vn_Full_PosEtaEP->SetLineColor(kRed);
        grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP->SetLineColor(kBlue);

        grSP.grSP_Ks_Sig[c]->vn_Full_PosEtaEP->Draw("psame");
        grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP->Draw("psame");

        legPA->AddEntry(grSP.grSP_Ks_Sig[c]->vn_Full_PosEtaEP, "K_{S}^{0} EP+", "p");
        legPA->AddEntry(grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP, "K_{S}^{0} EP-", "p");
        legPA->Draw();

        latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
        latexS.DrawLatexNDC(0.60, 0.80, strNoff[c]);
        cPA->SaveAs( (string("V2SP_Ks_")+to_string(c)+".pdf").c_str() );
    }

    for ( int c = 6; c < 10; c++ ) {
        // SP
        hframePt->GetYaxis()->SetTitle("v_{2}{SP}");
        hframePt->Draw();
        legPA->Clear();

        grSP.grSP_Lm_Sig[c]->vn_Full_PosEtaEP->SetMarkerStyle(kOpenCircle);
        grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP->SetMarkerStyle(kOpenCircle);

        grSP.grSP_Lm_Sig[c]->vn_Full_PosEtaEP->SetMarkerColor(kRed);
        grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP->SetMarkerColor(kBlue);

        grSP.grSP_Lm_Sig[c]->vn_Full_PosEtaEP->SetLineColor(kRed);
        grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP->SetLineColor(kBlue);

        grSP.grSP_Lm_Sig[c]->vn_Full_PosEtaEP->Draw("psame");
        grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP->Draw("psame");

        legPA->AddEntry(grSP.grSP_Lm_Sig[c]->vn_Full_PosEtaEP, "#Lambda EP+", "p");
        legPA->AddEntry(grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP, "#Lambda EP-", "p");
        legPA->Draw();

        latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
        latexS.DrawLatexNDC(0.60, 0.80, strNoff[c]);
        cPA->SaveAs( (string("V2SP_Lm_")+to_string(c)+".pdf").c_str() );
    }

    for ( int c = 6; c < 10; c++ ) {
        // SP
        hframePt->GetYaxis()->SetTitle("v_{2}{SP}");
        hframePt->Draw();
        legPA->Clear();

        grSP.grSP_H     [c]->vn_Full_PosEtaEP->SetMarkerStyle(kOpenCircle);
        grSP.grSP_H     [c]->vn_Full_NegEtaEP->SetMarkerStyle(kOpenCircle);

        grSP.grSP_H     [c]->vn_Full_PosEtaEP->SetMarkerSize(2.);
        grSP.grSP_H     [c]->vn_Full_NegEtaEP->SetMarkerSize(2.);

        grSP.grSP_H     [c]->vn_Full_PosEtaEP->SetMarkerColor(kRed);
        grSP.grSP_H     [c]->vn_Full_NegEtaEP->SetMarkerColor(kBlue);

        grSP.grSP_H     [c]->vn_Full_PosEtaEP->SetLineColor(kRed);
        grSP.grSP_H     [c]->vn_Full_NegEtaEP->SetLineColor(kBlue);

        grSP.grSP_H     [c]->vn_Full_PosEtaEP->Draw("psame");
        grSP.grSP_H     [c]->vn_Full_NegEtaEP->Draw("psame");

        legPA->AddEntry(grSP.grSP_H     [c]->vn_Full_PosEtaEP, "ch EP+", "p");
        legPA->AddEntry(grSP.grSP_H     [c]->vn_Full_NegEtaEP, "ch EP-", "p");
        legPA->Draw();

        latexS.DrawLatexNDC(0.60, 0.90, "CMS pPb 8.16 TeV");
        latexS.DrawLatexNDC(0.60, 0.80, strNoff[c]);
        cPA->SaveAs( (string("V2SP_ch_")+to_string(c)+".pdf").c_str() );
    }
}


