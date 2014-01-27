#include "../include/lnuj_bkgd_list.h"

void scaleQCD(string plot_name="lep_met_mt", int nbins=3){

  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In scaleQCD.C"<<endl;
  cout<<"** Run only on NON-scaled QCD samples! **"<<endl;
  cout<<endl;
  
  const int nBins = nbins;

  float elec_bkgd_bin_count[nBins]={0};
  float muon_bkgd_bin_count[nBins]={0};

  float elec_data_bin_count[nBins]={0};
  float muon_data_bin_count[nBins]={0};

  float elec_qcd_bin_count[nBins]={0};
  float muon_qcd_bin_count[nBins]={0};

  TFile* tmpFile;
  for(int s=0;s<nBkgds;s++){

    string cur_file = "../plots/gww_plots/merged/"+bkgd_list[s];
    cur_file+=".plot.root";
    cout<<"Loading :"<<bkgd_list[s]<<endl;
    tmpFile= (TFile*) TFile::Open(cur_file.c_str());

    string elec_hist_name = "all/h_elec_"+plot_name;
    TH1F* elec_hist = tmpFile->Get(elec_hist_name.c_str());

    string muon_hist_name = "all/h_muon_"+plot_name;
    TH1F* muon_hist = tmpFile->Get(muon_hist_name.c_str());

    if(!elec_hist || !muon_hist){
      cout<<"No histogram "<<elec_hist_name<<", in "<<cur_file<<endl;
      cout<<"No histogram "<<muon_hist_name<<", in "<<cur_file<<endl;
      exit(-143);
    }

    for(int i=1;i<nBins+1;i++){
      
      if(bkgd_list[s]=="qcd"){
	elec_qcd_bin_count[i-1]+=elec_hist->GetBinContent(i);
	muon_qcd_bin_count[i-1]+=muon_hist->GetBinContent(i);

      }else{
	elec_bkgd_bin_count[i-1]+=elec_hist->GetBinContent(i);
	muon_bkgd_bin_count[i-1]+=muon_hist->GetBinContent(i);
      }
    }
  
    delete elec_hist;
    delete muon_hist;
  
  }
  delete tmpFile;

  string data_loc = "../plots/gww_plots/merged/data11.lnuj.plot.root";
  TFile* dataFile = (TFile*) TFile::Open(data_loc.c_str());

  string elec_data_hist_name = "all/h_elec_"+plot_name;
  TH1F* data_elec_hist = dataFile->Get(elec_data_hist_name.c_str());
  string muon_data_hist_name = "all/h_muon_"+plot_name;
  TH1F* data_muon_hist = dataFile->Get(muon_data_hist_name.c_str());
  
  
  for(int j=1;j<nBins+1;j++){
    elec_data_bin_count[j-1]+=data_elec_hist->GetBinContent(j);
    muon_data_bin_count[j-1]+=data_muon_hist->GetBinContent(j);
  }

  float elec_bin_scales[nBins]={0};
  float muon_bin_scales[nBins]={0};
  cout<<endl;
  cout<<"results"<<endl;
  cout<<endl;
  
  float avg_elec_scale = 0;
  float avg_muon_scale = 0;
  for(int j=0;j<nBins;j++){

    float cur_elec_data = elec_data_bin_count[j];
    float cur_elec_bkgd = elec_bkgd_bin_count[j];
    float cur_elec_qcd = elec_qcd_bin_count[j];    
    elec_bin_scales[j]=(cur_elec_data-cur_elec_bkgd)/cur_elec_qcd;
    avg_elec_scale+=elec_bin_scales[j];
    
    float cur_muon_data = muon_data_bin_count[j];
    float cur_muon_bkgd = muon_bkgd_bin_count[j];
    float cur_muon_qcd = muon_qcd_bin_count[j];    
    muon_bin_scales[j]=(cur_muon_data-cur_muon_bkgd)/cur_muon_qcd;
    avg_muon_scale+=muon_bin_scales[j];
    
    cout<<"bin "<<j+1<<endl;
    cout<<"elec QCD scale: "<<elec_bin_scales[j]<<endl;
    cout<<"muon QCD scale: "<<muon_bin_scales[j]<<endl;    
    cout<<endl;
    }

  cout<<"For "<<plot_name<<":"<<endl;
  cout<<"Average Elec QCD scale: "<<avg_elec_scale/nBins<<endl;
  cout<<"Average Muon QCD scale: "<<avg_muon_scale/nBins<<endl;  
  cout<<endl;

  cout<<"Enter above values in ../include/wwXSec.h and re-merge!"<<endl;

}
