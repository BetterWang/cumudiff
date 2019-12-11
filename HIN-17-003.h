

TGraphErrors * gr_HIN17_003_pPb_v2_Ks;
TGraphErrors * gr_HIN17_003_pPb_v2_Lm;
TGraphErrors * gr_HIN17_003_pPb_v2sub_Ks;
TGraphErrors * gr_HIN17_003_pPb_v2sub_Lm;
TGraphErrors * gr_HIN17_003_pPb_v2subKET_Ks;
TGraphErrors * gr_HIN17_003_pPb_v2subKET_Lm;

TGraphErrors * gr_HIN17_003_PbPb_v2_Ks = nullptr;
TGraphErrors * gr_HIN17_003_PbPb_v2_Lm = nullptr;
TGraphErrors * gr_HIN17_003_PbPb_v2sub_Ks;
TGraphErrors * gr_HIN17_003_PbPb_v2sub_Lm;
TGraphErrors * gr_HIN17_003_PbPb_v2subKET_Ks;
TGraphErrors * gr_HIN17_003_PbPb_v2subKET_Lm;

TGraphErrors * gr_sys_HIN17_003_pPb_v2_Ks;
TGraphErrors * gr_sys_HIN17_003_pPb_v2_Lm;
TGraphErrors * gr_sys_HIN17_003_pPb_v2sub_Ks;
TGraphErrors * gr_sys_HIN17_003_pPb_v2sub_Lm;
TGraphErrors * gr_sys_HIN17_003_pPb_v2subKET_Ks;
TGraphErrors * gr_sys_HIN17_003_pPb_v2subKET_Lm;

TGraphErrors * gr_sys_HIN17_003_PbPb_v2_Ks = nullptr;
TGraphErrors * gr_sys_HIN17_003_PbPb_v2_Lm = nullptr;
TGraphErrors * gr_sys_HIN17_003_PbPb_v2sub_Ks;
TGraphErrors * gr_sys_HIN17_003_PbPb_v2sub_Lm;
TGraphErrors * gr_sys_HIN17_003_PbPb_v2subKET_Ks;
TGraphErrors * gr_sys_HIN17_003_PbPb_v2subKET_Lm;


double sys_pPb_Ks = 0.065;
double sys_pPb_Lm = 0.065;

double sys_PbPb_Ks = 0.065;
double sys_PbPb_Lm = 0.065;



double pT_pPb_Ks[13] = {0.33, 0.51, 0.70, 0.90, 1.18, 1.58, 1.98, 2.46, 3.13, 4.01, 5.15, 6.43, 7.62};
double pT_pPb_Lm[10] = {0.93, 1.19, 1.60, 1.99, 2.47, 3.14, 4.00, 5.12, 6.42, 7.60};

double pT_pPb_KsKET[11] = {0.05, 0.11, 0.18, 0.27, 0.39, 0.58, 0.77, 1.01, 1.34, 1.77, 2.34};
double pT_pPb_LmKET[10] = {0.11, 0.17, 0.28, 0.39, 0.53, 0.74, 1.01, 1.38, 1.80, 2.19};

double pT_PbPb_Ks[13] = {0.36, 0.53, 0.71, 0.90, 1.19, 1.59, 1.98, 2.45, 3.12, 3.99, 5.13, 6.43, 7.63};
double pT_PbPb_Lm[10] = {0.90, 1.20, 1.60, 1.99, 2.47, 3.13, 3.98, 5.10, 6.42, 7.62};

double pT_PbPb_KsKET[12] = {0.06, 0.12, 0.19, 0.27, 0.40, 0.58, 0.77, 1.00, 1.33, 1.76, 2.33, 2.98};
double pT_PbPb_LmKET[10] = {0.11, 0.18, 0.28, 0.39, 0.53, 0.74, 1.01, 1.37, 1.80, 2.20};


TGraphErrors * getGraphFromCSV(string, bool);

