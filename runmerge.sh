## merged pPb Ks
#root -l -b -q "combinedS.C(7, 8, 9)"
## merged pPb Lm
#root -l -b -q "combinedS.C(16, 17, 18)"

## pPb Ks
#root -l -b -q "combinedS.C(1, 56, 3)"
## pPb Ks reverse
#root -l -b -q "combinedS.C(4, 57, 6)"
## pPb Lm
#root -l -b -q "combinedS.C(10, 58, 12)"
## pPb Lm reverse
#root -l -b -q "combinedS.C(13, 59, 15)"

# PbPb Ks Cent
#root -l -b -q "combinedS.C(166, 166, 166)"
# PbPb Lm Cent
#root -l -b -q "combinedS.C(167, 167, 167)"



# PbPb Ks SB Cent
#root -l -b -q "combinedS.C(180, 180, 180)"
# PbPb Lm SB Cent
#root -l -b -q "combinedS.C(181, 181, 181)"

# PbPb Lm Cent2
#root -l -b -q "combinedS.C(227, 227, 227)"
# PbPb Lm SB Cent2
#root -l -b -q "combinedS.C(234, 234, 234)"

## pPb Ks2
#root -l -b -q "combinedS.C(216, 217, 218)"
## pPb Lm2
#root -l -b -q "combinedS.C(221, 222, 223)"
#
#
## pPb Ks2 SB
#root -l -b -q "combinedS.C(267, 268, 269)"
## pPb Lm2 SB
#root -l -b -q "combinedS.C(302, 303, 304)"
#


## pPb H
#root -l -b -q "combinedS.C(399, 400, 401)"
#





#
## pPb Ks2
#root -l -b -q "combinedS.C(182, 214, 189)"
#ln -s combinedS_182_214_189.root pPb_Ks2.root
## pPb Ks2 reverse
#root -l -b -q "combinedS.C(190, 215, 197)"
#ln -s combinedS_190_215_197.root pPb_Ks2_reverse.root
#
#
## pPb Lm2
#root -l -b -q "combinedS.C(198, 219, 205)"
#ln -s combinedS_198_219_205.root pPb_Lm2.root
## pPb Lm2 reverse
#root -l -b -q "combinedS.C(206, 220, 213)"
#ln -s combinedS_206_220_213.root pPb_Lm2_reverse.root
#
#
## pPb Ks2
#root -l -b -q "combinedS.C(402, 403, 404)"
#ln -s combinedS_402_403_404.root pPb_Ks2_SB.root
## pPb Ks2 reverse
#root -l -b -q "combinedS.C(405, 406, 407)"
#ln -s combinedS_405_406_407.root pPb_Ks2_SB_reverse.root
#
## pPb Lm2
#root -l -b -q "combinedS.C(408, 409, 410)"
#ln -s combinedS_408_409_410.root pPb_Lm2_SB.root
## pPb Lm2 reverse
#root -l -b -q "combinedS.C(411, 412, 413)"
#ln -s combinedS_411_412_413.root pPb_Lm2_SB_reverse.root
#
#
#
## pPb H
#root -l -b -q "combinedS.C(381, 382, 388)"
#ln -s combinedS_381_382_388.root pPb_H.root
## pPb H reverse
#root -l -b -q "combinedS.C(389, 390, 396)"
#ln -s combinedS_389_390_396.root pPb_H_reverse.root
#

root -l -b -q 'pPb_merge.C("pPb_Ks2.root", "pPb_Ks2_reverse.root", "pPb_Ks2_merged2.root")'
root -l -b -q 'pPb_merge.C("pPb_Lm2.root", "pPb_Lm2_reverse.root", "pPb_Lm2_merged2.root")'

root -l -b -q 'pPb_merge.C("pPb_Ks2_SB.root", "pPb_Ks2_SB_reverse.root", "pPb_Ks2_SB_merged2.root")'
root -l -b -q 'pPb_merge.C("pPb_Lm2_SB.root", "pPb_Lm2_SB_reverse.root", "pPb_Lm2_SB_merged2.root")'

root -l -b -q 'pPb_merge.C("pPb_H.root", "pPb_H_reverse.root", "pPb_H_merged2.root")'

