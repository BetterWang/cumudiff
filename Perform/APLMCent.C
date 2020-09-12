

{
    TChain * mtr = new TChain("mtr");
    mtr->Add("../../PbPb2018/V0Performance/newTreeCent/LM3cent_*.root/mtr");

    TCanvas * c = new TCanvas();
    c->SetRightMargin(0.15);
    c->SetLogz();
    TH2D * hLM1    = new TH2D("hLM1",    "hLM1;alpha;Q_{t}",    200, -1., 1., 300, 0., 0.3);
    TH2D * hLM1Fwd = new TH2D("hLM1Fwd", "hLM1Fwd;alpha;Q_{t}", 200, -1., 1., 300, 0., 0.3);
    TH2D * hLM2    = new TH2D("hLM2",    "hLM2;alpha;Q_{t}",    200, -1., 1., 300, 0., 0.3);
    TH2D * hLM2Fwd = new TH2D("hLM2Fwd", "hLM2Fwd;alpha;Q_{t}", 200, -1., 1., 300, 0., 0.3);
    TH2D * hLM3    = new TH2D("hLM3",    "hLM3;alpha;Q_{t}",    200, -1., 1., 300, 0., 0.3);
    TH2D * hLM3Fwd = new TH2D("hLM3Fwd", "hLM3Fwd;alpha;Q_{t}", 200, -1., 1., 300, 0., 0.3);
    TH2D * hLM4    = new TH2D("hLM4",    "hLM4;alpha;Q_{t}",    200, -1., 1., 300, 0., 0.3);
    TH2D * hLM4Fwd = new TH2D("hLM4Fwd", "hLM4Fwd;alpha;Q_{t}", 200, -1., 1., 300, 0., 0.3);

    mtr->Draw("v0qt:alpha>>hLM1", "mass>1.1115 && mass<1.1200 && abs(rapidity)<1. && pt>1.8 && pt < 8.5 && Cent>=10 && Cent<20", "colz");
    hLM1->SetTitle(";#alpha;Q_{t}");
    c->SaveAs("AP_Lm1.pdf");
    c->SaveAs("AP_Lm1.png");

    mtr->Draw("v0qt:alpha>>hLM2", "mass>1.1115 && mass<1.1200 && abs(rapidity)<1. && pt>1.8 && pt < 8.5 && Cent>=20 && Cent<60", "colz");
    hLM2->SetTitle(";#alpha;Q_{t}");
    c->SaveAs("AP_Lm2.pdf");
    c->SaveAs("AP_Lm2.png");

    mtr->Draw("v0qt:alpha>>hLM3", "mass>1.1115 && mass<1.1200 && abs(rapidity)<1. && pt>1.8 && pt < 8.5 && Cent>=60 && Cent<100", "colz");
    hLM3->SetTitle(";#alpha;Q_{t}");
    c->SaveAs("AP_Lm3.pdf");
    c->SaveAs("AP_Lm3.png");

    mtr->Draw("v0qt:alpha>>hLM4", "mass>1.1115 && mass<1.1200 && abs(rapidity)<1. && pt>1.8 && pt < 8.5 && Cent>=100 && Cent<160", "colz");
    hLM4->SetTitle(";#alpha;Q_{t}");
    c->SaveAs("AP_Lm4.pdf");
    c->SaveAs("AP_Lm4.png");

    mtr->Draw("v0qt:alpha>>hLM1Fwd", "mass>1.1115 && mass<1.1200 && abs(rapidity)<2. && abs(rapidity)>1. && pt>1.8 && pt < 8.5 && Cent>=10 && Cent<20", "colz");
    hLM1Fwd->SetTitle(";#alpha;Q_{t}");
    c->SaveAs("AP_Lm1Fwd.pdf");
    c->SaveAs("AP_Lm1Fwd.png");

    mtr->Draw("v0qt:alpha>>hLM2Fwd", "mass>1.1115 && mass<1.1200 && abs(rapidity)<2. && abs(rapidity)>1. && pt>1.8 && pt < 8.5 && Cent>=20 && Cent<60", "colz");
    hLM2Fwd->SetTitle(";#alpha;Q_{t}");
    c->SaveAs("AP_Lm2Fwd.pdf");
    c->SaveAs("AP_Lm2Fwd.png");

    mtr->Draw("v0qt:alpha>>hLM3Fwd", "mass>1.1115 && mass<1.1200 && abs(rapidity)<2. && abs(rapidity)>1. && pt>1.8 && pt < 8.5 && Cent>=60 && Cent<100", "colz");
    hLM3Fwd->SetTitle(";#alpha;Q_{t}");
    c->SaveAs("AP_Lm3Fwd.pdf");
    c->SaveAs("AP_Lm3Fwd.png");

    mtr->Draw("v0qt:alpha>>hLM4Fwd", "mass>1.1115 && mass<1.1200 && abs(rapidity)<2. && abs(rapidity)>1. && pt>1.8 && pt < 8.5 && Cent>=100 && Cent<160", "colz");
    hLM4Fwd->SetTitle(";#alpha;Q_{t}");
    c->SaveAs("AP_Lm4Fwd.pdf");
    c->SaveAs("AP_Lm4Fwd.png");

    TFile * f = new TFile("APLMCent.root", "recreate");
    hLM1   ->Write("hAP1");
    hLM1Fwd->Write("hAP1Fwd");
    hLM2   ->Write("hAP2");
    hLM2Fwd->Write("hAP2Fwd");
    hLM3   ->Write("hAP3");
    hLM3Fwd->Write("hAP3Fwd");
    hLM4   ->Write("hAP4");
    hLM4Fwd->Write("hAP4Fwd");
}
