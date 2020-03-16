#include "Steve_SP.h"

TGraphErrors* getSigVn(TGraphErrors*, TGraphErrors*, TH1D*, double sys = 0);

TGraphErrors* dummy = new TGraphErrors(13);

SteveGraph SteveGrCorrection( SteveGraph*, SteveGraph*,  TH1D*, double);

void vnFsigSP(string strSave = "test.root", double sys = 0.0 )
{
    for ( int i = 0; i < 13; i++ ) {
        dummy->GetX()[i] = 0.;
        dummy->GetY()[i] = 0.;
        dummy->GetEY()[i] = 99.;
    }

    LoadSP();

    SteveGraph Ks_pPb_corrected[10];
    SteveGraph Lm_pPb_corrected[10];

	TFile * fFsig = new TFile("Fsig.root");
	TH1D * hSigKs[20];
	TH1D * hSigLm[20];

    hSigKs[6] = (TH1D*) fFsig->Get("pPb_V0_HM0_eta1_merge/vectKsMassN120");
    hSigKs[7] = (TH1D*) fFsig->Get("pPb_V0_HM0_eta1_merge/vectKsMassN150");
    hSigKs[8] = (TH1D*) fFsig->Get("pPb_V0_HM123456_eta1_merge/vectKsMassN185");
    hSigKs[9] = (TH1D*) fFsig->Get("pPb_V0_HM7_eta1_merge/vectKsMassN250");

    hSigLm[6] = (TH1D*) fFsig->Get("pPb_V0_HM0_eta1_merge/vectLmMassN120");
    hSigLm[7] = (TH1D*) fFsig->Get("pPb_V0_HM0_eta1_merge/vectLmMassN150");
    hSigLm[8] = (TH1D*) fFsig->Get("pPb_V0_HM123456_eta1_merge/vectLmMassN185");
    hSigLm[9] = (TH1D*) fFsig->Get("pPb_V0_HM7_eta1_merge/vectLmMassN250");

    for ( int c = 6; c < 10; c++ ) {
        Ks_pPb_corrected[c] = SteveGrCorrection( Ks_pPb_merge[c], Ks_SB_pPb_merge[c], hSigKs[c], sys);
        Lm_pPb_corrected[c] = SteveGrCorrection( Lm_pPb_merge[c], Lm_SB_pPb_merge[c], hSigLm[c], sys);
    }



	TFile * fsave = new TFile(strSave.c_str(), "recreate");

    for ( int c = 6; c < 10; c++ ) {
        TDirectory * d = fsave->mkdir( (string("ch_pPb_corrected_") + to_string(c)).c_str() );
        ch_pPb_merge[c]->Write(d);

        d = fsave->mkdir( (string("Ks_pPb_Obs_") + to_string(c)).c_str() );
        if ( Ks_pPb_merge[c] ) Ks_pPb_merge[c]->Write(d);

        d = fsave->mkdir( (string("Ks_pPb_SB_") + to_string(c)).c_str() );
        if ( Ks_SB_pPb_merge[c] ) Ks_SB_pPb_merge[c]->Write(d);

        d = fsave->mkdir( (string("Ks_pPb_corrected_") + to_string(c)).c_str() );
        Ks_pPb_corrected[c].Write(d);

        d = fsave->mkdir( (string("Lm_pPb_Obs_") + to_string(c)).c_str() );
        if ( Lm_pPb_merge[c] ) Lm_pPb_merge[c]->Write(d);

        d = fsave->mkdir( (string("Lm_pPb_SB_") + to_string(c)).c_str() );
        if ( Lm_SB_pPb_merge[c] ) Lm_SB_pPb_merge[c]->Write(d);

        d = fsave->mkdir( (string("Lm_pPb_corrected_") + to_string(c)).c_str() );
        Lm_pPb_corrected[c].Write(d);
    }

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


SteveGraph SteveGrCorrection( SteveGraph* grObs, SteveGraph* grSB,  TH1D* hsig, double sys)
{
    SteveGraph ret;
    if ( grObs and grSB ) {
        ret.vn_NegEta_PosEtaEP          = getSigVn( grObs->vn_NegEta_PosEtaEP       , grSB->vn_NegEta_PosEtaEP        , hsig, sys );
        ret.vn_NegEta_PosEtaEP_SubEvt   = getSigVn( grObs->vn_NegEta_PosEtaEP_SubEvt, grSB->vn_NegEta_PosEtaEP_SubEvt , hsig, sys );
        ret.vn_PosEta_NegEtaEP          = getSigVn( grObs->vn_PosEta_NegEtaEP       , grSB->vn_PosEta_NegEtaEP        , hsig, sys );
        ret.vn_PosEta_NegEtaEP_SubEvt   = getSigVn( grObs->vn_PosEta_NegEtaEP_SubEvt, grSB->vn_PosEta_NegEtaEP_SubEvt , hsig, sys );
        ret.vn_Full_PosEtaEP            = getSigVn( grObs->vn_Full_PosEtaEP         , grSB->vn_Full_PosEtaEP          , hsig, sys );
        ret.vn_Full_PosEtaEP_SubEvt     = getSigVn( grObs->vn_Full_PosEtaEP_SubEvt  , grSB->vn_Full_PosEtaEP_SubEvt   , hsig, sys );
        ret.vn_Full_NegEtaEP            = getSigVn( grObs->vn_Full_NegEtaEP         , grSB->vn_Full_NegEtaEP          , hsig, sys );
        ret.vn_Full_NegEtaEP_SubEvt     = getSigVn( grObs->vn_Full_NegEtaEP_SubEvt  , grSB->vn_Full_NegEtaEP_SubEvt   , hsig, sys );
    } else {
        ret.vn_NegEta_PosEtaEP          = dummy;
        ret.vn_NegEta_PosEtaEP_SubEvt   = dummy;
        ret.vn_PosEta_NegEtaEP          = dummy;
        ret.vn_PosEta_NegEtaEP_SubEvt   = dummy;
        ret.vn_Full_PosEtaEP            = dummy;
        ret.vn_Full_PosEtaEP_SubEvt     = dummy;
        ret.vn_Full_NegEtaEP            = dummy;
        ret.vn_Full_NegEtaEP_SubEvt     = dummy;
    }

    return ret;
}

