

{
    TChain * mtr = new TChain("mtr");
    mtr->Add("../../PbPb2018/V0Performance/newTree5/KS3_rap1_*.root/mtr");

    TCanvas * c = new TCanvas();
    c->SetRightMargin(0.15);
    c->SetLogz();
    mtr->Draw("v0qt:alpha>>hLM(200, -1., 1., 300, 0., 0.3)", "mass>0.492 && mass<0.503 && abs(rapidity)<1. && pt>0.6 && pt<8.5 && Cent<160", "colz");
    hLM->SetTitle(";#alpha;Q_{t}");

    TFile * f = new TFile("APKS.root", "recreate");
    hLM->Write("hAP");
    c->SaveAs("AP_Ks.pdf");
    c->SaveAs("AP_Ks.png");
}
