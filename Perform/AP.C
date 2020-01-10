

{
    TChain * ch = new TChain("ch");
    ch->Add("../../PbPb2018/V0Performance/newTree4/LM3_rap1_*.root/mtr");

    TCanvas * c = new TCanvas();
    c->SetRightMargin(0.15);
    ch->Draw("v0qt:alpha>>hLM(200, -1., 1., 400, 0., 0.4)", "mass>1.1115 && mass<1.1200 && abs(rapidity)<1.", "colz");

    TFile * f = new TFile("APLM.root", "recreate");
    hLM->Write("hAP");
}
