#define jvf_cxx

#include "jvf.h"
#include <TH2.h>
#include <TH1.h>
#include <TStyle.h>
#include <iostream>
#include <cstdlib>
#include <stdio.h>

TH1* h_jet_n;

TFile* plotFile;
void jvf::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
   string str_option = option.Data();
   string file_option = str_option.substr(0,str_option.find(","));
   string jvf_option = str_option.substr(str_option.find(",")+1);


   string curPlotFile= file_option+".plot."+jvf_option+".root";
   curPlotFile="../plots/"+curPlotFile;

   plotFile = (TFile*) TFile::Open(curPlotFile.c_str(),"RECREATE");
   plotFile->cd();


   h_jet_n = new TH1F("h_jet_n","h_jet_n",15,0.5,15.5);

}

void jvf::SlaveBegin(TTree * /*tree*/)
{

   TString option = GetOption();

}

Bool_t jvf::Process(Long64_t entry)
{

  b_avgIntPerXing->GetEntry(entry);
  b_nGoodJets->GetEntry(entry);
  b_ww_met_et->GetEntry(entry);
  b_ctrl_all->GetEntry(entry);

  if(!ctrl_all || ww_met_et<30.0) return kTRUE;

  h_jet_n->Fill(nGoodJets);
  

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
