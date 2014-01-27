void printQCDSanityCheck(){
  gROOT->LoadMacro("../../include/atlasstyle-00-03-04/AtlasStyle.C");
  SetAtlasStyle();
  gROOT->LoadMacro("../../include/atlasstyle-00-03-04/AtlasUtils.C");
  gROOT->LoadMacro("../../include/atlasstyle-00-03-04/AtlasLabels.C");
  
  gROOT->SetBatch();

  TFile* qcd_noscale = TFile::Open("./plots/qcd.noscale.root");
  TFile* qcd_scale = TFile::Open("./plots/qcd.scale.root");

  TH1F* qcd_noscale_muon_mt = (TH1F*) qcd_noscale->Get("ps/h_muon_lep_met_mt");
  TH1F* qcd_scale_muon_mt = (TH1F*) qcd_scale->Get("ps/h_muon_lep_met_mt");

  TH1F* qcd_noscale_elec_mt = (TH1F*) qcd_noscale->Get("ps/h_elec_lep_met_mt");
  TH1F* qcd_scale_elec_mt = (TH1F*) qcd_scale->Get("ps/h_elec_lep_met_mt");

  TCanvas* tc_muon_lep_met_mt = new TCanvas("tc_muon_lep_met_mt","tc_muon_lep_met_mt",0,0,1920,1200);
  tc_muon_lep_met_mt->cd();

  //qcd_noscale_muon_mt->Scale(1./qcd_noscale_muon_mt->Integral());
  qcd_noscale_muon_mt->GetXaxis()->SetTitle("mT(mu,MET) [GeV]");
  qcd_noscale_muon_mt->Draw("hist");

  //qcd_scale_muon_mt->Scale(1./qcd_scale_muon_mt->Integral());
  qcd_scale_muon_mt->SetLineColor(kRed);
  qcd_scale_muon_mt->Draw("hist sames");

  TLegend* lgnd_muon_lep_met_mt = new TLegend(0.7,0.7,0.9,0.9);
  lgnd_muon_lep_met_mt->SetFillColor(0);
  lgnd_muon_lep_met_mt->SetBorderSize(0);
  lgnd_muon_lep_met_mt->SetTextSize(0.03);
  lgnd_muon_lep_met_mt->AddEntry(qcd_noscale_muon_mt,"No QCD scaling","F");
  lgnd_muon_lep_met_mt->AddEntry(qcd_scale_muon_mt,"After QCD scaling","F");  
  lgnd_muon_lep_met_mt->Draw();

  tc_muon_lep_met_mt->SetLogy();
  tc_muon_lep_met_mt->Update();
  tc_muon_lep_met_mt->SaveAs("./canvases/latest/qcd_muon_lep_met_mt.pdf");
  

  TCanvas* tc_elec_lep_met_mt = new TCanvas("tc_elec_lep_met_mt","tc_elec_lep_met_mt",0,0,1920,1200);
  tc_elec_lep_met_mt->cd();

  //qcd_noscale_elec_mt->Scale(1./qcd_noscale_elec_mt->Integral());
  qcd_noscale_elec_mt->GetXaxis()->SetTitle("mT(e,MET) [GeV]");
  qcd_noscale_elec_mt->Draw("hist");

  //qcd_scale_elec_mt->Scale(1./qcd_scale_elec_mt->Integral());
  qcd_scale_elec_mt->SetLineColor(kRed);
  qcd_scale_elec_mt->Draw("hist sames");

  TLegend* lgnd_elec_lep_met_mt = new TLegend(0.7,0.7,0.9,0.9);
  lgnd_elec_lep_met_mt->SetFillColor(0);
  lgnd_elec_lep_met_mt->SetBorderSize(0);
  lgnd_elec_lep_met_mt->SetTextSize(0.03);
  lgnd_elec_lep_met_mt->AddEntry(qcd_noscale_elec_mt,"No QCD scaling","F");
  lgnd_elec_lep_met_mt->AddEntry(qcd_scale_elec_mt,"After QCD scaling","F");  
  lgnd_elec_lep_met_mt->Draw();

  tc_elec_lep_met_mt->SetLogy();
  tc_elec_lep_met_mt->Update();
  tc_elec_lep_met_mt->SaveAs("./canvases/latest/qcd_elec_lep_met_mt.pdf");
  
  
  
  return;
}
