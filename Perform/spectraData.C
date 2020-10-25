
void spectraData(string s = "LM")
{
    double ptBins[10] = {1.0, 1.4, 1.8, 2.2, 2.8, 3.6, 4.6, 6.0, 7.0, 8.5};
    TH1D * hSpectMCfull4[5];
    TH1D * hSpectMCfull4C[5];
    TH1D * hSpectDataWS[5];

    for ( int c = 0; c < 5; c++ ) {
        hSpectMCfull4[c]  = new TH1D(Form("hSpectMCfull4_%i", c), Form("hSpectMCfull4_%i", c), 9, ptBins);
        hSpectMCfull4C[c] = new TH1D(Form("hSpectMCfull4C_%i", c), Form("hSpectMCfull4C_%i", c), 9, ptBins);
        hSpectDataWS[c]  = new TH1D(Form("hSpectDataWS_%i", c), Form("hSpectDataWS_%i", c), 9, ptBins);
    }

    TChain * mtr = new TChain("mtr");
    mtr->Add( (string("../../PbPb2018/V0Performance/newTree9/BDT_")+s+"3_*.root/mtr").c_str() );

    double cut = 0;
    if ( s == "LM" ) {
        cut = 0.20;
    } else {
        cut = 0.15;
    }

    Float_t         mass;
    Float_t         rapidity;
    Float_t         pt;
    Float_t         Cent;
    Float_t         BDT_MCfull4;
    Float_t         BDT_DataWS;
    Float_t         BDT_MCfull4C;

    mtr->SetBranchAddress("mass", &mass );
    mtr->SetBranchAddress("rapidity", &rapidity );
    mtr->SetBranchAddress("pt", &pt );
    mtr->SetBranchAddress("Cent", &Cent );
    mtr->SetBranchAddress("BDT_MCfull4", &BDT_MCfull4);
    mtr->SetBranchAddress("BDT_DataWS", &BDT_DataWS);
    mtr->SetBranchAddress("BDT_MCfull4C", &BDT_MCfull4C);

    int idx = 0;
    while ( mtr->GetEntry(idx++) ) {
        if ( idx%1000 == 0 ) cout << " --> Processed " << idx << endl;
        if ( fabs(rapidity) > 1.0 ) continue;
        int c = -1;
        if ( Cent < 10 ) c = 0;
        if ( (Cent>=10) and (Cent<20) ) c = 1;
        if ( (Cent>=20) and (Cent<60) ) c = 2;
        if ( (Cent>=60) and (Cent<100) ) c = 3;
        if ( (Cent>=100) and (Cent<180) ) c = 4;
        if ( c == -1 ) continue;
        if ( BDT_MCfull4 > cut ) hSpectMCfull4[c]->Fill(pt);
        if ( BDT_DataWS  > cut ) hSpectDataWS[c]->Fill(pt);
        if ( BDT_MCfull4C> cut ) hSpectMCfull4C[c]->Fill(pt);
    }

    TFile * fsave = new TFile(Form("spectraData_%s.root", s.c_str()), "recreate");
    for ( int c = 0; c < 5; c++ ) {
        hSpectMCfull4[c]->Write();
        hSpectMCfull4C[c]->Write();
        hSpectDataWS[c]->Write();
    }
}
