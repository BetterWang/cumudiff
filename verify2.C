#include "label.h"

void verify2(int s1 = 1, int c1 = 2){
//	int s1 = 1;
	int s3 = 10;

    cout << ftxt[s1] << endl;
	TFile *f;
	TFile *c;
    int Nevt1[11] = {};
    int Nevt2[11] = {};
    for ( int s2 = 0; s2 <= s3; s2++ ) {
        f = new TFile(Form("%s/output_%i_%i.root", ftxt[s1], s2, s3));

        TH1D * h;
        if (!f->IsZombie()) {
            h = (TH1D*) f->Get("hNoff");
            Nevt1[s2] = h->GetEntries();
            //cout << " s1 = " << s1 << "\ts2 = " << s2 << "\tNevt = " << Nevt1[s2];
            if ( Nevt1[s2]==0 ) cout << "\t!!!Empty!!!" << endl;
            //else cout << endl;
        } else {
            //cout << " s1 = " << s1 << "\ts2 = " << s2 << "\tNot exist!!!" << endl;
        }
    }

    cout << ftxt[c1] << endl;
    for ( int s2 = 0; s2 <= s3; s2++ ) {
        c = new TFile(Form("%s/output_%i_%i.root", ftxt[c1], s2, s3));

        TH1D * h;
        if (!f->IsZombie()) {
            h = (TH1D*) c->Get("hNoff");
            Nevt2[s2] = h->GetEntries();
            //cout << " c1 = " << c1 << "\ts2 = " << s2 << "\tNevt = " << Nevt2[s2];
            if ( Nevt2[s2]==0 ) cout << "\t!!!Empty!!!" << endl;
            //else cout << endl;
        } else {
            //cout << " c1 = " << c1 << "\ts2 = " << s2 << "\tNot exist!!!" << endl;
        }
    }

    cout << " ==> combined" << endl;
    for ( int s2 = 0; s2 <= s3; s2++ ) {
        //cout << " s1 = " << s1 << "\tc1 = " << c1 << "\ts2 = " << s2 << "\tNevt1 = " << Nevt1[s2] << "\tNevt2 = " << Nevt2[s2] << "\tsum = " << Nevt1[s2]+Nevt2[s2] << endl;
        cout << "s2 = " << s2 << "  \tNevt1 = " << Nevt1[s2] << "  \tNevt2 = " << Nevt2[s2] << "  \tsum = " << Nevt1[s2]+Nevt2[s2] << endl;
    }
}
