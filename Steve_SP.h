

typedef struct SteveGraph
{
    TGraphErrors* vn_NegEta_PosEtaEP;
    TGraphErrors* vn_NegEta_PosEtaEP_SubEvt;
    TGraphErrors* vn_PosEta_NegEtaEP;
    TGraphErrors* vn_PosEta_NegEtaEP_SubEvt;
    TGraphErrors* vn_Full_PosEtaEP;
    TGraphErrors* vn_Full_PosEtaEP_SubEvt;
    TGraphErrors* vn_Full_NegEtaEP;
    TGraphErrors* vn_Full_NegEtaEP_SubEvt;

    SteveGraph() {
        vn_NegEta_PosEtaEP        = 0;
        vn_NegEta_PosEtaEP_SubEvt = 0;
        vn_PosEta_NegEtaEP        = 0;
        vn_PosEta_NegEtaEP_SubEvt = 0;
        vn_Full_PosEtaEP          = 0;
        vn_Full_PosEtaEP_SubEvt   = 0;
        vn_Full_NegEtaEP          = 0;
        vn_Full_NegEtaEP_SubEvt   = 0;
    };

    SteveGraph(TDirectoryFile * dir) {
        vn_NegEta_PosEtaEP          = (TGraphErrors*) dir->Get("vn_NegEta_PosEtaEP");
        vn_NegEta_PosEtaEP_SubEvt   = (TGraphErrors*) dir->Get("vn_NegEta_PosEtaEP_SubEvt");
        vn_PosEta_NegEtaEP          = (TGraphErrors*) dir->Get("vn_PosEta_NegEtaEP");
        vn_PosEta_NegEtaEP_SubEvt   = (TGraphErrors*) dir->Get("vn_PosEta_NegEtaEP_SubEvt");
        vn_Full_PosEtaEP            = (TGraphErrors*) dir->Get("vn_Full_PosEtaEP");
        vn_Full_PosEtaEP_SubEvt     = (TGraphErrors*) dir->Get("vn_Full_PosEtaEP_SubEvt");
        vn_Full_NegEtaEP            = (TGraphErrors*) dir->Get("vn_Full_NegEtaEP");
        vn_Full_NegEtaEP_SubEvt     = (TGraphErrors*) dir->Get("vn_Full_NegEtaEP_SubEvt");
    };

    SteveGraph(SteveGraph* sg1, SteveGraph* sg2, bool bDirect = true) {
        if ( bDirect ) {
            vn_NegEta_PosEtaEP          = merge( sg1->vn_NegEta_PosEtaEP        , sg2->vn_NegEta_PosEtaEP       );
            vn_NegEta_PosEtaEP_SubEvt   = merge( sg1->vn_NegEta_PosEtaEP_SubEvt , sg2->vn_NegEta_PosEtaEP_SubEvt);
            vn_PosEta_NegEtaEP          = merge( sg1->vn_PosEta_NegEtaEP        , sg2->vn_PosEta_NegEtaEP       );
            vn_PosEta_NegEtaEP_SubEvt   = merge( sg1->vn_PosEta_NegEtaEP_SubEvt , sg2->vn_PosEta_NegEtaEP_SubEvt);
            vn_Full_PosEtaEP            = merge( sg1->vn_Full_PosEtaEP          , sg2->vn_Full_PosEtaEP         );
            vn_Full_PosEtaEP_SubEvt     = merge( sg1->vn_Full_PosEtaEP_SubEvt   , sg2->vn_Full_PosEtaEP_SubEvt  );
            vn_Full_NegEtaEP            = merge( sg1->vn_Full_NegEtaEP          , sg2->vn_Full_NegEtaEP         );
            vn_Full_NegEtaEP_SubEvt     = merge( sg1->vn_Full_NegEtaEP_SubEvt   , sg2->vn_Full_NegEtaEP_SubEvt  );
        } else {
            vn_NegEta_PosEtaEP          = merge( sg1->vn_NegEta_PosEtaEP        , sg2->vn_PosEta_NegEtaEP       );
            vn_NegEta_PosEtaEP_SubEvt   = merge( sg1->vn_NegEta_PosEtaEP_SubEvt , sg2->vn_PosEta_NegEtaEP_SubEvt);
            vn_PosEta_NegEtaEP          = merge( sg1->vn_PosEta_NegEtaEP        , sg2->vn_NegEta_PosEtaEP);
            vn_PosEta_NegEtaEP_SubEvt   = merge( sg1->vn_PosEta_NegEtaEP_SubEvt , sg2->vn_NegEta_PosEtaEP_SubEvt);
            vn_Full_PosEtaEP            = merge( sg1->vn_Full_PosEtaEP          , sg2->vn_Full_NegEtaEP         );
            vn_Full_PosEtaEP_SubEvt     = merge( sg1->vn_Full_PosEtaEP_SubEvt   , sg2->vn_Full_NegEtaEP_SubEvt  );
            vn_Full_NegEtaEP            = merge( sg1->vn_Full_NegEtaEP          , sg2->vn_Full_PosEtaEP         );
            vn_Full_NegEtaEP_SubEvt     = merge( sg1->vn_Full_NegEtaEP_SubEvt   , sg2->vn_Full_PosEtaEP_SubEvt  );
        }
    };

    void Write(TDirectory* dir) {
        dir->cd();
        vn_NegEta_PosEtaEP          ->Write( "vn_NegEta_PosEtaEP" );
        vn_NegEta_PosEtaEP_SubEvt   ->Write( "vn_NegEta_PosEtaEP_SubEvt" );
        vn_PosEta_NegEtaEP          ->Write( "vn_PosEta_NegEtaEP" );
        vn_PosEta_NegEtaEP_SubEvt   ->Write( "vn_PosEta_NegEtaEP_SubEvt" );
        vn_Full_PosEtaEP            ->Write( "vn_Full_PosEtaEP" );
        vn_Full_PosEtaEP_SubEvt     ->Write( "vn_Full_PosEtaEP_SubEvt" );
        vn_Full_NegEtaEP            ->Write( "vn_Full_NegEtaEP" );
        vn_Full_NegEtaEP_SubEvt     ->Write( "vn_Full_NegEtaEP_SubEvt" );
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

} SteveGraph;

SteveGraph*	Ks_pPb_120_150;
SteveGraph*	Ks_pPb_150_185;
SteveGraph*	Ks_pPb_185_250;
SteveGraph*	Ks_pPb_250_600;
SteveGraph*	Ks_SBPos_pPb_120_150;
SteveGraph*	Ks_SBPos_pPb_150_185;
SteveGraph*	Ks_SBPos_pPb_185_250;
SteveGraph*	Ks_SBPos_pPb_250_600;
SteveGraph*	Ks_SBNeg_pPb_120_150;
SteveGraph*	Ks_SBNeg_pPb_150_185;
SteveGraph*	Ks_SBNeg_pPb_185_250;
SteveGraph*	Ks_SBNeg_pPb_250_600;
SteveGraph*	Lambda_pPb_120_150;
SteveGraph*	Lambda_pPb_150_185;
SteveGraph*	Lambda_pPb_185_250;
SteveGraph*	Lambda_pPb_250_600;
SteveGraph*	Lambda_SBPos_pPb_120_150;
SteveGraph*	Lambda_SBPos_pPb_150_185;
SteveGraph*	Lambda_SBPos_pPb_185_250;
SteveGraph*	Lambda_SBPos_pPb_250_600;
SteveGraph*	Lambda_SBNeg_pPb_120_150;
SteveGraph*	Lambda_SBNeg_pPb_150_185;
SteveGraph*	Lambda_SBNeg_pPb_185_250;
SteveGraph*	Lambda_SBNeg_pPb_250_600;
SteveGraph*	ch_pPb_120_150;
SteveGraph*	ch_pPb_150_185;
SteveGraph*	ch_pPb_185_250;
SteveGraph*	ch_pPb_250_600;
SteveGraph*	Ks_Pbp_120_150;
SteveGraph*	Ks_Pbp_150_185;
SteveGraph*	Ks_Pbp_185_250;
SteveGraph*	Ks_Pbp_250_600;
SteveGraph*	Ks_SBPos_Pbp_120_150;
SteveGraph*	Ks_SBPos_Pbp_150_185;
SteveGraph*	Ks_SBPos_Pbp_185_250;
SteveGraph*	Ks_SBPos_Pbp_250_600;
SteveGraph*	Ks_SBNeg_Pbp_120_150;
SteveGraph*	Ks_SBNeg_Pbp_150_185;
SteveGraph*	Ks_SBNeg_Pbp_185_250;
SteveGraph*	Ks_SBNeg_Pbp_250_600;
SteveGraph*	Lambda_Pbp_120_150;
SteveGraph*	Lambda_Pbp_150_185;
SteveGraph*	Lambda_Pbp_185_250;
SteveGraph*	Lambda_Pbp_250_600;
SteveGraph*	Lambda_SBPos_Pbp_120_150;
SteveGraph*	Lambda_SBPos_Pbp_150_185;
SteveGraph*	Lambda_SBPos_Pbp_185_250;
SteveGraph*	Lambda_SBPos_Pbp_250_600;
SteveGraph*	Lambda_SBNeg_Pbp_120_150;
SteveGraph*	Lambda_SBNeg_Pbp_150_185;
SteveGraph*	Lambda_SBNeg_Pbp_185_250;
SteveGraph*	Lambda_SBNeg_Pbp_250_600;
SteveGraph*	ch_Pbp_120_150;
SteveGraph*	ch_Pbp_150_185;
SteveGraph*	ch_Pbp_185_250;
SteveGraph*	ch_Pbp_250_600;

// merged
SteveGraph* Ks_SB_pPb_120_150;
SteveGraph* Ks_SB_pPb_150_185;
SteveGraph* Ks_SB_pPb_185_250;
SteveGraph* Ks_SB_pPb_250_600;

SteveGraph* Ks_SB_Pbp_120_150;
SteveGraph* Ks_SB_Pbp_150_185;
SteveGraph* Ks_SB_Pbp_185_250;
SteveGraph* Ks_SB_Pbp_250_600;

SteveGraph* Ks_SB_pPb_merge_120_150;
SteveGraph* Ks_SB_pPb_merge_150_185;
SteveGraph* Ks_SB_pPb_merge_185_250;
SteveGraph* Ks_SB_pPb_merge_250_600;

SteveGraph* Ks_pPb_merge_120_150;
SteveGraph* Ks_pPb_merge_150_185;
SteveGraph* Ks_pPb_merge_185_250;
SteveGraph* Ks_pPb_merge_250_600;

SteveGraph* Lm_SB_pPb_120_150;
SteveGraph* Lm_SB_pPb_150_185;
SteveGraph* Lm_SB_pPb_185_250;
SteveGraph* Lm_SB_pPb_250_600;

SteveGraph* Lm_SB_Pbp_120_150;
SteveGraph* Lm_SB_Pbp_150_185;
SteveGraph* Lm_SB_Pbp_185_250;
SteveGraph* Lm_SB_Pbp_250_600;

SteveGraph* Lm_SB_pPb_merge_120_150;
SteveGraph* Lm_SB_pPb_merge_150_185;
SteveGraph* Lm_SB_pPb_merge_185_250;
SteveGraph* Lm_SB_pPb_merge_250_600;

SteveGraph* Lm_pPb_merge_120_150;
SteveGraph* Lm_pPb_merge_150_185;
SteveGraph* Lm_pPb_merge_185_250;
SteveGraph* Lm_pPb_merge_250_600;

SteveGraph* ch_pPb_merge_120_150;
SteveGraph* ch_pPb_merge_150_185;
SteveGraph* ch_pPb_merge_185_250;
SteveGraph* ch_pPb_merge_250_600;


SteveGraph* Ks_SB_pPb_merge[10] = {};
SteveGraph* Lm_SB_pPb_merge[10] = {};

SteveGraph* Ks_pPb_merge[10] = {};
SteveGraph* Lm_pPb_merge[10] = {};

SteveGraph* ch_pPb_merge[10] = {};

void LoadSP()
{
    TFile f("v0.root");

    Ks_pPb_120_150              = new SteveGraph((TDirectoryFile*) f.Get("Ks_pPb_120_150"));
    Ks_pPb_150_185              = new SteveGraph((TDirectoryFile*) f.Get("Ks_pPb_150_185"));
    Ks_pPb_185_250              = new SteveGraph((TDirectoryFile*) f.Get("Ks_pPb_185_250"));
    Ks_pPb_250_600              = new SteveGraph((TDirectoryFile*) f.Get("Ks_pPb_250_600"));
    Ks_SBPos_pPb_120_150        = new SteveGraph((TDirectoryFile*) f.Get("Ks_SBPos_pPb_120_150"));
    Ks_SBPos_pPb_150_185        = new SteveGraph((TDirectoryFile*) f.Get("Ks_SBPos_pPb_150_185"));
    Ks_SBPos_pPb_185_250        = new SteveGraph((TDirectoryFile*) f.Get("Ks_SBPos_pPb_185_250"));
    Ks_SBPos_pPb_250_600        = new SteveGraph((TDirectoryFile*) f.Get("Ks_SBPos_pPb_250_600"));
    Ks_SBNeg_pPb_120_150        = new SteveGraph((TDirectoryFile*) f.Get("Ks_SBNeg_pPb_120_150"));
    Ks_SBNeg_pPb_150_185        = new SteveGraph((TDirectoryFile*) f.Get("Ks_SBNeg_pPb_150_185"));
    Ks_SBNeg_pPb_185_250        = new SteveGraph((TDirectoryFile*) f.Get("Ks_SBNeg_pPb_185_250"));
    Ks_SBNeg_pPb_250_600        = new SteveGraph((TDirectoryFile*) f.Get("Ks_SBNeg_pPb_250_600"));
    Lambda_pPb_120_150          = new SteveGraph((TDirectoryFile*) f.Get("Lambda_pPb_120_150"));
    Lambda_pPb_150_185          = new SteveGraph((TDirectoryFile*) f.Get("Lambda_pPb_150_185"));
    Lambda_pPb_185_250          = new SteveGraph((TDirectoryFile*) f.Get("Lambda_pPb_185_250"));
    Lambda_pPb_250_600          = new SteveGraph((TDirectoryFile*) f.Get("Lambda_pPb_250_500"));
    Lambda_SBPos_pPb_120_150    = new SteveGraph((TDirectoryFile*) f.Get("Lambda_SBPos_pPb_120_150"));
    Lambda_SBPos_pPb_150_185    = new SteveGraph((TDirectoryFile*) f.Get("Lambda_SBPos_pPb_150_185"));
    Lambda_SBPos_pPb_185_250    = new SteveGraph((TDirectoryFile*) f.Get("Lambda_SBPos_pPb_185_250"));
    Lambda_SBPos_pPb_250_600    = new SteveGraph((TDirectoryFile*) f.Get("Lambda_SBPos_pPb_250_600"));
    Lambda_SBNeg_pPb_120_150    = new SteveGraph((TDirectoryFile*) f.Get("Lambda_SBNeg_pPb_120_150"));
    Lambda_SBNeg_pPb_150_185    = new SteveGraph((TDirectoryFile*) f.Get("Lambda_SBNeg_pPb_150_185"));
    Lambda_SBNeg_pPb_185_250    = new SteveGraph((TDirectoryFile*) f.Get("Lambda_SBNeg_pPb_185_250"));
    Lambda_SBNeg_pPb_250_600    = new SteveGraph((TDirectoryFile*) f.Get("Lambda_SBNeg_pPb_250_600"));
    ch_pPb_120_150              = new SteveGraph((TDirectoryFile*) f.Get("ch_pPb_120_150"));
    ch_pPb_150_185              = new SteveGraph((TDirectoryFile*) f.Get("ch_pPb_150_185"));
    ch_pPb_185_250              = new SteveGraph((TDirectoryFile*) f.Get("ch_pPb_185_250"));
    ch_pPb_250_600              = new SteveGraph((TDirectoryFile*) f.Get("ch_pPb_250_600"));
    Ks_Pbp_120_150              = new SteveGraph((TDirectoryFile*) f.Get("Ks_Pbp_120_150"));
    Ks_Pbp_150_185              = new SteveGraph((TDirectoryFile*) f.Get("Ks_Pbp_150_185"));
    Ks_Pbp_185_250              = new SteveGraph((TDirectoryFile*) f.Get("Ks_Pbp_185_250"));
    Ks_Pbp_250_600              = new SteveGraph((TDirectoryFile*) f.Get("Ks_Pbp_250_600"));
    Ks_SBPos_Pbp_120_150        = new SteveGraph((TDirectoryFile*) f.Get("Ks_SBPos_Pbp_120_150"));
    Ks_SBPos_Pbp_150_185        = new SteveGraph((TDirectoryFile*) f.Get("Ks_SBPos_Pbp_150_185"));
    Ks_SBPos_Pbp_185_250        = new SteveGraph((TDirectoryFile*) f.Get("Ks_SBPos_Pbp_185_250"));
    Ks_SBPos_Pbp_250_600        = new SteveGraph((TDirectoryFile*) f.Get("Ks_SBPos_Pbp_250_600"));
    Ks_SBNeg_Pbp_120_150        = new SteveGraph((TDirectoryFile*) f.Get("Ks_SBNeg_Pbp_120_150"));
    Ks_SBNeg_Pbp_150_185        = new SteveGraph((TDirectoryFile*) f.Get("Ks_SBNeg_Pbp_150_185"));
    Ks_SBNeg_Pbp_185_250        = new SteveGraph((TDirectoryFile*) f.Get("Ks_SBNeg_Pbp_185_250"));
    Ks_SBNeg_Pbp_250_600        = new SteveGraph((TDirectoryFile*) f.Get("Ks_SBNeg_Pbp_250_600"));
    Lambda_Pbp_120_150          = new SteveGraph((TDirectoryFile*) f.Get("Lambda_Pbp_120_150"));
    Lambda_Pbp_150_185          = new SteveGraph((TDirectoryFile*) f.Get("Lambda_Pbp_150_185"));
    Lambda_Pbp_185_250          = new SteveGraph((TDirectoryFile*) f.Get("Lambda_Pbp_185_250"));
    Lambda_Pbp_250_600          = new SteveGraph((TDirectoryFile*) f.Get("Lambda_Pbp_250_500"));
    Lambda_SBPos_Pbp_120_150    = new SteveGraph((TDirectoryFile*) f.Get("Lambda_SBPos_Pbp_120_150"));
    Lambda_SBPos_Pbp_150_185    = new SteveGraph((TDirectoryFile*) f.Get("Lambda_SBPos_Pbp_150_185"));
    Lambda_SBPos_Pbp_185_250    = new SteveGraph((TDirectoryFile*) f.Get("Lambda_SBPos_Pbp_185_250"));
    Lambda_SBPos_Pbp_250_600    = new SteveGraph((TDirectoryFile*) f.Get("Lambda_SBPos_Pbp_250_600"));
    Lambda_SBNeg_Pbp_120_150    = new SteveGraph((TDirectoryFile*) f.Get("Lambda_SBNeg_Pbp_120_150"));
    Lambda_SBNeg_Pbp_150_185    = new SteveGraph((TDirectoryFile*) f.Get("Lambda_SBNeg_Pbp_150_185"));
    Lambda_SBNeg_Pbp_185_250    = new SteveGraph((TDirectoryFile*) f.Get("Lambda_SBNeg_Pbp_185_250"));
    Lambda_SBNeg_Pbp_250_600    = new SteveGraph((TDirectoryFile*) f.Get("Lambda_SBNeg_Pbp_250_600"));
    ch_Pbp_120_150              = new SteveGraph((TDirectoryFile*) f.Get("ch_Pbp_120_150"));
    ch_Pbp_150_185              = new SteveGraph((TDirectoryFile*) f.Get("ch_Pbp_150_185"));
    ch_Pbp_185_250              = new SteveGraph((TDirectoryFile*) f.Get("ch_Pbp_185_250"));
    ch_Pbp_250_600              = new SteveGraph((TDirectoryFile*) f.Get("ch_Pbp_250_600"));

    Ks_SB_pPb_120_150           = new SteveGraph( Ks_SBPos_pPb_120_150, Ks_SBNeg_pPb_120_150 );
    Ks_SB_pPb_150_185           = new SteveGraph( Ks_SBPos_pPb_150_185, Ks_SBNeg_pPb_150_185 );
    Ks_SB_pPb_185_250           = new SteveGraph( Ks_SBPos_pPb_185_250, Ks_SBNeg_pPb_185_250 );
    Ks_SB_pPb_250_600           = new SteveGraph( Ks_SBPos_pPb_250_600, Ks_SBNeg_pPb_250_600 );

    Ks_SB_Pbp_120_150           = new SteveGraph( Ks_SBPos_Pbp_120_150, Ks_SBNeg_Pbp_120_150 );
    Ks_SB_Pbp_150_185           = new SteveGraph( Ks_SBPos_Pbp_150_185, Ks_SBNeg_Pbp_150_185 );
    Ks_SB_Pbp_185_250           = new SteveGraph( Ks_SBPos_Pbp_185_250, Ks_SBNeg_Pbp_185_250 );
    Ks_SB_Pbp_250_600           = new SteveGraph( Ks_SBPos_Pbp_250_600, Ks_SBNeg_Pbp_250_600 );

    Ks_SB_pPb_merge_120_150     = new SteveGraph( Ks_SB_pPb_120_150,    Ks_SB_Pbp_120_150, false );
    Ks_SB_pPb_merge_150_185     = new SteveGraph( Ks_SB_pPb_150_185,    Ks_SB_Pbp_150_185, false );
    Ks_SB_pPb_merge_185_250     = new SteveGraph( Ks_SB_pPb_185_250,    Ks_SB_Pbp_185_250, false );
    Ks_SB_pPb_merge_250_600     = new SteveGraph( Ks_SB_pPb_250_600,    Ks_SB_Pbp_250_600, false );

    Ks_pPb_merge_120_150        = new SteveGraph( Ks_pPb_120_150,       Ks_Pbp_120_150, false );
    Ks_pPb_merge_150_185        = new SteveGraph( Ks_pPb_150_185,       Ks_Pbp_150_185, false );
    Ks_pPb_merge_185_250        = new SteveGraph( Ks_pPb_185_250,       Ks_Pbp_185_250, false );
    Ks_pPb_merge_250_600        = new SteveGraph( Ks_pPb_250_600,       Ks_Pbp_250_600, false );

    Lm_SB_pPb_120_150           = new SteveGraph( Lambda_SBPos_pPb_120_150, Lambda_SBNeg_pPb_120_150 );
    Lm_SB_pPb_150_185           = new SteveGraph( Lambda_SBPos_pPb_150_185, Lambda_SBNeg_pPb_150_185 );
    Lm_SB_pPb_185_250           = new SteveGraph( Lambda_SBPos_pPb_185_250, Lambda_SBNeg_pPb_185_250 );
    Lm_SB_pPb_250_600           = new SteveGraph( Lambda_SBPos_pPb_250_600, Lambda_SBNeg_pPb_250_600 );

    Lm_SB_Pbp_120_150           = new SteveGraph( Lambda_SBPos_Pbp_120_150, Lambda_SBNeg_Pbp_120_150 );
    Lm_SB_Pbp_150_185           = new SteveGraph( Lambda_SBPos_Pbp_150_185, Lambda_SBNeg_Pbp_150_185 );
    Lm_SB_Pbp_185_250           = new SteveGraph( Lambda_SBPos_Pbp_185_250, Lambda_SBNeg_Pbp_185_250 );
    Lm_SB_Pbp_250_600           = new SteveGraph( Lambda_SBPos_Pbp_250_600, Lambda_SBNeg_Pbp_250_600 );

    Lm_SB_pPb_merge_120_150     = new SteveGraph( Lm_SB_pPb_120_150,    Lm_SB_Pbp_120_150, false );
    Lm_SB_pPb_merge_150_185     = new SteveGraph( Lm_SB_pPb_150_185,    Lm_SB_Pbp_150_185, false );
    Lm_SB_pPb_merge_185_250     = new SteveGraph( Lm_SB_pPb_185_250,    Lm_SB_Pbp_185_250, false );
    Lm_SB_pPb_merge_250_600     = new SteveGraph( Lm_SB_pPb_250_600,    Lm_SB_Pbp_250_600, false );

    Lm_pPb_merge_120_150        = new SteveGraph( Lambda_pPb_120_150,       Lambda_Pbp_120_150, false );
    Lm_pPb_merge_150_185        = new SteveGraph( Lambda_pPb_150_185,       Lambda_Pbp_150_185, false );
    Lm_pPb_merge_185_250        = new SteveGraph( Lambda_pPb_185_250,       Lambda_Pbp_185_250, false );
    Lm_pPb_merge_250_600        = new SteveGraph( Lambda_pPb_250_600,       Lambda_Pbp_250_600, false );

    ch_pPb_merge_120_150        = new SteveGraph( ch_pPb_120_150,       ch_Pbp_120_150, false );
    ch_pPb_merge_150_185        = new SteveGraph( ch_pPb_150_185,       ch_Pbp_150_185, false );
    ch_pPb_merge_185_250        = new SteveGraph( ch_pPb_185_250,       ch_Pbp_185_250, false );
    ch_pPb_merge_250_600        = new SteveGraph( ch_pPb_250_600,       ch_Pbp_250_600, false );

    Ks_SB_pPb_merge[6]      = Ks_SB_pPb_merge_120_150;
    Ks_SB_pPb_merge[7]      = Ks_SB_pPb_merge_150_185;
    Ks_SB_pPb_merge[8]      = Ks_SB_pPb_merge_185_250;
    Ks_SB_pPb_merge[9]      = Ks_SB_pPb_merge_250_600;

    Ks_pPb_merge[6]         = Ks_pPb_merge_120_150;
    Ks_pPb_merge[7]         = Ks_pPb_merge_150_185;
    Ks_pPb_merge[8]         = Ks_pPb_merge_185_250;
    Ks_pPb_merge[9]         = Ks_pPb_merge_250_600;

    Lm_SB_pPb_merge[6]      = Lm_SB_pPb_merge_120_150;
    Lm_SB_pPb_merge[7]      = Lm_SB_pPb_merge_150_185;
    Lm_SB_pPb_merge[8]      = Lm_SB_pPb_merge_185_250;
    Lm_SB_pPb_merge[9]      = Lm_SB_pPb_merge_250_600;

    Lm_pPb_merge[6]         = Lm_pPb_merge_120_150;
    Lm_pPb_merge[7]         = Lm_pPb_merge_150_185;
    Lm_pPb_merge[8]         = Lm_pPb_merge_185_250;
    Lm_pPb_merge[9]         = Lm_pPb_merge_250_600;

    ch_pPb_merge[6]         = ch_pPb_merge_120_150;
    ch_pPb_merge[7]         = ch_pPb_merge_150_185;
    ch_pPb_merge[8]         = ch_pPb_merge_185_250;
    ch_pPb_merge[9]         = ch_pPb_merge_250_600;
}

