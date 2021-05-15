#include "../../style.h"
#include "theory.h"
#include "pPb_header.h"

void plotFinalpPb( bool bPre = false )
{
//    SetStyle();

    TFile * fPA_Ks = new TFile("../cumudiff/pPb_Ks2_merged2_corrected.root");
    TFile * fPA_Lm = new TFile("../cumudiff/pPb_Lm2_merged2_corrected.root");
    TFile * fPA_H  = new TFile("../cumudiff/pPb_H_merged2_corrected.root");
    //TFile * fPA_Hveto  = new TFile("../cumudiff/pPb_H_veto10_merged2_corrected.root");
    TFile * fPA_Hveto   = new TFile("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root");
    TFile * fPA_Ksveto  = new TFile("../cumudiff/pPb_Ks_vetoakPu4Jet20eta20_merged2_corrected.root");
    TFile * fPA_Lmveto  = new TFile("../cumudiff/pPb_Lm_vetoakPu4Jet20eta20_merged2_corrected.root");

    CumuGraph grKs(fPA_Ks);
    CumuGraph grLm(fPA_Lm);
    CumuGraph grH (fPA_H);
    CumuGraph grHveto (fPA_Hveto);
    CumuGraph grKsveto(fPA_Ksveto);
    CumuGraph grLmveto(fPA_Lmveto);

    TFile * fPA_SP = new TFile("../cumudiff/V0SP.root");

    SteveGraphSP grSP(fPA_SP);
    grSP.SetSys();

    grH .ReplaceX(grSP.grSP_H);
    grHveto.ReplaceX(grSP.grSP_H);
    grKs.ReplaceX(grSP.grSP_Ks_Sig);
    grKsveto.ReplaceX(grSP.grSP_Ks_Sig);
    grLm.ReplaceX(grSP.grSP_Lm_Sig);
    grLmveto.ReplaceX(grSP.grSP_Lm_Sig);

    grH .SetSys();
    grHveto.SetSys();
    grKs.SetSys();
    grKsveto.SetSys();
    grLm.SetSys();
    grLmveto.SetSys();

    // H  -- 1
    // Ks -- 0
    // Lm -- 3
    grSP.DropPoints();

    grH.DropPoints(1);
    grHveto.DropPoints(1);
    grLm.DropPoints(3);
    grLmveto.DropPoints(3);

    TFile * fsave = new TFile( "plotFinalpPb.root", "recreate" );
    SaveToFile s2f( fsave );

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
    TLine line0(0.01, 0., 8.5, 0.);

    TCanvas * cpPbV2 = MakeCanvas("cpPbV2", "cpPbV2", 1400, 400);
    splitCanv4(cpPbV2);

    TCanvas * cpPbV2_1 = MakeCanvas("cpPbV2_1", "cpPbV2_1", 1400, 400);
    splitCanv4(cpPbV2_1);

    TH2D * hframe_pt = new TH2D("hframe_pt", "hframe_pt", 1, 0.01, 8.5, 1, -0.12, 0.36);
    InitHist(hframe_pt, "p_{T} (GeV)", "v_{2}");
    hframe_pt->GetYaxis()->SetTitleOffset(1.0);
    hframe_pt->GetXaxis()->SetTitleOffset(0.90);

    TGraphErrors * gChF[10] = {};
    TGraphErrors * gKsF[10] = {};
    TGraphErrors * gLmF[10] = {};

    TGraphErrors * gChFveto[10] = {};
    TGraphErrors * gKsFveto[10] = {};
    TGraphErrors * gLmFveto[10] = {};

    TGraphErrors * gChF_sys[10] = {};
    TGraphErrors * gKsF_sys[10] = {};
    TGraphErrors * gLmF_sys[10] = {};

    TGraphErrors * gChFveto_sys[10] = {};
    TGraphErrors * gKsFveto_sys[10] = {};
    TGraphErrors * gLmFveto_sys[10] = {};

    TGraphErrors * gCh42[10] = {};
    TGraphErrors * gKs42[10] = {};
    TGraphErrors * gLm42[10] = {};

    TGraphErrors * gCh42_sys[10] = {};
    TGraphErrors * gKs42_sys[10] = {};
    TGraphErrors * gLm42_sys[10] = {};

    TGraphErrors * gCh6[10] = {};
    TGraphErrors * gKs6[10] = {};
    TGraphErrors * gLm6[10] = {};

    TGraphErrors * gCh6_sys[10] = {};
    TGraphErrors * gKs6_sys[10] = {};
    TGraphErrors * gLm6_sys[10] = {};

    TGraphErrors* grChRatioCu1[10] = {};
    TGraphErrors* grKsRatioCu1[10] = {};
    TGraphErrors* grLmRatioCu1[10] = {};

    TGraphErrors* grSysChRatioCu1[10] = {};
    TGraphErrors* grSysKsRatioCu1[10] = {};
    TGraphErrors* grSysLmRatioCu1[10] = {};

    TGraphErrors* grChDeltaCu1[10] = {};
    TGraphErrors* grKsDeltaCu1[10] = {};
    TGraphErrors* grLmDeltaCu1[10] = {};

    TGraphErrors* grSysChDeltaCu1[10] = {};
    TGraphErrors* grSysKsDeltaCu1[10] = {};
    TGraphErrors* grSysLmDeltaCu1[10] = {};

    TGraphErrors* grChRatioVeto2[10] = {};
    TGraphErrors* grChRatioVeto4[10] = {};
    TGraphErrors* grChRatioVeto6[10] = {};
    TGraphErrors* grKsRatioVeto2[10] = {};
    TGraphErrors* grKsRatioVeto4[10] = {};
    TGraphErrors* grKsRatioVeto6[10] = {};
    TGraphErrors* grLmRatioVeto2[10] = {};
    TGraphErrors* grLmRatioVeto4[10] = {};
    TGraphErrors* grLmRatioVeto6[10] = {};

    TGraphErrors* grChRatioVeto2_sys[10] = {};
    TGraphErrors* grChRatioVeto4_sys[10] = {};
    TGraphErrors* grChRatioVeto6_sys[10] = {};
    TGraphErrors* grKsRatioVeto2_sys[10] = {};
    TGraphErrors* grKsRatioVeto4_sys[10] = {};
    TGraphErrors* grKsRatioVeto6_sys[10] = {};
    TGraphErrors* grLmRatioVeto2_sys[10] = {};
    TGraphErrors* grLmRatioVeto4_sys[10] = {};
    TGraphErrors* grLmRatioVeto6_sys[10] = {};

    TGraphErrors* grChVetoDelta4[10] = {};
    TGraphErrors* grChVetoDelta6[10] = {};
    TGraphErrors* grChVetoDelta4_sys[10] = {};
    TGraphErrors* grChVetoDelta6_sys[10] = {};

    TGraphErrors * grChRatioPos[10] = {};
    TGraphErrors * grChRatioNeg[10] = {};

    TGraphErrors * grChVetoRatioPos[10] = {};
    TGraphErrors * grChVetoRatioNeg[10] = {};

    for ( int c = 6; c < 10; c++ ) {
        gChF[c] = getFluct( grSP.grSP_H[c]->vn_Full_NegEtaEP     , grH .gr_v24[c], gChF_sys[c] );
        gKsF[c] = getFluct( grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP, grKs.gr_v24[c], gKsF_sys[c] );
        gLmF[c] = getFluct( grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP, grLm.gr_v24[c], gLmF_sys[c] );

        gChFveto[c] = getFluct( grSP.grSP_H[c]->vn_Full_NegEtaEP     , grHveto .gr_v24[c], gChFveto_sys[c] );
        gKsFveto[c] = getFluct( grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP, grKsveto.gr_v24[c], gKsFveto_sys[c] );
        gLmFveto[c] = getFluct( grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP, grLmveto.gr_v24[c], gLmFveto_sys[c] );

        gCh42[c] = getRatio(grH .gr_v24[c], grSP.grSP_H[c]->vn_Full_NegEtaEP      );
        gKs42[c] = getRatio(grKs.gr_v24[c], grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP );
        gLm42[c] = getRatio(grLm.gr_v24[c], grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP );

        gCh42_sys[c] = getRatio(grH .gr_v24[c], grSP.grSP_H[c]->vn_Full_NegEtaEP,      10 );
        gKs42_sys[c] = getRatio(grKs.gr_v24[c], grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP, 11 );
        gLm42_sys[c] = getRatio(grLm.gr_v24[c], grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP, 12 );

        s2f.WriteGr( gCh42[c], Form("grCh42_%i", c) );
        s2f.WriteGr( gKs42[c], Form("grKs42_%i", c) );
        s2f.WriteGr( gLm42[c], Form("grLm42_%i", c) );
        s2f.WriteGr( gCh42_sys[c], Form("grCh42sys_%i", c) );
        s2f.WriteGr( gKs42_sys[c], Form("grKs42sys_%i", c) );
        s2f.WriteGr( gLm42_sys[c], Form("grLm42sys_%i", c) );

        gCh6[c] = getFluct( grSP.grSP_H[c]->vn_Full_NegEtaEP     , grH .gr_v26[c], gCh6_sys[c]);
        gKs6[c] = getFluct( grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP, grKs.gr_v26[c], gKs6_sys[c]);
        gLm6[c] = getFluct( grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP, grLm.gr_v26[c], gLm6_sys[c]);

        grChRatioCu1[c] = getRatio( grH.gr_v24sub[c],    grH.gr_v24[c] , 3 );
        grKsRatioCu1[c] = getRatio( grKs.gr_v24sub[c],   grKs.gr_v24[c], 3 );
        grLmRatioCu1[c] = getRatio( grLm.gr_v24sub[c],   grLm.gr_v24[c], 3 );

        grSysChRatioCu1[c] = getRatio( grH.gr_v24sub[c],  grH.gr_v24[c] , 10);
        grSysKsRatioCu1[c] = getRatio( grKs.gr_v24sub[c], grKs.gr_v24[c], 11);
        grSysLmRatioCu1[c] = getRatio( grLm.gr_v24sub[c], grLm.gr_v24[c], 12);

        grChDeltaCu1[c] = getDelta( grH.gr_v24sub[c],    grH.gr_v24[c] , 3 );
        grKsDeltaCu1[c] = getDelta( grKs.gr_v24sub[c],   grKs.gr_v24[c], 3 );
        grLmDeltaCu1[c] = getDelta( grLm.gr_v24sub[c],   grLm.gr_v24[c], 3 );

        grSysChDeltaCu1[c] = getDelta( grH.gr_v24sub[c],  grH.gr_v24[c] , 10);
        grSysKsDeltaCu1[c] = getDelta( grKs.gr_v24sub[c], grKs.gr_v24[c], 11);
        grSysLmDeltaCu1[c] = getDelta( grLm.gr_v24sub[c], grLm.gr_v24[c], 12);

        grChRatioVeto2[c] = getRatio( grHveto.gr_v22Gap[c],  grH.gr_v22Gap[c] , 3 );
        grChRatioVeto4[c] = getRatio( grHveto.gr_v24[c],     grH.gr_v24[c]    , 3 );
        grChRatioVeto6[c] = getRatio( grHveto.gr_v26[c],     grH.gr_v26[c]    , 3 );
        grKsRatioVeto2[c] = getRatio( grKsveto.gr_v22Gap[c], grKs.gr_v22Gap[c], 3 );
        grKsRatioVeto4[c] = getRatio( grKsveto.gr_v24[c],    grKs.gr_v24[c]   , 3 );
        grKsRatioVeto6[c] = getRatio( grKsveto.gr_v26[c],    grKs.gr_v26[c]   , 3 );
        grLmRatioVeto2[c] = getRatio( grLmveto.gr_v22Gap[c], grLm.gr_v22Gap[c], 3 );
        grLmRatioVeto4[c] = getRatio( grLmveto.gr_v24[c],    grLm.gr_v24[c]   , 3 );
        grLmRatioVeto6[c] = getRatio( grLmveto.gr_v26[c],    grLm.gr_v26[c]   , 3 );

        grChRatioVeto2_sys[c] = getRatio( grHveto.gr_v22Gap[c],  grH.gr_v22Gap[c] , 10 );
        grChRatioVeto4_sys[c] = getRatio( grHveto.gr_v24[c],     grH.gr_v24[c]    , 10 );
        grChRatioVeto6_sys[c] = getRatio( grHveto.gr_v26[c],     grH.gr_v26[c]    , 10 );
        grKsRatioVeto2_sys[c] = getRatio( grKsveto.gr_v22Gap[c], grKs.gr_v22Gap[c], 11 );
        grKsRatioVeto4_sys[c] = getRatio( grKsveto.gr_v24[c],    grKs.gr_v24[c]   , 11 );
        grKsRatioVeto6_sys[c] = getRatio( grKsveto.gr_v26[c],    grKs.gr_v26[c]   , 11 );
        grLmRatioVeto2_sys[c] = getRatio( grLmveto.gr_v22Gap[c], grLm.gr_v22Gap[c], 12 );
        grLmRatioVeto4_sys[c] = getRatio( grLmveto.gr_v24[c],    grLm.gr_v24[c]   , 12 );
        grLmRatioVeto6_sys[c] = getRatio( grLmveto.gr_v26[c],    grLm.gr_v26[c]   , 12 );

        grChVetoDelta4[c] = getDelta( grHveto.gr_v24[c],     grH.gr_v24[c]    , 3 );
        grChVetoDelta6[c] = getDelta( grHveto.gr_v26[c],     grH.gr_v26[c]    , 3 );
        grChVetoDelta4_sys[c] = getDelta( grHveto.gr_v24[c],     grH.gr_v24[c]    , 10 );
        grChVetoDelta6_sys[c] = getDelta( grHveto.gr_v26[c],     grH.gr_v26[c]    , 10 );

        grChRatioPos[c] = getRatio(grH.gr_v24subpos[c], grH.gr_v24sub[c]);
        grChRatioNeg[c] = getRatio(grH.gr_v24subneg[c], grH.gr_v24sub[c]);

        grChVetoRatioPos[c] = getRatio(grHveto.gr_v24subpos[c], grHveto.gr_v24sub[c]);
        grChVetoRatioNeg[c] = getRatio(grHveto.gr_v24subneg[c], grHveto.gr_v24sub[c]);

        if ( c == 6 ) {
            // H
//            DropPoints( grH.grSys_v24[c], -2 );
//            DropPoints( grH.gr_v24[c],    -2 );
//            DropPoints( grH.gr_v24sub[c], -2 );

            DropPoints( grH.gr_v24subpos[c], -2 );
            DropPoints( grH.gr_v24subneg[c], -2 );
            //DropPoints( grHveto.gr_v24[c],   -2 );

            //DropPoints( grHveto.gr_v24sub[c],    -2 );
            //DropPoints( grHveto.gr_v24subpos[c], -2 );
            //DropPoints( grHveto.gr_v24subneg[c], -2 );

            DropPoints( grChRatioVeto4[c], -2 );
            DropPoints( grChRatioVeto4_sys[c], -2 );
//            DropPoints( grChVetoDelta4[c], -2 );
//            DropPoints( grChVetoDelta4_sys[c], -2 );

            DropPoints( grChRatioCu1[c], -2 );
            DropPoints( grSysChRatioCu1[c], -2 );
//            DropPoints( grChDeltaCu1[c], -2 );
//            DropPoints( grSysChDeltaCu1[c], -2 );

            DropPoints( gChF_sys[c], -2 );
            DropPoints( gChF[c],     -2 );
            DropPoints( gCh6_sys[c], -1 );
            DropPoints( gCh6[c],     -1 );

            // Ks
            DropPoints( grKs.grSys_v24[c], 1 );
            DropPoints( grKs.gr_v24[c],    1 );
            DropPoints( grKs.gr_v24sub[c], 1 );

//            DropPoints( grKs.grSys_v24[c], -2 );
//            DropPoints( grKs.gr_v24[c],    -2 );
//            DropPoints( grKs.gr_v24sub[c], -2 );

            DropPoints( grKs.grSys_v26[c], 1 );
            DropPoints( grKs.gr_v26[c],    1 );

            DropPoints( grKs.grSys_v26[c], -3 );
            DropPoints( grKs.gr_v26[c],    -3 );

            DropPoints( gKsF_sys[c], 1 );
            DropPoints( gKsF[c],     1 );
            DropPoints( gKsF_sys[c], -2 );
            DropPoints( gKsF[c],     -2 );

            // Lm
//            DropPoints( grLm.grSys_v24[c], -1 );
//            DropPoints( grLm.gr_v24[c],    -1 );

            DropPoints( gLmF_sys[c], -1 );
            DropPoints( gLmF[c],     -1 );

        } else if ( c == 7 ) {
            // H
//            DropPoints( grH.grSys_v24[c], -1 );
//            DropPoints( grH.gr_v24[c],    -1 );
//            DropPoints( grH.gr_v24sub[c], -2 );

            DropPoints( grH.gr_v24subpos[c], -1 );
            DropPoints( grH.gr_v24subneg[c], -1 );
            //DropPoints( grHveto.gr_v24[c],   -1 );

            //DropPoints( grHveto.gr_v24sub[c],    -1 );
            //DropPoints( grHveto.gr_v24subpos[c], -1 );
            //DropPoints( grHveto.gr_v24subneg[c], -1 );

            DropPoints( grChRatioVeto4[c], -1 );
            DropPoints( grChRatioVeto4_sys[c], -1 );
//            DropPoints( grChVetoDelta4[c], -1 );
//            DropPoints( grChVetoDelta4_sys[c], -1 );

            DropPoints( grChRatioCu1[c],   -2 );
            DropPoints( grSysChRatioCu1[c],   -2 );
//            DropPoints( grChDeltaCu1[c],   -2 );
//            DropPoints( grSysChDeltaCu1[c],   -2 );

            DropPoints( gChF_sys[c], -1 );
            DropPoints( gChF[c],     -1 );
            DropPoints( gCh6_sys[c], -1 );
            DropPoints( gCh6[c],     -1 );

            // Ks
            DropPoints( grKs.grSys_v24[c], 1 );
            DropPoints( grKs.gr_v24[c],    1 );
//            DropPoints( grKs.grSys_v24[c], -1 );
//            DropPoints( grKs.gr_v24[c],    -1 );
//            DropPoints( grKs.gr_v24sub[c], 1 );
//            DropPoints( grKs.gr_v24sub[c], -2 );

            DropPoints( grKsRatioCu1[c],   1 );
            DropPoints( grKsRatioCu1[c],   -2 );
            DropPoints( grSysKsRatioCu1[c],   1 );
            DropPoints( grSysKsRatioCu1[c],   -2 );
            DropPoints( grKsDeltaCu1[c],   1 );
            DropPoints( grKsDeltaCu1[c],   -2 );
            DropPoints( grSysKsDeltaCu1[c],   1 );
            DropPoints( grSysKsDeltaCu1[c],   -2 );

            DropPoints( gKsF_sys[c], 1 );
            DropPoints( gKsF[c],     1 );
            DropPoints( gKsF_sys[c], -1 );
            DropPoints( gKsF[c],     -1 );

            // Lm
//            DropPoints( grLm.grSys_v24[c], -1 );
//            DropPoints( grLm.gr_v24[c],    -1 );

            DropPoints( gLmF_sys[c], -1 );
            DropPoints( gLmF[c],     -1 );

        } else if ( c == 8 ) {
            // H
//            DropPoints( grH.gr_v24sub[c],   -1 );
            DropPoints( grChRatioCu1[c],    -1 );
            DropPoints( grSysChRatioCu1[c], -1 );
//            DropPoints( grChDeltaCu1[c],    -1 );
//            DropPoints( grSysChDeltaCu1[c], -1 );

            // Ks
            DropPoints( grKs.grSys_v24[c], 1 );
            DropPoints( grKs.gr_v24[c],    1 );

            DropPoints( grKs.gr_v24sub[c], 1 );
//            DropPoints( grKs.gr_v24sub[c], -1 );
            DropPoints( grKsRatioCu1[c],   1 );
            DropPoints( grKsRatioCu1[c],   -1 );
            DropPoints( grSysKsRatioCu1[c],   1 );
            DropPoints( grSysKsRatioCu1[c],   -1 );
            DropPoints( grKsDeltaCu1[c],   1 );
//            DropPoints( grKsDeltaCu1[c],   -1 );
            DropPoints( grSysKsDeltaCu1[c],   1 );
            DropPoints( grSysKsDeltaCu1[c],   -1 );

            DropPoints( grKs.grSys_v26[c], 1 );
            DropPoints( grKs.gr_v26[c],    1 );

            DropPoints( gKsF_sys[c], 1 );
            DropPoints( gKsF[c],     1 );
            DropPoints( gKs42_sys[c], 1 );
            DropPoints( gKs42[c],     1 );

            // Lm
            DropPoints( grLm.grSys_v26[c], 1 );
            DropPoints( grLm.gr_v26[c],    1 );
        } else if ( c == 9 ) {
            // H
            DropPoints( grH.gr_v28[c],    -1 );
            // Ks
            DropPoints( grKs.grSys_v24[c], 1 );
            DropPoints( grKs.gr_v24[c],    1 );
            DropPoints( grKs.gr_v24sub[c], 1 );

            DropPoints( grKsRatioCu1[c],   1 );
            DropPoints( grSysKsRatioCu1[c],   1 );
            DropPoints( grKsDeltaCu1[c],   1 );
            DropPoints( grSysKsDeltaCu1[c],   1 );

            DropPoints( gKsF_sys[c], 1 );
            DropPoints( gKsF[c],     1 );

            // Lm
            DropPoints( grLm.grSys_v24[c], 1 );
            DropPoints( grLm.gr_v24[c],    1 );
//            DropPoints( grLm.grSys_v24[c], -1 );
//            DropPoints( grLm.gr_v24[c],    -1 );

            DropPoints( gLmF_sys[c], 1 );
            DropPoints( gLmF[c],     1 );
            DropPoints( gLmF_sys[c], -1 );
            DropPoints( gLmF[c],     -1 );
        }
    }
    // ch v2
    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_pt->Draw();
        line0.Draw();

        setGr(grSP.grSP_H[c]->vn_Full_PosEtaEP, kOpenCircle, kBlue, 2.);
        setGr(grSP.grSP_H[c]->vn_Full_NegEtaEP, kOpenCircle, kRed,  2.);

        grSP.grSP_H[c]->vn_sys_Full_PosEtaEP->SetFillColor(3003);
        grSP.grSP_H[c]->vn_sys_Full_NegEtaEP->SetFillColor(3001);

        setGr(grH.gr_v24[c], kOpenStar,  kBlue, 2.);
        setGr(grH.gr_v26[c], kFullCross, kRed,  2.);
        setGr(grH.gr_v28[c], kFullDiamond, kGreen+2,  2.);

        grH.grSys_v24[c]->SetFillColor(3003);
        grH.grSys_v26[c]->SetFillColor(3001);
        grH.grSys_v28[c]->SetFillColor(3002);

        grSP.grSP_H[c]->vn_sys_Full_PosEtaEP->Draw("[]2");
        grSP.grSP_H[c]->vn_sys_Full_NegEtaEP->Draw("[]2");

        grSP.grSP_H[c]->vn_Full_PosEtaEP->Draw("psame");
        grSP.grSP_H[c]->vn_Full_NegEtaEP->Draw("psame");

        grH.grSys_v24[c]->Draw("[]2");
        grH.grSys_v26[c]->Draw("[]2");

        grH.gr_v24[c]->Draw("psame");
        grH.gr_v26[c]->Draw("psame");

        if ( c==8 ) {
            grH.grSys_v28[c]->Draw("[]2");
            grH.gr_v28[c]->Draw("psame");
        }

        s2f.WriteGr( grSP.grSP_H[c]->vn_sys_Full_PosEtaEP, Form( "grChSys_v2sp_Full_PosEtaEP_%i", c ) );
        s2f.WriteGr( grSP.grSP_H[c]->vn_sys_Full_NegEtaEP, Form( "grChSys_v2sp_Full_NegEtaEP_%i", c ) );
        s2f.WriteGr( grSP.grSP_H[c]->vn_Full_PosEtaEP,     Form( "grCh_v2sp_Full_PosEtaEP_%i", c ) );
        s2f.WriteGr( grSP.grSP_H[c]->vn_Full_NegEtaEP,     Form( "grCh_v2sp_Full_NegEtaEP_%i", c ) );

        s2f.WriteGr( grH.grSys_v22Gap[c], Form( "grChSys_v22Gap_%i", c ) );
        s2f.WriteGr( grH.grSys_v24[c], Form( "grChSys_v24_%i", c ) );
        s2f.WriteGr( grH.grSys_v26[c], Form( "grChSys_v26_%i", c ) );
        s2f.WriteGr( grH.grSys_v28[c], Form( "grChSys_v28_%i", c ) );
        s2f.WriteGr( grH.gr_v22Gap[c],    Form( "grCh_v22Gap_%i", c ) );
        s2f.WriteGr( grH.gr_v24[c],    Form( "grCh_v24_%i", c ) );
        s2f.WriteGr( grH.gr_v26[c],    Form( "grCh_v26_%i", c ) );
        s2f.WriteGr( grH.gr_v28[c],    Form( "grCh_v28_%i", c ) );
    }
    cpPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{Charge hadron}");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);

    TLegend * legCh0 = new TLegend(0.65, 0.75, 0.95, 0.92);
    legCh0->SetFillColor(kWhite);
    legCh0->SetTextFont(42);
    legCh0->SetTextSize(0.05);
    legCh0->SetBorderSize(0);

    legCh0->AddEntry(grSP.grSP_H[6]->vn_Full_PosEtaEP, "v_{2}{p-SP}",  "p");
    legCh0->AddEntry(grSP.grSP_H[6]->vn_Full_NegEtaEP, "v_{2}{Pb-SP}", "p");

    TLegend * legCh1 = new TLegend(0.65, 0.665, 0.95, 0.92);
    legCh1->SetFillColor(kWhite);
    legCh1->SetTextFont(42);
    legCh1->SetTextSize(0.05);
    legCh1->SetBorderSize(0);

    legCh1->AddEntry(grH.gr_v24[6], "v_{2}{4}",     "p");
    legCh1->AddEntry(grH.gr_v26[6], "v_{2}{6}",     "p");
    legCh1->AddEntry(grH.gr_v28[6], "v_{2}{8}",     "p");


    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);
    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);
    legCh0->Draw();
    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);
    legCh1->Draw();

    cpPbV2->SaveAs("pPbV2_Ch.pdf");

    // Ks v2
    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_pt->Draw();
        line0.Draw();

        setGr(grSP.grSP_Ks_Sig[c]->vn_Full_PosEtaEP, kOpenCircle, kBlue, 2.);
        setGr(grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP, kOpenCircle, kRed,  2.);

        grSP.grSP_Ks_Sig[c]->vn_sys_Full_PosEtaEP->SetFillColor(3003);
        grSP.grSP_Ks_Sig[c]->vn_sys_Full_NegEtaEP->SetFillColor(3001);

        setGr(grKs.gr_v24[c], kOpenStar,  kBlue, 2.);
        setGr(grKs.gr_v26[c], kFullCross, kRed,  2.);

        grKs.grSys_v24[c]->SetFillColor(3003);
        grKs.grSys_v26[c]->SetFillColor(3001);

        grSP.grSP_Ks_Sig[c]->vn_sys_Full_PosEtaEP->Draw("[]2");
        grSP.grSP_Ks_Sig[c]->vn_sys_Full_NegEtaEP->Draw("[]2");

        grSP.grSP_Ks_Sig[c]->vn_Full_PosEtaEP->Draw("psame");
        grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP->Draw("psame");

        grKs.grSys_v24[c]->Draw("[]2");
        grKs.gr_v24[c]->Draw("psame");

        if ( c==8 ) { // or (c==6) or (c==7) or (c==9) ) {
            grKs.grSys_v26[c]->Draw("[]2");
            grKs.gr_v26[c]->Draw("psame");
        }

        s2f.WriteGr( grSP.grSP_Ks_Sig[c]->vn_sys_Full_PosEtaEP, Form( "grKsSys_v2sp_Full_PosEtaEP_%i", c ) );
        s2f.WriteGr( grSP.grSP_Ks_Sig[c]->vn_sys_Full_NegEtaEP, Form( "grKsSys_v2sp_Full_NegEtaEP_%i", c ) );
        s2f.WriteGr( grSP.grSP_Ks_Sig[c]->vn_Full_PosEtaEP,     Form( "grKs_v2sp_Full_PosEtaEP_%i", c ) );
        s2f.WriteGr( grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP,     Form( "grKs_v2sp_Full_NegEtaEP_%i", c ) );

        s2f.WriteGr( grKs.grSys_v24[c], Form( "grKsSys_v24_%i", c ) );
        s2f.WriteGr( grKs.grSys_v26[c], Form( "grKsSys_v26_%i", c ) );
        s2f.WriteGr( grKs.gr_v24[c],    Form( "grKs_v24_%i", c ) );
        s2f.WriteGr( grKs.gr_v26[c],    Form( "grKs_v26_%i", c ) );
    }
    cpPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{K_{S}^{0}}");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);

    TLegend * legKs0 = new TLegend(0.65, 0.75, 0.95, 0.92);
    legKs0->SetFillColor(kWhite);
    legKs0->SetTextFont(42);
    legKs0->SetTextSize(0.05);
    legKs0->SetBorderSize(0);

    legKs0->AddEntry(grSP.grSP_Ks_Sig[6]->vn_Full_PosEtaEP, "v_{2}{p-SP}",  "p");
    legKs0->AddEntry(grSP.grSP_Ks_Sig[6]->vn_Full_NegEtaEP, "v_{2}{Pb-SP}", "p");

    TLegend * legKs1 = new TLegend(0.65, 0.75, 0.95, 0.92);
    legKs1->SetFillColor(kWhite);
    legKs1->SetTextFont(42);
    legKs1->SetTextSize(0.05);
    legKs1->SetBorderSize(0);

    legKs1->AddEntry(grH.gr_v24[6], "v_{2}{4}",     "p");
    legKs1->AddEntry(grH.gr_v26[6], "v_{2}{6}",     "p");

    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);
    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);
    legKs0->Draw();
    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);
    legKs1->Draw();

    cpPbV2->SaveAs("pPbV2_Ks.pdf");

    // Lm v2
    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_pt->Draw();
        line0.Draw();

        setGr(grSP.grSP_Lm_Sig[c]->vn_Full_PosEtaEP, kOpenCircle, kBlue, 2.);
        setGr(grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP, kOpenCircle, kRed,  2.);

        grSP.grSP_Lm_Sig[c]->vn_sys_Full_PosEtaEP->SetFillColor(3003);
        grSP.grSP_Lm_Sig[c]->vn_sys_Full_NegEtaEP->SetFillColor(3001);

        setGr(grLm.gr_v24[c], kOpenStar,  kBlue, 2.);
        setGr(grLm.gr_v26[c], kFullCross, kRed,  2.);

        grLm.grSys_v24[c]->SetFillColor(3003);
        grLm.grSys_v26[c]->SetFillColor(3001);

        grSP.grSP_Lm_Sig[c]->vn_sys_Full_PosEtaEP->Draw("[]2");
        grSP.grSP_Lm_Sig[c]->vn_sys_Full_NegEtaEP->Draw("[]2");

        grSP.grSP_Lm_Sig[c]->vn_Full_PosEtaEP->Draw("psame");
        grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP->Draw("psame");

        grLm.grSys_v24[c]->Draw("[]2");
        grLm.gr_v24[c]->Draw("psame");

        if ( c == 8 ) {
            grLm.grSys_v26[c]->Draw("[]2");
            grLm.gr_v26[c]->Draw("psame");
        }

        s2f.WriteGr( grSP.grSP_Lm_Sig[c]->vn_sys_Full_PosEtaEP, Form( "grLmSys_v2sp_Full_PosEtaEP_%i", c ) );
        s2f.WriteGr( grSP.grSP_Lm_Sig[c]->vn_sys_Full_NegEtaEP, Form( "grLmSys_v2sp_Full_NegEtaEP_%i", c ) );
        s2f.WriteGr( grSP.grSP_Lm_Sig[c]->vn_Full_PosEtaEP,     Form( "grLm_v2sp_Full_PosEtaEP_%i", c ) );
        s2f.WriteGr( grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP,     Form( "grLm_v2sp_Full_NegEtaEP_%i", c ) );

        s2f.WriteGr( grLm.grSys_v24[c], Form( "grLmSys_v24_%i", c ) );
        s2f.WriteGr( grLm.grSys_v26[c], Form( "grLmSys_v26_%i", c ) );
        s2f.WriteGr( grLm.gr_v24[c],    Form( "grLm_v24_%i", c ) );
        s2f.WriteGr( grLm.gr_v26[c],    Form( "grLm_v26_%i", c ) );
    }

    cpPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{#Lambda}");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);

    TLegend * legLm0 = new TLegend(0.65, 0.75, 0.95, 0.92);
    legLm0->SetFillColor(kWhite);
    legLm0->SetTextFont(42);
    legLm0->SetTextSize(0.05);
    legLm0->SetBorderSize(0);

    legLm0->AddEntry(grSP.grSP_Lm_Sig[6]->vn_Full_PosEtaEP, "v_{2}{p-SP}",  "p");
    legLm0->AddEntry(grSP.grSP_Lm_Sig[6]->vn_Full_NegEtaEP, "v_{2}{Pb-SP}", "p");

    TLegend * legLm1 = new TLegend(0.65, 0.75, 0.95, 0.92);
    legLm1->SetFillColor(kWhite);
    legLm1->SetTextFont(42);
    legLm1->SetTextSize(0.05);
    legLm1->SetBorderSize(0);

    legLm1->AddEntry(grH.gr_v24[6], "v_{2}{4}",     "p");
    legLm1->AddEntry(grH.gr_v26[6], "v_{2}{6}",     "p");


    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);
    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);
    legLm0->Draw();
    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);
    legLm1->Draw();

    cpPbV2->SaveAs("pPbV2_Lm.pdf");

    // fluctuation
    TH2D * hframe_fluct = new TH2D("hframe_fluct", "hframe_fluct", 1, 0.01, 8.5, 1, 0.05, 1.5);
    InitHist(hframe_fluct, "p_{T} (GeV)", "#sigma / v_{2}");
    hframe_fluct->GetYaxis()->SetTitleOffset(1.0);
    hframe_fluct->GetXaxis()->SetTitleOffset(0.90);

    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_fluct->Draw();
        line1.Draw();

        gChF[c]->SetMarkerStyle(kOpenCircle);
        gChF[c]->SetMarkerColor(kBlack);
        gChF[c]->SetLineColor  (kBlack);
        gChF[c]->SetMarkerSize(2.);

        gChFveto[c]->SetMarkerStyle(kOpenCircle);
        gChFveto[c]->SetMarkerColor(kRed);
        gChFveto[c]->SetLineColor  (kRed);
        gChFveto[c]->SetMarkerSize(2.);

        gChF_sys[c]->SetFillColor(3005);
        gCh6_sys[c]->SetFillColor(3003);
        gChFveto_sys[c]->SetFillColor(3001);

        gCh6[c]->SetMarkerStyle(kOpenCircle);
        gCh6[c]->SetMarkerColor(kBlue);
        gCh6[c]->SetLineColor  (kBlue);
        gCh6[c]->SetMarkerSize(2.);

        gKsF[c]->SetMarkerStyle(kOpenCircle);
        gKsF[c]->SetMarkerColor(kBlue);
        gKsF[c]->SetLineColor  (kBlue);
        gKsF[c]->SetMarkerSize(2.);

        gKsF_sys[c]->SetFillColor(3003);

        gKs6[c]->SetMarkerStyle(kFullCircle);
        gKs6[c]->SetMarkerColor(kBlue);
        gKs6[c]->SetLineColor  (kBlue);
        gKs6[c]->SetMarkerSize(2.);

        gLmF[c]->SetMarkerStyle(kOpenCircle);
        gLmF[c]->SetMarkerColor(kRed);
        gLmF[c]->SetLineColor  (kRed);
        gLmF[c]->SetMarkerSize(2.);

        gLmF_sys[c]->SetFillColor(3001);

        gLm6[c]->SetMarkerStyle(kFullCircle);
        gLm6[c]->SetMarkerColor(kRed);
        gLm6[c]->SetLineColor  (kRed);
        gLm6[c]->SetMarkerSize(2.);

        gChF_sys[c]->Draw("[]2");
        gKsF_sys[c]->Draw("[]2");
        gLmF_sys[c]->Draw("[]2");

        gChF[c]->Draw("psame");
        gKsF[c]->Draw("psame");
        gLmF[c]->Draw("psame");

        cpPbV2_1->cd(c-5);
        hframe_fluct->Draw();
        line1.Draw();
        gChF_sys[c]->Draw("[]2");
        gCh6_sys[c]->Draw("[]2");
        gChFveto_sys[c]->Draw("[]2");

        gChF[c]->Draw("psame");
        gCh6[c]->Draw("psame");
        gChFveto[c]->Draw("psame");

        s2f.WriteGr( gChF_sys[c], Form( "grCh_Fluct_sys_%i", c ) );
        s2f.WriteGr( gKsF_sys[c], Form( "grKs_Fluct_sys_%i", c ) );
        s2f.WriteGr( gLmF_sys[c], Form( "grLm_Fluct_sys_%i", c ) );

        s2f.WriteGr( gChF[c], Form( "grCh_Fluct_%i", c ) );
        s2f.WriteGr( gKsF[c], Form( "grKs_Fluct_%i", c ) );
        s2f.WriteGr( gLmF[c], Form( "grLm_Fluct_%i", c ) );

        s2f.WriteGr( gChFveto_sys[c], Form( "grChveto_Fluct_sys_%i", c ) );
        s2f.WriteGr( gKsFveto_sys[c], Form( "grKsveto_Fluct_sys_%i", c ) );
        s2f.WriteGr( gLmFveto_sys[c], Form( "grLmveto_Fluct_sys_%i", c ) );

        s2f.WriteGr( gChFveto[c], Form( "grChveto_Fluct_%i", c ) );
        s2f.WriteGr( gKsFveto[c], Form( "grKsveto_Fluct_%i", c ) );
        s2f.WriteGr( gLmFveto[c], Form( "grLmveto_Fluct_%i", c ) );

        s2f.WriteGr( gCh6_sys[c], Form( "grCh6_Fluct_sys_%i", c ) );
        s2f.WriteGr( gKs6_sys[c], Form( "grKs6_Fluct_sys_%i", c ) );
        s2f.WriteGr( gLm6_sys[c], Form( "grLm6_Fluct_sys_%i", c ) );

        s2f.WriteGr( gCh6[c], Form( "grCh6_Fluct_%i", c ) );
        s2f.WriteGr( gKs6[c], Form( "grKs6_Fluct_%i", c ) );
        s2f.WriteGr( gLm6[c], Form( "grLm6_Fluct_%i", c ) );
    }

    cpPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
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
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{Charge hadron}");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);

    TLegend * legFl6 = new TLegend(0.56, 0.72, 0.90, 0.92);
    legFl6->SetFillColor(kWhite);
    legFl6->SetTextFont(42);
    legFl6->SetTextSize(0.05);
    legFl6->SetBorderSize(0);

    legFl6->AddEntry(gChF[6], "from v_{2}{4}", "p");
    legFl6->AddEntry(gCh6[6], "from v_{2}{6}", "p");
    legFl6->AddEntry(gChFveto[6], "from v_{2}{4, veto}", "p");


    cpPbV2_1->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);

    cpPbV2_1->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);

    cpPbV2_1->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);
    legFl6->Draw();

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
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{K_{S}^{0}}");
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
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{#Lambda}");
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
    TH2D * hframe_ptsub = new TH2D("hframe_ptsub", "hframe_ptsub", 1, 0.01, 8.5, 1, -0.18, 0.36);
    InitHist(hframe_ptsub, "p_{T} (GeV)", "v_{2}");
    hframe_ptsub->GetYaxis()->SetTitleOffset(1.0);
    hframe_ptsub->GetXaxis()->SetTitleOffset(0.90);

    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_ptsub->Draw();
        line0.Draw();

        setGr( grSP.grSP_H[c]->vn_Full_NegEtaEP,          kFullCircle, kBlue,    2.);
        setGr( grSP.grSP_H[c]->vn_Full_NegEtaEP_SubEvt,   kOpenCircle, kRed,     2.);
        setGr( grSP.grSP_H[c]->vn_PosEta_NegEtaEP,        kOpenCircle, kBlack,   2.);
        setGr( grSP.grSP_H[c]->vn_PosEta_NegEtaEP_SubEvt, kOpenCircle, kGreen+2, 2.);

        setGr( grH.gr_v24[c],       kFullCircle,  kBlue,     2.);
        setGr( grH.gr_v24sub[c],    kOpenCircle,  kRed,      2.);
        setGr( grH.gr_v24subpos[c], kOpenCircle,  kBlack,    2.);
        setGr( grH.gr_v24subneg[c], kOpenCircle,  kGreen+2,  2.);

//        grSP.grSP_H[c]->vn_Full_NegEtaEP         ->Draw("psame");
//        grSP.grSP_H[c]->vn_Full_NegEtaEP_SubEvt  ->Draw("psame");
//        grSP.grSP_H[c]->vn_PosEta_NegEtaEP       ->Draw("psame");
//        grSP.grSP_H[c]->vn_PosEta_NegEtaEP_SubEvt->Draw("psame");

        grH.grSys_v24[c]->SetFillColor(3003);
        grH.grSys_v24sub[c]->SetFillColor(3001);

        grH.grSys_v24[c]                       ->Draw("[]2");
        grH.grSys_v24sub[c]                    ->Draw("[]2");

        grH.gr_v24[c]                          ->Draw("psame");
        grH.gr_v24sub[c]                       ->Draw("psame");
//        grH.gr_v24subpos[c]                    ->Draw("psame");
//        grH.gr_v24subneg[c]                    ->Draw("psame");
        s2f.WriteGr( grH.gr_v24sub[c], Form( "grCh_v24sub_%i", c ) );
        s2f.WriteGr( grH.grSys_v24sub[c], Form( "grSysCh_v24sub_%i", c ) );
    }
    cpPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{Charge hadron}");
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

    legChSub1->AddEntry( grH.gr_v24[6],       "v_{2}{4}",     "p" );
    legChSub1->AddEntry( grH.gr_v24sub[6],    "v_{2}{4,Sub}", "p" );
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
    InitHist(hframe_ratio, "p_{T} (GeV)", "Ratio");
    hframe_ratio->GetYaxis()->SetTitleOffset(1.0);
    hframe_ratio->GetXaxis()->SetTitleOffset(0.90);

    TGraphErrors* grChRatioSP1[10] = {};
    TGraphErrors* grChRatioSP2[10] = {};
    TGraphErrors* grChRatioSP3[10] = {};

