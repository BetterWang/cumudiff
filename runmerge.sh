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
## pPb H
#root -l -b -q "combinedS.C(381, 397, 388)"
#ln -s combinedS_381_397_388.root pPb_H.root
## pPb H reverse
#root -l -b -q "combinedS.C(389, 398, 396)"
#ln -s combinedS_389_398_396.root pPb_H_reverse.root


# pPb H veto10
#root -l -b -q "combinedS.C(416, 433, 425)"
#ln -s combinedS_416_433_425.root pPb_H_veto10.root
## pPb H veto10 reverse
#root -l -b -q "combinedS.C(417, 434, 432)"
#ln -s combinedS_417_434_432.root pPb_H_veto10_reverse.root

#root -l -b -q 'pPb_merge.C("pPb_Ks2.root", "pPb_Ks2_reverse.root", "pPb_Ks2_merged2.root")'
#root -l -b -q 'pPb_merge.C("pPb_Lm2.root", "pPb_Lm2_reverse.root", "pPb_Lm2_merged2.root")'
#
#root -l -b -q 'pPb_merge.C("pPb_Ks2_SB.root", "pPb_Ks2_SB_reverse.root", "pPb_Ks2_SB_merged2.root")'
#root -l -b -q 'pPb_merge.C("pPb_Lm2_SB.root", "pPb_Lm2_SB_reverse.root", "pPb_Lm2_SB_merged2.root")'
#
#root -l -b -q 'pPb_merge.C("pPb_H.root", "pPb_H_reverse.root", "pPb_H_merged2.root")'
#root -l -b -q 'pPb_merge.C("pPb_H_veto10.root", "pPb_H_veto10_reverse.root", "pPb_H_veto10_merged2.root")'

## pPb H veto10 eta18
#root -l -b -q "combinedS.C(435, 433, 425)"
#ln -s combinedS_435_433_425.root pPb_H_veto10eta18.root
## pPb H veto10 eta18 reverse
#root -l -b -q "combinedS.C(436, 434, 432)"
#ln -s combinedS_436_434_432.root pPb_H_veto10eta18_reverse.root
#root -l -b -q 'pPb_merge.C("pPb_H_veto10eta18.root", "pPb_H_veto10eta18_reverse.root", "pPb_H_veto10eta18_merged2.root")'
#

## pPb H veto10 eta24
#root -l -b -q "combinedS.C(438, 433, 425)"
#ln -s combinedS_438_433_425.root pPb_H_veto10eta24.root
## pPb H veto10 eta24 reverse
#root -l -b -q "combinedS.C(439, 434, 432)"
#ln -s combinedS_439_434_432.root pPb_H_veto10eta24_reverse.root
#root -l -b -q 'pPb_merge.C("pPb_H_veto10eta24.root", "pPb_H_veto10eta24_reverse.root", "pPb_H_veto10eta24_merged2.root")'
#
## pPb H eta18
#root -l -b -q "combinedS.C(440, 433, 425)"
#ln -s combinedS_440_433_425.root pPb_H_eta18.root
## pPb H eta18 reverse
#root -l -b -q "combinedS.C(441, 434, 432)"
#ln -s combinedS_441_434_432.root pPb_H_eta18_reverse.root
#root -l -b -q 'pPb_merge.C("pPb_H_eta18.root", "pPb_H_eta18_reverse.root", "pPb_H_eta18_merged2.root")'
#
## pPb H eta24
#root -l -b -q "combinedS.C(442, 433, 425)"
#ln -s combinedS_442_433_425.root pPb_H_eta24.root
## pPb H eta24 reverse
#root -l -b -q "combinedS.C(443, 434, 432)"
#ln -s combinedS_443_434_432.root pPb_H_eta24_reverse.root
#root -l -b -q 'pPb_merge.C("pPb_H_eta24.root", "pPb_H_eta24_reverse.root", "pPb_H_eta24_merged2.root")'
#

## pPb H vetoJet20
#root -l -b -q "combinedS.C(444, 460, 458)"
#ln -s combinedS_444_460_458.root pPb_H_vetoJet20.root
## pPb H vetoJet20 reverse
#root -l -b -q "combinedS.C(445, 461, 459)"
#ln -s combinedS_445_461_459.root pPb_H_vetoJet20_reverse.root
#
#root -l -b -q 'pPb_merge.C("pPb_H_vetoJet20.root", "pPb_H_vetoJet20_reverse.root", "pPb_H_vetoJet20_merged2.root")'
#

