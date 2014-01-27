#define jetUncertainty_cxx
#include "jetUncertainty.h"
#include <TH2.h>
#include <TGraphErrors.h>
#include <TStyle.h>
#include <TProfile.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <map>
#include "../../include/wwVarInfo.h"
//#include "defs.h"

const float eta_bin0 = 0.8;
const float eta_bin1= 1.2;
const float eta_bin2= 2.1;


const int nEtaBins = 4;
TProfile* prof_jes_up_v_pt[nEtaBins];
TProfile* prof_jes_down_v_pt[nEtaBins];

TProfile* prof_jer_mc_v_pt[nEtaBins];
TProfile* prof_jer_mc_uncert_v_pt[nEtaBins];


TFile* uncertaintyFile;
TH1F* h_avg_int_per_xing;
int evt_n;
void jetUncertainty::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
   cout<<"jetUncertainty::Begin: "<<option<<endl;

  string test_option = (string) option;

  string curFile = (string) option;
  string curPlotFile= curFile+".uncertainty.plot.root";

  curPlotFile="../plots/"+curPlotFile;

  uncertaintyFile = (TFile*) TFile::Open(curPlotFile.c_str(),"RECREATE");
  uncertaintyFile->cd();
  
  h_avg_int_per_xing = new TH1F("h_avg_int_per_xing","Average Int per Crossing",50,0,18);

  char eta_bin[50];
  string cur_bin="";
  for(int i=0;i<nEtaBins;i++){
    sprintf(eta_bin,"eta%i",i);
    cur_bin = eta_bin;
    //jes_up
    string prof_jes_up_name = "prof_jes_up_v_pt_"+cur_bin;
    prof_jes_up_v_pt[i] =
      new TProfile(prof_jes_up_name.c_str(),prof_jes_up_name.c_str(),20,0,1200,0,1.0);

    //jes_down
    string prof_jes_down_name = "prof_jes_down_v_pt_"+cur_bin;
    prof_jes_down_v_pt[i] =
      new TProfile(prof_jes_down_name.c_str(),prof_jes_down_name.c_str(),20,0,1200,0,1.0);
   
    //jer_up
    string prof_jer_mc_name = "prof_jer_mc_v_pt_"+cur_bin;
    prof_jer_mc_v_pt[i] =
      new TProfile(prof_jer_mc_name.c_str(),prof_jer_mc_name.c_str(),20,0,1200,0,1.0);

    //jer_down
    string prof_jer_mc_uncert_name = "prof_jer_mc_uncert_v_pt_"+cur_bin;
    prof_jer_mc_uncert_v_pt[i] =
      new TProfile(prof_jer_mc_uncert_name.c_str(),prof_jer_mc_uncert_name.c_str(),20,0,1200,0,1.0);
   
  }
      //jes_down_v_pt[i]=new TProfile("
  

  evt_n=0;
}

void jetUncertainty::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();

}

Bool_t jetUncertainty::Process(Long64_t entry)
{

  //////////////////////////////////////////////////
  // Load variables
  ////////////////////////////////////////////////// 

  b_nGoodJets->GetEntry(entry);
  b_lead_jet_pt->GetEntry(entry);
  b_lead_jet_jes_up->GetEntry(entry);
  b_lead_jet_jes_down->GetEntry(entry);
  b_lead_jet_jer_scale->GetEntry(entry);
  b_lead_jet_jer_up->GetEntry(entry);
  b_lead_jet_jer_down->GetEntry(entry);
  b_lead_jet_eta->GetEntry(entry);

  b_second_jet_pt->GetEntry(entry);
  b_second_jet_jes_up->GetEntry(entry);
  b_second_jet_jes_down->GetEntry(entry);
  b_second_jet_jer_mc->GetEntry(entry);
  b_second_jet_jer_mc_uncert->GetEntry(entry);
  b_second_jet_eta->GetEntry(entry);

  int cur_lead_eta_bin=-1;
  if(fabs(lead_jet_eta)<eta_bin0){
    cur_lead_eta_bin=0;
  }else if(fabs(lead_jet_eta)<eta_bin1){
    cur_lead_eta_bin=1;
  }else if(fabs(lead_jet_eta)<eta_bin2){
    cur_lead_eta_bin=2;
  }else{
    cur_lead_eta_bin=3;
  }

  int cur_second_eta_bin=-1;
  if(fabs(second_jet_eta)<eta_bin0){
    cur_second_eta_bin=0;
  }else if(fabs(second_jet_eta)<eta_bin1){
    cur_second_eta_bin=1;
  }else if(fabs(second_jet_eta)<eta_bin2){
    cur_second_eta_bin=2;
  }else{
    cur_second_eta_bin=3;
  }

  prof_jes_up_v_pt[cur_lead_eta_bin]->Fill(lead_jet_pt,lead_jet_jes_up);
  prof_jes_up_v_pt[cur_second_eta_bin]->Fill(second_jet_pt,second_jet_jes_up);
  prof_jes_down_v_pt[cur_lead_eta_bin]->Fill(lead_jet_pt,fabs(lead_jet_jes_down));
  prof_jes_down_v_pt[cur_second_eta_bin]->Fill(second_jet_pt,fabs(second_jet_jes_down));

  //cout<<endl;
  
  prof_jer_mc_v_pt[cur_lead_eta_bin]->Fill(lead_jet_pt,lead_jet_jer_mc);
  prof_jer_mc_v_pt[cur_second_eta_bin]->Fill(second_jet_pt,second_jet_jer_mc);
  
  prof_jer_mc_uncert_v_pt[cur_lead_eta_bin]->Fill(lead_jet_pt,fabs(lead_jet_jer_mc_uncert));
  prof_jer_mc_uncert_v_pt[cur_second_eta_bin]->Fill(second_jet_pt,fabs(second_jet_jer_mc_uncert));

  
  return kTRUE;
}

void jetUncertainty::SlaveTerminate()
{

}

void jetUncertainty::Terminate()
{
  // for(int i=0;i<nEtaBins;i++){
  //   prof_jes_up_v_pt[i]->Write();
  // }
  
  uncertaintyFile->Write();
  uncertaintyFile->Close();

}
