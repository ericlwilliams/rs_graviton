#define sysWJetsScale_cxx
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "defs.h"

#include "sysWJetsScale.h"
#include <TMath.h>
#include <TH2.h>
#include <TStyle.h>

const int nTotJets=4;

string plot_loc = "/Users/elw/analy/lnuj/plots/sys_wjets_plots/";
string plot_tail = ".plot.root";

TH1F* h_evt_n[nCtrls];
TH1F* h_purw_nom_sow[nCtrls];
TH1F* h_wjrw_iqopt3_sow[nCtrls];
TH1F* h_wjrw_ptjmin10_sow[nCtrls];


TH1F* h_purw_nom_jet_eta[nCtrls][nProcs];
TH1F* h_purw_nom_jet_phi[nCtrls][nProcs];
TH1F* h_purw_nom_jet_n[nCtrls][nProcs];
TH1F* h_purw_nom_jet_m[nCtrls][nProcs];
TH1F* h_purw_nom_jet_pt[nCtrls][nProcs];
TH1F* h_purw_nom_lep_met_pt[nCtrls][nProcs];
TH1F* h_purw_nom_dijet_pt[nCtrls][nProcs];
TH1F* h_purw_nom_lep_nu_dijet_m[nCtrls][nProcs];
TH1F* h_purw_nom_lep_met_dijet_mt[nCtrls][nProcs];
TH1F* h_purw_nom_lep_nu_jet_m[nCtrls][nProcs];
TH1F* h_purw_nom_lep_met_jet_mt[nCtrls][nProcs];

TH1F* h_purw_nom_lead_jet_pt[nCtrls][nProcs];
TH1F* h_purw_nom_ww_met_et[nCtrls][nProcs];
TH1F* h_purw_nom_lep_pt[nCtrls][nProcs];
TH1F* h_purw_nom_lep_eta[nCtrls][nProcs];

TH1F* h_wjrw_iqopt3_jet_eta[nCtrls][nProcs];
TH1F* h_wjrw_iqopt3_jet_phi[nCtrls][nProcs];
TH1F* h_wjrw_iqopt3_jet_n[nCtrls][nProcs];
TH1F* h_wjrw_iqopt3_jet_m[nCtrls][nProcs];
TH1F* h_wjrw_iqopt3_jet_pt[nCtrls][nProcs];
TH1F* h_wjrw_iqopt3_lep_met_pt[nCtrls][nProcs];
TH1F* h_wjrw_iqopt3_dijet_pt[nCtrls][nProcs];
TH1F* h_wjrw_iqopt3_lep_nu_dijet_m[nCtrls][nProcs];
TH1F* h_wjrw_iqopt3_lep_met_dijet_mt[nCtrls][nProcs];
TH1F* h_wjrw_iqopt3_lep_nu_jet_m[nCtrls][nProcs];
TH1F* h_wjrw_iqopt3_lep_met_jet_mt[nCtrls][nProcs];

TH1F* h_wjrw_iqopt3_lead_jet_pt[nCtrls][nProcs];
TH1F* h_wjrw_iqopt3_ww_met_et[nCtrls][nProcs];
TH1F* h_wjrw_iqopt3_lep_pt[nCtrls][nProcs];
TH1F* h_wjrw_iqopt3_lep_eta[nCtrls][nProcs];

TH1F* h_wjrw_ptjmin10_jet_eta[nCtrls][nProcs];
TH1F* h_wjrw_ptjmin10_jet_phi[nCtrls][nProcs];
TH1F* h_wjrw_ptjmin10_jet_n[nCtrls][nProcs];
TH1F* h_wjrw_ptjmin10_jet_m[nCtrls][nProcs];
TH1F* h_wjrw_ptjmin10_lep_met_pt[nCtrls][nProcs];
TH1F* h_wjrw_ptjmin10_dijet_pt[nCtrls][nProcs];
TH1F* h_wjrw_ptjmin10_jet_pt[nCtrls][nProcs];
TH1F* h_wjrw_ptjmin10_lep_nu_dijet_m[nCtrls][nProcs];
TH1F* h_wjrw_ptjmin10_lep_met_dijet_mt[nCtrls][nProcs];
TH1F* h_wjrw_ptjmin10_lep_nu_jet_m[nCtrls][nProcs];
TH1F* h_wjrw_ptjmin10_lep_met_jet_mt[nCtrls][nProcs];

TH1F* h_wjrw_ptjmin10_lead_jet_pt[nCtrls][nProcs];
TH1F* h_wjrw_ptjmin10_ww_met_et[nCtrls][nProcs];
TH1F* h_wjrw_ptjmin10_lep_pt[nCtrls][nProcs];
TH1F* h_wjrw_ptjmin10_lep_eta[nCtrls][nProcs];


int evt_n;
float sow_purw_nom;
float sow_wjrw_iqopt3;
float sow_wjrw_ptjmin10;

TFile* plotFile;

bool doWJetsScale=false; //only apply wjrw to alpgen w samples