## pPb H vetoJet20eta20
#root -l -b -q "combinedS.C(498, 500, 512)"
#ln -s combinedS_498_500_512.root pPb_H_vetoJet20eta20.root
## pPb H vetoJet20eta20 reverse
#root -l -b -q "combinedS.C(499, 501, 513)"
#ln -s combinedS_499_501_513.root pPb_H_vetoJet20eta20_reverse.root
#root -l -b -q 'pPb_merge.C("pPb_H_vetoJet20eta20.root", "pPb_H_vetoJet20eta20_reverse.root", "pPb_H_vetoJet20eta20_merged2.root")'
#
#
## pPb H vetoJet25eta20
#root -l -b -q "combinedS.C(516, 518, 530)"
#ln -s combinedS_516_518_530.root pPb_H_vetoJet25eta20.root
## pPb H vetoJet25eta20 reverse
#root -l -b -q "combinedS.C(517, 519, 531)"
#ln -s combinedS_517_519_531.root pPb_H_vetoJet25eta20_reverse.root
#root -l -b -q 'pPb_merge.C("pPb_H_vetoJet25eta20.root", "pPb_H_vetoJet25eta20_reverse.root", "pPb_H_vetoJet25eta20_merged2.root")'
#
## pPb H vetoJet30eta20
#root -l -b -q "combinedS.C(534, 536, 548)"
#ln -s combinedS_534_536_548.root pPb_H_vetoJet30eta20.root
## pPb H vetoJet30eta20 reverse
#root -l -b -q "combinedS.C(535, 537, 549)"
#ln -s combinedS_535_537_549.root pPb_H_vetoJet30eta20_reverse.root
#root -l -b -q 'pPb_merge.C("pPb_H_vetoJet30eta20.root", "pPb_H_vetoJet30eta20_reverse.root", "pPb_H_vetoJet30eta20_merged2.root")'
#
## pPb H vetoJet20eta16
#root -l -b -q "combinedS.C(552, 554, 566)"
#ln -s combinedS_552_554_566.root pPb_H_vetoJet20eta16.root
## pPb H vetoJet20eta16 reverse
#root -l -b -q "combinedS.C(553, 555, 567)"
#ln -s combinedS_553_555_567.root pPb_H_vetoJet20eta16_reverse.root
#root -l -b -q 'pPb_merge.C("pPb_H_vetoJet20eta16.root", "pPb_H_vetoJet20eta16_reverse.root", "pPb_H_vetoJet20eta16_merged2.root")'
#
## pPb H Jet20eta20
#root -l -b -q "combinedS.C(606, 608, 620)"
#ln -s combinedS_606_608_620.root pPb_H_Jet20eta20.root
## pPb H Jet20eta20 reverse
#root -l -b -q "combinedS.C(607, 609, 621)"
#ln -s combinedS_607_609_621.root pPb_H_Jet20eta20_reverse.root
#root -l -b -q 'pPb_merge.C("pPb_H_Jet20eta20.root", "pPb_H_Jet20eta20_reverse.root", "pPb_H_Jet20eta20_merged2.root")'
#

## pPb H vetoakPu3Jet20eta20
#root -l -b -q "combinedS.C(624, 626, 628)"
#ln -s combinedS_624_626_628.root pPb_H_vetoakPu3Jet20eta20.root
## pPb H vetoakPu3Jet20eta20 reverse
#root -l -b -q "combinedS.C(625, 627, 629)"
#ln -s combinedS_625_627_629.root pPb_H_vetoakPu3Jet20eta20_reverse.root
#root -l -b -q 'pPb_merge.C("pPb_H_vetoakPu3Jet20eta20.root", "pPb_H_vetoakPu3Jet20eta20_reverse.root", "pPb_H_vetoakPu3Jet20eta20_merged2.root")'
#
## pPb H vetoak4Jet20eta20
#root -l -b -q "combinedS.C(630, 632, 634)"
#ln -s combinedS_630_632_634.root pPb_H_vetoak4Jet20eta20.root
## pPb H vetoak4Jet20eta20 reverse
#root -l -b -q "combinedS.C(631, 633, 635)"
#ln -s combinedS_631_633_635.root pPb_H_vetoak4Jet20eta20_reverse.root
#root -l -b -q 'pPb_merge.C("pPb_H_vetoak4Jet20eta20.root", "pPb_H_vetoak4Jet20eta20_reverse.root", "pPb_H_vetoak4Jet20eta20_merged2.root")'

## pPb H vetoakPu4Jet21eta20
#root -l -b -q "combinedS.C(636, 638, 640)"
#ln -s combinedS_636_638_640.root pPb_H_vetoakPu4Jet21eta20.root
## pPb H vetoakPu4Jet21eta20 reverse
#root -l -b -q "combinedS.C(637, 639, 641)"
#ln -s combinedS_637_639_641.root pPb_H_vetoakPu4Jet21eta20_reverse.root
#root -l -b -q 'pPb_merge.C("pPb_H_vetoakPu4Jet21eta20.root", "pPb_H_vetoakPu4Jet21eta20_reverse.root", "pPb_H_vetoakPu4Jet21eta20_merged2.root")'

