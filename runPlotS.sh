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

#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_1;PbPb2018_Ks_MB3_sysBDT10_corrected.root:grSig_pT2_1_1;PbPb2018_Ks_MB3_sysBDT20_corrected.root:grSig_pT2_1_1", "v_{2}^{Sig}{4} BDT>0.15;v_{2}^{Sig}{4} BDT>0.10;v_{2}^{Sig}{4} BDT>0.20", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 10-30\%}", "Ks_v24_sysBDT", 0, 0.2)'

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



#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_veto10_merged2_corrected.root:grSig_pT2_1_6", "v_{2}{4};v_{2}{4} veto p_{T}>10.", "#splitline{pPb 8.16 TeV}{Ch 120 #leq N_{trk}^{offline} < 150}", "vetoPt_v24_6", 0, 0.9)'
#
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged_corrected.root:grSig_pT2_2_6;../cumudiff/pPb_H_veto10_merged2_corrected.root:grSig_pT2_2_6", "v_{2}{6};v_{2}{6} veto p_{T}>10.", "#splitline{pPb 8.16 TeV}{Ch 120 #leq N_{trk}^{offline} < 150}", "vetoPt_v26_6", 0, 0.9)'
#
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_H_veto10_merged2_corrected.root:grSig_pT2_1_7", "v_{2}{4};v_{2}{4} veto p_{T}>10.", "#splitline{pPb 8.16 TeV}{Ch 150 #leq N_{trk}^{offline} < 185}", "vetoPt_v24_7", 0, 0.9)'
#
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged_corrected.root:grSig_pT2_2_7;../cumudiff/pPb_H_veto10_merged2_corrected.root:grSig_pT2_2_7", "v_{2}{6};v_{2}{6} veto p_{T}>10.", "#splitline{pPb 8.16 TeV}{Ch 150 #leq N_{trk}^{offline} < 185}", "vetoPt_v26_7", 0, 0.9)'
#
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged_corrected.root:grSig_pT2_1_8;../cumudiff/pPb_H_veto10_merged2_corrected.root:grSig_pT2_1_8", "v_{2}{4};v_{2}{4} veto p_{T}>10.", "#splitline{pPb 8.16 TeV}{Ch 185 #leq N_{trk}^{offline} < 250}", "vetoPt_v24_8", 0, 0.9)'
#
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged_corrected.root:grSig_pT2_2_8;../cumudiff/pPb_H_veto10_merged2_corrected.root:grSig_pT2_2_8", "v_{2}{6};v_{2}{6} veto p_{T}>10.", "#splitline{pPb 8.16 TeV}{Ch 185 #leq N_{trk}^{offline} < 250}", "vetoPt_v26_8", 0, 0.9)'
#
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged_corrected.root:grSig_pT2_1_9;../cumudiff/pPb_H_veto10_merged2_corrected.root:grSig_pT2_1_9", "v_{2}{4};v_{2}{4} veto p_{T}>10.", "#splitline{pPb 8.16 TeV}{Ch N_{trk}^{offline} #geq 250}", "vetoPt_v24_9", 0, 0.9)'
#
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged_corrected.root:grSig_pT2_2_9;../cumudiff/pPb_H_veto10_merged2_corrected.root:grSig_pT2_2_9", "v_{2}{6};v_{2}{6} veto p_{T}>10.", "#splitline{pPb 8.16 TeV}{Ch N_{trk}^{offline} #geq 250}", "vetoPt_v26_9", 0, 0.9)'
#
#root -l -b -q 'plotS.C("PbPb_v0_SP_corrected.root:Lm_v2_PbPb_Sig_5_10/vn_MergedEta;PbPb_v0_SP_corrected.root:Lm_z3_v2_PbPb_Sig_5_10/vn_MergedEta;PbPb_v0_SP_corrected.root:Lm_z15_v2_PbPb_Sig_5_10/vn_MergedEta", "v_{2}^{Sig}{SP} |vz|<15;v_{2}^{Sig}{SP} |vz|<3;v_{2}^{Sig}{SP} 3<|vz|<15", "#splitline{PbPb 5.02 TeV}{#Lambda 5-10\%}", "Lm_v2SP_sysVz1", 0, 0.5, 5)'
#root -l -b -q 'plotS.C("PbPb_v0_SP_corrected.root:Lm_v2_PbPb_Sig_10_30/vn_MergedEta;PbPb_v0_SP_corrected.root:Lm_z3_v2_PbPb_Sig_10_30/vn_MergedEta;PbPb_v0_SP_corrected.root:Lm_z15_v2_PbPb_Sig_10_30/vn_MergedEta", "v_{2}^{Sig}{SP} |vz|<15;v_{2}^{Sig}{SP} |vz|<3;v_{2}^{Sig}{SP} 3<|vz|<15", "#splitline{PbPb 5.02 TeV}{#Lambda 10-30\%}", "Lm_v2SP_sysVz2", 0, 0.5, 5)'
#root -l -b -q 'plotS.C("PbPb_v0_SP_corrected.root:Lm_v2_PbPb_Sig_30_50/vn_MergedEta;PbPb_v0_SP_corrected.root:Lm_z3_v2_PbPb_Sig_30_50/vn_MergedEta;PbPb_v0_SP_corrected.root:Lm_z15_v2_PbPb_Sig_30_50/vn_MergedEta", "v_{2}^{Sig}{SP} |vz|<15;v_{2}^{Sig}{SP} |vz|<3;v_{2}^{Sig}{SP} 3<|vz|<15", "#splitline{PbPb 5.02 TeV}{#Lambda 30-50\%}", "Lm_v2SP_sysVz3", 0, 0.5, 5)'
#root -l -b -q 'plotS.C("PbPb_v0_SP_corrected.root:Lm_v2_PbPb_Sig_50_80/vn_MergedEta;PbPb_v0_SP_corrected.root:Lm_z3_v2_PbPb_Sig_50_80/vn_MergedEta;PbPb_v0_SP_corrected.root:Lm_z15_v2_PbPb_Sig_50_80/vn_MergedEta", "v_{2}^{Sig}{SP} |vz|<15;v_{2}^{Sig}{SP} |vz|<3;v_{2}^{Sig}{SP} 3<|vz|<15", "#splitline{PbPb 5.02 TeV}{#Lambda 50-80\%}", "Lm_v2SP_sysVz4", 0, 0.5, 5)'
##
#root -l -b -q 'plotS.C("PbPb_v0_SP_corrected.root:Ks_v2_PbPb_Sig_5_10/vn_MergedEta;PbPb_v0_SP_corrected.root:Ks_z3_v2_PbPb_Sig_5_10/vn_MergedEta;PbPb_v0_SP_corrected.root:Ks_z15_v2_PbPb_Sig_5_10/vn_MergedEta", "v_{2}^{Sig}{SP} |vz|<15;v_{2}^{Sig}{SP} |vz|<3;v_{2}^{Sig}{SP} 3<|vz|<15", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 5-10\%}", "Ks_v2SP_sysVz1", 0, 0.5, 5)'
#root -l -b -q 'plotS.C("PbPb_v0_SP_corrected.root:Ks_v2_PbPb_Sig_10_30/vn_MergedEta;PbPb_v0_SP_corrected.root:Ks_z3_v2_PbPb_Sig_10_30/vn_MergedEta;PbPb_v0_SP_corrected.root:Ks_z15_v2_PbPb_Sig_10_30/vn_MergedEta", "v_{2}^{Sig}{SP} |vz|<15;v_{2}^{Sig}{SP} |vz|<3;v_{2}^{Sig}{SP} 3<|vz|<15", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 10-30\%}", "Ks_v2SP_sysVz2", 0, 0.5, 5)'
#root -l -b -q 'plotS.C("PbPb_v0_SP_corrected.root:Ks_v2_PbPb_Sig_30_50/vn_MergedEta;PbPb_v0_SP_corrected.root:Ks_z3_v2_PbPb_Sig_30_50/vn_MergedEta;PbPb_v0_SP_corrected.root:Ks_z15_v2_PbPb_Sig_30_50/vn_MergedEta", "v_{2}^{Sig}{SP} |vz|<15;v_{2}^{Sig}{SP} |vz|<3;v_{2}^{Sig}{SP} 3<|vz|<15", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 30-50\%}", "Ks_v2SP_sysVz3", 0, 0.5, 5)'
#root -l -b -q 'plotS.C("PbPb_v0_SP_corrected.root:Ks_v2_PbPb_Sig_50_80/vn_MergedEta;PbPb_v0_SP_corrected.root:Ks_z3_v2_PbPb_Sig_50_80/vn_MergedEta;PbPb_v0_SP_corrected.root:Ks_z15_v2_PbPb_Sig_50_80/vn_MergedEta", "v_{2}^{Sig}{SP} |vz|<15;v_{2}^{Sig}{SP} |vz|<3;v_{2}^{Sig}{SP} 3<|vz|<15", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 50-80\%}", "Ks_v2SP_sysVz4", 0, 0.5, 5)'
#
#
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_1;PbPb2018_Lm_sysVz1_corrected.root:grSig_pT2_1_1;PbPb2018_Lm_sysVz2_corrected.root:grSig_pT2_1_1;PbPb2018_Lm_sysVz3_corrected.root:grSig_pT2_1_1;PbPb2018_Lm_sysVz4_corrected.root:grSig_pT2_1_1", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} 0<|vz|<3.;v_{2}^{Sig}{4} 3.<|vz|<15.;v_{2}^{Sig}{4} -15<vz<0;v_{2}^{Sig}{4} 0<vz<15", "#splitline{PbPb 5.02 TeV}{#Lambda 5-10\%}", "Lm_v24_sysVz1", 0, 0.5, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_2;PbPb2018_Lm_sysVz1_corrected.root:grSig_pT2_1_2;PbPb2018_Lm_sysVz2_corrected.root:grSig_pT2_1_2;PbPb2018_Lm_sysVz3_corrected.root:grSig_pT2_1_2;PbPb2018_Lm_sysVz4_corrected.root:grSig_pT2_1_2", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} 0<|vz|<3.;v_{2}^{Sig}{4} 3.<|vz|<15.;v_{2}^{Sig}{4} -15<vz<0;v_{2}^{Sig}{4} 0<vz<15", "#splitline{PbPb 5.02 TeV}{#Lambda 10-30\%}", "Lm_v24_sysVz2", 0, 0.5, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_3;PbPb2018_Lm_sysVz1_corrected.root:grSig_pT2_1_3;PbPb2018_Lm_sysVz2_corrected.root:grSig_pT2_1_3;PbPb2018_Lm_sysVz3_corrected.root:grSig_pT2_1_3;PbPb2018_Lm_sysVz4_corrected.root:grSig_pT2_1_3", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} 0<|vz|<3.;v_{2}^{Sig}{4} 3.<|vz|<15.;v_{2}^{Sig}{4} -15<vz<0;v_{2}^{Sig}{4} 0<vz<15", "#splitline{PbPb 5.02 TeV}{#Lambda 30-50\%}", "Lm_v24_sysVz3", 0, 0.5, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_4;PbPb2018_Lm_sysVz1_corrected.root:grSig_pT2_1_4;PbPb2018_Lm_sysVz2_corrected.root:grSig_pT2_1_4;PbPb2018_Lm_sysVz3_corrected.root:grSig_pT2_1_4;PbPb2018_Lm_sysVz4_corrected.root:grSig_pT2_1_4", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} 0<|vz|<3.;v_{2}^{Sig}{4} 3.<|vz|<15.;v_{2}^{Sig}{4} -15<vz<0;v_{2}^{Sig}{4} 0<vz<15", "#splitline{PbPb 5.02 TeV}{#Lambda 50-80\%}", "Lm_v24_sysVz4", 0, 0.5, 6)'
#
#
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_1;PbPb2018_Ks_sysVz1_corrected.root:grSig_pT2_1_1;PbPb2018_Ks_sysVz2_corrected.root:grSig_pT2_1_1;PbPb2018_Ks_sysVz3_corrected.root:grSig_pT2_1_1;PbPb2018_Ks_sysVz4_corrected.root:grSig_pT2_1_1", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} 0<|vz|<3.;v_{2}^{Sig}{4} 3.<|vz|<15.;v_{2}^{Sig}{4} -15<vz<0;v_{2}^{Sig}{4} 0<vz<15", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 5-10\%}", "Ks_v24_sysVz1", 0, 0.5, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_2;PbPb2018_Ks_sysVz1_corrected.root:grSig_pT2_1_2;PbPb2018_Ks_sysVz2_corrected.root:grSig_pT2_1_2;PbPb2018_Ks_sysVz3_corrected.root:grSig_pT2_1_2;PbPb2018_Ks_sysVz4_corrected.root:grSig_pT2_1_2", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} 0<|vz|<3.;v_{2}^{Sig}{4} 3.<|vz|<15.;v_{2}^{Sig}{4} -15<vz<0;v_{2}^{Sig}{4} 0<vz<15", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 10-30\%}", "Ks_v24_sysVz2", 0, 0.5, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_3;PbPb2018_Ks_sysVz1_corrected.root:grSig_pT2_1_3;PbPb2018_Ks_sysVz2_corrected.root:grSig_pT2_1_3;PbPb2018_Ks_sysVz3_corrected.root:grSig_pT2_1_3;PbPb2018_Ks_sysVz4_corrected.root:grSig_pT2_1_3", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} 0<|vz|<3.;v_{2}^{Sig}{4} 3.<|vz|<15.;v_{2}^{Sig}{4} -15<vz<0;v_{2}^{Sig}{4} 0<vz<15", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 30-50\%}", "Ks_v24_sysVz3", 0, 0.5, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_4;PbPb2018_Ks_sysVz1_corrected.root:grSig_pT2_1_4;PbPb2018_Ks_sysVz2_corrected.root:grSig_pT2_1_4;PbPb2018_Ks_sysVz3_corrected.root:grSig_pT2_1_4;PbPb2018_Ks_sysVz4_corrected.root:grSig_pT2_1_4", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} 0<|vz|<3.;v_{2}^{Sig}{4} 3.<|vz|<15.;v_{2}^{Sig}{4} -15<vz<0;v_{2}^{Sig}{4} 0<vz<15", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 50-80\%}", "Ks_v24_sysVz4", 0, 0.5, 6)'
#
#
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_1;PbPb2018_Lm_sysPol3_corrected.root:grSig_pT2_1_1", "v_{2}^{Sig}{4} Pol4;v_{2}^{Sig}{4} Pol3", "#splitline{PbPb 5.02 TeV}{#Lambda 10-30\%}", "Lm_v24_sysPol3", 0, 0.3, 4)'
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_1;PbPb2018_Ks_sysPol3_corrected.root:grSig_pT2_1_1", "v_{2}^{Sig}{4} Pol4;v_{2}^{Sig}{4} Pol3", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 10-30\%}", "Ks_v24_sysPol3", 0, 0.3, 3)'
#
#
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_2;PbPb2018_LmSBPos_corrected.root:grSig_pT2_1_2;PbPb2018_LmSBNeg_corrected.root:grSig_pT2_1_2", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} SB+;v_{2}^{Sig}{4} SB-", "#splitline{PbPb 5.02 TeV}{#Lambda 10-30\%}", "Lm_v24_sysSB", 0, 0.3, 4)'
#
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_2;PbPb2018_KsSBPos_corrected.root:grSig_pT2_1_2;PbPb2018_KsSBNeg_corrected.root:grSig_pT2_1_2", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} SB+;v_{2}^{Sig}{4} SB-", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 10-30\%}", "Ks_v24_sysSB", 0, 0.3, 4)'
#
#
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_1;PbPb2018_Lm_sysMVACent_corrected.root:grSig_pT2_1_1", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} MVACent", "#splitline{PbPb 5.02 TeV}{#Lambda 5-10\%}", "Lm_v24_sysMVACent_1", 0, 0.3, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_2;PbPb2018_Lm_sysMVACent_corrected.root:grSig_pT2_1_2", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} MVACent", "#splitline{PbPb 5.02 TeV}{#Lambda 10-30\%}", "Lm_v24_sysMVACent_2", 0, 0.3, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_3;PbPb2018_Lm_sysMVACent_corrected.root:grSig_pT2_1_3", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} MVACent", "#splitline{PbPb 5.02 TeV}{#Lambda 30-50\%}", "Lm_v24_sysMVACent_3", 0, 0.3, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_4;PbPb2018_Lm_sysMVACent_corrected.root:grSig_pT2_1_4", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} MVACent", "#splitline{PbPb 5.02 TeV}{#Lambda 50-80\%}", "Lm_v24_sysMVACent_4", 0, 0.3, 6)'
#
#root -l -b -q 'plotS.C("PbPb2018_Lm_A_corrected.root:grSig_pT2_1_1;PbPb2018_Lm_sysMVACent_corrected.root:grSig_pT2_1_1", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} MVACent", "#splitline{PbPb 5.02 TeV}{#Lambda 5-10\%}", "Lm_A_v24_sysMVACent_1", 0, 0.3, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Lm_A_corrected.root:grSig_pT2_1_2;PbPb2018_Lm_sysMVACent_corrected.root:grSig_pT2_1_2", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} MVACent", "#splitline{PbPb 5.02 TeV}{#Lambda 10-30\%}", "Lm_A_v24_sysMVACent_2", 0, 0.3, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Lm_A_corrected.root:grSig_pT2_1_3;PbPb2018_Lm_sysMVACent_corrected.root:grSig_pT2_1_3", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} MVACent", "#splitline{PbPb 5.02 TeV}{#Lambda 30-50\%}", "Lm_A_v24_sysMVACent_3", 0, 0.3, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Lm_A_corrected.root:grSig_pT2_1_4;PbPb2018_Lm_sysMVACent_corrected.root:grSig_pT2_1_4", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} MVACent", "#splitline{PbPb 5.02 TeV}{#Lambda 50-80\%}", "Lm_A_v24_sysMVACent_4", 0, 0.3, 6)'
#
#
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_1;PbPb2018_Ks_sysMVACent_corrected.root:grSig_pT2_1_1", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} MVACent", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 5-10\%}", "Ks_v24_sysMVACent_1", 0, 0.3, 4)'
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_2;PbPb2018_Ks_sysMVACent_corrected.root:grSig_pT2_1_2", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} MVACent", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 10-30\%}", "Ks_v24_sysMVACent_2", 0, 0.3, 4)'
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_3;PbPb2018_Ks_sysMVACent_corrected.root:grSig_pT2_1_3", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} MVACent", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 30-50\%}", "Ks_v24_sysMVACent_3", 0, 0.3, 4)'
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_4;PbPb2018_Ks_sysMVACent_corrected.root:grSig_pT2_1_4", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} MVACent", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 50-80\%}", "Ks_v24_sysMVACent_4", 0, 0.3, 4)'
#
#
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_1;PbPb2018_Lm_sysSB1_corrected.root:grSig_pT2_1_1", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} 4#sigma SB", "#splitline{PbPb 5.02 TeV}{#Lambda 5-10\%}", "Lm_v24_sysSB1_1", 0, 0.18, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_2;PbPb2018_Lm_sysSB1_corrected.root:grSig_pT2_1_2", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} 4#sigma SB", "#splitline{PbPb 5.02 TeV}{#Lambda 10-30\%}", "Lm_v24_sysSB1_2", 0, 0.18, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_3;PbPb2018_Lm_sysSB1_corrected.root:grSig_pT2_1_3", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} 4#sigma SB", "#splitline{PbPb 5.02 TeV}{#Lambda 30-50\%}", "Lm_v24_sysSB1_3", 0, 0.18, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_4;PbPb2018_Lm_sysSB1_corrected.root:grSig_pT2_1_4", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} 4#sigma SB", "#splitline{PbPb 5.02 TeV}{#Lambda 50-80\%}", "Lm_v24_sysSB1_4", 0, 0.18, 6)'
#
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_1;PbPb2018_Ks_sysSB1_corrected.root:grSig_pT2_1_1", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} 4#sigma SB", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 5-10\%}", "Ks_v24_sysSB1_1", 0, 0.18, 4)'
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_2;PbPb2018_Ks_sysSB1_corrected.root:grSig_pT2_1_2", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} 4#sigma SB", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 10-30\%}", "Ks_v24_sysSB1_2", 0, 0.18, 4)'
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_3;PbPb2018_Ks_sysSB1_corrected.root:grSig_pT2_1_3", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} 4#sigma SB", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 30-50\%}", "Ks_v24_sysSB1_3", 0, 0.18, 4)'
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_4;PbPb2018_Ks_sysSB1_corrected.root:grSig_pT2_1_4", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} 4#sigma SB", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 50-80\%}", "Ks_v24_sysSB1_4", 0, 0.18, 4)'
#
#
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_1;PbPb2018_Lm_sysCentPlus_corrected.root:grSig_pT2_1_1", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} Cent+5", "#splitline{PbPb 5.02 TeV}{#Lambda 5-10\%}", "Lm_v24_sysCentPlus_1", 0, 0.3, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_2;PbPb2018_Lm_sysCentPlus_corrected.root:grSig_pT2_1_2", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} Cent+5", "#splitline{PbPb 5.02 TeV}{#Lambda 10-30\%}", "Lm_v24_sysCentPlus_2", 0, 0.3, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_3;PbPb2018_Lm_sysCentPlus_corrected.root:grSig_pT2_1_3", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} Cent+5", "#splitline{PbPb 5.02 TeV}{#Lambda 30-50\%}", "Lm_v24_sysCentPlus_3", 0, 0.3, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_4;PbPb2018_Lm_sysCentPlus_corrected.root:grSig_pT2_1_4", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} Cent+5", "#splitline{PbPb 5.02 TeV}{#Lambda 50-80\%}", "Lm_v24_sysCentPlus_4", 0, 0.3, 6)'
#
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_1;PbPb2018_Ks_sysCentPlus_corrected.root:grSig_pT2_1_1", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} Cent+5", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 5-10\%}", "Ks_v24_sysCentPlus_1", 0, 0.3, 4)'
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_2;PbPb2018_Ks_sysCentPlus_corrected.root:grSig_pT2_1_2", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} Cent+5", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 10-30\%}", "Ks_v24_sysCentPlus_2", 0, 0.3, 4)'
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_3;PbPb2018_Ks_sysCentPlus_corrected.root:grSig_pT2_1_3", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} Cent+5", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 30-50\%}", "Ks_v24_sysCentPlus_3", 0, 0.3, 4)'
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_4;PbPb2018_Ks_sysCentPlus_corrected.root:grSig_pT2_1_4", "v_{2}^{Sig}{4} Std;v_{2}^{Sig}{4} Cent+5", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 50-80\%}", "Ks_v24_sysCentPlus_4", 0, 0.3, 4)'




