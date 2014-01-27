#include "../../include/data_skim_list.h"

void runVerification(){

  cout<<"RUN rmVerification.sh FIRST!"<<endl;

  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In runVerification.C"<<endl;
  cout<<"Running over "<<nSkims<<" skims"<<endl;
  cout<<endl;

  TChain *skimChain;
  string file;
  for(int s=0;s<nSkims;s++){

    skimChain=new TChain("analysisTree");
    string cur_skim = "../../files/skims/"+skim_list[s];
    cur_skim+=".skim.root";
    cout<<"skimChain->Add("<<cur_skim.c_str()<<")"<<endl;;
    skimChain->Add(cur_skim.c_str());

    file=skim_list[s];
    skimChain->Process("../src/verificationPlots.C+",file.c_str());

    
  }
  

  cout<<"Histogram files written to ../plots"<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  gROOT->ProcessLine(".q");
  return;
}
