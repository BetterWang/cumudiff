

void DataMVA_VarHist(string prefix = "LM", string input = "../../PbPb2018/HIMinimumBias4/crab_HIMB4_V0Tree_v6/190917_195729/0000/*.root/tree/trV", string fout = "HistData_LM.root", int centMin = 0, int centMax = 999)
{
    TChain * trV = new TChain();
    trV->Add(input.c_str());

    trV->SetMakeClass(1);
    trV->SetBranchStatus("*", 0);
    trV->SetBranchStatus("Cent", 1);
    trV->SetBranchStatus( (prefix+"pt").c_str(), 1 );
    trV->SetBranchStatus( (prefix+"phi").c_str(), 1 );
    trV->SetBranchStatus( (prefix+"eta").c_str(), 1 );
    trV->SetBranchStatus( (prefix+"rapidity").c_str(), 1 );
    trV->SetBranchStatus( (prefix+"mass").c_str(), 1 );
    trV->SetBranchStatus( (prefix+"vtxChi2").c_str(), 1 );
    trV->SetBranchStatus( (prefix+"cosThetaXYZ").c_str(), 1 );
    trV->SetBranchStatus( (prefix+"Lxyz").c_str(), 1 );
    trV->SetBranchStatus( (prefix+"vtxDecaySigXYZ").c_str(), 1 );
    trV->SetBranchStatus( (prefix+"DCA").c_str(), 1 );
    trV->SetBranchStatus( (prefix+"pdgId").c_str(), 1 );
    trV->SetBranchStatus( (prefix+"pTrkQuality").c_str(), 1 );
    trV->SetBranchStatus( (prefix+"pTrkNHit").c_str(), 1 );
    trV->SetBranchStatus( (prefix+"pTrkPt").c_str(), 1 );
    trV->SetBranchStatus( (prefix+"pTrkPtError").c_str(), 1 );
    trV->SetBranchStatus( (prefix+"pTrkEta").c_str(), 1 );
    trV->SetBranchStatus( (prefix+"pTrkNPxLayer").c_str(), 1 );
    trV->SetBranchStatus( (prefix+"pTrkDCASigXY").c_str(), 1 );
    trV->SetBranchStatus( (prefix+"pTrkDCASigZ").c_str(), 1 );
    trV->SetBranchStatus( (prefix+"nTrkQuality").c_str(), 1 );
    trV->SetBranchStatus( (prefix+"nTrkNHit").c_str(), 1 );
    trV->SetBranchStatus( (prefix+"nTrkPt").c_str(), 1 );
    trV->SetBranchStatus( (prefix+"nTrkPtError").c_str(), 1 );
    trV->SetBranchStatus( (prefix+"nTrkEta").c_str(), 1 );
    trV->SetBranchStatus( (prefix+"nTrkNPxLayer").c_str(), 1 );
    trV->SetBranchStatus( (prefix+"nTrkDCASigXY").c_str(), 1 );
    trV->SetBranchStatus( (prefix+"nTrkDCASigZ").c_str(), 1 );

    vector<double>  *t_pt = 0;
    vector<double>  *t_phi = 0;
    vector<double>  *t_eta = 0;
    vector<double>  *t_rapidity = 0;
    vector<double>  *t_mass = 0;
    vector<double>  *t_vtxChi2 = 0;
    vector<double>  *t_cosThetaXYZ = 0;
    vector<double>  *t_Lxyz = 0;
    vector<double>  *t_vtxDecaySigXYZ = 0;
    vector<double>  *t_DCA = 0;
    vector<double>  *t_pdgId = 0;
    vector<double>  *t_pTrkQuality = 0;
    vector<double>  *t_pTrkNHit = 0;
    vector<double>  *t_pTrkPt = 0;
    vector<double>  *t_pTrkPtError = 0;
    vector<double>  *t_pTrkEta = 0;
    vector<double>  *t_pTrkNPxLayer = 0;
    vector<double>  *t_pTrkDCASigXY = 0;
    vector<double>  *t_pTrkDCASigZ = 0;
    vector<double>  *t_nTrkQuality = 0;
    vector<double>  *t_nTrkNHit = 0;
    vector<double>  *t_nTrkPt = 0;
    vector<double>  *t_nTrkPtError = 0;
    vector<double>  *t_nTrkEta = 0;
    vector<double>  *t_nTrkNPxLayer = 0;
    vector<double>  *t_nTrkDCASigXY = 0;
    vector<double>  *t_nTrkDCASigZ = 0;
    Double_t        t_Cent = -1;

    trV->SetBranchAddress( (prefix+"pt").c_str(),             &t_pt);
    trV->SetBranchAddress( (prefix+"phi").c_str(),            &t_phi);
    trV->SetBranchAddress( (prefix+"eta").c_str(),            &t_eta);
    trV->SetBranchAddress( (prefix+"rapidity").c_str(),       &t_rapidity);
    trV->SetBranchAddress( (prefix+"mass").c_str(),           &t_mass);
    trV->SetBranchAddress( (prefix+"vtxChi2").c_str(),        &t_vtxChi2);
    trV->SetBranchAddress( (prefix+"cosThetaXYZ").c_str(),    &t_cosThetaXYZ);
    trV->SetBranchAddress( (prefix+"Lxyz").c_str(),           &t_Lxyz);
    trV->SetBranchAddress( (prefix+"vtxDecaySigXYZ").c_str(), &t_vtxDecaySigXYZ);
    trV->SetBranchAddress( (prefix+"DCA").c_str(),            &t_DCA);
    trV->SetBranchAddress( (prefix+"pdgId").c_str(),          &t_pdgId);
    trV->SetBranchAddress( (prefix+"pTrkQuality").c_str(),    &t_pTrkQuality);
    trV->SetBranchAddress( (prefix+"pTrkNHit").c_str(),       &t_pTrkNHit);
    trV->SetBranchAddress( (prefix+"pTrkPt").c_str(),         &t_pTrkPt);
    trV->SetBranchAddress( (prefix+"pTrkPtError").c_str(),    &t_pTrkPtError);
    trV->SetBranchAddress( (prefix+"pTrkEta").c_str(),        &t_pTrkEta);
    trV->SetBranchAddress( (prefix+"pTrkNPxLayer").c_str(),   &t_pTrkNPxLayer);
    trV->SetBranchAddress( (prefix+"pTrkDCASigXY").c_str(),   &t_pTrkDCASigXY);
    trV->SetBranchAddress( (prefix+"pTrkDCASigZ").c_str(),    &t_pTrkDCASigZ);
    trV->SetBranchAddress( (prefix+"nTrkQuality").c_str(),    &t_nTrkQuality);
    trV->SetBranchAddress( (prefix+"nTrkNHit").c_str(),       &t_nTrkNHit);
    trV->SetBranchAddress( (prefix+"nTrkPt").c_str(),         &t_nTrkPt);
    trV->SetBranchAddress( (prefix+"nTrkPtError").c_str(),    &t_nTrkPtError);
    trV->SetBranchAddress( (prefix+"nTrkEta").c_str(),        &t_nTrkEta);
    trV->SetBranchAddress( (prefix+"nTrkNPxLayer").c_str(),   &t_nTrkNPxLayer);
    trV->SetBranchAddress( (prefix+"nTrkDCASigXY").c_str(),   &t_nTrkDCASigXY);
    trV->SetBranchAddress( (prefix+"nTrkDCASigZ").c_str(),    &t_nTrkDCASigZ);
    trV->SetBranchAddress( "Cent",                            &t_Cent);


    TH1D * hpt          = new TH1D("hpt", "hpt", 200, 0., 10.);
    TH1D * hrapidity    = new TH1D("hrapidity", "hrapidity", 200, -2.5, 2.5);
    TH1D * hvtxChi2     = new TH1D("hvtxChi2", "hvtxChi2", 200, 0, 7);
    TH1D * hcosThetaXYZ = new TH1D("hcosThetaXYZ", "hcosThetaXYZ", 200, 0.999, 1.0);
    TH1D * hLxyz        = new TH1D("hLxyz", "hLxyz", 200, 0., 200.0);
    TH1D * hvtxDecaySigXYZ = new TH1D("hvtxDecaySigXYZ", "hvtxDecaySigXYZ", 200, 0., 5000.0);
    TH1D * hDCA         = new TH1D("hDCA", "hDCA", 200, 0., 1.0);
    TH1D * hpTrkNHit    = new TH1D("hpTrkNHit", "hpTrkNHit", 100, 0., 100.);
    TH1D * hnTrkNHit    = new TH1D("hnTrkNHit", "hnTrkNHit", 100, 0., 100.);
    TH1D * hpTrkPt      = new TH1D("hpTrkPt", "hpTrkPt", 200, 0.0, 20.0);
    TH1D * hnTrkPt      = new TH1D("hnTrkPt", "hnTrkPt", 200, 0.0, 20.0);
    TH1D * hpTrkEta     = new TH1D("hpTrkEta", "hpTrkEta", 200, -2.5, 2.5);
    TH1D * hnTrkEta     = new TH1D("hnTrkEta", "hnTrkEta", 200, -2.5, 2.5);
    TH1D * hpTrkNPxLayer= new TH1D("hpTrkNPxLayer", "hpTrkNPxLayer", 6, 0, 6);
    TH1D * hnTrkNPxLayer= new TH1D("hnTrkNPxLayer", "hnTrkNPxLayer", 6, 0, 6);
    TH1D * hpTrkDCASigXY= new TH1D("hpTrkDCASigXY", "hpTrkDCASigXY", 200, 0., 100.);
    TH1D * hnTrkDCASigXY= new TH1D("hnTrkDCASigXY", "hnTrkDCASigXY", 200, 0., 100.);
    TH1D * hpTrkDCASigZ = new TH1D("hpTrkDCASigZ", "hpTrkDCASigZ", 200, 0., 100.);
    TH1D * hnTrkDCASigZ = new TH1D("hnTrkDCASigZ", "hnTrkDCASigZ", 200, 0., 100.);

    int ievt = 0;
    while ( trV->GetEntry(ievt++) ) {
        if ( ievt%10000 == 0 ) cout << "  --- ... ievt = " << ievt << endl;
        if ( (t_Cent< centMin) and (t_Cent >= centMax) ) continue;
        int sz = t_pt->size();
        for ( int i = 0; i < sz; i++ ) {
            hpt         ->Fill((*t_pt)[i]);
            hrapidity   ->Fill((*t_rapidity)[i]);
            hvtxChi2    ->Fill((*t_vtxChi2)[i]);
            hcosThetaXYZ->Fill((*t_cosThetaXYZ)[i]);
            hLxyz       ->Fill((*t_Lxyz)[i]);
            hDCA        ->Fill((*t_DCA)[i]);
            hpTrkNHit   ->Fill((*t_pTrkNHit)[i]);
            hnTrkNHit   ->Fill((*t_nTrkNHit)[i]);
            hpTrkPt     ->Fill((*t_pTrkPt)[i]);
            hnTrkPt     ->Fill((*t_nTrkPt)[i]);
            hpTrkEta    ->Fill((*t_pTrkEta)[i]);
            hnTrkEta    ->Fill((*t_nTrkEta)[i]);
            hpTrkNPxLayer->Fill((*t_pTrkNPxLayer)[i]);
            hnTrkNPxLayer->Fill((*t_nTrkNPxLayer)[i]);
            hpTrkDCASigXY->Fill((*t_pTrkDCASigXY)[i]);
            hnTrkDCASigXY->Fill((*t_nTrkDCASigXY)[i]);
            hpTrkDCASigZ ->Fill((*t_pTrkDCASigZ)[i]);
            hnTrkDCASigZ ->Fill((*t_nTrkDCASigZ)[i]);
            hvtxDecaySigXYZ->Fill((*t_vtxDecaySigXYZ)[i]);

        }

    }
    TFile * fsave = new TFile(fout.c_str(), "recreate");
    hpt            ->Write();
    hrapidity      ->Write();
    hvtxChi2       ->Write();
    hcosThetaXYZ   ->Write();
    hLxyz          ->Write();
    hDCA           ->Write();
    hpTrkNHit      ->Write();
    hnTrkNHit      ->Write();
    hpTrkPt        ->Write();
    hnTrkPt        ->Write();
    hpTrkEta       ->Write();
    hnTrkEta       ->Write();
    hpTrkNPxLayer  ->Write();
    hnTrkNPxLayer  ->Write();
    hpTrkDCASigXY  ->Write();
    hnTrkDCASigXY  ->Write();
    hpTrkDCASigZ   ->Write();
    hnTrkDCASigZ   ->Write();
    hvtxDecaySigXYZ->Write();
}
