// Plots Scale Factor vs MT

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <string>

#include <TCanvas.h>
#include <TLegend.h>
#include <THStack.h>
#include "TH1.h"
#include <TFile.h>

string plot_loc = "../canvases/latest/";
string save_ext = ".pdf";

int alpgen_color = 6;
int sherpa_color = 7;


void vjetsShapeSystematics(){

  gROOT->LoadMacro("../include/atlasstyle-00-03-04/AtlasStyle.C");
  SetAtlasStyle();
  gROOT->LoadMacro("../include/atlasstyle-00-03-04/AtlasUtils.C");
  gROOT->LoadMacro("../include/atlasstyle-00-03-04/AtlasLabels.C");
  
  gROOT->SetBatch();

  TH1::SetDefaultSumw2(kTRUE);
  
  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In vjetsPrintSF.C"<<endl;

  const int nControlRegions = 2;
  string control_regions[nControlRegions] = {"lowsb_highm","highsb_highm"};

  
  // const int nProcs = 2;
  // string procs[nProcs] = {"elec", "muon"};

  string file_loc = "/Users/elw/Dropbox/eMacs/analy/lvjj/plots/ctrl_plots/";


    //////////////////////////////////////////////////
  // Load Data
  ////////////////////////////////////////////////// 
  string lowsb_hist_name = "h_lowsb_highm_comb_dijet_m_forshape_lep_nu_dijet_m";
  // M(jj)>115
  string highsb_hist_name = "h_highsb_highm_comb_dijet_m_forshape_lep_nu_dijet_m";
  // 115 < M(jj) < 150
  //string highsb_hist_name = "h_highsb_highm_comb_dijet_m_forshape_trunc_lep_nu_dijet_m";

  
  string data_loc = file_loc+"merged/data.lnuj.ctrl.plot.root";
  TFile* data = TFile::Open(data_loc.c_str());
  TH1F* h_lowsb_data = (TH1F*) data->Get(lowsb_hist_name.c_str());
  h_lowsb_data->SetDirectory(0);
  TH1F* h_highsb_data = (TH1F*) data->Get(highsb_hist_name.c_str());
  h_highsb_data->SetDirectory(0);
  data->Close();
  TH1F* h_comb_data = (TH1F*) h_lowsb_data->Clone();
  h_comb_data->Add((TH1F*) h_highsb_data->Clone());

  
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

  
  TFile* alpgen_wjets = TFile::Open(alpgen_wjets_loc.c_str(),"READ");
  TH1F* h_lowsb_alpgen_wjets = (TH1F*) alpgen_wjets->Get(lowsb_hist_name.c_str());
  h_lowsb_alpgen_wjets->SetDirectory(0);
  TH1F* h_highsb_alpgen_wjets = (TH1F*) alpgen_wjets->Get(highsb_hist_name.c_str());
  h_highsb_alpgen_wjets->SetDirectory(0);
  alpgen_wjets->Close();
  TH1F* h_comb_alpgen_wjets = (TH1F*) h_lowsb_alpgen_wjets->Clone();
  h_comb_alpgen_wjets->Add((TH1F*) h_highsb_alpgen_wjets->Clone());

  
  TFile* vv = TFile::Open(vv_loc.c_str(),"READ");
  TH1F* h_lowsb_vv = (TH1F*) vv->Get(lowsb_hist_name.c_str());
  h_lowsb_vv->SetDirectory(0);
  TH1F* h_highsb_vv = (TH1F*) vv->Get(highsb_hist_name.c_str());
  h_highsb_vv->SetDirectory(0);
  vv->Close();
  TH1F* h_comb_vv = (TH1F*) h_lowsb_vv->Clone();
  h_comb_vv->Add((TH1F*) h_highsb_vv->Clone());

  TFile* alpgen_qcd = TFile::Open(alpgen_qcd_loc.c_str(),"READ");
  TH1F* h_lowsb_alpgen_qcd = (TH1F*) alpgen_qcd->Get(lowsb_hist_name.c_str());
  h_lowsb_alpgen_qcd->SetDirectory(0);
  TH1F* h_highsb_alpgen_qcd = (TH1F*) alpgen_qcd->Get(highsb_hist_name.c_str());
  h_highsb_alpgen_qcd->SetDirectory(0);
  alpgen_qcd->Close();
  TH1F* h_comb_alpgen_qcd = (TH1F*) h_lowsb_alpgen_qcd->Clone();
  h_comb_alpgen_qcd->Add((TH1F*) h_highsb_alpgen_qcd->Clone());


  TFile* top = TFile::Open(top_loc.c_str(),"READ");
  TH1F* h_lowsb_top = (TH1F*) top->Get(lowsb_hist_name.c_str());
  h_lowsb_top->SetDirectory(0);
  TH1F* h_highsb_top = (TH1F*) top->Get(highsb_hist_name.c_str());
  h_highsb_top->SetDirectory(0);
  top->Close();
  TH1F* h_comb_top = (TH1F*) h_lowsb_top->Clone();
  h_comb_top->Add((TH1F*) h_highsb_top->Clone());

  TFile* alpgen_zjets = TFile::Open(alpgen_zjets_loc.c_str(),"READ");
  TH1F* h_lowsb_alpgen_zjets = (TH1F*) alpgen_zjets->Get(lowsb_hist_name.c_str());
  h_lowsb_alpgen_zjets->SetDirectory(0);
  TH1F* h_highsb_alpgen_zjets = (TH1F*) alpgen_zjets->Get(highsb_hist_name.c_str());
  h_highsb_alpgen_zjets->SetDirectory(0);
  alpgen_zjets->Close();
  TH1F* h_comb_alpgen_zjets = (TH1F*) h_lowsb_alpgen_zjets->Clone();
  h_comb_alpgen_zjets->Add((TH1F*) h_highsb_alpgen_zjets->Clone());


  // Non V+jets
  TH1F* h_lowsb_non_vjets_bkgd = (TH1F*) h_lowsb_vv;
  h_lowsb_non_vjets_bkgd->Add((TH1F*) h_lowsb_top);
  TH1F* h_highsb_non_vjets_bkgd = (TH1F*) h_highsb_vv;
  h_highsb_non_vjets_bkgd->Add((TH1F*) h_highsb_top);
  TH1F* h_comb_non_vjets_bkgd = (TH1F*) h_comb_vv;
  h_comb_non_vjets_bkgd->Add((TH1F*) h_comb_top);

  // ALPGEN V+JETS
  TH1F* h_lowsb_alpgen_vjets = (TH1F*) h_lowsb_alpgen_wjets;
  h_lowsb_alpgen_vjets->Add((TH1F*) h_lowsb_alpgen_zjets);
  TH1F* h_highsb_alpgen_vjets = (TH1F*) h_highsb_alpgen_wjets;
  h_highsb_alpgen_vjets->Add((TH1F*) h_highsb_alpgen_zjets);
  TH1F* h_comb_alpgen_vjets = (TH1F*) h_comb_alpgen_wjets;
  h_comb_alpgen_vjets->Add((TH1F*) h_comb_alpgen_zjets);

  // ALPGEN background
  TH1F* h_lowsb_alpgen_bkgd = (TH1F*) h_lowsb_non_vjets_bkgd->Clone();
  h_lowsb_alpgen_bkgd->Add((TH1F*) h_lowsb_alpgen_qcd);
  TH1F* h_highsb_alpgen_bkgd = (TH1F*) h_highsb_non_vjets_bkgd->Clone();
  h_highsb_alpgen_bkgd->Add((TH1F*) h_highsb_alpgen_qcd);
  TH1F* h_comb_alpgen_bkgd = (TH1F*) h_comb_non_vjets_bkgd->Clone();
  h_comb_alpgen_bkgd->Add((TH1F*) h_comb_alpgen_qcd);

  // lowsb bin widths
  const int n_lowsb_varbins=3;
  double lowsb_varbins[n_lowsb_varbins] = {200,550,2000};//best for ptjj,ptlv>200

  
  TH1F* h_lowsb_varbin_sf =
    (TH1F*) h_lowsb_data->Rebin(n_lowsb_varbins-1,"h_lowsb_varbin_sf",lowsb_varbins);
  TH1F* h_lowsb_varbin_bkgd =
    (TH1F*) h_lowsb_alpgen_bkgd->Rebin(n_lowsb_varbins-1,"h_lowsb_varbin_bkgd",lowsb_varbins);
  TH1F* h_lowsb_varbin_vjets =
    (TH1F*) h_lowsb_alpgen_vjets->Rebin(n_lowsb_varbins-1,"h_lowsb_varbin_vjets",lowsb_varbins);
  h_lowsb_varbin_sf->Add(h_lowsb_varbin_bkgd,-1.);
  h_lowsb_varbin_sf->Divide(h_lowsb_varbin_sf,h_lowsb_varbin_vjets,1,1,"B");

  // highsb bin widths

  // M(jj) > 115
  const int n_highsb_varbins=6;
  double highsb_varbins[n_highsb_varbins] = {200,550,950,1200,1450,2000};

  // 115 < M(jj) < 150
  // const int n_highsb_varbins=4;
  // double highsb_varbins[n_highsb_varbins] = {200,500,950,2000};


  TH1F* h_highsb_varbin_sf =
    (TH1F*) h_highsb_data->Rebin(n_highsb_varbins-1,"h_highsb_varbin_sf",highsb_varbins);
  TH1F* h_highsb_varbin_bkgd =
    (TH1F*) h_highsb_alpgen_bkgd->Rebin(n_highsb_varbins-1,"h_highsb_varbin_bkgd",highsb_varbins);
  TH1F* h_highsb_varbin_vjets =
    (TH1F*) h_highsb_alpgen_vjets->Rebin(n_highsb_varbins-1,"h_highsb_varbin_vjets",highsb_varbins);
  
  h_highsb_varbin_sf->Add(h_highsb_varbin_bkgd,-1.);
  h_highsb_varbin_sf->Divide(h_highsb_varbin_sf,h_highsb_varbin_vjets,1,1,"B");

  // avg bin widths

  // // M(jj) > 115
  const int n_avg_varbins=6;
  double avg_varbins[n_avg_varbins] = {200,550,950,1200,1450,2000};

  // 115 < M(jj) < 150
  // const int n_avg_varbins=4;
  // double avg_varbins[n_avg_varbins] = {200,500,950,2000};

  TH1F* h_avg_varbin_sf =
    (TH1F*) h_comb_data->Rebin(n_avg_varbins-1,"h_avg_varbin_sf",avg_varbins);
  TH1F* h_avg_varbin_bkgd =
    (TH1F*) h_comb_alpgen_bkgd->Rebin(n_avg_varbins-1,"h_avg_varbin_bkgd",avg_varbins);
  TH1F* h_avg_varbin_vjets =
    (TH1F*) h_comb_alpgen_vjets->Rebin(n_avg_varbins-1,"h_avg_varbin_vjets",avg_varbins);
  
  h_avg_varbin_sf->Add(h_avg_varbin_bkgd,-1.);
  h_avg_varbin_sf->Divide(h_avg_varbin_sf,h_avg_varbin_vjets,1,1,"B");
  
  // ALPGEN SF

  TH1F* h_lowsb_alpgen_sf = (TH1F*) h_lowsb_data->Clone();
  h_lowsb_alpgen_sf->Rebin(5);
  h_lowsb_alpgen_bkgd->Rebin(5);
  h_lowsb_alpgen_vjets->Rebin(5);
  h_lowsb_alpgen_sf->Add(h_lowsb_alpgen_bkgd,-1.);
  h_lowsb_alpgen_sf->Divide(h_lowsb_alpgen_sf,h_lowsb_alpgen_vjets,1,1,"B");
  TH1F* h_highsb_alpgen_sf = (TH1F*) h_highsb_data->Clone();
  h_highsb_alpgen_sf->Rebin(5);
  h_highsb_alpgen_bkgd->Rebin(5);
  h_highsb_alpgen_vjets->Rebin(5);

  h_highsb_alpgen_sf->Add(h_highsb_alpgen_bkgd,-1.);
  h_highsb_alpgen_sf->Divide(h_highsb_alpgen_sf,h_highsb_alpgen_vjets,1,1,"B");

  TH1F* h_comb_alpgen_sf = (TH1F*) h_comb_data->Clone();
  h_comb_alpgen_sf->Rebin(5);
  h_comb_alpgen_bkgd->Rebin(5);
  h_comb_alpgen_vjets->Rebin(5);

  h_comb_alpgen_sf->Add(h_comb_alpgen_bkgd,-1.);
  h_comb_alpgen_sf->Divide(h_comb_alpgen_sf,h_comb_alpgen_vjets,1,1,"B");


  // Calculate shape systematic
  float n_sfs=0;
  float avg_shape_systematic =0;
  int n_bins=h_comb_alpgen_sf->GetNbinsX();
  for(int i=1;i<n_bins+1;i++){
    if(h_comb_alpgen_sf->GetBinContent(i)){

      avg_shape_systematic+=(1-h_comb_alpgen_sf->GetBinContent(i))*(1/h_comb_alpgen_sf->GetBinError(i));
      n_sfs+=(1/h_comb_alpgen_sf->GetBinError(i));
    }
  }

  avg_shape_systematic/=n_sfs;
  cout<<" - "<<endl;
  cout<<"W/Z+jets shape systematic: "<<avg_shape_systematic<<endl;
  cout<<" - "<<endl;

  TCanvas* tc_highsb_sf = new TCanvas("tc_highsb_sf","tc_highsb_sf",0,0,1920,1200);
  tc_highsb_sf->cd();
  tc_highsb_sf->SetGrid();
  h_highsb_alpgen_sf->SetLineColor(alpgen_color);
  h_highsb_alpgen_sf->SetTitle("");
  h_highsb_alpgen_sf->GetYaxis()->SetTitle("V+jets Scale Factor");
  h_highsb_alpgen_sf->GetXaxis()->SetTitle("M_{T}(lep,E_{T}^{miss},j,j) (M(j,j) > 115GeV)");
  h_highsb_alpgen_sf->GetYaxis()->SetRangeUser(0,1.5);
  h_highsb_alpgen_sf->Draw();

  // h_highsb_alpgen_sf->SetLineColor(alpgen_color);
  // h_highsb_alpgen_sf->Draw("sames");
  
  // TLegend* lgnd_highsb_sf = new TLegend(0.22,0.2,0.4,0.35);
  // lgnd_highsb_sf->SetFillColor(0);
  // lgnd_highsb_sf->SetTextSize(0.045);
  // lgnd_highsb_sf->AddEntry(h_highsb_alpgen_sf,"ALPGEN","L");
  // //lgnd_highsb_sf->AddEntry(h_highsb_sherpa_sf,"SHERPA","L");
  // lgnd_highsb_sf->Draw();


  tc_highsb_sf->Update();
  string cur_saveas = plot_loc+"h_highsb_sf"+save_ext;
  tc_highsb_sf->SaveAs(cur_saveas.c_str());


  TCanvas* tc_lowsb_sf = new TCanvas("tc_lowsb_sf","tc_lowsb_sf",0,0,1920,1200);
  tc_lowsb_sf->cd();
  tc_lowsb_sf->SetGrid();
  h_lowsb_alpgen_sf->SetLineColor(alpgen_color);
  h_lowsb_alpgen_sf->SetTitle("");
  h_lowsb_alpgen_sf->GetYaxis()->SetTitle("V+jets Scale Factor");
  h_lowsb_alpgen_sf->GetXaxis()->SetTitle("M_{T}(lep,E_{T}^{miss},j,j) (M(j,j) < 65GeV)");
  h_lowsb_alpgen_sf->GetYaxis()->SetRangeUser(0,1.5);
  h_lowsb_alpgen_sf->Draw();

  // h_lowsb_alpgen_sf->SetLineColor(alpgen_color);
  // h_lowsb_alpgen_sf->Draw("sames");
  
  // TLegend* lgnd_lowsb_sf = new TLegend(0.22,0.2,0.4,0.35);
  // lgnd_lowsb_sf->SetFillColor(0);
  // lgnd_lowsb_sf->SetTextSize(0.045);
  // lgnd_lowsb_sf->AddEntry(h_lowsb_alpgen_sf,"ALPGEN","L");
  // lgnd_lowsb_sf->AddEntry(h_lowsb_sherpa_sf,"SHERPA","L");
  // lgnd_lowsb_sf->Draw();


  tc_lowsb_sf->Update();
  string cur_saveas = plot_loc+"h_lowsb_sf"+save_ext;
  tc_lowsb_sf->SaveAs(cur_saveas.c_str());

  TCanvas* tc_comb_sf = new TCanvas("tc_comb_sf","tc_comb_sf",0,0,1920,1200);
  tc_comb_sf->cd();
  tc_comb_sf->SetGrid();
  //h_comb_alpgen_sf->SetLineColor(alpgen_color);
  h_comb_alpgen_sf->SetTitle("");
  h_comb_alpgen_sf->SetMarkerStyle(3);
  h_comb_alpgen_sf->SetMarkerSize(3);
  h_comb_alpgen_sf->GetYaxis()->SetTitle("V+jets Scale Factor");
  h_comb_alpgen_sf->GetXaxis()->SetTitle("M(lep,#nu,j,j) (M(j,j) > 115GeV or M(j,j) < 65GeV)");
  h_comb_alpgen_sf->GetYaxis()->SetRangeUser(0,1.5);
  h_comb_alpgen_sf->SetLineWidth(2);
  h_comb_alpgen_sf->Draw("P");

  h_highsb_alpgen_sf->SetLineColor(7);
  h_highsb_alpgen_sf->Draw("sames");
  h_lowsb_alpgen_sf->Draw("sames");

  
  // h_comb_alpgen_sf->SetLineColor(alpgen_color);
  // h_comb_alpgen_sf->Draw("sames");
  
  TLegend* lgnd_comb_sf = new TLegend(0.22,0.2,0.4,0.35);
  lgnd_comb_sf->SetFillColor(0);
  lgnd_comb_sf->SetTextSize(0.045);
  lgnd_comb_sf->AddEntry(h_comb_alpgen_sf,"Average","L");
  lgnd_comb_sf->AddEntry(h_lowsb_alpgen_sf,"M(jj) < 65","L");
  lgnd_comb_sf->AddEntry(h_highsb_alpgen_sf,"M(jj) > 115","L");
  lgnd_comb_sf->Draw();


  tc_comb_sf->Update();
  string cur_saveas = plot_loc+"h_comb_sf"+save_ext;
  tc_comb_sf->SaveAs(cur_saveas.c_str());


  TF1* highsb_envelope = new TF1("highsb_envelope","[0]*x+[1]",200,2000);

  // M(jj) > 115 
  highsb_envelope->SetParameter(0,-0.8e-4);
  highsb_envelope->SetParameter(1,1.03);


  TH1F* h_avg_sf = (TH1F*) h_comb_alpgen_sf->Clone("h_avg_sf");
  TH1F* h_lowsb_sf = (TH1F*) h_lowsb_alpgen_sf->Clone("h_lowsb_sf");
  TH1F* h_highsb_sf = (TH1F*) h_highsb_alpgen_sf->Clone("h_highsb_sf");
  
  
  TCanvas* tc_avg_with_varbin = new TCanvas("tc_avg_with_varbin","tc_avg_with_varbin",0,0,1920,1200);
  tc_avg_with_varbin->cd();
  tc_avg_with_varbin->SetGrid();
  //h_highsb_varbin_sf->SetLineColor(alpgen_color);
  h_avg_varbin_sf->SetTitle("");
  h_avg_varbin_sf->SetMarkerStyle(3);
  h_avg_varbin_sf->SetMarkerSize(3);
  h_avg_varbin_sf->GetYaxis()->SetTitle("V+jets Scale Factor");
  h_avg_varbin_sf->GetXaxis()->SetTitle("M(l#nu jj) (M(j,j) > 115GeV or M(j,j) < 65GeV)");
  h_avg_varbin_sf->GetYaxis()->SetRangeUser(0,1.5);
  h_avg_varbin_sf->Draw("P");

  //New histogram with values shifted to tops of error bars
  TH1F* h_lowsb_varbin_err_sf = h_lowsb_varbin_sf->Clone();
  for(int i=1;i<=h_lowsb_varbin_err_sf->GetNbinsX();i++){
    float cur_val = h_lowsb_varbin_err_sf->GetBinContent(i);
    float cur_err = h_lowsb_varbin_err_sf->GetBinError(i);
    h_lowsb_varbin_err_sf->SetBinContent(i,cur_val+(cur_err/2));
    h_lowsb_varbin_err_sf->SetBinError(i,cur_err);
  
  }
  TF1* fn_lowsb_varbin_sf = new TF1("fn_lowsb_varbin_sf","[0]*TMath::Log(x)+[1]",200,2000);
  fn_lowsb_varbin_sf->SetLineWidth(1);
  fn_lowsb_varbin_sf->SetLineColor(6);
  h_lowsb_varbin_err_sf->Fit(fn_lowsb_varbin_sf,"SR0");
  
  // h_lowsb_varbin_sf->GetYaxis()->SetRangeUser(0,1.5);

  h_lowsb_varbin_sf->SetLineColor(6);
  fn_lowsb_varbin_sf->Draw("same");
  h_lowsb_varbin_sf->Draw("sames");



  //New histogram with values shifted to tops of error bars
  TH1F* h_highsb_varbin_err_sf = h_highsb_varbin_sf->Clone();
  for(int i=1;i<=h_highsb_varbin_err_sf->GetNbinsX();i++){
    float cur_val = h_highsb_varbin_err_sf->GetBinContent(i);
    float cur_err = h_highsb_varbin_err_sf->GetBinError(i);
    h_highsb_varbin_err_sf->SetBinContent(i,cur_val-cur_err);
    h_highsb_varbin_err_sf->SetBinError(i,cur_err);
  }

  TF1* fn_highsb_varbin_sf = new TF1("fn_highsb_varbin_sf","[0]*x+[1]",200,2000);
  fn_highsb_varbin_sf->SetLineWidth(1);
  fn_highsb_varbin_sf->SetLineColor(7);
  h_highsb_varbin_err_sf->Fit(fn_highsb_varbin_sf,"SR0");
  fn_highsb_varbin_sf->Draw("sames");
  
  h_highsb_varbin_sf->SetLineColor(7);
  h_highsb_varbin_sf->Draw("sames");

  // TMP
  // highsb_envelope->SetLineColor(7);
  // highsb_envelope->SetLineWidth(1);
  // highsb_envelope->Draw("same");
  
  
  TLegend* lgnd_comb_varbin_sf = new TLegend(0.22,0.2,0.4,0.35);
  lgnd_comb_varbin_sf->SetFillColor(0);
  lgnd_comb_varbin_sf->SetTextSize(0.045);
  lgnd_comb_varbin_sf->AddEntry(h_avg_varbin_sf,"Average","L");
  lgnd_comb_varbin_sf->AddEntry(h_lowsb_varbin_sf,"M(jj) < 65","L");
  lgnd_comb_varbin_sf->AddEntry(h_highsb_varbin_sf,"M(jj) > 115","L");
  lgnd_comb_varbin_sf->Draw();

  tc_avg_with_varbin->Update();
  string cur_saveas = plot_loc+"h_avg_with_envelope_varbin_sf"+save_ext;
  tc_avg_with_varbin->SaveAs(cur_saveas.c_str());

  TFile* envelope_file = new TFile("./files/vjets_systematics_functions.root","RECREATE");
  envelope_file->cd();
  fn_lowsb_varbin_sf->SetLineWidth(2);
  fn_lowsb_varbin_sf->SetLineColor(1);
  fn_lowsb_varbin_sf->Write("fn_lowsb");

  fn_highsb_varbin_sf->SetLineWidth(2);
  fn_highsb_varbin_sf->SetLineColor(1);
  fn_highsb_varbin_sf->Write("fn_highsb");


  h_avg_varbin_sf->Write("h_avg_varbin_sf");

  // highsb_envelope->SetLineWidth(2);
  // highsb_envelope->SetLineColor(1);
  // highsb_envelope->Write("fn_highsb");

  envelope_file->Close();
  gROOT->ProcessLine(".q");
  return;
}
