#
#
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_1;PbPb2018_Lm_corrected.root:grSig_pT2_2_1;PbPb2018_Lm_corrected.root:grSig_pT2_3_1;PbPb2018_Lm_corrected.root:grSig_V2sub4_1", "v_{2}^{Sig}{4};v_{2}^{Sig}{6};v_{2}^{Sig}{8};v_{2}^{Sig}{4, 2sub}", "#splitline{PbPb 5.02 TeV}{#Lambda 10-30\%}", "Lm_v2")'
#
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT3_1_1;PbPb2018_Lm_corrected.root:grSig_pT3_2_1;PbPb2018_Lm_corrected.root:grSig_pT3_3_1", "v_{2}^{Sig}{4};v_{2}^{Sig}{6};v_{2}^{Sig}{8}", "#splitline{PbPb 5.02 TeV}{#Lambda 10-30\%}", "Lm_v3")'
#
#
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_1;PbPb2018_Ks_corrected.root:grSig_pT2_2_1;PbPb2018_Ks_corrected.root:grSig_pT2_3_1;PbPb2018_Ks_corrected.root:grSig_V2sub4_1", "v_{2}^{Sig}{4};v_{2}^{Sig}{6};v_{2}^{Sig}{8};v_{2}^{Sig}{4, 2sub}", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 10-30\%}", "Ks_v2")'
#
#
#root -l -b -q 'plotS.C("PbPb2018_H_corrected.root:grSig_pT2_1_1;PbPb2018_H_corrected.root:grSig_pT2_2_1;PbPb2018_H_corrected.root:grSig_pT2_3_1;PbPb2018_H_corrected.root:grSig_V2sub4_1", "v_{2}^{Sig}{4};v_{2}^{Sig}{6};v_{2}^{Sig}{8};v_{2}^{Sig}{4, 2sub}", "#splitline{PbPb 5.02 TeV}{ch 10-30\%}", "H_v2")'
#
#
#
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_V2sub4_1;PbPb2018_Ks_corrected.root:grSig_V2sub4merge_1", "v_{2}^{Sig}{4, 2sub};v_{2}^{Sig}{4, 2sub} merge", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 10-30\%}", "test")'


#root -l -b -q 'plotS.C("PbPb2018_Lm.root:grV021_1;PbPb2018_Lm_sysVz1.root:grV021_1;PbPb2018_Lm_sysVz2.root:grV021_1", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} |vz|<3.;v_{2}^{Sig}{4} |vz|>3.", "#splitline{PbPb 5.02 TeV}{#Lambda 10-30\%}", "Lm_v24_sysVz")'

#root -l -b -q 'plotS.C("PbPb2018_Lm_MB2_corrected.root:grSig_pT2_1_1;PbPb2018_Lm_MB2_sysVz1_corrected.root:grSig_pT2_1_1;PbPb2018_Lm_MB2_sysVz2_corrected.root:grSig_pT2_1_1", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} |vz|<3.;v_{2}^{Sig}{4} |vz|>3.", "#splitline{PbPb 5.02 TeV}{#Lambda 10-30\%}", "Lm_MB2_v24_sysVz")'
#root -l -b -q 'plotS.C("PbPb2018_Lm_MB19_corrected.root:grSig_pT2_1_1;PbPb2018_Lm_MB19_sysVz1_corrected.root:grSig_pT2_1_1;PbPb2018_Lm_MB19_sysVz2_corrected.root:grSig_pT2_1_1", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} |vz|<3.;v_{2}^{Sig}{4} |vz|>3.", "#splitline{PbPb 5.02 TeV}{#Lambda 10-30\%}", "Lm_MB19_v24_sysVz")'

#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_1;PbPb2018_Lm_MB2_corrected.root:grSig_pT2_1_1;PbPb2018_Lm_MB19_corrected.root:grSig_pT2_1_1", "v_{2}^{Sig}{4} 2+19;v_{2}^{Sig}{4} 2;v_{2}^{Sig}{4} 19", "#splitline{PbPb 5.02 TeV}{#Lambda 10-30\%}", "Lm_v24")'



#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grObs_pT2_1_1;PbPb2018_Lm_sysVz1_corrected.root:grObs_pT2_1_1;PbPb2018_Lm_sysVz2_corrected.root:grObs_pT2_1_1", "v_{2}^{Obs}{4};v_{2}^{Obs}{4} sysVz1;v_{2}^{Obs}{4} sysVz2", "#splitline{PbPb 5.02 TeV}{#Lambda 10-30\%}", "Lm_v24Obs_sysVz")'


#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grBkg_pT2_1_1;PbPb2018_Lm_sysVz1_corrected.root:grBkg_pT2_1_1;PbPb2018_Lm_sysVz2_corrected.root:grBkg_pT2_1_1", "v_{2}^{Bkg}{4};v_{2}^{Bkg}{4} sysVz1;v_{2}^{Bkg}{4} sysVz2", "#splitline{PbPb 5.02 TeV}{#Lambda 10-30\%}", "Lm_v24Bkg_sysVz")'

