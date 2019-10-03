
{
    //TFile * f = new TFile("Lm_Hyjet_eff_test2dpt4.root");
    TFile * f = new TFile("Lm_Hyjet_eff_stddpt4.root");

    TH1D * hAcc_eta_0_20 = (TH1D*) f->Get("hAcc_eta_0_20");
    TH1D * hEff_eta_0_20 = (TH1D*) f->Get("hEff_eta_0_20");
    TH1D * hREC_eta_0_20 = (TH1D*) f->Get("hREC_eta_0_20");
    TH1D * hAcc_eta_20_60 = (TH1D*) f->Get("hAcc_eta_20_60");
    TH1D * hEff_eta_20_60 = (TH1D*) f->Get("hEff_eta_20_60");
    TH1D * hREC_eta_20_60 = (TH1D*) f->Get("hREC_eta_20_60");

    TH1D * hAcc_pT12_0_20 = (TH1D*) f->Get("hAcc_pT12_0_20");
    TH1D * hEff_pT12_0_20 = (TH1D*) f->Get("hEff_pT12_0_20");
    TH1D * hREC_pT12_0_20 = (TH1D*) f->Get("hREC_pT12_0_20");
    TH1D * hAcc_pT12_20_60 = (TH1D*) f->Get("hAcc_pT12_20_60");
    TH1D * hEff_pT12_20_60 = (TH1D*) f->Get("hEff_pT12_20_60");
    TH1D * hREC_pT12_20_60 = (TH1D*) f->Get("hREC_pT12_20_60");

    hAcc_eta_0_20 ->SetMarkerStyle(kOpenSquare);
    hEff_eta_0_20 ->SetMarkerStyle(kOpenSquare);
    hREC_eta_0_20 ->SetMarkerStyle(kOpenSquare);
    hAcc_eta_20_60->SetMarkerStyle(kOpenCircle);
    hEff_eta_20_60->SetMarkerStyle(kOpenCircle);
    hREC_eta_20_60->SetMarkerStyle(kOpenCircle);
    hAcc_eta_0_20 ->SetMarkerColor(kBlue);
    hEff_eta_0_20 ->SetMarkerColor(kBlue);
    hREC_eta_0_20 ->SetMarkerColor(kBlue);
    hAcc_eta_20_60->SetMarkerColor(kRed);
    hEff_eta_20_60->SetMarkerColor(kRed);
    hREC_eta_20_60->SetMarkerColor(kRed);
    hAcc_eta_0_20 ->SetLineColor(kBlue);
    hEff_eta_0_20 ->SetLineColor(kBlue);
    hREC_eta_0_20 ->SetLineColor(kBlue);
    hAcc_eta_20_60->SetLineColor(kRed);
    hEff_eta_20_60->SetLineColor(kRed);
    hREC_eta_20_60->SetLineColor(kRed);

    hAcc_pT12_0_20 ->SetMarkerStyle(kOpenSquare);
    hEff_pT12_0_20 ->SetMarkerStyle(kOpenSquare);
    hREC_pT12_0_20 ->SetMarkerStyle(kOpenSquare);
    hAcc_pT12_20_60->SetMarkerStyle(kOpenCircle);
    hEff_pT12_20_60->SetMarkerStyle(kOpenCircle);
    hREC_pT12_20_60->SetMarkerStyle(kOpenCircle);
    hAcc_pT12_0_20 ->SetMarkerColor(kBlue);
    hEff_pT12_0_20 ->SetMarkerColor(kBlue);
    hREC_pT12_0_20 ->SetMarkerColor(kBlue);
    hAcc_pT12_20_60->SetMarkerColor(kRed);
    hEff_pT12_20_60->SetMarkerColor(kRed);
    hREC_pT12_20_60->SetMarkerColor(kRed);
    hAcc_pT12_0_20 ->SetLineColor(kBlue);
    hEff_pT12_0_20 ->SetLineColor(kBlue);
    hREC_pT12_0_20 ->SetLineColor(kBlue);
    hAcc_pT12_20_60->SetLineColor(kRed);
    hEff_pT12_20_60->SetLineColor(kRed);
    hREC_pT12_20_60->SetLineColor(kRed);

    TCanvas * ceta = new TCanvas("ceta", "ceta", 800, 600);
    hAcc_eta_0_20->GetXaxis()->CenterTitle();
    hAcc_eta_0_20->GetYaxis()->CenterTitle();
    hAcc_eta_0_20->GetXaxis()->SetRangeUser(-1.2, 1.2);
    hAcc_eta_0_20->GetYaxis()->SetRangeUser(0, 1.0);
    hAcc_eta_0_20->SetTitle(";#eta;Acceptance");
    hAcc_eta_0_20->Draw();
    hAcc_eta_20_60->Draw("same");
    TLegend * leg = new TLegend(0.5, 0.75, 0.86, 0.92);
    leg->AddEntry(hAcc_eta_0_20,   "0-20% 1.8<p_{T}<8.5", "p");
    leg->AddEntry(hAcc_eta_20_60, "20-60% 1.8<p_{T}<8.5", "p");
    leg->Draw();
    ceta->SaveAs("Acc_eta.pdf");


    ///////
    hREC_eta_0_20->GetXaxis()->CenterTitle();
    hREC_eta_0_20->GetYaxis()->CenterTitle();
    hREC_eta_0_20->GetXaxis()->SetRangeUser(-1.2, 1.2);
    hREC_eta_0_20->GetYaxis()->SetRangeUser(0, 0.06);
    hREC_eta_0_20->SetTitle(";#eta;RECO Efficiency");
    hREC_eta_0_20->Draw();
    hREC_eta_20_60->Draw("same");
    leg->Draw();
    ceta->SaveAs("REC_eta.pdf");

    ///////
    hEff_eta_0_20->GetXaxis()->CenterTitle();
    hEff_eta_0_20->GetYaxis()->CenterTitle();
    hEff_eta_0_20->GetXaxis()->SetRangeUser(-1.2, 1.2);
    hEff_eta_0_20->GetYaxis()->SetRangeUser(0, 0.02);
    hEff_eta_0_20->SetTitle(";#eta;Total Efficiency");
    hEff_eta_0_20->Draw();
    hEff_eta_20_60->Draw("same");
    leg->Draw();
    ceta->SaveAs("Eff_eta.pdf");


    //////////
    hAcc_pT12_0_20->GetXaxis()->CenterTitle();
    hAcc_pT12_0_20->GetYaxis()->CenterTitle();
    hAcc_pT12_0_20->GetXaxis()->SetRangeUser(1.8, 8.5);
    hAcc_pT12_0_20->GetYaxis()->SetRangeUser(0, 1.4);
    hAcc_pT12_0_20->SetTitle(";p_{T};Acceptance");
    hAcc_pT12_0_20->Draw();
    hAcc_pT12_20_60->Draw("same");
    TLegend * leg1 = new TLegend(0.15, 0.75, 0.46, 0.92);
    leg1->AddEntry(hAcc_pT12_0_20,   "0-20% |#eta|<1.2", "p");
    leg1->AddEntry(hAcc_pT12_20_60, "20-60% |#eta|<1.2", "p");
    leg1->Draw();
    ceta->SaveAs("Acc_pT.pdf");


    //////////
    hREC_pT12_0_20->GetXaxis()->CenterTitle();
    hREC_pT12_0_20->GetYaxis()->CenterTitle();
    hREC_pT12_0_20->GetXaxis()->SetRangeUser(1.8, 8.5);
    hREC_pT12_0_20->GetYaxis()->SetRangeUser(0, 0.1);
    hREC_pT12_0_20->SetTitle(";p_{T};RECO Efficiency");
    hREC_pT12_0_20->Draw();
    hREC_pT12_20_60->Draw("same");
    leg1->Draw();
    ceta->SaveAs("REC_pT.pdf");


    //////////
    hEff_pT12_0_20->GetXaxis()->CenterTitle();
    hEff_pT12_0_20->GetYaxis()->CenterTitle();
    hEff_pT12_0_20->GetXaxis()->SetRangeUser(1.8, 8.5);
    hEff_pT12_0_20->GetYaxis()->SetRangeUser(0, 0.1);
    hEff_pT12_0_20->SetTitle(";p_{T};Total Efficiency");
    hEff_pT12_0_20->Draw();
    hEff_pT12_20_60->Draw("same");
    leg1->Draw();
    ceta->SaveAs("Eff_pT.pdf");
//    TCanvas * cpt  = new TCanvas("cpt",   "cpt", 800, 600);

}
