

root -l -b -q 'plotS.C("pPb_Ks2.root:grV0v2sub4pos_8;pPb_Ks2_reverse.root:grV0v2sub4neg_8;pPb_Ks2_merged2.root:grV0v2sub4pos_8", "K_{S}^{0} pPb v_{2}^{Obs}{4, 2sbu} Pb-side;K_{S}^{0} Pbp v_{2}^{Obs}{4, 2sub} Pb-side;K_{S}^{0} pPb+Pbp v_{2}^{Obs}{4, 2sub} Pb-side", "185 #leq N_{trk}^{offline} < 250", "Ks_v24_Pb")'

root -l -b -q 'plotS.C("pPb_Ks2.root:grV0v2sub4neg_8;pPb_Ks2_reverse.root:grV0v2sub4pos_8;pPb_Ks2_merged2.root:grV0v2sub4neg_8", "K_{S}^{0} pPb v_{2}^{Obs}{4, 2sbu} p-side;K_{S}^{0} Pbp v_{2}^{Obs}{4, 2sub} p-side;K_{S}^{0} pPb+Pbp v_{2}^{Obs}{4, 2sub} p-side", "185 #leq N_{trk}^{offline} < 250", "Ks_v24_p")'



root -l -b -q 'plotS.C("pPb_Lm2.root:grV0v2sub4pos_8;pPb_Lm2_reverse.root:grV0v2sub4neg_8;pPb_Lm2_merged2.root:grV0v2sub4pos_8", "#Lambda pPb v_{2}^{Obs}{4, 2sub} Pb-side;#Lambda Pbp v_{2}^{Obs}{4, 2sub} Pb-side;#Lambda pPb+Pbp v_{2}^{Obs}{4, 2sub} Pb-side", "185 #leq N_{trk}^{offline} < 250", "Lm_v24_Pb")'

root -l -b -q 'plotS.C("pPb_Lm2.root:grV0v2sub4neg_8;pPb_Lm2_reverse.root:grV0v2sub4pos_8;pPb_Lm2_merged2.root:grV0v2sub4neg_8", "#Lambda pPb v_{2}^{Obs}{4, 2sub} p-side;#Lambda Pbp v_{2}^{Obs}{4, 2sub} p-side;#Lambda pPb+Pbp v_{2}^{Obs}{4, 2sub} p-side", "185 #leq N_{trk}^{offline} < 250", "Lm_v24_p")'



root -l -b -q 'plotS.C("pPb_Ks2_SB.root:grV0v2sub4pos_8;pPb_Ks2_SB_reverse.root:grV0v2sub4neg_8;pPb_Ks2_SB_merged2.root:grV0v2sub4pos_8", "K_{S}^{0} pPb v_{2}^{Bkg}{4, 2sub} Pb-side;K_{S}^{0} Pbp v_{2}^{Bkg}{4, 2sub} Pb-side;K_{S}^{0} pPb+Pbp v_{2}^{Bkg}{4, 2sub} Pb-side", "185 #leq N_{trk}^{offline} < 250", "Ks_v24SB_Pb")'

root -l -b -q 'plotS.C("pPb_Ks2_SB.root:grV0v2sub4neg_8;pPb_Ks2_SB_reverse.root:grV0v2sub4pos_8;pPb_Ks2_SB_merged2.root:grV0v2sub4neg_8", "K_{S}^{0} pPb v_{2}^{Bkg}{4, 2sub} p-side;K_{S}^{0} Pbp v_{2}^{Bkg}{4, 2sub} p-side;K_{S}^{0} pPb+Pbp v_{2}^{Bkg}{4, 2sub} p-side", "185 #leq N_{trk}^{offline} < 250", "Ks_v24SB_p")'



root -l -b -q 'plotS.C("pPb_Lm2_SB.root:grV0v2sub4pos_8;pPb_Lm2_SB_reverse.root:grV0v2sub4neg_8;pPb_Lm2_SB_merged2.root:grV0v2sub4pos_8", "#Lambda pPb v_{2}^{Bkg}{4, 2sub} Pb-side;#Lambda Pbp v_{2}^{Bkg}{4, 2sub} Pb-side;#Lambda pPb+Pbp v_{2}^{Bkg}{4, 2sub} Pb-side", "185 #leq N_{trk}^{offline} < 250", "Lm_v24SB_Pb")'

root -l -b -q 'plotS.C("pPb_Lm2_SB.root:grV0v2sub4neg_8;pPb_Lm2_SB_reverse.root:grV0v2sub4pos_8;pPb_Lm2_SB_merged2.root:grV0v2sub4neg_8", "#Lambda pPb v_{2}^{Bkg}{4, 2sub} p-side;#Lambda Pbp v_{2}^{Bkg}{4, 2sub} p-side;p#Lambda pPb+Pbp v_{2}^{Bkg}{4, 2sub} p-side", "185 #leq N_{trk}^{offline} < 250", "Lm_v24SB_p")'


