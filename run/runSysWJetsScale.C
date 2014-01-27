#include "../include/sys_wjets_skim_list.h"

void runSysWJetsScale(){

  cout<<"RUN rmSysWJetsScale.sh FIRST!"<<endl;

  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In runSysWJetsScale.C"<<endl;
  cout<<"Running over "<<nSkims<<" skims"<<endl;
  cout<<endl;

  //TChain *skimChain;
  string file;
  for(int s=0;s<nSkims;s++){

    TChain* skimChain=new TChain("analysisTree");

    string skim_name = skim_list[s];

    if(skim_name.find("qcd")!=string::npos){//qcd.(elec/muon).(alpgen/sherpa)
      if(skim_name.find("elec")!=string::npos){
	skim_name="qcd.elec.pu";
      }else{
	skim_name="qcd.muon.pu";
      }
    }
    
    string cur_skim = "../files/skims/"+skim_name;
    cur_skim+=".skim.root";
    cout<<"skimChain->Add("<<cur_skim.c_str()<<")"<<endl;;
    skimChain->Add(cur_skim.c_str());

    file=skim_list[s];
    skimChain->Process("/Users/elw/analy/lnuj/src/sysWJetsScale.C+",file.c_str());

    delete skimChain;
  }



  cout<<"Histogram files written to ../sys_wjets_plots"<<endl;
  cout<<"Don't forget to merge histograms!"<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  gROOT->ProcessLine(".q");
  return;
}
