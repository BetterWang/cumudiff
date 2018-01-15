#include "../../../style.h"


void splitCanv(TCanvas *);
void InitHist2(TH1*, const char *xtit, const char *ytit  = "Number of Entries", EColor      color = kBlack);

const double Ks_mass_min = 0.45;
const double Ks_mass_max = 0.55;
//const double Ks_mass_min = 0.43;
//const double Ks_mass_max = 0.565;
const double Lm_mass_min = 1.10;
const double Lm_mass_max = 1.14;

// PbPb Lm
//                                     0,     1,     2,     3,     4,     5,     6,     7,     8,     9,    10,    11,   12
const double dbPbPbLm_sig1[13] = { 100e3, 100e3, 100e3,   3e3,  33e3, 660e3, 486e3, 436e3, 258e3,   3e3,   3e3,   3e3,   3e3};
const double dbPbPbLm_sig2[13] = { 100e3, 100e3, 100e3,   3e3,  33e3, 897e3, 698e3, 638e3, 376e3,   3e3,   3e3,   3e3,   3e3};
const double dbPbPbLm_sigp[13] = { 100e3, 100e3, 100e3,  13e3,  33e3, 725e3, 665e3, 565e3, 333e3,  13e3,  13e3,  13e3,  13e3};
const double dbPbPbLm_ap  [13] = {     0,     0,     0,- .200,- .200, 0.810, 0.810, 0.810, .0040,- .200,- .200,- .200,- .200};
const double dbPbPbLm_bp  [13] = {     0,     0,     0,  .285,  .285, 1.367, 1.367, 1.367,-.4000,  .285,  .285,  .285,  .285};
const double dbPbPbLm_cp  [13] = {     0,     0,     0,- .280,- .280, .3242, .3242, .3242, .1494,- .280,- .280,- .280,- .280};
const double dbPbPbLm_dp  [13] = {     0,     0,     0,  .176,  .176, 0.463, 0.463, 0.463,-.1105,  .176,  .176,  .176,  .176};

/*   Lm 1.1 - 1.13
// PbPb Lm
//                                     0,     1,     2,     3,     4,     5,     6,     7,     8,     9,    10,   11,   12
const double dbPbPbLm_sig1[13] = { 100e3, 100e3, 100e3, 182e3, 604e3, 660e3, 486e3, 436e3, 258e3,  98e3, 34142,  6881,  2350};
const double dbPbPbLm_sig2[13] = { 100e3, 100e3, 100e3, 170e3, 859e3, 897e3, 698e3, 638e3, 376e3, 146e3, 36953,  4610,  3216};
const double dbPbPbLm_sigp[13] = { 100e3, 100e3, 100e3, 503e3,5121e3,5725e3,2665e3,2065e3, 333e3, 242e3, 16505, 10309,  3524};
const double dbPbPbLm_ap  [13] = {     0,     0,     0,-.4376, 0.740, 0.810, 0.810, 0.810, .5040, .2614,-3.206,-1.246,-2.560};
const double dbPbPbLm_bp  [13] = {     0,     0,     0, 1.289, 1.367, 1.367, 1.367, 1.367, 1.400, 1.400, 1.536, 1.456, 1.285};
const double dbPbPbLm_cp  [13] = {     0,     0,     0,-.1122, .3042, .3242, .3242, .3242, .2494, .1521,-.9153,-.3300,-.7528};
const double dbPbPbLm_dp  [13] = {     0,     0,     0, .6984, 0.463, 0.463, 0.463, 0.463, .5105, .5768, 1.414, .9084, 1.076};
*/

// PbPb Ks
//                                     0,     1,     2,     3,     4,     5,     6,     7,     8,     9,    10,   11,   12
const double dbPbPbKs_sig1[13] = { 53866, 730e3,1630e3,1630e3,3200e3,2106e3,489449,489449,489449,198872, 82406, 17813, 17813};
const double dbPbPbKs_sig2[13] = { 58570, 980e3,2680e3,2680e3,6241e3,4248e3,735749,735749,735749,274994, 94972, 22202, 22202};
const double dbPbPbKs_sigp[13] = { 17570, 140e3, 370e3, 370e3,950406,159381,204215,204215,204215, 89369, 37466,  8006,  8006};
const double dbPbPbKs_ap  [13] = {-.4276,-.5276,-.5276,-.5276,-.2331,-.2444,-.2255,-.2255,-.2255,-.2097,-.2226,-0.188,-0.188};
const double dbPbPbKs_bp  [13] = {.43815, .4381,.43815,.43815, .2237, .2860, .3299, .3299, .3299, .3246, .2571,0.0035,0.0035};
const double dbPbPbKs_cp  [13] = {-.4343,-.1343,-.1343,-.1343,-.1106,-.0847,-.1070,-.1070,-.1070,-.1294,-.1586,-.1720,-.1720};
const double dbPbPbKs_dp  [13] = { 0.682, 0.682, 0.682, 0.682, .7775, .7053, .6252, .6252, .6252, .6124, .6001,0.4501,0.4501};


