#include "../../style.h"

void plotFsig()
{
    SetStyle();

    TFile * fsig = new TFile("Fsig.root");
    TH1D * hPAKs = (TH1D*) fsig->Get("pPb_V0_HM123456_eta1_merge/vectKsMassN185");
    TH1D * hPALm = (TH1D*) fsig->Get("pPb_V0_HM123456_eta1_merge/vectLmMassN185");

    TH1D * hAAKs = (TH1D*) fsig->Get("PbPb15_V0_rap_eta1_Cent_N185/vectKsMassN185");
    TH1D * hAALm = (TH1D*) fsig->Get("PbPb15_V0_rap_eta1_Cent2_N185/vectLmMassN185");

    TCanvas * cPA = MakeCanvas("cPA", "cPA", 800, 600);;
    TH2D * hframePt = new TH2D("hframePt", "", 1, 0, 8.5, 1, 0.80, 1.15);
    InitHist(hframePt, "p_{T}", "f_{sig}");
    hframePt->Draw();

    TLine * line = new TLine(0., 1., 8.5, 1.);
    line->Draw("same");

    hPAKs->SetMarkerStyle(kFullCircle);
    hPAKs->SetMarkerColor(kRed);
    hPAKs->SetLineColor(kRed);
    hPAKs->SetMarkerSize(2.);

    hPALm->SetMarkerStyle(kFullSquare);
    hPALm->SetMarkerColor(kBlue);
    hPALm->SetLineColor(kBlue);
    hPALm->SetMarkerSize(2.);

    hPAKs->Draw("psame");
    hPALm->Draw("psame");

    TLegend * legPA = new TLegend(0.16, 0.75, 0.35 , 0.94);
    legPA->SetFillColor(kWhite);
    legPA->SetTextFont(42);
    legPA->SetTextSize(0.05);
    legPA->SetBorderSize(0);

    legPA->AddEntry(hPAKs, "K_{s}", "p");
    legPA->AddEntry(hPALm, "#Lambda/#bar{#Lambda}", "p");
    legPA->Draw("same");

	TLatex latexS;
	latexS.SetTextFont(43);
	latexS.SetTextSize(28);
	latexS.SetTextAlign(13);

	latexS.DrawLatexNDC(0.35, 0.85, "CMS pPb 8.16 TeV 185 #leq N_{trk}^{offline} < 250");

    TCanvas * cAA = MakeCanvas("cAA", "cAA", 800, 600);;
    TH2D * hframePtAA = new TH2D("hframePtAA", "", 1, 0, 8.5, 1, 0.60, 1.15);
    InitHist(hframePtAA, "p_{T}", "f_{sig}");
    hframePtAA->Draw();
    line->Draw("same");

    hAAKs->SetMarkerStyle(kFullCircle);
    hAAKs->SetMarkerColor(kRed);
    hAAKs->SetLineColor(kRed);
    hAAKs->SetMarkerSize(2.);

    hAALm->SetMarkerStyle(kFullSquare);
    hAALm->SetMarkerColor(kBlue);
    hAALm->SetLineColor(kBlue);
    hAALm->SetMarkerSize(2.);

    hAAKs->Draw("psame");
    hAALm->Draw("psame");

    legPA->Draw("same");

	latexS.DrawLatexNDC(0.35, 0.85, "CMS PbPb 5.02 TeV 30-50%");

    cPA->SaveAs("fsig_pPb_185_Fsig.pdf");
    cAA->SaveAs("fsig_PbPb_30-50_Fsig.pdf");
}