//    TGraphErrors* grChRatioCu2[10] = {};
//    TGraphErrors* grChRatioCu3[10] = {};

    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_ratio->Draw();
        line1.Draw();

        grChRatioSP1[c] = getRatio( grSP.grSP_H[c]->vn_Full_NegEtaEP_SubEvt,   grSP.grSP_H[c]->vn_Full_NegEtaEP );
        grChRatioSP2[c] = getRatio( grSP.grSP_H[c]->vn_PosEta_NegEtaEP,        grSP.grSP_H[c]->vn_Full_NegEtaEP );
        grChRatioSP3[c] = getRatio( grSP.grSP_H[c]->vn_PosEta_NegEtaEP_SubEvt, grSP.grSP_H[c]->vn_Full_NegEtaEP );

//        grChRatioCu2[c] = getRatio( grH.gr_v24subpos[c], grH.gr_v24[c] );
//        grChRatioCu3[c] = getRatio( grH.gr_v24subneg[c], grH.gr_v24[c] );



        setGr( grChRatioSP1[c], kOpenCircle, kRed, 2.);
        setGr( grChRatioSP2[c], kOpenCircle, kBlack, 2.);
        setGr( grChRatioSP3[c], kOpenCircle, kGreen+2, 2.);

        setGr( grChRatioCu1[c], kOpenCircle, kBlack, 2.);
        setGr( grKsRatioCu1[c], kOpenCircle, kBlue, 2.);
        setGr( grLmRatioCu1[c], kOpenCircle, kRed, 2.);
