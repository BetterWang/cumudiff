

typedef struct
{
    TH1D * hpt            ;
    TH1D * hrapidity      ;
    TH1D * hvtxChi2       ;
    TH1D * hcosThetaXYZ   ;
    TH1D * hLxyz          ;
    TH1D * hvtxDecaySigXYZ;
    TH1D * hDCA           ;
    TH1D * hpTrkNHit      ;
    TH1D * hnTrkNHit      ;
    TH1D * hpTrkPt        ;
    TH1D * hnTrkPt        ;
    TH1D * hpTrkEta       ;
    TH1D * hnTrkEta       ;
    TH1D * hpTrkNPxLayer  ;
    TH1D * hnTrkNPxLayer  ;
    TH1D * hpTrkDCASigXY  ;
    TH1D * hnTrkDCASigXY  ;
    TH1D * hpTrkDCASigZ   ;
    TH1D * hnTrkDCASigZ   ;

    void SetLineColor(int color) {
        hpt            ->SetLineColor(color);
        hrapidity      ->SetLineColor(color);
        hvtxChi2       ->SetLineColor(color);
        hcosThetaXYZ   ->SetLineColor(color);
        hLxyz          ->SetLineColor(color);
        hvtxDecaySigXYZ->SetLineColor(color);
        hDCA           ->SetLineColor(color);
        hpTrkNHit      ->SetLineColor(color);
        hnTrkNHit      ->SetLineColor(color);
        hpTrkPt        ->SetLineColor(color);
        hnTrkPt        ->SetLineColor(color);
        hpTrkEta       ->SetLineColor(color);
        hnTrkEta       ->SetLineColor(color);
        hpTrkNPxLayer  ->SetLineColor(color);
        hnTrkNPxLayer  ->SetLineColor(color);
        hpTrkDCASigXY  ->SetLineColor(color);
        hnTrkDCASigXY  ->SetLineColor(color);
        hpTrkDCASigZ   ->SetLineColor(color);
        hnTrkDCASigZ   ->SetLineColor(color);
    };

    void Scale(double s) {
        hpt            ->Scale(s);
        hrapidity      ->Scale(s);
        hvtxChi2       ->Scale(s);
        hcosThetaXYZ   ->Scale(s);
        hLxyz          ->Scale(s);
        hvtxDecaySigXYZ->Scale(s);
        hDCA           ->Scale(s);
        hpTrkNHit      ->Scale(s);
        hnTrkNHit      ->Scale(s);
        hpTrkPt        ->Scale(s);
        hnTrkPt        ->Scale(s);
        hpTrkEta       ->Scale(s);
        hnTrkEta       ->Scale(s);
        hpTrkNPxLayer  ->Scale(s);
        hnTrkNPxLayer  ->Scale(s);
        hpTrkDCASigXY  ->Scale(s);
        hnTrkDCASigXY  ->Scale(s);
        hpTrkDCASigZ   ->Scale(s);
        hnTrkDCASigZ   ->Scale(s);
    }

} hists;

hists getHist(TFile * f)
{
    hists H;

    H.hpt             = (TH1D*)f->Get("hpt");
    H.hrapidity       = (TH1D*)f->Get("hrapidity");
    H.hvtxChi2        = (TH1D*)f->Get("hvtxChi2");
    H.hcosThetaXYZ    = (TH1D*)f->Get("hcosThetaXYZ");
    H.hLxyz           = (TH1D*)f->Get("hLxyz");
    H.hvtxDecaySigXYZ = (TH1D*)f->Get("hvtxDecaySigXYZ");
    H.hDCA            = (TH1D*)f->Get("hDCA");
    H.hpTrkNHit       = (TH1D*)f->Get("hpTrkNHit");
    H.hnTrkNHit       = (TH1D*)f->Get("hnTrkNHit");
    H.hpTrkPt         = (TH1D*)f->Get("hpTrkPt");
    H.hnTrkPt         = (TH1D*)f->Get("hnTrkPt");
    H.hpTrkEta        = (TH1D*)f->Get("hpTrkEta");
    H.hnTrkEta        = (TH1D*)f->Get("hnTrkEta");
    H.hpTrkNPxLayer   = (TH1D*)f->Get("hpTrkNPxLayer");
    H.hnTrkNPxLayer   = (TH1D*)f->Get("hnTrkNPxLayer");
    H.hpTrkDCASigXY   = (TH1D*)f->Get("hpTrkDCASigXY");
    H.hnTrkDCASigXY   = (TH1D*)f->Get("hnTrkDCASigXY");
    H.hpTrkDCASigZ    = (TH1D*)f->Get("hpTrkDCASigZ");
    H.hnTrkDCASigZ    = (TH1D*)f->Get("hnTrkDCASigZ");

    return H;
}

