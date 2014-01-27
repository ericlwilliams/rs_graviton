#include "../include/lnuj_skim_list.h"

// limit_cuts & limit_vars in limits_info.h

void runMetResolution(){


  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In runMetResolution.C"<<endl;
  cout<<"Running over "<<nSkims<<" skims"<<endl;
  cout<<endl;

  TChain *skimChain;
  string run_option;
  for(int s=0;s<nSkims;s++){

    skimChain=new TChain("analysisTree");
    string cur_skim = "../files/skims/"+skim_list[s];
    cur_skim+=".skim.root";

    
    skimChain->Add(cur_skim.c_str());

    run_option=skim_list[s];

    
    skimChain->Process("../src/metResolution.C+",run_option.c_str());
        
  }
  

  cout<<"Histogram files written to ../plots/met_resolution_plots"<<endl;
  cout<<"Don't forget to merge histograms!"<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  gROOT->ProcessLine(".q");
  return;
}
