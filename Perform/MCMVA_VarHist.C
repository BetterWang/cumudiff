


// pt                          0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12
    double pTbin[14] = {0.2, 0.4, 0.6, 0.8, 1.0, 1.4, 1.8, 2.2, 2.8, 3.6, 4.6, 6.0, 7.0, 8.5};
// cent                   0,  1,   2,   3,   4
    int centBin[6] = {0, 20, 60, 100, 160, 200};


void MCMVA_VarHist(string fin = "../../PbPb2018/V0Performance/MC/HydjetMCTruth_LM.root", string fout = "HistHydjetMCTruth_LM.root")
{
//    string fin = "../../PbPb2018/V0Performance/MC/HydjetMCTruth_LM.root";

    TFile * f = new TFile(fin.c_str());

    TTree * tree = (TTree*) f->Get("tree");
    // Declaration of leaf types
    Double_t        pt;
    Double_t        phi;
    Double_t        eta;
    Double_t        rapidity;
    Double_t        mass;
    Double_t        vtxChi2;
    Double_t        cosThetaXYZ;
    Double_t        Lxyz;
    Double_t        vtxDecaySigXYZ;
    Double_t        DCA;
    Int_t           pdgId;
    Int_t           pTrkQuality;
    Int_t           pTrkNHit;
    Double_t        pTrkPt;
    Double_t        pTrkPtError;
    Double_t        pTrkEta;
    Int_t           pTrkNPxLayer;
    Double_t        pTrkDCASigXY;
    Double_t        pTrkDCASigZ;
    Int_t           nTrkQuality;
    Int_t           nTrkNHit;
    Double_t        nTrkPt;
    Double_t        nTrkPtError;
    Double_t        nTrkEta;
    Int_t           nTrkNPxLayer;
    Double_t        nTrkDCASigXY;
    Double_t        nTrkDCASigZ;
    Double_t        Cent;

    tree->SetBranchAddress("pt", &pt);
    tree->SetBranchAddress("phi", &phi);
    tree->SetBranchAddress("eta", &eta);
    tree->SetBranchAddress("rapidity", &rapidity);
    tree->SetBranchAddress("mass", &mass);
    tree->SetBranchAddress("vtxChi2", &vtxChi2);
    tree->SetBranchAddress("cosThetaXYZ", &cosThetaXYZ);
    tree->SetBranchAddress("Lxyz", &Lxyz);
    tree->SetBranchAddress("vtxDecaySigXYZ", &vtxDecaySigXYZ);
    tree->SetBranchAddress("DCA", &DCA);
    tree->SetBranchAddress("pdgId", &pdgId);
    tree->SetBranchAddress("pTrkQuality", &pTrkQuality);
    tree->SetBranchAddress("pTrkNHit", &pTrkNHit);
    tree->SetBranchAddress("pTrkPt", &pTrkPt);
    tree->SetBranchAddress("pTrkPtError", &pTrkPtError);
    tree->SetBranchAddress("pTrkEta", &pTrkEta);
    tree->SetBranchAddress("pTrkNPxLayer", &pTrkNPxLayer);
    tree->SetBranchAddress("pTrkDCASigXY", &pTrkDCASigXY);
    tree->SetBranchAddress("pTrkDCASigZ", &pTrkDCASigZ);
    tree->SetBranchAddress("nTrkQuality", &nTrkQuality);
    tree->SetBranchAddress("nTrkNHit", &nTrkNHit);
    tree->SetBranchAddress("nTrkPt", &nTrkPt);
    tree->SetBranchAddress("nTrkPtError", &nTrkPtError);
    tree->SetBranchAddress("nTrkEta", &nTrkEta);
    tree->SetBranchAddress("nTrkNPxLayer", &nTrkNPxLayer);
    tree->SetBranchAddress("nTrkDCASigXY", &nTrkDCASigXY);
    tree->SetBranchAddress("nTrkDCASigZ", &nTrkDCASigZ);
    tree->SetBranchAddress("Cent", &Cent);


//    TH1D * hCent        = new TH1D("hCent", "hCent", 200, 0, 200);
    TH1D * hpt          [5];
    TH1D * hrapidity    [5];
    TH1D * hhpt         = new TH1D("hpt", "hpt", 200, 0., 10.);
    TH1D * hhrapidity   = new TH1D("hrapidity", "hrapidity", 200, -2.5, 2.5);

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
    while ( tree->GetEntry(ievt++) ) {
        if ( ievt%10000 == 0 ) cout << "  --- ... ievt = " << ievt << endl;

        if ( fabs(rapidity) > 2.0 ) continue;
        int ipt = 0;
        while ( pt > pTbin[ipt+1] ) ipt++;
        int c = 0;
        while ( Cent > centBin[c+1] ) c++;
        int ieta = 0;
        if ( fabs(rapidity) > 1.0 ) ieta = 1;

        hrapidity   [c]->Fill(rapidity);
        hpt         [c]->Fill(pt);

        hvtxChi2       [c][ipt][ieta] ->Fill(vtxChi2);
        hcosThetaXYZ   [c][ipt][ieta] ->Fill(cosThetaXYZ);
        hLxyz          [c][ipt][ieta] ->Fill(Lxyz);
        hDCA           [c][ipt][ieta] ->Fill(DCA);
        hpTrkNHit      [c][ipt][ieta] ->Fill(pTrkNHit);
        hnTrkNHit      [c][ipt][ieta] ->Fill(nTrkNHit);
        hpTrkPt        [c][ipt][ieta] ->Fill(pTrkPt);
        hnTrkPt        [c][ipt][ieta] ->Fill(nTrkPt);
        hpTrkEta       [c][ipt][ieta] ->Fill(pTrkEta);
        hnTrkEta       [c][ipt][ieta] ->Fill(nTrkEta);
        hpTrkNPxLayer  [c][ipt][ieta] ->Fill(pTrkNPxLayer);
        hnTrkNPxLayer  [c][ipt][ieta] ->Fill(nTrkNPxLayer);
        hpTrkDCASigXY  [c][ipt][ieta] ->Fill(pTrkDCASigXY);
        hnTrkDCASigXY  [c][ipt][ieta] ->Fill(nTrkDCASigXY);
        hpTrkDCASigZ   [c][ipt][ieta] ->Fill(pTrkDCASigZ);
        hnTrkDCASigZ   [c][ipt][ieta] ->Fill(nTrkDCASigZ);
        hvtxDecaySigXYZ[c][ipt][ieta] ->Fill(vtxDecaySigXYZ);

        if ( Cent < 160. and ieta == 0 ) {
            hhrapidity       ->Fill(rapidity);
            hhpt             ->Fill(pt);
            hhvtxChi2        ->Fill(vtxChi2);
            hhcosThetaXYZ    ->Fill(cosThetaXYZ);
            hhLxyz           ->Fill(Lxyz);
            hhDCA            ->Fill(DCA);
            hhpTrkNHit       ->Fill(pTrkNHit);
            hhnTrkNHit       ->Fill(nTrkNHit);
            hhpTrkPt         ->Fill(pTrkPt);
            hhnTrkPt         ->Fill(nTrkPt);
            hhpTrkEta        ->Fill(pTrkEta);
            hhnTrkEta        ->Fill(nTrkEta);
            hhpTrkNPxLayer   ->Fill(pTrkNPxLayer);
            hhnTrkNPxLayer   ->Fill(nTrkNPxLayer);
            hhpTrkDCASigXY   ->Fill(pTrkDCASigXY);
            hhnTrkDCASigXY   ->Fill(nTrkDCASigXY);
            hhpTrkDCASigZ    ->Fill(pTrkDCASigZ);
            hhnTrkDCASigZ    ->Fill(nTrkDCASigZ);
            hhvtxDecaySigXYZ ->Fill(vtxDecaySigXYZ);
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
    hhpt             ->Write();
    hhrapidity       ->Write();
    hhvtxChi2        ->Write();
    hhcosThetaXYZ    ->Write();
    hhLxyz           ->Write();
    hhDCA            ->Write();
    hhpTrkNHit       ->Write();
    hhnTrkNHit       ->Write();
    hhpTrkPt         ->Write();
    hhnTrkPt         ->Write();
    hhpTrkEta        ->Write();
    hhnTrkEta        ->Write();
    hhpTrkNPxLayer   ->Write();
    hhnTrkNPxLayer   ->Write();
    hhpTrkDCASigXY   ->Write();
    hhnTrkDCASigXY   ->Write();
    hhpTrkDCASigZ    ->Write();
    hhnTrkDCASigZ    ->Write();
    hhvtxDecaySigXYZ ->Write();
}