void sysWJetsScale::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
   cout<<"sysWJetsScale::Begin: "<<option<<endl;


   evt_n=0;
   sow_purw_nom=0.;
   sow_wjrw_iqopt3=0.;
   sow_wjrw_ptjmin10=0.;

   
   string curFile = (string) option;

   doWJetsScale = (curFile.find("mc.alpgen.w") != string::npos);
      
   string curPlotFile= curFile+plot_tail;

   curPlotFile=plot_loc+curPlotFile;
   
   plotFile = (TFile*) TFile::Open(curPlotFile.c_str(),"RECREATE");
   plotFile->cd();

   for(int c=0;c<nCtrls;c++){//control regions
     plotFile->mkdir(ctrls[c].c_str());
     plotFile->cd(ctrls[c].c_str());

     string evt_n_name = "h_"+ctrls[c]+"_evt_n";
     string evt_n_title = evt_n_name;
     h_evt_n[c] = new TH1F(evt_n_name.c_str(),evt_n_title.c_str(),1,0.5,1.5);

     string purw_nom_sow_name = "h_"+ctrls[c]+"_purw_nom_sow";
     string purw_nom_sow_title = purw_nom_sow_name;
     h_purw_nom_sow[c] = new TH1F(purw_nom_sow_name.c_str(),purw_nom_sow_title.c_str(),1,0.5,1.5);

     string wjrw_iqopt3_sow_name = "h_"+ctrls[c]+"_wjrw_iqopt3_sow";
     string wjrw_iqopt3_sow_title = wjrw_iqopt3_sow_name;
     h_wjrw_iqopt3_sow[c] = new TH1F(wjrw_iqopt3_sow_name.c_str(),wjrw_iqopt3_sow_title.c_str(),1,0.5,1.5);

     string wjrw_ptjmin10_sow_name = "h_"+ctrls[c]+"_wjrw_ptjmin10_sow";
     string wjrw_ptjmin10_sow_title = wjrw_ptjmin10_sow_name;
     h_wjrw_ptjmin10_sow[c] = new TH1F(wjrw_ptjmin10_sow_name.c_str(),wjrw_ptjmin10_sow_title.c_str(),1,0.5,1.5);


     for(int i=0;i<nProcs;i++){

       string h_proc = "h_"+procs[i];
       
       // nom
       
       string purw_nom_jet_n_name = h_proc+"_purw_nom_jet_n";
       string purw_nom_jet_n_title = purw_nom_jet_n_name;
       h_purw_nom_jet_n[c][i] =
	 new TH1F(purw_nom_jet_n_name.c_str(),purw_nom_jet_n_title.c_str(),15,0.5,15.5);

       string purw_nom_jet_m_name = h_proc+"_purw_nom_jet_m";
       string purw_nom_jet_m_title = purw_nom_jet_m_name;
       h_purw_nom_jet_m[c][i] =
	 new TH1F(purw_nom_jet_m_name.c_str(),purw_nom_jet_m_title.c_str(),30,0,140);

       string purw_nom_jet_eta_name = h_proc+"_purw_nom_jet_eta";
       string purw_nom_jet_eta_title = purw_nom_jet_eta_name;
       h_purw_nom_jet_eta[c][i] =
	 new TH1F(purw_nom_jet_eta_name.c_str(),purw_nom_jet_eta_title.c_str(),30,-TMath::Pi(),TMath::Pi());

       string purw_nom_jet_phi_name = h_proc+"_purw_nom_jet_phi";
       string purw_nom_jet_phi_title = purw_nom_jet_phi_name;
       h_purw_nom_jet_phi[c][i] =
	 new TH1F(purw_nom_jet_phi_name.c_str(),purw_nom_jet_phi_title.c_str(),30,0,2*TMath::Pi());

       string purw_nom_jet_pt_name = h_proc+"_purw_nom_jet_pt";
       string purw_nom_jet_pt_title = purw_nom_jet_pt_name;
       h_purw_nom_jet_pt[c][i] =
	 new TH1F(purw_nom_jet_pt_name.c_str(),purw_nom_jet_pt_title.c_str(),50,0,700);

       string purw_nom_lep_met_pt_name = h_proc+"_purw_nom_lep_met_pt";
       string purw_nom_lep_met_pt_title = purw_nom_lep_met_pt_name;
       h_purw_nom_lep_met_pt[c][i] =
	 new TH1F(purw_nom_lep_met_pt_name.c_str(),purw_nom_lep_met_pt_title.c_str(),50,0,1000);

       string purw_nom_dijet_pt_name = h_proc+"_purw_nom_dijet_pt";
       string purw_nom_dijet_pt_title = purw_nom_dijet_pt_name;
       h_purw_nom_dijet_pt[c][i] =
	 new TH1F(purw_nom_dijet_pt_name.c_str(),purw_nom_dijet_pt_title.c_str(),50,0,1000);

       string purw_nom_lep_nu_dijet_m_name = h_proc+"_purw_nom_lep_nu_dijet_m";
       string purw_nom_lep_nu_dijet_m_title = purw_nom_lep_nu_dijet_m_name;
       h_purw_nom_lep_nu_dijet_m[c][i] =
	 new TH1F(purw_nom_lep_nu_dijet_m_name.c_str(),purw_nom_lep_nu_dijet_m_title.c_str(),36,0,1800);

       string purw_nom_lep_met_dijet_mt_name = h_proc+"_purw_nom_lep_met_dijet_mt";
       string purw_nom_lep_met_dijet_mt_title = purw_nom_lep_met_dijet_mt_name;
       h_purw_nom_lep_met_dijet_mt[c][i] =
	 new TH1F(purw_nom_lep_met_dijet_mt_name.c_str(),purw_nom_lep_met_dijet_mt_title.c_str(),36,0,1800);

       string purw_nom_lep_nu_jet_m_name = h_proc+"_purw_nom_lep_nu_jet_m";
       string purw_nom_lep_nu_jet_m_title = purw_nom_lep_nu_jet_m_name;
       h_purw_nom_lep_nu_jet_m[c][i] =
	 new TH1F(purw_nom_lep_nu_jet_m_name.c_str(),purw_nom_lep_nu_jet_m_title.c_str(),36,0,1800);

       string purw_nom_lep_met_jet_mt_name = h_proc+"_purw_nom_lep_met_jet_mt";
       string purw_nom_lep_met_jet_mt_title = purw_nom_lep_met_jet_mt_name;
       h_purw_nom_lep_met_jet_mt[c][i] =
	 new TH1F(purw_nom_lep_met_jet_mt_name.c_str(),purw_nom_lep_met_jet_mt_title.c_str(),36,0,1800);

       string purw_nom_lead_jet_pt_name = h_proc+"_purw_nom_lead_jet_pt";
       string purw_nom_lead_jet_pt_title = purw_nom_lead_jet_pt_name;
       h_purw_nom_lead_jet_pt[c][i] =
	 new TH1F(purw_nom_lead_jet_pt_name.c_str(),purw_nom_lead_jet_pt_title.c_str(),50,0,700);

       string purw_nom_ww_met_et_name = h_proc+"_purw_nom_ww_met_et";
       string purw_nom_ww_met_et_title = purw_nom_ww_met_et_name;
       h_purw_nom_ww_met_et[c][i] =
	 new TH1F(purw_nom_ww_met_et_name.c_str(),purw_nom_ww_met_et_title.c_str(),60,0,600);

       string purw_nom_lep_pt_name = h_proc+"_purw_nom_lep_pt";
       string purw_nom_lep_pt_title = purw_nom_lep_pt_name;
       h_purw_nom_lep_pt[c][i] =
	 new TH1F(purw_nom_lep_pt_name.c_str(),purw_nom_lep_pt_title.c_str(),50,0,500);

       string purw_nom_lep_eta_name = h_proc+"_purw_nom_lep_eta";
       string purw_nom_lep_eta_title = purw_nom_lep_eta_name;
       h_purw_nom_lep_eta[c][i] =
	 new TH1F(purw_nom_lep_eta_name.c_str(),purw_nom_lep_eta_title.c_str(),30,-TMath::Pi(),TMath::Pi());

       // iqopt3
       
       string wjrw_iqopt3_jet_n_name = h_proc+"_wjrw_iqopt3_jet_n";
       string wjrw_iqopt3_jet_n_title = wjrw_iqopt3_jet_n_name;
       h_wjrw_iqopt3_jet_n[c][i] =
	 new TH1F(wjrw_iqopt3_jet_n_name.c_str(),wjrw_iqopt3_jet_n_title.c_str(),15,0.5,15.5);

       string wjrw_iqopt3_jet_m_name = h_proc+"_wjrw_iqopt3_jet_m";
       string wjrw_iqopt3_jet_m_title = wjrw_iqopt3_jet_m_name;
       h_wjrw_iqopt3_jet_m[c][i] =
	 new TH1F(wjrw_iqopt3_jet_m_name.c_str(),wjrw_iqopt3_jet_m_title.c_str(),30,0,140);

       string wjrw_iqopt3_jet_eta_name = h_proc+"_wjrw_iqopt3_jet_eta";
       string wjrw_iqopt3_jet_eta_title = wjrw_iqopt3_jet_eta_name;
       h_wjrw_iqopt3_jet_eta[c][i] =
	 new TH1F(wjrw_iqopt3_jet_eta_name.c_str(),wjrw_iqopt3_jet_eta_title.c_str(),30,-TMath::Pi(),TMath::Pi());

       string wjrw_iqopt3_jet_phi_name = h_proc+"_wjrw_iqopt3_jet_phi";
       string wjrw_iqopt3_jet_phi_title = wjrw_iqopt3_jet_phi_name;
       h_wjrw_iqopt3_jet_phi[c][i] =
	 new TH1F(wjrw_iqopt3_jet_phi_name.c_str(),wjrw_iqopt3_jet_phi_title.c_str(),30,0,2*TMath::Pi());

       string wjrw_iqopt3_jet_pt_name = h_proc+"_wjrw_iqopt3_jet_pt";
       string wjrw_iqopt3_jet_pt_title = wjrw_iqopt3_jet_pt_name;
       h_wjrw_iqopt3_jet_pt[c][i] =
	 new TH1F(wjrw_iqopt3_jet_pt_name.c_str(),wjrw_iqopt3_jet_pt_title.c_str(),50,0,700);

       string wjrw_iqopt3_lep_met_pt_name = h_proc+"_wjrw_iqopt3_lep_met_pt";
       string wjrw_iqopt3_lep_met_pt_title = wjrw_iqopt3_lep_met_pt_name;
       h_wjrw_iqopt3_lep_met_pt[c][i] =
	 new TH1F(wjrw_iqopt3_lep_met_pt_name.c_str(),wjrw_iqopt3_lep_met_pt_title.c_str(),50,0,1000);

       string wjrw_iqopt3_dijet_pt_name = h_proc+"_wjrw_iqopt3_dijet_pt";
       string wjrw_iqopt3_dijet_pt_title = wjrw_iqopt3_dijet_pt_name;
       h_wjrw_iqopt3_dijet_pt[c][i] =
	 new TH1F(wjrw_iqopt3_dijet_pt_name.c_str(),wjrw_iqopt3_dijet_pt_title.c_str(),50,0,1000);

       string wjrw_iqopt3_lep_nu_dijet_m_name = h_proc+"_wjrw_iqopt3_lep_nu_dijet_m";
       string wjrw_iqopt3_lep_nu_dijet_m_title = wjrw_iqopt3_lep_nu_dijet_m_name;
       h_wjrw_iqopt3_lep_nu_dijet_m[c][i] =
	 new TH1F(wjrw_iqopt3_lep_nu_dijet_m_name.c_str(),wjrw_iqopt3_lep_nu_dijet_m_title.c_str(),36,0,1800);

       string wjrw_iqopt3_lep_met_dijet_mt_name = h_proc+"_wjrw_iqopt3_lep_met_dijet_mt";
       string wjrw_iqopt3_lep_met_dijet_mt_title = wjrw_iqopt3_lep_met_dijet_mt_name;
       h_wjrw_iqopt3_lep_met_dijet_mt[c][i] =
	 new TH1F(wjrw_iqopt3_lep_met_dijet_mt_name.c_str(),wjrw_iqopt3_lep_met_dijet_mt_title.c_str(),36,0,1800);

       string wjrw_iqopt3_lep_nu_jet_m_name = h_proc+"_wjrw_iqopt3_lep_nu_jet_m";
       string wjrw_iqopt3_lep_nu_jet_m_title = wjrw_iqopt3_lep_nu_jet_m_name;
       h_wjrw_iqopt3_lep_nu_jet_m[c][i] =
	 new TH1F(wjrw_iqopt3_lep_nu_jet_m_name.c_str(),wjrw_iqopt3_lep_nu_jet_m_title.c_str(),36,0,1800);

       string wjrw_iqopt3_lep_met_jet_mt_name = h_proc+"_wjrw_iqopt3_lep_met_jet_mt";
       string wjrw_iqopt3_lep_met_jet_mt_title = wjrw_iqopt3_lep_met_jet_mt_name;
       h_wjrw_iqopt3_lep_met_jet_mt[c][i] =
	 new TH1F(wjrw_iqopt3_lep_met_jet_mt_name.c_str(),wjrw_iqopt3_lep_met_jet_mt_title.c_str(),36,0,1800);

       string wjrw_iqopt3_lead_jet_pt_name = h_proc+"_wjrw_iqopt3_lead_jet_pt";
       string wjrw_iqopt3_lead_jet_pt_title = wjrw_iqopt3_lead_jet_pt_name;
       h_wjrw_iqopt3_lead_jet_pt[c][i] =
	 new TH1F(wjrw_iqopt3_lead_jet_pt_name.c_str(),wjrw_iqopt3_lead_jet_pt_title.c_str(),50,0,700);

       string wjrw_iqopt3_ww_met_et_name = h_proc+"_wjrw_iqopt3_ww_met_et";
       string wjrw_iqopt3_ww_met_et_title = wjrw_iqopt3_ww_met_et_name;
       h_wjrw_iqopt3_ww_met_et[c][i] =
	 new TH1F(wjrw_iqopt3_ww_met_et_name.c_str(),wjrw_iqopt3_ww_met_et_title.c_str(),60,0,600);

       string wjrw_iqopt3_lep_pt_name = h_proc+"_wjrw_iqopt3_lep_pt";
       string wjrw_iqopt3_lep_pt_title = wjrw_iqopt3_lep_pt_name;
       h_wjrw_iqopt3_lep_pt[c][i] =
	 new TH1F(wjrw_iqopt3_lep_pt_name.c_str(),wjrw_iqopt3_lep_pt_title.c_str(),50,0,500);

       string wjrw_iqopt3_lep_eta_name = h_proc+"_wjrw_iqopt3_lep_eta";
       string wjrw_iqopt3_lep_eta_title = wjrw_iqopt3_lep_eta_name;
       h_wjrw_iqopt3_lep_eta[c][i] =
	 new TH1F(wjrw_iqopt3_lep_eta_name.c_str(),wjrw_iqopt3_lep_eta_title.c_str(),30,-TMath::Pi(),TMath::Pi());

       
       // ptjmin10
       
       string wjrw_ptjmin10_jet_n_name = h_proc+"_wjrw_ptjmin10_jet_n";
       string wjrw_ptjmin10_jet_n_title = wjrw_ptjmin10_jet_n_name;
       h_wjrw_ptjmin10_jet_n[c][i] =
	 new TH1F(wjrw_ptjmin10_jet_n_name.c_str(),wjrw_ptjmin10_jet_n_title.c_str(),15,0.5,15.5);

       string wjrw_ptjmin10_jet_m_name = h_proc+"_wjrw_ptjmin10_jet_m";
       string wjrw_ptjmin10_jet_m_title = wjrw_ptjmin10_jet_m_name;
       h_wjrw_ptjmin10_jet_m[c][i] =
	 new TH1F(wjrw_ptjmin10_jet_m_name.c_str(),wjrw_ptjmin10_jet_m_title.c_str(),30,0,140);

       string wjrw_ptjmin10_jet_eta_name = h_proc+"_wjrw_ptjmin10_jet_eta";
       string wjrw_ptjmin10_jet_eta_title = wjrw_ptjmin10_jet_eta_name;
       h_wjrw_ptjmin10_jet_eta[c][i] =
	 new TH1F(wjrw_ptjmin10_jet_eta_name.c_str(),wjrw_ptjmin10_jet_eta_title.c_str(),30,-TMath::Pi(),TMath::Pi());

       string wjrw_ptjmin10_jet_phi_name = h_proc+"_wjrw_ptjmin10_jet_phi";
       string wjrw_ptjmin10_jet_phi_title = wjrw_ptjmin10_jet_phi_name;
       h_wjrw_ptjmin10_jet_phi[c][i] =
	 new TH1F(wjrw_ptjmin10_jet_phi_name.c_str(),wjrw_ptjmin10_jet_phi_title.c_str(),30,0,2*TMath::Pi());

       string wjrw_ptjmin10_jet_pt_name = h_proc+"_wjrw_ptjmin10_jet_pt";
       string wjrw_ptjmin10_jet_pt_title = wjrw_ptjmin10_jet_pt_name;
       h_wjrw_ptjmin10_jet_pt[c][i] =
	 new TH1F(wjrw_ptjmin10_jet_pt_name.c_str(),wjrw_ptjmin10_jet_pt_title.c_str(),50,0,700);

       string wjrw_ptjmin10_lep_met_pt_name = h_proc+"_wjrw_ptjmin10_lep_met_pt";
       string wjrw_ptjmin10_lep_met_pt_title = wjrw_ptjmin10_lep_met_pt_name;
       h_wjrw_ptjmin10_lep_met_pt[c][i] =
	 new TH1F(wjrw_ptjmin10_lep_met_pt_name.c_str(),wjrw_ptjmin10_lep_met_pt_title.c_str(),50,0,1000);

       string wjrw_ptjmin10_dijet_pt_name = h_proc+"_wjrw_ptjmin10_dijet_pt";
       string wjrw_ptjmin10_dijet_pt_title = wjrw_ptjmin10_dijet_pt_name;
       h_wjrw_ptjmin10_dijet_pt[c][i] =
	 new TH1F(wjrw_ptjmin10_dijet_pt_name.c_str(),wjrw_ptjmin10_dijet_pt_title.c_str(),50,0,1000);

       string wjrw_ptjmin10_lep_nu_dijet_m_name = h_proc+"_wjrw_ptjmin10_lep_nu_dijet_m";
       string wjrw_ptjmin10_lep_nu_dijet_m_title = wjrw_ptjmin10_lep_nu_dijet_m_name;
       h_wjrw_ptjmin10_lep_nu_dijet_m[c][i] =
	 new TH1F(wjrw_ptjmin10_lep_nu_dijet_m_name.c_str(),wjrw_ptjmin10_lep_nu_dijet_m_title.c_str(),36,0,1800);

       string wjrw_ptjmin10_lep_met_dijet_mt_name = h_proc+"_wjrw_ptjmin10_lep_met_dijet_mt";
       string wjrw_ptjmin10_lep_met_dijet_mt_title = wjrw_ptjmin10_lep_met_dijet_mt_name;
       h_wjrw_ptjmin10_lep_met_dijet_mt[c][i] =
	 new TH1F(wjrw_ptjmin10_lep_met_dijet_mt_name.c_str(),wjrw_ptjmin10_lep_met_dijet_mt_title.c_str(),36,0,1800);

       string wjrw_ptjmin10_lep_nu_jet_m_name = h_proc+"_wjrw_ptjmin10_lep_nu_jet_m";
       string wjrw_ptjmin10_lep_nu_jet_m_title = wjrw_ptjmin10_lep_nu_jet_m_name;
       h_wjrw_ptjmin10_lep_nu_jet_m[c][i] =
	 new TH1F(wjrw_ptjmin10_lep_nu_jet_m_name.c_str(),wjrw_ptjmin10_lep_nu_jet_m_title.c_str(),36,0,1800);

       string wjrw_ptjmin10_lep_met_jet_mt_name = h_proc+"_wjrw_ptjmin10_lep_met_jet_mt";
       string wjrw_ptjmin10_lep_met_jet_mt_title = wjrw_ptjmin10_lep_met_jet_mt_name;
       h_wjrw_ptjmin10_lep_met_jet_mt[c][i] =
	 new TH1F(wjrw_ptjmin10_lep_met_jet_mt_name.c_str(),wjrw_ptjmin10_lep_met_jet_mt_title.c_str(),36,0,1800);


       string wjrw_ptjmin10_lead_jet_pt_name = h_proc+"_wjrw_ptjmin10_lead_jet_pt";
       string wjrw_ptjmin10_lead_jet_pt_title = wjrw_ptjmin10_lead_jet_pt_name;
       h_wjrw_ptjmin10_lead_jet_pt[c][i] =
	 new TH1F(wjrw_ptjmin10_lead_jet_pt_name.c_str(),wjrw_ptjmin10_lead_jet_pt_title.c_str(),50,0,700);

       string wjrw_ptjmin10_ww_met_et_name = h_proc+"_wjrw_ptjmin10_ww_met_et";
       string wjrw_ptjmin10_ww_met_et_title = wjrw_ptjmin10_ww_met_et_name;
       h_wjrw_ptjmin10_ww_met_et[c][i] =
	 new TH1F(wjrw_ptjmin10_ww_met_et_name.c_str(),wjrw_ptjmin10_ww_met_et_title.c_str(),60,0,600);

       string wjrw_ptjmin10_lep_pt_name = h_proc+"_wjrw_ptjmin10_lep_pt";
       string wjrw_ptjmin10_lep_pt_title = wjrw_ptjmin10_lep_pt_name;
       h_wjrw_ptjmin10_lep_pt[c][i] =
	 new TH1F(wjrw_ptjmin10_lep_pt_name.c_str(),wjrw_ptjmin10_lep_pt_title.c_str(),50,0,500);

       string wjrw_ptjmin10_lep_eta_name = h_proc+"_wjrw_ptjmin10_lep_eta";
       string wjrw_ptjmin10_lep_eta_title = wjrw_ptjmin10_lep_eta_name;
       h_wjrw_ptjmin10_lep_eta[c][i] =
	 new TH1F(wjrw_ptjmin10_lep_eta_name.c_str(),wjrw_ptjmin10_lep_eta_title.c_str(),30,-TMath::Pi(),TMath::Pi());

       
     }
   }
   plotFile->cd();
}

