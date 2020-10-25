
void plotDATAsignificanceT(string fin="", string fout="", string fMC="", string fWS="", string WSbdt = "BDT_MCfull4")
{
    TFile * ffin = new TFile(fin.c_str());
    TH1D * hS = (TH1D*)ffin->Get("hS");
    TH1D * hB = (TH1D*)ffin->Get("hB");

    TFile * ffMC = new TFile(fMC.c_str());
    TH1D * hMCS = (TH1D*)ffMC->Get("hS");
    double dbMCS = hMCS->GetBinContent(1);

    double massLow = 1.1115;
    double massHigh= 1.2;
    if ( fin.find("KS") != string::npos ) {
        massLow = 0.492;
        massHigh= 0.503;
    }

    TFile * ffWS = new TFile(fWS.c_str());
    TH1D * hWCB = (TH1D*)ffWS->Get((WSbdt+ "/hMass" + WSbdt + "_0").c_str());
    int binLow = hWCB->FindBin(massLow);
    int binHigh= hWCB->FindBin(massHigh);
    double tot = hWCB->Integral(binLow, binHigh);

    TH1D * hSignificance = new TH1D("hSignificance", "hSignificance", 200, -1., 1.);
    TH1D * hSignificanceC= new TH1D("hSignificanceC", "hSignificanceC", 200, -1., 1.);

    for ( int i = 0; i < 200; i++ ) {
        double S = hS->GetBinContent(i+1);
        double B = hB->GetBinContent(i+1);
        double sig = S/sqrt(S+B);
        hSignificance->SetBinContent(i+1, TMath::IsNaN(sig)?0:sig);

        double S0 = hS->GetBinContent(1);
        double Bx = hS->GetBinContent(1);
        double Seff = hMCS->GetBinContent(i+1)/dbMCS;
        TH1D * h = (TH1D*)ffWS->Get(Form("%s/hMass%s_%i", WSbdt.c_str(), WSbdt.c_str(), i));
        double Beff = h->Integral(binLow, binHigh) / tot;
        S = S0*Seff;
        B = Bx*Beff;
        sig = S/sqrt(S+B);
        hSignificanceC->SetBinContent(i+1, TMath::IsNaN(sig)?0:sig);
        delete h;
    }

    TFile * fsave = new TFile(fout.c_str(), "recreate");
    hSignificance->Write();
    hSignificanceC->Write();
}
