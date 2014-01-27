#include "TSystem.h"
#define COUT std::cout << "I'm here : " << __FILE__ << " : " << __LINE__ << std::endl;
#include "TH1F.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TFile.h>
#include <TGraph.h>
#include <TChain.h>
#include "THStack.h"
#include "TNamed.h"
#include "TCut.h"
#include "TF1.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TPaveText.h"
#include "/afs/cern.ch/user/m/mdavies/pubTemplate/atlasstyle-00-03-04/AtlasStyle.C"
#include <stdio.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <TEventList.h>
#include <TList.h>
#include <math.h>
#include <string>
#include <TFitResultPtr.h>
#include <TFitResult.h>

#include <stdio.h>
#include <stdlib.h>
#include <RooRealVar.h>
#include <RooGaussian.h>
#include <RooArgusBG.h>
#include <RooAddPdf.h>
#include <RooDataSet.h>
#include <RooAbsPdf.h>
#include <RooPlot.h>
#include <RooCBShape.h>
#include <RooDataHist.h>
#include <RooConstVar.h>

#include "kFacW.C"

using namespace std;
using namespace RooFit; 

TH1F * AddHisto(TH1F * h1, TH1F * h2, Int_t Bins){
  TH1F * h = (TH1F*) h2->Clone("h");
  for(Int_t bin = 0 ; bin < Bins; bin++){
    h->SetBinContent(bin, h1->GetBinContent(bin)+h2->GetBinContent(bin));   
  }
  return h;
}
TH1F * SubtractHisto(TH1F * h1, TH1F * h2, Int_t Bins){
  TH1F * h = (TH1F*) h1->Clone("h");
  h->Reset();
  for(Int_t bin = 0 ; bin < Bins; bin++){
    if((h1->GetBinContent(bin)-h2->GetBinContent(bin)) >= 0.){
      h->SetBinContent(bin, h1->GetBinContent(bin)-h2->GetBinContent(bin));   
    }
    if((h1->GetBinContent(bin)-h2->GetBinContent(bin)) < 0.){
      h->SetBinContent(bin, 0);
    }
  }
  return h;
}
Double_t GetSquareBinContent(TH1F * h1, Int_t bin_n){
  Double_t square;
  square = (h1->GetBinContent(bin_n))*(h1->GetBinContent(bin_n));
  return square;
}
TH1F * GetUpErrorHisto(TH1F * h_error, TH1F * h1, Int_t Bins){
  TH1F * h = (TH1F*) h1->Clone("h");
  h->Reset();
  for(Int_t bin = 0 ; bin < Bins; bin++){
    if((h_error->GetBinContent(bin) - h1->GetBinContent(bin)) >= 0.){
      h->SetBinContent(bin, (h_error->GetBinContent(bin) - h1->GetBinContent(bin)));
    }
    if((h_error->GetBinContent(bin) - h1->GetBinContent(bin))  < 0.){
      h->SetBinContent(bin, 0);
    }
  }    
  return h;
}
TH1F * GetDownErrorHisto(TH1F * h_error, TH1F * h1, Int_t Bins){
  TH1F * h = (TH1F*) h->Clone("h1");
  h->Reset();
  for(Int_t bin = 0 ; bin < Bins; bin++){
    if((h_error->GetBinContent(bin) - h1->GetBinContent(bin)) < 0.){
      h->SetBinContent(bin, fabs((h_error->GetBinContent(bin) - h1->GetBinContent(bin))));
    }
    if((h_error->GetBinContent(bin) - h1->GetBinContent(bin))  >= 0.){
      h->SetBinContent(bin, 0);
    }
  }    
  return h;
}

