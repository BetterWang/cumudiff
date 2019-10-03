
void copyTree(string inroot, string outroot, string cut)
{
    TChain * ch = new TChain("tree");
//    ch->Add("HydjetMCTruth_LM.root/tree");
//    TFile * fout = new TFile("HydjetMCTruth_LM_0_10_10_22.root", "recreate");
//    TTree * tr = ch->CopyTree("Cent<20 && pt>1.0 && pt<2.2");
    ch->Add(inroot.c_str());
    TFile * fout = new TFile(outroot.c_str(), "recreate");
    TTree * tr = ch->CopyTree(cut.c_str(), "", 1000000);
    fout->Write();
}
