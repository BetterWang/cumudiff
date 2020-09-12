
void plotSigCent(string s = "LM", int centS = 1)
{
    TFile * fSig3 = new TFile(Form("MCsignificanceCent/%s%i_Sig.root", s.c_str(), centS));

    TGraph * grSB3     = (TGraph*) fSig3->Get("grSB");
    TGraph * grSB3_pXY = (TGraph*) fSig3->Get("grSB_pTrkDCASigXY");
    TGraph * grSB3_nXY = (TGraph*) fSig3->Get("grSB_nTrkDCASigXY");
    TGraph * grSB3_pZ  = (TGraph*) fSig3->Get("grSB_pTrkDCASigZ");
    TGraph * grSB3_nZ  = (TGraph*) fSig3->Get("grSB_nTrkDCASigZ");
    TGraph * grSBR_pXY = (TGraph*) fSig3->Get("grSBR_pTrkDCASigXY");
    TGraph * grSBR_nXY = (TGraph*) fSig3->Get("grSBR_nTrkDCASigXY");
    TGraph * grSBR_pZ  = (TGraph*) fSig3->Get("grSBR_pTrkDCASigZ");
    TGraph * grSBR_nZ  = (TGraph*) fSig3->Get("grSBR_nTrkDCASigZ");
    TGraph * grSig     = (TGraph*) fSig3->Get("grSig");

    TCanvas * c = new TCanvas("c", "c", 800, 600);

    double l = s=="LM"?25:155;
    TH2D * hframe = new TH2D("hframe", "hframe;BDT;S/B", 1, 0, 0.55, 1, 0, l);
    hframe->Draw();

    grSB3->SetLineColor(kRed);

    grSB3->SetMarkerColor(kRed);

    grSB3->Draw("plsame");

    c->SaveAs( (s + to_string(centS) + "_sysSB.pdf").c_str() );

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

    c->SaveAs( (s + to_string(centS) + "_sysSBreweight.pdf").c_str() );

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
    c->SaveAs( (s + to_string(centS) + "_sysSBR.pdf").c_str() );

    c->SetGridx();
    TH1F *Graph_Graph01 = new TH1F("Graph_Graph01","Graph",100,0,0.55);
    if ( s == "KS" ) {
        if ( centS == 1 ) {
            Graph_Graph01->SetMinimum(800.);
            Graph_Graph01->SetMaximum(4600.);
        }
        if ( centS == 2 ) {
            Graph_Graph01->SetMinimum(3800.);
            Graph_Graph01->SetMaximum(8500.);
        }
        if ( centS == 3 ) {
            Graph_Graph01->SetMinimum(3200.);
            Graph_Graph01->SetMaximum(7000.);
        }
        if ( centS == 4 ) {
            Graph_Graph01->SetMinimum(200.);
            Graph_Graph01->SetMaximum(5000.);
        }
    } else {
        if ( centS == 1 ) {
            Graph_Graph01->SetMinimum(100.);
            Graph_Graph01->SetMaximum(1200.);
        }
        if ( centS == 2 ) {
            Graph_Graph01->SetMinimum(100.);
            Graph_Graph01->SetMaximum(2400.);
        }
        if ( centS == 3 ) {
            Graph_Graph01->SetMinimum(100.);
            Graph_Graph01->SetMaximum(1900.);
        }
        if ( centS == 4 ) {
            Graph_Graph01->SetMinimum(100.);
            Graph_Graph01->SetMaximum(1200.);
        }
    }
    Graph_Graph01->SetDirectory(0);
    Graph_Graph01->SetStats(0);
    Graph_Graph01->SetTitle(";BDT;S/#sqrt{S+B}");
    Graph_Graph01->Draw();

    grSig->Draw("plsame");
    c->SaveAs( (s + to_string(centS) + "_Sig.pdf").c_str() );
    c->SaveAs( (s + to_string(centS) + "_Sig.png").c_str() );
}
