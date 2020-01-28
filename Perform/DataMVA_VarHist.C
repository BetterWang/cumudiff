
// pt                          0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12
    double pTbin[14] = {0.2, 0.4, 0.6, 0.8, 1.0, 1.4, 1.8, 2.2, 2.8, 3.6, 4.6, 6.0, 7.0, 8.5};
// cent                   0,  1,   2,   3,   4
    int centBin[6] = {0, 20, 60, 100, 160, 200};


void DataMVA_VarHist(string prefix = "LM", string input = "../../PbPb2018/HIMinimumBias4/crab_HIMB4_V0Tree_v6/190917_195729/0000/*.root/tree/trV", string fout = "HistData_LM.root") //, bool bPeak = true)
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


//    TH1D * hCent        = new TH1D("hCent", "hCent", 200, 0, 200);
    TH1D * hpt          [5];
    TH1D * hrapidity    [5];
    TH1D * hhpt         = new TH1D("hpt", "hpt", 100, 0, 10);
    TH1D * hhrapidity   = new TH1D("hrapidity", "hrapidity", 100, -2.5, 2.5);

// Cent    - 5
// pT      - 13
// Mid/Fwd - 2
    TH1D * hvtxChi2        [5][13][2]; //= new TH1D("hvtxChi2", "hvtxChi2", 200, 0, 7);
    TH1D * hcosThetaXYZ    [5][13][2]; //= new TH1D("hcosThetaXYZ", "hcosThetaXYZ", 200, 0.999, 1.0);
    TH1D * hLxyz           [5][13][2]; //= new TH1D("hLxyz", "hLxyz", 200, 0., 200.0);
    TH1D * hvtxDecaySigXYZ [5][13][2]; //= new TH1D("hvtxDecaySigXYZ", "hvtxDecaySigXYZ", 200, 0., 5000.0);
    TH1D * hDCA            [5][13][2]; //= new TH1D("hDCA", "hDCA", 200, 0., 1.0);
    TH1D * hpTrkNHit       [5][13][2]; //= new TH1D("hpTrkNHit", "hpTrkNHit", 100, 0., 100.);
    TH1D * hnTrkNHit       [5][13][2]; //= new TH1D("hnTrkNHit", "hnTrkNHit", 100, 0., 100.);
    TH1D * hpTrkPt         [5][13][2]; //= new TH1D("hpTrkPt", "hpTrkPt", 200, 0.0, 20.0);
    TH1D * hnTrkPt         [5][13][2]; //= new TH1D("hnTrkPt", "hnTrkPt", 200, 0.0, 20.0);
    TH1D * hpTrkEta        [5][13][2]; //= new TH1D("hpTrkEta", "hpTrkEta", 200, -2.5, 2.5);
    TH1D * hnTrkEta        [5][13][2]; //= new TH1D("hnTrkEta", "hnTrkEta", 200, -2.5, 2.5);
    TH1D * hpTrkNPxLayer   [5][13][2]; //= new TH1D("hpTrkNPxLayer", "hpTrkNPxLayer", 6, 0, 6);
    TH1D * hnTrkNPxLayer   [5][13][2]; //= new TH1D("hnTrkNPxLayer", "hnTrkNPxLayer", 6, 0, 6);
    TH1D * hpTrkDCASigXY   [5][13][2]; //= new TH1D("hpTrkDCASigXY", "hpTrkDCASigXY", 200, 0., 100.);
    TH1D * hnTrkDCASigXY   [5][13][2]; //= new TH1D("hnTrkDCASigXY", "hnTrkDCASigXY", 200, 0., 100.);
    TH1D * hpTrkDCASigZ    [5][13][2]; //= new TH1D("hpTrkDCASigZ", "hpTrkDCASigZ", 200, 0., 100.);
    TH1D * hnTrkDCASigZ    [5][13][2]; //= new TH1D("hnTrkDCASigZ", "hnTrkDCASigZ", 200, 0., 100.);

    TH1D * hhvtxChi2        = new TH1D("hvtxChi2", "hvtxChi2", 200, 0, 7);
    TH1D * hhcosThetaXYZ    = new TH1D("hcosThetaXYZ", "hcosThetaXYZ", 200, 0.999, 1.0);
    TH1D * hhLxyz           = new TH1D("hLxyz", "hLxyz", 200, 0., 200.0);
    TH1D * hhvtxDecaySigXYZ = new TH1D("hvtxDecaySigXYZ", "hvtxDecaySigXYZ", 200, 0., 5000.0);
    TH1D * hhDCA            = new TH1D("hDCA", "hDCA", 200, 0., 1.0);
    TH1D * hhpTrkNHit       = new TH1D("hpTrkNHit", "hpTrkNHit", 100, 0., 100.);
    TH1D * hhnTrkNHit       = new TH1D("hnTrkNHit", "hnTrkNHit", 100, 0., 100.);
    TH1D * hhpTrkPt         = new TH1D("hpTrkPt", "hpTrkPt", 200, 0.0, 20.0);
    TH1D * hhnTrkPt         = new TH1D("hnTrkPt", "hnTrkPt", 200, 0.0, 20.0);
    TH1D * hhpTrkEta        = new TH1D("hpTrkEta", "hpTrkEta", 200, -2.5, 2.5);
    TH1D * hhnTrkEta        = new TH1D("hnTrkEta", "hnTrkEta", 200, -2.5, 2.5);
    TH1D * hhpTrkNPxLayer   = new TH1D("hpTrkNPxLayer", "hpTrkNPxLayer", 6, 0, 6);
    TH1D * hhnTrkNPxLayer   = new TH1D("hnTrkNPxLayer", "hnTrkNPxLayer", 6, 0, 6);
    TH1D * hhpTrkDCASigXY   = new TH1D("hpTrkDCASigXY", "hpTrkDCASigXY", 3000, 0., 1500.);
    TH1D * hhnTrkDCASigXY   = new TH1D("hnTrkDCASigXY", "hnTrkDCASigXY", 3000, 0., 1500.);
    TH1D * hhpTrkDCASigZ    = new TH1D("hpTrkDCASigZ", "hpTrkDCASigZ", 3000, 0., 1500.);
    TH1D * hhnTrkDCASigZ    = new TH1D("hnTrkDCASigZ", "hnTrkDCASigZ", 3000, 0., 1500.);

    for ( int c = 0; c < 5; c++ ) {
        hpt         [c] = new TH1D(Form("hpt_%i", c),       "hpt",          200, 0., 10.);
        hrapidity   [c] = new TH1D(Form("hrapidity_%i", c), "hrapidity",    200, -2.5, 2.5);
        for ( int ipt = 0; ipt < 13; ipt++ ) {
            for ( int ieta = 0; ieta < 2; ieta++ ) {
                hvtxChi2        [c][ipt][ieta] = new TH1D(Form("hvtxChi2_%i_%i_%i", c, ipt, ieta),           "hvtxChi2",         200, 0, 7);
                hcosThetaXYZ    [c][ipt][ieta] = new TH1D(Form("hcosThetaXYZ_%i_%i_%i", c, ipt, ieta),       "hcosThetaXYZ",     200, 0.999, 1.0);
                hLxyz           [c][ipt][ieta] = new TH1D(Form("hLxyz_%i_%i_%i", c, ipt, ieta),              "hLxyz",            200, 0., 200.0);
                hvtxDecaySigXYZ [c][ipt][ieta] = new TH1D(Form("hvtxDecaySigXYZ_%i_%i_%i", c, ipt, ieta),    "hvtxDecaySigXYZ",  200, 0., 5000.0);
                hDCA            [c][ipt][ieta] = new TH1D(Form("hDCA_%i_%i_%i", c, ipt, ieta),               "hDCA",             200, 0., 1.0);
                hpTrkNHit       [c][ipt][ieta] = new TH1D(Form("hpTrkNHit_%i_%i_%i", c, ipt, ieta),          "hpTrkNHit",        100, 0., 100.);
                hnTrkNHit       [c][ipt][ieta] = new TH1D(Form("hnTrkNHit_%i_%i_%i", c, ipt, ieta),          "hnTrkNHit",        100, 0., 100.);
                hpTrkPt         [c][ipt][ieta] = new TH1D(Form("hpTrkPt_%i_%i_%i", c, ipt, ieta),            "hpTrkPt",          200, 0.0, 20.0);
                hnTrkPt         [c][ipt][ieta] = new TH1D(Form("hnTrkPt_%i_%i_%i", c, ipt, ieta),            "hnTrkPt",          200, 0.0, 20.0);
                hpTrkEta        [c][ipt][ieta] = new TH1D(Form("hpTrkEta_%i_%i_%i", c, ipt, ieta),           "hpTrkEta",         200, -2.5, 2.5);
                hnTrkEta        [c][ipt][ieta] = new TH1D(Form("hnTrkEta_%i_%i_%i", c, ipt, ieta),           "hnTrkEta",         200, -2.5, 2.5);
                hpTrkNPxLayer   [c][ipt][ieta] = new TH1D(Form("hpTrkNPxLayer_%i_%i_%i", c, ipt, ieta),      "hpTrkNPxLayer",    6, 0, 6);
                hnTrkNPxLayer   [c][ipt][ieta] = new TH1D(Form("hnTrkNPxLayer_%i_%i_%i", c, ipt, ieta),      "hnTrkNPxLayer",    6, 0, 6);
                hpTrkDCASigXY   [c][ipt][ieta] = new TH1D(Form("hpTrkDCASigXY_%i_%i_%i", c, ipt, ieta),      "hpTrkDCASigXY",    3000, 0., 1500.);
                hnTrkDCASigXY   [c][ipt][ieta] = new TH1D(Form("hnTrkDCASigXY_%i_%i_%i", c, ipt, ieta),      "hnTrkDCASigXY",    3000, 0., 1500.);
                hpTrkDCASigZ    [c][ipt][ieta] = new TH1D(Form("hpTrkDCASigZ_%i_%i_%i", c, ipt, ieta),       "hpTrkDCASigZ",     3000, 0., 1500.);
                hnTrkDCASigZ    [c][ipt][ieta] = new TH1D(Form("hnTrkDCASigZ_%i_%i_%i", c, ipt, ieta),       "hnTrkDCASigZ",     3000, 0., 1500.);

            }
        }
    }


    int ievt = 0;
    while ( trV->GetEntry(ievt++) ) {
        if ( ievt%10000 == 0 ) cout << "  --- ... ievt = " << ievt << endl;

        int c = 0;
        while ( t_Cent > centBin[c+1] ) c++;

        int sz = t_pt->size();
        for ( int i = 0; i < sz; i++ ) {

            /*
            if ( bPeak ) {
                if ( prefix == "LM" ) {
                    if ( ((*t_mass)[i] > 1.1115) and ((*t_mass)[i] < 1.1200) ) {}
                    else { continue; }
                } else if ( prefix == "KS" ) {
                    if ( ((*t_mass)[i] > 0.492 ) and ((*t_mass)[i] < 0.503 ) ) {}
                    else { continue; }
                }
            } else {
                if ( prefix == "LM" ) {
                    if ( (((*t_mass)[i] > 1.1220) and ((*t_mass)[i] < 1.1600)) or (((*t_mass)[i] > 1.0800) and ((*t_mass)[i] < 1.1095)) ) {}
                    else { continue; }
                } else if ( prefix == "KS" ) {
                    if ( (((*t_mass)[i] > 0.506 ) and ((*t_mass)[i] < 0.565 )) or (((*t_mass)[i] > 0.43  ) and ((*t_mass)[i] < 0.489 )) ) {}
                    else { continue; }
                }
            }
            */

            if ( fabs((*t_rapidity)[i]) > 2.0 ) continue;
            int ipt = 0;
            while ( (*t_pt)[i] > pTbin[ipt+1] ) ipt++;
            int ieta = 0;
            if ( fabs((*t_rapidity)[i]) > 1.0 ) ieta = 1;

            hpt[c]                        ->Fill((*t_pt)[i]);
            hrapidity[c]                  ->Fill((*t_rapidity)[i]);

            hvtxChi2       [c][ipt][ieta] ->Fill((*t_vtxChi2)[i]);
            hcosThetaXYZ   [c][ipt][ieta] ->Fill((*t_cosThetaXYZ)[i]);
            hLxyz          [c][ipt][ieta] ->Fill((*t_Lxyz)[i]);
            hDCA           [c][ipt][ieta] ->Fill((*t_DCA)[i]);
            hpTrkNHit      [c][ipt][ieta] ->Fill((*t_pTrkNHit)[i]);
            hnTrkNHit      [c][ipt][ieta] ->Fill((*t_nTrkNHit)[i]);
            hpTrkPt        [c][ipt][ieta] ->Fill((*t_pTrkPt)[i]);
            hnTrkPt        [c][ipt][ieta] ->Fill((*t_nTrkPt)[i]);
            hpTrkEta       [c][ipt][ieta] ->Fill((*t_pTrkEta)[i]);
            hnTrkEta       [c][ipt][ieta] ->Fill((*t_nTrkEta)[i]);
            hpTrkNPxLayer  [c][ipt][ieta] ->Fill((*t_pTrkNPxLayer)[i]);
            hnTrkNPxLayer  [c][ipt][ieta] ->Fill((*t_nTrkNPxLayer)[i]);
            hpTrkDCASigXY  [c][ipt][ieta] ->Fill((*t_pTrkDCASigXY)[i]);
            hnTrkDCASigXY  [c][ipt][ieta] ->Fill((*t_nTrkDCASigXY)[i]);
            hpTrkDCASigZ   [c][ipt][ieta] ->Fill((*t_pTrkDCASigZ)[i]);
            hnTrkDCASigZ   [c][ipt][ieta] ->Fill((*t_nTrkDCASigZ)[i]);
            hvtxDecaySigXYZ[c][ipt][ieta] ->Fill((*t_vtxDecaySigXYZ)[i]);

            if ( t_Cent < 160. and ieta == 0 ) {
                hhpt             ->Fill((*t_pt)[i]);
                hhrapidity       ->Fill((*t_rapidity)[i]);
                hhvtxChi2        ->Fill((*t_vtxChi2)[i]);
                hhcosThetaXYZ    ->Fill((*t_cosThetaXYZ)[i]);
                hhLxyz           ->Fill((*t_Lxyz)[i]);
                hhDCA            ->Fill((*t_DCA)[i]);
                hhpTrkNHit       ->Fill((*t_pTrkNHit)[i]);
                hhnTrkNHit       ->Fill((*t_nTrkNHit)[i]);
                hhpTrkPt         ->Fill((*t_pTrkPt)[i]);
                hhnTrkPt         ->Fill((*t_nTrkPt)[i]);
                hhpTrkEta        ->Fill((*t_pTrkEta)[i]);
                hhnTrkEta        ->Fill((*t_nTrkEta)[i]);
                hhpTrkNPxLayer   ->Fill((*t_pTrkNPxLayer)[i]);
                hhnTrkNPxLayer   ->Fill((*t_nTrkNPxLayer)[i]);
                hhpTrkDCASigXY   ->Fill((*t_pTrkDCASigXY)[i]);
                hhnTrkDCASigXY   ->Fill((*t_nTrkDCASigXY)[i]);
                hhpTrkDCASigZ    ->Fill((*t_pTrkDCASigZ)[i]);
                hhnTrkDCASigZ    ->Fill((*t_nTrkDCASigZ)[i]);
                hhvtxDecaySigXYZ ->Fill((*t_vtxDecaySigXYZ)[i]);
            }

        }

    }
    TFile * fsave = new TFile(fout.c_str(), "recreate");
    for ( int c = 0; c < 5; c++ ) {
        hpt            [c]->Write();
        hrapidity      [c]->Write();
        for ( int ipt = 0; ipt < 13; ipt++ ) {
            for ( int ieta = 0; ieta < 2; ieta++ ) {
                hvtxChi2       [c][ipt][ieta]->Write();
                hcosThetaXYZ   [c][ipt][ieta]->Write();
                hLxyz          [c][ipt][ieta]->Write();
                hDCA           [c][ipt][ieta]->Write();
                hpTrkNHit      [c][ipt][ieta]->Write();
                hnTrkNHit      [c][ipt][ieta]->Write();
                hpTrkPt        [c][ipt][ieta]->Write();
                hnTrkPt        [c][ipt][ieta]->Write();
                hpTrkEta       [c][ipt][ieta]->Write();
                hnTrkEta       [c][ipt][ieta]->Write();
                hpTrkNPxLayer  [c][ipt][ieta]->Write();
                hnTrkNPxLayer  [c][ipt][ieta]->Write();
                hpTrkDCASigXY  [c][ipt][ieta]->Write();
                hnTrkDCASigXY  [c][ipt][ieta]->Write();
                hpTrkDCASigZ   [c][ipt][ieta]->Write();
                hnTrkDCASigZ   [c][ipt][ieta]->Write();
                hvtxDecaySigXYZ[c][ipt][ieta]->Write();
            }
        }
    }
    hhpt            ->Write();
    hhrapidity      ->Write();
    hhvtxChi2       ->Write();
    hhcosThetaXYZ   ->Write();
    hhLxyz          ->Write();
    hhDCA           ->Write();
    hhpTrkNHit      ->Write();
    hhnTrkNHit      ->Write();
    hhpTrkPt        ->Write();
    hhnTrkPt        ->Write();
    hhpTrkEta       ->Write();
    hhnTrkEta       ->Write();
    hhpTrkNPxLayer  ->Write();
    hhnTrkNPxLayer  ->Write();
    hhpTrkDCASigXY  ->Write();
    hhnTrkDCASigXY  ->Write();
    hhpTrkDCASigZ   ->Write();
    hhnTrkDCASigZ   ->Write();
    hhvtxDecaySigXYZ->Write();
}
