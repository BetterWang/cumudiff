
// pt                          0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12
    double pTbin[14] = {0.2, 0.4, 0.6, 0.8, 1.0, 1.4, 1.8, 2.2, 2.8, 3.6, 4.6, 6.0, 7.0, 8.5};
// cent                   0,  1,   2,   3,   4
    int centBin[6] = {0, 20, 60, 100, 160, 200};

void getFsig(string s = "LM", string y = "Mid")
{
    std::pair<double, double> signal_range(1.1115, 1.1200);
    if ( s == "KS" ) {
        signal_range = make_pair<double, double>(0.492, 0.503);
    }

    TH1D * hFsig[5];
    for ( int c = 0; c < 5; c++ ) {
        hFsig[c] = new TH1D(Form( "hFsig%s%i", y.c_str(), c), "", 13, pTbin);
    }

    for ( int c = 0; c < 5; c++ ) {
        for ( int ipt = 4; ipt < 13; ipt++ ) {
            TFile f( (s + "/hMass" + y + "_" + to_string(c) + "_" + to_string(ipt) + ".root" ).c_str() );
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

    TFile * fsave = new TFile(Form("Fsig%s%s.root", s.c_str(), y.c_str()), "recreate");
    for ( int c = 0; c < 5; c++ ) {
        hFsig[c]->Write();
    }

}
