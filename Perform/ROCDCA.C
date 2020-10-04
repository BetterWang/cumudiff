
{
    TFile * f = new TFile("fsave.root");

    TH1D * mvaS = (TH1D*) f->Get("mvaS");
    TH1D * mvaB = (TH1D*) f->Get("mvaB");

    TH1D * mvaSDCA20 = (TH1D*) f->Get("mvaSDCA20");
    TH1D * mvaBDCA20 = (TH1D*) f->Get("mvaBDCA20");

    TH1D * mvaSDCA40 = (TH1D*) f->Get("mvaSDCA40");
    TH1D * mvaBDCA40 = (TH1D*) f->Get("mvaBDCA40");

    TMVA::ROCCalc roc(mvaS, mvaB);
//    TMVA::ROCCalc roc20(mvaSDCA20, mvaBDCA20);
//    TMVA::ROCCalc roc40(mvaSDCA40, mvaBDCA40);
//
//    TH1D* rocc = roc.GetROC();
//    TH1D* rocc20 = roc20.GetROC();
//    TH1D* rocc40 = roc40.GetROC();
//
//    rocc20->SetLineColor(kRed);
//    rocc40->SetLineColor(kBlue);
//    rocc->Draw("c");
//    rocc20->Draw("csame");
//    rocc40->Draw("csame");

    TH1 * cumuS = TMVA::gTools().GetCumulativeDist(mvaS);
    TH1 * cumuB = TMVA::gTools().GetCumulativeDist(mvaB);

    double BDTcut0 = 0.15;
    double BDTcut1 = 0.10;
    double BDTcut2 = 0.20;

    double eff0= cumuS->GetBinContent( cumuS->FindBin(BDTcut0) );
    double rej0= cumuB->GetBinContent( cumuB->FindBin(BDTcut0) );
    double eff1= cumuS->GetBinContent( cumuS->FindBin(BDTcut1) );
    double rej1= cumuB->GetBinContent( cumuB->FindBin(BDTcut1) );
    double eff2= cumuS->GetBinContent( cumuS->FindBin(BDTcut2) );
    double rej2= cumuB->GetBinContent( cumuB->FindBin(BDTcut2) );

    TMarker * mk0 = new TMarker(eff0, 1. - rej0, kOpenCircle);
    TMarker * mk1 = new TMarker(eff1, 1. - rej1, kOpenCircle);
    TMarker * mk2 = new TMarker(eff2, 1. - rej2, kOpenCircle);
    TH1D* rocc = roc.GetROC();
    rocc->Draw("c");
    mk0->Draw();
    mk1->Draw();
    mk2->Draw();
}