// pPb Lm
//                                       0,     1,     2,     3,     4,     5,     6,     7,     8,     9,    10,    11,   12
const double dbpPbLm250_sig1[13] = { 100e3, 100e3, 100e3, 192e3, 504e3, 504e3, 504e3, 504e3, 504e3, 140e3,  34e3,  14e3,   4e3};
const double dbpPbLm250_sig2[13] = { 100e3, 100e3, 100e3, 190e3, 504e3, 504e3, 504e3, 504e3, 504e3, 140e3,  54e3,  14e3,   4e3};
const double dbpPbLm250_sigp[13] = { 100e3, 100e3, 100e3,  53e3,   1e6,   1e6,   1e6,   1e6,   1e6,   1e6,  14e3,  14e3,  13e3};
const double dbpPbLm250_ap  [13] = {     0,     0,     0,-.4376,    0.,    0.,    0.,    0.,    0.,    0.,    .0,    0.,    0.};
const double dbpPbLm250_bp  [13] = {     0,     0,     0, .5289,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1,    .1,   0.1,   0.1};
const double dbpPbLm250_cp  [13] = {     0,     0,     0,-.5122,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.2,  -0.1,  -0.1};
const double dbpPbLm250_dp  [13] = {     0,     0,     0, .5984,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1,   0.5,   0.1,   0.1};

// pPb Lm
//                                       0,     1,     2,     3,     4,     5,     6,     7,     8,     9,    10,    11,   12
const double dbpPbLm185_sig1[13] = { 100e3, 100e3, 100e3,   1e6,  14e6,  14e6,  14e6,  14e6,  14e6,   1e6,   1e6, 134e3, 134e3};
const double dbpPbLm185_sig2[13] = { 100e3, 100e3, 100e3,   1e6,  14e6,  14e6,  14e6,  14e6,  14e6,   1e6,   1e6, 154e3, 154e3};
const double dbpPbLm185_sigp[13] = { 100e3, 100e3, 100e3, 553e3,   5e6,   5e6,   5e6,   5e6,   1e6,   1e6, 501e3, 513e3, 513e3};
const double dbpPbLm185_ap  [13] = {     0,     0,     0,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.};
const double dbpPbLm185_bp  [13] = {     0,     0,     0,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1};
const double dbpPbLm185_cp  [13] = {     0,     0,     0,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1};
const double dbpPbLm185_dp  [13] = {     0,     0,     0,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1};

// pPb Lm
//                                       0,     1,     2,     3,     4,     5,     6,     7,     8,     9,    10,    11,   12
const double dbpPbLm150_sig1[13] = { 100e3, 100e3, 100e3,   1e6,   1e6,   1e6,   1e6,   1e6,   1e6,   1e6,   1e6, 134e3, 134e3};
const double dbpPbLm150_sig2[13] = { 100e3, 100e3, 100e3,   1e6,   1e6,   1e6,   1e6,   1e6,   1e6,   1e6,   1e6, 154e3, 154e3};
const double dbpPbLm150_sigp[13] = { 100e3, 100e3, 100e3, 553e3,   1e6,   1e6,   1e6,   1e6,   1e6,   1e6, 501e3, 113e3, 113e3};
const double dbpPbLm150_ap  [13] = {     0,     0,     0,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.};
const double dbpPbLm150_bp  [13] = {     0,     0,     0,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1};
const double dbpPbLm150_cp  [13] = {     0,     0,     0,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1};
const double dbpPbLm150_dp  [13] = {     0,     0,     0,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1};

// pPb Lm
//                                       0,     1,     2,     3,     4,     5,     6,     7,     8,     9,    10,    11,   12
const double dbpPbLm120_sig1[13] = { 100e3, 100e3, 100e3,   1e6,   1e6,   1e6,   1e6,   1e6,   1e6,   1e6,   1e6, 134e3,  34e3};
const double dbpPbLm120_sig2[13] = { 100e3, 100e3, 100e3,   1e6,   1e6,   1e6,   1e6,   1e6,   1e6,   1e6,   1e6, 154e3,  54e3};
const double dbpPbLm120_sigp[13] = { 100e3, 100e3, 100e3,   1e6,   1e6,   1e6,   1e6,   1e6,   1e6,   1e6, 501e3, 113e3,  73e3};
const double dbpPbLm120_ap  [13] = {     0,     0,     0,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.};
const double dbpPbLm120_bp  [13] = {     0,     0,     0,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1};
const double dbpPbLm120_cp  [13] = {     0,     0,     0,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1};
const double dbpPbLm120_dp  [13] = {     0,     0,     0,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1,   0.1};

// pPb Ks
//                                       0,     1,     2,     3,     4,     5,     6,     7,     8,     9,    10,    11,    12
const double dbpPbKs250_sig1[13] = {  19e3, 300e3, 800e3,1000e3,2.02e6,2.02e6,1.52e6,1.52e6, 804e3, 304e3, 110e3,  30e3,  30e3};
const double dbpPbKs250_sig2[13] = {  30e3, 454e3,1354e3,2354e3,5.52e6,4.32e6,2.72e6,   2e6,   2e6, 504e3, 195e3,  45e3,  25e3};
const double dbpPbKs250_sigp[13] = {  10e3,  64e3, 214e3, 374e3, 786e3, 686e3, 586e3, 503e3, 304e3, 204e3,  78e3,  18e3,  18e3};
const double dbpPbKs250_ap  [13] = {    0.,    0.,    0.,    0.,  -0.2,  -0.2,  -0.2,  -0.2,    0.,    0.,    0.,    0.,    0.};
const double dbpPbKs250_bp  [13] = {   0.1,   0.1,   0.1,   0.1,   0.5,   0.5,   0.5,   0.5,   0.1,   0.1,   0.1,   0.1,   0.1};
const double dbpPbKs250_cp  [13] = {  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1};
const double dbpPbKs250_dp  [13] = {   0.1,   0.5,   0.5,   0.5,   0.8,   0.8,   0.8,   0.8,   0.1,   0.1,   0.1,   0.1,   0.1};

