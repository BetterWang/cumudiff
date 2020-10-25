#include "../../../style.h"

//                  0             1             2               3               4               5
int color_list[] = {kRed,         kBlue,        kBlack,        kBlue,         kRed,           kBlack};
int style_list[] = {kOpenCircle,  kOpenSquare,  kOpenCircle,   kOpenCircle,   kOpenSquare,    kOpenSquare};

void plotSig3(string s = "SigLM.root:Sig/hSignificance_05_10_70_85;SigLMC.root:Sig/hSignificance_05_10_70_85", string fout = "test.pdf")
{
    stringstream ss(s);

    std::vector<string> vs;
    while( ss.good() ) {
        string sub;
        getline( ss, sub, ';' );
        vs.push_back( sub );
    }

    std::vector<TH1D*> grs;
    int idx = 0;
    double max_ = 0;
    for ( auto it : vs ) {
        auto pos = it.find(':');
        auto sname = it.substr(0, pos);
        auto sgr   = it.substr(pos+1);

        TFile * f = new TFile(sname.c_str());
        TH1D* gr = (TH1D*) f->Get(sgr.c_str());

//        gr->SetMarkerStyle( style_list[idx] );
        gr->SetMarkerColor( color_list[idx] );
        gr->SetLineColor( color_list[idx] );
//        gr->SetMarkerSize( 2 );

        gr->Smooth();
        gr->GetXaxis()->SetRange(80, 150);
        grs.push_back(gr);
        max_ = max(max_, gr->GetMaximum());
        idx++;
    }

    SetStyle();
    TCanvas * cPA = MakeCanvas("cPA", "cPA", 800, 600);;

    for ( int i = 0; i < grs.size(); i++ ) {
        TH1D* h = grs[i];
        if ( i==0 ) {
            h->SetMaximum(max_ * 1.1);
            h->Draw("hist");
        } else {
            h->Draw("histsame");
        }
    }
    cPA->SaveAs(fout.c_str());
}
