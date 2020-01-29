

void reweightMVA(string s = "LM")
{
    TFile * fMC_Sig = 0;
    TFile * fMC_Bkg = 0;
    TFile * fData = 0;

    TH1D * hpTrkDCASigXY_Sig = 0;
    TH1D * hnTrkDCASigXY_Sig = 0;
    TH1D * hpTrkDCASigXY_Bkg = 0;
    TH1D * hnTrkDCASigXY_Bkg = 0;
    TH1D * hpTrkDCASigXY_Data = 0;
    TH1D * hnTrkDCASigXY_Data = 0;

    TH1D * hpTrkDCASigZ_Sig = 0;
    TH1D * hnTrkDCASigZ_Sig = 0;
    TH1D * hpTrkDCASigZ_Bkg = 0;
    TH1D * hnTrkDCASigZ_Bkg = 0;
    TH1D * hpTrkDCASigZ_Data = 0;
    TH1D * hnTrkDCASigZ_Data = 0;

    if ( s == "LM" ) {
        fMC_Sig = new TFile("HistHydjetMCTruth_LM.root");
        fMC_Bkg = new TFile("HistHydjetMCBkg_LM.root");
        fData = new TFile("HistData_LM.root");

    } else {
        fMC_Sig = new TFile("HistHydjetMCTruth_KS.root");
        fMC_Bkg = new TFile("HistHydjetMCBkg_KS.root");
        fData = new TFile("HistData_KS.root");
    }
    hpTrkDCASigXY_Sig = (TH1D*) fMC_Sig->Get("hpTrkDCASigXY");
    hnTrkDCASigXY_Sig = (TH1D*) fMC_Sig->Get("hnTrkDCASigXY");
    hpTrkDCASigXY_Bkg = (TH1D*) fMC_Bkg->Get("hpTrkDCASigXY");
    hnTrkDCASigXY_Bkg = (TH1D*) fMC_Bkg->Get("hnTrkDCASigXY");

    hpTrkDCASigXY_Data = (TH1D*) fData->Get("hpTrkDCASigXY");
    hnTrkDCASigXY_Data = (TH1D*) fData->Get("hnTrkDCASigXY");

    hpTrkDCASigZ_Sig = (TH1D*) fMC_Sig->Get("hpTrkDCASigZ");
    hnTrkDCASigZ_Sig = (TH1D*) fMC_Sig->Get("hnTrkDCASigZ");
    hpTrkDCASigZ_Bkg = (TH1D*) fMC_Bkg->Get("hpTrkDCASigZ");
    hnTrkDCASigZ_Bkg = (TH1D*) fMC_Bkg->Get("hnTrkDCASigZ");

    hpTrkDCASigZ_Data = (TH1D*) fData->Get("hpTrkDCASigZ");
    hnTrkDCASigZ_Data = (TH1D*) fData->Get("hnTrkDCASigZ");


    hpTrkDCASigXY_Sig->Add(hpTrkDCASigXY_Bkg);
    hnTrkDCASigXY_Sig->Add(hnTrkDCASigXY_Bkg);

    hpTrkDCASigZ_Sig->Add(hpTrkDCASigZ_Bkg);
    hnTrkDCASigZ_Sig->Add(hnTrkDCASigZ_Bkg);

    //
    hpTrkDCASigXY_Sig->Rebin(20);
    hnTrkDCASigXY_Sig->Rebin(20);
    hpTrkDCASigZ_Sig->Rebin(20);
    hnTrkDCASigZ_Sig->Rebin(20);

    hpTrkDCASigXY_Data->Rebin(20);
    hnTrkDCASigXY_Data->Rebin(20);
    hpTrkDCASigZ_Data->Rebin(20);
    hnTrkDCASigZ_Data->Rebin(20);

    hpTrkDCASigXY_Sig->Divide(hpTrkDCASigXY_Data);
    hnTrkDCASigXY_Sig->Divide(hnTrkDCASigXY_Data);
    hpTrkDCASigZ_Sig->Divide(hpTrkDCASigZ_Data);
    hnTrkDCASigZ_Sig->Divide(hnTrkDCASigZ_Data);

    double pscale = hpTrkDCASigXY_Sig->GetEntries();
    double nscale = hnTrkDCASigXY_Sig->GetEntries();

    pscale += hpTrkDCASigXY_Bkg->GetEntries();
    nscale += hnTrkDCASigXY_Bkg->GetEntries();
    pscale /= hpTrkDCASigXY_Data->GetEntries();
    nscale /= hnTrkDCASigXY_Data->GetEntries();

    hpTrkDCASigXY_Sig->Scale( 1./pscale );
    hnTrkDCASigXY_Sig->Scale( 1./nscale );
    hpTrkDCASigZ_Sig->Scale( 1./pscale );
    hnTrkDCASigZ_Sig->Scale( 1./nscale );

    TFile * fsave = 0;
    if ( s == "LM" ) {
        fsave = new TFile("LM_reweight.root", "recreate");
    } else {
        fsave = new TFile("KS_reweight.root", "recreate");
    }

    hpTrkDCASigXY_Sig->Write("hWpTrkDCASigXY");
    hnTrkDCASigXY_Sig->Write("hWnTrkDCASigXY");
    hpTrkDCASigZ_Sig->Write("hWpTrkDCASigZ");
    hnTrkDCASigZ_Sig->Write("hWnTrkDCASigZ");
}
