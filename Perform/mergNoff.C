
void mergNoff()
{
//	TFile * f = new TFile("PbPb15_V0_ppRecoGMO567_v4.root");
	TFile * f = new TFile("PbPb15_V0_ppRecoGMO567_rap_v5.root");

//	TFile * fsave = new TFile("PbPb15_V0_ppRecoGMO567_v4_NoffAll.root", "recreate");
	TFile * fsave = new TFile("PbPb15_V0_ppRecoGMO567_rap_v5_NoffAll.root", "recreate");

	fsave->mkdir("vectKsMassNAll");
	fsave->cd("vectKsMassNAll");
	for ( int i = 0; i < 13; i++ ) {
		TH3D * h3D120 = (TH3D*)f->Get(Form("vectKsMassN120/h3DPhi_%i", i));
		TH3D * h3D150 = (TH3D*)f->Get(Form("vectKsMassN150/h3DPhi_%i", i));
		TH3D * h3D185 = (TH3D*)f->Get(Form("vectKsMassN185/h3DPhi_%i", i));
		TH3D * h3D250 = (TH3D*)f->Get(Form("vectKsMassN250/h3DPhi_%i", i));
		h3D120->Add(h3D150);
		h3D120->Add(h3D185);
		h3D120->Add(h3D250);
		h3D120->Write();

	}
	fsave->cd("/");
	fsave->mkdir("vectLmMassNAll");
	fsave->cd("vectLmMassNAll");
	for ( int i = 0; i < 13; i++ ) {
		TH3D * h3D120 = (TH3D*)f->Get(Form("vectLmMassN120/h3DPhi_%i", i));
		TH3D * h3D150 = (TH3D*)f->Get(Form("vectLmMassN150/h3DPhi_%i", i));
		TH3D * h3D185 = (TH3D*)f->Get(Form("vectLmMassN185/h3DPhi_%i", i));
		TH3D * h3D250 = (TH3D*)f->Get(Form("vectLmMassN250/h3DPhi_%i", i));
		h3D120->Add(h3D150);
		h3D120->Add(h3D185);
		h3D120->Add(h3D250);
		h3D120->Write();
	}
}