// pPb Ks
//                                       0,     1,     2,     3,     4,     5,     6,     7,     8,     9,    10,    11,    12
const double dbpPbKs185_sig1[13] = { 319e3, 300e3, 800e3,1000e3,   2e6,   2e6,  12e6,  12e6,   2e6,1.52e6,1.52e6, 304e3, 330e3};
const double dbpPbKs185_sig2[13] = { 230e3, 454e3,1354e3,2354e3,   4e6,   4e6,  34e6,  34e6,   4e6,   2e6,   2e6, 504e3, 225e3};
const double dbpPbKs185_sigp[13] = {  18e3,  64e3, 214e3, 374e3,  12e6,  12e6,   6e6,  12e6,   1e6,1503e3, 503e3, 204e3,  18e3};
const double dbpPbKs185_ap  [13] = {    0.,    0.,    0.,    0.,  -0.2,  -0.2,  -0.2,  -0.2,  -0.2,   0.0,   0.0,  -0.2,  -0.2};
const double dbpPbKs185_bp  [13] = {   0.1,   0.1,   0.1,   0.1,   0.5,   0.5,   0.5,   0.5,   0.5,   0.5,   0.5,   0.1,   0.1};
const double dbpPbKs185_cp  [13] = {  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1};
const double dbpPbKs185_dp  [13] = {   0.1,   0.5,   0.5,   0.5,   0.8,   0.8,   0.8,   0.8,   0.8,   0.8,   0.8,   0.1,   0.1};
// pPb Ks
//                                       0,     1,     2,     3,     4,     5,     6,     7,     8,     9,    10,    11,    12
const double dbpPbKs150_sig1[13] = { 109e3, 300e3, 800e3,1000e3,   2e6,   2e6,  12e6,  12e6,   2e6,1.52e6,1.52e6, 104e3, 104e3};
const double dbpPbKs150_sig2[13] = { 100e3, 454e3,1354e3,2354e3,   4e6,   4e6,  34e6,  34e6,   4e6,   2e6,   2e6, 104e3, 104e3};
const double dbpPbKs150_sigp[13] = {  18e3,  64e3, 214e3, 374e3,  12e6,  12e6,   6e6,  12e6,   1e6,1503e3, 503e3,  34e3,  34e3};
const double dbpPbKs150_ap  [13] = {  -0.2,    0.,    0.,    0.,  -0.2,  -0.2,  -0.2,  -0.2,  -0.2,   0.0,   0.0,  -0.2,  -0.2};
const double dbpPbKs150_bp  [13] = {   0.1,   0.1,   0.1,   0.1,   0.5,   0.5,   0.5,   0.5,   0.5,   0.5,   0.5,   0.1,   0.1};
const double dbpPbKs150_cp  [13] = {  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1};
const double dbpPbKs150_dp  [13] = {   0.1,   0.5,   0.5,   0.5,   0.8,   0.8,   0.8,   0.8,   0.8,   0.8,   0.8,   0.1,   0.1};
// pPb Ks
//                                       0,     1,     2,     3,     4,     5,     6,     7,     8,     9,    10,    11,    12
const double dbpPbKs120_sig1[13] = {  39e3,   1e6, 800e3,1000e3,   2e6,   2e6,  12e6,  12e6,   2e6,1.52e6, 152e3,  64e3,  30e3};
const double dbpPbKs120_sig2[13] = {  20e3,   2e6,1354e3,2354e3,   4e6,   4e6,  34e6,  34e6,   4e6,   2e6, 102e3,  54e3,  25e3};
const double dbpPbKs120_sigp[13] = {  38e3,   2e6, 214e3, 374e3,  12e6,  12e6,   6e6,  12e6,   1e6,1503e3, 103e3,  34e3,  38e3};
const double dbpPbKs120_ap  [13] = {    0.,    0.,    0.,    0.,  -0.2,  -0.2,  -0.2,  -0.2,  -0.2,   0.0,   0.0,  -0.2,  -0.2};
const double dbpPbKs120_bp  [13] = {   0.1,   0.1,   0.1,   0.1,   0.5,   0.5,   0.5,   0.5,   0.5,   0.5,   0.5,   0.1,   0.1};
const double dbpPbKs120_cp  [13] = {  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1,  -0.1};
const double dbpPbKs120_dp  [13] = {   0.1,   0.5,   0.5,   0.5,   0.8,   0.8,   0.8,   0.8,   0.8,   0.8,   0.8,   0.1,   0.1};

////                                 0,     1,     2,     3,     4,     5,     6,     7,     8,     9,    10,   11,   12
//const double dbLm_sig1[13] = { 100e3, 100e3, 100e3, 182e3, 604e3, 660e3, 486e3, 418e3, 258e3,  98e3,  6881,  6881,  2350};
//const double dbLm_sig2[13] = { 100e3, 100e3, 100e3, 170e3, 859e3, 897e3, 698e3, 660e3, 376e3, 146e3,  4610,  4610,  3216};
//const double dbLm_sigp[13] = { 100e3, 100e3, 100e3, 503e3,5121e3,5725e3,2665e3, 496e3, 333e3, 242e3, 10309, 10309,  3524};
//const double dbLm_ap  [13] = {     0,     0,     0,-.4376, 0.740, 0.810, 0.810, 0.610, .5040, .2614,-1.246,-1.246,-2.560};
//const double dbLm_bp  [13] = {     0,     0,     0, 1.289, 1.367, 1.367, 1.367, 1.367, 1.400, 1.400, 1.456, 1.456, 1.285};
//const double dbLm_cp  [13] = {     0,     0,     0,-.1122, .3042, .3242, .3242, .3242, .2494, .1521,-.3300,-.3300,-.7528};
//const double dbLm_dp  [13] = {     0,     0,     0, .6984, 0.463, 0.463, 0.463, .5111, .5105, .5768, .9084, .9084, 1.076};


