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
		double massMin = 1.08, double massMax = 1.16,
		double dauPtMin = 0., double dauDCASig = 1.,
        string prefix = "LM"
		)
{
	TChain * trV = new TChain("trV");
	if ( finput == "test" ) {
		trV->Add("/afs/cern.ch/user/q/qwang/work/cleanroomRun2/Ana/CMSSW_10_3_1_patch3/src/QWAna/QWCumuDiff/run2018/cumu.root/tree/trV");
    }
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
    trV->SetBranchStatus("*", 0);
    trV->SetBranchStatus("Cent", 1);
    trV->SetBranchStatus("vx", 1);

	trV->SetBranchStatus( (prefix+"pt"            ).c_str(),  1 );
	trV->SetBranchStatus( (prefix+"phi"           ).c_str(),  1 );
	trV->SetBranchStatus( (prefix+"eta"           ).c_str(),  1 );
	trV->SetBranchStatus( (prefix+"rapidity"      ).c_str(),  1 );
	trV->SetBranchStatus( (prefix+"mass"          ).c_str(),  1 );
	trV->SetBranchStatus( (prefix+"vtxChi2"       ).c_str(),  1 );
	trV->SetBranchStatus( (prefix+"cosThetaXYZ"   ).c_str(),  1 );
	trV->SetBranchStatus( (prefix+"Lxyz"          ).c_str(),  1 );
	trV->SetBranchStatus( (prefix+"vtxDecaySigXYZ").c_str(),  1 );
	trV->SetBranchStatus( (prefix+"DCA"           ).c_str(),  1 );
	trV->SetBranchStatus( (prefix+"pdgId"         ).c_str(),  1 );

	trV->SetBranchStatus( (prefix+"pTrkQuality" ).c_str(), 1 );
	trV->SetBranchStatus( (prefix+"pTrkNHit"    ).c_str(), 1 );
	trV->SetBranchStatus( (prefix+"pTrkPt"      ).c_str(), 1 );
	trV->SetBranchStatus( (prefix+"pTrkPtError" ).c_str(), 1 );
	trV->SetBranchStatus( (prefix+"pTrkEta"     ).c_str(), 1 );
	trV->SetBranchStatus( (prefix+"pTrkNPxLayer").c_str(), 1 );
	trV->SetBranchStatus( (prefix+"pTrkDCASigXY").c_str(), 1 );
	trV->SetBranchStatus( (prefix+"pTrkDCASigZ" ).c_str(), 1 );

	trV->SetBranchStatus( (prefix+"nTrkQuality" ).c_str(), 1 );
	trV->SetBranchStatus( (prefix+"nTrkNHit"    ).c_str(), 1 );
	trV->SetBranchStatus( (prefix+"nTrkPt"      ).c_str(), 1 );
	trV->SetBranchStatus( (prefix+"nTrkPtError" ).c_str(), 1 );
	trV->SetBranchStatus( (prefix+"nTrkEta"     ).c_str(), 1 );
	trV->SetBranchStatus( (prefix+"nTrkNPxLayer").c_str(), 1 );
	trV->SetBranchStatus( (prefix+"nTrkDCASigXY").c_str(), 1 );
	trV->SetBranchStatus( (prefix+"nTrkDCASigZ" ).c_str(), 1 );

	Double_t        Cent = -1;
	Double_t        vz   = -999;

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
	vector<double>  *pTrkDCASigZ  = 0;

	vector<double>  *nTrkQuality = 0;
	vector<double>  *nTrkNHit = 0;
	vector<double>  *nTrkPt = 0;
	vector<double>  *nTrkPtError = 0;
	vector<double>  *nTrkEta = 0;
	vector<double>  *nTrkNPxLayer = 0;
	vector<double>  *nTrkDCASigXY = 0;
	vector<double>  *nTrkDCASigZ  = 0;

	trV->SetBranchAddress("Cent", &Cent);
	trV->SetBranchAddress("vz",   &vz);

	trV->SetBranchAddress( (prefix+"pt"            ).c_str(), &pt               );
	trV->SetBranchAddress( (prefix+"phi"           ).c_str(), &phi              );
	trV->SetBranchAddress( (prefix+"eta"           ).c_str(), &eta              );
	trV->SetBranchAddress( (prefix+"rapidity"      ).c_str(), &rapidity         );
	trV->SetBranchAddress( (prefix+"mass"          ).c_str(), &mass             );
	trV->SetBranchAddress( (prefix+"vtxChi2"       ).c_str(), &vtxChi2          );
	trV->SetBranchAddress( (prefix+"cosThetaXYZ"   ).c_str(), &cosThetaXYZ      );
	trV->SetBranchAddress( (prefix+"Lxyz"          ).c_str(), &Lxyz             );
	trV->SetBranchAddress( (prefix+"vtxDecaySigXYZ").c_str(), &vtxDecaySigXYZ   );
	trV->SetBranchAddress( (prefix+"DCA"           ).c_str(), &DCA              );
	trV->SetBranchAddress( (prefix+"pdgId"         ).c_str(), &pdgId            );

	trV->SetBranchAddress( (prefix+"pTrkQuality" ).c_str(), &pTrkQuality  );
	trV->SetBranchAddress( (prefix+"pTrkNHit"    ).c_str(), &pTrkNHit     );
	trV->SetBranchAddress( (prefix+"pTrkPt"      ).c_str(), &pTrkPt       );
	trV->SetBranchAddress( (prefix+"pTrkPtError" ).c_str(), &pTrkPtError  );
	trV->SetBranchAddress( (prefix+"pTrkEta"     ).c_str(), &pTrkEta      );
	trV->SetBranchAddress( (prefix+"pTrkNPxLayer").c_str(), &pTrkNPxLayer );
	trV->SetBranchAddress( (prefix+"pTrkDCASigXY").c_str(), &pTrkDCASigXY );
	trV->SetBranchAddress( (prefix+"pTrkDCASigZ" ).c_str(), &pTrkDCASigZ  );

	trV->SetBranchAddress( (prefix+"nTrkQuality" ).c_str(), &nTrkQuality  );
	trV->SetBranchAddress( (prefix+"nTrkNHit"    ).c_str(), &nTrkNHit     );
	trV->SetBranchAddress( (prefix+"nTrkPt"      ).c_str(), &nTrkPt       );
	trV->SetBranchAddress( (prefix+"nTrkPtError" ).c_str(), &nTrkPtError  );
	trV->SetBranchAddress( (prefix+"nTrkEta"     ).c_str(), &nTrkEta      );
	trV->SetBranchAddress( (prefix+"nTrkNPxLayer").c_str(), &nTrkNPxLayer );
	trV->SetBranchAddress( (prefix+"nTrkDCASigXY").c_str(), &nTrkDCASigXY );
	trV->SetBranchAddress( (prefix+"nTrkDCASigZ" ).c_str(), &nTrkDCASigZ  );

// pt                          0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12
    double pTbin[14] = {0.2, 0.4, 0.6, 0.8, 1.0, 1.4, 1.8, 2.2, 2.8, 3.6, 4.6, 6.0, 7.0, 8.5};

// cent                   0,  1,  2,  3,  4,   5,   6,   7
	int centBin[9] = {0, 10, 20, 40, 60, 80, 100, 160, 200};

	TH1D * hMass[13][8];
	for ( int ipt = 0; ipt < 13; ipt++ ) {
		for ( int c = 0; c < 8; c++ ) {
			hMass[ipt][c] = new TH1D( Form("hMass_%i_%i", ipt, c), Form("%1.1f-%1.1f-%i-%i", pTbin[ipt], pTbin[ipt+1], centBin[c], centBin[c+1]), 160, massMin, massMax);
		}
	}
	int idx = 0;

	while ( trV->GetEntry(idx) ) {
		if ( (idx%10000)==0 ) cout << " --> idx = " << idx << endl;
        if ( fabs(vz) > 15 ) {
            idx++;
            continue;
        }
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

            if ( ((*pTrkPt)[i] < dauPtMin) or ((*nTrkPt)[i] < dauPtMin) ) continue;

            if ( ((*pTrkDCASigXY)[i] < dauDCASig) or ((*nTrkDCASigXY)[i] < dauDCASig) or ((*pTrkDCASigZ)[i] < dauDCASig) or ((*nTrkDCASigZ)[i] < dauDCASig) ) continue;

            if ( ((*pTrkPtError)[i]/(*pTrkPt)[i] > pTerrMax) or ((*pTrkPtError)[i]/(*pTrkPt)[i] < pTerrMin) or
                 ((*nTrkPtError)[i]/(*nTrkPt)[i] > pTerrMax) or ((*nTrkPtError)[i]/(*nTrkPt)[i] < pTerrMin) ) continue;

			hMass[ipt][c]->Fill((*mass)[i]);
		}
		idx++;
	}

	TFile * f = new TFile(foutput.c_str(), "recreate");
	for ( int ipt = 0; ipt < 13; ipt++ ) {
		for ( int c = 0; c < 8; c++ ) {
			hMass[ipt][c]->Write();
		}
	}
}