int main(int argc, char **argv){

  
  SetAtlasStyle();

  double initial_mass1 = 200.0; 
  double initial_mass2 = 350.0; 
  double initial_mass3 = 500.0; 
  double initial_mass4 = 750.0; 
  double initial_mass5 = 1000.0; 
  double initial_mass6 = 1250.0; 
  double initial_mass7 = 1500.0; 
  double a_initial1 = 1.;//initial_mass1/1.1;
  double a_initial2 = 1.;//initial_mass2//1.1;
  double a_initial3 = 1.;//initial_mass3/1.1;
  double a_initial4 = 1.;//initial_mass4/1.1;
  double a_initial5 = 1.;//initial_mass5/1.1;
  double a_initial6 = 1.;//initial_mass6/1.1;
  double a_initial7 = 1.;//initial_mass7/1.1;
  
  // --- Normalization ---
  Double_t Total_Lumi = 1024.0; // pb-1
  double cross_section[7];
  double init_n[7];
  double n_min[7];
  double n_max[7];
  cross_section[0] = 1.620 ; //pb  
  cross_section[1] = 0.456;  
  cross_section[2] = 0.107;  
  cross_section[3] = 0.0176;  
  cross_section[4] = 0.00446;  
  cross_section[5] = 0.0000794;  
  cross_section[6] = 0.000000000237;  
  for(int itr = 0; itr < 7 ; itr++){
    init_n[itr] = Total_Lumi*cross_section[itr];
    n_min[itr] = init_n[itr]/100.0;
    n_max[itr] = init_n[itr]*100.0;
  }
  
  TCanvas * Fit = new TCanvas("Fit","Fit Results", 500, 500);
  Fit->SetLogy();
  // --- Observable ---
  RooRealVar Mass("Mass","Transverse Mass (GeV)",0,2000);
  RooPlot * Fitframe = Mass.frame(); 
  RooPlot * Massframe = Mass.frame(); 
  //Massframe->SetLogy();

  // --- Defining Variables in Crystal Ball --- 
  RooRealVar mean1("mean1","Mean of the Gaussian half of the Crystal Ball",180, 0, 2000);
  RooRealVar sigma1("sigma1","Sigma of the Gaussian half of the Crystal Ball", 15.0, 5.0, 20.0);
  RooRealVar a1("a1","Delimiting Value", 1., 0.01, 1500.0);
  RooRealVar n1("n1","Exponentiating Form", 2.0);//, 0.001, 100.0);
  RooRealVar mean2("mean2","Mean of the Gaussian half of the Crystal Ball",initial_mass2, 0, 2000);
  RooRealVar sigma2("sigma2","Sigma of the Gaussian half of the Crystal Ball", 15.0, 0.1, 40.0);
  RooRealVar a2("a2","Delimiting Value", 1.0, 0.01, 1500.0);
  RooRealVar n2("n2","Exponentiating Form", 2.0);//, 0.001, 100.0);
  RooRealVar mean3("mean3","Mean of the Gaussian half of the Crystal Ball",initial_mass3, 0, 2000);
  RooRealVar sigma3("sigma3","Sigma of the Gaussian half of the Crystal Ball", 15.0, 0.1, 100.0);
  RooRealVar a3("a3","Delimiting Value", 1.0, 0.01, 1500.0);
  RooRealVar n3("n3","Exponentiating Form", 2.0);//, 0.001, 100.0);
  RooRealVar mean4("mean4","Mean of the Gaussian half of the Crystal Ball",initial_mass4, 0, 2000);
  RooRealVar sigma4("sigma4","Sigma of the Gaussian half of the Crystal Ball", 40.0, 0.1, 110.0);
  RooRealVar a4("a4","Delimiting Value", 1.0, 0.01, 1500.0);
  RooRealVar n4("n4","Exponentiating Form", 2.0);//, 0.001, 100.0);
  RooRealVar mean5("mean5","Mean of the Gaussian half of the Crystal Ball",initial_mass5, 0, 2000);
  RooRealVar sigma5("sigma5","Sigma of the Gaussian half of the Crystal Ball", 50.0, 0.1, 120.0);
  RooRealVar a5("a5","Delimiting Value", 1.0, 0.01, 1500.0);
  RooRealVar n5("n5","Exponentiating Form", 2.0);//, 0.001, 100.0);
  RooRealVar mean6("mean6","Mean of the Gaussian half of the Crystal Ball",initial_mass6, 0, 2000);
  RooRealVar sigma6("sigma6","Sigma of the Gaussian half of the Crystal Ball", 50.0, 0.1, 140.0);
  RooRealVar a6("a6","Delimiting Value", 1.0, 0.01, 1500.0);
  RooRealVar n6("n6","Exponentiating Form", 2.0);//, 0.001, 100.0);
  RooRealVar mean7("mean7","Mean of the Gaussian half of the Crystal Ball",initial_mass7, 0, 2000);
  RooRealVar sigma7("sigma7","Sigma of the Gaussian half of the Crystal Ball", 50.0, 0.1, 160.0);
  RooRealVar a7("a7","Delimiting Value", 1.0, 0.01, 1500.0);
  RooRealVar n7("n7","Exponentiating Form", 2.0);//, 0.001, 100.0);
    
  // --- Defining the fit function, i.e. The Crystal Ball
  RooCBShape CrystalBall1("CrystalBall1","Crystal Ball Fit to Signal Resonance",Mass,mean1,sigma1,a1,n1);
  RooCBShape CrystalBall2("CrystalBall2","Crystal Ball Fit to Signal Resonance",Mass,mean2,sigma2,a2,n2);
  RooCBShape CrystalBall3("CrystalBall3","Crystal Ball Fit to Signal Resonance",Mass,mean3,sigma3,a3,n3);
  RooCBShape CrystalBall4("CrystalBall4","Crystal Ball Fit to Signal Resonance",Mass,mean4,sigma4,a4,n4);
  RooCBShape CrystalBall5("CrystalBall5","Crystal Ball Fit to Signal Resonance",Mass,mean5,sigma5,a5,n5);
  RooCBShape CrystalBall6("CrystalBall6","Crystal Ball Fit to Signal Resonance",Mass,mean6,sigma6,a6,n6);
  RooCBShape CrystalBall7("CrystalBall7","Crystal Ball Fit to Signal Resonance",Mass,mean7,sigma7,a7,n7);
  
  TString Channel = argv[1];
  TString systematic_directory = argv[2]; 
  // --- Getting and Defining Signal Histograms ---
  TFile * f1;
  //Total number of events in channel
  Double_t Total_Channel_m200 = 0;
  Double_t Total_Channel_m350 = 0;
  Double_t Total_Channel_m500 = 0;
  Double_t Total_Channel_m750 = 0;
  Double_t Total_Channel_m1000 = 0;
  
  Double_t CrossSection_m200 = 1.524*kFacW(200.);
  Double_t CrossSection_m250 = 1.36175*kFacW(250.);
  Double_t CrossSection_m300 = 0.757956*kFacW(300.);
  Double_t CrossSection_m350 = 0.415*kFacW(350.);
  Double_t CrossSection_m400 = 0.248766*kFacW(400.);
  Double_t CrossSection_m450 = 0.153358*kFacW(450.);
  Double_t CrossSection_m500 = 0.095*kFacW(500.);
  Double_t CrossSection_m550 = 0.0652606*kFacW(550.);
  Double_t CrossSection_m600 = 0.0431795*kFacW(600.);
  Double_t CrossSection_m650 = 0.0310614*kFacW(650.);
  Double_t CrossSection_m700 = 0.0225217*kFacW(700.);
  Double_t CrossSection_m750 = 0.0158*kFacW(750.);
  Double_t CrossSection_m800 = 0.0120387*kFacW(800.);
  Double_t CrossSection_m850 = 0.00903195*kFacW(850.);
  Double_t CrossSection_m900 = 0.00690484*kFacW(900.);
  Double_t CrossSection_m950 = 0.0053882*kFacW(950.);
  Double_t CrossSection_m1000 = 0.004*kFacW(1000.);

  cout << "200 GeV K Factor: " << kFacW(200.) << endl;  
  cout << "225 GeV K Factor: " << kFacW(225.) << endl;  
  cout << "250 GeV K Factor: " << kFacW(250.) << endl;  
  cout << "275 GeV K Factor: " << kFacW(275.) << endl;  
  cout << "300 GeV K Factor: " << kFacW(300.) << endl;  
  cout << "325 GeV K Factor: " << kFacW(325.) << endl;  
  cout << "350 GeV K Factor: " << kFacW(350.) << endl;  
  cout << "375 GeV K Factor: " << kFacW(375.) << endl;  
  cout << "400 GeV K Factor: " << kFacW(400.) << endl;  
  cout << "425 GeV K Factor: " << kFacW(425.) << endl;  
  cout << "450 GeV K Factor: " << kFacW(450.) << endl;  
  cout << "475 GeV K Factor: " << kFacW(475.) << endl;  
  cout << "500 GeV K Factor: " << kFacW(500.) << endl;  
  cout << "525 GeV K Factor: " << kFacW(525.) << endl;  
  cout << "550 GeV K Factor: " << kFacW(550.) << endl;  
  cout << "575 GeV K Factor: " << kFacW(575.) << endl;  
  cout << "600 GeV K Factor: " << kFacW(600.) << endl;  
  cout << "625 GeV K Factor: " << kFacW(625.) << endl;  
  cout << "650 GeV K Factor: " << kFacW(650.) << endl;  
  cout << "675 GeV K Factor: " << kFacW(675.) << endl;  
  cout << "700 GeV K Factor: " << kFacW(700.) << endl;  
  cout << "725 GeV K Factor: " << kFacW(725.) << endl;  
  cout << "750 GeV K Factor: " << kFacW(750.) << endl;  
  cout << "775 GeV K Factor: " << kFacW(775.) << endl;  
  cout << "800 GeV K Factor: " << kFacW(800.) << endl;  
  cout << "825 GeV K Factor: " << kFacW(825.) << endl;  
  cout << "850 GeV K Factor: " << kFacW(850.) << endl;  
  cout << "875 GeV K Factor: " << kFacW(875.) << endl;  
  cout << "900 GeV K Factor: " << kFacW(900.) << endl;  
  cout << "925 GeV K Factor: " << kFacW(925.) << endl;  
  cout << "950 GeV K Factor: " << kFacW(950.) << endl;  
  cout << "975 GeV K Factor: " << kFacW(975.) << endl;  
  cout << "1000 GeV K Factor: " << kFacW(1000.) << endl;  

  //--- k-factor Plot  
  TCanvas *c_kfac = new TCanvas("c_kfac","K-Factor",200,10,700,700);
  Int_t number_of_signals = 1100;  
  Double_t x_axis[number_of_signals];
  Double_t y_axis[number_of_signals];
  for(Int_t itr = 0; itr < number_of_signals ; itr++){
    x_axis[itr] = itr+100.;
    y_axis[itr] = kFacW(itr+100.);
  }
  
  TGraph * KFAC = new TGraph(1100,x_axis,y_axis);
  KFAC->SetTitle("");
  KFAC->GetXaxis()->SetTitle("W' Mass [GeV]");
  KFAC->GetYaxis()->SetTitle("k-factor #equiv #sigma^{NNLO MSWT2008} / #sigma^{LO^{*} MRST2007}");
  KFAC->Draw("A*");
  //  KFAC->SetLineColor(2);
  //KFAC->SetLineWidth(2);
  KFAC->SetMarkerColor(4);
  //  KFAC->SetMarkerStyle(22);
  
  Double_t Acceptance_m200 = 0.062;   
  Double_t Acceptance_m350 = 0.116;
  Double_t Acceptance_m500 = 0.159;
  Double_t Acceptance_m750 = 0.199;
  Double_t Acceptance_m1000 = 0.204;

  Total_Channel_m200 = Total_Lumi*CrossSection_m200*Acceptance_m200;
  Total_Channel_m350 = Total_Lumi*CrossSection_m350*Acceptance_m350;
  Total_Channel_m500 = Total_Lumi*CrossSection_m500*Acceptance_m500;
  Total_Channel_m750 = Total_Lumi*CrossSection_m750*Acceptance_m750;
  Total_Channel_m1000 = Total_Lumi*CrossSection_m1000*Acceptance_m1000;
  
  // --- Normalization Systematics ---
  Double_t trig_sys = 0.01;
  Double_t el_iso = 0.02;
  Double_t mu_iso = 0.01;
  Double_t Total_norm_sys = 0.;  

  // --- Defining and Opening Files ---
  Int_t number_of_systematics = 20; // up and down combined
  TFile * f_sys[number_of_systematics];
  //TFile * f_sys_up[number_of_systematics];
  //TFile * f_sys_down[number_of_systematics];
  
  if(Channel == "eee"){
    Total_norm_sys = trig_sys*trig_sys + 3*el_iso*el_iso; 
    f1 = TFile::Open(systematic_directory+"/eee.root");
    f_sys[0] = TFile::Open(systematic_directory+"/eee_elec_scale_up.root"); 
    f_sys[1] = TFile::Open(systematic_directory+"/eee_elec_smear_up.root"); 
    f_sys[2] = TFile::Open(systematic_directory+"/eee_lljet_fake_up.root"); 
    f_sys[3] = TFile::Open(systematic_directory+"/eee_MET_Cell_Topo_up.root"); 
    f_sys[4] = TFile::Open(systematic_directory+"/eee_MET_Cell_Track_up.root"); 
    f_sys[5] = TFile::Open(systematic_directory+"/eee_MET_intime_up.root"); 
    f_sys[6] = TFile::Open(systematic_directory+"/eee_MET_outtime_up.root"); 
    f_sys[7] = TFile::Open(systematic_directory+"/eee_muon_scale_up.root"); 
    f_sys[8] = TFile::Open(systematic_directory+"/eee_muon_smear_id_up.root"); 
    f_sys[9] = TFile::Open(systematic_directory+"/eee_muon_smear_ms_up.root"); 
    f_sys[10] = TFile::Open(systematic_directory+"/eee_elec_scale_down.root"); 
    f_sys[11] = TFile::Open(systematic_directory+"/eee_elec_smear_down.root"); 
    f_sys[12] = TFile::Open(systematic_directory+"/eee_lljet_fake_down.root"); 
    f_sys[13] = TFile::Open(systematic_directory+"/eee_MET_Cell_Topo_down.root"); 
    f_sys[14] = TFile::Open(systematic_directory+"/eee_MET_Cell_Track_down.root"); 
    f_sys[15] = TFile::Open(systematic_directory+"/eee_MET_intime_down.root"); 
    f_sys[16] = TFile::Open(systematic_directory+"/eee_MET_outtime_down.root"); 
    f_sys[17] = TFile::Open(systematic_directory+"/eee_muon_scale_down.root"); 
    f_sys[18] = TFile::Open(systematic_directory+"/eee_muon_smear_id_down.root"); 
    f_sys[19] = TFile::Open(systematic_directory+"/eee_muon_smear_ms_down.root"); 
  }
  if(Channel == "eem"){
    Total_norm_sys = trig_sys*trig_sys + 2*el_iso*el_iso + mu_iso*mu_iso; 
    f1 = TFile::Open(systematic_directory+"/eem.root");
    f_sys[0] = TFile::Open(systematic_directory+"/eem_elec_scale_up.root"); 
    f_sys[1] = TFile::Open(systematic_directory+"/eem_elec_smear_up.root"); 
    f_sys[2] = TFile::Open(systematic_directory+"/eem_lljet_fake_up.root"); 
    f_sys[3] = TFile::Open(systematic_directory+"/eem_MET_Cell_Topo_up.root"); 
    f_sys[4] = TFile::Open(systematic_directory+"/eem_MET_Cell_Track_up.root"); 
    f_sys[5] = TFile::Open(systematic_directory+"/eem_MET_intime_up.root"); 
    f_sys[6] = TFile::Open(systematic_directory+"/eem_MET_outtime_up.root"); 
    f_sys[7] = TFile::Open(systematic_directory+"/eem_muon_scale_up.root"); 
    f_sys[8] = TFile::Open(systematic_directory+"/eem_muon_smear_id_up.root"); 
    f_sys[9] = TFile::Open(systematic_directory+"/eem_muon_smear_ms_up.root"); 
    f_sys[10] = TFile::Open(systematic_directory+"/eem_elec_scale_down.root"); 
    f_sys[11] = TFile::Open(systematic_directory+"/eem_elec_smear_down.root"); 
    f_sys[12] = TFile::Open(systematic_directory+"/eem_lljet_fake_down.root"); 
    f_sys[13] = TFile::Open(systematic_directory+"/eem_MET_Cell_Topo_down.root"); 
    f_sys[14] = TFile::Open(systematic_directory+"/eem_MET_Cell_Track_down.root"); 
    f_sys[15] = TFile::Open(systematic_directory+"/eem_MET_intime_down.root"); 
    f_sys[16] = TFile::Open(systematic_directory+"/eem_MET_outtime_down.root"); 
    f_sys[17] = TFile::Open(systematic_directory+"/eem_muon_scale_down.root"); 
    f_sys[18] = TFile::Open(systematic_directory+"/eem_muon_smear_id_down.root"); 
    f_sys[19] = TFile::Open(systematic_directory+"/eem_muon_smear_ms_down.root"); 
  }
  if(Channel == "emm"){
    Total_norm_sys = trig_sys*trig_sys + el_iso*el_iso + 2*mu_iso*mu_iso; 
    f1 = TFile::Open(systematic_directory+"/emm.root");
    f_sys[0] = TFile::Open(systematic_directory+"/emm_elec_scale_up.root"); 
    f_sys[1] = TFile::Open(systematic_directory+"/emm_elec_smear_up.root"); 
    f_sys[2] = TFile::Open(systematic_directory+"/emm_lljet_fake_up.root"); 
    f_sys[3] = TFile::Open(systematic_directory+"/emm_MET_Cell_Topo_up.root"); 
    f_sys[4] = TFile::Open(systematic_directory+"/emm_MET_Cell_Track_up.root"); 
    f_sys[5] = TFile::Open(systematic_directory+"/emm_MET_intime_up.root"); 
    f_sys[6] = TFile::Open(systematic_directory+"/emm_MET_outtime_up.root"); 
    f_sys[7] = TFile::Open(systematic_directory+"/emm_muon_scale_up.root"); 
    f_sys[8] = TFile::Open(systematic_directory+"/emm_muon_smear_id_up.root"); 
    f_sys[9] = TFile::Open(systematic_directory+"/emm_muon_smear_ms_up.root"); 
    f_sys[10] = TFile::Open(systematic_directory+"/emm_elec_scale_down.root"); 
    f_sys[11] = TFile::Open(systematic_directory+"/emm_elec_smear_down.root"); 
    f_sys[12] = TFile::Open(systematic_directory+"/emm_lljet_fake_down.root"); 
    f_sys[13] = TFile::Open(systematic_directory+"/emm_MET_Cell_Topo_down.root"); 
    f_sys[14] = TFile::Open(systematic_directory+"/emm_MET_Cell_Track_down.root"); 
    f_sys[15] = TFile::Open(systematic_directory+"/emm_MET_intime_down.root"); 
    f_sys[16] = TFile::Open(systematic_directory+"/emm_MET_outtime_down.root"); 
    f_sys[17] = TFile::Open(systematic_directory+"/emm_muon_scale_down.root"); 
    f_sys[18] = TFile::Open(systematic_directory+"/emm_muon_smear_id_down.root"); 
    f_sys[19] = TFile::Open(systematic_directory+"/emm_muon_smear_ms_down.root"); 
  }
  if(Channel == "mmm"){
    Total_norm_sys = trig_sys*trig_sys + 3*mu_iso*mu_iso; 
    f1 = TFile::Open(systematic_directory+"/mmm.root");
    f_sys[0] = TFile::Open(systematic_directory+"/mmm_elec_scale_up.root"); 
    f_sys[1] = TFile::Open(systematic_directory+"/mmm_elec_smear_up.root"); 
    f_sys[2] = TFile::Open(systematic_directory+"/mmm_lljet_fake_up.root"); 
    f_sys[3] = TFile::Open(systematic_directory+"/mmm_MET_Cell_Topo_up.root"); 
    f_sys[4] = TFile::Open(systematic_directory+"/mmm_MET_Cell_Track_up.root"); 
    f_sys[5] = TFile::Open(systematic_directory+"/mmm_MET_intime_up.root"); 
    f_sys[6] = TFile::Open(systematic_directory+"/mmm_MET_outtime_up.root"); 
    f_sys[7] = TFile::Open(systematic_directory+"/mmm_muon_scale_up.root"); 
    f_sys[8] = TFile::Open(systematic_directory+"/mmm_muon_smear_id_up.root"); 
    f_sys[9] = TFile::Open(systematic_directory+"/mmm_muon_smear_ms_up.root"); 
    f_sys[10] = TFile::Open(systematic_directory+"/mmm_elec_scale_down.root"); 
    f_sys[11] = TFile::Open(systematic_directory+"/mmm_elec_smear_down.root"); 
    f_sys[12] = TFile::Open(systematic_directory+"/mmm_lljet_fake_down.root"); 
    f_sys[13] = TFile::Open(systematic_directory+"/mmm_MET_Cell_Topo_down.root"); 
    f_sys[14] = TFile::Open(systematic_directory+"/mmm_MET_Cell_Track_down.root"); 
    f_sys[15] = TFile::Open(systematic_directory+"/mmm_MET_intime_down.root"); 
    f_sys[16] = TFile::Open(systematic_directory+"/mmm_MET_outtime_down.root"); 
    f_sys[17] = TFile::Open(systematic_directory+"/mmm_muon_scale_down.root"); 
    f_sys[18] = TFile::Open(systematic_directory+"/mmm_muon_smear_id_down.root"); 
    f_sys[19] = TFile::Open(systematic_directory+"/mmm_muon_smear_ms_down.root"); 
  }

  // --- Get Event Count Per Signal and Per Systematic --- 
  TH1F * h1_m200 = (TH1F*) f1->Get("wprime_lvll_m200");
  TH1F * h1_m350 = (TH1F*) f1->Get("wprime_lvll_m350");
  TH1F * h1_m500 = (TH1F*) f1->Get("wprime_lvll_m500");
  TH1F * h1_m750 = (TH1F*) f1->Get("wprime_lvll_m750");
  TH1F * h1_m1000 = (TH1F*) f1->Get("wprime_lvll_m1000");
  Double_t Integral_m200 = h1_m200->Integral(0,200);
  Double_t Integral_m350 = h1_m350->Integral(0,200);
  Double_t Integral_m500 = h1_m500->Integral(0,200);
  Double_t Integral_m750 = h1_m750->Integral(0,200);
  Double_t Integral_m1000 = h1_m1000->Integral(0,200);

  TH1F * h_sys_m200[number_of_systematics];
  TH1F * h_sys_m350[number_of_systematics];
  TH1F * h_sys_m500[number_of_systematics];
  TH1F * h_sys_m750[number_of_systematics];
  TH1F * h_sys_m1000[number_of_systematics];
  TH1F * h_sys_unc_up_m200[number_of_systematics];
  TH1F * h_sys_unc_up_m350[number_of_systematics];
  TH1F * h_sys_unc_up_m500[number_of_systematics];
  TH1F * h_sys_unc_up_m750[number_of_systematics];
  TH1F * h_sys_unc_up_m1000[number_of_systematics];
  TH1F * h_sys_unc_down_m200[number_of_systematics];
  TH1F * h_sys_unc_down_m350[number_of_systematics];
  TH1F * h_sys_unc_down_m500[number_of_systematics];
  TH1F * h_sys_unc_down_m750[number_of_systematics];
  TH1F * h_sys_unc_down_m1000[number_of_systematics];
  TH1F * h_total_sys_up_m200; 
  TH1F * h_total_sys_up_m350; 
  TH1F * h_total_sys_up_m500; 
  TH1F * h_total_sys_up_m750; 
  TH1F * h_total_sys_up_m1000; 
  TH1F * h1_sys_up_m200; 
  TH1F * h1_sys_up_m350; 
  TH1F * h1_sys_up_m500; 
  TH1F * h1_sys_up_m750; 
  TH1F * h1_sys_up_m1000; 
  Double_t Integral_sys_m200[number_of_systematics]; 
  Double_t Integral_sys_m350[number_of_systematics]; 
  Double_t Integral_sys_m500[number_of_systematics]; 
  Double_t Integral_sys_m750[number_of_systematics]; 
  Double_t Integral_sys_m1000[number_of_systematics]; 
  TH1F * h_total_sys_down_m200; 
  TH1F * h_total_sys_down_m350; 
  TH1F * h_total_sys_down_m500; 
  TH1F * h_total_sys_down_m750; 
  TH1F * h_total_sys_down_m1000; 
  TH1F * h1_sys_down_m200; 
  TH1F * h1_sys_down_m350; 
  TH1F * h1_sys_down_m500; 
  TH1F * h1_sys_down_m750; 
  TH1F * h1_sys_down_m1000; 
  COUT;
  
  Int_t nBins = 200;
  Double_t Total2_unc_up_bin_m200[nBins];
  Double_t Total2_unc_up_bin_m350[nBins];
  Double_t Total2_unc_up_bin_m500[nBins];
  Double_t Total2_unc_up_bin_m750[nBins];
  Double_t Total2_unc_up_bin_m1000[nBins];
  Double_t Total2_unc_down_bin_m200[nBins];
  Double_t Total2_unc_down_bin_m350[nBins];
  Double_t Total2_unc_down_bin_m500[nBins];
  Double_t Total2_unc_down_bin_m750[nBins];
  Double_t Total2_unc_down_bin_m1000[nBins];
  
  for(Int_t itr = 0; itr < number_of_systematics ; itr++){
    h_sys_m200[itr] = (TH1F*) f_sys[itr]->Get("wprime_lvll_m200");
    h_sys_m350[itr] = (TH1F*) f_sys[itr]->Get("wprime_lvll_m350");
    h_sys_m500[itr] = (TH1F*) f_sys[itr]->Get("wprime_lvll_m500");
    h_sys_m750[itr] = (TH1F*) f_sys[itr]->Get("wprime_lvll_m750");
    h_sys_m1000[itr] = (TH1F*) f_sys[itr]->Get("wprime_lvll_m1000");
    //---Need Integral of each systematic 
    Integral_sys_m200[itr] = h_sys_m200[itr]->Integral(0,nBins);
    Integral_sys_m350[itr] = h_sys_m350[itr]->Integral(0,nBins);
    Integral_sys_m500[itr] = h_sys_m500[itr]->Integral(0,nBins);
    Integral_sys_m750[itr] = h_sys_m750[itr]->Integral(0,nBins);
    Integral_sys_m1000[itr] = h_sys_m1000[itr]->Integral(0,nBins);
    cout << "Integral_sys_m200["<<itr<<"] " << Integral_sys_m200[itr] << endl;
    //---
  }
  //COUT;
  for(Int_t itr = 0; itr < number_of_systematics ; itr++){
    h_sys_unc_up_m200[itr] = GetUpErrorHisto(h_sys_m200[itr], h1_m200, nBins);
    h_sys_unc_up_m350[itr] = GetUpErrorHisto(h_sys_m350[itr], h1_m350, nBins);
    h_sys_unc_up_m500[itr] = GetUpErrorHisto(h_sys_m500[itr], h1_m500, nBins);
    h_sys_unc_up_m750[itr] = GetUpErrorHisto(h_sys_m750[itr], h1_m750, nBins);
    h_sys_unc_up_m1000[itr] = GetUpErrorHisto(h_sys_m1000[itr], h1_m1000, nBins);
    h_sys_unc_down_m200[itr] = GetDownErrorHisto(h_sys_m200[itr], h1_m200, nBins);
    h_sys_unc_down_m350[itr] = GetDownErrorHisto(h_sys_m350[itr], h1_m350, nBins);
    h_sys_unc_down_m500[itr] = GetDownErrorHisto(h_sys_m500[itr], h1_m500, nBins);
    h_sys_unc_down_m750[itr] = GetDownErrorHisto(h_sys_m750[itr], h1_m750, nBins);
    h_sys_unc_down_m1000[itr] = GetDownErrorHisto(h_sys_m1000[itr], h1_m1000, nBins);
    //COUT;
    for(Int_t bin = 0; bin < nBins; bin++){
      Total2_unc_up_bin_m200[bin] =+ GetSquareBinContent(h_sys_unc_up_m200[itr], bin);
      Total2_unc_up_bin_m350[bin] =+ GetSquareBinContent(h_sys_unc_up_m350[itr], bin);
      Total2_unc_up_bin_m500[bin] =+ GetSquareBinContent(h_sys_unc_up_m500[itr], bin);
      Total2_unc_up_bin_m750[bin] =+ GetSquareBinContent(h_sys_unc_up_m750[itr], bin);
      Total2_unc_up_bin_m1000[bin] =+ GetSquareBinContent(h_sys_unc_up_m1000[itr], bin);
      Total2_unc_down_bin_m200[bin] =+ GetSquareBinContent(h_sys_unc_down_m200[itr], bin);
      Total2_unc_down_bin_m350[bin] =+ GetSquareBinContent(h_sys_unc_down_m350[itr], bin);
      Total2_unc_down_bin_m500[bin] =+ GetSquareBinContent(h_sys_unc_down_m500[itr], bin);
      Total2_unc_down_bin_m750[bin] =+ GetSquareBinContent(h_sys_unc_down_m750[itr], bin);
      Total2_unc_down_bin_m1000[bin] =+ GetSquareBinContent(h_sys_unc_down_m1000[itr], bin);
    }
  }
  //  COUT;
  
  // --- Define Total Upward and Downward Systematic Histograms --- 
  TH1F * h_total_sys_unc_up_m200 = (TH1F*) h1_m200->Clone("h1_total_sys_unc_up_m200");
  TH1F * h_total_sys_unc_up_m350 = (TH1F*) h1_m350->Clone("h1_total_sys_unc_up_m350");
  TH1F * h_total_sys_unc_up_m500 = (TH1F*) h1_m500->Clone("h1_total_sys_unc_up_m500");
  TH1F * h_total_sys_unc_up_m750 = (TH1F*) h1_m750->Clone("h1_total_sys_unc_up_m750");
  TH1F * h_total_sys_unc_up_m1000 = (TH1F*) h1_m1000->Clone("h1_total_sys_unc_up_m1000");
  TH1F * h_total_sys_unc_down_m200 = (TH1F*) h1_m200->Clone("h1_total_sys_unc_down_m200");
  TH1F * h_total_sys_unc_down_m350 = (TH1F*) h1_m350->Clone("h1_total_sys_unc_down_m350");
  TH1F * h_total_sys_unc_down_m500 = (TH1F*) h1_m500->Clone("h1_total_sys_unc_down_m500");
  TH1F * h_total_sys_unc_down_m750 = (TH1F*) h1_m750->Clone("h1_total_sys_unc_down_m750");
  TH1F * h_total_sys_unc_down_m1000 = (TH1F*) h1_m1000->Clone("h1_total_sys_unc_down_m1000");
  h_total_sys_unc_up_m200->Reset();
  h_total_sys_unc_up_m350->Reset();
  h_total_sys_unc_up_m500->Reset();
  h_total_sys_unc_up_m750->Reset();
  h_total_sys_unc_up_m1000->Reset();
  h_total_sys_unc_down_m200->Reset();
  h_total_sys_unc_down_m350->Reset();
  h_total_sys_unc_down_m500->Reset();
  h_total_sys_unc_down_m750->Reset();
  h_total_sys_unc_down_m1000->Reset();
      
  for(Int_t bin = 0; bin < nBins; bin++){
    // --- Add total normalization systematic ---   
    Total2_unc_up_bin_m200[bin] =+ Total_norm_sys;
    Total2_unc_up_bin_m350[bin] =+ Total_norm_sys; 
    Total2_unc_up_bin_m500[bin] =+ Total_norm_sys; 
    Total2_unc_up_bin_m750[bin] =+ Total_norm_sys; 
    Total2_unc_up_bin_m1000[bin] =+ Total_norm_sys; 
    Total2_unc_down_bin_m200[bin] =+ Total_norm_sys; 
    Total2_unc_down_bin_m350[bin] =+ Total_norm_sys; 
    Total2_unc_down_bin_m500[bin] =+ Total_norm_sys; 
    Total2_unc_down_bin_m750[bin] =+ Total_norm_sys; 
    Total2_unc_down_bin_m1000[bin] =+ Total_norm_sys; 
    // --- Fill Total Upward and Downward Systematic Histograms --- 
    h_total_sys_unc_up_m200->SetBinContent(bin, sqrt(Total2_unc_up_bin_m200[bin]));
    h_total_sys_unc_up_m350->SetBinContent(bin, sqrt(Total2_unc_up_bin_m350[bin]));
    h_total_sys_unc_up_m500->SetBinContent(bin, sqrt(Total2_unc_up_bin_m500[bin]));
    h_total_sys_unc_up_m750->SetBinContent(bin, sqrt(Total2_unc_up_bin_m750[bin]));
    h_total_sys_unc_up_m1000->SetBinContent(bin, sqrt(Total2_unc_up_bin_m1000[bin]));
    h_total_sys_unc_down_m200->SetBinContent(bin, sqrt(Total2_unc_down_bin_m200[bin]));
    h_total_sys_unc_down_m350->SetBinContent(bin, sqrt(Total2_unc_down_bin_m350[bin]));
    h_total_sys_unc_down_m500->SetBinContent(bin, sqrt(Total2_unc_down_bin_m500[bin]));
    h_total_sys_unc_down_m750->SetBinContent(bin, sqrt(Total2_unc_down_bin_m750[bin]));
    h_total_sys_unc_down_m1000->SetBinContent(bin, sqrt(Total2_unc_down_bin_m1000[bin]));
    //COUT;
  }
  
  // --- Define Up And Down + Nominal Histogram --- 
  h1_sys_up_m200 = AddHisto(h_total_sys_unc_up_m200, h1_m200, nBins);
  h1_sys_up_m350 = AddHisto(h_total_sys_unc_up_m350, h1_m350, nBins);
  h1_sys_up_m500 = AddHisto(h_total_sys_unc_up_m500, h1_m500, nBins);
  h1_sys_up_m750 = AddHisto(h_total_sys_unc_up_m750, h1_m750, nBins);
  h1_sys_up_m1000 = AddHisto(h_total_sys_unc_up_m1000, h1_m1000, nBins);
  // This Subtracts but keeps all bins > 0
  h1_sys_down_m200 = SubtractHisto(h1_m200, h_total_sys_unc_down_m200, nBins);
  h1_sys_down_m350 = SubtractHisto(h1_m350, h_total_sys_unc_down_m350, nBins);
  h1_sys_down_m500 = SubtractHisto(h1_m500, h_total_sys_unc_down_m500, nBins);
  h1_sys_down_m750 = SubtractHisto(h1_m750, h_total_sys_unc_down_m750, nBins);
  h1_sys_down_m1000 = SubtractHisto(h1_m1000, h_total_sys_unc_down_m1000, nBins);
  
  COUT;
  // --- Calculate Difference Between Up, Down with Nominal Histogram
  Double_t Integral_Sys_up_m200 = h1_sys_up_m200->Integral(0,nBins);
  Double_t Integral_Sys_up_m350 = h1_sys_up_m350->Integral(0,nBins);
  Double_t Integral_Sys_up_m500 = h1_sys_up_m500->Integral(0,nBins);
  Double_t Integral_Sys_up_m750 = h1_sys_up_m750->Integral(0,nBins);
  Double_t Integral_Sys_up_m1000 = h1_sys_up_m1000->Integral(0,nBins);
  Double_t Integral_Sys_down_m200 = h1_sys_down_m200->Integral(0,nBins);
  Double_t Integral_Sys_down_m350 = h1_sys_down_m350->Integral(0,nBins);
  Double_t Integral_Sys_down_m500 = h1_sys_down_m500->Integral(0,nBins);
  Double_t Integral_Sys_down_m750 = h1_sys_down_m750->Integral(0,nBins);
  Double_t Integral_Sys_down_m1000 = h1_sys_down_m1000->Integral(0,nBins);

  // --- Make Histograms of these differences ---
  cout << "===========================================================" << endl;
  cout << "200 GeV Systematic Up:   " << Integral_Sys_up_m200 << endl;  
  cout << "        Systematic Down: " << Integral_Sys_down_m200 << endl;  
  cout << "        Nominal:         " << Integral_m200 << endl;  
  cout << "===========================================================" << endl;
  cout << "350 GeV Systematic Up:   " << Integral_Sys_up_m350 << endl;  
  cout << "        Systematic Down: " << Integral_Sys_down_m350 << endl;  
  cout << "        Nominal:         " << Integral_m350 << endl;  
  cout << "===========================================================" << endl;
  cout << "500 GeV Systematic Up:   " << Integral_Sys_up_m500 << endl;  
  cout << "        Systematic Down: " << Integral_Sys_down_m500 << endl;  
  cout << "        Nominal:         " << Integral_m500 << endl;  
  cout << "===========================================================" << endl;
  cout << "750 GeV Systematic Up:   " << Integral_Sys_up_m750 << endl;  
  cout << "        Systematic Down: " << Integral_Sys_down_m750 << endl;  
  cout << "        Nominal:         " << Integral_m750 << endl;  
  cout << "===========================================================" << endl;
  cout << "1000 GeV Systematic Up:   " << Integral_Sys_up_m1000 << endl;  
  cout << "        Systematic Down:  " << Integral_Sys_down_m1000 << endl;  
  cout << "        Nominal:          " << Integral_m1000 << endl;  
  cout << "===========================================================" << endl;
  
  // --- Define Channel Acceptance --- 
  Double_t Channel_Acceptance_m200 = Acceptance_m200*(Integral_m200/Total_Channel_m200);
  Double_t Channel_Acceptance_m350 = Acceptance_m350*(Integral_m350/Total_Channel_m350);
  Double_t Channel_Acceptance_m500 = Acceptance_m500*(Integral_m500/Total_Channel_m500);
  Double_t Channel_Acceptance_m750 = Acceptance_m750*(Integral_m750/Total_Channel_m750);
  Double_t Channel_Acceptance_m1000 = Acceptance_m1000*(Integral_m1000/Total_Channel_m1000);
  
  RooDataHist signal_m200("signal_m200","W' signal", Mass, h1_m200);
  RooDataHist signal_m350("signal_m350","W' signal", Mass, h1_m350);
  RooDataHist signal_m500("signal_m500","W' signal", Mass, h1_m500);
  RooDataHist signal_m750("signal_m750","W' signal", Mass, h1_m750);
  RooDataHist signal_m1000("signal_m1000","W' signal", Mass, h1_m1000);
  //RooDataHist signal_m1250("signal_m1250","W' signal", Mass, h1_m1250);
  //RooDataHist signal_m1500("signal_m1500","W' signal", Mass, h1_m1500);
  
  // --- Fitting CrystalBall to Signal Shape ---
  RooRealVar MASS("Mass","Transverse Mass (GeV)", 0., 2000.);
  TH1 * Hist_m200 = MASS.createHistogram("Signal m200", Binning(200));
  TH1 * Hist_m350 = MASS.createHistogram("Signal m350", Binning(200));
  TH1 * Hist_m500 = MASS.createHistogram("Signal m500", Binning(200));
  TH1 * Hist_m750 = MASS.createHistogram("Signal m750", Binning(200));
  TH1 * Hist_m1000 = MASS.createHistogram("Signal m1000", Binning(200));
  
  CrystalBall1.fitTo(signal_m200);
  //signal_m200.plotOn(Massframe,LineColor(2),MarkerColor(2),MarkerSize(1.0));
  //CrystalBall1.plotOn(Massframe,LineColor(2),LineStyle(2));
  //CrystalBall1.fillHistogram(Hist_m200,RooArgList(MASS));

  CrystalBall2.fitTo(signal_m350);
  //signal_m350.plotOn(Massframe,LineColor(3),MarkerColor(3),MarkerSize(1.0));
  //CrystalBall2.plotOn(Massframe,LineColor(3),LineStyle(2));
  //CrystalBall2.fillHistogram(Hist_m350,RooArgList(MASS));
  
  //CrystalBall3.fitTo(signal_m500);
  //signal_m500.plotOn(Massframe,LineColor(4),MarkerColor(4),MarkerSize(1.0));
  //CrystalBall3.plotOn(Massframe,LineColor(4),LineStyle(2));
  //CrystalBall3.fillHistogram(Hist_m500,RooArgList(MASS));

  CrystalBall4.fitTo(signal_m750);
  //signal_m750.plotOn(Massframe,LineColor(5),MarkerColor(5),MarkerSize(1.0));
  //CrystalBall4.plotOn(Massframe,LineColor(5),LineStyle(2));
  //CrystalBall4.fillHistogram(Hist_m750,RooArgList(MASS));

  CrystalBall5.fitTo(signal_m1000);
  //signal_m1000.plotOn(Massframe,LineColor(6),MarkerColor(6),MarkerSize(1.0));
  //CrystalBall5.plotOn(Massframe,LineColor(6),LineStyle(2));
  //CrystalBall5.fillHistogram(Hist_m1000,RooArgList(MASS));

  
  //CrystalBall6.fitTo(signal_m1250);
  //CrystalBall7.fitTo(signal_m1500);
 
  // --- Writing out the result
  //signal_m1250.plotOn(Massframe);
  //signal_m1500.plotOn(Massframe);
  //CrystalBall6.plotOn(Massframe);
  //CrystalBall7.plotOn(Massframe);
  TFile * CrystalBallFits = new TFile("Wprime_Templates/"+systematic_directory+"/"+Channel+".root", "RECREATE");
  Massframe->GetYaxis()->SetRangeUser(0.00001,10.);
  Massframe->GetYaxis()->SetDrawOption("Logy");
  //  Massframe->Write("CrystalBallFits");
  c_kfac->Write("KFactor");
  
  TCanvas *c_acc = new TCanvas("c_acc","Acceptances",200,10,500,500);
  Int_t number_of_signals_fitted = 5;  
  Double_t x[number_of_signals_fitted];
  Int_t n = number_of_signals_fitted;
  x[0] = 200.0;
  x[1] = 350.0;
  x[2] = 500.0;
  x[3] = 750.0;
  x[4] = 1000.0;

  Double_t Y[n];
  Y[0] = Acceptance_m200;
  Y[1] = Acceptance_m350;
  Y[2] = Acceptance_m500;
  Y[3] = Acceptance_m750;
  Y[4] = Acceptance_m1000;
  TGraph * Accept = new TGraph(n,x,Y);
  Accept->SetTitle("");
  Accept->GetXaxis()->SetTitle("W' Pole Mass [GeV]");
  Accept->GetYaxis()->SetTitle("Total Acceptance");
  Accept->Draw("AL*");
  Accept->SetLineColor(4);
  Accept->SetLineWidth(2);
  Accept->SetMarkerColor(4);
  Accept->SetMarkerStyle(22);
  c_acc->Write("TotalAcceptances");

  TCanvas *c_channel_acc = new TCanvas("c_channel_acc","Acceptances",200,10,500,500);
  x[0] = 200.0;
  x[1] = 350.0;
  x[2] = 500.0;
  x[3] = 750.0;
  x[4] = 1000.0;

  Y[0] = Channel_Acceptance_m200;
  Y[1] = Channel_Acceptance_m350;
  Y[2] = Channel_Acceptance_m500;
  Y[3] = Channel_Acceptance_m750;
  Y[4] = Channel_Acceptance_m1000;
  TGraph * Channel_Accept = new TGraph(n,x,Y);
  Channel_Accept->SetTitle("");
  Channel_Accept->GetXaxis()->SetTitle("W' Pole Mass [GeV]");
  Channel_Accept->GetYaxis()->SetTitle("Acceptance");
  Channel_Accept->Draw("AL*");
  TFitResultPtr Channel_acc_result = Channel_Accept->Fit("pol3", "S");
  Double_t chn_acc_p0 = Channel_acc_result->Value(0);
  Double_t chn_acc_p1 = Channel_acc_result->Value(1);
  Double_t chn_acc_p2 = Channel_acc_result->Value(2);
  Double_t chn_acc_p3 = Channel_acc_result->Value(3);
  Channel_Accept->SetLineColor(4);
  Channel_Accept->SetLineWidth(2);
  Channel_Accept->SetMarkerColor(4);
  Channel_Accept->SetMarkerStyle(22);
  c_channel_acc->Write("ChannelAcceptances");

  number_of_signals = 4;
  Double_t Mean[number_of_signals];
  Double_t Sigma[number_of_signals];
  Double_t A[number_of_signals];
  Double_t N[number_of_signals];

  Mean[0] = mean1.getVal();
  Mean[1] = mean2.getVal();
  //Mean[2] = mean3.getVal();
  Mean[2] = mean4.getVal();
  Mean[3] = mean5.getVal();
  //cout << "Mean[0] " << Mean[0] << endl;

  Sigma[0] = sigma1.getVal();
  Sigma[1] = sigma2.getVal();
  //Sigma[2] = sigma3.getVal();
  Sigma[2] = sigma4.getVal();
  Sigma[3] = sigma5.getVal();

  A[0] = a1.getVal();
  A[1] = a2.getVal();
  //A[2] = a3.getVal();
  A[2] = a4.getVal();
  A[3] = a5.getVal();

  N[0] = n1.getVal();
  N[1] = n2.getVal();
  //N[2] = n3.getVal();
  N[2] = n4.getVal();
  N[3] = n5.getVal();

  TCanvas *c_parm = new TCanvas("c_parm","Parameter fits",200,10,700,500);
  c_parm->Divide(2,2);
  Double_t xx[number_of_signals]; 
  xx[0] = 200.;
  xx[1] = 350.;
  xx[2] = 750.;
  xx[3] = 1000.;

  TGraph * gr_parameter_Mean = new TGraph(4,xx,Mean);
  TGraph * gr_parameter_Sigma = new TGraph(4,xx,Sigma);
  TGraph * gr_parameter_A = new TGraph(4,xx,A);
  TGraph * gr_parameter_N = new TGraph(4,xx,N);

  TF1 * sigma_fit = new TF1("sigma_fit", "[0]*sqrt([1]*(x-[2]))");
  sigma_fit->SetParameter(0,1);
  sigma_fit->SetParameter(1,1);
  sigma_fit->SetParameter(2,0);

  TF1 * a_fit = new TF1("a_fit", "[0]/([1]*x)+[2]*x"); 
  a_fit->SetParameter(0,1);
  a_fit->SetParameter(1,1);
  a_fit->SetParameter(2,1);

  TFitResultPtr MEAN = gr_parameter_Mean->Fit("pol1", "S");
  TFitResultPtr SIGMA = gr_parameter_Sigma->Fit("sigma_fit", "S");
  TFitResultPtr A_res = gr_parameter_A->Fit("a_fit", "S");
  TFitResultPtr N_res =  gr_parameter_N->Fit("pol1", "S");
  
  c_parm->cd(1);
  gr_parameter_Mean->SetTitle("");
  gr_parameter_Mean->GetYaxis()->SetTitle("Crystal Ball Mean");
  gr_parameter_Mean->SetMarkerColor(2);
  gr_parameter_Mean->Draw("A*");
  gr_parameter_Mean->SetMarkerStyle(22);
  gr_parameter_Mean->GetXaxis()->SetTitle("W' Pole Mass [GeV]");
  c_parm->cd(2);
  gr_parameter_Sigma->SetTitle("");
  gr_parameter_Sigma->GetYaxis()->SetTitle("Crystal Ball Sigma");
  gr_parameter_Sigma->SetMarkerColor(2);
  gr_parameter_Sigma->Draw("A*");
  gr_parameter_Sigma->SetMarkerStyle(22);
  gr_parameter_Sigma->GetXaxis()->SetTitle("W' Pole Mass [GeV]");
  c_parm->cd(3);
  gr_parameter_A->SetTitle("");
  gr_parameter_A->GetYaxis()->SetTitle("Crystal Ball a");
  gr_parameter_A->SetMarkerColor(2);
  gr_parameter_A->Draw("A*");
  gr_parameter_A->SetMarkerStyle(22);
  gr_parameter_A->GetXaxis()->SetTitle("W' Pole Mass [GeV]");
  
  c_parm->cd(4);
  gr_parameter_N->SetTitle("");
  gr_parameter_N->GetYaxis()->SetTitle("Crystal Ball n");
  gr_parameter_N->SetMarkerColor(2);
  gr_parameter_N->Draw("A*");
  gr_parameter_N->SetMarkerStyle(22);
  gr_parameter_N->GetXaxis()->SetTitle("W' Pole Mass [GeV]");
  c_parm->Write("Fits_to_Parameters");
  c_parm->Delete();

  // --- Get Fit Parameter Values --- 
  //p0 + p1*x
  double mean_p0 = MEAN->Value(0);
  double mean_p1 = MEAN->Value(1);
  //p0*sqrt(p1*(x - p2))
  double sigma_p0 = SIGMA->Value(0); 
  double sigma_p1 = SIGMA->Value(1); 
  double sigma_p2 = SIGMA->Value(2);
  // p0/p1*x 
  double a_res_p0 = A_res->Value(0); 
  double a_res_p1 = A_res->Value(1); 
  double a_res_p2 = A_res->Value(2); 

  // --- Get Function Values for different points --- 
  //M200
  Double_t mass;
  mass = 200.0;
  Double_t mean_m200 = (mean_p0 + mean_p1*mass); 
  Double_t sigma_m200 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
  Double_t a_m200 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
  //M250
  mass = 250.0;
  Double_t mean_m250 = (mean_p0 + mean_p1*mass); 
  Double_t sigma_m250 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
  Double_t a_m250 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
  //M300
  mass = 300.0;
  Double_t mean_m300 = (mean_p0 + mean_p1*mass); 
  Double_t sigma_m300 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
  Double_t a_m300 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
  //M350
  mass = 350.0;
  Double_t mean_m350 = (mean_p0 + mean_p1*mass); 
  Double_t sigma_m350 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
  Double_t a_m350 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
  //M400
  mass = 400.0;
  Double_t mean_m400 = (mean_p0 + mean_p1*mass); 
  Double_t sigma_m400 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
  Double_t a_m400 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
  //M450
  mass = 450.0;
  Double_t mean_m450 = (mean_p0 + mean_p1*mass); 
  Double_t sigma_m450 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
  Double_t a_m450 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
  //M500
  mass = 500.0;
  Double_t mean_m500 = (mean_p0 + mean_p1*mass); 
  Double_t sigma_m500 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
  Double_t a_m500 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
  //M550
  mass = 550.0;
  Double_t mean_m550 = (mean_p0 + mean_p1*mass); 
  Double_t sigma_m550 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
  Double_t a_m550 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
  //M600
  mass = 600.0;
  Double_t mean_m600 = (mean_p0 + mean_p1*mass); 
  Double_t sigma_m600 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
  Double_t a_m600 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
  //M650
  mass = 650.0;
  Double_t mean_m650 = (mean_p0 + mean_p1*mass); 
  Double_t sigma_m650 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
  Double_t a_m650 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
  //M700
  mass = 700.0;
  Double_t mean_m700 = (mean_p0 + mean_p1*mass); 
  Double_t sigma_m700 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
  Double_t a_m700 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
  //M750
  mass = 750.0;
  Double_t mean_m750 = (mean_p0 + mean_p1*mass); 
  Double_t sigma_m750 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
  Double_t a_m750 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
  //M800
  mass = 800.0;
  Double_t mean_m800 = (mean_p0 + mean_p1*mass); 
  Double_t sigma_m800 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
  Double_t a_m800 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
  //M850
  mass = 850.0;
  Double_t mean_m850 = (mean_p0 + mean_p1*mass); 
  Double_t sigma_m850 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
  Double_t a_m850 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
  //M900
  mass = 900.0;
  Double_t mean_m900 = (mean_p0 + mean_p1*mass); 
  Double_t sigma_m900 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
  Double_t a_m900 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
  //M950
  mass = 950.0;
  Double_t mean_m950 = (mean_p0 + mean_p1*mass); 
  Double_t sigma_m950 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
  Double_t a_m950 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
  //M1000
  mass = 1000.0;
  Double_t mean_m1000 = (mean_p0 + mean_p1*mass); 
  Double_t sigma_m1000 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
  Double_t a_m1000 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;

  // --- Define new Crystal Ball shapes for different mass points ---
  RooCBShape CrystalBall_m200("CrystalBall_m200","Crystal Ball 200 GeV", Mass, RooConst(mean_m200), RooConst(sigma_m200), RooConst(a_m200),RooConst(2));
  RooCBShape CrystalBall_m250("CrystalBall_m250","Crystal Ball 250 GeV", Mass, RooConst(mean_m250), RooConst(sigma_m250), RooConst(a_m250),RooConst(2));
  RooCBShape CrystalBall_m300("CrystalBall_m300","Crystal Ball 300 GeV", Mass, RooConst(mean_m300), RooConst(sigma_m300), RooConst(a_m300),RooConst(2));
  RooCBShape CrystalBall_m350("CrystalBall_m350","Crystal Ball 350 GeV", Mass, RooConst(mean_m350), RooConst(sigma_m350), RooConst(a_m350),RooConst(2));
  RooCBShape CrystalBall_m400("CrystalBall_m400","Crystal Ball 400 GeV", Mass, RooConst(mean_m400), RooConst(sigma_m400), RooConst(a_m400),RooConst(2));
  RooCBShape CrystalBall_m450("CrystalBall_m450","Crystal Ball 450 GeV", Mass, RooConst(mean_m450), RooConst(sigma_m450), RooConst(a_m450),RooConst(2));
  RooCBShape CrystalBall_m500("CrystalBall_m500","Crystal Ball 500 GeV", Mass, RooConst(mean_m500), RooConst(sigma_m500), RooConst(a_m500),RooConst(2));
  RooCBShape CrystalBall_m550("CrystalBall_m550","Crystal Ball 550 GeV", Mass, RooConst(mean_m550), RooConst(sigma_m550), RooConst(a_m550),RooConst(2));
  RooCBShape CrystalBall_m600("CrystalBall_m600","Crystal Ball 600 GeV", Mass, RooConst(mean_m600), RooConst(sigma_m600), RooConst(a_m600),RooConst(2));
  RooCBShape CrystalBall_m650("CrystalBall_m650","Crystal Ball 650 GeV", Mass, RooConst(mean_m650), RooConst(sigma_m650), RooConst(a_m650),RooConst(2));
  RooCBShape CrystalBall_m700("CrystalBall_m700","Crystal Ball 700 GeV", Mass, RooConst(mean_m700), RooConst(sigma_m700), RooConst(a_m700),RooConst(2));
  RooCBShape CrystalBall_m750("CrystalBall_m750","Crystal Ball 750 GeV", Mass, RooConst(mean_m750), RooConst(sigma_m750), RooConst(a_m750),RooConst(2));
  RooCBShape CrystalBall_m800("CrystalBall_m800","Crystal Ball 800 GeV", Mass, RooConst(mean_m800), RooConst(sigma_m800), RooConst(a_m800),RooConst(2));
  RooCBShape CrystalBall_m850("CrystalBall_m850","Crystal Ball 850 GeV", Mass, RooConst(mean_m850), RooConst(sigma_m850), RooConst(a_m850),RooConst(2));
  RooCBShape CrystalBall_m900("CrystalBall_m900","Crystal Ball 900 GeV", Mass, RooConst(mean_m900), RooConst(sigma_m900), RooConst(a_m900),RooConst(2));
  RooCBShape CrystalBall_m950("CrystalBall_m950","Crystal Ball 950 GeV", Mass, RooConst(mean_m950), RooConst(sigma_m950), RooConst(a_m950),RooConst(2));
  RooCBShape CrystalBall_m1000("CrystalBall_m1000","Crystal Ball 1000 GeV", Mass, RooConst(mean_m1000), RooConst(sigma_m1000), RooConst(a_m1000),RooConst(2));
  
  //cout << "mean_m250   " << mean_m250 << endl;
  //cout << "sigma_m250 " << sigma_m250 << endl;
  //cout << "a_m250     " << a_m200 << endl;
  Fitframe->GetYaxis()->SetRangeUser(0.00001,0.16);
  Fitframe->GetYaxis()->SetDrawOption("Logy");
  CrystalBall_m250.plotOn(Fitframe, LineColor(7));  
  CrystalBall_m300.plotOn(Fitframe, LineColor(8));  
  CrystalBall_m400.plotOn(Fitframe, LineColor(9));  
  CrystalBall_m450.plotOn(Fitframe, LineColor(11));  
  CrystalBall_m500.plotOn(Fitframe, LineColor(4));
  CrystalBall_m550.plotOn(Fitframe, LineColor(12));  
  CrystalBall_m600.plotOn(Fitframe, LineColor(13));  
  CrystalBall_m650.plotOn(Fitframe, LineColor(14));  
  CrystalBall_m700.plotOn(Fitframe, LineColor(15));  
  CrystalBall_m800.plotOn(Fitframe, LineColor(16));  
  CrystalBall_m850.plotOn(Fitframe, LineColor(17));  
  CrystalBall_m900.plotOn(Fitframe, LineColor(18));  
  CrystalBall_m950.plotOn(Fitframe, LineColor(19));  
  Fitframe->Write("Signal_Templates");
  TH1 * Hist_m250 = MASS.createHistogram("Signal m250",Binning(200)) ;
  TH1 * Hist_m300 = MASS.createHistogram("Signal m300",Binning(200)) ;
  TH1 * Hist_m400 = MASS.createHistogram("Signal m400",Binning(200)) ;
  TH1 * Hist_m450 = MASS.createHistogram("Signal m450",Binning(200)) ;
  TH1 * Hist_m550 = MASS.createHistogram("Signal m550",Binning(200)) ;
  TH1 * Hist_m600 = MASS.createHistogram("Signal m600",Binning(200)) ;
  TH1 * Hist_m650 = MASS.createHistogram("Signal m650",Binning(200)) ;
  TH1 * Hist_m700 = MASS.createHistogram("Signal m700",Binning(200)) ;
  TH1 * Hist_m800 = MASS.createHistogram("Signal m800",Binning(200)) ;
  TH1 * Hist_m850 = MASS.createHistogram("Signal m850",Binning(200)) ;
  TH1 * Hist_m900 = MASS.createHistogram("Signal m900",Binning(200)) ;
  TH1 * Hist_m950 = MASS.createHistogram("Signal m950",Binning(200)) ;
  
  //--- For removal of 200 GeV mass point 
  //CrystalBall1.fitTo(signal_m200);
  signal_m200.plotOn(Massframe,LineColor(2),MarkerColor(2),MarkerSize(1.0));
  CrystalBall1.plotOn(Massframe, LineColor(2),LineStyle(2));
  CrystalBall_m200.plotOn(Massframe,LineColor(2),LineWidth(3));
  CrystalBall1.fillHistogram(Hist_m200,RooArgList(MASS));
  //---
  CrystalBall_m250.fillHistogram(Hist_m250,RooArgList(MASS));
  CrystalBall_m300.fillHistogram(Hist_m300,RooArgList(MASS));
  //--- For removal of 350 GeV mass point 
  //CrystalBall2.fitTo(signal_m350);
  signal_m350.plotOn(Massframe,LineColor(3),MarkerColor(3),MarkerSize(1.0));
  CrystalBall2.plotOn(Massframe, LineColor(3),LineStyle(2));
  CrystalBall_m350.plotOn(Massframe,LineColor(3),LineWidth(3));
  CrystalBall2.fillHistogram(Hist_m350,RooArgList(MASS));
  //---
  CrystalBall_m400.fillHistogram(Hist_m400,RooArgList(MASS));
  CrystalBall_m450.fillHistogram(Hist_m450,RooArgList(MASS));
  //--- For removal of 500 GeV mass point
  CrystalBall3.fitTo(signal_m500);
  signal_m500.plotOn(Massframe,LineColor(4),MarkerColor(4),MarkerSize(1.0));
  CrystalBall3.plotOn(Massframe, LineColor(4),LineStyle(2));
  CrystalBall_m500.plotOn(Massframe,LineColor(4),LineWidth(3));
  CrystalBall_m500.fillHistogram(Hist_m500,RooArgList(MASS));
  //---  
  CrystalBall_m550.fillHistogram(Hist_m550,RooArgList(MASS));
  CrystalBall_m600.fillHistogram(Hist_m600,RooArgList(MASS));
  CrystalBall_m650.fillHistogram(Hist_m650,RooArgList(MASS));
  CrystalBall_m700.fillHistogram(Hist_m700,RooArgList(MASS));
  //--- For removal of 750 GeV mass point
  //CrystalBall4.fitTo(signal_m750);
  signal_m750.plotOn(Massframe,LineColor(5),MarkerColor(5),MarkerSize(1.0));
  CrystalBall4.plotOn(Massframe, LineColor(5),LineStyle(2));
  CrystalBall_m750.plotOn(Massframe,LineColor(5),LineWidth(3));
  CrystalBall4.fillHistogram(Hist_m750,RooArgList(MASS));
  //---  
  CrystalBall_m800.fillHistogram(Hist_m800,RooArgList(MASS));
  CrystalBall_m850.fillHistogram(Hist_m850,RooArgList(MASS));
  CrystalBall_m900.fillHistogram(Hist_m900,RooArgList(MASS));
  CrystalBall_m950.fillHistogram(Hist_m950,RooArgList(MASS));
  //--- For removal of 1000 GeV mass point
  //CrystalBall5.fitTo(signal_m1000);
  signal_m1000.plotOn(Massframe,LineColor(6),MarkerColor(6),MarkerSize(1.0));
  CrystalBall5.plotOn(Massframe, LineColor(6),LineStyle(2));
  CrystalBall_m1000.plotOn(Massframe,LineColor(6),LineWidth(3));
  CrystalBall5.fillHistogram(Hist_m1000,RooArgList(MASS));
  //---  
  Massframe->Write("CrystalBallFits");

  //--- Old Method
  //Double_t Channel_Acceptance_m250 = Channel_Acceptance_m200 + (Channel_Acceptance_m350-Channel_Acceptance_m200)*1./3.;
  //Double_t Channel_Acceptance_m300 = Channel_Acceptance_m200 + (Channel_Acceptance_m350-Channel_Acceptance_m200)*2./3.;
  //Double_t Channel_Acceptance_m400 = Channel_Acceptance_m350 + (Channel_Acceptance_m500-Channel_Acceptance_m350)*1./3.;
  //Double_t Channel_Acceptance_m450 = Channel_Acceptance_m350 + (Channel_Acceptance_m500-Channel_Acceptance_m350)*2./3.;
  //Double_t Channel_Acceptance_m550 = Channel_Acceptance_m500 + (Channel_Acceptance_m750-Channel_Acceptance_m500)*1./5.;
  //Double_t Channel_Acceptance_m600 = Channel_Acceptance_m500 + (Channel_Acceptance_m750-Channel_Acceptance_m500)*2./5.;
  //Double_t Channel_Acceptance_m650 = Channel_Acceptance_m500 + (Channel_Acceptance_m750-Channel_Acceptance_m500)*3./5.;
  //Double_t Channel_Acceptance_m700 = Channel_Acceptance_m500 + (Channel_Acceptance_m750-Channel_Acceptance_m500)*4./5.;
  //Double_t Channel_Acceptance_m800 = Channel_Acceptance_m750 + (Channel_Acceptance_m1000-Channel_Acceptance_m750)*1./5.;
  //Double_t Channel_Acceptance_m850 = Channel_Acceptance_m750 + (Channel_Acceptance_m1000-Channel_Acceptance_m750)*2./5.;
  //Double_t Channel_Acceptance_m900 = Channel_Acceptance_m750 + (Channel_Acceptance_m1000-Channel_Acceptance_m750)*3./5.;
  //Double_t Channel_Acceptance_m950 = Channel_Acceptance_m750 + (Channel_Acceptance_m1000-Channel_Acceptance_m750)*4./5.;
  //----

  Double_t Xmass = 250;  
  Double_t Channel_Acceptance_m250 = chn_acc_p0 + chn_acc_p1*Xmass + chn_acc_p2*Xmass*Xmass + chn_acc_p3*Xmass*Xmass*Xmass;
  Xmass = 300;
  Double_t Channel_Acceptance_m300 = chn_acc_p0 + chn_acc_p1*Xmass + chn_acc_p2*Xmass*Xmass + chn_acc_p3*Xmass*Xmass*Xmass;
  Xmass = 400;
  Double_t Channel_Acceptance_m400 = chn_acc_p0 + chn_acc_p1*Xmass + chn_acc_p2*Xmass*Xmass + chn_acc_p3*Xmass*Xmass*Xmass;
  Xmass = 450;
  Double_t Channel_Acceptance_m450 = chn_acc_p0 + chn_acc_p1*Xmass + chn_acc_p2*Xmass*Xmass + chn_acc_p3*Xmass*Xmass*Xmass;
  Xmass = 550;
  Double_t Channel_Acceptance_m550 = chn_acc_p0 + chn_acc_p1*Xmass + chn_acc_p2*Xmass*Xmass + chn_acc_p3*Xmass*Xmass*Xmass;
  Xmass = 600;
  Double_t Channel_Acceptance_m600 = chn_acc_p0 + chn_acc_p1*Xmass + chn_acc_p2*Xmass*Xmass + chn_acc_p3*Xmass*Xmass*Xmass;
  Xmass = 650;
  Double_t Channel_Acceptance_m650 = chn_acc_p0 + chn_acc_p1*Xmass + chn_acc_p2*Xmass*Xmass + chn_acc_p3*Xmass*Xmass*Xmass;
  Xmass = 700;
  Double_t Channel_Acceptance_m700 = chn_acc_p0 + chn_acc_p1*Xmass + chn_acc_p2*Xmass*Xmass + chn_acc_p3*Xmass*Xmass*Xmass;
  Xmass = 800;
  Double_t Channel_Acceptance_m800 = chn_acc_p0 + chn_acc_p1*Xmass + chn_acc_p2*Xmass*Xmass + chn_acc_p3*Xmass*Xmass*Xmass;
  Xmass = 850;
  Double_t Channel_Acceptance_m850 = chn_acc_p0 + chn_acc_p1*Xmass + chn_acc_p2*Xmass*Xmass + chn_acc_p3*Xmass*Xmass*Xmass;
  Xmass = 900;
  Double_t Channel_Acceptance_m900 = chn_acc_p0 + chn_acc_p1*Xmass + chn_acc_p2*Xmass*Xmass + chn_acc_p3*Xmass*Xmass*Xmass;
  Xmass = 950;
  Double_t Channel_Acceptance_m950 = chn_acc_p0 + chn_acc_p1*Xmass + chn_acc_p2*Xmass*Xmass + chn_acc_p3*Xmass*Xmass*Xmass;
					 
  Double_t Scale_m200 = Total_Lumi*CrossSection_m200*Channel_Acceptance_m200;
  Double_t Scale_m250 = Total_Lumi*CrossSection_m250*Channel_Acceptance_m250;
  Double_t Scale_m300 = Total_Lumi*CrossSection_m300*Channel_Acceptance_m300;
  Double_t Scale_m350 = Total_Lumi*CrossSection_m350*Channel_Acceptance_m350;
  Double_t Scale_m400 = Total_Lumi*CrossSection_m400*Channel_Acceptance_m400;
  Double_t Scale_m450 = Total_Lumi*CrossSection_m450*Channel_Acceptance_m450;
  Double_t Scale_m500 = Total_Lumi*CrossSection_m500*Channel_Acceptance_m500;
  Double_t Scale_m550 = Total_Lumi*CrossSection_m550*Channel_Acceptance_m550;
  Double_t Scale_m600 = Total_Lumi*CrossSection_m600*Channel_Acceptance_m600;
  Double_t Scale_m650 = Total_Lumi*CrossSection_m650*Channel_Acceptance_m650;
  Double_t Scale_m700 = Total_Lumi*CrossSection_m700*Channel_Acceptance_m700;
  Double_t Scale_m750 = Total_Lumi*CrossSection_m750*Channel_Acceptance_m750;
  Double_t Scale_m800 = Total_Lumi*CrossSection_m800*Channel_Acceptance_m800;
  Double_t Scale_m850 = Total_Lumi*CrossSection_m850*Channel_Acceptance_m850;
  Double_t Scale_m900 = Total_Lumi*CrossSection_m900*Channel_Acceptance_m900;
  Double_t Scale_m950 = Total_Lumi*CrossSection_m950*Channel_Acceptance_m950;
  Double_t Scale_m1000 = Total_Lumi*CrossSection_m1000*Channel_Acceptance_m1000;

  Hist_m200->Scale(3333*Channel_Acceptance_m200*2);
  Hist_m250->Scale(3333*Channel_Acceptance_m250*2);
  Hist_m300->Scale(3333*Channel_Acceptance_m300*2);
  Hist_m350->Scale(3333*Channel_Acceptance_m350*2);
  Hist_m400->Scale(3333*Channel_Acceptance_m400*2);
  Hist_m450->Scale(3333*Channel_Acceptance_m450*2);
  Hist_m500->Scale(3333*Channel_Acceptance_m500*2);
  Hist_m550->Scale(3333*Channel_Acceptance_m550*2);
  Hist_m600->Scale(3333*Channel_Acceptance_m600*2);
  Hist_m650->Scale(3333*Channel_Acceptance_m650*2);
  Hist_m700->Scale(3333*Channel_Acceptance_m700*2);
  Hist_m750->Scale(3333*Channel_Acceptance_m750*2);
  Hist_m800->Scale(3333*Channel_Acceptance_m800*2);
  Hist_m850->Scale(3333*Channel_Acceptance_m850*2);
  Hist_m900->Scale(3333*Channel_Acceptance_m900*2);
  Hist_m950->Scale(3333*Channel_Acceptance_m950*2);
  Hist_m1000->Scale(3333*Channel_Acceptance_m1000*2);

  Int_t total_bins = 200;
  for(Int_t bin = 0; bin < total_bins ; bin++){
    if(Hist_m200->GetBinContent(bin) >= 1.0){
      Hist_m200->SetBinError(bin, sqrt(Hist_m200->GetBinContent(bin)));
    }
    if(Hist_m250->GetBinContent(bin) >= 1.0){
      Hist_m250->SetBinError(bin, sqrt(Hist_m250->GetBinContent(bin)));
    }
    if(Hist_m300->GetBinContent(bin) >= 1.0){
      Hist_m300->SetBinError(bin, sqrt(Hist_m300->GetBinContent(bin)));
    }
    if(Hist_m350->GetBinContent(bin) >= 1.0){
      Hist_m350->SetBinError(bin, sqrt(Hist_m350->GetBinContent(bin)));
    }
    if(Hist_m400->GetBinContent(bin) >= 1.0){
      Hist_m400->SetBinError(bin, sqrt(Hist_m400->GetBinContent(bin)));
    }
    if(Hist_m450->GetBinContent(bin) >= 1.0){
      Hist_m450->SetBinError(bin, sqrt(Hist_m450->GetBinContent(bin)));
    }
    if(Hist_m500->GetBinContent(bin) >= 1.0){
      Hist_m500->SetBinError(bin, sqrt(Hist_m500->GetBinContent(bin)));
    }
    if(Hist_m550->GetBinContent(bin) >= 1.0){
      Hist_m550->SetBinError(bin, sqrt(Hist_m550->GetBinContent(bin)));
    }
    if(Hist_m600->GetBinContent(bin) >= 1.0){
      Hist_m600->SetBinError(bin, sqrt(Hist_m600->GetBinContent(bin)));
    }
    if(Hist_m650->GetBinContent(bin) >= 1.0){
      Hist_m650->SetBinError(bin, sqrt(Hist_m650->GetBinContent(bin)));
    }
    if(Hist_m700->GetBinContent(bin) >= 1.0){
      Hist_m700->SetBinError(bin, sqrt(Hist_m700->GetBinContent(bin)));
    }
    if(Hist_m750->GetBinContent(bin) >= 1.0){
      Hist_m750->SetBinError(bin, sqrt(Hist_m750->GetBinContent(bin)));
    }
    if(Hist_m800->GetBinContent(bin) >= 1.0){
      Hist_m800->SetBinError(bin, sqrt(Hist_m800->GetBinContent(bin)));
    }
    if(Hist_m850->GetBinContent(bin) >= 1.0){
      Hist_m850->SetBinError(bin, sqrt(Hist_m850->GetBinContent(bin)));
    }
    if(Hist_m900->GetBinContent(bin) >= 1.0){
      Hist_m900->SetBinError(bin, sqrt(Hist_m900->GetBinContent(bin)));
    }
    if(Hist_m950->GetBinContent(bin) >= 1.0){
      Hist_m950->SetBinError(bin, sqrt(Hist_m950->GetBinContent(bin)));
    }
    if(Hist_m1000->GetBinContent(bin) >= 1.0){
      Hist_m1000->SetBinError(bin, sqrt(Hist_m1000->GetBinContent(bin)));
    }

    if(Hist_m200->GetBinContent(bin) < 1.0){
      Hist_m200->SetBinError(bin, Hist_m200->GetBinContent(bin));
    }
    if(Hist_m250->GetBinContent(bin) < 1.0){
      Hist_m250->SetBinError(bin, Hist_m250->GetBinContent(bin));
    }
    if(Hist_m300->GetBinContent(bin) < 1.0){
      Hist_m300->SetBinError(bin, Hist_m300->GetBinContent(bin));
    }
    if(Hist_m350->GetBinContent(bin) < 1.0){
      Hist_m350->SetBinError(bin, Hist_m350->GetBinContent(bin));
    }
    if(Hist_m400->GetBinContent(bin) < 1.0){
      Hist_m400->SetBinError(bin, Hist_m400->GetBinContent(bin));
    }
    if(Hist_m450->GetBinContent(bin) < 1.0){
      Hist_m450->SetBinError(bin, Hist_m450->GetBinContent(bin));
    }
    if(Hist_m500->GetBinContent(bin) < 1.0){
      Hist_m500->SetBinError(bin, Hist_m500->GetBinContent(bin));
    }
    if(Hist_m550->GetBinContent(bin) < 1.0){
      Hist_m550->SetBinError(bin, Hist_m550->GetBinContent(bin));
    }
    if(Hist_m600->GetBinContent(bin) < 1.0){
      Hist_m600->SetBinError(bin, Hist_m600->GetBinContent(bin));
    }
    if(Hist_m650->GetBinContent(bin) < 1.0){
      Hist_m650->SetBinError(bin, Hist_m650->GetBinContent(bin));
    }
    if(Hist_m700->GetBinContent(bin) < 1.0){
      Hist_m700->SetBinError(bin, Hist_m700->GetBinContent(bin));
    }
    if(Hist_m750->GetBinContent(bin) < 1.0){
      Hist_m750->SetBinError(bin, Hist_m750->GetBinContent(bin));
    }
    if(Hist_m800->GetBinContent(bin) < 1.0){
      Hist_m800->SetBinError(bin, Hist_m800->GetBinContent(bin));
    }
    if(Hist_m850->GetBinContent(bin) < 1.0){
      Hist_m850->SetBinError(bin, Hist_m850->GetBinContent(bin));
    }
    if(Hist_m900->GetBinContent(bin) < 1.0){
      Hist_m900->SetBinError(bin, Hist_m900->GetBinContent(bin));
    }
    if(Hist_m950->GetBinContent(bin) < 1.0){
      Hist_m950->SetBinError(bin, Hist_m950->GetBinContent(bin));
    }
    if(Hist_m1000->GetBinContent(bin) < 1.0){
      Hist_m1000->SetBinError(bin, Hist_m1000->GetBinContent(bin));
    }
  }


  Hist_m200->Scale(Scale_m200/(3333*Channel_Acceptance_m200*2));
  Hist_m250->Scale(Scale_m250/(3333*Channel_Acceptance_m250*2));
  Hist_m300->Scale(Scale_m300/(3333*Channel_Acceptance_m300*2));
  Hist_m350->Scale(Scale_m350/(3333*Channel_Acceptance_m350*2));
  Hist_m400->Scale(Scale_m400/(3333*Channel_Acceptance_m400*2));
  Hist_m450->Scale(Scale_m450/(3333*Channel_Acceptance_m450*2));
  Hist_m500->Scale(Scale_m500/(3333*Channel_Acceptance_m500*2));
  Hist_m550->Scale(Scale_m550/(3333*Channel_Acceptance_m550*2));
  Hist_m600->Scale(Scale_m600/(3333*Channel_Acceptance_m600*2));
  Hist_m650->Scale(Scale_m650/(3333*Channel_Acceptance_m650*2));
  Hist_m700->Scale(Scale_m700/(3333*Channel_Acceptance_m700*2));
  Hist_m750->Scale(Scale_m750/(3333*Channel_Acceptance_m750*2));
  Hist_m800->Scale(Scale_m800/(3333*Channel_Acceptance_m800*2));
  Hist_m850->Scale(Scale_m850/(3333*Channel_Acceptance_m850*2));
  Hist_m900->Scale(Scale_m900/(3333*Channel_Acceptance_m900*2));
  Hist_m950->Scale(Scale_m950/(3333*Channel_Acceptance_m950*2));
  Hist_m1000->Scale(Scale_m1000/(3333*Channel_Acceptance_m1000*2));

  
  
  //Hist_m200->Rebin(200);
  //Hist_m200-SetRange(0.,2000.);
  //Hist_m250->SetBins(nBins, 0., 2000.);
  //Hist_m300->SetBins(nBins, 0., 2000.);
  //Hist_m350->SetBins(nBins, 0., 2000.);
  //Hist_m400->SetBins(nBins, 0., 2000.);
  //Hist_m450->SetBins(nBins, 0., 2000.);
  //Hist_m500->SetBins(nBins, 0., 2000.);
  //Hist_m550->SetBins(nBins, 0., 2000.);
  //Hist_m600->SetBins(nBins, 0., 2000.);
  //Hist_m650->SetBins(nBins, 0., 2000.);
  //Hist_m700->SetBins(nBins, 0., 2000.);
  //Hist_m750->SetBins(nBins, 0., 2000.);
  //Hist_m800->SetBins(nBins, 0., 2000.);
  //Hist_m850->SetBins(nBins, 0., 2000.);
  //Hist_m900->SetBins(nBins, 0., 2000.);
  //Hist_m950->SetBins(nBins, 0., 2000.);
  //Hist_m1000->SetBins(nBins, 0., 2000.);
  
  cout << "=====================================" << endl;
  cout << "Integral_m200 " << Integral_m200 << endl;   
  cout << "Integral_m350 " << Integral_m350 << endl;   
  cout << "Integral_m500 " << Integral_m500 << endl;   
  cout << "Integral_m750 " << Integral_m750 << endl;   
  cout << "Integral_m1000 " << Integral_m1000 << endl;   
  Integral_m200 = Hist_m200->Integral(0,200); 
  Double_t Integral_m250 = Hist_m250->Integral(0,200);
  Double_t Integral_m300 = Hist_m300->Integral(0,200);
  Integral_m350 = Hist_m350->Integral(0,200);
  Double_t Integral_m400 = Hist_m400->Integral(0,200);
  Double_t Integral_m450 = Hist_m450->Integral(0,200);
  Integral_m500 = Hist_m500->Integral(0,200);
  Double_t Integral_m550 = Hist_m550->Integral(0,200);
  Double_t Integral_m600 = Hist_m600->Integral(0,200);
  Double_t Integral_m650 = Hist_m650->Integral(0,200);
  Double_t Integral_m700 = Hist_m700->Integral(0,200);
  Integral_m750 = Hist_m750->Integral(0,200);
  Double_t Integral_m800 = Hist_m800->Integral(0,200);
  Double_t Integral_m850 = Hist_m850->Integral(0,200);
  Double_t Integral_m900 = Hist_m900->Integral(0,200);
  Double_t Integral_m950 = Hist_m950->Integral(0,200);
  Integral_m1000 = Hist_m1000->Integral(0,200);

  cout << "=====================================" << endl;
  cout << "Integral_m200 " << Integral_m200 << endl;   
  cout << "Integral_m250 " << Integral_m250 << endl;   
  cout << "Integral_m300 " << Integral_m300 << endl;   
  cout << "Integral_m350 " << Integral_m350 << endl;   
  cout << "Integral_m400 " << Integral_m400 << endl;   
  cout << "Integral_m450 " << Integral_m450 << endl;   
  cout << "Integral_m500 " << Integral_m500 << endl;   
  cout << "Integral_m550 " << Integral_m550 << endl;   
  cout << "Integral_m600 " << Integral_m600 << endl;   
  cout << "Integral_m650 " << Integral_m650 << endl;   
  cout << "Integral_m700 " << Integral_m700 << endl;   
  cout << "Integral_m750 " << Integral_m750 << endl;   
  cout << "Integral_m800 " << Integral_m800 << endl;   
  cout << "Integral_m850 " << Integral_m850 << endl;   
  cout << "Integral_m900 " << Integral_m900 << endl;   
  cout << "Integral_m950 " << Integral_m950 << endl;   
  cout << "Integral_m1000 " << Integral_m1000 << endl;   
  cout << "=====================================" << endl;
  cout << "Total_Channel_m200 " << Total_Channel_m200 << endl;
  cout << "Total_Channel_m350 " << Total_Channel_m350 << endl;
  cout << "Total_Channel_m500 " << Total_Channel_m500 << endl;
  cout << "Total_Channel_m750 " << Total_Channel_m750 << endl;
  cout << "Total_Channel_m1000 " << Total_Channel_m1000 << endl;
  cout << "=====================================" << endl;
  cout << "Channel_Acceptance_m200  " << Channel_Acceptance_m200*4 << endl; 
  cout << "Channel_Acceptance_m250  " << Channel_Acceptance_m250*4 << endl; 
  cout << "Channel_Acceptance_m300  " << Channel_Acceptance_m300*4 << endl; 
  cout << "Channel_Acceptance_m350  " << Channel_Acceptance_m350*4 << endl; 
  cout << "Channel_Acceptance_m400  " << Channel_Acceptance_m400*4 << endl; 
  cout << "Channel_Acceptance_m450  " << Channel_Acceptance_m450*4 << endl; 
  cout << "Channel_Acceptance_m500  " << Channel_Acceptance_m500*4 << endl; 
  cout << "Channel_Acceptance_m550  " << Channel_Acceptance_m550*4 << endl; 
  cout << "Channel_Acceptance_m600  " << Channel_Acceptance_m600*4 << endl; 
  cout << "Channel_Acceptance_m650  " << Channel_Acceptance_m650*4 << endl; 
  cout << "Channel_Acceptance_m700  " << Channel_Acceptance_m700*4 << endl; 
  cout << "Channel_Acceptance_m750  " << Channel_Acceptance_m750*4 << endl; 
  cout << "Channel_Acceptance_m800  " << Channel_Acceptance_m800*4 << endl; 
  cout << "Channel_Acceptance_m850  " << Channel_Acceptance_m850*4 << endl; 
  cout << "Channel_Acceptance_m900  " << Channel_Acceptance_m900*4 << endl; 
  cout << "Channel_Acceptance_m950  " << Channel_Acceptance_m950*4 << endl; 
  cout << "Channel_Acceptance_m1000  " << Channel_Acceptance_m1000*4 << endl; 
  cout << "=====================================" << endl;


  /*Hist_m250->Sumw2();
    Hist_m300->Sumw2();
    Hist_m400->Sumw2();
    Hist_m450->Sumw2();
    Hist_m550->Sumw2();
    Hist_m600->Sumw2();
    Hist_m650->Sumw2();
    Hist_m700->Sumw2();
    Hist_m800->Sumw2();
    Hist_m850->Sumw2();
    Hist_m900->Sumw2();
    Hist_m950->Sumw2();*/

  //Hist_m200->Write("wprime_lvll_m200");
  h1_m200->Write("wprime_lvll_m200");
  Hist_m250->Write("wprime_lvll_m250");
  Hist_m300->Write("wprime_lvll_m300");
  //Hist_m350->Write("wprime_lvll_m350");
  h1_m350->Write("wprime_lvll_m350");
  Hist_m400->Write("wprime_lvll_m400");
  Hist_m450->Write("wprime_lvll_m450");
  //Hist_m500->Write("wprime_lvll_m500");
  h1_m500->Write("wprime_lvll_m500");
  Hist_m550->Write("wprime_lvll_m550");
  Hist_m600->Write("wprime_lvll_m600");
  Hist_m650->Write("wprime_lvll_m650");
  Hist_m700->Write("wprime_lvll_m700");
  //Hist_m750->Write("wprime_lvll_m750");
  h1_m750->Write("wprime_lvll_m750");
  Hist_m800->Write("wprime_lvll_m800");
  Hist_m850->Write("wprime_lvll_m850");
  Hist_m900->Write("wprime_lvll_m900");
  Hist_m950->Write("wprime_lvll_m950");
  //Hist_m1000->Write("wprime_lvll_m1000");
  h1_m1000->Write("wprime_lvll_m1000");
  //cout << "norm_m200  " << norm_m200 << endl;

  CrystalBallFits->Close();
  
  //===================================================================
  // --- Loop Over All Systematics ---
  //===================================================================

  //RooRealVar Mass("Mass","Transverse Mass (GeV)", 0, 2000);
  //RooRealVar MASS("MASS","Transverse Mass (GeV)", 0, 2000);
  Int_t sys = atoi(argv[3]);   
  TString Systematic;  
  if(sys == 0){
      Systematic = "elec_scale_up";
    }
    if(sys == 1){
      Systematic = "elec_smear_up";
    }
    if(sys == 2){
      Systematic = "lljet_fake_up";
    }
    if(sys == 3){
      Systematic = "MET_Cell_Topo_up";
    }
    if(sys == 4){
      Systematic = "MET_Cell_Track_up";
    }
    if(sys == 5){
      Systematic = "MET_intime_up";
    }
    if(sys == 6){
      Systematic = "MET_outtime_up";
    }
    if(sys == 7){
      Systematic = "muon_scale_up";
    }
    if(sys == 8){
      Systematic = "muon_smear_id_up";
    }
    if(sys == 9){
      Systematic = "muon_smear_ms_up";
    }
    if(sys == 10){
      Systematic = "elec_scale_down";
    }
    if(sys == 11){
      Systematic = "elec_smear_down";
    }
    if(sys == 12){
      Systematic = "lljet_fake_down";
    }
    if(sys == 13){
      Systematic = "MET_Cell_Topo_down";
    }
    if(sys == 14){
      Systematic = "MET_Cell_Track_down";
    }
    if(sys == 15){
      Systematic = "MET_intime_down";
    }
    if(sys == 16){
      Systematic = "MET_outtime_down";
    }
    if(sys == 17){
      Systematic = "muon_scale_down";
    }
    if(sys == 18){
      Systematic = "muon_smear_id_down";
    }
    if(sys == 19){
      Systematic = "muon_smear_ms_down";
    }
    
    RooPlot * Fit_sys_frame = Mass.frame(); 
    RooPlot * Mass_sys_frame = Mass.frame(); 
    
    // --- Define Channel Acceptance --- 
    Double_t Channel_Acceptance_sys_m200 = Channel_Acceptance_m200*Integral_sys_m200[sys]/Integral_m200;
    Double_t Channel_Acceptance_sys_m350 = Channel_Acceptance_m350*Integral_sys_m350[sys]/Integral_m350;
    Double_t Channel_Acceptance_sys_m500 = Channel_Acceptance_m500*Integral_sys_m500[sys]/Integral_m500;
    Double_t Channel_Acceptance_sys_m750 = Channel_Acceptance_m750*Integral_sys_m750[sys]/Integral_m750;
    Double_t Channel_Acceptance_sys_m1000 = Channel_Acceptance_m1000*Integral_sys_m1000[sys]/Integral_m1000;
    
    RooDataHist signal_sys_m200("signal_sys_m200","W' signal", Mass, h_sys_m200[sys]);
    RooDataHist signal_sys_m350("signal_sys_m350","W' signal", Mass, h_sys_m350[sys]);
    RooDataHist signal_sys_m500("signal_sys_m500","W' signal", Mass, h_sys_m500[sys]);
    RooDataHist signal_sys_m750("signal_sys_m750","W' signal", Mass, h_sys_m750[sys]);
    RooDataHist signal_sys_m1000("signal_sys_m1000","W' signal", Mass, h_sys_m1000[sys]);
    //RooDataHist signal_sys_m1250("signal_sys_m1250","W' signal", Mass, h1_m1250);
    //RooDataHist signal_sys_m1500("signal_sys_m1500","W' signal", Mass, h1_m1500);
    
    // --- Fitting CrystalBall to Signal Shape ---
    TH1 * Hist_sys_m200 = MASS.createHistogram("Signal m200 "+Systematic, Binning(200));
    TH1 * Hist_sys_m350 = MASS.createHistogram("Signal m350 "+Systematic, Binning(200));
    TH1 * Hist_sys_m500 = MASS.createHistogram("Signal m500 "+Systematic, Binning(200));
    TH1 * Hist_sys_m750 = MASS.createHistogram("Signal m750 "+Systematic, Binning(200));
    TH1 * Hist_sys_m1000 = MASS.createHistogram("Signal m1000 "+Systematic, Binning(200));
    
    RooRealVar mean_sys1("mean_sys1","Mean of the Gaussian half of the Crystal Ball",180, 0, 2000);
    RooRealVar sigma_sys1("sigma_sys1","Sigma of the Gaussian half of the Crystal Ball", 15.0, 5., 20.0);
    RooRealVar a_sys1("a_sys1","Delimiting Value", 1., 0.01, 1500.0);
    RooRealVar n_sys1("n_sys1","Exponentiating Form", 2.0);//, 0.001, 100.0);
    RooRealVar mean_sys2("mean_sys2","Mean of the Gaussian half of the Crystal Ball",initial_mass2, 0, 2000);
    RooRealVar sigma_sys2("sigma_sys2","Sigma of the Gaussian half of the Crystal Ball", 15.0, 0.1, 40.0);
    RooRealVar a_sys2("a_sys2","Delimiting Value", 1.0, 0.01, 1500.0);
    RooRealVar n_sys2("n_sys2","Exponentiating Form", 2.0);//, 0.001, 100.0);
    RooRealVar mean_sys3("mean_sys3","Mean of the Gaussian half of the Crystal Ball",initial_mass3, 0, 2000);
    RooRealVar sigma_sys3("sigma_sys3","Sigma of the Gaussian half of the Crystal Ball", 15.0, 0.1, 100.0);
    RooRealVar a_sys3("a_sys3","Delimiting Value", 1.0, 0.01, 1500.0);
    RooRealVar n_sys3("n_sys3","Exponentiating Form", 2.0);//, 0.001, 100.0);
    RooRealVar mean_sys4("mean_sys4","Mean of the Gaussian half of the Crystal Ball",initial_mass4, 0, 2000);
    RooRealVar sigma_sys4("sigma_sys4","Sigma of the Gaussian half of the Crystal Ball", 40.0, 0.1, 110.0);
    RooRealVar a_sys4("a_sys4","Delimiting Value", 1.0, 0.01, 1500.0);
    RooRealVar n_sys4("n_sys4","Exponentiating Form", 2.0);//, 0.001, 100.0);
    RooRealVar mean_sys5("mean_sys5","Mean of the Gaussian half of the Crystal Ball",initial_mass5, 0, 2000);
    RooRealVar sigma_sys5("sigma_sys5","Sigma of the Gaussian half of the Crystal Ball", 50.0, 0.1, 120.0);
    RooRealVar a_sys5("a_sys5","Delimiting Value", 1.0, 0.01, 1500.0);
    RooRealVar n_sys5("n_sys5","Exponentiating Form", 2.0);//, 0.001, 100.0);
    RooRealVar mean_sys6("mean_sys6","Mean of the Gaussian half of the Crystal Ball",initial_mass6, 100, 2000);
    RooRealVar sigma_sys6("sigma_sys6","Sigma of the Gaussian half of the Crystal Ball", 10.0, 0.1, 140.0);
    RooRealVar a_sys6("a_sys6","Delimiting Value", 1.0, 0.01, 100.0);
    RooRealVar n_sys6("n_sys6","Exponentiating Form", 2.0);//, 0.001, 100.0);
    RooRealVar mean_sys7("mean_sys7","Mean of the Gaussian half of the Crystal Ball",initial_mass7, 100, 2000);
    RooRealVar sigma_sys7("sigma_sys7","Sigma of the Gaussian half of the Crystal Ball", 10.0, 0.1, 160.0);
    RooRealVar a_sys7("a_sys7","Delimiting Value", 1.0, 0.01, 100.0);
    RooRealVar n_sys7("n_sys7","Exponentiating Form", 2.0, 0.001, 100.0);
    
    RooCBShape CrystalBallSys1("CrystalBallSys1","Crystal Ball Fit to Signal Resonance",Mass,mean_sys1,sigma_sys1,a_sys1,n_sys1);
    RooCBShape CrystalBallSys2("CrystalBallSys2","Crystal Ball Fit to Signal Resonance",Mass,mean_sys2,sigma_sys2,a_sys2,n_sys2);
    RooCBShape CrystalBallSys3("CrystalBallSys3","Crystal Ball Fit to Signal Resonance",Mass,mean_sys3,sigma_sys3,a_sys3,n_sys3);
    RooCBShape CrystalBallSys4("CrystalBallSys4","Crystal Ball Fit to Signal Resonance",Mass,mean_sys4,sigma_sys4,a_sys4,n_sys4);
    RooCBShape CrystalBallSys5("CrystalBallSys5","Crystal Ball Fit to Signal Resonance",Mass,mean_sys5,sigma_sys5,a_sys5,n_sys5);
    RooCBShape CrystalBallSys6("CrystalBallSys6","Crystal Ball Fit to Signal Resonance",Mass,mean_sys6,sigma_sys6,a_sys6,n_sys6);
    RooCBShape CrystalBallSys7("CrystalBallSys7","Crystal Ball Fit to Signal Resonance",Mass,mean_sys7,sigma_sys7,a_sys7,n_sys7);

    CrystalBallSys1.fitTo(signal_sys_m200);
    //signal_sys_m200.plotOn(Mass_sys_frame,LineColor(2),MarkerColor(2));
    //CrystalBallSys1.plotOn(Mass_sys_frame,LineColor(2));
    //CrystalBallSys1.fillHistogram(Hist_sys_m200,RooArgList(MASS));
    
    CrystalBallSys2.fitTo(signal_sys_m350);
    //signal_sys_m350.plotOn(Mass_sys_frame,LineColor(3),MarkerColor(3));
    //CrystalBallSys2.plotOn(Mass_sys_frame,LineColor(3));
    //CrystalBallSys2.fillHistogram(Hist_sys_m350,RooArgList(MASS));
    
    CrystalBallSys3.fitTo(signal_sys_m500);
    //signal_sys_m500.plotOn(Mass_sys_frame,LineColor(4),MarkerColor(4));
    //CrystalBallSys3.plotOn(Mass_sys_frame,LineColor(4));
    //CrystalBallSys3.fillHistogram(Hist_sys_m500,RooArgList(MASS));
    
    CrystalBallSys4.fitTo(signal_sys_m750);
    //signal_sys_m750.plotOn(Mass_sys_frame,LineColor(5),MarkerColor(5));
    //CrystalBallSys4.plotOn(Mass_sys_frame,LineColor(5));
    //CrystalBallSys4.fillHistogram(Hist_sys_m750,RooArgList(MASS));
    
    CrystalBallSys5.fitTo(signal_sys_m1000);
    //signal_sys_m1000.plotOn(Mass_sys_frame,LineColor(6),MarkerColor(6));
    //CrystalBallSys5.plotOn(Mass_sys_frame,LineColor(6));
    //CrystalBallSys5.fillHistogram(Hist_sys_m1000,RooArgList(MASS));
    
    
    //CrystalBallSys6.fitTo(signal_sys_m1250);
    //CrystalBallSys7.fitTo(signal_sys_m1500);
    
    // --- Writing out the result
    //signal_sys_m1250.plotOn(Mass_sys_frame);
    //signal_sys_m1500.plotOn(Mass_sys_frame);
    //CrystalBallSys6.plotOn(Mass_sys_frame);
    //CrystalBallSys7.plotOn(Mass_sys_frame);
    TFile * CrystalBallSysFits = new TFile("Wprime_Templates/"+systematic_directory+"/"+Channel+"_"+Systematic+".root", "RECREATE");
    Mass_sys_frame->GetYaxis()->SetRangeUser(0.00001,10.);
    Mass_sys_frame->GetYaxis()->SetDrawOption("Logy");
    //Mass_sys_frame->Write("crystal_ball_fits_"+Systematic);
  
    //Double_t Mean_Sys[4];
    //Double_t Sigma[4];
    //Double_t A[4];
    //Double_t N[4];
    
    Mean[0] = mean_sys1.getVal();
    Mean[1] = mean_sys2.getVal();
    //Mean[2] = mean_sys3.getVal();
    Mean[2] = mean_sys4.getVal();
    Mean[3] = mean_sys5.getVal();
    
    Sigma[0] = sigma_sys1.getVal();
    Sigma[1] = sigma_sys2.getVal();
    //Sigma[2] = sigma_sys3.getVal();
    Sigma[2] = sigma_sys4.getVal();
    Sigma[3] = sigma_sys5.getVal();
    
    A[0] = a_sys1.getVal();
    A[1] = a_sys2.getVal();
    //A[2] = a_sys3.getVal();
    A[2] = a_sys4.getVal();
    A[3] = a_sys5.getVal();
    
    N[0] = n_sys1.getVal();
    N[1] = n_sys2.getVal();
    //N[2] = n_sys3.getVal();
    N[2] = n_sys4.getVal();
    N[3] = n_sys5.getVal();

    TCanvas *c_parm_sys = new TCanvas("c_parm_sys","Parameter fits "+Systematic,200,10,700,500);
    c_parm_sys->Divide(2,2);
    //Double_t x[4];
    //Int_t n = 4;
    //x[0] = 200.0;
    //x[0] = 350.0;
    //x[1] = 500.0;
    //x[2] = 750.0;
    //x[3] = 1000.0;

    TGraph * gr_parameter_sys_Mean = new TGraph(4,xx,Mean);
    TGraph * gr_parameter_sys_Sigma = new TGraph(4,xx,Sigma);
    TGraph * gr_parameter_sys_A = new TGraph(4,xx,A);
    TGraph * gr_parameter_sys_N = new TGraph(4,xx,N);
    
    TF1 * sigma_fit_sys = new TF1("sigma_fit_sys", "[0]*sqrt([1]*(x-[2]))");
    sigma_fit_sys->SetParameter(0,1);
    sigma_fit_sys->SetParameter(1,1);
    sigma_fit_sys->SetParameter(2,0);

    TF1 * a_fit_sys = new TF1("a_fit_sys", "[0]/([1]*x)+[2]*x");
    a_fit_sys->SetParameter(0,1);
    a_fit_sys->SetParameter(1,1);
    a_fit_sys->SetParameter(2,1);

    TFitResultPtr MEAN_sys = gr_parameter_sys_Mean->Fit("pol1", "S");
    TFitResultPtr SIGMA_sys = gr_parameter_sys_Sigma->Fit("sigma_fit_sys", "S");
    TFitResultPtr A_res_sys = gr_parameter_sys_A->Fit("a_fit_sys", "S");
    TFitResultPtr N_res_sys =  gr_parameter_sys_N->Fit("pol1", "S");
  
    c_parm_sys->cd(1);
    gr_parameter_sys_Mean->GetYaxis()->SetTitle("Crystal Ball Mean");
    gr_parameter_sys_Mean->GetXaxis()->SetTitle("W' Pole Mass [GeV]");
    gr_parameter_sys_Mean->SetMarkerColor(2);
    gr_parameter_sys_Mean->Draw("A*");
    gr_parameter_sys_Mean->SetMarkerStyle(22);
    c_parm_sys->cd(2);
    gr_parameter_sys_Sigma->GetYaxis()->SetTitle("Crystal Ball Sigma");
    gr_parameter_sys_Sigma->GetXaxis()->SetTitle("W' Pole Mass [GeV]");
    gr_parameter_sys_Sigma->SetMarkerColor(2);
    gr_parameter_sys_Sigma->Draw("A*");
    gr_parameter_sys_Sigma->SetMarkerStyle(22);
    c_parm_sys->cd(3);
    gr_parameter_sys_A->GetYaxis()->SetTitle("Crystal Ball a");
    gr_parameter_sys_A->GetXaxis()->SetTitle("W' Pole Mass [GeV]");
    gr_parameter_sys_A->SetMarkerColor(2);
    gr_parameter_sys_A->Draw("A*");
    gr_parameter_sys_A->SetMarkerStyle(22);
    c_parm_sys->cd(4);
    gr_parameter_sys_N->GetYaxis()->SetTitle("Crystal Ball n");
    gr_parameter_sys_N->GetXaxis()->SetTitle("W' Pole Mass [GeV]");
    gr_parameter_sys_N->SetMarkerColor(2);
    gr_parameter_sys_N->Draw("A*");
    gr_parameter_sys_N->SetMarkerStyle(22);
    
    c_parm_sys->Write("Fits_to_Parameters_"+Systematic);
    c_parm_sys->Delete();
    
    // --- Get Fit Parameter Values --- 
    //p0 + p1*x
    mean_p0 = MEAN_sys->Value(0);
    mean_p1 = MEAN_sys->Value(1);
    //p0*sqrt(p1*(x - p2))
    sigma_p0 = SIGMA_sys->Value(0); 
    sigma_p1 = SIGMA_sys->Value(1); 
    sigma_p2 = SIGMA_sys->Value(2);
    //exp(p0+p1*x) 
    a_res_p0 = A_res_sys->Value(0); 
    a_res_p1 = A_res_sys->Value(1); 
    a_res_p2 = A_res_sys->Value(2);

    // --- Get Function Values for different points --- 
    //M200
    //Double_t mass;
    mass = 200.0;
    mean_m200 = (mean_p0 + mean_p1*mass); 
    sigma_m200 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
    a_m200 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
    //M250
    mass = 250.0;
    mean_m250 = (mean_p0 + mean_p1*mass); 
    sigma_m250 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
    a_m250 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
    //M300
    mass = 300.0;
    mean_m300 = (mean_p0 + mean_p1*mass); 
    sigma_m300 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
    a_m300 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
    //M350
    mass = 350.0;
    mean_m350 = (mean_p0 + mean_p1*mass); 
    sigma_m350 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
    a_m350 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
    //M400
    mass = 400.0;
    mean_m400 = (mean_p0 + mean_p1*mass); 
    sigma_m400 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
    a_m400 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
    //M450
    mass = 450.0;
    mean_m450 = (mean_p0 + mean_p1*mass); 
    sigma_m450 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
    a_m450 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
    //M500
    mass = 500.0;
    mean_m500 = (mean_p0 + mean_p1*mass); 
    sigma_m500 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
    a_m500 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
    //M550
    mass = 550.0;
    mean_m550 = (mean_p0 + mean_p1*mass); 
    sigma_m550 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
    a_m550 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
    //M600
    mass = 600.0;
    mean_m600 = (mean_p0 + mean_p1*mass); 
    sigma_m600 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
    a_m600 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
    //M650
    mass = 650.0;
    mean_m650 = (mean_p0 + mean_p1*mass); 
    sigma_m650 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
    a_m650 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
    //M700
    mass = 700.0;
    mean_m700 = (mean_p0 + mean_p1*mass); 
    sigma_m700 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
    a_m700 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
    //M750
    mass = 750.0;
    mean_m750 = (mean_p0 + mean_p1*mass); 
    sigma_m750 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
    a_m750 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
    //M800
    mass = 800.0;
    mean_m800 = (mean_p0 + mean_p1*mass); 
    sigma_m800 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
    a_m800 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
    //M850
    mass = 850.0;
    mean_m850 = (mean_p0 + mean_p1*mass); 
    sigma_m850 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
    a_m850 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
    //M900
    mass = 900.0;
    mean_m900 = (mean_p0 + mean_p1*mass); 
    sigma_m900 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
    a_m900 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
    //M950
    mass = 950.0;
    mean_m950 = (mean_p0 + mean_p1*mass); 
    sigma_m950 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
    a_m950 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;
    //M1000
    mass = 1000.0;
    mean_m1000 = (mean_p0 + mean_p1*mass); 
    sigma_m1000 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
    a_m1000 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;

    // --- Define new Crystal Ball shapes for different mass points ---
    RooCBShape CrystalBallSys_m200("CrystalBallSys_m200","Crystal Ball 200 GeV", Mass, RooConst(mean_m200), RooConst(sigma_m200), RooConst(a_m200),RooConst(2));
    RooCBShape CrystalBallSys_m250("CrystalBallSys_m250","Crystal Ball 250 GeV", Mass, RooConst(mean_m250), RooConst(sigma_m250), RooConst(a_m250),RooConst(2));
    RooCBShape CrystalBallSys_m300("CrystalBallSys_m300","Crystal Ball 300 GeV", Mass, RooConst(mean_m300), RooConst(sigma_m300), RooConst(a_m300),RooConst(2));
    RooCBShape CrystalBallSys_m350("CrystalBallSys_m350","Crystal Ball 350 GeV", Mass, RooConst(mean_m350), RooConst(sigma_m350), RooConst(a_m350),RooConst(2));
    RooCBShape CrystalBallSys_m400("CrystalBallSys_m400","Crystal Ball 400 GeV", Mass, RooConst(mean_m400), RooConst(sigma_m400), RooConst(a_m400),RooConst(2));
    RooCBShape CrystalBallSys_m450("CrystalBallSys_m450","Crystal Ball 450 GeV", Mass, RooConst(mean_m450), RooConst(sigma_m450), RooConst(a_m450),RooConst(2));
    RooCBShape CrystalBallSys_m500("CrystalBallSys_m500","Crystal Ball 500 GeV", Mass, RooConst(mean_m500), RooConst(sigma_m500), RooConst(a_m500),RooConst(2));
    RooCBShape CrystalBallSys_m550("CrystalBallSys_m550","Crystal Ball 550 GeV", Mass, RooConst(mean_m550), RooConst(sigma_m550), RooConst(a_m550),RooConst(2));
    RooCBShape CrystalBallSys_m600("CrystalBallSys_m600","Crystal Ball 600 GeV", Mass, RooConst(mean_m600), RooConst(sigma_m600), RooConst(a_m600),RooConst(2));
    RooCBShape CrystalBallSys_m650("CrystalBallSys_m650","Crystal Ball 650 GeV", Mass, RooConst(mean_m650), RooConst(sigma_m650), RooConst(a_m650),RooConst(2));
    RooCBShape CrystalBallSys_m700("CrystalBallSys_m700","Crystal Ball 700 GeV", Mass, RooConst(mean_m700), RooConst(sigma_m700), RooConst(a_m700),RooConst(2));
    RooCBShape CrystalBallSys_m750("CrystalBallSys_m750","Crystal Ball 750 GeV", Mass, RooConst(mean_m750), RooConst(sigma_m750), RooConst(a_m750),RooConst(2));
    RooCBShape CrystalBallSys_m800("CrystalBallSys_m800","Crystal Ball 800 GeV", Mass, RooConst(mean_m800), RooConst(sigma_m800), RooConst(a_m800),RooConst(2));
    RooCBShape CrystalBallSys_m850("CrystalBallSys_m850","Crystal Ball 850 GeV", Mass, RooConst(mean_m850), RooConst(sigma_m850), RooConst(a_m850),RooConst(2));
    RooCBShape CrystalBallSys_m900("CrystalBallSys_m900","Crystal Ball 900 GeV", Mass, RooConst(mean_m900), RooConst(sigma_m900), RooConst(a_m900),RooConst(2));
    RooCBShape CrystalBallSys_m950("CrystalBallSys_m950","Crystal Ball 950 GeV", Mass, RooConst(mean_m950), RooConst(sigma_m950), RooConst(a_m950),RooConst(2));
    RooCBShape CrystalBallSys_m1000("CrystalBallSys_m1000","Crystal Ball 1000 GeV", Mass, RooConst(mean_m1000), RooConst(sigma_m1000), RooConst(a_m1000),RooConst(2));
  
    //cout << "mean_m250   " << mean_m250 << endl;
    //cout << "sigma_m250 " << sigma_m250 << endl;
    //cout << "a_m250     " << a_m200 << endl;
    Fit_sys_frame->GetYaxis()->SetRangeUser(0.00001,0.16);
    Fit_sys_frame->GetYaxis()->SetDrawOption("Logy");
    //--- Remove 200 GeV mass point
    signal_sys_m200.plotOn(Mass_sys_frame,LineColor(2),MarkerColor(2),MarkerSize(1.0));
    CrystalBallSys1.plotOn(Mass_sys_frame,LineColor(2),LineStyle(2)); 
    CrystalBallSys_m200.plotOn(Mass_sys_frame,LineColor(2),LineWidth(3));
    CrystalBallSys1.fillHistogram(Hist_sys_m200,RooArgList(MASS));
    //---
    CrystalBallSys_m250.plotOn(Fit_sys_frame, LineColor(7));  
    CrystalBallSys_m300.plotOn(Fit_sys_frame, LineColor(8));  
    //--- Remove 350 GeV mass point
    signal_sys_m350.plotOn(Mass_sys_frame,LineColor(3),MarkerColor(3));
    CrystalBallSys2.plotOn(Mass_sys_frame,LineColor(3),LineStyle(2)); 
    CrystalBallSys_m350.plotOn(Mass_sys_frame,LineColor(3),LineWidth(3));
    CrystalBallSys2.fillHistogram(Hist_sys_m350,RooArgList(MASS));
    //---
    CrystalBallSys_m400.plotOn(Fit_sys_frame, LineColor(9));  
    CrystalBallSys_m450.plotOn(Fit_sys_frame, LineColor(10));  
    //--- Remove 500 GeV mass point
    signal_sys_m500.plotOn(Mass_sys_frame,LineColor(4),MarkerColor(4));
    CrystalBallSys3.plotOn(Mass_sys_frame,LineColor(4),LineStyle(2)); 
    CrystalBallSys_m500.plotOn(Mass_sys_frame,LineColor(4),LineWidth(3));
    CrystalBallSys_m500.fillHistogram(Hist_sys_m500,RooArgList(MASS));
    //---
    CrystalBallSys_m550.plotOn(Fit_sys_frame, LineColor(11));  
    CrystalBallSys_m600.plotOn(Fit_sys_frame, LineColor(12));  
    CrystalBallSys_m650.plotOn(Fit_sys_frame, LineColor(13));  
    CrystalBallSys_m700.plotOn(Fit_sys_frame, LineColor(14));  
    //--- Remove 750 GeV mass point
    signal_sys_m750.plotOn(Mass_sys_frame,LineColor(5),MarkerColor(5));
    CrystalBallSys4.plotOn(Mass_sys_frame,LineColor(5),LineStyle(2)); 
    CrystalBallSys_m750.plotOn(Mass_sys_frame,LineColor(5),LineWidth(3));
    CrystalBallSys4.fillHistogram(Hist_sys_m750,RooArgList(MASS));
    //---
    CrystalBallSys_m800.plotOn(Fit_sys_frame, LineColor(15));  
    CrystalBallSys_m850.plotOn(Fit_sys_frame, LineColor(16));  
    CrystalBallSys_m900.plotOn(Fit_sys_frame, LineColor(17));  
    CrystalBallSys_m950.plotOn(Fit_sys_frame, LineColor(18));  
    //--- Remove 1000 GeV mass point
    signal_sys_m1000.plotOn(Mass_sys_frame,LineColor(6),MarkerColor(6));
    CrystalBallSys5.plotOn(Mass_sys_frame,LineColor(6),LineStyle(2)); 
    CrystalBallSys_m1000.plotOn(Mass_sys_frame,LineColor(6),LineWidth(3));
    CrystalBallSys5.fillHistogram(Hist_sys_m1000,RooArgList(MASS));
    //---

    Mass_sys_frame->Write("crystal_ball_fits_"+Systematic);
    TH1 * Hist_sys_m250 = MASS.createHistogram("Signal m250", Binning(200)) ;
    TH1 * Hist_sys_m300 = MASS.createHistogram("Signal m300", Binning(200)) ;
    TH1 * Hist_sys_m400 = MASS.createHistogram("Signal m400", Binning(200)) ;
    TH1 * Hist_sys_m450 = MASS.createHistogram("Signal m450", Binning(200)) ;
    TH1 * Hist_sys_m550 = MASS.createHistogram("Signal m550", Binning(200)) ;
    TH1 * Hist_sys_m600 = MASS.createHistogram("Signal m600", Binning(200)) ;
    TH1 * Hist_sys_m650 = MASS.createHistogram("Signal m650", Binning(200)) ;
    TH1 * Hist_sys_m700 = MASS.createHistogram("Signal m700", Binning(200)) ;
    TH1 * Hist_sys_m800 = MASS.createHistogram("Signal m800", Binning(200)) ;
    TH1 * Hist_sys_m850 = MASS.createHistogram("Signal m850", Binning(200)) ;
    TH1 * Hist_sys_m900 = MASS.createHistogram("Signal m900", Binning(200)) ;
    TH1 * Hist_sys_m950 = MASS.createHistogram("Signal m950", Binning(200)) ;
    
    CrystalBallSys_m250.fillHistogram(Hist_sys_m250,RooArgList(MASS));
    CrystalBallSys_m300.fillHistogram(Hist_sys_m300,RooArgList(MASS));
    CrystalBallSys_m400.fillHistogram(Hist_sys_m400,RooArgList(MASS));
    CrystalBallSys_m450.fillHistogram(Hist_sys_m450,RooArgList(MASS));
    CrystalBallSys_m550.fillHistogram(Hist_sys_m550,RooArgList(MASS));
    CrystalBallSys_m600.fillHistogram(Hist_sys_m600,RooArgList(MASS));
    CrystalBallSys_m650.fillHistogram(Hist_sys_m650,RooArgList(MASS));
    CrystalBallSys_m700.fillHistogram(Hist_sys_m700,RooArgList(MASS));
    CrystalBallSys_m800.fillHistogram(Hist_sys_m800,RooArgList(MASS));
    CrystalBallSys_m850.fillHistogram(Hist_sys_m850,RooArgList(MASS));
    CrystalBallSys_m900.fillHistogram(Hist_sys_m900,RooArgList(MASS));
    CrystalBallSys_m950.fillHistogram(Hist_sys_m950,RooArgList(MASS));
  
   Fit_sys_frame->Write("Signal_Templates_"+Systematic);

    TCanvas *c_channel_sys_acc = new TCanvas("c_channel_sys_acc","Acceptances",200,10,500,500);
    Double_t X_axis[5];
    Double_t Y_axis[5];
    X_axis[0] = 200.0;
    X_axis[1] = 350.0;
    X_axis[2] = 500.0;
    X_axis[3] = 750.0;
    X_axis[4] = 1000.0;
    
    cout << "Channel_Acceptance_sys_m200  " << Channel_Acceptance_sys_m200 << endl;
    cout << "Channel_Acceptance_sys_m350  " << Channel_Acceptance_sys_m350 << endl;
    cout << "Channel_Acceptance_sys_m500  " << Channel_Acceptance_sys_m500 << endl;
    cout << "Channel_Acceptance_sys_m750  " << Channel_Acceptance_sys_m750 << endl;
    cout << "Channel_Acceptance_sys_m1000  " << Channel_Acceptance_sys_m1000 << endl;
    cout << "Channel_Acceptance_m750 " << Channel_Acceptance_m750 << endl;
    cout << "Integral_sys_m750[sys] " << Integral_sys_m750[sys] << endl;
    cout << " Integral_m750 " << Integral_m750 << endl;

    Y_axis[0] = Channel_Acceptance_sys_m200;
    Y_axis[1] = Channel_Acceptance_sys_m350;
    Y_axis[2] = Channel_Acceptance_sys_m500;
    Y_axis[3] = Channel_Acceptance_sys_m750;
    Y_axis[4] = Channel_Acceptance_sys_m1000;
    TGraph * Channel_Accept_sys = new TGraph(5,X_axis,Y_axis);
    Channel_Accept_sys->SetTitle("");
    Channel_Accept_sys->GetXaxis()->SetTitle("W' Pole Mass [GeV]");
    Channel_Accept_sys->GetYaxis()->SetTitle("Channel Acceptance");
    Channel_Accept_sys->Draw("AL*");
    TFitResultPtr Channel_acc_sys_result = Channel_Accept_sys->Fit("pol3", "S");
    Double_t chn_acc_sys_p0 = Channel_acc_sys_result->Value(0);
    Double_t chn_acc_sys_p1 = Channel_acc_sys_result->Value(1);
    Double_t chn_acc_sys_p2 = Channel_acc_sys_result->Value(2);
    Double_t chn_acc_sys_p3 = Channel_acc_sys_result->Value(3);
    Channel_Accept_sys->SetLineColor(4);
    Channel_Accept_sys->SetLineWidth(2);
    Channel_Accept_sys->SetMarkerColor(4);
    Channel_Accept_sys->SetMarkerStyle(22);
    c_channel_sys_acc->Write("ChannelAcceptances_Sys");
    
    //cout << "chn_acc_sys_p2  " << chn_acc_sys_p2 << endl;

    Xmass = 250.;  
    Double_t Channel_Acceptance_sys_m250 = chn_acc_sys_p0 + chn_acc_sys_p1*Xmass + chn_acc_sys_p2*Xmass*Xmass + chn_acc_sys_p3*Xmass*Xmass*Xmass;
    Xmass = 300.;
    Double_t Channel_Acceptance_sys_m300 = chn_acc_sys_p0 + chn_acc_sys_p1*Xmass + chn_acc_sys_p2*Xmass*Xmass + chn_acc_sys_p3*Xmass*Xmass*Xmass;
    Xmass = 400.;
    Double_t Channel_Acceptance_sys_m400 = chn_acc_sys_p0 + chn_acc_sys_p1*Xmass + chn_acc_sys_p2*Xmass*Xmass + chn_acc_sys_p3*Xmass*Xmass*Xmass;
    Xmass = 450.;
    Double_t Channel_Acceptance_sys_m450 = chn_acc_sys_p0 + chn_acc_sys_p1*Xmass + chn_acc_sys_p2*Xmass*Xmass + chn_acc_sys_p3*Xmass*Xmass*Xmass;
    Xmass = 550.;
    Double_t Channel_Acceptance_sys_m550 = chn_acc_sys_p0 + chn_acc_sys_p1*Xmass + chn_acc_sys_p2*Xmass*Xmass + chn_acc_sys_p3*Xmass*Xmass*Xmass;
    Xmass = 600.;
    Double_t Channel_Acceptance_sys_m600 = chn_acc_sys_p0 + chn_acc_sys_p1*Xmass + chn_acc_sys_p2*Xmass*Xmass + chn_acc_sys_p3*Xmass*Xmass*Xmass;
    Xmass = 650.;
    Double_t Channel_Acceptance_sys_m650 = chn_acc_sys_p0 + chn_acc_sys_p1*Xmass + chn_acc_sys_p2*Xmass*Xmass + chn_acc_sys_p3*Xmass*Xmass*Xmass;
    Xmass = 700.;
    Double_t Channel_Acceptance_sys_m700 = chn_acc_sys_p0 + chn_acc_sys_p1*Xmass + chn_acc_sys_p2*Xmass*Xmass + chn_acc_sys_p3*Xmass*Xmass*Xmass;
    Xmass = 800.;
    Double_t Channel_Acceptance_sys_m800 = chn_acc_sys_p0 + chn_acc_sys_p1*Xmass + chn_acc_sys_p2*Xmass*Xmass + chn_acc_sys_p3*Xmass*Xmass*Xmass;
    Xmass = 850.;
    Double_t Channel_Acceptance_sys_m850 = chn_acc_sys_p0 + chn_acc_sys_p1*Xmass + chn_acc_sys_p2*Xmass*Xmass + chn_acc_sys_p3*Xmass*Xmass*Xmass;
    Xmass = 900.;
    Double_t Channel_Acceptance_sys_m900 = chn_acc_sys_p0 + chn_acc_sys_p1*Xmass + chn_acc_sys_p2*Xmass*Xmass + chn_acc_sys_p3*Xmass*Xmass*Xmass;
    Xmass = 950.;
    Double_t Channel_Acceptance_sys_m950 = chn_acc_sys_p0 + chn_acc_sys_p1*Xmass + chn_acc_sys_p2*Xmass*Xmass + chn_acc_sys_p3*Xmass*Xmass*Xmass;
    
    //--- Old method
    //Double_t Channel_Acceptance_sys_m250 = Channel_Acceptance_sys_m200 + (Channel_Acceptance_sys_m350-Channel_Acceptance_sys_m200)*1./3.;
    //Double_t Channel_Acceptance_sys_m300 = Channel_Acceptance_sys_m200 + (Channel_Acceptance_sys_m350-Channel_Acceptance_sys_m200)*2./3.;
    //Double_t Channel_Acceptance_sys_m400 = Channel_Acceptance_sys_m350 + (Channel_Acceptance_sys_m500-Channel_Acceptance_sys_m350)*1./3.;
    //Double_t Channel_Acceptance_sys_m450 = Channel_Acceptance_sys_m350 + (Channel_Acceptance_sys_m500-Channel_Acceptance_sys_m350)*2./3.;
    //Double_t Channel_Acceptance_sys_m550 = Channel_Acceptance_sys_m500 + (Channel_Acceptance_sys_m750-Channel_Acceptance_sys_m500)*1./5.;
    //Double_t Channel_Acceptance_sys_m600 = Channel_Acceptance_sys_m500 + (Channel_Acceptance_sys_m750-Channel_Acceptance_sys_m500)*2./5.;
    //Double_t Channel_Acceptance_sys_m650 = Channel_Acceptance_sys_m500 + (Channel_Acceptance_sys_m750-Channel_Acceptance_sys_m500)*3./5.;
    //Double_t Channel_Acceptance_sys_m700 = Channel_Acceptance_sys_m500 + (Channel_Acceptance_sys_m750-Channel_Acceptance_sys_m500)*4./5.;
    //Double_t Channel_Acceptance_sys_m800 = Channel_Acceptance_sys_m750 + (Channel_Acceptance_sys_m1000-Channel_Acceptance_sys_m750)*1./5.;
    //Double_t Channel_Acceptance_sys_m850 = Channel_Acceptance_sys_m750 + (Channel_Acceptance_sys_m1000-Channel_Acceptance_sys_m750)*2./5.;
    //Double_t Channel_Acceptance_sys_m900 = Channel_Acceptance_sys_m750 + (Channel_Acceptance_sys_m1000-Channel_Acceptance_sys_m750)*3./5.;
    //Double_t Channel_Acceptance_sys_m950 = Channel_Acceptance_sys_m750 + (Channel_Acceptance_sys_m1000-Channel_Acceptance_sys_m750)*4./5.;
    //--- 
		 
    Double_t Scale_sys_m200 = Total_Lumi*CrossSection_m200*Channel_Acceptance_sys_m200;
    Double_t Scale_sys_m250 = Total_Lumi*CrossSection_m250*Channel_Acceptance_sys_m250;
    Double_t Scale_sys_m300 = Total_Lumi*CrossSection_m300*Channel_Acceptance_sys_m300;
    Double_t Scale_sys_m350 = Total_Lumi*CrossSection_m350*Channel_Acceptance_sys_m350;
    Double_t Scale_sys_m400 = Total_Lumi*CrossSection_m400*Channel_Acceptance_sys_m400;
    Double_t Scale_sys_m450 = Total_Lumi*CrossSection_m450*Channel_Acceptance_sys_m450;
    Double_t Scale_sys_m500 = Total_Lumi*CrossSection_m500*Channel_Acceptance_sys_m500;
    Double_t Scale_sys_m550 = Total_Lumi*CrossSection_m550*Channel_Acceptance_sys_m550;
    Double_t Scale_sys_m600 = Total_Lumi*CrossSection_m600*Channel_Acceptance_sys_m600;
    Double_t Scale_sys_m650 = Total_Lumi*CrossSection_m650*Channel_Acceptance_sys_m650;
    Double_t Scale_sys_m700 = Total_Lumi*CrossSection_m700*Channel_Acceptance_sys_m700;
    Double_t Scale_sys_m750 = Total_Lumi*CrossSection_m750*Channel_Acceptance_sys_m750;
    Double_t Scale_sys_m800 = Total_Lumi*CrossSection_m800*Channel_Acceptance_sys_m800;
    Double_t Scale_sys_m850 = Total_Lumi*CrossSection_m850*Channel_Acceptance_sys_m850;
    Double_t Scale_sys_m900 = Total_Lumi*CrossSection_m900*Channel_Acceptance_sys_m900;
    Double_t Scale_sys_m950 = Total_Lumi*CrossSection_m950*Channel_Acceptance_sys_m950;
    Double_t Scale_sys_m1000 = Total_Lumi*CrossSection_m1000*Channel_Acceptance_sys_m1000;

    cout << "Scale_sys_m250  " << Scale_sys_m250 << endl;
    cout << "Scale_sys_m300  " << Scale_sys_m300 << endl;
    cout << "Scale_sys_m400  " << Scale_sys_m400 << endl;
    cout << "Scale_sys_m450  " << Scale_sys_m450 << endl;
    
    Hist_sys_m200->Scale(3333*Channel_Acceptance_sys_m200*2);
    Hist_sys_m250->Scale(3333*Channel_Acceptance_sys_m250*2);
    Hist_sys_m300->Scale(3333*Channel_Acceptance_sys_m300*2);
    Hist_sys_m350->Scale(3333*Channel_Acceptance_sys_m350*2);
    Hist_sys_m400->Scale(3333*Channel_Acceptance_sys_m400*2);
    Hist_sys_m450->Scale(3333*Channel_Acceptance_sys_m450*2);
    Hist_sys_m500->Scale(3333*Channel_Acceptance_sys_m500*2);
    Hist_sys_m550->Scale(3333*Channel_Acceptance_sys_m550*2);
    Hist_sys_m600->Scale(3333*Channel_Acceptance_sys_m600*2);
    Hist_sys_m650->Scale(3333*Channel_Acceptance_sys_m650*2);
    Hist_sys_m700->Scale(3333*Channel_Acceptance_sys_m700*2);
    Hist_sys_m750->Scale(3333*Channel_Acceptance_sys_m750*2);
    Hist_sys_m800->Scale(3333*Channel_Acceptance_sys_m800*2);
    Hist_sys_m850->Scale(3333*Channel_Acceptance_sys_m850*2);
    Hist_sys_m900->Scale(3333*Channel_Acceptance_sys_m900*2);
    Hist_sys_m950->Scale(3333*Channel_Acceptance_sys_m950*2);
    Hist_sys_m1000->Scale(3333*Channel_Acceptance_sys_m1000*2);

    for(Int_t bin = 0; bin < total_bins ; bin++){
      if(Hist_sys_m200->GetBinContent(bin) >= 1.0){
	Hist_sys_m200->SetBinError(bin, sqrt(Hist_sys_m200->GetBinContent(bin)));
      }
      if(Hist_sys_m250->GetBinContent(bin) >= 1.0){
	Hist_sys_m250->SetBinError(bin, sqrt(Hist_sys_m250->GetBinContent(bin)));
      }
      if(Hist_sys_m300->GetBinContent(bin) >= 1.0){
	Hist_sys_m300->SetBinError(bin, sqrt(Hist_sys_m300->GetBinContent(bin)));
      }
      if(Hist_sys_m350->GetBinContent(bin) >= 1.0){
	Hist_sys_m350->SetBinError(bin, sqrt(Hist_sys_m350->GetBinContent(bin)));
      }
      if(Hist_sys_m400->GetBinContent(bin) >= 1.0){
	Hist_sys_m400->SetBinError(bin, sqrt(Hist_sys_m400->GetBinContent(bin)));
      }
      if(Hist_sys_m450->GetBinContent(bin) >= 1.0){
	Hist_sys_m450->SetBinError(bin, sqrt(Hist_sys_m450->GetBinContent(bin)));
      }
      if(Hist_sys_m500->GetBinContent(bin) >= 1.0){
	Hist_sys_m500->SetBinError(bin, sqrt(Hist_sys_m500->GetBinContent(bin)));
      }
      if(Hist_sys_m550->GetBinContent(bin) >= 1.0){
	Hist_sys_m550->SetBinError(bin, sqrt(Hist_sys_m550->GetBinContent(bin)));
      }
      if(Hist_sys_m600->GetBinContent(bin) >= 1.0){
	Hist_sys_m600->SetBinError(bin, sqrt(Hist_sys_m600->GetBinContent(bin)));
      }
      if(Hist_sys_m650->GetBinContent(bin) >= 1.0){
	Hist_sys_m650->SetBinError(bin, sqrt(Hist_sys_m650->GetBinContent(bin)));
      }
      if(Hist_sys_m700->GetBinContent(bin) >= 1.0){
	Hist_sys_m700->SetBinError(bin, sqrt(Hist_sys_m700->GetBinContent(bin)));
      }
      if(Hist_sys_m750->GetBinContent(bin) >= 1.0){
	Hist_sys_m750->SetBinError(bin, sqrt(Hist_sys_m750->GetBinContent(bin)));
      }
      if(Hist_sys_m800->GetBinContent(bin) >= 1.0){
	Hist_sys_m800->SetBinError(bin, sqrt(Hist_sys_m800->GetBinContent(bin)));
      }
      if(Hist_sys_m850->GetBinContent(bin) >= 1.0){
	Hist_sys_m850->SetBinError(bin, sqrt(Hist_sys_m850->GetBinContent(bin)));
      }
      if(Hist_sys_m900->GetBinContent(bin) >= 1.0){
	Hist_sys_m900->SetBinError(bin, sqrt(Hist_sys_m900->GetBinContent(bin)));
      }
      if(Hist_sys_m950->GetBinContent(bin) >= 1.0){
	Hist_sys_m950->SetBinError(bin, sqrt(Hist_sys_m950->GetBinContent(bin)));
      }
      if(Hist_sys_m1000->GetBinContent(bin) >= 1.0){
	Hist_sys_m1000->SetBinError(bin, sqrt(Hist_sys_m1000->GetBinContent(bin)));
      }
      
      if(Hist_sys_m200->GetBinContent(bin) < 1.0){
	Hist_sys_m200->SetBinError(bin, Hist_sys_m200->GetBinContent(bin));
      }
      if(Hist_sys_m250->GetBinContent(bin) < 1.0){
	Hist_sys_m250->SetBinError(bin, Hist_sys_m250->GetBinContent(bin));
      }
      if(Hist_sys_m300->GetBinContent(bin) < 1.0){
	Hist_sys_m300->SetBinError(bin, Hist_sys_m300->GetBinContent(bin));
      }
      if(Hist_sys_m350->GetBinContent(bin) < 1.0){
	Hist_sys_m350->SetBinError(bin, Hist_sys_m350->GetBinContent(bin));
      }
      if(Hist_sys_m400->GetBinContent(bin) < 1.0){
	Hist_sys_m400->SetBinError(bin, Hist_sys_m400->GetBinContent(bin));
      }
      if(Hist_sys_m450->GetBinContent(bin) < 1.0){
	Hist_sys_m450->SetBinError(bin, Hist_sys_m450->GetBinContent(bin));
      }
      if(Hist_sys_m500->GetBinContent(bin) < 1.0){
	Hist_sys_m500->SetBinError(bin, Hist_sys_m500->GetBinContent(bin));
      }
      if(Hist_sys_m550->GetBinContent(bin) < 1.0){
	Hist_sys_m550->SetBinError(bin, Hist_sys_m550->GetBinContent(bin));
      }
      if(Hist_sys_m600->GetBinContent(bin) < 1.0){
	Hist_sys_m600->SetBinError(bin, Hist_sys_m600->GetBinContent(bin));
      }
      if(Hist_sys_m650->GetBinContent(bin) < 1.0){
	Hist_sys_m650->SetBinError(bin, Hist_sys_m650->GetBinContent(bin));
      }
      if(Hist_sys_m700->GetBinContent(bin) < 1.0){
	Hist_sys_m700->SetBinError(bin, Hist_sys_m700->GetBinContent(bin));
      }
      if(Hist_sys_m750->GetBinContent(bin) < 1.0){
	Hist_sys_m750->SetBinError(bin, Hist_sys_m750->GetBinContent(bin));
      }
      if(Hist_sys_m800->GetBinContent(bin) < 1.0){
	Hist_sys_m800->SetBinError(bin, Hist_sys_m800->GetBinContent(bin));
      }
      if(Hist_sys_m850->GetBinContent(bin) < 1.0){
	Hist_sys_m850->SetBinError(bin, Hist_sys_m850->GetBinContent(bin));
      }
      if(Hist_sys_m900->GetBinContent(bin) < 1.0){
	Hist_sys_m900->SetBinError(bin, Hist_sys_m900->GetBinContent(bin));
      }
      if(Hist_sys_m950->GetBinContent(bin) < 1.0){
	Hist_sys_m950->SetBinError(bin, Hist_sys_m950->GetBinContent(bin));
      }
      if(Hist_sys_m1000->GetBinContent(bin) < 1.0){
	Hist_sys_m1000->SetBinError(bin, Hist_sys_m1000->GetBinContent(bin));
      }
    }
    
    Hist_sys_m200->Scale(Scale_sys_m200/(3333*Channel_Acceptance_sys_m200*2));
    Hist_sys_m250->Scale(Scale_sys_m250/(3333*Channel_Acceptance_sys_m250*2));
    Hist_sys_m300->Scale(Scale_sys_m300/(3333*Channel_Acceptance_sys_m300*2));
    Hist_sys_m350->Scale(Scale_sys_m350/(3333*Channel_Acceptance_sys_m350*2));
    Hist_sys_m400->Scale(Scale_sys_m400/(3333*Channel_Acceptance_sys_m400*2));
    Hist_sys_m450->Scale(Scale_sys_m450/(3333*Channel_Acceptance_sys_m450*2));
    Hist_sys_m500->Scale(Scale_sys_m500/(3333*Channel_Acceptance_sys_m500*2));
    Hist_sys_m550->Scale(Scale_sys_m550/(3333*Channel_Acceptance_sys_m550*2));
    Hist_sys_m600->Scale(Scale_sys_m600/(3333*Channel_Acceptance_sys_m600*2));
    Hist_sys_m650->Scale(Scale_sys_m650/(3333*Channel_Acceptance_sys_m650*2));
    Hist_sys_m700->Scale(Scale_sys_m700/(3333*Channel_Acceptance_sys_m700*2));
    Hist_sys_m750->Scale(Scale_sys_m750/(3333*Channel_Acceptance_sys_m750*2));
    Hist_sys_m800->Scale(Scale_sys_m800/(3333*Channel_Acceptance_sys_m800*2));
    Hist_sys_m850->Scale(Scale_sys_m850/(3333*Channel_Acceptance_sys_m850*2));
    Hist_sys_m900->Scale(Scale_sys_m900/(3333*Channel_Acceptance_sys_m900*2));
    Hist_sys_m950->Scale(Scale_sys_m950/(3333*Channel_Acceptance_sys_m950*2));
    Hist_sys_m1000->Scale(Scale_sys_m1000/(3333*Channel_Acceptance_sys_m1000*2));

    //Hist_sys_m200->SetBins(nBins, 0., 2000.);
    //Hist_sys_m250->SetBins(nBins, 0., 2000.);
    //Hist_sys_m300->SetBins(nBins, 0., 2000.);
    //Hist_sys_m350->SetBins(nBins, 0., 2000.);
    //Hist_sys_m400->SetBins(nBins, 0., 2000.);
    //Hist_sys_m450->SetBins(nBins, 0., 2000.);
    //Hist_sys_m500->SetBins(nBins, 0., 2000.);
    //Hist_sys_m550->SetBins(nBins, 0., 2000.);
    //Hist_sys_m600->SetBins(nBins, 0., 2000.);
    //Hist_sys_m650->SetBins(nBins, 0., 2000.);
    //Hist_sys_m700->SetBins(nBins, 0., 2000.);
    //Hist_sys_m750->SetBins(nBins, 0., 2000.);
    //Hist_sys_m800->SetBins(nBins, 0., 2000.);
    //Hist_sys_m850->SetBins(nBins, 0., 2000.);
    //Hist_sys_m900->SetBins(nBins, 0., 2000.);
    //Hist_sys_m950->SetBins(nBins, 0., 2000.);
    //Hist_sys_m1000->SetBins(nBins, 0., 2000.);

    Double_t Integral_sys1_m200 = Hist_sys_m200->Integral(0,200);
    Double_t Integral_sys_m250 = Hist_sys_m250->Integral(0,200);
    Double_t Integral_sys_m300 = Hist_sys_m300->Integral(0,200);
    Double_t Integral_sys1_m350 = Hist_sys_m350->Integral(0,200);
    Double_t Integral_sys_m400 = Hist_sys_m400->Integral(0,200);
    Double_t Integral_sys_m450 = Hist_sys_m450->Integral(0,200);
    Double_t Integral_sys1_m500 = Hist_sys_m500->Integral(0,200);
    Double_t Integral_sys_m550 = Hist_sys_m550->Integral(0,200);
    Double_t Integral_sys_m600 = Hist_sys_m600->Integral(0,200);
    Double_t Integral_sys_m650 = Hist_sys_m650->Integral(0,200);
    Double_t Integral_sys_m700 = Hist_sys_m700->Integral(0,200);
    Double_t Integral_sys1_m750 = Hist_sys_m750->Integral(0,200);
    Double_t Integral_sys_m800 = Hist_sys_m800->Integral(0,200);
    Double_t Integral_sys_m850 = Hist_sys_m850->Integral(0,200);
    Double_t Integral_sys_m900 = Hist_sys_m900->Integral(0,200);
    Double_t Integral_sys_m950 = Hist_sys_m950->Integral(0,200);

    cout << "=======================================================" << endl;
    cout << "Integral_sys_m200_"+Systematic+" " << Integral_sys_m200[sys] << Integral_sys1_m200 << endl;   
    cout << "Integral_sys_m250_"+Systematic+" " << Integral_sys_m250 << endl;   
    cout << "Integral_sys_m300_"+Systematic+" " << Integral_sys_m300 << endl;   
    cout << "Integral_sys_m350_"+Systematic+" " << Integral_sys_m350[sys] << Integral_sys1_m350 << endl;   
    cout << "Integral_sys_m400_"+Systematic+" " << Integral_sys_m400 << endl;   
    cout << "Integral_sys_m450_"+Systematic+" " << Integral_sys_m450 << endl;   
    cout << "Integral_sys_m500_"+Systematic+" " << Integral_sys_m500[sys] << " " << Integral_sys1_m500 << endl;   
    cout << "Integral_sys_m550_"+Systematic+" " << Integral_sys_m550 << endl;   
    cout << "Integral_sys_m600_"+Systematic+" " << Integral_sys_m600 << endl;   
    cout << "Integral_sys_m650_"+Systematic+" " << Integral_sys_m650 << endl;   
    cout << "Integral_sys_m700_"+Systematic+" " << Integral_sys_m700 << endl;   
    cout << "Integral_sys_m750_"+Systematic+" " << Integral_sys_m750[sys] << Integral_sys1_m750 << endl;   
    cout << "======================================================" << endl;
    cout << "Channel_Acceptance_sys_m200 "+Systematic+" " << Channel_Acceptance_sys_m200*4 << endl; 
    cout << "Channel_Acceptance_sys_m250 "+Systematic+" " << Channel_Acceptance_sys_m250*4 << endl; 
    cout << "Channel_Acceptance_sys_m300 "+Systematic+" " << Channel_Acceptance_sys_m300*4 << endl; 
    cout << "Channel_Acceptance_sys_m350 "+Systematic+" " << Channel_Acceptance_sys_m350*4 << endl; 
    cout << "Channel_Acceptance_sys_m400 "+Systematic+" " << Channel_Acceptance_sys_m400*4 << endl; 
    cout << "Channel_Acceptance_sys_m450 "+Systematic+" " << Channel_Acceptance_sys_m450*4 << endl; 
    cout << "Channel_Acceptance_sys_m500 "+Systematic+" " << Channel_Acceptance_sys_m500*4 << endl; 
    cout << "Channel_Acceptance_sys_m550 "+Systematic+" " << Channel_Acceptance_sys_m550*4 << endl; 
    cout << "Channel_Acceptance_sys_m600 "+Systematic+" " << Channel_Acceptance_sys_m600*4 << endl; 
    cout << "Channel_Acceptance_sys_m650 "+Systematic+" " << Channel_Acceptance_sys_m650*4 << endl; 
    cout << "Channel_Acceptance_sys_m700 "+Systematic+" " << Channel_Acceptance_sys_m700*4 << endl; 
    cout << "Channel_Acceptance_sys_m750 "+Systematic+" " << Channel_Acceptance_sys_m750*4 << endl; 
    cout << "Channel_Acceptance_sys_m800 "+Systematic+" " << Channel_Acceptance_sys_m800*4 << endl; 
    cout << "Channel_Acceptance_sys_m850 "+Systematic+" " << Channel_Acceptance_sys_m850*4 << endl; 
    cout << "Channel_Acceptance_sys_m900 "+Systematic+" " << Channel_Acceptance_sys_m900*4 << endl; 
    cout << "Channel_Acceptance_sys_m950 "+Systematic+" " << Channel_Acceptance_sys_m950*4 << endl; 
    cout << "Channel_Acceptance_sys_m1000 "+Systematic+" " << Channel_Acceptance_sys_m1000*4 << endl; 
    cout << "=====================================" << endl;

    //COUT;

    /*Hist_sys_m250->Sumw2();
      Hist_sys_m300->Sumw2();
      Hist_sys_m400->Sumw2();
      Hist_sys_m450->Sumw2();
      Hist_sys_m550->Sumw2();
      Hist_sys_m600->Sumw2();
      Hist_sys_m650->Sumw2();
      Hist_sys_m700->Sumw2();
      Hist_sys_m800->Sumw2();
      Hist_sys_m850->Sumw2();
      Hist_sys_m900->Sumw2();
      Hist_sys_m950->Sumw2();*/

    //Hist_sys_m200->Write("wprime_lvll_m200");
    h_sys_m200[sys]->Write("wprime_lvll_m200");
    Hist_sys_m250->Write("wprime_lvll_m250");
    Hist_sys_m300->Write("wprime_lvll_m300");
    //Hist_sys_m350->Write("wprime_lvll_m350");
    h_sys_m350[sys]->Write("wprime_lvll_m350");
    Hist_sys_m400->Write("wprime_lvll_m400");
    Hist_sys_m450->Write("wprime_lvll_m450");
    //Hist_sys_m500->Write("wprime_lvll_m500");
    h_sys_m500[sys]->Write("wprime_lvll_m500");
    Hist_sys_m550->Write("wprime_lvll_m550");
    Hist_sys_m600->Write("wprime_lvll_m600");
    Hist_sys_m650->Write("wprime_lvll_m650");
    Hist_sys_m700->Write("wprime_lvll_m700");
    //Hist_sys_m750->Write("wprime_lvll_m750");
    h_sys_m750[sys]->Write("wprime_lvll_m750");
    Hist_sys_m800->Write("wprime_lvll_m800");
    Hist_sys_m850->Write("wprime_lvll_m850");
    Hist_sys_m900->Write("wprime_lvll_m900");
    Hist_sys_m950->Write("wprime_lvll_m950");
    //Hist_sys_m1000->Write("wprime_lvll_m1000");
    h_sys_m1000[itr]->Write("wprime_lvll_m1000");
//cout << "norm_m200  " << norm_m200 << endl;
    
    CrystalBallSysFits->Close();
    
  return 0;
  
}


