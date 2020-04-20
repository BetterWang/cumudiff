

#include "../../style.h"
#include "Steve_SP.h"
#include "theory.h"

TColor *red = new TColor(3001, 1, 0, 0, "red", 0.4);
TColor *green = new TColor(3002, 0, 0.5, 0, "green", 0.4);
TColor *blue = new TColor(3003, 0, 0, 1, "blue", 0.4);
TColor *gray = new TColor(3005, 0, 0, 0, "black", 0.4);

// systematics
// 0 -- H   1.4
// 1 -- Ks  3.5
// 2 -- Lm  5.7
const double cumu_syst[3] = {0.014, 0.035, 0.057};

struct QWCumu {
    TGraphErrors * grSig_pT[7][4][20] = {};
    TGraphErrors * grSig_pTGap[7][20] = {};

    TGraphErrors * grSig_V2sub2pos[20] = {};
    TGraphErrors * grSig_V2sub2neg[20] = {};
    TGraphErrors * grSig_V2sub2merge[20] = {};

    TGraphErrors * grSig_V2sub4pos[20] = {};
    TGraphErrors * grSig_V2sub4neg[20] = {};
    TGraphErrors * grSig_V2sub4merge[20] = {};

    // sys
    TGraphErrors * grSysSig_pT[7][4][20] = {};
    TGraphErrors * grSysSig_pTGap[7][20] = {};

    TGraphErrors * grSysSig_V2sub2pos[20] = {};
    TGraphErrors * grSysSig_V2sub2neg[20] = {};
    TGraphErrors * grSysSig_V2sub2merge[20] = {};

    TGraphErrors * grSysSig_V2sub4pos[20] = {};
    TGraphErrors * grSysSig_V2sub4neg[20] = {};
    TGraphErrors * grSysSig_V2sub4merge[20] = {};


    QWCumu(TFile *f, int pid, bool bTrim = false) {
        for ( int n = 2; n < 7; n++ ) {
            for ( int c = 0; c < 5; c++ ) {
                grSig_pTGap[n][c] = (TGraphErrors*) f->Get(Form("grSig_pTGap%i_%i", n, c));
                grSysSig_pTGap[n][c] = getSys( grSig_pTGap[n][c], cumu_syst[pid] );
                for ( int np = 0; np < 4; np++ ) {
                    grSig_pT[n][np][c] = (TGraphErrors*) f->Get( Form("grSig_pT%i_%i_%i", n, np, c) );
                    grSysSig_pT[n][np][c] = getSys( grSig_pT[n][np][c], cumu_syst[pid] );
                }
            }
        }

        for ( int c = 0; c < 5; c++ ) {
            grSig_V2sub2pos[c]      = (TGraphErrors*) f->Get( Form("grSig_V2sub2pos_%i", c) );
            grSig_V2sub2neg[c]      = (TGraphErrors*) f->Get( Form("grSig_V2sub2neg_%i", c) );
            grSig_V2sub2merge[c]    = (TGraphErrors*) f->Get( Form("grSig_V2sub2merge_%i", c) );

            grSig_V2sub4pos[c]      = (TGraphErrors*) f->Get( Form("grSig_V2sub4pos_%i", c) );
            grSig_V2sub4neg[c]      = (TGraphErrors*) f->Get( Form("grSig_V2sub4neg_%i", c) );
            grSig_V2sub4merge[c]    = (TGraphErrors*) f->Get( Form("grSig_V2sub4merge_%i", c) );

            grSysSig_V2sub2pos[c]      = getSys( grSig_V2sub2pos[c]   , cumu_syst[pid] );
            grSysSig_V2sub2neg[c]      = getSys( grSig_V2sub2neg[c]   , cumu_syst[pid] );
            grSysSig_V2sub2merge[c]    = getSys( grSig_V2sub2merge[c] , cumu_syst[pid] );

            grSysSig_V2sub4pos[c]      = getSys( grSig_V2sub4pos[c]   , cumu_syst[pid] );
            grSysSig_V2sub4neg[c]      = getSys( grSig_V2sub4neg[c]   , cumu_syst[pid] );
            grSysSig_V2sub4merge[c]    = getSys( grSig_V2sub4merge[c] , cumu_syst[pid] );
        }

        if ( bTrim ) {
            if ( pid == 0 ) dropPoints(2);
            else if ( pid == 1 ) dropPoints(4);
            else if ( pid == 2 ) dropPoints(6);
        }
    };

    TGraphErrors* getSys(TGraphErrors* gr, double sys)
    {
        int N = gr->GetN();
        TGraphErrors* g = new TGraphErrors(N);

        for ( int i = 0; i < N; i++ ) {
            g->GetX()[i] = gr->GetX()[i];
            g->GetY()[i] = gr->GetY()[i];
            g->GetEY()[i] = gr->GetY()[i] * sys;
            g->GetEX()[i] = 0.15;
        }
        return g;
    };

    void ReplaceX(SteveGraph** gr) {
        for ( int n = 2; n < 7; n++ ) {
            for ( int c = 0; c < 5; c++ ) {
                ReplaceX( grSig_pTGap[n][c],    gr[c]->vn_NegEta );
                ReplaceX( grSysSig_pTGap[n][c], gr[c]->vn_NegEta );
                for ( int np = 0; np < 4; np++ ) {
                    ReplaceX( grSig_pT[n][np][c],    gr[c]->vn_NegEta );
                    ReplaceX( grSysSig_pT[n][np][c], gr[c]->vn_NegEta );
                }
            }
        }
        for ( int c = 0; c < 5; c++ ) {
            ReplaceX( grSig_V2sub2pos[c],   gr[c]->vn_NegEta );
            ReplaceX( grSig_V2sub2neg[c],   gr[c]->vn_NegEta );
            ReplaceX( grSig_V2sub2merge[c], gr[c]->vn_NegEta );
            ReplaceX( grSig_V2sub4pos[c],   gr[c]->vn_NegEta );
            ReplaceX( grSig_V2sub4neg[c],   gr[c]->vn_NegEta );
            ReplaceX( grSig_V2sub4merge[c], gr[c]->vn_NegEta );

            ReplaceX( grSysSig_V2sub2pos[c],    gr[c]->vn_NegEta );
            ReplaceX( grSysSig_V2sub2neg[c],    gr[c]->vn_NegEta );
            ReplaceX( grSysSig_V2sub2merge[c],  gr[c]->vn_NegEta );
            ReplaceX( grSysSig_V2sub4pos[c],    gr[c]->vn_NegEta );
            ReplaceX( grSysSig_V2sub4neg[c],    gr[c]->vn_NegEta );
            ReplaceX( grSysSig_V2sub4merge[c],  gr[c]->vn_NegEta );
        }
    };