void perform(string fname = "PbPb15_V0_ppRecoGMO567_v4.root",
		string system = "PbPb 5.02 TeV",
		double etaMin = -2.4,
		double etaMax = 2.4,
		string ss = "all",
		int ipt = -1
		)
{
	int ndf = 10;
//	bool bPDGMass = false;
//	if ( bPDGMass ) {
//		ndf-=1;
//	}
//	SetStyle();

	bool bPbPb = (fname.find("pPb") == std::string::npos);

	const double * dbLm_sig1 ;
	const double * dbLm_sig2 ;
	const double * dbLm_sigp ;
	const double * dbLm_ap   ;
	const double * dbLm_bp   ;
	const double * dbLm_cp   ;
	const double * dbLm_dp   ;

	const double * dbKs_sig1 ;
	const double * dbKs_sig2 ;
	const double * dbKs_sigp ;
	const double * dbKs_ap   ;
	const double * dbKs_bp   ;
	const double * dbKs_cp   ;
	const double * dbKs_dp   ;
	if ( bPbPb ) {
		dbLm_sig1 = dbPbPbLm_sig1;
		dbLm_sig2 = dbPbPbLm_sig2;
		dbLm_sigp = dbPbPbLm_sigp;
		dbLm_ap   = dbPbPbLm_ap  ;
		dbLm_bp   = dbPbPbLm_bp  ;
		dbLm_cp   = dbPbPbLm_cp  ;
		dbLm_dp   = dbPbPbLm_dp  ;

		dbKs_sig1 = dbPbPbKs_sig1;
		dbKs_sig2 = dbPbPbKs_sig2;
		dbKs_sigp = dbPbPbKs_sigp;
		dbKs_ap   = dbPbPbKs_ap  ;
		dbKs_bp   = dbPbPbKs_bp  ;
		dbKs_cp   = dbPbPbKs_cp  ;
		dbKs_dp   = dbPbPbKs_dp  ;
	} else {
		// pPb

		if ( ss.find("250") != std::string::npos ) {
			dbLm_sig1 = dbpPbLm250_sig1;
			dbLm_sig2 = dbpPbLm250_sig2;
			dbLm_sigp = dbpPbLm250_sigp;
			dbLm_ap   = dbpPbLm250_ap  ;
			dbLm_bp   = dbpPbLm250_bp  ;
			dbLm_cp   = dbpPbLm250_cp  ;
			dbLm_dp   = dbpPbLm250_dp  ;

			dbKs_sig1 = dbpPbKs250_sig1;
			dbKs_sig2 = dbpPbKs250_sig2;
			dbKs_sigp = dbpPbKs250_sigp;
			dbKs_ap   = dbpPbKs250_ap  ;
			dbKs_bp   = dbpPbKs250_bp  ;
			dbKs_cp   = dbpPbKs250_cp  ;
			dbKs_dp   = dbpPbKs250_dp  ;
		} else if ( ss.find("185") != std::string::npos ) {
			dbLm_sig1 = dbpPbLm185_sig1;
			dbLm_sig2 = dbpPbLm185_sig2;
			dbLm_sigp = dbpPbLm185_sigp;
			dbLm_ap   = dbpPbLm185_ap  ;
			dbLm_bp   = dbpPbLm185_bp  ;
			dbLm_cp   = dbpPbLm185_cp  ;
			dbLm_dp   = dbpPbLm185_dp  ;

			dbKs_sig1 = dbpPbKs185_sig1;
			dbKs_sig2 = dbpPbKs185_sig2;
			dbKs_sigp = dbpPbKs185_sigp;
			dbKs_ap   = dbpPbKs185_ap  ;
			dbKs_bp   = dbpPbKs185_bp  ;
			dbKs_cp   = dbpPbKs185_cp  ;
			dbKs_dp   = dbpPbKs185_dp  ;
		} else if ( ss.find("150") != std::string::npos ) {
			dbLm_sig1 = dbpPbLm150_sig1;
			dbLm_sig2 = dbpPbLm150_sig2;
			dbLm_sigp = dbpPbLm150_sigp;
			dbLm_ap   = dbpPbLm150_ap  ;
			dbLm_bp   = dbpPbLm150_bp  ;
			dbLm_cp   = dbpPbLm150_cp  ;
			dbLm_dp   = dbpPbLm150_dp  ;

			dbKs_sig1 = dbpPbKs150_sig1;
			dbKs_sig2 = dbpPbKs150_sig2;
			dbKs_sigp = dbpPbKs150_sigp;
			dbKs_ap   = dbpPbKs150_ap  ;
			dbKs_bp   = dbpPbKs150_bp  ;
			dbKs_cp   = dbpPbKs150_cp  ;
			dbKs_dp   = dbpPbKs150_dp  ;
		} else if ( ss.find("120") != std::string::npos ) {
			dbLm_sig1 = dbpPbLm120_sig1;
			dbLm_sig2 = dbpPbLm120_sig2;
			dbLm_sigp = dbpPbLm120_sigp;
			dbLm_ap   = dbpPbLm120_ap  ;
			dbLm_bp   = dbpPbLm120_bp  ;
			dbLm_cp   = dbpPbLm120_cp  ;
			dbLm_dp   = dbpPbLm120_dp  ;

			dbKs_sig1 = dbpPbKs120_sig1;
			dbKs_sig2 = dbpPbKs120_sig2;
			dbKs_sigp = dbpPbKs120_sigp;
			dbKs_ap   = dbpPbKs120_ap  ;
			dbKs_bp   = dbpPbKs120_bp  ;
			dbKs_cp   = dbpPbKs120_cp  ;
			dbKs_dp   = dbpPbKs120_dp  ;
		}
	}


	gROOT->SetStyle("Plain");
	gStyle->SetPalette(1,0);
	using namespace RooFit;
	TFile * f = new TFile(fname.c_str());

//	TFile * fsave = new TFile("fits.root", "recreate");

	TGaxis::SetMaxDigits(3);
	RooMsgService::instance().setStreamStatus(0,kFALSE);
	RooMsgService::instance().setStreamStatus(1,kFALSE);

	TLatex latexS;
	latexS.SetTextFont(43);
	latexS.SetTextSize(22);
	latexS.SetTextAlign(13);

//	string dir[] = {
//		"vectKsMassN120",
//		"vectKsMassN150",
//		"vectKsMassN185",
//		"vectKsMassN250",
//		"vectLmMassN120",
//		"vectLmMassN150",
//		"vectLmMassN185",
//		"vectLmMassN250",
//	};

	std::map<string, string> noff_map = {
		{"vectKsMassNAll", "120 #leq N_{trk}^{offline} < 320"},
		{"vectKsMassN120", "120 #leq N_{trk}^{offline} < 150"},
		{"vectKsMassN150", "150 #leq N_{trk}^{offline} < 185"},
		{"vectKsMassN185", "185 #leq N_{trk}^{offline} < 250"},
		{"vectKsMassN250", "250 #leq N_{trk}^{offline} < 320"},
		{"vectLmMassNAll", "120 #leq N_{trk}^{offline} < 320"},
		{"vectLmMassN120", "120 #leq N_{trk}^{offline} < 150"},
		{"vectLmMassN150", "150 #leq N_{trk}^{offline} < 185"},
		{"vectLmMassN185", "185 #leq N_{trk}^{offline} < 250"},
		{"vectLmMassN250", "250 #leq N_{trk}^{offline} < 320"},
	};

	vector<double> vpt{
		0.2, // 0
		0.4, // 1
		0.6, // 2
		0.8, // 3
		1.0, // 4
		1.4, // 5
		1.8, // 6
		2.2, // 7
		2.8, // 8
		3.6, // 9
		4.6, // 10
		6.0, // 11
		7.0, // 12
		8.5  // 13
	};

	TCanvas * cMass = MakeCanvas("cMass", "cMass", 600, 800);
	splitCanv(cMass);
//	TCanvas * cEta = MakeCanvas("cEta", "cEta", 500, 500);
//	TCanvas * cPhi = MakeCanvas("cPhi", "cPhi", 500, 500);
//	cMass->SetLogy();
	TCanvas * cEtaPhi = MakeCanvas("cEtaPhi", "cEtaPhi", 500, 500);
	TCanvas * cM1 = MakeCanvas("cM", "cM", 600, 400);

	for ( auto item : noff_map ) {
		string s = item.first;
		if ( ss != "all" and s != ss ) continue;
		TDirectory * dir = (TDirectory*) f->Get(s.c_str());
		if ( dir == nullptr ) continue;
		bool bKs = (s.find("Lm") == std::string::npos);
		TH2D * hframe_ratio;
		TH2D * hframe_pull;
		if ( bKs ) {
			hframe_ratio = new TH2D("hframe_ratio", "", 1, 0.43, 0.565, 1, 0.2, 1.8);
			InitHist2(hframe_ratio, "Mass", "Ratio");

			hframe_pull = new TH2D("hframe_pull", "", 1, 0.43, 0.565, 1, -25, 25);
			InitHist2(hframe_pull, "Mass #pi+#pi (GeV)", "Pull");
		} else {
			hframe_ratio = new TH2D("hframe_ratio", "", 1, 1.08, 1.16, 1, 0.2, 1.8);
			InitHist2(hframe_ratio, "Mass", "Ratio");

			hframe_pull = new TH2D("hframe_pull", "", 1, 1.08, 1.16, 1, -25, 25);
			InitHist2(hframe_pull, "Mass #pi+p (GeV)", "Pull");
		}
//		fsave->mkdir(s.c_str());
//		fsave->cd(s.c_str());
//		TH1D * hmean = new TH1D("hmean", "hmean", 13, 0, 13);
//		TH1D * hsigma1 = new TH1D("hsigma1", "hsigma1", 13, 0, 13);
//		TH1D * hsigma2 = new TH1D("hsigma2", "hsigma2", 13, 0, 13);
//		TH1D * hsigmaS = new TH1D("hsigmaS", "hsigmaS", 13, 0, 13);
//		TH1D * hsig1 = new TH1D("hsig1", "hsig1", 13, 0, 13);
//		TH1D * hsig2 = new TH1D("hsig2", "hsig2", 13, 0, 13);
//		TH1D * hap = new TH1D("hap", "hap", 13, 0, 13);
//		TH1D * hbp = new TH1D("hbp", "hbp", 13, 0, 13);
//		TH1D * hcp = new TH1D("hcp", "hcp", 13, 0, 13);
//		TH1D * hdp = new TH1D("hdp", "hdp", 13, 0, 13);
//		TH1D * hpolysig = new TH1D("hpolysig", "hpolysig", 13, 0, 13);
		for ( int i = 0; i < 13; i++ ) {
			if ( ipt >= 0 and i != ipt ) continue;
			if ( not bKs and i < 3 ) continue;
			std::ofstream myfile;
			myfile.open(ss + ".csv", ios_base::app);
			TH3D * h3D = (TH3D*) f->Get(Form("%s/h3DPhi_%i", s.c_str(), i));
			// h3D(mass, phi, eta)
			//MakeHist(hMass, "Mass (GeV)", "count");
			TAxis * aEta = h3D->GetZaxis();
			TH1D * hMass = (TH1D*) h3D->ProjectionX(Form("hMass_%i", i), 0, -1, aEta->FindBin(etaMin), aEta->FindBin(etaMax)-1 );
			TH2D * hEtaPhi = (TH2D*) h3D->Project3D("yz");
			cEtaPhi->cd();
			hEtaPhi->Draw("colz");
			cEtaPhi->SaveAs(Form("acc_%s_%d.pdf", s.c_str(), i));

			RooRealVar x(Form("xKs_%i", i),"mass",bKs?0.43:1.08,bKs?0.565:1.16);
//			RooRealVar mean(Form("meanKs_%i", i),"mean",bKs?0.497611:1.115683);
			RooRealVar mean(Form("meanKs_%i", i),"mean",bKs?0.497611:1.115683,bKs?0.49:1.10,bKs?0.51:1.13);
			x.setRange("cut", bKs?Ks_mass_min:Lm_mass_min, bKs?Ks_mass_max:Lm_mass_max);

// Lm
//			RooRealVar sigma1(Form("sigma1_%i", i),"sigma1",0.0025,0.001,0.005);
//			RooRealVar sigma2(Form("sigma2_%i", i),"sigma2",0.0012,0.0001,0.005);

//			RooRealVar sigma1(Form("sigma1_%i", i),"sigma1",0.0075,  0.001, 0.01);
//			RooRealVar sigma2(Form("sigma2_%i", i),"sigma2",0.0033, 0.0001, 0.01);
			RooRealVar sigma1(Form("sigma1_%i", i),"sigma1",bKs?0.0075:0.0025,  0.001, 0.1);
			RooRealVar sigma2(Form("sigma2_%i", i),"sigma2",bKs?0.0035:0.0012, 0.0001, 0.1);

//			RooRealVar sig1(Form("sig1_%i", i),"signal1", bKs?dbKs_sig1[i]:dbLm_sig1[i],(bKs?dbKs_sig1[i]:dbLm_sig1[i])*.1,(bKs?dbKs_sig1[i]:dbLm_sig1[i])*100);
//			RooRealVar sig2(Form("sig2_%i", i),"signal2", bKs?dbKs_sig2[i]:dbLm_sig2[i],(bKs?dbKs_sig2[i]:dbLm_sig2[i])*.1,(bKs?dbKs_sig2[i]:dbLm_sig2[i])*100);
			RooRealVar sig1(Form("sig1_%i", i),"signal1", bKs?dbKs_sig1[i]:dbLm_sig1[i], 0, 100*(bKs?dbKs_sig1[i]:dbLm_sig1[i]));
			RooRealVar sig2(Form("sig2_%i", i),"signal2", bKs?dbKs_sig2[i]:dbLm_sig2[i], 0, 100*(bKs?dbKs_sig2[i]:dbLm_sig2[i]));

			RooGaussian gaus1(Form("gaus1_%i", i),"gaus1",x,mean,sigma1);
			RooGaussian gaus2(Form("gaus2_%i", i),"gaus2",x,mean,sigma2);

			RooDataHist data(Form("data_%i", i),"dataset",x,hMass);

			RooRealVar ap(Form("ap_%i", i),"ap", bKs?dbKs_ap[i]:dbLm_ap[i] , -5, 5);
			RooRealVar bp(Form("bp_%i", i),"bp", bKs?dbKs_bp[i]:dbLm_bp[i] , -5, 5);
			RooRealVar cp(Form("cp_%i", i),"cp", bKs?dbKs_cp[i]:dbLm_cp[i] , -5, 5);
			RooRealVar dp(Form("dp_%i", i),"dp", bKs?dbKs_dp[i]:dbLm_dp[i] , -5, 5);
			RooChebychev poly(Form("poly_%i", i),"poly",x,RooArgList(ap,bp,cp,dp));
//			RooChebychev poly("poly","poly",*x,RooArgList(ap,bp));

			RooRealVar polysig(Form("polysig_%i", i),"polysig", bKs?dbKs_sigp[i]:dbLm_sigp[i],0,100*(bKs?dbKs_sigp[i]:dbLm_sigp[i]));

			RooAddPdf sum(Form("sum_%i", i),"sum",RooArgList(gaus1,gaus2,poly),RooArgList(sig1,sig2,polysig));

//			sum.fitTo(data,Save(kFALSE),Minos(kTRUE),Range("cut"));
			RooFitResult* result = sum.fitTo(data,Save(),Minos(kTRUE),Range("cut"));

			RooPlot* xframe_ks = x.frame();
			data.plotOn(xframe_ks,Name("data"));
			sum.plotOn(xframe_ks,Components(gaus1),NormRange("cut"),LineStyle(kDashed),LineWidth(2),LineColor(kRed));
			sum.plotOn(xframe_ks,Components(gaus2),NormRange("cut"),LineStyle(kDashed),LineWidth(2),LineColor(kGreen));
			sum.plotOn(xframe_ks,Components(poly),NormRange("cut"),LineStyle(kDashed),LineWidth(2),LineColor(kBlue));
			sum.plotOn(xframe_ks,Name("sum"),NormRange("cut"),LineWidth(2),LineColor(kBlue));

			cMass->cd(1);
			xframe_ks->Draw();

			cM1->cd();
			cM1->SetLeftMargin(0.12);
			xframe_ks->Draw();

			cMass->cd(2);
			RooPlot* frame_res = x.frame(Title("Ratio Distribution"));
			RooCurve * sumCurv = xframe_ks->getCurve("sum");

			for ( int i = 1; i <= hMass->GetNbinsX(); i++ ) {
				hMass->SetBinContent(i, hMass->GetBinContent(i)/sumCurv->Eval(hMass->GetBinCenter(i)));
			}
//			InitHist2(hMass, "Mass", "Ratio");
			hMass->SetMarkerStyle(kFullCircle);
//			hMass->SetMaximum(1.8);
			hframe_ratio->Draw();
			hMass->Draw("Psame");

//			RooHist* hresid = xframe_ks->residHist();
//			frame_res->addPlotable(hMass,"P");
//			frame_res->Draw();

			cMass->cd(3);
			RooHist* hpull = xframe_ks->pullHist() ;
//			RooPlot* frame_pull = x->frame(Title("Pull Distribution")) ;
//			MakeHist(hpull, "Mass (GeV)", "Pull");
//			hpull->SetMinimum(-25.);
//			hpull->SetMaximum(25.);
//			hpull->Draw("ap");
//			frame_pull->addPlotable(hpull,"P") ;
//			frame_pull->SetMinimum(-80);
//			frame_pull->SetMaximum(80);
//			frame_pull->Draw();

			hframe_pull->Draw();
			hpull->Draw("Psame");
			double chi2 = 0.;
//			cout << " !!! hpull->GetN() = " << hpull->GetN() << endl;
			for ( int ibin = 0; ibin < hpull->GetN(); ibin++ ) {
				chi2 += hpull->GetY()[ibin]*hpull->GetY()[ibin];
			}

			cMass->cd(1);
			latexS.DrawLatexNDC(0.18, 0.9, system.c_str());
			latexS.DrawLatexNDC(0.18, 0.8, item.second.c_str());
			latexS.DrawLatexNDC(0.18, 0.7, Form("%.1f< p_{T} < %.1f GeV", vpt[i], vpt[i+1]));

			latexS.DrawLatexNDC(0.6, 0.9, Form("#chi^{2}/ndf = %.1f/%d", chi2, hpull->GetN() - ndf + 1) );
			latexS.DrawLatexNDC(0.6, 0.8, Form("covQual = %d", result->covQual()) );


			cM1->cd();
			latexS.DrawLatexNDC(0.16, 0.9, system.c_str());
			latexS.DrawLatexNDC(0.16, 0.8, item.second.c_str());
			latexS.DrawLatexNDC(0.16, 0.7, Form("%.1f< p_{T} < %.1f GeV", vpt[i], vpt[i+1]));

//			latexS.DrawLatexNDC(0.6, 0.9, Form("#chi^{2}/ndf = %.1f/%d", chi2, hpull->GetN() - ndf + 1) );
//			latexS.DrawLatexNDC(0.6, 0.8, Form("covQual = %d", result->covQual()) );

			cMass->cd(1);
			TLine *massl = new TLine(bKs?0.492:1.1115, 0, bKs?0.492:1.1115, 1000000);
			TLine *massh = new TLine(bKs?0.503:1.1200, 0, bKs?0.503:1.1200, 1000000);
			massl->Draw("same");
			massh->Draw("same");


			cMass->SaveAs(Form("fit_%s_%d.pdf", s.c_str(), i));
			cM1->SaveAs(Form("mass_%s_%d.pdf", s.c_str(), i));

			x.setRange("peak", bKs?0.492:1.1115, bKs?0.503:1.1200);

			RooAbsReal* IntG1 = gaus1.createIntegral(x, x, "peak");
			RooAbsReal* IntG2 = gaus2.createIntegral(x, x, "peak");
			RooAbsReal* IntPl = poly.createIntegral(x, x, "peak");

			double yield = sig1.getVal() * IntG1->getVal() + sig2.getVal() * IntG2->getVal();
			double tot = sig1.getVal() * IntG1->getVal() + sig2.getVal() * IntG2->getVal() + polysig.getVal() * IntPl->getVal();

			myfile << i << ",";
			myfile << mean.getVal() << ",";
			myfile << sigma1.getVal() << ",";
			myfile << sigma2.getVal() << ",";
			myfile << sig1.getVal() << ",";
			myfile << sig2.getVal() << ",";
			myfile << ap.getVal() << ",";
			myfile << bp.getVal() << ",";
			myfile << cp.getVal() << ",";
			myfile << dp.getVal() << ",";
			myfile << polysig.getVal() << ",";
			myfile << chi2 << ",";
			myfile << hpull->GetN() - ndf + 1<< ",";
			myfile << yield << ",";
			myfile << tot << ",";
			myfile << yield/tot << ",";
			myfile << result->covQual() << endl;
			myfile.close();

//			hmean->SetBinContent(i+1, mean.getVal());
//			hmean->SetBinError  (i+1, mean.getError());
//
//			if ( sig1.getVal() > sig2.getVal() ) {
//				hsigma1->SetBinContent(i+1, sigma1.getVal());
//				hsigma1->SetBinError  (i+1, sigma1.getError());
//				hsigma2->SetBinContent(i+1, sigma2.getVal());
//				hsigma2->SetBinError  (i+1, sigma2.getError());
//
//				hsig1->SetBinContent(i+1, sig1.getVal());
//				hsig1->SetBinError  (i+1, sig1.getError());
//				hsig2->SetBinContent(i+1, sig2.getVal());
//				hsig2->SetBinError  (i+1, sig2.getError());
//			} else {
//				hsigma1->SetBinContent(i+1, sigma2.getVal());
//				hsigma1->SetBinError  (i+1, sigma2.getError());
//				hsigma2->SetBinContent(i+1, sigma1.getVal());
//				hsigma2->SetBinError  (i+1, sigma1.getError());
//
//				hsig1->SetBinContent(i+1, sig2.getVal());
//				hsig1->SetBinError  (i+1, sig2.getError());
//				hsig2->SetBinContent(i+1, sig1.getVal());
//				hsig2->SetBinError  (i+1, sig1.getError());
//			}
//			hap->SetBinContent(i+1, ap.getVal());
//			hap->SetBinError  (i+1, ap.getError());
//			hbp->SetBinContent(i+1, bp.getVal());
//			hbp->SetBinError  (i+1, bp.getError());
//			hcp->SetBinContent(i+1, cp.getVal());
//			hcp->SetBinError  (i+1, cp.getError());
//			hdp->SetBinContent(i+1, dp.getVal());
//			hdp->SetBinError  (i+1, dp.getError());
//
//			hsigmaS->SetBinContent(i+1, sqrt( (sig1.getVal()*sigma1.getVal()*sigma1.getVal() + sig2.getVal()*sigma2.getVal()*sigma2.getVal())/(sig1.getVal() + sig2.getVal()) ) );
//
//			hpolysig->SetBinContent(i+1, polysig.getVal());
//			hpolysig->SetBinError  (i+1, polysig.getError());
		}
//		hmean->Write();
//		hsigma1->Write();
//		hsigma2->Write();
//		hsigmaS->Write();
//		hsig1->Write();
//		hsig2->Write();
//		hap->Write();
//		hbp->Write();
//		hcp->Write();
//		hdp->Write();
//		hpolysig->Write();
//		fsave->cd("/");
	}
}

