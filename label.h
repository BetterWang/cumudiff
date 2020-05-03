
char const * fname[] = {
	"test",							// 0 test
	"../cumu/PAHighMultiplicity0/crab_PAHM0_Kscumu_eff_v11/180125_225722/0000/",			// 1 Ks HM0 pPb
	"../cumu/PAHighMultiplicity1/crab_PAHM1_Kscumu_eff_v11/180125_225748/0000/",			// 2 Ks HM1 pPb
	"../cumu/PAHighMultiplicity7/crab_PAHM7_Kscumu_eff_v11/180125_230027/0000/",			// 3 Ks HM7 pPb
	"../cumu/PAHighMultiplicity0/crab_PAHM0_Kscumu_eff_reverse_v11/180125_230250/0000/",			// 4 Ks HM0 pPb reverse
	"../cumu/PAHighMultiplicity1/crab_PAHM1_Kscumu_eff_reverse_v11/180125_230315/0000/",			// 5 Ks HM1 pPb reverse
	"../cumu/PAHighMultiplicity7/crab_PAHM7_Kscumu_eff_reverse_v11/180125_230555/0000/",			// 6 Ks HM7 pPb reverse
	"NA",			// 7 Ks HM0 pPb merge
	"NA",			// 8 Ks HM1 pPb merge
	"NA",			// 9 Ks HM7 pPb merge
	"../cumu/PAHighMultiplicity0/crab_PAHM0_Lambda_cumu_eff_v11/180119_195527/0000/",			// 10 Lambda HM0 pPb
	"../cumu/PAHighMultiplicity1/crab_PAHM1_Lambda_cumu_eff_v11/180119_195101/0000/",			// 11 Lambda HM1 pPb
	"../cumu/PAHighMultiplicity7/crab_PAHM7_Lambda_cumu_eff_v11/180119_195327/0000/",			// 12 Lambda HM7 pPb
	"../cumu/PAHighMultiplicity0/crab_PAHM0_Lambda_cumu_eff_reverse_v11/180119_195712/0000/",		// 13 Lambda HM0 pPb reverse
	"../cumu/PAHighMultiplicity1/crab_PAHM1_Lambda_cumu_eff_reverse_v11/180119_195736/0000/",		// 14 Lambda HM1 pPb reverse
	"../cumu/PAHighMultiplicity7/crab_PAHM7_Lambda_cumu_eff_reverse_v11/180119_200006/0000/",		// 15 Lambda HM7 pPb reverse
	"NA",			// 16 Lambda HM0 pPb merge
	"NA",			// 17 Lambda HM1 pPb merge
	"NA",			// 18 Lambda HM7 pPb merge
	"../cumu/PAHighMultiplicity0/crab_PAHM0_Omega_cumu_eff_v7/170629_190143/0000/",				// 19 Omega HM0 pPb
	"../cumu/PAHighMultiplicity1/crab_PAHM1_Omega_cumu_eff_v7/170629_190215/0000/",				// 20 Omega HM1 pPb
	"../cumu/PAHighMultiplicity7/crab_PAHM7_Omega_cumu_eff_v7/170629_190247/0000/",				// 21 Omega HM7 pPb
	"../cumu/PAHighMultiplicity0/crab_PAHM0_Omega_cumu_eff_reverse_v7/170629_190411/0000/",			// 22 Omega HM0 pPb reverse
	"../cumu/PAHighMultiplicity1/crab_PAHM1_Omega_cumu_eff_reverse_v7/170629_190451/0000/",			// 23 Omega HM1 pPb reverse
	"../cumu/PAHighMultiplicity7/crab_PAHM7_Omega_cumu_eff_reverse_v7/170629_190524/0000/",			// 24 Omega HM7 pPb reverse
	"NA",			// 25 Omega HM0 pPb merge
	"NA",			// 26 Omega HM1 pPb merge
	"NA",			// 27 Omega HM7 pPb merge
	"../cumu/PAHighMultiplicity2/crab_PAHM2_Kscumu_eff_v11/180125_225816/0000/",			// 28 Ks HM2 pPb
	"../cumu/PAHighMultiplicity3/crab_PAHM3_Kscumu_eff_v11/180125_225842/0000/",			// 29 Ks HM3 pPb
	"../cumu/PAHighMultiplicity4/crab_PAHM4_Kscumu_eff_v11/180125_225908/0000/",			// 30 Ks HM4 pPb
	"../cumu/PAHighMultiplicity5/crab_PAHM5_Kscumu_eff_v11/180125_225935/0000/",			// 31 Ks HM5 pPb
	"../cumu/PAHighMultiplicity6/crab_PAHM6_Kscumu_eff_v11/180125_230000/0000/",			// 32 Ks HM6 pPb
	"../cumu/PAHighMultiplicity2/crab_PAHM2_Kscumu_eff_reverse_v11/180125_230342/0000/",		// 33 Ks HM2 pPb reverse
	"../cumu/PAHighMultiplicity3/crab_PAHM3_Kscumu_eff_reverse_v11/180125_230409/0000/",		// 34 Ks HM3 pPb reverse
	"../cumu/PAHighMultiplicity4/crab_PAHM4_Kscumu_eff_reverse_v11/180125_230436/0000/",		// 35 Ks HM4 pPb reverse
	"../cumu/PAHighMultiplicity5/crab_PAHM5_Kscumu_eff_reverse_v11/180125_230502/0000/",		// 36 Ks HM5 pPb reverse
	"../cumu/PAHighMultiplicity6/crab_PAHM6_Kscumu_eff_reverse_v11/180125_230528/0000/",		// 37 Ks HM6 pPb reverse
	"../cumu/PAHighMultiplicity2/crab_PAHM2_Lambda_cumu_eff_v11/180119_195125/0000/",		// 38 Lambda HM2 pPb
	"../cumu/PAHighMultiplicity3/crab_PAHM3_Lambda_cumu_eff_v11/180119_195149/0000/",		// 39 Lambda HM3 pPb
	"../cumu/PAHighMultiplicity4/crab_PAHM4_Lambda_cumu_eff_v11/180119_195213/0000/",		// 40 Lambda HM4 pPb
	"../cumu/PAHighMultiplicity5/crab_PAHM5_Lambda_cumu_eff_v11/180119_195238/0000/",		// 41 Lambda HM5 pPb
	"../cumu/PAHighMultiplicity6/crab_PAHM6_Lambda_cumu_eff_v11/180119_195302/0000/",		// 42 Lambda HM6 pPb
	"../cumu/PAHighMultiplicity2/crab_PAHM2_Lambda_cumu_eff_reverse_v11/180119_195801/0000/",	// 43 Lambda HM2 pPb reverse
	"../cumu/PAHighMultiplicity3/crab_PAHM3_Lambda_cumu_eff_reverse_v11/180119_195826/0000/",	// 44 Lambda HM3 pPb reverse
	"../cumu/PAHighMultiplicity4/crab_PAHM4_Lambda_cumu_eff_reverse_v11/180119_195852/0000/",	// 45 Lambda HM4 pPb reverse
	"../cumu/PAHighMultiplicity5/crab_PAHM5_Lambda_cumu_eff_reverse_v11/180119_195916/0000/",	// 46 Lambda HM5 pPb reverse
	"../cumu/PAHighMultiplicity6/crab_PAHM6_Lambda_cumu_eff_reverse_v11/180119_195941/0000/",	// 47 Lambda HM6 pPb reverse
	"../CumuV0/HIMinimumBias5/crab_HIMB5_V0cumu_ppRecoGMO_Ks_rapidity_v1/180221_184238/0000/",	// 48 Ks HIMB5
	"../CumuV0/HIMinimumBias6/crab_HIMB6_V0cumu_ppRecoGMO_Ks_rapidity_v1/180221_184252/0000/",	// 49 Ks HIMB6
	"../CumuV0/HIMinimumBias7/crab_HIMB7_V0cumu_ppRecoGMO_Ks_rapidity_v1/180221_184306/0000/",	// 50 Ks HIMB7
	"../CumuV0/HIMinimumBias5/crab_HIMB5_V0cumu_ppRecoGMO_Lm_rapidity_v1/180221_190620/0000/",	// 51 Lambda HIMB5
	"../CumuV0/HIMinimumBias6/crab_HIMB6_V0cumu_ppRecoGMO_Lm_rapidity_v1/180221_190635/0000/",	// 52 Lambda HIMB6
	"../CumuV0/HIMinimumBias7/crab_HIMB7_V0cumu_ppRecoGMO_Lm_rapidity_v1/180221_190651/0000/",	// 53 Lambda HIMB7
	"NA",			// 54 Ks merged HIMB567
	"NA",			// 55 Lambda merged HIMB567
	"NA",			// 56 Ks HM123456 pPb
	"NA",			// 57 Ks HM123456 pPb reverse
	"NA",			// 58 Lm HM123456 pPb
	"NA",			// 59 Lm HM123456 pPb reverse
	"../cumu/PAHighMultiplicity0/crab_PAHM0_KscumuSBPos_eff_v1/180128_050300/0000/",			// 60 Ks HM0 pPb SB Pos
	"../cumu/PAHighMultiplicity1/crab_PAHM1_KscumuSBPos_eff_v1/180128_050314/0000/",			// 61 Ks HM1 pPb SB Pos
	"../cumu/PAHighMultiplicity2/crab_PAHM2_KscumuSBPos_eff_v1/180128_050326/0000/",			// 62 Ks HM2 pPb SB Pos
	"../cumu/PAHighMultiplicity3/crab_PAHM3_KscumuSBPos_eff_v1/180128_050338/0000/",			// 63 Ks HM3 pPb SB Pos
	"../cumu/PAHighMultiplicity4/crab_PAHM4_KscumuSBPos_eff_v1/180128_050350/0000/",			// 64 Ks HM4 pPb SB Pos
	"../cumu/PAHighMultiplicity5/crab_PAHM5_KscumuSBPos_eff_v1/180128_050402/0000/",			// 65 Ks HM5 pPb SB Pos
	"../cumu/PAHighMultiplicity6/crab_PAHM6_KscumuSBPos_eff_v1/180128_050414/0000/",			// 66 Ks HM6 pPb SB Pos
	"../cumu/PAHighMultiplicity7/crab_PAHM7_KscumuSBPos_eff_v1/180128_050426/0000/",			// 67 Ks HM7 pPb SB Pos
	"../cumu/PAHighMultiplicity0/crab_PAHM0_KscumuSBPos_eff_reverse_v1/180201_155045/0000/",		// 68 Ks HM0 pPb SB Pos reverse
	"../cumu/PAHighMultiplicity1/crab_PAHM1_KscumuSBPos_eff_reverse_v1/180201_155059/0000/",		// 69 Ks HM1 pPb SB Pos reverse
	"../cumu/PAHighMultiplicity2/crab_PAHM2_KscumuSBPos_eff_reverse_v1/180201_155113/0000/",		// 70 Ks HM2 pPb SB Pos reverse
	"../cumu/PAHighMultiplicity3/crab_PAHM3_KscumuSBPos_eff_reverse_v1/180201_155127/0000/",		// 71 Ks HM3 pPb SB Pos reverse
	"../cumu/PAHighMultiplicity4/crab_PAHM4_KscumuSBPos_eff_reverse_v1/180201_155142/0000/",		// 72 Ks HM4 pPb SB Pos reverse
	"../cumu/PAHighMultiplicity5/crab_PAHM5_KscumuSBPos_eff_reverse_v1/180201_155200/0000/",		// 73 Ks HM5 pPb SB Pos reverse
	"../cumu/PAHighMultiplicity6/crab_PAHM6_KscumuSBPos_eff_reverse_v1/180201_155215/0000/",		// 74 Ks HM6 pPb SB Pos reverse
	"../cumu/PAHighMultiplicity7/crab_PAHM7_KscumuSBPos_eff_reverse_v1/180201_155231/0000/",		// 75 Ks HM7 pPb SB Pos reverse
	"NA",			// 76 Ks HM0 pPb SB Pos merge
	"NA",			// 77 Ks HM123456 pPb SB Pos merge
	"NA",			// 78 Ks HM7 pPb SB Pos merge
	"../cumu/PAHighMultiplicity0/crab_PAHM0_LambdaSBPos_cumu_eff_v1/180202_212701/0000/",			// 79 Lm HM0 pPb SB Pos
	"../cumu/PAHighMultiplicity1/crab_PAHM1_LambdaSBPos_cumu_eff_v1/180202_212726/0000/",			// 80 Lm HM1 pPb SB Pos
	"../cumu/PAHighMultiplicity2/crab_PAHM2_LambdaSBPos_cumu_eff_v1/180202_212753/0000/",			// 81 Lm HM2 pPb SB Pos
	"../cumu/PAHighMultiplicity3/crab_PAHM3_LambdaSBPos_cumu_eff_v1/180202_212817/0000/",			// 82 Lm HM3 pPb SB Pos
	"../cumu/PAHighMultiplicity4/crab_PAHM4_LambdaSBPos_cumu_eff_v1/180202_212842/0000/",			// 83 Lm HM4 pPb SB Pos
	"../cumu/PAHighMultiplicity5/crab_PAHM5_LambdaSBPos_cumu_eff_v1/180202_212907/0000/",			// 84 Lm HM5 pPb SB Pos
	"../cumu/PAHighMultiplicity6/crab_PAHM6_LambdaSBPos_cumu_eff_v1/180202_212933/0000/",			// 85 Lm HM6 pPb SB Pos
	"../cumu/PAHighMultiplicity7/crab_PAHM7_LambdaSBPos_cumu_eff_v1/180202_212958/0000/",			// 86 Lm HM7 pPb SB Pos
	"../cumu/PAHighMultiplicity0/crab_PAHM0_LambdaSBPos_cumu_eff_reverse_v1/180202_214945/0000/",		// 87 Lm HM0 pPb SB Pos reverse
	"../cumu/PAHighMultiplicity1/crab_PAHM1_LambdaSBPos_cumu_eff_reverse_v1/180202_215011/0000/",		// 88 Lm HM1 pPb SB Pos reverse
	"../cumu/PAHighMultiplicity2/crab_PAHM2_LambdaSBPos_cumu_eff_reverse_v1/180202_215036/0000/",		// 89 Lm HM2 pPb SB Pos reverse
	"../cumu/PAHighMultiplicity3/crab_PAHM3_LambdaSBPos_cumu_eff_reverse_v1/180202_215100/0000/",		// 90 Lm HM3 pPb SB Pos reverse
	"../cumu/PAHighMultiplicity4/crab_PAHM4_LambdaSBPos_cumu_eff_reverse_v1/180202_215125/0000/",		// 91 Lm HM4 pPb SB Pos reverse
	"../cumu/PAHighMultiplicity5/crab_PAHM5_LambdaSBPos_cumu_eff_reverse_v1/180202_215150/0000/",		// 92 Lm HM5 pPb SB Pos reverse
	"../cumu/PAHighMultiplicity6/crab_PAHM6_LambdaSBPos_cumu_eff_reverse_v1/180202_215215/0000/",		// 93 Lm HM6 pPb SB Pos reverse
	"../cumu/PAHighMultiplicity7/crab_PAHM7_LambdaSBPos_cumu_eff_reverse_v1/180202_215239/0000/",		// 94 Lm HM7 pPb SB Pos reverse
	"NA",			// 95 Lm HM0 pPb SB Pos merge
	"NA",			// 96 Lm HM123456 pPb SB Pos merge
	"NA",			// 97 Lm HM7 pPb SB Pos merge
	"../cumu/PAHighMultiplicity0/crab_PAHM0_KscumuSBNeg_eff_v1/180202_155823/0000/",			// 98  Ks HM0 pPb SB Neg
	"../cumu/PAHighMultiplicity1/crab_PAHM1_KscumuSBNeg_eff_v1/180202_155835/0000/",			// 99  Ks HM1 pPb SB Neg
	"../cumu/PAHighMultiplicity2/crab_PAHM2_KscumuSBNeg_eff_v1/180202_155848/0000/",			// 100 Ks HM2 pPb SB Neg
	"../cumu/PAHighMultiplicity3/crab_PAHM3_KscumuSBNeg_eff_v1/180202_155900/0000/",			// 101 Ks HM3 pPb SB Neg
	"../cumu/PAHighMultiplicity4/crab_PAHM4_KscumuSBNeg_eff_v1/180202_155912/0000/",			// 102 Ks HM4 pPb SB Neg
	"../cumu/PAHighMultiplicity5/crab_PAHM5_KscumuSBNeg_eff_v1/180202_155925/0000/",			// 103 Ks HM5 pPb SB Neg
	"../cumu/PAHighMultiplicity6/crab_PAHM6_KscumuSBNeg_eff_v1/180202_155939/0000/",			// 104 Ks HM6 pPb SB Neg
	"../cumu/PAHighMultiplicity7/crab_PAHM7_KscumuSBNeg_eff_v1/180202_155953/0000/",			// 105 Ks HM7 pPb SB Neg
	"../cumu/PAHighMultiplicity0/crab_PAHM0_KscumuSBNeg_eff_reverse_v1/180202_164544/0000/",		// 106 Ks HM0 pPb SB Neg reverse
	"../cumu/PAHighMultiplicity1/crab_PAHM1_KscumuSBNeg_eff_reverse_v1/180202_164559/0000/",		// 107 Ks HM1 pPb SB Neg reverse
	"../cumu/PAHighMultiplicity2/crab_PAHM2_KscumuSBNeg_eff_reverse_v1/180202_164614/0000/",		// 108 Ks HM2 pPb SB Neg reverse
	"../cumu/PAHighMultiplicity3/crab_PAHM3_KscumuSBNeg_eff_reverse_v1/180202_164629/0000/",		// 109 Ks HM3 pPb SB Neg reverse
	"../cumu/PAHighMultiplicity4/crab_PAHM4_KscumuSBNeg_eff_reverse_v1/180202_164643/0000/",		// 110 Ks HM4 pPb SB Neg reverse
	"../cumu/PAHighMultiplicity5/crab_PAHM5_KscumuSBNeg_eff_reverse_v1/180202_164658/0000/",		// 111 Ks HM5 pPb SB Neg reverse
	"../cumu/PAHighMultiplicity6/crab_PAHM6_KscumuSBNeg_eff_reverse_v1/180202_164711/0000/",		// 112 Ks HM6 pPb SB Neg reverse
	"../cumu/PAHighMultiplicity7/crab_PAHM7_KscumuSBNeg_eff_reverse_v1/180202_164724/0000/",		// 113 Ks HM7 pPb SB Neg reverse
	"NA",			// 114 Ks HM0 pPb SB Neg merge
	"NA",			// 115 Ks HM123456 pPb SB Neg merge
	"NA",			// 116 Ks HM7 pPb SB Neg merge
	"../cumu/PAHighMultiplicity0/crab_PAHM0_LambdaSBNeg_cumu_eff_v1/180204_224419/0000/",			// 117 Lm HM0 pPb SB Neg
	"../cumu/PAHighMultiplicity1/crab_PAHM1_LambdaSBNeg_cumu_eff_v1/180204_224432/0000/",			// 118 Lm HM1 pPb SB Neg
	"../cumu/PAHighMultiplicity2/crab_PAHM2_LambdaSBNeg_cumu_eff_v1/180204_224444/0000/",			// 119 Lm HM2 pPb SB Neg
	"../cumu/PAHighMultiplicity3/crab_PAHM3_LambdaSBNeg_cumu_eff_v1/180204_224456/0000/",			// 120 Lm HM3 pPb SB Neg
	"../cumu/PAHighMultiplicity4/crab_PAHM4_LambdaSBNeg_cumu_eff_v1/180204_224508/0000/",			// 121 Lm HM4 pPb SB Neg
	"../cumu/PAHighMultiplicity5/crab_PAHM5_LambdaSBNeg_cumu_eff_v1/180204_224520/0000/",			// 122 Lm HM5 pPb SB Neg
	"../cumu/PAHighMultiplicity6/crab_PAHM6_LambdaSBNeg_cumu_eff_v1/180204_224533/0000/",			// 123 Lm HM6 pPb SB Neg
	"../cumu/PAHighMultiplicity7/crab_PAHM7_LambdaSBNeg_cumu_eff_v1/180204_224546/0000/",			// 124 Lm HM7 pPb SB Neg
	"../cumu/PAHighMultiplicity0/crab_PAHM0_LambdaSBNeg_cumu_eff_reverse_v1/180204_224952/0000/",		// 125 Lm HM0 pPb SB Neg reverse
	"../cumu/PAHighMultiplicity1/crab_PAHM1_LambdaSBNeg_cumu_eff_reverse_v1/180204_225005/0000/",		// 126 Lm HM1 pPb SB Neg reverse
	"../cumu/PAHighMultiplicity2/crab_PAHM2_LambdaSBNeg_cumu_eff_reverse_v1/180204_225017/0000/",		// 127 Lm HM2 pPb SB Neg reverse
	"../cumu/PAHighMultiplicity3/crab_PAHM3_LambdaSBNeg_cumu_eff_reverse_v1/180204_225030/0000/",		// 128 Lm HM3 pPb SB Neg revers
	"../cumu/PAHighMultiplicity4/crab_PAHM4_LambdaSBNeg_cumu_eff_reverse_v1/180204_225042/0000/",		// 129 Lm HM4 pPb SB Neg reverse
	"../cumu/PAHighMultiplicity5/crab_PAHM5_LambdaSBNeg_cumu_eff_reverse_v1/180204_225055/0000/",		// 130 Lm HM5 pPb SB Neg reverse
	"../cumu/PAHighMultiplicity6/crab_PAHM6_LambdaSBNeg_cumu_eff_reverse_v1/180204_225109/0000/",		// 131 Lm HM6 pPb SB Neg reverse
	"../cumu/PAHighMultiplicity7/crab_PAHM7_LambdaSBNeg_cumu_eff_reverse_v1/180204_225122/0000/",		// 132 Lm HM7 pPb SB Neg reverse
	"NA",			// 133 Lm HM0 pPb SB Neg merge
	"NA",			// 134 Lm HM123456 pPb SB Neg merge
	"NA",			// 135 Lm HM7 pPb SB Neg merge
	"NA",			// 136 Ks HM0 pPb SB
	"NA",			// 137 Ks HM123456 pPb SB
	"NA",			// 138 Ks HM7 pPb SB
	"NA",			// 139 Lm HM0 pPb SB
	"NA",			// 140 Lm HM123456 pPb SB
	"NA",			// 141 Lm HM7 pPb SB
	"../CumuV0/HIMinimumBias5/crab_HIMB5_V0cumu_ppRecoGMO_KsSBPos_rapidity_v1/180225_201523/0000/",		// 142 Ks HIMB5 PbPb SBPos
	"../CumuV0/HIMinimumBias6/crab_HIMB6_V0cumu_ppRecoGMO_KsSBPos_rapidity_v1/180225_201536/0000/",		// 143 Ks HIMB6 PbPb SBPos
	"../CumuV0/HIMinimumBias7/crab_HIMB7_V0cumu_ppRecoGMO_KsSBPos_rapidity_v1/180225_201549/0000/",		// 144 Ks HIMB7 PbPb SBPos
	"../CumuV0/HIMinimumBias5/crab_HIMB5_V0cumu_ppRecoGMO_KsSBNeg_rapidity_v1/180225_212842/0000/",		// 145 Ks HIMB5 PbPb SBNeg
	"../CumuV0/HIMinimumBias6/crab_HIMB6_V0cumu_ppRecoGMO_KsSBNeg_rapidity_v1/180225_212855/0000/",		// 146 Ks HIMB6 PbPb SBNeg
	"../CumuV0/HIMinimumBias7/crab_HIMB7_V0cumu_ppRecoGMO_KsSBNeg_rapidity_v1/180225_212908/0000/",		// 147 Ks HIMB7 PbPb SBNeg
	"../CumuV0/HIMinimumBias5/crab_HIMB5_V0cumu_ppRecoGMO_LmSBPos_rapidity_v1/180226_051608/0000/",		// 148 Lm HIMB5 PbPb SBPos
	"../CumuV0/HIMinimumBias6/crab_HIMB6_V0cumu_ppRecoGMO_LmSBPos_rapidity_v1/180226_051623/0000/",		// 149 Lm HIMB6 PbPb SBPos
	"../CumuV0/HIMinimumBias7/crab_HIMB7_V0cumu_ppRecoGMO_LmSBPos_rapidity_v1/180226_051642/0000/",		// 150 Lm HIMB7 PbPb SBPos
	"../CumuV0/HIMinimumBias5/crab_HIMB5_V0cumu_ppRecoGMO_LmSBNeg_rapidity_v1/180226_051706/0000/",		// 151 Lm HIMB5 PbPb SBNeg
	"../CumuV0/HIMinimumBias6/crab_HIMB6_V0cumu_ppRecoGMO_LmSBNeg_rapidity_v1/180226_051719/0000/",		// 152 Lm HIMB6 PbPb SBNeg
	"../CumuV0/HIMinimumBias7/crab_HIMB7_V0cumu_ppRecoGMO_LmSBNeg_rapidity_v1/180226_051733/0000/",		// 153 Lm HIMB7 PbPb SBNeg
	"NA",			// 154 Ks HIMB567 PbPb SBPos
	"NA",			// 155 Ks HIMB567 PbPb SBNeg
	"NA",			// 156 Ks HIMB567 PbPb SB
	"NA",			// 157 Lm HIMB567 PbPb SBPos
	"NA",			// 158 Lm HIMB567 PbPb SBNeg
	"NA",			// 159 Lm HIMB567 PbPb SB
	"../CumuV0/HIMinimumBias5/crab_HIMB5_V0cumu_ppRecoGMO_Ks_rapidity_Cent_v3/190627_024854/0000/",		// 160 Ks HIMB5 Cent
	"../CumuV0/HIMinimumBias6/crab_HIMB6_V0cumu_ppRecoGMO_Ks_rapidity_Cent_v3/190627_024914/0000/",		// 161 Ks HIMB6 Cent
	"../CumuV0/HIMinimumBias7/crab_HIMB7_V0cumu_ppRecoGMO_Ks_rapidity_Cent_v3/190627_024934/0000/",		// 162 Ks HIMB7 Cent
	"../CumuV0/HIMinimumBias5/crab_HIMB5_V0cumu_ppRecoGMO_Lm_rapidity_Cent_v3/190627_030056/0000/",		// 163 Lm HIMB5 Cent
	"../CumuV0/HIMinimumBias6/crab_HIMB6_V0cumu_ppRecoGMO_Lm_rapidity_Cent_v3/190627_030117/0000/",		// 164 Lm HIMB6 Cent
	"../CumuV0/HIMinimumBias7/crab_HIMB7_V0cumu_ppRecoGMO_Lm_rapidity_Cent_v3/190627_030138/0000/",		// 165 Lm HIMB7 Cent
	"NA",		// 166 Ks HIMB567 Cent
	"NA",		// 167 Lm HIMB567 Cent
	"../CumuV0/HIMinimumBias5/crab_HIMB5_V0cumu_ppRecoGMO_KsSBPos_rapidity_Cent_v3/190702_032506/0000/",		// 168 Ks HIMB5 Cent SBPos
	"../CumuV0/HIMinimumBias6/crab_HIMB6_V0cumu_ppRecoGMO_KsSBPos_rapidity_Cent_v3/190702_032527/0000/",		// 169 Ks HIMB6 Cent SBPos
	"../CumuV0/HIMinimumBias7/crab_HIMB7_V0cumu_ppRecoGMO_KsSBPos_rapidity_Cent_v3/190702_032546/0000/",		// 170 Ks HIMB7 Cent SBPos
	"../CumuV0/HIMinimumBias5/crab_HIMB5_V0cumu_ppRecoGMO_KsSBNeg_rapidity_Cent_v3/190702_032922/0000/",		// 171 Ks HIMB5 Cent SBNeg
	"../CumuV0/HIMinimumBias6/crab_HIMB6_V0cumu_ppRecoGMO_KsSBNeg_rapidity_Cent_v3/190702_032941/0000/",		// 172 Ks HIMB6 Cent SBNeg
	"../CumuV0/HIMinimumBias7/crab_HIMB7_V0cumu_ppRecoGMO_KsSBNeg_rapidity_Cent_v3/190702_033000/0000/",		// 173 Ks HIMB7 Cent SBNeg
	"../CumuV0/HIMinimumBias5/crab_HIMB5_V0cumu_ppRecoGMO_LmSBPos_rapidity_Cent_v3/190702_033704/0000/",		// 174 Lm HIMB5 Cent SBPos
	"../CumuV0/HIMinimumBias6/crab_HIMB6_V0cumu_ppRecoGMO_LmSBPos_rapidity_Cent_v3/190702_033723/0000/",		// 175 Lm HIMB6 Cent SBPos
	"../CumuV0/HIMinimumBias7/crab_HIMB7_V0cumu_ppRecoGMO_LmSBPos_rapidity_Cent_v3/190702_033742/0000/",		// 176 Lm HIMB7 Cent SBPos
	"../CumuV0/HIMinimumBias5/crab_HIMB5_V0cumu_ppRecoGMO_LmSBNeg_rapidity_Cent_v4_rsb/190723_142454/0000/",		// 177 Lm HIMB5 Cent SBNeg
	"../CumuV0/HIMinimumBias6/crab_HIMB6_V0cumu_ppRecoGMO_LmSBNeg_rapidity_Cent_v3/190702_034229/0000/",		// 178 Lm HIMB6 Cent SBNeg
	"../CumuV0/HIMinimumBias7/crab_HIMB7_V0cumu_ppRecoGMO_LmSBNeg_rapidity_Cent_v4_rsb/190723_142532/0000/",		// 179 Lm HIMB7 Cent SBNeg
	"NA",		// 180 Ks HIMB567 Cent SB
	"NA",		// 181 Lm HIMB567 Cent SB
	"../cumu/PAHighMultiplicity0/crab_PAHM0_Kscumu_eff_v12_rsb/190816_193255/0000/",	// 182 Ks HM0 pPb
	"../cumu/PAHighMultiplicity1/crab_PAHM1_Kscumu_eff_v12/190708_155550/0000/",		// 183 Ks HM1 pPb
	"../cumu/PAHighMultiplicity2/crab_PAHM2_Kscumu_eff_v12/190708_155609/0000/",		// 184 Ks HM2 pPb
	"../cumu/PAHighMultiplicity3/crab_PAHM3_Kscumu_eff_v12/190708_155630/0000/",		// 185 Ks HM3 pPb
	"../cumu/PAHighMultiplicity4/crab_PAHM4_Kscumu_eff_v12/190708_155650/0000/",		// 186 Ks HM4 pPb
	"../cumu/PAHighMultiplicity5/crab_PAHM5_Kscumu_eff_v12/190708_155711/0000/",		// 187 Ks HM5 pPb
	"../cumu/PAHighMultiplicity6/crab_PAHM6_Kscumu_eff_v12_rsb/190818_044056/0000/",	// 188 Ks HM6 pPb
	"../cumu/PAHighMultiplicity7/crab_PAHM7_Kscumu_eff_v12_rsb/190816_193314/0000/",	// 189 Ks HM7 pPb
	"../cumu/PAHighMultiplicity0/crab_PAHM0_Kscumu_eff_reverse_v12_rsb/190816_193336/0000/",	// 190 Ks HM0 pPb reverse
	"../cumu/PAHighMultiplicity1/crab_PAHM1_Kscumu_eff_reverse_v12_rsb/190827_201252/0000/",	// 191 Ks HM1 pPb reverse
	"../cumu/PAHighMultiplicity2/crab_PAHM2_Kscumu_eff_reverse_v12/190802_163004/0000/",		// 192 Ks HM2 pPb reverse
	"../cumu/PAHighMultiplicity3/crab_PAHM3_Kscumu_eff_reverse_v12/190708_161206/0000/",		// 193 Ks HM3 pPb reverse
	"../cumu/PAHighMultiplicity4/crab_PAHM4_Kscumu_eff_reverse_v12/190802_163024/0000/",		// 194 Ks HM4 pPb reverse
	"../cumu/PAHighMultiplicity5/crab_PAHM5_Kscumu_eff_reverse_v12_rsb/190827_204128/0000/",	// 195 Ks HM5 pPb reverse
	"../cumu/PAHighMultiplicity6/crab_PAHM6_Kscumu_eff_reverse_v12_rsb/190818_044205/0000/",	// 196 Ks HM6 pPb reverse
	"../cumu/PAHighMultiplicity7/crab_PAHM7_Kscumu_eff_reverse_v12_rsb/190816_193356/0000/",	// 197 Ks HM7 pPb reverse
	"../cumu/PAHighMultiplicity0/crab_PAHM0_Lambda_cumu_eff_v12_rsb/190816_193054/0000/",	// 198 Lm HM0 pPb
	"../cumu/PAHighMultiplicity1/crab_PAHM1_Lambda_cumu_eff_v12/190802_163854/0000/",		// 199 Lm HM1 pPb
	"../cumu/PAHighMultiplicity2/crab_PAHM2_Lambda_cumu_eff_v12/190802_163913/0000/",		// 200 Lm HM2 pPb
	"../cumu/PAHighMultiplicity3/crab_PAHM3_Lambda_cumu_eff_v12/190802_163934/0000/",		// 201 Lm HM3 pPb
	"../cumu/PAHighMultiplicity4/crab_PAHM4_Lambda_cumu_eff_v12/190802_163954/0000/",		// 202 Lm HM4 pPb
	"../cumu/PAHighMultiplicity5/crab_PAHM5_Lambda_cumu_eff_v12/190802_164013/0000/",		// 203 Lm HM5 pPb
	"../cumu/PAHighMultiplicity6/crab_PAHM6_Lambda_cumu_eff_v12_rsb/190818_044226/0000/",	// 204 Lm HM6 pPb
	"../cumu/PAHighMultiplicity7/crab_PAHM7_Lambda_cumu_eff_v12_rsb/190816_193115/0000/",	// 205 Lm HM7 pPb
	"../cumu/PAHighMultiplicity0/crab_PAHM0_Lambda_cumu_eff_reverse_v12_rsb/190816_193419/0000/",	// 206 Lm HM0 pPb reverse
	"../cumu/PAHighMultiplicity1/crab_PAHM1_Lambda_cumu_eff_reverse_v12/190802_163542/0000/",		// 207 Lm HM1 pPb reverse
	"../cumu/PAHighMultiplicity2/crab_PAHM2_Lambda_cumu_eff_reverse_v12/190708_164645/0000/",		// 208 Lm HM2 pPb reverse
	"../cumu/PAHighMultiplicity3/crab_PAHM3_Lambda_cumu_eff_reverse_v12/190708_164727/0000/",		// 209 Lm HM3 pPb reverse
	"../cumu/PAHighMultiplicity4/crab_PAHM4_Lambda_cumu_eff_reverse_v12/190708_164753/0000/",		// 210 Lm HM4 pPb reverse
	"../cumu/PAHighMultiplicity5/crab_PAHM5_Lambda_cumu_eff_reverse_v12/190708_164815/0000/",		// 211 Lm HM5 pPb reverse
	"../cumu/PAHighMultiplicity6/crab_PAHM6_Lambda_cumu_eff_reverse_v12_rsb/190818_044251/0000/",	// 212 Lm HM6 pPb reverse
	"../cumu/PAHighMultiplicity7/crab_PAHM7_Lambda_cumu_eff_reverse_v12_rsb/190816_193438/0000/",	// 213 Lm HM7 pPb reverse
	"NA",		// 214 Ks HM123456 pPb
	"NA",		// 215 Ks HM123456 pPb reverse
	"NA",		// 216 Ks HM0 pPb merge
	"NA",		// 217 Ks HM123456 pPb merge
	"NA",		// 218 Ks HM7 pPb merge
	"NA",		// 219 Lm HM123456 pPb
	"NA",		// 220 Lm HM123456 pPb reverse
	"NA",		// 221 Lm HM0 pPb merge
	"NA",		// 222 Lm HM123456 pPb merge
	"NA",		// 223 Lm HM7 pPb merge
	"../CumuV0/HIMinimumBias5/crab_HIMB5_V0cumu_ppRecoGMO_Lm_rapidity_Cent_v4/190712_205805/0000/",		// 224 Lm HIMB5 PbPb Cent Update
	"../CumuV0/HIMinimumBias6/crab_HIMB6_V0cumu_ppRecoGMO_Lm_rapidity_Cent_v4/190712_205827/0000/",		// 225 Lm HIMB6 PbPb Cent Update
	"../CumuV0/HIMinimumBias7/crab_HIMB7_V0cumu_ppRecoGMO_Lm_rapidity_Cent_v4/190712_205849/0000/",		// 226 Lm HIMB7 PbPb Cent Update
	"NA",		// 227 Lm HIMB567 PbPb Cent Update
	"../CumuV0/HIMinimumBias5/crab_HIMB5_V0cumu_ppRecoGMO_LmSBPos_rapidity_Cent_v4/190712_210126/0000/",		// 228 Lm HIMB5 PbPb Cent SBPos Update
	"../CumuV0/HIMinimumBias6/crab_HIMB6_V0cumu_ppRecoGMO_LmSBPos_rapidity_Cent_v4/190712_210153/0000/",		// 229 Lm HIMB6 PbPb Cent SBPos Update
	"../CumuV0/HIMinimumBias7/crab_HIMB7_V0cumu_ppRecoGMO_LmSBPos_rapidity_Cent_v4/190712_210219/0000/",		// 230 Lm HIMB7 PbPb Cent SBPos Update
	"../CumuV0/HIMinimumBias5/crab_HIMB5_V0cumu_ppRecoGMO_LmSBNeg_rapidity_Cent_v4_rsb/190723_142454/0000/",		// 231 Lm HIMB5 PbPb Cent SBNeg Update
	"../CumuV0/HIMinimumBias6/crab_HIMB6_V0cumu_ppRecoGMO_LmSBNeg_rapidity_Cent_v4_rsb/190723_142513/0000/",		// 232 Lm HIMB6 PbPb Cent SBNeg Update
	"../CumuV0/HIMinimumBias7/crab_HIMB7_V0cumu_ppRecoGMO_LmSBNeg_rapidity_Cent_v4_rsb/190723_142532/0000/",		// 233 Lm HIMB7 PbPb Cent SBNeg Update
	"NA",		// 234 Lm HIMB567 PbPb Cent SB Update
	"../cumu/PAHighMultiplicity0/crab_PAHM0_KscumuSBPos_eff_v2_rsb/190816_193537/0000/",	// 235 Ks pPb HM0 SBPos
	"../cumu/PAHighMultiplicity1/crab_PAHM1_KscumuSBPos_eff_v2/190809_145047/0000/",		// 236 Ks pPb HM1 SBPos
	"../cumu/PAHighMultiplicity2/crab_PAHM2_KscumuSBPos_eff_v2/190809_145113/0000/",		// 237 Ks pPb HM2 SBPos
	"../cumu/PAHighMultiplicity3/crab_PAHM3_KscumuSBPos_eff_v2/190809_145145/0000/",		// 238 Ks pPb HM3 SBPos
	"../cumu/PAHighMultiplicity4/crab_PAHM4_KscumuSBPos_eff_v2/190809_145221/0000/",		// 239 Ks pPb HM4 SBPos
	"../cumu/PAHighMultiplicity5/crab_PAHM5_KscumuSBPos_eff_v2/190809_145248/0000/",		// 240 Ks pPb HM5 SBPos
	"../cumu/PAHighMultiplicity6/crab_PAHM6_KscumuSBPos_eff_v2/190809_145323/0000/",		// 241 Ks pPb HM6 SBPos
	"../cumu/PAHighMultiplicity7/crab_PAHM7_KscumuSBPos_eff_v2_rsb/190816_193558/0000/",	// 242 Ks pPb HM7 SBPos
	"../cumu/PAHighMultiplicity0/crab_PAHM0_KscumuSBPos_eff_reverse_v2_rsb/190816_193618/0000/",	// 243 Ks pPb HM0 SBPos reverse
	"../cumu/PAHighMultiplicity1/crab_PAHM1_KscumuSBPos_eff_reverse_v2/190807_190405/0000/",		// 244 Ks pPb HM1 SBPos reverse
	"../cumu/PAHighMultiplicity2/crab_PAHM2_KscumuSBPos_eff_reverse_v2/190807_190427/0000/",		// 245 Ks pPb HM2 SBPos reverse
	"../cumu/PAHighMultiplicity3/crab_PAHM3_KscumuSBPos_eff_reverse_v2/190807_190447/0000/",		// 246 Ks pPb HM3 SBPos reverse
	"../cumu/PAHighMultiplicity4/crab_PAHM4_KscumuSBPos_eff_reverse_v2/190807_190506/0000/",		// 247 Ks pPb HM4 SBPos reverse
	"../cumu/PAHighMultiplicity5/crab_PAHM5_KscumuSBPos_eff_reverse_v2/190807_190527/0000/",		// 248 Ks pPb HM5 SBPos reverse
	"../cumu/PAHighMultiplicity6/crab_PAHM6_KscumuSBPos_eff_reverse_v2/190807_190545/0000/",		// 249 Ks pPb HM6 SBPos reverse
	"../cumu/PAHighMultiplicity7/crab_PAHM7_KscumuSBPos_eff_reverse_v2_rsb/190816_193639/0000/",	// 250 Ks pPb HM7 SBPos reverse
	"../cumu/PAHighMultiplicity0/crab_PAHM0_KscumuSBNeg_eff_v2_rsb/190816_193704/0000/",	// 251 Ks pPb HM0 SBNeg
	"../cumu/PAHighMultiplicity1/crab_PAHM1_KscumuSBNeg_eff_v2/190809_145407/0000/",		// 252 Ks pPb HM1 SBNeg
	"../cumu/PAHighMultiplicity2/crab_PAHM2_KscumuSBNeg_eff_v2/190809_145437/0000/",		// 253 Ks pPb HM2 SBNeg
	"../cumu/PAHighMultiplicity3/crab_PAHM3_KscumuSBNeg_eff_v2/190809_145507/0000/",		// 254 Ks pPb HM3 SBNeg
	"../cumu/PAHighMultiplicity4/crab_PAHM4_KscumuSBNeg_eff_v2/190809_145540/0000/",		// 255 Ks pPb HM4 SBNeg
	"../cumu/PAHighMultiplicity5/crab_PAHM5_KscumuSBNeg_eff_v2/190809_145628/0000/",		// 256 Ks pPb HM5 SBNeg
	"../cumu/PAHighMultiplicity6/crab_PAHM6_KscumuSBNeg_eff_v2/190809_145708/0000/",		// 257 Ks pPb HM6 SBNeg
	"../cumu/PAHighMultiplicity7/crab_PAHM7_KscumuSBNeg_eff_v2_rsb/190816_193725/0000/",	// 258 Ks pPb HM7 SBNeg
	"../cumu/PAHighMultiplicity0/crab_PAHM0_KscumuSBNeg_eff_reverse_v2_rsb/190816_193749/0000/",	// 259 Ks pPb HM0 SBNeg reverse
	"../cumu/PAHighMultiplicity1/crab_PAHM1_KscumuSBNeg_eff_reverse_v2/190807_190642/0000/",		// 260 Ks pPb HM1 SBNeg reverse
	"../cumu/PAHighMultiplicity2/crab_PAHM2_KscumuSBNeg_eff_reverse_v2/190807_190701/0000/",		// 261 Ks pPb HM2 SBNeg reverse
	"../cumu/PAHighMultiplicity3/crab_PAHM3_KscumuSBNeg_eff_reverse_v2/190807_190719/0000/",		// 262 Ks pPb HM3 SBNeg reverse
	"../cumu/PAHighMultiplicity4/crab_PAHM4_KscumuSBNeg_eff_reverse_v2/190807_190738/0000/",		// 263 Ks pPb HM4 SBNeg reverse
	"../cumu/PAHighMultiplicity5/crab_PAHM5_KscumuSBNeg_eff_reverse_v2/190807_190757/0000/",		// 264 Ks pPb HM5 SBNeg reverse
	"../cumu/PAHighMultiplicity6/crab_PAHM6_KscumuSBNeg_eff_reverse_v2/190807_190817/0000/",		// 265 Ks pPb HM6 SBNeg reverse
	"../cumu/PAHighMultiplicity7/crab_PAHM7_KscumuSBNeg_eff_reverse_v2_rsb/190816_193808/0000/",	// 266 Ks pPb HM7 SBNeg reverse
	"NA",		// 267 Ks pPb HM0 SB merge
	"NA",		// 268 Ks pPb HM123456 SB merge
	"NA",		// 269 Ks pPb HM7 SB merge
	"../cumu/PAHighMultiplicity0/crab_PAHM0_LambdaSBPos_cumu_eff_v2_rsb/190816_193902/0000/",	// 270 Lm pPb HM0 SBPos
	"../cumu/PAHighMultiplicity1/crab_PAHM1_LambdaSBPos_cumu_eff_v2/190809_144402/0000/",		// 271 Lm pPb HM1 SBPos
	"../cumu/PAHighMultiplicity2/crab_PAHM2_LambdaSBPos_cumu_eff_v2/190809_144433/0000/",		// 272 Lm pPb HM2 SBPos
	"../cumu/PAHighMultiplicity3/crab_PAHM3_LambdaSBPos_cumu_eff_v2/190809_144459/0000/",		// 273 Lm pPb HM3 SBPos
	"../cumu/PAHighMultiplicity4/crab_PAHM4_LambdaSBPos_cumu_eff_v2/190809_144531/0000/",		// 274 Lm pPb HM4 SBPos
	"../cumu/PAHighMultiplicity5/crab_PAHM5_LambdaSBPos_cumu_eff_v2/190809_144611/0000/",		// 275 Lm pPb HM5 SBPos
	"../cumu/PAHighMultiplicity6/crab_PAHM6_LambdaSBPos_cumu_eff_v2/190809_144637/0000/",		// 276 Lm pPb HM6 SBPos
	"../cumu/PAHighMultiplicity7/crab_PAHM7_LambdaSBPos_cumu_eff_v2_rsb/190816_193921/0000/",	// 277 Lm pPb HM7 SBPos
	"../cumu/PAHighMultiplicity0/crab_PAHM0_LambdaSBPos_cumu_eff_reverse_v2_rsb/190816_193940/0000/",	// 278 Lm pPb HM0 SBPos reverse
	"../cumu/PAHighMultiplicity1/crab_PAHM1_LambdaSBPos_cumu_eff_reverse_v2_rsb/190809_143838/0000/",	// 279 Lm pPb HM1 SBPos reverse
	"../cumu/PAHighMultiplicity2/crab_PAHM2_LambdaSBPos_cumu_eff_reverse_v2/190728_151156/0000/",		// 280 Lm pPb HM2 SBPos reverse
	"../cumu/PAHighMultiplicity3/crab_PAHM3_LambdaSBPos_cumu_eff_reverse_v2/190728_151215/0000/",		// 281 Lm pPb HM3 SBPos reverse
	"../cumu/PAHighMultiplicity4/crab_PAHM4_LambdaSBPos_cumu_eff_reverse_v2/190728_151232/0000/",		// 282 Lm pPb HM4 SBPos reverse
	"../cumu/PAHighMultiplicity5/crab_PAHM5_LambdaSBPos_cumu_eff_reverse_v2/190728_151250/0000/",		// 283 Lm pPb HM5 SBPos reverse
	"../cumu/PAHighMultiplicity6/crab_PAHM6_LambdaSBPos_cumu_eff_reverse_v2/190728_151310/0000/",		// 284 Lm pPb HM6 SBPos reverse
	"../cumu/PAHighMultiplicity7/crab_PAHM7_LambdaSBPos_cumu_eff_reverse_v2_rsb/190816_194000/0000/",	// 285 Lm pPb HM7 SBPos reverse
	"../cumu/PAHighMultiplicity0/crab_PAHM0_LambdaSBNeg_cumu_eff_v2_rsb/190816_194025/0000/",	// 286 Lm pPb HM0 SBNeg
	"../cumu/PAHighMultiplicity1/crab_PAHM1_LambdaSBNeg_cumu_eff_v2/190809_144008/0000/",		// 287 Lm pPb HM1 SBNeg
	"../cumu/PAHighMultiplicity2/crab_PAHM2_LambdaSBNeg_cumu_eff_v2/190809_144044/0000/",		// 288 Lm pPb HM2 SBNeg
	"../cumu/PAHighMultiplicity3/crab_PAHM3_LambdaSBNeg_cumu_eff_v2/190809_144116/0000/",		// 289 Lm pPb HM3 SBNeg
	"../cumu/PAHighMultiplicity4/crab_PAHM4_LambdaSBNeg_cumu_eff_v2/190809_144143/0000/",		// 290 Lm pPb HM4 SBNeg
	"../cumu/PAHighMultiplicity5/crab_PAHM5_LambdaSBNeg_cumu_eff_v2/190809_144222/0000/",		// 291 Lm pPb HM5 SBNeg
	"../cumu/PAHighMultiplicity6/crab_PAHM6_LambdaSBNeg_cumu_eff_v2/190809_144254/0000/",		// 292 Lm pPb HM6 SBNeg
	"../cumu/PAHighMultiplicity7/crab_PAHM7_LambdaSBNeg_cumu_eff_v2_rsb/190816_194044/0000/",	// 293 Lm pPb HM7 SBNeg
	"../cumu/PAHighMultiplicity0/crab_PAHM0_LambdaSBNeg_cumu_eff_reverse_v2_rsb/190816_194104/0000/",	// 294 Lm pPb HM0 SBNeg reverse
	"../cumu/PAHighMultiplicity1/crab_PAHM1_LambdaSBNeg_cumu_eff_reverse_v2/190728_150924/0000/",		// 295 Lm pPb HM1 SBNeg reverse
	"../cumu/PAHighMultiplicity2/crab_PAHM2_LambdaSBNeg_cumu_eff_reverse_v2/190728_150945/0000/",		// 296 Lm pPb HM2 SBNeg reverse
	"../cumu/PAHighMultiplicity3/crab_PAHM3_LambdaSBNeg_cumu_eff_reverse_v2_rsb/190809_143527/0000/",	// 297 Lm pPb HM3 SBNeg reverse
	"../cumu/PAHighMultiplicity4/crab_PAHM4_LambdaSBNeg_cumu_eff_reverse_v2/190728_151029/0000/",		// 298 Lm pPb HM4 SBNeg reverse
	"../cumu/PAHighMultiplicity5/crab_PAHM5_LambdaSBNeg_cumu_eff_reverse_v2_rsb/190809_143601/0000/",	// 299 Lm pPb HM5 SBNeg reverse
	"../cumu/PAHighMultiplicity6/crab_PAHM6_LambdaSBNeg_cumu_eff_reverse_v2/190728_151105/0000/",		// 300 Lm pPb HM6 SBNeg reverse
	"../cumu/PAHighMultiplicity7/crab_PAHM7_LambdaSBNeg_cumu_eff_reverse_v2_rsb/190816_194123/0000/",	// 301 Lm pPb HM7 SBNeg reverse
	"NA",		// 302 Lm pPb HM0 SB merge
	"NA",		// 303 Lm pPb HM123456 SB merge
	"NA",		// 304 Lm pPb HM7 SB merge
    "",     // 305 Ks pPb HM0 sysTight
    "",     // 306 Ks pPb HM1 sysTight
    "../cumu/PAHighMultiplicity2/crab_PAHM2_Kscumu_sysTight_eff_v1/190817_033023/0000/",     // 307 Ks pPb HM2 sysTight
    "",     // 308 Ks pPb HM3 sysTight
    "../cumu/PAHighMultiplicity4/crab_PAHM4_Kscumu_sysTight_eff_v1/190809_180008/0000/",     // 309 Ks pPb HM4 sysTight
    "",     // 310 Ks pPb HM5 sysTight
    "",     // 311 Ks pPb HM6 sysTight
    "",     // 312 Ks pPb HM7 sysTight
    "",     // 313 Ks pPb HM0 sysTight reverse
    "",     // 314 Ks pPb HM1 sysTight reverse
    "../cumu/PAHighMultiplicity2/crab_PAHM2_Kscumu_sysTight_eff_reverse_v1/190817_033128/0000/",     // 315 Ks pPb HM2 sysTight reverse
    "",     // 316 Ks pPb HM3 sysTight reverse
    "../cumu/PAHighMultiplicity4/crab_PAHM4_Kscumu_sysTight_eff_reverse_v1/190809_180045/0000/",     // 317 Ks pPb HM4 sysTight reverse
    "",     // 318 Ks pPb HM5 sysTight reverse
    "",     // 319 Ks pPb HM6 sysTight reverse
    "",     // 320 Ks pPb HM7 sysTight reverse
    "NA",     // 321 Ks pPb HM0 sysTight merge
    "NA",     // 322 Ks pPb HM123456 sysTight merge
    "NA",     // 323 Ks pPb HM7 sysTight merge
    "",     // 324 Ks pPb HM0 sysLoose
    "",     // 325 Ks pPb HM1 sysLoose
    "../cumu/PAHighMultiplicity2/crab_PAHM2_Kscumu_sysLoose_eff_v1/190817_033218/0000/",     // 326 Ks pPb HM2 sysLoose
    "",     // 327 Ks pPb HM3 sysLoose
    "../cumu/PAHighMultiplicity4/crab_PAHM4_Kscumu_sysLoose_eff_v1/190809_180131/0000/",     // 328 Ks pPb HM4 sysLoose
    "",     // 329 Ks pPb HM5 sysLoose
    "",     // 330 Ks pPb HM6 sysLoose
    "",     // 331 Ks pPb HM7 sysLoose
    "",     // 332 Ks pPb HM0 sysLoose reverse
    "",     // 333 Ks pPb HM1 sysLoose reverse
    "../cumu/PAHighMultiplicity2/crab_PAHM2_Kscumu_sysLoose_eff_reverse_v1/190817_033304/0000/",     // 334 Ks pPb HM2 sysLoose reverse
    "",     // 335 Ks pPb HM3 sysLoose reverse
    "../cumu/PAHighMultiplicity4/crab_PAHM4_Kscumu_sysLoose_eff_reverse_v1/190809_180209/0000/",     // 336 Ks pPb HM4 sysLoose reverse
    "",     // 337 Ks pPb HM5 sysLoose reverse
    "",     // 338 Ks pPb HM6 sysLoose reverse
    "",     // 339 Ks pPb HM7 sysLoose reverse
    "NA",     // 340 Ks pPb HM0 sysLoose merge
    "NA",     // 341 Ks pPb HM123456 sysLoose merge
    "NA",     // 342 Ks pPb HM7 sysLoose merge
    "",     // 343 Lm pPb HM0 sysTight
    "",     // 344 Lm pPb HM1 sysTight
    "../cumu/PAHighMultiplicity2/crab_PAHM2_Lmcumu_sysTight_eff_v1/190817_033430/0000/",     // 345 Lm pPb HM2 sysTight
    "",     // 346 Lm pPb HM3 sysTight
    "../cumu/PAHighMultiplicity4/crab_PAHM4_Lmcumu_sysTight_eff_v1/190809_180253/0000/",     // 347 Lm pPb HM4 sysTight
    "",     // 348 Lm pPb HM5 sysTight
    "",     // 349 Lm pPb HM6 sysTight
    "",     // 350 Lm pPb HM7 sysTight
    "",     // 351 Lm pPb HM0 sysTight reverse
    "",     // 352 Lm pPb HM1 sysTight reverse
    "../cumu/PAHighMultiplicity2/crab_PAHM2_Lmcumu_sysTight_eff_reverse_v1/190817_033524/0000/",     // 353 Lm pPb HM2 sysTight reverse
    "../cumu/PAHighMultiplicity3/crab_PAHM3_Kscumu_sysTight_eff_reverse_v1/190621_180609/0000/",     // 354 Lm pPb HM3 sysTight reverse
    "../cumu/PAHighMultiplicity4/crab_PAHM4_Lmcumu_sysTight_eff_reverse_v1/190809_180326/0000/",     // 355 Lm pPb HM4 sysTight reverse
    "",     // 356 Lm pPb HM5 sysTight reverse
    "",     // 357 Lm pPb HM6 sysTight reverse
    "",     // 358 Lm pPb HM7 sysTight reverse
    "NA",     // 359 Lm pPb HM0 sysTight merge
    "NA",     // 360 Lm pPb HM123456 sysTight merge
    "NA",     // 361 Lm pPb HM7 sysTight merge
    "",     // 362 Lm pPb HM0 sysLoose
    "",     // 363 Lm pPb HM1 sysLoose
    "../cumu/PAHighMultiplicity2/crab_PAHM2_Lmcumu_sysLoose_eff_v1/190817_033610/0000/",     // 364 Lm pPb HM2 sysLoose
    "",     // 365 Lm pPb HM3 sysLoose
    "../cumu/PAHighMultiplicity4/crab_PAHM4_Lmcumu_sysLoose_eff_v1/190809_180406/0000/",     // 366 Lm pPb HM4 sysLoose
    "",     // 367 Lm pPb HM5 sysLoose
    "",     // 368 Lm pPb HM6 sysLoose
    "",     // 369 Lm pPb HM7 sysLoose
    "",     // 370 Lm pPb HM0 sysLoose reverse
    "",     // 371 Lm pPb HM1 sysLoose reverse
    "../cumu/PAHighMultiplicity2/crab_PAHM2_Lmcumu_sysLoose_eff_reverse_v1/190817_033657/0000/",     // 372 Lm pPb HM2 sysLoose reverse
    "",     // 373 Lm pPb HM3 sysLoose reverse
    "../cumu/PAHighMultiplicity4/crab_PAHM4_Lmcumu_sysLoose_eff_reverse_v1/190809_180439/0000/",     // 374 Lm pPb HM4 sysLoose reverse
    "",     // 375 Lm pPb HM5 sysLoose reverse
    "",     // 376 Lm pPb HM6 sysLoose reverse
    "",     // 377 Lm pPb HM7 sysLoose reverse
    "NA",     // 378 Lm pPb HM0 sysLoose merge
    "NA",     // 379 Lm pPb HM123456 sysLoose merge
    "NA",     // 380 Lm pPb HM7 sysLoose merge
    "../cumu/PAHighMultiplicity0/crab_PAHM0_H_v2/200130_201229/0000/",     // 381 Charged H pPb HM0
    "../cumu/PAHighMultiplicity1/crab_PAHM1_H_v2/200130_202200/0000/",     // 382 Charged H pPb HM1
    "",     // 383 Charged H pPb HM2
    "",     // 384 Charged H pPb HM3
    "",     // 385 Charged H pPb HM4
    "",     // 386 Charged H pPb HM5
    "",     // 387 Charged H pPb HM6
    "../cumu/PAHighMultiplicity7/crab_PAHM7_H_v2/200130_202338/0000/",     // 388 Charged H pPb HM7
    "../cumu/PAHighMultiplicity0/crab_PAHM0_H_reverse_v2/200131_124333/0000/",     // 389 Charged H pPb HM0 reverse
    "../cumu/PAHighMultiplicity1/crab_PAHM1_H_reverse_v2/200131_124526/0000/",     // 390 Charged H pPb HM1 reverse
    "",     // 391 Charged H pPb HM2 reverse
    "",     // 392 Charged H pPb HM3 reverse
    "",     // 393 Charged H pPb HM4 reverse
    "",     // 394 Charged H pPb HM5 reverse
    "",     // 395 Charged H pPb HM6 reverse
    "../cumu/PAHighMultiplicity7/crab_PAHM7_H_reverse_v2/200131_124627/0000/",     // 396 Charged H pPb HM7 reverse
    "NA",     // 397 Charged H pPb HM123456
    "NA",     // 398 Charged H pPb HM123456 reverse
    "NA",     // 399 Charged H pPb HM0 merge
    "NA",     // 400 Charged H pPb HM123456 merge
    "NA",     // 401 Charged H pPb HM7 merge
    "NA",     // 402 Ks pPb HM0 SB
    "NA",     // 403 Ks pPb HM123456 SB
    "NA",     // 404 Ks pPb HM7 SB
    "NA",     // 405 Ks pPb HM0 SB reverse
    "NA",     // 406 Ks pPb HM123456 SB reverse
    "NA",     // 407 Ks pPb HM7 SB reverse
    "NA",     // 408 Lm pPb HM0 SB
    "NA",     // 409 Lm pPb HM123456 SB
    "NA",     // 410 Lm pPb HM7 SB
    "NA",     // 411 Lm pPb HM0 SB reverse
    "NA",     // 412 Lm pPb HM123456 SB reverse
    "NA",     // 413 Lm pPb HM7 SB reverse
    "NA",     // 414 H pPb HM123456
    "NA",     // 415 H pPb HM123456 reverse
    "../cumu/PAHighMultiplicity0/crab_PAHM0_H_veto10_v2/200430_001229/0000/",             // 416 H veto10 pPb HM0
    "../cumu/PAHighMultiplicity0/crab_PAHM0_H_veto10_reverse_v2/200430_142711/0000/",     // 417 H veto10 pPb HM0 reverse
    "NA",     // 418 H veto10 pPb HM0 merge
    "../cumu/PAHighMultiplicity1/crab_PAHM1_H_veto10_v2/200501_192341/0000/",             // 419 H veto10 pPb HM1
    "../cumu/PAHighMultiplicity2/crab_PAHM2_H_veto10_v2/200501_192358/0000/",             // 420 H veto10 pPb HM2
    "../cumu/PAHighMultiplicity3/crab_PAHM3_H_veto10_v2/200501_192412/0000/",             // 421 H veto10 pPb HM3
    "../cumu/PAHighMultiplicity4/crab_PAHM4_H_veto10_v2/200502_002218/0000/",             // 422 H veto10 pPb HM4
    "../cumu/PAHighMultiplicity5/crab_PAHM5_H_veto10_v2/200502_151842/0000/",             // 423 H veto10 pPb HM5
    "../cumu/PAHighMultiplicity6/crab_PAHM6_H_veto10_v2/200502_151857/0000/",             // 424 H veto10 pPb HM6
    "../cumu/PAHighMultiplicity7/crab_PAHM7_H_veto10_v2/200502_170142/0000/",             // 425 H veto10 pPb HM7
    "../cumu/PAHighMultiplicity1/crab_PAHM1_H_veto10_reverse_v2/200501_234034/0000/",             // 426 H veto10 pPb HM1 reverse
    "../cumu/PAHighMultiplicity2/crab_PAHM2_H_veto10_reverse_v2/200501_234049/0000/",             // 427 H veto10 pPb HM2 reverse
    "../cumu/PAHighMultiplicity3/crab_PAHM3_H_veto10_reverse_v2/200501_234103/0000/",             // 428 H veto10 pPb HM3 reverse
    "../cumu/PAHighMultiplicity4/crab_PAHM4_H_veto10_reverse_v2/200501_235030/0000/",             // 429 H veto10 pPb HM4 reverse
    "../cumu/PAHighMultiplicity5/crab_PAHM5_H_veto10_reverse_v2/200502_170932/0000/",             // 430 H veto10 pPb HM5 reverse
    "../cumu/PAHighMultiplicity6/crab_PAHM6_H_veto10_reverse_v2/200502_170947/0000/",             // 431 H veto10 pPb HM6 reverse
    "../cumu/PAHighMultiplicity7/crab_PAHM7_H_veto10_reverse_v2/200502_171057/0000/",             // 432 H veto10 pPb HM7 reverse
    "NA",             // 433 H veto10 pPb HM123456
    "NA",             // 434 H veto10 pPb HM123456 reverse
};

