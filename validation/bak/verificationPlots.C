#define verificationPlots_cxx
#include "verificationPlots.h"
#include <TH2.h>
#include <TProfile.h>
#include <TGraphErrors.h>
#include <TStyle.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <map>
#include "../../include/wwVarInfo.h"
//#include "defs.h"

TProfile* prof_evtperlumi_rnum;// fill(rnum,1/lumi)
TProfile* prof_rlumi_rnum;// fill(rnum,1/lumi)

map<int,float> m_rnum_evtperlumi;
map<int,float> m_rnum_evts;
map<int,float> m_rnum_lumi;

TGraphErrors* graph_nevts_lumi;
TGraphErrors* graph_evtperlumi_rnum;

TFile* verificationFile;
int evt_n;
bool is_data;
void verificationPlots::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
   cout<<"verificationPlots::Begin: "<<option<<endl;

  string test_option = (string) option;
  is_data = (test_option.find("data11")!=string::npos);

  string curFile = (string) option;
  string curPlotFile= curFile+".verification.plot.root";

  curPlotFile="../plots/"+curPlotFile;

  verificationFile = (TFile*) TFile::Open(curPlotFile.c_str(),"RECREATE");

  //////////////////////////////////////////////////
  // Initialize Histograms
  //////////////////////////////////////////////////

  prof_evtperlumi_rnum = new TProfile("prof_evtperlumi_rnum","Evt/Lumi vs Run Number",1400,176e3,190e3,0,5000);
  prof_rlumi_rnum = new TProfile("prof_rlumi_rnum","Lumi vs Run Number",1400,176e3,190e3,0,100);

  verificationFile->cd();
  evt_n=0;
}

void verificationPlots::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();

}

Bool_t verificationPlots::Process(Long64_t entry)
{

  //////////////////////////////////////////////////
  // Load variables
  ////////////////////////////////////////////////// 

  b_RunNum->GetEntry(entry);
  b_RunLumi->GetEntry(entry);

  prof_rlumi_rnum->Fill(RunNum,RunLumi);
  m_rnum_evtperlumi[RunNum]+=(1/RunLumi);
  m_rnum_evts[RunNum]++;
  m_rnum_lumi[RunNum]=RunLumi;


  
  ++evt_n;

  return kTRUE;
}

void verificationPlots::SlaveTerminate()
{

}

void verificationPlots::Terminate()
{

  // vectors, number of entries is number of runs
  vector<Float_t> v_lumi;
  vector<Float_t> v_evtperlumi;
  vector<Float_t> v_nevts;
  vector<Float_t> v_rnum;
  int n_runs=0;
  
  map<int,float>::iterator m_end = m_rnum_evtperlumi.end();
  for(map<int,float>::iterator m_it=m_rnum_evtperlumi.begin(); m_it != m_end; ++m_it) {
    ++n_runs;

    prof_evtperlumi_rnum->Fill(m_it->first,m_it->second,m_rnum_evts[m_it->first]);

    v_rnum.push_back(m_it->first);
    v_evtperlumi.push_back(m_it->second);
    v_lumi.push_back(m_rnum_lumi[m_it->first]);
    v_nevts.push_back(m_rnum_evts[m_it->first]);


  }


  graph_nevts_lumi = new TGraphErrors(n_runs,&v_lumi[0],&v_nevts[0]);
  graph_nevts_lumi->SetName("graph_nevts_lumi");
  graph_nevts_lumi->Write("",TObject::kOverwrite);
  
  graph_evtperlumi_rnum = new TGraphErrors(n_runs,&v_rnum[0],&v_evtperlumi[0]);
  graph_evtperlumi_rnum->SetName("graph_evtperlumi_rnum");
  graph_evtperlumi_rnum->Write("",TObject::kOverwrite);
  

  verificationFile->Write("",TObject::kOverwrite);
  verificationFile->Close();





  cout<<"Total ";
  if(is_data){
    cout<<"Data ";
  }else{
    cout<<"MC ";
  }
  cout<<"Events processed: "<<evt_n<<endl;  

}
