#include "Steve_SP.h"

TGraphErrors* dummy = new TGraphErrors(13);


void vnFsigSP_veto(string strSave = "test.root", double sys = 0.0 )
{
    for ( int i = 0; i < 13; i++ ) {
        dummy->GetX()[i] = 0.;
        dummy->GetY()[i] = 0.;
        dummy->GetEY()[i] = 99.;
    }

    LoadSP_veto();

    TFile * fsave = new TFile(strSave.c_str(), "recreate");

    for ( int c = 6; c < 10; c++ ) {
        TDirectory * d = fsave->mkdir( (string("ch_pPb_corrected_") + to_string(c)).c_str() );
        ch_pPb_merge[c]->Write(d);
    }

}


