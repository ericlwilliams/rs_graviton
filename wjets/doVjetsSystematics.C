#include "../include/systematics_bkgd_list.h"

void doVjetsSystematics(){

  gROOT->ProcessLine(".L makeVjetsSystematics.C");
  for(int i=0;i<systematics_nBkgds;i++){
    string cur_file = systematics_bkgd_list[i];
  

    //string cur_proc = ".x makeVjetsSystematics.C(\""+cur_file+"\")";
    string cur_proc = "makeVjetsSystematics(\""+cur_file+"\")";
    cout<<"Making v+jets systematic for "<<cur_file<<endl;
    gROOT->ProcessLine(cur_proc.c_str());

  }
  // QCD done seperately
  string qcd_file = "qcd.alpgen";
  cout<<"Making v+jets systematic for "<<qcd_file<<endl;
  string qcd_proc = "makeVjetsSystematics(\""+qcd_file+"\")";
  gROOT->ProcessLine(qcd_proc.c_str());
  

  return;
}
