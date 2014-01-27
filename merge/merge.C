#include "../include/merge_list.h"
#include "../scripts/myhadd.C"
#include "../include/systematics_bkgd_list.h"
#include "../src/lvjjHelper.h"
#include "../scripts/subtractWjetsContamination.C"

//string analy="GWW";

// analy= "gww","sigeff","limit"

void merge(string analy="gww"){

  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In mergeGWW.C, "<<analy<<endl;

  string* cur_bkgd_list;
  int cur_nBkgds;
  bool doVjetsSystematics=false;
  if(analy=="sys_wjets"){// sys_wjets_bkgd_list
    cur_bkgd_list=sys_wjets_bkgd_list;
    cur_nBkgds=sys_wjets_nBkgds;
  }else if(analy=="limit"){// sys_wjets_bkgd_list
    cur_bkgd_list=limit_bkgd_list;
    cur_nBkgds=limit_nBkgds;
  }else if(analy=="systematics"){
    cur_bkgd_list=systematics_bkgd_list;
    cur_nBkgds=systematics_nBkgds;
    doVjetsSystematics=true;
  }else if(analy=="selection"){
    cur_bkgd_list=selection_list;
    cur_nBkgds=selection_nBkgds;
  }else{// lnuj_bkgd_list.h
    cur_bkgd_list=merge_list;
    cur_nBkgds=nBkgds;
  }

  
  //TObjArray* files=new TObjArray();
  //TObjArray* wwFileInfos=new TObjArray();

  for(int b=0;b<cur_nBkgds;b++){

    string cur_bkgd = cur_bkgd_list[b];

    cout<<endl;
    cout<<endl;
    cout<<"Scaling and Merging "<<cur_bkgd<<endl;
    cout<<"myhadd("<<cur_bkgd<<","<<analy<<")"<<endl;
    myhadd(cur_bkgd.c_str(),analy.c_str());
  }

  cout<<"Merged output written to ../plots/"<<analy<<"_plots/merged"<<endl;


  if(!lvjjHelper::qcdHelper::useQCDScale || analy=="ctrl" || analy=="systematics"){ // useQCDScale should always be true for ctrl plots
    subtractWjetsContamination(analy.c_str());
  }
   
  cout<<"myhadd(qcd.alpgen,"<<analy<<")"<<endl;
  myhadd("qcd.alpgen",analy.c_str());
  

  
  if(doVjetsSystematics){
    cout<<endl;
    cout<<"!!! Do runVjetsSystematics.sh in ../wjets before running systematics!"<<endl;
  }

  gROOT->ProcessLine(".q");
  return;
}



