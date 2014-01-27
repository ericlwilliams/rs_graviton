float ratio_split=0.35;
void ptElecPrint(){

  gROOT->LoadMacro("../../include/atlasstyle-00-03-04/AtlasStyle.C");
  SetAtlasStyle();
  gROOT->LoadMacro("../../include/atlasstyle-00-03-04/AtlasUtils.C");
  gROOT->LoadMacro("../../include/atlasstyle-00-03-04/AtlasLabels.C");
  
  gROOT->SetBatch();
  
  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In ptElecPrint.C"<<endl;


  TFile* data_sel_plots =
    (TFile*) TFile::Open("../../plots/selection_plots/merged/sel.data.selection.root");
  TFile* mc_bkgd_sel_plots = 
      (TFile*) TFile::Open("../../plots/selection_plots/merged/sel.bkgd.selection.root");

  TDirectory* dir_data_elec = (TDirectory*) data_sel_plots->GetDirectory("elec");
  TDirectory* dir_bkgd_elec = (TDirectory*) mc_bkgd_sel_plots->GetDirectory("elec");

  TH1F* h_data_sel_lep_pt = (TH1F*) dir_data_elec->Get("h_elec_rel_ptiso30_lep_pt");
  TH1F* h_bkgd_sel_lep_pt = (TH1F*) dir_bkgd_elec->Get("h_elec_rel_ptiso30_lep_pt");
  h_bkgd_sel_lep_pt->Scale(h_data_sel_lep_pt->Integral()/h_bkgd_sel_lep_pt->Integral());

  TH1F* h_sel_lep_pt_ratio = (TH1F*) h_data_sel_lep_pt->Clone();
  h_sel_lep_pt_ratio->Divide(h_sel_lep_pt_ratio,h_bkgd_sel_lep_pt,1,1,"B");

    //sel
  TCanvas* tc_elec_sel_lep_pt = new TCanvas("tc_elec_sel_lep_pt","tc_elec_sel_lep_pt",0,0,1920,1200);
  tc_elec_sel_lep_pt->cd();
  
  rp_elec_sel_lep_pt =
    new TPad("rp_elec_sel_lep_pt","rp_elec_sel_lep_pt",0.01,0.01,0.99,ratio_split);
  rp_elec_sel_lep_pt->SetTopMargin(0.05);
  rp_elec_sel_lep_pt->SetBottomMargin(0.31);
  rp_elec_sel_lep_pt->SetGrid();
  rp_elec_sel_lep_pt->Draw();

  pp_elec_sel_lep_pt =
    new TPad("pp_elec_sel_lep_pt","pp_elec_sel_lep_pt",0.01,ratio_split,0.99,0.99);
  pp_elec_sel_lep_pt->SetBottomMargin(0);
  pp_elec_sel_lep_pt->Draw();
  pp_elec_sel_lep_pt->cd();
  pp_elec_sel_lep_pt->SetGrid();
  pp_elec_sel_lep_pt->SetLogy();
  pp_elec_sel_lep_pt->Update();  
    
  //h_bkgd_sel_lep_pt->GetYaxis()->SetRangeUser(0,1.2);
  h_bkgd_sel_lep_pt->GetYaxis()->SetTitle("Efficiency of corr_etcone30 electron cut");
  h_bkgd_sel_lep_pt->GetYaxis()->SetTitleOffset(0.75);
  h_bkgd_sel_lep_pt->GetXaxis()->SetLabelSize(0);
  h_bkgd_sel_lep_pt->SetLineColor(kBlue);
  h_bkgd_sel_lep_pt->SetMarkerStyle(3);
  h_bkgd_sel_lep_pt->SetMarkerSize(2);
  h_bkgd_sel_lep_pt->Draw("hist");

  h_data_sel_lep_pt->SetLineColor(kRed);
  h_data_sel_lep_pt->SetMarkerStyle(3);
  h_data_sel_lep_pt->SetMarkerSize(2);
  h_data_sel_lep_pt->Draw("hist same");

  TLegend* lgnd_elec_sel_lep_pt = new TLegend(0.72,0.83,0.9,0.95);
  lgnd_elec_sel_lep_pt->SetFillColor(0);
  lgnd_elec_sel_lep_pt->SetTextSize(0.03);
  lgnd_elec_sel_lep_pt->AddEntry(h_data_sel_lep_pt,"Data","L");
  lgnd_elec_sel_lep_pt->AddEntry(h_bkgd_sel_lep_pt,"Backgrounds","L");
  lgnd_elec_sel_lep_pt->Draw();

  rp_elec_sel_lep_pt->cd();  
  h_sel_lep_pt_ratio->GetXaxis()->SetTitle("Electron pt [GeV]");
  h_sel_lep_pt_ratio->GetXaxis()->SetTitleSize(0.16);
  h_sel_lep_pt_ratio->GetXaxis()->SetTitleOffset(0.7);
  h_sel_lep_pt_ratio->GetYaxis()->SetNdivisions(4,4,4);
  h_sel_lep_pt_ratio->GetYaxis()->SetTitle("Data/Bkgd");
  h_sel_lep_pt_ratio->GetYaxis()->SetTitleSize(0.07);
  h_sel_lep_pt_ratio->GetYaxis()->SetTitleOffset(0.36);
  h_sel_lep_pt_ratio->GetYaxis()->SetRangeUser(0.5,1.5);
  h_sel_lep_pt_ratio->SetMarkerStyle(20);
  h_sel_lep_pt_ratio->SetMarkerSize(2);
  h_sel_lep_pt_ratio->SetLineWidth(1);
  h_sel_lep_pt_ratio->Draw("HIST PE");


  tc_elec_sel_lep_pt->Update();
  tc_elec_sel_lep_pt->RedrawAxis();
  tc_elec_sel_lep_pt->SaveAs("../canvases/latest/h_elec_sel_lep_pt.png");

  gROOT->ProcessLine(".q");

  return;
}
