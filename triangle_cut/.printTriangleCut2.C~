#include <TH2.h>
void printTriangleCut(){
  gROOT->LoadMacro("../include/atlasstyle-00-03-04/AtlasStyle.C");
  SetAtlasStyle();
  gROOT->LoadMacro("../include/atlasstyle-00-03-04/AtlasUtils.C");
  gROOT->LoadMacro("../include/atlasstyle-00-03-04/AtlasLabels.C");
  
  gROOT->SetBatch();
  
  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In printTriangleCut.C"<<endl;

  const int nProcs = 2;
  string procs[nProcs] = {"elec", "muon"};

  string file_loc = "/Users/elw/analy/lvjj/plots/gww_plots/merged/";

  //////////////////////////////////////////////////
  // Load Scaled Backgrounds
  //////////////////////////////////////////////////   


  string data_loc = file_loc+"data.lnuj.plot.root";
  TFile* data = TFile::Open(data_loc.c_str());
  TH2F* scat_elec_data = (TH2F*) data->Get("ps/scat_elec_lep_met_dphi_met");
  scat_elec_data->Rebin2D(3,3);
  scat_elec_data->SetDirectory(0);
  scat_elec_data->Scale(1./scat_elec_data->Integral());
  TH2F* scat_muon_data = (TH2F*) data->Get("ps/scat_muon_lep_met_dphi_met");
  scat_muon_data->Rebin2D(3,3);
  scat_muon_data->SetDirectory(0);
  scat_muon_data->Scale(1./scat_muon_data->Integral());
  data->Close();

  string qcd_loc = file_loc+"qcd.alpgen.plot.root";
  TFile* qcd = TFile::Open(qcd_loc.c_str());
  TH2F* scat_elec_qcd = (TH2F*) qcd->Get("ps/scat_elec_lep_met_dphi_met");
  scat_elec_qcd->Rebin2D(3,3);
  scat_elec_qcd->SetDirectory(0);
  scat_elec_qcd->Scale(1./scat_elec_qcd->Integral());
  TH2F* scat_muon_qcd = (TH2F*) qcd->Get("ps/scat_muon_lep_met_dphi_met");
  scat_muon_qcd->Rebin2D(3,3);
  scat_muon_qcd->SetDirectory(0);
  scat_muon_qcd->Scale(1./scat_muon_qcd->Integral());
  
  string wjets_loc = file_loc+"mc.alpgen.wjets.plot.root";
  TFile* wjets = TFile::Open(wjets_loc.c_str());
  TH2F* scat_elec_wjets = (TH2F*) wjets->Get("ps/scat_elec_lep_met_dphi_met");
  scat_elec_wjets->Rebin2D(3,3);
  scat_elec_wjets->SetDirectory(0);
  TH2F* scat_muon_wjets = (TH2F*) wjets->Get("ps/scat_muon_lep_met_dphi_met");
  scat_muon_wjets->Rebin2D(3,3);
  scat_muon_wjets->SetDirectory(0);

  string zjets_loc = file_loc+"mc.alpgen.zjets.plot.root";
  TFile* zjets = TFile::Open(zjets_loc.c_str());
  TH2F* scat_elec_zjets = (TH2F*) zjets->Get("ps/scat_elec_lep_met_dphi_met");
  scat_elec_zjets->Rebin2D(3,3);
  scat_elec_zjets->SetDirectory(0);
  TH2F* scat_muon_zjets = (TH2F*) zjets->Get("ps/scat_muon_lep_met_dphi_met");
  scat_muon_zjets->Rebin2D(3,3);
  scat_muon_zjets->SetDirectory(0);

  string top_loc = file_loc+"mc.mcatnlo.top.plot.root";
  TFile* top = TFile::Open(top_loc.c_str());
  TH2F* scat_elec_top = (TH2F*) top->Get("ps/scat_elec_lep_met_dphi_met");
  scat_elec_top->Rebin2D(3,3);
  scat_elec_top->SetDirectory(0);
  TH2F* scat_muon_top = (TH2F*) top->Get("ps/scat_muon_lep_met_dphi_met");
  scat_muon_top->Rebin2D(3,3);
  scat_muon_top->SetDirectory(0);

  string vv_loc = file_loc+"mc.herwig.vv.plot.root";
  TFile* vv = TFile::Open(vv_loc.c_str());
  TH2F* scat_elec_vv = (TH2F*) vv->Get("ps/scat_elec_lep_met_dphi_met");
  scat_elec_vv->Rebin2D(3,3);
  scat_elec_vv->SetDirectory(0);
  TH2F* scat_muon_vv = (TH2F*) vv->Get("ps/scat_muon_lep_met_dphi_met");
  scat_muon_vv->Rebin2D(3,3);
  scat_muon_vv->SetDirectory(0);

  TH2F* scat_elec_bkgd = (TH2F*) scat_elec_wjets->Clone();
  scat_elec_bkgd->Add((TH2F*) scat_elec_zjets->Clone());
  scat_elec_bkgd->Add((TH2F*) scat_elec_top->Clone());
  scat_elec_bkgd->Add((TH2F*) scat_elec_vv->Clone());
  scat_elec_bkgd->Scale(1./scat_elec_bkgd->Integral());

  TH2F* scat_muon_bkgd = (TH2F*) scat_muon_wjets->Clone();
  scat_muon_bkgd->Add((TH2F*) scat_muon_zjets->Clone());
  scat_muon_bkgd->Add((TH2F*) scat_muon_top->Clone());
  scat_muon_bkgd->Add((TH2F*) scat_muon_vv->Clone());
  scat_muon_bkgd->Scale(1./scat_muon_bkgd->Integral());

  string rsg_m750_loc = file_loc+"mc.rsg.m750.kmpl0_1.plot.root";
  TFile* rsg_m750 = TFile::Open(rsg_m750_loc.c_str());
  TH2F* scat_elec_rsg_m750 = (TH2F*) rsg_m750->Get("ps/scat_elec_lep_met_dphi_met");
  scat_elec_rsg_m750->Rebin2D(3,3);
  scat_elec_rsg_m750->SetDirectory(0);
  scat_elec_rsg_m750->Scale(1./scat_elec_rsg_m750->Integral());
  TH2F* scat_muon_rsg_m750 = (TH2F*) rsg_m750->Get("ps/scat_muon_lep_met_dphi_met");
  scat_muon_rsg_m750->Rebin2D(3,3);
  scat_muon_rsg_m750->SetDirectory(0);
  scat_muon_rsg_m750->Scale(1./scat_muon_rsg_m750->Integral());

  TCanvas* tc_scat_muon_lep_met_dphi_met = new TCanvas("tc_scat_muon_lep_met_dphi_met","tc_scat_muon_lep_met_dphi_met",0,0,1920,1200);
  tc_scat_muon_lep_met_dphi_met->cd();

  TPad* pp_scat_muon_lep_met_dphi_met =
    new TPad("pp_scat_muon_lep_met_dphi_met","scat_muon_lep_met_dphi_met",0.01,0.01,0.8,0.99);
  //pp_scat_muon_lep_met_dphi_met->SetBottomMargin(0);
  pp_scat_muon_lep_met_dphi_met->Draw();
  pp_scat_muon_lep_met_dphi_met->cd();
  pp_scat_muon_lep_met_dphi_met->SetGrid();
  pp_scat_muon_lep_met_dphi_met->Update();  

  //scat_muon_data->SetMarkerColor(kRed);
  scat_muon_data->GetXaxis()->SetTitle("MET");
  scat_muon_data->GetYaxis()->SetTitle("dPhi(lep,MET)");
  scat_muon_data->Draw("BOX");

  scat_muon_qcd->SetLineColor(kBlue);
  scat_muon_qcd->Draw("BOX same");

  scat_muon_bkgd->SetLineColor(kGreen);
  scat_muon_bkgd->Draw("BOX same");

  scat_muon_rsg_m750->SetLineColor(kMagenta);
  scat_muon_rsg_m750->Draw("BOX same");

  TLine* tline_scat_muon_lep_met_dphi_met = new TLine(0,0.8333,75,0);
  tline_scat_muon_lep_met_dphi_met->SetLineColor(kRed);
  tline_scat_muon_lep_met_dphi_met->Draw();


  tc_scat_muon_lep_met_dphi_met->cd();
  TPad* lgnd_pad_scat_muon_lep_met_dphi_met =
    new TPad("lgnd_pad_scat_muon_lep_met_dphi_met","lgnd_pad_muon_lep_met_dphi_met",0.8,0.15,0.9,0.95);
  //lgnd_pad_scat_muon_lep_met_dphi_met->SetBottomMargin(0);
  lgnd_pad_scat_muon_lep_met_dphi_met->Draw();
  lgnd_pad_scat_muon_lep_met_dphi_met->cd();
  TLegend* lgnd_scat_muon_lep_met_dphi_met = new TLegend(0.01,0.5,0.99,0.9);
  lgnd_scat_muon_lep_met_dphi_met->SetFillColor(0);
  lgnd_scat_muon_lep_met_dphi_met->SetBorderSize(0);
  lgnd_scat_muon_lep_met_dphi_met->SetTextSize(0.3);
  lgnd_scat_muon_lep_met_dphi_met->AddEntry(scat_muon_data,"data","F");
  lgnd_scat_muon_lep_met_dphi_met->AddEntry(scat_muon_qcd,"qcd","F");
  lgnd_scat_muon_lep_met_dphi_met->AddEntry(scat_muon_bkgd,"bkgds","F");
  lgnd_scat_muon_lep_met_dphi_met->AddEntry(scat_muon_rsg_m750,"sig","F");  
  lgnd_scat_muon_lep_met_dphi_met->Draw();
  lgnd_pad_scat_muon_lep_met_dphi_met->Update();
  
  tc_scat_muon_lep_met_dphi_met->Update();

  string cur_saveas = "./canvases/latest/scat_muon_lep_met_dphi_met.pdf";
  tc_scat_muon_lep_met_dphi_met->SaveAs(cur_saveas.c_str());

  TCanvas* tc_scat_elec_lep_met_dphi_met = new TCanvas("tc_scat_elec_lep_met_dphi_met","tc_scat_elec_lep_met_dphi_met",0,0,1920,1200);
  tc_scat_elec_lep_met_dphi_met->cd();

  TPad* pp_scat_elec_lep_met_dphi_met =
    new TPad("pp_scat_elec_lep_met_dphi_met","scat_elec_lep_met_dphi_met",0.01,0.01,0.8,0.99);
  pp_scat_elec_lep_met_dphi_met->Draw();
  pp_scat_elec_lep_met_dphi_met->cd();
  pp_scat_elec_lep_met_dphi_met->SetGrid();
  pp_scat_elec_lep_met_dphi_met->Update();  


  //scat_elec_data->SetMarkerColor(kRed);
  //scat_elec_data->SetLineColor(kRed);
  scat_elec_data->GetXaxis()->SetTitle("MET");
  scat_elec_data->GetYaxis()->SetTitle("dPhi(lep,MET)");
  scat_elec_data->Draw("BOX");

  scat_elec_qcd->SetLineColor(kBlue);
  scat_elec_qcd->Draw("BOX same");

  scat_elec_bkgd->SetLineColor(kGreen);
  scat_elec_bkgd->Draw("BOX same");

  scat_elec_rsg_m750->SetLineColor(kMagenta);
  scat_elec_rsg_m750->Draw("BOX same");

  TLine* tline_scat_elec_lep_met_dphi_met = new TLine(0,0.8333,75,0);
  tline_scat_elec_lep_met_dphi_met->SetLineColor(kRed);
  tline_scat_elec_lep_met_dphi_met->Draw();

  
  tc_scat_elec_lep_met_dphi_met->cd();
  TPad* lgnd_pad_scat_elec_lep_met_dphi_met =
    new TPad("lgnd_pad_scat_elec_lep_met_dphi_met","lgnd_pad_elec_lep_met_dphi_met",0.8,0.15,0.9,0.95);
  //lgnd_pad_scat_elec_lep_met_dphi_met->SetBottomMargin(0);
  lgnd_pad_scat_elec_lep_met_dphi_met->Draw();
  lgnd_pad_scat_elec_lep_met_dphi_met->cd();
  TLegend* lgnd_scat_elec_lep_met_dphi_met = new TLegend(0.01,0.5,0.99,0.9);
  lgnd_scat_elec_lep_met_dphi_met->SetFillColor(0);
  lgnd_scat_elec_lep_met_dphi_met->SetBorderSize(0);
  lgnd_scat_elec_lep_met_dphi_met->SetTextSize(0.3);
  lgnd_scat_elec_lep_met_dphi_met->AddEntry(scat_elec_data,"data","F");
  lgnd_scat_elec_lep_met_dphi_met->AddEntry(scat_elec_qcd,"qcd","F");
  lgnd_scat_elec_lep_met_dphi_met->AddEntry(scat_elec_bkgd,"bkgds","F");
  lgnd_scat_elec_lep_met_dphi_met->AddEntry(scat_elec_rsg_m750,"sig","F");  
  lgnd_scat_elec_lep_met_dphi_met->Draw();
  lgnd_pad_scat_elec_lep_met_dphi_met->Update();
  
  tc_scat_elec_lep_met_dphi_met->Update();

  string cur_saveas = "./canvases/latest/scat_elec_lep_met_dphi_met.pdf";
  tc_scat_elec_lep_met_dphi_met->SaveAs(cur_saveas.c_str());

  
  gROOT->ProcessLine(".q");
  return;
}
