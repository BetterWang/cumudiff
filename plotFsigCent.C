
void FixLm(TGraph * gr)
{
    gr->RemovePoint(0);
    gr->RemovePoint(0);
    gr->RemovePoint(0);
    gr->RemovePoint(0);
    gr->RemovePoint(0);
    gr->RemovePoint(0);
}
void FixKs(TGraph * gr)
{
    gr->RemovePoint(0);
    gr->RemovePoint(0);
    gr->RemovePoint(0);
    gr->RemovePoint(0);
}

void plotFsigCent(string s = "LM")
{
    bool bKs = (s == "KS");

    TFile * f7 = new TFile((string("Fsig") + s + "Mid_cent7.root").c_str());
    TFile * fS = new TFile((string("Fsig") + s + "Mid_centS.root").c_str());

    TH1D* hFsig7Mid1 = (TH1D*) f7->Get("hFsigMid1");
    TH1D* hFsig7Mid2 = (TH1D*) f7->Get("hFsigMid2");
    TH1D* hFsig7Mid3 = (TH1D*) f7->Get("hFsigMid3");
    TH1D* hFsig7Mid4 = (TH1D*) f7->Get("hFsigMid4");

    TH1D* hFsigSMid1 = (TH1D*) fS->Get("hFsigMid1");
    TH1D* hFsigSMid2 = (TH1D*) fS->Get("hFsigMid2");
    TH1D* hFsigSMid3 = (TH1D*) fS->Get("hFsigMid3");
    TH1D* hFsigSMid4 = (TH1D*) fS->Get("hFsigMid4");

    TGraph * gr71 = new TGraph(hFsig7Mid1);
    TGraph * gr72 = new TGraph(hFsig7Mid2);
    TGraph * gr73 = new TGraph(hFsig7Mid3);
    TGraph * gr74 = new TGraph(hFsig7Mid4);

    TGraph * grS1 = new TGraph(hFsigSMid1);
    TGraph * grS2 = new TGraph(hFsigSMid2);
    TGraph * grS3 = new TGraph(hFsigSMid3);
    TGraph * grS4 = new TGraph(hFsigSMid4);

    if ( bKs ) {
        FixKs(gr71);
        FixKs(gr72);
        FixKs(gr73);
        FixKs(gr74);
        FixKs(grS1);
        FixKs(grS2);
        FixKs(grS3);
        FixKs(grS4);
    } else {
        FixLm(gr71);
        FixLm(gr72);
        FixLm(gr73);
        FixLm(gr74);
        FixLm(grS1);
        FixLm(grS2);
        FixLm(grS3);
        FixLm(grS4);
    }

    gr71->SetMarkerStyle(kOpenCircle);
    gr72->SetMarkerStyle(kOpenCircle);
    gr73->SetMarkerStyle(kOpenCircle);
    gr74->SetMarkerStyle(kOpenCircle);

    gr71->SetMarkerColor(kRed);
    gr72->SetMarkerColor(kBlue);
    gr73->SetMarkerColor(kGreen);
    gr74->SetMarkerColor(kBlack);

    gr71->SetLineColor(kRed);
    gr72->SetLineColor(kBlue);
    gr73->SetLineColor(kGreen);
    gr74->SetLineColor(kBlack);

    grS1->SetMarkerStyle(kOpenSquare);
    grS2->SetMarkerStyle(kOpenSquare);
    grS3->SetMarkerStyle(kOpenSquare);
    grS4->SetMarkerStyle(kOpenSquare);

    grS1->SetMarkerColor(kRed);
    grS2->SetMarkerColor(kBlue);
    grS3->SetMarkerColor(kGreen);
    grS4->SetMarkerColor(kBlack);

    grS1->SetLineColor(kRed);
    grS2->SetLineColor(kBlue);
    grS3->SetLineColor(kGreen);
    grS4->SetLineColor(kBlack);

    grS1->SetLineStyle(kDashed);
    grS2->SetLineStyle(kDashed);
    grS3->SetLineStyle(kDashed);
    grS4->SetLineStyle(kDashed);

    TCanvas * c = new TCanvas("c", "c", 800, 600);
    TH2D* hframe = new TH2D("hframe", "hframe;p_{T};F_{sig}", 1, 0., 8.5, 1, 0.7, 1.0);

    hframe->Draw();
    gr71->Draw("plsame");
    gr72->Draw("plsame");
    gr73->Draw("plsame");
    gr74->Draw("plsame");

    grS1->Draw("plsame");
    grS2->Draw("plsame");
    grS3->Draw("plsame");
    grS4->Draw("plsame");

    TLegend * leg = new TLegend(0.3, 0.15, 0.5, 0.4);
    leg->SetHeader("Standard");
    leg->AddEntry(gr71, "5-10\%", "pl");
    leg->AddEntry(gr72, "10-30\%", "pl");
    leg->AddEntry(gr73, "30-50\%", "pl");
    leg->AddEntry(gr74, "50-80\%", "pl");
    leg->Draw();

    TLegend * legS = new TLegend(0.5, 0.15, 0.7, 0.4);
    legS->SetHeader("MVA Centrality");
    legS->AddEntry(grS1, "5-10\%", "pl");
    legS->AddEntry(grS2, "10-30\%", "pl");
    legS->AddEntry(grS3, "30-50\%", "pl");
    legS->AddEntry(grS4, "50-80\%", "pl");
    legS->Draw();

    c->SaveAs( (s + "_Fsig.pdf").c_str() );
}