#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_1;PbPb2018_Lm_sysPol3_corrected.root:grSig_pT2_1_1;PbPb2018_Lm_sysPol1_corrected.root:grSig_pT2_1_1;PbPb2018_Lm_sysExp_corrected.root:grSig_pT2_1_1", "v_{2}^{Sig}{4} Pol4;v_{2}^{Sig}{4} Pol3;v_{2}^{Sig}{4} Pol1;v_{2}^{Sig}{4} Exp", "#splitline{PbPb 5.02 TeV}{#Lambda 10-30\%}", "Lm_v24_sysBkg", 0, 0.1, 4)'
#
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_1;PbPb2018_Ks_sysPol3_corrected.root:grSig_pT2_1_1;PbPb2018_Ks_sysPol1_corrected.root:grSig_pT2_1_1;PbPb2018_Ks_sysExp_corrected.root:grSig_pT2_1_1", "v_{2}^{Sig}{4} Pol4;v_{2}^{Sig}{4} Pol3;v_{2}^{Sig}{4} Pol1;v_{2}^{Sig}{4} Exp", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 10-30\%}", "Ks_v24_sysBkg", 0, 0.1, 4)'



#
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grObs_pT2_1_1;PbPb2018_Lm_corrected.root:grBkg_pT2_1_1", "v_{2}^{Obs}{4};v_{2}^{Bkg}{4}", "#splitline{PbPb 5.02 TeV}{#Lambda 5-10\%}", "Lm_v24_1", -1, 0.3, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grObs_pT2_1_2;PbPb2018_Lm_corrected.root:grBkg_pT2_1_2", "v_{2}^{Obs}{4};v_{2}^{Bkg}{4}", "#splitline{PbPb 5.02 TeV}{#Lambda 10-30\%}", "Lm_v24_2", -1, 0.3, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grObs_pT2_1_3;PbPb2018_Lm_corrected.root:grBkg_pT2_1_3", "v_{2}^{Obs}{4};v_{2}^{Bkg}{4}", "#splitline{PbPb 5.02 TeV}{#Lambda 30-50\%}", "Lm_v24_3", -1, 0.3, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grObs_pT2_1_4;PbPb2018_Lm_corrected.root:grBkg_pT2_1_4", "v_{2}^{Obs}{4};v_{2}^{Bkg}{4}", "#splitline{PbPb 5.02 TeV}{#Lambda 50-80\%}", "Lm_v24_4", -1, 0.3, 6)'
#
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grObs_pT2_1_1;PbPb2018_Ks_corrected.root:grBkg_pT2_1_1", "v_{2}^{Obs}{4};v_{2}^{Bkg}{4}", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 5-10\%}", "Ks_v24_1", -1, 0.3, 4)'
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grObs_pT2_1_2;PbPb2018_Ks_corrected.root:grBkg_pT2_1_2", "v_{2}^{Obs}{4};v_{2}^{Bkg}{4}", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 10-30\%}", "Ks_v24_2", -1, 0.3, 4)'
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grObs_pT2_1_3;PbPb2018_Ks_corrected.root:grBkg_pT2_1_3", "v_{2}^{Obs}{4};v_{2}^{Bkg}{4}", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 30-50\%}", "Ks_v24_3", -1, 0.3, 4)'
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grObs_pT2_1_4;PbPb2018_Ks_corrected.root:grBkg_pT2_1_4", "v_{2}^{Obs}{4};v_{2}^{Bkg}{4}", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 50-80\%}", "Ks_v24_4", -1, 0.3, 4)'
#
#
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_1;PbPb2018_Lm_sysNoAP_corrected.root:grSig_pT2_1_1", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} No AP Cut", "#splitline{PbPb 5.02 TeV}{#Lambda 5-10\%}",  "Lm_v24_sysNoAP_1", 0, 0.5, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_2;PbPb2018_Lm_sysNoAP_corrected.root:grSig_pT2_1_2", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} No AP Cut", "#splitline{PbPb 5.02 TeV}{#Lambda 10-30\%}", "Lm_v24_sysNoAP_2", 0, 0.5, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_3;PbPb2018_Lm_sysNoAP_corrected.root:grSig_pT2_1_3", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} No AP Cut", "#splitline{PbPb 5.02 TeV}{#Lambda 30-50\%}", "Lm_v24_sysNoAP_3", 0, 0.5, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_4;PbPb2018_Lm_sysNoAP_corrected.root:grSig_pT2_1_4", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} No AP Cut", "#splitline{PbPb 5.02 TeV}{#Lambda 50-80\%}", "Lm_v24_sysNoAP_4", 0, 0.5, 6)'
#
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_1;PbPb2018_Ks_sysNoAP_corrected.root:grSig_pT2_1_1", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} No AP Cut", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 5-10\%}",  "Ks_v24_sysNoAP_1", 0, 0.5, 4)'
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_2;PbPb2018_Ks_sysNoAP_corrected.root:grSig_pT2_1_2", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} No AP Cut", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 10-30\%}", "Ks_v24_sysNoAP_2", 0, 0.5, 4)'
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_3;PbPb2018_Ks_sysNoAP_corrected.root:grSig_pT2_1_3", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} No AP Cut", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 30-50\%}", "Ks_v24_sysNoAP_3", 0, 0.5, 4)'
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_4;PbPb2018_Ks_sysNoAP_corrected.root:grSig_pT2_1_4", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} No AP Cut", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 50-80\%}", "Ks_v24_sysNoAP_4", 0, 0.5, 4)'
#

