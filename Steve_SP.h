
#include "noff.h"

// syst
// 0 -- H   1.4
// 1 -- Ks  3.5
// 2 -- Lm  5.7
const double sp_syst[3] = {0.014, 0.035, 0.057};

typedef struct SteveGraph
{
    TGraphErrors* vn_NegEta = 0;
    TGraphErrors* vn_NegEta_SubEvt = 0;
    TGraphErrors* vn_PosEta = 0;
    TGraphErrors* vn_PosEta_SubEvt = 0;

    TGraphErrors* vn_MergedEta = 0;
    TGraphErrors* vn_MergedEta_SubEvt = 0;

    SteveGraph() {
    };

    SteveGraph(TDirectoryFile * dir) {
        vn_NegEta       = (TGraphErrors*) dir->Get("vn_NegEta");
        vn_NegEta_SubEvt= (TGraphErrors*) dir->Get("vn_NegEta_SubEvt");
        vn_PosEta       = (TGraphErrors*) dir->Get("vn_PosEta");
        vn_PosEta_SubEvt= (TGraphErrors*) dir->Get("vn_PosEta_SubEvt");

        vn_MergedEta    = (TGraphErrors*) dir->Get("vn_MergedEta");
        vn_MergedEta_SubEvt = (TGraphErrors*) dir->Get("vn_MergedEta_SubEvt");

        if ( vn_MergedEta == nullptr ) vn_MergedEta    = merge( vn_NegEta, vn_PosEta );
        if ( vn_MergedEta_SubEvt == nullptr ) vn_MergedEta_SubEvt = merge( vn_NegEta_SubEvt, vn_PosEta_SubEvt );
    };

    SteveGraph( SteveGraph* a, SteveGraph* b ) {
        vn_NegEta       = merge( a->vn_NegEta       , b->vn_NegEta          );
        vn_NegEta_SubEvt= merge( a->vn_NegEta_SubEvt, b->vn_NegEta_SubEvt   );
        vn_PosEta       = merge( a->vn_PosEta       , b->vn_PosEta          );
        vn_PosEta_SubEvt= merge( a->vn_PosEta_SubEvt, b->vn_PosEta_SubEvt   );
        vn_MergedEta    = merge( a->vn_MergedEta    , b->vn_MergedEta       );
        vn_MergedEta_SubEvt= merge( a->vn_MergedEta_SubEvt, b->vn_MergedEta_SubEvt);
    };

    SteveGraph( SteveGraph* a, double sys ) {
        vn_NegEta           = getSys( a->vn_NegEta          , sys );
        vn_NegEta_SubEvt    = getSys( a->vn_NegEta_SubEvt   , sys );
        vn_PosEta           = getSys( a->vn_PosEta          , sys );
        vn_PosEta_SubEvt    = getSys( a->vn_PosEta_SubEvt   , sys );
        vn_MergedEta        = getSys( a->vn_MergedEta       , sys );
        vn_MergedEta_SubEvt = getSys( a->vn_MergedEta_SubEvt, sys );
    };

    void Write(TDirectory* dir) {
        dir->cd();
        vn_NegEta       ->Write( "vn_NegEta" );
        vn_NegEta_SubEvt->Write( "vn_NegEta_SubEvt" );
        vn_PosEta       ->Write( "vn_PosEta" );
        vn_PosEta_SubEvt->Write( "vn_PosEta_SubEvt" );
        vn_MergedEta    ->Write( "vn_MergedEta" );
        vn_MergedEta_SubEvt->Write( "vn_MergedEta_SubEvt" );
    };

    void ResetX() {
        for ( int i = 0; i < 13; i++ ) {
            vn_NegEta       ->GetX()[i]        = pTX[i];
            vn_NegEta_SubEvt->GetX()[i]        = pTX[i];
            vn_PosEta       ->GetX()[i]        = pTX[i];
            vn_PosEta_SubEvt->GetX()[i]        = pTX[i];
            vn_MergedEta    ->GetX()[i]        = pTX[i];
            vn_MergedEta_SubEvt->GetX()[i]     = pTX[i];
        }
    };

    void dropPoints( int N ) {
        for ( int i = 0; i < N; i++ ) {
            vn_NegEta       ->RemovePoint(0);
            vn_NegEta_SubEvt->RemovePoint(0);
            vn_PosEta       ->RemovePoint(0);
            vn_PosEta_SubEvt->RemovePoint(0);
            vn_MergedEta        ->RemovePoint(0);
            vn_MergedEta_SubEvt ->RemovePoint(0);
        }
    };

private:
    TGraphErrors* merge(TGraphErrors* gr1, TGraphErrors* gr2){
        int N = gr1->GetN();
        TGraphErrors * gr = new TGraphErrors(N);

        for ( int i = 0; i < N; i++ ) {
            gr->GetX()[i] = gr1->GetX()[i];
            double y1 = gr1->GetY()[i];
            double y2 = gr2->GetY()[i];
            double e1 = gr1->GetEY()[i];
            double e2 = gr2->GetEY()[i];

            gr->GetY()[i] = (y1/e1/e1 + y2/e2/e2) / (1./e1/e1 + 1./e2/e2);
            gr->GetEY()[i] = sqrt(1./e1/e1 + 1./e2/e2) / (1./e1/e1 + 1./e2/e2);
        }
        return gr;
    }

    TGraphErrors* getSys(TGraphErrors* gr, double sys)
    {
        int N = gr->GetN();
        TGraphErrors* g = new TGraphErrors(N);

        for ( int i = 0; i < N; i++ ) {
            g->GetX()[i] = gr->GetX()[i];
            g->GetY()[i] = gr->GetY()[i];
            g->GetEY()[i] = gr->GetY()[i] * sys;
            g->GetEX()[i] = 0.15;
        }
        return g;
    };
} SteveGraph;

