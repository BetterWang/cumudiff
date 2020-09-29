
void plotMCsignificanceT(string fin = "", string fout = "")
{
    TH1D * hSignificance = new TH1D("hSignificance", "hSignificance", 200, -1., 1.);
    TH1D * hS = new TH1D("hS", "hS", 200, -1., 1.);
    TH1D * hB = new TH1D("hB", "hB", 200, -1., 1.);
    TH1D * hSB= new TH1D("hSB","hSB",200, -1., 1.);

    double massLow = 1.1115;
    double massHigh= 1.2;
    if ( fin.find("KS") != string::npos ) {
        massLow = 0.492;
        massHigh= 0.503;
    }

    TFile f(fin.c_str());
    for ( int i = 0; i < 200; i++ ) {
        TH1D * hs = (TH1D*) f.Get(Form("hmass_Signal_%i", i));
        TH1D * hb = (TH1D*) f.Get(Form("hmass_Bckgnd_%i", i));

        double S = hs->Integral(hs->FindBin(massLow), hs->FindBin(massHigh)); // hs->GetBinWidth(1);
        double B = hb->Integral(hb->FindBin(massLow), hb->FindBin(massHigh)); // hb->GetBinWidth(1);

        hS->SetBinContent(i+1, S);
        hB->SetBinContent(i+1, B);
        double sig = S/sqrt(S+B);
        hSignificance->SetBinContent(i+1, TMath::IsNaN(sig)?0:sig);

        hSB->SetBinContent(i+1, (TMath::IsNaN(S/B) or (S/B == TMath::Infinity()))?0:S/B);

        delete hs;
        delete hb;
    }

    TFile * fsave = new TFile( fout.c_str(), "recreate" );
    hSignificance->Write();
    hS->Write();
    hB->Write();
    hSB->Write();
}