#root -l -b -q 'plotS.C("combinedS_145.root:grV023_4;combinedS_61.root:grV023_4;combinedS_62.root:grV023_4;combinedS_63.root:grV023_4;combinedS_64.root:grV023_4;combinedS_65.root:grV023_4", "v_{2}^{Obs}{8};MB0;MB1;MB2;MB3;MB4", "#splitline{PbPb 5.02 TeV}{#Ks 50-80\%}", "Ks_v28obs_0.pdf", 0, 0.5, 4)'

#root -l -b -q 'plotS.C("combinedS_145.root:grV023_4;combinedS_66.root:grV023_4;combinedS_67.root:grV023_4;combinedS_68.root:grV023_4;combinedS_69.root:grV023_4;combinedS_70.root:grV023_4", "v_{2}^{Obs}{8};MB5;MB6;MB7;MB8;MB9", "#splitline{PbPb 5.02 TeV}{#Ks 50-80\%}", "Ks_v28obs_1.pdf", 0, 0.5, 4)'
#
#root -l -b -q 'plotS.C("combinedS_145.root:grV023_4;combinedS_71.root:grV023_4;combinedS_72.root:grV023_4;combinedS_73.root:grV023_4;combinedS_74.root:grV023_4;combinedS_75.root:grV023_4", "v_{2}^{Obs}{8};MB10;MB11;MB12;MB13;MB14", "#splitline{PbPb 5.02 TeV}{#Ks 50-80\%}", "Ks_v28obs_2.pdf", 0, 0.5, 4)'
#
#root -l -b -q 'plotS.C("combinedS_145.root:grV023_4;combinedS_76.root:grV023_4;combinedS_77.root:grV023_4;combinedS_78.root:grV023_4;combinedS_79.root:grV023_4;combinedS_80.root:grV023_4", "v_{2}^{Obs}{8};MB15;MB16;MB17;MB18;MB19", "#splitline{PbPb 5.02 TeV}{#Ks 50-80\%}", "Ks_v28obs_3.pdf", 0, 0.5, 4)'
#
##root -l -b -q 'plotS.C("combinedS_145.root:grV022_4;combinedS_61.root:grV022_4;combinedS_62.root:grV022_4;combinedS_63.root:grV022_4;combinedS_64.root:grV022_4;combinedS_65.root:grV022_4", "v_{2}^{Obs}{6};MB0;MB1;MB2;MB3;MB4", "#splitline{PbPb 5.02 TeV}{#Ks 50-80\%}", "Ks_v26obs_0.pdf", 0, 0.5, 4)'
##
#root -l -b -q 'plotS.C("combinedS_145.root:grV022_4;combinedS_66.root:grV022_4;combinedS_67.root:grV022_4;combinedS_68.root:grV022_4;combinedS_69.root:grV022_4;combinedS_70.root:grV022_4", "v_{2}^{Obs}{6};MB5;MB6;MB7;MB8;MB9", "#splitline{PbPb 5.02 TeV}{#Ks 50-80\%}", "Ks_v26obs_1.pdf", 0, 0.5, 4)'
#
#root -l -b -q 'plotS.C("combinedS_145.root:grV022_4;combinedS_71.root:grV022_4;combinedS_72.root:grV022_4;combinedS_73.root:grV022_4;combinedS_74.root:grV022_4;combinedS_75.root:grV022_4", "v_{2}^{Obs}{6};MB10;MB11;MB12;MB13;MB14", "#splitline{PbPb 5.02 TeV}{#Ks 50-80\%}", "Ks_v26obs_2.pdf", 0, 0.5, 4)'
#
#root -l -b -q 'plotS.C("combinedS_145.root:grV022_4;combinedS_76.root:grV022_4;combinedS_77.root:grV022_4;combinedS_78.root:grV022_4;combinedS_79.root:grV022_4;combinedS_80.root:grV022_4", "v_{2}^{Obs}{6};MB15;MB16;MB17;MB18;MB19", "#splitline{PbPb 5.02 TeV}{#Ks 50-80\%}", "Ks_v26obs_3.pdf", 0, 0.5, 4)'

#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_veto10_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_veto10eta18_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_veto10eta24_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_eta18_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_eta24_merged2_corrected.root:grSig_pT2_1_6", "v_{2}{4} |#eta|<1.;v_{2}{4} |#eta|<1. veto;v_{2}{4} |#eta|<1.8 veto;v_{2}{4} |#eta|<2.4 veto;v_{2}{4} |#eta|<1.8;v_{2}{4} |#eta|<2.4", "#splitline{pPb 8.16 TeV}{Ch 120 #leq N_{trk}^{offline} < 150}", "vetoPt_v24_6.pdf", 0, 2.5)'

