#include "../../style.h"

//                  0             1             2               3               4               5
int color_list[] = {kRed,         kBlue,        kBlack,        kBlue,         kRed,           kBlack};
int style_list[] = {kOpenCircle,  kOpenSquare,  kOpenCircle,   kOpenCircle,   kOpenSquare,    kOpenSquare};


TGraphErrors* getRatio(TGraphErrors* gr1, TGraphErrors* gr2, TString options = "correlate")
{
    TGraphErrors * gr = new TGraphErrors(gr1->GetN());
    gr->SetMarkerStyle( gr1->GetMarkerStyle() );
    gr->SetMarkerColor( gr1->GetMarkerColor() );

    gr->SetLineStyle( gr1->GetLineStyle() );
    gr->SetLineColor( gr1->GetLineColor() );

    cout << " -> getRatio N1 = " << gr1->GetN() << " N2 = " << gr2->GetN() << endl;
    for ( int i = 0; i < gr1->GetN(); i++ ) {
        gr->GetX()[i] = gr1->GetX()[i];
        gr->GetY()[i] = gr1->GetY()[i] / gr2->GetY()[i];
        double y1 = gr1->GetY()[i];
        double y2 = gr2->GetY()[i];
        double e1 = gr1->GetEY()[i];
        double e2 = gr2->GetEY()[i];

//        cout << " ---> i = " << i << " X = " << gr->GetX()[i] << " Y1 = " << gr1->GetY()[i] << " Y2 = " << gr2->GetY()[i] << " Y = " << gr->GetY()[i] << endl;

        if ( options.Contains("correlate") ) {
            gr->GetEY()[i] = sqrt( abs(e1*e1/y1/y1 + e2*e2/y2/y2 - 2*e1*e1/y1/y2) ) * y1 / y2;
        } else {
            gr->GetEY()[i] = sqrt( e1*e1/y1/y1 + e2*e2/y2/y2 );
        }
    }
    return gr;
}



void plotS(
        string s = "pPb_Ks2.root:grV0v2sub4pos_8;pPb_Ks2_reverse.root:grV0v2sub4neg_8",
        string sl = "K_{S}^{0} pPb v_{2}{4} 0.<y<1.;K_{S}^{0} Pbp v_{2}{4} -1.<y<0.",
        string st = "185 #leq N_{trk}^{offline} < 250",
        string save = "Ks_v24_Pb",
        int sratio = -1,
        double delta = 0.9,
        int dropPoint = 0,
        TString options = "correlate"
        )
{
    stringstream ss(s);
    stringstream ssl(sl);

    std::vector<string> vs;
    std::vector<string> vl;
    while( ss.good() ) {
        string sub;
        getline( ss, sub, ';' );
        vs.push_back( sub );
    }
    while( ssl.good() ) {
        string sub;
        getline( ssl, sub, ';' );
        vl.push_back( sub );
    }

    std::vector<TGraphErrors*> grs;
    int idx = 0;
    for ( auto it : vs ) {
        auto pos = it.find(':');
        auto sname = it.substr(0, pos);
        auto sgr   = it.substr(pos+1);

        TFile * f = new TFile(sname.c_str());
        TGraphErrors* gr = (TGraphErrors*) f->Get(sgr.c_str());
        if ( gr == nullptr ) {
            cout << "!!! -> nullptr " << sname << " : " << sgr <<endl;
        }

        gr->SetMarkerStyle( style_list[idx] );
        gr->SetMarkerColor( color_list[idx] );
        gr->SetLineColor( color_list[idx] );
        gr->SetMarkerSize( 2 );

        for ( int i = 0; i < dropPoint; i++ ) {
            gr->RemovePoint(0);
        }

        grs.push_back(gr);
        idx++;
    }

    SetStyle();
    TCanvas * cPA = MakeCanvas("cPA", "cPA", 800, 600);;
    TH2D * hframePt = new TH2D("hframePt", "", 1, 0, 8.5, 1, -0.05, 0.45);
    InitHist(hframePt, "p_{T}", "v_{2}");

    TLegend * legPA = new TLegend(0.19, 0.60, 0.35 , 0.94);
    legPA->SetFillColor(kWhite);
    legPA->SetTextFont(42);
    legPA->SetTextSize(0.05);
    legPA->SetBorderSize(0);

	TLatex latexS;
	latexS.SetTextFont(43);
	latexS.SetTextSize(28);
	latexS.SetTextAlign(13);

    hframePt->Draw();
    TLine * line0 = new TLine(0, 0, 8.5, 0);
    line0->Draw();
    for ( int i = 0; i < grs.size(); i++ ) {
        TGraphErrors* gr = grs[i];
        gr->Draw("p");
        legPA->AddEntry(gr, vl[i].c_str(), "p");
    }
    legPA->Draw();
    latexS.DrawLatexNDC(0.60, 0.90, st.c_str());

    cPA->SaveAs( (save+".pdf").c_str() );

    cPA->SetGridy();
    if ( sratio >= 0 ) {
        TH2D * hframePtR = new TH2D("hframePtR", "", 1, 0, 8.5, 1, 1.-delta, 1.+delta);
        InitHist(hframePtR, "p_{T}", "Ratio");

        hframePtR->Draw();
        for ( int i = 0; i < grs.size(); i++ ) {
            if ( i == sratio ) continue;

            TGraphErrors * r = getRatio( grs[i], grs[sratio], options );
            r->Draw("psame");
        }
        latexS.DrawLatexNDC(0.60, 0.90, st.c_str());
        cPA->SaveAs( (save+"_Ratio.pdf").c_str() );
    }
}