//        setGr( grChRatioCu2[c], kOpenSquare, kBlack, 2.);
//        setGr( grChRatioCu3[c], kOpenSquare, kGreen+2, 2.);

//        grChRatioSP1[c]->Draw("psame");
//        grChRatioSP2[c]->Draw("psame");
//        grChRatioSP3[c]->Draw("psame");

        grSysChRatioCu1[c]->SetFillColor(3005);
        grSysChRatioCu1[c]->Draw("[]2");

        grChRatioCu1[c]->Draw("psame");
//        grChRatioCu2[c]->Draw("psame");
//        grChRatioCu3[c]->Draw("psame");

        s2f.WriteGr( grSysChRatioCu1[c], Form( "grCh_v24subRatioSys_%i", c ) );
        s2f.WriteGr( grChRatioCu1[c], Form( "grCh_v24subRatio_%i", c ) );
    }
    cpPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "v_{2}{4,Sub}/v_{2}{4}");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);

    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);

    TLegend * legChRatio1 = new TLegend(0.50, 0.68, 0.98, 0.92);
    legChRatio1->SetFillColor(kWhite);
    legChRatio1->SetTextFont(42);
    legChRatio1->SetTextSize(0.05);
    legChRatio1->SetBorderSize(0);

    legChRatio1->AddEntry( grChRatioCu1[8], "charge hadron", "p" );
    legChRatio1->AddEntry( grKsRatioCu1[8], "K_{S}^{0}", "p" );
    legChRatio1->AddEntry( grLmRatioCu1[8], "#Lambda", "p" );
