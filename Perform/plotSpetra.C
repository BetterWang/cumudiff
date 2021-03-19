
void plotSpetra(string s = "LM")
{
    TFile * fMC   = new TFile(Form("spectraMC_%s.root", s.c_str()));
    TFile * fData = new TFile(Form("spectraData_%s.root", s.c_str()));

    TH1D * hMC[5] = {};
    TH1D * hData[5] = {};

    string part = "#Lambda ";

    if (s != "LM") {
        part = "K_{S}^{0} ";
    }

    string strCent[5] = {
        "0-5\%",
        "5-10\%",
        "10-30\%",
        "30-50\%",
        "50-80\%",
    };
    TLatex latexS;
    latexS.SetTextFont(43);
    latexS.SetTextSize(28);
    latexS.SetTextAlign(13);

    for ( int c = 1; c < 5; c++ ) {
        hMC[c] = (TH1D*) fMC->Get(Form("hSpect_%i", c));
        hData[c] = (TH1D*) fData->Get(Form("hSpectMCfull4_%i", c));
        hMC[c]->Scale(1./hMC[c]->Integral());
        hData[c]->Scale(1./hData[c]->Integral());
        hMC[c]->SetLineColor(kRed);
        hData[c]->SetLineColor(kBlue);
    }

    TCanvas * c1 = new TCanvas("c1", "c1");
    c1->SetLogy();

    TLegend * legPA = new TLegend(0.62, 0.72, 0.85 , 0.83);
    legPA->SetFillColor(kWhite);
    legPA->SetTextFont(42);
    legPA->SetTextSize(0.05);
    legPA->SetBorderSize(0);

    legPA->AddEntry(hMC[1], "MC", "l");
    legPA->AddEntry(hData[1], "Data", "l");

    for ( int c = 1; c < 5; c++ ) {
        hMC[c]->SetTitle(";p_{T};[AU]");
        hMC[c]->Draw("hist");
        hData[c]->Draw("histsame");
        latexS.DrawLatexNDC(0.63, 0.94, (part+strCent[c]).c_str());
        legPA->Draw();
        c1->SaveAs(Form("spectra%s_%i.pdf", s.c_str(), c));
    }
}
