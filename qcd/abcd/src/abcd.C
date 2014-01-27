#define abcd_cxx

#include "abcd.h"
#include <TH2.h>
#include <TStyle.h>

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <TH1.h>
#include <TMath.h>

TH2F* scat_muon_d0sig_met;

TFile* out_file;

void abcd::Begin(TTree * /*tree*/)
{
   string option = GetOption();
   cout<<"abcd::Begin --> "<<option<<endl;
   string out_file_name = "../plots/"+option;
   string cur_out_file_name = out_file_name+".abcd.plots.root";

   out_file = (TFile*) TFile::Open(cur_out_file_name.c_str(),"RECREATE");
   out_file->cd();

   string muon_d0sig_met = "scat_muon_d0sig_met";
   scat_muon_d0sig_met = new TH2F(muon_d0sig_met.c_str(),muon_d0sig_met.c_str(),35,0,500,25,0,3);
   
}

void abcd::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();

}

Bool_t abcd::Process(Long64_t entry)
{
  b_nGoodMuons->GetEntry(entry);

  if(!nGoodMuons) return kTRUE;

  b_lvjj_lep_d0sig->GetEntry(entry);
  b_rf_met_et->GetEntry(entry);

  scat_muon_d0sig_met->Fill(rf_met_et,fabs(lvjj_lep_d0sig));
  
   return kTRUE;
}

void abcd::SlaveTerminate()
{
}

void abcd::Terminate()
{
  out_file->Write();
  out_file->Close();
}
