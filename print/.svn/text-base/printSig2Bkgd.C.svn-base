#include "../include/lnuj_bkgd_list.h"
#include "../include/wwFileInfo.h"
#include <iostream>
#include <iomanip>

TString proc_type="s2b";


void printSig2Bkgd(){

  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In printGWW.C"<<endl;

  TObjArray* wwFileInfos=new TObjArray();

  string file_loc = "../plots/merged/";
  
  for(int s=0;s<nBkgds;s++){

    string cur_file = file_loc+bkgd_list[s];
    cur_file+=".plot.root";

    //cout<<cur_file<<", find('gww') : "<<(cur_file.find("gww")==string::npos)<<endl;

    
    //true - loadMerged
    wwFileInfo* tmpFileInfo = (wwFileInfo*) new wwFileInfo(bkgd_list[s],proc_type.c_str());
    
    wwFileInfos->Add(tmpFileInfo);
  }

  //cout<<"TMP: NOT LOADING DATA"<<endl;
  wwFileInfos->Add((wwFileInfo) new wwFileInfo("data.lnuj",proc_type.c_str()));

  
  int file_info_n = wwFileInfos->GetEntries();

  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"%% Efficiencies"<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  vector<string>* v_procs = new vector<string>;
  vector<string>* v_tabs = new vector<string>;
  vector<double>* v_sow_n = new vector<double>;
  vector<double>* v_met_clean_n = new vector<double>;
  vector<double>* v_vxp_sel_n = new vector<double>;
  vector<double>* v_trig_n = new vector<double>;
  vector<double>* v_lep_sel_n = new vector<double>;      
  vector<double>* v_met_cut_n = new vector<double>;      
  vector<double>* v_one_jet_n = new vector<double>;
  vector<double>* v_one_elec_n = new vector<double>;
  vector<double>* v_one_muon_n = new vector<double>;        
  vector<double>* v_ctrl_all_n = new vector<double>;
  vector<double>* v_ctrl_ewk_n = new vector<double>;
  vector<double>* v_ctrl_ttbar_n = new vector<double>;
  vector<double>* v_ctrl_jetm_n = new vector<double>;  

  for(int f=0; f<file_info_n;f++){

    wwFileInfo* curFileInfo = (wwFileInfo*) wwFileInfos->At(f);
    string proc = curFileInfo->GetShortProc();
    string tab = (proc.size()>4) ? "\t\t" : "\t";
    v_procs->push_back(proc);
    v_tabs->push_back(tab);
    v_sow_n->push_back(curFileInfo->ScaledSumOfWeights());
    v_met_clean_n->push_back(curFileInfo->ScaledMetCleaningN());
    v_vxp_sel_n->push_back(curFileInfo->ScaledVxpSelectionN());
    v_trig_n->push_back(curFileInfo->ScaledTriggerN());
    v_lep_sel_n->push_back(curFileInfo->ScaledLeptonSelectionN());
    v_met_cut_n->push_back(curFileInfo->ScaledMetCutN());
    v_one_jet_n->push_back(curFileInfo->ScaledOneJetN());
    v_one_elec_n->push_back(curFileInfo->ScaledNElectronEvents());
    v_one_muon_n->push_back(curFileInfo->ScaledNMuonEvents());

    v_ctrl_all_n->push_back(curFileInfo->ScaledNEvents());
    v_ctrl_ewk_n->push_back(curFileInfo->ScaledNEventsEwk());
    v_ctrl_ttbar_n->push_back(curFileInfo->ScaledNEventsTTBar());
    v_ctrl_jetm_n->push_back(curFileInfo->ScaledNEventsJetM());
  }    


  std::cout.precision(3);
  std::cout.scientific;
  std::cout.right;

  string spacer1;
  cout<<"\t\t|*|";
  for(int f=0; f<file_info_n;f++){
    string cur_proc = v_procs->at(f);
    spacer1 = (cur_proc.size()>4) ? "  |*|": "     |*|";
    cout<<setw(16)<<cur_proc+spacer1;
  }   
  cout<<endl;

  string spacer2 = "  |*|";

  cout<<"SoW (#):\t|*|";
  for(int f=0; f<file_info_n;f++){
    char sow_n[20];
    sprintf(sow_n,"%.2e",v_sow_n->at(f)*1.);
    string cur_sow_n = sow_n;
    cur_sow_n+=spacer2;
    cout<<setw(16)<<cur_sow_n;
  }
  cout<<endl;

  cout<<"Met Clean (%):\t|*|";
  for(int f=0; f<file_info_n;f++){
    char met_clean_frac[20];
    sprintf(met_clean_frac,"%.2f",(v_met_clean_n->at(f)/v_sow_n->at(f))*100.);
    string cur_met_clean_frac = met_clean_frac;
    cur_met_clean_frac+=spacer2;
    cout<<setw(16)<<cur_met_clean_frac;
  }
  cout<<endl;
  
  cout<<"Vxp Sel (%):\t|*|";
  for(int f=0; f<file_info_n;f++){
    char vxp_sel_frac[20];
    sprintf(vxp_sel_frac,"%.2f",(v_vxp_sel_n->at(f)/v_sow_n->at(f))*100.);
    string cur_vxp_sel_frac = vxp_sel_frac;
    cur_vxp_sel_frac+=spacer2;
    cout<<setw(16)<<cur_vxp_sel_frac;
  }
  cout<<endl;

  cout<<"Trigger (%):\t|*|";
  for(int f=0; f<file_info_n;f++){
    char trig_frac[20];
    sprintf(trig_frac,"%.2f",(v_trig_n->at(f)/v_sow_n->at(f))*100.);
    string cur_trig_frac = trig_frac;
    cur_trig_frac+=spacer2;
    cout<<setw(16)<<cur_trig_frac;
  }
  cout<<endl;

  cout<<"Lepton Sel (%):\t|*|";
  for(int f=0; f<file_info_n;f++){
    char lep_sel_frac[20];
    sprintf(lep_sel_frac,"%.2f",(v_lep_sel_n->at(f)/v_sow_n->at(f))*100.);
    string cur_lep_sel_frac = lep_sel_frac;
    cur_lep_sel_frac+=spacer2;
    cout<<setw(16)<<cur_lep_sel_frac;
  }
  cout<<endl;

  cout<<"Met>30 GeV (%):\t|*|";
  for(int f=0; f<file_info_n;f++){
    char met_cut_frac[20];
    sprintf(met_cut_frac,"%.2f",(v_met_cut_n->at(f)/v_sow_n->at(f))*100.);
    string cur_met_cut_frac = met_cut_frac;
    cur_met_cut_frac+=spacer2;
    cout<<setw(16)<<cur_met_cut_frac;
  }
  cout<<endl;

  cout<<">= One Jet (%):\t|*|";
  for(int f=0; f<file_info_n;f++){
    char one_jet_frac[20];
    sprintf(one_jet_frac,"%.2f",(v_one_jet_n->at(f)/v_sow_n->at(f))*100.);
    string cur_one_jet_frac = one_jet_frac;
    cur_one_jet_frac+=spacer2;
    cout<<setw(16)<<cur_one_jet_frac;
  }
  cout<<endl;

  cout<<"Elec Evnt (%):\t|*|";
  for(int f=0; f<file_info_n;f++){
    char one_elec_frac[20];
    sprintf(one_elec_frac,"%.2f",(v_one_elec_n->at(f)/v_sow_n->at(f))*100.);
    string cur_one_elec_frac = one_elec_frac;
    cur_one_elec_frac+=spacer2;
    cout<<setw(16)<<cur_one_elec_frac;
  }
  cout<<endl;

  cout<<"Muon Evnt (%):\t|*|";
  for(int f=0; f<file_info_n;f++){
    char one_muon_frac[20];
    sprintf(one_muon_frac,"%.2f",(v_one_muon_n->at(f)/v_sow_n->at(f))*100.);
    string cur_one_muon_frac = one_muon_frac;
    cur_one_muon_frac+=spacer2;
    cout<<setw(16)<<cur_one_muon_frac;
  }
  cout<<endl;

  cout<<"--"<<endl;

  cout<<"Elec Evnt (#):\t|*|";
  for(int f=0; f<file_info_n;f++){
    char one_elec_n[20];
    sprintf(one_elec_n,"%.3f",v_one_elec_n->at(f));
    string cur_one_elec_n = one_elec_n;
    cur_one_elec_n+=spacer2;
    cout<<setw(16)<<cur_one_elec_n;
  }
  cout<<endl;

  cout<<"Muon Evnt (#):\t|*|";
  for(int f=0; f<file_info_n;f++){
    char one_muon_n[20];
    sprintf(one_muon_n,"%.3f",v_one_muon_n->at(f));
    string cur_one_muon_n = one_muon_n;
    cur_one_muon_n+=spacer2;
    cout<<setw(16)<<cur_one_muon_n;
  }
  cout<<endl;
  cout<<endl;



  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"%% Control Regions"<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  vector<string>* v_regions = new vector<string>;
  v_regions->push_back("all");
  v_regions->push_back("ewk");
  v_regions->push_back("ttbar");
  v_regions->push_back("jetm");

  int n_regions = v_regions->size();

  string rspacer1;
  cout<<"\t\t|*|";
  for(int r=0;r<n_regions;r++){
    string cur_region = v_regions->at(r);
    rspacer1 = (cur_region.size()>4) ? "  |*|": "     |*|";
    cout<<setw(16)<<cur_region+rspacer1;

  }
  cout<<endl;

  
  double bkgd_ctrl_all_n=0;
  double bkgd_ctrl_ewk_n=0;
  double bkgd_ctrl_ttbar_n=0;
  double bkgd_ctrl_jetm_n=0;    

  double sig_ctrl_all_n=0;
  double sig_ctrl_ewk_n=0;
  double sig_ctrl_ttbar_n=0;
  double sig_ctrl_jetm_n=0;    

  double data_ctrl_all_n=0;
  double data_ctrl_ewk_n=0;
  double data_ctrl_ttbar_n=0;
  double data_ctrl_jetm_n=0;    

  
  string spacer2 = "  |*|";

  for(int f=0; f<file_info_n;f++){

    string cur_proc = v_procs->at(f);

    bool isSig = (cur_proc.find("gww")!=string::npos) ? true : false;

    if(!isSig){
      spacer1 = (cur_proc.size()>4) ? "\t|*|": "\t\t|*|";
      cout<<cur_proc+spacer1;

      double ctrl_all_n = v_ctrl_all_n->at(f);
      cout<<setw(11)<<ctrl_all_n<<"  |*|";
      bkgd_ctrl_all_n+=ctrl_all_n;

      double ctrl_ewk_n = v_ctrl_ewk_n->at(f);
      cout<<setw(11)<<ctrl_ewk_n<<"  |*|";
      bkgd_ctrl_ewk_n+=ctrl_ewk_n;

      double ctrl_ttbar_n = v_ctrl_ttbar_n->at(f);
      cout<<setw(11)<<ctrl_ttbar_n<<"  |*|";
      bkgd_ctrl_ttbar_n+=ctrl_ttbar_n;

      double ctrl_jetm_n = v_ctrl_jetm_n->at(f);
      cout<<setw(11)<<ctrl_jetm_n<<"  |*|";
      bkgd_ctrl_jetm_n+=ctrl_jetm_n;
      cout<<endl;
    }else{//is Signal

      sig_ctrl_all_n = v_ctrl_all_n->at(f);
      sig_ctrl_ewk_n = v_ctrl_ewk_n->at(f);
      sig_ctrl_ttbar_n = v_ctrl_ttbar_n->at(f);      
      sig_ctrl_jetm_n = v_ctrl_jetm_n->at(f);            
      
    }
    
    
  }
  cout<<"--"<<endl;
  cout<<"tot_bkgd\t|*|";
  cout<<setw(11)<<bkgd_ctrl_all_n<<"  |*|";
  cout<<setw(11)<<bkgd_ctrl_ewk_n<<"  |*|";
  cout<<setw(11)<<bkgd_ctrl_ttbar_n<<"  |*|";  
  cout<<setw(11)<<bkgd_ctrl_jetm_n<<"  |*|";  
  cout<<endl;
  
  cout<<"sig\t\t|*|";
  cout<<setw(11)<<sig_ctrl_all_n<<"  |*|";
  cout<<setw(11)<<sig_ctrl_ewk_n<<"  |*|";
  cout<<setw(11)<<sig_ctrl_ttbar_n<<"  |*|";  
  cout<<setw(11)<<sig_ctrl_jetm_n<<"  |*|";  
  cout<<endl;
  
  double sig_bkgd_ctrl_all_n = sig_ctrl_all_n/bkgd_ctrl_all_n;
  double sig_bkgd_ctrl_ewk_n = sig_ctrl_ewk_n/bkgd_ctrl_ewk_n;
  double sig_bkgd_ctrl_ttbar_n = sig_ctrl_ttbar_n/bkgd_ctrl_ttbar_n;
  double sig_bkgd_ctrl_jetm_n = sig_ctrl_jetm_n/bkgd_ctrl_jetm_n;
  
  cout<<"--"<<endl;
  cout<<"sig/bkgd\t|*|";
  cout<<setw(11)<<sig_bkgd_ctrl_all_n<<"  |*|";
  cout<<setw(11)<<sig_bkgd_ctrl_ewk_n<<"  |*|";
  cout<<setw(11)<<sig_bkgd_ctrl_ttbar_n<<"  |*|";  
  cout<<setw(11)<<sig_bkgd_ctrl_jetm_n<<"  |*|";  
  
  cout<<endl;


  double sig_sqrt_bkgd_ctrl_all_n = sig_ctrl_all_n/sqrt(bkgd_ctrl_all_n);
  double sig_sqrt_bkgd_ctrl_ewk_n = sig_ctrl_ewk_n/sqrt(bkgd_ctrl_ewk_n);
  double sig_sqrt_bkgd_ctrl_ttbar_n = sig_ctrl_ttbar_n/sqrt(bkgd_ctrl_ttbar_n);
  double sig_sqrt_bkgd_ctrl_jetm_n = sig_ctrl_jetm_n/sqrt(bkgd_ctrl_jetm_n);

  cout<<"sig/sqrt(bkgd)\t|*|";
  cout<<setw(11)<<sig_sqrt_bkgd_ctrl_all_n<<"  |*|";
  cout<<setw(11)<<sig_sqrt_bkgd_ctrl_ewk_n<<"  |*|";
  cout<<setw(11)<<sig_sqrt_bkgd_ctrl_ttbar_n<<"  |*|";  
  cout<<setw(11)<<sig_sqrt_bkgd_ctrl_jetm_n<<"  |*|";  
  
  cout<<endl;


  
  gROOT->ProcessLine(".q");
  return;
}
