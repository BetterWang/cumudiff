
//#include "v2_2_4_pt_AMPT_all_charged.C"
//#include "v2_2_4_pt_AMPT_cent.C"
#include "v2_2_4_pt_TRENTo_all_charged.C"
#include "v2_2_4_pt_TRENTo_cent.C"

void theory()
{
    TGraphErrors * grCh_v22_5_10  = new TGraphErrors(row_PT, PT, v22pt_all_charged_510,    0, v22ptError_all_charged_510 );
    TGraphErrors * grCh_v22_10_30 = new TGraphErrors(row_PT, PT, v22pt_all_charged_1030,   0, v22ptError_all_charged_1030);
    TGraphErrors * grCh_v22_30_50 = new TGraphErrors(row_PT, PT, v22pt_all_charged_3050,   0, v22ptError_all_charged_3050);
    TGraphErrors * grCh_v22_50_70 = new TGraphErrors(row_PT, PT, v22pt_all_charged_3050,   0, v22ptError_all_charged_5070);

    TGraphErrors * grCh_v24_5_10  = new TGraphErrors(row_PT, PT, v24pt_all_charged_510,    0, v24ptError_all_charged_510 );
    TGraphErrors * grCh_v24_10_30 = new TGraphErrors(row_PT, PT, v24pt_all_charged_1030,   0, v24ptError_all_charged_1030);
    TGraphErrors * grCh_v24_30_50 = new TGraphErrors(row_PT, PT, v24pt_all_charged_3050,   0, v24ptError_all_charged_3050);
    TGraphErrors * grCh_v24_50_70 = new TGraphErrors(row_PT, PT, v24pt_all_charged_3050,   0, v24ptError_all_charged_5070);

    TGraphErrors * grKs_v22_5_10  = new TGraphErrors(row_PT, PT, v22pt_K0s_510,    0, v22ptError_K0s_510 );
    TGraphErrors * grKs_v22_10_30 = new TGraphErrors(row_PT, PT, v22pt_K0s_1030,   0, v22ptError_K0s_1030);
    TGraphErrors * grKs_v22_30_50 = new TGraphErrors(row_PT, PT, v22pt_K0s_3050,   0, v22ptError_K0s_3050);
    TGraphErrors * grKs_v22_50_70 = new TGraphErrors(row_PT, PT, v22pt_K0s_3050,   0, v22ptError_K0s_5070);

    TGraphErrors * grKs_v24_5_10  = new TGraphErrors(row_PT, PT, v24pt_K0s_510,    0, v24ptError_K0s_510 );
    TGraphErrors * grKs_v24_10_30 = new TGraphErrors(row_PT, PT, v24pt_K0s_1030,   0, v24ptError_K0s_1030);
    TGraphErrors * grKs_v24_30_50 = new TGraphErrors(row_PT, PT, v24pt_K0s_3050,   0, v24ptError_K0s_3050);
    TGraphErrors * grKs_v24_50_70 = new TGraphErrors(row_PT, PT, v24pt_K0s_3050,   0, v24ptError_K0s_5070);

    TGraphErrors * grLm_v22_5_10  = new TGraphErrors(row_PT, PT, v22pt_Lambda_510,    0, v22ptError_Lambda_510 );
    TGraphErrors * grLm_v22_10_30 = new TGraphErrors(row_PT, PT, v22pt_Lambda_1030,   0, v22ptError_Lambda_1030);
    TGraphErrors * grLm_v22_30_50 = new TGraphErrors(row_PT, PT, v22pt_Lambda_3050,   0, v22ptError_Lambda_3050);
    TGraphErrors * grLm_v22_50_70 = new TGraphErrors(row_PT, PT, v22pt_Lambda_3050,   0, v22ptError_Lambda_5070);

    TGraphErrors * grLm_v24_5_10  = new TGraphErrors(row_PT, PT, v24pt_Lambda_510,    0, v24ptError_Lambda_510 );
    TGraphErrors * grLm_v24_10_30 = new TGraphErrors(row_PT, PT, v24pt_Lambda_1030,   0, v24ptError_Lambda_1030);
    TGraphErrors * grLm_v24_30_50 = new TGraphErrors(row_PT, PT, v24pt_Lambda_3050,   0, v24ptError_Lambda_3050);
    TGraphErrors * grLm_v24_50_70 = new TGraphErrors(row_PT, PT, v24pt_Lambda_3050,   0, v24ptError_Lambda_5070);

    TFile * f = new TFile("TRENTo.root", "recreate");
    grCh_v22_5_10  ->Write("grCh_v22_5_10");
    grCh_v22_10_30 ->Write("grCh_v22_10_30");
    grCh_v22_30_50 ->Write("grCh_v22_30_50");
    grCh_v22_50_70 ->Write("grCh_v22_50_70");

    grCh_v24_5_10  ->Write("grCh_v24_5_10");
    grCh_v24_10_30 ->Write("grCh_v24_10_30");
    grCh_v24_30_50 ->Write("grCh_v24_30_50");
    grCh_v24_50_70 ->Write("grCh_v24_50_70");

    grKs_v22_5_10  ->Write("grKs_v22_5_10");
    grKs_v22_10_30 ->Write("grKs_v22_10_30");
    grKs_v22_30_50 ->Write("grKs_v22_30_50");
    grKs_v22_50_70 ->Write("grKs_v22_50_70");

    grKs_v24_5_10  ->Write("grKs_v24_5_10");
    grKs_v24_10_30 ->Write("grKs_v24_10_30");
    grKs_v24_30_50 ->Write("grKs_v24_30_50");
    grKs_v24_50_70 ->Write("grKs_v24_50_70");

    grLm_v22_5_10  ->Write("grLm_v22_5_10");
    grLm_v22_10_30 ->Write("grLm_v22_10_30");
    grLm_v22_30_50 ->Write("grLm_v22_30_50");
    grLm_v22_50_70 ->Write("grLm_v22_50_70");

    grLm_v24_5_10  ->Write("grLm_v24_5_10");
    grLm_v24_10_30 ->Write("grLm_v24_10_30");
    grLm_v24_30_50 ->Write("grLm_v24_30_50");
    grLm_v24_50_70 ->Write("grLm_v24_50_70");

    f->Close();
}
