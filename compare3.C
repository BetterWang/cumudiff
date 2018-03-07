#include "../../style.h"

void splitCanv(TCanvas * c);
void initHist(TH2D* h);

void compare3(string s1 = "pPb_Ks_SBPos.root", string s2 = "pPb_Ks_SBNeg.root", string s3 = "pPb_Ks_SB.root", string str_gr = "grV021_6", string fname = "comp_pPb_KsSB6_v24.pdf",
		string str_leg1 = "SBPos", string str_leg2 = "SBNeg", string str_leg3 = "SB",
		string str_ylabel = "v_2{4}")
{

	TFile * f1 = new TFile(s1.c_str());
	TFile * f2 = new TFile(s2.c_str());
	TFile * f3 = new TFile(s3.c_str());

	TGraphErrors * gr1 = (TGraphErrors*) f1->Get(str_gr.c_str());
	TGraphErrors * gr2 = (TGraphErrors*) f2->Get(str_gr.c_str());
	TGraphErrors * gr3 = (TGraphErrors*) f3->Get(str_gr.c_str());

	gr1->SetMarkerColor(kRed);
	gr1->SetLineColor(kRed);
	gr2->SetMarkerColor(kBlue);
	gr2->SetLineColor(kBlue);
	gr3->SetMarkerColor(kBlack);
	gr3->SetLineColor(kBlack);

	map<string, pair<double, double>> hrange{
		{"grV24", make_pair(0.01, 0.14)},
		{"grV2n", make_pair(0.01, 0.14)},
		{"grV26", make_pair(0.01, 0.14)},
		{"grV28", make_pair(0.01, 0.14)},
		{"grC22", make_pair(0.004, 0.0249)},
		{"grC24", make_pair(-0.000014, 0.0000119)},
		{"grC26", make_pair(-0.000000014, 0.000000199)},
		{"grC28", make_pair(-0.0000000024, 0.00000000119)},
		{"grC2n", make_pair(-0.000014, 0.0000119)},
		{"grC34", make_pair(-0.0000004, 0.0000007)},
		{"grC36", make_pair(-0.000000014, 0.000000199)},
		{"grC38", make_pair(-0.0000000024, 0.00000000119)},

		{"grV34", make_pair(0.00, 0.04)},
		{"grV3n", make_pair(0.00, 0.04)},
		{"grV36", make_pair(0.00, 0.04)},
		{"grV38", make_pair(0.00, 0.04)},
		{"grC3n", make_pair(-0.00000044, 0.0000019)},
		{"grV264", make_pair(0.8, 0.99)},
		{"grV286", make_pair(0.9, 1.1)},
	};
	if ( s1.find("PbPb") != string::npos ) {
		hrange = {
			{"grV22", make_pair(0.01, 0.19)},
			{"grV24", make_pair(0.01, 0.19)},
			{"grV2n", make_pair(0.01, 0.19)},
			{"grV26", make_pair(0.01, 0.19)},
			{"grV28", make_pair(0.01, 0.19)},
			{"grC22", make_pair(0.004, 0.0249)},
			{"grC24", make_pair(-0.000074, 0.0000499)},
			{"grC26", make_pair(-0.0000014, 0.00000699)},
			{"grC28", make_pair(-0.00000029, 0.000000499)},
			{"grC2n", make_pair(-0.000074, 0.0000499)},
			{"grC34", make_pair(-0.00000074, 0.0000019)},
			{"grC36", make_pair(-0.00000014, 0.000000699)},
			{"grC38", make_pair(-0.00000029, 0.000000499)},

			{"grV34", make_pair(0.00, 0.04)},
			{"grV3n", make_pair(0.00, 0.04)},
			{"grV36", make_pair(0.00, 0.04)},
			{"grV38", make_pair(0.00, 0.04)},
			{"grC3n", make_pair(-0.00000044, 0.0000019)},
			{"grV264", make_pair(0.9, 1.1)},
			{"grV286", make_pair(0.9, 1.1)},
		};
	}

	TCanvas * cT = MakeCanvas("cT", "cT", 600, 600);
	splitCanv(cT);

	TH2D * hframe = new TH2D("hframe", ";N_{trk}^{offline};v_{2}", 1, 0, 9, 1, 0, 0.35);
	hframe->SetYTitle(str_ylabel.c_str());
	initHist(hframe);
	TH2D * hframeR = new TH2D("hframeR", ";N_{trk}^{offline};Ratio", 1, 0, 9, 1, 0.91, 1.09);
	initHist(hframeR);

	TLegend * legPt = new TLegend(0.5, 0.7, 0.85, 0.9);
	legPt->SetFillColor(kWhite);
	legPt->SetTextFont(42);
	legPt->SetTextSize(0.06);
	legPt->SetBorderSize(0);

	legPt->AddEntry(gr1, str_leg1.c_str(), "p"); 
	legPt->AddEntry(gr2, str_leg2.c_str(), "p"); 
	legPt->AddEntry(gr3, str_leg3.c_str(), "p"); 

	TLine * l0 = new TLine(0, 0, 9, 0);
	cT->cd(1);
	hframe->Draw();
	l0->Draw();
	gr1->Draw("Psame");
	gr2->Draw("Psame");
	gr3->Draw("Psame");
	legPt->Draw();
	cT->cd(2);

	TGraphErrors * grR1 = (TGraphErrors*) gr1->Clone("grR1");
	TGraphErrors * grR2 = (TGraphErrors*) gr2->Clone("grR2");

	for ( int i = 0; i < grR1->GetN(); i++ ) {
		grR1->GetY()[i] = gr1->GetY()[i] / gr3->GetY()[i];
		grR1->GetEY()[i] = fabs( grR1->GetY()[i] * sqrt( (gr1->GetEY()[i]/gr1->GetY()[i])*(gr1->GetEY()[i]/gr1->GetY()[i]) + (gr3->GetEY()[i]/gr3->GetY()[i])*(gr3->GetEY()[i]/gr3->GetY()[i])
					- 2 * gr1->GetEY()[i] * gr3->GetEY()[i] /gr1->GetY()[i] / gr3->GetY()[i]
					) );
	}
	for ( int i = 0; i < grR2->GetN(); i++ ) {
		grR2->GetY()[i] = gr2->GetY()[i] / gr3->GetY()[i];
		grR2->GetEY()[i] = fabs( grR2->GetY()[i] * sqrt( (gr2->GetEY()[i]/gr2->GetY()[i])*(gr2->GetEY()[i]/gr2->GetY()[i]) + (gr3->GetEY()[i]/gr3->GetY()[i])*(gr3->GetEY()[i]/gr3->GetY()[i]) 
					- 2 * gr2->GetEY()[i] * gr3->GetEY()[i] /gr2->GetY()[i] / gr3->GetY()[i]
					) );
	}

	hframeR->Draw();
	grR1->Draw("Psame");
	grR2->Draw("Psame");

//	TF1 *fR1 = new TF1("fR1", "pol0", 100., 300.);
//	TF1 *fR2 = new TF1("fR2", "pol0", 100., 300.);
//	fR1->SetLineColor(grR1->GetMarkerColor());
//	fR2->SetLineColor(grR2->GetMarkerColor());
//	grR1->Fit(fR1, "E", "", 100, 300);
//	grR2->Fit(fR2, "E", "", 100, 300);

	cT->SaveAs(fname.c_str());
}

