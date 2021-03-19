
// pt                          0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12
    double pTbin[14] = {0.2, 0.4, 0.6, 0.8, 1.0, 1.4, 1.8, 2.2, 2.8, 3.6, 4.6, 6.0, 7.0, 8.5};

void getFsigpPb()
{
    std::pair<double, double> signal_range(1.1115, 1.1200);
    if ( s == "KS" ) {
        signal_range = make_pair<double, double>(0.492, 0.503);
    }



    TH1D * hKsFsig[4];
    TH1D * hLmFsig[4];
    for ( int c = 0; c < 4; c++ ) {
        if ( s == "KS" ) {
            hFsig[c] = new TH1D(Form( "vectKs%s", dir[c].c_str() ), "", 13, pTbin);
        } else {
            hFsig[c] = new TH1D(Form( "vectLm%s", dir[c].c_str() ), "", 13, pTbin);
        }
    }

    for ( int c = 0; c < 4; c++ ) {
        for ( int ipt = 0; ipt < 13; ipt++ ) {
            TFile f( (s + option + "/hMass" + y + "_" + to_string(c) + "_" + to_string(ipt) + ".root" ).c_str() );
            TF1 * fit = (TF1*) f.Get("func");
            TF1 * func_signal = (TF1*) f.Get("func_signal");

            double S = func_signal->Integral(signal_range.first, signal_range.second);
            double A = fit->Integral(signal_range.first, signal_range.second);

            hFsig[c]->SetBinContent( ipt+1, S/A );
            f.Close();
            fit->Delete();
            func_signal->Delete();
        }
    }

    TFile * fsave = new TFile((string("Fsig") + s + option + y + "_cent7.root").c_str(), "recreate");
    for ( int c = 0; c < 6; c++ ) {
        hFsig[c]->Write();
    }

    fsave->Close();
}
