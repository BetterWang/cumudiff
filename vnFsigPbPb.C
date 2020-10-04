

TGraphErrors* getSigVn(TGraphErrors*, TGraphErrors*, TH1D*, double);

TGraphErrors* dummy = new TGraphErrors(13);

TGraphErrors* merge(TGraphErrors* gr1, TGraphErrors* gr2){
    int N = gr1->GetN();
    TGraphErrors * gr = new TGraphErrors(N);

    for ( int i = 0; i < N; i++ ) {
        gr->GetX()[i] = gr1->GetX()[i];
        double y1 = gr1->GetY()[i];
        double y2 = gr2->GetY()[i];
        double e1 = gr1->GetEY()[i];
        double e2 = gr2->GetEY()[i];

        gr->GetY()[i] = (y1/e1/e1 + y2/e2/e2) / (1./e1/e1 + 1./e2/e2);
        gr->GetEY()[i] = sqrt(1./e1/e1 + 1./e2/e2) / (1./e1/e1 + 1./e2/e2);
    }
    return gr;
}

void vnFsigPbPb(string sig = "PbPb2018_Ks.root", string sb = "PbPb2018_Ks_SB.root", string strSave = "test.root", double sys = 0.0, string option = "")
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
		for ( int c = 0; c < 5; c++ ) {
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
    TGraphErrors * grPureV2sub2merge[20] = {};

    TGraphErrors * grSigV2sub4[20] = {};
    TGraphErrors * grSBV2sub4[20] = {};
    TGraphErrors * grPureV2sub4[20] = {};
    TGraphErrors * grPureV2sub4merge[20] = {};

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

    for ( int c = 0; c < 5; c++ ) {
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


	bool bKs   = (sig.find("Lm") == std::string::npos);
    bool bMid  = (sig.find("Fwd") == std::string::npos);

	TFile * fFsig;
	TH1D * hSig[20] = {};
    if ( bKs ) {
        // Ks
        if ( bMid ) {
            if ( option == "pol3" ) {
                fFsig = new TFile("FsigKSpol3Mid_cent7.root");
            } else if ( option == "pol1" ) {
                fFsig = new TFile("FsigKSpol1Mid_cent7.root");
            } else if ( option == "exp" ) {
                fFsig = new TFile("FsigKSExpMid_cent7.root");
            } else if ( option == "centS" ) {
                fFsig = new TFile("FsigKSMid_centS.root");
            } else {
                fFsig = new TFile("FsigKSMid_cent7.root");
            }
        } else {
            fFsig = new TFile("FsigKSFwd.root");
        }
    } else {
        // Lm
        if ( bMid ) {
            if ( option == "pol3" ) {
                fFsig = new TFile("FsigLMpol3Mid_cent7.root");
            } else if ( option == "pol1" ) {
                fFsig = new TFile("FsigLMpol1Mid_cent7.root");
            } else if ( option == "exp" ) {
                fFsig = new TFile("FsigLMExpMid_cent7.root");
            } else if ( option == "centS" ) {
                fFsig = new TFile("FsigLMMid_centS.root");
            } else {
                fFsig = new TFile("FsigLMMid_cent7.root");
            }
        } else {
            fFsig = new TFile("FsigLMFwd.root");
        }
    }
    hSig[0] = (TH1D*) fFsig->Get("hFsigMid0");
    hSig[1] = (TH1D*) fFsig->Get("hFsigMid1");
    hSig[2] = (TH1D*) fFsig->Get("hFsigMid2");
    hSig[3] = (TH1D*) fFsig->Get("hFsigMid3");
    hSig[4] = (TH1D*) fFsig->Get("hFsigMid4");
    hSig[5] = (TH1D*) fFsig->Get("hFsigMid5");

	for ( int n = 2; n < 7; n++ ) {
		for ( int c = 0; c < 5; c++ ) {
			grPure_pTGap[n][c] = getSigVn(grSig_pTGap[n][c], grSB_pTGap[n][c], hSig[c], sys);

			for ( int np = 0; np < 4; np++ ) {
				grPure_pT[n][np][c] = getSigVn(grSig_pT[n][np][c], grSB_pT[n][np][c], hSig[c], sys);
			}
		}
	}
    for ( int c = 0; c < 5; c++ ) {
        grPureV2sub2[c] = getSigVn( grSigV2sub2[c], grSBV2sub2[c], hSig[c] , sys);
        grPureV2sub4[c] = getSigVn( grSigV2sub4[c], grSBV2sub4[c], hSig[c] , sys);

        grPureV2sub2pos[c] = getSigVn( grSigV2sub2pos[c], grSBV2sub2pos[c], hSig[c] , sys);
        grPureV2sub4pos[c] = getSigVn( grSigV2sub4pos[c], grSBV2sub4pos[c], hSig[c] , sys);

        grPureV2sub2neg[c] = getSigVn( grSigV2sub2neg[c], grSBV2sub2neg[c], hSig[c] , sys);
        grPureV2sub4neg[c] = getSigVn( grSigV2sub4neg[c], grSBV2sub4neg[c], hSig[c] , sys);

        grPureV2sub2merge[c] = merge(grPureV2sub2pos[c], grPureV2sub2neg[c]);
        grPureV2sub4merge[c] = merge(grPureV2sub4pos[c], grPureV2sub4neg[c]);
    }

	TFile * fsave = new TFile(strSave.c_str(), "recreate");
	for ( int n = 2; n < 7; n++ ) {
		for ( int c = 0; c < 5; c++ ) {
			grSig_pTGap[n][c]->Write(Form("grObs_pTGap%i_%i", n, c));
			if (grSB_pTGap[n][c]) grSB_pTGap[n][c] ->Write(Form("grBkg_pTGap%i_%i", n, c));
            else                              dummy->Write(Form("grBkg_pTGap%i_%i", n, c));
			grPure_pTGap[n][c]->Write(Form("grSig_pTGap%i_%i", n, c));
			grH_pTGap[n][c] ->Write(Form("grH_pTGap%i_%i", n, c));
			for ( int np = 0; np < 4; np++ ) {
				grPure_pT[n][np][c]->Write(Form("grSig_pT%i_%i_%i", n, np, c));
				grSig_pT[n][np][c]->Write(Form("grObs_pT%i_%i_%i", n, np, c));
				if ( grSB_pT[n][np][c] ) grSB_pT[n][np][c]->Write(Form("grBkg_pT%i_%i_%i", n, np, c));
                else                                 dummy->Write(Form("grBkg_pT%i_%i_%i", n, np, c));
			}
		}
	}

    for ( int c = 0; c < 5; c++ ) {
        if ( grSigV2sub2[c]) grSigV2sub2[c]->Write(Form("grObs_V2sub2_%i", c));
        else                          dummy->Write(Form("grObs_V2sub2_%i", c));
        if ( grSBV2sub2[c] ) grSBV2sub2[c] ->Write(Form("grBkg_V2sub2_%i", c));
        else                          dummy->Write(Form("grBkg_V2sub2_%i", c));
        grPureV2sub2[c]->Write(Form("grSig_V2sub2_%i", c));
        grPureV2sub2merge[c]->Write(Form("grSig_V2sub2merge_%i", c));

        if ( grSigV2sub4[c]) grSigV2sub4[c]->Write(Form("grObs_V2sub4_%i", c));
        else                          dummy->Write(Form("grObs_V2sub4_%i", c));
        if ( grSBV2sub4[c] ) grSBV2sub4[c] ->Write(Form("grBkg_V2sub4_%i", c));
        else                          dummy->Write(Form("grBkg_V2sub4_%i", c));
        grPureV2sub4[c]->Write(Form("grSig_V2sub4_%i", c));
        grPureV2sub4merge[c]->Write(Form("grSig_V2sub4merge_%i", c));

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

    fsave->Close();
}




TGraphErrors* getSigVn(TGraphErrors* grSig, TGraphErrors* grSB, TH1D* hsig, double sys)
{
	TGraphErrors * ret = new TGraphErrors(13);
    if ( !grSig ) {
        return dummy;
    } else if ( !grSB ) {
        for ( int i = 0; i < 13; i++ ) {
            ret->GetX()[i] = grSig->GetX()[i];
            ret->GetY()[i] = grSig->GetY()[i];
            ret->GetEY()[i] = grSig->GetEY()[i];
        }
    } else {
        for ( int i = 0; i < 13; i++ ) {
            ret->GetX()[i] = grSig->GetX()[i];

            double obs = grSig->GetY()[i];
            double bkg = grSB->GetY()[i];
            double fsig = hsig->GetBinContent(i+1) + sys;
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




