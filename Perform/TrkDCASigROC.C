
//void TrkDCASigROC()
{
    TFile * f = new TFile("TMVA3_HydjetMCTruth_MCBkg_LM.root");
    TTree * tr = (TTree*) f->Get("dataset3_full_LM/TestTree");
    TH1D * mvaS = new TH1D("mvaS", "mvaS", 200, -1., 1.);
    TH1D * mvaB = new TH1D("mvaB", "mvaB", 200, -1., 1.);

    TH1D * mvaSDCA20 = new TH1D("mvaSDCA20", "mvaSDCA20", 200, -1., 1.);
    TH1D * mvaBDCA20 = new TH1D("mvaBDCA20", "mvaBDCA20", 200, -1., 1.);

    TH1D * mvaSDCA40 = new TH1D("mvaSDCA40", "mvaSDCA40", 200, -1., 1.);
    TH1D * mvaBDCA40 = new TH1D("mvaBDCA40", "mvaBDCA40", 200, -1., 1.);

    tr->Draw("BDT250_D4>>mvaS", "classID==0", "goff");
    tr->Draw("BDT250_D4>>mvaB", "classID==1", "goff");

    tr->Draw("BDT250_D4>>mvaSDCA20", "classID==0 && pTrkDCASigXY<20 && pTrkDCASigZ<20 && nTrkDCASigXY<20 && nTrkDCASigZ<20", "goff");
    tr->Draw("BDT250_D4>>mvaBDCA20", "classID==1 && pTrkDCASigXY<20 && pTrkDCASigZ<20 && nTrkDCASigXY<20 && nTrkDCASigZ<20", "goff");

    tr->Draw("BDT250_D4>>mvaSDCA40", "classID==0 && pTrkDCASigXY<40 && pTrkDCASigZ<40 && nTrkDCASigXY<40 && nTrkDCASigZ<40", "goff");
    tr->Draw("BDT250_D4>>mvaBDCA40", "classID==1 && pTrkDCASigXY<40 && pTrkDCASigZ<40 && nTrkDCASigXY<40 && nTrkDCASigZ<40", "goff");

    TFile * fsave = new TFile("fsave.root", "create");
    mvaS->Write();
    mvaB->Write();
    mvaSDCA20->Write();
    mvaBDCA20->Write();
    mvaSDCA40->Write();
    mvaBDCA40->Write();
}
