/// \file
/// \ingroup tutorial_tmva
/// \notebook -nodraw
/// This macro provides a simple example on how to use the trained classifiers
/// within an analysis module
/// - Project   : TMVA - a Root-integrated toolkit for multivariate data analysis
/// - Package   : TMVA
/// - Exectuable: TMVAClassificationApplication
///
/// \macro_output
/// \macro_code
/// \author Andreas Hoecker

#include <cstdlib>
#include <vector>
#include <iostream>
#include <map>
#include <string>

#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TStopwatch.h"

#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "TMVA/MethodCuts.h"

using namespace TMVA;

void TMVAClassificationApplication( TString myMethodList = "" )
{

   //---------------------------------------------------------------
   // This loads the library
   TMVA::Tools::Instance();

   // Default MVA methods to be trained + tested
   std::map<std::string,int> Use;

   // Cut optimisation
   Use["Cuts"]            = 1;
   Use["CutsD"]           = 0;
   Use["CutsPCA"]         = 0;
   Use["CutsGA"]          = 0;
   Use["CutsSA"]          = 0;
   //
   // 1-dimensional likelihood ("naive Bayes estimator")
   Use["Likelihood"]      = 0;
   Use["LikelihoodD"]     = 0; // the "D" extension indicates decorrelated input variables (see option strings)
   Use["LikelihoodPCA"]   = 0; // the "PCA" extension indicates PCA-transformed input variables (see option strings)
   Use["LikelihoodKDE"]   = 0;
   Use["LikelihoodMIX"]   = 0;
   //
   // Mutidimensional likelihood and Nearest-Neighbour methods
   Use["PDERS"]           = 0;
   Use["PDERSD"]          = 0;
   Use["PDERSPCA"]        = 0;
   Use["PDEFoam"]         = 0;
   Use["PDEFoamBoost"]    = 0; // uses generalised MVA method boosting
   Use["KNN"]             = 0; // k-nearest neighbour method
   //
   // Linear Discriminant Analysis
   Use["LD"]              = 1; // Linear Discriminant identical to Fisher
   Use["Fisher"]          = 0;
   Use["FisherG"]         = 0;
   Use["BoostedFisher"]   = 0; // uses generalised MVA method boosting
   Use["HMatrix"]         = 0;
   //
   // Function Discriminant analysis
   Use["FDA_GA"]          = 0; // minimisation of user-defined function using Genetics Algorithm
   Use["FDA_SA"]          = 0;
   Use["FDA_MC"]          = 0;
   Use["FDA_MT"]          = 0;
   Use["FDA_GAMT"]        = 0;
   Use["FDA_MCMT"]        = 0;
   //
   // Neural Networks (all are feed-forward Multilayer Perceptrons)
   Use["MLP"]             = 0; // Recommended ANN
   Use["MLPBFGS"]         = 0; // Recommended ANN with optional training method
   Use["MLPBNN"]          = 0; // Recommended ANN with BFGS training method and bayesian regulator
   Use["CFMlpANN"]        = 0; // Depreciated ANN from ALEPH
   Use["TMlpANN"]         = 0; // ROOT's own ANN
   Use["DNN_CPU"] = 0;         // CUDA-accelerated DNN training.
   Use["DNN_GPU"] = 0;         // Multi-core accelerated DNN.
   //
   // Support Vector Machine
   Use["SVM"]             = 0;
   //
   // Boosted Decision Trees
   Use["BDT250_D2"]       = 1; // uses Adaptive Boost
   Use["BDT250_D3"]       = 1; // uses Adaptive Boost
   Use["BDT500_D2"]       = 1; // uses Adaptive Boost
   Use["BDT500_D3"]       = 1; // uses Adaptive Boost
   Use["BDT850_D3"]       = 1; // uses Adaptive Boost
   Use["BDTG1000_D2"]     = 1; // uses Gradient Boost
   Use["BDTG250_D2"]      = 1; // uses Gradient Boost
   Use["BDTG250_D3"]      = 1; // uses Gradient Boost
   Use["BDTB"]            = 0; // uses Bagging
   Use["BDTD"]            = 0; // decorrelation + Adaptive Boost
   Use["BDTF"]            = 0; // allow usage of fisher discriminant for node splitting
   //
   // Friedman's RuleFit method, ie, an optimised series of cuts ("rules")
   Use["RuleFit"]         = 0;
   // ---------------------------------------------------------------
   Use["Plugin"]          = 0;
   Use["Category"]        = 0;
   Use["SVM_Gauss"]       = 0;
   Use["SVM_Poly"]        = 0;
   Use["SVM_Lin"]         = 0;

   std::cout << std::endl;
   std::cout << "==> Start TMVAClassificationApplication" << std::endl;

   // --------------------------------------------------------------------------------------------------

   // Create the Reader object

   TMVA::Reader *reader = new TMVA::Reader( "!Color:!Silent" );

   // Create a set of variables and declare them to the reader
   // - the variable names MUST corresponds in name and type to those given in the weight file(s) used
   Float_t pt;
   Float_t rapidity;
   Float_t vtxChi2;
   Float_t cosThetaXYZ;
   Float_t Lxyz;
   Float_t vtxDecaySigXYZ;
   Float_t DCA;
   Float_t pTrkNHit;
   Float_t pTrkPt;
   Float_t pTrkPtError;
   Float_t pTrkEta;
   Float_t pTrkNPxLayer;
   Float_t pTrkDCASigXY;
   Float_t pTrkDCASigZ;
   Float_t nTrkNHit;
   Float_t nTrkPt;
   Float_t nTrkPtError;
   Float_t nTrkEta;
   Float_t nTrkNPxLayer;
   Float_t nTrkDCASigXY;
   Float_t nTrkDCASigZ;
   Float_t Cent; 

   Float_t mass;
   Float_t eta;
   Float_t phi;
   Float_t pdgId;

   reader->AddVariable( "pt",               &pt             );
   reader->AddVariable( "rapidity",         &rapidity       );
   reader->AddVariable( "vtxChi2",          &vtxChi2        );
   reader->AddVariable( "cosThetaXYZ",      &cosThetaXYZ    );
   reader->AddVariable( "Lxyz",             &Lxyz           );
   reader->AddVariable( "vtxDecaySigXYZ",   &vtxDecaySigXYZ );
   reader->AddVariable( "DCA",              &DCA            );
   reader->AddVariable( "pTrkNHit",         &pTrkNHit       );
   reader->AddVariable( "pTrkPt",           &pTrkPt         );
   reader->AddVariable( "pTrkPtError",      &pTrkPtError    );
   reader->AddVariable( "pTrkEta",          &pTrkEta        );
   reader->AddVariable( "pTrkNPxLayer",     &pTrkNPxLayer   );
   reader->AddVariable( "pTrkDCASigXY",     &pTrkDCASigXY   );
   reader->AddVariable( "pTrkDCASigZ",      &pTrkDCASigZ    );
   reader->AddVariable( "nTrkNHit",         &nTrkNHit       );
   reader->AddVariable( "nTrkPt",           &nTrkPt         );
   reader->AddVariable( "nTrkPtError",      &nTrkPtError    );
   reader->AddVariable( "nTrkEta",          &nTrkEta        );
   reader->AddVariable( "nTrkNPxLayer",     &nTrkNPxLayer   );
   reader->AddVariable( "nTrkDCASigXY",     &nTrkDCASigXY   );
   reader->AddVariable( "nTrkDCASigZ",      &nTrkDCASigZ    );
   reader->AddVariable( "Cent",             &Cent           );

   // Spectator variables declared in the training have to be added to the reader, too
   reader->AddSpectator( "mass",   &mass);
   reader->AddSpectator( "eta",    &eta);
   reader->AddSpectator( "phi",    &phi);
   reader->AddSpectator( "pdgId",  &pdgId);

//   Float_t Category_cat1, Category_cat2, Category_cat3;
//   if (Use["Category"]){
//      // Add artificial spectators for distinguishing categories
//      reader->AddSpectator( "Category_cat1 := var3<=0",             &Category_cat1 );
//      reader->AddSpectator( "Category_cat2 := (var3>0)&&(var4<0)",  &Category_cat2 );
//      reader->AddSpectator( "Category_cat3 := (var3>0)&&(var4>=0)", &Category_cat3 );
//   }
//
   // Book the MVA methods

   TString dir    = "dataset_full_LM/weights/";

   // Book method(s)
   for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) {
      if (it->second) {
         TString methodName = TString(it->first) + TString(" method");
         TString weightfile = dir + TString("TMVAClassification") + TString("_") + TString(it->first) + TString(".weights.xml");
         reader->BookMVA( methodName, weightfile );
      }
   }

   // Book output histograms
   UInt_t nbin = 200;
   TH1F *histLD(0);
   TH1F *histBdt250D2(0);
   TH1F *histBdt250D3(0);
   TH1F *histBdt500D2(0);
   TH1F *histBdt500D3(0);
   TH1F *histBdt850D3(0);
   TH1F *histBdtG1000D2(0);
   TH1F *histBdtG250D2(0);
   TH1F *histBdtG250D3(0);

   if (Use["LD"])            histLD       = new TH1F( "MVA_LD",            "MVA_LD",            nbin, -2, 2 );
   if (Use["BDT250_D2"])     histBdt250D2 = new TH1F( "MVA_BDT250D2",      "MVA_BDT250D2",      nbin, -1.0, 1.0 );
   if (Use["BDT250_D3"])     histBdt250D3 = new TH1F( "MVA_BDT250D3",      "MVA_BDT250D3",      nbin, -1.0, 1.0 );
   if (Use["BDT500_D2"])     histBdt500D2 = new TH1F( "MVA_BDT500D2",      "MVA_BDT500D2",      nbin, -1.0, 1.0 );
   if (Use["BDT500_D3"])     histBdt500D3 = new TH1F( "MVA_BDT500D3",      "MVA_BDT500D3",      nbin, -1.0, 1.0 );
   if (Use["BDT850_D3"])     histBdt850D3 = new TH1F( "MVA_BDT850D3",      "MVA_BDT850D3",      nbin, -1.0, 1.0 );
   if (Use["BDTG1000_D2"])   histBdtG1000D2 = new TH1F( "MVA_BDTG1000D2",    "MVA_BDTG1000D2",      nbin, -1.0, 1.0 );
   if (Use["BDTG250_D2"])    histBdtG250D2 = new TH1F( "MVA_BDTG250D2",    "MVA_BDTG250D2",      nbin, -1.0, 1.0 );
   if (Use["BDTG250_D3"])    histBdtG250D3 = new TH1F( "MVA_BDTG250D3",    "MVA_BDTG250D3",      nbin, -1.0, 1.0 );

   // Prepare input tree (this must be replaced by your data source)
   // in this example, there is a toy tree with signal and one with background events
   // we'll later on use only the "signal" events for the test in this example.
   //
   TFile *input = new TFile("/afs/cern.ch/user/q/qwang/work/cleanroomRun2/Ana/CMSSW_10_3_1_patch3/src/QWAna/QWCumuDiff/run2018/cumu_V0Tree.root");
   std::cout << "--- TMVAClassificationApp    : Using input file: " << input->GetName() << std::endl;

   // Event loop

   // Prepare the event tree
   // - Here the variable names have to corresponds to your tree
   // - You can use the same variables as above which is slightly faster,
   //   but of course you can use different ones and copy the values inside the event loop
   //
   std::cout << "--- Select signal sample" << std::endl;
   TTree* trV = (TTree*)input->Get("tree/trV");
   string prefix = "LM";
   trV->SetMakeClass(1);
   trV->SetBranchStatus("*", 0);
   trV->SetBranchStatus("Cent", 1);
   trV->SetBranchStatus( (prefix+"pt").c_str(), 1 );
   trV->SetBranchStatus( (prefix+"phi").c_str(), 1 );
   trV->SetBranchStatus( (prefix+"eta").c_str(), 1 );
   trV->SetBranchStatus( (prefix+"rapidity").c_str(), 1 );
   trV->SetBranchStatus( (prefix+"mass").c_str(), 1 );
   trV->SetBranchStatus( (prefix+"vtxChi2").c_str(), 1 );
   trV->SetBranchStatus( (prefix+"cosThetaXYZ").c_str(), 1 );
   trV->SetBranchStatus( (prefix+"Lxyz").c_str(), 1 );
   trV->SetBranchStatus( (prefix+"vtxDecaySigXYZ").c_str(), 1 );
   trV->SetBranchStatus( (prefix+"DCA").c_str(), 1 );
   trV->SetBranchStatus( (prefix+"pdgId").c_str(), 1 );
   trV->SetBranchStatus( (prefix+"pTrkQuality").c_str(), 1 );
   trV->SetBranchStatus( (prefix+"pTrkNHit").c_str(), 1 );
   trV->SetBranchStatus( (prefix+"pTrkPt").c_str(), 1 );
   trV->SetBranchStatus( (prefix+"pTrkPtError").c_str(), 1 );
   trV->SetBranchStatus( (prefix+"pTrkEta").c_str(), 1 );
   trV->SetBranchStatus( (prefix+"pTrkNPxLayer").c_str(), 1 );
   trV->SetBranchStatus( (prefix+"pTrkDCASigXY").c_str(), 1 );
   trV->SetBranchStatus( (prefix+"pTrkDCASigZ").c_str(), 1 );
   trV->SetBranchStatus( (prefix+"nTrkQuality").c_str(), 1 );
   trV->SetBranchStatus( (prefix+"nTrkNHit").c_str(), 1 );
   trV->SetBranchStatus( (prefix+"nTrkPt").c_str(), 1 );
   trV->SetBranchStatus( (prefix+"nTrkPtError").c_str(), 1 );
   trV->SetBranchStatus( (prefix+"nTrkEta").c_str(), 1 );
   trV->SetBranchStatus( (prefix+"nTrkNPxLayer").c_str(), 1 );
   trV->SetBranchStatus( (prefix+"nTrkDCASigXY").c_str(), 1 );
   trV->SetBranchStatus( (prefix+"nTrkDCASigZ").c_str(), 1 );

   vector<double>  *t_pt = 0;
   vector<double>  *t_phi = 0;
   vector<double>  *t_eta = 0;
   vector<double>  *t_rapidity = 0;
   vector<double>  *t_mass = 0;
   vector<double>  *t_vtxChi2 = 0;
   vector<double>  *t_cosThetaXYZ = 0;
   vector<double>  *t_Lxyz = 0;
   vector<double>  *t_vtxDecaySigXYZ = 0;
   vector<double>  *t_DCA = 0;
   vector<double>  *t_pdgId = 0;
   vector<double>  *t_pTrkQuality = 0;
   vector<double>  *t_pTrkNHit = 0;
   vector<double>  *t_pTrkPt = 0;
   vector<double>  *t_pTrkPtError = 0;
   vector<double>  *t_pTrkEta = 0;
   vector<double>  *t_pTrkNPxLayer = 0;
   vector<double>  *t_pTrkDCASigXY = 0;
   vector<double>  *t_pTrkDCASigZ = 0;
   vector<double>  *t_nTrkQuality = 0;
   vector<double>  *t_nTrkNHit = 0;
   vector<double>  *t_nTrkPt = 0;
   vector<double>  *t_nTrkPtError = 0;
   vector<double>  *t_nTrkEta = 0;
   vector<double>  *t_nTrkNPxLayer = 0;
   vector<double>  *t_nTrkDCASigXY = 0;
   vector<double>  *t_nTrkDCASigZ = 0;
   Double_t        t_Cent = -1;

   trV->SetBranchAddress( (prefix+"pt").c_str(),             &t_pt);
   trV->SetBranchAddress( (prefix+"phi").c_str(),            &t_phi);
   trV->SetBranchAddress( (prefix+"eta").c_str(),            &t_eta);
   trV->SetBranchAddress( (prefix+"rapidity").c_str(),       &t_rapidity);
   trV->SetBranchAddress( (prefix+"mass").c_str(),           &t_mass);
   trV->SetBranchAddress( (prefix+"vtxChi2").c_str(),        &t_vtxChi2);
   trV->SetBranchAddress( (prefix+"cosThetaXYZ").c_str(),    &t_cosThetaXYZ);
   trV->SetBranchAddress( (prefix+"Lxyz").c_str(),           &t_Lxyz);
   trV->SetBranchAddress( (prefix+"vtxDecaySigXYZ").c_str(), &t_vtxDecaySigXYZ);
   trV->SetBranchAddress( (prefix+"DCA").c_str(),            &t_DCA);
   trV->SetBranchAddress( (prefix+"pdgId").c_str(),          &t_pdgId);
   trV->SetBranchAddress( (prefix+"pTrkQuality").c_str(),    &t_pTrkQuality);
   trV->SetBranchAddress( (prefix+"pTrkNHit").c_str(),       &t_pTrkNHit);
   trV->SetBranchAddress( (prefix+"pTrkPt").c_str(),         &t_pTrkPt);
   trV->SetBranchAddress( (prefix+"pTrkPtError").c_str(),    &t_pTrkPtError);
   trV->SetBranchAddress( (prefix+"pTrkEta").c_str(),        &t_pTrkEta);
   trV->SetBranchAddress( (prefix+"pTrkNPxLayer").c_str(),   &t_pTrkNPxLayer);
   trV->SetBranchAddress( (prefix+"pTrkDCASigXY").c_str(),   &t_pTrkDCASigXY);
   trV->SetBranchAddress( (prefix+"pTrkDCASigZ").c_str(),    &t_pTrkDCASigZ);
   trV->SetBranchAddress( (prefix+"nTrkQuality").c_str(),    &t_nTrkQuality);
   trV->SetBranchAddress( (prefix+"nTrkNHit").c_str(),       &t_nTrkNHit);
   trV->SetBranchAddress( (prefix+"nTrkPt").c_str(),         &t_nTrkPt);
   trV->SetBranchAddress( (prefix+"nTrkPtError").c_str(),    &t_nTrkPtError);
   trV->SetBranchAddress( (prefix+"nTrkEta").c_str(),        &t_nTrkEta);
   trV->SetBranchAddress( (prefix+"nTrkNPxLayer").c_str(),   &t_nTrkNPxLayer);
   trV->SetBranchAddress( (prefix+"nTrkDCASigXY").c_str(),   &t_nTrkDCASigXY);
   trV->SetBranchAddress( (prefix+"nTrkDCASigZ").c_str(),    &t_nTrkDCASigZ);
   trV->SetBranchAddress( "Cent",                            &t_Cent);


   std::cout << "--- Processing: " << trV->GetEntries() << " events" << std::endl;
   TStopwatch sw;
   sw.Start();
   for (Long64_t ievt=0; ievt<trV->GetEntries();ievt++) {

      if (ievt%1000 == 0) std::cout << "--- ... Processing event: " << ievt << std::endl;

      trV->GetEntry(ievt);

      int n = t_pt->size();
      for ( int i = 0; i < n; i++ ) {

          pt            = (*t_pt)[i];
          rapidity      = (*t_rapidity)[i];
          vtxChi2       = (*t_vtxChi2)[i];
          cosThetaXYZ   = (*t_cosThetaXYZ)[i];
          Lxyz          = (*t_Lxyz)[i];
          vtxDecaySigXYZ= (*t_vtxDecaySigXYZ)[i];
          DCA           = (*t_DCA)[i];
          pTrkNHit      = (*t_pTrkNHit)[i];
          pTrkPt        = (*t_pTrkPt)[i];
          pTrkPtError   = (*t_pTrkPtError)[i];
          pTrkEta       = (*t_pTrkEta)[i];
          pTrkNPxLayer  = (*t_pTrkNPxLayer)[i];
          pTrkDCASigXY  = (*t_pTrkDCASigXY)[i];
          pTrkDCASigZ   = (*t_pTrkDCASigZ)[i];
          nTrkNHit      = (*t_nTrkNHit)[i];
          nTrkPt        = (*t_nTrkPt)[i];
          nTrkPtError   = (*t_nTrkPtError)[i];
          nTrkEta       = (*t_nTrkEta)[i];
          nTrkNPxLayer  = (*t_nTrkNPxLayer)[i];
          nTrkDCASigXY  = (*t_nTrkDCASigXY)[i];
          nTrkDCASigZ   = (*t_nTrkDCASigZ)[i];
          Cent          = (t_Cent);

          mass          = (*t_mass)[i];
          eta           = (*t_eta)[i];
          phi           = (*t_phi)[i];
          pdgId         = (*t_pdgId)[i];

          // Return the MVA outputs and fill into histograms
          if (Use["LD"          ])  histLD        ->Fill( reader->EvaluateMVA( "LD method"           ) );
          if (Use["BDT250_D2"   ])  histBdt250D2  ->Fill( reader->EvaluateMVA( "BDT250_D2 method"    ) );
          if (Use["BDT250_D3"   ])  histBdt250D3  ->Fill( reader->EvaluateMVA( "BDT250_D3 method"    ) );
          if (Use["BDT500_D2"   ])  histBdt500D2  ->Fill( reader->EvaluateMVA( "BDT500_D2 method"    ) );
          if (Use["BDT500_D3"   ])  histBdt500D3  ->Fill( reader->EvaluateMVA( "BDT500_D3 method"    ) );
          if (Use["BDT850_D3"   ])  histBdt850D3  ->Fill( reader->EvaluateMVA( "BDT850_D3 method"    ) );
          if (Use["BDTG1000_D2" ])  histBdtG1000D2->Fill( reader->EvaluateMVA( "BDTG1000_D2 method"  ) );
          if (Use["BDTG250_D2"  ])  histBdtG250D2 ->Fill( reader->EvaluateMVA( "BDTG250_D2 method"   ) );
          if (Use["BDTG250_D3"  ])  histBdtG250D3 ->Fill( reader->EvaluateMVA( "BDTG250_D3 method"   ) );
      }
   }

   // Get elapsed time
   sw.Stop();
   std::cout << "--- End of event loop: "; sw.Print();

   // Write histograms

   TFile *target  = new TFile( "TMVApp.root","RECREATE" );
   if (Use["LD"          ])  histLD        ->Write();
   if (Use["BDT250_D2"   ])  histBdt250D2  ->Write();
   if (Use["BDT250_D3"   ])  histBdt250D3  ->Write();
   if (Use["BDT500_D2"   ])  histBdt500D2  ->Write();
   if (Use["BDT500_D3"   ])  histBdt500D3  ->Write();
   if (Use["BDT850_D3"   ])  histBdt850D3  ->Write();
   if (Use["BDTG1000_D2" ])  histBdtG1000D2->Write();
   if (Use["BDTG250_D2"  ])  histBdtG250D2 ->Write();
   if (Use["BDTG250_D3"  ])  histBdtG250D3 ->Write();
   target->Close();

   std::cout << "--- Created root file: \"TMVApp.root\" containing the MVA output histograms" << std::endl;

   delete reader;

   std::cout << "==> TMVAClassificationApplication is done!" << std::endl << std::endl;
}

int main( int argc, char** argv )
{
   TString methodList;
   for (int i=1; i<argc; i++) {
      TString regMethod(argv[i]);
      if(regMethod=="-b" || regMethod=="--batch") continue;
      if (!methodList.IsNull()) methodList += TString(",");
      methodList += regMethod;
   }
   TMVAClassificationApplication(methodList);
   return 0;
}
