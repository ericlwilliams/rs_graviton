#define verificationPlots_cxx
#include "verificationPlots.h"
#include <TH2.h>
#include <TGraphErrors.h>
#include <TStyle.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <map>
#include "../../include/wwVarInfo.h"
//#include "defs.h"

float luminosity_error=0.039;

map<int,float> m_rnum_evtperlumi;
map<int,float> m_rnum_evts;
map<int,float> m_rnum_lumi;

map<int,vector<int> > m_rnum_enum;

vector<Float_t> v_lumi_periodAE;
vector<Float_t> v_lumi_periodFI;
vector<Float_t> v_lumi_periodJM;

TH1F* h_avg_int_per_xing;

TGraphErrors* graph_nevts_lumi;
TGraphErrors* graph_nevts_lumi_periodAE;
TGraphErrors* graph_nevts_lumi_periodFI;
TGraphErrors* graph_nevts_lumi_periodJM;

TGraphErrors* graph_evtperlumi_rnum;

TFile* verificationFile;
int evt_n;
bool is_data;

void verificationPlots::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
   cout<<"verificationPlots::Begin: "<<option<<endl;

  string test_option = (string) option;
  is_data = (test_option.find("data")!=string::npos);

  string curFile = (string) option;
  string curPlotFile= curFile+".verification.plot.root";

  curPlotFile="../plots/"+curPlotFile;

  verificationFile = (TFile*) TFile::Open(curPlotFile.c_str(),"RECREATE");

  m_rnum_evtperlumi.clear();
  m_rnum_evts.clear();
  m_rnum_lumi.clear();

  v_lumi_periodAE.clear();
  v_lumi_periodFI.clear();
  v_lumi_periodJM.clear();

  h_avg_int_per_xing = new TH1F("h_avg_int_per_xing","Average Int per Crossing",50,0,18);
  
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

  b_EvtNum->GetEntry(entry);
  b_RunNum->GetEntry(entry);
  b_RunLumi->GetEntry(entry);
  b_ctrl_all->GetEntry(entry);
  b_lvjj_met_et->GetEntry(entry);
  b_lead_jet_pt->GetEntry(entry);
  b_avgIntPerXing->GetEntry(entry);
  
  if(ctrl_all && lvjj_met_et>40. && lead_jet_pt>100.){
  
    m_rnum_evtperlumi[RunNum]+=(1/RunLumi);
    m_rnum_evts[RunNum]++;
    m_rnum_lumi[RunNum]=RunLumi;

    h_avg_int_per_xing->Fill(avgIntPerXing);
    
    m_rnum_enum[RunNum].push_back(EvtNum);
    ++evt_n;
  }


  

  
  return kTRUE;
}

void verificationPlots::SlaveTerminate()
{

}