SteveGraph* ch_v2_PbPb_0_10;
SteveGraph* ch_v2_PbPb_10_30;
SteveGraph* ch_v2_PbPb_30_50;
SteveGraph* ch_v2_PbPb_50_80;
SteveGraph* Ks_v2_PbPb_0_10;
SteveGraph* Ks_v2_PbPb_10_30;
SteveGraph* Ks_v2_PbPb_30_50;
SteveGraph* Ks_v2_PbPb_50_80;
SteveGraph* Lm_v2_PbPb_0_10;
SteveGraph* Lm_v2_PbPb_10_30;
SteveGraph* Lm_v2_PbPb_30_50;
SteveGraph* Lm_v2_PbPb_50_80;
SteveGraph* Ks_SBPos_v2_PbPb_0_10;
SteveGraph* Ks_SBPos_v2_PbPb_10_30;
SteveGraph* Ks_SBPos_v2_PbPb_30_50;
SteveGraph* Ks_SBPos_v2_PbPb_50_80;
SteveGraph* Ks_SBNeg_v2_PbPb_0_10;
SteveGraph* Ks_SBNeg_v2_PbPb_10_30;
SteveGraph* Ks_SBNeg_v2_PbPb_30_50;
SteveGraph* Ks_SBNeg_v2_PbPb_50_80;
SteveGraph* Lm_SBPos_v2_PbPb_0_10;
SteveGraph* Lm_SBPos_v2_PbPb_10_30;
SteveGraph* Lm_SBPos_v2_PbPb_30_50;
SteveGraph* Lm_SBPos_v2_PbPb_50_80;
SteveGraph* Lm_SBNeg_v2_PbPb_0_10;
SteveGraph* Lm_SBNeg_v2_PbPb_10_30;
SteveGraph* Lm_SBNeg_v2_PbPb_30_50;
SteveGraph* Lm_SBNeg_v2_PbPb_50_80;

SteveGraph* Ks_SB_v2_PbPb_0_10;
SteveGraph* Ks_SB_v2_PbPb_10_30;
SteveGraph* Ks_SB_v2_PbPb_30_50;
SteveGraph* Ks_SB_v2_PbPb_50_80;
SteveGraph* Lm_SB_v2_PbPb_0_10;
SteveGraph* Lm_SB_v2_PbPb_10_30;
SteveGraph* Lm_SB_v2_PbPb_30_50;
SteveGraph* Lm_SB_v2_PbPb_50_80;

