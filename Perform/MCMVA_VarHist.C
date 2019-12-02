






void MCMVA_VarHist(string fin = "../../PbPb2018/V0Performance/MC/HydjetMCTruth_LM.root", string fout = "HistHydjetMCTruth_LM.root", int centMin = 0, int centMax = 999)
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
    while ( tree->GetEntry(ievt++) ) {
        if ( ievt%10000 == 0 ) cout << "  --- ... ievt = " << ievt << endl;
        if ( (Cent < centMin) and (Cent >= centMax) ) continue;

        hpt         ->Fill(pt);
        hrapidity   ->Fill(rapidity);
        hvtxChi2    ->Fill(vtxChi2);
        hcosThetaXYZ->Fill(cosThetaXYZ);
        hLxyz       ->Fill(Lxyz);
        hDCA        ->Fill(DCA);
        hpTrkNHit   ->Fill(pTrkNHit);
        hnTrkNHit   ->Fill(nTrkNHit);
        hpTrkPt     ->Fill(pTrkPt);
        hnTrkPt     ->Fill(nTrkPt);
        hpTrkEta    ->Fill(pTrkEta);
        hnTrkEta    ->Fill(nTrkEta);
        hpTrkNPxLayer->Fill(pTrkNPxLayer);
        hnTrkNPxLayer->Fill(nTrkNPxLayer);
        hpTrkDCASigXY->Fill(pTrkDCASigXY);
        hnTrkDCASigXY->Fill(nTrkDCASigXY);
        hpTrkDCASigZ ->Fill(pTrkDCASigZ);
        hnTrkDCASigZ ->Fill(nTrkDCASigZ);
        hvtxDecaySigXYZ->Fill(vtxDecaySigXYZ);
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