    void ReplaceX( TGraphErrors* gr1, TGraphErrors* gr2 ) {
        int N = gr1->GetN();
        if ( N != gr2->GetN() ) {
            cout << " --> inconsistent" << endl;
            return;
        }
        for ( int i = 0; i < N; i++ ) {
            gr1->GetX()[i] = gr2->GetX()[i];
        }
        return;
    };

    void dropPoints( int N ) {
        for ( int i = 0; i < N; i++ ) {
            for ( int n = 2; n < 7; n++ ) {
                for ( int c = 0; c < 5; c++ ) {
                    grSig_pTGap[n][c]   ->RemovePoint(0);
                    grSysSig_pTGap[n][c]->RemovePoint(0);
                    for ( int np = 0; np < 4; np++ ) {
                        grSig_pT[n][np][c]      ->RemovePoint(0);
                        grSysSig_pT[n][np][c]   ->RemovePoint(0);
                    }
                }
            }
            for ( int c = 0; c < 5; c++ ) {
                grSig_V2sub2pos[c]  ->RemovePoint(0);
                grSig_V2sub2neg[c]  ->RemovePoint(0);
                grSig_V2sub2merge[c]->RemovePoint(0);
                grSig_V2sub4pos[c]  ->RemovePoint(0);
                grSig_V2sub4neg[c]  ->RemovePoint(0);
                grSig_V2sub4merge[c]->RemovePoint(0);
                grSysSig_V2sub2pos[c]  ->RemovePoint(0);
                grSysSig_V2sub2neg[c]  ->RemovePoint(0);
                grSysSig_V2sub2merge[c]->RemovePoint(0);
                grSysSig_V2sub4pos[c]  ->RemovePoint(0);
                grSysSig_V2sub4neg[c]  ->RemovePoint(0);
                grSysSig_V2sub4merge[c]->RemovePoint(0);
            }
        }
    }
};

TGraphErrors* getFluct(TGraphErrors* gr1, TGraphErrors* gr2) {
    TGraphErrors* ret = new TGraphErrors(gr1->GetN());
    for ( int i = 0; i < gr1->GetN(); i++ ) {
		double y1 = gr1->GetY()[i];
		double ey1 = gr1->GetEY()[i];
		double y2 = gr2->GetY()[i];
		double ey2 = gr2->GetEY()[i];

		ret->GetX()[i] = gr1->GetX()[i];
		ret->GetY()[i] = sqrt( (y1*y1 - y2*y2)/(y1*y1 + y2*y2) );

		double t = y1*y1 - y2*y2;
		double g = y1*y1 + y2*y2;
		double f1 = 2*y1;
		double f2 = -2*y2;
		double g1 = 2*y1;
		double g2 = 2*y2;

		double err1 = (f1/g - t*g1/g/g)*(f1/g - t*g1/g/g)*ey1*ey1;
		double err2 = (f2/g - t*g2/g/g)*(f2/g - t*g2/g/g)*ey2*ey2;
		double x = t/g;
		double ex = sqrt(err1 + err2);

		ret->GetEY()[i] = ex/sqrt(x)/2;
    }
	return ret;
}

TGraphErrors* getRatio(TGraphErrors* gr1, TGraphErrors* gr2)
{
    TGraphErrors * ret = new TGraphErrors(gr2->GetN());
    for ( int i = 0; i < gr2->GetN(); i++ ) {
        ret->GetX()[i] = gr2->GetX()[i];
        ret->GetEX()[i] = gr2->GetEX()[i];
        ret->GetY()[i] = gr1->GetY()[i] / gr2->GetY()[i];
        ret->GetEY()[i] = sqrt( gr1->GetEY()[i]*gr1->GetEY()[i]/gr1->GetY()[i]/gr1->GetY()[i] + gr2->GetEY()[i]*gr2->GetEY()[i]/gr2->GetY()[i]/gr2->GetY()[i]  );
    }
    return ret;
}


