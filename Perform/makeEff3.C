
void makeEff3(string s = "../txt/v0_Hydjet_eff_std.root", string fout = "Lm_Hyjet_eff_std.root")
{
    TFile * f = new TFile(s.c_str());
    TH3D * LamEff_num = (TH3D*) f->Get("V0valid/Lm/LamEff_num");
    TH3D * LamEff_denom = (TH3D*) f->Get("V0valid/Lm/LamEff_denom");

    TH3D * LamFake_num = (TH3D*) f->Get("V0valid/Lm/LamFake_num");
    TH3D * LamTkFake_num = (TH3D*) f->Get("V0valid/Lm/LamTkFake_num");
    TH3D * LamFake_denom = (TH3D*) f->Get("V0valid/Lm/LamFake_denom");

    TH1D * LamEff_num_pT   = (TH1D*) LamEff_num->Project3D("x");
    TH1D * LamEff_num_eta  = (TH1D*) LamEff_num->Project3D("y");
    TH1D * LamEff_num_mass = (TH1D*) LamEff_num->Project3D("z");

    const double * pt_bins   = LamEff_num->GetXaxis()->GetXbins()->GetArray();
    const double * eta_bins  = LamEff_num->GetYaxis()->GetXbins()->GetArray();
    const double * mass_bins = LamEff_num->GetZaxis()->GetXbins()->GetArray();

    int Npt_bins   = LamEff_num->GetXaxis()->GetNbins();
    int Neta_bins  = LamEff_num->GetYaxis()->GetNbins();
    int Nmass_bins = LamEff_num->GetZaxis()->GetNbins();

    auto pt_axis   = LamEff_num->GetXaxis();
    auto eta_axis  = LamEff_num->GetYaxis();
    auto mass_axis = LamEff_num->GetZaxis();

    TH1D * LamEff_denom_pT   = (TH1D*) LamEff_denom->Project3D("x");
    TH1D * LamEff_denom_eta  = (TH1D*) LamEff_denom->Project3D("y");
    TH1D * LamEff_denom_mass = (TH1D*) LamEff_denom->Project3D("z");

    TH1D * LamFake_num_pT   = (TH1D*) LamFake_num->Project3D("x");
    TH1D * LamFake_num_eta  = (TH1D*) LamFake_num->Project3D("y");
    TH1D * LamFake_num_mass = (TH1D*) LamFake_num->Project3D("z");

    TH1D * LamTkFake_num_pT   = (TH1D*) LamTkFake_num->Project3D("x");
    TH1D * LamTkFake_num_eta  = (TH1D*) LamTkFake_num->Project3D("y");
    TH1D * LamTkFake_num_mass = (TH1D*) LamTkFake_num->Project3D("z");

    TH1D * LamFake_denom_pT   = (TH1D*) LamFake_denom->Project3D("x");
    TH1D * LamFake_denom_eta  = (TH1D*) LamFake_denom->Project3D("y");
    TH1D * LamFake_denom_mass = (TH1D*) LamFake_denom->Project3D("z");


    double eff_eta_bins[13] = { -2.4, -2.0, -1.6, -1.2, -0.8, -0.4, 0., 0.4, 0.8, 1.2, 1.6, 2.0, 2.4};

    TH2D * Eff_Num   = new TH2D("Eff_Num",   "Eff_Num",   12, eff_eta_bins, Npt_bins, pt_bins);
    TH2D * Eff_Denom = new TH2D("Eff_Denom", "Eff_Denom", 12, eff_eta_bins, Npt_bins, pt_bins);

    TH2D * Fak_Num   = new TH2D("Fak_Num",   "Fak_Num",   12, eff_eta_bins, Npt_bins, pt_bins);
    TH2D * Fak_Denom = new TH2D("Fak_Denom", "Fak_Denom", 12, eff_eta_bins, Npt_bins, pt_bins);


    TH1D * Eff_Num_pT12   = new TH1D("Eff_Num_pT12", "Eff_Num_pT12", Npt_bins, pt_bins);
    TH1D * Eff_Denom_pT12 = new TH1D("Eff_Denom_pT12", "Eff_Denom_pT12", Npt_bins, pt_bins);

// pt                            0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12
//    double pTbin[14] = {0.2, 0.4, 0.6, 0.8, 1.0, 1.4, 1.8, 2.2, 2.8, 3.6, 4.6, 6.0, 7.0, 8.5};
    TH1D * Eff_Num_eta = new TH1D("Eff_Num_eta", "Eff_Num_eta", 12, eff_eta_bins); // 1.8 - 8.5
    TH1D * Eff_Denom_eta = new TH1D("Eff_Denom_eta", "Eff_Denom_eta", 12, eff_eta_bins); // 1.8 - 8.5

    // Lm mass cut: 1.1115 - 1.1200, bin [64, 82)
    for ( int ieta = 0; ieta < 12; ieta++ ) {
        for ( int ipt = 0; ipt < Npt_bins; ipt++ ) {
            Eff_Num  ->SetBinContent( ieta+1, ipt+1, LamEff_num  ->Integral(ipt+1, ipt+1, ieta*4+2, ieta*4+5, 64, 81) );
            Eff_Denom->SetBinContent( ieta+1, ipt+1, LamEff_denom->Integral(ipt+1, ipt+1, ieta*4+2, ieta*4+5, 64, 81) );
            Fak_Num  ->SetBinContent( ieta+1, ipt+1, LamFake_num  ->Integral(ipt+1, ipt+1, ieta*4+2, ieta*4+5, 64, 81) );
            Fak_Denom->SetBinContent( ieta+1, ipt+1, LamFake_denom->Integral(ipt+1, ipt+1, ieta*4+2, ieta*4+5, 64, 81) );
        }
    }

    // eta range: -1.2 - 1.2, [14, 38)
    for ( int ieta = 13; ieta < 37; ieta++ ) {
        double eta = eta_axis->GetBinCenter(ieta+1);
        for ( int ipt = 0; ipt < Npt_bins; ipt++ ) {
            double pt = pt_axis->GetBinCenter(ipt+1);
            for ( int imass = 64; imass < 82; imass++ ) {
                double nLmEff = LamEff_num->GetBinContent( ipt+1, ieta+1, imass );
                double nLmDenom = LamEff_denom->GetBinContent( ipt+1, ieta+1, imass );

                Eff_Num_pT12->Fill( pt, nLmEff );
                Eff_Denom_pT12->Fill( pt, nLmDenom );
            }
        }
    }

    // pt range: 1.8 - 8.5  [7, 14)
    for ( int ieta = 0; ieta < Neta_bins; ieta++ ) {
        double eta = eta_axis->GetBinCenter(ieta+1);
        for ( int ipt = 6; ipt < 13; ipt++ ) {
            double pt = pt_axis->GetBinCenter(ipt+1);
            for ( int imass = 64; imass < 82; imass++ ) {
                double nLmEff = LamEff_num->GetBinContent( ipt+1, ieta+1, imass );
                double nLmDenom = LamEff_denom->GetBinContent( ipt+1, ieta+1, imass );

                Eff_Num_eta->Fill( eta, nLmEff );
                Eff_Denom_eta->Fill( eta, nLmDenom );
            }
        }
    }


    TH2D * hEff = (TH2D*) Eff_Num->Clone("hEff");
    TH2D * hFak = (TH2D*) Fak_Num->Clone("hFak");
    hEff->Divide(Eff_Denom);
    hFak->Divide(Fak_Denom);

    TFile * fsave = new TFile(fout.c_str(), "recreate");
    Eff_Num->Write();
    Eff_Denom->Write();
    Fak_Num->Write();
    Fak_Denom->Write();
    hEff->Write();
    hFak->Write();

    Eff_Num_eta->Write();
    Eff_Denom_eta->Write();
    Eff_Num_pT12->Write();
    Eff_Denom_pT12->Write();

    TH1D* hEff_eta = (TH1D*) Eff_Num_eta->Clone("hEff_eta");
    TH1D* hEff_pT = (TH1D*) Eff_Num_pT12->Clone("hEff_pT");
    hEff_eta->Divide(Eff_Denom_eta);
    hEff_pT->Divide(Eff_Denom_pT12);
    hEff_eta->Write();
    hEff_pT->Write();


}
