#include <vector>
#include <TGraph>
void runSignalSelection(){

  gStyle->SetPadTopMargin(0.05);
  gStyle->SetPadRightMargin(0.05);
  
  const int nProcs=2;
  const string procs[nProcs] = {"elec","muon"};
  
  string file_loc = "/Users/elw/analy/lvjj/plots/ctrl_plots/";
  string file_end = ".ctrl.plot.root";

  //////////////////////////////////////////////////
  // Load Scaled Backgrounds
  //////////////////////////////////////////////////
  
  string alpgen_wjets_loc = file_loc+"merged/mc.alpgen.wjets"+file_end;
  string vv_loc = file_loc+"merged/mc.herwig.vv"+file_end;
  string alpgen_qcd_loc = file_loc+"merged/qcd.alpgen"+file_end;
  string top_loc = file_loc+"merged/mc.mcatnlo.top"+file_end;  
  string alpgen_zjets_loc = file_loc+"merged/mc.alpgen.zjets"+file_end;

  TFile* alpgen_wjets = (TFile*) TFile::Open(alpgen_wjets_loc.c_str(),"READ");
  TFile* top = (TFile*) TFile::Open(top_loc.c_str(),"READ");
  TFile* alpgen_qcd = (TFile*) TFile::Open(alpgen_qcd_loc.c_str(),"READ");
  TFile* vv = (TFile*) TFile::Open(vv_loc.c_str(),"READ");
  TFile* alpgen_zjets = (TFile*) TFile::Open(alpgen_zjets_loc.c_str(),"READ");

  //////////////////////////////////////////////////
  // Signals
  ////////////////////////////////////////////////// 

  // RSG
  const int n_rsg_samples=5;
  TFile* rsg_samples[n_rsg_samples];
  string rsg_masses[n_rsg_samples] = {"m500","m750","m1000","m1250","m1500"};
  float v_rsg_masses[n_rsg_samples] = {500.,750.,1000.,1250.,1500};
  for(int r=0;r<n_rsg_samples;r++){
    string rsg_loc = file_loc+"merged/mc.rsg."+rsg_masses[r]+".kmpl0_1"+file_end;
    rsg_samples[r] = (TFile*) TFile::Open(rsg_loc.c_str(),"READ");
  }

  // wprime
  const int n_wprime_samples=11;
  TFile* wprime_samples[n_wprime_samples];
  string wprime_masses[n_wprime_samples] =
    {"m500","m600","m700","m800","m900","m1000",
     "m1100","m1200","m1300","m1400","m1500"};
  float v_wprime_masses[n_wprime_samples] =
    {500.,600.,700.,800.,900.,1000.,1100.,1200.,1300.,1400.,1500.};

  for(int r=0;r<n_wprime_samples;r++){
    string wprime_loc = file_loc+"merged/mc.wprime.wz."+wprime_masses[r]+file_end;
    wprime_samples[r] = (TFile*) TFile::Open(wprime_loc.c_str(),"READ");
  }

  TH1F* h_rsg_ps[n_rsg_samples][nProcs];
  TH1F* h_rsg_bpt175[n_rsg_samples][nProcs];
  TH1F* h_rsg_bpt200[n_rsg_samples][nProcs];
  TH1F* h_rsg_bpt225[n_rsg_samples][nProcs];
  TH1F* h_rsg_bpt250[n_rsg_samples][nProcs];
  TH1F* h_rsg_bpt275[n_rsg_samples][nProcs];
  TH1F* h_rsg_bpt300[n_rsg_samples][nProcs];
  
  TH1F* h_wprime_ps[n_wprime_samples][nProcs];
  TH1F* h_wprime_bpt175[n_wprime_samples][nProcs];
  TH1F* h_wprime_bpt200[n_wprime_samples][nProcs];
  TH1F* h_wprime_bpt225[n_wprime_samples][nProcs];
  TH1F* h_wprime_bpt250[n_wprime_samples][nProcs];
  TH1F* h_wprime_bpt275[n_wprime_samples][nProcs];
  TH1F* h_wprime_bpt300[n_wprime_samples][nProcs];


  TH1F* h_bkgd_ps[nProcs];// preselected
  TH1F* h_bkgd_bpt175[nProcs];// pt bosons > 200
  TH1F* h_bkgd_bpt200[nProcs];// pt bosons > 200
  TH1F* h_bkgd_bpt225[nProcs];
  TH1F* h_bkgd_bpt250[nProcs];
  TH1F* h_bkgd_bpt275[nProcs];
  TH1F* h_bkgd_bpt300[nProcs];
    

  for(int p=0;p<nProcs;p++){
    string ps_name = "h_sig_selection_"+procs[p]+"_ps_evt_n";
    h_bkgd_ps[p] = (TH1F*) alpgen_wjets->Get(ps_name.c_str());
    ((TH1F*) h_bkgd_ps[p])->Add((TH1F*) alpgen_qcd->Get(ps_name.c_str()));
    ((TH1F*) h_bkgd_ps[p])->Add((TH1F*) alpgen_zjets->Get(ps_name.c_str()));
    ((TH1F*) h_bkgd_ps[p])->Add((TH1F*) top->Get(ps_name.c_str()));
    ((TH1F*) h_bkgd_ps[p])->Add((TH1F*) vv->Get(ps_name.c_str()));

    string bpt175_name = "h_sig_selection_"+procs[p]+"_dijet_m_bpt175_evt_n";
    h_bkgd_bpt175[p] = (TH1F*) alpgen_wjets->Get(bpt175_name.c_str());
    ((TH1F*) h_bkgd_bpt175[p])->Add((TH1F*) alpgen_qcd->Get(bpt175_name.c_str()));
    ((TH1F*) h_bkgd_bpt175[p])->Add((TH1F*) alpgen_zjets->Get(bpt175_name.c_str()));
    ((TH1F*) h_bkgd_bpt175[p])->Add((TH1F*) top->Get(bpt175_name.c_str()));
    ((TH1F*) h_bkgd_bpt175[p])->Add((TH1F*) vv->Get(bpt175_name.c_str()));

    string bpt200_name = "h_sig_selection_"+procs[p]+"_dijet_m_bpt200_evt_n";
    h_bkgd_bpt200[p] = (TH1F*) alpgen_wjets->Get(bpt200_name.c_str());
    ((TH1F*) h_bkgd_bpt200[p])->Add((TH1F*) alpgen_qcd->Get(bpt200_name.c_str()));
    ((TH1F*) h_bkgd_bpt200[p])->Add((TH1F*) alpgen_zjets->Get(bpt200_name.c_str()));
    ((TH1F*) h_bkgd_bpt200[p])->Add((TH1F*) top->Get(bpt200_name.c_str()));
    ((TH1F*) h_bkgd_bpt200[p])->Add((TH1F*) vv->Get(bpt200_name.c_str()));

    string bpt225_name = "h_sig_selection_"+procs[p]+"_dijet_m_bpt225_evt_n";
    h_bkgd_bpt225[p] = (TH1F*) alpgen_wjets->Get(bpt225_name.c_str());
    ((TH1F*) h_bkgd_bpt225[p])->Add((TH1F*) alpgen_qcd->Get(bpt225_name.c_str()));
    ((TH1F*) h_bkgd_bpt225[p])->Add((TH1F*) alpgen_zjets->Get(bpt225_name.c_str()));
    ((TH1F*) h_bkgd_bpt225[p])->Add((TH1F*) top->Get(bpt225_name.c_str()));
    ((TH1F*) h_bkgd_bpt225[p])->Add((TH1F*) vv->Get(bpt225_name.c_str()));

    string bpt250_name = "h_sig_selection_"+procs[p]+"_dijet_m_bpt250_evt_n";
    h_bkgd_bpt250[p] = (TH1F*) alpgen_wjets->Get(bpt250_name.c_str());
    ((TH1F*) h_bkgd_bpt250[p])->Add((TH1F*) alpgen_qcd->Get(bpt250_name.c_str()));
    ((TH1F*) h_bkgd_bpt250[p])->Add((TH1F*) alpgen_zjets->Get(bpt250_name.c_str()));
    ((TH1F*) h_bkgd_bpt250[p])->Add((TH1F*) top->Get(bpt250_name.c_str()));
    ((TH1F*) h_bkgd_bpt250[p])->Add((TH1F*) vv->Get(bpt250_name.c_str()));

    string bpt275_name = "h_sig_selection_"+procs[p]+"_dijet_m_bpt275_evt_n";
    h_bkgd_bpt275[p] = (TH1F*) alpgen_wjets->Get(bpt275_name.c_str());
    ((TH1F*) h_bkgd_bpt275[p])->Add((TH1F*) alpgen_qcd->Get(bpt275_name.c_str()));
    ((TH1F*) h_bkgd_bpt275[p])->Add((TH1F*) alpgen_zjets->Get(bpt275_name.c_str()));
    ((TH1F*) h_bkgd_bpt275[p])->Add((TH1F*) top->Get(bpt275_name.c_str()));
    ((TH1F*) h_bkgd_bpt275[p])->Add((TH1F*) vv->Get(bpt275_name.c_str()));

    string bpt300_name = "h_sig_selection_"+procs[p]+"_dijet_m_bpt300_evt_n";
    h_bkgd_bpt300[p] = (TH1F*) alpgen_wjets->Get(bpt300_name.c_str());
    ((TH1F*) h_bkgd_bpt300[p])->Add((TH1F*) alpgen_qcd->Get(bpt300_name.c_str()));
    ((TH1F*) h_bkgd_bpt300[p])->Add((TH1F*) alpgen_zjets->Get(bpt300_name.c_str()));
    ((TH1F*) h_bkgd_bpt300[p])->Add((TH1F*) top->Get(bpt300_name.c_str()));
    ((TH1F*) h_bkgd_bpt300[p])->Add((TH1F*) vv->Get(bpt300_name.c_str()));

    //rsg
    for(int r=0;r<n_rsg_samples;r++){

      h_rsg_ps[r][p] = (TH1F*) ((TFile*) rsg_samples[r])->Get(ps_name.c_str());
      h_rsg_bpt175[r][p] = (TH1F*) ((TFile*) rsg_samples[r])->Get(bpt175_name.c_str());
      h_rsg_bpt200[r][p] = (TH1F*) ((TFile*) rsg_samples[r])->Get(bpt200_name.c_str());
      h_rsg_bpt225[r][p] = (TH1F*) ((TFile*) rsg_samples[r])->Get(bpt225_name.c_str());
      h_rsg_bpt250[r][p] = (TH1F*) ((TFile*) rsg_samples[r])->Get(bpt250_name.c_str());
      h_rsg_bpt275[r][p] = (TH1F*) ((TFile*) rsg_samples[r])->Get(bpt275_name.c_str());
      h_rsg_bpt300[r][p] = (TH1F*) ((TFile*) rsg_samples[r])->Get(bpt300_name.c_str());
    }

    //wprime
    for(int r=0;r<n_wprime_samples;r++){
      h_wprime_ps[r][p] = (TH1F*) ((TFile*) wprime_samples[r])->Get(ps_name.c_str());
      h_wprime_bpt175[r][p] = (TH1F*) ((TFile*) wprime_samples[r])->Get(bpt175_name.c_str());
      h_wprime_bpt200[r][p] = (TH1F*) ((TFile*) wprime_samples[r])->Get(bpt200_name.c_str());
      h_wprime_bpt225[r][p] = (TH1F*) ((TFile*) wprime_samples[r])->Get(bpt225_name.c_str());
      h_wprime_bpt250[r][p] = (TH1F*) ((TFile*) wprime_samples[r])->Get(bpt250_name.c_str());
      h_wprime_bpt275[r][p] = (TH1F*) ((TFile*) wprime_samples[r])->Get(bpt275_name.c_str());
      h_wprime_bpt300[r][p] = (TH1F*) ((TFile*) wprime_samples[r])->Get(bpt300_name.c_str());
    }
  }// background and signals loaded


  // rsg
  float rsg_comb_ps_acceptances[n_rsg_samples]={0.};
  float rsg_comb_bpt175_acceptances[n_rsg_samples]={0.};
  float rsg_comb_bpt200_acceptances[n_rsg_samples]={0.};
  float rsg_comb_bpt225_acceptances[n_rsg_samples]={0.};
  float rsg_comb_bpt250_acceptances[n_rsg_samples]={0.};
  float rsg_comb_bpt275_acceptances[n_rsg_samples]={0.};
  float rsg_comb_bpt300_acceptances[n_rsg_samples]={0.};
  
  float rsg_comb_ps_significance[n_rsg_samples]={0.};
  float rsg_comb_bpt175_significance[n_rsg_samples]={0.};
  float rsg_comb_bpt200_significance[n_rsg_samples]={0.};
  float rsg_comb_bpt225_significance[n_rsg_samples]={0.};
  float rsg_comb_bpt250_significance[n_rsg_samples]={0.};
  float rsg_comb_bpt275_significance[n_rsg_samples]={0.};
  float rsg_comb_bpt300_significance[n_rsg_samples]={0.};
  
  float rsg_comb_ps_sig_to_bkgd[n_rsg_samples]={0.};
  float rsg_comb_bpt175_sig_to_bkgd[n_rsg_samples]={0.};
  float rsg_comb_bpt200_sig_to_bkgd[n_rsg_samples]={0.};
  float rsg_comb_bpt225_sig_to_bkgd[n_rsg_samples]={0.};
  float rsg_comb_bpt250_sig_to_bkgd[n_rsg_samples]={0.};
  float rsg_comb_bpt275_sig_to_bkgd[n_rsg_samples]={0.};
  float rsg_comb_bpt300_sig_to_bkgd[n_rsg_samples]={0.};

  for(int r=0;r<n_rsg_samples;r++){

    //rsg: acceptance
    float cur_rsg_ps_acceptance =
      ((((TH1F*) h_rsg_ps[r][0])->Integral()/h_rsg_ps[r][0]->Integral()) +
       ((TH1F*) h_rsg_ps[r][1])->Integral()/h_rsg_ps[r][1]->Integral())/2.;
    rsg_comb_ps_acceptances[r]=(cur_rsg_ps_acceptance);
    float cur_rsg_bpt175_acceptance =
      ((((TH1F*) h_rsg_bpt175[r][0])->Integral()/h_rsg_ps[r][0]->Integral()) +
       ((TH1F*) h_rsg_bpt175[r][1])->Integral()/h_rsg_ps[r][1]->Integral())/2.;
    rsg_comb_bpt175_acceptances[r]=(cur_rsg_bpt175_acceptance);
    float cur_rsg_bpt200_acceptance =
      ((((TH1F*) h_rsg_bpt200[r][0])->Integral()/h_rsg_ps[r][0]->Integral()) +
       ((TH1F*) h_rsg_bpt200[r][1])->Integral()/h_rsg_ps[r][1]->Integral())/2.;
    rsg_comb_bpt200_acceptances[r]=(cur_rsg_bpt200_acceptance);
    float cur_rsg_bpt225_acceptance =
      ((((TH1F*) h_rsg_bpt225[r][0])->Integral()/h_rsg_ps[r][0]->Integral()) +
       ((TH1F*) h_rsg_bpt225[r][1])->Integral()/h_rsg_ps[r][1]->Integral())/2.;
    rsg_comb_bpt225_acceptances[r]=(cur_rsg_bpt225_acceptance);
    float cur_rsg_bpt250_acceptance =
      ((((TH1F*) h_rsg_bpt250[r][0])->Integral()/h_rsg_ps[r][0]->Integral()) +
       ((TH1F*) h_rsg_bpt250[r][1])->Integral()/h_rsg_ps[r][1]->Integral())/2.;
    rsg_comb_bpt250_acceptances[r]=(cur_rsg_bpt250_acceptance);
    float cur_rsg_bpt275_acceptance =
      ((((TH1F*) h_rsg_bpt275[r][0])->Integral()/h_rsg_ps[r][0]->Integral()) +
       ((TH1F*) h_rsg_bpt275[r][1])->Integral()/h_rsg_ps[r][1]->Integral())/2.;
    rsg_comb_bpt275_acceptances[r]=(cur_rsg_bpt275_acceptance);
    float cur_rsg_bpt300_acceptance =
      ((((TH1F*) h_rsg_bpt300[r][0])->Integral()/h_rsg_ps[r][0]->Integral()) +
       ((TH1F*) h_rsg_bpt300[r][1])->Integral()/h_rsg_ps[r][1]->Integral())/2.;
    rsg_comb_bpt300_acceptances[r]=(cur_rsg_bpt300_acceptance);

    //sig_to_bkgd = S/B
    float cur_rsg_ps_sig_to_bkgd =
      ((((TH1F*) h_rsg_ps[r][0])->Integral()/h_bkgd_ps[0]->Integral()) +
       ((TH1F*) h_rsg_ps[r][1])->Integral()/h_bkgd_ps[1]->Integral())/2.;
    rsg_comb_ps_sig_to_bkgd[r]=(cur_rsg_ps_sig_to_bkgd);
    float cur_rsg_bpt175_sig_to_bkgd =
      ((((TH1F*) h_rsg_bpt175[r][0])->Integral()/h_bkgd_bpt175[0]->Integral()) +
       ((TH1F*) h_rsg_bpt175[r][1])->Integral()/h_bkgd_bpt175[1]->Integral())/2.;
    rsg_comb_bpt175_sig_to_bkgd[r]=(cur_rsg_bpt175_sig_to_bkgd);
    float cur_rsg_bpt200_sig_to_bkgd =
      ((((TH1F*) h_rsg_bpt200[r][0])->Integral()/h_bkgd_bpt200[0]->Integral()) +
       ((TH1F*) h_rsg_bpt200[r][1])->Integral()/h_bkgd_bpt200[1]->Integral())/2.;
    rsg_comb_bpt200_sig_to_bkgd[r]=(cur_rsg_bpt200_sig_to_bkgd);
    float cur_rsg_bpt225_sig_to_bkgd =
      ((((TH1F*) h_rsg_bpt225[r][0])->Integral()/h_bkgd_bpt225[0]->Integral()) +
       ((TH1F*) h_rsg_bpt225[r][1])->Integral()/h_bkgd_bpt225[1]->Integral())/2.;
    rsg_comb_bpt225_sig_to_bkgd[r]=(cur_rsg_bpt225_sig_to_bkgd);
    float cur_rsg_bpt250_sig_to_bkgd =
      ((((TH1F*) h_rsg_bpt250[r][0])->Integral()/h_bkgd_bpt250[0]->Integral()) +
       ((TH1F*) h_rsg_bpt250[r][1])->Integral()/h_bkgd_bpt250[1]->Integral())/2.;
    rsg_comb_bpt250_sig_to_bkgd[r]=(cur_rsg_bpt250_sig_to_bkgd);
    float cur_rsg_bpt275_sig_to_bkgd =
      ((((TH1F*) h_rsg_bpt275[r][0])->Integral()/h_bkgd_bpt275[0]->Integral()) +
       ((TH1F*) h_rsg_bpt275[r][1])->Integral()/h_bkgd_bpt275[1]->Integral())/2.;
    rsg_comb_bpt275_sig_to_bkgd[r]=(cur_rsg_bpt275_sig_to_bkgd);
    float cur_rsg_bpt300_sig_to_bkgd =
      ((((TH1F*) h_rsg_bpt300[r][0])->Integral()/h_bkgd_bpt300[0]->Integral()) +
       ((TH1F*) h_rsg_bpt300[r][1])->Integral()/h_bkgd_bpt300[1]->Integral())/2.;
    rsg_comb_bpt300_sig_to_bkgd[r]=(cur_rsg_bpt300_sig_to_bkgd);

    //significance = S/sqrt(B)
    float cur_rsg_ps_significance =
      ((((TH1F*) h_rsg_ps[r][0])->Integral()/sqrt(h_bkgd_ps[0]->Integral())) +
       ((TH1F*) h_rsg_ps[r][1])->Integral()/sqrt(h_bkgd_ps[1]->Integral()))/2.;
    rsg_comb_ps_significance[r]=(cur_rsg_ps_significance);
    float cur_rsg_bpt175_significance =
      ((((TH1F*) h_rsg_bpt175[r][0])->Integral()/sqrt(h_bkgd_bpt175[0]->Integral())) +
       ((TH1F*) h_rsg_bpt175[r][1])->Integral()/sqrt(h_bkgd_bpt175[1]->Integral()))/2.;
    rsg_comb_bpt175_significance[r]=(cur_rsg_bpt175_significance);
    float cur_rsg_bpt200_significance =
      ((((TH1F*) h_rsg_bpt200[r][0])->Integral()/sqrt(h_bkgd_bpt200[0]->Integral())) +
       ((TH1F*) h_rsg_bpt200[r][1])->Integral()/sqrt(h_bkgd_bpt200[1]->Integral()))/2.;
    rsg_comb_bpt200_significance[r]=(cur_rsg_bpt200_significance);
    float cur_rsg_bpt225_significance =
      ((((TH1F*) h_rsg_bpt225[r][0])->Integral()/sqrt(h_bkgd_bpt225[0]->Integral())) +
       ((TH1F*) h_rsg_bpt225[r][1])->Integral()/sqrt(h_bkgd_bpt225[1]->Integral()))/2.;
    rsg_comb_bpt225_significance[r]=(cur_rsg_bpt225_significance);
    float cur_rsg_bpt250_significance =
      ((((TH1F*) h_rsg_bpt250[r][0])->Integral()/sqrt(h_bkgd_bpt250[0]->Integral())) +
       ((TH1F*) h_rsg_bpt250[r][1])->Integral()/sqrt(h_bkgd_bpt250[1]->Integral()))/2.;
    rsg_comb_bpt250_significance[r]=(cur_rsg_bpt250_significance);
    float cur_rsg_bpt275_significance =
      ((((TH1F*) h_rsg_bpt275[r][0])->Integral()/sqrt(h_bkgd_bpt275[0]->Integral())) +
       ((TH1F*) h_rsg_bpt275[r][1])->Integral()/sqrt(h_bkgd_bpt275[1]->Integral()))/2.;
    rsg_comb_bpt275_significance[r]=(cur_rsg_bpt275_significance);
    float cur_rsg_bpt300_significance =
      ((((TH1F*) h_rsg_bpt300[r][0])->Integral()/sqrt(h_bkgd_bpt300[0]->Integral())) +
       ((TH1F*) h_rsg_bpt300[r][1])->Integral()/sqrt(h_bkgd_bpt300[1]->Integral()))/2.;
    rsg_comb_bpt300_significance[r]=(cur_rsg_bpt300_significance);

  }

  // wprime
  float wprime_comb_ps_acceptances[n_wprime_samples]={0.};
  float wprime_comb_bpt175_acceptances[n_wprime_samples]={0.};
  float wprime_comb_bpt200_acceptances[n_wprime_samples]={0.};
  float wprime_comb_bpt225_acceptances[n_wprime_samples]={0.};
  float wprime_comb_bpt250_acceptances[n_wprime_samples]={0.};
  float wprime_comb_bpt275_acceptances[n_wprime_samples]={0.};
  float wprime_comb_bpt300_acceptances[n_wprime_samples]={0.};
  
  float wprime_comb_ps_significance[n_wprime_samples]={0.};
  float wprime_comb_bpt175_significance[n_wprime_samples]={0.};
  float wprime_comb_bpt200_significance[n_wprime_samples]={0.};
  float wprime_comb_bpt225_significance[n_wprime_samples]={0.};
  float wprime_comb_bpt250_significance[n_wprime_samples]={0.};
  float wprime_comb_bpt275_significance[n_wprime_samples]={0.};
  float wprime_comb_bpt300_significance[n_wprime_samples]={0.};
  
  float wprime_comb_ps_sig_to_bkgd[n_wprime_samples]={0.};
  float wprime_comb_bpt175_sig_to_bkgd[n_wprime_samples]={0.};
  float wprime_comb_bpt200_sig_to_bkgd[n_wprime_samples]={0.};
  float wprime_comb_bpt225_sig_to_bkgd[n_wprime_samples]={0.};
  float wprime_comb_bpt250_sig_to_bkgd[n_wprime_samples]={0.};
  float wprime_comb_bpt275_sig_to_bkgd[n_wprime_samples]={0.};
  float wprime_comb_bpt300_sig_to_bkgd[n_wprime_samples]={0.};
  
  for(int r=0;r<n_wprime_samples;r++){

    //wprime: acceptance
    float cur_wprime_ps_acceptance =
      ((((TH1F*) h_wprime_ps[r][0])->Integral()/h_wprime_ps[r][0]->Integral()) +
       ((TH1F*) h_wprime_ps[r][1])->Integral()/h_wprime_ps[r][1]->Integral())/2.;
    wprime_comb_ps_acceptances[r]=(cur_wprime_ps_acceptance);
    float cur_wprime_bpt175_acceptance =
      ((((TH1F*) h_wprime_bpt175[r][0])->Integral()/h_wprime_ps[r][0]->Integral()) +
       ((TH1F*) h_wprime_bpt175[r][1])->Integral()/h_wprime_ps[r][1]->Integral())/2.;
    wprime_comb_bpt175_acceptances[r]=(cur_wprime_bpt175_acceptance);
    float cur_wprime_bpt200_acceptance =
      ((((TH1F*) h_wprime_bpt200[r][0])->Integral()/h_wprime_ps[r][0]->Integral()) +
       ((TH1F*) h_wprime_bpt200[r][1])->Integral()/h_wprime_ps[r][1]->Integral())/2.;
    wprime_comb_bpt200_acceptances[r]=(cur_wprime_bpt200_acceptance);
    float cur_wprime_bpt225_acceptance =
      ((((TH1F*) h_wprime_bpt225[r][0])->Integral()/h_wprime_ps[r][0]->Integral()) +
       ((TH1F*) h_wprime_bpt225[r][1])->Integral()/h_wprime_ps[r][1]->Integral())/2.;
    wprime_comb_bpt225_acceptances[r]=(cur_wprime_bpt225_acceptance);
    float cur_wprime_bpt250_acceptance =
      ((((TH1F*) h_wprime_bpt250[r][0])->Integral()/h_wprime_ps[r][0]->Integral()) +
       ((TH1F*) h_wprime_bpt250[r][1])->Integral()/h_wprime_ps[r][1]->Integral())/2.;
    wprime_comb_bpt250_acceptances[r]=(cur_wprime_bpt250_acceptance);
    float cur_wprime_bpt275_acceptance =
      ((((TH1F*) h_wprime_bpt275[r][0])->Integral()/h_wprime_ps[r][0]->Integral()) +
       ((TH1F*) h_wprime_bpt275[r][1])->Integral()/h_wprime_ps[r][1]->Integral())/2.;
    wprime_comb_bpt275_acceptances[r]=(cur_wprime_bpt275_acceptance);
    float cur_wprime_bpt300_acceptance =
      ((((TH1F*) h_wprime_bpt300[r][0])->Integral()/h_wprime_ps[r][0]->Integral()) +
       ((TH1F*) h_wprime_bpt300[r][1])->Integral()/h_wprime_ps[r][1]->Integral())/2.;
    wprime_comb_bpt300_acceptances[r]=(cur_wprime_bpt300_acceptance);

    //sig_to_bkgd = S/B
    float cur_wprime_ps_sig_to_bkgd =
      ((((TH1F*) h_wprime_ps[r][0])->Integral()/h_bkgd_ps[0]->Integral()) +
       ((TH1F*) h_wprime_ps[r][1])->Integral()/h_bkgd_ps[1]->Integral())/2.;
    wprime_comb_ps_sig_to_bkgd[r]=(cur_wprime_ps_sig_to_bkgd);
    float cur_wprime_bpt175_sig_to_bkgd =
      ((((TH1F*) h_wprime_bpt175[r][0])->Integral()/h_bkgd_bpt175[0]->Integral()) +
       ((TH1F*) h_wprime_bpt175[r][1])->Integral()/h_bkgd_bpt175[1]->Integral())/2.;
    wprime_comb_bpt175_sig_to_bkgd[r]=(cur_wprime_bpt175_sig_to_bkgd);
    float cur_wprime_bpt200_sig_to_bkgd =
      ((((TH1F*) h_wprime_bpt200[r][0])->Integral()/h_bkgd_bpt200[0]->Integral()) +
       ((TH1F*) h_wprime_bpt200[r][1])->Integral()/h_bkgd_bpt200[1]->Integral())/2.;
    wprime_comb_bpt200_sig_to_bkgd[r]=(cur_wprime_bpt200_sig_to_bkgd);
    float cur_wprime_bpt225_sig_to_bkgd =
      ((((TH1F*) h_wprime_bpt225[r][0])->Integral()/h_bkgd_bpt225[0]->Integral()) +
       ((TH1F*) h_wprime_bpt225[r][1])->Integral()/h_bkgd_bpt225[1]->Integral())/2.;
    wprime_comb_bpt225_sig_to_bkgd[r]=(cur_wprime_bpt225_sig_to_bkgd);
    float cur_wprime_bpt250_sig_to_bkgd =
      ((((TH1F*) h_wprime_bpt250[r][0])->Integral()/h_bkgd_bpt225[0]->Integral()) +
       ((TH1F*) h_wprime_bpt250[r][1])->Integral()/h_bkgd_bpt225[1]->Integral())/2.;
    wprime_comb_bpt250_sig_to_bkgd[r]=(cur_wprime_bpt250_sig_to_bkgd);
    float cur_wprime_bpt275_sig_to_bkgd =
      ((((TH1F*) h_wprime_bpt275[r][0])->Integral()/h_bkgd_bpt225[0]->Integral()) +
       ((TH1F*) h_wprime_bpt275[r][1])->Integral()/h_bkgd_bpt200[1]->Integral())/2.;
    wprime_comb_bpt275_sig_to_bkgd[r]=(cur_wprime_bpt275_sig_to_bkgd);
    float cur_wprime_bpt300_sig_to_bkgd =
      ((((TH1F*) h_wprime_bpt300[r][0])->Integral()/h_bkgd_bpt225[0]->Integral()) +
       ((TH1F*) h_wprime_bpt300[r][1])->Integral()/h_bkgd_bpt225[1]->Integral())/2.;
    wprime_comb_bpt300_sig_to_bkgd[r]=(cur_wprime_bpt300_sig_to_bkgd);

    //significance = S/sqrt(B)
    float cur_wprime_ps_significance =
      ((((TH1F*) h_wprime_ps[r][0])->Integral()/sqrt(h_bkgd_ps[0]->Integral())) +
       ((TH1F*) h_wprime_ps[r][1])->Integral()/sqrt(h_bkgd_ps[1]->Integral()))/2.;
    wprime_comb_ps_significance[r]=(cur_wprime_ps_significance);
    float cur_wprime_bpt175_significance =
      ((((TH1F*) h_wprime_bpt175[r][0])->Integral()/sqrt(h_bkgd_bpt175[0]->Integral())) +
       ((TH1F*) h_wprime_bpt175[r][1])->Integral()/sqrt(h_bkgd_bpt175[1]->Integral()))/2.;
    wprime_comb_bpt175_significance[r]=(cur_wprime_bpt175_significance);
    float cur_wprime_bpt200_significance =
      ((((TH1F*) h_wprime_bpt200[r][0])->Integral()/sqrt(h_bkgd_bpt200[0]->Integral())) +
       ((TH1F*) h_wprime_bpt200[r][1])->Integral()/sqrt(h_bkgd_bpt200[1]->Integral()))/2.;
    wprime_comb_bpt200_significance[r]=(cur_wprime_bpt200_significance);
    float cur_wprime_bpt225_significance =
      ((((TH1F*) h_wprime_bpt225[r][0])->Integral()/sqrt(h_bkgd_bpt225[0]->Integral())) +
       ((TH1F*) h_wprime_bpt225[r][1])->Integral()/sqrt(h_bkgd_bpt225[1]->Integral()))/2.;
    wprime_comb_bpt225_significance[r]=(cur_wprime_bpt225_significance);
    float cur_wprime_bpt250_significance =
      ((((TH1F*) h_wprime_bpt250[r][0])->Integral()/sqrt(h_bkgd_bpt250[0]->Integral())) +
       ((TH1F*) h_wprime_bpt250[r][1])->Integral()/sqrt(h_bkgd_bpt250[1]->Integral()))/2.;
    wprime_comb_bpt250_significance[r]=(cur_wprime_bpt250_significance);
    float cur_wprime_bpt275_significance =
      ((((TH1F*) h_wprime_bpt275[r][0])->Integral()/sqrt(h_bkgd_bpt275[0]->Integral())) +
       ((TH1F*) h_wprime_bpt275[r][1])->Integral()/sqrt(h_bkgd_bpt275[1]->Integral()))/2.;
    wprime_comb_bpt275_significance[r]=(cur_wprime_bpt275_significance);
    float cur_wprime_bpt300_significance =
      ((((TH1F*) h_wprime_bpt300[r][0])->Integral()/sqrt(h_bkgd_bpt300[0]->Integral())) +
       ((TH1F*) h_wprime_bpt300[r][1])->Integral()/sqrt(h_bkgd_bpt300[1]->Integral()))/2.;
    wprime_comb_bpt300_significance[r]=(cur_wprime_bpt300_significance);

  }


  

  
  // rsg
  TCanvas *tc_rsg_acceptances =
    new TCanvas("tc_rsg_acceptances","RSG Acceptances",200,10,700,500);
  tc_rsg_acceptances->SetGrid();
  tc_rsg_acceptances->SetFillColor(0);

  TH1F *frame_rsg_acceptances = tc_rsg_acceptances->DrawFrame(450,0,1550,1.05);
  frame_rsg_acceptances->GetYaxis()->SetTitleSize(0.05);
  frame_rsg_acceptances->GetYaxis()->SetTitleOffset(0.8);
  frame_rsg_acceptances->GetXaxis()->SetTitleSize(0.05);
  frame_rsg_acceptances->GetXaxis()->SetTitleOffset(0.8);
  frame_rsg_acceptances->SetXTitle("G* Mass");
  frame_rsg_acceptances->SetYTitle("Acceptance");


  TGraph* gr_rsg_ps_acceptances =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_ps_acceptances);
  gr_rsg_ps_acceptances->SetTitle("RSG Acceptances");
  gr_rsg_ps_acceptances->Draw("C*");

  TGraph* gr_rsg_bpt175_acceptances =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_bpt175_acceptances);
  gr_rsg_bpt175_acceptances->SetLineColor(kGreen);
  gr_rsg_bpt175_acceptances->SetMarkerColor(kGreen);
  gr_rsg_bpt175_acceptances->Draw("C*");

  TGraph* gr_rsg_bpt200_acceptances =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_bpt200_acceptances);
  gr_rsg_bpt200_acceptances->SetLineColor(kRed);
  gr_rsg_bpt200_acceptances->SetMarkerColor(kRed);
  gr_rsg_bpt200_acceptances->Draw("C*");

  TGraph* gr_rsg_bpt225_acceptances =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_bpt225_acceptances);
  gr_rsg_bpt225_acceptances->SetLineColor(kBlue);
  gr_rsg_bpt225_acceptances->SetMarkerColor(kBlue);
  gr_rsg_bpt225_acceptances->Draw("C*");

  TGraph* gr_rsg_bpt250_acceptances =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_bpt250_acceptances);
  gr_rsg_bpt250_acceptances->SetLineColor(kMagenta);
  gr_rsg_bpt250_acceptances->SetMarkerColor(kMagenta);
  gr_rsg_bpt250_acceptances->Draw("C*");

  TGraph* gr_rsg_bpt275_acceptances =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_bpt275_acceptances);
  gr_rsg_bpt275_acceptances->SetLineColor(kOrange);
  gr_rsg_bpt275_acceptances->SetMarkerColor(kOrange);
  gr_rsg_bpt275_acceptances->Draw("C*");

  TGraph* gr_rsg_bpt300_acceptances =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_bpt300_acceptances);
  gr_rsg_bpt300_acceptances->SetLineColor(kTeal);
  gr_rsg_bpt300_acceptances->SetMarkerColor(kTeal);
  gr_rsg_bpt300_acceptances->Draw("C*");

  
  TLegend* lgnd_rsg_sig_acceptances = new TLegend(0.5,0.55,0.9,0.85);
  lgnd_rsg_sig_acceptances->SetTextSize(0.04);
  lgnd_rsg_sig_acceptances->SetFillColor(0);
  lgnd_rsg_sig_acceptances->AddEntry(gr_rsg_ps_acceptances,"preselection","L");
  lgnd_rsg_sig_acceptances->AddEntry(gr_rsg_bpt175_acceptances,"pt(l#nu)>175 && pt(jj)>175","L");
  lgnd_rsg_sig_acceptances->AddEntry(gr_rsg_bpt200_acceptances,"pt(l#nu)>200 && pt(jj)>200","L");
  lgnd_rsg_sig_acceptances->AddEntry(gr_rsg_bpt225_acceptances,"pt(l#nu)>225 && pt(jj)>225","L");
  lgnd_rsg_sig_acceptances->AddEntry(gr_rsg_bpt250_acceptances,"pt(l#nu)>250 && pt(jj)>250","L");
  lgnd_rsg_sig_acceptances->AddEntry(gr_rsg_bpt275_acceptances,"pt(l#nu)>275 && pt(jj)>275","L");
  lgnd_rsg_sig_acceptances->AddEntry(gr_rsg_bpt300_acceptances,"pt(l#nu)>300 && pt(jj)>300","L");
  lgnd_rsg_sig_acceptances->Draw();

  tc_rsg_acceptances->cd();
  tc_rsg_acceptances->SaveAs("./graphs/rsg_selection_acceptances.pdf");


  //rsg: significance
  TCanvas *tc_rsg_significance =
    new TCanvas("tc_rsg_significance","RSG significance (S/sqrt(B))",200,10,700,500);

  tc_rsg_significance->SetGrid();
  tc_rsg_significance->SetTicky(1);
  tc_rsg_significance->SetLogy();
  tc_rsg_significance->SetFillColor(0);
  
  TH1F *frame_rsg_significance = tc_rsg_significance->DrawFrame(450,0.001,1550,30);
  frame_rsg_significance->GetYaxis()->SetTitleSize(0.05);
  frame_rsg_significance->GetYaxis()->SetTitleOffset(0.8);
  frame_rsg_significance->GetXaxis()->SetTitleSize(0.05);
  frame_rsg_significance->GetXaxis()->SetTitleOffset(0.8);
  frame_rsg_significance->SetXTitle("G* Mass");
  frame_rsg_significance->SetYTitle("#frac{S}{#sqrt{B}}");

  
  TGraph* gr_rsg_bpt175_significance =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_bpt175_significance);
  gr_rsg_bpt175_significance->SetTitle("RSG signal to background");
  gr_rsg_bpt175_significance->SetLineColor(kGreen);
  gr_rsg_bpt175_significance->SetMarkerColor(kGreen);
  gr_rsg_bpt175_significance->Draw("C*");

  TGraph* gr_rsg_bpt200_significance =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_bpt200_significance);
  gr_rsg_bpt200_significance->SetLineColor(kRed);
  gr_rsg_bpt200_significance->SetMarkerColor(kRed);
  gr_rsg_bpt200_significance->Draw("C*");

  TGraph* gr_rsg_bpt225_significance =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_bpt225_significance);
  gr_rsg_bpt225_significance->SetLineColor(kBlue);
  gr_rsg_bpt225_significance->SetMarkerColor(kBlue);
  gr_rsg_bpt225_significance->Draw("C*");

  TGraph* gr_rsg_bpt250_significance =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_bpt250_significance);
  gr_rsg_bpt250_significance->SetLineColor(kMagenta);
  gr_rsg_bpt250_significance->SetMarkerColor(kMagenta);
  gr_rsg_bpt250_significance->Draw("C*");

  TGraph* gr_rsg_bpt275_significance =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_bpt275_significance);
  gr_rsg_bpt275_significance->SetLineColor(kOrange);
  gr_rsg_bpt275_significance->SetMarkerColor(kOrange);
  gr_rsg_bpt275_significance->Draw("C*");

  TGraph* gr_rsg_bpt300_significance =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_bpt300_significance);
  gr_rsg_bpt300_significance->SetLineColor(kTeal);
  gr_rsg_bpt300_significance->SetMarkerColor(kTeal);
  gr_rsg_bpt300_significance->Draw("C*");

  TGraph* gr_rsg_ps_significance =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_ps_significance);
  gr_rsg_ps_significance->SetLineWidth(2);
  gr_rsg_ps_significance->Draw("C*");

  TLegend* lgnd_rsg_significance = new TLegend(0.15,0.15,0.55,0.45);
  lgnd_rsg_significance->SetTextSize(0.04);
  lgnd_rsg_significance->SetFillColor(0);
  lgnd_rsg_significance->AddEntry(gr_rsg_ps_significance,"preselection","L");
  lgnd_rsg_significance->AddEntry(gr_rsg_bpt175_significance,"pt(l#nu)>175 && pt(jj)>175","L");
  lgnd_rsg_significance->AddEntry(gr_rsg_bpt200_significance,"pt(l#nu)>200 && pt(jj)>200","L");
  lgnd_rsg_significance->AddEntry(gr_rsg_bpt225_significance,"pt(l#nu)>225 && pt(jj)>225","L");
  lgnd_rsg_significance->AddEntry(gr_rsg_bpt250_significance,"pt(l#nu)>250 && pt(jj)>250","L");
  lgnd_rsg_significance->AddEntry(gr_rsg_bpt275_significance,"pt(l#nu)>275 && pt(jj)>275","L");
  lgnd_rsg_significance->AddEntry(gr_rsg_bpt300_significance,"pt(l#nu)>300 && pt(jj)>300","L");
  
  lgnd_rsg_significance->Draw();

  tc_rsg_significance->SaveAs("./graphs/rsg_selection_significance.pdf");

  //rsg sig_to_bkgd
  TCanvas *tc_rsg_sig_to_bkgd =
    new TCanvas("tc_rsg_sig_to_bkgd","RSG S/B",200,10,700,500);

  tc_rsg_sig_to_bkgd->SetGrid();
  tc_rsg_sig_to_bkgd->SetLogy();
  tc_rsg_sig_to_bkgd->SetFillColor(0);
  
  TH1F *frame_rsg_sig_to_bkgd = tc_rsg_sig_to_bkgd->DrawFrame(450,0.0001,1550,1.1);
  frame_rsg_sig_to_bkgd->GetYaxis()->SetTitleSize(0.05);
  frame_rsg_sig_to_bkgd->GetYaxis()->SetTitleOffset(0.8);
  frame_rsg_sig_to_bkgd->GetXaxis()->SetTitleSize(0.05);
  frame_rsg_sig_to_bkgd->GetXaxis()->SetTitleOffset(0.8);
  frame_rsg_sig_to_bkgd->SetXTitle("G* Mass");
  frame_rsg_sig_to_bkgd->SetYTitle("#frac{S}{B}");

  TGraph* gr_rsg_bpt175_sig_to_bkgd =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_bpt175_sig_to_bkgd);
  gr_rsg_bpt175_sig_to_bkgd->SetTitle("RSG S/B");
  gr_rsg_bpt175_sig_to_bkgd->SetLineColor(kGreen);
  gr_rsg_bpt175_sig_to_bkgd->SetMarkerColor(kGreen);
  gr_rsg_bpt175_sig_to_bkgd->Draw("C*");

  TGraph* gr_rsg_bpt200_sig_to_bkgd =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_bpt200_sig_to_bkgd);
  gr_rsg_bpt200_sig_to_bkgd->SetLineColor(kRed);
  gr_rsg_bpt200_sig_to_bkgd->SetMarkerColor(kRed);
  gr_rsg_bpt200_sig_to_bkgd->Draw("C*");

  TGraph* gr_rsg_bpt225_sig_to_bkgd =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_bpt225_sig_to_bkgd);
  gr_rsg_bpt225_sig_to_bkgd->SetLineColor(kBlue);
  gr_rsg_bpt225_sig_to_bkgd->SetMarkerColor(kBlue);
  gr_rsg_bpt225_sig_to_bkgd->Draw("C*");

  TGraph* gr_rsg_bpt250_sig_to_bkgd =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_bpt250_sig_to_bkgd);
  gr_rsg_bpt250_sig_to_bkgd->SetLineColor(kMagenta);
  gr_rsg_bpt250_sig_to_bkgd->SetMarkerColor(kMagenta);
  gr_rsg_bpt250_sig_to_bkgd->Draw("C*");

  TGraph* gr_rsg_bpt275_sig_to_bkgd =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_bpt275_sig_to_bkgd);
  gr_rsg_bpt275_sig_to_bkgd->SetLineColor(kOrange);
  gr_rsg_bpt275_sig_to_bkgd->SetMarkerColor(kOrange);
  gr_rsg_bpt275_sig_to_bkgd->Draw("C*");

  TGraph* gr_rsg_bpt300_sig_to_bkgd =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_bpt300_sig_to_bkgd);
  gr_rsg_bpt300_sig_to_bkgd->SetLineColor(kTeal);
  gr_rsg_bpt300_sig_to_bkgd->SetMarkerColor(kTeal);
  gr_rsg_bpt300_sig_to_bkgd->Draw("C*");

  TGraph* gr_rsg_ps_sig_to_bkgd =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_ps_sig_to_bkgd);
  gr_rsg_ps_sig_to_bkgd->Draw("C*");

  TLegend* lgnd_rsg_sig_to_bkgd = new TLegend(0.55,0.70,0.95,0.95);
  lgnd_rsg_sig_to_bkgd->SetTextSize(0.04);
  lgnd_rsg_sig_to_bkgd->SetFillColor(0);
  lgnd_rsg_sig_to_bkgd->AddEntry(gr_rsg_ps_sig_to_bkgd,"preselection","L");
  lgnd_rsg_sig_to_bkgd->AddEntry(gr_rsg_bpt175_sig_to_bkgd,"pt(l#nu)>175 && pt(jj)>175","L");
  lgnd_rsg_sig_to_bkgd->AddEntry(gr_rsg_bpt200_sig_to_bkgd,"pt(l#nu)>200 && pt(jj)>200","L");
  lgnd_rsg_sig_to_bkgd->AddEntry(gr_rsg_bpt225_sig_to_bkgd,"pt(l#nu)>225 && pt(jj)>225","L");
  lgnd_rsg_sig_to_bkgd->AddEntry(gr_rsg_bpt250_sig_to_bkgd,"pt(l#nu)>250 && pt(jj)>250","L");
  lgnd_rsg_sig_to_bkgd->AddEntry(gr_rsg_bpt275_sig_to_bkgd,"pt(l#nu)>275 && pt(jj)>275","L");
  lgnd_rsg_sig_to_bkgd->AddEntry(gr_rsg_bpt300_sig_to_bkgd,"pt(l#nu)>300 && pt(jj)>300","L");
  lgnd_rsg_sig_to_bkgd->Draw();

  tc_rsg_sig_to_bkgd->SaveAs("./graphs/rsg_selection_sig_to_bkgd.pdf");



    // wprime
  TCanvas *tc_wprime_acceptances =
    new TCanvas("tc_wprime_acceptances","W' Acceptances",200,10,700,500);
  tc_wprime_acceptances->SetGrid();
  tc_wprime_acceptances->SetFillColor(0);

  TH1F *frame_wprime_acceptances = tc_wprime_acceptances->DrawFrame(450,0,1550,1.05);
  frame_wprime_acceptances->GetYaxis()->SetTitleSize(0.05);
  frame_wprime_acceptances->GetYaxis()->SetTitleOffset(0.8);
  frame_wprime_acceptances->GetXaxis()->SetTitleSize(0.05);
  frame_wprime_acceptances->GetXaxis()->SetTitleOffset(0.8);
  frame_wprime_acceptances->SetXTitle("W' Mass");
  frame_wprime_acceptances->SetYTitle("Acceptance");


  TGraph* gr_wprime_ps_acceptances =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_ps_acceptances);
  gr_wprime_ps_acceptances->SetTitle("W' Acceptances");
  gr_wprime_ps_acceptances->Draw("C*");

  TGraph* gr_wprime_bpt175_acceptances =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_bpt175_acceptances);
  gr_wprime_bpt175_acceptances->SetLineColor(kGreen);
  gr_wprime_bpt175_acceptances->SetMarkerColor(kGreen);
  gr_wprime_bpt175_acceptances->Draw("C*");

  TGraph* gr_wprime_bpt200_acceptances =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_bpt200_acceptances);
  gr_wprime_bpt200_acceptances->SetLineColor(kRed);
  gr_wprime_bpt200_acceptances->SetMarkerColor(kRed);
  gr_wprime_bpt200_acceptances->Draw("C*");

  
  TGraph* gr_wprime_bpt225_acceptances =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_bpt225_acceptances);
  gr_wprime_bpt225_acceptances->SetLineColor(kBlue);
  gr_wprime_bpt225_acceptances->SetMarkerColor(kBlue);
  gr_wprime_bpt225_acceptances->Draw("C*");

  TGraph* gr_wprime_bpt250_acceptances =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_bpt250_acceptances);
  gr_wprime_bpt250_acceptances->SetLineColor(kMagenta);
  gr_wprime_bpt250_acceptances->SetMarkerColor(kMagenta);
  gr_wprime_bpt250_acceptances->Draw("C*");

  TGraph* gr_wprime_bpt275_acceptances =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_bpt275_acceptances);
  gr_wprime_bpt275_acceptances->SetLineColor(kOrange);
  gr_wprime_bpt275_acceptances->SetMarkerColor(kOrange);
  gr_wprime_bpt275_acceptances->Draw("C*");

  TGraph* gr_wprime_bpt300_acceptances =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_bpt300_acceptances);
  gr_wprime_bpt300_acceptances->SetLineColor(kTeal);
  gr_wprime_bpt300_acceptances->SetMarkerColor(kTeal);
  gr_wprime_bpt300_acceptances->Draw("C*");

  
  TLegend* lgnd_wprime_sig_acceptances = new TLegend(0.55,0.58,0.95,0.88);
  lgnd_wprime_sig_acceptances->SetTextSize(0.04);
  lgnd_wprime_sig_acceptances->SetFillColor(0);
  lgnd_wprime_sig_acceptances->AddEntry(gr_wprime_ps_acceptances,"preselection","L");
  lgnd_wprime_sig_acceptances->AddEntry(gr_wprime_bpt175_acceptances,"pt(l#nu)>175 && pt(jj)>175","L");
  lgnd_wprime_sig_acceptances->AddEntry(gr_wprime_bpt200_acceptances,"pt(l#nu)>200 && pt(jj)>200","L");
  lgnd_wprime_sig_acceptances->AddEntry(gr_wprime_bpt225_acceptances,"pt(l#nu)>225 && pt(jj)>225","L");
  lgnd_wprime_sig_acceptances->AddEntry(gr_wprime_bpt250_acceptances,"pt(l#nu)>250 && pt(jj)>250","L");
  lgnd_wprime_sig_acceptances->AddEntry(gr_wprime_bpt275_acceptances,"pt(l#nu)>275 && pt(jj)>275","L");
  lgnd_wprime_sig_acceptances->AddEntry(gr_wprime_bpt300_acceptances,"pt(l#nu)>300 && pt(jj)>300","L");
  lgnd_wprime_sig_acceptances->Draw();

  tc_wprime_acceptances->cd();
  tc_wprime_acceptances->SaveAs("./graphs/wprime_selection_acceptances.pdf");



  //wprime sig_to_bkgd
  TCanvas *tc_wprime_sig_to_bkgd =
    new TCanvas("tc_wprime_sig_to_bkgd","W' S/B",200,10,700,500);

  tc_wprime_sig_to_bkgd->SetGrid();
  tc_wprime_sig_to_bkgd->SetLogy();
  tc_wprime_sig_to_bkgd->SetFillColor(0);
  
  TH1F *frame_wprime_sig_to_bkgd = tc_wprime_sig_to_bkgd->DrawFrame(450,0.00001,1550,1.1);
  frame_wprime_sig_to_bkgd->GetYaxis()->SetTitleSize(0.05);
  frame_wprime_sig_to_bkgd->GetYaxis()->SetTitleOffset(0.8);
  frame_wprime_sig_to_bkgd->GetXaxis()->SetTitleSize(0.05);
  frame_wprime_sig_to_bkgd->GetXaxis()->SetTitleOffset(0.8);
  frame_wprime_sig_to_bkgd->SetXTitle("W' Mass");
  frame_wprime_sig_to_bkgd->SetYTitle("#frac{S}{B}");

  TGraph* gr_wprime_bpt175_sig_to_bkgd =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_bpt175_sig_to_bkgd);
  gr_wprime_bpt175_sig_to_bkgd->SetTitle("W' S/B");
  gr_wprime_bpt175_sig_to_bkgd->SetLineColor(kGreen);
  gr_wprime_bpt175_sig_to_bkgd->SetMarkerColor(kGreen);
  gr_wprime_bpt175_sig_to_bkgd->Draw("C*");

  TGraph* gr_wprime_bpt200_sig_to_bkgd =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_bpt200_sig_to_bkgd);
  gr_wprime_bpt200_sig_to_bkgd->SetLineColor(kRed);
  gr_wprime_bpt200_sig_to_bkgd->SetMarkerColor(kRed);
  gr_wprime_bpt200_sig_to_bkgd->Draw("C*");

  TGraph* gr_wprime_bpt225_sig_to_bkgd =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_bpt225_sig_to_bkgd);
  gr_wprime_bpt225_sig_to_bkgd->SetLineColor(kBlue);
  gr_wprime_bpt225_sig_to_bkgd->SetMarkerColor(kBlue);
  gr_wprime_bpt225_sig_to_bkgd->Draw("C*");

  TGraph* gr_wprime_bpt250_sig_to_bkgd =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_bpt250_sig_to_bkgd);
  gr_wprime_bpt250_sig_to_bkgd->SetLineColor(kMagenta);
  gr_wprime_bpt250_sig_to_bkgd->SetMarkerColor(kMagenta);
  gr_wprime_bpt250_sig_to_bkgd->Draw("C*");

  TGraph* gr_wprime_bpt275_sig_to_bkgd =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_bpt275_sig_to_bkgd);
  gr_wprime_bpt275_sig_to_bkgd->SetLineColor(kOrange);
  gr_wprime_bpt275_sig_to_bkgd->SetMarkerColor(kOrange);
  gr_wprime_bpt275_sig_to_bkgd->Draw("C*");

  TGraph* gr_wprime_bpt300_sig_to_bkgd =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_bpt300_sig_to_bkgd);
  gr_wprime_bpt300_sig_to_bkgd->SetLineColor(kTeal);
  gr_wprime_bpt300_sig_to_bkgd->SetMarkerColor(kTeal);
  gr_wprime_bpt300_sig_to_bkgd->Draw("C*");

  TGraph* gr_wprime_ps_sig_to_bkgd =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_ps_sig_to_bkgd);
  gr_wprime_ps_sig_to_bkgd->Draw("C*");

  TLegend* lgnd_wprime_sig_to_bkgd = new TLegend(0.55,0.70,0.95,0.95);
  lgnd_wprime_sig_to_bkgd->SetTextSize(0.04);
  lgnd_wprime_sig_to_bkgd->SetFillColor(0);
  lgnd_wprime_sig_to_bkgd->AddEntry(gr_wprime_ps_sig_to_bkgd,"preselection","L");
  lgnd_wprime_sig_to_bkgd->AddEntry(gr_wprime_bpt175_sig_to_bkgd,"pt(l#nu)>175 && pt(jj)>175","L");
  lgnd_wprime_sig_to_bkgd->AddEntry(gr_wprime_bpt200_sig_to_bkgd,"pt(l#nu)>200 && pt(jj)>200","L");
  lgnd_wprime_sig_to_bkgd->AddEntry(gr_wprime_bpt225_sig_to_bkgd,"pt(l#nu)>225 && pt(jj)>225","L");
  lgnd_wprime_sig_to_bkgd->AddEntry(gr_wprime_bpt250_sig_to_bkgd,"pt(l#nu)>250 && pt(jj)>250","L");
  lgnd_wprime_sig_to_bkgd->AddEntry(gr_wprime_bpt275_sig_to_bkgd,"pt(l#nu)>275 && pt(jj)>275","L");
  lgnd_wprime_sig_to_bkgd->AddEntry(gr_wprime_bpt300_sig_to_bkgd,"pt(l#nu)>300 && pt(jj)>300","L");
  lgnd_wprime_sig_to_bkgd->Draw();

  tc_wprime_sig_to_bkgd->SaveAs("./graphs/wprime_selection_sig_to_bkgd.pdf");
    
  //wprime: significance
  TCanvas *tc_wprime_significance =
    new TCanvas("tc_wprime_significance","W' significance (S/sqrt{B})",200,10,700,500);

  tc_wprime_significance->SetGrid();
  tc_wprime_significance->SetTicky(1);
  tc_wprime_significance->SetLogy();
  tc_wprime_significance->SetFillColor(0);
  
  TH1F *frame_wprime_significance = tc_wprime_significance->DrawFrame(450,0.0001,1550,10);
  frame_wprime_significance->GetYaxis()->SetTitleSize(0.05);
  frame_wprime_significance->GetYaxis()->SetTitleOffset(0.8);
  frame_wprime_significance->GetXaxis()->SetTitleSize(0.05);
  frame_wprime_significance->GetXaxis()->SetTitleOffset(0.8);
  frame_wprime_significance->SetXTitle("W' Mass");
  frame_wprime_significance->SetYTitle("#frac{S}{#sqrt{B}}");

  
  TGraph* gr_wprime_bpt175_significance =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_bpt175_significance);
  gr_wprime_bpt175_significance->SetTitle("W' S/#sqrt{B}");
  gr_wprime_bpt175_significance->SetLineColor(kGreen);
  gr_wprime_bpt175_significance->SetMarkerColor(kGreen);
  gr_wprime_bpt175_significance->Draw("C*");

  TGraph* gr_wprime_bpt200_significance =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_bpt200_significance);
  gr_wprime_bpt200_significance->SetLineColor(kRed);
  gr_wprime_bpt200_significance->SetMarkerColor(kRed);
  gr_wprime_bpt200_significance->Draw("C*");

  TGraph* gr_wprime_bpt225_significance =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_bpt225_significance);
  gr_wprime_bpt225_significance->SetLineColor(kBlue);
  gr_wprime_bpt225_significance->SetMarkerColor(kBlue);
  gr_wprime_bpt225_significance->Draw("C*");

  TGraph* gr_wprime_bpt250_significance =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_bpt250_significance);
  gr_wprime_bpt250_significance->SetLineColor(kMagenta);
  gr_wprime_bpt250_significance->SetMarkerColor(kMagenta);
  gr_wprime_bpt250_significance->Draw("C*");

  TGraph* gr_wprime_bpt275_significance =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_bpt275_significance);
  gr_wprime_bpt275_significance->SetLineColor(kOrange);
  gr_wprime_bpt275_significance->SetMarkerColor(kOrange);
  gr_wprime_bpt275_significance->Draw("C*");

  TGraph* gr_wprime_bpt300_significance =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_bpt300_significance);
  gr_wprime_bpt300_significance->SetLineColor(kTeal);
  gr_wprime_bpt300_significance->SetMarkerColor(kTeal);
  gr_wprime_bpt300_significance->Draw("C*");

  TGraph* gr_wprime_ps_significance =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_ps_significance);
  gr_wprime_ps_significance->SetLineWidth(2);
  //gr_wprime_ps_significance->SetMarkerWidth(2);
  gr_wprime_ps_significance->Draw("C*");

  TLegend* lgnd_wprime_significance = new TLegend(0.15,0.15,0.55,0.45);
  lgnd_wprime_significance->SetTextSize(0.04);
  lgnd_wprime_significance->SetFillColor(0);
  lgnd_wprime_significance->AddEntry(gr_wprime_ps_significance,"preselection","L");
  lgnd_wprime_significance->AddEntry(gr_wprime_bpt175_significance,"pt(l#nu)>175 && pt(jj)>175","L");
  lgnd_wprime_significance->AddEntry(gr_wprime_bpt200_significance,"pt(l#nu)>200 && pt(jj)>200","L");
  lgnd_wprime_significance->AddEntry(gr_wprime_bpt225_significance,"pt(l#nu)>225 && pt(jj)>225","L");
  lgnd_wprime_significance->AddEntry(gr_wprime_bpt250_significance,"pt(l#nu)>250 && pt(jj)>250","L");
  lgnd_wprime_significance->AddEntry(gr_wprime_bpt275_significance,"pt(l#nu)>275 && pt(jj)>275","L");
  lgnd_wprime_significance->AddEntry(gr_wprime_bpt300_significance,"pt(l#nu)>300 && pt(jj)>300","L");
  
  lgnd_wprime_significance->Draw();

  tc_wprime_significance->SaveAs("./graphs/wprime_selection_significance.pdf");

  //////////////////////////////////////////////////
  // Compute integrals
  ////////////////////////////////////////////////// 
  // rsg: significance
  TH1F* h_rsg_bpt175_significance =
    new TH1F("h_rsg_bpt175_significance","h_rsg_bpt175_significance",n_rsg_samples,450,1050);
  TH1F* h_rsg_bpt200_significance =
    new TH1F("h_rsg_bpt200_significance","h_rsg_bpt200_significance",n_rsg_samples,450,1050);
  TH1F* h_rsg_bpt225_significance =
    new TH1F("h_rsg_bpt225_significance","h_rsg_bpt225_significance",n_rsg_samples,450,1050);
  TH1F* h_rsg_bpt250_significance =
    new TH1F("h_rsg_bpt250_significance","h_rsg_bpt250_significance",n_rsg_samples,450,1050);
  TH1F* h_rsg_bpt275_significance =
    new TH1F("h_rsg_bpt275_significance","h_rsg_bpt275_significance",n_rsg_samples,450,1050);
  TH1F* h_rsg_bpt300_significance =
    new TH1F("h_rsg_bpt300_significance","h_rsg_bpt300_significance",n_rsg_samples,450,1050);

  // rsg: sig_to_bkgd
  TH1F* h_rsg_bpt175_sig_to_bkgd =
    new TH1F("h_rsg_bpt175_sig_to_bkgd","h_rsg_bpt175_sig_to_bkgd",n_rsg_samples,450,1050);
  TH1F* h_rsg_bpt200_sig_to_bkgd =
    new TH1F("h_rsg_bpt200_sig_to_bkgd","h_rsg_bpt200_sig_to_bkgd",n_rsg_samples,450,1050);
  TH1F* h_rsg_bpt225_sig_to_bkgd =
    new TH1F("h_rsg_bpt225_sig_to_bkgd","h_rsg_bpt225_sig_to_bkgd",n_rsg_samples,450,1050);
  TH1F* h_rsg_bpt250_sig_to_bkgd =
    new TH1F("h_rsg_bpt250_sig_to_bkgd","h_rsg_bpt250_sig_to_bkgd",n_rsg_samples,450,1050);
  TH1F* h_rsg_bpt275_sig_to_bkgd =
    new TH1F("h_rsg_bpt275_sig_to_bkgd","h_rsg_bpt275_sig_to_bkgd",n_rsg_samples,450,1050);
  TH1F* h_rsg_bpt300_sig_to_bkgd =
    new TH1F("h_rsg_bpt300_sig_to_bkgd","h_rsg_bpt300_sig_to_bkgd",n_rsg_samples,450,1050);

  // wprime: significance
  TH1F* h_wprime_bpt175_significance =
    new TH1F("h_wprime_bpt175_significance","h_wprime_bpt175_significance",n_wprime_samples,450,1050);
  TH1F* h_wprime_bpt200_significance =
    new TH1F("h_wprime_bpt200_significance","h_wprime_bpt200_significance",n_wprime_samples,450,1050);
  TH1F* h_wprime_bpt225_significance =
    new TH1F("h_wprime_bpt225_significance","h_wprime_bpt225_significance",n_wprime_samples,450,1050);
  TH1F* h_wprime_bpt250_significance =
    new TH1F("h_wprime_bpt250_significance","h_wprime_bpt250_significance",n_wprime_samples,450,1050);
  TH1F* h_wprime_bpt275_significance =
    new TH1F("h_wprime_bpt275_significance","h_wprime_bpt275_significance",n_wprime_samples,450,1050);
  TH1F* h_wprime_bpt300_significance =
    new TH1F("h_wprime_bpt300_significance","h_wprime_bpt300_significance",n_wprime_samples,450,1050);

  // wprime: sig_to_bkgd
  TH1F* h_wprime_bpt175_sig_to_bkgd =
    new TH1F("h_wprime_bpt175_sig_to_bkgd","h_wprime_bpt175_sig_to_bkgd",n_wprime_samples,450,1050);
  TH1F* h_wprime_bpt200_sig_to_bkgd =
    new TH1F("h_wprime_bpt200_sig_to_bkgd","h_wprime_bpt200_sig_to_bkgd",n_wprime_samples,450,1050);
  TH1F* h_wprime_bpt225_sig_to_bkgd =
    new TH1F("h_wprime_bpt225_sig_to_bkgd","h_wprime_bpt225_sig_to_bkgd",n_wprime_samples,450,1050);
  TH1F* h_wprime_bpt250_sig_to_bkgd =
    new TH1F("h_wprime_bpt250_sig_to_bkgd","h_wprime_bpt250_sig_to_bkgd",n_wprime_samples,450,1050);
  TH1F* h_wprime_bpt275_sig_to_bkgd =
    new TH1F("h_wprime_bpt275_sig_to_bkgd","h_wprime_bpt275_sig_to_bkgd",n_wprime_samples,450,1050);
  TH1F* h_wprime_bpt300_sig_to_bkgd =
    new TH1F("h_wprime_bpt300_sig_to_bkgd","h_wprime_bpt300_sig_to_bkgd",n_wprime_samples,450,1050);

  for(int i=0;i<3;i++){
    h_rsg_bpt175_significance->Fill(v_rsg_masses[i],rsg_comb_bpt175_significance[i]);
    h_rsg_bpt200_significance->Fill(v_rsg_masses[i],rsg_comb_bpt200_significance[i]);
    h_rsg_bpt225_significance->Fill(v_rsg_masses[i],rsg_comb_bpt225_significance[i]);
    h_rsg_bpt250_significance->Fill(v_rsg_masses[i],rsg_comb_bpt250_significance[i]);
    h_rsg_bpt275_significance->Fill(v_rsg_masses[i],rsg_comb_bpt275_significance[i]);
    h_rsg_bpt300_significance->Fill(v_rsg_masses[i],rsg_comb_bpt300_significance[i]);

    h_rsg_bpt175_sig_to_bkgd->Fill(v_rsg_masses[i],rsg_comb_bpt175_sig_to_bkgd[i]);
    h_rsg_bpt200_sig_to_bkgd->Fill(v_rsg_masses[i],rsg_comb_bpt200_sig_to_bkgd[i]);
    h_rsg_bpt225_sig_to_bkgd->Fill(v_rsg_masses[i],rsg_comb_bpt225_sig_to_bkgd[i]);
    h_rsg_bpt250_sig_to_bkgd->Fill(v_rsg_masses[i],rsg_comb_bpt250_sig_to_bkgd[i]);
    h_rsg_bpt275_sig_to_bkgd->Fill(v_rsg_masses[i],rsg_comb_bpt275_sig_to_bkgd[i]);
    h_rsg_bpt300_sig_to_bkgd->Fill(v_rsg_masses[i],rsg_comb_bpt300_sig_to_bkgd[i]);

    //wprime
    h_wprime_bpt175_significance->Fill(v_wprime_masses[i],wprime_comb_bpt175_significance[i]);
    h_wprime_bpt200_significance->Fill(v_wprime_masses[i],wprime_comb_bpt200_significance[i]);
    h_wprime_bpt225_significance->Fill(v_wprime_masses[i],wprime_comb_bpt225_significance[i]);
    h_wprime_bpt250_significance->Fill(v_wprime_masses[i],wprime_comb_bpt250_significance[i]);
    h_wprime_bpt275_significance->Fill(v_wprime_masses[i],wprime_comb_bpt275_significance[i]);
    h_wprime_bpt300_significance->Fill(v_wprime_masses[i],wprime_comb_bpt300_significance[i]);

    h_wprime_bpt175_sig_to_bkgd->Fill(v_wprime_masses[i],wprime_comb_bpt175_sig_to_bkgd[i]);
    h_wprime_bpt200_sig_to_bkgd->Fill(v_wprime_masses[i],wprime_comb_bpt200_sig_to_bkgd[i]);
    h_wprime_bpt225_sig_to_bkgd->Fill(v_wprime_masses[i],wprime_comb_bpt225_sig_to_bkgd[i]);
    h_wprime_bpt250_sig_to_bkgd->Fill(v_wprime_masses[i],wprime_comb_bpt250_sig_to_bkgd[i]);
    h_wprime_bpt275_sig_to_bkgd->Fill(v_wprime_masses[i],wprime_comb_bpt275_sig_to_bkgd[i]);
    h_wprime_bpt300_sig_to_bkgd->Fill(v_wprime_masses[i],wprime_comb_bpt300_sig_to_bkgd[i]);

  }

  // cout<<"S/B"<<endl;
  // cout<<"rsg m175: "<<h_rsg_bpt175_sig_to_bkgd->Integral()<<endl;
  // cout<<"rsg m200: "<<h_rsg_bpt200_sig_to_bkgd->Integral()<<endl;
  // cout<<"rsg m225: "<<h_rsg_bpt225_sig_to_bkgd->Integral()<<endl;
  // cout<<"rsg m250: "<<h_rsg_bpt250_sig_to_bkgd->Integral()<<endl;
  // cout<<"rsg m275: "<<h_rsg_bpt275_sig_to_bkgd->Integral()<<endl;
  // cout<<"rsg m300: "<<h_rsg_bpt300_sig_to_bkgd->Integral()<<endl;
  // cout<<"--"<<endl;
  // cout<<"wprime m175: "<<h_wprime_bpt175_sig_to_bkgd->Integral()<<endl;
  // cout<<"wprime m200: "<<h_wprime_bpt200_sig_to_bkgd->Integral()<<endl;
  // cout<<"wprime m225: "<<h_wprime_bpt225_sig_to_bkgd->Integral()<<endl;
  // cout<<"wprime m250: "<<h_wprime_bpt250_sig_to_bkgd->Integral()<<endl;
  // cout<<"wprime m275: "<<h_wprime_bpt275_sig_to_bkgd->Integral()<<endl;
  // cout<<"wprime m300: "<<h_wprime_bpt300_sig_to_bkgd->Integral()<<endl;
  // cout<<endl;
  
  // cout<<"S/sqrt(B)"<<endl;
  // cout<<"rsg m175: "<<h_rsg_bpt175_significance->Integral()<<endl;
  // cout<<"rsg m200: "<<h_rsg_bpt200_significance->Integral()<<endl;
  // cout<<"rsg m225: "<<h_rsg_bpt225_significance->Integral()<<endl;
  // cout<<"rsg m250: "<<h_rsg_bpt250_significance->Integral()<<endl;
  // cout<<"rsg m275: "<<h_rsg_bpt275_significance->Integral()<<endl;
  // cout<<"rsg m300: "<<h_rsg_bpt300_significance->Integral()<<endl;
  // cout<<"--"<<endl;
  // cout<<"wprime m175: "<<h_wprime_bpt175_significance->Integral()<<endl;
  // cout<<"wprime m200: "<<h_wprime_bpt200_significance->Integral()<<endl;
  // cout<<"wprime m225: "<<h_wprime_bpt225_significance->Integral()<<endl;
  // cout<<"wprime m250: "<<h_wprime_bpt250_significance->Integral()<<endl;
  // cout<<"wprime m275: "<<h_wprime_bpt275_significance->Integral()<<endl;
  // cout<<"wprime m300: "<<h_wprime_bpt300_significance->Integral()<<endl;
  // cout<<"--"<<endl;

  //rsg_signal_integrals
  // Quantity(S/B,or S/sqrt(B)), M500, M750, M1000
  string out_file_name = "./logs/signal_integrals.csv";
  std::ofstream out_file(out_file_name.c_str());
  out_file.precision(2);
  out_file.setf(ios::fixed,ios::floatfield);
  out_file<<"bpt,rsg_sig_to_bkgd,rsg_significance,wprime_sig_to_bkgd,wprime_significance"<<endl;
  out_file<<"175,"
	  <<h_rsg_bpt175_sig_to_bkgd->Integral()<<","
	  <<h_rsg_bpt175_significance->Integral()<<","
	  <<h_wprime_bpt175_sig_to_bkgd->Integral()<<","
	  <<h_wprime_bpt175_significance->Integral()<<endl;
  out_file<<"{\\color{red} 200},"
	  <<"{\\color{red} "<<h_rsg_bpt200_sig_to_bkgd->Integral()<<"},"
	  <<"{\\color{red} "<<h_rsg_bpt200_significance->Integral()<<"},"
	  <<"{\\color{red} "<<h_wprime_bpt200_sig_to_bkgd->Integral()<<"},"
	  <<"{\\color{red} "<<h_wprime_bpt200_significance->Integral()<<"}"<<endl;
  out_file<<"225,"
	  <<h_rsg_bpt225_sig_to_bkgd->Integral()<<","
	  <<h_rsg_bpt225_significance->Integral()<<","
	  <<h_wprime_bpt225_sig_to_bkgd->Integral()<<","
	  <<h_wprime_bpt225_significance->Integral()<<endl;
  out_file<<"250,"
	  <<h_rsg_bpt250_sig_to_bkgd->Integral()<<","
	  <<h_rsg_bpt250_significance->Integral()<<","
	  <<h_wprime_bpt250_sig_to_bkgd->Integral()<<","
	  <<h_wprime_bpt250_significance->Integral()<<endl;
  out_file<<"275,"
	  <<h_rsg_bpt275_sig_to_bkgd->Integral()<<","
	  <<h_rsg_bpt275_significance->Integral()<<","
	  <<h_wprime_bpt275_sig_to_bkgd->Integral()<<","
	  <<h_wprime_bpt275_significance->Integral()<<endl;
  out_file<<"300,"
	  <<h_rsg_bpt300_sig_to_bkgd->Integral()<<","
	  <<h_rsg_bpt300_significance->Integral()<<","
	  <<h_wprime_bpt300_sig_to_bkgd->Integral()<<","
	  <<h_wprime_bpt300_significance->Integral()<<endl;

  out_file.close();

  cout<<"See ./logs/signal_integrals.csv for integrals"<<endl;
  return;
}
