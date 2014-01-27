#include <TProfile.h>
#include <TMultiGraph.h>

void printVerification(){

  //gROOT->SetStyle("Plain");  
  // gStyle->SetOptStat(0);
  // gStyle->SetPalette(1);
  // gStyle->SetPadTickX(1);
  //gStyle->SetPadTickY(1);

  gROOT->LoadMacro("../../include/atlasstyle-00-03-04/AtlasStyle.C");
  SetAtlasStyle();
  gROOT->LoadMacro("../../include/atlasstyle-00-03-04/AtlasUtils.C");
  gROOT->LoadMacro("../../include/atlasstyle-00-03-04/AtlasLabels.C");
  
  gROOT->SetBatch();
  
  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In printVerfication.C"<<endl;

  TFile* data_elec = (TFile*) TFile::Open("../plots/data.elec.pu.verification.plot.root");
  TFile* data_muon = (TFile*) TFile::Open("../plots/data.muon.pu.verification.plot.root");
  
  //////////////////////////////////////////////////
  // Electron Stream
  ////////////////////////////////////////////////// 


  TCanvas* tc_graph_elec_evtperlumi_rnum = new TCanvas("tc_graph_elec_evtperlumi_rnum","Evt/Lumi vs Run Number (Electron)",0,0,1280,800);
  tc_graph_elec_evtperlumi_rnum->cd();
  TGraphErrors* graph_elec_evtperlumi_rnum = (TGraphErrors*) data_elec->Get("graph_evtperlumi_rnum");
  graph_elec_evtperlumi_rnum->GetXaxis()->SetTitle("Run Number (Electron Stream)");
  graph_elec_evtperlumi_rnum->GetYaxis()->SetTitle("Events/pb");
  graph_elec_evtperlumi_rnum->GetYaxis()->SetRangeUser(0,35);
  graph_elec_evtperlumi_rnum->Draw("AP");

  tc_graph_elec_evtperlumi_rnum->Update();
  tc_graph_elec_evtperlumi_rnum->SaveAs("../canvases/latest/graph_elec_evtperlumi_rnum.pdf");

  //////////////////////////////////////////////////
  // Muon Stream
  ////////////////////////////////////////////////// 


  TCanvas* tc_graph_muon_evtperlumi_rnum = new TCanvas("tc_graph_muon_evtperlumi_rnum","Evt/Lumi vs Run Number (Muon)",0,0,1280,800);
  tc_graph_muon_evtperlumi_rnum->cd();
  TGraphErrors* graph_muon_evtperlumi_rnum = (TGraphErrors*) data_muon->Get("graph_evtperlumi_rnum");
  graph_muon_evtperlumi_rnum->GetXaxis()->SetTitle("Run Number (Muon Stream)");
  graph_muon_evtperlumi_rnum->GetYaxis()->SetTitle("Events/pb");
  graph_muon_evtperlumi_rnum->GetYaxis()->SetRangeUser(0,35);
  graph_muon_evtperlumi_rnum->Draw("AP");

  tc_graph_muon_evtperlumi_rnum->Update();
  tc_graph_muon_evtperlumi_rnum->SaveAs("../canvases/latest/graph_muon_evtperlumi_rnum.pdf");


  
  //////////////////////////////////////////////////
  // Electron Stream
  ////////////////////////////////////////////////// 

  //////////////////////////////////////////////////
  // graph_elec_nevts_lumi
  ////////////////////////////////////////////////// 
  
  TCanvas* tc_graph_elec_nevts_lumi = new TCanvas("tc_graph_elec_nevts_lumi","Evt/Lumi vs Run Number (elec)",0,0,1280,800);
  tc_graph_elec_nevts_lumi->cd();

  
  //periodFI
  TGraphErrors* graph_elec_nevts_lumi_periodFI = (TGraphErrors*) data_elec->Get("graph_nevts_lumi_periodFI");
  graph_elec_nevts_lumi_periodFI->SetTitle("F-I");
  graph_elec_nevts_lumi_periodFI->SetMarkerColor(kBlue);
  graph_elec_nevts_lumi_periodFI->SetMarkerStyle(3);
  
  //periodAE
  TGraphErrors* graph_elec_nevts_lumi_periodAE = (TGraphErrors*) data_elec->Get("graph_nevts_lumi_periodAE");
  graph_elec_nevts_lumi_periodAE->SetTitle("A-E");
  graph_elec_nevts_lumi_periodAE->SetMarkerColor(kGreen);
  graph_elec_nevts_lumi_periodAE->SetMarkerStyle(3);
  
  TGraphErrors* graph_elec_nevts_lumi_periodJM = (TGraphErrors*) data_elec->Get("graph_nevts_lumi_periodJM");
  graph_elec_nevts_lumi_periodJM->SetTitle("J-M");
  graph_elec_nevts_lumi_periodJM->SetMarkerColor(kRed);
  graph_elec_nevts_lumi_periodJM->SetMarkerStyle(3);
  
  TMultiGraph* mgraph_elec_nevts_lumi = new TMultiGraph();
  mgraph_elec_nevts_lumi->Add(graph_elec_nevts_lumi_periodAE);
  mgraph_elec_nevts_lumi->Add(graph_elec_nevts_lumi_periodFI);
  mgraph_elec_nevts_lumi->Add(graph_elec_nevts_lumi_periodJM);
  mgraph_elec_nevts_lumi->Draw("AP");

  mgraph_elec_nevts_lumi->GetXaxis()->SetTitle("Run Luminosity pb^{-1} (elec Stream)");
  mgraph_elec_nevts_lumi->GetYaxis()->SetTitle("Events");

  TLegend* tlgd_graph_elec_nevts_lumi =
    (TLegend*) tc_graph_elec_nevts_lumi->BuildLegend(0.2,0.67,0.28,0.88,"Period");
  tlgd_graph_elec_nevts_lumi->SetFillStyle(0);
  tlgd_graph_elec_nevts_lumi->SetTextSize(0.04);
  tlgd_graph_elec_nevts_lumi->Draw();

  tc_graph_elec_nevts_lumi->Update();
  tc_graph_elec_nevts_lumi->SaveAs("../canvases/latest/graph_elec_nevts_lumi.pdf");

  //////////////////////////////////////////////////
  // graph_muon_nevts_lumi
  ////////////////////////////////////////////////// 
  
  TCanvas* tc_graph_muon_nevts_lumi = new TCanvas("tc_graph_muon_nevts_lumi","Evt/Lumi vs Run Number (muon)",0,0,1280,800);
  tc_graph_muon_nevts_lumi->cd();

  
  //periodFI
  TGraphErrors* graph_muon_nevts_lumi_periodFI = (TGraphErrors*) data_muon->Get("graph_nevts_lumi_periodFI");
  graph_muon_nevts_lumi_periodFI->SetTitle("F-I");
  graph_muon_nevts_lumi_periodFI->SetMarkerColor(kBlue);
  graph_muon_nevts_lumi_periodFI->SetMarkerStyle(3);
  
  //periodAE
  TGraphErrors* graph_muon_nevts_lumi_periodAE = (TGraphErrors*) data_muon->Get("graph_nevts_lumi_periodAE");
  graph_muon_nevts_lumi_periodAE->SetTitle("A-E");
  graph_muon_nevts_lumi_periodAE->SetMarkerColor(kGreen);
  graph_muon_nevts_lumi_periodAE->SetMarkerStyle(3);
  
  TGraphErrors* graph_muon_nevts_lumi_periodJM = (TGraphErrors*) data_muon->Get("graph_nevts_lumi_periodJM");
  graph_muon_nevts_lumi_periodJM->SetTitle("J-M");
  graph_muon_nevts_lumi_periodJM->SetMarkerColor(kRed);
  graph_muon_nevts_lumi_periodJM->SetMarkerStyle(3);
  
  TMultiGraph* mgraph_muon_nevts_lumi = new TMultiGraph();
  mgraph_muon_nevts_lumi->Add(graph_muon_nevts_lumi_periodAE);
  mgraph_muon_nevts_lumi->Add(graph_muon_nevts_lumi_periodFI);
  mgraph_muon_nevts_lumi->Add(graph_muon_nevts_lumi_periodJM);
  mgraph_muon_nevts_lumi->Draw("AP");

  mgraph_muon_nevts_lumi->GetXaxis()->SetTitle("Run Luminosity pb^{-1} (muon stream)");
  mgraph_muon_nevts_lumi->GetYaxis()->SetTitle("Events");

  TLegend* tlgd_graph_muon_nevts_lumi =
    (TLegend*) tc_graph_muon_nevts_lumi->BuildLegend(0.2,0.67,0.28,0.88,"Period");
  tlgd_graph_muon_nevts_lumi->SetFillStyle(0);
  tlgd_graph_muon_nevts_lumi->SetTextSize(0.04);
  tlgd_graph_muon_nevts_lumi->Draw();

  tc_graph_muon_nevts_lumi->Update();
  tc_graph_muon_nevts_lumi->SaveAs("../canvases/latest/graph_muon_nevts_lumi.pdf");

  gROOT->ProcessLine(".q");
  return;
}
