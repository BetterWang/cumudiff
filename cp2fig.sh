if [ "$1" == "" ]; then
    echo "cp to /Users/qwang/github/tdr/HIN-19-004/"
    #Fig 1.
    cp Perform/KSmass.pdf               /Users/qwang/github/tdr/HIN-19-004/Figure_001-a.pdf
    cp Perform/LMmass.pdf               /Users/qwang/github/tdr/HIN-19-004/Figure_001-b.pdf
    #Fig 2.
    cp PbPbV2_Ch.pdf                    /Users/qwang/github/tdr/HIN-19-004/Figure_002-a.pdf
    cp PbPbV2_Ks.pdf                    /Users/qwang/github/tdr/HIN-19-004/Figure_002-b.pdf
    cp PbPbV2_Lm.pdf                    /Users/qwang/github/tdr/HIN-19-004/Figure_002-c.pdf
    #Fig 3.
    cp pPbV2_Ch.pdf                     /Users/qwang/github/tdr/HIN-19-004/Figure_003-a.pdf
    cp pPbV2_Ks.pdf                     /Users/qwang/github/tdr/HIN-19-004/Figure_003-b.pdf
    cp pPbV2_Lm.pdf                     /Users/qwang/github/tdr/HIN-19-004/Figure_003-c.pdf
    #Fig 4.
    cp pPbV2_Ch_veto.pdf                /Users/qwang/github/tdr/HIN-19-004/Figure_004-a.pdf
    cp pPbV2_Ch_vetoRatio.pdf           /Users/qwang/github/tdr/HIN-19-004/Figure_004-b.pdf
    #Fig 5.
    cp PbPbV2_Subevt_Ch.pdf             /Users/qwang/github/tdr/HIN-19-004/Figure_005-a.pdf
    cp PbPbV2_Subevt_Ks.pdf             /Users/qwang/github/tdr/HIN-19-004/Figure_005-b.pdf
    cp PbPbV2_Subevt_Lm.pdf             /Users/qwang/github/tdr/HIN-19-004/Figure_005-c.pdf
    #Fig 6.
    cp pPbV2_Subevt_Ch.pdf              /Users/qwang/github/tdr/HIN-19-004/Figure_006.pdf
    #Fig 7.
    cp PbPbV2_SubevtCu_Ratio.pdf        /Users/qwang/github/tdr/HIN-19-004/Figure_007-a.pdf
    cp pPbV2_Ratio_Ch.pdf               /Users/qwang/github/tdr/HIN-19-004/Figure_007-b.pdf
    #Fig 8.
    cp PbPbV2_Fluct_Ch.pdf              /Users/qwang/github/tdr/HIN-19-004/Figure_008-a.pdf
    cp PbPbV2_Fluct_Ks.pdf              /Users/qwang/github/tdr/HIN-19-004/Figure_008-b.pdf
    cp PbPbV2_Fluct_Lm.pdf              /Users/qwang/github/tdr/HIN-19-004/Figure_008-c.pdf
    #Fig 9.
    cp pPbV2_FluctCh6.pdf               /Users/qwang/github/tdr/HIN-19-004/Figure_009.pdf
    #Fig 10.
    cp PbPbV2_V64_ratio.pdf             /Users/qwang/github/tdr/HIN-19-004/Figure_010-a.pdf
    cp PbPbV2_V84_ratio.pdf             /Users/qwang/github/tdr/HIN-19-004/Figure_010-b.pdf
    #aux
    cp PbPbV2_Ch_Trento.pdf             /Users/qwang/github/tdr/HIN-19-004/Figure_addional_001.pdf
    cp PbPbV2_Ks_Trento.pdf             /Users/qwang/github/tdr/HIN-19-004/Figure_addional_002.pdf
    cp PbPbV2_Lm_Trento.pdf             /Users/qwang/github/tdr/HIN-19-004/Figure_addional_003.pdf
    cp pPbV2_Ch_vetoDelta.pdf           /Users/qwang/github/tdr/HIN-19-004/Figure_addional_004.pdf
    cp pPbV2_Delta_Ch.pdf               /Users/qwang/github/tdr/HIN-19-004/Figure_addional_005.pdf
    cp PbPbV2_SubevtCu_Delta.pdf        /Users/qwang/github/tdr/HIN-19-004/Figure_addional_006.pdf
    exit 0;
elif [ $1 == "pre" ]; then
    echo "cp to /preliminary"
    #Fig 1.
    cp PbPbV2_Ch.pdf                    preliminary/
    cp PbPbV2_Ks.pdf                    preliminary/
    cp PbPbV2_Lm.pdf                    preliminary/
    
    #Fig 2.
    cp pPbV2_Ch.pdf                     preliminary/
    cp pPbV2_Ks.pdf                     preliminary/
    cp pPbV2_Lm.pdf                     preliminary/
    
    #Fig 3.
    cp pPbV2_Ch_veto.pdf                preliminary/
    cp pPbV2_Ch_vetoRatio.pdf           preliminary/
    
    #Fig 4.
    cp PbPbV2_Subevt_Ch.pdf             preliminary/
    cp PbPbV2_Subevt_Ks.pdf             preliminary/
    cp PbPbV2_Subevt_Lm.pdf             preliminary/
    
    #Fig 5.
    cp pPbV2_Subevt_Ch.pdf              preliminary/
    
    #Fig 6.
    cp PbPbV2_SubevtCu_Ratio.pdf        preliminary/
    cp pPbV2_Ratio_Ch.pdf               preliminary/
    
    #Fig 7.
    cp PbPbV2_Fluct_Ch.pdf              preliminary/
    cp PbPbV2_Fluct_Ks.pdf              preliminary/
    cp PbPbV2_Fluct_Lm.pdf              preliminary/
    
    #Fig 8.
    cp pPbV2_FluctCh6.pdf               preliminary/
    
    #Fig 9.
    cp PbPbV2_V64_ratio.pdf             preliminary/
    cp PbPbV2_V84_ratio.pdf             preliminary/
    
    cp PbPbV2_Ch_Trento.pdf             preliminary/
    cp PbPbV2_Ks_Trento.pdf             preliminary/
    cp PbPbV2_Lm_Trento.pdf             preliminary/
    
    cp pPbV2_Ch_vetoDelta.pdf           preliminary/
    cp pPbV2_Delta_Ch.pdf               preliminary/
    cp PbPbV2_SubevtCu_Delta.pdf        preliminary/
    exit 0;
fi
