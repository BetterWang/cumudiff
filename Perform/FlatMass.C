

// pt                          0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12
    double pTbin[14] = {0.2, 0.4, 0.6, 0.8, 1.0, 1.4, 1.8, 2.2, 2.8, 3.6, 4.6, 6.0, 7.0, 8.5};
// cent                   0,  1,   2,   3,   4,   5
    int centBin[7] = {0, 10, 20,  60, 100, 160, 200};

void FlatMass(string s = "LM", string ss = "SS")
{
    TChain * mtr = new TChain("mtr");
    string sout = "FlatMassWS2_LM.root";

    if ( s == "LM" ) {
        if ( ss == "SS"  ) {
            mtr->Add("../../PbPb2018/V0Performance/MB19v9_LM.root/tree");
            sout = "FlatMassSS2_LM.root";
        } else {
            mtr->Add("../../PbPb2018/V0Performance/MBWrongSign2_LM.root/tree");
            sout = "FlatMassWS2_LM.root";
        }
    } else {
        if ( ss == "SS"  ) {
            mtr->Add("../../PbPb2018/V0Performance/MB19v9_KS.root/tree");
            sout = "FlatMassSS2_KS.root";
        } else {
            mtr->Add("../../PbPb2018/V0Performance/MBWrongSign2_KS.root/tree");
            sout = "FlatMassWS2_KS.root";
        }
    }

    Double_t         mass;
    Double_t         rapidity;
    Double_t         pt;
    Double_t        Cent;

    mtr->SetMakeClass(1);
    mtr->SetBranchAddress("mass", &mass);
    mtr->SetBranchAddress("rapidity", &rapidity);
    mtr->SetBranchAddress("pt", &pt);
    mtr->SetBranchAddress("Cent", &Cent);

    TH1D * hMassMid[6][13];
    TH1D * hMassFwd[6][13];

    if ( s == "LM" ) {
        for ( int c = 0; c < 6; c++ ) {
            for ( int ipt = 0; ipt < 13; ipt++ ) {
                hMassMid[c][ipt] = new TH1D(Form("hMassMid_%i_%i", c, ipt), Form("hMassMid %i-%i, %f-%f;mass;Count", centBin[c], centBin[c+1], pTbin[ipt], pTbin[ipt+1]), 160, 1.08, 1.16);
                hMassFwd[c][ipt] = new TH1D(Form("hMassFwd_%i_%i", c, ipt), Form("hMassFwd %i-%i, %f-%f;mass;Count", centBin[c], centBin[c+1], pTbin[ipt], pTbin[ipt+1]), 160, 1.08, 1.16);
            }
        }
    } else if ( s == "KS" ) {
        for ( int c = 0; c < 6; c++ ) {
            for ( int ipt = 0; ipt < 13; ipt++ ) {
                hMassMid[c][ipt] = new TH1D(Form("hMassMid_%i_%i", c, ipt), Form("hMassMid %i-%i, %f-%f;mass;Count", centBin[c], centBin[c+1], pTbin[ipt], pTbin[ipt+1]), 270, 0.43, 0.565);
                hMassFwd[c][ipt] = new TH1D(Form("hMassFwd_%i_%i", c, ipt), Form("hMassFwd %i-%i, %f-%f;mass;Count", centBin[c], centBin[c+1], pTbin[ipt], pTbin[ipt+1]), 270, 0.43, 0.565);
            }
        }
    }

    int idx = 0;
    while ( mtr->GetEntry(idx++) ) {
        if ( (idx%100000)==0 ) cout << "  ---> " << idx << endl;
        if ( pt > pTbin[13] ) continue;
        if ( fabs(rapidity) > 2.0 ) continue;
        int ipt = 0;
        while ( pt > pTbin[ipt+1] ) ipt++;
        int c = 0;
        while ( Cent > centBin[c+1] ) c++;

        if ( fabs(rapidity) > 1.0 ) {
            hMassFwd[c][ipt]->Fill(mass);
        } else {
            hMassMid[c][ipt]->Fill(mass);
        }
//        if (idx>100000) break;
    }

    TFile * f = new TFile(sout.c_str(), "recreate");
    for ( int c = 0; c < 6; c++ ) {
        for ( int ipt = 0; ipt < 13; ipt++ ) {
            hMassMid[c][ipt]->Write();
            hMassFwd[c][ipt]->Write();
        }
    }
}
