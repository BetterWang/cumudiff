
#include "Steve_SP.h"

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

void vnFsigPbPbSP(string strSave = "PbPb_v0_SP_corrected.root", double sys = 0.0)
{
    for ( int i = 0; i < 13; i++ ) {
        dummy->GetX()[i] = 0.;
        dummy->GetY()[i] = 0.;
        dummy->GetEY()[i] = 99.;
    }


    TFile * fFsigKs = new TFile("FsigKSMid.root");
    TFile * fFsigLm = new TFile("FsigLMMid.root");
	TH1D * hSigKs[5] = {};
	TH1D * hSigLm[5] = {};

    hSigKs[0] = (TH1D*) fFsigKs->Get("hFsigMid0");
    hSigKs[1] = (TH1D*) fFsigKs->Get("hFsigMid0");
    hSigKs[2] = (TH1D*) fFsigKs->Get("hFsigMid1");
    hSigKs[3] = (TH1D*) fFsigKs->Get("hFsigMid2");
    hSigKs[4] = (TH1D*) fFsigKs->Get("hFsigMid3");

    hSigLm[0] = (TH1D*) fFsigLm->Get("hFsigMid0");
    hSigLm[1] = (TH1D*) fFsigLm->Get("hFsigMid0");
    hSigLm[2] = (TH1D*) fFsigLm->Get("hFsigMid1");
    hSigLm[3] = (TH1D*) fFsigLm->Get("hFsigMid2");
    hSigLm[4] = (TH1D*) fFsigLm->Get("hFsigMid3");

    LoadSP();

    for ( int c = 0; c < 5; c++ ) {
        Ks_v2_PbPb_Sig[c]->vn_NegEta           = getSigVn( Ks_v2_PbPb_Obs[c]->vn_NegEta,           Ks_v2_PbPb_Bkg[c]->vn_NegEta          , hSigKs[c], sys);
        Ks_v2_PbPb_Sig[c]->vn_PosEta           = getSigVn( Ks_v2_PbPb_Obs[c]->vn_PosEta,           Ks_v2_PbPb_Bkg[c]->vn_PosEta          , hSigKs[c], sys);
        Ks_v2_PbPb_Sig[c]->vn_NegEta_SubEvt    = getSigVn( Ks_v2_PbPb_Obs[c]->vn_NegEta_SubEvt,    Ks_v2_PbPb_Bkg[c]->vn_NegEta_SubEvt   , hSigKs[c], sys);
        Ks_v2_PbPb_Sig[c]->vn_PosEta_SubEvt    = getSigVn( Ks_v2_PbPb_Obs[c]->vn_PosEta_SubEvt,    Ks_v2_PbPb_Bkg[c]->vn_PosEta_SubEvt   , hSigKs[c], sys);
        Ks_v2_PbPb_Sig[c]->vn_MergedEta        = getSigVn( Ks_v2_PbPb_Obs[c]->vn_MergedEta,        Ks_v2_PbPb_Bkg[c]->vn_MergedEta       , hSigKs[c], sys);
        Ks_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt = getSigVn( Ks_v2_PbPb_Obs[c]->vn_MergedEta_SubEvt, Ks_v2_PbPb_Bkg[c]->vn_MergedEta_SubEvt, hSigKs[c], sys);

        Ks_v3_PbPb_Sig[c]->vn_NegEta           = getSigVn( Ks_v3_PbPb_Obs[c]->vn_NegEta,           Ks_v3_PbPb_Bkg[c]->vn_NegEta          , hSigKs[c], sys);
        Ks_v3_PbPb_Sig[c]->vn_PosEta           = getSigVn( Ks_v3_PbPb_Obs[c]->vn_PosEta,           Ks_v3_PbPb_Bkg[c]->vn_PosEta          , hSigKs[c], sys);
        Ks_v3_PbPb_Sig[c]->vn_NegEta_SubEvt    = getSigVn( Ks_v3_PbPb_Obs[c]->vn_NegEta_SubEvt,    Ks_v3_PbPb_Bkg[c]->vn_NegEta_SubEvt   , hSigKs[c], sys);
        Ks_v3_PbPb_Sig[c]->vn_PosEta_SubEvt    = getSigVn( Ks_v3_PbPb_Obs[c]->vn_PosEta_SubEvt,    Ks_v3_PbPb_Bkg[c]->vn_PosEta_SubEvt   , hSigKs[c], sys);
        Ks_v3_PbPb_Sig[c]->vn_MergedEta        = getSigVn( Ks_v3_PbPb_Obs[c]->vn_MergedEta,        Ks_v3_PbPb_Bkg[c]->vn_MergedEta       , hSigKs[c], sys);
        Ks_v3_PbPb_Sig[c]->vn_MergedEta_SubEvt = getSigVn( Ks_v3_PbPb_Obs[c]->vn_MergedEta_SubEvt, Ks_v3_PbPb_Bkg[c]->vn_MergedEta_SubEvt, hSigKs[c], sys);

        Lm_v2_PbPb_Sig[c]->vn_NegEta           = getSigVn( Lm_v2_PbPb_Obs[c]->vn_NegEta,           Lm_v2_PbPb_Bkg[c]->vn_NegEta          , hSigLm[c], sys);
        Lm_v2_PbPb_Sig[c]->vn_PosEta           = getSigVn( Lm_v2_PbPb_Obs[c]->vn_PosEta,           Lm_v2_PbPb_Bkg[c]->vn_PosEta          , hSigLm[c], sys);
        Lm_v2_PbPb_Sig[c]->vn_NegEta_SubEvt    = getSigVn( Lm_v2_PbPb_Obs[c]->vn_NegEta_SubEvt,    Lm_v2_PbPb_Bkg[c]->vn_NegEta_SubEvt   , hSigLm[c], sys);
        Lm_v2_PbPb_Sig[c]->vn_PosEta_SubEvt    = getSigVn( Lm_v2_PbPb_Obs[c]->vn_PosEta_SubEvt,    Lm_v2_PbPb_Bkg[c]->vn_PosEta_SubEvt   , hSigLm[c], sys);
        Lm_v2_PbPb_Sig[c]->vn_MergedEta        = getSigVn( Lm_v2_PbPb_Obs[c]->vn_MergedEta,        Lm_v2_PbPb_Bkg[c]->vn_MergedEta       , hSigLm[c], sys);
        Lm_v2_PbPb_Sig[c]->vn_MergedEta_SubEvt = getSigVn( Lm_v2_PbPb_Obs[c]->vn_MergedEta_SubEvt, Lm_v2_PbPb_Bkg[c]->vn_MergedEta_SubEvt, hSigLm[c], sys);

        Lm_v3_PbPb_Sig[c]->vn_NegEta           = getSigVn( Lm_v3_PbPb_Obs[c]->vn_NegEta,           Lm_v3_PbPb_Bkg[c]->vn_NegEta          , hSigLm[c], sys);
        Lm_v3_PbPb_Sig[c]->vn_PosEta           = getSigVn( Lm_v3_PbPb_Obs[c]->vn_PosEta,           Lm_v3_PbPb_Bkg[c]->vn_PosEta          , hSigLm[c], sys);
        Lm_v3_PbPb_Sig[c]->vn_NegEta_SubEvt    = getSigVn( Lm_v3_PbPb_Obs[c]->vn_NegEta_SubEvt,    Lm_v3_PbPb_Bkg[c]->vn_NegEta_SubEvt   , hSigLm[c], sys);
        Lm_v3_PbPb_Sig[c]->vn_PosEta_SubEvt    = getSigVn( Lm_v3_PbPb_Obs[c]->vn_PosEta_SubEvt,    Lm_v3_PbPb_Bkg[c]->vn_PosEta_SubEvt   , hSigLm[c], sys);
        Lm_v3_PbPb_Sig[c]->vn_MergedEta        = getSigVn( Lm_v3_PbPb_Obs[c]->vn_MergedEta,        Lm_v3_PbPb_Bkg[c]->vn_MergedEta       , hSigLm[c], sys);
        Lm_v3_PbPb_Sig[c]->vn_MergedEta_SubEvt = getSigVn( Lm_v3_PbPb_Obs[c]->vn_MergedEta_SubEvt, Lm_v3_PbPb_Bkg[c]->vn_MergedEta_SubEvt, hSigLm[c], sys);
    }

	TFile * fsave = new TFile(strSave.c_str(), "recreate");

    int c = 0;
    for ( auto dir : {"_0_5", "_5_10", "_10_30", "_30_50", "_50_80"} ) {
        TDirectory * d = fsave->mkdir( (string("ch_v2_PbPb") + dir).c_str() );
        ch_v2_PbPb[c]->Write(d);

        d = fsave->mkdir( (string("ch_v3_PbPb") + dir).c_str() );
        ch_v3_PbPb[c]->Write(d);

        d = fsave->mkdir( (string("Ks_v2_PbPb_Obs") + dir).c_str() );
        Ks_v2_PbPb_Obs[c]->Write(d);
        d = fsave->mkdir( (string("Ks_v2_PbPb_Bkg") + dir).c_str() );
        Ks_v2_PbPb_Bkg[c]->Write(d);
        d = fsave->mkdir( (string("Ks_v2_PbPb_Sig") + dir).c_str() );
        Ks_v2_PbPb_Sig[c]->Write(d);

        d = fsave->mkdir( (string("Ks_v3_PbPb_Obs") + dir).c_str() );
        Ks_v3_PbPb_Obs[c]->Write(d);
        d = fsave->mkdir( (string("Ks_v3_PbPb_Bkg") + dir).c_str() );
        Ks_v3_PbPb_Bkg[c]->Write(d);
        d = fsave->mkdir( (string("Ks_v3_PbPb_Sig") + dir).c_str() );
        Ks_v3_PbPb_Sig[c]->Write(d);

        d = fsave->mkdir( (string("Lm_v2_PbPb_Obs") + dir).c_str() );
        Lm_v2_PbPb_Obs[c]->Write(d);
        d = fsave->mkdir( (string("Lm_v2_PbPb_Bkg") + dir).c_str() );
        Lm_v2_PbPb_Bkg[c]->Write(d);
        d = fsave->mkdir( (string("Lm_v2_PbPb_Sig") + dir).c_str() );
        Lm_v2_PbPb_Sig[c]->Write(d);

        d = fsave->mkdir( (string("Lm_v3_PbPb_Obs") + dir).c_str() );
        Lm_v3_PbPb_Obs[c]->Write(d);
        d = fsave->mkdir( (string("Lm_v3_PbPb_Bkg") + dir).c_str() );
        Lm_v3_PbPb_Bkg[c]->Write(d);
        d = fsave->mkdir( (string("Lm_v3_PbPb_Sig") + dir).c_str() );
        Lm_v3_PbPb_Sig[c]->Write(d);

        c++;
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




