#define triangleCuts_cxx

#include "triangleCuts.h"
#include <TH2.h>
#include <TStyle.h>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <TH1.h>
#include <TMath.h>
#include "../../src/lvjjHelper.h"

const int nProcs=2;
const string procs[nProcs]={"elec","muon"};
TH1F* h_lep_met_mt[nProcs];

TH2F* scat_lep_met_dphi_met[nProcs];

TFile* out_file;


void triangleCuts::Begin(TTree * /*tree*/)
{

  string option = GetOption();
  cout<<"triangleCuts::Begin --> "<<option<<endl;
  string out_file_name = "../plots/"+option;
  string cur_out_file_name = out_file_name+".tri.plots.root";

  out_file = (TFile*) TFile::Open(cur_out_file_name.c_str(),"RECREATE");
  out_file->cd();

  for(int p=0;p<nProcs;p++){
    string cur_hist_name = "h_"+procs[p];
    string cur_scat_name = "scat_"+procs[p];
     
    string lep_met_mt_name = cur_hist_name+"_lep_met_mt";
    h_lep_met_mt[p] = new TH1F(lep_met_mt_name.c_str(),lep_met_mt_name.c_str(),35,0,150);

    string lep_met_dphi_met_name = cur_scat_name+"_lep_met_dphi_met";
    scat_lep_met_dphi_met[p] = new TH2F(lep_met_dphi_met_name.c_str(),lep_met_dphi_met_name.c_str(),35,40,200,25,0,TMath::Pi());
     
  }
      
}

void triangleCuts::SlaveBegin(TTree * /*tree*/)
{
  // The SlaveBegin() function is called after the Begin() function.
  // When running with PROOF SlaveBegin() is called on each slave server.
  // The tree argument is deprecated (on PROOF 0 is passed).

  TString option = GetOption();

}

Bool_t triangleCuts::Process(Long64_t entry)
{
  b_evt_pu_weight->GetEntry(entry);
  b_evt_alpgen_weight->GetEntry(entry);

  b_ctrl_all->GetEntry(entry);
  b_rf_met_et->GetEntry(entry);
  b_lead_jet_pt->GetEntry(entry);
  b_nGoodElectrons->GetEntry(entry);
  b_nGoodMuons->GetEntry(entry);
  b_qcd_event->GetEntry(entry);
  b_lvjj_lep_d0sig->GetEntry(entry);

  b_rf_met_et->GetEntry(entry);
  b_rf_met_phi->GetEntry(entry);
  b_lvjj_lep_phi->GetEntry(entry);
  b_lvjj_lep_pt->GetEntry(entry);
  b_lep_met_mt->GetEntry(entry);
  b_dijet_dr->GetEntry(entry);

  
  bool pass_muon_d0sig = (nGoodMuons && !qcd_event) ? fabs(lvjj_lep_d0sig)<3. : true;
  
  if(!ctrl_all || lead_jet_pt<100 || lvjj_lep_pt<30 || (dijet_dr>4.0) || rf_met_et<40. || !pass_muon_d0sig) return kTRUE;

  float evt_weight = evt_pu_weight*evt_alpgen_weight;

  int proc_ind = (nGoodElectrons==1) ? 0 : 1;

  float lep_met_dphi = lvjjHelper::getDeltaPhi(rf_met_phi,lvjj_lep_phi);

  scat_lep_met_dphi_met[proc_ind]->Fill(rf_met_et,lep_met_dphi);
  h_lep_met_mt[proc_ind]->Fill(lep_met_mt,evt_weight);

   return kTRUE;
}

void triangleCuts::SlaveTerminate()
{

}

void triangleCuts::Terminate()
{

  out_file->Write();
  out_file->Close();
  
  //if(h_lep_met_mt[0]) delete h_lep_met_mt[0];
}
