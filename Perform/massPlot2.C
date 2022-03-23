#include "../../../tdrstyle.C"

void massPlot2(TString fname = "KS/hMassMid_2_8.root", TString fsave = "test.pdf", bool bLog = false)
{
    setTDRStyle();
    tdrStyle->SetPadTopMargin(0.065);
    tdrStyle->SetPadLeftMargin(0.12);
    tdrStyle->SetPadRightMargin(0.04);
    tdrStyle->SetPadBottomMargin(0.14);
    bool bKS = fname.Contains("KS");
    TFile * f = new TFile(fname.Data());
    TH1D * hist = (TH1D*) f->Get("hmass");
    TF1 * func = (TF1*) f->Get("func");
    TF1 * func_bckgnd = (TF1*) f->Get("func_bckgnd");
    TF1 * func_signal = (TF1*) f->Get("func_signal");

    TCanvas* c = new TCanvas("c", "c", 800, 600);
    if ( bLog ) c->SetLogy();
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
    hist->GetYaxis()->SetMaxDigits(3);
    hist->GetYaxis()->SetTitleOffset(0.90);
    hist->GetYaxis()->SetTitleSize(0.07);
    hist->GetYaxis()->SetLabelSize(0.06);
    hist->GetXaxis()->SetTitleOffset(0.88);
    hist->GetXaxis()->SetTitleSize(0.07);
    hist->GetXaxis()->SetLabelSize(0.06);
    if ( bLog ) hist->SetMinimum(0.1);
    else        hist->SetMinimum(0);
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
    latexS.SetTextSize(26);
    latexS.SetTextAlign(13);

    latexS.DrawLatexNDC(0.23, 0.98, "#bf{CMS}");
    latexS.DrawLatexNDC(0.75, 0.98, "PbPb 5.02 TeV");

    TLatex latexL;
    latexL.SetTextFont(43);
    latexL.SetTextSize(26);
    latexL.SetTextAlign(13);
    latexL.DrawLatexNDC(0.20, 0.90, bKS?"K_{S}^{0}":"#Lambda/#bar{#Lambda}");
    latexL.DrawLatexNDC(0.20, 0.83, Form("Cent. %d-%d%%", cent1/2, cent2/2));
    latexL.DrawLatexNDC(0.20, 0.76, Form("%.1f < p_{T} < %.1f GeV", pt1, pt2));
    latexL.DrawLatexNDC(0.20, 0.69, "|#it{y} | < 1");

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

    TH1D * hpull = (TH1D*) hist->Clone("hpull");
    hpull->Reset();

    //for ( int i = hist->FindBin(bKS?0.492:1.1115); i < hist->FindBin(bKS?0.503:1.12); i++ ) {
    for ( int i = hist->FindBin(bKS?0.46:1.105); i < hist->FindBin(bKS?0.52:1.13); i++ ) {
    //for ( int i = 0; i < hist->GetNbinsX(); i++ ) {
        hpull->SetBinContent(i+1, (hist->GetBinContent(i+1) - func->Eval(hist->GetBinCenter(i+1))) / hist->GetBinError(i+1) );
    }
    hpull->SetYTitle("Pull");
    hpull->SetMinimum();
    hpull->SetMaximum();
    hpull->Draw("hist");

    c->SaveAs((fsave.Remove(fsave.Sizeof() - 5, 4) + "_pull.pdf").Data());
}
