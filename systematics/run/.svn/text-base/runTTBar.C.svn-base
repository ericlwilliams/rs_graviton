//////////////////////////////////////////////////
// Calculates acceptance uncertainty for ttbar samples
////////////////////////////////////////////////// 
#include "../../include/systematics_defs.h"
#include <iomanip>
void runTTBar(){

  //elec
  //fixme, change to acer
  // TFile* ttbar_nom = TFile::Open("../../plots/systematics_plots/merged/mc.acer.ttbar.systematics.plot.root");
  // TH1F* h_ttbar_elec_nom = (TH1F*) ttbar_nom->Get("h_el_jes_nom_highm_pass_sig");
  // TH1F* h_ttbar_muon_nom = (TH1F*) ttbar_nom->Get("h_mu_jes_nom_highm_pass_sig");

  TFile* ttbar_isr_up = TFile::Open("../../plots/systematics_plots/merged/mc.acer.moreps.ttbar.systematics.plot.root");
  TH1F* h_ttbar_elec_isr_up = (TH1F*) ttbar_isr_up->Get("h_el_jes_nom_highm_pass_sig");
  TH1F* h_ttbar_muon_isr_up = (TH1F*) ttbar_isr_up->Get("h_mu_jes_nom_highm_pass_sig");

  TFile* ttbar_isr_down = TFile::Open("../../plots/systematics_plots/merged/mc.acer.lessps.ttbar.systematics.plot.root");
  TH1F* h_ttbar_elec_isr_down = (TH1F*) ttbar_isr_down->Get("h_el_jes_nom_highm_pass_sig");
  TH1F* h_ttbar_muon_isr_down = (TH1F*) ttbar_isr_down->Get("h_mu_jes_nom_highm_pass_sig");


  //float elec_count_nom = h_ttbar_elec_nom->Integral();
  float elec_count_up = h_ttbar_elec_isr_up->Integral();
  float elec_count_down = h_ttbar_elec_isr_down->Integral();

  float elec_uncert = 100*fabs(elec_count_up-elec_count_down)/(elec_count_up+elec_count_down);
  
  // float elec_fluc_up = fabs(elec_count_up-elec_count_nom)/elec_count_nom;
  // float elec_fluc_down = fabs(elec_count_down-elec_count_nom)/elec_count_nom;

  // float elec_uncert = 100.*(elec_fluc_up+elec_fluc_down)/2.;
  
  //float muon_count_nom = h_ttbar_muon_nom->Integral();
  float muon_count_up = h_ttbar_muon_isr_up->Integral();
  float muon_count_down = h_ttbar_muon_isr_down->Integral();
  float muon_uncert = 100*fabs(muon_count_up-muon_count_down)/(muon_count_up+muon_count_down);


  // float muon_fluc_up = fabs(muon_count_up-muon_count_nom)/muon_count_nom;
  // float muon_fluc_down = fabs(muon_count_down-muon_count_nom)/muon_count_nom;

  // float muon_uncert = 100.*(muon_fluc_up+muon_fluc_down)/2.;


  string out_file_name = "../logs/ttbar.csv";
  std::ofstream out_file(out_file_name.c_str());
  out_file<<setprecision(2)<<fixed;

  out_file<<"mcatnlo.ttbar,"<<elec_uncert<<","<<muon_uncert<<endl;

  out_file.close();
  cout<<"TTBar ISR/FSR uncertianties"<<endl;
  cout<<"evjj :\t"<<elec_uncert<<endl;
  cout<<"uvjj :\t"<<muon_uncert<<endl;
  cout<<endl;
  cout<<"See ../logs/ttbar.csv for acceptance uncertainties"<<endl;
  
  return;
}
