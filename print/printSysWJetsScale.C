#include "../include/lnuj_bkgd_list.h"
#include "../include/wwFileInfo.h"
#include "../include/HistogramPainter.h"
#include <string>
#include <TLine.h>

string proc_type = "sys_wjets";
string file_tail = ".sys.wjets.plot.root";

void printSysWJetsScale(){

  gROOT->SetStyle("Plain");  
  gStyle->SetOptStat(0);
  gStyle->SetPalette(1);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  //gStyle->SetFillStyle(3144);
  
  gROOT->SetBatch();
  
  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In printSysWJetsScale.C"<<endl;

  const int nProcs=2;
  string procs[nProcs] = {"elec","muon"};

  const int nCtrls=3;
  string ctrls[nCtrls] = {"all","ewk","ttbar"};


  TObjArray* wwFileInfos=new TObjArray();
  
  for(int s=0;s<nBkgds;s++){

    string cur_file = "../plots/"+proc_type+"_plots/merged/"+bkgd_list[s];
    cur_file+=file_tail;

    //cout<<cur_file<<", find('gww') : "<<(cur_file.find("gww")==string::npos)<<endl;


    cout<<"Loading :"<<bkgd_list[s]<<", "<<cur_file<<endl;
    //true - loadMerged
    wwFileInfo* tmpFileInfo = (wwFileInfo*) new wwFileInfo((string) bkgd_list[s],(string) proc_type,(bool) true);

    if(tmpFileInfo){
      wwFileInfos->Add((wwFileInfo*) tmpFileInfo);
    }else{
      cout<<"No wwFileInfo for "<<bkgd_list[s]<<endl;
    }

  }

  HistogramPainter* histogram_painter = new HistogramPainter(proc_type,wwFileInfos);


  string vars[] = {"purw_nom_jet_eta","wjrw_iqopt3_jet_eta","wjrw_ptjmin10_jet_eta",
		   "purw_nom_lead_jet_pt","wjrw_iqopt3_lead_jet_pt","wjrw_ptjmin10_lead_jet_pt",
		   "purw_nom_jet_n","wjrw_iqopt3_jet_n","wjrw_ptjmin10_jet_n",
		   "purw_nom_lep_met_pt","wjrw_iqopt3_lep_met_pt","wjrw_ptjmin10_lep_met_pt",
		   "purw_nom_dijet_pt","wjrw_iqopt3_dijet_pt","wjrw_ptjmin10_dijet_pt"};
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
	
	cout<<"histogram_painter->Draw("<<cur_to_print<<","<<cur_ctrl<<",'.png','gww',true)"<<endl;
	histogram_painter->Draw(cur_to_print.c_str(),cur_ctrl.c_str(),".png","gww",true);
      }
    }
  }



  delete histogram_painter;
  delete wwFileInfos;
  



}
