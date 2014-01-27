#include "../../include/atlasstyle-00-03-04/AtlasStyle.C";
void printTriangleCuts(){

  SetAtlasStyle();
  
  gROOT->SetBatch();
  gStyle->SetPalette(1);

  // gStyle->SetOptStat(0);
  // Int_t icol=0; // WHITE
  // gStyle->SetFrameBorderMode(icol);
  // gStyle->SetFrameFillColor(icol);
  // gStyle->SetCanvasBorderMode(icol);
  // gStyle->SetCanvasColor(icol);
  // gStyle->SetPadBorderMode(icol);
  // gStyle->SetPadColor(icol);
  // gStyle->SetStatColor(icol);
  // gStyle->SetOptTitle(0);

  // atlasStyle->SetTitleXOffset(1.4);
  gStyle->SetTitleYOffset(1.0);
  gStyle->SetTitleXOffset(1.2);

  gStyle->SetPadRightMargin(0.1);
  gStyle->SetPadLeftMargin(0.12);
  // gStyle->SetTitleSize(0.05,"x");
  // gStyle->SetTitleSize(0.05,"y");  
  

TFile* wjets = (TFile*) TFile::Open("../plots/wjets.tri.plots.root","READ");
  TH1F* h_wjets_elec_lep_met_mt = (TH1F*) wjets->Get("h_elec_lep_met_mt");
  h_wjets_elec_lep_met_mt->SetDirectory(0);
  TH1F* h_wjets_muon_lep_met_mt = (TH1F*) wjets->Get("h_elec_lep_met_mt");
  h_wjets_muon_lep_met_mt->SetDirectory(0);

  TH2F* scat_wjets_elec_lep_met_dphi_met = (TH2F*) wjets->Get("scat_elec_lep_met_dphi_met");
  scat_wjets_elec_lep_met_dphi_met->SetDirectory(0);
  TH2F* scat_wjets_muon_lep_met_dphi_met = (TH2F*) wjets->Get("scat_muon_lep_met_dphi_met");
  scat_wjets_muon_lep_met_dphi_met->SetDirectory(0);
  
  wjets->Close();

  
  TFile* qcd = (TFile*) TFile::Open("../plots/qcd.tri.plots.root","READ");
  TH1F* h_qcd_elec_lep_met_mt = (TH1F*) qcd->Get("h_elec_lep_met_mt");
  h_qcd_elec_lep_met_mt->SetDirectory(0);
  TH1F* h_qcd_muon_lep_met_mt = (TH1F*) qcd->Get("h_elec_lep_met_mt");
  h_qcd_muon_lep_met_mt->SetDirectory(0);
  
  TH2F* scat_qcd_elec_lep_met_dphi_met = (TH2F*) qcd->Get("scat_elec_lep_met_dphi_met");
  scat_qcd_elec_lep_met_dphi_met->SetDirectory(0);
  TH2F* scat_qcd_muon_lep_met_dphi_met = (TH2F*) qcd->Get("scat_muon_lep_met_dphi_met");
  scat_qcd_muon_lep_met_dphi_met->SetDirectory(0);
  
  qcd->Close();

  TFile* data = (TFile*) TFile::Open("../plots/data.tri.plots.root","READ");
  TH1F* h_data_elec_lep_met_mt = (TH1F*) data->Get("h_elec_lep_met_mt");
  h_data_elec_lep_met_mt->SetDirectory(0);
  TH1F* h_data_muon_lep_met_mt = (TH1F*) data->Get("h_elec_lep_met_mt");
  h_data_muon_lep_met_mt->SetDirectory(0);
  
  TH2F* scat_data_elec_lep_met_dphi_met = (TH2F*) data->Get("scat_elec_lep_met_dphi_met");
  scat_data_elec_lep_met_dphi_met->SetDirectory(0);
  TH2F* scat_data_muon_lep_met_dphi_met = (TH2F*) data->Get("scat_muon_lep_met_dphi_met");
  scat_data_muon_lep_met_dphi_met->SetDirectory(0);
  
  data->Close();


  TFile* sig = (TFile*) TFile::Open("../plots/sig.tri.plots.root","READ");
  TH1F* h_sig_elec_lep_met_mt = (TH1F*) sig->Get("h_elec_lep_met_mt");
  h_sig_elec_lep_met_mt->SetDirectory(0);
  TH1F* h_sig_muon_lep_met_mt = (TH1F*) sig->Get("h_elec_lep_met_mt");
  h_sig_muon_lep_met_mt->SetDirectory(0);

  TH2F* scat_sig_elec_lep_met_dphi_met = (TH2F*) sig->Get("scat_elec_lep_met_dphi_met");
  scat_sig_elec_lep_met_dphi_met->SetDirectory(0);
  TH2F* scat_sig_muon_lep_met_dphi_met = (TH2F*) sig->Get("scat_muon_lep_met_dphi_met");
  scat_sig_muon_lep_met_dphi_met->SetDirectory(0);

  sig->Close();


  TCanvas* tc_tri_elec_lep_met_mt = new TCanvas("tc_tri_elec_lep_met_mt","tc_tri_elec_lep_met_mt",0,0,1920,1200);
  tc_tri_elec_lep_met_mt->cd();

  h_qcd_elec_lep_met_mt->SetLineColor(kRed);
  h_qcd_elec_lep_met_mt->Scale(1./h_qcd_elec_lep_met_mt->Integral());
  h_qcd_elec_lep_met_mt->Draw();

  h_sig_elec_lep_met_mt->SetLineColor(kGreen);
  h_sig_elec_lep_met_mt->Scale(1./h_sig_elec_lep_met_mt->Integral());
  h_sig_elec_lep_met_mt->Draw("same");

  h_wjets_elec_lep_met_mt->SetLineColor(kBlue);
  h_wjets_elec_lep_met_mt->Scale(1./h_wjets_elec_lep_met_mt->Integral());
  h_wjets_elec_lep_met_mt->Draw("same");

  

  TLegend* lgnd_tri_elec_lep_met_mt = new TLegend(0.80,0.5,0.92,0.92);
  lgnd_tri_elec_lep_met_mt->SetFillColor(0);
  lgnd_tri_elec_lep_met_mt->SetBorderSize(0);
  lgnd_tri_elec_lep_met_mt->SetTextSize(0.03);
  lgnd_tri_elec_lep_met_mt->AddEntry(h_wjets_elec_lep_met_mt,"wjets","F");
  lgnd_tri_elec_lep_met_mt->AddEntry(h_qcd_elec_lep_met_mt,"qcd","F");
  lgnd_tri_elec_lep_met_mt->AddEntry(h_sig_elec_lep_met_mt,"sig","F");
  lgnd_tri_elec_lep_met_mt->Draw();
  tc_tri_elec_lep_met_mt->Update();

  string cur_saveas = "../canvases/latest/h_tri_elec_lep_met_mt.pdf";
  tc_tri_elec_lep_met_mt->SaveAs(cur_saveas.c_str());

  TLine* tri_line = new TLine(40,1.5,75,0.0);
  tri_line->SetLineWidth(2);
  tri_line->SetLineColor(kMagenta);

  TText* reject_text = new TText(47,0.9,"REJECT");
  reject_text->SetTextSize(0.04);
  reject_text->SetTextAngle(-53);
  
  
  TLine* tri_line_2 = new TLine(40,2,75,TMath::Pi());
  tri_line_2->SetLineWidth(2);
  tri_line_2->SetLineColor(kMagenta);

  TText* reject_text_2 = new TText(51,2.46,"REJECT");
  reject_text_2->SetTextSize(0.04);
  reject_text_2->SetTextAngle(+47);
  

  //qcd
  TCanvas* tc_qcd_elec_lep_met_dphi_met = new TCanvas("tc_qcd_elec_lep_met_dphi_met","tc_qcd_elec_lep_met_dphi_met",0,0,1920,1200);
  tc_qcd_elec_lep_met_dphi_met->cd();

  scat_qcd_elec_lep_met_dphi_met->GetZaxis()->SetLabelSize(0);
  scat_qcd_elec_lep_met_dphi_met->GetXaxis()->SetTitle("E_{T}^{miss} [GeV]");
  scat_qcd_elec_lep_met_dphi_met->GetXaxis()->SetTitleSize(0.05);
  scat_qcd_elec_lep_met_dphi_met->GetYaxis()->SetTitle("#Delta#phi(lepton,E_{T}^{miss}) [Rad]");
  scat_qcd_elec_lep_met_dphi_met->GetYaxis()->SetTitleSize(0.05);
  scat_qcd_elec_lep_met_dphi_met->Draw("COLZ");
  tri_line->Draw();
  reject_text->Draw();
  tri_line_2->Draw();
  reject_text_2->Draw();
  
  tc_qcd_elec_lep_met_dphi_met->Update();

  cur_saveas = "../canvases/latest/scat_qcd_elec_lep_met_dphi_met.pdf";
  tc_qcd_elec_lep_met_dphi_met->SaveAs(cur_saveas.c_str());


  //data
  TCanvas* tc_data_elec_lep_met_dphi_met = new TCanvas("tc_data_elec_lep_met_dphi_met","tc_data_elec_lep_met_dphi_met",0,0,1920,1200);
  tc_data_elec_lep_met_dphi_met->cd();

  scat_data_elec_lep_met_dphi_met->GetZaxis()->SetLabelSize(0);
  scat_data_elec_lep_met_dphi_met->GetXaxis()->SetTitle("E_{T}^{miss} [GeV]");
  scat_data_elec_lep_met_dphi_met->GetYaxis()->SetTitle("#Delta#phi(lepton,E_{T}^{miss}) [Rad]");
  scat_data_elec_lep_met_dphi_met->Draw("COLZ");
  tri_line->Draw();
  reject_text->Draw();
  tri_line_2->Draw();
  reject_text_2->Draw();
  
  tc_data_elec_lep_met_dphi_met->Update();

  cur_saveas = "../canvases/latest/scat_data_elec_lep_met_dphi_met.pdf";
  tc_data_elec_lep_met_dphi_met->SaveAs(cur_saveas.c_str());


  //wjets
  TCanvas* tc_wjets_elec_lep_met_dphi_met = new TCanvas("tc_wjets_elec_lep_met_dphi_met","tc_wjets_elec_lep_met_dphi_met",0,0,1920,1200);
  tc_wjets_elec_lep_met_dphi_met->cd();

  scat_wjets_elec_lep_met_dphi_met->GetXaxis()->SetTitle("E_{T}^{miss} [GeV]");
  scat_wjets_elec_lep_met_dphi_met->GetYaxis()->SetTitle("#Delta#phi(lepton,E_{T}^{miss}) [Rad]");
  scat_wjets_elec_lep_met_dphi_met->GetZaxis()->SetLabelSize(0);
  scat_wjets_elec_lep_met_dphi_met->Draw("COLZ");
  tri_line->Draw();
  reject_text->Draw();
  tri_line_2->Draw();
  reject_text_2->Draw();
  tc_wjets_elec_lep_met_dphi_met->Update();

  cur_saveas = "../canvases/latest/scat_wjets_elec_lep_met_dphi_met.pdf";
  tc_wjets_elec_lep_met_dphi_met->SaveAs(cur_saveas.c_str());


  //sig
  TCanvas* tc_sig_elec_lep_met_dphi_met = new TCanvas("tc_sig_elec_lep_met_dphi_met","tc_sig_elec_lep_met_dphi_met",0,0,1920,1200);
  tc_sig_elec_lep_met_dphi_met->cd();

  scat_sig_elec_lep_met_dphi_met->GetXaxis()->SetTitle("E_{T}^{miss} [GeV]");
  scat_sig_elec_lep_met_dphi_met->GetYaxis()->SetTitle("#Delta#phi(lepton,E_{T}^{miss}) [Rad]");
  scat_sig_elec_lep_met_dphi_met->GetZaxis()->SetLabelSize(0);
  scat_sig_elec_lep_met_dphi_met->Draw("COLZ");
  tri_line->Draw();
  reject_text->Draw();
  tri_line_2->Draw();
  reject_text_2->Draw();

  tc_sig_elec_lep_met_dphi_met->Update();

  cur_saveas = "../canvases/latest/scat_sig_elec_lep_met_dphi_met.pdf";
  tc_sig_elec_lep_met_dphi_met->SaveAs(cur_saveas.c_str());


  //data
  TCanvas* tc_data_muon_lep_met_dphi_met = new TCanvas("tc_data_muon_lep_met_dphi_met","tc_data_muon_lep_met_dphi_met",0,0,1920,1200);
  tc_data_muon_lep_met_dphi_met->cd();

  scat_data_muon_lep_met_dphi_met->GetXaxis()->SetTitle("E_{T}^{miss} [GeV]");
  scat_data_muon_lep_met_dphi_met->GetYaxis()->SetTitle("#Delta#phi(lepton,E_{T}^{miss}) [Rad]");
  scat_data_muon_lep_met_dphi_met->GetZaxis()->SetLabelSize(0);
  scat_data_muon_lep_met_dphi_met->Draw("COLZ");
  tri_line->Draw();
  reject_text->Draw();
  tc_data_muon_lep_met_dphi_met->Update();

  cur_saveas = "../canvases/latest/scat_data_muon_lep_met_dphi_met.pdf";
  tc_data_muon_lep_met_dphi_met->SaveAs(cur_saveas.c_str());


  //wjets
  TCanvas* tc_wjets_muon_lep_met_dphi_met = new TCanvas("tc_wjets_muon_lep_met_dphi_met","tc_wjets_muon_lep_met_dphi_met",0,0,1920,1200);
  tc_wjets_muon_lep_met_dphi_met->cd();

  scat_wjets_muon_lep_met_dphi_met->GetXaxis()->SetTitle("E_{T}^{miss} [GeV]");
  scat_wjets_muon_lep_met_dphi_met->GetYaxis()->SetTitle("#Delta#phi(lepton,E_{T}^{miss}) [Rad]");
  scat_wjets_muon_lep_met_dphi_met->GetZaxis()->SetLabelSize(0);
  scat_wjets_muon_lep_met_dphi_met->Draw("COLZ");
  tri_line->Draw();
  reject_text->Draw();
  tc_wjets_muon_lep_met_dphi_met->Update();

  cur_saveas = "../canvases/latest/scat_wjets_muon_lep_met_dphi_met.pdf";
  tc_wjets_muon_lep_met_dphi_met->SaveAs(cur_saveas.c_str());


  //sig
  TCanvas* tc_sig_muon_lep_met_dphi_met = new TCanvas("tc_sig_muon_lep_met_dphi_met","tc_sig_muon_lep_met_dphi_met",0,0,1920,1200);
  tc_sig_muon_lep_met_dphi_met->cd();

  scat_sig_muon_lep_met_dphi_met->GetXaxis()->SetTitle("E_{T}^{miss} [GeV]");
  scat_sig_muon_lep_met_dphi_met->GetYaxis()->SetTitle("#Delta#phi(lepton,E_{T}^{miss}) [Rad]");
  scat_sig_muon_lep_met_dphi_met->GetZaxis()->SetLabelSize(0);
  scat_sig_muon_lep_met_dphi_met->Draw("COLZ");
  tri_line->Draw();
  reject_text->Draw();

  tc_sig_muon_lep_met_dphi_met->Update();

  cur_saveas = "../canvases/latest/scat_sig_muon_lep_met_dphi_met.pdf";
  tc_sig_muon_lep_met_dphi_met->SaveAs(cur_saveas.c_str());



  return;
}
