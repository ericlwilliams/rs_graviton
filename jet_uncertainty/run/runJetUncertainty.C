void runJetUncertainty(){

  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In runJetUncertainty.C"<<endl;


  TChain *skimChain=new TChain("analysisTree");;
  string file = "mc.mcatnlo.t1";
  string skim_loc = "../../files/skims/";
  string cur_skim = skim_loc+file+".pu.skim.root";
  skimChain->Add(cur_skim.c_str());
  skimChain->Process("../src/jetUncertainty.C+",file.c_str());

  // for(int s=0;s<nSkims;s++){

  //   skimChain
  //   string cur_skim = "../../files/skims/"+skim_list[s];
  //   cur_skim+=".skim.root";
  //   cout<<"skimChain->Add("<<cur_skim.c_str()<<")"<<endl;;
  //   skimChain->Add(cur_skim.c_str());

  //   file=skim_list[s];
  //   skimChain->Process("../src/verificationPlots.C+",file.c_str());

    
  // }
  

  cout<<"Histogram files written to ../plots"<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  gROOT->ProcessLine(".q");
  return;
}
