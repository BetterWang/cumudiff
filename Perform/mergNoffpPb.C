
void mergNoffpPb()
{
	TFile * f0 = new TFile("pPb16_V0_HM0_merge.root");
	TFile * f1 = new TFile("pPb16_V0_HM123456_merge.root");
	TFile * f7 = new TFile("pPb16_V0_HM7_merge.root");

	TFile * fsave = new TFile("pPb16_V0_NoffAll_merge.root", "recreate");

	fsave->mkdir("vectKsMassNAll");
	fsave->cd("vectKsMassNAll");
	for ( int i = 0; i < 13; i++ ) {
		TH3D * h3D120 = (TH3D*)f0->Get(Form("vectKsMassN120/h3DPhi_%i", i));
		TH3D * h3D150 = (TH3D*)f0->Get(Form("vectKsMassN150/h3DPhi_%i", i));
		TH3D * h3D185 = (TH3D*)f1->Get(Form("vectKsMassN185/h3DPhi_%i", i));
		TH3D * h3D250 = (TH3D*)f7->Get(Form("vectKsMassN250/h3DPhi_%i", i));
		h3D120->Add(h3D150);
		h3D120->Add(h3D185);
		h3D120->Add(h3D250);
		h3D120->Write();
	}
	fsave->cd("/");
	fsave->mkdir("vectLmMassNAll");
	fsave->cd("vectLmMassNAll");
	for ( int i = 0; i < 13; i++ ) {
		TH3D * h3D120 = (TH3D*)f0->Get(Form("vectLmMassN120/h3DPhi_%i", i));
		TH3D * h3D150 = (TH3D*)f0->Get(Form("vectLmMassN150/h3DPhi_%i", i));
		TH3D * h3D185 = (TH3D*)f1->Get(Form("vectLmMassN185/h3DPhi_%i", i));
		TH3D * h3D250 = (TH3D*)f7->Get(Form("vectLmMassN250/h3DPhi_%i", i));
		h3D120->Add(h3D150);
		h3D120->Add(h3D185);
		h3D120->Add(h3D250);
		h3D120->Write();
	}
}
