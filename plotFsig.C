
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

void plotFsig(string fname = "FsigKSMid.root")
{
    bool bKs = (fname.find("LM") == std::string::npos);

    TFile * f = new TFile(fname.c_str());
    TH1D* hFsigMid0 = (TH1D*) f->Get("hFsigMid0");
    TH1D* hFsigMid1 = (TH1D*) f->Get("hFsigMid1");
    TH1D* hFsigMid2 = (TH1D*) f->Get("hFsigMid2");
    TH1D* hFsigMid3 = (TH1D*) f->Get("hFsigMid3");
    TH1D* hFsigMid4 = (TH1D*) f->Get("hFsigMid4");

    TGraph * gr0 = new TGraph(hFsigMid0);
    TGraph * gr1 = new TGraph(hFsigMid1);
    TGraph * gr2 = new TGraph(hFsigMid2);
    TGraph * gr3 = new TGraph(hFsigMid3);
    TGraph * gr4 = new TGraph(hFsigMid4);

    if ( bKs ) {
        FixKs(gr0);
        FixKs(gr1);
        FixKs(gr2);
        FixKs(gr3);
        FixKs(gr4);
    } else {
        FixLm(gr0);
        FixLm(gr1);
        FixLm(gr2);
        FixLm(gr3);
        FixLm(gr4);
    }

    gr0->SetMarkerStyle(kOpenCircle);
    gr1->SetMarkerStyle(kOpenCircle);
    gr2->SetMarkerStyle(kOpenCircle);
    gr3->SetMarkerStyle(kOpenCircle);
    gr4->SetMarkerStyle(kOpenCircle);

    gr0->SetMarkerColor(kBlack);
    gr1->SetMarkerColor(kRed);
    gr2->SetMarkerColor(kBlue);
    gr3->SetMarkerColor(kGreen);
    gr4->SetMarkerColor(kBlack);

    gr0->SetLineColor(kBlack);
    gr1->SetLineColor(kRed);
    gr2->SetLineColor(kBlue);
    gr3->SetLineColor(kGreen);
    gr4->SetLineColor(kBlack);

    TCanvas * c = new TCanvas("c", "c", 800, 600);
    TH2D* hframe = new TH2D("hframe", "hframe;p_{T};F_{sig}", 1, 0., 8.5, 1, 0.7, 1.0);

    hframe->Draw();
//    gr0->Draw("plsame");
    gr1->Draw("plsame");
    gr2->Draw("plsame");
    gr3->Draw("plsame");
    gr4->Draw("plsame");
    TLegend * leg = new TLegend(0.5, 0.15, 0.7, 0.4);
    leg->AddEntry(gr1, "5-10\%", "pl");
    leg->AddEntry(gr2, "10-30\%", "pl");
    leg->AddEntry(gr3, "30-50\%", "pl");
    leg->AddEntry(gr4, "50-80\%", "pl");
    leg->Draw();

    c->SaveAs( (fname + ".pdf").c_str() );
}
