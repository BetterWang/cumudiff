
struct iEbyE {
    TGraphErrors * grKs_v22_5_10;
    TGraphErrors * grKs_v22_10_30;
    TGraphErrors * grKs_v22_30_50;
    TGraphErrors * grKs_v22_50_80;

    TGraphErrors * grLm_v22_5_10;
    TGraphErrors * grLm_v22_10_30;
    TGraphErrors * grLm_v22_30_50;
    TGraphErrors * grLm_v22_50_80;

    TGraphErrors * grCh_v22_5_10;
    TGraphErrors * grCh_v22_10_30;
    TGraphErrors * grCh_v22_30_50;
    TGraphErrors * grCh_v22_50_80;

    TGraphErrors * grKs_v24_5_10;
    TGraphErrors * grKs_v24_10_30;
    TGraphErrors * grKs_v24_30_50;
    TGraphErrors * grKs_v24_50_80;

    TGraphErrors * grLm_v24_5_10;
    TGraphErrors * grLm_v24_10_30;
    TGraphErrors * grLm_v24_30_50;
    TGraphErrors * grLm_v24_50_80;

    TGraphErrors * grCh_v24_5_10;
    TGraphErrors * grCh_v24_10_30;
    TGraphErrors * grCh_v24_30_50;
    TGraphErrors * grCh_v24_50_80;

    TGraphErrors * grKs_Fv2_5_10;
    TGraphErrors * grKs_Fv2_10_30;
    TGraphErrors * grKs_Fv2_30_50;
    TGraphErrors * grKs_Fv2_50_80;

    TGraphErrors * grLm_Fv2_5_10;
    TGraphErrors * grLm_Fv2_10_30;
    TGraphErrors * grLm_Fv2_30_50;
    TGraphErrors * grLm_Fv2_50_80;

    TGraphErrors * grCh_Fv2_5_10;
    TGraphErrors * grCh_Fv2_10_30;
    TGraphErrors * grCh_Fv2_30_50;
    TGraphErrors * grCh_Fv2_50_80;

    TGraphErrors * grKs_v22[5] = {};
    TGraphErrors * grKs_v24[5] = {};
    TGraphErrors * grKs_Fv2[5] = {};
    TGraphErrors * grLm_v22[5] = {};
    TGraphErrors * grLm_v24[5] = {};
    TGraphErrors * grLm_Fv2[5] = {};
    TGraphErrors * grCh_v22[5] = {};
    TGraphErrors * grCh_v24[5] = {};
    TGraphErrors * grCh_Fv2[5] = {};

