
void chkNeg()
{
    TFile * f = new TFile("plotFinalpPb.root");

//    for ( int i = 8; i < 10; i++ ) {
    {
        int i = 8;
        // Ch
        cout << "=================" << endl;
        auto grCh_v22 = (TGraphErrors*) f->Get(Form("grCh_v2sp_Full_NegEtaEP_%i", i));
        for ( int j = 0; j < grCh_v22->GetN(); j++  )
        {
            if ( grCh_v22->GetY()[j] < 0. ) {
                cout << "!! grCh_v22_" << i << " -> " << j << grCh_v22->GetY()[j] << endl;
            }
        }
        cout << "!! i = " << i << " grCh_v22->GetN() =\t" << grCh_v22->GetN() << endl;

        auto grCh_v24 = (TGraphErrors*) f->Get(Form("grCh_v24_%i", i));
        for ( int j = 0; j < grCh_v24->GetN(); j++  )
        {
            if ( grCh_v24->GetY()[j] < 0. ) {
                cout << "!! grCh_v24_" << i << " -> " << j << grCh_v24->GetY()[j] << endl;
            }
        }
        cout << "!! i = " << i << " grCh_v24->GetN() =\t" << grCh_v24->GetN() << endl;

        auto grCh_v24veto = (TGraphErrors*) f->Get(Form("grCh_v24veto_%i", i));
        for ( int j = 0; j < grCh_v24veto->GetN(); j++  )
        {
            if ( grCh_v24veto->GetY()[j] < 0. ) {
                cout << "!! grCh_v24veto_" << i << " -> " << j << grCh_v24veto->GetY()[j] << endl;
            }
        }
        cout << "!! i = " << i << " grCh_v24veto->GetN() =\t" << grCh_v24veto->GetN() << endl;

        auto grCh_v26veto = (TGraphErrors*) f->Get(Form("grCh_v26veto_%i", i));
        for ( int j = 0; j < grCh_v26veto->GetN(); j++  )
        {
            if ( grCh_v26veto->GetY()[j] < 0. ) {
                cout << "!! grCh_v26veto_" << i << " -> " << j << grCh_v26veto->GetY()[j] << endl;
            }
        }
        cout << "!! i = " << i << " grCh_v26veto->GetN() =\t" << grCh_v26veto->GetN() << endl;

        auto grCh_v24sub = (TGraphErrors*) f->Get(Form("grCh_v24sub_%i", i));
        for ( int j = 0; j < grCh_v24sub->GetN(); j++  )
        {
            if ( grCh_v24sub->GetY()[j] < 0. ) {
                cout << "!! grCh_v24sub_" << i << " -> " << j << grCh_v24sub->GetY()[j] << endl;
            }
        }
        cout << "!! i = " << i << " grCh_v24sub->GetN() =\t" << grCh_v24sub->GetN() << endl;

        auto grCh_v24subR = (TGraphErrors*) f->Get(Form("grCh_v24subRatio_%i", i));
        for ( int j = 0; j < grCh_v24subR->GetN(); j++  )
        {
            if ( grCh_v24subR->GetY()[j] < 0. ) {
                cout << "!! grCh_v24subR_" << i << " -> " << j << grCh_v24subR->GetY()[j] << endl;
            }
        }
        cout << "!! i = " << i << " grCh_v24subR->GetN() =\t" << grCh_v24subR->GetN() << endl;

        auto grCh_v26 = (TGraphErrors*) f->Get(Form("grCh_v26_%i", i));
        for ( int j = 0; j < grCh_v26->GetN(); j++  )
        {
            if ( grCh_v26->GetY()[j] < 0. ) {
                cout << "!! grCh_v26_" << i << " -> " << j << grCh_v26->GetY()[j] << endl;
            }
        }
        cout << "!! i = " << i << " grCh_v26->GetN() =\t" << grCh_v26->GetN() << endl;

        auto grChF = (TGraphErrors*) f->Get(Form("grCh_Fluct_%i", i));
        for ( int j = 0; j < grChF->GetN(); j++  )
        {
            if ( grChF->GetY()[j] < 0. ) {
                cout << "!! grChF_" << i << " -> " << j << grChF->GetY()[j] << endl;
            }
        }
        cout << "!! i = " << i << " grChF->GetN() =\t" << grChF->GetN() << endl;
        cout << endl;
        cout << endl;

        // Ks
        auto grKs_v22 = (TGraphErrors*) f->Get(Form("grKs_v2sp_Full_NegEtaEP_%i", i));
        for ( int j = 0; j < grKs_v22->GetN(); j++  )
        {
            if ( grKs_v22->GetY()[j] < 0. ) {
                cout << "!! grKs_v22_" << i << " -> " << j << grKs_v22->GetY()[j] << endl;
            }
        }
        cout << "!! i = " << i << " grKs_v22->GetN() =\t" << grKs_v22->GetN() << endl;

        auto grKs_v24 = (TGraphErrors*) f->Get(Form("grKs_v24_%i", i));
        for ( int j = 0; j < grKs_v24->GetN(); j++  )
        {
            if ( grKs_v24->GetY()[j] < 0. ) {
                cout << "!! grKs_v24_" << i << " -> " << j << grKs_v24->GetY()[j] << endl;
            }
        }
        cout << "!! i = " << i << " grKs_v24->GetN() =\t" << grKs_v24->GetN() << endl;

        auto grKs_v24sub = (TGraphErrors*) f->Get(Form("grKs_v24sub_%i", i));
        for ( int j = 0; j < grKs_v24sub->GetN(); j++  )
        {
            if ( grKs_v24sub->GetY()[j] < 0. ) {
                cout << "!! grKs_v24sub_" << i << " -> " << j << " " << grKs_v24sub->GetY()[j] << endl;
            }
        }
        cout << "!! i = " << i << " grKs_v24sub->GetN() =\t" << grKs_v24sub->GetN() << endl;

        auto grKs_v24subR = (TGraphErrors*) f->Get(Form("grKs_v24subRatio_%i", i));
        for ( int j = 0; j < grKs_v24subR->GetN(); j++  )
        {
            if ( grKs_v24subR->GetY()[j] < 0. ) {
                cout << "!! grKs_v24subR_" << i << " -> " << j << " " << grKs_v24subR->GetY()[j] << endl;
            }
        }
        cout << "!! i = " << i << " grKs_v24subR->GetN() =\t" << grKs_v24subR->GetN() << endl;

        auto grKs_v26 = (TGraphErrors*) f->Get(Form("grKs_v26_%i", i));
        for ( int j = 0; j < grKs_v26->GetN(); j++  )
        {
            if ( grKs_v26->GetY()[j] < 0. ) {
                cout << "!! grKs_v26_" << i << " -> " << j << " " << grKs_v26->GetY()[j] << endl;
            }
        }
        cout << "!! i = " << i << " grKs_v26->GetN() =\t" << grKs_v26->GetN() << endl;

        auto grKsF = (TGraphErrors*) f->Get(Form("grKs_Fluct_%i", i));
        for ( int j = 0; j < grKsF->GetN(); j++  )
        {
            if ( grKsF->GetY()[j] < 0. ) {
                cout << "!! grKsF_" << i << " -> " << j << grKsF->GetY()[j] << endl;
            }
        }
        cout << "!! i = " << i << " grKsF->GetN() =\t" << grKsF->GetN() << endl;
        cout << endl;
        cout << endl;

        // Lm
        auto grLm_v22 = (TGraphErrors*) f->Get(Form("grLm_v2sp_Full_NegEtaEP_%i", i));
        for ( int j = 0; j < grLm_v22->GetN(); j++  )
        {
            if ( grLm_v22->GetY()[j] < 0. ) {
                cout << "!! grLm_v22_" << i << " -> " << j << grLm_v22->GetY()[j] << endl;
            }
        }
        cout << "!! i = " << i << " grLm_v22->GetN() =\t" << grLm_v22->GetN() << endl;

        auto grLm_v24 = (TGraphErrors*) f->Get(Form("grLm_v24_%i", i));
        for ( int j = 0; j < grLm_v24->GetN(); j++  )
        {
            if ( grLm_v24->GetY()[j] < 0. ) {
                cout << "!! grLm_v24_" << i << " -> " << j << grLm_v24->GetY()[j] << endl;
            }
        }
        cout << "!! i = " << i << " grLm_v24->GetN() =\t" << grLm_v24->GetN() << endl;

        auto grLm_v24sub = (TGraphErrors*) f->Get(Form("grLm_v24sub_%i", i));
        for ( int j = 0; j < grLm_v24sub->GetN(); j++  )
        {
            if ( grLm_v24sub->GetY()[j] < 0. ) {
                cout << "!! grLm_v24sub_" << i << " -> " << j << " " << grLm_v24sub->GetY()[j] << endl;
            }
        }
        cout << "!! i = " << i << " grLm_v24sub->GetN() =\t" << grLm_v24sub->GetN() << endl;

        auto grLm_v24subR = (TGraphErrors*) f->Get(Form("grLm_v24subRatio_%i", i));
        for ( int j = 0; j < grLm_v24subR->GetN(); j++  )
        {
            if ( grLm_v24subR->GetY()[j] < 0. ) {
                cout << "!! grLm_v24subR_" << i << " -> " << j << " " << grLm_v24subR->GetY()[j] << endl;
            }
        }
        cout << "!! i = " << i << " grLm_v24subR->GetN() =\t" << grLm_v24subR->GetN() << endl;

        auto grLm_v26 = (TGraphErrors*) f->Get(Form("grLm_v26_%i", i));
        for ( int j = 0; j < grLm_v26->GetN(); j++  )
        {
            if ( grLm_v26->GetY()[j] < 0. ) {
                cout << "!! grLm_v26_" << i << " -> " << j << " " << grLm_v26->GetY()[j] << endl;
            }
        }
        cout << "!! i = " << i << " grLm_v26->GetN() =\t" << grLm_v26->GetN() << endl;

        auto grLmF = (TGraphErrors*) f->Get(Form("grLm_Fluct_%i", i));
        for ( int j = 0; j < grLmF->GetN(); j++  )
        {
            if ( grLmF->GetY()[j] < 0. ) {
                cout << "!! grLmF_" << i << " -> " << j << grLmF->GetY()[j] << endl;
            }
        }
        cout << "!! i = " << i << " grLmF->GetN() =\t" << grLmF->GetN() << endl;
        cout << endl;
        cout << endl;
    }

}