void HIN_17_003()
{
//    TFile * f = new TFile("HEPData-ins1670168-v1-root.root");
//
//    gr_HIN17_003_pPb_v2_Ks = (TGraphAsymmErrors*) f->Get("Table 1/Graph1D_y1");
//    gr_HIN17_003_pPb_v2_Lm = (TGraphAsymmErrors*) f->Get("Table 2/Graph1D_y1");
//    gr_HIN17_003_pPb_v2sub_Ks = (TGraphAsymmErrors*) f->Get("Table 6/Graph1D_y1");
//    gr_HIN17_003_pPb_v2sub_Lm = (TGraphAsymmErrors*) f->Get("Table 7/Graph1D_y1");
//    gr_HIN17_003_pPb_v2subKET_Ks = (TGraphAsymmErrors*) f->Get("Table 11/Graph1D_y1");
//    gr_HIN17_003_pPb_v2subKET_Lm = (TGraphAsymmErrors*) f->Get("Table 12/Graph1D_y1");
//
//    gr_HIN17_003_PbPb_v2sub_Ks = (TGraphAsymmErrors*) f->Get("Table 16/Graph1D_y1");
//    gr_HIN17_003_PbPb_v2sub_Lm = (TGraphAsymmErrors*) f->Get("Table 17/Graph1D_y1");
//    gr_HIN17_003_PbPb_v2subKET_Ks = (TGraphAsymmErrors*) f->Get("Table 20/Graph1D_y1");
//    gr_HIN17_003_PbPb_v2subKET_Lm = (TGraphAsymmErrors*) f->Get("Table 21/Graph1D_y1");

    gr_HIN17_003_pPb_v2_Ks        = getGraphFromCSV("HEPData-ins1670168-v1-csv/Table1.csv", false);
    gr_HIN17_003_pPb_v2_Lm        = getGraphFromCSV("HEPData-ins1670168-v1-csv/Table2.csv", false);
    gr_HIN17_003_pPb_v2sub_Ks     = getGraphFromCSV("HEPData-ins1670168-v1-csv/Table6.csv", false);
    gr_HIN17_003_pPb_v2sub_Lm     = getGraphFromCSV("HEPData-ins1670168-v1-csv/Table7.csv", false);
    gr_HIN17_003_pPb_v2subKET_Ks  = getGraphFromCSV("HEPData-ins1670168-v1-csv/Table11.csv", false);
    gr_HIN17_003_pPb_v2subKET_Lm  = getGraphFromCSV("HEPData-ins1670168-v1-csv/Table12.csv", false);

    gr_HIN17_003_PbPb_v2sub_Ks    = getGraphFromCSV("HEPData-ins1670168-v1-csv/Table16.csv", false);
    gr_HIN17_003_PbPb_v2sub_Lm    = getGraphFromCSV("HEPData-ins1670168-v1-csv/Table17.csv", false);
    gr_HIN17_003_PbPb_v2subKET_Ks = getGraphFromCSV("HEPData-ins1670168-v1-csv/Table20.csv", false);
    gr_HIN17_003_PbPb_v2subKET_Lm = getGraphFromCSV("HEPData-ins1670168-v1-csv/Table21.csv", false);


    gr_sys_HIN17_003_pPb_v2_Ks        = getGraphFromCSV("HEPData-ins1670168-v1-csv/Table1.csv", true);
    gr_sys_HIN17_003_pPb_v2_Lm        = getGraphFromCSV("HEPData-ins1670168-v1-csv/Table2.csv", true);
    gr_sys_HIN17_003_pPb_v2sub_Ks     = getGraphFromCSV("HEPData-ins1670168-v1-csv/Table6.csv", true);
    gr_sys_HIN17_003_pPb_v2sub_Lm     = getGraphFromCSV("HEPData-ins1670168-v1-csv/Table7.csv", true);
    gr_sys_HIN17_003_pPb_v2subKET_Ks  = getGraphFromCSV("HEPData-ins1670168-v1-csv/Table11.csv", true);
    gr_sys_HIN17_003_pPb_v2subKET_Lm  = getGraphFromCSV("HEPData-ins1670168-v1-csv/Table12.csv", true);

    gr_sys_HIN17_003_PbPb_v2sub_Ks    = getGraphFromCSV("HEPData-ins1670168-v1-csv/Table16.csv", true);
    gr_sys_HIN17_003_PbPb_v2sub_Lm    = getGraphFromCSV("HEPData-ins1670168-v1-csv/Table17.csv", true);
    gr_sys_HIN17_003_PbPb_v2subKET_Ks = getGraphFromCSV("HEPData-ins1670168-v1-csv/Table20.csv", true);
    gr_sys_HIN17_003_PbPb_v2subKET_Lm = getGraphFromCSV("HEPData-ins1670168-v1-csv/Table21.csv", true);
}


TGraphErrors * getGraphFromCSV(string s, bool syst = false)
{
    std::ifstream fcsv(s.c_str());
    string line;
    for ( int i = 0; i < 15; i++ ) getline(fcsv, line);

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
        y.push_back(v[1]);
        if ( syst ) {
            e.push_back(v[4]);
        } else {
            e.push_back(v[2]);
        }
	}

    TGraphErrors * ret = new TGraphErrors(x.size());
    for ( int i = 0; i < x.size(); i++ ) {
        ret->GetX()[i]  = x[i];
        ret->GetY()[i]  = y[i];
        ret->GetEY()[i] = e[i];
        if ( syst ) {
            ret->GetEX()[i] = 0.15;
        }
    }

    return ret;
}
