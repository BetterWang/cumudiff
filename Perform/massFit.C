
std::pair<double, double> full_range(1.085, 1.16);
std::pair<double, double> signal_range(1.1115, 1.1200);
std::pair<double, double> sb1(1.085, 1.1000);
std::pair<double, double> sb2(1.1450, 1.16);

double mass = 1.115683;
int Nbins = 160;

//const std::string signal_func = "[3]*TMath::Gaus(x, [0], [1]) + [4]*TMath::Gaus(x, [0], [2])";
const std::string gaus_func = "[2]*TMath::Gaus(x, [0], [1])";

const std::string poly_bkg = "[5] + [6]*x + [7]*x*x + [8]*x*x*x + [9]*x*x*x*x";
const std::string poly_bkg0= "[0] + [1]*x + [2]*x*x + [3]*x*x*x + [4]*x*x*x*x";
const std::string double_gaussian = "[3]*TMath::Gaus(x, [0], [1]) + [4]*TMath::Gaus(x, [0], [2])";
const std::string massfunc = double_gaussian + " + " + poly_bkg;

TF1* fitHist(TH1D* hist, string s)
{

    /////////
    // Setting up the fit func
    // [0] common mean of double gaussian
    // [1] signal 1 gaussian sigma
    // [2] signal 2 gaussian sigma
    // [3] signal 1 amplitude
    // [4] signal 2 amplitude
    //
    // [5] background pol, 1
    // [6] background pol, x
    // [7] background pol, x*x
    // [8] background pol, x*x*x
    // [9] background pol, x*x*x*x
    //

    TF1 * func = new TF1("func", massfunc.c_str(), full_range.first, full_range.second);

    int cnt = 0;
    for ( int i = 0; i < hist->GetNbinsX(); i++ ) {
        double center = hist->GetBinCenter(i+1);
        if ( (center > sb1.first and center < sb1.second) or (center > sb2.first and center < sb2.second) ) {
            cnt++;
        }
    }

    // sb gr
    TGraphErrors gr(cnt);
    cnt = 0;
    for ( int i = 0; i < hist->GetNbinsX(); i++ ) {
        double center = hist->GetBinCenter(i+1);
        if ( (center > sb1.first and center < sb1.second) or (center > sb2.first and center < sb2.second) ) {
            gr.GetX()[cnt] = center;
            gr.GetY()[cnt] = hist->GetBinContent(i+1);
            gr.GetEY()[cnt] = hist->GetBinError(i+1);
            cnt++;
        }
    }

    func->SetParameter(5, 10.);
    func->SetParameter(6, 1.);
    func->SetParameter(7, 1.);
    func->SetParameter(8, 1.);
    func->SetParameter(9, 1.);

    func->FixParameter(0, mass);
    func->FixParameter(1, 1.);
    func->FixParameter(2, 1.);
    func->FixParameter(3, 0.);
    func->FixParameter(4, 0.);

    gr.Fit(func, "q0");
    gr.Fit(func, "q0");
    gr.Fit(func, "q0");

    func->FixParameter(5, func->GetParameter(5));
    func->FixParameter(6, func->GetParameter(6));
    func->FixParameter(7, func->GetParameter(7));
    func->FixParameter(8, func->GetParameter(8));
    func->FixParameter(9, func->GetParameter(9));

    func->ReleaseParameter(0);
    func->SetParLimits(0, mass-0.01, mass+0.01);
    func->ReleaseParameter(1);
    func->ReleaseParameter(2);
    func->ReleaseParameter(3);
    func->ReleaseParameter(4);
    func->SetParLimits(1, 0, 0.025);
    func->SetParLimits(2, 0, 0.025);
    func->SetParLimits(3, 0, 0.8*hist->GetBinContent(hist->FindBin(mass)));
    func->SetParLimits(4, 0, 0.8*hist->GetBinContent(hist->FindBin(mass)));

    hist->Fit(func, "q0", "", full_range.first, full_range.second);
    hist->Fit(func, "q0", "", full_range.first, full_range.second);
    hist->Fit(func, "q0", "", full_range.first, full_range.second);

    func->ReleaseParameter(5);
    func->ReleaseParameter(6);
    func->ReleaseParameter(7);
    func->ReleaseParameter(8);
    func->ReleaseParameter(9);

    hist->Fit(func, "q0", "", full_range.first, full_range.second);
    hist->Fit(func, "q0", "", full_range.first, full_range.second);
    hist->Fit(func, "q0", "", full_range.first, full_range.second);
    return func;
}