void sysWJetsScale::SlaveBegin(TTree * /*tree*/)
{
  // The SlaveBegin() function is called after the Begin() function.
  // When running with PROOF SlaveBegin() is called on each slave server.
  // The tree argument is deprecated (on PROOF 0 is passed).

  TString option = GetOption();

}

Bool_t sysWJetsScale::Process(Long64_t entry)
{
  b_nGoodElectrons->GetEntry(entry);
  b_nGoodJets->GetEntry(entry);  
  b_goodNeutrinoSolution->GetEntry(entry);

  b_evt_pu_weight->GetEntry(entry);
  b_EventWJetsScaleIQOPT3->GetEntry(entry);
  b_EventWJetsScalePTJMIN10->GetEntry(entry);

  b_lead_jet_pt->GetEntry(entry);
  b_lead_jet_phi->GetEntry(entry);
  b_lead_jet_eta->GetEntry(entry);
  b_lead_jet_m->GetEntry(entry);

  b_second_jet_pt->GetEntry(entry);
  b_second_jet_phi->GetEntry(entry);
  b_second_jet_eta->GetEntry(entry);
  b_second_jet_m->GetEntry(entry);
  
  b_third_jet_pt->GetEntry(entry);
  b_third_jet_phi->GetEntry(entry);
  b_third_jet_eta->GetEntry(entry);
  b_third_jet_m->GetEntry(entry);

  b_fourth_jet_pt->GetEntry(entry);
  b_fourth_jet_phi->GetEntry(entry);
  b_fourth_jet_eta->GetEntry(entry);
  b_fourth_jet_m->GetEntry(entry);

  float jet_pt[nTotJets] = {lead_jet_pt,second_jet_pt,third_jet_pt,fourth_jet_pt};
  float jet_phi[nTotJets] = {lead_jet_phi,second_jet_phi,third_jet_phi,fourth_jet_phi};
  float jet_eta[nTotJets] = {lead_jet_eta,second_jet_eta,third_jet_eta,fourth_jet_eta};
  float jet_m[nTotJets] = {lead_jet_m,second_jet_m,third_jet_m,fourth_jet_m};  

  b_lep_met_pt->GetEntry(entry);
  b_dijet_pt->GetEntry(entry);
  b_lep_nu_dijet_m->GetEntry(entry);
  b_lep_met_dijet_mt->GetEntry(entry);
  b_lep_nu_jet_m->GetEntry(entry);
  b_lep_met_jet_mt->GetEntry(entry);

  b_lnuj_lep_pt->GetEntry(entry);
  b_lnuj_lep_eta->GetEntry(entry);
  b_ww_met_et->GetEntry(entry);
  
  b_ctrl_ewk->GetEntry(entry);
  b_ctrl_ttbar->GetEntry(entry);

  // evt_ctrls {all,sig,ewk,ttbar,jetm}

  bool is_sig = (lep_met_pt>100 && dijet_pt>200);

  int evt_ctrls[nCtrls] = {1,is_sig,ctrl_ewk,ctrl_ttbar,0};

  isElec = (nGoodElectrons) ? true : false;
  procIndex = (isElec) ? 0 : 1;


  float evt_purw_nom = evt_pu_weight;
  float evt_wjrw_iqopt3 = (doWJetsScale) ? evt_pu_weight*EventWJetsScaleIQOPT3 : EventPileUpReWeight;
  float evt_wjrw_ptjmin10 = (doWJetsScale) ? evt_pu_weight*EventWJetsScalePTJMIN10 : EventPileUpReWeight;

  
  ++evt_n;
  sow_purw_nom+=evt_purw_nom;
  sow_wjrw_iqopt3+=evt_wjrw_iqopt3;
  sow_wjrw_ptjmin10+=evt_wjrw_ptjmin10;


  for(int ctrlIndex=0;ctrlIndex<nCtrls;ctrlIndex++){

    if(!evt_ctrls[ctrlIndex]) continue;


    plotFile->cd(ctrls[ctrlIndex].c_str());


    h_evt_n[ctrlIndex]->Fill(1);
    h_purw_nom_sow[ctrlIndex]->Fill(1,evt_purw_nom);
    h_wjrw_iqopt3_sow[ctrlIndex]->Fill(1,evt_wjrw_iqopt3);
    h_wjrw_ptjmin10_sow[ctrlIndex]->Fill(1,evt_wjrw_ptjmin10);


    for(int j=0;j<nGoodJets;j++){

      h_purw_nom_jet_eta[ctrlIndex][procIndex]->Fill(jet_eta[j],evt_purw_nom);
      h_wjrw_iqopt3_jet_eta[ctrlIndex][procIndex]->Fill(jet_eta[j],evt_wjrw_iqopt3);
      h_wjrw_ptjmin10_jet_eta[ctrlIndex][procIndex]->Fill(jet_eta[j],evt_wjrw_ptjmin10);

      h_purw_nom_jet_pt[ctrlIndex][procIndex]->Fill(jet_pt[j],evt_purw_nom);
      h_wjrw_iqopt3_jet_pt[ctrlIndex][procIndex]->Fill(jet_pt[j],evt_wjrw_iqopt3);
      h_wjrw_ptjmin10_jet_pt[ctrlIndex][procIndex]->Fill(jet_pt[j],evt_wjrw_ptjmin10);

      h_purw_nom_jet_phi[ctrlIndex][procIndex]->Fill(jet_phi[j],evt_purw_nom);
      h_wjrw_iqopt3_jet_phi[ctrlIndex][procIndex]->Fill(jet_phi[j],evt_wjrw_iqopt3);
      h_wjrw_ptjmin10_jet_phi[ctrlIndex][procIndex]->Fill(jet_phi[j],evt_wjrw_ptjmin10);

      h_purw_nom_jet_m[ctrlIndex][procIndex]->Fill(jet_m[j],evt_purw_nom);
      h_wjrw_iqopt3_jet_m[ctrlIndex][procIndex]->Fill(jet_m[j],evt_wjrw_iqopt3);
      h_wjrw_ptjmin10_jet_m[ctrlIndex][procIndex]->Fill(jet_m[j],evt_wjrw_ptjmin10);

    }

    h_purw_nom_jet_n[ctrlIndex][procIndex]->Fill(nGoodJets,evt_purw_nom);
    h_wjrw_iqopt3_jet_n[ctrlIndex][procIndex]->Fill(nGoodJets,evt_wjrw_iqopt3);
    h_wjrw_ptjmin10_jet_n[ctrlIndex][procIndex]->Fill(nGoodJets,evt_wjrw_ptjmin10);
    
    h_purw_nom_lead_jet_pt[ctrlIndex][procIndex]->Fill(jet_pt[0],evt_purw_nom);
    h_wjrw_iqopt3_lead_jet_pt[ctrlIndex][procIndex]->Fill(jet_pt[0],evt_wjrw_iqopt3);
    h_wjrw_ptjmin10_lead_jet_pt[ctrlIndex][procIndex]->Fill(jet_pt[0],evt_wjrw_ptjmin10);

    h_purw_nom_lep_met_pt[ctrlIndex][procIndex]->Fill(lep_met_pt,evt_purw_nom);
    h_wjrw_iqopt3_lep_met_pt[ctrlIndex][procIndex]->Fill(lep_met_pt,evt_wjrw_iqopt3);
    h_wjrw_ptjmin10_lep_met_pt[ctrlIndex][procIndex]->Fill(lep_met_pt,evt_wjrw_ptjmin10);

    h_purw_nom_dijet_pt[ctrlIndex][procIndex]->Fill(dijet_pt,evt_purw_nom);
    h_wjrw_iqopt3_dijet_pt[ctrlIndex][procIndex]->Fill(dijet_pt,evt_wjrw_iqopt3);
    h_wjrw_ptjmin10_dijet_pt[ctrlIndex][procIndex]->Fill(dijet_pt,evt_wjrw_ptjmin10);

    h_purw_nom_lep_pt[ctrlIndex][procIndex]->Fill(lnuj_lep_pt,evt_purw_nom);
    h_wjrw_iqopt3_lep_pt[ctrlIndex][procIndex]->Fill(lnuj_lep_pt,evt_wjrw_iqopt3);
    h_wjrw_ptjmin10_lep_pt[ctrlIndex][procIndex]->Fill(lnuj_lep_pt,evt_wjrw_ptjmin10);

    h_purw_nom_lep_eta[ctrlIndex][procIndex]->Fill(lnuj_lep_eta,evt_purw_nom);
    h_wjrw_iqopt3_lep_eta[ctrlIndex][procIndex]->Fill(lnuj_lep_eta,evt_wjrw_iqopt3);
    h_wjrw_ptjmin10_lep_eta[ctrlIndex][procIndex]->Fill(lnuj_lep_eta,evt_wjrw_ptjmin10);

    h_purw_nom_ww_met_et[ctrlIndex][procIndex]->Fill(ww_met_et,evt_purw_nom);
    h_wjrw_iqopt3_ww_met_et[ctrlIndex][procIndex]->Fill(ww_met_et,evt_wjrw_iqopt3);
    h_wjrw_ptjmin10_ww_met_et[ctrlIndex][procIndex]->Fill(ww_met_et,evt_wjrw_ptjmin10);

    
    if(goodNeutrinoSolution){
      h_purw_nom_lep_nu_dijet_m[ctrlIndex][procIndex]->Fill(lep_nu_dijet_m,evt_purw_nom);
      h_wjrw_iqopt3_lep_nu_dijet_m[ctrlIndex][procIndex]->Fill(lep_nu_dijet_m,evt_wjrw_iqopt3);
      h_wjrw_ptjmin10_lep_nu_dijet_m[ctrlIndex][procIndex]->Fill(lep_nu_dijet_m,evt_wjrw_ptjmin10);
    }
    
    h_purw_nom_lep_met_dijet_mt[ctrlIndex][procIndex]->Fill(lep_met_dijet_mt,evt_purw_nom);
    h_wjrw_iqopt3_lep_met_dijet_mt[ctrlIndex][procIndex]->Fill(lep_met_dijet_mt,evt_wjrw_iqopt3);
    h_wjrw_ptjmin10_lep_met_dijet_mt[ctrlIndex][procIndex]->Fill(lep_met_dijet_mt,evt_wjrw_ptjmin10);

    if(goodNeutrinoSolution){
      h_purw_nom_lep_nu_jet_m[ctrlIndex][procIndex]->Fill(lep_nu_jet_m,evt_purw_nom);
      h_wjrw_iqopt3_lep_nu_jet_m[ctrlIndex][procIndex]->Fill(lep_nu_jet_m,evt_wjrw_iqopt3);
      h_wjrw_ptjmin10_lep_nu_jet_m[ctrlIndex][procIndex]->Fill(lep_nu_jet_m,evt_wjrw_ptjmin10);
    }
    
    h_purw_nom_lep_met_jet_mt[ctrlIndex][procIndex]->Fill(lep_met_jet_mt,evt_purw_nom);
    h_wjrw_iqopt3_lep_met_jet_mt[ctrlIndex][procIndex]->Fill(lep_met_jet_mt,evt_wjrw_iqopt3);
    h_wjrw_ptjmin10_lep_met_jet_mt[ctrlIndex][procIndex]->Fill(lep_met_jet_mt,evt_wjrw_ptjmin10);
    
  }

  return kTRUE;
}

void sysWJetsScale::SlaveTerminate()
{
  // The SlaveTerminate() function is called after all entries or objects
  // have been processed. When running with PROOF SlaveTerminate() is called
  // on each slave server.

}

void sysWJetsScale::Terminate()
{

  cout<<"Total Events processed: "<<evt_n<<endl;
  cout<<"Total Sum of Weights: "<<sow_purw_nom<<endl;
  cout<<"Total Sum of Weights (iqopt3): "<<sow_wjrw_iqopt3<<endl;
  cout<<"Total Sum of Weights (ptjmin10): "<<sow_wjrw_ptjmin10<<endl;

  plotFile->Write("",TObject::kOverwrite);
  return;
}
