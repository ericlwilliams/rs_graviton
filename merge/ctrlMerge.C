#include "../include/lnuj_bkgd_list.h"
//#include "../include/wwFileInfo.h"
#include "../scripts/myhadd.C"

//string analy="GWW";

// analy= "gww","sigeff","limit"

void merge(string analy="gww"){

  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In mergeGWW.C, "<<analy<<endl;

  
  //TObjArray* files=new TObjArray();
  //TObjArray* wwFileInfos=new TObjArray();

  for(int b=0;b<nBkgds;b++){

    string cur_bkgd = bkgd_list[b];

    cout<<"Scaling and Merging "<<cur_bkgd<<endl;
    cout<<"myhadd("<<cur_bkgd<<","<<analy<<")"<<endl;
    myhadd(cur_bkgd.c_str(),analy.c_str());
  }


  cout<<"Merged output written to ../plots/"<<analy<<"_plots/merged"<<endl;
  gROOT->ProcessLine(".q");
  return;
}