#
#
#
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_H_veto10_merged2_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_H_veto10eta18_merged2_corrected.root:grSig_pT2_1_7", "v_{2}{4} |#eta|<1.;v_{2}{4} |#eta|<1. veto;v_{2}{4} |#eta|<1.8 veto", "#splitline{pPb 8.16 TeV}{Ch 150 #leq N_{trk}^{offline} < 185}", "vetoPt_v24_7.pdf", 0, 2.5)'
#
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_2_6;../cumudiff/pPb_H_veto10_merged2_corrected.root:grSig_pT2_2_6;../cumudiff/pPb_H_veto10eta18_merged2_corrected.root:grSig_pT2_2_6", "v_{2}{6} |#eta|<1.;v_{2}{6} |#eta|<1. veto;v_{2}{6} |#eta|<1.8 veto", "#splitline{pPb 8.16 TeV}{Ch 120 #leq N_{trk}^{offline} < 150}", "vetoPt_v26_6.pdf", 0, 2.5)'
#
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_2_7;../cumudiff/pPb_H_veto10_merged2_corrected.root:grSig_pT2_2_7;../cumudiff/pPb_H_veto10eta18_merged2_corrected.root:grSig_pT2_2_7", "v_{2}{6} |#eta|<1.;v_{2}{6} |#eta|<1. veto;v_{2}{6} |#eta|<1.8 veto", "#splitline{pPb 8.16 TeV}{Ch 150 #leq N_{trk}^{offline} < 185}", "vetoPt_v26_7.pdf", 0, 2.5)'
#


#
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_1;PbPb2018_Ks_sysMCBias_corrected.root:grSig_pT2_1_1", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} MCBias", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 5-10\%}",  "Ks_v24_sysMCBias_1", 0, 0.5, 4)'
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_2;PbPb2018_Ks_sysMCBias_corrected.root:grSig_pT2_1_2", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} MCBias", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 10-30\%}",  "Ks_v24_sysMCBias_2", 0, 0.5, 4)'
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_3;PbPb2018_Ks_sysMCBias_corrected.root:grSig_pT2_1_3", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} MCBias", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 30-50\%}",  "Ks_v24_sysMCBias_3", 0, 0.5, 4)'
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_4;PbPb2018_Ks_sysMCBias_corrected.root:grSig_pT2_1_4", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} MCBias", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 50-80\%}",  "Ks_v24_sysMCBias_4", 0, 0.5, 4)'
#
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_1;PbPb2018_Lm_sysMCBias_corrected.root:grSig_pT2_1_1", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} MCBias", "#splitline{PbPb 5.02 TeV}{#Lambda 5-10\%}",  "Lm_v24_sysMCBias_1", 0, 0.5, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_2;PbPb2018_Lm_sysMCBias_corrected.root:grSig_pT2_1_2", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} MCBias", "#splitline{PbPb 5.02 TeV}{#Lambda 10-30\%}",  "Lm_v24_sysMCBias_2", 0, 0.5, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_3;PbPb2018_Lm_sysMCBias_corrected.root:grSig_pT2_1_3", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} MCBias", "#splitline{PbPb 5.02 TeV}{#Lambda 30-50\%}",  "Lm_v24_sysMCBias_3", 0, 0.5, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_4;PbPb2018_Lm_sysMCBias_corrected.root:grSig_pT2_1_4", "v_{2}^{Sig}{4};v_{2}^{Sig}{4} MCBias", "#splitline{PbPb 5.02 TeV}{#Lambda 50-80\%}",  "Lm_v24_sysMCBias_4", 0, 0.5, 6)'
#



#
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_veto10_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_veto10eta18_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_veto10eta24_merged2_corrected.root:grSig_pT2_1_6", "v_{2}{4} |#eta|<1.;v_{2}{4} |#eta|<1. veto;v_{2}{4} |#eta|<1.8 veto;v_{2}{4} |#eta|<2.4 veto", "#splitline{pPb 8.16 TeV}{Ch 120 #leq N_{trk}^{offline} < 150}", "Pt_v24veto_6", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_H_veto10_merged2_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_H_veto10eta18_merged2_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_H_veto10eta24_merged2_corrected.root:grSig_pT2_1_7", "v_{2}{4} |#eta|<1.;v_{2}{4} |#eta|<1. veto;v_{2}{4} |#eta|<1.8 veto;v_{2}{4} |#eta|<2.4 veto", "#splitline{pPb 8.16 TeV}{Ch 150 #leq N_{trk}^{offline} < 185}", "Pt_v24veto_7", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_2_6;../cumudiff/pPb_H_veto10_merged2_corrected.root:grSig_pT2_2_6;../cumudiff/pPb_H_veto10eta18_merged2_corrected.root:grSig_pT2_2_6;../cumudiff/pPb_H_veto10eta24_merged2_corrected.root:grSig_pT2_2_6", "v_{2}{6} |#eta|<1.;v_{2}{6} |#eta|<1. veto;v_{2}{6} |#eta|<1.8 veto;v_{2}{6} |#eta|<2.4 veto", "#splitline{pPb 8.16 TeV}{Ch 120 #leq N_{trk}^{offline} < 150}", "Pt_v26veto_6", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_2_7;../cumudiff/pPb_H_veto10_merged2_corrected.root:grSig_pT2_2_7;../cumudiff/pPb_H_veto10eta18_merged2_corrected.root:grSig_pT2_2_7;../cumudiff/pPb_H_veto10eta24_merged2_corrected.root:grSig_pT2_2_7", "v_{2}{6} |#eta|<1.;v_{2}{6} |#eta|<1. veto;v_{2}{6} |#eta|<1.8 veto;v_{2}{6} |#eta|<2.4 veto", "#splitline{pPb 8.16 TeV}{Ch 150 #leq N_{trk}^{offline} < 185}", "Pt_v26veto_7", 0, 2.5)'
#
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_eta18_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_eta24_merged2_corrected.root:grSig_pT2_1_6", "v_{2}{4} |#eta|<1.;v_{2}{4} |#eta|<1.8;v_{2}{4} |#eta|<2.4", "#splitline{pPb 8.16 TeV}{Ch 120 #leq N_{trk}^{offline} < 150}", "Pt_v24_6", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_H_eta18_merged2_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_H_eta24_merged2_corrected.root:grSig_pT2_1_7", "v_{2}{4} |#eta|<1.;v_{2}{4} |#eta|<1.8;v_{2}{4} |#eta|<2.4", "#splitline{pPb 8.16 TeV}{Ch 150 #leq N_{trk}^{offline} < 185}", "Pt_v24_7", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_2_6;../cumudiff/pPb_H_eta18_merged2_corrected.root:grSig_pT2_2_6;../cumudiff/pPb_H_eta24_merged2_corrected.root:grSig_pT2_2_6", "v_{2}{6} |#eta|<1.;v_{2}{6} |#eta|<1.8;v_{2}{6} |#eta|<2.4", "#splitline{pPb 8.16 TeV}{Ch 120 #leq N_{trk}^{offline} < 150}", "Pt_v26_6", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_2_7;../cumudiff/pPb_H_eta18_merged2_corrected.root:grSig_pT2_2_7;../cumudiff/pPb_H_eta24_merged2_corrected.root:grSig_pT2_2_7", "v_{2}{6} |#eta|<1.;v_{2}{6} |#eta|<1.8;v_{2}{6} |#eta|<2.4", "#splitline{pPb 8.16 TeV}{Ch 150 #leq N_{trk}^{offline} < 185}", "Pt_v26_7", 0, 2.5)'
#

#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_veto10_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_vetoJet20_merged2_corrected.root:grSig_pT2_1_6", "v_{2}{4};v_{2}{4} veto track;v_{2}{4} veto jet", "#splitline{pPb 8.16 TeV}{Ch 120 #leq N_{trk}^{offline} < 150}", "Pt_v24veto_6", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_H_veto10_merged2_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_H_vetoJet20_merged2_corrected.root:grSig_pT2_1_7", "v_{2}{4};v_{2}{4} veto track;v_{2}{4} veto jet", "#splitline{pPb 8.16 TeV}{Ch 150 #leq N_{trk}^{offline} < 185}", "Pt_v24veto_7", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_1_8;../cumudiff/pPb_H_veto10_merged2_corrected.root:grSig_pT2_1_8;../cumudiff/pPb_H_vetoJet20_merged2_corrected.root:grSig_pT2_1_8", "v_{2}{4};v_{2}{4} veto track;v_{2}{4} veto jet", "#splitline{pPb 8.16 TeV}{Ch 185 #leq N_{trk}^{offline} < 250}", "Pt_v24veto_8", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_1_9;../cumudiff/pPb_H_veto10_merged2_corrected.root:grSig_pT2_1_9;../cumudiff/pPb_H_vetoJet20_merged2_corrected.root:grSig_pT2_1_9", "v_{2}{4};v_{2}{4} veto track;v_{2}{4} veto jet", "#splitline{pPb 8.16 TeV}{Ch N_{trk}^{offline} #geq 250}", "Pt_v24veto_9", 0, 2.5)'
#
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_2_6;../cumudiff/pPb_H_veto10_merged2_corrected.root:grSig_pT2_2_6;../cumudiff/pPb_H_vetoJet20_merged2_corrected.root:grSig_pT2_2_6", "v_{2}{6};v_{2}{6} veto track;v_{2}{6} veto jet", "#splitline{pPb 8.16 TeV}{Ch 120 #leq N_{trk}^{offline} < 150}", "Pt_v26veto_6", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_2_7;../cumudiff/pPb_H_veto10_merged2_corrected.root:grSig_pT2_2_7;../cumudiff/pPb_H_vetoJet20_merged2_corrected.root:grSig_pT2_2_7", "v_{2}{6};v_{2}{6} veto track;v_{2}{6} veto jet", "#splitline{pPb 8.16 TeV}{Ch 150 #leq N_{trk}^{offline} < 185}", "Pt_v26veto_7", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_2_8;../cumudiff/pPb_H_veto10_merged2_corrected.root:grSig_pT2_2_8;../cumudiff/pPb_H_vetoJet20_merged2_corrected.root:grSig_pT2_2_8", "v_{2}{6};v_{2}{6} veto track;v_{2}{6} veto jet", "#splitline{pPb 8.16 TeV}{Ch 185 #leq N_{trk}^{offline} < 250}", "Pt_v26veto_8", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_2_9;../cumudiff/pPb_H_veto10_merged2_corrected.root:grSig_pT2_2_9;../cumudiff/pPb_H_vetoJet20_merged2_corrected.root:grSig_pT2_2_9", "v_{2}{6};v_{2}{6} veto track;v_{2}{6} veto jet", "#splitline{pPb 8.16 TeV}{Ch N_{trk}^{offline} #geq 250}", "Pt_v26veto_9", 0, 2.5)'
#
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_3_6;../cumudiff/pPb_H_veto10_merged2_corrected.root:grSig_pT2_3_6;../cumudiff/pPb_H_vetoJet20_merged2_corrected.root:grSig_pT2_2_6", "v_{2}{8};v_{2}{8} veto track;v_{2}{8} veto jet", "#splitline{pPb 8.16 TeV}{Ch 120 #leq N_{trk}^{offline} < 150}", "Pt_v28veto_6", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_3_7;../cumudiff/pPb_H_veto10_merged2_corrected.root:grSig_pT2_3_7;../cumudiff/pPb_H_vetoJet20_merged2_corrected.root:grSig_pT2_2_7", "v_{2}{8};v_{2}{8} veto track;v_{2}{8} veto jet", "#splitline{pPb 8.16 TeV}{Ch 150 #leq N_{trk}^{offline} < 185}", "Pt_v28veto_7", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_3_8;../cumudiff/pPb_H_veto10_merged2_corrected.root:grSig_pT2_3_8;../cumudiff/pPb_H_vetoJet20_merged2_corrected.root:grSig_pT2_2_8", "v_{2}{8};v_{2}{8} veto track;v_{2}{8} veto jet", "#splitline{pPb 8.16 TeV}{Ch 185 #leq N_{trk}^{offline} < 250}", "Pt_v28veto_8", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_3_9;../cumudiff/pPb_H_veto10_merged2_corrected.root:grSig_pT2_3_9;../cumudiff/pPb_H_vetoJet20_merged2_corrected.root:grSig_pT2_2_9", "v_{2}{8};v_{2}{8} veto track;v_{2}{8} veto jet", "#splitline{pPb 8.16 TeV}{Ch N_{trk}^{offline} #geq 250}", "Pt_v26veto_8", 0, 2.5)'
#
#
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_vetoJet20_merged2_corrected.root:grSig_pT2_2_6", "v_{2}{4} veto jet;v_{2}{6} veto jet", "#splitline{pPb 8.16 TeV}{Ch 120 #leq N_{trk}^{offline} < 150}", "Pt_v246veto_6", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20_merged2_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_H_vetoJet20_merged2_corrected.root:grSig_pT2_2_7", "v_{2}{4} veto jet;v_{2}{6} veto jet", "#splitline{pPb 8.16 TeV}{Ch 150 #leq N_{trk}^{offline} < 185}", "Pt_v246veto_7", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20_merged2_corrected.root:grSig_pT2_1_8;../cumudiff/pPb_H_vetoJet20_merged2_corrected.root:grSig_pT2_2_8", "v_{2}{4} veto jet;v_{2}{6} veto jet", "#splitline{pPb 8.16 TeV}{Ch 185 #leq N_{trk}^{offline} < 250}", "Pt_v246veto_8", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20_merged2_corrected.root:grSig_pT2_1_9;../cumudiff/pPb_H_vetoJet20_merged2_corrected.root:grSig_pT2_2_9", "v_{2}{4} veto jet;v_{2}{6} veto jet", "#splitline{pPb 8.16 TeV}{Ch N_{trk}^{offline} #geq 250}", "Pt_v246veto_9", 0, 2.5)'
#





