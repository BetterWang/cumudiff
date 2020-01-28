
void plotMCsignificance(string s = "LM")
{
    TGraph * grSig = new TGraph( 51 );
    TGraph * grSig_pTrkDCASigXY = new TGraph( 51 );
    TGraph * grSig_nTrkDCASigXY = new TGraph( 51 );
    TGraph * grSig_pTrkDCASigZ  = new TGraph( 51 );
    TGraph * grSig_nTrkDCASigZ  = new TGraph( 51 );

    TGraph * grSB = new TGraph( 51 );
    TGraph * grSB_pTrkDCASigXY = new TGraph( 51 );
    TGraph * grSB_nTrkDCASigXY = new TGraph( 51 );
    TGraph * grSB_pTrkDCASigZ  = new TGraph( 51 );
    TGraph * grSB_nTrkDCASigZ  = new TGraph( 51 );

    double massLow = 1.1115;
    double massHigh= 1.2;
    if ( s == "KS" ) {
        massLow = 0.492;
        massHigh= 0.503;
    }

    for ( int i = 0; i < 51; i++ ) {
        TFile f((s + to_string(i) + ".root").c_str());
        TH1D * hs = (TH1D*) f.Get("hmass_Signal");
        TH1D * hb = (TH1D*) f.Get("hmass_Bckgnd");

        double S = hs->Integral(hs->FindBin(massLow), hs->FindBin(massHigh));
        double B = hb->Integral(hb->FindBin(massLow), hb->FindBin(massHigh));

        grSig->GetX()[i] = i*0.01;
        grSig->GetY()[i] = S/sqrt(S+B);
        grSB->GetX()[i] = i*0.01;
        grSB->GetY()[i]  = S/B;

        hs = (TH1D*) f.Get("hmass_Signal_pTrkDCASigXY");
        hb = (TH1D*) f.Get("hmass_Bckgnd_pTrkDCASigXY");
        S = hs->Integral(hs->FindBin(massLow), hs->FindBin(massHigh));
        B = hb->Integral(hb->FindBin(massLow), hb->FindBin(massHigh));
        grSig_pTrkDCASigXY->GetX()[i] = i*0.01;
        grSig_pTrkDCASigXY->GetY()[i] = S/sqrt(S+B);
        grSB_pTrkDCASigXY->GetX()[i] = i*0.01;
        grSB_pTrkDCASigXY->GetY()[i]  = S/B;

        hs = (TH1D*) f.Get("hmass_Signal_nTrkDCASigXY");
        hb = (TH1D*) f.Get("hmass_Bckgnd_nTrkDCASigXY");
        S = hs->Integral(hs->FindBin(massLow), hs->FindBin(massHigh));
        B = hb->Integral(hb->FindBin(massLow), hb->FindBin(massHigh));
        grSig_nTrkDCASigXY->GetX()[i] = i*0.01;
        grSig_nTrkDCASigXY->GetY()[i] = S/sqrt(S+B);
        grSB_nTrkDCASigXY->GetX()[i] = i*0.01;
        grSB_nTrkDCASigXY->GetY()[i]  = S/B;

        hs = (TH1D*) f.Get("hmass_Signal_pTrkDCASigZ");
        hb = (TH1D*) f.Get("hmass_Bckgnd_pTrkDCASigZ");
        S = hs->Integral(hs->FindBin(massLow), hs->FindBin(massHigh));
        B = hb->Integral(hb->FindBin(massLow), hb->FindBin(massHigh));
        grSig_pTrkDCASigZ->GetX()[i] = i*0.01;
        grSig_pTrkDCASigZ->GetY()[i] = S/sqrt(S+B);
        grSB_pTrkDCASigZ->GetX()[i] = i*0.01;
        grSB_pTrkDCASigZ->GetY()[i]  = S/B;

        hs = (TH1D*) f.Get("hmass_Signal_nTrkDCASigZ");
        hb = (TH1D*) f.Get("hmass_Bckgnd_nTrkDCASigZ");
        S = hs->Integral(hs->FindBin(massLow), hs->FindBin(massHigh));
        B = hb->Integral(hb->FindBin(massLow), hb->FindBin(massHigh));
        grSig_nTrkDCASigZ->GetX()[i] = i*0.01;
        grSig_nTrkDCASigZ->GetY()[i] = S/sqrt(S+B);
        grSB_nTrkDCASigZ->GetX()[i] = i*0.01;
        grSB_nTrkDCASigZ->GetY()[i]  = S/B;
        delete hs;
        delete hb;
    }

    TFile * fsave = new TFile( (s+"8_Sig.root").c_str(), "recreate" );
    grSig->Write("grSig");
    grSig_pTrkDCASigXY->Write("grSig_pTrkDCASigXY");
    grSig_nTrkDCASigXY->Write("grSig_nTrkDCASigXY");
    grSig_pTrkDCASigZ->Write("grSig_pTrkDCASigZ");
    grSig_nTrkDCASigZ->Write("grSig_nTrkDCASigZ");

    grSB->Write("grSB");
    grSB_pTrkDCASigXY->Write("grSB_pTrkDCASigXY");
    grSB_nTrkDCASigXY->Write("grSB_nTrkDCASigXY");
    grSB_pTrkDCASigZ->Write("grSB_pTrkDCASigZ");
    grSB_nTrkDCASigZ->Write("grSB_nTrkDCASigZ");
}
