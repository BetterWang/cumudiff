
struct MassHist {
	TH1D * hMass[13][5];
};

void GetHist(MassHist& hist, TFile* f, int color, bool norm = false)
{
	for ( int c = 0; c < 5; c++ ) {
		for ( int ipt = 0; ipt < 13; ipt++ ) {
			hist.hMass[ipt][c] = (TH1D*) f->Get(Form("hMass_%i_%i", ipt, c));
			hist.hMass[ipt][c]->SetLineColor(color);
			if ( norm ) {
				hist.hMass[ipt][c]->Scale(1./hist.hMass[ipt][c]->GetEntries());
			}
		}
	}
}

void
makePlot()
{
	string s = "10";
	bool bNorm = true;

	TFile * fstd   = new TFile( (string("../txt/PbPb2018v2_Perform/Lm_rap")+s+"_std.root").c_str() );
	TFile * ftest1 = new TFile( (string("../txt/PbPb2018v2_Perform/Lm_rap")+s+"_test1.root").c_str() );
	TFile * ftest2 = new TFile( (string("../txt/PbPb2018v2_Perform/Lm_rap")+s+"_test2.root").c_str() );
	TFile * ftest3 = new TFile( (string("../txt/PbPb2018v2_Perform/Lm_rap")+s+"_test3.root").c_str() );
	TFile * ftest4 = new TFile( (string("../txt/PbPb2018v2_Perform/Lm_rap")+s+"_test4.root").c_str() );
	TFile * ftest5 = new TFile( (string("../txt/PbPb2018v2_Perform/Lm_rap")+s+"_test5.root").c_str() );
	TFile * ftest6 = new TFile( (string("../txt/PbPb2018v2_Perform/Lm_rap")+s+"_test6.root").c_str() );
	TFile * ftest7 = new TFile( (string("../txt/PbPb2018v2_Perform/Lm_rap")+s+"_test7.root").c_str() );
	TFile * ftest8 = new TFile( (string("../txt/PbPb2018v2_Perform/Lm_rap")+s+"_test8.root").c_str() );
	TFile * ftight = new TFile( (string("../txt/PbPb2018v2_Perform/Lm_rap")+s+"_tight.root").c_str() );

	MassHist hstd;
	MassHist htest1;
	MassHist htest2;
	MassHist htest3;
	MassHist htest4;
	MassHist htest5;
	MassHist htest6;
	MassHist htest7;
	MassHist htest8;
	MassHist htight;
	GetHist( hstd,   fstd,   kBlack,   bNorm );
	GetHist( htest1, ftest1, kRed,     bNorm );
	GetHist( htest2, ftest2, kBlue,    bNorm );
	GetHist( htest3, ftest3, kGreen+2, bNorm );
	GetHist( htest4, ftest4, kCyan,    bNorm );
	GetHist( htest5, ftest5, kMagenta, bNorm );
	GetHist( htest6, ftest6, kRed,     bNorm );
	GetHist( htest7, ftest7, kGreen,   bNorm );
	GetHist( htest8, ftest8, kBlue,     bNorm );
	GetHist( htight, ftight, kOrange,  bNorm );

	TCanvas * c1 = new TCanvas("c1", "c1", 800, 600);
	for ( int c = 0; c < 5; c++ ) {
		for ( int ipt = 0; ipt < 13; ipt++ ) {
//			hstd.hMass[ipt][c]  ->Draw("hist");
			htight.hMass[ipt][c]->Draw("hist");
//			htight.hMass[ipt][c]->Draw("histsame");
			hstd.hMass[ipt][c]  ->Draw("histsame plc pmc");
			htest1.hMass[ipt][c]->Draw("histsame plc pmc");
			htest2.hMass[ipt][c]->Draw("histsame plc pmc");
			htest3.hMass[ipt][c]->Draw("histsame plc pmc");
			htest4.hMass[ipt][c]->Draw("histsame plc pmc");
			htest5.hMass[ipt][c]->Draw("histsame plc pmc");
			htest6.hMass[ipt][c]->Draw("histsame plc pmc");
			htest7.hMass[ipt][c]->Draw("histsame plc pmc");
			htest8.hMass[ipt][c]->Draw("histsame plc pmc");

			c1->SaveAs(Form("hMassTest%s_%s_%i_%i.pdf", s.c_str(), bNorm?"Norm":"", ipt, c));
		}
	}

}
