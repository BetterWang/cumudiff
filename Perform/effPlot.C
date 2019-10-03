
{
    TFile * fstd   = new TFile("Lm_Hyjet_eff_std.root");
    TFile * ftest2 = new TFile("Lm_Hydjet_eff_test2.root");

    TH1D * hEta_std  = (TH1D*) fstd  ->Get("hEff_eta");
    TH1D * hEta_test2= (TH1D*) ftest2->Get("hEff_eta");

    TH1D * hPt_std  = (TH1D*) fstd  ->Get("hEff_pT");
    TH1D * hPt_test2= (TH1D*) ftest2->Get("hEff_pT");

    hEta_std  ->SetMarkerStyle(kFullSquare);
    hEta_std  ->SetMarkerColor(kRed);
    hEta_std  ->SetLineColor(kRed);
    hPt_std   ->SetMarkerStyle(kFullSquare);
    hPt_std   ->SetMarkerColor(kRed);
    hPt_std   ->SetLineColor(kRed);

    hEta_test2->SetMarkerStyle(kOpenCircle);
    hEta_test2->SetMarkerColor(kBlue);
    hEta_test2->SetLineColor(kBlue);
    hPt_test2 ->SetMarkerStyle(kOpenCircle);
    hPt_test2 ->SetMarkerColor(kBlue);
    hPt_test2 ->SetLineColor(kBlue);

    TCanvas * ceta = new TCanvas("ceta", "ceta", 800, 600);
    TCanvas * cpt  = new TCanvas("cpt",   "cpt", 800, 600);

    ceta->cd();
    hEta_std->GetXaxis()->SetRangeUser(-1.2, 1.2);
    hEta_std->GetYaxis()->SetRangeUser(0., 0.02);
    hEta_std->SetTitle(";#eta;Efficiency");
    hEta_std->Draw();
    hEta_test2->Draw("same");

    cpt->cd();
    hPt_std->GetXaxis()->SetRangeUser(1.8, 8.0);
    hPt_std->GetYaxis()->SetRangeUser(0., 0.05);
    hPt_std->SetTitle(";p_{T};Efficiency");
    hPt_std->Draw();
    hPt_test2->Draw("same");

    ceta->SaveAs("Hydjet_eta_eff.pdf");
    cpt->SaveAs("Hydjet_pt_eff.pdf");
}
