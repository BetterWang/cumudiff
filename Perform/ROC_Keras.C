
void ROC_Keras(string s = "LM")
{
    TFile *f3, *f4, *f5, *f6, *f7, *f8;

    TH1D * MVA_BDT250D4_rejBvsS;
    TH1D * MVA_PyKeras_rejBvsS;

    TH1D * MVA_BDT250D4DG_rejBvsS;
    TH1D * MVA_PyKerasSGD_rejBvsS;

    TH1D * MVA_PyKerasD2_rejBvsS;

    TH1D * MVA_PyKeras100_rejBvsS;

    TH1D * MVA_BDT850D3_rejBvsS;

    if ( s == "LM" ) {
        f3 = new TFile("TMVA.root");
        f4 = new TFile("TMVA_Keras2.root");
        f5 = new TFile("TMVA_Keras3.root");
        f6 = new TFile("TMVA_Keras4.root");
        f7 = new TFile("TMVA3_HydjetMCTruth_MCBkg_LM.root");

        MVA_BDT250D4_rejBvsS  = (TH1D*) f3->Get("dataset/Method_BDT250_D4/BDT250_D4/MVA_BDT250_D4_rejBvsS");
        MVA_PyKeras_rejBvsS   = (TH1D*) f3->Get("dataset/Method_PyKeras/PyKeras/MVA_PyKeras_rejBvsS");

        MVA_BDT250D4DG_rejBvsS  = (TH1D*) f4->Get("dataset_Keras2/Method_BDT250_D4DG/BDT250_D4DG/MVA_BDT250_D4DG_rejBvsS");
        MVA_PyKerasSGD_rejBvsS  = (TH1D*) f4->Get("dataset_Keras2/Method_PyKerasSGD/PyKerasSGD/MVA_PyKerasSGD_rejBvsS");

        MVA_PyKerasD2_rejBvsS = (TH1D*) f5->Get("dataset_Keras3/Method_PyKerasD2/PyKerasD2/MVA_PyKerasD2_rejBvsS");
        MVA_PyKeras100_rejBvsS = (TH1D*) f6->Get("dataset_Keras4/Method_PyKeras/PyKeras/MVA_PyKeras_rejBvsS");

        MVA_BDT850D3_rejBvsS = (TH1D*) f7->Get("dataset3_full_LM/Method_BDT850_D3/BDT850_D3/MVA_BDT850_D3_rejBvsS");
    } else if ( s == "KS" ) {
    }

    MVA_BDT250D4_rejBvsS->SetLineColor(kRed);
    MVA_PyKeras_rejBvsS->SetLineColor(kBlue);

    MVA_BDT250D4DG_rejBvsS->SetLineColor(kBlack);
    MVA_PyKerasSGD_rejBvsS->SetLineColor(kGreen);

    MVA_PyKerasD2_rejBvsS->SetLineColor(kBlack);
    MVA_PyKeras100_rejBvsS->SetLineColor(kBlack);

    MVA_BDT850D3_rejBvsS->SetLineColor(kGreen);

    TCanvas * c = new TCanvas();
    c->SetGrid();
    TH2D * hframe = new TH2D("hframe", "hframe", 1, 0.8, 1., 1, 0.8, 1.);
    hframe->SetXTitle(MVA_BDT250D4_rejBvsS->GetXaxis()->GetTitle());
    hframe->SetYTitle(MVA_BDT250D4_rejBvsS->GetYaxis()->GetTitle());

    hframe->Draw();

    MVA_BDT250D4_rejBvsS->Draw("csame");
    MVA_PyKeras_rejBvsS->Draw("csame");

//    MVA_PyKerasD2_rejBvsS->Draw("csame");
//    MVA_PyKerasSGD_rejBvsS->Draw("csame");

    MVA_PyKeras100_rejBvsS->Draw("csame");
    MVA_BDT850D3_rejBvsS->Draw("csame");

    c->SaveAs(Form("ROC_Keras_%s.pdf", s.c_str()));

    TFile * fsave = new TFile(Form("ROC_Keras_%s.root", s.c_str()), "recreate");
    MVA_BDT250D4_rejBvsS->Write("MVA_BDT250D4_rejBvsS");
    MVA_PyKeras_rejBvsS->Write("MVA_PyKeras_rejBvsS");

    MVA_BDT250D4DG_rejBvsS->Write("MVA_BDT250D4DG_rejBvsS");
    MVA_PyKerasSGD_rejBvsS->Write("MVA_PyKerasSGD_rejBvsS");

    MVA_PyKerasD2_rejBvsS->Write("MVA_PyKerasD2_rejBvsS");
    MVA_PyKeras100_rejBvsS->Write("MVA_PyKeras100_rejBvsS");
    MVA_BDT850D3_rejBvsS->Write("MVA_BDT850D3_rejBvsS");
}