SteveGraph* ch_v3_PbPb_0_10;
SteveGraph* ch_v3_PbPb_10_30;
SteveGraph* ch_v3_PbPb_30_50;
SteveGraph* ch_v3_PbPb_50_80;
SteveGraph* Ks_v3_PbPb_0_10;
SteveGraph* Ks_v3_PbPb_10_30;
SteveGraph* Ks_v3_PbPb_30_50;
SteveGraph* Ks_v3_PbPb_50_80;
SteveGraph* Lm_v3_PbPb_0_10;
SteveGraph* Lm_v3_PbPb_10_30;
SteveGraph* Lm_v3_PbPb_30_50;
SteveGraph* Lm_v3_PbPb_50_80;
SteveGraph* Ks_SBPos_v3_PbPb_0_10;
SteveGraph* Ks_SBPos_v3_PbPb_10_30;
SteveGraph* Ks_SBPos_v3_PbPb_30_50;
SteveGraph* Ks_SBPos_v3_PbPb_50_80;
SteveGraph* Ks_SBNeg_v3_PbPb_0_10;
SteveGraph* Ks_SBNeg_v3_PbPb_10_30;
SteveGraph* Ks_SBNeg_v3_PbPb_30_50;
SteveGraph* Ks_SBNeg_v3_PbPb_50_80;
SteveGraph* Lm_SBPos_v3_PbPb_0_10;
SteveGraph* Lm_SBPos_v3_PbPb_10_30;
SteveGraph* Lm_SBPos_v3_PbPb_30_50;
SteveGraph* Lm_SBPos_v3_PbPb_50_80;
SteveGraph* Lm_SBNeg_v3_PbPb_0_10;
SteveGraph* Lm_SBNeg_v3_PbPb_10_30;
SteveGraph* Lm_SBNeg_v3_PbPb_30_50;
SteveGraph* Lm_SBNeg_v3_PbPb_50_80;

SteveGraph* Ks_SB_v3_PbPb_0_10;
SteveGraph* Ks_SB_v3_PbPb_10_30;
SteveGraph* Ks_SB_v3_PbPb_30_50;
SteveGraph* Ks_SB_v3_PbPb_50_80;
SteveGraph* Lm_SB_v3_PbPb_0_10;
SteveGraph* Lm_SB_v3_PbPb_10_30;
SteveGraph* Lm_SB_v3_PbPb_30_50;
SteveGraph* Lm_SB_v3_PbPb_50_80;


SteveGraph* Ks_corrected_v2_PbPb_0_10;
SteveGraph* Ks_corrected_v2_PbPb_10_30;
SteveGraph* Ks_corrected_v2_PbPb_30_50;
SteveGraph* Ks_corrected_v2_PbPb_50_80;
SteveGraph* Lm_corrected_v2_PbPb_0_10;
SteveGraph* Lm_corrected_v2_PbPb_10_30;
SteveGraph* Lm_corrected_v2_PbPb_30_50;
SteveGraph* Lm_corrected_v2_PbPb_50_80;

SteveGraph* Ks_corrected_v3_PbPb_0_10;
SteveGraph* Ks_corrected_v3_PbPb_10_30;
SteveGraph* Ks_corrected_v3_PbPb_30_50;
SteveGraph* Ks_corrected_v3_PbPb_50_80;
SteveGraph* Lm_corrected_v3_PbPb_0_10;
SteveGraph* Lm_corrected_v3_PbPb_10_30;
SteveGraph* Lm_corrected_v3_PbPb_30_50;
SteveGraph* Lm_corrected_v3_PbPb_50_80;

SteveGraph* ch_v2_PbPb[5] = {};
SteveGraph* Ks_v2_PbPb_Obs[5] = {};
SteveGraph* Ks_v2_PbPb_Bkg[5] = {};
SteveGraph* Ks_v2_PbPb_Sig[5] = {};
SteveGraph* Lm_v2_PbPb_Obs[5] = {};
SteveGraph* Lm_v2_PbPb_Bkg[5] = {};
SteveGraph* Lm_v2_PbPb_Sig[5] = {};

SteveGraph* ch_v3_PbPb[5] = {};
SteveGraph* Ks_v3_PbPb_Obs[5] = {};
SteveGraph* Ks_v3_PbPb_Bkg[5] = {};
SteveGraph* Ks_v3_PbPb_Sig[5] = {};
SteveGraph* Lm_v3_PbPb_Obs[5] = {};
SteveGraph* Lm_v3_PbPb_Bkg[5] = {};
SteveGraph* Lm_v3_PbPb_Sig[5] = {};



SteveGraph* ch_v2_sysPbPb[5] = {};
SteveGraph* Ks_v2_sysPbPb_Sig[5] = {};
SteveGraph* Lm_v2_sysPbPb_Sig[5] = {};

