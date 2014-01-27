////////////////////////////////////////////////////////////////////////////
// Produces plots to compare MET_RefFinal, MET_RefFinal_em and MET_LocHadTopo
////////////////////////////////////////////////////////////////////////////
#include "../include/lnuj_bkgd_list.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <vector>

#include <TCanvas.h>
#include <TLegend.h>
#include "TH1.h"
#include <TFile.h>

void metSystematics(){

  gROOT->SetStyle("Plain");  
  gStyle->SetOptStat(0);
  gStyle->SetPalette(1);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  //gStyle->SetFillStyle(3144);
  
  gROOT->SetBatch();
  
  
  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In metSystematics.C"<<endl;

  const int nProcs = 2;
  string procs[nProcs] = {"elec", "muon"};

  TH1F* bkgd_all_ww_mets[nProcs];
  TH1F* bkgd_all_ww_lc_mets[nProcs];
  TH1F* bkgd_all_ww_em_mets[nProcs];

  TH1F* bkgd_all_lep_met_pts[nProcs];
  TH1F* bkgd_all_lep_lc_met_pts[nProcs];
  TH1F* bkgd_all_lep_em_met_pts[nProcs];
  
  TH1F* sig_all_m500_ww_mets[nProcs];
  TH1F* sig_all_m500_ww_lc_mets[nProcs];
  TH1F* sig_all_m500_ww_em_mets[nProcs];

  //////////////////////////////////////////////////
  // sig_lowm
  ////////////////////////////////////////////////// 
  //met
  TH1F* bkgd_sig_lowm_ww_mets[nProcs];
  TH1F* bkgd_sig_lowm_ww_lc_mets[nProcs];
  TH1F* bkgd_sig_lowm_ww_em_mets[nProcs];

  TH1F* sig_sig_lowm_m500_ww_mets[nProcs];
  TH1F* sig_sig_lowm_m500_ww_lc_mets[nProcs];
  TH1F* sig_sig_lowm_m500_ww_em_mets[nProcs];

  //lep_met_dijet_mt
  TH1F* bkgd_sig_lowm_lep_met_dijet_mts[nProcs];
  TH1F* bkgd_sig_lowm_lep_lc_met_dijet_mts[nProcs];
  TH1F* bkgd_sig_lowm_lep_em_met_dijet_mts[nProcs];

  TH1F* sig_sig_lowm_m500_lep_met_dijet_mts[nProcs];
  TH1F* sig_sig_lowm_m500_lep_lc_met_dijet_mts[nProcs];
  TH1F* sig_sig_lowm_m500_lep_em_met_dijet_mts[nProcs];
  
  //////////////////////////////////////////////////
  // sig_highm
  ////////////////////////////////////////////////// 
  //met
  TH1F* bkgd_sig_highm_ww_mets[nProcs];
  TH1F* bkgd_sig_highm_ww_lc_mets[nProcs];
  TH1F* bkgd_sig_highm_ww_em_mets[nProcs];

  TH1F* sig_sig_highm_m750_ww_mets[nProcs];
  TH1F* sig_sig_highm_m750_ww_lc_mets[nProcs];
  TH1F* sig_sig_highm_m750_ww_em_mets[nProcs];

  //lep_met_dijet_mt
  TH1F* bkgd_sig_highm_lep_met_dijet_mts[nProcs];
  TH1F* bkgd_sig_highm_lep_lc_met_dijet_mts[nProcs];
  TH1F* bkgd_sig_highm_lep_em_met_dijet_mts[nProcs];

  TH1F* sig_sig_highm_m750_lep_met_dijet_mts[nProcs];
  TH1F* sig_sig_highm_m750_lep_lc_met_dijet_mts[nProcs];
  TH1F* sig_sig_highm_m750_lep_em_met_dijet_mts[nProcs];

  //////////////////////////////////////////////////
  // Get Sig_M500 histograms
  ////////////////////////////////////////////////// 
  
  string sig_m500_name = "../plots/gww_plots/merged/mc.gww.lvjj.m500.kmpl0_1.plot.root";
  TFile* sig_m500_file = (TFile*) TFile::Open(sig_m500_name.c_str());
  TDirectory* sig_m500_all = sig_m500_file->GetDirectory("all");
  TDirectory* sig_m500_sig_lowm = sig_m500_file->GetDirectory("sig_lowm");

  string sig_m750_name = "../plots/gww_plots/merged/mc.gww.lvjj.m750.kmpl0_1.plot.root";
  TFile* sig_m750_file = (TFile*) TFile::Open(sig_m750_name.c_str());
  TDirectory* sig_m750_sig_highm = sig_m750_file->GetDirectory("sig_highm");
  
  
  for(int p=0;p<nProcs;p++){
    string cur_proc = procs[p];

    
    for(int s=0;s<nBkgds;s++){

      if(bkgd_list[s].find("gww")!=string::npos) continue;
    
      
      string cur_file = "../plots/gww_plots/merged/"+bkgd_list[s];
      cur_file+=".plot.root";
      cout<<"Loading :"<<bkgd_list[s]<<endl;
      TFile* bkgd_file = (TFile*) TFile::Open(cur_file.c_str());


      TDirectory* bkgd_all = bkgd_file->GetDirectory("all");
      TDirectory* bkgd_sig_lowm = bkgd_file->GetDirectory("sig_lowm");
      TDirectory* bkgd_sig_highm = bkgd_file->GetDirectory("sig_highm");

      //////////////////////////////////////////////////
      // all
      ////////////////////////////////////////////////// 
      string bkgd_all_ww_met_hist = "h_"+cur_proc+"_ww_met";
      TH1F* bkgd_all_ww_met = (TH1F*) bkgd_all->Get(bkgd_all_ww_met_hist.c_str());

      string bkgd_all_ww_lc_met_hist = "h_"+cur_proc+"_ww_lc_met";
      TH1F* bkgd_all_ww_lc_met = (TH1F*) bkgd_all->Get(bkgd_all_ww_lc_met_hist.c_str());

      string bkgd_all_ww_em_met_hist = "h_"+cur_proc+"_ww_em_met";
      TH1F* bkgd_all_ww_em_met = (TH1F*) bkgd_all->Get(bkgd_all_ww_em_met_hist.c_str());

      //////////////////////////////////////////////////
      // all
      ////////////////////////////////////////////////// 
      string bkgd_all_lep_met_pt_hist = "h_"+cur_proc+"_lep_met_pt";
      TH1F* bkgd_all_lep_met_pt = (TH1F*) bkgd_all->Get(bkgd_all_lep_met_pt_hist.c_str());

      string bkgd_all_lep_lc_met_pt_hist = "h_"+cur_proc+"_lep_lc_met_pt";
      TH1F* bkgd_all_lep_lc_met_pt = (TH1F*) bkgd_all->Get(bkgd_all_lep_lc_met_pt_hist.c_str());

      string bkgd_all_lep_em_met_pt_hist = "h_"+cur_proc+"_lep_em_met_pt";
      TH1F* bkgd_all_lep_em_met_pt = (TH1F*) bkgd_all->Get(bkgd_all_lep_em_met_pt_hist.c_str());

      //////////////////////////////////////////////////
      // sig_lowm
      ////////////////////////////////////////////////// 
      //met
      string bkgd_sig_lowm_ww_met_hist = "h_"+cur_proc+"_ww_met";
      TH1F* bkgd_sig_lowm_ww_met = (TH1F*) bkgd_sig_lowm->Get(bkgd_sig_lowm_ww_met_hist.c_str());

      string bkgd_sig_lowm_ww_lc_met_hist = "h_"+cur_proc+"_ww_lc_met";
      TH1F* bkgd_sig_lowm_ww_lc_met = (TH1F*) bkgd_sig_lowm->Get(bkgd_sig_lowm_ww_lc_met_hist.c_str());

      string bkgd_sig_lowm_ww_em_met_hist = "h_"+cur_proc+"_ww_em_met";
      TH1F* bkgd_sig_lowm_ww_em_met = (TH1F*) bkgd_sig_lowm->Get(bkgd_sig_lowm_ww_em_met_hist.c_str());

      //lep_met_dijet_mt
      string bkgd_sig_lowm_lep_met_dijet_mt_hist = "h_"+cur_proc+"_lep_met_dijet_mt";
      TH1F* bkgd_sig_lowm_lep_met_dijet_mt =
	(TH1F*) bkgd_sig_lowm->Get(bkgd_sig_lowm_lep_met_dijet_mt_hist.c_str());

      string bkgd_sig_lowm_lep_lc_met_dijet_mt_hist = "h_"+cur_proc+"_lep_lc_met_dijet_mt";
      TH1F* bkgd_sig_lowm_lep_lc_met_dijet_mt =
	(TH1F*) bkgd_sig_lowm->Get(bkgd_sig_lowm_lep_lc_met_dijet_mt_hist.c_str());

      string bkgd_sig_lowm_lep_em_met_dijet_mt_hist = "h_"+cur_proc+"_lep_em_met_dijet_mt";
      TH1F* bkgd_sig_lowm_lep_em_met_dijet_mt =
	(TH1F*) bkgd_sig_lowm->Get(bkgd_sig_lowm_lep_em_met_dijet_mt_hist.c_str());

      //////////////////////////////////////////////////
      // sig_highm
      ////////////////////////////////////////////////// 
      //met
      string bkgd_sig_highm_ww_met_hist = "h_"+cur_proc+"_ww_met";
      TH1F* bkgd_sig_highm_ww_met = (TH1F*) bkgd_sig_highm->Get(bkgd_sig_highm_ww_met_hist.c_str());

      string bkgd_sig_highm_ww_lc_met_hist = "h_"+cur_proc+"_ww_lc_met";
      TH1F* bkgd_sig_highm_ww_lc_met = (TH1F*) bkgd_sig_highm->Get(bkgd_sig_highm_ww_lc_met_hist.c_str());

      string bkgd_sig_highm_ww_em_met_hist = "h_"+cur_proc+"_ww_em_met";
      TH1F* bkgd_sig_highm_ww_em_met = (TH1F*) bkgd_sig_highm->Get(bkgd_sig_highm_ww_em_met_hist.c_str());

      //lep_met_dijet_mt
      string bkgd_sig_highm_lep_met_dijet_mt_hist = "h_"+cur_proc+"_lep_met_dijet_mt";
      TH1F* bkgd_sig_highm_lep_met_dijet_mt =
	(TH1F*) bkgd_sig_highm->Get(bkgd_sig_highm_lep_met_dijet_mt_hist.c_str());

      string bkgd_sig_highm_lep_lc_met_dijet_mt_hist = "h_"+cur_proc+"_lep_lc_met_dijet_mt";
      TH1F* bkgd_sig_highm_lep_lc_met_dijet_mt =
	(TH1F*) bkgd_sig_highm->Get(bkgd_sig_highm_lep_lc_met_dijet_mt_hist.c_str());

      string bkgd_sig_highm_lep_em_met_dijet_mt_hist = "h_"+cur_proc+"_lep_em_met_dijet_mt";
      TH1F* bkgd_sig_highm_lep_em_met_dijet_mt =
	(TH1F*) bkgd_sig_highm->Get(bkgd_sig_highm_lep_em_met_dijet_mt_hist.c_str());

      
      if(!s){
	//met
	bkgd_all_ww_mets[p]=bkgd_all_ww_met;
	bkgd_all_ww_lc_mets[p]=bkgd_all_ww_lc_met;	
	bkgd_all_ww_em_mets[p]=bkgd_all_ww_em_met;

	//lep_met_pt
	bkgd_all_lep_met_pts[p]=bkgd_all_lep_met_pt;
	bkgd_all_lep_lc_met_pts[p]=bkgd_all_lep_lc_met_pt;	
	bkgd_all_lep_em_met_pts[p]=bkgd_all_lep_em_met_pt;


	//////////////////////////////////////////////////
	// sig_lowm
	////////////////////////////////////////////////// 
	//met
	bkgd_sig_lowm_ww_mets[p]=bkgd_sig_lowm_ww_met;
	bkgd_sig_lowm_ww_em_mets[p]=bkgd_sig_lowm_ww_em_met;
	bkgd_sig_lowm_ww_lc_mets[p]=bkgd_sig_lowm_ww_lc_met;	

	//lep_met_dijet_mt
	bkgd_sig_lowm_lep_met_dijet_mts[p]=bkgd_sig_lowm_lep_met_dijet_mt;
	bkgd_sig_lowm_lep_em_met_dijet_mts[p]=bkgd_sig_lowm_lep_em_met_dijet_mt;
	bkgd_sig_lowm_lep_lc_met_dijet_mts[p]=bkgd_sig_lowm_lep_lc_met_dijet_mt;	

	//////////////////////////////////////////////////
	// sig_highm
	////////////////////////////////////////////////// 
	//met
	bkgd_sig_highm_ww_mets[p]=bkgd_sig_highm_ww_met;
	bkgd_sig_highm_ww_em_mets[p]=bkgd_sig_highm_ww_em_met;
	bkgd_sig_highm_ww_lc_mets[p]=bkgd_sig_highm_ww_lc_met;	

	//lep_met_dijet_met
	bkgd_sig_highm_lep_met_dijet_mts[p]=bkgd_sig_highm_lep_met_dijet_mt;
	bkgd_sig_highm_lep_em_met_dijet_mts[p]=bkgd_sig_highm_lep_em_met_dijet_mt;
	bkgd_sig_highm_lep_lc_met_dijet_mts[p]=bkgd_sig_highm_lep_lc_met_dijet_mt;	

      }else{

	//met
	bkgd_all_ww_mets[p]->Add(bkgd_all_ww_met);
	bkgd_all_ww_em_mets[p]->Add(bkgd_all_ww_em_met);
	bkgd_all_ww_lc_mets[p]->Add(bkgd_all_ww_lc_met);

	//lep_met_pt
	bkgd_all_lep_met_pts[p]->Add(bkgd_all_lep_met_pt);
	bkgd_all_lep_em_met_pts[p]->Add(bkgd_all_lep_em_met_pt);
	bkgd_all_lep_lc_met_pts[p]->Add(bkgd_all_lep_lc_met_pt);

	//////////////////////////////////////////////////
	// sig_lowm
	////////////////////////////////////////////////// 
	//met
	bkgd_sig_lowm_ww_mets[p]->Add(bkgd_sig_lowm_ww_met);
	bkgd_sig_lowm_ww_em_mets[p]->Add(bkgd_sig_lowm_ww_em_met);
	bkgd_sig_lowm_ww_lc_mets[p]->Add(bkgd_sig_lowm_ww_lc_met);
	//lep_met_dijet_mt
	bkgd_sig_lowm_lep_met_dijet_mts[p]->Add(bkgd_sig_lowm_lep_met_dijet_mt);
	bkgd_sig_lowm_lep_em_met_dijet_mts[p]->Add(bkgd_sig_lowm_lep_em_met_dijet_mt);
	bkgd_sig_lowm_lep_lc_met_dijet_mts[p]->Add(bkgd_sig_lowm_lep_lc_met_dijet_mt);

	//////////////////////////////////////////////////
	// sig_highm
	////////////////////////////////////////////////// 
	//met
	bkgd_sig_highm_ww_mets[p]->Add(bkgd_sig_highm_ww_met);
	bkgd_sig_highm_ww_em_mets[p]->Add(bkgd_sig_highm_ww_em_met);
	bkgd_sig_highm_ww_lc_mets[p]->Add(bkgd_sig_highm_ww_lc_met);
	//lep_met_dijet_mt
	bkgd_sig_highm_lep_met_dijet_mts[p]->Add(bkgd_sig_highm_lep_met_dijet_mt);
	bkgd_sig_highm_lep_em_met_dijet_mts[p]->Add(bkgd_sig_highm_lep_em_met_dijet_mt);
	bkgd_sig_highm_lep_lc_met_dijet_mts[p]->Add(bkgd_sig_highm_lep_lc_met_dijet_mt);
      }
    }

    string sig_all_m500_ww_met_hist = "h_"+cur_proc+"_ww_met";
    TH1F* sig_all_m500_ww_met = (TH1F*) sig_m500_all->Get(sig_all_m500_ww_met_hist.c_str());
    
    string sig_all_m500_ww_lc_met_hist = "h_"+cur_proc+"_ww_lc_met";
    TH1F* sig_all_m500_ww_lc_met = (TH1F*) sig_m500_all->Get(sig_all_m500_ww_lc_met_hist.c_str());
    
    string sig_all_m500_ww_em_met_hist = "h_"+cur_proc+"_ww_em_met";
    TH1F* sig_all_m500_ww_em_met = (TH1F*) sig_m500_all->Get(sig_all_m500_ww_em_met_hist.c_str());
    
    sig_all_m500_ww_mets[p]=sig_all_m500_ww_met;
    sig_all_m500_ww_lc_mets[p]=sig_all_m500_ww_lc_met;
    sig_all_m500_ww_em_mets[p]=sig_all_m500_ww_em_met;    

    //////////////////////////////////////////////////
    // sig_lowm
    ////////////////////////////////////////////////// 
    //met
    string sig_sig_lowm_m500_ww_met_hist = "h_"+cur_proc+"_ww_met";
    TH1F* sig_sig_lowm_m500_ww_met = (TH1F*) sig_m500_sig_lowm->Get(sig_sig_lowm_m500_ww_met_hist.c_str());
    
    string sig_sig_lowm_m500_ww_lc_met_hist = "h_"+cur_proc+"_ww_lc_met";
    TH1F* sig_sig_lowm_m500_ww_lc_met = (TH1F*) sig_m500_sig_lowm->Get(sig_sig_lowm_m500_ww_lc_met_hist.c_str());
    
    string sig_sig_lowm_m500_ww_em_met_hist = "h_"+cur_proc+"_ww_em_met";
    TH1F* sig_sig_lowm_m500_ww_em_met = (TH1F*) sig_m500_sig_lowm->Get(sig_sig_lowm_m500_ww_em_met_hist.c_str());
    
    sig_sig_lowm_m500_ww_mets[p]=sig_sig_lowm_m500_ww_met;
    sig_sig_lowm_m500_ww_lc_mets[p]=sig_sig_lowm_m500_ww_lc_met;
    sig_sig_lowm_m500_ww_em_mets[p]=sig_sig_lowm_m500_ww_em_met;    

    //lep_met_dijet_mt_dijet_mt
    string sig_sig_lowm_m500_lep_met_dijet_mt_hist = "h_"+cur_proc+"_lep_met_dijet_mt";
    TH1F* sig_sig_lowm_m500_lep_met_dijet_mt =
      (TH1F*) sig_m500_sig_lowm->Get(sig_sig_lowm_m500_lep_met_dijet_mt_hist.c_str());
    
    string sig_sig_lowm_m500_lep_lc_met_dijet_mt_hist = "h_"+cur_proc+"_lep_lc_met_dijet_mt";
    TH1F* sig_sig_lowm_m500_lep_lc_met_dijet_mt =
      (TH1F*) sig_m500_sig_lowm->Get(sig_sig_lowm_m500_lep_lc_met_dijet_mt_hist.c_str());
    
    string sig_sig_lowm_m500_lep_em_met_dijet_mt_hist = "h_"+cur_proc+"_lep_em_met_dijet_mt";
    TH1F* sig_sig_lowm_m500_lep_em_met_dijet_mt =
      (TH1F*) sig_m500_sig_lowm->Get(sig_sig_lowm_m500_lep_em_met_dijet_mt_hist.c_str());
    
    sig_sig_lowm_m500_lep_met_dijet_mts[p]=sig_sig_lowm_m500_lep_met_dijet_mt;
    sig_sig_lowm_m500_lep_lc_met_dijet_mts[p]=sig_sig_lowm_m500_lep_lc_met_dijet_mt;
    sig_sig_lowm_m500_lep_em_met_dijet_mts[p]=sig_sig_lowm_m500_lep_em_met_dijet_mt;    

    //////////////////////////////////////////////////
    // sig_highm
    ////////////////////////////////////////////////// 
    //met
    string sig_sig_highm_m750_ww_met_hist = "h_"+cur_proc+"_ww_met";
    TH1F* sig_sig_highm_m750_ww_met = (TH1F*) sig_m750_sig_highm->Get(sig_sig_highm_m750_ww_met_hist.c_str());
    
    string sig_sig_highm_m750_ww_lc_met_hist = "h_"+cur_proc+"_ww_lc_met";
    TH1F* sig_sig_highm_m750_ww_lc_met = (TH1F*) sig_m750_sig_highm->Get(sig_sig_highm_m750_ww_lc_met_hist.c_str());
    
    string sig_sig_highm_m750_ww_em_met_hist = "h_"+cur_proc+"_ww_em_met";
    TH1F* sig_sig_highm_m750_ww_em_met = (TH1F*) sig_m750_sig_highm->Get(sig_sig_highm_m750_ww_em_met_hist.c_str());
    
    sig_sig_highm_m750_ww_mets[p]=sig_sig_highm_m750_ww_met;
    sig_sig_highm_m750_ww_lc_mets[p]=sig_sig_highm_m750_ww_lc_met;
    sig_sig_highm_m750_ww_em_mets[p]=sig_sig_highm_m750_ww_em_met;    

    //lep_met_dijet_mt
    string sig_sig_highm_m750_lep_met_dijet_mt_hist = "h_"+cur_proc+"_lep_met_dijet_mt";
    TH1F* sig_sig_highm_m750_lep_met_dijet_mt = (TH1F*) sig_m750_sig_highm->Get(sig_sig_highm_m750_lep_met_dijet_mt_hist.c_str());
    
    string sig_sig_highm_m750_lep_lc_met_dijet_mt_hist = "h_"+cur_proc+"_lep_lc_met_dijet_mt";
    TH1F* sig_sig_highm_m750_lep_lc_met_dijet_mt = (TH1F*) sig_m750_sig_highm->Get(sig_sig_highm_m750_lep_lc_met_dijet_mt_hist.c_str());
    
    string sig_sig_highm_m750_lep_em_met_dijet_mt_hist = "h_"+cur_proc+"_lep_em_met_dijet_mt";
    TH1F* sig_sig_highm_m750_lep_em_met_dijet_mt = (TH1F*) sig_m750_sig_highm->Get(sig_sig_highm_m750_lep_em_met_dijet_mt_hist.c_str());
    
    sig_sig_highm_m750_lep_met_dijet_mts[p]=sig_sig_highm_m750_lep_met_dijet_mt;
    sig_sig_highm_m750_lep_lc_met_dijet_mts[p]=sig_sig_highm_m750_lep_lc_met_dijet_mt;
    sig_sig_highm_m750_lep_em_met_dijet_mts[p]=sig_sig_highm_m750_lep_em_met_dijet_mt;    

  }

  cout<<endl;
  cout<<"yields"<<endl;
  cout<<endl;
  cout<<"all"<<endl;
  for(int i=0;i<nProcs;i++){
    cout<<procs[i]<<endl;
    cout<<"ww_met:\t\t S/sqrt(B):\t "<<sig_all_m500_ww_mets[i]->Integral()/sqrt(bkgd_all_ww_mets[i]->Integral());
    cout<<"  \t S/B: "<<sig_all_m500_ww_mets[i]->Integral()/bkgd_all_ww_mets[i]->Integral()<<endl;
    cout<<"ww_lc_met:\t S/sqrt(B):\t "<<sig_all_m500_ww_lc_mets[i]->Integral()/sqrt(bkgd_all_ww_lc_mets[i]->Integral());
    cout<<"  \t S/B: "<<sig_all_m500_ww_lc_mets[i]->Integral()/bkgd_all_ww_lc_mets[i]->Integral()<<endl;
    cout<<"ww_em_met:\t S/sqrt(B):\t "<<sig_all_m500_ww_em_mets[i]->Integral()/sqrt(bkgd_all_ww_em_mets[i]->Integral());
    cout<<"  \t S/B: "<<sig_all_m500_ww_em_mets[i]->Integral()/bkgd_all_ww_em_mets[i]->Integral()<<endl;

  }
  cout<<endl;
  cout<<"sig_lowm"<<endl;
  for(int i=0;i<nProcs;i++){
    cout<<"** "<<procs[i]<<" **"<<endl;

    cout<<"ww_met:\t\t S/sqrt(B):\t "<<sig_sig_lowm_m500_ww_mets[i]->Integral()/sqrt(bkgd_sig_lowm_ww_mets[i]->Integral());
    cout<<"  \t S/B: "<<sig_sig_lowm_m500_ww_mets[i]->Integral()/bkgd_sig_lowm_ww_mets[i]->Integral()<<endl;
    cout<<"n_bkgd:\t"<<bkgd_sig_lowm_ww_mets[i]->Integral()<<"  n_sig:\t"<<sig_sig_lowm_m500_ww_mets[i]->Integral()<<endl;
    cout<<endl;

    cout<<"ww_em_met:\t S/sqrt(B):\t "<<sig_sig_lowm_m500_ww_em_mets[i]->Integral()/sqrt(bkgd_sig_lowm_ww_em_mets[i]->Integral());
    cout<<"  \t S/B: "<<sig_sig_lowm_m500_ww_em_mets[i]->Integral()/bkgd_sig_lowm_ww_em_mets[i]->Integral()<<endl;
    cout<<"n_bkgd:\t"<<bkgd_sig_lowm_ww_em_mets[i]->Integral()<<"  n_sig:\t"<<sig_sig_lowm_m500_ww_em_mets[i]->Integral()<<endl;
        cout<<endl;
    cout<<"ww_lc_met:\t S/sqrt(B):\t "<<sig_sig_lowm_m500_ww_lc_mets[i]->Integral()/sqrt(bkgd_sig_lowm_ww_lc_mets[i]->Integral());
    cout<<"  \t S/B: "<<sig_sig_lowm_m500_ww_lc_mets[i]->Integral()/bkgd_sig_lowm_ww_lc_mets[i]->Integral()<<endl;
    cout<<"n_bkgd:\t"<<bkgd_sig_lowm_ww_lc_mets[i]->Integral()<<"  n_sig:\t"<<sig_sig_lowm_m500_ww_lc_mets[i]->Integral()<<endl;
    cout<<endl;  

  }
  
  cout<<endl;
  cout<<endl;
  cout<<"sig_highm"<<endl;
  for(int i=0;i<nProcs;i++){
    cout<<"** "<<procs[i]<<" **"<<endl;

    cout<<"ww_met:\t\t S/sqrt(B):\t "<<sig_sig_highm_m750_ww_mets[i]->Integral()/sqrt(bkgd_sig_highm_ww_mets[i]->Integral());
    cout<<"  \t S/B: "<<sig_sig_highm_m750_ww_mets[i]->Integral()/bkgd_sig_highm_ww_mets[i]->Integral()<<endl;
    cout<<"n_bkgd:\t"<<bkgd_sig_highm_ww_mets[i]->Integral()<<"  n_sig:\t"<<sig_sig_highm_m750_ww_mets[i]->Integral()<<endl;
    cout<<endl;
    cout<<"ww_em_met:\t S/sqrt(B):\t "<<sig_sig_highm_m750_ww_em_mets[i]->Integral()/sqrt(bkgd_sig_highm_ww_em_mets[i]->Integral());
    cout<<"  \t S/B: "<<sig_sig_highm_m750_ww_em_mets[i]->Integral()/bkgd_sig_highm_ww_em_mets[i]->Integral()<<endl;
    cout<<"n_bkgd:\t"<<bkgd_sig_highm_ww_em_mets[i]->Integral()<<"  n_sig:\t"<<sig_sig_highm_m750_ww_em_mets[i]->Integral()<<endl;
        cout<<endl;
    cout<<"ww_lc_met:\t S/sqrt(B):\t "<<sig_sig_highm_m750_ww_lc_mets[i]->Integral()/sqrt(bkgd_sig_highm_ww_lc_mets[i]->Integral());
    cout<<"  \t S/B: "<<sig_sig_highm_m750_ww_lc_mets[i]->Integral()/bkgd_sig_highm_ww_lc_mets[i]->Integral()<<endl;
    cout<<"n_bkgd:\t"<<bkgd_sig_highm_ww_lc_mets[i]->Integral()<<"  n_sig:\t"<<sig_sig_highm_m750_ww_lc_mets[i]->Integral()<<endl;
    cout<<endl;
  }
  cout<<endl;
  //////////////////////////////////////////////////
  // Plots
  ////////////////////////////////////////////////// 

  TCanvas* tc_all_ww_met[nProcs];
  TLegend* lgnd_all_ww_met[nProcs];
  for(int i=0;i<nProcs;i++){

    string cur_tc_name = "tc_bkgds_all_"+procs[i]+"_ww_met";
    string cur_tc_title = cur_tc_name;
    tc_all_ww_met[i] = new TCanvas(cur_tc_name.c_str(),cur_tc_title.c_str(),0,0,1920,1200);


    bkgd_all_ww_mets[i]->SetLineColor(kBlack);
    bkgd_all_ww_mets[i]->SetLineWidth(2);
    bkgd_all_ww_mets[i]->Draw();
    bkgd_all_ww_em_mets[i]->SetLineColor(kGreen);
    bkgd_all_ww_em_mets[i]->SetLineWidth(2);
    bkgd_all_ww_em_mets[i]->Draw("sames");
    bkgd_all_ww_lc_mets[i]->SetLineColor(kRed);
    bkgd_all_ww_lc_mets[i]->SetLineWidth(2);
    bkgd_all_ww_lc_mets[i]->Draw("sames");    

    tc_all_ww_met[i]->SetLogy();

    lgnd_all_ww_met[i] = new TLegend(0.62,0.7,0.9,0.9);
    lgnd_all_ww_met[i]->SetFillColor(0);
    lgnd_all_ww_met[i]->SetTextSize(0.03);
    lgnd_all_ww_met[i]->AddEntry(bkgd_all_ww_mets[i],"MET_RefFinal","L");
    lgnd_all_ww_met[i]->AddEntry(bkgd_all_ww_em_mets[i],"MET_RefFinal_em","L");
    lgnd_all_ww_met[i]->AddEntry(bkgd_all_ww_lc_mets[i],"MET_LocHadTopo","L");
    lgnd_all_ww_met[i]->Draw();

    tc_all_ww_met[i]->Update();
    string cur_saveas = "./plots/latest/bkgds_all_"+procs[i]+"_ww_met.png";
    tc_all_ww_met[i]->SaveAs(cur_saveas.c_str());

  }


  TCanvas* tc_all_lep_met_pt[nProcs];
  TLegend* lgnd_all_lep_met_pt[nProcs];
  for(int i=0;i<nProcs;i++){

    string cur_tc_name = "tc_bkgds_all_"+procs[i]+"_lep_met_pt";
    string cur_tc_title = cur_tc_name;
    tc_all_lep_met_pt[i] = new TCanvas(cur_tc_name.c_str(),cur_tc_title.c_str(),0,0,1920,1200);


    bkgd_all_lep_met_pts[i]->SetLineColor(kBlack);
    bkgd_all_lep_met_pts[i]->SetLineWidth(2);
    bkgd_all_lep_met_pts[i]->Draw();
    bkgd_all_lep_em_met_pts[i]->SetLineColor(kGreen);
    bkgd_all_lep_em_met_pts[i]->SetLineWidth(2);
    bkgd_all_lep_em_met_pts[i]->Draw("sames");
    bkgd_all_lep_lc_met_pts[i]->SetLineColor(kRed);
    bkgd_all_lep_lc_met_pts[i]->SetLineWidth(2);
    bkgd_all_lep_lc_met_pts[i]->Draw("sames");    

    tc_all_lep_met_pt[i]->SetLogy();

    lgnd_all_lep_met_pt[i] = new TLegend(0.62,0.7,0.9,0.9);
    lgnd_all_lep_met_pt[i]->SetFillColor(0);
    lgnd_all_lep_met_pt[i]->SetTextSize(0.03);
    lgnd_all_lep_met_pt[i]->AddEntry(bkgd_all_lep_met_pts[i],"MET_RefFinal","L");
    lgnd_all_lep_met_pt[i]->AddEntry(bkgd_all_lep_em_met_pts[i],"MET_RefFinal_em","L");
    lgnd_all_lep_met_pt[i]->AddEntry(bkgd_all_lep_lc_met_pts[i],"MET_LocHadTopo","L");
    lgnd_all_lep_met_pt[i]->Draw();

    tc_all_lep_met_pt[i]->Update();
    string cur_saveas = "./plots/latest/bkgds_all_"+procs[i]+"_lep_met_pt.png";
    tc_all_lep_met_pt[i]->SaveAs(cur_saveas.c_str());

  }


  TCanvas* tc_sig_sig_lowm_ww_met[nProcs];
  TLegend* lgnd_sig_sig_lowm_ww_met[nProcs];
  for(int i=0;i<nProcs;i++){

    string cur_tc_name = "tc_sig_sig_lowm_"+procs[i]+"_ww_met";
    string cur_tc_title = cur_tc_name;
    tc_sig_sig_lowm_ww_met[i] = new TCanvas(cur_tc_name.c_str(),cur_tc_title.c_str(),0,0,1920,1200);


    sig_sig_lowm_m500_ww_mets[i]->SetLineColor(kBlack);
    sig_sig_lowm_m500_ww_mets[i]->SetLineWidth(2);
    sig_sig_lowm_m500_ww_mets[i]->Draw();
    sig_sig_lowm_m500_ww_em_mets[i]->SetLineColor(kGreen);
    sig_sig_lowm_m500_ww_em_mets[i]->SetLineWidth(2);
    sig_sig_lowm_m500_ww_em_mets[i]->Draw("sames");
    sig_sig_lowm_m500_ww_lc_mets[i]->SetLineColor(kRed);
    sig_sig_lowm_m500_ww_lc_mets[i]->SetLineWidth(2);
    sig_sig_lowm_m500_ww_lc_mets[i]->Draw("sames");    

    tc_sig_sig_lowm_ww_met[i]->SetLogy();

    lgnd_sig_sig_lowm_ww_met[i] = new TLegend(0.62,0.7,0.9,0.9);
    lgnd_sig_sig_lowm_ww_met[i]->SetFillColor(0);
    lgnd_sig_sig_lowm_ww_met[i]->SetTextSize(0.03);
    lgnd_sig_sig_lowm_ww_met[i]->AddEntry(sig_sig_lowm_m500_ww_mets[i],"MET_RefFinal","L");
    lgnd_sig_sig_lowm_ww_met[i]->AddEntry(sig_sig_lowm_m500_ww_em_mets[i],"MET_RefFinal_em","L");
    lgnd_sig_sig_lowm_ww_met[i]->AddEntry(sig_sig_lowm_m500_ww_lc_mets[i],"MET_LocHadTopo","L");
    lgnd_sig_sig_lowm_ww_met[i]->Draw();

    tc_sig_sig_lowm_ww_met[i]->Update();
    string cur_saveas = "./plots/latest/sig_sig_lowm_"+procs[i]+"_ww_met.png";
    tc_sig_sig_lowm_ww_met[i]->SaveAs(cur_saveas.c_str());

  }
  

  TCanvas* tc_sig_sig_highm_ww_met[nProcs];
  TLegend* lgnd_sig_sig_highm_ww_met[nProcs];
  for(int i=0;i<nProcs;i++){

    string cur_tc_name = "tc_sig_sig_highm_"+procs[i]+"_ww_met";
    string cur_tc_title = cur_tc_name;
    tc_sig_sig_highm_ww_met[i] = new TCanvas(cur_tc_name.c_str(),cur_tc_title.c_str(),0,0,1920,1200);


    sig_sig_highm_m750_ww_mets[i]->SetLineColor(kBlack);
    sig_sig_highm_m750_ww_mets[i]->SetLineWidth(2);
    sig_sig_highm_m750_ww_mets[i]->Draw();
    sig_sig_highm_m750_ww_em_mets[i]->SetLineColor(kGreen);
    sig_sig_highm_m750_ww_em_mets[i]->SetLineWidth(2);
    sig_sig_highm_m750_ww_em_mets[i]->Draw("sames");
    sig_sig_highm_m750_ww_lc_mets[i]->SetLineColor(kRed);
    sig_sig_highm_m750_ww_lc_mets[i]->SetLineWidth(2);
    sig_sig_highm_m750_ww_lc_mets[i]->Draw("sames");    

    tc_sig_sig_highm_ww_met[i]->SetLogy();

    lgnd_sig_sig_highm_ww_met[i] = new TLegend(0.62,0.7,0.9,0.9);
    lgnd_sig_sig_highm_ww_met[i]->SetFillColor(0);
    lgnd_sig_sig_highm_ww_met[i]->SetTextSize(0.03);
    lgnd_sig_sig_highm_ww_met[i]->AddEntry(sig_sig_highm_m750_ww_mets[i],"MET_RefFinal","L");
    lgnd_sig_sig_highm_ww_met[i]->AddEntry(sig_sig_highm_m750_ww_em_mets[i],"MET_RefFinal_em","L");
    lgnd_sig_sig_highm_ww_met[i]->AddEntry(sig_sig_highm_m750_ww_lc_mets[i],"MET_LocHadTopo","L");
    lgnd_sig_sig_highm_ww_met[i]->Draw();

    tc_sig_sig_highm_ww_met[i]->Update();
    string cur_saveas = "./plots/latest/sig_sig_highm_"+procs[i]+"_ww_met.png";
    tc_sig_sig_highm_ww_met[i]->SaveAs(cur_saveas.c_str());

  }
  
  TCanvas* tc_sig_sig_lowm_lep_met_dijet_mts[nProcs];
  TLegend* lgnd_sig_sig_lowm_lep_met_dijet_mts[nProcs];
  for(int i=0;i<nProcs;i++){

    string cur_tc_name = "tc_sig_sig_lowm_"+procs[i]+"_lep_met_dijet_mt";
    string cur_tc_title = cur_tc_name;
    tc_sig_sig_lowm_lep_met_dijet_mts[i] = new TCanvas(cur_tc_name.c_str(),cur_tc_title.c_str(),0,0,1920,1200);


    sig_sig_lowm_m500_lep_met_dijet_mts[i]->SetLineColor(kBlack);
    sig_sig_lowm_m500_lep_met_dijet_mts[i]->SetLineWidth(2);
    sig_sig_lowm_m500_lep_met_dijet_mts[i]->Draw();
    sig_sig_lowm_m500_lep_em_met_dijet_mts[i]->SetLineColor(kGreen);
    sig_sig_lowm_m500_lep_em_met_dijet_mts[i]->SetLineWidth(2);
    sig_sig_lowm_m500_lep_em_met_dijet_mts[i]->Draw("sames");
    sig_sig_lowm_m500_lep_lc_met_dijet_mts[i]->SetLineColor(kRed);
    sig_sig_lowm_m500_lep_lc_met_dijet_mts[i]->SetLineWidth(2);
    sig_sig_lowm_m500_lep_lc_met_dijet_mts[i]->Draw("sames");    

    tc_sig_sig_lowm_lep_met_dijet_mts[i]->SetLogy();

    lgnd_sig_sig_lowm_lep_met_dijet_mts[i] = new TLegend(0.62,0.7,0.9,0.9);
    lgnd_sig_sig_lowm_lep_met_dijet_mts[i]->SetFillColor(0);
    lgnd_sig_sig_lowm_lep_met_dijet_mts[i]->SetTextSize(0.03);
    lgnd_sig_sig_lowm_lep_met_dijet_mts[i]->AddEntry(sig_sig_lowm_m500_lep_met_dijet_mts[i],"MET_RefFinal","L");
    lgnd_sig_sig_lowm_lep_met_dijet_mts[i]->AddEntry(sig_sig_lowm_m500_lep_em_met_dijet_mts[i],"MET_RefFinal_em","L");
    lgnd_sig_sig_lowm_lep_met_dijet_mts[i]->AddEntry(sig_sig_lowm_m500_lep_lc_met_dijet_mts[i],"MET_LocHadTopo","L");
    lgnd_sig_sig_lowm_lep_met_dijet_mts[i]->Draw();

    tc_sig_sig_lowm_lep_met_dijet_mts[i]->Update();
    string cur_saveas = "./plots/latest/sig_sig_lowm_"+procs[i]+"_lep_met_dijet_mt.png";
    tc_sig_sig_lowm_lep_met_dijet_mts[i]->SaveAs(cur_saveas.c_str());

  }


  TCanvas* tc_sig_sig_highm_lep_met_dijet_mts[nProcs];
  TLegend* lgnd_sig_sig_highm_lep_met_dijet_mts[nProcs];
  for(int i=0;i<nProcs;i++){

    string cur_tc_name = "tc_sig_sig_highm_"+procs[i]+"_lep_met_dijet_mt";
    string cur_tc_title = cur_tc_name;
    tc_sig_sig_highm_lep_met_dijet_mts[i] = new TCanvas(cur_tc_name.c_str(),cur_tc_title.c_str(),0,0,1920,1200);


    sig_sig_highm_m750_lep_met_dijet_mts[i]->SetLineColor(kBlack);
    sig_sig_highm_m750_lep_met_dijet_mts[i]->SetLineWidth(2);
    sig_sig_highm_m750_lep_met_dijet_mts[i]->Draw();
    sig_sig_highm_m750_lep_em_met_dijet_mts[i]->SetLineColor(kGreen);
    sig_sig_highm_m750_lep_em_met_dijet_mts[i]->SetLineWidth(2);
    sig_sig_highm_m750_lep_em_met_dijet_mts[i]->Draw("sames");
    sig_sig_highm_m750_lep_lc_met_dijet_mts[i]->SetLineColor(kRed);
    sig_sig_highm_m750_lep_lc_met_dijet_mts[i]->SetLineWidth(2);
    sig_sig_highm_m750_lep_lc_met_dijet_mts[i]->Draw("sames");    

    tc_sig_sig_highm_lep_met_dijet_mts[i]->SetLogy();

    lgnd_sig_sig_highm_lep_met_dijet_mts[i] = new TLegend(0.62,0.7,0.9,0.9);
    lgnd_sig_sig_highm_lep_met_dijet_mts[i]->SetFillColor(0);
    lgnd_sig_sig_highm_lep_met_dijet_mts[i]->SetTextSize(0.03);
    lgnd_sig_sig_highm_lep_met_dijet_mts[i]->AddEntry(sig_sig_highm_m750_lep_met_dijet_mts[i],"MET_RefFinal","L");
    lgnd_sig_sig_highm_lep_met_dijet_mts[i]->AddEntry(sig_sig_highm_m750_lep_em_met_dijet_mts[i],"MET_RefFinal_em","L");
    lgnd_sig_sig_highm_lep_met_dijet_mts[i]->AddEntry(sig_sig_highm_m750_lep_lc_met_dijet_mts[i],"MET_LocHadTopo","L");
    lgnd_sig_sig_highm_lep_met_dijet_mts[i]->Draw();

    tc_sig_sig_highm_lep_met_dijet_mts[i]->Update();
    string cur_saveas = "./plots/latest/sig_sig_highm_"+procs[i]+"_lep_met_dijet_mt.png";
    tc_sig_sig_highm_lep_met_dijet_mts[i]->SaveAs(cur_saveas.c_str());

  }
  
  TCanvas* tc_bkgd_sig_lowm_lep_met_dijet_mts[nProcs];
  TLegend* lgnd_bkgd_sig_lowm_lep_met_dijet_mts[nProcs];
  for(int i=0;i<nProcs;i++){

    string cur_tc_name = "tc_bkgd_sig_lowm_"+procs[i]+"_lep_met_dijet_mt";
    string cur_tc_title = cur_tc_name;
    tc_bkgd_sig_lowm_lep_met_dijet_mts[i] = new TCanvas(cur_tc_name.c_str(),cur_tc_title.c_str(),0,0,1920,1200);


    bkgd_sig_lowm_lep_met_dijet_mts[i]->SetLineColor(kBlack);
    bkgd_sig_lowm_lep_met_dijet_mts[i]->SetLineWidth(2);
    bkgd_sig_lowm_lep_met_dijet_mts[i]->Draw();
    bkgd_sig_lowm_lep_em_met_dijet_mts[i]->SetLineColor(kGreen);
    bkgd_sig_lowm_lep_em_met_dijet_mts[i]->SetLineWidth(2);
    bkgd_sig_lowm_lep_em_met_dijet_mts[i]->Draw("sames");
    bkgd_sig_lowm_lep_lc_met_dijet_mts[i]->SetLineColor(kRed);
    bkgd_sig_lowm_lep_lc_met_dijet_mts[i]->SetLineWidth(2);
    bkgd_sig_lowm_lep_lc_met_dijet_mts[i]->Draw("sames");    

    tc_bkgd_sig_lowm_lep_met_dijet_mts[i]->SetLogy();

    lgnd_bkgd_sig_lowm_lep_met_dijet_mts[i] = new TLegend(0.62,0.7,0.9,0.9);
    lgnd_bkgd_sig_lowm_lep_met_dijet_mts[i]->SetFillColor(0);
    lgnd_bkgd_sig_lowm_lep_met_dijet_mts[i]->SetTextSize(0.03);
    lgnd_bkgd_sig_lowm_lep_met_dijet_mts[i]->AddEntry(bkgd_sig_lowm_lep_met_dijet_mts[i],"MET_RefFinal","L");
    lgnd_bkgd_sig_lowm_lep_met_dijet_mts[i]->AddEntry(bkgd_sig_lowm_lep_em_met_dijet_mts[i],"MET_RefFinal_em","L");
    lgnd_bkgd_sig_lowm_lep_met_dijet_mts[i]->AddEntry(bkgd_sig_lowm_lep_lc_met_dijet_mts[i],"MET_LocHadTopo","L");
    lgnd_bkgd_sig_lowm_lep_met_dijet_mts[i]->Draw();

    tc_bkgd_sig_lowm_lep_met_dijet_mts[i]->Update();
    string cur_saveas = "./plots/latest/bkgd_sig_lowm_"+procs[i]+"_lep_met_dijet_mt.png";
    tc_bkgd_sig_lowm_lep_met_dijet_mts[i]->SaveAs(cur_saveas.c_str());

  }


  TCanvas* tc_bkgd_sig_highm_lep_met_dijet_mts[nProcs];
  TLegend* lgnd_bkgd_sig_highm_lep_met_dijet_mts[nProcs];
  for(int i=0;i<nProcs;i++){

    string cur_tc_name = "tc_bkgd_sig_highm_"+procs[i]+"_lep_met_dijet_mt";
    string cur_tc_title = cur_tc_name;
    tc_bkgd_sig_highm_lep_met_dijet_mts[i] = new TCanvas(cur_tc_name.c_str(),cur_tc_title.c_str(),0,0,1920,1200);


    bkgd_sig_highm_lep_met_dijet_mts[i]->SetLineColor(kBlack);
    bkgd_sig_highm_lep_met_dijet_mts[i]->SetLineWidth(2);
    bkgd_sig_highm_lep_met_dijet_mts[i]->Draw();
    bkgd_sig_highm_lep_em_met_dijet_mts[i]->SetLineColor(kGreen);
    bkgd_sig_highm_lep_em_met_dijet_mts[i]->SetLineWidth(2);
    bkgd_sig_highm_lep_em_met_dijet_mts[i]->Draw("sames");
    bkgd_sig_highm_lep_lc_met_dijet_mts[i]->SetLineColor(kRed);
    bkgd_sig_highm_lep_lc_met_dijet_mts[i]->SetLineWidth(2);
    bkgd_sig_highm_lep_lc_met_dijet_mts[i]->Draw("sames");    

    tc_bkgd_sig_highm_lep_met_dijet_mts[i]->SetLogy();

    lgnd_bkgd_sig_highm_lep_met_dijet_mts[i] = new TLegend(0.62,0.7,0.9,0.9);
    lgnd_bkgd_sig_highm_lep_met_dijet_mts[i]->SetFillColor(0);
    lgnd_bkgd_sig_highm_lep_met_dijet_mts[i]->SetTextSize(0.03);
    lgnd_bkgd_sig_highm_lep_met_dijet_mts[i]->AddEntry(bkgd_sig_highm_lep_met_dijet_mts[i],"MET_RefFinal","L");
    lgnd_bkgd_sig_highm_lep_met_dijet_mts[i]->AddEntry(bkgd_sig_highm_lep_em_met_dijet_mts[i],"MET_RefFinal_em","L");
    lgnd_bkgd_sig_highm_lep_met_dijet_mts[i]->AddEntry(bkgd_sig_highm_lep_lc_met_dijet_mts[i],"MET_LocHadTopo","L");
    lgnd_bkgd_sig_highm_lep_met_dijet_mts[i]->Draw();

    tc_bkgd_sig_highm_lep_met_dijet_mts[i]->Update();
    string cur_saveas = "./plots/latest/bkgd_sig_highm_"+procs[i]+"_lep_met_dijet_mt.png";
    tc_bkgd_sig_highm_lep_met_dijet_mts[i]->SaveAs(cur_saveas.c_str());

  }
  


}
