
//#include "v2_2_4_pt_AMPT.C"
#include "v2_2_4_pt_TRENTo.C"

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
};

void theory()
{
    TGraphErrors * grKs_v22_10_20 = new TGraphErrors(row_PT, PT, v22pt_K0s__1020,    0, v22ptError_K0s__1020);
    TGraphErrors * grKs_v22_20_30 = new TGraphErrors(row_PT, PT, v22pt_K0s__2030,    0, v22ptError_K0s__2030);
    TGraphErrors * grKs_v22_30_40 = new TGraphErrors(row_PT, PT, v22pt_K0s__3040,    0, v22ptError_K0s__3040);
    TGraphErrors * grKs_v22_40_50 = new TGraphErrors(row_PT, PT, v22pt_K0s__4050,    0, v22ptError_K0s__4050);
    TGraphErrors * grKs_v22_50_60 = new TGraphErrors(row_PT, PT, v22pt_K0s__5060,    0, v22ptError_K0s__5060);

    TGraphErrors * grKs_v24_10_20 = new TGraphErrors(row_PT, PT, v24pt_K0s__1020,    0, v24ptError_K0s__1020);
    TGraphErrors * grKs_v24_20_30 = new TGraphErrors(row_PT, PT, v24pt_K0s__2030,    0, v24ptError_K0s__2030);
    TGraphErrors * grKs_v24_30_40 = new TGraphErrors(row_PT, PT, v24pt_K0s__3040,    0, v24ptError_K0s__3040);
    TGraphErrors * grKs_v24_40_50 = new TGraphErrors(row_PT, PT, v24pt_K0s__4050,    0, v24ptError_K0s__4050);
    TGraphErrors * grKs_v24_50_60 = new TGraphErrors(row_PT, PT, v24pt_K0s__5060,    0, v24ptError_K0s__5060);

    TGraphErrors * grLm_v22_10_20 = new TGraphErrors(row_PT, PT, v22pt_Lambda_1020, 0, v22ptError_K0s__1020);
    TGraphErrors * grLm_v22_20_30 = new TGraphErrors(row_PT, PT, v22pt_Lambda_2030, 0, v22ptError_K0s__2030);
    TGraphErrors * grLm_v22_30_40 = new TGraphErrors(row_PT, PT, v22pt_Lambda_3040, 0, v22ptError_K0s__3040);
    TGraphErrors * grLm_v22_40_50 = new TGraphErrors(row_PT, PT, v22pt_Lambda_4050, 0, v22ptError_K0s__4050);
    TGraphErrors * grLm_v22_50_60 = new TGraphErrors(row_PT, PT, v22pt_Lambda_5060, 0, v22ptError_K0s__5060);

    TGraphErrors * grLm_v24_10_20 = new TGraphErrors(row_PT, PT, v24pt_Lambda_1020, 0, v24ptError_K0s__1020);
    TGraphErrors * grLm_v24_20_30 = new TGraphErrors(row_PT, PT, v24pt_Lambda_2030, 0, v24ptError_K0s__2030);
    TGraphErrors * grLm_v24_30_40 = new TGraphErrors(row_PT, PT, v24pt_Lambda_3040, 0, v24ptError_K0s__3040);
    TGraphErrors * grLm_v24_40_50 = new TGraphErrors(row_PT, PT, v24pt_Lambda_4050, 0, v24ptError_K0s__4050);
    TGraphErrors * grLm_v24_50_60 = new TGraphErrors(row_PT, PT, v24pt_Lambda_5060, 0, v24ptError_K0s__5060);

    TGraphErrors * grKs_v22_10_30 = merge( grKs_v22_10_20, grKs_v22_20_30 );
    TGraphErrors * grKs_v22_30_50 = merge( grKs_v22_30_40, grKs_v22_40_50 );
    TGraphErrors * grKs_v24_10_30 = merge( grKs_v24_10_20, grKs_v24_20_30 );
    TGraphErrors * grKs_v24_30_50 = merge( grKs_v24_30_40, grKs_v24_40_50 );

    TGraphErrors * grLm_v22_10_30 = merge( grLm_v22_10_20, grLm_v22_20_30 );
    TGraphErrors * grLm_v22_30_50 = merge( grLm_v22_30_40, grLm_v22_40_50 );
    TGraphErrors * grLm_v24_10_30 = merge( grLm_v24_10_20, grLm_v24_20_30 );
    TGraphErrors * grLm_v24_30_50 = merge( grLm_v24_30_40, grLm_v24_40_50 );

    TFile * f = new TFile("Trento.root", "recreate");

    grKs_v22_10_20->Write("grKs_v22_10_20");
    grKs_v22_20_30->Write("grKs_v22_20_30");
    grKs_v22_30_40->Write("grKs_v22_30_40");
    grKs_v22_40_50->Write("grKs_v22_40_50");
    grKs_v22_50_60->Write("grKs_v22_50_60");

    grKs_v24_10_20->Write("grKs_v24_10_20");
    grKs_v24_20_30->Write("grKs_v24_20_30");
    grKs_v24_30_40->Write("grKs_v24_30_40");
    grKs_v24_40_50->Write("grKs_v24_40_50");
    grKs_v24_50_60->Write("grKs_v24_50_60");

    grLm_v22_10_20->Write("grLm_v22_10_20");
    grLm_v22_20_30->Write("grLm_v22_20_30");
    grLm_v22_30_40->Write("grLm_v22_30_40");
    grLm_v22_40_50->Write("grLm_v22_40_50");
    grLm_v22_50_60->Write("grLm_v22_50_60");

    grLm_v24_10_20->Write("grLm_v24_10_20");
    grLm_v24_20_30->Write("grLm_v24_20_30");
    grLm_v24_30_40->Write("grLm_v24_30_40");
    grLm_v24_40_50->Write("grLm_v24_40_50");
    grLm_v24_50_60->Write("grLm_v24_50_60");

    grKs_v22_10_30->Write("grKs_v22_10_30");
    grKs_v22_30_50->Write("grKs_v22_30_50");
    grKs_v24_10_30->Write("grKs_v24_10_30");
    grKs_v24_30_50->Write("grKs_v24_30_50");

    grLm_v22_10_30->Write("grLm_v22_10_30");
    grLm_v22_30_50->Write("grLm_v22_30_50");
    grLm_v24_10_30->Write("grLm_v24_10_30");
    grLm_v24_30_50->Write("grLm_v24_30_50");
}
