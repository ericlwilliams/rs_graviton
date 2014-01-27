#include <TCanvas.h>
#include <TPad.h>
#include <TGraph.h>
#include <TFile.h>
#include <TDirectory.h>
#include "../../include/atlasstyle-00-03-04/AtlasStyle.C";
float ratio_split=0.35;

string plot_dir_name="opt";

void printTruthSignalPlots(string sample="data"){

  SetAtlasStyle();
  gROOT->SetBatch();
  
  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In printTruthSignalPlots.C"<<endl;

  string save_loc = "../canvases/latest/";
  string cur_saveas="";

  // rsg_file
  TFile* rsg_m500_file = (TFile*) TFile::Open("../plots/rsg_m500_truth_plots.root");
  TFile* rsg_m1000_file = (TFile*) TFile::Open("../plots/rsg_m1000_truth_plots.root");

  // wprime_file
  TFile* wprime_m500_file = (TFile*) TFile::Open("../plots/wprime_m500_truth_plots.root");
  TFile* wprime_m1000_file = (TFile*) TFile::Open("../plots/wprime_m1000_truth_plots.root");

  // kkg_file
  TFile* kkg_m500_file = (TFile*) TFile::Open("../plots/kkg_m500_truth_plots.root");
  TFile* kkg_m1000_file = (TFile*) TFile::Open("../plots/kkg_m1000_truth_plots.root");
  
  
  //////////////////////////////////////////////////
  // plots
  ////////////////////////////////////////////////// 
  
  // // m500_v_pt
  // TCanvas* tc_m500_v_pt = new TCanvas("tc_m500_v_pt","tc_m500_v_pt",0,0,1920,1200);
  // tc_m500_v_pt->cd();

  // TH1F* h_rsg_m500_v_pt = (TH1F*) rsg_m500_file->Get("h_v_pt");
  // h_rsg_m500_v_pt->Scale(1./h_rsg_m500_v_pt->Integral());
  
  // TH1F* h_wprime_m500_v_pt = (TH1F*) wprime_m500_file->Get("h_v_pt");
  // h_wprime_m500_v_pt->Scale(1./h_wprime_m500_v_pt->Integral());

  // h_rsg_m500_v_pt->GetXaxis()->SetTitle("W/Z boson pt [GeV]");
  // h_rsg_m500_v_pt->SetLineColor(kRed);
  // h_rsg_m500_v_pt->Draw();

  // h_wprime_m500_v_pt->SetLineColor(kBlue);
  // h_wprime_m500_v_pt->Draw("same");

  // tc_m500_v_pt->SetLogy();
  // tc_m500_v_pt->Update();

  // TLegend* lgnd_m500_v_pt = new TLegend(0.80,0.75,0.9,0.90);
  // lgnd_m500_v_pt->SetFillColor(0);
  // lgnd_m500_v_pt->SetTextSize(0.05);
  // lgnd_m500_v_pt->SetBorderSize(0);
  // lgnd_m500_v_pt->AddEntry(h_rsg_m500_v_pt,"G*","L");
  // lgnd_m500_v_pt->AddEntry(h_wprime_m500_v_pt,"W'","L");
  // lgnd_m500_v_pt->Draw();
  

  // cur_saveas = save_loc+"h_m500_v_pt.pdf";
  // tc_m500_v_pt->SaveAs(cur_saveas.c_str());

  // // m500_v_eta
  // TCanvas* tc_m500_v_eta = new TCanvas("tc_m500_v_eta","tc_m500_v_eta",0,0,1920,1200);
  // tc_m500_v_eta->cd();

  // TH1F* h_rsg_m500_v_eta = (TH1F*) rsg_m500_file->Get("h_v_eta");
  // h_rsg_m500_v_eta->Scale(1./h_rsg_m500_v_eta->Integral());
  
  // TH1F* h_wprime_m500_v_eta = (TH1F*) wprime_m500_file->Get("h_v_eta");
  // h_wprime_m500_v_eta->Scale(1./h_wprime_m500_v_eta->Integral());
  
  // h_rsg_m500_v_eta->GetXaxis()->SetTitle("W/Z boson #eta");
  // h_rsg_m500_v_eta->SetLineColor(kRed);
  // h_rsg_m500_v_eta->Draw();
  
  // h_wprime_m500_v_eta->SetLineColor(kBlue);
  // h_wprime_m500_v_eta->Draw("same");

  // tc_m500_v_eta->SetLogy();
  // tc_m500_v_eta->Update();

  // TLegend* lgnd_m500_v_eta = new TLegend(0.80,0.75,0.9,0.90);
  // lgnd_m500_v_eta->SetFillColor(0);
  // lgnd_m500_v_eta->SetTextSize(0.05);
  // lgnd_m500_v_eta->SetBorderSize(0);
  // lgnd_m500_v_eta->AddEntry(h_rsg_m500_v_eta,"G*","L");
  // lgnd_m500_v_eta->AddEntry(h_wprime_m500_v_eta,"W'","L");
  // lgnd_m500_v_eta->Draw();
  
  // cur_saveas = save_loc+"h_m500_v_eta.pdf";
  // tc_m500_v_eta->SaveAs(cur_saveas.c_str());


  // // m500_vv_pt
  // TCanvas* tc_m500_vv_pt = new TCanvas("tc_m500_vv_pt","tc_m500_vv_pt",0,0,1920,1200);
  // tc_m500_vv_pt->cd();

  // TH1F* h_rsg_m500_vv_pt = (TH1F*) rsg_m500_file->Get("h_vv_pt");
  // h_rsg_m500_vv_pt->Scale(1./h_rsg_m500_vv_pt->Integral());
  
  // TH1F* h_wprime_m500_vv_pt = (TH1F*) wprime_m500_file->Get("h_vv_pt");
  // h_wprime_m500_vv_pt->Scale(1./h_wprime_m500_vv_pt->Integral());
  
  // h_rsg_m500_vv_pt->GetXaxis()->SetTitle("G*/W' pt [GeV]");
  // h_rsg_m500_vv_pt->SetLineColor(kRed);
  // h_rsg_m500_vv_pt->Draw();

  // h_wprime_m500_vv_pt->SetLineColor(kBlue);
  // h_wprime_m500_vv_pt->Draw("same");

  // tc_m500_vv_pt->SetLogy();
  // tc_m500_vv_pt->Update();

  // TLegend* lgnd_m500_vv_pt = new TLegend(0.80,0.75,0.9,0.90);
  // lgnd_m500_vv_pt->SetFillColor(0);
  // lgnd_m500_vv_pt->SetTextSize(0.05);
  // lgnd_m500_vv_pt->SetBorderSize(0);
  // lgnd_m500_vv_pt->AddEntry(h_rsg_m500_vv_pt,"G*","L");
  // lgnd_m500_vv_pt->AddEntry(h_wprime_m500_vv_pt,"W'","L");
  // lgnd_m500_vv_pt->Draw();
  

  // cur_saveas = save_loc+"h_m500_vv_pt.pdf";
  // tc_m500_vv_pt->SaveAs(cur_saveas.c_str());


  // // m500_vv_eta
  // TCanvas* tc_m500_vv_eta = new TCanvas("tc_m500_vv_eta","tc_m500_vv_eta",0,0,1920,1200);
  // tc_m500_vv_eta->cd();

  // TH1F* h_rsg_m500_vv_eta = (TH1F*) rsg_m500_file->Get("h_vv_eta");
  // h_rsg_m500_vv_eta->Scale(1./h_rsg_m500_vv_eta->Integral());
  
  // TH1F* h_wprime_m500_vv_eta = (TH1F*) wprime_m500_file->Get("h_vv_eta");
  // h_wprime_m500_vv_eta->Scale(1./h_wprime_m500_vv_eta->Integral());

  // h_rsg_m500_vv_eta->GetXaxis()->SetTitle("G*/W' #eta");
  // h_rsg_m500_vv_eta->SetLineColor(kRed);
  // h_rsg_m500_vv_eta->Draw();
  
  // h_wprime_m500_vv_eta->SetLineColor(kBlue);
  // h_wprime_m500_vv_eta->Draw("same");

  // tc_m500_vv_eta->SetLogy();
  // tc_m500_vv_eta->Update();

  // TLegend* lgnd_m500_vv_eta = new TLegend(0.80,0.75,0.9,0.90);
  // lgnd_m500_vv_eta->SetFillColor(0);
  // lgnd_m500_vv_eta->SetTextSize(0.05);
  // lgnd_m500_vv_eta->SetBorderSize(0);
  // lgnd_m500_vv_eta->AddEntry(h_rsg_m500_vv_eta,"G*","L");
  // lgnd_m500_vv_eta->AddEntry(h_wprime_m500_vv_eta,"W'","L");
  // lgnd_m500_vv_eta->Draw();
  
  // cur_saveas = save_loc+"h_m500_vv_eta.pdf";
  // tc_m500_vv_eta->SaveAs(cur_saveas.c_str());


  // // m500_lep_pt
  // TCanvas* tc_m500_lep_pt = new TCanvas("tc_m500_lep_pt","tc_m500_lep_pt",0,0,1920,1200);
  // tc_m500_lep_pt->cd();

  // TH1F* h_rsg_m500_lep_pt = (TH1F*) rsg_m500_file->Get("h_lep_pt");
  // h_rsg_m500_lep_pt->Scale(1./h_rsg_m500_lep_pt->Integral());
  
  // TH1F* h_wprime_m500_lep_pt = (TH1F*) wprime_m500_file->Get("h_lep_pt");
  // h_wprime_m500_lep_pt->Scale(1./h_wprime_m500_lep_pt->Integral());

  // h_rsg_m500_lep_pt->GetXaxis()->SetTitle("lepton pt [GeV]");
  // h_rsg_m500_lep_pt->SetLineColor(kRed);
  // h_rsg_m500_lep_pt->Draw();

  // h_wprime_m500_lep_pt->SetLineColor(kBlue);
  // h_wprime_m500_lep_pt->Draw("same");

  // tc_m500_lep_pt->SetLogy();
  // tc_m500_lep_pt->Update();

  // TLegend* lgnd_m500_lep_pt = new TLegend(0.80,0.75,0.9,0.90);
  // lgnd_m500_lep_pt->SetFillColor(0);
  // lgnd_m500_lep_pt->SetTextSize(0.05);
  // lgnd_m500_lep_pt->SetBorderSize(0);
  // lgnd_m500_lep_pt->AddEntry(h_rsg_m500_lep_pt,"G*","L");
  // lgnd_m500_lep_pt->AddEntry(h_wprime_m500_lep_pt,"W'","L");
  // lgnd_m500_lep_pt->Draw();
  

  // cur_saveas = save_loc+"h_m500_lep_pt.pdf";
  // tc_m500_lep_pt->SaveAs(cur_saveas.c_str());


  // // m500_lep_eta
  // TCanvas* tc_m500_lep_eta = new TCanvas("tc_m500_lep_eta","tc_m500_lep_eta",0,0,1920,1200);
  // tc_m500_lep_eta->cd();

  // TH1F* h_rsg_m500_lep_eta = (TH1F*) rsg_m500_file->Get("h_lep_eta");
  // h_rsg_m500_lep_eta->Scale(1./h_rsg_m500_lep_eta->Integral());
  
  // TH1F* h_wprime_m500_lep_eta = (TH1F*) wprime_m500_file->Get("h_lep_eta");
  // h_wprime_m500_lep_eta->Scale(1./h_wprime_m500_lep_eta->Integral());
  
  // h_rsg_m500_lep_eta->GetXaxis()->SetTitle("lepton #eta");
  // h_rsg_m500_lep_eta->SetLineColor(kRed);
  // h_rsg_m500_lep_eta->Draw();
  
  // h_wprime_m500_lep_eta->SetLineColor(kBlue);
  // h_wprime_m500_lep_eta->Draw("same");

  // tc_m500_lep_eta->SetLogy();
  // tc_m500_lep_eta->Update();

  // TLegend* lgnd_m500_lep_eta = new TLegend(0.80,0.75,0.9,0.90);
  // lgnd_m500_lep_eta->SetFillColor(0);
  // lgnd_m500_lep_eta->SetTextSize(0.05);
  // lgnd_m500_lep_eta->SetBorderSize(0);
  // lgnd_m500_lep_eta->AddEntry(h_rsg_m500_lep_eta,"G*","L");
  // lgnd_m500_lep_eta->AddEntry(h_wprime_m500_lep_eta,"W'","L");
  // lgnd_m500_lep_eta->Draw();
  
  // cur_saveas = save_loc+"h_m500_lep_eta.pdf";
  // tc_m500_lep_eta->SaveAs(cur_saveas.c_str());



  // // m500_nu_pt
  // TCanvas* tc_m500_nu_pt = new TCanvas("tc_m500_nu_pt","tc_m500_nu_pt",0,0,1920,1200);
  // tc_m500_nu_pt->cd();

  // TH1F* h_rsg_m500_nu_pt = (TH1F*) rsg_m500_file->Get("h_nu_pt");
  // h_rsg_m500_nu_pt->Scale(1./h_rsg_m500_nu_pt->Integral());
  
  // TH1F* h_wprime_m500_nu_pt = (TH1F*) wprime_m500_file->Get("h_nu_pt");
  // h_wprime_m500_nu_pt->Scale(1./h_wprime_m500_nu_pt->Integral());

  // h_rsg_m500_nu_pt->GetXaxis()->SetTitle("lepton pt [GeV]");
  // h_rsg_m500_nu_pt->SetLineColor(kRed);
  // h_rsg_m500_nu_pt->Draw();

  // h_wprime_m500_nu_pt->SetLineColor(kBlue);
  // h_wprime_m500_nu_pt->Draw("same");

  // tc_m500_nu_pt->SetLogy();
  // tc_m500_nu_pt->Update();

  // TLegend* lgnd_m500_nu_pt = new TLegend(0.80,0.75,0.9,0.90);
  // lgnd_m500_nu_pt->SetFillColor(0);
  // lgnd_m500_nu_pt->SetTextSize(0.05);
  // lgnd_m500_nu_pt->SetBorderSize(0);
  // lgnd_m500_nu_pt->AddEntry(h_rsg_m500_nu_pt,"G*","L");
  // lgnd_m500_nu_pt->AddEntry(h_wprime_m500_nu_pt,"W'","L");
  // lgnd_m500_nu_pt->Draw();
  

  // cur_saveas = save_loc+"h_m500_nu_pt.pdf";
  // tc_m500_nu_pt->SaveAs(cur_saveas.c_str());




  // // m500_qrk_pt
  // TCanvas* tc_m500_qrk_pt = new TCanvas("tc_m500_qrk_pt","tc_m500_jet_pt",0,0,1920,1200);
  // tc_m500_jet_pt->cd();

  // TH1F* h_rsg_m500_jet_pt = (TH1F*) rsg_m500_file->Get("h_jet_pt");
  // h_rsg_m500_jet_pt->Scale(1./h_rsg_m500_jet_pt->Integral());
  
  // TH1F* h_wprime_m500_jet_pt = (TH1F*) wprime_m500_file->Get("h_jet_pt");
  // h_wprime_m500_jet_pt->Scale(1./h_wprime_m500_jet_pt->Integral());
  
  // h_rsg_m500_jet_pt->GetXaxis()->SetTitle("jet pt [GeV]");
  // h_rsg_m500_jet_pt->SetLineColor(kRed);
  // h_rsg_m500_jet_pt->Draw();

  // h_wprime_m500_jet_pt->SetLineColor(kBlue);
  // h_wprime_m500_jet_pt->Draw("same");

  // tc_m500_jet_pt->SetLogy();
  // tc_m500_jet_pt->Update();

  // TLegend* lgnd_m500_jet_pt = new TLegend(0.80,0.75,0.9,0.90);
  // lgnd_m500_jet_pt->SetFillColor(0);
  // lgnd_m500_jet_pt->SetTextSize(0.05);
  // lgnd_m500_jet_pt->SetBorderSize(0);
  // lgnd_m500_jet_pt->AddEntry(h_rsg_m500_jet_pt,"G*","L");
  // lgnd_m500_jet_pt->AddEntry(h_wprime_m500_jet_pt,"W'","L");
  // lgnd_m500_jet_pt->Draw();
  

  // cur_saveas = save_loc+"h_m500_jet_pt.pdf";
  // tc_m500_jet_pt->SaveAs(cur_saveas.c_str());


  // // m500_jet_eta
  // TCanvas* tc_m500_jet_eta = new TCanvas("tc_m500_jet_eta","tc_m500_jet_eta",0,0,1920,1200);
  // tc_m500_jet_eta->cd();

  // TH1F* h_rsg_m500_jet_eta = (TH1F*) rsg_m500_file->Get("h_jet_eta");
  // h_rsg_m500_jet_eta->Scale(1./h_rsg_m500_jet_eta->Integral());
  
  // TH1F* h_wprime_m500_jet_eta = (TH1F*) wprime_m500_file->Get("h_jet_eta");
  // h_wprime_m500_jet_eta->Scale(1./h_wprime_m500_jet_eta->Integral());

  // h_rsg_m500_jet_eta->GetXaxis()->SetTitle("jet #eta");
  // h_rsg_m500_jet_eta->SetLineColor(kRed);
  // h_rsg_m500_jet_eta->Draw();
  
  // h_wprime_m500_jet_eta->SetLineColor(kBlue);
  // h_wprime_m500_jet_eta->Draw("same");

  // tc_m500_jet_eta->SetLogy();
  // tc_m500_jet_eta->Update();

  // TLegend* lgnd_m500_jet_eta = new TLegend(0.80,0.75,0.9,0.90);
  // lgnd_m500_jet_eta->SetFillColor(0);
  // lgnd_m500_jet_eta->SetTextSize(0.05);
  // lgnd_m500_jet_eta->SetBorderSize(0);
  // lgnd_m500_jet_eta->AddEntry(h_rsg_m500_jet_eta,"G*","L");
  // lgnd_m500_jet_eta->AddEntry(h_wprime_m500_jet_eta,"W'","L");
  // lgnd_m500_jet_eta->Draw();
  
  // cur_saveas = save_loc+"h_m500_jet_eta.pdf";
  // tc_m500_jet_eta->SaveAs(cur_saveas.c_str());

  // // m500_cos_theta_star
  // TCanvas* tc_m500_cos_theta_star = new TCanvas("tc_m500_cos_theta_star","tc_m500_cos_theta_star",0,0,1920,1200);
  // tc_m500_cos_theta_star->cd();

  // TH1F* h_rsg_m500_cos_theta_star = (TH1F*) rsg_m500_file->Get("h_cos_theta_star");
  // h_rsg_m500_cos_theta_star->Scale(1./h_rsg_m500_cos_theta_star->Integral());
  
  // TH1F* h_wprime_m500_cos_theta_star = (TH1F*) wprime_m500_file->Get("h_cos_theta_star");
  // h_wprime_m500_cos_theta_star->Scale(1./h_wprime_m500_cos_theta_star->Integral());

  // h_rsg_m500_cos_theta_star->GetYaxis()->SetRangeUser(0,0.08);
  // h_rsg_m500_cos_theta_star->GetXaxis()->SetTitle("cos(#theta*)");
  // h_rsg_m500_cos_theta_star->SetLineColor(kRed);
  // h_rsg_m500_cos_theta_star->Draw();
  
  // h_wprime_m500_cos_theta_star->SetLineColor(kBlue);
  // h_wprime_m500_cos_theta_star->Draw("same");

  // //tc_m500_cos_theta_star->SetLogy();
  // tc_m500_cos_theta_star->Update();

  // TLegend* lgnd_m500_cos_theta_star = new TLegend(0.80,0.75,0.9,0.90);
  // lgnd_m500_cos_theta_star->SetFillColor(0);
  // lgnd_m500_cos_theta_star->SetTextSize(0.05);
  // lgnd_m500_cos_theta_star->SetBorderSize(0);
  // lgnd_m500_cos_theta_star->AddEntry(h_rsg_m500_cos_theta_star,"G*","L");
  // lgnd_m500_cos_theta_star->AddEntry(h_wprime_m500_cos_theta_star,"W'","L");
  // lgnd_m500_cos_theta_star->Draw();
  
  // cur_saveas = save_loc+"h_m500_cos_theta_star.pdf";
  // tc_m500_cos_theta_star->SaveAs(cur_saveas.c_str());

  // // m500_vv_m
  // TCanvas* tc_m500_vv_m = new TCanvas("tc_m500_vv_m","tc_m500_vv_m",0,0,1920,1200);
  // tc_m500_vv_m->cd();

  // TH1F* h_rsg_m500_vv_m = (TH1F*) rsg_m500_file->Get("h_vv_m");
  // h_rsg_m500_vv_m->Scale(1./h_rsg_m500_vv_m->Integral());


  
  // TH1F* h_wprime_m500_vv_m = (TH1F*) wprime_m500_file->Get("h_vv_m");
  // h_wprime_m500_vv_m->Scale(1./h_wprime_m500_vv_m->Integral());

  // h_rsg_m500_vv_m->GetXaxis()->SetTitle("G*/W' #m");
  // h_rsg_m500_vv_m->SetLineColor(kRed);
  // h_rsg_m500_vv_m->Draw();
  
  // h_wprime_m500_vv_m->SetLineColor(kBlue);
  // h_wprime_m500_vv_m->Draw("same");


  // tc_m500_vv_m->SetLogy();
  // tc_m500_vv_m->Update();

  // TLegend* lgnd_m500_vv_m = new TLegend(0.80,0.75,0.9,0.90);
  // lgnd_m500_vv_m->SetFillColor(0);
  // lgnd_m500_vv_m->SetTextSize(0.05);
  // lgnd_m500_vv_m->SetBorderSize(0);
  // lgnd_m500_vv_m->AddEntry(h_rsg_m500_vv_m,"G*","L");
  // lgnd_m500_vv_m->AddEntry(h_wprime_m500_vv_m,"W'","L");
  // lgnd_m500_vv_m->Draw();
  
  // cur_saveas = save_loc+"h_m500_vv_m.pdf";
  // tc_m500_vv_m->SaveAs(cur_saveas.c_str());

  
  // m1000_v_pt
  TCanvas* tc_m1000_v_pt = new TCanvas("tc_m1000_v_pt","tc_m1000_v_pt",0,0,1920,1200);
  tc_m1000_v_pt->cd();

  TH1F* h_rsg_m1000_v_pt = (TH1F*) rsg_m1000_file->Get("h_v_pt");
  h_rsg_m1000_v_pt->Scale(1./h_rsg_m1000_v_pt->Integral());
  
  TH1F* h_kkg_m1000_v_pt = (TH1F*) kkg_m1000_file->Get("h_v_pt");
  h_kkg_m1000_v_pt->Scale(1./h_kkg_m1000_v_pt->Integral());
  
  TH1F* h_wprime_m1000_v_pt = (TH1F*) wprime_m1000_file->Get("h_v_pt");
  h_wprime_m1000_v_pt->Scale(1./h_wprime_m1000_v_pt->Integral());

  h_rsg_m1000_v_pt->GetXaxis()->SetTitle("W/Z boson pt [GeV]");
  h_rsg_m1000_v_pt->SetLineColor(kRed);
  h_rsg_m1000_v_pt->Draw();

  h_wprime_m1000_v_pt->SetLineColor(kBlue);
  h_wprime_m1000_v_pt->Draw("same");

  h_kkg_m1000_v_pt->SetLineColor(kGreen);
  h_kkg_m1000_v_pt->Draw("same");

  tc_m1000_v_pt->SetLogy();
  tc_m1000_v_pt->Update();

  TLegend* lgnd_m1000_v_pt = new TLegend(0.80,0.75,0.9,0.90);
  lgnd_m1000_v_pt->SetFillColor(0);
  lgnd_m1000_v_pt->SetTextSize(0.05);
  lgnd_m1000_v_pt->SetBorderSize(0);
  lgnd_m1000_v_pt->AddEntry(h_rsg_m1000_v_pt,"G*","L");
  lgnd_m1000_v_pt->AddEntry(h_kkg_m1000_v_pt,"G_{kk}","L");
  lgnd_m1000_v_pt->AddEntry(h_wprime_m1000_v_pt,"W'","L");
  lgnd_m1000_v_pt->Draw();
  

  cur_saveas = save_loc+"h_m1000_v_pt.pdf";
  tc_m1000_v_pt->SaveAs(cur_saveas.c_str());


  // m1000_v_eta
  TCanvas* tc_m1000_v_eta = new TCanvas("tc_m1000_v_eta","tc_m1000_v_eta",0,0,1920,1200);
  tc_m1000_v_eta->cd();

  TH1F* h_rsg_m1000_v_eta = (TH1F*) rsg_m1000_file->Get("h_v_eta");
  h_rsg_m1000_v_eta->Scale(1./h_rsg_m1000_v_eta->Integral());
  
  TH1F* h_kkg_m1000_v_eta = (TH1F*) kkg_m1000_file->Get("h_v_eta");
  h_kkg_m1000_v_eta->Scale(1./h_kkg_m1000_v_eta->Integral());
  
  TH1F* h_wprime_m1000_v_eta = (TH1F*) wprime_m1000_file->Get("h_v_eta");
  h_wprime_m1000_v_eta->Scale(1./h_wprime_m1000_v_eta->Integral());
  
  h_rsg_m1000_v_eta->GetXaxis()->SetTitle("W/Z boson #eta");
  h_rsg_m1000_v_eta->SetLineColor(kRed);
  h_rsg_m1000_v_eta->Draw();
  
  h_wprime_m1000_v_eta->SetLineColor(kBlue);
  h_wprime_m1000_v_eta->Draw("same");

  h_kkg_m1000_v_eta->SetLineColor(kGreen);
  h_kkg_m1000_v_eta->Draw("same");

  tc_m1000_v_eta->SetLogy();
  tc_m1000_v_eta->Update();

  TLegend* lgnd_m1000_v_eta = new TLegend(0.80,0.75,0.9,0.90);
  lgnd_m1000_v_eta->SetFillColor(0);
  lgnd_m1000_v_eta->SetTextSize(0.05);
  lgnd_m1000_v_eta->SetBorderSize(0);
  lgnd_m1000_v_eta->AddEntry(h_rsg_m1000_v_eta,"G*","L");
  lgnd_m1000_v_eta->AddEntry(h_kkg_m1000_v_eta,"G_{kk}","L");
  lgnd_m1000_v_eta->AddEntry(h_wprime_m1000_v_eta,"W'","L");
  lgnd_m1000_v_eta->Draw();
  
  cur_saveas = save_loc+"h_m1000_v_eta.pdf";
  tc_m1000_v_eta->SaveAs(cur_saveas.c_str());


  // m1000_vv_pt
  TCanvas* tc_m1000_vv_pt = new TCanvas("tc_m1000_vv_pt","tc_m1000_vv_pt",0,0,1920,1200);
  tc_m1000_vv_pt->cd();

  TH1F* h_rsg_m1000_vv_pt = (TH1F*) rsg_m1000_file->Get("h_vv_pt");
  h_rsg_m1000_vv_pt->Scale(1./h_rsg_m1000_vv_pt->Integral());
  
  TH1F* h_kkg_m1000_vv_pt = (TH1F*) kkg_m1000_file->Get("h_vv_pt");
  h_kkg_m1000_vv_pt->Scale(1./h_kkg_m1000_vv_pt->Integral());
  
  TH1F* h_wprime_m1000_vv_pt = (TH1F*) wprime_m1000_file->Get("h_vv_pt");
  h_wprime_m1000_vv_pt->Scale(1./h_wprime_m1000_vv_pt->Integral());
  
  h_rsg_m1000_vv_pt->GetXaxis()->SetTitle("G*/W' pt [GeV]");
  h_rsg_m1000_vv_pt->SetLineColor(kRed);
  h_rsg_m1000_vv_pt->Draw();

  h_kkg_m1000_vv_pt->SetLineColor(kGreen);
  h_kkg_m1000_vv_pt->Draw("same");

  h_wprime_m1000_vv_pt->SetLineColor(kBlue);
  h_wprime_m1000_vv_pt->Draw("same");

  tc_m1000_vv_pt->SetLogy();
  tc_m1000_vv_pt->Update();

  TLegend* lgnd_m1000_vv_pt = new TLegend(0.80,0.75,0.9,0.90);
  lgnd_m1000_vv_pt->SetFillColor(0);
  lgnd_m1000_vv_pt->SetTextSize(0.05);
  lgnd_m1000_vv_pt->SetBorderSize(0);
  lgnd_m1000_vv_pt->AddEntry(h_rsg_m1000_vv_pt,"G*","L");
  lgnd_m1000_vv_pt->AddEntry(h_kkg_m1000_vv_pt,"G_{KK}","L");
  lgnd_m1000_vv_pt->AddEntry(h_wprime_m1000_vv_pt,"W'","L");
  lgnd_m1000_vv_pt->Draw();
  

  cur_saveas = save_loc+"h_m1000_vv_pt.pdf";
  tc_m1000_vv_pt->SaveAs(cur_saveas.c_str());


  // m1000_vv_eta
  TCanvas* tc_m1000_vv_eta = new TCanvas("tc_m1000_vv_eta","tc_m1000_vv_eta",0,0,1920,1200);
  tc_m1000_vv_eta->cd();

  TH1F* h_rsg_m1000_vv_eta = (TH1F*) rsg_m1000_file->Get("h_vv_eta");
  h_rsg_m1000_vv_eta->Scale(1./h_rsg_m1000_vv_eta->Integral());

  TH1F* h_kkg_m1000_vv_eta = (TH1F*) kkg_m1000_file->Get("h_vv_eta");
  h_kkg_m1000_vv_eta->Scale(1./h_kkg_m1000_vv_eta->Integral());
  
  TH1F* h_wprime_m1000_vv_eta = (TH1F*) wprime_m1000_file->Get("h_vv_eta");
  h_wprime_m1000_vv_eta->Scale(1./h_wprime_m1000_vv_eta->Integral());

  h_rsg_m1000_vv_eta->GetXaxis()->SetTitle("G*/W' #eta");
  h_rsg_m1000_vv_eta->SetLineColor(kRed);
  h_rsg_m1000_vv_eta->Draw();
  
  h_wprime_m1000_vv_eta->SetLineColor(kBlue);
  h_wprime_m1000_vv_eta->Draw("same");

  h_kkg_m1000_vv_eta->SetLineColor(kGreen);
  h_kkg_m1000_vv_eta->Draw("same");

  tc_m1000_vv_eta->SetLogy();
  tc_m1000_vv_eta->Update();

  TLegend* lgnd_m1000_vv_eta = new TLegend(0.80,0.75,0.9,0.90);
  lgnd_m1000_vv_eta->SetFillColor(0);
  lgnd_m1000_vv_eta->SetTextSize(0.05);
  lgnd_m1000_vv_eta->SetBorderSize(0);
  lgnd_m1000_vv_eta->AddEntry(h_rsg_m1000_vv_eta,"G*","L");
  lgnd_m1000_vv_eta->AddEntry(h_kkg_m1000_vv_eta,"G_{KK}","L");
  lgnd_m1000_vv_eta->AddEntry(h_wprime_m1000_vv_eta,"W'","L");
  lgnd_m1000_vv_eta->Draw();
  
  cur_saveas = save_loc+"h_m1000_vv_eta.pdf";
  tc_m1000_vv_eta->SaveAs(cur_saveas.c_str());

  // m1000_vv_m
  TCanvas* tc_m1000_vv_m = new TCanvas("tc_m1000_vv_m","tc_m1000_vv_m",0,0,1920,1200);
  tc_m1000_vv_m->cd();

  TH1F* h_rsg_m1000_vv_m = (TH1F*) rsg_m1000_file->Get("h_vv_m");
  h_rsg_m1000_vv_m->Scale(1./h_rsg_m1000_vv_m->Integral());

  TH1F* h_kkg_m1000_vv_m = (TH1F*) kkg_m1000_file->Get("h_vv_m");
  h_kkg_m1000_vv_m->Scale(1./h_kkg_m1000_vv_m->Integral());
  
  TH1F* h_wprime_m1000_vv_m = (TH1F*) wprime_m1000_file->Get("h_vv_m");
  h_wprime_m1000_vv_m->Scale(1./h_wprime_m1000_vv_m->Integral());

  h_rsg_m1000_vv_m->GetXaxis()->SetTitle("G*/W' #m");
  h_rsg_m1000_vv_m->SetLineColor(kRed);
  h_rsg_m1000_vv_m->Draw();
  
  h_wprime_m1000_vv_m->SetLineColor(kBlue);
  h_wprime_m1000_vv_m->Draw("same");

  h_kkg_m1000_vv_m->SetLineColor(kGreen);
  h_kkg_m1000_vv_m->Draw("same");

  tc_m1000_vv_m->SetLogy();
  tc_m1000_vv_m->Update();

  TLegend* lgnd_m1000_vv_m = new TLegend(0.80,0.75,0.9,0.90);
  lgnd_m1000_vv_m->SetFillColor(0);
  lgnd_m1000_vv_m->SetTextSize(0.05);
  lgnd_m1000_vv_m->SetBorderSize(0);
  lgnd_m1000_vv_m->AddEntry(h_rsg_m1000_vv_m,"G*","L");
  lgnd_m1000_vv_m->AddEntry(h_kkg_m1000_vv_m,"G_{KK}","L");
  lgnd_m1000_vv_m->AddEntry(h_wprime_m1000_vv_m,"W'","L");
  lgnd_m1000_vv_m->Draw();
  
  cur_saveas = save_loc+"h_m1000_vv_m.pdf";
  tc_m1000_vv_m->SaveAs(cur_saveas.c_str());





  // m1000_lep_pt
  TCanvas* tc_m1000_lep_pt = new TCanvas("tc_m1000_lep_pt","tc_m1000_lep_pt",0,0,1920,1200);
  tc_m1000_lep_pt->cd();

  TH1F* h_rsg_m1000_lep_pt = (TH1F*) rsg_m1000_file->Get("h_lep_pt");
  h_rsg_m1000_lep_pt->Scale(1./h_rsg_m1000_lep_pt->Integral());
  
  TH1F* h_kkg_m1000_lep_pt = (TH1F*) kkg_m1000_file->Get("h_lep_pt");
  h_kkg_m1000_lep_pt->Scale(1./h_kkg_m1000_lep_pt->Integral());
  
  TH1F* h_wprime_m1000_lep_pt = (TH1F*) wprime_m1000_file->Get("h_lep_pt");
  h_wprime_m1000_lep_pt->Scale(1./h_wprime_m1000_lep_pt->Integral());

  h_rsg_m1000_lep_pt->GetXaxis()->SetTitle("lepton pt [GeV]");
  h_rsg_m1000_lep_pt->SetLineColor(kRed);
  h_rsg_m1000_lep_pt->Draw();

  h_kkg_m1000_lep_pt->SetLineColor(kGreen);
  h_kkg_m1000_lep_pt->Draw("same");

  h_wprime_m1000_lep_pt->SetLineColor(kBlue);
  h_wprime_m1000_lep_pt->Draw("same");

  tc_m1000_lep_pt->SetLogy();
  tc_m1000_lep_pt->Update();

  TLegend* lgnd_m1000_lep_pt = new TLegend(0.80,0.75,0.9,0.90);
  lgnd_m1000_lep_pt->SetFillColor(0);
  lgnd_m1000_lep_pt->SetTextSize(0.05);
  lgnd_m1000_lep_pt->SetBorderSize(0);
  lgnd_m1000_lep_pt->AddEntry(h_rsg_m1000_lep_pt,"G*","L");
  lgnd_m1000_lep_pt->AddEntry(h_kkg_m1000_lep_pt,"G_{KK}","L");
  lgnd_m1000_lep_pt->AddEntry(h_wprime_m1000_lep_pt,"W'","L");
  lgnd_m1000_lep_pt->Draw();
  

  cur_saveas = save_loc+"h_m1000_lep_pt.pdf";
  tc_m1000_lep_pt->SaveAs(cur_saveas.c_str());


  // m1000_lep_eta
  TCanvas* tc_m1000_lep_eta = new TCanvas("tc_m1000_lep_eta","tc_m1000_lep_eta",0,0,1920,1200);
  tc_m1000_lep_eta->cd();

  TH1F* h_rsg_m1000_lep_eta = (TH1F*) rsg_m1000_file->Get("h_lep_eta");
  h_rsg_m1000_lep_eta->Scale(1./h_rsg_m1000_lep_eta->Integral());
  
  TH1F* h_kkg_m1000_lep_eta = (TH1F*) kkg_m1000_file->Get("h_lep_eta");
  h_kkg_m1000_lep_eta->Scale(1./h_kkg_m1000_lep_eta->Integral());
  
  TH1F* h_wprime_m1000_lep_eta = (TH1F*) wprime_m1000_file->Get("h_lep_eta");
  h_wprime_m1000_lep_eta->Scale(1./h_wprime_m1000_lep_eta->Integral());
  
  h_rsg_m1000_lep_eta->GetXaxis()->SetTitle("lepton #eta");
  h_rsg_m1000_lep_eta->SetLineColor(kRed);
  h_rsg_m1000_lep_eta->Draw();
  
  h_wprime_m1000_lep_eta->SetLineColor(kBlue);
  h_wprime_m1000_lep_eta->Draw("same");

  h_kkg_m1000_lep_eta->SetLineColor(kGreen);
  h_kkg_m1000_lep_eta->Draw("same");

  tc_m1000_lep_eta->SetLogy();
  tc_m1000_lep_eta->Update();

  TLegend* lgnd_m1000_lep_eta = new TLegend(0.80,0.75,0.9,0.90);
  lgnd_m1000_lep_eta->SetFillColor(0);
  lgnd_m1000_lep_eta->SetTextSize(0.05);
  lgnd_m1000_lep_eta->SetBorderSize(0);
  lgnd_m1000_lep_eta->AddEntry(h_rsg_m1000_lep_eta,"G*","L");
  lgnd_m1000_lep_eta->AddEntry(h_kkg_m1000_lep_eta,"G_{KK}","L");
  lgnd_m1000_lep_eta->AddEntry(h_wprime_m1000_lep_eta,"W'","L");
  lgnd_m1000_lep_eta->Draw();
  
  cur_saveas = save_loc+"h_m1000_lep_eta.pdf";
  tc_m1000_lep_eta->SaveAs(cur_saveas.c_str());


  // m1000_nu_pt
  TCanvas* tc_m1000_nu_pt = new TCanvas("tc_m1000_nu_pt","tc_m1000_nu_pt",0,0,1920,1200);
  tc_m1000_nu_pt->cd();

  TH1F* h_rsg_m1000_nu_pt = (TH1F*) rsg_m1000_file->Get("h_nu_pt");
  h_rsg_m1000_nu_pt->Scale(1./h_rsg_m1000_nu_pt->Integral());

  TH1F* h_kkg_m1000_nu_pt = (TH1F*) kkg_m1000_file->Get("h_nu_pt");
  h_kkg_m1000_nu_pt->Scale(1./h_kkg_m1000_nu_pt->Integral());
  
  TH1F* h_wprime_m1000_nu_pt = (TH1F*) wprime_m1000_file->Get("h_nu_pt");
  h_wprime_m1000_nu_pt->Scale(1./h_wprime_m1000_nu_pt->Integral());

  h_rsg_m1000_nu_pt->GetXaxis()->SetTitle("lepton pt [GeV]");
  h_rsg_m1000_nu_pt->SetLineColor(kRed);
  h_rsg_m1000_nu_pt->Draw();

  h_wprime_m1000_nu_pt->SetLineColor(kBlue);
  h_wprime_m1000_nu_pt->Draw("same");

  h_kkg_m1000_nu_pt->SetLineColor(kGreen);
  h_kkg_m1000_nu_pt->Draw("same");

  tc_m1000_nu_pt->SetLogy();
  tc_m1000_nu_pt->Update();

  TLegend* lgnd_m1000_nu_pt = new TLegend(0.80,0.75,0.9,0.90);
  lgnd_m1000_nu_pt->SetFillColor(0);
  lgnd_m1000_nu_pt->SetTextSize(0.05);
  lgnd_m1000_nu_pt->SetBorderSize(0);
  lgnd_m1000_nu_pt->AddEntry(h_rsg_m1000_nu_pt,"G*","L");
  lgnd_m1000_nu_pt->AddEntry(h_kkg_m1000_nu_pt,"G_{KK}","L");
  lgnd_m1000_nu_pt->AddEntry(h_wprime_m1000_nu_pt,"W'","L");
  lgnd_m1000_nu_pt->Draw();
  

  cur_saveas = save_loc+"h_m1000_nu_pt.pdf";
  tc_m1000_nu_pt->SaveAs(cur_saveas.c_str());



  // m1000_qrk_pt
  TCanvas* tc_m1000_qrk_pt = new TCanvas("tc_m1000_qrk_pt","tc_m1000_qrk_pt",0,0,1920,1200);
  tc_m1000_qrk_pt->cd();

  TH1F* h_rsg_m1000_qrk_pt = (TH1F*) rsg_m1000_file->Get("h_qrk_pt");
  h_rsg_m1000_qrk_pt->Scale(1./h_rsg_m1000_qrk_pt->Integral());
  
  TH1F* h_kkg_m1000_qrk_pt = (TH1F*) kkg_m1000_file->Get("h_qrk_pt");
  h_kkg_m1000_qrk_pt->Scale(1./h_kkg_m1000_qrk_pt->Integral());
  
  TH1F* h_wprime_m1000_qrk_pt = (TH1F*) wprime_m1000_file->Get("h_qrk_pt");
  h_wprime_m1000_qrk_pt->Scale(1./h_wprime_m1000_qrk_pt->Integral());
  
  h_rsg_m1000_qrk_pt->GetXaxis()->SetTitle("quark pt [GeV]");
  h_rsg_m1000_qrk_pt->SetLineColor(kRed);
  h_rsg_m1000_qrk_pt->Draw();

  h_wprime_m1000_qrk_pt->SetLineColor(kBlue);
  h_wprime_m1000_qrk_pt->Draw("same");

  h_kkg_m1000_qrk_pt->SetLineColor(kGreen);
  h_kkg_m1000_qrk_pt->Draw("same");

  tc_m1000_qrk_pt->SetLogy();
  tc_m1000_qrk_pt->Update();

  TLegend* lgnd_m1000_qrk_pt = new TLegend(0.80,0.75,0.9,0.90);
  lgnd_m1000_qrk_pt->SetFillColor(0);
  lgnd_m1000_qrk_pt->SetTextSize(0.05);
  lgnd_m1000_qrk_pt->SetBorderSize(0);
  lgnd_m1000_qrk_pt->AddEntry(h_rsg_m1000_qrk_pt,"G*","L");
  lgnd_m1000_qrk_pt->AddEntry(h_kkg_m1000_qrk_pt,"G_{KK}","L");
  lgnd_m1000_qrk_pt->AddEntry(h_wprime_m1000_qrk_pt,"W'","L");
  lgnd_m1000_qrk_pt->Draw();
  

  cur_saveas = save_loc+"h_m1000_qrk_pt.pdf";
  tc_m1000_qrk_pt->SaveAs(cur_saveas.c_str());


  // m1000_qrk_eta
  TCanvas* tc_m1000_qrk_eta = new TCanvas("tc_m1000_qrk_eta","tc_m1000_qrk_eta",0,0,1920,1200);
  tc_m1000_qrk_eta->cd();

  TH1F* h_rsg_m1000_qrk_eta = (TH1F*) rsg_m1000_file->Get("h_qrk_eta");
  h_rsg_m1000_qrk_eta->Scale(1./h_rsg_m1000_qrk_eta->Integral());
  
  TH1F* h_kkg_m1000_qrk_eta = (TH1F*) kkg_m1000_file->Get("h_qrk_eta");
  h_kkg_m1000_qrk_eta->Scale(1./h_kkg_m1000_qrk_eta->Integral());
  
  TH1F* h_wprime_m1000_qrk_eta = (TH1F*) wprime_m1000_file->Get("h_qrk_eta");
  h_wprime_m1000_qrk_eta->Scale(1./h_wprime_m1000_qrk_eta->Integral());

  h_rsg_m1000_qrk_eta->GetXaxis()->SetTitle("quark #eta");
  h_rsg_m1000_qrk_eta->SetLineColor(kRed);
  h_rsg_m1000_qrk_eta->Draw();
  
  h_wprime_m1000_qrk_eta->SetLineColor(kBlue);
  h_wprime_m1000_qrk_eta->Draw("same");

  h_kkg_m1000_qrk_eta->SetLineColor(kGreen);
  h_kkg_m1000_qrk_eta->Draw("same");

  tc_m1000_qrk_eta->SetLogy();
  tc_m1000_qrk_eta->Update();

  TLegend* lgnd_m1000_qrk_eta = new TLegend(0.80,0.75,0.9,0.90);
  lgnd_m1000_qrk_eta->SetFillColor(0);
  lgnd_m1000_qrk_eta->SetTextSize(0.05);
  lgnd_m1000_qrk_eta->SetBorderSize(0);
  lgnd_m1000_qrk_eta->AddEntry(h_rsg_m1000_qrk_eta,"G*","L");
  lgnd_m1000_qrk_eta->AddEntry(h_kkg_m1000_qrk_eta,"G_{KK}","L");
  lgnd_m1000_qrk_eta->AddEntry(h_wprime_m1000_qrk_eta,"W'","L");
  lgnd_m1000_qrk_eta->Draw();
  
  cur_saveas = save_loc+"h_m1000_qrk_eta.pdf";
  tc_m1000_qrk_eta->SaveAs(cur_saveas.c_str());


  // m1000_jet_pt
  TCanvas* tc_m1000_jet_pt = new TCanvas("tc_m1000_jet_pt","tc_m1000_jet_pt",0,0,1920,1200);
  tc_m1000_jet_pt->cd();

  TH1F* h_rsg_m1000_jet_pt = (TH1F*) rsg_m1000_file->Get("h_jet_pt");
  h_rsg_m1000_jet_pt->Scale(1./h_rsg_m1000_jet_pt->Integral());
  
  TH1F* h_kkg_m1000_jet_pt = (TH1F*) kkg_m1000_file->Get("h_jet_pt");
  h_kkg_m1000_jet_pt->Scale(1./h_kkg_m1000_jet_pt->Integral());
  
  TH1F* h_wprime_m1000_jet_pt = (TH1F*) wprime_m1000_file->Get("h_jet_pt");
  h_wprime_m1000_jet_pt->Scale(1./h_wprime_m1000_jet_pt->Integral());
  
  h_rsg_m1000_jet_pt->GetXaxis()->SetTitle("jet pt [GeV]");
  h_rsg_m1000_jet_pt->SetLineColor(kRed);
  h_rsg_m1000_jet_pt->Draw();

  h_wprime_m1000_jet_pt->SetLineColor(kBlue);
  h_wprime_m1000_jet_pt->Draw("same");

  h_kkg_m1000_jet_pt->SetLineColor(kGreen);
  h_kkg_m1000_jet_pt->Draw("same");

  tc_m1000_jet_pt->SetLogy();
  tc_m1000_jet_pt->Update();

  TLegend* lgnd_m1000_jet_pt = new TLegend(0.80,0.75,0.9,0.90);
  lgnd_m1000_jet_pt->SetFillColor(0);
  lgnd_m1000_jet_pt->SetTextSize(0.05);
  lgnd_m1000_jet_pt->SetBorderSize(0);
  lgnd_m1000_jet_pt->AddEntry(h_rsg_m1000_jet_pt,"G*","L");
  lgnd_m1000_jet_pt->AddEntry(h_kkg_m1000_jet_pt,"G_{KK}","L");
  lgnd_m1000_jet_pt->AddEntry(h_wprime_m1000_jet_pt,"W'","L");
  lgnd_m1000_jet_pt->Draw();
  

  cur_saveas = save_loc+"h_m1000_jet_pt.pdf";
  tc_m1000_jet_pt->SaveAs(cur_saveas.c_str());


  // m1000_jet_eta
  TCanvas* tc_m1000_jet_eta = new TCanvas("tc_m1000_jet_eta","tc_m1000_jet_eta",0,0,1920,1200);
  tc_m1000_jet_eta->cd();

  TH1F* h_rsg_m1000_jet_eta = (TH1F*) rsg_m1000_file->Get("h_jet_eta");
  h_rsg_m1000_jet_eta->Scale(1./h_rsg_m1000_jet_eta->Integral());
  
  TH1F* h_kkg_m1000_jet_eta = (TH1F*) kkg_m1000_file->Get("h_jet_eta");
  h_kkg_m1000_jet_eta->Scale(1./h_kkg_m1000_jet_eta->Integral());
  
  TH1F* h_wprime_m1000_jet_eta = (TH1F*) wprime_m1000_file->Get("h_jet_eta");
  h_wprime_m1000_jet_eta->Scale(1./h_wprime_m1000_jet_eta->Integral());

  h_rsg_m1000_jet_eta->GetXaxis()->SetTitle("jet #eta");
  h_rsg_m1000_jet_eta->SetLineColor(kRed);
  h_rsg_m1000_jet_eta->Draw();
  
  h_wprime_m1000_jet_eta->SetLineColor(kBlue);
  h_wprime_m1000_jet_eta->Draw("same");

  h_kkg_m1000_jet_eta->SetLineColor(kGreen);
  h_kkg_m1000_jet_eta->Draw("same");

  tc_m1000_jet_eta->SetLogy();
  tc_m1000_jet_eta->Update();

  TLegend* lgnd_m1000_jet_eta = new TLegend(0.80,0.75,0.9,0.90);
  lgnd_m1000_jet_eta->SetFillColor(0);
  lgnd_m1000_jet_eta->SetTextSize(0.05);
  lgnd_m1000_jet_eta->SetBorderSize(0);
  lgnd_m1000_jet_eta->AddEntry(h_rsg_m1000_jet_eta,"G*","L");
  lgnd_m1000_jet_eta->AddEntry(h_kkg_m1000_jet_eta,"G_{KK}","L");
  lgnd_m1000_jet_eta->AddEntry(h_wprime_m1000_jet_eta,"W'","L");
  lgnd_m1000_jet_eta->Draw();
  
  cur_saveas = save_loc+"h_m1000_jet_eta.pdf";
  tc_m1000_jet_eta->SaveAs(cur_saveas.c_str());



  // m1000_jet_n
  TCanvas* tc_m1000_jet_n = new TCanvas("tc_m1000_jet_n","tc_m1000_jet_n",0,0,1920,1200);
  tc_m1000_jet_n->cd();

  TH1F* h_rsg_m1000_jet_n = (TH1F*) rsg_m1000_file->Get("h_jet_n");
  h_rsg_m1000_jet_n->Scale(1./h_rsg_m1000_jet_n->Integral());
  
  TH1F* h_kkg_m1000_jet_n = (TH1F*) kkg_m1000_file->Get("h_jet_n");
  h_kkg_m1000_jet_n->Scale(1./h_kkg_m1000_jet_n->Integral());
  
  TH1F* h_wprime_m1000_jet_n = (TH1F*) wprime_m1000_file->Get("h_jet_n");
  h_wprime_m1000_jet_n->Scale(1./h_wprime_m1000_jet_n->Integral());

  h_rsg_m1000_jet_n->GetXaxis()->SetTitle("jet n");
  h_rsg_m1000_jet_n->SetLineColor(kRed);
  h_rsg_m1000_jet_n->Draw();
  
  h_wprime_m1000_jet_n->SetLineColor(kBlue);
  h_wprime_m1000_jet_n->Draw("same");

  h_kkg_m1000_jet_n->SetLineColor(kGreen);
  h_kkg_m1000_jet_n->Draw("same");

  tc_m1000_jet_n->SetLogy();
  tc_m1000_jet_n->Update();

  TLegend* lgnd_m1000_jet_n = new TLegend(0.80,0.75,0.9,0.90);
  lgnd_m1000_jet_n->SetFillColor(0);
  lgnd_m1000_jet_n->SetTextSize(0.05);
  lgnd_m1000_jet_n->SetBorderSize(0);
  lgnd_m1000_jet_n->AddEntry(h_rsg_m1000_jet_n,"G*","L");
  lgnd_m1000_jet_n->AddEntry(h_kkg_m1000_jet_n,"G_{KK}","L");
  lgnd_m1000_jet_n->AddEntry(h_wprime_m1000_jet_n,"W'","L");
  lgnd_m1000_jet_n->Draw();
  
  cur_saveas = save_loc+"h_m1000_jet_n.pdf";
  tc_m1000_jet_n->SaveAs(cur_saveas.c_str());


  // m1000_cos_theta_star
  TCanvas* tc_m1000_cos_theta_star = new TCanvas("tc_m1000_cos_theta_star","tc_m1000_cos_theta_star",0,0,1920,1200);
  tc_m1000_cos_theta_star->cd();

  TH1F* h_rsg_m1000_cos_theta_star = (TH1F*) rsg_m1000_file->Get("h_cos_theta_star");
  h_rsg_m1000_cos_theta_star->Scale(1./h_rsg_m1000_cos_theta_star->Integral());
  
  TH1F* h_kkg_m1000_cos_theta_star = (TH1F*) kkg_m1000_file->Get("h_cos_theta_star");
  h_kkg_m1000_cos_theta_star->Scale(1./h_kkg_m1000_cos_theta_star->Integral());
  
  TH1F* h_wprime_m1000_cos_theta_star = (TH1F*) wprime_m1000_file->Get("h_cos_theta_star");
  h_wprime_m1000_cos_theta_star->Scale(1./h_wprime_m1000_cos_theta_star->Integral());

  h_kkg_m1000_cos_theta_star->GetYaxis()->SetRangeUser(0,0.1);
  h_kkg_m1000_cos_theta_star->GetXaxis()->SetTitle("cos(#theta*)");
  h_kkg_m1000_cos_theta_star->SetLineColor(kGreen);
  h_kkg_m1000_cos_theta_star->Draw();
  
  h_wprime_m1000_cos_theta_star->SetLineColor(kBlue);
  h_wprime_m1000_cos_theta_star->Draw("same");

  h_rsg_m1000_cos_theta_star->SetLineColor(kRed);
  h_rsg_m1000_cos_theta_star->Draw("same");

  //tc_m1000_cos_theta_star->SetLogy();
  tc_m1000_cos_theta_star->Update();

  TLegend* lgnd_m1000_cos_theta_star = new TLegend(0.80,0.75,0.9,0.90);
  lgnd_m1000_cos_theta_star->SetFillColor(0);
  lgnd_m1000_cos_theta_star->SetTextSize(0.05);
  lgnd_m1000_cos_theta_star->SetBorderSize(0);
  lgnd_m1000_cos_theta_star->AddEntry(h_rsg_m1000_cos_theta_star,"G*","L");
  lgnd_m1000_cos_theta_star->AddEntry(h_kkg_m1000_cos_theta_star,"G_{KK}","L");
  lgnd_m1000_cos_theta_star->AddEntry(h_wprime_m1000_cos_theta_star,"W'","L");
  lgnd_m1000_cos_theta_star->Draw();
  
  cur_saveas = save_loc+"h_m1000_cos_theta_star.pdf";
  tc_m1000_cos_theta_star->SaveAs(cur_saveas.c_str());


  // m500_v_pt
  TCanvas* tc_m500_v_pt = new TCanvas("tc_m500_v_pt","tc_m500_v_pt",0,0,1920,1200);
  tc_m500_v_pt->cd();

  TH1F* h_rsg_m500_v_pt = (TH1F*) rsg_m500_file->Get("h_v_pt");
  h_rsg_m500_v_pt->Scale(1./h_rsg_m500_v_pt->Integral());
  
  TH1F* h_kkg_m500_v_pt = (TH1F*) kkg_m500_file->Get("h_v_pt");
  h_kkg_m500_v_pt->Scale(1./h_kkg_m500_v_pt->Integral());
  
  TH1F* h_wprime_m500_v_pt = (TH1F*) wprime_m500_file->Get("h_v_pt");
  h_wprime_m500_v_pt->Scale(1./h_wprime_m500_v_pt->Integral());

  h_rsg_m500_v_pt->GetXaxis()->SetTitle("W/Z boson pt [GeV]");
  h_rsg_m500_v_pt->SetLineColor(kRed);
  h_rsg_m500_v_pt->Draw();

  h_wprime_m500_v_pt->SetLineColor(kBlue);
  h_wprime_m500_v_pt->Draw("same");

  h_kkg_m500_v_pt->SetLineColor(kGreen);
  h_kkg_m500_v_pt->Draw("same");

  tc_m500_v_pt->SetLogy();
  tc_m500_v_pt->Update();

  TLegend* lgnd_m500_v_pt = new TLegend(0.80,0.75,0.9,0.90);
  lgnd_m500_v_pt->SetFillColor(0);
  lgnd_m500_v_pt->SetTextSize(0.05);
  lgnd_m500_v_pt->SetBorderSize(0);
  lgnd_m500_v_pt->AddEntry(h_rsg_m500_v_pt,"G*","L");
  lgnd_m500_v_pt->AddEntry(h_kkg_m500_v_pt,"G_{kk}","L");
  lgnd_m500_v_pt->AddEntry(h_wprime_m500_v_pt,"W'","L");
  lgnd_m500_v_pt->Draw();
  

  cur_saveas = save_loc+"h_m500_v_pt.pdf";
  tc_m500_v_pt->SaveAs(cur_saveas.c_str());


  // m500_v_eta
  TCanvas* tc_m500_v_eta = new TCanvas("tc_m500_v_eta","tc_m500_v_eta",0,0,1920,1200);
  tc_m500_v_eta->cd();

  TH1F* h_rsg_m500_v_eta = (TH1F*) rsg_m500_file->Get("h_v_eta");
  h_rsg_m500_v_eta->Scale(1./h_rsg_m500_v_eta->Integral());
  
  TH1F* h_kkg_m500_v_eta = (TH1F*) kkg_m500_file->Get("h_v_eta");
  h_kkg_m500_v_eta->Scale(1./h_kkg_m500_v_eta->Integral());
  
  TH1F* h_wprime_m500_v_eta = (TH1F*) wprime_m500_file->Get("h_v_eta");
  h_wprime_m500_v_eta->Scale(1./h_wprime_m500_v_eta->Integral());
  
  h_rsg_m500_v_eta->GetXaxis()->SetTitle("W/Z boson #eta");
  h_rsg_m500_v_eta->SetLineColor(kRed);
  h_rsg_m500_v_eta->Draw();
  
  h_wprime_m500_v_eta->SetLineColor(kBlue);
  h_wprime_m500_v_eta->Draw("same");

  h_kkg_m500_v_eta->SetLineColor(kGreen);
  h_kkg_m500_v_eta->Draw("same");

  tc_m500_v_eta->SetLogy();
  tc_m500_v_eta->Update();

  TLegend* lgnd_m500_v_eta = new TLegend(0.80,0.75,0.9,0.90);
  lgnd_m500_v_eta->SetFillColor(0);
  lgnd_m500_v_eta->SetTextSize(0.05);
  lgnd_m500_v_eta->SetBorderSize(0);
  lgnd_m500_v_eta->AddEntry(h_rsg_m500_v_eta,"G*","L");
  lgnd_m500_v_eta->AddEntry(h_kkg_m500_v_eta,"G_{kk}","L");
  lgnd_m500_v_eta->AddEntry(h_wprime_m500_v_eta,"W'","L");
  lgnd_m500_v_eta->Draw();
  
  cur_saveas = save_loc+"h_m500_v_eta.pdf";
  tc_m500_v_eta->SaveAs(cur_saveas.c_str());


  // m500_vv_pt
  TCanvas* tc_m500_vv_pt = new TCanvas("tc_m500_vv_pt","tc_m500_vv_pt",0,0,1920,1200);
  tc_m500_vv_pt->cd();

  TH1F* h_rsg_m500_vv_pt = (TH1F*) rsg_m500_file->Get("h_vv_pt");
  h_rsg_m500_vv_pt->Scale(1./h_rsg_m500_vv_pt->Integral());
  
  TH1F* h_kkg_m500_vv_pt = (TH1F*) kkg_m500_file->Get("h_vv_pt");
  h_kkg_m500_vv_pt->Scale(1./h_kkg_m500_vv_pt->Integral());
  
  TH1F* h_wprime_m500_vv_pt = (TH1F*) wprime_m500_file->Get("h_vv_pt");
  h_wprime_m500_vv_pt->Scale(1./h_wprime_m500_vv_pt->Integral());
  
  h_rsg_m500_vv_pt->GetXaxis()->SetTitle("G*/W' pt [GeV]");
  h_rsg_m500_vv_pt->SetLineColor(kRed);
  h_rsg_m500_vv_pt->Draw();

  h_kkg_m500_vv_pt->SetLineColor(kGreen);
  h_kkg_m500_vv_pt->Draw("same");

  h_wprime_m500_vv_pt->SetLineColor(kBlue);
  h_wprime_m500_vv_pt->Draw("same");

  tc_m500_vv_pt->SetLogy();
  tc_m500_vv_pt->Update();

  TLegend* lgnd_m500_vv_pt = new TLegend(0.80,0.75,0.9,0.90);
  lgnd_m500_vv_pt->SetFillColor(0);
  lgnd_m500_vv_pt->SetTextSize(0.05);
  lgnd_m500_vv_pt->SetBorderSize(0);
  lgnd_m500_vv_pt->AddEntry(h_rsg_m500_vv_pt,"G*","L");
  lgnd_m500_vv_pt->AddEntry(h_kkg_m500_vv_pt,"G_{KK}","L");
  lgnd_m500_vv_pt->AddEntry(h_wprime_m500_vv_pt,"W'","L");
  lgnd_m500_vv_pt->Draw();
  

  cur_saveas = save_loc+"h_m500_vv_pt.pdf";
  tc_m500_vv_pt->SaveAs(cur_saveas.c_str());


  // m500_vv_eta
  TCanvas* tc_m500_vv_eta = new TCanvas("tc_m500_vv_eta","tc_m500_vv_eta",0,0,1920,1200);
  tc_m500_vv_eta->cd();

  TH1F* h_rsg_m500_vv_eta = (TH1F*) rsg_m500_file->Get("h_vv_eta");
  h_rsg_m500_vv_eta->Scale(1./h_rsg_m500_vv_eta->Integral());

  TH1F* h_kkg_m500_vv_eta = (TH1F*) kkg_m500_file->Get("h_vv_eta");
  h_kkg_m500_vv_eta->Scale(1./h_kkg_m500_vv_eta->Integral());
  
  TH1F* h_wprime_m500_vv_eta = (TH1F*) wprime_m500_file->Get("h_vv_eta");
  h_wprime_m500_vv_eta->Scale(1./h_wprime_m500_vv_eta->Integral());

  h_rsg_m500_vv_eta->GetXaxis()->SetTitle("G*/W' #eta");
  h_rsg_m500_vv_eta->SetLineColor(kRed);
  h_rsg_m500_vv_eta->Draw();
  
  h_wprime_m500_vv_eta->SetLineColor(kBlue);
  h_wprime_m500_vv_eta->Draw("same");

  h_kkg_m500_vv_eta->SetLineColor(kGreen);
  h_kkg_m500_vv_eta->Draw("same");

  tc_m500_vv_eta->SetLogy();
  tc_m500_vv_eta->Update();

  TLegend* lgnd_m500_vv_eta = new TLegend(0.80,0.75,0.9,0.90);
  lgnd_m500_vv_eta->SetFillColor(0);
  lgnd_m500_vv_eta->SetTextSize(0.05);
  lgnd_m500_vv_eta->SetBorderSize(0);
  lgnd_m500_vv_eta->AddEntry(h_rsg_m500_vv_eta,"G*","L");
  lgnd_m500_vv_eta->AddEntry(h_kkg_m500_vv_eta,"G_{KK}","L");
  lgnd_m500_vv_eta->AddEntry(h_wprime_m500_vv_eta,"W'","L");
  lgnd_m500_vv_eta->Draw();
  
  cur_saveas = save_loc+"h_m500_vv_eta.pdf";
  tc_m500_vv_eta->SaveAs(cur_saveas.c_str());

  // m500_vv_m
  TCanvas* tc_m500_vv_m = new TCanvas("tc_m500_vv_m","tc_m500_vv_m",0,0,1920,1200);
  tc_m500_vv_m->cd();

  TH1F* h_rsg_m500_vv_m = (TH1F*) rsg_m500_file->Get("h_vv_m");
  h_rsg_m500_vv_m->Scale(1./h_rsg_m500_vv_m->Integral());

  TH1F* h_kkg_m500_vv_m = (TH1F*) kkg_m500_file->Get("h_vv_m");
  h_kkg_m500_vv_m->Scale(1./h_kkg_m500_vv_m->Integral());
  
  TH1F* h_wprime_m500_vv_m = (TH1F*) wprime_m500_file->Get("h_vv_m");
  h_wprime_m500_vv_m->Scale(1./h_wprime_m500_vv_m->Integral());

  h_rsg_m500_vv_m->GetXaxis()->SetTitle("G*/W' #m");
  h_rsg_m500_vv_m->SetLineColor(kRed);
  h_rsg_m500_vv_m->Draw();
  
  h_wprime_m500_vv_m->SetLineColor(kBlue);
  h_wprime_m500_vv_m->Draw("same");

  h_kkg_m500_vv_m->SetLineColor(kGreen);
  h_kkg_m500_vv_m->Draw("same");

  tc_m500_vv_m->SetLogy();
  tc_m500_vv_m->Update();

  TLegend* lgnd_m500_vv_m = new TLegend(0.80,0.75,0.9,0.90);
  lgnd_m500_vv_m->SetFillColor(0);
  lgnd_m500_vv_m->SetTextSize(0.05);
  lgnd_m500_vv_m->SetBorderSize(0);
  lgnd_m500_vv_m->AddEntry(h_rsg_m500_vv_m,"G*","L");
  lgnd_m500_vv_m->AddEntry(h_kkg_m500_vv_m,"G_{KK}","L");
  lgnd_m500_vv_m->AddEntry(h_wprime_m500_vv_m,"W'","L");
  lgnd_m500_vv_m->Draw();
  
  cur_saveas = save_loc+"h_m500_vv_m.pdf";
  tc_m500_vv_m->SaveAs(cur_saveas.c_str());





  // m500_lep_pt
  TCanvas* tc_m500_lep_pt = new TCanvas("tc_m500_lep_pt","tc_m500_lep_pt",0,0,1920,1200);
  tc_m500_lep_pt->cd();

  TH1F* h_rsg_m500_lep_pt = (TH1F*) rsg_m500_file->Get("h_lep_pt");
  h_rsg_m500_lep_pt->Scale(1./h_rsg_m500_lep_pt->Integral());
  
  TH1F* h_kkg_m500_lep_pt = (TH1F*) kkg_m500_file->Get("h_lep_pt");
  h_kkg_m500_lep_pt->Scale(1./h_kkg_m500_lep_pt->Integral());
  
  TH1F* h_wprime_m500_lep_pt = (TH1F*) wprime_m500_file->Get("h_lep_pt");
  h_wprime_m500_lep_pt->Scale(1./h_wprime_m500_lep_pt->Integral());

  h_rsg_m500_lep_pt->GetXaxis()->SetTitle("lepton pt [GeV]");
  h_rsg_m500_lep_pt->SetLineColor(kRed);
  h_rsg_m500_lep_pt->Draw();

  h_kkg_m500_lep_pt->SetLineColor(kGreen);
  h_kkg_m500_lep_pt->Draw("same");

  h_wprime_m500_lep_pt->SetLineColor(kBlue);
  h_wprime_m500_lep_pt->Draw("same");

  tc_m500_lep_pt->SetLogy();
  tc_m500_lep_pt->Update();

  TLegend* lgnd_m500_lep_pt = new TLegend(0.80,0.75,0.9,0.90);
  lgnd_m500_lep_pt->SetFillColor(0);
  lgnd_m500_lep_pt->SetTextSize(0.05);
  lgnd_m500_lep_pt->SetBorderSize(0);
  lgnd_m500_lep_pt->AddEntry(h_rsg_m500_lep_pt,"G*","L");
  lgnd_m500_lep_pt->AddEntry(h_kkg_m500_lep_pt,"G_{KK}","L");
  lgnd_m500_lep_pt->AddEntry(h_wprime_m500_lep_pt,"W'","L");
  lgnd_m500_lep_pt->Draw();
  

  cur_saveas = save_loc+"h_m500_lep_pt.pdf";
  tc_m500_lep_pt->SaveAs(cur_saveas.c_str());


  // m500_lep_eta
  TCanvas* tc_m500_lep_eta = new TCanvas("tc_m500_lep_eta","tc_m500_lep_eta",0,0,1920,1200);
  tc_m500_lep_eta->cd();

  TH1F* h_rsg_m500_lep_eta = (TH1F*) rsg_m500_file->Get("h_lep_eta");
  h_rsg_m500_lep_eta->Scale(1./h_rsg_m500_lep_eta->Integral());
  
  TH1F* h_kkg_m500_lep_eta = (TH1F*) kkg_m500_file->Get("h_lep_eta");
  h_kkg_m500_lep_eta->Scale(1./h_kkg_m500_lep_eta->Integral());
  
  TH1F* h_wprime_m500_lep_eta = (TH1F*) wprime_m500_file->Get("h_lep_eta");
  h_wprime_m500_lep_eta->Scale(1./h_wprime_m500_lep_eta->Integral());
  
  h_rsg_m500_lep_eta->GetXaxis()->SetTitle("lepton #eta");
  h_rsg_m500_lep_eta->SetLineColor(kRed);
  h_rsg_m500_lep_eta->Draw();
  
  h_wprime_m500_lep_eta->SetLineColor(kBlue);
  h_wprime_m500_lep_eta->Draw("same");

  h_kkg_m500_lep_eta->SetLineColor(kGreen);
  h_kkg_m500_lep_eta->Draw("same");

  tc_m500_lep_eta->SetLogy();
  tc_m500_lep_eta->Update();

  TLegend* lgnd_m500_lep_eta = new TLegend(0.80,0.75,0.9,0.90);
  lgnd_m500_lep_eta->SetFillColor(0);
  lgnd_m500_lep_eta->SetTextSize(0.05);
  lgnd_m500_lep_eta->SetBorderSize(0);
  lgnd_m500_lep_eta->AddEntry(h_rsg_m500_lep_eta,"G*","L");
  lgnd_m500_lep_eta->AddEntry(h_kkg_m500_lep_eta,"G_{KK}","L");
  lgnd_m500_lep_eta->AddEntry(h_wprime_m500_lep_eta,"W'","L");
  lgnd_m500_lep_eta->Draw();
  
  cur_saveas = save_loc+"h_m500_lep_eta.pdf";
  tc_m500_lep_eta->SaveAs(cur_saveas.c_str());


  // m500_nu_pt
  TCanvas* tc_m500_nu_pt = new TCanvas("tc_m500_nu_pt","tc_m500_nu_pt",0,0,1920,1200);
  tc_m500_nu_pt->cd();

  TH1F* h_rsg_m500_nu_pt = (TH1F*) rsg_m500_file->Get("h_nu_pt");
  h_rsg_m500_nu_pt->Scale(1./h_rsg_m500_nu_pt->Integral());

  TH1F* h_kkg_m500_nu_pt = (TH1F*) kkg_m500_file->Get("h_nu_pt");
  h_kkg_m500_nu_pt->Scale(1./h_kkg_m500_nu_pt->Integral());
  
  TH1F* h_wprime_m500_nu_pt = (TH1F*) wprime_m500_file->Get("h_nu_pt");
  h_wprime_m500_nu_pt->Scale(1./h_wprime_m500_nu_pt->Integral());

  h_rsg_m500_nu_pt->GetXaxis()->SetTitle("lepton pt [GeV]");
  h_rsg_m500_nu_pt->SetLineColor(kRed);
  h_rsg_m500_nu_pt->Draw();

  h_wprime_m500_nu_pt->SetLineColor(kBlue);
  h_wprime_m500_nu_pt->Draw("same");

  h_kkg_m500_nu_pt->SetLineColor(kGreen);
  h_kkg_m500_nu_pt->Draw("same");

  tc_m500_nu_pt->SetLogy();
  tc_m500_nu_pt->Update();

  TLegend* lgnd_m500_nu_pt = new TLegend(0.80,0.75,0.9,0.90);
  lgnd_m500_nu_pt->SetFillColor(0);
  lgnd_m500_nu_pt->SetTextSize(0.05);
  lgnd_m500_nu_pt->SetBorderSize(0);
  lgnd_m500_nu_pt->AddEntry(h_rsg_m500_nu_pt,"G*","L");
  lgnd_m500_nu_pt->AddEntry(h_kkg_m500_nu_pt,"G_{KK}","L");
  lgnd_m500_nu_pt->AddEntry(h_wprime_m500_nu_pt,"W'","L");
  lgnd_m500_nu_pt->Draw();
  

  cur_saveas = save_loc+"h_m500_nu_pt.pdf";
  tc_m500_nu_pt->SaveAs(cur_saveas.c_str());



  // m500_qrk_pt
  TCanvas* tc_m500_qrk_pt = new TCanvas("tc_m500_qrk_pt","tc_m500_qrk_pt",0,0,1920,1200);
  tc_m500_qrk_pt->cd();

  TH1F* h_rsg_m500_qrk_pt = (TH1F*) rsg_m500_file->Get("h_qrk_pt");
  h_rsg_m500_qrk_pt->Scale(1./h_rsg_m500_qrk_pt->Integral());
  
  TH1F* h_kkg_m500_qrk_pt = (TH1F*) kkg_m500_file->Get("h_qrk_pt");
  h_kkg_m500_qrk_pt->Scale(1./h_kkg_m500_qrk_pt->Integral());
  
  TH1F* h_wprime_m500_qrk_pt = (TH1F*) wprime_m500_file->Get("h_qrk_pt");
  h_wprime_m500_qrk_pt->Scale(1./h_wprime_m500_qrk_pt->Integral());
  
  h_rsg_m500_qrk_pt->GetXaxis()->SetTitle("quark pt [GeV]");
  h_rsg_m500_qrk_pt->SetLineColor(kRed);
  h_rsg_m500_qrk_pt->Draw();

  h_wprime_m500_qrk_pt->SetLineColor(kBlue);
  h_wprime_m500_qrk_pt->Draw("same");

  h_kkg_m500_qrk_pt->SetLineColor(kGreen);
  h_kkg_m500_qrk_pt->Draw("same");

  tc_m500_qrk_pt->SetLogy();
  tc_m500_qrk_pt->Update();

  TLegend* lgnd_m500_qrk_pt = new TLegend(0.80,0.75,0.9,0.90);
  lgnd_m500_qrk_pt->SetFillColor(0);
  lgnd_m500_qrk_pt->SetTextSize(0.05);
  lgnd_m500_qrk_pt->SetBorderSize(0);
  lgnd_m500_qrk_pt->AddEntry(h_rsg_m500_qrk_pt,"G*","L");
  lgnd_m500_qrk_pt->AddEntry(h_kkg_m500_qrk_pt,"G_{KK}","L");
  lgnd_m500_qrk_pt->AddEntry(h_wprime_m500_qrk_pt,"W'","L");
  lgnd_m500_qrk_pt->Draw();
  

  cur_saveas = save_loc+"h_m500_qrk_pt.pdf";
  tc_m500_qrk_pt->SaveAs(cur_saveas.c_str());


  // m500_qrk_eta
  TCanvas* tc_m500_qrk_eta = new TCanvas("tc_m500_qrk_eta","tc_m500_qrk_eta",0,0,1920,1200);
  tc_m500_qrk_eta->cd();

  TH1F* h_rsg_m500_qrk_eta = (TH1F*) rsg_m500_file->Get("h_qrk_eta");
  h_rsg_m500_qrk_eta->Scale(1./h_rsg_m500_qrk_eta->Integral());
  
  TH1F* h_kkg_m500_qrk_eta = (TH1F*) kkg_m500_file->Get("h_qrk_eta");
  h_kkg_m500_qrk_eta->Scale(1./h_kkg_m500_qrk_eta->Integral());
  
  TH1F* h_wprime_m500_qrk_eta = (TH1F*) wprime_m500_file->Get("h_qrk_eta");
  h_wprime_m500_qrk_eta->Scale(1./h_wprime_m500_qrk_eta->Integral());

  h_rsg_m500_qrk_eta->GetXaxis()->SetTitle("quark #eta");
  h_rsg_m500_qrk_eta->SetLineColor(kRed);
  h_rsg_m500_qrk_eta->Draw();
  
  h_wprime_m500_qrk_eta->SetLineColor(kBlue);
  h_wprime_m500_qrk_eta->Draw("same");

  h_kkg_m500_qrk_eta->SetLineColor(kGreen);
  h_kkg_m500_qrk_eta->Draw("same");

  tc_m500_qrk_eta->SetLogy();
  tc_m500_qrk_eta->Update();

  TLegend* lgnd_m500_qrk_eta = new TLegend(0.80,0.75,0.9,0.90);
  lgnd_m500_qrk_eta->SetFillColor(0);
  lgnd_m500_qrk_eta->SetTextSize(0.05);
  lgnd_m500_qrk_eta->SetBorderSize(0);
  lgnd_m500_qrk_eta->AddEntry(h_rsg_m500_qrk_eta,"G*","L");
  lgnd_m500_qrk_eta->AddEntry(h_kkg_m500_qrk_eta,"G_{KK}","L");
  lgnd_m500_qrk_eta->AddEntry(h_wprime_m500_qrk_eta,"W'","L");
  lgnd_m500_qrk_eta->Draw();
  
  cur_saveas = save_loc+"h_m500_qrk_eta.pdf";
  tc_m500_qrk_eta->SaveAs(cur_saveas.c_str());

  // m500_jet_pt
  TCanvas* tc_m500_jet_pt = new TCanvas("tc_m500_jet_pt","tc_m500_jet_pt",0,0,1920,1200);
  tc_m500_jet_pt->cd();

  TH1F* h_rsg_m500_jet_pt = (TH1F*) rsg_m500_file->Get("h_jet_pt");
  h_rsg_m500_jet_pt->Scale(1./h_rsg_m500_jet_pt->Integral());
  
  TH1F* h_kkg_m500_jet_pt = (TH1F*) kkg_m500_file->Get("h_jet_pt");
  h_kkg_m500_jet_pt->Scale(1./h_kkg_m500_jet_pt->Integral());
  
  TH1F* h_wprime_m500_jet_pt = (TH1F*) wprime_m500_file->Get("h_jet_pt");
  h_wprime_m500_jet_pt->Scale(1./h_wprime_m500_jet_pt->Integral());
  
  h_rsg_m500_jet_pt->GetXaxis()->SetTitle("jet pt [GeV]");
  h_rsg_m500_jet_pt->SetLineColor(kRed);
  h_rsg_m500_jet_pt->Draw();

  h_wprime_m500_jet_pt->SetLineColor(kBlue);
  h_wprime_m500_jet_pt->Draw("same");

  h_kkg_m500_jet_pt->SetLineColor(kGreen);
  h_kkg_m500_jet_pt->Draw("same");

  tc_m500_jet_pt->SetLogy();
  tc_m500_jet_pt->Update();

  TLegend* lgnd_m500_jet_pt = new TLegend(0.80,0.75,0.9,0.90);
  lgnd_m500_jet_pt->SetFillColor(0);
  lgnd_m500_jet_pt->SetTextSize(0.05);
  lgnd_m500_jet_pt->SetBorderSize(0);
  lgnd_m500_jet_pt->AddEntry(h_rsg_m500_jet_pt,"G*","L");
  lgnd_m500_jet_pt->AddEntry(h_kkg_m500_jet_pt,"G_{KK}","L");
  lgnd_m500_jet_pt->AddEntry(h_wprime_m500_jet_pt,"W'","L");
  lgnd_m500_jet_pt->Draw();
  

  cur_saveas = save_loc+"h_m500_jet_pt.pdf";
  tc_m500_jet_pt->SaveAs(cur_saveas.c_str());


  // m500_jet_eta
  TCanvas* tc_m500_jet_eta = new TCanvas("tc_m500_jet_eta","tc_m500_jet_eta",0,0,1920,1200);
  tc_m500_jet_eta->cd();

  TH1F* h_rsg_m500_jet_eta = (TH1F*) rsg_m500_file->Get("h_jet_eta");
  h_rsg_m500_jet_eta->Scale(1./h_rsg_m500_jet_eta->Integral());
  
  TH1F* h_kkg_m500_jet_eta = (TH1F*) kkg_m500_file->Get("h_jet_eta");
  h_kkg_m500_jet_eta->Scale(1./h_kkg_m500_jet_eta->Integral());
  
  TH1F* h_wprime_m500_jet_eta = (TH1F*) wprime_m500_file->Get("h_jet_eta");
  h_wprime_m500_jet_eta->Scale(1./h_wprime_m500_jet_eta->Integral());

  h_rsg_m500_jet_eta->GetXaxis()->SetTitle("jet #eta");
  h_rsg_m500_jet_eta->SetLineColor(kRed);
  h_rsg_m500_jet_eta->Draw();
  
  h_wprime_m500_jet_eta->SetLineColor(kBlue);
  h_wprime_m500_jet_eta->Draw("same");

  h_kkg_m500_jet_eta->SetLineColor(kGreen);
  h_kkg_m500_jet_eta->Draw("same");

  tc_m500_jet_eta->SetLogy();
  tc_m500_jet_eta->Update();

  TLegend* lgnd_m500_jet_eta = new TLegend(0.80,0.75,0.9,0.90);
  lgnd_m500_jet_eta->SetFillColor(0);
  lgnd_m500_jet_eta->SetTextSize(0.05);
  lgnd_m500_jet_eta->SetBorderSize(0);
  lgnd_m500_jet_eta->AddEntry(h_rsg_m500_jet_eta,"G*","L");
  lgnd_m500_jet_eta->AddEntry(h_kkg_m500_jet_eta,"G_{KK}","L");
  lgnd_m500_jet_eta->AddEntry(h_wprime_m500_jet_eta,"W'","L");
  lgnd_m500_jet_eta->Draw();
  
  cur_saveas = save_loc+"h_m500_jet_eta.pdf";
  tc_m500_jet_eta->SaveAs(cur_saveas.c_str());



  // m500_jet_n
  TCanvas* tc_m500_jet_n = new TCanvas("tc_m500_jet_n","tc_m500_jet_n",0,0,1920,1200);
  tc_m500_jet_n->cd();

  TH1F* h_rsg_m500_jet_n = (TH1F*) rsg_m500_file->Get("h_jet_n");
  h_rsg_m500_jet_n->Scale(1./h_rsg_m500_jet_n->Integral());
  
  TH1F* h_kkg_m500_jet_n = (TH1F*) kkg_m500_file->Get("h_jet_n");
  h_kkg_m500_jet_n->Scale(1./h_kkg_m500_jet_n->Integral());
  
  TH1F* h_wprime_m500_jet_n = (TH1F*) wprime_m500_file->Get("h_jet_n");
  h_wprime_m500_jet_n->Scale(1./h_wprime_m500_jet_n->Integral());

  h_rsg_m500_jet_n->GetXaxis()->SetTitle("jet n");
  h_rsg_m500_jet_n->SetLineColor(kRed);
  h_rsg_m500_jet_n->Draw();
  
  h_wprime_m500_jet_n->SetLineColor(kBlue);
  h_wprime_m500_jet_n->Draw("same");

  h_kkg_m500_jet_n->SetLineColor(kGreen);
  h_kkg_m500_jet_n->Draw("same");

  tc_m500_jet_n->SetLogy();
  tc_m500_jet_n->Update();

  TLegend* lgnd_m500_jet_n = new TLegend(0.80,0.75,0.9,0.90);
  lgnd_m500_jet_n->SetFillColor(0);
  lgnd_m500_jet_n->SetTextSize(0.05);
  lgnd_m500_jet_n->SetBorderSize(0);
  lgnd_m500_jet_n->AddEntry(h_rsg_m500_jet_n,"G*","L");
  lgnd_m500_jet_n->AddEntry(h_kkg_m500_jet_n,"G_{KK}","L");
  lgnd_m500_jet_n->AddEntry(h_wprime_m500_jet_n,"W'","L");
  lgnd_m500_jet_n->Draw();
  
  cur_saveas = save_loc+"h_m500_jet_n.pdf";
  tc_m500_jet_n->SaveAs(cur_saveas.c_str());


  // m500_cos_theta_star
  TCanvas* tc_m500_cos_theta_star = new TCanvas("tc_m500_cos_theta_star","tc_m500_cos_theta_star",0,0,1920,1200);
  tc_m500_cos_theta_star->cd();

  TH1F* h_rsg_m500_cos_theta_star = (TH1F*) rsg_m500_file->Get("h_cos_theta_star");
  h_rsg_m500_cos_theta_star->Scale(1./h_rsg_m500_cos_theta_star->Integral());
  
  TH1F* h_kkg_m500_cos_theta_star = (TH1F*) kkg_m500_file->Get("h_cos_theta_star");
  h_kkg_m500_cos_theta_star->Scale(1./h_kkg_m500_cos_theta_star->Integral());
  
  TH1F* h_wprime_m500_cos_theta_star = (TH1F*) wprime_m500_file->Get("h_cos_theta_star");
  h_wprime_m500_cos_theta_star->Scale(1./h_wprime_m500_cos_theta_star->Integral());

  h_kkg_m500_cos_theta_star->GetYaxis()->SetRangeUser(0,0.1);
  h_kkg_m500_cos_theta_star->GetXaxis()->SetTitle("cos(#theta*)");
  h_kkg_m500_cos_theta_star->SetLineColor(kGreen);
  h_kkg_m500_cos_theta_star->Draw();
  
  h_wprime_m500_cos_theta_star->SetLineColor(kBlue);
  h_wprime_m500_cos_theta_star->Draw("same");

  h_rsg_m500_cos_theta_star->SetLineColor(kRed);
  h_rsg_m500_cos_theta_star->Draw("same");

  //tc_m500_cos_theta_star->SetLogy();
  tc_m500_cos_theta_star->Update();

  TLegend* lgnd_m500_cos_theta_star = new TLegend(0.80,0.75,0.9,0.90);
  lgnd_m500_cos_theta_star->SetFillColor(0);
  lgnd_m500_cos_theta_star->SetTextSize(0.05);
  lgnd_m500_cos_theta_star->SetBorderSize(0);
  lgnd_m500_cos_theta_star->AddEntry(h_rsg_m500_cos_theta_star,"G*","L");
  lgnd_m500_cos_theta_star->AddEntry(h_kkg_m500_cos_theta_star,"G_{KK}","L");
  lgnd_m500_cos_theta_star->AddEntry(h_wprime_m500_cos_theta_star,"W'","L");
  lgnd_m500_cos_theta_star->Draw();
  
  cur_saveas = save_loc+"h_m500_cos_theta_star.pdf";
  tc_m500_cos_theta_star->SaveAs(cur_saveas.c_str());


  //////////////////////////////////////////////////
  // acceptance cut flow
  ////////////////////////////////////////////////// 
  const int n_cuts = 7; //none, lep_pt,jet_pt,nu_pt,lv_pt,dijet_pt,dijet_m;
  float acceptance_cuts[n_cuts] = {1,2,3,4,5,6,7};
  
  TH1F* h_rsg_m500_evt_n = (TH1F*) rsg_m500_file->Get("h_evt_n");
  TH1F* h_rsg_m500_lep_pt_n = (TH1F*) rsg_m500_file->Get("h_lep_pt_n");
  TH1F* h_rsg_m500_qrk_pt_n = (TH1F*) rsg_m500_file->Get("h_qrk_pt_n");
  TH1F* h_rsg_m500_nu_pt_n = (TH1F*) rsg_m500_file->Get("h_nu_pt_n");
  TH1F* h_rsg_m500_lv_pt_n = (TH1F*) rsg_m500_file->Get("h_lv_pt_n");
  TH1F* h_rsg_m500_dijet_pt_n = (TH1F*) rsg_m500_file->Get("h_dijet_pt_n");
  TH1F* h_rsg_m500_dijet_m_n = (TH1F*) rsg_m500_file->Get("h_dijet_m_n");
   
  float rsg_m500_acceptances[n_cuts] = {
    h_rsg_m500_evt_n->GetEntries()/h_rsg_m500_evt_n->GetEntries(),
    h_rsg_m500_lep_pt_n->GetEntries()/h_rsg_m500_evt_n->GetEntries(),
    h_rsg_m500_qrk_pt_n->GetEntries()/h_rsg_m500_evt_n->GetEntries(),
    h_rsg_m500_nu_pt_n->GetEntries()/h_rsg_m500_evt_n->GetEntries(),
    h_rsg_m500_lv_pt_n->GetEntries()/h_rsg_m500_evt_n->GetEntries(),
    h_rsg_m500_dijet_pt_n->GetEntries()/h_rsg_m500_evt_n->GetEntries(),
    h_rsg_m500_dijet_m_n->GetEntries()/h_rsg_m500_evt_n->GetEntries()};

  TH1F* h_kkg_m500_evt_n = (TH1F*) kkg_m500_file->Get("h_evt_n");
  TH1F* h_kkg_m500_lep_pt_n = (TH1F*) kkg_m500_file->Get("h_lep_pt_n");
  TH1F* h_kkg_m500_qrk_pt_n = (TH1F*) kkg_m500_file->Get("h_qrk_pt_n");
  TH1F* h_kkg_m500_nu_pt_n = (TH1F*) kkg_m500_file->Get("h_nu_pt_n");
  TH1F* h_kkg_m500_lv_pt_n = (TH1F*) kkg_m500_file->Get("h_lv_pt_n");
  TH1F* h_kkg_m500_dijet_pt_n = (TH1F*) kkg_m500_file->Get("h_dijet_pt_n");
  TH1F* h_kkg_m500_dijet_m_n = (TH1F*) kkg_m500_file->Get("h_dijet_m_n");
   
  float kkg_m500_acceptances[n_cuts] = {
    h_kkg_m500_evt_n->GetEntries()/h_kkg_m500_evt_n->GetEntries(),
    h_kkg_m500_lep_pt_n->GetEntries()/h_kkg_m500_evt_n->GetEntries(),
    h_kkg_m500_qrk_pt_n->GetEntries()/h_kkg_m500_evt_n->GetEntries(),
    h_kkg_m500_nu_pt_n->GetEntries()/h_kkg_m500_evt_n->GetEntries(),
    h_kkg_m500_lv_pt_n->GetEntries()/h_kkg_m500_evt_n->GetEntries(),
    h_kkg_m500_dijet_pt_n->GetEntries()/h_kkg_m500_evt_n->GetEntries(),
    h_kkg_m500_dijet_m_n->GetEntries()/h_kkg_m500_evt_n->GetEntries()};

  TH1F* h_wprime_m500_evt_n = (TH1F*) wprime_m500_file->Get("h_evt_n");
  TH1F* h_wprime_m500_lep_pt_n = (TH1F*) wprime_m500_file->Get("h_lep_pt_n");
  TH1F* h_wprime_m500_qrk_pt_n = (TH1F*) wprime_m500_file->Get("h_qrk_pt_n");
  TH1F* h_wprime_m500_nu_pt_n = (TH1F*) wprime_m500_file->Get("h_nu_pt_n");
  TH1F* h_wprime_m500_lv_pt_n = (TH1F*) wprime_m500_file->Get("h_lv_pt_n");
  TH1F* h_wprime_m500_dijet_pt_n = (TH1F*) wprime_m500_file->Get("h_dijet_pt_n");
  TH1F* h_wprime_m500_dijet_m_n = (TH1F*) wprime_m500_file->Get("h_dijet_m_n");
 
  float wprime_m500_acceptances[n_cuts] = {
    h_wprime_m500_evt_n->GetEntries()/h_wprime_m500_evt_n->GetEntries(),
    h_wprime_m500_lep_pt_n->GetEntries()/h_wprime_m500_evt_n->GetEntries(),
    h_wprime_m500_qrk_pt_n->GetEntries()/h_wprime_m500_evt_n->GetEntries(),
    h_wprime_m500_nu_pt_n->GetEntries()/h_wprime_m500_evt_n->GetEntries(),
    h_wprime_m500_lv_pt_n->GetEntries()/h_wprime_m500_evt_n->GetEntries(),
    h_wprime_m500_dijet_pt_n->GetEntries()/h_wprime_m500_evt_n->GetEntries(),
    h_wprime_m500_dijet_m_n->GetEntries()/h_wprime_m500_evt_n->GetEntries()};

  
  TCanvas *tc_m500_acceptances =
    new TCanvas("tc_m500_acceptances","Acceptances",200,10,700,500);
  tc_m500_acceptances->SetGrid();
  tc_m500_acceptances->SetFillColor(0);

  TH1F *frame_m500_acceptances = tc_m500_acceptances->DrawFrame(0,0,8,1);
  frame_m500_acceptances->GetYaxis()->SetTitleSize(0.06);
  frame_m500_acceptances->GetYaxis()->SetTitleOffset(1);
  frame_m500_acceptances->GetXaxis()->SetTitleSize(0.05);
  frame_m500_acceptances->GetXaxis()->SetTitleOffset(0.8);
  // frame_m500_acceptances->GetXaxis()->SetBinLabel(1,"bin1");
  // frame_m500_acceptances->GetXaxis()->SetBinLabel(2,"bin2");

  frame_m500_acceptances->SetXTitle("Selection Cut");
  frame_m500_acceptances->SetYTitle("Acceptance");

  TGraph* gr_rsg_m500_acceptances = new TGraph(n_cuts,acceptance_cuts,rsg_m500_acceptances);
  gr_rsg_m500_acceptances->SetLineColor(kRed);
  gr_rsg_m500_acceptances->SetMarkerColor(kRed);
  gr_rsg_m500_acceptances->Draw("C*");

  TGraph* gr_kkg_m500_acceptances = new TGraph(n_cuts,acceptance_cuts,kkg_m500_acceptances);
  gr_kkg_m500_acceptances->SetLineColor(kGreen);
  gr_kkg_m500_acceptances->SetMarkerColor(kGreen);
  gr_kkg_m500_acceptances->Draw("C*");

  TGraph* gr_wprime_m500_acceptances = new TGraph(n_cuts,acceptance_cuts,wprime_m500_acceptances);
  gr_wprime_m500_acceptances->SetLineColor(kBlue);
  gr_wprime_m500_acceptances->SetMarkerColor(kBlue);
  gr_wprime_m500_acceptances->Draw("C*");


  TLegend* lgnd_m500_acceptances = new TLegend(0.8,0.8,0.9,0.95);
  lgnd_m500_acceptances->SetTextSize(0.05);
  lgnd_m500_acceptances->SetFillColor(0);
  lgnd_m500_acceptances->AddEntry(gr_wprime_m500_acceptances,"W'","L");
  lgnd_m500_acceptances->AddEntry(gr_rsg_m500_acceptances,"G*","L");
  lgnd_m500_acceptances->AddEntry(gr_kkg_m500_acceptances,"G_{KK}","L");
  lgnd_m500_acceptances->Draw();

  tc_m500_acceptances->cd();
  tc_m500_acceptances->SaveAs("../canvases/latest/gr_m500_acceptances.pdf");

  
  //m1000
  TH1F* h_rsg_m1000_evt_n = (TH1F*) rsg_m1000_file->Get("h_evt_n");
  TH1F* h_rsg_m1000_lep_pt_n = (TH1F*) rsg_m1000_file->Get("h_lep_pt_n");
  TH1F* h_rsg_m1000_qrk_pt_n = (TH1F*) rsg_m1000_file->Get("h_qrk_pt_n");
  TH1F* h_rsg_m1000_nu_pt_n = (TH1F*) rsg_m1000_file->Get("h_nu_pt_n");
  TH1F* h_rsg_m1000_lv_pt_n = (TH1F*) rsg_m1000_file->Get("h_lv_pt_n");
  TH1F* h_rsg_m1000_dijet_pt_n = (TH1F*) rsg_m1000_file->Get("h_dijet_pt_n");
  TH1F* h_rsg_m1000_dijet_m_n = (TH1F*) rsg_m1000_file->Get("h_dijet_m_n");
   
  float rsg_m1000_acceptances[n_cuts] = {
    h_rsg_m1000_evt_n->GetEntries()/h_rsg_m1000_evt_n->GetEntries(),
    h_rsg_m1000_lep_pt_n->GetEntries()/h_rsg_m1000_evt_n->GetEntries(),
    h_rsg_m1000_qrk_pt_n->GetEntries()/h_rsg_m1000_evt_n->GetEntries(),
    h_rsg_m1000_nu_pt_n->GetEntries()/h_rsg_m1000_evt_n->GetEntries(),
    h_rsg_m1000_lv_pt_n->GetEntries()/h_rsg_m1000_evt_n->GetEntries(),
    h_rsg_m1000_dijet_pt_n->GetEntries()/h_rsg_m1000_evt_n->GetEntries(),
    h_rsg_m1000_dijet_m_n->GetEntries()/h_rsg_m1000_evt_n->GetEntries()};

  //kkg
  TH1F* h_kkg_m1000_evt_n = (TH1F*) kkg_m1000_file->Get("h_evt_n");
  TH1F* h_kkg_m1000_lep_pt_n = (TH1F*) kkg_m1000_file->Get("h_lep_pt_n");
  TH1F* h_kkg_m1000_qrk_pt_n = (TH1F*) kkg_m1000_file->Get("h_qrk_pt_n");
  TH1F* h_kkg_m1000_nu_pt_n = (TH1F*) kkg_m1000_file->Get("h_nu_pt_n");
  TH1F* h_kkg_m1000_lv_pt_n = (TH1F*) kkg_m1000_file->Get("h_lv_pt_n");
  TH1F* h_kkg_m1000_dijet_pt_n = (TH1F*) kkg_m1000_file->Get("h_dijet_pt_n");
  TH1F* h_kkg_m1000_dijet_m_n = (TH1F*) kkg_m1000_file->Get("h_dijet_m_n");
   
  float kkg_m1000_acceptances[n_cuts] = {
    h_kkg_m1000_evt_n->GetEntries()/h_kkg_m1000_evt_n->GetEntries(),
    h_kkg_m1000_lep_pt_n->GetEntries()/h_kkg_m1000_evt_n->GetEntries(),
    h_kkg_m1000_qrk_pt_n->GetEntries()/h_kkg_m1000_evt_n->GetEntries(),
    h_kkg_m1000_nu_pt_n->GetEntries()/h_kkg_m1000_evt_n->GetEntries(),
    h_kkg_m1000_lv_pt_n->GetEntries()/h_kkg_m1000_evt_n->GetEntries(),
    h_kkg_m1000_dijet_pt_n->GetEntries()/h_kkg_m1000_evt_n->GetEntries(),
    h_kkg_m1000_dijet_m_n->GetEntries()/h_kkg_m1000_evt_n->GetEntries()};


  TH1F* h_wprime_m1000_evt_n = (TH1F*) wprime_m1000_file->Get("h_evt_n");
  TH1F* h_wprime_m1000_lep_pt_n = (TH1F*) wprime_m1000_file->Get("h_lep_pt_n");
  TH1F* h_wprime_m1000_qrk_pt_n = (TH1F*) wprime_m1000_file->Get("h_qrk_pt_n");
  TH1F* h_wprime_m1000_nu_pt_n = (TH1F*) wprime_m1000_file->Get("h_nu_pt_n");
  TH1F* h_wprime_m1000_lv_pt_n = (TH1F*) wprime_m1000_file->Get("h_lv_pt_n");
  TH1F* h_wprime_m1000_dijet_pt_n = (TH1F*) wprime_m1000_file->Get("h_dijet_pt_n");
  TH1F* h_wprime_m1000_dijet_m_n = (TH1F*) wprime_m1000_file->Get("h_dijet_m_n");
 
  float wprime_m1000_acceptances[n_cuts] = {
    h_wprime_m1000_evt_n->GetEntries()/h_wprime_m1000_evt_n->GetEntries(),
    h_wprime_m1000_lep_pt_n->GetEntries()/h_wprime_m1000_evt_n->GetEntries(),
    h_wprime_m1000_qrk_pt_n->GetEntries()/h_wprime_m1000_evt_n->GetEntries(),
    h_wprime_m1000_nu_pt_n->GetEntries()/h_wprime_m1000_evt_n->GetEntries(),
    h_wprime_m1000_lv_pt_n->GetEntries()/h_wprime_m1000_evt_n->GetEntries(),
    h_wprime_m1000_dijet_pt_n->GetEntries()/h_wprime_m1000_evt_n->GetEntries(),
    h_wprime_m1000_dijet_m_n->GetEntries()/h_wprime_m1000_evt_n->GetEntries()};

  
  TCanvas *tc_m1000_acceptances =
    new TCanvas("tc_m1000_acceptances","RSG Acceptances",200,10,700,500);
  tc_m1000_acceptances->SetGrid();
  tc_m1000_acceptances->SetFillColor(0);

  TH1F *frame_m1000_acceptances = tc_m1000_acceptances->DrawFrame(0,0,8,1);
  frame_m1000_acceptances->GetYaxis()->SetTitleSize(0.06);
  frame_m1000_acceptances->GetYaxis()->SetTitleOffset(1);
  frame_m1000_acceptances->GetXaxis()->SetTitleSize(0.05);
  frame_m1000_acceptances->GetXaxis()->SetTitleOffset(0.8);
  frame_m1000_acceptances->SetXTitle("Selection Cut");
  frame_m1000_acceptances->SetYTitle("Acceptance");

  TGraph* gr_rsg_m1000_acceptances = new TGraph(n_cuts,acceptance_cuts,rsg_m1000_acceptances);
  gr_rsg_m1000_acceptances->SetLineColor(kRed);
  gr_rsg_m1000_acceptances->SetMarkerColor(kRed);
  gr_rsg_m1000_acceptances->Draw("C*");

  TGraph* gr_kkg_m1000_acceptances = new TGraph(n_cuts,acceptance_cuts,kkg_m1000_acceptances);
  gr_kkg_m1000_acceptances->SetLineColor(kGreen);
  gr_kkg_m1000_acceptances->SetMarkerColor(kGreen);
  gr_kkg_m1000_acceptances->Draw("C*");

  TGraph* gr_wprime_m1000_acceptances = new TGraph(n_cuts,acceptance_cuts,wprime_m1000_acceptances);
  gr_wprime_m1000_acceptances->SetLineColor(kBlue);
  gr_wprime_m1000_acceptances->SetMarkerColor(kBlue);
  gr_wprime_m1000_acceptances->Draw("C*");

  TLegend* lgnd_m1000_acceptances = new TLegend(0.8,0.8,0.9,0.95);
  lgnd_m1000_acceptances->SetTextSize(0.05);
  lgnd_m1000_acceptances->SetFillColor(0);
  lgnd_m1000_acceptances->AddEntry(gr_wprime_m1000_acceptances,"W'","L");
  lgnd_m1000_acceptances->AddEntry(gr_kkg_m1000_acceptances,"G_{KK}","L");
  lgnd_m1000_acceptances->AddEntry(gr_rsg_m1000_acceptances,"G*","L");
  lgnd_m1000_acceptances->Draw();

  tc_m1000_acceptances->cd();
  tc_m1000_acceptances->SaveAs("../canvases/latest/gr_m1000_acceptances.pdf");

  //relative acceptances

  float rel_m500_acceptances[n_cuts]={0.};
  float rel_m1000_acceptances[n_cuts]={0.};

  for(int i=0;i<n_cuts;i++){
    rel_m500_acceptances[i]=kkg_m500_acceptances[i]/rsg_m500_acceptances[i];
    rel_m1000_acceptances[i]=kkg_m1000_acceptances[i]/rsg_m1000_acceptances[i];
  }

  TCanvas *tc_rel_m500_acceptances =
    new TCanvas("tc_rel_m500_acceptances","Relative Acceptances",200,10,700,500);
  tc_rel_m500_acceptances->SetGrid();
  tc_rel_m500_acceptances->SetFillColor(0);

  TH1F *frame_rel_m500_acceptances = tc_rel_m500_acceptances->DrawFrame(0,1,8,3.5);
  frame_rel_m500_acceptances->GetYaxis()->SetTitleSize(0.06);
  frame_rel_m500_acceptances->GetYaxis()->SetTitleOffset(1);
  frame_rel_m500_acceptances->GetXaxis()->SetTitleSize(0.05);
  frame_rel_m500_acceptances->GetXaxis()->SetTitleOffset(0.8);
  // frame_rel_m500_acceptances->GetXaxis()->SetBinLabel(1,"bin1");
  // frame_rel_m500_acceptances->GetXaxis()->SetBinLabel(2,"bin2");

  frame_rel_m500_acceptances->SetXTitle("Selection Cut");
  frame_rel_m500_acceptances->SetYTitle("Relative Acceptance (G_{KK}/G*)");

  TGraph* gr_rel_m500_acceptances = new TGraph(n_cuts,acceptance_cuts,rel_m500_acceptances);
  gr_rel_m500_acceptances->Draw("C*");

  tc_rel_m500_acceptances->cd();
  tc_rel_m500_acceptances->SaveAs("../canvases/latest/gr_rel_m500_acceptances.pdf");


  
  TCanvas *tc_rel_m1000_acceptances =
    new TCanvas("tc_rel_m1000_acceptances","Relative Acceptances",200,10,700,500);
  tc_rel_m1000_acceptances->SetGrid();
  tc_rel_m1000_acceptances->SetFillColor(0);

  TH1F *frame_rel_m1000_acceptances = tc_rel_m1000_acceptances->DrawFrame(0,1,8,2);
  frame_rel_m1000_acceptances->GetYaxis()->SetTitleSize(0.06);
  frame_rel_m1000_acceptances->GetYaxis()->SetTitleOffset(1);
  frame_rel_m1000_acceptances->GetXaxis()->SetTitleSize(0.05);
  frame_rel_m1000_acceptances->GetXaxis()->SetTitleOffset(0.8);
  // frame_rel_m1000_acceptances->GetXaxis()->SetBinLabel(1,"bin1");
  // frame_rel_m1000_acceptances->GetXaxis()->SetBinLabel(2,"bin2");

  frame_rel_m1000_acceptances->SetXTitle("Selection Cut");
  frame_rel_m1000_acceptances->SetYTitle("Relative Acceptance (G_{KK}/G*)");

  TGraph* gr_rel_m1000_acceptances = new TGraph(n_cuts,acceptance_cuts,rel_m1000_acceptances);
  gr_rel_m1000_acceptances->Draw("C*");

  tc_rel_m1000_acceptances->cd();
  tc_rel_m1000_acceptances->SaveAs("../canvases/latest/gr_rel_m1000_acceptances.pdf");


  gROOT->ProcessLine(".q");
  return;
}


