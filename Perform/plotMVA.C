#include "fitHelper.h"

// pt                          0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12
    double pTbin[14] = {0.2, 0.4, 0.6, 0.8, 1.0, 1.4, 1.8, 2.2, 2.8, 3.6, 4.6, 6.0, 7.0, 8.5};
// cent                   0,  1,   2,   3,   4
    int centBin[6] = {0, 20, 60, 100, 160, 200};

void plotMVA(string s = "LM", string fname = "MVAmass_LM.root")
{
    TFile * f;
    if ( s == "LM" ) {
        f = new TFile(fname.c_str());
    } else if ( s == "KS" ) {
        f = new TFile(fname.c_str());
        Nbins = 270;
        full_range = make_pair<double, double>(0.430, 0.565);
        signal_range = make_pair<double, double>(0.492, 0.503);
        sb1 = make_pair<double, double>(0.430, 0.489);
        sb2 = make_pair<double, double>(0.506, 0.503);
        mass = 0.497648;
        sigma = 0.01;
        Dmass = 0.005;
    }

    TH1D * hMassMid[5][13];
    TH1D * hMassFwd[5][13];

    TF1 * fits_Mid[5][13] = {};
    TF1 * func_signal_Mid[5][13] = {};
    TF1 * gaus1_signal_Mid[5][13] = {};
    TF1 * gaus2_signal_Mid[5][13] = {};
    TF1 * func_bckgnd_Mid[5][13] = {};

    TF1 * fits_Fwd[5][13] = {};
    TF1 * func_signal_Fwd[5][13] = {};
    TF1 * gaus1_signal_Fwd[5][13] = {};
    TF1 * gaus2_signal_Fwd[5][13] = {};
    TF1 * func_bckgnd_Fwd[5][13] = {};

    for ( int c = 0; c < 5; c++ ) {
        for ( int ipt = 0; ipt < 13; ipt++ ) {
            hMassMid[c][ipt] = (TH1D*) f->Get(Form("hMassMid_%i_%i", c, ipt));
            hMassFwd[c][ipt] = (TH1D*) f->Get(Form("hMassFwd_%i_%i", c, ipt));
        }
    }

    for ( int c = 0; c < 5; c++ ) {
        for ( int ipt = 0; ipt < 13; ipt++ ) {
            // Mid
            fits_Mid[c][ipt] = fitHist(hMassMid[c][ipt], s);

            func_signal_Mid [c][ipt] = new TF1(Form("func_signal_Mid_%i_%i" , c, ipt), double_gaussian.c_str(), full_range.first, full_range.second);
            gaus1_signal_Mid[c][ipt] = new TF1(Form("gaus1_signal_Mid_%i_%i", c, ipt), gaus_func.c_str(), full_range.first, full_range.second);
            gaus2_signal_Mid[c][ipt] = new TF1(Form("gaus2_signal_Mid_%i_%i", c, ipt), gaus_func.c_str(), full_range.first, full_range.second);
            func_bckgnd_Mid [c][ipt] = new TF1(Form("func_bckgnd_Mid_%i_%i" , c, ipt), poly_bkg0.c_str(), full_range.first, full_range.second);

            func_signal_Mid[c][ipt]->SetParameter(0, fits_Mid[c][ipt]->GetParameter(0));
            func_signal_Mid[c][ipt]->SetParameter(1, fits_Mid[c][ipt]->GetParameter(1));
            func_signal_Mid[c][ipt]->SetParameter(2, fits_Mid[c][ipt]->GetParameter(2));
            func_signal_Mid[c][ipt]->SetParameter(3, fits_Mid[c][ipt]->GetParameter(3));
            func_signal_Mid[c][ipt]->SetParameter(4, fits_Mid[c][ipt]->GetParameter(4));

            func_bckgnd_Mid[c][ipt]->SetParameter(0, fits_Mid[c][ipt]->GetParameter(5));
            func_bckgnd_Mid[c][ipt]->SetParameter(1, fits_Mid[c][ipt]->GetParameter(6));
            func_bckgnd_Mid[c][ipt]->SetParameter(2, fits_Mid[c][ipt]->GetParameter(7));
            func_bckgnd_Mid[c][ipt]->SetParameter(3, fits_Mid[c][ipt]->GetParameter(8));
            func_bckgnd_Mid[c][ipt]->SetParameter(4, fits_Mid[c][ipt]->GetParameter(9));

            func_signal_Mid[c][ipt]->SetLineColor(kRed);
            func_bckgnd_Mid[c][ipt]->SetLineColor(kBlue);

            if ( abs(fits_Mid[c][ipt]->GetParameter(1)) > abs(fits_Mid[c][ipt]->GetParameter(2)) ) {
                gaus1_signal_Mid[c][ipt]->SetParameter(0, fits_Mid[c][ipt]->GetParameter(0));
                gaus1_signal_Mid[c][ipt]->SetParameter(1, fits_Mid[c][ipt]->GetParameter(1));
                gaus1_signal_Mid[c][ipt]->SetParameter(2, fits_Mid[c][ipt]->GetParameter(3));
                gaus2_signal_Mid[c][ipt]->SetParameter(0, fits_Mid[c][ipt]->GetParameter(0));
                gaus2_signal_Mid[c][ipt]->SetParameter(1, fits_Mid[c][ipt]->GetParameter(2));
                gaus2_signal_Mid[c][ipt]->SetParameter(2, fits_Mid[c][ipt]->GetParameter(4));
            } else {
                gaus2_signal_Mid[c][ipt]->SetParameter(0, fits_Mid[c][ipt]->GetParameter(0));
                gaus2_signal_Mid[c][ipt]->SetParameter(1, fits_Mid[c][ipt]->GetParameter(1));
                gaus2_signal_Mid[c][ipt]->SetParameter(2, fits_Mid[c][ipt]->GetParameter(3));
                gaus1_signal_Mid[c][ipt]->SetParameter(0, fits_Mid[c][ipt]->GetParameter(0));
                gaus1_signal_Mid[c][ipt]->SetParameter(1, fits_Mid[c][ipt]->GetParameter(2));
                gaus1_signal_Mid[c][ipt]->SetParameter(2, fits_Mid[c][ipt]->GetParameter(4));
            }

            gaus1_signal_Mid[c][ipt]->SetLineColor(kBlue);
            gaus2_signal_Mid[c][ipt]->SetLineColor(kRed);
            gaus1_signal_Mid[c][ipt]->SetLineStyle(kDashDotted);
            gaus2_signal_Mid[c][ipt]->SetLineStyle(kDashDotted);


            // Fwd
            fits_Fwd[c][ipt] = fitHist(hMassFwd[c][ipt], s);

            func_signal_Fwd [c][ipt] = new TF1(Form("func_signal_Fwd_%i_%i" , c, ipt), double_gaussian.c_str(), full_range.first, full_range.second);
            gaus1_signal_Fwd[c][ipt] = new TF1(Form("gaus1_signal_Fwd_%i_%i", c, ipt), gaus_func.c_str(), full_range.first, full_range.second);
            gaus2_signal_Fwd[c][ipt] = new TF1(Form("gaus2_signal_Fwd_%i_%i", c, ipt), gaus_func.c_str(), full_range.first, full_range.second);
            func_bckgnd_Fwd [c][ipt] = new TF1(Form("func_bckgnd_Fwd_%i_%i" , c, ipt), poly_bkg0.c_str(), full_range.first, full_range.second);

            func_signal_Fwd[c][ipt]->SetParameter(0, fits_Fwd[c][ipt]->GetParameter(0));
            func_signal_Fwd[c][ipt]->SetParameter(1, fits_Fwd[c][ipt]->GetParameter(1));
            func_signal_Fwd[c][ipt]->SetParameter(2, fits_Fwd[c][ipt]->GetParameter(2));
            func_signal_Fwd[c][ipt]->SetParameter(3, fits_Fwd[c][ipt]->GetParameter(3));
            func_signal_Fwd[c][ipt]->SetParameter(4, fits_Fwd[c][ipt]->GetParameter(4));

            func_bckgnd_Fwd[c][ipt]->SetParameter(0, fits_Fwd[c][ipt]->GetParameter(5));
            func_bckgnd_Fwd[c][ipt]->SetParameter(1, fits_Fwd[c][ipt]->GetParameter(6));
            func_bckgnd_Fwd[c][ipt]->SetParameter(2, fits_Fwd[c][ipt]->GetParameter(7));
            func_bckgnd_Fwd[c][ipt]->SetParameter(3, fits_Fwd[c][ipt]->GetParameter(8));
            func_bckgnd_Fwd[c][ipt]->SetParameter(4, fits_Fwd[c][ipt]->GetParameter(9));

            func_signal_Fwd[c][ipt]->SetLineColor(kRed);
            func_bckgnd_Fwd[c][ipt]->SetLineColor(kBlue);

            if ( abs(fits_Fwd[c][ipt]->GetParameter(1)) > abs(fits_Fwd[c][ipt]->GetParameter(2)) ) {
                gaus1_signal_Fwd[c][ipt]->SetParameter(0, fits_Fwd[c][ipt]->GetParameter(0));
                gaus1_signal_Fwd[c][ipt]->SetParameter(1, fits_Fwd[c][ipt]->GetParameter(1));
                gaus1_signal_Fwd[c][ipt]->SetParameter(2, fits_Fwd[c][ipt]->GetParameter(3));
                gaus2_signal_Fwd[c][ipt]->SetParameter(0, fits_Fwd[c][ipt]->GetParameter(0));
                gaus2_signal_Fwd[c][ipt]->SetParameter(1, fits_Fwd[c][ipt]->GetParameter(2));
                gaus2_signal_Fwd[c][ipt]->SetParameter(2, fits_Fwd[c][ipt]->GetParameter(4));
            } else {
                gaus2_signal_Fwd[c][ipt]->SetParameter(0, fits_Fwd[c][ipt]->GetParameter(0));
                gaus2_signal_Fwd[c][ipt]->SetParameter(1, fits_Fwd[c][ipt]->GetParameter(1));
                gaus2_signal_Fwd[c][ipt]->SetParameter(2, fits_Fwd[c][ipt]->GetParameter(3));
                gaus1_signal_Fwd[c][ipt]->SetParameter(0, fits_Fwd[c][ipt]->GetParameter(0));
                gaus1_signal_Fwd[c][ipt]->SetParameter(1, fits_Fwd[c][ipt]->GetParameter(2));
                gaus1_signal_Fwd[c][ipt]->SetParameter(2, fits_Fwd[c][ipt]->GetParameter(4));
            }

            gaus1_signal_Fwd[c][ipt]->SetLineColor(kBlue);
            gaus2_signal_Fwd[c][ipt]->SetLineColor(kRed);
            gaus1_signal_Fwd[c][ipt]->SetLineStyle(kDashDotted);
            gaus2_signal_Fwd[c][ipt]->SetLineStyle(kDashDotted);

        }
    }

    // Draw
	TLatex latexS;
	latexS.SetTextFont(43);
	latexS.SetTextSize(22);
	latexS.SetTextAlign(13);

    TCanvas * can = new TCanvas("c", "c", 800, 600);
    for ( int c = 0; c < 5; c++ ) {
        for ( int ipt = 0; ipt < 13; ipt++ ) {

            // Mid
            hMassMid[c][ipt]->Draw();
            fits_Mid[c][ipt]->Draw("same");
            func_signal_Mid[c][ipt]->Draw("same");
            gaus1_signal_Mid[c][ipt]->Draw("same");
            gaus2_signal_Mid[c][ipt]->Draw("same");
            func_bckgnd_Mid[c][ipt]->Draw("same");

            double S = func_signal_Mid[c][ipt]->Integral(signal_range.first, signal_range.second);
            double B = func_bckgnd_Mid[c][ipt]->Integral(signal_range.first, signal_range.second);
            double sig = S/sqrt(S+B);
			latexS.DrawLatexNDC(0.16, 0.9, Form("%i-%i%%", centBin[c]/2, centBin[c+1]/2 ));
			latexS.DrawLatexNDC(0.16, 0.8, Form("%.1f< p_{T} < %.1f GeV", pTbin[ipt], pTbin[ipt+1]));
			latexS.DrawLatexNDC(0.16, 0.7, Form("S/#sqrt{S+B} = %.2f", sig));

            can->SaveAs(Form("MVAPlotMid_%s_%i_%i.pdf", s.c_str(), c, ipt));

            // Fwd
            hMassFwd[c][ipt]->Draw();
            fits_Fwd[c][ipt]->Draw("same");
            func_signal_Fwd[c][ipt]->Draw("same");
            gaus1_signal_Fwd[c][ipt]->Draw("same");
            gaus2_signal_Fwd[c][ipt]->Draw("same");
            func_bckgnd_Fwd[c][ipt]->Draw("same");

            S = func_signal_Fwd[c][ipt]->Integral(signal_range.first, signal_range.second);
            B = func_bckgnd_Fwd[c][ipt]->Integral(signal_range.first, signal_range.second);
            sig = S/sqrt(S+B);
			latexS.DrawLatexNDC(0.16, 0.9, Form("%i-%i%%", centBin[c]/2, centBin[c+1]/2 ));
			latexS.DrawLatexNDC(0.16, 0.8, Form("%.1f< p_{T} < %.1f GeV", pTbin[ipt], pTbin[ipt+1]));
			latexS.DrawLatexNDC(0.16, 0.7, Form("S/#sqrt{S+B} = %.2f", sig));

            can->SaveAs(Form("MVAPlotFwd_%s_%i_%i.pdf", s.c_str(), c, ipt));
        }
    }
}
