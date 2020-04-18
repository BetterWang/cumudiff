
struct iEbyE {
    TGraphErrors * grKs_v22_10_30;
    TGraphErrors * grKs_v22_30_50;
    TGraphErrors * grKs_v22_50_60;
    TGraphErrors * grKs_v24_10_30;
    TGraphErrors * grKs_v24_30_50;
    TGraphErrors * grKs_v24_50_60;

    TGraphErrors * grLm_v22_10_30;
    TGraphErrors * grLm_v22_30_50;
    TGraphErrors * grLm_v22_50_60;
    TGraphErrors * grLm_v24_10_30;
    TGraphErrors * grLm_v24_30_50;
    TGraphErrors * grLm_v24_50_60;

    TGraphErrors * grKs_v22[5] = {};
    TGraphErrors * grKs_v24[5] = {};
    TGraphErrors * grLm_v22[5] = {};
    TGraphErrors * grLm_v24[5] = {};

    iEbyE(TFile *f) {
        grKs_v22_10_30 = (TGraphErrors*) f->Get("grKs_v22_10_30");
        grKs_v22_30_50 = (TGraphErrors*) f->Get("grKs_v22_30_50");
        grKs_v22_50_60 = (TGraphErrors*) f->Get("grKs_v22_50_60");
        grKs_v24_10_30 = (TGraphErrors*) f->Get("grKs_v24_10_30");
        grKs_v24_30_50 = (TGraphErrors*) f->Get("grKs_v24_30_50");
        grKs_v24_50_60 = (TGraphErrors*) f->Get("grKs_v24_50_60");

        grLm_v22_10_30 = (TGraphErrors*) f->Get("grLm_v22_10_30");
        grLm_v22_30_50 = (TGraphErrors*) f->Get("grLm_v22_30_50");
        grLm_v22_50_60 = (TGraphErrors*) f->Get("grLm_v22_50_60");
        grLm_v24_10_30 = (TGraphErrors*) f->Get("grLm_v24_10_30");
        grLm_v24_30_50 = (TGraphErrors*) f->Get("grLm_v24_30_50");
        grLm_v24_50_60 = (TGraphErrors*) f->Get("grLm_v24_50_60");

        grKs_v22[0] = nullptr;
        grKs_v22[1] = grKs_v22_10_30;
        grKs_v22[2] = grKs_v22_30_50;
        grKs_v22[3] = grKs_v22_50_60;
        grKs_v22[4] = nullptr;

        grKs_v24[0] = nullptr;
        grKs_v24[1] = grKs_v24_10_30;
        grKs_v24[2] = grKs_v24_30_50;
        grKs_v24[3] = grKs_v24_50_60;
        grKs_v24[4] = nullptr;

        grLm_v22[0] = nullptr;
        grLm_v22[1] = grLm_v22_10_30;
        grLm_v22[2] = grLm_v22_30_50;
        grLm_v22[3] = grLm_v22_50_60;
        grLm_v22[4] = nullptr;

        grLm_v24[0] = nullptr;
        grLm_v24[1] = grLm_v24_10_30;
        grLm_v24[2] = grLm_v24_30_50;
        grLm_v24[3] = grLm_v24_50_60;
        grLm_v24[4] = nullptr;
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