#root -l -b -q 'plotS.C("PbPb_v0.root:ch_PbPb_10_30/vn_NegEta;PbPb_v0.root:ch_PbPb_10_30/vn_PosEta;PbPb_v0.root:ch_PbPb_10_30/vn_NegEta_SubEvt;PbPb_v0.root:ch_PbPb_10_30/vn_PosEta_SubEvt", "v_{2}{SP-};v_{2}{SP+};v_{2}{SP-,SubEvt};v_{2}{SP+,SubEvt}", "#splitline{PbPb 5.02 TeV}{Ch 10-30\%}", "ch_v2SP")'


#root -l -b -q 'plotS.C("PbPb2018_Lm.root:grSig_pT2_1_1;PbPb2018_Lm_sysVz1.root:grSig_pT2_1_1;PbPb2018_Lm_sysVz2.root:grSig_pT2_1_1", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} |vz|<3.;v_{2}^{Sig}{4} |vz|>3.", "#splitline{PbPb 5.02 TeV}{#Lambda 10-30\%}", "Lm_v24_sysVz")'
#
#root -l -b -q 'plotS.C("PbPb2018_H_corrected.root:grSig_pT2_1_1;PbPb2018_H_sysVz1_corrected.root:grSig_pT2_1_1;PbPb2018_H_sysVz2_corrected.root:grSig_pT2_1_1", "v_{2}{4} |v_{z}|<15.;v_{2}{4} |v_{z}|<3.;v_{2}{4} 3.<|v_{z}|<15.", "#splitline{PbPb 5.02 TeV}{Ch 10-30\%}", "ch_v24_sysVz", 0, 0.09)'
#
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_1;PbPb2018_Ks_sysVz1_corrected.root:grSig_pT2_1_1;PbPb2018_Ks_sysVz2_corrected.root:grSig_pT2_1_1", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} 0<|vz|<3.;v_{2}^{Sig}{4} 3.<|vz|<15.", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 10-30\%}", "Ks_v24_sysVz", 0, 0.2)'
#
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_1;PbPb2018_Lm_sysVz1_corrected.root:grSig_pT2_1_1;PbPb2018_Lm_sysVz2_corrected.root:grSig_pT2_1_1", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} 0<|vz|<3.;v_{2}^{Sig}{4} 3.<|vz|<15.", "#splitline{PbPb 5.02 TeV}{#Lambda 10-30\%}", "Lm_v24_sysVz", 0, 0.2)'
#




#root -l -b -q 'plotS.C("PbPb2018_H_corrected.root:grSig_pT2_1_1;PbPb2018_H_sysTight_corrected.root:grSig_pT2_1_1;PbPb2018_H_sysLoose_corrected.root:grSig_pT2_1_1", "v_{2}{4} nominal;v_{2}{4} tight;v_{2}{4} loose", "#splitline{PbPb 5.02 TeV}{Ch 10-30\%}", "ch_v24_sysTrack", 0, 0.09)'



#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_1;PbPb2018_Lm_corrected_sysF3p.root:grSig_pT2_1_1;PbPb2018_Lm_corrected_sysF3n.root:grSig_pT2_1_1", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} +3%;v_{2}^{Sig}{4} -3%", "#splitline{PbPb 5.02 TeV}{#Lambda 10-30\%}", "Lm_v24_sysF", 0, 0.2)'


#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_1;PbPb2018_Ks_corrected_sysF3p.root:grSig_pT2_1_1;PbPb2018_Ks_corrected_sysF3n.root:grSig_pT2_1_1", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} +3%;v_{2}^{Sig}{4} -3%", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 10-30\%}", "Ks_v24_sysF", 0, 0.2)'

#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_1;PbPb2018_Lm_MB4_sysBDT15_corrected.root:grSig_pT2_1_1;PbPb2018_Lm_MB3_sysBDT25_corrected.root:grSig_pT2_1_1", "v_{2}^{Sig}{4} BDT>0.20;v_{2}^{Sig}{4} BDT>0.25;v_{2}^{Sig}{4} BDT>0.15", "#splitline{PbPb 5.02 TeV}{#Lambda 10-30\%}", "Lm_v24_sysBDT", 0, 0.2)'

root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_1;PbPb2018_Ks_MB3_sysBDT10_corrected.root:grSig_pT2_1_1;PbPb2018_Ks_MB3_sysBDT20_corrected.root:grSig_pT2_1_1", "v_{2}^{Sig}{4} BDT>0.15;v_{2}^{Sig}{4} BDT>0.10;v_{2}^{Sig}{4} BDT>0.20", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 10-30\%}", "Ks_v24_sysBDT", 0, 0.2)'

