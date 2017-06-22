
char const * fname[] = {
	"test",							// 0 test
	"../cumu/PAHighMultiplicity0/crab_PAHM0_Kscumu_eff_v2/170622_135650/0000/",			// 1 Ks HM0 pPb
};

char const * ftxt[] = {
	"txt/test/",			// 0
	"txt/PAHM0_Ks/",		// 1
};

#include <TChain.h>
#include <iostream>

TChain * chV = new TChain("trV");
void addchain(int s1)
{
        std::cout << fname[s1] << std::endl;
        chV->Add(Form("%s/*.root/QWCumuDiff/trV", fname[s1]));
}
