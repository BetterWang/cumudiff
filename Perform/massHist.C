
struct massH {
    massH(string fin) {
        f = new TFile(fin.c_str());
        for ( int c = 0; c < 6; c++ ) {
            for ( int ipt = 0; ipt < 13; ipt++ ) {
                hMassMid[c][ipt] = (TH1D*) f->Get(Form("hMassMid_%i_%i", c, ipt));
                hMassFwd[c][ipt] = (TH1D*) f->Get(Form("hMassFwd_%i_%i", c, ipt));
            }
        }
    };
    TFile * f;
    TH1D * hMassMid[6][13];
    TH1D * hMassFwd[6][13];
};


void massHist(string s = "LM", int c = 2, int ipt = 7)
{
    massH * mSS = new massH( (string("FlatMassSS2_")+s+".root").c_str() );
    massH * mWS = new massH( (string("FlatMassWS2_")+s+".root").c_str() );

    massH * mSSmva = new massH( (string("MVAmassBDT250D4_")+s+"_MB19SS.root").c_str() );
    massH * mWSmva = new massH( (string("MVAmassBDT250D4_")+s+"_MB19WS.root").c_str() );

    TCanvas * c1 = new TCanvas("c1", "c1", 800, 600);

    mSS->hMassMid[c][ipt]->SetMinimum(0.);
    mSS->hMassMid[c][ipt]->Draw("hist");
    mWS->hMassMid[c][ipt]->SetLineColor(kGreen+2);
    mWS->hMassMid[c][ipt]->Draw("histsame");


    mSSmva->hMassMid[c][ipt]->SetLineColor(kRed);
    mWSmva->hMassMid[c][ipt]->SetLineColor(kBlue);
    mSSmva->hMassMid[c][ipt]->Draw("histsame");
    mWSmva->hMassMid[c][ipt]->Draw("histsame");

    c1->SaveAs(Form("massWS_%s_%i_%i.pdf", s.c_str(), c, ipt));
}