root -l -b -q 'plotS.C("pPb_H.root:grV0v2sub4pos_8;pPb_H_reverse.root:grV0v2sub4neg_8;pPb_H_merged2.root:grV0v2sub4pos_8", "ch pPb v_{2}{4, 2sub} Pb-side;ch Pbp v_{2}{4, 2sub} Pb-side;ch pPb+Pbp v_{2}{4, 2sub} Pb-side", "185 #leq N_{trk}^{offline} < 250", "H_v24_Pb")'
root -l -b -q 'plotS.C("pPb_H.root:grV0v2sub4neg_8;pPb_H_reverse.root:grV0v2sub4pos_8;pPb_H_merged2.root:grV0v2sub4neg_8", "ch pPb v_{2}{4, 2sub} p-side;ch Pbp v_{2}{4, 2sub} p-side;ch pPb+Pbp v_{2}{4, 2sub} p-side", "185 #leq N_{trk}^{offline} < 250", "H_v24_p")'




#root -l -b -q 'plotS.C("pPb_Ks2_merged2_corrected.root:grSig_V2sub4pos_8;pPb_Ks2_merged2_corrected.root:grSig_V2sub4neg_8;pPb_Ks2_merged2_corrected.root:grSig_V2sub4merge_8", "K_{S}^{0} v_{2}^{Sig}{4, 2sub} Pb-side;K_{S}^{0} v_{2}^{Sig}{4, 2sub} p-side;K_{S}^{0} v_{2}^{Sig}{4, 2sub} merged", "185 #leq N_{trk}^{offline} < 250", "Ks_v24_Sig")'

root -l -b -q 'plotS.C("pPb_Lm2_merged2_corrected.root:grSig_V2sub4pos_8;pPb_Lm2_merged2_corrected.root:grSig_V2sub4neg_8;pPb_Lm2_merged2_corrected.root:grSig_V2sub4merge_8", "#Lambda v_{2}^{Sig}{4, 2sub} Pb-side;#Lambda v_{2}^{Sig}{4, 2sub} p-side;#Lambda v_{2}^{Sig}{4, 2sub} merged", "185 #leq N_{trk}^{offline} < 250", "Lm_v24_Sig")'

root -l -b -q 'plotS.C("pPb_H_merged2_corrected.root:grSig_V2sub4pos_8;pPb_H_merged2_corrected.root:grSig_V2sub4neg_8;pPb_H_merged2_corrected.root:grSig_V2sub4merge_8", "ch v_{2}{4, 2sub} Pb-side;ch v_{2}{4, 2sub} Pb-side;ch v_{2}{4, 2sub} merged", "185 #leq N_{trk}^{offline} < 250", "H_v24_Sig")'


root -l -b -q 'plotS.C("V0SP.root:Ks_pPb_corrected_8/vn_NegEta_PosEtaEP_SubEvt;V0SP.root:Ks_pPb_corrected_8/vn_PosEta_NegEtaEP_SubEvt", "v_{2}^{Sig}{p-SP};v_{2}^{Sig}{Pb-SP}", "#splitline{K_{S}^{0}}{185 #leq N_{trk}^{offline} < 250}", "Ks_v2sp")'

root -l -b -q 'plotS.C("V0SP.root:Lm_pPb_corrected_8/vn_NegEta_PosEtaEP_SubEvt;V0SP.root:Lm_pPb_corrected_8/vn_PosEta_NegEtaEP_SubEvt", "#Lambda v_{2}^{Sig}{p-SP};#Lambda v_{2}^{Sig}{Pb-SP}", "185 #leq N_{trk}^{offline} < 250", "Lm_v2sp")'

root -l -b -q 'plotS.C("V0SP.root:ch_pPb_corrected_8/vn_NegEta_PosEtaEP_SubEvt;V0SP.root:ch_pPb_corrected_8/vn_PosEta_NegEtaEP_SubEvt", "ch v_{2}^{Sig}{p-SP};ch v_{2}^{Sig}{Pb-SP}", "#splitline{ch v_{2}^{Sig} SP}{185 #leq N_{trk}^{offline} < 250}", "H_v2sp")'







root -l -b -q 'plotS.C("V0SP.root:Ks_pPb_corrected_8/vn_NegEta_PosEtaEP_SubEvt;pPb_Ks2_merged2_corrected.root:grSig_V2sub4pos_8;pPb_Ks2_merged2_corrected.root:grSig_pT2_1_8", "v_{2}^{Sig}{p-SP};v_{2}^{Sig}{4, 2sub} Pb-side;v_{2}^{Sig}{4} std", "#splitline{Pb-Side K_{S}^{0}}{185 #leq N_{trk}^{offline} < 250}", "Ks_PbSide")'

