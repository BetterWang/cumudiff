#include "label.h"
#include "noff.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TH1.h"
#include "TGraphErrors.h"
#include "TMultiGraph.h"
#include "../../style.h"
#include "HIN-14-002.h"


void genPlot(int s1 = 1)
{
	TFile *f = new TFile(Form("%s/outputE.root", ftxt[s1]));

	int NCent = NCent8TeV4;

	double dVp[7][4][24][20] = {};
	double eVp[7][4][24][20] = {};

	double dVpGap[7][24][20] = {};
	double eVpGap[7][24][20] = {};

	double dpVpGap[7][24][20] = {};
	double epVpGap[7][24][20] = {};

    double dVsub2pos[24][20] = {};
    double dVsub2neg[24][20] = {};
    double dVsub2[24][20] = {};
    double dVsub4pos[24][20] = {};
    double dVsub4neg[24][20] = {};
    double dVsub4[24][20] = {};

    double eVsub2pos[24][20] = {};
    double eVsub2neg[24][20] = {};
    double eVsub2[24][20] = {};
    double eVsub4pos[24][20] = {};
    double eVsub4neg[24][20] = {};
    double eVsub4[24][20] = {};

	HIN_14_002();
	for ( int n = 2; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			for ( int i = 0; i < 24; i++ ) {
				TH1D * h = (TH1D*) f->Get(Form("hVp%i%i_%i", n, np, i));
				for ( int c = 0; c < 20; c++ ) {
					dVp[n][np][i][c] = h->GetBinContent(c+1);
					eVp[n][np][i][c] = h->GetBinError(c+1);
				}
			}
		}
		for ( int i = 0; i < 24; i++ ) {
			TH1D * h = (TH1D*) f->Get(Form("hVpGap%i_%i", n, i));
			TH1D * h2= (TH1D*) f->Get(Form("hpVpGap%i_%i", n, i));
			for ( int c = 0; c < 20; c++ ) {
				dVpGap[n][i][c] = h->GetBinContent(c+1);
				eVpGap[n][i][c] = h->GetBinError(c+1);

				dpVpGap[n][i][c] = h2->GetBinContent(c+1);
				epVpGap[n][i][c] = h2->GetBinError(c+1);
			}
		}
	}
    for ( int i = 0; i < 24; i++ ) {
        TH1D * h2p = (TH1D*) f->Get(Form("hpVsub2pos%i", i));
        TH1D * h2n = (TH1D*) f->Get(Form("hpVsub2neg%i", i));
        TH1D * h4p = (TH1D*) f->Get(Form("hpVsub4pos%i", i));
        TH1D * h4n = (TH1D*) f->Get(Form("hpVsub4neg%i", i));
        if ( !h2p ) continue;
        for ( int c = 0; c < 20; c++ ) {
            dVsub2pos[i][c] = h2p->GetBinContent( c+1 );
            dVsub2neg[i][c] = h2n->GetBinContent( c+1 );
            dVsub4pos[i][c] = h4p->GetBinContent( c+1 );
            dVsub4neg[i][c] = h4n->GetBinContent( c+1 );

            dVsub2[i][c] = (dVsub2pos[i][c] + dVsub2neg[i][c])/2.;
            dVsub4[i][c] = (dVsub4pos[i][c] + dVsub4neg[i][c])/2.;

            eVsub2pos[i][c] = h2p->GetBinError( c+1 );
            eVsub2neg[i][c] = h2n->GetBinError( c+1 );
            eVsub4pos[i][c] = h4p->GetBinError( c+1 );
            eVsub4neg[i][c] = h4n->GetBinError( c+1 );

            eVsub2[i][c] = sqrt(eVsub2pos[i][c]*eVsub2pos[i][c] + eVsub2neg[i][c]*eVsub2neg[i][c])/2.;
            eVsub4[i][c] = sqrt(eVsub4pos[i][c]*eVsub4pos[i][c] + eVsub4neg[i][c]*eVsub4neg[i][c])/2.;
        }
    }

	TGraphErrors * grV0pT[7][4][20] = {};
	TGraphErrors * grV0pTGap[7][20] = {};
	TGraphErrors * grpTGap[7][20] = {};

	for ( int n = 2; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			for ( int c = 0; c < NCent; c++ ) {
				double y[24] = {};
				double e[24] = {};
				for ( int ipt = 0; ipt < NpT; ipt++ ) {
					y[ipt] = dVp[n][np][ipt][c];
					e[ipt] = eVp[n][np][ipt][c];
				}
				grV0pT[n][np][c] = new TGraphErrors(NpT, pTX, y, 0, e);
			}
		}
		for ( int c = 0; c < NCent; c++ ) {
			double y[24] = {};
			double e[24] = {};
			for ( int ipt = 0; ipt < NpT; ipt++ ) {
				y[ipt] = dVpGap[n][ipt][c];
				e[ipt] = eVpGap[n][ipt][c];
			}
			grV0pTGap[n][c] = new TGraphErrors(NpT, pTX, y, 0, e);
		}

		for ( int c = 0; c < NCent; c++ ) {
			double y[24] = {};
			double e[24] = {};
			for ( int ipt = 0; ipt < NpT; ipt++ ) {
				y[ipt] = dpVpGap[n][ipt][c];
				e[ipt] = epVpGap[n][ipt][c];
			}
			grpTGap[n][c] = new TGraphErrors(NpT, pTX, y, 0, e);
		}
	}

	for ( int n = 2; n < 7; n++ ) {
		for ( int c = 0; c < NCent; c++ ) {
			grV0pTGap[n][c]->SetMarkerStyle(kOpenCircle);
			grV0pTGap[n][c]->SetMarkerColor(kRed);
			grV0pTGap[n][c]->SetLineColor(kRed);

			grpTGap[n][c]->SetMarkerStyle(kOpenSquare);
			grpTGap[n][c]->SetMarkerColor(kBlack);
			grpTGap[n][c]->SetLineColor(kBlack);

			grV0pT[n][0][c]->SetMarkerStyle(kFullCircle);
			grV0pT[n][0][c]->SetMarkerColor(kRed);
			grV0pT[n][0][c]->SetLineColor(kRed);

			grV0pT[n][1][c]->SetMarkerStyle(kFullSquare);
			grV0pT[n][1][c]->SetMarkerColor(kBlue);
			grV0pT[n][1][c]->SetLineColor(kBlue);

			grV0pT[n][2][c]->SetMarkerStyle(kOpenCross);
			grV0pT[n][2][c]->SetMarkerColor(kBlack);
			grV0pT[n][2][c]->SetLineColor(kBlack);

			grV0pT[n][3][c]->SetMarkerStyle(kOpenStar);
			grV0pT[n][3][c]->SetMarkerColor(kGreen);
			grV0pT[n][3][c]->SetLineColor(kGreen);
		}
	}

	TH2D * hframe_pt = new TH2D("hframe_pt", "", 1, 0, 10, 1, 0, 0.35);
	InitHist(hframe_pt, "p_{T} (GeV/c)", "v_{n}");
	TCanvas * cT = MakeCanvas("cT", "cT", 600, 500);

	for ( int n = 2; n < 7; n++ ) {
		hframe_pt->GetYaxis()->SetTitle(Form("v_{%i}",n));
		for ( int c = 6; c < 11; c++ ) {
			hframe_pt->Draw();

			TLegend * legPt = new TLegend(0.2, 0.7, 0.55, 0.9);
			legPt->SetFillColor(kWhite);
			legPt->SetTextFont(42);
			legPt->SetTextSize(0.03);
			legPt->SetBorderSize(0);

			grpTGap[n][c]->Draw("psame");
			grV0pTGap[n][c]->Draw("psame");
			grV0pT[n][1][c]->Draw("psame");
//			grV0pT[n][2][c]->Draw("psame");
//			grV0pT[n][3][c]->Draw("psame");

			legPt->AddEntry(grpTGap[n][c], Form("v_{%i}{2, |#Delta#eta|>2} h#pm", n), "p");
			legPt->AddEntry(grV0pTGap[n][c], Form("v_{%i}{2, |#Delta#eta|>2}", n), "p");
			legPt->AddEntry(grV0pT[n][1][c], Form("v_{%i}{4}", n), "p");
//			legPt->AddEntry(grV0pT[n][2][c], Form("v_{%i}{6}", n), "p");
//			legPt->AddEntry(grV0pT[n][3][c], Form("v_{%i}{8}", n), "p");

			if ( isKs(PID[s1]) ) {
				if ( isPA(PID[s1]) and mgr_pPb_Ks_v22[c] and n==2 ) {
					mgr_pPb_Ks_v22[c]->Draw("psame");
					legPt->AddEntry(mgr_pPb_Ks_v22[c], Form("HIN14002 v_{%i}{2, |#Delta#eta|>2}", n), "p");
				}
				if ( not isPA(PID[s1]) and mgr_PbPb_Ks_v22[c] and n==2 ) {
					mgr_PbPb_Ks_v22[c]->Draw("psame");
					legPt->AddEntry(mgr_PbPb_Ks_v22[c], Form("HIN14002 v_{%i}{2, |#Delta#eta|>2}", n), "p");
				}
			}

			if ( isLambda(PID[s1]) ) {
				if ( isPA(PID[s1]) and mgr_pPb_Lambda_v22[c] and n==2 ) {
					mgr_pPb_Lambda_v22[c]->Draw("psame");
					legPt->AddEntry(mgr_pPb_Lambda_v22[c], Form("HIN14002 v_{%i}{2, |#Delta#eta|>2}", n), "p");
				}
				if ( not isPA(PID[s1]) and mgr_PbPb_Lambda_v22[c] and n==2 ) {
					mgr_PbPb_Lambda_v22[c]->Draw("psame");
					legPt->AddEntry(mgr_PbPb_Lambda_v22[c], Form("HIN14002 v_{%i}{2, |#Delta#eta|>2}", n), "p");
				}
			}

			legPt->Draw();

			cT->SaveAs(Form("%s/cPt_%i_%i.pdf", ftxt[s1],n, c));
			delete legPt;
		}
	}

    TGraphErrors * grpTV2sub2pos[20];
    TGraphErrors * grpTV2sub4pos[20];
    TGraphErrors * grpTV2sub2neg[20];
    TGraphErrors * grpTV2sub4neg[20];

    TGraphErrors * grpTV2sub2[20];
    TGraphErrors * grpTV2sub4[20];

    for ( int c = 0; c < NCent; c++ ) {
        double y[24] = {};
        double e[24] = {};
        for ( int ipt = 0; ipt < NpT; ipt++ ) {
            y[ipt] = dVsub2[ipt][c];
            e[ipt] = eVsub2[ipt][c];
        }
        grpTV2sub2[c] = new TGraphErrors(NpT, pTX, y, 0, e);
        grpTV2sub2[c]->SetMarkerStyle(kOpenCircle);
        grpTV2sub2[c]->SetMarkerColor(kRed);
        grpTV2sub2[c]->SetLineColor  (kRed);

        for ( int ipt = 0; ipt < NpT; ipt++ ) {
            y[ipt] = dVsub4[ipt][c];
            e[ipt] = eVsub4[ipt][c];
        }
        grpTV2sub4[c] = new TGraphErrors(NpT, pTX, y, 0, e);
        grpTV2sub4[c]->SetMarkerStyle(kOpenCircle);
        grpTV2sub4[c]->SetMarkerColor(kBlue);
        grpTV2sub4[c]->SetLineColor  (kBlue);

        for ( int ipt = 0; ipt < NpT; ipt++ ) {
            y[ipt] = dVsub2pos[ipt][c];
            e[ipt] = eVsub2pos[ipt][c];
        }
        grpTV2sub2pos[c] = new TGraphErrors(NpT, pTX, y, 0, e);
        grpTV2sub2pos[c]->SetMarkerStyle(kOpenCircle);
        grpTV2sub2pos[c]->SetMarkerColor(kRed);
        grpTV2sub2pos[c]->SetLineColor  (kRed);

        for ( int ipt = 0; ipt < NpT; ipt++ ) {
            y[ipt] = dVsub2neg[ipt][c];
            e[ipt] = eVsub2neg[ipt][c];
        }
        grpTV2sub2neg[c] = new TGraphErrors(NpT, pTX, y, 0, e);
        grpTV2sub2neg[c]->SetMarkerStyle(kOpenCircle);
        grpTV2sub2neg[c]->SetMarkerColor(kBlue);
        grpTV2sub2neg[c]->SetLineColor  (kBlue);

        for ( int ipt = 0; ipt < NpT; ipt++ ) {
            y[ipt] = dVsub4pos[ipt][c];
            e[ipt] = eVsub4pos[ipt][c];
        }
        grpTV2sub4pos[c] = new TGraphErrors(NpT, pTX, y, 0, e);
        grpTV2sub4pos[c]->SetMarkerStyle(kOpenSquare);
        grpTV2sub4pos[c]->SetMarkerColor(kRed);
        grpTV2sub4pos[c]->SetLineColor  (kRed);

        for ( int ipt = 0; ipt < NpT; ipt++ ) {
            y[ipt] = dVsub4neg[ipt][c];
            e[ipt] = eVsub4neg[ipt][c];
        }
        grpTV2sub4neg[c] = new TGraphErrors(NpT, pTX, y, 0, e);
        grpTV2sub4neg[c]->SetMarkerStyle(kOpenSquare);
        grpTV2sub4neg[c]->SetMarkerColor(kBlue);
        grpTV2sub4neg[c]->SetLineColor  (kBlue);
    }

    for ( int c = 6; c < 11; c++ ) {
        cT->cd();
		hframe_pt->GetYaxis()->SetTitle(Form("v_{%i}",2));
        hframe_pt->Draw();

        TLegend * legPt = new TLegend(0.2, 0.7, 0.55, 0.9);
        legPt->SetFillColor(kWhite);
        legPt->SetTextFont(42);
        legPt->SetTextSize(0.03);
        legPt->SetBorderSize(0);

        //grpTV2sub2pos[c]->Draw("psame");
        //grpTV2sub2neg[c]->Draw("psame");
        //grpTV2sub4pos[c]->Draw("psame");
        //grpTV2sub4neg[c]->Draw("psame");
        grpTV2sub2[c]->Draw("psame");
        grpTV2sub4[c]->Draw("psame");

        //legPt->AddEntry(grpTV2sub2pos[c], Form("v_{2}{2, 2sub #eta>0}"), "p");
        //legPt->AddEntry(grpTV2sub2neg[c], Form("v_{2}{2, 2sub #eta<0}"), "p");
        //legPt->AddEntry(grpTV2sub4pos[c], Form("v_{2}{4, 2sub #eta>0}"), "p");
        //legPt->AddEntry(grpTV2sub4neg[c], Form("v_{2}{4, 2sub #eta<0}"), "p");
        legPt->AddEntry(grpTV2sub2[c], Form("v_{2}{2, 2sub}"), "p");
        legPt->AddEntry(grpTV2sub4[c], Form("v_{2}{4, 2sub}"), "p");

        legPt->Draw("same");
        cT->SaveAs(Form("%s/cPtV2sub_%i.pdf", ftxt[s1], c));
    }

	TFile * fwrite = new TFile(Form("%s/outGraph.root", ftxt[s1]), "recreate");
	for ( int n = 2; n < 7; n++ ) {
		for ( int c = 0; c < NCent; c++ ) {
			for ( int np = 0; np < 4; np++ ) {
				grV0pT[n][np][c]->Write(Form("grV0pT%i%i_%i", n, np, c));
			}
			grV0pTGap[n][c]->Write(Form("grV0pTGap%i_%i", n, c));
			grpTGap[n][c]->Write(Form("grpTGap%i_%i", n, c));
		}
	}
    for ( int c = 0; c < NCent; c++ ) {
        grpTV2sub2pos[c]->Write(Form("grpTV2sub2pos%i", c));
        grpTV2sub2neg[c]->Write(Form("grpTV2sub2neg%i", c));
        grpTV2sub4pos[c]->Write(Form("grpTV2sub4pos%i", c));
        grpTV2sub4neg[c]->Write(Form("grpTV2sub4neg%i", c));

        grpTV2sub2[c]->Write(Form("grpTV2sub2%i", c));
        grpTV2sub4[c]->Write(Form("grpTV2sub4%i", c));
    }
}