    iEbyE(TFile *f) {
        grKs_v22_5_10  = (TGraphErrors*) f->Get("grKs_v22_5_10");
        grKs_v22_10_30 = (TGraphErrors*) f->Get("grKs_v22_10_30");
        grKs_v22_30_50 = (TGraphErrors*) f->Get("grKs_v22_30_50");
        grKs_v22_50_80 = (TGraphErrors*) f->Get("grKs_v22_50_80");
        grKs_v24_5_10  = (TGraphErrors*) f->Get("grKs_v24_5_10");
        grKs_v24_10_30 = (TGraphErrors*) f->Get("grKs_v24_10_30");
        grKs_v24_30_50 = (TGraphErrors*) f->Get("grKs_v24_30_50");
        grKs_v24_50_80 = (TGraphErrors*) f->Get("grKs_v24_50_80");
        grKs_Fv2_5_10  = (TGraphErrors*) f->Get("grKs_Fv2_5_10");
        grKs_Fv2_10_30 = (TGraphErrors*) f->Get("grKs_Fv2_10_30");
        grKs_Fv2_30_50 = (TGraphErrors*) f->Get("grKs_Fv2_30_50");
        grKs_Fv2_50_80 = (TGraphErrors*) f->Get("grKs_Fv2_50_80");

        grLm_v22_5_10  = (TGraphErrors*) f->Get("grLm_v22_5_10");
        grLm_v22_10_30 = (TGraphErrors*) f->Get("grLm_v22_10_30");
        grLm_v22_30_50 = (TGraphErrors*) f->Get("grLm_v22_30_50");
        grLm_v22_50_80 = (TGraphErrors*) f->Get("grLm_v22_50_80");
        grLm_v24_5_10  = (TGraphErrors*) f->Get("grLm_v24_5_10");
        grLm_v24_10_30 = (TGraphErrors*) f->Get("grLm_v24_10_30");
        grLm_v24_30_50 = (TGraphErrors*) f->Get("grLm_v24_30_50");
        grLm_v24_50_80 = (TGraphErrors*) f->Get("grLm_v24_50_80");
        grLm_Fv2_5_10  = (TGraphErrors*) f->Get("grLm_Fv2_5_10");
        grLm_Fv2_10_30 = (TGraphErrors*) f->Get("grLm_Fv2_10_30");
        grLm_Fv2_30_50 = (TGraphErrors*) f->Get("grLm_Fv2_30_50");
        grLm_Fv2_50_80 = (TGraphErrors*) f->Get("grLm_Fv2_50_80");

        grCh_v22_5_10  = (TGraphErrors*) f->Get("grCh_v22_5_10");
        grCh_v22_10_30 = (TGraphErrors*) f->Get("grCh_v22_10_30");
        grCh_v22_30_50 = (TGraphErrors*) f->Get("grCh_v22_30_50");
        grCh_v22_50_80 = (TGraphErrors*) f->Get("grCh_v22_50_80");
        grCh_v24_5_10  = (TGraphErrors*) f->Get("grCh_v24_5_10");
        grCh_v24_10_30 = (TGraphErrors*) f->Get("grCh_v24_10_30");
        grCh_v24_30_50 = (TGraphErrors*) f->Get("grCh_v24_30_50");
        grCh_v24_50_80 = (TGraphErrors*) f->Get("grCh_v24_50_80");
        grCh_Fv2_5_10  = (TGraphErrors*) f->Get("grCh_Fv2_5_10");
        grCh_Fv2_10_30 = (TGraphErrors*) f->Get("grCh_Fv2_10_30");
        grCh_Fv2_30_50 = (TGraphErrors*) f->Get("grCh_Fv2_30_50");
        grCh_Fv2_50_80 = (TGraphErrors*) f->Get("grCh_Fv2_50_80");

        grKs_v22[1] = grKs_v22_5_10;
        grKs_v22[2] = grKs_v22_10_30;
        grKs_v22[3] = grKs_v22_30_50;
        grKs_v22[4] = grKs_v22_50_80;
        grKs_v24[1] = grKs_v24_5_10;
        grKs_v24[2] = grKs_v24_10_30;
        grKs_v24[3] = grKs_v24_30_50;
        grKs_v24[4] = grKs_v24_50_80;
        grKs_Fv2[1] = grKs_Fv2_5_10;
        grKs_Fv2[2] = grKs_Fv2_10_30;
        grKs_Fv2[3] = grKs_Fv2_30_50;
        grKs_Fv2[4] = grKs_Fv2_50_80;

        grLm_v22[1] = grLm_v22_5_10;
        grLm_v22[2] = grLm_v22_10_30;
        grLm_v22[3] = grLm_v22_30_50;
        grLm_v22[4] = grLm_v22_50_80;
        grLm_v24[1] = grLm_v24_5_10;
        grLm_v24[2] = grLm_v24_10_30;
        grLm_v24[3] = grLm_v24_30_50;
        grLm_v24[4] = grLm_v24_50_80;
        grLm_Fv2[1] = grLm_Fv2_5_10;
        grLm_Fv2[2] = grLm_Fv2_10_30;
        grLm_Fv2[3] = grLm_Fv2_30_50;
        grLm_Fv2[4] = grLm_Fv2_50_80;

        grCh_v22[1] = grCh_v22_5_10;
        grCh_v22[2] = grCh_v22_10_30;
        grCh_v22[3] = grCh_v22_30_50;
        grCh_v22[4] = grCh_v22_50_80;
        grCh_v24[1] = grCh_v24_5_10;
        grCh_v24[2] = grCh_v24_10_30;
        grCh_v24[3] = grCh_v24_30_50;
        grCh_v24[4] = grCh_v24_50_80;
        grCh_Fv2[1] = grCh_Fv2_5_10;
        grCh_Fv2[2] = grCh_Fv2_10_30;
        grCh_Fv2[3] = grCh_Fv2_30_50;
        grCh_Fv2[4] = grCh_Fv2_50_80;
    };
};

iEbyE* ampt;
iEbyE* trento;

void theory()
{
    TFile * fampt = new TFile("AMPT.root");
    TFile * ftrento = new TFile("Trento.root");

    ampt = new iEbyE(fampt);
    trento = new iEbyE(ftrento);
}
