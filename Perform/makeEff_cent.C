
//void makeEff_cent(string s = "../txt/v0_Hydjet_eff_test2dpt4_eff.root", string fout = "Lm_Hyjet_eff_test2dpt4.root")
void makeEff_cent(string s = "../txt/v0_Hydjet_eff_stddpt4_eff.root", string fout = "Lm_Hyjet_eff_stddpt4.root")
{
    TFile * f = new TFile(s.c_str());

    TH3D * LamEff_num[10];
    TH3D * LamEff_acc[10];
    TH3D * LamEff_denom[10];

    for ( int c = 0; c < 10; c++ ) {
        LamEff_num[c] = (TH3D*) f->Get( Form("V0valid_%i/Lm/LamEff_num", c) );
        LamEff_acc[c] = (TH3D*) f->Get( Form("V0valid_%i/Lm/LamEff_acc", c) );
        LamEff_denom[c] = (TH3D*) f->Get( Form("V0valid_%i/Lm/LamEff_denom", c) );
    }

    const double * pt_bins   = LamEff_num[0]->GetXaxis()->GetXbins()->GetArray();
    const double * eta_bins  = LamEff_num[0]->GetYaxis()->GetXbins()->GetArray();
    const double * mass_bins = LamEff_num[0]->GetZaxis()->GetXbins()->GetArray();

    int Npt_bins   = LamEff_num[0]->GetXaxis()->GetNbins();
    int Neta_bins  = LamEff_num[0]->GetYaxis()->GetNbins();
    int Nmass_bins = LamEff_num[0]->GetZaxis()->GetNbins();

    auto pt_axis   = LamEff_num[0]->GetXaxis();
    auto eta_axis  = LamEff_num[0]->GetYaxis();
    auto mass_axis = LamEff_num[0]->GetZaxis();

    double eff_eta_bins[13] = { -2.4, -2.0, -1.6, -1.2, -0.8, -0.4, 0., 0.4, 0.8, 1.2, 1.6, 2.0, 2.4};
// pt                            0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12
//    double pTbin[14] = {0.2, 0.4, 0.6, 0.8, 1.0, 1.4, 1.8, 2.2, 2.8, 3.6, 4.6, 6.0, 7.0, 8.5};
    TH1D * Eff_Num_eta  [10]; // 1.8 - 8.5
    TH1D * Eff_Acc_eta  [10]; // 1.8 - 8.5
    TH1D * Eff_Denom_eta[10]; // 1.8 - 8.5

    TH1D * Eff_Num_pT12  [10];
    TH1D * Eff_Acc_pT12  [10];
    TH1D * Eff_Denom_pT12[10];

    for ( int c = 0; c < 10; c++ ) {
        Eff_Num_eta  [c] = new TH1D(Form("Eff_Num_eta_%i", c), Form("Eff_Num_eta_%i", c), 12, eff_eta_bins); // 1.8 - 8.5
        Eff_Acc_eta  [c] = new TH1D(Form("Eff_Acc_eta_%i", c), Form("Eff_Acc_eta_%i", c), 12, eff_eta_bins); // 1.8 - 8.5
        Eff_Denom_eta[c] = new TH1D(Form("Eff_Denom_eta_%i", c), Form("Eff_Denom_eta_%i", c), 12, eff_eta_bins); // 1.8 - 8.5

        Eff_Num_pT12  [c] = new TH1D(Form("Eff_Num_pT12_%i", c), Form("Eff_Num_pT12_%i", c), Npt_bins, pt_bins);
        Eff_Acc_pT12  [c] = new TH1D(Form("Eff_Acc_pT12_%i", c), Form("Eff_Acc_pT12_%i", c), Npt_bins, pt_bins);
        Eff_Denom_pT12[c] = new TH1D(Form("Eff_Denom_pT12_%i", c), Form("Eff_Denom_pT12_%i", c), Npt_bins, pt_bins);
    }




    // eta range: -1.2 - 1.2, [14, 38)
    for ( int ieta = 13; ieta < 37; ieta++ ) {
        double eta = eta_axis->GetBinCenter(ieta+1);
        for ( int ipt = 0; ipt < Npt_bins; ipt++ ) {
            double pt = pt_axis->GetBinCenter(ipt+1);
            for ( int imass = 64; imass < 82; imass++ ) {
                for ( int c = 0; c < 10; c++ ) {
                    double nLmEff = LamEff_num[c]->GetBinContent( ipt+1, ieta+1, imass );
                    double nLmAcc = LamEff_acc[c]->GetBinContent( ipt+1, ieta+1, imass );
                    double nLmDenom = LamEff_denom[c]->GetBinContent( ipt+1, ieta+1, imass );

                    Eff_Num_pT12[c]->Fill( pt, nLmEff );
                    Eff_Acc_pT12[c]->Fill( pt, nLmAcc );
                    Eff_Denom_pT12[c]->Fill( pt, nLmDenom );
                }
            }
        }
    }

    // pt range: 1.8 - 8.5  [7, 14)
    for ( int ieta = 0; ieta < Neta_bins; ieta++ ) {
        double eta = eta_axis->GetBinCenter(ieta+1);
        for ( int ipt = 6; ipt < 13; ipt++ ) {
            double pt = pt_axis->GetBinCenter(ipt+1);
            for ( int imass = 64; imass < 82; imass++ ) {
                for ( int c = 0; c < 10; c++ ) {
                    double nLmEff = LamEff_num[c]->GetBinContent( ipt+1, ieta+1, imass );
                    double nLmAcc = LamEff_acc[c]->GetBinContent( ipt+1, ieta+1, imass );
                    double nLmDenom = LamEff_denom[c]->GetBinContent( ipt+1, ieta+1, imass );

                    Eff_Num_eta[c]->Fill( eta, nLmEff );
                    Eff_Acc_eta[c]->Fill( eta, nLmAcc );
                    Eff_Denom_eta[c]->Fill( eta, nLmDenom );
                }
            }
        }
    }


    TFile * fsave = new TFile(fout.c_str(), "recreate");
    for ( int c = 0; c < 10; c++ ) {
        Eff_Num_eta  [c]->Write();
        Eff_Acc_eta  [c]->Write();
        Eff_Denom_eta[c]->Write();

        Eff_Num_pT12  [c]->Write();
        Eff_Acc_pT12  [c]->Write();
        Eff_Denom_pT12[c]->Write();
    }

    // cent 0-20
    TH1D * Eff_Num_eta_0_20   = (TH1D*) Eff_Num_eta[0]  ->Clone("Eff_Num_eta_0_20");
    TH1D * Eff_Acc_eta_0_20   = (TH1D*) Eff_Acc_eta[0]  ->Clone("Eff_Acc_eta_0_20");
    TH1D * Eff_Denom_eta_0_20 = (TH1D*) Eff_Denom_eta[0]->Clone("Eff_Denom_eta_0_20");
    Eff_Num_eta_0_20  ->Add(Eff_Num_eta  [1]);
    Eff_Acc_eta_0_20  ->Add(Eff_Acc_eta  [1]);
    Eff_Denom_eta_0_20->Add(Eff_Denom_eta[1]);

    TH1D * Eff_Num_pT12_0_20   = (TH1D*) Eff_Num_pT12[0]  ->Clone("Eff_Num_pT12_0_20");
    TH1D * Eff_Acc_pT12_0_20   = (TH1D*) Eff_Acc_pT12[0]  ->Clone("Eff_Acc_pT12_0_20");
    TH1D * Eff_Denom_pT12_0_20 = (TH1D*) Eff_Denom_pT12[0]->Clone("Eff_Denom_pT12_0_20");
    Eff_Num_pT12_0_20  ->Add(Eff_Num_pT12  [1]);
    Eff_Acc_pT12_0_20  ->Add(Eff_Acc_pT12  [1]);
    Eff_Denom_pT12_0_20->Add(Eff_Denom_pT12[1]);

    // cent 20-60
    TH1D * Eff_Num_eta_20_60   = (TH1D*) Eff_Num_eta[2]  ->Clone("Eff_Num_eta_20_60");
    TH1D * Eff_Acc_eta_20_60   = (TH1D*) Eff_Acc_eta[2]  ->Clone("Eff_Acc_eta_20_60");
    TH1D * Eff_Denom_eta_20_60 = (TH1D*) Eff_Denom_eta[2]->Clone("Eff_Denom_eta_20_60");
    Eff_Num_eta_20_60  ->Add(Eff_Num_eta  [3]);
    Eff_Acc_eta_20_60  ->Add(Eff_Acc_eta  [3]);
    Eff_Denom_eta_20_60->Add(Eff_Denom_eta[3]);
    Eff_Num_eta_20_60  ->Add(Eff_Num_eta  [4]);
    Eff_Acc_eta_20_60  ->Add(Eff_Acc_eta  [4]);
    Eff_Denom_eta_20_60->Add(Eff_Denom_eta[4]);
    Eff_Num_eta_20_60  ->Add(Eff_Num_eta  [5]);
    Eff_Acc_eta_20_60  ->Add(Eff_Acc_eta  [5]);
    Eff_Denom_eta_20_60->Add(Eff_Denom_eta[5]);

    TH1D * Eff_Num_pT12_20_60   = (TH1D*) Eff_Num_pT12[2]  ->Clone("Eff_Num_pT12_20_60");
    TH1D * Eff_Acc_pT12_20_60   = (TH1D*) Eff_Acc_pT12[2]  ->Clone("Eff_Acc_pT12_20_60");
    TH1D * Eff_Denom_pT12_20_60 = (TH1D*) Eff_Denom_pT12[2]->Clone("Eff_Denom_pT12_20_60");
    Eff_Num_pT12_20_60  ->Add(Eff_Num_pT12  [3]);
    Eff_Acc_pT12_20_60  ->Add(Eff_Acc_pT12  [3]);
    Eff_Denom_pT12_20_60->Add(Eff_Denom_pT12[3]);
    Eff_Num_pT12_20_60  ->Add(Eff_Num_pT12  [4]);
    Eff_Acc_pT12_20_60  ->Add(Eff_Acc_pT12  [4]);
    Eff_Denom_pT12_20_60->Add(Eff_Denom_pT12[4]);
    Eff_Num_pT12_20_60  ->Add(Eff_Num_pT12  [5]);
    Eff_Acc_pT12_20_60  ->Add(Eff_Acc_pT12  [5]);
    Eff_Denom_pT12_20_60->Add(Eff_Denom_pT12[5]);

    //
    Eff_Num_eta_0_20->Write();
    Eff_Acc_eta_0_20->Write();
    Eff_Denom_eta_0_20->Write();
    Eff_Num_eta_20_60->Write();
    Eff_Acc_eta_20_60->Write();
    Eff_Denom_eta_20_60->Write();

    Eff_Num_pT12_0_20->Write();
    Eff_Acc_pT12_0_20->Write();
    Eff_Denom_pT12_0_20->Write();
    Eff_Num_pT12_20_60->Write();
    Eff_Acc_pT12_20_60->Write();
    Eff_Denom_pT12_20_60->Write();

    //
    TH1D * hAcc_eta_0_20 = (TH1D*) Eff_Acc_eta_0_20->Clone("hAcc_eta_0_20");
    TH1D * hEff_eta_0_20 = (TH1D*) Eff_Num_eta_0_20->Clone("hEff_eta_0_20");
    TH1D * hREC_eta_0_20 = (TH1D*) Eff_Num_eta_0_20->Clone("hREC_eta_0_20");
    hAcc_eta_0_20->Divide(Eff_Denom_eta_0_20);
    hEff_eta_0_20->Divide(Eff_Denom_eta_0_20);
    hREC_eta_0_20->Divide(Eff_Acc_eta_0_20);

    TH1D * hAcc_eta_20_60 = (TH1D*) Eff_Acc_eta_20_60->Clone("hAcc_eta_20_60");
    TH1D * hEff_eta_20_60 = (TH1D*) Eff_Num_eta_20_60->Clone("hEff_eta_20_60");
    TH1D * hREC_eta_20_60 = (TH1D*) Eff_Num_eta_20_60->Clone("hREC_eta_20_60");
    hAcc_eta_20_60->Divide(Eff_Denom_eta_20_60);
    hEff_eta_20_60->Divide(Eff_Denom_eta_20_60);
    hREC_eta_20_60->Divide(Eff_Acc_eta_20_60);


    TH1D * hAcc_pT12_0_20 = (TH1D*) Eff_Acc_pT12_0_20->Clone("hAcc_pT12_0_20");
    TH1D * hEff_pT12_0_20 = (TH1D*) Eff_Num_pT12_0_20->Clone("hEff_pT12_0_20");
    TH1D * hREC_pT12_0_20 = (TH1D*) Eff_Num_pT12_0_20->Clone("hREC_pT12_0_20");
    hAcc_pT12_0_20->Divide(Eff_Denom_pT12_0_20);
    hEff_pT12_0_20->Divide(Eff_Denom_pT12_0_20);
    hREC_pT12_0_20->Divide(Eff_Acc_pT12_0_20);

    TH1D * hAcc_pT12_20_60 = (TH1D*) Eff_Acc_pT12_20_60->Clone("hAcc_pT12_20_60");
    TH1D * hEff_pT12_20_60 = (TH1D*) Eff_Num_pT12_20_60->Clone("hEff_pT12_20_60");
    TH1D * hREC_pT12_20_60 = (TH1D*) Eff_Num_pT12_20_60->Clone("hREC_pT12_20_60");
    hAcc_pT12_20_60->Divide(Eff_Denom_pT12_20_60);
    hEff_pT12_20_60->Divide(Eff_Denom_pT12_20_60);
    hREC_pT12_20_60->Divide(Eff_Acc_pT12_20_60);

    hAcc_eta_0_20->Write();
    hEff_eta_0_20->Write();
    hREC_eta_0_20->Write();
    hAcc_eta_20_60->Write();
    hEff_eta_20_60->Write();
    hREC_eta_20_60->Write();

    hAcc_pT12_0_20->Write();
    hEff_pT12_0_20->Write();
    hREC_pT12_0_20->Write();
    hAcc_pT12_20_60->Write();
    hEff_pT12_20_60->Write();
    hREC_pT12_20_60->Write();
}
