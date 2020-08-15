
#include "Fv2_CMS/Fv2pt_AMPT.C"
#include "Fv2_CMS/v2_2_4_pt_AMPT.C"
#include "Fv2_CMS/Fv2pt_TRENTo.C"
#include "Fv2_CMS/v2_2_4_pt_TRENTo.C"

#include "Fv2_all_charged/Fv2pt_AMPT.C"
#include "Fv2_all_charged/v2_2_4_pt_AMTP.C"
#include "Fv2_all_charged/Fv2pt_TRENTo.C"
#include "Fv2_all_charged/v2_2_4_pt_TRENTo.C"

void theory()
{
    // Ch
    TGraphErrors * grChAMPT_v22_5_10  = new TGraphErrors(row_PT_charged_hadron_v2, PT_charged_hadron_v2, v22AMPTpt_all_charged_510 , 0, v22AMPTptError_all_charged_510 );
    TGraphErrors * grChAMPT_v22_10_30 = new TGraphErrors(row_PT_charged_hadron_v2, PT_charged_hadron_v2, v22AMPTpt_all_charged_1030, 0, v22AMPTptError_all_charged_1030);
    TGraphErrors * grChAMPT_v22_30_50 = new TGraphErrors(row_PT_charged_hadron_v2, PT_charged_hadron_v2, v22AMPTpt_all_charged_3050, 0, v22AMPTptError_all_charged_3050);
    TGraphErrors * grChAMPT_v22_50_80 = new TGraphErrors(row_PT_charged_hadron_v2, PT_charged_hadron_v2, v22AMPTpt_all_charged_5080, 0, v22AMPTptError_all_charged_5080);

    TGraphErrors * grChTrento_v22_5_10  = new TGraphErrors(row_PT_charged_hadron_v2, PT_charged_hadron_v2, v22TRENTopt_all_charged_510 , 0, v22TRENToptError_all_charged_510 );
    TGraphErrors * grChTrento_v22_10_30 = new TGraphErrors(row_PT_charged_hadron_v2, PT_charged_hadron_v2, v22TRENTopt_all_charged_1030, 0, v22TRENToptError_all_charged_1030);
    TGraphErrors * grChTrento_v22_30_50 = new TGraphErrors(row_PT_charged_hadron_v2, PT_charged_hadron_v2, v22TRENTopt_all_charged_3050, 0, v22TRENToptError_all_charged_3050);
    TGraphErrors * grChTrento_v22_50_80 = new TGraphErrors(row_PT_charged_hadron_v2, PT_charged_hadron_v2, v22TRENTopt_all_charged_5080, 0, v22TRENToptError_all_charged_5080);

    TGraphErrors * grChAMPT_v24_5_10  = new TGraphErrors(row_PT_charged_hadron_v2, PT_charged_hadron_v2, v24AMPTpt_all_charged_510 , 0, v24AMPTptError_all_charged_510 );
    TGraphErrors * grChAMPT_v24_10_30 = new TGraphErrors(row_PT_charged_hadron_v2, PT_charged_hadron_v2, v24AMPTpt_all_charged_1030, 0, v24AMPTptError_all_charged_1030);
    TGraphErrors * grChAMPT_v24_30_50 = new TGraphErrors(row_PT_charged_hadron_v2, PT_charged_hadron_v2, v24AMPTpt_all_charged_3050, 0, v24AMPTptError_all_charged_3050);
    TGraphErrors * grChAMPT_v24_50_80 = new TGraphErrors(row_PT_charged_hadron_v2, PT_charged_hadron_v2, v24AMPTpt_all_charged_5080, 0, v24AMPTptError_all_charged_5080);

    TGraphErrors * grChTrento_v24_5_10  = new TGraphErrors(row_PT_charged_hadron_v2, PT_charged_hadron_v2, v24TRENTopt_all_charged_510 , 0, v24TRENToptError_all_charged_510 );
    TGraphErrors * grChTrento_v24_10_30 = new TGraphErrors(row_PT_charged_hadron_v2, PT_charged_hadron_v2, v24TRENTopt_all_charged_1030, 0, v24TRENToptError_all_charged_1030);
    TGraphErrors * grChTrento_v24_30_50 = new TGraphErrors(row_PT_charged_hadron_v2, PT_charged_hadron_v2, v24TRENTopt_all_charged_3050, 0, v24TRENToptError_all_charged_3050);
    TGraphErrors * grChTrento_v24_50_80 = new TGraphErrors(row_PT_charged_hadron_v2, PT_charged_hadron_v2, v24TRENTopt_all_charged_5080, 0, v24TRENToptError_all_charged_5080);

    TGraphErrors * grChAMPT_Fv2_5_10  = new TGraphErrors(row_PT_charged_hadron, PT_charged_hadron, Fv2total_AMPT_charged_hadron_510 , 0, Fv2total_AMPT_charged_hadron_Error_510 );
    TGraphErrors * grChAMPT_Fv2_10_30 = new TGraphErrors(row_PT_charged_hadron, PT_charged_hadron, Fv2total_AMPT_charged_hadron_1030, 0, Fv2total_AMPT_charged_hadron_Error_1030);
    TGraphErrors * grChAMPT_Fv2_30_50 = new TGraphErrors(row_PT_charged_hadron, PT_charged_hadron, Fv2total_AMPT_charged_hadron_3050, 0, Fv2total_AMPT_charged_hadron_Error_3050);
    TGraphErrors * grChAMPT_Fv2_50_80 = new TGraphErrors(row_PT_charged_hadron, PT_charged_hadron, Fv2total_AMPT_charged_hadron_5080, 0, Fv2total_AMPT_charged_hadron_Error_5080);

    TGraphErrors * grChTRENTo_Fv2_5_10  = new TGraphErrors(row_PT_charged_hadron, PT_charged_hadron, Fv2total_TRENTo_charged_hadron_510 , 0, Fv2total_TRENTo_charged_hadron_Error_510 );
    TGraphErrors * grChTRENTo_Fv2_10_30 = new TGraphErrors(row_PT_charged_hadron, PT_charged_hadron, Fv2total_TRENTo_charged_hadron_1030, 0, Fv2total_TRENTo_charged_hadron_Error_1030);
    TGraphErrors * grChTRENTo_Fv2_30_50 = new TGraphErrors(row_PT_charged_hadron, PT_charged_hadron, Fv2total_TRENTo_charged_hadron_3050, 0, Fv2total_TRENTo_charged_hadron_Error_3050);
    TGraphErrors * grChTRENTo_Fv2_50_80 = new TGraphErrors(row_PT_charged_hadron, PT_charged_hadron, Fv2total_TRENTo_charged_hadron_5080, 0, Fv2total_TRENTo_charged_hadron_Error_5080);

    // Ks
    TGraphErrors * grKsAMPT_v22_5_10  = new TGraphErrors(row_PT, PT, v22AMPTpt_K0s_510 , 0, v22AMPTptError_K0s_510 );
    TGraphErrors * grKsAMPT_v22_10_30 = new TGraphErrors(row_PT, PT, v22AMPTpt_K0s_1030, 0, v22AMPTptError_K0s_1030);
    TGraphErrors * grKsAMPT_v22_30_50 = new TGraphErrors(row_PT, PT, v22AMPTpt_K0s_3050, 0, v22AMPTptError_K0s_3050);
    TGraphErrors * grKsAMPT_v22_50_80 = new TGraphErrors(row_PT, PT, v22AMPTpt_K0s_5080, 0, v22AMPTptError_K0s_5080);

    TGraphErrors * grKsTrento_v22_5_10  = new TGraphErrors(row_PT, PT, v22Trentopt_K0s_510 , 0, v22TrentoptError_K0s_510 );
    TGraphErrors * grKsTrento_v22_10_30 = new TGraphErrors(row_PT, PT, v22Trentopt_K0s_1030, 0, v22TrentoptError_K0s_1030);
    TGraphErrors * grKsTrento_v22_30_50 = new TGraphErrors(row_PT, PT, v22Trentopt_K0s_3050, 0, v22TrentoptError_K0s_3050);
    TGraphErrors * grKsTrento_v22_50_80 = new TGraphErrors(row_PT, PT, v22Trentopt_K0s_5080, 0, v22TrentoptError_K0s_5080);

    TGraphErrors * grKsAMPT_v24_5_10  = new TGraphErrors(row_PT, PT, v24AMPTpt_K0s_510 , 0, v24AMPTptError_K0s_510 );
    TGraphErrors * grKsAMPT_v24_10_30 = new TGraphErrors(row_PT, PT, v24AMPTpt_K0s_1030, 0, v24AMPTptError_K0s_1030);
    TGraphErrors * grKsAMPT_v24_30_50 = new TGraphErrors(row_PT, PT, v24AMPTpt_K0s_3050, 0, v24AMPTptError_K0s_3050);
    TGraphErrors * grKsAMPT_v24_50_80 = new TGraphErrors(row_PT, PT, v24AMPTpt_K0s_5080, 0, v24AMPTptError_K0s_5080);

    TGraphErrors * grKsTrento_v24_5_10  = new TGraphErrors(row_PT, PT, v24Trentopt_K0s_510 , 0, v24TrentoptError_K0s_510 );
    TGraphErrors * grKsTrento_v24_10_30 = new TGraphErrors(row_PT, PT, v24Trentopt_K0s_1030, 0, v24TrentoptError_K0s_1030);
    TGraphErrors * grKsTrento_v24_30_50 = new TGraphErrors(row_PT, PT, v24Trentopt_K0s_3050, 0, v24TrentoptError_K0s_3050);
    TGraphErrors * grKsTrento_v24_50_80 = new TGraphErrors(row_PT, PT, v24Trentopt_K0s_5080, 0, v24TrentoptError_K0s_5080);

    TGraphErrors * grKsAMPT_Fv2_5_10  = new TGraphErrors(row_PT_K0s, PT_K0s, Fv2total_AMPT_K0s_510 , 0, Fv2total_AMPT_K0s_Error_510 );
    TGraphErrors * grKsAMPT_Fv2_10_30 = new TGraphErrors(row_PT_K0s, PT_K0s, Fv2total_AMPT_K0s_1030, 0, Fv2total_AMPT_K0s_Error_1030);
    TGraphErrors * grKsAMPT_Fv2_30_50 = new TGraphErrors(row_PT_K0s, PT_K0s, Fv2total_AMPT_K0s_3050, 0, Fv2total_AMPT_K0s_Error_3050);
    TGraphErrors * grKsAMPT_Fv2_50_80 = new TGraphErrors(row_PT_K0s, PT_K0s, Fv2total_AMPT_K0s_5080, 0, Fv2total_AMPT_K0s_Error_5080);

    TGraphErrors * grKsTRENTo_Fv2_5_10  = new TGraphErrors(row_PT_K0s, PT_K0s, Fv2total_TRENTo_K0s_510 , 0, Fv2total_TRENTo_K0s_Error_510 );
    TGraphErrors * grKsTRENTo_Fv2_10_30 = new TGraphErrors(row_PT_K0s, PT_K0s, Fv2total_TRENTo_K0s_1030, 0, Fv2total_TRENTo_K0s_Error_1030);
    TGraphErrors * grKsTRENTo_Fv2_30_50 = new TGraphErrors(row_PT_K0s, PT_K0s, Fv2total_TRENTo_K0s_3050, 0, Fv2total_TRENTo_K0s_Error_3050);
    TGraphErrors * grKsTRENTo_Fv2_50_80 = new TGraphErrors(row_PT_K0s, PT_K0s, Fv2total_TRENTo_K0s_5080, 0, Fv2total_TRENTo_K0s_Error_5080);

    // Lm
    TGraphErrors * grLmAMPT_v22_5_10  = new TGraphErrors(row_PT, PT, v22AMPTpt_Lambda_510 , 0, v22AMPTptError_Lambda_510 );
    TGraphErrors * grLmAMPT_v22_10_30 = new TGraphErrors(row_PT, PT, v22AMPTpt_Lambda_1030, 0, v22AMPTptError_Lambda_1030);
    TGraphErrors * grLmAMPT_v22_30_50 = new TGraphErrors(row_PT, PT, v22AMPTpt_Lambda_3050, 0, v22AMPTptError_Lambda_3050);
    TGraphErrors * grLmAMPT_v22_50_80 = new TGraphErrors(row_PT, PT, v22AMPTpt_Lambda_5080, 0, v22AMPTptError_Lambda_5080);

    TGraphErrors * grLmTrento_v22_5_10  = new TGraphErrors(row_PT, PT, v22Trentopt_Lambda_510 , 0, v22TrentoptError_Lambda_510 );
    TGraphErrors * grLmTrento_v22_10_30 = new TGraphErrors(row_PT, PT, v22Trentopt_Lambda_1030, 0, v22TrentoptError_Lambda_1030);
    TGraphErrors * grLmTrento_v22_30_50 = new TGraphErrors(row_PT, PT, v22Trentopt_Lambda_3050, 0, v22TrentoptError_Lambda_3050);
    TGraphErrors * grLmTrento_v22_50_80 = new TGraphErrors(row_PT, PT, v22Trentopt_Lambda_5080, 0, v22TrentoptError_Lambda_5080);

    TGraphErrors * grLmAMPT_v24_5_10  = new TGraphErrors(row_PT, PT, v24AMPTpt_Lambda_510 , 0, v24AMPTptError_Lambda_510 );
    TGraphErrors * grLmAMPT_v24_10_30 = new TGraphErrors(row_PT, PT, v24AMPTpt_Lambda_1030, 0, v24AMPTptError_Lambda_1030);
    TGraphErrors * grLmAMPT_v24_30_50 = new TGraphErrors(row_PT, PT, v24AMPTpt_Lambda_3050, 0, v24AMPTptError_Lambda_3050);
    TGraphErrors * grLmAMPT_v24_50_80 = new TGraphErrors(row_PT, PT, v24AMPTpt_Lambda_5080, 0, v24AMPTptError_Lambda_5080);

    TGraphErrors * grLmTrento_v24_5_10  = new TGraphErrors(row_PT, PT, v24Trentopt_Lambda_510 , 0, v24TrentoptError_Lambda_510 );
    TGraphErrors * grLmTrento_v24_10_30 = new TGraphErrors(row_PT, PT, v24Trentopt_Lambda_1030, 0, v24TrentoptError_Lambda_1030);
    TGraphErrors * grLmTrento_v24_30_50 = new TGraphErrors(row_PT, PT, v24Trentopt_Lambda_3050, 0, v24TrentoptError_Lambda_3050);
    TGraphErrors * grLmTrento_v24_50_80 = new TGraphErrors(row_PT, PT, v24Trentopt_Lambda_5080, 0, v24TrentoptError_Lambda_5080);

    TGraphErrors * grLmAMPT_Fv2_5_10  = new TGraphErrors(row_PT_Lambda, PT_Lambda, Fv2total_AMPT_Lambda_510 , 0, Fv2total_AMPT_Lambda_Error_510 );
    TGraphErrors * grLmAMPT_Fv2_10_30 = new TGraphErrors(row_PT_Lambda, PT_Lambda, Fv2total_AMPT_Lambda_1030, 0, Fv2total_AMPT_Lambda_Error_1030);
    TGraphErrors * grLmAMPT_Fv2_30_50 = new TGraphErrors(row_PT_Lambda, PT_Lambda, Fv2total_AMPT_Lambda_3050, 0, Fv2total_AMPT_Lambda_Error_3050);
    TGraphErrors * grLmAMPT_Fv2_50_80 = new TGraphErrors(row_PT_Lambda, PT_Lambda, Fv2total_AMPT_Lambda_5080, 0, Fv2total_AMPT_Lambda_Error_5080);

    TGraphErrors * grLmTRENTo_Fv2_5_10  = new TGraphErrors(row_PT_Lambda, PT_Lambda, Fv2total_TRENTo_Lambda_510 , 0, Fv2total_TRENTo_Lambda_Error_510 );
    TGraphErrors * grLmTRENTo_Fv2_10_30 = new TGraphErrors(row_PT_Lambda, PT_Lambda, Fv2total_TRENTo_Lambda_1030, 0, Fv2total_TRENTo_Lambda_Error_1030);
    TGraphErrors * grLmTRENTo_Fv2_30_50 = new TGraphErrors(row_PT_Lambda, PT_Lambda, Fv2total_TRENTo_Lambda_3050, 0, Fv2total_TRENTo_Lambda_Error_3050);
    TGraphErrors * grLmTRENTo_Fv2_50_80 = new TGraphErrors(row_PT_Lambda, PT_Lambda, Fv2total_TRENTo_Lambda_5080, 0, Fv2total_TRENTo_Lambda_Error_5080);




    TFile * fAMPT = new TFile("AMPT.root", "recreate");
    grChAMPT_v22_5_10 ->Write("grCh_v22_5_10");
    grChAMPT_v22_10_30->Write("grCh_v22_10_30");
    grChAMPT_v22_30_50->Write("grCh_v22_30_50");
    grChAMPT_v22_50_80->Write("grCh_v22_50_80");

    grChAMPT_v24_5_10 ->Write("grCh_v24_5_10");
    grChAMPT_v24_10_30->Write("grCh_v24_10_30");
    grChAMPT_v24_30_50->Write("grCh_v24_30_50");
    grChAMPT_v24_50_80->Write("grCh_v24_50_80");

    grChAMPT_Fv2_5_10 ->Write("grCh_Fv2_5_10");
    grChAMPT_Fv2_10_30->Write("grCh_Fv2_10_30");
    grChAMPT_Fv2_30_50->Write("grCh_Fv2_30_50");
    grChAMPT_Fv2_50_80->Write("grCh_Fv2_50_80");

    grKsAMPT_v22_5_10 ->Write("grKs_v22_5_10");
    grKsAMPT_v22_10_30->Write("grKs_v22_10_30");
    grKsAMPT_v22_30_50->Write("grKs_v22_30_50");
    grKsAMPT_v22_50_80->Write("grKs_v22_50_80");

    grKsAMPT_v24_5_10 ->Write("grKs_v24_5_10");
    grKsAMPT_v24_10_30->Write("grKs_v24_10_30");
    grKsAMPT_v24_30_50->Write("grKs_v24_30_50");
    grKsAMPT_v24_50_80->Write("grKs_v24_50_80");

    grKsAMPT_Fv2_5_10 ->Write("grKs_Fv2_5_10");
    grKsAMPT_Fv2_10_30->Write("grKs_Fv2_10_30");
    grKsAMPT_Fv2_30_50->Write("grKs_Fv2_30_50");
    grKsAMPT_Fv2_50_80->Write("grKs_Fv2_50_80");

    grLmAMPT_v22_5_10 ->Write("grLm_v22_5_10");
    grLmAMPT_v22_10_30->Write("grLm_v22_10_30");
    grLmAMPT_v22_30_50->Write("grLm_v22_30_50");
    grLmAMPT_v22_50_80->Write("grLm_v22_50_80");

    grLmAMPT_v24_5_10 ->Write("grLm_v24_5_10");
    grLmAMPT_v24_10_30->Write("grLm_v24_10_30");
    grLmAMPT_v24_30_50->Write("grLm_v24_30_50");
    grLmAMPT_v24_50_80->Write("grLm_v24_50_80");

    grLmAMPT_Fv2_5_10 ->Write("grLm_Fv2_5_10");
    grLmAMPT_Fv2_10_30->Write("grLm_Fv2_10_30");
    grLmAMPT_Fv2_30_50->Write("grLm_Fv2_30_50");
    grLmAMPT_Fv2_50_80->Write("grLm_Fv2_50_80");

    TFile * fTrento = new TFile("Trento.root", "recreate");
    grChTrento_v22_5_10 ->Write("grCh_v22_5_10");
    grChTrento_v22_10_30->Write("grCh_v22_10_30");
    grChTrento_v22_30_50->Write("grCh_v22_30_50");
    grChTrento_v22_50_80->Write("grCh_v22_50_80");

    grChTrento_v24_5_10 ->Write("grCh_v24_5_10");
    grChTrento_v24_10_30->Write("grCh_v24_10_30");
    grChTrento_v24_30_50->Write("grCh_v24_30_50");
    grChTrento_v24_50_80->Write("grCh_v24_50_80");

    grChTRENTo_Fv2_5_10 ->Write("grCh_Fv2_5_10");
    grChTRENTo_Fv2_10_30->Write("grCh_Fv2_10_30");
    grChTRENTo_Fv2_30_50->Write("grCh_Fv2_30_50");
    grChTRENTo_Fv2_50_80->Write("grCh_Fv2_50_80");

    grKsTrento_v22_5_10 ->Write("grKs_v22_5_10");
    grKsTrento_v22_10_30->Write("grKs_v22_10_30");
    grKsTrento_v22_30_50->Write("grKs_v22_30_50");
    grKsTrento_v22_50_80->Write("grKs_v22_50_80");

    grKsTrento_v24_5_10 ->Write("grKs_v24_5_10");
    grKsTrento_v24_10_30->Write("grKs_v24_10_30");
    grKsTrento_v24_30_50->Write("grKs_v24_30_50");
    grKsTrento_v24_50_80->Write("grKs_v24_50_80");

    grKsTRENTo_Fv2_5_10 ->Write("grKs_Fv2_5_10");
    grKsTRENTo_Fv2_10_30->Write("grKs_Fv2_10_30");
    grKsTRENTo_Fv2_30_50->Write("grKs_Fv2_30_50");
    grKsTRENTo_Fv2_50_80->Write("grKs_Fv2_50_80");

    grLmTrento_v22_5_10 ->Write("grLm_v22_5_10");
    grLmTrento_v22_10_30->Write("grLm_v22_10_30");
    grLmTrento_v22_30_50->Write("grLm_v22_30_50");
    grLmTrento_v22_50_80->Write("grLm_v22_50_80");

    grLmTrento_v24_5_10 ->Write("grLm_v24_5_10");
    grLmTrento_v24_10_30->Write("grLm_v24_10_30");
    grLmTrento_v24_30_50->Write("grLm_v24_30_50");
    grLmTrento_v24_50_80->Write("grLm_v24_50_80");

    grLmTRENTo_Fv2_5_10 ->Write("grLm_Fv2_5_10");
    grLmTRENTo_Fv2_10_30->Write("grLm_Fv2_10_30");
    grLmTRENTo_Fv2_30_50->Write("grLm_Fv2_30_50");
    grLmTRENTo_Fv2_50_80->Write("grLm_Fv2_50_80");

}
