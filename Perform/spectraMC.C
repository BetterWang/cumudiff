
void spectraMC(string s = "LM")
{
    double ptBins[10] = {1.0, 1.4, 1.8, 2.2, 2.8, 3.6, 4.6, 6.0, 7.0, 8.5};
    TH1D * hSpect[5];
    TH1D * hSpectObs[5];
    for ( int c = 0; c < 5; c++ ) {
        hSpect[c] = new TH1D(Form("hSpect_%i", c), Form("hSpect_%i", c), 9, ptBins);
        hSpectObs[c] = new TH1D(Form("hSpectObs_%i", c), Form("hSpectObs_%i", c), 9, ptBins);
    }

    TChain * ch = new TChain("ch");
    double cut;
    if ( s == "LM" ) {
        ch->Add("../../PbPb2018/V0Performance/TMVA/TMVA3_HydjetMCTruth_MCBkg_LM.root/dataset3_full_LM/TestTree");
        ch->Add("../../PbPb2018/V0Performance/TMVA/TMVA3_HydjetMCTruth_MCBkg_LM.root/dataset3_full_LM/TrainTree");
        cut = 0.20;
    } else {
        ch->Add("../../PbPb2018/V0Performance/TMVA/TMVA3_HydjetMCTruth_MCBkg_KS.root/dataset3_full_KS/TestTree");
        ch->Add("../../PbPb2018/V0Performance/TMVA/TMVA3_HydjetMCTruth_MCBkg_KS.root/dataset3_full_KS/TrainTree");
        cut = 0.15;
    }

    Int_t           classID;
    Float_t         Cent;
    Float_t         mass;
    Float_t         BDT250_D4;
    Float_t         pt;
    Float_t         rapidity;

    ch->SetBranchAddress("classID", &classID );
    ch->SetBranchAddress("Cent", &Cent );
    ch->SetBranchAddress("mass", &mass );
    ch->SetBranchAddress("BDT250_D4", &BDT250_D4 );
    ch->SetBranchAddress("pt", &pt );
    ch->SetBranchAddress("rapidity", &rapidity);

    int idx = 0;
    while ( ch->GetEntry(idx++) ) {
        if ( idx%1000 == 0 ) cout << " --> Processed " << idx << endl;
        if ( fabs(rapidity) > 1.0 ) continue;
        if ( classID != 0 ) continue;
        int c = -1;
        if ( Cent < 10 ) c = 0;
        if ( (Cent>=10) and (Cent<20) ) c = 1;
        if ( (Cent>=20) and (Cent<60) ) c = 2;
        if ( (Cent>=60) and (Cent<100) ) c = 3;
        if ( (Cent>=100) and (Cent<180) ) c = 4;
        if ( c == -1 ) continue;
        hSpect[c]->Fill(pt);
        if ( BDT250_D4 > cut ) hSpectObs[c]->Fill(pt);
    }
    TFile * fsave = new TFile(Form("spectraMC_%s.root", s.c_str()), "recreate");
    for ( int c = 0; c < 5; c++ ) {
        hSpect[c]->Write();
        hSpectObs[c]->Write();
    }
}

