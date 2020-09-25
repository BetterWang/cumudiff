

1) filter_mass3.C               BDT score tree
2) genMassHist3.C               mass histo as a func of bdt
3) massFit3.C,                  mass fit / find optimized bdt cut
4) APplot.C                     use bdt cut to get mass hist and AP
5) APLM.C APKS.C                generate AP plot from 4)
6) MVAmass.C                    generate mass histogram from 4)
7) MVAmassFit.C                 do mass fit from 6)
8) getFsig.C                    get Fsig from 7)


MC Eff
1) run QWV0Skim/qw_HydjetDrum5F_V0_eff_MVA_v2.py
2) hadd
3) makeEff3_cent.C
4) effPlotLm3_cent.C effPlotKs3_cent.C


MVA validation
1) MCMVA_VarHist.C      get MC var distribution
2) DataMVA_VarHist.C    get data var distribution
3) varHist.C            plot/compare 1) and 2)
4) reweightMVA.C        get reweight factor from 1) and 2) ([p][n]TrkDCASig[XY][Z])
5) MCsignificance.C     get S/sqrt(S+B) with reweight
6) plotMCsignificance.C plot S/sqrt(S+B) vs BDT cut
7) plotSig.C            plot S/B for TMVA3 vs TMVA8 and reweighting, plot significance


- Hydjet dataset,   501271 events,  0-80% 400058  events, 0-70% 351280  events.
- HIMB19 WrongSign, 5855529 events, 0-80% 4846890 events, 0-70% 4219953 events.
- HIMB19 WrongSign, 0-80% 400058/4846890=0.0825, 0-70% 351280/4219953 = 0.0832
- HIMB19 WrongSign `cumu_1*.root`, 1481434 events, 0-80% 1223986 events, 0-70% 1065043 events.
- HIMB19 WrongSign, 0-80% 1223986/4846890=0.2525, 0-70% 1065043/4219953 = 0.2524
- HIMB4 v9 `cumu_90*.root`, 1181092 events, 0-80% 979090 events, 0-70% 851993.
- HIMB4 v9, 0-80% 400058/979090 = 0.409, 0-70% 351280/851993 = 0.4123
- HIMB19 SameSign (|vz|<15.), 5841434
- HIMB19 WrongSign (|vz|15),  5841434 events, 0-80% 4835223 events, 0-70% 4209781 events.