void verificationPlots::Terminate()
{

  // vectors, number of entries is number of runs
  vector<Float_t> v_rnum,v_rnum_err;
  
  vector<Float_t> v_evtperlumi,v_evtperlumi_err;

  vector<Float_t> v_lumi,v_lumi_err;

  vector<Float_t> v_nevts,v_nevts_err;
  vector<Float_t> v_nevts_periodAE;
  vector<Float_t> v_nevts_periodFI;
  vector<Float_t> v_nevts_periodJM;

  int n_runs=0;
  int n_periodAE_runs=0;
  int n_periodFI_runs=0;
  int n_periodJM_runs=0;

  
  map<int,float>::iterator m_end = m_rnum_evtperlumi.end();
  for(map<int,float>::iterator m_it=m_rnum_evtperlumi.begin(); m_it != m_end; ++m_it) {
    ++n_runs;

    int cur_rnum = m_it->first;
    //////////////////////////////////////////////////
    // Error propagation
    //////////////////////////////////////////////////

    // relative errors
    float nevts_error = 1/sqrt(m_rnum_evts[cur_rnum]);
    float evtperlumi_error = sqrt(pow(luminosity_error,2.)+pow(nevts_error,2.));
    
    v_rnum.push_back(cur_rnum);
    v_rnum_err.push_back(0.);

    v_evtperlumi.push_back(m_it->second);
    //cout<<m_it->second<<", "<<evtperlumi_error<<"% (#{pm} "<<evtperlumi_error*m_it->second<<")"<<endl;
    v_evtperlumi_err.push_back(evtperlumi_error*m_it->second);
    

    //////////////////////////////////////////////////
    // nevts vs lumi
    ////////////////////////////////////////////////// 

    v_lumi.push_back(m_rnum_lumi[cur_rnum]);
    v_lumi_err.push_back(m_rnum_lumi[cur_rnum]*luminosity_error);
    
    v_nevts.push_back(m_rnum_evts[cur_rnum]);
    v_nevts_err.push_back((m_rnum_evts[cur_rnum])*nevts_error);    

    if(cur_rnum<=180776){ // periodAE

      ++n_periodAE_runs;
      v_lumi_periodAE.push_back(m_rnum_lumi[cur_rnum]);
      v_nevts_periodAE.push_back(m_rnum_evts[cur_rnum]);
      
    }else if(cur_rnum<=186493){ //periodFI

      ++n_periodFI_runs;
      v_lumi_periodFI.push_back(m_rnum_lumi[cur_rnum]);
      v_nevts_periodFI.push_back(m_rnum_evts[cur_rnum]);

    }else{ //periodJM

      ++n_periodJM_runs;
      v_lumi_periodJM.push_back(m_rnum_lumi[cur_rnum]);
      v_nevts_periodJM.push_back(m_rnum_evts[cur_rnum]);

    }
  }

  graph_nevts_lumi = new TGraphErrors(n_runs,&v_lumi[0],&v_nevts[0]);
  graph_nevts_lumi->SetName("graph_nevts_lumi");
  graph_nevts_lumi->Write("",TObject::kOverwrite);
  
  graph_nevts_lumi_periodAE =
    new TGraphErrors(n_periodAE_runs,&v_lumi_periodAE[0],&v_nevts_periodAE[0]);
  graph_nevts_lumi_periodAE->SetName("graph_nevts_lumi_periodAE");
  graph_nevts_lumi_periodAE->Write("",TObject::kOverwrite);
  
  graph_nevts_lumi_periodFI =
    new TGraphErrors(n_periodFI_runs,&v_lumi_periodFI[0],&v_nevts_periodFI[0]);
  graph_nevts_lumi_periodFI->SetName("graph_nevts_lumi_periodFI");
  graph_nevts_lumi_periodFI->Write("",TObject::kOverwrite);
  
  graph_nevts_lumi_periodJM =
    new TGraphErrors(n_periodJM_runs,&v_lumi_periodJM[0],&v_nevts_periodJM[0]);
  graph_nevts_lumi_periodJM->SetName("graph_nevts_lumi_periodJM");
  graph_nevts_lumi_periodJM->Write("",TObject::kOverwrite);

  graph_evtperlumi_rnum =
    new TGraphErrors(n_runs,&v_rnum[0],&v_evtperlumi[0],&v_rnum_err[0],&v_evtperlumi_err[0]);
  graph_evtperlumi_rnum->SetName("graph_evtperlumi_rnum");
  graph_evtperlumi_rnum->Write("",TObject::kOverwrite);
  

  //////////////////////////////////////////////////
  // Event number plots
  ////////////////////////////////////////////////// 

  gDirectory->mkdir("evt_nums")->cd();
  
  const int num_runs=n_runs;
  TH1* h_evt_nums[num_runs];


  for(int i=0;i<n_runs;i++){

    int cur_run_number= v_rnum.at(i);
    vector<int> cur_enum = m_rnum_enum[cur_run_number];
    
    int cur_enum_min = *(std::min_element(cur_enum.begin(),cur_enum.end()));
    int cur_enum_max = *(std::max_element(cur_enum.begin(),cur_enum.end()));

    string cur_run_hist_name = Form("h_%d_evt_nums",cur_run_number);
    
    h_evt_nums[i] =
      new TH1I(cur_run_hist_name.c_str(),cur_run_hist_name.c_str(),
	       1000,cur_enum_min-100,cur_enum_max+100);
    for(int j=0;j<cur_enum.size();j++){
      h_evt_nums[i]->Fill(cur_enum.at(j));
    }
  }
  
  verificationFile->Write("",TObject::kOverwrite);
  verificationFile->Close();

  delete graph_nevts_lumi;
  delete graph_evtperlumi_rnum;

  cout<<"Total ";
  if(is_data){
    cout<<"Data ";
  }else{
    cout<<"MC ";
  }
  cout<<"Events processed: "<<evt_n<<", Number of runs: "<<n_runs<<endl;


}
