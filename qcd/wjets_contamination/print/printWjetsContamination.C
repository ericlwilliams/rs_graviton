#include <TCanvas.h>
#include <TPad.h>
#include <TGraph.h>
#include <TFile.h>
#include <TDirectory.h>
#include "../../../include/atlasstyle-00-03-04/AtlasStyle.C";

void printWjetsContamination(){

  SetAtlasStyle();
  gROOT->SetBatch();
  
  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In printWjetsContamination.C"<<endl;
  string save_loc = "../canvases/latest/";
  string cur_saveas="";

  
  TFile* qcd_raw_elec = (TFile*) TFile::Open("../plots/qcd.elec.raw.root");
  TH1F* h_qcd_raw_elec_lep_met_mt = (TH1F*) qcd_raw_elec->Get("loose/h_elec_lep_met_mt");
  h_qcd_raw_elec_lep_met_mt->SetDirectory(0);
  float n_raw_elec_qcd = h_qcd_raw_elec_lep_met_mt->Integral();
  qcd_raw_elec->Close();

  TFile* qcd_raw_muon = (TFile*) TFile::Open("../plots/qcd.muon.raw.root");
  TH1F* h_qcd_raw_muon_lep_met_mt = (TH1F*) qcd_raw_muon->Get("loose/h_muon_lep_met_mt");
  h_qcd_raw_muon_lep_met_mt->SetDirectory(0);
  float n_raw_muon_qcd = h_qcd_raw_muon_lep_met_mt->Integral();
  qcd_raw_muon->Close();

  TFile* wjets_cont = (TFile*) TFile::Open("../plots/mc.alpgen.cont.wjets.plot.root");
  TH1F* h_wjets_cont_elec_lep_met_mt = (TH1F*) wjets_cont->Get("loose/h_elec_lep_met_mt");
  h_wjets_cont_elec_lep_met_mt->SetDirectory(0);
  float n_elec_wjets_cont =   h_wjets_cont_elec_lep_met_mt->Integral();
  TH1F* h_wjets_cont_muon_lep_met_mt = (TH1F*) wjets_cont->Get("loose/h_muon_lep_met_mt");
  h_wjets_cont_muon_lep_met_mt->SetDirectory(0);
  float n_muon_wjets_cont =   h_wjets_cont_muon_lep_met_mt->Integral();
  wjets_cont->Close();

  TFile* qcd_noadj = (TFile*) TFile::Open("../plots/qcd.scaled.noadj.root");
  TH1F* h_qcd_noadj_elec_lep_met_mt = (TH1F*) qcd_noadj->Get("loose/h_elec_lep_met_mt");
  h_qcd_noadj_elec_lep_met_mt->SetDirectory(0);
  TH1F* h_qcd_noadj_muon_lep_met_mt = (TH1F*) qcd_noadj->Get("loose/h_muon_lep_met_mt");
  h_qcd_noadj_muon_lep_met_mt->SetDirectory(0);
  qcd_noadj->Close();

  TFile* qcd_adj = (TFile*) TFile::Open("../plots/qcd.scaled.adj.root");
  TH1F* h_qcd_adj_elec_lep_met_mt = (TH1F*) qcd_adj->Get("loose/h_elec_lep_met_mt");
  h_qcd_adj_elec_lep_met_mt->SetDirectory(0);
  TH1F* h_qcd_adj_muon_lep_met_mt = (TH1F*) qcd_adj->Get("loose/h_muon_lep_met_mt");
  h_qcd_adj_muon_lep_met_mt->SetDirectory(0);
  qcd_adj->Close();


  
  TCanvas* tc_elec_wjets_qcd_lep_met_mt =
    new TCanvas("tc_elec_wjets_qcd_lep_met_mt","tc_elec_wjets_qcd_lep_met_mt",0,0,1920,1200);
  tc_elec_wjets_qcd_lep_met_mt->cd();

  h_qcd_raw_elec_lep_met_mt->GetXaxis()->SetTitle("M_{T}(e,E_{T}^{miss}) [GeV]");
  h_qcd_raw_elec_lep_met_mt->GetYaxis()->SetTitle("Events");
  h_qcd_raw_elec_lep_met_mt->GetYaxis()->SetTitleOffset(0.8);
  h_qcd_raw_elec_lep_met_mt->Draw("hist");

  h_wjets_cont_elec_lep_met_mt->SetLineColor(kRed);
  h_wjets_cont_elec_lep_met_mt->Draw("hist same");

  tc_elec_wjets_qcd_lep_met_mt->SetLogy();
  tc_elec_wjets_qcd_lep_met_mt->Update();

  TLegend* lgnd_elec_wjets_qcd_lep_met_mt = new TLegend(0.50,0.75,0.9,0.90);
  lgnd_elec_wjets_qcd_lep_met_mt->SetFillColor(0);
  lgnd_elec_wjets_qcd_lep_met_mt->SetTextSize(0.05);
  lgnd_elec_wjets_qcd_lep_met_mt->SetBorderSize(0);
  lgnd_elec_wjets_qcd_lep_met_mt->AddEntry(h_qcd_raw_elec_lep_met_mt,"Unscaled QCD","L");
  lgnd_elec_wjets_qcd_lep_met_mt->AddEntry(h_wjets_cont_elec_lep_met_mt,"W+jets contamination","L");
  lgnd_elec_wjets_qcd_lep_met_mt->Draw();

  cur_saveas = save_loc+"h_elec_wjets_qcd_lep_met_mt.pdf";
  tc_elec_wjets_qcd_lep_met_mt->SaveAs(cur_saveas.c_str());
  
  TCanvas* tc_muon_wjets_qcd_lep_met_mt =
    new TCanvas("tc_muon_wjets_qcd_lep_met_mt","tc_muon_wjets_qcd_lep_met_mt",0,0,1920,1200);
  tc_muon_wjets_qcd_lep_met_mt->cd();

  h_qcd_raw_muon_lep_met_mt->GetXaxis()->SetTitle("M_{T}(#mu,E_{T}^{miss}) [GeV]");
  h_qcd_raw_muon_lep_met_mt->GetYaxis()->SetTitle("Events");
  h_qcd_raw_muon_lep_met_mt->GetYaxis()->SetTitleOffset(0.8);
  h_qcd_raw_muon_lep_met_mt->Draw("hist");

  h_wjets_cont_muon_lep_met_mt->SetLineColor(kRed);
  h_wjets_cont_muon_lep_met_mt->Draw("hist same");

  tc_muon_wjets_qcd_lep_met_mt->SetLogy();
  tc_muon_wjets_qcd_lep_met_mt->Update();

  TLegend* lgnd_muon_wjets_qcd_lep_met_mt = new TLegend(0.50,0.75,0.9,0.90);
  lgnd_muon_wjets_qcd_lep_met_mt->SetFillColor(0);
  lgnd_muon_wjets_qcd_lep_met_mt->SetTextSize(0.05);
  lgnd_muon_wjets_qcd_lep_met_mt->SetBorderSize(0);
  lgnd_muon_wjets_qcd_lep_met_mt->AddEntry(h_qcd_raw_muon_lep_met_mt,"Unscaled QCD","L");
  lgnd_muon_wjets_qcd_lep_met_mt->AddEntry(h_wjets_cont_muon_lep_met_mt,"W+jets contamination","L");
  lgnd_muon_wjets_qcd_lep_met_mt->Draw();

  cur_saveas = save_loc+"h_muon_wjets_qcd_lep_met_mt.pdf";
  tc_muon_wjets_qcd_lep_met_mt->SaveAs(cur_saveas.c_str());
  
//////////////////////////////////////////////////
//////////////////////////////////////////////////

  TCanvas* tc_elec_qcd_adj_lep_met_mt =
    new TCanvas("tc_elec_qcd_adj_lep_met_mt","tc_elec_qcd_adj_lep_met_mt",0,0,1920,1200);
  tc_elec_qcd_adj_lep_met_mt->cd();

  h_qcd_noadj_elec_lep_met_mt->GetXaxis()->SetTitle("M_{T}(e,E_{T}^{miss}) [GeV]");
  h_qcd_noadj_elec_lep_met_mt->GetYaxis()->SetTitle("Events");
  h_qcd_noadj_elec_lep_met_mt->GetYaxis()->SetTitleOffset(0.8);
  h_qcd_noadj_elec_lep_met_mt->Draw("hist");

  h_qcd_adj_elec_lep_met_mt->SetLineColor(kRed);
  h_qcd_adj_elec_lep_met_mt->Draw("hist same");

  tc_elec_qcd_adj_lep_met_mt->SetLogy();
  tc_elec_qcd_adj_lep_met_mt->Update();

  TLegend* lgnd_elec_qcd_adj_lep_met_mt = new TLegend(0.50,0.75,0.9,0.90);
  lgnd_elec_qcd_adj_lep_met_mt->SetFillColor(0);
  lgnd_elec_qcd_adj_lep_met_mt->SetTextSize(0.05);
  lgnd_elec_qcd_adj_lep_met_mt->SetBorderSize(0);
  lgnd_elec_qcd_adj_lep_met_mt->AddEntry(h_qcd_noadj_elec_lep_met_mt,"QCD w/out W+jets sub","L");
  lgnd_elec_qcd_adj_lep_met_mt->AddEntry(h_qcd_adj_elec_lep_met_mt,"QCD w/ W+jets sub","L");
  lgnd_elec_qcd_adj_lep_met_mt->Draw();

  cur_saveas = save_loc+"h_elec_qcd_adj_lep_met_mt.pdf";
  tc_elec_qcd_adj_lep_met_mt->SaveAs(cur_saveas.c_str());

  
  TCanvas* tc_muon_qcd_adj_lep_met_mt =
    new TCanvas("tc_muon_qcd_adj_lep_met_mt","tc_muon_qcd_adj_lep_met_mt",0,0,1920,1200);
  tc_muon_qcd_adj_lep_met_mt->cd();

  h_qcd_noadj_muon_lep_met_mt->GetXaxis()->SetTitle("M_{T}(#mu,E_{T}^{miss}) [GeV]");
  h_qcd_noadj_muon_lep_met_mt->GetYaxis()->SetTitle("Events");
  h_qcd_noadj_muon_lep_met_mt->GetYaxis()->SetTitleOffset(0.8);
  h_qcd_noadj_muon_lep_met_mt->Draw("hist");

  h_qcd_adj_muon_lep_met_mt->SetLineColor(kRed);
  h_qcd_adj_muon_lep_met_mt->Draw("hist same");

  tc_muon_qcd_adj_lep_met_mt->SetLogy();
  tc_muon_qcd_adj_lep_met_mt->Update();

  TLegend* lgnd_muon_qcd_adj_lep_met_mt = new TLegend(0.50,0.75,0.9,0.90);
  lgnd_muon_qcd_adj_lep_met_mt->SetFillColor(0);
  lgnd_muon_qcd_adj_lep_met_mt->SetTextSize(0.05);
  lgnd_muon_qcd_adj_lep_met_mt->SetBorderSize(0);
  lgnd_muon_qcd_adj_lep_met_mt->AddEntry(h_qcd_noadj_muon_lep_met_mt,"QCD w/out W+jets sub","L");
  lgnd_muon_qcd_adj_lep_met_mt->AddEntry(h_qcd_adj_muon_lep_met_mt,"QCD w/ W+jets sub","L");
  lgnd_muon_qcd_adj_lep_met_mt->Draw();

  cur_saveas = save_loc+"h_muon_qcd_adj_lep_met_mt.pdf";
  tc_muon_qcd_adj_lep_met_mt->SaveAs(cur_saveas.c_str());
    
  cout<<"Electron channel W+jets contamination:\t"<<n_elec_wjets_cont/n_raw_elec_qcd<<endl;
  cout<<"Muon channel W+jets contamination:\t"<<n_muon_wjets_cont/n_raw_muon_qcd<<endl;
  
  gROOT->ProcessLine(".q");
  return;
}
