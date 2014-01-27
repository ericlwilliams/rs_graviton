#include <TCanvas.h>
#include <TPad.h>
#include <TProfile.h>
#include <TFile.h>
#include <TDirectory.h>
#include "../../include/atlasstyle-00-03-04/AtlasStyle.C";

void printJetUncertainty(){

  SetAtlasStyle();
  gROOT->SetBatch();
  
  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In printJetUncertainty.C"<<endl;

  string save_loc = "../canvases/latest/";
  string cur_saveas="";

  TFile* t1_file = (TFile*) TFile::Open("../plots/mc.mcatnlo.t1.uncertainty.plot.root");
  //jes_up
  TProfile* t1_prof_jes_up_v_pt_eta0 = t1_file->Get("prof_jes_up_v_pt_eta0");
  TProfile* t1_prof_jes_up_v_pt_eta1 = t1_file->Get("prof_jes_up_v_pt_eta1");
  TProfile* t1_prof_jes_up_v_pt_eta2 = t1_file->Get("prof_jes_up_v_pt_eta2");
  TProfile* t1_prof_jes_up_v_pt_eta3 = t1_file->Get("prof_jes_up_v_pt_eta3");
  //jes_down
  TProfile* t1_prof_jes_down_v_pt_eta0 = t1_file->Get("prof_jes_down_v_pt_eta0");
  TProfile* t1_prof_jes_down_v_pt_eta1 = t1_file->Get("prof_jes_down_v_pt_eta1");
  TProfile* t1_prof_jes_down_v_pt_eta2 = t1_file->Get("prof_jes_down_v_pt_eta2");
  TProfile* t1_prof_jes_down_v_pt_eta3 = t1_file->Get("prof_jes_down_v_pt_eta3");

  //jer_mc
  TProfile* t1_prof_jer_mc_v_pt_eta0 = t1_file->Get("prof_jer_mc_v_pt_eta0");
  TProfile* t1_prof_jer_mc_v_pt_eta1 = t1_file->Get("prof_jer_mc_v_pt_eta1");
  TProfile* t1_prof_jer_mc_v_pt_eta2 = t1_file->Get("prof_jer_mc_v_pt_eta2");
  TProfile* t1_prof_jer_mc_v_pt_eta3 = t1_file->Get("prof_jer_mc_v_pt_eta3");
  //jer_mc_uncert
  TProfile* t1_prof_jer_mc_uncert_v_pt_eta0 = t1_file->Get("prof_jer_mc_uncert_v_pt_eta0");
  TProfile* t1_prof_jer_mc_uncert_v_pt_eta1 = t1_file->Get("prof_jer_mc_uncert_v_pt_eta1");
  TProfile* t1_prof_jer_mc_uncert_v_pt_eta2 = t1_file->Get("prof_jer_mc_uncert_v_pt_eta2");
  TProfile* t1_prof_jer_mc_uncert_v_pt_eta3 = t1_file->Get("prof_jer_mc_uncert_v_pt_eta3");


  //jes_up
  TCanvas* tc_t1_jes_up_v_pt = new TCanvas("tc_t1_jes_up_v_pt","tc_t1_jes_up_v_pt",0,0,1920,1200);
  tc_t1_jes_up_v_pt->cd();

  t1_prof_jes_up_v_pt_eta0->GetYaxis()->SetRangeUser(0.012,0.055);
  t1_prof_jes_up_v_pt_eta0->GetXaxis()->SetRangeUser(25,1000);
  t1_prof_jes_up_v_pt_eta0->GetXaxis()->SetTitle("jet p_{T} [GeV]");
  t1_prof_jes_up_v_pt_eta0->GetYaxis()->SetTitle("MultiJES Positive Uncertainty");
  t1_prof_jes_up_v_pt_eta0->SetLineColor(kBlack);
  t1_prof_jes_up_v_pt_eta0->Draw("hist");

  t1_prof_jes_up_v_pt_eta1->SetLineColor(kBlue);
  t1_prof_jes_up_v_pt_eta1->Draw("hist same");

  t1_prof_jes_up_v_pt_eta2->SetLineColor(kGreen);
  t1_prof_jes_up_v_pt_eta2->Draw("hist same");

  t1_prof_jes_up_v_pt_eta3->SetLineColor(kRed);
  t1_prof_jes_up_v_pt_eta3->Draw("hist same");

  
  //tc_t1_jes_up_v_pt->SetLogx();
  tc_t1_jes_up_v_pt->Update();

  TLegend* lgnd_t1_jes_up_v_pt = new TLegend(0.80,0.70,0.9,0.90);
  lgnd_t1_jes_up_v_pt->SetFillColor(0);
  lgnd_t1_jes_up_v_pt->SetTextSize(0.05);
  lgnd_t1_jes_up_v_pt->SetBorderSize(0);
  lgnd_t1_jes_up_v_pt->AddEntry(t1_prof_jes_up_v_pt_eta0,"#eta < 0.8","L");
  lgnd_t1_jes_up_v_pt->AddEntry(t1_prof_jes_up_v_pt_eta1,"#eta < 1.2","L");
  lgnd_t1_jes_up_v_pt->AddEntry(t1_prof_jes_up_v_pt_eta2,"#eta < 2.1","L");
  lgnd_t1_jes_up_v_pt->AddEntry(t1_prof_jes_up_v_pt_eta3,"#eta > 2.1","L");
  lgnd_t1_jes_up_v_pt->Draw();
  

  cur_saveas = save_loc+"prof_jes_up_v_pt.pdf";
  tc_t1_jes_up_v_pt->SaveAs(cur_saveas.c_str());


  //jes_down
  TCanvas* tc_t1_jes_down_v_pt = new TCanvas("tc_t1_jes_down_v_pt","tc_t1_jes_down_v_pt",0,0,1920,1200);
  tc_t1_jes_down_v_pt->cd();

  t1_prof_jes_down_v_pt_eta0->GetYaxis()->SetRangeUser(0.012,0.055);
  t1_prof_jes_down_v_pt_eta0->GetXaxis()->SetRangeUser(25,1000);
  t1_prof_jes_down_v_pt_eta0->GetXaxis()->SetTitle("jet p_{T} [GeV]");
  t1_prof_jes_down_v_pt_eta0->GetYaxis()->SetTitle("MultiJES Negative Uncertainty");
  t1_prof_jes_down_v_pt_eta0->SetLineColor(kBlack);
  t1_prof_jes_down_v_pt_eta0->SetMarkerColor(kBlack);
  t1_prof_jes_down_v_pt_eta0->Draw("hist");

  t1_prof_jes_down_v_pt_eta1->SetLineColor(kBlue);
  t1_prof_jes_down_v_pt_eta1->SetMarkerColor(kBlue);
  t1_prof_jes_down_v_pt_eta1->Draw("hist same");

  t1_prof_jes_down_v_pt_eta2->SetLineColor(kGreen);
  t1_prof_jes_down_v_pt_eta2->SetMarkerColor(kGreen);
  t1_prof_jes_down_v_pt_eta2->Draw("hist same");

  t1_prof_jes_down_v_pt_eta3->SetLineColor(kRed);
  t1_prof_jes_down_v_pt_eta3->SetMarkerColor(kRed);
  t1_prof_jes_down_v_pt_eta3->Draw("hist same");

  
  //tc_t1_jes_down_v_pt->SetLogx();
  tc_t1_jes_down_v_pt->Update();

  TLegend* lgnd_t1_jes_down_v_pt = new TLegend(0.80,0.70,0.9,0.90);
  lgnd_t1_jes_down_v_pt->SetFillColor(0);
  lgnd_t1_jes_down_v_pt->SetTextSize(0.05);
  lgnd_t1_jes_down_v_pt->SetBorderSize(0);
  lgnd_t1_jes_down_v_pt->AddEntry(t1_prof_jes_down_v_pt_eta0,"#eta < 0.8","L");
  lgnd_t1_jes_down_v_pt->AddEntry(t1_prof_jes_down_v_pt_eta1,"#eta < 1.2","L");
  lgnd_t1_jes_down_v_pt->AddEntry(t1_prof_jes_down_v_pt_eta2,"#eta < 2.1","L");
  lgnd_t1_jes_down_v_pt->AddEntry(t1_prof_jes_down_v_pt_eta3,"#eta > 2.1","L");
  lgnd_t1_jes_down_v_pt->Draw();
  

  cur_saveas = save_loc+"prof_jes_down_v_pt.pdf";
  tc_t1_jes_down_v_pt->SaveAs(cur_saveas.c_str());


  //jer_mc
  TCanvas* tc_t1_jer_mc_v_pt = new TCanvas("tc_t1_jer_mc_v_pt","tc_t1_jer_mc_v_pt",0,0,1920,1200);
  tc_t1_jer_mc_v_pt->cd();

  //t1_prof_jer_mc_v_pt_eta0->GetYaxis()->SetRangeUser(0.012,0.1);
  t1_prof_jer_mc_v_pt_eta0->GetYaxis()->SetRangeUser(0.0,0.16);
  t1_prof_jer_mc_v_pt_eta0->GetXaxis()->SetRangeUser(25,1000);
  t1_prof_jer_mc_v_pt_eta0->GetXaxis()->SetTitle("jet p_{T} [GeV]");
  t1_prof_jer_mc_v_pt_eta0->GetYaxis()->SetTitle("JER");
  t1_prof_jer_mc_v_pt_eta0->SetLineColor(kBlack);
  t1_prof_jer_mc_v_pt_eta0->Draw("hist");

  t1_prof_jer_mc_v_pt_eta1->SetLineColor(kBlue);
  t1_prof_jer_mc_v_pt_eta1->Draw("hist same");

  t1_prof_jer_mc_v_pt_eta2->SetLineColor(kGreen);
  t1_prof_jer_mc_v_pt_eta2->Draw("hist same");

  t1_prof_jer_mc_v_pt_eta3->SetLineColor(kRed);
  t1_prof_jer_mc_v_pt_eta3->Draw("hist same");

  
  //tc_t1_jer_mc_v_pt->SetLogx();
  tc_t1_jer_mc_v_pt->Update();

  TLegend* lgnd_t1_jer_mc_v_pt = new TLegend(0.80,0.70,0.9,0.90);
  lgnd_t1_jer_mc_v_pt->SetFillColor(0);
  lgnd_t1_jer_mc_v_pt->SetTextSize(0.05);
  lgnd_t1_jer_mc_v_pt->SetBorderSize(0);
  lgnd_t1_jer_mc_v_pt->AddEntry(t1_prof_jer_mc_v_pt_eta0,"#eta < 0.8","L");
  lgnd_t1_jer_mc_v_pt->AddEntry(t1_prof_jer_mc_v_pt_eta1,"#eta < 1.2","L");
  lgnd_t1_jer_mc_v_pt->AddEntry(t1_prof_jer_mc_v_pt_eta2,"#eta < 2.1","L");
  lgnd_t1_jer_mc_v_pt->AddEntry(t1_prof_jer_mc_v_pt_eta3,"#eta > 2.1","L");
  lgnd_t1_jer_mc_v_pt->Draw();
  

  cur_saveas = save_loc+"prof_jer_mc_v_pt.pdf";
  tc_t1_jer_mc_v_pt->SaveAs(cur_saveas.c_str());


  //jer_mc_uncert
  TCanvas* tc_t1_jer_mc_uncert_v_pt = new TCanvas("tc_t1_jer_mc_uncert_v_pt","tc_t1_jer_mc_uncert_v_pt",0,0,1920,1200);
  tc_t1_jer_mc_uncert_v_pt->cd();

  t1_prof_jer_mc_uncert_v_pt_eta0->GetYaxis()->SetRangeUser(0,0.0335);
  t1_prof_jer_mc_uncert_v_pt_eta0->GetXaxis()->SetRangeUser(25,1000);
  t1_prof_jer_mc_uncert_v_pt_eta0->GetXaxis()->SetTitle("jet p_{T} [GeV]");
  t1_prof_jer_mc_uncert_v_pt_eta0->GetYaxis()->SetTitle("JER Uncertainty");
  t1_prof_jer_mc_uncert_v_pt_eta0->SetLineColor(kBlack);
  t1_prof_jer_mc_uncert_v_pt_eta0->Draw("hist");

  t1_prof_jer_mc_uncert_v_pt_eta1->SetLineColor(kBlue);
  t1_prof_jer_mc_uncert_v_pt_eta1->Draw("hist same");

  t1_prof_jer_mc_uncert_v_pt_eta2->SetLineColor(kGreen);
  t1_prof_jer_mc_uncert_v_pt_eta2->Draw("hist same");

  t1_prof_jer_mc_uncert_v_pt_eta3->SetLineColor(kRed);
  t1_prof_jer_mc_uncert_v_pt_eta3->Draw("hist same");

  
  //tc_t1_jer_mc_uncert_v_pt->SetLogx();
  tc_t1_jer_mc_uncert_v_pt->Update();

  TLegend* lgnd_t1_jer_mc_uncert_v_pt = new TLegend(0.80,0.70,0.9,0.90);
  lgnd_t1_jer_mc_uncert_v_pt->SetFillColor(0);
  lgnd_t1_jer_mc_uncert_v_pt->SetTextSize(0.05);
  lgnd_t1_jer_mc_uncert_v_pt->SetBorderSize(0);
  lgnd_t1_jer_mc_uncert_v_pt->AddEntry(t1_prof_jer_mc_uncert_v_pt_eta0,"#eta < 0.8","L");
  lgnd_t1_jer_mc_uncert_v_pt->AddEntry(t1_prof_jer_mc_uncert_v_pt_eta1,"#eta < 1.2","L");
  lgnd_t1_jer_mc_uncert_v_pt->AddEntry(t1_prof_jer_mc_uncert_v_pt_eta2,"#eta < 2.1","L");
  lgnd_t1_jer_mc_uncert_v_pt->AddEntry(t1_prof_jer_mc_uncert_v_pt_eta3,"#eta > 2.1","L");
  lgnd_t1_jer_mc_uncert_v_pt->Draw();
  

  cur_saveas = save_loc+"prof_jer_mc_uncert_v_pt.pdf";
  tc_t1_jer_mc_uncert_v_pt->SaveAs(cur_saveas.c_str());

}
