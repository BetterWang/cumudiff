

{
    TChain * ch = new TChain("ch");
    ch->Add("../../PbPb2018/V0Performance/newTree5/LM3_rap1_*.root/mtr");

    TCanvas * c = new TCanvas();
    c->SetRightMargin(0.15);
    c->SetLogz();
    ch->Draw("v0qt:alpha>>hLM(200, -1., 1., 300, 0., 0.3)", "mass>1.1115 && mass<1.1200 && abs(rapidity)<1. && pt>1.8 && pt < 8.5 && Cent<160", "colz");
    hLM->SetTitle(";#alpha;Q_{t}");

    TFile * f = new TFile("APLM.root", "recreate");
    hLM->Write("hAP");
    c->SaveAs("AP_Lm.pdf");
    c->SaveAs("AP_Lm.png");
}
