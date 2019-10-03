

void genMassHist3( Float_t centMin, Float_t centMax, Float_t ptMin, Float_t ptMax, string fout, string s = "LM" )
{
	TChain * mtr = new TChain("mtr");
	mtr->Add( (string("../../PbPb2018/V0Performance/newTree3/")+s+"3_*.root/mtr").c_str() );

    TH1D * hMassBDT_MCfull[200] = {};
    TH1D * hMassBDT_MCrap1[200] = {};
    TH1D * hMassBDT_DataWSrap1[200] = {};
    TH1D * hMassBDT_DataSBrap1[200] = {};
    for ( int i = 0; i < 200; i++ ) {
        if ( s == "LM" ) {
            hMassBDT_MCfull[i] = new TH1D(Form("hMassBDT_MCfull_%i", i), Form("%f", 0.01*i-1.),  160, 1.08, 1.16);
            hMassBDT_MCrap1[i] = new TH1D(Form("hMassBDT_MCrap1_%i", i), Form("%f", 0.01*i-1.),  160, 1.08, 1.16);
            hMassBDT_DataWSrap1[i] = new TH1D(Form("hMassBDT_DataWSrap1_%i", i), Form("%f", 0.01*i-1.),  160, 1.08, 1.16);
            hMassBDT_DataSBrap1[i] = new TH1D(Form("hMassBDT_DataSBrap1_%i", i), Form("%f", 0.01*i-1.),  160, 1.08, 1.16);
        }
        if ( s == "KS" ) {
            hMassBDT_MCfull[i] = new TH1D(Form("hMassBDT_MCfull_%i", i), Form("%f", 0.01*i-1.),  270, 0.430, 0.565);
            hMassBDT_MCrap1[i] = new TH1D(Form("hMassBDT_MCrap1_%i", i), Form("%f", 0.01*i-1.),  270, 0.430, 0.565);
            hMassBDT_DataWSrap1[i] = new TH1D(Form("hMassBDT_DataWSrap1_%i", i), Form("%f", 0.01*i-1.),  270, 0.430, 0.565);
            hMassBDT_DataSBrap1[i] = new TH1D(Form("hMassBDT_DataSBrap1_%i", i), Form("%f", 0.01*i-1.),  270, 0.430, 0.565);
        }
    }

    TH1D * hBDT_MCfull = new TH1D("hBDT_MCfull", "hBDT_MCfull", 200, -1.0, 1);
    TH1D * hBDT_MCrap1 = new TH1D("hBDT_MCrap1", "hBDT_MCrap1", 200, -1.0, 1);
    TH1D * hBDT_DataWSrap1 = new TH1D("hBDT_DataWSrap1", "hBDT_DataWSrap1", 200, -1.0, 1);
    TH1D * hBDT_DataSBrap1 = new TH1D("hBDT_DataSBrap1", "hBDT_DataSBrap1", 200, -1.0, 1);

	Float_t         mass;
	Float_t         rapidity;
	Float_t         pt;
	Float_t         Cent;
	Float_t         BDT_MCfull;
	Float_t         BDT_MCrap1;
	Float_t         BDT_DataWSrap1;
	Float_t         BDT_DataSBrap1;

	mtr->SetBranchAddress("mass", &mass );
	mtr->SetBranchAddress("rapidity", &rapidity );
	mtr->SetBranchAddress("pt", &pt );
	mtr->SetBranchAddress("Cent", &Cent );
	mtr->SetBranchAddress("BDT_MCfull", &BDT_MCfull);
	mtr->SetBranchAddress("BDT_MCrap1", &BDT_MCrap1);
	mtr->SetBranchAddress("BDT_DataWSrap1", &BDT_DataWSrap1);
	mtr->SetBranchAddress("BDT_DataSBrap1", &BDT_DataSBrap1);

	int ievt = 0;
	while ( mtr->GetEntry(ievt) ) {
		if ( ievt%1000000 == 0 ) cout << "  --- ... ievt = " << ievt << endl; 
        if ( Cent < centMin or Cent >= centMax or pt < ptMin or pt > ptMax ) {
            ievt++;
            continue;
        }

        for ( int i = 0; i < 200; i++ ) {
            double cut = 0.01*i-1.;
            if ( BDT_MCfull > cut ){
                hMassBDT_MCfull[i]->Fill(mass);
            } else {
                break;
            }
        }
        for ( int i = 0; i < 200; i++ ) {
            double cut = 0.01*i-1.;
            if ( BDT_MCrap1 > cut ){
                hMassBDT_MCrap1[i]->Fill(mass);
            } else {
                break;
            }
        }
        for ( int i = 0; i < 200; i++ ) {
            double cut = 0.01*i-1.;
            if ( BDT_DataWSrap1 > cut ){
                hMassBDT_DataWSrap1[i]->Fill(mass);
            } else {
                break;
            }
        }
        for ( int i = 0; i < 200; i++ ) {
            double cut = 0.01*i-1.;
            if ( BDT_DataSBrap1 > cut ){
                hMassBDT_DataSBrap1[i]->Fill(mass);
            } else {
                break;
            }
        }

        hBDT_MCfull->Fill(BDT_MCfull);
        hBDT_MCrap1->Fill(BDT_MCrap1);
        hBDT_DataWSrap1->Fill(BDT_DataWSrap1);
        hBDT_DataSBrap1->Fill(BDT_DataSBrap1);
        ievt++;
        //if ( ievt > 1000000 ) break;
    }

    TFile * fsave = new TFile(fout.c_str(), "recreate");
    auto fBDT_MCfull = fsave->mkdir("BDT_MCfull");
    auto fBDT_MCrap1 = fsave->mkdir("BDT_MCrap1");
    auto fBDT_DataWSrap1 = fsave->mkdir("BDT_DataWSrap1");
    auto fBDT_DataSBrap1 = fsave->mkdir("BDT_DataSBrap1");

    fBDT_MCfull->cd();
    for ( int i = 0; i < 200; i++ ) {
        hMassBDT_MCfull[i]->Write();
    }
    hBDT_MCfull->Write();

    fBDT_MCrap1->cd();
    for ( int i = 0; i < 200; i++ ) {
        hMassBDT_MCrap1[i]->Write();
    }
    hBDT_MCrap1->Write();

    fBDT_DataWSrap1->cd();
    for ( int i = 0; i < 200; i++ ) {
        hMassBDT_DataWSrap1[i]->Write();
    }
    hBDT_DataWSrap1->Write();

    fBDT_DataSBrap1->cd();
    for ( int i = 0; i < 200; i++ ) {
        hMassBDT_DataSBrap1[i]->Write();
    }
    hBDT_DataSBrap1->Write();

}

