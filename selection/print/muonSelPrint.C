#include <TLine.h>


void muonSelPrint(bool drawData=true){

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
  
  TFile* mc_alpgen_wjets_sel_plots =
    (TFile*) TFile::Open("../../plots/selection_plots/merged/sel.alpgen.wjets.selection.root");
  TFile* mc_alpgen_zjets_sel_plots =
    (TFile*) TFile::Open("../../plots/selection_plots/merged/sel.alpgen.zjets.selection.root");
  TFile* mc_alpgen_top_sel_plots =
    (TFile*) TFile::Open("../../plots/selection_plots/merged/sel.mcatnlo.top.selection.root");
  TFile* mc_alpgen_vv_sel_plots =
    (TFile*) TFile::Open("../../plots/selection_plots/merged/sel.herwig.vv.selection.root");

  // TFile* gww_m350_sel_plots =
  //   (TFile*) TFile::Open("../../plots/selection_plots/merged/sel.gww.lvjj.m350.kmpl0_1.pu.skim.root");
  // TFile* gww_m1000_sel_plots =
  //   (TFile*) TFile::Open("../../plots/selection_plots/merged/sel.gww.lvjj.m1000.kmpl0_1.pu.skim.root");


  TDirectory* dir_data_muon = (TDirectory*) data_sel_plots->GetDirectory("muon");
    
  TDirectory* dir_wjets_muon = (TDirectory*) mc_alpgen_wjets_sel_plots->GetDirectory("muon");
  TDirectory* dir_zjets_muon = (TDirectory*) mc_alpgen_zjets_sel_plots->GetDirectory("muon");
  TDirectory* dir_top_muon = (TDirectory*) mc_alpgen_top_sel_plots->GetDirectory("muon");
  TDirectory* dir_vv_muon = (TDirectory*) mc_alpgen_vv_sel_plots->GetDirectory("muon");
  // TDirectory* dir_gww_m350_muon = (TDirectory*) gww_m350_sel_plots->GetDirectory("elec");
  // TDirectory* dir_gww_m1000_muon = (TDirectory*) gww_m1000_sel_plots->GetDirectory("elec");


  //////////////////////////////////////////////////
  // elec_nm1_iso
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_muon_nm1_iso = (TH1F*) dir_wjets_muon->Get("h_muon_nm1_iso");
  h_bkgd_muon_nm1_iso->Add((TH1F*) dir_zjets_muon->Get("h_muon_nm1_iso"));
  h_bkgd_muon_nm1_iso->Add((TH1F*) dir_top_muon->Get("h_muon_nm1_iso"));
  h_bkgd_muon_nm1_iso->Add((TH1F*) dir_vv_muon->Get("h_muon_nm1_iso"));

  TH1F* h_data_muon_nm1_iso = (TH1F*) dir_data_muon->Get("h_muon_nm1_iso");
  int n_data_muon_nm1_iso = h_data_muon_nm1_iso->GetEntries();
  
  TCanvas* tc_muon_nm1_iso = new TCanvas("tc_muon_nm1_iso","tc_muon_nm1_iso",0,0,1920,1200);
  tc_muon_nm1_iso->cd();

  h_data_muon_nm1_iso->Scale(1/h_data_muon_nm1_iso->Integral());
  h_data_muon_nm1_iso->SetLineColor(kRed);
  h_data_muon_nm1_iso->GetXaxis()->SetTitle("elec_nm1_iso");
  h_data_muon_nm1_iso->Draw();
  h_bkgd_muon_nm1_iso->Scale(1/h_bkgd_muon_nm1_iso->Integral());
  h_bkgd_muon_nm1_iso->Draw("sames");



  TLegend* lgnd_muon_nm1_iso = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_muon_nm1_iso->SetFillColor(0);
  lgnd_muon_nm1_iso->SetTextSize(0.03);
  lgnd_muon_nm1_iso->AddEntry(h_data_muon_nm1_iso,"Data","L");
  lgnd_muon_nm1_iso->AddEntry(h_bkgd_muon_nm1_iso,"Backgrounds","L");
  lgnd_muon_nm1_iso->Draw();
  
  tc_muon_nm1_iso->Update();
  
  TLine *elec_nm1_iso_cut = new TLine(0.14,tc_muon_nm1_iso->GetUymin(),0.14,tc_muon_nm1_iso->GetUymax());
  elec_nm1_iso_cut->SetLineColor(kBlue);
  elec_nm1_iso_cut->Draw();

  tc_muon_nm1_iso->SetLogy();
  tc_muon_nm1_iso->SaveAs("../canvases/latest/h_muon_nm1_iso.png");


  gROOT->ProcessLine(".q");
  return;
}
  
