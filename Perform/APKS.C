

{
    TChain * mtr = new TChain("mtr");
    mtr->Add("../../PbPb2018/V0Performance/newTree8/KS3_rap1_*.root/mtr");

    TCanvas * c = new TCanvas();
    c->SetRightMargin(0.15);
    c->SetLogz();
    TH2D * hLM = new TH2D("hLM", "hLM;alpha;Q_{t}", 200, -1., 1., 300, 0., 0.3);
    TH2D * hLMFwd = new TH2D("hLMFwd", "hLMFwd;alpha;Q_{t}", 200, -1., 1., 300, 0., 0.3);

    mtr->Draw("v0qt:alpha>>hLM", "mass>0.492 && mass<0.503 && abs(rapidity)<1. && pt>0.6 && pt<8.5 && Cent<160", "colz");
    c->SaveAs("AP_Ks.pdf");
    c->SaveAs("AP_Ks.png");


    mtr->Draw("v0qt:alpha>>hLMFwd", "mass>0.492 && mass<0.503 && abs(rapidity)<2. && abs(rapidity)>1. && pt>0.6 && pt<8.5 && Cent<160", "colz");
    c->SaveAs("AP_KsFwd.pdf");
    c->SaveAs("AP_KsFwd.png");


    TFile * f = new TFile("APKS.root", "recreate");
    hLM->Write("hAP");
    hLMFwd->Write("hAPFwd");
}
