# Lm SB
./runGet1.sh 144
# Ks SB
./runGet1.sh 148


# Lm Peak
./runFix1.sh 141 144

# Ks Peak
./runFix1.sh 145 148


## PbPb Lm
root -l -b -q "combinedS.C(141)"
#ln -s combinedS_141.root PbPb2018_Lm.root
root -l -b -q 'vnFsigPbPb.C("PbPb2018_Lm.root", "dummy.root", "PbPb2018_Lm_corrected_fix.root")'

## PbPb Ks
root -l -b -q "combinedS.C(145)"
#ln -s combinedS_145.root PbPb2018_Ks.root
root -l -b -q 'vnFsigPbPb.C("PbPb2018_Ks.root", "dummy.root", "PbPb2018_Ks_corrected_fix.root")'





#
## Lm Peak
#./runGet1.sh 141
## Lm SB
#./runGet1.sh 144
## Ks Peak
#./runGet1.sh 145
## Ks SB
#./runGet1.sh 148
#
## PbPb Lm
#root -l -b -q "combinedS.C(141)"
## PbPb Ks
#root -l -b -q "combinedS.C(145)"
#
#root -l -b -q 'vnFsigPbPb.C("PbPb2018_Lm.root", "PbPb2018_Lm_SB.root", "PbPb2018_Lm_corrected.root")'
#root -l -b -q 'vnFsigPbPb.C("PbPb2018_Ks.root", "PbPb2018_Ks_SB.root", "PbPb2018_Ks_corrected.root")'
