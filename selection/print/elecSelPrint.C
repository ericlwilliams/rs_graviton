#include <TLine.h>

void elecSelPrint(bool drawData=true){

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
  TFile* mc_bkgd_sel_plots = 
      (TFile*) TFile::Open("../../plots/selection_plots/merged/sel.bkgd.selection.root");

  TDirectory* dir_data_elec = (TDirectory*) data_sel_plots->GetDirectory("elec");
  TDirectory* dir_bkgd_elec = (TDirectory*) mc_bkgd_sel_plots->GetDirectory("elec");

  //////////////////////////////////////////////////
  // elec_nm1_pt
  //////////////////////////////////////////////////
  TH1F* h_bkgd_elec_nm1_pt = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_pt");
  TH1F* h_data_elec_nm1_pt = (TH1F*) dir_data_elec->Get("h_elec_nm1_pt");
  int n_data_elec_nm1_pt = h_data_elec_nm1_pt->GetEntries();
  
  TCanvas* tc_elec_nm1_pt = new TCanvas("tc_elec_nm1_pt","tc_elec_nm1_pt",0,0,1920,1200);
  tc_elec_nm1_pt->cd();

  h_data_elec_nm1_pt->Scale(1/h_data_elec_nm1_pt->Integral());
  h_data_elec_nm1_pt->SetLineColor(kRed);
  h_data_elec_nm1_pt->GetXaxis()->SetTitle("elec_nm1_pt");
  h_data_elec_nm1_pt->Draw("HIST");
  h_bkgd_elec_nm1_pt->Scale(1/h_bkgd_elec_nm1_pt->Integral());
  h_bkgd_elec_nm1_pt->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_pt = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_pt->SetFillColor(0);
  lgnd_elec_nm1_pt->SetTextSize(0.03);
  lgnd_elec_nm1_pt->AddEntry(h_data_elec_nm1_pt,"Data","L");
  lgnd_elec_nm1_pt->AddEntry(h_bkgd_elec_nm1_pt,"Backgrounds","L");
  lgnd_elec_nm1_pt->Draw();
  
  tc_elec_nm1_pt->Update();
  
  TLine *elec_nm1_pt_cut = new TLine(0.14,tc_elec_nm1_pt->GetUymin(),0.14,tc_elec_nm1_pt->GetUymax());
  elec_nm1_pt_cut->SetLineColor(kBlue);
  elec_nm1_pt_cut->Draw();

  tc_elec_nm1_pt->SetLogy();
  tc_elec_nm1_pt->SaveAs("../canvases/latest/h_elec_nm1_pt.png");

  //////////////////////////////////////////////////
  // elec_sel_pt
  //////////////////////////////////////////////////
  TH1F* h_bkgd_elec_sel_pt = (TH1F*) dir_bkgd_elec->Get("h_elec_sel_pt");
  TH1F* h_data_elec_sel_pt = (TH1F*) dir_data_elec->Get("h_elec_sel_pt");
  int n_data_elec_sel_pt = h_data_elec_sel_pt->GetEntries();
  
  TCanvas* tc_elec_sel_pt = new TCanvas("tc_elec_sel_pt","tc_elec_sel_pt",0,0,1920,1200);
  tc_elec_sel_pt->cd();

  h_data_elec_sel_pt->Scale(1/h_data_elec_sel_pt->Integral());
  h_data_elec_sel_pt->SetLineColor(kRed);
  h_data_elec_sel_pt->GetXaxis()->SetTitle("elec_sel_pt");
  h_data_elec_sel_pt->Draw("HIST");
  h_bkgd_elec_sel_pt->Scale(1/h_bkgd_elec_sel_pt->Integral());
  h_bkgd_elec_sel_pt->Draw("HIST sames");



  TLegend* lgnd_elec_sel_pt = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_sel_pt->SetFillColor(0);
  lgnd_elec_sel_pt->SetTextSize(0.03);
  lgnd_elec_sel_pt->AddEntry(h_data_elec_sel_pt,"Data","L");
  lgnd_elec_sel_pt->AddEntry(h_bkgd_elec_sel_pt,"Backgrounds","L");
  lgnd_elec_sel_pt->Draw();
  
  tc_elec_sel_pt->Update();
  
  TLine *elec_sel_pt_cut = new TLine(0.14,tc_elec_sel_pt->GetUymin(),0.14,tc_elec_sel_pt->GetUymax());
  elec_sel_pt_cut->SetLineColor(kBlue);
  elec_sel_pt_cut->Draw();

  tc_elec_sel_pt->SetLogy();
  tc_elec_sel_pt->SaveAs("../canvases/latest/h_elec_sel_pt.png");

  //////////////////////////////////////////////////
  // elec_nm1_d0_sig
  //////////////////////////////////////////////////
  TH1F* h_bkgd_elec_nm1_d0_sig = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_d0_sig");
  TH1F* h_data_elec_nm1_d0_sig = (TH1F*) dir_data_elec->Get("h_elec_nm1_d0_sig");
  int n_data_elec_nm1_d0_sig = h_data_elec_nm1_d0_sig->GetEntries();
  
  TCanvas* tc_elec_nm1_d0_sig = new TCanvas("tc_elec_nm1_d0_sig","tc_elec_nm1_d0_sig",0,0,1920,1200);
  tc_elec_nm1_d0_sig->cd();

  h_data_elec_nm1_d0_sig->Scale(1/h_data_elec_nm1_d0_sig->Integral());
  h_data_elec_nm1_d0_sig->SetLineColor(kRed);
  h_data_elec_nm1_d0_sig->GetXaxis()->SetTitle("elec_nm1_d0_sig");
  h_data_elec_nm1_d0_sig->Draw("HIST");
  h_bkgd_elec_nm1_d0_sig->Scale(1/h_bkgd_elec_nm1_d0_sig->Integral());
  h_bkgd_elec_nm1_d0_sig->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_d0_sig = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_d0_sig->SetFillColor(0);
  lgnd_elec_nm1_d0_sig->SetTextSize(0.03);
  lgnd_elec_nm1_d0_sig->AddEntry(h_data_elec_nm1_d0_sig,"Data","L");
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
  tc_elec_nm1_d0_sig->SaveAs("../canvases/latest/h_elec_nm1_d0_sig.png");

  //////////////////////////////////////////////////
  // elec_sel_d0_sig
  //////////////////////////////////////////////////
  TH1F* h_bkgd_elec_sel_d0_sig = (TH1F*) dir_bkgd_elec->Get("h_elec_sel_d0_sig");
  TH1F* h_data_elec_sel_d0_sig = (TH1F*) dir_data_elec->Get("h_elec_sel_d0_sig");
  int n_data_elec_sel_d0_sig = h_data_elec_sel_d0_sig->GetEntries();
  
  TCanvas* tc_elec_sel_d0_sig = new TCanvas("tc_elec_sel_d0_sig","tc_elec_sel_d0_sig",0,0,1920,1200);
  tc_elec_sel_d0_sig->cd();

  h_data_elec_sel_d0_sig->Scale(1/h_data_elec_sel_d0_sig->Integral());
  h_data_elec_sel_d0_sig->SetLineColor(kRed);
  h_data_elec_sel_d0_sig->GetXaxis()->SetTitle("elec_sel_d0_sig");
  h_data_elec_sel_d0_sig->Draw("HIST");
  h_bkgd_elec_sel_d0_sig->Scale(1/h_bkgd_elec_sel_d0_sig->Integral());
  h_bkgd_elec_sel_d0_sig->Draw("HIST sames");



  TLegend* lgnd_elec_sel_d0_sig = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_sel_d0_sig->SetFillColor(0);
  lgnd_elec_sel_d0_sig->SetTextSize(0.03);
  lgnd_elec_sel_d0_sig->AddEntry(h_data_elec_sel_d0_sig,"Data","L");
  lgnd_elec_sel_d0_sig->AddEntry(h_bkgd_elec_sel_d0_sig,"Backgrounds","L");
  lgnd_elec_sel_d0_sig->Draw();
  
  tc_elec_sel_d0_sig->Update();
  
  TLine *elec_sel_d0_sig_high_cut = new TLine(10.0,tc_elec_sel_d0_sig->GetUymin(),10.0,tc_elec_sel_d0_sig->GetUymax());
  elec_sel_d0_sig_high_cut->SetLineColor(kBlue);
  elec_sel_d0_sig_high_cut->Draw();

  TLine *elec_sel_d0_sig_low_cut = new TLine(-10.0,tc_elec_sel_d0_sig->GetUymin(),-10.0,tc_elec_sel_d0_sig->GetUymax());
  elec_sel_d0_sig_low_cut->SetLineColor(kBlue);
  elec_sel_d0_sig_low_cut->Draw();


  tc_elec_sel_d0_sig->SetLogy();
  tc_elec_sel_d0_sig->SaveAs("../canvases/latest/h_elec_sel_d0_sig.png");
  
  //////////////////////////////////////////////////
  // elec_nm1_abs_z0
  //////////////////////////////////////////////////
  TH1F* h_bkgd_elec_nm1_abs_z0 = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_abs_z0");
  TH1F* h_data_elec_nm1_abs_z0 = (TH1F*) dir_data_elec->Get("h_elec_nm1_abs_z0");
  int n_data_elec_nm1_abs_z0 = h_data_elec_nm1_abs_z0->GetEntries();
  
  TCanvas* tc_elec_nm1_abs_z0 = new TCanvas("tc_elec_nm1_abs_z0","tc_elec_nm1_abs_z0",0,0,1920,1200);
  tc_elec_nm1_abs_z0->cd();

  h_data_elec_nm1_abs_z0->Scale(1/h_data_elec_nm1_abs_z0->Integral());
  h_data_elec_nm1_abs_z0->SetLineColor(kRed);
  h_data_elec_nm1_abs_z0->GetXaxis()->SetTitle("elec_nm1_abs_z0");
  h_data_elec_nm1_abs_z0->Draw("HIST");
  h_bkgd_elec_nm1_abs_z0->Scale(1/h_bkgd_elec_nm1_abs_z0->Integral());
  h_bkgd_elec_nm1_abs_z0->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_abs_z0 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_abs_z0->SetFillColor(0);
  lgnd_elec_nm1_abs_z0->SetTextSize(0.03);
  lgnd_elec_nm1_abs_z0->AddEntry(h_data_elec_nm1_abs_z0,"Data","L");
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
  tc_elec_nm1_abs_z0->SaveAs("../canvases/latest/h_elec_nm1_abs_z0.png");

  //////////////////////////////////////////////////
  // elec_sel_abs_z0
  //////////////////////////////////////////////////
  TH1F* h_bkgd_elec_sel_abs_z0 = (TH1F*) dir_bkgd_elec->Get("h_elec_sel_abs_z0");
  TH1F* h_data_elec_sel_abs_z0 = (TH1F*) dir_data_elec->Get("h_elec_sel_abs_z0");
  int n_data_elec_sel_abs_z0 = h_data_elec_sel_abs_z0->GetEntries();
  
  TCanvas* tc_elec_sel_abs_z0 = new TCanvas("tc_elec_sel_abs_z0","tc_elec_sel_abs_z0",0,0,1920,1200);
  tc_elec_sel_abs_z0->cd();

  h_data_elec_sel_abs_z0->Scale(1/h_data_elec_sel_abs_z0->Integral());
  h_data_elec_sel_abs_z0->SetLineColor(kRed);
  h_data_elec_sel_abs_z0->GetXaxis()->SetTitle("elec_sel_abs_z0");
  h_data_elec_sel_abs_z0->Draw("HIST");
  h_bkgd_elec_sel_abs_z0->Scale(1/h_bkgd_elec_sel_abs_z0->Integral());
  h_bkgd_elec_sel_abs_z0->Draw("HIST sames");



  TLegend* lgnd_elec_sel_abs_z0 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_sel_abs_z0->SetFillColor(0);
  lgnd_elec_sel_abs_z0->SetTextSize(0.03);
  lgnd_elec_sel_abs_z0->AddEntry(h_data_elec_sel_abs_z0,"Data","L");
  lgnd_elec_sel_abs_z0->AddEntry(h_bkgd_elec_sel_abs_z0,"Backgrounds","L");
  lgnd_elec_sel_abs_z0->Draw();
  
  tc_elec_sel_abs_z0->Update();
  
  TLine *elec_sel_abs_z0_high_cut = new TLine(1.0,tc_elec_sel_abs_z0->GetUymin(),1.0,tc_elec_sel_abs_z0->GetUymax());
  elec_sel_abs_z0_high_cut->SetLineColor(kBlue);
  elec_sel_abs_z0_high_cut->Draw();

  TLine *elec_sel_abs_z0_low_cut = new TLine(-1.0,tc_elec_sel_abs_z0->GetUymin(),-1.0,tc_elec_sel_abs_z0->GetUymax());
  elec_sel_abs_z0_low_cut->SetLineColor(kBlue);
  elec_sel_abs_z0_low_cut->Draw();

  tc_elec_sel_abs_z0->SetLogy();
  tc_elec_sel_abs_z0->SaveAs("../canvases/latest/h_elec_sel_abs_z0.png");
  
  //////////////////////////////////////////////////
  // elec_nm1_rel_etiso30
  //////////////////////////////////////////////////
  TH1F* h_bkgd_elec_nm1_rel_etiso30 = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_etiso30");
  TH1F* h_data_elec_nm1_rel_etiso30 = (TH1F*) dir_data_elec->Get("h_elec_nm1_rel_etiso30");
  int n_data_elec_nm1_rel_etiso30 = h_data_elec_nm1_rel_etiso30->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_etiso30 = new TCanvas("tc_elec_nm1_rel_etiso30","tc_elec_nm1_rel_etiso30",0,0,1920,1200);
  tc_elec_nm1_rel_etiso30->cd();

  h_data_elec_nm1_rel_etiso30->Scale(1/h_data_elec_nm1_rel_etiso30->Integral());
  h_data_elec_nm1_rel_etiso30->SetLineColor(kRed);
  h_data_elec_nm1_rel_etiso30->GetXaxis()->SetTitle("elec_nm1_rel_etiso30");
  h_data_elec_nm1_rel_etiso30->Draw("HIST");
  h_bkgd_elec_nm1_rel_etiso30->Scale(1/h_bkgd_elec_nm1_rel_etiso30->Integral());
  h_bkgd_elec_nm1_rel_etiso30->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_etiso30 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_etiso30->SetFillColor(0);
  lgnd_elec_nm1_rel_etiso30->SetTextSize(0.03);
  lgnd_elec_nm1_rel_etiso30->AddEntry(h_data_elec_nm1_rel_etiso30,"Data","L");
  lgnd_elec_nm1_rel_etiso30->AddEntry(h_bkgd_elec_nm1_rel_etiso30,"Backgrounds","L");
  lgnd_elec_nm1_rel_etiso30->Draw();
  
  tc_elec_nm1_rel_etiso30->Update();
  
  TLine *elec_nm1_rel_etiso30_cut = new TLine(0.14,tc_elec_nm1_rel_etiso30->GetUymin(),0.14,tc_elec_nm1_rel_etiso30->GetUymax());
  elec_nm1_rel_etiso30_cut->SetLineColor(kBlue);
  elec_nm1_rel_etiso30_cut->Draw();

  tc_elec_nm1_rel_etiso30->SetLogy();
  tc_elec_nm1_rel_etiso30->SaveAs("../canvases/latest/h_elec_nm1_rel_etiso30.png");


  //////////////////////////////////////////////////
  // elec_sel_rel_etiso30
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_sel_rel_etiso30 = (TH1F*) dir_bkgd_elec->Get("h_elec_sel_rel_etiso30");
  TH1F* h_data_elec_sel_rel_etiso30 = (TH1F*) dir_data_elec->Get("h_elec_sel_rel_etiso30");
  int n_data_elec_sel_rel_etiso30 = h_data_elec_sel_rel_etiso30->GetEntries();
  
  TCanvas* tc_elec_sel_rel_etiso30 = new TCanvas("tc_elec_sel_rel_etiso30","tc_elec_sel_rel_etiso30",0,0,1920,1200);
  tc_elec_sel_rel_etiso30->cd();

  h_data_elec_sel_rel_etiso30->Scale(1/h_data_elec_sel_rel_etiso30->Integral());
  h_data_elec_sel_rel_etiso30->SetLineColor(kRed);
  h_data_elec_sel_rel_etiso30->GetXaxis()->SetTitle("elec_sel_rel_etiso30");
  h_data_elec_sel_rel_etiso30->Draw("HIST");

  h_bkgd_elec_sel_rel_etiso30->Scale(1/h_bkgd_elec_sel_rel_etiso30->Integral());
  h_bkgd_elec_sel_rel_etiso30->Draw("HIST sames");



  TLegend* lgnd_elec_sel_rel_etiso30 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_sel_rel_etiso30->SetFillColor(0);
  lgnd_elec_sel_rel_etiso30->SetTextSize(0.03);
  lgnd_elec_sel_rel_etiso30->AddEntry(h_data_elec_sel_rel_etiso30,"Data","L");
  lgnd_elec_sel_rel_etiso30->AddEntry(h_bkgd_elec_sel_rel_etiso30,"Backgrounds","L");
  lgnd_elec_sel_rel_etiso30->Draw();
  
  tc_elec_sel_rel_etiso30->Update();
  
  tc_elec_sel_rel_etiso30->SetLogy();
  tc_elec_sel_rel_etiso30->SaveAs("../canvases/latest/h_elec_sel_rel_etiso30.png");

  //////////////////////////////////////////////////
  // elec_nm1_rel_ptiso30
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_ptiso30 = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_ptiso30");
  TH1F* h_data_elec_nm1_rel_ptiso30 = (TH1F*) dir_data_elec->Get("h_elec_nm1_rel_ptiso30");
  int n_data_elec_nm1_rel_ptiso30 = h_data_elec_nm1_rel_ptiso30->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_ptiso30 = new TCanvas("tc_elec_nm1_rel_ptiso30","tc_elec_nm1_rel_ptiso30",0,0,1920,1200);
  tc_elec_nm1_rel_ptiso30->cd();

  h_data_elec_nm1_rel_ptiso30->Scale(1/h_data_elec_nm1_rel_ptiso30->Integral());
  h_data_elec_nm1_rel_ptiso30->SetLineColor(kRed);
  h_data_elec_nm1_rel_ptiso30->GetXaxis()->SetTitle("elec_nm1_rel_ptiso30");
  h_data_elec_nm1_rel_ptiso30->Draw("HIST");

  h_bkgd_elec_nm1_rel_ptiso30->Scale(1/h_bkgd_elec_nm1_rel_ptiso30->Integral());
  h_bkgd_elec_nm1_rel_ptiso30->Draw("HIST sames");


  TLegend* lgnd_elec_nm1_rel_ptiso30 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_ptiso30->SetFillColor(0);
  lgnd_elec_nm1_rel_ptiso30->SetTextSize(0.03);
  lgnd_elec_nm1_rel_ptiso30->AddEntry(h_data_elec_nm1_rel_ptiso30,"Data","L");
  lgnd_elec_nm1_rel_ptiso30->AddEntry(h_bkgd_elec_nm1_rel_ptiso30,"Backgrounds","L");
  lgnd_elec_nm1_rel_ptiso30->Draw();
  
  tc_elec_nm1_rel_ptiso30->Update();
  
  //  cout<<h_data_elec_nm1_rel_ptiso30->GetYaxis()->GetXmax()<<endl;
  TLine *elec_nm1_rel_ptiso30_cut = new TLine(0.13,tc_elec_nm1_rel_ptiso30->GetUymin(),0.13,tc_elec_nm1_rel_ptiso30->GetUymax());
  elec_nm1_rel_ptiso30_cut->SetLineColor(kBlue);
  elec_nm1_rel_ptiso30_cut->Draw();

  tc_elec_nm1_rel_ptiso30->SetLogy();
  tc_elec_nm1_rel_ptiso30->SaveAs("../canvases/latest/h_elec_nm1_rel_ptiso30.png");


  //////////////////////////////////////////////////
  // elec_sel_rel_ptiso30
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_sel_rel_ptiso30 = (TH1F*) dir_bkgd_elec->Get("h_elec_sel_rel_ptiso30");
  TH1F* h_data_elec_sel_rel_ptiso30 = (TH1F*) dir_data_elec->Get("h_elec_sel_rel_ptiso30");
  int n_data_elec_sel_rel_ptiso30 = h_data_elec_sel_rel_ptiso30->GetEntries();
  
  TCanvas* tc_elec_sel_rel_ptiso30 = new TCanvas("tc_elec_sel_rel_ptiso30","tc_elec_sel_rel_ptiso30",0,0,1920,1200);
  tc_elec_sel_rel_ptiso30->cd();

  h_data_elec_sel_rel_ptiso30->Scale(1/h_data_elec_sel_rel_ptiso30->Integral());
  h_data_elec_sel_rel_ptiso30->SetLineColor(kRed);
  h_data_elec_sel_rel_ptiso30->GetXaxis()->SetTitle("elec_sel_rel_ptiso30");
  h_data_elec_sel_rel_ptiso30->Draw("HIST");

  //h_bkgd_elec_sel_rel_ptiso30->Scale(n_data_elec_sel_rel_ptiso30/h_bkgd_elec_sel_rel_ptiso30->Integral());
  h_bkgd_elec_sel_rel_ptiso30->Scale(1/h_bkgd_elec_sel_rel_ptiso30->Integral());
  //h_bkgd_elec_sel_rel_ptiso30->GetYaxis()->SetRangeUser(0.0001,0.9);
  h_bkgd_elec_sel_rel_ptiso30->Draw("HIST sames");



  TLegend* lgnd_elec_sel_rel_ptiso30 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_sel_rel_ptiso30->SetFillColor(0);
  lgnd_elec_sel_rel_ptiso30->SetTextSize(0.03);
  lgnd_elec_sel_rel_ptiso30->AddEntry(h_data_elec_sel_rel_ptiso30,"Data","L");
  lgnd_elec_sel_rel_ptiso30->AddEntry(h_bkgd_elec_sel_rel_ptiso30,"Backgrounds","L");
  lgnd_elec_sel_rel_ptiso30->Draw();
  
  tc_elec_sel_rel_ptiso30->Update();
  
  tc_elec_sel_rel_ptiso30->SetLogy();
  tc_elec_sel_rel_ptiso30->SaveAs("../canvases/latest/h_elec_sel_rel_ptiso30.png");

  //////////////////////////////////////////////////
  // elec_nm1_rel_etiso20
  //////////////////////////////////////////////////
  TH1F* h_bkgd_elec_nm1_rel_etiso20 = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_etiso20");
  TH1F* h_data_elec_nm1_rel_etiso20 = (TH1F*) dir_data_elec->Get("h_elec_nm1_rel_etiso20");
  int n_data_elec_nm1_rel_etiso20 = h_data_elec_nm1_rel_etiso20->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_etiso20 = new TCanvas("tc_elec_nm1_rel_etiso20","tc_elec_nm1_rel_etiso20",0,0,1920,1200);
  tc_elec_nm1_rel_etiso20->cd();

  h_data_elec_nm1_rel_etiso20->Scale(1/h_data_elec_nm1_rel_etiso20->Integral());
  h_data_elec_nm1_rel_etiso20->SetLineColor(kRed);
  h_data_elec_nm1_rel_etiso20->GetXaxis()->SetTitle("elec_nm1_rel_etiso20");
  h_data_elec_nm1_rel_etiso20->Draw("HIST");
  h_bkgd_elec_nm1_rel_etiso20->Scale(1/h_bkgd_elec_nm1_rel_etiso20->Integral());
  h_bkgd_elec_nm1_rel_etiso20->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_etiso20 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_etiso20->SetFillColor(0);
  lgnd_elec_nm1_rel_etiso20->SetTextSize(0.03);
  lgnd_elec_nm1_rel_etiso20->AddEntry(h_data_elec_nm1_rel_etiso20,"Data","L");
  lgnd_elec_nm1_rel_etiso20->AddEntry(h_bkgd_elec_nm1_rel_etiso20,"Backgrounds","L");
  lgnd_elec_nm1_rel_etiso20->Draw();
  
  tc_elec_nm1_rel_etiso20->Update();
  
  TLine *elec_nm1_rel_etiso20_cut = new TLine(0.14,tc_elec_nm1_rel_etiso20->GetUymin(),0.14,tc_elec_nm1_rel_etiso20->GetUymax());
  elec_nm1_rel_etiso20_cut->SetLineColor(kBlue);
  elec_nm1_rel_etiso20_cut->Draw();

  tc_elec_nm1_rel_etiso20->SetLogy();
  tc_elec_nm1_rel_etiso20->SaveAs("../canvases/latest/h_elec_nm1_rel_etiso20.png");


  //////////////////////////////////////////////////
  // elec_sel_rel_etiso20
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_sel_rel_etiso20 = (TH1F*) dir_bkgd_elec->Get("h_elec_sel_rel_etiso20");
  TH1F* h_data_elec_sel_rel_etiso20 = (TH1F*) dir_data_elec->Get("h_elec_sel_rel_etiso20");
  int n_data_elec_sel_rel_etiso20 = h_data_elec_sel_rel_etiso20->GetEntries();
  
  TCanvas* tc_elec_sel_rel_etiso20 = new TCanvas("tc_elec_sel_rel_etiso20","tc_elec_sel_rel_etiso20",0,0,1920,1200);
  tc_elec_sel_rel_etiso20->cd();

  h_data_elec_sel_rel_etiso20->Scale(1/h_data_elec_sel_rel_etiso20->Integral());
  h_data_elec_sel_rel_etiso20->SetLineColor(kRed);
  h_data_elec_sel_rel_etiso20->GetXaxis()->SetTitle("elec_sel_rel_etiso20");
  h_data_elec_sel_rel_etiso20->Draw("HIST");

  h_bkgd_elec_sel_rel_etiso20->Scale(1/h_bkgd_elec_sel_rel_etiso20->Integral());
  h_bkgd_elec_sel_rel_etiso20->Draw("HIST sames");



  TLegend* lgnd_elec_sel_rel_etiso20 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_sel_rel_etiso20->SetFillColor(0);
  lgnd_elec_sel_rel_etiso20->SetTextSize(0.03);
  lgnd_elec_sel_rel_etiso20->AddEntry(h_data_elec_sel_rel_etiso20,"Data","L");
  lgnd_elec_sel_rel_etiso20->AddEntry(h_bkgd_elec_sel_rel_etiso20,"Backgrounds","L");
  lgnd_elec_sel_rel_etiso20->Draw();
  
  tc_elec_sel_rel_etiso20->Update();
  
  tc_elec_sel_rel_etiso20->SetLogy();
  tc_elec_sel_rel_etiso20->SaveAs("../canvases/latest/h_elec_sel_rel_etiso20.png");

  //////////////////////////////////////////////////
  // elec_nm1_rel_ptiso20
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_ptiso20 = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_ptiso20");
  TH1F* h_data_elec_nm1_rel_ptiso20 = (TH1F*) dir_data_elec->Get("h_elec_nm1_rel_ptiso20");
  int n_data_elec_nm1_rel_ptiso20 = h_data_elec_nm1_rel_ptiso20->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_ptiso20 = new TCanvas("tc_elec_nm1_rel_ptiso20","tc_elec_nm1_rel_ptiso20",0,0,1920,1200);
  tc_elec_nm1_rel_ptiso20->cd();

  h_data_elec_nm1_rel_ptiso20->Scale(1/h_data_elec_nm1_rel_ptiso20->Integral());
  h_data_elec_nm1_rel_ptiso20->SetLineColor(kRed);
  h_data_elec_nm1_rel_ptiso20->GetXaxis()->SetTitle("elec_nm1_rel_ptiso20");
  h_data_elec_nm1_rel_ptiso20->Draw("HIST");

  h_bkgd_elec_nm1_rel_ptiso20->Scale(1/h_bkgd_elec_nm1_rel_ptiso20->Integral());
  h_bkgd_elec_nm1_rel_ptiso20->Draw("HIST sames");


  TLegend* lgnd_elec_nm1_rel_ptiso20 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_ptiso20->SetFillColor(0);
  lgnd_elec_nm1_rel_ptiso20->SetTextSize(0.03);
  lgnd_elec_nm1_rel_ptiso20->AddEntry(h_data_elec_nm1_rel_ptiso20,"Data","L");
  lgnd_elec_nm1_rel_ptiso20->AddEntry(h_bkgd_elec_nm1_rel_ptiso20,"Backgrounds","L");
  lgnd_elec_nm1_rel_ptiso20->Draw();
  
  tc_elec_nm1_rel_ptiso20->Update();
  
  //  cout<<h_data_elec_nm1_rel_ptiso20->GetYaxis()->GetXmax()<<endl;
  TLine *elec_nm1_rel_ptiso20_cut = new TLine(0.13,tc_elec_nm1_rel_ptiso20->GetUymin(),0.13,tc_elec_nm1_rel_ptiso20->GetUymax());
  elec_nm1_rel_ptiso20_cut->SetLineColor(kBlue);
  elec_nm1_rel_ptiso20_cut->Draw();

  tc_elec_nm1_rel_ptiso20->SetLogy();
  tc_elec_nm1_rel_ptiso20->SaveAs("../canvases/latest/h_elec_nm1_rel_ptiso20.png");


  //////////////////////////////////////////////////
  // elec_sel_rel_ptiso20
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_sel_rel_ptiso20 = (TH1F*) dir_bkgd_elec->Get("h_elec_sel_rel_ptiso20");
  TH1F* h_data_elec_sel_rel_ptiso20 = (TH1F*) dir_data_elec->Get("h_elec_sel_rel_ptiso20");
  int n_data_elec_sel_rel_ptiso20 = h_data_elec_sel_rel_ptiso20->GetEntries();
  
  TCanvas* tc_elec_sel_rel_ptiso20 = new TCanvas("tc_elec_sel_rel_ptiso20","tc_elec_sel_rel_ptiso20",0,0,1920,1200);
  tc_elec_sel_rel_ptiso20->cd();

  h_data_elec_sel_rel_ptiso20->Scale(1/h_data_elec_sel_rel_ptiso20->Integral());
  h_data_elec_sel_rel_ptiso20->SetLineColor(kRed);
  h_data_elec_sel_rel_ptiso20->GetXaxis()->SetTitle("elec_sel_rel_ptiso20");
  h_data_elec_sel_rel_ptiso20->Draw("HIST");

  //h_bkgd_elec_sel_rel_ptiso20->Scale(n_data_elec_sel_rel_ptiso20/h_bkgd_elec_sel_rel_ptiso20->Integral());
  h_bkgd_elec_sel_rel_ptiso20->Scale(1/h_bkgd_elec_sel_rel_ptiso20->Integral());
  //h_bkgd_elec_sel_rel_ptiso20->GetYaxis()->SetRangeUser(0.0001,0.9);
  h_bkgd_elec_sel_rel_ptiso20->Draw("HISTsames");



  TLegend* lgnd_elec_sel_rel_ptiso20 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_sel_rel_ptiso20->SetFillColor(0);
  lgnd_elec_sel_rel_ptiso20->SetTextSize(0.03);
  lgnd_elec_sel_rel_ptiso20->AddEntry(h_data_elec_sel_rel_ptiso20,"Data","L");
  lgnd_elec_sel_rel_ptiso20->AddEntry(h_bkgd_elec_sel_rel_ptiso20,"Backgrounds","L");
  lgnd_elec_sel_rel_ptiso20->Draw();
  
  tc_elec_sel_rel_ptiso20->Update();
  
  tc_elec_sel_rel_ptiso20->SetLogy();
  tc_elec_sel_rel_ptiso20->SaveAs("../canvases/latest/h_elec_sel_rel_ptiso20.png");


  //////////////////////////////////////////////////
  // elec_sel_rel_etiso30_0bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_sel_rel_etiso30_0bin = (TH1F*) dir_bkgd_elec->Get("h_elec_sel_rel_etiso30_0bin");
  TH1F* h_data_elec_sel_rel_etiso30_0bin = (TH1F*) dir_data_elec->Get("h_elec_sel_rel_etiso30_0bin");
  int n_data_elec_sel_rel_etiso30_0bin = h_data_elec_sel_rel_etiso30_0bin->GetEntries();
  
  TCanvas* tc_elec_sel_rel_etiso30_0bin = new TCanvas("tc_elec_sel_rel_etiso30_0bin","tc_elec_sel_rel_etiso30_0bin",0,0,1920,1200);
  tc_elec_sel_rel_etiso30_0bin->cd();

  h_data_elec_sel_rel_etiso30_0bin->Scale(1/h_data_elec_sel_rel_etiso30_0bin->Integral());
  h_data_elec_sel_rel_etiso30_0bin->SetLineColor(kRed);
  h_data_elec_sel_rel_etiso30_0bin->GetXaxis()->SetTitle("elec_sel_rel_etiso30_0bin");
  h_data_elec_sel_rel_etiso30_0bin->Draw("HIST");
  h_bkgd_elec_sel_rel_etiso30_0bin->Scale(1/h_bkgd_elec_sel_rel_etiso30_0bin->Integral());
  h_bkgd_elec_sel_rel_etiso30_0bin->Draw("HIST sames");



  TLegend* lgnd_elec_sel_rel_etiso30_0bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_sel_rel_etiso30_0bin->SetFillColor(0);
  lgnd_elec_sel_rel_etiso30_0bin->SetTextSize(0.03);
  lgnd_elec_sel_rel_etiso30_0bin->AddEntry(h_data_elec_sel_rel_etiso30_0bin,"Data","L");
  lgnd_elec_sel_rel_etiso30_0bin->AddEntry(h_bkgd_elec_sel_rel_etiso30_0bin,"Backgrounds","L");
  lgnd_elec_sel_rel_etiso30_0bin->Draw();
  
  tc_elec_sel_rel_etiso30_0bin->Update();
  
  TLine *elec_sel_rel_etiso30_0bin_cut = new TLine(0.14,tc_elec_sel_rel_etiso30_0bin->GetUymin(),0.14,tc_elec_sel_rel_etiso30_0bin->GetUymax());
  elec_sel_rel_etiso30_0bin_cut->SetLineColor(kBlue);
  elec_sel_rel_etiso30_0bin_cut->Draw();

  tc_elec_sel_rel_etiso30_0bin->SetLogy();
  tc_elec_sel_rel_etiso30_0bin->SaveAs("../canvases/latest/h_elec_sel_rel_etiso30_0bin.png");


  //////////////////////////////////////////////////
  // elec_sel_rel_etiso30_1bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_sel_rel_etiso30_1bin = (TH1F*) dir_bkgd_elec->Get("h_elec_sel_rel_etiso30_1bin");
  TH1F* h_data_elec_sel_rel_etiso30_1bin = (TH1F*) dir_data_elec->Get("h_elec_sel_rel_etiso30_1bin");
  int n_data_elec_sel_rel_etiso30_1bin = h_data_elec_sel_rel_etiso30_1bin->GetEntries();
  
  TCanvas* tc_elec_sel_rel_etiso30_1bin = new TCanvas("tc_elec_sel_rel_etiso30_1bin","tc_elec_sel_rel_etiso30_1bin",0,0,1920,1200);
  tc_elec_sel_rel_etiso30_1bin->cd();

  h_data_elec_sel_rel_etiso30_1bin->Scale(1/h_data_elec_sel_rel_etiso30_1bin->Integral());
  h_data_elec_sel_rel_etiso30_1bin->SetLineColor(kRed);
  h_data_elec_sel_rel_etiso30_1bin->GetXaxis()->SetTitle("elec_sel_rel_etiso30_1bin");
  h_data_elec_sel_rel_etiso30_1bin->Draw("HIST");
  h_bkgd_elec_sel_rel_etiso30_1bin->Scale(1/h_bkgd_elec_sel_rel_etiso30_1bin->Integral());
  h_bkgd_elec_sel_rel_etiso30_1bin->Draw("HIST sames");



  TLegend* lgnd_elec_sel_rel_etiso30_1bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_sel_rel_etiso30_1bin->SetFillColor(0);
  lgnd_elec_sel_rel_etiso30_1bin->SetTextSize(0.03);
  lgnd_elec_sel_rel_etiso30_1bin->AddEntry(h_data_elec_sel_rel_etiso30_1bin,"Data","L");
  lgnd_elec_sel_rel_etiso30_1bin->AddEntry(h_bkgd_elec_sel_rel_etiso30_1bin,"Backgrounds","L");
  lgnd_elec_sel_rel_etiso30_1bin->Draw();
  
  tc_elec_sel_rel_etiso30_1bin->Update();
  
  TLine *elec_sel_rel_etiso30_1bin_cut = new TLine(0.14,tc_elec_sel_rel_etiso30_1bin->GetUymin(),0.14,tc_elec_sel_rel_etiso30_1bin->GetUymax());
  elec_sel_rel_etiso30_1bin_cut->SetLineColor(kBlue);
  elec_sel_rel_etiso30_1bin_cut->Draw();

  tc_elec_sel_rel_etiso30_1bin->SetLogy();
  tc_elec_sel_rel_etiso30_1bin->SaveAs("../canvases/latest/h_elec_sel_rel_etiso30_1bin.png");

//////////////////////////////////////////////////
  // elec_sel_rel_etiso30_2bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_sel_rel_etiso30_2bin = (TH1F*) dir_bkgd_elec->Get("h_elec_sel_rel_etiso30_2bin");
  TH1F* h_data_elec_sel_rel_etiso30_2bin = (TH1F*) dir_data_elec->Get("h_elec_sel_rel_etiso30_2bin");
  int n_data_elec_sel_rel_etiso30_2bin = h_data_elec_sel_rel_etiso30_2bin->GetEntries();
  
  TCanvas* tc_elec_sel_rel_etiso30_2bin = new TCanvas("tc_elec_sel_rel_etiso30_2bin","tc_elec_sel_rel_etiso30_2bin",0,0,1920,1200);
  tc_elec_sel_rel_etiso30_2bin->cd();

  h_data_elec_sel_rel_etiso30_2bin->Scale(1/h_data_elec_sel_rel_etiso30_2bin->Integral());
  h_data_elec_sel_rel_etiso30_2bin->SetLineColor(kRed);
  h_data_elec_sel_rel_etiso30_2bin->GetXaxis()->SetTitle("elec_sel_rel_etiso30_2bin");
  h_data_elec_sel_rel_etiso30_2bin->Draw("HIST");
  h_bkgd_elec_sel_rel_etiso30_2bin->Scale(1/h_bkgd_elec_sel_rel_etiso30_2bin->Integral());
  h_bkgd_elec_sel_rel_etiso30_2bin->Draw("HIST sames");



  TLegend* lgnd_elec_sel_rel_etiso30_2bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_sel_rel_etiso30_2bin->SetFillColor(0);
  lgnd_elec_sel_rel_etiso30_2bin->SetTextSize(0.03);
  lgnd_elec_sel_rel_etiso30_2bin->AddEntry(h_data_elec_sel_rel_etiso30_2bin,"Data","L");
  lgnd_elec_sel_rel_etiso30_2bin->AddEntry(h_bkgd_elec_sel_rel_etiso30_2bin,"Backgrounds","L");
  lgnd_elec_sel_rel_etiso30_2bin->Draw();
  
  tc_elec_sel_rel_etiso30_2bin->Update();
  
  TLine *elec_sel_rel_etiso30_2bin_cut = new TLine(0.14,tc_elec_sel_rel_etiso30_2bin->GetUymin(),0.14,tc_elec_sel_rel_etiso30_2bin->GetUymax());
  elec_sel_rel_etiso30_2bin_cut->SetLineColor(kBlue);
  elec_sel_rel_etiso30_2bin_cut->Draw();

  tc_elec_sel_rel_etiso30_2bin->SetLogy();
  tc_elec_sel_rel_etiso30_2bin->SaveAs("../canvases/latest/h_elec_sel_rel_etiso30_2bin.png");

//////////////////////////////////////////////////
  // elec_sel_rel_etiso30_3bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_sel_rel_etiso30_3bin = (TH1F*) dir_bkgd_elec->Get("h_elec_sel_rel_etiso30_3bin");
  TH1F* h_data_elec_sel_rel_etiso30_3bin = (TH1F*) dir_data_elec->Get("h_elec_sel_rel_etiso30_3bin");
  int n_data_elec_sel_rel_etiso30_3bin = h_data_elec_sel_rel_etiso30_3bin->GetEntries();
  
  TCanvas* tc_elec_sel_rel_etiso30_3bin = new TCanvas("tc_elec_sel_rel_etiso30_3bin","tc_elec_sel_rel_etiso30_3bin",0,0,1920,1200);
  tc_elec_sel_rel_etiso30_3bin->cd();

  h_data_elec_sel_rel_etiso30_3bin->Scale(1/h_data_elec_sel_rel_etiso30_3bin->Integral());
  h_data_elec_sel_rel_etiso30_3bin->SetLineColor(kRed);
  h_data_elec_sel_rel_etiso30_3bin->GetXaxis()->SetTitle("elec_sel_rel_etiso30_3bin");
  h_data_elec_sel_rel_etiso30_3bin->Draw("HIST");
  h_bkgd_elec_sel_rel_etiso30_3bin->Scale(1/h_bkgd_elec_sel_rel_etiso30_3bin->Integral());
  h_bkgd_elec_sel_rel_etiso30_3bin->Draw("HIST sames");



  TLegend* lgnd_elec_sel_rel_etiso30_3bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_sel_rel_etiso30_3bin->SetFillColor(0);
  lgnd_elec_sel_rel_etiso30_3bin->SetTextSize(0.03);
  lgnd_elec_sel_rel_etiso30_3bin->AddEntry(h_data_elec_sel_rel_etiso30_3bin,"Data","L");
  lgnd_elec_sel_rel_etiso30_3bin->AddEntry(h_bkgd_elec_sel_rel_etiso30_3bin,"Backgrounds","L");
  lgnd_elec_sel_rel_etiso30_3bin->Draw();
  
  tc_elec_sel_rel_etiso30_3bin->Update();
  
  TLine *elec_sel_rel_etiso30_3bin_cut = new TLine(0.14,tc_elec_sel_rel_etiso30_3bin->GetUymin(),0.14,tc_elec_sel_rel_etiso30_3bin->GetUymax());
  elec_sel_rel_etiso30_3bin_cut->SetLineColor(kBlue);
  elec_sel_rel_etiso30_3bin_cut->Draw();

  tc_elec_sel_rel_etiso30_3bin->SetLogy();
  tc_elec_sel_rel_etiso30_3bin->SaveAs("../canvases/latest/h_elec_sel_rel_etiso30_3bin.png");


  //////////////////////////////////////////////////
  // elec_nm1_rel_etiso30_0bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_etiso30_0bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_etiso30_0bin");
  TH1F* h_data_elec_nm1_rel_etiso30_0bin = (TH1F*) dir_data_elec->Get("h_elec_nm1_rel_etiso30_0bin");
  int n_data_elec_nm1_rel_etiso30_0bin = h_data_elec_nm1_rel_etiso30_0bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_etiso30_0bin = new TCanvas("tc_elec_nm1_rel_etiso30_0bin","tc_elec_nm1_rel_etiso30_0bin",0,0,1920,1200);
  tc_elec_nm1_rel_etiso30_0bin->cd();

  h_data_elec_nm1_rel_etiso30_0bin->Scale(1/h_data_elec_nm1_rel_etiso30_0bin->Integral());
  h_data_elec_nm1_rel_etiso30_0bin->SetLineColor(kRed);
  h_data_elec_nm1_rel_etiso30_0bin->GetXaxis()->SetTitle("elec_nm1_rel_etiso30_0bin");
  h_data_elec_nm1_rel_etiso30_0bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_etiso30_0bin->Scale(1/h_bkgd_elec_nm1_rel_etiso30_0bin->Integral());
  h_bkgd_elec_nm1_rel_etiso30_0bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_etiso30_0bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_etiso30_0bin->SetFillColor(0);
  lgnd_elec_nm1_rel_etiso30_0bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_etiso30_0bin->AddEntry(h_data_elec_nm1_rel_etiso30_0bin,"Data","L");
  lgnd_elec_nm1_rel_etiso30_0bin->AddEntry(h_bkgd_elec_nm1_rel_etiso30_0bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_etiso30_0bin->Draw();
  
  tc_elec_nm1_rel_etiso30_0bin->Update();
  
  TLine *elec_nm1_rel_etiso30_0bin_cut = new TLine(0.14,tc_elec_nm1_rel_etiso30_0bin->GetUymin(),0.14,tc_elec_nm1_rel_etiso30_0bin->GetUymax());
  elec_nm1_rel_etiso30_0bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_etiso30_0bin_cut->Draw();

  tc_elec_nm1_rel_etiso30_0bin->SetLogy();
  tc_elec_nm1_rel_etiso30_0bin->SaveAs("../canvases/latest/h_elec_nm1_rel_etiso30_0bin.png");


  //////////////////////////////////////////////////
  // elec_nm1_rel_etiso30_1bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_etiso30_1bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_etiso30_1bin");
  TH1F* h_data_elec_nm1_rel_etiso30_1bin = (TH1F*) dir_data_elec->Get("h_elec_nm1_rel_etiso30_1bin");
  int n_data_elec_nm1_rel_etiso30_1bin = h_data_elec_nm1_rel_etiso30_1bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_etiso30_1bin = new TCanvas("tc_elec_nm1_rel_etiso30_1bin","tc_elec_nm1_rel_etiso30_1bin",0,0,1920,1200);
  tc_elec_nm1_rel_etiso30_1bin->cd();

  h_data_elec_nm1_rel_etiso30_1bin->Scale(1/h_data_elec_nm1_rel_etiso30_1bin->Integral());
  h_data_elec_nm1_rel_etiso30_1bin->SetLineColor(kRed);
  h_data_elec_nm1_rel_etiso30_1bin->GetXaxis()->SetTitle("elec_nm1_rel_etiso30_1bin");
  h_data_elec_nm1_rel_etiso30_1bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_etiso30_1bin->Scale(1/h_bkgd_elec_nm1_rel_etiso30_1bin->Integral());
  h_bkgd_elec_nm1_rel_etiso30_1bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_etiso30_1bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_etiso30_1bin->SetFillColor(0);
  lgnd_elec_nm1_rel_etiso30_1bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_etiso30_1bin->AddEntry(h_data_elec_nm1_rel_etiso30_1bin,"Data","L");
  lgnd_elec_nm1_rel_etiso30_1bin->AddEntry(h_bkgd_elec_nm1_rel_etiso30_1bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_etiso30_1bin->Draw();
  
  tc_elec_nm1_rel_etiso30_1bin->Update();
  
  TLine *elec_nm1_rel_etiso30_1bin_cut = new TLine(0.14,tc_elec_nm1_rel_etiso30_1bin->GetUymin(),0.14,tc_elec_nm1_rel_etiso30_1bin->GetUymax());
  elec_nm1_rel_etiso30_1bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_etiso30_1bin_cut->Draw();

  tc_elec_nm1_rel_etiso30_1bin->SetLogy();
  tc_elec_nm1_rel_etiso30_1bin->SaveAs("../canvases/latest/h_elec_nm1_rel_etiso30_1bin.png");

//////////////////////////////////////////////////
  // elec_nm1_rel_etiso30_2bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_etiso30_2bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_etiso30_2bin");
  TH1F* h_data_elec_nm1_rel_etiso30_2bin = (TH1F*) dir_data_elec->Get("h_elec_nm1_rel_etiso30_2bin");
  int n_data_elec_nm1_rel_etiso30_2bin = h_data_elec_nm1_rel_etiso30_2bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_etiso30_2bin = new TCanvas("tc_elec_nm1_rel_etiso30_2bin","tc_elec_nm1_rel_etiso30_2bin",0,0,1920,1200);
  tc_elec_nm1_rel_etiso30_2bin->cd();

  h_data_elec_nm1_rel_etiso30_2bin->Scale(1/h_data_elec_nm1_rel_etiso30_2bin->Integral());
  h_data_elec_nm1_rel_etiso30_2bin->SetLineColor(kRed);
  h_data_elec_nm1_rel_etiso30_2bin->GetXaxis()->SetTitle("elec_nm1_rel_etiso30_2bin");
  h_data_elec_nm1_rel_etiso30_2bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_etiso30_2bin->Scale(1/h_bkgd_elec_nm1_rel_etiso30_2bin->Integral());
  h_bkgd_elec_nm1_rel_etiso30_2bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_etiso30_2bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_etiso30_2bin->SetFillColor(0);
  lgnd_elec_nm1_rel_etiso30_2bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_etiso30_2bin->AddEntry(h_data_elec_nm1_rel_etiso30_2bin,"Data","L");
  lgnd_elec_nm1_rel_etiso30_2bin->AddEntry(h_bkgd_elec_nm1_rel_etiso30_2bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_etiso30_2bin->Draw();
  
  tc_elec_nm1_rel_etiso30_2bin->Update();
  
  TLine *elec_nm1_rel_etiso30_2bin_cut = new TLine(0.14,tc_elec_nm1_rel_etiso30_2bin->GetUymin(),0.14,tc_elec_nm1_rel_etiso30_2bin->GetUymax());
  elec_nm1_rel_etiso30_2bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_etiso30_2bin_cut->Draw();

  tc_elec_nm1_rel_etiso30_2bin->SetLogy();
  tc_elec_nm1_rel_etiso30_2bin->SaveAs("../canvases/latest/h_elec_nm1_rel_etiso30_2bin.png");

//////////////////////////////////////////////////
  // elec_nm1_rel_etiso30_3bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_etiso30_3bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_etiso30_3bin");
  TH1F* h_data_elec_nm1_rel_etiso30_3bin = (TH1F*) dir_data_elec->Get("h_elec_nm1_rel_etiso30_3bin");
  int n_data_elec_nm1_rel_etiso30_3bin = h_data_elec_nm1_rel_etiso30_3bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_etiso30_3bin = new TCanvas("tc_elec_nm1_rel_etiso30_3bin","tc_elec_nm1_rel_etiso30_3bin",0,0,1920,1200);
  tc_elec_nm1_rel_etiso30_3bin->cd();

  h_data_elec_nm1_rel_etiso30_3bin->Scale(1/h_data_elec_nm1_rel_etiso30_3bin->Integral());
  h_data_elec_nm1_rel_etiso30_3bin->SetLineColor(kRed);
  h_data_elec_nm1_rel_etiso30_3bin->GetXaxis()->SetTitle("elec_nm1_rel_etiso30_3bin");
  h_data_elec_nm1_rel_etiso30_3bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_etiso30_3bin->Scale(1/h_bkgd_elec_nm1_rel_etiso30_3bin->Integral());
  h_bkgd_elec_nm1_rel_etiso30_3bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_etiso30_3bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_etiso30_3bin->SetFillColor(0);
  lgnd_elec_nm1_rel_etiso30_3bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_etiso30_3bin->AddEntry(h_data_elec_nm1_rel_etiso30_3bin,"Data","L");
  lgnd_elec_nm1_rel_etiso30_3bin->AddEntry(h_bkgd_elec_nm1_rel_etiso30_3bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_etiso30_3bin->Draw();
  
  tc_elec_nm1_rel_etiso30_3bin->Update();
  
  TLine *elec_nm1_rel_etiso30_3bin_cut = new TLine(0.14,tc_elec_nm1_rel_etiso30_3bin->GetUymin(),0.14,tc_elec_nm1_rel_etiso30_3bin->GetUymax());
  elec_nm1_rel_etiso30_3bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_etiso30_3bin_cut->Draw();

  tc_elec_nm1_rel_etiso30_3bin->SetLogy();
  tc_elec_nm1_rel_etiso30_3bin->SaveAs("../canvases/latest/h_elec_nm1_rel_etiso30_3bin.png");

  //////////////////////////////////////////////////
  // elec_sel_rel_ptiso30_0bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_sel_rel_ptiso30_0bin = (TH1F*) dir_bkgd_elec->Get("h_elec_sel_rel_ptiso30_0bin");
  TH1F* h_data_elec_sel_rel_ptiso30_0bin = (TH1F*) dir_data_elec->Get("h_elec_sel_rel_ptiso30_0bin");
  int n_data_elec_sel_rel_ptiso30_0bin = h_data_elec_sel_rel_ptiso30_0bin->GetEntries();
  
  TCanvas* tc_elec_sel_rel_ptiso30_0bin = new TCanvas("tc_elec_sel_rel_ptiso30_0bin","tc_elec_sel_rel_ptiso30_0bin",0,0,1920,1200);
  tc_elec_sel_rel_ptiso30_0bin->cd();

  h_data_elec_sel_rel_ptiso30_0bin->Scale(1/h_data_elec_sel_rel_ptiso30_0bin->Integral());
  h_data_elec_sel_rel_ptiso30_0bin->SetLineColor(kRed);
  h_data_elec_sel_rel_ptiso30_0bin->GetXaxis()->SetTitle("elec_sel_rel_ptiso30_0bin");
  h_data_elec_sel_rel_ptiso30_0bin->Draw("HIST");
  h_bkgd_elec_sel_rel_ptiso30_0bin->Scale(1/h_bkgd_elec_sel_rel_ptiso30_0bin->Integral());
  h_bkgd_elec_sel_rel_ptiso30_0bin->Draw("HIST sames");



  TLegend* lgnd_elec_sel_rel_ptiso30_0bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_sel_rel_ptiso30_0bin->SetFillColor(0);
  lgnd_elec_sel_rel_ptiso30_0bin->SetTextSize(0.03);
  lgnd_elec_sel_rel_ptiso30_0bin->AddEntry(h_data_elec_sel_rel_ptiso30_0bin,"Data","L");
  lgnd_elec_sel_rel_ptiso30_0bin->AddEntry(h_bkgd_elec_sel_rel_ptiso30_0bin,"Backgrounds","L");
  lgnd_elec_sel_rel_ptiso30_0bin->Draw();
  
  tc_elec_sel_rel_ptiso30_0bin->Update();
  
  TLine *elec_sel_rel_ptiso30_0bin_cut = new TLine(0.14,tc_elec_sel_rel_ptiso30_0bin->GetUymin(),0.14,tc_elec_sel_rel_ptiso30_0bin->GetUymax());
  elec_sel_rel_ptiso30_0bin_cut->SetLineColor(kBlue);
  elec_sel_rel_ptiso30_0bin_cut->Draw();

  tc_elec_sel_rel_ptiso30_0bin->SetLogy();
  tc_elec_sel_rel_ptiso30_0bin->SaveAs("../canvases/latest/h_elec_sel_rel_ptiso30_0bin.png");


  //////////////////////////////////////////////////
  // elec_sel_rel_ptiso30_1bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_sel_rel_ptiso30_1bin = (TH1F*) dir_bkgd_elec->Get("h_elec_sel_rel_ptiso30_1bin");
  TH1F* h_data_elec_sel_rel_ptiso30_1bin = (TH1F*) dir_data_elec->Get("h_elec_sel_rel_ptiso30_1bin");
  int n_data_elec_sel_rel_ptiso30_1bin = h_data_elec_sel_rel_ptiso30_1bin->GetEntries();
  
  TCanvas* tc_elec_sel_rel_ptiso30_1bin = new TCanvas("tc_elec_sel_rel_ptiso30_1bin","tc_elec_sel_rel_ptiso30_1bin",0,0,1920,1200);
  tc_elec_sel_rel_ptiso30_1bin->cd();

  h_data_elec_sel_rel_ptiso30_1bin->Scale(1/h_data_elec_sel_rel_ptiso30_1bin->Integral());
  h_data_elec_sel_rel_ptiso30_1bin->SetLineColor(kRed);
  h_data_elec_sel_rel_ptiso30_1bin->GetXaxis()->SetTitle("elec_sel_rel_ptiso30_1bin");
  h_data_elec_sel_rel_ptiso30_1bin->Draw("HIST");
  h_bkgd_elec_sel_rel_ptiso30_1bin->Scale(1/h_bkgd_elec_sel_rel_ptiso30_1bin->Integral());
  h_bkgd_elec_sel_rel_ptiso30_1bin->Draw("HIST sames");



  TLegend* lgnd_elec_sel_rel_ptiso30_1bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_sel_rel_ptiso30_1bin->SetFillColor(0);
  lgnd_elec_sel_rel_ptiso30_1bin->SetTextSize(0.03);
  lgnd_elec_sel_rel_ptiso30_1bin->AddEntry(h_data_elec_sel_rel_ptiso30_1bin,"Data","L");
  lgnd_elec_sel_rel_ptiso30_1bin->AddEntry(h_bkgd_elec_sel_rel_ptiso30_1bin,"Backgrounds","L");
  lgnd_elec_sel_rel_ptiso30_1bin->Draw();
  
  tc_elec_sel_rel_ptiso30_1bin->Update();
  
  TLine *elec_sel_rel_ptiso30_1bin_cut = new TLine(0.14,tc_elec_sel_rel_ptiso30_1bin->GetUymin(),0.14,tc_elec_sel_rel_ptiso30_1bin->GetUymax());
  elec_sel_rel_ptiso30_1bin_cut->SetLineColor(kBlue);
  elec_sel_rel_ptiso30_1bin_cut->Draw();

  tc_elec_sel_rel_ptiso30_1bin->SetLogy();
  tc_elec_sel_rel_ptiso30_1bin->SaveAs("../canvases/latest/h_elec_sel_rel_ptiso30_1bin.png");

//////////////////////////////////////////////////
  // elec_sel_rel_ptiso30_2bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_sel_rel_ptiso30_2bin = (TH1F*) dir_bkgd_elec->Get("h_elec_sel_rel_ptiso30_2bin");
  TH1F* h_data_elec_sel_rel_ptiso30_2bin = (TH1F*) dir_data_elec->Get("h_elec_sel_rel_ptiso30_2bin");
  int n_data_elec_sel_rel_ptiso30_2bin = h_data_elec_sel_rel_ptiso30_2bin->GetEntries();
  
  TCanvas* tc_elec_sel_rel_ptiso30_2bin = new TCanvas("tc_elec_sel_rel_ptiso30_2bin","tc_elec_sel_rel_ptiso30_2bin",0,0,1920,1200);
  tc_elec_sel_rel_ptiso30_2bin->cd();

  h_data_elec_sel_rel_ptiso30_2bin->Scale(1/h_data_elec_sel_rel_ptiso30_2bin->Integral());
  h_data_elec_sel_rel_ptiso30_2bin->SetLineColor(kRed);
  h_data_elec_sel_rel_ptiso30_2bin->GetXaxis()->SetTitle("elec_sel_rel_ptiso30_2bin");
  h_data_elec_sel_rel_ptiso30_2bin->Draw("HIST");
  h_bkgd_elec_sel_rel_ptiso30_2bin->Scale(1/h_bkgd_elec_sel_rel_ptiso30_2bin->Integral());
  h_bkgd_elec_sel_rel_ptiso30_2bin->Draw("HIST sames");



  TLegend* lgnd_elec_sel_rel_ptiso30_2bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_sel_rel_ptiso30_2bin->SetFillColor(0);
  lgnd_elec_sel_rel_ptiso30_2bin->SetTextSize(0.03);
  lgnd_elec_sel_rel_ptiso30_2bin->AddEntry(h_data_elec_sel_rel_ptiso30_2bin,"Data","L");
  lgnd_elec_sel_rel_ptiso30_2bin->AddEntry(h_bkgd_elec_sel_rel_ptiso30_2bin,"Backgrounds","L");
  lgnd_elec_sel_rel_ptiso30_2bin->Draw();
  
  tc_elec_sel_rel_ptiso30_2bin->Update();
  
  TLine *elec_sel_rel_ptiso30_2bin_cut = new TLine(0.14,tc_elec_sel_rel_ptiso30_2bin->GetUymin(),0.14,tc_elec_sel_rel_ptiso30_2bin->GetUymax());
  elec_sel_rel_ptiso30_2bin_cut->SetLineColor(kBlue);
  elec_sel_rel_ptiso30_2bin_cut->Draw();

  tc_elec_sel_rel_ptiso30_2bin->SetLogy();
  tc_elec_sel_rel_ptiso30_2bin->SaveAs("../canvases/latest/h_elec_sel_rel_ptiso30_2bin.png");

//////////////////////////////////////////////////
  // elec_sel_rel_ptiso30_3bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_sel_rel_ptiso30_3bin = (TH1F*) dir_bkgd_elec->Get("h_elec_sel_rel_ptiso30_3bin");
  TH1F* h_data_elec_sel_rel_ptiso30_3bin = (TH1F*) dir_data_elec->Get("h_elec_sel_rel_ptiso30_3bin");
  int n_data_elec_sel_rel_ptiso30_3bin = h_data_elec_sel_rel_ptiso30_3bin->GetEntries();
  
  TCanvas* tc_elec_sel_rel_ptiso30_3bin = new TCanvas("tc_elec_sel_rel_ptiso30_3bin","tc_elec_sel_rel_ptiso30_3bin",0,0,1920,1200);
  tc_elec_sel_rel_ptiso30_3bin->cd();

  h_data_elec_sel_rel_ptiso30_3bin->Scale(1/h_data_elec_sel_rel_ptiso30_3bin->Integral());
  h_data_elec_sel_rel_ptiso30_3bin->SetLineColor(kRed);
  h_data_elec_sel_rel_ptiso30_3bin->GetXaxis()->SetTitle("elec_sel_rel_ptiso30_3bin");
  h_data_elec_sel_rel_ptiso30_3bin->Draw("HIST");
  h_bkgd_elec_sel_rel_ptiso30_3bin->Scale(1/h_bkgd_elec_sel_rel_ptiso30_3bin->Integral());
  h_bkgd_elec_sel_rel_ptiso30_3bin->Draw("HIST sames");



  TLegend* lgnd_elec_sel_rel_ptiso30_3bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_sel_rel_ptiso30_3bin->SetFillColor(0);
  lgnd_elec_sel_rel_ptiso30_3bin->SetTextSize(0.03);
  lgnd_elec_sel_rel_ptiso30_3bin->AddEntry(h_data_elec_sel_rel_ptiso30_3bin,"Data","L");
  lgnd_elec_sel_rel_ptiso30_3bin->AddEntry(h_bkgd_elec_sel_rel_ptiso30_3bin,"Backgrounds","L");
  lgnd_elec_sel_rel_ptiso30_3bin->Draw();
  
  tc_elec_sel_rel_ptiso30_3bin->Update();
  
  TLine *elec_sel_rel_ptiso30_3bin_cut = new TLine(0.14,tc_elec_sel_rel_ptiso30_3bin->GetUymin(),0.14,tc_elec_sel_rel_ptiso30_3bin->GetUymax());
  elec_sel_rel_ptiso30_3bin_cut->SetLineColor(kBlue);
  elec_sel_rel_ptiso30_3bin_cut->Draw();

  tc_elec_sel_rel_ptiso30_3bin->SetLogy();
  tc_elec_sel_rel_ptiso30_3bin->SaveAs("../canvases/latest/h_elec_sel_rel_ptiso30_3bin.png");


  //////////////////////////////////////////////////
  // elec_nm1_rel_ptiso30_0bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_ptiso30_0bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_ptiso30_0bin");
  TH1F* h_data_elec_nm1_rel_ptiso30_0bin = (TH1F*) dir_data_elec->Get("h_elec_nm1_rel_ptiso30_0bin");
  int n_data_elec_nm1_rel_ptiso30_0bin = h_data_elec_nm1_rel_ptiso30_0bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_ptiso30_0bin = new TCanvas("tc_elec_nm1_rel_ptiso30_0bin","tc_elec_nm1_rel_ptiso30_0bin",0,0,1920,1200);
  tc_elec_nm1_rel_ptiso30_0bin->cd();

  h_data_elec_nm1_rel_ptiso30_0bin->Scale(1/h_data_elec_nm1_rel_ptiso30_0bin->Integral());
  h_data_elec_nm1_rel_ptiso30_0bin->SetLineColor(kRed);
  h_data_elec_nm1_rel_ptiso30_0bin->GetXaxis()->SetTitle("elec_nm1_rel_ptiso30_0bin");
  h_data_elec_nm1_rel_ptiso30_0bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_ptiso30_0bin->Scale(1/h_bkgd_elec_nm1_rel_ptiso30_0bin->Integral());
  h_bkgd_elec_nm1_rel_ptiso30_0bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_ptiso30_0bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_ptiso30_0bin->SetFillColor(0);
  lgnd_elec_nm1_rel_ptiso30_0bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_ptiso30_0bin->AddEntry(h_data_elec_nm1_rel_ptiso30_0bin,"Data","L");
  lgnd_elec_nm1_rel_ptiso30_0bin->AddEntry(h_bkgd_elec_nm1_rel_ptiso30_0bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_ptiso30_0bin->Draw();
  
  tc_elec_nm1_rel_ptiso30_0bin->Update();
  
  TLine *elec_nm1_rel_ptiso30_0bin_cut = new TLine(0.14,tc_elec_nm1_rel_ptiso30_0bin->GetUymin(),0.14,tc_elec_nm1_rel_ptiso30_0bin->GetUymax());
  elec_nm1_rel_ptiso30_0bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_ptiso30_0bin_cut->Draw();

  tc_elec_nm1_rel_ptiso30_0bin->SetLogy();
  tc_elec_nm1_rel_ptiso30_0bin->SaveAs("../canvases/latest/h_elec_nm1_rel_ptiso30_0bin.png");


  //////////////////////////////////////////////////
  // elec_nm1_rel_ptiso30_1bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_ptiso30_1bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_ptiso30_1bin");
  TH1F* h_data_elec_nm1_rel_ptiso30_1bin = (TH1F*) dir_data_elec->Get("h_elec_nm1_rel_ptiso30_1bin");
  int n_data_elec_nm1_rel_ptiso30_1bin = h_data_elec_nm1_rel_ptiso30_1bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_ptiso30_1bin = new TCanvas("tc_elec_nm1_rel_ptiso30_1bin","tc_elec_nm1_rel_ptiso30_1bin",0,0,1920,1200);
  tc_elec_nm1_rel_ptiso30_1bin->cd();

  h_data_elec_nm1_rel_ptiso30_1bin->Scale(1/h_data_elec_nm1_rel_ptiso30_1bin->Integral());
  h_data_elec_nm1_rel_ptiso30_1bin->SetLineColor(kRed);
  h_data_elec_nm1_rel_ptiso30_1bin->GetXaxis()->SetTitle("elec_nm1_rel_ptiso30_1bin");
  h_data_elec_nm1_rel_ptiso30_1bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_ptiso30_1bin->Scale(1/h_bkgd_elec_nm1_rel_ptiso30_1bin->Integral());
  h_bkgd_elec_nm1_rel_ptiso30_1bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_ptiso30_1bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_ptiso30_1bin->SetFillColor(0);
  lgnd_elec_nm1_rel_ptiso30_1bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_ptiso30_1bin->AddEntry(h_data_elec_nm1_rel_ptiso30_1bin,"Data","L");
  lgnd_elec_nm1_rel_ptiso30_1bin->AddEntry(h_bkgd_elec_nm1_rel_ptiso30_1bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_ptiso30_1bin->Draw();
  
  tc_elec_nm1_rel_ptiso30_1bin->Update();
  
  TLine *elec_nm1_rel_ptiso30_1bin_cut = new TLine(0.14,tc_elec_nm1_rel_ptiso30_1bin->GetUymin(),0.14,tc_elec_nm1_rel_ptiso30_1bin->GetUymax());
  elec_nm1_rel_ptiso30_1bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_ptiso30_1bin_cut->Draw();

  tc_elec_nm1_rel_ptiso30_1bin->SetLogy();
  tc_elec_nm1_rel_ptiso30_1bin->SaveAs("../canvases/latest/h_elec_nm1_rel_ptiso30_1bin.png");

//////////////////////////////////////////////////
  // elec_nm1_rel_ptiso30_2bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_ptiso30_2bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_ptiso30_2bin");
  TH1F* h_data_elec_nm1_rel_ptiso30_2bin = (TH1F*) dir_data_elec->Get("h_elec_nm1_rel_ptiso30_2bin");
  int n_data_elec_nm1_rel_ptiso30_2bin = h_data_elec_nm1_rel_ptiso30_2bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_ptiso30_2bin = new TCanvas("tc_elec_nm1_rel_ptiso30_2bin","tc_elec_nm1_rel_ptiso30_2bin",0,0,1920,1200);
  tc_elec_nm1_rel_ptiso30_2bin->cd();

  h_data_elec_nm1_rel_ptiso30_2bin->Scale(1/h_data_elec_nm1_rel_ptiso30_2bin->Integral());
  h_data_elec_nm1_rel_ptiso30_2bin->SetLineColor(kRed);
  h_data_elec_nm1_rel_ptiso30_2bin->GetXaxis()->SetTitle("elec_nm1_rel_ptiso30_2bin");
  h_data_elec_nm1_rel_ptiso30_2bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_ptiso30_2bin->Scale(1/h_bkgd_elec_nm1_rel_ptiso30_2bin->Integral());
  h_bkgd_elec_nm1_rel_ptiso30_2bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_ptiso30_2bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_ptiso30_2bin->SetFillColor(0);
  lgnd_elec_nm1_rel_ptiso30_2bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_ptiso30_2bin->AddEntry(h_data_elec_nm1_rel_ptiso30_2bin,"Data","L");
  lgnd_elec_nm1_rel_ptiso30_2bin->AddEntry(h_bkgd_elec_nm1_rel_ptiso30_2bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_ptiso30_2bin->Draw();
  
  tc_elec_nm1_rel_ptiso30_2bin->Update();
  
  TLine *elec_nm1_rel_ptiso30_2bin_cut = new TLine(0.14,tc_elec_nm1_rel_ptiso30_2bin->GetUymin(),0.14,tc_elec_nm1_rel_ptiso30_2bin->GetUymax());
  elec_nm1_rel_ptiso30_2bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_ptiso30_2bin_cut->Draw();

  tc_elec_nm1_rel_ptiso30_2bin->SetLogy();
  tc_elec_nm1_rel_ptiso30_2bin->SaveAs("../canvases/latest/h_elec_nm1_rel_ptiso30_2bin.png");

//////////////////////////////////////////////////
  // elec_nm1_rel_ptiso30_3bin
  //////////////////////////////////////////////////
  
  TH1F* h_bkgd_elec_nm1_rel_ptiso30_3bin = (TH1F*) dir_bkgd_elec->Get("h_elec_nm1_rel_ptiso30_3bin");
  TH1F* h_data_elec_nm1_rel_ptiso30_3bin = (TH1F*) dir_data_elec->Get("h_elec_nm1_rel_ptiso30_3bin");
  int n_data_elec_nm1_rel_ptiso30_3bin = h_data_elec_nm1_rel_ptiso30_3bin->GetEntries();
  
  TCanvas* tc_elec_nm1_rel_ptiso30_3bin = new TCanvas("tc_elec_nm1_rel_ptiso30_3bin","tc_elec_nm1_rel_ptiso30_3bin",0,0,1920,1200);
  tc_elec_nm1_rel_ptiso30_3bin->cd();

  h_data_elec_nm1_rel_ptiso30_3bin->Scale(1/h_data_elec_nm1_rel_ptiso30_3bin->Integral());
  h_data_elec_nm1_rel_ptiso30_3bin->SetLineColor(kRed);
  h_data_elec_nm1_rel_ptiso30_3bin->GetXaxis()->SetTitle("elec_nm1_rel_ptiso30_3bin");
  h_data_elec_nm1_rel_ptiso30_3bin->Draw("HIST");
  h_bkgd_elec_nm1_rel_ptiso30_3bin->Scale(1/h_bkgd_elec_nm1_rel_ptiso30_3bin->Integral());
  h_bkgd_elec_nm1_rel_ptiso30_3bin->Draw("HIST sames");



  TLegend* lgnd_elec_nm1_rel_ptiso30_3bin = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_elec_nm1_rel_ptiso30_3bin->SetFillColor(0);
  lgnd_elec_nm1_rel_ptiso30_3bin->SetTextSize(0.03);
  lgnd_elec_nm1_rel_ptiso30_3bin->AddEntry(h_data_elec_nm1_rel_ptiso30_3bin,"Data","L");
  lgnd_elec_nm1_rel_ptiso30_3bin->AddEntry(h_bkgd_elec_nm1_rel_ptiso30_3bin,"Backgrounds","L");
  lgnd_elec_nm1_rel_ptiso30_3bin->Draw();
  
  tc_elec_nm1_rel_ptiso30_3bin->Update();
  
  TLine *elec_nm1_rel_ptiso30_3bin_cut = new TLine(0.14,tc_elec_nm1_rel_ptiso30_3bin->GetUymin(),0.14,tc_elec_nm1_rel_ptiso30_3bin->GetUymax());
  elec_nm1_rel_ptiso30_3bin_cut->SetLineColor(kBlue);
  elec_nm1_rel_ptiso30_3bin_cut->Draw();

  tc_elec_nm1_rel_ptiso30_3bin->SetLogy();
  tc_elec_nm1_rel_ptiso30_3bin->SaveAs("../canvases/latest/h_elec_nm1_rel_ptiso30_3bin.png");


  //////////////////////////////////////////////////
  // prof_elec_sel_rel_etiso30
  //////////////////////////////////////////////////
  
  TH1F* prof_bkgd_elec_sel_rel_etiso30 = (TH1F*) dir_bkgd_elec->Get("prof_elec_sel_rel_etiso30");
  TH1F* prof_data_elec_sel_rel_etiso30 = (TH1F*) dir_data_elec->Get("prof_elec_sel_rel_etiso30");
  int n_data_elec_sel_rel_etiso30 = prof_data_elec_sel_rel_etiso30->GetEntries();
  
  TCanvas* tc_prof_elec_sel_rel_etiso30 = new TCanvas("tc_prof_elec_sel_rel_etiso30","tc_prof_elec_sel_rel_etiso30",0,0,1920,1200);
  tc_prof_elec_sel_rel_etiso30->cd();
  tc_prof_elec_sel_rel_etiso30->SetGrid();

  //prof_data_elec_sel_rel_etiso30->Scale(1/prof_data_elec_sel_rel_etiso30->Integral());
  prof_data_elec_sel_rel_etiso30->SetLineColor(kRed);
  prof_data_elec_sel_rel_etiso30->GetXaxis()->SetTitle("elec_sel_rel_etiso30");
  prof_data_elec_sel_rel_etiso30->GetYaxis()->SetRangeUser(0,0.035);
  prof_data_elec_sel_rel_etiso30->Draw();
  //prof_bkgd_elec_sel_rel_etiso30->Scale(1/prof_bkgd_elec_sel_rel_etiso30->Integral());
  prof_bkgd_elec_sel_rel_etiso30->Draw("sames");



  TLegend* lgnd_prof_elec_sel_rel_etiso30 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_prof_elec_sel_rel_etiso30->SetFillColor(0);
  lgnd_prof_elec_sel_rel_etiso30->SetTextSize(0.03);
  lgnd_prof_elec_sel_rel_etiso30->AddEntry(prof_data_elec_sel_rel_etiso30,"Data","L");
  lgnd_prof_elec_sel_rel_etiso30->AddEntry(prof_bkgd_elec_sel_rel_etiso30,"Backgrounds","L");
  lgnd_prof_elec_sel_rel_etiso30->Draw();
  
  tc_prof_elec_sel_rel_etiso30->Update();
  
  TLine *elec_sel_rel_etiso30_cut = new TLine(0.14,tc_prof_elec_sel_rel_etiso30->GetUymin(),0.14,tc_prof_elec_sel_rel_etiso30->GetUymax());
  elec_sel_rel_etiso30_cut->SetLineColor(kBlue);
  elec_sel_rel_etiso30_cut->Draw();

  tc_prof_elec_sel_rel_etiso30->SaveAs("../canvases/latest/prof_elec_sel_rel_etiso30.png");

  //////////////////////////////////////////////////
  // prof_elec_sel_rel_ptiso30
  //////////////////////////////////////////////////
  
  TH1F* prof_bkgd_elec_sel_rel_ptiso30 = (TH1F*) dir_bkgd_elec->Get("prof_elec_sel_rel_ptiso30");
  TH1F* prof_data_elec_sel_rel_ptiso30 = (TH1F*) dir_data_elec->Get("prof_elec_sel_rel_ptiso30");
  int n_data_elec_sel_rel_ptiso30 = prof_data_elec_sel_rel_ptiso30->GetEntries();
  
  TCanvas* tc_prof_elec_sel_rel_ptiso30 = new TCanvas("tc_prof_elec_sel_rel_ptiso30","tc_prof_elec_sel_rel_ptiso30",0,0,1920,1200);
  tc_prof_elec_sel_rel_ptiso30->cd();
  tc_prof_elec_sel_rel_ptiso30->SetGrid();

  //prof_data_elec_sel_rel_ptiso30->Scale(1/prof_data_elec_sel_rel_ptiso30->Integral());
  prof_data_elec_sel_rel_ptiso30->SetLineColor(kRed);
  prof_data_elec_sel_rel_ptiso30->GetXaxis()->SetTitle("elec_sel_rel_ptiso30");
  prof_data_elec_sel_rel_ptiso30->Draw();
  //prof_bkgd_elec_sel_rel_ptiso30->Scale(1/prof_bkgd_elec_sel_rel_ptiso30->Integral());
  prof_bkgd_elec_sel_rel_ptiso30->Draw("sames");



  TLegend* lgnd_prof_elec_sel_rel_ptiso30 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_prof_elec_sel_rel_ptiso30->SetFillColor(0);
  lgnd_prof_elec_sel_rel_ptiso30->SetTextSize(0.03);
  lgnd_prof_elec_sel_rel_ptiso30->AddEntry(prof_data_elec_sel_rel_ptiso30,"Data","L");
  lgnd_prof_elec_sel_rel_ptiso30->AddEntry(prof_bkgd_elec_sel_rel_ptiso30,"Backgrounds","L");
  lgnd_prof_elec_sel_rel_ptiso30->Draw();
  
  tc_prof_elec_sel_rel_ptiso30->Update();
  
  TLine *elec_sel_rel_ptiso30_cut = new TLine(0.14,tc_prof_elec_sel_rel_ptiso30->GetUymin(),0.14,tc_prof_elec_sel_rel_ptiso30->GetUymax());
  elec_sel_rel_ptiso30_cut->SetLineColor(kBlue);
  elec_sel_rel_ptiso30_cut->Draw();

  tc_prof_elec_sel_rel_ptiso30->SaveAs("../canvases/latest/prof_elec_sel_rel_ptiso30.png");


  //////////////////////////////////////////////////
  // prof_elec_sel_rel_etiso20
  //////////////////////////////////////////////////
  
  TH1F* prof_bkgd_elec_sel_rel_etiso20 = (TH1F*) dir_bkgd_elec->Get("prof_elec_sel_rel_etiso20");
  TH1F* prof_data_elec_sel_rel_etiso20 = (TH1F*) dir_data_elec->Get("prof_elec_sel_rel_etiso20");
  int n_data_elec_sel_rel_etiso20 = prof_data_elec_sel_rel_etiso20->GetEntries();
  
  TCanvas* tc_prof_elec_sel_rel_etiso20 = new TCanvas("tc_prof_elec_sel_rel_etiso20","tc_prof_elec_sel_rel_etiso20",0,0,1920,1200);
  tc_prof_elec_sel_rel_etiso20->cd();
  tc_prof_elec_sel_rel_etiso20->SetGrid();

  //prof_data_elec_sel_rel_etiso20->Scale(1/prof_data_elec_sel_rel_etiso20->Integral());
  prof_data_elec_sel_rel_etiso20->SetLineColor(kRed);
  prof_data_elec_sel_rel_etiso20->GetXaxis()->SetTitle("elec_sel_rel_etiso20");
  prof_data_elec_sel_rel_etiso20->Draw();
  //prof_bkgd_elec_sel_rel_etiso20->Scale(1/prof_bkgd_elec_sel_rel_etiso20->Integral());
  prof_bkgd_elec_sel_rel_etiso20->Draw("sames");



  TLegend* lgnd_prof_elec_sel_rel_etiso20 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_prof_elec_sel_rel_etiso20->SetFillColor(0);
  lgnd_prof_elec_sel_rel_etiso20->SetTextSize(0.03);
  lgnd_prof_elec_sel_rel_etiso20->AddEntry(prof_data_elec_sel_rel_etiso20,"Data","L");
  lgnd_prof_elec_sel_rel_etiso20->AddEntry(prof_bkgd_elec_sel_rel_etiso20,"Backgrounds","L");
  lgnd_prof_elec_sel_rel_etiso20->Draw();
  
  tc_prof_elec_sel_rel_etiso20->Update();
  
  TLine *elec_sel_rel_etiso20_cut = new TLine(0.14,tc_prof_elec_sel_rel_etiso20->GetUymin(),0.14,tc_prof_elec_sel_rel_etiso20->GetUymax());
  elec_sel_rel_etiso20_cut->SetLineColor(kBlue);
  elec_sel_rel_etiso20_cut->Draw();

  tc_prof_elec_sel_rel_etiso20->SaveAs("../canvases/latest/prof_elec_sel_rel_etiso20.png");

  //////////////////////////////////////////////////
  // prof_elec_sel_rel_ptiso20
  //////////////////////////////////////////////////
  
  TH1F* prof_bkgd_elec_sel_rel_ptiso20 = (TH1F*) dir_bkgd_elec->Get("prof_elec_sel_rel_ptiso20");
  TH1F* prof_data_elec_sel_rel_ptiso20 = (TH1F*) dir_data_elec->Get("prof_elec_sel_rel_ptiso20");
  int n_data_elec_sel_rel_ptiso20 = prof_data_elec_sel_rel_ptiso20->GetEntries();
  
  TCanvas* tc_prof_elec_sel_rel_ptiso20 = new TCanvas("tc_prof_elec_sel_rel_ptiso20","tc_prof_elec_sel_rel_ptiso20",0,0,1920,1200);
  tc_prof_elec_sel_rel_ptiso20->cd();
  tc_prof_elec_sel_rel_ptiso20->SetGrid();

  //prof_data_elec_sel_rel_ptiso20->Scale(1/prof_data_elec_sel_rel_ptiso20->Integral());
  prof_data_elec_sel_rel_ptiso20->SetLineColor(kRed);
  prof_data_elec_sel_rel_ptiso20->GetXaxis()->SetTitle("elec_sel_rel_ptiso20");
  prof_data_elec_sel_rel_ptiso20->Draw();
  //prof_bkgd_elec_sel_rel_ptiso20->Scale(1/prof_bkgd_elec_sel_rel_ptiso20->Integral());
  prof_bkgd_elec_sel_rel_ptiso20->Draw("sames");



  TLegend* lgnd_prof_elec_sel_rel_ptiso20 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_prof_elec_sel_rel_ptiso20->SetFillColor(0);
  lgnd_prof_elec_sel_rel_ptiso20->SetTextSize(0.03);
  lgnd_prof_elec_sel_rel_ptiso20->AddEntry(prof_data_elec_sel_rel_ptiso20,"Data","L");
  lgnd_prof_elec_sel_rel_ptiso20->AddEntry(prof_bkgd_elec_sel_rel_ptiso20,"Backgrounds","L");
  lgnd_prof_elec_sel_rel_ptiso20->Draw();
  
  tc_prof_elec_sel_rel_ptiso20->Update();
  
  TLine *elec_sel_rel_ptiso20_cut = new TLine(0.14,tc_prof_elec_sel_rel_ptiso20->GetUymin(),0.14,tc_prof_elec_sel_rel_ptiso20->GetUymax());
  elec_sel_rel_ptiso20_cut->SetLineColor(kBlue);
  elec_sel_rel_ptiso20_cut->Draw();

  tc_prof_elec_sel_rel_ptiso20->SaveAs("../canvases/latest/prof_elec_sel_rel_ptiso20.png");


  
  //////////////////////////////////////////////////
  // prof_elec_nm1_rel_etiso30
  //////////////////////////////////////////////////
  
  TH1F* prof_bkgd_elec_nm1_rel_etiso30 = (TH1F*) dir_bkgd_elec->Get("prof_elec_nm1_rel_etiso30");
  TH1F* prof_data_elec_nm1_rel_etiso30 = (TH1F*) dir_data_elec->Get("prof_elec_nm1_rel_etiso30");
  int n_data_elec_nm1_rel_etiso30 = prof_data_elec_nm1_rel_etiso30->GetEntries();
  
  TCanvas* tc_prof_elec_nm1_rel_etiso30 = new TCanvas("tc_prof_elec_nm1_rel_etiso30","tc_prof_elec_nm1_rel_etiso30",0,0,1920,1200);
  tc_prof_elec_nm1_rel_etiso30->cd();
  tc_prof_elec_nm1_rel_etiso30->SetGrid();

  //prof_data_elec_nm1_rel_etiso30->Scale(1/prof_data_elec_nm1_rel_etiso30->Integral());
  prof_data_elec_nm1_rel_etiso30->SetLineColor(kRed);
  prof_data_elec_nm1_rel_etiso30->GetXaxis()->SetTitle("elec_nm1_rel_etiso30");
  prof_data_elec_nm1_rel_etiso30->GetYaxis()->SetRangeUser(0,0.15);
  prof_data_elec_nm1_rel_etiso30->Draw();
  //prof_bkgd_elec_nm1_rel_etiso30->Scale(1/prof_bkgd_elec_nm1_rel_etiso30->Integral());
  prof_bkgd_elec_nm1_rel_etiso30->Draw("sames");



  TLegend* lgnd_prof_elec_nm1_rel_etiso30 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_prof_elec_nm1_rel_etiso30->SetFillColor(0);
  lgnd_prof_elec_nm1_rel_etiso30->SetTextSize(0.03);
  lgnd_prof_elec_nm1_rel_etiso30->AddEntry(prof_data_elec_nm1_rel_etiso30,"Data","L");
  lgnd_prof_elec_nm1_rel_etiso30->AddEntry(prof_bkgd_elec_nm1_rel_etiso30,"Backgrounds","L");
  lgnd_prof_elec_nm1_rel_etiso30->Draw();
  
  tc_prof_elec_nm1_rel_etiso30->Update();
  
  TLine *elec_nm1_rel_etiso30_cut = new TLine(0.14,tc_prof_elec_nm1_rel_etiso30->GetUymin(),0.14,tc_prof_elec_nm1_rel_etiso30->GetUymax());
  elec_nm1_rel_etiso30_cut->SetLineColor(kBlue);
  elec_nm1_rel_etiso30_cut->Draw();

  tc_prof_elec_nm1_rel_etiso30->SaveAs("../canvases/latest/prof_elec_nm1_rel_etiso30.png");

  //////////////////////////////////////////////////
  // prof_elec_nm1_rel_ptiso30
  //////////////////////////////////////////////////
  
  TH1F* prof_bkgd_elec_nm1_rel_ptiso30 = (TH1F*) dir_bkgd_elec->Get("prof_elec_nm1_rel_ptiso30");
  TH1F* prof_data_elec_nm1_rel_ptiso30 = (TH1F*) dir_data_elec->Get("prof_elec_nm1_rel_ptiso30");
  int n_data_elec_nm1_rel_ptiso30 = prof_data_elec_nm1_rel_ptiso30->GetEntries();
  
  TCanvas* tc_prof_elec_nm1_rel_ptiso30 = new TCanvas("tc_prof_elec_nm1_rel_ptiso30","tc_prof_elec_nm1_rel_ptiso30",0,0,1920,1200);
  tc_prof_elec_nm1_rel_ptiso30->cd();
  tc_prof_elec_nm1_rel_ptiso30->SetGrid();

  //prof_data_elec_nm1_rel_ptiso30->Scale(1/prof_data_elec_nm1_rel_ptiso30->Integral());
  prof_data_elec_nm1_rel_ptiso30->SetLineColor(kRed);
  prof_data_elec_nm1_rel_ptiso30->GetXaxis()->SetTitle("elec_nm1_rel_ptiso30");
  prof_data_elec_nm1_rel_ptiso30->GetYaxis()->SetRangeUser(0,0.15);
  prof_data_elec_nm1_rel_ptiso30->Draw();
  //prof_bkgd_elec_nm1_rel_ptiso30->Scale(1/prof_bkgd_elec_nm1_rel_ptiso30->Integral());
  prof_bkgd_elec_nm1_rel_ptiso30->Draw("sames");



  TLegend* lgnd_prof_elec_nm1_rel_ptiso30 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_prof_elec_nm1_rel_ptiso30->SetFillColor(0);
  lgnd_prof_elec_nm1_rel_ptiso30->SetTextSize(0.03);
  lgnd_prof_elec_nm1_rel_ptiso30->AddEntry(prof_data_elec_nm1_rel_ptiso30,"Data","L");
  lgnd_prof_elec_nm1_rel_ptiso30->AddEntry(prof_bkgd_elec_nm1_rel_ptiso30,"Backgrounds","L");
  lgnd_prof_elec_nm1_rel_ptiso30->Draw();
  
  tc_prof_elec_nm1_rel_ptiso30->Update();
  
  TLine *elec_nm1_rel_ptiso30_cut = new TLine(0.14,tc_prof_elec_nm1_rel_ptiso30->GetUymin(),0.14,tc_prof_elec_nm1_rel_ptiso30->GetUymax());
  elec_nm1_rel_ptiso30_cut->SetLineColor(kBlue);
  elec_nm1_rel_ptiso30_cut->Draw();

  tc_prof_elec_nm1_rel_ptiso30->SaveAs("../canvases/latest/prof_elec_nm1_rel_ptiso30.png");


  //////////////////////////////////////////////////
  // prof_elec_nm1_rel_etiso20
  //////////////////////////////////////////////////
  
  TH1F* prof_bkgd_elec_nm1_rel_etiso20 = (TH1F*) dir_bkgd_elec->Get("prof_elec_nm1_rel_etiso20");
  TH1F* prof_data_elec_nm1_rel_etiso20 = (TH1F*) dir_data_elec->Get("prof_elec_nm1_rel_etiso20");
  int n_data_elec_nm1_rel_etiso20 = prof_data_elec_nm1_rel_etiso20->GetEntries();
  
  TCanvas* tc_prof_elec_nm1_rel_etiso20 = new TCanvas("tc_prof_elec_nm1_rel_etiso20","tc_prof_elec_nm1_rel_etiso20",0,0,1920,1200);
  tc_prof_elec_nm1_rel_etiso20->cd();
  tc_prof_elec_nm1_rel_etiso20->SetGrid();

  //prof_data_elec_nm1_rel_etiso20->Scale(1/prof_data_elec_nm1_rel_etiso20->Integral());
  prof_data_elec_nm1_rel_etiso20->SetLineColor(kRed);
  prof_data_elec_nm1_rel_etiso20->GetXaxis()->SetTitle("elec_nm1_rel_etiso20");
  prof_data_elec_nm1_rel_etiso20->GetYaxis()->SetRangeUser(0,0.09);
  prof_data_elec_nm1_rel_etiso20->Draw();
  //prof_bkgd_elec_nm1_rel_etiso20->Scale(1/prof_bkgd_elec_nm1_rel_etiso20->Integral());
  prof_bkgd_elec_nm1_rel_etiso20->Draw("sames");



  TLegend* lgnd_prof_elec_nm1_rel_etiso20 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_prof_elec_nm1_rel_etiso20->SetFillColor(0);
  lgnd_prof_elec_nm1_rel_etiso20->SetTextSize(0.03);
  lgnd_prof_elec_nm1_rel_etiso20->AddEntry(prof_data_elec_nm1_rel_etiso20,"Data","L");
  lgnd_prof_elec_nm1_rel_etiso20->AddEntry(prof_bkgd_elec_nm1_rel_etiso20,"Backgrounds","L");
  lgnd_prof_elec_nm1_rel_etiso20->Draw();
  
  tc_prof_elec_nm1_rel_etiso20->Update();
  
  TLine *elec_nm1_rel_etiso20_cut = new TLine(0.14,tc_prof_elec_nm1_rel_etiso20->GetUymin(),0.14,tc_prof_elec_nm1_rel_etiso20->GetUymax());
  elec_nm1_rel_etiso20_cut->SetLineColor(kBlue);
  elec_nm1_rel_etiso20_cut->Draw();

  tc_prof_elec_nm1_rel_etiso20->SaveAs("../canvases/latest/prof_elec_nm1_rel_etiso20.png");

  //////////////////////////////////////////////////
  // prof_elec_nm1_rel_ptiso20
  //////////////////////////////////////////////////
  
  TH1F* prof_bkgd_elec_nm1_rel_ptiso20 = (TH1F*) dir_bkgd_elec->Get("prof_elec_nm1_rel_ptiso20");
  TH1F* prof_data_elec_nm1_rel_ptiso20 = (TH1F*) dir_data_elec->Get("prof_elec_nm1_rel_ptiso20");
  int n_data_elec_nm1_rel_ptiso20 = prof_data_elec_nm1_rel_ptiso20->GetEntries();
  
  TCanvas* tc_prof_elec_nm1_rel_ptiso20 = new TCanvas("tc_prof_elec_nm1_rel_ptiso20","tc_prof_elec_nm1_rel_ptiso20",0,0,1920,1200);
  tc_prof_elec_nm1_rel_ptiso20->cd();
  tc_prof_elec_nm1_rel_ptiso20->SetGrid();

  prof_data_elec_nm1_rel_ptiso20->SetLineColor(kRed);
  prof_data_elec_nm1_rel_ptiso20->GetXaxis()->SetTitle("elec_nm1_rel_ptiso20");
  prof_data_elec_nm1_rel_ptiso20->GetYaxis()->SetRangeUser(0,0.09);
  prof_data_elec_nm1_rel_ptiso20->Draw();
  prof_bkgd_elec_nm1_rel_ptiso20->Draw("sames");



  TLegend* lgnd_prof_elec_nm1_rel_ptiso20 = new TLegend(0.6,0.78,0.8,0.9);
  lgnd_prof_elec_nm1_rel_ptiso20->SetFillColor(0);
  lgnd_prof_elec_nm1_rel_ptiso20->SetTextSize(0.03);
  lgnd_prof_elec_nm1_rel_ptiso20->AddEntry(prof_data_elec_nm1_rel_ptiso20,"Data","L");
  lgnd_prof_elec_nm1_rel_ptiso20->AddEntry(prof_bkgd_elec_nm1_rel_ptiso20,"Backgrounds","L");
  lgnd_prof_elec_nm1_rel_ptiso20->Draw();
  
  tc_prof_elec_nm1_rel_ptiso20->Update();
  
  TLine *elec_nm1_rel_ptiso20_cut = new TLine(0.14,tc_prof_elec_nm1_rel_ptiso20->GetUymin(),0.14,tc_prof_elec_nm1_rel_ptiso20->GetUymax());
  elec_nm1_rel_ptiso20_cut->SetLineColor(kBlue);
  elec_nm1_rel_ptiso20_cut->Draw();

  tc_prof_elec_nm1_rel_ptiso20->SaveAs("../canvases/latest/prof_elec_nm1_rel_ptiso20.png");


  

  gROOT->ProcessLine(".q");
xo  return;
}
  
