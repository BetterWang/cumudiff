#root -l -b MVAmassFit.C <<EOF
#full_range.first = 1.095
#full_range.second = 1.135
#doFit(0, 6)
#doSave()
#.q
#EOF
#
#root -l -b MVAmassFit.C <<EOF
#full_range.first = 1.1
#full_range.second = 1.135
#doFit(1, 6)
#doSave()
#.q
#EOF
#

root -l -b MVAmassFit.C <<EOF
full_range.first = 1.1
full_range.second = 1.135
doFit(1, 6, "Mid", 8)
doSave()
.q
EOF
