

{
    TChain * mtr = new TChain("mtr");
    mtr->Add("../../PbPb2018/V0Performance/newTree8/LM3_rap1_*.root/mtr");

    TCanvas * c = new TCanvas();
    c->SetRightMargin(0.15);
    c->SetLogz();
    TH2D * hLM = new TH2D("hLM", "hLM;alpha;Q_{t}", 200, -1., 1., 300, 0., 0.3);
    TH2D * hLMFwd = new TH2D("hLMFwd", "hLMFwd;alpha;Q_{t}", 200, -1., 1., 300, 0., 0.3);

    mtr->Draw("v0qt:alpha>>hLM", "mass>1.1115 && mass<1.1200 && abs(rapidity)<1. && pt>1.8 && pt < 8.5 && Cent<160", "colz");
    hLM->SetTitle(";#alpha;Q_{t}");
    c->SaveAs("AP_Lm.pdf");
    c->SaveAs("AP_Lm.png");

    mtr->Draw("v0qt:alpha>>hLMFwd", "mass>1.1115 && mass<1.1200 && abs(rapidity)<2. && abs(rapidity)>1. && pt>1.8 && pt < 8.5 && Cent<160", "colz");
    hLMFwd->SetTitle(";#alpha;Q_{t}");
    c->SaveAs("AP_LmFwd.pdf");
    c->SaveAs("AP_LmFwd.png");

    TFile * f = new TFile("APLM.root", "recreate");
    hLM->Write("hAP");
    hLMFwd->Write("hAPFwd");
}
