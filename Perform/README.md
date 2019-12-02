

1) filter_mass3.C  BDT score tree
2) genMassHist3.C  mass histo as a func of bdt
3) massFit3.C      mass fit / find optimized bdt cut
4) APplot.C        use bdt cut to get mass hist and AP
5) APLM.C APKS.C   generate AP plot from 4)
6) MVAmass.C       generate mass plot from 4)


MC Eff
1) run QWV0Skim/qw_HydjetDrum5F_V0_eff_MVA_v2.py
2) hadd
3) makeEff3_cent.C
4) effPlotLm3_cent.C effPlotKs3_cent.C

