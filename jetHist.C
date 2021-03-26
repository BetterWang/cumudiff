#include "TH1.h"
#include "TH2.h"
#include "TFile.h"
#include "TChain.h"
#include "TMath.h"
#include <iostream>

void jetHist(string s1 = "", string fout = "test.root", int Noff1 =185, int Noff2 = 250)
{
    TChain * ch = new TChain("trV");

    ch->Add(s1.c_str());

    vector<double>  *pt = nullptr;
    vector<double>  *phi = nullptr;
    vector<double>  *eta = nullptr;
    Double_t        Noff = -1;

    ch->SetMakeClass(1);
    ch->SetBranchAddress("pt", &pt);
    ch->SetBranchAddress("phi", &phi);
    ch->SetBranchAddress("eta", &eta);
    ch->SetBranchAddress("Noff", &Noff);

    TH1D * hJetPt  = new TH1D("hJetPt", "hJetPt;p_{T,jet}", 100, 0, 100);
    TH1D * hJetEta = new TH1D("hJetEta", "hJetEta;#eta_{jet}", 50, -2.5, 2.5);
    TH1D * hJetPhi = new TH1D("hJetPhi", "hJetPhi;#phi_{jet}", 50, -TMath::Pi(), TMath::Pi());
    TH2D * hJetEtaPhi = new TH2D("hJetEtaPhi", "hJetEtaPhi;#eta_{jet};#phi_{jet}", 50, -2.5, 2.5, 50, -TMath::Pi(), TMath::Pi());
    TH1D * hNoff = new TH1D("hNoff", "hNoff;Noff", 600, 0, 600);
    TH1D * hNJet = new TH1D("hNJet", "hNJet;NJet", 100, 0, 100);
    TH2D * hJetPtEta = new TH2D("hJetPtEta", "hJetPtEta;p_{T,jet};#eta_{jet}", 100, 0, 100, 50, -2.5, 2.5);

    unsigned int ievt = 0;
    while (ch->GetEvent(ievt++)) {
        if ( (ievt%10000)==0 ) {
            std::cout << " --> processing event " << ievt << std::endl;
        }
        if ( int(Noff)<Noff1 or int(Noff)>=250 ) {
            continue;
        }
        if ( pt->size() == 0 ) continue;
        hNoff->Fill(Noff);
        hNJet->Fill(pt->size());
        for ( unsigned int j = 0; j < pt->size(); j++ ) {
            hJetPt->Fill( (*pt)[j] );
            hJetEta->Fill( (*eta)[j] );
            hJetPhi->Fill( (*phi)[j] );
            hJetEtaPhi->Fill( (*eta)[j], (*phi)[j] );
            hJetPtEta->Fill( (*pt)[j], (*eta)[j] );
        }
    }

    TFile * fsave = new TFile(fout.c_str(), "recreate");
    hJetPt->Write();
    hJetEta->Write();
    hJetPhi->Write();
    hJetEtaPhi->Write();
    hJetPtEta->Write();
    hNoff->Write();
    hNJet->Write();
}