void histAdd(hists* a, hists* b)
{
    a->hpt            ->Add( b->hpt             );
    a->hrapidity      ->Add( b->hrapidity       );
    a->hvtxChi2       ->Add( b->hvtxChi2        );
    a->hcosThetaXYZ   ->Add( b->hcosThetaXYZ    );
    a->hLxyz          ->Add( b->hLxyz           );
    a->hvtxDecaySigXYZ->Add( b->hvtxDecaySigXYZ );
    a->hDCA           ->Add( b->hDCA            );
    a->hpTrkNHit      ->Add( b->hpTrkNHit       );
    a->hnTrkNHit      ->Add( b->hnTrkNHit       );
    a->hpTrkPt        ->Add( b->hpTrkPt         );
    a->hnTrkPt        ->Add( b->hnTrkPt         );
    a->hpTrkEta       ->Add( b->hpTrkEta        );
    a->hnTrkEta       ->Add( b->hnTrkEta        );
    a->hpTrkNPxLayer  ->Add( b->hpTrkNPxLayer   );
    a->hnTrkNPxLayer  ->Add( b->hnTrkNPxLayer   );
    a->hpTrkDCASigXY  ->Add( b->hpTrkDCASigXY   );
    a->hnTrkDCASigXY  ->Add( b->hnTrkDCASigXY   );
    a->hpTrkDCASigZ   ->Add( b->hpTrkDCASigZ    );
    a->hnTrkDCASigZ   ->Add( b->hnTrkDCASigZ    );

}