char const * ftxt[] = {
	"txt/test/",				// 0
	"txt/PAHM0_Ks/",			// 1
	"txt/PAHM1_Ks/",			// 2
	"txt/PAHM7_Ks/",			// 3
	"txt/PAHM0_Ks_reverse/",		// 4
	"txt/PAHM1_Ks_reverse/",		// 5
	"txt/PAHM7_Ks_reverse/",		// 6
	"txt/PAHM0_Ks_merge/",			// 7
	"txt/PAHM1_Ks_merge/",			// 8
	"txt/PAHM7_Ks_merge/",			// 9
	"txt/PAHM0_Lambda/",			// 10
	"txt/PAHM1_Lambda/",			// 11
	"txt/PAHM7_Lambda/",			// 12
	"txt/PAHM0_Lambda_reverse/",		// 13
	"txt/PAHM1_Lambda_reverse/",		// 14
	"txt/PAHM7_Lambda_reverse/",		// 15
	"txt/PAHM0_Lambda_merge/",		// 16
	"txt/PAHM1_Lambda_merge/",		// 17
	"txt/PAHM7_Lambda_merge/",		// 18
	"txt/PAHM0_Omega/",			// 19
	"txt/PAHM1_Omega/",			// 20
	"txt/PAHM7_Omega/",			// 21
	"txt/PAHM0_Omega_reverse/",		// 22
	"txt/PAHM1_Omega_reverse/",		// 23
	"txt/PAHM7_Omega_reverse/",		// 24
	"txt/PAHM0_Omega_merge/",		// 25
	"txt/PAHM1_Omega_merge/",		// 26
	"txt/PAHM7_Omega_merge/",		// 27
	"txt/PAHM2_Ks/",			// 28
	"txt/PAHM3_Ks/",			// 29
	"txt/PAHM4_Ks/",			// 30
	"txt/PAHM5_Ks/",			// 31
	"txt/PAHM6_Ks/",			// 32
	"txt/PAHM2_Ks_reverse/",		// 33
	"txt/PAHM3_Ks_reverse/",		// 34
	"txt/PAHM4_Ks_reverse/",		// 35
	"txt/PAHM5_Ks_reverse/",		// 36
	"txt/PAHM6_Ks_reverse/",		// 37
	"txt/PAHM2_Lambda/",			// 38
	"txt/PAHM3_Lambda/",			// 39
	"txt/PAHM4_Lambda/",			// 40
	"txt/PAHM5_Lambda/",			// 41
	"txt/PAHM6_Lambda/",			// 42
	"txt/PAHM2_Lambda_reverse/",		// 43
	"txt/PAHM3_Lambda_reverse/",		// 44
	"txt/PAHM4_Lambda_reverse/",		// 45
	"txt/PAHM5_Lambda_reverse/",		// 46
	"txt/PAHM6_Lambda_reverse/",		// 47
	"txt/PbPb5_Ks/",			// 48
	"txt/PbPb6_Ks/",			// 49
	"txt/PbPb7_Ks/",			// 50
	"txt/PbPb5_Lambda/",			// 51
	"txt/PbPb6_Lambda/",			// 52
	"txt/PbPb7_Lambda/",			// 53
	"txt/PbPb_Ks_merge/",			// 54
	"txt/PbPb_Lambda_merge/",		// 55
	"txt/PAHM123456_Ks_pPb/",		// 56
	"txt/PAHM123456_Ks_pPb_reverse/",	// 57
	"txt/PAHM123456_Lm_pPb/",		// 58
	"txt/PAHM123456_Lm_pPb_reverse/",	// 59
	"txt/PAHM0_KsSBPos_pPb/",		// 60
	"txt/PAHM1_KsSBPos_pPb/",		// 61
	"txt/PAHM2_KsSBPos_pPb/",		// 62
	"txt/PAHM3_KsSBPos_pPb/",		// 63
	"txt/PAHM4_KsSBPos_pPb/",		// 64
	"txt/PAHM5_KsSBPos_pPb/",		// 65
	"txt/PAHM6_KsSBPos_pPb/",		// 66
	"txt/PAHM7_KsSBPos_pPb/",		// 67
	"txt/PAHM0_KsSBPos_pPb_reverse/",	// 68
	"txt/PAHM1_KsSBPos_pPb_reverse/",	// 69
	"txt/PAHM2_KsSBPos_pPb_reverse/",	// 70
	"txt/PAHM3_KsSBPos_pPb_reverse/",	// 71
	"txt/PAHM4_KsSBPos_pPb_reverse/",	// 72
	"txt/PAHM5_KsSBPos_pPb_reverse/",	// 73
	"txt/PAHM6_KsSBPos_pPb_reverse/",	// 74
	"txt/PAHM7_KsSBPos_pPb_reverse/",	// 75
	"txt/PAHM0_KsSBPos_pPb_merge/",		// 76
	"txt/PAHM123456_KsSBPos_pPb_merge/",	// 77
	"txt/PAHM7_KsSBPos_pPb_merge/",		// 78
	"txt/PAHM0_LmSBPos_pPb/",		// 79
	"txt/PAHM1_LmSBPos_pPb/",		// 80
	"txt/PAHM2_LmSBPos_pPb/",		// 81
	"txt/PAHM3_LmSBPos_pPb/",		// 82
	"txt/PAHM4_LmSBPos_pPb/",		// 83
	"txt/PAHM5_LmSBPos_pPb/",		// 84
	"txt/PAHM6_LmSBPos_pPb/",		// 85
	"txt/PAHM7_LmSBPos_pPb/",		// 86
	"txt/PAHM0_LmSBPos_pPb_reverse/",	// 87
	"txt/PAHM1_LmSBPos_pPb_reverse/",	// 88
	"txt/PAHM2_LmSBPos_pPb_reverse/",	// 89
	"txt/PAHM3_LmSBPos_pPb_reverse/",	// 90
	"txt/PAHM4_LmSBPos_pPb_reverse/",	// 91
	"txt/PAHM5_LmSBPos_pPb_reverse/",	// 92
	"txt/PAHM6_LmSBPos_pPb_reverse/",	// 93
	"txt/PAHM7_LmSBPos_pPb_reverse/",	// 94
	"txt/PAHM0_LmSBPos_pPb_merge/",		// 95
	"txt/PAHM123456_LmSBPos_pPb_merge/",	// 96
	"txt/PAHM7_LmSBPos_pPb_merge/",		// 97
	"txt/PAHM0_KsSBNeg_pPb/",		// 98
	"txt/PAHM1_KsSBNeg_pPb/",		// 99
	"txt/PAHM2_KsSBNeg_pPb/",		// 100
	"txt/PAHM3_KsSBNeg_pPb/",		// 101
	"txt/PAHM4_KsSBNeg_pPb/",		// 102
	"txt/PAHM5_KsSBNeg_pPb/",		// 103
	"txt/PAHM6_KsSBNeg_pPb/",		// 104
	"txt/PAHM7_KsSBNeg_pPb/",		// 105
	"txt/PAHM0_KsSBNeg_pPb_reverse/",	// 106
	"txt/PAHM1_KsSBNeg_pPb_reverse/",	// 107
	"txt/PAHM2_KsSBNeg_pPb_reverse/",	// 108
	"txt/PAHM3_KsSBNeg_pPb_reverse/",	// 109
	"txt/PAHM4_KsSBNeg_pPb_reverse/",	// 110
	"txt/PAHM5_KsSBNeg_pPb_reverse/",	// 111
	"txt/PAHM6_KsSBNeg_pPb_reverse/",	// 112
	"txt/PAHM7_KsSBNeg_pPb_reverse/",	// 113
	"txt/PAHM0_KsSBNeg_pPb_merge/",		// 114
	"txt/PAHM123456_KsSBNeg_pPb_merge/",	// 115
	"txt/PAHM7_KsSBNeg_pPb_merge/",		// 116
	"txt/PAHM0_LmSBNeg_pPb/",		// 117
	"txt/PAHM1_LmSBNeg_pPb/",		// 118
	"txt/PAHM2_LmSBNeg_pPb/",		// 119
	"txt/PAHM3_LmSBNeg_pPb/",		// 120
	"txt/PAHM4_LmSBNeg_pPb/",		// 121
	"txt/PAHM5_LmSBNeg_pPb/",		// 122
	"txt/PAHM6_LmSBNeg_pPb/",		// 123
	"txt/PAHM7_LmSBNeg_pPb/",		// 124
	"txt/PAHM0_LmSBNeg_pPb_reverse/",	// 125
	"txt/PAHM1_LmSBNeg_pPb_reverse/",	// 126
	"txt/PAHM2_LmSBNeg_pPb_reverse/",	// 127
	"txt/PAHM3_LmSBNeg_pPb_reverse/",	// 128
	"txt/PAHM4_LmSBNeg_pPb_reverse/",	// 129
	"txt/PAHM5_LmSBNeg_pPb_reverse/",	// 130
	"txt/PAHM6_LmSBNeg_pPb_reverse/",	// 131
	"txt/PAHM7_LmSBNeg_pPb_reverse/",	// 132
	"txt/PAHM0_LmSBNeg_pPb_merge/",		// 133
	"txt/PAHM123456_LmSBNeg_pPb_merge/",	// 134
	"txt/PAHM7_LmSBNeg_pPb_merge/",		// 135
	"txt/PAHM0_KsSB/",			// 136
	"txt/PAHM123456_KsSB/",			// 137
	"txt/PAHM7_KsSB/",			// 138
	"txt/PAHM0_LmSB/",			// 139
	"txt/PAHM123456_LmSB/",			// 140
	"txt/PAHM7_LmSB/",			// 141
	"txt/PbPb5_Ks_SBPos/",			// 142
	"txt/PbPb6_Ks_SBPos/",			// 143
	"txt/PbPb7_Ks_SBPos/",			// 144
	"txt/PbPb5_Ks_SBNeg/",			// 145
	"txt/PbPb6_Ks_SBNeg/",			// 146
	"txt/PbPb7_Ks_SBNeg/",			// 147
	"txt/PbPb5_Lm_SBPos/",			// 148
	"txt/PbPb6_Lm_SBPos/",			// 149
	"txt/PbPb7_Lm_SBPos/",			// 150
	"txt/PbPb5_Lm_SBNeg/",			// 151
	"txt/PbPb6_Lm_SBNeg/",			// 152
	"txt/PbPb7_Lm_SBNeg/",			// 153
	"txt/PbPb567_Ks_SBPos/",		// 154
	"txt/PbPb567_Ks_SBNeg/",		// 155
	"txt/PbPb567_Ks_SB/",			// 156
	"txt/PbPb567_Lm_SBPos/",		// 157
	"txt/PbPb567_Lm_SBNeg/",		// 158
	"txt/PbPb567_Lm_SB/",			// 159
	"txt/PbPb5_Ks_Cent/",			// 160
	"txt/PbPb6_Ks_Cent/",			// 161
	"txt/PbPb7_Ks_Cent/",			// 162
	"txt/PbPb5_Lm_Cent/",			// 163
	"txt/PbPb6_Lm_Cent/",			// 164
	"txt/PbPb7_Lm_Cent/",			// 165
	"txt/PbPb567_Ks_Cent/",			// 166
	"txt/PbPb567_Lm_Cent/",			// 167
	"txt/PbPb5_Ks_SBPos_Cent/",		// 168
	"txt/PbPb6_Ks_SBPos_Cent/",		// 169
	"txt/PbPb7_Ks_SBPos_Cent/",		// 170
	"txt/PbPb5_Ks_SBNeg_Cent/",		// 171
	"txt/PbPb6_Ks_SBNeg_Cent/",		// 172
	"txt/PbPb7_Ks_SBNeg_Cent/",		// 173
	"txt/PbPb5_Lm_SBPos_Cent/",		// 174
	"txt/PbPb6_Lm_SBPos_Cent/",		// 175
	"txt/PbPb7_Lm_SBPos_Cent/",		// 176
	"txt/PbPb5_Lm_SBNeg_Cent/",		// 177
	"txt/PbPb6_Lm_SBNeg_Cent/",		// 178
	"txt/PbPb7_Lm_SBNeg_Cent/",		// 179
	"txt/PbPb567_Ks_SB_Cent/",		// 180
	"txt/PbPb567_Lm_SB_Cent/",		// 181
	"txt/PAHM0_Ks2/",		        // 182
	"txt/PAHM1_Ks2/",		        // 183
	"txt/PAHM2_Ks2/",		        // 184
	"txt/PAHM3_Ks2/",		        // 185
	"txt/PAHM4_Ks2/",		        // 186
	"txt/PAHM5_Ks2/",		        // 187
	"txt/PAHM6_Ks2/",		        // 188
	"txt/PAHM7_Ks2/",		        // 189
	"txt/PAHM0_Ks2_reverse/",       // 190
	"txt/PAHM1_Ks2_reverse/",       // 191
	"txt/PAHM2_Ks2_reverse/",       // 192
	"txt/PAHM3_Ks2_reverse/",       // 193
	"txt/PAHM4_Ks2_reverse/",       // 194
	"txt/PAHM5_Ks2_reverse/",       // 195
	"txt/PAHM6_Ks2_reverse/",       // 196
	"txt/PAHM7_Ks2_reverse/",       // 197
	"txt/PAHM0_Lm2/",		        // 198
	"txt/PAHM1_Lm2/",		        // 199
	"txt/PAHM2_Lm2/",		        // 200
	"txt/PAHM3_Lm2/",		        // 201
	"txt/PAHM4_Lm2/",		        // 202
	"txt/PAHM5_Lm2/",		        // 203
	"txt/PAHM6_Lm2/",		        // 204
	"txt/PAHM7_Lm2/",		        // 205
	"txt/PAHM0_Lm2_reverse/",       // 206
	"txt/PAHM1_Lm2_reverse/",       // 207
	"txt/PAHM2_Lm2_reverse/",       // 208
	"txt/PAHM3_Lm2_reverse/",       // 209
	"txt/PAHM4_Lm2_reverse/",       // 210
	"txt/PAHM5_Lm2_reverse/",       // 211
	"txt/PAHM6_Lm2_reverse/",       // 212
	"txt/PAHM7_Lm2_reverse/",       // 213
	"txt/PAHM123456_Ks2/",	        // 214
	"txt/PAHM123456_Ks2_reverse/",  // 215
	"txt/PAHM0_Ks2_merge/",         // 216
	"txt/PAHM123456_Ks2_merge/",    // 217
	"txt/PAHM7_Ks2_merge/",         // 218
	"txt/PAHM123456_Lm2/",	        // 219
	"txt/PAHM123456_Lm2_reverse/",  // 220
	"txt/PAHM0_Lm2_merge/",         // 221
	"txt/PAHM123456_Lm2_merge/",    // 222
	"txt/PAHM7_Lm2_merge/",         // 223
	"txt/PbPb5_Lm_Cent2/",          // 224
	"txt/PbPb6_Lm_Cent2/",          // 225
	"txt/PbPb7_Lm_Cent2/",          // 226
	"txt/PbPb567_Lm_Cent2/",        // 227
	"txt/PbPb5_Lm_SBPos_Cent2/",     // 228
	"txt/PbPb6_Lm_SBPos_Cent2/",     // 229
	"txt/PbPb7_Lm_SBPos_Cent2/",     // 230
	"txt/PbPb5_Lm_SBNeg_Cent2/",     // 231
	"txt/PbPb6_Lm_SBNeg_Cent2/",     // 232
	"txt/PbPb7_Lm_SBNeg_Cent2/",     // 233
	"txt/PbPb567_Lm_SB_Cent2/",      // 234
	"txt/PAHM0_Ks2_SBPos/",                 // 235
	"txt/PAHM1_Ks2_SBPos/",                 // 236
	"txt/PAHM2_Ks2_SBPos/",                 // 237
	"txt/PAHM3_Ks2_SBPos/",                 // 238
	"txt/PAHM4_Ks2_SBPos/",                 // 239
	"txt/PAHM5_Ks2_SBPos/",                 // 240
	"txt/PAHM6_Ks2_SBPos/",                 // 241
	"txt/PAHM7_Ks2_SBPos/",                 // 242
	"txt/PAHM0_Ks2_SBPos_reverse/",         // 243
	"txt/PAHM1_Ks2_SBPos_reverse/",         // 244
	"txt/PAHM2_Ks2_SBPos_reverse/",         // 245
	"txt/PAHM3_Ks2_SBPos_reverse/",         // 246
	"txt/PAHM4_Ks2_SBPos_reverse/",         // 247
	"txt/PAHM5_Ks2_SBPos_reverse/",         // 248
	"txt/PAHM6_Ks2_SBPos_reverse/",         // 249
	"txt/PAHM7_Ks2_SBPos_reverse/",         // 250
	"txt/PAHM0_Ks2_SBNeg/",                 // 251
	"txt/PAHM1_Ks2_SBNeg/",                 // 252
	"txt/PAHM2_Ks2_SBNeg/",                 // 253
	"txt/PAHM3_Ks2_SBNeg/",                 // 254
	"txt/PAHM4_Ks2_SBNeg/",                 // 255
	"txt/PAHM5_Ks2_SBNeg/",                 // 256
	"txt/PAHM6_Ks2_SBNeg/",                 // 257
	"txt/PAHM7_Ks2_SBNeg/",                 // 258
	"txt/PAHM0_Ks2_SBNeg_reverse/",         // 259
	"txt/PAHM1_Ks2_SBNeg_reverse/",         // 260
	"txt/PAHM2_Ks2_SBNeg_reverse/",         // 261
	"txt/PAHM3_Ks2_SBNeg_reverse/",         // 262
	"txt/PAHM4_Ks2_SBNeg_reverse/",         // 263
	"txt/PAHM5_Ks2_SBNeg_reverse/",         // 264
	"txt/PAHM6_Ks2_SBNeg_reverse/",         // 265
	"txt/PAHM7_Ks2_SBNeg_reverse/",         // 266
	"txt/PAHM0_Ks2_SB_merge/",              // 267
	"txt/PAHM123456_Ks2_SB_merge/",         // 268
	"txt/PAHM7_Ks2_SB_merge/",              // 269
	"txt/PAHM0_Lm2_SBPos/",                 // 270
	"txt/PAHM1_Lm2_SBPos/",                 // 271
	"txt/PAHM2_Lm2_SBPos/",                 // 272
	"txt/PAHM3_Lm2_SBPos/",                 // 273
	"txt/PAHM4_Lm2_SBPos/",                 // 274
	"txt/PAHM5_Lm2_SBPos/",                 // 275
	"txt/PAHM6_Lm2_SBPos/",                 // 276
	"txt/PAHM7_Lm2_SBPos/",                 // 277
	"txt/PAHM0_Lm2_SBPos_reverse/",         // 278
	"txt/PAHM1_Lm2_SBPos_reverse/",         // 279
	"txt/PAHM2_Lm2_SBPos_reverse/",         // 280
	"txt/PAHM3_Lm2_SBPos_reverse/",         // 281
	"txt/PAHM4_Lm2_SBPos_reverse/",         // 282
	"txt/PAHM5_Lm2_SBPos_reverse/",         // 283
	"txt/PAHM6_Lm2_SBPos_reverse/",         // 284
	"txt/PAHM7_Lm2_SBPos_reverse/",         // 285
	"txt/PAHM0_Lm2_SBNeg/",                 // 286
	"txt/PAHM1_Lm2_SBNeg/",                 // 287
	"txt/PAHM2_Lm2_SBNeg/",                 // 288
	"txt/PAHM3_Lm2_SBNeg/",                 // 289
	"txt/PAHM4_Lm2_SBNeg/",                 // 290
	"txt/PAHM5_Lm2_SBNeg/",                 // 291
	"txt/PAHM6_Lm2_SBNeg/",                 // 292
	"txt/PAHM7_Lm2_SBNeg/",                 // 293
	"txt/PAHM0_Lm2_SBNeg_reverse/",         // 294
	"txt/PAHM1_Lm2_SBNeg_reverse/",         // 295
	"txt/PAHM2_Lm2_SBNeg_reverse/",         // 296
	"txt/PAHM3_Lm2_SBNeg_reverse/",         // 297
	"txt/PAHM4_Lm2_SBNeg_reverse/",         // 298
	"txt/PAHM5_Lm2_SBNeg_reverse/",         // 299
	"txt/PAHM6_Lm2_SBNeg_reverse/",         // 300
	"txt/PAHM7_Lm2_SBNeg_reverse/",         // 301
	"txt/PAHM0_Lm2_SB_merge/",              // 302
	"txt/PAHM123456_Lm2_SB_merge/",         // 303
	"txt/PAHM7_Lm2_SB_merge/",              // 304
	"txt/PAHM0_Ks_sysTight/",               // 305
	"txt/PAHM1_Ks_sysTight/",               // 306
	"txt/PAHM2_Ks_sysTight/",               // 307
	"txt/PAHM3_Ks_sysTight/",               // 308
	"txt/PAHM4_Ks_sysTight/",               // 309
	"txt/PAHM5_Ks_sysTight/",               // 310
	"txt/PAHM6_Ks_sysTight/",               // 311
	"txt/PAHM7_Ks_sysTight/",               // 312
	"txt/PAHM0_Ks_sysTight_reverse/",       // 313
	"txt/PAHM1_Ks_sysTight_reverse/",       // 314
	"txt/PAHM2_Ks_sysTight_reverse/",       // 315
	"txt/PAHM3_Ks_sysTight_reverse/",       // 316
	"txt/PAHM4_Ks_sysTight_reverse/",       // 317
	"txt/PAHM5_Ks_sysTight_reverse/",       // 318
	"txt/PAHM6_Ks_sysTight_reverse/",       // 319
	"txt/PAHM7_Ks_sysTight_reverse/",       // 320
	"txt/PAHM0_Ks_sysTight_merge/",         // 321
	"txt/PAHM123456_Ks_sysTight_merge/",    // 322
	"txt/PAHM7_Ks_sysTight_merge/",         // 323
	"txt/PAHM0_Ks_sysLoose/",               // 324
	"txt/PAHM1_Ks_sysLoose/",               // 325
	"txt/PAHM2_Ks_sysLoose/",               // 326
	"txt/PAHM3_Ks_sysLoose/",               // 327
	"txt/PAHM4_Ks_sysLoose/",               // 328
	"txt/PAHM5_Ks_sysLoose/",               // 329
	"txt/PAHM6_Ks_sysLoose/",               // 330
	"txt/PAHM7_Ks_sysLoose/",               // 331
	"txt/PAHM0_Ks_sysLoose_reverse/",       // 332
	"txt/PAHM1_Ks_sysLoose_reverse/",       // 333
	"txt/PAHM2_Ks_sysLoose_reverse/",       // 334
	"txt/PAHM3_Ks_sysLoose_reverse/",       // 335
	"txt/PAHM4_Ks_sysLoose_reverse/",       // 336
	"txt/PAHM5_Ks_sysLoose_reverse/",       // 337
	"txt/PAHM6_Ks_sysLoose_reverse/",       // 338
	"txt/PAHM7_Ks_sysLoose_reverse/",       // 339
	"txt/PAHM0_Ks_sysLoose_merge/",         // 340
	"txt/PAHM123456_Ks_sysLoose_merge/",    // 341
	"txt/PAHM7_Ks_sysLoose_merge/",         // 342
	"txt/PAHM0_Lm_sysTight/",               // 343
	"txt/PAHM1_Lm_sysTight/",               // 344
	"txt/PAHM2_Lm_sysTight/",               // 345
	"txt/PAHM3_Lm_sysTight/",               // 346
	"txt/PAHM4_Lm_sysTight/",               // 347
	"txt/PAHM5_Lm_sysTight/",               // 348
	"txt/PAHM6_Lm_sysTight/",               // 349
	"txt/PAHM7_Lm_sysTight/",               // 350
	"txt/PAHM0_Lm_sysTight_reverse/",       // 351
	"txt/PAHM1_Lm_sysTight_reverse/",       // 352
	"txt/PAHM2_Lm_sysTight_reverse/",       // 353
	"txt/PAHM3_Lm_sysTight_reverse/",       // 354
	"txt/PAHM4_Lm_sysTight_reverse/",       // 355
	"txt/PAHM5_Lm_sysTight_reverse/",       // 356
	"txt/PAHM6_Lm_sysTight_reverse/",       // 357
	"txt/PAHM7_Lm_sysTight_reverse/",       // 358
	"txt/PAHM0_Lm_sysTight_merge/",         // 359
	"txt/PAHM123456_Lm_sysTight_merge/",    // 360
	"txt/PAHM7_Lm_sysTight_merge/",         // 361
	"txt/PAHM0_Lm_sysLoose/",               // 362
	"txt/PAHM1_Lm_sysLoose/",               // 363
	"txt/PAHM2_Lm_sysLoose/",               // 364
	"txt/PAHM3_Lm_sysLoose/",               // 365
	"txt/PAHM4_Lm_sysLoose/",               // 366
	"txt/PAHM5_Lm_sysLoose/",               // 367
	"txt/PAHM6_Lm_sysLoose/",               // 368
	"txt/PAHM7_Lm_sysLoose/",               // 369
	"txt/PAHM0_Lm_sysLoose_reverse/",       // 370
	"txt/PAHM1_Lm_sysLoose_reverse/",       // 371
	"txt/PAHM2_Lm_sysLoose_reverse/",       // 372
	"txt/PAHM3_Lm_sysLoose_reverse/",       // 373
	"txt/PAHM4_Lm_sysLoose_reverse/",       // 374
	"txt/PAHM5_Lm_sysLoose_reverse/",       // 375
	"txt/PAHM6_Lm_sysLoose_reverse/",       // 376
	"txt/PAHM7_Lm_sysLoose_reverse/",       // 377
	"txt/PAHM0_Lm_sysLoose_merge/",         // 378
	"txt/PAHM123456_Lm_sysLoose_merge/",    // 379
	"txt/PAHM7_Lm_sysLoose_merge/",         // 380
	"txt/PAHM0_H/",                         // 381
	"txt/PAHM1_H/",                         // 382
	"txt/PAHM2_H/",                         // 383
	"txt/PAHM3_H/",                         // 384
	"txt/PAHM4_H/",                         // 385
	"txt/PAHM5_H/",                         // 386
	"txt/PAHM6_H/",                         // 387
	"txt/PAHM7_H/",                         // 388
	"txt/PAHM0_H_reverse/",                 // 389
	"txt/PAHM1_H_reverse/",                 // 390
	"txt/PAHM2_H_reverse/",                 // 391
	"txt/PAHM3_H_reverse/",                 // 392
	"txt/PAHM4_H_reverse/",                 // 393
	"txt/PAHM5_H_reverse/",                 // 394
	"txt/PAHM6_H_reverse/",                 // 395
	"txt/PAHM7_H_reverse/",                 // 396
	"txt/PAHM123456_H/",                    // 397
	"txt/PAHM123456_H_reverse/",            // 398
	"txt/PAHM0_H_merge/",                   // 399
	"txt/PAHM123456_H_merge/",              // 400
	"txt/PAHM7_H_merge/",                   // 401
	"txt/PAHM0_Ks2_SB/",                    // 402
	"txt/PAHM123456_Ks2_SB/",               // 403
	"txt/PAHM7_Ks2_SB/",                    // 404
	"txt/PAHM0_Ks2_SB_reverse/",            // 405
	"txt/PAHM123456_Ks2_SB_reverse/",       // 406
	"txt/PAHM7_Ks2_SB_reverse/",            // 407
	"txt/PAHM0_Lm2_SB/",                    // 408
	"txt/PAHM123456_Lm2_SB/",               // 409
	"txt/PAHM7_Lm2_SB/",                    // 410
	"txt/PAHM0_Lm2_SB_reverse/",            // 411
	"txt/PAHM123456_Lm2_SB_reverse/",       // 412
	"txt/PAHM7_Lm2_SB_reverse/",            // 413
	"txt/PAHM123456_H/",                    // 414
	"txt/PAHM123456_H_reverse/",            // 415
	"txt/PAHM0_H_veto10/",                  // 416
	"txt/PAHM0_H_veto10_reverse/",          // 417
	"txt/PAHM0_H_veto10_merge/",            // 418
	"txt/PAHM1_H_veto10/",                  // 419
	"txt/PAHM2_H_veto10/",                  // 420
	"txt/PAHM3_H_veto10/",                  // 421
	"txt/PAHM4_H_veto10/",                  // 422
	"txt/PAHM5_H_veto10/",                  // 423
	"txt/PAHM6_H_veto10/",                  // 424
	"txt/PAHM7_H_veto10/",                  // 425
	"txt/PAHM1_H_veto10_reverse/",          // 426
	"txt/PAHM2_H_veto10_reverse/",          // 427
	"txt/PAHM3_H_veto10_reverse/",          // 428
	"txt/PAHM4_H_veto10_reverse/",          // 429
	"txt/PAHM5_H_veto10_reverse/",          // 430
	"txt/PAHM6_H_veto10_reverse/",          // 431
	"txt/PAHM7_H_veto10_reverse/",          // 432
	"txt/PAHM123456_H_veto10/",             // 433
	"txt/PAHM123456_H_veto10_reverse/",     // 434
};

