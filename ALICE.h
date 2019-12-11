

TGraphErrors * gr_ALICE_AA_v2_Ks_30_40;
TGraphErrors * gr_ALICE_AA_v2_Ks_40_50;
TGraphErrors * gr_ALICE_AA_v2_Lm_30_40;
TGraphErrors * gr_ALICE_AA_v2_Lm_40_50;

TGraphErrors * gr_sys_ALICE_AA_v2_Ks_30_40;
TGraphErrors * gr_sys_ALICE_AA_v2_Ks_40_50;
TGraphErrors * gr_sys_ALICE_AA_v2_Lm_30_40;
TGraphErrors * gr_sys_ALICE_AA_v2_Lm_40_50;

TGraphErrors * getALICEGraphFromCSV(string, bool);


void ALICE()
{
    gr_ALICE_AA_v2_Ks_30_40 = getALICEGraphFromCSV("ALICE-csv/HEPData-ins1672822-v1-Table_73.csv", false);
    gr_ALICE_AA_v2_Ks_40_50 = getALICEGraphFromCSV("ALICE-csv/HEPData-ins1672822-v1-Table_74.csv", false);
    gr_ALICE_AA_v2_Lm_30_40 = getALICEGraphFromCSV("ALICE-csv/HEPData-ins1672822-v1-Table_87.csv", false);
    gr_ALICE_AA_v2_Lm_40_50 = getALICEGraphFromCSV("ALICE-csv/HEPData-ins1672822-v1-Table_88.csv", false);

    gr_sys_ALICE_AA_v2_Ks_30_40 = getALICEGraphFromCSV("ALICE-csv/HEPData-ins1672822-v1-Table_73.csv", true);
    gr_sys_ALICE_AA_v2_Ks_40_50 = getALICEGraphFromCSV("ALICE-csv/HEPData-ins1672822-v1-Table_74.csv", true);
    gr_sys_ALICE_AA_v2_Lm_30_40 = getALICEGraphFromCSV("ALICE-csv/HEPData-ins1672822-v1-Table_87.csv", true);
    gr_sys_ALICE_AA_v2_Lm_40_50 = getALICEGraphFromCSV("ALICE-csv/HEPData-ins1672822-v1-Table_88.csv", true);

    gr_ALICE_AA_v2_Ks_30_40->SetMarkerStyle(kOpenTriangleUp);
    gr_ALICE_AA_v2_Ks_40_50->SetMarkerStyle(kOpenTriangleUp);
    gr_ALICE_AA_v2_Lm_30_40->SetMarkerStyle(kOpenTriangleUp);
    gr_ALICE_AA_v2_Lm_40_50->SetMarkerStyle(kOpenTriangleUp);

    gr_ALICE_AA_v2_Ks_30_40->SetMarkerColor(kRed);
    gr_ALICE_AA_v2_Lm_30_40->SetMarkerColor(kRed);
    gr_ALICE_AA_v2_Ks_30_40->SetLineColor(kRed);
    gr_ALICE_AA_v2_Lm_30_40->SetLineColor(kRed);

    gr_ALICE_AA_v2_Ks_40_50->SetMarkerColor(kBlue);
    gr_ALICE_AA_v2_Lm_40_50->SetMarkerColor(kBlue);
    gr_ALICE_AA_v2_Ks_40_50->SetLineColor(kBlue);
    gr_ALICE_AA_v2_Lm_40_50->SetLineColor(kBlue);
}

TGraphErrors * getALICEGraphFromCSV(string s, bool syst = false)
{
    std::ifstream fcsv(s.c_str());
    string line;
    for ( int i = 0; i < 13; i++ ) getline(fcsv, line);

    vector<double> x;
    vector<double> y;
    vector<double> e;

    while ( getline(fcsv, line) ) {
        if ( line == "" ) continue;
		std::stringstream  strm(line);
		string cell;
		vector<double> v;
		while ( std::getline(strm, cell, ',') ) {
			v.push_back(std::atof(cell.c_str()));
		}
        x.push_back(v[0]);
        y.push_back(v[3]);
        if ( syst ) {
            e.push_back(v[6]);
        } else {
            e.push_back(v[4]);
        }
	}

    TGraphErrors * ret = new TGraphErrors(x.size());
    for ( int i = 0; i < x.size(); i++ ) {
        ret->GetX()[i]  = x[i];
        ret->GetY()[i]  = y[i];
        ret->GetEY()[i] = e[i];
        if ( syst ) {
            ret->GetEX()[i] = 0.1;
        }
    }

    return ret;
}