//    legChRatio1->AddEntry( grChRatioCu2[6], "v_{2}{4,Sub} 0.<#eta<1.", "p" );
//    legChRatio1->AddEntry( grChRatioCu3[6], "v_{2}{4,Sub} -1.<#eta<0.", "p" );


    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);

    DropPoints(grKsRatioCu1[8], 1);
    DropPoints(grKsRatioCu1[8], -1);
    DropPoints(grLmRatioCu1[8], 1);
    DropPoints(grLmRatioCu1[8], -1);

    DropPoints(grSysKsRatioCu1[8], 1);
    DropPoints(grSysKsRatioCu1[8], -1);
    DropPoints(grSysLmRatioCu1[8], 1);
    DropPoints(grSysLmRatioCu1[8], -1);

    grSysKsRatioCu1[8]->SetFillColor(3003);
    grSysLmRatioCu1[8]->SetFillColor(3001);

    grSysKsRatioCu1[8]->Draw("[]2");
    grSysLmRatioCu1[8]->Draw("[]2");

    grKsRatioCu1[8]->Draw("psame");
    grLmRatioCu1[8]->Draw("psame");


    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);

    legChRatio1->Draw();
    cpPbV2->SaveAs("pPbV2_Ratio_Ch.pdf");

    // Ch v2 subevent delta
    TH2D * hframe_pt_delta = new TH2D("hframe_pt_delta", "hframe_pt_delta", 1, 0.01, 8.5, 1, -0.11, 0.09);
    InitHist(hframe_pt_delta, "p_{T} (GeV)", "#Deltav_{2}");
    hframe_pt_delta->GetYaxis()->SetTitleOffset(1.0);
    hframe_pt_delta->GetXaxis()->SetTitleOffset(0.90);

    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_pt_delta->Draw();
        line0.Draw();

        setGr( grChDeltaCu1[c], kOpenCircle, kBlack, 2.);
        setGr( grKsDeltaCu1[c], kOpenCircle, kBlue, 2.);
        setGr( grLmDeltaCu1[c], kOpenCircle, kRed, 2.);

        grSysChDeltaCu1[c]->SetFillColor(3005);
        grSysChDeltaCu1[c]->Draw("[]2");
        grChDeltaCu1[c]->Draw("psame");

        s2f.WriteGr( grSysChDeltaCu1[c], Form( "grCh_v24subDeltaSys_%i", c ) );
        s2f.WriteGr( grChDeltaCu1[c], Form( "grCh_v24subDelta_%i", c ) );
    }
    cpPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "v_{2}{4,Sub} - v_{2}{4}");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);

    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);

    TLegend * legChDelta1 = new TLegend(0.50, 0.68, 0.98, 0.92);
    legChDelta1->SetFillColor(kWhite);
    legChDelta1->SetTextFont(42);
    legChDelta1->SetTextSize(0.05);
    legChDelta1->SetBorderSize(0);

    legChDelta1->AddEntry( grChDeltaCu1[8], "charge hadron", "p" );
    legChDelta1->AddEntry( grKsDeltaCu1[8], "K_{S}^{0}", "p" );
    legChDelta1->AddEntry( grLmDeltaCu1[8], "#Lambda", "p" );

    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);

    DropPoints(grKsDeltaCu1[8], 1);
