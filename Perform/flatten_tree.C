#include "TTree.h"
#include "TChain.h"
#include "TFile.h"


void flatten_tree(string s = "test", string prefix = "LM", string sout = "test.root")
{
    TChain * trV = new TChain("trV");
    int limit = 1000000;
	if ( s == "test" ) {
        trV->Add("../../run2018/cumu_MC_TruthV0Tree.root/tree/trV");
    } else if ( s == "MBWrongSignTest" ) {
        trV->Add("../../run2018/cumu_MB_WrongSignV0Tree.root/tree/trV");
    } else if ( s == "HydjetMCTruth" ) {
        trV->Add("../../PbPb2018/MinBias_Hydjet_Drum5F_2018_5p02TeV/crab_Hydjet_RECODEBUG_TruthV0Tree_v1/190909_202145/0000/cumu_*.root/tree/trV");
    } else if ( s == "HydjetMCBkg" ) {
        trV->Add("../../PbPb2018/MinBias_Hydjet_Drum5F_2018_5p02TeV/crab_Hydjet_RECODEBUG_BkgV0Tree_v1/190911_160359/0000/cumu_*.root/tree/trV");
    } else if ( s == "MBWrongSign" ) {
        trV->Add("../../PbPb2018/HIMinimumBias19/crab_HIMB19_WrongSignV0Tree_v4/200916_134822/0000/cumu_*.root/tree/trV");
        limit = 10000000;
    } else if ( s == "MB4" ) {
        trV->Add("../../PbPb2018/HIMinimumBias4/crab_HIMB4_V0Tree_v9/200909_044330/0000/cumu_90*.root/tree/trV");
//        limit = 1000000;
    } else if ( s == "MB19" ) {
        trV->Add("../../PbPb2018/HIMinimumBias19/crab_HIMB19_V0Tree_v9/200918_050416/0000/cumu_*.root/tree/trV");
        limit = 10000000;
    }

	trV->SetMakeClass(1);
    trV->SetBranchStatus("*", 0);
    trV->SetBranchStatus("Cent", 1);
    trV->SetBranchStatus("vz", 1);
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

    vector<double>  *pt = 0;
    vector<double>  *phi = 0;
    vector<double>  *eta = 0;
    vector<double>  *rapidity = 0;
    vector<double>  *mass = 0;
    vector<double>  *vtxChi2 = 0;
    vector<double>  *cosThetaXYZ = 0;
    vector<double>  *Lxyz = 0;
    vector<double>  *vtxDecaySigXYZ = 0;
    vector<double>  *DCA = 0;
    vector<double>  *pdgId = 0;
    vector<double>  *pTrkQuality = 0;
    vector<double>  *pTrkNHit = 0;
    vector<double>  *pTrkPt = 0;
    vector<double>  *pTrkPtError = 0;
    vector<double>  *pTrkEta = 0;
    vector<double>  *pTrkNPxLayer = 0;
    vector<double>  *pTrkDCASigXY = 0;
    vector<double>  *pTrkDCASigZ = 0;
    vector<double>  *nTrkQuality = 0;
    vector<double>  *nTrkNHit = 0;
    vector<double>  *nTrkPt = 0;
    vector<double>  *nTrkPtError = 0;
    vector<double>  *nTrkEta = 0;
    vector<double>  *nTrkNPxLayer = 0;
    vector<double>  *nTrkDCASigXY = 0;
    vector<double>  *nTrkDCASigZ = 0;
    Double_t        Cent = -1;
    Double_t        vz = -9999;

    trV->SetBranchAddress( (prefix+"pt").c_str(),             &pt);
    trV->SetBranchAddress( (prefix+"phi").c_str(),            &phi);
    trV->SetBranchAddress( (prefix+"eta").c_str(),            &eta);
    trV->SetBranchAddress( (prefix+"rapidity").c_str(),       &rapidity);
    trV->SetBranchAddress( (prefix+"mass").c_str(),           &mass);
    trV->SetBranchAddress( (prefix+"vtxChi2").c_str(),        &vtxChi2);
    trV->SetBranchAddress( (prefix+"cosThetaXYZ").c_str(),    &cosThetaXYZ);
    trV->SetBranchAddress( (prefix+"Lxyz").c_str(),           &Lxyz);
    trV->SetBranchAddress( (prefix+"vtxDecaySigXYZ").c_str(), &vtxDecaySigXYZ);
    trV->SetBranchAddress( (prefix+"DCA").c_str(),            &DCA);
    trV->SetBranchAddress( (prefix+"pdgId").c_str(),          &pdgId);
    trV->SetBranchAddress( (prefix+"pTrkQuality").c_str(),    &pTrkQuality);
    trV->SetBranchAddress( (prefix+"pTrkNHit").c_str(),       &pTrkNHit);
    trV->SetBranchAddress( (prefix+"pTrkPt").c_str(),         &pTrkPt);
    trV->SetBranchAddress( (prefix+"pTrkPtError").c_str(),    &pTrkPtError);
    trV->SetBranchAddress( (prefix+"pTrkEta").c_str(),        &pTrkEta);
    trV->SetBranchAddress( (prefix+"pTrkNPxLayer").c_str(),   &pTrkNPxLayer);
    trV->SetBranchAddress( (prefix+"pTrkDCASigXY").c_str(),   &pTrkDCASigXY);
    trV->SetBranchAddress( (prefix+"pTrkDCASigZ").c_str(),    &pTrkDCASigZ);
    trV->SetBranchAddress( (prefix+"nTrkQuality").c_str(),    &nTrkQuality);
    trV->SetBranchAddress( (prefix+"nTrkNHit").c_str(),       &nTrkNHit);
    trV->SetBranchAddress( (prefix+"nTrkPt").c_str(),         &nTrkPt);
    trV->SetBranchAddress( (prefix+"nTrkPtError").c_str(),    &nTrkPtError);
    trV->SetBranchAddress( (prefix+"nTrkEta").c_str(),        &nTrkEta);
    trV->SetBranchAddress( (prefix+"nTrkNPxLayer").c_str(),   &nTrkNPxLayer);
    trV->SetBranchAddress( (prefix+"nTrkDCASigXY").c_str(),   &nTrkDCASigXY);
    trV->SetBranchAddress( (prefix+"nTrkDCASigZ").c_str(),    &nTrkDCASigZ);
    trV->SetBranchAddress( "Cent",                            &Cent);
    trV->SetBranchAddress( "vz",                              &vz);


    TFile * fout = new TFile( sout.c_str(), "recreate" );

    TTree * tree = new TTree("tree", "tree");

    double  n_pt = 0;
    double  n_phi = 0;
    double  n_eta = 0;
    double  n_rapidity = 0;
    double  n_mass = 0;
    double  n_vtxChi2 = 0;
    double  n_cosThetaXYZ = 0;
    double  n_Lxyz = 0;
    double  n_vtxDecaySigXYZ = 0;
    double  n_DCA = 0;
    int     n_pdgId = 0;
    int     n_pTrkQuality = 0;
    int     n_pTrkNHit = 0;
    double  n_pTrkPt = 0;
    double  n_pTrkPtError = 0;
    double  n_pTrkEta = 0;
    int     n_pTrkNPxLayer = 0;
    double  n_pTrkDCASigXY = 0;
    double  n_pTrkDCASigZ = 0;
    int     n_nTrkQuality = 0;
    int     n_nTrkNHit = 0;
    double  n_nTrkPt = 0;
    double  n_nTrkPtError = 0;
    double  n_nTrkEta = 0;
    int     n_nTrkNPxLayer = 0;
    double  n_nTrkDCASigXY = 0;
    double  n_nTrkDCASigZ = 0;

    tree->Branch( "pt",             &n_pt,             "pt/D");
    tree->Branch( "phi",            &n_phi,            "phi/D");
    tree->Branch( "eta",            &n_eta,            "eta/D");
    tree->Branch( "rapidity",       &n_rapidity,       "rapidity/D");
    tree->Branch( "mass",           &n_mass,           "mass/D");
    tree->Branch( "vtxChi2",        &n_vtxChi2,        "vtxChi2/D");
    tree->Branch( "cosThetaXYZ",    &n_cosThetaXYZ,    "cosThetaXYZ/D");
    tree->Branch( "Lxyz",           &n_Lxyz,           "Lxyz/D");
    tree->Branch( "vtxDecaySigXYZ", &n_vtxDecaySigXYZ, "vtxDecaySigXYZ/D");
    tree->Branch( "DCA",            &n_DCA,            "DCA/D");
    tree->Branch( "pdgId",          &n_pdgId,          "pdgId/I");
    tree->Branch( "pTrkQuality",    &n_pTrkQuality,    "pTrkQuality/I");
    tree->Branch( "pTrkNHit",       &n_pTrkNHit,       "pTrkNHit/I");
    tree->Branch( "pTrkPt",         &n_pTrkPt,         "pTrkPt/D");
    tree->Branch( "pTrkPtError",    &n_pTrkPtError,    "pTrkPtError/D");
    tree->Branch( "pTrkEta",        &n_pTrkEta,        "pTrkEta/D");
    tree->Branch( "pTrkNPxLayer",   &n_pTrkNPxLayer,   "pTrkNPxLayer/I");
    tree->Branch( "pTrkDCASigXY",   &n_pTrkDCASigXY,   "pTrkDCASigXY/D");
    tree->Branch( "pTrkDCASigZ",    &n_pTrkDCASigZ,    "pTrkDCASigZ/D");
    tree->Branch( "nTrkQuality",    &n_nTrkQuality,    "nTrkQuality/I");
    tree->Branch( "nTrkNHit",       &n_nTrkNHit,       "nTrkNHit/I");
    tree->Branch( "nTrkPt",         &n_nTrkPt,         "nTrkPt/D");
    tree->Branch( "nTrkPtError",    &n_nTrkPtError,    "nTrkPtError/D");
    tree->Branch( "nTrkEta",        &n_nTrkEta,        "nTrkEta/D");
    tree->Branch( "nTrkNPxLayer",   &n_nTrkNPxLayer,   "nTrkNPxLayer/I");
    tree->Branch( "nTrkDCASigXY",   &n_nTrkDCASigXY,   "nTrkDCASigXY/D");
    tree->Branch( "nTrkDCASigZ",    &n_nTrkDCASigZ,    "nTrkDCASigZ/D");
    tree->Branch( "Cent",           &Cent,             "Cent/D");

	int idx = 0;
    // cout << trV->GetEntries() << endl;
	while ( trV->GetEntry(idx) ) {
		//cout << " --> idx = " << idx << endl;
		if ( (idx%10000)==0 ) cout << " --> idx = " << idx << endl;
        if ( (vz > 15.) or (vz < -15.) ) {
            idx++;
            continue;
        }
		int sz = pt->size();
		for ( int i = 0; i < sz; i++ ) {
            n_pt             = (*pt            )[i];
            n_phi            = (*phi           )[i];
            n_eta            = (*eta           )[i];
            n_rapidity       = (*rapidity      )[i];
            n_mass           = (*mass          )[i];
            n_vtxChi2        = (*vtxChi2       )[i];
            n_cosThetaXYZ    = (*cosThetaXYZ   )[i];
            n_Lxyz           = (*Lxyz          )[i];
            n_vtxDecaySigXYZ = (*vtxDecaySigXYZ)[i];
            n_DCA            = (*DCA           )[i];
            n_pdgId          = (*pdgId         )[i];
            n_pTrkQuality    = (*pTrkQuality   )[i];
            n_pTrkNHit       = (*pTrkNHit      )[i];
            n_pTrkPt         = (*pTrkPt        )[i];
            n_pTrkPtError    = (*pTrkPtError   )[i];
            n_pTrkEta        = (*pTrkEta       )[i];
            n_pTrkNPxLayer   = (*pTrkNPxLayer  )[i];
            n_pTrkDCASigXY   = (*pTrkDCASigXY  )[i];
            n_pTrkDCASigZ    = (*pTrkDCASigZ   )[i];
            n_nTrkQuality    = (*nTrkQuality   )[i];
            n_nTrkNHit       = (*nTrkNHit      )[i];
            n_nTrkPt         = (*nTrkPt        )[i];
            n_nTrkPtError    = (*nTrkPtError   )[i];
            n_nTrkEta        = (*nTrkEta       )[i];
            n_nTrkNPxLayer   = (*nTrkNPxLayer  )[i];
            n_nTrkDCASigXY   = (*nTrkDCASigXY  )[i];
            n_nTrkDCASigZ    = (*nTrkDCASigZ   )[i];
            tree->Fill();
        }
        idx++;
        if ( idx > limit ) break;
    }
    tree->Write();
}
