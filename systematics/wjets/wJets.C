#include "/Users/elw/analy/lnuj/include/lnuj_bkgd_list.h"
#include "/Users/elw/analy/lnuj/include/wwFileInfo.h"
#include <string>
#include <TLine.h>

string proc_type = "sys_wjets";
string file_tail = ".sys.wjets.plot.root";

void wJets(){

  gROOT->SetStyle("Plain");  
  gStyle->SetOptStat(0);
  gStyle->SetPalette(1);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  //gStyle->SetFillStyle(3144);
  
  //gROOT->SetBatch();
  
  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In wJets.C"<<endl;

  const int nProcs=2;
  string procs[nProcs] = {"elec","muon"};

  const int nCtrls=3;
  string ctrls[nCtrls] = {"all","ewk","ttbar"};

  string wjets_alpgen = "/Users/elw/analy/lnuj/plots/sys_wjets_plots/merged/mc.alpgen.wjets.sys.wjets.plot.root";
  TFile* wjets_alpgen_file = TFile::Open(wjets_alpgen.c_str());
  string wjets_sherpa = "/Users/elw/analy/lnuj/plots/sys_wjets_plots/merged/mc.sherpa.wjets.sys.wjets.plot.root";  
  TFile* wjets_sherpa_file = TFile::Open(wjets_sherpa.c_str());
  // Backgrounds
  string top_mcatnlo = "/Users/elw/analy/lnuj/plots/sys_wjets_plots/merged/mc.mcatnlo.top.sys.wjets.plot.root";
  TFile* top_mcatnlo_file = TFile::Open(top_mcatnlo.c_str());

  string zjets_alpgen = "/Users/elw/analy/lnuj/plots/sys_wjets_plots/merged/mc.alpgen.zjets.sys.wjets.plot.root";
  TFile* zjets_alpgen_file = TFile::Open(zjets_alpgen.c_str());
  
  string vv_herwig = "/Users/elw/analy/lnuj/plots/sys_wjets_plots/merged/mc.herwig.vv.sys.wjets.plot.root";
  TFile* vv_herwig_file = TFile::Open(vv_herwig.c_str());
  
  string qcd = "/Users/elw/analy/lnuj/plots/sys_wjets_plots/merged/qcd.sys.wjets.plot.root";  
  TFile* qcd_file = TFile::Open(qcd.c_str());

  
  string data = "/Users/elw/analy/lnuj/plots/sys_wjets_plots/merged/data.lnuj.plot.root";  
  TFile* data_file = TFile::Open(data.c_str());

  
  if(!wjets_sherpa_file || !wjets_alpgen_file ||
     !top_mcatnlo_file || !data_file ||
     !zjets_alpgen_file || !vv_herwig_file || !qcd_file) {
    cout<<"alpgen or sherpa files not found"<<endl;
    exit(-142);
  }

  // // //NEXT
  
  // //////////////////////////////////////////////////
  // // tc01
  // // lead_jet_pt: sherpa/alpgen+wjrw
  // //////////////////////////////////////////////////
  
  // string tc01_title = "Lead Jet Pt (elec)";
  // string tc01_name = "tc01";
  // TCanvas* tc01 = new TCanvas(tc01_name.c_str(),tc01_title.c_str(),0,0,1920,1200);
  // tc01->cd();

  // TPad* tc01_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc01_pad01->SetTopMargin(0.05);
  // tc01_pad01->SetBottomMargin(0.31);
  // tc01_pad01->Draw();

  // TPad* tc01_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc01_pad02->SetBottomMargin(0.0005);
  // tc01_pad02->SetLogy();
  // tc01_pad02->Draw();
  // tc01_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_elec_lead_jet_pt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_purw_nom_lead_jet_pt");
  // TH1F* h_alpgen_iqopt3_elec_lead_jet_pt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_iqopt3_lead_jet_pt");
  // TH1F* h_alpgen_ptjmin10_elec_lead_jet_pt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_ptjmin10_lead_jet_pt");
  // TH1F* h_sherpa_nom_elec_lead_jet_pt = (TH1F*) wjets_sherpa_file->Get("all/h_elec_purw_nom_lead_jet_pt");
  
  // h_alpgen_nom_elec_lead_jet_pt->SetMarkerStyle(20);
  // h_alpgen_nom_elec_lead_jet_pt->SetMarkerSize(1.2);
  // h_alpgen_nom_elec_lead_jet_pt->SetTitle("");
  // h_alpgen_nom_elec_lead_jet_pt->Draw("PE");

  // h_alpgen_iqopt3_elec_lead_jet_pt->SetMarkerStyle(22);
  // h_alpgen_iqopt3_elec_lead_jet_pt->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_elec_lead_jet_pt->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_elec_lead_jet_pt->Draw("PE sames");


  // h_alpgen_ptjmin10_elec_lead_jet_pt->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_elec_lead_jet_pt->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_elec_lead_jet_pt->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_elec_lead_jet_pt->Draw("PE sames");


  // h_sherpa_nom_elec_lead_jet_pt->SetMarkerStyle(20);
  // h_sherpa_nom_elec_lead_jet_pt->SetMarkerSize(1.2);
  // h_sherpa_nom_elec_lead_jet_pt->SetMarkerColor(kRed);
  // h_sherpa_nom_elec_lead_jet_pt->Draw("PE sames");


  // //Legend
  // TLegend* lgnd_tc01 = new TLegend(0.15,0.15,0.28,0.35);
  // lgnd_tc01->SetFillColor(0);
  // lgnd_tc01->SetTextSize(0.03);
  // lgnd_tc01->SetBorderSize(0);


  // char lgnd_alpgen_nom_elec_lead_jet_pt_name[20];
  // sprintf(lgnd_alpgen_nom_elec_lead_jet_pt_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_elec_lead_jet_pt->Integral());
  // lgnd_tc01->AddEntry(h_alpgen_nom_elec_lead_jet_pt,lgnd_alpgen_nom_elec_lead_jet_pt_name,"p");

  // char lgnd_alpgen_iqopt3_elec_lead_jet_pt_name[20];
  // sprintf(lgnd_alpgen_iqopt3_elec_lead_jet_pt_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_elec_lead_jet_pt->Integral());
  // lgnd_tc01->AddEntry(h_alpgen_iqopt3_elec_lead_jet_pt,lgnd_alpgen_iqopt3_elec_lead_jet_pt_name,"p");

  // char lgnd_alpgen_ptjmin10_elec_lead_jet_pt_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_elec_lead_jet_pt_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_elec_lead_jet_pt->Integral());
  // lgnd_tc01->AddEntry(h_alpgen_ptjmin10_elec_lead_jet_pt,lgnd_alpgen_ptjmin10_elec_lead_jet_pt_name,"p");

  // char lgnd_sherpa_nom_elec_lead_jet_pt_name[20];
  // sprintf(lgnd_sherpa_nom_elec_lead_jet_pt_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_elec_lead_jet_pt->Integral());
  // lgnd_tc01->AddEntry(h_sherpa_nom_elec_lead_jet_pt,lgnd_sherpa_nom_elec_lead_jet_pt_name,"p");

  // lgnd_tc01->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc01_pad01->cd();
  // tc01_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_elec_lead_jet_pt->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_elec_lead_jet_pt->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_elec_lead_jet_pt->GetXaxis())->GetXmax();

  // // alp-sherp/sherp
  // string tc01_ratio_alpgen_sherpa_lead_jet_pt_name = "tc01_ratio_alpgen_sherpa_lead_jet_pt";
  // TH1F* h_ratio_alpgen_sherpa_lead_jet_pt = new TH1F(tc01_ratio_alpgen_sherpa_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_sherpa_lead_jet_pt->SetMarkerStyle(8);
  // h_ratio_alpgen_sherpa_lead_jet_pt->SetMarkerColor(kRed);

  // TAxis* h_ratio_alpgen_sherpa_lead_jet_pt_xaxis = h_ratio_alpgen_sherpa_lead_jet_pt->GetXaxis();
  // TAxis* h_ratio_alpgen_sherpa_lead_jet_pt_yaxis = h_ratio_alpgen_sherpa_lead_jet_pt->GetYaxis();
  
  // h_ratio_alpgen_sherpa_lead_jet_pt_xaxis->SetLabelSize(0.08);
  // h_ratio_alpgen_sherpa_lead_jet_pt_yaxis->SetLabelSize(0.08);

  // h_ratio_alpgen_sherpa_lead_jet_pt_xaxis->SetTitle("lead jet pt");
  // h_ratio_alpgen_sherpa_lead_jet_pt_xaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_lead_jet_pt_yaxis->SetNdivisions(4,4,4);
  // h_ratio_alpgen_sherpa_lead_jet_pt_yaxis->SetTitle("(alpgen-MC)/MC");
  // h_ratio_alpgen_sherpa_lead_jet_pt_yaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_lead_jet_pt_yaxis->SetTitleOffset(0.36);
  // h_ratio_alpgen_sherpa_lead_jet_pt_yaxis->SetRangeUser(-1,1);

  
  // // alp-iqopt3/iqopt3
  // string tc01_ratio_alpgen_iqopt3_lead_jet_pt_name = "tc01_ratio_alpgen_iqopt3_lead_jet_pt";
  // TH1F* h_ratio_alpgen_iqopt3_lead_jet_pt = new TH1F(tc01_ratio_alpgen_iqopt3_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerStyle(8);
  // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerColor(kGreen);

  
  // // alp-ptjmin10/ptjmin10
  // string tc01_ratio_alpgen_ptjmin10_lead_jet_pt_name = "tc01_ratio_alpgen_ptjmin10_lead_jet_pt";
  // TH1F* h_ratio_alpgen_ptjmin10_lead_jet_pt = new TH1F(tc01_ratio_alpgen_ptjmin10_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerStyle(8);
  // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerColor(kBlue);


  
  // double tc01_alpgen_sherpa_ratio=0.;
  // double tc01_alpgen_iqopt3_ratio=0.;
  // double tc01_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc01_alpgen_nom_bin_n=h_alpgen_nom_elec_lead_jet_pt->GetBinContent(b);
  //   double tc01_alpgen_nom_bin_err=h_alpgen_nom_elec_lead_jet_pt->GetBinError(b);    

  //   double tc01_sherpa_nom_bin_n=h_sherpa_nom_elec_lead_jet_pt->GetBinContent(b);
  //   double tc01_sherpa_nom_bin_err=h_sherpa_nom_elec_lead_jet_pt->GetBinError(b);    

  //   double tc01_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_elec_lead_jet_pt->GetBinContent(b);
  //   double tc01_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_elec_lead_jet_pt->GetBinError(b);

  //   double tc01_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_elec_lead_jet_pt->GetBinContent(b);
  //   double tc01_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_elec_lead_jet_pt->GetBinError(b);



  //   if(tc01_alpgen_nom_bin_n && tc01_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc01_abs_alpgen_sherpa_err = sqrt(pow(tc01_alpgen_nom_bin_err,2.)+pow(tc01_sherpa_nom_bin_err,2.));
  //     double tc01_rel_alpgen_sherpa_err = tc01_abs_alpgen_sherpa_err/(tc01_alpgen_nom_bin_n-tc01_sherpa_nom_bin_n);
  //     double tc01_rel_sherpa_err = tc01_sherpa_nom_bin_err/tc01_sherpa_nom_bin_n;
      
  //     double tc01_rel_ratio_alpgen_sherpa_lead_jet_pt_err = sqrt(pow(tc01_rel_alpgen_sherpa_err,2.)+pow(tc01_rel_sherpa_err,2.));

  //     double tc01_alpgen_sherpa_ratio = (tc01_alpgen_nom_bin_n-tc01_sherpa_nom_bin_n)/tc01_sherpa_nom_bin_n;

  //     double tc01_alpgen_sherpa_ratio_err = fabs(tc01_rel_ratio_alpgen_sherpa_lead_jet_pt_err*tc01_alpgen_sherpa_ratio);

  //     h_ratio_alpgen_sherpa_lead_jet_pt->SetBinContent(b,tc01_alpgen_sherpa_ratio);
  //     h_ratio_alpgen_sherpa_lead_jet_pt->SetBinError(b,tc01_alpgen_sherpa_ratio_err);
  //   }
    

  //   if(tc01_alpgen_nom_bin_n && tc01_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc01_abs_alpgen_iqopt3_err = sqrt(pow(tc01_alpgen_nom_bin_err,2.)+pow(tc01_alpgen_iqopt3_bin_err,2.));
  //     double tc01_rel_alpgen_iqopt3_err = tc01_abs_alpgen_iqopt3_err/(tc01_alpgen_nom_bin_n-tc01_alpgen_iqopt3_bin_n);
  //     double tc01_rel_iqopt3_err = tc01_alpgen_iqopt3_bin_err/tc01_alpgen_iqopt3_bin_n;
      
  //     double tc01_rel_ratio_alpgen_iqopt3_lead_jet_pt_err = sqrt(pow(tc01_rel_alpgen_iqopt3_err,2.)+pow(tc01_rel_iqopt3_err,2.));

  //     double tc01_alpgen_iqopt3_ratio = (tc01_alpgen_nom_bin_n-tc01_alpgen_iqopt3_bin_n)/tc01_alpgen_iqopt3_bin_n;

  //     double tc01_alpgen_iqopt3_ratio_err = fabs(tc01_rel_ratio_alpgen_iqopt3_lead_jet_pt_err*tc01_alpgen_iqopt3_ratio);

  //     h_ratio_alpgen_iqopt3_lead_jet_pt->SetBinContent(b,tc01_alpgen_iqopt3_ratio);
  //     h_ratio_alpgen_iqopt3_lead_jet_pt->SetBinError(b,tc01_alpgen_iqopt3_ratio_err);
  //   }

    

  //   if(tc01_alpgen_nom_bin_n && tc01_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc01_abs_alpgen_ptjmin10_err = sqrt(pow(tc01_alpgen_nom_bin_err,2.)+pow(tc01_alpgen_ptjmin10_bin_err,2.));
  //     double tc01_rel_alpgen_ptjmin10_err = tc01_abs_alpgen_ptjmin10_err/(tc01_alpgen_nom_bin_n-tc01_alpgen_ptjmin10_bin_n);
  //     double tc01_rel_ptjmin10_err = tc01_alpgen_ptjmin10_bin_err/tc01_alpgen_ptjmin10_bin_n;
      
  //     double tc01_rel_ratio_alpgen_ptjmin10_lead_jet_pt_err = sqrt(pow(tc01_rel_alpgen_ptjmin10_err,2.)+pow(tc01_rel_ptjmin10_err,2.));

  //     double tc01_alpgen_ptjmin10_ratio = (tc01_alpgen_nom_bin_n-tc01_alpgen_ptjmin10_bin_n)/tc01_alpgen_ptjmin10_bin_n;

  //     double tc01_alpgen_ptjmin10_ratio_err = fabs(tc01_rel_ratio_alpgen_ptjmin10_lead_jet_pt_err*tc01_alpgen_ptjmin10_ratio);

  //     h_ratio_alpgen_ptjmin10_lead_jet_pt->SetBinContent(b,tc01_alpgen_ptjmin10_ratio);
  //     h_ratio_alpgen_ptjmin10_lead_jet_pt->SetBinError(b,tc01_alpgen_ptjmin10_ratio_err);
  //   }
    
  // }


  // h_ratio_alpgen_sherpa_lead_jet_pt->Draw("PE");
  // h_ratio_alpgen_iqopt3_lead_jet_pt->Draw("PE sames");
  // h_ratio_alpgen_ptjmin10_lead_jet_pt->Draw("PE sames");
  
  // tc01->Update();

  // tc01->SaveAs("./plots/latest/elec_lead_jet_pt.png");
    
  // //NEXT
  
  // //////////////////////////////////////////////////
  // // tc01_5
  // // lead_jet_pt: sherpa/alpgen+wjrw
  // //////////////////////////////////////////////////
  
  // string tc01_5_title = "Lead Jet Pt (elec) w/ Data";
  // string tc01_5_name = "tc01_5";
  // TCanvas* tc01_5 = new TCanvas(tc01_5_name.c_str(),tc01_5_title.c_str(),0,0,1920,1200);
  // tc01_5->cd();

  // TPad* tc01_5_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc01_5_pad01->SetTopMargin(0.05);
  // tc01_5_pad01->SetBottomMargin(0.31);
  // tc01_5_pad01->Draw();

  // TPad* tc01_5_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc01_5_pad02->SetBottomMargin(0.0005);
  // tc01_5_pad02->SetLogy();
  // tc01_5_pad02->Draw();
  // tc01_5_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_elec_lead_jet_pt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_purw_nom_lead_jet_pt");
  // TH1F* h_alpgen_iqopt3_elec_lead_jet_pt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_iqopt3_lead_jet_pt");
  // TH1F* h_alpgen_ptjmin10_elec_lead_jet_pt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_ptjmin10_lead_jet_pt");
  // TH1F* h_sherpa_nom_elec_lead_jet_pt = (TH1F*) wjets_sherpa_file->Get("all/h_elec_purw_nom_lead_jet_pt");
  // TH1F* h_data_elec_lead_jet_pt = (TH1F*) data_file->Get("all/h_elec_purw_nom_lead_jet_pt");

  // TH1F* h_top_elec_lead_jet_pt = (TH1F*) top_mcatnlo_file->Get("all/h_elec_purw_nom_lead_jet_pt");
  // TH1F* h_zjets_elec_lead_jet_pt = (TH1F*) zjets_alpgen_file->Get("all/h_elec_purw_nom_lead_jet_pt");
  // TH1F* h_vv_elec_lead_jet_pt = (TH1F*) vv_herwig_file->Get("all/h_elec_purw_nom_lead_jet_pt");
  // TH1F* h_qcd_elec_lead_jet_pt = (TH1F*) qcd_file->Get("all/h_elec_purw_nom_lead_jet_pt");
  

  // //Add Backgrounds
  // h_alpgen_nom_elec_lead_jet_pt->Add(h_top_elec_lead_jet_pt);
  // h_alpgen_nom_elec_lead_jet_pt->Add(h_zjets_elec_lead_jet_pt);
  // h_alpgen_nom_elec_lead_jet_pt->Add(h_vv_elec_lead_jet_pt);
  // h_alpgen_nom_elec_lead_jet_pt->Add(h_qcd_elec_lead_jet_pt);
  
  // h_alpgen_nom_elec_lead_jet_pt->SetMarkerStyle(20);
  // h_alpgen_nom_elec_lead_jet_pt->SetMarkerSize(1.2);
  // h_alpgen_nom_elec_lead_jet_pt->SetTitle("");
  // h_alpgen_nom_elec_lead_jet_pt->Draw("PE");

  // //Add backgrounds
  // h_alpgen_iqopt3_elec_lead_jet_pt->Add(h_top_elec_lead_jet_pt);
  // h_alpgen_iqopt3_elec_lead_jet_pt->Add(h_zjets_elec_lead_jet_pt);
  // h_alpgen_iqopt3_elec_lead_jet_pt->Add(h_vv_elec_lead_jet_pt);
  // h_alpgen_iqopt3_elec_lead_jet_pt->Add(h_qcd_elec_lead_jet_pt);

  // h_alpgen_iqopt3_elec_lead_jet_pt->SetMarkerStyle(22);
  // h_alpgen_iqopt3_elec_lead_jet_pt->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_elec_lead_jet_pt->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_elec_lead_jet_pt->Draw("PE sames");

  // //Add Backgrounds
  // h_alpgen_ptjmin10_elec_lead_jet_pt->Add(h_top_elec_lead_jet_pt);
  // h_alpgen_ptjmin10_elec_lead_jet_pt->Add(h_zjets_elec_lead_jet_pt);
  // h_alpgen_ptjmin10_elec_lead_jet_pt->Add(h_vv_elec_lead_jet_pt);
  // h_alpgen_ptjmin10_elec_lead_jet_pt->Add(h_qcd_elec_lead_jet_pt);

  // h_alpgen_ptjmin10_elec_lead_jet_pt->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_elec_lead_jet_pt->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_elec_lead_jet_pt->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_elec_lead_jet_pt->Draw("PE sames");

  // //Add Backgrounds
  // h_sherpa_nom_elec_lead_jet_pt->Add(h_top_elec_lead_jet_pt);
  // h_sherpa_nom_elec_lead_jet_pt->Add(h_zjets_elec_lead_jet_pt);
  // h_sherpa_nom_elec_lead_jet_pt->Add(h_vv_elec_lead_jet_pt);
  // h_sherpa_nom_elec_lead_jet_pt->Add(h_qcd_elec_lead_jet_pt);

  // h_sherpa_nom_elec_lead_jet_pt->SetMarkerStyle(20);
  // h_sherpa_nom_elec_lead_jet_pt->SetMarkerSize(1.2);
  // h_sherpa_nom_elec_lead_jet_pt->SetMarkerColor(kRed);
  // h_sherpa_nom_elec_lead_jet_pt->Draw("PE sames");

  // h_data_elec_lead_jet_pt->Draw("sames");


  // //Legend
  // TLegend* lgnd_tc01_5 = new TLegend(0.15,0.15,0.28,0.35);
  // lgnd_tc01_5->SetFillColor(0);
  // lgnd_tc01_5->SetTextSize(0.03);
  // lgnd_tc01_5->SetBorderSize(0);

  // char lgnd_data_elec_lead_jet_pt_name[20];
  // sprintf(lgnd_data_elec_lead_jet_pt_name,"%s,  %.2f","DATA",h_data_elec_lead_jet_pt->Integral());
  // lgnd_tc01_5->AddEntry(h_data_elec_lead_jet_pt,lgnd_data_elec_lead_jet_pt_name,"f");

  // char lgnd_alpgen_nom_elec_lead_jet_pt_name[20];
  // sprintf(lgnd_alpgen_nom_elec_lead_jet_pt_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_elec_lead_jet_pt->Integral());
  // lgnd_tc01_5->AddEntry(h_alpgen_nom_elec_lead_jet_pt,lgnd_alpgen_nom_elec_lead_jet_pt_name,"p");

  // char lgnd_alpgen_iqopt3_elec_lead_jet_pt_name[20];
  // sprintf(lgnd_alpgen_iqopt3_elec_lead_jet_pt_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_elec_lead_jet_pt->Integral());
  // lgnd_tc01_5->AddEntry(h_alpgen_iqopt3_elec_lead_jet_pt,lgnd_alpgen_iqopt3_elec_lead_jet_pt_name,"p");

  // char lgnd_alpgen_ptjmin10_elec_lead_jet_pt_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_elec_lead_jet_pt_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_elec_lead_jet_pt->Integral());
  // lgnd_tc01_5->AddEntry(h_alpgen_ptjmin10_elec_lead_jet_pt,lgnd_alpgen_ptjmin10_elec_lead_jet_pt_name,"p");

  // char lgnd_sherpa_nom_elec_lead_jet_pt_name[20];
  // sprintf(lgnd_sherpa_nom_elec_lead_jet_pt_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_elec_lead_jet_pt->Integral());
  // lgnd_tc01_5->AddEntry(h_sherpa_nom_elec_lead_jet_pt,lgnd_sherpa_nom_elec_lead_jet_pt_name,"p");

  // lgnd_tc01_5->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc01_5_pad01->cd();
  // tc01_5_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_elec_lead_jet_pt->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_elec_lead_jet_pt->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_elec_lead_jet_pt->GetXaxis())->GetXmax();

  // // data-alpgen(nom)/alpgen(nom)
  // string tc01_5_ratio_data_alpgen_lead_jet_pt_name = "tc01_5_ratio_data_alpgen_lead_jet_pt";
  // TH1F* h_ratio_data_alpgen_lead_jet_pt = new TH1F(tc01_5_ratio_data_alpgen_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_lead_jet_pt->SetMarkerStyle(8);
  // //h_ratio_data_alpgen_lead_jet_pt->SetMarkerColor(kRed);

  // TAxis* h_ratio_data_alpgen_lead_jet_pt_xaxis = h_ratio_data_alpgen_lead_jet_pt->GetXaxis();
  // TAxis* h_ratio_data_alpgen_lead_jet_pt_yaxis = h_ratio_data_alpgen_lead_jet_pt->GetYaxis();
  
  // h_ratio_data_alpgen_lead_jet_pt_xaxis->SetLabelSize(0.08);
  // h_ratio_data_alpgen_lead_jet_pt_yaxis->SetLabelSize(0.08);

  // h_ratio_data_alpgen_lead_jet_pt_xaxis->SetTitle("lead jet pt");
  // h_ratio_data_alpgen_lead_jet_pt_xaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_lead_jet_pt_yaxis->SetNdivisions(4,4,4);
  // h_ratio_data_alpgen_lead_jet_pt_yaxis->SetTitle("(data-MC)/MC");
  // h_ratio_data_alpgen_lead_jet_pt_yaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_lead_jet_pt_yaxis->SetTitleOffset(0.36);
  // h_ratio_data_alpgen_lead_jet_pt_yaxis->SetRangeUser(-1,1);

  // // data-sherpa(nom)/sherpa(nom)
  // string tc01_5_ratio_data_sherpa_lead_jet_pt_name = "tc01_5_ratio_data_sherpa_lead_jet_pt";
  // TH1F* h_ratio_data_sherpa_lead_jet_pt = new TH1F(tc01_5_ratio_data_sherpa_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_sherpa_lead_jet_pt->SetMarkerStyle(8);
  // h_ratio_data_sherpa_lead_jet_pt->SetMarkerColor(kRed);


  // // data-alpgen(iqopt3)/alpgen(iqopt3)
  // string tc01_5_ratio_data_alpgen_iqopt3_lead_jet_pt_name = "tc01_5_ratio_data_alpgen_iqopt3_lead_jet_pt";
  // TH1F* h_ratio_data_alpgen_iqopt3_lead_jet_pt = new TH1F(tc01_5_ratio_data_alpgen_iqopt3_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_iqopt3_lead_jet_pt->SetMarkerStyle(8);
  // h_ratio_data_alpgen_iqopt3_lead_jet_pt->SetMarkerColor(kGreen);

  // // data-alpgen(ptjmin10)/alpgen(ptjmin10)
  // string tc01_5_ratio_data_alpgen_ptjmin10_lead_jet_pt_name = "tc01_5_ratio_data_alpgen_ptjmin10_lead_jet_pt";
  // TH1F* h_ratio_data_alpgen_ptjmin10_lead_jet_pt = new TH1F(tc01_5_ratio_data_alpgen_ptjmin10_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_ptjmin10_lead_jet_pt->SetMarkerStyle(8);
  // h_ratio_data_alpgen_ptjmin10_lead_jet_pt->SetMarkerColor(kBlue);

  

  
  // // // alp-iqopt3/iqopt3
  // // string tc01_5_ratio_alpgen_iqopt3_lead_jet_pt_name = "tc01_5_ratio_alpgen_iqopt3_lead_jet_pt";
  // // TH1F* h_ratio_alpgen_iqopt3_lead_jet_pt = new TH1F(tc01_5_ratio_alpgen_iqopt3_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerStyle(8);
  // // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerColor(kGreen);

  
  // // // alp-ptjmin10/ptjmin10
  // // string tc01_5_ratio_alpgen_ptjmin10_lead_jet_pt_name = "tc01_5_ratio_alpgen_ptjmin10_lead_jet_pt";
  // // TH1F* h_ratio_alpgen_ptjmin10_lead_jet_pt = new TH1F(tc01_5_ratio_alpgen_ptjmin10_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerStyle(8);
  // // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerColor(kBlue);


  
  // double tc01_5_data_alpgen_ratio=0.;
  // double tc01_5_data_sherpa_ratio=0.;
  // double tc01_5_data_alpgen_iqopt3_ratio=0.;
  // double tc01_5_data_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc01_5_alpgen_nom_bin_n=h_alpgen_nom_elec_lead_jet_pt->GetBinContent(b);
  //   double tc01_5_alpgen_nom_bin_err=h_alpgen_nom_elec_lead_jet_pt->GetBinError(b);    

  //   double tc01_5_data_bin_n=h_data_elec_lead_jet_pt->GetBinContent(b);
  //   double tc01_5_data_bin_err=h_data_elec_lead_jet_pt->GetBinError(b);    

  //   double tc01_5_sherpa_nom_bin_n=h_sherpa_nom_elec_lead_jet_pt->GetBinContent(b);
  //   double tc01_5_sherpa_nom_bin_err=h_sherpa_nom_elec_lead_jet_pt->GetBinError(b);    

  //   double tc01_5_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_elec_lead_jet_pt->GetBinContent(b);
  //   double tc01_5_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_elec_lead_jet_pt->GetBinError(b);

  //   double tc01_5_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_elec_lead_jet_pt->GetBinContent(b);
  //   double tc01_5_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_elec_lead_jet_pt->GetBinError(b);



  //   if(tc01_5_data_bin_n && tc01_5_alpgen_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc01_5_abs_data_alpgen_err = sqrt(pow(tc01_5_data_bin_err,2.)+pow(tc01_5_alpgen_nom_bin_err,2.));
  //     double tc01_5_rel_data_alpgen_err = tc01_5_abs_data_alpgen_err/(tc01_5_data_bin_n-tc01_5_alpgen_nom_bin_n);
  //     double tc01_5_rel_alpgen_err = tc01_5_alpgen_nom_bin_err/tc01_5_alpgen_nom_bin_n;
      
  //     double tc01_5_rel_ratio_data_alpgen_lead_jet_pt_err = sqrt(pow(tc01_5_rel_data_alpgen_err,2.)+pow(tc01_5_rel_alpgen_err,2.));

  //     double tc01_5_data_alpgen_ratio = (tc01_5_data_bin_n-tc01_5_alpgen_nom_bin_n)/tc01_5_alpgen_nom_bin_n;

  //     double tc01_5_data_alpgen_ratio_err = fabs(tc01_5_rel_ratio_data_alpgen_lead_jet_pt_err*tc01_5_data_alpgen_ratio);

  //     h_ratio_data_alpgen_lead_jet_pt->SetBinContent(b,tc01_5_data_alpgen_ratio);
  //     h_ratio_data_alpgen_lead_jet_pt->SetBinError(b,tc01_5_data_alpgen_ratio_err);
  //   }
    

  //   if(tc01_5_data_bin_n && tc01_5_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc01_5_abs_data_sherpa_err = sqrt(pow(tc01_5_data_bin_err,2.)+pow(tc01_5_sherpa_nom_bin_err,2.));
  //     double tc01_5_rel_data_sherpa_err = tc01_5_abs_data_sherpa_err/(tc01_5_data_bin_n-tc01_5_sherpa_nom_bin_n);
  //     double tc01_5_rel_sherpa_err = tc01_5_sherpa_nom_bin_err/tc01_5_sherpa_nom_bin_n;
      
  //     double tc01_5_rel_ratio_data_sherpa_lead_jet_pt_err = sqrt(pow(tc01_5_rel_data_sherpa_err,2.)+pow(tc01_5_rel_sherpa_err,2.));

  //     double tc01_5_data_sherpa_ratio = (tc01_5_data_bin_n-tc01_5_sherpa_nom_bin_n)/tc01_5_sherpa_nom_bin_n;

  //     double tc01_5_data_sherpa_ratio_err = fabs(tc01_5_rel_ratio_data_sherpa_lead_jet_pt_err*tc01_5_data_sherpa_ratio);

  //     h_ratio_data_sherpa_lead_jet_pt->SetBinContent(b,tc01_5_data_sherpa_ratio);
  //     h_ratio_data_sherpa_lead_jet_pt->SetBinError(b,tc01_5_data_sherpa_ratio_err);
  //   }
    

  //   if(tc01_5_data_bin_n && tc01_5_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc01_5_abs_data_alpgen_iqopt3_err = sqrt(pow(tc01_5_data_bin_err,2.)+pow(tc01_5_alpgen_iqopt3_bin_err,2.));
  //     double tc01_5_rel_data_alpgen_iqopt3_err = tc01_5_abs_data_alpgen_iqopt3_err/(tc01_5_data_bin_n-tc01_5_alpgen_iqopt3_bin_n);
  //     double tc01_5_rel_alpgen_iqopt3_err = tc01_5_alpgen_iqopt3_bin_err/tc01_5_alpgen_iqopt3_bin_n;
      
  //     double tc01_5_rel_ratio_data_alpgen_iqopt3_lead_jet_pt_err = sqrt(pow(tc01_5_rel_data_alpgen_iqopt3_err,2.)+pow(tc01_5_rel_alpgen_iqopt3_err,2.));

  //     double tc01_5_data_alpgen_iqopt3_ratio = (tc01_5_data_bin_n-tc01_5_alpgen_iqopt3_bin_n)/tc01_5_alpgen_iqopt3_bin_n;

  //     double tc01_5_data_alpgen_iqopt3_ratio_err = fabs(tc01_5_rel_ratio_data_alpgen_iqopt3_lead_jet_pt_err*tc01_5_data_alpgen_iqopt3_ratio);

  //     h_ratio_data_alpgen_iqopt3_lead_jet_pt->SetBinContent(b,tc01_5_data_alpgen_iqopt3_ratio);
  //     h_ratio_data_alpgen_iqopt3_lead_jet_pt->SetBinError(b,tc01_5_data_alpgen_iqopt3_ratio_err);
  //   }
    
  //   if(tc01_5_data_bin_n && tc01_5_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc01_5_abs_data_alpgen_ptjmin10_err = sqrt(pow(tc01_5_data_bin_err,2.)+pow(tc01_5_alpgen_ptjmin10_bin_err,2.));
  //     double tc01_5_rel_data_alpgen_ptjmin10_err = tc01_5_abs_data_alpgen_ptjmin10_err/(tc01_5_data_bin_n-tc01_5_alpgen_ptjmin10_bin_n);
  //     double tc01_5_rel_alpgen_ptjmin10_err = tc01_5_alpgen_ptjmin10_bin_err/tc01_5_alpgen_ptjmin10_bin_n;
      
  //     double tc01_5_rel_ratio_data_alpgen_ptjmin10_lead_jet_pt_err = sqrt(pow(tc01_5_rel_data_alpgen_ptjmin10_err,2.)+pow(tc01_5_rel_alpgen_ptjmin10_err,2.));

  //     double tc01_5_data_alpgen_ptjmin10_ratio = (tc01_5_data_bin_n-tc01_5_alpgen_ptjmin10_bin_n)/tc01_5_alpgen_ptjmin10_bin_n;

  //     double tc01_5_data_alpgen_ptjmin10_ratio_err = fabs(tc01_5_rel_ratio_data_alpgen_ptjmin10_lead_jet_pt_err*tc01_5_data_alpgen_ptjmin10_ratio);

  //     h_ratio_data_alpgen_ptjmin10_lead_jet_pt->SetBinContent(b,tc01_5_data_alpgen_ptjmin10_ratio);
  //     h_ratio_data_alpgen_ptjmin10_lead_jet_pt->SetBinError(b,tc01_5_data_alpgen_ptjmin10_ratio_err);
  //   }
    
  // }



  // h_ratio_data_alpgen_lead_jet_pt->Draw("PE");
  // h_ratio_data_sherpa_lead_jet_pt->Draw("PE sames");
  // h_ratio_data_alpgen_iqopt3_lead_jet_pt->Draw("PE sames");
  // h_ratio_data_alpgen_ptjmin10_lead_jet_pt->Draw("PE sames");
  
  // //  h_ratio_alpgen_iqopt3_lead_jet_pt->Draw("PE sames");
  // //  h_ratio_alpgen_ptjmin10_lead_jet_pt->Draw("PE sames");
  
  // tc01_5->Update();

  // tc01_5->SaveAs("./plots/latest/data_elec_lead_jet_pt.png");
    
  // //NEXT

  // //////////////////////////////////////////////////
  // // tc02
  // // lead_jet_pt: sherpa/alpgen+wjrw
  // //////////////////////////////////////////////////
  
  // string tc02_title = "Lead Jet Pt (muon)";
  // string tc02_name = "tc02";
  // TCanvas* tc02 = new TCanvas(tc02_name.c_str(),tc02_title.c_str(),0,0,1920,1200);
  // tc02->cd();

  // TPad* tc02_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc02_pad01->SetTopMargin(0.05);
  // tc02_pad01->SetBottomMargin(0.31);
  // tc02_pad01->Draw();

  // TPad* tc02_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc02_pad02->SetBottomMargin(0.0005);
  // tc02_pad02->SetLogy();
  // tc02_pad02->Draw();
  // tc02_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_muon_lead_jet_pt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_purw_nom_lead_jet_pt");
  // TH1F* h_alpgen_iqopt3_muon_lead_jet_pt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_iqopt3_lead_jet_pt");
  // TH1F* h_alpgen_ptjmin10_muon_lead_jet_pt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_ptjmin10_lead_jet_pt");
  // TH1F* h_sherpa_nom_muon_lead_jet_pt = (TH1F*) wjets_sherpa_file->Get("all/h_muon_purw_nom_lead_jet_pt");
  
  // h_alpgen_nom_muon_lead_jet_pt->SetMarkerStyle(20);
  // h_alpgen_nom_muon_lead_jet_pt->SetMarkerSize(1.2);
  // h_alpgen_nom_muon_lead_jet_pt->SetTitle("");
  // h_alpgen_nom_muon_lead_jet_pt->Draw("PE");

  // h_alpgen_iqopt3_muon_lead_jet_pt->SetMarkerStyle(22);
  // h_alpgen_iqopt3_muon_lead_jet_pt->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_muon_lead_jet_pt->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_muon_lead_jet_pt->Draw("PE sames");


  // h_alpgen_ptjmin10_muon_lead_jet_pt->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_muon_lead_jet_pt->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_muon_lead_jet_pt->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_muon_lead_jet_pt->Draw("PE sames");


  // h_sherpa_nom_muon_lead_jet_pt->SetMarkerStyle(20);
  // h_sherpa_nom_muon_lead_jet_pt->SetMarkerSize(1.2);
  // h_sherpa_nom_muon_lead_jet_pt->SetMarkerColor(kRed);
  // h_sherpa_nom_muon_lead_jet_pt->Draw("PE sames");


  // //Legend
  // TLegend* lgnd_tc02 = new TLegend(0.15,0.15,0.28,0.35);
  // lgnd_tc02->SetFillColor(0);
  // lgnd_tc02->SetTextSize(0.03);
  // lgnd_tc02->SetBorderSize(0);

  // char lgnd_alpgen_nom_muon_lead_jet_pt_name[20];
  // sprintf(lgnd_alpgen_nom_muon_lead_jet_pt_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_muon_lead_jet_pt->Integral());
  // lgnd_tc02->AddEntry(h_alpgen_nom_muon_lead_jet_pt,lgnd_alpgen_nom_muon_lead_jet_pt_name,"p");

  // char lgnd_alpgen_iqopt3_muon_lead_jet_pt_name[20];
  // sprintf(lgnd_alpgen_iqopt3_muon_lead_jet_pt_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_muon_lead_jet_pt->Integral());
  // lgnd_tc02->AddEntry(h_alpgen_iqopt3_muon_lead_jet_pt,lgnd_alpgen_iqopt3_muon_lead_jet_pt_name,"p");

  // char lgnd_alpgen_ptjmin10_muon_lead_jet_pt_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_muon_lead_jet_pt_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_muon_lead_jet_pt->Integral());
  // lgnd_tc02->AddEntry(h_alpgen_ptjmin10_muon_lead_jet_pt,lgnd_alpgen_ptjmin10_muon_lead_jet_pt_name,"p");

  // char lgnd_sherpa_nom_muon_lead_jet_pt_name[20];
  // sprintf(lgnd_sherpa_nom_muon_lead_jet_pt_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_muon_lead_jet_pt->Integral());
  // lgnd_tc02->AddEntry(h_sherpa_nom_muon_lead_jet_pt,lgnd_sherpa_nom_muon_lead_jet_pt_name,"p");

  // lgnd_tc02->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc02_pad01->cd();
  // tc02_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_muon_lead_jet_pt->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_muon_lead_jet_pt->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_muon_lead_jet_pt->GetXaxis())->GetXmax();

  // // alp-sherp/sherp
  // string tc02_ratio_alpgen_sherpa_lead_jet_pt_name = "tc02_ratio_alpgen_sherpa_lead_jet_pt";
  // TH1F* h_ratio_alpgen_sherpa_lead_jet_pt = new TH1F(tc02_ratio_alpgen_sherpa_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_sherpa_lead_jet_pt->SetMarkerStyle(8);
  // h_ratio_alpgen_sherpa_lead_jet_pt->SetMarkerColor(kRed);

  // TAxis* h_ratio_alpgen_sherpa_lead_jet_pt_xaxis = h_ratio_alpgen_sherpa_lead_jet_pt->GetXaxis();
  // TAxis* h_ratio_alpgen_sherpa_lead_jet_pt_yaxis = h_ratio_alpgen_sherpa_lead_jet_pt->GetYaxis();
  
  // h_ratio_alpgen_sherpa_lead_jet_pt_xaxis->SetLabelSize(0.08);
  // h_ratio_alpgen_sherpa_lead_jet_pt_yaxis->SetLabelSize(0.08);

  // h_ratio_alpgen_sherpa_lead_jet_pt_xaxis->SetTitle("lead jet pt");
  // h_ratio_alpgen_sherpa_lead_jet_pt_xaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_lead_jet_pt_yaxis->SetNdivisions(4,4,4);
  // h_ratio_alpgen_sherpa_lead_jet_pt_yaxis->SetTitle("(alpgen-MC)/MC");
  // h_ratio_alpgen_sherpa_lead_jet_pt_yaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_lead_jet_pt_yaxis->SetTitleOffset(0.36);
  // h_ratio_alpgen_sherpa_lead_jet_pt_yaxis->SetRangeUser(-1,1);

  
  // // alp-iqopt3/iqopt3
  // string tc02_ratio_alpgen_iqopt3_lead_jet_pt_name = "tc02_ratio_alpgen_iqopt3_lead_jet_pt";
  // TH1F* h_ratio_alpgen_iqopt3_lead_jet_pt = new TH1F(tc02_ratio_alpgen_iqopt3_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerStyle(8);
  // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerColor(kGreen);

  
  // // alp-ptjmin10/ptjmin10
  // string tc02_ratio_alpgen_ptjmin10_lead_jet_pt_name = "tc02_ratio_alpgen_ptjmin10_lead_jet_pt";
  // TH1F* h_ratio_alpgen_ptjmin10_lead_jet_pt = new TH1F(tc02_ratio_alpgen_ptjmin10_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerStyle(8);
  // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerColor(kBlue);


  
  // double tc02_alpgen_sherpa_ratio=0.;
  // double tc02_alpgen_iqopt3_ratio=0.;
  // double tc02_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc02_alpgen_nom_bin_n=h_alpgen_nom_muon_lead_jet_pt->GetBinContent(b);
  //   double tc02_alpgen_nom_bin_err=h_alpgen_nom_muon_lead_jet_pt->GetBinError(b);    

  //   double tc02_sherpa_nom_bin_n=h_sherpa_nom_muon_lead_jet_pt->GetBinContent(b);
  //   double tc02_sherpa_nom_bin_err=h_sherpa_nom_muon_lead_jet_pt->GetBinError(b);    

  //   double tc02_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_muon_lead_jet_pt->GetBinContent(b);
  //   double tc02_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_muon_lead_jet_pt->GetBinError(b);

  //   double tc02_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_muon_lead_jet_pt->GetBinContent(b);
  //   double tc02_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_muon_lead_jet_pt->GetBinError(b);



  //   if(tc02_alpgen_nom_bin_n && tc02_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc02_abs_alpgen_sherpa_err = sqrt(pow(tc02_alpgen_nom_bin_err,2.)+pow(tc02_sherpa_nom_bin_err,2.));
  //     double tc02_rel_alpgen_sherpa_err = tc02_abs_alpgen_sherpa_err/(tc02_alpgen_nom_bin_n-tc02_sherpa_nom_bin_n);
  //     double tc02_rel_sherpa_err = tc02_sherpa_nom_bin_err/tc02_sherpa_nom_bin_n;
      
  //     double tc02_rel_ratio_alpgen_sherpa_lead_jet_pt_err = sqrt(pow(tc02_rel_alpgen_sherpa_err,2.)+pow(tc02_rel_sherpa_err,2.));

  //     double tc02_alpgen_sherpa_ratio = (tc02_alpgen_nom_bin_n-tc02_sherpa_nom_bin_n)/tc02_sherpa_nom_bin_n;

  //     double tc02_alpgen_sherpa_ratio_err = fabs(tc02_rel_ratio_alpgen_sherpa_lead_jet_pt_err*tc02_alpgen_sherpa_ratio);

  //     h_ratio_alpgen_sherpa_lead_jet_pt->SetBinContent(b,tc02_alpgen_sherpa_ratio);
  //     h_ratio_alpgen_sherpa_lead_jet_pt->SetBinError(b,tc02_alpgen_sherpa_ratio_err);
  //   }
    

  //   if(tc02_alpgen_nom_bin_n && tc02_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc02_abs_alpgen_iqopt3_err = sqrt(pow(tc02_alpgen_nom_bin_err,2.)+pow(tc02_alpgen_iqopt3_bin_err,2.));
  //     double tc02_rel_alpgen_iqopt3_err = tc02_abs_alpgen_iqopt3_err/(tc02_alpgen_nom_bin_n-tc02_alpgen_iqopt3_bin_n);
  //     double tc02_rel_iqopt3_err = tc02_alpgen_iqopt3_bin_err/tc02_alpgen_iqopt3_bin_n;
      
  //     double tc02_rel_ratio_alpgen_iqopt3_lead_jet_pt_err = sqrt(pow(tc02_rel_alpgen_iqopt3_err,2.)+pow(tc02_rel_iqopt3_err,2.));

  //     double tc02_alpgen_iqopt3_ratio = (tc02_alpgen_nom_bin_n-tc02_alpgen_iqopt3_bin_n)/tc02_alpgen_iqopt3_bin_n;

  //     double tc02_alpgen_iqopt3_ratio_err = fabs(tc02_rel_ratio_alpgen_iqopt3_lead_jet_pt_err*tc02_alpgen_iqopt3_ratio);

  //     h_ratio_alpgen_iqopt3_lead_jet_pt->SetBinContent(b,tc02_alpgen_iqopt3_ratio);
  //     h_ratio_alpgen_iqopt3_lead_jet_pt->SetBinError(b,tc02_alpgen_iqopt3_ratio_err);
  //   }

    

  //   if(tc02_alpgen_nom_bin_n && tc02_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc02_abs_alpgen_ptjmin10_err = sqrt(pow(tc02_alpgen_nom_bin_err,2.)+pow(tc02_alpgen_ptjmin10_bin_err,2.));
  //     double tc02_rel_alpgen_ptjmin10_err = tc02_abs_alpgen_ptjmin10_err/(tc02_alpgen_nom_bin_n-tc02_alpgen_ptjmin10_bin_n);
  //     double tc02_rel_ptjmin10_err = tc02_alpgen_ptjmin10_bin_err/tc02_alpgen_ptjmin10_bin_n;
      
  //     double tc02_rel_ratio_alpgen_ptjmin10_lead_jet_pt_err = sqrt(pow(tc02_rel_alpgen_ptjmin10_err,2.)+pow(tc02_rel_ptjmin10_err,2.));

  //     double tc02_alpgen_ptjmin10_ratio = (tc02_alpgen_nom_bin_n-tc02_alpgen_ptjmin10_bin_n)/tc02_alpgen_ptjmin10_bin_n;

  //     double tc02_alpgen_ptjmin10_ratio_err = fabs(tc02_rel_ratio_alpgen_ptjmin10_lead_jet_pt_err*tc02_alpgen_ptjmin10_ratio);

  //     h_ratio_alpgen_ptjmin10_lead_jet_pt->SetBinContent(b,tc02_alpgen_ptjmin10_ratio);
  //     h_ratio_alpgen_ptjmin10_lead_jet_pt->SetBinError(b,tc02_alpgen_ptjmin10_ratio_err);
  //   }
    
  // }


  // h_ratio_alpgen_sherpa_lead_jet_pt->Draw("PE");
  // h_ratio_alpgen_iqopt3_lead_jet_pt->Draw("PE sames");
  // h_ratio_alpgen_ptjmin10_lead_jet_pt->Draw("PE sames");
  
  // tc02->Update();

  // tc02->SaveAs("./plots/latest/muon_lead_jet_pt.png");
    
  // //NEXT
  
  // //////////////////////////////////////////////////
  // // tc02_5
  // // lead_jet_pt: sherpa/alpgen+wjrw
  // //////////////////////////////////////////////////
  
  // string tc02_5_title = "Lead Jet Pt (muon) w/Data";
  // string tc02_5_name = "tc02_5";
  // TCanvas* tc02_5 = new TCanvas(tc02_5_name.c_str(),tc02_5_title.c_str(),0,0,1920,1200);
  // tc02_5->cd();

  // TPad* tc02_5_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc02_5_pad01->SetTopMargin(0.05);
  // tc02_5_pad01->SetBottomMargin(0.31);
  // tc02_5_pad01->Draw();

  // TPad* tc02_5_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc02_5_pad02->SetBottomMargin(0.0005);
  // tc02_5_pad02->SetLogy();
  // tc02_5_pad02->Draw();
  // tc02_5_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_muon_lead_jet_pt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_purw_nom_lead_jet_pt");
  // TH1F* h_alpgen_iqopt3_muon_lead_jet_pt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_iqopt3_lead_jet_pt");
  // TH1F* h_alpgen_ptjmin10_muon_lead_jet_pt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_ptjmin10_lead_jet_pt");
  // TH1F* h_sherpa_nom_muon_lead_jet_pt = (TH1F*) wjets_sherpa_file->Get("all/h_muon_purw_nom_lead_jet_pt");
  // TH1F* h_data_muon_lead_jet_pt = (TH1F*) data_file->Get("all/h_muon_purw_nom_lead_jet_pt");

  // TH1F* h_top_muon_lead_jet_pt = (TH1F*) top_mcatnlo_file->Get("all/h_muon_purw_nom_lead_jet_pt");
  // TH1F* h_zjets_muon_lead_jet_pt = (TH1F*) zjets_alpgen_file->Get("all/h_muon_purw_nom_lead_jet_pt");
  // TH1F* h_vv_muon_lead_jet_pt = (TH1F*) vv_herwig_file->Get("all/h_muon_purw_nom_lead_jet_pt");
  // TH1F* h_qcd_muon_lead_jet_pt = (TH1F*) qcd_file->Get("all/h_muon_purw_nom_lead_jet_pt");
  

  // //Add Backgrounds
  // h_alpgen_nom_muon_lead_jet_pt->Add(h_top_muon_lead_jet_pt);
  // h_alpgen_nom_muon_lead_jet_pt->Add(h_zjets_muon_lead_jet_pt);
  // h_alpgen_nom_muon_lead_jet_pt->Add(h_vv_muon_lead_jet_pt);
  // h_alpgen_nom_muon_lead_jet_pt->Add(h_qcd_muon_lead_jet_pt);
  
  // h_alpgen_nom_muon_lead_jet_pt->SetMarkerStyle(20);
  // h_alpgen_nom_muon_lead_jet_pt->SetMarkerSize(1.2);
  // h_alpgen_nom_muon_lead_jet_pt->SetTitle("");
  // h_alpgen_nom_muon_lead_jet_pt->Draw("PE");

  // //Add backgrounds
  // h_alpgen_iqopt3_muon_lead_jet_pt->Add(h_top_muon_lead_jet_pt);
  // h_alpgen_iqopt3_muon_lead_jet_pt->Add(h_zjets_muon_lead_jet_pt);
  // h_alpgen_iqopt3_muon_lead_jet_pt->Add(h_vv_muon_lead_jet_pt);
  // h_alpgen_iqopt3_muon_lead_jet_pt->Add(h_qcd_muon_lead_jet_pt);

  // h_alpgen_iqopt3_muon_lead_jet_pt->SetMarkerStyle(22);
  // h_alpgen_iqopt3_muon_lead_jet_pt->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_muon_lead_jet_pt->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_muon_lead_jet_pt->Draw("PE sames");

  // //Add Backgrounds
  // h_alpgen_ptjmin10_muon_lead_jet_pt->Add(h_top_muon_lead_jet_pt);
  // h_alpgen_ptjmin10_muon_lead_jet_pt->Add(h_zjets_muon_lead_jet_pt);
  // h_alpgen_ptjmin10_muon_lead_jet_pt->Add(h_vv_muon_lead_jet_pt);
  // h_alpgen_ptjmin10_muon_lead_jet_pt->Add(h_qcd_muon_lead_jet_pt);

  // h_alpgen_ptjmin10_muon_lead_jet_pt->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_muon_lead_jet_pt->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_muon_lead_jet_pt->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_muon_lead_jet_pt->Draw("PE sames");

  // //Add Backgrounds
  // h_sherpa_nom_muon_lead_jet_pt->Add(h_top_muon_lead_jet_pt);
  // h_sherpa_nom_muon_lead_jet_pt->Add(h_zjets_muon_lead_jet_pt);
  // h_sherpa_nom_muon_lead_jet_pt->Add(h_vv_muon_lead_jet_pt);
  // h_sherpa_nom_muon_lead_jet_pt->Add(h_qcd_muon_lead_jet_pt);

  // h_sherpa_nom_muon_lead_jet_pt->SetMarkerStyle(20);
  // h_sherpa_nom_muon_lead_jet_pt->SetMarkerSize(1.2);
  // h_sherpa_nom_muon_lead_jet_pt->SetMarkerColor(kRed);
  // h_sherpa_nom_muon_lead_jet_pt->Draw("PE sames");

  // h_data_muon_lead_jet_pt->Draw("sames");


  // //Legend
  // TLegend* lgnd_tc02_5 = new TLegend(0.15,0.15,0.28,0.35);
  // lgnd_tc02_5->SetFillColor(0);
  // lgnd_tc02_5->SetTextSize(0.03);
  // lgnd_tc02_5->SetBorderSize(0);

  // char lgnd_data_muon_lead_jet_pt_name[20];
  // sprintf(lgnd_data_muon_lead_jet_pt_name,"%s,  %.2f","DATA",h_data_muon_lead_jet_pt->Integral());
  // lgnd_tc02_5->AddEntry(h_data_muon_lead_jet_pt,lgnd_data_muon_lead_jet_pt_name,"f");

  // char lgnd_alpgen_nom_muon_lead_jet_pt_name[20];
  // sprintf(lgnd_alpgen_nom_muon_lead_jet_pt_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_muon_lead_jet_pt->Integral());
  // lgnd_tc02_5->AddEntry(h_alpgen_nom_muon_lead_jet_pt,lgnd_alpgen_nom_muon_lead_jet_pt_name,"p");

  // char lgnd_alpgen_iqopt3_muon_lead_jet_pt_name[20];
  // sprintf(lgnd_alpgen_iqopt3_muon_lead_jet_pt_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_muon_lead_jet_pt->Integral());
  // lgnd_tc02_5->AddEntry(h_alpgen_iqopt3_muon_lead_jet_pt,lgnd_alpgen_iqopt3_muon_lead_jet_pt_name,"p");

  // char lgnd_alpgen_ptjmin10_muon_lead_jet_pt_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_muon_lead_jet_pt_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_muon_lead_jet_pt->Integral());
  // lgnd_tc02_5->AddEntry(h_alpgen_ptjmin10_muon_lead_jet_pt,lgnd_alpgen_ptjmin10_muon_lead_jet_pt_name,"p");

  // char lgnd_sherpa_nom_muon_lead_jet_pt_name[20];
  // sprintf(lgnd_sherpa_nom_muon_lead_jet_pt_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_muon_lead_jet_pt->Integral());
  // lgnd_tc02_5->AddEntry(h_sherpa_nom_muon_lead_jet_pt,lgnd_sherpa_nom_muon_lead_jet_pt_name,"p");

  // lgnd_tc02_5->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc02_5_pad01->cd();
  // tc02_5_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_muon_lead_jet_pt->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_muon_lead_jet_pt->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_muon_lead_jet_pt->GetXaxis())->GetXmax();

  // // data-alpgen(nom)/alpgen(nom)
  // string tc02_5_ratio_data_alpgen_lead_jet_pt_name = "tc02_5_ratio_data_alpgen_lead_jet_pt";
  // TH1F* h_ratio_data_alpgen_lead_jet_pt = new TH1F(tc02_5_ratio_data_alpgen_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_lead_jet_pt->SetMarkerStyle(8);
  // //h_ratio_data_alpgen_lead_jet_pt->SetMarkerColor(kRed);

  // TAxis* h_ratio_data_alpgen_lead_jet_pt_xaxis = h_ratio_data_alpgen_lead_jet_pt->GetXaxis();
  // TAxis* h_ratio_data_alpgen_lead_jet_pt_yaxis = h_ratio_data_alpgen_lead_jet_pt->GetYaxis();
  
  // h_ratio_data_alpgen_lead_jet_pt_xaxis->SetLabelSize(0.08);
  // h_ratio_data_alpgen_lead_jet_pt_yaxis->SetLabelSize(0.08);

  // h_ratio_data_alpgen_lead_jet_pt_xaxis->SetTitle("lead jet pt");
  // h_ratio_data_alpgen_lead_jet_pt_xaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_lead_jet_pt_yaxis->SetNdivisions(4,4,4);
  // h_ratio_data_alpgen_lead_jet_pt_yaxis->SetTitle("(data-MC)/MC");
  // h_ratio_data_alpgen_lead_jet_pt_yaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_lead_jet_pt_yaxis->SetTitleOffset(0.36);
  // h_ratio_data_alpgen_lead_jet_pt_yaxis->SetRangeUser(-1,1);

  // // data-sherpa(nom)/sherpa(nom)
  // string tc02_5_ratio_data_sherpa_lead_jet_pt_name = "tc02_5_ratio_data_sherpa_lead_jet_pt";
  // TH1F* h_ratio_data_sherpa_lead_jet_pt = new TH1F(tc02_5_ratio_data_sherpa_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_sherpa_lead_jet_pt->SetMarkerStyle(8);
  // h_ratio_data_sherpa_lead_jet_pt->SetMarkerColor(kRed);


  // // data-alpgen(iqopt3)/alpgen(iqopt3)
  // string tc02_5_ratio_data_alpgen_iqopt3_lead_jet_pt_name = "tc02_5_ratio_data_alpgen_iqopt3_lead_jet_pt";
  // TH1F* h_ratio_data_alpgen_iqopt3_lead_jet_pt = new TH1F(tc02_5_ratio_data_alpgen_iqopt3_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_iqopt3_lead_jet_pt->SetMarkerStyle(8);
  // h_ratio_data_alpgen_iqopt3_lead_jet_pt->SetMarkerColor(kGreen);

  // // data-alpgen(ptjmin10)/alpgen(ptjmin10)
  // string tc02_5_ratio_data_alpgen_ptjmin10_lead_jet_pt_name = "tc02_5_ratio_data_alpgen_ptjmin10_lead_jet_pt";
  // TH1F* h_ratio_data_alpgen_ptjmin10_lead_jet_pt = new TH1F(tc02_5_ratio_data_alpgen_ptjmin10_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_ptjmin10_lead_jet_pt->SetMarkerStyle(8);
  // h_ratio_data_alpgen_ptjmin10_lead_jet_pt->SetMarkerColor(kBlue);

  

  
  // // // alp-iqopt3/iqopt3
  // // string tc02_5_ratio_alpgen_iqopt3_lead_jet_pt_name = "tc02_5_ratio_alpgen_iqopt3_lead_jet_pt";
  // // TH1F* h_ratio_alpgen_iqopt3_lead_jet_pt = new TH1F(tc02_5_ratio_alpgen_iqopt3_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerStyle(8);
  // // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerColor(kGreen);

  
  // // // alp-ptjmin10/ptjmin10
  // // string tc02_5_ratio_alpgen_ptjmin10_lead_jet_pt_name = "tc02_5_ratio_alpgen_ptjmin10_lead_jet_pt";
  // // TH1F* h_ratio_alpgen_ptjmin10_lead_jet_pt = new TH1F(tc02_5_ratio_alpgen_ptjmin10_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerStyle(8);
  // // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerColor(kBlue);


  
  // double tc02_5_data_alpgen_ratio=0.;
  // double tc02_5_data_sherpa_ratio=0.;
  // double tc02_5_data_alpgen_iqopt3_ratio=0.;
  // double tc02_5_data_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc02_5_alpgen_nom_bin_n=h_alpgen_nom_muon_lead_jet_pt->GetBinContent(b);
  //   double tc02_5_alpgen_nom_bin_err=h_alpgen_nom_muon_lead_jet_pt->GetBinError(b);    

  //   double tc02_5_data_bin_n=h_data_muon_lead_jet_pt->GetBinContent(b);
  //   double tc02_5_data_bin_err=h_data_muon_lead_jet_pt->GetBinError(b);    

  //   double tc02_5_sherpa_nom_bin_n=h_sherpa_nom_muon_lead_jet_pt->GetBinContent(b);
  //   double tc02_5_sherpa_nom_bin_err=h_sherpa_nom_muon_lead_jet_pt->GetBinError(b);    

  //   double tc02_5_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_muon_lead_jet_pt->GetBinContent(b);
  //   double tc02_5_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_muon_lead_jet_pt->GetBinError(b);

  //   double tc02_5_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_muon_lead_jet_pt->GetBinContent(b);
  //   double tc02_5_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_muon_lead_jet_pt->GetBinError(b);



  //   if(tc02_5_data_bin_n && tc02_5_alpgen_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc02_5_abs_data_alpgen_err = sqrt(pow(tc02_5_data_bin_err,2.)+pow(tc02_5_alpgen_nom_bin_err,2.));
  //     double tc02_5_rel_data_alpgen_err = tc02_5_abs_data_alpgen_err/(tc02_5_data_bin_n-tc02_5_alpgen_nom_bin_n);
  //     double tc02_5_rel_alpgen_err = tc02_5_alpgen_nom_bin_err/tc02_5_alpgen_nom_bin_n;
      
  //     double tc02_5_rel_ratio_data_alpgen_lead_jet_pt_err = sqrt(pow(tc02_5_rel_data_alpgen_err,2.)+pow(tc02_5_rel_alpgen_err,2.));

  //     double tc02_5_data_alpgen_ratio = (tc02_5_data_bin_n-tc02_5_alpgen_nom_bin_n)/tc02_5_alpgen_nom_bin_n;

  //     double tc02_5_data_alpgen_ratio_err = fabs(tc02_5_rel_ratio_data_alpgen_lead_jet_pt_err*tc02_5_data_alpgen_ratio);

  //     h_ratio_data_alpgen_lead_jet_pt->SetBinContent(b,tc02_5_data_alpgen_ratio);
  //     h_ratio_data_alpgen_lead_jet_pt->SetBinError(b,tc02_5_data_alpgen_ratio_err);
  //   }
    

  //   if(tc02_5_data_bin_n && tc02_5_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc02_5_abs_data_sherpa_err = sqrt(pow(tc02_5_data_bin_err,2.)+pow(tc02_5_sherpa_nom_bin_err,2.));
  //     double tc02_5_rel_data_sherpa_err = tc02_5_abs_data_sherpa_err/(tc02_5_data_bin_n-tc02_5_sherpa_nom_bin_n);
  //     double tc02_5_rel_sherpa_err = tc02_5_sherpa_nom_bin_err/tc02_5_sherpa_nom_bin_n;
      
  //     double tc02_5_rel_ratio_data_sherpa_lead_jet_pt_err = sqrt(pow(tc02_5_rel_data_sherpa_err,2.)+pow(tc02_5_rel_sherpa_err,2.));

  //     double tc02_5_data_sherpa_ratio = (tc02_5_data_bin_n-tc02_5_sherpa_nom_bin_n)/tc02_5_sherpa_nom_bin_n;

  //     double tc02_5_data_sherpa_ratio_err = fabs(tc02_5_rel_ratio_data_sherpa_lead_jet_pt_err*tc02_5_data_sherpa_ratio);

  //     h_ratio_data_sherpa_lead_jet_pt->SetBinContent(b,tc02_5_data_sherpa_ratio);
  //     h_ratio_data_sherpa_lead_jet_pt->SetBinError(b,tc02_5_data_sherpa_ratio_err);
  //   }
    

  //   if(tc02_5_data_bin_n && tc02_5_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc02_5_abs_data_alpgen_iqopt3_err = sqrt(pow(tc02_5_data_bin_err,2.)+pow(tc02_5_alpgen_iqopt3_bin_err,2.));
  //     double tc02_5_rel_data_alpgen_iqopt3_err = tc02_5_abs_data_alpgen_iqopt3_err/(tc02_5_data_bin_n-tc02_5_alpgen_iqopt3_bin_n);
  //     double tc02_5_rel_alpgen_iqopt3_err = tc02_5_alpgen_iqopt3_bin_err/tc02_5_alpgen_iqopt3_bin_n;
      
  //     double tc02_5_rel_ratio_data_alpgen_iqopt3_lead_jet_pt_err = sqrt(pow(tc02_5_rel_data_alpgen_iqopt3_err,2.)+pow(tc02_5_rel_alpgen_iqopt3_err,2.));

  //     double tc02_5_data_alpgen_iqopt3_ratio = (tc02_5_data_bin_n-tc02_5_alpgen_iqopt3_bin_n)/tc02_5_alpgen_iqopt3_bin_n;

  //     double tc02_5_data_alpgen_iqopt3_ratio_err = fabs(tc02_5_rel_ratio_data_alpgen_iqopt3_lead_jet_pt_err*tc02_5_data_alpgen_iqopt3_ratio);

  //     h_ratio_data_alpgen_iqopt3_lead_jet_pt->SetBinContent(b,tc02_5_data_alpgen_iqopt3_ratio);
  //     h_ratio_data_alpgen_iqopt3_lead_jet_pt->SetBinError(b,tc02_5_data_alpgen_iqopt3_ratio_err);
  //   }
    
  //   if(tc02_5_data_bin_n && tc02_5_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc02_5_abs_data_alpgen_ptjmin10_err = sqrt(pow(tc02_5_data_bin_err,2.)+pow(tc02_5_alpgen_ptjmin10_bin_err,2.));
  //     double tc02_5_rel_data_alpgen_ptjmin10_err = tc02_5_abs_data_alpgen_ptjmin10_err/(tc02_5_data_bin_n-tc02_5_alpgen_ptjmin10_bin_n);
  //     double tc02_5_rel_alpgen_ptjmin10_err = tc02_5_alpgen_ptjmin10_bin_err/tc02_5_alpgen_ptjmin10_bin_n;
      
  //     double tc02_5_rel_ratio_data_alpgen_ptjmin10_lead_jet_pt_err = sqrt(pow(tc02_5_rel_data_alpgen_ptjmin10_err,2.)+pow(tc02_5_rel_alpgen_ptjmin10_err,2.));

  //     double tc02_5_data_alpgen_ptjmin10_ratio = (tc02_5_data_bin_n-tc02_5_alpgen_ptjmin10_bin_n)/tc02_5_alpgen_ptjmin10_bin_n;

  //     double tc02_5_data_alpgen_ptjmin10_ratio_err = fabs(tc02_5_rel_ratio_data_alpgen_ptjmin10_lead_jet_pt_err*tc02_5_data_alpgen_ptjmin10_ratio);

  //     h_ratio_data_alpgen_ptjmin10_lead_jet_pt->SetBinContent(b,tc02_5_data_alpgen_ptjmin10_ratio);
  //     h_ratio_data_alpgen_ptjmin10_lead_jet_pt->SetBinError(b,tc02_5_data_alpgen_ptjmin10_ratio_err);
  //   }
    
  // }



  // h_ratio_data_alpgen_lead_jet_pt->Draw("PE");
  // h_ratio_data_sherpa_lead_jet_pt->Draw("PE sames");
  // h_ratio_data_alpgen_iqopt3_lead_jet_pt->Draw("PE sames");
  // h_ratio_data_alpgen_ptjmin10_lead_jet_pt->Draw("PE sames");
  
  // //  h_ratio_alpgen_iqopt3_lead_jet_pt->Draw("PE sames");
  // //  h_ratio_alpgen_ptjmin10_lead_jet_pt->Draw("PE sames");
  
  // tc02_5->Update();

  // tc02_5->SaveAs("./plots/latest/data_muon_lead_jet_pt.png");
    
  // //NEXT

  //////////////////////////////////////////////////
  // tc03
  // jet_eta: tc03_sherpa/alpgen+wjrw
  ////////////////////////////////////////////////// 

  string tc03_title = "Jet Eta (elec)";
  string tc03_name = "tc03";
  TCanvas* tc03 = new TCanvas(tc03_name.c_str(),tc03_title.c_str(),0,0,1920,1200);
  tc03->cd();

  TPad* tc03_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  tc03_pad01->SetTopMargin(0.05);
  tc03_pad01->SetBottomMargin(0.31);
  tc03_pad01->Draw();

  TPad* tc03_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  tc03_pad02->SetBottomMargin(0.0005);
  //tc03_pad02->SetLogy();
  tc03_pad02->Draw();
  tc03_pad02->cd();

  // Plots
  
  TH1F* h_alpgen_nom_elec_jet_eta = (TH1F*) wjets_alpgen_file->Get("all/h_elec_purw_nom_jet_eta");
  TH1F* h_alpgen_iqopt3_elec_jet_eta = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_iqopt3_jet_eta");
  TH1F* h_alpgen_ptjmin10_elec_jet_eta = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_ptjmin10_jet_eta");
  TH1F* h_sherpa_nom_elec_jet_eta = (TH1F*) wjets_sherpa_file->Get("all/h_elec_purw_nom_jet_eta");

  //h_alpgen_nom_elec_jet_eta->SetLineWidth(2);
  h_alpgen_nom_elec_jet_eta->SetMarkerStyle(20);
  h_alpgen_nom_elec_jet_eta->SetMarkerSize(1.2);
  h_alpgen_nom_elec_jet_eta->SetTitle("");
  h_alpgen_nom_elec_jet_eta->Draw("PE");

  //h_alpgen_iqopt3_elec_jet_eta->SetLineColor(kGreen);
  h_alpgen_iqopt3_elec_jet_eta->SetMarkerStyle(22);
  h_alpgen_iqopt3_elec_jet_eta->SetMarkerSize(1.2);
  h_alpgen_iqopt3_elec_jet_eta->SetMarkerColor(kGreen);
  h_alpgen_iqopt3_elec_jet_eta->Draw("PE sames");

  //  h_alpgen_ptjmin10_elec_jet_eta->SetLineColor(kBlue);
  h_alpgen_ptjmin10_elec_jet_eta->SetMarkerStyle(22);
  h_alpgen_ptjmin10_elec_jet_eta->SetMarkerSize(1.2);
  h_alpgen_ptjmin10_elec_jet_eta->SetMarkerColor(kBlue);
  h_alpgen_ptjmin10_elec_jet_eta->Draw("PE sames");

  // h_sherpa_nom_elec_jet_eta->SetLineWidth(1.2);
  // h_sherpa_nom_elec_jet_eta->SetLineColor(kRed);
  h_sherpa_nom_elec_jet_eta->SetMarkerStyle(20);
  h_sherpa_nom_elec_jet_eta->SetMarkerSize(1.2);
  h_sherpa_nom_elec_jet_eta->SetMarkerColor(kRed);
  h_sherpa_nom_elec_jet_eta->Draw("PE sames");


  //Legend
  TLegend* lgnd_tc03 = new TLegend(0.68,0.72,0.83,0.85);
  lgnd_tc03->SetFillColor(0);
  lgnd_tc03->SetTextSize(0.03);
  lgnd_tc03->SetBorderSize(0);

  char lgnd_alpgen_nom_elec_jet_eta_name[20];
  sprintf(lgnd_alpgen_nom_elec_jet_eta_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_elec_jet_eta->Integral());
  lgnd_tc03->AddEntry(h_alpgen_nom_elec_jet_eta,lgnd_alpgen_nom_elec_jet_eta_name,"p");

  char lgnd_alpgen_iqopt3_elec_jet_eta_name[20];
  sprintf(lgnd_alpgen_iqopt3_elec_jet_eta_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_elec_jet_eta->Integral());
  lgnd_tc03->AddEntry(h_alpgen_iqopt3_elec_jet_eta,lgnd_alpgen_iqopt3_elec_jet_eta_name,"p");

  char lgnd_alpgen_ptjmin10_elec_jet_eta_name[20];
  sprintf(lgnd_alpgen_ptjmin10_elec_jet_eta_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_elec_jet_eta->Integral());
  lgnd_tc03->AddEntry(h_alpgen_ptjmin10_elec_jet_eta,lgnd_alpgen_ptjmin10_elec_jet_eta_name,"p");

  char lgnd_sherpa_nom_elec_jet_eta_name[20];
  sprintf(lgnd_sherpa_nom_elec_jet_eta_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_elec_jet_eta->Integral());
  lgnd_tc03->AddEntry(h_sherpa_nom_elec_jet_eta,lgnd_sherpa_nom_elec_jet_eta_name,"p");

  lgnd_tc03->Draw();
  
  //////////////////////////////////////////////////
  //Ratio
  ////////////////////////////////////////////////// 

  tc03_pad01->cd();
  tc03_pad01->SetGrid();

  int n_bins = ((TAxis*) h_alpgen_nom_elec_jet_eta->GetXaxis())->GetNbins();
  double x_min = ((TAxis*) h_alpgen_nom_elec_jet_eta->GetXaxis())->GetXmin();
  double x_max = ((TAxis*) h_alpgen_nom_elec_jet_eta->GetXaxis())->GetXmax();

  // alp-sherp/sherp
  string tc03_ratio_alpgen_sherpa_jet_eta_name = "tc03_ratio_alpgen_sherpa_jet_eta";
  TH1F* h_ratio_alpgen_sherpa_jet_eta = new TH1F(tc03_ratio_alpgen_sherpa_jet_eta_name.c_str(),"",n_bins,x_min,x_max);
  h_ratio_alpgen_sherpa_jet_eta->SetMarkerStyle(8);
  h_ratio_alpgen_sherpa_jet_eta->SetMarkerColor(kRed);

  TAxis* h_ratio_alpgen_sherpa_jet_eta_xaxis = h_ratio_alpgen_sherpa_jet_eta->GetXaxis();
  TAxis* h_ratio_alpgen_sherpa_jet_eta_yaxis = h_ratio_alpgen_sherpa_jet_eta->GetYaxis();
  
  h_ratio_alpgen_sherpa_jet_eta_xaxis->SetLabelSize(0.08);
  h_ratio_alpgen_sherpa_jet_eta_yaxis->SetLabelSize(0.08);

  h_ratio_alpgen_sherpa_jet_eta_xaxis->SetTitle("jet eta");
  h_ratio_alpgen_sherpa_jet_eta_xaxis->SetTitleSize(0.07);
  h_ratio_alpgen_sherpa_jet_eta_yaxis->SetNdivisions(4,4,4);
  h_ratio_alpgen_sherpa_jet_eta_yaxis->SetTitle("(alpgen-MC)/MC");
  h_ratio_alpgen_sherpa_jet_eta_yaxis->SetTitleSize(0.07);
  h_ratio_alpgen_sherpa_jet_eta_yaxis->SetTitleOffset(0.36);
  h_ratio_alpgen_sherpa_jet_eta_yaxis->SetRangeUser(-1,1);

  
  // alp-iqopt3/iqopt3
  string tc03_ratio_alpgen_iqopt3_jet_eta_name = "tc03_ratio_alpgen_iqopt3_jet_eta";
  TH1F* h_ratio_alpgen_iqopt3_jet_eta = new TH1F(tc03_ratio_alpgen_iqopt3_jet_eta_name.c_str(),"",n_bins,x_min,x_max);
  h_ratio_alpgen_iqopt3_jet_eta->SetMarkerStyle(8);
  h_ratio_alpgen_iqopt3_jet_eta->SetMarkerColor(kGreen);

  
  // alp-ptjmin10/ptjmin10
  string tc03_ratio_alpgen_ptjmin10_jet_eta_name = "tc03_ratio_alpgen_ptjmin10_jet_eta";
  TH1F* h_ratio_alpgen_ptjmin10_jet_eta = new TH1F(tc03_ratio_alpgen_ptjmin10_jet_eta_name.c_str(),"",n_bins,x_min,x_max);
  h_ratio_alpgen_ptjmin10_jet_eta->SetMarkerStyle(8);
  h_ratio_alpgen_ptjmin10_jet_eta->SetMarkerColor(kBlue);


  
  double tc03_alpgen_sherpa_ratio=0.;
  double tc03_alpgen_iqopt3_ratio=0.;
  double tc03_alpgen_ptjmin10_ratio=0.;
  
  for(int b=1;b<n_bins+1;b++){

    double tc03_alpgen_nom_bin_n=h_alpgen_nom_elec_jet_eta->GetBinContent(b);
    double tc03_alpgen_nom_bin_err=h_alpgen_nom_elec_jet_eta->GetBinError(b);    

    double tc03_sherpa_nom_bin_n=h_sherpa_nom_elec_jet_eta->GetBinContent(b);
    double tc03_sherpa_nom_bin_err=h_sherpa_nom_elec_jet_eta->GetBinError(b);    

    double tc03_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_elec_jet_eta->GetBinContent(b);
    double tc03_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_elec_jet_eta->GetBinError(b);

    double tc03_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_elec_jet_eta->GetBinContent(b);
    double tc03_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_elec_jet_eta->GetBinError(b);



    if(tc03_alpgen_nom_bin_n && tc03_sherpa_nom_bin_n) {

      // //Error calc (see histogrampainter for clarification)
      double tc03_abs_alpgen_sherpa_err = sqrt(pow(tc03_alpgen_nom_bin_err,2.)+pow(tc03_sherpa_nom_bin_err,2.));
      double tc03_rel_alpgen_sherpa_err = tc03_abs_alpgen_sherpa_err/(tc03_alpgen_nom_bin_n-tc03_sherpa_nom_bin_n);
      double tc03_rel_sherpa_err = tc03_sherpa_nom_bin_err/tc03_sherpa_nom_bin_n;
      
      double tc03_rel_ratio_alpgen_sherpa_jet_eta_err = sqrt(pow(tc03_rel_alpgen_sherpa_err,2.)+pow(tc03_rel_sherpa_err,2.));

      double tc03_alpgen_sherpa_ratio = (tc03_alpgen_nom_bin_n-tc03_sherpa_nom_bin_n)/tc03_sherpa_nom_bin_n;

      double tc03_alpgen_sherpa_ratio_err = fabs(tc03_rel_ratio_alpgen_sherpa_jet_eta_err*tc03_alpgen_sherpa_ratio);

      h_ratio_alpgen_sherpa_jet_eta->SetBinContent(b,tc03_alpgen_sherpa_ratio);
      h_ratio_alpgen_sherpa_jet_eta->SetBinError(b,tc03_alpgen_sherpa_ratio_err);
    }
    

    if(tc03_alpgen_nom_bin_n && tc03_alpgen_iqopt3_bin_n) {

      // //Error calc (see histogrampainter for clarification)
      double tc03_abs_alpgen_iqopt3_err = sqrt(pow(tc03_alpgen_nom_bin_err,2.)+pow(tc03_alpgen_iqopt3_bin_err,2.));
      double tc03_rel_alpgen_iqopt3_err = tc03_abs_alpgen_iqopt3_err/(tc03_alpgen_nom_bin_n-tc03_alpgen_iqopt3_bin_n);
      double tc03_rel_iqopt3_err = tc03_alpgen_iqopt3_bin_err/tc03_alpgen_iqopt3_bin_n;
      
      double tc03_rel_ratio_alpgen_iqopt3_jet_eta_err = sqrt(pow(tc03_rel_alpgen_iqopt3_err,2.)+pow(tc03_rel_iqopt3_err,2.));

      double tc03_alpgen_iqopt3_ratio = (tc03_alpgen_nom_bin_n-tc03_alpgen_iqopt3_bin_n)/tc03_alpgen_iqopt3_bin_n;

      double tc03_alpgen_iqopt3_ratio_err = fabs(tc03_rel_ratio_alpgen_iqopt3_jet_eta_err*tc03_alpgen_iqopt3_ratio);

      h_ratio_alpgen_iqopt3_jet_eta->SetBinContent(b,tc03_alpgen_iqopt3_ratio);
      h_ratio_alpgen_iqopt3_jet_eta->SetBinError(b,tc03_alpgen_iqopt3_ratio_err);
    }

    

    if(tc03_alpgen_nom_bin_n && tc03_alpgen_ptjmin10_bin_n) {

      // //Error calc (see histogrampainter for clarification)
      double tc03_abs_alpgen_ptjmin10_err = sqrt(pow(tc03_alpgen_nom_bin_err,2.)+pow(tc03_alpgen_ptjmin10_bin_err,2.));
      double tc03_rel_alpgen_ptjmin10_err = tc03_abs_alpgen_ptjmin10_err/(tc03_alpgen_nom_bin_n-tc03_alpgen_ptjmin10_bin_n);
      double tc03_rel_ptjmin10_err = tc03_alpgen_ptjmin10_bin_err/tc03_alpgen_ptjmin10_bin_n;
      
      double tc03_rel_ratio_alpgen_ptjmin10_jet_eta_err = sqrt(pow(tc03_rel_alpgen_ptjmin10_err,2.)+pow(tc03_rel_ptjmin10_err,2.));

      double tc03_alpgen_ptjmin10_ratio = (tc03_alpgen_nom_bin_n-tc03_alpgen_ptjmin10_bin_n)/tc03_alpgen_ptjmin10_bin_n;

      double tc03_alpgen_ptjmin10_ratio_err = fabs(tc03_rel_ratio_alpgen_ptjmin10_jet_eta_err*tc03_alpgen_ptjmin10_ratio);

      h_ratio_alpgen_ptjmin10_jet_eta->SetBinContent(b,tc03_alpgen_ptjmin10_ratio);
      h_ratio_alpgen_ptjmin10_jet_eta->SetBinError(b,tc03_alpgen_ptjmin10_ratio_err);
    }
    
  }


  h_ratio_alpgen_sherpa_jet_eta->Draw("PE");
  h_ratio_alpgen_iqopt3_jet_eta->Draw("PE sames");
  h_ratio_alpgen_ptjmin10_jet_eta->Draw("PE sames");
  
  tc03->Update();

  tc03->SaveAs("./plots/latest/elec_jet_eta.png");
  
  //NEXT
  
  //////////////////////////////////////////////////
  // tc03_5
  // jet_eta: sherpa/alpgen+wjrw
  //////////////////////////////////////////////////
  
  string tc03_5_title = "Jet Eta (elec) w/ Data";
  string tc03_5_name = "tc03_5";
  TCanvas* tc03_5 = new TCanvas(tc03_5_name.c_str(),tc03_5_title.c_str(),0,0,1920,1200);
  tc03_5->cd();

  TPad* tc03_5_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  tc03_5_pad01->SetTopMargin(0.05);
  tc03_5_pad01->SetBottomMargin(0.31);
  tc03_5_pad01->Draw();

  TPad* tc03_5_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  tc03_5_pad02->SetBottomMargin(0.0005);
  //tc03_5_pad02->SetLogy();
  tc03_5_pad02->Draw();
  tc03_5_pad02->cd();

  // Plots
  
  TH1F* h_alpgen_nom_elec_jet_eta = (TH1F*) wjets_alpgen_file->Get("all/h_elec_purw_nom_jet_eta");
  TH1F* h_alpgen_iqopt3_elec_jet_eta = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_iqopt3_jet_eta");
  TH1F* h_alpgen_ptjmin10_elec_jet_eta = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_ptjmin10_jet_eta");
  TH1F* h_sherpa_nom_elec_jet_eta = (TH1F*) wjets_sherpa_file->Get("all/h_elec_purw_nom_jet_eta");
  TH1F* h_data_elec_jet_eta = (TH1F*) data_file->Get("all/h_elec_purw_nom_jet_eta");

  TH1F* h_top_elec_jet_eta = (TH1F*) top_mcatnlo_file->Get("all/h_elec_purw_nom_jet_eta");
  TH1F* h_zjets_elec_jet_eta = (TH1F*) zjets_alpgen_file->Get("all/h_elec_purw_nom_jet_eta");
  TH1F* h_vv_elec_jet_eta = (TH1F*) vv_herwig_file->Get("all/h_elec_purw_nom_jet_eta");
  TH1F* h_qcd_elec_jet_eta = (TH1F*) qcd_file->Get("all/h_elec_purw_nom_jet_eta");
  
  h_data_elec_jet_eta->SetTitle("");
  h_data_elec_jet_eta->Draw();
  
  //Add Backgrounds
  h_alpgen_nom_elec_jet_eta->Add(h_top_elec_jet_eta);
  h_alpgen_nom_elec_jet_eta->Add(h_zjets_elec_jet_eta);
  h_alpgen_nom_elec_jet_eta->Add(h_vv_elec_jet_eta);
  h_alpgen_nom_elec_jet_eta->Add(h_qcd_elec_jet_eta);
  
  h_alpgen_nom_elec_jet_eta->SetMarkerStyle(20);
  h_alpgen_nom_elec_jet_eta->SetMarkerSize(1.2);
  h_alpgen_nom_elec_jet_eta->Draw("PE sames");

  //Add backgrounds
  h_alpgen_iqopt3_elec_jet_eta->Add(h_top_elec_jet_eta);
  h_alpgen_iqopt3_elec_jet_eta->Add(h_zjets_elec_jet_eta);
  h_alpgen_iqopt3_elec_jet_eta->Add(h_vv_elec_jet_eta);
  h_alpgen_iqopt3_elec_jet_eta->Add(h_qcd_elec_jet_eta);

  h_alpgen_iqopt3_elec_jet_eta->SetMarkerStyle(22);
  h_alpgen_iqopt3_elec_jet_eta->SetMarkerSize(1.2);
  h_alpgen_iqopt3_elec_jet_eta->SetMarkerColor(kGreen);
  h_alpgen_iqopt3_elec_jet_eta->Draw("PE sames");

  //Add Backgrounds
  h_alpgen_ptjmin10_elec_jet_eta->Add(h_top_elec_jet_eta);
  h_alpgen_ptjmin10_elec_jet_eta->Add(h_zjets_elec_jet_eta);
  h_alpgen_ptjmin10_elec_jet_eta->Add(h_vv_elec_jet_eta);
  h_alpgen_ptjmin10_elec_jet_eta->Add(h_qcd_elec_jet_eta);

  h_alpgen_ptjmin10_elec_jet_eta->SetMarkerStyle(22);
  h_alpgen_ptjmin10_elec_jet_eta->SetMarkerSize(1.2);
  h_alpgen_ptjmin10_elec_jet_eta->SetMarkerColor(kBlue);
  h_alpgen_ptjmin10_elec_jet_eta->Draw("PE sames");

  //Add Backgrounds
  h_sherpa_nom_elec_jet_eta->Add(h_top_elec_jet_eta);
  h_sherpa_nom_elec_jet_eta->Add(h_zjets_elec_jet_eta);
  h_sherpa_nom_elec_jet_eta->Add(h_vv_elec_jet_eta);
  h_sherpa_nom_elec_jet_eta->Add(h_qcd_elec_jet_eta);

  h_sherpa_nom_elec_jet_eta->SetMarkerStyle(20);
  h_sherpa_nom_elec_jet_eta->SetMarkerSize(1.2);
  h_sherpa_nom_elec_jet_eta->SetMarkerColor(kRed);
  h_sherpa_nom_elec_jet_eta->Draw("PE sames");




  //Legend
  TLegend* lgnd_tc03_5 = new TLegend(0.68,0.72,0.83,0.85);
  lgnd_tc03_5->SetFillColor(0);
  lgnd_tc03_5->SetTextSize(0.03);
  lgnd_tc03_5->SetBorderSize(0);


  char lgnd_data_elec_jet_eta_name[20];
  sprintf(lgnd_data_elec_jet_eta_name,"%s,  %.2f","DATA",h_data_elec_jet_eta->Integral());
  lgnd_tc03_5->AddEntry(h_data_elec_jet_eta,lgnd_data_elec_jet_eta_name,"f");

  char lgnd_alpgen_nom_elec_jet_eta_name[20];
  sprintf(lgnd_alpgen_nom_elec_jet_eta_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_elec_jet_eta->Integral());
  lgnd_tc03_5->AddEntry(h_alpgen_nom_elec_jet_eta,lgnd_alpgen_nom_elec_jet_eta_name,"p");

  char lgnd_alpgen_iqopt3_elec_jet_eta_name[20];
  sprintf(lgnd_alpgen_iqopt3_elec_jet_eta_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_elec_jet_eta->Integral());
  lgnd_tc03_5->AddEntry(h_alpgen_iqopt3_elec_jet_eta,lgnd_alpgen_iqopt3_elec_jet_eta_name,"p");

  char lgnd_alpgen_ptjmin10_elec_jet_eta_name[20];
  sprintf(lgnd_alpgen_ptjmin10_elec_jet_eta_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_elec_jet_eta->Integral());
  lgnd_tc03_5->AddEntry(h_alpgen_ptjmin10_elec_jet_eta,lgnd_alpgen_ptjmin10_elec_jet_eta_name,"p");

  char lgnd_sherpa_nom_elec_jet_eta_name[20];
  sprintf(lgnd_sherpa_nom_elec_jet_eta_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_elec_jet_eta->Integral());
  lgnd_tc03_5->AddEntry(h_sherpa_nom_elec_jet_eta,lgnd_sherpa_nom_elec_jet_eta_name,"p");

  lgnd_tc03_5->Draw();
  
  //////////////////////////////////////////////////
  //Ratio
  ////////////////////////////////////////////////// 

  tc03_5_pad01->cd();
  tc03_5_pad01->SetGrid();

  int n_bins = ((TAxis*) h_alpgen_nom_elec_jet_eta->GetXaxis())->GetNbins();
  double x_min = ((TAxis*) h_alpgen_nom_elec_jet_eta->GetXaxis())->GetXmin();
  double x_max = ((TAxis*) h_alpgen_nom_elec_jet_eta->GetXaxis())->GetXmax();

  // data-alpgen(nom)/alpgen(nom)
  string tc03_5_ratio_data_alpgen_jet_eta_name = "tc03_5_ratio_data_alpgen_jet_eta";
  TH1F* h_ratio_data_alpgen_jet_eta = new TH1F(tc03_5_ratio_data_alpgen_jet_eta_name.c_str(),"",n_bins,x_min,x_max);
  h_ratio_data_alpgen_jet_eta->SetMarkerStyle(8);
  //h_ratio_data_alpgen_jet_eta->SetMarkerColor(kRed);

  TAxis* h_ratio_data_alpgen_jet_eta_xaxis = h_ratio_data_alpgen_jet_eta->GetXaxis();
  TAxis* h_ratio_data_alpgen_jet_eta_yaxis = h_ratio_data_alpgen_jet_eta->GetYaxis();
  
  h_ratio_data_alpgen_jet_eta_xaxis->SetLabelSize(0.08);
  h_ratio_data_alpgen_jet_eta_yaxis->SetLabelSize(0.08);

  h_ratio_data_alpgen_jet_eta_xaxis->SetTitle("jet eta");
  h_ratio_data_alpgen_jet_eta_xaxis->SetTitleSize(0.07);
  h_ratio_data_alpgen_jet_eta_yaxis->SetNdivisions(4,4,4);
  h_ratio_data_alpgen_jet_eta_yaxis->SetTitle("(data-MC)/MC");
  h_ratio_data_alpgen_jet_eta_yaxis->SetTitleSize(0.07);
  h_ratio_data_alpgen_jet_eta_yaxis->SetTitleOffset(0.36);
  h_ratio_data_alpgen_jet_eta_yaxis->SetRangeUser(-1,1);

  // data-sherpa(nom)/sherpa(nom)
  string tc03_5_ratio_data_sherpa_jet_eta_name = "tc03_5_ratio_data_sherpa_jet_eta";
  TH1F* h_ratio_data_sherpa_jet_eta = new TH1F(tc03_5_ratio_data_sherpa_jet_eta_name.c_str(),"",n_bins,x_min,x_max);
  h_ratio_data_sherpa_jet_eta->SetMarkerStyle(8);
  h_ratio_data_sherpa_jet_eta->SetMarkerColor(kRed);


  // data-alpgen(iqopt3)/alpgen(iqopt3)
  string tc03_5_ratio_data_alpgen_iqopt3_jet_eta_name = "tc03_5_ratio_data_alpgen_iqopt3_jet_eta";
  TH1F* h_ratio_data_alpgen_iqopt3_jet_eta = new TH1F(tc03_5_ratio_data_alpgen_iqopt3_jet_eta_name.c_str(),"",n_bins,x_min,x_max);
  h_ratio_data_alpgen_iqopt3_jet_eta->SetMarkerStyle(8);
  h_ratio_data_alpgen_iqopt3_jet_eta->SetMarkerColor(kGreen);

  // data-alpgen(ptjmin10)/alpgen(ptjmin10)
  string tc03_5_ratio_data_alpgen_ptjmin10_jet_eta_name = "tc03_5_ratio_data_alpgen_ptjmin10_jet_eta";
  TH1F* h_ratio_data_alpgen_ptjmin10_jet_eta = new TH1F(tc03_5_ratio_data_alpgen_ptjmin10_jet_eta_name.c_str(),"",n_bins,x_min,x_max);
  h_ratio_data_alpgen_ptjmin10_jet_eta->SetMarkerStyle(8);
  h_ratio_data_alpgen_ptjmin10_jet_eta->SetMarkerColor(kBlue);

  

  
  // // alp-iqopt3/iqopt3
  // string tc03_5_ratio_alpgen_iqopt3_lead_jet_pt_name = "tc03_5_ratio_alpgen_iqopt3_lead_jet_pt";
  // TH1F* h_ratio_alpgen_iqopt3_lead_jet_pt = new TH1F(tc03_5_ratio_alpgen_iqopt3_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerStyle(8);
  // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerColor(kGreen);

  
  // // alp-ptjmin10/ptjmin10
  // string tc03_5_ratio_alpgen_ptjmin10_lead_jet_pt_name = "tc03_5_ratio_alpgen_ptjmin10_lead_jet_pt";
  // TH1F* h_ratio_alpgen_ptjmin10_lead_jet_pt = new TH1F(tc03_5_ratio_alpgen_ptjmin10_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerStyle(8);
  // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerColor(kBlue);


  
  double tc03_5_data_alpgen_ratio=0.;
  double tc03_5_data_sherpa_ratio=0.;
  double tc03_5_data_alpgen_iqopt3_ratio=0.;
  double tc03_5_data_alpgen_ptjmin10_ratio=0.;
  
  for(int b=1;b<n_bins+1;b++){

    double tc03_5_alpgen_nom_bin_n=h_alpgen_nom_elec_jet_eta->GetBinContent(b);
    double tc03_5_alpgen_nom_bin_err=h_alpgen_nom_elec_jet_eta->GetBinError(b);    

    double tc03_5_data_bin_n=h_data_elec_jet_eta->GetBinContent(b);
    double tc03_5_data_bin_err=h_data_elec_jet_eta->GetBinError(b);    

    double tc03_5_sherpa_nom_bin_n=h_sherpa_nom_elec_jet_eta->GetBinContent(b);
    double tc03_5_sherpa_nom_bin_err=h_sherpa_nom_elec_jet_eta->GetBinError(b);    

    double tc03_5_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_elec_jet_eta->GetBinContent(b);
    double tc03_5_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_elec_jet_eta->GetBinError(b);

    double tc03_5_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_elec_jet_eta->GetBinContent(b);
    double tc03_5_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_elec_jet_eta->GetBinError(b);



    if(tc03_5_data_bin_n && tc03_5_alpgen_nom_bin_n) {

      // //Error calc (see histogrampainter for clarification)
      double tc03_5_abs_data_alpgen_err = sqrt(pow(tc03_5_data_bin_err,2.)+pow(tc03_5_alpgen_nom_bin_err,2.));
      double tc03_5_rel_data_alpgen_err = tc03_5_abs_data_alpgen_err/(tc03_5_data_bin_n-tc03_5_alpgen_nom_bin_n);
      double tc03_5_rel_alpgen_err = tc03_5_alpgen_nom_bin_err/tc03_5_alpgen_nom_bin_n;
      
      double tc03_5_rel_ratio_data_alpgen_jet_eta_err = sqrt(pow(tc03_5_rel_data_alpgen_err,2.)+pow(tc03_5_rel_alpgen_err,2.));

      double tc03_5_data_alpgen_ratio = (tc03_5_data_bin_n-tc03_5_alpgen_nom_bin_n)/tc03_5_alpgen_nom_bin_n;

      double tc03_5_data_alpgen_ratio_err = fabs(tc03_5_rel_ratio_data_alpgen_jet_eta_err*tc03_5_data_alpgen_ratio);

      h_ratio_data_alpgen_jet_eta->SetBinContent(b,tc03_5_data_alpgen_ratio);
      h_ratio_data_alpgen_jet_eta->SetBinError(b,tc03_5_data_alpgen_ratio_err);
    }
    

    if(tc03_5_data_bin_n && tc03_5_sherpa_nom_bin_n) {

      // //Error calc (see histogrampainter for clarification)
      double tc03_5_abs_data_sherpa_err = sqrt(pow(tc03_5_data_bin_err,2.)+pow(tc03_5_sherpa_nom_bin_err,2.));
      double tc03_5_rel_data_sherpa_err = tc03_5_abs_data_sherpa_err/(tc03_5_data_bin_n-tc03_5_sherpa_nom_bin_n);
      double tc03_5_rel_sherpa_err = tc03_5_sherpa_nom_bin_err/tc03_5_sherpa_nom_bin_n;
      
      double tc03_5_rel_ratio_data_sherpa_jet_eta_err = sqrt(pow(tc03_5_rel_data_sherpa_err,2.)+pow(tc03_5_rel_sherpa_err,2.));

      double tc03_5_data_sherpa_ratio = (tc03_5_data_bin_n-tc03_5_sherpa_nom_bin_n)/tc03_5_sherpa_nom_bin_n;

      double tc03_5_data_sherpa_ratio_err = fabs(tc03_5_rel_ratio_data_sherpa_jet_eta_err*tc03_5_data_sherpa_ratio);

      h_ratio_data_sherpa_jet_eta->SetBinContent(b,tc03_5_data_sherpa_ratio);
      h_ratio_data_sherpa_jet_eta->SetBinError(b,tc03_5_data_sherpa_ratio_err);
    }
    

    if(tc03_5_data_bin_n && tc03_5_alpgen_iqopt3_bin_n) {

      // //Error calc (see histogrampainter for clarification)
      double tc03_5_abs_data_alpgen_iqopt3_err = sqrt(pow(tc03_5_data_bin_err,2.)+pow(tc03_5_alpgen_iqopt3_bin_err,2.));
      double tc03_5_rel_data_alpgen_iqopt3_err = tc03_5_abs_data_alpgen_iqopt3_err/(tc03_5_data_bin_n-tc03_5_alpgen_iqopt3_bin_n);
      double tc03_5_rel_alpgen_iqopt3_err = tc03_5_alpgen_iqopt3_bin_err/tc03_5_alpgen_iqopt3_bin_n;
      
      double tc03_5_rel_ratio_data_alpgen_iqopt3_jet_eta_err = sqrt(pow(tc03_5_rel_data_alpgen_iqopt3_err,2.)+pow(tc03_5_rel_alpgen_iqopt3_err,2.));

      double tc03_5_data_alpgen_iqopt3_ratio = (tc03_5_data_bin_n-tc03_5_alpgen_iqopt3_bin_n)/tc03_5_alpgen_iqopt3_bin_n;

      double tc03_5_data_alpgen_iqopt3_ratio_err = fabs(tc03_5_rel_ratio_data_alpgen_iqopt3_jet_eta_err*tc03_5_data_alpgen_iqopt3_ratio);

      h_ratio_data_alpgen_iqopt3_jet_eta->SetBinContent(b,tc03_5_data_alpgen_iqopt3_ratio);
      h_ratio_data_alpgen_iqopt3_jet_eta->SetBinError(b,tc03_5_data_alpgen_iqopt3_ratio_err);
    }
    
    if(tc03_5_data_bin_n && tc03_5_alpgen_ptjmin10_bin_n) {

      // //Error calc (see histogrampainter for clarification)
      double tc03_5_abs_data_alpgen_ptjmin10_err = sqrt(pow(tc03_5_data_bin_err,2.)+pow(tc03_5_alpgen_ptjmin10_bin_err,2.));
      double tc03_5_rel_data_alpgen_ptjmin10_err = tc03_5_abs_data_alpgen_ptjmin10_err/(tc03_5_data_bin_n-tc03_5_alpgen_ptjmin10_bin_n);
      double tc03_5_rel_alpgen_ptjmin10_err = tc03_5_alpgen_ptjmin10_bin_err/tc03_5_alpgen_ptjmin10_bin_n;
      
      double tc03_5_rel_ratio_data_alpgen_ptjmin10_jet_eta_err = sqrt(pow(tc03_5_rel_data_alpgen_ptjmin10_err,2.)+pow(tc03_5_rel_alpgen_ptjmin10_err,2.));

      double tc03_5_data_alpgen_ptjmin10_ratio = (tc03_5_data_bin_n-tc03_5_alpgen_ptjmin10_bin_n)/tc03_5_alpgen_ptjmin10_bin_n;

      double tc03_5_data_alpgen_ptjmin10_ratio_err = fabs(tc03_5_rel_ratio_data_alpgen_ptjmin10_jet_eta_err*tc03_5_data_alpgen_ptjmin10_ratio);

      h_ratio_data_alpgen_ptjmin10_jet_eta->SetBinContent(b,tc03_5_data_alpgen_ptjmin10_ratio);
      h_ratio_data_alpgen_ptjmin10_jet_eta->SetBinError(b,tc03_5_data_alpgen_ptjmin10_ratio_err);
    }
  }


  h_ratio_data_alpgen_jet_eta->Draw("PE");
  h_ratio_data_sherpa_jet_eta->Draw("PE sames");
  h_ratio_data_alpgen_iqopt3_jet_eta->Draw("PE sames");
  h_ratio_data_alpgen_ptjmin10_jet_eta->Draw("PE sames");
  
  //  h_ratio_alpgen_iqopt3_jet_eta->Draw("PE sames");
  //  h_ratio_alpgen_ptjmin10_jet_eta->Draw("PE sames");
  
  tc03_5->Update();
  tc03_5->SaveAs("./plots/latest/data_elec_jet_eta.png");

  //NEXT

  //////////////////////////////////////////////////
  // tc04
  // jet_eta: tc04_sherpa/alpgen+wjrw
  ////////////////////////////////////////////////// 

  string tc04_title = "Jet Eta (muon)";
  string tc04_name = "tc04";
  TCanvas* tc04 = new TCanvas(tc04_name.c_str(),tc04_title.c_str(),0,0,1920,1200);
  tc04->cd();

  TPad* tc04_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  tc04_pad01->SetTopMargin(0.05);
  tc04_pad01->SetBottomMargin(0.31);
  tc04_pad01->Draw();

  TPad* tc04_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  tc04_pad02->SetBottomMargin(0.0005);
  //tc04_pad02->SetLogy();
  tc04_pad02->Draw();
  tc04_pad02->cd();

  // Plots
  
  TH1F* h_alpgen_nom_muon_jet_eta = (TH1F*) wjets_alpgen_file->Get("all/h_muon_purw_nom_jet_eta");
  TH1F* h_alpgen_iqopt3_muon_jet_eta = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_iqopt3_jet_eta");
  TH1F* h_alpgen_ptjmin10_muon_jet_eta = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_ptjmin10_jet_eta");
  TH1F* h_sherpa_nom_muon_jet_eta = (TH1F*) wjets_sherpa_file->Get("all/h_muon_purw_nom_jet_eta");

  //h_alpgen_nom_muon_jet_eta->SetLineWidth(2);
  h_alpgen_nom_muon_jet_eta->SetMarkerStyle(20);
  h_alpgen_nom_muon_jet_eta->SetMarkerSize(1.2);
  h_alpgen_nom_muon_jet_eta->SetTitle("");
  h_alpgen_nom_muon_jet_eta->Draw("PE");

  //h_alpgen_iqopt3_muon_jet_eta->SetLineColor(kGreen);
  h_alpgen_iqopt3_muon_jet_eta->SetMarkerStyle(22);
  h_alpgen_iqopt3_muon_jet_eta->SetMarkerSize(1.2);
  h_alpgen_iqopt3_muon_jet_eta->SetMarkerColor(kGreen);
  h_alpgen_iqopt3_muon_jet_eta->Draw("PE sames");

  //  h_alpgen_ptjmin10_muon_jet_eta->SetLineColor(kBlue);
  h_alpgen_ptjmin10_muon_jet_eta->SetMarkerStyle(22);
  h_alpgen_ptjmin10_muon_jet_eta->SetMarkerSize(1.2);
  h_alpgen_ptjmin10_muon_jet_eta->SetMarkerColor(kBlue);
  h_alpgen_ptjmin10_muon_jet_eta->Draw("PE sames");

  // h_sherpa_nom_muon_jet_eta->SetLineWidth(1.2);
  // h_sherpa_nom_muon_jet_eta->SetLineColor(kRed);
  h_sherpa_nom_muon_jet_eta->SetMarkerStyle(20);
  h_sherpa_nom_muon_jet_eta->SetMarkerSize(1.2);
  h_sherpa_nom_muon_jet_eta->SetMarkerColor(kRed);
  h_sherpa_nom_muon_jet_eta->Draw("PE sames");


  //Legend
  TLegend* lgnd_tc04 = new TLegend(0.68,0.72,0.83,0.85);
  lgnd_tc04->SetFillColor(0);
  lgnd_tc04->SetTextSize(0.03);
  lgnd_tc04->SetBorderSize(0);

  char lgnd_alpgen_nom_muon_jet_eta_name[20];
  sprintf(lgnd_alpgen_nom_muon_jet_eta_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_muon_jet_eta->Integral());
  lgnd_tc04->AddEntry(h_alpgen_nom_muon_jet_eta,lgnd_alpgen_nom_muon_jet_eta_name,"p");

  char lgnd_alpgen_iqopt3_muon_jet_eta_name[20];
  sprintf(lgnd_alpgen_iqopt3_muon_jet_eta_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_muon_jet_eta->Integral());
  lgnd_tc04->AddEntry(h_alpgen_iqopt3_muon_jet_eta,lgnd_alpgen_iqopt3_muon_jet_eta_name,"p");

  char lgnd_alpgen_ptjmin10_muon_jet_eta_name[20];
  sprintf(lgnd_alpgen_ptjmin10_muon_jet_eta_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_muon_jet_eta->Integral());
  lgnd_tc04->AddEntry(h_alpgen_ptjmin10_muon_jet_eta,lgnd_alpgen_ptjmin10_muon_jet_eta_name,"p");

  char lgnd_sherpa_nom_muon_jet_eta_name[20];
  sprintf(lgnd_sherpa_nom_muon_jet_eta_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_muon_jet_eta->Integral());
  lgnd_tc04->AddEntry(h_sherpa_nom_muon_jet_eta,lgnd_sherpa_nom_muon_jet_eta_name,"p");

  lgnd_tc04->Draw();
  
  //////////////////////////////////////////////////
  //Ratio
  ////////////////////////////////////////////////// 

  tc04_pad01->cd();
  tc04_pad01->SetGrid();

  int n_bins = ((TAxis*) h_alpgen_nom_muon_jet_eta->GetXaxis())->GetNbins();
  double x_min = ((TAxis*) h_alpgen_nom_muon_jet_eta->GetXaxis())->GetXmin();
  double x_max = ((TAxis*) h_alpgen_nom_muon_jet_eta->GetXaxis())->GetXmax();

  // alp-sherp/sherp
  string tc04_ratio_alpgen_sherpa_jet_eta_name = "tc04_ratio_alpgen_sherpa_jet_eta";
  TH1F* h_ratio_alpgen_sherpa_jet_eta = new TH1F(tc04_ratio_alpgen_sherpa_jet_eta_name.c_str(),"",n_bins,x_min,x_max);
  h_ratio_alpgen_sherpa_jet_eta->SetMarkerStyle(8);
  h_ratio_alpgen_sherpa_jet_eta->SetMarkerColor(kRed);

  TAxis* h_ratio_alpgen_sherpa_jet_eta_xaxis = h_ratio_alpgen_sherpa_jet_eta->GetXaxis();
  TAxis* h_ratio_alpgen_sherpa_jet_eta_yaxis = h_ratio_alpgen_sherpa_jet_eta->GetYaxis();
  
  h_ratio_alpgen_sherpa_jet_eta_xaxis->SetLabelSize(0.08);
  h_ratio_alpgen_sherpa_jet_eta_yaxis->SetLabelSize(0.08);

  h_ratio_alpgen_sherpa_jet_eta_xaxis->SetTitle("jet eta");
  h_ratio_alpgen_sherpa_jet_eta_xaxis->SetTitleSize(0.07);
  h_ratio_alpgen_sherpa_jet_eta_yaxis->SetNdivisions(4,4,4);
  h_ratio_alpgen_sherpa_jet_eta_yaxis->SetTitle("(alpgen-MC)/MC");
  h_ratio_alpgen_sherpa_jet_eta_yaxis->SetTitleSize(0.07);
  h_ratio_alpgen_sherpa_jet_eta_yaxis->SetTitleOffset(0.36);
  h_ratio_alpgen_sherpa_jet_eta_yaxis->SetRangeUser(-1,1);

  
  // alp-iqopt3/iqopt3
  string tc04_ratio_alpgen_iqopt3_jet_eta_name = "tc04_ratio_alpgen_iqopt3_jet_eta";
  TH1F* h_ratio_alpgen_iqopt3_jet_eta = new TH1F(tc04_ratio_alpgen_iqopt3_jet_eta_name.c_str(),"",n_bins,x_min,x_max);
  h_ratio_alpgen_iqopt3_jet_eta->SetMarkerStyle(8);
  h_ratio_alpgen_iqopt3_jet_eta->SetMarkerColor(kGreen);

  
  // alp-ptjmin10/ptjmin10
  string tc04_ratio_alpgen_ptjmin10_jet_eta_name = "tc04_ratio_alpgen_ptjmin10_jet_eta";
  TH1F* h_ratio_alpgen_ptjmin10_jet_eta = new TH1F(tc04_ratio_alpgen_ptjmin10_jet_eta_name.c_str(),"",n_bins,x_min,x_max);
  h_ratio_alpgen_ptjmin10_jet_eta->SetMarkerStyle(8);
  h_ratio_alpgen_ptjmin10_jet_eta->SetMarkerColor(kBlue);


  
  double tc04_alpgen_sherpa_ratio=0.;
  double tc04_alpgen_iqopt3_ratio=0.;
  double tc04_alpgen_ptjmin10_ratio=0.;
  
  for(int b=1;b<n_bins+1;b++){

    double tc04_alpgen_nom_bin_n=h_alpgen_nom_muon_jet_eta->GetBinContent(b);
    double tc04_alpgen_nom_bin_err=h_alpgen_nom_muon_jet_eta->GetBinError(b);    

    double tc04_sherpa_nom_bin_n=h_sherpa_nom_muon_jet_eta->GetBinContent(b);
    double tc04_sherpa_nom_bin_err=h_sherpa_nom_muon_jet_eta->GetBinError(b);    

    double tc04_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_muon_jet_eta->GetBinContent(b);
    double tc04_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_muon_jet_eta->GetBinError(b);

    double tc04_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_muon_jet_eta->GetBinContent(b);
    double tc04_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_muon_jet_eta->GetBinError(b);



    if(tc04_alpgen_nom_bin_n && tc04_sherpa_nom_bin_n) {

      // //Error calc (see histogrampainter for clarification)
      double tc04_abs_alpgen_sherpa_err = sqrt(pow(tc04_alpgen_nom_bin_err,2.)+pow(tc04_sherpa_nom_bin_err,2.));
      double tc04_rel_alpgen_sherpa_err = tc04_abs_alpgen_sherpa_err/(tc04_alpgen_nom_bin_n-tc04_sherpa_nom_bin_n);
      double tc04_rel_sherpa_err = tc04_sherpa_nom_bin_err/tc04_sherpa_nom_bin_n;
      
      double tc04_rel_ratio_alpgen_sherpa_jet_eta_err = sqrt(pow(tc04_rel_alpgen_sherpa_err,2.)+pow(tc04_rel_sherpa_err,2.));

      double tc04_alpgen_sherpa_ratio = (tc04_alpgen_nom_bin_n-tc04_sherpa_nom_bin_n)/tc04_sherpa_nom_bin_n;

      double tc04_alpgen_sherpa_ratio_err = fabs(tc04_rel_ratio_alpgen_sherpa_jet_eta_err*tc04_alpgen_sherpa_ratio);

      h_ratio_alpgen_sherpa_jet_eta->SetBinContent(b,tc04_alpgen_sherpa_ratio);
      h_ratio_alpgen_sherpa_jet_eta->SetBinError(b,tc04_alpgen_sherpa_ratio_err);
    }
    

    if(tc04_alpgen_nom_bin_n && tc04_alpgen_iqopt3_bin_n) {

      // //Error calc (see histogrampainter for clarification)
      double tc04_abs_alpgen_iqopt3_err = sqrt(pow(tc04_alpgen_nom_bin_err,2.)+pow(tc04_alpgen_iqopt3_bin_err,2.));
      double tc04_rel_alpgen_iqopt3_err = tc04_abs_alpgen_iqopt3_err/(tc04_alpgen_nom_bin_n-tc04_alpgen_iqopt3_bin_n);
      double tc04_rel_iqopt3_err = tc04_alpgen_iqopt3_bin_err/tc04_alpgen_iqopt3_bin_n;
      
      double tc04_rel_ratio_alpgen_iqopt3_jet_eta_err = sqrt(pow(tc04_rel_alpgen_iqopt3_err,2.)+pow(tc04_rel_iqopt3_err,2.));

      double tc04_alpgen_iqopt3_ratio = (tc04_alpgen_nom_bin_n-tc04_alpgen_iqopt3_bin_n)/tc04_alpgen_iqopt3_bin_n;

      double tc04_alpgen_iqopt3_ratio_err = fabs(tc04_rel_ratio_alpgen_iqopt3_jet_eta_err*tc04_alpgen_iqopt3_ratio);

      h_ratio_alpgen_iqopt3_jet_eta->SetBinContent(b,tc04_alpgen_iqopt3_ratio);
      h_ratio_alpgen_iqopt3_jet_eta->SetBinError(b,tc04_alpgen_iqopt3_ratio_err);
    }

    

    if(tc04_alpgen_nom_bin_n && tc04_alpgen_ptjmin10_bin_n) {

      // //Error calc (see histogrampainter for clarification)
      double tc04_abs_alpgen_ptjmin10_err = sqrt(pow(tc04_alpgen_nom_bin_err,2.)+pow(tc04_alpgen_ptjmin10_bin_err,2.));
      double tc04_rel_alpgen_ptjmin10_err = tc04_abs_alpgen_ptjmin10_err/(tc04_alpgen_nom_bin_n-tc04_alpgen_ptjmin10_bin_n);
      double tc04_rel_ptjmin10_err = tc04_alpgen_ptjmin10_bin_err/tc04_alpgen_ptjmin10_bin_n;
      
      double tc04_rel_ratio_alpgen_ptjmin10_jet_eta_err = sqrt(pow(tc04_rel_alpgen_ptjmin10_err,2.)+pow(tc04_rel_ptjmin10_err,2.));

      double tc04_alpgen_ptjmin10_ratio = (tc04_alpgen_nom_bin_n-tc04_alpgen_ptjmin10_bin_n)/tc04_alpgen_ptjmin10_bin_n;

      double tc04_alpgen_ptjmin10_ratio_err = fabs(tc04_rel_ratio_alpgen_ptjmin10_jet_eta_err*tc04_alpgen_ptjmin10_ratio);

      h_ratio_alpgen_ptjmin10_jet_eta->SetBinContent(b,tc04_alpgen_ptjmin10_ratio);
      h_ratio_alpgen_ptjmin10_jet_eta->SetBinError(b,tc04_alpgen_ptjmin10_ratio_err);
    }
    
  }


  h_ratio_alpgen_sherpa_jet_eta->Draw("PE");
  h_ratio_alpgen_iqopt3_jet_eta->Draw("PE sames");
  h_ratio_alpgen_ptjmin10_jet_eta->Draw("PE sames");
  
  tc04->Update();

  tc04->SaveAs("./plots/latest/muon_jet_eta.png");
  
  //NEXT
  
  //////////////////////////////////////////////////
  // tc04_5
  // jet_eta: sherpa/alpgen+wjrw
  //////////////////////////////////////////////////
  
  string tc04_5_title = "Jet Eta (muon) w/ Data";
  string tc04_5_name = "tc04_5";
  TCanvas* tc04_5 = new TCanvas(tc04_5_name.c_str(),tc04_5_title.c_str(),0,0,1920,1200);
  tc04_5->cd();

  TPad* tc04_5_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  tc04_5_pad01->SetTopMargin(0.05);
  tc04_5_pad01->SetBottomMargin(0.31);
  tc04_5_pad01->Draw();

  TPad* tc04_5_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  tc04_5_pad02->SetBottomMargin(0.0005);
  //tc04_5_pad02->SetLogy();
  tc04_5_pad02->Draw();
  tc04_5_pad02->cd();

  // Plots
  
  TH1F* h_alpgen_nom_muon_jet_eta = (TH1F*) wjets_alpgen_file->Get("all/h_muon_purw_nom_jet_eta");
  TH1F* h_alpgen_iqopt3_muon_jet_eta = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_iqopt3_jet_eta");
  TH1F* h_alpgen_ptjmin10_muon_jet_eta = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_ptjmin10_jet_eta");
  TH1F* h_sherpa_nom_muon_jet_eta = (TH1F*) wjets_sherpa_file->Get("all/h_muon_purw_nom_jet_eta");
  TH1F* h_data_muon_jet_eta = (TH1F*) data_file->Get("all/h_muon_purw_nom_jet_eta");

  TH1F* h_top_muon_jet_eta = (TH1F*) top_mcatnlo_file->Get("all/h_muon_purw_nom_jet_eta");
  TH1F* h_zjets_muon_jet_eta = (TH1F*) zjets_alpgen_file->Get("all/h_muon_purw_nom_jet_eta");
  TH1F* h_vv_muon_jet_eta = (TH1F*) vv_herwig_file->Get("all/h_muon_purw_nom_jet_eta");
  TH1F* h_qcd_muon_jet_eta = (TH1F*) qcd_file->Get("all/h_muon_purw_nom_jet_eta");
  
  h_data_muon_jet_eta->SetTitle("");
  h_data_muon_jet_eta->Draw();
  
  //Add Backgrounds
  h_alpgen_nom_muon_jet_eta->Add(h_top_muon_jet_eta);
  h_alpgen_nom_muon_jet_eta->Add(h_zjets_muon_jet_eta);
  h_alpgen_nom_muon_jet_eta->Add(h_vv_muon_jet_eta);
  h_alpgen_nom_muon_jet_eta->Add(h_qcd_muon_jet_eta);
  
  h_alpgen_nom_muon_jet_eta->SetMarkerStyle(20);
  h_alpgen_nom_muon_jet_eta->SetMarkerSize(1.2);
  h_alpgen_nom_muon_jet_eta->Draw("PE sames");

  //Add backgrounds
  h_alpgen_iqopt3_muon_jet_eta->Add(h_top_muon_jet_eta);
  h_alpgen_iqopt3_muon_jet_eta->Add(h_zjets_muon_jet_eta);
  h_alpgen_iqopt3_muon_jet_eta->Add(h_vv_muon_jet_eta);
  h_alpgen_iqopt3_muon_jet_eta->Add(h_qcd_muon_jet_eta);

  h_alpgen_iqopt3_muon_jet_eta->SetMarkerStyle(22);
  h_alpgen_iqopt3_muon_jet_eta->SetMarkerSize(1.2);
  h_alpgen_iqopt3_muon_jet_eta->SetMarkerColor(kGreen);
  h_alpgen_iqopt3_muon_jet_eta->Draw("PE sames");

  //Add Backgrounds
  h_alpgen_ptjmin10_muon_jet_eta->Add(h_top_muon_jet_eta);
  h_alpgen_ptjmin10_muon_jet_eta->Add(h_zjets_muon_jet_eta);
  h_alpgen_ptjmin10_muon_jet_eta->Add(h_vv_muon_jet_eta);
  h_alpgen_ptjmin10_muon_jet_eta->Add(h_qcd_muon_jet_eta);

  h_alpgen_ptjmin10_muon_jet_eta->SetMarkerStyle(22);
  h_alpgen_ptjmin10_muon_jet_eta->SetMarkerSize(1.2);
  h_alpgen_ptjmin10_muon_jet_eta->SetMarkerColor(kBlue);
  h_alpgen_ptjmin10_muon_jet_eta->Draw("PE sames");

  //Add Backgrounds
  h_sherpa_nom_muon_jet_eta->Add(h_top_muon_jet_eta);
  h_sherpa_nom_muon_jet_eta->Add(h_zjets_muon_jet_eta);
  h_sherpa_nom_muon_jet_eta->Add(h_vv_muon_jet_eta);
  h_sherpa_nom_muon_jet_eta->Add(h_qcd_muon_jet_eta);

  h_sherpa_nom_muon_jet_eta->SetMarkerStyle(20);
  h_sherpa_nom_muon_jet_eta->SetMarkerSize(1.2);
  h_sherpa_nom_muon_jet_eta->SetMarkerColor(kRed);
  h_sherpa_nom_muon_jet_eta->Draw("PE sames");




  //Legend
  TLegend* lgnd_tc04_5 = new TLegend(0.68,0.72,0.83,0.85);
  lgnd_tc04_5->SetFillColor(0);
  lgnd_tc04_5->SetTextSize(0.03);
  lgnd_tc04_5->SetBorderSize(0);

  char lgnd_data_muon_jet_eta_name[20];
  sprintf(lgnd_data_muon_jet_eta_name,"%s,  %.2f","DATA",h_data_muon_jet_eta->Integral());
  lgnd_tc04_5->AddEntry(h_data_muon_jet_eta,lgnd_data_muon_jet_eta_name,"f");

  char lgnd_alpgen_nom_muon_jet_eta_name[20];
  sprintf(lgnd_alpgen_nom_muon_jet_eta_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_muon_jet_eta->Integral());
  lgnd_tc04_5->AddEntry(h_alpgen_nom_muon_jet_eta,lgnd_alpgen_nom_muon_jet_eta_name,"p");

  char lgnd_alpgen_iqopt3_muon_jet_eta_name[20];
  sprintf(lgnd_alpgen_iqopt3_muon_jet_eta_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_muon_jet_eta->Integral());
  lgnd_tc04_5->AddEntry(h_alpgen_iqopt3_muon_jet_eta,lgnd_alpgen_iqopt3_muon_jet_eta_name,"p");

  char lgnd_alpgen_ptjmin10_muon_jet_eta_name[20];
  sprintf(lgnd_alpgen_ptjmin10_muon_jet_eta_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_muon_jet_eta->Integral());
  lgnd_tc04_5->AddEntry(h_alpgen_ptjmin10_muon_jet_eta,lgnd_alpgen_ptjmin10_muon_jet_eta_name,"p");

  char lgnd_sherpa_nom_muon_jet_eta_name[20];
  sprintf(lgnd_sherpa_nom_muon_jet_eta_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_muon_jet_eta->Integral());
  lgnd_tc04_5->AddEntry(h_sherpa_nom_muon_jet_eta,lgnd_sherpa_nom_muon_jet_eta_name,"p");

  lgnd_tc04_5->Draw();
  
  //////////////////////////////////////////////////
  //Ratio
  ////////////////////////////////////////////////// 

  tc04_5_pad01->cd();
  tc04_5_pad01->SetGrid();

  int n_bins = ((TAxis*) h_alpgen_nom_muon_jet_eta->GetXaxis())->GetNbins();
  double x_min = ((TAxis*) h_alpgen_nom_muon_jet_eta->GetXaxis())->GetXmin();
  double x_max = ((TAxis*) h_alpgen_nom_muon_jet_eta->GetXaxis())->GetXmax();

  // data-alpgen(nom)/alpgen(nom)
  string tc04_5_ratio_data_alpgen_jet_eta_name = "tc04_5_ratio_data_alpgen_jet_eta";
  TH1F* h_ratio_data_alpgen_jet_eta = new TH1F(tc04_5_ratio_data_alpgen_jet_eta_name.c_str(),"",n_bins,x_min,x_max);
  h_ratio_data_alpgen_jet_eta->SetMarkerStyle(8);
  //h_ratio_data_alpgen_jet_eta->SetMarkerColor(kRed);

  TAxis* h_ratio_data_alpgen_jet_eta_xaxis = h_ratio_data_alpgen_jet_eta->GetXaxis();
  TAxis* h_ratio_data_alpgen_jet_eta_yaxis = h_ratio_data_alpgen_jet_eta->GetYaxis();
  
  h_ratio_data_alpgen_jet_eta_xaxis->SetLabelSize(0.08);
  h_ratio_data_alpgen_jet_eta_yaxis->SetLabelSize(0.08);

  h_ratio_data_alpgen_jet_eta_xaxis->SetTitle("jet eta");
  h_ratio_data_alpgen_jet_eta_xaxis->SetTitleSize(0.07);
  h_ratio_data_alpgen_jet_eta_yaxis->SetNdivisions(4,4,4);
  h_ratio_data_alpgen_jet_eta_yaxis->SetTitle("(data-MC)/MC");
  h_ratio_data_alpgen_jet_eta_yaxis->SetTitleSize(0.07);
  h_ratio_data_alpgen_jet_eta_yaxis->SetTitleOffset(0.36);
  h_ratio_data_alpgen_jet_eta_yaxis->SetRangeUser(-1,1);

  // data-sherpa(nom)/sherpa(nom)
  string tc04_5_ratio_data_sherpa_jet_eta_name = "tc04_5_ratio_data_sherpa_jet_eta";
  TH1F* h_ratio_data_sherpa_jet_eta = new TH1F(tc04_5_ratio_data_sherpa_jet_eta_name.c_str(),"",n_bins,x_min,x_max);
  h_ratio_data_sherpa_jet_eta->SetMarkerStyle(8);
  h_ratio_data_sherpa_jet_eta->SetMarkerColor(kRed);


  // data-alpgen(iqopt3)/alpgen(iqopt3)
  string tc04_5_ratio_data_alpgen_iqopt3_jet_eta_name = "tc04_5_ratio_data_alpgen_iqopt3_jet_eta";
  TH1F* h_ratio_data_alpgen_iqopt3_jet_eta = new TH1F(tc04_5_ratio_data_alpgen_iqopt3_jet_eta_name.c_str(),"",n_bins,x_min,x_max);
  h_ratio_data_alpgen_iqopt3_jet_eta->SetMarkerStyle(8);
  h_ratio_data_alpgen_iqopt3_jet_eta->SetMarkerColor(kGreen);

  // data-alpgen(ptjmin10)/alpgen(ptjmin10)
  string tc04_5_ratio_data_alpgen_ptjmin10_jet_eta_name = "tc04_5_ratio_data_alpgen_ptjmin10_jet_eta";
  TH1F* h_ratio_data_alpgen_ptjmin10_jet_eta = new TH1F(tc04_5_ratio_data_alpgen_ptjmin10_jet_eta_name.c_str(),"",n_bins,x_min,x_max);
  h_ratio_data_alpgen_ptjmin10_jet_eta->SetMarkerStyle(8);
  h_ratio_data_alpgen_ptjmin10_jet_eta->SetMarkerColor(kBlue);

  

  
  // // alp-iqopt3/iqopt3
  // string tc04_5_ratio_alpgen_iqopt3_lead_jet_pt_name = "tc04_5_ratio_alpgen_iqopt3_lead_jet_pt";
  // TH1F* h_ratio_alpgen_iqopt3_lead_jet_pt = new TH1F(tc04_5_ratio_alpgen_iqopt3_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerStyle(8);
  // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerColor(kGreen);

  
  // // alp-ptjmin10/ptjmin10
  // string tc04_5_ratio_alpgen_ptjmin10_lead_jet_pt_name = "tc04_5_ratio_alpgen_ptjmin10_lead_jet_pt";
  // TH1F* h_ratio_alpgen_ptjmin10_lead_jet_pt = new TH1F(tc04_5_ratio_alpgen_ptjmin10_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerStyle(8);
  // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerColor(kBlue);


  
  double tc04_5_data_alpgen_ratio=0.;
  double tc04_5_data_sherpa_ratio=0.;
  double tc04_5_data_alpgen_iqopt3_ratio=0.;
  double tc04_5_data_alpgen_ptjmin10_ratio=0.;
  
  for(int b=1;b<n_bins+1;b++){

    double tc04_5_alpgen_nom_bin_n=h_alpgen_nom_muon_jet_eta->GetBinContent(b);
    double tc04_5_alpgen_nom_bin_err=h_alpgen_nom_muon_jet_eta->GetBinError(b);    

    double tc04_5_data_bin_n=h_data_muon_jet_eta->GetBinContent(b);
    double tc04_5_data_bin_err=h_data_muon_jet_eta->GetBinError(b);    

    double tc04_5_sherpa_nom_bin_n=h_sherpa_nom_muon_jet_eta->GetBinContent(b);
    double tc04_5_sherpa_nom_bin_err=h_sherpa_nom_muon_jet_eta->GetBinError(b);    

    double tc04_5_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_muon_jet_eta->GetBinContent(b);
    double tc04_5_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_muon_jet_eta->GetBinError(b);

    double tc04_5_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_muon_jet_eta->GetBinContent(b);
    double tc04_5_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_muon_jet_eta->GetBinError(b);



    if(tc04_5_data_bin_n && tc04_5_alpgen_nom_bin_n) {

      // //Error calc (see histogrampainter for clarification)
      double tc04_5_abs_data_alpgen_err = sqrt(pow(tc04_5_data_bin_err,2.)+pow(tc04_5_alpgen_nom_bin_err,2.));
      double tc04_5_rel_data_alpgen_err = tc04_5_abs_data_alpgen_err/(tc04_5_data_bin_n-tc04_5_alpgen_nom_bin_n);
      double tc04_5_rel_alpgen_err = tc04_5_alpgen_nom_bin_err/tc04_5_alpgen_nom_bin_n;
      
      double tc04_5_rel_ratio_data_alpgen_jet_eta_err = sqrt(pow(tc04_5_rel_data_alpgen_err,2.)+pow(tc04_5_rel_alpgen_err,2.));

      double tc04_5_data_alpgen_ratio = (tc04_5_data_bin_n-tc04_5_alpgen_nom_bin_n)/tc04_5_alpgen_nom_bin_n;

      double tc04_5_data_alpgen_ratio_err = fabs(tc04_5_rel_ratio_data_alpgen_jet_eta_err*tc04_5_data_alpgen_ratio);

      h_ratio_data_alpgen_jet_eta->SetBinContent(b,tc04_5_data_alpgen_ratio);
      h_ratio_data_alpgen_jet_eta->SetBinError(b,tc04_5_data_alpgen_ratio_err);
    }
    

    if(tc04_5_data_bin_n && tc04_5_sherpa_nom_bin_n) {

      // //Error calc (see histogrampainter for clarification)
      double tc04_5_abs_data_sherpa_err = sqrt(pow(tc04_5_data_bin_err,2.)+pow(tc04_5_sherpa_nom_bin_err,2.));
      double tc04_5_rel_data_sherpa_err = tc04_5_abs_data_sherpa_err/(tc04_5_data_bin_n-tc04_5_sherpa_nom_bin_n);
      double tc04_5_rel_sherpa_err = tc04_5_sherpa_nom_bin_err/tc04_5_sherpa_nom_bin_n;
      
      double tc04_5_rel_ratio_data_sherpa_jet_eta_err = sqrt(pow(tc04_5_rel_data_sherpa_err,2.)+pow(tc04_5_rel_sherpa_err,2.));

      double tc04_5_data_sherpa_ratio = (tc04_5_data_bin_n-tc04_5_sherpa_nom_bin_n)/tc04_5_sherpa_nom_bin_n;

      double tc04_5_data_sherpa_ratio_err = fabs(tc04_5_rel_ratio_data_sherpa_jet_eta_err*tc04_5_data_sherpa_ratio);

      h_ratio_data_sherpa_jet_eta->SetBinContent(b,tc04_5_data_sherpa_ratio);
      h_ratio_data_sherpa_jet_eta->SetBinError(b,tc04_5_data_sherpa_ratio_err);
    }
    

    if(tc04_5_data_bin_n && tc04_5_alpgen_iqopt3_bin_n) {

      // //Error calc (see histogrampainter for clarification)
      double tc04_5_abs_data_alpgen_iqopt3_err = sqrt(pow(tc04_5_data_bin_err,2.)+pow(tc04_5_alpgen_iqopt3_bin_err,2.));
      double tc04_5_rel_data_alpgen_iqopt3_err = tc04_5_abs_data_alpgen_iqopt3_err/(tc04_5_data_bin_n-tc04_5_alpgen_iqopt3_bin_n);
      double tc04_5_rel_alpgen_iqopt3_err = tc04_5_alpgen_iqopt3_bin_err/tc04_5_alpgen_iqopt3_bin_n;
      
      double tc04_5_rel_ratio_data_alpgen_iqopt3_jet_eta_err = sqrt(pow(tc04_5_rel_data_alpgen_iqopt3_err,2.)+pow(tc04_5_rel_alpgen_iqopt3_err,2.));

      double tc04_5_data_alpgen_iqopt3_ratio = (tc04_5_data_bin_n-tc04_5_alpgen_iqopt3_bin_n)/tc04_5_alpgen_iqopt3_bin_n;

      double tc04_5_data_alpgen_iqopt3_ratio_err = fabs(tc04_5_rel_ratio_data_alpgen_iqopt3_jet_eta_err*tc04_5_data_alpgen_iqopt3_ratio);

      h_ratio_data_alpgen_iqopt3_jet_eta->SetBinContent(b,tc04_5_data_alpgen_iqopt3_ratio);
      h_ratio_data_alpgen_iqopt3_jet_eta->SetBinError(b,tc04_5_data_alpgen_iqopt3_ratio_err);
    }
    
    if(tc04_5_data_bin_n && tc04_5_alpgen_ptjmin10_bin_n) {

      // //Error calc (see histogrampainter for clarification)
      double tc04_5_abs_data_alpgen_ptjmin10_err = sqrt(pow(tc04_5_data_bin_err,2.)+pow(tc04_5_alpgen_ptjmin10_bin_err,2.));
      double tc04_5_rel_data_alpgen_ptjmin10_err = tc04_5_abs_data_alpgen_ptjmin10_err/(tc04_5_data_bin_n-tc04_5_alpgen_ptjmin10_bin_n);
      double tc04_5_rel_alpgen_ptjmin10_err = tc04_5_alpgen_ptjmin10_bin_err/tc04_5_alpgen_ptjmin10_bin_n;
      
      double tc04_5_rel_ratio_data_alpgen_ptjmin10_jet_eta_err = sqrt(pow(tc04_5_rel_data_alpgen_ptjmin10_err,2.)+pow(tc04_5_rel_alpgen_ptjmin10_err,2.));

      double tc04_5_data_alpgen_ptjmin10_ratio = (tc04_5_data_bin_n-tc04_5_alpgen_ptjmin10_bin_n)/tc04_5_alpgen_ptjmin10_bin_n;

      double tc04_5_data_alpgen_ptjmin10_ratio_err = fabs(tc04_5_rel_ratio_data_alpgen_ptjmin10_jet_eta_err*tc04_5_data_alpgen_ptjmin10_ratio);

      h_ratio_data_alpgen_ptjmin10_jet_eta->SetBinContent(b,tc04_5_data_alpgen_ptjmin10_ratio);
      h_ratio_data_alpgen_ptjmin10_jet_eta->SetBinError(b,tc04_5_data_alpgen_ptjmin10_ratio_err);
    }
  }


  h_ratio_data_alpgen_jet_eta->Draw("PE");
  h_ratio_data_sherpa_jet_eta->Draw("PE sames");
  h_ratio_data_alpgen_iqopt3_jet_eta->Draw("PE sames");
  h_ratio_data_alpgen_ptjmin10_jet_eta->Draw("PE sames");
  
  //  h_ratio_alpgen_iqopt3_jet_eta->Draw("PE sames");
  //  h_ratio_alpgen_ptjmin10_jet_eta->Draw("PE sames");
  
  tc04_5->Update();
  tc04_5->SaveAs("./plots/latest/data_muon_jet_eta.png");

  // //NEXT
  
  // ////////////////////////////////////////////////// 
  // // tc05
  // // elec_lep_met_pt: tc05_sherpa/alpgen+wjrw
  // ////////////////////////////////////////////////// 

  // string tc05_title = "Pt(elec+MET) (elec)";
  // string tc05_name = "tc05";
  // TCanvas* tc05 = new TCanvas(tc05_name.c_str(),tc05_title.c_str(),0,0,1920,1200);
  // tc05->cd();

  // TPad* tc05_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc05_pad01->SetTopMargin(0.05);
  // tc05_pad01->SetBottomMargin(0.31);
  // tc05_pad01->Draw();

  // TPad* tc05_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc05_pad02->SetBottomMargin(0.0005);
  // tc05_pad02->SetLogy();
  // tc05_pad02->Draw();
  // tc05_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_elec_lep_met_pt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_purw_nom_lep_met_pt");
  // TH1F* h_alpgen_iqopt3_elec_lep_met_pt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_iqopt3_lep_met_pt");
  // TH1F* h_alpgen_ptjmin10_elec_lep_met_pt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_ptjmin10_lep_met_pt");
  // TH1F* h_sherpa_nom_elec_lep_met_pt = (TH1F*) wjets_sherpa_file->Get("all/h_elec_purw_nom_lep_met_pt");

  // //h_alpgen_nom_elec_lep_met_pt->SetLineWidth(2);
  // h_alpgen_nom_elec_lep_met_pt->SetMarkerStyle(20);
  // h_alpgen_nom_elec_lep_met_pt->SetMarkerSize(1.2);
  // h_alpgen_nom_elec_lep_met_pt->SetTitle("");
  // h_alpgen_nom_elec_lep_met_pt->Draw("PE");

  // //h_alpgen_iqopt3_elec_lep_met_pt->SetLineColor(kGreen);
  // h_alpgen_iqopt3_elec_lep_met_pt->SetMarkerStyle(22);
  // h_alpgen_iqopt3_elec_lep_met_pt->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_elec_lep_met_pt->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_elec_lep_met_pt->Draw("PE sames");

  // //  h_alpgen_ptjmin10_elec_lep_met_pt->SetLineColor(kBlue);
  // h_alpgen_ptjmin10_elec_lep_met_pt->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_elec_lep_met_pt->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_elec_lep_met_pt->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_elec_lep_met_pt->Draw("PE sames");

  // // h_sherpa_nom_elec_lep_met_pt->SetLineWidth(1.2);
  // // h_sherpa_nom_elec_lep_met_pt->SetLineColor(kRed);
  // h_sherpa_nom_elec_lep_met_pt->SetMarkerStyle(20);
  // h_sherpa_nom_elec_lep_met_pt->SetMarkerSize(1.2);
  // h_sherpa_nom_elec_lep_met_pt->SetMarkerColor(kRed);
  // h_sherpa_nom_elec_lep_met_pt->Draw("PE sames");


  // //Legend
  // TLegend* lgnd_tc05 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc05->SetFillColor(0);
  // lgnd_tc05->SetTextSize(0.03);
  // lgnd_tc05->SetBorderSize(0);

  // char lgnd_alpgen_nom_elec_lep_met_pt_name[20];
  // sprintf(lgnd_alpgen_nom_elec_lep_met_pt_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_elec_lep_met_pt->Integral());
  // lgnd_tc05->AddEntry(h_alpgen_nom_elec_lep_met_pt,lgnd_alpgen_nom_elec_lep_met_pt_name,"p");

  // char lgnd_alpgen_iqopt3_elec_lep_met_pt_name[20];
  // sprintf(lgnd_alpgen_iqopt3_elec_lep_met_pt_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_elec_lep_met_pt->Integral());
  // lgnd_tc05->AddEntry(h_alpgen_iqopt3_elec_lep_met_pt,lgnd_alpgen_iqopt3_elec_lep_met_pt_name,"p");

  // char lgnd_alpgen_ptjmin10_elec_lep_met_pt_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_elec_lep_met_pt_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_elec_lep_met_pt->Integral());
  // lgnd_tc05->AddEntry(h_alpgen_ptjmin10_elec_lep_met_pt,lgnd_alpgen_ptjmin10_elec_lep_met_pt_name,"p");

  // char lgnd_sherpa_nom_elec_lep_met_pt_name[20];
  // sprintf(lgnd_sherpa_nom_elec_lep_met_pt_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_elec_lep_met_pt->Integral());
  // lgnd_tc05->AddEntry(h_sherpa_nom_elec_lep_met_pt,lgnd_sherpa_nom_elec_lep_met_pt_name,"p");

  // lgnd_tc05->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc05_pad01->cd();
  // tc05_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_elec_lep_met_pt->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_elec_lep_met_pt->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_elec_lep_met_pt->GetXaxis())->GetXmax();

  // // alp-sherp/sherp
  // string tc05_ratio_alpgen_sherpa_lep_met_pt_name = "tc05_ratio_alpgen_sherpa_lep_met_pt";
  // TH1F* h_ratio_alpgen_sherpa_lep_met_pt = new TH1F(tc05_ratio_alpgen_sherpa_lep_met_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_sherpa_lep_met_pt->SetMarkerStyle(8);
  // h_ratio_alpgen_sherpa_lep_met_pt->SetMarkerColor(kRed);

  // TAxis* h_ratio_alpgen_sherpa_lep_met_pt_xaxis = h_ratio_alpgen_sherpa_lep_met_pt->GetXaxis();
  // TAxis* h_ratio_alpgen_sherpa_lep_met_pt_yaxis = h_ratio_alpgen_sherpa_lep_met_pt->GetYaxis();
  
  // h_ratio_alpgen_sherpa_lep_met_pt_xaxis->SetLabelSize(0.08);
  // h_ratio_alpgen_sherpa_lep_met_pt_yaxis->SetLabelSize(0.08);

  // h_ratio_alpgen_sherpa_lep_met_pt_xaxis->SetTitle("Pt(elec+MET)");
  // h_ratio_alpgen_sherpa_lep_met_pt_xaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_lep_met_pt_yaxis->SetNdivisions(4,4,4);
  // h_ratio_alpgen_sherpa_lep_met_pt_yaxis->SetTitle("(alpgen-MC)/MC");
  // h_ratio_alpgen_sherpa_lep_met_pt_yaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_lep_met_pt_yaxis->SetTitleOffset(0.36);
  // h_ratio_alpgen_sherpa_lep_met_pt_yaxis->SetRangeUser(-1,1);

  
  // // alp-iqopt3/iqopt3
  // string tc05_ratio_alpgen_iqopt3_lep_met_pt_name = "tc05_ratio_alpgen_iqopt3_lep_met_pt";
  // TH1F* h_ratio_alpgen_iqopt3_lep_met_pt = new TH1F(tc05_ratio_alpgen_iqopt3_lep_met_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_iqopt3_lep_met_pt->SetMarkerStyle(8);
  // h_ratio_alpgen_iqopt3_lep_met_pt->SetMarkerColor(kGreen);

  
  // // alp-ptjmin10/ptjmin10
  // string tc05_ratio_alpgen_ptjmin10_lep_met_pt_name = "tc05_ratio_alpgen_ptjmin10_lep_met_pt";
  // TH1F* h_ratio_alpgen_ptjmin10_lep_met_pt = new TH1F(tc05_ratio_alpgen_ptjmin10_lep_met_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_ptjmin10_lep_met_pt->SetMarkerStyle(8);
  // h_ratio_alpgen_ptjmin10_lep_met_pt->SetMarkerColor(kBlue);


  
  // double tc05_alpgen_sherpa_ratio=0.;
  // double tc05_alpgen_iqopt3_ratio=0.;
  // double tc05_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc05_alpgen_nom_bin_n=h_alpgen_nom_elec_lep_met_pt->GetBinContent(b);
  //   double tc05_alpgen_nom_bin_err=h_alpgen_nom_elec_lep_met_pt->GetBinError(b);    

  //   double tc05_sherpa_nom_bin_n=h_sherpa_nom_elec_lep_met_pt->GetBinContent(b);
  //   double tc05_sherpa_nom_bin_err=h_sherpa_nom_elec_lep_met_pt->GetBinError(b);    

  //   double tc05_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_elec_lep_met_pt->GetBinContent(b);
  //   double tc05_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_elec_lep_met_pt->GetBinError(b);

  //   double tc05_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_elec_lep_met_pt->GetBinContent(b);
  //   double tc05_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_elec_lep_met_pt->GetBinError(b);



  //   if(tc05_alpgen_nom_bin_n && tc05_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc05_abs_alpgen_sherpa_err = sqrt(pow(tc05_alpgen_nom_bin_err,2.)+pow(tc05_sherpa_nom_bin_err,2.));
  //     double tc05_rel_alpgen_sherpa_err = tc05_abs_alpgen_sherpa_err/(tc05_alpgen_nom_bin_n-tc05_sherpa_nom_bin_n);
  //     double tc05_rel_sherpa_err = tc05_sherpa_nom_bin_err/tc05_sherpa_nom_bin_n;
      
  //     double tc05_rel_ratio_alpgen_sherpa_lep_met_pt_err = sqrt(pow(tc05_rel_alpgen_sherpa_err,2.)+pow(tc05_rel_sherpa_err,2.));

  //     double tc05_alpgen_sherpa_ratio = (tc05_alpgen_nom_bin_n-tc05_sherpa_nom_bin_n)/tc05_sherpa_nom_bin_n;

  //     double tc05_alpgen_sherpa_ratio_err = fabs(tc05_rel_ratio_alpgen_sherpa_lep_met_pt_err*tc05_alpgen_sherpa_ratio);

  //     h_ratio_alpgen_sherpa_lep_met_pt->SetBinContent(b,tc05_alpgen_sherpa_ratio);
  //     h_ratio_alpgen_sherpa_lep_met_pt->SetBinError(b,tc05_alpgen_sherpa_ratio_err);
  //   }
    

  //   if(tc05_alpgen_nom_bin_n && tc05_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc05_abs_alpgen_iqopt3_err = sqrt(pow(tc05_alpgen_nom_bin_err,2.)+pow(tc05_alpgen_iqopt3_bin_err,2.));
  //     double tc05_rel_alpgen_iqopt3_err = tc05_abs_alpgen_iqopt3_err/(tc05_alpgen_nom_bin_n-tc05_alpgen_iqopt3_bin_n);
  //     double tc05_rel_iqopt3_err = tc05_alpgen_iqopt3_bin_err/tc05_alpgen_iqopt3_bin_n;
      
  //     double tc05_rel_ratio_alpgen_iqopt3_lep_met_pt_err = sqrt(pow(tc05_rel_alpgen_iqopt3_err,2.)+pow(tc05_rel_iqopt3_err,2.));

  //     double tc05_alpgen_iqopt3_ratio = (tc05_alpgen_nom_bin_n-tc05_alpgen_iqopt3_bin_n)/tc05_alpgen_iqopt3_bin_n;

  //     double tc05_alpgen_iqopt3_ratio_err = fabs(tc05_rel_ratio_alpgen_iqopt3_lep_met_pt_err*tc05_alpgen_iqopt3_ratio);

  //     h_ratio_alpgen_iqopt3_lep_met_pt->SetBinContent(b,tc05_alpgen_iqopt3_ratio);
  //     h_ratio_alpgen_iqopt3_lep_met_pt->SetBinError(b,tc05_alpgen_iqopt3_ratio_err);
  //   }

    

  //   if(tc05_alpgen_nom_bin_n && tc05_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc05_abs_alpgen_ptjmin10_err = sqrt(pow(tc05_alpgen_nom_bin_err,2.)+pow(tc05_alpgen_ptjmin10_bin_err,2.));
  //     double tc05_rel_alpgen_ptjmin10_err = tc05_abs_alpgen_ptjmin10_err/(tc05_alpgen_nom_bin_n-tc05_alpgen_ptjmin10_bin_n);
  //     double tc05_rel_ptjmin10_err = tc05_alpgen_ptjmin10_bin_err/tc05_alpgen_ptjmin10_bin_n;
      
  //     double tc05_rel_ratio_alpgen_ptjmin10_lep_met_pt_err = sqrt(pow(tc05_rel_alpgen_ptjmin10_err,2.)+pow(tc05_rel_ptjmin10_err,2.));

  //     double tc05_alpgen_ptjmin10_ratio = (tc05_alpgen_nom_bin_n-tc05_alpgen_ptjmin10_bin_n)/tc05_alpgen_ptjmin10_bin_n;

  //     double tc05_alpgen_ptjmin10_ratio_err = fabs(tc05_rel_ratio_alpgen_ptjmin10_lep_met_pt_err*tc05_alpgen_ptjmin10_ratio);

  //     h_ratio_alpgen_ptjmin10_lep_met_pt->SetBinContent(b,tc05_alpgen_ptjmin10_ratio);
  //     h_ratio_alpgen_ptjmin10_lep_met_pt->SetBinError(b,tc05_alpgen_ptjmin10_ratio_err);
  //   }
    
  // }


  // h_ratio_alpgen_sherpa_lep_met_pt->Draw("PE");
  // h_ratio_alpgen_iqopt3_lep_met_pt->Draw("PE sames");
  // h_ratio_alpgen_ptjmin10_lep_met_pt->Draw("PE sames");
  
  // tc05->Update();

  // tc05->SaveAs("./plots/latest/elec_lep_met_pt.png");
  
  // //NEXT
  
  // //////////////////////////////////////////////////
  // // tc05_5
  // // data_elec_lep_met_pt: sherpa/alpgen+wjrw
  // //////////////////////////////////////////////////
  
  // string tc05_5_title = "Pt(elec+MET) (elec) w/ Data";
  // string tc05_5_name = "tc05_5";
  // TCanvas* tc05_5 = new TCanvas(tc05_5_name.c_str(),tc05_5_title.c_str(),0,0,1920,1200);
  // tc05_5->cd();

  // TPad* tc05_5_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc05_5_pad01->SetTopMargin(0.05);
  // tc05_5_pad01->SetBottomMargin(0.31);
  // tc05_5_pad01->Draw();

  // TPad* tc05_5_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc05_5_pad02->SetBottomMargin(0.0005);
  // tc05_5_pad02->SetLogy();
  // tc05_5_pad02->Draw();
  // tc05_5_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_elec_lep_met_pt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_purw_nom_lep_met_pt");
  // TH1F* h_alpgen_iqopt3_elec_lep_met_pt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_iqopt3_lep_met_pt");
  // TH1F* h_alpgen_ptjmin10_elec_lep_met_pt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_ptjmin10_lep_met_pt");
  // TH1F* h_sherpa_nom_elec_lep_met_pt = (TH1F*) wjets_sherpa_file->Get("all/h_elec_purw_nom_lep_met_pt");
  // TH1F* h_data_elec_lep_met_pt = (TH1F*) data_file->Get("all/h_elec_purw_nom_lep_met_pt");

  // TH1F* h_top_elec_lep_met_pt = (TH1F*) top_mcatnlo_file->Get("all/h_elec_purw_nom_lep_met_pt");
  // TH1F* h_zjets_elec_lep_met_pt = (TH1F*) zjets_alpgen_file->Get("all/h_elec_purw_nom_lep_met_pt");
  // TH1F* h_vv_elec_lep_met_pt = (TH1F*) vv_herwig_file->Get("all/h_elec_purw_nom_lep_met_pt");
  // TH1F* h_qcd_elec_lep_met_pt = (TH1F*) qcd_file->Get("all/h_elec_purw_nom_lep_met_pt");
  
  // h_data_elec_lep_met_pt->SetTitle("");
  // h_data_elec_lep_met_pt->Draw();
  
  // //Add Backgrounds
  // h_alpgen_nom_elec_lep_met_pt->Add(h_top_elec_lep_met_pt);
  // h_alpgen_nom_elec_lep_met_pt->Add(h_zjets_elec_lep_met_pt);
  // h_alpgen_nom_elec_lep_met_pt->Add(h_vv_elec_lep_met_pt);
  // h_alpgen_nom_elec_lep_met_pt->Add(h_qcd_elec_lep_met_pt);
  
  // h_alpgen_nom_elec_lep_met_pt->SetMarkerStyle(20);
  // h_alpgen_nom_elec_lep_met_pt->SetMarkerSize(1.2);
  // h_alpgen_nom_elec_lep_met_pt->Draw("PE sames");

  // //Add backgrounds
  // h_alpgen_iqopt3_elec_lep_met_pt->Add(h_top_elec_lep_met_pt);
  // h_alpgen_iqopt3_elec_lep_met_pt->Add(h_zjets_elec_lep_met_pt);
  // h_alpgen_iqopt3_elec_lep_met_pt->Add(h_vv_elec_lep_met_pt);
  // h_alpgen_iqopt3_elec_lep_met_pt->Add(h_qcd_elec_lep_met_pt);

  // h_alpgen_iqopt3_elec_lep_met_pt->SetMarkerStyle(22);
  // h_alpgen_iqopt3_elec_lep_met_pt->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_elec_lep_met_pt->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_elec_lep_met_pt->Draw("PE sames");

  // //Add Backgrounds
  // h_alpgen_ptjmin10_elec_lep_met_pt->Add(h_top_elec_lep_met_pt);
  // h_alpgen_ptjmin10_elec_lep_met_pt->Add(h_zjets_elec_lep_met_pt);
  // h_alpgen_ptjmin10_elec_lep_met_pt->Add(h_vv_elec_lep_met_pt);
  // h_alpgen_ptjmin10_elec_lep_met_pt->Add(h_qcd_elec_lep_met_pt);

  // h_alpgen_ptjmin10_elec_lep_met_pt->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_elec_lep_met_pt->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_elec_lep_met_pt->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_elec_lep_met_pt->Draw("PE sames");

  // //Add Backgrounds
  // h_sherpa_nom_elec_lep_met_pt->Add(h_top_elec_lep_met_pt);
  // h_sherpa_nom_elec_lep_met_pt->Add(h_zjets_elec_lep_met_pt);
  // h_sherpa_nom_elec_lep_met_pt->Add(h_vv_elec_lep_met_pt);
  // h_sherpa_nom_elec_lep_met_pt->Add(h_qcd_elec_lep_met_pt);

  // h_sherpa_nom_elec_lep_met_pt->SetMarkerStyle(20);
  // h_sherpa_nom_elec_lep_met_pt->SetMarkerSize(1.2);
  // h_sherpa_nom_elec_lep_met_pt->SetMarkerColor(kRed);
  // h_sherpa_nom_elec_lep_met_pt->Draw("PE sames");




  // //Legend
  // TLegend* lgnd_tc05_5 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc05_5->SetFillColor(0);
  // lgnd_tc05_5->SetTextSize(0.03);
  // lgnd_tc05_5->SetBorderSize(0);

  // char lgnd_data_elec_lep_met_pt_name[20];
  // sprintf(lgnd_data_elec_lep_met_pt_name,"%s,  %.2f","DATA",h_data_elec_lep_met_pt->Integral());
  // lgnd_tc05_5->AddEntry(h_data_elec_lep_met_pt,lgnd_data_elec_lep_met_pt_name,"f");

  // char lgnd_alpgen_nom_elec_lep_met_pt_name[20];
  // sprintf(lgnd_alpgen_nom_elec_lep_met_pt_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_elec_lep_met_pt->Integral());
  // lgnd_tc05_5->AddEntry(h_alpgen_nom_elec_lep_met_pt,lgnd_alpgen_nom_elec_lep_met_pt_name,"p");

  // char lgnd_alpgen_iqopt3_elec_lep_met_pt_name[20];
  // sprintf(lgnd_alpgen_iqopt3_elec_lep_met_pt_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_elec_lep_met_pt->Integral());
  // lgnd_tc05_5->AddEntry(h_alpgen_iqopt3_elec_lep_met_pt,lgnd_alpgen_iqopt3_elec_lep_met_pt_name,"p");

  // char lgnd_alpgen_ptjmin10_elec_lep_met_pt_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_elec_lep_met_pt_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_elec_lep_met_pt->Integral());
  // lgnd_tc05_5->AddEntry(h_alpgen_ptjmin10_elec_lep_met_pt,lgnd_alpgen_ptjmin10_elec_lep_met_pt_name,"p");

  // char lgnd_sherpa_nom_elec_lep_met_pt_name[20];
  // sprintf(lgnd_sherpa_nom_elec_lep_met_pt_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_elec_lep_met_pt->Integral());
  // lgnd_tc05_5->AddEntry(h_sherpa_nom_elec_lep_met_pt,lgnd_sherpa_nom_elec_lep_met_pt_name,"p");

  // lgnd_tc05_5->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc05_5_pad01->cd();
  // tc05_5_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_elec_lep_met_pt->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_elec_lep_met_pt->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_elec_lep_met_pt->GetXaxis())->GetXmax();

  // // data-alpgen(nom)/alpgen(nom)
  // string tc05_5_ratio_data_alpgen_lep_met_pt_name = "tc05_5_ratio_data_alpgen_lep_met_pt";
  // TH1F* h_ratio_data_alpgen_lep_met_pt = new TH1F(tc05_5_ratio_data_alpgen_lep_met_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_lep_met_pt->SetMarkerStyle(8);
  // //h_ratio_data_alpgen_lep_met_pt->SetMarkerColor(kRed);

  // TAxis* h_ratio_data_alpgen_lep_met_pt_xaxis = h_ratio_data_alpgen_lep_met_pt->GetXaxis();
  // TAxis* h_ratio_data_alpgen_lep_met_pt_yaxis = h_ratio_data_alpgen_lep_met_pt->GetYaxis();
  
  // h_ratio_data_alpgen_lep_met_pt_xaxis->SetLabelSize(0.08);
  // h_ratio_data_alpgen_lep_met_pt_yaxis->SetLabelSize(0.08);

  // h_ratio_data_alpgen_lep_met_pt_xaxis->SetTitle("Pt(elec+MET)");
  // h_ratio_data_alpgen_lep_met_pt_xaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_lep_met_pt_yaxis->SetNdivisions(4,4,4);
  // h_ratio_data_alpgen_lep_met_pt_yaxis->SetTitle("(data-MC)/MC");
  // h_ratio_data_alpgen_lep_met_pt_yaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_lep_met_pt_yaxis->SetTitleOffset(0.36);
  // h_ratio_data_alpgen_lep_met_pt_yaxis->SetRangeUser(-1,1);

  // // data-sherpa(nom)/sherpa(nom)
  // string tc05_5_ratio_data_sherpa_lep_met_pt_name = "tc05_5_ratio_data_sherpa_lep_met_pt";
  // TH1F* h_ratio_data_sherpa_lep_met_pt = new TH1F(tc05_5_ratio_data_sherpa_lep_met_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_sherpa_lep_met_pt->SetMarkerStyle(8);
  // h_ratio_data_sherpa_lep_met_pt->SetMarkerColor(kRed);


  // // data-alpgen(iqopt3)/alpgen(iqopt3)
  // string tc05_5_ratio_data_alpgen_iqopt3_lep_met_pt_name = "tc05_5_ratio_data_alpgen_iqopt3_lep_met_pt";
  // TH1F* h_ratio_data_alpgen_iqopt3_lep_met_pt = new TH1F(tc05_5_ratio_data_alpgen_iqopt3_lep_met_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_iqopt3_lep_met_pt->SetMarkerStyle(8);
  // h_ratio_data_alpgen_iqopt3_lep_met_pt->SetMarkerColor(kGreen);

  // // data-alpgen(ptjmin10)/alpgen(ptjmin10)
  // string tc05_5_ratio_data_alpgen_ptjmin10_lep_met_pt_name = "tc05_5_ratio_data_alpgen_ptjmin10_lep_met_pt";
  // TH1F* h_ratio_data_alpgen_ptjmin10_lep_met_pt = new TH1F(tc05_5_ratio_data_alpgen_ptjmin10_lep_met_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_ptjmin10_lep_met_pt->SetMarkerStyle(8);
  // h_ratio_data_alpgen_ptjmin10_lep_met_pt->SetMarkerColor(kBlue);

  

  
  // // // alp-iqopt3/iqopt3
  // // string tc05_5_ratio_alpgen_iqopt3_lead_jet_pt_name = "tc05_5_ratio_alpgen_iqopt3_lead_jet_pt";
  // // TH1F* h_ratio_alpgen_iqopt3_lead_jet_pt = new TH1F(tc05_5_ratio_alpgen_iqopt3_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerStyle(8);
  // // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerColor(kGreen);

  
  // // // alp-ptjmin10/ptjmin10
  // // string tc05_5_ratio_alpgen_ptjmin10_lead_jet_pt_name = "tc05_5_ratio_alpgen_ptjmin10_lead_jet_pt";
  // // TH1F* h_ratio_alpgen_ptjmin10_lead_jet_pt = new TH1F(tc05_5_ratio_alpgen_ptjmin10_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerStyle(8);
  // // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerColor(kBlue);


  
  // double tc05_5_data_alpgen_ratio=0.;
  // double tc05_5_data_sherpa_ratio=0.;
  // double tc05_5_data_alpgen_iqopt3_ratio=0.;
  // double tc05_5_data_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc05_5_alpgen_nom_bin_n=h_alpgen_nom_elec_lep_met_pt->GetBinContent(b);
  //   double tc05_5_alpgen_nom_bin_err=h_alpgen_nom_elec_lep_met_pt->GetBinError(b);    

  //   double tc05_5_data_bin_n=h_data_elec_lep_met_pt->GetBinContent(b);
  //   double tc05_5_data_bin_err=h_data_elec_lep_met_pt->GetBinError(b);    

  //   double tc05_5_sherpa_nom_bin_n=h_sherpa_nom_elec_lep_met_pt->GetBinContent(b);
  //   double tc05_5_sherpa_nom_bin_err=h_sherpa_nom_elec_lep_met_pt->GetBinError(b);    

  //   double tc05_5_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_elec_lep_met_pt->GetBinContent(b);
  //   double tc05_5_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_elec_lep_met_pt->GetBinError(b);

  //   double tc05_5_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_elec_lep_met_pt->GetBinContent(b);
  //   double tc05_5_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_elec_lep_met_pt->GetBinError(b);



  //   if(tc05_5_data_bin_n && tc05_5_alpgen_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc05_5_abs_data_alpgen_err = sqrt(pow(tc05_5_data_bin_err,2.)+pow(tc05_5_alpgen_nom_bin_err,2.));
  //     double tc05_5_rel_data_alpgen_err = tc05_5_abs_data_alpgen_err/(tc05_5_data_bin_n-tc05_5_alpgen_nom_bin_n);
  //     double tc05_5_rel_alpgen_err = tc05_5_alpgen_nom_bin_err/tc05_5_alpgen_nom_bin_n;
      
  //     double tc05_5_rel_ratio_data_alpgen_lep_met_pt_err = sqrt(pow(tc05_5_rel_data_alpgen_err,2.)+pow(tc05_5_rel_alpgen_err,2.));

  //     double tc05_5_data_alpgen_ratio = (tc05_5_data_bin_n-tc05_5_alpgen_nom_bin_n)/tc05_5_alpgen_nom_bin_n;

  //     double tc05_5_data_alpgen_ratio_err = fabs(tc05_5_rel_ratio_data_alpgen_lep_met_pt_err*tc05_5_data_alpgen_ratio);

  //     h_ratio_data_alpgen_lep_met_pt->SetBinContent(b,tc05_5_data_alpgen_ratio);
  //     h_ratio_data_alpgen_lep_met_pt->SetBinError(b,tc05_5_data_alpgen_ratio_err);
  //   }
    

  //   if(tc05_5_data_bin_n && tc05_5_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc05_5_abs_data_sherpa_err = sqrt(pow(tc05_5_data_bin_err,2.)+pow(tc05_5_sherpa_nom_bin_err,2.));
  //     double tc05_5_rel_data_sherpa_err = tc05_5_abs_data_sherpa_err/(tc05_5_data_bin_n-tc05_5_sherpa_nom_bin_n);
  //     double tc05_5_rel_sherpa_err = tc05_5_sherpa_nom_bin_err/tc05_5_sherpa_nom_bin_n;
      
  //     double tc05_5_rel_ratio_data_sherpa_lep_met_pt_err = sqrt(pow(tc05_5_rel_data_sherpa_err,2.)+pow(tc05_5_rel_sherpa_err,2.));

  //     double tc05_5_data_sherpa_ratio = (tc05_5_data_bin_n-tc05_5_sherpa_nom_bin_n)/tc05_5_sherpa_nom_bin_n;

  //     double tc05_5_data_sherpa_ratio_err = fabs(tc05_5_rel_ratio_data_sherpa_lep_met_pt_err*tc05_5_data_sherpa_ratio);

  //     h_ratio_data_sherpa_lep_met_pt->SetBinContent(b,tc05_5_data_sherpa_ratio);
  //     h_ratio_data_sherpa_lep_met_pt->SetBinError(b,tc05_5_data_sherpa_ratio_err);
  //   }
    

  //   if(tc05_5_data_bin_n && tc05_5_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc05_5_abs_data_alpgen_iqopt3_err = sqrt(pow(tc05_5_data_bin_err,2.)+pow(tc05_5_alpgen_iqopt3_bin_err,2.));
  //     double tc05_5_rel_data_alpgen_iqopt3_err = tc05_5_abs_data_alpgen_iqopt3_err/(tc05_5_data_bin_n-tc05_5_alpgen_iqopt3_bin_n);
  //     double tc05_5_rel_alpgen_iqopt3_err = tc05_5_alpgen_iqopt3_bin_err/tc05_5_alpgen_iqopt3_bin_n;
      
  //     double tc05_5_rel_ratio_data_alpgen_iqopt3_lep_met_pt_err = sqrt(pow(tc05_5_rel_data_alpgen_iqopt3_err,2.)+pow(tc05_5_rel_alpgen_iqopt3_err,2.));

  //     double tc05_5_data_alpgen_iqopt3_ratio = (tc05_5_data_bin_n-tc05_5_alpgen_iqopt3_bin_n)/tc05_5_alpgen_iqopt3_bin_n;

  //     double tc05_5_data_alpgen_iqopt3_ratio_err = fabs(tc05_5_rel_ratio_data_alpgen_iqopt3_lep_met_pt_err*tc05_5_data_alpgen_iqopt3_ratio);

  //     h_ratio_data_alpgen_iqopt3_lep_met_pt->SetBinContent(b,tc05_5_data_alpgen_iqopt3_ratio);
  //     h_ratio_data_alpgen_iqopt3_lep_met_pt->SetBinError(b,tc05_5_data_alpgen_iqopt3_ratio_err);
  //   }
    
  //   if(tc05_5_data_bin_n && tc05_5_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc05_5_abs_data_alpgen_ptjmin10_err = sqrt(pow(tc05_5_data_bin_err,2.)+pow(tc05_5_alpgen_ptjmin10_bin_err,2.));
  //     double tc05_5_rel_data_alpgen_ptjmin10_err = tc05_5_abs_data_alpgen_ptjmin10_err/(tc05_5_data_bin_n-tc05_5_alpgen_ptjmin10_bin_n);
  //     double tc05_5_rel_alpgen_ptjmin10_err = tc05_5_alpgen_ptjmin10_bin_err/tc05_5_alpgen_ptjmin10_bin_n;
      
  //     double tc05_5_rel_ratio_data_alpgen_ptjmin10_lep_met_pt_err = sqrt(pow(tc05_5_rel_data_alpgen_ptjmin10_err,2.)+pow(tc05_5_rel_alpgen_ptjmin10_err,2.));

  //     double tc05_5_data_alpgen_ptjmin10_ratio = (tc05_5_data_bin_n-tc05_5_alpgen_ptjmin10_bin_n)/tc05_5_alpgen_ptjmin10_bin_n;

  //     double tc05_5_data_alpgen_ptjmin10_ratio_err = fabs(tc05_5_rel_ratio_data_alpgen_ptjmin10_lep_met_pt_err*tc05_5_data_alpgen_ptjmin10_ratio);

  //     h_ratio_data_alpgen_ptjmin10_lep_met_pt->SetBinContent(b,tc05_5_data_alpgen_ptjmin10_ratio);
  //     h_ratio_data_alpgen_ptjmin10_lep_met_pt->SetBinError(b,tc05_5_data_alpgen_ptjmin10_ratio_err);
  //   }
  // }


  // h_ratio_data_alpgen_lep_met_pt->Draw("PE");
  // h_ratio_data_sherpa_lep_met_pt->Draw("PE sames");
  // h_ratio_data_alpgen_iqopt3_lep_met_pt->Draw("PE sames");
  // h_ratio_data_alpgen_ptjmin10_lep_met_pt->Draw("PE sames");
  
  // //  h_ratio_alpgen_iqopt3_lep_met_pt->Draw("PE sames");
  // //  h_ratio_alpgen_ptjmin10_lep_met_pt->Draw("PE sames");
  
  // tc05_5->Update();
  // tc05_5->SaveAs("./plots/latest/data_elec_lep_met_pt.png");

  // //NEXT  
  
  // ////////////////////////////////////////////////// 
  // // tc06
  // // muon_lep_met_pt: tc06_sherpa/alpgen+wjrw
  // ////////////////////////////////////////////////// 

  // string tc06_title = "Pt(muon+MET) (muon)";
  // string tc06_name = "tc06";
  // TCanvas* tc06 = new TCanvas(tc06_name.c_str(),tc06_title.c_str(),0,0,1920,1200);
  // tc06->cd();

  // TPad* tc06_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc06_pad01->SetTopMargin(0.05);
  // tc06_pad01->SetBottomMargin(0.31);
  // tc06_pad01->Draw();

  // TPad* tc06_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc06_pad02->SetBottomMargin(0.0005);
  // tc06_pad02->SetLogy();
  // tc06_pad02->Draw();
  // tc06_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_muon_lep_met_pt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_purw_nom_lep_met_pt");
  // TH1F* h_alpgen_iqopt3_muon_lep_met_pt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_iqopt3_lep_met_pt");
  // TH1F* h_alpgen_ptjmin10_muon_lep_met_pt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_ptjmin10_lep_met_pt");
  // TH1F* h_sherpa_nom_muon_lep_met_pt = (TH1F*) wjets_sherpa_file->Get("all/h_muon_purw_nom_lep_met_pt");

  // //h_alpgen_nom_muon_lep_met_pt->SetLineWidth(2);
  // h_alpgen_nom_muon_lep_met_pt->SetMarkerStyle(20);
  // h_alpgen_nom_muon_lep_met_pt->SetMarkerSize(1.2);
  // h_alpgen_nom_muon_lep_met_pt->SetTitle("");
  // h_alpgen_nom_muon_lep_met_pt->Draw("PE");

  // //h_alpgen_iqopt3_muon_lep_met_pt->SetLineColor(kGreen);
  // h_alpgen_iqopt3_muon_lep_met_pt->SetMarkerStyle(22);
  // h_alpgen_iqopt3_muon_lep_met_pt->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_muon_lep_met_pt->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_muon_lep_met_pt->Draw("PE sames");

  // //  h_alpgen_ptjmin10_muon_lep_met_pt->SetLineColor(kBlue);
  // h_alpgen_ptjmin10_muon_lep_met_pt->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_muon_lep_met_pt->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_muon_lep_met_pt->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_muon_lep_met_pt->Draw("PE sames");

  // // h_sherpa_nom_muon_lep_met_pt->SetLineWidth(1.2);
  // // h_sherpa_nom_muon_lep_met_pt->SetLineColor(kRed);
  // h_sherpa_nom_muon_lep_met_pt->SetMarkerStyle(20);
  // h_sherpa_nom_muon_lep_met_pt->SetMarkerSize(1.2);
  // h_sherpa_nom_muon_lep_met_pt->SetMarkerColor(kRed);
  // h_sherpa_nom_muon_lep_met_pt->Draw("PE sames");


  // //Legend
  // TLegend* lgnd_tc06 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc06->SetFillColor(0);
  // lgnd_tc06->SetTextSize(0.03);
  // lgnd_tc06->SetBorderSize(0);

  // char lgnd_alpgen_nom_muon_lep_met_pt_name[20];
  // sprintf(lgnd_alpgen_nom_muon_lep_met_pt_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_muon_lep_met_pt->Integral());
  // lgnd_tc06->AddEntry(h_alpgen_nom_muon_lep_met_pt,lgnd_alpgen_nom_muon_lep_met_pt_name,"p");

  // char lgnd_alpgen_iqopt3_muon_lep_met_pt_name[20];
  // sprintf(lgnd_alpgen_iqopt3_muon_lep_met_pt_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_muon_lep_met_pt->Integral());
  // lgnd_tc06->AddEntry(h_alpgen_iqopt3_muon_lep_met_pt,lgnd_alpgen_iqopt3_muon_lep_met_pt_name,"p");

  // char lgnd_alpgen_ptjmin10_muon_lep_met_pt_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_muon_lep_met_pt_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_muon_lep_met_pt->Integral());
  // lgnd_tc06->AddEntry(h_alpgen_ptjmin10_muon_lep_met_pt,lgnd_alpgen_ptjmin10_muon_lep_met_pt_name,"p");

  // char lgnd_sherpa_nom_muon_lep_met_pt_name[20];
  // sprintf(lgnd_sherpa_nom_muon_lep_met_pt_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_muon_lep_met_pt->Integral());
  // lgnd_tc06->AddEntry(h_sherpa_nom_muon_lep_met_pt,lgnd_sherpa_nom_muon_lep_met_pt_name,"p");

  // lgnd_tc06->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc06_pad01->cd();
  // tc06_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_muon_lep_met_pt->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_muon_lep_met_pt->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_muon_lep_met_pt->GetXaxis())->GetXmax();

  // // alp-sherp/sherp
  // string tc06_ratio_alpgen_sherpa_lep_met_pt_name = "tc06_ratio_alpgen_sherpa_lep_met_pt";
  // TH1F* h_ratio_alpgen_sherpa_lep_met_pt = new TH1F(tc06_ratio_alpgen_sherpa_lep_met_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_sherpa_lep_met_pt->SetMarkerStyle(8);
  // h_ratio_alpgen_sherpa_lep_met_pt->SetMarkerColor(kRed);

  // TAxis* h_ratio_alpgen_sherpa_lep_met_pt_xaxis = h_ratio_alpgen_sherpa_lep_met_pt->GetXaxis();
  // TAxis* h_ratio_alpgen_sherpa_lep_met_pt_yaxis = h_ratio_alpgen_sherpa_lep_met_pt->GetYaxis();
  
  // h_ratio_alpgen_sherpa_lep_met_pt_xaxis->SetLabelSize(0.08);
  // h_ratio_alpgen_sherpa_lep_met_pt_yaxis->SetLabelSize(0.08);

  // h_ratio_alpgen_sherpa_lep_met_pt_xaxis->SetTitle("Pt(muon+MET)");
  // h_ratio_alpgen_sherpa_lep_met_pt_xaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_lep_met_pt_yaxis->SetNdivisions(4,4,4);
  // h_ratio_alpgen_sherpa_lep_met_pt_yaxis->SetTitle("(alpgen-MC)/MC");
  // h_ratio_alpgen_sherpa_lep_met_pt_yaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_lep_met_pt_yaxis->SetTitleOffset(0.36);
  // h_ratio_alpgen_sherpa_lep_met_pt_yaxis->SetRangeUser(-1,1);

  
  // // alp-iqopt3/iqopt3
  // string tc06_ratio_alpgen_iqopt3_lep_met_pt_name = "tc06_ratio_alpgen_iqopt3_lep_met_pt";
  // TH1F* h_ratio_alpgen_iqopt3_lep_met_pt = new TH1F(tc06_ratio_alpgen_iqopt3_lep_met_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_iqopt3_lep_met_pt->SetMarkerStyle(8);
  // h_ratio_alpgen_iqopt3_lep_met_pt->SetMarkerColor(kGreen);

  
  // // alp-ptjmin10/ptjmin10
  // string tc06_ratio_alpgen_ptjmin10_lep_met_pt_name = "tc06_ratio_alpgen_ptjmin10_lep_met_pt";
  // TH1F* h_ratio_alpgen_ptjmin10_lep_met_pt = new TH1F(tc06_ratio_alpgen_ptjmin10_lep_met_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_ptjmin10_lep_met_pt->SetMarkerStyle(8);
  // h_ratio_alpgen_ptjmin10_lep_met_pt->SetMarkerColor(kBlue);


  
  // double tc06_alpgen_sherpa_ratio=0.;
  // double tc06_alpgen_iqopt3_ratio=0.;
  // double tc06_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc06_alpgen_nom_bin_n=h_alpgen_nom_muon_lep_met_pt->GetBinContent(b);
  //   double tc06_alpgen_nom_bin_err=h_alpgen_nom_muon_lep_met_pt->GetBinError(b);    

  //   double tc06_sherpa_nom_bin_n=h_sherpa_nom_muon_lep_met_pt->GetBinContent(b);
  //   double tc06_sherpa_nom_bin_err=h_sherpa_nom_muon_lep_met_pt->GetBinError(b);    

  //   double tc06_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_muon_lep_met_pt->GetBinContent(b);
  //   double tc06_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_muon_lep_met_pt->GetBinError(b);

  //   double tc06_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_muon_lep_met_pt->GetBinContent(b);
  //   double tc06_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_muon_lep_met_pt->GetBinError(b);



  //   if(tc06_alpgen_nom_bin_n && tc06_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc06_abs_alpgen_sherpa_err = sqrt(pow(tc06_alpgen_nom_bin_err,2.)+pow(tc06_sherpa_nom_bin_err,2.));
  //     double tc06_rel_alpgen_sherpa_err = tc06_abs_alpgen_sherpa_err/(tc06_alpgen_nom_bin_n-tc06_sherpa_nom_bin_n);
  //     double tc06_rel_sherpa_err = tc06_sherpa_nom_bin_err/tc06_sherpa_nom_bin_n;
      
  //     double tc06_rel_ratio_alpgen_sherpa_lep_met_pt_err = sqrt(pow(tc06_rel_alpgen_sherpa_err,2.)+pow(tc06_rel_sherpa_err,2.));

  //     double tc06_alpgen_sherpa_ratio = (tc06_alpgen_nom_bin_n-tc06_sherpa_nom_bin_n)/tc06_sherpa_nom_bin_n;

  //     double tc06_alpgen_sherpa_ratio_err = fabs(tc06_rel_ratio_alpgen_sherpa_lep_met_pt_err*tc06_alpgen_sherpa_ratio);

  //     h_ratio_alpgen_sherpa_lep_met_pt->SetBinContent(b,tc06_alpgen_sherpa_ratio);
  //     h_ratio_alpgen_sherpa_lep_met_pt->SetBinError(b,tc06_alpgen_sherpa_ratio_err);
  //   }
    

  //   if(tc06_alpgen_nom_bin_n && tc06_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc06_abs_alpgen_iqopt3_err = sqrt(pow(tc06_alpgen_nom_bin_err,2.)+pow(tc06_alpgen_iqopt3_bin_err,2.));
  //     double tc06_rel_alpgen_iqopt3_err = tc06_abs_alpgen_iqopt3_err/(tc06_alpgen_nom_bin_n-tc06_alpgen_iqopt3_bin_n);
  //     double tc06_rel_iqopt3_err = tc06_alpgen_iqopt3_bin_err/tc06_alpgen_iqopt3_bin_n;
      
  //     double tc06_rel_ratio_alpgen_iqopt3_lep_met_pt_err = sqrt(pow(tc06_rel_alpgen_iqopt3_err,2.)+pow(tc06_rel_iqopt3_err,2.));

  //     double tc06_alpgen_iqopt3_ratio = (tc06_alpgen_nom_bin_n-tc06_alpgen_iqopt3_bin_n)/tc06_alpgen_iqopt3_bin_n;

  //     double tc06_alpgen_iqopt3_ratio_err = fabs(tc06_rel_ratio_alpgen_iqopt3_lep_met_pt_err*tc06_alpgen_iqopt3_ratio);

  //     h_ratio_alpgen_iqopt3_lep_met_pt->SetBinContent(b,tc06_alpgen_iqopt3_ratio);
  //     h_ratio_alpgen_iqopt3_lep_met_pt->SetBinError(b,tc06_alpgen_iqopt3_ratio_err);
  //   }

    

  //   if(tc06_alpgen_nom_bin_n && tc06_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc06_abs_alpgen_ptjmin10_err = sqrt(pow(tc06_alpgen_nom_bin_err,2.)+pow(tc06_alpgen_ptjmin10_bin_err,2.));
  //     double tc06_rel_alpgen_ptjmin10_err = tc06_abs_alpgen_ptjmin10_err/(tc06_alpgen_nom_bin_n-tc06_alpgen_ptjmin10_bin_n);
  //     double tc06_rel_ptjmin10_err = tc06_alpgen_ptjmin10_bin_err/tc06_alpgen_ptjmin10_bin_n;
      
  //     double tc06_rel_ratio_alpgen_ptjmin10_lep_met_pt_err = sqrt(pow(tc06_rel_alpgen_ptjmin10_err,2.)+pow(tc06_rel_ptjmin10_err,2.));

  //     double tc06_alpgen_ptjmin10_ratio = (tc06_alpgen_nom_bin_n-tc06_alpgen_ptjmin10_bin_n)/tc06_alpgen_ptjmin10_bin_n;

  //     double tc06_alpgen_ptjmin10_ratio_err = fabs(tc06_rel_ratio_alpgen_ptjmin10_lep_met_pt_err*tc06_alpgen_ptjmin10_ratio);

  //     h_ratio_alpgen_ptjmin10_lep_met_pt->SetBinContent(b,tc06_alpgen_ptjmin10_ratio);
  //     h_ratio_alpgen_ptjmin10_lep_met_pt->SetBinError(b,tc06_alpgen_ptjmin10_ratio_err);
  //   }
    
  // }


  // h_ratio_alpgen_sherpa_lep_met_pt->Draw("PE");
  // h_ratio_alpgen_iqopt3_lep_met_pt->Draw("PE sames");
  // h_ratio_alpgen_ptjmin10_lep_met_pt->Draw("PE sames");
  
  // tc06->Update();

  // tc06->SaveAs("./plots/latest/muon_lep_met_pt.png");
  
  // //NEXT
  
  // //////////////////////////////////////////////////
  // // tc06_5
  // // data_muon_lep_met_pt: sherpa/alpgen+wjrw
  // //////////////////////////////////////////////////
  
  // string tc06_5_title = "Pt(muon+MET) (muon) w/ Data";
  // string tc06_5_name = "tc06_5";
  // TCanvas* tc06_5 = new TCanvas(tc06_5_name.c_str(),tc06_5_title.c_str(),0,0,1920,1200);
  // tc06_5->cd();

  // TPad* tc06_5_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc06_5_pad01->SetTopMargin(0.05);
  // tc06_5_pad01->SetBottomMargin(0.31);
  // tc06_5_pad01->Draw();

  // TPad* tc06_5_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc06_5_pad02->SetBottomMargin(0.0005);
  // tc06_5_pad02->SetLogy();
  // tc06_5_pad02->Draw();
  // tc06_5_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_muon_lep_met_pt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_purw_nom_lep_met_pt");
  // TH1F* h_alpgen_iqopt3_muon_lep_met_pt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_iqopt3_lep_met_pt");
  // TH1F* h_alpgen_ptjmin10_muon_lep_met_pt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_ptjmin10_lep_met_pt");
  // TH1F* h_sherpa_nom_muon_lep_met_pt = (TH1F*) wjets_sherpa_file->Get("all/h_muon_purw_nom_lep_met_pt");
  // TH1F* h_data_muon_lep_met_pt = (TH1F*) data_file->Get("all/h_muon_purw_nom_lep_met_pt");

  // TH1F* h_top_muon_lep_met_pt = (TH1F*) top_mcatnlo_file->Get("all/h_muon_purw_nom_lep_met_pt");
  // TH1F* h_zjets_muon_lep_met_pt = (TH1F*) zjets_alpgen_file->Get("all/h_muon_purw_nom_lep_met_pt");
  // TH1F* h_vv_muon_lep_met_pt = (TH1F*) vv_herwig_file->Get("all/h_muon_purw_nom_lep_met_pt");
  // TH1F* h_qcd_muon_lep_met_pt = (TH1F*) qcd_file->Get("all/h_muon_purw_nom_lep_met_pt");
  
  // h_data_muon_lep_met_pt->SetTitle("");
  // h_data_muon_lep_met_pt->Draw();
  
  // //Add Backgrounds
  // h_alpgen_nom_muon_lep_met_pt->Add(h_top_muon_lep_met_pt);
  // h_alpgen_nom_muon_lep_met_pt->Add(h_zjets_muon_lep_met_pt);
  // h_alpgen_nom_muon_lep_met_pt->Add(h_vv_muon_lep_met_pt);
  // h_alpgen_nom_muon_lep_met_pt->Add(h_qcd_muon_lep_met_pt);
  
  // h_alpgen_nom_muon_lep_met_pt->SetMarkerStyle(20);
  // h_alpgen_nom_muon_lep_met_pt->SetMarkerSize(1.2);
  // h_alpgen_nom_muon_lep_met_pt->Draw("PE sames");

  // //Add backgrounds
  // h_alpgen_iqopt3_muon_lep_met_pt->Add(h_top_muon_lep_met_pt);
  // h_alpgen_iqopt3_muon_lep_met_pt->Add(h_zjets_muon_lep_met_pt);
  // h_alpgen_iqopt3_muon_lep_met_pt->Add(h_vv_muon_lep_met_pt);
  // h_alpgen_iqopt3_muon_lep_met_pt->Add(h_qcd_muon_lep_met_pt);

  // h_alpgen_iqopt3_muon_lep_met_pt->SetMarkerStyle(22);
  // h_alpgen_iqopt3_muon_lep_met_pt->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_muon_lep_met_pt->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_muon_lep_met_pt->Draw("PE sames");

  // //Add Backgrounds
  // h_alpgen_ptjmin10_muon_lep_met_pt->Add(h_top_muon_lep_met_pt);
  // h_alpgen_ptjmin10_muon_lep_met_pt->Add(h_zjets_muon_lep_met_pt);
  // h_alpgen_ptjmin10_muon_lep_met_pt->Add(h_vv_muon_lep_met_pt);
  // h_alpgen_ptjmin10_muon_lep_met_pt->Add(h_qcd_muon_lep_met_pt);

  // h_alpgen_ptjmin10_muon_lep_met_pt->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_muon_lep_met_pt->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_muon_lep_met_pt->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_muon_lep_met_pt->Draw("PE sames");

  // //Add Backgrounds
  // h_sherpa_nom_muon_lep_met_pt->Add(h_top_muon_lep_met_pt);
  // h_sherpa_nom_muon_lep_met_pt->Add(h_zjets_muon_lep_met_pt);
  // h_sherpa_nom_muon_lep_met_pt->Add(h_vv_muon_lep_met_pt);
  // h_sherpa_nom_muon_lep_met_pt->Add(h_qcd_muon_lep_met_pt);

  // h_sherpa_nom_muon_lep_met_pt->SetMarkerStyle(20);
  // h_sherpa_nom_muon_lep_met_pt->SetMarkerSize(1.2);
  // h_sherpa_nom_muon_lep_met_pt->SetMarkerColor(kRed);
  // h_sherpa_nom_muon_lep_met_pt->Draw("PE sames");




  // //Legend
  // TLegend* lgnd_tc06_5 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc06_5->SetFillColor(0);
  // lgnd_tc06_5->SetTextSize(0.03);
  // lgnd_tc06_5->SetBorderSize(0);

  // char lgnd_data_muon_lep_met_pt_name[20];
  // sprintf(lgnd_data_muon_lep_met_pt_name,"%s,  %.2f","DATA",h_data_muon_lep_met_pt->Integral());
  // lgnd_tc06_5->AddEntry(h_data_muon_lep_met_pt,lgnd_data_muon_lep_met_pt_name,"f");

  // char lgnd_alpgen_nom_muon_lep_met_pt_name[20];
  // sprintf(lgnd_alpgen_nom_muon_lep_met_pt_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_muon_lep_met_pt->Integral());
  // lgnd_tc06_5->AddEntry(h_alpgen_nom_muon_lep_met_pt,lgnd_alpgen_nom_muon_lep_met_pt_name,"p");

  // char lgnd_alpgen_iqopt3_muon_lep_met_pt_name[20];
  // sprintf(lgnd_alpgen_iqopt3_muon_lep_met_pt_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_muon_lep_met_pt->Integral());
  // lgnd_tc06_5->AddEntry(h_alpgen_iqopt3_muon_lep_met_pt,lgnd_alpgen_iqopt3_muon_lep_met_pt_name,"p");

  // char lgnd_alpgen_ptjmin10_muon_lep_met_pt_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_muon_lep_met_pt_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_muon_lep_met_pt->Integral());
  // lgnd_tc06_5->AddEntry(h_alpgen_ptjmin10_muon_lep_met_pt,lgnd_alpgen_ptjmin10_muon_lep_met_pt_name,"p");

  // char lgnd_sherpa_nom_muon_lep_met_pt_name[20];
  // sprintf(lgnd_sherpa_nom_muon_lep_met_pt_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_muon_lep_met_pt->Integral());
  // lgnd_tc06_5->AddEntry(h_sherpa_nom_muon_lep_met_pt,lgnd_sherpa_nom_muon_lep_met_pt_name,"p");

  // lgnd_tc06_5->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc06_5_pad01->cd();
  // tc06_5_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_muon_lep_met_pt->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_muon_lep_met_pt->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_muon_lep_met_pt->GetXaxis())->GetXmax();

  // // data-alpgen(nom)/alpgen(nom)
  // string tc06_5_ratio_data_alpgen_lep_met_pt_name = "tc06_5_ratio_data_alpgen_lep_met_pt";
  // TH1F* h_ratio_data_alpgen_lep_met_pt = new TH1F(tc06_5_ratio_data_alpgen_lep_met_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_lep_met_pt->SetMarkerStyle(8);
  // //h_ratio_data_alpgen_lep_met_pt->SetMarkerColor(kRed);

  // TAxis* h_ratio_data_alpgen_lep_met_pt_xaxis = h_ratio_data_alpgen_lep_met_pt->GetXaxis();
  // TAxis* h_ratio_data_alpgen_lep_met_pt_yaxis = h_ratio_data_alpgen_lep_met_pt->GetYaxis();
  
  // h_ratio_data_alpgen_lep_met_pt_xaxis->SetLabelSize(0.08);
  // h_ratio_data_alpgen_lep_met_pt_yaxis->SetLabelSize(0.08);

  // h_ratio_data_alpgen_lep_met_pt_xaxis->SetTitle("Pt(muon+MET)");
  // h_ratio_data_alpgen_lep_met_pt_xaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_lep_met_pt_yaxis->SetNdivisions(4,4,4);
  // h_ratio_data_alpgen_lep_met_pt_yaxis->SetTitle("(data-MC)/MC");
  // h_ratio_data_alpgen_lep_met_pt_yaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_lep_met_pt_yaxis->SetTitleOffset(0.36);
  // h_ratio_data_alpgen_lep_met_pt_yaxis->SetRangeUser(-1,1);

  // // data-sherpa(nom)/sherpa(nom)
  // string tc06_5_ratio_data_sherpa_lep_met_pt_name = "tc06_5_ratio_data_sherpa_lep_met_pt";
  // TH1F* h_ratio_data_sherpa_lep_met_pt = new TH1F(tc06_5_ratio_data_sherpa_lep_met_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_sherpa_lep_met_pt->SetMarkerStyle(8);
  // h_ratio_data_sherpa_lep_met_pt->SetMarkerColor(kRed);


  // // data-alpgen(iqopt3)/alpgen(iqopt3)
  // string tc06_5_ratio_data_alpgen_iqopt3_lep_met_pt_name = "tc06_5_ratio_data_alpgen_iqopt3_lep_met_pt";
  // TH1F* h_ratio_data_alpgen_iqopt3_lep_met_pt = new TH1F(tc06_5_ratio_data_alpgen_iqopt3_lep_met_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_iqopt3_lep_met_pt->SetMarkerStyle(8);
  // h_ratio_data_alpgen_iqopt3_lep_met_pt->SetMarkerColor(kGreen);

  // // data-alpgen(ptjmin10)/alpgen(ptjmin10)
  // string tc06_5_ratio_data_alpgen_ptjmin10_lep_met_pt_name = "tc06_5_ratio_data_alpgen_ptjmin10_lep_met_pt";
  // TH1F* h_ratio_data_alpgen_ptjmin10_lep_met_pt = new TH1F(tc06_5_ratio_data_alpgen_ptjmin10_lep_met_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_ptjmin10_lep_met_pt->SetMarkerStyle(8);
  // h_ratio_data_alpgen_ptjmin10_lep_met_pt->SetMarkerColor(kBlue);

  

  
  // // // alp-iqopt3/iqopt3
  // // string tc06_5_ratio_alpgen_iqopt3_lead_jet_pt_name = "tc06_5_ratio_alpgen_iqopt3_lead_jet_pt";
  // // TH1F* h_ratio_alpgen_iqopt3_lead_jet_pt = new TH1F(tc06_5_ratio_alpgen_iqopt3_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerStyle(8);
  // // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerColor(kGreen);

  
  // // // alp-ptjmin10/ptjmin10
  // // string tc06_5_ratio_alpgen_ptjmin10_lead_jet_pt_name = "tc06_5_ratio_alpgen_ptjmin10_lead_jet_pt";
  // // TH1F* h_ratio_alpgen_ptjmin10_lead_jet_pt = new TH1F(tc06_5_ratio_alpgen_ptjmin10_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerStyle(8);
  // // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerColor(kBlue);


  
  // double tc06_5_data_alpgen_ratio=0.;
  // double tc06_5_data_sherpa_ratio=0.;
  // double tc06_5_data_alpgen_iqopt3_ratio=0.;
  // double tc06_5_data_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc06_5_alpgen_nom_bin_n=h_alpgen_nom_muon_lep_met_pt->GetBinContent(b);
  //   double tc06_5_alpgen_nom_bin_err=h_alpgen_nom_muon_lep_met_pt->GetBinError(b);    

  //   double tc06_5_data_bin_n=h_data_muon_lep_met_pt->GetBinContent(b);
  //   double tc06_5_data_bin_err=h_data_muon_lep_met_pt->GetBinError(b);    

  //   double tc06_5_sherpa_nom_bin_n=h_sherpa_nom_muon_lep_met_pt->GetBinContent(b);
  //   double tc06_5_sherpa_nom_bin_err=h_sherpa_nom_muon_lep_met_pt->GetBinError(b);    

  //   double tc06_5_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_muon_lep_met_pt->GetBinContent(b);
  //   double tc06_5_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_muon_lep_met_pt->GetBinError(b);

  //   double tc06_5_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_muon_lep_met_pt->GetBinContent(b);
  //   double tc06_5_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_muon_lep_met_pt->GetBinError(b);



  //   if(tc06_5_data_bin_n && tc06_5_alpgen_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc06_5_abs_data_alpgen_err = sqrt(pow(tc06_5_data_bin_err,2.)+pow(tc06_5_alpgen_nom_bin_err,2.));
  //     double tc06_5_rel_data_alpgen_err = tc06_5_abs_data_alpgen_err/(tc06_5_data_bin_n-tc06_5_alpgen_nom_bin_n);
  //     double tc06_5_rel_alpgen_err = tc06_5_alpgen_nom_bin_err/tc06_5_alpgen_nom_bin_n;
      
  //     double tc06_5_rel_ratio_data_alpgen_lep_met_pt_err = sqrt(pow(tc06_5_rel_data_alpgen_err,2.)+pow(tc06_5_rel_alpgen_err,2.));

  //     double tc06_5_data_alpgen_ratio = (tc06_5_data_bin_n-tc06_5_alpgen_nom_bin_n)/tc06_5_alpgen_nom_bin_n;

  //     double tc06_5_data_alpgen_ratio_err = fabs(tc06_5_rel_ratio_data_alpgen_lep_met_pt_err*tc06_5_data_alpgen_ratio);

  //     h_ratio_data_alpgen_lep_met_pt->SetBinContent(b,tc06_5_data_alpgen_ratio);
  //     h_ratio_data_alpgen_lep_met_pt->SetBinError(b,tc06_5_data_alpgen_ratio_err);
  //   }
    

  //   if(tc06_5_data_bin_n && tc06_5_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc06_5_abs_data_sherpa_err = sqrt(pow(tc06_5_data_bin_err,2.)+pow(tc06_5_sherpa_nom_bin_err,2.));
  //     double tc06_5_rel_data_sherpa_err = tc06_5_abs_data_sherpa_err/(tc06_5_data_bin_n-tc06_5_sherpa_nom_bin_n);
  //     double tc06_5_rel_sherpa_err = tc06_5_sherpa_nom_bin_err/tc06_5_sherpa_nom_bin_n;
      
  //     double tc06_5_rel_ratio_data_sherpa_lep_met_pt_err = sqrt(pow(tc06_5_rel_data_sherpa_err,2.)+pow(tc06_5_rel_sherpa_err,2.));

  //     double tc06_5_data_sherpa_ratio = (tc06_5_data_bin_n-tc06_5_sherpa_nom_bin_n)/tc06_5_sherpa_nom_bin_n;

  //     double tc06_5_data_sherpa_ratio_err = fabs(tc06_5_rel_ratio_data_sherpa_lep_met_pt_err*tc06_5_data_sherpa_ratio);

  //     h_ratio_data_sherpa_lep_met_pt->SetBinContent(b,tc06_5_data_sherpa_ratio);
  //     h_ratio_data_sherpa_lep_met_pt->SetBinError(b,tc06_5_data_sherpa_ratio_err);
  //   }
    

  //   if(tc06_5_data_bin_n && tc06_5_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc06_5_abs_data_alpgen_iqopt3_err = sqrt(pow(tc06_5_data_bin_err,2.)+pow(tc06_5_alpgen_iqopt3_bin_err,2.));
  //     double tc06_5_rel_data_alpgen_iqopt3_err = tc06_5_abs_data_alpgen_iqopt3_err/(tc06_5_data_bin_n-tc06_5_alpgen_iqopt3_bin_n);
  //     double tc06_5_rel_alpgen_iqopt3_err = tc06_5_alpgen_iqopt3_bin_err/tc06_5_alpgen_iqopt3_bin_n;
      
  //     double tc06_5_rel_ratio_data_alpgen_iqopt3_lep_met_pt_err = sqrt(pow(tc06_5_rel_data_alpgen_iqopt3_err,2.)+pow(tc06_5_rel_alpgen_iqopt3_err,2.));

  //     double tc06_5_data_alpgen_iqopt3_ratio = (tc06_5_data_bin_n-tc06_5_alpgen_iqopt3_bin_n)/tc06_5_alpgen_iqopt3_bin_n;

  //     double tc06_5_data_alpgen_iqopt3_ratio_err = fabs(tc06_5_rel_ratio_data_alpgen_iqopt3_lep_met_pt_err*tc06_5_data_alpgen_iqopt3_ratio);

  //     h_ratio_data_alpgen_iqopt3_lep_met_pt->SetBinContent(b,tc06_5_data_alpgen_iqopt3_ratio);
  //     h_ratio_data_alpgen_iqopt3_lep_met_pt->SetBinError(b,tc06_5_data_alpgen_iqopt3_ratio_err);
  //   }
    
  //   if(tc06_5_data_bin_n && tc06_5_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc06_5_abs_data_alpgen_ptjmin10_err = sqrt(pow(tc06_5_data_bin_err,2.)+pow(tc06_5_alpgen_ptjmin10_bin_err,2.));
  //     double tc06_5_rel_data_alpgen_ptjmin10_err = tc06_5_abs_data_alpgen_ptjmin10_err/(tc06_5_data_bin_n-tc06_5_alpgen_ptjmin10_bin_n);
  //     double tc06_5_rel_alpgen_ptjmin10_err = tc06_5_alpgen_ptjmin10_bin_err/tc06_5_alpgen_ptjmin10_bin_n;
      
  //     double tc06_5_rel_ratio_data_alpgen_ptjmin10_lep_met_pt_err = sqrt(pow(tc06_5_rel_data_alpgen_ptjmin10_err,2.)+pow(tc06_5_rel_alpgen_ptjmin10_err,2.));

  //     double tc06_5_data_alpgen_ptjmin10_ratio = (tc06_5_data_bin_n-tc06_5_alpgen_ptjmin10_bin_n)/tc06_5_alpgen_ptjmin10_bin_n;

  //     double tc06_5_data_alpgen_ptjmin10_ratio_err = fabs(tc06_5_rel_ratio_data_alpgen_ptjmin10_lep_met_pt_err*tc06_5_data_alpgen_ptjmin10_ratio);

  //     h_ratio_data_alpgen_ptjmin10_lep_met_pt->SetBinContent(b,tc06_5_data_alpgen_ptjmin10_ratio);
  //     h_ratio_data_alpgen_ptjmin10_lep_met_pt->SetBinError(b,tc06_5_data_alpgen_ptjmin10_ratio_err);
  //   }
  // }


  // h_ratio_data_alpgen_lep_met_pt->Draw("PE");
  // h_ratio_data_sherpa_lep_met_pt->Draw("PE sames");
  // h_ratio_data_alpgen_iqopt3_lep_met_pt->Draw("PE sames");
  // h_ratio_data_alpgen_ptjmin10_lep_met_pt->Draw("PE sames");
  
  // //  h_ratio_alpgen_iqopt3_lep_met_pt->Draw("PE sames");
  // //  h_ratio_alpgen_ptjmin10_lep_met_pt->Draw("PE sames");
  
  // tc06_5->Update();
  // tc06_5->SaveAs("./plots/latest/data_muon_lep_met_pt.png");
    

  // //NEXT
  
  // ////////////////////////////////////////////////// 
  // // tc07
  // // elec_dijet_pt: tc07_sherpa/alpgen+wjrw
  // ////////////////////////////////////////////////// 

  // string tc07_title = "Pt(dijet) (elec)";
  // string tc07_name = "tc07";
  // TCanvas* tc07 = new TCanvas(tc07_name.c_str(),tc07_title.c_str(),0,0,1920,1200);
  // tc07->cd();

  // TPad* tc07_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc07_pad01->SetTopMargin(0.05);
  // tc07_pad01->SetBottomMargin(0.31);
  // tc07_pad01->Draw();

  // TPad* tc07_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc07_pad02->SetBottomMargin(0.0005);
  // tc07_pad02->SetLogy();
  // tc07_pad02->Draw();
  // tc07_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_elec_dijet_pt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_purw_nom_dijet_pt");
  // TH1F* h_alpgen_iqopt3_elec_dijet_pt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_iqopt3_dijet_pt");
  // TH1F* h_alpgen_ptjmin10_elec_dijet_pt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_ptjmin10_dijet_pt");
  // TH1F* h_sherpa_nom_elec_dijet_pt = (TH1F*) wjets_sherpa_file->Get("all/h_elec_purw_nom_dijet_pt");

  // //h_alpgen_nom_elec_dijet_pt->SetLineWidth(2);
  // h_alpgen_nom_elec_dijet_pt->SetMarkerStyle(20);
  // h_alpgen_nom_elec_dijet_pt->SetMarkerSize(1.2);
  // h_alpgen_nom_elec_dijet_pt->SetTitle("");
  // h_alpgen_nom_elec_dijet_pt->Draw("PE");

  // //h_alpgen_iqopt3_elec_dijet_pt->SetLineColor(kGreen);
  // h_alpgen_iqopt3_elec_dijet_pt->SetMarkerStyle(22);
  // h_alpgen_iqopt3_elec_dijet_pt->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_elec_dijet_pt->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_elec_dijet_pt->Draw("PE sames");

  // //  h_alpgen_ptjmin10_elec_dijet_pt->SetLineColor(kBlue);
  // h_alpgen_ptjmin10_elec_dijet_pt->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_elec_dijet_pt->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_elec_dijet_pt->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_elec_dijet_pt->Draw("PE sames");

  // // h_sherpa_nom_elec_dijet_pt->SetLineWidth(1.2);
  // // h_sherpa_nom_elec_dijet_pt->SetLineColor(kRed);
  // h_sherpa_nom_elec_dijet_pt->SetMarkerStyle(20);
  // h_sherpa_nom_elec_dijet_pt->SetMarkerSize(1.2);
  // h_sherpa_nom_elec_dijet_pt->SetMarkerColor(kRed);
  // h_sherpa_nom_elec_dijet_pt->Draw("PE sames");


  // //Legend
  // TLegend* lgnd_tc07 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc07->SetFillColor(0);
  // lgnd_tc07->SetTextSize(0.03);
  // lgnd_tc07->SetBorderSize(0);

  // char lgnd_alpgen_nom_elec_dijet_pt_name[20];
  // sprintf(lgnd_alpgen_nom_elec_dijet_pt_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_elec_dijet_pt->Integral());
  // lgnd_tc07->AddEntry(h_alpgen_nom_elec_dijet_pt,lgnd_alpgen_nom_elec_dijet_pt_name,"p");

  // char lgnd_alpgen_iqopt3_elec_dijet_pt_name[20];
  // sprintf(lgnd_alpgen_iqopt3_elec_dijet_pt_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_elec_dijet_pt->Integral());
  // lgnd_tc07->AddEntry(h_alpgen_iqopt3_elec_dijet_pt,lgnd_alpgen_iqopt3_elec_dijet_pt_name,"p");

  // char lgnd_alpgen_ptjmin10_elec_dijet_pt_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_elec_dijet_pt_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_elec_dijet_pt->Integral());
  // lgnd_tc07->AddEntry(h_alpgen_ptjmin10_elec_dijet_pt,lgnd_alpgen_ptjmin10_elec_dijet_pt_name,"p");

  // char lgnd_sherpa_nom_elec_dijet_pt_name[20];
  // sprintf(lgnd_sherpa_nom_elec_dijet_pt_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_elec_dijet_pt->Integral());
  // lgnd_tc07->AddEntry(h_sherpa_nom_elec_dijet_pt,lgnd_sherpa_nom_elec_dijet_pt_name,"p");

  // lgnd_tc07->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc07_pad01->cd();
  // tc07_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_elec_dijet_pt->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_elec_dijet_pt->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_elec_dijet_pt->GetXaxis())->GetXmax();

  // // alp-sherp/sherp
  // string tc07_ratio_alpgen_sherpa_dijet_pt_name = "tc07_ratio_alpgen_sherpa_dijet_pt";
  // TH1F* h_ratio_alpgen_sherpa_dijet_pt = new TH1F(tc07_ratio_alpgen_sherpa_dijet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_sherpa_dijet_pt->SetMarkerStyle(8);
  // h_ratio_alpgen_sherpa_dijet_pt->SetMarkerColor(kRed);

  // TAxis* h_ratio_alpgen_sherpa_dijet_pt_xaxis = h_ratio_alpgen_sherpa_dijet_pt->GetXaxis();
  // TAxis* h_ratio_alpgen_sherpa_dijet_pt_yaxis = h_ratio_alpgen_sherpa_dijet_pt->GetYaxis();
  
  // h_ratio_alpgen_sherpa_dijet_pt_xaxis->SetLabelSize(0.08);
  // h_ratio_alpgen_sherpa_dijet_pt_yaxis->SetLabelSize(0.08);

  // h_ratio_alpgen_sherpa_dijet_pt_xaxis->SetTitle("Pt(dijet)");
  // h_ratio_alpgen_sherpa_dijet_pt_xaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_dijet_pt_yaxis->SetNdivisions(4,4,4);
  // h_ratio_alpgen_sherpa_dijet_pt_yaxis->SetTitle("(alpgen-MC)/MC");
  // h_ratio_alpgen_sherpa_dijet_pt_yaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_dijet_pt_yaxis->SetTitleOffset(0.36);
  // h_ratio_alpgen_sherpa_dijet_pt_yaxis->SetRangeUser(-1,1);

  
  // // alp-iqopt3/iqopt3
  // string tc07_ratio_alpgen_iqopt3_dijet_pt_name = "tc07_ratio_alpgen_iqopt3_dijet_pt";
  // TH1F* h_ratio_alpgen_iqopt3_dijet_pt = new TH1F(tc07_ratio_alpgen_iqopt3_dijet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_iqopt3_dijet_pt->SetMarkerStyle(8);
  // h_ratio_alpgen_iqopt3_dijet_pt->SetMarkerColor(kGreen);

  
  // // alp-ptjmin10/ptjmin10
  // string tc07_ratio_alpgen_ptjmin10_dijet_pt_name = "tc07_ratio_alpgen_ptjmin10_dijet_pt";
  // TH1F* h_ratio_alpgen_ptjmin10_dijet_pt = new TH1F(tc07_ratio_alpgen_ptjmin10_dijet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_ptjmin10_dijet_pt->SetMarkerStyle(8);
  // h_ratio_alpgen_ptjmin10_dijet_pt->SetMarkerColor(kBlue);


  
  // double tc07_alpgen_sherpa_ratio=0.;
  // double tc07_alpgen_iqopt3_ratio=0.;
  // double tc07_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc07_alpgen_nom_bin_n=h_alpgen_nom_elec_dijet_pt->GetBinContent(b);
  //   double tc07_alpgen_nom_bin_err=h_alpgen_nom_elec_dijet_pt->GetBinError(b);    

  //   double tc07_sherpa_nom_bin_n=h_sherpa_nom_elec_dijet_pt->GetBinContent(b);
  //   double tc07_sherpa_nom_bin_err=h_sherpa_nom_elec_dijet_pt->GetBinError(b);    

  //   double tc07_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_elec_dijet_pt->GetBinContent(b);
  //   double tc07_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_elec_dijet_pt->GetBinError(b);

  //   double tc07_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_elec_dijet_pt->GetBinContent(b);
  //   double tc07_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_elec_dijet_pt->GetBinError(b);



  //   if(tc07_alpgen_nom_bin_n && tc07_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc07_abs_alpgen_sherpa_err = sqrt(pow(tc07_alpgen_nom_bin_err,2.)+pow(tc07_sherpa_nom_bin_err,2.));
  //     double tc07_rel_alpgen_sherpa_err = tc07_abs_alpgen_sherpa_err/(tc07_alpgen_nom_bin_n-tc07_sherpa_nom_bin_n);
  //     double tc07_rel_sherpa_err = tc07_sherpa_nom_bin_err/tc07_sherpa_nom_bin_n;
      
  //     double tc07_rel_ratio_alpgen_sherpa_dijet_pt_err = sqrt(pow(tc07_rel_alpgen_sherpa_err,2.)+pow(tc07_rel_sherpa_err,2.));

  //     double tc07_alpgen_sherpa_ratio = (tc07_alpgen_nom_bin_n-tc07_sherpa_nom_bin_n)/tc07_sherpa_nom_bin_n;

  //     double tc07_alpgen_sherpa_ratio_err = fabs(tc07_rel_ratio_alpgen_sherpa_dijet_pt_err*tc07_alpgen_sherpa_ratio);

  //     h_ratio_alpgen_sherpa_dijet_pt->SetBinContent(b,tc07_alpgen_sherpa_ratio);
  //     h_ratio_alpgen_sherpa_dijet_pt->SetBinError(b,tc07_alpgen_sherpa_ratio_err);
  //   }
    

  //   if(tc07_alpgen_nom_bin_n && tc07_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc07_abs_alpgen_iqopt3_err = sqrt(pow(tc07_alpgen_nom_bin_err,2.)+pow(tc07_alpgen_iqopt3_bin_err,2.));
  //     double tc07_rel_alpgen_iqopt3_err = tc07_abs_alpgen_iqopt3_err/(tc07_alpgen_nom_bin_n-tc07_alpgen_iqopt3_bin_n);
  //     double tc07_rel_iqopt3_err = tc07_alpgen_iqopt3_bin_err/tc07_alpgen_iqopt3_bin_n;
      
  //     double tc07_rel_ratio_alpgen_iqopt3_dijet_pt_err = sqrt(pow(tc07_rel_alpgen_iqopt3_err,2.)+pow(tc07_rel_iqopt3_err,2.));

  //     double tc07_alpgen_iqopt3_ratio = (tc07_alpgen_nom_bin_n-tc07_alpgen_iqopt3_bin_n)/tc07_alpgen_iqopt3_bin_n;

  //     double tc07_alpgen_iqopt3_ratio_err = fabs(tc07_rel_ratio_alpgen_iqopt3_dijet_pt_err*tc07_alpgen_iqopt3_ratio);

  //     h_ratio_alpgen_iqopt3_dijet_pt->SetBinContent(b,tc07_alpgen_iqopt3_ratio);
  //     h_ratio_alpgen_iqopt3_dijet_pt->SetBinError(b,tc07_alpgen_iqopt3_ratio_err);
  //   }

    

  //   if(tc07_alpgen_nom_bin_n && tc07_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc07_abs_alpgen_ptjmin10_err = sqrt(pow(tc07_alpgen_nom_bin_err,2.)+pow(tc07_alpgen_ptjmin10_bin_err,2.));
  //     double tc07_rel_alpgen_ptjmin10_err = tc07_abs_alpgen_ptjmin10_err/(tc07_alpgen_nom_bin_n-tc07_alpgen_ptjmin10_bin_n);
  //     double tc07_rel_ptjmin10_err = tc07_alpgen_ptjmin10_bin_err/tc07_alpgen_ptjmin10_bin_n;
      
  //     double tc07_rel_ratio_alpgen_ptjmin10_dijet_pt_err = sqrt(pow(tc07_rel_alpgen_ptjmin10_err,2.)+pow(tc07_rel_ptjmin10_err,2.));

  //     double tc07_alpgen_ptjmin10_ratio = (tc07_alpgen_nom_bin_n-tc07_alpgen_ptjmin10_bin_n)/tc07_alpgen_ptjmin10_bin_n;

  //     double tc07_alpgen_ptjmin10_ratio_err = fabs(tc07_rel_ratio_alpgen_ptjmin10_dijet_pt_err*tc07_alpgen_ptjmin10_ratio);

  //     h_ratio_alpgen_ptjmin10_dijet_pt->SetBinContent(b,tc07_alpgen_ptjmin10_ratio);
  //     h_ratio_alpgen_ptjmin10_dijet_pt->SetBinError(b,tc07_alpgen_ptjmin10_ratio_err);
  //   }
    
  // }


  // h_ratio_alpgen_sherpa_dijet_pt->Draw("PE");
  // h_ratio_alpgen_iqopt3_dijet_pt->Draw("PE sames");
  // h_ratio_alpgen_ptjmin10_dijet_pt->Draw("PE sames");
  
  // tc07->Update();

  // tc07->SaveAs("./plots/latest/elec_dijet_pt.png");
  

  // //NEXT
  
  // //////////////////////////////////////////////////
  // // tc07_5
  // // data_elec_dijet_pt: sherpa/alpgen+wjrw
  // //////////////////////////////////////////////////
  
  // string tc07_5_title = "Pt(dijet) (elec) w/ Data";
  // string tc07_5_name = "tc07_5";
  // TCanvas* tc07_5 = new TCanvas(tc07_5_name.c_str(),tc07_5_title.c_str(),0,0,1920,1200);
  // tc07_5->cd();

  // TPad* tc07_5_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc07_5_pad01->SetTopMargin(0.05);
  // tc07_5_pad01->SetBottomMargin(0.31);
  // tc07_5_pad01->Draw();

  // TPad* tc07_5_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc07_5_pad02->SetBottomMargin(0.0005);
  // tc07_5_pad02->SetLogy();
  // tc07_5_pad02->Draw();
  // tc07_5_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_elec_dijet_pt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_purw_nom_dijet_pt");
  // TH1F* h_alpgen_iqopt3_elec_dijet_pt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_iqopt3_dijet_pt");
  // TH1F* h_alpgen_ptjmin10_elec_dijet_pt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_ptjmin10_dijet_pt");
  // TH1F* h_sherpa_nom_elec_dijet_pt = (TH1F*) wjets_sherpa_file->Get("all/h_elec_purw_nom_dijet_pt");
  // TH1F* h_data_elec_dijet_pt = (TH1F*) data_file->Get("all/h_elec_purw_nom_dijet_pt");

  // TH1F* h_top_elec_dijet_pt = (TH1F*) top_mcatnlo_file->Get("all/h_elec_purw_nom_dijet_pt");
  // TH1F* h_zjets_elec_dijet_pt = (TH1F*) zjets_alpgen_file->Get("all/h_elec_purw_nom_dijet_pt");
  // TH1F* h_vv_elec_dijet_pt = (TH1F*) vv_herwig_file->Get("all/h_elec_purw_nom_dijet_pt");
  // TH1F* h_qcd_elec_dijet_pt = (TH1F*) qcd_file->Get("all/h_elec_purw_nom_dijet_pt");
  
  // h_data_elec_dijet_pt->SetTitle("");
  // h_data_elec_dijet_pt->Draw();
  
  // //Add Backgrounds
  // h_alpgen_nom_elec_dijet_pt->Add(h_top_elec_dijet_pt);
  // h_alpgen_nom_elec_dijet_pt->Add(h_zjets_elec_dijet_pt);
  // h_alpgen_nom_elec_dijet_pt->Add(h_vv_elec_dijet_pt);
  // h_alpgen_nom_elec_dijet_pt->Add(h_qcd_elec_dijet_pt);
  
  // h_alpgen_nom_elec_dijet_pt->SetMarkerStyle(20);
  // h_alpgen_nom_elec_dijet_pt->SetMarkerSize(1.2);
  // h_alpgen_nom_elec_dijet_pt->Draw("PE sames");

  // //Add backgrounds
  // h_alpgen_iqopt3_elec_dijet_pt->Add(h_top_elec_dijet_pt);
  // h_alpgen_iqopt3_elec_dijet_pt->Add(h_zjets_elec_dijet_pt);
  // h_alpgen_iqopt3_elec_dijet_pt->Add(h_vv_elec_dijet_pt);
  // h_alpgen_iqopt3_elec_dijet_pt->Add(h_qcd_elec_dijet_pt);

  // h_alpgen_iqopt3_elec_dijet_pt->SetMarkerStyle(22);
  // h_alpgen_iqopt3_elec_dijet_pt->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_elec_dijet_pt->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_elec_dijet_pt->Draw("PE sames");

  // //Add Backgrounds
  // h_alpgen_ptjmin10_elec_dijet_pt->Add(h_top_elec_dijet_pt);
  // h_alpgen_ptjmin10_elec_dijet_pt->Add(h_zjets_elec_dijet_pt);
  // h_alpgen_ptjmin10_elec_dijet_pt->Add(h_vv_elec_dijet_pt);
  // h_alpgen_ptjmin10_elec_dijet_pt->Add(h_qcd_elec_dijet_pt);

  // h_alpgen_ptjmin10_elec_dijet_pt->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_elec_dijet_pt->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_elec_dijet_pt->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_elec_dijet_pt->Draw("PE sames");

  // //Add Backgrounds
  // h_sherpa_nom_elec_dijet_pt->Add(h_top_elec_dijet_pt);
  // h_sherpa_nom_elec_dijet_pt->Add(h_zjets_elec_dijet_pt);
  // h_sherpa_nom_elec_dijet_pt->Add(h_vv_elec_dijet_pt);
  // h_sherpa_nom_elec_dijet_pt->Add(h_qcd_elec_dijet_pt);

  // h_sherpa_nom_elec_dijet_pt->SetMarkerStyle(20);
  // h_sherpa_nom_elec_dijet_pt->SetMarkerSize(1.2);
  // h_sherpa_nom_elec_dijet_pt->SetMarkerColor(kRed);
  // h_sherpa_nom_elec_dijet_pt->Draw("PE sames");




  // //Legend
  // TLegend* lgnd_tc07_5 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc07_5->SetFillColor(0);
  // lgnd_tc07_5->SetTextSize(0.03);
  // lgnd_tc07_5->SetBorderSize(0);


  // char lgnd_data_elec_dijet_pt_name[20];
  // sprintf(lgnd_data_elec_dijet_pt_name,"%s,  %.2f","DATA",h_data_elec_dijet_pt->Integral());
  // lgnd_tc07_5->AddEntry(h_data_elec_dijet_pt,lgnd_data_elec_dijet_pt_name,"f");

  // char lgnd_alpgen_nom_elec_dijet_pt_name[20];
  // sprintf(lgnd_alpgen_nom_elec_dijet_pt_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_elec_dijet_pt->Integral());
  // lgnd_tc07_5->AddEntry(h_alpgen_nom_elec_dijet_pt,lgnd_alpgen_nom_elec_dijet_pt_name,"p");

  // char lgnd_alpgen_iqopt3_elec_dijet_pt_name[20];
  // sprintf(lgnd_alpgen_iqopt3_elec_dijet_pt_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_elec_dijet_pt->Integral());
  // lgnd_tc07_5->AddEntry(h_alpgen_iqopt3_elec_dijet_pt,lgnd_alpgen_iqopt3_elec_dijet_pt_name,"p");

  // char lgnd_alpgen_ptjmin10_elec_dijet_pt_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_elec_dijet_pt_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_elec_dijet_pt->Integral());
  // lgnd_tc07_5->AddEntry(h_alpgen_ptjmin10_elec_dijet_pt,lgnd_alpgen_ptjmin10_elec_dijet_pt_name,"p");

  // char lgnd_sherpa_nom_elec_dijet_pt_name[20];
  // sprintf(lgnd_sherpa_nom_elec_dijet_pt_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_elec_dijet_pt->Integral());
  // lgnd_tc07_5->AddEntry(h_sherpa_nom_elec_dijet_pt,lgnd_sherpa_nom_elec_dijet_pt_name,"p");

  // lgnd_tc07_5->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc07_5_pad01->cd();
  // tc07_5_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_elec_dijet_pt->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_elec_dijet_pt->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_elec_dijet_pt->GetXaxis())->GetXmax();

  // // data-alpgen(nom)/alpgen(nom)
  // string tc07_5_ratio_data_alpgen_dijet_pt_name = "tc07_5_ratio_data_alpgen_dijet_pt";
  // TH1F* h_ratio_data_alpgen_dijet_pt = new TH1F(tc07_5_ratio_data_alpgen_dijet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_dijet_pt->SetMarkerStyle(8);
  // //h_ratio_data_alpgen_dijet_pt->SetMarkerColor(kRed);

  // TAxis* h_ratio_data_alpgen_dijet_pt_xaxis = h_ratio_data_alpgen_dijet_pt->GetXaxis();
  // TAxis* h_ratio_data_alpgen_dijet_pt_yaxis = h_ratio_data_alpgen_dijet_pt->GetYaxis();
  
  // h_ratio_data_alpgen_dijet_pt_xaxis->SetLabelSize(0.08);
  // h_ratio_data_alpgen_dijet_pt_yaxis->SetLabelSize(0.08);

  // h_ratio_data_alpgen_dijet_pt_xaxis->SetTitle("Pt(dijet)");
  // h_ratio_data_alpgen_dijet_pt_xaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_dijet_pt_yaxis->SetNdivisions(4,4,4);
  // h_ratio_data_alpgen_dijet_pt_yaxis->SetTitle("(data-MC)/MC");
  // h_ratio_data_alpgen_dijet_pt_yaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_dijet_pt_yaxis->SetTitleOffset(0.36);
  // h_ratio_data_alpgen_dijet_pt_yaxis->SetRangeUser(-1,1);

  // // data-sherpa(nom)/sherpa(nom)
  // string tc07_5_ratio_data_sherpa_dijet_pt_name = "tc07_5_ratio_data_sherpa_dijet_pt";
  // TH1F* h_ratio_data_sherpa_dijet_pt = new TH1F(tc07_5_ratio_data_sherpa_dijet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_sherpa_dijet_pt->SetMarkerStyle(8);
  // h_ratio_data_sherpa_dijet_pt->SetMarkerColor(kRed);


  // // data-alpgen(iqopt3)/alpgen(iqopt3)
  // string tc07_5_ratio_data_alpgen_iqopt3_dijet_pt_name = "tc07_5_ratio_data_alpgen_iqopt3_dijet_pt";
  // TH1F* h_ratio_data_alpgen_iqopt3_dijet_pt = new TH1F(tc07_5_ratio_data_alpgen_iqopt3_dijet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_iqopt3_dijet_pt->SetMarkerStyle(8);
  // h_ratio_data_alpgen_iqopt3_dijet_pt->SetMarkerColor(kGreen);

  // // data-alpgen(ptjmin10)/alpgen(ptjmin10)
  // string tc07_5_ratio_data_alpgen_ptjmin10_dijet_pt_name = "tc07_5_ratio_data_alpgen_ptjmin10_dijet_pt";
  // TH1F* h_ratio_data_alpgen_ptjmin10_dijet_pt = new TH1F(tc07_5_ratio_data_alpgen_ptjmin10_dijet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_ptjmin10_dijet_pt->SetMarkerStyle(8);
  // h_ratio_data_alpgen_ptjmin10_dijet_pt->SetMarkerColor(kBlue);

  

  
  // // // alp-iqopt3/iqopt3
  // // string tc07_5_ratio_alpgen_iqopt3_lead_jet_pt_name = "tc07_5_ratio_alpgen_iqopt3_lead_jet_pt";
  // // TH1F* h_ratio_alpgen_iqopt3_lead_jet_pt = new TH1F(tc07_5_ratio_alpgen_iqopt3_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerStyle(8);
  // // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerColor(kGreen);

  
  // // // alp-ptjmin10/ptjmin10
  // // string tc07_5_ratio_alpgen_ptjmin10_lead_jet_pt_name = "tc07_5_ratio_alpgen_ptjmin10_lead_jet_pt";
  // // TH1F* h_ratio_alpgen_ptjmin10_lead_jet_pt = new TH1F(tc07_5_ratio_alpgen_ptjmin10_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerStyle(8);
  // // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerColor(kBlue);


  
  // double tc07_5_data_alpgen_ratio=0.;
  // double tc07_5_data_sherpa_ratio=0.;
  // double tc07_5_data_alpgen_iqopt3_ratio=0.;
  // double tc07_5_data_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc07_5_alpgen_nom_bin_n=h_alpgen_nom_elec_dijet_pt->GetBinContent(b);
  //   double tc07_5_alpgen_nom_bin_err=h_alpgen_nom_elec_dijet_pt->GetBinError(b);    

  //   double tc07_5_data_bin_n=h_data_elec_dijet_pt->GetBinContent(b);
  //   double tc07_5_data_bin_err=h_data_elec_dijet_pt->GetBinError(b);    

  //   double tc07_5_sherpa_nom_bin_n=h_sherpa_nom_elec_dijet_pt->GetBinContent(b);
  //   double tc07_5_sherpa_nom_bin_err=h_sherpa_nom_elec_dijet_pt->GetBinError(b);    

  //   double tc07_5_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_elec_dijet_pt->GetBinContent(b);
  //   double tc07_5_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_elec_dijet_pt->GetBinError(b);

  //   double tc07_5_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_elec_dijet_pt->GetBinContent(b);
  //   double tc07_5_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_elec_dijet_pt->GetBinError(b);



  //   if(tc07_5_data_bin_n && tc07_5_alpgen_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc07_5_abs_data_alpgen_err = sqrt(pow(tc07_5_data_bin_err,2.)+pow(tc07_5_alpgen_nom_bin_err,2.));
  //     double tc07_5_rel_data_alpgen_err = tc07_5_abs_data_alpgen_err/(tc07_5_data_bin_n-tc07_5_alpgen_nom_bin_n);
  //     double tc07_5_rel_alpgen_err = tc07_5_alpgen_nom_bin_err/tc07_5_alpgen_nom_bin_n;
      
  //     double tc07_5_rel_ratio_data_alpgen_dijet_pt_err = sqrt(pow(tc07_5_rel_data_alpgen_err,2.)+pow(tc07_5_rel_alpgen_err,2.));

  //     double tc07_5_data_alpgen_ratio = (tc07_5_data_bin_n-tc07_5_alpgen_nom_bin_n)/tc07_5_alpgen_nom_bin_n;

  //     double tc07_5_data_alpgen_ratio_err = fabs(tc07_5_rel_ratio_data_alpgen_dijet_pt_err*tc07_5_data_alpgen_ratio);

  //     h_ratio_data_alpgen_dijet_pt->SetBinContent(b,tc07_5_data_alpgen_ratio);
  //     h_ratio_data_alpgen_dijet_pt->SetBinError(b,tc07_5_data_alpgen_ratio_err);
  //   }
    

  //   if(tc07_5_data_bin_n && tc07_5_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc07_5_abs_data_sherpa_err = sqrt(pow(tc07_5_data_bin_err,2.)+pow(tc07_5_sherpa_nom_bin_err,2.));
  //     double tc07_5_rel_data_sherpa_err = tc07_5_abs_data_sherpa_err/(tc07_5_data_bin_n-tc07_5_sherpa_nom_bin_n);
  //     double tc07_5_rel_sherpa_err = tc07_5_sherpa_nom_bin_err/tc07_5_sherpa_nom_bin_n;
      
  //     double tc07_5_rel_ratio_data_sherpa_dijet_pt_err = sqrt(pow(tc07_5_rel_data_sherpa_err,2.)+pow(tc07_5_rel_sherpa_err,2.));

  //     double tc07_5_data_sherpa_ratio = (tc07_5_data_bin_n-tc07_5_sherpa_nom_bin_n)/tc07_5_sherpa_nom_bin_n;

  //     double tc07_5_data_sherpa_ratio_err = fabs(tc07_5_rel_ratio_data_sherpa_dijet_pt_err*tc07_5_data_sherpa_ratio);

  //     h_ratio_data_sherpa_dijet_pt->SetBinContent(b,tc07_5_data_sherpa_ratio);
  //     h_ratio_data_sherpa_dijet_pt->SetBinError(b,tc07_5_data_sherpa_ratio_err);
  //   }
    

  //   if(tc07_5_data_bin_n && tc07_5_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc07_5_abs_data_alpgen_iqopt3_err = sqrt(pow(tc07_5_data_bin_err,2.)+pow(tc07_5_alpgen_iqopt3_bin_err,2.));
  //     double tc07_5_rel_data_alpgen_iqopt3_err = tc07_5_abs_data_alpgen_iqopt3_err/(tc07_5_data_bin_n-tc07_5_alpgen_iqopt3_bin_n);
  //     double tc07_5_rel_alpgen_iqopt3_err = tc07_5_alpgen_iqopt3_bin_err/tc07_5_alpgen_iqopt3_bin_n;
      
  //     double tc07_5_rel_ratio_data_alpgen_iqopt3_dijet_pt_err = sqrt(pow(tc07_5_rel_data_alpgen_iqopt3_err,2.)+pow(tc07_5_rel_alpgen_iqopt3_err,2.));

  //     double tc07_5_data_alpgen_iqopt3_ratio = (tc07_5_data_bin_n-tc07_5_alpgen_iqopt3_bin_n)/tc07_5_alpgen_iqopt3_bin_n;

  //     double tc07_5_data_alpgen_iqopt3_ratio_err = fabs(tc07_5_rel_ratio_data_alpgen_iqopt3_dijet_pt_err*tc07_5_data_alpgen_iqopt3_ratio);

  //     h_ratio_data_alpgen_iqopt3_dijet_pt->SetBinContent(b,tc07_5_data_alpgen_iqopt3_ratio);
  //     h_ratio_data_alpgen_iqopt3_dijet_pt->SetBinError(b,tc07_5_data_alpgen_iqopt3_ratio_err);
  //   }
    
  //   if(tc07_5_data_bin_n && tc07_5_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc07_5_abs_data_alpgen_ptjmin10_err = sqrt(pow(tc07_5_data_bin_err,2.)+pow(tc07_5_alpgen_ptjmin10_bin_err,2.));
  //     double tc07_5_rel_data_alpgen_ptjmin10_err = tc07_5_abs_data_alpgen_ptjmin10_err/(tc07_5_data_bin_n-tc07_5_alpgen_ptjmin10_bin_n);
  //     double tc07_5_rel_alpgen_ptjmin10_err = tc07_5_alpgen_ptjmin10_bin_err/tc07_5_alpgen_ptjmin10_bin_n;
      
  //     double tc07_5_rel_ratio_data_alpgen_ptjmin10_dijet_pt_err = sqrt(pow(tc07_5_rel_data_alpgen_ptjmin10_err,2.)+pow(tc07_5_rel_alpgen_ptjmin10_err,2.));

  //     double tc07_5_data_alpgen_ptjmin10_ratio = (tc07_5_data_bin_n-tc07_5_alpgen_ptjmin10_bin_n)/tc07_5_alpgen_ptjmin10_bin_n;

  //     double tc07_5_data_alpgen_ptjmin10_ratio_err = fabs(tc07_5_rel_ratio_data_alpgen_ptjmin10_dijet_pt_err*tc07_5_data_alpgen_ptjmin10_ratio);

  //     h_ratio_data_alpgen_ptjmin10_dijet_pt->SetBinContent(b,tc07_5_data_alpgen_ptjmin10_ratio);
  //     h_ratio_data_alpgen_ptjmin10_dijet_pt->SetBinError(b,tc07_5_data_alpgen_ptjmin10_ratio_err);
  //   }
  // }


  // h_ratio_data_alpgen_dijet_pt->Draw("PE");
  // h_ratio_data_sherpa_dijet_pt->Draw("PE sames");
  // h_ratio_data_alpgen_iqopt3_dijet_pt->Draw("PE sames");
  // h_ratio_data_alpgen_ptjmin10_dijet_pt->Draw("PE sames");
  
  // //  h_ratio_alpgen_iqopt3_dijet_pt->Draw("PE sames");
  // //  h_ratio_alpgen_ptjmin10_dijet_pt->Draw("PE sames");
  
  // tc07_5->Update();
  // tc07_5->SaveAs("./plots/latest/data_elec_dijet_pt.png");
    
  // //NEXT

  // ////////////////////////////////////////////////// 
  // // tc08
  // // muon_dijet_pt: tc08_sherpa/alpgen+wjrw
  // ////////////////////////////////////////////////// 

  // string tc08_title = "Pt(dijet) (muon)";
  // string tc08_name = "tc08";
  // TCanvas* tc08 = new TCanvas(tc08_name.c_str(),tc08_title.c_str(),0,0,1920,1200);
  // tc08->cd();

  // TPad* tc08_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc08_pad01->SetTopMargin(0.05);
  // tc08_pad01->SetBottomMargin(0.31);
  // tc08_pad01->Draw();

  // TPad* tc08_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc08_pad02->SetBottomMargin(0.0005);
  // tc08_pad02->SetLogy();
  // tc08_pad02->Draw();
  // tc08_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_muon_dijet_pt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_purw_nom_dijet_pt");
  // TH1F* h_alpgen_iqopt3_muon_dijet_pt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_iqopt3_dijet_pt");
  // TH1F* h_alpgen_ptjmin10_muon_dijet_pt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_ptjmin10_dijet_pt");
  // TH1F* h_sherpa_nom_muon_dijet_pt = (TH1F*) wjets_sherpa_file->Get("all/h_muon_purw_nom_dijet_pt");

  // //h_alpgen_nom_muon_dijet_pt->SetLineWidth(2);
  // h_alpgen_nom_muon_dijet_pt->SetMarkerStyle(20);
  // h_alpgen_nom_muon_dijet_pt->SetMarkerSize(1.2);
  // h_alpgen_nom_muon_dijet_pt->SetTitle("");
  // h_alpgen_nom_muon_dijet_pt->Draw("PE");

  // //h_alpgen_iqopt3_muon_dijet_pt->SetLineColor(kGreen);
  // h_alpgen_iqopt3_muon_dijet_pt->SetMarkerStyle(22);
  // h_alpgen_iqopt3_muon_dijet_pt->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_muon_dijet_pt->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_muon_dijet_pt->Draw("PE sames");

  // //  h_alpgen_ptjmin10_muon_dijet_pt->SetLineColor(kBlue);
  // h_alpgen_ptjmin10_muon_dijet_pt->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_muon_dijet_pt->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_muon_dijet_pt->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_muon_dijet_pt->Draw("PE sames");

  // // h_sherpa_nom_muon_dijet_pt->SetLineWidth(1.2);
  // // h_sherpa_nom_muon_dijet_pt->SetLineColor(kRed);
  // h_sherpa_nom_muon_dijet_pt->SetMarkerStyle(20);
  // h_sherpa_nom_muon_dijet_pt->SetMarkerSize(1.2);
  // h_sherpa_nom_muon_dijet_pt->SetMarkerColor(kRed);
  // h_sherpa_nom_muon_dijet_pt->Draw("PE sames");


  // //Legend
  // TLegend* lgnd_tc08 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc08->SetFillColor(0);
  // lgnd_tc08->SetTextSize(0.03);
  // lgnd_tc08->SetBorderSize(0);

  // char lgnd_alpgen_nom_muon_dijet_pt_name[20];
  // sprintf(lgnd_alpgen_nom_muon_dijet_pt_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_muon_dijet_pt->Integral());
  // lgnd_tc08->AddEntry(h_alpgen_nom_muon_dijet_pt,lgnd_alpgen_nom_muon_dijet_pt_name,"p");

  // char lgnd_alpgen_iqopt3_muon_dijet_pt_name[20];
  // sprintf(lgnd_alpgen_iqopt3_muon_dijet_pt_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_muon_dijet_pt->Integral());
  // lgnd_tc08->AddEntry(h_alpgen_iqopt3_muon_dijet_pt,lgnd_alpgen_iqopt3_muon_dijet_pt_name,"p");

  // char lgnd_alpgen_ptjmin10_muon_dijet_pt_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_muon_dijet_pt_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_muon_dijet_pt->Integral());
  // lgnd_tc08->AddEntry(h_alpgen_ptjmin10_muon_dijet_pt,lgnd_alpgen_ptjmin10_muon_dijet_pt_name,"p");

  // char lgnd_sherpa_nom_muon_dijet_pt_name[20];
  // sprintf(lgnd_sherpa_nom_muon_dijet_pt_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_muon_dijet_pt->Integral());
  // lgnd_tc08->AddEntry(h_sherpa_nom_muon_dijet_pt,lgnd_sherpa_nom_muon_dijet_pt_name,"p");

  // lgnd_tc08->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc08_pad01->cd();
  // tc08_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_muon_dijet_pt->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_muon_dijet_pt->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_muon_dijet_pt->GetXaxis())->GetXmax();

  // // alp-sherp/sherp
  // string tc08_ratio_alpgen_sherpa_dijet_pt_name = "tc08_ratio_alpgen_sherpa_dijet_pt";
  // TH1F* h_ratio_alpgen_sherpa_dijet_pt = new TH1F(tc08_ratio_alpgen_sherpa_dijet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_sherpa_dijet_pt->SetMarkerStyle(8);
  // h_ratio_alpgen_sherpa_dijet_pt->SetMarkerColor(kRed);

  // TAxis* h_ratio_alpgen_sherpa_dijet_pt_xaxis = h_ratio_alpgen_sherpa_dijet_pt->GetXaxis();
  // TAxis* h_ratio_alpgen_sherpa_dijet_pt_yaxis = h_ratio_alpgen_sherpa_dijet_pt->GetYaxis();
  
  // h_ratio_alpgen_sherpa_dijet_pt_xaxis->SetLabelSize(0.08);
  // h_ratio_alpgen_sherpa_dijet_pt_yaxis->SetLabelSize(0.08);

  // h_ratio_alpgen_sherpa_dijet_pt_xaxis->SetTitle("Pt(dijet)");
  // h_ratio_alpgen_sherpa_dijet_pt_xaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_dijet_pt_yaxis->SetNdivisions(4,4,4);
  // h_ratio_alpgen_sherpa_dijet_pt_yaxis->SetTitle("(alpgen-MC)/MC");
  // h_ratio_alpgen_sherpa_dijet_pt_yaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_dijet_pt_yaxis->SetTitleOffset(0.36);
  // h_ratio_alpgen_sherpa_dijet_pt_yaxis->SetRangeUser(-1,1);

  
  // // alp-iqopt3/iqopt3
  // string tc08_ratio_alpgen_iqopt3_dijet_pt_name = "tc08_ratio_alpgen_iqopt3_dijet_pt";
  // TH1F* h_ratio_alpgen_iqopt3_dijet_pt = new TH1F(tc08_ratio_alpgen_iqopt3_dijet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_iqopt3_dijet_pt->SetMarkerStyle(8);
  // h_ratio_alpgen_iqopt3_dijet_pt->SetMarkerColor(kGreen);

  
  // // alp-ptjmin10/ptjmin10
  // string tc08_ratio_alpgen_ptjmin10_dijet_pt_name = "tc08_ratio_alpgen_ptjmin10_dijet_pt";
  // TH1F* h_ratio_alpgen_ptjmin10_dijet_pt = new TH1F(tc08_ratio_alpgen_ptjmin10_dijet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_ptjmin10_dijet_pt->SetMarkerStyle(8);
  // h_ratio_alpgen_ptjmin10_dijet_pt->SetMarkerColor(kBlue);


  
  // double tc08_alpgen_sherpa_ratio=0.;
  // double tc08_alpgen_iqopt3_ratio=0.;
  // double tc08_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc08_alpgen_nom_bin_n=h_alpgen_nom_muon_dijet_pt->GetBinContent(b);
  //   double tc08_alpgen_nom_bin_err=h_alpgen_nom_muon_dijet_pt->GetBinError(b);    

  //   double tc08_sherpa_nom_bin_n=h_sherpa_nom_muon_dijet_pt->GetBinContent(b);
  //   double tc08_sherpa_nom_bin_err=h_sherpa_nom_muon_dijet_pt->GetBinError(b);    

  //   double tc08_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_muon_dijet_pt->GetBinContent(b);
  //   double tc08_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_muon_dijet_pt->GetBinError(b);

  //   double tc08_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_muon_dijet_pt->GetBinContent(b);
  //   double tc08_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_muon_dijet_pt->GetBinError(b);



  //   if(tc08_alpgen_nom_bin_n && tc08_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc08_abs_alpgen_sherpa_err = sqrt(pow(tc08_alpgen_nom_bin_err,2.)+pow(tc08_sherpa_nom_bin_err,2.));
  //     double tc08_rel_alpgen_sherpa_err = tc08_abs_alpgen_sherpa_err/(tc08_alpgen_nom_bin_n-tc08_sherpa_nom_bin_n);
  //     double tc08_rel_sherpa_err = tc08_sherpa_nom_bin_err/tc08_sherpa_nom_bin_n;
      
  //     double tc08_rel_ratio_alpgen_sherpa_dijet_pt_err = sqrt(pow(tc08_rel_alpgen_sherpa_err,2.)+pow(tc08_rel_sherpa_err,2.));

  //     double tc08_alpgen_sherpa_ratio = (tc08_alpgen_nom_bin_n-tc08_sherpa_nom_bin_n)/tc08_sherpa_nom_bin_n;

  //     double tc08_alpgen_sherpa_ratio_err = fabs(tc08_rel_ratio_alpgen_sherpa_dijet_pt_err*tc08_alpgen_sherpa_ratio);

  //     h_ratio_alpgen_sherpa_dijet_pt->SetBinContent(b,tc08_alpgen_sherpa_ratio);
  //     h_ratio_alpgen_sherpa_dijet_pt->SetBinError(b,tc08_alpgen_sherpa_ratio_err);
  //   }
    

  //   if(tc08_alpgen_nom_bin_n && tc08_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc08_abs_alpgen_iqopt3_err = sqrt(pow(tc08_alpgen_nom_bin_err,2.)+pow(tc08_alpgen_iqopt3_bin_err,2.));
  //     double tc08_rel_alpgen_iqopt3_err = tc08_abs_alpgen_iqopt3_err/(tc08_alpgen_nom_bin_n-tc08_alpgen_iqopt3_bin_n);
  //     double tc08_rel_iqopt3_err = tc08_alpgen_iqopt3_bin_err/tc08_alpgen_iqopt3_bin_n;
      
  //     double tc08_rel_ratio_alpgen_iqopt3_dijet_pt_err = sqrt(pow(tc08_rel_alpgen_iqopt3_err,2.)+pow(tc08_rel_iqopt3_err,2.));

  //     double tc08_alpgen_iqopt3_ratio = (tc08_alpgen_nom_bin_n-tc08_alpgen_iqopt3_bin_n)/tc08_alpgen_iqopt3_bin_n;

  //     double tc08_alpgen_iqopt3_ratio_err = fabs(tc08_rel_ratio_alpgen_iqopt3_dijet_pt_err*tc08_alpgen_iqopt3_ratio);

  //     h_ratio_alpgen_iqopt3_dijet_pt->SetBinContent(b,tc08_alpgen_iqopt3_ratio);
  //     h_ratio_alpgen_iqopt3_dijet_pt->SetBinError(b,tc08_alpgen_iqopt3_ratio_err);
  //   }

    

  //   if(tc08_alpgen_nom_bin_n && tc08_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc08_abs_alpgen_ptjmin10_err = sqrt(pow(tc08_alpgen_nom_bin_err,2.)+pow(tc08_alpgen_ptjmin10_bin_err,2.));
  //     double tc08_rel_alpgen_ptjmin10_err = tc08_abs_alpgen_ptjmin10_err/(tc08_alpgen_nom_bin_n-tc08_alpgen_ptjmin10_bin_n);
  //     double tc08_rel_ptjmin10_err = tc08_alpgen_ptjmin10_bin_err/tc08_alpgen_ptjmin10_bin_n;
      
  //     double tc08_rel_ratio_alpgen_ptjmin10_dijet_pt_err = sqrt(pow(tc08_rel_alpgen_ptjmin10_err,2.)+pow(tc08_rel_ptjmin10_err,2.));

  //     double tc08_alpgen_ptjmin10_ratio = (tc08_alpgen_nom_bin_n-tc08_alpgen_ptjmin10_bin_n)/tc08_alpgen_ptjmin10_bin_n;

  //     double tc08_alpgen_ptjmin10_ratio_err = fabs(tc08_rel_ratio_alpgen_ptjmin10_dijet_pt_err*tc08_alpgen_ptjmin10_ratio);

  //     h_ratio_alpgen_ptjmin10_dijet_pt->SetBinContent(b,tc08_alpgen_ptjmin10_ratio);
  //     h_ratio_alpgen_ptjmin10_dijet_pt->SetBinError(b,tc08_alpgen_ptjmin10_ratio_err);
  //   }
    
  // }


  // h_ratio_alpgen_sherpa_dijet_pt->Draw("PE");
  // h_ratio_alpgen_iqopt3_dijet_pt->Draw("PE sames");
  // h_ratio_alpgen_ptjmin10_dijet_pt->Draw("PE sames");
  
  // tc08->Update();

  // tc08->SaveAs("./plots/latest/muon_dijet_pt.png");
  
  // //NEXT  

  // //////////////////////////////////////////////////
  // // tc08_5
  // // data_muon_dijet_pt: sherpa/alpgen+wjrw
  // //////////////////////////////////////////////////
  
  // string tc08_5_title = "Pt(dijet) (muon) w/ Data";
  // string tc08_5_name = "tc08_5";
  // TCanvas* tc08_5 = new TCanvas(tc08_5_name.c_str(),tc08_5_title.c_str(),0,0,1920,1200);
  // tc08_5->cd();

  // TPad* tc08_5_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc08_5_pad01->SetTopMargin(0.05);
  // tc08_5_pad01->SetBottomMargin(0.31);
  // tc08_5_pad01->Draw();

  // TPad* tc08_5_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc08_5_pad02->SetBottomMargin(0.0005);
  // tc08_5_pad02->SetLogy();
  // tc08_5_pad02->Draw();
  // tc08_5_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_muon_dijet_pt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_purw_nom_dijet_pt");
  // TH1F* h_alpgen_iqopt3_muon_dijet_pt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_iqopt3_dijet_pt");
  // TH1F* h_alpgen_ptjmin10_muon_dijet_pt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_ptjmin10_dijet_pt");
  // TH1F* h_sherpa_nom_muon_dijet_pt = (TH1F*) wjets_sherpa_file->Get("all/h_muon_purw_nom_dijet_pt");
  // TH1F* h_data_muon_dijet_pt = (TH1F*) data_file->Get("all/h_muon_purw_nom_dijet_pt");

  // TH1F* h_top_muon_dijet_pt = (TH1F*) top_mcatnlo_file->Get("all/h_muon_purw_nom_dijet_pt");
  // TH1F* h_zjets_muon_dijet_pt = (TH1F*) zjets_alpgen_file->Get("all/h_muon_purw_nom_dijet_pt");
  // TH1F* h_vv_muon_dijet_pt = (TH1F*) vv_herwig_file->Get("all/h_muon_purw_nom_dijet_pt");
  // TH1F* h_qcd_muon_dijet_pt = (TH1F*) qcd_file->Get("all/h_muon_purw_nom_dijet_pt");
  
  // h_data_muon_dijet_pt->SetTitle("");
  // h_data_muon_dijet_pt->Draw();
  
  // //Add Backgrounds
  // h_alpgen_nom_muon_dijet_pt->Add(h_top_muon_dijet_pt);
  // h_alpgen_nom_muon_dijet_pt->Add(h_zjets_muon_dijet_pt);
  // h_alpgen_nom_muon_dijet_pt->Add(h_vv_muon_dijet_pt);
  // h_alpgen_nom_muon_dijet_pt->Add(h_qcd_muon_dijet_pt);
  
  // h_alpgen_nom_muon_dijet_pt->SetMarkerStyle(20);
  // h_alpgen_nom_muon_dijet_pt->SetMarkerSize(1.2);
  // h_alpgen_nom_muon_dijet_pt->Draw("PE sames");

  // //Add backgrounds
  // h_alpgen_iqopt3_muon_dijet_pt->Add(h_top_muon_dijet_pt);
  // h_alpgen_iqopt3_muon_dijet_pt->Add(h_zjets_muon_dijet_pt);
  // h_alpgen_iqopt3_muon_dijet_pt->Add(h_vv_muon_dijet_pt);
  // h_alpgen_iqopt3_muon_dijet_pt->Add(h_qcd_muon_dijet_pt);

  // h_alpgen_iqopt3_muon_dijet_pt->SetMarkerStyle(22);
  // h_alpgen_iqopt3_muon_dijet_pt->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_muon_dijet_pt->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_muon_dijet_pt->Draw("PE sames");

  // //Add Backgrounds
  // h_alpgen_ptjmin10_muon_dijet_pt->Add(h_top_muon_dijet_pt);
  // h_alpgen_ptjmin10_muon_dijet_pt->Add(h_zjets_muon_dijet_pt);
  // h_alpgen_ptjmin10_muon_dijet_pt->Add(h_vv_muon_dijet_pt);
  // h_alpgen_ptjmin10_muon_dijet_pt->Add(h_qcd_muon_dijet_pt);

  // h_alpgen_ptjmin10_muon_dijet_pt->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_muon_dijet_pt->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_muon_dijet_pt->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_muon_dijet_pt->Draw("PE sames");

  // //Add Backgrounds
  // h_sherpa_nom_muon_dijet_pt->Add(h_top_muon_dijet_pt);
  // h_sherpa_nom_muon_dijet_pt->Add(h_zjets_muon_dijet_pt);
  // h_sherpa_nom_muon_dijet_pt->Add(h_vv_muon_dijet_pt);
  // h_sherpa_nom_muon_dijet_pt->Add(h_qcd_muon_dijet_pt);

  // h_sherpa_nom_muon_dijet_pt->SetMarkerStyle(20);
  // h_sherpa_nom_muon_dijet_pt->SetMarkerSize(1.2);
  // h_sherpa_nom_muon_dijet_pt->SetMarkerColor(kRed);
  // h_sherpa_nom_muon_dijet_pt->Draw("PE sames");




  // //Legend
  // TLegend* lgnd_tc08_5 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc08_5->SetFillColor(0);
  // lgnd_tc08_5->SetTextSize(0.03);
  // lgnd_tc08_5->SetBorderSize(0);

  // char lgnd_data_muon_dijet_pt_name[20];
  // sprintf(lgnd_data_muon_dijet_pt_name,"%s,  %.2f","DATA",h_data_muon_dijet_pt->Integral());
  // lgnd_tc08_5->AddEntry(h_data_muon_dijet_pt,lgnd_data_muon_dijet_pt_name,"f");

  // char lgnd_alpgen_nom_muon_dijet_pt_name[20];
  // sprintf(lgnd_alpgen_nom_muon_dijet_pt_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_muon_dijet_pt->Integral());
  // lgnd_tc08_5->AddEntry(h_alpgen_nom_muon_dijet_pt,lgnd_alpgen_nom_muon_dijet_pt_name,"p");

  // char lgnd_alpgen_iqopt3_muon_dijet_pt_name[20];
  // sprintf(lgnd_alpgen_iqopt3_muon_dijet_pt_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_muon_dijet_pt->Integral());
  // lgnd_tc08_5->AddEntry(h_alpgen_iqopt3_muon_dijet_pt,lgnd_alpgen_iqopt3_muon_dijet_pt_name,"p");

  // char lgnd_alpgen_ptjmin10_muon_dijet_pt_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_muon_dijet_pt_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_muon_dijet_pt->Integral());
  // lgnd_tc08_5->AddEntry(h_alpgen_ptjmin10_muon_dijet_pt,lgnd_alpgen_ptjmin10_muon_dijet_pt_name,"p");

  // char lgnd_sherpa_nom_muon_dijet_pt_name[20];
  // sprintf(lgnd_sherpa_nom_muon_dijet_pt_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_muon_dijet_pt->Integral());
  // lgnd_tc08_5->AddEntry(h_sherpa_nom_muon_dijet_pt,lgnd_sherpa_nom_muon_dijet_pt_name,"p");

  // lgnd_tc08_5->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc08_5_pad01->cd();
  // tc08_5_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_muon_dijet_pt->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_muon_dijet_pt->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_muon_dijet_pt->GetXaxis())->GetXmax();

  // // data-alpgen(nom)/alpgen(nom)
  // string tc08_5_ratio_data_alpgen_dijet_pt_name = "tc08_5_ratio_data_alpgen_dijet_pt";
  // TH1F* h_ratio_data_alpgen_dijet_pt = new TH1F(tc08_5_ratio_data_alpgen_dijet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_dijet_pt->SetMarkerStyle(8);
  // //h_ratio_data_alpgen_dijet_pt->SetMarkerColor(kRed);

  // TAxis* h_ratio_data_alpgen_dijet_pt_xaxis = h_ratio_data_alpgen_dijet_pt->GetXaxis();
  // TAxis* h_ratio_data_alpgen_dijet_pt_yaxis = h_ratio_data_alpgen_dijet_pt->GetYaxis();
  
  // h_ratio_data_alpgen_dijet_pt_xaxis->SetLabelSize(0.08);
  // h_ratio_data_alpgen_dijet_pt_yaxis->SetLabelSize(0.08);

  // h_ratio_data_alpgen_dijet_pt_xaxis->SetTitle("Pt(dijet)");
  // h_ratio_data_alpgen_dijet_pt_xaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_dijet_pt_yaxis->SetNdivisions(4,4,4);
  // h_ratio_data_alpgen_dijet_pt_yaxis->SetTitle("(data-MC)/MC");
  // h_ratio_data_alpgen_dijet_pt_yaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_dijet_pt_yaxis->SetTitleOffset(0.36);
  // h_ratio_data_alpgen_dijet_pt_yaxis->SetRangeUser(-1,1);

  // // data-sherpa(nom)/sherpa(nom)
  // string tc08_5_ratio_data_sherpa_dijet_pt_name = "tc08_5_ratio_data_sherpa_dijet_pt";
  // TH1F* h_ratio_data_sherpa_dijet_pt = new TH1F(tc08_5_ratio_data_sherpa_dijet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_sherpa_dijet_pt->SetMarkerStyle(8);
  // h_ratio_data_sherpa_dijet_pt->SetMarkerColor(kRed);


  // // data-alpgen(iqopt3)/alpgen(iqopt3)
  // string tc08_5_ratio_data_alpgen_iqopt3_dijet_pt_name = "tc08_5_ratio_data_alpgen_iqopt3_dijet_pt";
  // TH1F* h_ratio_data_alpgen_iqopt3_dijet_pt = new TH1F(tc08_5_ratio_data_alpgen_iqopt3_dijet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_iqopt3_dijet_pt->SetMarkerStyle(8);
  // h_ratio_data_alpgen_iqopt3_dijet_pt->SetMarkerColor(kGreen);

  // // data-alpgen(ptjmin10)/alpgen(ptjmin10)
  // string tc08_5_ratio_data_alpgen_ptjmin10_dijet_pt_name = "tc08_5_ratio_data_alpgen_ptjmin10_dijet_pt";
  // TH1F* h_ratio_data_alpgen_ptjmin10_dijet_pt = new TH1F(tc08_5_ratio_data_alpgen_ptjmin10_dijet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_ptjmin10_dijet_pt->SetMarkerStyle(8);
  // h_ratio_data_alpgen_ptjmin10_dijet_pt->SetMarkerColor(kBlue);

  

  
  // // // alp-iqopt3/iqopt3
  // // string tc08_5_ratio_alpgen_iqopt3_lead_jet_pt_name = "tc08_5_ratio_alpgen_iqopt3_lead_jet_pt";
  // // TH1F* h_ratio_alpgen_iqopt3_lead_jet_pt = new TH1F(tc08_5_ratio_alpgen_iqopt3_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerStyle(8);
  // // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerColor(kGreen);

  
  // // // alp-ptjmin10/ptjmin10
  // // string tc08_5_ratio_alpgen_ptjmin10_lead_jet_pt_name = "tc08_5_ratio_alpgen_ptjmin10_lead_jet_pt";
  // // TH1F* h_ratio_alpgen_ptjmin10_lead_jet_pt = new TH1F(tc08_5_ratio_alpgen_ptjmin10_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerStyle(8);
  // // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerColor(kBlue);


  
  // double tc08_5_data_alpgen_ratio=0.;
  // double tc08_5_data_sherpa_ratio=0.;
  // double tc08_5_data_alpgen_iqopt3_ratio=0.;
  // double tc08_5_data_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc08_5_alpgen_nom_bin_n=h_alpgen_nom_muon_dijet_pt->GetBinContent(b);
  //   double tc08_5_alpgen_nom_bin_err=h_alpgen_nom_muon_dijet_pt->GetBinError(b);    

  //   double tc08_5_data_bin_n=h_data_muon_dijet_pt->GetBinContent(b);
  //   double tc08_5_data_bin_err=h_data_muon_dijet_pt->GetBinError(b);    

  //   double tc08_5_sherpa_nom_bin_n=h_sherpa_nom_muon_dijet_pt->GetBinContent(b);
  //   double tc08_5_sherpa_nom_bin_err=h_sherpa_nom_muon_dijet_pt->GetBinError(b);    

  //   double tc08_5_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_muon_dijet_pt->GetBinContent(b);
  //   double tc08_5_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_muon_dijet_pt->GetBinError(b);

  //   double tc08_5_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_muon_dijet_pt->GetBinContent(b);
  //   double tc08_5_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_muon_dijet_pt->GetBinError(b);



  //   if(tc08_5_data_bin_n && tc08_5_alpgen_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc08_5_abs_data_alpgen_err = sqrt(pow(tc08_5_data_bin_err,2.)+pow(tc08_5_alpgen_nom_bin_err,2.));
  //     double tc08_5_rel_data_alpgen_err = tc08_5_abs_data_alpgen_err/(tc08_5_data_bin_n-tc08_5_alpgen_nom_bin_n);
  //     double tc08_5_rel_alpgen_err = tc08_5_alpgen_nom_bin_err/tc08_5_alpgen_nom_bin_n;
      
  //     double tc08_5_rel_ratio_data_alpgen_dijet_pt_err = sqrt(pow(tc08_5_rel_data_alpgen_err,2.)+pow(tc08_5_rel_alpgen_err,2.));

  //     double tc08_5_data_alpgen_ratio = (tc08_5_data_bin_n-tc08_5_alpgen_nom_bin_n)/tc08_5_alpgen_nom_bin_n;

  //     double tc08_5_data_alpgen_ratio_err = fabs(tc08_5_rel_ratio_data_alpgen_dijet_pt_err*tc08_5_data_alpgen_ratio);

  //     h_ratio_data_alpgen_dijet_pt->SetBinContent(b,tc08_5_data_alpgen_ratio);
  //     h_ratio_data_alpgen_dijet_pt->SetBinError(b,tc08_5_data_alpgen_ratio_err);
  //   }
    

  //   if(tc08_5_data_bin_n && tc08_5_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc08_5_abs_data_sherpa_err = sqrt(pow(tc08_5_data_bin_err,2.)+pow(tc08_5_sherpa_nom_bin_err,2.));
  //     double tc08_5_rel_data_sherpa_err = tc08_5_abs_data_sherpa_err/(tc08_5_data_bin_n-tc08_5_sherpa_nom_bin_n);
  //     double tc08_5_rel_sherpa_err = tc08_5_sherpa_nom_bin_err/tc08_5_sherpa_nom_bin_n;
      
  //     double tc08_5_rel_ratio_data_sherpa_dijet_pt_err = sqrt(pow(tc08_5_rel_data_sherpa_err,2.)+pow(tc08_5_rel_sherpa_err,2.));

  //     double tc08_5_data_sherpa_ratio = (tc08_5_data_bin_n-tc08_5_sherpa_nom_bin_n)/tc08_5_sherpa_nom_bin_n;

  //     double tc08_5_data_sherpa_ratio_err = fabs(tc08_5_rel_ratio_data_sherpa_dijet_pt_err*tc08_5_data_sherpa_ratio);

  //     h_ratio_data_sherpa_dijet_pt->SetBinContent(b,tc08_5_data_sherpa_ratio);
  //     h_ratio_data_sherpa_dijet_pt->SetBinError(b,tc08_5_data_sherpa_ratio_err);
  //   }
    

  //   if(tc08_5_data_bin_n && tc08_5_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc08_5_abs_data_alpgen_iqopt3_err = sqrt(pow(tc08_5_data_bin_err,2.)+pow(tc08_5_alpgen_iqopt3_bin_err,2.));
  //     double tc08_5_rel_data_alpgen_iqopt3_err = tc08_5_abs_data_alpgen_iqopt3_err/(tc08_5_data_bin_n-tc08_5_alpgen_iqopt3_bin_n);
  //     double tc08_5_rel_alpgen_iqopt3_err = tc08_5_alpgen_iqopt3_bin_err/tc08_5_alpgen_iqopt3_bin_n;
      
  //     double tc08_5_rel_ratio_data_alpgen_iqopt3_dijet_pt_err = sqrt(pow(tc08_5_rel_data_alpgen_iqopt3_err,2.)+pow(tc08_5_rel_alpgen_iqopt3_err,2.));

  //     double tc08_5_data_alpgen_iqopt3_ratio = (tc08_5_data_bin_n-tc08_5_alpgen_iqopt3_bin_n)/tc08_5_alpgen_iqopt3_bin_n;

  //     double tc08_5_data_alpgen_iqopt3_ratio_err = fabs(tc08_5_rel_ratio_data_alpgen_iqopt3_dijet_pt_err*tc08_5_data_alpgen_iqopt3_ratio);

  //     h_ratio_data_alpgen_iqopt3_dijet_pt->SetBinContent(b,tc08_5_data_alpgen_iqopt3_ratio);
  //     h_ratio_data_alpgen_iqopt3_dijet_pt->SetBinError(b,tc08_5_data_alpgen_iqopt3_ratio_err);
  //   }
    
  //   if(tc08_5_data_bin_n && tc08_5_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc08_5_abs_data_alpgen_ptjmin10_err = sqrt(pow(tc08_5_data_bin_err,2.)+pow(tc08_5_alpgen_ptjmin10_bin_err,2.));
  //     double tc08_5_rel_data_alpgen_ptjmin10_err = tc08_5_abs_data_alpgen_ptjmin10_err/(tc08_5_data_bin_n-tc08_5_alpgen_ptjmin10_bin_n);
  //     double tc08_5_rel_alpgen_ptjmin10_err = tc08_5_alpgen_ptjmin10_bin_err/tc08_5_alpgen_ptjmin10_bin_n;
      
  //     double tc08_5_rel_ratio_data_alpgen_ptjmin10_dijet_pt_err = sqrt(pow(tc08_5_rel_data_alpgen_ptjmin10_err,2.)+pow(tc08_5_rel_alpgen_ptjmin10_err,2.));

  //     double tc08_5_data_alpgen_ptjmin10_ratio = (tc08_5_data_bin_n-tc08_5_alpgen_ptjmin10_bin_n)/tc08_5_alpgen_ptjmin10_bin_n;

  //     double tc08_5_data_alpgen_ptjmin10_ratio_err = fabs(tc08_5_rel_ratio_data_alpgen_ptjmin10_dijet_pt_err*tc08_5_data_alpgen_ptjmin10_ratio);

  //     h_ratio_data_alpgen_ptjmin10_dijet_pt->SetBinContent(b,tc08_5_data_alpgen_ptjmin10_ratio);
  //     h_ratio_data_alpgen_ptjmin10_dijet_pt->SetBinError(b,tc08_5_data_alpgen_ptjmin10_ratio_err);
  //   }
  // }


  // h_ratio_data_alpgen_dijet_pt->Draw("PE");
  // h_ratio_data_sherpa_dijet_pt->Draw("PE sames");
  // h_ratio_data_alpgen_iqopt3_dijet_pt->Draw("PE sames");
  // h_ratio_data_alpgen_ptjmin10_dijet_pt->Draw("PE sames");
  
  // //  h_ratio_alpgen_iqopt3_dijet_pt->Draw("PE sames");
  // //  h_ratio_alpgen_ptjmin10_dijet_pt->Draw("PE sames");
  
  // tc08_5->Update();
  // tc08_5->SaveAs("./plots/latest/data_muon_dijet_pt.png");
    




  // //NEXT
  
  // ////////////////////////////////////////////////// 
  // // tc09
  // // elec_nu_dijet_m: tc09_sherpa/alpgen+wjrw
  // ////////////////////////////////////////////////// 

  // string tc09_title = "M(elec,nu,dijet) (elec)";
  // string tc09_name = "tc09";
  // TCanvas* tc09 = new TCanvas(tc09_name.c_str(),tc09_title.c_str(),0,0,1920,1200);
  // tc09->cd();

  // TPad* tc09_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc09_pad01->SetTopMargin(0.05);
  // tc09_pad01->SetBottomMargin(0.31);
  // tc09_pad01->Draw();

  // TPad* tc09_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc09_pad02->SetBottomMargin(0.0005);
  // tc09_pad02->SetLogy();
  // tc09_pad02->Draw();
  // tc09_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_elec_lep_nu_dijet_m = (TH1F*) wjets_alpgen_file->Get("all/h_elec_purw_nom_lep_nu_dijet_m");
  // TH1F* h_alpgen_iqopt3_elec_lep_nu_dijet_m = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_iqopt3_lep_nu_dijet_m");
  // TH1F* h_alpgen_ptjmin10_elec_lep_nu_dijet_m = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_ptjmin10_lep_nu_dijet_m");
  // TH1F* h_sherpa_nom_elec_lep_nu_dijet_m = (TH1F*) wjets_sherpa_file->Get("all/h_elec_purw_nom_lep_nu_dijet_m");

  // //h_alpgen_nom_elec_lep_nu_dijet_m->SetLineWidth(2);
  // h_alpgen_nom_elec_lep_nu_dijet_m->SetMarkerStyle(20);
  // h_alpgen_nom_elec_lep_nu_dijet_m->SetMarkerSize(1.2);
  // h_alpgen_nom_elec_lep_nu_dijet_m->SetTitle("");
  // h_alpgen_nom_elec_lep_nu_dijet_m->Draw("PE");

  // //h_alpgen_iqopt3_elec_lep_nu_dijet_m->SetLineColor(kGreen);
  // h_alpgen_iqopt3_elec_lep_nu_dijet_m->SetMarkerStyle(22);
  // h_alpgen_iqopt3_elec_lep_nu_dijet_m->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_elec_lep_nu_dijet_m->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_elec_lep_nu_dijet_m->Draw("PE sames");

  // //  h_alpgen_ptjmin10_elec_lep_nu_dijet_m->SetLineColor(kBlue);
  // h_alpgen_ptjmin10_elec_lep_nu_dijet_m->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_elec_lep_nu_dijet_m->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_elec_lep_nu_dijet_m->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_elec_lep_nu_dijet_m->Draw("PE sames");

  // // h_sherpa_nom_elec_lep_nu_dijet_m->SetLineWidth(1.2);
  // // h_sherpa_nom_elec_lep_nu_dijet_m->SetLineColor(kRed);
  // h_sherpa_nom_elec_lep_nu_dijet_m->SetMarkerStyle(20);
  // h_sherpa_nom_elec_lep_nu_dijet_m->SetMarkerSize(1.2);
  // h_sherpa_nom_elec_lep_nu_dijet_m->SetMarkerColor(kRed);
  // h_sherpa_nom_elec_lep_nu_dijet_m->Draw("PE sames");


  // //Legend
  // TLegend* lgnd_tc09 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc09->SetFillColor(0);
  // lgnd_tc09->SetTextSize(0.03);
  // lgnd_tc09->SetBorderSize(0);

  // char lgnd_alpgen_nom_elec_lep_nu_dijet_m_name[20];
  // sprintf(lgnd_alpgen_nom_elec_lep_nu_dijet_m_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_elec_lep_nu_dijet_m->Integral());
  // lgnd_tc09->AddEntry(h_alpgen_nom_elec_lep_nu_dijet_m,lgnd_alpgen_nom_elec_lep_nu_dijet_m_name,"p");

  // char lgnd_alpgen_iqopt3_elec_lep_nu_dijet_m_name[20];
  // sprintf(lgnd_alpgen_iqopt3_elec_lep_nu_dijet_m_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_elec_lep_nu_dijet_m->Integral());
  // lgnd_tc09->AddEntry(h_alpgen_iqopt3_elec_lep_nu_dijet_m,lgnd_alpgen_iqopt3_elec_lep_nu_dijet_m_name,"p");

  // char lgnd_alpgen_ptjmin10_elec_lep_nu_dijet_m_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_elec_lep_nu_dijet_m_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_elec_lep_nu_dijet_m->Integral());
  // lgnd_tc09->AddEntry(h_alpgen_ptjmin10_elec_lep_nu_dijet_m,lgnd_alpgen_ptjmin10_elec_lep_nu_dijet_m_name,"p");

  // char lgnd_sherpa_nom_elec_lep_nu_dijet_m_name[20];
  // sprintf(lgnd_sherpa_nom_elec_lep_nu_dijet_m_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_elec_lep_nu_dijet_m->Integral());
  // lgnd_tc09->AddEntry(h_sherpa_nom_elec_lep_nu_dijet_m,lgnd_sherpa_nom_elec_lep_nu_dijet_m_name,"p");

  // lgnd_tc09->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc09_pad01->cd();
  // tc09_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_elec_lep_nu_dijet_m->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_elec_lep_nu_dijet_m->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_elec_lep_nu_dijet_m->GetXaxis())->GetXmax();

  // // alp-sherp/sherp
  // string tc09_ratio_alpgen_sherpa_elec_nu_dijet_m_name = "tc09_ratio_alpgen_sherpa_elec_nu_dijet_m";
  // TH1F* h_ratio_alpgen_sherpa_elec_nu_dijet_m = new TH1F(tc09_ratio_alpgen_sherpa_elec_nu_dijet_m_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_sherpa_elec_nu_dijet_m->SetMarkerStyle(8);
  // h_ratio_alpgen_sherpa_elec_nu_dijet_m->SetMarkerColor(kRed);

  // TAxis* h_ratio_alpgen_sherpa_elec_nu_dijet_m_xaxis = h_ratio_alpgen_sherpa_elec_nu_dijet_m->GetXaxis();
  // TAxis* h_ratio_alpgen_sherpa_elec_nu_dijet_m_yaxis = h_ratio_alpgen_sherpa_elec_nu_dijet_m->GetYaxis();
  
  // h_ratio_alpgen_sherpa_elec_nu_dijet_m_xaxis->SetLabelSize(0.08);
  // h_ratio_alpgen_sherpa_elec_nu_dijet_m_yaxis->SetLabelSize(0.08);

  // h_ratio_alpgen_sherpa_elec_nu_dijet_m_xaxis->SetTitle("M(elec,nu,dijet)");
  // h_ratio_alpgen_sherpa_elec_nu_dijet_m_xaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_elec_nu_dijet_m_yaxis->SetNdivisions(4,4,4);
  // h_ratio_alpgen_sherpa_elec_nu_dijet_m_yaxis->SetTitle("(alpgen-MC)/MC");
  // h_ratio_alpgen_sherpa_elec_nu_dijet_m_yaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_elec_nu_dijet_m_yaxis->SetTitleOffset(0.36);
  // h_ratio_alpgen_sherpa_elec_nu_dijet_m_yaxis->SetRangeUser(-1,1);

  
  // // alp-iqopt3/iqopt3
  // string tc09_ratio_alpgen_iqopt3_elec_nu_dijet_m_name = "tc09_ratio_alpgen_iqopt3_elec_nu_dijet_m";
  // TH1F* h_ratio_alpgen_iqopt3_elec_nu_dijet_m = new TH1F(tc09_ratio_alpgen_iqopt3_elec_nu_dijet_m_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_iqopt3_elec_nu_dijet_m->SetMarkerStyle(8);
  // h_ratio_alpgen_iqopt3_elec_nu_dijet_m->SetMarkerColor(kGreen);

  
  // // alp-ptjmin10/ptjmin10
  // string tc09_ratio_alpgen_ptjmin10_elec_nu_dijet_m_name = "tc09_ratio_alpgen_ptjmin10_elec_nu_dijet_m";
  // TH1F* h_ratio_alpgen_ptjmin10_elec_nu_dijet_m = new TH1F(tc09_ratio_alpgen_ptjmin10_elec_nu_dijet_m_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_ptjmin10_elec_nu_dijet_m->SetMarkerStyle(8);
  // h_ratio_alpgen_ptjmin10_elec_nu_dijet_m->SetMarkerColor(kBlue);


  
  // double tc09_alpgen_sherpa_ratio=0.;
  // double tc09_alpgen_iqopt3_ratio=0.;
  // double tc09_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc09_alpgen_nom_bin_n=h_alpgen_nom_elec_lep_nu_dijet_m->GetBinContent(b);
  //   double tc09_alpgen_nom_bin_err=h_alpgen_nom_elec_lep_nu_dijet_m->GetBinError(b);    

  //   double tc09_sherpa_nom_bin_n=h_sherpa_nom_elec_lep_nu_dijet_m->GetBinContent(b);
  //   double tc09_sherpa_nom_bin_err=h_sherpa_nom_elec_lep_nu_dijet_m->GetBinError(b);    

  //   double tc09_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_elec_lep_nu_dijet_m->GetBinContent(b);
  //   double tc09_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_elec_lep_nu_dijet_m->GetBinError(b);

  //   double tc09_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_elec_lep_nu_dijet_m->GetBinContent(b);
  //   double tc09_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_elec_lep_nu_dijet_m->GetBinError(b);



  //   if(tc09_alpgen_nom_bin_n && tc09_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc09_abs_alpgen_sherpa_err = sqrt(pow(tc09_alpgen_nom_bin_err,2.)+pow(tc09_sherpa_nom_bin_err,2.));
  //     double tc09_rel_alpgen_sherpa_err = tc09_abs_alpgen_sherpa_err/(tc09_alpgen_nom_bin_n-tc09_sherpa_nom_bin_n);
  //     double tc09_rel_sherpa_err = tc09_sherpa_nom_bin_err/tc09_sherpa_nom_bin_n;
      
  //     double tc09_rel_ratio_alpgen_sherpa_elec_nu_dijet_m_err = sqrt(pow(tc09_rel_alpgen_sherpa_err,2.)+pow(tc09_rel_sherpa_err,2.));

  //     double tc09_alpgen_sherpa_ratio = (tc09_alpgen_nom_bin_n-tc09_sherpa_nom_bin_n)/tc09_sherpa_nom_bin_n;

  //     double tc09_alpgen_sherpa_ratio_err = fabs(tc09_rel_ratio_alpgen_sherpa_elec_nu_dijet_m_err*tc09_alpgen_sherpa_ratio);

  //     h_ratio_alpgen_sherpa_elec_nu_dijet_m->SetBinContent(b,tc09_alpgen_sherpa_ratio);
  //     h_ratio_alpgen_sherpa_elec_nu_dijet_m->SetBinError(b,tc09_alpgen_sherpa_ratio_err);
  //   }
    

  //   if(tc09_alpgen_nom_bin_n && tc09_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc09_abs_alpgen_iqopt3_err = sqrt(pow(tc09_alpgen_nom_bin_err,2.)+pow(tc09_alpgen_iqopt3_bin_err,2.));
  //     double tc09_rel_alpgen_iqopt3_err = tc09_abs_alpgen_iqopt3_err/(tc09_alpgen_nom_bin_n-tc09_alpgen_iqopt3_bin_n);
  //     double tc09_rel_iqopt3_err = tc09_alpgen_iqopt3_bin_err/tc09_alpgen_iqopt3_bin_n;
      
  //     double tc09_rel_ratio_alpgen_iqopt3_elec_nu_dijet_m_err = sqrt(pow(tc09_rel_alpgen_iqopt3_err,2.)+pow(tc09_rel_iqopt3_err,2.));

  //     double tc09_alpgen_iqopt3_ratio = (tc09_alpgen_nom_bin_n-tc09_alpgen_iqopt3_bin_n)/tc09_alpgen_iqopt3_bin_n;

  //     double tc09_alpgen_iqopt3_ratio_err = fabs(tc09_rel_ratio_alpgen_iqopt3_elec_nu_dijet_m_err*tc09_alpgen_iqopt3_ratio);

  //     h_ratio_alpgen_iqopt3_elec_nu_dijet_m->SetBinContent(b,tc09_alpgen_iqopt3_ratio);
  //     h_ratio_alpgen_iqopt3_elec_nu_dijet_m->SetBinError(b,tc09_alpgen_iqopt3_ratio_err);
  //   }

    

  //   if(tc09_alpgen_nom_bin_n && tc09_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc09_abs_alpgen_ptjmin10_err = sqrt(pow(tc09_alpgen_nom_bin_err,2.)+pow(tc09_alpgen_ptjmin10_bin_err,2.));
  //     double tc09_rel_alpgen_ptjmin10_err = tc09_abs_alpgen_ptjmin10_err/(tc09_alpgen_nom_bin_n-tc09_alpgen_ptjmin10_bin_n);
  //     double tc09_rel_ptjmin10_err = tc09_alpgen_ptjmin10_bin_err/tc09_alpgen_ptjmin10_bin_n;
      
  //     double tc09_rel_ratio_alpgen_ptjmin10_elec_nu_dijet_m_err = sqrt(pow(tc09_rel_alpgen_ptjmin10_err,2.)+pow(tc09_rel_ptjmin10_err,2.));

  //     double tc09_alpgen_ptjmin10_ratio = (tc09_alpgen_nom_bin_n-tc09_alpgen_ptjmin10_bin_n)/tc09_alpgen_ptjmin10_bin_n;

  //     double tc09_alpgen_ptjmin10_ratio_err = fabs(tc09_rel_ratio_alpgen_ptjmin10_elec_nu_dijet_m_err*tc09_alpgen_ptjmin10_ratio);

  //     h_ratio_alpgen_ptjmin10_elec_nu_dijet_m->SetBinContent(b,tc09_alpgen_ptjmin10_ratio);
  //     h_ratio_alpgen_ptjmin10_elec_nu_dijet_m->SetBinError(b,tc09_alpgen_ptjmin10_ratio_err);
  //   }
    
  // }


  // h_ratio_alpgen_sherpa_elec_nu_dijet_m->Draw("PE");
  // h_ratio_alpgen_iqopt3_elec_nu_dijet_m->Draw("PE sames");
  // h_ratio_alpgen_ptjmin10_elec_nu_dijet_m->Draw("PE sames");
  
  // tc09->Update();

  // tc09->SaveAs("./plots/latest/elec_lep_nu_dijet_m.png");
  

  // //NEXT
  
  // //////////////////////////////////////////////////
  // // tc09_5
  // // data_elec_lep_nu_dijet_m: sherpa/alpgen+wjrw
  // //////////////////////////////////////////////////
  
  // string tc09_5_title = "M(elec,nu,dijet) (elec) w/ Data";
  // string tc09_5_name = "tc09_5";
  // TCanvas* tc09_5 = new TCanvas(tc09_5_name.c_str(),tc09_5_title.c_str(),0,0,1920,1200);
  // tc09_5->cd();

  // TPad* tc09_5_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc09_5_pad01->SetTopMargin(0.05);
  // tc09_5_pad01->SetBottomMargin(0.31);
  // tc09_5_pad01->Draw();

  // TPad* tc09_5_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc09_5_pad02->SetBottomMargin(0.0005);
  // tc09_5_pad02->SetLogy();
  // tc09_5_pad02->Draw();
  // tc09_5_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_elec_lep_nu_dijet_m = (TH1F*) wjets_alpgen_file->Get("all/h_elec_purw_nom_lep_nu_dijet_m");
  // TH1F* h_alpgen_iqopt3_elec_lep_nu_dijet_m = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_iqopt3_lep_nu_dijet_m");
  // TH1F* h_alpgen_ptjmin10_elec_lep_nu_dijet_m = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_ptjmin10_lep_nu_dijet_m");
  // TH1F* h_sherpa_nom_elec_lep_nu_dijet_m = (TH1F*) wjets_sherpa_file->Get("all/h_elec_purw_nom_lep_nu_dijet_m");
  // TH1F* h_data_elec_lep_nu_dijet_m = (TH1F*) data_file->Get("all/h_elec_purw_nom_lep_nu_dijet_m");

  // TH1F* h_top_elec_lep_nu_dijet_m = (TH1F*) top_mcatnlo_file->Get("all/h_elec_purw_nom_lep_nu_dijet_m");
  // TH1F* h_zjets_elec_lep_nu_dijet_m = (TH1F*) zjets_alpgen_file->Get("all/h_elec_purw_nom_lep_nu_dijet_m");
  // TH1F* h_vv_elec_lep_nu_dijet_m = (TH1F*) vv_herwig_file->Get("all/h_elec_purw_nom_lep_nu_dijet_m");
  // TH1F* h_qcd_elec_lep_nu_dijet_m = (TH1F*) qcd_file->Get("all/h_elec_purw_nom_lep_nu_dijet_m");
  
  // h_data_elec_lep_nu_dijet_m->SetTitle("");
  // h_data_elec_lep_nu_dijet_m->Draw();
  
  // //Add Backgrounds
  // h_alpgen_nom_elec_lep_nu_dijet_m->Add(h_top_elec_lep_nu_dijet_m);
  // h_alpgen_nom_elec_lep_nu_dijet_m->Add(h_zjets_elec_lep_nu_dijet_m);
  // h_alpgen_nom_elec_lep_nu_dijet_m->Add(h_vv_elec_lep_nu_dijet_m);
  // h_alpgen_nom_elec_lep_nu_dijet_m->Add(h_qcd_elec_lep_nu_dijet_m);
  
  // h_alpgen_nom_elec_lep_nu_dijet_m->SetMarkerStyle(20);
  // h_alpgen_nom_elec_lep_nu_dijet_m->SetMarkerSize(1.2);
  // h_alpgen_nom_elec_lep_nu_dijet_m->Draw("PE sames");

  // //Add backgrounds
  // h_alpgen_iqopt3_elec_lep_nu_dijet_m->Add(h_top_elec_lep_nu_dijet_m);
  // h_alpgen_iqopt3_elec_lep_nu_dijet_m->Add(h_zjets_elec_lep_nu_dijet_m);
  // h_alpgen_iqopt3_elec_lep_nu_dijet_m->Add(h_vv_elec_lep_nu_dijet_m);
  // h_alpgen_iqopt3_elec_lep_nu_dijet_m->Add(h_qcd_elec_lep_nu_dijet_m);

  // h_alpgen_iqopt3_elec_lep_nu_dijet_m->SetMarkerStyle(22);
  // h_alpgen_iqopt3_elec_lep_nu_dijet_m->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_elec_lep_nu_dijet_m->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_elec_lep_nu_dijet_m->Draw("PE sames");

  // //Add Backgrounds
  // h_alpgen_ptjmin10_elec_lep_nu_dijet_m->Add(h_top_elec_lep_nu_dijet_m);
  // h_alpgen_ptjmin10_elec_lep_nu_dijet_m->Add(h_zjets_elec_lep_nu_dijet_m);
  // h_alpgen_ptjmin10_elec_lep_nu_dijet_m->Add(h_vv_elec_lep_nu_dijet_m);
  // h_alpgen_ptjmin10_elec_lep_nu_dijet_m->Add(h_qcd_elec_lep_nu_dijet_m);

  // h_alpgen_ptjmin10_elec_lep_nu_dijet_m->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_elec_lep_nu_dijet_m->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_elec_lep_nu_dijet_m->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_elec_lep_nu_dijet_m->Draw("PE sames");

  // //Add Backgrounds
  // h_sherpa_nom_elec_lep_nu_dijet_m->Add(h_top_elec_lep_nu_dijet_m);
  // h_sherpa_nom_elec_lep_nu_dijet_m->Add(h_zjets_elec_lep_nu_dijet_m);
  // h_sherpa_nom_elec_lep_nu_dijet_m->Add(h_vv_elec_lep_nu_dijet_m);
  // h_sherpa_nom_elec_lep_nu_dijet_m->Add(h_qcd_elec_lep_nu_dijet_m);

  // h_sherpa_nom_elec_lep_nu_dijet_m->SetMarkerStyle(20);
  // h_sherpa_nom_elec_lep_nu_dijet_m->SetMarkerSize(1.2);
  // h_sherpa_nom_elec_lep_nu_dijet_m->SetMarkerColor(kRed);
  // h_sherpa_nom_elec_lep_nu_dijet_m->Draw("PE sames");




  // //Legend
  // TLegend* lgnd_tc09_5 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc09_5->SetFillColor(0);
  // lgnd_tc09_5->SetTextSize(0.03);
  // lgnd_tc09_5->SetBorderSize(0);


  // char lgnd_data_elec_lep_nu_dijet_m_name[20];
  // sprintf(lgnd_data_elec_lep_nu_dijet_m_name,"%s,  %.2f","DATA",h_data_elec_lep_nu_dijet_m->Integral());
  // lgnd_tc09_5->AddEntry(h_data_elec_lep_nu_dijet_m,lgnd_data_elec_lep_nu_dijet_m_name,"f");

  // char lgnd_alpgen_nom_elec_lep_nu_dijet_m_name[20];
  // sprintf(lgnd_alpgen_nom_elec_lep_nu_dijet_m_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_elec_lep_nu_dijet_m->Integral());
  // lgnd_tc09_5->AddEntry(h_alpgen_nom_elec_lep_nu_dijet_m,lgnd_alpgen_nom_elec_lep_nu_dijet_m_name,"p");

  // char lgnd_alpgen_iqopt3_elec_lep_nu_dijet_m_name[20];
  // sprintf(lgnd_alpgen_iqopt3_elec_lep_nu_dijet_m_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_elec_lep_nu_dijet_m->Integral());
  // lgnd_tc09_5->AddEntry(h_alpgen_iqopt3_elec_lep_nu_dijet_m,lgnd_alpgen_iqopt3_elec_lep_nu_dijet_m_name,"p");

  // char lgnd_alpgen_ptjmin10_elec_lep_nu_dijet_m_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_elec_lep_nu_dijet_m_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_elec_lep_nu_dijet_m->Integral());
  // lgnd_tc09_5->AddEntry(h_alpgen_ptjmin10_elec_lep_nu_dijet_m,lgnd_alpgen_ptjmin10_elec_lep_nu_dijet_m_name,"p");

  // char lgnd_sherpa_nom_elec_lep_nu_dijet_m_name[20];
  // sprintf(lgnd_sherpa_nom_elec_lep_nu_dijet_m_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_elec_lep_nu_dijet_m->Integral());
  // lgnd_tc09_5->AddEntry(h_sherpa_nom_elec_lep_nu_dijet_m,lgnd_sherpa_nom_elec_lep_nu_dijet_m_name,"p");

  // lgnd_tc09_5->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc09_5_pad01->cd();
  // tc09_5_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_elec_lep_nu_dijet_m->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_elec_lep_nu_dijet_m->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_elec_lep_nu_dijet_m->GetXaxis())->GetXmax();

  // // data-alpgen(nom)/alpgen(nom)
  // string tc09_5_ratio_data_alpgen_lep_nu_dijet_m_name = "tc09_5_ratio_data_alpgen_lep_nu_dijet_m";
  // TH1F* h_ratio_data_alpgen_lep_nu_dijet_m = new TH1F(tc09_5_ratio_data_alpgen_lep_nu_dijet_m_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_lep_nu_dijet_m->SetMarkerStyle(8);
  // //h_ratio_data_alpgen_lep_nu_dijet_m->SetMarkerColor(kRed);

  // TAxis* h_ratio_data_alpgen_lep_nu_dijet_m_xaxis = h_ratio_data_alpgen_lep_nu_dijet_m->GetXaxis();
  // TAxis* h_ratio_data_alpgen_lep_nu_dijet_m_yaxis = h_ratio_data_alpgen_lep_nu_dijet_m->GetYaxis();
  
  // h_ratio_data_alpgen_lep_nu_dijet_m_xaxis->SetLabelSize(0.08);
  // h_ratio_data_alpgen_lep_nu_dijet_m_yaxis->SetLabelSize(0.08);

  // h_ratio_data_alpgen_lep_nu_dijet_m_xaxis->SetTitle("M(elec,nu,dijet)");
  // h_ratio_data_alpgen_lep_nu_dijet_m_xaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_lep_nu_dijet_m_yaxis->SetNdivisions(4,4,4);
  // h_ratio_data_alpgen_lep_nu_dijet_m_yaxis->SetTitle("(data-MC)/MC");
  // h_ratio_data_alpgen_lep_nu_dijet_m_yaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_lep_nu_dijet_m_yaxis->SetTitleOffset(0.36);
  // h_ratio_data_alpgen_lep_nu_dijet_m_yaxis->SetRangeUser(-1,1);

  // // data-sherpa(nom)/sherpa(nom)
  // string tc09_5_ratio_data_sherpa_lep_nu_dijet_m_name = "tc09_5_ratio_data_sherpa_lep_nu_dijet_m";
  // TH1F* h_ratio_data_sherpa_lep_nu_dijet_m = new TH1F(tc09_5_ratio_data_sherpa_lep_nu_dijet_m_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_sherpa_lep_nu_dijet_m->SetMarkerStyle(8);
  // h_ratio_data_sherpa_lep_nu_dijet_m->SetMarkerColor(kRed);


  // // data-alpgen(iqopt3)/alpgen(iqopt3)
  // string tc09_5_ratio_data_alpgen_iqopt3_lep_nu_dijet_m_name = "tc09_5_ratio_data_alpgen_iqopt3_lep_nu_dijet_m";
  // TH1F* h_ratio_data_alpgen_iqopt3_lep_nu_dijet_m = new TH1F(tc09_5_ratio_data_alpgen_iqopt3_lep_nu_dijet_m_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_iqopt3_lep_nu_dijet_m->SetMarkerStyle(8);
  // h_ratio_data_alpgen_iqopt3_lep_nu_dijet_m->SetMarkerColor(kGreen);

  // // data-alpgen(ptjmin10)/alpgen(ptjmin10)
  // string tc09_5_ratio_data_alpgen_ptjmin10_lep_nu_dijet_m_name = "tc09_5_ratio_data_alpgen_ptjmin10_lep_nu_dijet_m";
  // TH1F* h_ratio_data_alpgen_ptjmin10_lep_nu_dijet_m = new TH1F(tc09_5_ratio_data_alpgen_ptjmin10_lep_nu_dijet_m_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_ptjmin10_lep_nu_dijet_m->SetMarkerStyle(8);
  // h_ratio_data_alpgen_ptjmin10_lep_nu_dijet_m->SetMarkerColor(kBlue);

  

  
  // // // alp-iqopt3/iqopt3
  // // string tc09_5_ratio_alpgen_iqopt3_lead_jet_pt_name = "tc09_5_ratio_alpgen_iqopt3_lead_jet_pt";
  // // TH1F* h_ratio_alpgen_iqopt3_lead_jet_pt = new TH1F(tc09_5_ratio_alpgen_iqopt3_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerStyle(8);
  // // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerColor(kGreen);

  
  // // // alp-ptjmin10/ptjmin10
  // // string tc09_5_ratio_alpgen_ptjmin10_lead_jet_pt_name = "tc09_5_ratio_alpgen_ptjmin10_lead_jet_pt";
  // // TH1F* h_ratio_alpgen_ptjmin10_lead_jet_pt = new TH1F(tc09_5_ratio_alpgen_ptjmin10_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerStyle(8);
  // // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerColor(kBlue);


  
  // double tc09_5_data_alpgen_ratio=0.;
  // double tc09_5_data_sherpa_ratio=0.;
  // double tc09_5_data_alpgen_iqopt3_ratio=0.;
  // double tc09_5_data_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc09_5_alpgen_nom_bin_n=h_alpgen_nom_elec_lep_nu_dijet_m->GetBinContent(b);
  //   double tc09_5_alpgen_nom_bin_err=h_alpgen_nom_elec_lep_nu_dijet_m->GetBinError(b);    

  //   double tc09_5_data_bin_n=h_data_elec_lep_nu_dijet_m->GetBinContent(b);
  //   double tc09_5_data_bin_err=h_data_elec_lep_nu_dijet_m->GetBinError(b);    

  //   double tc09_5_sherpa_nom_bin_n=h_sherpa_nom_elec_lep_nu_dijet_m->GetBinContent(b);
  //   double tc09_5_sherpa_nom_bin_err=h_sherpa_nom_elec_lep_nu_dijet_m->GetBinError(b);    

  //   double tc09_5_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_elec_lep_nu_dijet_m->GetBinContent(b);
  //   double tc09_5_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_elec_lep_nu_dijet_m->GetBinError(b);

  //   double tc09_5_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_elec_lep_nu_dijet_m->GetBinContent(b);
  //   double tc09_5_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_elec_lep_nu_dijet_m->GetBinError(b);



  //   if(tc09_5_data_bin_n && tc09_5_alpgen_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc09_5_abs_data_alpgen_err = sqrt(pow(tc09_5_data_bin_err,2.)+pow(tc09_5_alpgen_nom_bin_err,2.));
  //     double tc09_5_rel_data_alpgen_err = tc09_5_abs_data_alpgen_err/(tc09_5_data_bin_n-tc09_5_alpgen_nom_bin_n);
  //     double tc09_5_rel_alpgen_err = tc09_5_alpgen_nom_bin_err/tc09_5_alpgen_nom_bin_n;
      
  //     double tc09_5_rel_ratio_data_alpgen_lep_nu_dijet_m_err = sqrt(pow(tc09_5_rel_data_alpgen_err,2.)+pow(tc09_5_rel_alpgen_err,2.));

  //     double tc09_5_data_alpgen_ratio = (tc09_5_data_bin_n-tc09_5_alpgen_nom_bin_n)/tc09_5_alpgen_nom_bin_n;

  //     double tc09_5_data_alpgen_ratio_err = fabs(tc09_5_rel_ratio_data_alpgen_lep_nu_dijet_m_err*tc09_5_data_alpgen_ratio);

  //     h_ratio_data_alpgen_lep_nu_dijet_m->SetBinContent(b,tc09_5_data_alpgen_ratio);
  //     h_ratio_data_alpgen_lep_nu_dijet_m->SetBinError(b,tc09_5_data_alpgen_ratio_err);
  //   }
    

  //   if(tc09_5_data_bin_n && tc09_5_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc09_5_abs_data_sherpa_err = sqrt(pow(tc09_5_data_bin_err,2.)+pow(tc09_5_sherpa_nom_bin_err,2.));
  //     double tc09_5_rel_data_sherpa_err = tc09_5_abs_data_sherpa_err/(tc09_5_data_bin_n-tc09_5_sherpa_nom_bin_n);
  //     double tc09_5_rel_sherpa_err = tc09_5_sherpa_nom_bin_err/tc09_5_sherpa_nom_bin_n;
      
  //     double tc09_5_rel_ratio_data_sherpa_lep_nu_dijet_m_err = sqrt(pow(tc09_5_rel_data_sherpa_err,2.)+pow(tc09_5_rel_sherpa_err,2.));

  //     double tc09_5_data_sherpa_ratio = (tc09_5_data_bin_n-tc09_5_sherpa_nom_bin_n)/tc09_5_sherpa_nom_bin_n;

  //     double tc09_5_data_sherpa_ratio_err = fabs(tc09_5_rel_ratio_data_sherpa_lep_nu_dijet_m_err*tc09_5_data_sherpa_ratio);

  //     h_ratio_data_sherpa_lep_nu_dijet_m->SetBinContent(b,tc09_5_data_sherpa_ratio);
  //     h_ratio_data_sherpa_lep_nu_dijet_m->SetBinError(b,tc09_5_data_sherpa_ratio_err);
  //   }
    

  //   if(tc09_5_data_bin_n && tc09_5_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc09_5_abs_data_alpgen_iqopt3_err = sqrt(pow(tc09_5_data_bin_err,2.)+pow(tc09_5_alpgen_iqopt3_bin_err,2.));
  //     double tc09_5_rel_data_alpgen_iqopt3_err = tc09_5_abs_data_alpgen_iqopt3_err/(tc09_5_data_bin_n-tc09_5_alpgen_iqopt3_bin_n);
  //     double tc09_5_rel_alpgen_iqopt3_err = tc09_5_alpgen_iqopt3_bin_err/tc09_5_alpgen_iqopt3_bin_n;
      
  //     double tc09_5_rel_ratio_data_alpgen_iqopt3_lep_nu_dijet_m_err = sqrt(pow(tc09_5_rel_data_alpgen_iqopt3_err,2.)+pow(tc09_5_rel_alpgen_iqopt3_err,2.));

  //     double tc09_5_data_alpgen_iqopt3_ratio = (tc09_5_data_bin_n-tc09_5_alpgen_iqopt3_bin_n)/tc09_5_alpgen_iqopt3_bin_n;

  //     double tc09_5_data_alpgen_iqopt3_ratio_err = fabs(tc09_5_rel_ratio_data_alpgen_iqopt3_lep_nu_dijet_m_err*tc09_5_data_alpgen_iqopt3_ratio);

  //     h_ratio_data_alpgen_iqopt3_lep_nu_dijet_m->SetBinContent(b,tc09_5_data_alpgen_iqopt3_ratio);
  //     h_ratio_data_alpgen_iqopt3_lep_nu_dijet_m->SetBinError(b,tc09_5_data_alpgen_iqopt3_ratio_err);
  //   }
    
  //   if(tc09_5_data_bin_n && tc09_5_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc09_5_abs_data_alpgen_ptjmin10_err = sqrt(pow(tc09_5_data_bin_err,2.)+pow(tc09_5_alpgen_ptjmin10_bin_err,2.));
  //     double tc09_5_rel_data_alpgen_ptjmin10_err = tc09_5_abs_data_alpgen_ptjmin10_err/(tc09_5_data_bin_n-tc09_5_alpgen_ptjmin10_bin_n);
  //     double tc09_5_rel_alpgen_ptjmin10_err = tc09_5_alpgen_ptjmin10_bin_err/tc09_5_alpgen_ptjmin10_bin_n;
      
  //     double tc09_5_rel_ratio_data_alpgen_ptjmin10_lep_nu_dijet_m_err = sqrt(pow(tc09_5_rel_data_alpgen_ptjmin10_err,2.)+pow(tc09_5_rel_alpgen_ptjmin10_err,2.));

  //     double tc09_5_data_alpgen_ptjmin10_ratio = (tc09_5_data_bin_n-tc09_5_alpgen_ptjmin10_bin_n)/tc09_5_alpgen_ptjmin10_bin_n;

  //     double tc09_5_data_alpgen_ptjmin10_ratio_err = fabs(tc09_5_rel_ratio_data_alpgen_ptjmin10_lep_nu_dijet_m_err*tc09_5_data_alpgen_ptjmin10_ratio);

  //     h_ratio_data_alpgen_ptjmin10_lep_nu_dijet_m->SetBinContent(b,tc09_5_data_alpgen_ptjmin10_ratio);
  //     h_ratio_data_alpgen_ptjmin10_lep_nu_dijet_m->SetBinError(b,tc09_5_data_alpgen_ptjmin10_ratio_err);
  //   }
  // }


  // h_ratio_data_alpgen_lep_nu_dijet_m->Draw("PE");
  // h_ratio_data_sherpa_lep_nu_dijet_m->Draw("PE sames");
  // h_ratio_data_alpgen_iqopt3_lep_nu_dijet_m->Draw("PE sames");
  // h_ratio_data_alpgen_ptjmin10_lep_nu_dijet_m->Draw("PE sames");
  
  // //  h_ratio_alpgen_iqopt3_lep_nu_dijet_m->Draw("PE sames");
  // //  h_ratio_alpgen_ptjmin10_lep_nu_dijet_m->Draw("PE sames");
  
  // tc09_5->Update();
  // tc09_5->SaveAs("./plots/latest/data_elec_lep_nu_dijet_m.png");
    
  // //NEXT

  // ////////////////////////////////////////////////// 
  // // tc10
  // // muon_lep_nu_dijet_m: tc10_sherpa/alpgen+wjrw
  // ////////////////////////////////////////////////// 

  // string tc10_title = "M(muon,nu,dijet) (muon)";
  // string tc10_name = "tc10";
  // TCanvas* tc10 = new TCanvas(tc10_name.c_str(),tc10_title.c_str(),0,0,1920,1200);
  // tc10->cd();

  // TPad* tc10_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc10_pad01->SetTopMargin(0.05);
  // tc10_pad01->SetBottomMargin(0.31);
  // tc10_pad01->Draw();

  // TPad* tc10_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc10_pad02->SetBottomMargin(0.0005);
  // tc10_pad02->SetLogy();
  // tc10_pad02->Draw();
  // tc10_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_muon_lep_nu_dijet_m = (TH1F*) wjets_alpgen_file->Get("all/h_muon_purw_nom_lep_nu_dijet_m");
  // TH1F* h_alpgen_iqopt3_muon_lep_nu_dijet_m = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_iqopt3_lep_nu_dijet_m");
  // TH1F* h_alpgen_ptjmin10_muon_lep_nu_dijet_m = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_ptjmin10_lep_nu_dijet_m");
  // TH1F* h_sherpa_nom_muon_lep_nu_dijet_m = (TH1F*) wjets_sherpa_file->Get("all/h_muon_purw_nom_lep_nu_dijet_m");

  // //h_alpgen_nom_muon_lep_nu_dijet_m->SetLineWidth(2);
  // h_alpgen_nom_muon_lep_nu_dijet_m->SetMarkerStyle(20);
  // h_alpgen_nom_muon_lep_nu_dijet_m->SetMarkerSize(1.2);
  // h_alpgen_nom_muon_lep_nu_dijet_m->SetTitle("");
  // h_alpgen_nom_muon_lep_nu_dijet_m->Draw("PE");

  // //h_alpgen_iqopt3_muon_lep_nu_dijet_m->SetLineColor(kGreen);
  // h_alpgen_iqopt3_muon_lep_nu_dijet_m->SetMarkerStyle(22);
  // h_alpgen_iqopt3_muon_lep_nu_dijet_m->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_muon_lep_nu_dijet_m->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_muon_lep_nu_dijet_m->Draw("PE sames");

  // //  h_alpgen_ptjmin10_muon_lep_nu_dijet_m->SetLineColor(kBlue);
  // h_alpgen_ptjmin10_muon_lep_nu_dijet_m->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_muon_lep_nu_dijet_m->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_muon_lep_nu_dijet_m->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_muon_lep_nu_dijet_m->Draw("PE sames");

  // // h_sherpa_nom_muon_lep_nu_dijet_m->SetLineWidth(1.2);
  // // h_sherpa_nom_muon_lep_nu_dijet_m->SetLineColor(kRed);
  // h_sherpa_nom_muon_lep_nu_dijet_m->SetMarkerStyle(20);
  // h_sherpa_nom_muon_lep_nu_dijet_m->SetMarkerSize(1.2);
  // h_sherpa_nom_muon_lep_nu_dijet_m->SetMarkerColor(kRed);
  // h_sherpa_nom_muon_lep_nu_dijet_m->Draw("PE sames");


  // //Legend
  // TLegend* lgnd_tc10 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc10->SetFillColor(0);
  // lgnd_tc10->SetTextSize(0.03);
  // lgnd_tc10->SetBorderSize(0);

  // char lgnd_alpgen_nom_muon_lep_nu_dijet_m_name[20];
  // sprintf(lgnd_alpgen_nom_muon_lep_nu_dijet_m_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_muon_lep_nu_dijet_m->Integral());
  // lgnd_tc10->AddEntry(h_alpgen_nom_muon_lep_nu_dijet_m,lgnd_alpgen_nom_muon_lep_nu_dijet_m_name,"p");

  // char lgnd_alpgen_iqopt3_muon_lep_nu_dijet_m_name[20];
  // sprintf(lgnd_alpgen_iqopt3_muon_lep_nu_dijet_m_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_muon_lep_nu_dijet_m->Integral());
  // lgnd_tc10->AddEntry(h_alpgen_iqopt3_muon_lep_nu_dijet_m,lgnd_alpgen_iqopt3_muon_lep_nu_dijet_m_name,"p");

  // char lgnd_alpgen_ptjmin10_muon_lep_nu_dijet_m_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_muon_lep_nu_dijet_m_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_muon_lep_nu_dijet_m->Integral());
  // lgnd_tc10->AddEntry(h_alpgen_ptjmin10_muon_lep_nu_dijet_m,lgnd_alpgen_ptjmin10_muon_lep_nu_dijet_m_name,"p");

  // char lgnd_sherpa_nom_muon_lep_nu_dijet_m_name[20];
  // sprintf(lgnd_sherpa_nom_muon_lep_nu_dijet_m_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_muon_lep_nu_dijet_m->Integral());
  // lgnd_tc10->AddEntry(h_sherpa_nom_muon_lep_nu_dijet_m,lgnd_sherpa_nom_muon_lep_nu_dijet_m_name,"p");

  // lgnd_tc10->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc10_pad01->cd();
  // tc10_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_muon_lep_nu_dijet_m->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_muon_lep_nu_dijet_m->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_muon_lep_nu_dijet_m->GetXaxis())->GetXmax();

  // // alp-sherp/sherp
  // string tc10_ratio_alpgen_sherpa_lep_nu_dijet_m_name = "tc10_ratio_alpgen_sherpa_lep_nu_dijet_m";
  // TH1F* h_ratio_alpgen_sherpa_lep_nu_dijet_m = new TH1F(tc10_ratio_alpgen_sherpa_lep_nu_dijet_m_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_sherpa_lep_nu_dijet_m->SetMarkerStyle(8);
  // h_ratio_alpgen_sherpa_lep_nu_dijet_m->SetMarkerColor(kRed);

  // TAxis* h_ratio_alpgen_sherpa_lep_nu_dijet_m_xaxis = h_ratio_alpgen_sherpa_lep_nu_dijet_m->GetXaxis();
  // TAxis* h_ratio_alpgen_sherpa_lep_nu_dijet_m_yaxis = h_ratio_alpgen_sherpa_lep_nu_dijet_m->GetYaxis();
  
  // h_ratio_alpgen_sherpa_lep_nu_dijet_m_xaxis->SetLabelSize(0.08);
  // h_ratio_alpgen_sherpa_lep_nu_dijet_m_yaxis->SetLabelSize(0.08);

  // h_ratio_alpgen_sherpa_lep_nu_dijet_m_xaxis->SetTitle("M(muon,nu,dijet)");
  // h_ratio_alpgen_sherpa_lep_nu_dijet_m_xaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_lep_nu_dijet_m_yaxis->SetNdivisions(4,4,4);
  // h_ratio_alpgen_sherpa_lep_nu_dijet_m_yaxis->SetTitle("(alpgen-MC)/MC");
  // h_ratio_alpgen_sherpa_lep_nu_dijet_m_yaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_lep_nu_dijet_m_yaxis->SetTitleOffset(0.36);
  // h_ratio_alpgen_sherpa_lep_nu_dijet_m_yaxis->SetRangeUser(-1,1);

  
  // // alp-iqopt3/iqopt3
  // string tc10_ratio_alpgen_iqopt3_lep_nu_dijet_m_name = "tc10_ratio_alpgen_iqopt3_lep_nu_dijet_m";
  // TH1F* h_ratio_alpgen_iqopt3_lep_nu_dijet_m = new TH1F(tc10_ratio_alpgen_iqopt3_lep_nu_dijet_m_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_iqopt3_lep_nu_dijet_m->SetMarkerStyle(8);
  // h_ratio_alpgen_iqopt3_lep_nu_dijet_m->SetMarkerColor(kGreen);

  
  // // alp-ptjmin10/ptjmin10
  // string tc10_ratio_alpgen_ptjmin10_lep_nu_dijet_m_name = "tc10_ratio_alpgen_ptjmin10_lep_nu_dijet_m";
  // TH1F* h_ratio_alpgen_ptjmin10_lep_nu_dijet_m = new TH1F(tc10_ratio_alpgen_ptjmin10_lep_nu_dijet_m_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_ptjmin10_lep_nu_dijet_m->SetMarkerStyle(8);
  // h_ratio_alpgen_ptjmin10_lep_nu_dijet_m->SetMarkerColor(kBlue);


  
  // double tc10_alpgen_sherpa_ratio=0.;
  // double tc10_alpgen_iqopt3_ratio=0.;
  // double tc10_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc10_alpgen_nom_bin_n=h_alpgen_nom_muon_lep_nu_dijet_m->GetBinContent(b);
  //   double tc10_alpgen_nom_bin_err=h_alpgen_nom_muon_lep_nu_dijet_m->GetBinError(b);    

  //   double tc10_sherpa_nom_bin_n=h_sherpa_nom_muon_lep_nu_dijet_m->GetBinContent(b);
  //   double tc10_sherpa_nom_bin_err=h_sherpa_nom_muon_lep_nu_dijet_m->GetBinError(b);    

  //   double tc10_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_muon_lep_nu_dijet_m->GetBinContent(b);
  //   double tc10_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_muon_lep_nu_dijet_m->GetBinError(b);

  //   double tc10_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_muon_lep_nu_dijet_m->GetBinContent(b);
  //   double tc10_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_muon_lep_nu_dijet_m->GetBinError(b);



  //   if(tc10_alpgen_nom_bin_n && tc10_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc10_abs_alpgen_sherpa_err = sqrt(pow(tc10_alpgen_nom_bin_err,2.)+pow(tc10_sherpa_nom_bin_err,2.));
  //     double tc10_rel_alpgen_sherpa_err = tc10_abs_alpgen_sherpa_err/(tc10_alpgen_nom_bin_n-tc10_sherpa_nom_bin_n);
  //     double tc10_rel_sherpa_err = tc10_sherpa_nom_bin_err/tc10_sherpa_nom_bin_n;
      
  //     double tc10_rel_ratio_alpgen_sherpa_lep_nu_dijet_m_err = sqrt(pow(tc10_rel_alpgen_sherpa_err,2.)+pow(tc10_rel_sherpa_err,2.));

  //     double tc10_alpgen_sherpa_ratio = (tc10_alpgen_nom_bin_n-tc10_sherpa_nom_bin_n)/tc10_sherpa_nom_bin_n;

  //     double tc10_alpgen_sherpa_ratio_err = fabs(tc10_rel_ratio_alpgen_sherpa_lep_nu_dijet_m_err*tc10_alpgen_sherpa_ratio);

  //     h_ratio_alpgen_sherpa_lep_nu_dijet_m->SetBinContent(b,tc10_alpgen_sherpa_ratio);
  //     h_ratio_alpgen_sherpa_lep_nu_dijet_m->SetBinError(b,tc10_alpgen_sherpa_ratio_err);
  //   }
    

  //   if(tc10_alpgen_nom_bin_n && tc10_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc10_abs_alpgen_iqopt3_err = sqrt(pow(tc10_alpgen_nom_bin_err,2.)+pow(tc10_alpgen_iqopt3_bin_err,2.));
  //     double tc10_rel_alpgen_iqopt3_err = tc10_abs_alpgen_iqopt3_err/(tc10_alpgen_nom_bin_n-tc10_alpgen_iqopt3_bin_n);
  //     double tc10_rel_iqopt3_err = tc10_alpgen_iqopt3_bin_err/tc10_alpgen_iqopt3_bin_n;
      
  //     double tc10_rel_ratio_alpgen_iqopt3_lep_nu_dijet_m_err = sqrt(pow(tc10_rel_alpgen_iqopt3_err,2.)+pow(tc10_rel_iqopt3_err,2.));

  //     double tc10_alpgen_iqopt3_ratio = (tc10_alpgen_nom_bin_n-tc10_alpgen_iqopt3_bin_n)/tc10_alpgen_iqopt3_bin_n;

  //     double tc10_alpgen_iqopt3_ratio_err = fabs(tc10_rel_ratio_alpgen_iqopt3_lep_nu_dijet_m_err*tc10_alpgen_iqopt3_ratio);

  //     h_ratio_alpgen_iqopt3_lep_nu_dijet_m->SetBinContent(b,tc10_alpgen_iqopt3_ratio);
  //     h_ratio_alpgen_iqopt3_lep_nu_dijet_m->SetBinError(b,tc10_alpgen_iqopt3_ratio_err);
  //   }

    

  //   if(tc10_alpgen_nom_bin_n && tc10_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc10_abs_alpgen_ptjmin10_err = sqrt(pow(tc10_alpgen_nom_bin_err,2.)+pow(tc10_alpgen_ptjmin10_bin_err,2.));
  //     double tc10_rel_alpgen_ptjmin10_err = tc10_abs_alpgen_ptjmin10_err/(tc10_alpgen_nom_bin_n-tc10_alpgen_ptjmin10_bin_n);
  //     double tc10_rel_ptjmin10_err = tc10_alpgen_ptjmin10_bin_err/tc10_alpgen_ptjmin10_bin_n;
      
  //     double tc10_rel_ratio_alpgen_ptjmin10_lep_nu_dijet_m_err = sqrt(pow(tc10_rel_alpgen_ptjmin10_err,2.)+pow(tc10_rel_ptjmin10_err,2.));

  //     double tc10_alpgen_ptjmin10_ratio = (tc10_alpgen_nom_bin_n-tc10_alpgen_ptjmin10_bin_n)/tc10_alpgen_ptjmin10_bin_n;

  //     double tc10_alpgen_ptjmin10_ratio_err = fabs(tc10_rel_ratio_alpgen_ptjmin10_lep_nu_dijet_m_err*tc10_alpgen_ptjmin10_ratio);

  //     h_ratio_alpgen_ptjmin10_lep_nu_dijet_m->SetBinContent(b,tc10_alpgen_ptjmin10_ratio);
  //     h_ratio_alpgen_ptjmin10_lep_nu_dijet_m->SetBinError(b,tc10_alpgen_ptjmin10_ratio_err);
  //   }
    
  // }


  // h_ratio_alpgen_sherpa_lep_nu_dijet_m->Draw("PE");
  // h_ratio_alpgen_iqopt3_lep_nu_dijet_m->Draw("PE sames");
  // h_ratio_alpgen_ptjmin10_lep_nu_dijet_m->Draw("PE sames");
  
  // tc10->Update();

  // tc10->SaveAs("./plots/latest/muon_lep_nu_dijet_m.png");
  
  // //NEXT  

  // //////////////////////////////////////////////////
  // // tc10_5
  // // data_muon_lep_nu_dijet_m: sherpa/alpgen+wjrw
  // //////////////////////////////////////////////////
  
  // string tc10_5_title = "M(muon,nu,dijet) (muon) w/ Data";
  // string tc10_5_name = "tc10_5";
  // TCanvas* tc10_5 = new TCanvas(tc10_5_name.c_str(),tc10_5_title.c_str(),0,0,1920,1200);
  // tc10_5->cd();

  // TPad* tc10_5_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc10_5_pad01->SetTopMargin(0.05);
  // tc10_5_pad01->SetBottomMargin(0.31);
  // tc10_5_pad01->Draw();

  // TPad* tc10_5_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc10_5_pad02->SetBottomMargin(0.0005);
  // tc10_5_pad02->SetLogy();
  // tc10_5_pad02->Draw();
  // tc10_5_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_muon_lep_nu_dijet_m = (TH1F*) wjets_alpgen_file->Get("all/h_muon_purw_nom_lep_nu_dijet_m");
  // TH1F* h_alpgen_iqopt3_muon_lep_nu_dijet_m = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_iqopt3_lep_nu_dijet_m");
  // TH1F* h_alpgen_ptjmin10_muon_lep_nu_dijet_m = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_ptjmin10_lep_nu_dijet_m");
  // TH1F* h_sherpa_nom_muon_lep_nu_dijet_m = (TH1F*) wjets_sherpa_file->Get("all/h_muon_purw_nom_lep_nu_dijet_m");
  // TH1F* h_data_muon_lep_nu_dijet_m = (TH1F*) data_file->Get("all/h_muon_purw_nom_lep_nu_dijet_m");

  // TH1F* h_top_muon_lep_nu_dijet_m = (TH1F*) top_mcatnlo_file->Get("all/h_muon_purw_nom_lep_nu_dijet_m");
  // TH1F* h_zjets_muon_lep_nu_dijet_m = (TH1F*) zjets_alpgen_file->Get("all/h_muon_purw_nom_lep_nu_dijet_m");
  // TH1F* h_vv_muon_lep_nu_dijet_m = (TH1F*) vv_herwig_file->Get("all/h_muon_purw_nom_lep_nu_dijet_m");
  // TH1F* h_qcd_muon_lep_nu_dijet_m = (TH1F*) qcd_file->Get("all/h_muon_purw_nom_lep_nu_dijet_m");
  
  // h_data_muon_lep_nu_dijet_m->SetTitle("");
  // h_data_muon_lep_nu_dijet_m->Draw();
  
  // //Add Backgrounds
  // h_alpgen_nom_muon_lep_nu_dijet_m->Add(h_top_muon_lep_nu_dijet_m);
  // h_alpgen_nom_muon_lep_nu_dijet_m->Add(h_zjets_muon_lep_nu_dijet_m);
  // h_alpgen_nom_muon_lep_nu_dijet_m->Add(h_vv_muon_lep_nu_dijet_m);
  // h_alpgen_nom_muon_lep_nu_dijet_m->Add(h_qcd_muon_lep_nu_dijet_m);
  
  // h_alpgen_nom_muon_lep_nu_dijet_m->SetMarkerStyle(20);
  // h_alpgen_nom_muon_lep_nu_dijet_m->SetMarkerSize(1.2);
  // h_alpgen_nom_muon_lep_nu_dijet_m->Draw("PE sames");

  // //Add backgrounds
  // h_alpgen_iqopt3_muon_lep_nu_dijet_m->Add(h_top_muon_lep_nu_dijet_m);
  // h_alpgen_iqopt3_muon_lep_nu_dijet_m->Add(h_zjets_muon_lep_nu_dijet_m);
  // h_alpgen_iqopt3_muon_lep_nu_dijet_m->Add(h_vv_muon_lep_nu_dijet_m);
  // h_alpgen_iqopt3_muon_lep_nu_dijet_m->Add(h_qcd_muon_lep_nu_dijet_m);

  // h_alpgen_iqopt3_muon_lep_nu_dijet_m->SetMarkerStyle(22);
  // h_alpgen_iqopt3_muon_lep_nu_dijet_m->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_muon_lep_nu_dijet_m->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_muon_lep_nu_dijet_m->Draw("PE sames");

  // //Add Backgrounds
  // h_alpgen_ptjmin10_muon_lep_nu_dijet_m->Add(h_top_muon_lep_nu_dijet_m);
  // h_alpgen_ptjmin10_muon_lep_nu_dijet_m->Add(h_zjets_muon_lep_nu_dijet_m);
  // h_alpgen_ptjmin10_muon_lep_nu_dijet_m->Add(h_vv_muon_lep_nu_dijet_m);
  // h_alpgen_ptjmin10_muon_lep_nu_dijet_m->Add(h_qcd_muon_lep_nu_dijet_m);

  // h_alpgen_ptjmin10_muon_lep_nu_dijet_m->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_muon_lep_nu_dijet_m->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_muon_lep_nu_dijet_m->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_muon_lep_nu_dijet_m->Draw("PE sames");

  // //Add Backgrounds
  // h_sherpa_nom_muon_lep_nu_dijet_m->Add(h_top_muon_lep_nu_dijet_m);
  // h_sherpa_nom_muon_lep_nu_dijet_m->Add(h_zjets_muon_lep_nu_dijet_m);
  // h_sherpa_nom_muon_lep_nu_dijet_m->Add(h_vv_muon_lep_nu_dijet_m);
  // h_sherpa_nom_muon_lep_nu_dijet_m->Add(h_qcd_muon_lep_nu_dijet_m);

  // h_sherpa_nom_muon_lep_nu_dijet_m->SetMarkerStyle(20);
  // h_sherpa_nom_muon_lep_nu_dijet_m->SetMarkerSize(1.2);
  // h_sherpa_nom_muon_lep_nu_dijet_m->SetMarkerColor(kRed);
  // h_sherpa_nom_muon_lep_nu_dijet_m->Draw("PE sames");




  // //Legend
  // TLegend* lgnd_tc10_5 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc10_5->SetFillColor(0);
  // lgnd_tc10_5->SetTextSize(0.03);
  // lgnd_tc10_5->SetBorderSize(0);


  // char lgnd_data_muon_lep_nu_dijet_m_name[20];
  // sprintf(lgnd_data_muon_lep_nu_dijet_m_name,"%s,  %.2f","DATA",h_data_muon_lep_nu_dijet_m->Integral());
  // lgnd_tc10_5->AddEntry(h_data_muon_lep_nu_dijet_m,lgnd_data_muon_lep_nu_dijet_m_name,"f");

  // char lgnd_alpgen_nom_muon_lep_nu_dijet_m_name[20];
  // sprintf(lgnd_alpgen_nom_muon_lep_nu_dijet_m_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_muon_lep_nu_dijet_m->Integral());
  // lgnd_tc10_5->AddEntry(h_alpgen_nom_muon_lep_nu_dijet_m,lgnd_alpgen_nom_muon_lep_nu_dijet_m_name,"p");

  // char lgnd_alpgen_iqopt3_muon_lep_nu_dijet_m_name[20];
  // sprintf(lgnd_alpgen_iqopt3_muon_lep_nu_dijet_m_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_muon_lep_nu_dijet_m->Integral());
  // lgnd_tc10_5->AddEntry(h_alpgen_iqopt3_muon_lep_nu_dijet_m,lgnd_alpgen_iqopt3_muon_lep_nu_dijet_m_name,"p");

  // char lgnd_alpgen_ptjmin10_muon_lep_nu_dijet_m_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_muon_lep_nu_dijet_m_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_muon_lep_nu_dijet_m->Integral());
  // lgnd_tc10_5->AddEntry(h_alpgen_ptjmin10_muon_lep_nu_dijet_m,lgnd_alpgen_ptjmin10_muon_lep_nu_dijet_m_name,"p");

  // char lgnd_sherpa_nom_muon_lep_nu_dijet_m_name[20];
  // sprintf(lgnd_sherpa_nom_muon_lep_nu_dijet_m_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_muon_lep_nu_dijet_m->Integral());
  // lgnd_tc10_5->AddEntry(h_sherpa_nom_muon_lep_nu_dijet_m,lgnd_sherpa_nom_muon_lep_nu_dijet_m_name,"p");

  // lgnd_tc10_5->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc10_5_pad01->cd();
  // tc10_5_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_muon_lep_nu_dijet_m->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_muon_lep_nu_dijet_m->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_muon_lep_nu_dijet_m->GetXaxis())->GetXmax();

  // // data-alpgen(nom)/alpgen(nom)
  // string tc10_5_ratio_data_alpgen_lep_nu_dijet_m_name = "tc10_5_ratio_data_alpgen_lep_nu_dijet_m";
  // TH1F* h_ratio_data_alpgen_lep_nu_dijet_m = new TH1F(tc10_5_ratio_data_alpgen_lep_nu_dijet_m_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_lep_nu_dijet_m->SetMarkerStyle(8);
  // //h_ratio_data_alpgen_lep_nu_dijet_m->SetMarkerColor(kRed);

  // TAxis* h_ratio_data_alpgen_lep_nu_dijet_m_xaxis = h_ratio_data_alpgen_lep_nu_dijet_m->GetXaxis();
  // TAxis* h_ratio_data_alpgen_lep_nu_dijet_m_yaxis = h_ratio_data_alpgen_lep_nu_dijet_m->GetYaxis();
  
  // h_ratio_data_alpgen_lep_nu_dijet_m_xaxis->SetLabelSize(0.08);
  // h_ratio_data_alpgen_lep_nu_dijet_m_yaxis->SetLabelSize(0.08);

  // h_ratio_data_alpgen_lep_nu_dijet_m_xaxis->SetTitle("M(muon,nu,dijet)");
  // h_ratio_data_alpgen_lep_nu_dijet_m_xaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_lep_nu_dijet_m_yaxis->SetNdivisions(4,4,4);
  // h_ratio_data_alpgen_lep_nu_dijet_m_yaxis->SetTitle("(data-MC)/MC");
  // h_ratio_data_alpgen_lep_nu_dijet_m_yaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_lep_nu_dijet_m_yaxis->SetTitleOffset(0.36);
  // h_ratio_data_alpgen_lep_nu_dijet_m_yaxis->SetRangeUser(-1,1);

  // // data-sherpa(nom)/sherpa(nom)
  // string tc10_5_ratio_data_sherpa_lep_nu_dijet_m_name = "tc10_5_ratio_data_sherpa_lep_nu_dijet_m";
  // TH1F* h_ratio_data_sherpa_lep_nu_dijet_m = new TH1F(tc10_5_ratio_data_sherpa_lep_nu_dijet_m_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_sherpa_lep_nu_dijet_m->SetMarkerStyle(8);
  // h_ratio_data_sherpa_lep_nu_dijet_m->SetMarkerColor(kRed);


  // // data-alpgen(iqopt3)/alpgen(iqopt3)
  // string tc10_5_ratio_data_alpgen_iqopt3_lep_nu_dijet_m_name = "tc10_5_ratio_data_alpgen_iqopt3_lep_nu_dijet_m";
  // TH1F* h_ratio_data_alpgen_iqopt3_lep_nu_dijet_m = new TH1F(tc10_5_ratio_data_alpgen_iqopt3_lep_nu_dijet_m_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_iqopt3_lep_nu_dijet_m->SetMarkerStyle(8);
  // h_ratio_data_alpgen_iqopt3_lep_nu_dijet_m->SetMarkerColor(kGreen);

  // // data-alpgen(ptjmin10)/alpgen(ptjmin10)
  // string tc10_5_ratio_data_alpgen_ptjmin10_lep_nu_dijet_m_name = "tc10_5_ratio_data_alpgen_ptjmin10_lep_nu_dijet_m";
  // TH1F* h_ratio_data_alpgen_ptjmin10_lep_nu_dijet_m = new TH1F(tc10_5_ratio_data_alpgen_ptjmin10_lep_nu_dijet_m_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_ptjmin10_lep_nu_dijet_m->SetMarkerStyle(8);
  // h_ratio_data_alpgen_ptjmin10_lep_nu_dijet_m->SetMarkerColor(kBlue);

  
  // double tc10_5_data_alpgen_ratio=0.;
  // double tc10_5_data_sherpa_ratio=0.;
  // double tc10_5_data_alpgen_iqopt3_ratio=0.;
  // double tc10_5_data_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc10_5_alpgen_nom_bin_n=h_alpgen_nom_muon_lep_nu_dijet_m->GetBinContent(b);
  //   double tc10_5_alpgen_nom_bin_err=h_alpgen_nom_muon_lep_nu_dijet_m->GetBinError(b);    

  //   double tc10_5_data_bin_n=h_data_muon_lep_nu_dijet_m->GetBinContent(b);
  //   double tc10_5_data_bin_err=h_data_muon_lep_nu_dijet_m->GetBinError(b);    

  //   double tc10_5_sherpa_nom_bin_n=h_sherpa_nom_muon_lep_nu_dijet_m->GetBinContent(b);
  //   double tc10_5_sherpa_nom_bin_err=h_sherpa_nom_muon_lep_nu_dijet_m->GetBinError(b);    

  //   double tc10_5_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_muon_lep_nu_dijet_m->GetBinContent(b);
  //   double tc10_5_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_muon_lep_nu_dijet_m->GetBinError(b);

  //   double tc10_5_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_muon_lep_nu_dijet_m->GetBinContent(b);
  //   double tc10_5_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_muon_lep_nu_dijet_m->GetBinError(b);



  //   if(tc10_5_data_bin_n && tc10_5_alpgen_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc10_5_abs_data_alpgen_err = sqrt(pow(tc10_5_data_bin_err,2.)+pow(tc10_5_alpgen_nom_bin_err,2.));
  //     double tc10_5_rel_data_alpgen_err = tc10_5_abs_data_alpgen_err/(tc10_5_data_bin_n-tc10_5_alpgen_nom_bin_n);
  //     double tc10_5_rel_alpgen_err = tc10_5_alpgen_nom_bin_err/tc10_5_alpgen_nom_bin_n;
      
  //     double tc10_5_rel_ratio_data_alpgen_lep_nu_dijet_m_err = sqrt(pow(tc10_5_rel_data_alpgen_err,2.)+pow(tc10_5_rel_alpgen_err,2.));

  //     double tc10_5_data_alpgen_ratio = (tc10_5_data_bin_n-tc10_5_alpgen_nom_bin_n)/tc10_5_alpgen_nom_bin_n;

  //     double tc10_5_data_alpgen_ratio_err = fabs(tc10_5_rel_ratio_data_alpgen_lep_nu_dijet_m_err*tc10_5_data_alpgen_ratio);

  //     h_ratio_data_alpgen_lep_nu_dijet_m->SetBinContent(b,tc10_5_data_alpgen_ratio);
  //     h_ratio_data_alpgen_lep_nu_dijet_m->SetBinError(b,tc10_5_data_alpgen_ratio_err);
  //   }
    

  //   if(tc10_5_data_bin_n && tc10_5_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc10_5_abs_data_sherpa_err = sqrt(pow(tc10_5_data_bin_err,2.)+pow(tc10_5_sherpa_nom_bin_err,2.));
  //     double tc10_5_rel_data_sherpa_err = tc10_5_abs_data_sherpa_err/(tc10_5_data_bin_n-tc10_5_sherpa_nom_bin_n);
  //     double tc10_5_rel_sherpa_err = tc10_5_sherpa_nom_bin_err/tc10_5_sherpa_nom_bin_n;
      
  //     double tc10_5_rel_ratio_data_sherpa_lep_nu_dijet_m_err = sqrt(pow(tc10_5_rel_data_sherpa_err,2.)+pow(tc10_5_rel_sherpa_err,2.));

  //     double tc10_5_data_sherpa_ratio = (tc10_5_data_bin_n-tc10_5_sherpa_nom_bin_n)/tc10_5_sherpa_nom_bin_n;

  //     double tc10_5_data_sherpa_ratio_err = fabs(tc10_5_rel_ratio_data_sherpa_lep_nu_dijet_m_err*tc10_5_data_sherpa_ratio);

  //     h_ratio_data_sherpa_lep_nu_dijet_m->SetBinContent(b,tc10_5_data_sherpa_ratio);
  //     h_ratio_data_sherpa_lep_nu_dijet_m->SetBinError(b,tc10_5_data_sherpa_ratio_err);
  //   }
    

  //   if(tc10_5_data_bin_n && tc10_5_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc10_5_abs_data_alpgen_iqopt3_err = sqrt(pow(tc10_5_data_bin_err,2.)+pow(tc10_5_alpgen_iqopt3_bin_err,2.));
  //     double tc10_5_rel_data_alpgen_iqopt3_err = tc10_5_abs_data_alpgen_iqopt3_err/(tc10_5_data_bin_n-tc10_5_alpgen_iqopt3_bin_n);
  //     double tc10_5_rel_alpgen_iqopt3_err = tc10_5_alpgen_iqopt3_bin_err/tc10_5_alpgen_iqopt3_bin_n;
      
  //     double tc10_5_rel_ratio_data_alpgen_iqopt3_lep_nu_dijet_m_err = sqrt(pow(tc10_5_rel_data_alpgen_iqopt3_err,2.)+pow(tc10_5_rel_alpgen_iqopt3_err,2.));

  //     double tc10_5_data_alpgen_iqopt3_ratio = (tc10_5_data_bin_n-tc10_5_alpgen_iqopt3_bin_n)/tc10_5_alpgen_iqopt3_bin_n;

  //     double tc10_5_data_alpgen_iqopt3_ratio_err = fabs(tc10_5_rel_ratio_data_alpgen_iqopt3_lep_nu_dijet_m_err*tc10_5_data_alpgen_iqopt3_ratio);

  //     h_ratio_data_alpgen_iqopt3_lep_nu_dijet_m->SetBinContent(b,tc10_5_data_alpgen_iqopt3_ratio);
  //     h_ratio_data_alpgen_iqopt3_lep_nu_dijet_m->SetBinError(b,tc10_5_data_alpgen_iqopt3_ratio_err);
  //   }
    
  //   if(tc10_5_data_bin_n && tc10_5_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc10_5_abs_data_alpgen_ptjmin10_err = sqrt(pow(tc10_5_data_bin_err,2.)+pow(tc10_5_alpgen_ptjmin10_bin_err,2.));
  //     double tc10_5_rel_data_alpgen_ptjmin10_err = tc10_5_abs_data_alpgen_ptjmin10_err/(tc10_5_data_bin_n-tc10_5_alpgen_ptjmin10_bin_n);
  //     double tc10_5_rel_alpgen_ptjmin10_err = tc10_5_alpgen_ptjmin10_bin_err/tc10_5_alpgen_ptjmin10_bin_n;
      
  //     double tc10_5_rel_ratio_data_alpgen_ptjmin10_lep_nu_dijet_m_err = sqrt(pow(tc10_5_rel_data_alpgen_ptjmin10_err,2.)+pow(tc10_5_rel_alpgen_ptjmin10_err,2.));

  //     double tc10_5_data_alpgen_ptjmin10_ratio = (tc10_5_data_bin_n-tc10_5_alpgen_ptjmin10_bin_n)/tc10_5_alpgen_ptjmin10_bin_n;

  //     double tc10_5_data_alpgen_ptjmin10_ratio_err = fabs(tc10_5_rel_ratio_data_alpgen_ptjmin10_lep_nu_dijet_m_err*tc10_5_data_alpgen_ptjmin10_ratio);

  //     h_ratio_data_alpgen_ptjmin10_lep_nu_dijet_m->SetBinContent(b,tc10_5_data_alpgen_ptjmin10_ratio);
  //     h_ratio_data_alpgen_ptjmin10_lep_nu_dijet_m->SetBinError(b,tc10_5_data_alpgen_ptjmin10_ratio_err);
  //   }
  // }


  // h_ratio_data_alpgen_lep_nu_dijet_m->Draw("PE");
  // h_ratio_data_sherpa_lep_nu_dijet_m->Draw("PE sames");
  // h_ratio_data_alpgen_iqopt3_lep_nu_dijet_m->Draw("PE sames");
  // h_ratio_data_alpgen_ptjmin10_lep_nu_dijet_m->Draw("PE sames");
  
  // //  h_ratio_alpgen_iqopt3_lep_nu_dijet_m->Draw("PE sames");
  // //  h_ratio_alpgen_ptjmin10_lep_nu_dijet_m->Draw("PE sames");
  
  // tc10_5->Update();
  // tc10_5->SaveAs("./plots/latest/data_muon_lep_nu_dijet_m.png");
    
  // //NEXT
  
  // ////////////////////////////////////////////////// 
  // // tc11
  // // elec_met_dijet_mt: tc11_sherpa/alpgen+wjrw
  // ////////////////////////////////////////////////// 

  // string tc11_title = "MT(elec,MET,dijet) (elec)";
  // string tc11_name = "tc11";
  // TCanvas* tc11 = new TCanvas(tc11_name.c_str(),tc11_title.c_str(),0,0,1920,1200);
  // tc11->cd();

  // TPad* tc11_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc11_pad01->SetTopMargin(0.05);
  // tc11_pad01->SetBottomMargin(0.31);
  // tc11_pad01->Draw();

  // TPad* tc11_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc11_pad02->SetBottomMargin(0.0005);
  // tc11_pad02->SetLogy();
  // tc11_pad02->Draw();
  // tc11_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_elec_lep_met_dijet_mt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_purw_nom_lep_met_dijet_mt");
  // TH1F* h_alpgen_iqopt3_elec_lep_met_dijet_mt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_iqopt3_lep_met_dijet_mt");
  // TH1F* h_alpgen_ptjmin10_elec_lep_met_dijet_mt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_ptjmin10_lep_met_dijet_mt");
  // TH1F* h_sherpa_nom_elec_lep_met_dijet_mt = (TH1F*) wjets_sherpa_file->Get("all/h_elec_purw_nom_lep_met_dijet_mt");

  // //h_alpgen_nom_elec_lep_met_dijet_mt->SetLineWidth(2);
  // h_alpgen_nom_elec_lep_met_dijet_mt->SetMarkerStyle(20);
  // h_alpgen_nom_elec_lep_met_dijet_mt->SetMarkerSize(1.2);
  // h_alpgen_nom_elec_lep_met_dijet_mt->SetTitle("");
  // h_alpgen_nom_elec_lep_met_dijet_mt->Draw("PE");

  // //h_alpgen_iqopt3_elec_lep_met_dijet_mt->SetLineColor(kGreen);
  // h_alpgen_iqopt3_elec_lep_met_dijet_mt->SetMarkerStyle(22);
  // h_alpgen_iqopt3_elec_lep_met_dijet_mt->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_elec_lep_met_dijet_mt->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_elec_lep_met_dijet_mt->Draw("PE sames");

  // //  h_alpgen_ptjmin10_elec_lep_met_dijet_mt->SetLineColor(kBlue);
  // h_alpgen_ptjmin10_elec_lep_met_dijet_mt->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_elec_lep_met_dijet_mt->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_elec_lep_met_dijet_mt->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_elec_lep_met_dijet_mt->Draw("PE sames");

  // // h_sherpa_nom_elec_lep_met_dijet_mt->SetLineWidth(1.2);
  // // h_sherpa_nom_elec_lep_met_dijet_mt->SetLineColor(kRed);
  // h_sherpa_nom_elec_lep_met_dijet_mt->SetMarkerStyle(20);
  // h_sherpa_nom_elec_lep_met_dijet_mt->SetMarkerSize(1.2);
  // h_sherpa_nom_elec_lep_met_dijet_mt->SetMarkerColor(kRed);
  // h_sherpa_nom_elec_lep_met_dijet_mt->Draw("PE sames");


  // //Legend
  // TLegend* lgnd_tc11 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc11->SetFillColor(0);
  // lgnd_tc11->SetTextSize(0.03);
  // lgnd_tc11->SetBorderSize(0);

  // char lgnd_alpgen_nom_elec_lep_met_dijet_mt_name[20];
  // sprintf(lgnd_alpgen_nom_elec_lep_met_dijet_mt_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_elec_lep_met_dijet_mt->Integral());
  // lgnd_tc11->AddEntry(h_alpgen_nom_elec_lep_met_dijet_mt,lgnd_alpgen_nom_elec_lep_met_dijet_mt_name,"p");

  // char lgnd_alpgen_iqopt3_elec_lep_met_dijet_mt_name[20];
  // sprintf(lgnd_alpgen_iqopt3_elec_lep_met_dijet_mt_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_elec_lep_met_dijet_mt->Integral());
  // lgnd_tc11->AddEntry(h_alpgen_iqopt3_elec_lep_met_dijet_mt,lgnd_alpgen_iqopt3_elec_lep_met_dijet_mt_name,"p");

  // char lgnd_alpgen_ptjmin10_elec_lep_met_dijet_mt_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_elec_lep_met_dijet_mt_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_elec_lep_met_dijet_mt->Integral());
  // lgnd_tc11->AddEntry(h_alpgen_ptjmin10_elec_lep_met_dijet_mt,lgnd_alpgen_ptjmin10_elec_lep_met_dijet_mt_name,"p");

  // char lgnd_sherpa_nom_elec_lep_met_dijet_mt_name[20];
  // sprintf(lgnd_sherpa_nom_elec_lep_met_dijet_mt_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_elec_lep_met_dijet_mt->Integral());
  // lgnd_tc11->AddEntry(h_sherpa_nom_elec_lep_met_dijet_mt,lgnd_sherpa_nom_elec_lep_met_dijet_mt_name,"p");

  // lgnd_tc11->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc11_pad01->cd();
  // tc11_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_elec_lep_met_dijet_mt->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_elec_lep_met_dijet_mt->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_elec_lep_met_dijet_mt->GetXaxis())->GetXmax();

  // // alp-sherp/sherp
  // string tc11_ratio_alpgen_sherpa_elec_met_dijet_mt_name = "tc11_ratio_alpgen_sherpa_elec_met_dijet_mt";
  // TH1F* h_ratio_alpgen_sherpa_elec_met_dijet_mt = new TH1F(tc11_ratio_alpgen_sherpa_elec_met_dijet_mt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_sherpa_elec_met_dijet_mt->SetMarkerStyle(8);
  // h_ratio_alpgen_sherpa_elec_met_dijet_mt->SetMarkerColor(kRed);

  // TAxis* h_ratio_alpgen_sherpa_elec_met_dijet_mt_xaxis = h_ratio_alpgen_sherpa_elec_met_dijet_mt->GetXaxis();
  // TAxis* h_ratio_alpgen_sherpa_elec_met_dijet_mt_yaxis = h_ratio_alpgen_sherpa_elec_met_dijet_mt->GetYaxis();
  
  // h_ratio_alpgen_sherpa_elec_met_dijet_mt_xaxis->SetLabelSize(0.08);
  // h_ratio_alpgen_sherpa_elec_met_dijet_mt_yaxis->SetLabelSize(0.08);

  // h_ratio_alpgen_sherpa_elec_met_dijet_mt_xaxis->SetTitle("MT(elec,MET,dijet)");
  // h_ratio_alpgen_sherpa_elec_met_dijet_mt_xaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_elec_met_dijet_mt_yaxis->SetNdivisions(4,4,4);
  // h_ratio_alpgen_sherpa_elec_met_dijet_mt_yaxis->SetTitle("(alpgen-MC)/MC");
  // h_ratio_alpgen_sherpa_elec_met_dijet_mt_yaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_elec_met_dijet_mt_yaxis->SetTitleOffset(0.36);
  // h_ratio_alpgen_sherpa_elec_met_dijet_mt_yaxis->SetRangeUser(-1,1);

  
  // // alp-iqopt3/iqopt3
  // string tc11_ratio_alpgen_iqopt3_elec_met_dijet_mt_name = "tc11_ratio_alpgen_iqopt3_elec_met_dijet_mt";
  // TH1F* h_ratio_alpgen_iqopt3_elec_met_dijet_mt = new TH1F(tc11_ratio_alpgen_iqopt3_elec_met_dijet_mt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_iqopt3_elec_met_dijet_mt->SetMarkerStyle(8);
  // h_ratio_alpgen_iqopt3_elec_met_dijet_mt->SetMarkerColor(kGreen);

  
  // // alp-ptjmin10/ptjmin10
  // string tc11_ratio_alpgen_ptjmin10_elec_met_dijet_mt_name = "tc11_ratio_alpgen_ptjmin10_elec_met_dijet_mt";
  // TH1F* h_ratio_alpgen_ptjmin10_elec_met_dijet_mt = new TH1F(tc11_ratio_alpgen_ptjmin10_elec_met_dijet_mt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_ptjmin10_elec_met_dijet_mt->SetMarkerStyle(8);
  // h_ratio_alpgen_ptjmin10_elec_met_dijet_mt->SetMarkerColor(kBlue);


  
  // double tc11_alpgen_sherpa_ratio=0.;
  // double tc11_alpgen_iqopt3_ratio=0.;
  // double tc11_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc11_alpgen_nom_bin_n=h_alpgen_nom_elec_lep_met_dijet_mt->GetBinContent(b);
  //   double tc11_alpgen_nom_bin_err=h_alpgen_nom_elec_lep_met_dijet_mt->GetBinError(b);    

  //   double tc11_sherpa_nom_bin_n=h_sherpa_nom_elec_lep_met_dijet_mt->GetBinContent(b);
  //   double tc11_sherpa_nom_bin_err=h_sherpa_nom_elec_lep_met_dijet_mt->GetBinError(b);    

  //   double tc11_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_elec_lep_met_dijet_mt->GetBinContent(b);
  //   double tc11_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_elec_lep_met_dijet_mt->GetBinError(b);

  //   double tc11_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_elec_lep_met_dijet_mt->GetBinContent(b);
  //   double tc11_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_elec_lep_met_dijet_mt->GetBinError(b);



  //   if(tc11_alpgen_nom_bin_n && tc11_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc11_abs_alpgen_sherpa_err = sqrt(pow(tc11_alpgen_nom_bin_err,2.)+pow(tc11_sherpa_nom_bin_err,2.));
  //     double tc11_rel_alpgen_sherpa_err = tc11_abs_alpgen_sherpa_err/(tc11_alpgen_nom_bin_n-tc11_sherpa_nom_bin_n);
  //     double tc11_rel_sherpa_err = tc11_sherpa_nom_bin_err/tc11_sherpa_nom_bin_n;
      
  //     double tc11_rel_ratio_alpgen_sherpa_elec_met_dijet_mt_err = sqrt(pow(tc11_rel_alpgen_sherpa_err,2.)+pow(tc11_rel_sherpa_err,2.));

  //     double tc11_alpgen_sherpa_ratio = (tc11_alpgen_nom_bin_n-tc11_sherpa_nom_bin_n)/tc11_sherpa_nom_bin_n;

  //     double tc11_alpgen_sherpa_ratio_err = fabs(tc11_rel_ratio_alpgen_sherpa_elec_met_dijet_mt_err*tc11_alpgen_sherpa_ratio);

  //     h_ratio_alpgen_sherpa_elec_met_dijet_mt->SetBinContent(b,tc11_alpgen_sherpa_ratio);
  //     h_ratio_alpgen_sherpa_elec_met_dijet_mt->SetBinError(b,tc11_alpgen_sherpa_ratio_err);
  //   }
    

  //   if(tc11_alpgen_nom_bin_n && tc11_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc11_abs_alpgen_iqopt3_err = sqrt(pow(tc11_alpgen_nom_bin_err,2.)+pow(tc11_alpgen_iqopt3_bin_err,2.));
  //     double tc11_rel_alpgen_iqopt3_err = tc11_abs_alpgen_iqopt3_err/(tc11_alpgen_nom_bin_n-tc11_alpgen_iqopt3_bin_n);
  //     double tc11_rel_iqopt3_err = tc11_alpgen_iqopt3_bin_err/tc11_alpgen_iqopt3_bin_n;
      
  //     double tc11_rel_ratio_alpgen_iqopt3_elec_met_dijet_mt_err = sqrt(pow(tc11_rel_alpgen_iqopt3_err,2.)+pow(tc11_rel_iqopt3_err,2.));

  //     double tc11_alpgen_iqopt3_ratio = (tc11_alpgen_nom_bin_n-tc11_alpgen_iqopt3_bin_n)/tc11_alpgen_iqopt3_bin_n;

  //     double tc11_alpgen_iqopt3_ratio_err = fabs(tc11_rel_ratio_alpgen_iqopt3_elec_met_dijet_mt_err*tc11_alpgen_iqopt3_ratio);

  //     h_ratio_alpgen_iqopt3_elec_met_dijet_mt->SetBinContent(b,tc11_alpgen_iqopt3_ratio);
  //     h_ratio_alpgen_iqopt3_elec_met_dijet_mt->SetBinError(b,tc11_alpgen_iqopt3_ratio_err);
  //   }

    

  //   if(tc11_alpgen_nom_bin_n && tc11_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc11_abs_alpgen_ptjmin10_err = sqrt(pow(tc11_alpgen_nom_bin_err,2.)+pow(tc11_alpgen_ptjmin10_bin_err,2.));
  //     double tc11_rel_alpgen_ptjmin10_err = tc11_abs_alpgen_ptjmin10_err/(tc11_alpgen_nom_bin_n-tc11_alpgen_ptjmin10_bin_n);
  //     double tc11_rel_ptjmin10_err = tc11_alpgen_ptjmin10_bin_err/tc11_alpgen_ptjmin10_bin_n;
      
  //     double tc11_rel_ratio_alpgen_ptjmin10_elec_met_dijet_mt_err = sqrt(pow(tc11_rel_alpgen_ptjmin10_err,2.)+pow(tc11_rel_ptjmin10_err,2.));

  //     double tc11_alpgen_ptjmin10_ratio = (tc11_alpgen_nom_bin_n-tc11_alpgen_ptjmin10_bin_n)/tc11_alpgen_ptjmin10_bin_n;

  //     double tc11_alpgen_ptjmin10_ratio_err = fabs(tc11_rel_ratio_alpgen_ptjmin10_elec_met_dijet_mt_err*tc11_alpgen_ptjmin10_ratio);

  //     h_ratio_alpgen_ptjmin10_elec_met_dijet_mt->SetBinContent(b,tc11_alpgen_ptjmin10_ratio);
  //     h_ratio_alpgen_ptjmin10_elec_met_dijet_mt->SetBinError(b,tc11_alpgen_ptjmin10_ratio_err);
  //   }
    
  // }


  // h_ratio_alpgen_sherpa_elec_met_dijet_mt->Draw("PE");
  // h_ratio_alpgen_iqopt3_elec_met_dijet_mt->Draw("PE sames");
  // h_ratio_alpgen_ptjmin10_elec_met_dijet_mt->Draw("PE sames");
  
  // tc11->Update();

  // tc11->SaveAs("./plots/latest/elec_lep_met_dijet_mt.png");
  

  // //NEXT
  
  // //////////////////////////////////////////////////
  // // tc11_5
  // // data_elec_lep_met_dijet_mt: sherpa/alpgen+wjrw
  // //////////////////////////////////////////////////
  
  // string tc11_5_title = "MT(elec,MET,dijet) (elec) w/ Data";
  // string tc11_5_name = "tc11_5";
  // TCanvas* tc11_5 = new TCanvas(tc11_5_name.c_str(),tc11_5_title.c_str(),0,0,1920,1200);
  // tc11_5->cd();

  // TPad* tc11_5_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc11_5_pad01->SetTopMargin(0.05);
  // tc11_5_pad01->SetBottomMargin(0.31);
  // tc11_5_pad01->Draw();

  // TPad* tc11_5_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc11_5_pad02->SetBottomMargin(0.0005);
  // tc11_5_pad02->SetLogy();
  // tc11_5_pad02->Draw();
  // tc11_5_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_elec_lep_met_dijet_mt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_purw_nom_lep_met_dijet_mt");
  // TH1F* h_alpgen_iqopt3_elec_lep_met_dijet_mt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_iqopt3_lep_met_dijet_mt");
  // TH1F* h_alpgen_ptjmin10_elec_lep_met_dijet_mt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_ptjmin10_lep_met_dijet_mt");
  // TH1F* h_sherpa_nom_elec_lep_met_dijet_mt = (TH1F*) wjets_sherpa_file->Get("all/h_elec_purw_nom_lep_met_dijet_mt");
  // TH1F* h_data_elec_lep_met_dijet_mt = (TH1F*) data_file->Get("all/h_elec_purw_nom_lep_met_dijet_mt");

  // TH1F* h_top_elec_lep_met_dijet_mt = (TH1F*) top_mcatnlo_file->Get("all/h_elec_purw_nom_lep_met_dijet_mt");
  // TH1F* h_zjets_elec_lep_met_dijet_mt = (TH1F*) zjets_alpgen_file->Get("all/h_elec_purw_nom_lep_met_dijet_mt");
  // TH1F* h_vv_elec_lep_met_dijet_mt = (TH1F*) vv_herwig_file->Get("all/h_elec_purw_nom_lep_met_dijet_mt");
  // TH1F* h_qcd_elec_lep_met_dijet_mt = (TH1F*) qcd_file->Get("all/h_elec_purw_nom_lep_met_dijet_mt");
  
  // h_data_elec_lep_met_dijet_mt->SetTitle("");
  // h_data_elec_lep_met_dijet_mt->Draw();
  
  // //Add Backgrounds
  // h_alpgen_nom_elec_lep_met_dijet_mt->Add(h_top_elec_lep_met_dijet_mt);
  // h_alpgen_nom_elec_lep_met_dijet_mt->Add(h_zjets_elec_lep_met_dijet_mt);
  // h_alpgen_nom_elec_lep_met_dijet_mt->Add(h_vv_elec_lep_met_dijet_mt);
  // h_alpgen_nom_elec_lep_met_dijet_mt->Add(h_qcd_elec_lep_met_dijet_mt);
  
  // h_alpgen_nom_elec_lep_met_dijet_mt->SetMarkerStyle(20);
  // h_alpgen_nom_elec_lep_met_dijet_mt->SetMarkerSize(1.2);
  // h_alpgen_nom_elec_lep_met_dijet_mt->Draw("PE sames");

  // //Add backgrounds
  // h_alpgen_iqopt3_elec_lep_met_dijet_mt->Add(h_top_elec_lep_met_dijet_mt);
  // h_alpgen_iqopt3_elec_lep_met_dijet_mt->Add(h_zjets_elec_lep_met_dijet_mt);
  // h_alpgen_iqopt3_elec_lep_met_dijet_mt->Add(h_vv_elec_lep_met_dijet_mt);
  // h_alpgen_iqopt3_elec_lep_met_dijet_mt->Add(h_qcd_elec_lep_met_dijet_mt);

  // h_alpgen_iqopt3_elec_lep_met_dijet_mt->SetMarkerStyle(22);
  // h_alpgen_iqopt3_elec_lep_met_dijet_mt->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_elec_lep_met_dijet_mt->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_elec_lep_met_dijet_mt->Draw("PE sames");

  // //Add Backgrounds
  // h_alpgen_ptjmin10_elec_lep_met_dijet_mt->Add(h_top_elec_lep_met_dijet_mt);
  // h_alpgen_ptjmin10_elec_lep_met_dijet_mt->Add(h_zjets_elec_lep_met_dijet_mt);
  // h_alpgen_ptjmin10_elec_lep_met_dijet_mt->Add(h_vv_elec_lep_met_dijet_mt);
  // h_alpgen_ptjmin10_elec_lep_met_dijet_mt->Add(h_qcd_elec_lep_met_dijet_mt);

  // h_alpgen_ptjmin10_elec_lep_met_dijet_mt->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_elec_lep_met_dijet_mt->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_elec_lep_met_dijet_mt->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_elec_lep_met_dijet_mt->Draw("PE sames");

  // //Add Backgrounds
  // h_sherpa_nom_elec_lep_met_dijet_mt->Add(h_top_elec_lep_met_dijet_mt);
  // h_sherpa_nom_elec_lep_met_dijet_mt->Add(h_zjets_elec_lep_met_dijet_mt);
  // h_sherpa_nom_elec_lep_met_dijet_mt->Add(h_vv_elec_lep_met_dijet_mt);
  // h_sherpa_nom_elec_lep_met_dijet_mt->Add(h_qcd_elec_lep_met_dijet_mt);

  // h_sherpa_nom_elec_lep_met_dijet_mt->SetMarkerStyle(20);
  // h_sherpa_nom_elec_lep_met_dijet_mt->SetMarkerSize(1.2);
  // h_sherpa_nom_elec_lep_met_dijet_mt->SetMarkerColor(kRed);
  // h_sherpa_nom_elec_lep_met_dijet_mt->Draw("PE sames");




  // //Legend
  // TLegend* lgnd_tc11_5 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc11_5->SetFillColor(0);
  // lgnd_tc11_5->SetTextSize(0.03);
  // lgnd_tc11_5->SetBorderSize(0);


  // char lgnd_data_elec_lep_met_dijet_mt_name[20];
  // sprintf(lgnd_data_elec_lep_met_dijet_mt_name,"%s,  %.2f","DATA",h_data_elec_lep_met_dijet_mt->Integral());
  // lgnd_tc11_5->AddEntry(h_data_elec_lep_met_dijet_mt,lgnd_data_elec_lep_met_dijet_mt_name,"f");

  // char lgnd_alpgen_nom_elec_lep_met_dijet_mt_name[20];
  // sprintf(lgnd_alpgen_nom_elec_lep_met_dijet_mt_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_elec_lep_met_dijet_mt->Integral());
  // lgnd_tc11_5->AddEntry(h_alpgen_nom_elec_lep_met_dijet_mt,lgnd_alpgen_nom_elec_lep_met_dijet_mt_name,"p");

  // char lgnd_alpgen_iqopt3_elec_lep_met_dijet_mt_name[20];
  // sprintf(lgnd_alpgen_iqopt3_elec_lep_met_dijet_mt_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_elec_lep_met_dijet_mt->Integral());
  // lgnd_tc11_5->AddEntry(h_alpgen_iqopt3_elec_lep_met_dijet_mt,lgnd_alpgen_iqopt3_elec_lep_met_dijet_mt_name,"p");

  // char lgnd_alpgen_ptjmin10_elec_lep_met_dijet_mt_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_elec_lep_met_dijet_mt_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_elec_lep_met_dijet_mt->Integral());
  // lgnd_tc11_5->AddEntry(h_alpgen_ptjmin10_elec_lep_met_dijet_mt,lgnd_alpgen_ptjmin10_elec_lep_met_dijet_mt_name,"p");

  // char lgnd_sherpa_nom_elec_lep_met_dijet_mt_name[20];
  // sprintf(lgnd_sherpa_nom_elec_lep_met_dijet_mt_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_elec_lep_met_dijet_mt->Integral());
  // lgnd_tc11_5->AddEntry(h_sherpa_nom_elec_lep_met_dijet_mt,lgnd_sherpa_nom_elec_lep_met_dijet_mt_name,"p");

  // lgnd_tc11_5->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc11_5_pad01->cd();
  // tc11_5_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_elec_lep_met_dijet_mt->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_elec_lep_met_dijet_mt->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_elec_lep_met_dijet_mt->GetXaxis())->GetXmax();

  // // data-alpgen(nom)/alpgen(nom)
  // string tc11_5_ratio_data_alpgen_lep_met_dijet_mt_name = "tc11_5_ratio_data_alpgen_lep_met_dijet_mt";
  // TH1F* h_ratio_data_alpgen_lep_met_dijet_mt = new TH1F(tc11_5_ratio_data_alpgen_lep_met_dijet_mt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_lep_met_dijet_mt->SetMarkerStyle(8);
  // //h_ratio_data_alpgen_lep_met_dijet_mt->SetMarkerColor(kRed);

  // TAxis* h_ratio_data_alpgen_lep_met_dijet_mt_xaxis = h_ratio_data_alpgen_lep_met_dijet_mt->GetXaxis();
  // TAxis* h_ratio_data_alpgen_lep_met_dijet_mt_yaxis = h_ratio_data_alpgen_lep_met_dijet_mt->GetYaxis();
  
  // h_ratio_data_alpgen_lep_met_dijet_mt_xaxis->SetLabelSize(0.08);
  // h_ratio_data_alpgen_lep_met_dijet_mt_yaxis->SetLabelSize(0.08);

  // h_ratio_data_alpgen_lep_met_dijet_mt_xaxis->SetTitle("MT(elec,MET,dijet)");
  // h_ratio_data_alpgen_lep_met_dijet_mt_xaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_lep_met_dijet_mt_yaxis->SetNdivisions(4,4,4);
  // h_ratio_data_alpgen_lep_met_dijet_mt_yaxis->SetTitle("(data-MC)/MC");
  // h_ratio_data_alpgen_lep_met_dijet_mt_yaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_lep_met_dijet_mt_yaxis->SetTitleOffset(0.36);
  // h_ratio_data_alpgen_lep_met_dijet_mt_yaxis->SetRangeUser(-1,1);

  // // data-sherpa(nom)/sherpa(nom)
  // string tc11_5_ratio_data_sherpa_lep_met_dijet_mt_name = "tc11_5_ratio_data_sherpa_lep_met_dijet_mt";
  // TH1F* h_ratio_data_sherpa_lep_met_dijet_mt = new TH1F(tc11_5_ratio_data_sherpa_lep_met_dijet_mt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_sherpa_lep_met_dijet_mt->SetMarkerStyle(8);
  // h_ratio_data_sherpa_lep_met_dijet_mt->SetMarkerColor(kRed);


  // // data-alpgen(iqopt3)/alpgen(iqopt3)
  // string tc11_5_ratio_data_alpgen_iqopt3_lep_met_dijet_mt_name = "tc11_5_ratio_data_alpgen_iqopt3_lep_met_dijet_mt";
  // TH1F* h_ratio_data_alpgen_iqopt3_lep_met_dijet_mt = new TH1F(tc11_5_ratio_data_alpgen_iqopt3_lep_met_dijet_mt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_iqopt3_lep_met_dijet_mt->SetMarkerStyle(8);
  // h_ratio_data_alpgen_iqopt3_lep_met_dijet_mt->SetMarkerColor(kGreen);

  // // data-alpgen(ptjmin10)/alpgen(ptjmin10)
  // string tc11_5_ratio_data_alpgen_ptjmin10_lep_met_dijet_mt_name = "tc11_5_ratio_data_alpgen_ptjmin10_lep_met_dijet_mt";
  // TH1F* h_ratio_data_alpgen_ptjmin10_lep_met_dijet_mt = new TH1F(tc11_5_ratio_data_alpgen_ptjmin10_lep_met_dijet_mt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_ptjmin10_lep_met_dijet_mt->SetMarkerStyle(8);
  // h_ratio_data_alpgen_ptjmin10_lep_met_dijet_mt->SetMarkerColor(kBlue);

  

  
  // // // alp-iqopt3/iqopt3
  // // string tc11_5_ratio_alpgen_iqopt3_lead_jet_pt_name = "tc11_5_ratio_alpgen_iqopt3_lead_jet_pt";
  // // TH1F* h_ratio_alpgen_iqopt3_lead_jet_pt = new TH1F(tc11_5_ratio_alpgen_iqopt3_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerStyle(8);
  // // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerColor(kGreen);

  
  // // // alp-ptjmin10/ptjmin10
  // // string tc11_5_ratio_alpgen_ptjmin10_lead_jet_pt_name = "tc11_5_ratio_alpgen_ptjmin10_lead_jet_pt";
  // // TH1F* h_ratio_alpgen_ptjmin10_lead_jet_pt = new TH1F(tc11_5_ratio_alpgen_ptjmin10_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerStyle(8);
  // // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerColor(kBlue);


  
  // double tc11_5_data_alpgen_ratio=0.;
  // double tc11_5_data_sherpa_ratio=0.;
  // double tc11_5_data_alpgen_iqopt3_ratio=0.;
  // double tc11_5_data_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc11_5_alpgen_nom_bin_n=h_alpgen_nom_elec_lep_met_dijet_mt->GetBinContent(b);
  //   double tc11_5_alpgen_nom_bin_err=h_alpgen_nom_elec_lep_met_dijet_mt->GetBinError(b);    

  //   double tc11_5_data_bin_n=h_data_elec_lep_met_dijet_mt->GetBinContent(b);
  //   double tc11_5_data_bin_err=h_data_elec_lep_met_dijet_mt->GetBinError(b);    

  //   double tc11_5_sherpa_nom_bin_n=h_sherpa_nom_elec_lep_met_dijet_mt->GetBinContent(b);
  //   double tc11_5_sherpa_nom_bin_err=h_sherpa_nom_elec_lep_met_dijet_mt->GetBinError(b);    

  //   double tc11_5_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_elec_lep_met_dijet_mt->GetBinContent(b);
  //   double tc11_5_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_elec_lep_met_dijet_mt->GetBinError(b);

  //   double tc11_5_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_elec_lep_met_dijet_mt->GetBinContent(b);
  //   double tc11_5_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_elec_lep_met_dijet_mt->GetBinError(b);



  //   if(tc11_5_data_bin_n && tc11_5_alpgen_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc11_5_abs_data_alpgen_err = sqrt(pow(tc11_5_data_bin_err,2.)+pow(tc11_5_alpgen_nom_bin_err,2.));
  //     double tc11_5_rel_data_alpgen_err = tc11_5_abs_data_alpgen_err/(tc11_5_data_bin_n-tc11_5_alpgen_nom_bin_n);
  //     double tc11_5_rel_alpgen_err = tc11_5_alpgen_nom_bin_err/tc11_5_alpgen_nom_bin_n;
      
  //     double tc11_5_rel_ratio_data_alpgen_lep_met_dijet_mt_err = sqrt(pow(tc11_5_rel_data_alpgen_err,2.)+pow(tc11_5_rel_alpgen_err,2.));

  //     double tc11_5_data_alpgen_ratio = (tc11_5_data_bin_n-tc11_5_alpgen_nom_bin_n)/tc11_5_alpgen_nom_bin_n;

  //     double tc11_5_data_alpgen_ratio_err = fabs(tc11_5_rel_ratio_data_alpgen_lep_met_dijet_mt_err*tc11_5_data_alpgen_ratio);

  //     h_ratio_data_alpgen_lep_met_dijet_mt->SetBinContent(b,tc11_5_data_alpgen_ratio);
  //     h_ratio_data_alpgen_lep_met_dijet_mt->SetBinError(b,tc11_5_data_alpgen_ratio_err);
  //   }
    

  //   if(tc11_5_data_bin_n && tc11_5_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc11_5_abs_data_sherpa_err = sqrt(pow(tc11_5_data_bin_err,2.)+pow(tc11_5_sherpa_nom_bin_err,2.));
  //     double tc11_5_rel_data_sherpa_err = tc11_5_abs_data_sherpa_err/(tc11_5_data_bin_n-tc11_5_sherpa_nom_bin_n);
  //     double tc11_5_rel_sherpa_err = tc11_5_sherpa_nom_bin_err/tc11_5_sherpa_nom_bin_n;
      
  //     double tc11_5_rel_ratio_data_sherpa_lep_met_dijet_mt_err = sqrt(pow(tc11_5_rel_data_sherpa_err,2.)+pow(tc11_5_rel_sherpa_err,2.));

  //     double tc11_5_data_sherpa_ratio = (tc11_5_data_bin_n-tc11_5_sherpa_nom_bin_n)/tc11_5_sherpa_nom_bin_n;

  //     double tc11_5_data_sherpa_ratio_err = fabs(tc11_5_rel_ratio_data_sherpa_lep_met_dijet_mt_err*tc11_5_data_sherpa_ratio);

  //     h_ratio_data_sherpa_lep_met_dijet_mt->SetBinContent(b,tc11_5_data_sherpa_ratio);
  //     h_ratio_data_sherpa_lep_met_dijet_mt->SetBinError(b,tc11_5_data_sherpa_ratio_err);
  //   }
    

  //   if(tc11_5_data_bin_n && tc11_5_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc11_5_abs_data_alpgen_iqopt3_err = sqrt(pow(tc11_5_data_bin_err,2.)+pow(tc11_5_alpgen_iqopt3_bin_err,2.));
  //     double tc11_5_rel_data_alpgen_iqopt3_err = tc11_5_abs_data_alpgen_iqopt3_err/(tc11_5_data_bin_n-tc11_5_alpgen_iqopt3_bin_n);
  //     double tc11_5_rel_alpgen_iqopt3_err = tc11_5_alpgen_iqopt3_bin_err/tc11_5_alpgen_iqopt3_bin_n;
      
  //     double tc11_5_rel_ratio_data_alpgen_iqopt3_lep_met_dijet_mt_err = sqrt(pow(tc11_5_rel_data_alpgen_iqopt3_err,2.)+pow(tc11_5_rel_alpgen_iqopt3_err,2.));

  //     double tc11_5_data_alpgen_iqopt3_ratio = (tc11_5_data_bin_n-tc11_5_alpgen_iqopt3_bin_n)/tc11_5_alpgen_iqopt3_bin_n;

  //     double tc11_5_data_alpgen_iqopt3_ratio_err = fabs(tc11_5_rel_ratio_data_alpgen_iqopt3_lep_met_dijet_mt_err*tc11_5_data_alpgen_iqopt3_ratio);

  //     h_ratio_data_alpgen_iqopt3_lep_met_dijet_mt->SetBinContent(b,tc11_5_data_alpgen_iqopt3_ratio);
  //     h_ratio_data_alpgen_iqopt3_lep_met_dijet_mt->SetBinError(b,tc11_5_data_alpgen_iqopt3_ratio_err);
  //   }
    
  //   if(tc11_5_data_bin_n && tc11_5_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc11_5_abs_data_alpgen_ptjmin10_err = sqrt(pow(tc11_5_data_bin_err,2.)+pow(tc11_5_alpgen_ptjmin10_bin_err,2.));
  //     double tc11_5_rel_data_alpgen_ptjmin10_err = tc11_5_abs_data_alpgen_ptjmin10_err/(tc11_5_data_bin_n-tc11_5_alpgen_ptjmin10_bin_n);
  //     double tc11_5_rel_alpgen_ptjmin10_err = tc11_5_alpgen_ptjmin10_bin_err/tc11_5_alpgen_ptjmin10_bin_n;
      
  //     double tc11_5_rel_ratio_data_alpgen_ptjmin10_lep_met_dijet_mt_err = sqrt(pow(tc11_5_rel_data_alpgen_ptjmin10_err,2.)+pow(tc11_5_rel_alpgen_ptjmin10_err,2.));

  //     double tc11_5_data_alpgen_ptjmin10_ratio = (tc11_5_data_bin_n-tc11_5_alpgen_ptjmin10_bin_n)/tc11_5_alpgen_ptjmin10_bin_n;

  //     double tc11_5_data_alpgen_ptjmin10_ratio_err = fabs(tc11_5_rel_ratio_data_alpgen_ptjmin10_lep_met_dijet_mt_err*tc11_5_data_alpgen_ptjmin10_ratio);

  //     h_ratio_data_alpgen_ptjmin10_lep_met_dijet_mt->SetBinContent(b,tc11_5_data_alpgen_ptjmin10_ratio);
  //     h_ratio_data_alpgen_ptjmin10_lep_met_dijet_mt->SetBinError(b,tc11_5_data_alpgen_ptjmin10_ratio_err);
  //   }
  // }


  // h_ratio_data_alpgen_lep_met_dijet_mt->Draw("PE");
  // h_ratio_data_sherpa_lep_met_dijet_mt->Draw("PE sames");
  // h_ratio_data_alpgen_iqopt3_lep_met_dijet_mt->Draw("PE sames");
  // h_ratio_data_alpgen_ptjmin10_lep_met_dijet_mt->Draw("PE sames");
  
  // //  h_ratio_alpgen_iqopt3_lep_met_dijet_mt->Draw("PE sames");
  // //  h_ratio_alpgen_ptjmin10_lep_met_dijet_mt->Draw("PE sames");
  
  // tc11_5->Update();
  // tc11_5->SaveAs("./plots/latest/data_elec_lep_met_dijet_mt.png");
    
  // //NEXT

  // ////////////////////////////////////////////////// 
  // // tc12
  // // muon_lep_met_dijet_mt: tc12_sherpa/alpgen+wjrw
  // ////////////////////////////////////////////////// 

  // string tc12_title = "MT(muon,MET,dijet) (muon)";
  // string tc12_name = "tc12";
  // TCanvas* tc12 = new TCanvas(tc12_name.c_str(),tc12_title.c_str(),0,0,1920,1200);
  // tc12->cd();

  // TPad* tc12_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc12_pad01->SetTopMargin(0.05);
  // tc12_pad01->SetBottomMargin(0.31);
  // tc12_pad01->Draw();

  // TPad* tc12_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc12_pad02->SetBottomMargin(0.0005);
  // tc12_pad02->SetLogy();
  // tc12_pad02->Draw();
  // tc12_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_muon_lep_met_dijet_mt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_purw_nom_lep_met_dijet_mt");
  // TH1F* h_alpgen_iqopt3_muon_lep_met_dijet_mt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_iqopt3_lep_met_dijet_mt");
  // TH1F* h_alpgen_ptjmin10_muon_lep_met_dijet_mt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_ptjmin10_lep_met_dijet_mt");
  // TH1F* h_sherpa_nom_muon_lep_met_dijet_mt = (TH1F*) wjets_sherpa_file->Get("all/h_muon_purw_nom_lep_met_dijet_mt");

  // //h_alpgen_nom_muon_lep_met_dijet_mt->SetLineWidth(2);
  // h_alpgen_nom_muon_lep_met_dijet_mt->SetMarkerStyle(20);
  // h_alpgen_nom_muon_lep_met_dijet_mt->SetMarkerSize(1.2);
  // h_alpgen_nom_muon_lep_met_dijet_mt->SetTitle("");
  // h_alpgen_nom_muon_lep_met_dijet_mt->Draw("PE");

  // //h_alpgen_iqopt3_muon_lep_met_dijet_mt->SetLineColor(kGreen);
  // h_alpgen_iqopt3_muon_lep_met_dijet_mt->SetMarkerStyle(22);
  // h_alpgen_iqopt3_muon_lep_met_dijet_mt->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_muon_lep_met_dijet_mt->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_muon_lep_met_dijet_mt->Draw("PE sames");

  // //  h_alpgen_ptjmin10_muon_lep_met_dijet_mt->SetLineColor(kBlue);
  // h_alpgen_ptjmin10_muon_lep_met_dijet_mt->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_muon_lep_met_dijet_mt->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_muon_lep_met_dijet_mt->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_muon_lep_met_dijet_mt->Draw("PE sames");

  // // h_sherpa_nom_muon_lep_met_dijet_mt->SetLineWidth(1.2);
  // // h_sherpa_nom_muon_lep_met_dijet_mt->SetLineColor(kRed);
  // h_sherpa_nom_muon_lep_met_dijet_mt->SetMarkerStyle(20);
  // h_sherpa_nom_muon_lep_met_dijet_mt->SetMarkerSize(1.2);
  // h_sherpa_nom_muon_lep_met_dijet_mt->SetMarkerColor(kRed);
  // h_sherpa_nom_muon_lep_met_dijet_mt->Draw("PE sames");


  // //Legend
  // TLegend* lgnd_tc12 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc12->SetFillColor(0);
  // lgnd_tc12->SetTextSize(0.03);
  // lgnd_tc12->SetBorderSize(0);

  // char lgnd_alpgen_nom_muon_lep_met_dijet_mt_name[20];
  // sprintf(lgnd_alpgen_nom_muon_lep_met_dijet_mt_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_muon_lep_met_dijet_mt->Integral());
  // lgnd_tc12->AddEntry(h_alpgen_nom_muon_lep_met_dijet_mt,lgnd_alpgen_nom_muon_lep_met_dijet_mt_name,"p");

  // char lgnd_alpgen_iqopt3_muon_lep_met_dijet_mt_name[20];
  // sprintf(lgnd_alpgen_iqopt3_muon_lep_met_dijet_mt_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_muon_lep_met_dijet_mt->Integral());
  // lgnd_tc12->AddEntry(h_alpgen_iqopt3_muon_lep_met_dijet_mt,lgnd_alpgen_iqopt3_muon_lep_met_dijet_mt_name,"p");

  // char lgnd_alpgen_ptjmin10_muon_lep_met_dijet_mt_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_muon_lep_met_dijet_mt_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_muon_lep_met_dijet_mt->Integral());
  // lgnd_tc12->AddEntry(h_alpgen_ptjmin10_muon_lep_met_dijet_mt,lgnd_alpgen_ptjmin10_muon_lep_met_dijet_mt_name,"p");

  // char lgnd_sherpa_nom_muon_lep_met_dijet_mt_name[20];
  // sprintf(lgnd_sherpa_nom_muon_lep_met_dijet_mt_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_muon_lep_met_dijet_mt->Integral());
  // lgnd_tc12->AddEntry(h_sherpa_nom_muon_lep_met_dijet_mt,lgnd_sherpa_nom_muon_lep_met_dijet_mt_name,"p");

  // lgnd_tc12->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc12_pad01->cd();
  // tc12_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_muon_lep_met_dijet_mt->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_muon_lep_met_dijet_mt->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_muon_lep_met_dijet_mt->GetXaxis())->GetXmax();

  // // alp-sherp/sherp
  // string tc12_ratio_alpgen_sherpa_lep_met_dijet_mt_name = "tc12_ratio_alpgen_sherpa_lep_met_dijet_mt";
  // TH1F* h_ratio_alpgen_sherpa_lep_met_dijet_mt = new TH1F(tc12_ratio_alpgen_sherpa_lep_met_dijet_mt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_sherpa_lep_met_dijet_mt->SetMarkerStyle(8);
  // h_ratio_alpgen_sherpa_lep_met_dijet_mt->SetMarkerColor(kRed);

  // TAxis* h_ratio_alpgen_sherpa_lep_met_dijet_mt_xaxis = h_ratio_alpgen_sherpa_lep_met_dijet_mt->GetXaxis();
  // TAxis* h_ratio_alpgen_sherpa_lep_met_dijet_mt_yaxis = h_ratio_alpgen_sherpa_lep_met_dijet_mt->GetYaxis();
  
  // h_ratio_alpgen_sherpa_lep_met_dijet_mt_xaxis->SetLabelSize(0.08);
  // h_ratio_alpgen_sherpa_lep_met_dijet_mt_yaxis->SetLabelSize(0.08);

  // h_ratio_alpgen_sherpa_lep_met_dijet_mt_xaxis->SetTitle("MT(muon,MET,dijet)");
  // h_ratio_alpgen_sherpa_lep_met_dijet_mt_xaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_lep_met_dijet_mt_yaxis->SetNdivisions(4,4,4);
  // h_ratio_alpgen_sherpa_lep_met_dijet_mt_yaxis->SetTitle("(alpgen-MC)/MC");
  // h_ratio_alpgen_sherpa_lep_met_dijet_mt_yaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_lep_met_dijet_mt_yaxis->SetTitleOffset(0.36);
  // h_ratio_alpgen_sherpa_lep_met_dijet_mt_yaxis->SetRangeUser(-1,1);

  
  // // alp-iqopt3/iqopt3
  // string tc12_ratio_alpgen_iqopt3_lep_met_dijet_mt_name = "tc12_ratio_alpgen_iqopt3_lep_met_dijet_mt";
  // TH1F* h_ratio_alpgen_iqopt3_lep_met_dijet_mt = new TH1F(tc12_ratio_alpgen_iqopt3_lep_met_dijet_mt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_iqopt3_lep_met_dijet_mt->SetMarkerStyle(8);
  // h_ratio_alpgen_iqopt3_lep_met_dijet_mt->SetMarkerColor(kGreen);

  
  // // alp-ptjmin10/ptjmin10
  // string tc12_ratio_alpgen_ptjmin10_lep_met_dijet_mt_name = "tc12_ratio_alpgen_ptjmin10_lep_met_dijet_mt";
  // TH1F* h_ratio_alpgen_ptjmin10_lep_met_dijet_mt = new TH1F(tc12_ratio_alpgen_ptjmin10_lep_met_dijet_mt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_ptjmin10_lep_met_dijet_mt->SetMarkerStyle(8);
  // h_ratio_alpgen_ptjmin10_lep_met_dijet_mt->SetMarkerColor(kBlue);


  
  // double tc12_alpgen_sherpa_ratio=0.;
  // double tc12_alpgen_iqopt3_ratio=0.;
  // double tc12_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc12_alpgen_nom_bin_n=h_alpgen_nom_muon_lep_met_dijet_mt->GetBinContent(b);
  //   double tc12_alpgen_nom_bin_err=h_alpgen_nom_muon_lep_met_dijet_mt->GetBinError(b);    

  //   double tc12_sherpa_nom_bin_n=h_sherpa_nom_muon_lep_met_dijet_mt->GetBinContent(b);
  //   double tc12_sherpa_nom_bin_err=h_sherpa_nom_muon_lep_met_dijet_mt->GetBinError(b);    

  //   double tc12_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_muon_lep_met_dijet_mt->GetBinContent(b);
  //   double tc12_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_muon_lep_met_dijet_mt->GetBinError(b);

  //   double tc12_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_muon_lep_met_dijet_mt->GetBinContent(b);
  //   double tc12_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_muon_lep_met_dijet_mt->GetBinError(b);



  //   if(tc12_alpgen_nom_bin_n && tc12_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc12_abs_alpgen_sherpa_err = sqrt(pow(tc12_alpgen_nom_bin_err,2.)+pow(tc12_sherpa_nom_bin_err,2.));
  //     double tc12_rel_alpgen_sherpa_err = tc12_abs_alpgen_sherpa_err/(tc12_alpgen_nom_bin_n-tc12_sherpa_nom_bin_n);
  //     double tc12_rel_sherpa_err = tc12_sherpa_nom_bin_err/tc12_sherpa_nom_bin_n;
      
  //     double tc12_rel_ratio_alpgen_sherpa_lep_met_dijet_mt_err = sqrt(pow(tc12_rel_alpgen_sherpa_err,2.)+pow(tc12_rel_sherpa_err,2.));

  //     double tc12_alpgen_sherpa_ratio = (tc12_alpgen_nom_bin_n-tc12_sherpa_nom_bin_n)/tc12_sherpa_nom_bin_n;

  //     double tc12_alpgen_sherpa_ratio_err = fabs(tc12_rel_ratio_alpgen_sherpa_lep_met_dijet_mt_err*tc12_alpgen_sherpa_ratio);

  //     h_ratio_alpgen_sherpa_lep_met_dijet_mt->SetBinContent(b,tc12_alpgen_sherpa_ratio);
  //     h_ratio_alpgen_sherpa_lep_met_dijet_mt->SetBinError(b,tc12_alpgen_sherpa_ratio_err);
  //   }
    

  //   if(tc12_alpgen_nom_bin_n && tc12_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc12_abs_alpgen_iqopt3_err = sqrt(pow(tc12_alpgen_nom_bin_err,2.)+pow(tc12_alpgen_iqopt3_bin_err,2.));
  //     double tc12_rel_alpgen_iqopt3_err = tc12_abs_alpgen_iqopt3_err/(tc12_alpgen_nom_bin_n-tc12_alpgen_iqopt3_bin_n);
  //     double tc12_rel_iqopt3_err = tc12_alpgen_iqopt3_bin_err/tc12_alpgen_iqopt3_bin_n;
      
  //     double tc12_rel_ratio_alpgen_iqopt3_lep_met_dijet_mt_err = sqrt(pow(tc12_rel_alpgen_iqopt3_err,2.)+pow(tc12_rel_iqopt3_err,2.));

  //     double tc12_alpgen_iqopt3_ratio = (tc12_alpgen_nom_bin_n-tc12_alpgen_iqopt3_bin_n)/tc12_alpgen_iqopt3_bin_n;

  //     double tc12_alpgen_iqopt3_ratio_err = fabs(tc12_rel_ratio_alpgen_iqopt3_lep_met_dijet_mt_err*tc12_alpgen_iqopt3_ratio);

  //     h_ratio_alpgen_iqopt3_lep_met_dijet_mt->SetBinContent(b,tc12_alpgen_iqopt3_ratio);
  //     h_ratio_alpgen_iqopt3_lep_met_dijet_mt->SetBinError(b,tc12_alpgen_iqopt3_ratio_err);
  //   }

    

  //   if(tc12_alpgen_nom_bin_n && tc12_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc12_abs_alpgen_ptjmin10_err = sqrt(pow(tc12_alpgen_nom_bin_err,2.)+pow(tc12_alpgen_ptjmin10_bin_err,2.));
  //     double tc12_rel_alpgen_ptjmin10_err = tc12_abs_alpgen_ptjmin10_err/(tc12_alpgen_nom_bin_n-tc12_alpgen_ptjmin10_bin_n);
  //     double tc12_rel_ptjmin10_err = tc12_alpgen_ptjmin10_bin_err/tc12_alpgen_ptjmin10_bin_n;
      
  //     double tc12_rel_ratio_alpgen_ptjmin10_lep_met_dijet_mt_err = sqrt(pow(tc12_rel_alpgen_ptjmin10_err,2.)+pow(tc12_rel_ptjmin10_err,2.));

  //     double tc12_alpgen_ptjmin10_ratio = (tc12_alpgen_nom_bin_n-tc12_alpgen_ptjmin10_bin_n)/tc12_alpgen_ptjmin10_bin_n;

  //     double tc12_alpgen_ptjmin10_ratio_err = fabs(tc12_rel_ratio_alpgen_ptjmin10_lep_met_dijet_mt_err*tc12_alpgen_ptjmin10_ratio);

  //     h_ratio_alpgen_ptjmin10_lep_met_dijet_mt->SetBinContent(b,tc12_alpgen_ptjmin10_ratio);
  //     h_ratio_alpgen_ptjmin10_lep_met_dijet_mt->SetBinError(b,tc12_alpgen_ptjmin10_ratio_err);
  //   }
    
  // }


  // h_ratio_alpgen_sherpa_lep_met_dijet_mt->Draw("PE");
  // h_ratio_alpgen_iqopt3_lep_met_dijet_mt->Draw("PE sames");
  // h_ratio_alpgen_ptjmin10_lep_met_dijet_mt->Draw("PE sames");
  
  // tc12->Update();

  // tc12->SaveAs("./plots/latest/muon_lep_met_dijet_mt.png");
  
  // //NEXT  

  // //////////////////////////////////////////////////
  // // tc12_5
  // // data_muon_lep_met_dijet_mt: sherpa/alpgen+wjrw
  // //////////////////////////////////////////////////
  
  // string tc12_5_title = "Mt(muon,MET,dijet) (muon) w/ Data";
  // string tc12_5_name = "tc12_5";
  // TCanvas* tc12_5 = new TCanvas(tc12_5_name.c_str(),tc12_5_title.c_str(),0,0,1920,1200);
  // tc12_5->cd();

  // TPad* tc12_5_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc12_5_pad01->SetTopMargin(0.05);
  // tc12_5_pad01->SetBottomMargin(0.31);
  // tc12_5_pad01->Draw();

  // TPad* tc12_5_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc12_5_pad02->SetBottomMargin(0.0005);
  // tc12_5_pad02->SetLogy();
  // tc12_5_pad02->Draw();
  // tc12_5_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_muon_lep_met_dijet_mt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_purw_nom_lep_met_dijet_mt");
  // TH1F* h_alpgen_iqopt3_muon_lep_met_dijet_mt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_iqopt3_lep_met_dijet_mt");
  // TH1F* h_alpgen_ptjmin10_muon_lep_met_dijet_mt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_ptjmin10_lep_met_dijet_mt");
  // TH1F* h_sherpa_nom_muon_lep_met_dijet_mt = (TH1F*) wjets_sherpa_file->Get("all/h_muon_purw_nom_lep_met_dijet_mt");
  // TH1F* h_data_muon_lep_met_dijet_mt = (TH1F*) data_file->Get("all/h_muon_purw_nom_lep_met_dijet_mt");

  // TH1F* h_top_muon_lep_met_dijet_mt = (TH1F*) top_mcatnlo_file->Get("all/h_muon_purw_nom_lep_met_dijet_mt");
  // TH1F* h_zjets_muon_lep_met_dijet_mt = (TH1F*) zjets_alpgen_file->Get("all/h_muon_purw_nom_lep_met_dijet_mt");
  // TH1F* h_vv_muon_lep_met_dijet_mt = (TH1F*) vv_herwig_file->Get("all/h_muon_purw_nom_lep_met_dijet_mt");
  // TH1F* h_qcd_muon_lep_met_dijet_mt = (TH1F*) qcd_file->Get("all/h_muon_purw_nom_lep_met_dijet_mt");
  
  // h_data_muon_lep_met_dijet_mt->SetTitle("");
  // h_data_muon_lep_met_dijet_mt->Draw();
  
  // //Add Backgrounds
  // h_alpgen_nom_muon_lep_met_dijet_mt->Add(h_top_muon_lep_met_dijet_mt);
  // h_alpgen_nom_muon_lep_met_dijet_mt->Add(h_zjets_muon_lep_met_dijet_mt);
  // h_alpgen_nom_muon_lep_met_dijet_mt->Add(h_vv_muon_lep_met_dijet_mt);
  // h_alpgen_nom_muon_lep_met_dijet_mt->Add(h_qcd_muon_lep_met_dijet_mt);
  
  // h_alpgen_nom_muon_lep_met_dijet_mt->SetMarkerStyle(20);
  // h_alpgen_nom_muon_lep_met_dijet_mt->SetMarkerSize(1.2);
  // h_alpgen_nom_muon_lep_met_dijet_mt->Draw("PE sames");

  // //Add backgrounds
  // h_alpgen_iqopt3_muon_lep_met_dijet_mt->Add(h_top_muon_lep_met_dijet_mt);
  // h_alpgen_iqopt3_muon_lep_met_dijet_mt->Add(h_zjets_muon_lep_met_dijet_mt);
  // h_alpgen_iqopt3_muon_lep_met_dijet_mt->Add(h_vv_muon_lep_met_dijet_mt);
  // h_alpgen_iqopt3_muon_lep_met_dijet_mt->Add(h_qcd_muon_lep_met_dijet_mt);

  // h_alpgen_iqopt3_muon_lep_met_dijet_mt->SetMarkerStyle(22);
  // h_alpgen_iqopt3_muon_lep_met_dijet_mt->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_muon_lep_met_dijet_mt->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_muon_lep_met_dijet_mt->Draw("PE sames");

  // //Add Backgrounds
  // h_alpgen_ptjmin10_muon_lep_met_dijet_mt->Add(h_top_muon_lep_met_dijet_mt);
  // h_alpgen_ptjmin10_muon_lep_met_dijet_mt->Add(h_zjets_muon_lep_met_dijet_mt);
  // h_alpgen_ptjmin10_muon_lep_met_dijet_mt->Add(h_vv_muon_lep_met_dijet_mt);
  // h_alpgen_ptjmin10_muon_lep_met_dijet_mt->Add(h_qcd_muon_lep_met_dijet_mt);

  // h_alpgen_ptjmin10_muon_lep_met_dijet_mt->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_muon_lep_met_dijet_mt->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_muon_lep_met_dijet_mt->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_muon_lep_met_dijet_mt->Draw("PE sames");

  // //Add Backgrounds
  // h_sherpa_nom_muon_lep_met_dijet_mt->Add(h_top_muon_lep_met_dijet_mt);
  // h_sherpa_nom_muon_lep_met_dijet_mt->Add(h_zjets_muon_lep_met_dijet_mt);
  // h_sherpa_nom_muon_lep_met_dijet_mt->Add(h_vv_muon_lep_met_dijet_mt);
  // h_sherpa_nom_muon_lep_met_dijet_mt->Add(h_qcd_muon_lep_met_dijet_mt);

  // h_sherpa_nom_muon_lep_met_dijet_mt->SetMarkerStyle(20);
  // h_sherpa_nom_muon_lep_met_dijet_mt->SetMarkerSize(1.2);
  // h_sherpa_nom_muon_lep_met_dijet_mt->SetMarkerColor(kRed);
  // h_sherpa_nom_muon_lep_met_dijet_mt->Draw("PE sames");




  // //Legend
  // TLegend* lgnd_tc12_5 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc12_5->SetFillColor(0);
  // lgnd_tc12_5->SetTextSize(0.03);
  // lgnd_tc12_5->SetBorderSize(0);


  // char lgnd_data_muon_lep_met_dijet_mt_name[20];
  // sprintf(lgnd_data_muon_lep_met_dijet_mt_name,"%s,  %.2f","DATA",h_data_muon_lep_met_dijet_mt->Integral());
  // lgnd_tc12_5->AddEntry(h_data_muon_lep_met_dijet_mt,lgnd_data_muon_lep_met_dijet_mt_name,"f");

  // char lgnd_alpgen_nom_muon_lep_met_dijet_mt_name[20];
  // sprintf(lgnd_alpgen_nom_muon_lep_met_dijet_mt_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_muon_lep_met_dijet_mt->Integral());
  // lgnd_tc12_5->AddEntry(h_alpgen_nom_muon_lep_met_dijet_mt,lgnd_alpgen_nom_muon_lep_met_dijet_mt_name,"p");

  // char lgnd_alpgen_iqopt3_muon_lep_met_dijet_mt_name[20];
  // sprintf(lgnd_alpgen_iqopt3_muon_lep_met_dijet_mt_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_muon_lep_met_dijet_mt->Integral());
  // lgnd_tc12_5->AddEntry(h_alpgen_iqopt3_muon_lep_met_dijet_mt,lgnd_alpgen_iqopt3_muon_lep_met_dijet_mt_name,"p");

  // char lgnd_alpgen_ptjmin10_muon_lep_met_dijet_mt_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_muon_lep_met_dijet_mt_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_muon_lep_met_dijet_mt->Integral());
  // lgnd_tc12_5->AddEntry(h_alpgen_ptjmin10_muon_lep_met_dijet_mt,lgnd_alpgen_ptjmin10_muon_lep_met_dijet_mt_name,"p");

  // char lgnd_sherpa_nom_muon_lep_met_dijet_mt_name[20];
  // sprintf(lgnd_sherpa_nom_muon_lep_met_dijet_mt_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_muon_lep_met_dijet_mt->Integral());
  // lgnd_tc12_5->AddEntry(h_sherpa_nom_muon_lep_met_dijet_mt,lgnd_sherpa_nom_muon_lep_met_dijet_mt_name,"p");

  // lgnd_tc12_5->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc12_5_pad01->cd();
  // tc12_5_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_muon_lep_met_dijet_mt->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_muon_lep_met_dijet_mt->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_muon_lep_met_dijet_mt->GetXaxis())->GetXmax();

  // // data-alpgen(nom)/alpgen(nom)
  // string tc12_5_ratio_data_alpgen_lep_met_dijet_mt_name = "tc12_5_ratio_data_alpgen_lep_met_dijet_mt";
  // TH1F* h_ratio_data_alpgen_lep_met_dijet_mt = new TH1F(tc12_5_ratio_data_alpgen_lep_met_dijet_mt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_lep_met_dijet_mt->SetMarkerStyle(8);
  // //h_ratio_data_alpgen_lep_met_dijet_mt->SetMarkerColor(kRed);

  // TAxis* h_ratio_data_alpgen_lep_met_dijet_mt_xaxis = h_ratio_data_alpgen_lep_met_dijet_mt->GetXaxis();
  // TAxis* h_ratio_data_alpgen_lep_met_dijet_mt_yaxis = h_ratio_data_alpgen_lep_met_dijet_mt->GetYaxis();
  
  // h_ratio_data_alpgen_lep_met_dijet_mt_xaxis->SetLabelSize(0.08);
  // h_ratio_data_alpgen_lep_met_dijet_mt_yaxis->SetLabelSize(0.08);

  // h_ratio_data_alpgen_lep_met_dijet_mt_xaxis->SetTitle("MT(muon,MET,dijet)");
  // h_ratio_data_alpgen_lep_met_dijet_mt_xaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_lep_met_dijet_mt_yaxis->SetNdivisions(4,4,4);
  // h_ratio_data_alpgen_lep_met_dijet_mt_yaxis->SetTitle("(data-MC)/MC");
  // h_ratio_data_alpgen_lep_met_dijet_mt_yaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_lep_met_dijet_mt_yaxis->SetTitleOffset(0.36);
  // h_ratio_data_alpgen_lep_met_dijet_mt_yaxis->SetRangeUser(-1,1);

  // // data-sherpa(nom)/sherpa(nom)
  // string tc12_5_ratio_data_sherpa_lep_met_dijet_mt_name = "tc12_5_ratio_data_sherpa_lep_met_dijet_mt";
  // TH1F* h_ratio_data_sherpa_lep_met_dijet_mt = new TH1F(tc12_5_ratio_data_sherpa_lep_met_dijet_mt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_sherpa_lep_met_dijet_mt->SetMarkerStyle(8);
  // h_ratio_data_sherpa_lep_met_dijet_mt->SetMarkerColor(kRed);


  // // data-alpgen(iqopt3)/alpgen(iqopt3)
  // string tc12_5_ratio_data_alpgen_iqopt3_lep_met_dijet_mt_name = "tc12_5_ratio_data_alpgen_iqopt3_lep_met_dijet_mt";
  // TH1F* h_ratio_data_alpgen_iqopt3_lep_met_dijet_mt = new TH1F(tc12_5_ratio_data_alpgen_iqopt3_lep_met_dijet_mt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_iqopt3_lep_met_dijet_mt->SetMarkerStyle(8);
  // h_ratio_data_alpgen_iqopt3_lep_met_dijet_mt->SetMarkerColor(kGreen);

  // // data-alpgen(ptjmin10)/alpgen(ptjmin10)
  // string tc12_5_ratio_data_alpgen_ptjmin10_lep_met_dijet_mt_name = "tc12_5_ratio_data_alpgen_ptjmin10_lep_met_dijet_mt";
  // TH1F* h_ratio_data_alpgen_ptjmin10_lep_met_dijet_mt = new TH1F(tc12_5_ratio_data_alpgen_ptjmin10_lep_met_dijet_mt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_ptjmin10_lep_met_dijet_mt->SetMarkerStyle(8);
  // h_ratio_data_alpgen_ptjmin10_lep_met_dijet_mt->SetMarkerColor(kBlue);

  
  // double tc12_5_data_alpgen_ratio=0.;
  // double tc12_5_data_sherpa_ratio=0.;
  // double tc12_5_data_alpgen_iqopt3_ratio=0.;
  // double tc12_5_data_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc12_5_alpgen_nom_bin_n=h_alpgen_nom_muon_lep_met_dijet_mt->GetBinContent(b);
  //   double tc12_5_alpgen_nom_bin_err=h_alpgen_nom_muon_lep_met_dijet_mt->GetBinError(b);    

  //   double tc12_5_data_bin_n=h_data_muon_lep_met_dijet_mt->GetBinContent(b);
  //   double tc12_5_data_bin_err=h_data_muon_lep_met_dijet_mt->GetBinError(b);    

  //   double tc12_5_sherpa_nom_bin_n=h_sherpa_nom_muon_lep_met_dijet_mt->GetBinContent(b);
  //   double tc12_5_sherpa_nom_bin_err=h_sherpa_nom_muon_lep_met_dijet_mt->GetBinError(b);    

  //   double tc12_5_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_muon_lep_met_dijet_mt->GetBinContent(b);
  //   double tc12_5_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_muon_lep_met_dijet_mt->GetBinError(b);

  //   double tc12_5_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_muon_lep_met_dijet_mt->GetBinContent(b);
  //   double tc12_5_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_muon_lep_met_dijet_mt->GetBinError(b);



  //   if(tc12_5_data_bin_n && tc12_5_alpgen_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc12_5_abs_data_alpgen_err = sqrt(pow(tc12_5_data_bin_err,2.)+pow(tc12_5_alpgen_nom_bin_err,2.));
  //     double tc12_5_rel_data_alpgen_err = tc12_5_abs_data_alpgen_err/(tc12_5_data_bin_n-tc12_5_alpgen_nom_bin_n);
  //     double tc12_5_rel_alpgen_err = tc12_5_alpgen_nom_bin_err/tc12_5_alpgen_nom_bin_n;
      
  //     double tc12_5_rel_ratio_data_alpgen_lep_met_dijet_mt_err = sqrt(pow(tc12_5_rel_data_alpgen_err,2.)+pow(tc12_5_rel_alpgen_err,2.));

  //     double tc12_5_data_alpgen_ratio = (tc12_5_data_bin_n-tc12_5_alpgen_nom_bin_n)/tc12_5_alpgen_nom_bin_n;

  //     double tc12_5_data_alpgen_ratio_err = fabs(tc12_5_rel_ratio_data_alpgen_lep_met_dijet_mt_err*tc12_5_data_alpgen_ratio);

  //     h_ratio_data_alpgen_lep_met_dijet_mt->SetBinContent(b,tc12_5_data_alpgen_ratio);
  //     h_ratio_data_alpgen_lep_met_dijet_mt->SetBinError(b,tc12_5_data_alpgen_ratio_err);
  //   }
    

  //   if(tc12_5_data_bin_n && tc12_5_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc12_5_abs_data_sherpa_err = sqrt(pow(tc12_5_data_bin_err,2.)+pow(tc12_5_sherpa_nom_bin_err,2.));
  //     double tc12_5_rel_data_sherpa_err = tc12_5_abs_data_sherpa_err/(tc12_5_data_bin_n-tc12_5_sherpa_nom_bin_n);
  //     double tc12_5_rel_sherpa_err = tc12_5_sherpa_nom_bin_err/tc12_5_sherpa_nom_bin_n;
      
  //     double tc12_5_rel_ratio_data_sherpa_lep_met_dijet_mt_err = sqrt(pow(tc12_5_rel_data_sherpa_err,2.)+pow(tc12_5_rel_sherpa_err,2.));

  //     double tc12_5_data_sherpa_ratio = (tc12_5_data_bin_n-tc12_5_sherpa_nom_bin_n)/tc12_5_sherpa_nom_bin_n;

  //     double tc12_5_data_sherpa_ratio_err = fabs(tc12_5_rel_ratio_data_sherpa_lep_met_dijet_mt_err*tc12_5_data_sherpa_ratio);

  //     h_ratio_data_sherpa_lep_met_dijet_mt->SetBinContent(b,tc12_5_data_sherpa_ratio);
  //     h_ratio_data_sherpa_lep_met_dijet_mt->SetBinError(b,tc12_5_data_sherpa_ratio_err);
  //   }
    

  //   if(tc12_5_data_bin_n && tc12_5_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc12_5_abs_data_alpgen_iqopt3_err = sqrt(pow(tc12_5_data_bin_err,2.)+pow(tc12_5_alpgen_iqopt3_bin_err,2.));
  //     double tc12_5_rel_data_alpgen_iqopt3_err = tc12_5_abs_data_alpgen_iqopt3_err/(tc12_5_data_bin_n-tc12_5_alpgen_iqopt3_bin_n);
  //     double tc12_5_rel_alpgen_iqopt3_err = tc12_5_alpgen_iqopt3_bin_err/tc12_5_alpgen_iqopt3_bin_n;
      
  //     double tc12_5_rel_ratio_data_alpgen_iqopt3_lep_met_dijet_mt_err = sqrt(pow(tc12_5_rel_data_alpgen_iqopt3_err,2.)+pow(tc12_5_rel_alpgen_iqopt3_err,2.));

  //     double tc12_5_data_alpgen_iqopt3_ratio = (tc12_5_data_bin_n-tc12_5_alpgen_iqopt3_bin_n)/tc12_5_alpgen_iqopt3_bin_n;

  //     double tc12_5_data_alpgen_iqopt3_ratio_err = fabs(tc12_5_rel_ratio_data_alpgen_iqopt3_lep_met_dijet_mt_err*tc12_5_data_alpgen_iqopt3_ratio);

  //     h_ratio_data_alpgen_iqopt3_lep_met_dijet_mt->SetBinContent(b,tc12_5_data_alpgen_iqopt3_ratio);
  //     h_ratio_data_alpgen_iqopt3_lep_met_dijet_mt->SetBinError(b,tc12_5_data_alpgen_iqopt3_ratio_err);
  //   }
    
  //   if(tc12_5_data_bin_n && tc12_5_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc12_5_abs_data_alpgen_ptjmin10_err = sqrt(pow(tc12_5_data_bin_err,2.)+pow(tc12_5_alpgen_ptjmin10_bin_err,2.));
  //     double tc12_5_rel_data_alpgen_ptjmin10_err = tc12_5_abs_data_alpgen_ptjmin10_err/(tc12_5_data_bin_n-tc12_5_alpgen_ptjmin10_bin_n);
  //     double tc12_5_rel_alpgen_ptjmin10_err = tc12_5_alpgen_ptjmin10_bin_err/tc12_5_alpgen_ptjmin10_bin_n;
      
  //     double tc12_5_rel_ratio_data_alpgen_ptjmin10_lep_met_dijet_mt_err = sqrt(pow(tc12_5_rel_data_alpgen_ptjmin10_err,2.)+pow(tc12_5_rel_alpgen_ptjmin10_err,2.));

  //     double tc12_5_data_alpgen_ptjmin10_ratio = (tc12_5_data_bin_n-tc12_5_alpgen_ptjmin10_bin_n)/tc12_5_alpgen_ptjmin10_bin_n;

  //     double tc12_5_data_alpgen_ptjmin10_ratio_err = fabs(tc12_5_rel_ratio_data_alpgen_ptjmin10_lep_met_dijet_mt_err*tc12_5_data_alpgen_ptjmin10_ratio);

  //     h_ratio_data_alpgen_ptjmin10_lep_met_dijet_mt->SetBinContent(b,tc12_5_data_alpgen_ptjmin10_ratio);
  //     h_ratio_data_alpgen_ptjmin10_lep_met_dijet_mt->SetBinError(b,tc12_5_data_alpgen_ptjmin10_ratio_err);
  //   }
  // }


  // h_ratio_data_alpgen_lep_met_dijet_mt->Draw("PE");
  // h_ratio_data_sherpa_lep_met_dijet_mt->Draw("PE sames");
  // h_ratio_data_alpgen_iqopt3_lep_met_dijet_mt->Draw("PE sames");
  // h_ratio_data_alpgen_ptjmin10_lep_met_dijet_mt->Draw("PE sames");
  
  // //  h_ratio_alpgen_iqopt3_lep_met_dijet_mt->Draw("PE sames");
  // //  h_ratio_alpgen_ptjmin10_lep_met_dijet_mt->Draw("PE sames");
  
  // tc12_5->Update();
  // tc12_5->SaveAs("./plots/latest/data_muon_lep_met_dijet_mt.png");


  
  // //NEXT
  
  // ////////////////////////////////////////////////// 
  // // tc13
  // // elec_nu_dijet_m: tc13_sherpa/alpgen+wjrw
  // ////////////////////////////////////////////////// 

  // string tc13_title = "M(elec,nu,dijet) (elec) SIG";
  // string tc13_name = "tc13";
  // TCanvas* tc13 = new TCanvas(tc13_name.c_str(),tc13_title.c_str(),0,0,1920,1200);
  // tc13->cd();

  // TPad* tc13_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc13_pad01->SetTopMargin(0.05);
  // tc13_pad01->SetBottomMargin(0.31);
  // tc13_pad01->Draw();

  // TPad* tc13_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc13_pad02->SetBottomMargin(0.0005);
  // tc13_pad02->SetLogy();
  // tc13_pad02->Draw();
  // tc13_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_elec_lep_nu_dijet_m = (TH1F*) wjets_alpgen_file->Get("sig/h_elec_purw_nom_lep_nu_dijet_m");
  // TH1F* h_alpgen_iqopt3_elec_lep_nu_dijet_m = (TH1F*) wjets_alpgen_file->Get("sig/h_elec_wjrw_iqopt3_lep_nu_dijet_m");
  // TH1F* h_alpgen_ptjmin10_elec_lep_nu_dijet_m = (TH1F*) wjets_alpgen_file->Get("sig/h_elec_wjrw_ptjmin10_lep_nu_dijet_m");
  // TH1F* h_sherpa_nom_elec_lep_nu_dijet_m = (TH1F*) wjets_sherpa_file->Get("sig/h_elec_purw_nom_lep_nu_dijet_m");

  // //h_alpgen_nom_elec_lep_nu_dijet_m->SetLineWidth(2);
  // h_alpgen_nom_elec_lep_nu_dijet_m->SetMarkerStyle(20);
  // h_alpgen_nom_elec_lep_nu_dijet_m->SetMarkerSize(1.2);
  // h_alpgen_nom_elec_lep_nu_dijet_m->SetTitle("");
  // h_alpgen_nom_elec_lep_nu_dijet_m->Draw("PE");

  // //h_alpgen_iqopt3_elec_lep_nu_dijet_m->SetLineColor(kGreen);
  // h_alpgen_iqopt3_elec_lep_nu_dijet_m->SetMarkerStyle(22);
  // h_alpgen_iqopt3_elec_lep_nu_dijet_m->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_elec_lep_nu_dijet_m->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_elec_lep_nu_dijet_m->Draw("PE sames");

  // //  h_alpgen_ptjmin10_elec_lep_nu_dijet_m->SetLineColor(kBlue);
  // h_alpgen_ptjmin10_elec_lep_nu_dijet_m->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_elec_lep_nu_dijet_m->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_elec_lep_nu_dijet_m->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_elec_lep_nu_dijet_m->Draw("PE sames");

  // // h_sherpa_nom_elec_lep_nu_dijet_m->SetLineWidth(1.2);
  // // h_sherpa_nom_elec_lep_nu_dijet_m->SetLineColor(kRed);
  // h_sherpa_nom_elec_lep_nu_dijet_m->SetMarkerStyle(20);
  // h_sherpa_nom_elec_lep_nu_dijet_m->SetMarkerSize(1.2);
  // h_sherpa_nom_elec_lep_nu_dijet_m->SetMarkerColor(kRed);
  // h_sherpa_nom_elec_lep_nu_dijet_m->Draw("PE sames");


  // //Legend
  // TLegend* lgnd_tc13 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc13->SetFillColor(0);
  // lgnd_tc13->SetTextSize(0.03);
  // lgnd_tc13->SetBorderSize(0);

  // char lgnd_alpgen_nom_elec_lep_nu_dijet_m_name[20];
  // sprintf(lgnd_alpgen_nom_elec_lep_nu_dijet_m_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_elec_lep_nu_dijet_m->Integral());
  // lgnd_tc13->AddEntry(h_alpgen_nom_elec_lep_nu_dijet_m,lgnd_alpgen_nom_elec_lep_nu_dijet_m_name,"p");

  // char lgnd_alpgen_iqopt3_elec_lep_nu_dijet_m_name[20];
  // sprintf(lgnd_alpgen_iqopt3_elec_lep_nu_dijet_m_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_elec_lep_nu_dijet_m->Integral());
  // lgnd_tc13->AddEntry(h_alpgen_iqopt3_elec_lep_nu_dijet_m,lgnd_alpgen_iqopt3_elec_lep_nu_dijet_m_name,"p");

  // char lgnd_alpgen_ptjmin10_elec_lep_nu_dijet_m_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_elec_lep_nu_dijet_m_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_elec_lep_nu_dijet_m->Integral());
  // lgnd_tc13->AddEntry(h_alpgen_ptjmin10_elec_lep_nu_dijet_m,lgnd_alpgen_ptjmin10_elec_lep_nu_dijet_m_name,"p");

  // char lgnd_sherpa_nom_elec_lep_nu_dijet_m_name[20];
  // sprintf(lgnd_sherpa_nom_elec_lep_nu_dijet_m_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_elec_lep_nu_dijet_m->Integral());
  // lgnd_tc13->AddEntry(h_sherpa_nom_elec_lep_nu_dijet_m,lgnd_sherpa_nom_elec_lep_nu_dijet_m_name,"p");

  // lgnd_tc13->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc13_pad01->cd();
  // tc13_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_elec_lep_nu_dijet_m->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_elec_lep_nu_dijet_m->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_elec_lep_nu_dijet_m->GetXaxis())->GetXmax();

  // // alp-sherp/sherp
  // string tc13_ratio_alpgen_sherpa_elec_nu_dijet_m_name = "tc13_ratio_alpgen_sherpa_elec_nu_dijet_m";
  // TH1F* h_ratio_alpgen_sherpa_elec_nu_dijet_m = new TH1F(tc13_ratio_alpgen_sherpa_elec_nu_dijet_m_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_sherpa_elec_nu_dijet_m->SetMarkerStyle(8);
  // h_ratio_alpgen_sherpa_elec_nu_dijet_m->SetMarkerColor(kRed);

  // TAxis* h_ratio_alpgen_sherpa_elec_nu_dijet_m_xaxis = h_ratio_alpgen_sherpa_elec_nu_dijet_m->GetXaxis();
  // TAxis* h_ratio_alpgen_sherpa_elec_nu_dijet_m_yaxis = h_ratio_alpgen_sherpa_elec_nu_dijet_m->GetYaxis();
  
  // h_ratio_alpgen_sherpa_elec_nu_dijet_m_xaxis->SetLabelSize(0.08);
  // h_ratio_alpgen_sherpa_elec_nu_dijet_m_yaxis->SetLabelSize(0.08);

  // h_ratio_alpgen_sherpa_elec_nu_dijet_m_xaxis->SetTitle("M(elec,nu,dijet)");
  // h_ratio_alpgen_sherpa_elec_nu_dijet_m_xaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_elec_nu_dijet_m_yaxis->SetNdivisions(4,4,4);
  // h_ratio_alpgen_sherpa_elec_nu_dijet_m_yaxis->SetTitle("(alpgen-MC)/MC");
  // h_ratio_alpgen_sherpa_elec_nu_dijet_m_yaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_elec_nu_dijet_m_yaxis->SetTitleOffset(0.36);
  // h_ratio_alpgen_sherpa_elec_nu_dijet_m_yaxis->SetRangeUser(-1,1);

  
  // // alp-iqopt3/iqopt3
  // string tc13_ratio_alpgen_iqopt3_elec_nu_dijet_m_name = "tc13_ratio_alpgen_iqopt3_elec_nu_dijet_m";
  // TH1F* h_ratio_alpgen_iqopt3_elec_nu_dijet_m = new TH1F(tc13_ratio_alpgen_iqopt3_elec_nu_dijet_m_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_iqopt3_elec_nu_dijet_m->SetMarkerStyle(8);
  // h_ratio_alpgen_iqopt3_elec_nu_dijet_m->SetMarkerColor(kGreen);

  
  // // alp-ptjmin10/ptjmin10
  // string tc13_ratio_alpgen_ptjmin10_elec_nu_dijet_m_name = "tc13_ratio_alpgen_ptjmin10_elec_nu_dijet_m";
  // TH1F* h_ratio_alpgen_ptjmin10_elec_nu_dijet_m = new TH1F(tc13_ratio_alpgen_ptjmin10_elec_nu_dijet_m_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_ptjmin10_elec_nu_dijet_m->SetMarkerStyle(8);
  // h_ratio_alpgen_ptjmin10_elec_nu_dijet_m->SetMarkerColor(kBlue);


  
  // double tc13_alpgen_sherpa_ratio=0.;
  // double tc13_alpgen_iqopt3_ratio=0.;
  // double tc13_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc13_alpgen_nom_bin_n=h_alpgen_nom_elec_lep_nu_dijet_m->GetBinContent(b);
  //   double tc13_alpgen_nom_bin_err=h_alpgen_nom_elec_lep_nu_dijet_m->GetBinError(b);    

  //   double tc13_sherpa_nom_bin_n=h_sherpa_nom_elec_lep_nu_dijet_m->GetBinContent(b);
  //   double tc13_sherpa_nom_bin_err=h_sherpa_nom_elec_lep_nu_dijet_m->GetBinError(b);    

  //   double tc13_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_elec_lep_nu_dijet_m->GetBinContent(b);
  //   double tc13_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_elec_lep_nu_dijet_m->GetBinError(b);

  //   double tc13_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_elec_lep_nu_dijet_m->GetBinContent(b);
  //   double tc13_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_elec_lep_nu_dijet_m->GetBinError(b);



  //   if(tc13_alpgen_nom_bin_n && tc13_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc13_abs_alpgen_sherpa_err = sqrt(pow(tc13_alpgen_nom_bin_err,2.)+pow(tc13_sherpa_nom_bin_err,2.));
  //     double tc13_rel_alpgen_sherpa_err = tc13_abs_alpgen_sherpa_err/(tc13_alpgen_nom_bin_n-tc13_sherpa_nom_bin_n);
  //     double tc13_rel_sherpa_err = tc13_sherpa_nom_bin_err/tc13_sherpa_nom_bin_n;
      
  //     double tc13_rel_ratio_alpgen_sherpa_elec_nu_dijet_m_err = sqrt(pow(tc13_rel_alpgen_sherpa_err,2.)+pow(tc13_rel_sherpa_err,2.));

  //     double tc13_alpgen_sherpa_ratio = (tc13_alpgen_nom_bin_n-tc13_sherpa_nom_bin_n)/tc13_sherpa_nom_bin_n;

  //     double tc13_alpgen_sherpa_ratio_err = fabs(tc13_rel_ratio_alpgen_sherpa_elec_nu_dijet_m_err*tc13_alpgen_sherpa_ratio);

  //     h_ratio_alpgen_sherpa_elec_nu_dijet_m->SetBinContent(b,tc13_alpgen_sherpa_ratio);
  //     h_ratio_alpgen_sherpa_elec_nu_dijet_m->SetBinError(b,tc13_alpgen_sherpa_ratio_err);
  //   }
    

  //   if(tc13_alpgen_nom_bin_n && tc13_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc13_abs_alpgen_iqopt3_err = sqrt(pow(tc13_alpgen_nom_bin_err,2.)+pow(tc13_alpgen_iqopt3_bin_err,2.));
  //     double tc13_rel_alpgen_iqopt3_err = tc13_abs_alpgen_iqopt3_err/(tc13_alpgen_nom_bin_n-tc13_alpgen_iqopt3_bin_n);
  //     double tc13_rel_iqopt3_err = tc13_alpgen_iqopt3_bin_err/tc13_alpgen_iqopt3_bin_n;
      
  //     double tc13_rel_ratio_alpgen_iqopt3_elec_nu_dijet_m_err = sqrt(pow(tc13_rel_alpgen_iqopt3_err,2.)+pow(tc13_rel_iqopt3_err,2.));

  //     double tc13_alpgen_iqopt3_ratio = (tc13_alpgen_nom_bin_n-tc13_alpgen_iqopt3_bin_n)/tc13_alpgen_iqopt3_bin_n;

  //     double tc13_alpgen_iqopt3_ratio_err = fabs(tc13_rel_ratio_alpgen_iqopt3_elec_nu_dijet_m_err*tc13_alpgen_iqopt3_ratio);

  //     h_ratio_alpgen_iqopt3_elec_nu_dijet_m->SetBinContent(b,tc13_alpgen_iqopt3_ratio);
  //     h_ratio_alpgen_iqopt3_elec_nu_dijet_m->SetBinError(b,tc13_alpgen_iqopt3_ratio_err);
  //   }

    

  //   if(tc13_alpgen_nom_bin_n && tc13_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc13_abs_alpgen_ptjmin10_err = sqrt(pow(tc13_alpgen_nom_bin_err,2.)+pow(tc13_alpgen_ptjmin10_bin_err,2.));
  //     double tc13_rel_alpgen_ptjmin10_err = tc13_abs_alpgen_ptjmin10_err/(tc13_alpgen_nom_bin_n-tc13_alpgen_ptjmin10_bin_n);
  //     double tc13_rel_ptjmin10_err = tc13_alpgen_ptjmin10_bin_err/tc13_alpgen_ptjmin10_bin_n;
      
  //     double tc13_rel_ratio_alpgen_ptjmin10_elec_nu_dijet_m_err = sqrt(pow(tc13_rel_alpgen_ptjmin10_err,2.)+pow(tc13_rel_ptjmin10_err,2.));

  //     double tc13_alpgen_ptjmin10_ratio = (tc13_alpgen_nom_bin_n-tc13_alpgen_ptjmin10_bin_n)/tc13_alpgen_ptjmin10_bin_n;

  //     double tc13_alpgen_ptjmin10_ratio_err = fabs(tc13_rel_ratio_alpgen_ptjmin10_elec_nu_dijet_m_err*tc13_alpgen_ptjmin10_ratio);

  //     h_ratio_alpgen_ptjmin10_elec_nu_dijet_m->SetBinContent(b,tc13_alpgen_ptjmin10_ratio);
  //     h_ratio_alpgen_ptjmin10_elec_nu_dijet_m->SetBinError(b,tc13_alpgen_ptjmin10_ratio_err);
  //   }
    
  // }


  // h_ratio_alpgen_sherpa_elec_nu_dijet_m->Draw("PE");
  // h_ratio_alpgen_iqopt3_elec_nu_dijet_m->Draw("PE sames");
  // h_ratio_alpgen_ptjmin10_elec_nu_dijet_m->Draw("PE sames");
  
  // tc13->Update();

  // tc13->SaveAs("./plots/latest/sig_elec_lep_nu_dijet_m.png");
  

  // //NEXT

  // ////////////////////////////////////////////////// 
  // // tc14
  // // muon_lep_nu_dijet_m: tc14_sherpa/alpgen+wjrw
  // ////////////////////////////////////////////////// 

  // string tc14_title = "M(muon,nu,dijet) (muon) SIG";
  // string tc14_name = "tc14";
  // TCanvas* tc14 = new TCanvas(tc14_name.c_str(),tc14_title.c_str(),0,0,1920,1200);
  // tc14->cd();

  // TPad* tc14_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc14_pad01->SetTopMargin(0.05);
  // tc14_pad01->SetBottomMargin(0.31);
  // tc14_pad01->Draw();

  // TPad* tc14_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc14_pad02->SetBottomMargin(0.0005);
  // tc14_pad02->SetLogy();
  // tc14_pad02->Draw();
  // tc14_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_muon_lep_nu_dijet_m = (TH1F*) wjets_alpgen_file->Get("sig/h_muon_purw_nom_lep_nu_dijet_m");
  // TH1F* h_alpgen_iqopt3_muon_lep_nu_dijet_m = (TH1F*) wjets_alpgen_file->Get("sig/h_muon_wjrw_iqopt3_lep_nu_dijet_m");
  // TH1F* h_alpgen_ptjmin10_muon_lep_nu_dijet_m = (TH1F*) wjets_alpgen_file->Get("sig/h_muon_wjrw_ptjmin10_lep_nu_dijet_m");
  // TH1F* h_sherpa_nom_muon_lep_nu_dijet_m = (TH1F*) wjets_sherpa_file->Get("sig/h_muon_purw_nom_lep_nu_dijet_m");

  // //h_alpgen_nom_muon_lep_nu_dijet_m->SetLineWidth(2);
  // h_alpgen_nom_muon_lep_nu_dijet_m->SetMarkerStyle(20);
  // h_alpgen_nom_muon_lep_nu_dijet_m->SetMarkerSize(1.2);
  // h_alpgen_nom_muon_lep_nu_dijet_m->SetTitle("");
  // h_alpgen_nom_muon_lep_nu_dijet_m->Draw("PE");

  // //h_alpgen_iqopt3_muon_lep_nu_dijet_m->SetLineColor(kGreen);
  // h_alpgen_iqopt3_muon_lep_nu_dijet_m->SetMarkerStyle(22);
  // h_alpgen_iqopt3_muon_lep_nu_dijet_m->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_muon_lep_nu_dijet_m->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_muon_lep_nu_dijet_m->Draw("PE sames");

  // //  h_alpgen_ptjmin10_muon_lep_nu_dijet_m->SetLineColor(kBlue);
  // h_alpgen_ptjmin10_muon_lep_nu_dijet_m->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_muon_lep_nu_dijet_m->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_muon_lep_nu_dijet_m->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_muon_lep_nu_dijet_m->Draw("PE sames");

  // // h_sherpa_nom_muon_lep_nu_dijet_m->SetLineWidth(1.2);
  // // h_sherpa_nom_muon_lep_nu_dijet_m->SetLineColor(kRed);
  // h_sherpa_nom_muon_lep_nu_dijet_m->SetMarkerStyle(20);
  // h_sherpa_nom_muon_lep_nu_dijet_m->SetMarkerSize(1.2);
  // h_sherpa_nom_muon_lep_nu_dijet_m->SetMarkerColor(kRed);
  // h_sherpa_nom_muon_lep_nu_dijet_m->Draw("PE sames");


  // //Legend
  // TLegend* lgnd_tc14 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc14->SetFillColor(0);
  // lgnd_tc14->SetTextSize(0.03);
  // lgnd_tc14->SetBorderSize(0);

  // char lgnd_alpgen_nom_muon_lep_nu_dijet_m_name[20];
  // sprintf(lgnd_alpgen_nom_muon_lep_nu_dijet_m_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_muon_lep_nu_dijet_m->Integral());
  // lgnd_tc14->AddEntry(h_alpgen_nom_muon_lep_nu_dijet_m,lgnd_alpgen_nom_muon_lep_nu_dijet_m_name,"p");

  // char lgnd_alpgen_iqopt3_muon_lep_nu_dijet_m_name[20];
  // sprintf(lgnd_alpgen_iqopt3_muon_lep_nu_dijet_m_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_muon_lep_nu_dijet_m->Integral());
  // lgnd_tc14->AddEntry(h_alpgen_iqopt3_muon_lep_nu_dijet_m,lgnd_alpgen_iqopt3_muon_lep_nu_dijet_m_name,"p");

  // char lgnd_alpgen_ptjmin10_muon_lep_nu_dijet_m_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_muon_lep_nu_dijet_m_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_muon_lep_nu_dijet_m->Integral());
  // lgnd_tc14->AddEntry(h_alpgen_ptjmin10_muon_lep_nu_dijet_m,lgnd_alpgen_ptjmin10_muon_lep_nu_dijet_m_name,"p");

  // char lgnd_sherpa_nom_muon_lep_nu_dijet_m_name[20];
  // sprintf(lgnd_sherpa_nom_muon_lep_nu_dijet_m_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_muon_lep_nu_dijet_m->Integral());
  // lgnd_tc14->AddEntry(h_sherpa_nom_muon_lep_nu_dijet_m,lgnd_sherpa_nom_muon_lep_nu_dijet_m_name,"p");

  // lgnd_tc14->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc14_pad01->cd();
  // tc14_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_muon_lep_nu_dijet_m->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_muon_lep_nu_dijet_m->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_muon_lep_nu_dijet_m->GetXaxis())->GetXmax();

  // // alp-sherp/sherp
  // string tc14_ratio_alpgen_sherpa_lep_nu_dijet_m_name = "tc14_ratio_alpgen_sherpa_lep_nu_dijet_m";
  // TH1F* h_ratio_alpgen_sherpa_lep_nu_dijet_m = new TH1F(tc14_ratio_alpgen_sherpa_lep_nu_dijet_m_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_sherpa_lep_nu_dijet_m->SetMarkerStyle(8);
  // h_ratio_alpgen_sherpa_lep_nu_dijet_m->SetMarkerColor(kRed);

  // TAxis* h_ratio_alpgen_sherpa_lep_nu_dijet_m_xaxis = h_ratio_alpgen_sherpa_lep_nu_dijet_m->GetXaxis();
  // TAxis* h_ratio_alpgen_sherpa_lep_nu_dijet_m_yaxis = h_ratio_alpgen_sherpa_lep_nu_dijet_m->GetYaxis();
  
  // h_ratio_alpgen_sherpa_lep_nu_dijet_m_xaxis->SetLabelSize(0.08);
  // h_ratio_alpgen_sherpa_lep_nu_dijet_m_yaxis->SetLabelSize(0.08);

  // h_ratio_alpgen_sherpa_lep_nu_dijet_m_xaxis->SetTitle("M(muon,nu,dijet)");
  // h_ratio_alpgen_sherpa_lep_nu_dijet_m_xaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_lep_nu_dijet_m_yaxis->SetNdivisions(4,4,4);
  // h_ratio_alpgen_sherpa_lep_nu_dijet_m_yaxis->SetTitle("(alpgen-MC)/MC");
  // h_ratio_alpgen_sherpa_lep_nu_dijet_m_yaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_lep_nu_dijet_m_yaxis->SetTitleOffset(0.36);
  // h_ratio_alpgen_sherpa_lep_nu_dijet_m_yaxis->SetRangeUser(-1,1);

  
  // // alp-iqopt3/iqopt3
  // string tc14_ratio_alpgen_iqopt3_lep_nu_dijet_m_name = "tc14_ratio_alpgen_iqopt3_lep_nu_dijet_m";
  // TH1F* h_ratio_alpgen_iqopt3_lep_nu_dijet_m = new TH1F(tc14_ratio_alpgen_iqopt3_lep_nu_dijet_m_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_iqopt3_lep_nu_dijet_m->SetMarkerStyle(8);
  // h_ratio_alpgen_iqopt3_lep_nu_dijet_m->SetMarkerColor(kGreen);

  
  // // alp-ptjmin10/ptjmin10
  // string tc14_ratio_alpgen_ptjmin10_lep_nu_dijet_m_name = "tc14_ratio_alpgen_ptjmin10_lep_nu_dijet_m";
  // TH1F* h_ratio_alpgen_ptjmin10_lep_nu_dijet_m = new TH1F(tc14_ratio_alpgen_ptjmin10_lep_nu_dijet_m_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_ptjmin10_lep_nu_dijet_m->SetMarkerStyle(8);
  // h_ratio_alpgen_ptjmin10_lep_nu_dijet_m->SetMarkerColor(kBlue);


  
  // double tc14_alpgen_sherpa_ratio=0.;
  // double tc14_alpgen_iqopt3_ratio=0.;
  // double tc14_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc14_alpgen_nom_bin_n=h_alpgen_nom_muon_lep_nu_dijet_m->GetBinContent(b);
  //   double tc14_alpgen_nom_bin_err=h_alpgen_nom_muon_lep_nu_dijet_m->GetBinError(b);    

  //   double tc14_sherpa_nom_bin_n=h_sherpa_nom_muon_lep_nu_dijet_m->GetBinContent(b);
  //   double tc14_sherpa_nom_bin_err=h_sherpa_nom_muon_lep_nu_dijet_m->GetBinError(b);    

  //   double tc14_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_muon_lep_nu_dijet_m->GetBinContent(b);
  //   double tc14_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_muon_lep_nu_dijet_m->GetBinError(b);

  //   double tc14_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_muon_lep_nu_dijet_m->GetBinContent(b);
  //   double tc14_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_muon_lep_nu_dijet_m->GetBinError(b);



  //   if(tc14_alpgen_nom_bin_n && tc14_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc14_abs_alpgen_sherpa_err = sqrt(pow(tc14_alpgen_nom_bin_err,2.)+pow(tc14_sherpa_nom_bin_err,2.));
  //     double tc14_rel_alpgen_sherpa_err = tc14_abs_alpgen_sherpa_err/(tc14_alpgen_nom_bin_n-tc14_sherpa_nom_bin_n);
  //     double tc14_rel_sherpa_err = tc14_sherpa_nom_bin_err/tc14_sherpa_nom_bin_n;
      
  //     double tc14_rel_ratio_alpgen_sherpa_lep_nu_dijet_m_err = sqrt(pow(tc14_rel_alpgen_sherpa_err,2.)+pow(tc14_rel_sherpa_err,2.));

  //     double tc14_alpgen_sherpa_ratio = (tc14_alpgen_nom_bin_n-tc14_sherpa_nom_bin_n)/tc14_sherpa_nom_bin_n;

  //     double tc14_alpgen_sherpa_ratio_err = fabs(tc14_rel_ratio_alpgen_sherpa_lep_nu_dijet_m_err*tc14_alpgen_sherpa_ratio);

  //     h_ratio_alpgen_sherpa_lep_nu_dijet_m->SetBinContent(b,tc14_alpgen_sherpa_ratio);
  //     h_ratio_alpgen_sherpa_lep_nu_dijet_m->SetBinError(b,tc14_alpgen_sherpa_ratio_err);
  //   }
    

  //   if(tc14_alpgen_nom_bin_n && tc14_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc14_abs_alpgen_iqopt3_err = sqrt(pow(tc14_alpgen_nom_bin_err,2.)+pow(tc14_alpgen_iqopt3_bin_err,2.));
  //     double tc14_rel_alpgen_iqopt3_err = tc14_abs_alpgen_iqopt3_err/(tc14_alpgen_nom_bin_n-tc14_alpgen_iqopt3_bin_n);
  //     double tc14_rel_iqopt3_err = tc14_alpgen_iqopt3_bin_err/tc14_alpgen_iqopt3_bin_n;
      
  //     double tc14_rel_ratio_alpgen_iqopt3_lep_nu_dijet_m_err = sqrt(pow(tc14_rel_alpgen_iqopt3_err,2.)+pow(tc14_rel_iqopt3_err,2.));

  //     double tc14_alpgen_iqopt3_ratio = (tc14_alpgen_nom_bin_n-tc14_alpgen_iqopt3_bin_n)/tc14_alpgen_iqopt3_bin_n;

  //     double tc14_alpgen_iqopt3_ratio_err = fabs(tc14_rel_ratio_alpgen_iqopt3_lep_nu_dijet_m_err*tc14_alpgen_iqopt3_ratio);

  //     h_ratio_alpgen_iqopt3_lep_nu_dijet_m->SetBinContent(b,tc14_alpgen_iqopt3_ratio);
  //     h_ratio_alpgen_iqopt3_lep_nu_dijet_m->SetBinError(b,tc14_alpgen_iqopt3_ratio_err);
  //   }

    

  //   if(tc14_alpgen_nom_bin_n && tc14_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc14_abs_alpgen_ptjmin10_err = sqrt(pow(tc14_alpgen_nom_bin_err,2.)+pow(tc14_alpgen_ptjmin10_bin_err,2.));
  //     double tc14_rel_alpgen_ptjmin10_err = tc14_abs_alpgen_ptjmin10_err/(tc14_alpgen_nom_bin_n-tc14_alpgen_ptjmin10_bin_n);
  //     double tc14_rel_ptjmin10_err = tc14_alpgen_ptjmin10_bin_err/tc14_alpgen_ptjmin10_bin_n;
      
  //     double tc14_rel_ratio_alpgen_ptjmin10_lep_nu_dijet_m_err = sqrt(pow(tc14_rel_alpgen_ptjmin10_err,2.)+pow(tc14_rel_ptjmin10_err,2.));

  //     double tc14_alpgen_ptjmin10_ratio = (tc14_alpgen_nom_bin_n-tc14_alpgen_ptjmin10_bin_n)/tc14_alpgen_ptjmin10_bin_n;

  //     double tc14_alpgen_ptjmin10_ratio_err = fabs(tc14_rel_ratio_alpgen_ptjmin10_lep_nu_dijet_m_err*tc14_alpgen_ptjmin10_ratio);

  //     h_ratio_alpgen_ptjmin10_lep_nu_dijet_m->SetBinContent(b,tc14_alpgen_ptjmin10_ratio);
  //     h_ratio_alpgen_ptjmin10_lep_nu_dijet_m->SetBinError(b,tc14_alpgen_ptjmin10_ratio_err);
  //   }
    
  // }


  // h_ratio_alpgen_sherpa_lep_nu_dijet_m->Draw("PE");
  // h_ratio_alpgen_iqopt3_lep_nu_dijet_m->Draw("PE sames");
  // h_ratio_alpgen_ptjmin10_lep_nu_dijet_m->Draw("PE sames");
  
  // tc14->Update();

  // tc14->SaveAs("./plots/latest/sig_muon_lep_nu_dijet_m.png");
  
  // //NEXT
  
  // ////////////////////////////////////////////////// 
  // // tc15
  // // elec_met_dijet_mt: tc15_sherpa/alpgen+wjrw
  // ////////////////////////////////////////////////// 

  // string tc15_title = "MT(elec,MET,dijet) (elec) SIG";
  // string tc15_name = "tc15";
  // TCanvas* tc15 = new TCanvas(tc15_name.c_str(),tc15_title.c_str(),0,0,1920,1200);
  // tc15->cd();

  // TPad* tc15_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc15_pad01->SetTopMargin(0.05);
  // tc15_pad01->SetBottomMargin(0.31);
  // tc15_pad01->Draw();

  // TPad* tc15_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc15_pad02->SetBottomMargin(0.0005);
  // tc15_pad02->SetLogy();
  // tc15_pad02->Draw();
  // tc15_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_elec_lep_met_dijet_mt = (TH1F*) wjets_alpgen_file->Get("sig/h_elec_purw_nom_lep_met_dijet_mt");
  // TH1F* h_alpgen_iqopt3_elec_lep_met_dijet_mt = (TH1F*) wjets_alpgen_file->Get("sig/h_elec_wjrw_iqopt3_lep_met_dijet_mt");
  // TH1F* h_alpgen_ptjmin10_elec_lep_met_dijet_mt = (TH1F*) wjets_alpgen_file->Get("sig/h_elec_wjrw_ptjmin10_lep_met_dijet_mt");
  // TH1F* h_sherpa_nom_elec_lep_met_dijet_mt = (TH1F*) wjets_sherpa_file->Get("sig/h_elec_purw_nom_lep_met_dijet_mt");

  // //h_alpgen_nom_elec_lep_met_dijet_mt->SetLineWidth(2);
  // h_alpgen_nom_elec_lep_met_dijet_mt->SetMarkerStyle(20);
  // h_alpgen_nom_elec_lep_met_dijet_mt->SetMarkerSize(1.2);
  // h_alpgen_nom_elec_lep_met_dijet_mt->SetTitle("");
  // h_alpgen_nom_elec_lep_met_dijet_mt->Draw("PE");

  // //h_alpgen_iqopt3_elec_lep_met_dijet_mt->SetLineColor(kGreen);
  // h_alpgen_iqopt3_elec_lep_met_dijet_mt->SetMarkerStyle(22);
  // h_alpgen_iqopt3_elec_lep_met_dijet_mt->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_elec_lep_met_dijet_mt->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_elec_lep_met_dijet_mt->Draw("PE sames");

  // //  h_alpgen_ptjmin10_elec_lep_met_dijet_mt->SetLineColor(kBlue);
  // h_alpgen_ptjmin10_elec_lep_met_dijet_mt->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_elec_lep_met_dijet_mt->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_elec_lep_met_dijet_mt->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_elec_lep_met_dijet_mt->Draw("PE sames");

  // // h_sherpa_nom_elec_lep_met_dijet_mt->SetLineWidth(1.2);
  // // h_sherpa_nom_elec_lep_met_dijet_mt->SetLineColor(kRed);
  // h_sherpa_nom_elec_lep_met_dijet_mt->SetMarkerStyle(20);
  // h_sherpa_nom_elec_lep_met_dijet_mt->SetMarkerSize(1.2);
  // h_sherpa_nom_elec_lep_met_dijet_mt->SetMarkerColor(kRed);
  // h_sherpa_nom_elec_lep_met_dijet_mt->Draw("PE sames");


  // //Legend
  // TLegend* lgnd_tc15 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc15->SetFillColor(0);
  // lgnd_tc15->SetTextSize(0.03);
  // lgnd_tc15->SetBorderSize(0);

  // char lgnd_alpgen_nom_elec_lep_met_dijet_mt_name[20];
  // sprintf(lgnd_alpgen_nom_elec_lep_met_dijet_mt_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_elec_lep_met_dijet_mt->Integral());
  // lgnd_tc15->AddEntry(h_alpgen_nom_elec_lep_met_dijet_mt,lgnd_alpgen_nom_elec_lep_met_dijet_mt_name,"p");

  // char lgnd_alpgen_iqopt3_elec_lep_met_dijet_mt_name[20];
  // sprintf(lgnd_alpgen_iqopt3_elec_lep_met_dijet_mt_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_elec_lep_met_dijet_mt->Integral());
  // lgnd_tc15->AddEntry(h_alpgen_iqopt3_elec_lep_met_dijet_mt,lgnd_alpgen_iqopt3_elec_lep_met_dijet_mt_name,"p");

  // char lgnd_alpgen_ptjmin10_elec_lep_met_dijet_mt_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_elec_lep_met_dijet_mt_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_elec_lep_met_dijet_mt->Integral());
  // lgnd_tc15->AddEntry(h_alpgen_ptjmin10_elec_lep_met_dijet_mt,lgnd_alpgen_ptjmin10_elec_lep_met_dijet_mt_name,"p");

  // char lgnd_sherpa_nom_elec_lep_met_dijet_mt_name[20];
  // sprintf(lgnd_sherpa_nom_elec_lep_met_dijet_mt_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_elec_lep_met_dijet_mt->Integral());
  // lgnd_tc15->AddEntry(h_sherpa_nom_elec_lep_met_dijet_mt,lgnd_sherpa_nom_elec_lep_met_dijet_mt_name,"p");

  // lgnd_tc15->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc15_pad01->cd();
  // tc15_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_elec_lep_met_dijet_mt->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_elec_lep_met_dijet_mt->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_elec_lep_met_dijet_mt->GetXaxis())->GetXmax();

  // // alp-sherp/sherp
  // string tc15_ratio_alpgen_sherpa_elec_met_dijet_mt_name = "tc15_ratio_alpgen_sherpa_elec_met_dijet_mt";
  // TH1F* h_ratio_alpgen_sherpa_elec_met_dijet_mt = new TH1F(tc15_ratio_alpgen_sherpa_elec_met_dijet_mt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_sherpa_elec_met_dijet_mt->SetMarkerStyle(8);
  // h_ratio_alpgen_sherpa_elec_met_dijet_mt->SetMarkerColor(kRed);

  // TAxis* h_ratio_alpgen_sherpa_elec_met_dijet_mt_xaxis = h_ratio_alpgen_sherpa_elec_met_dijet_mt->GetXaxis();
  // TAxis* h_ratio_alpgen_sherpa_elec_met_dijet_mt_yaxis = h_ratio_alpgen_sherpa_elec_met_dijet_mt->GetYaxis();
  
  // h_ratio_alpgen_sherpa_elec_met_dijet_mt_xaxis->SetLabelSize(0.08);
  // h_ratio_alpgen_sherpa_elec_met_dijet_mt_yaxis->SetLabelSize(0.08);

  // h_ratio_alpgen_sherpa_elec_met_dijet_mt_xaxis->SetTitle("MT(elec,MET,dijet)");
  // h_ratio_alpgen_sherpa_elec_met_dijet_mt_xaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_elec_met_dijet_mt_yaxis->SetNdivisions(4,4,4);
  // h_ratio_alpgen_sherpa_elec_met_dijet_mt_yaxis->SetTitle("(alpgen-MC)/MC");
  // h_ratio_alpgen_sherpa_elec_met_dijet_mt_yaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_elec_met_dijet_mt_yaxis->SetTitleOffset(0.36);
  // h_ratio_alpgen_sherpa_elec_met_dijet_mt_yaxis->SetRangeUser(-1,1);

  
  // // alp-iqopt3/iqopt3
  // string tc15_ratio_alpgen_iqopt3_elec_met_dijet_mt_name = "tc15_ratio_alpgen_iqopt3_elec_met_dijet_mt";
  // TH1F* h_ratio_alpgen_iqopt3_elec_met_dijet_mt = new TH1F(tc15_ratio_alpgen_iqopt3_elec_met_dijet_mt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_iqopt3_elec_met_dijet_mt->SetMarkerStyle(8);
  // h_ratio_alpgen_iqopt3_elec_met_dijet_mt->SetMarkerColor(kGreen);

  
  // // alp-ptjmin10/ptjmin10
  // string tc15_ratio_alpgen_ptjmin10_elec_met_dijet_mt_name = "tc15_ratio_alpgen_ptjmin10_elec_met_dijet_mt";
  // TH1F* h_ratio_alpgen_ptjmin10_elec_met_dijet_mt = new TH1F(tc15_ratio_alpgen_ptjmin10_elec_met_dijet_mt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_ptjmin10_elec_met_dijet_mt->SetMarkerStyle(8);
  // h_ratio_alpgen_ptjmin10_elec_met_dijet_mt->SetMarkerColor(kBlue);


  
  // double tc15_alpgen_sherpa_ratio=0.;
  // double tc15_alpgen_iqopt3_ratio=0.;
  // double tc15_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc15_alpgen_nom_bin_n=h_alpgen_nom_elec_lep_met_dijet_mt->GetBinContent(b);
  //   double tc15_alpgen_nom_bin_err=h_alpgen_nom_elec_lep_met_dijet_mt->GetBinError(b);    

  //   double tc15_sherpa_nom_bin_n=h_sherpa_nom_elec_lep_met_dijet_mt->GetBinContent(b);
  //   double tc15_sherpa_nom_bin_err=h_sherpa_nom_elec_lep_met_dijet_mt->GetBinError(b);    

  //   double tc15_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_elec_lep_met_dijet_mt->GetBinContent(b);
  //   double tc15_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_elec_lep_met_dijet_mt->GetBinError(b);

  //   double tc15_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_elec_lep_met_dijet_mt->GetBinContent(b);
  //   double tc15_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_elec_lep_met_dijet_mt->GetBinError(b);



  //   if(tc15_alpgen_nom_bin_n && tc15_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc15_abs_alpgen_sherpa_err = sqrt(pow(tc15_alpgen_nom_bin_err,2.)+pow(tc15_sherpa_nom_bin_err,2.));
  //     double tc15_rel_alpgen_sherpa_err = tc15_abs_alpgen_sherpa_err/(tc15_alpgen_nom_bin_n-tc15_sherpa_nom_bin_n);
  //     double tc15_rel_sherpa_err = tc15_sherpa_nom_bin_err/tc15_sherpa_nom_bin_n;
      
  //     double tc15_rel_ratio_alpgen_sherpa_elec_met_dijet_mt_err = sqrt(pow(tc15_rel_alpgen_sherpa_err,2.)+pow(tc15_rel_sherpa_err,2.));

  //     double tc15_alpgen_sherpa_ratio = (tc15_alpgen_nom_bin_n-tc15_sherpa_nom_bin_n)/tc15_sherpa_nom_bin_n;

  //     double tc15_alpgen_sherpa_ratio_err = fabs(tc15_rel_ratio_alpgen_sherpa_elec_met_dijet_mt_err*tc15_alpgen_sherpa_ratio);

  //     h_ratio_alpgen_sherpa_elec_met_dijet_mt->SetBinContent(b,tc15_alpgen_sherpa_ratio);
  //     h_ratio_alpgen_sherpa_elec_met_dijet_mt->SetBinError(b,tc15_alpgen_sherpa_ratio_err);
  //   }
    

  //   if(tc15_alpgen_nom_bin_n && tc15_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc15_abs_alpgen_iqopt3_err = sqrt(pow(tc15_alpgen_nom_bin_err,2.)+pow(tc15_alpgen_iqopt3_bin_err,2.));
  //     double tc15_rel_alpgen_iqopt3_err = tc15_abs_alpgen_iqopt3_err/(tc15_alpgen_nom_bin_n-tc15_alpgen_iqopt3_bin_n);
  //     double tc15_rel_iqopt3_err = tc15_alpgen_iqopt3_bin_err/tc15_alpgen_iqopt3_bin_n;
      
  //     double tc15_rel_ratio_alpgen_iqopt3_elec_met_dijet_mt_err = sqrt(pow(tc15_rel_alpgen_iqopt3_err,2.)+pow(tc15_rel_iqopt3_err,2.));

  //     double tc15_alpgen_iqopt3_ratio = (tc15_alpgen_nom_bin_n-tc15_alpgen_iqopt3_bin_n)/tc15_alpgen_iqopt3_bin_n;

  //     double tc15_alpgen_iqopt3_ratio_err = fabs(tc15_rel_ratio_alpgen_iqopt3_elec_met_dijet_mt_err*tc15_alpgen_iqopt3_ratio);

  //     h_ratio_alpgen_iqopt3_elec_met_dijet_mt->SetBinContent(b,tc15_alpgen_iqopt3_ratio);
  //     h_ratio_alpgen_iqopt3_elec_met_dijet_mt->SetBinError(b,tc15_alpgen_iqopt3_ratio_err);
  //   }

    

  //   if(tc15_alpgen_nom_bin_n && tc15_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc15_abs_alpgen_ptjmin10_err = sqrt(pow(tc15_alpgen_nom_bin_err,2.)+pow(tc15_alpgen_ptjmin10_bin_err,2.));
  //     double tc15_rel_alpgen_ptjmin10_err = tc15_abs_alpgen_ptjmin10_err/(tc15_alpgen_nom_bin_n-tc15_alpgen_ptjmin10_bin_n);
  //     double tc15_rel_ptjmin10_err = tc15_alpgen_ptjmin10_bin_err/tc15_alpgen_ptjmin10_bin_n;
      
  //     double tc15_rel_ratio_alpgen_ptjmin10_elec_met_dijet_mt_err = sqrt(pow(tc15_rel_alpgen_ptjmin10_err,2.)+pow(tc15_rel_ptjmin10_err,2.));

  //     double tc15_alpgen_ptjmin10_ratio = (tc15_alpgen_nom_bin_n-tc15_alpgen_ptjmin10_bin_n)/tc15_alpgen_ptjmin10_bin_n;

  //     double tc15_alpgen_ptjmin10_ratio_err = fabs(tc15_rel_ratio_alpgen_ptjmin10_elec_met_dijet_mt_err*tc15_alpgen_ptjmin10_ratio);

  //     h_ratio_alpgen_ptjmin10_elec_met_dijet_mt->SetBinContent(b,tc15_alpgen_ptjmin10_ratio);
  //     h_ratio_alpgen_ptjmin10_elec_met_dijet_mt->SetBinError(b,tc15_alpgen_ptjmin10_ratio_err);
  //   }
    
  // }


  // h_ratio_alpgen_sherpa_elec_met_dijet_mt->Draw("PE");
  // h_ratio_alpgen_iqopt3_elec_met_dijet_mt->Draw("PE sames");
  // h_ratio_alpgen_ptjmin10_elec_met_dijet_mt->Draw("PE sames");
  
  // tc15->Update();

  // tc15->SaveAs("./plots/latest/sig_elec_lep_met_dijet_mt.png");
  
  // //NEXT

  // ////////////////////////////////////////////////// 
  // // tc16
  // // muon_lep_met_dijet_mt: tc16_sherpa/alpgen+wjrw
  // ////////////////////////////////////////////////// 

  // string tc16_title = "MT(muon,MET,dijet) (muon) SIG";
  // string tc16_name = "tc16";
  // TCanvas* tc16 = new TCanvas(tc16_name.c_str(),tc16_title.c_str(),0,0,1920,1200);
  // tc16->cd();

  // TPad* tc16_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc16_pad01->SetTopMargin(0.05);
  // tc16_pad01->SetBottomMargin(0.31);
  // tc16_pad01->Draw();

  // TPad* tc16_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc16_pad02->SetBottomMargin(0.0005);
  // tc16_pad02->SetLogy();
  // tc16_pad02->Draw();
  // tc16_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_muon_lep_met_dijet_mt = (TH1F*) wjets_alpgen_file->Get("sig/h_muon_purw_nom_lep_met_dijet_mt");
  // TH1F* h_alpgen_iqopt3_muon_lep_met_dijet_mt = (TH1F*) wjets_alpgen_file->Get("sig/h_muon_wjrw_iqopt3_lep_met_dijet_mt");
  // TH1F* h_alpgen_ptjmin10_muon_lep_met_dijet_mt = (TH1F*) wjets_alpgen_file->Get("sig/h_muon_wjrw_ptjmin10_lep_met_dijet_mt");
  // TH1F* h_sherpa_nom_muon_lep_met_dijet_mt = (TH1F*) wjets_sherpa_file->Get("sig/h_muon_purw_nom_lep_met_dijet_mt");

  // //h_alpgen_nom_muon_lep_met_dijet_mt->SetLineWidth(2);
  // h_alpgen_nom_muon_lep_met_dijet_mt->SetMarkerStyle(20);
  // h_alpgen_nom_muon_lep_met_dijet_mt->SetMarkerSize(1.2);
  // h_alpgen_nom_muon_lep_met_dijet_mt->SetTitle("");
  // h_alpgen_nom_muon_lep_met_dijet_mt->Draw("PE");

  // //h_alpgen_iqopt3_muon_lep_met_dijet_mt->SetLineColor(kGreen);
  // h_alpgen_iqopt3_muon_lep_met_dijet_mt->SetMarkerStyle(22);
  // h_alpgen_iqopt3_muon_lep_met_dijet_mt->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_muon_lep_met_dijet_mt->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_muon_lep_met_dijet_mt->Draw("PE sames");

  // //  h_alpgen_ptjmin10_muon_lep_met_dijet_mt->SetLineColor(kBlue);
  // h_alpgen_ptjmin10_muon_lep_met_dijet_mt->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_muon_lep_met_dijet_mt->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_muon_lep_met_dijet_mt->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_muon_lep_met_dijet_mt->Draw("PE sames");

  // // h_sherpa_nom_muon_lep_met_dijet_mt->SetLineWidth(1.2);
  // // h_sherpa_nom_muon_lep_met_dijet_mt->SetLineColor(kRed);
  // h_sherpa_nom_muon_lep_met_dijet_mt->SetMarkerStyle(20);
  // h_sherpa_nom_muon_lep_met_dijet_mt->SetMarkerSize(1.2);
  // h_sherpa_nom_muon_lep_met_dijet_mt->SetMarkerColor(kRed);
  // h_sherpa_nom_muon_lep_met_dijet_mt->Draw("PE sames");


  // //Legend
  // TLegend* lgnd_tc16 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc16->SetFillColor(0);
  // lgnd_tc16->SetTextSize(0.03);
  // lgnd_tc16->SetBorderSize(0);

  // char lgnd_alpgen_nom_muon_lep_met_dijet_mt_name[20];
  // sprintf(lgnd_alpgen_nom_muon_lep_met_dijet_mt_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_muon_lep_met_dijet_mt->Integral());
  // lgnd_tc16->AddEntry(h_alpgen_nom_muon_lep_met_dijet_mt,lgnd_alpgen_nom_muon_lep_met_dijet_mt_name,"p");

  // char lgnd_alpgen_iqopt3_muon_lep_met_dijet_mt_name[20];
  // sprintf(lgnd_alpgen_iqopt3_muon_lep_met_dijet_mt_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_muon_lep_met_dijet_mt->Integral());
  // lgnd_tc16->AddEntry(h_alpgen_iqopt3_muon_lep_met_dijet_mt,lgnd_alpgen_iqopt3_muon_lep_met_dijet_mt_name,"p");

  // char lgnd_alpgen_ptjmin10_muon_lep_met_dijet_mt_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_muon_lep_met_dijet_mt_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_muon_lep_met_dijet_mt->Integral());
  // lgnd_tc16->AddEntry(h_alpgen_ptjmin10_muon_lep_met_dijet_mt,lgnd_alpgen_ptjmin10_muon_lep_met_dijet_mt_name,"p");

  // char lgnd_sherpa_nom_muon_lep_met_dijet_mt_name[20];
  // sprintf(lgnd_sherpa_nom_muon_lep_met_dijet_mt_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_muon_lep_met_dijet_mt->Integral());
  // lgnd_tc16->AddEntry(h_sherpa_nom_muon_lep_met_dijet_mt,lgnd_sherpa_nom_muon_lep_met_dijet_mt_name,"p");

  // lgnd_tc16->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc16_pad01->cd();
  // tc16_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_muon_lep_met_dijet_mt->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_muon_lep_met_dijet_mt->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_muon_lep_met_dijet_mt->GetXaxis())->GetXmax();

  // // alp-sherp/sherp
  // string tc16_ratio_alpgen_sherpa_lep_met_dijet_mt_name = "tc16_ratio_alpgen_sherpa_lep_met_dijet_mt";
  // TH1F* h_ratio_alpgen_sherpa_lep_met_dijet_mt = new TH1F(tc16_ratio_alpgen_sherpa_lep_met_dijet_mt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_sherpa_lep_met_dijet_mt->SetMarkerStyle(8);
  // h_ratio_alpgen_sherpa_lep_met_dijet_mt->SetMarkerColor(kRed);

  // TAxis* h_ratio_alpgen_sherpa_lep_met_dijet_mt_xaxis = h_ratio_alpgen_sherpa_lep_met_dijet_mt->GetXaxis();
  // TAxis* h_ratio_alpgen_sherpa_lep_met_dijet_mt_yaxis = h_ratio_alpgen_sherpa_lep_met_dijet_mt->GetYaxis();
  
  // h_ratio_alpgen_sherpa_lep_met_dijet_mt_xaxis->SetLabelSize(0.08);
  // h_ratio_alpgen_sherpa_lep_met_dijet_mt_yaxis->SetLabelSize(0.08);

  // h_ratio_alpgen_sherpa_lep_met_dijet_mt_xaxis->SetTitle("MT(muon,MET,dijet)");
  // h_ratio_alpgen_sherpa_lep_met_dijet_mt_xaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_lep_met_dijet_mt_yaxis->SetNdivisions(4,4,4);
  // h_ratio_alpgen_sherpa_lep_met_dijet_mt_yaxis->SetTitle("(alpgen-MC)/MC");
  // h_ratio_alpgen_sherpa_lep_met_dijet_mt_yaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_lep_met_dijet_mt_yaxis->SetTitleOffset(0.36);
  // h_ratio_alpgen_sherpa_lep_met_dijet_mt_yaxis->SetRangeUser(-1,1);

  
  // // alp-iqopt3/iqopt3
  // string tc16_ratio_alpgen_iqopt3_lep_met_dijet_mt_name = "tc16_ratio_alpgen_iqopt3_lep_met_dijet_mt";
  // TH1F* h_ratio_alpgen_iqopt3_lep_met_dijet_mt = new TH1F(tc16_ratio_alpgen_iqopt3_lep_met_dijet_mt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_iqopt3_lep_met_dijet_mt->SetMarkerStyle(8);
  // h_ratio_alpgen_iqopt3_lep_met_dijet_mt->SetMarkerColor(kGreen);

  
  // // alp-ptjmin10/ptjmin10
  // string tc16_ratio_alpgen_ptjmin10_lep_met_dijet_mt_name = "tc16_ratio_alpgen_ptjmin10_lep_met_dijet_mt";
  // TH1F* h_ratio_alpgen_ptjmin10_lep_met_dijet_mt = new TH1F(tc16_ratio_alpgen_ptjmin10_lep_met_dijet_mt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_ptjmin10_lep_met_dijet_mt->SetMarkerStyle(8);
  // h_ratio_alpgen_ptjmin10_lep_met_dijet_mt->SetMarkerColor(kBlue);


  
  // double tc16_alpgen_sherpa_ratio=0.;
  // double tc16_alpgen_iqopt3_ratio=0.;
  // double tc16_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc16_alpgen_nom_bin_n=h_alpgen_nom_muon_lep_met_dijet_mt->GetBinContent(b);
  //   double tc16_alpgen_nom_bin_err=h_alpgen_nom_muon_lep_met_dijet_mt->GetBinError(b);    

  //   double tc16_sherpa_nom_bin_n=h_sherpa_nom_muon_lep_met_dijet_mt->GetBinContent(b);
  //   double tc16_sherpa_nom_bin_err=h_sherpa_nom_muon_lep_met_dijet_mt->GetBinError(b);    

  //   double tc16_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_muon_lep_met_dijet_mt->GetBinContent(b);
  //   double tc16_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_muon_lep_met_dijet_mt->GetBinError(b);

  //   double tc16_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_muon_lep_met_dijet_mt->GetBinContent(b);
  //   double tc16_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_muon_lep_met_dijet_mt->GetBinError(b);



  //   if(tc16_alpgen_nom_bin_n && tc16_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc16_abs_alpgen_sherpa_err = sqrt(pow(tc16_alpgen_nom_bin_err,2.)+pow(tc16_sherpa_nom_bin_err,2.));
  //     double tc16_rel_alpgen_sherpa_err = tc16_abs_alpgen_sherpa_err/(tc16_alpgen_nom_bin_n-tc16_sherpa_nom_bin_n);
  //     double tc16_rel_sherpa_err = tc16_sherpa_nom_bin_err/tc16_sherpa_nom_bin_n;
      
  //     double tc16_rel_ratio_alpgen_sherpa_lep_met_dijet_mt_err = sqrt(pow(tc16_rel_alpgen_sherpa_err,2.)+pow(tc16_rel_sherpa_err,2.));

  //     double tc16_alpgen_sherpa_ratio = (tc16_alpgen_nom_bin_n-tc16_sherpa_nom_bin_n)/tc16_sherpa_nom_bin_n;

  //     double tc16_alpgen_sherpa_ratio_err = fabs(tc16_rel_ratio_alpgen_sherpa_lep_met_dijet_mt_err*tc16_alpgen_sherpa_ratio);

  //     h_ratio_alpgen_sherpa_lep_met_dijet_mt->SetBinContent(b,tc16_alpgen_sherpa_ratio);
  //     h_ratio_alpgen_sherpa_lep_met_dijet_mt->SetBinError(b,tc16_alpgen_sherpa_ratio_err);
  //   }
    

  //   if(tc16_alpgen_nom_bin_n && tc16_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc16_abs_alpgen_iqopt3_err = sqrt(pow(tc16_alpgen_nom_bin_err,2.)+pow(tc16_alpgen_iqopt3_bin_err,2.));
  //     double tc16_rel_alpgen_iqopt3_err = tc16_abs_alpgen_iqopt3_err/(tc16_alpgen_nom_bin_n-tc16_alpgen_iqopt3_bin_n);
  //     double tc16_rel_iqopt3_err = tc16_alpgen_iqopt3_bin_err/tc16_alpgen_iqopt3_bin_n;
      
  //     double tc16_rel_ratio_alpgen_iqopt3_lep_met_dijet_mt_err = sqrt(pow(tc16_rel_alpgen_iqopt3_err,2.)+pow(tc16_rel_iqopt3_err,2.));

  //     double tc16_alpgen_iqopt3_ratio = (tc16_alpgen_nom_bin_n-tc16_alpgen_iqopt3_bin_n)/tc16_alpgen_iqopt3_bin_n;

  //     double tc16_alpgen_iqopt3_ratio_err = fabs(tc16_rel_ratio_alpgen_iqopt3_lep_met_dijet_mt_err*tc16_alpgen_iqopt3_ratio);

  //     h_ratio_alpgen_iqopt3_lep_met_dijet_mt->SetBinContent(b,tc16_alpgen_iqopt3_ratio);
  //     h_ratio_alpgen_iqopt3_lep_met_dijet_mt->SetBinError(b,tc16_alpgen_iqopt3_ratio_err);
  //   }

    

  //   if(tc16_alpgen_nom_bin_n && tc16_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc16_abs_alpgen_ptjmin10_err = sqrt(pow(tc16_alpgen_nom_bin_err,2.)+pow(tc16_alpgen_ptjmin10_bin_err,2.));
  //     double tc16_rel_alpgen_ptjmin10_err = tc16_abs_alpgen_ptjmin10_err/(tc16_alpgen_nom_bin_n-tc16_alpgen_ptjmin10_bin_n);
  //     double tc16_rel_ptjmin10_err = tc16_alpgen_ptjmin10_bin_err/tc16_alpgen_ptjmin10_bin_n;
      
  //     double tc16_rel_ratio_alpgen_ptjmin10_lep_met_dijet_mt_err = sqrt(pow(tc16_rel_alpgen_ptjmin10_err,2.)+pow(tc16_rel_ptjmin10_err,2.));

  //     double tc16_alpgen_ptjmin10_ratio = (tc16_alpgen_nom_bin_n-tc16_alpgen_ptjmin10_bin_n)/tc16_alpgen_ptjmin10_bin_n;

  //     double tc16_alpgen_ptjmin10_ratio_err = fabs(tc16_rel_ratio_alpgen_ptjmin10_lep_met_dijet_mt_err*tc16_alpgen_ptjmin10_ratio);

  //     h_ratio_alpgen_ptjmin10_lep_met_dijet_mt->SetBinContent(b,tc16_alpgen_ptjmin10_ratio);
  //     h_ratio_alpgen_ptjmin10_lep_met_dijet_mt->SetBinError(b,tc16_alpgen_ptjmin10_ratio_err);
  //   }
    
  // }


  // h_ratio_alpgen_sherpa_lep_met_dijet_mt->Draw("PE");
  // h_ratio_alpgen_iqopt3_lep_met_dijet_mt->Draw("PE sames");
  // h_ratio_alpgen_ptjmin10_lep_met_dijet_mt->Draw("PE sames");
  
  // tc16->Update();

  // tc16->SaveAs("./plots/latest/sig_muon_lep_met_dijet_mt.png");



  // //NEXT
  
  // ////////////////////////////////////////////////// 
  // // tc17
  // // elec_lep_pt: tc17_sherpa/alpgen+wjrw
  // ////////////////////////////////////////////////// 

  // string tc17_title = "Pt(elec) (elec)";
  // string tc17_name = "tc17";
  // TCanvas* tc17 = new TCanvas(tc17_name.c_str(),tc17_title.c_str(),0,0,1920,1200);
  // tc17->cd();

  // TPad* tc17_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc17_pad01->SetTopMargin(0.05);
  // tc17_pad01->SetBottomMargin(0.31);
  // tc17_pad01->Draw();

  // TPad* tc17_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc17_pad02->SetBottomMargin(0.0005);
  // tc17_pad02->SetLogy();
  // tc17_pad02->Draw();
  // tc17_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_elec_lep_pt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_purw_nom_lep_pt");
  // TH1F* h_alpgen_iqopt3_elec_lep_pt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_iqopt3_lep_pt");
  // TH1F* h_alpgen_ptjmin10_elec_lep_pt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_ptjmin10_lep_pt");
  // TH1F* h_sherpa_nom_elec_lep_pt = (TH1F*) wjets_sherpa_file->Get("all/h_elec_purw_nom_lep_pt");

  // //h_alpgen_nom_elec_lep_pt->SetLineWidth(2);
  // h_alpgen_nom_elec_lep_pt->SetMarkerStyle(20);
  // h_alpgen_nom_elec_lep_pt->SetMarkerSize(1.2);
  // h_alpgen_nom_elec_lep_pt->SetTitle("");
  // h_alpgen_nom_elec_lep_pt->Draw("PE");

  // //h_alpgen_iqopt3_elec_lep_pt->SetLineColor(kGreen);
  // h_alpgen_iqopt3_elec_lep_pt->SetMarkerStyle(22);
  // h_alpgen_iqopt3_elec_lep_pt->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_elec_lep_pt->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_elec_lep_pt->Draw("PE sames");

  // //  h_alpgen_ptjmin10_elec_lep_pt->SetLineColor(kBlue);
  // h_alpgen_ptjmin10_elec_lep_pt->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_elec_lep_pt->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_elec_lep_pt->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_elec_lep_pt->Draw("PE sames");

  // // h_sherpa_nom_elec_lep_pt->SetLineWidth(1.2);
  // // h_sherpa_nom_elec_lep_pt->SetLineColor(kRed);
  // h_sherpa_nom_elec_lep_pt->SetMarkerStyle(20);
  // h_sherpa_nom_elec_lep_pt->SetMarkerSize(1.2);
  // h_sherpa_nom_elec_lep_pt->SetMarkerColor(kRed);
  // h_sherpa_nom_elec_lep_pt->Draw("PE sames");


  // //Legend
  // TLegend* lgnd_tc17 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc17->SetFillColor(0);
  // lgnd_tc17->SetTextSize(0.03);
  // lgnd_tc17->SetBorderSize(0);

  // char lgnd_alpgen_nom_elec_lep_pt_name[20];
  // sprintf(lgnd_alpgen_nom_elec_lep_pt_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_elec_lep_pt->Integral());
  // lgnd_tc17->AddEntry(h_alpgen_nom_elec_lep_pt,lgnd_alpgen_nom_elec_lep_pt_name,"p");

  // char lgnd_alpgen_iqopt3_elec_lep_pt_name[20];
  // sprintf(lgnd_alpgen_iqopt3_elec_lep_pt_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_elec_lep_pt->Integral());
  // lgnd_tc17->AddEntry(h_alpgen_iqopt3_elec_lep_pt,lgnd_alpgen_iqopt3_elec_lep_pt_name,"p");

  // char lgnd_alpgen_ptjmin10_elec_lep_pt_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_elec_lep_pt_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_elec_lep_pt->Integral());
  // lgnd_tc17->AddEntry(h_alpgen_ptjmin10_elec_lep_pt,lgnd_alpgen_ptjmin10_elec_lep_pt_name,"p");

  // char lgnd_sherpa_nom_elec_lep_pt_name[20];
  // sprintf(lgnd_sherpa_nom_elec_lep_pt_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_elec_lep_pt->Integral());
  // lgnd_tc17->AddEntry(h_sherpa_nom_elec_lep_pt,lgnd_sherpa_nom_elec_lep_pt_name,"p");

  // lgnd_tc17->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc17_pad01->cd();
  // tc17_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_elec_lep_pt->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_elec_lep_pt->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_elec_lep_pt->GetXaxis())->GetXmax();

  // // alp-sherp/sherp
  // string tc17_ratio_alpgen_sherpa_lep_pt_name = "tc17_ratio_alpgen_sherpa_lep_pt";
  // TH1F* h_ratio_alpgen_sherpa_lep_pt = new TH1F(tc17_ratio_alpgen_sherpa_lep_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_sherpa_lep_pt->SetMarkerStyle(8);
  // h_ratio_alpgen_sherpa_lep_pt->SetMarkerColor(kRed);

  // TAxis* h_ratio_alpgen_sherpa_lep_pt_xaxis = h_ratio_alpgen_sherpa_lep_pt->GetXaxis();
  // TAxis* h_ratio_alpgen_sherpa_lep_pt_yaxis = h_ratio_alpgen_sherpa_lep_pt->GetYaxis();
  
  // h_ratio_alpgen_sherpa_lep_pt_xaxis->SetLabelSize(0.08);
  // h_ratio_alpgen_sherpa_lep_pt_yaxis->SetLabelSize(0.08);

  // h_ratio_alpgen_sherpa_lep_pt_xaxis->SetTitle("Pt(elec)");
  // h_ratio_alpgen_sherpa_lep_pt_xaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_lep_pt_yaxis->SetNdivisions(4,4,4);
  // h_ratio_alpgen_sherpa_lep_pt_yaxis->SetTitle("(alpgen-MC)/MC");
  // h_ratio_alpgen_sherpa_lep_pt_yaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_lep_pt_yaxis->SetTitleOffset(0.36);
  // h_ratio_alpgen_sherpa_lep_pt_yaxis->SetRangeUser(-1,1);

  
  // // alp-iqopt3/iqopt3
  // string tc17_ratio_alpgen_iqopt3_lep_pt_name = "tc17_ratio_alpgen_iqopt3_lep_pt";
  // TH1F* h_ratio_alpgen_iqopt3_lep_pt = new TH1F(tc17_ratio_alpgen_iqopt3_lep_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_iqopt3_lep_pt->SetMarkerStyle(8);
  // h_ratio_alpgen_iqopt3_lep_pt->SetMarkerColor(kGreen);

  
  // // alp-ptjmin10/ptjmin10
  // string tc17_ratio_alpgen_ptjmin10_lep_pt_name = "tc17_ratio_alpgen_ptjmin10_lep_pt";
  // TH1F* h_ratio_alpgen_ptjmin10_lep_pt = new TH1F(tc17_ratio_alpgen_ptjmin10_lep_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_ptjmin10_lep_pt->SetMarkerStyle(8);
  // h_ratio_alpgen_ptjmin10_lep_pt->SetMarkerColor(kBlue);


  
  // double tc17_alpgen_sherpa_ratio=0.;
  // double tc17_alpgen_iqopt3_ratio=0.;
  // double tc17_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc17_alpgen_nom_bin_n=h_alpgen_nom_elec_lep_pt->GetBinContent(b);
  //   double tc17_alpgen_nom_bin_err=h_alpgen_nom_elec_lep_pt->GetBinError(b);    

  //   double tc17_sherpa_nom_bin_n=h_sherpa_nom_elec_lep_pt->GetBinContent(b);
  //   double tc17_sherpa_nom_bin_err=h_sherpa_nom_elec_lep_pt->GetBinError(b);    

  //   double tc17_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_elec_lep_pt->GetBinContent(b);
  //   double tc17_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_elec_lep_pt->GetBinError(b);

  //   double tc17_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_elec_lep_pt->GetBinContent(b);
  //   double tc17_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_elec_lep_pt->GetBinError(b);



  //   if(tc17_alpgen_nom_bin_n && tc17_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc17_abs_alpgen_sherpa_err = sqrt(pow(tc17_alpgen_nom_bin_err,2.)+pow(tc17_sherpa_nom_bin_err,2.));
  //     double tc17_rel_alpgen_sherpa_err = tc17_abs_alpgen_sherpa_err/(tc17_alpgen_nom_bin_n-tc17_sherpa_nom_bin_n);
  //     double tc17_rel_sherpa_err = tc17_sherpa_nom_bin_err/tc17_sherpa_nom_bin_n;
      
  //     double tc17_rel_ratio_alpgen_sherpa_lep_pt_err = sqrt(pow(tc17_rel_alpgen_sherpa_err,2.)+pow(tc17_rel_sherpa_err,2.));

  //     double tc17_alpgen_sherpa_ratio = (tc17_alpgen_nom_bin_n-tc17_sherpa_nom_bin_n)/tc17_sherpa_nom_bin_n;

  //     double tc17_alpgen_sherpa_ratio_err = fabs(tc17_rel_ratio_alpgen_sherpa_lep_pt_err*tc17_alpgen_sherpa_ratio);

  //     h_ratio_alpgen_sherpa_lep_pt->SetBinContent(b,tc17_alpgen_sherpa_ratio);
  //     h_ratio_alpgen_sherpa_lep_pt->SetBinError(b,tc17_alpgen_sherpa_ratio_err);
  //   }
    

  //   if(tc17_alpgen_nom_bin_n && tc17_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc17_abs_alpgen_iqopt3_err = sqrt(pow(tc17_alpgen_nom_bin_err,2.)+pow(tc17_alpgen_iqopt3_bin_err,2.));
  //     double tc17_rel_alpgen_iqopt3_err = tc17_abs_alpgen_iqopt3_err/(tc17_alpgen_nom_bin_n-tc17_alpgen_iqopt3_bin_n);
  //     double tc17_rel_iqopt3_err = tc17_alpgen_iqopt3_bin_err/tc17_alpgen_iqopt3_bin_n;
      
  //     double tc17_rel_ratio_alpgen_iqopt3_lep_pt_err = sqrt(pow(tc17_rel_alpgen_iqopt3_err,2.)+pow(tc17_rel_iqopt3_err,2.));

  //     double tc17_alpgen_iqopt3_ratio = (tc17_alpgen_nom_bin_n-tc17_alpgen_iqopt3_bin_n)/tc17_alpgen_iqopt3_bin_n;

  //     double tc17_alpgen_iqopt3_ratio_err = fabs(tc17_rel_ratio_alpgen_iqopt3_lep_pt_err*tc17_alpgen_iqopt3_ratio);

  //     h_ratio_alpgen_iqopt3_lep_pt->SetBinContent(b,tc17_alpgen_iqopt3_ratio);
  //     h_ratio_alpgen_iqopt3_lep_pt->SetBinError(b,tc17_alpgen_iqopt3_ratio_err);
  //   }

    

  //   if(tc17_alpgen_nom_bin_n && tc17_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc17_abs_alpgen_ptjmin10_err = sqrt(pow(tc17_alpgen_nom_bin_err,2.)+pow(tc17_alpgen_ptjmin10_bin_err,2.));
  //     double tc17_rel_alpgen_ptjmin10_err = tc17_abs_alpgen_ptjmin10_err/(tc17_alpgen_nom_bin_n-tc17_alpgen_ptjmin10_bin_n);
  //     double tc17_rel_ptjmin10_err = tc17_alpgen_ptjmin10_bin_err/tc17_alpgen_ptjmin10_bin_n;
      
  //     double tc17_rel_ratio_alpgen_ptjmin10_lep_pt_err = sqrt(pow(tc17_rel_alpgen_ptjmin10_err,2.)+pow(tc17_rel_ptjmin10_err,2.));

  //     double tc17_alpgen_ptjmin10_ratio = (tc17_alpgen_nom_bin_n-tc17_alpgen_ptjmin10_bin_n)/tc17_alpgen_ptjmin10_bin_n;

  //     double tc17_alpgen_ptjmin10_ratio_err = fabs(tc17_rel_ratio_alpgen_ptjmin10_lep_pt_err*tc17_alpgen_ptjmin10_ratio);

  //     h_ratio_alpgen_ptjmin10_lep_pt->SetBinContent(b,tc17_alpgen_ptjmin10_ratio);
  //     h_ratio_alpgen_ptjmin10_lep_pt->SetBinError(b,tc17_alpgen_ptjmin10_ratio_err);
  //   }
    
  // }


  // h_ratio_alpgen_sherpa_lep_pt->Draw("PE");
  // h_ratio_alpgen_iqopt3_lep_pt->Draw("PE sames");
  // h_ratio_alpgen_ptjmin10_lep_pt->Draw("PE sames");
  
  // tc17->Update();

  // tc17->SaveAs("./plots/latest/elec_lep_pt.png");
  

  // //NEXT
  
  // //////////////////////////////////////////////////
  // // tc17_5
  // // data_elec_lep_pt: sherpa/alpgen+wjrw
  // //////////////////////////////////////////////////
  
  // string tc17_5_title = "Pt(elec) (elec) w/ Data";
  // string tc17_5_name = "tc17_5";
  // TCanvas* tc17_5 = new TCanvas(tc17_5_name.c_str(),tc17_5_title.c_str(),0,0,1920,1200);
  // tc17_5->cd();

  // TPad* tc17_5_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc17_5_pad01->SetTopMargin(0.05);
  // tc17_5_pad01->SetBottomMargin(0.31);
  // tc17_5_pad01->Draw();

  // TPad* tc17_5_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc17_5_pad02->SetBottomMargin(0.0005);
  // tc17_5_pad02->SetLogy();
  // tc17_5_pad02->Draw();
  // tc17_5_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_elec_lep_pt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_purw_nom_lep_pt");
  // TH1F* h_alpgen_iqopt3_elec_lep_pt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_iqopt3_lep_pt");
  // TH1F* h_alpgen_ptjmin10_elec_lep_pt = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_ptjmin10_lep_pt");
  // TH1F* h_sherpa_nom_elec_lep_pt = (TH1F*) wjets_sherpa_file->Get("all/h_elec_purw_nom_lep_pt");
  // TH1F* h_data_elec_lep_pt = (TH1F*) data_file->Get("all/h_elec_purw_nom_lep_pt");

  // TH1F* h_top_elec_lep_pt = (TH1F*) top_mcatnlo_file->Get("all/h_elec_purw_nom_lep_pt");
  // TH1F* h_zjets_elec_lep_pt = (TH1F*) zjets_alpgen_file->Get("all/h_elec_purw_nom_lep_pt");
  // TH1F* h_vv_elec_lep_pt = (TH1F*) vv_herwig_file->Get("all/h_elec_purw_nom_lep_pt");
  // TH1F* h_qcd_elec_lep_pt = (TH1F*) qcd_file->Get("all/h_elec_purw_nom_lep_pt");
  
  // h_data_elec_lep_pt->SetTitle("");
  // h_data_elec_lep_pt->Draw();
  
  // //Add Backgrounds
  // h_alpgen_nom_elec_lep_pt->Add(h_top_elec_lep_pt);
  // h_alpgen_nom_elec_lep_pt->Add(h_zjets_elec_lep_pt);
  // h_alpgen_nom_elec_lep_pt->Add(h_vv_elec_lep_pt);
  // h_alpgen_nom_elec_lep_pt->Add(h_qcd_elec_lep_pt);
  
  // h_alpgen_nom_elec_lep_pt->SetMarkerStyle(20);
  // h_alpgen_nom_elec_lep_pt->SetMarkerSize(1.2);
  // h_alpgen_nom_elec_lep_pt->Draw("PE sames");

  // //Add backgrounds
  // h_alpgen_iqopt3_elec_lep_pt->Add(h_top_elec_lep_pt);
  // h_alpgen_iqopt3_elec_lep_pt->Add(h_zjets_elec_lep_pt);
  // h_alpgen_iqopt3_elec_lep_pt->Add(h_vv_elec_lep_pt);
  // h_alpgen_iqopt3_elec_lep_pt->Add(h_qcd_elec_lep_pt);

  // h_alpgen_iqopt3_elec_lep_pt->SetMarkerStyle(22);
  // h_alpgen_iqopt3_elec_lep_pt->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_elec_lep_pt->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_elec_lep_pt->Draw("PE sames");

  // //Add Backgrounds
  // h_alpgen_ptjmin10_elec_lep_pt->Add(h_top_elec_lep_pt);
  // h_alpgen_ptjmin10_elec_lep_pt->Add(h_zjets_elec_lep_pt);
  // h_alpgen_ptjmin10_elec_lep_pt->Add(h_vv_elec_lep_pt);
  // h_alpgen_ptjmin10_elec_lep_pt->Add(h_qcd_elec_lep_pt);

  // h_alpgen_ptjmin10_elec_lep_pt->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_elec_lep_pt->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_elec_lep_pt->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_elec_lep_pt->Draw("PE sames");

  // //Add Backgrounds
  // h_sherpa_nom_elec_lep_pt->Add(h_top_elec_lep_pt);
  // h_sherpa_nom_elec_lep_pt->Add(h_zjets_elec_lep_pt);
  // h_sherpa_nom_elec_lep_pt->Add(h_vv_elec_lep_pt);
  // h_sherpa_nom_elec_lep_pt->Add(h_qcd_elec_lep_pt);

  // h_sherpa_nom_elec_lep_pt->SetMarkerStyle(20);
  // h_sherpa_nom_elec_lep_pt->SetMarkerSize(1.2);
  // h_sherpa_nom_elec_lep_pt->SetMarkerColor(kRed);
  // h_sherpa_nom_elec_lep_pt->Draw("PE sames");




  // //Legend
  // TLegend* lgnd_tc17_5 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc17_5->SetFillColor(0);
  // lgnd_tc17_5->SetTextSize(0.03);
  // lgnd_tc17_5->SetBorderSize(0);


  // char lgnd_data_elec_lep_pt_name[20];
  // sprintf(lgnd_data_elec_lep_pt_name,"%s,  %.2f","DATA",h_data_elec_lep_pt->Integral());
  // lgnd_tc17_5->AddEntry(h_data_elec_lep_pt,lgnd_data_elec_lep_pt_name,"f");

  // char lgnd_alpgen_nom_elec_lep_pt_name[20];
  // sprintf(lgnd_alpgen_nom_elec_lep_pt_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_elec_lep_pt->Integral());
  // lgnd_tc17_5->AddEntry(h_alpgen_nom_elec_lep_pt,lgnd_alpgen_nom_elec_lep_pt_name,"p");

  // char lgnd_alpgen_iqopt3_elec_lep_pt_name[20];
  // sprintf(lgnd_alpgen_iqopt3_elec_lep_pt_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_elec_lep_pt->Integral());
  // lgnd_tc17_5->AddEntry(h_alpgen_iqopt3_elec_lep_pt,lgnd_alpgen_iqopt3_elec_lep_pt_name,"p");

  // char lgnd_alpgen_ptjmin10_elec_lep_pt_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_elec_lep_pt_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_elec_lep_pt->Integral());
  // lgnd_tc17_5->AddEntry(h_alpgen_ptjmin10_elec_lep_pt,lgnd_alpgen_ptjmin10_elec_lep_pt_name,"p");

  // char lgnd_sherpa_nom_elec_lep_pt_name[20];
  // sprintf(lgnd_sherpa_nom_elec_lep_pt_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_elec_lep_pt->Integral());
  // lgnd_tc17_5->AddEntry(h_sherpa_nom_elec_lep_pt,lgnd_sherpa_nom_elec_lep_pt_name,"p");

  // lgnd_tc17_5->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc17_5_pad01->cd();
  // tc17_5_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_elec_lep_pt->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_elec_lep_pt->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_elec_lep_pt->GetXaxis())->GetXmax();

  // // data-alpgen(nom)/alpgen(nom)
  // string tc17_5_ratio_data_alpgen_lep_pt_name = "tc17_5_ratio_data_alpgen_lep_pt";
  // TH1F* h_ratio_data_alpgen_lep_pt = new TH1F(tc17_5_ratio_data_alpgen_lep_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_lep_pt->SetMarkerStyle(8);
  // //h_ratio_data_alpgen_lep_pt->SetMarkerColor(kRed);

  // TAxis* h_ratio_data_alpgen_lep_pt_xaxis = h_ratio_data_alpgen_lep_pt->GetXaxis();
  // TAxis* h_ratio_data_alpgen_lep_pt_yaxis = h_ratio_data_alpgen_lep_pt->GetYaxis();
  
  // h_ratio_data_alpgen_lep_pt_xaxis->SetLabelSize(0.08);
  // h_ratio_data_alpgen_lep_pt_yaxis->SetLabelSize(0.08);

  // h_ratio_data_alpgen_lep_pt_xaxis->SetTitle("Pt(elec)");
  // h_ratio_data_alpgen_lep_pt_xaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_lep_pt_yaxis->SetNdivisions(4,4,4);
  // h_ratio_data_alpgen_lep_pt_yaxis->SetTitle("(data-MC)/MC");
  // h_ratio_data_alpgen_lep_pt_yaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_lep_pt_yaxis->SetTitleOffset(0.36);
  // h_ratio_data_alpgen_lep_pt_yaxis->SetRangeUser(-1,1);

  // // data-sherpa(nom)/sherpa(nom)
  // string tc17_5_ratio_data_sherpa_lep_pt_name = "tc17_5_ratio_data_sherpa_lep_pt";
  // TH1F* h_ratio_data_sherpa_lep_pt = new TH1F(tc17_5_ratio_data_sherpa_lep_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_sherpa_lep_pt->SetMarkerStyle(8);
  // h_ratio_data_sherpa_lep_pt->SetMarkerColor(kRed);


  // // data-alpgen(iqopt3)/alpgen(iqopt3)
  // string tc17_5_ratio_data_alpgen_iqopt3_lep_pt_name = "tc17_5_ratio_data_alpgen_iqopt3_lep_pt";
  // TH1F* h_ratio_data_alpgen_iqopt3_lep_pt = new TH1F(tc17_5_ratio_data_alpgen_iqopt3_lep_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_iqopt3_lep_pt->SetMarkerStyle(8);
  // h_ratio_data_alpgen_iqopt3_lep_pt->SetMarkerColor(kGreen);

  // // data-alpgen(ptjmin10)/alpgen(ptjmin10)
  // string tc17_5_ratio_data_alpgen_ptjmin10_lep_pt_name = "tc17_5_ratio_data_alpgen_ptjmin10_lep_pt";
  // TH1F* h_ratio_data_alpgen_ptjmin10_lep_pt = new TH1F(tc17_5_ratio_data_alpgen_ptjmin10_lep_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_ptjmin10_lep_pt->SetMarkerStyle(8);
  // h_ratio_data_alpgen_ptjmin10_lep_pt->SetMarkerColor(kBlue);

  

  
  // // // alp-iqopt3/iqopt3
  // // string tc17_5_ratio_alpgen_iqopt3_lead_jet_pt_name = "tc17_5_ratio_alpgen_iqopt3_lead_jet_pt";
  // // TH1F* h_ratio_alpgen_iqopt3_lead_jet_pt = new TH1F(tc17_5_ratio_alpgen_iqopt3_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerStyle(8);
  // // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerColor(kGreen);

  
  // // // alp-ptjmin10/ptjmin10
  // // string tc17_5_ratio_alpgen_ptjmin10_lead_jet_pt_name = "tc17_5_ratio_alpgen_ptjmin10_lead_jet_pt";
  // // TH1F* h_ratio_alpgen_ptjmin10_lead_jet_pt = new TH1F(tc17_5_ratio_alpgen_ptjmin10_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerStyle(8);
  // // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerColor(kBlue);


  
  // double tc17_5_data_alpgen_ratio=0.;
  // double tc17_5_data_sherpa_ratio=0.;
  // double tc17_5_data_alpgen_iqopt3_ratio=0.;
  // double tc17_5_data_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc17_5_alpgen_nom_bin_n=h_alpgen_nom_elec_lep_pt->GetBinContent(b);
  //   double tc17_5_alpgen_nom_bin_err=h_alpgen_nom_elec_lep_pt->GetBinError(b);    

  //   double tc17_5_data_bin_n=h_data_elec_lep_pt->GetBinContent(b);
  //   double tc17_5_data_bin_err=h_data_elec_lep_pt->GetBinError(b);    

  //   double tc17_5_sherpa_nom_bin_n=h_sherpa_nom_elec_lep_pt->GetBinContent(b);
  //   double tc17_5_sherpa_nom_bin_err=h_sherpa_nom_elec_lep_pt->GetBinError(b);    

  //   double tc17_5_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_elec_lep_pt->GetBinContent(b);
  //   double tc17_5_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_elec_lep_pt->GetBinError(b);

  //   double tc17_5_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_elec_lep_pt->GetBinContent(b);
  //   double tc17_5_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_elec_lep_pt->GetBinError(b);



  //   if(tc17_5_data_bin_n && tc17_5_alpgen_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc17_5_abs_data_alpgen_err = sqrt(pow(tc17_5_data_bin_err,2.)+pow(tc17_5_alpgen_nom_bin_err,2.));
  //     double tc17_5_rel_data_alpgen_err = tc17_5_abs_data_alpgen_err/(tc17_5_data_bin_n-tc17_5_alpgen_nom_bin_n);
  //     double tc17_5_rel_alpgen_err = tc17_5_alpgen_nom_bin_err/tc17_5_alpgen_nom_bin_n;
      
  //     double tc17_5_rel_ratio_data_alpgen_lep_pt_err = sqrt(pow(tc17_5_rel_data_alpgen_err,2.)+pow(tc17_5_rel_alpgen_err,2.));

  //     double tc17_5_data_alpgen_ratio = (tc17_5_data_bin_n-tc17_5_alpgen_nom_bin_n)/tc17_5_alpgen_nom_bin_n;

  //     double tc17_5_data_alpgen_ratio_err = fabs(tc17_5_rel_ratio_data_alpgen_lep_pt_err*tc17_5_data_alpgen_ratio);

  //     h_ratio_data_alpgen_lep_pt->SetBinContent(b,tc17_5_data_alpgen_ratio);
  //     h_ratio_data_alpgen_lep_pt->SetBinError(b,tc17_5_data_alpgen_ratio_err);
  //   }
    

  //   if(tc17_5_data_bin_n && tc17_5_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc17_5_abs_data_sherpa_err = sqrt(pow(tc17_5_data_bin_err,2.)+pow(tc17_5_sherpa_nom_bin_err,2.));
  //     double tc17_5_rel_data_sherpa_err = tc17_5_abs_data_sherpa_err/(tc17_5_data_bin_n-tc17_5_sherpa_nom_bin_n);
  //     double tc17_5_rel_sherpa_err = tc17_5_sherpa_nom_bin_err/tc17_5_sherpa_nom_bin_n;
      
  //     double tc17_5_rel_ratio_data_sherpa_lep_pt_err = sqrt(pow(tc17_5_rel_data_sherpa_err,2.)+pow(tc17_5_rel_sherpa_err,2.));

  //     double tc17_5_data_sherpa_ratio = (tc17_5_data_bin_n-tc17_5_sherpa_nom_bin_n)/tc17_5_sherpa_nom_bin_n;

  //     double tc17_5_data_sherpa_ratio_err = fabs(tc17_5_rel_ratio_data_sherpa_lep_pt_err*tc17_5_data_sherpa_ratio);

  //     h_ratio_data_sherpa_lep_pt->SetBinContent(b,tc17_5_data_sherpa_ratio);
  //     h_ratio_data_sherpa_lep_pt->SetBinError(b,tc17_5_data_sherpa_ratio_err);
  //   }
    

  //   if(tc17_5_data_bin_n && tc17_5_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc17_5_abs_data_alpgen_iqopt3_err = sqrt(pow(tc17_5_data_bin_err,2.)+pow(tc17_5_alpgen_iqopt3_bin_err,2.));
  //     double tc17_5_rel_data_alpgen_iqopt3_err = tc17_5_abs_data_alpgen_iqopt3_err/(tc17_5_data_bin_n-tc17_5_alpgen_iqopt3_bin_n);
  //     double tc17_5_rel_alpgen_iqopt3_err = tc17_5_alpgen_iqopt3_bin_err/tc17_5_alpgen_iqopt3_bin_n;
      
  //     double tc17_5_rel_ratio_data_alpgen_iqopt3_lep_pt_err = sqrt(pow(tc17_5_rel_data_alpgen_iqopt3_err,2.)+pow(tc17_5_rel_alpgen_iqopt3_err,2.));

  //     double tc17_5_data_alpgen_iqopt3_ratio = (tc17_5_data_bin_n-tc17_5_alpgen_iqopt3_bin_n)/tc17_5_alpgen_iqopt3_bin_n;

  //     double tc17_5_data_alpgen_iqopt3_ratio_err = fabs(tc17_5_rel_ratio_data_alpgen_iqopt3_lep_pt_err*tc17_5_data_alpgen_iqopt3_ratio);

  //     h_ratio_data_alpgen_iqopt3_lep_pt->SetBinContent(b,tc17_5_data_alpgen_iqopt3_ratio);
  //     h_ratio_data_alpgen_iqopt3_lep_pt->SetBinError(b,tc17_5_data_alpgen_iqopt3_ratio_err);
  //   }
    
  //   if(tc17_5_data_bin_n && tc17_5_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc17_5_abs_data_alpgen_ptjmin10_err = sqrt(pow(tc17_5_data_bin_err,2.)+pow(tc17_5_alpgen_ptjmin10_bin_err,2.));
  //     double tc17_5_rel_data_alpgen_ptjmin10_err = tc17_5_abs_data_alpgen_ptjmin10_err/(tc17_5_data_bin_n-tc17_5_alpgen_ptjmin10_bin_n);
  //     double tc17_5_rel_alpgen_ptjmin10_err = tc17_5_alpgen_ptjmin10_bin_err/tc17_5_alpgen_ptjmin10_bin_n;
      
  //     double tc17_5_rel_ratio_data_alpgen_ptjmin10_lep_pt_err = sqrt(pow(tc17_5_rel_data_alpgen_ptjmin10_err,2.)+pow(tc17_5_rel_alpgen_ptjmin10_err,2.));

  //     double tc17_5_data_alpgen_ptjmin10_ratio = (tc17_5_data_bin_n-tc17_5_alpgen_ptjmin10_bin_n)/tc17_5_alpgen_ptjmin10_bin_n;

  //     double tc17_5_data_alpgen_ptjmin10_ratio_err = fabs(tc17_5_rel_ratio_data_alpgen_ptjmin10_lep_pt_err*tc17_5_data_alpgen_ptjmin10_ratio);

  //     h_ratio_data_alpgen_ptjmin10_lep_pt->SetBinContent(b,tc17_5_data_alpgen_ptjmin10_ratio);
  //     h_ratio_data_alpgen_ptjmin10_lep_pt->SetBinError(b,tc17_5_data_alpgen_ptjmin10_ratio_err);
  //   }
  // }


  // h_ratio_data_alpgen_lep_pt->Draw("PE");
  // h_ratio_data_sherpa_lep_pt->Draw("PE sames");
  // h_ratio_data_alpgen_iqopt3_lep_pt->Draw("PE sames");
  // h_ratio_data_alpgen_ptjmin10_lep_pt->Draw("PE sames");
  
  // //  h_ratio_alpgen_iqopt3_lep_pt->Draw("PE sames");
  // //  h_ratio_alpgen_ptjmin10_lep_pt->Draw("PE sames");
  
  // tc17_5->Update();
  // tc17_5->SaveAs("./plots/latest/data_elec_lep_pt.png");
    
  // //NEXT

  // ////////////////////////////////////////////////// 
  // // tc18
  // // muon_lep_pt: tc18_sherpa/alpgen+wjrw
  // ////////////////////////////////////////////////// 

  // string tc18_title = "Pt(muon) (muon)";
  // string tc18_name = "tc18";
  // TCanvas* tc18 = new TCanvas(tc18_name.c_str(),tc18_title.c_str(),0,0,1920,1200);
  // tc18->cd();

  // TPad* tc18_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc18_pad01->SetTopMargin(0.05);
  // tc18_pad01->SetBottomMargin(0.31);
  // tc18_pad01->Draw();

  // TPad* tc18_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc18_pad02->SetBottomMargin(0.0005);
  // tc18_pad02->SetLogy();
  // tc18_pad02->Draw();
  // tc18_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_muon_lep_pt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_purw_nom_lep_pt");
  // TH1F* h_alpgen_iqopt3_muon_lep_pt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_iqopt3_lep_pt");
  // TH1F* h_alpgen_ptjmin10_muon_lep_pt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_ptjmin10_lep_pt");
  // TH1F* h_sherpa_nom_muon_lep_pt = (TH1F*) wjets_sherpa_file->Get("all/h_muon_purw_nom_lep_pt");

  // //h_alpgen_nom_muon_lep_pt->SetLineWidth(2);
  // h_alpgen_nom_muon_lep_pt->SetMarkerStyle(20);
  // h_alpgen_nom_muon_lep_pt->SetMarkerSize(1.2);
  // h_alpgen_nom_muon_lep_pt->SetTitle("");
  // h_alpgen_nom_muon_lep_pt->Draw("PE");

  // //h_alpgen_iqopt3_muon_lep_pt->SetLineColor(kGreen);
  // h_alpgen_iqopt3_muon_lep_pt->SetMarkerStyle(22);
  // h_alpgen_iqopt3_muon_lep_pt->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_muon_lep_pt->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_muon_lep_pt->Draw("PE sames");

  // //  h_alpgen_ptjmin10_muon_lep_pt->SetLineColor(kBlue);
  // h_alpgen_ptjmin10_muon_lep_pt->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_muon_lep_pt->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_muon_lep_pt->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_muon_lep_pt->Draw("PE sames");

  // // h_sherpa_nom_muon_lep_pt->SetLineWidth(1.2);
  // // h_sherpa_nom_muon_lep_pt->SetLineColor(kRed);
  // h_sherpa_nom_muon_lep_pt->SetMarkerStyle(20);
  // h_sherpa_nom_muon_lep_pt->SetMarkerSize(1.2);
  // h_sherpa_nom_muon_lep_pt->SetMarkerColor(kRed);
  // h_sherpa_nom_muon_lep_pt->Draw("PE sames");


  // //Legend
  // TLegend* lgnd_tc18 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc18->SetFillColor(0);
  // lgnd_tc18->SetTextSize(0.03);
  // lgnd_tc18->SetBorderSize(0);

  // char lgnd_alpgen_nom_muon_lep_pt_name[20];
  // sprintf(lgnd_alpgen_nom_muon_lep_pt_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_muon_lep_pt->Integral());
  // lgnd_tc18->AddEntry(h_alpgen_nom_muon_lep_pt,lgnd_alpgen_nom_muon_lep_pt_name,"p");

  // char lgnd_alpgen_iqopt3_muon_lep_pt_name[20];
  // sprintf(lgnd_alpgen_iqopt3_muon_lep_pt_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_muon_lep_pt->Integral());
  // lgnd_tc18->AddEntry(h_alpgen_iqopt3_muon_lep_pt,lgnd_alpgen_iqopt3_muon_lep_pt_name,"p");

  // char lgnd_alpgen_ptjmin10_muon_lep_pt_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_muon_lep_pt_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_muon_lep_pt->Integral());
  // lgnd_tc18->AddEntry(h_alpgen_ptjmin10_muon_lep_pt,lgnd_alpgen_ptjmin10_muon_lep_pt_name,"p");

  // char lgnd_sherpa_nom_muon_lep_pt_name[20];
  // sprintf(lgnd_sherpa_nom_muon_lep_pt_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_muon_lep_pt->Integral());
  // lgnd_tc18->AddEntry(h_sherpa_nom_muon_lep_pt,lgnd_sherpa_nom_muon_lep_pt_name,"p");

  // lgnd_tc18->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc18_pad01->cd();
  // tc18_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_muon_lep_pt->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_muon_lep_pt->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_muon_lep_pt->GetXaxis())->GetXmax();

  // // alp-sherp/sherp
  // string tc18_ratio_alpgen_sherpa_lep_pt_name = "tc18_ratio_alpgen_sherpa_lep_pt";
  // TH1F* h_ratio_alpgen_sherpa_lep_pt = new TH1F(tc18_ratio_alpgen_sherpa_lep_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_sherpa_lep_pt->SetMarkerStyle(8);
  // h_ratio_alpgen_sherpa_lep_pt->SetMarkerColor(kRed);

  // TAxis* h_ratio_alpgen_sherpa_lep_pt_xaxis = h_ratio_alpgen_sherpa_lep_pt->GetXaxis();
  // TAxis* h_ratio_alpgen_sherpa_lep_pt_yaxis = h_ratio_alpgen_sherpa_lep_pt->GetYaxis();
  
  // h_ratio_alpgen_sherpa_lep_pt_xaxis->SetLabelSize(0.08);
  // h_ratio_alpgen_sherpa_lep_pt_yaxis->SetLabelSize(0.08);

  // h_ratio_alpgen_sherpa_lep_pt_xaxis->SetTitle("Pt(muon)");
  // h_ratio_alpgen_sherpa_lep_pt_xaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_lep_pt_yaxis->SetNdivisions(4,4,4);
  // h_ratio_alpgen_sherpa_lep_pt_yaxis->SetTitle("(alpgen-MC)/MC");
  // h_ratio_alpgen_sherpa_lep_pt_yaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_lep_pt_yaxis->SetTitleOffset(0.36);
  // h_ratio_alpgen_sherpa_lep_pt_yaxis->SetRangeUser(-1,1);

  
  // // alp-iqopt3/iqopt3
  // string tc18_ratio_alpgen_iqopt3_lep_pt_name = "tc18_ratio_alpgen_iqopt3_lep_pt";
  // TH1F* h_ratio_alpgen_iqopt3_lep_pt = new TH1F(tc18_ratio_alpgen_iqopt3_lep_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_iqopt3_lep_pt->SetMarkerStyle(8);
  // h_ratio_alpgen_iqopt3_lep_pt->SetMarkerColor(kGreen);

  
  // // alp-ptjmin10/ptjmin10
  // string tc18_ratio_alpgen_ptjmin10_lep_pt_name = "tc18_ratio_alpgen_ptjmin10_lep_pt";
  // TH1F* h_ratio_alpgen_ptjmin10_lep_pt = new TH1F(tc18_ratio_alpgen_ptjmin10_lep_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_ptjmin10_lep_pt->SetMarkerStyle(8);
  // h_ratio_alpgen_ptjmin10_lep_pt->SetMarkerColor(kBlue);


  
  // double tc18_alpgen_sherpa_ratio=0.;
  // double tc18_alpgen_iqopt3_ratio=0.;
  // double tc18_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc18_alpgen_nom_bin_n=h_alpgen_nom_muon_lep_pt->GetBinContent(b);
  //   double tc18_alpgen_nom_bin_err=h_alpgen_nom_muon_lep_pt->GetBinError(b);    

  //   double tc18_sherpa_nom_bin_n=h_sherpa_nom_muon_lep_pt->GetBinContent(b);
  //   double tc18_sherpa_nom_bin_err=h_sherpa_nom_muon_lep_pt->GetBinError(b);    

  //   double tc18_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_muon_lep_pt->GetBinContent(b);
  //   double tc18_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_muon_lep_pt->GetBinError(b);

  //   double tc18_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_muon_lep_pt->GetBinContent(b);
  //   double tc18_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_muon_lep_pt->GetBinError(b);



  //   if(tc18_alpgen_nom_bin_n && tc18_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc18_abs_alpgen_sherpa_err = sqrt(pow(tc18_alpgen_nom_bin_err,2.)+pow(tc18_sherpa_nom_bin_err,2.));
  //     double tc18_rel_alpgen_sherpa_err = tc18_abs_alpgen_sherpa_err/(tc18_alpgen_nom_bin_n-tc18_sherpa_nom_bin_n);
  //     double tc18_rel_sherpa_err = tc18_sherpa_nom_bin_err/tc18_sherpa_nom_bin_n;
      
  //     double tc18_rel_ratio_alpgen_sherpa_lep_pt_err = sqrt(pow(tc18_rel_alpgen_sherpa_err,2.)+pow(tc18_rel_sherpa_err,2.));

  //     double tc18_alpgen_sherpa_ratio = (tc18_alpgen_nom_bin_n-tc18_sherpa_nom_bin_n)/tc18_sherpa_nom_bin_n;

  //     double tc18_alpgen_sherpa_ratio_err = fabs(tc18_rel_ratio_alpgen_sherpa_lep_pt_err*tc18_alpgen_sherpa_ratio);

  //     h_ratio_alpgen_sherpa_lep_pt->SetBinContent(b,tc18_alpgen_sherpa_ratio);
  //     h_ratio_alpgen_sherpa_lep_pt->SetBinError(b,tc18_alpgen_sherpa_ratio_err);
  //   }
    

  //   if(tc18_alpgen_nom_bin_n && tc18_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc18_abs_alpgen_iqopt3_err = sqrt(pow(tc18_alpgen_nom_bin_err,2.)+pow(tc18_alpgen_iqopt3_bin_err,2.));
  //     double tc18_rel_alpgen_iqopt3_err = tc18_abs_alpgen_iqopt3_err/(tc18_alpgen_nom_bin_n-tc18_alpgen_iqopt3_bin_n);
  //     double tc18_rel_iqopt3_err = tc18_alpgen_iqopt3_bin_err/tc18_alpgen_iqopt3_bin_n;
      
  //     double tc18_rel_ratio_alpgen_iqopt3_lep_pt_err = sqrt(pow(tc18_rel_alpgen_iqopt3_err,2.)+pow(tc18_rel_iqopt3_err,2.));

  //     double tc18_alpgen_iqopt3_ratio = (tc18_alpgen_nom_bin_n-tc18_alpgen_iqopt3_bin_n)/tc18_alpgen_iqopt3_bin_n;

  //     double tc18_alpgen_iqopt3_ratio_err = fabs(tc18_rel_ratio_alpgen_iqopt3_lep_pt_err*tc18_alpgen_iqopt3_ratio);

  //     h_ratio_alpgen_iqopt3_lep_pt->SetBinContent(b,tc18_alpgen_iqopt3_ratio);
  //     h_ratio_alpgen_iqopt3_lep_pt->SetBinError(b,tc18_alpgen_iqopt3_ratio_err);
  //   }

    

  //   if(tc18_alpgen_nom_bin_n && tc18_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc18_abs_alpgen_ptjmin10_err = sqrt(pow(tc18_alpgen_nom_bin_err,2.)+pow(tc18_alpgen_ptjmin10_bin_err,2.));
  //     double tc18_rel_alpgen_ptjmin10_err = tc18_abs_alpgen_ptjmin10_err/(tc18_alpgen_nom_bin_n-tc18_alpgen_ptjmin10_bin_n);
  //     double tc18_rel_ptjmin10_err = tc18_alpgen_ptjmin10_bin_err/tc18_alpgen_ptjmin10_bin_n;
      
  //     double tc18_rel_ratio_alpgen_ptjmin10_lep_pt_err = sqrt(pow(tc18_rel_alpgen_ptjmin10_err,2.)+pow(tc18_rel_ptjmin10_err,2.));

  //     double tc18_alpgen_ptjmin10_ratio = (tc18_alpgen_nom_bin_n-tc18_alpgen_ptjmin10_bin_n)/tc18_alpgen_ptjmin10_bin_n;

  //     double tc18_alpgen_ptjmin10_ratio_err = fabs(tc18_rel_ratio_alpgen_ptjmin10_lep_pt_err*tc18_alpgen_ptjmin10_ratio);

  //     h_ratio_alpgen_ptjmin10_lep_pt->SetBinContent(b,tc18_alpgen_ptjmin10_ratio);
  //     h_ratio_alpgen_ptjmin10_lep_pt->SetBinError(b,tc18_alpgen_ptjmin10_ratio_err);
  //   }
    
  // }


  // h_ratio_alpgen_sherpa_lep_pt->Draw("PE");
  // h_ratio_alpgen_iqopt3_lep_pt->Draw("PE sames");
  // h_ratio_alpgen_ptjmin10_lep_pt->Draw("PE sames");
  
  // tc18->Update();

  // tc18->SaveAs("./plots/latest/muon_lep_pt.png");
  
  // //NEXT  

  // //////////////////////////////////////////////////
  // // tc18_5
  // // data_muon_lep_pt: sherpa/alpgen+wjrw
  // //////////////////////////////////////////////////
  
  // string tc18_5_title = "Pt(muon) (muon) w/ Data";
  // string tc18_5_name = "tc18_5";
  // TCanvas* tc18_5 = new TCanvas(tc18_5_name.c_str(),tc18_5_title.c_str(),0,0,1920,1200);
  // tc18_5->cd();

  // TPad* tc18_5_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc18_5_pad01->SetTopMargin(0.05);
  // tc18_5_pad01->SetBottomMargin(0.31);
  // tc18_5_pad01->Draw();

  // TPad* tc18_5_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc18_5_pad02->SetBottomMargin(0.0005);
  // tc18_5_pad02->SetLogy();
  // tc18_5_pad02->Draw();
  // tc18_5_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_muon_lep_pt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_purw_nom_lep_pt");
  // TH1F* h_alpgen_iqopt3_muon_lep_pt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_iqopt3_lep_pt");
  // TH1F* h_alpgen_ptjmin10_muon_lep_pt = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_ptjmin10_lep_pt");
  // TH1F* h_sherpa_nom_muon_lep_pt = (TH1F*) wjets_sherpa_file->Get("all/h_muon_purw_nom_lep_pt");
  // TH1F* h_data_muon_lep_pt = (TH1F*) data_file->Get("all/h_muon_purw_nom_lep_pt");

  // TH1F* h_top_muon_lep_pt = (TH1F*) top_mcatnlo_file->Get("all/h_muon_purw_nom_lep_pt");
  // TH1F* h_zjets_muon_lep_pt = (TH1F*) zjets_alpgen_file->Get("all/h_muon_purw_nom_lep_pt");
  // TH1F* h_vv_muon_lep_pt = (TH1F*) vv_herwig_file->Get("all/h_muon_purw_nom_lep_pt");
  // TH1F* h_qcd_muon_lep_pt = (TH1F*) qcd_file->Get("all/h_muon_purw_nom_lep_pt");
  
  // h_data_muon_lep_pt->SetTitle("");
  // h_data_muon_lep_pt->Draw();
  
  // //Add Backgrounds
  // h_alpgen_nom_muon_lep_pt->Add(h_top_muon_lep_pt);
  // h_alpgen_nom_muon_lep_pt->Add(h_zjets_muon_lep_pt);
  // h_alpgen_nom_muon_lep_pt->Add(h_vv_muon_lep_pt);
  // h_alpgen_nom_muon_lep_pt->Add(h_qcd_muon_lep_pt);
  
  // h_alpgen_nom_muon_lep_pt->SetMarkerStyle(20);
  // h_alpgen_nom_muon_lep_pt->SetMarkerSize(1.2);
  // h_alpgen_nom_muon_lep_pt->Draw("PE sames");

  // //Add backgrounds
  // h_alpgen_iqopt3_muon_lep_pt->Add(h_top_muon_lep_pt);
  // h_alpgen_iqopt3_muon_lep_pt->Add(h_zjets_muon_lep_pt);
  // h_alpgen_iqopt3_muon_lep_pt->Add(h_vv_muon_lep_pt);
  // h_alpgen_iqopt3_muon_lep_pt->Add(h_qcd_muon_lep_pt);

  // h_alpgen_iqopt3_muon_lep_pt->SetMarkerStyle(22);
  // h_alpgen_iqopt3_muon_lep_pt->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_muon_lep_pt->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_muon_lep_pt->Draw("PE sames");

  // //Add Backgrounds
  // h_alpgen_ptjmin10_muon_lep_pt->Add(h_top_muon_lep_pt);
  // h_alpgen_ptjmin10_muon_lep_pt->Add(h_zjets_muon_lep_pt);
  // h_alpgen_ptjmin10_muon_lep_pt->Add(h_vv_muon_lep_pt);
  // h_alpgen_ptjmin10_muon_lep_pt->Add(h_qcd_muon_lep_pt);

  // h_alpgen_ptjmin10_muon_lep_pt->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_muon_lep_pt->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_muon_lep_pt->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_muon_lep_pt->Draw("PE sames");

  // //Add Backgrounds
  // h_sherpa_nom_muon_lep_pt->Add(h_top_muon_lep_pt);
  // h_sherpa_nom_muon_lep_pt->Add(h_zjets_muon_lep_pt);
  // h_sherpa_nom_muon_lep_pt->Add(h_vv_muon_lep_pt);
  // h_sherpa_nom_muon_lep_pt->Add(h_qcd_muon_lep_pt);

  // h_sherpa_nom_muon_lep_pt->SetMarkerStyle(20);
  // h_sherpa_nom_muon_lep_pt->SetMarkerSize(1.2);
  // h_sherpa_nom_muon_lep_pt->SetMarkerColor(kRed);
  // h_sherpa_nom_muon_lep_pt->Draw("PE sames");




  // //Legend
  // TLegend* lgnd_tc18_5 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc18_5->SetFillColor(0);
  // lgnd_tc18_5->SetTextSize(0.03);
  // lgnd_tc18_5->SetBorderSize(0);


  // char lgnd_data_muon_lep_pt_name[20];
  // sprintf(lgnd_data_muon_lep_pt_name,"%s,  %.2f","DATA",h_data_muon_lep_pt->Integral());
  // lgnd_tc18_5->AddEntry(h_data_muon_lep_pt,lgnd_data_muon_lep_pt_name,"f");

  // char lgnd_alpgen_nom_muon_lep_pt_name[20];
  // sprintf(lgnd_alpgen_nom_muon_lep_pt_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_muon_lep_pt->Integral());
  // lgnd_tc18_5->AddEntry(h_alpgen_nom_muon_lep_pt,lgnd_alpgen_nom_muon_lep_pt_name,"p");

  // char lgnd_alpgen_iqopt3_muon_lep_pt_name[20];
  // sprintf(lgnd_alpgen_iqopt3_muon_lep_pt_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_muon_lep_pt->Integral());
  // lgnd_tc18_5->AddEntry(h_alpgen_iqopt3_muon_lep_pt,lgnd_alpgen_iqopt3_muon_lep_pt_name,"p");

  // char lgnd_alpgen_ptjmin10_muon_lep_pt_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_muon_lep_pt_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_muon_lep_pt->Integral());
  // lgnd_tc18_5->AddEntry(h_alpgen_ptjmin10_muon_lep_pt,lgnd_alpgen_ptjmin10_muon_lep_pt_name,"p");

  // char lgnd_sherpa_nom_muon_lep_pt_name[20];
  // sprintf(lgnd_sherpa_nom_muon_lep_pt_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_muon_lep_pt->Integral());
  // lgnd_tc18_5->AddEntry(h_sherpa_nom_muon_lep_pt,lgnd_sherpa_nom_muon_lep_pt_name,"p");

  // lgnd_tc18_5->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc18_5_pad01->cd();
  // tc18_5_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_muon_lep_pt->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_muon_lep_pt->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_muon_lep_pt->GetXaxis())->GetXmax();

  // // data-alpgen(nom)/alpgen(nom)
  // string tc18_5_ratio_data_alpgen_lep_pt_name = "tc18_5_ratio_data_alpgen_lep_pt";
  // TH1F* h_ratio_data_alpgen_lep_pt = new TH1F(tc18_5_ratio_data_alpgen_lep_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_lep_pt->SetMarkerStyle(8);
  // //h_ratio_data_alpgen_lep_pt->SetMarkerColor(kRed);

  // TAxis* h_ratio_data_alpgen_lep_pt_xaxis = h_ratio_data_alpgen_lep_pt->GetXaxis();
  // TAxis* h_ratio_data_alpgen_lep_pt_yaxis = h_ratio_data_alpgen_lep_pt->GetYaxis();
  
  // h_ratio_data_alpgen_lep_pt_xaxis->SetLabelSize(0.08);
  // h_ratio_data_alpgen_lep_pt_yaxis->SetLabelSize(0.08);

  // h_ratio_data_alpgen_lep_pt_xaxis->SetTitle("Pt(muon)");
  // h_ratio_data_alpgen_lep_pt_xaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_lep_pt_yaxis->SetNdivisions(4,4,4);
  // h_ratio_data_alpgen_lep_pt_yaxis->SetTitle("(data-MC)/MC");
  // h_ratio_data_alpgen_lep_pt_yaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_lep_pt_yaxis->SetTitleOffset(0.36);
  // h_ratio_data_alpgen_lep_pt_yaxis->SetRangeUser(-1,1);

  // // data-sherpa(nom)/sherpa(nom)
  // string tc18_5_ratio_data_sherpa_lep_pt_name = "tc18_5_ratio_data_sherpa_lep_pt";
  // TH1F* h_ratio_data_sherpa_lep_pt = new TH1F(tc18_5_ratio_data_sherpa_lep_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_sherpa_lep_pt->SetMarkerStyle(8);
  // h_ratio_data_sherpa_lep_pt->SetMarkerColor(kRed);


  // // data-alpgen(iqopt3)/alpgen(iqopt3)
  // string tc18_5_ratio_data_alpgen_iqopt3_lep_pt_name = "tc18_5_ratio_data_alpgen_iqopt3_lep_pt";
  // TH1F* h_ratio_data_alpgen_iqopt3_lep_pt = new TH1F(tc18_5_ratio_data_alpgen_iqopt3_lep_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_iqopt3_lep_pt->SetMarkerStyle(8);
  // h_ratio_data_alpgen_iqopt3_lep_pt->SetMarkerColor(kGreen);

  // // data-alpgen(ptjmin10)/alpgen(ptjmin10)
  // string tc18_5_ratio_data_alpgen_ptjmin10_lep_pt_name = "tc18_5_ratio_data_alpgen_ptjmin10_lep_pt";
  // TH1F* h_ratio_data_alpgen_ptjmin10_lep_pt = new TH1F(tc18_5_ratio_data_alpgen_ptjmin10_lep_pt_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_ptjmin10_lep_pt->SetMarkerStyle(8);
  // h_ratio_data_alpgen_ptjmin10_lep_pt->SetMarkerColor(kBlue);

  

  
  // // // alp-iqopt3/iqopt3
  // // string tc18_5_ratio_alpgen_iqopt3_lead_jet_pt_name = "tc18_5_ratio_alpgen_iqopt3_lead_jet_pt";
  // // TH1F* h_ratio_alpgen_iqopt3_lead_jet_pt = new TH1F(tc18_5_ratio_alpgen_iqopt3_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerStyle(8);
  // // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerColor(kGreen);

  
  // // // alp-ptjmin10/ptjmin10
  // // string tc18_5_ratio_alpgen_ptjmin10_lead_jet_pt_name = "tc18_5_ratio_alpgen_ptjmin10_lead_jet_pt";
  // // TH1F* h_ratio_alpgen_ptjmin10_lead_jet_pt = new TH1F(tc18_5_ratio_alpgen_ptjmin10_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerStyle(8);
  // // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerColor(kBlue);


  
  // double tc18_5_data_alpgen_ratio=0.;
  // double tc18_5_data_sherpa_ratio=0.;
  // double tc18_5_data_alpgen_iqopt3_ratio=0.;
  // double tc18_5_data_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc18_5_alpgen_nom_bin_n=h_alpgen_nom_muon_lep_pt->GetBinContent(b);
  //   double tc18_5_alpgen_nom_bin_err=h_alpgen_nom_muon_lep_pt->GetBinError(b);    

  //   double tc18_5_data_bin_n=h_data_muon_lep_pt->GetBinContent(b);
  //   double tc18_5_data_bin_err=h_data_muon_lep_pt->GetBinError(b);    

  //   double tc18_5_sherpa_nom_bin_n=h_sherpa_nom_muon_lep_pt->GetBinContent(b);
  //   double tc18_5_sherpa_nom_bin_err=h_sherpa_nom_muon_lep_pt->GetBinError(b);    

  //   double tc18_5_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_muon_lep_pt->GetBinContent(b);
  //   double tc18_5_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_muon_lep_pt->GetBinError(b);

  //   double tc18_5_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_muon_lep_pt->GetBinContent(b);
  //   double tc18_5_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_muon_lep_pt->GetBinError(b);



  //   if(tc18_5_data_bin_n && tc18_5_alpgen_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc18_5_abs_data_alpgen_err = sqrt(pow(tc18_5_data_bin_err,2.)+pow(tc18_5_alpgen_nom_bin_err,2.));
  //     double tc18_5_rel_data_alpgen_err = tc18_5_abs_data_alpgen_err/(tc18_5_data_bin_n-tc18_5_alpgen_nom_bin_n);
  //     double tc18_5_rel_alpgen_err = tc18_5_alpgen_nom_bin_err/tc18_5_alpgen_nom_bin_n;
      
  //     double tc18_5_rel_ratio_data_alpgen_lep_pt_err = sqrt(pow(tc18_5_rel_data_alpgen_err,2.)+pow(tc18_5_rel_alpgen_err,2.));

  //     double tc18_5_data_alpgen_ratio = (tc18_5_data_bin_n-tc18_5_alpgen_nom_bin_n)/tc18_5_alpgen_nom_bin_n;

  //     double tc18_5_data_alpgen_ratio_err = fabs(tc18_5_rel_ratio_data_alpgen_lep_pt_err*tc18_5_data_alpgen_ratio);

  //     h_ratio_data_alpgen_lep_pt->SetBinContent(b,tc18_5_data_alpgen_ratio);
  //     h_ratio_data_alpgen_lep_pt->SetBinError(b,tc18_5_data_alpgen_ratio_err);
  //   }
    

  //   if(tc18_5_data_bin_n && tc18_5_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc18_5_abs_data_sherpa_err = sqrt(pow(tc18_5_data_bin_err,2.)+pow(tc18_5_sherpa_nom_bin_err,2.));
  //     double tc18_5_rel_data_sherpa_err = tc18_5_abs_data_sherpa_err/(tc18_5_data_bin_n-tc18_5_sherpa_nom_bin_n);
  //     double tc18_5_rel_sherpa_err = tc18_5_sherpa_nom_bin_err/tc18_5_sherpa_nom_bin_n;
      
  //     double tc18_5_rel_ratio_data_sherpa_lep_pt_err = sqrt(pow(tc18_5_rel_data_sherpa_err,2.)+pow(tc18_5_rel_sherpa_err,2.));

  //     double tc18_5_data_sherpa_ratio = (tc18_5_data_bin_n-tc18_5_sherpa_nom_bin_n)/tc18_5_sherpa_nom_bin_n;

  //     double tc18_5_data_sherpa_ratio_err = fabs(tc18_5_rel_ratio_data_sherpa_lep_pt_err*tc18_5_data_sherpa_ratio);

  //     h_ratio_data_sherpa_lep_pt->SetBinContent(b,tc18_5_data_sherpa_ratio);
  //     h_ratio_data_sherpa_lep_pt->SetBinError(b,tc18_5_data_sherpa_ratio_err);
  //   }
    

  //   if(tc18_5_data_bin_n && tc18_5_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc18_5_abs_data_alpgen_iqopt3_err = sqrt(pow(tc18_5_data_bin_err,2.)+pow(tc18_5_alpgen_iqopt3_bin_err,2.));
  //     double tc18_5_rel_data_alpgen_iqopt3_err = tc18_5_abs_data_alpgen_iqopt3_err/(tc18_5_data_bin_n-tc18_5_alpgen_iqopt3_bin_n);
  //     double tc18_5_rel_alpgen_iqopt3_err = tc18_5_alpgen_iqopt3_bin_err/tc18_5_alpgen_iqopt3_bin_n;
      
  //     double tc18_5_rel_ratio_data_alpgen_iqopt3_lep_pt_err = sqrt(pow(tc18_5_rel_data_alpgen_iqopt3_err,2.)+pow(tc18_5_rel_alpgen_iqopt3_err,2.));

  //     double tc18_5_data_alpgen_iqopt3_ratio = (tc18_5_data_bin_n-tc18_5_alpgen_iqopt3_bin_n)/tc18_5_alpgen_iqopt3_bin_n;

  //     double tc18_5_data_alpgen_iqopt3_ratio_err = fabs(tc18_5_rel_ratio_data_alpgen_iqopt3_lep_pt_err*tc18_5_data_alpgen_iqopt3_ratio);

  //     h_ratio_data_alpgen_iqopt3_lep_pt->SetBinContent(b,tc18_5_data_alpgen_iqopt3_ratio);
  //     h_ratio_data_alpgen_iqopt3_lep_pt->SetBinError(b,tc18_5_data_alpgen_iqopt3_ratio_err);
  //   }
    
  //   if(tc18_5_data_bin_n && tc18_5_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc18_5_abs_data_alpgen_ptjmin10_err = sqrt(pow(tc18_5_data_bin_err,2.)+pow(tc18_5_alpgen_ptjmin10_bin_err,2.));
  //     double tc18_5_rel_data_alpgen_ptjmin10_err = tc18_5_abs_data_alpgen_ptjmin10_err/(tc18_5_data_bin_n-tc18_5_alpgen_ptjmin10_bin_n);
  //     double tc18_5_rel_alpgen_ptjmin10_err = tc18_5_alpgen_ptjmin10_bin_err/tc18_5_alpgen_ptjmin10_bin_n;
      
  //     double tc18_5_rel_ratio_data_alpgen_ptjmin10_lep_pt_err = sqrt(pow(tc18_5_rel_data_alpgen_ptjmin10_err,2.)+pow(tc18_5_rel_alpgen_ptjmin10_err,2.));

  //     double tc18_5_data_alpgen_ptjmin10_ratio = (tc18_5_data_bin_n-tc18_5_alpgen_ptjmin10_bin_n)/tc18_5_alpgen_ptjmin10_bin_n;

  //     double tc18_5_data_alpgen_ptjmin10_ratio_err = fabs(tc18_5_rel_ratio_data_alpgen_ptjmin10_lep_pt_err*tc18_5_data_alpgen_ptjmin10_ratio);

  //     h_ratio_data_alpgen_ptjmin10_lep_pt->SetBinContent(b,tc18_5_data_alpgen_ptjmin10_ratio);
  //     h_ratio_data_alpgen_ptjmin10_lep_pt->SetBinError(b,tc18_5_data_alpgen_ptjmin10_ratio_err);
  //   }
  // }


  // h_ratio_data_alpgen_lep_pt->Draw("PE");
  // h_ratio_data_sherpa_lep_pt->Draw("PE sames");
  // h_ratio_data_alpgen_iqopt3_lep_pt->Draw("PE sames");
  // h_ratio_data_alpgen_ptjmin10_lep_pt->Draw("PE sames");
  
  // //  h_ratio_alpgen_iqopt3_lep_pt->Draw("PE sames");
  // //  h_ratio_alpgen_ptjmin10_lep_pt->Draw("PE sames");
  
  // tc18_5->Update();
  // tc18_5->SaveAs("./plots/latest/data_muon_lep_pt.png");
    


  // //NEXT
  
  // ////////////////////////////////////////////////// 
  // // tc19
  // // elec_lep_eta: tc19_sherpa/alpgen+wjrw
  // ////////////////////////////////////////////////// 

  // string tc19_title = "Eta(elec) (elec)";
  // string tc19_name = "tc19";
  // TCanvas* tc19 = new TCanvas(tc19_name.c_str(),tc19_title.c_str(),0,0,1920,1200);
  // tc19->cd();

  // TPad* tc19_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc19_pad01->SetTopMargin(0.05);
  // tc19_pad01->SetBottomMargin(0.31);
  // tc19_pad01->Draw();

  // TPad* tc19_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc19_pad02->SetBottomMargin(0.0005);
  // //tc19_pad02->SetLogy();
  // tc19_pad02->Draw();
  // tc19_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_elec_lep_eta = (TH1F*) wjets_alpgen_file->Get("all/h_elec_purw_nom_lep_eta");
  // TH1F* h_alpgen_iqopt3_elec_lep_eta = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_iqopt3_lep_eta");
  // TH1F* h_alpgen_ptjmin10_elec_lep_eta = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_ptjmin10_lep_eta");
  // TH1F* h_sherpa_nom_elec_lep_eta = (TH1F*) wjets_sherpa_file->Get("all/h_elec_purw_nom_lep_eta");

  // //h_alpgen_nom_elec_lep_eta->SetLineWidth(2);
  // h_alpgen_nom_elec_lep_eta->SetMarkerStyle(20);
  // h_alpgen_nom_elec_lep_eta->SetMarkerSize(1.2);
  // h_alpgen_nom_elec_lep_eta->SetTitle("");
  // h_alpgen_nom_elec_lep_eta->Draw("PE");

  // //h_alpgen_iqopt3_elec_lep_eta->SetLineColor(kGreen);
  // h_alpgen_iqopt3_elec_lep_eta->SetMarkerStyle(22);
  // h_alpgen_iqopt3_elec_lep_eta->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_elec_lep_eta->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_elec_lep_eta->Draw("PE sames");

  // //  h_alpgen_ptjmin10_elec_lep_eta->SetLineColor(kBlue);
  // h_alpgen_ptjmin10_elec_lep_eta->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_elec_lep_eta->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_elec_lep_eta->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_elec_lep_eta->Draw("PE sames");

  // // h_sherpa_nom_elec_lep_eta->SetLineWidth(1.2);
  // // h_sherpa_nom_elec_lep_eta->SetLineColor(kRed);
  // h_sherpa_nom_elec_lep_eta->SetMarkerStyle(20);
  // h_sherpa_nom_elec_lep_eta->SetMarkerSize(1.2);
  // h_sherpa_nom_elec_lep_eta->SetMarkerColor(kRed);
  // h_sherpa_nom_elec_lep_eta->Draw("PE sames");


  // //Legend
  // TLegend* lgnd_tc19 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc19->SetFillColor(0);
  // lgnd_tc19->SetTextSize(0.03);
  // lgnd_tc19->SetBorderSize(0);

  // char lgnd_alpgen_nom_elec_lep_eta_name[20];
  // sprintf(lgnd_alpgen_nom_elec_lep_eta_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_elec_lep_eta->Integral());
  // lgnd_tc19->AddEntry(h_alpgen_nom_elec_lep_eta,lgnd_alpgen_nom_elec_lep_eta_name,"p");

  // char lgnd_alpgen_iqopt3_elec_lep_eta_name[20];
  // sprintf(lgnd_alpgen_iqopt3_elec_lep_eta_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_elec_lep_eta->Integral());
  // lgnd_tc19->AddEntry(h_alpgen_iqopt3_elec_lep_eta,lgnd_alpgen_iqopt3_elec_lep_eta_name,"p");

  // char lgnd_alpgen_ptjmin10_elec_lep_eta_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_elec_lep_eta_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_elec_lep_eta->Integral());
  // lgnd_tc19->AddEntry(h_alpgen_ptjmin10_elec_lep_eta,lgnd_alpgen_ptjmin10_elec_lep_eta_name,"p");

  // char lgnd_sherpa_nom_elec_lep_eta_name[20];
  // sprintf(lgnd_sherpa_nom_elec_lep_eta_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_elec_lep_eta->Integral());
  // lgnd_tc19->AddEntry(h_sherpa_nom_elec_lep_eta,lgnd_sherpa_nom_elec_lep_eta_name,"p");

  // lgnd_tc19->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc19_pad01->cd();
  // tc19_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_elec_lep_eta->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_elec_lep_eta->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_elec_lep_eta->GetXaxis())->GetXmax();

  // // alp-sherp/sherp
  // string tc19_ratio_alpgen_sherpa_lep_eta_name = "tc19_ratio_alpgen_sherpa_lep_eta";
  // TH1F* h_ratio_alpgen_sherpa_lep_eta = new TH1F(tc19_ratio_alpgen_sherpa_lep_eta_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_sherpa_lep_eta->SetMarkerStyle(8);
  // h_ratio_alpgen_sherpa_lep_eta->SetMarkerColor(kRed);

  // TAxis* h_ratio_alpgen_sherpa_lep_eta_xaxis = h_ratio_alpgen_sherpa_lep_eta->GetXaxis();
  // TAxis* h_ratio_alpgen_sherpa_lep_eta_yaxis = h_ratio_alpgen_sherpa_lep_eta->GetYaxis();
  
  // h_ratio_alpgen_sherpa_lep_eta_xaxis->SetLabelSize(0.08);
  // h_ratio_alpgen_sherpa_lep_eta_yaxis->SetLabelSize(0.08);

  // h_ratio_alpgen_sherpa_lep_eta_xaxis->SetTitle("Eta(elec)");
  // h_ratio_alpgen_sherpa_lep_eta_xaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_lep_eta_yaxis->SetNdivisions(4,4,4);
  // h_ratio_alpgen_sherpa_lep_eta_yaxis->SetTitle("(alpgen-MC)/MC");
  // h_ratio_alpgen_sherpa_lep_eta_yaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_lep_eta_yaxis->SetTitleOffset(0.36);
  // h_ratio_alpgen_sherpa_lep_eta_yaxis->SetRangeUser(-1,1);

  
  // // alp-iqopt3/iqopt3
  // string tc19_ratio_alpgen_iqopt3_lep_eta_name = "tc19_ratio_alpgen_iqopt3_lep_eta";
  // TH1F* h_ratio_alpgen_iqopt3_lep_eta = new TH1F(tc19_ratio_alpgen_iqopt3_lep_eta_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_iqopt3_lep_eta->SetMarkerStyle(8);
  // h_ratio_alpgen_iqopt3_lep_eta->SetMarkerColor(kGreen);

  
  // // alp-ptjmin10/ptjmin10
  // string tc19_ratio_alpgen_ptjmin10_lep_eta_name = "tc19_ratio_alpgen_ptjmin10_lep_eta";
  // TH1F* h_ratio_alpgen_ptjmin10_lep_eta = new TH1F(tc19_ratio_alpgen_ptjmin10_lep_eta_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_ptjmin10_lep_eta->SetMarkerStyle(8);
  // h_ratio_alpgen_ptjmin10_lep_eta->SetMarkerColor(kBlue);


  
  // double tc19_alpgen_sherpa_ratio=0.;
  // double tc19_alpgen_iqopt3_ratio=0.;
  // double tc19_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc19_alpgen_nom_bin_n=h_alpgen_nom_elec_lep_eta->GetBinContent(b);
  //   double tc19_alpgen_nom_bin_err=h_alpgen_nom_elec_lep_eta->GetBinError(b);    

  //   double tc19_sherpa_nom_bin_n=h_sherpa_nom_elec_lep_eta->GetBinContent(b);
  //   double tc19_sherpa_nom_bin_err=h_sherpa_nom_elec_lep_eta->GetBinError(b);    

  //   double tc19_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_elec_lep_eta->GetBinContent(b);
  //   double tc19_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_elec_lep_eta->GetBinError(b);

  //   double tc19_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_elec_lep_eta->GetBinContent(b);
  //   double tc19_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_elec_lep_eta->GetBinError(b);



  //   if(tc19_alpgen_nom_bin_n && tc19_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc19_abs_alpgen_sherpa_err = sqrt(pow(tc19_alpgen_nom_bin_err,2.)+pow(tc19_sherpa_nom_bin_err,2.));
  //     double tc19_rel_alpgen_sherpa_err = tc19_abs_alpgen_sherpa_err/(tc19_alpgen_nom_bin_n-tc19_sherpa_nom_bin_n);
  //     double tc19_rel_sherpa_err = tc19_sherpa_nom_bin_err/tc19_sherpa_nom_bin_n;
      
  //     double tc19_rel_ratio_alpgen_sherpa_lep_eta_err = sqrt(pow(tc19_rel_alpgen_sherpa_err,2.)+pow(tc19_rel_sherpa_err,2.));

  //     double tc19_alpgen_sherpa_ratio = (tc19_alpgen_nom_bin_n-tc19_sherpa_nom_bin_n)/tc19_sherpa_nom_bin_n;

  //     double tc19_alpgen_sherpa_ratio_err = fabs(tc19_rel_ratio_alpgen_sherpa_lep_eta_err*tc19_alpgen_sherpa_ratio);

  //     h_ratio_alpgen_sherpa_lep_eta->SetBinContent(b,tc19_alpgen_sherpa_ratio);
  //     h_ratio_alpgen_sherpa_lep_eta->SetBinError(b,tc19_alpgen_sherpa_ratio_err);
  //   }
    

  //   if(tc19_alpgen_nom_bin_n && tc19_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc19_abs_alpgen_iqopt3_err = sqrt(pow(tc19_alpgen_nom_bin_err,2.)+pow(tc19_alpgen_iqopt3_bin_err,2.));
  //     double tc19_rel_alpgen_iqopt3_err = tc19_abs_alpgen_iqopt3_err/(tc19_alpgen_nom_bin_n-tc19_alpgen_iqopt3_bin_n);
  //     double tc19_rel_iqopt3_err = tc19_alpgen_iqopt3_bin_err/tc19_alpgen_iqopt3_bin_n;
      
  //     double tc19_rel_ratio_alpgen_iqopt3_lep_eta_err = sqrt(pow(tc19_rel_alpgen_iqopt3_err,2.)+pow(tc19_rel_iqopt3_err,2.));

  //     double tc19_alpgen_iqopt3_ratio = (tc19_alpgen_nom_bin_n-tc19_alpgen_iqopt3_bin_n)/tc19_alpgen_iqopt3_bin_n;

  //     double tc19_alpgen_iqopt3_ratio_err = fabs(tc19_rel_ratio_alpgen_iqopt3_lep_eta_err*tc19_alpgen_iqopt3_ratio);

  //     h_ratio_alpgen_iqopt3_lep_eta->SetBinContent(b,tc19_alpgen_iqopt3_ratio);
  //     h_ratio_alpgen_iqopt3_lep_eta->SetBinError(b,tc19_alpgen_iqopt3_ratio_err);
  //   }

    

  //   if(tc19_alpgen_nom_bin_n && tc19_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc19_abs_alpgen_ptjmin10_err = sqrt(pow(tc19_alpgen_nom_bin_err,2.)+pow(tc19_alpgen_ptjmin10_bin_err,2.));
  //     double tc19_rel_alpgen_ptjmin10_err = tc19_abs_alpgen_ptjmin10_err/(tc19_alpgen_nom_bin_n-tc19_alpgen_ptjmin10_bin_n);
  //     double tc19_rel_ptjmin10_err = tc19_alpgen_ptjmin10_bin_err/tc19_alpgen_ptjmin10_bin_n;
      
  //     double tc19_rel_ratio_alpgen_ptjmin10_lep_eta_err = sqrt(pow(tc19_rel_alpgen_ptjmin10_err,2.)+pow(tc19_rel_ptjmin10_err,2.));

  //     double tc19_alpgen_ptjmin10_ratio = (tc19_alpgen_nom_bin_n-tc19_alpgen_ptjmin10_bin_n)/tc19_alpgen_ptjmin10_bin_n;

  //     double tc19_alpgen_ptjmin10_ratio_err = fabs(tc19_rel_ratio_alpgen_ptjmin10_lep_eta_err*tc19_alpgen_ptjmin10_ratio);

  //     h_ratio_alpgen_ptjmin10_lep_eta->SetBinContent(b,tc19_alpgen_ptjmin10_ratio);
  //     h_ratio_alpgen_ptjmin10_lep_eta->SetBinError(b,tc19_alpgen_ptjmin10_ratio_err);
  //   }
    
  // }


  // h_ratio_alpgen_sherpa_lep_eta->Draw("PE");
  // h_ratio_alpgen_iqopt3_lep_eta->Draw("PE sames");
  // h_ratio_alpgen_ptjmin10_lep_eta->Draw("PE sames");
  
  // tc19->Update();

  // tc19->SaveAs("./plots/latest/elec_lep_eta.png");
  

  // //NEXT
  
  // //////////////////////////////////////////////////
  // // tc19_5
  // // data_elec_lep_eta: sherpa/alpgen+wjrw
  // //////////////////////////////////////////////////
  
  // string tc19_5_title = "Eta(elec) (elec) w/ Data";
  // string tc19_5_name = "tc19_5";
  // TCanvas* tc19_5 = new TCanvas(tc19_5_name.c_str(),tc19_5_title.c_str(),0,0,1920,1200);
  // tc19_5->cd();

  // TPad* tc19_5_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc19_5_pad01->SetTopMargin(0.05);
  // tc19_5_pad01->SetBottomMargin(0.31);
  // tc19_5_pad01->Draw();

  // TPad* tc19_5_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc19_5_pad02->SetBottomMargin(0.0005);
  // //tc19_5_pad02->SetLogy();
  // tc19_5_pad02->Draw();
  // tc19_5_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_elec_lep_eta = (TH1F*) wjets_alpgen_file->Get("all/h_elec_purw_nom_lep_eta");
  // TH1F* h_alpgen_iqopt3_elec_lep_eta = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_iqopt3_lep_eta");
  // TH1F* h_alpgen_ptjmin10_elec_lep_eta = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_ptjmin10_lep_eta");
  // TH1F* h_sherpa_nom_elec_lep_eta = (TH1F*) wjets_sherpa_file->Get("all/h_elec_purw_nom_lep_eta");
  // TH1F* h_data_elec_lep_eta = (TH1F*) data_file->Get("all/h_elec_purw_nom_lep_eta");

  // TH1F* h_top_elec_lep_eta = (TH1F*) top_mcatnlo_file->Get("all/h_elec_purw_nom_lep_eta");
  // TH1F* h_zjets_elec_lep_eta = (TH1F*) zjets_alpgen_file->Get("all/h_elec_purw_nom_lep_eta");
  // TH1F* h_vv_elec_lep_eta = (TH1F*) vv_herwig_file->Get("all/h_elec_purw_nom_lep_eta");
  // TH1F* h_qcd_elec_lep_eta = (TH1F*) qcd_file->Get("all/h_elec_purw_nom_lep_eta");
  
  // h_data_elec_lep_eta->SetTitle("");
  // h_data_elec_lep_eta->Draw();
  
  // //Add Backgrounds
  // h_alpgen_nom_elec_lep_eta->Add(h_top_elec_lep_eta);
  // h_alpgen_nom_elec_lep_eta->Add(h_zjets_elec_lep_eta);
  // h_alpgen_nom_elec_lep_eta->Add(h_vv_elec_lep_eta);
  // h_alpgen_nom_elec_lep_eta->Add(h_qcd_elec_lep_eta);
  
  // h_alpgen_nom_elec_lep_eta->SetMarkerStyle(20);
  // h_alpgen_nom_elec_lep_eta->SetMarkerSize(1.2);
  // h_alpgen_nom_elec_lep_eta->Draw("PE sames");

  // //Add backgrounds
  // h_alpgen_iqopt3_elec_lep_eta->Add(h_top_elec_lep_eta);
  // h_alpgen_iqopt3_elec_lep_eta->Add(h_zjets_elec_lep_eta);
  // h_alpgen_iqopt3_elec_lep_eta->Add(h_vv_elec_lep_eta);
  // h_alpgen_iqopt3_elec_lep_eta->Add(h_qcd_elec_lep_eta);

  // h_alpgen_iqopt3_elec_lep_eta->SetMarkerStyle(22);
  // h_alpgen_iqopt3_elec_lep_eta->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_elec_lep_eta->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_elec_lep_eta->Draw("PE sames");

  // //Add Backgrounds
  // h_alpgen_ptjmin10_elec_lep_eta->Add(h_top_elec_lep_eta);
  // h_alpgen_ptjmin10_elec_lep_eta->Add(h_zjets_elec_lep_eta);
  // h_alpgen_ptjmin10_elec_lep_eta->Add(h_vv_elec_lep_eta);
  // h_alpgen_ptjmin10_elec_lep_eta->Add(h_qcd_elec_lep_eta);

  // h_alpgen_ptjmin10_elec_lep_eta->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_elec_lep_eta->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_elec_lep_eta->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_elec_lep_eta->Draw("PE sames");

  // //Add Backgrounds
  // h_sherpa_nom_elec_lep_eta->Add(h_top_elec_lep_eta);
  // h_sherpa_nom_elec_lep_eta->Add(h_zjets_elec_lep_eta);
  // h_sherpa_nom_elec_lep_eta->Add(h_vv_elec_lep_eta);
  // h_sherpa_nom_elec_lep_eta->Add(h_qcd_elec_lep_eta);

  // h_sherpa_nom_elec_lep_eta->SetMarkerStyle(20);
  // h_sherpa_nom_elec_lep_eta->SetMarkerSize(1.2);
  // h_sherpa_nom_elec_lep_eta->SetMarkerColor(kRed);
  // h_sherpa_nom_elec_lep_eta->Draw("PE sames");




  // //Legend
  // TLegend* lgnd_tc19_5 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc19_5->SetFillColor(0);
  // lgnd_tc19_5->SetTextSize(0.03);
  // lgnd_tc19_5->SetBorderSize(0);

  // char lgnd_data_elec_lep_eta_name[20];
  // sprintf(lgnd_data_elec_lep_eta_name,"%s,  %.2f","DATA",h_data_elec_lep_eta->Integral());
  // lgnd_tc19_5->AddEntry(h_data_elec_lep_eta,lgnd_data_elec_lep_eta_name,"f");

  // char lgnd_alpgen_nom_elec_lep_eta_name[20];
  // sprintf(lgnd_alpgen_nom_elec_lep_eta_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_elec_lep_eta->Integral());
  // lgnd_tc19_5->AddEntry(h_alpgen_nom_elec_lep_eta,lgnd_alpgen_nom_elec_lep_eta_name,"p");

  // char lgnd_alpgen_iqopt3_elec_lep_eta_name[20];
  // sprintf(lgnd_alpgen_iqopt3_elec_lep_eta_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_elec_lep_eta->Integral());
  // lgnd_tc19_5->AddEntry(h_alpgen_iqopt3_elec_lep_eta,lgnd_alpgen_iqopt3_elec_lep_eta_name,"p");

  // char lgnd_alpgen_ptjmin10_elec_lep_eta_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_elec_lep_eta_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_elec_lep_eta->Integral());
  // lgnd_tc19_5->AddEntry(h_alpgen_ptjmin10_elec_lep_eta,lgnd_alpgen_ptjmin10_elec_lep_eta_name,"p");

  // char lgnd_sherpa_nom_elec_lep_eta_name[20];
  // sprintf(lgnd_sherpa_nom_elec_lep_eta_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_elec_lep_eta->Integral());
  // lgnd_tc19_5->AddEntry(h_sherpa_nom_elec_lep_eta,lgnd_sherpa_nom_elec_lep_eta_name,"p");

  // lgnd_tc19_5->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc19_5_pad01->cd();
  // tc19_5_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_elec_lep_eta->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_elec_lep_eta->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_elec_lep_eta->GetXaxis())->GetXmax();

  // // data-alpgen(nom)/alpgen(nom)
  // string tc19_5_ratio_data_alpgen_lep_eta_name = "tc19_5_ratio_data_alpgen_lep_eta";
  // TH1F* h_ratio_data_alpgen_lep_eta = new TH1F(tc19_5_ratio_data_alpgen_lep_eta_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_lep_eta->SetMarkerStyle(8);
  // //h_ratio_data_alpgen_lep_eta->SetMarkerColor(kRed);

  // TAxis* h_ratio_data_alpgen_lep_eta_xaxis = h_ratio_data_alpgen_lep_eta->GetXaxis();
  // TAxis* h_ratio_data_alpgen_lep_eta_yaxis = h_ratio_data_alpgen_lep_eta->GetYaxis();
  
  // h_ratio_data_alpgen_lep_eta_xaxis->SetLabelSize(0.08);
  // h_ratio_data_alpgen_lep_eta_yaxis->SetLabelSize(0.08);

  // h_ratio_data_alpgen_lep_eta_xaxis->SetTitle("Eta(elec)");
  // h_ratio_data_alpgen_lep_eta_xaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_lep_eta_yaxis->SetNdivisions(4,4,4);
  // h_ratio_data_alpgen_lep_eta_yaxis->SetTitle("(data-MC)/MC");
  // h_ratio_data_alpgen_lep_eta_yaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_lep_eta_yaxis->SetTitleOffset(0.36);
  // h_ratio_data_alpgen_lep_eta_yaxis->SetRangeUser(-1,1);

  // // data-sherpa(nom)/sherpa(nom)
  // string tc19_5_ratio_data_sherpa_lep_eta_name = "tc19_5_ratio_data_sherpa_lep_eta";
  // TH1F* h_ratio_data_sherpa_lep_eta = new TH1F(tc19_5_ratio_data_sherpa_lep_eta_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_sherpa_lep_eta->SetMarkerStyle(8);
  // h_ratio_data_sherpa_lep_eta->SetMarkerColor(kRed);


  // // data-alpgen(iqopt3)/alpgen(iqopt3)
  // string tc19_5_ratio_data_alpgen_iqopt3_lep_eta_name = "tc19_5_ratio_data_alpgen_iqopt3_lep_eta";
  // TH1F* h_ratio_data_alpgen_iqopt3_lep_eta = new TH1F(tc19_5_ratio_data_alpgen_iqopt3_lep_eta_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_iqopt3_lep_eta->SetMarkerStyle(8);
  // h_ratio_data_alpgen_iqopt3_lep_eta->SetMarkerColor(kGreen);

  // // data-alpgen(ptjmin10)/alpgen(ptjmin10)
  // string tc19_5_ratio_data_alpgen_ptjmin10_lep_eta_name = "tc19_5_ratio_data_alpgen_ptjmin10_lep_eta";
  // TH1F* h_ratio_data_alpgen_ptjmin10_lep_eta = new TH1F(tc19_5_ratio_data_alpgen_ptjmin10_lep_eta_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_ptjmin10_lep_eta->SetMarkerStyle(8);
  // h_ratio_data_alpgen_ptjmin10_lep_eta->SetMarkerColor(kBlue);

  

  
  // // // alp-iqopt3/iqopt3
  // // string tc19_5_ratio_alpgen_iqopt3_lead_jet_pt_name = "tc19_5_ratio_alpgen_iqopt3_lead_jet_pt";
  // // TH1F* h_ratio_alpgen_iqopt3_lead_jet_pt = new TH1F(tc19_5_ratio_alpgen_iqopt3_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerStyle(8);
  // // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerColor(kGreen);

  
  // // // alp-ptjmin10/ptjmin10
  // // string tc19_5_ratio_alpgen_ptjmin10_lead_jet_pt_name = "tc19_5_ratio_alpgen_ptjmin10_lead_jet_pt";
  // // TH1F* h_ratio_alpgen_ptjmin10_lead_jet_pt = new TH1F(tc19_5_ratio_alpgen_ptjmin10_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerStyle(8);
  // // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerColor(kBlue);


  
  // double tc19_5_data_alpgen_ratio=0.;
  // double tc19_5_data_sherpa_ratio=0.;
  // double tc19_5_data_alpgen_iqopt3_ratio=0.;
  // double tc19_5_data_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc19_5_alpgen_nom_bin_n=h_alpgen_nom_elec_lep_eta->GetBinContent(b);
  //   double tc19_5_alpgen_nom_bin_err=h_alpgen_nom_elec_lep_eta->GetBinError(b);    

  //   double tc19_5_data_bin_n=h_data_elec_lep_eta->GetBinContent(b);
  //   double tc19_5_data_bin_err=h_data_elec_lep_eta->GetBinError(b);    

  //   double tc19_5_sherpa_nom_bin_n=h_sherpa_nom_elec_lep_eta->GetBinContent(b);
  //   double tc19_5_sherpa_nom_bin_err=h_sherpa_nom_elec_lep_eta->GetBinError(b);    

  //   double tc19_5_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_elec_lep_eta->GetBinContent(b);
  //   double tc19_5_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_elec_lep_eta->GetBinError(b);

  //   double tc19_5_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_elec_lep_eta->GetBinContent(b);
  //   double tc19_5_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_elec_lep_eta->GetBinError(b);



  //   if(tc19_5_data_bin_n && tc19_5_alpgen_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc19_5_abs_data_alpgen_err = sqrt(pow(tc19_5_data_bin_err,2.)+pow(tc19_5_alpgen_nom_bin_err,2.));
  //     double tc19_5_rel_data_alpgen_err = tc19_5_abs_data_alpgen_err/(tc19_5_data_bin_n-tc19_5_alpgen_nom_bin_n);
  //     double tc19_5_rel_alpgen_err = tc19_5_alpgen_nom_bin_err/tc19_5_alpgen_nom_bin_n;
      
  //     double tc19_5_rel_ratio_data_alpgen_lep_eta_err = sqrt(pow(tc19_5_rel_data_alpgen_err,2.)+pow(tc19_5_rel_alpgen_err,2.));

  //     double tc19_5_data_alpgen_ratio = (tc19_5_data_bin_n-tc19_5_alpgen_nom_bin_n)/tc19_5_alpgen_nom_bin_n;

  //     double tc19_5_data_alpgen_ratio_err = fabs(tc19_5_rel_ratio_data_alpgen_lep_eta_err*tc19_5_data_alpgen_ratio);

  //     h_ratio_data_alpgen_lep_eta->SetBinContent(b,tc19_5_data_alpgen_ratio);
  //     h_ratio_data_alpgen_lep_eta->SetBinError(b,tc19_5_data_alpgen_ratio_err);
  //   }
    

  //   if(tc19_5_data_bin_n && tc19_5_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc19_5_abs_data_sherpa_err = sqrt(pow(tc19_5_data_bin_err,2.)+pow(tc19_5_sherpa_nom_bin_err,2.));
  //     double tc19_5_rel_data_sherpa_err = tc19_5_abs_data_sherpa_err/(tc19_5_data_bin_n-tc19_5_sherpa_nom_bin_n);
  //     double tc19_5_rel_sherpa_err = tc19_5_sherpa_nom_bin_err/tc19_5_sherpa_nom_bin_n;
      
  //     double tc19_5_rel_ratio_data_sherpa_lep_eta_err = sqrt(pow(tc19_5_rel_data_sherpa_err,2.)+pow(tc19_5_rel_sherpa_err,2.));

  //     double tc19_5_data_sherpa_ratio = (tc19_5_data_bin_n-tc19_5_sherpa_nom_bin_n)/tc19_5_sherpa_nom_bin_n;

  //     double tc19_5_data_sherpa_ratio_err = fabs(tc19_5_rel_ratio_data_sherpa_lep_eta_err*tc19_5_data_sherpa_ratio);

  //     h_ratio_data_sherpa_lep_eta->SetBinContent(b,tc19_5_data_sherpa_ratio);
  //     h_ratio_data_sherpa_lep_eta->SetBinError(b,tc19_5_data_sherpa_ratio_err);
  //   }
    

  //   if(tc19_5_data_bin_n && tc19_5_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc19_5_abs_data_alpgen_iqopt3_err = sqrt(pow(tc19_5_data_bin_err,2.)+pow(tc19_5_alpgen_iqopt3_bin_err,2.));
  //     double tc19_5_rel_data_alpgen_iqopt3_err = tc19_5_abs_data_alpgen_iqopt3_err/(tc19_5_data_bin_n-tc19_5_alpgen_iqopt3_bin_n);
  //     double tc19_5_rel_alpgen_iqopt3_err = tc19_5_alpgen_iqopt3_bin_err/tc19_5_alpgen_iqopt3_bin_n;
      
  //     double tc19_5_rel_ratio_data_alpgen_iqopt3_lep_eta_err = sqrt(pow(tc19_5_rel_data_alpgen_iqopt3_err,2.)+pow(tc19_5_rel_alpgen_iqopt3_err,2.));

  //     double tc19_5_data_alpgen_iqopt3_ratio = (tc19_5_data_bin_n-tc19_5_alpgen_iqopt3_bin_n)/tc19_5_alpgen_iqopt3_bin_n;

  //     double tc19_5_data_alpgen_iqopt3_ratio_err = fabs(tc19_5_rel_ratio_data_alpgen_iqopt3_lep_eta_err*tc19_5_data_alpgen_iqopt3_ratio);

  //     h_ratio_data_alpgen_iqopt3_lep_eta->SetBinContent(b,tc19_5_data_alpgen_iqopt3_ratio);
  //     h_ratio_data_alpgen_iqopt3_lep_eta->SetBinError(b,tc19_5_data_alpgen_iqopt3_ratio_err);
  //   }
    
  //   if(tc19_5_data_bin_n && tc19_5_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc19_5_abs_data_alpgen_ptjmin10_err = sqrt(pow(tc19_5_data_bin_err,2.)+pow(tc19_5_alpgen_ptjmin10_bin_err,2.));
  //     double tc19_5_rel_data_alpgen_ptjmin10_err = tc19_5_abs_data_alpgen_ptjmin10_err/(tc19_5_data_bin_n-tc19_5_alpgen_ptjmin10_bin_n);
  //     double tc19_5_rel_alpgen_ptjmin10_err = tc19_5_alpgen_ptjmin10_bin_err/tc19_5_alpgen_ptjmin10_bin_n;
      
  //     double tc19_5_rel_ratio_data_alpgen_ptjmin10_lep_eta_err = sqrt(pow(tc19_5_rel_data_alpgen_ptjmin10_err,2.)+pow(tc19_5_rel_alpgen_ptjmin10_err,2.));

  //     double tc19_5_data_alpgen_ptjmin10_ratio = (tc19_5_data_bin_n-tc19_5_alpgen_ptjmin10_bin_n)/tc19_5_alpgen_ptjmin10_bin_n;

  //     double tc19_5_data_alpgen_ptjmin10_ratio_err = fabs(tc19_5_rel_ratio_data_alpgen_ptjmin10_lep_eta_err*tc19_5_data_alpgen_ptjmin10_ratio);

  //     h_ratio_data_alpgen_ptjmin10_lep_eta->SetBinContent(b,tc19_5_data_alpgen_ptjmin10_ratio);
  //     h_ratio_data_alpgen_ptjmin10_lep_eta->SetBinError(b,tc19_5_data_alpgen_ptjmin10_ratio_err);
  //   }
  // }


  // h_ratio_data_alpgen_lep_eta->Draw("PE");
  // h_ratio_data_sherpa_lep_eta->Draw("PE sames");
  // h_ratio_data_alpgen_iqopt3_lep_eta->Draw("PE sames");
  // h_ratio_data_alpgen_ptjmin10_lep_eta->Draw("PE sames");
  
  // //  h_ratio_alpgen_iqopt3_lep_eta->Draw("PE sames");
  // //  h_ratio_alpgen_ptjmin10_lep_eta->Draw("PE sames");
  
  // tc19_5->Update();
  // tc19_5->SaveAs("./plots/latest/data_elec_lep_eta.png");
    
  // //NEXT

  // ////////////////////////////////////////////////// 
  // // tc20
  // // muon_lep_eta: tc20_sherpa/alpgen+wjrw
  // ////////////////////////////////////////////////// 

  // string tc20_title = "Eta(muon) (muon)";
  // string tc20_name = "tc20";
  // TCanvas* tc20 = new TCanvas(tc20_name.c_str(),tc20_title.c_str(),0,0,1920,1200);
  // tc20->cd();

  // TPad* tc20_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc20_pad01->SetTopMargin(0.05);
  // tc20_pad01->SetBottomMargin(0.31);
  // tc20_pad01->Draw();

  // TPad* tc20_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc20_pad02->SetBottomMargin(0.0005);
  // //tc20_pad02->SetLogy();
  // tc20_pad02->Draw();
  // tc20_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_muon_lep_eta = (TH1F*) wjets_alpgen_file->Get("all/h_muon_purw_nom_lep_eta");
  // TH1F* h_alpgen_iqopt3_muon_lep_eta = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_iqopt3_lep_eta");
  // TH1F* h_alpgen_ptjmin10_muon_lep_eta = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_ptjmin10_lep_eta");
  // TH1F* h_sherpa_nom_muon_lep_eta = (TH1F*) wjets_sherpa_file->Get("all/h_muon_purw_nom_lep_eta");

  // //h_alpgen_nom_muon_lep_eta->SetLineWidth(2);
  // h_alpgen_nom_muon_lep_eta->SetMarkerStyle(20);
  // h_alpgen_nom_muon_lep_eta->SetMarkerSize(1.2);
  // h_alpgen_nom_muon_lep_eta->SetTitle("");
  // h_alpgen_nom_muon_lep_eta->Draw("PE");

  // //h_alpgen_iqopt3_muon_lep_eta->SetLineColor(kGreen);
  // h_alpgen_iqopt3_muon_lep_eta->SetMarkerStyle(22);
  // h_alpgen_iqopt3_muon_lep_eta->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_muon_lep_eta->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_muon_lep_eta->Draw("PE sames");

  // //  h_alpgen_ptjmin10_muon_lep_eta->SetLineColor(kBlue);
  // h_alpgen_ptjmin10_muon_lep_eta->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_muon_lep_eta->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_muon_lep_eta->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_muon_lep_eta->Draw("PE sames");

  // // h_sherpa_nom_muon_lep_eta->SetLineWidth(1.2);
  // // h_sherpa_nom_muon_lep_eta->SetLineColor(kRed);
  // h_sherpa_nom_muon_lep_eta->SetMarkerStyle(20);
  // h_sherpa_nom_muon_lep_eta->SetMarkerSize(1.2);
  // h_sherpa_nom_muon_lep_eta->SetMarkerColor(kRed);
  // h_sherpa_nom_muon_lep_eta->Draw("PE sames");


  // //Legend
  // TLegend* lgnd_tc20 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc20->SetFillColor(0);
  // lgnd_tc20->SetTextSize(0.03);
  // lgnd_tc20->SetBorderSize(0);

  // char lgnd_alpgen_nom_muon_lep_eta_name[20];
  // sprintf(lgnd_alpgen_nom_muon_lep_eta_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_muon_lep_eta->Integral());
  // lgnd_tc20->AddEntry(h_alpgen_nom_muon_lep_eta,lgnd_alpgen_nom_muon_lep_eta_name,"p");

  // char lgnd_alpgen_iqopt3_muon_lep_eta_name[20];
  // sprintf(lgnd_alpgen_iqopt3_muon_lep_eta_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_muon_lep_eta->Integral());
  // lgnd_tc20->AddEntry(h_alpgen_iqopt3_muon_lep_eta,lgnd_alpgen_iqopt3_muon_lep_eta_name,"p");

  // char lgnd_alpgen_ptjmin10_muon_lep_eta_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_muon_lep_eta_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_muon_lep_eta->Integral());
  // lgnd_tc20->AddEntry(h_alpgen_ptjmin10_muon_lep_eta,lgnd_alpgen_ptjmin10_muon_lep_eta_name,"p");

  // char lgnd_sherpa_nom_muon_lep_eta_name[20];
  // sprintf(lgnd_sherpa_nom_muon_lep_eta_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_muon_lep_eta->Integral());
  // lgnd_tc20->AddEntry(h_sherpa_nom_muon_lep_eta,lgnd_sherpa_nom_muon_lep_eta_name,"p");

  // lgnd_tc20->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc20_pad01->cd();
  // tc20_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_muon_lep_eta->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_muon_lep_eta->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_muon_lep_eta->GetXaxis())->GetXmax();

  // // alp-sherp/sherp
  // string tc20_ratio_alpgen_sherpa_lep_eta_name = "tc20_ratio_alpgen_sherpa_lep_eta";
  // TH1F* h_ratio_alpgen_sherpa_lep_eta = new TH1F(tc20_ratio_alpgen_sherpa_lep_eta_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_sherpa_lep_eta->SetMarkerStyle(8);
  // h_ratio_alpgen_sherpa_lep_eta->SetMarkerColor(kRed);

  // TAxis* h_ratio_alpgen_sherpa_lep_eta_xaxis = h_ratio_alpgen_sherpa_lep_eta->GetXaxis();
  // TAxis* h_ratio_alpgen_sherpa_lep_eta_yaxis = h_ratio_alpgen_sherpa_lep_eta->GetYaxis();
  
  // h_ratio_alpgen_sherpa_lep_eta_xaxis->SetLabelSize(0.08);
  // h_ratio_alpgen_sherpa_lep_eta_yaxis->SetLabelSize(0.08);

  // h_ratio_alpgen_sherpa_lep_eta_xaxis->SetTitle("Eta(muon)");
  // h_ratio_alpgen_sherpa_lep_eta_xaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_lep_eta_yaxis->SetNdivisions(4,4,4);
  // h_ratio_alpgen_sherpa_lep_eta_yaxis->SetTitle("(alpgen-MC)/MC");
  // h_ratio_alpgen_sherpa_lep_eta_yaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_lep_eta_yaxis->SetTitleOffset(0.36);
  // h_ratio_alpgen_sherpa_lep_eta_yaxis->SetRangeUser(-1,1);

  
  // // alp-iqopt3/iqopt3
  // string tc20_ratio_alpgen_iqopt3_lep_eta_name = "tc20_ratio_alpgen_iqopt3_lep_eta";
  // TH1F* h_ratio_alpgen_iqopt3_lep_eta = new TH1F(tc20_ratio_alpgen_iqopt3_lep_eta_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_iqopt3_lep_eta->SetMarkerStyle(8);
  // h_ratio_alpgen_iqopt3_lep_eta->SetMarkerColor(kGreen);

  
  // // alp-ptjmin10/ptjmin10
  // string tc20_ratio_alpgen_ptjmin10_lep_eta_name = "tc20_ratio_alpgen_ptjmin10_lep_eta";
  // TH1F* h_ratio_alpgen_ptjmin10_lep_eta = new TH1F(tc20_ratio_alpgen_ptjmin10_lep_eta_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_ptjmin10_lep_eta->SetMarkerStyle(8);
  // h_ratio_alpgen_ptjmin10_lep_eta->SetMarkerColor(kBlue);


  
  // double tc20_alpgen_sherpa_ratio=0.;
  // double tc20_alpgen_iqopt3_ratio=0.;
  // double tc20_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc20_alpgen_nom_bin_n=h_alpgen_nom_muon_lep_eta->GetBinContent(b);
  //   double tc20_alpgen_nom_bin_err=h_alpgen_nom_muon_lep_eta->GetBinError(b);    

  //   double tc20_sherpa_nom_bin_n=h_sherpa_nom_muon_lep_eta->GetBinContent(b);
  //   double tc20_sherpa_nom_bin_err=h_sherpa_nom_muon_lep_eta->GetBinError(b);    

  //   double tc20_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_muon_lep_eta->GetBinContent(b);
  //   double tc20_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_muon_lep_eta->GetBinError(b);

  //   double tc20_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_muon_lep_eta->GetBinContent(b);
  //   double tc20_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_muon_lep_eta->GetBinError(b);



  //   if(tc20_alpgen_nom_bin_n && tc20_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc20_abs_alpgen_sherpa_err = sqrt(pow(tc20_alpgen_nom_bin_err,2.)+pow(tc20_sherpa_nom_bin_err,2.));
  //     double tc20_rel_alpgen_sherpa_err = tc20_abs_alpgen_sherpa_err/(tc20_alpgen_nom_bin_n-tc20_sherpa_nom_bin_n);
  //     double tc20_rel_sherpa_err = tc20_sherpa_nom_bin_err/tc20_sherpa_nom_bin_n;
      
  //     double tc20_rel_ratio_alpgen_sherpa_lep_eta_err = sqrt(pow(tc20_rel_alpgen_sherpa_err,2.)+pow(tc20_rel_sherpa_err,2.));

  //     double tc20_alpgen_sherpa_ratio = (tc20_alpgen_nom_bin_n-tc20_sherpa_nom_bin_n)/tc20_sherpa_nom_bin_n;

  //     double tc20_alpgen_sherpa_ratio_err = fabs(tc20_rel_ratio_alpgen_sherpa_lep_eta_err*tc20_alpgen_sherpa_ratio);

  //     h_ratio_alpgen_sherpa_lep_eta->SetBinContent(b,tc20_alpgen_sherpa_ratio);
  //     h_ratio_alpgen_sherpa_lep_eta->SetBinError(b,tc20_alpgen_sherpa_ratio_err);
  //   }
    

  //   if(tc20_alpgen_nom_bin_n && tc20_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc20_abs_alpgen_iqopt3_err = sqrt(pow(tc20_alpgen_nom_bin_err,2.)+pow(tc20_alpgen_iqopt3_bin_err,2.));
  //     double tc20_rel_alpgen_iqopt3_err = tc20_abs_alpgen_iqopt3_err/(tc20_alpgen_nom_bin_n-tc20_alpgen_iqopt3_bin_n);
  //     double tc20_rel_iqopt3_err = tc20_alpgen_iqopt3_bin_err/tc20_alpgen_iqopt3_bin_n;
      
  //     double tc20_rel_ratio_alpgen_iqopt3_lep_eta_err = sqrt(pow(tc20_rel_alpgen_iqopt3_err,2.)+pow(tc20_rel_iqopt3_err,2.));

  //     double tc20_alpgen_iqopt3_ratio = (tc20_alpgen_nom_bin_n-tc20_alpgen_iqopt3_bin_n)/tc20_alpgen_iqopt3_bin_n;

  //     double tc20_alpgen_iqopt3_ratio_err = fabs(tc20_rel_ratio_alpgen_iqopt3_lep_eta_err*tc20_alpgen_iqopt3_ratio);

  //     h_ratio_alpgen_iqopt3_lep_eta->SetBinContent(b,tc20_alpgen_iqopt3_ratio);
  //     h_ratio_alpgen_iqopt3_lep_eta->SetBinError(b,tc20_alpgen_iqopt3_ratio_err);
  //   }

    

  //   if(tc20_alpgen_nom_bin_n && tc20_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc20_abs_alpgen_ptjmin10_err = sqrt(pow(tc20_alpgen_nom_bin_err,2.)+pow(tc20_alpgen_ptjmin10_bin_err,2.));
  //     double tc20_rel_alpgen_ptjmin10_err = tc20_abs_alpgen_ptjmin10_err/(tc20_alpgen_nom_bin_n-tc20_alpgen_ptjmin10_bin_n);
  //     double tc20_rel_ptjmin10_err = tc20_alpgen_ptjmin10_bin_err/tc20_alpgen_ptjmin10_bin_n;
      
  //     double tc20_rel_ratio_alpgen_ptjmin10_lep_eta_err = sqrt(pow(tc20_rel_alpgen_ptjmin10_err,2.)+pow(tc20_rel_ptjmin10_err,2.));

  //     double tc20_alpgen_ptjmin10_ratio = (tc20_alpgen_nom_bin_n-tc20_alpgen_ptjmin10_bin_n)/tc20_alpgen_ptjmin10_bin_n;

  //     double tc20_alpgen_ptjmin10_ratio_err = fabs(tc20_rel_ratio_alpgen_ptjmin10_lep_eta_err*tc20_alpgen_ptjmin10_ratio);

  //     h_ratio_alpgen_ptjmin10_lep_eta->SetBinContent(b,tc20_alpgen_ptjmin10_ratio);
  //     h_ratio_alpgen_ptjmin10_lep_eta->SetBinError(b,tc20_alpgen_ptjmin10_ratio_err);
  //   }
    
  // }


  // h_ratio_alpgen_sherpa_lep_eta->Draw("PE");
  // h_ratio_alpgen_iqopt3_lep_eta->Draw("PE sames");
  // h_ratio_alpgen_ptjmin10_lep_eta->Draw("PE sames");
  
  // tc20->Update();

  // tc20->SaveAs("./plots/latest/muon_lep_eta.png");
  
  // //NEXT  

  // //////////////////////////////////////////////////
  // // tc20_5
  // // data_muon_lep_eta: sherpa/alpgen+wjrw
  // //////////////////////////////////////////////////
  
  // string tc20_5_title = "Eta(muon) (muon) w/ Data";
  // string tc20_5_name = "tc20_5";
  // TCanvas* tc20_5 = new TCanvas(tc20_5_name.c_str(),tc20_5_title.c_str(),0,0,1920,1200);
  // tc20_5->cd();

  // TPad* tc20_5_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc20_5_pad01->SetTopMargin(0.05);
  // tc20_5_pad01->SetBottomMargin(0.31);
  // tc20_5_pad01->Draw();

  // TPad* tc20_5_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc20_5_pad02->SetBottomMargin(0.0005);
  // //tc20_5_pad02->SetLogy();
  // tc20_5_pad02->Draw();
  // tc20_5_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_muon_lep_eta = (TH1F*) wjets_alpgen_file->Get("all/h_muon_purw_nom_lep_eta");
  // TH1F* h_alpgen_iqopt3_muon_lep_eta = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_iqopt3_lep_eta");
  // TH1F* h_alpgen_ptjmin10_muon_lep_eta = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_ptjmin10_lep_eta");
  // TH1F* h_sherpa_nom_muon_lep_eta = (TH1F*) wjets_sherpa_file->Get("all/h_muon_purw_nom_lep_eta");
  // TH1F* h_data_muon_lep_eta = (TH1F*) data_file->Get("all/h_muon_purw_nom_lep_eta");

  // TH1F* h_top_muon_lep_eta = (TH1F*) top_mcatnlo_file->Get("all/h_muon_purw_nom_lep_eta");
  // TH1F* h_zjets_muon_lep_eta = (TH1F*) zjets_alpgen_file->Get("all/h_muon_purw_nom_lep_eta");
  // TH1F* h_vv_muon_lep_eta = (TH1F*) vv_herwig_file->Get("all/h_muon_purw_nom_lep_eta");
  // TH1F* h_qcd_muon_lep_eta = (TH1F*) qcd_file->Get("all/h_muon_purw_nom_lep_eta");
  
  // h_data_muon_lep_eta->SetTitle("");
  // h_data_muon_lep_eta->Draw();
  
  // //Add Backgrounds
  // h_alpgen_nom_muon_lep_eta->Add(h_top_muon_lep_eta);
  // h_alpgen_nom_muon_lep_eta->Add(h_zjets_muon_lep_eta);
  // h_alpgen_nom_muon_lep_eta->Add(h_vv_muon_lep_eta);
  // h_alpgen_nom_muon_lep_eta->Add(h_qcd_muon_lep_eta);
  
  // h_alpgen_nom_muon_lep_eta->SetMarkerStyle(20);
  // h_alpgen_nom_muon_lep_eta->SetMarkerSize(1.2);
  // h_alpgen_nom_muon_lep_eta->Draw("PE sames");

  // //Add backgrounds
  // h_alpgen_iqopt3_muon_lep_eta->Add(h_top_muon_lep_eta);
  // h_alpgen_iqopt3_muon_lep_eta->Add(h_zjets_muon_lep_eta);
  // h_alpgen_iqopt3_muon_lep_eta->Add(h_vv_muon_lep_eta);
  // h_alpgen_iqopt3_muon_lep_eta->Add(h_qcd_muon_lep_eta);

  // h_alpgen_iqopt3_muon_lep_eta->SetMarkerStyle(22);
  // h_alpgen_iqopt3_muon_lep_eta->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_muon_lep_eta->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_muon_lep_eta->Draw("PE sames");

  // //Add Backgrounds
  // h_alpgen_ptjmin10_muon_lep_eta->Add(h_top_muon_lep_eta);
  // h_alpgen_ptjmin10_muon_lep_eta->Add(h_zjets_muon_lep_eta);
  // h_alpgen_ptjmin10_muon_lep_eta->Add(h_vv_muon_lep_eta);
  // h_alpgen_ptjmin10_muon_lep_eta->Add(h_qcd_muon_lep_eta);

  // h_alpgen_ptjmin10_muon_lep_eta->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_muon_lep_eta->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_muon_lep_eta->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_muon_lep_eta->Draw("PE sames");

  // //Add Backgrounds
  // h_sherpa_nom_muon_lep_eta->Add(h_top_muon_lep_eta);
  // h_sherpa_nom_muon_lep_eta->Add(h_zjets_muon_lep_eta);
  // h_sherpa_nom_muon_lep_eta->Add(h_vv_muon_lep_eta);
  // h_sherpa_nom_muon_lep_eta->Add(h_qcd_muon_lep_eta);

  // h_sherpa_nom_muon_lep_eta->SetMarkerStyle(20);
  // h_sherpa_nom_muon_lep_eta->SetMarkerSize(1.2);
  // h_sherpa_nom_muon_lep_eta->SetMarkerColor(kRed);
  // h_sherpa_nom_muon_lep_eta->Draw("PE sames");




  // //Legend
  // TLegend* lgnd_tc20_5 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc20_5->SetFillColor(0);
  // lgnd_tc20_5->SetTextSize(0.03);
  // lgnd_tc20_5->SetBorderSize(0);


  // char lgnd_data_muon_lep_eta_name[20];
  // sprintf(lgnd_data_muon_lep_eta_name,"%s,  %.2f","DATA",h_data_muon_lep_eta->Integral());
  // lgnd_tc20_5->AddEntry(h_data_muon_lep_eta,lgnd_data_muon_lep_eta_name,"f");

  // char lgnd_alpgen_nom_muon_lep_eta_name[20];
  // sprintf(lgnd_alpgen_nom_muon_lep_eta_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_muon_lep_eta->Integral());
  // lgnd_tc20_5->AddEntry(h_alpgen_nom_muon_lep_eta,lgnd_alpgen_nom_muon_lep_eta_name,"p");

  // char lgnd_alpgen_iqopt3_muon_lep_eta_name[20];
  // sprintf(lgnd_alpgen_iqopt3_muon_lep_eta_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_muon_lep_eta->Integral());
  // lgnd_tc20_5->AddEntry(h_alpgen_iqopt3_muon_lep_eta,lgnd_alpgen_iqopt3_muon_lep_eta_name,"p");

  // char lgnd_alpgen_ptjmin10_muon_lep_eta_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_muon_lep_eta_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_muon_lep_eta->Integral());
  // lgnd_tc20_5->AddEntry(h_alpgen_ptjmin10_muon_lep_eta,lgnd_alpgen_ptjmin10_muon_lep_eta_name,"p");

  // char lgnd_sherpa_nom_muon_lep_eta_name[20];
  // sprintf(lgnd_sherpa_nom_muon_lep_eta_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_muon_lep_eta->Integral());
  // lgnd_tc20_5->AddEntry(h_sherpa_nom_muon_lep_eta,lgnd_sherpa_nom_muon_lep_eta_name,"p");

  // lgnd_tc20_5->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc20_5_pad01->cd();
  // tc20_5_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_muon_lep_eta->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_muon_lep_eta->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_muon_lep_eta->GetXaxis())->GetXmax();

  // // data-alpgen(nom)/alpgen(nom)
  // string tc20_5_ratio_data_alpgen_lep_eta_name = "tc20_5_ratio_data_alpgen_lep_eta";
  // TH1F* h_ratio_data_alpgen_lep_eta = new TH1F(tc20_5_ratio_data_alpgen_lep_eta_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_lep_eta->SetMarkerStyle(8);
  // //h_ratio_data_alpgen_lep_eta->SetMarkerColor(kRed);

  // TAxis* h_ratio_data_alpgen_lep_eta_xaxis = h_ratio_data_alpgen_lep_eta->GetXaxis();
  // TAxis* h_ratio_data_alpgen_lep_eta_yaxis = h_ratio_data_alpgen_lep_eta->GetYaxis();
  
  // h_ratio_data_alpgen_lep_eta_xaxis->SetLabelSize(0.08);
  // h_ratio_data_alpgen_lep_eta_yaxis->SetLabelSize(0.08);

  // h_ratio_data_alpgen_lep_eta_xaxis->SetTitle("Eta(muon)");
  // h_ratio_data_alpgen_lep_eta_xaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_lep_eta_yaxis->SetNdivisions(4,4,4);
  // h_ratio_data_alpgen_lep_eta_yaxis->SetTitle("(data-MC)/MC");
  // h_ratio_data_alpgen_lep_eta_yaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_lep_eta_yaxis->SetTitleOffset(0.36);
  // h_ratio_data_alpgen_lep_eta_yaxis->SetRangeUser(-1,1);

  // // data-sherpa(nom)/sherpa(nom)
  // string tc20_5_ratio_data_sherpa_lep_eta_name = "tc20_5_ratio_data_sherpa_lep_eta";
  // TH1F* h_ratio_data_sherpa_lep_eta = new TH1F(tc20_5_ratio_data_sherpa_lep_eta_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_sherpa_lep_eta->SetMarkerStyle(8);
  // h_ratio_data_sherpa_lep_eta->SetMarkerColor(kRed);


  // // data-alpgen(iqopt3)/alpgen(iqopt3)
  // string tc20_5_ratio_data_alpgen_iqopt3_lep_eta_name = "tc20_5_ratio_data_alpgen_iqopt3_lep_eta";
  // TH1F* h_ratio_data_alpgen_iqopt3_lep_eta = new TH1F(tc20_5_ratio_data_alpgen_iqopt3_lep_eta_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_iqopt3_lep_eta->SetMarkerStyle(8);
  // h_ratio_data_alpgen_iqopt3_lep_eta->SetMarkerColor(kGreen);

  // // data-alpgen(ptjmin10)/alpgen(ptjmin10)
  // string tc20_5_ratio_data_alpgen_ptjmin10_lep_eta_name = "tc20_5_ratio_data_alpgen_ptjmin10_lep_eta";
  // TH1F* h_ratio_data_alpgen_ptjmin10_lep_eta = new TH1F(tc20_5_ratio_data_alpgen_ptjmin10_lep_eta_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_ptjmin10_lep_eta->SetMarkerStyle(8);
  // h_ratio_data_alpgen_ptjmin10_lep_eta->SetMarkerColor(kBlue);

  

  
  // // // alp-iqopt3/iqopt3
  // // string tc20_5_ratio_alpgen_iqopt3_lead_jet_pt_name = "tc20_5_ratio_alpgen_iqopt3_lead_jet_pt";
  // // TH1F* h_ratio_alpgen_iqopt3_lead_jet_pt = new TH1F(tc20_5_ratio_alpgen_iqopt3_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerStyle(8);
  // // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerColor(kGreen);

  
  // // // alp-ptjmin10/ptjmin10
  // // string tc20_5_ratio_alpgen_ptjmin10_lead_jet_pt_name = "tc20_5_ratio_alpgen_ptjmin10_lead_jet_pt";
  // // TH1F* h_ratio_alpgen_ptjmin10_lead_jet_pt = new TH1F(tc20_5_ratio_alpgen_ptjmin10_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerStyle(8);
  // // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerColor(kBlue);


  
  // double tc20_5_data_alpgen_ratio=0.;
  // double tc20_5_data_sherpa_ratio=0.;
  // double tc20_5_data_alpgen_iqopt3_ratio=0.;
  // double tc20_5_data_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc20_5_alpgen_nom_bin_n=h_alpgen_nom_muon_lep_eta->GetBinContent(b);
  //   double tc20_5_alpgen_nom_bin_err=h_alpgen_nom_muon_lep_eta->GetBinError(b);    

  //   double tc20_5_data_bin_n=h_data_muon_lep_eta->GetBinContent(b);
  //   double tc20_5_data_bin_err=h_data_muon_lep_eta->GetBinError(b);    

  //   double tc20_5_sherpa_nom_bin_n=h_sherpa_nom_muon_lep_eta->GetBinContent(b);
  //   double tc20_5_sherpa_nom_bin_err=h_sherpa_nom_muon_lep_eta->GetBinError(b);    

  //   double tc20_5_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_muon_lep_eta->GetBinContent(b);
  //   double tc20_5_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_muon_lep_eta->GetBinError(b);

  //   double tc20_5_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_muon_lep_eta->GetBinContent(b);
  //   double tc20_5_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_muon_lep_eta->GetBinError(b);



  //   if(tc20_5_data_bin_n && tc20_5_alpgen_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc20_5_abs_data_alpgen_err = sqrt(pow(tc20_5_data_bin_err,2.)+pow(tc20_5_alpgen_nom_bin_err,2.));
  //     double tc20_5_rel_data_alpgen_err = tc20_5_abs_data_alpgen_err/(tc20_5_data_bin_n-tc20_5_alpgen_nom_bin_n);
  //     double tc20_5_rel_alpgen_err = tc20_5_alpgen_nom_bin_err/tc20_5_alpgen_nom_bin_n;
      
  //     double tc20_5_rel_ratio_data_alpgen_lep_eta_err = sqrt(pow(tc20_5_rel_data_alpgen_err,2.)+pow(tc20_5_rel_alpgen_err,2.));

  //     double tc20_5_data_alpgen_ratio = (tc20_5_data_bin_n-tc20_5_alpgen_nom_bin_n)/tc20_5_alpgen_nom_bin_n;

  //     double tc20_5_data_alpgen_ratio_err = fabs(tc20_5_rel_ratio_data_alpgen_lep_eta_err*tc20_5_data_alpgen_ratio);

  //     h_ratio_data_alpgen_lep_eta->SetBinContent(b,tc20_5_data_alpgen_ratio);
  //     h_ratio_data_alpgen_lep_eta->SetBinError(b,tc20_5_data_alpgen_ratio_err);
  //   }
    

  //   if(tc20_5_data_bin_n && tc20_5_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc20_5_abs_data_sherpa_err = sqrt(pow(tc20_5_data_bin_err,2.)+pow(tc20_5_sherpa_nom_bin_err,2.));
  //     double tc20_5_rel_data_sherpa_err = tc20_5_abs_data_sherpa_err/(tc20_5_data_bin_n-tc20_5_sherpa_nom_bin_n);
  //     double tc20_5_rel_sherpa_err = tc20_5_sherpa_nom_bin_err/tc20_5_sherpa_nom_bin_n;
      
  //     double tc20_5_rel_ratio_data_sherpa_lep_eta_err = sqrt(pow(tc20_5_rel_data_sherpa_err,2.)+pow(tc20_5_rel_sherpa_err,2.));

  //     double tc20_5_data_sherpa_ratio = (tc20_5_data_bin_n-tc20_5_sherpa_nom_bin_n)/tc20_5_sherpa_nom_bin_n;

  //     double tc20_5_data_sherpa_ratio_err = fabs(tc20_5_rel_ratio_data_sherpa_lep_eta_err*tc20_5_data_sherpa_ratio);

  //     h_ratio_data_sherpa_lep_eta->SetBinContent(b,tc20_5_data_sherpa_ratio);
  //     h_ratio_data_sherpa_lep_eta->SetBinError(b,tc20_5_data_sherpa_ratio_err);
  //   }
    

  //   if(tc20_5_data_bin_n && tc20_5_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc20_5_abs_data_alpgen_iqopt3_err = sqrt(pow(tc20_5_data_bin_err,2.)+pow(tc20_5_alpgen_iqopt3_bin_err,2.));
  //     double tc20_5_rel_data_alpgen_iqopt3_err = tc20_5_abs_data_alpgen_iqopt3_err/(tc20_5_data_bin_n-tc20_5_alpgen_iqopt3_bin_n);
  //     double tc20_5_rel_alpgen_iqopt3_err = tc20_5_alpgen_iqopt3_bin_err/tc20_5_alpgen_iqopt3_bin_n;
      
  //     double tc20_5_rel_ratio_data_alpgen_iqopt3_lep_eta_err = sqrt(pow(tc20_5_rel_data_alpgen_iqopt3_err,2.)+pow(tc20_5_rel_alpgen_iqopt3_err,2.));

  //     double tc20_5_data_alpgen_iqopt3_ratio = (tc20_5_data_bin_n-tc20_5_alpgen_iqopt3_bin_n)/tc20_5_alpgen_iqopt3_bin_n;

  //     double tc20_5_data_alpgen_iqopt3_ratio_err = fabs(tc20_5_rel_ratio_data_alpgen_iqopt3_lep_eta_err*tc20_5_data_alpgen_iqopt3_ratio);

  //     h_ratio_data_alpgen_iqopt3_lep_eta->SetBinContent(b,tc20_5_data_alpgen_iqopt3_ratio);
  //     h_ratio_data_alpgen_iqopt3_lep_eta->SetBinError(b,tc20_5_data_alpgen_iqopt3_ratio_err);
  //   }
    
  //   if(tc20_5_data_bin_n && tc20_5_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc20_5_abs_data_alpgen_ptjmin10_err = sqrt(pow(tc20_5_data_bin_err,2.)+pow(tc20_5_alpgen_ptjmin10_bin_err,2.));
  //     double tc20_5_rel_data_alpgen_ptjmin10_err = tc20_5_abs_data_alpgen_ptjmin10_err/(tc20_5_data_bin_n-tc20_5_alpgen_ptjmin10_bin_n);
  //     double tc20_5_rel_alpgen_ptjmin10_err = tc20_5_alpgen_ptjmin10_bin_err/tc20_5_alpgen_ptjmin10_bin_n;
      
  //     double tc20_5_rel_ratio_data_alpgen_ptjmin10_lep_eta_err = sqrt(pow(tc20_5_rel_data_alpgen_ptjmin10_err,2.)+pow(tc20_5_rel_alpgen_ptjmin10_err,2.));

  //     double tc20_5_data_alpgen_ptjmin10_ratio = (tc20_5_data_bin_n-tc20_5_alpgen_ptjmin10_bin_n)/tc20_5_alpgen_ptjmin10_bin_n;

  //     double tc20_5_data_alpgen_ptjmin10_ratio_err = fabs(tc20_5_rel_ratio_data_alpgen_ptjmin10_lep_eta_err*tc20_5_data_alpgen_ptjmin10_ratio);

  //     h_ratio_data_alpgen_ptjmin10_lep_eta->SetBinContent(b,tc20_5_data_alpgen_ptjmin10_ratio);
  //     h_ratio_data_alpgen_ptjmin10_lep_eta->SetBinError(b,tc20_5_data_alpgen_ptjmin10_ratio_err);
  //   }
  // }


  // h_ratio_data_alpgen_lep_eta->Draw("PE");
  // h_ratio_data_sherpa_lep_eta->Draw("PE sames");
  // h_ratio_data_alpgen_iqopt3_lep_eta->Draw("PE sames");
  // h_ratio_data_alpgen_ptjmin10_lep_eta->Draw("PE sames");
  
  // //  h_ratio_alpgen_iqopt3_lep_eta->Draw("PE sames");
  // //  h_ratio_alpgen_ptjmin10_lep_eta->Draw("PE sames");
  
  // tc20_5->Update();
  // tc20_5->SaveAs("./plots/latest/data_muon_lep_eta.png");
    


  // //NEXT
  
  // ////////////////////////////////////////////////// 
  // // tc21
  // // elec_ww_met_et: tc21_sherpa/alpgen+wjrw
  // ////////////////////////////////////////////////// 

  // string tc21_title = "MET (elec)";
  // string tc21_name = "tc21";
  // TCanvas* tc21 = new TCanvas(tc21_name.c_str(),tc21_title.c_str(),0,0,1920,1200);
  // tc21->cd();

  // TPad* tc21_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc21_pad01->SetTopMargin(0.05);
  // tc21_pad01->SetBottomMargin(0.31);
  // tc21_pad01->Draw();

  // TPad* tc21_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc21_pad02->SetBottomMargin(0.0005);
  // tc21_pad02->SetLogy();
  // tc21_pad02->Draw();
  // tc21_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_elec_ww_met_et = (TH1F*) wjets_alpgen_file->Get("all/h_elec_purw_nom_ww_met_et");
  // TH1F* h_alpgen_iqopt3_elec_ww_met_et = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_iqopt3_ww_met_et");
  // TH1F* h_alpgen_ptjmin10_elec_ww_met_et = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_ptjmin10_ww_met_et");
  // TH1F* h_sherpa_nom_elec_ww_met_et = (TH1F*) wjets_sherpa_file->Get("all/h_elec_purw_nom_ww_met_et");

  // //h_alpgen_nom_elec_ww_met_et->SetLineWidth(2);
  // h_alpgen_nom_elec_ww_met_et->SetMarkerStyle(20);
  // h_alpgen_nom_elec_ww_met_et->SetMarkerSize(1.2);
  // h_alpgen_nom_elec_ww_met_et->SetTitle("");
  // h_alpgen_nom_elec_ww_met_et->Draw("PE");

  // //h_alpgen_iqopt3_elec_ww_met_et->SetLineColor(kGreen);
  // h_alpgen_iqopt3_elec_ww_met_et->SetMarkerStyle(22);
  // h_alpgen_iqopt3_elec_ww_met_et->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_elec_ww_met_et->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_elec_ww_met_et->Draw("PE sames");

  // //  h_alpgen_ptjmin10_elec_ww_met_et->SetLineColor(kBlue);
  // h_alpgen_ptjmin10_elec_ww_met_et->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_elec_ww_met_et->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_elec_ww_met_et->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_elec_ww_met_et->Draw("PE sames");

  // // h_sherpa_nom_elec_ww_met_et->SetLineWidth(1.2);
  // // h_sherpa_nom_elec_ww_met_et->SetLineColor(kRed);
  // h_sherpa_nom_elec_ww_met_et->SetMarkerStyle(20);
  // h_sherpa_nom_elec_ww_met_et->SetMarkerSize(1.2);
  // h_sherpa_nom_elec_ww_met_et->SetMarkerColor(kRed);
  // h_sherpa_nom_elec_ww_met_et->Draw("PE sames");


  // //Legend
  // TLegend* lgnd_tc21 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc21->SetFillColor(0);
  // lgnd_tc21->SetTextSize(0.03);
  // lgnd_tc21->SetBorderSize(0);

  // char lgnd_alpgen_nom_elec_ww_met_et_name[20];
  // sprintf(lgnd_alpgen_nom_elec_ww_met_et_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_elec_ww_met_et->Integral());
  // lgnd_tc21->AddEntry(h_alpgen_nom_elec_ww_met_et,lgnd_alpgen_nom_elec_ww_met_et_name,"p");

  // char lgnd_alpgen_iqopt3_elec_ww_met_et_name[20];
  // sprintf(lgnd_alpgen_iqopt3_elec_ww_met_et_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_elec_ww_met_et->Integral());
  // lgnd_tc21->AddEntry(h_alpgen_iqopt3_elec_ww_met_et,lgnd_alpgen_iqopt3_elec_ww_met_et_name,"p");

  // char lgnd_alpgen_ptjmin10_elec_ww_met_et_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_elec_ww_met_et_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_elec_ww_met_et->Integral());
  // lgnd_tc21->AddEntry(h_alpgen_ptjmin10_elec_ww_met_et,lgnd_alpgen_ptjmin10_elec_ww_met_et_name,"p");

  // char lgnd_sherpa_nom_elec_ww_met_et_name[20];
  // sprintf(lgnd_sherpa_nom_elec_ww_met_et_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_elec_ww_met_et->Integral());
  // lgnd_tc21->AddEntry(h_sherpa_nom_elec_ww_met_et,lgnd_sherpa_nom_elec_ww_met_et_name,"p");

  // lgnd_tc21->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc21_pad01->cd();
  // tc21_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_elec_ww_met_et->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_elec_ww_met_et->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_elec_ww_met_et->GetXaxis())->GetXmax();

  // // alp-sherp/sherp
  // string tc21_ratio_alpgen_sherpa_ww_met_et_name = "tc21_ratio_alpgen_sherpa_ww_met_et";
  // TH1F* h_ratio_alpgen_sherpa_ww_met_et = new TH1F(tc21_ratio_alpgen_sherpa_ww_met_et_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_sherpa_ww_met_et->SetMarkerStyle(8);
  // h_ratio_alpgen_sherpa_ww_met_et->SetMarkerColor(kRed);

  // TAxis* h_ratio_alpgen_sherpa_ww_met_et_xaxis = h_ratio_alpgen_sherpa_ww_met_et->GetXaxis();
  // TAxis* h_ratio_alpgen_sherpa_ww_met_et_yaxis = h_ratio_alpgen_sherpa_ww_met_et->GetYaxis();
  
  // h_ratio_alpgen_sherpa_ww_met_et_xaxis->SetLabelSize(0.08);
  // h_ratio_alpgen_sherpa_ww_met_et_yaxis->SetLabelSize(0.08);

  // h_ratio_alpgen_sherpa_ww_met_et_xaxis->SetTitle("MET");
  // h_ratio_alpgen_sherpa_ww_met_et_xaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_ww_met_et_yaxis->SetNdivisions(4,4,4);
  // h_ratio_alpgen_sherpa_ww_met_et_yaxis->SetTitle("(alpgen-MC)/MC");
  // h_ratio_alpgen_sherpa_ww_met_et_yaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_ww_met_et_yaxis->SetTitleOffset(0.36);
  // h_ratio_alpgen_sherpa_ww_met_et_yaxis->SetRangeUser(-1,1);

  
  // // alp-iqopt3/iqopt3
  // string tc21_ratio_alpgen_iqopt3_ww_met_et_name = "tc21_ratio_alpgen_iqopt3_ww_met_et";
  // TH1F* h_ratio_alpgen_iqopt3_ww_met_et = new TH1F(tc21_ratio_alpgen_iqopt3_ww_met_et_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_iqopt3_ww_met_et->SetMarkerStyle(8);
  // h_ratio_alpgen_iqopt3_ww_met_et->SetMarkerColor(kGreen);

  
  // // alp-ptjmin10/ptjmin10
  // string tc21_ratio_alpgen_ptjmin10_ww_met_et_name = "tc21_ratio_alpgen_ptjmin10_ww_met_et";
  // TH1F* h_ratio_alpgen_ptjmin10_ww_met_et = new TH1F(tc21_ratio_alpgen_ptjmin10_ww_met_et_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_ptjmin10_ww_met_et->SetMarkerStyle(8);
  // h_ratio_alpgen_ptjmin10_ww_met_et->SetMarkerColor(kBlue);


  
  // double tc21_alpgen_sherpa_ratio=0.;
  // double tc21_alpgen_iqopt3_ratio=0.;
  // double tc21_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc21_alpgen_nom_bin_n=h_alpgen_nom_elec_ww_met_et->GetBinContent(b);
  //   double tc21_alpgen_nom_bin_err=h_alpgen_nom_elec_ww_met_et->GetBinError(b);    

  //   double tc21_sherpa_nom_bin_n=h_sherpa_nom_elec_ww_met_et->GetBinContent(b);
  //   double tc21_sherpa_nom_bin_err=h_sherpa_nom_elec_ww_met_et->GetBinError(b);    

  //   double tc21_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_elec_ww_met_et->GetBinContent(b);
  //   double tc21_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_elec_ww_met_et->GetBinError(b);

  //   double tc21_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_elec_ww_met_et->GetBinContent(b);
  //   double tc21_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_elec_ww_met_et->GetBinError(b);



  //   if(tc21_alpgen_nom_bin_n && tc21_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc21_abs_alpgen_sherpa_err = sqrt(pow(tc21_alpgen_nom_bin_err,2.)+pow(tc21_sherpa_nom_bin_err,2.));
  //     double tc21_rel_alpgen_sherpa_err = tc21_abs_alpgen_sherpa_err/(tc21_alpgen_nom_bin_n-tc21_sherpa_nom_bin_n);
  //     double tc21_rel_sherpa_err = tc21_sherpa_nom_bin_err/tc21_sherpa_nom_bin_n;
      
  //     double tc21_rel_ratio_alpgen_sherpa_ww_met_et_err = sqrt(pow(tc21_rel_alpgen_sherpa_err,2.)+pow(tc21_rel_sherpa_err,2.));

  //     double tc21_alpgen_sherpa_ratio = (tc21_alpgen_nom_bin_n-tc21_sherpa_nom_bin_n)/tc21_sherpa_nom_bin_n;

  //     double tc21_alpgen_sherpa_ratio_err = fabs(tc21_rel_ratio_alpgen_sherpa_ww_met_et_err*tc21_alpgen_sherpa_ratio);

  //     h_ratio_alpgen_sherpa_ww_met_et->SetBinContent(b,tc21_alpgen_sherpa_ratio);
  //     h_ratio_alpgen_sherpa_ww_met_et->SetBinError(b,tc21_alpgen_sherpa_ratio_err);
  //   }
    

  //   if(tc21_alpgen_nom_bin_n && tc21_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc21_abs_alpgen_iqopt3_err = sqrt(pow(tc21_alpgen_nom_bin_err,2.)+pow(tc21_alpgen_iqopt3_bin_err,2.));
  //     double tc21_rel_alpgen_iqopt3_err = tc21_abs_alpgen_iqopt3_err/(tc21_alpgen_nom_bin_n-tc21_alpgen_iqopt3_bin_n);
  //     double tc21_rel_iqopt3_err = tc21_alpgen_iqopt3_bin_err/tc21_alpgen_iqopt3_bin_n;
      
  //     double tc21_rel_ratio_alpgen_iqopt3_ww_met_et_err = sqrt(pow(tc21_rel_alpgen_iqopt3_err,2.)+pow(tc21_rel_iqopt3_err,2.));

  //     double tc21_alpgen_iqopt3_ratio = (tc21_alpgen_nom_bin_n-tc21_alpgen_iqopt3_bin_n)/tc21_alpgen_iqopt3_bin_n;

  //     double tc21_alpgen_iqopt3_ratio_err = fabs(tc21_rel_ratio_alpgen_iqopt3_ww_met_et_err*tc21_alpgen_iqopt3_ratio);

  //     h_ratio_alpgen_iqopt3_ww_met_et->SetBinContent(b,tc21_alpgen_iqopt3_ratio);
  //     h_ratio_alpgen_iqopt3_ww_met_et->SetBinError(b,tc21_alpgen_iqopt3_ratio_err);
  //   }

    

  //   if(tc21_alpgen_nom_bin_n && tc21_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc21_abs_alpgen_ptjmin10_err = sqrt(pow(tc21_alpgen_nom_bin_err,2.)+pow(tc21_alpgen_ptjmin10_bin_err,2.));
  //     double tc21_rel_alpgen_ptjmin10_err = tc21_abs_alpgen_ptjmin10_err/(tc21_alpgen_nom_bin_n-tc21_alpgen_ptjmin10_bin_n);
  //     double tc21_rel_ptjmin10_err = tc21_alpgen_ptjmin10_bin_err/tc21_alpgen_ptjmin10_bin_n;
      
  //     double tc21_rel_ratio_alpgen_ptjmin10_ww_met_et_err = sqrt(pow(tc21_rel_alpgen_ptjmin10_err,2.)+pow(tc21_rel_ptjmin10_err,2.));

  //     double tc21_alpgen_ptjmin10_ratio = (tc21_alpgen_nom_bin_n-tc21_alpgen_ptjmin10_bin_n)/tc21_alpgen_ptjmin10_bin_n;

  //     double tc21_alpgen_ptjmin10_ratio_err = fabs(tc21_rel_ratio_alpgen_ptjmin10_ww_met_et_err*tc21_alpgen_ptjmin10_ratio);

  //     h_ratio_alpgen_ptjmin10_ww_met_et->SetBinContent(b,tc21_alpgen_ptjmin10_ratio);
  //     h_ratio_alpgen_ptjmin10_ww_met_et->SetBinError(b,tc21_alpgen_ptjmin10_ratio_err);
  //   }
    
  // }


  // h_ratio_alpgen_sherpa_ww_met_et->Draw("PE");
  // h_ratio_alpgen_iqopt3_ww_met_et->Draw("PE sames");
  // h_ratio_alpgen_ptjmin10_ww_met_et->Draw("PE sames");
  
  // tc21->Update();

  // tc21->SaveAs("./plots/latest/elec_ww_met_et.png");
  

  // //NEXT
  
  // //////////////////////////////////////////////////
  // // tc21_5
  // // data_elec_ww_met_et: sherpa/alpgen+wjrw
  // //////////////////////////////////////////////////
  
  // string tc21_5_title = "MET (elec) w/ Data";
  // string tc21_5_name = "tc21_5";
  // TCanvas* tc21_5 = new TCanvas(tc21_5_name.c_str(),tc21_5_title.c_str(),0,0,1920,1200);
  // tc21_5->cd();

  // TPad* tc21_5_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc21_5_pad01->SetTopMargin(0.05);
  // tc21_5_pad01->SetBottomMargin(0.31);
  // tc21_5_pad01->Draw();

  // TPad* tc21_5_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc21_5_pad02->SetBottomMargin(0.0005);
  // tc21_5_pad02->SetLogy();
  // tc21_5_pad02->Draw();
  // tc21_5_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_elec_ww_met_et = (TH1F*) wjets_alpgen_file->Get("all/h_elec_purw_nom_ww_met_et");
  // TH1F* h_alpgen_iqopt3_elec_ww_met_et = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_iqopt3_ww_met_et");
  // TH1F* h_alpgen_ptjmin10_elec_ww_met_et = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_ptjmin10_ww_met_et");
  // TH1F* h_sherpa_nom_elec_ww_met_et = (TH1F*) wjets_sherpa_file->Get("all/h_elec_purw_nom_ww_met_et");
  // TH1F* h_data_elec_ww_met_et = (TH1F*) data_file->Get("all/h_elec_purw_nom_ww_met_et");

  // TH1F* h_top_elec_ww_met_et = (TH1F*) top_mcatnlo_file->Get("all/h_elec_purw_nom_ww_met_et");
  // TH1F* h_zjets_elec_ww_met_et = (TH1F*) zjets_alpgen_file->Get("all/h_elec_purw_nom_ww_met_et");
  // TH1F* h_vv_elec_ww_met_et = (TH1F*) vv_herwig_file->Get("all/h_elec_purw_nom_ww_met_et");
  // TH1F* h_qcd_elec_ww_met_et = (TH1F*) qcd_file->Get("all/h_elec_purw_nom_ww_met_et");
  
  // h_data_elec_ww_met_et->SetTitle("");
  // h_data_elec_ww_met_et->Draw();
  
  // //Add Backgrounds
  // h_alpgen_nom_elec_ww_met_et->Add(h_top_elec_ww_met_et);
  // h_alpgen_nom_elec_ww_met_et->Add(h_zjets_elec_ww_met_et);
  // h_alpgen_nom_elec_ww_met_et->Add(h_vv_elec_ww_met_et);
  // h_alpgen_nom_elec_ww_met_et->Add(h_qcd_elec_ww_met_et);
  
  // h_alpgen_nom_elec_ww_met_et->SetMarkerStyle(20);
  // h_alpgen_nom_elec_ww_met_et->SetMarkerSize(1.2);
  // h_alpgen_nom_elec_ww_met_et->Draw("PE sames");

  // //Add backgrounds
  // h_alpgen_iqopt3_elec_ww_met_et->Add(h_top_elec_ww_met_et);
  // h_alpgen_iqopt3_elec_ww_met_et->Add(h_zjets_elec_ww_met_et);
  // h_alpgen_iqopt3_elec_ww_met_et->Add(h_vv_elec_ww_met_et);
  // h_alpgen_iqopt3_elec_ww_met_et->Add(h_qcd_elec_ww_met_et);

  // h_alpgen_iqopt3_elec_ww_met_et->SetMarkerStyle(22);
  // h_alpgen_iqopt3_elec_ww_met_et->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_elec_ww_met_et->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_elec_ww_met_et->Draw("PE sames");

  // //Add Backgrounds
  // h_alpgen_ptjmin10_elec_ww_met_et->Add(h_top_elec_ww_met_et);
  // h_alpgen_ptjmin10_elec_ww_met_et->Add(h_zjets_elec_ww_met_et);
  // h_alpgen_ptjmin10_elec_ww_met_et->Add(h_vv_elec_ww_met_et);
  // h_alpgen_ptjmin10_elec_ww_met_et->Add(h_qcd_elec_ww_met_et);

  // h_alpgen_ptjmin10_elec_ww_met_et->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_elec_ww_met_et->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_elec_ww_met_et->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_elec_ww_met_et->Draw("PE sames");

  // //Add Backgrounds
  // h_sherpa_nom_elec_ww_met_et->Add(h_top_elec_ww_met_et);
  // h_sherpa_nom_elec_ww_met_et->Add(h_zjets_elec_ww_met_et);
  // h_sherpa_nom_elec_ww_met_et->Add(h_vv_elec_ww_met_et);
  // h_sherpa_nom_elec_ww_met_et->Add(h_qcd_elec_ww_met_et);

  // h_sherpa_nom_elec_ww_met_et->SetMarkerStyle(20);
  // h_sherpa_nom_elec_ww_met_et->SetMarkerSize(1.2);
  // h_sherpa_nom_elec_ww_met_et->SetMarkerColor(kRed);
  // h_sherpa_nom_elec_ww_met_et->Draw("PE sames");




  // //Legend
  // TLegend* lgnd_tc21_5 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc21_5->SetFillColor(0);
  // lgnd_tc21_5->SetTextSize(0.03);
  // lgnd_tc21_5->SetBorderSize(0);


  // char lgnd_data_elec_ww_met_et_name[20];
  // sprintf(lgnd_data_elec_ww_met_et_name,"%s,  %.2f","DATA",h_data_elec_ww_met_et->Integral());
  // lgnd_tc21_5->AddEntry(h_data_elec_ww_met_et,lgnd_data_elec_ww_met_et_name,"f");

  // char lgnd_alpgen_nom_elec_ww_met_et_name[20];
  // sprintf(lgnd_alpgen_nom_elec_ww_met_et_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_elec_ww_met_et->Integral());
  // lgnd_tc21_5->AddEntry(h_alpgen_nom_elec_ww_met_et,lgnd_alpgen_nom_elec_ww_met_et_name,"p");

  // char lgnd_alpgen_iqopt3_elec_ww_met_et_name[20];
  // sprintf(lgnd_alpgen_iqopt3_elec_ww_met_et_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_elec_ww_met_et->Integral());
  // lgnd_tc21_5->AddEntry(h_alpgen_iqopt3_elec_ww_met_et,lgnd_alpgen_iqopt3_elec_ww_met_et_name,"p");

  // char lgnd_alpgen_ptjmin10_elec_ww_met_et_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_elec_ww_met_et_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_elec_ww_met_et->Integral());
  // lgnd_tc21_5->AddEntry(h_alpgen_ptjmin10_elec_ww_met_et,lgnd_alpgen_ptjmin10_elec_ww_met_et_name,"p");

  // char lgnd_sherpa_nom_elec_ww_met_et_name[20];
  // sprintf(lgnd_sherpa_nom_elec_ww_met_et_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_elec_ww_met_et->Integral());
  // lgnd_tc21_5->AddEntry(h_sherpa_nom_elec_ww_met_et,lgnd_sherpa_nom_elec_ww_met_et_name,"p");

  // lgnd_tc21_5->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc21_5_pad01->cd();
  // tc21_5_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_elec_ww_met_et->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_elec_ww_met_et->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_elec_ww_met_et->GetXaxis())->GetXmax();

  // // data-alpgen(nom)/alpgen(nom)
  // string tc21_5_ratio_data_alpgen_ww_met_et_name = "tc21_5_ratio_data_alpgen_ww_met_et";
  // TH1F* h_ratio_data_alpgen_ww_met_et = new TH1F(tc21_5_ratio_data_alpgen_ww_met_et_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_ww_met_et->SetMarkerStyle(8);
  // //h_ratio_data_alpgen_ww_met_et->SetMarkerColor(kRed);

  // TAxis* h_ratio_data_alpgen_ww_met_et_xaxis = h_ratio_data_alpgen_ww_met_et->GetXaxis();
  // TAxis* h_ratio_data_alpgen_ww_met_et_yaxis = h_ratio_data_alpgen_ww_met_et->GetYaxis();
  
  // h_ratio_data_alpgen_ww_met_et_xaxis->SetLabelSize(0.08);
  // h_ratio_data_alpgen_ww_met_et_yaxis->SetLabelSize(0.08);

  // h_ratio_data_alpgen_ww_met_et_xaxis->SetTitle("MET");
  // h_ratio_data_alpgen_ww_met_et_xaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_ww_met_et_yaxis->SetNdivisions(4,4,4);
  // h_ratio_data_alpgen_ww_met_et_yaxis->SetTitle("(data-MC)/MC");
  // h_ratio_data_alpgen_ww_met_et_yaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_ww_met_et_yaxis->SetTitleOffset(0.36);
  // h_ratio_data_alpgen_ww_met_et_yaxis->SetRangeUser(-1,1);

  // // data-sherpa(nom)/sherpa(nom)
  // string tc21_5_ratio_data_sherpa_ww_met_et_name = "tc21_5_ratio_data_sherpa_ww_met_et";
  // TH1F* h_ratio_data_sherpa_ww_met_et = new TH1F(tc21_5_ratio_data_sherpa_ww_met_et_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_sherpa_ww_met_et->SetMarkerStyle(8);
  // h_ratio_data_sherpa_ww_met_et->SetMarkerColor(kRed);


  // // data-alpgen(iqopt3)/alpgen(iqopt3)
  // string tc21_5_ratio_data_alpgen_iqopt3_ww_met_et_name = "tc21_5_ratio_data_alpgen_iqopt3_ww_met_et";
  // TH1F* h_ratio_data_alpgen_iqopt3_ww_met_et = new TH1F(tc21_5_ratio_data_alpgen_iqopt3_ww_met_et_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_iqopt3_ww_met_et->SetMarkerStyle(8);
  // h_ratio_data_alpgen_iqopt3_ww_met_et->SetMarkerColor(kGreen);

  // // data-alpgen(ptjmin10)/alpgen(ptjmin10)
  // string tc21_5_ratio_data_alpgen_ptjmin10_ww_met_et_name = "tc21_5_ratio_data_alpgen_ptjmin10_ww_met_et";
  // TH1F* h_ratio_data_alpgen_ptjmin10_ww_met_et = new TH1F(tc21_5_ratio_data_alpgen_ptjmin10_ww_met_et_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_ptjmin10_ww_met_et->SetMarkerStyle(8);
  // h_ratio_data_alpgen_ptjmin10_ww_met_et->SetMarkerColor(kBlue);

  

  
  // // // alp-iqopt3/iqopt3
  // // string tc21_5_ratio_alpgen_iqopt3_lead_jet_pt_name = "tc21_5_ratio_alpgen_iqopt3_lead_jet_pt";
  // // TH1F* h_ratio_alpgen_iqopt3_lead_jet_pt = new TH1F(tc21_5_ratio_alpgen_iqopt3_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerStyle(8);
  // // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerColor(kGreen);

  
  // // // alp-ptjmin10/ptjmin10
  // // string tc21_5_ratio_alpgen_ptjmin10_lead_jet_pt_name = "tc21_5_ratio_alpgen_ptjmin10_lead_jet_pt";
  // // TH1F* h_ratio_alpgen_ptjmin10_lead_jet_pt = new TH1F(tc21_5_ratio_alpgen_ptjmin10_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerStyle(8);
  // // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerColor(kBlue);


  
  // double tc21_5_data_alpgen_ratio=0.;
  // double tc21_5_data_sherpa_ratio=0.;
  // double tc21_5_data_alpgen_iqopt3_ratio=0.;
  // double tc21_5_data_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc21_5_alpgen_nom_bin_n=h_alpgen_nom_elec_ww_met_et->GetBinContent(b);
  //   double tc21_5_alpgen_nom_bin_err=h_alpgen_nom_elec_ww_met_et->GetBinError(b);    

  //   double tc21_5_data_bin_n=h_data_elec_ww_met_et->GetBinContent(b);
  //   double tc21_5_data_bin_err=h_data_elec_ww_met_et->GetBinError(b);    

  //   double tc21_5_sherpa_nom_bin_n=h_sherpa_nom_elec_ww_met_et->GetBinContent(b);
  //   double tc21_5_sherpa_nom_bin_err=h_sherpa_nom_elec_ww_met_et->GetBinError(b);    

  //   double tc21_5_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_elec_ww_met_et->GetBinContent(b);
  //   double tc21_5_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_elec_ww_met_et->GetBinError(b);

  //   double tc21_5_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_elec_ww_met_et->GetBinContent(b);
  //   double tc21_5_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_elec_ww_met_et->GetBinError(b);



  //   if(tc21_5_data_bin_n && tc21_5_alpgen_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc21_5_abs_data_alpgen_err = sqrt(pow(tc21_5_data_bin_err,2.)+pow(tc21_5_alpgen_nom_bin_err,2.));
  //     double tc21_5_rel_data_alpgen_err = tc21_5_abs_data_alpgen_err/(tc21_5_data_bin_n-tc21_5_alpgen_nom_bin_n);
  //     double tc21_5_rel_alpgen_err = tc21_5_alpgen_nom_bin_err/tc21_5_alpgen_nom_bin_n;
      
  //     double tc21_5_rel_ratio_data_alpgen_ww_met_et_err = sqrt(pow(tc21_5_rel_data_alpgen_err,2.)+pow(tc21_5_rel_alpgen_err,2.));

  //     double tc21_5_data_alpgen_ratio = (tc21_5_data_bin_n-tc21_5_alpgen_nom_bin_n)/tc21_5_alpgen_nom_bin_n;

  //     double tc21_5_data_alpgen_ratio_err = fabs(tc21_5_rel_ratio_data_alpgen_ww_met_et_err*tc21_5_data_alpgen_ratio);

  //     h_ratio_data_alpgen_ww_met_et->SetBinContent(b,tc21_5_data_alpgen_ratio);
  //     h_ratio_data_alpgen_ww_met_et->SetBinError(b,tc21_5_data_alpgen_ratio_err);
  //   }
    

  //   if(tc21_5_data_bin_n && tc21_5_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc21_5_abs_data_sherpa_err = sqrt(pow(tc21_5_data_bin_err,2.)+pow(tc21_5_sherpa_nom_bin_err,2.));
  //     double tc21_5_rel_data_sherpa_err = tc21_5_abs_data_sherpa_err/(tc21_5_data_bin_n-tc21_5_sherpa_nom_bin_n);
  //     double tc21_5_rel_sherpa_err = tc21_5_sherpa_nom_bin_err/tc21_5_sherpa_nom_bin_n;
      
  //     double tc21_5_rel_ratio_data_sherpa_ww_met_et_err = sqrt(pow(tc21_5_rel_data_sherpa_err,2.)+pow(tc21_5_rel_sherpa_err,2.));

  //     double tc21_5_data_sherpa_ratio = (tc21_5_data_bin_n-tc21_5_sherpa_nom_bin_n)/tc21_5_sherpa_nom_bin_n;

  //     double tc21_5_data_sherpa_ratio_err = fabs(tc21_5_rel_ratio_data_sherpa_ww_met_et_err*tc21_5_data_sherpa_ratio);

  //     h_ratio_data_sherpa_ww_met_et->SetBinContent(b,tc21_5_data_sherpa_ratio);
  //     h_ratio_data_sherpa_ww_met_et->SetBinError(b,tc21_5_data_sherpa_ratio_err);
  //   }
    

  //   if(tc21_5_data_bin_n && tc21_5_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc21_5_abs_data_alpgen_iqopt3_err = sqrt(pow(tc21_5_data_bin_err,2.)+pow(tc21_5_alpgen_iqopt3_bin_err,2.));
  //     double tc21_5_rel_data_alpgen_iqopt3_err = tc21_5_abs_data_alpgen_iqopt3_err/(tc21_5_data_bin_n-tc21_5_alpgen_iqopt3_bin_n);
  //     double tc21_5_rel_alpgen_iqopt3_err = tc21_5_alpgen_iqopt3_bin_err/tc21_5_alpgen_iqopt3_bin_n;
      
  //     double tc21_5_rel_ratio_data_alpgen_iqopt3_ww_met_et_err = sqrt(pow(tc21_5_rel_data_alpgen_iqopt3_err,2.)+pow(tc21_5_rel_alpgen_iqopt3_err,2.));

  //     double tc21_5_data_alpgen_iqopt3_ratio = (tc21_5_data_bin_n-tc21_5_alpgen_iqopt3_bin_n)/tc21_5_alpgen_iqopt3_bin_n;

  //     double tc21_5_data_alpgen_iqopt3_ratio_err = fabs(tc21_5_rel_ratio_data_alpgen_iqopt3_ww_met_et_err*tc21_5_data_alpgen_iqopt3_ratio);

  //     h_ratio_data_alpgen_iqopt3_ww_met_et->SetBinContent(b,tc21_5_data_alpgen_iqopt3_ratio);
  //     h_ratio_data_alpgen_iqopt3_ww_met_et->SetBinError(b,tc21_5_data_alpgen_iqopt3_ratio_err);
  //   }
    
  //   if(tc21_5_data_bin_n && tc21_5_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc21_5_abs_data_alpgen_ptjmin10_err = sqrt(pow(tc21_5_data_bin_err,2.)+pow(tc21_5_alpgen_ptjmin10_bin_err,2.));
  //     double tc21_5_rel_data_alpgen_ptjmin10_err = tc21_5_abs_data_alpgen_ptjmin10_err/(tc21_5_data_bin_n-tc21_5_alpgen_ptjmin10_bin_n);
  //     double tc21_5_rel_alpgen_ptjmin10_err = tc21_5_alpgen_ptjmin10_bin_err/tc21_5_alpgen_ptjmin10_bin_n;
      
  //     double tc21_5_rel_ratio_data_alpgen_ptjmin10_ww_met_et_err = sqrt(pow(tc21_5_rel_data_alpgen_ptjmin10_err,2.)+pow(tc21_5_rel_alpgen_ptjmin10_err,2.));

  //     double tc21_5_data_alpgen_ptjmin10_ratio = (tc21_5_data_bin_n-tc21_5_alpgen_ptjmin10_bin_n)/tc21_5_alpgen_ptjmin10_bin_n;

  //     double tc21_5_data_alpgen_ptjmin10_ratio_err = fabs(tc21_5_rel_ratio_data_alpgen_ptjmin10_ww_met_et_err*tc21_5_data_alpgen_ptjmin10_ratio);

  //     h_ratio_data_alpgen_ptjmin10_ww_met_et->SetBinContent(b,tc21_5_data_alpgen_ptjmin10_ratio);
  //     h_ratio_data_alpgen_ptjmin10_ww_met_et->SetBinError(b,tc21_5_data_alpgen_ptjmin10_ratio_err);
  //   }
  // }


  // h_ratio_data_alpgen_ww_met_et->Draw("PE");
  // h_ratio_data_sherpa_ww_met_et->Draw("PE sames");
  // h_ratio_data_alpgen_iqopt3_ww_met_et->Draw("PE sames");
  // h_ratio_data_alpgen_ptjmin10_ww_met_et->Draw("PE sames");
  
  // //  h_ratio_alpgen_iqopt3_ww_met_et->Draw("PE sames");
  // //  h_ratio_alpgen_ptjmin10_ww_met_et->Draw("PE sames");
  
  // tc21_5->Update();
  // tc21_5->SaveAs("./plots/latest/data_elec_ww_met_et.png");
    
  // //NEXT

  // ////////////////////////////////////////////////// 
  // // tc22
  // // muon_ww_met_et: tc22_sherpa/alpgen+wjrw
  // ////////////////////////////////////////////////// 

  // string tc22_title = "MET (muon)";
  // string tc22_name = "tc22";
  // TCanvas* tc22 = new TCanvas(tc22_name.c_str(),tc22_title.c_str(),0,0,1920,1200);
  // tc22->cd();

  // TPad* tc22_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc22_pad01->SetTopMargin(0.05);
  // tc22_pad01->SetBottomMargin(0.31);
  // tc22_pad01->Draw();

  // TPad* tc22_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc22_pad02->SetBottomMargin(0.0005);
  // tc22_pad02->SetLogy();
  // tc22_pad02->Draw();
  // tc22_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_muon_ww_met_et = (TH1F*) wjets_alpgen_file->Get("all/h_muon_purw_nom_ww_met_et");
  // TH1F* h_alpgen_iqopt3_muon_ww_met_et = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_iqopt3_ww_met_et");
  // TH1F* h_alpgen_ptjmin10_muon_ww_met_et = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_ptjmin10_ww_met_et");
  // TH1F* h_sherpa_nom_muon_ww_met_et = (TH1F*) wjets_sherpa_file->Get("all/h_muon_purw_nom_ww_met_et");

  // //h_alpgen_nom_muon_ww_met_et->SetLineWidth(2);
  // h_alpgen_nom_muon_ww_met_et->SetMarkerStyle(20);
  // h_alpgen_nom_muon_ww_met_et->SetMarkerSize(1.2);
  // h_alpgen_nom_muon_ww_met_et->SetTitle("");
  // h_alpgen_nom_muon_ww_met_et->Draw("PE");

  // //h_alpgen_iqopt3_muon_ww_met_et->SetLineColor(kGreen);
  // h_alpgen_iqopt3_muon_ww_met_et->SetMarkerStyle(22);
  // h_alpgen_iqopt3_muon_ww_met_et->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_muon_ww_met_et->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_muon_ww_met_et->Draw("PE sames");

  // //  h_alpgen_ptjmin10_muon_ww_met_et->SetLineColor(kBlue);
  // h_alpgen_ptjmin10_muon_ww_met_et->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_muon_ww_met_et->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_muon_ww_met_et->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_muon_ww_met_et->Draw("PE sames");

  // // h_sherpa_nom_muon_ww_met_et->SetLineWidth(1.2);
  // // h_sherpa_nom_muon_ww_met_et->SetLineColor(kRed);
  // h_sherpa_nom_muon_ww_met_et->SetMarkerStyle(20);
  // h_sherpa_nom_muon_ww_met_et->SetMarkerSize(1.2);
  // h_sherpa_nom_muon_ww_met_et->SetMarkerColor(kRed);
  // h_sherpa_nom_muon_ww_met_et->Draw("PE sames");


  // //Legend
  // TLegend* lgnd_tc22 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc22->SetFillColor(0);
  // lgnd_tc22->SetTextSize(0.03);
  // lgnd_tc22->SetBorderSize(0);

  // char lgnd_alpgen_nom_muon_ww_met_et_name[20];
  // sprintf(lgnd_alpgen_nom_muon_ww_met_et_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_muon_ww_met_et->Integral());
  // lgnd_tc22->AddEntry(h_alpgen_nom_muon_ww_met_et,lgnd_alpgen_nom_muon_ww_met_et_name,"p");

  // char lgnd_alpgen_iqopt3_muon_ww_met_et_name[20];
  // sprintf(lgnd_alpgen_iqopt3_muon_ww_met_et_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_muon_ww_met_et->Integral());
  // lgnd_tc22->AddEntry(h_alpgen_iqopt3_muon_ww_met_et,lgnd_alpgen_iqopt3_muon_ww_met_et_name,"p");

  // char lgnd_alpgen_ptjmin10_muon_ww_met_et_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_muon_ww_met_et_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_muon_ww_met_et->Integral());
  // lgnd_tc22->AddEntry(h_alpgen_ptjmin10_muon_ww_met_et,lgnd_alpgen_ptjmin10_muon_ww_met_et_name,"p");

  // char lgnd_sherpa_nom_muon_ww_met_et_name[20];
  // sprintf(lgnd_sherpa_nom_muon_ww_met_et_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_muon_ww_met_et->Integral());
  // lgnd_tc22->AddEntry(h_sherpa_nom_muon_ww_met_et,lgnd_sherpa_nom_muon_ww_met_et_name,"p");

  // lgnd_tc22->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc22_pad01->cd();
  // tc22_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_muon_ww_met_et->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_muon_ww_met_et->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_muon_ww_met_et->GetXaxis())->GetXmax();

  // // alp-sherp/sherp
  // string tc22_ratio_alpgen_sherpa_ww_met_et_name = "tc22_ratio_alpgen_sherpa_ww_met_et";
  // TH1F* h_ratio_alpgen_sherpa_ww_met_et = new TH1F(tc22_ratio_alpgen_sherpa_ww_met_et_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_sherpa_ww_met_et->SetMarkerStyle(8);
  // h_ratio_alpgen_sherpa_ww_met_et->SetMarkerColor(kRed);

  // TAxis* h_ratio_alpgen_sherpa_ww_met_et_xaxis = h_ratio_alpgen_sherpa_ww_met_et->GetXaxis();
  // TAxis* h_ratio_alpgen_sherpa_ww_met_et_yaxis = h_ratio_alpgen_sherpa_ww_met_et->GetYaxis();
  
  // h_ratio_alpgen_sherpa_ww_met_et_xaxis->SetLabelSize(0.08);
  // h_ratio_alpgen_sherpa_ww_met_et_yaxis->SetLabelSize(0.08);

  // h_ratio_alpgen_sherpa_ww_met_et_xaxis->SetTitle("MET");
  // h_ratio_alpgen_sherpa_ww_met_et_xaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_ww_met_et_yaxis->SetNdivisions(4,4,4);
  // h_ratio_alpgen_sherpa_ww_met_et_yaxis->SetTitle("(alpgen-MC)/MC");
  // h_ratio_alpgen_sherpa_ww_met_et_yaxis->SetTitleSize(0.07);
  // h_ratio_alpgen_sherpa_ww_met_et_yaxis->SetTitleOffset(0.36);
  // h_ratio_alpgen_sherpa_ww_met_et_yaxis->SetRangeUser(-1,1);

  
  // // alp-iqopt3/iqopt3
  // string tc22_ratio_alpgen_iqopt3_ww_met_et_name = "tc22_ratio_alpgen_iqopt3_ww_met_et";
  // TH1F* h_ratio_alpgen_iqopt3_ww_met_et = new TH1F(tc22_ratio_alpgen_iqopt3_ww_met_et_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_iqopt3_ww_met_et->SetMarkerStyle(8);
  // h_ratio_alpgen_iqopt3_ww_met_et->SetMarkerColor(kGreen);

  
  // // alp-ptjmin10/ptjmin10
  // string tc22_ratio_alpgen_ptjmin10_ww_met_et_name = "tc22_ratio_alpgen_ptjmin10_ww_met_et";
  // TH1F* h_ratio_alpgen_ptjmin10_ww_met_et = new TH1F(tc22_ratio_alpgen_ptjmin10_ww_met_et_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_ptjmin10_ww_met_et->SetMarkerStyle(8);
  // h_ratio_alpgen_ptjmin10_ww_met_et->SetMarkerColor(kBlue);


  
  // double tc22_alpgen_sherpa_ratio=0.;
  // double tc22_alpgen_iqopt3_ratio=0.;
  // double tc22_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc22_alpgen_nom_bin_n=h_alpgen_nom_muon_ww_met_et->GetBinContent(b);
  //   double tc22_alpgen_nom_bin_err=h_alpgen_nom_muon_ww_met_et->GetBinError(b);    

  //   double tc22_sherpa_nom_bin_n=h_sherpa_nom_muon_ww_met_et->GetBinContent(b);
  //   double tc22_sherpa_nom_bin_err=h_sherpa_nom_muon_ww_met_et->GetBinError(b);    

  //   double tc22_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_muon_ww_met_et->GetBinContent(b);
  //   double tc22_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_muon_ww_met_et->GetBinError(b);

  //   double tc22_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_muon_ww_met_et->GetBinContent(b);
  //   double tc22_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_muon_ww_met_et->GetBinError(b);



  //   if(tc22_alpgen_nom_bin_n && tc22_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc22_abs_alpgen_sherpa_err = sqrt(pow(tc22_alpgen_nom_bin_err,2.)+pow(tc22_sherpa_nom_bin_err,2.));
  //     double tc22_rel_alpgen_sherpa_err = tc22_abs_alpgen_sherpa_err/(tc22_alpgen_nom_bin_n-tc22_sherpa_nom_bin_n);
  //     double tc22_rel_sherpa_err = tc22_sherpa_nom_bin_err/tc22_sherpa_nom_bin_n;
      
  //     double tc22_rel_ratio_alpgen_sherpa_ww_met_et_err = sqrt(pow(tc22_rel_alpgen_sherpa_err,2.)+pow(tc22_rel_sherpa_err,2.));

  //     double tc22_alpgen_sherpa_ratio = (tc22_alpgen_nom_bin_n-tc22_sherpa_nom_bin_n)/tc22_sherpa_nom_bin_n;

  //     double tc22_alpgen_sherpa_ratio_err = fabs(tc22_rel_ratio_alpgen_sherpa_ww_met_et_err*tc22_alpgen_sherpa_ratio);

  //     h_ratio_alpgen_sherpa_ww_met_et->SetBinContent(b,tc22_alpgen_sherpa_ratio);
  //     h_ratio_alpgen_sherpa_ww_met_et->SetBinError(b,tc22_alpgen_sherpa_ratio_err);
  //   }
    

  //   if(tc22_alpgen_nom_bin_n && tc22_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc22_abs_alpgen_iqopt3_err = sqrt(pow(tc22_alpgen_nom_bin_err,2.)+pow(tc22_alpgen_iqopt3_bin_err,2.));
  //     double tc22_rel_alpgen_iqopt3_err = tc22_abs_alpgen_iqopt3_err/(tc22_alpgen_nom_bin_n-tc22_alpgen_iqopt3_bin_n);
  //     double tc22_rel_iqopt3_err = tc22_alpgen_iqopt3_bin_err/tc22_alpgen_iqopt3_bin_n;
      
  //     double tc22_rel_ratio_alpgen_iqopt3_ww_met_et_err = sqrt(pow(tc22_rel_alpgen_iqopt3_err,2.)+pow(tc22_rel_iqopt3_err,2.));

  //     double tc22_alpgen_iqopt3_ratio = (tc22_alpgen_nom_bin_n-tc22_alpgen_iqopt3_bin_n)/tc22_alpgen_iqopt3_bin_n;

  //     double tc22_alpgen_iqopt3_ratio_err = fabs(tc22_rel_ratio_alpgen_iqopt3_ww_met_et_err*tc22_alpgen_iqopt3_ratio);

  //     h_ratio_alpgen_iqopt3_ww_met_et->SetBinContent(b,tc22_alpgen_iqopt3_ratio);
  //     h_ratio_alpgen_iqopt3_ww_met_et->SetBinError(b,tc22_alpgen_iqopt3_ratio_err);
  //   }

    

  //   if(tc22_alpgen_nom_bin_n && tc22_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc22_abs_alpgen_ptjmin10_err = sqrt(pow(tc22_alpgen_nom_bin_err,2.)+pow(tc22_alpgen_ptjmin10_bin_err,2.));
  //     double tc22_rel_alpgen_ptjmin10_err = tc22_abs_alpgen_ptjmin10_err/(tc22_alpgen_nom_bin_n-tc22_alpgen_ptjmin10_bin_n);
  //     double tc22_rel_ptjmin10_err = tc22_alpgen_ptjmin10_bin_err/tc22_alpgen_ptjmin10_bin_n;
      
  //     double tc22_rel_ratio_alpgen_ptjmin10_ww_met_et_err = sqrt(pow(tc22_rel_alpgen_ptjmin10_err,2.)+pow(tc22_rel_ptjmin10_err,2.));

  //     double tc22_alpgen_ptjmin10_ratio = (tc22_alpgen_nom_bin_n-tc22_alpgen_ptjmin10_bin_n)/tc22_alpgen_ptjmin10_bin_n;

  //     double tc22_alpgen_ptjmin10_ratio_err = fabs(tc22_rel_ratio_alpgen_ptjmin10_ww_met_et_err*tc22_alpgen_ptjmin10_ratio);

  //     h_ratio_alpgen_ptjmin10_ww_met_et->SetBinContent(b,tc22_alpgen_ptjmin10_ratio);
  //     h_ratio_alpgen_ptjmin10_ww_met_et->SetBinError(b,tc22_alpgen_ptjmin10_ratio_err);
  //   }
    
  // }


  // h_ratio_alpgen_sherpa_ww_met_et->Draw("PE");
  // h_ratio_alpgen_iqopt3_ww_met_et->Draw("PE sames");
  // h_ratio_alpgen_ptjmin10_ww_met_et->Draw("PE sames");
  
  // tc22->Update();

  // tc22->SaveAs("./plots/latest/muon_ww_met_et.png");
  
  // //NEXT  

  // //////////////////////////////////////////////////
  // // tc22_5
  // // data_muon_ww_met_et: sherpa/alpgen+wjrw
  // //////////////////////////////////////////////////
  
  // string tc22_5_title = "MET (muon) w/ Data";
  // string tc22_5_name = "tc22_5";
  // TCanvas* tc22_5 = new TCanvas(tc22_5_name.c_str(),tc22_5_title.c_str(),0,0,1920,1200);
  // tc22_5->cd();

  // TPad* tc22_5_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  // tc22_5_pad01->SetTopMargin(0.05);
  // tc22_5_pad01->SetBottomMargin(0.31);
  // tc22_5_pad01->Draw();

  // TPad* tc22_5_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  // tc22_5_pad02->SetBottomMargin(0.0005);
  // tc22_5_pad02->SetLogy();
  // tc22_5_pad02->Draw();
  // tc22_5_pad02->cd();

  // // Plots
  
  // TH1F* h_alpgen_nom_muon_ww_met_et = (TH1F*) wjets_alpgen_file->Get("all/h_muon_purw_nom_ww_met_et");
  // TH1F* h_alpgen_iqopt3_muon_ww_met_et = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_iqopt3_ww_met_et");
  // TH1F* h_alpgen_ptjmin10_muon_ww_met_et = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_ptjmin10_ww_met_et");
  // TH1F* h_sherpa_nom_muon_ww_met_et = (TH1F*) wjets_sherpa_file->Get("all/h_muon_purw_nom_ww_met_et");
  // TH1F* h_data_muon_ww_met_et = (TH1F*) data_file->Get("all/h_muon_purw_nom_ww_met_et");

  // TH1F* h_top_muon_ww_met_et = (TH1F*) top_mcatnlo_file->Get("all/h_muon_purw_nom_ww_met_et");
  // TH1F* h_zjets_muon_ww_met_et = (TH1F*) zjets_alpgen_file->Get("all/h_muon_purw_nom_ww_met_et");
  // TH1F* h_vv_muon_ww_met_et = (TH1F*) vv_herwig_file->Get("all/h_muon_purw_nom_ww_met_et");
  // TH1F* h_qcd_muon_ww_met_et = (TH1F*) qcd_file->Get("all/h_muon_purw_nom_ww_met_et");
  
  // h_data_muon_ww_met_et->SetTitle("");
  // h_data_muon_ww_met_et->Draw();
  
  // //Add Backgrounds
  // h_alpgen_nom_muon_ww_met_et->Add(h_top_muon_ww_met_et);
  // h_alpgen_nom_muon_ww_met_et->Add(h_zjets_muon_ww_met_et);
  // h_alpgen_nom_muon_ww_met_et->Add(h_vv_muon_ww_met_et);
  // h_alpgen_nom_muon_ww_met_et->Add(h_qcd_muon_ww_met_et);
  
  // h_alpgen_nom_muon_ww_met_et->SetMarkerStyle(20);
  // h_alpgen_nom_muon_ww_met_et->SetMarkerSize(1.2);
  // h_alpgen_nom_muon_ww_met_et->Draw("PE sames");

  // //Add backgrounds
  // h_alpgen_iqopt3_muon_ww_met_et->Add(h_top_muon_ww_met_et);
  // h_alpgen_iqopt3_muon_ww_met_et->Add(h_zjets_muon_ww_met_et);
  // h_alpgen_iqopt3_muon_ww_met_et->Add(h_vv_muon_ww_met_et);
  // h_alpgen_iqopt3_muon_ww_met_et->Add(h_qcd_muon_ww_met_et);

  // h_alpgen_iqopt3_muon_ww_met_et->SetMarkerStyle(22);
  // h_alpgen_iqopt3_muon_ww_met_et->SetMarkerSize(1.2);
  // h_alpgen_iqopt3_muon_ww_met_et->SetMarkerColor(kGreen);
  // h_alpgen_iqopt3_muon_ww_met_et->Draw("PE sames");

  // //Add Backgrounds
  // h_alpgen_ptjmin10_muon_ww_met_et->Add(h_top_muon_ww_met_et);
  // h_alpgen_ptjmin10_muon_ww_met_et->Add(h_zjets_muon_ww_met_et);
  // h_alpgen_ptjmin10_muon_ww_met_et->Add(h_vv_muon_ww_met_et);
  // h_alpgen_ptjmin10_muon_ww_met_et->Add(h_qcd_muon_ww_met_et);

  // h_alpgen_ptjmin10_muon_ww_met_et->SetMarkerStyle(22);
  // h_alpgen_ptjmin10_muon_ww_met_et->SetMarkerSize(1.2);
  // h_alpgen_ptjmin10_muon_ww_met_et->SetMarkerColor(kBlue);
  // h_alpgen_ptjmin10_muon_ww_met_et->Draw("PE sames");

  // //Add Backgrounds
  // h_sherpa_nom_muon_ww_met_et->Add(h_top_muon_ww_met_et);
  // h_sherpa_nom_muon_ww_met_et->Add(h_zjets_muon_ww_met_et);
  // h_sherpa_nom_muon_ww_met_et->Add(h_vv_muon_ww_met_et);
  // h_sherpa_nom_muon_ww_met_et->Add(h_qcd_muon_ww_met_et);

  // h_sherpa_nom_muon_ww_met_et->SetMarkerStyle(20);
  // h_sherpa_nom_muon_ww_met_et->SetMarkerSize(1.2);
  // h_sherpa_nom_muon_ww_met_et->SetMarkerColor(kRed);
  // h_sherpa_nom_muon_ww_met_et->Draw("PE sames");




  // //Legend
  // TLegend* lgnd_tc22_5 = new TLegend(0.68,0.72,0.83,0.85);
  // lgnd_tc22_5->SetFillColor(0);
  // lgnd_tc22_5->SetTextSize(0.03);
  // lgnd_tc22_5->SetBorderSize(0);

  // char lgnd_data_muon_ww_met_et_name[20];
  // sprintf(lgnd_data_muon_ww_met_et_name,"%s,  %.2f","DATA",h_data_muon_ww_met_et->Integral());
  // lgnd_tc22_5->AddEntry(h_data_muon_ww_met_et,lgnd_data_muon_ww_met_et_name,"f");

  // char lgnd_alpgen_nom_muon_ww_met_et_name[20];
  // sprintf(lgnd_alpgen_nom_muon_ww_met_et_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_muon_ww_met_et->Integral());
  // lgnd_tc22_5->AddEntry(h_alpgen_nom_muon_ww_met_et,lgnd_alpgen_nom_muon_ww_met_et_name,"p");

  // char lgnd_alpgen_iqopt3_muon_ww_met_et_name[20];
  // sprintf(lgnd_alpgen_iqopt3_muon_ww_met_et_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_muon_ww_met_et->Integral());
  // lgnd_tc22_5->AddEntry(h_alpgen_iqopt3_muon_ww_met_et,lgnd_alpgen_iqopt3_muon_ww_met_et_name,"p");

  // char lgnd_alpgen_ptjmin10_muon_ww_met_et_name[20];
  // sprintf(lgnd_alpgen_ptjmin10_muon_ww_met_et_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_muon_ww_met_et->Integral());
  // lgnd_tc22_5->AddEntry(h_alpgen_ptjmin10_muon_ww_met_et,lgnd_alpgen_ptjmin10_muon_ww_met_et_name,"p");

  // char lgnd_sherpa_nom_muon_ww_met_et_name[20];
  // sprintf(lgnd_sherpa_nom_muon_ww_met_et_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_muon_ww_met_et->Integral());
  // lgnd_tc22_5->AddEntry(h_sherpa_nom_muon_ww_met_et,lgnd_sherpa_nom_muon_ww_met_et_name,"p");

  // lgnd_tc22_5->Draw();
  
  // //////////////////////////////////////////////////
  // //Ratio
  // ////////////////////////////////////////////////// 

  // tc22_5_pad01->cd();
  // tc22_5_pad01->SetGrid();

  // int n_bins = ((TAxis*) h_alpgen_nom_muon_ww_met_et->GetXaxis())->GetNbins();
  // double x_min = ((TAxis*) h_alpgen_nom_muon_ww_met_et->GetXaxis())->GetXmin();
  // double x_max = ((TAxis*) h_alpgen_nom_muon_ww_met_et->GetXaxis())->GetXmax();

  // // data-alpgen(nom)/alpgen(nom)
  // string tc22_5_ratio_data_alpgen_ww_met_et_name = "tc22_5_ratio_data_alpgen_ww_met_et";
  // TH1F* h_ratio_data_alpgen_ww_met_et = new TH1F(tc22_5_ratio_data_alpgen_ww_met_et_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_ww_met_et->SetMarkerStyle(8);
  // //h_ratio_data_alpgen_ww_met_et->SetMarkerColor(kRed);

  // TAxis* h_ratio_data_alpgen_ww_met_et_xaxis = h_ratio_data_alpgen_ww_met_et->GetXaxis();
  // TAxis* h_ratio_data_alpgen_ww_met_et_yaxis = h_ratio_data_alpgen_ww_met_et->GetYaxis();
  
  // h_ratio_data_alpgen_ww_met_et_xaxis->SetLabelSize(0.08);
  // h_ratio_data_alpgen_ww_met_et_yaxis->SetLabelSize(0.08);

  // h_ratio_data_alpgen_ww_met_et_xaxis->SetTitle("MET");
  // h_ratio_data_alpgen_ww_met_et_xaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_ww_met_et_yaxis->SetNdivisions(4,4,4);
  // h_ratio_data_alpgen_ww_met_et_yaxis->SetTitle("(data-MC)/MC");
  // h_ratio_data_alpgen_ww_met_et_yaxis->SetTitleSize(0.07);
  // h_ratio_data_alpgen_ww_met_et_yaxis->SetTitleOffset(0.36);
  // h_ratio_data_alpgen_ww_met_et_yaxis->SetRangeUser(-1,1);

  // // data-sherpa(nom)/sherpa(nom)
  // string tc22_5_ratio_data_sherpa_ww_met_et_name = "tc22_5_ratio_data_sherpa_ww_met_et";
  // TH1F* h_ratio_data_sherpa_ww_met_et = new TH1F(tc22_5_ratio_data_sherpa_ww_met_et_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_sherpa_ww_met_et->SetMarkerStyle(8);
  // h_ratio_data_sherpa_ww_met_et->SetMarkerColor(kRed);


  // // data-alpgen(iqopt3)/alpgen(iqopt3)
  // string tc22_5_ratio_data_alpgen_iqopt3_ww_met_et_name = "tc22_5_ratio_data_alpgen_iqopt3_ww_met_et";
  // TH1F* h_ratio_data_alpgen_iqopt3_ww_met_et = new TH1F(tc22_5_ratio_data_alpgen_iqopt3_ww_met_et_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_iqopt3_ww_met_et->SetMarkerStyle(8);
  // h_ratio_data_alpgen_iqopt3_ww_met_et->SetMarkerColor(kGreen);

  // // data-alpgen(ptjmin10)/alpgen(ptjmin10)
  // string tc22_5_ratio_data_alpgen_ptjmin10_ww_met_et_name = "tc22_5_ratio_data_alpgen_ptjmin10_ww_met_et";
  // TH1F* h_ratio_data_alpgen_ptjmin10_ww_met_et = new TH1F(tc22_5_ratio_data_alpgen_ptjmin10_ww_met_et_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_data_alpgen_ptjmin10_ww_met_et->SetMarkerStyle(8);
  // h_ratio_data_alpgen_ptjmin10_ww_met_et->SetMarkerColor(kBlue);

  

  
  // // // alp-iqopt3/iqopt3
  // // string tc22_5_ratio_alpgen_iqopt3_lead_jet_pt_name = "tc22_5_ratio_alpgen_iqopt3_lead_jet_pt";
  // // TH1F* h_ratio_alpgen_iqopt3_lead_jet_pt = new TH1F(tc22_5_ratio_alpgen_iqopt3_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerStyle(8);
  // // h_ratio_alpgen_iqopt3_lead_jet_pt->SetMarkerColor(kGreen);

  
  // // // alp-ptjmin10/ptjmin10
  // // string tc22_5_ratio_alpgen_ptjmin10_lead_jet_pt_name = "tc22_5_ratio_alpgen_ptjmin10_lead_jet_pt";
  // // TH1F* h_ratio_alpgen_ptjmin10_lead_jet_pt = new TH1F(tc22_5_ratio_alpgen_ptjmin10_lead_jet_pt_name.c_str(),"",n_bins,x_min,x_max);
  // // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerStyle(8);
  // // h_ratio_alpgen_ptjmin10_lead_jet_pt->SetMarkerColor(kBlue);


  
  // double tc22_5_data_alpgen_ratio=0.;
  // double tc22_5_data_sherpa_ratio=0.;
  // double tc22_5_data_alpgen_iqopt3_ratio=0.;
  // double tc22_5_data_alpgen_ptjmin10_ratio=0.;
  
  // for(int b=1;b<n_bins+1;b++){

  //   double tc22_5_alpgen_nom_bin_n=h_alpgen_nom_muon_ww_met_et->GetBinContent(b);
  //   double tc22_5_alpgen_nom_bin_err=h_alpgen_nom_muon_ww_met_et->GetBinError(b);    

  //   double tc22_5_data_bin_n=h_data_muon_ww_met_et->GetBinContent(b);
  //   double tc22_5_data_bin_err=h_data_muon_ww_met_et->GetBinError(b);    

  //   double tc22_5_sherpa_nom_bin_n=h_sherpa_nom_muon_ww_met_et->GetBinContent(b);
  //   double tc22_5_sherpa_nom_bin_err=h_sherpa_nom_muon_ww_met_et->GetBinError(b);    

  //   double tc22_5_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_muon_ww_met_et->GetBinContent(b);
  //   double tc22_5_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_muon_ww_met_et->GetBinError(b);

  //   double tc22_5_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_muon_ww_met_et->GetBinContent(b);
  //   double tc22_5_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_muon_ww_met_et->GetBinError(b);



  //   if(tc22_5_data_bin_n && tc22_5_alpgen_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc22_5_abs_data_alpgen_err = sqrt(pow(tc22_5_data_bin_err,2.)+pow(tc22_5_alpgen_nom_bin_err,2.));
  //     double tc22_5_rel_data_alpgen_err = tc22_5_abs_data_alpgen_err/(tc22_5_data_bin_n-tc22_5_alpgen_nom_bin_n);
  //     double tc22_5_rel_alpgen_err = tc22_5_alpgen_nom_bin_err/tc22_5_alpgen_nom_bin_n;
      
  //     double tc22_5_rel_ratio_data_alpgen_ww_met_et_err = sqrt(pow(tc22_5_rel_data_alpgen_err,2.)+pow(tc22_5_rel_alpgen_err,2.));

  //     double tc22_5_data_alpgen_ratio = (tc22_5_data_bin_n-tc22_5_alpgen_nom_bin_n)/tc22_5_alpgen_nom_bin_n;

  //     double tc22_5_data_alpgen_ratio_err = fabs(tc22_5_rel_ratio_data_alpgen_ww_met_et_err*tc22_5_data_alpgen_ratio);

  //     h_ratio_data_alpgen_ww_met_et->SetBinContent(b,tc22_5_data_alpgen_ratio);
  //     h_ratio_data_alpgen_ww_met_et->SetBinError(b,tc22_5_data_alpgen_ratio_err);
  //   }
    

  //   if(tc22_5_data_bin_n && tc22_5_sherpa_nom_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc22_5_abs_data_sherpa_err = sqrt(pow(tc22_5_data_bin_err,2.)+pow(tc22_5_sherpa_nom_bin_err,2.));
  //     double tc22_5_rel_data_sherpa_err = tc22_5_abs_data_sherpa_err/(tc22_5_data_bin_n-tc22_5_sherpa_nom_bin_n);
  //     double tc22_5_rel_sherpa_err = tc22_5_sherpa_nom_bin_err/tc22_5_sherpa_nom_bin_n;
      
  //     double tc22_5_rel_ratio_data_sherpa_ww_met_et_err = sqrt(pow(tc22_5_rel_data_sherpa_err,2.)+pow(tc22_5_rel_sherpa_err,2.));

  //     double tc22_5_data_sherpa_ratio = (tc22_5_data_bin_n-tc22_5_sherpa_nom_bin_n)/tc22_5_sherpa_nom_bin_n;

  //     double tc22_5_data_sherpa_ratio_err = fabs(tc22_5_rel_ratio_data_sherpa_ww_met_et_err*tc22_5_data_sherpa_ratio);

  //     h_ratio_data_sherpa_ww_met_et->SetBinContent(b,tc22_5_data_sherpa_ratio);
  //     h_ratio_data_sherpa_ww_met_et->SetBinError(b,tc22_5_data_sherpa_ratio_err);
  //   }
    

  //   if(tc22_5_data_bin_n && tc22_5_alpgen_iqopt3_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc22_5_abs_data_alpgen_iqopt3_err = sqrt(pow(tc22_5_data_bin_err,2.)+pow(tc22_5_alpgen_iqopt3_bin_err,2.));
  //     double tc22_5_rel_data_alpgen_iqopt3_err = tc22_5_abs_data_alpgen_iqopt3_err/(tc22_5_data_bin_n-tc22_5_alpgen_iqopt3_bin_n);
  //     double tc22_5_rel_alpgen_iqopt3_err = tc22_5_alpgen_iqopt3_bin_err/tc22_5_alpgen_iqopt3_bin_n;
      
  //     double tc22_5_rel_ratio_data_alpgen_iqopt3_ww_met_et_err = sqrt(pow(tc22_5_rel_data_alpgen_iqopt3_err,2.)+pow(tc22_5_rel_alpgen_iqopt3_err,2.));

  //     double tc22_5_data_alpgen_iqopt3_ratio = (tc22_5_data_bin_n-tc22_5_alpgen_iqopt3_bin_n)/tc22_5_alpgen_iqopt3_bin_n;

  //     double tc22_5_data_alpgen_iqopt3_ratio_err = fabs(tc22_5_rel_ratio_data_alpgen_iqopt3_ww_met_et_err*tc22_5_data_alpgen_iqopt3_ratio);

  //     h_ratio_data_alpgen_iqopt3_ww_met_et->SetBinContent(b,tc22_5_data_alpgen_iqopt3_ratio);
  //     h_ratio_data_alpgen_iqopt3_ww_met_et->SetBinError(b,tc22_5_data_alpgen_iqopt3_ratio_err);
  //   }
    
  //   if(tc22_5_data_bin_n && tc22_5_alpgen_ptjmin10_bin_n) {

  //     // //Error calc (see histogrampainter for clarification)
  //     double tc22_5_abs_data_alpgen_ptjmin10_err = sqrt(pow(tc22_5_data_bin_err,2.)+pow(tc22_5_alpgen_ptjmin10_bin_err,2.));
  //     double tc22_5_rel_data_alpgen_ptjmin10_err = tc22_5_abs_data_alpgen_ptjmin10_err/(tc22_5_data_bin_n-tc22_5_alpgen_ptjmin10_bin_n);
  //     double tc22_5_rel_alpgen_ptjmin10_err = tc22_5_alpgen_ptjmin10_bin_err/tc22_5_alpgen_ptjmin10_bin_n;
      
  //     double tc22_5_rel_ratio_data_alpgen_ptjmin10_ww_met_et_err = sqrt(pow(tc22_5_rel_data_alpgen_ptjmin10_err,2.)+pow(tc22_5_rel_alpgen_ptjmin10_err,2.));

  //     double tc22_5_data_alpgen_ptjmin10_ratio = (tc22_5_data_bin_n-tc22_5_alpgen_ptjmin10_bin_n)/tc22_5_alpgen_ptjmin10_bin_n;

  //     double tc22_5_data_alpgen_ptjmin10_ratio_err = fabs(tc22_5_rel_ratio_data_alpgen_ptjmin10_ww_met_et_err*tc22_5_data_alpgen_ptjmin10_ratio);

  //     h_ratio_data_alpgen_ptjmin10_ww_met_et->SetBinContent(b,tc22_5_data_alpgen_ptjmin10_ratio);
  //     h_ratio_data_alpgen_ptjmin10_ww_met_et->SetBinError(b,tc22_5_data_alpgen_ptjmin10_ratio_err);
  //   }
  // }


  // h_ratio_data_alpgen_ww_met_et->Draw("PE");
  // h_ratio_data_sherpa_ww_met_et->Draw("PE sames");
  // h_ratio_data_alpgen_iqopt3_ww_met_et->Draw("PE sames");
  // h_ratio_data_alpgen_ptjmin10_ww_met_et->Draw("PE sames");
  
  // //  h_ratio_alpgen_iqopt3_ww_met_et->Draw("PE sames");
  // //  h_ratio_alpgen_ptjmin10_ww_met_et->Draw("PE sames");
  
  // tc22_5->Update();
  // tc22_5->SaveAs("./plots/latest/data_muon_ww_met_et.png");
    
  // // //NEXT
  
  //////////////////////////////////////////////////
  // tc23
  // jet_n: sherpa/alpgen+wjrw
  //////////////////////////////////////////////////
  
  string tc23_title = "Jet N (elec)";
  string tc23_name = "tc23";
  TCanvas* tc23 = new TCanvas(tc23_name.c_str(),tc23_title.c_str(),0,0,1920,1200);
  tc23->cd();

  TPad* tc23_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  tc23_pad01->SetTopMargin(0.05);
  tc23_pad01->SetBottomMargin(0.31);
  tc23_pad01->Draw();

  TPad* tc23_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  tc23_pad02->SetBottomMargin(0.0005);
  tc23_pad02->SetLogy();
  tc23_pad02->Draw();
  tc23_pad02->cd();

  // Plots
  
  TH1F* h_alpgen_nom_elec_jet_n = (TH1F*) wjets_alpgen_file->Get("all/h_elec_purw_nom_jet_n");
  TH1F* h_alpgen_iqopt3_elec_jet_n = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_iqopt3_jet_n");
  TH1F* h_alpgen_ptjmin10_elec_jet_n = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_ptjmin10_jet_n");
  TH1F* h_sherpa_nom_elec_jet_n = (TH1F*) wjets_sherpa_file->Get("all/h_elec_purw_nom_jet_n");
  
  h_alpgen_nom_elec_jet_n->SetMarkerStyle(20);
  h_alpgen_nom_elec_jet_n->SetMarkerSize(1.2);
  h_alpgen_nom_elec_jet_n->SetTitle("");
  h_alpgen_nom_elec_jet_n->Draw("PE");

  h_alpgen_iqopt3_elec_jet_n->SetMarkerStyle(22);
  h_alpgen_iqopt3_elec_jet_n->SetMarkerSize(1.2);
  h_alpgen_iqopt3_elec_jet_n->SetMarkerColor(kGreen);
  h_alpgen_iqopt3_elec_jet_n->Draw("PE sames");


  h_alpgen_ptjmin10_elec_jet_n->SetMarkerStyle(22);
  h_alpgen_ptjmin10_elec_jet_n->SetMarkerSize(1.2);
  h_alpgen_ptjmin10_elec_jet_n->SetMarkerColor(kBlue);
  h_alpgen_ptjmin10_elec_jet_n->Draw("PE sames");


  h_sherpa_nom_elec_jet_n->SetMarkerStyle(20);
  h_sherpa_nom_elec_jet_n->SetMarkerSize(1.2);
  h_sherpa_nom_elec_jet_n->SetMarkerColor(kRed);
  h_sherpa_nom_elec_jet_n->Draw("PE sames");


  //Legend
  TLegend* lgnd_tc23 = new TLegend(0.15,0.15,0.28,0.35);
  lgnd_tc23->SetFillColor(0);
  lgnd_tc23->SetTextSize(0.03);
  lgnd_tc23->SetBorderSize(0);


  char lgnd_alpgen_nom_elec_jet_n_name[20];
  sprintf(lgnd_alpgen_nom_elec_jet_n_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_elec_jet_n->Integral());
  lgnd_tc23->AddEntry(h_alpgen_nom_elec_jet_n,lgnd_alpgen_nom_elec_jet_n_name,"p");

  char lgnd_alpgen_iqopt3_elec_jet_n_name[20];
  sprintf(lgnd_alpgen_iqopt3_elec_jet_n_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_elec_jet_n->Integral());
  lgnd_tc23->AddEntry(h_alpgen_iqopt3_elec_jet_n,lgnd_alpgen_iqopt3_elec_jet_n_name,"p");

  char lgnd_alpgen_ptjmin10_elec_jet_n_name[20];
  sprintf(lgnd_alpgen_ptjmin10_elec_jet_n_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_elec_jet_n->Integral());
  lgnd_tc23->AddEntry(h_alpgen_ptjmin10_elec_jet_n,lgnd_alpgen_ptjmin10_elec_jet_n_name,"p");

  char lgnd_sherpa_nom_elec_jet_n_name[20];
  sprintf(lgnd_sherpa_nom_elec_jet_n_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_elec_jet_n->Integral());
  lgnd_tc23->AddEntry(h_sherpa_nom_elec_jet_n,lgnd_sherpa_nom_elec_jet_n_name,"p");

  lgnd_tc23->Draw();
  
  //////////////////////////////////////////////////
  //Ratio
  ////////////////////////////////////////////////// 

  tc23_pad01->cd();
  tc23_pad01->SetGrid();

  int n_bins = ((TAxis*) h_alpgen_nom_elec_jet_n->GetXaxis())->GetNbins();
  double x_min = ((TAxis*) h_alpgen_nom_elec_jet_n->GetXaxis())->GetXmin();
  double x_max = ((TAxis*) h_alpgen_nom_elec_jet_n->GetXaxis())->GetXmax();

  // alp-sherp/sherp
  string tc23_ratio_alpgen_sherpa_jet_n_name = "tc23_ratio_alpgen_sherpa_jet_n";
  TH1F* h_ratio_alpgen_sherpa_jet_n = new TH1F(tc23_ratio_alpgen_sherpa_jet_n_name.c_str(),"",n_bins,x_min,x_max);
  h_ratio_alpgen_sherpa_jet_n->SetMarkerStyle(8);
  h_ratio_alpgen_sherpa_jet_n->SetMarkerColor(kRed);

  TAxis* h_ratio_alpgen_sherpa_jet_n_xaxis = h_ratio_alpgen_sherpa_jet_n->GetXaxis();
  TAxis* h_ratio_alpgen_sherpa_jet_n_yaxis = h_ratio_alpgen_sherpa_jet_n->GetYaxis();
  
  h_ratio_alpgen_sherpa_jet_n_xaxis->SetLabelSize(0.08);
  h_ratio_alpgen_sherpa_jet_n_yaxis->SetLabelSize(0.08);

  h_ratio_alpgen_sherpa_jet_n_xaxis->SetTitle("jet n");
  h_ratio_alpgen_sherpa_jet_n_xaxis->SetTitleSize(0.07);
  h_ratio_alpgen_sherpa_jet_n_yaxis->SetNdivisions(4,4,4);
  h_ratio_alpgen_sherpa_jet_n_yaxis->SetTitle("(alpgen-MC)/MC");
  h_ratio_alpgen_sherpa_jet_n_yaxis->SetTitleSize(0.07);
  h_ratio_alpgen_sherpa_jet_n_yaxis->SetTitleOffset(0.36);
  h_ratio_alpgen_sherpa_jet_n_yaxis->SetRangeUser(-1,1);

  
  // alp-iqopt3/iqopt3
  string tc23_ratio_alpgen_iqopt3_jet_n_name = "tc23_ratio_alpgen_iqopt3_jet_n";
  TH1F* h_ratio_alpgen_iqopt3_jet_n = new TH1F(tc23_ratio_alpgen_iqopt3_jet_n_name.c_str(),"",n_bins,x_min,x_max);
  h_ratio_alpgen_iqopt3_jet_n->SetMarkerStyle(8);
  h_ratio_alpgen_iqopt3_jet_n->SetMarkerColor(kGreen);

  
  // alp-ptjmin10/ptjmin10
  string tc23_ratio_alpgen_ptjmin10_jet_n_name = "tc23_ratio_alpgen_ptjmin10_jet_n";
  TH1F* h_ratio_alpgen_ptjmin10_jet_n = new TH1F(tc23_ratio_alpgen_ptjmin10_jet_n_name.c_str(),"",n_bins,x_min,x_max);
  h_ratio_alpgen_ptjmin10_jet_n->SetMarkerStyle(8);
  h_ratio_alpgen_ptjmin10_jet_n->SetMarkerColor(kBlue);


  
  double tc23_alpgen_sherpa_ratio=0.;
  double tc23_alpgen_iqopt3_ratio=0.;
  double tc23_alpgen_ptjmin10_ratio=0.;
  
  for(int b=1;b<n_bins+1;b++){

    double tc23_alpgen_nom_bin_n=h_alpgen_nom_elec_jet_n->GetBinContent(b);
    double tc23_alpgen_nom_bin_err=h_alpgen_nom_elec_jet_n->GetBinError(b);    

    double tc23_sherpa_nom_bin_n=h_sherpa_nom_elec_jet_n->GetBinContent(b);
    double tc23_sherpa_nom_bin_err=h_sherpa_nom_elec_jet_n->GetBinError(b);    

    double tc23_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_elec_jet_n->GetBinContent(b);
    double tc23_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_elec_jet_n->GetBinError(b);

    double tc23_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_elec_jet_n->GetBinContent(b);
    double tc23_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_elec_jet_n->GetBinError(b);



    if(tc23_alpgen_nom_bin_n && tc23_sherpa_nom_bin_n) {

      // //Error calc (see histogrampainter for clarification)
      double tc23_abs_alpgen_sherpa_err = sqrt(pow(tc23_alpgen_nom_bin_err,2.)+pow(tc23_sherpa_nom_bin_err,2.));
      double tc23_rel_alpgen_sherpa_err = tc23_abs_alpgen_sherpa_err/(tc23_alpgen_nom_bin_n-tc23_sherpa_nom_bin_n);
      double tc23_rel_sherpa_err = tc23_sherpa_nom_bin_err/tc23_sherpa_nom_bin_n;
      
      double tc23_rel_ratio_alpgen_sherpa_jet_n_err = sqrt(pow(tc23_rel_alpgen_sherpa_err,2.)+pow(tc23_rel_sherpa_err,2.));

      double tc23_alpgen_sherpa_ratio = (tc23_alpgen_nom_bin_n-tc23_sherpa_nom_bin_n)/tc23_sherpa_nom_bin_n;

      double tc23_alpgen_sherpa_ratio_err = fabs(tc23_rel_ratio_alpgen_sherpa_jet_n_err*tc23_alpgen_sherpa_ratio);

      h_ratio_alpgen_sherpa_jet_n->SetBinContent(b,tc23_alpgen_sherpa_ratio);
      h_ratio_alpgen_sherpa_jet_n->SetBinError(b,tc23_alpgen_sherpa_ratio_err);
    }
    

    if(tc23_alpgen_nom_bin_n && tc23_alpgen_iqopt3_bin_n) {

      // //Error calc (see histogrampainter for clarification)
      double tc23_abs_alpgen_iqopt3_err = sqrt(pow(tc23_alpgen_nom_bin_err,2.)+pow(tc23_alpgen_iqopt3_bin_err,2.));
      double tc23_rel_alpgen_iqopt3_err = tc23_abs_alpgen_iqopt3_err/(tc23_alpgen_nom_bin_n-tc23_alpgen_iqopt3_bin_n);
      double tc23_rel_iqopt3_err = tc23_alpgen_iqopt3_bin_err/tc23_alpgen_iqopt3_bin_n;
      
      double tc23_rel_ratio_alpgen_iqopt3_jet_n_err = sqrt(pow(tc23_rel_alpgen_iqopt3_err,2.)+pow(tc23_rel_iqopt3_err,2.));

      double tc23_alpgen_iqopt3_ratio = (tc23_alpgen_nom_bin_n-tc23_alpgen_iqopt3_bin_n)/tc23_alpgen_iqopt3_bin_n;

      double tc23_alpgen_iqopt3_ratio_err = fabs(tc23_rel_ratio_alpgen_iqopt3_jet_n_err*tc23_alpgen_iqopt3_ratio);

      h_ratio_alpgen_iqopt3_jet_n->SetBinContent(b,tc23_alpgen_iqopt3_ratio);
      h_ratio_alpgen_iqopt3_jet_n->SetBinError(b,tc23_alpgen_iqopt3_ratio_err);
    }

    

    if(tc23_alpgen_nom_bin_n && tc23_alpgen_ptjmin10_bin_n) {

      // //Error calc (see histogrampainter for clarification)
      double tc23_abs_alpgen_ptjmin10_err = sqrt(pow(tc23_alpgen_nom_bin_err,2.)+pow(tc23_alpgen_ptjmin10_bin_err,2.));
      double tc23_rel_alpgen_ptjmin10_err = tc23_abs_alpgen_ptjmin10_err/(tc23_alpgen_nom_bin_n-tc23_alpgen_ptjmin10_bin_n);
      double tc23_rel_ptjmin10_err = tc23_alpgen_ptjmin10_bin_err/tc23_alpgen_ptjmin10_bin_n;
      
      double tc23_rel_ratio_alpgen_ptjmin10_jet_n_err = sqrt(pow(tc23_rel_alpgen_ptjmin10_err,2.)+pow(tc23_rel_ptjmin10_err,2.));

      double tc23_alpgen_ptjmin10_ratio = (tc23_alpgen_nom_bin_n-tc23_alpgen_ptjmin10_bin_n)/tc23_alpgen_ptjmin10_bin_n;

      double tc23_alpgen_ptjmin10_ratio_err = fabs(tc23_rel_ratio_alpgen_ptjmin10_jet_n_err*tc23_alpgen_ptjmin10_ratio);

      h_ratio_alpgen_ptjmin10_jet_n->SetBinContent(b,tc23_alpgen_ptjmin10_ratio);
      h_ratio_alpgen_ptjmin10_jet_n->SetBinError(b,tc23_alpgen_ptjmin10_ratio_err);
    }
    
  }


  h_ratio_alpgen_sherpa_jet_n->Draw("PE");
  h_ratio_alpgen_iqopt3_jet_n->Draw("PE sames");
  h_ratio_alpgen_ptjmin10_jet_n->Draw("PE sames");
  
  tc23->Update();

  tc23->SaveAs("./plots/latest/elec_jet_n.png");
    
  //NEXT
  
  //////////////////////////////////////////////////
  // tc23_5
  // jet_n: sherpa/alpgen+wjrw
  //////////////////////////////////////////////////
  
  string tc23_5_title = "Jet N (elec) w/ Data";
  string tc23_5_name = "tc23_5";
  TCanvas* tc23_5 = new TCanvas(tc23_5_name.c_str(),tc23_5_title.c_str(),0,0,1920,1200);
  tc23_5->cd();

  TPad* tc23_5_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  tc23_5_pad01->SetTopMargin(0.05);
  tc23_5_pad01->SetBottomMargin(0.31);
  tc23_5_pad01->Draw();

  TPad* tc23_5_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  tc23_5_pad02->SetBottomMargin(0.0005);
  tc23_5_pad02->SetLogy();
  tc23_5_pad02->Draw();
  tc23_5_pad02->cd();

  // Plots
  
  TH1F* h_alpgen_nom_elec_jet_n = (TH1F*) wjets_alpgen_file->Get("all/h_elec_purw_nom_jet_n");
  TH1F* h_alpgen_iqopt3_elec_jet_n = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_iqopt3_jet_n");
  TH1F* h_alpgen_ptjmin10_elec_jet_n = (TH1F*) wjets_alpgen_file->Get("all/h_elec_wjrw_ptjmin10_jet_n");
  TH1F* h_sherpa_nom_elec_jet_n = (TH1F*) wjets_sherpa_file->Get("all/h_elec_purw_nom_jet_n");
  TH1F* h_data_elec_jet_n = (TH1F*) data_file->Get("all/h_elec_purw_nom_jet_n");

  TH1F* h_top_elec_jet_n = (TH1F*) top_mcatnlo_file->Get("all/h_elec_purw_nom_jet_n");
  TH1F* h_zjets_elec_jet_n = (TH1F*) zjets_alpgen_file->Get("all/h_elec_purw_nom_jet_n");
  TH1F* h_vv_elec_jet_n = (TH1F*) vv_herwig_file->Get("all/h_elec_purw_nom_jet_n");
  TH1F* h_qcd_elec_jet_n = (TH1F*) qcd_file->Get("all/h_elec_purw_nom_jet_n");
  

  //Add Backgrounds
  h_alpgen_nom_elec_jet_n->Add(h_top_elec_jet_n);
  h_alpgen_nom_elec_jet_n->Add(h_zjets_elec_jet_n);
  h_alpgen_nom_elec_jet_n->Add(h_vv_elec_jet_n);
  h_alpgen_nom_elec_jet_n->Add(h_qcd_elec_jet_n);
  
  h_alpgen_nom_elec_jet_n->SetMarkerStyle(20);
  h_alpgen_nom_elec_jet_n->SetMarkerSize(1.2);
  h_alpgen_nom_elec_jet_n->SetTitle("");
  h_alpgen_nom_elec_jet_n->Draw("PE");

  //Add backgrounds
  h_alpgen_iqopt3_elec_jet_n->Add(h_top_elec_jet_n);
  h_alpgen_iqopt3_elec_jet_n->Add(h_zjets_elec_jet_n);
  h_alpgen_iqopt3_elec_jet_n->Add(h_vv_elec_jet_n);
  h_alpgen_iqopt3_elec_jet_n->Add(h_qcd_elec_jet_n);

  h_alpgen_iqopt3_elec_jet_n->SetMarkerStyle(22);
  h_alpgen_iqopt3_elec_jet_n->SetMarkerSize(1.2);
  h_alpgen_iqopt3_elec_jet_n->SetMarkerColor(kGreen);
  h_alpgen_iqopt3_elec_jet_n->Draw("PE sames");

  //Add Backgrounds
  h_alpgen_ptjmin10_elec_jet_n->Add(h_top_elec_jet_n);
  h_alpgen_ptjmin10_elec_jet_n->Add(h_zjets_elec_jet_n);
  h_alpgen_ptjmin10_elec_jet_n->Add(h_vv_elec_jet_n);
  h_alpgen_ptjmin10_elec_jet_n->Add(h_qcd_elec_jet_n);

  h_alpgen_ptjmin10_elec_jet_n->SetMarkerStyle(22);
  h_alpgen_ptjmin10_elec_jet_n->SetMarkerSize(1.2);
  h_alpgen_ptjmin10_elec_jet_n->SetMarkerColor(kBlue);
  h_alpgen_ptjmin10_elec_jet_n->Draw("PE sames");

  //Add Backgrounds
  h_sherpa_nom_elec_jet_n->Add(h_top_elec_jet_n);
  h_sherpa_nom_elec_jet_n->Add(h_zjets_elec_jet_n);
  h_sherpa_nom_elec_jet_n->Add(h_vv_elec_jet_n);
  h_sherpa_nom_elec_jet_n->Add(h_qcd_elec_jet_n);

  h_sherpa_nom_elec_jet_n->SetMarkerStyle(20);
  h_sherpa_nom_elec_jet_n->SetMarkerSize(1.2);
  h_sherpa_nom_elec_jet_n->SetMarkerColor(kRed);
  h_sherpa_nom_elec_jet_n->Draw("PE sames");

  h_data_elec_jet_n->Draw("sames");


  //Legend
  TLegend* lgnd_tc23_5 = new TLegend(0.15,0.15,0.28,0.35);
  lgnd_tc23_5->SetFillColor(0);
  lgnd_tc23_5->SetTextSize(0.03);
  lgnd_tc23_5->SetBorderSize(0);

  char lgnd_data_elec_jet_n_name[20];
  sprintf(lgnd_data_elec_jet_n_name,"%s,  %.2f","DATA",h_data_elec_jet_n->Integral());
  lgnd_tc23_5->AddEntry(h_data_elec_jet_n,lgnd_data_elec_jet_n_name,"f");

  char lgnd_alpgen_nom_elec_jet_n_name[20];
  sprintf(lgnd_alpgen_nom_elec_jet_n_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_elec_jet_n->Integral());
  lgnd_tc23_5->AddEntry(h_alpgen_nom_elec_jet_n,lgnd_alpgen_nom_elec_jet_n_name,"p");

  char lgnd_alpgen_iqopt3_elec_jet_n_name[20];
  sprintf(lgnd_alpgen_iqopt3_elec_jet_n_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_elec_jet_n->Integral());
  lgnd_tc23_5->AddEntry(h_alpgen_iqopt3_elec_jet_n,lgnd_alpgen_iqopt3_elec_jet_n_name,"p");

  char lgnd_alpgen_ptjmin10_elec_jet_n_name[20];
  sprintf(lgnd_alpgen_ptjmin10_elec_jet_n_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_elec_jet_n->Integral());
  lgnd_tc23_5->AddEntry(h_alpgen_ptjmin10_elec_jet_n,lgnd_alpgen_ptjmin10_elec_jet_n_name,"p");

  char lgnd_sherpa_nom_elec_jet_n_name[20];
  sprintf(lgnd_sherpa_nom_elec_jet_n_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_elec_jet_n->Integral());
  lgnd_tc23_5->AddEntry(h_sherpa_nom_elec_jet_n,lgnd_sherpa_nom_elec_jet_n_name,"p");

  lgnd_tc23_5->Draw();
  
  //////////////////////////////////////////////////
  //Ratio
  ////////////////////////////////////////////////// 

  tc23_5_pad01->cd();
  tc23_5_pad01->SetGrid();

  int n_bins = ((TAxis*) h_alpgen_nom_elec_jet_n->GetXaxis())->GetNbins();
  double x_min = ((TAxis*) h_alpgen_nom_elec_jet_n->GetXaxis())->GetXmin();
  double x_max = ((TAxis*) h_alpgen_nom_elec_jet_n->GetXaxis())->GetXmax();

  // data-alpgen(nom)/alpgen(nom)
  string tc23_5_ratio_data_alpgen_jet_n_name = "tc23_5_ratio_data_alpgen_jet_n";
  TH1F* h_ratio_data_alpgen_jet_n = new TH1F(tc23_5_ratio_data_alpgen_jet_n_name.c_str(),"",n_bins,x_min,x_max);
  h_ratio_data_alpgen_jet_n->SetMarkerStyle(8);
  //h_ratio_data_alpgen_jet_n->SetMarkerColor(kRed);

  TAxis* h_ratio_data_alpgen_jet_n_xaxis = h_ratio_data_alpgen_jet_n->GetXaxis();
  TAxis* h_ratio_data_alpgen_jet_n_yaxis = h_ratio_data_alpgen_jet_n->GetYaxis();
  
  h_ratio_data_alpgen_jet_n_xaxis->SetLabelSize(0.08);
  h_ratio_data_alpgen_jet_n_yaxis->SetLabelSize(0.08);

  h_ratio_data_alpgen_jet_n_xaxis->SetTitle("jet n");
  h_ratio_data_alpgen_jet_n_xaxis->SetTitleSize(0.07);
  h_ratio_data_alpgen_jet_n_yaxis->SetNdivisions(4,4,4);
  h_ratio_data_alpgen_jet_n_yaxis->SetTitle("(data-MC)/MC");
  h_ratio_data_alpgen_jet_n_yaxis->SetTitleSize(0.07);
  h_ratio_data_alpgen_jet_n_yaxis->SetTitleOffset(0.36);
  h_ratio_data_alpgen_jet_n_yaxis->SetRangeUser(-1,1);

  // data-sherpa(nom)/sherpa(nom)
  string tc23_5_ratio_data_sherpa_jet_n_name = "tc23_5_ratio_data_sherpa_jet_n";
  TH1F* h_ratio_data_sherpa_jet_n = new TH1F(tc23_5_ratio_data_sherpa_jet_n_name.c_str(),"",n_bins,x_min,x_max);
  h_ratio_data_sherpa_jet_n->SetMarkerStyle(8);
  h_ratio_data_sherpa_jet_n->SetMarkerColor(kRed);


  // data-alpgen(iqopt3)/alpgen(iqopt3)
  string tc23_5_ratio_data_alpgen_iqopt3_jet_n_name = "tc23_5_ratio_data_alpgen_iqopt3_jet_n";
  TH1F* h_ratio_data_alpgen_iqopt3_jet_n = new TH1F(tc23_5_ratio_data_alpgen_iqopt3_jet_n_name.c_str(),"",n_bins,x_min,x_max);
  h_ratio_data_alpgen_iqopt3_jet_n->SetMarkerStyle(8);
  h_ratio_data_alpgen_iqopt3_jet_n->SetMarkerColor(kGreen);

  // data-alpgen(ptjmin10)/alpgen(ptjmin10)
  string tc23_5_ratio_data_alpgen_ptjmin10_jet_n_name = "tc23_5_ratio_data_alpgen_ptjmin10_jet_n";
  TH1F* h_ratio_data_alpgen_ptjmin10_jet_n = new TH1F(tc23_5_ratio_data_alpgen_ptjmin10_jet_n_name.c_str(),"",n_bins,x_min,x_max);
  h_ratio_data_alpgen_ptjmin10_jet_n->SetMarkerStyle(8);
  h_ratio_data_alpgen_ptjmin10_jet_n->SetMarkerColor(kBlue);

  

  
  // // alp-iqopt3/iqopt3
  // string tc23_5_ratio_alpgen_iqopt3_jet_n_name = "tc23_5_ratio_alpgen_iqopt3_jet_n";
  // TH1F* h_ratio_alpgen_iqopt3_jet_n = new TH1F(tc23_5_ratio_alpgen_iqopt3_jet_n_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_iqopt3_jet_n->SetMarkerStyle(8);
  // h_ratio_alpgen_iqopt3_jet_n->SetMarkerColor(kGreen);

  
  // // alp-ptjmin10/ptjmin10
  // string tc23_5_ratio_alpgen_ptjmin10_jet_n_name = "tc23_5_ratio_alpgen_ptjmin10_jet_n";
  // TH1F* h_ratio_alpgen_ptjmin10_jet_n = new TH1F(tc23_5_ratio_alpgen_ptjmin10_jet_n_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_ptjmin10_jet_n->SetMarkerStyle(8);
  // h_ratio_alpgen_ptjmin10_jet_n->SetMarkerColor(kBlue);


  
  double tc23_5_data_alpgen_ratio=0.;
  double tc23_5_data_sherpa_ratio=0.;
  double tc23_5_data_alpgen_iqopt3_ratio=0.;
  double tc23_5_data_alpgen_ptjmin10_ratio=0.;
  
  for(int b=1;b<n_bins+1;b++){

    double tc23_5_alpgen_nom_bin_n=h_alpgen_nom_elec_jet_n->GetBinContent(b);
    double tc23_5_alpgen_nom_bin_err=h_alpgen_nom_elec_jet_n->GetBinError(b);    

    double tc23_5_data_bin_n=h_data_elec_jet_n->GetBinContent(b);
    double tc23_5_data_bin_err=h_data_elec_jet_n->GetBinError(b);    

    double tc23_5_sherpa_nom_bin_n=h_sherpa_nom_elec_jet_n->GetBinContent(b);
    double tc23_5_sherpa_nom_bin_err=h_sherpa_nom_elec_jet_n->GetBinError(b);    

    double tc23_5_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_elec_jet_n->GetBinContent(b);
    double tc23_5_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_elec_jet_n->GetBinError(b);

    double tc23_5_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_elec_jet_n->GetBinContent(b);
    double tc23_5_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_elec_jet_n->GetBinError(b);



    if(tc23_5_data_bin_n && tc23_5_alpgen_nom_bin_n) {

      // //Error calc (see histogrampainter for clarification)
      double tc23_5_abs_data_alpgen_err = sqrt(pow(tc23_5_data_bin_err,2.)+pow(tc23_5_alpgen_nom_bin_err,2.));
      double tc23_5_rel_data_alpgen_err = tc23_5_abs_data_alpgen_err/(tc23_5_data_bin_n-tc23_5_alpgen_nom_bin_n);
      double tc23_5_rel_alpgen_err = tc23_5_alpgen_nom_bin_err/tc23_5_alpgen_nom_bin_n;
      
      double tc23_5_rel_ratio_data_alpgen_jet_n_err = sqrt(pow(tc23_5_rel_data_alpgen_err,2.)+pow(tc23_5_rel_alpgen_err,2.));

      double tc23_5_data_alpgen_ratio = (tc23_5_data_bin_n-tc23_5_alpgen_nom_bin_n)/tc23_5_alpgen_nom_bin_n;

      double tc23_5_data_alpgen_ratio_err = fabs(tc23_5_rel_ratio_data_alpgen_jet_n_err*tc23_5_data_alpgen_ratio);

      h_ratio_data_alpgen_jet_n->SetBinContent(b,tc23_5_data_alpgen_ratio);
      h_ratio_data_alpgen_jet_n->SetBinError(b,tc23_5_data_alpgen_ratio_err);
    }
    

    if(tc23_5_data_bin_n && tc23_5_sherpa_nom_bin_n) {

      // //Error calc (see histogrampainter for clarification)
      double tc23_5_abs_data_sherpa_err = sqrt(pow(tc23_5_data_bin_err,2.)+pow(tc23_5_sherpa_nom_bin_err,2.));
      double tc23_5_rel_data_sherpa_err = tc23_5_abs_data_sherpa_err/(tc23_5_data_bin_n-tc23_5_sherpa_nom_bin_n);
      double tc23_5_rel_sherpa_err = tc23_5_sherpa_nom_bin_err/tc23_5_sherpa_nom_bin_n;
      
      double tc23_5_rel_ratio_data_sherpa_jet_n_err = sqrt(pow(tc23_5_rel_data_sherpa_err,2.)+pow(tc23_5_rel_sherpa_err,2.));

      double tc23_5_data_sherpa_ratio = (tc23_5_data_bin_n-tc23_5_sherpa_nom_bin_n)/tc23_5_sherpa_nom_bin_n;

      double tc23_5_data_sherpa_ratio_err = fabs(tc23_5_rel_ratio_data_sherpa_jet_n_err*tc23_5_data_sherpa_ratio);

      h_ratio_data_sherpa_jet_n->SetBinContent(b,tc23_5_data_sherpa_ratio);
      h_ratio_data_sherpa_jet_n->SetBinError(b,tc23_5_data_sherpa_ratio_err);
    }
    

    if(tc23_5_data_bin_n && tc23_5_alpgen_iqopt3_bin_n) {

      // //Error calc (see histogrampainter for clarification)
      double tc23_5_abs_data_alpgen_iqopt3_err = sqrt(pow(tc23_5_data_bin_err,2.)+pow(tc23_5_alpgen_iqopt3_bin_err,2.));
      double tc23_5_rel_data_alpgen_iqopt3_err = tc23_5_abs_data_alpgen_iqopt3_err/(tc23_5_data_bin_n-tc23_5_alpgen_iqopt3_bin_n);
      double tc23_5_rel_alpgen_iqopt3_err = tc23_5_alpgen_iqopt3_bin_err/tc23_5_alpgen_iqopt3_bin_n;
      
      double tc23_5_rel_ratio_data_alpgen_iqopt3_jet_n_err = sqrt(pow(tc23_5_rel_data_alpgen_iqopt3_err,2.)+pow(tc23_5_rel_alpgen_iqopt3_err,2.));

      double tc23_5_data_alpgen_iqopt3_ratio = (tc23_5_data_bin_n-tc23_5_alpgen_iqopt3_bin_n)/tc23_5_alpgen_iqopt3_bin_n;

      double tc23_5_data_alpgen_iqopt3_ratio_err = fabs(tc23_5_rel_ratio_data_alpgen_iqopt3_jet_n_err*tc23_5_data_alpgen_iqopt3_ratio);

      h_ratio_data_alpgen_iqopt3_jet_n->SetBinContent(b,tc23_5_data_alpgen_iqopt3_ratio);
      h_ratio_data_alpgen_iqopt3_jet_n->SetBinError(b,tc23_5_data_alpgen_iqopt3_ratio_err);
    }
    
    if(tc23_5_data_bin_n && tc23_5_alpgen_ptjmin10_bin_n) {

      // //Error calc (see histogrampainter for clarification)
      double tc23_5_abs_data_alpgen_ptjmin10_err = sqrt(pow(tc23_5_data_bin_err,2.)+pow(tc23_5_alpgen_ptjmin10_bin_err,2.));
      double tc23_5_rel_data_alpgen_ptjmin10_err = tc23_5_abs_data_alpgen_ptjmin10_err/(tc23_5_data_bin_n-tc23_5_alpgen_ptjmin10_bin_n);
      double tc23_5_rel_alpgen_ptjmin10_err = tc23_5_alpgen_ptjmin10_bin_err/tc23_5_alpgen_ptjmin10_bin_n;
      
      double tc23_5_rel_ratio_data_alpgen_ptjmin10_jet_n_err = sqrt(pow(tc23_5_rel_data_alpgen_ptjmin10_err,2.)+pow(tc23_5_rel_alpgen_ptjmin10_err,2.));

      double tc23_5_data_alpgen_ptjmin10_ratio = (tc23_5_data_bin_n-tc23_5_alpgen_ptjmin10_bin_n)/tc23_5_alpgen_ptjmin10_bin_n;

      double tc23_5_data_alpgen_ptjmin10_ratio_err = fabs(tc23_5_rel_ratio_data_alpgen_ptjmin10_jet_n_err*tc23_5_data_alpgen_ptjmin10_ratio);

      h_ratio_data_alpgen_ptjmin10_jet_n->SetBinContent(b,tc23_5_data_alpgen_ptjmin10_ratio);
      h_ratio_data_alpgen_ptjmin10_jet_n->SetBinError(b,tc23_5_data_alpgen_ptjmin10_ratio_err);
    }
    
  }



  h_ratio_data_alpgen_jet_n->Draw("PE");
  h_ratio_data_sherpa_jet_n->Draw("PE sames");
  h_ratio_data_alpgen_iqopt3_jet_n->Draw("PE sames");
  h_ratio_data_alpgen_ptjmin10_jet_n->Draw("PE sames");
  
  //  h_ratio_alpgen_iqopt3_jet_n->Draw("PE sames");
  //  h_ratio_alpgen_ptjmin10_jet_n->Draw("PE sames");
  
  tc23_5->Update();

  tc23_5->SaveAs("./plots/latest/data_elec_jet_n.png");
    
  //NEXT

  //////////////////////////////////////////////////
  // tc24
  // jet_n: sherpa/alpgen+wjrw
  //////////////////////////////////////////////////
  
  string tc24_title = "Jet N (muon)";
  string tc24_name = "tc24";
  TCanvas* tc24 = new TCanvas(tc24_name.c_str(),tc24_title.c_str(),0,0,1920,1200);
  tc24->cd();

  TPad* tc24_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  tc24_pad01->SetTopMargin(0.05);
  tc24_pad01->SetBottomMargin(0.31);
  tc24_pad01->Draw();

  TPad* tc24_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  tc24_pad02->SetBottomMargin(0.0005);
  tc24_pad02->SetLogy();
  tc24_pad02->Draw();
  tc24_pad02->cd();

  // Plots
  
  TH1F* h_alpgen_nom_muon_jet_n = (TH1F*) wjets_alpgen_file->Get("all/h_muon_purw_nom_jet_n");
  TH1F* h_alpgen_iqopt3_muon_jet_n = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_iqopt3_jet_n");
  TH1F* h_alpgen_ptjmin10_muon_jet_n = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_ptjmin10_jet_n");
  TH1F* h_sherpa_nom_muon_jet_n = (TH1F*) wjets_sherpa_file->Get("all/h_muon_purw_nom_jet_n");
  
  h_alpgen_nom_muon_jet_n->SetMarkerStyle(20);
  h_alpgen_nom_muon_jet_n->SetMarkerSize(1.2);
  h_alpgen_nom_muon_jet_n->SetTitle("");
  h_alpgen_nom_muon_jet_n->Draw("PE");

  h_alpgen_iqopt3_muon_jet_n->SetMarkerStyle(22);
  h_alpgen_iqopt3_muon_jet_n->SetMarkerSize(1.2);
  h_alpgen_iqopt3_muon_jet_n->SetMarkerColor(kGreen);
  h_alpgen_iqopt3_muon_jet_n->Draw("PE sames");


  h_alpgen_ptjmin10_muon_jet_n->SetMarkerStyle(22);
  h_alpgen_ptjmin10_muon_jet_n->SetMarkerSize(1.2);
  h_alpgen_ptjmin10_muon_jet_n->SetMarkerColor(kBlue);
  h_alpgen_ptjmin10_muon_jet_n->Draw("PE sames");


  h_sherpa_nom_muon_jet_n->SetMarkerStyle(20);
  h_sherpa_nom_muon_jet_n->SetMarkerSize(1.2);
  h_sherpa_nom_muon_jet_n->SetMarkerColor(kRed);
  h_sherpa_nom_muon_jet_n->Draw("PE sames");


  //Legend
  TLegend* lgnd_tc24 = new TLegend(0.15,0.15,0.28,0.35);
  lgnd_tc24->SetFillColor(0);
  lgnd_tc24->SetTextSize(0.03);
  lgnd_tc24->SetBorderSize(0);

  char lgnd_alpgen_nom_muon_jet_n_name[20];
  sprintf(lgnd_alpgen_nom_muon_jet_n_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_muon_jet_n->Integral());
  lgnd_tc24->AddEntry(h_alpgen_nom_muon_jet_n,lgnd_alpgen_nom_muon_jet_n_name,"p");

  char lgnd_alpgen_iqopt3_muon_jet_n_name[20];
  sprintf(lgnd_alpgen_iqopt3_muon_jet_n_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_muon_jet_n->Integral());
  lgnd_tc24->AddEntry(h_alpgen_iqopt3_muon_jet_n,lgnd_alpgen_iqopt3_muon_jet_n_name,"p");

  char lgnd_alpgen_ptjmin10_muon_jet_n_name[20];
  sprintf(lgnd_alpgen_ptjmin10_muon_jet_n_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_muon_jet_n->Integral());
  lgnd_tc24->AddEntry(h_alpgen_ptjmin10_muon_jet_n,lgnd_alpgen_ptjmin10_muon_jet_n_name,"p");

  char lgnd_sherpa_nom_muon_jet_n_name[20];
  sprintf(lgnd_sherpa_nom_muon_jet_n_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_muon_jet_n->Integral());
  lgnd_tc24->AddEntry(h_sherpa_nom_muon_jet_n,lgnd_sherpa_nom_muon_jet_n_name,"p");

  lgnd_tc24->Draw();
  
  //////////////////////////////////////////////////
  //Ratio
  ////////////////////////////////////////////////// 

  tc24_pad01->cd();
  tc24_pad01->SetGrid();

  int n_bins = ((TAxis*) h_alpgen_nom_muon_jet_n->GetXaxis())->GetNbins();
  double x_min = ((TAxis*) h_alpgen_nom_muon_jet_n->GetXaxis())->GetXmin();
  double x_max = ((TAxis*) h_alpgen_nom_muon_jet_n->GetXaxis())->GetXmax();

  // alp-sherp/sherp
  string tc24_ratio_alpgen_sherpa_jet_n_name = "tc24_ratio_alpgen_sherpa_jet_n";
  TH1F* h_ratio_alpgen_sherpa_jet_n = new TH1F(tc24_ratio_alpgen_sherpa_jet_n_name.c_str(),"",n_bins,x_min,x_max);
  h_ratio_alpgen_sherpa_jet_n->SetMarkerStyle(8);
  h_ratio_alpgen_sherpa_jet_n->SetMarkerColor(kRed);

  TAxis* h_ratio_alpgen_sherpa_jet_n_xaxis = h_ratio_alpgen_sherpa_jet_n->GetXaxis();
  TAxis* h_ratio_alpgen_sherpa_jet_n_yaxis = h_ratio_alpgen_sherpa_jet_n->GetYaxis();
  
  h_ratio_alpgen_sherpa_jet_n_xaxis->SetLabelSize(0.08);
  h_ratio_alpgen_sherpa_jet_n_yaxis->SetLabelSize(0.08);

  h_ratio_alpgen_sherpa_jet_n_xaxis->SetTitle("jet n");
  h_ratio_alpgen_sherpa_jet_n_xaxis->SetTitleSize(0.07);
  h_ratio_alpgen_sherpa_jet_n_yaxis->SetNdivisions(4,4,4);
  h_ratio_alpgen_sherpa_jet_n_yaxis->SetTitle("(alpgen-MC)/MC");
  h_ratio_alpgen_sherpa_jet_n_yaxis->SetTitleSize(0.07);
  h_ratio_alpgen_sherpa_jet_n_yaxis->SetTitleOffset(0.36);
  h_ratio_alpgen_sherpa_jet_n_yaxis->SetRangeUser(-1,1);

  
  // alp-iqopt3/iqopt3
  string tc24_ratio_alpgen_iqopt3_jet_n_name = "tc24_ratio_alpgen_iqopt3_jet_n";
  TH1F* h_ratio_alpgen_iqopt3_jet_n = new TH1F(tc24_ratio_alpgen_iqopt3_jet_n_name.c_str(),"",n_bins,x_min,x_max);
  h_ratio_alpgen_iqopt3_jet_n->SetMarkerStyle(8);
  h_ratio_alpgen_iqopt3_jet_n->SetMarkerColor(kGreen);

  
  // alp-ptjmin10/ptjmin10
  string tc24_ratio_alpgen_ptjmin10_jet_n_name = "tc24_ratio_alpgen_ptjmin10_jet_n";
  TH1F* h_ratio_alpgen_ptjmin10_jet_n = new TH1F(tc24_ratio_alpgen_ptjmin10_jet_n_name.c_str(),"",n_bins,x_min,x_max);
  h_ratio_alpgen_ptjmin10_jet_n->SetMarkerStyle(8);
  h_ratio_alpgen_ptjmin10_jet_n->SetMarkerColor(kBlue);


  
  double tc24_alpgen_sherpa_ratio=0.;
  double tc24_alpgen_iqopt3_ratio=0.;
  double tc24_alpgen_ptjmin10_ratio=0.;
  
  for(int b=1;b<n_bins+1;b++){

    double tc24_alpgen_nom_bin_n=h_alpgen_nom_muon_jet_n->GetBinContent(b);
    double tc24_alpgen_nom_bin_err=h_alpgen_nom_muon_jet_n->GetBinError(b);    

    double tc24_sherpa_nom_bin_n=h_sherpa_nom_muon_jet_n->GetBinContent(b);
    double tc24_sherpa_nom_bin_err=h_sherpa_nom_muon_jet_n->GetBinError(b);    

    double tc24_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_muon_jet_n->GetBinContent(b);
    double tc24_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_muon_jet_n->GetBinError(b);

    double tc24_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_muon_jet_n->GetBinContent(b);
    double tc24_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_muon_jet_n->GetBinError(b);



    if(tc24_alpgen_nom_bin_n && tc24_sherpa_nom_bin_n) {

      // //Error calc (see histogrampainter for clarification)
      double tc24_abs_alpgen_sherpa_err = sqrt(pow(tc24_alpgen_nom_bin_err,2.)+pow(tc24_sherpa_nom_bin_err,2.));
      double tc24_rel_alpgen_sherpa_err = tc24_abs_alpgen_sherpa_err/(tc24_alpgen_nom_bin_n-tc24_sherpa_nom_bin_n);
      double tc24_rel_sherpa_err = tc24_sherpa_nom_bin_err/tc24_sherpa_nom_bin_n;
      
      double tc24_rel_ratio_alpgen_sherpa_jet_n_err = sqrt(pow(tc24_rel_alpgen_sherpa_err,2.)+pow(tc24_rel_sherpa_err,2.));

      double tc24_alpgen_sherpa_ratio = (tc24_alpgen_nom_bin_n-tc24_sherpa_nom_bin_n)/tc24_sherpa_nom_bin_n;

      double tc24_alpgen_sherpa_ratio_err = fabs(tc24_rel_ratio_alpgen_sherpa_jet_n_err*tc24_alpgen_sherpa_ratio);

      h_ratio_alpgen_sherpa_jet_n->SetBinContent(b,tc24_alpgen_sherpa_ratio);
      h_ratio_alpgen_sherpa_jet_n->SetBinError(b,tc24_alpgen_sherpa_ratio_err);
    }
    

    if(tc24_alpgen_nom_bin_n && tc24_alpgen_iqopt3_bin_n) {

      // //Error calc (see histogrampainter for clarification)
      double tc24_abs_alpgen_iqopt3_err = sqrt(pow(tc24_alpgen_nom_bin_err,2.)+pow(tc24_alpgen_iqopt3_bin_err,2.));
      double tc24_rel_alpgen_iqopt3_err = tc24_abs_alpgen_iqopt3_err/(tc24_alpgen_nom_bin_n-tc24_alpgen_iqopt3_bin_n);
      double tc24_rel_iqopt3_err = tc24_alpgen_iqopt3_bin_err/tc24_alpgen_iqopt3_bin_n;
      
      double tc24_rel_ratio_alpgen_iqopt3_jet_n_err = sqrt(pow(tc24_rel_alpgen_iqopt3_err,2.)+pow(tc24_rel_iqopt3_err,2.));

      double tc24_alpgen_iqopt3_ratio = (tc24_alpgen_nom_bin_n-tc24_alpgen_iqopt3_bin_n)/tc24_alpgen_iqopt3_bin_n;

      double tc24_alpgen_iqopt3_ratio_err = fabs(tc24_rel_ratio_alpgen_iqopt3_jet_n_err*tc24_alpgen_iqopt3_ratio);

      h_ratio_alpgen_iqopt3_jet_n->SetBinContent(b,tc24_alpgen_iqopt3_ratio);
      h_ratio_alpgen_iqopt3_jet_n->SetBinError(b,tc24_alpgen_iqopt3_ratio_err);
    }

    

    if(tc24_alpgen_nom_bin_n && tc24_alpgen_ptjmin10_bin_n) {

      // //Error calc (see histogrampainter for clarification)
      double tc24_abs_alpgen_ptjmin10_err = sqrt(pow(tc24_alpgen_nom_bin_err,2.)+pow(tc24_alpgen_ptjmin10_bin_err,2.));
      double tc24_rel_alpgen_ptjmin10_err = tc24_abs_alpgen_ptjmin10_err/(tc24_alpgen_nom_bin_n-tc24_alpgen_ptjmin10_bin_n);
      double tc24_rel_ptjmin10_err = tc24_alpgen_ptjmin10_bin_err/tc24_alpgen_ptjmin10_bin_n;
      
      double tc24_rel_ratio_alpgen_ptjmin10_jet_n_err = sqrt(pow(tc24_rel_alpgen_ptjmin10_err,2.)+pow(tc24_rel_ptjmin10_err,2.));

      double tc24_alpgen_ptjmin10_ratio = (tc24_alpgen_nom_bin_n-tc24_alpgen_ptjmin10_bin_n)/tc24_alpgen_ptjmin10_bin_n;

      double tc24_alpgen_ptjmin10_ratio_err = fabs(tc24_rel_ratio_alpgen_ptjmin10_jet_n_err*tc24_alpgen_ptjmin10_ratio);

      h_ratio_alpgen_ptjmin10_jet_n->SetBinContent(b,tc24_alpgen_ptjmin10_ratio);
      h_ratio_alpgen_ptjmin10_jet_n->SetBinError(b,tc24_alpgen_ptjmin10_ratio_err);
    }
    
  }


  h_ratio_alpgen_sherpa_jet_n->Draw("PE");
  h_ratio_alpgen_iqopt3_jet_n->Draw("PE sames");
  h_ratio_alpgen_ptjmin10_jet_n->Draw("PE sames");
  
  tc24->Update();

  tc24->SaveAs("./plots/latest/muon_jet_n.png");
    
  //NEXT
  
  //////////////////////////////////////////////////
  // tc24_5
  // jet_n: sherpa/alpgen+wjrw
  //////////////////////////////////////////////////
  
  string tc24_5_title = "Jet N (muon) w/Data";
  string tc24_5_name = "tc24_5";
  TCanvas* tc24_5 = new TCanvas(tc24_5_name.c_str(),tc24_5_title.c_str(),0,0,1920,1200);
  tc24_5->cd();

  TPad* tc24_5_pad01 = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,0.35);
  tc24_5_pad01->SetTopMargin(0.05);
  tc24_5_pad01->SetBottomMargin(0.31);
  tc24_5_pad01->Draw();

  TPad* tc24_5_pad02 = new TPad("plot_pad","plot_pad",0.01,0.35,0.99,0.99);
  tc24_5_pad02->SetBottomMargin(0.0005);
  tc24_5_pad02->SetLogy();
  tc24_5_pad02->Draw();
  tc24_5_pad02->cd();

  // Plots
  
  TH1F* h_alpgen_nom_muon_jet_n = (TH1F*) wjets_alpgen_file->Get("all/h_muon_purw_nom_jet_n");
  TH1F* h_alpgen_iqopt3_muon_jet_n = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_iqopt3_jet_n");
  TH1F* h_alpgen_ptjmin10_muon_jet_n = (TH1F*) wjets_alpgen_file->Get("all/h_muon_wjrw_ptjmin10_jet_n");
  TH1F* h_sherpa_nom_muon_jet_n = (TH1F*) wjets_sherpa_file->Get("all/h_muon_purw_nom_jet_n");
  TH1F* h_data_muon_jet_n = (TH1F*) data_file->Get("all/h_muon_purw_nom_jet_n");

  TH1F* h_top_muon_jet_n = (TH1F*) top_mcatnlo_file->Get("all/h_muon_purw_nom_jet_n");
  TH1F* h_zjets_muon_jet_n = (TH1F*) zjets_alpgen_file->Get("all/h_muon_purw_nom_jet_n");
  TH1F* h_vv_muon_jet_n = (TH1F*) vv_herwig_file->Get("all/h_muon_purw_nom_jet_n");
  TH1F* h_qcd_muon_jet_n = (TH1F*) qcd_file->Get("all/h_muon_purw_nom_jet_n");
  

  //Add Backgrounds
  h_alpgen_nom_muon_jet_n->Add(h_top_muon_jet_n);
  h_alpgen_nom_muon_jet_n->Add(h_zjets_muon_jet_n);
  h_alpgen_nom_muon_jet_n->Add(h_vv_muon_jet_n);
  h_alpgen_nom_muon_jet_n->Add(h_qcd_muon_jet_n);
  
  h_alpgen_nom_muon_jet_n->SetMarkerStyle(20);
  h_alpgen_nom_muon_jet_n->SetMarkerSize(1.2);
  h_alpgen_nom_muon_jet_n->SetTitle("");
  h_alpgen_nom_muon_jet_n->Draw("PE");

  //Add backgrounds
  h_alpgen_iqopt3_muon_jet_n->Add(h_top_muon_jet_n);
  h_alpgen_iqopt3_muon_jet_n->Add(h_zjets_muon_jet_n);
  h_alpgen_iqopt3_muon_jet_n->Add(h_vv_muon_jet_n);
  h_alpgen_iqopt3_muon_jet_n->Add(h_qcd_muon_jet_n);

  h_alpgen_iqopt3_muon_jet_n->SetMarkerStyle(22);
  h_alpgen_iqopt3_muon_jet_n->SetMarkerSize(1.2);
  h_alpgen_iqopt3_muon_jet_n->SetMarkerColor(kGreen);
  h_alpgen_iqopt3_muon_jet_n->Draw("PE sames");

  //Add Backgrounds
  h_alpgen_ptjmin10_muon_jet_n->Add(h_top_muon_jet_n);
  h_alpgen_ptjmin10_muon_jet_n->Add(h_zjets_muon_jet_n);
  h_alpgen_ptjmin10_muon_jet_n->Add(h_vv_muon_jet_n);
  h_alpgen_ptjmin10_muon_jet_n->Add(h_qcd_muon_jet_n);

  h_alpgen_ptjmin10_muon_jet_n->SetMarkerStyle(22);
  h_alpgen_ptjmin10_muon_jet_n->SetMarkerSize(1.2);
  h_alpgen_ptjmin10_muon_jet_n->SetMarkerColor(kBlue);
  h_alpgen_ptjmin10_muon_jet_n->Draw("PE sames");

  //Add Backgrounds
  h_sherpa_nom_muon_jet_n->Add(h_top_muon_jet_n);
  h_sherpa_nom_muon_jet_n->Add(h_zjets_muon_jet_n);
  h_sherpa_nom_muon_jet_n->Add(h_vv_muon_jet_n);
  h_sherpa_nom_muon_jet_n->Add(h_qcd_muon_jet_n);

  h_sherpa_nom_muon_jet_n->SetMarkerStyle(20);
  h_sherpa_nom_muon_jet_n->SetMarkerSize(1.2);
  h_sherpa_nom_muon_jet_n->SetMarkerColor(kRed);
  h_sherpa_nom_muon_jet_n->Draw("PE sames");

  h_data_muon_jet_n->Draw("sames");


  //Legend
  TLegend* lgnd_tc24_5 = new TLegend(0.15,0.15,0.28,0.35);
  lgnd_tc24_5->SetFillColor(0);
  lgnd_tc24_5->SetTextSize(0.03);
  lgnd_tc24_5->SetBorderSize(0);

  char lgnd_data_muon_jet_n_name[20];
  sprintf(lgnd_data_muon_jet_n_name,"%s,  %.2f","DATA",h_data_muon_jet_n->Integral());
  lgnd_tc24_5->AddEntry(h_data_muon_jet_n,lgnd_data_muon_jet_n_name,"f");

  char lgnd_alpgen_nom_muon_jet_n_name[20];
  sprintf(lgnd_alpgen_nom_muon_jet_n_name,"%s,  %.2f","ALPGEN (nom)",h_alpgen_nom_muon_jet_n->Integral());
  lgnd_tc24_5->AddEntry(h_alpgen_nom_muon_jet_n,lgnd_alpgen_nom_muon_jet_n_name,"p");

  char lgnd_alpgen_iqopt3_muon_jet_n_name[20];
  sprintf(lgnd_alpgen_iqopt3_muon_jet_n_name,"%s,  %.2f","ALPGEN (iqopt)",h_alpgen_iqopt3_muon_jet_n->Integral());
  lgnd_tc24_5->AddEntry(h_alpgen_iqopt3_muon_jet_n,lgnd_alpgen_iqopt3_muon_jet_n_name,"p");

  char lgnd_alpgen_ptjmin10_muon_jet_n_name[20];
  sprintf(lgnd_alpgen_ptjmin10_muon_jet_n_name,"%s,  %.2f","ALPGEN (ptjmin10)",h_alpgen_ptjmin10_muon_jet_n->Integral());
  lgnd_tc24_5->AddEntry(h_alpgen_ptjmin10_muon_jet_n,lgnd_alpgen_ptjmin10_muon_jet_n_name,"p");

  char lgnd_sherpa_nom_muon_jet_n_name[20];
  sprintf(lgnd_sherpa_nom_muon_jet_n_name,"%s,  %.2f","SHERPA (nom)",h_sherpa_nom_muon_jet_n->Integral());
  lgnd_tc24_5->AddEntry(h_sherpa_nom_muon_jet_n,lgnd_sherpa_nom_muon_jet_n_name,"p");

  lgnd_tc24_5->Draw();
  
  //////////////////////////////////////////////////
  //Ratio
  ////////////////////////////////////////////////// 

  tc24_5_pad01->cd();
  tc24_5_pad01->SetGrid();

  int n_bins = ((TAxis*) h_alpgen_nom_muon_jet_n->GetXaxis())->GetNbins();
  double x_min = ((TAxis*) h_alpgen_nom_muon_jet_n->GetXaxis())->GetXmin();
  double x_max = ((TAxis*) h_alpgen_nom_muon_jet_n->GetXaxis())->GetXmax();

  // data-alpgen(nom)/alpgen(nom)
  string tc24_5_ratio_data_alpgen_jet_n_name = "tc24_5_ratio_data_alpgen_jet_n";
  TH1F* h_ratio_data_alpgen_jet_n = new TH1F(tc24_5_ratio_data_alpgen_jet_n_name.c_str(),"",n_bins,x_min,x_max);
  h_ratio_data_alpgen_jet_n->SetMarkerStyle(8);
  //h_ratio_data_alpgen_jet_n->SetMarkerColor(kRed);

  TAxis* h_ratio_data_alpgen_jet_n_xaxis = h_ratio_data_alpgen_jet_n->GetXaxis();
  TAxis* h_ratio_data_alpgen_jet_n_yaxis = h_ratio_data_alpgen_jet_n->GetYaxis();
  
  h_ratio_data_alpgen_jet_n_xaxis->SetLabelSize(0.08);
  h_ratio_data_alpgen_jet_n_yaxis->SetLabelSize(0.08);

  h_ratio_data_alpgen_jet_n_xaxis->SetTitle("jet n");
  h_ratio_data_alpgen_jet_n_xaxis->SetTitleSize(0.07);
  h_ratio_data_alpgen_jet_n_yaxis->SetNdivisions(4,4,4);
  h_ratio_data_alpgen_jet_n_yaxis->SetTitle("(data-MC)/MC");
  h_ratio_data_alpgen_jet_n_yaxis->SetTitleSize(0.07);
  h_ratio_data_alpgen_jet_n_yaxis->SetTitleOffset(0.36);
  h_ratio_data_alpgen_jet_n_yaxis->SetRangeUser(-1,1);

  // data-sherpa(nom)/sherpa(nom)
  string tc24_5_ratio_data_sherpa_jet_n_name = "tc24_5_ratio_data_sherpa_jet_n";
  TH1F* h_ratio_data_sherpa_jet_n = new TH1F(tc24_5_ratio_data_sherpa_jet_n_name.c_str(),"",n_bins,x_min,x_max);
  h_ratio_data_sherpa_jet_n->SetMarkerStyle(8);
  h_ratio_data_sherpa_jet_n->SetMarkerColor(kRed);


  // data-alpgen(iqopt3)/alpgen(iqopt3)
  string tc24_5_ratio_data_alpgen_iqopt3_jet_n_name = "tc24_5_ratio_data_alpgen_iqopt3_jet_n";
  TH1F* h_ratio_data_alpgen_iqopt3_jet_n = new TH1F(tc24_5_ratio_data_alpgen_iqopt3_jet_n_name.c_str(),"",n_bins,x_min,x_max);
  h_ratio_data_alpgen_iqopt3_jet_n->SetMarkerStyle(8);
  h_ratio_data_alpgen_iqopt3_jet_n->SetMarkerColor(kGreen);

  // data-alpgen(ptjmin10)/alpgen(ptjmin10)
  string tc24_5_ratio_data_alpgen_ptjmin10_jet_n_name = "tc24_5_ratio_data_alpgen_ptjmin10_jet_n";
  TH1F* h_ratio_data_alpgen_ptjmin10_jet_n = new TH1F(tc24_5_ratio_data_alpgen_ptjmin10_jet_n_name.c_str(),"",n_bins,x_min,x_max);
  h_ratio_data_alpgen_ptjmin10_jet_n->SetMarkerStyle(8);
  h_ratio_data_alpgen_ptjmin10_jet_n->SetMarkerColor(kBlue);

  

  
  // // alp-iqopt3/iqopt3
  // string tc24_5_ratio_alpgen_iqopt3_jet_n_name = "tc24_5_ratio_alpgen_iqopt3_jet_n";
  // TH1F* h_ratio_alpgen_iqopt3_jet_n = new TH1F(tc24_5_ratio_alpgen_iqopt3_jet_n_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_iqopt3_jet_n->SetMarkerStyle(8);
  // h_ratio_alpgen_iqopt3_jet_n->SetMarkerColor(kGreen);

  
  // // alp-ptjmin10/ptjmin10
  // string tc24_5_ratio_alpgen_ptjmin10_jet_n_name = "tc24_5_ratio_alpgen_ptjmin10_jet_n";
  // TH1F* h_ratio_alpgen_ptjmin10_jet_n = new TH1F(tc24_5_ratio_alpgen_ptjmin10_jet_n_name.c_str(),"",n_bins,x_min,x_max);
  // h_ratio_alpgen_ptjmin10_jet_n->SetMarkerStyle(8);
  // h_ratio_alpgen_ptjmin10_jet_n->SetMarkerColor(kBlue);


  
  double tc24_5_data_alpgen_ratio=0.;
  double tc24_5_data_sherpa_ratio=0.;
  double tc24_5_data_alpgen_iqopt3_ratio=0.;
  double tc24_5_data_alpgen_ptjmin10_ratio=0.;
  
  for(int b=1;b<n_bins+1;b++){

    double tc24_5_alpgen_nom_bin_n=h_alpgen_nom_muon_jet_n->GetBinContent(b);
    double tc24_5_alpgen_nom_bin_err=h_alpgen_nom_muon_jet_n->GetBinError(b);    

    double tc24_5_data_bin_n=h_data_muon_jet_n->GetBinContent(b);
    double tc24_5_data_bin_err=h_data_muon_jet_n->GetBinError(b);    

    double tc24_5_sherpa_nom_bin_n=h_sherpa_nom_muon_jet_n->GetBinContent(b);
    double tc24_5_sherpa_nom_bin_err=h_sherpa_nom_muon_jet_n->GetBinError(b);    

    double tc24_5_alpgen_iqopt3_bin_n=h_alpgen_iqopt3_muon_jet_n->GetBinContent(b);
    double tc24_5_alpgen_iqopt3_bin_err=h_alpgen_iqopt3_muon_jet_n->GetBinError(b);

    double tc24_5_alpgen_ptjmin10_bin_n=h_alpgen_ptjmin10_muon_jet_n->GetBinContent(b);
    double tc24_5_alpgen_ptjmin10_bin_err=h_alpgen_ptjmin10_muon_jet_n->GetBinError(b);



    if(tc24_5_data_bin_n && tc24_5_alpgen_nom_bin_n) {

      // //Error calc (see histogrampainter for clarification)
      double tc24_5_abs_data_alpgen_err = sqrt(pow(tc24_5_data_bin_err,2.)+pow(tc24_5_alpgen_nom_bin_err,2.));
      double tc24_5_rel_data_alpgen_err = tc24_5_abs_data_alpgen_err/(tc24_5_data_bin_n-tc24_5_alpgen_nom_bin_n);
      double tc24_5_rel_alpgen_err = tc24_5_alpgen_nom_bin_err/tc24_5_alpgen_nom_bin_n;
      
      double tc24_5_rel_ratio_data_alpgen_jet_n_err = sqrt(pow(tc24_5_rel_data_alpgen_err,2.)+pow(tc24_5_rel_alpgen_err,2.));

      double tc24_5_data_alpgen_ratio = (tc24_5_data_bin_n-tc24_5_alpgen_nom_bin_n)/tc24_5_alpgen_nom_bin_n;

      double tc24_5_data_alpgen_ratio_err = fabs(tc24_5_rel_ratio_data_alpgen_jet_n_err*tc24_5_data_alpgen_ratio);

      h_ratio_data_alpgen_jet_n->SetBinContent(b,tc24_5_data_alpgen_ratio);
      h_ratio_data_alpgen_jet_n->SetBinError(b,tc24_5_data_alpgen_ratio_err);
    }
    

    if(tc24_5_data_bin_n && tc24_5_sherpa_nom_bin_n) {

      // //Error calc (see histogrampainter for clarification)
      double tc24_5_abs_data_sherpa_err = sqrt(pow(tc24_5_data_bin_err,2.)+pow(tc24_5_sherpa_nom_bin_err,2.));
      double tc24_5_rel_data_sherpa_err = tc24_5_abs_data_sherpa_err/(tc24_5_data_bin_n-tc24_5_sherpa_nom_bin_n);
      double tc24_5_rel_sherpa_err = tc24_5_sherpa_nom_bin_err/tc24_5_sherpa_nom_bin_n;
      
      double tc24_5_rel_ratio_data_sherpa_jet_n_err = sqrt(pow(tc24_5_rel_data_sherpa_err,2.)+pow(tc24_5_rel_sherpa_err,2.));

      double tc24_5_data_sherpa_ratio = (tc24_5_data_bin_n-tc24_5_sherpa_nom_bin_n)/tc24_5_sherpa_nom_bin_n;

      double tc24_5_data_sherpa_ratio_err = fabs(tc24_5_rel_ratio_data_sherpa_jet_n_err*tc24_5_data_sherpa_ratio);

      h_ratio_data_sherpa_jet_n->SetBinContent(b,tc24_5_data_sherpa_ratio);
      h_ratio_data_sherpa_jet_n->SetBinError(b,tc24_5_data_sherpa_ratio_err);
    }
    

    if(tc24_5_data_bin_n && tc24_5_alpgen_iqopt3_bin_n) {

      // //Error calc (see histogrampainter for clarification)
      double tc24_5_abs_data_alpgen_iqopt3_err = sqrt(pow(tc24_5_data_bin_err,2.)+pow(tc24_5_alpgen_iqopt3_bin_err,2.));
      double tc24_5_rel_data_alpgen_iqopt3_err = tc24_5_abs_data_alpgen_iqopt3_err/(tc24_5_data_bin_n-tc24_5_alpgen_iqopt3_bin_n);
      double tc24_5_rel_alpgen_iqopt3_err = tc24_5_alpgen_iqopt3_bin_err/tc24_5_alpgen_iqopt3_bin_n;
      
      double tc24_5_rel_ratio_data_alpgen_iqopt3_jet_n_err = sqrt(pow(tc24_5_rel_data_alpgen_iqopt3_err,2.)+pow(tc24_5_rel_alpgen_iqopt3_err,2.));

      double tc24_5_data_alpgen_iqopt3_ratio = (tc24_5_data_bin_n-tc24_5_alpgen_iqopt3_bin_n)/tc24_5_alpgen_iqopt3_bin_n;

      double tc24_5_data_alpgen_iqopt3_ratio_err = fabs(tc24_5_rel_ratio_data_alpgen_iqopt3_jet_n_err*tc24_5_data_alpgen_iqopt3_ratio);

      h_ratio_data_alpgen_iqopt3_jet_n->SetBinContent(b,tc24_5_data_alpgen_iqopt3_ratio);
      h_ratio_data_alpgen_iqopt3_jet_n->SetBinError(b,tc24_5_data_alpgen_iqopt3_ratio_err);
    }
    
    if(tc24_5_data_bin_n && tc24_5_alpgen_ptjmin10_bin_n) {

      // //Error calc (see histogrampainter for clarification)
      double tc24_5_abs_data_alpgen_ptjmin10_err = sqrt(pow(tc24_5_data_bin_err,2.)+pow(tc24_5_alpgen_ptjmin10_bin_err,2.));
      double tc24_5_rel_data_alpgen_ptjmin10_err = tc24_5_abs_data_alpgen_ptjmin10_err/(tc24_5_data_bin_n-tc24_5_alpgen_ptjmin10_bin_n);
      double tc24_5_rel_alpgen_ptjmin10_err = tc24_5_alpgen_ptjmin10_bin_err/tc24_5_alpgen_ptjmin10_bin_n;
      
      double tc24_5_rel_ratio_data_alpgen_ptjmin10_jet_n_err = sqrt(pow(tc24_5_rel_data_alpgen_ptjmin10_err,2.)+pow(tc24_5_rel_alpgen_ptjmin10_err,2.));

      double tc24_5_data_alpgen_ptjmin10_ratio = (tc24_5_data_bin_n-tc24_5_alpgen_ptjmin10_bin_n)/tc24_5_alpgen_ptjmin10_bin_n;

      double tc24_5_data_alpgen_ptjmin10_ratio_err = fabs(tc24_5_rel_ratio_data_alpgen_ptjmin10_jet_n_err*tc24_5_data_alpgen_ptjmin10_ratio);

      h_ratio_data_alpgen_ptjmin10_jet_n->SetBinContent(b,tc24_5_data_alpgen_ptjmin10_ratio);
      h_ratio_data_alpgen_ptjmin10_jet_n->SetBinError(b,tc24_5_data_alpgen_ptjmin10_ratio_err);
    }
    
  }



  h_ratio_data_alpgen_jet_n->Draw("PE");
  h_ratio_data_sherpa_jet_n->Draw("PE sames");
  h_ratio_data_alpgen_iqopt3_jet_n->Draw("PE sames");
  h_ratio_data_alpgen_ptjmin10_jet_n->Draw("PE sames");
  
  //  h_ratio_alpgen_iqopt3_jet_n->Draw("PE sames");
  //  h_ratio_alpgen_ptjmin10_jet_n->Draw("PE sames");
  
  tc24_5->Update();

  tc24_5->SaveAs("./plots/latest/data_muon_jet_n.png");
    
  
  return;
}