root -l -b -q 'plotS.C("V0SP.root:Ks_pPb_corrected_8/vn_PosEta_NegEtaEP_SubEvt;pPb_Ks2_merged2_corrected.root:grSig_V2sub4neg_8;pPb_Ks2_merged2_corrected.root:grSig_pT2_1_8", "v_{2}^{Sig}{Pb-SP};v_{2}^{Sig}{4, 2sub} p-side;v_{2}^{Sig}{4} std", "#splitline{p-Side K_{S}^{0}}{185 #leq N_{trk}^{offline} < 250}", "Ks_pSide")'





root -l -b -q 'plotS.C("V0SP.root:Lm_pPb_corrected_8/vn_NegEta_PosEtaEP_SubEvt;pPb_Lm2_merged2_corrected.root:grSig_V2sub4pos_8;pPb_Lm2_merged2_corrected.root:grSig_pT2_1_8", "v_{2}^{Sig}{p-SP};v_{2}^{Sig}{4, 2sub} Pb-side;v_{2}^{Sig}{4} std", "#splitline{Pb-Side #Lambda}{185 #leq N_{trk}^{offline} < 250}", "Lm_PbSide")'

root -l -b -q 'plotS.C("V0SP.root:Lm_pPb_corrected_8/vn_PosEta_NegEtaEP_SubEvt;pPb_Lm2_merged2_corrected.root:grSig_V2sub4neg_8;pPb_Lm2_merged2_corrected.root:grSig_pT2_1_8", "v_{2}^{Sig}{Pb-SP};v_{2}^{Sig}{4, 2sub} p-side;v_{2}^{Sig}{4} std", "#splitline{p-Side #Lambda}{185 #leq N_{trk}^{offline} < 250}", "Lm_pSide")'





root -l -b -q 'plotS.C("V0SP.root:ch_pPb_corrected_8/vn_NegEta_PosEtaEP_SubEvt;pPb_H_merged2_corrected.root:grSig_V2sub4pos_8;pPb_H_merged2_corrected.root:grSig_pT2_1_8", "v_{2}^{Sig}{p-SP};v_{2}^{Sig}{4, 2sub} Pb-side;v_{2}^{Sig}{4} std", "#splitline{Pb-Side ch}{185 #leq N_{trk}^{offline} < 250}", "H_PbSide")'

root -l -b -q 'plotS.C("V0SP.root:ch_pPb_corrected_8/vn_PosEta_NegEtaEP_SubEvt;pPb_H_merged2_corrected.root:grSig_V2sub4neg_8;pPb_H_merged2_corrected.root:grSig_pT2_1_8", "v_{2}^{Sig}{Pb-SP};v_{2}^{Sig}{4, 2sub} p-side;v_{2}^{Sig}{4} std", "#splitline{p-Side ch}{185 #leq N_{trk}^{offline} < 250}", "H_pSide")'


root -l -b -q 'plotS.C("pPb_H_merged2_corrected.root:grSig_V2sub4neg_8;pPb_H_merged2_corrected.root:grSig_V2sub4pos_8;pPb_H_merged2_corrected.root:grSig_pT2_1_8", "v_{2}^{Sig}{4, 2sub} p-side;v_{2}^{Sig}{4, 2sub} Pb-side;v_{2}^{Sig}{4} std", "#splitline{ch v_{2}}{185 #leq N_{trk}^{offline} < 250}", "H_v2sub")'


root -l -b -q 'plotS.C("pPb_Ks2_merged2_corrected.root:grSig_V2sub4pos_8;pPb_Ks2_merged2_corrected.root:grSig_V2sub4neg_8;pPb_Ks2_merged2_corrected.root:grSig_pT2_1_8", "v_{2}^{Sig}{4, 2sub} Pb-side;v_{2}^{Sig}{4, 2sub} p-side;v_{2}^{Sig}{4} std", "#splitline{K_{S}^{0}}{185 #leq N_{trk}^{offline} < 250}", "Ks_v24_Sig")'

root -l -b -q 'plotS.C("pPb_Lm2_merged2_corrected.root:grSig_V2sub4pos_8;pPb_Lm2_merged2_corrected.root:grSig_V2sub4neg_8;pPb_Lm2_merged2_corrected.root:grSig_pT2_1_8", "v_{2}^{Sig}{4, 2sub} Pb-side;v_{2}^{Sig}{4, 2sub} p-side;v_{2}^{Sig}{4} std", "#splitline{#Lambda}{185 #leq N_{trk}^{offline} < 250}", "Lm_v24_Sig")'