void splitCanv(TCanvas * c)
{
	if (!c) return;

	c->cd(0);
	TPad * p1 = new TPad("pad1", "", 0., 0.4, 1., 1.);
	p1->SetLeftMargin(0.15);
	p1->SetRightMargin(0.05);
	p1->SetBottomMargin(0.);
	p1->SetTopMargin(0.07);
	p1->Draw();
	p1->SetNumber(1);

	TPad * p2 = new TPad("pad2", "", 0., 0.0, 1., 0.4);
	p2->SetLeftMargin(0.15);
	p2->SetRightMargin(0.05);
	p2->SetBottomMargin(0.25);
	p2->SetTopMargin(0.);
	p2->SetGridy();
	p2->Draw();
	p2->SetNumber(2);
}

void initHist(TH2D * h)
{
	h->GetXaxis()->SetLabelFont(43);
	h->GetXaxis()->SetLabelSize(20);
	h->GetXaxis()->SetLabelOffset(0.02);
	h->GetXaxis()->SetTitleFont(43);
	h->GetXaxis()->SetTitleSize(22);
	h->GetXaxis()->CenterTitle();
	h->GetXaxis()->SetNdivisions(505);
	h->GetXaxis()->SetTickLength(0.03);
	h->GetXaxis()->SetTitleOffset(3);

	h->GetYaxis()->SetLabelFont(43);
	h->GetYaxis()->SetLabelSize(20);
	h->GetYaxis()->SetLabelOffset(0.02);
	h->GetYaxis()->SetTitleFont(43);
	h->GetYaxis()->SetTitleSize(26);
	h->GetYaxis()->CenterTitle();
	h->GetYaxis()->SetNdivisions(505);
	h->GetYaxis()->SetTickLength(0.03);
	h->GetYaxis()->SetTitleOffset(1.5);
}
