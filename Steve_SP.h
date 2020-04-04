

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

        vn_MergedEta    = merge( vn_NegEta, vn_PosEta );
        vn_MergedEta_SubEvt = merge( vn_NegEta_SubEvt, vn_PosEta_SubEvt );
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

SteveGraph* ch_PbPb_0_10;
SteveGraph* ch_PbPb_10_30;
SteveGraph* ch_PbPb_30_50;
SteveGraph* ch_PbPb_50_80;

void LoadSP()
{
    TFile f("PbPb_v0.root");

    ch_PbPb_0_10  = new SteveGraph( (TDirectoryFile*) f->Get("ch_PbPb_0_10") );
    ch_PbPb_10_30 = new SteveGraph( (TDirectoryFile*) f->Get("ch_PbPb_10_30") );
    ch_PbPb_30_50 = new SteveGraph( (TDirectoryFile*) f->Get("ch_PbPb_30_50") );
    ch_PbPb_50_80 = new SteveGraph( (TDirectoryFile*) f->Get("ch_PbPb_50_80") );

}

