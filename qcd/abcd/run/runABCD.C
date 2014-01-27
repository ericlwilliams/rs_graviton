void runABCD(){
  string file_loc = "/Users/elw/Dropbox/eMacs/analy/lvjj/files/skims/";
  TChain* dataChain = new TChain("analysisTree");
  string data_loc = file_loc+"merged/data.lnuj.skim.root";
  dataChain->Add(data_loc.c_str());
  dataChain->Process("../src/abcd.C+","data");

  TChain* qcdChain = new TChain("analysisTree");
  string qcd_loc = file_loc+"qcd.muon.pu.skim.root";
  qcdChain->Add(qcd_loc.c_str());
  qcdChain->Process("../src/abcd.C+","qcd");

  const int nWjets= 6;
  string wjets_file_start = file_loc+"mc.alpgen.w";
  string wjets_file_middle ="nu.np";
  string wjets_file_end =".pu.skim.root";  
  string wjets_skims[nWjets] =
    {wjets_file_start+"u"+wjets_file_middle+"0"+wjets_file_end,
     wjets_file_start+"u"+wjets_file_middle+"1"+wjets_file_end,
     wjets_file_start+"u"+wjets_file_middle+"2"+wjets_file_end,
     wjets_file_start+"u"+wjets_file_middle+"3"+wjets_file_end,
     wjets_file_start+"u"+wjets_file_middle+"4"+wjets_file_end,
     wjets_file_start+"u"+wjets_file_middle+"5"+wjets_file_end};

  TChain *wjetsChain = new TChain("analysisTree");
  for(int w=0;w<nWjets;w++){
    cout<<wjets_skims[w]<<endl;
    wjetsChain->Add(wjets_skims[w].c_str());
  }

  wjetsChain->Process("../src/abcd.C+","wjets");

  gROOT->ProcessLine(".q");

  return;
}
  
  
