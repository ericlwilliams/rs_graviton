#define jvf_cxx

#include "jvf.h"
#include <TH2.h>
#include <TH1.h>
#include <TStyle.h>
#include <TProfile.h>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "defs.h"

TH1* h_jet_n[nProcs];
TH1* h_avg_int_per_xing[nProcs];
TProfile* prof_jet_n_mu[nProcs];
TProfile* prof_jet_pt_mu[nProcs];

TFile* plotFile;
void jvf::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
   string str_option = option.Data();
   string file_option = str_option.substr(0,str_option.find(","));
   string jvf_option = str_option.substr(str_option.find(",")+1);


   string curPlotFile= file_option+".plot."+jvf_option+".root";
   curPlotFile="../plots/"+jvf_option+"_plots/"+curPlotFile;

   plotFile = (TFile*) TFile::Open(curPlotFile.c_str(),"RECREATE");
   plotFile->cd();


   for(int i=0;i<nProcs;i++){

     string h_proc = "h_"+procs[i];
     string prof_proc = "prof_"+procs[i];
     
     string jet_n_name = h_proc+"_jet_n";
     string jet_n_title = jet_n_name;
     h_jet_n[i] = new TH1F(jet_n_name.c_str(),jet_n_title.c_str(),15,0.5,15.5);

     string avg_int_per_xing_name = h_proc+"_avg_int_per_xing";
     string avg_int_per_xing_title = avg_int_per_xing_name;
     h_avg_int_per_xing[i] = new TH1F(avg_int_per_xing_name.c_str(),avg_int_per_xing_title.c_str(),15,0.5,15.5);

     string jet_n_mu_name = prof_proc+"_jet_n_mu";
     string jet_n_mu_title = jet_n_mu_name;
     prof_jet_n_mu[i] = new TProfile(jet_n_mu_name.c_str(),jet_n_mu_title.c_str(),30,0,16,0,20);

     string jet_pt_mu_name = prof_proc+"_jet_pt_mu";
     string jet_pt_mu_title = jet_pt_mu_name;
     prof_jet_pt_mu[i] = new TProfile(jet_pt_mu_name.c_str(),jet_pt_mu_title.c_str(),30,0,16,40,1000);


     
   }

}

void jvf::SlaveBegin(TTree * /*tree*/)
{

   TString option = GetOption();

}

Bool_t jvf::Process(Long64_t entry)
{

  b_avgIntPerXing->GetEntry(entry);
  b_nGoodJets->GetEntry(entry);
  b_lead_jet_pt->GetEntry(entry);
  b_ww_met_et->GetEntry(entry);
  b_ctrl_all->GetEntry(entry);
  b_nGoodElectrons->GetEntry(entry);

  isElec = (nGoodElectrons) ? true : false;
  procIndex = (isElec) ? 0 : 1;

  if(!ctrl_all || ww_met_et<30.0) return kTRUE;

  h_jet_n[procIndex]->Fill(nGoodJets);
  h_avg_int_per_xing[procIndex]->Fill(avgIntPerXing);

  prof_jet_n_mu[procIndex]->Fill(avgIntPerXing,nGoodJets);
  prof_jet_pt_mu[procIndex]->Fill(avgIntPerXing,lead_jet_pt);

   return kTRUE;
}

void jvf::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void jvf::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
  plotFile->Write("",TObject::kOverwrite);
  plotFile->Close();

  //delete h_jet_n;
}
