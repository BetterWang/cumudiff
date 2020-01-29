
void plotSig(string s = "LM")
{
    TFile * fSig3 = new TFile(Form("MCsignificance/%s_Sig.root", s.c_str()));
    TFile * fSig8 = new TFile(Form("MCsignificance8/%s8_Sig.root", s.c_str()));

    TGraph * grSB3     = (TGraph*) fSig3->Get("grSB");
    TGraph * grSB3_pXY = (TGraph*) fSig3->Get("grSB_pTrkDCASigXY");
    TGraph * grSB3_nXY = (TGraph*) fSig3->Get("grSB_nTrkDCASigXY");
    TGraph * grSB3_pZ  = (TGraph*) fSig3->Get("grSB_pTrkDCASigZ");
    TGraph * grSB3_nZ  = (TGraph*) fSig3->Get("grSB_nTrkDCASigZ");
    TGraph * grSBR_pXY = (TGraph*) fSig3->Get("grSBR_pTrkDCASigXY");
    TGraph * grSBR_nXY = (TGraph*) fSig3->Get("grSBR_nTrkDCASigXY");
    TGraph * grSBR_pZ  = (TGraph*) fSig3->Get("grSBR_pTrkDCASigZ");
    TGraph * grSBR_nZ  = (TGraph*) fSig3->Get("grSBR_nTrkDCASigZ");
    TGraph * grSB8     = (TGraph*) fSig8->Get("grSB");

    TGraph * grSig     = (TGraph*) fSig3->Get("grSig");

    TCanvas * c = new TCanvas("c", "c", 800, 600);

    double l = s=="LM"?25:155;
    TH2D * hframe = new TH2D("hframe", "hframe;BDT;S/B", 1, 0, 0.55, 1, 0, l);
    hframe->Draw();

    grSB3->SetLineColor(kRed);
    grSB8->SetLineColor(kBlue);

    grSB3->SetMarkerColor(kRed);
    grSB8->SetMarkerColor(kBlue);

    grSB3->Draw("plsame");
    grSB8->Draw("plsame");

    c->SaveAs( (s + "_sysSB.pdf").c_str() );

    hframe->Draw();
    grSB3->Draw("plsame");

    grSB3_pXY->SetLineColor(kBlue);
    grSB3_nXY->SetLineColor(kGreen);
    grSB3_pZ ->SetLineColor(kCyan);
    grSB3_nZ ->SetLineColor(kBlack);

    grSB3_pXY->SetMarkerColor(kBlue);
    grSB3_nXY->SetMarkerColor(kGreen);
    grSB3_pZ ->SetMarkerColor(kCyan);
    grSB3_nZ ->SetMarkerColor(kBlack);

    grSB3_pXY->Draw("plsame");
    grSB3_nXY->Draw("plsame");
    grSB3_pZ ->Draw("plsame");
    grSB3_nZ ->Draw("plsame");

    c->SaveAs( (s + "_sysSBreweight.pdf").c_str() );

    TH2D * hframeR = new TH2D("hframeR", "hframeR;BDT;S/B Ratio", 1, 0, 0.55, 1, 0, 2.);
    hframeR->Draw();
    grSBR_pXY->SetLineColor(kBlue);
    grSBR_nXY->SetLineColor(kGreen);
    grSBR_pZ ->SetLineColor(kCyan);
    grSBR_nZ ->SetLineColor(kBlack);

    grSBR_pXY->SetMarkerColor(kBlue);
    grSBR_nXY->SetMarkerColor(kGreen);
    grSBR_pZ ->SetMarkerColor(kCyan);
    grSBR_nZ ->SetMarkerColor(kBlack);

    grSBR_pXY->Draw("plsame");
    grSBR_nXY->Draw("plsame");
    grSBR_pZ ->Draw("plsame");
    grSBR_nZ ->Draw("plsame");

    c->SetGridy();
    c->SaveAs( (s + "_sysSBR.pdf").c_str() );

    c->SetGridx();
    TH1F *Graph_Graph01 = new TH1F("Graph_Graph01","Graph",100,0,0.55);
    Graph_Graph01->SetMinimum(0.);
    if ( s == "KS" ) {
        Graph_Graph01->SetMinimum(120.);
        Graph_Graph01->SetMaximum(300.);
    } else {
        Graph_Graph01->SetMaximum(70.);
    }
    Graph_Graph01->SetDirectory(0);
    Graph_Graph01->SetStats(0);
    Graph_Graph01->SetTitle(";BDT;S/#sqrt{S+B}");
    Graph_Graph01->Draw();

    grSig->Draw("plsame");
    c->SaveAs( (s + "_Sig.pdf").c_str() );
    c->SaveAs( (s + "_Sig.png").c_str() );
}
