
//void makeEff3_cent(string s = "V0_MCFull_110.root", string prefix = "Lm", string fout = "Lm_Hyjet_eff_MVAMCFull.root")
void makeEff3_cent(string s = "V0_MCFullD4_115.root", string prefix = "Lm", string fout = "Lm_Hyjet_eff_MVAMCFullD4.root")
{
    TFile * f = new TFile(s.c_str());

    TH3D * LamEff_num[10];
    TH3D * LamEff_acc[10];
    TH3D * LamEff_denom[10];
    TH3D * LamFak_num[10];
    TH3D * LamFak_denom[10];

    for ( int c = 0; c < 10; c++ ) {
        LamEff_num[c]   = (TH3D*) f->Get( Form("V0valid_%i/%s/%sEff_num", c, prefix.c_str(), prefix=="Lm"?"Lam":"K0s") );
        LamEff_acc[c]   = (TH3D*) f->Get( Form("V0valid_%i/%s/%sEff_acc", c, prefix.c_str(), prefix=="Lm"?"Lam":"K0s") );
        LamEff_denom[c] = (TH3D*) f->Get( Form("V0valid_%i/%s/%sEff_denom", c, prefix.c_str(), prefix=="Lm"?"Lam":"K0s") );
        LamFak_num[c]   = (TH3D*) f->Get( Form("V0valid_%i/%s/%sFake_num", c, prefix.c_str(), prefix=="Lm"?"Lam":"K0s") );
        LamFak_denom[c] = (TH3D*) f->Get( Form("V0valid_%i/%s/%sFake_denom", c, prefix.c_str(), prefix=="Lm"?"Lam":"K0s") );
    }

    // Lm mass signal range: 1.1115, 1.1200, [64, 82)
    // Ks mass signal range: 0.492, 0.503, [125, 147)
    int mass_start = 64;
    int mass_end   = 82;
    if ( prefix == "Ks" ) {
        mass_start = 125;
        mass_end   = 147;
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

    double eff_eta_bins[11] = { -2.5, -2.0, -1.5, -1.0, -0.5, 0., 0.5, 1.0, 1.5, 2.0, 2.5};
// pt                            0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12
//    double pTbin[14] = {0.2, 0.4, 0.6, 0.8, 1.0, 1.4, 1.8, 2.2, 2.8, 3.6, 4.6, 6.0, 7.0, 8.5};
    TH1D * Eff_Num_eta  [10]; // 1.8 - 8.5
    TH1D * Eff_Acc_eta  [10]; // 1.8 - 8.5
    TH1D * Eff_Denom_eta[10]; // 1.8 - 8.5

    TH1D * Eff_Num_pT12  [10];
    TH1D * Eff_Acc_pT12  [10];
    TH1D * Eff_Denom_pT12[10];

    TH1D * Fak_Num_eta  [10]; // 1.8 - 8.5
    TH1D * Fak_Denom_eta[10]; // 1.8 - 8.5

    TH1D * Fak_Num_pT12  [10];
    TH1D * Fak_Denom_pT12[10];

    for ( int c = 0; c < 10; c++ ) {
        Eff_Num_eta  [c] = new TH1D(Form("Eff_Num_eta_%i", c), Form("Eff_Num_eta_%i", c), 10, eff_eta_bins); // 1.8 - 8.5
        Eff_Acc_eta  [c] = new TH1D(Form("Eff_Acc_eta_%i", c), Form("Eff_Acc_eta_%i", c), 10, eff_eta_bins); // 1.8 - 8.5
        Eff_Denom_eta[c] = new TH1D(Form("Eff_Denom_eta_%i", c), Form("Eff_Denom_eta_%i", c), 10, eff_eta_bins); // 1.8 - 8.5

        Eff_Num_pT12  [c] = new TH1D(Form("Eff_Num_pT12_%i", c), Form("Eff_Num_pT12_%i", c), Npt_bins, pt_bins);
        Eff_Acc_pT12  [c] = new TH1D(Form("Eff_Acc_pT12_%i", c), Form("Eff_Acc_pT12_%i", c), Npt_bins, pt_bins);
        Eff_Denom_pT12[c] = new TH1D(Form("Eff_Denom_pT12_%i", c), Form("Eff_Denom_pT12_%i", c), Npt_bins, pt_bins);

        Fak_Num_eta  [c] = new TH1D(Form("Fak_Num_eta_%i", c), Form("Fak_Num_eta_%i", c), 10, eff_eta_bins);
        Fak_Denom_eta[c] = new TH1D(Form("Fak_Denom_eta_%i", c), Form("Fak_Denom_eta_%i", c), 10, eff_eta_bins);

        Fak_Num_pT12  [c] = new TH1D(Form("Fak_Num_pT12_%i", c), Form("Fak_Num_pT12_%i", c), Npt_bins, pt_bins);
        Fak_Denom_pT12[c] = new TH1D(Form("Fak_Denom_pT12_%i", c), Form("Fak_Denom_pT12_%i", c), Npt_bins, pt_bins);
    }

    // eta range: -1.0 - 1.0, [16, 36)
    for ( int ieta = 15; ieta < 35; ieta++ ) {
        double eta = eta_axis->GetBinCenter(ieta+1);
        for ( int ipt = 0; ipt < Npt_bins; ipt++ ) {
            double pt = pt_axis->GetBinCenter(ipt+1);
            for ( int imass = mass_start; imass < mass_end; imass++ ) {
                for ( int c = 0; c < 10; c++ ) {
                    double nLmEff = LamEff_num[c]->GetBinContent( ipt+1, ieta+1, imass );
                    double nLmAcc = LamEff_acc[c]->GetBinContent( ipt+1, ieta+1, imass );
                    double nLmDenom = LamEff_denom[c]->GetBinContent( ipt+1, ieta+1, imass );

                    Eff_Num_pT12[c]->Fill( pt, nLmEff );
                    Eff_Acc_pT12[c]->Fill( pt, nLmAcc );
                    Eff_Denom_pT12[c]->Fill( pt, nLmDenom );

                    double nLmFak = LamFak_num[c]->GetBinContent( ipt+1, ieta+1, imass );
                    double nLmFakDenom = LamFak_denom[c]->GetBinContent( ipt+1, ieta+1, imass );

                    Fak_Num_pT12[c]->Fill( pt, nLmFak);
                    Fak_Denom_pT12[c]->Fill( pt, nLmFakDenom);
                }
            }
        }
    }

    // Lm pt range: 1.8 - 8.5  [7, 14)
    // Ks pt range: 1.0 - 8.5  [7, 14)
    int pt_start = 6;
    int pt_end   = 13;
    if ( prefix == "Ks" ) {
        pt_start = 4;
    }

    for ( int ieta = 0; ieta < Neta_bins; ieta++ ) {
        double eta = eta_axis->GetBinCenter(ieta+1);
        for ( int ipt = pt_start; ipt < pt_end; ipt++ ) {
            double pt = pt_axis->GetBinCenter(ipt+1);
            for ( int imass = mass_start; imass < mass_end; imass++ ) {
                for ( int c = 0; c < 10; c++ ) {
                    double nLmEff = LamEff_num[c]->GetBinContent( ipt+1, ieta+1, imass );
                    double nLmAcc = LamEff_acc[c]->GetBinContent( ipt+1, ieta+1, imass );
                    double nLmDenom = LamEff_denom[c]->GetBinContent( ipt+1, ieta+1, imass );

                    Eff_Num_eta[c]->Fill( eta, nLmEff );
                    Eff_Acc_eta[c]->Fill( eta, nLmAcc );
                    Eff_Denom_eta[c]->Fill( eta, nLmDenom );

                    double nLmFak = LamFak_num[c]->GetBinContent( ipt+1, ieta+1, imass );
                    double nLmFakDenom = LamFak_denom[c]->GetBinContent( ipt+1, ieta+1, imass );

                    Fak_Num_eta[c]->Fill(eta, nLmFak);
                    Fak_Denom_eta[c]->Fill(eta, nLmFakDenom);
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

        Fak_Num_eta   [c]->Write();
        Fak_Denom_eta [c]->Write();

        Fak_Num_pT12  [c]->Write();
        Fak_Denom_pT12[c]->Write();
    }
    // cent 0-10
    TH1D *   Eff_Num_eta_0_10 = (TH1D*) Eff_Num_eta[0]  ->Clone(  "Eff_Num_eta_0_10");
    TH1D *   Eff_Acc_eta_0_10 = (TH1D*) Eff_Acc_eta[0]  ->Clone(  "Eff_Acc_eta_0_10");
    TH1D * Eff_Denom_eta_0_10 = (TH1D*) Eff_Denom_eta[0]->Clone("Eff_Denom_eta_0_10");

    TH1D *   Eff_Num_pT12_0_10 = (TH1D*) Eff_Num_pT12[0]  ->Clone(  "Eff_Num_pT12_0_10");
    TH1D *   Eff_Acc_pT12_0_10 = (TH1D*) Eff_Acc_pT12[0]  ->Clone(  "Eff_Acc_pT12_0_10");
    TH1D * Eff_Denom_pT12_0_10 = (TH1D*) Eff_Denom_pT12[0]->Clone("Eff_Denom_pT12_0_10");

    TH1D *   Fak_Num_eta_0_10 = (TH1D*) Fak_Num_eta[0]  ->Clone(  "Fak_Num_eta_0_10");
    TH1D * Fak_Denom_eta_0_10 = (TH1D*) Fak_Denom_eta[0]->Clone("Fak_Denom_eta_0_10");

    TH1D *   Fak_Num_pT12_0_10 = (TH1D*) Fak_Num_pT12[0]  ->Clone(  "Fak_Num_pT12_0_10");
    TH1D * Fak_Denom_pT12_0_10 = (TH1D*) Fak_Denom_pT12[0]->Clone("Fak_Denom_pT12_0_10");

    // cent 10-30
    TH1D *   Eff_Num_eta_10_30 = (TH1D*)   Eff_Num_eta[1]->Clone(  "Eff_Num_eta_10_30");
    TH1D *   Eff_Acc_eta_10_30 = (TH1D*)   Eff_Acc_eta[1]->Clone(  "Eff_Acc_eta_10_30");
    TH1D * Eff_Denom_eta_10_30 = (TH1D*) Eff_Denom_eta[1]->Clone("Eff_Denom_eta_10_30");

    TH1D *   Eff_Num_pT12_10_30 = (TH1D*)   Eff_Num_pT12[1]->Clone(  "Eff_Num_pT12_10_30");
    TH1D *   Eff_Acc_pT12_10_30 = (TH1D*)   Eff_Acc_pT12[1]->Clone(  "Eff_Acc_pT12_10_30");
    TH1D * Eff_Denom_pT12_10_30 = (TH1D*) Eff_Denom_pT12[1]->Clone("Eff_Denom_pT12_10_30");

    TH1D *   Fak_Num_eta_10_30 = (TH1D*) Fak_Num_eta[1]  ->Clone(  "Fak_Num_eta_10_30");
    TH1D * Fak_Denom_eta_10_30 = (TH1D*) Fak_Denom_eta[1]->Clone("Fak_Denom_eta_10_30");

    TH1D *   Fak_Num_pT12_10_30 = (TH1D*) Fak_Num_pT12[1]  ->Clone(  "Fak_Num_pT12_10_30");
    TH1D * Fak_Denom_pT12_10_30 = (TH1D*) Fak_Denom_pT12[1]->Clone("Fak_Denom_pT12_10_30");

      Eff_Num_eta_10_30->Add(  Eff_Num_eta[2]);
      Eff_Acc_eta_10_30->Add(  Eff_Acc_eta[2]);
    Eff_Denom_eta_10_30->Add(Eff_Denom_eta[2]);

      Eff_Num_pT12_10_30->Add(  Eff_Num_pT12[2]);
      Eff_Acc_pT12_10_30->Add(  Eff_Acc_pT12[2]);
    Eff_Denom_pT12_10_30->Add(Eff_Denom_pT12[2]);

      Fak_Num_eta_10_30->Add(  Fak_Num_eta[2]);
    Fak_Denom_eta_10_30->Add(Fak_Denom_eta[2]);

      Fak_Num_pT12_10_30->Add(  Fak_Num_pT12[2]);
    Fak_Denom_pT12_10_30->Add(Fak_Denom_pT12[2]);

    // cent 30-50
    TH1D *   Eff_Num_eta_30_50 = (TH1D*)   Eff_Num_eta[3]->Clone(  "Eff_Num_eta_30_50");
    TH1D *   Eff_Acc_eta_30_50 = (TH1D*)   Eff_Acc_eta[3]->Clone(  "Eff_Acc_eta_30_50");
    TH1D * Eff_Denom_eta_30_50 = (TH1D*) Eff_Denom_eta[3]->Clone("Eff_Denom_eta_30_50");

    TH1D *   Eff_Num_pT12_30_50 = (TH1D*)   Eff_Num_pT12[3]->Clone(  "Eff_Num_pT12_30_50");
    TH1D *   Eff_Acc_pT12_30_50 = (TH1D*)   Eff_Acc_pT12[3]->Clone(  "Eff_Acc_pT12_30_50");
    TH1D * Eff_Denom_pT12_30_50 = (TH1D*) Eff_Denom_pT12[3]->Clone("Eff_Denom_pT12_30_50");

    TH1D *   Fak_Num_eta_30_50 = (TH1D*) Fak_Num_eta[3]  ->Clone(  "Fak_Num_eta_30_50");
    TH1D * Fak_Denom_eta_30_50 = (TH1D*) Fak_Denom_eta[3]->Clone("Fak_Denom_eta_30_50");

    TH1D *   Fak_Num_pT12_30_50 = (TH1D*) Fak_Num_pT12[3]  ->Clone(  "Fak_Num_pT12_30_50");
    TH1D * Fak_Denom_pT12_30_50 = (TH1D*) Fak_Denom_pT12[3]->Clone("Fak_Denom_pT12_30_50");

      Eff_Num_eta_30_50->Add(  Eff_Num_eta[4]);
      Eff_Acc_eta_30_50->Add(  Eff_Acc_eta[4]);
    Eff_Denom_eta_30_50->Add(Eff_Denom_eta[4]);

      Eff_Num_pT12_30_50->Add(  Eff_Num_pT12[4]);
      Eff_Acc_pT12_30_50->Add(  Eff_Acc_pT12[4]);
    Eff_Denom_pT12_30_50->Add(Eff_Denom_pT12[4]);

      Fak_Num_eta_30_50->Add(  Fak_Num_eta[4]);
    Fak_Denom_eta_30_50->Add(Fak_Denom_eta[4]);

      Fak_Num_pT12_30_50->Add(  Fak_Num_pT12[4]);
    Fak_Denom_pT12_30_50->Add(Fak_Denom_pT12[4]);

    // cent 50-80
    TH1D *   Eff_Num_eta_50_80 = (TH1D*)   Eff_Num_eta[5]->Clone(  "Eff_Num_eta_50_80");
    TH1D *   Eff_Acc_eta_50_80 = (TH1D*)   Eff_Acc_eta[5]->Clone(  "Eff_Acc_eta_50_80");
    TH1D * Eff_Denom_eta_50_80 = (TH1D*) Eff_Denom_eta[5]->Clone("Eff_Denom_eta_50_80");

    TH1D *   Eff_Num_pT12_50_80 = (TH1D*)   Eff_Num_pT12[5]->Clone(  "Eff_Num_pT12_50_80");
    TH1D *   Eff_Acc_pT12_50_80 = (TH1D*)   Eff_Acc_pT12[5]->Clone(  "Eff_Acc_pT12_50_80");
    TH1D * Eff_Denom_pT12_50_80 = (TH1D*) Eff_Denom_pT12[5]->Clone("Eff_Denom_pT12_50_80");

    TH1D *   Fak_Num_eta_50_80 = (TH1D*) Fak_Num_eta[5]  ->Clone(  "Fak_Num_eta_50_80");
    TH1D * Fak_Denom_eta_50_80 = (TH1D*) Fak_Denom_eta[5]->Clone("Fak_Denom_eta_50_80");

    TH1D *   Fak_Num_pT12_50_80 = (TH1D*) Fak_Num_pT12[5]  ->Clone(  "Fak_Num_pT12_50_80");
    TH1D * Fak_Denom_pT12_50_80 = (TH1D*) Fak_Denom_pT12[5]->Clone("Fak_Denom_pT12_50_80");

      Eff_Num_eta_50_80->Add(  Eff_Num_eta[6]);
      Eff_Acc_eta_50_80->Add(  Eff_Acc_eta[6]);
    Eff_Denom_eta_50_80->Add(Eff_Denom_eta[6]);

      Eff_Num_pT12_50_80->Add(  Eff_Num_pT12[6]);
      Eff_Acc_pT12_50_80->Add(  Eff_Acc_pT12[6]);
    Eff_Denom_pT12_50_80->Add(Eff_Denom_pT12[6]);

      Eff_Num_eta_50_80->Add(  Eff_Num_eta[7]);
      Eff_Acc_eta_50_80->Add(  Eff_Acc_eta[7]);
    Eff_Denom_eta_50_80->Add(Eff_Denom_eta[7]);

      Eff_Num_pT12_50_80->Add(  Eff_Num_pT12[7]);
      Eff_Acc_pT12_50_80->Add(  Eff_Acc_pT12[7]);
    Eff_Denom_pT12_50_80->Add(Eff_Denom_pT12[7]);

      Fak_Num_eta_50_80->Add(  Fak_Num_eta[6]);
    Fak_Denom_eta_50_80->Add(Fak_Denom_eta[6]);
      Fak_Num_eta_50_80->Add(  Fak_Num_eta[7]);
    Fak_Denom_eta_50_80->Add(Fak_Denom_eta[7]);

      Fak_Num_pT12_50_80->Add(  Fak_Num_pT12[6]);
    Fak_Denom_pT12_50_80->Add(Fak_Denom_pT12[6]);
      Fak_Num_pT12_50_80->Add(  Fak_Num_pT12[7]);
    Fak_Denom_pT12_50_80->Add(Fak_Denom_pT12[7]);

    //
      Eff_Num_eta_0_10->Write();
      Eff_Acc_eta_0_10->Write();
    Eff_Denom_eta_0_10->Write();
      Eff_Num_eta_10_30->Write();
      Eff_Acc_eta_10_30->Write();
    Eff_Denom_eta_10_30->Write();
      Eff_Num_eta_30_50->Write();
      Eff_Acc_eta_30_50->Write();
    Eff_Denom_eta_30_50->Write();

      Eff_Num_pT12_0_10->Write();
      Eff_Acc_pT12_0_10->Write();
    Eff_Denom_pT12_0_10->Write();
      Eff_Num_pT12_10_30->Write();
      Eff_Acc_pT12_10_30->Write();
    Eff_Denom_pT12_10_30->Write();
      Eff_Num_pT12_30_50->Write();
      Eff_Acc_pT12_30_50->Write();
    Eff_Denom_pT12_30_50->Write();

      Fak_Num_eta_0_10->Write();
    Fak_Denom_eta_0_10->Write();
      Fak_Num_eta_10_30->Write();
    Fak_Denom_eta_10_30->Write();
      Fak_Num_eta_30_50->Write();
    Fak_Denom_eta_30_50->Write();
      Fak_Num_eta_50_80->Write();
    Fak_Denom_eta_50_80->Write();

      Fak_Num_pT12_0_10->Write();
    Fak_Denom_pT12_0_10->Write();
      Fak_Num_pT12_10_30->Write();
    Fak_Denom_pT12_10_30->Write();
      Fak_Num_pT12_30_50->Write();
    Fak_Denom_pT12_30_50->Write();
      Fak_Num_pT12_50_80->Write();
    Fak_Denom_pT12_50_80->Write();

    //
    TH1D * hAcc_eta_0_10 = (TH1D*) Eff_Acc_eta_0_10->Clone("hAcc_eta_0_10");
    TH1D * hEff_eta_0_10 = (TH1D*) Eff_Num_eta_0_10->Clone("hEff_eta_0_10");
    TH1D * hREC_eta_0_10 = (TH1D*) Eff_Num_eta_0_10->Clone("hREC_eta_0_10");

    TH1D * hAcc_eta_10_30 = (TH1D*) Eff_Acc_eta_10_30->Clone("hAcc_eta_10_30");
    TH1D * hEff_eta_10_30 = (TH1D*) Eff_Num_eta_10_30->Clone("hEff_eta_10_30");
    TH1D * hREC_eta_10_30 = (TH1D*) Eff_Num_eta_10_30->Clone("hREC_eta_10_30");

    TH1D * hAcc_eta_30_50 = (TH1D*) Eff_Acc_eta_30_50->Clone("hAcc_eta_30_50");
    TH1D * hEff_eta_30_50 = (TH1D*) Eff_Num_eta_30_50->Clone("hEff_eta_30_50");
    TH1D * hREC_eta_30_50 = (TH1D*) Eff_Num_eta_30_50->Clone("hREC_eta_30_50");

    TH1D * hAcc_eta_50_80 = (TH1D*) Eff_Acc_eta_50_80->Clone("hAcc_eta_50_80");
    TH1D * hEff_eta_50_80 = (TH1D*) Eff_Num_eta_50_80->Clone("hEff_eta_50_80");
    TH1D * hREC_eta_50_80 = (TH1D*) Eff_Num_eta_50_80->Clone("hREC_eta_50_80");

    hAcc_eta_0_10->Divide(Eff_Denom_eta_0_10);
    hEff_eta_0_10->Divide(Eff_Denom_eta_0_10);
    hREC_eta_0_10->Divide(  Eff_Acc_eta_0_10);

    hAcc_eta_10_30->Divide(Eff_Denom_eta_10_30);
    hEff_eta_10_30->Divide(Eff_Denom_eta_10_30);
    hREC_eta_10_30->Divide(  Eff_Acc_eta_10_30);

    hAcc_eta_30_50->Divide(Eff_Denom_eta_30_50);
    hEff_eta_30_50->Divide(Eff_Denom_eta_30_50);
    hREC_eta_30_50->Divide(  Eff_Acc_eta_30_50);

    hAcc_eta_50_80->Divide(Eff_Denom_eta_50_80);
    hEff_eta_50_80->Divide(Eff_Denom_eta_50_80);
    hREC_eta_50_80->Divide(  Eff_Acc_eta_50_80);

    TH1D * hAcc_pT12_0_10 = (TH1D*) Eff_Acc_pT12_0_10->Clone("hAcc_pT12_0_10");
    TH1D * hEff_pT12_0_10 = (TH1D*) Eff_Num_pT12_0_10->Clone("hEff_pT12_0_10");
    TH1D * hREC_pT12_0_10 = (TH1D*) Eff_Num_pT12_0_10->Clone("hREC_pT12_0_10");

    TH1D * hAcc_pT12_10_30 = (TH1D*) Eff_Acc_pT12_10_30->Clone("hAcc_pT12_10_30");
    TH1D * hEff_pT12_10_30 = (TH1D*) Eff_Num_pT12_10_30->Clone("hEff_pT12_10_30");
    TH1D * hREC_pT12_10_30 = (TH1D*) Eff_Num_pT12_10_30->Clone("hREC_pT12_10_30");

    TH1D * hAcc_pT12_30_50 = (TH1D*) Eff_Acc_pT12_30_50->Clone("hAcc_pT12_30_50");
    TH1D * hEff_pT12_30_50 = (TH1D*) Eff_Num_pT12_30_50->Clone("hEff_pT12_30_50");
    TH1D * hREC_pT12_30_50 = (TH1D*) Eff_Num_pT12_30_50->Clone("hREC_pT12_30_50");

    TH1D * hAcc_pT12_50_80 = (TH1D*) Eff_Acc_pT12_50_80->Clone("hAcc_pT12_50_80");
    TH1D * hEff_pT12_50_80 = (TH1D*) Eff_Num_pT12_50_80->Clone("hEff_pT12_50_80");
    TH1D * hREC_pT12_50_80 = (TH1D*) Eff_Num_pT12_50_80->Clone("hREC_pT12_50_80");

    hAcc_pT12_0_10->Divide(Eff_Denom_pT12_0_10);
    hEff_pT12_0_10->Divide(Eff_Denom_pT12_0_10);
    hREC_pT12_0_10->Divide(  Eff_Acc_pT12_0_10);

    hAcc_pT12_10_30->Divide(Eff_Denom_pT12_10_30);
    hEff_pT12_10_30->Divide(Eff_Denom_pT12_10_30);
    hREC_pT12_10_30->Divide(  Eff_Acc_pT12_10_30);

    hAcc_pT12_30_50->Divide(Eff_Denom_pT12_30_50);
    hEff_pT12_30_50->Divide(Eff_Denom_pT12_30_50);
    hREC_pT12_30_50->Divide(  Eff_Acc_pT12_30_50);

    hAcc_pT12_50_80->Divide(Eff_Denom_pT12_50_80);
    hEff_pT12_50_80->Divide(Eff_Denom_pT12_50_80);
    hREC_pT12_50_80->Divide(  Eff_Acc_pT12_50_80);

    TH1D * hFak_eta_0_10  = (TH1D*)  Fak_Num_eta_0_10->Clone("hFak_eta_0_10");
    TH1D * hFak_eta_10_30 = (TH1D*) Fak_Num_eta_10_30->Clone("hFak_eta_10_30");
    TH1D * hFak_eta_30_50 = (TH1D*) Fak_Num_eta_30_50->Clone("hFak_eta_30_50");
    TH1D * hFak_eta_50_80 = (TH1D*) Fak_Num_eta_50_80->Clone("hFak_eta_50_80");

    hFak_eta_0_10 ->Divide( Fak_Denom_eta_0_10);
    hFak_eta_10_30->Divide(Fak_Denom_eta_10_30);
    hFak_eta_30_50->Divide(Fak_Denom_eta_30_50);
    hFak_eta_50_80->Divide(Fak_Denom_eta_50_80);

    TH1D * hFak_pT12_0_10  = (TH1D*) Fak_Num_pT12_0_10 ->Clone("hFak_pT12_0_10");
    TH1D * hFak_pT12_10_30 = (TH1D*) Fak_Num_pT12_10_30->Clone("hFak_pT12_10_30");
    TH1D * hFak_pT12_30_50 = (TH1D*) Fak_Num_pT12_30_50->Clone("hFak_pT12_30_50");
    TH1D * hFak_pT12_50_80 = (TH1D*) Fak_Num_pT12_50_80->Clone("hFak_pT12_50_80");

    hFak_pT12_0_10 ->Divide(Fak_Denom_pT12_0_10);
    hFak_pT12_10_30->Divide(Fak_Denom_pT12_10_30);
    hFak_pT12_30_50->Divide(Fak_Denom_pT12_30_50);
    hFak_pT12_50_80->Divide(Fak_Denom_pT12_50_80);

    hAcc_eta_0_10->Write();
    hEff_eta_0_10->Write();
    hREC_eta_0_10->Write();

    hAcc_eta_10_30->Write();
    hEff_eta_10_30->Write();
    hREC_eta_10_30->Write();

    hAcc_eta_30_50->Write();
    hEff_eta_30_50->Write();
    hREC_eta_30_50->Write();

    hAcc_eta_50_80->Write();
    hEff_eta_50_80->Write();
    hREC_eta_50_80->Write();

    hAcc_pT12_0_10->Write();
    hEff_pT12_0_10->Write();
    hREC_pT12_0_10->Write();

    hAcc_pT12_10_30->Write();
    hEff_pT12_10_30->Write();
    hREC_pT12_10_30->Write();

    hAcc_pT12_30_50->Write();
    hEff_pT12_30_50->Write();
    hREC_pT12_30_50->Write();

    hAcc_pT12_50_80->Write();
    hEff_pT12_50_80->Write();
    hREC_pT12_50_80->Write();

    hFak_eta_0_10->Write();
    hFak_eta_10_30->Write();
    hFak_eta_30_50->Write();
    hFak_eta_50_80->Write();

    hFak_pT12_0_10->Write();
    hFak_pT12_10_30->Write();
    hFak_pT12_30_50->Write();
    hFak_pT12_50_80->Write();

    //////// Do 2D projection

    TH2D * Eff_num2D[10];
    TH2D * Eff_acc2D[10];
    TH2D * Eff_denom2D[10];
    TH2D * Fak_num2D[10];
    TH2D * Fak_denom2D[10];

    cout << " mass_start = " << mass_start << " mass_end = " << mass_end << endl;
    for ( int c = 0; c < 10; c++ ) {
        LamEff_num[c]->GetZaxis()->SetRange(mass_start, mass_end-1);
        LamEff_acc[c]->GetZaxis()->SetRange(mass_start, mass_end-1);
        LamEff_denom[c]->GetZaxis()->SetRange(mass_start, mass_end-1);
        LamFak_num[c]->GetZaxis()->SetRange(mass_start, mass_end-1);
        LamFak_denom[c]->GetZaxis()->SetRange(mass_start, mass_end-1);

        Eff_num2D[c] = (TH2D*) LamEff_num[c]->Project3D("yx");
        Eff_acc2D[c] = (TH2D*) LamEff_acc[c]->Project3D("yx");
        Eff_denom2D[c] = (TH2D*) LamEff_denom[c]->Project3D("yx");
        Fak_num2D[c] = (TH2D*) LamFak_num[c]->Project3D("yx");
        Fak_denom2D[c] = (TH2D*) LamFak_denom[c]->Project3D("yx");

        Eff_num2D[c]->RebinY(5);
        Eff_acc2D[c]->RebinY(5);
        Eff_denom2D[c]->RebinY(5);
        Fak_num2D[c]->RebinY(5);
        Fak_denom2D[c]->RebinY(5);
        LamEff_acc[c]->GetZaxis()->SetRange(mass_start, mass_end-1);
        LamEff_denom[c]->GetZaxis()->SetRange(mass_start, mass_end-1);
        Eff_acc2D[c] = (TH2D*) LamEff_acc[c]->Project3D("yx");
        Eff_denom2D[c] = (TH2D*) LamEff_denom[c]->Project3D("yx");
        Eff_acc2D[c]->RebinY(5);
        Eff_denom2D[c]->RebinY(5);

        Eff_num2D[c]->SetName(Form("Eff_num2D%i", c));
        Eff_acc2D[c]->SetName(Form("Eff_acc2D%i", c));
        Eff_denom2D[c]->SetName(Form("Eff_denom2D%i", c));
        Fak_num2D[c]->SetName(Form("Fak_num2D%i", c));
        Fak_denom2D[c]->SetName(Form("Fak_denom2D%i", c));

        Eff_num2D[c]->Write(Form("Eff_num2D%i", c));
        Eff_acc2D[c]->Write(Form("Eff_acc2D%i", c));
        Eff_denom2D[c]->Write(Form("Eff_denom2D%i", c));
        Fak_num2D[c]->Write(Form("Fak_num2D%i", c));
        Fak_denom2D[c]->Write(Form("Fak_denom2D%i", c));
    }

    TH2D * hAcc_0_10 = (TH2D*) Eff_acc2D[0]->Clone("hAcc_0_10");
    TH2D * hEff_0_10 = (TH2D*) Eff_num2D[0]->Clone("hEff_0_10");
    TH2D * hREC_0_10 = (TH2D*) Eff_num2D[0]->Clone("hREC_0_10");
    TH2D * hFak_0_10 = (TH2D*) Fak_num2D[0]->Clone("hFak_0_10");

    TH2D * hAcc_10_30 = (TH2D*) Eff_acc2D[1]->Clone("hAcc_10_30");
    TH2D * hEff_10_30 = (TH2D*) Eff_num2D[1]->Clone("hEff_10_30");
    TH2D * hREC_10_30 = (TH2D*) Eff_num2D[1]->Clone("hREC_10_30");
    TH2D * hFak_10_30 = (TH2D*) Fak_num2D[1]->Clone("hFak_10_30");

    hAcc_10_30->Add(Eff_acc2D[2]);
    hEff_10_30->Add(Eff_num2D[2]);
    hREC_10_30->Add(Eff_num2D[2]);
    hFak_10_30->Add(Fak_num2D[2]);

    Eff_denom2D[1]->Add(Eff_denom2D[2]);
    Fak_denom2D[1]->Add(Fak_denom2D[2]);

    TH2D * hAcc_30_50 = (TH2D*) Eff_acc2D[3]->Clone("hAcc_30_50");
    TH2D * hEff_30_50 = (TH2D*) Eff_num2D[3]->Clone("hEff_30_50");
    TH2D * hREC_30_50 = (TH2D*) Eff_num2D[3]->Clone("hREC_30_50");
    TH2D * hFak_30_50 = (TH2D*) Fak_num2D[3]->Clone("hFak_30_50");

    hAcc_30_50->Add(Eff_acc2D[4]);
    hEff_30_50->Add(Eff_num2D[4]);
    hREC_30_50->Add(Eff_num2D[4]);
    hFak_30_50->Add(Fak_num2D[4]);

    Eff_denom2D[3]->Add(Eff_denom2D[4]);
    Fak_denom2D[3]->Add(Fak_denom2D[4]);

    TH2D * hAcc_50_80 = (TH2D*) Eff_acc2D[5]->Clone("hAcc_50_80");
    TH2D * hEff_50_80 = (TH2D*) Eff_num2D[5]->Clone("hEff_50_80");
    TH2D * hREC_50_80 = (TH2D*) Eff_num2D[5]->Clone("hREC_50_80");
    TH2D * hFak_50_80 = (TH2D*) Fak_num2D[5]->Clone("hFak_50_80");

    hAcc_50_80->Add(Eff_acc2D[6]);
    hEff_50_80->Add(Eff_num2D[6]);
    hREC_50_80->Add(Eff_num2D[6]);
    hFak_50_80->Add(Fak_num2D[6]);

    hAcc_50_80->Add(Eff_acc2D[7]);
    hEff_50_80->Add(Eff_num2D[7]);
    hREC_50_80->Add(Eff_num2D[7]);
    hFak_50_80->Add(Fak_num2D[7]);

    Eff_denom2D[5]->Add(Eff_denom2D[6]);
    Fak_denom2D[5]->Add(Fak_denom2D[6]);

    Eff_denom2D[5]->Add(Eff_denom2D[7]);
    Fak_denom2D[5]->Add(Fak_denom2D[7]);


    hREC_0_10->Divide(hAcc_0_10);
    hAcc_0_10->Divide(Eff_denom2D[0]);
    hEff_0_10->Divide(Eff_denom2D[0]);
    hFak_0_10->Divide(Fak_denom2D[0]);

    hREC_10_30->Divide(hAcc_10_30);
    hAcc_10_30->Divide(Eff_denom2D[1]);
    hEff_10_30->Divide(Eff_denom2D[1]);
    hFak_10_30->Divide(Fak_denom2D[1]);

    hREC_30_50->Divide(hAcc_30_50);
    hAcc_30_50->Divide(Eff_denom2D[3]);
    hEff_30_50->Divide(Eff_denom2D[3]);
    hFak_30_50->Divide(Fak_denom2D[3]);

    hREC_50_80->Divide(hAcc_50_80);
    hAcc_50_80->Divide(Eff_denom2D[5]);
    hEff_50_80->Divide(Eff_denom2D[5]);
    hFak_50_80->Divide(Fak_denom2D[5]);

    hREC_0_10->Write();
    hAcc_0_10->Write();
    hEff_0_10->Write();
    hFak_0_10->Write();

    hREC_10_30->Write();
    hAcc_10_30->Write();
    hEff_10_30->Write();
    hFak_10_30->Write();

    hREC_30_50->Write();
    hAcc_30_50->Write();
    hEff_30_50->Write();
    hFak_30_50->Write();

    hREC_50_80->Write();
    hAcc_50_80->Write();
    hEff_50_80->Write();
    hFak_50_80->Write();
}
