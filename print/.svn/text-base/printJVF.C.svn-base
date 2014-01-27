#include "../include/print_list.h"
#include "../include/wwFileInfo.h"
#include "../include/HistogramPainter.h"
#include <string>
#include <TProfile.h>

string proc_type="jvf";
string print_type=".png";
string color_scheme="conf";//normal, conf, thesis(?)

void printJVF(bool drawData=true){

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
  cout<<"In printJVF.C"<<endl;

  const int nProcs = 2;
  string procs[nProcs] = {"elec", "muon"};


  string jvf_file_loc = "/Users/elw/analy/lnuj/plots/jvf_plots/";
  string nojvf_file_loc = "/Users/elw/analy/lnuj/plots/nojvf_plots/";

  //////////////////////////////////////////////////
  // Load Data
  ////////////////////////////////////////////////// 
  
  string jvf_data_loc = jvf_file_loc+"merged/data.lnuj.plot.jvf.root";
  TFile* jvf_data = TFile::Open(jvf_data_loc.c_str());

  string nojvf_data_loc = nojvf_file_loc+"merged/data.lnuj.plot.nojvf.root";
  TFile* nojvf_data = TFile::Open(nojvf_data_loc.c_str());
  //////////////////////////////////////////////////
  // Load Scaled Backgrounds
  //////////////////////////////////////////////////   
  string jvf_alpgen_wjets_loc = jvf_file_loc+"merged/mc.alpgen.wjets.jvf.root";
  string jvf_vv_loc = jvf_file_loc+"merged/mc.herwig.vv.jvf.root";
  string jvf_alpgen_qcd_loc = jvf_file_loc+"merged/qcd.alpgen.jvf.root";
  string jvf_top_loc = jvf_file_loc+"merged/mc.mcatnlo.top.jvf.root";  
  string jvf_zjets_loc = jvf_file_loc+"merged/mc.alpgen.zjets.jvf.root";

  string nojvf_alpgen_wjets_loc = nojvf_file_loc+"merged/mc.alpgen.wjets.nojvf.root";
  string nojvf_vv_loc = nojvf_file_loc+"merged/mc.herwig.vv.nojvf.root";
  string nojvf_alpgen_qcd_loc = nojvf_file_loc+"merged/qcd.alpgen.nojvf.root";
  string nojvf_top_loc = nojvf_file_loc+"merged/mc.mcatnlo.top.nojvf.root";  
  string nojvf_zjets_loc = nojvf_file_loc+"merged/mc.alpgen.zjets.nojvf.root";

  TFile* jvf_alpgen_wjets = TFile::Open(jvf_alpgen_wjets_loc.c_str());
  TFile* jvf_vv = TFile::Open(jvf_vv_loc.c_str());
  TFile* jvf_alpgen_qcd = TFile::Open(jvf_alpgen_qcd_loc.c_str());
  TFile* jvf_top = TFile::Open(jvf_top_loc.c_str());
  TFile* jvf_zjets = TFile::Open(jvf_zjets_loc.c_str());

  TFile* nojvf_alpgen_wjets = TFile::Open(nojvf_alpgen_wjets_loc.c_str());
  TFile* nojvf_vv = TFile::Open(nojvf_vv_loc.c_str());
  TFile* nojvf_alpgen_qcd = TFile::Open(nojvf_alpgen_qcd_loc.c_str());
  TFile* nojvf_top = TFile::Open(nojvf_top_loc.c_str());
  TFile* nojvf_zjets = TFile::Open(nojvf_zjets_loc.c_str());

  
  //////////////////////////////////////////////////
  // h_elec_jet_n
  ////////////////////////////////////////////////// 

  //jvf
  TH1F* h_data_jvf_elec_jet_n = jvf_data->Get("h_elec_jet_n");

  TH1F* h_bkgd_jvf_elec_jet_n = jvf_alpgen_wjets->Get("h_elec_jet_n");
  h_bkgd_jvf_elec_jet_n->Add((TH1F*)jvf_vv->Get("h_elec_jet_n"));
  h_bkgd_jvf_elec_jet_n->Add((TH1F*)jvf_alpgen_qcd->Get("h_elec_jet_n"));
  h_bkgd_jvf_elec_jet_n->Add((TH1F*)jvf_top->Get("h_elec_jet_n"));
  h_bkgd_jvf_elec_jet_n->Add((TH1F*)jvf_zjets->Get("h_elec_jet_n"));

  //nojvf
  TH1F* h_data_nojvf_elec_jet_n = nojvf_data->Get("h_elec_jet_n");

  TH1F* h_bkgd_nojvf_elec_jet_n = nojvf_alpgen_wjets->Get("h_elec_jet_n");
  h_bkgd_nojvf_elec_jet_n->Add((TH1F*)nojvf_vv->Get("h_elec_jet_n"));
  h_bkgd_nojvf_elec_jet_n->Add((TH1F*)nojvf_alpgen_qcd->Get("h_elec_jet_n"));
  h_bkgd_nojvf_elec_jet_n->Add((TH1F*)nojvf_top->Get("h_elec_jet_n"));
  h_bkgd_nojvf_elec_jet_n->Add((TH1F*)nojvf_zjets->Get("h_elec_jet_n"));

  // data plots
  TCanvas* tc_data_elec_jet_n
    = new TCanvas("tc_data_elec_jet_n","tc_data_elec_jet_n",0,0,1920,1200);
  tc_data_elec_jet_n->cd();

  h_data_jvf_elec_jet_n->Scale(1/h_data_jvf_elec_jet_n->Integral());
  h_data_jvf_elec_jet_n->GetXaxis()->SetTitle("Jet N");
  h_data_jvf_elec_jet_n->SetLineColor(kRed);
  h_data_jvf_elec_jet_n->SetTitle("w/ JVF Cut");
  h_data_jvf_elec_jet_n->Draw();

  h_data_nojvf_elec_jet_n->Scale(1/h_data_nojvf_elec_jet_n->Integral());
  h_data_nojvf_elec_jet_n->SetTitle("no JVF Cut");
  h_data_nojvf_elec_jet_n->SetLineColor(kBlue);
  h_data_nojvf_elec_jet_n->Draw("sames");


  TLegend* tl_data_elec_jet_n = new TLegend(0.63,0.8,0.9,0.9);
  tl_data_elec_jet_n->SetFillColor(0);
  tl_data_elec_jet_n->SetTextSize(0.03);
  tl_data_elec_jet_n->SetHeader("Data");
  tl_data_elec_jet_n->AddEntry(h_data_jvf_elec_jet_n);
  tl_data_elec_jet_n->AddEntry(h_data_nojvf_elec_jet_n);
  tl_data_elec_jet_n->Draw();

  tc_data_elec_jet_n->Update();
  tc_data_elec_jet_n->SetLogy();
  
  string cur_saveas = "../canvases/latest/h_jvf_data_elec_jet_n.eps";
  tc_data_elec_jet_n->SaveAs(cur_saveas.c_str());

  
  // bkgd plots
  TCanvas* tc_bkgd_elec_jet_n
    = new TCanvas("tc_bkgd_elec_jet_n","tc_bkgd_elec_jet_n",0,0,1920,1200);
  tc_bkgd_elec_jet_n->cd();

  h_bkgd_jvf_elec_jet_n->Scale(1/h_bkgd_jvf_elec_jet_n->Integral());
  h_bkgd_jvf_elec_jet_n->GetXaxis()->SetTitle("Jet N");
  h_bkgd_jvf_elec_jet_n->SetLineColor(kRed);
  h_bkgd_jvf_elec_jet_n->SetTitle("w/ JVF Cut");
  h_bkgd_jvf_elec_jet_n->Draw();

  h_bkgd_nojvf_elec_jet_n->Scale(1/h_bkgd_nojvf_elec_jet_n->Integral());
  h_bkgd_nojvf_elec_jet_n->SetTitle("no JVF Cut");
  h_bkgd_nojvf_elec_jet_n->SetLineColor(kBlue);
  h_bkgd_nojvf_elec_jet_n->Draw("sames");

  TLegend* tl_bkgd_elec_jet_n = new TLegend(0.63,0.8,0.9,0.9);
  tl_bkgd_elec_jet_n->SetFillColor(0);
  tl_bkgd_elec_jet_n->SetTextSize(0.03);
  tl_bkgd_elec_jet_n->SetHeader("Backgrounds");
  tl_bkgd_elec_jet_n->AddEntry(h_bkgd_jvf_elec_jet_n);
  tl_bkgd_elec_jet_n->AddEntry(h_bkgd_nojvf_elec_jet_n);
  tl_bkgd_elec_jet_n->Draw();


  tc_bkgd_elec_jet_n->Update();
  tc_bkgd_elec_jet_n->SetLogy();
  
  string cur_saveas = "../canvases/latest/h_jvf_bkgd_elec_jet_n.eps";
  tc_bkgd_elec_jet_n->SaveAs(cur_saveas.c_str());
  
  //////////////////////////////////////////////////
  // h_muon_jet_n
  ////////////////////////////////////////////////// 

  //jvf
  TH1F* h_data_jvf_muon_jet_n = jvf_data->Get("h_muon_jet_n");

  TH1F* h_bkgd_jvf_muon_jet_n = jvf_alpgen_wjets->Get("h_muon_jet_n");
  h_bkgd_jvf_muon_jet_n->Add((TH1F*)jvf_vv->Get("h_muon_jet_n"));
  h_bkgd_jvf_muon_jet_n->Add((TH1F*)jvf_alpgen_qcd->Get("h_muon_jet_n"));
  h_bkgd_jvf_muon_jet_n->Add((TH1F*)jvf_top->Get("h_muon_jet_n"));
  h_bkgd_jvf_muon_jet_n->Add((TH1F*)jvf_zjets->Get("h_muon_jet_n"));

  //nojvf
  TH1F* h_data_nojvf_muon_jet_n = nojvf_data->Get("h_muon_jet_n");

  TH1F* h_bkgd_nojvf_muon_jet_n = nojvf_alpgen_wjets->Get("h_muon_jet_n");
  h_bkgd_nojvf_muon_jet_n->Add((TH1F*)nojvf_vv->Get("h_muon_jet_n"));
  h_bkgd_nojvf_muon_jet_n->Add((TH1F*)nojvf_alpgen_qcd->Get("h_muon_jet_n"));
  h_bkgd_nojvf_muon_jet_n->Add((TH1F*)nojvf_top->Get("h_muon_jet_n"));
  h_bkgd_nojvf_muon_jet_n->Add((TH1F*)nojvf_zjets->Get("h_muon_jet_n"));

  // data plots
  TCanvas* tc_data_muon_jet_n
    = new TCanvas("tc_data_muon_jet_n","tc_data_muon_jet_n",0,0,1920,1200);
  tc_data_muon_jet_n->cd();

  h_data_jvf_muon_jet_n->Scale(1/h_data_jvf_muon_jet_n->Integral());
  h_data_jvf_muon_jet_n->GetXaxis()->SetTitle("Jet N");
  h_data_jvf_muon_jet_n->SetLineColor(kRed);
  h_data_jvf_muon_jet_n->SetTitle("w/ JVF Cut");
  h_data_jvf_muon_jet_n->Draw();

  h_data_nojvf_muon_jet_n->Scale(1/h_data_nojvf_muon_jet_n->Integral());
  h_data_nojvf_muon_jet_n->SetTitle("no JVF Cut");
  h_data_nojvf_muon_jet_n->SetLineColor(kBlue);
  h_data_nojvf_muon_jet_n->Draw("sames");


  TLegend* tl_data_muon_jet_n = new TLegend(0.63,0.8,0.9,0.9);
  tl_data_muon_jet_n->SetFillColor(0);
  tl_data_muon_jet_n->SetTextSize(0.03);
  tl_data_muon_jet_n->SetHeader("Data");
  tl_data_muon_jet_n->AddEntry(h_data_jvf_muon_jet_n);
  tl_data_muon_jet_n->AddEntry(h_data_nojvf_muon_jet_n);
  tl_data_muon_jet_n->Draw();

  tc_data_muon_jet_n->Update();
  tc_data_muon_jet_n->SetLogy();
  
  string cur_saveas = "../canvases/latest/h_jvf_data_muon_jet_n.eps";
  tc_data_muon_jet_n->SaveAs(cur_saveas.c_str());

  
  // bkgd plots
  TCanvas* tc_bkgd_muon_jet_n
    = new TCanvas("tc_bkgd_muon_jet_n","tc_bkgd_muon_jet_n",0,0,1920,1200);
  tc_bkgd_muon_jet_n->cd();

  h_bkgd_jvf_muon_jet_n->Scale(1/h_bkgd_jvf_muon_jet_n->Integral());
  h_bkgd_jvf_muon_jet_n->SetLineColor(kRed);
  h_bkgd_jvf_muon_jet_n->GetXaxis()->SetTitle("Jet N");
  h_bkgd_jvf_muon_jet_n->SetTitle("w/ JVF Cut");
  h_bkgd_jvf_muon_jet_n->Draw();

  h_bkgd_nojvf_muon_jet_n->Scale(1/h_bkgd_nojvf_muon_jet_n->Integral());
  h_bkgd_nojvf_muon_jet_n->SetTitle("no JVF Cut");
  h_bkgd_nojvf_muon_jet_n->SetLineColor(kBlue);
  h_bkgd_nojvf_muon_jet_n->Draw("sames");

  TLegend* tl_bkgd_muon_jet_n = new TLegend(0.63,0.8,0.9,0.9);
  tl_bkgd_muon_jet_n->SetFillColor(0);
  tl_bkgd_muon_jet_n->SetTextSize(0.03);
  tl_bkgd_muon_jet_n->SetHeader("Backgrounds");
  tl_bkgd_muon_jet_n->AddEntry(h_bkgd_jvf_muon_jet_n);
  tl_bkgd_muon_jet_n->AddEntry(h_bkgd_nojvf_muon_jet_n);
  tl_bkgd_muon_jet_n->Draw();


  tc_bkgd_muon_jet_n->Update();
  tc_bkgd_muon_jet_n->SetLogy();
  
  string cur_saveas = "../canvases/latest/h_jvf_bkgd_muon_jet_n.eps";
  tc_bkgd_muon_jet_n->SaveAs(cur_saveas.c_str());


  //////////////////////////////////////////////////
  // prof_elec_jet_n_mu
  ////////////////////////////////////////////////// 

  //jvf
  TProfile* prof_data_jvf_elec_jet_n_mu = jvf_data->Get("prof_elec_jet_n_mu");

  TProfile* prof_bkgd_jvf_elec_jet_n_mu = jvf_alpgen_wjets->Get("prof_elec_jet_n_mu");
  prof_bkgd_jvf_elec_jet_n_mu->Add((TProfile*)jvf_vv->Get("prof_elec_jet_n_mu"));
  prof_bkgd_jvf_elec_jet_n_mu->Add((TProfile*)jvf_alpgen_qcd->Get("prof_elec_jet_n_mu"));
  prof_bkgd_jvf_elec_jet_n_mu->Add((TProfile*)jvf_top->Get("prof_elec_jet_n_mu"));
  prof_bkgd_jvf_elec_jet_n_mu->Add((TProfile*)jvf_zjets->Get("prof_elec_jet_n_mu"));

  //nojvf
  TProfile* prof_data_nojvf_elec_jet_n_mu = nojvf_data->Get("prof_elec_jet_n_mu");

  TProfile* prof_bkgd_nojvf_elec_jet_n_mu = nojvf_alpgen_wjets->Get("prof_elec_jet_n_mu");
  prof_bkgd_nojvf_elec_jet_n_mu->Add((TProfile*)nojvf_vv->Get("prof_elec_jet_n_mu"));
  prof_bkgd_nojvf_elec_jet_n_mu->Add((TProfile*)nojvf_alpgen_qcd->Get("prof_elec_jet_n_mu"));
  prof_bkgd_nojvf_elec_jet_n_mu->Add((TProfile*)nojvf_top->Get("prof_elec_jet_n_mu"));
  prof_bkgd_nojvf_elec_jet_n_mu->Add((TProfile*)nojvf_zjets->Get("prof_elec_jet_n_mu"));
  
  // data plots
  TCanvas* tc_data_elec_jet_n_mu
    = new TCanvas("tc_data_elec_jet_n_mu","tc_data_elec_jet_n_mu",0,0,1920,1200);
  tc_data_elec_jet_n_mu->cd();

  //prof_data_jvf_elec_jet_n_mu->Scale(1/prof_data_jvf_elec_jet_n_mu->Integral());
  prof_data_jvf_elec_jet_n_mu->GetYaxis()->SetRangeUser(2,3.5);
  prof_data_jvf_elec_jet_n_mu->GetYaxis()->SetTitle("Avg Number of Jets");
  prof_data_jvf_elec_jet_n_mu->GetXaxis()->SetTitle("Avg Interactions Per Xing <mu>");
  prof_data_jvf_elec_jet_n_mu->SetLineColor(kRed);
  prof_data_jvf_elec_jet_n_mu->SetTitle("w/ JVF Cut");
  prof_data_jvf_elec_jet_n_mu->Draw();

  //prof_data_nojvf_elec_jet_n_mu->Scale(1/prof_data_nojvf_elec_jet_n_mu->Integral());
  prof_data_nojvf_elec_jet_n_mu->SetTitle("no JVF Cut");
  prof_data_nojvf_elec_jet_n_mu->SetLineColor(kBlue);
  prof_data_nojvf_elec_jet_n_mu->Draw("sames");


  TLegend* tl_data_elec_jet_n_mu = new TLegend(0.63,0.8,0.9,0.9);
  tl_data_elec_jet_n_mu->SetFillColor(0);
  tl_data_elec_jet_n_mu->SetTextSize(0.03);
  tl_data_elec_jet_n_mu->SetHeader("Data");
  tl_data_elec_jet_n_mu->AddEntry(prof_data_jvf_elec_jet_n_mu);
  tl_data_elec_jet_n_mu->AddEntry(prof_data_nojvf_elec_jet_n_mu);
  tl_data_elec_jet_n_mu->Draw();

  tc_data_elec_jet_n_mu->Update();
  
  string cur_saveas = "../canvases/latest/prof_jvf_data_elec_jet_n_mu.eps";
  tc_data_elec_jet_n_mu->SaveAs(cur_saveas.c_str());


  //////////////////////////////////////////////////
  // prof_muon_jet_n_mu
  ////////////////////////////////////////////////// 

  //jvf
  TProfile* prof_data_jvf_muon_jet_n_mu = jvf_data->Get("prof_muon_jet_n_mu");

  TProfile* prof_bkgd_jvf_muon_jet_n_mu = jvf_alpgen_wjets->Get("prof_muon_jet_n_mu");
  prof_bkgd_jvf_muon_jet_n_mu->Add((TProfile*)jvf_vv->Get("prof_muon_jet_n_mu"));
  prof_bkgd_jvf_muon_jet_n_mu->Add((TProfile*)jvf_alpgen_qcd->Get("prof_muon_jet_n_mu"));
  prof_bkgd_jvf_muon_jet_n_mu->Add((TProfile*)jvf_top->Get("prof_muon_jet_n_mu"));
  prof_bkgd_jvf_muon_jet_n_mu->Add((TProfile*)jvf_zjets->Get("prof_muon_jet_n_mu"));

  //nojvf
  TProfile* prof_data_nojvf_muon_jet_n_mu = nojvf_data->Get("prof_muon_jet_n_mu");

  TProfile* prof_bkgd_nojvf_muon_jet_n_mu = nojvf_alpgen_wjets->Get("prof_muon_jet_n_mu");
  prof_bkgd_nojvf_muon_jet_n_mu->Add((TProfile*)nojvf_vv->Get("prof_muon_jet_n_mu"));
  prof_bkgd_nojvf_muon_jet_n_mu->Add((TProfile*)nojvf_alpgen_qcd->Get("prof_muon_jet_n_mu"));
  prof_bkgd_nojvf_muon_jet_n_mu->Add((TProfile*)nojvf_top->Get("prof_muon_jet_n_mu"));
  prof_bkgd_nojvf_muon_jet_n_mu->Add((TProfile*)nojvf_zjets->Get("prof_muon_jet_n_mu"));
  
  // data plots
  TCanvas* tc_data_muon_jet_n_mu
    = new TCanvas("tc_data_muon_jet_n_mu","tc_data_muon_jet_n_mu",0,0,1920,1200);
  tc_data_muon_jet_n_mu->cd();

  //prof_data_jvf_muon_jet_n_mu->Scale(1/prof_data_jvf_muon_jet_n_mu->Integral());
  prof_data_jvf_muon_jet_n_mu->GetYaxis()->SetRangeUser(2,3.5);
  prof_data_jvf_muon_jet_n_mu->GetYaxis()->SetTitle("Avg Jet Pt");
  prof_data_jvf_muon_jet_n_mu->GetXaxis()->SetTitle("Avg Interactions Per Xing <mu>");
  prof_data_jvf_muon_jet_n_mu->SetLineColor(kRed);
  prof_data_jvf_muon_jet_n_mu->SetTitle("w/ JVF Cut");
  prof_data_jvf_muon_jet_n_mu->Draw();

  //prof_data_nojvf_muon_jet_n_mu->Scale(1/prof_data_nojvf_muon_jet_n_mu->Integral());
  prof_data_nojvf_muon_jet_n_mu->SetTitle("no JVF Cut");
  prof_data_nojvf_muon_jet_n_mu->SetLineColor(kBlue);
  prof_data_nojvf_muon_jet_n_mu->Draw("sames");


  TLegend* tl_data_muon_jet_n_mu = new TLegend(0.63,0.8,0.9,0.9);
  tl_data_muon_jet_n_mu->SetFillColor(0);
  tl_data_muon_jet_n_mu->SetTextSize(0.03);
  tl_data_muon_jet_n_mu->SetHeader("Data");
  tl_data_muon_jet_n_mu->AddEntry(prof_data_jvf_muon_jet_n_mu);
  tl_data_muon_jet_n_mu->AddEntry(prof_data_nojvf_muon_jet_n_mu);
  tl_data_muon_jet_n_mu->Draw();

  tc_data_muon_jet_n_mu->Update();
  
  string cur_saveas = "../canvases/latest/prof_jvf_data_muon_jet_n_mu.eps";
  tc_data_muon_jet_n_mu->SaveAs(cur_saveas.c_str());


  //////////////////////////////////////////////////
  // prof_elec_jet_pt_mu
  ////////////////////////////////////////////////// 

  //jvf
  TProfile* prof_data_jvf_elec_jet_pt_mu = jvf_data->Get("prof_elec_jet_pt_mu");

  TProfile* prof_bkgd_jvf_elec_jet_pt_mu = jvf_alpgen_wjets->Get("prof_elec_jet_pt_mu");
  prof_bkgd_jvf_elec_jet_pt_mu->Add((TProfile*)jvf_vv->Get("prof_elec_jet_pt_mu"));
  prof_bkgd_jvf_elec_jet_pt_mu->Add((TProfile*)jvf_alpgen_qcd->Get("prof_elec_jet_pt_mu"));
  prof_bkgd_jvf_elec_jet_pt_mu->Add((TProfile*)jvf_top->Get("prof_elec_jet_pt_mu"));
  prof_bkgd_jvf_elec_jet_pt_mu->Add((TProfile*)jvf_zjets->Get("prof_elec_jet_pt_mu"));

  //nojvf
  TProfile* prof_data_nojvf_elec_jet_pt_mu = nojvf_data->Get("prof_elec_jet_pt_mu");

  TProfile* prof_bkgd_nojvf_elec_jet_pt_mu = nojvf_alpgen_wjets->Get("prof_elec_jet_pt_mu");
  prof_bkgd_nojvf_elec_jet_pt_mu->Add((TProfile*)nojvf_vv->Get("prof_elec_jet_pt_mu"));
  prof_bkgd_nojvf_elec_jet_pt_mu->Add((TProfile*)nojvf_alpgen_qcd->Get("prof_elec_jet_pt_mu"));
  prof_bkgd_nojvf_elec_jet_pt_mu->Add((TProfile*)nojvf_top->Get("prof_elec_jet_pt_mu"));
  prof_bkgd_nojvf_elec_jet_pt_mu->Add((TProfile*)nojvf_zjets->Get("prof_elec_jet_pt_mu"));
  
  // data plots
  TCanvas* tc_data_elec_jet_pt_mu
    = new TCanvas("tc_data_elec_jet_pt_mu","tc_data_elec_jet_pt_mu",0,0,1920,1200);
  tc_data_elec_jet_pt_mu->cd();

  //prof_data_jvf_elec_jet_pt_mu->Scale(1/prof_data_jvf_elec_jet_pt_mu->Integral());
  prof_data_jvf_elec_jet_pt_mu->GetYaxis()->SetRangeUser(80,140);
  prof_data_jvf_elec_jet_pt_mu->GetYaxis()->SetTitle("Avg Lead Jet Pt [GeV]");
  prof_data_jvf_elec_jet_pt_mu->GetXaxis()->SetTitle("Avg Interactions Per Xing <mu>");
  prof_data_jvf_elec_jet_pt_mu->SetLineColor(kRed);
  prof_data_jvf_elec_jet_pt_mu->SetTitle("w/ JVF Cut");
  prof_data_jvf_elec_jet_pt_mu->Draw();

  //prof_data_nojvf_elec_jet_pt_mu->Scale(1/prof_data_nojvf_elec_jet_pt_mu->Integral());
  prof_data_nojvf_elec_jet_pt_mu->SetTitle("no JVF Cut");
  prof_data_nojvf_elec_jet_pt_mu->SetLineColor(kBlue);
  prof_data_nojvf_elec_jet_pt_mu->Draw("sames");


  TLegend* tl_data_elec_jet_pt_mu = new TLegend(0.63,0.8,0.9,0.9);
  tl_data_elec_jet_pt_mu->SetFillColor(0);
  tl_data_elec_jet_pt_mu->SetTextSize(0.03);
  tl_data_elec_jet_pt_mu->SetHeader("Data");
  tl_data_elec_jet_pt_mu->AddEntry(prof_data_jvf_elec_jet_pt_mu);
  tl_data_elec_jet_pt_mu->AddEntry(prof_data_nojvf_elec_jet_pt_mu);
  tl_data_elec_jet_pt_mu->Draw();

  tc_data_elec_jet_pt_mu->Update();
  
  string cur_saveas = "../canvases/latest/prof_jvf_data_elec_jet_pt_mu.eps";
  tc_data_elec_jet_pt_mu->SaveAs(cur_saveas.c_str());


  //////////////////////////////////////////////////
  // prof_muon_jet_pt_mu
  ////////////////////////////////////////////////// 

  //jvf
  TProfile* prof_data_jvf_muon_jet_pt_mu = jvf_data->Get("prof_muon_jet_pt_mu");

  TProfile* prof_bkgd_jvf_muon_jet_pt_mu = jvf_alpgen_wjets->Get("prof_muon_jet_pt_mu");
  prof_bkgd_jvf_muon_jet_pt_mu->Add((TProfile*)jvf_vv->Get("prof_muon_jet_pt_mu"));
  prof_bkgd_jvf_muon_jet_pt_mu->Add((TProfile*)jvf_alpgen_qcd->Get("prof_muon_jet_pt_mu"));
  prof_bkgd_jvf_muon_jet_pt_mu->Add((TProfile*)jvf_top->Get("prof_muon_jet_pt_mu"));
  prof_bkgd_jvf_muon_jet_pt_mu->Add((TProfile*)jvf_zjets->Get("prof_muon_jet_pt_mu"));

  //nojvf
  TProfile* prof_data_nojvf_muon_jet_pt_mu = nojvf_data->Get("prof_muon_jet_pt_mu");

  TProfile* prof_bkgd_nojvf_muon_jet_pt_mu = nojvf_alpgen_wjets->Get("prof_muon_jet_pt_mu");
  prof_bkgd_nojvf_muon_jet_pt_mu->Add((TProfile*)nojvf_vv->Get("prof_muon_jet_pt_mu"));
  prof_bkgd_nojvf_muon_jet_pt_mu->Add((TProfile*)nojvf_alpgen_qcd->Get("prof_muon_jet_pt_mu"));
  prof_bkgd_nojvf_muon_jet_pt_mu->Add((TProfile*)nojvf_top->Get("prof_muon_jet_pt_mu"));
  prof_bkgd_nojvf_muon_jet_pt_mu->Add((TProfile*)nojvf_zjets->Get("prof_muon_jet_pt_mu"));
  
  // data plots
  TCanvas* tc_data_muon_jet_pt_mu
    = new TCanvas("tc_data_muon_jet_pt_mu","tc_data_muon_jet_pt_mu",0,0,1920,1200);
  tc_data_muon_jet_pt_mu->cd();

  //prof_data_jvf_muon_jet_pt_mu->Scale(1/prof_data_jvf_muon_jet_pt_mu->Integral());
  prof_data_jvf_muon_jet_pt_mu->GetYaxis()->SetRangeUser(80,140);
  prof_data_jvf_muon_jet_pt_mu->GetYaxis()->SetTitle("Avg Lead Jet Pt [GeV]");
  prof_data_jvf_muon_jet_pt_mu->GetXaxis()->SetTitle("Avg Interactions Per Xing <mu>");
  prof_data_jvf_muon_jet_pt_mu->SetLineColor(kRed);
  prof_data_jvf_muon_jet_pt_mu->SetTitle("w/ JVF Cut");
  prof_data_jvf_muon_jet_pt_mu->Draw();

  //prof_data_nojvf_muon_jet_pt_mu->Scale(1/prof_data_nojvf_muon_jet_pt_mu->Integral());
  prof_data_nojvf_muon_jet_pt_mu->SetTitle("no JVF Cut");
  prof_data_nojvf_muon_jet_pt_mu->SetLineColor(kBlue);
  prof_data_nojvf_muon_jet_pt_mu->Draw("sames");


  TLegend* tl_data_muon_jet_pt_mu = new TLegend(0.63,0.8,0.9,0.9);
  tl_data_muon_jet_pt_mu->SetFillColor(0);
  tl_data_muon_jet_pt_mu->SetTextSize(0.03);
  tl_data_muon_jet_pt_mu->SetHeader("Data");
  tl_data_muon_jet_pt_mu->AddEntry(prof_data_jvf_muon_jet_pt_mu);
  tl_data_muon_jet_pt_mu->AddEntry(prof_data_nojvf_muon_jet_pt_mu);
  tl_data_muon_jet_pt_mu->Draw();

  tc_data_muon_jet_pt_mu->Update();
  
  string cur_saveas = "../canvases/latest/prof_jvf_data_muon_jet_pt_mu.eps";
  tc_data_muon_jet_pt_mu->SaveAs(cur_saveas.c_str());

  
}

