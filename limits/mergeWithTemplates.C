#include "../include/limit_bkgd_list.h"
#include "../include/wwFileInfo.h"
#include "../include/limits_wsys_info.h"
#include <iostream>
#include <iomanip>


void mergeWithTemplates(){

  for(int pr=0;pr<nProcs;pr++){ // el, mu

    string hist_name = "h_"+procs[pr];
    string proc_name = (procs[pr]=="el") ? "evjj" : "uvjj";
    //proc_name=procs[pr];
    
    string sys_name;
    bool isNominal=false;
    for(int sys=0;sys<nSystematics;sys++){//e.g. "nom", "jes"...

	sys_name=systematics[sys];

	if(sys_name=="nom"){
	  isNominal=true;
	  sys_name="jes_";//could be any
	}else{
	  isNominal=false;
	  sys_name+="_";
	}

	string mod_name;
	bool isNominalDoneModulation=false;
	for(int m=0;m<nModulations;m++){//e.g. "up", "down"

	  if(isNominalDoneModulation) continue;// is "nom", already run (don't need up/down/)
	  
	  if(!isNominal){
	    mod_name=modulations[m]+"_";
	    isNominalDoneModulation=false;
	  }else{ // is nom, no 'modulation' for nominal case
	    mod_name="nom_";
	    isNominalDoneModulation=true;
	  }
	  
	  string sim_file_name = (isNominal) ?
	    proc_name+"_highm_lep_nu_dijet_m" :
	    proc_name+"_highm_"+sys_name+mod_name+"lep_nu_dijet_m";

	    sim_file_name="./limit_files/"+sim_file_name+".root";

	    TFile* sim_file = TFile::Open(sim_file_name.c_str());
	    sim_file->ReadAll();

	    string wprime_cb_file_name =
	      "../signal_templates/wprime_files/"+proc_name+"_cb_"+sys_name+mod_name+"lep_nu_dijet_m.root";
	    TFile* wprime_cb_file = TFile::Open(wprime_cb_file_name.c_str());
	    wprime_cb_file->ReadAll();

	    string kkg_cb_file_name =
	      "../signal_templates/kkg_files/"+proc_name+"_cb_"+sys_name+mod_name+"lep_nu_dijet_m.root";
	    TFile* kkg_cb_file = TFile::Open(kkg_cb_file_name.c_str());
	    kkg_cb_file->ReadAll();

	    string rsg_cb_file_name =
	      "../signal_templates/rsg_files/"+proc_name+"_cb_"+sys_name+mod_name+"lep_nu_dijet_m.root";

	    TFile* rsg_cb_file = TFile::Open(rsg_cb_file_name.c_str());
	    rsg_cb_file->ReadAll();
	    
	    string new_file_name = (isNominal) ?
	      "./limit_files/merged/"+proc_name+"_lep_nu_dijet_m.root":
	      "./limit_files/merged/"+proc_name+"_"+sys_name+mod_name+"lep_nu_dijet_m.root";
	    TFile* new_file = TFile::Open(new_file_name.c_str(),"RECREATE");
	    
	    //cout<<"new file: "<<new_file_name<<endl;

	    gStyle->ResetAttMarker();
	    //gStyle->ResetAttMarker();
	    
	    sim_file->GetList()->Write();
	    rsg_cb_file->GetList()->Write();
	    kkg_cb_file->GetList()->Write();
	    wprime_cb_file->GetList()->Write();


	    new_file->Close();
	    rsg_cb_file->Close();
	    kkg_cb_file->Close();
	    wprime_cb_file->Close();

	    sim_file->Close();
	
	}
      }
  }

  gROOT->ProcessLine(".q");
  return;
}
