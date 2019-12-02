

// pt                          0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12
    double pTbin[14] = {0.2, 0.4, 0.6, 0.8, 1.0, 1.4, 1.8, 2.2, 2.8, 3.6, 4.6, 6.0, 7.0, 8.5};
// cent                   0,  1,   2,   3,   4
    int centBin[6] = {0, 20, 60, 100, 160, 200};

void MVAmass(string s = "LM")
{
    TChain * mtr = new TChain("mtr");
    string sout = "MVAmassBDT250D4_LM.root";

    if ( s == "LM" ) {
        mtr->Add("../../PbPb2018/V0Performance/newTree8/LM3_rap1_*.root/mtr");
    } else {
        mtr->Add("../../PbPb2018/V0Performance/newTree8/KS3_rap1_*.root/mtr");
        sout = "MVAmassBDT250D4_KS.root";
    }

    Float_t         mass;
    Float_t         rapidity;
    Float_t         pt;
    Float_t         pdgId;
    Float_t         Cent;
    Float_t         alpha;
    Float_t         v0qt;

    mtr->SetBranchAddress("mass", &mass);
    mtr->SetBranchAddress("rapidity", &rapidity);
    mtr->SetBranchAddress("pt", &pt);
    mtr->SetBranchAddress("pdgId", &pdgId);
    mtr->SetBranchAddress("Cent", &Cent);
    mtr->SetBranchAddress("alpha", &alpha);
    mtr->SetBranchAddress("v0qt", &v0qt);

    TH1D * hMassMid[5][13];
    TH1D * hMassFwd[5][13];

    if ( s == "LM" ) {
        for ( int c = 0; c < 5; c++ ) {
            for ( int ipt = 0; ipt < 13; ipt++ ) {
                hMassMid[c][ipt] = new TH1D(Form("hMassMid_%i_%i", c, ipt), Form("hMassMid %i-%i, %f-%f;mass;Count", centBin[c], centBin[c+1], pTbin[ipt], pTbin[ipt+1]), 160, 1.08, 1.16);
                hMassFwd[c][ipt] = new TH1D(Form("hMassFwd_%i_%i", c, ipt), Form("hMassFwd %i-%i, %f-%f;mass;Count", centBin[c], centBin[c+1], pTbin[ipt], pTbin[ipt+1]), 160, 1.08, 1.16);
            }
        }
    } else if ( s == "KS" ) {
        for ( int c = 0; c < 5; c++ ) {
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
    for ( int c = 0; c < 5; c++ ) {
        for ( int ipt = 0; ipt < 13; ipt++ ) {
            hMassMid[c][ipt]->Write();
            hMassFwd[c][ipt]->Write();
        }
    }
}
