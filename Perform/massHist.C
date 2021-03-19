
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

    TLegend * leg = new TLegend(0.60, 0.70, 0.85 , 0.87);
    leg->SetFillColor(kWhite);
    leg->SetTextFont(42);
    leg->SetTextSize(0.04);
    leg->SetBorderSize(0);

    leg->AddEntry(mSS->hMassMid[c][ipt], "OS before MVA", "l");
    leg->AddEntry(mWS->hMassMid[c][ipt], "SS before MVA", "l");
    leg->AddEntry(mSSmva->hMassMid[c][ipt], "OS after MVA", "l");
    leg->AddEntry(mWSmva->hMassMid[c][ipt], "SS after MVA", "l");

    leg->Draw();
    TLatex latexS;
    latexS.SetTextFont(43);
    latexS.SetTextSize(24);
    latexS.SetTextAlign(13);

    string strCent[5] = {
        "0-5\%",
        "5-10\%",
        "10-30\%",
        "30-50\%",
        "50-80\%",
    };

    string strPt[13] = {
        " ", // 0
        " ", // 1
        " ", // 2
        " ", // 3
        " 1.0<p_{T}<1.4", // 4
        " 1.4<p_{T}<1.8", // 5
        " 1.8<p_{T}<2.2", // 6
        " 2.2<p_{T}<2.8", // 7
        " 2.8<p_{T}<3.6", // 8
        " 3.6<p_{T}<4.6", // 9
        " 4.6<p_{T}<6.0", // 10
        " 6.0<p_{T}<7.0", // 11
        " 7.0<p_{T}<8.5", // 12
    };

    string part = "#Lambda ";
    if (s != "LM") {
        part = "K_{S}^{0} ";
    }
    cout << (part+strCent[c]+strPt[ipt]) << endl;;
    latexS.DrawLatexNDC(0.55, 0.93, (part+strCent[c]+strPt[ipt]).c_str());

    c1->SaveAs(Form("massWS_%s_%i_%i.pdf", s.c_str(), c, ipt));
}