//    DropPoints(grKsDeltaCu1[8], -1);
    DropPoints(grLmDeltaCu1[8], 1);
//    DropPoints(grLmDeltaCu1[8], -1);

    DropPoints(grSysKsDeltaCu1[8], 1);
    DropPoints(grSysKsDeltaCu1[8], -1);
    DropPoints(grSysLmDeltaCu1[8], 1);
    DropPoints(grSysLmDeltaCu1[8], -1);

    grSysKsDeltaCu1[8]->SetFillColor(3003);
    grSysLmDeltaCu1[8]->SetFillColor(3001);

    grSysKsDeltaCu1[8]->Draw("[]2");
    grSysLmDeltaCu1[8]->Draw("[]2");

    grKsDeltaCu1[8]->Draw("psame");
    grLmDeltaCu1[8]->Draw("psame");

    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);

    legChDelta1->Draw();
    cpPbV2->SaveAs("pPbV2_Delta_Ch.pdf");

    // Ks v2 subevent
    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_ptsub->Draw();
        line0.Draw();

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
        s2f.WriteGr( grKs.gr_v24sub[c], Form( "grKs_v24sub_%i", c ) );
        s2f.WriteGr( grKs.grSys_v24sub[c], Form( "grSysKs_v24sub_%i", c ) );
    }
    cpPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{K_{S}^{0}}");
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

//    TGraphErrors* grKsRatioCu2[10] = {};
//    TGraphErrors* grKsRatioCu3[10] = {};

    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_ratio->Draw();
        line1.Draw();

        grKsRatioSP1[c] = getRatio( grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP_SubEvt,   grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP );
        grKsRatioSP2[c] = getRatio( grSP.grSP_Ks_Sig[c]->vn_PosEta_NegEtaEP,        grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP );
        grKsRatioSP3[c] = getRatio( grSP.grSP_Ks_Sig[c]->vn_PosEta_NegEtaEP_SubEvt, grSP.grSP_Ks_Sig[c]->vn_Full_NegEtaEP );

