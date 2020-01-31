

1) filter_mass3.C  BDT score tree
2) genMassHist3.C  mass histo as a func of bdt
3) massFit3.C      mass fit / find optimized bdt cut
4) APplot.C        use bdt cut to get mass hist and AP
5) APLM.C APKS.C   generate AP plot from 4)
6) MVAmass.C       generate mass histogram from 4)
7) MVAmassFit.C    do mass fit from 6)


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

