//////////////////////////////////////////////////
// Script to make root files to be read by runLimit
// e.g. gww_met25_ptlv150_ptjj250_lep_met_dijet_mt:
//       - signal500, data, background
//       - signal750, data, background
//       - signal1000, data, background
//////////////////////////////////////////////////

#include "../include/lnuj_bkgd_list.h"
#include "../include/wwFileInfo.h"
#include "../include/limits_info.h"
#include <iostream>
#include <iomanip>

const int nProcs = 2;
string procs[nProcs] = {"elec","muon"};

TH1F* h_limit_plots[nLimitCuts][nLimitVars][nProcs];

void makeLimit(bool doData=true){

  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In makeLimit.C"<<endl;
  cout<<"doData: "<<doData<<endl;

  
  for(int pr=0;pr<nProcs;pr++){

    string hist_name = "h_"+procs[pr];

    string proc_name = "gww_"+procs[pr];
    
    for(int lc=0;lc<nLimitCuts;lc++){
      
      string cut_name = 
	Form("met%d_ptlv%d_ptjj%d",met_cut[lc],ptlv_cut[lc],ptjj_cut[lc]);

      for(int lv=0;lv<nLimitVars;lv++){
	
	string cur_limit_var = limit_vars[lv];
	
	string new_file_name = proc_name+"_"+cut_name+"_"+cur_limit_var;

	string cur_hist_name = hist_name+"_"+cut_name+"_"+cur_limit_var;

	
	new_file_name="./limit_files/"+new_file_name+".root";

	cout<<"Opening: "<<new_file_name<<endl;
	TFile* new_file = TFile::Open(new_file_name.c_str(),"RECREATE");
	//new_file->cd();

	//TH1F* h_signal500;
	// TH1F* h_signal750;
	// TH1F* h_signal1000;
	// TH1F* h_signal1250;

	
	// Make new file. cd()
	// 
	// Loop over merged files
	// Retreive histogram
	// Rename either signal%d, data or background
	// special case if adding to background
	//
	// Write new file

	string file_loc = "../plots/limit_plots/merged/";
	for(int s=0;s<nBkgds;s++){

	  string cur_file = file_loc+bkgd_list[s];
	  cur_file+=".limit.plot.root";

	  //cout<<cur_file<<endl;

	  TFile* cur_plot_file = TFile::Open(cur_file.c_str());

	  //get cur_hist_name
	  if(!cur_plot_file){
	    cout<<"No file "<<cur_file<<endl;
	    return;
	  }

	  TH1F* cur_plot_hist = (TH1F*) cur_plot_file->Get(cur_hist_name.c_str());

	  if(!cur_plot_hist){
	    cout<<"No histogram "<<cur_hist_name<<" in "<<cur_file<<endl;
	    return;
	  }

	  //cur_plot_hist->SetDirectory(0);
	  string cur_bkgd = bkgd_list[s];
	  
	  if(cur_bkgd=="mc.gww.m500") {cur_plot_hist->SetName("signal500");}
	  else if(cur_bkgd=="mc.gww.m750") {cur_plot_hist->SetName("signal750");}
	  else if(cur_bkgd=="mc.gww.m1000") {cur_plot_hist->SetName("signal1000");}
	  else if(cur_bkgd=="mc.gww.m1250") {cur_plot_hist->SetName("signal1250");}

	  else{// Need to add it to background histogram

	    TH1F* h_background = (TH1F*) new_file->Get("background");

	    if(!h_background){cur_plot_hist->SetName("background");}// no background hist yet
	    else{ //add to existing background hist
	      h_background->Add(cur_plot_hist);
	    }
	  }

	  cur_plot_hist->SetDirectory(new_file);
	  new_file->Delete(cur_hist_name.c_str());
	  cur_plot_file->Close();
	  delete cur_plot_file;
	}

	//////////////////////////////////////////////////
	// Data
	////////////////////////////////////////////////// 
	string data_file = "data.lnuj.limit.plot.root";
	string data_loc = file_loc+data_file;

	TFile* cur_data_file = TFile::Open(data_loc.c_str());

	if(!cur_data_file){
	  cout<<"No data file "<<data_file<<endl;
	  return;
	}

	TH1F* cur_data_hist = (doData) ?
	  (TH1F*) cur_data_file->Get(cur_hist_name.c_str()) :
	  (TH1F*) h_background->Clone();// if !doData, set background histogram to data
	
	if(!cur_data_hist){
	  cout<<"No histogram "<<cur_data_hist<<" in "<<data_file<<endl;
	  return;
	}

	cur_data_hist->SetName("data");
	cur_data_hist->SetDirectory(new_file);
	new_file->Delete(cur_hist_name.c_str());

	
	
	new_file->Write("",TObject::kOverwrite);
	new_file->Close();
	delete new_file;
      }
    }
  }
  
  // TObjArray* wwFileInfos=new TObjArray();
  // string file_loc = "../plots/limit_plots/merged/";
  // for(int s=0;s<nBkgds;s++){

  //   string cur_file = file_loc+bkgd_list[s];
  //   cur_file+=".plot.root";

  //   cout<<cur_file<<endl;
  //   //cout<<cur_file<<", find('gww') : "<<(cur_file.find("gww")==string::npos)<<endl;

  // }

  return;
}