void varHist(string mcsig="HistHydjetMCTruth_LM.root", string mcbkg="HistHydjetMCBkg_LM.root", string data="HistData_LM.root", string prefix = "LM")
{
    TFile * fMCSig = new TFile(mcsig.c_str());
    TFile * fMCBkg = new TFile(mcbkg.c_str());
    TFile * fData  = new TFile(data.c_str());

    hists HistMCSig = getHist(fMCSig);
    hists HistMCBkg = getHist(fMCBkg);
    hists HistData  = getHist(fData);

    histAdd( &HistMCSig, &HistMCBkg );
    double MCCount= HistMCSig.hpt->GetEntries();
    double MCBkgCount= HistMCBkg.hpt->GetEntries();
    double DataCount = HistData.hpt->GetEntries();
    cout << " MCCount = " << MCCount << "\tDataCount = " << DataCount << endl;

    HistMCSig.Scale(1./MCCount);
    HistMCBkg.Scale(1./MCCount);
    HistData .Scale(1./DataCount);

    HistMCSig.SetLineColor(kRed);
    HistMCBkg.SetLineColor(kBlue);
    HistData.SetLineColor(kBlack);

    TCanvas *c = new TCanvas("c", "c", 800, 600);
    c->SetLogy();

    HistMCSig.hpt       ->Draw("hist");
    HistMCBkg.hpt       ->Draw("histsame");
    HistData. hpt       ->Draw("histsame");
    c->SaveAs((prefix+"pt.pdf").c_str());

    HistMCSig.hrapidity       ->Draw("hist");
    HistMCBkg.hrapidity       ->Draw("histsame");
    HistData .hrapidity       ->Draw("histsame");
    c->SaveAs((prefix+"rapidity.pdf").c_str());

    HistMCSig.hvtxChi2        ->Draw("hist");
    HistMCBkg.hvtxChi2        ->Draw("histsame");
    HistData .hvtxChi2        ->Draw("histsame");
    c->SaveAs((prefix+"vtxChi2.pdf").c_str());

    HistMCSig.hcosThetaXYZ    ->Draw("hist");
    HistMCBkg.hcosThetaXYZ    ->Draw("histsame");
    HistData .hcosThetaXYZ    ->Draw("histsame");
    c->SaveAs((prefix+"cosThetaXYZ.pdf").c_str());

    HistMCSig.hLxyz           ->Draw("hist");
    HistMCBkg.hLxyz           ->Draw("histsame");
    HistData .hLxyz           ->Draw("histsame");
    c->SaveAs((prefix+"Lxyz.pdf").c_str());

    HistMCSig.hvtxDecaySigXYZ ->Draw("hist");
    HistMCBkg.hvtxDecaySigXYZ ->Draw("histsame");
    HistData .hvtxDecaySigXYZ ->Draw("histsame");
    c->SaveAs((prefix+"vtxDecaySigXYZ.pdf").c_str());

    HistMCSig.hDCA            ->Draw("hist");
    HistMCBkg.hDCA            ->Draw("histsame");
    HistData .hDCA            ->Draw("histsame");
    c->SaveAs((prefix+"DCA.pdf").c_str());

    HistMCSig.hpTrkNHit       ->Draw("hist");
    HistMCBkg.hpTrkNHit       ->Draw("histsame");
    HistData .hpTrkNHit       ->Draw("histsame");
    c->SaveAs((prefix+"pTrkNHit.pdf").c_str());

    HistMCSig.hnTrkNHit       ->Draw("hist");
    HistMCBkg.hnTrkNHit       ->Draw("histsame");
    HistData .hnTrkNHit       ->Draw("histsame");
    c->SaveAs((prefix+"nTrkNHit.pdf").c_str());

    HistMCSig.hpTrkPt         ->Draw("hist");
    HistMCBkg.hpTrkPt         ->Draw("histsame");
    HistData .hpTrkPt         ->Draw("histsame");
    c->SaveAs((prefix+"pTrkPt.pdf").c_str());

    HistMCSig.hnTrkPt         ->Draw("hist");
    HistMCBkg.hnTrkPt         ->Draw("histsame");
    HistData .hnTrkPt         ->Draw("histsame");
    c->SaveAs((prefix+"nTrkPt.pdf").c_str());

    HistMCSig.hpTrkEta        ->Draw("hist");
    HistMCBkg.hpTrkEta        ->Draw("histsame");
    HistData .hpTrkEta        ->Draw("histsame");
    c->SaveAs((prefix+"pTrkEta.pdf").c_str());

    HistMCSig.hnTrkEta        ->Draw("hist");
    HistMCBkg.hnTrkEta        ->Draw("histsame");
    HistData .hnTrkEta        ->Draw("histsame");
    c->SaveAs((prefix+"nTrkEta.pdf").c_str());

    HistMCSig.hpTrkNPxLayer   ->Draw("hist");
    HistMCBkg.hpTrkNPxLayer   ->Draw("histsame");
    HistData .hpTrkNPxLayer   ->Draw("histsame");
    c->SaveAs((prefix+"pTrkNPxLayer.pdf").c_str());

    HistMCSig.hnTrkNPxLayer   ->Draw("hist");
    HistMCBkg.hnTrkNPxLayer   ->Draw("histsame");
    HistData .hnTrkNPxLayer   ->Draw("histsame");
    c->SaveAs((prefix+"nTrkNPxLayer.pdf").c_str());

    HistMCSig.hpTrkDCASigXY   ->Draw("hist");
    HistMCBkg.hpTrkDCASigXY   ->Draw("histsame");
    HistData .hpTrkDCASigXY   ->Draw("histsame");
    c->SaveAs((prefix+"pTrkDCASigXY.pdf").c_str());

    HistMCSig.hnTrkDCASigXY   ->Draw("hist");
    HistMCBkg.hnTrkDCASigXY   ->Draw("histsame");
    HistData .hnTrkDCASigXY   ->Draw("histsame");
    c->SaveAs((prefix+"nTrkDCASigXY.pdf").c_str());

    HistMCSig.hpTrkDCASigZ    ->Draw("hist");
    HistMCBkg.hpTrkDCASigZ    ->Draw("histsame");
    HistData .hpTrkDCASigZ    ->Draw("histsame");
    c->SaveAs((prefix+"pTrkDCASigZ.pdf").c_str());

    HistMCSig.hnTrkDCASigZ    ->Draw("hist");
    HistMCBkg.hnTrkDCASigZ    ->Draw("histsame");
    HistData .hnTrkDCASigZ    ->Draw("histsame");
    c->SaveAs((prefix+"nTrkDCASigZ.pdf").c_str());

//    TFile * fsave = new TFile("varHist.root", "recreate");
}
