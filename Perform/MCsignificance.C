


void MCsignificance(string s = "LM", int BDT = 15, int centMin = 0, int centMax = 160)
{
    bool bReweight = true;
    TFile * f = 0;
    TTree * testTree = 0;
    TH1D * hmass_Signal = 0;
    TH1D * hmass_Bckgnd = 0;

    TH1D * hmass_Signal_pTrkDCASigXY = 0;
    TH1D * hmass_Bckgnd_pTrkDCASigXY = 0;
    TH1D * hmass_Signal_nTrkDCASigXY = 0;
    TH1D * hmass_Bckgnd_nTrkDCASigXY = 0;

    TH1D * hmass_Signal_pTrkDCASigZ  = 0;
    TH1D * hmass_Bckgnd_pTrkDCASigZ  = 0;
    TH1D * hmass_Signal_nTrkDCASigZ  = 0;
    TH1D * hmass_Bckgnd_nTrkDCASigZ  = 0;


    TFile * reweight = 0;
    TH1D * hWpTrkDCASigXY = 0;
    TH1D * hWnTrkDCASigXY = 0;
    TH1D * hWpTrkDCASigZ = 0;
    TH1D * hWnTrkDCASigZ = 0;

    if ( s == "LM" ) {
        f = new TFile("TMVA3_HydjetMCTruth_MCBkg_LM.root");
        testTree = (TTree*) f->Get("dataset3_full_LM/TestTree");
        hmass_Signal = new TH1D("hmass_Signal", "", 160, 1.08, 1.16);
        hmass_Bckgnd = new TH1D("hmass_Bckgnd", "", 160, 1.08, 1.16);

        reweight = new TFile("LM_reweight.root");
    } else {
        f = new TFile("TMVA3_HydjetMCTruth_MCBkg_KS.root");
        testTree = (TTree*) f->Get("dataset3_full_KS/TestTree");
        hmass_Signal = new TH1D("hmass_Signal", "", 270, 0.430, 0.565);
        hmass_Bckgnd = new TH1D("hmass_Bckgnd", "", 270, 0.430, 0.565);

        reweight = new TFile("KS_reweight.root");
    }
    if ( reweight->IsZombie() ) {
        bReweight = false;
        cout << " --> failed to open reweight file." << endl;
    } else {
        hWpTrkDCASigXY = (TH1D*) reweight->Get("hWpTrkDCASigXY");
        hWnTrkDCASigXY = (TH1D*) reweight->Get("hWnTrkDCASigXY");
        hWpTrkDCASigZ  = (TH1D*) reweight->Get("hWpTrkDCASigZ");
        hWnTrkDCASigZ  = (TH1D*) reweight->Get("hWnTrkDCASigZ");
    }
    hmass_Signal_pTrkDCASigXY = (TH1D*) hmass_Signal->Clone("hmass_Signal_pTrkDCASigXY");
    hmass_Signal_nTrkDCASigXY = (TH1D*) hmass_Signal->Clone("hmass_Signal_nTrkDCASigXY");
    hmass_Signal_pTrkDCASigZ  = (TH1D*) hmass_Signal->Clone("hmass_Signal_pTrkDCASigZ");
    hmass_Signal_nTrkDCASigZ  = (TH1D*) hmass_Signal->Clone("hmass_Signal_nTrkDCASigZ");

    hmass_Bckgnd_pTrkDCASigXY = (TH1D*) hmass_Bckgnd->Clone("hmass_Bckgnd_pTrkDCASigXY");
    hmass_Bckgnd_nTrkDCASigXY = (TH1D*) hmass_Bckgnd->Clone("hmass_Bckgnd_nTrkDCASigXY");
    hmass_Bckgnd_pTrkDCASigZ  = (TH1D*) hmass_Bckgnd->Clone("hmass_Bckgnd_pTrkDCASigZ");
    hmass_Bckgnd_nTrkDCASigZ  = (TH1D*) hmass_Bckgnd->Clone("hmass_Bckgnd_nTrkDCASigZ");

    Int_t           classID;
    Float_t         Cent;
    Float_t         mass;
    Float_t         BDT250_D4;
    Float_t         pt;
    Float_t         rapidity;
    Float_t         pTrkDCASigXY;
    Float_t         pTrkDCASigZ;
    Float_t         nTrkDCASigXY;
    Float_t         nTrkDCASigZ;

    testTree->SetBranchAddress("classID", &classID );
    testTree->SetBranchAddress("Cent", &Cent );
    testTree->SetBranchAddress("mass", &mass );
    testTree->SetBranchAddress("BDT250_D4", &BDT250_D4 );
    testTree->SetBranchAddress("pt", &pt );
    testTree->SetBranchAddress("rapidity", &rapidity);

    testTree->SetBranchAddress("pTrkDCASigXY", &pTrkDCASigXY );
    testTree->SetBranchAddress("pTrkDCASigZ", &pTrkDCASigZ );
    testTree->SetBranchAddress("nTrkDCASigXY", &nTrkDCASigXY );
    testTree->SetBranchAddress("nTrkDCASigZ", &nTrkDCASigZ );

    int idx = 0;
    while ( testTree->GetEntry(idx++) ) {
        if ( Cent < centMin or Cent >= centMax ) continue;
        if ( fabs(rapidity) > 1.0 ) continue;
        if ( BDT250_D4 > BDT*0.01 ) {
            double dbpTrkDCASigXY = 1.;
            double dbnTrkDCASigXY = 1.;
            double dbpTrkDCASigZ  = 1.;
            double dbnTrkDCASigZ  = 1.;

            if ( bReweight ) {
                dbpTrkDCASigXY = hWpTrkDCASigXY->GetBinContent( hWpTrkDCASigXY->FindBin(pTrkDCASigXY) );
                dbnTrkDCASigXY = hWnTrkDCASigXY->GetBinContent( hWnTrkDCASigXY->FindBin(nTrkDCASigXY) );

                dbpTrkDCASigZ  = hWpTrkDCASigZ ->GetBinContent( hWpTrkDCASigZ ->FindBin(pTrkDCASigZ ) );
                dbnTrkDCASigZ  = hWnTrkDCASigZ ->GetBinContent( hWnTrkDCASigZ ->FindBin(nTrkDCASigZ ) );
            }

            if ( classID == 0 ) {
                hmass_Signal->Fill( mass );
                hmass_Signal_pTrkDCASigXY->Fill( mass, dbpTrkDCASigXY );
                hmass_Signal_nTrkDCASigXY->Fill( mass, dbnTrkDCASigXY );
                hmass_Signal_pTrkDCASigZ ->Fill( mass, dbpTrkDCASigZ  );
                hmass_Signal_nTrkDCASigZ ->Fill( mass, dbnTrkDCASigZ  );
            } else {
                hmass_Bckgnd->Fill( mass );
                hmass_Bckgnd_pTrkDCASigXY->Fill( mass, dbpTrkDCASigXY );
                hmass_Bckgnd_nTrkDCASigXY->Fill( mass, dbnTrkDCASigXY );
                hmass_Bckgnd_pTrkDCASigZ ->Fill( mass, dbpTrkDCASigZ  );
                hmass_Bckgnd_nTrkDCASigZ ->Fill( mass, dbnTrkDCASigZ  );
            }
        }
    }

    TFile * fsave = new TFile( (s + to_string(BDT) + ".root").c_str(), "recreate" );
    hmass_Signal->Write();
    hmass_Bckgnd->Write();

    hmass_Signal_pTrkDCASigXY->Write();
    hmass_Signal_nTrkDCASigXY->Write();
    hmass_Signal_pTrkDCASigZ ->Write();
    hmass_Signal_nTrkDCASigZ ->Write();

    hmass_Bckgnd_pTrkDCASigXY->Write();
    hmass_Bckgnd_nTrkDCASigXY->Write();
    hmass_Bckgnd_pTrkDCASigZ ->Write();
    hmass_Bckgnd_nTrkDCASigZ ->Write();
}