#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_1;PbPb2018_Lm_WSFsig_corrected.root:grSig_pT2_1_1", "v_{2}^{Sig}{4} Pol4;v_{2}^{Sig}{4} SS", "#splitline{PbPb 5.02 TeV}{#Lambda 5-10\%}", "Lm_v24_sysWS_1", 0, 0.1, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_2;PbPb2018_Lm_WSFsig_corrected.root:grSig_pT2_1_2", "v_{2}^{Sig}{4} Pol4;v_{2}^{Sig}{4} SS", "#splitline{PbPb 5.02 TeV}{#Lambda 10-30\%}", "Lm_v24_sysWS_2", 0, 0.1, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_3;PbPb2018_Lm_WSFsig_corrected.root:grSig_pT2_1_3", "v_{2}^{Sig}{4} Pol4;v_{2}^{Sig}{4} SS", "#splitline{PbPb 5.02 TeV}{#Lambda 30-50\%}", "Lm_v24_sysWS_3", 0, 0.1, 6)'
#root -l -b -q 'plotS.C("PbPb2018_Lm_corrected.root:grSig_pT2_1_4;PbPb2018_Lm_WSFsig_corrected.root:grSig_pT2_1_4", "v_{2}^{Sig}{4} Pol4;v_{2}^{Sig}{4} SS", "#splitline{PbPb 5.02 TeV}{#Lambda 50-80\%}", "Lm_v24_sysWS_4", 0, 0.1, 6)'
#
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_1;PbPb2018_Ks_WSFsig_corrected.root:grSig_pT2_1_1", "v_{2}^{Sig}{4} Pol4;v_{2}^{Sig}{4} SS", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 5-10\%}", "Ks_v24_sysWS_1", 0, 0.1, 4)'
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_2;PbPb2018_Ks_WSFsig_corrected.root:grSig_pT2_1_2", "v_{2}^{Sig}{4} Pol4;v_{2}^{Sig}{4} SS", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 10-30\%}", "Ks_v24_sysWS_2", 0, 0.1, 4)'
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_3;PbPb2018_Ks_WSFsig_corrected.root:grSig_pT2_1_3", "v_{2}^{Sig}{4} Pol4;v_{2}^{Sig}{4} SS", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 30-50\%}", "Ks_v24_sysWS_3", 0, 0.1, 4)'
#root -l -b -q 'plotS.C("PbPb2018_Ks_corrected.root:grSig_pT2_1_4;PbPb2018_Ks_WSFsig_corrected.root:grSig_pT2_1_4", "v_{2}^{Sig}{4} Pol4;v_{2}^{Sig}{4} SS", "#splitline{PbPb 5.02 TeV}{K_{S}^{0} 50-80\%}", "Ks_v24_sysWS_4", 0, 0.1, 4)'
#




