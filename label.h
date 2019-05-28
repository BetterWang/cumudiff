
char const * fname[] = {
	"test",							// 0 test
	"",			                    // 1 PbPb HIMB1 Lambda
};

char const * ftxt[] = {
	"txt/test/",				    // 0
    "txt/HIMB1_Lambda_Signal",      // 1
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
	Pid_AA_Lambda,		// 1
};

#include <TChain.h>
#include <iostream>

TChain * chV = new TChain("trV");
void addchain(int s1)
{
        std::cout << fname[s1] << std::endl;
        chV->Add(Form("%s/*.root/QWCumuDiff/trV", fname[s1]));
}
