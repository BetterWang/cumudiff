
void plotSig2(TString prefix = "MCsignificanceTCent/SigKSC_", TString fout = "", TString option = "C")
{
    TString centBin[4] = {"05_10", "10_30", "30_50", "50_80"};
    TString ptBin[9] = {"10_14", "14_18", "18_22", "22_28", "28_36", "36_46", "46_60", "60_70", "70_85"};
    double pt[9] = {1.2, 1.6, 2.0, 2.5, 3.2, 4.1, 5.3, 6.5, 7.75};

    bool isLM = prefix.Contains("LM");

    int pTstart = 0;
    if ( isLM ) pTstart = 2;

    TGraph * grBDTcut[4];
    TFile * fsave = new TFile( fout.Data(), "recreate" );
    auto dirSig = fsave->mkdir("Sig");
    auto dirSigC= fsave->mkdir("SigC");

    for ( int c = 0; c < 4; c++ ) {
        grBDTcut[c] = new TGraph(9-pTstart);
        for ( int ipt = pTstart; ipt < 9; ipt++ ) {
            TFile f( (prefix + centBin[c] + "_" + ptBin[ipt] + ".root").Data() );
            TH1D * hSig  = (TH1D*) f.Get("hSignificance");
            TH1D * hSigC = (TH1D*) f.Get("hSignificanceC");
            dirSig->cd();
            hSig->SetTitle(";BDT;S/#sqrt{S+B}");
            hSig->Write( (TString("hSignificance_") + centBin[c] + "_" + ptBin[ipt]).Data() );
            dirSigC->cd();
            hSigC->SetTitle(";BDT;S/#sqrt{S+B}");
            hSigC->Write( (TString("hSignificanceC_") + centBin[c] + "_" + ptBin[ipt]).Data() );

            hSig->Smooth();
            double bin = hSig->GetMaximumBin();
            grBDTcut[c]->GetX()[ipt-pTstart] = pt[ipt];
            grBDTcut[c]->GetY()[ipt-pTstart] = bin/100. - 1;
        }
        fsave->cd();
        grBDTcut[c]->SetTitle(";p_{T};BDT");
        grBDTcut[c]->Write( (TString("grBDTcut_")+centBin[c]).Data() );
    }
}
