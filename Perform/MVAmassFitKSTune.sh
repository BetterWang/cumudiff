#root -l -b 'MVAmassFit.C("KS")' <<EOF
#doFit(0, 6, "Mid", 5)
#doSave()
#.q
#EOF
#
#root -l -b 'MVAmassFit.C("KS")' <<EOF
#doFit(1, 4, "Mid", 5)
#doSave()
#.q
#EOF
#
#root -l -b 'MVAmassFit.C("KS")' <<EOF
#doFit(1, 5, "Mid", 5)
#doSave()
#.q
#EOF
#
#root -l -b 'MVAmassFit.C("KS")' <<EOF
#doFit(3, 6, "Mid", 5)
#doSave()
#.q
#EOF
