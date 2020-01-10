#include "TFile.h"
#include "TChain.h"
#include "TMVA/DataLoader.h"
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include <iostream>

using namespace TMVA;


void filter_mass2(string prefix = "LM", string input = "../../PbPb2018/HIMinimumBias4/crab_HIMB4_V0Tree_v6/190917_195729/0000/*.root/tree/trV", string fout = "LM.root" )
{
    TMVA::Tools::Instance();
    TMVA::Reader *reader = new TMVA::Reader( "!Color:!Silent" );

    Float_t pt;
    Float_t rapidity;
    Float_t vtxChi2;
    Float_t cosThetaXYZ;
    Float_t Lxyz;
    Float_t vtxDecaySigXYZ;
    Float_t DCA;
    Float_t pTrkNHit;
    Float_t pTrkPt;
    Float_t pTrkPtError;
    Float_t pTrkEta;
    Float_t pTrkNPxLayer;
    Float_t pTrkDCASigXY;
    Float_t pTrkDCASigZ;
    Float_t nTrkNHit;
    Float_t nTrkPt;
    Float_t nTrkPtError;
    Float_t nTrkEta;
    Float_t nTrkNPxLayer;
    Float_t nTrkDCASigXY;
    Float_t nTrkDCASigZ;
    Float_t Cent; 

    Float_t mass;
    Float_t eta;
    Float_t phi;
    Float_t pdgId;

    reader->AddVariable( "pt",               &pt             );
    reader->AddVariable( "rapidity",         &rapidity       );
    reader->AddVariable( "vtxChi2",          &vtxChi2        );
    reader->AddVariable( "cosThetaXYZ",      &cosThetaXYZ    );
    reader->AddVariable( "Lxyz",             &Lxyz           );
    reader->AddVariable( "vtxDecaySigXYZ",   &vtxDecaySigXYZ );
    reader->AddVariable( "DCA",              &DCA            );
    reader->AddVariable( "pTrkNHit",         &pTrkNHit       );
    reader->AddVariable( "pTrkPt",           &pTrkPt         );
    reader->AddVariable( "pTrkPtError",      &pTrkPtError    );
    reader->AddVariable( "pTrkEta",          &pTrkEta        );
    reader->AddVariable( "pTrkNPxLayer",     &pTrkNPxLayer   );
    reader->AddVariable( "pTrkDCASigXY",     &pTrkDCASigXY   );
    reader->AddVariable( "pTrkDCASigZ",      &pTrkDCASigZ    );
    reader->AddVariable( "nTrkNHit",         &nTrkNHit       );
    reader->AddVariable( "nTrkPt",           &nTrkPt         );
    reader->AddVariable( "nTrkPtError",      &nTrkPtError    );
    reader->AddVariable( "nTrkEta",          &nTrkEta        );
    reader->AddVariable( "nTrkNPxLayer",     &nTrkNPxLayer   );
    reader->AddVariable( "nTrkDCASigXY",     &nTrkDCASigXY   );
    reader->AddVariable( "nTrkDCASigZ",      &nTrkDCASigZ    );
    reader->AddVariable( "Cent",             &Cent           );

    reader->AddSpectator( "mass",   &mass);
    reader->AddSpectator( "eta",    &eta);
    reader->AddSpectator( "phi",    &phi);
    reader->AddSpectator( "pdgId",  &pdgId);

    reader->BookMVA( string("BDT_MCfull"),     string("dataset_full_")+prefix+"/weights/TMVAClassification_BDT250_D3.weights.xml");
    reader->BookMVA( string("BDT_MCrap1"),     string("dataset_rap1_")+prefix+"/weights/TMVAClassification_BDT250_D3.weights.xml");
    reader->BookMVA( string("BDT_DataWSrap1"), string("dataset_dataWS_rap1_")+prefix+"/weights/TMVAClassification_BDT250_D3.weights.xml");

    Float_t BDT_MCfull = 0.;
    Float_t BDT_MCrap1 = 0.;
    Float_t BDT_DataWSrap1 = 0.;

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

    TTree * mtr = new TTree("mtr", "mtr");
    mtr->Branch("mass",     &mass,      "mass/F" );
    mtr->Branch("rapidity", &rapidity,  "rapidity/F" );
    mtr->Branch("pt",       &pt,        "pt/F" );
    mtr->Branch("Cent",     &Cent,      "Cent/F" );

    mtr->Branch("BDT_MCfull",     &BDT_MCfull,        "BDT_MCfull/F" );
    mtr->Branch("BDT_MCrap1",     &BDT_MCrap1,        "BDT_MCrap1/F" );
    mtr->Branch("BDT_DataWSrap1", &BDT_DataWSrap1,    "BDT_DataWSrap1/F" );

    TFile * fsave = new TFile( fout.c_str(), "recreate" );
    int ievt= 0;
    while (trV->GetEntry(ievt)) {
        if (ievt%1000 == 0) std::cout << "--- ... Processing event: " << ievt << std::endl;
        int n = t_pt->size();
        for ( int i = 0; i < n; i++ ) {
            pt            = (*t_pt)[i];
            rapidity      = (*t_rapidity)[i];
            vtxChi2       = (*t_vtxChi2)[i];
            cosThetaXYZ   = (*t_cosThetaXYZ)[i];
            Lxyz          = (*t_Lxyz)[i];
            vtxDecaySigXYZ= (*t_vtxDecaySigXYZ)[i];
            DCA           = (*t_DCA)[i];
            pTrkNHit      = (*t_pTrkNHit)[i];
            pTrkPt        = (*t_pTrkPt)[i];
            pTrkPtError   = (*t_pTrkPtError)[i];
            pTrkEta       = (*t_pTrkEta)[i];
            pTrkNPxLayer  = (*t_pTrkNPxLayer)[i];
            pTrkDCASigXY  = (*t_pTrkDCASigXY)[i];
            pTrkDCASigZ   = (*t_pTrkDCASigZ)[i];
            nTrkNHit      = (*t_nTrkNHit)[i];
            nTrkPt        = (*t_nTrkPt)[i];
            nTrkPtError   = (*t_nTrkPtError)[i];
            nTrkEta       = (*t_nTrkEta)[i];
            nTrkNPxLayer  = (*t_nTrkNPxLayer)[i];
            nTrkDCASigXY  = (*t_nTrkDCASigXY)[i];
            nTrkDCASigZ   = (*t_nTrkDCASigZ)[i];
            Cent          = (t_Cent);

            if ( fabs(rapidity)<1.0 ) continue;

            mass          = (*t_mass)[i];
            eta           = (*t_eta)[i];
            phi           = (*t_phi)[i];
            pdgId         = (*t_pdgId)[i];

            BDT_MCfull = reader->EvaluateMVA( "BDT_MCfull" );
            BDT_MCrap1 = reader->EvaluateMVA( "BDT_MCrap1" );
            BDT_DataWSrap1 = reader->EvaluateMVA( "BDT_DataWSrap1" );

            mtr->Fill();
        }
        ievt++;
        //if ( ievt > 100000 ) break;
    }

    mtr->Write();
    fsave->Close();
}
