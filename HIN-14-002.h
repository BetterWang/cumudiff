TGraphErrors* mgr_pPb_Ks_120_v22;
TGraphErrors* mgr_pPb_Ks_150_v22;
TGraphErrors* mgr_pPb_Ks_185_v22;
TGraphErrors* mgr_pPb_Ks_220_v22;

TGraphErrors* mgr_PbPb_Ks_120_v22;
TGraphErrors* mgr_PbPb_Ks_150_v22;
TGraphErrors* mgr_PbPb_Ks_185_v22;
TGraphErrors* mgr_PbPb_Ks_220_v22;

TGraphErrors* mgr_pPb_Lambda_120_v22;
TGraphErrors* mgr_pPb_Lambda_150_v22;
TGraphErrors* mgr_pPb_Lambda_185_v22;
TGraphErrors* mgr_pPb_Lambda_220_v22;

TGraphErrors* mgr_PbPb_Lambda_120_v22;
TGraphErrors* mgr_PbPb_Lambda_150_v22;
TGraphErrors* mgr_PbPb_Lambda_185_v22;
TGraphErrors* mgr_PbPb_Lambda_220_v22;

TGraphErrors* mgr_pPb_Ks_v22[14] = {};
TGraphErrors* mgr_pPb_Lambda_v22[14] = {};

TGraphErrors* mgr_PbPb_Ks_v22[14] = {};
TGraphErrors* mgr_PbPb_Lambda_v22[14] = {};

pair<TGraphErrors*, TGraphErrors*> getGr(string &s)
{
        istringstream iss(s);
        vector<double> Noff, v2, v2e, v2s;
        while (!iss.eof())
        {
                double x, y, e, sys;
                iss >> x >> y >> e >> sys;
                Noff.push_back(x);
                v2.push_back(y);
                v2e.push_back(e);
                v2s.push_back(sys);
        }
        auto gr  = new TGraphErrors(Noff.size(), &Noff[0], &v2[0], 0, &v2e[0]);
        auto grs = new TGraphErrors(Noff.size(), &Noff[0], &v2[0], 0, &v2s[0]);
        gr->SetMarkerSize(2.);
        return std::make_pair(gr, grs);
};

