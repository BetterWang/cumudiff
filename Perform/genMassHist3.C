#include "TChain.h"
#include "TFile.h"
#include "TH1D.h"
#include "iostream"

using namespace std;

void genMassHist3( Float_t centMin, Float_t centMax, Float_t ptMin, Float_t ptMax, string fout, string s = "LM", bool bForward = false, TString option = "")
{
	TChain * mtr = new TChain("mtr");
    if ( bForward ) {
    } else {
        if ( option.Contains("WrongSign") ) {
	        mtr->Add( (string("../../PbPb2018/V0Performance/newTree9/BDT_")+s+"3_WrongSignMB19.root/mtr").c_str() );
        } else {
	        mtr->Add( (string("../../PbPb2018/V0Performance/newTree9/BDT_")+s+"3_*.root/mtr").c_str() );
        }
    }

    TH1D * hMassBDT_MCfull4 [200] = {};
    TH1D * hMassBDT_DataWS  [200] = {};
    TH1D * hMassBDT_MCfull4C[200] = {};

    for ( int i = 0; i < 200; i++ ) {
        if ( s == "LM" ) {
            hMassBDT_MCfull4[i] = new TH1D(Form("hMassBDT_MCfull4_%i", i), Form("%f", 0.01*i-1.),  160, 1.08, 1.16);
            hMassBDT_DataWS [i] = new TH1D(Form("hMassBDT_DataWS_%i", i), Form("%f", 0.01*i-1.),  160, 1.08, 1.16);
            hMassBDT_MCfull4C[i] = new TH1D(Form("hMassBDT_MCfull4C_%i", i), Form("%f", 0.01*i-1.),  160, 1.08, 1.16);
        }
        if ( s == "KS" ) {
            hMassBDT_MCfull4[i] = new TH1D(Form("hMassBDT_MCfull4_%i", i), Form("%f", 0.01*i-1.),  270, 0.430, 0.565);
            hMassBDT_DataWS [i] = new TH1D(Form("hMassBDT_DataWS_%i", i), Form("%f", 0.01*i-1.),  270, 0.430, 0.565);
            hMassBDT_MCfull4C[i] = new TH1D(Form("hMassBDT_MCfull4C_%i", i), Form("%f", 0.01*i-1.),  270, 0.430, 0.565);
        }
    }

    TH1D * hBDT_MCfull4 = new TH1D("hBDT_MCfull4", "hBDT_MCfull4", 200, -1.0, 1);
    TH1D * hBDT_DataWS  = new TH1D("hBDT_DataWS", "hBDT_DataWS", 200, -1.0, 1);
    TH1D * hBDT_MCfull4C= new TH1D("hBDT_MCfull4C", "hBDT_MCfull4C", 200, -1.0, 1);

	Float_t         mass;
	Float_t         rapidity;
	Float_t         pt;
	Float_t         Cent;
	Float_t         BDT_MCfull4;
	Float_t         BDT_DataWS;
	Float_t         BDT_MCfull4C;

	mtr->SetBranchAddress("mass", &mass );
	mtr->SetBranchAddress("rapidity", &rapidity );
	mtr->SetBranchAddress("pt", &pt );
	mtr->SetBranchAddress("Cent", &Cent );
	mtr->SetBranchAddress("BDT_MCfull4", &BDT_MCfull4);
	mtr->SetBranchAddress("BDT_DataWS", &BDT_DataWS);
	mtr->SetBranchAddress("BDT_MCfull4C", &BDT_MCfull4C);

	int ievt = 0;
	while ( mtr->GetEntry(ievt++) ) {
		if ( ievt%1000000 == 0 ) cout << "  --- ... ievt = " << ievt << endl;
        if ( Cent < centMin or Cent >= centMax or pt < ptMin or pt > ptMax ) {
            continue;
        }
        if ( !bForward ) {
            if ( fabs(rapidity)>1.0 ) {
                continue;
            }
        } else {
            if ( fabs(rapidity) < 1.0 or fabs(rapidity) > 2.0 ) {
                continue;
            }
        }

        for ( int i = 0; i < 200; i++ ) {
            double cut = 0.01*i-1.;
            if ( BDT_MCfull4 > cut ){
                hMassBDT_MCfull4[i]->Fill(mass);
            } else {
                break;
            }
        }

        for ( int i = 0; i < 200; i++ ) {
            double cut = 0.01*i-1.;
            if ( BDT_MCfull4C > cut ){
                hMassBDT_MCfull4C[i]->Fill(mass);
            } else {
                break;
            }
        }

        for ( int i = 0; i < 200; i++ ) {
            double cut = 0.01*i-1.;
            if ( BDT_DataWS > cut ){
                hMassBDT_DataWS[i]->Fill(mass);
            } else {
                break;
            }
        }


        hBDT_MCfull4->Fill(BDT_MCfull4);
        hBDT_DataWS->Fill(BDT_DataWS);
        hBDT_MCfull4C->Fill(BDT_MCfull4C);

        //if ( ievt > 1000000 ) break;
    }

    TFile * fsave = new TFile(fout.c_str(), "recreate");
    auto fBDT_MCfull4 = fsave->mkdir("BDT_MCfull4");
    auto fBDT_DataWS  = fsave->mkdir("BDT_DataWS");
    auto fBDT_MCfull4C= fsave->mkdir("BDT_MCfull4C");

    fBDT_MCfull4->cd();
    for ( int i = 0; i < 200; i++ ) {
        hMassBDT_MCfull4[i]->Write();
    }
    hBDT_MCfull4->Write();

    fBDT_DataWS->cd();
    for ( int i = 0; i < 200; i++ ) {
        hMassBDT_DataWS[i]->Write();
    }
    hBDT_DataWS->Write();

    fBDT_MCfull4C->cd();
    for ( int i = 0; i < 200; i++ ) {
        hMassBDT_MCfull4C[i]->Write();
    }
    hBDT_MCfull4C->Write();

}