########## !!!! Veto jet study
##### standard v24 vs v26 vs v22
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_2_6;../cumudiff/pPb_H_merged2_corrected.root:grSig_pTGap2_6", "v_{2}{4};v_{2}{6};v_{2}{2,|#Delta#eta|>2.}", "#splitline{pPb 8.16 TeV}{Ch 120 #leq N_{trk}^{offline} < 150}", "Pt_v246_6", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_2_7;../cumudiff/pPb_H_merged2_corrected.root:grSig_pTGap2_7", "v_{2}{4};v_{2}{6};v_{2}{2,|#Delta#eta|>2.}", "#splitline{pPb 8.16 TeV}{Ch 150 #leq N_{trk}^{offline} < 185}", "Pt_v246_7", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_1_8;../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_2_8;../cumudiff/pPb_H_merged2_corrected.root:grSig_pTGap2_8", "v_{2}{4};v_{2}{6};v_{2}{2,|#Delta#eta|>2.}", "#splitline{pPb 8.16 TeV}{Ch 185 #leq N_{trk}^{offline} < 250}", "Pt_v246_8", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_1_9;../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_2_9;../cumudiff/pPb_H_merged2_corrected.root:grSig_pTGap2_9", "v_{2}{4};v_{2}{6};v_{2}{2,|#Delta#eta|>2.}", "#splitline{pPb 8.16 TeV}{Ch N_{trk}^{offline} #geq 250}", "Pt_v246_9", 0, 2.5)'
#

#####  vetoJet20eta20 v24 vs v26 vs v22
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_2_6;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pTGap2_6", "v_{2}{4} p_{T,jet}>20 |#eta_{jet}|<2.0;v_{2}{6} p_{T,jet}>20 |#eta_{jet}|<2.0;v_{2}{2} p_{T,jet}>20 |#eta_{jet}|<2.0", "#splitline{pPb 8.16 TeV}{Ch 120 #leq N_{trk}^{offline} < 150}", "Pt_v246veto_6", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_2_7;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pTGap2_7", "v_{2}{4} p_{T,jet}>20 |#eta_{jet}|<2.0;v_{2}{6} p_{T,jet}>20 |#eta_{jet}|<2.0;v_{2}{2} p_{T,jet}>20 |#eta_{jet}|<2.0", "#splitline{pPb 8.16 TeV}{Ch 150 #leq N_{trk}^{offline} < 185}", "Pt_v246veto_7", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_8;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_2_8;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pTGap2_8", "v_{2}{4} p_{T,jet}>20 |#eta_{jet}|<2.0;v_{2}{6} p_{T,jet}>20 |#eta_{jet}|<2.0;v_{2}{2} p_{T,jet}>20 |#eta_{jet}|<2.0", "#splitline{pPb 8.16 TeV}{Ch 185 #leq N_{trk}^{offline} < 250}", "Pt_v246veto_8", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_9;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_2_9;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pTGap2_9", "v_{2}{4} p_{T,jet}>20 |#eta_{jet}|<2.0;v_{2}{6} p_{T,jet}>20 |#eta_{jet}|<2.0;v_{2}{2} p_{T,jet}>20 |#eta_{jet}|<2.0", "#splitline{pPb 8.16 TeV}{Ch N_{trk}^{offline} #geq 250}", "Pt_v246veto_9", 0, 2.5)'
#

####  vetoJet20 vs vetoJet20eta20
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_6", "v_{2}{4} p_{T,jet}>20;v_{2}{4} p_{T,jet}>20 |#eta_{jet}|<2.0", "#splitline{pPb 8.16 TeV}{Ch 120 #leq N_{trk}^{offline} < 150}", "Pt_v24vetoJet20eta20_6", 0, 0.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20_merged2_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_7", "v_{2}{4} p_{T,jet}>20;v_{2}{4} p_{T,jet}>20 |#eta_{jet}|<2.0", "#splitline{pPb 8.16 TeV}{Ch 150 #leq N_{trk}^{offline} < 185}", "Pt_v24vetoJet20eta20_7", 0, 0.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20_merged2_corrected.root:grSig_pT2_1_8;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_8", "v_{2}{4} p_{T,jet}>20;v_{2}{4} p_{T,jet}>20 |#eta_{jet}|<2.0", "#splitline{pPb 8.16 TeV}{Ch 185 #leq N_{trk}^{offline} < 250}", "Pt_v24vetoJet20eta20_8", 0, 0.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20_merged2_corrected.root:grSig_pT2_1_9;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_9", "v_{2}{4} p_{T,jet}>20;v_{2}{4} p_{T,jet}>20 |#eta_{jet}|<2.0", "#splitline{pPb 8.16 TeV}{Ch N_{trk}^{offline} #geq 250}", "Pt_v24vetoJet20eta20_9", 0, 0.5)'
#

######## standard v24 vs vetoJet20eta20 vs vetoJet25eta20 vs vetoJet30eta20
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_vetoJet25eta20_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_vetoJet30eta20_merged2_corrected.root:grSig_pT2_1_6", "v_{2}{4};v_{2}{4} p_{T,jet}>20;v_{2}{4} p_{T,jet}>25;v_{2}{4} p_{T,jet}>30", "#splitline{pPb 8.16 TeV}{Ch 120 #leq N_{trk}^{offline} < 150}", "Pt_v24vetoJet_6", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_H_vetoJet25eta20_merged2_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_H_vetoJet30eta20_merged2_corrected.root:grSig_pT2_1_7", "v_{2}{4};v_{2}{4} p_{T,jet}>20;v_{2}{4} p_{T,jet}>25;v_{2}{4} p_{T,jet}>30", "#splitline{pPb 8.16 TeV}{Ch 150 #leq N_{trk}^{offline} < 185}", "Pt_v24vetoJet_7", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_1_8;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_8;../cumudiff/pPb_H_vetoJet25eta20_merged2_corrected.root:grSig_pT2_1_8;../cumudiff/pPb_H_vetoJet30eta20_merged2_corrected.root:grSig_pT2_1_8", "v_{2}{4};v_{2}{4} p_{T,jet}>20;v_{2}{4} p_{T,jet}>25;v_{2}{4} p_{T,jet}>30", "#splitline{pPb 8.16 TeV}{Ch 185 #leq N_{trk}^{offline} < 250}", "Pt_v24vetoJet_8", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_1_9;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_9;../cumudiff/pPb_H_vetoJet25eta20_merged2_corrected.root:grSig_pT2_1_9;../cumudiff/pPb_H_vetoJet30eta20_merged2_corrected.root:grSig_pT2_1_9", "v_{2}{4};v_{2}{4} p_{T,jet}>20;v_{2}{4} p_{T,jet}>25;v_{2}{4} p_{T,jet}>30", "#splitline{pPb 8.16 TeV}{Ch N_{trk}^{offline} #geq 250}",       "Pt_v24vetoJet_9", 0, 2.5)'
#
######## standard v26 vs vetoJet20eta20 vs vetoJet25eta20 vs vetoJet30eta20
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_2_6;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_2_6;../cumudiff/pPb_H_vetoJet25eta20_merged2_corrected.root:grSig_pT2_2_6;../cumudiff/pPb_H_vetoJet30eta20_merged2_corrected.root:grSig_pT2_2_6", "v_{2}{6};v_{2}{6} p_{T,jet}>20;v_{2}{6} p_{T,jet}>25;v_{2}{6} p_{T,jet}>30", "#splitline{pPb 8.16 TeV}{Ch 120 #leq N_{trk}^{offline} < 150}", "Pt_v26vetoJet_6", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_2_7;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_2_7;../cumudiff/pPb_H_vetoJet25eta20_merged2_corrected.root:grSig_pT2_2_7;../cumudiff/pPb_H_vetoJet30eta20_merged2_corrected.root:grSig_pT2_2_7", "v_{2}{6};v_{2}{6} p_{T,jet}>20;v_{2}{6} p_{T,jet}>25;v_{2}{6} p_{T,jet}>30", "#splitline{pPb 8.16 TeV}{Ch 150 #leq N_{trk}^{offline} < 185}", "Pt_v26vetoJet_7", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_2_8;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_2_8;../cumudiff/pPb_H_vetoJet25eta20_merged2_corrected.root:grSig_pT2_2_8;../cumudiff/pPb_H_vetoJet30eta20_merged2_corrected.root:grSig_pT2_2_8", "v_{2}{6};v_{2}{6} p_{T,jet}>20;v_{2}{6} p_{T,jet}>25;v_{2}{6} p_{T,jet}>30", "#splitline{pPb 8.16 TeV}{Ch 185 #leq N_{trk}^{offline} < 250}", "Pt_v26vetoJet_8", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_2_9;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_2_9;../cumudiff/pPb_H_vetoJet25eta20_merged2_corrected.root:grSig_pT2_2_9;../cumudiff/pPb_H_vetoJet30eta20_merged2_corrected.root:grSig_pT2_2_9", "v_{2}{6};v_{2}{6} p_{T,jet}>20;v_{2}{6} p_{T,jet}>25;v_{2}{6} p_{T,jet}>30", "#splitline{pPb 8.16 TeV}{Ch N_{trk}^{offline} #geq 250}",       "Pt_v26vetoJet_9", 0, 2.5)'
#
#
######### standard v22 vs vetoJet20eta20 vs vetoJet25eta20 vs vetoJet30eta20
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pTGap2_6;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pTGap2_6;../cumudiff/pPb_H_vetoJet25eta20_merged2_corrected.root:grSig_pTGap2_6;../cumudiff/pPb_H_vetoJet30eta20_merged2_corrected.root:grSig_pTGap2_6", "v_{2}{2};v_{2}{2} p_{T,jet}>20;v_{2}{2} p_{T,jet}>25;v_{2}{2} p_{T,jet}>30", "#splitline{pPb 8.16 TeV}{Ch 120 #leq N_{trk}^{offline} < 150}", "Pt_v22vetoJet_6", 0, 0.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pTGap2_7;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pTGap2_7;../cumudiff/pPb_H_vetoJet25eta20_merged2_corrected.root:grSig_pTGap2_7;../cumudiff/pPb_H_vetoJet30eta20_merged2_corrected.root:grSig_pTGap2_7", "v_{2}{2};v_{2}{2} p_{T,jet}>20;v_{2}{2} p_{T,jet}>25;v_{2}{2} p_{T,jet}>30", "#splitline{pPb 8.16 TeV}{Ch 150 #leq N_{trk}^{offline} < 185}", "Pt_v22vetoJet_7", 0, 0.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pTGap2_8;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pTGap2_8;../cumudiff/pPb_H_vetoJet25eta20_merged2_corrected.root:grSig_pTGap2_8;../cumudiff/pPb_H_vetoJet30eta20_merged2_corrected.root:grSig_pTGap2_8", "v_{2}{2};v_{2}{2} p_{T,jet}>20;v_{2}{2} p_{T,jet}>25;v_{2}{2} p_{T,jet}>30", "#splitline{pPb 8.16 TeV}{Ch 185 #leq N_{trk}^{offline} < 250}", "Pt_v22vetoJet_8", 0, 0.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pTGap2_9;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pTGap2_9;../cumudiff/pPb_H_vetoJet25eta20_merged2_corrected.root:grSig_pTGap2_9;../cumudiff/pPb_H_vetoJet30eta20_merged2_corrected.root:grSig_pTGap2_9", "v_{2}{2};v_{2}{2} p_{T,jet}>20;v_{2}{2} p_{T,jet}>25;v_{2}{2} p_{T,jet}>30", "#splitline{pPb 8.16 TeV}{Ch N_{trk}^{offline} #geq 250}",       "Pt_v22vetoJet_9", 0, 0.5)'

#
######## standard v24 vs vetoJet20eta20 vs vetoJet20eta16
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_vetoJet20eta16_merged2_corrected.root:grSig_pT2_1_6", "v_{2}{4};v_{2}{4} |#eta_{jet}|<2.0;v_{2}{4} |#eta_{jet}|<1.6", "#splitline{pPb 8.16 TeV}{Ch 120 #leq N_{trk}^{offline} < 150}", "Pt_v24eta_6", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_H_vetoJet20eta16_merged2_corrected.root:grSig_pT2_1_7", "v_{2}{4};v_{2}{4} |#eta_{jet}|<2.0;v_{2}{4} |#eta_{jet}|<1.6", "#splitline{pPb 8.16 TeV}{Ch 150 #leq N_{trk}^{offline} < 185}", "Pt_v24eta_7", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_1_8;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_8;../cumudiff/pPb_H_vetoJet20eta16_merged2_corrected.root:grSig_pT2_1_8", "v_{2}{4};v_{2}{4} |#eta_{jet}|<2.0;v_{2}{4} |#eta_{jet}|<1.6", "#splitline{pPb 8.16 TeV}{Ch 185 #leq N_{trk}^{offline} < 250}", "Pt_v24eta_8", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_1_9;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_9;../cumudiff/pPb_H_vetoJet20eta16_merged2_corrected.root:grSig_pT2_1_9", "v_{2}{4};v_{2}{4} |#eta_{jet}|<2.0;v_{2}{4} |#eta_{jet}|<1.6", "#splitline{pPb 8.16 TeV}{Ch N_{trk}^{offline} #geq 250}",       "Pt_v24eta_9", 0, 2.5)'
#
######## standard v24 vs Jet20eta20
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_Jet20eta20_merged2_corrected.root:grSig_pT2_1_6", "v_{2}{4};v_{2}{4} veto Jet;v_{2}{4} Jet Only", "#splitline{pPb 8.16 TeV}{Ch 120 #leq N_{trk}^{offline} < 150}", "Pt_v24Jet_6", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_H_Jet20eta20_merged2_corrected.root:grSig_pT2_1_7", "v_{2}{4};v_{2}{4} veto Jet;v_{2}{4} Jet Only", "#splitline{pPb 8.16 TeV}{Ch 150 #leq N_{trk}^{offline} < 185}", "Pt_v24Jet_7", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_1_8;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_8;../cumudiff/pPb_H_Jet20eta20_merged2_corrected.root:grSig_pT2_1_8", "v_{2}{4};v_{2}{4} veto Jet;v_{2}{4} Jet Only", "#splitline{pPb 8.16 TeV}{Ch 185 #leq N_{trk}^{offline} < 250}", "Pt_v24Jet_8", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_1_9;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_9;../cumudiff/pPb_H_Jet20eta20_merged2_corrected.root:grSig_pT2_1_9", "v_{2}{4};v_{2}{4} veto Jet;v_{2}{4} Jet Only", "#splitline{pPb 8.16 TeV}{Ch N_{trk}^{offline} #geq 250}",       "Pt_v24Jet_9", 0, 2.5)'
#
######## standard v26 vs Jet20eta20
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_2_6;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_2_6;../cumudiff/pPb_H_Jet20eta20_merged2_corrected.root:grSig_pT2_2_6", "v_{2}{6};v_{2}{6} veto Jet;v_{2}{6} Jet Only", "#splitline{pPb 8.16 TeV}{Ch 120 #leq N_{trk}^{offline} < 150}", "Pt_v26Jet_6", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_2_7;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_2_7;../cumudiff/pPb_H_Jet20eta20_merged2_corrected.root:grSig_pT2_2_7", "v_{2}{6};v_{2}{6} veto Jet;v_{2}{6} Jet Only", "#splitline{pPb 8.16 TeV}{Ch 150 #leq N_{trk}^{offline} < 185}", "Pt_v26Jet_7", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_2_8;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_2_8;../cumudiff/pPb_H_Jet20eta20_merged2_corrected.root:grSig_pT2_2_8", "v_{2}{6};v_{2}{6} veto Jet;v_{2}{6} Jet Only", "#splitline{pPb 8.16 TeV}{Ch 185 #leq N_{trk}^{offline} < 250}", "Pt_v26Jet_8", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_merged2_corrected.root:grSig_pT2_2_9;../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_2_9;../cumudiff/pPb_H_Jet20eta20_merged2_corrected.root:grSig_pT2_2_9", "v_{2}{6};v_{2}{6} veto Jet;v_{2}{6} Jet Only", "#splitline{pPb 8.16 TeV}{Ch N_{trk}^{offline} #geq 250}",       "Pt_v26Jet_9", 0, 2.5)'
#
######  vetoJet20eta20 vs vetoakPu3Jet20eta20 vs vetoak4Jet20eta20 v24
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_vetoakPu3Jet20eta20_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pT2_1_6", "v_{2}{4} akPu4PFJet;v_{2}{4} akPu3PFJet;v_{2}{4} ak4PFJet", "#splitline{pPb 8.16 TeV vetoJet20}{Ch 120 #leq N_{trk}^{offline} < 150}", "Pt_v4vetoJet_6", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_H_vetoakPu3Jet20eta20_merged2_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pT2_1_7", "v_{2}{4} akPu4PFJet;v_{2}{4} akPu3PFJet;v_{2}{4} ak4PFJet", "#splitline{pPb 8.16 TeV vetoJet20}{Ch 150 #leq N_{trk}^{offline} < 185}", "Pt_v4vetoJet_7", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_8;../cumudiff/pPb_H_vetoakPu3Jet20eta20_merged2_corrected.root:grSig_pT2_1_8;../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pT2_1_8", "v_{2}{4} akPu4PFJet;v_{2}{4} akPu3PFJet;v_{2}{4} ak4PFJet", "#splitline{pPb 8.16 TeV vetoJet20}{Ch 185 #leq N_{trk}^{offline} < 250}", "Pt_v4vetoJet_8", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_9;../cumudiff/pPb_H_vetoakPu3Jet20eta20_merged2_corrected.root:grSig_pT2_1_9;../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pT2_1_9", "v_{2}{4} akPu4PFJet;v_{2}{4} akPu3PFJet;v_{2}{4} ak4PFJet", "#splitline{pPb 8.16 TeV vetoJet20}{Ch N_{trk}^{offline} #geq 250}",       "Pt_v4vetoJet_9", 0, 2.5)'

######  vetoJet20eta20 vs vetoakPu3Jet20eta20 vs vetoak4Jet20eta20 v26
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_2_6;../cumudiff/pPb_H_vetoakPu3Jet20eta20_merged2_corrected.root:grSig_pT2_2_6;../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pT2_2_6", "v_{2}{6} akPu4PFJet;v_{2}{6} akPu3PFJet;v_{2}{6} ak4PFJet", "#splitline{pPb 8.16 TeV vetoJet20}{Ch 120 #leq N_{trk}^{offline} < 150}", "Pt_v6vetoJet_6", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_2_7;../cumudiff/pPb_H_vetoakPu3Jet20eta20_merged2_corrected.root:grSig_pT2_2_7;../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pT2_2_7", "v_{2}{6} akPu4PFJet;v_{2}{6} akPu3PFJet;v_{2}{6} ak4PFJet", "#splitline{pPb 8.16 TeV vetoJet20}{Ch 150 #leq N_{trk}^{offline} < 185}", "Pt_v6vetoJet_7", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_2_8;../cumudiff/pPb_H_vetoakPu3Jet20eta20_merged2_corrected.root:grSig_pT2_2_8;../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pT2_2_8", "v_{2}{6} akPu4PFJet;v_{2}{6} akPu3PFJet;v_{2}{6} ak4PFJet", "#splitline{pPb 8.16 TeV vetoJet20}{Ch 185 #leq N_{trk}^{offline} < 250}", "Pt_v6vetoJet_8", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_2_9;../cumudiff/pPb_H_vetoakPu3Jet20eta20_merged2_corrected.root:grSig_pT2_2_9;../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pT2_2_9", "v_{2}{6} akPu4PFJet;v_{2}{6} akPu3PFJet;v_{2}{6} ak4PFJet", "#splitline{pPb 8.16 TeV vetoJet20}{Ch N_{trk}^{offline} #geq 250}",       "Pt_v6vetoJet_9", 0, 2.5)'
#
#####  vetoJet20eta20 vs vetoakPu3Jet20eta20 vs vetoak4Jet20eta20 v22
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pTGap2_6;../cumudiff/pPb_H_vetoakPu3Jet20eta20_merged2_corrected.root:grSig_pTGap2_6;../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pTGap2_6", "v_{2}{2} akPu4PFJet;v_{2}{2} akPu3PFJet;v_{2}{2} ak4PFJet", "#splitline{pPb 8.16 TeV vetoJet20}{Ch 120 #leq N_{trk}^{offline} < 150}", "Pt_v2vetoJet_6", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pTGap2_7;../cumudiff/pPb_H_vetoakPu3Jet20eta20_merged2_corrected.root:grSig_pTGap2_7;../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pTGap2_7", "v_{2}{2} akPu4PFJet;v_{2}{2} akPu3PFJet;v_{2}{2} ak4PFJet", "#splitline{pPb 8.16 TeV vetoJet20}{Ch 150 #leq N_{trk}^{offline} < 185}", "Pt_v2vetoJet_7", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pTGap2_8;../cumudiff/pPb_H_vetoakPu3Jet20eta20_merged2_corrected.root:grSig_pTGap2_8;../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pTGap2_8", "v_{2}{2} akPu4PFJet;v_{2}{2} akPu3PFJet;v_{2}{2} ak4PFJet", "#splitline{pPb 8.16 TeV vetoJet20}{Ch 185 #leq N_{trk}^{offline} < 250}", "Pt_v2vetoJet_8", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pTGap2_9;../cumudiff/pPb_H_vetoakPu3Jet20eta20_merged2_corrected.root:grSig_pTGap2_9;../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pTGap2_9", "v_{2}{2} akPu4PFJet;v_{2}{2} akPu3PFJet;v_{2}{2} ak4PFJet", "#splitline{pPb 8.16 TeV vetoJet20}{Ch N_{trk}^{offline} #geq 250}",       "Pt_v2vetoJet_9", 0, 2.5)'

####### vetoak4Jet20eta20 v22 vs v24 vs v26
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pT2_2_6;../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pTGap2_6", "v_{2}{4};v_{2}{6};v_{2}{2}", "#splitline{pPb 8.16 TeV vetoak4PfJet20}{Ch 120 #leq N_{trk}^{offline} < 150}", "Pt_vetoak4Jet_6", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pT2_2_7;../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pTGap2_7", "v_{2}{4};v_{2}{6};v_{2}{2}", "#splitline{pPb 8.16 TeV vetoak4PfJet20}{Ch 150 #leq N_{trk}^{offline} < 185}", "Pt_vetoak4Jet_7", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pT2_1_8;../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pT2_2_8;../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pTGap2_8", "v_{2}{4};v_{2}{6};v_{2}{2}", "#splitline{pPb 8.16 TeV vetoak4PfJet20}{Ch 185 #leq N_{trk}^{offline} < 250}", "Pt_vetoak4Jet_8", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pT2_1_9;../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pT2_2_9;../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pTGap2_9", "v_{2}{4};v_{2}{6};v_{2}{2}", "#splitline{pPb 8.16 TeV vetoak4PfJet20}{Ch N_{trk}^{offline} #geq 250}",       "Pt_vetoak4Jet_9", 0, 2.5)'
#
#### vetoakPu4Jet20eta20 vs vetoak4Jet20eta20 v24
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pT2_1_6", "v_{2}{4} akPu4;v_{2}{4} ak4", "#splitline{pPb 8.16 TeV}{Ch 120 #leq N_{trk}^{offline} < 150}", "Pt_v4vetoPu_6", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pT2_1_7", "v_{2}{4} akPu4;v_{2}{4} ak4", "#splitline{pPb 8.16 TeV}{Ch 150 #leq N_{trk}^{offline} < 185}", "Pt_v4vetoPu_7", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_8;../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pT2_1_8", "v_{2}{4} akPu4;v_{2}{4} ak4", "#splitline{pPb 8.16 TeV}{Ch 185 #leq N_{trk}^{offline} < 250}", "Pt_v4vetoPu_8", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_9;../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pT2_1_9", "v_{2}{4} akPu4;v_{2}{4} ak4", "#splitline{pPb 8.16 TeV}{Ch N_{trk}^{offline} #geq 250}",       "Pt_v4vetoPu_9", 0, 2.5)'
#
#### vetoakPu4Jet20eta20 vs vetoak4Jet20eta20 v26
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_2_6;../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pT2_2_6", "v_{2}{6} akPu4;v_{2}{6} ak4", "#splitline{pPb 8.16 TeV}{Ch 120 #leq N_{trk}^{offline} < 150}", "Pt_v6vetoPu_6", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_2_7;../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pT2_2_7", "v_{2}{6} akPu4;v_{2}{6} ak4", "#splitline{pPb 8.16 TeV}{Ch 150 #leq N_{trk}^{offline} < 185}", "Pt_v6vetoPu_7", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_2_8;../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pT2_2_8", "v_{2}{6} akPu4;v_{2}{6} ak4", "#splitline{pPb 8.16 TeV}{Ch 185 #leq N_{trk}^{offline} < 250}", "Pt_v6vetoPu_8", 0, 2.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_2_9;../cumudiff/pPb_H_vetoak4Jet20eta20_merged2_corrected.root:grSig_pT2_2_9", "v_{2}{6} akPu4;v_{2}{6} ak4", "#splitline{pPb 8.16 TeV}{Ch N_{trk}^{offline} #geq 250}",       "Pt_v6vetoPu_9", 0, 2.5)'


#### vetoakPu4Jet20eta20 vs vetoakPu4Jet21eta20 v24
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_vetoakPu4Jet21eta20_merged2_corrected.root:grSig_pT2_1_6", "v_{2}{4} p_{T,jet}>20;v_{2}{4} p_{T,jet}>21", "#splitline{pPb 8.16 TeV}{Ch 120 #leq N_{trk}^{offline} < 150}", "Pt_v4sysvetoJet_6", 0, 0.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_H_vetoakPu4Jet21eta20_merged2_corrected.root:grSig_pT2_1_7", "v_{2}{4} p_{T,jet}>20;v_{2}{4} p_{T,jet}>21", "#splitline{pPb 8.16 TeV}{Ch 150 #leq N_{trk}^{offline} < 185}", "Pt_v4sysvetoJet_7", 0, 0.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_8;../cumudiff/pPb_H_vetoakPu4Jet21eta20_merged2_corrected.root:grSig_pT2_1_8", "v_{2}{4} p_{T,jet}>20;v_{2}{4} p_{T,jet}>21", "#splitline{pPb 8.16 TeV}{Ch 185 #leq N_{trk}^{offline} < 250}", "Pt_v4sysvetoJet_8", 0, 0.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_9;../cumudiff/pPb_H_vetoakPu4Jet21eta20_merged2_corrected.root:grSig_pT2_1_9", "v_{2}{4} p_{T,jet}>20;v_{2}{4} p_{T,jet}>21", "#splitline{pPb 8.16 TeV}{Ch N_{trk}^{offline} #geq 250}",       "Pt_v4sysvetoJet_9", 0, 0.5)'
#
#### vetoakPu4Jet20eta20 vs vetoakPu4Jet21eta20 v26
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_2_6;../cumudiff/pPb_H_vetoakPu4Jet21eta20_merged2_corrected.root:grSig_pT2_2_6", "v_{2}{6} p_{T,jet}>20;v_{2}{6} p_{T,jet}>21", "#splitline{pPb 8.16 TeV}{Ch 120 #leq N_{trk}^{offline} < 150}", "Pt_v6sysvetoJet_6", 0, 0.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_2_7;../cumudiff/pPb_H_vetoakPu4Jet21eta20_merged2_corrected.root:grSig_pT2_2_7", "v_{2}{6} p_{T,jet}>20;v_{2}{6} p_{T,jet}>21", "#splitline{pPb 8.16 TeV}{Ch 150 #leq N_{trk}^{offline} < 185}", "Pt_v6sysvetoJet_7", 0, 0.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_2_8;../cumudiff/pPb_H_vetoakPu4Jet21eta20_merged2_corrected.root:grSig_pT2_2_8", "v_{2}{6} p_{T,jet}>20;v_{2}{6} p_{T,jet}>21", "#splitline{pPb 8.16 TeV}{Ch 185 #leq N_{trk}^{offline} < 250}", "Pt_v6sysvetoJet_8", 0, 0.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_2_9;../cumudiff/pPb_H_vetoakPu4Jet21eta20_merged2_corrected.root:grSig_pT2_2_9", "v_{2}{6} p_{T,jet}>20;v_{2}{6} p_{T,jet}>21", "#splitline{pPb 8.16 TeV}{Ch N_{trk}^{offline} #geq 250}",       "Pt_v6sysvetoJet_9", 0, 0.5)'
#


### Ks v24 standard vs vetoakPu4Jet20eta20
root -l -b -q 'plotS.C("../cumudiff/pPb_Ks2_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_Ks_vetoakPu4Jet20eta20_merged2_corrected.root:grSig_pT2_1_6", "v_{2}{4} standard;v_{2}{4} vetoJet20", "#splitline{pPb 8.16 TeV}{K_{S}^{0} 120 #leq N_{trk}^{offline} < 150}", "Ks_v4vetoJet20_6", 0, 2.5)'
root -l -b -q 'plotS.C("../cumudiff/pPb_Ks2_merged2_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_Ks_vetoakPu4Jet20eta20_merged2_corrected.root:grSig_pT2_1_7", "v_{2}{4} standard;v_{2}{4} vetoJet20", "#splitline{pPb 8.16 TeV}{K_{S}^{0} 150 #leq N_{trk}^{offline} < 185}", "Ks_v4vetoJet20_7", 0, 2.5)'
root -l -b -q 'plotS.C("../cumudiff/pPb_Ks2_merged2_corrected.root:grSig_pT2_1_8;../cumudiff/pPb_Ks_vetoakPu4Jet20eta20_merged2_corrected.root:grSig_pT2_1_8", "v_{2}{4} standard;v_{2}{4} vetoJet20", "#splitline{pPb 8.16 TeV}{K_{S}^{0} 185 #leq N_{trk}^{offline} < 250}", "Ks_v4vetoJet20_8", 0, 2.5)'
root -l -b -q 'plotS.C("../cumudiff/pPb_Ks2_merged2_corrected.root:grSig_pT2_1_9;../cumudiff/pPb_Ks_vetoakPu4Jet20eta20_merged2_corrected.root:grSig_pT2_1_9", "v_{2}{4} standard;v_{2}{4} vetoJet20", "#splitline{pPb 8.16 TeV}{K_{S}^{0} N_{trk}^{offline} #geq 250}",       "Ks_v4vetoJet20_9", 0, 2.5)'

### Ks v26 standard vs vetoakPu4Jet20eta20
root -l -b -q 'plotS.C("../cumudiff/pPb_Ks2_merged2_corrected.root:grSig_pT2_2_6;../cumudiff/pPb_Ks_vetoakPu4Jet20eta20_merged2_corrected.root:grSig_pT2_2_6", "v_{2}{6} standard;v_{2}{6} vetoJet20", "#splitline{pPb 8.16 TeV}{K_{S}^{0} 120 #leq N_{trk}^{offline} < 150}", "Ks_v6vetoJet20_6", 0, 2.5)'
root -l -b -q 'plotS.C("../cumudiff/pPb_Ks2_merged2_corrected.root:grSig_pT2_2_7;../cumudiff/pPb_Ks_vetoakPu4Jet20eta20_merged2_corrected.root:grSig_pT2_2_7", "v_{2}{6} standard;v_{2}{6} vetoJet20", "#splitline{pPb 8.16 TeV}{K_{S}^{0} 150 #leq N_{trk}^{offline} < 185}", "Ks_v6vetoJet20_7", 0, 2.5)'
root -l -b -q 'plotS.C("../cumudiff/pPb_Ks2_merged2_corrected.root:grSig_pT2_2_8;../cumudiff/pPb_Ks_vetoakPu4Jet20eta20_merged2_corrected.root:grSig_pT2_2_8", "v_{2}{6} standard;v_{2}{6} vetoJet20", "#splitline{pPb 8.16 TeV}{K_{S}^{0} 185 #leq N_{trk}^{offline} < 250}", "Ks_v6vetoJet20_8", 0, 2.5)'
root -l -b -q 'plotS.C("../cumudiff/pPb_Ks2_merged2_corrected.root:grSig_pT2_2_9;../cumudiff/pPb_Ks_vetoakPu4Jet20eta20_merged2_corrected.root:grSig_pT2_2_9", "v_{2}{6} standard;v_{2}{6} vetoJet20", "#splitline{pPb 8.16 TeV}{K_{S}^{0} N_{trk}^{offline} #geq 250}",       "Ks_v6vetoJet20_9", 0, 2.5)'

### Lm v24 standard vs vetoakPu4Jet20eta20
root -l -b -q 'plotS.C("../cumudiff/pPb_Lm2_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_Lm_vetoakPu4Jet20eta20_merged2_corrected.root:grSig_pT2_1_6", "v_{2}{4} standard;v_{2}{4} vetoJet20", "#splitline{pPb 8.16 TeV}{#Lambda 120 #leq N_{trk}^{offline} < 150}", "Lm_v4vetoJet20_6", 0, 2.5)'
root -l -b -q 'plotS.C("../cumudiff/pPb_Lm2_merged2_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_Lm_vetoakPu4Jet20eta20_merged2_corrected.root:grSig_pT2_1_7", "v_{2}{4} standard;v_{2}{4} vetoJet20", "#splitline{pPb 8.16 TeV}{#Lambda 150 #leq N_{trk}^{offline} < 185}", "Lm_v4vetoJet20_7", 0, 2.5)'
root -l -b -q 'plotS.C("../cumudiff/pPb_Lm2_merged2_corrected.root:grSig_pT2_1_8;../cumudiff/pPb_Lm_vetoakPu4Jet20eta20_merged2_corrected.root:grSig_pT2_1_8", "v_{2}{4} standard;v_{2}{4} vetoJet20", "#splitline{pPb 8.16 TeV}{#Lambda 185 #leq N_{trk}^{offline} < 250}", "Lm_v4vetoJet20_8", 0, 2.5)'
root -l -b -q 'plotS.C("../cumudiff/pPb_Lm2_merged2_corrected.root:grSig_pT2_1_9;../cumudiff/pPb_Lm_vetoakPu4Jet20eta20_merged2_corrected.root:grSig_pT2_1_9", "v_{2}{4} standard;v_{2}{4} vetoJet20", "#splitline{pPb 8.16 TeV}{#Lambda N_{trk}^{offline} #geq 250}",       "Lm_v4vetoJet20_9", 0, 2.5)'

### Lm v26 standard vs vetoakPu4Jet20eta20
root -l -b -q 'plotS.C("../cumudiff/pPb_Lm2_merged2_corrected.root:grSig_pT2_2_6;../cumudiff/pPb_Lm_vetoakPu4Jet20eta20_merged2_corrected.root:grSig_pT2_2_6", "v_{2}{6} standard;v_{2}{6} vetoJet20", "#splitline{pPb 8.16 TeV}{#Lambda 120 #leq N_{trk}^{offline} < 150}", "Lm_v6vetoJet20_6", 0, 2.5)'
root -l -b -q 'plotS.C("../cumudiff/pPb_Lm2_merged2_corrected.root:grSig_pT2_2_7;../cumudiff/pPb_Lm_vetoakPu4Jet20eta20_merged2_corrected.root:grSig_pT2_2_7", "v_{2}{6} standard;v_{2}{6} vetoJet20", "#splitline{pPb 8.16 TeV}{#Lambda 150 #leq N_{trk}^{offline} < 185}", "Lm_v6vetoJet20_7", 0, 2.5)'
root -l -b -q 'plotS.C("../cumudiff/pPb_Lm2_merged2_corrected.root:grSig_pT2_2_8;../cumudiff/pPb_Lm_vetoakPu4Jet20eta20_merged2_corrected.root:grSig_pT2_2_8", "v_{2}{6} standard;v_{2}{6} vetoJet20", "#splitline{pPb 8.16 TeV}{#Lambda 185 #leq N_{trk}^{offline} < 250}", "Lm_v6vetoJet20_8", 0, 2.5)'
root -l -b -q 'plotS.C("../cumudiff/pPb_Lm2_merged2_corrected.root:grSig_pT2_2_9;../cumudiff/pPb_Lm_vetoakPu4Jet20eta20_merged2_corrected.root:grSig_pT2_2_9", "v_{2}{6} standard;v_{2}{6} vetoJet20", "#splitline{pPb 8.16 TeV}{#Lambda N_{trk}^{offline} #geq 250}",       "Lm_v6vetoJet20_9", 0, 2.5)'

#### vetoakPu4Jet20eta20 JER v24
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_6;../cumudiff/pPb_H_vetoakPu4Jet20eta20_JER_merged2_corrected.root:grSig_pT2_1_6", "v_{2}{4,veto};v_{2}{4,veto} JER 20\%", "#splitline{pPb 8.16 TeV}{Ch 120 #leq N_{trk}^{offline} < 150}", "Pt_v4sysvetoJetJER_6", 0, 0.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_7;../cumudiff/pPb_H_vetoakPu4Jet20eta20_JER_merged2_corrected.root:grSig_pT2_1_7", "v_{2}{4,veto};v_{2}{4,veto} JER 20\%", "#splitline{pPb 8.16 TeV}{Ch 150 #leq N_{trk}^{offline} < 185}", "Pt_v4sysvetoJetJER_7", 0, 0.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_8;../cumudiff/pPb_H_vetoakPu4Jet20eta20_JER_merged2_corrected.root:grSig_pT2_1_8", "v_{2}{4,veto};v_{2}{4,veto} JER 20\%", "#splitline{pPb 8.16 TeV}{Ch 185 #leq N_{trk}^{offline} < 250}", "Pt_v4sysvetoJetJER_8", 0, 0.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_1_9;../cumudiff/pPb_H_vetoakPu4Jet20eta20_JER_merged2_corrected.root:grSig_pT2_1_9", "v_{2}{4,veto};v_{2}{4,veto} JER 20\%", "#splitline{pPb 8.16 TeV}{Ch N_{trk}^{offline} #geq 250}",       "Pt_v4sysvetoJetJER_9", 0, 0.5)'
#
#### vetoakPu4Jet20eta20 JER v26
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_2_6;../cumudiff/pPb_H_vetoakPu4Jet20eta20_JER_merged2_corrected.root:grSig_pT2_2_6", "v_{2}{6,veto};v_{2}{6,veto} JER 20\%", "#splitline{pPb 8.16 TeV}{Ch 120 #leq N_{trk}^{offline} < 150}", "Pt_v6sysvetoJetJER_6", 0, 0.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_2_7;../cumudiff/pPb_H_vetoakPu4Jet20eta20_JER_merged2_corrected.root:grSig_pT2_2_7", "v_{2}{6,veto};v_{2}{6,veto} JER 20\%", "#splitline{pPb 8.16 TeV}{Ch 150 #leq N_{trk}^{offline} < 185}", "Pt_v6sysvetoJetJER_7", 0, 0.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_2_8;../cumudiff/pPb_H_vetoakPu4Jet20eta20_JER_merged2_corrected.root:grSig_pT2_2_8", "v_{2}{6,veto};v_{2}{6,veto} JER 20\%", "#splitline{pPb 8.16 TeV}{Ch 185 #leq N_{trk}^{offline} < 250}", "Pt_v6sysvetoJetJER_8", 0, 0.5)'
#root -l -b -q 'plotS.C("../cumudiff/pPb_H_vetoJet20eta20_merged2_corrected.root:grSig_pT2_2_9;../cumudiff/pPb_H_vetoakPu4Jet20eta20_JER_merged2_corrected.root:grSig_pT2_2_9", "v_{2}{6,veto};v_{2}{6,veto} JER 20\%", "#splitline{pPb 8.16 TeV}{Ch N_{trk}^{offline} #geq 250}",       "Pt_v6sysvetoJetJER_9", 0, 0.5)'
#
#
