#include "../../../tdrstyle.C"

void massPlot2(TString fname = "KS/hMassMid_2_8.root", TString fsave = "test.pdf")
{
    setTDRStyle();
//    tdrStyle->SetPadLeftMargin(0.12);
    tdrStyle->SetPadRightMargin(0.04);
    bool bKS = fname.Contains("KS");
    TFile * f = new TFile(fname.Data());
    TH1D * hist = (TH1D*) f->Get("hmass");
    TF1 * func = (TF1*) f->Get("func");
    TF1 * func_bckgnd = (TF1*) f->Get("func_bckgnd");
    TF1 * func_signal = (TF1*) f->Get("func_signal");

    TCanvas* c = new TCanvas("c", "c", 800, 600);
    double mass1 = bKS?0.43:1.08;
    double mass2 = bKS?0,565:1.16;
    func->SetRange(mass1, mass2);
    func_bckgnd->SetRange(mass1, mass2);
    func_signal->SetRange(mass1, mass2);

    hist->SetMarkerStyle(kFullCircle);

    hist->SetXTitle(bKS?"#pi^{+}#pi^{-} invariant mass (GeV)":
                        "p#pi^{-}(#bar{p}#pi^{+}) invariant mass (GeV)");
    hist->SetYTitle("Entries / 0.5 MeV");
    hist->GetXaxis()->CenterTitle();
    hist->GetYaxis()->CenterTitle();
    hist->GetYaxis()->SetMaxDigits(6);
    hist->GetYaxis()->SetTitleOffset(1.5);
    hist->SetMinimum(0);
    cout << "Title: " << hist->GetTitle() << endl;
    char str1[16];
    int cent1, cent2;
    float pt1, pt2;
    sscanf(hist->GetTitle(), "%s %d-%d, %f-%f", str1, &cent1, &cent2, &pt1, &pt2);
    cout << " converted to " << cent1 << " " << cent2 << " " << pt1 << " " << pt2 << endl;

    func->SetLineColor(kBlue);
    func_bckgnd->SetLineColor(kRed);

    hist->Draw("p");
    func->Draw("csame");
    func_bckgnd->Draw("csame");

    TLatex latexS;
    latexS.SetTextFont(43);
    latexS.SetTextSize(22);
    latexS.SetTextAlign(13);

    latexS.DrawLatexNDC(0.16, 0.99, "#bf{CMS}");
    latexS.DrawLatexNDC(0.78, 0.99, "PbPb 5.02 TeV");

    latexS.DrawLatexNDC(0.24, 0.91, bKS?"K_{S}^{0}":"#Lambda/#bar{#Lambda}");
    latexS.DrawLatexNDC(0.24, 0.85, Form("Cent. %d-%d%%", cent1/2, cent2/2));
    latexS.DrawLatexNDC(0.24, 0.80, Form("%.1f < p_{T} < %.1f GeV", pt1, pt2));
    latexS.DrawLatexNDC(0.24, 0.74, "|#it{y} | < 1.");

    TLegend * leg = new TLegend(0.65, 0.70, 0.95, 0.90);
    leg->SetFillColor(kWhite);
    leg->SetTextFont(42);
    leg->SetTextSize(0.05);
    leg->SetBorderSize(0);

    leg->AddEntry(hist, "Data", "p");
    leg->AddEntry(func, "Fit", "l");
    leg->AddEntry(func_bckgnd, "Background", "l");

    leg->Draw();

    c->SaveAs(fsave.Data());
}
