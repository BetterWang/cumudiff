
char const * fname[] = {
	"test",							// 0 test
	"../cumu/PAHighMultiplicity0/crab_PAHM0_Kscumu_eff_v9/170731_154149/0000/",			// 1 Ks HM0 pPb
	"../cumu/PAHighMultiplicity1/crab_PAHM1_Kscumu_eff_v9/170731_154224/0000/",			// 2 Ks HM1 pPb
	"../cumu/PAHighMultiplicity7/crab_PAHM7_Kscumu_eff_v9/170731_154524/0000/",			// 3 Ks HM7 pPb
	"../cumu/PAHighMultiplicity0/crab_PAHM0_Kscumu_eff_reverse_v9/170801_104216/0000/",			// 4 Ks HM0 pPb reverse
	"../cumu/PAHighMultiplicity1/crab_PAHM1_Kscumu_eff_reverse_v9/170801_104234/0000/",			// 5 Ks HM1 pPb reverse
	"../cumu/PAHighMultiplicity7/crab_PAHM7_Kscumu_eff_reverse_v9/170801_104410/0000/",			// 6 Ks HM7 pPb reverse
	"NA",			// 7 Ks HM0 pPb merge
	"NA",			// 8 Ks HM1 pPb merge
	"NA",			// 9 Ks HM7 pPb merge
	"../cumu/PAHighMultiplicity0/crab_PAHM0_Lambda_cumu_eff_v9/170731_202351/0000/",			// 10 Lambda HM0 pPb
	"../cumu/PAHighMultiplicity1/crab_PAHM1_Lambda_cumu_eff_v9/170731_202408/0000/",			// 11 Lambda HM1 pPb
	"../cumu/PAHighMultiplicity7/crab_PAHM7_Lambda_cumu_eff_v9/170731_202709/0000/",			// 12 Lambda HM7 pPb
	"../cumu/PAHighMultiplicity0/crab_PAHM0_Lambda_cumu_eff_reverse_v9/170801_104634/0000/",		// 13 Lambda HM0 pPb reverse
	"../cumu/PAHighMultiplicity1/crab_PAHM1_Lambda_cumu_eff_reverse_v9/170801_104650/0000/",		// 14 Lambda HM1 pPb reverse
	"../cumu/PAHighMultiplicity7/crab_PAHM7_Lambda_cumu_eff_reverse_v9/170801_104838/0000/",		// 15 Lambda HM7 pPb reverse
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
	"../cumu/PAHighMultiplicity2/crab_PAHM2_Kscumu_eff_v9/170731_154255/0000/",			// 28 Ks HM2 pPb
	"../cumu/PAHighMultiplicity3/crab_PAHM3_Kscumu_eff_v9/170731_154321/0000/",			// 29 Ks HM3 pPb
	"../cumu/PAHighMultiplicity4/crab_PAHM4_Kscumu_eff_v9/170731_154353/0000/",			// 30 Ks HM4 pPb
	"../cumu/PAHighMultiplicity5/crab_PAHM5_Kscumu_eff_v9/170731_154424/0000/",			// 31 Ks HM5 pPb
	"../cumu/PAHighMultiplicity6/crab_PAHM6_Kscumu_eff_v9/170731_154453/0000/",			// 32 Ks HM6 pPb
	"../cumu/PAHighMultiplicity2/crab_PAHM2_Kscumu_eff_reverse_v9/170801_104251/0000/",		// 33 Ks HM2 pPb reverse
	"../cumu/PAHighMultiplicity3/crab_PAHM3_Kscumu_eff_reverse_v9/170801_104307/0000/",		// 34 Ks HM3 pPb reverse
	"../cumu/PAHighMultiplicity4/crab_PAHM4_Kscumu_eff_reverse_v9/170801_104324/0000/",		// 35 Ks HM4 pPb reverse
	"../cumu/PAHighMultiplicity5/crab_PAHM5_Kscumu_eff_reverse_v9/170801_104339/0000/",		// 36 Ks HM5 pPb reverse
	"../cumu/PAHighMultiplicity6/crab_PAHM6_Kscumu_eff_reverse_v9/170801_104355/0000/",		// 37 Ks HM6 pPb reverse
	"../cumu/PAHighMultiplicity2/crab_PAHM2_Lambda_cumu_eff_v9/170731_202545/0000/",		// 38 Lambda HM2 pPb
	"../cumu/PAHighMultiplicity3/crab_PAHM3_Lambda_cumu_eff_v9/170731_202601/0000/",		// 39 Lambda HM3 pPb
	"../cumu/PAHighMultiplicity4/crab_PAHM4_Lambda_cumu_eff_v9/170731_202618/0000/",		// 40 Lambda HM4 pPb
	"../cumu/PAHighMultiplicity5/crab_PAHM5_Lambda_cumu_eff_v9/170731_202637/0000/",		// 41 Lambda HM5 pPb
	"../cumu/PAHighMultiplicity6/crab_PAHM6_Lambda_cumu_eff_v9/170731_202653/0000/",		// 42 Lambda HM6 pPb
	"../cumu/PAHighMultiplicity2/crab_PAHM2_Lambda_cumu_eff_reverse_v9/170801_104711/0000/",	// 43 Lambda HM2 pPb reverse
	"../cumu/PAHighMultiplicity3/crab_PAHM3_Lambda_cumu_eff_reverse_v9/170801_104729/0000/",	// 44 Lambda HM3 pPb reverse
	"../cumu/PAHighMultiplicity4/crab_PAHM4_Lambda_cumu_eff_reverse_v9/170801_104746/0000/",	// 45 Lambda HM4 pPb reverse
	"../cumu/PAHighMultiplicity5/crab_PAHM5_Lambda_cumu_eff_reverse_v9/170801_104803/0000/",	// 46 Lambda HM5 pPb reverse
	"../cumu/PAHighMultiplicity6/crab_PAHM6_Lambda_cumu_eff_reverse_v9/170801_104822/0000/",	// 47 Lambda HM6 pPb reverse
	"../cumu/HIMinimumBias5/crab_HIMB5_Kscumu_eff_v2/170711_170943/0000/",				// 48 Ks HIMB5
	"../cumu/HIMinimumBias6/crab_HIMB6_Kscumu_eff_v2/170711_171005/0000/",				// 49 Ks HIMB6
	"../cumu/HIMinimumBias7/crab_HIMB7_Kscumu_eff_v2/170711_171025/0000/",				// 50 Ks HIMB7
	"../cumu/HIMinimumBias5/crab_HIMB5_Lambda_cumu_eff_v2/170711_171101/0000/",			// 51 Lambda HIMB5
	"../cumu/HIMinimumBias6/crab_HIMB6_Lambda_cumu_eff_v2/170711_171126/0000/",			// 52 Lambda HIMB5
	"../cumu/HIMinimumBias7/crab_HIMB7_Lambda_cumu_eff_v2/170711_171150/0000/",			// 53 Lambda HIMB5
	"NA",			// 54 Ks merged HIMB567
	"NA",			// 55 Lambda merged HIMB567
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
};

#include <TChain.h>
#include <iostream>

TChain * chV = new TChain("trV");
void addchain(int s1)
{
        std::cout << fname[s1] << std::endl;
        chV->Add(Form("%s/*.root/QWCumuDiff/trV", fname[s1]));
}
