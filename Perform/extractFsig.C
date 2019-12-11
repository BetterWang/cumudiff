//   0,   1,     2,     3,   4,   5, 6, 7, 8, 9,     10,  11, 12,   13, 14,  15,     16
// ipt,mean,sigma1,sigma2,sig1,sig2,ap,bp,cp,dp,polysig,chi2,ndf,yield,tot,Fsig,covQual


void extractFsig()
{
	TFile * fsave = new TFile("Fsig.root", "recreate");

	std::map<string, vector<string>> mydict;

	mydict["PbPb15_V0_rap_eta1_NoffAll"]   = vector<string>{"vectKsMassNAll", "vectLmMassNAll"};
	mydict["pPb_V0_HM0_eta1_merge"]        = vector<string>{"vectKsMassN120", "vectKsMassN150", "vectLmMassN120", "vectLmMassN150"};
	mydict["pPb_V0_HM123456_eta1_merge"]   = vector<string>{"vectKsMassN185", "vectLmMassN185"};
	mydict["pPb_V0_HM7_eta1_merge"]        = vector<string>{"vectKsMassN250", "vectLmMassN250"};
	mydict["PbPb15_V0_rap_eta1_Cent_N185"] = vector<string>{"vectKsMassN185", "vectLmMassN185"};
	mydict["PbPb15_V0_rap_eta1_Cent2_N185"] = vector<string>{"vectLmMassN185"};

	//                         0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13
	const double pTbins[] = {0.2, 0.4, 0.6, 0.8, 1.0, 1.4, 1.8, 2.2, 2.8, 3.6, 4.6, 6.0, 7.0, 8.5};

	for ( auto dir = mydict.begin(); dir != mydict.end(); dir++ ) {
		fsave->mkdir(dir->first.c_str());
		fsave->cd(dir->first.c_str());
		for ( auto fname = dir->second.begin(); fname != dir->second.end(); fname++ ) {
			string ff = dir->first + "/" + *fname + ".csv";
			cout << ff << endl;
			std::ifstream fcsv(ff.c_str());
			string line;
			std::getline(fcsv, line); // skip header
			TH1D h(fname->c_str(), "", 13, pTbins);
			h.SetMarkerStyle(kStar);
			while ( std::getline(fcsv, line) )
			{
				//cout << line << endl;
				std::stringstream  strm(line);
				string cell;
				vector<double> v;
				while ( std::getline(strm, cell, ',') ) {
					v.push_back(std::atof(cell.c_str()));
				}
				cout << "Fsig" << v[0] << " = " << v[15] << endl;
				h.SetBinContent(v[0]+1, v[15]);
			}
			h.Write();
		}
		fsave->cd("/");
	}

	/*
	std::ifstream fcsv("PbPb15_V0_rap_eta1_NoffAll/vectKsMassNAll.csv");
	string line;
	std::getline(fcsv, line);
//   0,   1,     2,     3,   4,   5, 6, 7, 8, 9,     10,  11, 12,   13, 14,  15,     16
// ipt,mean,sigma1,sigma2,sig1,sig2,ap,bp,cp,dp,polysig,chi2,ndf,yield,tot,Fsig,covQual

	while ( std::getline(fcsv, line) )
	{
		//cout << line << endl;
		std::stringstream  strm(line);
		string cell;
		vector<double> v;
		while ( std::getline(strm, cell, ',') ) {
			v.push_back(std::atof(cell.c_str()));
		}
		cout << "Fsig" << v[0] << " = " << v[15] << endl;
	}
	*/
}
