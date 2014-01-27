void runQCDUncertainty(){

  TFile* qcd_mt = (TFile*) TFile::Open("qcd_sf_mt.root","READ");
  TH1F* h_el_sig_mt_lep_nu_dijet_m = (TH1F*) qcd_mt->Get("ps/h_elec_sig_lep_nu_dijet_m");
  h_el_sig_mt_lep_nu_dijet_m->SetDirectory(0);
  TH1F* h_mu_sig_mt_lep_nu_dijet_m = (TH1F*) qcd_mt->Get("ps/h_muon_sig_lep_nu_dijet_m");
  h_mu_sig_mt_lep_nu_dijet_m->SetDirectory(0);
  qcd_mt->Close();

  TFile* qcd_mt_eq2j = (TFile*) TFile::Open("qcd_sf_mt_eq2j.root","READ");
  TH1F* h_el_sig_mt_eq2j_lep_nu_dijet_m = (TH1F*) qcd_mt_eq2j->Get("ps/h_elec_sig_lep_nu_dijet_m");
  h_el_sig_mt_eq2j_lep_nu_dijet_m->SetDirectory(0);
  TH1F* h_mu_sig_mt_eq2j_lep_nu_dijet_m = (TH1F*) qcd_mt_eq2j->Get("ps/h_muon_sig_lep_nu_dijet_m");
  h_mu_sig_mt_eq2j_lep_nu_dijet_m->SetDirectory(0);
  qcd_mt_eq2j->Close();

  TFile* qcd_mt_gt2j = (TFile*) TFile::Open("qcd_sf_mt_gt2j.root","READ");
  TH1F* h_el_sig_mt_gt2j_lep_nu_dijet_m = (TH1F*) qcd_mt_gt2j->Get("ps/h_elec_sig_lep_nu_dijet_m");
  h_el_sig_mt_gt2j_lep_nu_dijet_m->SetDirectory(0);
  TH1F* h_mu_sig_mt_gt2j_lep_nu_dijet_m = (TH1F*) qcd_mt_gt2j->Get("ps/h_muon_sig_lep_nu_dijet_m");
  h_mu_sig_mt_gt2j_lep_nu_dijet_m->SetDirectory(0);
  qcd_mt_gt2j->Close();
  
  TFile* qcd_lep_pt = (TFile*) TFile::Open("qcd_sf_lep_pt.root","READ");
  TH1F* h_el_sig_lep_pt_lep_nu_dijet_m = (TH1F*) qcd_lep_pt->Get("ps/h_elec_sig_lep_nu_dijet_m");
  h_el_sig_lep_pt_lep_nu_dijet_m->SetDirectory(0);
  TH1F* h_mu_sig_lep_pt_lep_nu_dijet_m = (TH1F*) qcd_lep_pt->Get("ps/h_muon_sig_lep_nu_dijet_m");
  h_mu_sig_lep_pt_lep_nu_dijet_m->SetDirectory(0);
  qcd_lep_pt->Close();
  
  TFile* qcd_met = (TFile*) TFile::Open("qcd_sf_met.root","READ");
  TH1F* h_el_sig_met_lep_nu_dijet_m = (TH1F*) qcd_met->Get("ps/h_elec_sig_lep_nu_dijet_m");
  h_el_sig_met_lep_nu_dijet_m->SetDirectory(0);
  TH1F* h_mu_sig_met_lep_nu_dijet_m = (TH1F*) qcd_met->Get("ps/h_muon_sig_lep_nu_dijet_m");
  h_mu_sig_met_lep_nu_dijet_m->SetDirectory(0);

  qcd_met->Close();

  float n_el_mt = h_el_sig_mt_lep_nu_dijet_m->Integral();
  float n_el_mt_eq2j = h_el_sig_mt_eq2j_lep_nu_dijet_m->Integral();
  float n_el_mt_gt2j = h_el_sig_mt_gt2j_lep_nu_dijet_m->Integral();
  float n_el_lep_pt = h_el_sig_lep_pt_lep_nu_dijet_m->Integral();
  float n_el_met = h_el_sig_met_lep_nu_dijet_m->Integral();
  float n_mu_mt = h_mu_sig_mt_lep_nu_dijet_m->Integral();
  float n_mu_mt_eq2j = h_mu_sig_mt_eq2j_lep_nu_dijet_m->Integral();
  float n_mu_mt_gt2j = h_mu_sig_mt_gt2j_lep_nu_dijet_m->Integral();
  float n_mu_lep_pt = h_mu_sig_lep_pt_lep_nu_dijet_m->Integral();
  float n_mu_met = h_mu_sig_met_lep_nu_dijet_m->Integral();

  cout.setf(ios::fixed,ios::floatfield);            // floatfield not set
  cout.precision(2);
  cout<<"== QCD events in Signal Region =="<<endl;
  cout<<"proc \t mt \t eq2j \t gt2j \t pt \t met"<<endl;
  cout<<"elec \t";
  cout<<n_el_mt<<"\t";
  cout<<n_el_mt_eq2j<<"\t";
  cout<<n_el_mt_gt2j<<"\t";
  cout<<n_el_lep_pt<<"\t";
  cout<<n_el_met<<endl;
  cout<<"muon \t";
  cout<<n_mu_mt<<"\t";
  cout<<n_mu_mt_eq2j<<"\t";
  cout<<n_mu_mt_gt2j<<"\t";
  cout<<n_mu_lep_pt<<"\t";
  cout<<n_mu_met<<endl;
  cout<<"=="<<endl;


  cout<<"== Fractional QCD events Signal Region =="<<endl;
  cout<<"proc \t mt \t eq2j \t gt2j \t pt \t met"<<endl;
  cout<<"elec \t";
  cout<<fabs((n_el_mt-n_el_mt)/n_el_mt)<<"\t";
  cout<<fabs((n_el_mt_eq2j-n_el_mt)/n_el_mt)<<"\t";
  cout<<fabs((n_el_mt_gt2j-n_el_mt)/n_el_mt)<<"\t";
  cout<<fabs((n_el_lep_pt-n_el_mt)/n_el_mt)<<"\t";
  cout<<fabs((n_el_met-n_el_mt)/n_el_mt)<<endl;
  cout<<"muon \t";
  cout<<fabs((n_mu_mt-n_mu_mt)/n_mu_mt)<<"\t";
  cout<<fabs((n_mu_mt_eq2j-n_mu_mt)/n_mu_mt)<<"\t";
  cout<<fabs((n_mu_mt_gt2j-n_mu_mt)/n_mu_mt)<<"\t";
  cout<<fabs((n_mu_lep_pt-n_mu_mt)/n_mu_mt)<<"\t";
  cout<<fabs((n_mu_met-n_mu_mt)/n_mu_mt)<<endl;
  cout<<"=="<<endl;


}