SteveGraph* ch_v3_sysPbPb[5] = {};
SteveGraph* Ks_v3_sysPbPb_Sig[5] = {};
SteveGraph* Lm_v3_sysPbPb_Sig[5] = {};


void LoadSP()
{
    TFile* f = new TFile("PbPb_v0.root");

    ch_v2_PbPb_0_10            = new SteveGraph( (TDirectoryFile*) f->Get("ch_v2_PbPb_0_10") );
    ch_v2_PbPb_10_30           = new SteveGraph( (TDirectoryFile*) f->Get("ch_v2_PbPb_10_30") );
    ch_v2_PbPb_30_50           = new SteveGraph( (TDirectoryFile*) f->Get("ch_v2_PbPb_30_50") );
    ch_v2_PbPb_50_80           = new SteveGraph( (TDirectoryFile*) f->Get("ch_v2_PbPb_50_80") );
    Ks_v2_PbPb_0_10            = new SteveGraph( (TDirectoryFile*) f->Get("Ks_v2_PbPb_0_10") );
    Ks_v2_PbPb_10_30           = new SteveGraph( (TDirectoryFile*) f->Get("Ks_v2_PbPb_10_30") );
    Ks_v2_PbPb_30_50           = new SteveGraph( (TDirectoryFile*) f->Get("Ks_v2_PbPb_30_50") );
    Ks_v2_PbPb_50_80           = new SteveGraph( (TDirectoryFile*) f->Get("Ks_v2_PbPb_50_80") );
    Lm_v2_PbPb_0_10            = new SteveGraph( (TDirectoryFile*) f->Get("LM_v2_PbPb_0_10") );
    Lm_v2_PbPb_10_30           = new SteveGraph( (TDirectoryFile*) f->Get("LM_v2_PbPb_10_30") );
    Lm_v2_PbPb_30_50           = new SteveGraph( (TDirectoryFile*) f->Get("LM_v2_PbPb_30_50") );
    Lm_v2_PbPb_50_80           = new SteveGraph( (TDirectoryFile*) f->Get("LM_v2_PbPb_50_80") );
    Ks_SBPos_v2_PbPb_0_10      = new SteveGraph( (TDirectoryFile*) f->Get("Ks_SBPos_v2_PbPb_0_10") );
    Ks_SBPos_v2_PbPb_10_30     = new SteveGraph( (TDirectoryFile*) f->Get("Ks_SBPos_v2_PbPb_10_30") );
    Ks_SBPos_v2_PbPb_30_50     = new SteveGraph( (TDirectoryFile*) f->Get("Ks_SBPos_v2_PbPb_30_50") );
    Ks_SBPos_v2_PbPb_50_80     = new SteveGraph( (TDirectoryFile*) f->Get("Ks_SBPos_v2_PbPb_50_80") );
    Ks_SBNeg_v2_PbPb_0_10      = new SteveGraph( (TDirectoryFile*) f->Get("Ks_SBNeg_v2_PbPb_0_10") );
    Ks_SBNeg_v2_PbPb_10_30     = new SteveGraph( (TDirectoryFile*) f->Get("Ks_SBNeg_v2_PbPb_10_30") );
    Ks_SBNeg_v2_PbPb_30_50     = new SteveGraph( (TDirectoryFile*) f->Get("Ks_SBNeg_v2_PbPb_30_50") );
    Ks_SBNeg_v2_PbPb_50_80     = new SteveGraph( (TDirectoryFile*) f->Get("Ks_SBNeg_v2_PbPb_50_80") );
    Lm_SBPos_v2_PbPb_0_10      = new SteveGraph( (TDirectoryFile*) f->Get("LM_SBPos_v2_PbPb_0_10") );
    Lm_SBPos_v2_PbPb_10_30     = new SteveGraph( (TDirectoryFile*) f->Get("LM_SBPos_v2_PbPb_10_30") );
    Lm_SBPos_v2_PbPb_30_50     = new SteveGraph( (TDirectoryFile*) f->Get("LM_SBPos_v2_PbPb_30_50") );
    Lm_SBPos_v2_PbPb_50_80     = new SteveGraph( (TDirectoryFile*) f->Get("LM_SBPos_v2_PbPb_50_80") );
    Lm_SBNeg_v2_PbPb_0_10      = new SteveGraph( (TDirectoryFile*) f->Get("LM_SBNeg_v2_PbPb_0_10") );
    Lm_SBNeg_v2_PbPb_10_30     = new SteveGraph( (TDirectoryFile*) f->Get("LM_SBNeg_v2_PbPb_10_30") );
    Lm_SBNeg_v2_PbPb_30_50     = new SteveGraph( (TDirectoryFile*) f->Get("LM_SBNeg_v2_PbPb_30_50") );
    Lm_SBNeg_v2_PbPb_50_80     = new SteveGraph( (TDirectoryFile*) f->Get("LM_SBNeg_v2_PbPb_50_80") );

    Ks_SB_v2_PbPb_0_10         = new SteveGraph( Ks_SBPos_v2_PbPb_0_10 , Ks_SBNeg_v2_PbPb_0_10   );
    Ks_SB_v2_PbPb_10_30        = new SteveGraph( Ks_SBPos_v2_PbPb_10_30, Ks_SBNeg_v2_PbPb_10_30  );
    Ks_SB_v2_PbPb_30_50        = new SteveGraph( Ks_SBPos_v2_PbPb_30_50, Ks_SBNeg_v2_PbPb_30_50  );
    Ks_SB_v2_PbPb_50_80        = new SteveGraph( Ks_SBPos_v2_PbPb_50_80, Ks_SBNeg_v2_PbPb_50_80  );
    Lm_SB_v2_PbPb_0_10         = new SteveGraph( Lm_SBPos_v2_PbPb_0_10 , Lm_SBNeg_v2_PbPb_0_10   );
    Lm_SB_v2_PbPb_10_30        = new SteveGraph( Lm_SBPos_v2_PbPb_10_30, Lm_SBNeg_v2_PbPb_10_30  );
    Lm_SB_v2_PbPb_30_50        = new SteveGraph( Lm_SBPos_v2_PbPb_30_50, Lm_SBNeg_v2_PbPb_30_50  );
    Lm_SB_v2_PbPb_50_80        = new SteveGraph( Lm_SBPos_v2_PbPb_50_80, Lm_SBNeg_v2_PbPb_50_80  );


    ch_v3_PbPb_0_10            = new SteveGraph( (TDirectoryFile*) f->Get("ch_v3_PbPb_0_10") );
    ch_v3_PbPb_10_30           = new SteveGraph( (TDirectoryFile*) f->Get("ch_v3_PbPb_10_30") );
    ch_v3_PbPb_30_50           = new SteveGraph( (TDirectoryFile*) f->Get("ch_v3_PbPb_30_50") );
    ch_v3_PbPb_50_80           = new SteveGraph( (TDirectoryFile*) f->Get("ch_v3_PbPb_50_80") );
    Ks_v3_PbPb_0_10            = new SteveGraph( (TDirectoryFile*) f->Get("Ks_v3_PbPb_0_10") );
    Ks_v3_PbPb_10_30           = new SteveGraph( (TDirectoryFile*) f->Get("Ks_v3_PbPb_10_30") );
    Ks_v3_PbPb_30_50           = new SteveGraph( (TDirectoryFile*) f->Get("Ks_v3_PbPb_30_50") );
    Ks_v3_PbPb_50_80           = new SteveGraph( (TDirectoryFile*) f->Get("Ks_v3_PbPb_50_80") );
    Lm_v3_PbPb_0_10            = new SteveGraph( (TDirectoryFile*) f->Get("LM_v3_PbPb_0_10") );
    Lm_v3_PbPb_10_30           = new SteveGraph( (TDirectoryFile*) f->Get("LM_v3_PbPb_10_30") );
    Lm_v3_PbPb_30_50           = new SteveGraph( (TDirectoryFile*) f->Get("LM_v3_PbPb_30_50") );
    Lm_v3_PbPb_50_80           = new SteveGraph( (TDirectoryFile*) f->Get("LM_v3_PbPb_50_80") );
    Ks_SBPos_v3_PbPb_0_10      = new SteveGraph( (TDirectoryFile*) f->Get("Ks_SBPos_v3_PbPb_0_10") );
    Ks_SBPos_v3_PbPb_10_30     = new SteveGraph( (TDirectoryFile*) f->Get("Ks_SBPos_v3_PbPb_10_30") );
    Ks_SBPos_v3_PbPb_30_50     = new SteveGraph( (TDirectoryFile*) f->Get("Ks_SBPos_v3_PbPb_30_50") );
    Ks_SBPos_v3_PbPb_50_80     = new SteveGraph( (TDirectoryFile*) f->Get("Ks_SBPos_v3_PbPb_50_80") );
    Ks_SBNeg_v3_PbPb_0_10      = new SteveGraph( (TDirectoryFile*) f->Get("Ks_SBNeg_v3_PbPb_0_10") );
    Ks_SBNeg_v3_PbPb_10_30     = new SteveGraph( (TDirectoryFile*) f->Get("Ks_SBNeg_v3_PbPb_10_30") );
    Ks_SBNeg_v3_PbPb_30_50     = new SteveGraph( (TDirectoryFile*) f->Get("Ks_SBNeg_v3_PbPb_30_50") );
    Ks_SBNeg_v3_PbPb_50_80     = new SteveGraph( (TDirectoryFile*) f->Get("Ks_SBNeg_v3_PbPb_50_80") );
    Lm_SBPos_v3_PbPb_0_10      = new SteveGraph( (TDirectoryFile*) f->Get("LM_SBPos_v3_PbPb_0_10") );
    Lm_SBPos_v3_PbPb_10_30     = new SteveGraph( (TDirectoryFile*) f->Get("LM_SBPos_v3_PbPb_10_30") );
    Lm_SBPos_v3_PbPb_30_50     = new SteveGraph( (TDirectoryFile*) f->Get("LM_SBPos_v3_PbPb_30_50") );
    Lm_SBPos_v3_PbPb_50_80     = new SteveGraph( (TDirectoryFile*) f->Get("LM_SBPos_v3_PbPb_50_80") );
    Lm_SBNeg_v3_PbPb_0_10      = new SteveGraph( (TDirectoryFile*) f->Get("LM_SBNeg_v3_PbPb_0_10") );
    Lm_SBNeg_v3_PbPb_10_30     = new SteveGraph( (TDirectoryFile*) f->Get("LM_SBNeg_v3_PbPb_10_30") );
    Lm_SBNeg_v3_PbPb_30_50     = new SteveGraph( (TDirectoryFile*) f->Get("LM_SBNeg_v3_PbPb_30_50") );
    Lm_SBNeg_v3_PbPb_50_80     = new SteveGraph( (TDirectoryFile*) f->Get("LM_SBNeg_v3_PbPb_50_80") );

    Ks_SB_v3_PbPb_0_10         = new SteveGraph( Ks_SBPos_v3_PbPb_0_10 , Ks_SBNeg_v3_PbPb_0_10   );
    Ks_SB_v3_PbPb_10_30        = new SteveGraph( Ks_SBPos_v3_PbPb_10_30, Ks_SBNeg_v3_PbPb_10_30  );
    Ks_SB_v3_PbPb_30_50        = new SteveGraph( Ks_SBPos_v3_PbPb_30_50, Ks_SBNeg_v3_PbPb_30_50  );
    Ks_SB_v3_PbPb_50_80        = new SteveGraph( Ks_SBPos_v3_PbPb_50_80, Ks_SBNeg_v3_PbPb_50_80  );
    Lm_SB_v3_PbPb_0_10         = new SteveGraph( Lm_SBPos_v3_PbPb_0_10 , Lm_SBNeg_v3_PbPb_0_10   );
    Lm_SB_v3_PbPb_10_30        = new SteveGraph( Lm_SBPos_v3_PbPb_10_30, Lm_SBNeg_v3_PbPb_10_30  );
    Lm_SB_v3_PbPb_30_50        = new SteveGraph( Lm_SBPos_v3_PbPb_30_50, Lm_SBNeg_v3_PbPb_30_50  );
    Lm_SB_v3_PbPb_50_80        = new SteveGraph( Lm_SBPos_v3_PbPb_50_80, Lm_SBNeg_v3_PbPb_50_80  );

    ch_v2_PbPb[0]       = ch_v2_PbPb_0_10;
    ch_v2_PbPb[1]       = ch_v2_PbPb_10_30;
    ch_v2_PbPb[2]       = ch_v2_PbPb_30_50;
    ch_v2_PbPb[3]       = ch_v2_PbPb_50_80;

    Ks_v2_PbPb_Obs[0]   = Ks_v2_PbPb_0_10;
    Ks_v2_PbPb_Obs[1]   = Ks_v2_PbPb_10_30;
    Ks_v2_PbPb_Obs[2]   = Ks_v2_PbPb_30_50;
    Ks_v2_PbPb_Obs[3]   = Ks_v2_PbPb_50_80;

    Ks_v2_PbPb_Bkg[0]   = Ks_SB_v2_PbPb_0_10;
    Ks_v2_PbPb_Bkg[1]   = Ks_SB_v2_PbPb_10_30;
    Ks_v2_PbPb_Bkg[2]   = Ks_SB_v2_PbPb_30_50;
    Ks_v2_PbPb_Bkg[3]   = Ks_SB_v2_PbPb_50_80;

    Ks_v2_PbPb_Sig[0]   = new SteveGraph();
    Ks_v2_PbPb_Sig[1]   = new SteveGraph();
    Ks_v2_PbPb_Sig[2]   = new SteveGraph();
    Ks_v2_PbPb_Sig[3]   = new SteveGraph();

    Lm_v2_PbPb_Obs[0]   = Lm_v2_PbPb_0_10;
    Lm_v2_PbPb_Obs[1]   = Lm_v2_PbPb_10_30;
    Lm_v2_PbPb_Obs[2]   = Lm_v2_PbPb_30_50;
    Lm_v2_PbPb_Obs[3]   = Lm_v2_PbPb_50_80;

    Lm_v2_PbPb_Bkg[0]   = Lm_SB_v2_PbPb_0_10;
    Lm_v2_PbPb_Bkg[1]   = Lm_SB_v2_PbPb_10_30;
    Lm_v2_PbPb_Bkg[2]   = Lm_SB_v2_PbPb_30_50;
    Lm_v2_PbPb_Bkg[3]   = Lm_SB_v2_PbPb_50_80;

    Lm_v2_PbPb_Sig[0]   = new SteveGraph();
    Lm_v2_PbPb_Sig[1]   = new SteveGraph();
    Lm_v2_PbPb_Sig[2]   = new SteveGraph();
    Lm_v2_PbPb_Sig[3]   = new SteveGraph();

    ch_v3_PbPb[0]       = ch_v3_PbPb_0_10;
    ch_v3_PbPb[1]       = ch_v3_PbPb_10_30;
    ch_v3_PbPb[2]       = ch_v3_PbPb_30_50;
    ch_v3_PbPb[3]       = ch_v3_PbPb_50_80;

    Ks_v3_PbPb_Obs[0]   = Ks_v3_PbPb_0_10;
    Ks_v3_PbPb_Obs[1]   = Ks_v3_PbPb_10_30;
    Ks_v3_PbPb_Obs[2]   = Ks_v3_PbPb_30_50;
    Ks_v3_PbPb_Obs[3]   = Ks_v3_PbPb_50_80;

    Ks_v3_PbPb_Bkg[0]   = Ks_SB_v3_PbPb_0_10;
    Ks_v3_PbPb_Bkg[1]   = Ks_SB_v3_PbPb_10_30;
    Ks_v3_PbPb_Bkg[2]   = Ks_SB_v3_PbPb_30_50;
    Ks_v3_PbPb_Bkg[3]   = Ks_SB_v3_PbPb_50_80;

    Ks_v3_PbPb_Sig[0]   = new SteveGraph();
    Ks_v3_PbPb_Sig[1]   = new SteveGraph();
    Ks_v3_PbPb_Sig[2]   = new SteveGraph();
    Ks_v3_PbPb_Sig[3]   = new SteveGraph();

    Lm_v3_PbPb_Obs[0]   = Lm_v3_PbPb_0_10;
    Lm_v3_PbPb_Obs[1]   = Lm_v3_PbPb_10_30;
    Lm_v3_PbPb_Obs[2]   = Lm_v3_PbPb_30_50;
    Lm_v3_PbPb_Obs[3]   = Lm_v3_PbPb_50_80;

    Lm_v3_PbPb_Bkg[0]   = Lm_SB_v3_PbPb_0_10;
    Lm_v3_PbPb_Bkg[1]   = Lm_SB_v3_PbPb_10_30;
    Lm_v3_PbPb_Bkg[2]   = Lm_SB_v3_PbPb_30_50;
    Lm_v3_PbPb_Bkg[3]   = Lm_SB_v3_PbPb_50_80;

    Lm_v3_PbPb_Sig[0]   = new SteveGraph();
    Lm_v3_PbPb_Sig[1]   = new SteveGraph();
    Lm_v3_PbPb_Sig[2]   = new SteveGraph();
    Lm_v3_PbPb_Sig[3]   = new SteveGraph();

}


