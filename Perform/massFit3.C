#include "MVAmassFit.C"

void massFit3(string fin, string BDT, string fout, string s = "LM")
{
    TFile * f = new TFile(fin.c_str());

    if ( s == "KS" ) {
        Nbins = 270;
        full_range = make_pair<double, double>(0.450, 0.54);
        signal_range = make_pair<double, double>(0.492, 0.503);
        sb1 = make_pair<double, double>(0.430, 0.489);
        sb2 = make_pair<double, double>(0.506, 0.503);
        mass = 0.497648;
        sigma = 0.01;
        Dmass = 0.005;
    }
    bPol4 = true;

    TH1D * hmass[200] = {};
    TF1 * fits[200] = {};
    TF1 * func_signal[200] = {};
    TF1 * gaus1_signal[200] = {};
    TF1 * gaus2_signal[200] = {};
    TF1 * func_bckgnd[200] = {};

    for ( int i = 0; i < 200; i++ ) {
        hmass[i] = (TH1D*)f->Get(Form("%s/hMass%s_%i", BDT.c_str(), BDT.c_str(), i));
        fits[i] = fitHist(hmass[i], 100);

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
    TH1D * hS = new TH1D("hS", "hS", 200, -1., 1.);
    TH1D * hB = new TH1D("hB", "hB", 200, -1., 1.);
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
        hS->SetBinContent(i+1, S);
        hB->SetBinContent(i+1, B);
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
    hS->Write();
    hB->Write();
    hSignificance->Write();
    hSigma1->Write();
    hSigma2->Write();
    hAmpt1->Write();
    hAmpt2->Write();
    TH1D * hBDT = f->Get<TH1D>(Form("%s/h%s", BDT.c_str(), BDT.c_str()));
    hBDT->Write();
}
