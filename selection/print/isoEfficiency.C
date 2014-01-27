#include <TFile.h>
#include <TH1.h>
#include <TGraph.h>

float ratio_split=0.35;
void isoEfficiency(){

  gROOT->LoadMacro("../../include/atlasstyle-00-03-04/AtlasStyle.C");
  SetAtlasStyle();
  gROOT->LoadMacro("../../include/atlasstyle-00-03-04/AtlasUtils.C");
  gROOT->LoadMacro("../../include/atlasstyle-00-03-04/AtlasLabels.C");
  
  gROOT->SetBatch();
  
  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In cutFlowElec.C"<<endl;


  TFile* data_sel_plots =
    (TFile*) TFile::Open("../../plots/selection_plots/merged/sel.data.selection.root");
  TFile* mc_bkgd_sel_plots = 
      (TFile*) TFile::Open("../../plots/selection_plots/merged/sel.bkgd.selection.root");

  TDirectory* dir_data_elec = (TDirectory*) data_sel_plots->GetDirectory("elec");
  TDirectory* dir_bkgd_elec = (TDirectory*) mc_bkgd_sel_plots->GetDirectory("elec");

  //data

  TH1F* h_data_pre_d0_sig_lep_pt = (TH1F*) dir_data_elec->Get("h_elec_pt_lep_pt");
  h_data_pre_d0_sig_lep_pt->Rebin(2);
  //d0_sig
  TH1F* h_data_d0_sig_lep_pt = (TH1F*) dir_data_elec->Get("h_elec_d0_sig_lep_pt");
  h_data_d0_sig_lep_pt->Rebin(2);
  TH1F* h_data_pre_abs_z0_lep_pt = (TH1F*) h_data_d0_sig_lep_pt->Clone();
  
  //abs_z0
  TH1F* h_data_abs_z0_lep_pt = (TH1F*) dir_data_elec->Get("h_elec_abs_z0_lep_pt");
  h_data_abs_z0_lep_pt->Rebin(2);
  TH1F* h_data_pre_tight_lep_pt = (TH1F*) h_data_abs_z0_lep_pt->Clone();
  
  //tight
  TH1F* h_data_tight_lep_pt = (TH1F*) dir_data_elec->Get("h_elec_tight_lep_pt");
  h_data_tight_lep_pt->Rebin(2);
  TH1F* h_data_pre_etiso30_lep_pt = (TH1F*) h_data_tight_lep_pt->Clone();
  TH1F* h_data_pre_ptiso20_lep_pt = (TH1F*) h_data_tight_lep_pt->Clone();

  //etiso30
  TH1F* h_data_etiso30_lep_pt = (TH1F*) dir_data_elec->Get("h_elec_rel_etiso30_lep_pt");
  h_data_etiso30_lep_pt->Rebin(2);
  TH1F* h_data_pre_ptiso30_lep_pt = (TH1F*) h_data_etiso30_lep_pt->Clone();


  //ptiso30
  TH1F* h_data_ptiso30_lep_pt = (TH1F*) dir_data_elec->Get("h_elec_rel_ptiso30_lep_pt");
  h_data_ptiso30_lep_pt->Rebin(2);
  
  //ptiso20
  TH1F* h_data_ptiso20_lep_pt = (TH1F*) dir_data_elec->Get("h_elec_rel_ptiso20_lep_pt");
  h_data_ptiso20_lep_pt->Rebin(2);
  
  
  //bkgd
  //d0_sig
  TH1F* h_bkgd_pre_d0_sig_lep_pt = (TH1F*) dir_bkgd_elec->Get("h_elec_pt_lep_pt");
  h_bkgd_pre_d0_sig_lep_pt->Rebin(2);
  TH1F* h_bkgd_d0_sig_lep_pt = (TH1F*) dir_bkgd_elec->Get("h_elec_d0_sig_lep_pt");
  h_bkgd_d0_sig_lep_pt->Rebin(2);
  TH1F* h_bkgd_pre_abs_z0_lep_pt = (TH1F*) h_bkgd_d0_sig_lep_pt->Clone();

  //abs_z0
  TH1F* h_bkgd_abs_z0_lep_pt = (TH1F*) dir_bkgd_elec->Get("h_elec_abs_z0_lep_pt");
  h_bkgd_abs_z0_lep_pt->Rebin(2);
  TH1F* h_bkgd_pre_tight_lep_pt = (TH1F*) h_bkgd_abs_z0_lep_pt->Clone();

  //tight
  TH1F* h_bkgd_tight_lep_pt = (TH1F*) dir_bkgd_elec->Get("h_elec_tight_lep_pt");
  h_bkgd_tight_lep_pt->Rebin(2);
  TH1F* h_bkgd_pre_etiso30_lep_pt = (TH1F*) h_bkgd_tight_lep_pt->Clone();
  TH1F* h_bkgd_pre_ptiso20_lep_pt = (TH1F*) h_bkgd_tight_lep_pt->Clone();

  //etiso30
  TH1F* h_bkgd_etiso30_lep_pt = (TH1F*) dir_bkgd_elec->Get("h_elec_rel_etiso30_lep_pt");
  h_bkgd_etiso30_lep_pt->Rebin(2);
  TH1F* h_bkgd_pre_ptiso30_lep_pt = (TH1F*) h_bkgd_etiso30_lep_pt->Clone();

  //ptiso30
  TH1F* h_bkgd_ptiso30_lep_pt = (TH1F*) dir_bkgd_elec->Get("h_elec_rel_ptiso30_lep_pt");
  h_bkgd_ptiso30_lep_pt->Rebin(2);

  //ptiso20
  TH1F* h_bkgd_ptiso20_lep_pt = (TH1F*) dir_bkgd_elec->Get("h_elec_rel_ptiso20_lep_pt");
  h_bkgd_ptiso20_lep_pt->Rebin(2);

  
  //d0_sig
  h_data_d0_sig_lep_pt->Divide(h_data_d0_sig_lep_pt,h_data_pre_d0_sig_lep_pt,1,1,"B");
  h_bkgd_d0_sig_lep_pt->Divide(h_bkgd_d0_sig_lep_pt,h_bkgd_pre_d0_sig_lep_pt,1,1,"B");
  TH1F* h_d0_sig_lep_pt_ratio = (TH1F*) h_data_d0_sig_lep_pt->Clone();
  h_d0_sig_lep_pt_ratio->Divide(h_d0_sig_lep_pt_ratio,h_bkgd_d0_sig_lep_pt,1,1,"B");
  
  //abs_z0
  h_data_abs_z0_lep_pt->Divide(h_data_abs_z0_lep_pt,h_data_pre_abs_z0_lep_pt,1,1,"B");
  h_bkgd_abs_z0_lep_pt->Divide(h_bkgd_abs_z0_lep_pt,h_bkgd_pre_abs_z0_lep_pt,1,1,"B");
  TH1F* h_abs_z0_lep_pt_ratio = (TH1F*) h_data_abs_z0_lep_pt->Clone();
  h_abs_z0_lep_pt_ratio->Divide(h_abs_z0_lep_pt_ratio,h_bkgd_abs_z0_lep_pt,1,1,"B");
  
  //tight
  h_data_tight_lep_pt->Divide(h_data_tight_lep_pt,h_data_pre_tight_lep_pt,1,1,"B");
  h_bkgd_tight_lep_pt->Divide(h_bkgd_tight_lep_pt,h_bkgd_pre_tight_lep_pt,1,1,"B");
  TH1F* h_tight_lep_pt_ratio = (TH1F*) h_data_tight_lep_pt->Clone();
  h_tight_lep_pt_ratio->Divide(h_tight_lep_pt_ratio,h_bkgd_tight_lep_pt,1,1,"B");
  
  //etiso30
  h_data_etiso30_lep_pt->Divide(h_data_etiso30_lep_pt,h_data_pre_etiso30_lep_pt,1,1,"B");
  h_bkgd_etiso30_lep_pt->Divide(h_bkgd_etiso30_lep_pt,h_bkgd_pre_etiso30_lep_pt,1,1,"B");
  TH1F* h_etiso30_lep_pt_ratio = (TH1F*) h_data_etiso30_lep_pt->Clone();
  h_etiso30_lep_pt_ratio->Divide(h_etiso30_lep_pt_ratio,h_bkgd_etiso30_lep_pt,1,1,"B");

  //ptiso30
  h_data_ptiso30_lep_pt->Divide(h_data_ptiso30_lep_pt,h_data_pre_ptiso30_lep_pt,1,1,"B");
  h_bkgd_ptiso30_lep_pt->Divide(h_bkgd_ptiso30_lep_pt,h_bkgd_pre_ptiso30_lep_pt,1,1,"B");
  TH1F* h_ptiso30_lep_pt_ratio = (TH1F*) h_data_ptiso30_lep_pt->Clone();
  h_ptiso30_lep_pt_ratio->Divide(h_ptiso30_lep_pt_ratio,h_bkgd_ptiso30_lep_pt,1,1,"B");

  //ptiso20
  h_data_ptiso20_lep_pt->Divide(h_data_ptiso20_lep_pt,h_data_pre_ptiso20_lep_pt,1,1,"B");
  h_bkgd_ptiso20_lep_pt->Divide(h_bkgd_ptiso20_lep_pt,h_bkgd_pre_ptiso20_lep_pt,1,1,"B");
  TH1F* h_ptiso20_lep_pt_ratio = (TH1F*) h_data_ptiso20_lep_pt->Clone();
  h_ptiso20_lep_pt_ratio->Divide(h_ptiso20_lep_pt_ratio,h_bkgd_ptiso20_lep_pt,1,1,"B");


  //d0_sig
  TCanvas* tc_elec_d0_sig_eff_lep_pt = new TCanvas("tc_elec_d0_sig_eff_lep_pt","tc_elec_d0_sig_eff_lep_pt",0,0,1920,1200);
  tc_elec_d0_sig_eff_lep_pt->cd();
  
  rp_elec_d0_sig_eff_lep_pt =
    new TPad("rp_elec_d0_sig_eff_lep_pt","rp_elec_d0_sig_eff_lep_pt",0.01,0.01,0.99,ratio_split);
  rp_elec_d0_sig_eff_lep_pt->SetTopMargin(0.05);
  rp_elec_d0_sig_eff_lep_pt->SetBottomMargin(0.31);
  rp_elec_d0_sig_eff_lep_pt->SetGrid();
  rp_elec_d0_sig_eff_lep_pt->Draw();

  pp_elec_d0_sig_eff_lep_pt =
    new TPad("pp_elec_d0_sig_eff_lep_pt","pp_elec_d0_sig_eff_lep_pt",0.01,ratio_split,0.99,0.99);
  pp_elec_d0_sig_eff_lep_pt->SetBottomMargin(0);
  pp_elec_d0_sig_eff_lep_pt->Draw();
  pp_elec_d0_sig_eff_lep_pt->cd();
  pp_elec_d0_sig_eff_lep_pt->SetGrid();
  pp_elec_d0_sig_eff_lep_pt->Update();  
    
  h_bkgd_d0_sig_lep_pt->GetYaxis()->SetRangeUser(0,1.2);
  h_bkgd_d0_sig_lep_pt->GetYaxis()->SetTitle("Efficiency of corr_etcone30 electron cut");
  h_bkgd_d0_sig_lep_pt->GetYaxis()->SetTitleOffset(0.75);
  h_bkgd_d0_sig_lep_pt->GetXaxis()->SetLabelSize(0);
  h_bkgd_d0_sig_lep_pt->SetLineColor(kBlue);
  h_bkgd_d0_sig_lep_pt->SetMarkerStyle(3);
  h_bkgd_d0_sig_lep_pt->SetMarkerSize(2);
  h_bkgd_d0_sig_lep_pt->Draw("P");

  h_data_d0_sig_lep_pt->SetLineColor(kRed);
  h_data_d0_sig_lep_pt->SetMarkerStyle(3);
  h_data_d0_sig_lep_pt->SetMarkerSize(2);
  h_data_d0_sig_lep_pt->Draw("P same");

  TLegend* lgnd_elec_d0_sig_eff_lep_pt = new TLegend(0.72,0.83,0.9,0.95);
  lgnd_elec_d0_sig_eff_lep_pt->SetFillColor(0);
  lgnd_elec_d0_sig_eff_lep_pt->SetTextSize(0.03);
  lgnd_elec_d0_sig_eff_lep_pt->AddEntry(h_data_d0_sig_lep_pt,"Data","L");
  lgnd_elec_d0_sig_eff_lep_pt->AddEntry(h_bkgd_d0_sig_lep_pt,"Backgrounds","L");
  lgnd_elec_d0_sig_eff_lep_pt->Draw();

  rp_elec_d0_sig_eff_lep_pt->cd();  
  h_d0_sig_lep_pt_ratio->GetXaxis()->SetTitle("Electron pt [GeV]");
  h_d0_sig_lep_pt_ratio->GetXaxis()->SetTitleSize(0.16);
  h_d0_sig_lep_pt_ratio->GetXaxis()->SetTitleOffset(0.7);
  h_d0_sig_lep_pt_ratio->GetYaxis()->SetNdivisions(4,4,4);
  h_d0_sig_lep_pt_ratio->GetYaxis()->SetTitle("Data/Bkgd");
  h_d0_sig_lep_pt_ratio->GetYaxis()->SetTitleSize(0.07);
  h_d0_sig_lep_pt_ratio->GetYaxis()->SetTitleOffset(0.36);
  h_d0_sig_lep_pt_ratio->GetYaxis()->SetRangeUser(0.5,1.5);
  h_d0_sig_lep_pt_ratio->SetMarkerStyle(20);
  h_d0_sig_lep_pt_ratio->SetMarkerSize(2);
  h_d0_sig_lep_pt_ratio->SetLineWidth(1);
  h_d0_sig_lep_pt_ratio->Draw("HIST PE");
  
  tc_elec_d0_sig_eff_lep_pt->Update();
  tc_elec_d0_sig_eff_lep_pt->RedrawAxis();
  tc_elec_d0_sig_eff_lep_pt->SaveAs("../canvases/latest/h_elec_d0_sig_eff_lep_pt.png");



  //abs_z0
  TCanvas* tc_elec_abs_z0_eff_lep_pt = new TCanvas("tc_elec_abs_z0_eff_lep_pt","tc_elec_abs_z0_eff_lep_pt",0,0,1920,1200);
  tc_elec_abs_z0_eff_lep_pt->cd();
  
  rp_elec_abs_z0_eff_lep_pt =
    new TPad("rp_elec_abs_z0_eff_lep_pt","rp_elec_abs_z0_eff_lep_pt",0.01,0.01,0.99,ratio_split);
  rp_elec_abs_z0_eff_lep_pt->SetTopMargin(0.05);
  rp_elec_abs_z0_eff_lep_pt->SetBottomMargin(0.31);
  rp_elec_abs_z0_eff_lep_pt->SetGrid();
  rp_elec_abs_z0_eff_lep_pt->Draw();

  pp_elec_abs_z0_eff_lep_pt =
    new TPad("pp_elec_abs_z0_eff_lep_pt","pp_elec_abs_z0_eff_lep_pt",0.01,ratio_split,0.99,0.99);
  pp_elec_abs_z0_eff_lep_pt->SetBottomMargin(0);
  pp_elec_abs_z0_eff_lep_pt->Draw();
  pp_elec_abs_z0_eff_lep_pt->cd();
  pp_elec_abs_z0_eff_lep_pt->SetGrid();
  pp_elec_abs_z0_eff_lep_pt->Update();  
    
  h_bkgd_abs_z0_lep_pt->GetYaxis()->SetRangeUser(0,1.2);
  h_bkgd_abs_z0_lep_pt->GetYaxis()->SetTitle("Efficiency of corr_etcone30 electron cut");
  h_bkgd_abs_z0_lep_pt->GetYaxis()->SetTitleOffset(0.75);
  h_bkgd_abs_z0_lep_pt->GetXaxis()->SetLabelSize(0);
  h_bkgd_abs_z0_lep_pt->SetLineColor(kBlue);
  h_bkgd_abs_z0_lep_pt->SetMarkerStyle(3);
  h_bkgd_abs_z0_lep_pt->SetMarkerSize(2);
  h_bkgd_abs_z0_lep_pt->Draw("P");

  h_data_abs_z0_lep_pt->SetLineColor(kRed);
  h_data_abs_z0_lep_pt->SetMarkerStyle(3);
  h_data_abs_z0_lep_pt->SetMarkerSize(2);
  h_data_abs_z0_lep_pt->Draw("P same");

  TLegend* lgnd_elec_abs_z0_eff_lep_pt = new TLegend(0.72,0.83,0.9,0.95);
  lgnd_elec_abs_z0_eff_lep_pt->SetFillColor(0);
  lgnd_elec_abs_z0_eff_lep_pt->SetTextSize(0.03);
  lgnd_elec_abs_z0_eff_lep_pt->AddEntry(h_data_abs_z0_lep_pt,"Data","L");
  lgnd_elec_abs_z0_eff_lep_pt->AddEntry(h_bkgd_abs_z0_lep_pt,"Backgrounds","L");
  lgnd_elec_abs_z0_eff_lep_pt->Draw();

  rp_elec_abs_z0_eff_lep_pt->cd();  
  h_abs_z0_lep_pt_ratio->GetXaxis()->SetTitle("Electron pt [GeV]");
  h_abs_z0_lep_pt_ratio->GetXaxis()->SetTitleSize(0.16);
  h_abs_z0_lep_pt_ratio->GetXaxis()->SetTitleOffset(0.7);
  h_abs_z0_lep_pt_ratio->GetYaxis()->SetNdivisions(4,4,4);
  h_abs_z0_lep_pt_ratio->GetYaxis()->SetTitle("Data/Bkgd");
  h_abs_z0_lep_pt_ratio->GetYaxis()->SetTitleSize(0.07);
  h_abs_z0_lep_pt_ratio->GetYaxis()->SetTitleOffset(0.36);
  h_abs_z0_lep_pt_ratio->GetYaxis()->SetRangeUser(0.5,1.5);
  h_abs_z0_lep_pt_ratio->SetMarkerStyle(20);
  h_abs_z0_lep_pt_ratio->SetMarkerSize(2);
  h_abs_z0_lep_pt_ratio->SetLineWidth(1);
  h_abs_z0_lep_pt_ratio->Draw("HIST PE");
  
  tc_elec_abs_z0_eff_lep_pt->Update();
  tc_elec_abs_z0_eff_lep_pt->RedrawAxis();
  tc_elec_abs_z0_eff_lep_pt->SaveAs("../canvases/latest/h_elec_abs_z0_eff_lep_pt.png");


  //tight
  TCanvas* tc_elec_tight_eff_lep_pt = new TCanvas("tc_elec_tight_eff_lep_pt","tc_elec_tight_eff_lep_pt",0,0,1920,1200);
  tc_elec_tight_eff_lep_pt->cd();
  
  rp_elec_tight_eff_lep_pt =
    new TPad("rp_elec_tight_eff_lep_pt","rp_elec_tight_eff_lep_pt",0.01,0.01,0.99,ratio_split);
  rp_elec_tight_eff_lep_pt->SetTopMargin(0.05);
  rp_elec_tight_eff_lep_pt->SetBottomMargin(0.31);
  rp_elec_tight_eff_lep_pt->SetGrid();
  rp_elec_tight_eff_lep_pt->Draw();

  pp_elec_tight_eff_lep_pt =
    new TPad("pp_elec_tight_eff_lep_pt","pp_elec_tight_eff_lep_pt",0.01,ratio_split,0.99,0.99);
  pp_elec_tight_eff_lep_pt->SetBottomMargin(0);
  pp_elec_tight_eff_lep_pt->Draw();
  pp_elec_tight_eff_lep_pt->cd();
  pp_elec_tight_eff_lep_pt->SetGrid();
  pp_elec_tight_eff_lep_pt->Update();  
    
  h_bkgd_tight_lep_pt->GetYaxis()->SetRangeUser(0,1.2);
  h_bkgd_tight_lep_pt->GetYaxis()->SetTitle("Efficiency of corr_etcone30 electron cut");
  h_bkgd_tight_lep_pt->GetYaxis()->SetTitleOffset(0.75);
  h_bkgd_tight_lep_pt->GetXaxis()->SetLabelSize(0);
  h_bkgd_tight_lep_pt->SetLineColor(kBlue);
  h_bkgd_tight_lep_pt->SetMarkerStyle(3);
  h_bkgd_tight_lep_pt->SetMarkerSize(2);
  h_bkgd_tight_lep_pt->Draw("P");

  h_data_tight_lep_pt->SetLineColor(kRed);
  h_data_tight_lep_pt->SetMarkerStyle(3);
  h_data_tight_lep_pt->SetMarkerSize(2);
  h_data_tight_lep_pt->Draw("P same");

  TLegend* lgnd_elec_tight_eff_lep_pt = new TLegend(0.72,0.83,0.9,0.95);
  lgnd_elec_tight_eff_lep_pt->SetFillColor(0);
  lgnd_elec_tight_eff_lep_pt->SetTextSize(0.03);
  lgnd_elec_tight_eff_lep_pt->AddEntry(h_data_tight_lep_pt,"Data","L");
  lgnd_elec_tight_eff_lep_pt->AddEntry(h_bkgd_tight_lep_pt,"Backgrounds","L");
  lgnd_elec_tight_eff_lep_pt->Draw();

  rp_elec_tight_eff_lep_pt->cd();  
  h_tight_lep_pt_ratio->GetXaxis()->SetTitle("Electron pt [GeV]");
  h_tight_lep_pt_ratio->GetXaxis()->SetTitleSize(0.16);
  h_tight_lep_pt_ratio->GetXaxis()->SetTitleOffset(0.7);
  h_tight_lep_pt_ratio->GetYaxis()->SetNdivisions(4,4,4);
  h_tight_lep_pt_ratio->GetYaxis()->SetTitle("Data/Bkgd");
  h_tight_lep_pt_ratio->GetYaxis()->SetTitleSize(0.07);
  h_tight_lep_pt_ratio->GetYaxis()->SetTitleOffset(0.36);
  h_tight_lep_pt_ratio->GetYaxis()->SetRangeUser(0.5,1.5);
  h_tight_lep_pt_ratio->SetMarkerStyle(20);
  h_tight_lep_pt_ratio->SetMarkerSize(2);
  h_tight_lep_pt_ratio->SetLineWidth(1);
  h_tight_lep_pt_ratio->Draw("HIST PE");
  
  tc_elec_tight_eff_lep_pt->Update();
  tc_elec_tight_eff_lep_pt->RedrawAxis();
  tc_elec_tight_eff_lep_pt->SaveAs("../canvases/latest/h_elec_tight_eff_lep_pt.png");


  //etiso30
  TCanvas* tc_elec_etiso30_eff_lep_pt = new TCanvas("tc_elec_etiso30_eff_lep_pt","tc_elec_etiso30_eff_lep_pt",0,0,1920,1200);
  tc_elec_etiso30_eff_lep_pt->cd();
  
  rp_elec_etiso30_eff_lep_pt =
    new TPad("rp_elec_etiso30_eff_lep_pt","rp_elec_etiso30_eff_lep_pt",0.01,0.01,0.99,ratio_split);
  rp_elec_etiso30_eff_lep_pt->SetTopMargin(0.05);
  rp_elec_etiso30_eff_lep_pt->SetBottomMargin(0.31);
  rp_elec_etiso30_eff_lep_pt->SetGrid();
  rp_elec_etiso30_eff_lep_pt->Draw();

  pp_elec_etiso30_eff_lep_pt =
    new TPad("pp_elec_etiso30_eff_lep_pt","pp_elec_etiso30_eff_lep_pt",0.01,ratio_split,0.99,0.99);
  pp_elec_etiso30_eff_lep_pt->SetBottomMargin(0);
  pp_elec_etiso30_eff_lep_pt->Draw();
  pp_elec_etiso30_eff_lep_pt->cd();
  pp_elec_etiso30_eff_lep_pt->SetGrid();
  pp_elec_etiso30_eff_lep_pt->Update();  
    
  h_bkgd_etiso30_lep_pt->GetYaxis()->SetRangeUser(0,1.2);
  h_bkgd_etiso30_lep_pt->GetYaxis()->SetTitle("Efficiency of corr_etcone30 electron cut");
  h_bkgd_etiso30_lep_pt->GetYaxis()->SetTitleOffset(0.75);
  h_bkgd_etiso30_lep_pt->GetXaxis()->SetLabelSize(0);
  h_bkgd_etiso30_lep_pt->SetLineColor(kBlue);
  h_bkgd_etiso30_lep_pt->SetMarkerStyle(3);
  h_bkgd_etiso30_lep_pt->SetMarkerSize(2);
  h_bkgd_etiso30_lep_pt->Draw("P");

  h_data_etiso30_lep_pt->SetLineColor(kRed);
  h_data_etiso30_lep_pt->SetMarkerStyle(3);
  h_data_etiso30_lep_pt->SetMarkerSize(2);
  h_data_etiso30_lep_pt->Draw("P same");

  TLegend* lgnd_elec_etiso30_eff_lep_pt = new TLegend(0.72,0.83,0.9,0.95);
  lgnd_elec_etiso30_eff_lep_pt->SetFillColor(0);
  lgnd_elec_etiso30_eff_lep_pt->SetTextSize(0.03);
  lgnd_elec_etiso30_eff_lep_pt->AddEntry(h_data_etiso30_lep_pt,"Data","L");
  lgnd_elec_etiso30_eff_lep_pt->AddEntry(h_bkgd_etiso30_lep_pt,"Backgrounds","L");
  lgnd_elec_etiso30_eff_lep_pt->Draw();

  rp_elec_etiso30_eff_lep_pt->cd();  
  h_etiso30_lep_pt_ratio->GetXaxis()->SetTitle("Electron pt [GeV]");
  h_etiso30_lep_pt_ratio->GetXaxis()->SetTitleSize(0.16);
  h_etiso30_lep_pt_ratio->GetXaxis()->SetTitleOffset(0.7);
  h_etiso30_lep_pt_ratio->GetYaxis()->SetNdivisions(4,4,4);
  h_etiso30_lep_pt_ratio->GetYaxis()->SetTitle("Data/Bkgd");
  h_etiso30_lep_pt_ratio->GetYaxis()->SetTitleSize(0.07);
  h_etiso30_lep_pt_ratio->GetYaxis()->SetTitleOffset(0.36);
  h_etiso30_lep_pt_ratio->GetYaxis()->SetRangeUser(0.5,1.5);
  h_etiso30_lep_pt_ratio->SetMarkerStyle(20);
  h_etiso30_lep_pt_ratio->SetMarkerSize(2);
  h_etiso30_lep_pt_ratio->SetLineWidth(1);
  h_etiso30_lep_pt_ratio->Draw("HIST PE");
  
  tc_elec_etiso30_eff_lep_pt->Update();
  tc_elec_etiso30_eff_lep_pt->RedrawAxis();
  tc_elec_etiso30_eff_lep_pt->SaveAs("../canvases/latest/h_elec_etiso30_eff_lep_pt.png");


  //ptiso30
  TCanvas* tc_elec_ptiso30_eff_lep_pt = new TCanvas("tc_elec_ptiso30_eff_lep_pt","tc_elec_ptiso30_eff_lep_pt",0,0,1920,1200);
  tc_elec_ptiso30_eff_lep_pt->cd();
  
  rp_elec_ptiso30_eff_lep_pt =
    new TPad("rp_elec_ptiso30_eff_lep_pt","rp_elec_ptiso30_eff_lep_pt",0.01,0.01,0.99,ratio_split);
  rp_elec_ptiso30_eff_lep_pt->SetTopMargin(0.05);
  rp_elec_ptiso30_eff_lep_pt->SetBottomMargin(0.31);
  rp_elec_ptiso30_eff_lep_pt->SetGrid();
  rp_elec_ptiso30_eff_lep_pt->Draw();

  pp_elec_ptiso30_eff_lep_pt =
    new TPad("pp_elec_ptiso30_eff_lep_pt","pp_elec_ptiso30_eff_lep_pt",0.01,ratio_split,0.99,0.99);
  pp_elec_ptiso30_eff_lep_pt->SetBottomMargin(0);
  pp_elec_ptiso30_eff_lep_pt->Draw();
  pp_elec_ptiso30_eff_lep_pt->cd();
  pp_elec_ptiso30_eff_lep_pt->SetGrid();
  pp_elec_ptiso30_eff_lep_pt->Update();  
    
  h_bkgd_ptiso30_lep_pt->GetYaxis()->SetRangeUser(0,1.2);
  h_bkgd_ptiso30_lep_pt->GetYaxis()->SetTitle("Efficiency of corr_etcone30 electron cut");
  h_bkgd_ptiso30_lep_pt->GetYaxis()->SetTitleOffset(0.75);
  h_bkgd_ptiso30_lep_pt->GetXaxis()->SetLabelSize(0);
  h_bkgd_ptiso30_lep_pt->SetLineColor(kBlue);
  h_bkgd_ptiso30_lep_pt->SetMarkerStyle(3);
  h_bkgd_ptiso30_lep_pt->SetMarkerSize(2);
  h_bkgd_ptiso30_lep_pt->Draw("P");

  h_data_ptiso30_lep_pt->SetLineColor(kRed);
  h_data_ptiso30_lep_pt->SetMarkerStyle(3);
  h_data_ptiso30_lep_pt->SetMarkerSize(2);
  h_data_ptiso30_lep_pt->Draw("P same");

  TLegend* lgnd_elec_ptiso30_eff_lep_pt = new TLegend(0.72,0.83,0.9,0.95);
  lgnd_elec_ptiso30_eff_lep_pt->SetFillColor(0);
  lgnd_elec_ptiso30_eff_lep_pt->SetTextSize(0.03);
  lgnd_elec_ptiso30_eff_lep_pt->AddEntry(h_data_ptiso30_lep_pt,"Data","L");
  lgnd_elec_ptiso30_eff_lep_pt->AddEntry(h_bkgd_ptiso30_lep_pt,"Backgrounds","L");
  lgnd_elec_ptiso30_eff_lep_pt->Draw();

  rp_elec_ptiso30_eff_lep_pt->cd();  
  h_ptiso30_lep_pt_ratio->GetXaxis()->SetTitle("Electron pt [GeV]");
  h_ptiso30_lep_pt_ratio->GetXaxis()->SetTitleSize(0.16);
  h_ptiso30_lep_pt_ratio->GetXaxis()->SetTitleOffset(0.7);
  h_ptiso30_lep_pt_ratio->GetYaxis()->SetNdivisions(4,4,4);
  h_ptiso30_lep_pt_ratio->GetYaxis()->SetTitle("Data/Bkgd");
  h_ptiso30_lep_pt_ratio->GetYaxis()->SetTitleSize(0.07);
  h_ptiso30_lep_pt_ratio->GetYaxis()->SetTitleOffset(0.36);
  h_ptiso30_lep_pt_ratio->GetYaxis()->SetRangeUser(0.5,1.5);
  h_ptiso30_lep_pt_ratio->SetMarkerStyle(20);
  h_ptiso30_lep_pt_ratio->SetMarkerSize(2);
  h_ptiso30_lep_pt_ratio->SetLineWidth(1);
  h_ptiso30_lep_pt_ratio->Draw("HIST PE");
  
  tc_elec_ptiso30_eff_lep_pt->Update();
  tc_elec_ptiso30_eff_lep_pt->RedrawAxis();
  tc_elec_ptiso30_eff_lep_pt->SaveAs("../canvases/latest/h_elec_ptiso30_eff_lep_pt.png");


  //ptiso20
  TCanvas* tc_elec_ptiso20_eff_lep_pt = new TCanvas("tc_elec_ptiso20_eff_lep_pt","tc_elec_ptiso20_eff_lep_pt",0,0,1920,1200);
  tc_elec_ptiso20_eff_lep_pt->cd();
  
  rp_elec_ptiso20_eff_lep_pt =
    new TPad("rp_elec_ptiso20_eff_lep_pt","rp_elec_ptiso20_eff_lep_pt",0.01,0.01,0.99,ratio_split);
  rp_elec_ptiso20_eff_lep_pt->SetTopMargin(0.05);
  rp_elec_ptiso20_eff_lep_pt->SetBottomMargin(0.31);
  rp_elec_ptiso20_eff_lep_pt->SetGrid();
  rp_elec_ptiso20_eff_lep_pt->Draw();

  pp_elec_ptiso20_eff_lep_pt =
    new TPad("pp_elec_ptiso20_eff_lep_pt","pp_elec_ptiso20_eff_lep_pt",0.01,ratio_split,0.99,0.99);
  pp_elec_ptiso20_eff_lep_pt->SetBottomMargin(0);
  pp_elec_ptiso20_eff_lep_pt->Draw();
  pp_elec_ptiso20_eff_lep_pt->cd();
  pp_elec_ptiso20_eff_lep_pt->SetGrid();
  pp_elec_ptiso20_eff_lep_pt->Update();  
    
  h_bkgd_ptiso20_lep_pt->GetYaxis()->SetRangeUser(0,1.2);
  h_bkgd_ptiso20_lep_pt->GetYaxis()->SetTitle("Efficiency of corr_etcone30 electron cut");
  h_bkgd_ptiso20_lep_pt->GetYaxis()->SetTitleOffset(0.75);
  h_bkgd_ptiso20_lep_pt->GetXaxis()->SetLabelSize(0);
  h_bkgd_ptiso20_lep_pt->SetLineColor(kBlue);
  h_bkgd_ptiso20_lep_pt->SetMarkerStyle(3);
  h_bkgd_ptiso20_lep_pt->SetMarkerSize(2);
  h_bkgd_ptiso20_lep_pt->Draw("P");

  h_data_ptiso20_lep_pt->SetLineColor(kRed);
  h_data_ptiso20_lep_pt->SetMarkerStyle(3);
  h_data_ptiso20_lep_pt->SetMarkerSize(2);
  h_data_ptiso20_lep_pt->Draw("P same");

  TLegend* lgnd_elec_ptiso20_eff_lep_pt = new TLegend(0.72,0.83,0.9,0.95);
  lgnd_elec_ptiso20_eff_lep_pt->SetFillColor(0);
  lgnd_elec_ptiso20_eff_lep_pt->SetTextSize(0.03);
  lgnd_elec_ptiso20_eff_lep_pt->AddEntry(h_data_ptiso20_lep_pt,"Data","L");
  lgnd_elec_ptiso20_eff_lep_pt->AddEntry(h_bkgd_ptiso20_lep_pt,"Backgrounds","L");
  lgnd_elec_ptiso20_eff_lep_pt->Draw();

  rp_elec_ptiso20_eff_lep_pt->cd();  
  h_ptiso20_lep_pt_ratio->GetXaxis()->SetTitle("Electron pt [GeV]");
  h_ptiso20_lep_pt_ratio->GetXaxis()->SetTitleSize(0.16);
  h_ptiso20_lep_pt_ratio->GetXaxis()->SetTitleOffset(0.7);
  h_ptiso20_lep_pt_ratio->GetYaxis()->SetNdivisions(4,4,4);
  h_ptiso20_lep_pt_ratio->GetYaxis()->SetTitle("Data/Bkgd");
  h_ptiso20_lep_pt_ratio->GetYaxis()->SetTitleSize(0.07);
  h_ptiso20_lep_pt_ratio->GetYaxis()->SetTitleOffset(0.36);
  h_ptiso20_lep_pt_ratio->GetYaxis()->SetRangeUser(0.5,1.5);
  h_ptiso20_lep_pt_ratio->SetMarkerStyle(20);
  h_ptiso20_lep_pt_ratio->SetMarkerSize(2);
  h_ptiso20_lep_pt_ratio->SetLineWidth(1);
  h_ptiso20_lep_pt_ratio->Draw("HIST PE");
  
  tc_elec_ptiso20_eff_lep_pt->Update();
  tc_elec_ptiso20_eff_lep_pt->RedrawAxis();
  tc_elec_ptiso20_eff_lep_pt->SaveAs("../canvases/latest/h_elec_ptiso20_eff_lep_pt.png");



  gROOT->ProcessLine(".q");
  return;
}
