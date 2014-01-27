#include <fstream.h>

void metCutEfficiency(){

  const int nProcs=2;
  const string procs[nProcs] = {"elec","muon"};
  
  string file_loc = "/Users/elw/analy/lvjj/plots/ctrl_plots/";
  string file_end = ".ctrl.plot.root";

  //////////////////////////////////////////////////
  // Load Scaled Backgrounds
  //////////////////////////////////////////////////
  
  string wjets_loc = file_loc+"merged/mc.alpgen.wjets"+file_end;
  string vv_loc = file_loc+"merged/mc.herwig.vv"+file_end;
  string qcd_loc = file_loc+"merged/qcd.alpgen"+file_end;
  string top_loc = file_loc+"merged/mc.mcatnlo.top"+file_end;  
  string zjets_loc = file_loc+"merged/mc.alpgen.zjets"+file_end;

  TFile* wjets = (TFile*) TFile::Open(wjets_loc.c_str(),"READ");
  TFile* top = (TFile*) TFile::Open(top_loc.c_str(),"READ");
  TFile* qcd = (TFile*) TFile::Open(qcd_loc.c_str(),"READ");
  TFile* vv = (TFile*) TFile::Open(vv_loc.c_str(),"READ");
  TFile* zjets = (TFile*) TFile::Open(zjets_loc.c_str(),"READ");

  const int n_met_cuts = 6;// signal region w/ met>20,25,30,35,40,45,50
  int met_cut_values[n_met_cuts] = {25,30,35,40,45,50};
  TH1F* h_bkgd_evt_n[nProcs][n_met_cuts];
  string h_evt_n_name[nProcs] = {"h_met_sel_elec_sig_met%i_evt_n",
				      "h_met_sel_muon_sig_met%i_evt_n"};

  
  for(int i=0;i<nProcs;i++){

    
    for(int j=0;j<n_met_cuts;j++){
      string cur_evt_n_hist_name = Form(h_evt_n_name[i].c_str(),met_cut_values[j]);
      TH1F* cur_wjets_evt_n = wjets->Get(cur_evt_n_hist_name.c_str());
      cur_wjets_evt_n->SetDirectory(0);
      TH1F* cur_top_evt_n = top->Get(cur_evt_n_hist_name.c_str());
      cur_top_evt_n->SetDirectory(0);
      TH1F* cur_qcd_evt_n = qcd->Get(cur_evt_n_hist_name.c_str());
      cur_qcd_evt_n->SetDirectory(0);
      TH1F* cur_vv_evt_n = vv->Get(cur_evt_n_hist_name.c_str());
      cur_vv_evt_n->SetDirectory(0);
      TH1F* cur_zjets_evt_n = zjets->Get(cur_evt_n_hist_name.c_str());
      cur_zjets_evt_n->SetDirectory(0);

      h_bkgd_evt_n[i][j] = cur_wjets_evt_n;
      h_bkgd_evt_n[i][j]->Add(cur_top_evt_n);
      h_bkgd_evt_n[i][j]->Add(cur_qcd_evt_n);
      h_bkgd_evt_n[i][j]->Add(cur_vv_evt_n);
      h_bkgd_evt_n[i][j]->Add(cur_zjets_evt_n);

    }
  }

  wjets->Close();
  top->Close();
  vv->Close();
  zjets->Close();
  qcd->Close();

  
  //////////////////////////////////////////////////
  // Signals
  ////////////////////////////////////////////////// 

  // RSG
  const int n_rsg_samples=5;
  TFile* rsg_samples[n_rsg_samples];
  string rsg_masses[n_rsg_samples] = {"m500","m750","m1000","m1250","m1500"};
  float v_rsg_masses[n_rsg_samples] = {500.,750.,1000.,1250.,1500};

  TH1F* h_rsg_evt_n[nProcs][n_met_cuts][n_rsg_samples];

  TH1F* h_rsg_ps_evt_n[nProcs][n_rsg_samples];
  string h_rsg_ps_evt_n_name[nProcs] = {"h_met_sel_elec_ps_evt_n",
					"h_met_sel_muon_ps_evt_n"};

  for(int r=0;r<n_rsg_samples;r++){
    string rsg_loc = file_loc+"merged/mc.rsg."+rsg_masses[r]+".kmpl0_1"+file_end;
    //rsg_samples[r] = (TFile*) TFile::Open(rsg_loc.c_str(),"READ");
    TFile* cur_rsg_file = (TFile*) TFile::Open(rsg_loc.c_str(),"READ");

    for(int i=0;i<nProcs;i++){

      h_rsg_ps_evt_n[i][r] = (TH1F*) cur_rsg_file->Get(h_rsg_ps_evt_n_name[i].c_str());
      h_rsg_ps_evt_n[i][r]->SetDirectory(0);
      
      for(int j=0;j<n_met_cuts;j++){
	string cur_rsg_evt_n_hist_name = Form(h_evt_n_name[i].c_str(),met_cut_values[j]);
	h_rsg_evt_n[i][j][r] = (TH1F) cur_rsg_file->Get(cur_rsg_evt_n_hist_name.c_str());
	h_rsg_evt_n[i][j][r]->SetDirectory(0);
      }
    }
    cur_rsg_file->Close();
  }

  //  wprime
  const int n_wprime_samples=11;
  TFile* wprime_samples[n_wprime_samples];
  string wprime_masses[n_wprime_samples] =
    {"m500","m600","m700","m800","m900","m1000",
     "m1100","m1200","m1300","m1400","m1500"};
  float v_wprime_masses[n_wprime_samples] =
    {500.,600.,700.,800.,900.,1000.,1100.,1200.,1300.,1400.,1500.};

  TH1F* h_wprime_evt_n[nProcs][n_met_cuts][n_wprime_samples];

  TH1F* h_wprime_ps_evt_n[nProcs][n_wprime_samples];
  string h_wprime_ps_evt_n_name[nProcs] = {"h_met_sel_elec_ps_evt_n",
					"h_met_sel_muon_ps_evt_n"};

  for(int r=0;r<n_wprime_samples;r++){
    string wprime_loc = file_loc+"merged/mc.wprime.wz."+wprime_masses[r]+file_end;
    //wprime_samples[r] = (TFile*) TFile::Open(wprime_loc.c_str(),"READ");
    TFile* cur_wprime_file = (TFile*) TFile::Open(wprime_loc.c_str(),"READ");

    for(int i=0;i<nProcs;i++){

      h_wprime_ps_evt_n[i][r] = (TH1F*) cur_wprime_file->Get(h_wprime_ps_evt_n_name[i].c_str());
      h_wprime_ps_evt_n[i][r]->SetDirectory(0);
      
      for(int j=0;j<n_met_cuts;j++){
	string cur_sig_evt_n_hist_name = Form(h_evt_n_name[i].c_str(),met_cut_values[j]);
	h_wprime_evt_n[i][j][r] = (TH1F) cur_wprime_file->Get(cur_sig_evt_n_hist_name.c_str());
	h_wprime_evt_n[i][j][r]->SetDirectory(0);
      }
    }
    cur_wprime_file->Close();
  }

  //////////////////////////////////////////////////
  // rsg histograms in : h_rsg_evt_n[nProcs][met cut][rsg mass]
  // w' histograms in ; h_wprime_evt_n[nProcs][met_cut][w' mass]
  // background histos in : h_bkgd_evt_n[nProcs][met_cut]
  //////////////////////////////////////////////////

  string elec_out_file_name = "./logs/elec_met_cut_efficiencies.csv";
  std::ofstream elec_out_file(elec_out_file_name.c_str());
  elec_out_file.precision(2);
  elec_out_file.setf(ios::fixed,ios::floatfield);
  elec_out_file<<"metcut,rsg500,rsg750,rsg1000,rsg1250,rsg1500,";
  elec_out_file<<"wp500,wp600,wp700,wp800,wp900,wp1000,wp1100,";
  elec_out_file<<"wp1200,wp1300,wp1400,wp1500"<<endl;

  string muon_out_file_name = "./logs/muon_met_cut_efficiencies.csv";
  std::ofstream muon_out_file(muon_out_file_name.c_str());
  muon_out_file.precision(2);
  muon_out_file.setf(ios::fixed,ios::floatfield);
  muon_out_file<<"metcut,rsg500,rsg750,rsg1000,rsg1250,rsg1500,";
  muon_out_file<<"wp500,wp600,wp700,wp800,wp900,wp1000,wp1100,";
  muon_out_file<<"wp1200,wp1300,wp1400,wp1500"<<endl;

  //std::ofstream out_files[nProcs] = {(std::ofstream) elec_out_file, (std::ofstream) muon_out_file};
  
  for(int i=0;i<nProcs;i++){
    bool isElec = (i==0);
    for(int j=0;j<n_met_cuts;j++){

      if(isElec){
	elec_out_file<<Form("%i,",met_cut_values[j]);
      }else{
	muon_out_file<<Form("%i,",met_cut_values[j]);
      }

      float bkgd_evt_n = (float) ((TH1F*) h_bkgd_evt_n[i][j])->Integral();



      for(int k=0;k<n_rsg_samples;k++){
	float rsg_evt_n = (float) ((TH1F*) h_rsg_evt_n[i][j][k])->Integral();

	float rsg_ps_evt_n = (float) ((TH1F*) h_rsg_ps_evt_n[i][k])->Integral();

	
	float rsg_acceptance = rsg_evt_n/rsg_ps_evt_n;
	float rsg_sig_to_bkgd = rsg_evt_n/bkgd_evt_n;
	float rsg_sig_to_sqrt_bkgd = rsg_evt_n/sqrt(bkgd_evt_n);

	
	if(isElec){
	  //elec_out_file<<Form("%f|",rsg_sig_to_bkgd);
	  elec_out_file<<rsg_acceptance<<" / ";
	  elec_out_file<<rsg_sig_to_bkgd<<" / ";
	  elec_out_file<<rsg_sig_to_sqrt_bkgd<<",";
	}else{
	  muon_out_file<<rsg_acceptance<<" / ";
	  muon_out_file<<rsg_sig_to_bkgd<<" / ";
	  muon_out_file<<rsg_sig_to_sqrt_bkgd<<",";
	}
      }

      for(int l=0;l<n_wprime_samples;l++){
	float wprime_evt_n = (float) ((TH1F*) h_wprime_evt_n[i][j][l])->Integral();
	float wprime_ps_evt_n = (float) ((TH1F*) h_wprime_ps_evt_n[i][l])->Integral();

	float wprime_acceptance = wprime_evt_n/wprime_ps_evt_n;
	float wprime_sig_to_bkgd = wprime_evt_n/bkgd_evt_n;
	float wprime_sig_to_sqrt_bkgd = wprime_evt_n/sqrt(bkgd_evt_n);
	  
	if(isElec){
	  elec_out_file<<wprime_acceptance<<" / ";
	  elec_out_file<<wprime_sig_to_bkgd<<" / ";
	  elec_out_file<<wprime_sig_to_sqrt_bkgd<<",";
	}else{
	  muon_out_file<<wprime_acceptance<<" / ";
	  muon_out_file<<wprime_sig_to_bkgd<<" / ";
	  muon_out_file<<wprime_sig_to_sqrt_bkgd<<",";
	}
      }
      if(isElec){
	elec_out_file<<endl;
      }else{
	muon_out_file<<endl;
      }

    }
    if(isElec){
      elec_out_file<<endl;
    }else{
      muon_out_file<<endl;
    }

    
  }
  

  
  gROOT->ProcessLine(".q");
  return;
}
