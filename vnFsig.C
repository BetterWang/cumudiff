

TGraphErrors* getSigVn(TGraphErrors*, TGraphErrors*, TH1D*);


void vnFsig(string sig = "pPb_Ks.root", string sb = "pPb_Ks_SB.root", string strSave = "test.root")
{
	TFile * fsig = new TFile(sig.c_str());
	TFile * fsb  = new TFile(sb.c_str());

	TGraphErrors * grSig_pT[7][4][20] = {};
	TGraphErrors * grSig_pTGap[7][20] = {};
	TGraphErrors * grH_pTGap[7][20] = {};

	TGraphErrors * grSB_pT[7][4][20] = {};
	TGraphErrors * grSB_pTGap[7][20] = {};

	TGraphErrors * grPure_pT[7][4][20] = {};
	TGraphErrors * grPure_pTGap[7][20] = {};

	for ( int n = 2; n < 7; n++ ) {
		for ( int c = 6; c < 10; c++ ) {
			grSig_pTGap[n][c] = (TGraphErrors*) fsig->Get(Form("grV0Gap%i_%i", n, c));
			grSB_pTGap[n][c]  = (TGraphErrors*) fsb ->Get(Form("grV0Gap%i_%i", n, c));
			grH_pTGap[n][c]   = (TGraphErrors*) fsig->Get(Form("grHV0Gap%i_%i", n, c));
			for ( int np = 0; np < 4; np++ ) {
				grSig_pT[n][np][c] = (TGraphErrors*) fsig->Get(Form("grV0%i%i_%i", n, np, c));
				grSB_pT[n][np][c]  = (TGraphErrors*) fsb ->Get(Form("grV0%i%i_%i", n, np, c));
			}
		}
	}

	bool bPbPb = (sig.find("pPb") == std::string::npos);
	bool bKs   = (sig.find("Lm") == std::string::npos);

	TFile * fFsig = new TFile("Fsig.root");
	TH1D * hSig[20];
	if ( bPbPb ) {
		if ( bKs ) {
			hSig[6] = (TH1D*) fFsig->Get("PbPb15_V0_rap_eta1_NoffAll/vectKsMassNAll");
			hSig[7] = (TH1D*) fFsig->Get("PbPb15_V0_rap_eta1_NoffAll/vectKsMassNAll");
			hSig[8] = (TH1D*) fFsig->Get("PbPb15_V0_rap_eta1_NoffAll/vectKsMassNAll");
			hSig[9] = (TH1D*) fFsig->Get("PbPb15_V0_rap_eta1_NoffAll/vectKsMassNAll");
		} else {
			hSig[6] = (TH1D*) fFsig->Get("PbPb15_V0_rap_eta1_NoffAll/vectLmMassNAll");
			hSig[7] = (TH1D*) fFsig->Get("PbPb15_V0_rap_eta1_NoffAll/vectLmMassNAll");
			hSig[8] = (TH1D*) fFsig->Get("PbPb15_V0_rap_eta1_NoffAll/vectLmMassNAll");
			hSig[9] = (TH1D*) fFsig->Get("PbPb15_V0_rap_eta1_NoffAll/vectLmMassNAll");
		}
	} else {
		if ( bKs ) {
			hSig[6] = (TH1D*) fFsig->Get("pPb_V0_HM0_eta1_merge/vectKsMassN120");
			hSig[7] = (TH1D*) fFsig->Get("pPb_V0_HM0_eta1_merge/vectKsMassN150");
			hSig[8] = (TH1D*) fFsig->Get("pPb_V0_HM123456_eta1_merge/vectKsMassN185");
			hSig[9] = (TH1D*) fFsig->Get("pPb_V0_HM7_eta1_merge/vectKsMassN250");
		} else {
			hSig[6] = (TH1D*) fFsig->Get("pPb_V0_HM0_eta1_merge/vectLmMassN120");
			hSig[7] = (TH1D*) fFsig->Get("pPb_V0_HM0_eta1_merge/vectLmMassN150");
			hSig[8] = (TH1D*) fFsig->Get("pPb_V0_HM123456_eta1_merge/vectLmMassN185");
			hSig[9] = (TH1D*) fFsig->Get("pPb_V0_HM7_eta1_merge/vectLmMassN250");
		}
	}

	for ( int n = 2; n < 7; n++ ) {
		for ( int c = 6; c < 10; c++ ) {
			grPure_pTGap[n][c] = getSigVn(grSig_pTGap[n][c], grSB_pTGap[n][c], hSig[c]);

			for ( int np = 0; np < 4; np++ ) {
				grPure_pT[n][np][c] = getSigVn(grSig_pT[n][np][c], grSB_pT[n][np][c], hSig[c]);
			}
		}
	}

	TFile * fsave = new TFile(strSave.c_str(), "recreate");
	for ( int n = 2; n < 7; n++ ) {
		for ( int c = 6; c < 10; c++ ) {
			grSig_pTGap[n][c]->Write(Form("grObs_pTGap%i_%i", n, c));
			grSB_pTGap[n][c] ->Write(Form("grBkg_pTGap%i_%i", n, c));
			grPure_pTGap[n][c]->Write(Form("grSig_pTGap%i_%i", n, c));
			grH_pTGap[n][c] ->Write(Form("grH_pTGap%i_%i", n, c));
			for ( int np = 0; np < 4; np++ ) {
				grPure_pT[n][np][c]->Write(Form("grSig_pT%i_%i_%i", n, np, c));
				grSig_pT[n][np][c]->Write(Form("grObs_pT%i_%i_%i", n, np, c));
				grSB_pT[n][np][c]->Write(Form("grBkg_pT%i_%i_%i", n, np, c));
			}
		}
	}
}




TGraphErrors* getSigVn(TGraphErrors* grSig, TGraphErrors* grSB, TH1D* hsig)
{
	TGraphErrors * ret = new TGraphErrors(13);
	for ( int i = 0; i < 13; i++ ) {
		ret->GetX()[i] = grSig->GetX()[i];

		double obs = grSig->GetY()[i];
		double bkg = grSB->GetY()[i];
		double fsig = hsig->GetBinContent(i+1);
		double sig = ( obs - (1-fsig) * bkg ) / fsig;

		double eobs = grSig->GetEY()[i];
		double ebkg = grSB->GetEY()[i];

		double esig = sqrt( eobs*eobs + (1-fsig)*(1-fsig)*ebkg * ebkg ) / fsig;

		ret->GetY()[i] = sig;
		ret->GetEY()[i] = esig;
//		cout << "--> i = " << i << endl;
//		cout << " obs = " << obs << endl;
//		cout << " bkg = " << bkg << endl;
//		cout << " fsig = " << fsig << endl;
//		cout << " sig = " << sig << endl;
//		cout << " eobs = " << eobs << endl;
//		cout << " ebkg = " << ebkg << endl;
//		cout << " esig = " << esig << endl;
	}

	return ret;
}