#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_0;PbPb_v0_SP_corrected.root:Ks_v2_PbPb_Sig_0_10/vn_MergedEta;PbPb_v0_SP_corrected.root:Ks_v3_PbPb_Sig_0_10/vn_MergedEta", "v_{2}^{Sig}{4};v_{2}^{Sig}{SP};v_{3}^{Sig}{SP}", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 0-10\%}", "Ks_0_vn")'
#
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_1;PbPb_v0_SP_corrected.root:Ks_v2_PbPb_Sig_10_30/vn_MergedEta;PbPb_v0_SP_corrected.root:Ks_v3_PbPb_Sig_10_30/vn_MergedEta", "v_{2}^{Sig}{4};v_{2}^{Sig}{SP};v_{3}^{Sig}{SP}", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 10-30\%}", "Ks_10_vn")'
#
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_2;PbPb_v0_SP_corrected.root:Ks_v2_PbPb_Sig_30_50/vn_MergedEta;PbPb_v0_SP_corrected.root:Ks_v3_PbPb_Sig_30_50/vn_MergedEta", "v_{2}^{Sig}{4};v_{2}^{Sig}{SP};v_{3}^{Sig}{SP}", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 30-50\%}", "Ks_30_vn")'
#
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_3;PbPb_v0_SP_corrected.root:Ks_v2_PbPb_Sig_50_80/vn_MergedEta;PbPb_v0_SP_corrected.root:Ks_v3_PbPb_Sig_50_80/vn_MergedEta", "v_{2}^{Sig}{4};v_{2}^{Sig}{SP};v_{3}^{Sig}{SP}", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 50-80\%}", "Ks_50_vn")'
#
#
#
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_0;PbPb_v0_SP_corrected.root:Lm_v2_PbPb_Sig_0_10/vn_MergedEta;PbPb_v0_SP_corrected.root:Lm_v3_PbPb_Sig_0_10/vn_MergedEta", "v_{2}^{Sig}{4};v_{2}^{Sig}{SP};v_{3}^{Sig}{SP}", "#splitline{PbPb 5.02 TeV}{#Lambda 0-10\%}", "Lm_0_vn")'
#
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_1;PbPb_v0_SP_corrected.root:Lm_v2_PbPb_Sig_10_30/vn_MergedEta;PbPb_v0_SP_corrected.root:Lm_v3_PbPb_Sig_10_30/vn_MergedEta", "v_{2}^{Sig}{4};v_{2}^{Sig}{SP};v_{3}^{Sig}{SP}", "#splitline{PbPb 5.02 TeV}{#Lambda 10-30\%}", "Lm_10_vn")'
#
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_2;PbPb_v0_SP_corrected.root:Lm_v2_PbPb_Sig_30_50/vn_MergedEta;PbPb_v0_SP_corrected.root:Lm_v3_PbPb_Sig_30_50/vn_MergedEta", "v_{2}^{Sig}{4};v_{2}^{Sig}{SP};v_{3}^{Sig}{SP}", "#splitline{PbPb 5.02 TeV}{#Lambda 30-50\%}", "Lm_30_vn")'
#
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_3;PbPb_v0_SP_corrected.root:Lm_v2_PbPb_Sig_50_80/vn_MergedEta;PbPb_v0_SP_corrected.root:Lm_v3_PbPb_Sig_50_80/vn_MergedEta", "v_{2}^{Sig}{4};v_{2}^{Sig}{SP};v_{3}^{Sig}{SP}", "#splitline{PbPb 5.02 TeV}{#Lambda 50-80\%}", "Lm_50_vn")'
#
#
#
#root -l -b -q 'plotS.C("PbPb2018_H_corrected.root:grSig_pT2_1_0;PbPb_v0_SP_corrected.root:ch_v2_PbPb_0_10/vn_MergedEta;PbPb_v0_SP_corrected.root:ch_v3_PbPb_0_10/vn_MergedEta", "v_{2}^{Sig}{4};v_{2}^{Sig}{SP};v_{3}^{Sig}{SP}", "#splitline{PbPb 5.02 TeV}{ch 0-10\%}", "ch_0_vn")'
#
#root -l -b -q 'plotS.C("PbPb2018_H_corrected.root:grSig_pT2_1_1;PbPb_v0_SP_corrected.root:ch_v2_PbPb_10_30/vn_MergedEta;PbPb_v0_SP_corrected.root:ch_v3_PbPb_10_30/vn_MergedEta", "v_{2}^{Sig}{4};v_{2}^{Sig}{SP};v_{3}^{Sig}{SP}", "#splitline{PbPb 5.02 TeV}{ch 10-30\%}", "ch_10_vn")'
#
#root -l -b -q 'plotS.C("PbPb2018_H_corrected.root:grSig_pT2_1_2;PbPb_v0_SP_corrected.root:ch_v2_PbPb_30_50/vn_MergedEta;PbPb_v0_SP_corrected.root:ch_v3_PbPb_30_50/vn_MergedEta", "v_{2}^{Sig}{4};v_{2}^{Sig}{SP};v_{3}^{Sig}{SP}", "#splitline{PbPb 5.02 TeV}{ch 30-50\%}", "ch_30_vn")'
#
#root -l -b -q 'plotS.C("PbPb2018_H_corrected.root:grSig_pT2_1_3;PbPb_v0_SP_corrected.root:ch_v2_PbPb_50_80/vn_MergedEta;PbPb_v0_SP_corrected.root:ch_v3_PbPb_50_80/vn_MergedEta", "v_{2}^{Sig}{4};v_{2}^{Sig}{SP};v_{3}^{Sig}{SP}", "#splitline{PbPb 5.02 TeV}{ch 50-80\%}", "ch_50_vn")'
#
#
#



