
typedef struct pPbGr {
    TGraphErrors* gr_pT[7][4][20];
    TGraphErrors* gr_pTGap[7][20];
    TGraphErrors* grH_pTGap[7][20];

    TGraphErrors* grV2sub2[20] = {};
    TGraphErrors* grV2sub4[20] = {};
    TGraphErrors* grV2sub2pos[20] = {};
    TGraphErrors* grV2sub4pos[20] = {};
    TGraphErrors* grV2sub2neg[20] = {};
    TGraphErrors* grV2sub4neg[20] = {};

    pPbGr(TFile* f) {
        for ( int n = 2; n < 7; n++ ) {
            for ( int c = 6; c < 10; c++ ) {
                gr_pTGap[n][c] = (TGraphErrors*) f->Get(Form("grV0Gap%i_%i", n, c));
                grH_pTGap[n][c]   = (TGraphErrors*) f->Get(Form("grHV0Gap%i_%i", n, c));
                for ( int np = 0; np < 4; np++ ) {
                    gr_pT[n][np][c] = (TGraphErrors*) f->Get(Form("grV0%i%i_%i", n, np, c));
                }
            }
        }

        for ( int c = 6; c < 10; c++ ) {
            grV2sub2[c] = (TGraphErrors*) f->Get(Form("grV0v2sub2_%i", c));
            grV2sub4[c] = (TGraphErrors*) f->Get(Form("grV0v2sub4_%i", c));
            grV2sub2pos[c] = (TGraphErrors*) f->Get(Form("grV0v2sub2pos_%i", c));
            grV2sub4pos[c] = (TGraphErrors*) f->Get(Form("grV0v2sub4pos_%i", c));
            grV2sub2neg[c] = (TGraphErrors*) f->Get(Form("grV0v2sub2neg_%i", c));
            grV2sub4neg[c] = (TGraphErrors*) f->Get(Form("grV0v2sub4neg_%i", c));
        }
    };

    void Write(TFile *f) {
        f->cd();
        for ( int n = 2; n < 7; n++ ) {
            for ( int c = 6; c < 10; c++ ) {
                gr_pTGap[n][c] ->Write(Form("grV0Gap%i_%i", n, c));
                grH_pTGap[n][c]->Write(Form("grHV0Gap%i_%i", n, c));
                for ( int np = 0; np < 4; np++ ) {
                    gr_pT[n][np][c]->Write(Form("grV0%i%i_%i", n, np, c));
                }
            }
        }

        for ( int c = 6; c < 10; c++ ) {
            grV2sub2[c]   ->Write(Form("grV0v2sub2_%i", c));
            grV2sub4[c]   ->Write(Form("grV0v2sub4_%i", c));
            grV2sub2pos[c]->Write(Form("grV0v2sub2pos_%i", c));
            grV2sub4pos[c]->Write(Form("grV0v2sub4pos_%i", c));
            grV2sub2neg[c]->Write(Form("grV0v2sub2neg_%i", c));
            grV2sub4neg[c]->Write(Form("grV0v2sub4neg_%i", c));
        }
    };
} pPbGr;

void merge(TGraphErrors* gr1, TGraphErrors* gr2) {
    int N = gr1->GetN();
    for ( int i = 0; i < N; i++ ) {
        double y1 = gr1->GetY()[i];
        double y2 = gr2->GetY()[i];
        double e1 = gr1->GetEY()[i];
        double e2 = gr2->GetEY()[i];

        gr1->GetY()[i] = (y1/e1/e1 + y2/e2/e2) / (1./e1/e1 + 1./e2/e2);
        gr1->GetEY()[i] = sqrt(1./e1/e1 + 1./e2/e2) / (1./e1/e1 + 1./e2/e2);
    }
    return;
};

void pPb_merge( string s1 = "pPb_Ks2.root", string s2 = "pPb_Ks2_reverse.root", string ssave = "pPb_Ks2_merged2.root" )
{
    TFile * f1 = new TFile(s1.c_str());
    TFile * f2 = new TFile(s2.c_str());

    pPbGr gr1(f1);
    pPbGr gr2(f2);

    for ( int n = 2; n < 7; n++ ) {
        for ( int c = 6; c < 10; c++ ) {
            merge( gr1.gr_pTGap[n][c],  gr2.gr_pTGap[n][c] );
            merge( gr1.grH_pTGap[n][c], gr2.grH_pTGap[n][c] );
            for ( int np = 0; np < 4; np++ ) {
                merge( gr1.gr_pT[n][np][c], gr2.gr_pT[n][np][c] );
            }
        }
    }
    for ( int c = 6; c < 10; c++ ) {
        merge( gr1.grV2sub2[c], gr2.grV2sub2[c] );
        merge( gr1.grV2sub4[c], gr2.grV2sub4[c] );

        merge( gr1.grV2sub2pos[c], gr2.grV2sub2neg[c] );
        merge( gr1.grV2sub2neg[c], gr2.grV2sub2pos[c] );

        merge( gr1.grV2sub4pos[c], gr2.grV2sub4neg[c] );
        merge( gr1.grV2sub4neg[c], gr2.grV2sub4pos[c] );
    }

    TFile * fsave = new TFile(ssave.c_str(), "recreate");
    gr1.Write(fsave);
}
