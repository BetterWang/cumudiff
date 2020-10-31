
void plotSpetra(string s = "LM")
{
    TFile * fMC   = new TFile(Form("spectraMC_%s.root", s.c_str()));
    TFile * fData = new TFile(Form("spectraData_%s.root", s.c_str()));

    TH1D * hMC[5] = {};
    TH1D * hData[5] = {};

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
    for ( int c = 1; c < 5; c++ ) {
        hMC[c]->SetTitle(";p_{T};[AU]");
        hMC[c]->Draw("hist");
        hData[c]->Draw("histsame");
        c1->SaveAs(Form("spectra%s_%i.pdf", s.c_str(), c));
    }
}
