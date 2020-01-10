

void genMassHist( Float_t centMin, Float_t centMax, Float_t ptMin, Float_t ptMax, string fout, string s = "LM" )
{
	TChain * mtr = new TChain("mtr");
	mtr->Add( (string("../../PbPb2018/V0Performance/")+s+"_*.root/mtr").c_str() );

    TH1D * hmass[200] = {};
    for ( int i = 0; i < 200; i++ ) {
        if ( s == "LM" ) {
            hmass[i] = new TH1D(Form("hmass_%i", i), Form("%f", 0.01*i-1.),  160, 1.08, 1.16);
        }
        if ( s == "KS" ) {
            hmass[i] = new TH1D(Form("hmass_%i", i), Form("%f", 0.01*i-1.),  270, 0.430, 0.565);
        }
    }

    TH1D * hBDT = new TH1D("hBDT", "hBDT", 200, -1.0, 1);

	Float_t         mass;
	Float_t         rapidity;
	Float_t         pt;
	Float_t         Cent;
	Float_t         BDT250_D3;

	mtr->SetBranchAddress("mass", &mass );
	mtr->SetBranchAddress("rapidity", &rapidity );
	mtr->SetBranchAddress("pt", &pt );
	mtr->SetBranchAddress("Cent", &Cent );
	mtr->SetBranchAddress("BDT250_D3", &BDT250_D3 );

	int ievt = 0;
	while ( mtr->GetEntry(ievt) ) {
		if ( ievt%1000000 == 0 ) cout << "  --- ... ievt = " << ievt << endl; 
        if ( Cent < centMin or Cent >= centMax or pt < ptMin or pt > ptMax ) {
            ievt++;
            continue;
        }

        for ( int i = 0; i < 200; i++ ) {
            double cut = 0.01*i-1.;
            if ( BDT250_D3 > cut ){
                hmass[i]->Fill(mass);
            } else {
                break;
            }
        }
        hBDT->Fill(BDT250_D3);
        ievt++;
        //if ( ievt > 1000000 ) break;
    }

    TFile * fsave = new TFile(fout.c_str(), "recreate");
    for ( int i = 0; i < 200; i++ ) {
        hmass[i]->Write();
    }
    hBDT->Write();
}

