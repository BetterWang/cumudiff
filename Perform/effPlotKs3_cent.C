
{
    //TFile * f = new TFile("Ks_Hyjet_eff_MVAMCFull.root");
    //TFile * f = new TFile("Ks_Hyjet_eff_MVAMCFullD4.root");
    TFile * f = new TFile("Ks_Hyjet_eff_MVAMCFull250D4_115.root");

    TH1D * hAcc_eta_0_10 = (TH1D*) f->Get("hAcc_eta_0_10");
    TH1D * hEff_eta_0_10 = (TH1D*) f->Get("hEff_eta_0_10");
    TH1D * hREC_eta_0_10 = (TH1D*) f->Get("hREC_eta_0_10");
    TH1D * hFak_eta_0_10 = (TH1D*) f->Get("hFak_eta_0_10");
    TH1D * hAcc_eta_10_30 = (TH1D*) f->Get("hAcc_eta_10_30");
    TH1D * hEff_eta_10_30 = (TH1D*) f->Get("hEff_eta_10_30");
    TH1D * hREC_eta_10_30 = (TH1D*) f->Get("hREC_eta_10_30");
    TH1D * hFak_eta_10_30 = (TH1D*) f->Get("hFak_eta_10_30");
    TH1D * hAcc_eta_30_50 = (TH1D*) f->Get("hAcc_eta_30_50");
    TH1D * hEff_eta_30_50 = (TH1D*) f->Get("hEff_eta_30_50");
    TH1D * hREC_eta_30_50 = (TH1D*) f->Get("hREC_eta_30_50");
    TH1D * hFak_eta_30_50 = (TH1D*) f->Get("hFak_eta_30_50");
    TH1D * hAcc_eta_50_80 = (TH1D*) f->Get("hAcc_eta_50_80");
    TH1D * hEff_eta_50_80 = (TH1D*) f->Get("hEff_eta_50_80");
    TH1D * hREC_eta_50_80 = (TH1D*) f->Get("hREC_eta_50_80");
    TH1D * hFak_eta_50_80 = (TH1D*) f->Get("hFak_eta_50_80");

    TH2D * hEff_0_10  = (TH2D*) f->Get("hEff_0_10");
    TH2D * hEff_10_30 = (TH2D*) f->Get("hEff_10_30");
    TH2D * hEff_30_50 = (TH2D*) f->Get("hEff_30_50");
    TH2D * hEff_50_80 = (TH2D*) f->Get("hEff_50_80");

    hAcc_eta_0_10 ->SetMarkerStyle(kOpenSquare);
    hEff_eta_0_10 ->SetMarkerStyle(kOpenSquare);
    hREC_eta_0_10 ->SetMarkerStyle(kOpenSquare);
    hFak_eta_0_10 ->SetMarkerStyle(kOpenSquare);
    hAcc_eta_10_30->SetMarkerStyle(kOpenCircle);
    hEff_eta_10_30->SetMarkerStyle(kOpenCircle);
    hREC_eta_10_30->SetMarkerStyle(kOpenCircle);
    hFak_eta_10_30->SetMarkerStyle(kOpenCircle);

    hAcc_eta_30_50->SetMarkerStyle(kOpenSquareDiagonal);
    hEff_eta_30_50->SetMarkerStyle(kOpenSquareDiagonal);
    hREC_eta_30_50->SetMarkerStyle(kOpenSquareDiagonal);
    hFak_eta_30_50->SetMarkerStyle(kOpenSquareDiagonal);

    hAcc_eta_50_80->SetMarkerStyle(kOpenFourTrianglesX);
    hEff_eta_50_80->SetMarkerStyle(kOpenFourTrianglesX);
    hREC_eta_50_80->SetMarkerStyle(kOpenFourTrianglesX);
    hFak_eta_50_80->SetMarkerStyle(kOpenFourTrianglesX);

    hAcc_eta_0_10 ->SetMarkerColor(kBlue);
    hEff_eta_0_10 ->SetMarkerColor(kBlue);
    hREC_eta_0_10 ->SetMarkerColor(kBlue);
    hFak_eta_0_10 ->SetMarkerColor(kBlue);
    hAcc_eta_10_30->SetMarkerColor(kRed);
    hEff_eta_10_30->SetMarkerColor(kRed);
    hREC_eta_10_30->SetMarkerColor(kRed);
    hFak_eta_10_30->SetMarkerColor(kRed);
    hAcc_eta_30_50->SetMarkerColor(kBlack);
    hEff_eta_30_50->SetMarkerColor(kBlack);
    hREC_eta_30_50->SetMarkerColor(kBlack);
    hFak_eta_30_50->SetMarkerColor(kBlack);
    hAcc_eta_50_80->SetMarkerColor(kGreen);
    hEff_eta_50_80->SetMarkerColor(kGreen);
    hREC_eta_50_80->SetMarkerColor(kGreen);
    hFak_eta_50_80->SetMarkerColor(kGreen);

    hAcc_eta_0_10 ->SetLineColor(kBlue);
    hEff_eta_0_10 ->SetLineColor(kBlue);
    hREC_eta_0_10 ->SetLineColor(kBlue);
    hFak_eta_0_10 ->SetLineColor(kBlue);
    hAcc_eta_10_30->SetLineColor(kRed);
    hEff_eta_10_30->SetLineColor(kRed);
    hREC_eta_10_30->SetLineColor(kRed);
    hFak_eta_10_30->SetLineColor(kRed);
    hAcc_eta_30_50->SetLineColor(kBlack);
    hEff_eta_30_50->SetLineColor(kBlack);
    hREC_eta_30_50->SetLineColor(kBlack);
    hFak_eta_30_50->SetLineColor(kBlack);
    hAcc_eta_50_80->SetLineColor(kGreen);
    hEff_eta_50_80->SetLineColor(kGreen);
    hREC_eta_50_80->SetLineColor(kGreen);
    hFak_eta_50_80->SetLineColor(kGreen);

    TH1D * hAcc_pT12_0_10 = (TH1D*) f->Get("hAcc_pT12_0_10");
    TH1D * hEff_pT12_0_10 = (TH1D*) f->Get("hEff_pT12_0_10");
    TH1D * hREC_pT12_0_10 = (TH1D*) f->Get("hREC_pT12_0_10");
    TH1D * hFak_pT12_0_10 = (TH1D*) f->Get("hFak_pT12_0_10");
    TH1D * hAcc_pT12_10_30 = (TH1D*) f->Get("hAcc_pT12_10_30");
    TH1D * hEff_pT12_10_30 = (TH1D*) f->Get("hEff_pT12_10_30");
    TH1D * hREC_pT12_10_30 = (TH1D*) f->Get("hREC_pT12_10_30");
    TH1D * hFak_pT12_10_30 = (TH1D*) f->Get("hFak_pT12_10_30");
    TH1D * hAcc_pT12_30_50 = (TH1D*) f->Get("hAcc_pT12_30_50");
    TH1D * hEff_pT12_30_50 = (TH1D*) f->Get("hEff_pT12_30_50");
    TH1D * hREC_pT12_30_50 = (TH1D*) f->Get("hREC_pT12_30_50");
    TH1D * hFak_pT12_30_50 = (TH1D*) f->Get("hFak_pT12_30_50");
    TH1D * hAcc_pT12_50_80 = (TH1D*) f->Get("hAcc_pT12_50_80");
    TH1D * hEff_pT12_50_80 = (TH1D*) f->Get("hEff_pT12_50_80");
    TH1D * hREC_pT12_50_80 = (TH1D*) f->Get("hREC_pT12_50_80");
    TH1D * hFak_pT12_50_80 = (TH1D*) f->Get("hFak_pT12_50_80");

    hAcc_pT12_0_10 ->SetMarkerStyle(kOpenSquare);
    hEff_pT12_0_10 ->SetMarkerStyle(kOpenSquare);
    hREC_pT12_0_10 ->SetMarkerStyle(kOpenSquare);
    hFak_pT12_0_10 ->SetMarkerStyle(kOpenSquare);
    hAcc_pT12_10_30->SetMarkerStyle(kOpenCircle);
    hEff_pT12_10_30->SetMarkerStyle(kOpenCircle);
    hREC_pT12_10_30->SetMarkerStyle(kOpenCircle);
    hFak_pT12_10_30->SetMarkerStyle(kOpenCircle);

    hAcc_pT12_30_50->SetMarkerStyle(kOpenSquareDiagonal);
    hEff_pT12_30_50->SetMarkerStyle(kOpenSquareDiagonal);
    hREC_pT12_30_50->SetMarkerStyle(kOpenSquareDiagonal);
    hFak_pT12_30_50->SetMarkerStyle(kOpenSquareDiagonal);

    hAcc_pT12_50_80->SetMarkerStyle(kOpenFourTrianglesX);
    hEff_pT12_50_80->SetMarkerStyle(kOpenFourTrianglesX);
    hREC_pT12_50_80->SetMarkerStyle(kOpenFourTrianglesX);
    hFak_pT12_50_80->SetMarkerStyle(kOpenFourTrianglesX);

    hAcc_pT12_0_10 ->SetMarkerColor(kBlue);
    hEff_pT12_0_10 ->SetMarkerColor(kBlue);
    hREC_pT12_0_10 ->SetMarkerColor(kBlue);
    hFak_pT12_0_10 ->SetMarkerColor(kBlue);
    hAcc_pT12_10_30->SetMarkerColor(kRed);
    hEff_pT12_10_30->SetMarkerColor(kRed);
    hREC_pT12_10_30->SetMarkerColor(kRed);
    hFak_pT12_10_30->SetMarkerColor(kRed);
    hAcc_pT12_30_50->SetMarkerColor(kBlack);
    hEff_pT12_30_50->SetMarkerColor(kBlack);
    hREC_pT12_30_50->SetMarkerColor(kBlack);
    hFak_pT12_30_50->SetMarkerColor(kBlack);
    hAcc_pT12_50_80->SetMarkerColor(kGreen);
    hEff_pT12_50_80->SetMarkerColor(kGreen);
    hREC_pT12_50_80->SetMarkerColor(kGreen);
    hFak_pT12_50_80->SetMarkerColor(kGreen);

    hAcc_pT12_0_10 ->SetLineColor(kBlue);
    hEff_pT12_0_10 ->SetLineColor(kBlue);
    hREC_pT12_0_10 ->SetLineColor(kBlue);
    hFak_pT12_0_10 ->SetLineColor(kBlue);
    hAcc_pT12_10_30->SetLineColor(kRed);
    hEff_pT12_10_30->SetLineColor(kRed);
    hREC_pT12_10_30->SetLineColor(kRed);
    hFak_pT12_10_30->SetLineColor(kRed);
    hAcc_pT12_30_50->SetLineColor(kBlack);
    hEff_pT12_30_50->SetLineColor(kBlack);
    hREC_pT12_30_50->SetLineColor(kBlack);
    hFak_pT12_30_50->SetLineColor(kBlack);
    hAcc_pT12_50_80->SetLineColor(kGreen);
    hEff_pT12_50_80->SetLineColor(kGreen);
    hREC_pT12_50_80->SetLineColor(kGreen);
    hFak_pT12_50_80->SetLineColor(kGreen);


    TCanvas * ceta = new TCanvas("ceta", "ceta", 800, 600);
    hAcc_eta_0_10->GetXaxis()->CenterTitle();
    hAcc_eta_0_10->GetYaxis()->CenterTitle();
    hAcc_eta_0_10->GetXaxis()->SetRangeUser(-2.5, 2.5);
    hAcc_eta_0_10->GetYaxis()->SetRangeUser(0, 1.8);
    hAcc_eta_0_10->SetTitle(";y;Acceptance");
    hAcc_eta_0_10->Draw("histpl");
    hAcc_eta_10_30->Draw("histplsame");
    hAcc_eta_30_50->Draw("histplsame");
    hAcc_eta_50_80->Draw("histplsame");
    TLegend * leg = new TLegend(0.5, 0.75, 0.86, 0.92);
    leg->AddEntry(hAcc_eta_0_10,   "0-10% 1.0<p_{T}<8.5", "p");
    leg->AddEntry(hAcc_eta_10_30, "10-30% 1.0<p_{T}<8.5", "p");
    leg->AddEntry(hAcc_eta_30_50, "30-50% 1.0<p_{T}<8.5", "p");
    leg->AddEntry(hAcc_eta_50_80, "50-80% 1.0<p_{T}<8.5", "p");
    leg->Draw();
    ceta->SaveAs("Ks_Acc_etaD4.pdf");
    ceta->SaveAs("Ks_Acc_etaD4.png");


    ///////
    hREC_eta_0_10->GetXaxis()->CenterTitle();
    hREC_eta_0_10->GetYaxis()->CenterTitle();
    hREC_eta_0_10->GetXaxis()->SetRangeUser(-2.5, 2.5);
    hREC_eta_0_10->GetYaxis()->SetRangeUser(0, 0.06);
    hREC_eta_0_10->SetTitle(";y;RECO Efficiency");
    hREC_eta_0_10->Draw("histpl");
    hREC_eta_10_30->Draw("histplsame");
    hREC_eta_30_50->Draw("histplsame");
    hREC_eta_50_80->Draw("histplsame");
    leg->Draw();
    ceta->SaveAs("Ks_REC_etaD4.pdf");
    ceta->SaveAs("Ks_REC_etaD4.png");

    ///////
    hEff_eta_0_10->GetXaxis()->CenterTitle();
    hEff_eta_0_10->GetYaxis()->CenterTitle();
    hEff_eta_0_10->GetXaxis()->SetRangeUser(-2.5, 2.5);
    hEff_eta_0_10->GetYaxis()->SetRangeUser(0, 0.06);
    hEff_eta_0_10->SetTitle(";y;Total Efficiency");
    hEff_eta_0_10->Draw("histpl");
    hEff_eta_10_30->Draw("histplsame");
    hEff_eta_30_50->Draw("histplsame");
    hEff_eta_50_80->Draw("histplsame");
    leg->Draw();
    ceta->SaveAs("Ks_Eff_etaD4.pdf");
    ceta->SaveAs("Ks_Eff_etaD4.png");

    //////// Fak
    hFak_eta_0_10->GetXaxis()->CenterTitle();
    hFak_eta_0_10->GetYaxis()->CenterTitle();
    hFak_eta_0_10->GetXaxis()->SetRangeUser(-2.5, 2.5);
    hFak_eta_0_10->GetYaxis()->SetRangeUser(0, 1.0);
    hFak_eta_0_10->SetTitle(";y;Fake Rate");
    hFak_eta_0_10->Draw("histpl");
    hFak_eta_10_30->Draw("histplsame");
    hFak_eta_30_50->Draw("histplsame");
    hFak_eta_50_80->Draw("histplsame");
    leg->Draw();
    ceta->SaveAs("Ks_Fak_etaD4.pdf");
    ceta->SaveAs("Ks_Fak_etaD4.png");

    //////////
    hAcc_pT12_0_10->GetXaxis()->CenterTitle();
    hAcc_pT12_0_10->GetYaxis()->CenterTitle();
    hAcc_pT12_0_10->GetXaxis()->SetRangeUser(1.0, 8.5);
    hAcc_pT12_0_10->GetYaxis()->SetRangeUser(0, 1.4);
    hAcc_pT12_0_10->SetTitle(";p_{T};Acceptance");
    hAcc_pT12_0_10->Draw("histpl");
    hAcc_pT12_10_30->Draw("histplsame");
    hAcc_pT12_30_50->Draw("histplsame");
    hAcc_pT12_50_80->Draw("histplsame");
    TLegend * leg1 = new TLegend(0.15, 0.75, 0.46, 0.92);
    leg1->AddEntry(hAcc_pT12_0_10,   "0-10% |y|<1.0", "p");
    leg1->AddEntry(hAcc_pT12_10_30, "10-30% |y|<1.0", "p");
    leg1->AddEntry(hAcc_pT12_30_50, "30-50% |y|<1.0", "p");
    leg1->AddEntry(hAcc_pT12_50_80, "50-80% |y|<1.0", "p");
    leg1->Draw();
    ceta->SaveAs("Ks_Acc_pTD4.pdf");
    ceta->SaveAs("Ks_Acc_pTD4.png");


    //////////
    hREC_pT12_0_10->GetXaxis()->CenterTitle();
    hREC_pT12_0_10->GetYaxis()->CenterTitle();
    hREC_pT12_0_10->GetXaxis()->SetRangeUser(1.0, 8.5);
    hREC_pT12_0_10->GetYaxis()->SetRangeUser(0, 0.2);
    hREC_pT12_0_10->SetTitle(";p_{T};RECO Efficiency");
    hREC_pT12_0_10->Draw("histpl");
    hREC_pT12_10_30->Draw("histplsame");
    hREC_pT12_30_50->Draw("histplsame");
    hREC_pT12_50_80->Draw("histplsame");
    leg1->Draw();
    ceta->SaveAs("Ks_REC_pTD4.pdf");
    ceta->SaveAs("Ks_REC_pTD4.png");


    //////////
    hEff_pT12_0_10->GetXaxis()->CenterTitle();
    hEff_pT12_0_10->GetYaxis()->CenterTitle();
    hEff_pT12_0_10->GetXaxis()->SetRangeUser(1.0, 8.5);
    hEff_pT12_0_10->GetYaxis()->SetRangeUser(0, 0.2);
    hEff_pT12_0_10->SetTitle(";p_{T};Total Efficiency");
    hEff_pT12_0_10->Draw("histpl");
    hEff_pT12_10_30->Draw("histplsame");
    hEff_pT12_30_50->Draw("histplsame");
    hEff_pT12_50_80->Draw("histplsame");
    leg1->Draw();
    ceta->SaveAs("Ks_Eff_pTD4.pdf");
    ceta->SaveAs("Ks_Eff_pTD4.png");

    //////////
    hFak_pT12_0_10->GetXaxis()->CenterTitle();
    hFak_pT12_0_10->GetYaxis()->CenterTitle();
    hFak_pT12_0_10->GetXaxis()->SetRangeUser(1.0, 8.5);
    hFak_pT12_0_10->GetYaxis()->SetRangeUser(0, 0.8);
    hFak_pT12_0_10->SetTitle(";p_{T};Fake Rate");
    hFak_pT12_0_10->Draw("histpl");
    hFak_pT12_10_30->Draw("histplsame");
    hFak_pT12_30_50->Draw("histplsame");
    hFak_pT12_50_80->Draw("histplsame");
    leg1->Draw();
    ceta->SaveAs("Ks_Fak_pTD4.pdf");
    ceta->SaveAs("Ks_Fak_pTD4.png");


    ///////////
    ceta->SetRightMargin(0.15);
    hEff_0_10->GetXaxis()->CenterTitle();
    hEff_0_10->GetYaxis()->CenterTitle();
    hEff_0_10->SetTitle(";p_{T};y");
    hEff_10_30->GetXaxis()->CenterTitle();
    hEff_10_30->GetYaxis()->CenterTitle();
    hEff_10_30->SetTitle(";p_{T};y");
    hEff_30_50->GetXaxis()->CenterTitle();
    hEff_30_50->GetYaxis()->CenterTitle();
    hEff_30_50->SetTitle(";p_{T};y");
    hEff_50_80->GetXaxis()->CenterTitle();
    hEff_50_80->GetYaxis()->CenterTitle();
    hEff_50_80->SetTitle(";p_{T};y");

    hEff_0_10->Draw("colztext");
    ceta->SaveAs("Ks_Eff2D_0_10D4.pdf");
    ceta->SaveAs("Ks_Eff2D_0_10D4.png");

    hEff_10_30->Draw("colztext");
    ceta->SaveAs("Ks_Eff2D_10_30D4.pdf");
    ceta->SaveAs("Ks_Eff2D_10_30D4.png");

    hEff_30_50->Draw("colztext");
    ceta->SaveAs("Ks_Eff2D_30_50D4.pdf");
    ceta->SaveAs("Ks_Eff2D_30_50D4.png");

    hEff_50_80->Draw("colztext");
    ceta->SaveAs("Ks_Eff2D_50_80D4.pdf");
    ceta->SaveAs("Ks_Eff2D_50_80D4.png");
}