void HIN_14_002() {
	string str_v22_pPb_120_150 = 
"0.348	0.0193  0.0086  0.0013 "
"0.522	0.0339  0.0029  0.0023 "
"0.706	0.0444  0.0018  0.0031 "
"0.900	0.0620  0.0016  0.0043 "
"1.19	0.0848  0.0011  0.0058 "
"1.58	0.107   0.001   0.007  "
"1.98	0.125   0.002   0.009  "
"2.46	0.136   0.002   0.009  "
"3.13	0.144   0.003   0.010  "
"4.01	0.137   0.004   0.009  "
"5.19	0.141   0.007   0.010  ";


	string str_v22_pPb_150_185 = 
"0.348	0.0168  0.0067  0.0012 "
"0.522	0.0276  0.0022  0.0019 "
"0.706	0.0450  0.0014  0.0031 "
"0.900	0.0590  0.0012  0.0041 "
"1.19	0.0830  0.0008  0.0057 "
"1.58	0.106   0.001   0.007  "
"1.98	0.126   0.001   0.009  "
"2.46	0.139   0.001   0.010  "
"3.13	0.144   0.002   0.010  "
"4.01	0.141   0.003   0.010  "
"5.19	0.129   0.005   0.009  ";

	string str_v22_pPb_185_220 = 
"0.349	0.0113  0.0063  0.0008 "
"0.523	0.0245  0.0020  0.0017 "
"0.707	0.0438  0.0013  0.0030 "
"0.901	0.0596  0.0011  0.0041 "
"1.19	0.0829  0.0008  0.0057 "
"1.58	0.107   0.001   0.007  "
"1.98	0.126   0.001   0.009  "
"2.46	0.136   0.001   0.009  "
"3.13	0.144   0.002   0.010  "
"4.01	0.146   0.003   0.010  "
"5.19	0.136   0.004   0.009  ";

	string str_v22_pPb_220_260 = 
"0.348	-0.00496 0.00913  0.00034 "
"0.523	0.0270   0.0030   0.0019  "
"0.707	0.0387   0.0019   0.0027  "
"0.901	0.0612   0.0016   0.0042  "
"1.19	0.0824   0.0011   0.0057  "
"1.58	0.104    0.001    0.007   "
"1.98	0.125    0.002    0.009   "
"2.46	0.132    0.002    0.009   "
"3.13	0.140    0.002    0.010   "
"4.01	0.148    0.004    0.010   "
"5.19	0.136    0.006    0.009   ";

	auto gr = getGr(str_v22_pPb_120_150);
	gr.first->SetMarkerStyle(kOpenCircle);
	gr.first->SetMarkerColor(kBlue);
	gr.first->SetLineColor(kBlue);
	mgr_pPb_Ks_120_v22 = gr.first;

	gr = getGr(str_v22_pPb_150_185);
	gr.first->SetMarkerStyle(kOpenCircle);
	gr.first->SetMarkerColor(kBlue);
	gr.first->SetLineColor(kBlue);
	mgr_pPb_Ks_150_v22 = gr.first;

	gr = getGr(str_v22_pPb_185_220);
	gr.first->SetMarkerStyle(kOpenCircle);
	gr.first->SetMarkerColor(kBlue);
	gr.first->SetLineColor(kBlue);
	mgr_pPb_Ks_185_v22 = gr.first;

	gr = getGr(str_v22_pPb_220_260);
	gr.first->SetMarkerStyle(kOpenCircle);
	gr.first->SetMarkerColor(kBlue);
	gr.first->SetLineColor(kBlue);
	mgr_pPb_Ks_220_v22 = gr.first;

	str_v22_pPb_120_150 =
"0.885	0.0313  0.0063  0.0022 "
"1.21	0.0564  0.0029  0.0039 "
"1.59	0.0836  0.0025  0.0058 "
"1.99	0.115   0.003   0.008  "
"2.47	0.143   0.003   0.010  "
"3.14	0.176   0.003   0.012  "
"4.00	0.199   0.005   0.014  "
"5.15	0.214   0.009   0.015  ";

	str_v22_pPb_150_185 =
"0.885	0.0338  0.0050  0.0023 "
"1.21	0.0512  0.0022  0.0035 "
"1.59	0.0847  0.0019  0.0058 "
"1.99	0.112   0.002   0.008  "
"2.47	0.143   0.002   0.010  "
"3.14	0.169   0.002   0.012  "
"4.00	0.192   0.004   0.013  "
"5.15	0.210   0.007   0.014  ";

	str_v22_pPb_185_220 =
"0.883	0.0310  0.0047  0.0021 "
"1.21	0.0567  0.0020  0.0039 "
"1.59	0.0811  0.0017  0.0056 "
"1.99	0.104   0.002   0.007  "
"2.47	0.144   0.002   0.010  "
"3.14	0.170   0.002   0.012  "
"4.00	0.196   0.003   0.014  "
"5.15	0.186   0.006   0.013  ";

	str_v22_pPb_220_260 =
"0.881	0.0308  0.0071  0.0021 "
"1.21	0.0477  0.0030  0.0033 "
"1.59	0.0733  0.0025  0.0051 "
"1.99	0.110   0.002   0.008  "
"2.47	0.139   0.002   0.010  "
"3.14	0.177   0.003   0.012  "
"4.00	0.186   0.004   0.013  "
"5.16	0.201   0.008   0.014  ";


	gr = getGr(str_v22_pPb_120_150);
	gr.first->SetMarkerStyle(kOpenSquare);
	gr.first->SetMarkerColor(kBlue);
	gr.first->SetLineColor(kBlue);
	mgr_pPb_Lambda_120_v22 = gr.first;

	gr = getGr(str_v22_pPb_150_185);
	gr.first->SetMarkerStyle(kOpenSquare);
	gr.first->SetMarkerColor(kBlue);
	gr.first->SetLineColor(kBlue);
	mgr_pPb_Lambda_150_v22 = gr.first;

	gr = getGr(str_v22_pPb_185_220);
	gr.first->SetMarkerStyle(kOpenSquare);
	gr.first->SetMarkerColor(kBlue);
	gr.first->SetLineColor(kBlue);
	mgr_pPb_Lambda_185_v22 = gr.first;

	gr = getGr(str_v22_pPb_220_260);
	gr.first->SetMarkerStyle(kOpenSquare);
	gr.first->SetMarkerColor(kBlue);
	gr.first->SetLineColor(kBlue);
	mgr_pPb_Lambda_220_v22 = gr.first;

	mgr_pPb_Ks_v22[6] = mgr_pPb_Ks_120_v22;
	mgr_pPb_Ks_v22[7] = mgr_pPb_Ks_150_v22;
	mgr_pPb_Ks_v22[8] = mgr_pPb_Ks_185_v22;
	mgr_pPb_Ks_v22[9] = mgr_pPb_Ks_220_v22;

	mgr_pPb_Lambda_v22[6] = mgr_pPb_Lambda_120_v22;
	mgr_pPb_Lambda_v22[7] = mgr_pPb_Lambda_150_v22;
	mgr_pPb_Lambda_v22[8] = mgr_pPb_Lambda_185_v22;
	mgr_pPb_Lambda_v22[9] = mgr_pPb_Lambda_220_v22;

// PbPb
	string s =
"0.313	0.0156  0.0067  0.0010 "
"0.510	0.0442  0.0041  0.0029 "
"0.700	0.0768  0.0033  0.0051 "
"0.896	0.101   0.003   0.007  "
"1.18	0.121   0.003   0.008  "
"1.57	0.146   0.003   0.010  "
"1.98	0.157   0.005   0.010  "
"2.45	0.168   0.006   0.011  "
"3.13	0.140   0.009   0.009  "
"4.00	0.153   0.015   0.010  "
"5.17	0.0932  0.0251  0.0062 ";


	gr = getGr(s);
	gr.first->SetMarkerStyle(kOpenCircle);
	gr.first->SetMarkerColor(kBlue);
	gr.first->SetLineColor(kBlue);
	mgr_PbPb_Ks_120_v22 = gr.first;

	s =
"0.314	0.0144  0.0054 0.0010 "
"0.510	0.0446  0.0033 0.0030 "
"0.700	0.0716  0.0026 0.0047 "
"0.896	0.0932  0.0025 0.0062 "
"1.18	0.126   0.002  0.008  "
"1.57	0.146   0.003  0.010  "
"1.98	0.168   0.004  0.011  "
"2.45	0.166   0.005  0.011  "
"3.12	0.165   0.007  0.011  "
"4.00	0.170   0.012  0.011  "
"5.18	0.194   0.020  0.013  ";

	gr = getGr(s);
	gr.first->SetMarkerStyle(kOpenCircle);
	gr.first->SetMarkerColor(kBlue);
	gr.first->SetLineColor(kBlue);
	mgr_PbPb_Ks_150_v22 = gr.first;

	s =
"0.314	0.0232  0.0050 0.0015 "
"0.511	0.0428  0.0029 0.0028 "
"0.701	0.0732  0.0023 0.0048 "
"0.896	0.103   0.002  0.007  "
"1.18	0.130   0.002  0.009  "
"1.57	0.158   0.002  0.010  "
"1.98	0.173   0.003  0.011  "
"2.45	0.166   0.004  0.011  "
"3.12	0.158   0.006  0.010  "
"4.00	0.169   0.010  0.011  "
"5.17	0.141   0.018  0.009  ";

	gr = getGr(s);
	gr.first->SetMarkerStyle(kOpenCircle);
	gr.first->SetMarkerColor(kBlue);
	gr.first->SetLineColor(kBlue);
	mgr_PbPb_Ks_185_v22 = gr.first;

	s =
"0.315	0.0176  0.0042  0.0012 "
"0.511	0.0407  0.0025  0.0027 "
"0.701	0.0805  0.0019  0.0053 "
"0.897	0.103   0.002   0.007  "
"1.18	0.135   0.001   0.009  "
"1.57	0.164   0.002   0.011  "
"1.98	0.175   0.003   0.012  "
"2.45	0.176   0.003   0.012  "
"3.12	0.170   0.005   0.011  "
"4.00	0.137   0.009   0.009  "
"5.18	0.166   0.015   0.011  ";

	gr = getGr(s);
	gr.first->SetMarkerStyle(kOpenCircle);
	gr.first->SetMarkerColor(kBlue);
	gr.first->SetLineColor(kBlue);
	mgr_PbPb_Ks_220_v22 = gr.first;

	s =
"0.846	0.0815  0.0072 0.0054 "
"1.19	0.0955  0.0055 0.0063 "
"1.58	0.164   0.006  0.011  "
"1.98	0.191   0.007  0.013  "
"2.45	0.180   0.008  0.012  "
"3.12	0.221   0.011  0.015  "
"3.98	0.210   0.022  0.014  "
"5.15	0.136   0.039  0.009  ";

	gr = getGr(s);
	gr.first->SetMarkerStyle(kOpenSquare);
	gr.first->SetMarkerColor(kBlue);
	gr.first->SetLineColor(kBlue);
	mgr_PbPb_Lambda_120_v22= gr.first;

	s =
"0.847	0.0715 0.0061 0.0047 "
"1.19	0.111  0.004  0.007  "
"1.58	0.163  0.004  0.011  "
"1.98	0.191  0.005  0.013  "
"2.45	0.227  0.006  0.015  "
"3.11	0.227  0.009  0.015  "
"3.98	0.157  0.016  0.010  "
"5.14	0.211  0.032  0.014  ";

	gr = getGr(s);
	gr.first->SetMarkerStyle(kOpenSquare);
	gr.first->SetMarkerColor(kBlue);
	gr.first->SetLineColor(kBlue);
	mgr_PbPb_Lambda_150_v22= gr.first;

	s =
"0.845	0.0709  0.0054 0.0047 "
"1.19	0.122   0.004  0.008  "
"1.58	0.156   0.004  0.010  "
"1.98	0.186   0.005  0.012  "
"2.45	0.207   0.005  0.014  "
"3.12	0.234   0.008  0.016  "
"3.98	0.213   0.014  0.014  "
"5.14	0.193   0.025  0.013  ";

	gr = getGr(s);
	gr.first->SetMarkerStyle(kOpenSquare);
	gr.first->SetMarkerColor(kBlue);
	gr.first->SetLineColor(kBlue);
	mgr_PbPb_Lambda_185_v22= gr.first;

	s =
"0.844	0.0747  0.0050 0.0049 "
"1.19	0.105   0.003  0.007  "
"1.58	0.158   0.003  0.010  "
"1.98	0.193   0.004  0.013  "
"2.45	0.213   0.004  0.014  "
"3.11	0.227   0.006  0.015  "
"3.98	0.199   0.011  0.013  "
"5.16	0.205   0.019  0.014  ";

	gr = getGr(s);
	gr.first->SetMarkerStyle(kOpenSquare);
	gr.first->SetMarkerColor(kBlue);
	gr.first->SetLineColor(kBlue);
	mgr_PbPb_Lambda_220_v22= gr.first;

	mgr_PbPb_Ks_v22[6] = mgr_PbPb_Ks_120_v22;
	mgr_PbPb_Ks_v22[7] = mgr_PbPb_Ks_150_v22;
	mgr_PbPb_Ks_v22[8] = mgr_PbPb_Ks_185_v22;
	mgr_PbPb_Ks_v22[9] = mgr_PbPb_Ks_220_v22;

	mgr_PbPb_Lambda_v22[6] = mgr_PbPb_Lambda_120_v22;
	mgr_PbPb_Lambda_v22[7] = mgr_PbPb_Lambda_150_v22;
	mgr_PbPb_Lambda_v22[8] = mgr_PbPb_Lambda_185_v22;
	mgr_PbPb_Lambda_v22[9] = mgr_PbPb_Lambda_220_v22;

}