void LoadSPCorrected(bool bTrim = false)
{
    TFile * fSP  = new TFile("PbPb_v0_SP_corrected.root");
    int idx = 0;
    for ( auto dir : {"_0_10", "_10_30", "_30_50", "_50_80"} ) {
        TDirectoryFile * d = (TDirectoryFile*) fSP->Get( (string("ch_v2_PbPb") + dir).c_str() );
        ch_v2_PbPb[idx] = new SteveGraph(d);

        d = (TDirectoryFile*) fSP->Get( (string("ch_v3_PbPb") + dir).c_str() );
        ch_v3_PbPb[idx] = new SteveGraph(d);

        d = (TDirectoryFile*) fSP->Get( (string("Ks_v2_PbPb_Sig") + dir).c_str() );
        Ks_v2_PbPb_Sig[idx] = new SteveGraph(d);

        d = (TDirectoryFile*) fSP->Get( (string("Ks_v3_PbPb_Sig") + dir).c_str() );
        Ks_v3_PbPb_Sig[idx] = new SteveGraph(d);

        d = (TDirectoryFile*) fSP->Get( (string("Lm_v2_PbPb_Sig") + dir).c_str() );
        Lm_v2_PbPb_Sig[idx] = new SteveGraph(d);

        d = (TDirectoryFile*) fSP->Get( (string("Lm_v3_PbPb_Sig") + dir).c_str() );
        Lm_v3_PbPb_Sig[idx] = new SteveGraph(d);

        ch_v2_sysPbPb[idx]      = new SteveGraph( ch_v2_PbPb[idx],  sp_syst[0] );
        ch_v3_sysPbPb[idx]      = new SteveGraph( ch_v3_PbPb[idx],  sp_syst[0] );

        Ks_v2_sysPbPb_Sig[idx]  = new SteveGraph( Ks_v2_PbPb_Sig[idx],  sp_syst[1] );
        Ks_v3_sysPbPb_Sig[idx]  = new SteveGraph( Ks_v3_PbPb_Sig[idx],  sp_syst[1] );

        Lm_v2_sysPbPb_Sig[idx]  = new SteveGraph( Lm_v2_PbPb_Sig[idx],  sp_syst[2] );
        Lm_v3_sysPbPb_Sig[idx]  = new SteveGraph( Lm_v3_PbPb_Sig[idx],  sp_syst[2] );

        ch_v2_PbPb         [idx]->ResetX();
        Ks_v2_PbPb_Sig     [idx]->ResetX();
        Lm_v2_PbPb_Sig     [idx]->ResetX();
        ch_v3_PbPb         [idx]->ResetX();
        Ks_v3_PbPb_Sig     [idx]->ResetX();
        Lm_v3_PbPb_Sig     [idx]->ResetX();

        ch_v2_sysPbPb      [idx]->ResetX();
        Ks_v2_sysPbPb_Sig  [idx]->ResetX();
        Lm_v2_sysPbPb_Sig  [idx]->ResetX();
        ch_v3_sysPbPb      [idx]->ResetX();
        Ks_v3_sysPbPb_Sig  [idx]->ResetX();
        Lm_v3_sysPbPb_Sig  [idx]->ResetX();

        if ( bTrim ) {
            ch_v2_PbPb         [idx]->dropPoints(2);
            Ks_v2_PbPb_Sig     [idx]->dropPoints(4);
            Lm_v2_PbPb_Sig     [idx]->dropPoints(6);
            ch_v3_PbPb         [idx]->dropPoints(2);
            Ks_v3_PbPb_Sig     [idx]->dropPoints(4);
            Lm_v3_PbPb_Sig     [idx]->dropPoints(6);

            ch_v2_sysPbPb      [idx]->dropPoints(2);
            Ks_v2_sysPbPb_Sig  [idx]->dropPoints(4);
            Lm_v2_sysPbPb_Sig  [idx]->dropPoints(6);
            ch_v3_sysPbPb      [idx]->dropPoints(2);
            Ks_v3_sysPbPb_Sig  [idx]->dropPoints(4);
            Lm_v3_sysPbPb_Sig  [idx]->dropPoints(6);
        }

        idx++;
    }
}
