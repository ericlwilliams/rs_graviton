#include "../include/print_list.h"
#include "../include/wwFileInfo.h"
#include "../include/HistogramPainter.h"
#include <string>
#include <TLine.h>

string proc_type="gww";
string print_type=".pdf";
string color_scheme="conf";//normal, conf, thesis(?)

void printGWW(bool drawData=true,bool drawText=true){

  // gROOT->SetStyle("Plain");  
  // gStyle->SetOptStat(0);
  // gStyle->SetPalette(1);
  // gStyle->SetPadTickX(1);
  // gStyle->SetPadTickY(1);

  gROOT->LoadMacro("../include/atlasstyle-00-03-04/AtlasStyle.C");
  SetAtlasStyle();
  gROOT->LoadMacro("../include/atlasstyle-00-03-04/AtlasUtils.C");
  gROOT->LoadMacro("../include/atlasstyle-00-03-04/AtlasLabels.C");
  
  gROOT->SetBatch();
  
  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In printGWW.C"<<endl;

  const int nCtrls = 1;
  string ctrls[nCtrls] = {"ps"};

  const int nProcs = 2;
  string procs[nProcs] = {"elec", "muon"};

  
  TObjArray* wwFileInfos=new TObjArray();
  
  for(int s=0;s<nBkgds;s++){

    string cur_file = "../plots/gww_plots/merged/"+bkgd_list[s];
    cur_file+=".plot.root";

    cout<<"Loading :"<<bkgd_list[s]<<endl;

    //true - loadMerged
    wwFileInfo* tmpFileInfo = (wwFileInfo*) 
      new wwFileInfo((string) bkgd_list[s],(string) proc_type,(bool) true,(bool) true,(string) color_scheme);

    if(/*tmpFile &&*/ tmpFileInfo){
      wwFileInfos->Add((wwFileInfo*) tmpFileInfo);
    }else{
      cout<<"No wwFileInfo for "<<bkgd_list[s]<<endl;
    }
  }

  HistogramPainter* histogram_painter = new HistogramPainter(proc_type,wwFileInfos);

  // kinematic variables
  //string vars[] = {"lep_nu_dr","lep_nu_dijet_m","jet_n","lead_jet_pt","dijet_m","dijet_pt","lead_jet_eta","second_jet_eta","second_jet_pt","jet_m","lep_pt","lep_eta","lep_phi","lep_met_pt","vxp_n","avg_int_per_xing","lep_lead_jet_dr","lep_second_jet_dr","dijet_dr","dijet_dphi","lep_met_dphi","lead_jet_met_dphi","ht","st"};

  // qcd variables
  //string vars[] = {"lep_met_mt_eq2j","lep_met_mt_gt2j","lep_met_mt","lt","met"};

  // lepton variables
  //string vars[] = {"lep_sig_diff_qoverp"};

  // all
  //string vars[] = {"lep_nu_dr","lep_nu_dijet_m","jet_n","lead_jet_pt","dijet_m","dijet_pt","lead_jet_eta","second_jet_eta","second_jet_pt","jet_m","lep_pt","lep_eta","lep_phi","lep_met_pt","vxp_n","avg_int_per_xing","lep_lead_jet_dr","lep_second_jet_dr","dijet_dr","dijet_dphi","lep_met_dphi","lead_jet_met_dphi","lep_met_mt_eq2j","lep_met_mt_gt2j","lep_met_mt","lt","met","lep_calo_iso","lep_d0","lep_d0sig","lep_absz0","lep_track_iso","lep_sig_diff_qoverp","ht","st"};

  // tmp
  string vars[] = {"lep_met_mt"};
 

  int nVars = sizeof(vars)/sizeof(vars[0]);  

  cout<<endl;  
  for(int v=0;v<nVars;v++){   

    string cur_var = vars[v];
    
    for(int p=0;p<nProcs;p++){

      //TMP
      //if(!p) continue;
	
      string cur_proc = procs[p];

      string cur_to_print = cur_proc+"_"+cur_var;
      
      for(int c=0;c<nCtrls;c++){

	string cur_ctrl = ctrls[c];

	bool curDrawData = (cur_ctrl.find("sig_")!=string::npos) ?  false : drawData;
	
	cout<<"histogram_painter->Draw("<<cur_to_print<<","<<cur_ctrl<<","<<print_type<<",'gww',"<<curDrawData<<")"<<endl;
	histogram_painter->Draw(cur_to_print.c_str(),cur_ctrl.c_str(),print_type.c_str(),"gww",curDrawData,drawText);
      }
    }
  }


  delete histogram_painter;
  delete wwFileInfos;
  
  // cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  // cout<<"%% Event Selection Information "<<endl;
  // cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  // cout<<endl;
  // for(int fi=0;fi<wwFileInfos->GetEntries();fi++){
    
  //   ((wwFileInfo*) wwFileInfos->At(fi))->PrintInfo();

  // }
  
}
