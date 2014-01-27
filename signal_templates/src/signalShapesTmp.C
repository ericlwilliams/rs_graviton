#define signalShapes_cxx
#include "signalShapes.h"

#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <vector>


#include <TROOT.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TGraphErrors.h>
#include <THStack.h>
#include <TMath.h>
#include "TH1.h"
#include "TF1.h"
#include <TFile.h>
#include "../../include/atlasstyle-00-03-04/AtlasStyle.C"
//#include "../../include/atlasstyle-00-03-04/AtlasUtils.C"
//#include "../../include/atlasstyle-00-03-04/AtlasLabels.C"

#include <TFitResultPtr.h>
#include <TFitResult.h>

#include <RooRealVar.h>
#include <RooAddPdf.h>
#include <RooDataSet.h>
#include <RooAbsPdf.h>
#include <RooPlot.h>
#include <RooCBShape.h>
#include <RooDataHist.h>
#include <RooConstVar.h>

using namespace RooFit;

const int NGmass  = 31;
int GmassInt[NGmass] =
  {500,550,600,650,700,750,800,850,900,950,1000,
   1050,1100,1150,1200,1250,1300,1350,1400,1450,
   1500,1550,1600,1650,1700,1750,1800,1850,1900,1950,2000};
string file_loc = "/Users/elw/analy/lvjj/plots/systematics_plots/merged/";

signalShapes::signalShapes(){

  SetAtlasStyle();
  gROOT->SetBatch();
  //gSystem->Load("libRooFit");
}


