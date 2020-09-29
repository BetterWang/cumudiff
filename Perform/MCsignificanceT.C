
void MCsignificanceT(string fin = "../../PbPb2018/V0Performance/TMVA/TMVA3_HydjetMCTruth_MCBkg_LM.root",
        string stree = "dataset3_full_LM", string sBDT = "BDT250_D4",
        string fout = "Hydjet_MC_BDT250_D4_LM.root",
        double ptMin = 1.8, double ptMax = 8.5, int centMin = 0, int centMax = 160)
{
    //TFile * f = new TFile(fin.c_str());
    TChain * testTree = new TChain("testTree") ;
    testTree->Add( (fin+"/"+stree+"/TestTree").c_str() );
    testTree->Add( (fin+"/"+stree+"/TrainTree").c_str() );

    TH1D * hmass_Signal[200] = {};
    TH1D * hmass_Bckgnd[200] = {};

    if ( stree.find("LM") != string::npos ) {
        for ( int i = 0; i < 200; i++ ) {
            hmass_Signal[i] = new TH1D(Form("hmass_Signal_%i", i), "", 160, 1.08, 1.16);
            hmass_Bckgnd[i] = new TH1D(Form("hmass_Bckgnd_%i", i), "", 160, 1.08, 1.16);
        }
    } else {
        for ( int i = 0; i < 200; i++ ) {
            hmass_Signal[i] = new TH1D(Form("hmass_Signal_%i", i), "", 270, 0.430, 0.565);
            hmass_Bckgnd[i] = new TH1D(Form("hmass_Bckgnd_%i", i), "", 270, 0.430, 0.565);
        }
    }

    Int_t           classID;
    Float_t         Cent;
    Float_t         mass;
    Float_t         BDT;
    Float_t         pt;
    Float_t         rapidity;

    testTree->SetBranchAddress("classID", &classID );
    testTree->SetBranchAddress("Cent", &Cent );
    testTree->SetBranchAddress("mass", &mass );
    testTree->SetBranchAddress(sBDT.c_str(), &BDT );
    testTree->SetBranchAddress("pt", &pt );
    testTree->SetBranchAddress("rapidity", &rapidity);

    int idx = 0;
    while ( testTree->GetEntry(idx++) ) {
        if ( (idx%1000) == 0 ) cout << "  -- processed " << idx << endl;
        if ( Cent < centMin or Cent >= centMax ) continue;
        if ( fabs(rapidity) > 1.0 ) continue;
        if ( pt < ptMin or pt > ptMax ) continue;

        for ( int i = 0; i < 200; i++ ) {
            double cut = 0.01*i-1.;
            if ( BDT > cut ) {
                if ( classID == 0 ) {
                    hmass_Signal[i]->Fill( mass );
                } else {
                    hmass_Bckgnd[i]->Fill( mass );
                }
            }
        }
    }

    TFile * fsave = new TFile( fout.c_str(), "recreate" );
    for ( int i = 0; i < 200; i++ ) {
        hmass_Signal[i]->Write();
        hmass_Bckgnd[i]->Write();
    }
}