void splitCanv(TCanvas * c)
{
	if (!c) return;

	c->cd(0);
	TPad * p1 = new TPad("pad1", "", 0., 0.45, 1., 1.);
	p1->SetLeftMargin(0.15);
	p1->SetRightMargin(0.05);
	p1->SetBottomMargin(0.);
	p1->SetTopMargin(0.07);
//	p1->SetLogy();
	p1->Draw();
	p1->SetNumber(1);

	TPad * p2 = new TPad("pad2", "", 0., 0.25, 1., 0.45);
	p2->SetLeftMargin(0.15);
	p2->SetRightMargin(0.05);
	p2->SetBottomMargin(0.);
	p2->SetTopMargin(0.);
	p2->SetGrid();
	p2->Draw();
	p2->SetNumber(2);

	TPad * p3 = new TPad("pad3", "", 0., 0.0, 1., 0.25);
	p3->SetLeftMargin(0.15);
	p3->SetRightMargin(0.05);
	p3->SetBottomMargin(0.25);
	p3->SetTopMargin(0.);
	p3->SetGrid();
	p3->Draw();
	p3->SetNumber(3);
}

void InitHist2(TH1        *hist,
	      const char *xtit,
	      const char *ytit  = "Number of Entries",
	      EColor      color = kBlack)
{
  hist->SetXTitle(xtit);
  hist->SetYTitle(ytit);
  hist->SetLineColor(color);
  hist->SetMarkerStyle(20);
  hist->SetMarkerColor(color);
  hist->SetMarkerSize (1.);
  // Strangely enough this cannot be set anywhere else??
  hist->GetXaxis()->CenterTitle();
  hist->GetXaxis()->SetTitleFont(42);
  hist->GetXaxis()->SetTitleOffset(1.1);
  hist->GetXaxis()->SetTitleSize(0.1);
  hist->GetXaxis()->SetLabelOffset(0.03);
  hist->GetXaxis()->SetLabelSize(0.10);

  hist->GetYaxis()->CenterTitle();
  hist->GetYaxis()->SetTitleFont(42);
  hist->GetYaxis()->SetTitleOffset(0.7);
  hist->GetYaxis()->SetTitleSize(0.1);
  hist->GetYaxis()->SetLabelOffset(0.03);
  hist->GetYaxis()->SetLabelSize(0.10);

  hist->SetTitle("");
  return;
}

