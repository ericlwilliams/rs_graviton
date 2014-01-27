//////////////////////////////////////////////////
// Loads plot files from ../plots/ctrl_plots/...
// Calculates scale factors in
// ctrl_lowm: pt(lv)>50, pt(jj)>50, m(jj)<65 || m(jj)>115
// ctrl_highm: pt(lv)>200, pt(jj)>200, m(jj)<65 || m(jj)>115
// lowsb_lowm: pt(lv)>50, pt(jj)>50, m(jj)<65
// highsb_lowm: pt(lv)>50, pt(jj)>50, m(jj)>115
// lowsb_highm: pt(lv)>200, pt(jj)>200, m(jj)<65
// highsb_highm: pt(lv)>200, pt(jj)>200, m(jj)>115
//////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <vector>

#include <TCanvas.h>
#include <TLegend.h>
#include <THStack.h>
#include "TH1.h"
#include <TFile.h>

//#include "../include/wjets_sf_defs.h"

//////////////////////////////////////////////////
// scale_region:
// - "sidebands"
//   - loads 'lowsb_lowm','highsb_lowm','lowsb_highm','highsb_higm'
// - "inclusive"
//   - loads 'ctrl_wjets_lowpt' (maybe 'ctrl_wjets_lowpt')
////////////////////////////////////////////////// 
void wjetsScaleFactors(string scale_region="sidebands"){

  gROOT->SetStyle("Plain");  
  gStyle->SetOptStat(0);
  gStyle->SetPalette(1);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  //gStyle->SetFillStyle(3144);
  
  gROOT->SetBatch();

  cout.setf(ios::fixed,ios::floatfield);            // floatfield not set
  cout.precision(3);
  
  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In wjetsScaleFactors.C"<<endl;

  const int nControlRegions = 2;
  string control_regions[nControlRegions] = {"lowsb_highm","highsb_highm"};

  const int nLowSB=0;
  const int nHighSB=1;
  
  // const int nProcs = 2;
  // string procs[nProcs] = {"elec", "muon"};

  string file_loc = "~/Dropbox/eMacs/analy/lvjj/plots/ctrl_plots/";


    //////////////////////////////////////////////////
  // Load Data
  ////////////////////////////////////////////////// 
  // string lowsb_hist_name = "h_lowsb_highm_comb_dijet_m_dijet_m";
  // string highsb_hist_name = "h_highsb_highm_comb_dijet_m_dijet_m";
  string lowsb_hist_name = "h_lowsb_highm_comb_dijet_m_evt_n";
  string highsb_hist_name = "h_highsb_highm_comb_dijet_m_evt_n";
  //string highsb_hist_name = "h_highsb_highm_comb_dijet_m_trunc_evt_n";

  
  string data_loc = file_loc+"merged/data.lnuj.ctrl.plot.root";
  TFile* data = TFile::Open(data_loc.c_str());
  TH1F* h_lowsb_data = (TH1F*) data->Get(lowsb_hist_name.c_str());
  h_lowsb_data->SetDirectory(0);
  TH1F* h_highsb_data = (TH1F*) data->Get(highsb_hist_name.c_str());
  h_highsb_data->SetDirectory(0);
  data->Close();  
  //////////////////////////////////////////////////
  // Load Scaled Backgrounds
  //////////////////////////////////////////////////   
  string sherpa_wjets_loc = file_loc+"merged/mc.sherpa.wjets.ctrl.plot.root";
  string alpgen_wjets_loc = file_loc+"merged/mc.alpgen.wjets.ctrl.plot.root";
  string vv_loc = file_loc+"merged/mc.herwig.vv.ctrl.plot.root";
  string alpgen_qcd_loc = file_loc+"merged/qcd.alpgen.ctrl.plot.root";
  string sherpa_qcd_loc = file_loc+"merged/qcd.sherpa.ctrl.plot.root";
  string top_loc = file_loc+"merged/mc.mcatnlo.top.ctrl.plot.root";  
  string alpgen_zjets_loc = file_loc+"merged/mc.alpgen.zjets.ctrl.plot.root";
  string sherpa_zjets_loc = file_loc+"merged/mc.sherpa.zjets.ctrl.plot.root";

  
  // TFile* sherpa_wjets = TFile::Open(sherpa_wjets_loc.c_str(),"READ");  
  // TH1F* h_lowsb_sherpa_wjets = (TH1F*) sherpa_wjets->Get(lowsb_hist_name.c_str());
  // h_lowsb_sherpa_wjets->SetDirectory(0);
  // TH1F* h_highsb_sherpa_wjets = (TH1F*) sherpa_wjets->Get(highsb_hist_name.c_str());
  // h_highsb_sherpa_wjets->SetDirectory(0);
  // sherpa_wjets->Close();

  TFile* alpgen_wjets = TFile::Open(alpgen_wjets_loc.c_str(),"READ");
  TH1F* h_lowsb_alpgen_wjets = (TH1F*) alpgen_wjets->Get(lowsb_hist_name.c_str());
  h_lowsb_alpgen_wjets->SetDirectory(0);
  TH1F* h_highsb_alpgen_wjets = (TH1F*) alpgen_wjets->Get(highsb_hist_name.c_str());
  h_highsb_alpgen_wjets->SetDirectory(0);
  alpgen_wjets->Close();

  TFile* vv = TFile::Open(vv_loc.c_str(),"READ");
  TH1F* h_lowsb_vv = (TH1F*) vv->Get(lowsb_hist_name.c_str());
  h_lowsb_vv->SetDirectory(0);
  TH1F* h_highsb_vv = (TH1F*) vv->Get(highsb_hist_name.c_str());
  h_highsb_vv->SetDirectory(0);
  vv->Close();

  TFile* alpgen_qcd = TFile::Open(alpgen_qcd_loc.c_str(),"READ");
  TH1F* h_lowsb_alpgen_qcd = (TH1F*) alpgen_qcd->Get(lowsb_hist_name.c_str());
  h_lowsb_alpgen_qcd->SetDirectory(0);
  TH1F* h_highsb_alpgen_qcd = (TH1F*) alpgen_qcd->Get(highsb_hist_name.c_str());
  h_highsb_alpgen_qcd->SetDirectory(0);
  alpgen_qcd->Close();

  // TFile* sherpa_qcd = TFile::Open(sherpa_qcd_loc.c_str(),"READ");
  // TH1F* h_lowsb_sherpa_qcd = (TH1F*) sherpa_qcd->Get(lowsb_hist_name.c_str());
  // h_lowsb_sherpa_qcd->SetDirectory(0);
  // TH1F* h_highsb_sherpa_qcd = (TH1F*) sherpa_qcd->Get(highsb_hist_name.c_str());
  // h_highsb_sherpa_qcd->SetDirectory(0);
  // sherpa_qcd->Close();

  TFile* top = TFile::Open(top_loc.c_str(),"READ");
  TH1F* h_lowsb_top = (TH1F*) top->Get(lowsb_hist_name.c_str());
  h_lowsb_top->SetDirectory(0);
  TH1F* h_highsb_top = (TH1F*) top->Get(highsb_hist_name.c_str());
  h_highsb_top->SetDirectory(0);
  top->Close();

  TFile* alpgen_zjets = TFile::Open(alpgen_zjets_loc.c_str(),"READ");
  TH1F* h_lowsb_alpgen_zjets = (TH1F*) alpgen_zjets->Get(lowsb_hist_name.c_str());
  h_lowsb_alpgen_zjets->SetDirectory(0);
  TH1F* h_highsb_alpgen_zjets = (TH1F*) alpgen_zjets->Get(highsb_hist_name.c_str());
  h_highsb_alpgen_zjets->SetDirectory(0);
  alpgen_zjets->Close();

  // TFile* sherpa_zjets = TFile::Open(sherpa_zjets_loc.c_str(),"READ");
  // TH1F* h_lowsb_sherpa_zjets = (TH1F*) sherpa_zjets->Get(lowsb_hist_name.c_str());
  // h_lowsb_sherpa_zjets->SetDirectory(0);
  // TH1F* h_highsb_sherpa_zjets = (TH1F*) sherpa_zjets->Get(highsb_hist_name.c_str());
  // h_highsb_sherpa_zjets->SetDirectory(0);
  // sherpa_zjets->Close();



  // Non V+jets
  TH1F* h_lowsb_non_vjets_bkgd = (TH1F*) h_lowsb_vv;
  h_lowsb_non_vjets_bkgd->Add((TH1F*) h_lowsb_top);
  TH1F* h_highsb_non_vjets_bkgd = (TH1F*) h_highsb_vv;
  h_highsb_non_vjets_bkgd->Add((TH1F*) h_highsb_top);
  

  // // SHERPA V+JETS
  // TH1F* h_lowsb_sherpa_vjets = (TH1F*) h_lowsb_sherpa_wjets;
  // h_lowsb_sherpa_vjets->Add((TH1F*) h_lowsb_sherpa_zjets);
  // TH1F* h_highsb_sherpa_vjets = (TH1F*) h_highsb_sherpa_wjets;
  // h_highsb_sherpa_vjets->Add((TH1F*) h_highsb_sherpa_zjets);

  // // SHERPA background
  // TH1F* h_lowsb_sherpa_bkgd = (TH1F*) h_lowsb_non_vjets_bkgd->Clone();
  // h_lowsb_sherpa_bkgd->Add((TH1F*) h_lowsb_sherpa_qcd);
  // TH1F* h_highsb_sherpa_bkgd = (TH1F*) h_highsb_non_vjets_bkgd->Clone();
  // h_highsb_sherpa_bkgd->Add((TH1F*) h_highsb_sherpa_qcd);

  // // SHERPA SF
  // TH1F* h_lowsb_sherpa_sf = (TH1F*) h_lowsb_data->Clone();
  // h_lowsb_sherpa_sf->Add(h_lowsb_sherpa_bkgd,-1.);
  // h_lowsb_sherpa_sf->Divide(h_lowsb_sherpa_sf,h_lowsb_sherpa_vjets,1,1,"B");
  // TH1F* h_highsb_sherpa_sf = (TH1F*) h_highsb_data->Clone();
  // h_highsb_sherpa_sf->Add(h_highsb_sherpa_bkgd,-1.);
  // h_highsb_sherpa_sf->Divide(h_highsb_sherpa_sf,h_highsb_sherpa_vjets,1,1,"B");

  // ALPGEN V+JETS
  TH1F* h_lowsb_alpgen_vjets = (TH1F*) h_lowsb_alpgen_wjets;
  h_lowsb_alpgen_vjets->Add((TH1F*) h_lowsb_alpgen_zjets);
  TH1F* h_highsb_alpgen_vjets = (TH1F*) h_highsb_alpgen_wjets;
  h_highsb_alpgen_vjets->Add((TH1F*) h_highsb_alpgen_zjets);

  // ALPGEN background
  TH1F* h_lowsb_alpgen_bkgd = (TH1F*) h_lowsb_non_vjets_bkgd->Clone();
  h_lowsb_alpgen_bkgd->Add((TH1F*) h_lowsb_alpgen_qcd);
  TH1F* h_highsb_alpgen_bkgd = (TH1F*) h_highsb_non_vjets_bkgd->Clone();
  h_highsb_alpgen_bkgd->Add((TH1F*) h_highsb_alpgen_qcd);

  // ALPGEN SF
  TH1F* h_lowsb_alpgen_sf = (TH1F*) h_lowsb_data->Clone();
  h_lowsb_alpgen_sf->Add(h_lowsb_alpgen_bkgd,-1.);
  h_lowsb_alpgen_sf->Divide(h_lowsb_alpgen_sf,h_lowsb_alpgen_vjets,1,1,"B");
  TH1F* h_highsb_alpgen_sf = (TH1F*) h_highsb_data->Clone();
  h_highsb_alpgen_sf->Add(h_highsb_alpgen_bkgd,-1.);
  h_highsb_alpgen_sf->Divide(h_highsb_alpgen_sf,h_highsb_alpgen_vjets,1,1,"B");

  
  double alpgen_evt_n[nControlRegions]={0.};
  double alpgen_sf[nControlRegions]={0.};
  double alpgen_sf_err[nControlRegions]={0.};
  double sherpa_evt_n[nControlRegions]={0.};
  double sherpa_sf[nControlRegions]={0.};
  double sherpa_sf_err[nControlRegions]={0.};  




  alpgen_sf[nLowSB] =
    h_lowsb_alpgen_sf->IntegralAndError(1,h_lowsb_alpgen_sf->GetNbinsX(),alpgen_sf_err[nLowSB]);
  alpgen_evt_n[nLowSB] = (double) h_lowsb_alpgen_vjets->Integral();      

  
  alpgen_sf[nHighSB] =
    h_highsb_alpgen_sf->IntegralAndError(1,h_highsb_alpgen_sf->GetNbinsX(),alpgen_sf_err[nHighSB]);
  alpgen_evt_n[nHighSB] = (double) h_highsb_alpgen_vjets->Integral();      

  
  //////////////////////////////////////////////////
  // Print Scale Factors
  ////////////////////////////////////////////////// 
  
  cout<<"== W+Jets Scale Factors =="<<endl;
  for(int i=0;i<nControlRegions;i++){
    
    string cur_control_region = control_regions[i];
    string ctrl_out_file_name = "./logs/vjets_"+cur_control_region+"_sf.csv";
    std::ofstream ctrl_out_file(ctrl_out_file_name.c_str());
    ctrl_out_file.precision(3);
    ctrl_out_file.setf(ios::fixed,ios::floatfield);
    ctrl_out_file<<"alpgen_sf,alpgen_err,sherpa_sf,sherpa_err"<<endl;;

    ctrl_out_file<<alpgen_sf[i]<<","<<alpgen_sf_err[i]<<","//alpgen
  		 <<sherpa_sf[i]<<","<<sherpa_sf_err[i]<<endl;//sherpa

    ctrl_out_file.close();

      cout<<"* comb channel *"<<endl;
      cout<<"ALPGEN: "<<alpgen_sf[i]<<" +- "<<alpgen_sf_err[i]
  	  <<" ("<<(alpgen_sf_err[i]/alpgen_sf[i])*100<<"%)  (weight by: "
  	  <<alpgen_evt_n[i]<<" entries)"<<endl;
      // cout<<"SHERPA: "<<sherpa_sf[i]<<" +- "<<sherpa_sf_err[i]
      // 	  <<" ("<<(sherpa_sf_err[i]/sherpa_sf[i])*100<<"%)  (weight by: "
      // 	  <<sherpa_evt_n[i]<<" entries)"<<endl;
  }
  
  double avg_alpgen_sf=0.;
  double err_alpgen_sf=0.;
  double alpgen_sow=0.;

  double avg_sherpa_sf=0;
  double err_sherpa_sf=0.;
  double sherpa_sow=0.;
  
  cout<<"--"<<endl;
  cout<<"Control Region: "<<cur_control_region<<endl;

  avg_alpgen_sf=(((alpgen_sf[nLowSB]*alpgen_evt_n[nLowSB]) +
  		  (alpgen_sf[nHighSB]*alpgen_evt_n[nHighSB])) /
  		 (alpgen_evt_n[nLowSB]+alpgen_evt_n[nHighSB]));

  err_alpgen_sf=sqrt(pow(alpgen_sf_err[nLowSB],2.)+
  		     pow(alpgen_sf_err[nHighSB],2.));

  // avg_sherpa_sf=(((sherpa_sf[nLowSB]*sherpa_evt_n[nLowSB]) +
  // 		  (sherpa_sf[nHighSB]*sherpa_evt_n[nHighSB])) /
  // 		 (sherpa_evt_n[nLowSB]+sherpa_evt_n[nHighSB]));
  
  // err_sherpa_sf=sqrt(pow(sherpa_sf_err[nLowSB],2.)+
  // 		     pow(sherpa_sf_err[nHighSB],2.));

  double max_alpgen_sf_diff=0;
  double max_sherpa_sf_diff=0;

  // Find max for systematics


  max_alpgen_sf_diff =
    (fabs(avg_alpgen_sf - alpgen_sf[nLowSB]) > fabs(avg_alpgen_sf - alpgen_sf[nHighSB])) ?
    fabs(avg_alpgen_sf - alpgen_sf[nLowSB]) :
    fabs(avg_alpgen_sf - alpgen_sf[nHighSB]);

  //max_alpgen_sf_diff/=avg_alpgen_sf;
    
  // max_sherpa_sf_diff =
  //   (fabs(avg_sherpa_sf - sherpa_sf[nLowSB]) > fabs(avg_sherpa_sf - sherpa_sf[nHighSB])) ?
  //   fabs(avg_sherpa_sf - sherpa_sf[nLowSB]) :
  //   fabs(avg_sherpa_sf - sherpa_sf[nHighSB]);

  //max_sherpa_sf_diff/=avg_sherpa_sf;
  
  string avg_sf_out_file_name = "./logs/vjets_avg_sf.csv";
  std::ofstream avg_sf_out_file(avg_sf_out_file_name.c_str());
  avg_sf_out_file.precision(3);
  avg_sf_out_file.setf(ios::fixed,ios::floatfield);
  avg_sf_out_file<<"alpgen_sf,alpgen_sys,alpgen_stat,";
  avg_sf_out_file<<"sherpa_sf,sherpa_sys,sherpa_stat"<<endl;

  avg_sf_out_file<<avg_alpgen_sf<<","<<max_alpgen_sf_diff<<","<<err_alpgen_sf<<",";
  avg_sf_out_file<<avg_sherpa_sf<<","<<max_sherpa_sf_diff<<","<<err_sherpa_sf<<endl;
  cout<<"Weighted averages"<<endl;
  cout<<"alpgen_sf: "<<avg_alpgen_sf<<" /\pm "<<err_alpgen_sf<<endl;
  cout<<"sherpa_sf: "<<avg_sherpa_sf<<" /\pm "<<err_sherpa_sf<<endl;
  
  cout<<"--"<<endl;
  cout<<"data written to ./logs/vjets_avg_sf.csv and ./logs/vjets_{sideband}_sf.csv"<<endl;


  return;
}
