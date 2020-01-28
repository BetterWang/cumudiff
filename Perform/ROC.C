
void ROC(string s = "LM")
{
    TFile *f3, *f4, *f5, *f6, *f7, *f8;

    TH1D * MVA3_BDT250D3_rejBvsS;
    TH1D * MVA4_BDT250D3_rejBvsS;
    TH1D * MVA5_BDT250D3_rejBvsS;
    TH1D * MVA6_BDT250D3_rejBvsS;
    TH1D * MVA7_BDT250D3_rejBvsS;
    TH1D * MVA8_BDT250D3_rejBvsS;

    TH1D * MVA3_BDT250D4_rejBvsS;
    TH1D * MVA4_BDT250D4_rejBvsS;
    TH1D * MVA5_BDT250D4_rejBvsS;
    TH1D * MVA6_BDT250D4_rejBvsS;
    TH1D * MVA7_BDT250D4_rejBvsS;
    TH1D * MVA8_BDT250D4_rejBvsS;

    if ( s == "LM" ) {
        f3 = new TFile("TMVA3_HydjetMCTruth_MCBkg_LM.root");
        f4 = new TFile("TMVA4_HydjetMCTruth_MCBkg_LM.root");
        f5 = new TFile("TMVA5_HydjetMCTruth_MCBkg_LM.root");
        f6 = new TFile("TMVA6_HydjetMCTruth_MCBkg_LM.root");
        f7 = new TFile("TMVA7_HydjetMCTruth_MCBkg_LM.root");
        f8 = new TFile("TMVA8_HydjetMCTruth_MCBkg_LM.root");

        MVA3_BDT250D3_rejBvsS = (TH1D*) f3->Get("dataset3_full_LM/Method_BDT250_D3/BDT250_D3/MVA_BDT250_D3_rejBvsS");
        MVA4_BDT250D3_rejBvsS = (TH1D*) f4->Get("dataset4_full_LM/Method_BDT250_D3/BDT250_D3/MVA_BDT250_D3_rejBvsS");
        MVA5_BDT250D3_rejBvsS = (TH1D*) f5->Get("dataset5_full_LM/Method_BDT250_D3/BDT250_D3/MVA_BDT250_D3_rejBvsS");
        MVA6_BDT250D3_rejBvsS = (TH1D*) f6->Get("dataset6_full_LM/Method_BDT250_D3/BDT250_D3/MVA_BDT250_D3_rejBvsS");
        MVA7_BDT250D3_rejBvsS = (TH1D*) f7->Get("dataset7_full_LM/Method_BDT250_D3/BDT250_D3/MVA_BDT250_D3_rejBvsS");
        MVA8_BDT250D3_rejBvsS = (TH1D*) f8->Get("dataset8_full_LM/Method_BDT250_D3/BDT250_D3/MVA_BDT250_D3_rejBvsS");

        MVA3_BDT250D4_rejBvsS = (TH1D*) f3->Get("dataset3_full_LM/Method_BDT250_D4/BDT250_D4/MVA_BDT250_D4_rejBvsS");
        MVA4_BDT250D4_rejBvsS = (TH1D*) f4->Get("dataset4_full_LM/Method_BDT250_D4/BDT250_D4/MVA_BDT250_D4_rejBvsS");
        MVA5_BDT250D4_rejBvsS = (TH1D*) f5->Get("dataset5_full_LM/Method_BDT250_D4/BDT250_D4/MVA_BDT250_D4_rejBvsS");
        MVA6_BDT250D4_rejBvsS = (TH1D*) f6->Get("dataset6_full_LM/Method_BDT250_D4/BDT250_D4/MVA_BDT250_D4_rejBvsS");
        MVA7_BDT250D4_rejBvsS = (TH1D*) f7->Get("dataset7_full_LM/Method_BDT250_D4/BDT250_D4/MVA_BDT250_D4_rejBvsS");
        MVA8_BDT250D4_rejBvsS = (TH1D*) f8->Get("dataset8_full_LM/Method_BDT250_D4/BDT250_D4/MVA_BDT250_D4_rejBvsS");
    } else if ( s == "KS" ) {
        f3 = new TFile("TMVA3_HydjetMCTruth_MCBkg_KS.root");
        f4 = new TFile("TMVA4_HydjetMCTruth_MCBkg_KS.root");
        f5 = new TFile("TMVA5_HydjetMCTruth_MCBkg_KS.root");
        f6 = new TFile("TMVA6_HydjetMCTruth_MCBkg_KS.root");
        f7 = new TFile("TMVA7_HydjetMCTruth_MCBkg_KS.root");
        f8 = new TFile("TMVA8_HydjetMCTruth_MCBkg_KS.root");

        MVA3_BDT250D3_rejBvsS = (TH1D*) f3->Get("dataset3_full_KS/Method_BDT250_D3/BDT250_D3/MVA_BDT250_D3_rejBvsS");
        MVA4_BDT250D3_rejBvsS = (TH1D*) f4->Get("dataset4_full_KS/Method_BDT250_D3/BDT250_D3/MVA_BDT250_D3_rejBvsS");
        MVA5_BDT250D3_rejBvsS = (TH1D*) f5->Get("dataset5_full_KS/Method_BDT250_D3/BDT250_D3/MVA_BDT250_D3_rejBvsS");
        MVA6_BDT250D3_rejBvsS = (TH1D*) f6->Get("dataset6_full_KS/Method_BDT250_D3/BDT250_D3/MVA_BDT250_D3_rejBvsS");
        MVA7_BDT250D3_rejBvsS = (TH1D*) f7->Get("dataset7_full_KS/Method_BDT250_D3/BDT250_D3/MVA_BDT250_D3_rejBvsS");
        MVA8_BDT250D3_rejBvsS = (TH1D*) f8->Get("dataset8_full_KS/Method_BDT250_D3/BDT250_D3/MVA_BDT250_D3_rejBvsS");

        MVA3_BDT250D4_rejBvsS = (TH1D*) f3->Get("dataset3_full_KS/Method_BDT250_D4/BDT250_D4/MVA_BDT250_D4_rejBvsS");
        MVA4_BDT250D4_rejBvsS = (TH1D*) f4->Get("dataset4_full_KS/Method_BDT250_D4/BDT250_D4/MVA_BDT250_D4_rejBvsS");
        MVA5_BDT250D4_rejBvsS = (TH1D*) f5->Get("dataset5_full_KS/Method_BDT250_D4/BDT250_D4/MVA_BDT250_D4_rejBvsS");
        MVA6_BDT250D4_rejBvsS = (TH1D*) f6->Get("dataset6_full_KS/Method_BDT250_D4/BDT250_D4/MVA_BDT250_D4_rejBvsS");
        MVA7_BDT250D4_rejBvsS = (TH1D*) f7->Get("dataset7_full_KS/Method_BDT250_D4/BDT250_D4/MVA_BDT250_D4_rejBvsS");
        MVA8_BDT250D4_rejBvsS = (TH1D*) f8->Get("dataset8_full_KS/Method_BDT250_D4/BDT250_D4/MVA_BDT250_D4_rejBvsS");
    }
    MVA3_BDT250D3_rejBvsS->SetLineColor(kRed);
    MVA4_BDT250D3_rejBvsS->SetLineColor(kBlue);
    MVA5_BDT250D3_rejBvsS->SetLineColor(kBlack);
    MVA6_BDT250D3_rejBvsS->SetLineColor(kGreen+2);
    MVA7_BDT250D3_rejBvsS->SetLineColor(kOrange);
    MVA8_BDT250D3_rejBvsS->SetLineColor(kBlue);

    MVA3_BDT250D4_rejBvsS->SetLineColor(kRed);
    MVA4_BDT250D4_rejBvsS->SetLineColor(kBlue);
    MVA5_BDT250D4_rejBvsS->SetLineColor(kBlack);
    MVA6_BDT250D4_rejBvsS->SetLineColor(kGreen+2);
    MVA7_BDT250D4_rejBvsS->SetLineColor(kOrange);
    MVA8_BDT250D4_rejBvsS->SetLineColor(kBlue);

//    MVA3_BDT250D4_rejBvsS->SetLineStyle(kDashed);
//    MVA4_BDT250D4_rejBvsS->SetLineStyle(kDashed);
//    MVA5_BDT250D4_rejBvsS->SetLineStyle(kDashed);
//    MVA6_BDT250D4_rejBvsS->SetLineStyle(kDashed);

    TCanvas * c = new TCanvas();
    c->SetGrid();
    TH2D * hframe = new TH2D("hframe", "hframe", 1, 0.8, 1., 1, 0.8, 1.);
    hframe->SetXTitle(MVA3_BDT250D3_rejBvsS->GetXaxis()->GetTitle());
    hframe->SetYTitle(MVA3_BDT250D3_rejBvsS->GetYaxis()->GetTitle());
    hframe->Draw();

    MVA3_BDT250D4_rejBvsS->Draw("csame");
//    MVA4_BDT250D4_rejBvsS->Draw("csame");
//    MVA5_BDT250D4_rejBvsS->Draw("csame");
//    MVA6_BDT250D4_rejBvsS->Draw("csame");
//    MVA7_BDT250D4_rejBvsS->Draw("csame");
    MVA8_BDT250D4_rejBvsS->Draw("csame");

    c->SaveAs(Form("ROC4_%s.pdf", s.c_str()));

    hframe->Draw();

    MVA3_BDT250D3_rejBvsS->Draw("csame");
    MVA4_BDT250D3_rejBvsS->Draw("csame");
    MVA5_BDT250D3_rejBvsS->Draw("csame");
    MVA6_BDT250D3_rejBvsS->Draw("csame");
    MVA7_BDT250D3_rejBvsS->Draw("csame");
    MVA8_BDT250D3_rejBvsS->Draw("csame");
    c->SaveAs(Form("ROC3_%s.pdf", s.c_str()));

    TFile * fsave = new TFile(Form("ROC_%s.root", s.c_str()), "recreate");
    MVA3_BDT250D3_rejBvsS->Write("MVA3_BDT250D3_rejBvsS");
    MVA4_BDT250D3_rejBvsS->Write("MVA4_BDT250D3_rejBvsS");
    MVA5_BDT250D3_rejBvsS->Write("MVA5_BDT250D3_rejBvsS");
    MVA6_BDT250D3_rejBvsS->Write("MVA6_BDT250D3_rejBvsS");
    MVA7_BDT250D3_rejBvsS->Write("MVA7_BDT250D3_rejBvsS");
    MVA8_BDT250D3_rejBvsS->Write("MVA8_BDT250D3_rejBvsS");

    MVA3_BDT250D4_rejBvsS->Write("MVA3_BDT250D4_rejBvsS");
    MVA4_BDT250D4_rejBvsS->Write("MVA4_BDT250D4_rejBvsS");
    MVA5_BDT250D4_rejBvsS->Write("MVA5_BDT250D4_rejBvsS");
    MVA6_BDT250D4_rejBvsS->Write("MVA6_BDT250D4_rejBvsS");
    MVA7_BDT250D4_rejBvsS->Write("MVA7_BDT250D4_rejBvsS");
    MVA8_BDT250D4_rejBvsS->Write("MVA8_BDT250D4_rejBvsS");
}
