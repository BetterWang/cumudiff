#include "TChain.h"
#include "TH1.h"
#include "TFile.h"
#include "string"
#include "iostream"


using namespace std;
void V0tuneA(string finput = "MB1",
		string foutput = "fout.root",
	 	double etaMin = -1.0, double etaMax = 1.0,
		double DecayXYZMin = 5.0, double DecayXYZMax = 9999999., //  vtxDecaySigXYZ
		double ThetaXYZMin = 0.9999, double ThetaXYZMax = 999., // cosThetaXYZ
		double vtxChi2Min = 0, double vtxChi2Max = 99, // vtxChi2 0.-7.
		double LxyzMin = 0, double LxyzMax = 9999999, // Lxyz 0. - 200.
		double DCAMin = 0, double DCAMax = 99, // DCA 0. - 1.
        bool highPurity = false, // track highPurity?
        double pTerrMin = 0.0, double pTerrMax = 99999.0, // track pterror / pt  < pTerr
        int NHitsMin = 0, int NHitsMax = 99999, // track NHits < NHits
		double massMin = 1.08, double massMax = 1.16
		)
{
	TChain * trV = new TChain("trV");
	if ( finput == "MB1" ) {
		trV->Add("../../PbPb2018/HIMinimumBias1/crab_HIMB1_V0Tree_v1/190218_180553/0000/*.root/treeLm/trV");
		trV->Add("../../PbPb2018/HIMinimumBias1/crab_HIMB1_V0Tree_v1/190218_180553/0001/*.root/treeLm/trV");
	}
	if ( finput == "MB1v2" ) {
		trV->Add("../../PbPb2018/HIMinimumBias1/crab_HIMB1_LmTree_v2/190225_190655/0000/*.root/treeLm/trV");
		trV->Add("../../PbPb2018/HIMinimumBias1/crab_HIMB1_LmTree_v2/190225_190655/0001/*.root/treeLm/trV");
    }
	if ( finput == "MB1v3" ) {
		trV->Add("../../PbPb2018/HIMinimumBias1/crab_HIMB1_LmTree_v3/190311_191253/0000/*.root/treeLm/trV");
		trV->Add("../../PbPb2018/HIMinimumBias1/crab_HIMB1_LmTree_v3/190311_191253/0001/*.root/treeLm/trV");
    }
	trV->SetMakeClass(1);

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
	Double_t        Cent = -1;

	vector<double>  *pdgId = 0;

	vector<double>  *pTrkQuality = 0;
	vector<double>  *pTrkNHit = 0;
	vector<double>  *pTrkPt = 0;
	vector<double>  *pTrkPtError = 0;
	vector<double>  *pTrkEta = 0;
	vector<double>  *pTrkNPxLayer = 0;

	vector<double>  *nTrkQuality = 0;
	vector<double>  *nTrkNHit = 0;
	vector<double>  *nTrkPt = 0;
	vector<double>  *nTrkPtError = 0;
	vector<double>  *nTrkEta = 0;
	vector<double>  *nTrkNPxLayer = 0;

	// List of branches
	TBranch        *b_pt;   //!
	TBranch        *b_phi;   //!
	TBranch        *b_eta;   //!
	TBranch        *b_rapidity;   //!
	TBranch        *b_mass;   //!
	TBranch        *b_vtxChi2;   //!
	TBranch        *b_cosThetaXYZ;   //!
	TBranch        *b_Lxyz;   //!
	TBranch        *b_vtxDecaySigXYZ;   //!
	TBranch        *b_DCA;   //!
	TBranch        *b_Cent;   //!

	TBranch        *b_pdgId;   //!

	TBranch        *b_pTrkQuality;   //!
	TBranch        *b_pTrkNHit;   //!
	TBranch        *b_pTrkPt;   //!
	TBranch        *b_pTrkPtError;   //!
	TBranch        *b_pTrkEta;   //!
	TBranch        *b_pTrkNPxLayer;   //!

	TBranch        *b_nTrkQuality;   //!
	TBranch        *b_nTrkNHit;   //!
	TBranch        *b_nTrkPt;   //!
	TBranch        *b_nTrkPtError;   //!
	TBranch        *b_nTrkEta;   //!
	TBranch        *b_nTrkNPxLayer;   //!

	trV->SetBranchAddress("pt", &pt, &b_pt);
	trV->SetBranchAddress("phi", &phi, &b_phi);
	trV->SetBranchAddress("eta", &eta, &b_eta);
	trV->SetBranchAddress("rapidity", &rapidity, &b_rapidity);
	trV->SetBranchAddress("mass", &mass, &b_mass);
	trV->SetBranchAddress("vtxChi2", &vtxChi2, &b_vtxChi2);
	trV->SetBranchAddress("cosThetaXYZ", &cosThetaXYZ, &b_cosThetaXYZ);
	trV->SetBranchAddress("Lxyz", &Lxyz, &b_Lxyz);
	trV->SetBranchAddress("vtxDecaySigXYZ", &vtxDecaySigXYZ, &b_vtxDecaySigXYZ);
	trV->SetBranchAddress("DCA", &DCA, &b_DCA);
	trV->SetBranchAddress("Cent", &Cent, &b_Cent);

	trV->SetBranchAddress("pdgId",  &pdgId,  &b_pdgId);

	trV->SetBranchAddress("pTrkQuality",  &pTrkQuality,  &b_pTrkQuality);
	trV->SetBranchAddress("pTrkNHit",     &pTrkNHit,     &b_pTrkNHit);
	trV->SetBranchAddress("pTrkPt",       &pTrkPt,       &b_pTrkPt);
	trV->SetBranchAddress("pTrkPtError",  &pTrkPtError,  &b_pTrkPtError);
	trV->SetBranchAddress("pTrkEta",      &pTrkEta,      &b_pTrkEta);
	trV->SetBranchAddress("pTrkNPxLayer", &pTrkNPxLayer, &b_pTrkNPxLayer);

	trV->SetBranchAddress("nTrkQuality",  &nTrkQuality,  &b_nTrkQuality);
	trV->SetBranchAddress("nTrkNHit",     &nTrkNHit,     &b_nTrkNHit);
	trV->SetBranchAddress("nTrkPt",       &nTrkPt,       &b_nTrkPt);
	trV->SetBranchAddress("nTrkPtError",  &nTrkPtError,  &b_nTrkPtError);
	trV->SetBranchAddress("nTrkEta",      &nTrkEta,      &b_nTrkEta);
	trV->SetBranchAddress("nTrkNPxLayer", &nTrkNPxLayer, &b_nTrkNPxLayer);

// pt                          0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12
    double pTbin[14] = {0.2, 0.4, 0.6, 0.8, 1.0, 1.4, 1.8, 2.2, 2.8, 3.6, 4.6, 6.0, 7.0, 8.5};

// cent                       0,  1,   2,   3,   4
	int centBin[6] = {0, 20, 60, 100, 160, 200};

	TH1D * hMass[13][6];
	for ( int ipt = 0; ipt < 13; ipt++ ) {
		for ( int c = 0; c < 5; c++ ) {
			hMass[ipt][c] = new TH1D( Form("hMass_%i_%i", ipt, c), Form("%1.1f-%1.1f-%i-%i", pTbin[ipt], pTbin[ipt+1], centBin[c], centBin[c+1]), 160, massMin, massMax);
		}
	}
	int idx = 0;

	while ( trV->GetEntry(idx) ) {
		if ( (idx%10000)==0 ) cout << " --> idx = " << idx << endl;
		int c = 0;
		while ( int(Cent) >= centBin[c+1] ) {
			c++;
		}
		int sz = pt->size();
		for ( int i = 0; i < sz; i++ ) {
			if ( (*pt)[i] < pTbin[0] or (*pt)[i] > pTbin[13] or (*rapidity)[i] < etaMin or (*rapidity)[i] > etaMax ) {
				continue;
			}
			int ipt = 0;
			while ( (*pt)[i] > pTbin[ipt+1] ) {
				ipt++;
			}

			if ( (*vtxDecaySigXYZ)[i] < DecayXYZMin or (*vtxDecaySigXYZ)[i] > DecayXYZMax ) continue;
			if ( (*cosThetaXYZ)[i] < ThetaXYZMin or (*cosThetaXYZ)[i] > ThetaXYZMax ) continue;
			if ( (*vtxChi2)[i] < vtxChi2Min or (*vtxChi2)[i] > vtxChi2Max ) continue;
			if ( (*Lxyz)[i] < LxyzMin or (*Lxyz)[i] > LxyzMax ) continue;
			if ( (*DCA)[i] < DCAMin or (*DCA)[i] > DCAMax ) continue;

            if ( highPurity ) {
                // highPurity = 1<<2
                if ( !(int((*pTrkQuality)[i]) & 4) or !(int((*nTrkQuality)[i]) & 4) ) continue;
            }

            if ( ((*pTrkNHit)[i] < NHitsMin) or ((*nTrkNHit)[i] < NHitsMin) or
                 ((*pTrkNHit)[i] > NHitsMax) or ((*nTrkNHit)[i] > NHitsMax) ) continue;

            if ( ((*pTrkPtError)[i]/(*pTrkPt)[i] > pTerrMax) or ((*pTrkPtError)[i]/(*pTrkPt)[i] < pTerrMin) or
                 ((*nTrkPtError)[i]/(*nTrkPt)[i] > pTerrMax) or ((*nTrkPtError)[i]/(*nTrkPt)[i] < pTerrMin) ) continue;

			hMass[ipt][c]->Fill((*mass)[i]);
		}
		idx++;
	}

	TFile * f = new TFile(foutput.c_str(), "recreate");
	for ( int ipt = 0; ipt < 13; ipt++ ) {
		for ( int c = 0; c < 5; c++ ) {
			hMass[ipt][c]->Write();
		}
	}
}
