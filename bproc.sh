#!/bin/bash
echo $PWD
echo $1
source /afs/cern.ch/project/eos/installation/cms/etc/setup.sh
cd /afs/cern.ch/user/q/qwang/work/cleanroomRun2/Ana/CMSSW_8_0_24/src/QWAna/QWCumuDiff/bin
eval `scramv1 runtime -sh`

root -n -l -b <<EOF
.x process.C+($1, $2, $3)
.q
EOF

