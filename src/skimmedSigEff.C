#define skimmedSigEff_cxx
#include "skimmedSigEff.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "../include/wwVarInfo.h"
#include "../../include/sig_eff_cuts.h"
#include <TH2.h>
#include <TStyle.h>
#include <TMath.h>
#include <TVector2.h>
#include <TLorentzVector.h>


// bool isElec=true;
// int procIndex=0;

TH1F* h_evt_n;

TH1F* h_cuts_n[nCuts][nVals];


TFile* sigEffFile;
void skimmedSigEff::Begin(TTree * /*tree*/)
{

   TString option = GetOption();
   //cout<<"In skimmedSigEff::Begin"<<endl;
   cout<<"skimmedSigEff::Begin: "<<option<<endl;

      
   string curFile = (string) option;
   string curPlotFile= curFile+".sig.eff.root";

   curPlotFile="../plots/"+curPlotFile;

   sigEffFile = (TFile*) TFile::Open(curPlotFile.c_str(),"RECREATE");
   sigEffFile->cd();

   string evt_n_name = "h_evt_n";
   string evt_n_title = evt_n_name;
   h_evt_n = new TH1F(evt_n_name.c_str(),evt_n_title.c_str(),1,0.5,1.5);

   for(int c=0;c<nCuts;c++){
     string cuts_n_name = "h_"+cuts[c];
     for(int v=0;v<nVals;v++){
       string cur_cuts_n_name =cuts_n_name+"_"+vals[v]+"_cuts_n";
       string cur_cuts_n_title = cur_cuts_n_name;
       h_cuts_n[c][v] = new TH1F(cur_cuts_n_name.c_str(),cur_cuts_n_title.c_str(),1,0.5,1.5);
     }
   }
   
}


void skimmedSigEff::SlaveBegin(TTree * /*tree*/)
{

  TString option = GetOption();

}

Bool_t skimmedSigEff::Process(Long64_t entry)
{

  //  b_nGoodMuons->GetEntry(entry);
  b_nGoodJets->GetEntry(entry);  
  //  b_nGoodElectrons->GetEntry(entry);  

  b_sig_jet_m->GetEntry(entry);
  
  b_ww_met_et->GetEntry(entry);

  isElec = (nGoodElectrons) ? true : false;
  procIndex = (isElec) ? 0 : 1;

  
  // //sanity
  // if(nGoodMuons && nGoodElectrons) cout<<"nGoodMuons && nGoodElectrons !?"<<endl;
  // if(!nGoodMuons && !nGoodElectrons) cout<<"!nGoodMuons && !nGoodElectrons !?"<<endl;


  //MET Cut
  h_evt_n->Fill(1);
    
  if(ww_met_et>=30) {
    
    for(int c=0;c<nCuts;c++)
      for(int v=0;v<nVals;v++)
	if(passSignal(cuts[c],values[v],sig_jet_m)) h_cuts_n[c][v]->Fill(1);

      
    

  }
  return kTRUE;
}

void skimmedSigEff::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void skimmedSigEff::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

  
  
  sigEffFile->Write("",TObject::kOverwrite);
}

bool skimmedSigEff::passSignal(string cut, double val, double sig_m){
  //Signal conditions here
  bool passed = true;

  if(sig_m<sig_m_min || sig_m>sig_m_max) return false;

  if(cut=="lt"){
    if(ww_lt<val) passed=false;
  }else if(cut=="st"){
    if(ww_st<val) passed=false;
  }else if(cut=="ht"){
    if(ww_ht<val) passed=false;
  }else{
    cout<<"Unknown cut value: "<<cut<<endl;
    passed=false;
  }

  //
  //
  
  return passed;
}
