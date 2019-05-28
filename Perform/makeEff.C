
{
    TFile * f = new TFile("../txt/v0_Hydro_eff_std.root");
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

    // Lm mass cut: 1.1115 - 1.1200, bin [64, 82)
    for ( int ieta = 0; ieta < 12; ieta++ ) {
        for ( int ipt = 0; ipt < Npt_bins; ipt++ ) {
            Eff_Num  ->SetBinContent( ieta+1, ipt+1, LamEff_num  ->Integral(ipt+1, ipt+1, ieta*4+2, ieta*4+5, 64, 81) );
            Eff_Denom->SetBinContent( ieta+1, ipt+1, LamEff_denom->Integral(ipt+1, ipt+1, ieta*4+2, ieta*4+5, 64, 81) );
            Fak_Num  ->SetBinContent( ieta+1, ipt+1, LamFake_num  ->Integral(ipt+1, ipt+1, ieta*4+2, ieta*4+5, 64, 81) );
            Fak_Denom->SetBinContent( ieta+1, ipt+1, LamFake_denom->Integral(ipt+1, ipt+1, ieta*4+2, ieta*4+5, 64, 81) );
        }
    }

    TH2D * hEff = (TH2D*) Eff_Num->Clone("hEff");
    TH2D * hFak = (TH2D*) Fak_Num->Clone("hFak");
    hEff->Divide(Eff_Denom);
    hFak->Divide(Fak_Denom);

}
