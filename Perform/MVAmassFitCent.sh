root -l -b MVAmassFitCent.C <<EOF
doFit(1, 4)
doSave()
doFit(1, 5)
doSave()
doFit(1, 6)
doSave()
doFit(1, 7)
doSave()
doFit(1, 8)
doSave()
doFit(1, 9)
doSave()
doFit(1, 10)
doSave()
doFit(1, 11)
doSave()
doFit(1, 12)
doSave()
.q
EOF

root -l -b MVAmassFitCent.C <<EOF
doFit(2, 4)
doSave()
doFit(2, 5)
doSave()
doFit(2, 6)
doSave()
doFit(2, 7)
doSave()
doFit(2, 8)
doSave()
doFit(2, 9)
doSave()
doFit(2, 10)
doSave()
doFit(2, 11)
doSave()
doFit(2, 12)
doSave()
.q
EOF

root -l -b MVAmassFitCent.C <<EOF
doFit(3, 4)
doSave()
doFit(3, 5)
doSave()
doFit(3, 6)
doSave()
doFit(3, 7)
doSave()
doFit(3, 8)
doSave()
doFit(3, 9)
doSave()
doFit(3, 10)
doSave()
doFit(3, 11)
doSave()
doFit(3, 12)
doSave()
.q
EOF

root -l -b MVAmassFitCent.C <<EOF
doFit(4, 4)
doSave()
doFit(4, 5)
doSave()
doFit(4, 6)
doSave()
doFit(4, 7)
doSave()
doFit(4, 8)
doSave()
doFit(4, 9)
doSave()
doFit(4, 10)
doSave()
doFit(4, 11)
doSave()
doFit(4, 12)
doSave()
.q
EOF

root -l -b -q 'getFsigCent.C("LM")'