void massFit(string fin, string fout, string s = "LM")
{
    TFile * f = new TFile(fin.c_str());

    if ( s == "KS" ) {
        Nbins = 270;
        full_range = make_pair<double, double>(0.430, 0.565);
        signal_range = make_pair<double, double>(0.492, 0.503);
        sb1 = make_pair<double, double>(0.430, 0.489);
        sb2 = make_pair<double, double>(0.506, 0.503);
        mass = 0.497648;
    }

    TH1D * hmass[200] = {};
    TF1 * fits[200] = {};
    TF1 * func_signal[200] = {};
    TF1 * gaus1_signal[200] = {};
    TF1 * gaus2_signal[200] = {};
    TF1 * func_bckgnd[200] = {};

    for ( int i = 0; i < 200; i++ ) {
        hmass[i] = (TH1D*)f->Get(Form("hmass_%i", i));
        fits[i] = fitHist(hmass[i], s);

        func_signal [i] = new TF1(Form("func_signal_%i" , i), double_gaussian.c_str(), full_range.first, full_range.second);
        gaus1_signal[i] = new TF1(Form("gaus1_signal_%i", i), gaus_func.c_str(), full_range.first, full_range.second);
        gaus2_signal[i] = new TF1(Form("gaus2_signal_%i", i), gaus_func.c_str(), full_range.first, full_range.second);
        func_bckgnd [i] = new TF1(Form("func_bckgnd_%i" , i), poly_bkg0.c_str(), full_range.first, full_range.second);

        func_signal[i]->SetParameter(0, fits[i]->GetParameter(0));
        func_signal[i]->SetParameter(1, fits[i]->GetParameter(1));
        func_signal[i]->SetParameter(2, fits[i]->GetParameter(2));
        func_signal[i]->SetParameter(3, fits[i]->GetParameter(3));
        func_signal[i]->SetParameter(4, fits[i]->GetParameter(4));

        func_bckgnd[i]->SetParameter(0, fits[i]->GetParameter(5));
        func_bckgnd[i]->SetParameter(1, fits[i]->GetParameter(6));
        func_bckgnd[i]->SetParameter(2, fits[i]->GetParameter(7));
        func_bckgnd[i]->SetParameter(3, fits[i]->GetParameter(8));
        func_bckgnd[i]->SetParameter(4, fits[i]->GetParameter(9));

        func_signal[i]->SetLineColor(kRed);
        func_bckgnd[i]->SetLineColor(kBlue);

        if ( abs(fits[i]->GetParameter(1)) > abs(fits[i]->GetParameter(2)) ) {
            gaus1_signal[i]->SetParameter(0, fits[i]->GetParameter(0));
            gaus1_signal[i]->SetParameter(1, fits[i]->GetParameter(1));
            gaus1_signal[i]->SetParameter(2, fits[i]->GetParameter(3));
            gaus2_signal[i]->SetParameter(0, fits[i]->GetParameter(0));
            gaus2_signal[i]->SetParameter(1, fits[i]->GetParameter(2));
            gaus2_signal[i]->SetParameter(2, fits[i]->GetParameter(4));
        } else {
            gaus2_signal[i]->SetParameter(0, fits[i]->GetParameter(0));
            gaus2_signal[i]->SetParameter(1, fits[i]->GetParameter(1));
            gaus2_signal[i]->SetParameter(2, fits[i]->GetParameter(3));
            gaus1_signal[i]->SetParameter(0, fits[i]->GetParameter(0));
            gaus1_signal[i]->SetParameter(1, fits[i]->GetParameter(2));
            gaus1_signal[i]->SetParameter(2, fits[i]->GetParameter(4));
        }

        gaus1_signal[i]->SetLineColor(kBlue);
        gaus2_signal[i]->SetLineColor(kRed);
        gaus1_signal[i]->SetLineStyle(kDashDotted);
        gaus2_signal[i]->SetLineStyle(kDashDotted);
    }

    TCanvas *c = new TCanvas("c", "c", 800, 600);

    TH1D * hSignificance = new TH1D("hSignificance", "hSignificance", 200, -1., 1.);
    TH1D * hSigma1 = new TH1D("hSigma1", "hSigma1", 200, -1., 1.);
    TH1D * hSigma2 = new TH1D("hSigma2", "hSigma2", 200, -1., 1.);
    TH1D * hAmpt1 = new TH1D("hAmpt1", "hAmpt1", 200, -1., 1.);
    TH1D * hAmpt2 = new TH1D("hAmpt2", "hAmpt2", 200, -1., 1.);

    for ( int i = 0; i < 200; i++ ) {
    //int i = 100;
        hmass[i]->Draw();
        fits[i]->Draw("same");
        func_signal[i]->Draw("same");
        gaus1_signal[i]->Draw("same");
        gaus2_signal[i]->Draw("same");
        func_bckgnd[i]->Draw("same");
        double S = func_signal[i]->Integral(signal_range.first, signal_range.second);
        double B = func_bckgnd[i]->Integral(signal_range.first, signal_range.second);
        double sig = S/sqrt(S+B);
        hSignificance->SetBinContent(i+1, TMath::IsNaN(sig)?0:sig);

        hSigma1->SetBinContent(i+1, gaus1_signal[i]->GetParameter(1));
        hSigma2->SetBinContent(i+1, gaus2_signal[i]->GetParameter(1));
        hAmpt1->SetBinContent(i+1, gaus1_signal[i]->GetParameter(2));
        hAmpt2->SetBinContent(i+1, gaus2_signal[i]->GetParameter(2));

        c->SaveAs( Form( (fout.substr(0, fout.size()-5)+ "_%i.pdf").c_str(), i) );
    }

    TFile * fsave = new TFile(fout.c_str(), "recreate");
    for ( int i = 0; i < 200; i++ ) {
        hmass[i]->Write();
        fits[i]->Write(Form("fit_%i", i));
    }
    hSignificance->Write();
    hSigma1->Write();
    hSigma2->Write();
    hAmpt1->Write();
    hAmpt2->Write();
    TH1D * hBDT = f->Get<TH1D>("hBDT");
    hBDT->Write();
}
