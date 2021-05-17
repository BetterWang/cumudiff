if [ "$1" == "" ]; then
    echo "cp to /Users/qwang/github/tdr/HIN-19-004/figures/"
    #Fig 1.
    cp PbPbV2_Ch.pdf                    /Users/qwang/github/tdr/HIN-19-004/figures/
    cp PbPbV2_Ks.pdf                    /Users/qwang/github/tdr/HIN-19-004/figures/
    cp PbPbV2_Lm.pdf                    /Users/qwang/github/tdr/HIN-19-004/figures/
    
    #Fig 2.
    cp pPbV2_Ch.pdf                     /Users/qwang/github/tdr/HIN-19-004/figures/
    cp pPbV2_Ks.pdf                     /Users/qwang/github/tdr/HIN-19-004/figures/
    cp pPbV2_Lm.pdf                     /Users/qwang/github/tdr/HIN-19-004/figures/
    
    #Fig 3.
    cp pPbV2_Ch_veto.pdf                /Users/qwang/github/tdr/HIN-19-004/figures/
    cp pPbV2_Ch_vetoRatio.pdf           /Users/qwang/github/tdr/HIN-19-004/figures/
    
    #Fig 4.
    cp PbPbV2_Subevt_Ch.pdf             /Users/qwang/github/tdr/HIN-19-004/figures/
    cp PbPbV2_Subevt_Ks.pdf             /Users/qwang/github/tdr/HIN-19-004/figures/
    cp PbPbV2_Subevt_Lm.pdf             /Users/qwang/github/tdr/HIN-19-004/figures/
    
    #Fig 5.
    cp pPbV2_Subevt_Ch.pdf              /Users/qwang/github/tdr/HIN-19-004/figures/
    
    #Fig 6.
    cp PbPbV2_SubevtCu_Ratio.pdf        /Users/qwang/github/tdr/HIN-19-004/figures/
    cp pPbV2_Ratio_Ch.pdf               /Users/qwang/github/tdr/HIN-19-004/figures/
    
    #Fig 7.
    cp PbPbV2_Fluct_Ch.pdf              /Users/qwang/github/tdr/HIN-19-004/figures/
    cp PbPbV2_Fluct_Ks.pdf              /Users/qwang/github/tdr/HIN-19-004/figures/
    cp PbPbV2_Fluct_Lm.pdf              /Users/qwang/github/tdr/HIN-19-004/figures/
    
    #Fig 8.
    cp pPbV2_FluctCh6.pdf               /Users/qwang/github/tdr/HIN-19-004/figures/
    
    #Fig 9.
    cp PbPbV2_V64_ratio.pdf             /Users/qwang/github/tdr/HIN-19-004/figures/
    cp PbPbV2_V84_ratio.pdf             /Users/qwang/github/tdr/HIN-19-004/figures/
    
    #cp pPbV2_Subevt_Ks.pdf              /Users/qwang/github/tdr/HIN-19-004/figures/
    #cp pPbV2_Subevt_Lm.pdf              /Users/qwang/github/tdr/HIN-19-004/figures/
    #cp PbPbV2_Ch42.pdf                  /Users/qwang/github/tdr/HIN-19-004/figures/
    #cp PbPbV2_Ks42.pdf                  /Users/qwang/github/tdr/HIN-19-004/figures/
    #cp PbPbV2_Lm42.pdf                  /Users/qwang/github/tdr/HIN-19-004/figures/
    cp PbPbV2_Ch_Trento.pdf             /Users/qwang/github/tdr/HIN-19-004/figures/
    cp PbPbV2_Ks_Trento.pdf             /Users/qwang/github/tdr/HIN-19-004/figures/
    cp PbPbV2_Lm_Trento.pdf             /Users/qwang/github/tdr/HIN-19-004/figures/
    
    cp pPbV2_Ch_vetoDelta.pdf           /Users/qwang/github/tdr/HIN-19-004/figures/
    cp pPbV2_Delta_Ch.pdf               /Users/qwang/github/tdr/HIN-19-004/figures/
    cp PbPbV2_SubevtCu_Delta.pdf        /Users/qwang/github/tdr/HIN-19-004/figures/
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
