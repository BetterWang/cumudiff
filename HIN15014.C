#include "../../style.h"
#include "PbPb_header.h"

TGraphErrors * grQuanCumu[4][7] = {};

void HIN15014()
{
    TFile * f = new TFile("QuanCumu.root");
    for ( int np = 1; np < 4; np++ ) {
        for ( int c = 0; c < 7; c++ ) {
            grQuanCumu[np][c] = (TGraphErrors*) f->Get(Form("grV2%i_%i", 2*np+2, c));
        }
    }

    TLatex latexS;
    latexS.SetTextFont(43);
    latexS.SetTextSize(22);
    latexS.SetTextAlign(13);

    string centBins[] = {"0-5\%", "5-10\%", "10-20\%", "20-30\%", "30-40\%", "40-50\%", "50-60\%"};

    TCanvas * cPbPbV2 = MakeCanvas("cPbPbV2", "cPbPbV2", 1000, 500);
    makeMultiPanelCanvas(cPbPbV2, 4, 2, 0.0, 0., 0.2, 0.2, 0.01);
    //splitCanv4(cPbPbV2);
    TH2D * hframe_pt = new TH2D("hframe_pt", "hframe_pt", 1, 0.01, 8.5, 1, 0.01, 0.35);
    InitHist(hframe_pt, "p_{T}", "v_{2}");
    hframe_pt->GetYaxis()->SetTitleOffset(1.0);
    hframe_pt->GetXaxis()->SetTitleOffset(0.90);

    for ( int c = 1; c < 7; c++ ) {
        cPbPbV2->cd(c);
        hframe_pt->Draw();
        latexS.DrawLatexNDC(0.25, 0.94, (centBins[c]).c_str());

        grQuanCumu[1][c]->SetMarkerStyle(kOpenStar);
        grQuanCumu[1][c]->SetMarkerSize (2.);
        grQuanCumu[1][c]->SetMarkerColor(kBlue);
        grQuanCumu[1][c]->SetLineColor  (kBlue);

        grQuanCumu[2][c]->SetMarkerStyle(kFullCross);
        grQuanCumu[2][c]->SetMarkerSize (2.);
        grQuanCumu[2][c]->SetMarkerColor(kRed);
        grQuanCumu[2][c]->SetLineColor  (kRed);

        grQuanCumu[3][c]->SetMarkerStyle(kFullDiamond);
        grQuanCumu[3][c]->SetMarkerSize (2.);
        grQuanCumu[3][c]->SetMarkerColor(kGreen+2);
        grQuanCumu[3][c]->SetLineColor  (kGreen+2);

        grQuanCumu[1][c]->Draw("psame");
        grQuanCumu[2][c]->Draw("psame");
        grQuanCumu[3][c]->Draw("psame");
        cout << " c = " << c << " Nv24 = " << grQuanCumu[1][c]->GetN() << " Nv26 = " << grQuanCumu[2][c]->GetN() << " Nv28 = " << grQuanCumu[3][c]->GetN() << endl;
    }
    cPbPbV2->cd(7);
    hframe_pt->Draw();
    latexS.DrawLatexNDC(0.10, 0.94, "PbPb 5.02 TeV 2015");
    TLegend * legv2 = new TLegend(0.40, 0.45, 0.90, 0.80);
    legv2->AddEntry(grQuanCumu[1][1], "v_{2}{4}", "p");
    legv2->AddEntry(grQuanCumu[2][1], "v_{2}{6}", "p");
    legv2->AddEntry(grQuanCumu[3][1], "v_{2}{8}", "p");
    legv2->Draw();

    cPbPbV2->cd(8);
    hframe_pt->Draw();

    cPbPbV2->SaveAs("PbPb2015_v2.pdf");

    //
    TGraphErrors * grRatio64[7] = {};
    TGraphErrors * grRatio84[7] = {};
    TH2D * hframe_ratio = new TH2D("hframe_ratio", "hframe_ratio", 1, 0.01, 8.5, 1, 0.95, 1.05);
    InitHist(hframe_ratio, "p_{T}", "Ratio");
    hframe_ratio->GetYaxis()->SetTitleOffset(1.0);
    hframe_ratio->GetXaxis()->SetTitleOffset(0.90);

    TLine line1(0.1, 1., 8.5, 1.);
    for ( int c = 1; c < 7; c++ ) {
        cPbPbV2->cd(c);
        hframe_ratio->Draw();
        line1.Draw();
        latexS.DrawLatexNDC(0.25, 0.94, (centBins[c]).c_str());

        grRatio64[c] = getRatio( grQuanCumu[2][c], grQuanCumu[1][c] );
        grRatio84[c] = getRatio( grQuanCumu[3][c], grQuanCumu[1][c] );

        grRatio64[c]->SetMarkerStyle(kFullCross);
        grRatio64[c]->SetMarkerSize (2.);
        grRatio64[c]->SetMarkerColor(kRed);
        grRatio64[c]->SetLineColor  (kRed);

        grRatio84[c]->SetMarkerStyle(kFullDiamond);
        grRatio84[c]->SetMarkerSize (2.);
        grRatio84[c]->SetMarkerColor(kGreen+2);
        grRatio84[c]->SetLineColor  (kGreen+2);

        grRatio64[c]->Draw("psame");
        grRatio84[c]->Draw("psame");
    }
    cPbPbV2->cd(7);
    hframe_pt->Draw();
    latexS.DrawLatexNDC(0.10, 0.94, "PbPb 5.02 TeV 2015");
    TLegend * legv2ratio = new TLegend(0.40, 0.45, 0.90, 0.80);
    legv2ratio->AddEntry(grRatio64[1], "v_{2}{6}/v_{2}{4}", "p");
    legv2ratio->AddEntry(grRatio84[1], "v_{2}{8}/v_{2}{4}", "p");
    legv2ratio->Draw();

    cPbPbV2->cd(8);
    hframe_pt->Draw();


    cPbPbV2->SaveAs("PbPb2015_v2ratio.pdf");

//    f->Close();
}
