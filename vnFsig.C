

TGraphErrors* getSigVn(TGraphErrors*, TGraphErrors*, TH1D*);

TGraphErrors* dummy = new TGraphErrors(13);

void vnFsig(string sig = "pPb_Ks.root", string sb = "pPb_Ks_SB.root", string strSave = "test.root")
{
    for ( int i = 0; i < 13; i++ ) {
        dummy->GetX()[i] = 0.;
        dummy->GetY()[i] = 0.;
        dummy->GetEY()[i] = 99.;
    }

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

    TGraphErrors * grSigV2sub2[20] = {};
    TGraphErrors * grSBV2sub2[20] = {};
    TGraphErrors * grPureV2sub2[20] = {};

    TGraphErrors * grSigV2sub4[20] = {};
    TGraphErrors * grSBV2sub4[20] = {};
    TGraphErrors * grPureV2sub4[20] = {};

    TGraphErrors * grSigV2sub2pos[20] = {};
    TGraphErrors * grSBV2sub2pos[20] = {};
    TGraphErrors * grPureV2sub2pos[20] = {};

    TGraphErrors * grSigV2sub4pos[20] = {};
    TGraphErrors * grSBV2sub4pos[20] = {};
    TGraphErrors * grPureV2sub4pos[20] = {};

    TGraphErrors * grSigV2sub2neg[20] = {};
    TGraphErrors * grSBV2sub2neg[20] = {};
    TGraphErrors * grPureV2sub2neg[20] = {};

    TGraphErrors * grSigV2sub4neg[20] = {};
    TGraphErrors * grSBV2sub4neg[20] = {};
    TGraphErrors * grPureV2sub4neg[20] = {};

    for ( int c = 6; c < 10; c++ ) {
        grSigV2sub2[c] = (TGraphErrors*) fsig->Get(Form("grV0v2sub2_%i", c));
        grSBV2sub2[c]  = (TGraphErrors*) fsb ->Get(Form("grV0v2sub2_%i", c));

        grSigV2sub4[c] = (TGraphErrors*) fsig->Get(Form("grV0v2sub4_%i", c));
        grSBV2sub4[c]  = (TGraphErrors*) fsb ->Get(Form("grV0v2sub4_%i", c));

        grSigV2sub2pos[c] = (TGraphErrors*) fsig->Get(Form("grV0v2sub2pos_%i", c));
        grSBV2sub2pos[c]  = (TGraphErrors*) fsb ->Get(Form("grV0v2sub2pos_%i", c));

        grSigV2sub4pos[c] = (TGraphErrors*) fsig->Get(Form("grV0v2sub4pos_%i", c));
        grSBV2sub4pos[c]  = (TGraphErrors*) fsb ->Get(Form("grV0v2sub4pos_%i", c));

        grSigV2sub2neg[c] = (TGraphErrors*) fsig->Get(Form("grV0v2sub2neg_%i", c));
        grSBV2sub2neg[c]  = (TGraphErrors*) fsb ->Get(Form("grV0v2sub2neg_%i", c));

        grSigV2sub4neg[c] = (TGraphErrors*) fsig->Get(Form("grV0v2sub4neg_%i", c));
        grSBV2sub4neg[c]  = (TGraphErrors*) fsb ->Get(Form("grV0v2sub4neg_%i", c));
    }


	bool bPbPb = (sig.find("pPb") == std::string::npos);
	bool bCent = (sig.find("Cent") != std::string::npos);
	bool bCent2= (sig.find("Cent2") != std::string::npos);
	bool bKs   = (sig.find("Lm") == std::string::npos);

	TFile * fFsig = new TFile("Fsig.root");
	TH1D * hSig[20];
	if ( bPbPb ) {
		if ( bKs ) { // Ks
            if ( bCent ) {
                hSig[6] = (TH1D*) fFsig->Get("PbPb15_V0_rap_eta1_Cent_N185/vectKsMassN185");
                hSig[7] = (TH1D*) fFsig->Get("PbPb15_V0_rap_eta1_Cent_N185/vectKsMassN185");
                hSig[8] = (TH1D*) fFsig->Get("PbPb15_V0_rap_eta1_Cent_N185/vectKsMassN185");
                hSig[9] = (TH1D*) fFsig->Get("PbPb15_V0_rap_eta1_Cent_N185/vectKsMassN185");
            } else {
                hSig[6] = (TH1D*) fFsig->Get("PbPb15_V0_rap_eta1_NoffAll/vectKsMassNAll");
                hSig[7] = (TH1D*) fFsig->Get("PbPb15_V0_rap_eta1_NoffAll/vectKsMassNAll");
                hSig[8] = (TH1D*) fFsig->Get("PbPb15_V0_rap_eta1_NoffAll/vectKsMassNAll");
                hSig[9] = (TH1D*) fFsig->Get("PbPb15_V0_rap_eta1_NoffAll/vectKsMassNAll");
            }
		} else { // Lm
            if ( bCent ) {
                hSig[6] = (TH1D*) fFsig->Get("PbPb15_V0_rap_eta1_Cent_N185/vectLmMassN185");
                hSig[7] = (TH1D*) fFsig->Get("PbPb15_V0_rap_eta1_Cent_N185/vectLmMassN185");
                hSig[8] = (TH1D*) fFsig->Get("PbPb15_V0_rap_eta1_Cent_N185/vectLmMassN185");
                hSig[9] = (TH1D*) fFsig->Get("PbPb15_V0_rap_eta1_Cent_N185/vectLmMassN185");
            } if ( bCent2 ) {
                hSig[6] = (TH1D*) fFsig->Get("PbPb15_V0_rap_eta1_Cent2_N185/vectLmMassN185");
                hSig[7] = (TH1D*) fFsig->Get("PbPb15_V0_rap_eta1_Cent2_N185/vectLmMassN185");
                hSig[8] = (TH1D*) fFsig->Get("PbPb15_V0_rap_eta1_Cent2_N185/vectLmMassN185");
                hSig[9] = (TH1D*) fFsig->Get("PbPb15_V0_rap_eta1_Cent2_N185/vectLmMassN185");
            } else {
                hSig[6] = (TH1D*) fFsig->Get("PbPb15_V0_rap_eta1_NoffAll/vectLmMassNAll");
                hSig[7] = (TH1D*) fFsig->Get("PbPb15_V0_rap_eta1_NoffAll/vectLmMassNAll");
                hSig[8] = (TH1D*) fFsig->Get("PbPb15_V0_rap_eta1_NoffAll/vectLmMassNAll");
                hSig[9] = (TH1D*) fFsig->Get("PbPb15_V0_rap_eta1_NoffAll/vectLmMassNAll");
            }
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
    for ( int c = 6; c < 10; c++ ) {
        grPureV2sub2[c] = getSigVn( grSigV2sub2[c], grSBV2sub2[c], hSig[c] );
        grPureV2sub4[c] = getSigVn( grSigV2sub4[c], grSBV2sub4[c], hSig[c] );

        grPureV2sub2pos[c] = getSigVn( grSigV2sub2pos[c], grSBV2sub2pos[c], hSig[c] );
        grPureV2sub4pos[c] = getSigVn( grSigV2sub4pos[c], grSBV2sub4pos[c], hSig[c] );

        grPureV2sub2neg[c] = getSigVn( grSigV2sub2neg[c], grSBV2sub2neg[c], hSig[c] );
        grPureV2sub4neg[c] = getSigVn( grSigV2sub4neg[c], grSBV2sub4neg[c], hSig[c] );
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

    for ( int c = 6; c < 10; c++ ) {
        if ( grSigV2sub2[c]) grSigV2sub2[c]->Write(Form("grObs_V2sub2_%i", c));
        else                          dummy->Write(Form("grObs_V2sub2_%i", c));
        if ( grSBV2sub2[c] ) grSBV2sub2[c] ->Write(Form("grBkg_V2sub2_%i", c));
        else                          dummy->Write(Form("grBkg_V2sub2_%i", c));
        grPureV2sub2[c]->Write(Form("grSig_V2sub2_%i", c));

        if ( grSigV2sub4[c]) grSigV2sub4[c]->Write(Form("grObs_V2sub4_%i", c));
        else                          dummy->Write(Form("grObs_V2sub4_%i", c));
        if ( grSBV2sub4[c] ) grSBV2sub4[c] ->Write(Form("grBkg_V2sub4_%i", c));
        else                          dummy->Write(Form("grBkg_V2sub4_%i", c));
        grPureV2sub4[c]->Write(Form("grSig_V2sub4_%i", c));

        if ( grSigV2sub2pos[c]) grSigV2sub2pos[c]->Write(Form("grObs_V2sub2pos_%i", c));
        else                                dummy->Write(Form("grObs_V2sub2pos_%i", c));
        if ( grSBV2sub2pos[c] ) grSBV2sub2pos[c] ->Write(Form("grBkg_V2sub2pos_%i", c));
        else                                dummy->Write(Form("grBkg_V2sub2pos_%i", c));
        grPureV2sub2pos[c]->Write(Form("grSig_V2sub2pos_%i", c));

        if ( grSigV2sub4pos[c]) grSigV2sub4pos[c]->Write(Form("grObs_V2sub4pos_%i", c));
        else                                dummy->Write(Form("grObs_V2sub4pos_%i", c));
        if ( grSBV2sub4pos[c] ) grSBV2sub4pos[c] ->Write(Form("grBkg_V2sub4pos_%i", c));
        else                                dummy->Write(Form("grBkg_V2sub4pos_%i", c));
        grPureV2sub4pos[c]->Write(Form("grSig_V2sub4pos_%i", c));

        if ( grSigV2sub2neg[c]) grSigV2sub2neg[c]->Write(Form("grObs_V2sub2neg_%i", c));
        else                                dummy->Write(Form("grObs_V2sub2neg_%i", c));
        if ( grSBV2sub2neg[c] ) grSBV2sub2neg[c] ->Write(Form("grBkg_V2sub2neg_%i", c));
        else                                dummy->Write(Form("grBkg_V2sub2neg_%i", c));
        grPureV2sub2neg[c]->Write(Form("grSig_V2sub2neg_%i", c));

        if ( grSigV2sub4neg[c]) grSigV2sub4neg[c]->Write(Form("grObs_V2sub4neg_%i", c));
        else                                dummy->Write(Form("grObs_V2sub4neg_%i", c));
        if ( grSBV2sub4neg[c] ) grSBV2sub4neg[c] ->Write(Form("grBkg_V2sub4neg_%i", c));
        else                                dummy->Write(Form("grBkg_V2sub4neg_%i", c));
        grPureV2sub4neg[c]->Write(Form("grSig_V2sub4neg_%i", c));
    }
}




TGraphErrors* getSigVn(TGraphErrors* grSig, TGraphErrors* grSB, TH1D* hsig)
{
	TGraphErrors * ret = new TGraphErrors(13);
    if ( !grSig ) {
        return dummy;
    } else {
        for ( int i = 0; i < 13; i++ ) {
            ret->GetX()[i] = grSig->GetX()[i];

            double obs = grSig->GetY()[i];
            double bkg = grSB->GetY()[i];
            double fsig = hsig->GetBinContent(i+1);
            double sig = ( obs - (1-fsig) * bkg ) / fsig;

            double eobs = grSig->GetEY()[i];
            double ebkg = grSB->GetEY()[i];

            double esig = sqrt( eobs*eobs + (1-fsig)*(1-fsig)*ebkg * ebkg ) / fsig;

            if ( fsig == 0. ) {
                sig = 0.;
                esig = 0.;
            }
            ret->GetY()[i] = sig;
            ret->GetEY()[i] = esig;

            //cout << "--> i = " << i << endl;
            //cout << " obs = " << obs << endl;
            //cout << " bkg = " << bkg << endl;
            //cout << " fsig = " << fsig << endl;
            //cout << " sig = " << sig << endl;
            //cout << " eobs = " << eobs << endl;
            //cout << " ebkg = " << ebkg << endl;
            //cout << " esig = " << esig << endl;
        }
    }

	return ret;
}




