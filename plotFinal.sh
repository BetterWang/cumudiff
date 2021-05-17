#root -l -b -q 'plotFinalpPb.C(false)'
#root -l -b -q 'plotFinal.C(false, false)'
#root -l -b -q 'plotFinal.C(false, true)'
#
# preliminary
root -l -b -q 'plotFinalpPb.C(true)'
root -l -b -q 'plotFinal.C(true, false)'
root -l -b -q 'plotFinal.C(true, true)'