void signalShapes::makeSignalParameterFits(string channel/*="evjj"*/,string cur_sys/*="jes_nom"*/){
  //gROOT->SetBatch();
  const int n_sig_masses=5;
  double initial_mass1 = 500.0; 
  double initial_mass2 = 750.0; 
  double initial_mass3 = 1000.0; 
  double initial_mass4 = 1250.0; 
  double initial_mass5 = 1500.0; 

  double a_initial1 = 1.;//initial_mass1/1.1;
  double a_initial2 = 1.;//initial_mass2//1.1;
  double a_initial3 = 1.;//initial_mass3/1.1;
  double a_initial4 = 1.;//initial_mass4/1.1;
  double a_initial5 = 1.;//initial_mass5/1.1;

  
  int signal_masses_int[n_sig_masses] = {500,750,1000,1250,1500};
  double signal_masses[n_sig_masses] = {500,750,1000,1250,1500};
  string signal_file_name = file_loc+"mc.gww.lvjj.m%i.kmpl0_1.systematics.plot.root";


  string signal_hist = (channel=="evjj") ?
    "h_el_"+cur_sys+"_highm_lep_nu_dijet_m" :
    "h_mu_"+cur_sys+"_highm_lep_nu_dijet_m";
  
  TH1F* h_signal_hist[n_sig_masses];
  for(int i=0;i<n_sig_masses;i++){
    string cur_signal_file = Form(signal_file_name.c_str(),signal_masses_int[i]);
    TFile* cur_file = TFile::Open(cur_signal_file.c_str());

    TH1F* cur_hist = (TH1F*) cur_file->Get(signal_hist.c_str());
    cur_hist->SetDirectory(0);
    cur_file->Close();

    h_signal_hist[i] = (TH1F*) cur_hist->Clone();
  }


  
  // --- Normalization ---
  Double_t Total_Lumi = 4703.1; // pb-1
  double cross_section[n_sig_masses];
  cross_section[0] = 5.56 ; //pb  
  cross_section[1] = 0.56;  
  cross_section[2] = 0.1;  
  cross_section[3] = 0.026;  
  cross_section[4] = 0.0074;  

  Double_t CrossSection_m500 = cross_section[0];
  Double_t CrossSection_m550 = 3.3;
  Double_t CrossSection_m600 = 2.0;
  Double_t CrossSection_m650 = 1.3;
  Double_t CrossSection_m700 = 0.84;
  Double_t CrossSection_m750 = cross_section[1];
  Double_t CrossSection_m800 = 0.39;
  Double_t CrossSection_m850 = 0.27;
  Double_t CrossSection_m900 = 0.19;
  Double_t CrossSection_m950 = 0.14;
  Double_t CrossSection_m1000 = cross_section[2];
  Double_t CrossSection_m1050 = 0.078;
  Double_t CrossSection_m1100 = 0.058;
  Double_t CrossSection_m1150 = 0.044;
  Double_t CrossSection_m1200 = 0.034;
  Double_t CrossSection_m1250 = cross_section[3];
  Double_t CrossSection_m1300 = 0.02;
  Double_t CrossSection_m1350 = 0.016;
  Double_t CrossSection_m1400 = 0.012;
  Double_t CrossSection_m1450 = 0.0095;
  Double_t CrossSection_m1500 = cross_section[4];
  Double_t CrossSection_m1550 = 0.004316;
  Double_t CrossSection_m1600 = 0.003523;
  Double_t CrossSection_m1650 = 0.00298;
  Double_t CrossSection_m1700 = 0.002398;
  Double_t CrossSection_m1750 = 0.002033;
  Double_t CrossSection_m1800 = 0.001725;
  Double_t CrossSection_m1850 = 0.001365;
  Double_t CrossSection_m1900 = 0.001118;
  Double_t CrossSection_m1950 = 0.0009884;
  Double_t CrossSection_m2000 = 0.0008129;
  

  for(int j=0;j<n_sig_masses;j++)
    h_signal_hist[j]->SetDirectory(gDirectory);
  
  // --- Observable ---
  RooRealVar Mass("Mass","Mass(lvjj) (GeV)",0,2000);
  //RooPlot * Fitframe = Mass.frame(); 
  RooPlot * m500frame = Mass.frame(200,800);
  RooPlot * m750frame = Mass.frame(400,1200);
  RooPlot * m1000frame = Mass.frame(400,1600);
  RooPlot * m1250frame = Mass.frame(400,2000);
  RooPlot * m1500frame = Mass.frame(600,2000);

    
  // --- Defining Variables in Crystal Ball --- 
  RooRealVar cb_mean1("cb_mean1","Mean of the Gaussian half of the Crystal Ball", initial_mass1, 0, 1000);
  RooRealVar cb_sigma1("cb_sigma1","Sigma of the Gaussian half of the Crystal Ball", 35.0, 15.0, 100.0);
  RooRealVar cb_a1("cb_a1","Delimiting Value", 1., 0.01, 50.0);
  RooRealVar cb_n1("cb_n1","Exponentiating Form", 2.0);//, 0.001, 100.0);
  RooRealVar cb_mean2("cb_mean2","Mean of the Gaussian half of the Crystal Ball",initial_mass2, 250, 1250);
  RooRealVar cb_sigma2("cb_sigma2","Sigma of the Gaussian half of the Crystal Ball", 40.0, 0.1, 100.0);
  RooRealVar cb_a2("cb_a2","Delimiting Value", 1.0, 0.01, 50.0);
  RooRealVar cb_n2("cb_n2","Exponentiating Form", 2.0);//, 0.001, 100.0);
  
  RooRealVar cb_mean3("cb_mean3","Mean of the Gaussian half of the Crystal Ball",initial_mass3,500, 1500);
  RooRealVar cb_sigma3("cb_sigma3","Sigma of the Gaussian half of the Crystal Ball", 70.0, 0.1, 140.0);
  RooRealVar cb_a3("cb_a3","Delimiting Value", 1.0, 0.01, 50.0);
  RooRealVar cb_n3("cb_n3","Exponentiating Form", 2.0);//, 0.001, 100.0);

  RooRealVar cb_mean4("cb_mean4","Mean of the Gaussian half of the Crystal Ball",initial_mass4, 750, 1750);
 RooRealVar cb_sigma4("cb_sigma4","Sigma of the Gaussian half of the Crystal Ball", 90.0, 0.1, 180.0);
 RooRealVar cb_a4("cb_a4","Delimiting Value", 1.0, 0.01, 50.0);
  RooRealVar cb_n4("cb_n4","Exponentiating Form", 2.0);//, 0.001, 100.0);

  RooRealVar cb_mean5("cb_mean5","Mean of the Gaussian half of the Crystal Ball",initial_mass5, 1000, 2000);
  RooRealVar cb_sigma5("cb_sigma5","Sigma of the Gaussian half of the Crystal Ball", 150.0, 0.1, 300.0);
  RooRealVar cb_a5("cb_a5","Delimiting Value", 1.0, 0.01, 50.0);
  RooRealVar cb_n5("cb_n5","Exponentiating Form", 2.0);//, 0.001, 100.0);
    
  // --- Defining the fit function, i.e. The Crystal Ball
  RooCBShape CrystalBall1("CrystalBall1","Crystal Ball Fit to Signal Resonance",Mass,cb_mean1,cb_sigma1,cb_a1,cb_n1);
  RooCBShape CrystalBall2("CrystalBall2","Crystal Ball Fit to Signal Resonance",Mass,cb_mean2,cb_sigma2,cb_a2,cb_n2);
  RooCBShape CrystalBall3("CrystalBall3","Crystal Ball Fit to Signal Resonance",Mass,cb_mean3,cb_sigma3,cb_a3,cb_n3);
  RooCBShape CrystalBall4("CrystalBall4","Crystal Ball Fit to Signal Resonance",Mass,cb_mean4,cb_sigma4,cb_a4,cb_n4);
  RooCBShape CrystalBall5("CrystalBall5","Crystal Ball Fit to Signal Resonance",Mass,cb_mean5,cb_sigma5,cb_a5,cb_n5);

  // RooRealVar gaus_mean1("gaus_mean1","Mean of the Gaussian half of the Crystal Ball", initial_mass1, 0, 2000);
  // RooRealVar gaus_sigma1("gaus_sigma1","Sigma of the Gaussian half of the Crystal Ball", 70.0, 0.1, 500.0);
  // RooRealVar gaus_mean2("gaus_mean2","Mean of the Gaussian half of the Crystal Ball",initial_mass2, 0, 2000);
  // RooRealVar gaus_sigma2("gaus_sigma2","Sigma of the Gaussian half of the Crystal Ball", 80.0, 0.1, 500.0);
  // RooRealVar gaus_mean3("gaus_mean3","Mean of the Gaussian half of the Crystal Ball",initial_mass3, 0, 2000);
  // RooRealVar gaus_sigma3("gaus_sigma3","Sigma of the Gaussian half of the Crystal Ball", 90.0, 0.1, 500.0);
  // RooRealVar gaus_mean4("gaus_mean4","Mean of the Gaussian half of the Crystal Ball",initial_mass4, 0, 2000);
  // RooRealVar gaus_sigma4("gaus_sigma4","Sigma of the Gaussian half of the Crystal Ball", 120.0, 0.1, 500.0);
  // RooRealVar gaus_mean5("gaus_mean5","Mean of the Gaussian half of the Crystal Ball",initial_mass5, 0, 2000);
  // RooRealVar gaus_sigma5("gaus_sigma5","Sigma of the Gaussian half of the Crystal Ball", 140.0, 0.1, 500.0);


  // RooGaussian GausTest1("GausTest1","Gaus fit",Mass,gaus_mean1,gaus_sigma1);
  // RooGaussian GausTest2("GausTest2","Gaus fit",Mass,gaus_mean2,gaus_sigma2);
  // RooGaussian GausTest3("GausTest","Gaus fit",Mass,gaus_mean3,gaus_sigma3);
  // RooGaussian GausTest4("GausTest","Gaus fit",Mass,gaus_mean4,gaus_sigma4);
  // RooGaussian GausTest5("GausTest","Gaus fit",Mass,gaus_mean5,gaus_sigma5);

  // RooRealVar bw_mean1("bw_mean1","Mean of the Gaussian half of the Crystal Ball", initial_mass1, 0, 2000);
  // RooRealVar bw_sigma1("bw_sigma1","Sigma of the Gaussian half of the Crystal Ball", 35.0, 15.0, 500.0);
  // RooRealVar bw_mean2("bw_mean2","Mean of the Gaussian half of the Crystal Ball",initial_mass2, 0, 2000);
  // RooRealVar bw_sigma2("bw_sigma2","Sigma of the Gaussian half of the Crystal Ball", 40.0, 0.1, 500.0);
  // RooRealVar bw_mean3("bw_mean3","Mean of the Gaussian half of the Crystal Ball",initial_mass3, 0, 2000);
  // RooRealVar bw_sigma3("bw_sigma3","Sigma of the Gaussian half of the Crystal Ball", 70.0, 0.1, 500.0);
  // RooRealVar bw_mean4("bw_mean4","Mean of the Gaussian half of the Crystal Ball",initial_mass4, 0, 2000);
  // RooRealVar bw_sigma4("bw_sigma4","Sigma of the Gaussian half of the Crystal Ball", 60.0, 0.1, 500.0);
  // RooRealVar bw_mean5("bw_mean5","Mean of the Gaussian half of the Crystal Ball",initial_mass5, 0, 2000);
  // RooRealVar bw_sigma5("bw_sigma5","Sigma of the Gaussian half of the Crystal Ball", 70.0, 0.1, 500.0);


  // RooBreitWigner BWTest1("BWTest1","BW fit",Mass,bw_mean1,bw_sigma1);
  // RooBreitWigner BWTest2("BWTest2","BW fit",Mass,bw_mean2,bw_sigma2);
  // RooBreitWigner BWTest3("BWTest","BW fit",Mass,bw_mean3,bw_sigma3);
  // RooBreitWigner BWTest4("BWTest","BW fit",Mass,bw_mean4,bw_sigma4);
  // RooBreitWigner BWTest5("BWTest","BW fit",Mass,bw_mean5,bw_sigma5);

  
  //Total number of events in channel
  Double_t Total_Channel_m500 = 0;
  Double_t Total_Channel_m750 = 0;
  Double_t Total_Channel_m1000 = 0;
  Double_t Total_Channel_m1250 = 0;
  Double_t Total_Channel_m1500 = 0;

  double signal_evt_n = 30000;
  Double_t Acceptance_m500 = h_signal_hist[0]->GetEntries()/signal_evt_n;
  Double_t Acceptance_m750 = h_signal_hist[1]->GetEntries()/signal_evt_n;   
  Double_t Acceptance_m1000 = h_signal_hist[2]->GetEntries()/signal_evt_n;   
  Double_t Acceptance_m1250 = h_signal_hist[3]->GetEntries()/signal_evt_n;   
  Double_t Acceptance_m1500 = h_signal_hist[4]->GetEntries()/signal_evt_n;

  Double_t Integral_m500 = h_signal_hist[0]->Integral();
  Double_t Integral_m750 = h_signal_hist[1]->Integral();   
  Double_t Integral_m1000 = h_signal_hist[2]->Integral();   
  Double_t Integral_m1250 = h_signal_hist[3]->Integral();   
  Double_t Integral_m1500 = h_signal_hist[4]->Integral();

  
  Total_Channel_m500 = Total_Lumi*cross_section[0]*Acceptance_m500;
  Total_Channel_m750 = Total_Lumi*cross_section[1]*Acceptance_m750;
  Total_Channel_m1000 = Total_Lumi*cross_section[2]*Acceptance_m1000;
  Total_Channel_m1250 = Total_Lumi*cross_section[3]*Acceptance_m1250;
  Total_Channel_m1500 = Total_Lumi*cross_section[4]*Acceptance_m1500;

  // --- Define Channel Acceptance --- 
  Double_t Channel_Acceptance_m500 = Acceptance_m500*(Integral_m500/Total_Channel_m500);
  Double_t Channel_Acceptance_m750 = Acceptance_m750*(Integral_m750/Total_Channel_m750);
  Double_t Channel_Acceptance_m1000 = Acceptance_m1000*(Integral_m1000/Total_Channel_m1000);
  Double_t Channel_Acceptance_m1250 = Acceptance_m1250*(Integral_m1250/Total_Channel_m1250);
  Double_t Channel_Acceptance_m1500 = Acceptance_m1500*(Integral_m1500/Total_Channel_m1500);
  string out_file_loc = "../files/"+channel+"_cb_"+cur_sys+"_lep_nu_dijet_m.root";
  TFile* CrystalBallFits = new TFile(out_file_loc.c_str(), "RECREATE");
  CrystalBallFits->cd();

  RooDataHist signal_m500("signal_m500","W' signal", Mass, h_signal_hist[0]);
  RooDataHist signal_m750("signal_m750","W' signal", Mass, h_signal_hist[1]);
  RooDataHist signal_m1000("signal_m1000","W' signal", Mass, h_signal_hist[2]);
  RooDataHist signal_m1250("signal_m1250","W' signal", Mass, h_signal_hist[3]);
  RooDataHist signal_m1500("signal_m1500","W' signal", Mass, h_signal_hist[4]);


  // --- Fitting CrystalBall to Signal Shape ---
  RooRealVar MASS("Mass","Mass(lvjj) (GeV)", 0., 2000.);

  string hist_name = channel+"_"+cur_sys+"_";
  TH1 * Hist_m500 = MASS.createHistogram("Signal m500", Binning(200));
  //string hist_m500_name = hist_name+"m500_cb_lep_nu_dijet_m";
  string hist_m500_name = "cb_rsg_m500_kMpl0_1";
  Hist_m500->SetName(hist_m500_name.c_str());
  TH1 * Hist_m750 = MASS.createHistogram("Signal m750", Binning(200));
  //string hist_m750_name = hist_name+"m750_cb_lep_nu_dijet_m";
  string hist_m750_name = "cb_rsg_m750_kMpl0_1";
  Hist_m750->SetName(hist_m750_name.c_str());
  TH1 * Hist_m1000 = MASS.createHistogram("Signal m1000", Binning(200));
  //string hist_m1000_name = hist_name+"m1000_cb_lep_nu_dijet_m";
  string hist_m1000_name = "cb_rsg_m1000_kMpl0_1";
  Hist_m1000->SetName(hist_m1000_name.c_str());
  TH1 * Hist_m1250 = MASS.createHistogram("Signal m1250", Binning(200));
  //string hist_m1250_name = hist_name+"m1250_cb_lep_nu_dijet_m";
  string hist_m1250_name = "cb_rsg_m1250_kMpl0_1";
  Hist_m1250->SetName(hist_m1250_name.c_str());
  TH1 * Hist_m1500 = MASS.createHistogram("Signal m1500", Binning(200));
  //string hist_m1500_name = hist_name+"m1500_cb_lep_nu_dijet_m";
  string hist_m1500_name = "cb_rsg_m1500_kMpl0_1";
  Hist_m1500->SetName(hist_m1500_name.c_str());

  
  CrystalBall1.fitTo(signal_m500,Range(425,650));//650
  CrystalBall1.fillHistogram(Hist_m500,RooArgList(MASS));
  //BWTest1.fitTo(signal_m500,Range(400,650));
  //GausTest1.fitTo(signal_m500,Range(400,650));
  
  CrystalBall2.fitTo(signal_m750,Range(550,900));
  CrystalBall2.fillHistogram(Hist_m750,RooArgList(MASS));
  //GausTest2.fitTo(signal_m750,Range(600,900));
  //BWTest2.fitTo(signal_m750,Range(600,900));

  CrystalBall3.fitTo(signal_m1000,Range(600,1200));
  CrystalBall3.fillHistogram(Hist_m1000,RooArgList(MASS));
  //GausTest3.fitTo(signal_m1000,Range(700,1200));
  //BWTest3.fitTo(signal_m1000,Range(700,1200));

 
  CrystalBall4.fitTo(signal_m1250,Range(800,1500));
  CrystalBall4.fillHistogram(Hist_m1250,RooArgList(MASS));
  //GausTest4.fitTo(signal_m1250,Range(800,1500));
  //BWTest4.fitTo(signal_m1250,Range(800,1500));


  CrystalBall5.fitTo(signal_m1500,Range(900,1800));
  CrystalBall5.fillHistogram(Hist_m1500,RooArgList(MASS));
  //GausTest5.fitTo(signal_m1500,Range(700,1800));
  //BWTest5.fitTo(signal_m1500,Range(700,1800));

  
  Double_t x[n_sig_masses];
  x[0] = 500.0;
  x[1] = 750.0;
  x[2] = 1000.0;
  x[3] = 1250.0;
  x[4] = 1500.0;

  Double_t Y[n_sig_masses];
  Y[0] = Acceptance_m500;
  Y[1] = Acceptance_m750;
  Y[2] = Acceptance_m1000;
  Y[3] = Acceptance_m1250;
  Y[4] = Acceptance_m1500;

  TCanvas *c_acc = new TCanvas("c_acc","Acceptances",200,10,500,500);
  TGraph * Accept = new TGraph(n_sig_masses,x,Y);
  Accept->SetTitle("");
  Accept->GetXaxis()->SetTitle("W' Pole Mass [GeV]");
  Accept->GetYaxis()->SetTitle("Total Acceptance");
  Accept->Draw("AL*");
  Accept->SetLineColor(4);
  Accept->SetLineWidth(2);
  Accept->SetMarkerColor(4);
  Accept->SetMarkerStyle(22);
  string acc_saveas = "../plots/"+channel+"_"+cur_sys+"_signal_acceptances.pdf";
  c_acc->SaveAs(acc_saveas.c_str());
  

  Y[0] = Channel_Acceptance_m500;
  Y[1] = Channel_Acceptance_m750;
  Y[2] = Channel_Acceptance_m1000;
  Y[3] = Channel_Acceptance_m1250;
  Y[4] = Channel_Acceptance_m1500;

  TCanvas *c_chan_acc = new TCanvas("c_chan_acc","Channel Acceptances",200,10,500,500);
  TGraph * Channel_Accept = new TGraph(n_sig_masses,x,Y);

  // TF1* f1_landau = new TF1("f1_landau","TMath::Landau(x,[0],[1],0)",400,1600);
  // f1_landau->SetParameter(0,850);
  // f1_landau->SetParameter(1,150);
  TF1* f1_landau = new TF1("f1_landau","landau",400,1600);
  f1_landau->SetParameter(0,1);
  f1_landau->SetParameter(1,850);
  f1_landau->SetParameter(2,150);

  TFitResultPtr Channel_acc_result = Channel_Accept->Fit(f1_landau, "S");
  //TFitResultPtr Channel_acc_result = Channel_Accept->Fit("pol3", "S");
  Double_t chn_acc_n = Channel_acc_result->Value(0);
  Double_t chn_acc_mpv = Channel_acc_result->Value(1);
  Double_t chn_acc_sig = Channel_acc_result->Value(2);
   

  Channel_Accept->SetTitle("");
  Channel_Accept->GetXaxis()->SetTitle("W' Pole Mass [GeV]");
  Channel_Accept->GetYaxis()->SetTitle("Acceptance");
  Channel_Accept->Draw("A*");
  Channel_Accept->SetLineColor(4);
  Channel_Accept->SetLineWidth(2);
  Channel_Accept->SetMarkerColor(4);
  Channel_Accept->SetMarkerStyle(22);
  string chan_acc_saveas = "../plots/"+channel+"_"+cur_sys+"_signal_channel_acceptances.pdf";
  c_chan_acc->SaveAs(chan_acc_saveas.c_str());

  Double_t Mean[n_sig_masses]={0.};
  Double_t Sigma[n_sig_masses]={0.};
  Double_t A[n_sig_masses]={0.};
  Double_t N[n_sig_masses]={0.};

  Mean[0] = cb_mean1.getVal();
  Mean[1] = cb_mean2.getVal();
  Mean[2] = cb_mean3.getVal();
  Mean[3] = cb_mean4.getVal();
  Mean[4] = cb_mean5.getVal();
  //cout << "Mean[0] " << Mean[0] << endl;

  Sigma[0] = cb_sigma1.getVal();
  Sigma[1] = cb_sigma2.getVal();
  Sigma[2] = cb_sigma3.getVal();
  Sigma[3] = cb_sigma4.getVal();
  Sigma[4] = cb_sigma5.getVal();
  //cout << "Sigma[0] " << Sigma[0] << endl;

  A[0] = cb_a1.getVal();
  A[1] = cb_a2.getVal();
  A[2] = cb_a3.getVal();
  A[3] = cb_a4.getVal();
  A[4] = cb_a5.getVal();
  // cout << "A[0] " << A[0] << ", "<<cb_a1.getVal()<<endl;
  // cout << "A[1] " << A[1] << ", "<<cb_a2.getVal()<<endl;
  
  N[0] = cb_n1.getVal();
  N[1] = cb_n2.getVal();
  N[2] = cb_n3.getVal();
  N[3] = cb_n4.getVal();
  N[4] = cb_n5.getVal();
  //cout << "N[0] " << N[0] << endl;

  Double_t xx[n_sig_masses]; 
  xx[0] = 500.;
  xx[1] = 750.;
  xx[2] = 1000.;
  xx[3] = 1250.;
  xx[4] = 1500.;

  TGraph * gr_parameter_Mean = new TGraph(n_sig_masses,xx,Mean);
  TGraph * gr_parameter_Sigma = new TGraph(n_sig_masses,xx,Sigma);
  TGraph * gr_parameter_A = new TGraph(n_sig_masses,xx,A);
  TGraph * gr_parameter_N = new TGraph(n_sig_masses,xx,N);

  // TF1 * sigma_fit = new TF1("sigma_fit", "[0]*sqrt([1]*(x-[2]))");
  // sigma_fit->SetParameter(0,1);
  // sigma_fit->SetParameter(1,1);
  // sigma_fit->SetParameter(2,0);

  TF1 * sigma_fit = new TF1("sigma_fit", "[0]+[1]*x");
  sigma_fit->SetParameter(0,0);
  sigma_fit->SetParameter(1,0.1);

  TF1 * mean_fit = new TF1("mean_fit", "[0]+[1]*x");
  mean_fit->SetParameter(0,0);
  mean_fit->SetParameter(1,1);


  TF1 * n_fit = new TF1("n_fit", "[0]+[1]*x");
  mean_fit->SetParameter(0,2);
  mean_fit->SetParameter(1,0);


  TF1 * a_fit = new TF1("a_fit", "[0]/([1]*x^2)+[2]*x");
  //TF1 * a_fit = new TF1("a_fit", "[0]*exp(-1.*[1]*x)+[2]");
  a_fit->SetParameter(0,1);
  a_fit->SetParameter(1,1);
  a_fit->SetParameter(2,1);

  //TFitResultPtr MEAN = gr_parameter_Mean->Fit("pol1", "S");
  TFitResultPtr MEAN = gr_parameter_Mean->Fit("mean_fit", "S");
  TFitResultPtr SIGMA = gr_parameter_Sigma->Fit("sigma_fit", "S");
  //TFitResultPtr SIGMA = gr_parameter_Sigma->Fit("pol1", "S");
  TFitResultPtr A_res = gr_parameter_A->Fit("a_fit", "S");
  //TFitResultPtr N_res =  gr_parameter_N->Fit("pol1", "S");
  TFitResultPtr N_res =  gr_parameter_N->Fit("n_fit", "S");
  

  // --- Get Fit Parameter Values --- 
  //p0 + p1*x
  double mean_p0 = MEAN->Value(0);
  double mean_p1 = MEAN->Value(1);
  //p0*sqrt(p1*(x - p2))
  double sigma_p0 = SIGMA->Value(0); 
  double sigma_p1 = SIGMA->Value(1); 
  //double sigma_p2 = SIGMA->Value(2);
  // p0/p1*x 
  double a_res_p0 = A_res->Value(0); 
  double a_res_p1 = A_res->Value(1); 
  double a_res_p2 = A_res->Value(2); 

  // --- Get Function Values for different points --- 
  
  Double_t mass;
  const int n_template_masses=31;
  double template_masses[n_template_masses] =
    {500,550,600,650,700,750,800,850,900,950,1000,
     1050,1100,1150,1200,1250,1300,1350,1400,1450,
     1500,1550,1600,1650,1700,1750,1800,1850,1900,1950,2000};


  Double_t mean_template[n_template_masses]={0.};
  Double_t sigma_template[n_template_masses]={0.};
  Double_t a_template[n_template_masses]={0.};

  for(int i=0;i<n_template_masses;i++){
    mass = template_masses[i];
    mean_template[i]=(mean_p0 + mean_p1*mass);
    sigma_template[i]=(sigma_p0 + sigma_p1*mass);
    a_template[i]= (a_res_p0/(a_res_p1*(mass*mass)) + a_res_p2*mass);

  }
  
  //M1500
  // mass = 1500.0;
  // Double_t mean_m1500 = 
  // Double_t sigma_m1500 = (sigma_p0 + sigma_p1*mass); 
  // //Double_t sigma_m1500 = sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
  // Double_t a_m1500 = a_res_p0/(a_res_p1*mass) + a_res_p2*mass;


  // --- Define new Crystal Ball shapes for different mass points ---
  RooCBShape CrystalBall_m500("CrystalBall_m500","Crystal Ball 500 GeV", Mass, RooConst(mean_template[0]), RooConst(sigma_template[0]), RooConst(a_template[0]),RooConst(2));
  RooCBShape CrystalBall_m550("CrystalBall_m550","Crystal Ball 550 GeV", Mass, RooConst(mean_template[1]), RooConst(sigma_template[1]), RooConst(a_template[1]),RooConst(2));
  RooCBShape CrystalBall_m600("CrystalBall_m600","Crystal Ball 600 GeV", Mass, RooConst(mean_template[2]), RooConst(sigma_template[2]), RooConst(a_template[2]),RooConst(2));
  RooCBShape CrystalBall_m650("CrystalBall_m650","Crystal Ball 650 GeV", Mass, RooConst(mean_template[3]), RooConst(sigma_template[3]), RooConst(a_template[3]),RooConst(2));
  RooCBShape CrystalBall_m700("CrystalBall_m700","Crystal Ball 700 GeV", Mass, RooConst(mean_template[4]), RooConst(sigma_template[4]), RooConst(a_template[4]),RooConst(2));
  RooCBShape CrystalBall_m750("CrystalBall_m750","Crystal Ball 750 GeV", Mass, RooConst(mean_template[5]), RooConst(sigma_template[5]), RooConst(a_template[5]),RooConst(2));
  RooCBShape CrystalBall_m800("CrystalBall_m800","Crystal Ball 800 GeV", Mass, RooConst(mean_template[6]), RooConst(sigma_template[6]), RooConst(a_template[6]),RooConst(2));
  RooCBShape CrystalBall_m850("CrystalBall_m850","Crystal Ball 850 GeV", Mass, RooConst(mean_template[7]), RooConst(sigma_template[7]), RooConst(a_template[7]),RooConst(2));
  RooCBShape CrystalBall_m900("CrystalBall_m900","Crystal Ball 900 GeV", Mass, RooConst(mean_template[8]), RooConst(sigma_template[8]), RooConst(a_template[8]),RooConst(2));
  RooCBShape CrystalBall_m950("CrystalBall_m950","Crystal Ball 950 GeV", Mass, RooConst(mean_template[9]), RooConst(sigma_template[9]), RooConst(a_template[9]),RooConst(2));
  RooCBShape CrystalBall_m1000("CrystalBall_m1000","Crystal Ball 1000 GeV", Mass, RooConst(mean_template[10]), RooConst(sigma_template[10]), RooConst(a_template[10]),RooConst(2));
  RooCBShape CrystalBall_m1050("CrystalBall_m1050","Crystal Ball 1050 GeV", Mass, RooConst(mean_template[11]), RooConst(sigma_template[11]), RooConst(a_template[11]),RooConst(2));
  RooCBShape CrystalBall_m1100("CrystalBall_m1100","Crystal Ball 1100 GeV", Mass, RooConst(mean_template[12]), RooConst(sigma_template[12]), RooConst(a_template[12]),RooConst(2));
  RooCBShape CrystalBall_m1150("CrystalBall_m1150","Crystal Ball 1150 GeV", Mass, RooConst(mean_template[13]), RooConst(sigma_template[13]), RooConst(a_template[13]),RooConst(2));
  RooCBShape CrystalBall_m1200("CrystalBall_m1200","Crystal Ball 1200 GeV", Mass, RooConst(mean_template[14]), RooConst(sigma_template[14]), RooConst(a_template[14]),RooConst(2));
  RooCBShape CrystalBall_m1250("CrystalBall_m1250","Crystal Ball 1250 GeV", Mass, RooConst(mean_template[15]), RooConst(sigma_template[15]), RooConst(a_template[15]),RooConst(2));
  RooCBShape CrystalBall_m1300("CrystalBall_m1300","Crystal Ball 1300 GeV", Mass, RooConst(mean_template[16]), RooConst(sigma_template[16]), RooConst(a_template[16]),RooConst(2));
  RooCBShape CrystalBall_m1350("CrystalBall_m1350","Crystal Ball 1350 GeV", Mass, RooConst(mean_template[17]), RooConst(sigma_template[17]), RooConst(a_template[17]),RooConst(2));
  RooCBShape CrystalBall_m1400("CrystalBall_m1400","Crystal Ball 1400 GeV", Mass, RooConst(mean_template[18]), RooConst(sigma_template[18]), RooConst(a_template[18]),RooConst(2));
  RooCBShape CrystalBall_m1450("CrystalBall_m1450","Crystal Ball 1450 GeV", Mass, RooConst(mean_template[19]), RooConst(sigma_template[19]), RooConst(a_template[19]),RooConst(2));
  RooCBShape CrystalBall_m1500("CrystalBall_m1500","Crystal Ball 1500 GeV", Mass, RooConst(mean_template[20]), RooConst(sigma_template[20]), RooConst(a_template[20]),RooConst(2));
  RooCBShape CrystalBall_m1550("CrystalBall_m1550","Crystal Ball 1550 GeV", Mass, RooConst(mean_template[21]), RooConst(sigma_template[21]), RooConst(a_template[21]),RooConst(2));
  RooCBShape CrystalBall_m1600("CrystalBall_m1600","Crystal Ball 1600 GeV", Mass, RooConst(mean_template[22]), RooConst(sigma_template[22]), RooConst(a_template[22]),RooConst(2));
  RooCBShape CrystalBall_m1650("CrystalBall_m1650","Crystal Ball 1650 GeV", Mass, RooConst(mean_template[23]), RooConst(sigma_template[23]), RooConst(a_template[23]),RooConst(2));
  RooCBShape CrystalBall_m1700("CrystalBall_m1700","Crystal Ball 1700 GeV", Mass, RooConst(mean_template[24]), RooConst(sigma_template[24]), RooConst(a_template[24]),RooConst(2));
  RooCBShape CrystalBall_m1750("CrystalBall_m1750","Crystal Ball 1750 GeV", Mass, RooConst(mean_template[25]), RooConst(sigma_template[25]), RooConst(a_template[25]),RooConst(2));
  RooCBShape CrystalBall_m1800("CrystalBall_m1800","Crystal Ball 1800 GeV", Mass, RooConst(mean_template[26]), RooConst(sigma_template[26]), RooConst(a_template[26]),RooConst(2));
  RooCBShape CrystalBall_m1850("CrystalBall_m1850","Crystal Ball 1850 GeV", Mass, RooConst(mean_template[27]), RooConst(sigma_template[27]), RooConst(a_template[27]),RooConst(2));
  RooCBShape CrystalBall_m1900("CrystalBall_m1900","Crystal Ball 1900 GeV", Mass, RooConst(mean_template[28]), RooConst(sigma_template[28]), RooConst(a_template[28]),RooConst(2));
  RooCBShape CrystalBall_m1950("CrystalBall_m1950","Crystal Ball 1950 GeV", Mass, RooConst(mean_template[29]), RooConst(sigma_template[29]), RooConst(a_template[29]),RooConst(2));
  RooCBShape CrystalBall_m2000("CrystalBall_m2000","Crystal Ball 2000 GeV", Mass, RooConst(mean_template[30]), RooConst(sigma_template[30]), RooConst(a_template[30]),RooConst(2));
  

  // Fitframe->GetYaxis()->SetRangeUser(0.00001,0.16);
  // Fitframe->GetYaxis()->SetDrawOption("Logy");
  // CrystalBall_m550.plotOn(Fitframe, LineColor(kOrange));  
  // CrystalBall_m600.plotOn(Fitframe, LineColor(kOrange+1));  
  // CrystalBall_m650.plotOn(Fitframe, LineColor(kOrange+2));  
  // CrystalBall_m700.plotOn(Fitframe, LineColor(kOrange+3));  
  // CrystalBall_m800.plotOn(Fitframe, LineColor(kOrange+4));  
  // CrystalBall_m850.plotOn(Fitframe, LineColor(kOrange+5));  
  // CrystalBall_m900.plotOn(Fitframe, LineColor(kOrange+6));  
  // CrystalBall_m950.plotOn(Fitframe, LineColor(kOrange+7));  
  // CrystalBall_m1050.plotOn(Fitframe, LineColor(kOrange+8));  
  // CrystalBall_m1100.plotOn(Fitframe, LineColor(kOrange+9));  
  // CrystalBall_m1150.plotOn(Fitframe, LineColor(kOrange+10));  
  // CrystalBall_m1200.plotOn(Fitframe, LineColor(kOrange+11));
  // CrystalBall_m1300.plotOn(Fitframe, LineColor(kOrange+12));
  // CrystalBall_m1350.plotOn(Fitframe, LineColor(kOrange+13));
  // CrystalBall_m1400.plotOn(Fitframe, LineColor(kOrange+14));
  // CrystalBall_m1450.plotOn(Fitframe, LineColor(kOrange+15));  

  TH1 * Hist_m550 = MASS.createHistogram("Signal m550",Binning(200)) ;
  //string hist_m550_name = hist_name+"m550_cb_lep_nu_dijet_m";
  string hist_m550_name = "cb_rsg_m550_kMpl0_1";
  Hist_m550->SetName(hist_m550_name.c_str());
  TH1 * Hist_m600 = MASS.createHistogram("Signal m600",Binning(200)) ;
  //string hist_m600_name = hist_name+"m600_cb_lep_nu_dijet_m";
  string hist_m600_name = "cb_rsg_m600_kMpl0_1";
  Hist_m600->SetName(hist_m600_name.c_str());
  TH1 * Hist_m650 = MASS.createHistogram("Signal m650",Binning(200)) ;
  //string hist_m650_name = hist_name+"m650_cb_lep_nu_dijet_m";
  string hist_m650_name = "cb_rsg_m650_kMpl0_1";
  Hist_m650->SetName(hist_m650_name.c_str());
  TH1 * Hist_m700 = MASS.createHistogram("Signal m700",Binning(200)) ;
  //string hist_m700_name = hist_name+"m700_cb_lep_nu_dijet_m";
  string hist_m700_name = "cb_rsg_m700_kMpl0_1";
  Hist_m700->SetName(hist_m700_name.c_str());
  TH1 * Hist_m800 = MASS.createHistogram("Signal m800",Binning(200)) ;
  //string hist_m800_name = hist_name+"m800_cb_lep_nu_dijet_m";
  string hist_m800_name = "cb_rsg_m800_kMpl0_1";
  Hist_m800->SetName(hist_m800_name.c_str());
  TH1 * Hist_m850 = MASS.createHistogram("Signal m850",Binning(200)) ;
  //string hist_m850_name = hist_name+"m850_cb_lep_nu_dijet_m";
  string hist_m850_name = "cb_rsg_m850_kMpl0_1";
  Hist_m850->SetName(hist_m850_name.c_str());
  TH1 * Hist_m900 = MASS.createHistogram("Signal m900",Binning(200)) ;
  //string hist_m900_name = hist_name+"m900_cb_lep_nu_dijet_m";
  string hist_m900_name = "cb_rsg_m900_kMpl0_1";
  Hist_m900->SetName(hist_m900_name.c_str());
  TH1 * Hist_m950 = MASS.createHistogram("Signal m950",Binning(200)) ;
  //string hist_m950_name = hist_name+"m950_cb_lep_nu_dijet_m";
  string hist_m950_name = "cb_rsg_m950_kMpl0_1";
  Hist_m950->SetName(hist_m950_name.c_str());
  TH1 * Hist_m1050 = MASS.createHistogram("Signal m1050",Binning(200)) ;
  //string hist_m1050_name = hist_name+"m1050_cb_lep_nu_dijet_m";
  string hist_m1050_name = "cb_rsg_m1050_kMpl0_1";
  Hist_m1050->SetName(hist_m1050_name.c_str());
  TH1 * Hist_m1100 = MASS.createHistogram("Signal m1100",Binning(200)) ;
  //string hist_m1100_name = hist_name+"m1100_cb_lep_nu_dijet_m";
  string hist_m1100_name = "cb_rsg_m1100_kMpl0_1";
  Hist_m1100->SetName(hist_m1100_name.c_str());
  TH1 * Hist_m1150 = MASS.createHistogram("Signal m1150",Binning(200)) ;

  string hist_m1150_name = "cb_rsg_m1150_kMpl0_1";
  Hist_m1150->SetName(hist_m1150_name.c_str());
  TH1 * Hist_m1200 = MASS.createHistogram("Signal m1200",Binning(200)) ;

  string hist_m1200_name = "cb_rsg_m1200_kMpl0_1";
  Hist_m1200->SetName(hist_m1200_name.c_str());
  TH1 * Hist_m1300 = MASS.createHistogram("Signal m1300",Binning(200)) ;

  string hist_m1300_name = "cb_rsg_m1300_kMpl0_1";
  Hist_m1300->SetName(hist_m1300_name.c_str());
  TH1 * Hist_m1350 = MASS.createHistogram("Signal m1350",Binning(200)) ;

  string hist_m1350_name = "cb_rsg_m1350_kMpl0_1";
  Hist_m1350->SetName(hist_m1350_name.c_str());

  TH1 * Hist_m1400 = MASS.createHistogram("Signal m1400",Binning(200)) ;
  string hist_m1400_name = "cb_rsg_m1400_kMpl0_1";
  Hist_m1400->SetName(hist_m1400_name.c_str());

  TH1 * Hist_m1450 = MASS.createHistogram("Signal m1450",Binning(200)) ;
  string hist_m1450_name = "cb_rsg_m1450_kMpl0_1";
  Hist_m1450->SetName(hist_m1450_name.c_str());

  TH1 * Hist_m1550 = MASS.createHistogram("Signal m1550",Binning(200)) ;
  string hist_m1550_name = "cb_rsg_m1550_kMpl0_1";
  Hist_m1550->SetName(hist_m1550_name.c_str());

  TH1 * Hist_m1600 = MASS.createHistogram("Signal m1600",Binning(200)) ;
  string hist_m1600_name = "cb_rsg_m1600_kMpl0_1";
  Hist_m1600->SetName(hist_m1600_name.c_str());

  TH1 * Hist_m1650 = MASS.createHistogram("Signal m1650",Binning(200)) ;
  string hist_m1650_name = "cb_rsg_m1650_kMpl0_1";
  Hist_m1650->SetName(hist_m1650_name.c_str());

  TH1 * Hist_m1700 = MASS.createHistogram("Signal m1700",Binning(200)) ;
  string hist_m1700_name = "cb_rsg_m1700_kMpl0_1";
  Hist_m1700->SetName(hist_m1700_name.c_str());

  TH1 * Hist_m1750 = MASS.createHistogram("Signal m1750",Binning(200)) ;
  string hist_m1750_name = "cb_rsg_m1750_kMpl0_1";
  Hist_m1750->SetName(hist_m1750_name.c_str());

  TH1 * Hist_m1800 = MASS.createHistogram("Signal m1800",Binning(200)) ;
  string hist_m1800_name = "cb_rsg_m1800_kMpl0_1";
  Hist_m1800->SetName(hist_m1800_name.c_str());

  TH1 * Hist_m1850 = MASS.createHistogram("Signal m1850",Binning(200)) ;
  string hist_m1850_name = "cb_rsg_m1850_kMpl0_1";
  Hist_m1850->SetName(hist_m1850_name.c_str());

  TH1 * Hist_m1900 = MASS.createHistogram("Signal m1900",Binning(200)) ;
  string hist_m1900_name = "cb_rsg_m1900_kMpl0_1";
  Hist_m1900->SetName(hist_m1900_name.c_str());

  TH1 * Hist_m1950 = MASS.createHistogram("Signal m1950",Binning(200)) ;
  string hist_m1950_name = "cb_rsg_m1950_kMpl0_1";
  Hist_m1950->SetName(hist_m1950_name.c_str());

  TH1 * Hist_m2000 = MASS.createHistogram("Signal m2000",Binning(200)) ;
  string hist_m2000_name = "cb_rsg_m2000_kMpl0_1";
  Hist_m2000->SetName(hist_m2000_name.c_str());
  
  CrystalBall_m550.fillHistogram(Hist_m550,RooArgList(MASS));
  CrystalBall_m600.fillHistogram(Hist_m600,RooArgList(MASS));
  CrystalBall_m650.fillHistogram(Hist_m650,RooArgList(MASS));
  CrystalBall_m700.fillHistogram(Hist_m700,RooArgList(MASS));
  CrystalBall_m800.fillHistogram(Hist_m800,RooArgList(MASS));
  CrystalBall_m850.fillHistogram(Hist_m850,RooArgList(MASS));
  CrystalBall_m900.fillHistogram(Hist_m900,RooArgList(MASS));
  CrystalBall_m950.fillHistogram(Hist_m950,RooArgList(MASS));
  CrystalBall_m1050.fillHistogram(Hist_m1050,RooArgList(MASS));
  CrystalBall_m1100.fillHistogram(Hist_m1100,RooArgList(MASS));
  CrystalBall_m1150.fillHistogram(Hist_m1150,RooArgList(MASS));
  CrystalBall_m1200.fillHistogram(Hist_m1200,RooArgList(MASS));
  //CrystalBall_m1250.fillHistogram(Hist_m1250,RooArgList(MASS));
  CrystalBall_m1300.fillHistogram(Hist_m1300,RooArgList(MASS));
  CrystalBall_m1350.fillHistogram(Hist_m1350,RooArgList(MASS));
  CrystalBall_m1400.fillHistogram(Hist_m1400,RooArgList(MASS));
  CrystalBall_m1450.fillHistogram(Hist_m1450,RooArgList(MASS));
  CrystalBall_m1550.fillHistogram(Hist_m1550,RooArgList(MASS));
  CrystalBall_m1600.fillHistogram(Hist_m1600,RooArgList(MASS));
  CrystalBall_m1650.fillHistogram(Hist_m1650,RooArgList(MASS));
  CrystalBall_m1700.fillHistogram(Hist_m1700,RooArgList(MASS));
  CrystalBall_m1750.fillHistogram(Hist_m1750,RooArgList(MASS));
  CrystalBall_m1800.fillHistogram(Hist_m1800,RooArgList(MASS));
  CrystalBall_m1850.fillHistogram(Hist_m1850,RooArgList(MASS));
  CrystalBall_m1900.fillHistogram(Hist_m1900,RooArgList(MASS));
  CrystalBall_m1950.fillHistogram(Hist_m1950,RooArgList(MASS));
  CrystalBall_m2000.fillHistogram(Hist_m2000,RooArgList(MASS));
  
  Double_t Xmass = 550;
  Double_t Channel_Acceptance_m550 = chn_acc_n*TMath::Landau(Xmass,chn_acc_mpv,chn_acc_sig);
  Xmass = 600;
  Double_t Channel_Acceptance_m600 = chn_acc_n*TMath::Landau(Xmass,chn_acc_mpv,chn_acc_sig);
  Xmass = 650;
  Double_t Channel_Acceptance_m650 = chn_acc_n*TMath::Landau(Xmass,chn_acc_mpv,chn_acc_sig);
  Xmass = 700;
  Double_t Channel_Acceptance_m700 = chn_acc_n*TMath::Landau(Xmass,chn_acc_mpv,chn_acc_sig);
  Xmass = 800;
  Double_t Channel_Acceptance_m800 = chn_acc_n*TMath::Landau(Xmass,chn_acc_mpv,chn_acc_sig);
  Xmass = 850;
  Double_t Channel_Acceptance_m850 = chn_acc_n*TMath::Landau(Xmass,chn_acc_mpv,chn_acc_sig);
  Xmass = 900;
  Double_t Channel_Acceptance_m900 = chn_acc_n*TMath::Landau(Xmass,chn_acc_mpv,chn_acc_sig);
  Xmass = 950;
  Double_t Channel_Acceptance_m950 = chn_acc_n*TMath::Landau(Xmass,chn_acc_mpv,chn_acc_sig);
  Xmass = 1050;
  Double_t Channel_Acceptance_m1050 = chn_acc_n*TMath::Landau(Xmass,chn_acc_mpv,chn_acc_sig);
  Xmass = 1100;
  Double_t Channel_Acceptance_m1100 = chn_acc_n*TMath::Landau(Xmass,chn_acc_mpv,chn_acc_sig);
  Xmass = 1150;
  Double_t Channel_Acceptance_m1150 = chn_acc_n*TMath::Landau(Xmass,chn_acc_mpv,chn_acc_sig);
  Xmass = 1200;
  Double_t Channel_Acceptance_m1200 = chn_acc_n*TMath::Landau(Xmass,chn_acc_mpv,chn_acc_sig);
  Xmass = 1300;
  Double_t Channel_Acceptance_m1300 = chn_acc_n*TMath::Landau(Xmass,chn_acc_mpv,chn_acc_sig);
  Xmass = 1350;
  Double_t Channel_Acceptance_m1350 = chn_acc_n*TMath::Landau(Xmass,chn_acc_mpv,chn_acc_sig);
  Xmass = 1400;
  Double_t Channel_Acceptance_m1400 = chn_acc_n*TMath::Landau(Xmass,chn_acc_mpv,chn_acc_sig);
  Xmass = 1450;
  Double_t Channel_Acceptance_m1450 = chn_acc_n*TMath::Landau(Xmass,chn_acc_mpv,chn_acc_sig);

  Xmass = 1550;
  Double_t Channel_Acceptance_m1550 = chn_acc_n*TMath::Landau(Xmass,chn_acc_mpv,chn_acc_sig);
  Xmass = 1600;
  Double_t Channel_Acceptance_m1600 = chn_acc_n*TMath::Landau(Xmass,chn_acc_mpv,chn_acc_sig);
  Xmass = 1650;
  Double_t Channel_Acceptance_m1650 = chn_acc_n*TMath::Landau(Xmass,chn_acc_mpv,chn_acc_sig);
  Xmass = 1700;
  Double_t Channel_Acceptance_m1700 = chn_acc_n*TMath::Landau(Xmass,chn_acc_mpv,chn_acc_sig);
  Xmass = 1750;
  Double_t Channel_Acceptance_m1750 = chn_acc_n*TMath::Landau(Xmass,chn_acc_mpv,chn_acc_sig);
  Xmass = 1800;
  Double_t Channel_Acceptance_m1800 = chn_acc_n*TMath::Landau(Xmass,chn_acc_mpv,chn_acc_sig);
  Xmass = 1850;
  Double_t Channel_Acceptance_m1850 = chn_acc_n*TMath::Landau(Xmass,chn_acc_mpv,chn_acc_sig);
  Xmass = 1900;
  Double_t Channel_Acceptance_m1900 = chn_acc_n*TMath::Landau(Xmass,chn_acc_mpv,chn_acc_sig);
  Xmass = 1950;
  Double_t Channel_Acceptance_m1950 = chn_acc_n*TMath::Landau(Xmass,chn_acc_mpv,chn_acc_sig);
  Xmass = 2000;
  Double_t Channel_Acceptance_m2000 = chn_acc_n*TMath::Landau(Xmass,chn_acc_mpv,chn_acc_sig);

  
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
  Double_t Scale_m1050 = Total_Lumi*CrossSection_m1050*Channel_Acceptance_m1050;
  Double_t Scale_m1100 = Total_Lumi*CrossSection_m1100*Channel_Acceptance_m1100;
  Double_t Scale_m1150 = Total_Lumi*CrossSection_m1150*Channel_Acceptance_m1150;
  Double_t Scale_m1200 = Total_Lumi*CrossSection_m1200*Channel_Acceptance_m1200;
  Double_t Scale_m1250 = Total_Lumi*CrossSection_m1250*Channel_Acceptance_m1250;
  Double_t Scale_m1300 = Total_Lumi*CrossSection_m1300*Channel_Acceptance_m1300;
  Double_t Scale_m1350 = Total_Lumi*CrossSection_m1350*Channel_Acceptance_m1350;
  Double_t Scale_m1400 = Total_Lumi*CrossSection_m1400*Channel_Acceptance_m1400;
  Double_t Scale_m1450 = Total_Lumi*CrossSection_m1450*Channel_Acceptance_m1450;
  Double_t Scale_m1500 = Total_Lumi*CrossSection_m1500*Channel_Acceptance_m1500;
  Double_t Scale_m1550 = Total_Lumi*CrossSection_m1550*Channel_Acceptance_m1550;
  Double_t Scale_m1600 = Total_Lumi*CrossSection_m1600*Channel_Acceptance_m1600;
  Double_t Scale_m1650 = Total_Lumi*CrossSection_m1650*Channel_Acceptance_m1650;
  Double_t Scale_m1700 = Total_Lumi*CrossSection_m1700*Channel_Acceptance_m1700;
  Double_t Scale_m1750 = Total_Lumi*CrossSection_m1750*Channel_Acceptance_m1750;
  Double_t Scale_m1800 = Total_Lumi*CrossSection_m1800*Channel_Acceptance_m1800;
  Double_t Scale_m1850 = Total_Lumi*CrossSection_m1850*Channel_Acceptance_m1850;
  Double_t Scale_m1900 = Total_Lumi*CrossSection_m1900*Channel_Acceptance_m1900;
  Double_t Scale_m1950 = Total_Lumi*CrossSection_m1950*Channel_Acceptance_m1950;
  Double_t Scale_m2000 = Total_Lumi*CrossSection_m2000*Channel_Acceptance_m2000;

  Hist_m500->Scale(9999*Channel_Acceptance_m500*2);
  Hist_m550->Scale(9999*Channel_Acceptance_m550*2);
  Hist_m600->Scale(9999*Channel_Acceptance_m600*2);
  Hist_m650->Scale(9999*Channel_Acceptance_m650*2);
  Hist_m700->Scale(9999*Channel_Acceptance_m700*2);
  Hist_m750->Scale(9999*Channel_Acceptance_m750*2);
  Hist_m800->Scale(9999*Channel_Acceptance_m800*2);
  Hist_m850->Scale(9999*Channel_Acceptance_m850*2);
  Hist_m900->Scale(9999*Channel_Acceptance_m900*2);
  Hist_m950->Scale(9999*Channel_Acceptance_m950*2);
  Hist_m1000->Scale(9999*Channel_Acceptance_m1000*2);
  Hist_m1050->Scale(9999*Channel_Acceptance_m1050*2);
  Hist_m1100->Scale(9999*Channel_Acceptance_m1100*2);
  Hist_m1150->Scale(9999*Channel_Acceptance_m1150*2);
  Hist_m1200->Scale(9999*Channel_Acceptance_m1200*2);
  Hist_m1250->Scale(9999*Channel_Acceptance_m1250*2);
  Hist_m1300->Scale(9999*Channel_Acceptance_m1300*2);
  Hist_m1350->Scale(9999*Channel_Acceptance_m1350*2);
  Hist_m1400->Scale(9999*Channel_Acceptance_m1400*2);
  Hist_m1450->Scale(9999*Channel_Acceptance_m1450*2);
  Hist_m1500->Scale(9999*Channel_Acceptance_m1500*2);
  Hist_m1500->Scale(9999*Channel_Acceptance_m1500*2);
  Hist_m1550->Scale(9999*Channel_Acceptance_m1550*2);
  Hist_m1600->Scale(9999*Channel_Acceptance_m1600*2);
  Hist_m1650->Scale(9999*Channel_Acceptance_m1650*2);
  Hist_m1700->Scale(9999*Channel_Acceptance_m1700*2);
  Hist_m1750->Scale(9999*Channel_Acceptance_m1750*2);
  Hist_m1800->Scale(9999*Channel_Acceptance_m1800*2);
  Hist_m1850->Scale(9999*Channel_Acceptance_m1850*2);
  Hist_m1900->Scale(9999*Channel_Acceptance_m1900*2);
  Hist_m1950->Scale(9999*Channel_Acceptance_m1950*2);
  Hist_m2000->Scale(9999*Channel_Acceptance_m2000*2);
  

  Int_t total_bins = 200;
  for(Int_t bin = 0; bin < total_bins ; bin++){
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
    if(Hist_m1050->GetBinContent(bin) >= 1.0){
      Hist_m1050->SetBinError(bin, sqrt(Hist_m1050->GetBinContent(bin)));
    }
    if(Hist_m1100->GetBinContent(bin) >= 1.0){
      Hist_m1100->SetBinError(bin, sqrt(Hist_m1100->GetBinContent(bin)));
    }
    if(Hist_m1150->GetBinContent(bin) >= 1.0){
      Hist_m1150->SetBinError(bin, sqrt(Hist_m1150->GetBinContent(bin)));
    }
    if(Hist_m1200->GetBinContent(bin) >= 1.0){
      Hist_m1200->SetBinError(bin, sqrt(Hist_m1200->GetBinContent(bin)));
    }
    if(Hist_m1250->GetBinContent(bin) >= 1.0){
      Hist_m1250->SetBinError(bin, sqrt(Hist_m1250->GetBinContent(bin)));
    }
    if(Hist_m1300->GetBinContent(bin) >= 1.0){
      Hist_m1300->SetBinError(bin, sqrt(Hist_m1300->GetBinContent(bin)));
    }
    if(Hist_m1350->GetBinContent(bin) >= 1.0){
      Hist_m1350->SetBinError(bin, sqrt(Hist_m1350->GetBinContent(bin)));
    }
    if(Hist_m1400->GetBinContent(bin) >= 1.0){
      Hist_m1400->SetBinError(bin, sqrt(Hist_m1400->GetBinContent(bin)));
    }
    if(Hist_m1450->GetBinContent(bin) >= 1.0){
      Hist_m1450->SetBinError(bin, sqrt(Hist_m1450->GetBinContent(bin)));
    }
    if(Hist_m1500->GetBinContent(bin) >= 1.0){
      Hist_m1500->SetBinError(bin, sqrt(Hist_m1500->GetBinContent(bin)));
    }
    if(Hist_m1500->GetBinContent(bin) >= 1.0){
      Hist_m1500->SetBinError(bin, sqrt(Hist_m1500->GetBinContent(bin)));
    }
    if(Hist_m1550->GetBinContent(bin) >= 1.0){
      Hist_m1550->SetBinError(bin, sqrt(Hist_m1550->GetBinContent(bin)));
    }
    if(Hist_m1600->GetBinContent(bin) >= 1.0){
      Hist_m1600->SetBinError(bin, sqrt(Hist_m1600->GetBinContent(bin)));
    }
    if(Hist_m1650->GetBinContent(bin) >= 1.0){
      Hist_m1650->SetBinError(bin, sqrt(Hist_m1650->GetBinContent(bin)));
    }
    if(Hist_m1700->GetBinContent(bin) >= 1.0){
      Hist_m1700->SetBinError(bin, sqrt(Hist_m1700->GetBinContent(bin)));
    }
    if(Hist_m1750->GetBinContent(bin) >= 1.0){
      Hist_m1750->SetBinError(bin, sqrt(Hist_m1750->GetBinContent(bin)));
    }
    if(Hist_m1800->GetBinContent(bin) >= 1.0){
      Hist_m1800->SetBinError(bin, sqrt(Hist_m1800->GetBinContent(bin)));
    }
    if(Hist_m1850->GetBinContent(bin) >= 1.0){
      Hist_m1850->SetBinError(bin, sqrt(Hist_m1850->GetBinContent(bin)));
    }
    if(Hist_m1900->GetBinContent(bin) >= 1.0){
      Hist_m1900->SetBinError(bin, sqrt(Hist_m1900->GetBinContent(bin)));
    }
    if(Hist_m1950->GetBinContent(bin) >= 1.0){
      Hist_m1950->SetBinError(bin, sqrt(Hist_m1950->GetBinContent(bin)));
    }
    if(Hist_m2000->GetBinContent(bin) >= 1.0){
      Hist_m2000->SetBinError(bin, sqrt(Hist_m2000->GetBinContent(bin)));
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
    if(Hist_m1050->GetBinContent(bin) < 1.0){
      Hist_m1050->SetBinError(bin, Hist_m1050->GetBinContent(bin));
    }
    if(Hist_m1100->GetBinContent(bin) < 1.0){
      Hist_m1100->SetBinError(bin, Hist_m1100->GetBinContent(bin));
    }
    if(Hist_m1150->GetBinContent(bin) < 1.0){
      Hist_m1150->SetBinError(bin, Hist_m1150->GetBinContent(bin));
    }
    if(Hist_m1200->GetBinContent(bin) < 1.0){
      Hist_m1200->SetBinError(bin, Hist_m1200->GetBinContent(bin));
    }
    if(Hist_m1250->GetBinContent(bin) < 1.0){
      Hist_m1250->SetBinError(bin, Hist_m1250->GetBinContent(bin));
    }
    if(Hist_m1300->GetBinContent(bin) < 1.0){
      Hist_m1300->SetBinError(bin, Hist_m1300->GetBinContent(bin));
    }
    if(Hist_m1350->GetBinContent(bin) < 1.0){
      Hist_m1350->SetBinError(bin, Hist_m1350->GetBinContent(bin));
    }
    if(Hist_m1400->GetBinContent(bin) < 1.0){
      Hist_m1400->SetBinError(bin, Hist_m1400->GetBinContent(bin));
    }
    if(Hist_m1450->GetBinContent(bin) < 1.0){
      Hist_m1450->SetBinError(bin, Hist_m1450->GetBinContent(bin));
    }
    if(Hist_m1500->GetBinContent(bin) < 1.0){
      Hist_m1500->SetBinError(bin, Hist_m1500->GetBinContent(bin));
    }
    if(Hist_m1500->GetBinContent(bin) < 1.0){
      Hist_m1500->SetBinError(bin, Hist_m1500->GetBinContent(bin));
    }
    if(Hist_m1550->GetBinContent(bin) < 1.0){
      Hist_m1550->SetBinError(bin, Hist_m1550->GetBinContent(bin));
    }
    if(Hist_m1600->GetBinContent(bin) < 1.0){
      Hist_m1600->SetBinError(bin, Hist_m1600->GetBinContent(bin));
    }
    if(Hist_m1650->GetBinContent(bin) < 1.0){
      Hist_m1650->SetBinError(bin, Hist_m1650->GetBinContent(bin));
    }
    if(Hist_m1700->GetBinContent(bin) < 1.0){
      Hist_m1700->SetBinError(bin, Hist_m1700->GetBinContent(bin));
    }
    if(Hist_m1750->GetBinContent(bin) < 1.0){
      Hist_m1750->SetBinError(bin, Hist_m1750->GetBinContent(bin));
    }
    if(Hist_m1800->GetBinContent(bin) < 1.0){
      Hist_m1800->SetBinError(bin, Hist_m1800->GetBinContent(bin));
    }
    if(Hist_m1850->GetBinContent(bin) < 1.0){
      Hist_m1850->SetBinError(bin, Hist_m1850->GetBinContent(bin));
    }
    if(Hist_m1900->GetBinContent(bin) < 1.0){
      Hist_m1900->SetBinError(bin, Hist_m1900->GetBinContent(bin));
    }
    if(Hist_m1950->GetBinContent(bin) < 1.0){
      Hist_m1950->SetBinError(bin, Hist_m1950->GetBinContent(bin));
    }
    if(Hist_m2000->GetBinContent(bin) < 1.0){
      Hist_m2000->SetBinError(bin, Hist_m2000->GetBinContent(bin));
    }

  }

  Hist_m500->Scale(Scale_m500/(9999*Channel_Acceptance_m500*2));
  Hist_m550->Scale(Scale_m550/(9999*Channel_Acceptance_m550*2));
  Hist_m600->Scale(Scale_m600/(9999*Channel_Acceptance_m600*2));
  Hist_m650->Scale(Scale_m650/(9999*Channel_Acceptance_m650*2));
  Hist_m700->Scale(Scale_m700/(9999*Channel_Acceptance_m700*2));
  Hist_m750->Scale(Scale_m750/(9999*Channel_Acceptance_m750*2));
  Hist_m800->Scale(Scale_m800/(9999*Channel_Acceptance_m800*2));
  Hist_m850->Scale(Scale_m850/(9999*Channel_Acceptance_m850*2));
  Hist_m900->Scale(Scale_m900/(9999*Channel_Acceptance_m900*2));
  Hist_m950->Scale(Scale_m950/(9999*Channel_Acceptance_m950*2));
  Hist_m1000->Scale(Scale_m1000/(9999*Channel_Acceptance_m1000*2));
  Hist_m1050->Scale(Scale_m1050/(9999*Channel_Acceptance_m1050*2));
  Hist_m1100->Scale(Scale_m1100/(9999*Channel_Acceptance_m1100*2));
  Hist_m1150->Scale(Scale_m1150/(9999*Channel_Acceptance_m1150*2));
  Hist_m1200->Scale(Scale_m1200/(9999*Channel_Acceptance_m1200*2));
  Hist_m1250->Scale(Scale_m1250/(9999*Channel_Acceptance_m1250*2));
  Hist_m1300->Scale(Scale_m1300/(9999*Channel_Acceptance_m1300*2));
  Hist_m1350->Scale(Scale_m1350/(9999*Channel_Acceptance_m1350*2));
  Hist_m1400->Scale(Scale_m1400/(9999*Channel_Acceptance_m1400*2));
  Hist_m1450->Scale(Scale_m1450/(9999*Channel_Acceptance_m1450*2));
  Hist_m1500->Scale(Scale_m1500/(9999*Channel_Acceptance_m1500*2));
  Hist_m1550->Scale(Scale_m1550/(9999*Channel_Acceptance_m1550*2));
  Hist_m1600->Scale(Scale_m1600/(9999*Channel_Acceptance_m1600*2));
  Hist_m1650->Scale(Scale_m1650/(9999*Channel_Acceptance_m1650*2));
  Hist_m1700->Scale(Scale_m1700/(9999*Channel_Acceptance_m1700*2));
  Hist_m1750->Scale(Scale_m1750/(9999*Channel_Acceptance_m1750*2));
  Hist_m1800->Scale(Scale_m1800/(9999*Channel_Acceptance_m1800*2));
  Hist_m1850->Scale(Scale_m1850/(9999*Channel_Acceptance_m1850*2));
  Hist_m1900->Scale(Scale_m1900/(9999*Channel_Acceptance_m1900*2));
  Hist_m1950->Scale(Scale_m1950/(9999*Channel_Acceptance_m1950*2));
  Hist_m2000->Scale(Scale_m2000/(9999*Channel_Acceptance_m2000*2));
  

  // TODO 
  //Int_t nBins = 200;
  Hist_m500->Rebin(8);
  Hist_m550->Rebin(8);
  Hist_m600->Rebin(8);
  Hist_m650->Rebin(8);
  Hist_m700->Rebin(8);
  Hist_m750->Rebin(8);
  Hist_m800->Rebin(8);
  Hist_m850->Rebin(8);
  Hist_m900->Rebin(8);
  Hist_m950->Rebin(8);
  Hist_m1000->Rebin(8);
  Hist_m1050->Rebin(8);
  Hist_m1100->Rebin(8);
  Hist_m1150->Rebin(8);
  Hist_m1200->Rebin(8);
  Hist_m1250->Rebin(8);
  Hist_m1300->Rebin(8);
  Hist_m1350->Rebin(8);
  Hist_m1400->Rebin(8);
  Hist_m1450->Rebin(8);
  Hist_m1500->Rebin(8);
  Hist_m1550->Rebin(8);
  Hist_m1600->Rebin(8);
  Hist_m1650->Rebin(8);
  Hist_m1700->Rebin(8);
  Hist_m1750->Rebin(8);
  Hist_m1800->Rebin(8);
  Hist_m1850->Rebin(8);
  Hist_m1900->Rebin(8);
  Hist_m1950->Rebin(8);
  Hist_m2000->Rebin(8);
  

  
  cout << "=====================================" << endl;
  cout << "Integral_m500 " << Integral_m500 << endl;   
  cout << "Integral_m750 " << Integral_m750 << endl;   
  cout << "Integral_m1000 " << Integral_m1000 << endl;   
  cout << "Integral_m1250 " << Integral_m1250 << endl;   
  cout << "Integral_m1500 " << Integral_m1500 << endl;   
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
  Double_t Integral_m1050 = Hist_m1050->Integral(0,200);
  Double_t Integral_m1100 = Hist_m1100->Integral(0,200);
  Double_t Integral_m1150 = Hist_m1150->Integral(0,200);
  Double_t Integral_m1200 = Hist_m1200->Integral(0,200);
  Integral_m1250 = Hist_m1250->Integral(0,200);
  Double_t Integral_m1300 = Hist_m1300->Integral(0,200);
  Double_t Integral_m1350 = Hist_m1350->Integral(0,200);
  Double_t Integral_m1400 = Hist_m1400->Integral(0,200);
  Double_t Integral_m1450 = Hist_m1450->Integral(0,200);
  Integral_m1500 = Hist_m1500->Integral(0,200);

  cout << "=====================================" << endl;
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
  cout << "Integral_m1050 " << Integral_m1050 << endl;   
  cout << "Integral_m1100 " << Integral_m1100 << endl;
  cout << "Integral_m1150 " << Integral_m1150 << endl;   
  cout << "Integral_m1200 " << Integral_m1200 << endl;
  cout << "Integral_m1250 " << Integral_m1250 << endl;   
  cout << "Integral_m1300 " << Integral_m1300 << endl;
  cout << "Integral_m1350 " << Integral_m1350 << endl;   
  cout << "Integral_m1400 " << Integral_m1400 << endl;
  cout << "Integral_m1450 " << Integral_m1450 << endl;   
  cout << "Integral_m1500 " << Integral_m1500 << endl;
  cout << "Integral_m1550 " << Integral_m1550 << endl;   
  cout << "Integral_m1600 " << Integral_m1600 << endl;   
  cout << "Integral_m1650 " << Integral_m1650 << endl;   
  cout << "Integral_m1700 " << Integral_m1700 << endl;   
  cout << "Integral_m1750 " << Integral_m1750 << endl;   
  cout << "Integral_m1800 " << Integral_m1800 << endl;   
  cout << "Integral_m1850 " << Integral_m1850 << endl;   
  cout << "Integral_m1900 " << Integral_m1900 << endl;   
  cout << "Integral_m1950 " << Integral_m1950 << endl;   
  cout << "Integral_m2000 " << Integral_m2000 << endl;
  cout << "=====================================" << endl;
  cout << "Total_Channel_m500 " << Total_Channel_m500 << endl;
  cout << "Total_Channel_m750 " << Total_Channel_m750 << endl;
  cout << "Total_Channel_m1000 " << Total_Channel_m1000 << endl;
  cout << "Total_Channel_m1250 " << Total_Channel_m1250 << endl;
  cout << "Total_Channel_m1500 " << Total_Channel_m1500 << endl;
  cout << "=====================================" << endl;
  cout << "Channel_Acceptance_m500  " << Channel_Acceptance_m500 << endl; 
  cout << "Channel_Acceptance_m550  " << Channel_Acceptance_m550 << endl; 
  cout << "Channel_Acceptance_m600  " << Channel_Acceptance_m600 << endl; 
  cout << "Channel_Acceptance_m650  " << Channel_Acceptance_m650 << endl; 
  cout << "Channel_Acceptance_m700  " << Channel_Acceptance_m700 << endl; 
  cout << "Channel_Acceptance_m750  " << Channel_Acceptance_m750 << endl; 
  cout << "Channel_Acceptance_m800  " << Channel_Acceptance_m800 << endl; 
  cout << "Channel_Acceptance_m850  " << Channel_Acceptance_m850 << endl; 
  cout << "Channel_Acceptance_m900  " << Channel_Acceptance_m900 << endl; 
  cout << "Channel_Acceptance_m950  " << Channel_Acceptance_m950 << endl; 
  cout << "Channel_Acceptance_m1000  " << Channel_Acceptance_m1000 << endl; 
  cout << "Channel_Acceptance_m1050 " << Channel_Acceptance_m1050 << endl;   
  cout << "Channel_Acceptance_m1100 " << Channel_Acceptance_m1100 << endl;
  cout << "Channel_Acceptance_m1150 " << Channel_Acceptance_m1150 << endl;   
  cout << "Channel_Acceptance_m1200 " << Channel_Acceptance_m1200 << endl;
  cout << "Channel_Acceptance_m1250 " << Channel_Acceptance_m1250 << endl;   
  cout << "Channel_Acceptance_m1300 " << Channel_Acceptance_m1300 << endl;
  cout << "Channel_Acceptance_m1350 " << Channel_Acceptance_m1350 << endl;   
  cout << "Channel_Acceptance_m1400 " << Channel_Acceptance_m1400 << endl;
  cout << "Channel_Acceptance_m1450 " << Channel_Acceptance_m1450 << endl;   
  cout << "Channel_Acceptance_m1500 " << Channel_Acceptance_m1500 << endl;
  cout << "Channel_Acceptance_m1550  " << Channel_Acceptance_m1550 << endl; 
  cout << "Channel_Acceptance_m1600  " << Channel_Acceptance_m1600 << endl; 
  cout << "Channel_Acceptance_m1650  " << Channel_Acceptance_m1650 << endl; 
  cout << "Channel_Acceptance_m1700  " << Channel_Acceptance_m1700 << endl; 
  cout << "Channel_Acceptance_m1750  " << Channel_Acceptance_m1750 << endl; 
  cout << "Channel_Acceptance_m1800  " << Channel_Acceptance_m1800 << endl; 
  cout << "Channel_Acceptance_m1850  " << Channel_Acceptance_m1850 << endl; 
  cout << "Channel_Acceptance_m1900  " << Channel_Acceptance_m1900 << endl; 
  cout << "Channel_Acceptance_m1950  " << Channel_Acceptance_m1950 << endl; 
  cout << "Channel_Acceptance_m2000  " << Channel_Acceptance_m2000 << endl; 
  cout << "=====================================" << endl;


  
  CrystalBallFits->Write();
  CrystalBallFits->Close();

  signal_m500.plotOn(m500frame,LineColor(1),MarkerColor(1),MarkerSize(1.0),Name("data"));
  CrystalBall1.plotOn(m500frame, LineColor(kBlue),LineStyle(2),Name("cb"),Range(300,700));
    
  signal_m750.plotOn(m750frame,LineColor(1),MarkerColor(1),MarkerSize(1.0),Name("data"));
  CrystalBall2.plotOn(m750frame, LineColor(kBlue),LineStyle(2),Name("cb"));
    
  signal_m1000.plotOn(m1000frame,LineColor(1),MarkerColor(1),MarkerSize(1.0),Name("data"));
  CrystalBall3.plotOn(m1000frame, LineColor(kBlue),LineStyle(2),Name("cb"));
    
  signal_m1250.plotOn(m1250frame,LineColor(1),MarkerColor(1),MarkerSize(1.0),Name("data"));
  CrystalBall4.plotOn(m1250frame, LineColor(kBlue),LineStyle(2),Name("cb"));
  
  signal_m1500.plotOn(m1500frame,LineColor(1),MarkerColor(1),MarkerSize(1.0),Name("data"));
  CrystalBall5.plotOn(m1500frame, LineColor(kBlue),LineStyle(2),Name("cb"));

  
  string tc_m500_fit_templates_name = channel+"_"+cur_sys+"_m500_fit_templates";  
  TCanvas* c_m500_fit_templates =
    new TCanvas(tc_m500_fit_templates_name.c_str(),"Template distributions",200,10,700,500);
  c_m500_fit_templates->cd();

  m500frame->Draw();

  TLegend *lgnd_m500 = new TLegend(0.25,0.73,0.46,0.87);
  lgnd_m500->SetFillColor(kWhite);
  lgnd_m500->SetLineColor(kWhite);
  lgnd_m500->AddEntry("data","Signal", "P");
  lgnd_m500->AddEntry("cb","Crystal Ball","L");
  lgnd_m500->Draw();
  
  string tmp_saveas = "../plots/"+channel+"_"+cur_sys+"_m500_fit_templates.pdf";
  c_m500_fit_templates->SaveAs(tmp_saveas.c_str());


  // string tc_m500_fit_templates_with_template_name = channel+"_"+cur_sys+"_m500_fit_templates_with_template";  
  // TCanvas* c_m500_fit_templates_with_template =
  //   new TCanvas(tc_m500_fit_templates_with_template_name.c_str(),"Template distributions",200,10,700,500);
  // c_m500_fit_templates_with_template->cd();

  // m500frame->Draw();

    
  string tc_m750_fit_templates_name = channel+"_"+cur_sys+"_m750_fit_templates";
  TCanvas* c_m750_fit_templates =
    new TCanvas(tc_m750_fit_templates_name.c_str(),"Template distributions",200,10,700,500);
  c_m750_fit_templates->cd();
  
  m750frame->Draw();

  TLegend *lgnd_m750 = new TLegend(0.25,0.73,0.46,0.87);
  lgnd_m750->SetFillColor(kWhite);
  lgnd_m750->SetLineColor(kWhite);
  lgnd_m750->AddEntry("data","Signal", "P");
  lgnd_m750->AddEntry("cb","Crystal Ball","L");
  lgnd_m750->Draw();
  
  tmp_saveas = "../plots/"+channel+"_"+cur_sys+"_m750_fit_templates.pdf";
  c_m750_fit_templates->SaveAs(tmp_saveas.c_str());

  string tc_m1000_fit_templates_name = channel+"_"+cur_sys+"_m1000_fit_templates";
  TCanvas* c_m1000_fit_templates =
    new TCanvas(tc_m1000_fit_templates_name.c_str(),"Template distributions",200,10,700,500);
  c_m1000_fit_templates->cd();
  
  m1000frame->Draw();

  TLegend *lgnd_m1000 = new TLegend(0.25,0.73,0.46,0.87);
  lgnd_m1000->SetFillColor(kWhite);
  lgnd_m1000->SetLineColor(kWhite);
  lgnd_m1000->AddEntry("data","Signal", "P");
  lgnd_m1000->AddEntry("cb","Crystal Ball","L");
  lgnd_m1000->Draw();
  
  tmp_saveas = "../plots/"+channel+"_"+cur_sys+"_m1000_fit_templates.pdf";
  c_m1000_fit_templates->SaveAs(tmp_saveas.c_str());

  string tc_m1250_fit_templates_name = channel+"_"+cur_sys+"_m1250_fit_templates";
  TCanvas* c_m1250_fit_templates =
    new TCanvas(tc_m1250_fit_templates_name.c_str(),"Template distributions",200,10,700,500);
  c_m1250_fit_templates->cd();
  
  m1250frame->Draw();

  TLegend *lgnd_m1250 = new TLegend(0.25,0.73,0.46,0.87);
  lgnd_m1250->SetFillColor(kWhite);
  lgnd_m1250->SetLineColor(kWhite);
  lgnd_m1250->AddEntry("data","Signal", "P");
  lgnd_m1250->AddEntry("cb","Crystal Ball","L");
  lgnd_m1250->Draw();
  
  tmp_saveas = "../plots/"+channel+"_"+cur_sys+"_m1250_fit_templates.pdf";
  c_m1250_fit_templates->SaveAs(tmp_saveas.c_str());


  string tc_m1500_fit_templates_name = channel+"_"+cur_sys+"_m1500_fit_templates";
  TCanvas* c_m1500_fit_templates =
    new TCanvas(tc_m1500_fit_templates_name.c_str(),"Template distributions",200,10,700,500);
  c_m1500_fit_templates->cd();

  //m1500frame->GetYaxis()->SetRangeUser(0.001,0.06);

  m1500frame->Draw();
  c_m1500_fit_templates->Update();
  
  TLegend *lgnd_m1500 = new TLegend(0.25,0.73,0.46,0.87);
  lgnd_m1500->SetFillColor(kWhite);
  lgnd_m1500->SetLineColor(kWhite);
  lgnd_m1500->AddEntry("data","Signal", "P");
  lgnd_m1500->AddEntry("cb","Crystal Ball","L");
  lgnd_m1500->Draw();

  tmp_saveas = "../plots/"+channel+"_"+cur_sys+"_m1500_fit_templates.pdf";
  c_m1500_fit_templates->SaveAs(tmp_saveas.c_str());

  
  //Massframe->Draw();
  //Massframe->Write("CrystalBallFits_MassFrame");
  //  Massframe->Write();



  



  // TCanvas* c_sig_templates = new TCanvas("c_sig_templates","Templae distributions",200,10,700,500);
  // c_sig_templates->cd();

  // Fitframe->Draw();
  
  // string tmp_saveas = "../plots/"+channel+"_"+cur_sys+"_signal_templates.pdf";
  // c_sig_templates->SaveAs(tmp_saveas.c_str());



  string tc_c_parm_name = channel+"_"+cur_sys+"_c_parm";
  TCanvas *c_parm = new TCanvas(tc_c_parm_name.c_str(),"Parameter fits",200,10,700,500);
  c_parm->Divide(2,2);

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

  string cur_saveas = "../plots/"+channel+"_"+cur_sys+"_fit_parameters.pdf";
  c_parm->SaveAs(cur_saveas.c_str());
  

  // TCanvas *c_acc = new TCanvas("c_acc","Acceptances",200,10,500,500);
  // Double_t x[n_sig_masses];
  // x[0] = 500.0;
  // x[1] = 750.0;
  // x[2] = 1000.0;
  // x[3] = 1250.0;
  // x[4] = 1500.0;

  // Double_t Y[n_sig_masses];
  // Y[0] = Acceptance_m500;
  // Y[1] = Acceptance_m750;
  // Y[2] = Acceptance_m1000;
  // Y[3] = Acceptance_m1250;
  // Y[4] = Acceptance_m1500;
  
  // TGraph * Accept = new TGraph(n_sig_masses,x,Y);
  // Accept->SetTitle("");
  // Accept->GetXaxis()->SetTitle("W' Pole Mass [GeV]");
  // Accept->GetYaxis()->SetTitle("Total Acceptance");
  // Accept->Draw("AL*");
  // Accept->SetLineColor(4);
  // Accept->SetLineWidth(2);
  // Accept->SetMarkerColor(4);
  // Accept->SetMarkerStyle(22);

  // cur_saveas = "../plots/"+channel+"_"+cur_sys+"_signal_acceptances.pdf";
  // c_acc->SaveAs(cur_saveas.c_str());
  

  //Massframe->Write("CrystalBallFits");

  if(sigma_fit) delete sigma_fit;
  if(mean_fit) delete mean_fit;
  if(a_fit) delete a_fit;
  if(n_fit) delete n_fit;

  if(gr_parameter_Mean) delete gr_parameter_Mean;
  if(gr_parameter_Sigma) delete gr_parameter_Sigma;
  if(gr_parameter_A) delete gr_parameter_A;
  if(gr_parameter_N) delete gr_parameter_N;

  if(Channel_Accept) delete Channel_Accept;
  if(Accept) delete Accept;
  if(CrystalBallFits) delete CrystalBallFits;

  if(c_m500_fit_templates) delete c_m500_fit_templates;
  if(lgnd_m500) delete lgnd_m500;
  if(c_m750_fit_templates) delete c_m750_fit_templates;
  if(lgnd_m750) delete lgnd_m750;
  if(c_m1000_fit_templates) delete c_m1000_fit_templates;
  if(lgnd_m1000) delete lgnd_m1000;
  if(c_m1250_fit_templates) delete c_m1250_fit_templates;
  if(lgnd_m1250) delete lgnd_m1250;
  if(c_m1500_fit_templates) delete c_m1500_fit_templates;
  if(lgnd_m1500) delete lgnd_m1500;
  
  cout<<"okay"<<endl;
  return;
}

void signalShapes::makeClosurePlots(string channel/*="evjj"*/,string cur_sys/*="jes_nom"*/){

  //gROOT->SetBatch();

  
  // Plot simulated variables against template histograms
  // compare normalization, shape etc.

  
  
   // Get Template histograms
  string cb_file_name = "../files/"+channel+"_cb_"+cur_sys+"_lep_nu_dijet_m.root";
  TFile* cur_cb_file = TFile::Open(cb_file_name.c_str(),"READ");

  TH1F* cb_hists[NGmass];
  char cb_name[200];
  //string cb_string = channel+"_"+cur_sys+"_m%i_cb_lep_nu_dijet_m";
  string cb_string = "cb_rsg_m%i_kMpl0_1";
  for(int i=0;i<NGmass;i++){
    sprintf(cb_name,cb_string.c_str(),GmassInt[i]);
    cb_hists[i] = (TH1F*) cur_cb_file->Get(cb_name);
    cb_hists[i]->SetDirectory(0);
  }
  
  // string cb_m500_hist_name = channel+"_"+cur_sys+"_m500_cb_lep_nu_dijet_m";
  // TH1F* cb_m500_hist = (TH1F*) cur_cb_file->Get(cb_m500_hist_name.c_str());
  // cb_m500_hist->SetDirectory(0);
  
  // string cb_m750_hist_name = channel+"_"+cur_sys+"_m750_cb_lep_nu_dijet_m";
  // TH1F* cb_m750_hist = (TH1F*) cur_cb_file->Get(cb_m750_hist_name.c_str());
  // cb_m750_hist->SetDirectory(0);

  // string cb_m1000_hist_name = channel+"_"+cur_sys+"_m1000_cb_lep_nu_dijet_m";
  // TH1F* cb_m1000_hist = (TH1F*) cur_cb_file->Get(cb_m1000_hist_name.c_str());
  // cb_m1000_hist->SetDirectory(0);
  
  // string cb_m1250_hist_name = channel+"_"+cur_sys+"_m1250_cb_lep_nu_dijet_m";
  // TH1F* cb_m1250_hist = (TH1F*) cur_cb_file->Get(cb_m1250_hist_name.c_str());
  // cb_m1250_hist->SetDirectory(0);
  
  // string cb_m1500_hist_name = channel+"_"+cur_sys+"_m1500_cb_lep_nu_dijet_m";
  // TH1F* cb_m1500_hist = (TH1F*) cur_cb_file->Get(cb_m1500_hist_name.c_str());
  // cb_m1500_hist->SetDirectory(0);
  
  cur_cb_file->Close();
  

  // Get Signal histograms
  string signal_m500_file_name =
    "../../plots/systematics_plots/merged/mc.gww.lvjj.m500.kmpl0_1.systematics.plot.root";
  TFile* cur_signal_m500_file = TFile::Open(signal_m500_file_name.c_str(),"READ");
  
  string signal_m500_hist_name = (channel=="evjj") ?
    "h_el_"+cur_sys+"_highm_lep_nu_dijet_m" :
    "h_mu_"+cur_sys+"_highm_lep_nu_dijet_m";
  
  TH1F* signal_m500_hist = (TH1F*) cur_signal_m500_file->Get(signal_m500_hist_name.c_str());
  signal_m500_hist->SetDirectory(0);
  cur_signal_m500_file->Close();

  //m750
  string signal_m750_file_name =
    "../../plots/systematics_plots/merged/mc.gww.lvjj.m750.kmpl0_1.systematics.plot.root";
  TFile* cur_signal_m750_file = TFile::Open(signal_m750_file_name.c_str(),"READ");
  
  string signal_m750_hist_name = (channel=="evjj") ?
    "h_el_"+cur_sys+"_highm_lep_nu_dijet_m" :
    "h_mu_"+cur_sys+"_highm_lep_nu_dijet_m";
  
  TH1F* signal_m750_hist = (TH1F*) cur_signal_m750_file->Get(signal_m750_hist_name.c_str());
  signal_m750_hist->SetDirectory(0);
  cur_signal_m750_file->Close();


  //m1000
  string signal_m1000_file_name =
    "../../plots/systematics_plots/merged/mc.gww.lvjj.m1000.kmpl0_1.systematics.plot.root";
  TFile* cur_signal_m1000_file = TFile::Open(signal_m1000_file_name.c_str(),"READ");
  
  string signal_m1000_hist_name = (channel=="evjj") ?
    "h_el_"+cur_sys+"_highm_lep_nu_dijet_m" :
    "h_mu_"+cur_sys+"_highm_lep_nu_dijet_m";
  
  TH1F* signal_m1000_hist = (TH1F*) cur_signal_m1000_file->Get(signal_m1000_hist_name.c_str());
  signal_m1000_hist->SetDirectory(0);
  cur_signal_m1000_file->Close();

  //m1250
  string signal_m1250_file_name =
    "../../plots/systematics_plots/merged/mc.gww.lvjj.m1250.kmpl0_1.systematics.plot.root";
  TFile* cur_signal_m1250_file = TFile::Open(signal_m1250_file_name.c_str(),"READ");
  
  string signal_m1250_hist_name = (channel=="evjj") ?
    "h_el_"+cur_sys+"_highm_lep_nu_dijet_m" :
    "h_mu_"+cur_sys+"_highm_lep_nu_dijet_m";
  
  TH1F* signal_m1250_hist = (TH1F*) cur_signal_m1250_file->Get(signal_m1250_hist_name.c_str());
  signal_m1250_hist->SetDirectory(0);
  cur_signal_m1250_file->Close();


  //m1500
  string signal_m1500_file_name =
    "../../plots/systematics_plots/merged/mc.gww.lvjj.m1500.kmpl0_1.systematics.plot.root";
  TFile* cur_signal_m1500_file = TFile::Open(signal_m1500_file_name.c_str(),"READ");
  
  string signal_m1500_hist_name = (channel=="evjj") ?
    "h_el_"+cur_sys+"_highm_lep_nu_dijet_m" :
    "h_mu_"+cur_sys+"_highm_lep_nu_dijet_m";
  
  TH1F* signal_m1500_hist = (TH1F*) cur_signal_m1500_file->Get(signal_m1500_hist_name.c_str());
  signal_m1500_hist->SetDirectory(0);
  cur_signal_m1500_file->Close();

  //////////////////////////////////////////////////
  // Make Plots
  ////////////////////////////////////////////////// 

  //m500
  string tc_m500_closure_name = channel+"_"+cur_sys+"_m500_closure";
  TCanvas* c_m500_closure =
    new TCanvas(tc_m500_closure_name.c_str(),"m500 Signal and Template histos",200,10,700,500);
  c_m500_closure->cd();

  signal_m500_hist->Rebin(4);
  signal_m500_hist->GetXaxis()->SetRangeUser(200,800);
  signal_m500_hist->SetMarkerSize(0.8);
  signal_m500_hist->Draw();

  cb_hists[0]->SetMarkerSize(0.8);
  cb_hists[0]->SetMarkerColor(kBlue);
  cb_hists[0]->SetLineColor(kBlue);
  cb_hists[0]->Draw("same");

  //c_m500_closure->SetLogy();
  c_m500_closure->Update();
  
  TLegend *lgnd_m500 = new TLegend(0.69,0.73,0.9,0.87);
  lgnd_m500->SetFillColor(kWhite);
  lgnd_m500->SetLineColor(kWhite);
  lgnd_m500->AddEntry(signal_m500_hist,"Signal", "P");
  lgnd_m500->AddEntry(cb_hists[0],"Crystal Ball","P");
  lgnd_m500->Draw();

  string tmp_saveas = "../plots/closure_plots/"+channel+"_"+cur_sys+"_m500_closure.pdf";
  c_m500_closure->SaveAs(tmp_saveas.c_str());


  //m750
  string tc_m750_closure_name = channel+"_"+cur_sys+"_m750_closure";
  TCanvas* c_m750_closure =
    new TCanvas(tc_m750_closure_name.c_str(),"m750 Signal and Template histos",200,10,700,500);
  c_m750_closure->cd();

  signal_m750_hist->Rebin(4);
  signal_m750_hist->GetXaxis()->SetRangeUser(400,1200);
  signal_m750_hist->SetMarkerSize(0.8);
  signal_m750_hist->Draw();

  cb_hists[5]->SetMarkerSize(0.8);
  cb_hists[5]->SetMarkerColor(kBlue);
  cb_hists[5]->SetLineColor(kBlue);
  cb_hists[5]->Draw("same");

  c_m750_closure->Update();
  
  TLegend *lgnd_m750 = new TLegend(0.25,0.73,0.46,0.87);
  lgnd_m750->SetFillColor(kWhite);
  lgnd_m750->SetLineColor(kWhite);
  lgnd_m750->AddEntry(signal_m750_hist,"Signal", "P");
  lgnd_m750->AddEntry(cb_hists[5],"Crystal Ball","P");
  lgnd_m750->Draw();

  tmp_saveas = "../plots/closure_plots/"+channel+"_"+cur_sys+"_m750_closure.pdf";
  c_m750_closure->SaveAs(tmp_saveas.c_str());


  //m1000
  string tc_m1000_closure_name = channel+"_"+cur_sys+"_m1000_closure";
  TCanvas* c_m1000_closure =
    new TCanvas(tc_m1000_closure_name.c_str(),"m1000 Signal and Template histos",200,10,700,500);
  c_m1000_closure->cd();

  signal_m1000_hist->Rebin(4);
  signal_m1000_hist->GetXaxis()->SetRangeUser(400,1600);
  signal_m1000_hist->SetMarkerSize(0.8);
  signal_m1000_hist->Draw();

  cb_hists[10]->SetMarkerSize(0.8);
  cb_hists[10]->SetMarkerColor(kBlue);
  cb_hists[10]->SetLineColor(kBlue);
  cb_hists[10]->Draw("same");

  c_m1000_closure->Update();
  
  TLegend *lgnd_m1000 = new TLegend(0.25,0.73,0.46,0.87);
  lgnd_m1000->SetFillColor(kWhite);
  lgnd_m1000->SetLineColor(kWhite);
  lgnd_m1000->AddEntry(signal_m1000_hist,"Signal", "P");
  lgnd_m1000->AddEntry(cb_hists[10],"Crystal Ball","P");
  lgnd_m1000->Draw();

  tmp_saveas = "../plots/closure_plots/"+channel+"_"+cur_sys+"_m1000_closure.pdf";
  c_m1000_closure->SaveAs(tmp_saveas.c_str());


  //m1250
  string tc_m1250_closure_name = channel+"_"+cur_sys+"_m1250_closure";
  TCanvas* c_m1250_closure =
    new TCanvas(tc_m1250_closure_name.c_str(),"m1250 Signal and Template histos",200,10,700,500);
  c_m1250_closure->cd();

  signal_m1250_hist->Rebin(4);
  signal_m1250_hist->GetXaxis()->SetRangeUser(400,2000);
  signal_m1250_hist->SetMarkerSize(0.8);
  signal_m1250_hist->Draw();

  cb_hists[15]->SetMarkerSize(0.8);
  cb_hists[15]->SetMarkerColor(kBlue);
  cb_hists[15]->SetLineColor(kBlue);
  cb_hists[15]->Draw("same");

  c_m1250_closure->Update();
  
  TLegend *lgnd_m1250 = new TLegend(0.25,0.73,0.46,0.87);
  lgnd_m1250->SetFillColor(kWhite);
  lgnd_m1250->SetLineColor(kWhite);
  lgnd_m1250->AddEntry(signal_m1250_hist,"Signal", "P");
  lgnd_m1250->AddEntry(cb_hists[15],"Crystal Ball","P");
  lgnd_m1250->Draw();

  tmp_saveas = "../plots/closure_plots/"+channel+"_"+cur_sys+"_m1250_closure.pdf";
  c_m1250_closure->SaveAs(tmp_saveas.c_str());


  //m1500
  string tc_m1500_closure_name = channel+"_"+cur_sys+"_m1500_closure";
  TCanvas* c_m1500_closure =
    new TCanvas(tc_m1500_closure_name.c_str(),"m1500 Signal and Template histos",200,10,700,500);
  c_m1500_closure->cd();

  signal_m1500_hist->Rebin(4);
  signal_m1500_hist->GetXaxis()->SetRangeUser(600,2000);
  signal_m1500_hist->SetMarkerSize(0.8);
  signal_m1500_hist->Draw();

  cb_hists[20]->SetMarkerSize(0.8);
  cb_hists[20]->SetMarkerColor(kBlue);
  cb_hists[20]->SetLineColor(kBlue);
  cb_hists[20]->Draw("same");

  c_m1500_closure->Update();
  
  TLegend *lgnd_m1500 = new TLegend(0.25,0.73,0.46,0.87);
  lgnd_m1500->SetFillColor(kWhite);
  lgnd_m1500->SetLineColor(kWhite);
  lgnd_m1500->AddEntry(signal_m1500_hist,"Signal", "P");
  lgnd_m1500->AddEntry(cb_hists[20],"Crystal Ball","P");
  lgnd_m1500->Draw();

  tmp_saveas = "../plots/closure_plots/"+channel+"_"+cur_sys+"_m1500_closure.pdf";
  c_m1500_closure->SaveAs(tmp_saveas.c_str());


  string c_template_plots_name = "c_"+channel+"_"+cur_sys+"_template_plots";
  TCanvas* c_template_plots =
    new TCanvas(c_template_plots_name.c_str(),"Template histos",200,10,700,500);
  //c_template_plots->cd();
  c_template_plots->Divide(6,4);

  for(int i=1;i<NGmass+1;i++){
    c_template_plots->cd(i);

    cb_hists[i-1]->SetLineColor(kBlack);
    cb_hists[i-1]->Draw("hist");

  }
  c_template_plots->Update();
  
  tmp_saveas = "../plots/template_plots/"+channel+"_"+cur_sys+"_template_plots.pdf";
  c_template_plots->SaveAs(tmp_saveas.c_str());
  

  if(cur_cb_file) delete cur_cb_file;  
  if(cur_signal_m500_file) delete cur_signal_m500_file;
  if(cur_signal_m750_file) delete cur_signal_m750_file;
  if(cur_signal_m1000_file) delete cur_signal_m1000_file;
  if(cur_signal_m1250_file) delete cur_signal_m1250_file;
  if(cur_signal_m1500_file) delete cur_signal_m1500_file;

  
}
