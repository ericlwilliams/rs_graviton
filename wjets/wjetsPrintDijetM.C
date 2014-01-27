//////////////////////////////////////////////////
// Loads plot files from ../plots/ctrl_plots/...
// plots regarding wjets normalization and systematics
//////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <vector>

#include <TBox.h>
#include <TLine.h>
#include <TCanvas.h>
#include <TAxis.h>
#include <TLegend.h>
#include <THStack.h>
#include "TH1.h"
#include <TFile.h>
#include "../include/atlasstyle-00-03-04/AtlasStyle.C";

float ratio_split=0.35;
string plot_var = "Mt(lep,MET,dijet)";
void wjetsPrintDijetM(){
  SetAtlasStyle();
  
  gROOT->SetBatch();
  gStyle->SetPalette(1);

  // gROOT->SetStyle("Plain");  
  // gStyle->SetOptStat(0);
  // gStyle->SetPalette(1);
  // gStyle->SetPadTickX(1);
  // gStyle->SetPadTickY(1);
  // //gStyle->SetFillStyle(3144);
  
  // gROOT->SetBatch();
  
  
  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In wjetsPrintSystematics.C"<<endl;

  const int nProcs = 2;
  string procs[nProcs] = {"elec", "muon"};

  string file_loc = "/Users/elw/Dropbox/eMacs/analy/lvjj/plots/ctrl_plots/";

  //////////////////////////////////////////////////
  // Load Data
  ////////////////////////////////////////////////// 
  
  string data_loc = file_loc+"merged/data.lnuj.ctrl.plot.root";
  TFile* data = TFile::Open(data_loc.c_str());
  TH1F* h_data_highm_elec_dijet_m_dijet_m = (TH1F*) data->Get("h_ctrl_highm_elec_dijet_m_zoom_dijet_m");
  h_data_highm_elec_dijet_m_dijet_m->SetDirectory(0);
  //h_data_highm_elec_dijet_m_dijet_m->Rebin(50);
  TH1F* h_data_highm_muon_dijet_m_dijet_m = (TH1F*) data->Get("h_ctrl_highm_muon_dijet_m_zoom_dijet_m");
  h_data_highm_muon_dijet_m_dijet_m->SetDirectory(0);
  //h_data_highm_muon_dijet_m_dijet_m->Rebin(50);
  TH1F* h_data_highm_comb_dijet_m_dijet_m = (TH1F*) h_data_highm_elec_dijet_m_dijet_m->Clone();
  h_data_highm_comb_dijet_m_dijet_m->Add((TH1F*) h_data_highm_muon_dijet_m_dijet_m->Clone());
  h_data_highm_comb_dijet_m_dijet_m->SetDirectory(0);

  data->Close();

  string wprime_m800_loc = file_loc+"merged/mc.wprime.wz.m800.ctrl.plot.root";
  TFile* wprime_m800 = TFile::Open(wprime_m800_loc.c_str());
  TH1F* h_wprime_m800_highm_elec_dijet_pt_dijet_m = (TH1F*) wprime_m800->Get("h_ctrl_highm_elec_dijet_pt_zoom_dijet_m");
  h_wprime_m800_highm_elec_dijet_pt_dijet_m->SetDirectory(0);
  //h_wprime_m800_highm_elec_dijet_pt_dijet_m->Rebin(50);
  TH1F* h_wprime_m800_highm_muon_dijet_pt_dijet_m = (TH1F*) wprime_m800->Get("h_ctrl_highm_muon_dijet_pt_zoom_dijet_m");
  h_wprime_m800_highm_muon_dijet_pt_dijet_m->SetDirectory(0);
  //h_wprime_m800_highm_muon_dijet_pt_dijet_m->Rebin(50);
  TH1F* h_wprime_m800_highm_comb_dijet_pt_dijet_m = (TH1F*) h_wprime_m800_highm_elec_dijet_pt_dijet_m->Clone();
  h_wprime_m800_highm_comb_dijet_pt_dijet_m->Add((TH1F*) h_wprime_m800_highm_muon_dijet_pt_dijet_m->Clone());
  h_wprime_m800_highm_comb_dijet_pt_dijet_m->SetDirectory(0);

  wprime_m800->Close();

  string rsg_m750_loc = file_loc+"merged/mc.rsg.m750.kmpl0_1.ctrl.plot.root";
  TFile* rsg_m750 = TFile::Open(rsg_m750_loc.c_str());
  TH1F* h_rsg_m750_highm_elec_dijet_pt_dijet_m = (TH1F*) rsg_m750->Get("h_ctrl_highm_elec_dijet_pt_zoom_dijet_m");
  h_rsg_m750_highm_elec_dijet_pt_dijet_m->SetDirectory(0);
  //h_rsg_m750_highm_elec_dijet_pt_dijet_m->Rebin(50);
  TH1F* h_rsg_m750_highm_muon_dijet_pt_dijet_m = (TH1F*) rsg_m750->Get("h_ctrl_highm_muon_dijet_pt_zoom_dijet_m");
  h_rsg_m750_highm_muon_dijet_pt_dijet_m->SetDirectory(0);
  //h_rsg_m750_highm_muon_dijet_pt_dijet_m->Rebin(50);
  TH1F* h_rsg_m750_highm_comb_dijet_pt_dijet_m = (TH1F*) h_rsg_m750_highm_elec_dijet_pt_dijet_m->Clone();
  h_rsg_m750_highm_comb_dijet_pt_dijet_m->Add((TH1F*) h_rsg_m750_highm_muon_dijet_pt_dijet_m->Clone());
  h_rsg_m750_highm_comb_dijet_pt_dijet_m->SetDirectory(0);

  rsg_m750->Close();

  

  //////////////////////////////////////////////////
  // Load Scaled Backgrounds
  //////////////////////////////////////////////////   
  //string sherpa_wjets_loc = file_loc+"merged/mc.sherpa.wjets.ctrl.plot.root";
  string alpgen_wjets_loc = file_loc+"merged/mc.alpgen.wjets.ctrl.plot.root";
  string vv_loc = file_loc+"merged/mc.herwig.vv.ctrl.plot.root";
  string alpgen_qcd_loc = file_loc+"merged/qcd.alpgen.ctrl.plot.root";
  //string sherpa_qcd_loc = file_loc+"merged/qcd.sherpa.ctrl.plot.root";
  string top_loc = file_loc+"merged/mc.mcatnlo.top.ctrl.plot.root";  
  string alpgen_zjets_loc = file_loc+"merged/mc.alpgen.zjets.ctrl.plot.root";
  //string sherpa_zjets_loc = file_loc+"merged/mc.sherpa.zjets.ctrl.plot.root";

  // TFile* sherpa_wjets = TFile::Open(sherpa_wjets_loc.c_str());  
  // TH1F* h_sherpa_wjets_highm_elec_dijet_pt_dijet_m = (TH1F*) sherpa_wjets->Get("h_ctrl_highm_elec_dijet_pt_zoom_dijet_m");
  // h_sherpa_wjets_highm_elec_dijet_pt_dijet_m->SetDirectory(0);
  // TH1F* h_sherpa_wjets_highm_muon_dijet_pt_dijet_m = (TH1F*) sherpa_wjets->Get("h_ctrl_highm_muon_dijet_pt_zoom_dijet_m");
  // h_sherpa_wjets_highm_muon_dijet_pt_dijet_m->SetDirectory(0);
  // TH1F* h_sherpa_wjets_highm_comb_dijet_pt_dijet_m = (TH1F*) h_sherpa_wjets_highm_elec_dijet_pt_dijet_m->Clone();
  // h_sherpa_wjets_highm_comb_dijet_pt_dijet_m->Add((TH1F*) h_sherpa_wjets_highm_muon_dijet_pt_dijet_m->Clone());
  // h_sherpa_wjets_highm_comb_dijet_pt_dijet_m->SetDirectory(0);
  // sherpa_wjets->Close();

  // TFile* sherpa_zjets = TFile::Open(sherpa_zjets_loc.c_str());  
  // TH1F* h_sherpa_zjets_highm_elec_dijet_pt_dijet_m = (TH1F*) sherpa_zjets->Get("h_ctrl_highm_elec_dijet_pt_zoom_dijet_m");
  // h_sherpa_zjets_highm_elec_dijet_pt_dijet_m->SetDirectory(0);
  // TH1F* h_sherpa_zjets_highm_muon_dijet_pt_dijet_m = (TH1F*) sherpa_zjets->Get("h_ctrl_highm_muon_dijet_pt_zoom_dijet_m");
  // h_sherpa_zjets_highm_muon_dijet_pt_dijet_m->SetDirectory(0);
  // TH1F* h_sherpa_zjets_highm_comb_dijet_pt_dijet_m = (TH1F*) h_sherpa_zjets_highm_elec_dijet_pt_dijet_m->Clone();
  // h_sherpa_zjets_highm_comb_dijet_pt_dijet_m->Add((TH1F*) h_sherpa_zjets_highm_muon_dijet_pt_dijet_m->Clone());
  // h_sherpa_zjets_highm_comb_dijet_pt_dijet_m->SetDirectory(0);
  // sherpa_zjets->Close();

  // TFile* sherpa_qcd = TFile::Open(sherpa_qcd_loc.c_str());  
  // TH1F* h_sherpa_qcd_highm_elec_dijet_pt_dijet_m = (TH1F*) sherpa_qcd->Get("h_ctrl_highm_elec_dijet_pt_zoom_dijet_m");
  // h_sherpa_qcd_highm_elec_dijet_pt_dijet_m->SetDirectory(0);
  // TH1F* h_sherpa_qcd_highm_muon_dijet_pt_dijet_m = (TH1F*) sherpa_qcd->Get("h_ctrl_highm_muon_dijet_pt_zoom_dijet_m");
  // h_sherpa_qcd_highm_muon_dijet_pt_dijet_m->SetDirectory(0);
  // TH1F* h_sherpa_qcd_highm_comb_dijet_pt_dijet_m = (TH1F*) h_sherpa_qcd_highm_elec_dijet_pt_dijet_m->Clone();
  // h_sherpa_qcd_highm_comb_dijet_pt_dijet_m->Add((TH1F*) h_sherpa_qcd_highm_muon_dijet_pt_dijet_m->Clone());
  // h_sherpa_qcd_highm_comb_dijet_pt_dijet_m->SetDirectory(0);
  // sherpa_qcd->Close();

  TFile* alpgen_wjets = TFile::Open(alpgen_wjets_loc.c_str());  
  TH1F* h_alpgen_wjets_highm_elec_dijet_pt_dijet_m = (TH1F*) alpgen_wjets->Get("h_ctrl_highm_elec_dijet_pt_zoom_dijet_m");
  h_alpgen_wjets_highm_elec_dijet_pt_dijet_m->SetDirectory(0);
  TH1F* h_alpgen_wjets_highm_muon_dijet_pt_dijet_m = (TH1F*) alpgen_wjets->Get("h_ctrl_highm_muon_dijet_pt_zoom_dijet_m");
  h_alpgen_wjets_highm_muon_dijet_pt_dijet_m->SetDirectory(0);
  TH1F* h_alpgen_wjets_highm_comb_dijet_pt_dijet_m = (TH1F*) h_alpgen_wjets_highm_elec_dijet_pt_dijet_m->Clone();
  h_alpgen_wjets_highm_comb_dijet_pt_dijet_m->Add((TH1F*) h_alpgen_wjets_highm_muon_dijet_pt_dijet_m->Clone());
  h_alpgen_wjets_highm_comb_dijet_pt_dijet_m->SetDirectory(0);
  alpgen_wjets->Close();

  TFile* alpgen_zjets = TFile::Open(alpgen_zjets_loc.c_str());  
  TH1F* h_alpgen_zjets_highm_elec_dijet_pt_dijet_m = (TH1F*) alpgen_zjets->Get("h_ctrl_highm_elec_dijet_pt_zoom_dijet_m");
  h_alpgen_zjets_highm_elec_dijet_pt_dijet_m->SetDirectory(0);
  TH1F* h_alpgen_zjets_highm_muon_dijet_pt_dijet_m = (TH1F*) alpgen_zjets->Get("h_ctrl_highm_muon_dijet_pt_zoom_dijet_m");
  h_alpgen_zjets_highm_muon_dijet_pt_dijet_m->SetDirectory(0);
  TH1F* h_alpgen_zjets_highm_comb_dijet_pt_dijet_m = (TH1F*) h_alpgen_zjets_highm_elec_dijet_pt_dijet_m->Clone();
  h_alpgen_zjets_highm_comb_dijet_pt_dijet_m->Add((TH1F*) h_alpgen_zjets_highm_muon_dijet_pt_dijet_m->Clone());
  h_alpgen_zjets_highm_comb_dijet_pt_dijet_m->SetDirectory(0);
  alpgen_zjets->Close();


  TFile* alpgen_qcd = TFile::Open(alpgen_qcd_loc.c_str());  
  TH1F* h_alpgen_qcd_highm_elec_dijet_pt_dijet_m = (TH1F*) alpgen_qcd->Get("h_ctrl_highm_elec_dijet_pt_zoom_dijet_m");
  h_alpgen_qcd_highm_elec_dijet_pt_dijet_m->SetDirectory(0);
  TH1F* h_alpgen_qcd_highm_muon_dijet_pt_dijet_m = (TH1F*) alpgen_qcd->Get("h_ctrl_highm_muon_dijet_pt_zoom_dijet_m");
  h_alpgen_qcd_highm_muon_dijet_pt_dijet_m->SetDirectory(0);
  TH1F* h_alpgen_qcd_highm_comb_dijet_pt_dijet_m = (TH1F*) h_alpgen_qcd_highm_elec_dijet_pt_dijet_m->Clone();
  h_alpgen_qcd_highm_comb_dijet_pt_dijet_m->Add((TH1F*) h_alpgen_qcd_highm_muon_dijet_pt_dijet_m->Clone());
  h_alpgen_qcd_highm_comb_dijet_pt_dijet_m->SetDirectory(0);
  alpgen_qcd->Close();

  TFile* top = TFile::Open(top_loc.c_str());  
  TH1F* h_top_highm_elec_dijet_pt_dijet_m = (TH1F*) top->Get("h_ctrl_highm_elec_dijet_pt_zoom_dijet_m");
  h_top_highm_elec_dijet_pt_dijet_m->SetDirectory(0);
  TH1F* h_top_highm_muon_dijet_pt_dijet_m = (TH1F*) top->Get("h_ctrl_highm_muon_dijet_pt_zoom_dijet_m");
  h_top_highm_muon_dijet_pt_dijet_m->SetDirectory(0);
  TH1F* h_top_highm_comb_dijet_pt_dijet_m = (TH1F*) h_top_highm_elec_dijet_pt_dijet_m->Clone();
  h_top_highm_comb_dijet_pt_dijet_m->Add((TH1F*) h_top_highm_muon_dijet_pt_dijet_m->Clone());
  h_top_highm_comb_dijet_pt_dijet_m->SetDirectory(0);
  top->Close();

  TFile* vv = TFile::Open(vv_loc.c_str());  
  TH1F* h_vv_highm_elec_dijet_pt_dijet_m = (TH1F*) vv->Get("h_ctrl_highm_elec_dijet_pt_zoom_dijet_m");
  h_vv_highm_elec_dijet_pt_dijet_m->SetDirectory(0);
  TH1F* h_vv_highm_muon_dijet_pt_dijet_m = (TH1F*) vv->Get("h_ctrl_highm_muon_dijet_pt_zoom_dijet_m");
  h_vv_highm_muon_dijet_pt_dijet_m->SetDirectory(0);
  TH1F* h_vv_highm_comb_dijet_pt_dijet_m = (TH1F*) h_vv_highm_elec_dijet_pt_dijet_m->Clone();
  h_vv_highm_comb_dijet_pt_dijet_m->Add((TH1F*) h_vv_highm_muon_dijet_pt_dijet_m->Clone());
  h_vv_highm_comb_dijet_pt_dijet_m->SetDirectory(0);
  vv->Close();

  //////////////////////////////////////////////////
  // Histogram selection
  // - these histograms (in controlPlots.C) have been prepared with
  //   more bins for rebinning and
  // - data,  lowm/highm control regions (w/ mass cut)
  // - mc, lowm/highm control regions (*before* mass cut)
  ////////////////////////////////////////////////// 
  

  //////////////////////////////////////////////////
  // highm_dijet_m
  //////////////////////////////////////////////////

  // TH1F* h_data_highm_comb_dijet_m_dijet_m = (TH1F*) h_data_highm_elec_dijet_m_dijet_m->Clone();
  // h_data_highm_comb_dijet_m_dijet_m->Add((TH1F*) h_data_highm_muon_dijet_m_dijet_m->Clone());

  // h_sherpa_wjets_highm_elec_dijet_pt_dijet_m->Add(h_sherpa_qcd_highm_elec_dijet_pt_dijet_m);
  // h_sherpa_wjets_highm_elec_dijet_pt_dijet_m->Add(h_vv_highm_elec_dijet_pt_dijet_m);
  // h_sherpa_wjets_highm_elec_dijet_pt_dijet_m->Add(h_top_highm_elec_dijet_pt_dijet_m);
  // h_sherpa_wjets_highm_elec_dijet_pt_dijet_m->Add(h_sherpa_zjets_highm_elec_dijet_pt_dijet_m);
  // //h_sherpa_wjets_highm_elec_dijet_pt_dijet_m->Rebin(50);

  // h_alpgen_wjets_highm_elec_dijet_pt_dijet_m->Add(h_alpgen_qcd_highm_elec_dijet_pt_dijet_m);
  // h_alpgen_wjets_highm_elec_dijet_pt_dijet_m->Add(h_vv_highm_elec_dijet_pt_dijet_m);
  // h_alpgen_wjets_highm_elec_dijet_pt_dijet_m->Add(h_top_highm_elec_dijet_pt_dijet_m);
  // h_alpgen_wjets_highm_elec_dijet_pt_dijet_m->Add(h_alpgen_zjets_highm_elec_dijet_pt_dijet_m);
  // //h_alpgen_wjets_highm_elec_dijet_pt_dijet_m->Rebin(50);
  
  // TCanvas* tc_highm_elec_dijet_m = new TCanvas("tc_highm_elec_dijet_m","tc_highm_elec_dijet_m",0,0,1920,1200);

  // // h_sherpa_wjets_highm_elec_dijet_pt_dijet_m->SetLineColor(kBlue);
  // // h_sherpa_wjets_highm_elec_dijet_pt_dijet_m->SetTitle("");
  // // h_sherpa_wjets_highm_elec_dijet_pt_dijet_m->GetXaxis()->SetTitle("Dijet Mass");
  // // h_sherpa_wjets_highm_elec_dijet_pt_dijet_m->Draw("HIST");

  // h_alpgen_wjets_highm_elec_dijet_pt_dijet_m->SetLineColor(kRed);
  // h_alpgen_wjets_highm_elec_dijet_pt_dijet_m->Draw("HIST");

  // h_data_highm_elec_dijet_m_dijet_m->SetMarkerStyle(8);
  // h_data_highm_elec_dijet_m_dijet_m->Draw("HIST sames PE");

  // //tc_highm_elec_dijet_m->SetLogy();
  // tc_highm_elec_dijet_m->Update();


  // TLegend* tl_highm_elec_dijet_m = new TLegend(0.63,0.8,0.9,0.9);
  // tl_highm_elec_dijet_m->SetFillColor(0);
  // tl_highm_elec_dijet_m->SetTextSize(0.03);
  // tl_highm_elec_dijet_m->AddEntry(h_data_highm_elec_dijet_m_dijet_m,"data","L");
  // tl_highm_elec_dijet_m->AddEntry(h_alpgen_wjets_highm_elec_dijet_pt_dijet_m,"Bkgd w/ ALPGEN wjets","L");
  // //tl_highm_elec_dijet_m->AddEntry(h_sherpa_wjets_highm_elec_dijet_pt_dijet_m,"Bkgd w/ SHERPA wjets","L");
  // tl_highm_elec_dijet_m->Draw();



  // string cur_saveas = "../canvases/latest/h_highm_elec_dijet_m.pdf";
  // tc_highm_elec_dijet_m->SaveAs(cur_saveas.c_str());
  

  //////////////////////////////////////////////////
  // highm_muon_dijet_m
  ////////////////////////////////////////////////// 
  
  // h_sherpa_wjets_highm_muon_dijet_pt_dijet_m->Add(h_sherpa_qcd_highm_muon_dijet_pt_dijet_m);
  // h_sherpa_wjets_highm_muon_dijet_pt_dijet_m->Add(h_vv_highm_muon_dijet_pt_dijet_m);
  // h_sherpa_wjets_highm_muon_dijet_pt_dijet_m->Add(h_top_highm_muon_dijet_pt_dijet_m);
  // h_sherpa_wjets_highm_muon_dijet_pt_dijet_m->Add(h_sherpa_zjets_highm_muon_dijet_pt_dijet_m);
  // //h_sherpa_wjets_highm_muon_dijet_pt_dijet_m->Rebin(50);

  // h_alpgen_wjets_highm_muon_dijet_pt_dijet_m->Add(h_alpgen_qcd_highm_muon_dijet_pt_dijet_m);
  // h_alpgen_wjets_highm_muon_dijet_pt_dijet_m->Add(h_vv_highm_muon_dijet_pt_dijet_m);
  // h_alpgen_wjets_highm_muon_dijet_pt_dijet_m->Add(h_top_highm_muon_dijet_pt_dijet_m);
  // h_alpgen_wjets_highm_muon_dijet_pt_dijet_m->Add(h_alpgen_zjets_highm_muon_dijet_pt_dijet_m);
  // ///h_alpgen_wjets_highm_muon_dijet_pt_dijet_m->Rebin(50);
  
  // TCanvas* tc_highm_muon_dijet_m = new TCanvas("tc_highm_muon_dijet_m","tc_highm_muon_dijet_m",0,0,1920,1200);

  // // h_sherpa_wjets_highm_muon_dijet_pt_dijet_m->SetLineColor(kBlue);
  // // h_sherpa_wjets_highm_muon_dijet_pt_dijet_m->GetXaxis()->SetTitle("Dijet Mass");
  // // h_sherpa_wjets_highm_muon_dijet_pt_dijet_m->SetTitle("");
  // // h_sherpa_wjets_highm_muon_dijet_pt_dijet_m->Draw("HIST");

  // h_alpgen_wjets_highm_muon_dijet_pt_dijet_m->SetLineColor(kRed);
  // h_alpgen_wjets_highm_muon_dijet_pt_dijet_m->Draw("HIST");

  // h_data_highm_muon_dijet_m_dijet_m->SetMarkerStyle(8);
  // h_data_highm_muon_dijet_m_dijet_m->Draw("HIST sames PE");

  // //tc_highm_muon_dijet_m->SetLogy();
  // tc_highm_muon_dijet_m->Update();
  
  // TLegend* tl_highm_muon_dijet_m = new TLegend(0.63,0.8,0.9,0.9);
  // tl_highm_muon_dijet_m->SetFillColor(0);
  // tl_highm_muon_dijet_m->SetTextSize(0.03);
  // tl_highm_muon_dijet_m->AddEntry(h_data_highm_muon_dijet_m_dijet_m,"data","L");
  // tl_highm_muon_dijet_m->AddEntry(h_alpgen_wjets_highm_muon_dijet_pt_dijet_m,"Bkgd w/ ALPGEN wjets","L");
  // //tl_highm_muon_dijet_m->AddEntry(h_sherpa_wjets_highm_muon_dijet_pt_dijet_m,"Bkgd w/ SHERPA wjets","L");
  // tl_highm_muon_dijet_m->Draw();
  
  // string cur_saveas = "../canvases/latest/h_highm_muon_dijet_m.pdf";
  // tc_highm_muon_dijet_m->SaveAs(cur_saveas.c_str());



  h_alpgen_wjets_highm_comb_dijet_pt_dijet_m->Add(h_alpgen_zjets_highm_comb_dijet_pt_dijet_m);
  h_alpgen_wjets_highm_comb_dijet_pt_dijet_m->Add(h_alpgen_qcd_highm_comb_dijet_pt_dijet_m);
  h_alpgen_wjets_highm_comb_dijet_pt_dijet_m->Add(h_top_highm_comb_dijet_pt_dijet_m);
  h_alpgen_wjets_highm_comb_dijet_pt_dijet_m->Add(h_vv_highm_comb_dijet_pt_dijet_m);
    
  
  TCanvas* tc_highm_comb_dijet_m = new TCanvas("tc_highm_comb_dijet_m","tc_highm_comb_dijet_m",0,0,1920,1200);

  h_alpgen_wjets_highm_comb_dijet_pt_dijet_m->SetLineColor(kBlue-4);
  h_alpgen_wjets_highm_comb_dijet_pt_dijet_m->SetLineWidth(2);
  h_alpgen_wjets_highm_comb_dijet_pt_dijet_m->GetXaxis()->SetTitle("M(jj) [GeV]");
  h_alpgen_wjets_highm_comb_dijet_pt_dijet_m->Draw("HIST");

  TLine comb_cut_line;
  TBox comb_cut_box;

  float comb_ymax = h_alpgen_wjets_highm_comb_dijet_pt_dijet_m->GetMaximum();
  comb_cut_line=TLine(65,0,65,comb_ymax*1.05);
  comb_cut_line.SetLineWidth(2);
  comb_cut_line.SetLineStyle(2);
  comb_cut_line.SetLineColor(kGray+3);
  comb_cut_line.DrawClone();

  double xmax = h_alpgen_wjets_highm_comb_dijet_pt_dijet_m->GetXaxis()->GetXmax();
  double xmin = h_alpgen_wjets_highm_comb_dijet_pt_dijet_m->GetXaxis()->GetXmin();

  double range = xmax-xmin;
  comb_cut_box = TBox(65-(range/30.),0,65,comb_ymax*1.05);
  comb_cut_box.SetFillStyle(3345);
  comb_cut_box.SetFillColor(kGray+2);
  comb_cut_box.DrawClone();

  comb_cut_line=TLine(115,0,115,comb_ymax*1.05);
  comb_cut_line.SetLineWidth(2);
  comb_cut_line.SetLineStyle(2);
  comb_cut_line.SetLineColor(kGray+3);
  comb_cut_line.DrawClone();

  comb_cut_box = TBox(115,0,115+(range/30.),comb_ymax*1.05);
  comb_cut_box.SetFillStyle(3345);
  comb_cut_box.SetFillColor(kGray+2);
  comb_cut_box.DrawClone();

  h_data_highm_comb_dijet_m_dijet_m->SetMarkerStyle(8);
  h_data_highm_comb_dijet_m_dijet_m->SetMarkerSize(3);
  h_data_highm_comb_dijet_m_dijet_m->Draw("HIST sames PE");

  // h_wprime_m800_highm_comb_dijet_pt_dijet_m->SetLineColor(kBlue);
  // h_wprime_m800_highm_comb_dijet_pt_dijet_m->SetLineWidth(2);
  // h_wprime_m800_highm_comb_dijet_pt_dijet_m->Draw("HIST sames");

  h_rsg_m750_highm_comb_dijet_pt_dijet_m->SetLineColor(kRed);
  h_rsg_m750_highm_comb_dijet_pt_dijet_m->SetLineWidth(2);
  h_rsg_m750_highm_comb_dijet_pt_dijet_m->Draw("HIST sames");


  //tc_highm_comb_dijet_m->SetLogy();
  tc_highm_comb_dijet_m->Update();
  
  TLegend* tl_highm_comb_dijet_m = new TLegend(0.63,0.7,0.9,0.9);
  tl_highm_comb_dijet_m->SetFillColor(0);
  tl_highm_comb_dijet_m->SetTextSize(0.04);
  tl_highm_comb_dijet_m->AddEntry(h_data_highm_comb_dijet_m_dijet_m,"data","P");
  tl_highm_comb_dijet_m->AddEntry(h_alpgen_wjets_highm_comb_dijet_pt_dijet_m,"MC backgrounds","L");
  tl_highm_comb_dijet_m->AddEntry(h_rsg_m750_highm_comb_dijet_pt_dijet_m,"G* (750 GeV)","L");
  //tl_highm_comb_dijet_m->AddEntry(h_sherpa_wjets_highm_comb_dijet_pt_dijet_m,"Bkgd w/ SHERPA wjets","L");
  tl_highm_comb_dijet_m->Draw();
  
  string cur_saveas = "../canvases/latest/h_highm_comb_dijet_m.pdf";
  tc_highm_comb_dijet_m->SaveAs(cur_saveas.c_str());




  h_alpgen_wjets_highm_elec_dijet_pt_dijet_m->Add(h_alpgen_zjets_highm_elec_dijet_pt_dijet_m);
  h_alpgen_wjets_highm_elec_dijet_pt_dijet_m->Add(h_alpgen_qcd_highm_elec_dijet_pt_dijet_m);
  h_alpgen_wjets_highm_elec_dijet_pt_dijet_m->Add(h_top_highm_elec_dijet_pt_dijet_m);
  h_alpgen_wjets_highm_elec_dijet_pt_dijet_m->Add(h_vv_highm_elec_dijet_pt_dijet_m);
    
  
  TCanvas* tc_highm_elec_dijet_m = new TCanvas("tc_highm_elec_dijet_m","tc_highm_elec_dijet_m",0,0,1920,1200);

  h_alpgen_wjets_highm_elec_dijet_pt_dijet_m->SetLineColor(kBlue-4);
  h_alpgen_wjets_highm_elec_dijet_pt_dijet_m->SetLineWidth(2);
  h_alpgen_wjets_highm_elec_dijet_pt_dijet_m->GetXaxis()->SetTitle("M(jj) [GeV]");
  h_alpgen_wjets_highm_elec_dijet_pt_dijet_m->Draw("HIST");

  TLine elec_cut_line;
  TBox elec_cut_box;

  float elec_ymax = h_alpgen_wjets_highm_elec_dijet_pt_dijet_m->GetMaximum();
  elec_cut_line=TLine(65,0,65,elec_ymax*1.05);
  elec_cut_line.SetLineWidth(2);
  elec_cut_line.SetLineStyle(2);
  elec_cut_line.SetLineColor(kGray+3);
  elec_cut_line.DrawClone();

  double xmax = h_alpgen_wjets_highm_elec_dijet_pt_dijet_m->GetXaxis()->GetXmax();
  double xmin = h_alpgen_wjets_highm_elec_dijet_pt_dijet_m->GetXaxis()->GetXmin();

  double range = xmax-xmin;
  elec_cut_box = TBox(65-(range/30.),0,65,elec_ymax*1.05);
  elec_cut_box.SetFillStyle(3345);
  elec_cut_box.SetFillColor(kGray+2);
  elec_cut_box.DrawClone();

  elec_cut_line=TLine(115,0,115,elec_ymax*1.05);
  elec_cut_line.SetLineWidth(2);
  elec_cut_line.SetLineStyle(2);
  elec_cut_line.SetLineColor(kGray+3);
  elec_cut_line.DrawClone();

  elec_cut_box = TBox(115,0,115+(range/30.),elec_ymax*1.05);
  elec_cut_box.SetFillStyle(3345);
  elec_cut_box.SetFillColor(kGray+2);
  elec_cut_box.DrawClone();

  h_data_highm_elec_dijet_m_dijet_m->SetMarkerStyle(8);
  h_data_highm_elec_dijet_m_dijet_m->SetMarkerSize(3);
  h_data_highm_elec_dijet_m_dijet_m->Draw("HIST sames PE");

  // h_wprime_m800_highm_elec_dijet_pt_dijet_m->SetLineColor(kBlue);
  // h_wprime_m800_highm_elec_dijet_pt_dijet_m->SetLineWidth(2);
  // h_wprime_m800_highm_elec_dijet_pt_dijet_m->Draw("HIST sames");

  h_rsg_m750_highm_elec_dijet_pt_dijet_m->SetLineColor(kRed);
  h_rsg_m750_highm_elec_dijet_pt_dijet_m->SetLineWidth(2);
  h_rsg_m750_highm_elec_dijet_pt_dijet_m->Draw("HIST sames");


  //tc_highm_elec_dijet_m->SetLogy();
  tc_highm_elec_dijet_m->Update();
  
  TLegend* tl_highm_elec_dijet_m = new TLegend(0.63,0.7,0.9,0.9);
  tl_highm_elec_dijet_m->SetFillColor(0);
  tl_highm_elec_dijet_m->SetTextSize(0.04);
  tl_highm_elec_dijet_m->AddEntry(h_data_highm_elec_dijet_m_dijet_m,"data","P");
  tl_highm_elec_dijet_m->AddEntry(h_alpgen_wjets_highm_elec_dijet_pt_dijet_m,"MC backgrounds","L");
  tl_highm_elec_dijet_m->AddEntry(h_rsg_m750_highm_elec_dijet_pt_dijet_m,"G* (750 GeV)","L");
  //tl_highm_elec_dijet_m->AddEntry(h_sherpa_wjets_highm_elec_dijet_pt_dijet_m,"Bkgd w/ SHERPA wjets","L");
  tl_highm_elec_dijet_m->Draw();
  
  string cur_saveas = "../canvases/latest/h_highm_elec_dijet_m.pdf";
  tc_highm_elec_dijet_m->SaveAs(cur_saveas.c_str());




  h_alpgen_wjets_highm_muon_dijet_pt_dijet_m->Add(h_alpgen_zjets_highm_muon_dijet_pt_dijet_m);
  h_alpgen_wjets_highm_muon_dijet_pt_dijet_m->Add(h_alpgen_qcd_highm_muon_dijet_pt_dijet_m);
  h_alpgen_wjets_highm_muon_dijet_pt_dijet_m->Add(h_top_highm_muon_dijet_pt_dijet_m);
  h_alpgen_wjets_highm_muon_dijet_pt_dijet_m->Add(h_vv_highm_muon_dijet_pt_dijet_m);
    
  
  TCanvas* tc_highm_muon_dijet_m = new TCanvas("tc_highm_muon_dijet_m","tc_highm_muon_dijet_m",0,0,1920,1200);

  h_alpgen_wjets_highm_muon_dijet_pt_dijet_m->SetLineColor(kBlue-4);
  h_alpgen_wjets_highm_muon_dijet_pt_dijet_m->SetLineWidth(2);
  h_alpgen_wjets_highm_muon_dijet_pt_dijet_m->GetXaxis()->SetTitle("M(jj) [GeV]");
  h_alpgen_wjets_highm_muon_dijet_pt_dijet_m->Draw("HIST");

  TLine muon_cut_line;
  TBox muon_cut_box;

  float muon_ymax = h_alpgen_wjets_highm_muon_dijet_pt_dijet_m->GetMaximum();
  muon_cut_line=TLine(65,0,65,muon_ymax*1.05);
  muon_cut_line.SetLineWidth(2);
  muon_cut_line.SetLineStyle(2);
  muon_cut_line.SetLineColor(kGray+3);
  muon_cut_line.DrawClone();

  double xmax = h_alpgen_wjets_highm_muon_dijet_pt_dijet_m->GetXaxis()->GetXmax();
  double xmin = h_alpgen_wjets_highm_muon_dijet_pt_dijet_m->GetXaxis()->GetXmin();

  double range = xmax-xmin;
  muon_cut_box = TBox(65-(range/30.),0,65,muon_ymax*1.05);
  muon_cut_box.SetFillStyle(3345);
  muon_cut_box.SetFillColor(kGray+2);
  muon_cut_box.DrawClone();

  muon_cut_line=TLine(115,0,115,muon_ymax*1.05);
  muon_cut_line.SetLineWidth(2);
  muon_cut_line.SetLineStyle(2);
  muon_cut_line.SetLineColor(kGray+3);
  muon_cut_line.DrawClone();

  muon_cut_box = TBox(115,0,115+(range/30.),muon_ymax*1.05);
  muon_cut_box.SetFillStyle(3345);
  muon_cut_box.SetFillColor(kGray+2);
  muon_cut_box.DrawClone();

  h_data_highm_muon_dijet_m_dijet_m->SetMarkerStyle(8);
  h_data_highm_muon_dijet_m_dijet_m->SetMarkerSize(3);
  h_data_highm_muon_dijet_m_dijet_m->Draw("HIST sames PE");

  // h_wprime_m800_highm_muon_dijet_pt_dijet_m->SetLineColor(kBlue);
  // h_wprime_m800_highm_muon_dijet_pt_dijet_m->SetLineWidth(2);
  // h_wprime_m800_highm_muon_dijet_pt_dijet_m->Draw("HIST sames");

  h_rsg_m750_highm_muon_dijet_pt_dijet_m->SetLineColor(kRed);
  h_rsg_m750_highm_muon_dijet_pt_dijet_m->SetLineWidth(2);
  h_rsg_m750_highm_muon_dijet_pt_dijet_m->Draw("HIST sames");


  //tc_highm_muon_dijet_m->SetLogy();
  tc_highm_muon_dijet_m->Update();
  
  TLegend* tl_highm_muon_dijet_m = new TLegend(0.63,0.7,0.9,0.9);
  tl_highm_muon_dijet_m->SetFillColor(0);
  tl_highm_muon_dijet_m->SetTextSize(0.04);
  tl_highm_muon_dijet_m->AddEntry(h_data_highm_muon_dijet_m_dijet_m,"data","P");
  tl_highm_muon_dijet_m->AddEntry(h_alpgen_wjets_highm_muon_dijet_pt_dijet_m,"MC backgrounds","L");
  tl_highm_muon_dijet_m->AddEntry(h_rsg_m750_highm_muon_dijet_pt_dijet_m,"G* (750 GeV)","L");
  //tl_highm_muon_dijet_m->AddEntry(h_sherpa_wjets_highm_muon_dijet_pt_dijet_m,"Bkgd w/ SHERPA wjets","L");
  tl_highm_muon_dijet_m->Draw();
  
  string cur_saveas = "../canvases/latest/h_highm_muon_dijet_m.pdf";
  tc_highm_muon_dijet_m->SaveAs(cur_saveas.c_str());



  

  // //////////////////////////////////////////////////
  // // ctrl_sig_muon_lvjj_mt
  // //////////////////////////////////////////////////

  // TH1F* h_data_ctrl_sig_elec_lvjj_mt = (TH1F*) data->Get("h_ctrl_highm_elec_dijet_m_lep_met_dijet_mt");
  // h_data_ctrl_sig_elec_lvjj_mt->GetXaxis()->SetRangeUser(0,1e3);
  // h_data_ctrl_sig_elec_lvjj_mt->Rebin(2);
  // TH1F* h_data_ctrl_sig_muon_lvjj_mt = (TH1F*) data->Get("h_ctrl_highm_muon_dijet_m_lep_met_dijet_mt");
  // //h_data_ctrl_sig_muon_lvjj_mt->Rebin(2);
  

  // TH1F* h_alpgen_wjets_ctrl_sig_elec_lvjj_mt = (TH1F*) alpgen_wjets->Get("h_ctrl_highm_elec_dijet_m_lep_met_dijet_mt");  
  // h_alpgen_wjets_ctrl_sig_elec_lvjj_mt->Rebin(2);
  // TH1F* h_alpgen_wjets_ctrl_sig_muon_lvjj_mt = (TH1F*) alpgen_wjets->Get("h_ctrl_highm_muon_dijet_m_lep_met_dijet_mt");
  // TH1F* h_vv_ctrl_sig_elec_lvjj_mt = (TH1F*) vv->Get("h_ctrl_highm_elec_dijet_m_lep_met_dijet_mt");
  // h_vv_ctrl_sig_elec_lvjj_mt->GetXaxis()->SetRangeUser(0,1e3);
  // h_vv_ctrl_sig_elec_lvjj_mt->Rebin(2);
  // TH1F* h_vv_ctrl_sig_muon_lvjj_mt = (TH1F*) vv->Get("h_ctrl_highm_muon_dijet_m_lep_met_dijet_mt");
  // TH1F* h_top_ctrl_sig_elec_lvjj_mt = (TH1F*) top->Get("h_ctrl_highm_elec_dijet_m_lep_met_dijet_mt");
  // h_top_ctrl_sig_elec_lvjj_mt->GetXaxis()->SetRangeUser(0,1e3);
  // h_top_ctrl_sig_elec_lvjj_mt->Rebin(2);
  // TH1F* h_top_ctrl_sig_muon_lvjj_mt = (TH1F*) top->Get("h_ctrl_highm_muon_dijet_m_lep_met_dijet_mt");
  // TH1F* h_alpgen_zjets_ctrl_sig_elec_lvjj_mt = (TH1F*) alpgen_zjets->Get("h_ctrl_highm_elec_dijet_m_lep_met_dijet_mt");
  // h_alpgen_zjets_ctrl_sig_elec_lvjj_mt->GetXaxis()->SetRangeUser(0,1e3);
  // h_alpgen_zjets_ctrl_sig_elec_lvjj_mt->Rebin(2);
  // TH1F* h_alpgen_zjets_ctrl_sig_muon_lvjj_mt =
  //   (TH1F*) alpgen_zjets->Get("h_ctrl_highm_muon_dijet_m_lep_met_dijet_mt");
  // TH1F* h_alpgen_qcd_ctrl_sig_elec_lvjj_mt =
  //   (TH1F*) alpgen_qcd->Get("h_ctrl_highm_elec_dijet_m_lep_met_dijet_mt");
  // h_alpgen_qcd_ctrl_sig_elec_lvjj_mt->GetXaxis()->SetRangeUser(0,1e3);
  // h_alpgen_qcd_ctrl_sig_elec_lvjj_mt->Rebin(2);
  // TH1F* h_alpgen_qcd_ctrl_sig_muon_lvjj_mt = (TH1F*) alpgen_qcd->Get("h_ctrl_highm_muon_dijet_m_lep_met_dijet_mt");

  // h_alpgen_wjets_ctrl_sig_elec_lvjj_mt->Add(h_alpgen_qcd_ctrl_sig_elec_lvjj_mt);
  // h_alpgen_wjets_ctrl_sig_elec_lvjj_mt->Add(h_vv_ctrl_sig_elec_lvjj_mt);
  // h_alpgen_wjets_ctrl_sig_elec_lvjj_mt->Add(h_top_ctrl_sig_elec_lvjj_mt);
  // h_alpgen_wjets_ctrl_sig_elec_lvjj_mt->Add(h_alpgen_zjets_ctrl_sig_elec_lvjj_mt);
  // //h_alpgen_wjets_ctrl_sig_elec_lvjj_mt->Rebin(2);
  

  // //////////////////////////////////////////////////
  // // Make ratio histos
  // ////////////////////////////////////////////////// 

  // TH1F* h_alpgen_ctrl_sig_elec_lvjj_mt_ratio = (TH1F*) h_data_ctrl_sig_elec_lvjj_mt->Clone();
  // h_alpgen_ctrl_sig_elec_lvjj_mt_ratio->Add(h_alpgen_wjets_ctrl_sig_elec_lvjj_mt,-1.);
  // h_alpgen_ctrl_sig_elec_lvjj_mt_ratio->
  //   Divide(h_alpgen_ctrl_sig_elec_lvjj_mt_ratio,h_alpgen_wjets_ctrl_sig_elec_lvjj_mt,1,1,"B");
  

  // //lowsb_highm
  // TH1F* h_data_lowsb_highm_elec_lvjj_mt = (TH1F*) data->Get("h_lowsb_highm_elec_dijet_m_lep_met_dijet_mt");
  // h_data_lowsb_highm_elec_lvjj_mt->GetXaxis()->SetRangeUser(0,1e3);
  // h_data_lowsb_highm_elec_lvjj_mt->Rebin(2);
  // TH1F* h_data_lowsb_highm_muon_lvjj_mt = (TH1F*) data->Get("h_lowsb_highm_muon_dijet_m_lep_met_dijet_mt");
  // //h_data_lowsb_highm_muon_lvjj_mt->Rebin(2);
  

  // TH1F* h_alpgen_wjets_lowsb_highm_elec_lvjj_mt = (TH1F*) alpgen_wjets->Get("h_lowsb_highm_elec_dijet_m_lep_met_dijet_mt");  
  // h_alpgen_wjets_lowsb_highm_elec_lvjj_mt->GetXaxis()->SetRangeUser(0,1e3);
  // h_alpgen_wjets_lowsb_highm_elec_lvjj_mt->Rebin(2);

  // TH1F* h_alpgen_wjets_lowsb_highm_muon_lvjj_mt = (TH1F*) alpgen_wjets->Get("h_lowsb_highm_muon_dijet_m_lep_met_dijet_mt");
  // TH1F* h_vv_lowsb_highm_elec_lvjj_mt = (TH1F*) vv->Get("h_lowsb_highm_elec_dijet_m_lep_met_dijet_mt");
  // h_vv_lowsb_highm_elec_lvjj_mt->GetXaxis()->SetRangeUser(0,1e3);
  // h_vv_lowsb_highm_elec_lvjj_mt->Rebin(2);

  // TH1F* h_vv_lowsb_highm_muon_lvjj_mt = (TH1F*) vv->Get("h_lowsb_highm_muon_dijet_m_lep_met_dijet_mt");
  // TH1F* h_top_lowsb_highm_elec_lvjj_mt = (TH1F*) top->Get("h_lowsb_highm_elec_dijet_m_lep_met_dijet_mt");
  // h_top_lowsb_highm_elec_lvjj_mt->GetXaxis()->SetRangeUser(0,1e3);
  // h_top_lowsb_highm_elec_lvjj_mt->Rebin(2);

  // TH1F* h_top_lowsb_highm_muon_lvjj_mt = (TH1F*) top->Get("h_lowsb_highm_muon_dijet_m_lep_met_dijet_mt");
  // TH1F* h_alpgen_zjets_lowsb_highm_elec_lvjj_mt = (TH1F*) alpgen_zjets->Get("h_lowsb_highm_elec_dijet_m_lep_met_dijet_mt");
  // h_alpgen_zjets_lowsb_highm_elec_lvjj_mt->GetXaxis()->SetRangeUser(0,1e3);
  // h_alpgen_zjets_lowsb_highm_elec_lvjj_mt->Rebin(2);

  // TH1F* h_alpgen_zjets_lowsb_highm_muon_lvjj_mt = (TH1F*) alpgen_zjets->Get("h_lowsb_highm_muon_dijet_m_lep_met_dijet_mt");
  // TH1F* h_alpgen_qcd_lowsb_highm_elec_lvjj_mt = (TH1F*) alpgen_qcd->Get("h_lowsb_highm_elec_dijet_m_lep_met_dijet_mt");
  // h_alpgen_qcd_lowsb_highm_elec_lvjj_mt->GetXaxis()->SetRangeUser(0,1e3);
  // h_alpgen_qcd_lowsb_highm_elec_lvjj_mt->Rebin(2);
  // TH1F* h_alpgen_qcd_lowsb_highm_muon_lvjj_mt = (TH1F*) alpgen_qcd->Get("h_lowsb_highm_muon_dijet_m_lep_met_dijet_mt");

  // h_alpgen_wjets_lowsb_highm_elec_lvjj_mt->Add(h_alpgen_qcd_lowsb_highm_elec_lvjj_mt);
  // h_alpgen_wjets_lowsb_highm_elec_lvjj_mt->Add(h_vv_lowsb_highm_elec_lvjj_mt);
  // h_alpgen_wjets_lowsb_highm_elec_lvjj_mt->Add(h_top_lowsb_highm_elec_lvjj_mt);
  // h_alpgen_wjets_lowsb_highm_elec_lvjj_mt->Add(h_alpgen_zjets_lowsb_highm_elec_lvjj_mt);
  // //h_alpgen_wjets_lowsb_highm_elec_lvjj_mt->Rebin(2);
  

  // //////////////////////////////////////////////////
  // // Make ratio histos
  // ////////////////////////////////////////////////// 

  // TH1F* h_alpgen_lowsb_highm_elec_lvjj_mt_ratio = (TH1F*) h_data_lowsb_highm_elec_lvjj_mt->Clone();
  // h_alpgen_lowsb_highm_elec_lvjj_mt_ratio->Add(h_alpgen_wjets_lowsb_highm_elec_lvjj_mt,-1.);
  // h_alpgen_lowsb_highm_elec_lvjj_mt_ratio->
  //   Divide(h_alpgen_lowsb_highm_elec_lvjj_mt_ratio,h_alpgen_wjets_lowsb_highm_elec_lvjj_mt,1,1,"B");
  
  // //highsb_highm
  // TH1F* h_data_highsb_highm_elec_lvjj_mt = (TH1F*) data->Get("h_highsb_highm_elec_dijet_m_lep_met_dijet_mt");
  // h_data_highsb_highm_elec_lvjj_mt->GetXaxis()->SetRangeUser(0,1e3);
  // h_data_highsb_highm_elec_lvjj_mt->Rebin(2);

  // TH1F* h_data_highsb_highm_muon_lvjj_mt = (TH1F*) data->Get("h_highsb_highm_muon_dijet_m_lep_met_dijet_mt");
  // //h_data_highsb_highm_muon_lvjj_mt->Rebin(2);
  

  // TH1F* h_alpgen_wjets_highsb_highm_elec_lvjj_mt = (TH1F*) alpgen_wjets->Get("h_highsb_highm_elec_dijet_m_lep_met_dijet_mt");  
  // h_alpgen_wjets_highsb_highm_elec_lvjj_mt->GetXaxis()->SetRangeUser(0,1e3);
  // h_alpgen_wjets_highsb_highm_elec_lvjj_mt->Rebin(2);

  // TH1F* h_alpgen_wjets_highsb_highm_muon_lvjj_mt = (TH1F*) alpgen_wjets->Get("h_highsb_highm_muon_dijet_m_lep_met_dijet_mt");
  // TH1F* h_vv_highsb_highm_elec_lvjj_mt = (TH1F*) vv->Get("h_highsb_highm_elec_dijet_m_lep_met_dijet_mt");
  // h_vv_highsb_highm_elec_lvjj_mt->GetXaxis()->SetRangeUser(0,1e3);
  // h_vv_highsb_highm_elec_lvjj_mt->Rebin(2);

  // TH1F* h_vv_highsb_highm_muon_lvjj_mt = (TH1F*) vv->Get("h_highsb_highm_muon_dijet_m_lep_met_dijet_mt");
  // TH1F* h_top_highsb_highm_elec_lvjj_mt = (TH1F*) top->Get("h_highsb_highm_elec_dijet_m_lep_met_dijet_mt");
  // h_top_highsb_highm_elec_lvjj_mt->GetXaxis()->SetRangeUser(0,1e3);
  // h_top_highsb_highm_elec_lvjj_mt->Rebin(2);

  // TH1F* h_top_highsb_highm_muon_lvjj_mt = (TH1F*) top->Get("h_highsb_highm_muon_dijet_m_lep_met_dijet_mt");
  // TH1F* h_alpgen_zjets_highsb_highm_elec_lvjj_mt = (TH1F*) alpgen_zjets->Get("h_highsb_highm_elec_dijet_m_lep_met_dijet_mt");
  // h_alpgen_zjets_highsb_highm_elec_lvjj_mt->GetXaxis()->SetRangeUser(0,1e3);
  // h_alpgen_zjets_highsb_highm_elec_lvjj_mt->Rebin(2);
  // TH1F* h_alpgen_zjets_highsb_highm_muon_lvjj_mt = (TH1F*) alpgen_zjets->Get("h_highsb_highm_muon_dijet_m_lep_met_dijet_mt");
  // TH1F* h_alpgen_qcd_highsb_highm_elec_lvjj_mt = (TH1F*) alpgen_qcd->Get("h_highsb_highm_elec_dijet_m_lep_met_dijet_mt");
  // h_alpgen_qcd_highsb_highm_elec_lvjj_mt->GetXaxis()->SetRangeUser(0,1e3);
  // h_alpgen_qcd_highsb_highm_elec_lvjj_mt->Rebin(2);

  // TH1F* h_alpgen_qcd_highsb_highm_muon_lvjj_mt = (TH1F*) alpgen_qcd->Get("h_highsb_highm_muon_dijet_m_lep_met_dijet_mt");

  // h_alpgen_wjets_highsb_highm_elec_lvjj_mt->Add(h_alpgen_qcd_highsb_highm_elec_lvjj_mt);
  // h_alpgen_wjets_highsb_highm_elec_lvjj_mt->Add(h_vv_highsb_highm_elec_lvjj_mt);
  // h_alpgen_wjets_highsb_highm_elec_lvjj_mt->Add(h_top_highsb_highm_elec_lvjj_mt);
  // h_alpgen_wjets_highsb_highm_elec_lvjj_mt->Add(h_alpgen_zjets_highsb_highm_elec_lvjj_mt);
  // //h_alpgen_wjets_highsb_highm_elec_lvjj_mt->Rebin(2);
  

  // //////////////////////////////////////////////////
  // // Make ratio histos
  // ////////////////////////////////////////////////// 

  // TH1F* h_alpgen_highsb_highm_elec_lvjj_mt_ratio = (TH1F*) h_data_highsb_highm_elec_lvjj_mt->Clone();
  // h_alpgen_highsb_highm_elec_lvjj_mt_ratio->Add(h_alpgen_wjets_highsb_highm_elec_lvjj_mt,-1.);
  // h_alpgen_highsb_highm_elec_lvjj_mt_ratio->
  //   Divide(h_alpgen_highsb_highm_elec_lvjj_mt_ratio,h_alpgen_wjets_highsb_highm_elec_lvjj_mt,1,1,"B");
  

  // //////////////////////////////////////////////////
  // // Make Plots
  // ////////////////////////////////////////////////// 
  
  // TCanvas* tc_ctrl_sig_elec_lvjj_mt = new TCanvas("tc_ctrl_sig_elec_lvjj_mt","tc_ctrl_sig_elec_lvjj_mt",0,0,1920,1200);

  // TPad* ctrl_sig_elec_lvjj_mt_ratio_pad = new TPad("ctrl_sig_elec_lvjj_mt_ratio_pad","ctrl_sig_elec_lvjj_mt_ratio_pad",0.01,0.01,0.99,ratio_split);
  // ctrl_sig_elec_lvjj_mt_ratio_pad->SetTopMargin(0.05);
  // ctrl_sig_elec_lvjj_mt_ratio_pad->SetBottomMargin(0.31);
  // ctrl_sig_elec_lvjj_mt_ratio_pad->Draw();

    
  // TPad* ctrl_sig_elec_lvjj_mt_plot_pad = new TPad("ctrl_sig_elec_lvjj_mt_plot_pad","ctrl_sig_elec_lvjj_mt_plot_pad",0.01,ratio_split,0.99,0.99);
  // ctrl_sig_elec_lvjj_mt_plot_pad->SetBottomMargin(0);
  // ctrl_sig_elec_lvjj_mt_plot_pad->SetTopMargin(0.05);
  // ctrl_sig_elec_lvjj_mt_plot_pad->Draw();
  // ctrl_sig_elec_lvjj_mt_plot_pad->cd();
  // ctrl_sig_elec_lvjj_mt_plot_pad->Update();  

  // //ctrl_sig

  // h_alpgen_wjets_ctrl_sig_elec_lvjj_mt->GetXaxis()->SetRangeUser(0,1000.);
  // h_alpgen_wjets_ctrl_sig_elec_lvjj_mt->Draw("HIST");

  // h_data_ctrl_sig_elec_lvjj_mt->SetMarkerStyle(8);
  // h_data_ctrl_sig_elec_lvjj_mt->GetXaxis()->SetRangeUser(0,1000.);
  // h_data_ctrl_sig_elec_lvjj_mt->Draw("HIST sames PE");

  // //lowsb_highm
  // h_alpgen_wjets_lowsb_highm_elec_lvjj_mt->SetLineColor(kBlue);
  // h_alpgen_wjets_lowsb_highm_elec_lvjj_mt->GetXaxis()->SetRangeUser(0,1000.);
  // h_alpgen_wjets_lowsb_highm_elec_lvjj_mt->Draw("HIST sames");
  

  // h_data_lowsb_highm_elec_lvjj_mt->SetMarkerStyle(8);
  // h_data_lowsb_highm_elec_lvjj_mt->SetLineColor(kBlue);
  // h_data_lowsb_highm_elec_lvjj_mt->SetMarkerColor(kBlue);
  // h_data_lowsb_highm_elec_lvjj_mt->GetXaxis()->SetRangeUser(0,1000.);
  // h_data_lowsb_highm_elec_lvjj_mt->Draw("HIST sames PE");

  // //highsb_highm
  // h_alpgen_wjets_highsb_highm_elec_lvjj_mt->SetLineColor(kRed);
  // h_alpgen_wjets_highsb_highm_elec_lvjj_mt->GetXaxis()->SetRangeUser(0,1000.);
  // h_alpgen_wjets_highsb_highm_elec_lvjj_mt->Draw("HIST sames");

  // h_data_highsb_highm_elec_lvjj_mt->SetMarkerStyle(8);
  // h_data_highsb_highm_elec_lvjj_mt->SetLineColor(kRed);
  // h_data_highsb_highm_elec_lvjj_mt->SetMarkerColor(kRed);
  // h_data_highsb_highm_elec_lvjj_mt->GetXaxis()->SetRangeUser(0,1000.);
  // h_data_highsb_highm_elec_lvjj_mt->Draw("HIST sames PE");

  // ctrl_sig_elec_lvjj_mt_plot_pad->SetLogy();
  // ctrl_sig_elec_lvjj_mt_plot_pad->Update();

  // tc_ctrl_sig_elec_lvjj_mt->Update();

  // TLegend* tl_ctrl_sig_elec_dijet_m = new TLegend(0.63,0.8,0.9,0.9);
  // tl_ctrl_sig_elec_dijet_m->SetFillColor(0);
  // tl_ctrl_sig_elec_dijet_m->SetTextSize(0.03);
  // //tl_ctrl_sig_elec_dijet_m->AddEntry(h_data_ctrl_sig_elec_lvjj_mt,"data","L");
  // tl_ctrl_sig_elec_dijet_m->AddEntry(h_alpgen_wjets_ctrl_sig_elec_lvjj_mt,"M(jj)<65 || M(jj)>115","L");
  // tl_ctrl_sig_elec_dijet_m->AddEntry(h_alpgen_wjets_lowsb_highm_elec_lvjj_mt,"M(jj)<65","L");
  // tl_ctrl_sig_elec_dijet_m->AddEntry(h_alpgen_wjets_highsb_highm_elec_lvjj_mt,"M(jj)>115","L");
  // tl_ctrl_sig_elec_dijet_m->Draw();

  // //////////////////////////////////////////////////
  // // Do ratio
  // ////////////////////////////////////////////////// 

  // ctrl_sig_elec_lvjj_mt_ratio_pad->cd();
  // ctrl_sig_elec_lvjj_mt_ratio_pad->SetGrid();

  
  // TAxis* alpgen_ctrl_sig_elec_ratio_xaxis= h_alpgen_ctrl_sig_elec_lvjj_mt_ratio->GetXaxis();
  // TAxis* alpgen_ctrl_sig_elec_ratio_yaxis= h_alpgen_ctrl_sig_elec_lvjj_mt_ratio->GetYaxis();

  // h_alpgen_ctrl_sig_elec_lvjj_mt_ratio->SetMarkerStyle(20);
  // h_alpgen_ctrl_sig_elec_lvjj_mt_ratio->SetMarkerSize(2);
  // h_alpgen_ctrl_sig_elec_lvjj_mt_ratio->SetLineWidth(1);
  // h_alpgen_ctrl_sig_elec_lvjj_mt_ratio->SetTitle("");
  // h_alpgen_ctrl_sig_elec_lvjj_mt_ratio->Rebin(2);
  // //  h_alpgen_ctrl_sig_elec_lvjj_mt_ratio->SetLineColor(kRed);
  // //    h_alpgen_ctrl_sig_elec_lvjj_mt_ratio->SetMarkerColor(kRed);

  // alpgen_ctrl_sig_elec_ratio_xaxis->SetLabelSize(0.08);
  // alpgen_ctrl_sig_elec_ratio_yaxis->SetLabelSize(0.08);

  
  // alpgen_ctrl_sig_elec_ratio_xaxis->SetTitle(plot_var.c_str());
  // alpgen_ctrl_sig_elec_ratio_xaxis->SetTitleSize(0.16);
  // alpgen_ctrl_sig_elec_ratio_xaxis->SetTitleOffset(0.7);
  // alpgen_ctrl_sig_elec_ratio_yaxis->SetNdivisions(4,4,4);
  // alpgen_ctrl_sig_elec_ratio_yaxis->SetTitle("(data-MC)/MC");
  // alpgen_ctrl_sig_elec_ratio_yaxis->SetTitleSize(0.07);
  // alpgen_ctrl_sig_elec_ratio_yaxis->SetTitleOffset(0.36);

  // alpgen_ctrl_sig_elec_ratio_yaxis->SetRangeUser(-0.75,0.75);
  // alpgen_ctrl_sig_elec_ratio_xaxis->SetRangeUser(0,1000.);
  // h_alpgen_ctrl_sig_elec_lvjj_mt_ratio->Draw("HIST PE");


  // TAxis* alpgen_lowsb_highm_elec_ratio_xaxis= h_alpgen_lowsb_highm_elec_lvjj_mt_ratio->GetXaxis();
  // TAxis* alpgen_lowsb_highm_elec_ratio_yaxis= h_alpgen_lowsb_highm_elec_lvjj_mt_ratio->GetYaxis();

  // h_alpgen_lowsb_highm_elec_lvjj_mt_ratio->SetMarkerStyle(20);
  // h_alpgen_lowsb_highm_elec_lvjj_mt_ratio->SetMarkerSize(2);
  // h_alpgen_lowsb_highm_elec_lvjj_mt_ratio->SetLineWidth(1);
  // h_alpgen_lowsb_highm_elec_lvjj_mt_ratio->SetLineColor(kBlue);
  //   h_alpgen_lowsb_highm_elec_lvjj_mt_ratio->SetMarkerColor(kBlue);

  // alpgen_lowsb_highm_elec_ratio_xaxis->SetLabelSize(0.08);
  // alpgen_lowsb_highm_elec_ratio_yaxis->SetLabelSize(0.08);

  
  // alpgen_lowsb_highm_elec_ratio_xaxis->SetTitle(plot_var.c_str());
  // alpgen_lowsb_highm_elec_ratio_xaxis->SetTitleSize(0.16);
  // alpgen_lowsb_highm_elec_ratio_xaxis->SetTitleOffset(0.7);
  // alpgen_lowsb_highm_elec_ratio_yaxis->SetNdivisions(4,4,4);
  // alpgen_lowsb_highm_elec_ratio_yaxis->SetTitle("(data-MC)/MC");
  // alpgen_lowsb_highm_elec_ratio_yaxis->SetTitleSize(0.07);
  // alpgen_lowsb_highm_elec_ratio_yaxis->SetTitleOffset(0.36);

  // alpgen_lowsb_highm_elec_ratio_yaxis->SetRangeUser(-0.75,0.75);
  // h_alpgen_lowsb_highm_elec_lvjj_mt_ratio->Draw("HIST PE sames");

  // TAxis* alpgen_highsb_highm_elec_ratio_xaxis= h_alpgen_highsb_highm_elec_lvjj_mt_ratio->GetXaxis();
  // TAxis* alpgen_highsb_highm_elec_ratio_yaxis= h_alpgen_highsb_highm_elec_lvjj_mt_ratio->GetYaxis();

  // h_alpgen_highsb_highm_elec_lvjj_mt_ratio->SetMarkerStyle(20);
  // h_alpgen_highsb_highm_elec_lvjj_mt_ratio->SetMarkerSize(2);
  // h_alpgen_highsb_highm_elec_lvjj_mt_ratio->SetLineWidth(1);
  // h_alpgen_highsb_highm_elec_lvjj_mt_ratio->SetLineColor(kRed);
  //   h_alpgen_highsb_highm_elec_lvjj_mt_ratio->SetMarkerColor(kRed);

  // alpgen_highsb_highm_elec_ratio_xaxis->SetLabelSize(0.08);
  // alpgen_highsb_highm_elec_ratio_yaxis->SetLabelSize(0.08);

  
  // alpgen_highsb_highm_elec_ratio_xaxis->SetTitle(plot_var.c_str());
  // alpgen_highsb_highm_elec_ratio_xaxis->SetTitleSize(0.16);
  // alpgen_highsb_highm_elec_ratio_xaxis->SetTitleOffset(0.7);
  // alpgen_highsb_highm_elec_ratio_yaxis->SetNdivisions(4,4,4);
  // alpgen_highsb_highm_elec_ratio_yaxis->SetTitle("(data-MC)/MC");
  // alpgen_highsb_highm_elec_ratio_yaxis->SetTitleSize(0.07);
  // alpgen_highsb_highm_elec_ratio_yaxis->SetTitleOffset(0.36);

  // alpgen_highsb_highm_elec_ratio_yaxis->SetRangeUser(-0.75,0.75);
  // h_alpgen_highsb_highm_elec_lvjj_mt_ratio->Draw("HIST PE sames");



  // tc_ctrl_sig_elec_lvjj_mt->Update();


  // string cur_saveas = "../canvases/latest/h_ctrl_sig_elec_lvjj_mt.pdf";
  // tc_ctrl_sig_elec_lvjj_mt->SaveAs(cur_saveas.c_str());

  

  gROOT->ProcessLine(".q");  
}