//        grKsRatioCu2[c] = getRatio( grKs.gr_v24subpos[c], grKs.gr_v24[c] );
//        grKsRatioCu3[c] = getRatio( grKs.gr_v24subneg[c], grKs.gr_v24[c] );

        setGr( grKsRatioSP1[c], kOpenCircle, kRed, 2.);
        setGr( grKsRatioSP2[c], kOpenCircle, kBlack, 2.);
        setGr( grKsRatioSP3[c], kOpenCircle, kGreen+2, 2.);

        setGr( grKsRatioCu1[c], kOpenSquare, kRed, 2.);
//        setGr( grKsRatioCu2[c], kOpenSquare, kBlack, 2.);
//        setGr( grKsRatioCu3[c], kOpenSquare, kGreen+2, 2.);

//        grKsRatioSP1[c]->Draw("psame");
//        grKsRatioSP2[c]->Draw("psame");
//        grKsRatioSP3[c]->Draw("psame");

        grKsRatioCu1[c]->Draw("psame");
//        grKsRatioCu2[c]->Draw("psame");
//        grKsRatioCu3[c]->Draw("psame");
        s2f.WriteGr( grKsRatioCu1[c], Form( "grKs_v24subRatio_%i", c ) );
    }
    cpPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{K_{S}^{0}}");
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

    legKsRatio1->AddEntry( grKsRatioCu1[6], "v_{2}{4,Sub}/v_{2}{4} |y|<1.", "p" );
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
        line0.Draw();

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
        s2f.WriteGr( grLm.gr_v24sub[c], Form( "grLm_v24sub_%i", c ) );
        s2f.WriteGr( grLm.grSys_v24sub[c], Form( "grSysLm_v24sub_%i", c ) );
    }
    cpPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{#Lambda}");
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

//    TGraphErrors* grLmRatioCu2[10] = {};
//    TGraphErrors* grLmRatioCu3[10] = {};

    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_ratio->Draw();
        line1.Draw();

        grLmRatioSP1[c] = getRatio( grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP_SubEvt,   grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP );
        grLmRatioSP2[c] = getRatio( grSP.grSP_Lm_Sig[c]->vn_PosEta_NegEtaEP,        grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP );
        grLmRatioSP3[c] = getRatio( grSP.grSP_Lm_Sig[c]->vn_PosEta_NegEtaEP_SubEvt, grSP.grSP_Lm_Sig[c]->vn_Full_NegEtaEP );

//        grLmRatioCu2[c] = getRatio( grLm.gr_v24subpos[c], grLm.gr_v24[c] );
//        grLmRatioCu3[c] = getRatio( grLm.gr_v24subneg[c], grLm.gr_v24[c] );

        setGr( grLmRatioSP1[c], kOpenCircle, kRed, 2.);
        setGr( grLmRatioSP2[c], kOpenCircle, kBlack, 2.);
        setGr( grLmRatioSP3[c], kOpenCircle, kGreen+2, 2.);

        setGr( grLmRatioCu1[c], kOpenSquare, kRed, 2.);
//        setGr( grLmRatioCu2[c], kOpenSquare, kBlack, 2.);
//        setGr( grLmRatioCu3[c], kOpenSquare, kGreen+2, 2.);

//        grLmRatioSP1[c]->Draw("psame");
//        grLmRatioSP2[c]->Draw("psame");
//        grLmRatioSP3[c]->Draw("psame");

        grLmRatioCu1[c]->Draw("psame");
//        grLmRatioCu2[c]->Draw("psame");
//        grLmRatioCu3[c]->Draw("psame");
        s2f.WriteGr( grLmRatioCu1[c], Form( "grLm_v24subRatio_%i", c ) );
    }
    cpPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{#Lambda}");
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

    legLmRatio1->AddEntry( grLmRatioCu1[6], "v_{2}{4,Sub}/v_{2}{4} |y|<1.", "p" );
//    legLmRatio1->AddEntry( grLmRatioCu2[6], "v_{2}{4,Sub} 0.<#eta<1.", "p" );
//    legLmRatio1->AddEntry( grLmRatioCu3[6], "v_{2}{4,Sub} -1.<#eta<0.", "p" );

    legLmRatio1->Draw();

    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);

    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);

    cpPbV2->SaveAs("pPbV2_Ratio_Lm.pdf");

    // veto only for Ch
    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_pt->Draw();
        line0.Draw();

        setGr( grH.gr_v22Gap [c]    , kOpenCircle, kBlue, 2. );
        setGr( grHveto.gr_v22Gap [c], kFullCircle, kRed,  2. );

        setGr( grH.gr_v24    [c], kOpenCircle, kRed, 2. );
        setGr( grHveto.gr_v24[c], kFullCircle, kRed, 2. );

        setGr( grH.gr_v26    [c], kOpenStar, kBlue, 2. );
        setGr( grHveto.gr_v26[c], kFullStar, kBlue,  2. );

        grHveto.grSys_v24[c]->SetFillColor(3001);
        grHveto.grSys_v26[c]->SetFillColor(3003);
        grH    .grSys_v24[c]->SetFillColor(3001);
        grH    .grSys_v26[c]->SetFillColor(3003);

        grHveto.grSys_v24[c]->Draw("[]2");
        grHveto.grSys_v26[c]->Draw("[]2");
        grH    .grSys_v24[c]->Draw("[]2");
        grH    .grSys_v26[c]->Draw("[]2");

        grHveto.gr_v24[c]->Draw("psame");
        grHveto.gr_v26[c]->Draw("psame");
        grH    .gr_v24[c]->Draw("psame");
        grH    .gr_v26[c]->Draw("psame");

        s2f.WriteGr( grHveto.gr_v22Gap[c], Form( "grCh_v22Gapveto_%i", c ) );
        s2f.WriteGr( grHveto.gr_v24[c], Form( "grCh_v24veto_%i", c ) );
        s2f.WriteGr( grHveto.gr_v26[c], Form( "grCh_v26veto_%i", c ) );
    }
    cpPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{Charge hadron}");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);
    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);

    TLegend * legChVeto = new TLegend(0.45, 0.58, 0.90, 0.92);
    legChVeto->SetFillColor(kWhite);
    legChVeto->SetTextFont(42);
    legChVeto->SetTextSize(0.05);
    legChVeto->SetBorderSize(0);

//    legChVeto->AddEntry( grH.gr_v22Gap[6], "v_{2}{2,|#Delta#eta|>2.}", "p" );
    legChVeto->AddEntry( grH.gr_v24[6], "v_{2}{4}", "p" );
    legChVeto->AddEntry( grH.gr_v26[6], "v_{2}{6}", "p" );
//    legChVeto->AddEntry( grHveto.gr_v22Gap[6], "v_{2}{2, veto,|#Delta#eta|>2.}", "p" );
    legChVeto->AddEntry( grHveto.gr_v24[6], "v_{2}{4,veto}", "p" );
    legChVeto->AddEntry( grHveto.gr_v26[6], "v_{2}{6,veto}", "p" );


    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);
    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);
    legChVeto->Draw();

    cpPbV2->SaveAs("pPbV2_Ch_veto.pdf");

    // veto for Ks
    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_pt->Draw();

        setGr( grKs.gr_v22Gap [c]    , kOpenCircle, kBlue, 2. );
        setGr( grKsveto.gr_v22Gap [c], kFullCircle, kRed,  2. );

        setGr( grKs.gr_v24    [c], kOpenCircle, kBlue, 2. );
        setGr( grKsveto.gr_v24[c], kFullCircle, kRed,  2. );

        setGr( grKs.gr_v26    [c], kOpenStar, kBlue, 2. );
        setGr( grKsveto.gr_v26[c], kFullStar, kRed,  2. );

        grKsveto.grSys_v24[c]->SetFillColor(3001);
        grKsveto.grSys_v26[c]->SetFillColor(3001);
        grKs    .grSys_v24[c]->SetFillColor(3003);
        grKs    .grSys_v26[c]->SetFillColor(3003);

        grKsveto.grSys_v24[c]->Draw("[]2");
        grKsveto.grSys_v26[c]->Draw("[]2");
        grKs    .grSys_v24[c]->Draw("[]2");
        grKs    .grSys_v26[c]->Draw("[]2");

        grKsveto.gr_v24[c]->Draw("psame");
        grKsveto.gr_v26[c]->Draw("psame");
        grKs    .gr_v24[c]->Draw("psame");
        grKs    .gr_v26[c]->Draw("psame");

        s2f.WriteGr( grKsveto.gr_v22Gap[c], Form( "grKs_v22Gapveto_%i", c ) );
        s2f.WriteGr( grKsveto.gr_v24[c], Form( "grKs_v24veto_%i", c ) );
        s2f.WriteGr( grKsveto.gr_v26[c], Form( "grKs_v26veto_%i", c ) );
    }

    cpPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{K_{S}^{0}}");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);
    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);

    TLegend * legKsVeto = new TLegend(0.45, 0.58, 0.90, 0.92);
    legKsVeto->SetFillColor(kWhite);
    legKsVeto->SetTextFont(42);
    legKsVeto->SetTextSize(0.05);
    legKsVeto->SetBorderSize(0);

    legKsVeto->AddEntry( grKs.gr_v24[6], "v_{2}{4}", "p" );
    legKsVeto->AddEntry( grKs.gr_v26[6], "v_{2}{6}", "p" );
    legKsVeto->AddEntry( grKsveto.gr_v24[6], "v_{2}{4,veto}", "p" );
    legKsVeto->AddEntry( grKsveto.gr_v26[6], "v_{2}{6,veto}", "p" );

    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);
    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);
    legKsVeto->Draw();

    cpPbV2->SaveAs("pPbV2_Ks_veto.pdf");

    // veto for Lm
    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_pt->Draw();

        setGr( grLm.gr_v22Gap [c]    , kOpenCircle, kBlue, 2. );
        setGr( grLmveto.gr_v22Gap [c], kFullCircle, kRed,  2. );

        setGr( grLm.gr_v24    [c], kOpenCircle, kBlue, 2. );
        setGr( grLmveto.gr_v24[c], kFullCircle, kRed,  2. );
        setGr( grLm.gr_v26    [c], kOpenStar, kBlue, 2. );
        setGr( grLmveto.gr_v26[c], kFullStar, kRed,  2. );

        grLmveto.grSys_v24[c]->SetFillColor(3001);
        grLmveto.grSys_v26[c]->SetFillColor(3001);
        grLm    .grSys_v24[c]->SetFillColor(3003);
        grLm    .grSys_v26[c]->SetFillColor(3003);

        grLmveto.grSys_v24[c]->Draw("[]2");
        grLmveto.grSys_v26[c]->Draw("[]2");
        grLm    .grSys_v24[c]->Draw("[]2");
        grLm    .grSys_v26[c]->Draw("[]2");


        grLmveto.gr_v24[c]->Draw("psame");
        grLmveto.gr_v26[c]->Draw("psame");
        grLm    .gr_v24[c]->Draw("psame");
        grLm    .gr_v26[c]->Draw("psame");

        s2f.WriteGr( grLmveto.gr_v22Gap[c], Form( "grLm_v22Gapveto_%i", c ) );
        s2f.WriteGr( grLmveto.gr_v24[c], Form( "grLm_v24veto_%i", c ) );
        s2f.WriteGr( grLmveto.gr_v26[c], Form( "grLm_v26veto_%i", c ) );
    }

    cpPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{#Lambda}");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);
    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);

    TLegend * legLmVeto = new TLegend(0.45, 0.58, 0.90, 0.92);
    legLmVeto->SetFillColor(kWhite);
    legLmVeto->SetTextFont(42);
    legLmVeto->SetTextSize(0.05);
    legLmVeto->SetBorderSize(0);

    legLmVeto->AddEntry( grLm.gr_v24[6], "v_{2}{4}", "p" );
    legLmVeto->AddEntry( grLm.gr_v26[6], "v_{2}{6}", "p" );
    legLmVeto->AddEntry( grLmveto.gr_v24[6], "v_{2}{4,veto}", "p" );
    legLmVeto->AddEntry( grLmveto.gr_v26[6], "v_{2}{6,veto}", "p" );

    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);
    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);
    legLmVeto->Draw();

    cpPbV2->SaveAs("pPbV2_Lm_veto.pdf");

    // veto ratio only for Ch
    TH2D * hframe_ratioVeto = new TH2D("hframe_ratioVeto", "hframe_ratioVeto", 1, 0.01, 8.5, 1, 0.05, 3.95);
    InitHist(hframe_ratioVeto, "p_{T} (GeV)", "Ratio");
    hframe_ratioVeto->GetYaxis()->SetTitleOffset(1.0);
    hframe_ratioVeto->GetXaxis()->SetTitleOffset(0.90);

    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_ratioVeto->Draw();
        line1.Draw();


        setGr( grChRatioVeto2[c], kOpenCircle, kBlack, 2. );
        setGr( grChRatioVeto4[c], kOpenCircle, kRed, 2. );
        setGr( grChRatioVeto6[c], kOpenStar, kBlue, 2. );

        grChRatioVeto4_sys[c]->SetFillColor(3001);
        grChRatioVeto6_sys[c]->SetFillColor(3003);

        grChRatioVeto4_sys[c]->Draw("[]2");
        grChRatioVeto6_sys[c]->Draw("[]2");

