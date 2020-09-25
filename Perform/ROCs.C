
void ROCs(string s = "LM")
{
    TFile *f3, *f3s1, *f3s2, *f3s3, *f3s4;

    TH1D * MVA3_BDT250D3_rejBvsS;
    TH1D * MVA3_BDT850D3_rejBvsS;
    TH1D * MVA3_BDT250D4_rejBvsS;

    TH1D * MVA3_BDT250D3_rejBvsS_s1;
    TH1D * MVA3_BDT850D3_rejBvsS_s1;
    TH1D * MVA3_BDT250D4_rejBvsS_s1;

    TH1D * MVA3_BDT250D3_rejBvsS_s2;
    TH1D * MVA3_BDT850D3_rejBvsS_s2;
    TH1D * MVA3_BDT250D4_rejBvsS_s2;

    TH1D * MVA3_BDT250D3_rejBvsS_s3;
    TH1D * MVA3_BDT850D3_rejBvsS_s3;
    TH1D * MVA3_BDT250D4_rejBvsS_s3;

    TH1D * MVA3_BDT250D3_rejBvsS_s4;
    TH1D * MVA3_BDT850D3_rejBvsS_s4;
    TH1D * MVA3_BDT250D4_rejBvsS_s4;

    if ( s == "LM" ) {
        f3   = new TFile("TMVA3_HydjetMCTruth_MCBkg_LM.root");
        f3s1 = new TFile("TMVA3_HydjetMCTruth_MCBkg_LM_1.root");
        f3s2 = new TFile("TMVA3_HydjetMCTruth_MCBkg_LM_2.root");
        f3s3 = new TFile("TMVA3_HydjetMCTruth_MCBkg_LM_3.root");
        f3s4 = new TFile("TMVA3_HydjetMCTruth_MCBkg_LM_4.root");

        MVA3_BDT250D3_rejBvsS = (TH1D*) f3->Get("dataset3_full_LM/Method_BDT250_D3/BDT250_D3/MVA_BDT250_D3_rejBvsS");
        MVA3_BDT850D3_rejBvsS = (TH1D*) f3->Get("dataset3_full_LM/Method_BDT850_D3/BDT850_D3/MVA_BDT850_D3_rejBvsS");
        MVA3_BDT250D4_rejBvsS = (TH1D*) f3->Get("dataset3_full_LM/Method_BDT250_D4/BDT250_D4/MVA_BDT250_D4_rejBvsS");

        MVA3_BDT250D3_rejBvsS_s1 = (TH1D*) f3s1->Get("dataset3_full_LM_1/Method_BDT250_D3/BDT250_D3/MVA_BDT250_D3_rejBvsS");
        MVA3_BDT850D3_rejBvsS_s1 = (TH1D*) f3s1->Get("dataset3_full_LM_1/Method_BDT850_D3/BDT850_D3/MVA_BDT850_D3_rejBvsS");
        MVA3_BDT250D4_rejBvsS_s1 = (TH1D*) f3s1->Get("dataset3_full_LM_1/Method_BDT250_D4/BDT250_D4/MVA_BDT250_D4_rejBvsS");

        MVA3_BDT250D3_rejBvsS_s2 = (TH1D*) f3s2->Get("dataset3_full_LM_2/Method_BDT250_D3/BDT250_D3/MVA_BDT250_D3_rejBvsS");
        MVA3_BDT850D3_rejBvsS_s2 = (TH1D*) f3s2->Get("dataset3_full_LM_2/Method_BDT850_D3/BDT850_D3/MVA_BDT850_D3_rejBvsS");
        MVA3_BDT250D4_rejBvsS_s2 = (TH1D*) f3s2->Get("dataset3_full_LM_2/Method_BDT250_D4/BDT250_D4/MVA_BDT250_D4_rejBvsS");

        MVA3_BDT250D3_rejBvsS_s3 = (TH1D*) f3s3->Get("dataset3_full_LM_3/Method_BDT250_D3/BDT250_D3/MVA_BDT250_D3_rejBvsS");
        MVA3_BDT850D3_rejBvsS_s3 = (TH1D*) f3s3->Get("dataset3_full_LM_3/Method_BDT850_D3/BDT850_D3/MVA_BDT850_D3_rejBvsS");
        MVA3_BDT250D4_rejBvsS_s3 = (TH1D*) f3s3->Get("dataset3_full_LM_3/Method_BDT250_D4/BDT250_D4/MVA_BDT250_D4_rejBvsS");

        MVA3_BDT250D3_rejBvsS_s4 = (TH1D*) f3s4->Get("dataset3_full_LM_4/Method_BDT250_D3/BDT250_D3/MVA_BDT250_D3_rejBvsS");
        MVA3_BDT850D3_rejBvsS_s4 = (TH1D*) f3s4->Get("dataset3_full_LM_4/Method_BDT850_D3/BDT850_D3/MVA_BDT850_D3_rejBvsS");
        MVA3_BDT250D4_rejBvsS_s4 = (TH1D*) f3s4->Get("dataset3_full_LM_4/Method_BDT250_D4/BDT250_D4/MVA_BDT250_D4_rejBvsS");
    } else if ( s == "KS" ) {
        f3   = new TFile("TMVA3_HydjetMCTruth_MCBkg_KS.root");
        f3s1 = new TFile("TMVA3_HydjetMCTruth_MCBkg_KS_1.root");
        f3s2 = new TFile("TMVA3_HydjetMCTruth_MCBkg_KS_2.root");
        f3s3 = new TFile("TMVA3_HydjetMCTruth_MCBkg_KS_3.root");
        f3s4 = new TFile("TMVA3_HydjetMCTruth_MCBkg_KS_4.root");

        MVA3_BDT250D3_rejBvsS = (TH1D*) f3->Get("dataset3_full_KS/Method_BDT250_D3/BDT250_D3/MVA_BDT250_D3_rejBvsS");
        MVA3_BDT850D3_rejBvsS = (TH1D*) f3->Get("dataset3_full_KS/Method_BDT850_D3/BDT850_D3/MVA_BDT850_D3_rejBvsS");
        MVA3_BDT250D4_rejBvsS = (TH1D*) f3->Get("dataset3_full_KS/Method_BDT250_D4/BDT250_D4/MVA_BDT250_D4_rejBvsS");

        MVA3_BDT250D3_rejBvsS_s1 = (TH1D*) f3s1->Get("dataset3_full_KS_1/Method_BDT250_D3/BDT250_D3/MVA_BDT250_D3_rejBvsS");
        MVA3_BDT850D3_rejBvsS_s1 = (TH1D*) f3s1->Get("dataset3_full_KS_1/Method_BDT850_D3/BDT850_D3/MVA_BDT850_D3_rejBvsS");
        MVA3_BDT250D4_rejBvsS_s1 = (TH1D*) f3s1->Get("dataset3_full_KS_1/Method_BDT250_D4/BDT250_D4/MVA_BDT250_D4_rejBvsS");

        MVA3_BDT250D3_rejBvsS_s2 = (TH1D*) f3s2->Get("dataset3_full_KS_2/Method_BDT250_D3/BDT250_D3/MVA_BDT250_D3_rejBvsS");
        MVA3_BDT850D3_rejBvsS_s2 = (TH1D*) f3s2->Get("dataset3_full_KS_2/Method_BDT850_D3/BDT850_D3/MVA_BDT850_D3_rejBvsS");
        MVA3_BDT250D4_rejBvsS_s2 = (TH1D*) f3s2->Get("dataset3_full_KS_2/Method_BDT250_D4/BDT250_D4/MVA_BDT250_D4_rejBvsS");

        MVA3_BDT250D3_rejBvsS_s3 = (TH1D*) f3s3->Get("dataset3_full_KS_3/Method_BDT250_D3/BDT250_D3/MVA_BDT250_D3_rejBvsS");
        MVA3_BDT850D3_rejBvsS_s3 = (TH1D*) f3s3->Get("dataset3_full_KS_3/Method_BDT850_D3/BDT850_D3/MVA_BDT850_D3_rejBvsS");
        MVA3_BDT250D4_rejBvsS_s3 = (TH1D*) f3s3->Get("dataset3_full_KS_3/Method_BDT250_D4/BDT250_D4/MVA_BDT250_D4_rejBvsS");

        MVA3_BDT250D3_rejBvsS_s4 = (TH1D*) f3s4->Get("dataset3_full_KS_4/Method_BDT250_D3/BDT250_D3/MVA_BDT250_D3_rejBvsS");
        MVA3_BDT850D3_rejBvsS_s4 = (TH1D*) f3s4->Get("dataset3_full_KS_4/Method_BDT850_D3/BDT850_D3/MVA_BDT850_D3_rejBvsS");
        MVA3_BDT250D4_rejBvsS_s4 = (TH1D*) f3s4->Get("dataset3_full_KS_4/Method_BDT250_D4/BDT250_D4/MVA_BDT250_D4_rejBvsS");
    }

    TCanvas * c = new TCanvas();
    c->SetGrid();
    TH2D * hframe = new TH2D("hframe", "hframe", 1, 0.0, 1., 1, 0.2, 1.);
    hframe->SetXTitle(MVA3_BDT250D3_rejBvsS->GetXaxis()->GetTitle());
    hframe->SetYTitle(MVA3_BDT250D3_rejBvsS->GetYaxis()->GetTitle());
    hframe->Draw();

    MVA3_BDT250D4_rejBvsS->SetLineColor(kRed);
    MVA3_BDT250D4_rejBvsS->SetLineStyle(kDashed);

    MVA3_BDT250D4_rejBvsS_s1->SetLineColor(kRed);
    MVA3_BDT250D4_rejBvsS_s2->SetLineColor(kBlue);
    MVA3_BDT250D4_rejBvsS_s3->SetLineColor(kGreen);
    MVA3_BDT250D4_rejBvsS_s4->SetLineColor(kBlack);

    MVA3_BDT250D4_rejBvsS->Draw("csame");
    MVA3_BDT250D4_rejBvsS_s1->Draw("csame");
    MVA3_BDT250D4_rejBvsS_s2->Draw("csame");
    MVA3_BDT250D4_rejBvsS_s3->Draw("csame");
    MVA3_BDT250D4_rejBvsS_s4->Draw("csame");

    TLegend* leg = new TLegend(0.2, 0.15, 0.7, 0.6);
    leg->AddEntry( MVA3_BDT250D4_rejBvsS,    "MVA Standard 250D4", "pl" );
    leg->AddEntry( MVA3_BDT250D4_rejBvsS_s1, "MVA Centrality 5-10\% 250D4", "pl" );
    leg->AddEntry( MVA3_BDT250D4_rejBvsS_s2, "MVA Centrality 10-30\% 250D4", "pl" );
    leg->AddEntry( MVA3_BDT250D4_rejBvsS_s3, "MVA Centrality 30-50\% 250D4", "pl" );
    leg->AddEntry( MVA3_BDT250D4_rejBvsS_s4, "MVA Centrality 50-80\% 250D4", "pl" );
    leg->Draw();

    c->SaveAs(Form("ROC3s_%s.pdf", s.c_str()));

    //
    hframe->Draw();
    MVA3_BDT250D4_rejBvsS->SetLineColor(kRed);
    MVA3_BDT250D4_rejBvsS->SetLineStyle(kSolid);
    MVA3_BDT250D4_rejBvsS->Draw("csame");

    MVA3_BDT250D3_rejBvsS->SetLineColor(kBlue);
    MVA3_BDT250D3_rejBvsS->SetLineStyle(kSolid);
    MVA3_BDT250D3_rejBvsS->Draw("csame");

    MVA3_BDT850D3_rejBvsS->SetLineColor(kBlack);
    MVA3_BDT850D3_rejBvsS->SetLineStyle(kSolid);
    MVA3_BDT850D3_rejBvsS->Draw("csame");

    TLegend* leg1 = new TLegend(0.2, 0.15, 0.5, 0.4);
    leg1->AddEntry( MVA3_BDT250D4_rejBvsS,    "250D4", "pl" );
    leg1->AddEntry( MVA3_BDT250D3_rejBvsS,    "250D3", "pl" );
    leg1->AddEntry( MVA3_BDT850D3_rejBvsS,    "850D3", "pl" );
    leg1->Draw();

    c->SaveAs(Form("ROC_MVA_%s.pdf", s.c_str()));
    //
    TFile * fsave = new TFile(Form("ROC_%s.root", s.c_str()), "recreate");
    MVA3_BDT250D3_rejBvsS->Write("MVA3_BDT250D3_rejBvsS");
    MVA3_BDT850D3_rejBvsS->Write("MVA3_BDT850D3_rejBvsS");
    MVA3_BDT250D4_rejBvsS->Write("MVA3_BDT250D4_rejBvsS");

    MVA3_BDT250D3_rejBvsS_s1->Write("MVA3_BDT250D3_rejBvsS_s1");
    MVA3_BDT850D3_rejBvsS_s1->Write("MVA3_BDT850D3_rejBvsS_s1");
    MVA3_BDT250D4_rejBvsS_s1->Write("MVA3_BDT250D4_rejBvsS_s1");

    MVA3_BDT250D3_rejBvsS_s2->Write("MVA3_BDT250D3_rejBvsS_s2");
    MVA3_BDT850D3_rejBvsS_s2->Write("MVA3_BDT850D3_rejBvsS_s2");
    MVA3_BDT250D4_rejBvsS_s2->Write("MVA3_BDT250D4_rejBvsS_s2");

    MVA3_BDT250D3_rejBvsS_s3->Write("MVA3_BDT250D3_rejBvsS_s3");
    MVA3_BDT850D3_rejBvsS_s3->Write("MVA3_BDT850D3_rejBvsS_s3");
    MVA3_BDT250D4_rejBvsS_s3->Write("MVA3_BDT250D4_rejBvsS_s3");

    MVA3_BDT250D3_rejBvsS_s4->Write("MVA3_BDT250D3_rejBvsS_s4");
    MVA3_BDT850D3_rejBvsS_s4->Write("MVA3_BDT850D3_rejBvsS_s4");
    MVA3_BDT250D4_rejBvsS_s4->Write("MVA3_BDT250D4_rejBvsS_s4");
}
