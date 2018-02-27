
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
};

const int Pid_Non	= 0;
const int Pid_PA_Ks	= 1;
const int Pid_PA_Lambda	= 2;
const int Pid_PA_Omega	= 3;
const int Pid_AA_Ks	= 11;
const int Pid_AA_Lambda	= 12;
const int Pid_AA_Omega	= 13;

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
};

#include <TChain.h>
#include <iostream>

TChain * chV = new TChain("trV");
void addchain(int s1)
{
        std::cout << fname[s1] << std::endl;
        chV->Add(Form("%s/*.root/QWCumuDiff/trV", fname[s1]));
}
