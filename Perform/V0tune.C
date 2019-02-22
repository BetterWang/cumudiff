#include "TChain.h"
#include "TH1.h"
#include "TFile.h"
#include "string"
#include "iostream"


using namespace std;
void V0tune(string finput = "MB1",
		string foutput = "fout.root",
		double ptMin = 1.0, double ptMax = 1.4,
		double etaMin = -1.0, double etaMax = 1.0,
		int centMin = 20, int centMax = 60,
		double DecayXYZMin = 5.0, double DecayXYZMax = 9999999., //  vtxDecaySigXYZ
		double ThetaXYZMin = 0.9999, double ThetaXYZMax = 999., // cosThetaXYZ
		double vtxChi2Min = 0, double vtxChi2Max = 99, // vtxChi2 0.-7.
		double LxyzMin = 0, double LxyzMax = 9999999, // Lxyz 0. - 200.
		double DCAMin = 0, double DCAMax = 99, // DCA 0. - 1.
		double massMin = 1.08, double massMax = 1.16
		)
{
	TChain * trV = new TChain("trV");
	if ( finput == "MB1" ) {
		trV->Add("../../PbPb2018/HIMinimumBias1/crab_HIMB1_V0Tree_v1/190218_180553/0000/*.root/treeLm/trV");
		trV->Add("../../PbPb2018/HIMinimumBias1/crab_HIMB1_V0Tree_v1/190218_180553/0001/*.root/treeLm/trV");
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

	TH1D * hMass = new TH1D("hMass", "hMass", 160, massMin, massMax);
	int idx = 0;

	while ( trV->GetEntry(idx) ) {
		if ( (idx%10000)==0 ) cout << " --> idx = " << idx << endl;
		if ( int(Cent) < centMin or int(Cent) >= centMax ) {
			idx++;
			continue;
		}
		int sz = pt->size();
		for ( int i = 0; i < sz; i++ ) {
			if ( (*pt)[i] < ptMin or (*pt)[i] > ptMax or (*rapidity)[i] < etaMin or (*rapidity)[i] > etaMax ) {
				continue;
			}

			if ( (*vtxDecaySigXYZ)[i] < DecayXYZMin or (*vtxDecaySigXYZ)[i] > DecayXYZMax ) continue;
			if ( (*cosThetaXYZ)[i] < ThetaXYZMin or (*cosThetaXYZ)[i] > ThetaXYZMax ) continue;
			if ( (*vtxChi2)[i] < vtxChi2Min or (*vtxChi2)[i] > vtxChi2Max ) continue;
			if ( (*Lxyz)[i] < LxyzMin or (*Lxyz)[i] > LxyzMax ) continue;
			if ( (*DCA)[i] < DCAMin or (*DCA)[i] > DCAMax ) continue;

			hMass->Fill((*mass)[i]);
		}
		idx++;
	}

	TFile * f = new TFile(foutput.c_str(), "recreate");
	hMass->Write();
}
