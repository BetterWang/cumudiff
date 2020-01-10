
void genHist()
{
	TChain * mtr = new TChain("mtr");
	mtr->Add("../../PbPb2018/V0Performance/LM_*.root/mtr");

// cent                                 0,  1,  2,  3,  4,   5,   6,   7
	const Float_t centBin[9] = {0, 10, 20, 40, 60, 80, 100, 160, 200};
// pt                                     0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12
	const Float_t pTbin[14] = {0.2, 0.4, 0.6, 0.8, 1.0, 1.4, 1.8, 2.2, 2.8, 3.6, 4.6, 6.0, 7.0, 8.5};

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

	TH1F * hBDT[9][14] = {};
	for ( int c = 0; c < 8; c++ ) {
		for ( int ipt = 0; ipt < 13; ipt++ ) {
			hBDT[c][ipt] = new TH1F(Form("hBDT_%i_%i", c, ipt), Form("%1.1f-%1.1f-%i-%i", pTbin[ipt], pTbin[ipt+1], int(centBin[c]), int(centBin[c+1])), 200, -1., 1.);
		}
	}

	int ievt = 0;
	while ( mtr->GetEntry(ievt) ) {
		if ( ievt%100000 == 0 ) cout << "  --- ... ievt = " << ievt << endl; 
		int c = 0;
		while ( int(Cent) >= centBin[c+1] ) {
			c++;
		}
		if ( pt < pTbin[0] or pt > pTbin[13] or rapidity < -1.0 or rapidity > 1.0) {
			ievt++;
			continue;
		}
		int ipt = 0;
		while ( pt > pTbin[ipt+1] ) {
			ipt++;
		}

		hBDT[c][ipt]->Fill(BDT250_D3);

		ievt++;
		//if ( ievt > 1000000 ) break;
	}

	TFile * fsave = new TFile("test.root", "recreate");
	for ( int c = 0; c < 8; c++ ) {
		for ( int ipt = 0; ipt < 13; ipt++ ) {
			hBDT[c][ipt]->Write();
		}
	}

}
