//
// pt                          0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12
    double pTbin[14] = {0.2, 0.4, 0.6, 0.8, 1.0, 1.4, 1.8, 2.2, 2.8, 3.6, 4.6, 6.0, 7.0, 8.5};

std::pair<double, double> full_range(1.095, 1.14);
std::pair<int, int> signal_range(64, 80);
std::pair<int, int> sb1(1, 40);
std::pair<int, int> sb2(121, 160);

double mass = 1.115683;
int Nbins = 160;

void FsigWS(string s1 = "KS", TString options = "SB0")
{
    TFile * f0 = nullptr;
    TFile * f1 = nullptr;
    if ( s1 == "LM" ) {
        f0 = new TFile("MVAmassBDT250D4_LM_WS.root");
        f1 = new TFile("MVAmassBDT250D4_LM20_cent7.root");
    } else if ( s1 == "KS" ) {
        f0 = new TFile("MVAmassBDT250D4_KS_WS.root");
        f1 = new TFile("MVAmassBDT250D4_KS_cent7.root");

        Nbins = 270;
        //full_range = make_pair<double, double>(0.430, 0.565);
        full_range = make_pair<double, double>(0.450, 0.54);
        signal_range = make_pair<int, int>(125, 146);
        sb1 = make_pair<int, int>(1, 90);
        sb2 = make_pair<int, int>(180, 270);
        mass = 0.497648;
    }

    TH1D * hMass0[6][13];
    TH1D * hMass1[6][13];

    for ( int c = 0; c < 6; c++ ) {
        for ( int i = 0; i < 13; i++ ) {
            hMass0[c][i] = (TH1D*) f0->Get(Form("hMassMid_%i_%i", c, i));
            hMass1[c][i] = (TH1D*) f1->Get(Form("hMassMid_%i_%i", c, i));
        }
    }

    TH1D * hFsig[5];
    TCanvas * c1 = new TCanvas("c1", "c1", 800, 600);
    for ( int c = 0; c < 6; c++ ) {
        hFsig[c] = new TH1D(Form( "hFsigMid%i", c), "", 13, pTbin);
        for ( int i = 0; i < 13; i++ ) {
            double sum0_sb1 = hMass0[c][i]->Integral(sb1.first, sb1.second);
            double sum0_sb2 = hMass0[c][i]->Integral(sb2.first, sb2.second);
            double sum1_sb1 = hMass1[c][i]->Integral(sb1.first, sb1.second);
            double sum1_sb2 = hMass1[c][i]->Integral(sb2.first, sb2.second);

            double sum0 = sum0_sb1 + sum0_sb2;
            double sum1 = sum1_sb1 + sum1_sb2;

            double scale0 = sum1 / sum0;
            double scale1 = sum1_sb1 / sum0_sb1;
            double scale2 = sum1_sb2 / sum0_sb2;

            if ( options.Contains("SB0") ) {
                if ( (scale0 != scale0) or (scale0 == TMath::Infinity()))  {
                    cout << " scale0 = " << scale0 << endl;
                    scale0 = 1.;
                }
                hMass0[c][i]->Scale(scale0);
                //cout << " scale0 = " << scale0 << endl;
            }
            if ( options.Contains("SB1") ) {
                hMass0[c][i]->Scale(scale1);
                //cout << " scale1 = " << scale1 << endl;
            }
            if ( options.Contains("SB2") ) {
                hMass0[c][i]->Scale(scale2);
                //cout << " scale2 = " << scale2 << endl;
            }

            hMass1[c][i]->SetLineColor(kRed);
            hMass0[c][i]->SetLineColor(kBlue);

            hMass1[c][i]->Draw("hist");
            hMass0[c][i]->Draw("histsame");
            c1->SaveAs(Form("hMass%s_%i_%i.pdf", s1.c_str(), c, i));

            double y0 = hMass0[c][i]->Integral(signal_range.first, signal_range.second);
            double y1 = hMass1[c][i]->Integral(signal_range.first, signal_range.second);

            cout << "c = " << c << " i = " << i << " y1 = " << y1 << " y0 = " << y0 << endl;
            if ( y1 != 0. ) {
                hFsig[c]->SetBinContent( i+1, (y1-y0)/y1 );
            } else {
                hFsig[c]->SetBinContent( i+1, 0 );
            }
        }
    }

    TFile * fsave = new TFile(Form("Fsig%sMid_WS.root", s1.c_str()), "recreate");
    for ( int c = 0; c < 6; c++ ) {
        hFsig[c]->Write();
    }
    fsave->Close();
}

