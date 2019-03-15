#include "../../../style.h"


void massPlot(string fname, string ss, double etaMin = -2.4, double etaMax = 2.4)
{
	TFile * f = new TFile(fname.c_str());
	TDirectory * dir = (TDirectory*) f->Get(ss.c_str());
	if ( dir == nullptr ) return;

	TCanvas * cMass = MakeCanvas("cMass", "cMass", 800, 600);
	for ( int i = 0; i < 13; i++ ) {
		TH3D * h3D = (TH3D*) f->Get(Form("%s/h3DPhi_%i", ss.c_str(), i));
		TAxis * aEta = h3D->GetZaxis();
		TH1D * hMass = (TH1D*) h3D->ProjectionX(Form("hMass_%i", i), 0, -1, aEta->FindBin(etaMin), aEta->FindBin(etaMax)-1 );
		hMass->Draw();
		cMass->SaveAs(Form("Mass_%s_%i.pdf", ss.c_str(), i));
	}

}
