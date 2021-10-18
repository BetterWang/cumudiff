#root -n -l -b -q 'perform2018.C("../txt/PbPb2018MB1_t.root", "PbPb 5.02 TeV", -2.4, 2.4, "vectLmMassN50", 6)'

#
#root -l -b -q 'massPlot.C("../txt/PbPb2018MB1_t.root", "vectLmMassN0")'
#root -l -b -q 'massPlot.C("../txt/PbPb2018MB1_t.root", "vectLmMassN10")'
#root -l -b -q 'massPlot.C("../txt/PbPb2018MB1_t.root", "vectLmMassN30")'
#root -l -b -q 'massPlot.C("../txt/PbPb2018MB1_t.root", "vectLmMassN50")'
#
#root -l -b -q 'massPlot.C("../txt/PbPb2018MB1_t.root", "vectKsMassN0")'
#root -l -b -q 'massPlot.C("../txt/PbPb2018MB1_t.root", "vectKsMassN10")'
#root -l -b -q 'massPlot.C("../txt/PbPb2018MB1_t.root", "vectKsMassN30")'
#root -l -b -q 'massPlot.C("../txt/PbPb2018MB1_t.root", "vectKsMassN50")'


root -l -b -q 'massPlot.C("../txt/PbPb2018MB1_t.root", "vectLmMassN0", -1., 1.)'
root -l -b -q 'massPlot.C("../txt/PbPb2018MB1_t.root", "vectLmMassN10", -1., 1.)'
root -l -b -q 'massPlot.C("../txt/PbPb2018MB1_t.root", "vectLmMassN30", -1., 1.)'
root -l -b -q 'massPlot.C("../txt/PbPb2018MB1_t.root", "vectLmMassN50", -1., 1.)'

root -l -b -q 'massPlot.C("../txt/PbPb2018MB1_t.root", "vectKsMassN0", -1., 1.)'
root -l -b -q 'massPlot.C("../txt/PbPb2018MB1_t.root", "vectKsMassN10", -1., 1.)'
root -l -b -q 'massPlot.C("../txt/PbPb2018MB1_t.root", "vectKsMassN30", -1., 1.)'
root -l -b -q 'massPlot.C("../txt/PbPb2018MB1_t.root", "vectKsMassN50", -1., 1.)'
