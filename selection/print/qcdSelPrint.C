#include <TLine.h>

void qcdSelPrint(bool drawData=true){

  gROOT->LoadMacro("../../include/atlasstyle-00-03-04/AtlasStyle.C");
  SetAtlasStyle();
  gROOT->LoadMacro("../../include/atlasstyle-00-03-04/AtlasUtils.C");
  gROOT->LoadMacro("../../include/atlasstyle-00-03-04/AtlasLabels.C");
  
  gROOT->SetBatch();
  
  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In selPrint.C"<<endl;

  TFile* data_sel_plots =
    (TFile*) TFile::Open("../../plots/selection_plots/merged/sel.data.selection.root");

  TFile* qcd_sel_plots =
    (TFile*) TFile::Open("../../plots/selection_plots/merged/sel.qcd.selection.root");
  TFile* mc_bkgd_sel_plots = 
      (TFile*) TFile::Open("../../plots/selection_plots/merged/sel.nonqcd.selection.root");

  TDirectory* dir_qcd_elec = (TDirectory*) qcd_sel_plots->GetDirectory("elec");
  TDirectory* dir_bkgd_elec = (TDirectory*) mc_bkgd_sel_plots->GetDirectory("elec");

  

  //////////////////////////////////////////////////
  // elec_nm1_rel_etiso30
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_etiso30 = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_etiso30");
  TH1F* h_qcd_elec_nm1_rel_etiso30 = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_etiso30");
  int n_qcd_elec_nm1_rel_etiso30 = h_qcd_elec_nm1_rel_etiso30->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_etiso30 = new TCanvas("tc_elec_nm1_rel_etiso30","tc_elec_nm1_rel_etiso30",0,0,1920,1200);
  tc_elec_nm1_rel_etiso30->cd();

  h_bkgd_elec_nm1_rel_etiso30->Scale(1/h_bkgd_elec_nm1_rel_etiso30->Integral());
  h_bkgd_elec_nm1_rel_etiso30->SetLineColor(kBlack);
  h_bkgd_elec_nm1_rel_etiso30->GetXaxis()->SetTitle("elec_nm1_rel_etiso30");
  h_bkgd_elec_nm1_rel_etiso30->Draw("HIST");
  h_qcd_elec_nm1_rel_etiso30->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_etiso30->Scale(1/h_qcd_elec_nm1_rel_etiso30->Integral());
  h_qcd_elec_nm1_rel_etiso30->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_etiso30 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_etiso30->SetFillColor(0);
  lgnd_elec_nm1_rel_etiso30->SetTextSize(0.03);
  lgnd_elec_nm1_rel_etiso30->AddEntry(h_qcd_elec_nm1_rel_etiso30,"Qcd","L");
  lgnd_elec_nm1_rel_etiso30->AddEntry(h_bkgd_elec_nm1_rel_etiso30,"Backgrounds","L");
  lgnd_elec_nm1_rel_etiso30->Draw();
  
  tc_elec_nm1_rel_etiso30->Update();
  
  TLine *elec_nm1_rel_etiso30_cut = new TLine(0.14,tc_elec_nm1_rel_etiso30->GetUymin(),0.14,tc_elec_nm1_rel_etiso30->GetUymax());
  elec_nm1_rel_etiso30_cut->SetLineColor(kBlue);
  elec_nm1_rel_etiso30_cut->Draw();

  tc_elec_nm1_rel_etiso30->SetLogy();
  tc_elec_nm1_rel_etiso30->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_etiso30.png");


  //////////////////////////////////////////////////
  // elec_nm1_rel_etiso30_0bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_etiso30_0bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_etiso30_0bin");
  TH1F* h_qcd_elec_nm1_rel_etiso30_0bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_etiso30_0bin");

  int n_qcd_elec_nm1_rel_etiso30_0bin = h_qcd_elec_nm1_rel_etiso30_0bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_etiso30_0bin = new TCanvas("tc_elec_nm1_rel_etiso30_0bin","tc_elec_nm1_rel_etiso30_0bin",0,0,1920,1200);
  tc_elec_nm1_rel_etiso30_0bin->cd();

  h_bkgd_elec_nm1_rel_etiso30_0bin->Scale(1/h_bkgd_elec_nm1_rel_etiso30_0bin->Integral());
  //  h_bkgd_elec_nm1_rel_etiso30_0bin->SetLineColor(kRed);
  h_bkgd_elec_nm1_rel_etiso30_0bin->GetXaxis()->SetTitle("elec_nm1_rel_etiso30_0bin");
  h_bkgd_elec_nm1_rel_etiso30_0bin->Draw("HIST");
  h_qcd_elec_nm1_rel_etiso30_0bin->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_etiso30_0bin->Scale(1/h_qcd_elec_nm1_rel_etiso30_0bin->Integral());
  h_qcd_elec_nm1_rel_etiso30_0bin->Draw("HIST sames");


  TLegend* lgnd_elec_nm1_rel_etiso30_0bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_etiso30_0bin->SetFillColor(0);
  lgnd_elec_nm1_rel_etiso30_0bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_etiso30_0bin->AddEntry(h_qcd_elec_nm1_rel_etiso30_0bin,"Qcd","L");
  lgnd_elec_nm1_rel_etiso30_0bin->AddEntry(h_bkgd_elec_nm1_rel_etiso30_0bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_etiso30_0bin->Draw();
  
  tc_elec_nm1_rel_etiso30_0bin->Update();
  
  TLine *elec_nm1_rel_etiso30_0bin_cut = new TLine(0.14,tc_elec_nm1_rel_etiso30_0bin->GetUymin(),0.14,tc_elec_nm1_rel_etiso30_0bin->GetUymax());
  elec_nm1_rel_etiso30_0bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_etiso30_0bin_cut->Draw();

  tc_elec_nm1_rel_etiso30_0bin->SetLogy();
  tc_elec_nm1_rel_etiso30_0bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_etiso30_0bin.png");


  //////////////////////////////////////////////////
  // elec_nm1_rel_etiso30_1bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_etiso30_1bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_etiso30_1bin");
  TH1F* h_qcd_elec_nm1_rel_etiso30_1bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_etiso30_1bin");
  int n_qcd_elec_nm1_rel_etiso30_1bin = h_qcd_elec_nm1_rel_etiso30_1bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_etiso30_1bin = new TCanvas("tc_elec_nm1_rel_etiso30_1bin","tc_elec_nm1_rel_etiso30_1bin",0,0,1920,1200);
  tc_elec_nm1_rel_etiso30_1bin->cd();

  h_qcd_elec_nm1_rel_etiso30_1bin->Scale(1/h_qcd_elec_nm1_rel_etiso30_1bin->Integral());
  h_qcd_elec_nm1_rel_etiso30_1bin->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_etiso30_1bin->GetXaxis()->SetTitle("elec_nm1_rel_etiso30_1bin");
  h_qcd_elec_nm1_rel_etiso30_1bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_etiso30_1bin->Scale(1/h_bkgd_elec_nm1_rel_etiso30_1bin->Integral());
  h_bkgd_elec_nm1_rel_etiso30_1bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_etiso30_1bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_etiso30_1bin->SetFillColor(0);
  lgnd_elec_nm1_rel_etiso30_1bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_etiso30_1bin->AddEntry(h_qcd_elec_nm1_rel_etiso30_1bin,"Qcd","L");
  lgnd_elec_nm1_rel_etiso30_1bin->AddEntry(h_bkgd_elec_nm1_rel_etiso30_1bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_etiso30_1bin->Draw();
  
  tc_elec_nm1_rel_etiso30_1bin->Update();
  
  TLine *elec_nm1_rel_etiso30_1bin_cut = new TLine(0.14,tc_elec_nm1_rel_etiso30_1bin->GetUymin(),0.14,tc_elec_nm1_rel_etiso30_1bin->GetUymax());
  elec_nm1_rel_etiso30_1bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_etiso30_1bin_cut->Draw();

  tc_elec_nm1_rel_etiso30_1bin->SetLogy();
  tc_elec_nm1_rel_etiso30_1bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_etiso30_1bin.png");

//////////////////////////////////////////////////
  // elec_nm1_rel_etiso30_2bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_etiso30_2bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_etiso30_2bin");
  TH1F* h_qcd_elec_nm1_rel_etiso30_2bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_etiso30_2bin");
  int n_qcd_elec_nm1_rel_etiso30_2bin = h_qcd_elec_nm1_rel_etiso30_2bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_etiso30_2bin = new TCanvas("tc_elec_nm1_rel_etiso30_2bin","tc_elec_nm1_rel_etiso30_2bin",0,0,1920,1200);
  tc_elec_nm1_rel_etiso30_2bin->cd();

  h_qcd_elec_nm1_rel_etiso30_2bin->Scale(1/h_qcd_elec_nm1_rel_etiso30_2bin->Integral());
  h_qcd_elec_nm1_rel_etiso30_2bin->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_etiso30_2bin->GetXaxis()->SetTitle("elec_nm1_rel_etiso30_2bin");
  h_qcd_elec_nm1_rel_etiso30_2bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_etiso30_2bin->Scale(1/h_bkgd_elec_nm1_rel_etiso30_2bin->Integral());
  h_bkgd_elec_nm1_rel_etiso30_2bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_etiso30_2bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_etiso30_2bin->SetFillColor(0);
  lgnd_elec_nm1_rel_etiso30_2bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_etiso30_2bin->AddEntry(h_qcd_elec_nm1_rel_etiso30_2bin,"Qcd","L");
  lgnd_elec_nm1_rel_etiso30_2bin->AddEntry(h_bkgd_elec_nm1_rel_etiso30_2bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_etiso30_2bin->Draw();
  
  tc_elec_nm1_rel_etiso30_2bin->Update();
  
  TLine *elec_nm1_rel_etiso30_2bin_cut = new TLine(0.14,tc_elec_nm1_rel_etiso30_2bin->GetUymin(),0.14,tc_elec_nm1_rel_etiso30_2bin->GetUymax());
  elec_nm1_rel_etiso30_2bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_etiso30_2bin_cut->Draw();

  tc_elec_nm1_rel_etiso30_2bin->SetLogy();
  tc_elec_nm1_rel_etiso30_2bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_etiso30_2bin.png");

//////////////////////////////////////////////////
  // elec_nm1_rel_etiso30_3bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_etiso30_3bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_etiso30_3bin");
  TH1F* h_qcd_elec_nm1_rel_etiso30_3bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_etiso30_3bin");
  int n_qcd_elec_nm1_rel_etiso30_3bin = h_qcd_elec_nm1_rel_etiso30_3bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_etiso30_3bin = new TCanvas("tc_elec_nm1_rel_etiso30_3bin","tc_elec_nm1_rel_etiso30_3bin",0,0,1920,1200);
  tc_elec_nm1_rel_etiso30_3bin->cd();

  h_qcd_elec_nm1_rel_etiso30_3bin->Scale(1/h_qcd_elec_nm1_rel_etiso30_3bin->Integral());
  h_qcd_elec_nm1_rel_etiso30_3bin->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_etiso30_3bin->GetXaxis()->SetTitle("elec_nm1_rel_etiso30_3bin");
  h_qcd_elec_nm1_rel_etiso30_3bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_etiso30_3bin->Scale(1/h_bkgd_elec_nm1_rel_etiso30_3bin->Integral());
  h_bkgd_elec_nm1_rel_etiso30_3bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_etiso30_3bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_etiso30_3bin->SetFillColor(0);
  lgnd_elec_nm1_rel_etiso30_3bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_etiso30_3bin->AddEntry(h_qcd_elec_nm1_rel_etiso30_3bin,"QCD","L");
  lgnd_elec_nm1_rel_etiso30_3bin->AddEntry(h_bkgd_elec_nm1_rel_etiso30_3bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_etiso30_3bin->Draw();
  
  tc_elec_nm1_rel_etiso30_3bin->Update();
  
  TLine *elec_nm1_rel_etiso30_3bin_cut = new TLine(0.14,tc_elec_nm1_rel_etiso30_3bin->GetUymin(),0.14,tc_elec_nm1_rel_etiso30_3bin->GetUymax());
  elec_nm1_rel_etiso30_3bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_etiso30_3bin_cut->Draw();

  tc_elec_nm1_rel_etiso30_3bin->SetLogy();
  tc_elec_nm1_rel_etiso30_3bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_etiso30_3bin.png");


  //////////////////////////////////////////////////
  // elec_nm1_etiso30
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_etiso30 = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_etiso30");
  TH1F* h_qcd_elec_nm1_etiso30 = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_etiso30");
  int n_qcd_elec_nm1_etiso30 = h_qcd_elec_nm1_etiso30->GetEntries();
  
  TCanvas* tc_elec_nm1_etiso30 = new TCanvas("tc_elec_nm1_etiso30","tc_elec_nm1_etiso30",0,0,1920,1200);
  tc_elec_nm1_etiso30->cd();

  h_bkgd_elec_nm1_etiso30->Scale(1/h_bkgd_elec_nm1_etiso30->Integral());
  h_bkgd_elec_nm1_etiso30->SetLineColor(kRed);
  h_bkgd_elec_nm1_etiso30->GetXaxis()->SetTitle("elec_nm1_etiso30");
  h_bkgd_elec_nm1_etiso30->Draw("HIST");
  h_qcd_elec_nm1_etiso30->Scale(1/h_qcd_elec_nm1_etiso30->Integral());
  h_qcd_elec_nm1_etiso30->Draw("HIST sames");


  TLegend* lgnd_elec_nm1_etiso30 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_etiso30->SetFillColor(0);
  lgnd_elec_nm1_etiso30->SetTextSize(0.03);
  lgnd_elec_nm1_etiso30->AddEntry(h_qcd_elec_nm1_etiso30,"Qcd","L");
  lgnd_elec_nm1_etiso30->AddEntry(h_bkgd_elec_nm1_etiso30,"Backgrounds","L");
  lgnd_elec_nm1_etiso30->Draw();
  
  tc_elec_nm1_etiso30->Update();
  
  TLine *elec_nm1_etiso30_cut = new TLine(0.14,tc_elec_nm1_etiso30->GetUymin(),0.14,tc_elec_nm1_etiso30->GetUymax());
  elec_nm1_etiso30_cut->SetLineColor(kBlue);
  elec_nm1_etiso30_cut->Draw();

  tc_elec_nm1_etiso30->SetLogy();
  tc_elec_nm1_etiso30->SaveAs("../canvases/latest/h_qcd_elec_nm1_etiso30.png");


  //////////////////////////////////////////////////
  // elec_nm1_etiso30_0bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_etiso30_0bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_etiso30_0bin");
  TH1F* h_qcd_elec_nm1_etiso30_0bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_etiso30_0bin");

  int n_qcd_elec_nm1_etiso30_0bin = h_qcd_elec_nm1_etiso30_0bin->GetEntries();
  
  TCanvas* tc_elec_nm1_etiso30_0bin = new TCanvas("tc_elec_nm1_etiso30_0bin","tc_elec_nm1_etiso30_0bin",0,0,1920,1200);
  tc_elec_nm1_etiso30_0bin->cd();

  h_qcd_elec_nm1_etiso30_0bin->Scale(1/h_qcd_elec_nm1_etiso30_0bin->Integral());
  h_qcd_elec_nm1_etiso30_0bin->SetLineColor(kRed);
  h_qcd_elec_nm1_etiso30_0bin->GetXaxis()->SetTitle("elec_nm1_etiso30_0bin");
  h_qcd_elec_nm1_etiso30_0bin->Draw("HIST");
  h_bkgd_elec_nm1_etiso30_0bin->Scale(1/h_bkgd_elec_nm1_etiso30_0bin->Integral());
  h_bkgd_elec_nm1_etiso30_0bin->Draw("HIST sames");


  TLegend* lgnd_elec_nm1_etiso30_0bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_etiso30_0bin->SetFillColor(0);
  lgnd_elec_nm1_etiso30_0bin->SetTextSize(0.03);
  lgnd_elec_nm1_etiso30_0bin->AddEntry(h_qcd_elec_nm1_etiso30_0bin,"Qcd","L");
  lgnd_elec_nm1_etiso30_0bin->AddEntry(h_bkgd_elec_nm1_etiso30_0bin,"Backgrounds","L");
  lgnd_elec_nm1_etiso30_0bin->Draw();
  
  tc_elec_nm1_etiso30_0bin->Update();
  
  TLine *elec_nm1_etiso30_0bin_cut = new TLine(0.14,tc_elec_nm1_etiso30_0bin->GetUymin(),0.14,tc_elec_nm1_etiso30_0bin->GetUymax());
  elec_nm1_etiso30_0bin_cut->SetLineColor(kBlue);
  elec_nm1_etiso30_0bin_cut->Draw();

  tc_elec_nm1_etiso30_0bin->SetLogy();
  tc_elec_nm1_etiso30_0bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_etiso30_0bin.png");


  //////////////////////////////////////////////////
  // elec_nm1_etiso30_1bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_etiso30_1bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_etiso30_1bin");
  TH1F* h_qcd_elec_nm1_etiso30_1bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_etiso30_1bin");
  int n_qcd_elec_nm1_etiso30_1bin = h_qcd_elec_nm1_etiso30_1bin->GetEntries();
  
  TCanvas* tc_elec_nm1_etiso30_1bin = new TCanvas("tc_elec_nm1_etiso30_1bin","tc_elec_nm1_etiso30_1bin",0,0,1920,1200);
  tc_elec_nm1_etiso30_1bin->cd();

  h_qcd_elec_nm1_etiso30_1bin->Scale(1/h_qcd_elec_nm1_etiso30_1bin->Integral());
  h_qcd_elec_nm1_etiso30_1bin->SetLineColor(kRed);
  h_qcd_elec_nm1_etiso30_1bin->GetXaxis()->SetTitle("elec_nm1_etiso30_1bin");
  h_qcd_elec_nm1_etiso30_1bin->Draw("HIST");
  h_bkgd_elec_nm1_etiso30_1bin->Scale(1/h_bkgd_elec_nm1_etiso30_1bin->Integral());
  h_bkgd_elec_nm1_etiso30_1bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_etiso30_1bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_etiso30_1bin->SetFillColor(0);
  lgnd_elec_nm1_etiso30_1bin->SetTextSize(0.03);
  lgnd_elec_nm1_etiso30_1bin->AddEntry(h_qcd_elec_nm1_etiso30_1bin,"Qcd","L");
  lgnd_elec_nm1_etiso30_1bin->AddEntry(h_bkgd_elec_nm1_etiso30_1bin,"Backgrounds","L");
  lgnd_elec_nm1_etiso30_1bin->Draw();
  
  tc_elec_nm1_etiso30_1bin->Update();
  
  TLine *elec_nm1_etiso30_1bin_cut = new TLine(0.14,tc_elec_nm1_etiso30_1bin->GetUymin(),0.14,tc_elec_nm1_etiso30_1bin->GetUymax());
  elec_nm1_etiso30_1bin_cut->SetLineColor(kBlue);
  elec_nm1_etiso30_1bin_cut->Draw();

  tc_elec_nm1_etiso30_1bin->SetLogy();
  tc_elec_nm1_etiso30_1bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_etiso30_1bin.png");

//////////////////////////////////////////////////
  // elec_nm1_etiso30_2bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_etiso30_2bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_etiso30_2bin");
  TH1F* h_qcd_elec_nm1_etiso30_2bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_etiso30_2bin");
  int n_qcd_elec_nm1_etiso30_2bin = h_qcd_elec_nm1_etiso30_2bin->GetEntries();
  
  TCanvas* tc_elec_nm1_etiso30_2bin = new TCanvas("tc_elec_nm1_etiso30_2bin","tc_elec_nm1_etiso30_2bin",0,0,1920,1200);
  tc_elec_nm1_etiso30_2bin->cd();

  h_qcd_elec_nm1_etiso30_2bin->Scale(1/h_qcd_elec_nm1_etiso30_2bin->Integral());
  h_qcd_elec_nm1_etiso30_2bin->SetLineColor(kRed);
  h_qcd_elec_nm1_etiso30_2bin->GetXaxis()->SetTitle("elec_nm1_etiso30_2bin");
  h_qcd_elec_nm1_etiso30_2bin->Draw("HIST");
  h_bkgd_elec_nm1_etiso30_2bin->Scale(1/h_bkgd_elec_nm1_etiso30_2bin->Integral());
  h_bkgd_elec_nm1_etiso30_2bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_etiso30_2bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_etiso30_2bin->SetFillColor(0);
  lgnd_elec_nm1_etiso30_2bin->SetTextSize(0.03);
  lgnd_elec_nm1_etiso30_2bin->AddEntry(h_qcd_elec_nm1_etiso30_2bin,"Qcd","L");
  lgnd_elec_nm1_etiso30_2bin->AddEntry(h_bkgd_elec_nm1_etiso30_2bin,"Backgrounds","L");
  lgnd_elec_nm1_etiso30_2bin->Draw();
  
  tc_elec_nm1_etiso30_2bin->Update();
  
  TLine *elec_nm1_etiso30_2bin_cut = new TLine(0.14,tc_elec_nm1_etiso30_2bin->GetUymin(),0.14,tc_elec_nm1_etiso30_2bin->GetUymax());
  elec_nm1_etiso30_2bin_cut->SetLineColor(kBlue);
  elec_nm1_etiso30_2bin_cut->Draw();

  tc_elec_nm1_etiso30_2bin->SetLogy();
  tc_elec_nm1_etiso30_2bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_etiso30_2bin.png");

//////////////////////////////////////////////////
  // elec_nm1_etiso30_3bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_etiso30_3bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_etiso30_3bin");
  TH1F* h_qcd_elec_nm1_etiso30_3bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_etiso30_3bin");
  int n_qcd_elec_nm1_etiso30_3bin = h_qcd_elec_nm1_etiso30_3bin->GetEntries();
  
  TCanvas* tc_elec_nm1_etiso30_3bin = new TCanvas("tc_elec_nm1_etiso30_3bin","tc_elec_nm1_etiso30_3bin",0,0,1920,1200);
  tc_elec_nm1_etiso30_3bin->cd();

  h_qcd_elec_nm1_etiso30_3bin->Scale(1/h_qcd_elec_nm1_etiso30_3bin->Integral());
  h_qcd_elec_nm1_etiso30_3bin->SetLineColor(kRed);
  h_qcd_elec_nm1_etiso30_3bin->GetXaxis()->SetTitle("elec_nm1_etiso30_3bin");
  h_qcd_elec_nm1_etiso30_3bin->Draw("HIST");
  h_bkgd_elec_nm1_etiso30_3bin->Scale(1/h_bkgd_elec_nm1_etiso30_3bin->Integral());
  h_bkgd_elec_nm1_etiso30_3bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_etiso30_3bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_etiso30_3bin->SetFillColor(0);
  lgnd_elec_nm1_etiso30_3bin->SetTextSize(0.03);
  lgnd_elec_nm1_etiso30_3bin->AddEntry(h_qcd_elec_nm1_etiso30_3bin,"QCD","L");
  lgnd_elec_nm1_etiso30_3bin->AddEntry(h_bkgd_elec_nm1_etiso30_3bin,"Backgrounds","L");
  lgnd_elec_nm1_etiso30_3bin->Draw();
  
  tc_elec_nm1_etiso30_3bin->Update();
  
  TLine *elec_nm1_etiso30_3bin_cut = new TLine(0.14,tc_elec_nm1_etiso30_3bin->GetUymin(),0.14,tc_elec_nm1_etiso30_3bin->GetUymax());
  elec_nm1_etiso30_3bin_cut->SetLineColor(kBlue);
  elec_nm1_etiso30_3bin_cut->Draw();

  tc_elec_nm1_etiso30_3bin->SetLogy();
  tc_elec_nm1_etiso30_3bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_etiso30_3bin.png");



  //////////////////////////////////////////////////
  // elec_nm1_ptiso30
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_ptiso30 = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_ptiso30");
  TH1F* h_qcd_elec_nm1_ptiso30 = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_ptiso30");
  int n_qcd_elec_nm1_ptiso30 = h_qcd_elec_nm1_ptiso30->GetEntries();
  
  TCanvas* tc_elec_nm1_ptiso30 = new TCanvas("tc_elec_nm1_ptiso30","tc_elec_nm1_ptiso30",0,0,1920,1200);
  tc_elec_nm1_ptiso30->cd();

  h_qcd_elec_nm1_ptiso30->Scale(1/h_qcd_elec_nm1_ptiso30->Integral());
  h_qcd_elec_nm1_ptiso30->SetLineColor(kRed);
  h_qcd_elec_nm1_ptiso30->GetXaxis()->SetTitle("elec_nm1_ptiso30");
  h_qcd_elec_nm1_ptiso30->Draw("HIST");
  h_bkgd_elec_nm1_ptiso30->Scale(1/h_bkgd_elec_nm1_ptiso30->Integral());
  h_bkgd_elec_nm1_ptiso30->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_ptiso30 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_ptiso30->SetFillColor(0);
  lgnd_elec_nm1_ptiso30->SetTextSize(0.03);
  lgnd_elec_nm1_ptiso30->AddEntry(h_qcd_elec_nm1_ptiso30,"Qcd","L");
  lgnd_elec_nm1_ptiso30->AddEntry(h_bkgd_elec_nm1_ptiso30,"Backgrounds","L");
  lgnd_elec_nm1_ptiso30->Draw();
  
  tc_elec_nm1_ptiso30->Update();

  tc_elec_nm1_ptiso30->SetLogy();
  tc_elec_nm1_ptiso30->SaveAs("../canvases/latest/h_qcd_elec_nm1_ptiso30.png");


  
  //////////////////////////////////////////////////
  // elec_nm1_ptiso30_0bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_ptiso30_0bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_ptiso30_0bin");
  TH1F* h_qcd_elec_nm1_ptiso30_0bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_ptiso30_0bin");
  int n_qcd_elec_nm1_ptiso30_0bin = h_qcd_elec_nm1_ptiso30_0bin->GetEntries();
  
  TCanvas* tc_elec_nm1_ptiso30_0bin = new TCanvas("tc_elec_nm1_ptiso30_0bin","tc_elec_nm1_ptiso30_0bin",0,0,1920,1200);
  tc_elec_nm1_ptiso30_0bin->cd();

  h_qcd_elec_nm1_ptiso30_0bin->Scale(1/h_qcd_elec_nm1_ptiso30_0bin->Integral());
  h_qcd_elec_nm1_ptiso30_0bin->SetLineColor(kRed);
  h_qcd_elec_nm1_ptiso30_0bin->GetXaxis()->SetTitle("elec_nm1_ptiso30_0bin");
  h_qcd_elec_nm1_ptiso30_0bin->Draw("HIST");
  h_bkgd_elec_nm1_ptiso30_0bin->Scale(1/h_bkgd_elec_nm1_ptiso30_0bin->Integral());
  h_bkgd_elec_nm1_ptiso30_0bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_ptiso30_0bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_ptiso30_0bin->SetFillColor(0);
  lgnd_elec_nm1_ptiso30_0bin->SetTextSize(0.03);
  lgnd_elec_nm1_ptiso30_0bin->AddEntry(h_qcd_elec_nm1_ptiso30_0bin,"Qcd","L");
  lgnd_elec_nm1_ptiso30_0bin->AddEntry(h_bkgd_elec_nm1_ptiso30_0bin,"Backgrounds","L");
  lgnd_elec_nm1_ptiso30_0bin->Draw();
  
  tc_elec_nm1_ptiso30_0bin->Update();
  
  TLine *elec_nm1_ptiso30_0bin_cut = new TLine(0.14,tc_elec_nm1_ptiso30_0bin->GetUymin(),0.14,tc_elec_nm1_ptiso30_0bin->GetUymax());
  elec_nm1_ptiso30_0bin_cut->SetLineColor(kBlue);
  elec_nm1_ptiso30_0bin_cut->Draw();

  tc_elec_nm1_ptiso30_0bin->SetLogy();
  tc_elec_nm1_ptiso30_0bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_ptiso30_0bin.png");
  
  


  //////////////////////////////////////////////////
  // elec_nm1_ptiso30_1bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_ptiso30_1bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_ptiso30_1bin");
  TH1F* h_qcd_elec_nm1_ptiso30_1bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_ptiso30_1bin");
  int n_qcd_elec_nm1_ptiso30_1bin = h_qcd_elec_nm1_ptiso30_1bin->GetEntries();
  
  TCanvas* tc_elec_nm1_ptiso30_1bin = new TCanvas("tc_elec_nm1_ptiso30_1bin","tc_elec_nm1_ptiso30_1bin",0,0,1920,1200);
  tc_elec_nm1_ptiso30_1bin->cd();

  h_qcd_elec_nm1_ptiso30_1bin->Scale(1/h_qcd_elec_nm1_ptiso30_1bin->Integral());
  h_qcd_elec_nm1_ptiso30_1bin->SetLineColor(kRed);
  h_qcd_elec_nm1_ptiso30_1bin->GetXaxis()->SetTitle("elec_nm1_ptiso30_1bin");
  h_qcd_elec_nm1_ptiso30_1bin->Draw("HIST");
  h_bkgd_elec_nm1_ptiso30_1bin->Scale(1/h_bkgd_elec_nm1_ptiso30_1bin->Integral());
  h_bkgd_elec_nm1_ptiso30_1bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_ptiso30_1bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_ptiso30_1bin->SetFillColor(0);
  lgnd_elec_nm1_ptiso30_1bin->SetTextSize(0.03);
  lgnd_elec_nm1_ptiso30_1bin->AddEntry(h_qcd_elec_nm1_ptiso30_1bin,"Qcd","L");
  lgnd_elec_nm1_ptiso30_1bin->AddEntry(h_bkgd_elec_nm1_ptiso30_1bin,"Backgrounds","L");
  lgnd_elec_nm1_ptiso30_1bin->Draw();
  
  tc_elec_nm1_ptiso30_1bin->Update();
  
  TLine *elec_nm1_ptiso30_1bin_cut = new TLine(0.14,tc_elec_nm1_ptiso30_1bin->GetUymin(),0.14,tc_elec_nm1_ptiso30_1bin->GetUymax());
  elec_nm1_ptiso30_1bin_cut->SetLineColor(kBlue);
  elec_nm1_ptiso30_1bin_cut->Draw();

  tc_elec_nm1_ptiso30_1bin->SetLogy();
  tc_elec_nm1_ptiso30_1bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_ptiso30_1bin.png");

//////////////////////////////////////////////////
  // elec_nm1_ptiso30_2bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_ptiso30_2bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_ptiso30_2bin");
  TH1F* h_qcd_elec_nm1_ptiso30_2bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_ptiso30_2bin");
  int n_qcd_elec_nm1_ptiso30_2bin = h_qcd_elec_nm1_ptiso30_2bin->GetEntries();
  
  TCanvas* tc_elec_nm1_ptiso30_2bin = new TCanvas("tc_elec_nm1_ptiso30_2bin","tc_elec_nm1_ptiso30_2bin",0,0,1920,1200);
  tc_elec_nm1_ptiso30_2bin->cd();

  h_qcd_elec_nm1_ptiso30_2bin->Scale(1/h_qcd_elec_nm1_ptiso30_2bin->Integral());
  h_qcd_elec_nm1_ptiso30_2bin->SetLineColor(kRed);
  h_qcd_elec_nm1_ptiso30_2bin->GetXaxis()->SetTitle("elec_nm1_ptiso30_2bin");
  h_qcd_elec_nm1_ptiso30_2bin->Draw("HIST");
  h_bkgd_elec_nm1_ptiso30_2bin->Scale(1/h_bkgd_elec_nm1_ptiso30_2bin->Integral());
  h_bkgd_elec_nm1_ptiso30_2bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_ptiso30_2bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_ptiso30_2bin->SetFillColor(0);
  lgnd_elec_nm1_ptiso30_2bin->SetTextSize(0.03);
  lgnd_elec_nm1_ptiso30_2bin->AddEntry(h_qcd_elec_nm1_ptiso30_2bin,"Qcd","L");
  lgnd_elec_nm1_ptiso30_2bin->AddEntry(h_bkgd_elec_nm1_ptiso30_2bin,"Backgrounds","L");
  lgnd_elec_nm1_ptiso30_2bin->Draw();
  
  tc_elec_nm1_ptiso30_2bin->Update();
  
  TLine *elec_nm1_ptiso30_2bin_cut = new TLine(0.14,tc_elec_nm1_ptiso30_2bin->GetUymin(),0.14,tc_elec_nm1_ptiso30_2bin->GetUymax());
  elec_nm1_ptiso30_2bin_cut->SetLineColor(kBlue);
  elec_nm1_ptiso30_2bin_cut->Draw();

  tc_elec_nm1_ptiso30_2bin->SetLogy();
  tc_elec_nm1_ptiso30_2bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_ptiso30_2bin.png");

//////////////////////////////////////////////////
  // elec_nm1_ptiso30_3bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_ptiso30_3bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_ptiso30_3bin");
  TH1F* h_qcd_elec_nm1_ptiso30_3bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_ptiso30_3bin");
  int n_qcd_elec_nm1_ptiso30_3bin = h_qcd_elec_nm1_ptiso30_3bin->GetEntries();
  
  TCanvas* tc_elec_nm1_ptiso30_3bin = new TCanvas("tc_elec_nm1_ptiso30_3bin","tc_elec_nm1_ptiso30_3bin",0,0,1920,1200);
  tc_elec_nm1_ptiso30_3bin->cd();

  h_qcd_elec_nm1_ptiso30_3bin->Scale(1/h_qcd_elec_nm1_ptiso30_3bin->Integral());
  h_qcd_elec_nm1_ptiso30_3bin->SetLineColor(kRed);
  h_qcd_elec_nm1_ptiso30_3bin->GetXaxis()->SetTitle("elec_nm1_ptiso30_3bin");
  h_qcd_elec_nm1_ptiso30_3bin->Draw("HIST");
  h_bkgd_elec_nm1_ptiso30_3bin->Scale(1/h_bkgd_elec_nm1_ptiso30_3bin->Integral());
  h_bkgd_elec_nm1_ptiso30_3bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_ptiso30_3bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_ptiso30_3bin->SetFillColor(0);
  lgnd_elec_nm1_ptiso30_3bin->SetTextSize(0.03);
  lgnd_elec_nm1_ptiso30_3bin->AddEntry(h_qcd_elec_nm1_ptiso30_3bin,"QCD","L");
  lgnd_elec_nm1_ptiso30_3bin->AddEntry(h_bkgd_elec_nm1_ptiso30_3bin,"Backgrounds","L");
  lgnd_elec_nm1_ptiso30_3bin->Draw();
  
  tc_elec_nm1_ptiso30_3bin->Update();
  
  TLine *elec_nm1_ptiso30_3bin_cut = new TLine(0.14,tc_elec_nm1_ptiso30_3bin->GetUymin(),0.14,tc_elec_nm1_ptiso30_3bin->GetUymax());
  elec_nm1_ptiso30_3bin_cut->SetLineColor(kBlue);
  elec_nm1_ptiso30_3bin_cut->Draw();

  tc_elec_nm1_ptiso30_3bin->SetLogy();
  tc_elec_nm1_ptiso30_3bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_ptiso30_3bin.png");


  
  //////////////////////////////////////////////////
  // elec_nm1_rel_ptiso30
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_ptiso30 = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_ptiso30");
  TH1F* h_qcd_elec_nm1_rel_ptiso30 = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_ptiso30");
  int n_qcd_elec_nm1_rel_ptiso30 = h_qcd_elec_nm1_rel_ptiso30->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_ptiso30 = new TCanvas("tc_elec_nm1_rel_ptiso30","tc_elec_nm1_rel_ptiso30",0,0,1920,1200);
  tc_elec_nm1_rel_ptiso30->cd();

  h_bkgd_elec_nm1_rel_ptiso30->Scale(1/h_bkgd_elec_nm1_rel_ptiso30->Integral());
  //h_bkgd_elec_nm1_rel_ptiso30->SetLineColor(kRed);
  h_bkgd_elec_nm1_rel_ptiso30->GetXaxis()->SetTitle("elec_nm1_rel_ptiso30");
  h_bkgd_elec_nm1_rel_ptiso30->Draw("HIST");
  h_qcd_elec_nm1_rel_ptiso30->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_ptiso30->Scale(1/h_qcd_elec_nm1_rel_ptiso30->Integral());
  h_qcd_elec_nm1_rel_ptiso30->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_ptiso30 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_ptiso30->SetFillColor(0);
  lgnd_elec_nm1_rel_ptiso30->SetTextSize(0.03);
  lgnd_elec_nm1_rel_ptiso30->AddEntry(h_qcd_elec_nm1_rel_ptiso30,"Qcd","L");
  lgnd_elec_nm1_rel_ptiso30->AddEntry(h_bkgd_elec_nm1_rel_ptiso30,"Backgrounds","L");
  lgnd_elec_nm1_rel_ptiso30->Draw();
  
  tc_elec_nm1_rel_ptiso30->Update();
  
  TLine *elec_nm1_rel_ptiso30_cut = new TLine(0.14,tc_elec_nm1_rel_ptiso30->GetUymin(),0.14,tc_elec_nm1_rel_ptiso30->GetUymax());
  elec_nm1_rel_ptiso30_cut->SetLineColor(kBlue);
  elec_nm1_rel_ptiso30_cut->Draw();

  tc_elec_nm1_rel_ptiso30->SetLogy();
  tc_elec_nm1_rel_ptiso30->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_ptiso30.png");
  
  //////////////////////////////////////////////////
  // elec_nm1_rel_ptiso30_0bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_ptiso30_0bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_ptiso30_0bin");
  TH1F* h_qcd_elec_nm1_rel_ptiso30_0bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_ptiso30_0bin");
  int n_qcd_elec_nm1_rel_ptiso30_0bin = h_qcd_elec_nm1_rel_ptiso30_0bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_ptiso30_0bin = new TCanvas("tc_elec_nm1_rel_ptiso30_0bin","tc_elec_nm1_rel_ptiso30_0bin",0,0,1920,1200);
  tc_elec_nm1_rel_ptiso30_0bin->cd();

  h_qcd_elec_nm1_rel_ptiso30_0bin->Scale(1/h_qcd_elec_nm1_rel_ptiso30_0bin->Integral());
  h_qcd_elec_nm1_rel_ptiso30_0bin->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_ptiso30_0bin->GetXaxis()->SetTitle("elec_nm1_rel_ptiso30_0bin");
  h_qcd_elec_nm1_rel_ptiso30_0bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_ptiso30_0bin->Scale(1/h_bkgd_elec_nm1_rel_ptiso30_0bin->Integral());
  h_bkgd_elec_nm1_rel_ptiso30_0bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_ptiso30_0bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_ptiso30_0bin->SetFillColor(0);
  lgnd_elec_nm1_rel_ptiso30_0bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_ptiso30_0bin->AddEntry(h_qcd_elec_nm1_rel_ptiso30_0bin,"Qcd","L");
  lgnd_elec_nm1_rel_ptiso30_0bin->AddEntry(h_bkgd_elec_nm1_rel_ptiso30_0bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_ptiso30_0bin->Draw();
  
  tc_elec_nm1_rel_ptiso30_0bin->Update();
  
  TLine *elec_nm1_rel_ptiso30_0bin_cut = new TLine(0.14,tc_elec_nm1_rel_ptiso30_0bin->GetUymin(),0.14,tc_elec_nm1_rel_ptiso30_0bin->GetUymax());
  elec_nm1_rel_ptiso30_0bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_ptiso30_0bin_cut->Draw();

  tc_elec_nm1_rel_ptiso30_0bin->SetLogy();
  tc_elec_nm1_rel_ptiso30_0bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_ptiso30_0bin.png");
  
  


  //////////////////////////////////////////////////
  // elec_nm1_rel_ptiso30_1bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_ptiso30_1bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_ptiso30_1bin");
  TH1F* h_qcd_elec_nm1_rel_ptiso30_1bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_ptiso30_1bin");
  int n_qcd_elec_nm1_rel_ptiso30_1bin = h_qcd_elec_nm1_rel_ptiso30_1bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_ptiso30_1bin = new TCanvas("tc_elec_nm1_rel_ptiso30_1bin","tc_elec_nm1_rel_ptiso30_1bin",0,0,1920,1200);
  tc_elec_nm1_rel_ptiso30_1bin->cd();

  h_qcd_elec_nm1_rel_ptiso30_1bin->Scale(1/h_qcd_elec_nm1_rel_ptiso30_1bin->Integral());
  h_qcd_elec_nm1_rel_ptiso30_1bin->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_ptiso30_1bin->GetXaxis()->SetTitle("elec_nm1_rel_ptiso30_1bin");
  h_qcd_elec_nm1_rel_ptiso30_1bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_ptiso30_1bin->Scale(1/h_bkgd_elec_nm1_rel_ptiso30_1bin->Integral());
  h_bkgd_elec_nm1_rel_ptiso30_1bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_ptiso30_1bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_ptiso30_1bin->SetFillColor(0);
  lgnd_elec_nm1_rel_ptiso30_1bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_ptiso30_1bin->AddEntry(h_qcd_elec_nm1_rel_ptiso30_1bin,"Qcd","L");
  lgnd_elec_nm1_rel_ptiso30_1bin->AddEntry(h_bkgd_elec_nm1_rel_ptiso30_1bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_ptiso30_1bin->Draw();
  
  tc_elec_nm1_rel_ptiso30_1bin->Update();
  
  TLine *elec_nm1_rel_ptiso30_1bin_cut = new TLine(0.14,tc_elec_nm1_rel_ptiso30_1bin->GetUymin(),0.14,tc_elec_nm1_rel_ptiso30_1bin->GetUymax());
  elec_nm1_rel_ptiso30_1bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_ptiso30_1bin_cut->Draw();

  tc_elec_nm1_rel_ptiso30_1bin->SetLogy();
  tc_elec_nm1_rel_ptiso30_1bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_ptiso30_1bin.png");

//////////////////////////////////////////////////
  // elec_nm1_rel_ptiso30_2bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_ptiso30_2bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_ptiso30_2bin");
  TH1F* h_qcd_elec_nm1_rel_ptiso30_2bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_ptiso30_2bin");
  int n_qcd_elec_nm1_rel_ptiso30_2bin = h_qcd_elec_nm1_rel_ptiso30_2bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_ptiso30_2bin = new TCanvas("tc_elec_nm1_rel_ptiso30_2bin","tc_elec_nm1_rel_ptiso30_2bin",0,0,1920,1200);
  tc_elec_nm1_rel_ptiso30_2bin->cd();

  h_qcd_elec_nm1_rel_ptiso30_2bin->Scale(1/h_qcd_elec_nm1_rel_ptiso30_2bin->Integral());
  h_qcd_elec_nm1_rel_ptiso30_2bin->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_ptiso30_2bin->GetXaxis()->SetTitle("elec_nm1_rel_ptiso30_2bin");
  h_qcd_elec_nm1_rel_ptiso30_2bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_ptiso30_2bin->Scale(1/h_bkgd_elec_nm1_rel_ptiso30_2bin->Integral());
  h_bkgd_elec_nm1_rel_ptiso30_2bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_ptiso30_2bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_ptiso30_2bin->SetFillColor(0);
  lgnd_elec_nm1_rel_ptiso30_2bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_ptiso30_2bin->AddEntry(h_qcd_elec_nm1_rel_ptiso30_2bin,"Qcd","L");
  lgnd_elec_nm1_rel_ptiso30_2bin->AddEntry(h_bkgd_elec_nm1_rel_ptiso30_2bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_ptiso30_2bin->Draw();
  
  tc_elec_nm1_rel_ptiso30_2bin->Update();
  
  TLine *elec_nm1_rel_ptiso30_2bin_cut = new TLine(0.14,tc_elec_nm1_rel_ptiso30_2bin->GetUymin(),0.14,tc_elec_nm1_rel_ptiso30_2bin->GetUymax());
  elec_nm1_rel_ptiso30_2bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_ptiso30_2bin_cut->Draw();

  tc_elec_nm1_rel_ptiso30_2bin->SetLogy();
  tc_elec_nm1_rel_ptiso30_2bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_ptiso30_2bin.png");

//////////////////////////////////////////////////
  // elec_nm1_rel_ptiso30_3bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_ptiso30_3bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_ptiso30_3bin");
  TH1F* h_qcd_elec_nm1_rel_ptiso30_3bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_ptiso30_3bin");
  int n_qcd_elec_nm1_rel_ptiso30_3bin = h_qcd_elec_nm1_rel_ptiso30_3bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_ptiso30_3bin = new TCanvas("tc_elec_nm1_rel_ptiso30_3bin","tc_elec_nm1_rel_ptiso30_3bin",0,0,1920,1200);
  tc_elec_nm1_rel_ptiso30_3bin->cd();

  h_qcd_elec_nm1_rel_ptiso30_3bin->Scale(1/h_qcd_elec_nm1_rel_ptiso30_3bin->Integral());
  h_qcd_elec_nm1_rel_ptiso30_3bin->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_ptiso30_3bin->GetXaxis()->SetTitle("elec_nm1_rel_ptiso30_3bin");
  h_qcd_elec_nm1_rel_ptiso30_3bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_ptiso30_3bin->Scale(1/h_bkgd_elec_nm1_rel_ptiso30_3bin->Integral());
  h_bkgd_elec_nm1_rel_ptiso30_3bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_ptiso30_3bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_ptiso30_3bin->SetFillColor(0);
  lgnd_elec_nm1_rel_ptiso30_3bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_ptiso30_3bin->AddEntry(h_qcd_elec_nm1_rel_ptiso30_3bin,"QCD","L");
  lgnd_elec_nm1_rel_ptiso30_3bin->AddEntry(h_bkgd_elec_nm1_rel_ptiso30_3bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_ptiso30_3bin->Draw();
  
  tc_elec_nm1_rel_ptiso30_3bin->Update();
  
  TLine *elec_nm1_rel_ptiso30_3bin_cut = new TLine(0.14,tc_elec_nm1_rel_ptiso30_3bin->GetUymin(),0.14,tc_elec_nm1_rel_ptiso30_3bin->GetUymax());
  elec_nm1_rel_ptiso30_3bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_ptiso30_3bin_cut->Draw();

  tc_elec_nm1_rel_ptiso30_3bin->SetLogy();
  tc_elec_nm1_rel_ptiso30_3bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_ptiso30_3bin.png");



  //////////////////////////////////////////////////
  // elec_nm1_rel_etiso20
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_etiso20 = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_etiso20");
  TH1F* h_qcd_elec_nm1_rel_etiso20 = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_etiso20");
  int n_qcd_elec_nm1_rel_etiso20 = h_qcd_elec_nm1_rel_etiso20->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_etiso20 = new TCanvas("tc_elec_nm1_rel_etiso20","tc_elec_nm1_rel_etiso20",0,0,1920,1200);
  tc_elec_nm1_rel_etiso20->cd();

  h_bkgd_elec_nm1_rel_etiso20->Scale(1/h_bkgd_elec_nm1_rel_etiso20->Integral());
  h_bkgd_elec_nm1_rel_etiso20->SetLineColor(kBlack);
  h_bkgd_elec_nm1_rel_etiso20->GetXaxis()->SetTitle("elec_nm1_rel_etiso20");
  h_bkgd_elec_nm1_rel_etiso20->Draw("HIST");
  h_qcd_elec_nm1_rel_etiso20->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_etiso20->Scale(1/h_qcd_elec_nm1_rel_etiso20->Integral());
  h_qcd_elec_nm1_rel_etiso20->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_etiso20 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_etiso20->SetFillColor(0);
  lgnd_elec_nm1_rel_etiso20->SetTextSize(0.03);
  lgnd_elec_nm1_rel_etiso20->AddEntry(h_qcd_elec_nm1_rel_etiso20,"Qcd","L");
  lgnd_elec_nm1_rel_etiso20->AddEntry(h_bkgd_elec_nm1_rel_etiso20,"Backgrounds","L");
  lgnd_elec_nm1_rel_etiso20->Draw();
  
  tc_elec_nm1_rel_etiso20->Update();
  
  TLine *elec_nm1_rel_etiso20_cut = new TLine(0.14,tc_elec_nm1_rel_etiso20->GetUymin(),0.14,tc_elec_nm1_rel_etiso20->GetUymax());
  elec_nm1_rel_etiso20_cut->SetLineColor(kBlue);
  elec_nm1_rel_etiso20_cut->Draw();

  tc_elec_nm1_rel_etiso20->SetLogy();
  tc_elec_nm1_rel_etiso20->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_etiso20.png");


  //////////////////////////////////////////////////
  // elec_nm1_rel_etiso20_0bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_etiso20_0bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_etiso20_0bin");
  TH1F* h_qcd_elec_nm1_rel_etiso20_0bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_etiso20_0bin");

  int n_qcd_elec_nm1_rel_etiso20_0bin = h_qcd_elec_nm1_rel_etiso20_0bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_etiso20_0bin = new TCanvas("tc_elec_nm1_rel_etiso20_0bin","tc_elec_nm1_rel_etiso20_0bin",0,0,1920,1200);
  tc_elec_nm1_rel_etiso20_0bin->cd();

  h_bkgd_elec_nm1_rel_etiso20_0bin->Scale(1/h_bkgd_elec_nm1_rel_etiso20_0bin->Integral());
  //  h_bkgd_elec_nm1_rel_etiso20_0bin->SetLineColor(kRed);
  h_bkgd_elec_nm1_rel_etiso20_0bin->GetXaxis()->SetTitle("elec_nm1_rel_etiso20_0bin");
  h_bkgd_elec_nm1_rel_etiso20_0bin->Draw("HIST");
  h_qcd_elec_nm1_rel_etiso20_0bin->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_etiso20_0bin->Scale(1/h_qcd_elec_nm1_rel_etiso20_0bin->Integral());
  h_qcd_elec_nm1_rel_etiso20_0bin->Draw("HIST sames");


  TLegend* lgnd_elec_nm1_rel_etiso20_0bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_etiso20_0bin->SetFillColor(0);
  lgnd_elec_nm1_rel_etiso20_0bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_etiso20_0bin->AddEntry(h_qcd_elec_nm1_rel_etiso20_0bin,"Qcd","L");
  lgnd_elec_nm1_rel_etiso20_0bin->AddEntry(h_bkgd_elec_nm1_rel_etiso20_0bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_etiso20_0bin->Draw();
  
  tc_elec_nm1_rel_etiso20_0bin->Update();
  
  TLine *elec_nm1_rel_etiso20_0bin_cut = new TLine(0.14,tc_elec_nm1_rel_etiso20_0bin->GetUymin(),0.14,tc_elec_nm1_rel_etiso20_0bin->GetUymax());
  elec_nm1_rel_etiso20_0bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_etiso20_0bin_cut->Draw();

  tc_elec_nm1_rel_etiso20_0bin->SetLogy();
  tc_elec_nm1_rel_etiso20_0bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_etiso20_0bin.png");


  //////////////////////////////////////////////////
  // elec_nm1_rel_etiso20_1bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_etiso20_1bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_etiso20_1bin");
  TH1F* h_qcd_elec_nm1_rel_etiso20_1bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_etiso20_1bin");
  int n_qcd_elec_nm1_rel_etiso20_1bin = h_qcd_elec_nm1_rel_etiso20_1bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_etiso20_1bin = new TCanvas("tc_elec_nm1_rel_etiso20_1bin","tc_elec_nm1_rel_etiso20_1bin",0,0,1920,1200);
  tc_elec_nm1_rel_etiso20_1bin->cd();

  h_qcd_elec_nm1_rel_etiso20_1bin->Scale(1/h_qcd_elec_nm1_rel_etiso20_1bin->Integral());
  h_qcd_elec_nm1_rel_etiso20_1bin->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_etiso20_1bin->GetXaxis()->SetTitle("elec_nm1_rel_etiso20_1bin");
  h_qcd_elec_nm1_rel_etiso20_1bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_etiso20_1bin->Scale(1/h_bkgd_elec_nm1_rel_etiso20_1bin->Integral());
  h_bkgd_elec_nm1_rel_etiso20_1bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_etiso20_1bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_etiso20_1bin->SetFillColor(0);
  lgnd_elec_nm1_rel_etiso20_1bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_etiso20_1bin->AddEntry(h_qcd_elec_nm1_rel_etiso20_1bin,"Qcd","L");
  lgnd_elec_nm1_rel_etiso20_1bin->AddEntry(h_bkgd_elec_nm1_rel_etiso20_1bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_etiso20_1bin->Draw();
  
  tc_elec_nm1_rel_etiso20_1bin->Update();
  
  TLine *elec_nm1_rel_etiso20_1bin_cut = new TLine(0.14,tc_elec_nm1_rel_etiso20_1bin->GetUymin(),0.14,tc_elec_nm1_rel_etiso20_1bin->GetUymax());
  elec_nm1_rel_etiso20_1bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_etiso20_1bin_cut->Draw();

  tc_elec_nm1_rel_etiso20_1bin->SetLogy();
  tc_elec_nm1_rel_etiso20_1bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_etiso20_1bin.png");

//////////////////////////////////////////////////
  // elec_nm1_rel_etiso20_2bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_etiso20_2bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_etiso20_2bin");
  TH1F* h_qcd_elec_nm1_rel_etiso20_2bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_etiso20_2bin");
  int n_qcd_elec_nm1_rel_etiso20_2bin = h_qcd_elec_nm1_rel_etiso20_2bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_etiso20_2bin = new TCanvas("tc_elec_nm1_rel_etiso20_2bin","tc_elec_nm1_rel_etiso20_2bin",0,0,1920,1200);
  tc_elec_nm1_rel_etiso20_2bin->cd();

  h_qcd_elec_nm1_rel_etiso20_2bin->Scale(1/h_qcd_elec_nm1_rel_etiso20_2bin->Integral());
  h_qcd_elec_nm1_rel_etiso20_2bin->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_etiso20_2bin->GetXaxis()->SetTitle("elec_nm1_rel_etiso20_2bin");
  h_qcd_elec_nm1_rel_etiso20_2bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_etiso20_2bin->Scale(1/h_bkgd_elec_nm1_rel_etiso20_2bin->Integral());
  h_bkgd_elec_nm1_rel_etiso20_2bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_etiso20_2bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_etiso20_2bin->SetFillColor(0);
  lgnd_elec_nm1_rel_etiso20_2bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_etiso20_2bin->AddEntry(h_qcd_elec_nm1_rel_etiso20_2bin,"Qcd","L");
  lgnd_elec_nm1_rel_etiso20_2bin->AddEntry(h_bkgd_elec_nm1_rel_etiso20_2bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_etiso20_2bin->Draw();
  
  tc_elec_nm1_rel_etiso20_2bin->Update();
  
  TLine *elec_nm1_rel_etiso20_2bin_cut = new TLine(0.14,tc_elec_nm1_rel_etiso20_2bin->GetUymin(),0.14,tc_elec_nm1_rel_etiso20_2bin->GetUymax());
  elec_nm1_rel_etiso20_2bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_etiso20_2bin_cut->Draw();

  tc_elec_nm1_rel_etiso20_2bin->SetLogy();
  tc_elec_nm1_rel_etiso20_2bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_etiso20_2bin.png");

//////////////////////////////////////////////////
  // elec_nm1_rel_etiso20_3bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_etiso20_3bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_etiso20_3bin");
  TH1F* h_qcd_elec_nm1_rel_etiso20_3bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_etiso20_3bin");
  int n_qcd_elec_nm1_rel_etiso20_3bin = h_qcd_elec_nm1_rel_etiso20_3bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_etiso20_3bin = new TCanvas("tc_elec_nm1_rel_etiso20_3bin","tc_elec_nm1_rel_etiso20_3bin",0,0,1920,1200);
  tc_elec_nm1_rel_etiso20_3bin->cd();

  h_qcd_elec_nm1_rel_etiso20_3bin->Scale(1/h_qcd_elec_nm1_rel_etiso20_3bin->Integral());
  h_qcd_elec_nm1_rel_etiso20_3bin->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_etiso20_3bin->GetXaxis()->SetTitle("elec_nm1_rel_etiso20_3bin");
  h_qcd_elec_nm1_rel_etiso20_3bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_etiso20_3bin->Scale(1/h_bkgd_elec_nm1_rel_etiso20_3bin->Integral());
  h_bkgd_elec_nm1_rel_etiso20_3bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_etiso20_3bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_etiso20_3bin->SetFillColor(0);
  lgnd_elec_nm1_rel_etiso20_3bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_etiso20_3bin->AddEntry(h_qcd_elec_nm1_rel_etiso20_3bin,"QCD","L");
  lgnd_elec_nm1_rel_etiso20_3bin->AddEntry(h_bkgd_elec_nm1_rel_etiso20_3bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_etiso20_3bin->Draw();
  
  tc_elec_nm1_rel_etiso20_3bin->Update();
  
  TLine *elec_nm1_rel_etiso20_3bin_cut = new TLine(0.14,tc_elec_nm1_rel_etiso20_3bin->GetUymin(),0.14,tc_elec_nm1_rel_etiso20_3bin->GetUymax());
  elec_nm1_rel_etiso20_3bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_etiso20_3bin_cut->Draw();

  tc_elec_nm1_rel_etiso20_3bin->SetLogy();
  tc_elec_nm1_rel_etiso20_3bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_etiso20_3bin.png");


  //////////////////////////////////////////////////
  // elec_nm1_etiso20
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_etiso20 = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_etiso20");
  TH1F* h_qcd_elec_nm1_etiso20 = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_etiso20");
  int n_qcd_elec_nm1_etiso20 = h_qcd_elec_nm1_etiso20->GetEntries();
  
  TCanvas* tc_elec_nm1_etiso20 = new TCanvas("tc_elec_nm1_etiso20","tc_elec_nm1_etiso20",0,0,1920,1200);
  tc_elec_nm1_etiso20->cd();

  h_bkgd_elec_nm1_etiso20->Scale(1/h_bkgd_elec_nm1_etiso20->Integral());
  h_bkgd_elec_nm1_etiso20->SetLineColor(kRed);
  h_bkgd_elec_nm1_etiso20->GetXaxis()->SetTitle("elec_nm1_etiso20");
  h_bkgd_elec_nm1_etiso20->Draw("HIST");
  h_qcd_elec_nm1_etiso20->Scale(1/h_qcd_elec_nm1_etiso20->Integral());
  h_qcd_elec_nm1_etiso20->Draw("HIST sames");


  TLegend* lgnd_elec_nm1_etiso20 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_etiso20->SetFillColor(0);
  lgnd_elec_nm1_etiso20->SetTextSize(0.03);
  lgnd_elec_nm1_etiso20->AddEntry(h_qcd_elec_nm1_etiso20,"Qcd","L");
  lgnd_elec_nm1_etiso20->AddEntry(h_bkgd_elec_nm1_etiso20,"Backgrounds","L");
  lgnd_elec_nm1_etiso20->Draw();
  
  tc_elec_nm1_etiso20->Update();
  
  TLine *elec_nm1_etiso20_cut = new TLine(0.14,tc_elec_nm1_etiso20->GetUymin(),0.14,tc_elec_nm1_etiso20->GetUymax());
  elec_nm1_etiso20_cut->SetLineColor(kBlue);
  elec_nm1_etiso20_cut->Draw();

  tc_elec_nm1_etiso20->SetLogy();
  tc_elec_nm1_etiso20->SaveAs("../canvases/latest/h_qcd_elec_nm1_etiso20.png");


  //////////////////////////////////////////////////
  // elec_nm1_etiso20_0bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_etiso20_0bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_etiso20_0bin");
  TH1F* h_qcd_elec_nm1_etiso20_0bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_etiso20_0bin");

  int n_qcd_elec_nm1_etiso20_0bin = h_qcd_elec_nm1_etiso20_0bin->GetEntries();
  
  TCanvas* tc_elec_nm1_etiso20_0bin = new TCanvas("tc_elec_nm1_etiso20_0bin","tc_elec_nm1_etiso20_0bin",0,0,1920,1200);
  tc_elec_nm1_etiso20_0bin->cd();

  h_qcd_elec_nm1_etiso20_0bin->Scale(1/h_qcd_elec_nm1_etiso20_0bin->Integral());
  h_qcd_elec_nm1_etiso20_0bin->SetLineColor(kRed);
  h_qcd_elec_nm1_etiso20_0bin->GetXaxis()->SetTitle("elec_nm1_etiso20_0bin");
  h_qcd_elec_nm1_etiso20_0bin->Draw("HIST");
  h_bkgd_elec_nm1_etiso20_0bin->Scale(1/h_bkgd_elec_nm1_etiso20_0bin->Integral());
  h_bkgd_elec_nm1_etiso20_0bin->Draw("HIST sames");


  TLegend* lgnd_elec_nm1_etiso20_0bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_etiso20_0bin->SetFillColor(0);
  lgnd_elec_nm1_etiso20_0bin->SetTextSize(0.03);
  lgnd_elec_nm1_etiso20_0bin->AddEntry(h_qcd_elec_nm1_etiso20_0bin,"Qcd","L");
  lgnd_elec_nm1_etiso20_0bin->AddEntry(h_bkgd_elec_nm1_etiso20_0bin,"Backgrounds","L");
  lgnd_elec_nm1_etiso20_0bin->Draw();
  
  tc_elec_nm1_etiso20_0bin->Update();
  
  TLine *elec_nm1_etiso20_0bin_cut = new TLine(0.14,tc_elec_nm1_etiso20_0bin->GetUymin(),0.14,tc_elec_nm1_etiso20_0bin->GetUymax());
  elec_nm1_etiso20_0bin_cut->SetLineColor(kBlue);
  elec_nm1_etiso20_0bin_cut->Draw();

  tc_elec_nm1_etiso20_0bin->SetLogy();
  tc_elec_nm1_etiso20_0bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_etiso20_0bin.png");


  //////////////////////////////////////////////////
  // elec_nm1_etiso20_1bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_etiso20_1bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_etiso20_1bin");
  TH1F* h_qcd_elec_nm1_etiso20_1bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_etiso20_1bin");
  int n_qcd_elec_nm1_etiso20_1bin = h_qcd_elec_nm1_etiso20_1bin->GetEntries();
  
  TCanvas* tc_elec_nm1_etiso20_1bin = new TCanvas("tc_elec_nm1_etiso20_1bin","tc_elec_nm1_etiso20_1bin",0,0,1920,1200);
  tc_elec_nm1_etiso20_1bin->cd();

  h_qcd_elec_nm1_etiso20_1bin->Scale(1/h_qcd_elec_nm1_etiso20_1bin->Integral());
  h_qcd_elec_nm1_etiso20_1bin->SetLineColor(kRed);
  h_qcd_elec_nm1_etiso20_1bin->GetXaxis()->SetTitle("elec_nm1_etiso20_1bin");
  h_qcd_elec_nm1_etiso20_1bin->Draw("HIST");
  h_bkgd_elec_nm1_etiso20_1bin->Scale(1/h_bkgd_elec_nm1_etiso20_1bin->Integral());
  h_bkgd_elec_nm1_etiso20_1bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_etiso20_1bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_etiso20_1bin->SetFillColor(0);
  lgnd_elec_nm1_etiso20_1bin->SetTextSize(0.03);
  lgnd_elec_nm1_etiso20_1bin->AddEntry(h_qcd_elec_nm1_etiso20_1bin,"Qcd","L");
  lgnd_elec_nm1_etiso20_1bin->AddEntry(h_bkgd_elec_nm1_etiso20_1bin,"Backgrounds","L");
  lgnd_elec_nm1_etiso20_1bin->Draw();
  
  tc_elec_nm1_etiso20_1bin->Update();
  
  TLine *elec_nm1_etiso20_1bin_cut = new TLine(0.14,tc_elec_nm1_etiso20_1bin->GetUymin(),0.14,tc_elec_nm1_etiso20_1bin->GetUymax());
  elec_nm1_etiso20_1bin_cut->SetLineColor(kBlue);
  elec_nm1_etiso20_1bin_cut->Draw();

  tc_elec_nm1_etiso20_1bin->SetLogy();
  tc_elec_nm1_etiso20_1bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_etiso20_1bin.png");

//////////////////////////////////////////////////
  // elec_nm1_etiso20_2bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_etiso20_2bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_etiso20_2bin");
  TH1F* h_qcd_elec_nm1_etiso20_2bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_etiso20_2bin");
  int n_qcd_elec_nm1_etiso20_2bin = h_qcd_elec_nm1_etiso20_2bin->GetEntries();
  
  TCanvas* tc_elec_nm1_etiso20_2bin = new TCanvas("tc_elec_nm1_etiso20_2bin","tc_elec_nm1_etiso20_2bin",0,0,1920,1200);
  tc_elec_nm1_etiso20_2bin->cd();

  h_qcd_elec_nm1_etiso20_2bin->Scale(1/h_qcd_elec_nm1_etiso20_2bin->Integral());
  h_qcd_elec_nm1_etiso20_2bin->SetLineColor(kRed);
  h_qcd_elec_nm1_etiso20_2bin->GetXaxis()->SetTitle("elec_nm1_etiso20_2bin");
  h_qcd_elec_nm1_etiso20_2bin->Draw("HIST");
  h_bkgd_elec_nm1_etiso20_2bin->Scale(1/h_bkgd_elec_nm1_etiso20_2bin->Integral());
  h_bkgd_elec_nm1_etiso20_2bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_etiso20_2bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_etiso20_2bin->SetFillColor(0);
  lgnd_elec_nm1_etiso20_2bin->SetTextSize(0.03);
  lgnd_elec_nm1_etiso20_2bin->AddEntry(h_qcd_elec_nm1_etiso20_2bin,"Qcd","L");
  lgnd_elec_nm1_etiso20_2bin->AddEntry(h_bkgd_elec_nm1_etiso20_2bin,"Backgrounds","L");
  lgnd_elec_nm1_etiso20_2bin->Draw();
  
  tc_elec_nm1_etiso20_2bin->Update();
  
  TLine *elec_nm1_etiso20_2bin_cut = new TLine(0.14,tc_elec_nm1_etiso20_2bin->GetUymin(),0.14,tc_elec_nm1_etiso20_2bin->GetUymax());
  elec_nm1_etiso20_2bin_cut->SetLineColor(kBlue);
  elec_nm1_etiso20_2bin_cut->Draw();

  tc_elec_nm1_etiso20_2bin->SetLogy();
  tc_elec_nm1_etiso20_2bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_etiso20_2bin.png");

//////////////////////////////////////////////////
  // elec_nm1_etiso20_3bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_etiso20_3bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_etiso20_3bin");
  TH1F* h_qcd_elec_nm1_etiso20_3bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_etiso20_3bin");
  int n_qcd_elec_nm1_etiso20_3bin = h_qcd_elec_nm1_etiso20_3bin->GetEntries();
  
  TCanvas* tc_elec_nm1_etiso20_3bin = new TCanvas("tc_elec_nm1_etiso20_3bin","tc_elec_nm1_etiso20_3bin",0,0,1920,1200);
  tc_elec_nm1_etiso20_3bin->cd();

  h_qcd_elec_nm1_etiso20_3bin->Scale(1/h_qcd_elec_nm1_etiso20_3bin->Integral());
  h_qcd_elec_nm1_etiso20_3bin->SetLineColor(kRed);
  h_qcd_elec_nm1_etiso20_3bin->GetXaxis()->SetTitle("elec_nm1_etiso20_3bin");
  h_qcd_elec_nm1_etiso20_3bin->Draw("HIST");
  h_bkgd_elec_nm1_etiso20_3bin->Scale(1/h_bkgd_elec_nm1_etiso20_3bin->Integral());
  h_bkgd_elec_nm1_etiso20_3bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_etiso20_3bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_etiso20_3bin->SetFillColor(0);
  lgnd_elec_nm1_etiso20_3bin->SetTextSize(0.03);
  lgnd_elec_nm1_etiso20_3bin->AddEntry(h_qcd_elec_nm1_etiso20_3bin,"QCD","L");
  lgnd_elec_nm1_etiso20_3bin->AddEntry(h_bkgd_elec_nm1_etiso20_3bin,"Backgrounds","L");
  lgnd_elec_nm1_etiso20_3bin->Draw();
  
  tc_elec_nm1_etiso20_3bin->Update();
  
  TLine *elec_nm1_etiso20_3bin_cut = new TLine(0.14,tc_elec_nm1_etiso20_3bin->GetUymin(),0.14,tc_elec_nm1_etiso20_3bin->GetUymax());
  elec_nm1_etiso20_3bin_cut->SetLineColor(kBlue);
  elec_nm1_etiso20_3bin_cut->Draw();

  tc_elec_nm1_etiso20_3bin->SetLogy();
  tc_elec_nm1_etiso20_3bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_etiso20_3bin.png");



  //////////////////////////////////////////////////
  // elec_nm1_ptiso20
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_ptiso20 = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_ptiso20");
  TH1F* h_qcd_elec_nm1_ptiso20 = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_ptiso20");
  int n_qcd_elec_nm1_ptiso20 = h_qcd_elec_nm1_ptiso20->GetEntries();
  
  TCanvas* tc_elec_nm1_ptiso20 = new TCanvas("tc_elec_nm1_ptiso20","tc_elec_nm1_ptiso20",0,0,1920,1200);
  tc_elec_nm1_ptiso20->cd();

  h_qcd_elec_nm1_ptiso20->Scale(1/h_qcd_elec_nm1_ptiso20->Integral());
  h_qcd_elec_nm1_ptiso20->SetLineColor(kRed);
  h_qcd_elec_nm1_ptiso20->GetXaxis()->SetTitle("elec_nm1_ptiso20");
  h_qcd_elec_nm1_ptiso20->Draw("HIST");
  h_bkgd_elec_nm1_ptiso20->Scale(1/h_bkgd_elec_nm1_ptiso20->Integral());
  h_bkgd_elec_nm1_ptiso20->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_ptiso20 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_ptiso20->SetFillColor(0);
  lgnd_elec_nm1_ptiso20->SetTextSize(0.03);
  lgnd_elec_nm1_ptiso20->AddEntry(h_qcd_elec_nm1_ptiso20,"Qcd","L");
  lgnd_elec_nm1_ptiso20->AddEntry(h_bkgd_elec_nm1_ptiso20,"Backgrounds","L");
  lgnd_elec_nm1_ptiso20->Draw();
  
  tc_elec_nm1_ptiso20->Update();

  tc_elec_nm1_ptiso20->SetLogy();
  tc_elec_nm1_ptiso20->SaveAs("../canvases/latest/h_qcd_elec_nm1_ptiso20.png");


  
  //////////////////////////////////////////////////
  // elec_nm1_ptiso20_0bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_ptiso20_0bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_ptiso20_0bin");
  TH1F* h_qcd_elec_nm1_ptiso20_0bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_ptiso20_0bin");
  int n_qcd_elec_nm1_ptiso20_0bin = h_qcd_elec_nm1_ptiso20_0bin->GetEntries();
  
  TCanvas* tc_elec_nm1_ptiso20_0bin = new TCanvas("tc_elec_nm1_ptiso20_0bin","tc_elec_nm1_ptiso20_0bin",0,0,1920,1200);
  tc_elec_nm1_ptiso20_0bin->cd();

  h_qcd_elec_nm1_ptiso20_0bin->Scale(1/h_qcd_elec_nm1_ptiso20_0bin->Integral());
  h_qcd_elec_nm1_ptiso20_0bin->SetLineColor(kRed);
  h_qcd_elec_nm1_ptiso20_0bin->GetXaxis()->SetTitle("elec_nm1_ptiso20_0bin");
  h_qcd_elec_nm1_ptiso20_0bin->Draw("HIST");
  h_bkgd_elec_nm1_ptiso20_0bin->Scale(1/h_bkgd_elec_nm1_ptiso20_0bin->Integral());
  h_bkgd_elec_nm1_ptiso20_0bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_ptiso20_0bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_ptiso20_0bin->SetFillColor(0);
  lgnd_elec_nm1_ptiso20_0bin->SetTextSize(0.03);
  lgnd_elec_nm1_ptiso20_0bin->AddEntry(h_qcd_elec_nm1_ptiso20_0bin,"Qcd","L");
  lgnd_elec_nm1_ptiso20_0bin->AddEntry(h_bkgd_elec_nm1_ptiso20_0bin,"Backgrounds","L");
  lgnd_elec_nm1_ptiso20_0bin->Draw();
  
  tc_elec_nm1_ptiso20_0bin->Update();
  
  TLine *elec_nm1_ptiso20_0bin_cut = new TLine(0.14,tc_elec_nm1_ptiso20_0bin->GetUymin(),0.14,tc_elec_nm1_ptiso20_0bin->GetUymax());
  elec_nm1_ptiso20_0bin_cut->SetLineColor(kBlue);
  elec_nm1_ptiso20_0bin_cut->Draw();

  tc_elec_nm1_ptiso20_0bin->SetLogy();
  tc_elec_nm1_ptiso20_0bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_ptiso20_0bin.png");
  
  


  //////////////////////////////////////////////////
  // elec_nm1_ptiso20_1bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_ptiso20_1bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_ptiso20_1bin");
  TH1F* h_qcd_elec_nm1_ptiso20_1bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_ptiso20_1bin");
  int n_qcd_elec_nm1_ptiso20_1bin = h_qcd_elec_nm1_ptiso20_1bin->GetEntries();
  
  TCanvas* tc_elec_nm1_ptiso20_1bin = new TCanvas("tc_elec_nm1_ptiso20_1bin","tc_elec_nm1_ptiso20_1bin",0,0,1920,1200);
  tc_elec_nm1_ptiso20_1bin->cd();

  h_qcd_elec_nm1_ptiso20_1bin->Scale(1/h_qcd_elec_nm1_ptiso20_1bin->Integral());
  h_qcd_elec_nm1_ptiso20_1bin->SetLineColor(kRed);
  h_qcd_elec_nm1_ptiso20_1bin->GetXaxis()->SetTitle("elec_nm1_ptiso20_1bin");
  h_qcd_elec_nm1_ptiso20_1bin->Draw("HIST");
  h_bkgd_elec_nm1_ptiso20_1bin->Scale(1/h_bkgd_elec_nm1_ptiso20_1bin->Integral());
  h_bkgd_elec_nm1_ptiso20_1bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_ptiso20_1bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_ptiso20_1bin->SetFillColor(0);
  lgnd_elec_nm1_ptiso20_1bin->SetTextSize(0.03);
  lgnd_elec_nm1_ptiso20_1bin->AddEntry(h_qcd_elec_nm1_ptiso20_1bin,"Qcd","L");
  lgnd_elec_nm1_ptiso20_1bin->AddEntry(h_bkgd_elec_nm1_ptiso20_1bin,"Backgrounds","L");
  lgnd_elec_nm1_ptiso20_1bin->Draw();
  
  tc_elec_nm1_ptiso20_1bin->Update();
  
  TLine *elec_nm1_ptiso20_1bin_cut = new TLine(0.14,tc_elec_nm1_ptiso20_1bin->GetUymin(),0.14,tc_elec_nm1_ptiso20_1bin->GetUymax());
  elec_nm1_ptiso20_1bin_cut->SetLineColor(kBlue);
  elec_nm1_ptiso20_1bin_cut->Draw();

  tc_elec_nm1_ptiso20_1bin->SetLogy();
  tc_elec_nm1_ptiso20_1bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_ptiso20_1bin.png");

//////////////////////////////////////////////////
  // elec_nm1_ptiso20_2bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_ptiso20_2bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_ptiso20_2bin");
  TH1F* h_qcd_elec_nm1_ptiso20_2bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_ptiso20_2bin");
  int n_qcd_elec_nm1_ptiso20_2bin = h_qcd_elec_nm1_ptiso20_2bin->GetEntries();
  
  TCanvas* tc_elec_nm1_ptiso20_2bin = new TCanvas("tc_elec_nm1_ptiso20_2bin","tc_elec_nm1_ptiso20_2bin",0,0,1920,1200);
  tc_elec_nm1_ptiso20_2bin->cd();

  h_qcd_elec_nm1_ptiso20_2bin->Scale(1/h_qcd_elec_nm1_ptiso20_2bin->Integral());
  h_qcd_elec_nm1_ptiso20_2bin->SetLineColor(kRed);
  h_qcd_elec_nm1_ptiso20_2bin->GetXaxis()->SetTitle("elec_nm1_ptiso20_2bin");
  h_qcd_elec_nm1_ptiso20_2bin->Draw("HIST");
  h_bkgd_elec_nm1_ptiso20_2bin->Scale(1/h_bkgd_elec_nm1_ptiso20_2bin->Integral());
  h_bkgd_elec_nm1_ptiso20_2bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_ptiso20_2bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_ptiso20_2bin->SetFillColor(0);
  lgnd_elec_nm1_ptiso20_2bin->SetTextSize(0.03);
  lgnd_elec_nm1_ptiso20_2bin->AddEntry(h_qcd_elec_nm1_ptiso20_2bin,"Qcd","L");
  lgnd_elec_nm1_ptiso20_2bin->AddEntry(h_bkgd_elec_nm1_ptiso20_2bin,"Backgrounds","L");
  lgnd_elec_nm1_ptiso20_2bin->Draw();
  
  tc_elec_nm1_ptiso20_2bin->Update();
  
  TLine *elec_nm1_ptiso20_2bin_cut = new TLine(0.14,tc_elec_nm1_ptiso20_2bin->GetUymin(),0.14,tc_elec_nm1_ptiso20_2bin->GetUymax());
  elec_nm1_ptiso20_2bin_cut->SetLineColor(kBlue);
  elec_nm1_ptiso20_2bin_cut->Draw();

  tc_elec_nm1_ptiso20_2bin->SetLogy();
  tc_elec_nm1_ptiso20_2bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_ptiso20_2bin.png");

//////////////////////////////////////////////////
  // elec_nm1_ptiso20_3bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_ptiso20_3bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_ptiso20_3bin");
  TH1F* h_qcd_elec_nm1_ptiso20_3bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_ptiso20_3bin");
  int n_qcd_elec_nm1_ptiso20_3bin = h_qcd_elec_nm1_ptiso20_3bin->GetEntries();
  
  TCanvas* tc_elec_nm1_ptiso20_3bin = new TCanvas("tc_elec_nm1_ptiso20_3bin","tc_elec_nm1_ptiso20_3bin",0,0,1920,1200);
  tc_elec_nm1_ptiso20_3bin->cd();

  h_qcd_elec_nm1_ptiso20_3bin->Scale(1/h_qcd_elec_nm1_ptiso20_3bin->Integral());
  h_qcd_elec_nm1_ptiso20_3bin->SetLineColor(kRed);
  h_qcd_elec_nm1_ptiso20_3bin->GetXaxis()->SetTitle("elec_nm1_ptiso20_3bin");
  h_qcd_elec_nm1_ptiso20_3bin->Draw("HIST");
  h_bkgd_elec_nm1_ptiso20_3bin->Scale(1/h_bkgd_elec_nm1_ptiso20_3bin->Integral());
  h_bkgd_elec_nm1_ptiso20_3bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_ptiso20_3bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_ptiso20_3bin->SetFillColor(0);
  lgnd_elec_nm1_ptiso20_3bin->SetTextSize(0.03);
  lgnd_elec_nm1_ptiso20_3bin->AddEntry(h_qcd_elec_nm1_ptiso20_3bin,"QCD","L");
  lgnd_elec_nm1_ptiso20_3bin->AddEntry(h_bkgd_elec_nm1_ptiso20_3bin,"Backgrounds","L");
  lgnd_elec_nm1_ptiso20_3bin->Draw();
  
  tc_elec_nm1_ptiso20_3bin->Update();
  
  TLine *elec_nm1_ptiso20_3bin_cut = new TLine(0.14,tc_elec_nm1_ptiso20_3bin->GetUymin(),0.14,tc_elec_nm1_ptiso20_3bin->GetUymax());
  elec_nm1_ptiso20_3bin_cut->SetLineColor(kBlue);
  elec_nm1_ptiso20_3bin_cut->Draw();

  tc_elec_nm1_ptiso20_3bin->SetLogy();
  tc_elec_nm1_ptiso20_3bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_ptiso20_3bin.png");


  
  //////////////////////////////////////////////////
  // elec_nm1_rel_ptiso20
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_ptiso20 = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_ptiso20");
  TH1F* h_qcd_elec_nm1_rel_ptiso20 = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_ptiso20");
  int n_qcd_elec_nm1_rel_ptiso20 = h_qcd_elec_nm1_rel_ptiso20->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_ptiso20 = new TCanvas("tc_elec_nm1_rel_ptiso20","tc_elec_nm1_rel_ptiso20",0,0,1920,1200);
  tc_elec_nm1_rel_ptiso20->cd();

  h_bkgd_elec_nm1_rel_ptiso20->Scale(1/h_bkgd_elec_nm1_rel_ptiso20->Integral());
  //h_bkgd_elec_nm1_rel_ptiso20->SetLineColor(kRed);
  h_bkgd_elec_nm1_rel_ptiso20->GetXaxis()->SetTitle("elec_nm1_rel_ptiso20");
  h_bkgd_elec_nm1_rel_ptiso20->Draw("HIST");
  h_qcd_elec_nm1_rel_ptiso20->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_ptiso20->Scale(1/h_qcd_elec_nm1_rel_ptiso20->Integral());
  h_qcd_elec_nm1_rel_ptiso20->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_ptiso20 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_ptiso20->SetFillColor(0);
  lgnd_elec_nm1_rel_ptiso20->SetTextSize(0.03);
  lgnd_elec_nm1_rel_ptiso20->AddEntry(h_qcd_elec_nm1_rel_ptiso20,"Qcd","L");
  lgnd_elec_nm1_rel_ptiso20->AddEntry(h_bkgd_elec_nm1_rel_ptiso20,"Backgrounds","L");
  lgnd_elec_nm1_rel_ptiso20->Draw();
  
  tc_elec_nm1_rel_ptiso20->Update();
  
  TLine *elec_nm1_rel_ptiso20_cut = new TLine(0.14,tc_elec_nm1_rel_ptiso20->GetUymin(),0.14,tc_elec_nm1_rel_ptiso20->GetUymax());
  elec_nm1_rel_ptiso20_cut->SetLineColor(kBlue);
  elec_nm1_rel_ptiso20_cut->Draw();

  tc_elec_nm1_rel_ptiso20->SetLogy();
  tc_elec_nm1_rel_ptiso20->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_ptiso20.png");
  
  //////////////////////////////////////////////////
  // elec_nm1_rel_ptiso20_0bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_ptiso20_0bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_ptiso20_0bin");
  TH1F* h_qcd_elec_nm1_rel_ptiso20_0bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_ptiso20_0bin");
  int n_qcd_elec_nm1_rel_ptiso20_0bin = h_qcd_elec_nm1_rel_ptiso20_0bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_ptiso20_0bin = new TCanvas("tc_elec_nm1_rel_ptiso20_0bin","tc_elec_nm1_rel_ptiso20_0bin",0,0,1920,1200);
  tc_elec_nm1_rel_ptiso20_0bin->cd();

  h_qcd_elec_nm1_rel_ptiso20_0bin->Scale(1/h_qcd_elec_nm1_rel_ptiso20_0bin->Integral());
  h_qcd_elec_nm1_rel_ptiso20_0bin->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_ptiso20_0bin->GetXaxis()->SetTitle("elec_nm1_rel_ptiso20_0bin");
  h_qcd_elec_nm1_rel_ptiso20_0bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_ptiso20_0bin->Scale(1/h_bkgd_elec_nm1_rel_ptiso20_0bin->Integral());
  h_bkgd_elec_nm1_rel_ptiso20_0bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_ptiso20_0bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_ptiso20_0bin->SetFillColor(0);
  lgnd_elec_nm1_rel_ptiso20_0bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_ptiso20_0bin->AddEntry(h_qcd_elec_nm1_rel_ptiso20_0bin,"Qcd","L");
  lgnd_elec_nm1_rel_ptiso20_0bin->AddEntry(h_bkgd_elec_nm1_rel_ptiso20_0bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_ptiso20_0bin->Draw();
  
  tc_elec_nm1_rel_ptiso20_0bin->Update();
  
  TLine *elec_nm1_rel_ptiso20_0bin_cut = new TLine(0.14,tc_elec_nm1_rel_ptiso20_0bin->GetUymin(),0.14,tc_elec_nm1_rel_ptiso20_0bin->GetUymax());
  elec_nm1_rel_ptiso20_0bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_ptiso20_0bin_cut->Draw();

  tc_elec_nm1_rel_ptiso20_0bin->SetLogy();
  tc_elec_nm1_rel_ptiso20_0bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_ptiso20_0bin.png");
  
  


  //////////////////////////////////////////////////
  // elec_nm1_rel_ptiso20_1bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_ptiso20_1bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_ptiso20_1bin");
  TH1F* h_qcd_elec_nm1_rel_ptiso20_1bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_ptiso20_1bin");
  int n_qcd_elec_nm1_rel_ptiso20_1bin = h_qcd_elec_nm1_rel_ptiso20_1bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_ptiso20_1bin = new TCanvas("tc_elec_nm1_rel_ptiso20_1bin","tc_elec_nm1_rel_ptiso20_1bin",0,0,1920,1200);
  tc_elec_nm1_rel_ptiso20_1bin->cd();

  h_qcd_elec_nm1_rel_ptiso20_1bin->Scale(1/h_qcd_elec_nm1_rel_ptiso20_1bin->Integral());
  h_qcd_elec_nm1_rel_ptiso20_1bin->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_ptiso20_1bin->GetXaxis()->SetTitle("elec_nm1_rel_ptiso20_1bin");
  h_qcd_elec_nm1_rel_ptiso20_1bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_ptiso20_1bin->Scale(1/h_bkgd_elec_nm1_rel_ptiso20_1bin->Integral());
  h_bkgd_elec_nm1_rel_ptiso20_1bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_ptiso20_1bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_ptiso20_1bin->SetFillColor(0);
  lgnd_elec_nm1_rel_ptiso20_1bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_ptiso20_1bin->AddEntry(h_qcd_elec_nm1_rel_ptiso20_1bin,"Qcd","L");
  lgnd_elec_nm1_rel_ptiso20_1bin->AddEntry(h_bkgd_elec_nm1_rel_ptiso20_1bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_ptiso20_1bin->Draw();
  
  tc_elec_nm1_rel_ptiso20_1bin->Update();
  
  TLine *elec_nm1_rel_ptiso20_1bin_cut = new TLine(0.14,tc_elec_nm1_rel_ptiso20_1bin->GetUymin(),0.14,tc_elec_nm1_rel_ptiso20_1bin->GetUymax());
  elec_nm1_rel_ptiso20_1bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_ptiso20_1bin_cut->Draw();

  tc_elec_nm1_rel_ptiso20_1bin->SetLogy();
  tc_elec_nm1_rel_ptiso20_1bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_ptiso20_1bin.png");

//////////////////////////////////////////////////
  // elec_nm1_rel_ptiso20_2bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_ptiso20_2bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_ptiso20_2bin");
  TH1F* h_qcd_elec_nm1_rel_ptiso20_2bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_ptiso20_2bin");
  int n_qcd_elec_nm1_rel_ptiso20_2bin = h_qcd_elec_nm1_rel_ptiso20_2bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_ptiso20_2bin = new TCanvas("tc_elec_nm1_rel_ptiso20_2bin","tc_elec_nm1_rel_ptiso20_2bin",0,0,1920,1200);
  tc_elec_nm1_rel_ptiso20_2bin->cd();

  h_qcd_elec_nm1_rel_ptiso20_2bin->Scale(1/h_qcd_elec_nm1_rel_ptiso20_2bin->Integral());
  h_qcd_elec_nm1_rel_ptiso20_2bin->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_ptiso20_2bin->GetXaxis()->SetTitle("elec_nm1_rel_ptiso20_2bin");
  h_qcd_elec_nm1_rel_ptiso20_2bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_ptiso20_2bin->Scale(1/h_bkgd_elec_nm1_rel_ptiso20_2bin->Integral());
  h_bkgd_elec_nm1_rel_ptiso20_2bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_ptiso20_2bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_ptiso20_2bin->SetFillColor(0);
  lgnd_elec_nm1_rel_ptiso20_2bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_ptiso20_2bin->AddEntry(h_qcd_elec_nm1_rel_ptiso20_2bin,"Qcd","L");
  lgnd_elec_nm1_rel_ptiso20_2bin->AddEntry(h_bkgd_elec_nm1_rel_ptiso20_2bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_ptiso20_2bin->Draw();
  
  tc_elec_nm1_rel_ptiso20_2bin->Update();
  
  TLine *elec_nm1_rel_ptiso20_2bin_cut = new TLine(0.14,tc_elec_nm1_rel_ptiso20_2bin->GetUymin(),0.14,tc_elec_nm1_rel_ptiso20_2bin->GetUymax());
  elec_nm1_rel_ptiso20_2bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_ptiso20_2bin_cut->Draw();

  tc_elec_nm1_rel_ptiso20_2bin->SetLogy();
  tc_elec_nm1_rel_ptiso20_2bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_ptiso20_2bin.png");

//////////////////////////////////////////////////
  // elec_nm1_rel_ptiso20_3bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_ptiso20_3bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_ptiso20_3bin");
  TH1F* h_qcd_elec_nm1_rel_ptiso20_3bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_ptiso20_3bin");
  int n_qcd_elec_nm1_rel_ptiso20_3bin = h_qcd_elec_nm1_rel_ptiso20_3bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_ptiso20_3bin = new TCanvas("tc_elec_nm1_rel_ptiso20_3bin","tc_elec_nm1_rel_ptiso20_3bin",0,0,1920,1200);
  tc_elec_nm1_rel_ptiso20_3bin->cd();

  h_qcd_elec_nm1_rel_ptiso20_3bin->Scale(1/h_qcd_elec_nm1_rel_ptiso20_3bin->Integral());
  h_qcd_elec_nm1_rel_ptiso20_3bin->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_ptiso20_3bin->GetXaxis()->SetTitle("elec_nm1_rel_ptiso20_3bin");
  h_qcd_elec_nm1_rel_ptiso20_3bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_ptiso20_3bin->Scale(1/h_bkgd_elec_nm1_rel_ptiso20_3bin->Integral());
  h_bkgd_elec_nm1_rel_ptiso20_3bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_ptiso20_3bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_ptiso20_3bin->SetFillColor(0);
  lgnd_elec_nm1_rel_ptiso20_3bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_ptiso20_3bin->AddEntry(h_qcd_elec_nm1_rel_ptiso20_3bin,"QCD","L");
  lgnd_elec_nm1_rel_ptiso20_3bin->AddEntry(h_bkgd_elec_nm1_rel_ptiso20_3bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_ptiso20_3bin->Draw();
  
  tc_elec_nm1_rel_ptiso20_3bin->Update();
  
  TLine *elec_nm1_rel_ptiso20_3bin_cut = new TLine(0.14,tc_elec_nm1_rel_ptiso20_3bin->GetUymin(),0.14,tc_elec_nm1_rel_ptiso20_3bin->GetUymax());
  elec_nm1_rel_ptiso20_3bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_ptiso20_3bin_cut->Draw();

  tc_elec_nm1_rel_ptiso20_3bin->SetLogy();
  tc_elec_nm1_rel_ptiso20_3bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_ptiso20_3bin.png");



  //////////////////////////////////////////////////
  // elec_nm1_rel_etiso40
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_etiso40 = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_etiso40");
  TH1F* h_qcd_elec_nm1_rel_etiso40 = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_etiso40");
  int n_qcd_elec_nm1_rel_etiso40 = h_qcd_elec_nm1_rel_etiso40->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_etiso40 = new TCanvas("tc_elec_nm1_rel_etiso40","tc_elec_nm1_rel_etiso40",0,0,1920,1200);
  tc_elec_nm1_rel_etiso40->cd();

  h_bkgd_elec_nm1_rel_etiso40->Scale(1/h_bkgd_elec_nm1_rel_etiso40->Integral());
  h_bkgd_elec_nm1_rel_etiso40->SetLineColor(kBlack);
  h_bkgd_elec_nm1_rel_etiso40->GetXaxis()->SetTitle("elec_nm1_rel_etiso40");
  h_bkgd_elec_nm1_rel_etiso40->Draw("HIST");
  h_qcd_elec_nm1_rel_etiso40->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_etiso40->Scale(1/h_qcd_elec_nm1_rel_etiso40->Integral());
  h_qcd_elec_nm1_rel_etiso40->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_etiso40 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_etiso40->SetFillColor(0);
  lgnd_elec_nm1_rel_etiso40->SetTextSize(0.03);
  lgnd_elec_nm1_rel_etiso40->AddEntry(h_qcd_elec_nm1_rel_etiso40,"Qcd","L");
  lgnd_elec_nm1_rel_etiso40->AddEntry(h_bkgd_elec_nm1_rel_etiso40,"Backgrounds","L");
  lgnd_elec_nm1_rel_etiso40->Draw();
  
  tc_elec_nm1_rel_etiso40->Update();
  
  TLine *elec_nm1_rel_etiso40_cut = new TLine(0.14,tc_elec_nm1_rel_etiso40->GetUymin(),0.14,tc_elec_nm1_rel_etiso40->GetUymax());
  elec_nm1_rel_etiso40_cut->SetLineColor(kBlue);
  elec_nm1_rel_etiso40_cut->Draw();

  tc_elec_nm1_rel_etiso40->SetLogy();
  tc_elec_nm1_rel_etiso40->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_etiso40.png");


  //////////////////////////////////////////////////
  // elec_nm1_rel_etiso40_0bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_etiso40_0bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_etiso40_0bin");
  TH1F* h_qcd_elec_nm1_rel_etiso40_0bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_etiso40_0bin");

  int n_qcd_elec_nm1_rel_etiso40_0bin = h_qcd_elec_nm1_rel_etiso40_0bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_etiso40_0bin = new TCanvas("tc_elec_nm1_rel_etiso40_0bin","tc_elec_nm1_rel_etiso40_0bin",0,0,1920,1200);
  tc_elec_nm1_rel_etiso40_0bin->cd();

  h_bkgd_elec_nm1_rel_etiso40_0bin->Scale(1/h_bkgd_elec_nm1_rel_etiso40_0bin->Integral());
  //  h_bkgd_elec_nm1_rel_etiso40_0bin->SetLineColor(kRed);
  h_bkgd_elec_nm1_rel_etiso40_0bin->GetXaxis()->SetTitle("elec_nm1_rel_etiso40_0bin");
  h_bkgd_elec_nm1_rel_etiso40_0bin->Draw("HIST");
  h_qcd_elec_nm1_rel_etiso40_0bin->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_etiso40_0bin->Scale(1/h_qcd_elec_nm1_rel_etiso40_0bin->Integral());
  h_qcd_elec_nm1_rel_etiso40_0bin->Draw("HIST sames");


  TLegend* lgnd_elec_nm1_rel_etiso40_0bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_etiso40_0bin->SetFillColor(0);
  lgnd_elec_nm1_rel_etiso40_0bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_etiso40_0bin->AddEntry(h_qcd_elec_nm1_rel_etiso40_0bin,"Qcd","L");
  lgnd_elec_nm1_rel_etiso40_0bin->AddEntry(h_bkgd_elec_nm1_rel_etiso40_0bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_etiso40_0bin->Draw();
  
  tc_elec_nm1_rel_etiso40_0bin->Update();
  
  TLine *elec_nm1_rel_etiso40_0bin_cut = new TLine(0.14,tc_elec_nm1_rel_etiso40_0bin->GetUymin(),0.14,tc_elec_nm1_rel_etiso40_0bin->GetUymax());
  elec_nm1_rel_etiso40_0bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_etiso40_0bin_cut->Draw();

  tc_elec_nm1_rel_etiso40_0bin->SetLogy();
  tc_elec_nm1_rel_etiso40_0bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_etiso40_0bin.png");


  //////////////////////////////////////////////////
  // elec_nm1_rel_etiso40_1bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_etiso40_1bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_etiso40_1bin");
  TH1F* h_qcd_elec_nm1_rel_etiso40_1bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_etiso40_1bin");
  int n_qcd_elec_nm1_rel_etiso40_1bin = h_qcd_elec_nm1_rel_etiso40_1bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_etiso40_1bin = new TCanvas("tc_elec_nm1_rel_etiso40_1bin","tc_elec_nm1_rel_etiso40_1bin",0,0,1920,1200);
  tc_elec_nm1_rel_etiso40_1bin->cd();

  h_qcd_elec_nm1_rel_etiso40_1bin->Scale(1/h_qcd_elec_nm1_rel_etiso40_1bin->Integral());
  h_qcd_elec_nm1_rel_etiso40_1bin->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_etiso40_1bin->GetXaxis()->SetTitle("elec_nm1_rel_etiso40_1bin");
  h_qcd_elec_nm1_rel_etiso40_1bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_etiso40_1bin->Scale(1/h_bkgd_elec_nm1_rel_etiso40_1bin->Integral());
  h_bkgd_elec_nm1_rel_etiso40_1bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_etiso40_1bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_etiso40_1bin->SetFillColor(0);
  lgnd_elec_nm1_rel_etiso40_1bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_etiso40_1bin->AddEntry(h_qcd_elec_nm1_rel_etiso40_1bin,"Qcd","L");
  lgnd_elec_nm1_rel_etiso40_1bin->AddEntry(h_bkgd_elec_nm1_rel_etiso40_1bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_etiso40_1bin->Draw();
  
  tc_elec_nm1_rel_etiso40_1bin->Update();
  
  TLine *elec_nm1_rel_etiso40_1bin_cut = new TLine(0.14,tc_elec_nm1_rel_etiso40_1bin->GetUymin(),0.14,tc_elec_nm1_rel_etiso40_1bin->GetUymax());
  elec_nm1_rel_etiso40_1bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_etiso40_1bin_cut->Draw();

  tc_elec_nm1_rel_etiso40_1bin->SetLogy();
  tc_elec_nm1_rel_etiso40_1bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_etiso40_1bin.png");

//////////////////////////////////////////////////
  // elec_nm1_rel_etiso40_2bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_etiso40_2bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_etiso40_2bin");
  TH1F* h_qcd_elec_nm1_rel_etiso40_2bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_etiso40_2bin");
  int n_qcd_elec_nm1_rel_etiso40_2bin = h_qcd_elec_nm1_rel_etiso40_2bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_etiso40_2bin = new TCanvas("tc_elec_nm1_rel_etiso40_2bin","tc_elec_nm1_rel_etiso40_2bin",0,0,1920,1200);
  tc_elec_nm1_rel_etiso40_2bin->cd();

  h_qcd_elec_nm1_rel_etiso40_2bin->Scale(1/h_qcd_elec_nm1_rel_etiso40_2bin->Integral());
  h_qcd_elec_nm1_rel_etiso40_2bin->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_etiso40_2bin->GetXaxis()->SetTitle("elec_nm1_rel_etiso40_2bin");
  h_qcd_elec_nm1_rel_etiso40_2bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_etiso40_2bin->Scale(1/h_bkgd_elec_nm1_rel_etiso40_2bin->Integral());
  h_bkgd_elec_nm1_rel_etiso40_2bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_etiso40_2bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_etiso40_2bin->SetFillColor(0);
  lgnd_elec_nm1_rel_etiso40_2bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_etiso40_2bin->AddEntry(h_qcd_elec_nm1_rel_etiso40_2bin,"Qcd","L");
  lgnd_elec_nm1_rel_etiso40_2bin->AddEntry(h_bkgd_elec_nm1_rel_etiso40_2bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_etiso40_2bin->Draw();
  
  tc_elec_nm1_rel_etiso40_2bin->Update();
  
  TLine *elec_nm1_rel_etiso40_2bin_cut = new TLine(0.14,tc_elec_nm1_rel_etiso40_2bin->GetUymin(),0.14,tc_elec_nm1_rel_etiso40_2bin->GetUymax());
  elec_nm1_rel_etiso40_2bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_etiso40_2bin_cut->Draw();

  tc_elec_nm1_rel_etiso40_2bin->SetLogy();
  tc_elec_nm1_rel_etiso40_2bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_etiso40_2bin.png");

//////////////////////////////////////////////////
  // elec_nm1_rel_etiso40_3bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_etiso40_3bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_etiso40_3bin");
  TH1F* h_qcd_elec_nm1_rel_etiso40_3bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_etiso40_3bin");
  int n_qcd_elec_nm1_rel_etiso40_3bin = h_qcd_elec_nm1_rel_etiso40_3bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_etiso40_3bin = new TCanvas("tc_elec_nm1_rel_etiso40_3bin","tc_elec_nm1_rel_etiso40_3bin",0,0,1920,1200);
  tc_elec_nm1_rel_etiso40_3bin->cd();

  h_qcd_elec_nm1_rel_etiso40_3bin->Scale(1/h_qcd_elec_nm1_rel_etiso40_3bin->Integral());
  h_qcd_elec_nm1_rel_etiso40_3bin->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_etiso40_3bin->GetXaxis()->SetTitle("elec_nm1_rel_etiso40_3bin");
  h_qcd_elec_nm1_rel_etiso40_3bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_etiso40_3bin->Scale(1/h_bkgd_elec_nm1_rel_etiso40_3bin->Integral());
  h_bkgd_elec_nm1_rel_etiso40_3bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_etiso40_3bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_etiso40_3bin->SetFillColor(0);
  lgnd_elec_nm1_rel_etiso40_3bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_etiso40_3bin->AddEntry(h_qcd_elec_nm1_rel_etiso40_3bin,"QCD","L");
  lgnd_elec_nm1_rel_etiso40_3bin->AddEntry(h_bkgd_elec_nm1_rel_etiso40_3bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_etiso40_3bin->Draw();
  
  tc_elec_nm1_rel_etiso40_3bin->Update();
  
  TLine *elec_nm1_rel_etiso40_3bin_cut = new TLine(0.14,tc_elec_nm1_rel_etiso40_3bin->GetUymin(),0.14,tc_elec_nm1_rel_etiso40_3bin->GetUymax());
  elec_nm1_rel_etiso40_3bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_etiso40_3bin_cut->Draw();

  tc_elec_nm1_rel_etiso40_3bin->SetLogy();
  tc_elec_nm1_rel_etiso40_3bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_etiso40_3bin.png");


  //////////////////////////////////////////////////
  // elec_nm1_etiso40
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_etiso40 = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_etiso40");
  TH1F* h_qcd_elec_nm1_etiso40 = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_etiso40");
  int n_qcd_elec_nm1_etiso40 = h_qcd_elec_nm1_etiso40->GetEntries();
  
  TCanvas* tc_elec_nm1_etiso40 = new TCanvas("tc_elec_nm1_etiso40","tc_elec_nm1_etiso40",0,0,1920,1200);
  tc_elec_nm1_etiso40->cd();

  h_bkgd_elec_nm1_etiso40->Scale(1/h_bkgd_elec_nm1_etiso40->Integral());
  h_bkgd_elec_nm1_etiso40->SetLineColor(kRed);
  h_bkgd_elec_nm1_etiso40->GetXaxis()->SetTitle("elec_nm1_etiso40");
  h_bkgd_elec_nm1_etiso40->Draw("HIST");
  h_qcd_elec_nm1_etiso40->Scale(1/h_qcd_elec_nm1_etiso40->Integral());
  h_qcd_elec_nm1_etiso40->Draw("HIST sames");


  TLegend* lgnd_elec_nm1_etiso40 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_etiso40->SetFillColor(0);
  lgnd_elec_nm1_etiso40->SetTextSize(0.03);
  lgnd_elec_nm1_etiso40->AddEntry(h_qcd_elec_nm1_etiso40,"Qcd","L");
  lgnd_elec_nm1_etiso40->AddEntry(h_bkgd_elec_nm1_etiso40,"Backgrounds","L");
  lgnd_elec_nm1_etiso40->Draw();
  
  tc_elec_nm1_etiso40->Update();
  
  TLine *elec_nm1_etiso40_cut = new TLine(0.14,tc_elec_nm1_etiso40->GetUymin(),0.14,tc_elec_nm1_etiso40->GetUymax());
  elec_nm1_etiso40_cut->SetLineColor(kBlue);
  elec_nm1_etiso40_cut->Draw();

  tc_elec_nm1_etiso40->SetLogy();
  tc_elec_nm1_etiso40->SaveAs("../canvases/latest/h_qcd_elec_nm1_etiso40.png");


  //////////////////////////////////////////////////
  // elec_nm1_etiso40_0bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_etiso40_0bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_etiso40_0bin");
  TH1F* h_qcd_elec_nm1_etiso40_0bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_etiso40_0bin");

  int n_qcd_elec_nm1_etiso40_0bin = h_qcd_elec_nm1_etiso40_0bin->GetEntries();
  
  TCanvas* tc_elec_nm1_etiso40_0bin = new TCanvas("tc_elec_nm1_etiso40_0bin","tc_elec_nm1_etiso40_0bin",0,0,1920,1200);
  tc_elec_nm1_etiso40_0bin->cd();

  h_qcd_elec_nm1_etiso40_0bin->Scale(1/h_qcd_elec_nm1_etiso40_0bin->Integral());
  h_qcd_elec_nm1_etiso40_0bin->SetLineColor(kRed);
  h_qcd_elec_nm1_etiso40_0bin->GetXaxis()->SetTitle("elec_nm1_etiso40_0bin");
  h_qcd_elec_nm1_etiso40_0bin->Draw("HIST");
  h_bkgd_elec_nm1_etiso40_0bin->Scale(1/h_bkgd_elec_nm1_etiso40_0bin->Integral());
  h_bkgd_elec_nm1_etiso40_0bin->Draw("HIST sames");


  TLegend* lgnd_elec_nm1_etiso40_0bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_etiso40_0bin->SetFillColor(0);
  lgnd_elec_nm1_etiso40_0bin->SetTextSize(0.03);
  lgnd_elec_nm1_etiso40_0bin->AddEntry(h_qcd_elec_nm1_etiso40_0bin,"Qcd","L");
  lgnd_elec_nm1_etiso40_0bin->AddEntry(h_bkgd_elec_nm1_etiso40_0bin,"Backgrounds","L");
  lgnd_elec_nm1_etiso40_0bin->Draw();
  
  tc_elec_nm1_etiso40_0bin->Update();
  
  TLine *elec_nm1_etiso40_0bin_cut = new TLine(0.14,tc_elec_nm1_etiso40_0bin->GetUymin(),0.14,tc_elec_nm1_etiso40_0bin->GetUymax());
  elec_nm1_etiso40_0bin_cut->SetLineColor(kBlue);
  elec_nm1_etiso40_0bin_cut->Draw();

  tc_elec_nm1_etiso40_0bin->SetLogy();
  tc_elec_nm1_etiso40_0bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_etiso40_0bin.png");


  //////////////////////////////////////////////////
  // elec_nm1_etiso40_1bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_etiso40_1bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_etiso40_1bin");
  TH1F* h_qcd_elec_nm1_etiso40_1bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_etiso40_1bin");
  int n_qcd_elec_nm1_etiso40_1bin = h_qcd_elec_nm1_etiso40_1bin->GetEntries();
  
  TCanvas* tc_elec_nm1_etiso40_1bin = new TCanvas("tc_elec_nm1_etiso40_1bin","tc_elec_nm1_etiso40_1bin",0,0,1920,1200);
  tc_elec_nm1_etiso40_1bin->cd();

  h_qcd_elec_nm1_etiso40_1bin->Scale(1/h_qcd_elec_nm1_etiso40_1bin->Integral());
  h_qcd_elec_nm1_etiso40_1bin->SetLineColor(kRed);
  h_qcd_elec_nm1_etiso40_1bin->GetXaxis()->SetTitle("elec_nm1_etiso40_1bin");
  h_qcd_elec_nm1_etiso40_1bin->Draw("HIST");
  h_bkgd_elec_nm1_etiso40_1bin->Scale(1/h_bkgd_elec_nm1_etiso40_1bin->Integral());
  h_bkgd_elec_nm1_etiso40_1bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_etiso40_1bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_etiso40_1bin->SetFillColor(0);
  lgnd_elec_nm1_etiso40_1bin->SetTextSize(0.03);
  lgnd_elec_nm1_etiso40_1bin->AddEntry(h_qcd_elec_nm1_etiso40_1bin,"Qcd","L");
  lgnd_elec_nm1_etiso40_1bin->AddEntry(h_bkgd_elec_nm1_etiso40_1bin,"Backgrounds","L");
  lgnd_elec_nm1_etiso40_1bin->Draw();
  
  tc_elec_nm1_etiso40_1bin->Update();
  
  TLine *elec_nm1_etiso40_1bin_cut = new TLine(0.14,tc_elec_nm1_etiso40_1bin->GetUymin(),0.14,tc_elec_nm1_etiso40_1bin->GetUymax());
  elec_nm1_etiso40_1bin_cut->SetLineColor(kBlue);
  elec_nm1_etiso40_1bin_cut->Draw();

  tc_elec_nm1_etiso40_1bin->SetLogy();
  tc_elec_nm1_etiso40_1bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_etiso40_1bin.png");

//////////////////////////////////////////////////
  // elec_nm1_etiso40_2bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_etiso40_2bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_etiso40_2bin");
  TH1F* h_qcd_elec_nm1_etiso40_2bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_etiso40_2bin");
  int n_qcd_elec_nm1_etiso40_2bin = h_qcd_elec_nm1_etiso40_2bin->GetEntries();
  
  TCanvas* tc_elec_nm1_etiso40_2bin = new TCanvas("tc_elec_nm1_etiso40_2bin","tc_elec_nm1_etiso40_2bin",0,0,1920,1200);
  tc_elec_nm1_etiso40_2bin->cd();

  h_qcd_elec_nm1_etiso40_2bin->Scale(1/h_qcd_elec_nm1_etiso40_2bin->Integral());
  h_qcd_elec_nm1_etiso40_2bin->SetLineColor(kRed);
  h_qcd_elec_nm1_etiso40_2bin->GetXaxis()->SetTitle("elec_nm1_etiso40_2bin");
  h_qcd_elec_nm1_etiso40_2bin->Draw("HIST");
  h_bkgd_elec_nm1_etiso40_2bin->Scale(1/h_bkgd_elec_nm1_etiso40_2bin->Integral());
  h_bkgd_elec_nm1_etiso40_2bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_etiso40_2bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_etiso40_2bin->SetFillColor(0);
  lgnd_elec_nm1_etiso40_2bin->SetTextSize(0.03);
  lgnd_elec_nm1_etiso40_2bin->AddEntry(h_qcd_elec_nm1_etiso40_2bin,"Qcd","L");
  lgnd_elec_nm1_etiso40_2bin->AddEntry(h_bkgd_elec_nm1_etiso40_2bin,"Backgrounds","L");
  lgnd_elec_nm1_etiso40_2bin->Draw();
  
  tc_elec_nm1_etiso40_2bin->Update();
  
  TLine *elec_nm1_etiso40_2bin_cut = new TLine(0.14,tc_elec_nm1_etiso40_2bin->GetUymin(),0.14,tc_elec_nm1_etiso40_2bin->GetUymax());
  elec_nm1_etiso40_2bin_cut->SetLineColor(kBlue);
  elec_nm1_etiso40_2bin_cut->Draw();

  tc_elec_nm1_etiso40_2bin->SetLogy();
  tc_elec_nm1_etiso40_2bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_etiso40_2bin.png");

//////////////////////////////////////////////////
  // elec_nm1_etiso40_3bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_etiso40_3bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_etiso40_3bin");
  TH1F* h_qcd_elec_nm1_etiso40_3bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_etiso40_3bin");
  int n_qcd_elec_nm1_etiso40_3bin = h_qcd_elec_nm1_etiso40_3bin->GetEntries();
  
  TCanvas* tc_elec_nm1_etiso40_3bin = new TCanvas("tc_elec_nm1_etiso40_3bin","tc_elec_nm1_etiso40_3bin",0,0,1920,1200);
  tc_elec_nm1_etiso40_3bin->cd();

  h_qcd_elec_nm1_etiso40_3bin->Scale(1/h_qcd_elec_nm1_etiso40_3bin->Integral());
  h_qcd_elec_nm1_etiso40_3bin->SetLineColor(kRed);
  h_qcd_elec_nm1_etiso40_3bin->GetXaxis()->SetTitle("elec_nm1_etiso40_3bin");
  h_qcd_elec_nm1_etiso40_3bin->Draw("HIST");
  h_bkgd_elec_nm1_etiso40_3bin->Scale(1/h_bkgd_elec_nm1_etiso40_3bin->Integral());
  h_bkgd_elec_nm1_etiso40_3bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_etiso40_3bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_etiso40_3bin->SetFillColor(0);
  lgnd_elec_nm1_etiso40_3bin->SetTextSize(0.03);
  lgnd_elec_nm1_etiso40_3bin->AddEntry(h_qcd_elec_nm1_etiso40_3bin,"QCD","L");
  lgnd_elec_nm1_etiso40_3bin->AddEntry(h_bkgd_elec_nm1_etiso40_3bin,"Backgrounds","L");
  lgnd_elec_nm1_etiso40_3bin->Draw();
  
  tc_elec_nm1_etiso40_3bin->Update();
  
  TLine *elec_nm1_etiso40_3bin_cut = new TLine(0.14,tc_elec_nm1_etiso40_3bin->GetUymin(),0.14,tc_elec_nm1_etiso40_3bin->GetUymax());
  elec_nm1_etiso40_3bin_cut->SetLineColor(kBlue);
  elec_nm1_etiso40_3bin_cut->Draw();

  tc_elec_nm1_etiso40_3bin->SetLogy();
  tc_elec_nm1_etiso40_3bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_etiso40_3bin.png");



  //////////////////////////////////////////////////
  // elec_nm1_ptiso40
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_ptiso40 = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_ptiso40");
  TH1F* h_qcd_elec_nm1_ptiso40 = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_ptiso40");
  int n_qcd_elec_nm1_ptiso40 = h_qcd_elec_nm1_ptiso40->GetEntries();
  
  TCanvas* tc_elec_nm1_ptiso40 = new TCanvas("tc_elec_nm1_ptiso40","tc_elec_nm1_ptiso40",0,0,1920,1200);
  tc_elec_nm1_ptiso40->cd();

  h_qcd_elec_nm1_ptiso40->Scale(1/h_qcd_elec_nm1_ptiso40->Integral());
  h_qcd_elec_nm1_ptiso40->SetLineColor(kRed);
  h_qcd_elec_nm1_ptiso40->GetXaxis()->SetTitle("elec_nm1_ptiso40");
  h_qcd_elec_nm1_ptiso40->Draw("HIST");
  h_bkgd_elec_nm1_ptiso40->Scale(1/h_bkgd_elec_nm1_ptiso40->Integral());
  h_bkgd_elec_nm1_ptiso40->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_ptiso40 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_ptiso40->SetFillColor(0);
  lgnd_elec_nm1_ptiso40->SetTextSize(0.03);
  lgnd_elec_nm1_ptiso40->AddEntry(h_qcd_elec_nm1_ptiso40,"Qcd","L");
  lgnd_elec_nm1_ptiso40->AddEntry(h_bkgd_elec_nm1_ptiso40,"Backgrounds","L");
  lgnd_elec_nm1_ptiso40->Draw();
  
  tc_elec_nm1_ptiso40->Update();

  tc_elec_nm1_ptiso40->SetLogy();
  tc_elec_nm1_ptiso40->SaveAs("../canvases/latest/h_qcd_elec_nm1_ptiso40.png");


  
  //////////////////////////////////////////////////
  // elec_nm1_ptiso40_0bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_ptiso40_0bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_ptiso40_0bin");
  TH1F* h_qcd_elec_nm1_ptiso40_0bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_ptiso40_0bin");
  int n_qcd_elec_nm1_ptiso40_0bin = h_qcd_elec_nm1_ptiso40_0bin->GetEntries();
  
  TCanvas* tc_elec_nm1_ptiso40_0bin = new TCanvas("tc_elec_nm1_ptiso40_0bin","tc_elec_nm1_ptiso40_0bin",0,0,1920,1200);
  tc_elec_nm1_ptiso40_0bin->cd();

  h_qcd_elec_nm1_ptiso40_0bin->Scale(1/h_qcd_elec_nm1_ptiso40_0bin->Integral());
  h_qcd_elec_nm1_ptiso40_0bin->SetLineColor(kRed);
  h_qcd_elec_nm1_ptiso40_0bin->GetXaxis()->SetTitle("elec_nm1_ptiso40_0bin");
  h_qcd_elec_nm1_ptiso40_0bin->Draw("HIST");
  h_bkgd_elec_nm1_ptiso40_0bin->Scale(1/h_bkgd_elec_nm1_ptiso40_0bin->Integral());
  h_bkgd_elec_nm1_ptiso40_0bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_ptiso40_0bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_ptiso40_0bin->SetFillColor(0);
  lgnd_elec_nm1_ptiso40_0bin->SetTextSize(0.03);
  lgnd_elec_nm1_ptiso40_0bin->AddEntry(h_qcd_elec_nm1_ptiso40_0bin,"Qcd","L");
  lgnd_elec_nm1_ptiso40_0bin->AddEntry(h_bkgd_elec_nm1_ptiso40_0bin,"Backgrounds","L");
  lgnd_elec_nm1_ptiso40_0bin->Draw();
  
  tc_elec_nm1_ptiso40_0bin->Update();
  
  TLine *elec_nm1_ptiso40_0bin_cut = new TLine(0.14,tc_elec_nm1_ptiso40_0bin->GetUymin(),0.14,tc_elec_nm1_ptiso40_0bin->GetUymax());
  elec_nm1_ptiso40_0bin_cut->SetLineColor(kBlue);
  elec_nm1_ptiso40_0bin_cut->Draw();

  tc_elec_nm1_ptiso40_0bin->SetLogy();
  tc_elec_nm1_ptiso40_0bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_ptiso40_0bin.png");
  
  


  //////////////////////////////////////////////////
  // elec_nm1_ptiso40_1bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_ptiso40_1bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_ptiso40_1bin");
  TH1F* h_qcd_elec_nm1_ptiso40_1bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_ptiso40_1bin");
  int n_qcd_elec_nm1_ptiso40_1bin = h_qcd_elec_nm1_ptiso40_1bin->GetEntries();
  
  TCanvas* tc_elec_nm1_ptiso40_1bin = new TCanvas("tc_elec_nm1_ptiso40_1bin","tc_elec_nm1_ptiso40_1bin",0,0,1920,1200);
  tc_elec_nm1_ptiso40_1bin->cd();

  h_qcd_elec_nm1_ptiso40_1bin->Scale(1/h_qcd_elec_nm1_ptiso40_1bin->Integral());
  h_qcd_elec_nm1_ptiso40_1bin->SetLineColor(kRed);
  h_qcd_elec_nm1_ptiso40_1bin->GetXaxis()->SetTitle("elec_nm1_ptiso40_1bin");
  h_qcd_elec_nm1_ptiso40_1bin->Draw("HIST");
  h_bkgd_elec_nm1_ptiso40_1bin->Scale(1/h_bkgd_elec_nm1_ptiso40_1bin->Integral());
  h_bkgd_elec_nm1_ptiso40_1bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_ptiso40_1bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_ptiso40_1bin->SetFillColor(0);
  lgnd_elec_nm1_ptiso40_1bin->SetTextSize(0.03);
  lgnd_elec_nm1_ptiso40_1bin->AddEntry(h_qcd_elec_nm1_ptiso40_1bin,"Qcd","L");
  lgnd_elec_nm1_ptiso40_1bin->AddEntry(h_bkgd_elec_nm1_ptiso40_1bin,"Backgrounds","L");
  lgnd_elec_nm1_ptiso40_1bin->Draw();
  
  tc_elec_nm1_ptiso40_1bin->Update();
  
  TLine *elec_nm1_ptiso40_1bin_cut = new TLine(0.14,tc_elec_nm1_ptiso40_1bin->GetUymin(),0.14,tc_elec_nm1_ptiso40_1bin->GetUymax());
  elec_nm1_ptiso40_1bin_cut->SetLineColor(kBlue);
  elec_nm1_ptiso40_1bin_cut->Draw();

  tc_elec_nm1_ptiso40_1bin->SetLogy();
  tc_elec_nm1_ptiso40_1bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_ptiso40_1bin.png");

//////////////////////////////////////////////////
  // elec_nm1_ptiso40_2bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_ptiso40_2bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_ptiso40_2bin");
  TH1F* h_qcd_elec_nm1_ptiso40_2bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_ptiso40_2bin");
  int n_qcd_elec_nm1_ptiso40_2bin = h_qcd_elec_nm1_ptiso40_2bin->GetEntries();
  
  TCanvas* tc_elec_nm1_ptiso40_2bin = new TCanvas("tc_elec_nm1_ptiso40_2bin","tc_elec_nm1_ptiso40_2bin",0,0,1920,1200);
  tc_elec_nm1_ptiso40_2bin->cd();

  h_qcd_elec_nm1_ptiso40_2bin->Scale(1/h_qcd_elec_nm1_ptiso40_2bin->Integral());
  h_qcd_elec_nm1_ptiso40_2bin->SetLineColor(kRed);
  h_qcd_elec_nm1_ptiso40_2bin->GetXaxis()->SetTitle("elec_nm1_ptiso40_2bin");
  h_qcd_elec_nm1_ptiso40_2bin->Draw("HIST");
  h_bkgd_elec_nm1_ptiso40_2bin->Scale(1/h_bkgd_elec_nm1_ptiso40_2bin->Integral());
  h_bkgd_elec_nm1_ptiso40_2bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_ptiso40_2bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_ptiso40_2bin->SetFillColor(0);
  lgnd_elec_nm1_ptiso40_2bin->SetTextSize(0.03);
  lgnd_elec_nm1_ptiso40_2bin->AddEntry(h_qcd_elec_nm1_ptiso40_2bin,"Qcd","L");
  lgnd_elec_nm1_ptiso40_2bin->AddEntry(h_bkgd_elec_nm1_ptiso40_2bin,"Backgrounds","L");
  lgnd_elec_nm1_ptiso40_2bin->Draw();
  
  tc_elec_nm1_ptiso40_2bin->Update();
  
  TLine *elec_nm1_ptiso40_2bin_cut = new TLine(0.14,tc_elec_nm1_ptiso40_2bin->GetUymin(),0.14,tc_elec_nm1_ptiso40_2bin->GetUymax());
  elec_nm1_ptiso40_2bin_cut->SetLineColor(kBlue);
  elec_nm1_ptiso40_2bin_cut->Draw();

  tc_elec_nm1_ptiso40_2bin->SetLogy();
  tc_elec_nm1_ptiso40_2bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_ptiso40_2bin.png");

//////////////////////////////////////////////////
  // elec_nm1_ptiso40_3bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_ptiso40_3bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_ptiso40_3bin");
  TH1F* h_qcd_elec_nm1_ptiso40_3bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_ptiso40_3bin");
  int n_qcd_elec_nm1_ptiso40_3bin = h_qcd_elec_nm1_ptiso40_3bin->GetEntries();
  
  TCanvas* tc_elec_nm1_ptiso40_3bin = new TCanvas("tc_elec_nm1_ptiso40_3bin","tc_elec_nm1_ptiso40_3bin",0,0,1920,1200);
  tc_elec_nm1_ptiso40_3bin->cd();

  h_qcd_elec_nm1_ptiso40_3bin->Scale(1/h_qcd_elec_nm1_ptiso40_3bin->Integral());
  h_qcd_elec_nm1_ptiso40_3bin->SetLineColor(kRed);
  h_qcd_elec_nm1_ptiso40_3bin->GetXaxis()->SetTitle("elec_nm1_ptiso40_3bin");
  h_qcd_elec_nm1_ptiso40_3bin->Draw("HIST");
  h_bkgd_elec_nm1_ptiso40_3bin->Scale(1/h_bkgd_elec_nm1_ptiso40_3bin->Integral());
  h_bkgd_elec_nm1_ptiso40_3bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_ptiso40_3bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_ptiso40_3bin->SetFillColor(0);
  lgnd_elec_nm1_ptiso40_3bin->SetTextSize(0.03);
  lgnd_elec_nm1_ptiso40_3bin->AddEntry(h_qcd_elec_nm1_ptiso40_3bin,"QCD","L");
  lgnd_elec_nm1_ptiso40_3bin->AddEntry(h_bkgd_elec_nm1_ptiso40_3bin,"Backgrounds","L");
  lgnd_elec_nm1_ptiso40_3bin->Draw();
  
  tc_elec_nm1_ptiso40_3bin->Update();
  
  TLine *elec_nm1_ptiso40_3bin_cut = new TLine(0.14,tc_elec_nm1_ptiso40_3bin->GetUymin(),0.14,tc_elec_nm1_ptiso40_3bin->GetUymax());
  elec_nm1_ptiso40_3bin_cut->SetLineColor(kBlue);
  elec_nm1_ptiso40_3bin_cut->Draw();

  tc_elec_nm1_ptiso40_3bin->SetLogy();
  tc_elec_nm1_ptiso40_3bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_ptiso40_3bin.png");


  
  //////////////////////////////////////////////////
  // elec_nm1_rel_ptiso40
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_ptiso40 = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_ptiso40");
  TH1F* h_qcd_elec_nm1_rel_ptiso40 = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_ptiso40");
  int n_qcd_elec_nm1_rel_ptiso40 = h_qcd_elec_nm1_rel_ptiso40->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_ptiso40 = new TCanvas("tc_elec_nm1_rel_ptiso40","tc_elec_nm1_rel_ptiso40",0,0,1920,1200);
  tc_elec_nm1_rel_ptiso40->cd();

  h_bkgd_elec_nm1_rel_ptiso40->Scale(1/h_bkgd_elec_nm1_rel_ptiso40->Integral());
  //h_bkgd_elec_nm1_rel_ptiso40->SetLineColor(kRed);
  h_bkgd_elec_nm1_rel_ptiso40->GetXaxis()->SetTitle("elec_nm1_rel_ptiso40");
  h_bkgd_elec_nm1_rel_ptiso40->Draw("HIST");
  h_qcd_elec_nm1_rel_ptiso40->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_ptiso40->Scale(1/h_qcd_elec_nm1_rel_ptiso40->Integral());
  h_qcd_elec_nm1_rel_ptiso40->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_ptiso40 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_ptiso40->SetFillColor(0);
  lgnd_elec_nm1_rel_ptiso40->SetTextSize(0.03);
  lgnd_elec_nm1_rel_ptiso40->AddEntry(h_qcd_elec_nm1_rel_ptiso40,"Qcd","L");
  lgnd_elec_nm1_rel_ptiso40->AddEntry(h_bkgd_elec_nm1_rel_ptiso40,"Backgrounds","L");
  lgnd_elec_nm1_rel_ptiso40->Draw();
  
  tc_elec_nm1_rel_ptiso40->Update();
  
  TLine *elec_nm1_rel_ptiso40_cut = new TLine(0.14,tc_elec_nm1_rel_ptiso40->GetUymin(),0.14,tc_elec_nm1_rel_ptiso40->GetUymax());
  elec_nm1_rel_ptiso40_cut->SetLineColor(kBlue);
  elec_nm1_rel_ptiso40_cut->Draw();

  tc_elec_nm1_rel_ptiso40->SetLogy();
  tc_elec_nm1_rel_ptiso40->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_ptiso40.png");
  
  //////////////////////////////////////////////////
  // elec_nm1_rel_ptiso40_0bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_ptiso40_0bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_ptiso40_0bin");
  TH1F* h_qcd_elec_nm1_rel_ptiso40_0bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_ptiso40_0bin");
  int n_qcd_elec_nm1_rel_ptiso40_0bin = h_qcd_elec_nm1_rel_ptiso40_0bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_ptiso40_0bin = new TCanvas("tc_elec_nm1_rel_ptiso40_0bin","tc_elec_nm1_rel_ptiso40_0bin",0,0,1920,1200);
  tc_elec_nm1_rel_ptiso40_0bin->cd();

  h_qcd_elec_nm1_rel_ptiso40_0bin->Scale(1/h_qcd_elec_nm1_rel_ptiso40_0bin->Integral());
  h_qcd_elec_nm1_rel_ptiso40_0bin->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_ptiso40_0bin->GetXaxis()->SetTitle("elec_nm1_rel_ptiso40_0bin");
  h_qcd_elec_nm1_rel_ptiso40_0bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_ptiso40_0bin->Scale(1/h_bkgd_elec_nm1_rel_ptiso40_0bin->Integral());
  h_bkgd_elec_nm1_rel_ptiso40_0bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_ptiso40_0bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_ptiso40_0bin->SetFillColor(0);
  lgnd_elec_nm1_rel_ptiso40_0bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_ptiso40_0bin->AddEntry(h_qcd_elec_nm1_rel_ptiso40_0bin,"Qcd","L");
  lgnd_elec_nm1_rel_ptiso40_0bin->AddEntry(h_bkgd_elec_nm1_rel_ptiso40_0bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_ptiso40_0bin->Draw();
  
  tc_elec_nm1_rel_ptiso40_0bin->Update();
  
  TLine *elec_nm1_rel_ptiso40_0bin_cut = new TLine(0.14,tc_elec_nm1_rel_ptiso40_0bin->GetUymin(),0.14,tc_elec_nm1_rel_ptiso40_0bin->GetUymax());
  elec_nm1_rel_ptiso40_0bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_ptiso40_0bin_cut->Draw();

  tc_elec_nm1_rel_ptiso40_0bin->SetLogy();
  tc_elec_nm1_rel_ptiso40_0bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_ptiso40_0bin.png");
  
  


  //////////////////////////////////////////////////
  // elec_nm1_rel_ptiso40_1bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_ptiso40_1bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_ptiso40_1bin");
  TH1F* h_qcd_elec_nm1_rel_ptiso40_1bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_ptiso40_1bin");
  int n_qcd_elec_nm1_rel_ptiso40_1bin = h_qcd_elec_nm1_rel_ptiso40_1bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_ptiso40_1bin = new TCanvas("tc_elec_nm1_rel_ptiso40_1bin","tc_elec_nm1_rel_ptiso40_1bin",0,0,1920,1200);
  tc_elec_nm1_rel_ptiso40_1bin->cd();

  h_qcd_elec_nm1_rel_ptiso40_1bin->Scale(1/h_qcd_elec_nm1_rel_ptiso40_1bin->Integral());
  h_qcd_elec_nm1_rel_ptiso40_1bin->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_ptiso40_1bin->GetXaxis()->SetTitle("elec_nm1_rel_ptiso40_1bin");
  h_qcd_elec_nm1_rel_ptiso40_1bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_ptiso40_1bin->Scale(1/h_bkgd_elec_nm1_rel_ptiso40_1bin->Integral());
  h_bkgd_elec_nm1_rel_ptiso40_1bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_ptiso40_1bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_ptiso40_1bin->SetFillColor(0);
  lgnd_elec_nm1_rel_ptiso40_1bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_ptiso40_1bin->AddEntry(h_qcd_elec_nm1_rel_ptiso40_1bin,"Qcd","L");
  lgnd_elec_nm1_rel_ptiso40_1bin->AddEntry(h_bkgd_elec_nm1_rel_ptiso40_1bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_ptiso40_1bin->Draw();
  
  tc_elec_nm1_rel_ptiso40_1bin->Update();
  
  TLine *elec_nm1_rel_ptiso40_1bin_cut = new TLine(0.14,tc_elec_nm1_rel_ptiso40_1bin->GetUymin(),0.14,tc_elec_nm1_rel_ptiso40_1bin->GetUymax());
  elec_nm1_rel_ptiso40_1bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_ptiso40_1bin_cut->Draw();

  tc_elec_nm1_rel_ptiso40_1bin->SetLogy();
  tc_elec_nm1_rel_ptiso40_1bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_ptiso40_1bin.png");

//////////////////////////////////////////////////
  // elec_nm1_rel_ptiso40_2bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_ptiso40_2bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_ptiso40_2bin");
  TH1F* h_qcd_elec_nm1_rel_ptiso40_2bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_ptiso40_2bin");
  int n_qcd_elec_nm1_rel_ptiso40_2bin = h_qcd_elec_nm1_rel_ptiso40_2bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_ptiso40_2bin = new TCanvas("tc_elec_nm1_rel_ptiso40_2bin","tc_elec_nm1_rel_ptiso40_2bin",0,0,1920,1200);
  tc_elec_nm1_rel_ptiso40_2bin->cd();

  h_qcd_elec_nm1_rel_ptiso40_2bin->Scale(1/h_qcd_elec_nm1_rel_ptiso40_2bin->Integral());
  h_qcd_elec_nm1_rel_ptiso40_2bin->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_ptiso40_2bin->GetXaxis()->SetTitle("elec_nm1_rel_ptiso40_2bin");
  h_qcd_elec_nm1_rel_ptiso40_2bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_ptiso40_2bin->Scale(1/h_bkgd_elec_nm1_rel_ptiso40_2bin->Integral());
  h_bkgd_elec_nm1_rel_ptiso40_2bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_ptiso40_2bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_ptiso40_2bin->SetFillColor(0);
  lgnd_elec_nm1_rel_ptiso40_2bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_ptiso40_2bin->AddEntry(h_qcd_elec_nm1_rel_ptiso40_2bin,"Qcd","L");
  lgnd_elec_nm1_rel_ptiso40_2bin->AddEntry(h_bkgd_elec_nm1_rel_ptiso40_2bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_ptiso40_2bin->Draw();
  
  tc_elec_nm1_rel_ptiso40_2bin->Update();
  
  TLine *elec_nm1_rel_ptiso40_2bin_cut = new TLine(0.14,tc_elec_nm1_rel_ptiso40_2bin->GetUymin(),0.14,tc_elec_nm1_rel_ptiso40_2bin->GetUymax());
  elec_nm1_rel_ptiso40_2bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_ptiso40_2bin_cut->Draw();

  tc_elec_nm1_rel_ptiso40_2bin->SetLogy();
  tc_elec_nm1_rel_ptiso40_2bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_ptiso40_2bin.png");

//////////////////////////////////////////////////
  // elec_nm1_rel_ptiso40_3bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_ptiso40_3bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_ptiso40_3bin");
  TH1F* h_qcd_elec_nm1_rel_ptiso40_3bin = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_rel_ptiso40_3bin");
  int n_qcd_elec_nm1_rel_ptiso40_3bin = h_qcd_elec_nm1_rel_ptiso40_3bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_ptiso40_3bin = new TCanvas("tc_elec_nm1_rel_ptiso40_3bin","tc_elec_nm1_rel_ptiso40_3bin",0,0,1920,1200);
  tc_elec_nm1_rel_ptiso40_3bin->cd();

  h_qcd_elec_nm1_rel_ptiso40_3bin->Scale(1/h_qcd_elec_nm1_rel_ptiso40_3bin->Integral());
  h_qcd_elec_nm1_rel_ptiso40_3bin->SetLineColor(kRed);
  h_qcd_elec_nm1_rel_ptiso40_3bin->GetXaxis()->SetTitle("elec_nm1_rel_ptiso40_3bin");
  h_qcd_elec_nm1_rel_ptiso40_3bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_ptiso40_3bin->Scale(1/h_bkgd_elec_nm1_rel_ptiso40_3bin->Integral());
  h_bkgd_elec_nm1_rel_ptiso40_3bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_ptiso40_3bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_ptiso40_3bin->SetFillColor(0);
  lgnd_elec_nm1_rel_ptiso40_3bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_ptiso40_3bin->AddEntry(h_qcd_elec_nm1_rel_ptiso40_3bin,"QCD","L");
  lgnd_elec_nm1_rel_ptiso40_3bin->AddEntry(h_bkgd_elec_nm1_rel_ptiso40_3bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_ptiso40_3bin->Draw();
  
  tc_elec_nm1_rel_ptiso40_3bin->Update();
  
  TLine *elec_nm1_rel_ptiso40_3bin_cut = new TLine(0.14,tc_elec_nm1_rel_ptiso40_3bin->GetUymin(),0.14,tc_elec_nm1_rel_ptiso40_3bin->GetUymax());
  elec_nm1_rel_ptiso40_3bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_ptiso40_3bin_cut->Draw();

  tc_elec_nm1_rel_ptiso40_3bin->SetLogy();
  tc_elec_nm1_rel_ptiso40_3bin->SaveAs("../canvases/latest/h_qcd_elec_nm1_rel_ptiso40_3bin.png");



  //////////////////////////////////////////////////
  // elec_nm1_d0_sig
  //////////////////////////////////////////////////
  TH1F* h_bkgd_elec_nm1_d0_sig = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_d0_sig");
  TH1F* h_qcd_elec_nm1_d0_sig = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_d0_sig");
  int n_qcd_elec_nm1_d0_sig = h_qcd_elec_nm1_d0_sig->GetEntries();
  
  TCanvas* tc_elec_nm1_d0_sig = new TCanvas("tc_elec_nm1_d0_sig","tc_elec_nm1_d0_sig",0,0,1920,1200);
  tc_elec_nm1_d0_sig->cd();

  h_qcd_elec_nm1_d0_sig->Scale(1/h_qcd_elec_nm1_d0_sig->Integral());
  h_qcd_elec_nm1_d0_sig->SetLineColor(kRed);
  h_qcd_elec_nm1_d0_sig->GetXaxis()->SetTitle("elec_nm1_d0_sig");
  h_qcd_elec_nm1_d0_sig->Draw("HIST");
  h_bkgd_elec_nm1_d0_sig->Scale(1/h_bkgd_elec_nm1_d0_sig->Integral());
  h_bkgd_elec_nm1_d0_sig->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_d0_sig = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_d0_sig->SetFillColor(0);
  lgnd_elec_nm1_d0_sig->SetTextSize(0.03);
  lgnd_elec_nm1_d0_sig->AddEntry(h_qcd_elec_nm1_d0_sig,"Qcd","L");
  lgnd_elec_nm1_d0_sig->AddEntry(h_bkgd_elec_nm1_d0_sig,"Backgrounds","L");
  lgnd_elec_nm1_d0_sig->Draw();
  
  tc_elec_nm1_d0_sig->Update();
  
  TLine *elec_nm1_d0_sig_high_cut = new TLine(10.0,tc_elec_nm1_d0_sig->GetUymin(),10.0,tc_elec_nm1_d0_sig->GetUymax());
  elec_nm1_d0_sig_high_cut->SetLineColor(kBlue);
  elec_nm1_d0_sig_high_cut->Draw();

  TLine *elec_nm1_d0_sig_low_cut = new TLine(-10.0,tc_elec_nm1_d0_sig->GetUymin(),-10.0,tc_elec_nm1_d0_sig->GetUymax());
  elec_nm1_d0_sig_low_cut->SetLineColor(kBlue);
  elec_nm1_d0_sig_low_cut->Draw();

  tc_elec_nm1_d0_sig->SetLogy();
  tc_elec_nm1_d0_sig->SaveAs("../canvases/latest/h_qcd_elec_nm1_d0_sig.png");

  //////////////////////////////////////////////////
  // elec_nm1_abs_z0
  //////////////////////////////////////////////////
  TH1F* h_bkgd_elec_nm1_abs_z0 = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_abs_z0");
  TH1F* h_qcd_elec_nm1_abs_z0 = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_abs_z0");
  int n_qcd_elec_nm1_abs_z0 = h_qcd_elec_nm1_abs_z0->GetEntries();
  
  TCanvas* tc_elec_nm1_abs_z0 = new TCanvas("tc_elec_nm1_abs_z0","tc_elec_nm1_abs_z0",0,0,1920,1200);
  tc_elec_nm1_abs_z0->cd();

  h_qcd_elec_nm1_abs_z0->Scale(1/h_qcd_elec_nm1_abs_z0->Integral());
  h_qcd_elec_nm1_abs_z0->SetLineColor(kRed);
  h_qcd_elec_nm1_abs_z0->GetXaxis()->SetTitle("elec_nm1_abs_z0");
  h_qcd_elec_nm1_abs_z0->Draw("HIST");
  h_bkgd_elec_nm1_abs_z0->Scale(1/h_bkgd_elec_nm1_abs_z0->Integral());
  h_bkgd_elec_nm1_abs_z0->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_abs_z0 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_abs_z0->SetFillColor(0);
  lgnd_elec_nm1_abs_z0->SetTextSize(0.03);
  lgnd_elec_nm1_abs_z0->AddEntry(h_qcd_elec_nm1_abs_z0,"Qcd","L");
  lgnd_elec_nm1_abs_z0->AddEntry(h_bkgd_elec_nm1_abs_z0,"Backgrounds","L");
  lgnd_elec_nm1_abs_z0->Draw();
  
  tc_elec_nm1_abs_z0->Update();
  
  TLine *elec_nm1_abs_z0_high_cut = new TLine(1.0,tc_elec_nm1_abs_z0->GetUymin(),1.0,tc_elec_nm1_abs_z0->GetUymax());
  elec_nm1_abs_z0_high_cut->SetLineColor(kBlue);
  elec_nm1_abs_z0_high_cut->Draw();

  TLine *elec_nm1_abs_z0_low_cut = new TLine(-1.0,tc_elec_nm1_abs_z0->GetUymin(),-1.0,tc_elec_nm1_abs_z0->GetUymax());
  elec_nm1_abs_z0_low_cut->SetLineColor(kBlue);
  elec_nm1_abs_z0_low_cut->Draw();

  tc_elec_nm1_abs_z0->SetLogy();
  tc_elec_nm1_abs_z0->SaveAs("../canvases/latest/h_qcd_elec_nm1_abs_z0.png");

  //////////////////////////////////////////////////
  // elec_nm1_tight
  //////////////////////////////////////////////////
  TH1F* h_bkgd_elec_nm1_tight = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_tight");
  TH1F* h_qcd_elec_nm1_tight = (TH1F*) dir_qcd_elec->Get("h_elec_nm1_tight");
  int n_qcd_elec_nm1_tight = h_qcd_elec_nm1_tight->GetEntries();
  
  TCanvas* tc_elec_nm1_tight = new TCanvas("tc_elec_nm1_tight","tc_elec_nm1_tight",0,0,1920,1200);
  tc_elec_nm1_tight->cd();

  h_qcd_elec_nm1_tight->Scale(1/h_qcd_elec_nm1_tight->Integral());
  h_qcd_elec_nm1_tight->SetLineColor(kRed);
  h_qcd_elec_nm1_tight->GetXaxis()->SetTitle("elec_nm1_tight");
  h_qcd_elec_nm1_tight->Draw("HIST");
  h_bkgd_elec_nm1_tight->Scale(1/h_bkgd_elec_nm1_tight->Integral());
  h_bkgd_elec_nm1_tight->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_tight = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_tight->SetFillColor(0);
  lgnd_elec_nm1_tight->SetTextSize(0.03);
  lgnd_elec_nm1_tight->AddEntry(h_qcd_elec_nm1_tight,"Qcd","L");
  lgnd_elec_nm1_tight->AddEntry(h_bkgd_elec_nm1_tight,"Backgrounds","L");
  lgnd_elec_nm1_tight->Draw();
  
  tc_elec_nm1_tight->Update();
  
  tc_elec_nm1_tight->SetLogy();
  tc_elec_nm1_tight->SaveAs("../canvases/latest/h_qcd_elec_nm1_tight.png");


  return;
}