const int Pid_Non	= 0;
const int Pid_PA_Ks	= 1;
const int Pid_PA_Lambda	= 2;
const int Pid_PA_Omega	= 3;
const int Pid_PA_Hadron	= 4;
const int Pid_AA_Ks	= 11;
const int Pid_AA_Lambda	= 12;
const int Pid_AA_Omega	= 13;
const int Pid_AA_Hadron	= 14;

bool isPA(int c) { return c < 10; }
bool isKs(int c)     { return (c%10)==1; }
bool isLambda(int c) { return (c%10)==2; }
bool isOmega(int c)  { return (c%10)==3; }

auto PID = std::vector<int>{
	Pid_Non,	// 0
	Pid_PA_Ks,		// 1
	Pid_PA_Ks,		// 2
	Pid_PA_Ks,		// 3
	Pid_PA_Ks,		// 4
	Pid_PA_Ks,		// 5
	Pid_PA_Ks,		// 6
	Pid_PA_Ks,		// 7
	Pid_PA_Ks,		// 8
	Pid_PA_Ks,		// 9
	Pid_PA_Lambda,	// 10
	Pid_PA_Lambda,	// 11
	Pid_PA_Lambda,	// 12
	Pid_PA_Lambda,	// 13
	Pid_PA_Lambda,	// 14
	Pid_PA_Lambda,	// 15
	Pid_PA_Lambda,	// 16
	Pid_PA_Lambda,	// 17
	Pid_PA_Lambda,	// 18
	Pid_PA_Omega,	// 19
	Pid_PA_Omega,	// 20
	Pid_PA_Omega,	// 21
	Pid_PA_Omega,	// 22
	Pid_PA_Omega,	// 23
	Pid_PA_Omega,	// 24
	Pid_PA_Omega,	// 25
	Pid_PA_Omega,	// 26
	Pid_PA_Omega,	// 27
	Pid_PA_Ks,		// 28
	Pid_PA_Ks,		// 29
	Pid_PA_Ks,		// 30
	Pid_PA_Ks,		// 31
	Pid_PA_Ks,		// 32
	Pid_PA_Ks,		// 33
	Pid_PA_Ks,		// 34
	Pid_PA_Ks,		// 35
	Pid_PA_Ks,		// 36
	Pid_PA_Ks,		// 37
	Pid_PA_Lambda,	// 38
	Pid_PA_Lambda,	// 39
	Pid_PA_Lambda,	// 40
	Pid_PA_Lambda,	// 41
	Pid_PA_Lambda,	// 42
	Pid_PA_Lambda,	// 43
	Pid_PA_Lambda,	// 44
	Pid_PA_Lambda,	// 45
	Pid_PA_Lambda,	// 46
	Pid_PA_Lambda,	// 47
	Pid_AA_Ks,		// 48
	Pid_AA_Ks,		// 49
	Pid_AA_Ks,		// 50
	Pid_AA_Lambda,	// 51
	Pid_AA_Lambda,	// 52
	Pid_AA_Lambda,	// 53
	Pid_AA_Ks,		// 54
	Pid_AA_Lambda,	// 55
	Pid_PA_Ks,	// 56
	Pid_PA_Ks,	// 57
	Pid_PA_Lambda,	// 58
	Pid_PA_Lambda,	// 59
	Pid_PA_Ks,		// 60
	Pid_PA_Ks,		// 61
	Pid_PA_Ks,		// 62
	Pid_PA_Ks,		// 63
	Pid_PA_Ks,		// 64
	Pid_PA_Ks,		// 65
	Pid_PA_Ks,		// 66
	Pid_PA_Ks,		// 67
	Pid_PA_Ks,		// 68
	Pid_PA_Ks,		// 69
	Pid_PA_Ks,		// 70
	Pid_PA_Ks,		// 71
	Pid_PA_Ks,		// 72
	Pid_PA_Ks,		// 73
	Pid_PA_Ks,		// 74
	Pid_PA_Ks,		// 75
	Pid_PA_Ks,		// 76
	Pid_PA_Ks,		// 77
	Pid_PA_Ks,		// 78
	Pid_PA_Lambda,		// 79
	Pid_PA_Lambda,		// 80
	Pid_PA_Lambda,		// 81
	Pid_PA_Lambda,		// 82
	Pid_PA_Lambda,		// 83
	Pid_PA_Lambda,		// 84
	Pid_PA_Lambda,		// 85
	Pid_PA_Lambda,		// 86
	Pid_PA_Lambda,		// 87
	Pid_PA_Lambda,		// 88
	Pid_PA_Lambda,		// 89
	Pid_PA_Lambda,		// 90
	Pid_PA_Lambda,		// 91
	Pid_PA_Lambda,		// 92
	Pid_PA_Lambda,		// 93
	Pid_PA_Lambda,		// 94
	Pid_PA_Lambda,		// 95
	Pid_PA_Lambda,		// 96
	Pid_PA_Lambda,		// 97
	Pid_PA_Ks,		// 98
	Pid_PA_Ks,		// 99
	Pid_PA_Ks,		// 100
	Pid_PA_Ks,		// 101
	Pid_PA_Ks,		// 102
	Pid_PA_Ks,		// 103
	Pid_PA_Ks,		// 104
	Pid_PA_Ks,		// 105
	Pid_PA_Ks,		// 106
	Pid_PA_Ks,		// 107
	Pid_PA_Ks,		// 108
	Pid_PA_Ks,		// 109
	Pid_PA_Ks,		// 110
	Pid_PA_Ks,		// 111
	Pid_PA_Ks,		// 112
	Pid_PA_Ks,		// 113
	Pid_PA_Ks,		// 114
	Pid_PA_Ks,		// 115
	Pid_PA_Ks,		// 116
	Pid_PA_Lambda,		// 117
	Pid_PA_Lambda,		// 118
	Pid_PA_Lambda,		// 119
	Pid_PA_Lambda,		// 120
	Pid_PA_Lambda,		// 121
	Pid_PA_Lambda,		// 122
	Pid_PA_Lambda,		// 123
	Pid_PA_Lambda,		// 124
	Pid_PA_Lambda,		// 125
	Pid_PA_Lambda,		// 126
	Pid_PA_Lambda,		// 127
	Pid_PA_Lambda,		// 128
	Pid_PA_Lambda,		// 129
	Pid_PA_Lambda,		// 130
	Pid_PA_Lambda,		// 131
	Pid_PA_Lambda,		// 132
	Pid_PA_Lambda,		// 133
	Pid_PA_Lambda,		// 134
	Pid_PA_Lambda,		// 135
	Pid_PA_Ks,		// 136
	Pid_PA_Ks,		// 137
	Pid_PA_Ks,		// 138
	Pid_PA_Lambda,		// 139
	Pid_PA_Lambda,		// 140
	Pid_PA_Lambda,		// 141
	Pid_AA_Ks,		// 142
	Pid_AA_Ks,		// 143
	Pid_AA_Ks,		// 144
	Pid_AA_Ks,		// 145
	Pid_AA_Ks,		// 146
	Pid_AA_Ks,		// 147
	Pid_AA_Lambda,		// 148
	Pid_AA_Lambda,		// 149
	Pid_AA_Lambda,		// 150
	Pid_AA_Lambda,		// 151
	Pid_AA_Lambda,		// 152
	Pid_AA_Lambda,		// 153
	Pid_AA_Ks,		// 154
	Pid_AA_Ks,		// 155
	Pid_AA_Ks,		// 156
	Pid_AA_Lambda,		// 157
	Pid_AA_Lambda,		// 158
	Pid_AA_Lambda,		// 159
	Pid_AA_Ks,		    // 160
	Pid_AA_Ks,		    // 161
	Pid_AA_Ks,		    // 162
	Pid_AA_Lambda,		// 163
	Pid_AA_Lambda,		// 164
	Pid_AA_Lambda,		// 165
	Pid_AA_Ks,		    // 166
	Pid_AA_Lambda,		// 167
	Pid_AA_Ks,		    // 168
	Pid_AA_Ks,		    // 169
	Pid_AA_Ks,		    // 170
	Pid_AA_Ks,		    // 171
	Pid_AA_Ks,		    // 172
	Pid_AA_Ks,		    // 173
	Pid_AA_Lambda,	    // 174
	Pid_AA_Lambda,	    // 175
	Pid_AA_Lambda,	    // 176
	Pid_AA_Lambda,	    // 177
	Pid_AA_Lambda,	    // 178
	Pid_AA_Lambda,	    // 179
	Pid_AA_Ks,		    // 180
	Pid_AA_Lambda,	    // 181
	Pid_PA_Ks,		    // 182
	Pid_PA_Ks,		    // 183
	Pid_PA_Ks,		    // 184
	Pid_PA_Ks,		    // 185
	Pid_PA_Ks,		    // 186
	Pid_PA_Ks,		    // 187
	Pid_PA_Ks,		    // 188
	Pid_PA_Ks,		    // 189
	Pid_PA_Ks,		    // 190
	Pid_PA_Ks,		    // 191
	Pid_PA_Ks,		    // 192
	Pid_PA_Ks,		    // 193
	Pid_PA_Ks,		    // 194
	Pid_PA_Ks,		    // 195
	Pid_PA_Ks,		    // 196
	Pid_PA_Ks,		    // 197
	Pid_PA_Lambda,	    // 198
	Pid_PA_Lambda,	    // 199
	Pid_PA_Lambda,	    // 200
	Pid_PA_Lambda,	    // 201
	Pid_PA_Lambda,	    // 202
	Pid_PA_Lambda,	    // 203
	Pid_PA_Lambda,	    // 204
	Pid_PA_Lambda,	    // 205
	Pid_PA_Lambda,	    // 206
	Pid_PA_Lambda,	    // 207
	Pid_PA_Lambda,	    // 208
	Pid_PA_Lambda,	    // 209
	Pid_PA_Lambda,	    // 210
	Pid_PA_Lambda,	    // 211
	Pid_PA_Lambda,	    // 212
	Pid_PA_Lambda,	    // 213
	Pid_PA_Ks,	        // 214
	Pid_PA_Ks,	        // 215
	Pid_PA_Ks,	        // 216
	Pid_PA_Ks,	        // 217
	Pid_PA_Ks,	        // 218
	Pid_PA_Lambda,	    // 219
	Pid_PA_Lambda,	    // 220
	Pid_PA_Lambda,	    // 221
	Pid_PA_Lambda,	    // 222
	Pid_PA_Lambda,	    // 223
	Pid_AA_Lambda,	    // 224
	Pid_AA_Lambda,	    // 225
	Pid_AA_Lambda,	    // 226
	Pid_AA_Lambda,	    // 227
	Pid_AA_Lambda,	    // 228
	Pid_AA_Lambda,	    // 229
	Pid_AA_Lambda,	    // 230
	Pid_AA_Lambda,	    // 231
	Pid_AA_Lambda,	    // 232
	Pid_AA_Lambda,	    // 233
	Pid_AA_Lambda,	    // 234
	Pid_PA_Ks,	        // 235
	Pid_PA_Ks,	        // 236
	Pid_PA_Ks,	        // 237
	Pid_PA_Ks,	        // 238
	Pid_PA_Ks,	        // 239
	Pid_PA_Ks,	        // 240
	Pid_PA_Ks,	        // 241
	Pid_PA_Ks,	        // 242
	Pid_PA_Ks,	        // 243
	Pid_PA_Ks,	        // 244
	Pid_PA_Ks,	        // 245
	Pid_PA_Ks,	        // 246
	Pid_PA_Ks,	        // 247
	Pid_PA_Ks,	        // 248
	Pid_PA_Ks,	        // 249
	Pid_PA_Ks,	        // 250
	Pid_PA_Ks,	        // 251
	Pid_PA_Ks,	        // 252
	Pid_PA_Ks,	        // 253
	Pid_PA_Ks,	        // 254
	Pid_PA_Ks,	        // 255
	Pid_PA_Ks,	        // 256
	Pid_PA_Ks,	        // 257
	Pid_PA_Ks,	        // 258
	Pid_PA_Ks,	        // 259
	Pid_PA_Ks,	        // 260
	Pid_PA_Ks,	        // 261
	Pid_PA_Ks,	        // 262
	Pid_PA_Ks,	        // 263
	Pid_PA_Ks,	        // 264
	Pid_PA_Ks,	        // 265
	Pid_PA_Ks,	        // 266
	Pid_PA_Ks,	        // 267
	Pid_PA_Ks,	        // 268
	Pid_PA_Ks,	        // 269
	Pid_PA_Lambda,	    // 270
	Pid_PA_Lambda,	    // 271
	Pid_PA_Lambda,	    // 272
	Pid_PA_Lambda,	    // 273
	Pid_PA_Lambda,	    // 274
	Pid_PA_Lambda,	    // 275
	Pid_PA_Lambda,	    // 276
	Pid_PA_Lambda,	    // 277
	Pid_PA_Lambda,	    // 278
	Pid_PA_Lambda,	    // 279
	Pid_PA_Lambda,	    // 280
	Pid_PA_Lambda,	    // 281
	Pid_PA_Lambda,	    // 282
	Pid_PA_Lambda,	    // 283
	Pid_PA_Lambda,	    // 284
	Pid_PA_Lambda,	    // 285
	Pid_PA_Lambda,	    // 286
	Pid_PA_Lambda,	    // 287
	Pid_PA_Lambda,	    // 288
	Pid_PA_Lambda,	    // 289
	Pid_PA_Lambda,	    // 290
	Pid_PA_Lambda,	    // 291
	Pid_PA_Lambda,	    // 292
	Pid_PA_Lambda,	    // 293
	Pid_PA_Lambda,	    // 294
	Pid_PA_Lambda,	    // 295
	Pid_PA_Lambda,	    // 296
	Pid_PA_Lambda,	    // 297
	Pid_PA_Lambda,	    // 298
	Pid_PA_Lambda,	    // 299
	Pid_PA_Lambda,	    // 300
	Pid_PA_Lambda,	    // 301
	Pid_PA_Lambda,	    // 302
	Pid_PA_Lambda,	    // 303
	Pid_PA_Lambda,	    // 304
	Pid_PA_Ks,	        // 305
	Pid_PA_Ks,	        // 306
	Pid_PA_Ks,	        // 307
	Pid_PA_Ks,	        // 308
	Pid_PA_Ks,	        // 309
	Pid_PA_Ks,	        // 310
	Pid_PA_Ks,	        // 311
	Pid_PA_Ks,	        // 312
	Pid_PA_Ks,	        // 313
	Pid_PA_Ks,	        // 314
	Pid_PA_Ks,	        // 315
	Pid_PA_Ks,	        // 316
	Pid_PA_Ks,	        // 317
	Pid_PA_Ks,	        // 318
	Pid_PA_Ks,	        // 319
	Pid_PA_Ks,	        // 320
	Pid_PA_Ks,	        // 321
	Pid_PA_Ks,	        // 322
	Pid_PA_Ks,	        // 323
	Pid_PA_Ks,	        // 324
	Pid_PA_Ks,	        // 325
	Pid_PA_Ks,	        // 326
	Pid_PA_Ks,	        // 327
	Pid_PA_Ks,	        // 328
	Pid_PA_Ks,	        // 329
	Pid_PA_Ks,	        // 330
	Pid_PA_Ks,	        // 331
	Pid_PA_Ks,	        // 332
	Pid_PA_Ks,	        // 333
	Pid_PA_Ks,	        // 334
	Pid_PA_Ks,	        // 335
	Pid_PA_Ks,	        // 336
	Pid_PA_Ks,	        // 337
	Pid_PA_Ks,	        // 338
	Pid_PA_Ks,	        // 339
	Pid_PA_Ks,	        // 340
	Pid_PA_Ks,	        // 341
	Pid_PA_Ks,	        // 342
	Pid_PA_Lambda,	    // 343
	Pid_PA_Lambda,	    // 344
	Pid_PA_Lambda,	    // 345
	Pid_PA_Lambda,	    // 346
	Pid_PA_Lambda,	    // 347
	Pid_PA_Lambda,	    // 348
	Pid_PA_Lambda,	    // 349
	Pid_PA_Lambda,	    // 350
	Pid_PA_Lambda,	    // 351
	Pid_PA_Lambda,	    // 352
	Pid_PA_Lambda,	    // 353
	Pid_PA_Lambda,	    // 354
	Pid_PA_Lambda,	    // 355
	Pid_PA_Lambda,	    // 356
	Pid_PA_Lambda,	    // 357
	Pid_PA_Lambda,	    // 358
	Pid_PA_Lambda,	    // 359
	Pid_PA_Lambda,	    // 360
	Pid_PA_Lambda,	    // 361
	Pid_PA_Lambda,	    // 362
	Pid_PA_Lambda,	    // 363
	Pid_PA_Lambda,	    // 364
	Pid_PA_Lambda,	    // 365
	Pid_PA_Lambda,	    // 366
	Pid_PA_Lambda,	    // 367
	Pid_PA_Lambda,	    // 368
	Pid_PA_Lambda,	    // 369
	Pid_PA_Lambda,	    // 370
	Pid_PA_Lambda,	    // 371
	Pid_PA_Lambda,	    // 372
	Pid_PA_Lambda,	    // 373
	Pid_PA_Lambda,	    // 374
	Pid_PA_Lambda,	    // 375
	Pid_PA_Lambda,	    // 376
	Pid_PA_Lambda,	    // 377
	Pid_PA_Lambda,	    // 378
	Pid_PA_Lambda,	    // 379
	Pid_PA_Lambda,	    // 380
	Pid_PA_Hadron,	    // 381
	Pid_PA_Hadron,	    // 382
	Pid_PA_Hadron,	    // 383
	Pid_PA_Hadron,	    // 384
	Pid_PA_Hadron,	    // 385
	Pid_PA_Hadron,	    // 386
	Pid_PA_Hadron,	    // 387
	Pid_PA_Hadron,	    // 388
	Pid_PA_Hadron,	    // 389
	Pid_PA_Hadron,	    // 390
	Pid_PA_Hadron,	    // 391
	Pid_PA_Hadron,	    // 392
	Pid_PA_Hadron,	    // 393
	Pid_PA_Hadron,	    // 394
	Pid_PA_Hadron,	    // 395
	Pid_PA_Hadron,	    // 396
	Pid_PA_Hadron,	    // 397
	Pid_PA_Hadron,	    // 398
	Pid_PA_Hadron,	    // 399
	Pid_PA_Hadron,	    // 400
	Pid_PA_Hadron,	    // 401
	Pid_PA_Ks,	        // 402
	Pid_PA_Ks,	        // 403
	Pid_PA_Ks,	        // 404
	Pid_PA_Ks,	        // 405
	Pid_PA_Ks,	        // 406
	Pid_PA_Ks,	        // 407
	Pid_PA_Lambda,	    // 408
	Pid_PA_Lambda,	    // 409
	Pid_PA_Lambda,	    // 410
	Pid_PA_Lambda,	    // 411
	Pid_PA_Lambda,	    // 412
	Pid_PA_Lambda,	    // 413
	Pid_PA_Hadron,	    // 414
	Pid_PA_Hadron,	    // 415
	Pid_PA_Hadron,	    // 416
	Pid_PA_Hadron,	    // 417
	Pid_PA_Hadron,	    // 418
	Pid_PA_Hadron,	    // 419
	Pid_PA_Hadron,	    // 420
	Pid_PA_Hadron,	    // 421
	Pid_PA_Hadron,	    // 422
	Pid_PA_Hadron,	    // 423
	Pid_PA_Hadron,	    // 424
	Pid_PA_Hadron,	    // 425
	Pid_PA_Hadron,	    // 426
	Pid_PA_Hadron,	    // 427
	Pid_PA_Hadron,	    // 428
	Pid_PA_Hadron,	    // 429
	Pid_PA_Hadron,	    // 430
	Pid_PA_Hadron,	    // 431
	Pid_PA_Hadron,	    // 432
	Pid_PA_Hadron,	    // 433
	Pid_PA_Hadron,	    // 434
};

#include <TChain.h>
#include <iostream>

TChain * chV = new TChain("trV");
void addchain(int s1)
{
        std::cout << fname[s1] << std::endl;
        chV->Add(Form("%s/*.root/QWCumuDiff/trV", fname[s1]));
}