//        grChRatioVeto2[c]->Draw("plsame");
        grChRatioVeto4[c]->Draw("plsame");
        grChRatioVeto6[c]->Draw("plsame");

        s2f.WriteGr( grChRatioVeto4_sys[c], Form( "grCh_v24vetoRatioSys_%i", c ) );
        s2f.WriteGr( grChRatioVeto6_sys[c], Form( "grCh_v26vetoRatioSys_%i", c ) );
        s2f.WriteGr( grChRatioVeto4[c], Form( "grCh_v24vetoRatio_%i", c ) );
        s2f.WriteGr( grChRatioVeto6[c], Form( "grCh_v26vetoRatio_%i", c ) );
    }
    cpPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{Charge hadron}");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);

    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);

    TLegend * legChVetoRatio = new TLegend(0.05, 0.6, 0.45, 0.82);
    legChVetoRatio->SetFillColor(kWhite);
    legChVetoRatio->SetTextFont(42);
    legChVetoRatio->SetTextSize(0.05);
    legChVetoRatio->SetBorderSize(0);

//    legChVetoRatio->AddEntry( grChRatioVeto2[6], "v_{2}{2,veto}/v_{2}{2}", "p" );
    legChVetoRatio->AddEntry( grChRatioVeto4[6], "v_{2}{4,veto}/v_{2}{4}", "p" );
    legChVetoRatio->AddEntry( grChRatioVeto6[6], "v_{2}{6,veto}/v_{2}{6}", "p" );

    legChVetoRatio->Draw();

    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);

    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);

    cpPbV2->SaveAs("pPbV2_Ch_vetoRatio.pdf");


    // veto delta only for Ch
    TH2D * hframe_pt_deltaVeto = new TH2D("hframe_pt_deltaVeto", "hframe_pt_deltaVeto", 1, 0.01, 8.5, 1, -0.09, 0.19);
    InitHist(hframe_pt_deltaVeto, "p_{T} (GeV)", "#Deltav_{2}");
    hframe_pt_deltaVeto->GetYaxis()->SetTitleOffset(1.0);
    hframe_pt_deltaVeto->GetXaxis()->SetTitleOffset(0.90);

    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_pt_deltaVeto->Draw();
        line0.Draw();

        setGr( grChVetoDelta4[c], kOpenCircle, kRed,  2. );
        setGr( grChVetoDelta6[c], kOpenStar,   kBlue, 2. );

        grChVetoDelta4_sys[c]->SetFillColor(3001);
        grChVetoDelta6_sys[c]->SetFillColor(3003);

        grChVetoDelta4_sys[c]->Draw("[]2");
        grChVetoDelta6_sys[c]->Draw("[]2");
        grChVetoDelta4[c]->Draw("psame");
        grChVetoDelta6[c]->Draw("psame");
    }
    cpPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{Charge hadron}");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);

    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);

    TLegend * legChVetoDelta = new TLegend(0.05, 0.6, 0.45, 0.82);
    legChVetoDelta->SetFillColor(kWhite);
    legChVetoDelta->SetTextFont(42);
    legChVetoDelta->SetTextSize(0.05);
    legChVetoDelta->SetBorderSize(0);

    legChVetoDelta->AddEntry( grChRatioVeto4[6], "v_{2}{4,veto} - v_{2}{4}", "p" );
    legChVetoDelta->AddEntry( grChRatioVeto6[6], "v_{2}{6,veto} - v_{2}{6}", "p" );
    legChVetoDelta->Draw();

    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);

    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);

    cpPbV2->SaveAs("pPbV2_Ch_vetoDelta.pdf");

    // veto ratio only for Ks
    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_ratioVeto->Draw();
        line1.Draw();

        setGr( grKsRatioVeto2[c], kOpenCircle, kBlack, 2. );
        setGr( grKsRatioVeto4[c], kOpenSquare, kRed, 2. );
        setGr( grKsRatioVeto6[c], kOpenStar, kBlue, 2. );

        grKsRatioVeto4_sys[c]->SetFillColor(3001);
        grKsRatioVeto6_sys[c]->SetFillColor(3003);

        grKsRatioVeto4_sys[c]->Draw("[]2");
        grKsRatioVeto6_sys[c]->Draw("[]2");

        grKsRatioVeto4[c]->Draw("plsame");
        grKsRatioVeto6[c]->Draw("plsame");

        s2f.WriteGr( grKsRatioVeto4_sys[c], Form( "grKs_v24vetoRatioSys_%i", c ) );
        s2f.WriteGr( grKsRatioVeto6_sys[c], Form( "grKs_v26vetoRatioSys_%i", c ) );
        s2f.WriteGr( grKsRatioVeto4[c], Form( "grKs_v24vetoRatio_%i", c ) );
        s2f.WriteGr( grKsRatioVeto6[c], Form( "grKs_v26vetoRatio_%i", c ) );
    }
    cpPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{K_{S}^{0}}");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);

    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);

    TLegend * legKsVetoRatio = new TLegend(0.05, 0.6, 0.45, 0.82);
    legKsVetoRatio->SetFillColor(kWhite);
    legKsVetoRatio->SetTextFont(42);
    legKsVetoRatio->SetTextSize(0.05);
    legKsVetoRatio->SetBorderSize(0);

    legKsVetoRatio->AddEntry( grKsRatioVeto4[6], "v_{2}{4,veto}/v_{2}{4}", "p" );
    legKsVetoRatio->AddEntry( grKsRatioVeto6[6], "v_{2}{6,veto}/v_{2}{6}", "p" );

    legKsVetoRatio->Draw();

    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);

    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);

    cpPbV2->SaveAs("pPbV2_Ks_vetoRatio.pdf");

    // veto ratio only for Lm
    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_ratioVeto->Draw();
        line1.Draw();

        setGr( grLmRatioVeto2[c], kOpenCircle, kBlack, 2. );
        setGr( grLmRatioVeto4[c], kOpenSquare, kRed, 2. );
        setGr( grLmRatioVeto6[c], kOpenStar, kBlue, 2. );

        grLmRatioVeto4_sys[c]->SetFillColor(3001);
        grLmRatioVeto6_sys[c]->SetFillColor(3003);

        grLmRatioVeto4_sys[c]->Draw("[]2");
        grLmRatioVeto6_sys[c]->Draw("[]2");

        grLmRatioVeto4[c]->Draw("plsame");
        grLmRatioVeto6[c]->Draw("plsame");

        s2f.WriteGr( grLmRatioVeto4_sys[c], Form( "grLm_v24vetoRatioSys_%i", c ) );
        s2f.WriteGr( grLmRatioVeto6_sys[c], Form( "grLm_v26vetoRatioSys_%i", c ) );
        s2f.WriteGr( grLmRatioVeto4[c], Form( "grLm_v24vetoRatio_%i", c ) );
        s2f.WriteGr( grLmRatioVeto6[c], Form( "grLm_v26vetoRatio_%i", c ) );
    }
    cpPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{#Lambda}");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);

    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);

    TLegend * legLmVetoRatio = new TLegend(0.05, 0.6, 0.45, 0.82);
    legLmVetoRatio->SetFillColor(kWhite);
    legLmVetoRatio->SetTextFont(42);
    legLmVetoRatio->SetTextSize(0.05);
    legLmVetoRatio->SetBorderSize(0);

    legLmVetoRatio->AddEntry( grLmRatioVeto4[6], "v_{2}{4,veto}/v_{2}{4}", "p" );
    legLmVetoRatio->AddEntry( grLmRatioVeto6[6], "v_{2}{6,veto}/v_{2}{6}", "p" );

    legLmVetoRatio->Draw();

    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);

    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);

    cpPbV2->SaveAs("pPbV2_Lm_vetoRatio.pdf");

    // subevent pos neg
    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_pt->Draw();

        setGr( grH.gr_v24sub   [c], kOpenCircle, kBlack, 2. );
        setGr( grH.gr_v24subneg[c], kOpenCircle, kRed,   2. );
        setGr( grH.gr_v24subpos[c], kOpenCircle, kBlue,  2. );

        grH.gr_v24sub   [c]->Draw("psame");
        grH.gr_v24subneg[c]->Draw("psame");
        grH.gr_v24subpos[c]->Draw("psame");
    }
    cpPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{Charge hadron}");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);
    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);

    TLegend * legChPosNeg = new TLegend(0.05, 0.6, 0.45, 0.82);
    legChPosNeg->SetFillColor(kWhite);
    legChPosNeg->SetTextFont(42);
    legChPosNeg->SetTextSize(0.05);
    legChPosNeg->SetBorderSize(0);

    legChPosNeg->AddEntry( grH.gr_v24sub[6], "v_{2}{4,Sub}", "p" );
    legChPosNeg->AddEntry( grH.gr_v24subpos[6], "v_{2}{4,p-Sub}", "p" );
    legChPosNeg->AddEntry( grH.gr_v24subneg[6], "v_{2}{4,Pb-Sub}", "p" );

    legChPosNeg->Draw();

    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);
    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);

    cpPbV2->SaveAs("pPbV2_Subevt_Ch_PosNeg.pdf");

    // subevent pos neg ratio
    TH2D * hframe_ratioPosNeg = new TH2D("hframe_ratioPosNeg", "hframe_ratioPosNeg", 1, 0.01, 8.5, 1, 0.05, 1.95);
    InitHist(hframe_ratioPosNeg, "p_{T} (GeV)", "Ratio");
    hframe_ratioPosNeg->GetYaxis()->SetTitleOffset(1.0);
    hframe_ratioPosNeg->GetXaxis()->SetTitleOffset(0.90);

    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_ratioPosNeg->Draw();
        line1.Draw();

        setGr( grChRatioPos[c], kOpenCircle, kBlue, 2. );
        setGr( grChRatioNeg[c], kOpenCircle, kRed,  2. );

        grChRatioPos[c]->Draw("psame");
        grChRatioNeg[c]->Draw("psame");
    }
    cpPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{Charge hadron}");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);
    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);

    TLegend * legChPosNegRatio = new TLegend(0.05, 0.65, 0.45, 0.82);
    legChPosNegRatio->SetFillColor(kWhite);
    legChPosNegRatio->SetTextFont(42);
    legChPosNegRatio->SetTextSize(0.05);
    legChPosNegRatio->SetBorderSize(0);

    legChPosNegRatio->AddEntry( grChRatioPos[6], "v_{2}{4,p-Sub}/v_{2}{4,Sub}", "p" );
    legChPosNegRatio->AddEntry( grChRatioNeg[6], "v_{2}{4,Pb-Sub}/v_{2}{4,Sub}", "p" );

    legChPosNegRatio->Draw();

    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);
    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);

    cpPbV2->SaveAs("pPbV2_Subevt_Ch_RatioPosNeg.pdf");

    // subevent veto pos neg
    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_pt->Draw();

        setGr( grHveto.gr_v24sub   [c], kOpenSquare, kBlack, 2. );
        setGr( grHveto.gr_v24subneg[c], kOpenSquare, kRed,   2. );
        setGr( grHveto.gr_v24subpos[c], kOpenSquare, kBlue,  2. );

        grHveto.gr_v24sub   [c]->Draw("psame");
        grHveto.gr_v24subneg[c]->Draw("psame");
        grHveto.gr_v24subpos[c]->Draw("psame");
    }
    cpPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{Charge hadron}");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);
    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);

    TLegend * legChVetoPosNeg = new TLegend(0.05, 0.6, 0.45, 0.82);
    legChVetoPosNeg->SetFillColor(kWhite);
    legChVetoPosNeg->SetTextFont(42);
    legChVetoPosNeg->SetTextSize(0.05);
    legChVetoPosNeg->SetBorderSize(0);

    legChVetoPosNeg->AddEntry( grHveto.gr_v24sub[6], "v_{2}{4,Sub}", "p" );
    legChVetoPosNeg->AddEntry( grHveto.gr_v24subpos[6], "v_{2}{4,p-Sub}", "p" );
    legChVetoPosNeg->AddEntry( grHveto.gr_v24subneg[6], "v_{2}{4,Pb-Sub}", "p" );

    legChVetoPosNeg->Draw();

    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);
    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);

    cpPbV2->SaveAs("pPbV2_Subevt_ChVeto_PosNeg.pdf");

    // subevent veto pos neg ratio
    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_ratioPosNeg->Draw();
        line1.Draw();

        setGr( grChVetoRatioPos[c], kOpenSquare, kBlue, 2. );
        setGr( grChVetoRatioNeg[c], kOpenSquare, kRed,  2. );

        grChVetoRatioPos[c]->Draw("psame");
        grChVetoRatioNeg[c]->Draw("psame");
    }
    cpPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{Charge hadron}");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);
    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);

    TLegend * legChVetoPosNegRatio = new TLegend(0.05, 0.65, 0.45, 0.82);
    legChVetoPosNegRatio->SetFillColor(kWhite);
    legChVetoPosNegRatio->SetTextFont(42);
    legChVetoPosNegRatio->SetTextSize(0.05);
    legChVetoPosNegRatio->SetBorderSize(0);

    legChVetoPosNegRatio->AddEntry( grChRatioPos[6], "v_{2}{4,p-Sub}/v_{2}{4,Sub} veto", "p" );
    legChVetoPosNegRatio->AddEntry( grChRatioNeg[6], "v_{2}{4,Pb-Sub}/v_{2}{4,Sub} veto", "p" );

    legChVetoPosNegRatio->Draw();

    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);
    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);

    cpPbV2->SaveAs("pPbV2_Subevt_ChVeto_RatioPosNeg.pdf");

    // sub veto
    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_pt->Draw();

        setGr( grH    .gr_v24   [c], kOpenCircle, kBlue, 2. );
        setGr( grHveto.gr_v24   [c], kFullCircle, kRed,  2. );
        setGr( grH    .gr_v24sub[c], kOpenSquare, kBlue, 2. );
        setGr( grHveto.gr_v24sub[c], kFullSquare, kRed,  2. );

        grHveto.gr_v24   [c]->Draw("psame");
        grHveto.gr_v24sub[c]->Draw("psame");
        grH    .gr_v24   [c]->Draw("psame");
        grH    .gr_v24sub[c]->Draw("psame");
    }
    cpPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{Charge hadron}");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);
    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);

    TLegend * legChSubVeto = new TLegend(0.05, 0.55, 0.45, 0.82);
    legChSubVeto->SetFillColor(kWhite);
    legChSubVeto->SetTextFont(42);
    legChSubVeto->SetTextSize(0.05);
    legChSubVeto->SetBorderSize(0);

    legChSubVeto->AddEntry( grH    .gr_v24   [6], "v_{2}{4}", "p" );
    legChSubVeto->AddEntry( grH    .gr_v24sub[6], "v_{2}{4,Sub}", "p" );
    legChSubVeto->AddEntry( grHveto.gr_v24   [6], "v_{2}{4,veto}", "p" );
    legChSubVeto->AddEntry( grHveto.gr_v24sub[6], "v_{2}{4,Sub,veto}", "p" );

    legChSubVeto->Draw();

    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);
    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);

    cpPbV2->SaveAs("pPbV2_ChSub_veto.pdf");

    // sub veto ratio
    TGraphErrors * grChVetoSubRatio[10] = {};
    for ( int c = 6; c < 10; c++ ) {
        cpPbV2->cd(c-5);
        hframe_ratioVeto->Draw();
        line1.Draw();

        grChVetoSubRatio[c] = getRatio( grHveto.gr_v24sub[c], grH.gr_v24[c], 3 );

        setGr( grChRatioVeto4  [c], kOpenCircle, kRed,  2. );
        setGr( grChRatioCu1    [c], kOpenSquare, kBlue, 2. );
        setGr( grChVetoSubRatio[c], kOpenSquare, kRed,  2. );

        grChVetoSubRatio[c]->Draw("psame");
        grChRatioCu1  [c]->Draw("psame");
        grChRatioVeto4[c]->Draw("psame");
    }
    cpPbV2->cd(1);
    if ( bPre ) {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS #it{Preliminary}}");
    } else {
        latexS.DrawLatexNDC(0.12, 0.99, "#bf{CMS}");
    }
    latexS.DrawLatexNDC(0.16, 0.80, "#bf{Charge hadron}");
    latexS.DrawLatexNDC(0.16, 0.90, strNoff[6]);
    cpPbV2->cd(2);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[7]);

    TLegend * legChSubVetoRatio = new TLegend(0.05, 0.60, 0.45, 0.82);
    legChSubVetoRatio->SetFillColor(kWhite);
    legChSubVetoRatio->SetTextFont(42);
    legChSubVetoRatio->SetTextSize(0.05);
    legChSubVetoRatio->SetBorderSize(0);

    legChSubVetoRatio->AddEntry( grChRatioVeto4  [6], "v_{2}{4,veto}/v_{2}{4}", "p" );
    legChSubVetoRatio->AddEntry( grChRatioCu1    [6], "v_{2}{4,Sub}/v_{2}{4}", "p" );
    legChSubVetoRatio->AddEntry( grChVetoSubRatio[6], "v_{2}{4,Sub,veto}/v_{2}{4}", "p" );

    legChSubVetoRatio->Draw();

    cpPbV2->cd(3);
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[8]);
    cpPbV2->cd(4);
    latexS.DrawLatexNDC(0.55, 0.99, "pPb 8.16 TeV");
    latexS.DrawLatexNDC(0.08, 0.90, strNoff[9]);

    cpPbV2->SaveAs("pPbV2_ChSub_veto_ratio.pdf");
}