void plotResult()
{
    TFile * fH  = new TFile("PbPb2018_H_corrected.root");
    TFile * fKs = new TFile("PbPb2018_Ks_corrected.root");
    TFile * fLm = new TFile("PbPb2018_Lm_corrected.root");

    QWCumu vH (fH,  0, true);
    QWCumu vKs(fKs, 1, true);
    QWCumu vLm(fLm, 2, true);

    LoadSPCorrected(true);

    vH .ReplaceX( ch_v2_PbPb );
    vKs.ReplaceX( Ks_v2_PbPb_Sig );
    vLm.ReplaceX( Lm_v2_PbPb_Sig );

    theory();

    string centBins[] = {"0-5\%", "5-10\%", "10-30\%", "30-50\%", "50-80\%"};

    TLatex latexS;
    latexS.SetTextFont(43);
    latexS.SetTextSize(22);
    latexS.SetTextAlign(13);

    TLine line1(0., 1., 8.5, 1.);

    TCanvas* c0 = MakeCanvas("c0", "c0", 800, 600);
    TCanvas* c1 = MakeCanvas("c1", "c1", 800, 600);
    TCanvas* c2 = MakeCanvas("c2", "c2", 800, 600);

    TCanvas* cR = MakeCanvas("cR", "cR", 800, 600);
    TCanvas* cF = MakeCanvas("cF", "cF", 800, 600);

    TH2D * hframe_pt = new TH2D("hframe_pt", "hframe_pt", 1, 0, 8.5, 1, 0, 0.35);
    InitHist(hframe_pt, "p_{T}", "v_{n}");

    TH2D * hframe_ratio = new TH2D("hframe_ratio", "hframe_ratio", 1, 0, 8.5, 1, 0.05, 1.8);
    InitHist(hframe_ratio, "p_{T}", "v_{2}{4} / v_{2}{SP}");

    TH2D * hframeS_ratio = new TH2D("hframeS_ratio", "hframeS_ratio", 1, 0, 8.5, 1, 0.8, 1.5);
    InitHist(hframeS_ratio, "p_{T}", "Ratio");

    TH2D * hframe_fluct = new TH2D("hframe_fluct", "hframe_fluct", 1, 0, 8.5, 1, 0.05, 0.9);
    InitHist(hframe_fluct, "p_{T}", "Fluctuation");

    for ( int c = 0; c < 5; c++ ) {
        c0->cd();
        hframe_pt->Draw();

        latexS.DrawLatexNDC(0.15, 0.99, "#bf{CMS}");
        latexS.DrawLatexNDC(0.75, 0.99, "PbPb 5.02 TeV");
        latexS.DrawLatexNDC(0.25, 0.90, (centBins[c]+ " Ch").c_str());

        TLegend * leg0 = new TLegend(0.68, 0.71, 0.90, 0.93);
        leg0->SetFillColor(kWhite);
        leg0->SetTextFont(42);
        leg0->SetTextSize(0.05);
        leg0->SetBorderSize(0);

        ch_v2_PbPb[c]   ->vn_MergedEta->SetMarkerStyle(kOpenCircle);
        ch_v2_PbPb[c]   ->vn_MergedEta->SetMarkerColor(kBlack);
        ch_v2_PbPb[c]   ->vn_MergedEta->SetLineColor  (kBlack);
        ch_v2_PbPb[c]   ->vn_MergedEta->SetMarkerSize(2.);

        ch_v2_sysPbPb[c]->vn_MergedEta->SetFillColor(3005);

        ch_v2_sysPbPb[c]->vn_MergedEta->Draw("[]2");
        ch_v2_PbPb[c]   ->vn_MergedEta->Draw("psame");

        //
        vH.grSig_pT[2][1][c] ->SetMarkerStyle(kOpenCircle);
        vH.grSig_pT[2][1][c] ->SetMarkerColor(kBlue);
        vH.grSig_pT[2][1][c] ->SetLineColor  (kBlue);
        vH.grSig_pT[2][1][c] ->SetMarkerSize(2.);

        vH.grSig_pT[2][2][c] ->SetMarkerStyle(kOpenCircle);
        vH.grSig_pT[2][2][c] ->SetMarkerColor(kRed);
        vH.grSig_pT[2][2][c] ->SetLineColor  (kRed);
        vH.grSig_pT[2][2][c] ->SetMarkerSize(2.);

        vH.grSig_pT[2][3][c] ->SetMarkerStyle(kOpenCircle);
        vH.grSig_pT[2][3][c] ->SetMarkerColor(kGreen+2);
        vH.grSig_pT[2][3][c] ->SetLineColor  (kGreen+2);
        vH.grSig_pT[2][3][c] ->SetMarkerSize(2.);

        vH.grSysSig_pT[2][1][c] ->SetFillColor(3003);
        vH.grSysSig_pT[2][2][c] ->SetFillColor(3001);
        vH.grSysSig_pT[2][3][c] ->SetFillColor(3002);

        vH.grSysSig_pT[2][1][c] ->Draw("[]2");
        vH.grSysSig_pT[2][2][c] ->Draw("[]2");
        vH.grSysSig_pT[2][3][c] ->Draw("[]2");

        vH.grSig_pT[2][1][c]    ->Draw("psame");
        vH.grSig_pT[2][2][c]    ->Draw("psame");
        vH.grSig_pT[2][3][c]    ->Draw("psame");

        cout << " sp ch N = " << ch_v2_PbPb[c]   ->vn_MergedEta->GetN() << endl;
        cout << " cumu ch N = " << vH.grSig_pT[2][1][c]->GetN() << endl;

        leg0->AddEntry(ch_v2_PbPb[c]->vn_MergedEta,     "v_{2}{SP}", "p");
        leg0->AddEntry(vH.grSig_pT[2][1][c], "v_{2}{4}", "p");
        leg0->AddEntry(vH.grSig_pT[2][2][c], "v_{2}{6}", "p");
        leg0->AddEntry(vH.grSig_pT[2][3][c], "v_{2}{8}", "p");
        leg0->Draw();

        //
        c1->cd();
        hframe_pt->Draw();

        latexS.DrawLatexNDC(0.15, 0.99, "#bf{CMS}");
        latexS.DrawLatexNDC(0.75, 0.99, "PbPb 5.02 TeV");
        latexS.DrawLatexNDC(0.25, 0.90, (centBins[c]+ " K_{S}^{0}").c_str());

        TLegend * leg1 = new TLegend(0.68, 0.71, 0.90, 0.93);
        leg1->SetFillColor(kWhite);
        leg1->SetTextFont(42);
        leg1->SetTextSize(0.05);
        leg1->SetBorderSize(0);


        Ks_v2_PbPb_Sig[c]   ->vn_MergedEta->SetMarkerStyle(kOpenSquare);
        Ks_v2_PbPb_Sig[c]   ->vn_MergedEta->SetMarkerColor(kBlack);
        Ks_v2_PbPb_Sig[c]   ->vn_MergedEta->SetLineColor  (kBlack);
        Ks_v2_PbPb_Sig[c]   ->vn_MergedEta->SetMarkerSize(2.);

        Ks_v2_sysPbPb_Sig[c]->vn_MergedEta->SetFillColor(3005);

        Ks_v2_sysPbPb_Sig[c]->vn_MergedEta->Draw("[]2");
        Ks_v2_PbPb_Sig[c]   ->vn_MergedEta->Draw("psame");

        //
        vKs.grSig_pT[2][1][c] ->SetMarkerStyle(kOpenSquare);
        vKs.grSig_pT[2][1][c] ->SetMarkerColor(kBlue);
        vKs.grSig_pT[2][1][c] ->SetLineColor  (kBlue);
        vKs.grSig_pT[2][1][c] ->SetMarkerSize(2.);

        vKs.grSig_pT[2][2][c] ->SetMarkerStyle(kOpenSquare);
        vKs.grSig_pT[2][2][c] ->SetMarkerColor(kRed);
        vKs.grSig_pT[2][2][c] ->SetLineColor  (kRed);
        vKs.grSig_pT[2][2][c] ->SetMarkerSize(2.);

        vKs.grSig_pT[2][3][c] ->SetMarkerStyle(kOpenSquare);
        vKs.grSig_pT[2][3][c] ->SetMarkerColor(kGreen+2);
        vKs.grSig_pT[2][3][c] ->SetLineColor  (kGreen+2);
        vKs.grSig_pT[2][3][c] ->SetMarkerSize(2.);

        vKs.grSysSig_pT[2][1][c] ->SetFillColor(3003);
        vKs.grSysSig_pT[2][2][c] ->SetFillColor(3001);
        vKs.grSysSig_pT[2][3][c] ->SetFillColor(3002);

        vKs.grSysSig_pT[2][1][c] ->Draw("[]2");
        vKs.grSysSig_pT[2][2][c] ->Draw("[]2");
        vKs.grSysSig_pT[2][3][c] ->Draw("[]2");

        vKs.grSig_pT[2][1][c]    ->Draw("psame");
        vKs.grSig_pT[2][2][c]    ->Draw("psame");
        vKs.grSig_pT[2][3][c]    ->Draw("psame");

        cout << " sp Ks N = " << Ks_v2_PbPb_Sig[c]   ->vn_MergedEta->GetN() << endl;
        cout << " cumu Ks N = " << vKs.grSig_pT[2][1][c]->GetN() << endl;

        leg1->AddEntry(Ks_v2_PbPb_Sig[c]->vn_MergedEta,     "v_{2}{SP}", "p");
        leg1->AddEntry(vKs.grSig_pT[2][1][c], "v_{2}{4}", "p");
        leg1->AddEntry(vKs.grSig_pT[2][2][c], "v_{2}{6}", "p");
        leg1->AddEntry(vKs.grSig_pT[2][3][c], "v_{2}{8}", "p");
        leg1->Draw();

        //
        c2->cd();
        hframe_pt->Draw();

        latexS.DrawLatexNDC(0.15, 0.99, "#bf{CMS}");
        latexS.DrawLatexNDC(0.75, 0.99, "PbPb 5.02 TeV");
        latexS.DrawLatexNDC(0.25, 0.90, (centBins[c]+ " Ch").c_str());

        TLegend * leg2 = new TLegend(0.68, 0.71, 0.90, 0.93);
        leg2->SetFillColor(kWhite);
        leg2->SetTextFont(42);
        leg2->SetTextSize(0.05);
        leg2->SetBorderSize(0);


        Lm_v2_PbPb_Sig[c]   ->vn_MergedEta->SetMarkerStyle(kOpenCircle);
        Lm_v2_PbPb_Sig[c]   ->vn_MergedEta->SetMarkerColor(kBlack);
        Lm_v2_PbPb_Sig[c]   ->vn_MergedEta->SetLineColor  (kBlack);
        Lm_v2_PbPb_Sig[c]   ->vn_MergedEta->SetMarkerSize(2.);

        Lm_v2_sysPbPb_Sig[c]->vn_MergedEta->SetFillColor(3005);

        Lm_v2_sysPbPb_Sig[c]->vn_MergedEta->Draw("[]2");
        Lm_v2_PbPb_Sig[c]   ->vn_MergedEta->Draw("psame");

        //
        vLm.grSig_pT[2][1][c] ->SetMarkerStyle(kOpenCircle);
        vLm.grSig_pT[2][1][c] ->SetMarkerColor(kBlue);
        vLm.grSig_pT[2][1][c] ->SetLineColor  (kBlue);
        vLm.grSig_pT[2][1][c] ->SetMarkerSize(2.);

        vLm.grSig_pT[2][2][c] ->SetMarkerStyle(kOpenCircle);
        vLm.grSig_pT[2][2][c] ->SetMarkerColor(kRed);
        vLm.grSig_pT[2][2][c] ->SetLineColor  (kRed);
        vLm.grSig_pT[2][2][c] ->SetMarkerSize(2.);

        vLm.grSig_pT[2][3][c] ->SetMarkerStyle(kOpenCircle);
        vLm.grSig_pT[2][3][c] ->SetMarkerColor(kGreen+2);
        vLm.grSig_pT[2][3][c] ->SetLineColor  (kGreen+2);
        vLm.grSig_pT[2][3][c] ->SetMarkerSize(2.);

        vLm.grSysSig_pT[2][1][c] ->SetFillColor(3003);
        vLm.grSysSig_pT[2][2][c] ->SetFillColor(3001);
        vLm.grSysSig_pT[2][3][c] ->SetFillColor(3002);

        vLm.grSysSig_pT[2][1][c] ->Draw("[]2");
        vLm.grSysSig_pT[2][2][c] ->Draw("[]2");
        vLm.grSysSig_pT[2][3][c] ->Draw("[]2");

        vLm.grSig_pT[2][1][c]    ->Draw("psame");
        vLm.grSig_pT[2][2][c]    ->Draw("psame");
        vLm.grSig_pT[2][3][c]    ->Draw("psame");

        cout << " sp Lm N = " << Lm_v2_PbPb_Sig[c]   ->vn_MergedEta->GetN() << endl;
        cout << " cumu Lm N = " << vLm.grSig_pT[2][1][c]->GetN() << endl;

        leg2->AddEntry(Lm_v2_PbPb_Sig[c]->vn_MergedEta,     "v_{2}{SP}", "p");
        leg2->AddEntry(vLm.grSig_pT[2][1][c], "v_{2}{4}", "p");
        leg2->AddEntry(vLm.grSig_pT[2][2][c], "v_{2}{6}", "p");
        leg2->AddEntry(vLm.grSig_pT[2][3][c], "v_{2}{8}", "p");
        leg2->Draw();

        //
        cR->cd();
        hframe_ratio->Draw();

        latexS.DrawLatexNDC(0.15, 0.99, "#bf{CMS}");
        latexS.DrawLatexNDC(0.75, 0.99, "PbPb 5.02 TeV");
        latexS.DrawLatexNDC(0.25, 0.90, centBins[c].c_str());

        TLegend * legR = new TLegend(0.58, 0.71, 0.80, 0.93);
        legR->SetFillColor(kWhite);
        legR->SetTextFont(42);
        legR->SetTextSize(0.05);
        legR->SetBorderSize(0);

        auto * gRatio     = getRatio( vH.grSig_pT[2][1][c], ch_v2_PbPb[c]->vn_MergedEta );
        auto * gRatio_sys = getRatio( vH.grSysSig_pT[2][1][c], ch_v2_sysPbPb[c]->vn_MergedEta );

        gRatio_sys->SetFillColor(3005);

        gRatio->SetMarkerStyle(kOpenCircle);
        gRatio->SetMarkerColor(kBlack);
        gRatio->SetLineColor  (kBlack);
        gRatio->SetMarkerSize(2.);

        gRatio_sys->Draw("[]2");
        gRatio->Draw("psame");

        auto * gKsRatio     = getRatio( vKs.grSig_pT[2][1][c],    Ks_v2_PbPb_Sig[c]->vn_MergedEta );
        auto * gKsRatio_sys = getRatio( vKs.grSysSig_pT[2][1][c], Ks_v2_sysPbPb_Sig[c]->vn_MergedEta );

        gKsRatio_sys->SetFillColor(3003);
        gKsRatio->SetMarkerStyle(kOpenSquare);
        gKsRatio->SetMarkerColor(kBlue);
        gKsRatio->SetLineColor  (kBlue);
        gKsRatio->SetMarkerSize(2.);

        gKsRatio_sys->Draw("[]2");
        gKsRatio->Draw("psame");

        auto * gLmRatio     = getRatio( vLm.grSig_pT[2][1][c],    Lm_v2_PbPb_Sig[c]->vn_MergedEta );
        auto * gLmRatio_sys = getRatio( vLm.grSysSig_pT[2][1][c], Lm_v2_sysPbPb_Sig[c]->vn_MergedEta );

        gLmRatio_sys->SetFillColor(3001);
        gLmRatio->SetMarkerStyle(kOpenCircle);
        gLmRatio->SetMarkerColor(kRed);
        gLmRatio->SetLineColor  (kRed);
        gLmRatio->SetMarkerSize(2.);

        gLmRatio_sys->Draw("[]2");
        gLmRatio->Draw("psame");


        legR->AddEntry(gRatio, "Ch", "p");
        legR->AddEntry(gKsRatio, "K_{S}^{0}", "p");
        legR->AddEntry(gLmRatio, "#Lambda", "p");

        if ( ampt  ->grLm_v22[c] ) {
            auto * gKsAMPTRatio   = getRatio( ampt  ->grKs_v24[c], ampt  ->grKs_v22[c] );
            auto * gKsTrentoRatio = getRatio( trento->grKs_v24[c], trento->grKs_v22[c] );

            auto * gLmAMPTRatio   = getRatio( ampt  ->grLm_v24[c], ampt  ->grLm_v22[c] );
            auto * gLmTrentoRatio = getRatio( trento->grLm_v24[c], trento->grLm_v22[c] );

            gKsAMPTRatio  ->SetLineColor(kBlue);
            gKsTrentoRatio->SetLineColor(kBlue);
            gKsTrentoRatio->SetLineStyle(kDashed);

            gLmAMPTRatio  ->SetLineColor(kRed);
            gLmTrentoRatio->SetLineColor(kRed);
            gLmTrentoRatio->SetLineStyle(kDashed);

            gKsAMPTRatio  ->Draw("lsame");
            gKsTrentoRatio->Draw("lsame");
            gLmAMPTRatio  ->Draw("lsame");
            gLmTrentoRatio->Draw("lsame");
        }

        legR->Draw();

        //
        cF->cd();
        hframe_fluct->Draw();

        latexS.DrawLatexNDC(0.15, 0.99, "#bf{CMS}");
        latexS.DrawLatexNDC(0.75, 0.99, "PbPb 5.02 TeV");
        latexS.DrawLatexNDC(0.25, 0.90, (centBins[c]+ " Ch").c_str());

        TLegend * legF = new TLegend(0.68, 0.71, 0.90, 0.93);
        legF->SetFillColor(kWhite);
        legF->SetTextFont(42);
        legF->SetTextSize(0.05);
        legF->SetBorderSize(0);

        auto * gChF = getFluct( ch_v2_PbPb[c]->vn_MergedEta     , vH .grSig_pT[2][1][c] );
        auto * gKsF = getFluct( Ks_v2_PbPb_Sig[c]->vn_MergedEta , vKs.grSig_pT[2][1][c] );
        auto * gLmF = getFluct( Lm_v2_PbPb_Sig[c]->vn_MergedEta , vLm.grSig_pT[2][1][c] );

        gChF->SetMarkerStyle(kOpenCircle);
        gChF->SetMarkerColor(kBlack);
        gChF->SetLineColor  (kBlack);
        gChF->SetMarkerSize(2.);

        gKsF->SetMarkerStyle(kOpenSquare);
        gKsF->SetMarkerColor(kBlue);
        gKsF->SetLineColor  (kBlue);
        gKsF->SetMarkerSize(2.);

        gLmF->SetMarkerStyle(kOpenCircle);
        gLmF->SetMarkerColor(kRed);
        gLmF->SetLineColor  (kRed);
        gLmF->SetMarkerSize(2.);

        gChF->Draw("psame");
        gKsF->Draw("psame");
        gLmF->Draw("psame");

        legF->AddEntry( gChF, "Ch", "p" );
        legF->AddEntry( gKsF, "K_{S}^{0}", "p" );
        legF->AddEntry( gLmF, "#Lambda", "p" );

        legF->Draw();

        //
        c0->SaveAs(Form("PbPb2018_H_%i.pdf", c));
        c1->SaveAs(Form("PbPb2018_Ks_%i.pdf", c));
        c2->SaveAs(Form("PbPb2018_Lm_%i.pdf", c));
        cR->SaveAs(Form("PbPb2018_Ratio_%i.pdf", c));
        cF->SaveAs(Form("PbPb2018_Fluct_%i.pdf", c));
    }

    for ( int c = 0; c < 5; c++ ) {
        c1->cd();
        hframe_pt->Draw();

        latexS.DrawLatexNDC(0.15, 0.99, "#bf{CMS}");
        latexS.DrawLatexNDC(0.75, 0.99, "PbPb 5.02 TeV");
        latexS.DrawLatexNDC(0.25, 0.90, (centBins[c]+ " K_{S}^{0}").c_str());

        Ks_v2_sysPbPb_Sig[c]->vn_MergedEta->Draw("[]2");
        Ks_v2_PbPb_Sig[c]   ->vn_MergedEta->Draw("psame");

        vKs.grSysSig_pT[2][1][c] ->Draw("[]2");
        vKs.grSig_pT[2][1][c]    ->Draw("psame");

        TLegend * leg1 = new TLegend(0.68, 0.61, 0.90, 0.93);
        leg1->SetFillColor(kWhite);
        leg1->SetTextFont(42);
        leg1->SetTextSize(0.05);
        leg1->SetBorderSize(0);

        leg1->AddEntry(Ks_v2_PbPb_Sig[c]->vn_MergedEta,     "v_{2}{SP}", "p");
        leg1->AddEntry(vKs.grSig_pT[2][1][c], "v_{2}{4}", "p");

        if ( ampt  ->grKs_v22[c] ) {
            ampt  ->grKs_v22[c]->SetLineColor(kBlack);
            trento->grKs_v22[c]->SetLineColor(kBlack);
            trento->grKs_v22[c]->SetLineStyle(kDashed);

            ampt  ->grKs_v24[c]->SetLineColor(kBlue);
            trento->grKs_v24[c]->SetLineColor(kBlue);
            trento->grKs_v24[c]->SetLineStyle(kDashed);

            ampt  ->grKs_v22[c] ->Draw("plsame");
            ampt  ->grKs_v24[c] ->Draw("plsame");
            trento->grKs_v22[c] ->Draw("plsame");
            trento->grKs_v24[c] ->Draw("plsame");

            leg1->AddEntry(trento->grKs_v22[c], "v_{2}{2} Trento", "l");
            leg1->AddEntry(ampt  ->grKs_v22[c], "v_{2}{2} AMPT", "l");
            leg1->AddEntry(trento->grKs_v24[c], "v_{2}{4} Trento", "l");
            leg1->AddEntry(ampt  ->grKs_v24[c], "v_{2}{4} AMPT", "l");
        }

        leg1->Draw();

        //
        c2->cd();
        hframe_pt->Draw();

        latexS.DrawLatexNDC(0.15, 0.99, "#bf{CMS}");
        latexS.DrawLatexNDC(0.75, 0.99, "PbPb 5.02 TeV");
        latexS.DrawLatexNDC(0.25, 0.90, (centBins[c]+ " #Lambda").c_str());

        Lm_v2_sysPbPb_Sig[c]->vn_MergedEta->Draw("[]2");
        Lm_v2_PbPb_Sig[c]   ->vn_MergedEta->Draw("psame");

        vLm.grSysSig_pT[2][1][c] ->Draw("[]2");
        vLm.grSig_pT[2][1][c]    ->Draw("psame");

        TLegend * leg2 = new TLegend(0.68, 0.61, 0.90, 0.93);
        leg2->SetFillColor(kWhite);
        leg2->SetTextFont(42);
        leg2->SetTextSize(0.05);
        leg2->SetBorderSize(0);

        leg2->AddEntry(Lm_v2_PbPb_Sig[c]->vn_MergedEta,     "v_{2}{SP}", "p");
        leg2->AddEntry(vLm.grSig_pT[2][1][c], "v_{2}{4}", "p");

        if ( ampt  ->grLm_v22[c] ) {
            ampt  ->grLm_v22[c]->SetLineColor(kBlack);
            trento->grLm_v22[c]->SetLineColor(kBlack);
            trento->grLm_v22[c]->SetLineStyle(kDashed);

            ampt  ->grLm_v24[c]->SetLineColor(kBlue);
            trento->grLm_v24[c]->SetLineColor(kBlue);
            trento->grLm_v24[c]->SetLineStyle(kDashed);

            ampt  ->grLm_v22[c]->Draw("plsame");
            ampt  ->grLm_v24[c]->Draw("plsame");
            trento->grLm_v22[c]->Draw("plsame");
            trento->grLm_v24[c]->Draw("plsame");

            leg2->AddEntry(trento->grLm_v22[c], "v_{2}{2} Trento", "l");
            leg2->AddEntry(ampt  ->grLm_v22[c], "v_{2}{2} AMPT", "l");
            leg2->AddEntry(trento->grLm_v24[c], "v_{2}{4} Trento", "l");
            leg2->AddEntry(ampt  ->grLm_v24[c], "v_{2}{4} AMPT", "l");
        }

        leg2->Draw();

        //
        c1->SaveAs(Form("PbPb2018_Ks_EbyE_%i.pdf", c));
        c2->SaveAs(Form("PbPb2018_Lm_EbyE_%i.pdf", c));
    }

//    TCanvas * cSub  = MakeCanvas("cSub",  "cSub",  800, 600);
//    TCanvas * cSubR = MakeCanvas("cSubR", "cSubR", 800, 600);

    for ( int c = 0; c < 5; c++ ) {
        c0->cd();
        hframe_pt->Draw();

        latexS.DrawLatexNDC(0.15, 0.99, "#bf{CMS}");
        latexS.DrawLatexNDC(0.75, 0.99, "PbPb 5.02 TeV");
        latexS.DrawLatexNDC(0.25, 0.90, (centBins[c]+ " Ch").c_str());

        TLegend * leg0 = new TLegend(0.68, 0.71, 0.90, 0.93);
        leg0->SetFillColor(kWhite);
        leg0->SetTextFont(42);
        leg0->SetTextSize(0.05);
        leg0->SetBorderSize(0);

        ch_v2_PbPb[c]->vn_MergedEta->SetMarkerStyle(kOpenSquare);
        ch_v2_PbPb[c]->vn_MergedEta->SetMarkerColor(kBlack);
        ch_v2_PbPb[c]->vn_MergedEta->SetLineColor  (kBlack);
        ch_v2_PbPb[c]->vn_MergedEta->SetMarkerSize(2.);

        ch_v2_PbPb[c]->vn_MergedEta_SubEvt->SetMarkerStyle(kOpenCircle);
        ch_v2_PbPb[c]->vn_MergedEta_SubEvt->SetMarkerColor(kRed);
        ch_v2_PbPb[c]->vn_MergedEta_SubEvt->SetLineColor  (kRed);
        ch_v2_PbPb[c]->vn_MergedEta_SubEvt->SetMarkerSize(2.);

        vH.grSig_pT[2][1][c]->SetMarkerStyle(kOpenSquare);
        vH.grSig_pT[2][1][c]->SetMarkerColor(kBlue);
        vH.grSig_pT[2][1][c]->SetLineColor  (kBlue);
        vH.grSig_pT[2][1][c]->SetMarkerSize(2.);

        vH.grSig_V2sub4merge[c]->SetMarkerStyle(kOpenCircle);
        vH.grSig_V2sub4merge[c]->SetMarkerColor(kGreen+2);
        vH.grSig_V2sub4merge[c]->SetLineColor  (kGreen+2);
        vH.grSig_V2sub4merge[c]->SetMarkerSize(2.);



        ch_v2_PbPb[c]->vn_MergedEta       ->Draw("psame");
        ch_v2_PbPb[c]->vn_MergedEta_SubEvt->Draw("psame");
        vH.grSig_pT[2][1][c]->Draw("psame");
        vH.grSig_V2sub4merge[c]->Draw("psame");

        leg0->AddEntry( ch_v2_PbPb[c]->vn_MergedEta,        "v_{2}{SP}",     "p" );
        leg0->AddEntry( ch_v2_PbPb[c]->vn_MergedEta_SubEvt, "v_{2}{SP,Sub}", "p" );
        leg0->AddEntry( vH.grSig_pT[2][1][c],               "v_{2}{4}", "p" );
        leg0->AddEntry( vH.grSig_V2sub4merge[c],         "v_{2}{4,Sub}", "p" );
        leg0->Draw();

        //
        c1->cd();
        hframe_pt->Draw();

        latexS.DrawLatexNDC(0.15, 0.99, "#bf{CMS}");
        latexS.DrawLatexNDC(0.75, 0.99, "PbPb 5.02 TeV");
        latexS.DrawLatexNDC(0.25, 0.90, (centBins[c]+ " K_{S}^{0}").c_str());

        TLegend * leg1 = new TLegend(0.68, 0.71, 0.90, 0.93);
        leg1->SetFillColor(kWhite);
        leg1->SetTextFont(42);
        leg1->SetTextSize(0.05);
        leg1->SetBorderSize(0);

        Ks_v2_PbPb_Sig[c]->vn_MergedEta->SetMarkerStyle(kOpenSquare);
        Ks_v2_PbPb_Sig[c]->vn_MergedEta->SetMarkerColor(kBlack);
        Ks_v2_PbPb_Sig[c]->vn_MergedEta->SetLineColor  (kBlack);
        Ks_v2_PbPb_Sig[c]->vn_MergedEta->SetMarkerSize(2.);

        Ks_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt->SetMarkerStyle(kOpenCircle);
        Ks_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt->SetMarkerColor(kRed);
        Ks_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt->SetLineColor  (kRed);
        Ks_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt->SetMarkerSize(2.);

        vKs.grSig_pT[2][1][c]->SetMarkerStyle(kOpenSquare);
        vKs.grSig_pT[2][1][c]->SetMarkerColor(kBlue);
        vKs.grSig_pT[2][1][c]->SetLineColor  (kBlue);
        vKs.grSig_pT[2][1][c]->SetMarkerSize(2.);

        vKs.grSig_V2sub4merge[c]->SetMarkerStyle(kOpenCircle);
        vKs.grSig_V2sub4merge[c]->SetMarkerColor(kGreen+2);
        vKs.grSig_V2sub4merge[c]->SetLineColor  (kGreen+2);
        vKs.grSig_V2sub4merge[c]->SetMarkerSize(2.);

        Ks_v2_PbPb_Sig[c]->vn_MergedEta       ->Draw("psame");
        Ks_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt->Draw("psame");
        vKs.grSig_pT[2][1][c]->Draw("psame");
        vKs.grSig_V2sub4merge[c]->Draw("psame");

        leg1->AddEntry( Ks_v2_PbPb_Sig[c]->vn_MergedEta,        "v_{2}{SP}",     "p" );
        leg1->AddEntry( Ks_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt, "v_{2}{SP,Sub}", "p" );
        leg1->AddEntry( vKs.grSig_pT[2][1][c],               "v_{2}{4}", "p" );
        leg1->AddEntry( vKs.grSig_V2sub4merge[c],         "v_{2}{4,Sub}", "p" );
        leg1->Draw();

        //
        c2->cd();
        hframe_pt->Draw();

        latexS.DrawLatexNDC(0.15, 0.99, "#bf{CMS}");
        latexS.DrawLatexNDC(0.75, 0.99, "PbPb 5.02 TeV");
        latexS.DrawLatexNDC(0.25, 0.90, (centBins[c]+ " #Lambda").c_str());

        TLegend * leg2 = new TLegend(0.68, 0.71, 0.90, 0.93);
        leg2->SetFillColor(kWhite);
        leg2->SetTextFont(42);
        leg2->SetTextSize(0.05);
        leg2->SetBorderSize(0);

        Lm_v2_PbPb_Sig[c]->vn_MergedEta->SetMarkerStyle(kOpenSquare);
        Lm_v2_PbPb_Sig[c]->vn_MergedEta->SetMarkerColor(kBlack);
        Lm_v2_PbPb_Sig[c]->vn_MergedEta->SetLineColor  (kBlack);
        Lm_v2_PbPb_Sig[c]->vn_MergedEta->SetMarkerSize(2.);

        Lm_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt->SetMarkerStyle(kOpenCircle);
        Lm_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt->SetMarkerColor(kRed);
        Lm_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt->SetLineColor  (kRed);
        Lm_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt->SetMarkerSize(2.);

        vLm.grSig_pT[2][1][c]->SetMarkerStyle(kOpenSquare);
        vLm.grSig_pT[2][1][c]->SetMarkerColor(kBlue);
        vLm.grSig_pT[2][1][c]->SetLineColor  (kBlue);
        vLm.grSig_pT[2][1][c]->SetMarkerSize(2.);

        vLm.grSig_V2sub4merge[c]->SetMarkerStyle(kOpenCircle);
        vLm.grSig_V2sub4merge[c]->SetMarkerColor(kGreen+2);
        vLm.grSig_V2sub4merge[c]->SetLineColor  (kGreen+2);
        vLm.grSig_V2sub4merge[c]->SetMarkerSize(2.);

        Lm_v2_PbPb_Sig[c]->vn_MergedEta       ->Draw("psame");
        Lm_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt->Draw("psame");
        vLm.grSig_pT[2][1][c]->Draw("psame");
        vLm.grSig_V2sub4merge[c]->Draw("psame");

        leg2->AddEntry( Lm_v2_PbPb_Sig[c]->vn_MergedEta,        "v_{2}{SP}",     "p" );
        leg2->AddEntry( Lm_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt, "v_{2}{SP,Sub}", "p" );
        leg2->AddEntry( vLm.grSig_pT[2][1][c],               "v_{2}{4}", "p" );
        leg2->AddEntry( vLm.grSig_V2sub4merge[c],         "v_{2}{4,Sub}", "p" );
        leg2->Draw();

        //
        cR->cd();
        hframeS_ratio->Draw();
        line1.Draw();

        latexS.DrawLatexNDC(0.15, 0.99, "#bf{CMS}");
        latexS.DrawLatexNDC(0.75, 0.99, "PbPb 5.02 TeV");
        latexS.DrawLatexNDC(0.25, 0.90, (centBins[c]).c_str());

        auto * gChRatio     = getRatio( vH.grSig_V2sub4merge[c], vH.grSig_pT[2][1][c] );
        auto * gKsRatio     = getRatio( vKs.grSig_V2sub4merge[c], vKs.grSig_pT[2][1][c] );
        auto * gLmRatio     = getRatio( vLm.grSig_V2sub4merge[c], vLm.grSig_pT[2][1][c] );

        auto * gChRatioSP   = getRatio( ch_v2_PbPb[c]->vn_MergedEta_SubEvt, ch_v2_PbPb[c]->vn_MergedEta );
        auto * gKsRatioSP   = getRatio( Ks_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt, Ks_v2_PbPb_Sig[c]->vn_MergedEta );
        auto * gLmRatioSP   = getRatio( Lm_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt, Lm_v2_PbPb_Sig[c]->vn_MergedEta );

        gChRatio->SetMarkerStyle(kOpenCircle);
        gChRatio->SetMarkerColor(kBlack);
        gChRatio->SetLineColor  (kBlack);
        gChRatio->SetMarkerSize(2.);

        gKsRatio->SetMarkerStyle(kOpenCircle);
        gKsRatio->SetMarkerColor(kBlue);
        gKsRatio->SetLineColor  (kBlue);
        gKsRatio->SetMarkerSize(2.);

        gLmRatio->SetMarkerStyle(kOpenCircle);
        gLmRatio->SetMarkerColor(kRed);
        gLmRatio->SetLineColor  (kRed);
        gLmRatio->SetMarkerSize(2.);

        gChRatioSP->SetMarkerStyle(kOpenSquare);
        gChRatioSP->SetMarkerColor(kBlack);
        gChRatioSP->SetLineColor  (kBlack);
        gChRatioSP->SetMarkerSize(2.);

        gKsRatioSP->SetMarkerStyle(kOpenSquare);
        gKsRatioSP->SetMarkerColor(kBlue);
        gKsRatioSP->SetLineColor  (kBlue);
        gKsRatioSP->SetMarkerSize(2.);

        gLmRatioSP->SetMarkerStyle(kOpenSquare);
        gLmRatioSP->SetMarkerColor(kRed);
        gLmRatioSP->SetLineColor  (kRed);
        gLmRatioSP->SetMarkerSize(2.);

        gChRatio  ->Draw("psame");
        gKsRatio  ->Draw("psame");
        gLmRatio  ->Draw("psame");

        gChRatioSP->Draw("psame");
        gKsRatioSP->Draw("psame");
        gLmRatioSP->Draw("psame");

        TLegend * legR = new TLegend(0.40, 0.61, 0.70, 0.93);
        legR->SetFillColor(kWhite);
        legR->SetTextFont(42);
        legR->SetTextSize(0.05);
        legR->SetBorderSize(0);

        legR->AddEntry(gChRatioSP, "SP: Ch", "p");
        legR->AddEntry(gKsRatioSP, "SP: K_{S}^{0}", "p");
        legR->AddEntry(gLmRatioSP, "SP: #Lambda", "p");

        legR->AddEntry(gChRatio,   "Cumu: Ch", "p");
        legR->AddEntry(gKsRatio,   "Cumu: K_{S}^{0}", "p");
        legR->AddEntry(gLmRatio,   "Cumu: #Lambda", "p");

        legR->Draw();
        //
        c0->SaveAs(Form("PbPb2018_H_Sub_%i.pdf", c));
        c1->SaveAs(Form("PbPb2018_Ks_Sub_%i.pdf", c));
        c2->SaveAs(Form("PbPb2018_Lm_Sub_%i.pdf", c));
        cR->SaveAs(Form("PbPb2018_SubRatio_%i.pdf", c));
    }

}
