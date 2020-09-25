
void getMVASB( string tr, string fout )
{
    TChain * trV = new TChain("trV", "trV");
    trV->Add(tr.c_str());

    TH1D * mvaS = new TH1D("mvaS", "mvaS", 200, -1., 1.);
    TH1D * mvaB = new TH1D("mvaB", "mvaB", 200, -1., 1.);

    TH1D * mvaS_s1 = new TH1D("mvaS_s1", "mvaS_s1", 200, -1., 1.);
    TH1D * mvaB_s1 = new TH1D("mvaB_s1", "mvaB_s1", 200, -1., 1.);
    TH1D * mvaS_s2 = new TH1D("mvaS_s2", "mvaS_s2", 200, -1., 1.);
    TH1D * mvaB_s2 = new TH1D("mvaB_s2", "mvaB_s2", 200, -1., 1.);
    TH1D * mvaS_s3 = new TH1D("mvaS_s3", "mvaS_s3", 200, -1., 1.);
    TH1D * mvaB_s3 = new TH1D("mvaB_s3", "mvaB_s3", 200, -1., 1.);
    TH1D * mvaS_s4 = new TH1D("mvaS_s4", "mvaS_s4", 200, -1., 1.);
    TH1D * mvaB_s4 = new TH1D("mvaB_s4", "mvaB_s4", 200, -1., 1.);

    TCut bSig = "classID==0";
    TCut bBkg = "classID==1";
    TCut CentBin1 = "(Cent>=10) && (Cent<20)";
    TCut CentBin2 = "(Cent>=20) && (Cent<60)";
    TCut CentBin3 = "(Cent>=60) && (Cent<100)";
    TCut CentBin4 = "(Cent>=100) && (Cent<160)";
    TCut bMid = "(rapidity>-1.0) &&(rapidity<1.0)";

    trV->Draw("BDT250_D4>>mvaS", bSig && bMid, "goff");
    trV->Draw("BDT250_D4>>mvaB", bBkg && bMid, "goff");

    trV->Draw("BDT250_D4>>mvaS_s1", bSig && bMid && CentBin1, "goff");
    trV->Draw("BDT250_D4>>mvaS_s2", bSig && bMid && CentBin2, "goff");
    trV->Draw("BDT250_D4>>mvaS_s3", bSig && bMid && CentBin3, "goff");
    trV->Draw("BDT250_D4>>mvaS_s4", bSig && bMid && CentBin4, "goff");

    trV->Draw("BDT250_D4>>mvaB_s1", bBkg && bMid && CentBin1, "goff");
    trV->Draw("BDT250_D4>>mvaB_s2", bBkg && bMid && CentBin2, "goff");
    trV->Draw("BDT250_D4>>mvaB_s3", bBkg && bMid && CentBin3, "goff");
    trV->Draw("BDT250_D4>>mvaB_s4", bBkg && bMid && CentBin4, "goff");

    TFile * fsave = new TFile(fout.c_str(), "recreate");
    mvaS->Write();
    mvaB->Write();
    mvaS_s1->Write();
    mvaS_s2->Write();
    mvaS_s3->Write();
    mvaS_s4->Write();
    mvaB_s1->Write();
    mvaB_s2->Write();
    mvaB_s3->Write();
    mvaB_s4->Write();

    TMVA::ROCCalc roc(mvaS, mvaB);
    TMVA::ROCCalc roc_s1(mvaS_s1, mvaB_s1);
    TMVA::ROCCalc roc_s2(mvaS_s2, mvaB_s2);
    TMVA::ROCCalc roc_s3(mvaS_s3, mvaB_s3);
    TMVA::ROCCalc roc_s4(mvaS_s4, mvaB_s4);

    TH1D * hROC    = roc.GetROC();
    TH1D * hROC_s1 = roc_s1.GetROC();
    TH1D * hROC_s2 = roc_s2.GetROC();
    TH1D * hROC_s3 = roc_s3.GetROC();
    TH1D * hROC_s4 = roc_s4.GetROC();

    hROC   ->Write("hROC");
    hROC_s1->Write("hROC_s1");
    hROC_s2->Write("hROC_s2");
    hROC_s3->Write("hROC_s3");
    hROC_s4->Write("hROC_s4");

}
