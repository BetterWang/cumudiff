

1.1) filter_mass3.C,      BDT score tree, filterLM3.sh filterKS3.sh, HIMinimumBias4/crab_HIMB4_V0Tree_v9, HIMinimumBias19/crab_HIMB19_WrongSignV0Tree_v5
1.2) genMassHist3.C,      mass histo as a func of bdt, `genmass*.sh`, input from 1) output
1.3) massFit3.C,          mass fit / find optimized bdt cut, massFit.sh, massFitKS3.sh
1.4) APplot.C             use bdt cut to get mass hist and AP, filterLMAP20_D4.sh filterKSAP_D4.sh
1.5) APLM.C APKS.C        generate AP plot from 4)
1.6) MVAmass.C            generate mass histogram from 4)
1.7) MVAmassFit.C         do mass fit from 6)
1.8) getFsig.C            get Fsig from 7)


MC Eff
2.1) run QWV0Skim/qw_HydjetDrum5F_V0_eff_MVA_v2.py
2.2) hadd
2.3) makeEff3_cent.C
2.4) effPlotLm3_cent.C effPlotKs3_cent.C


MVA validation
3.1) MCMVA_VarHist.C                                    get MC var distribution
3.2) DataMVA_VarHist.C                                  get data var distribution
3.3) varHist.C                                          plot/compare 1) and 2)
3.4) reweightMVA.C                                      get reweight factor from 1) and 2) ([p][n]TrkDCASig[XY][Z])
3.5) MCsignificanceT.C                                  get Signal and Background vs mass for each BDT cut, from TMVA trainging tree
3.6) plotMCsignificanceT.C,                             get Signal and Background vs BDT cut, from 3.5)
3.7) plotDATAsignificanceT.C                            plot S/sqrt(S+B) vs BDT cut, from 3.6) for MC sig eff and 1.2) for WS background eff
3.8) plotSig.C                                          plot S/B for TMVA3 vs TMVA8 and reweighting, plot significance


- Hydjet dataset,   501271 events,  0-80% 400058  events, 0-70% 351280  events.
- HIMB19 WrongSign, 5855529 events, 0-80% 4846890 events, 0-70% 4219953 events.
- HIMB19 WrongSign, 0-80% 400058/4846890=0.0825, 0-70% 351280/4219953 = 0.0832
- HIMB19 WrongSign `cumu_1*.root`, 1481434 events, 0-80% 1223986 events, 0-70% 1065043 events.
- HIMB19 WrongSign, 0-80% 1223986/4846890=0.2525, 0-70% 1065043/4219953 = 0.2524 (USED)
- HIMB4 v9 `cumu_90*.root`, 1181092 events, 0-80% 979090 events, 0-70% 851993.
- HIMB4 v9, 0-80% 400058/979090 = 0.409, 0-70% 351280/851993 = 0.4123
- HIMB19 SameSign (|vz|<15.), 5841434
- HIMB19 WrongSign (|vz|15),  5841434 events, 0-80% 4835223 events, 0-70% 4209781 events.


To optimze BDT cut
1.1) filter
1.2) mass histo vs bdt
1.3) fit 1.2)
3.7) plotDATAsignificanceT.C

