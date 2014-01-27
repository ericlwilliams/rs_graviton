#define signalShapesWprime_cxx
#include "signalShapesWprime.h"

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

const float rebin_n=16; //16-> 80 GeV Bins
//const float rebin_n=32; //32-> 160 GeV Bins
//const float rebin_n=64; //32-> 320 GeV Bins

const int n_bins=576;
const double integral_frac_cut=0.0015;

const int NGmass  = 31;
int GmassInt[NGmass] =
  {500,550,600,650,700,750,800,850,900,950,1000,
   1050,1100,1150,1200,1250,1300,1350,1400,1450,
   1500,1550,1600,1650,1700,1750,1800,1850,1900,1950,2000};

string file_loc = "/Users/elw/Dropbox/eMacs/analy/lvjj/plots/systematics_plots/merged/";

const double wprime_xsecs[NGmass] =
  {1.2, 0.81,0.55, 0.39, 0.27, 0.2,0.15, 0.11, 0.082,  0.062, 0.048, 0.038, 0.03, 0.023, 0.019, 0.015, 0.012, 0.0098, 0.008, 0.0065, 0.0053,0.004316, 0.003523, 0.00298, 0.002398, 0.002033, 0.001725, 0.001365,0.001118, 0.0009884, 0.0008129};
  


// const double wprime_xsecs[NGmass] =
//   {1.15, 0.765,0.538, 0.378, 0.262, 0.192,0.144, 0.108, 0.0825,  0.065, 0.04905, 0.03822, 0.02971, 0.02379, 0.0188, 0.01544, 0.01159, 0.009935, 0.007775, 0.006477, 0.005413};


const double signal_evt_n = 10000;

signalShapesWprime::signalShapesWprime(){

  SetAtlasStyle();
  gROOT->SetBatch();
}


void signalShapesWprime::makeSignalParameterFits(string channel/*="evjj"*/,string cur_sys/*="jes_nom"*/){
  //gROOT->SetBatch();
  const int n_sig_masses=11;
  double initial_mass1 = 500.0; 
  double initial_mass2 = 600.0; 
  double initial_mass3 = 700.0; 
  double initial_mass4 = 800.0; 
  double initial_mass5 = 900.0; 
  double initial_mass6 = 1000.0; 
  double initial_mass7 = 1100.0; 
  double initial_mass8 = 1200.0; 
  double initial_mass9 = 1300.0; 
  double initial_mass10 = 1400.0;
  double initial_mass11 = 1500.0; 
  
  int signal_masses_int[n_sig_masses] = {500,600,700,800,900,1000,1100,1200,1300,1400,1500};
  string signal_file_name = file_loc+"mc.wprime.wz.m%i.systematics.plot.root";


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
  // double cross_section[n_sig_masses];
  // cross_section[0] = 0.665771 ;//500
  // cross_section[1] = 0.309849;//600
  // cross_section[2] = 0.15407;  //700
  // cross_section[3] = 0.0837345; //800
  // cross_section[4] = 0.0486112;  //900
  // cross_section[5] = 0.0281449;  //1000
  // cross_section[6] = 0.0144956;  //1100
  // cross_section[7] = 0.00565906;  //1200
  // cross_section[8] = 0.00136325;  //1300
  // cross_section[9] = 0.000157593;  //1400
  // cross_section[10] = 0.00000649526;  //1500

  Double_t CrossSection_m500 = wprime_xsecs[0];
  Double_t CrossSection_m550 = wprime_xsecs[1];
  Double_t CrossSection_m600 = wprime_xsecs[2];
  Double_t CrossSection_m650 = wprime_xsecs[3];
  Double_t CrossSection_m700 = wprime_xsecs[4];
  Double_t CrossSection_m750 = wprime_xsecs[5];
  Double_t CrossSection_m800 = wprime_xsecs[6];
  Double_t CrossSection_m850 = wprime_xsecs[7];
  Double_t CrossSection_m900 = wprime_xsecs[8];
  Double_t CrossSection_m950 = wprime_xsecs[9];
  Double_t CrossSection_m1000 = wprime_xsecs[10];
  Double_t CrossSection_m1050 = wprime_xsecs[11];
  Double_t CrossSection_m1100 = wprime_xsecs[12];
  Double_t CrossSection_m1150 = wprime_xsecs[13];
  Double_t CrossSection_m1200 = wprime_xsecs[14];
  Double_t CrossSection_m1250 = wprime_xsecs[15];
  Double_t CrossSection_m1300 = wprime_xsecs[16];
  Double_t CrossSection_m1350 = wprime_xsecs[17];
  Double_t CrossSection_m1400 = wprime_xsecs[18];
  Double_t CrossSection_m1450 = wprime_xsecs[19];
  Double_t CrossSection_m1500 = wprime_xsecs[20];
  Double_t CrossSection_m1550 = wprime_xsecs[21];
  Double_t CrossSection_m1600 = wprime_xsecs[22];
  Double_t CrossSection_m1650 = wprime_xsecs[23];
  Double_t CrossSection_m1700 = wprime_xsecs[24];
  Double_t CrossSection_m1750 = wprime_xsecs[25];
  Double_t CrossSection_m1800 = wprime_xsecs[26];
  Double_t CrossSection_m1850 = wprime_xsecs[27];
  Double_t CrossSection_m1900 = wprime_xsecs[28];
  Double_t CrossSection_m1950 = wprime_xsecs[29];
  Double_t CrossSection_m2000 = wprime_xsecs[30];
  
  
  for(int j=0;j<n_sig_masses;j++)
    h_signal_hist[j]->SetDirectory(gDirectory);

  // --- Observable ---
  RooRealVar Mass("Mass","Mass(lvjj) (GeV)",0,2880);
  //RooPlot * Fitframe = Mass.frame(); 
  RooPlot * m500frame = Mass.frame(200,800);
  RooPlot * m600frame = Mass.frame(200,900);
  RooPlot * m700frame = Mass.frame(300,1000);
  RooPlot * m800frame = Mass.frame(400,1200);
  RooPlot * m900frame = Mass.frame(400,1250);
  RooPlot * m1000frame = Mass.frame(400,1400);
  RooPlot * m1100frame = Mass.frame(400,1500);
  RooPlot * m1200frame = Mass.frame(400,1600);
  RooPlot * m1300frame = Mass.frame(500,1650);
  RooPlot * m1400frame = Mass.frame(500,1800);
  RooPlot * m1500frame = Mass.frame(600,1900);

    
  // --- Defining Variables in Crystal Ball --- 
  RooRealVar cb_mean1("cb_mean1","Mean of the Gaussian half of the Crystal Ball", initial_mass1, 0, 1000);
  RooRealVar cb_sigma1("cb_sigma1","Sigma of the Gaussian half of the Crystal Ball", 35.0, 15.0, 100.0);
  RooRealVar cb_a1("cb_a1","Delimiting Value", 1., 0.01, 50.0);
  RooRealVar cb_n1("cb_n1","Exponentiating Form", 2.0);//, 0.001, 100.0);

  //600
  RooRealVar cb_mean2("cb_mean2","Mean of the Gaussian half of the Crystal Ball",initial_mass2, 100, 1100);
  RooRealVar cb_sigma2("cb_sigma2","Sigma of the Gaussian half of the Crystal Ball", 40.0, 0.1, 100.0);
  RooRealVar cb_a2("cb_a2","Delimiting Value", 1.0, 0.01, 50.0);
  RooRealVar cb_n2("cb_n2","Exponentiating Form", 2.0);//, 0.001, 100.0);
  
  //700
  RooRealVar cb_mean3("cb_mean3","Mean of the Gaussian half of the Crystal Ball",initial_mass3,200, 1200);
  RooRealVar cb_sigma3("cb_sigma3","Sigma of the Gaussian half of the Crystal Ball", 70.0, 0.1, 140.0);
  RooRealVar cb_a3("cb_a3","Delimiting Value", 1.0, 0.01, 50.0);
  RooRealVar cb_n3("cb_n3","Exponentiating Form", 2.0);//, 0.001, 100.0);

  //800
  RooRealVar cb_mean4("cb_mean4","Mean of the Gaussian half of the Crystal Ball",initial_mass4, 300, 1300);
 RooRealVar cb_sigma4("cb_sigma4","Sigma of the Gaussian half of the Crystal Ball", 80.0, 0.1, 180.0);
 RooRealVar cb_a4("cb_a4","Delimiting Value", 1.0, 0.01, 50.0);
  RooRealVar cb_n4("cb_n4","Exponentiating Form", 2.0);//, 0.001, 100.0);

  //900
  RooRealVar cb_mean5("cb_mean5","Mean of the Gaussian half of the Crystal Ball",initial_mass5, 400, 1400);
  RooRealVar cb_sigma5("cb_sigma5","Sigma of the Gaussian half of the Crystal Ball", 100.0, 0.1, 300.0);
  RooRealVar cb_a5("cb_a5","Delimiting Value", 1.0, 0.01, 50.0);
  RooRealVar cb_n5("cb_n5","Exponentiating Form", 2.0);//, 0.001, 100.0);
    
  //1000
  RooRealVar cb_mean6("cb_mean6","Mean of the Gaussian half of the Crystal Ball",initial_mass6, 500, 1500);
  RooRealVar cb_sigma6("cb_sigma6","Sigma of the Gaussian half of the Crystal Ball", 110.0, 0.1, 300.0);
  RooRealVar cb_a6("cb_a6","Delimiting Value", 1.0, 0.01, 50.0);
  RooRealVar cb_n6("cb_n6","Exponentiating Form", 2.0);//, 0.001, 100.0);

  //1100
  RooRealVar cb_mean7("cb_mean7","Mean of the Gaussian half of the Crystal Ball",initial_mass7, 600, 1600);
  RooRealVar cb_sigma7("cb_sigma7","Sigma of the Gaussian half of the Crystal Ball", 130.0, 0.1, 300.0);
  RooRealVar cb_a7("cb_a7","Delimiting Value", 1.0, 0.01, 50.0);
  RooRealVar cb_n7("cb_n7","Exponentiating Form", 2.0);//, 0.001, 100.0);
    
  //1200
  RooRealVar cb_mean8("cb_mean8","Mean of the Gaussian half of the Crystal Ball",initial_mass8, 700, 1700);
  RooRealVar cb_sigma8("cb_sigma8","Sigma of the Gaussian half of the Crystal Ball", 160.0, 0.1, 300.0);
  RooRealVar cb_a8("cb_a8","Delimiting Value", 1.0, 0.01, 50.0);
  RooRealVar cb_n8("cb_n8","Exponentiating Form", 2.0);//, 0.001, 100.0);
    
  //1300
  RooRealVar cb_mean9("cb_mean9","Mean of the Gaussian half of the Crystal Ball",initial_mass9, 800, 1800);
  RooRealVar cb_sigma9("cb_sigma9","Sigma of the Gaussian half of the Crystal Ball", 180.0, 0.1, 300.0);
  RooRealVar cb_a9("cb_a9","Delimiting Value", 1.0, 0.01, 50.0);
  RooRealVar cb_n9("cb_n9","Exponentiating Form", 2.0);//, 0.001, 100.0);

  //1400
  RooRealVar cb_mean10("cb_mean10","Mean of the Gaussian half of the Crystal Ball",initial_mass10, 900, 1900);
  RooRealVar cb_sigma10("cb_sigma10","Sigma of the Gaussian half of the Crystal Ball", 190.0, 0.1, 300.0);
  RooRealVar cb_a10("cb_a10","Delimiting Value", 1.0, 0.01, 50.0);
  RooRealVar cb_n10("cb_n10","Exponentiating Form", 2.0);//, 0.001, 100.0);
    
  //1500
  RooRealVar cb_mean11("cb_mean11","Mean of the Gaussian half of the Crystal Ball",initial_mass11, 1000, 2000);
  RooRealVar cb_sigma11("cb_sigma11","Sigma of the Gaussian half of the Crystal Ball", 220.0, 0.1, 350.0);
  RooRealVar cb_a11("cb_a11","Delimiting Value", 1.0, 0.01, 50.0);
  RooRealVar cb_n11("cb_n11","Exponentiating Form", 2.0);//, 0.001, 100.0);
    

  // --- Defining the fit function, i.e. The Crystal Ball
  RooCBShape CrystalBall1("CrystalBall1","Crystal Ball Fit to Signal Resonance",Mass,cb_mean1,cb_sigma1,cb_a1,cb_n1);
  RooCBShape CrystalBall2("CrystalBall2","Crystal Ball Fit to Signal Resonance",Mass,cb_mean2,cb_sigma2,cb_a2,cb_n2);
  RooCBShape CrystalBall3("CrystalBall3","Crystal Ball Fit to Signal Resonance",Mass,cb_mean3,cb_sigma3,cb_a3,cb_n3);
  RooCBShape CrystalBall4("CrystalBall4","Crystal Ball Fit to Signal Resonance",Mass,cb_mean4,cb_sigma4,cb_a4,cb_n4);
  RooCBShape CrystalBall5("CrystalBall5","Crystal Ball Fit to Signal Resonance",Mass,cb_mean5,cb_sigma5,cb_a5,cb_n5);
  RooCBShape CrystalBall6("CrystalBall6","Crystal Ball Fit to Signal Resonance",Mass,cb_mean6,cb_sigma6,cb_a6,cb_n6);
  RooCBShape CrystalBall7("CrystalBall7","Crystal Ball Fit to Signal Resonance",Mass,cb_mean7,cb_sigma7,cb_a7,cb_n7);
  RooCBShape CrystalBall8("CrystalBall8","Crystal Ball Fit to Signal Resonance",Mass,cb_mean8,cb_sigma8,cb_a8,cb_n8);
  RooCBShape CrystalBall9("CrystalBall9","Crystal Ball Fit to Signal Resonance",Mass,cb_mean9,cb_sigma9,cb_a9,cb_n9);
  RooCBShape CrystalBall10("CrystalBall10","Crystal Ball Fit to Signal Resonance",Mass,cb_mean10,cb_sigma10,cb_a10,cb_n10);
  RooCBShape CrystalBall11("CrystalBall11","Crystal Ball Fit to Signal Resonance",Mass,cb_mean11,cb_sigma11,cb_a11,cb_n11);
  
  //Total number of events in channel
  Double_t Total_Channel_m500 = 0;
  Double_t Total_Channel_m600 = 0;
  Double_t Total_Channel_m700 = 0;
  Double_t Total_Channel_m800 = 0;
  Double_t Total_Channel_m900 = 0;
  Double_t Total_Channel_m1000 = 0;
  Double_t Total_Channel_m1100 = 0;
  Double_t Total_Channel_m1200 = 0;
  Double_t Total_Channel_m1300 = 0;
  Double_t Total_Channel_m1400 = 0;
  Double_t Total_Channel_m1500 = 0;


  Double_t Acceptance_m500 = h_signal_hist[0]->GetEntries()/signal_evt_n;
  Double_t Acceptance_m600 = h_signal_hist[1]->GetEntries()/signal_evt_n;   
  Double_t Acceptance_m700 = h_signal_hist[2]->GetEntries()/signal_evt_n;   
  Double_t Acceptance_m800 = h_signal_hist[3]->GetEntries()/signal_evt_n;   
  Double_t Acceptance_m900 = h_signal_hist[4]->GetEntries()/signal_evt_n;
  Double_t Acceptance_m1000 = h_signal_hist[5]->GetEntries()/signal_evt_n;
  Double_t Acceptance_m1100 = h_signal_hist[6]->GetEntries()/signal_evt_n;
  Double_t Acceptance_m1200 = h_signal_hist[7]->GetEntries()/signal_evt_n;
  Double_t Acceptance_m1300 = h_signal_hist[8]->GetEntries()/signal_evt_n;
  Double_t Acceptance_m1400 = h_signal_hist[9]->GetEntries()/signal_evt_n;
  Double_t Acceptance_m1500 = h_signal_hist[10]->GetEntries()/signal_evt_n;

  Double_t Integral_m500 = h_signal_hist[0]->Integral();
  Double_t Integral_m600 = h_signal_hist[1]->Integral();   
  Double_t Integral_m700 = h_signal_hist[2]->Integral();   
  Double_t Integral_m800 = h_signal_hist[3]->Integral();   
  Double_t Integral_m900 = h_signal_hist[4]->Integral();
  Double_t Integral_m1000 = h_signal_hist[5]->Integral();
  Double_t Integral_m1100 = h_signal_hist[6]->Integral();
  Double_t Integral_m1200 = h_signal_hist[7]->Integral();
  Double_t Integral_m1300 = h_signal_hist[8]->Integral();
  Double_t Integral_m1400 = h_signal_hist[9]->Integral();
  Double_t Integral_m1500 = h_signal_hist[10]->Integral();  
  

  
  Total_Channel_m500 = Total_Lumi*wprime_xsecs[0]*Acceptance_m500;
  Total_Channel_m600 = Total_Lumi*wprime_xsecs[2]*Acceptance_m600;
  Total_Channel_m700 = Total_Lumi*wprime_xsecs[4]*Acceptance_m700;
  Total_Channel_m800 = Total_Lumi*wprime_xsecs[6]*Acceptance_m800;
  Total_Channel_m900 = Total_Lumi*wprime_xsecs[8]*Acceptance_m900;
  Total_Channel_m1000 = Total_Lumi*wprime_xsecs[10]*Acceptance_m1000;
  Total_Channel_m1100 = Total_Lumi*wprime_xsecs[12]*Acceptance_m1100;
  Total_Channel_m1200 = Total_Lumi*wprime_xsecs[14]*Acceptance_m1200;
  Total_Channel_m1300 = Total_Lumi*wprime_xsecs[16]*Acceptance_m1300;
  Total_Channel_m1400 = Total_Lumi*wprime_xsecs[18]*Acceptance_m1400;
  Total_Channel_m1500 = Total_Lumi*wprime_xsecs[20]*Acceptance_m1500;

  // --- Define Channel Acceptance --- 
  Double_t Channel_Acceptance_m500 = Acceptance_m500*(Integral_m500/Total_Channel_m500);
  Double_t Channel_Acceptance_m600 = Acceptance_m600*(Integral_m600/Total_Channel_m600);
  Double_t Channel_Acceptance_m700 = Acceptance_m700*(Integral_m700/Total_Channel_m700);
  Double_t Channel_Acceptance_m800 = Acceptance_m800*(Integral_m800/Total_Channel_m800);
  Double_t Channel_Acceptance_m900 = Acceptance_m900*(Integral_m900/Total_Channel_m900);
  Double_t Channel_Acceptance_m1000 = Acceptance_m1000*(Integral_m1000/Total_Channel_m1000);
  Double_t Channel_Acceptance_m1100 = Acceptance_m1100*(Integral_m1100/Total_Channel_m1100);
  Double_t Channel_Acceptance_m1200 = Acceptance_m1200*(Integral_m1200/Total_Channel_m1200);
  Double_t Channel_Acceptance_m1300 = Acceptance_m1300*(Integral_m1300/Total_Channel_m1300);
  Double_t Channel_Acceptance_m1400 = Acceptance_m1400*(Integral_m1400/Total_Channel_m1400);
  Double_t Channel_Acceptance_m1500 = Acceptance_m1500*(Integral_m1500/Total_Channel_m1500);

  string out_file_loc = "../wprime_files/"+channel+"_cb_"+cur_sys+"_lep_nu_dijet_m.root";
  TFile* CrystalBallFits = new TFile(out_file_loc.c_str(), "RECREATE");
  CrystalBallFits->cd();

  RooDataHist signal_m500("signal_m500","W' signal", Mass, h_signal_hist[0]);
  RooDataHist signal_m600("signal_m600","W' signal", Mass, h_signal_hist[1]);
  RooDataHist signal_m700("signal_m700","W' signal", Mass, h_signal_hist[2]);
  RooDataHist signal_m800("signal_m800","W' signal", Mass, h_signal_hist[3]);
  RooDataHist signal_m900("signal_m900","W' signal", Mass, h_signal_hist[4]);
  RooDataHist signal_m1000("signal_m1000","W' signal", Mass, h_signal_hist[5]);
  RooDataHist signal_m1100("signal_m1100","W' signal", Mass, h_signal_hist[6]);
  RooDataHist signal_m1200("signal_m1200","W' signal", Mass, h_signal_hist[7]);
  RooDataHist signal_m1300("signal_m1300","W' signal", Mass, h_signal_hist[8]);
    h_signal_hist[9]->Rebin(2);
  RooDataHist signal_m1400("signal_m1400","W' signal", Mass, h_signal_hist[9]);
  h_signal_hist[10]->Rebin(2);
  RooDataHist signal_m1500("signal_m1500","W' signal", Mass, h_signal_hist[10]);


  // --- Fitting CrystalBall to Signal Shape ---
  RooRealVar MASS("Mass","Mass(lvjj) (GeV)", 0., 2880.);

  string hist_name = channel+"_"+cur_sys+"_";
  TH1 * Hist_m500 = MASS.createHistogram("Signal m500", Binning(n_bins));
  string hist_m500_name = "cb_wprime_m500";
  Hist_m500->SetName(hist_m500_name.c_str());
  TH1 * Hist_m600 = MASS.createHistogram("Signal m600", Binning(n_bins));
  string hist_m600_name = "cb_wprime_m600";
  Hist_m600->SetName(hist_m600_name.c_str());
  TH1 * Hist_m700 = MASS.createHistogram("Signal m700", Binning(n_bins));
  string hist_m700_name = "cb_wprime_m700";
  Hist_m700->SetName(hist_m700_name.c_str());
  TH1 * Hist_m800 = MASS.createHistogram("Signal m800", Binning(n_bins));
  string hist_m800_name = "cb_wprime_m800";
  Hist_m800->SetName(hist_m800_name.c_str());
  TH1 * Hist_m900 = MASS.createHistogram("Signal m900", Binning(n_bins));
  string hist_m900_name = "cb_wprime_m900";
  Hist_m900->SetName(hist_m900_name.c_str());
  TH1 * Hist_m1000 = MASS.createHistogram("Signal m1000", Binning(n_bins));
  string hist_m1000_name = "cb_wprime_m1000";
  Hist_m1000->SetName(hist_m1000_name.c_str());
  TH1 * Hist_m1100 = MASS.createHistogram("Signal m1100", Binning(n_bins));
  string hist_m1100_name = "cb_wprime_m1100";
  Hist_m1100->SetName(hist_m1100_name.c_str());
  TH1 * Hist_m1200 = MASS.createHistogram("Signal m1200", Binning(n_bins));
  string hist_m1200_name = "cb_wprime_m1200";
  Hist_m1200->SetName(hist_m1200_name.c_str());
  TH1 * Hist_m1300 = MASS.createHistogram("Signal m1300", Binning(n_bins));
  string hist_m1300_name = "cb_wprime_m1300";
  Hist_m1300->SetName(hist_m1300_name.c_str());
  TH1 * Hist_m1400 = MASS.createHistogram("Signal m1400", Binning(n_bins));
  string hist_m1400_name = "cb_wprime_m1400";
  Hist_m1400->SetName(hist_m1400_name.c_str());
  TH1 * Hist_m1500 = MASS.createHistogram("Signal m1500", Binning(n_bins));
  string hist_m1500_name = "cb_wprime_m1500";
  Hist_m1500->SetName(hist_m1500_name.c_str());

  
  CrystalBall1.fitTo(signal_m500,Range(400,625));
  CrystalBall1.fillHistogram(Hist_m500,RooArgList(MASS));

  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m500->Integral(1,i)/Hist_m500->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m500->SetBinContent(i,0.);
  }
  Hist_m500->Scale(1./Hist_m500->Integral());

  CrystalBall2.fitTo(signal_m600,Range(450,800));
  CrystalBall2.fillHistogram(Hist_m600,RooArgList(MASS));

  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m600->Integral(1,i)/Hist_m600->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m600->SetBinContent(i,0.);
  }
  Hist_m600->Scale(1./Hist_m600->Integral());

  CrystalBall3.fitTo(signal_m700,Range(500,900));
  CrystalBall3.fillHistogram(Hist_m700,RooArgList(MASS));

  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m700->Integral(1,i)/Hist_m700->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m700->SetBinContent(i,0.);
  }
  Hist_m700->Scale(1./Hist_m700->Integral());
 
  CrystalBall4.fitTo(signal_m800,Range(600,950));
  CrystalBall4.fillHistogram(Hist_m800,RooArgList(MASS));

  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m800->Integral(1,i)/Hist_m800->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m800->SetBinContent(i,0.);
  }
  Hist_m800->Scale(1./Hist_m800->Integral());

  CrystalBall5.fitTo(signal_m900,Range(600,1100));
  CrystalBall5.fillHistogram(Hist_m900,RooArgList(MASS));

  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m900->Integral(1,i)/Hist_m900->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m900->SetBinContent(i,0.);
  }
  Hist_m900->Scale(1./Hist_m900->Integral());

  CrystalBall6.fitTo(signal_m1000,Range(650,1200));
  CrystalBall6.fillHistogram(Hist_m1000,RooArgList(MASS));

  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m1000->Integral(1,i)/Hist_m1000->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m1000->SetBinContent(i,0.);
  }
  Hist_m1000->Scale(1./Hist_m1000->Integral());

  CrystalBall7.fitTo(signal_m1100,Range(650,1300));
  CrystalBall7.fillHistogram(Hist_m1100,RooArgList(MASS));

  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m1100->Integral(1,i)/Hist_m1100->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m1100->SetBinContent(i,0.);
  }
  Hist_m1100->Scale(1./Hist_m1100->Integral());

  //CrystalBall8.fitTo(signal_m1200,Range(700,1400));
  CrystalBall8.fitTo(signal_m1200,Range(600,1500));
  CrystalBall8.fillHistogram(Hist_m1200,RooArgList(MASS));

  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m1200->Integral(1,i)/Hist_m1200->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m1200->SetBinContent(i,0.);
  }
  Hist_m1200->Scale(1./Hist_m1200->Integral());

  CrystalBall9.fitTo(signal_m1300,Range(800,1500));
  CrystalBall9.fillHistogram(Hist_m1300,RooArgList(MASS));

  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m1300->Integral(1,i)/Hist_m1300->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m1300->SetBinContent(i,0.);
  }
  Hist_m1300->Scale(1./Hist_m1300->Integral());

  CrystalBall10.fitTo(signal_m1400,Range(800,1700));
  CrystalBall10.fillHistogram(Hist_m1400,RooArgList(MASS));

  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m1400->Integral(1,i)/Hist_m1400->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m1400->SetBinContent(i,0.);
  }
  Hist_m1400->Scale(1./Hist_m1400->Integral());

  CrystalBall11.fitTo(signal_m1500,Range(800,1800));
  CrystalBall11.fillHistogram(Hist_m1500,RooArgList(MASS));

  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m1500->Integral(1,i)/Hist_m1500->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m1500->SetBinContent(i,0.);
  }
  Hist_m1500->Scale(1./Hist_m1500->Integral());
  
  
  Double_t x[n_sig_masses];
  x[0] = 500.0;
  x[1] = 600.0;
  x[2] = 700.0;
  x[3] = 800.0;
  x[4] = 900.0;
  x[5] = 1000.0;
  x[6] = 1100.0;
  x[7] = 1200.0;
  x[8] = 1300.0;
  x[9] = 1400.0;
  x[10] = 1500.0;

  Double_t Y[n_sig_masses];
  Y[0] = Acceptance_m500;
  Y[1] = Acceptance_m600;
  Y[2] = Acceptance_m700;
  Y[3] = Acceptance_m800;
  Y[4] = Acceptance_m900;
  Y[5] = Acceptance_m1000;
  Y[6] = Acceptance_m1100;
  Y[7] = Acceptance_m1200;
  Y[8] = Acceptance_m1300;
  Y[9] = Acceptance_m1400;
  Y[10] = Acceptance_m1500;

  TCanvas *c_acc = new TCanvas("c_acc","Acceptances",200,10,500,500);
  TGraph * Accept = new TGraph(n_sig_masses,x,Y);
  Accept->SetTitle("");
  Accept->GetXaxis()->SetTitle("W' Mass [GeV]");
  Accept->GetYaxis()->SetTitle("Total Acceptance");
  Accept->Draw("AL*");
  Accept->SetLineColor(4);
  Accept->SetLineWidth(2);
  Accept->SetMarkerColor(4);
  Accept->SetMarkerStyle(22);
  string acc_saveas = "../wprime_plots/"+channel+"_"+cur_sys+"_signal_acceptances.pdf";
  c_acc->SaveAs(acc_saveas.c_str());
  

  Y[0] = Channel_Acceptance_m500;
  Y[1] = Channel_Acceptance_m600;
  Y[2] = Channel_Acceptance_m700;
  Y[3] = Channel_Acceptance_m800;
  Y[4] = Channel_Acceptance_m900;
  Y[5] = Channel_Acceptance_m1000;
  Y[6] = Channel_Acceptance_m1100;
  Y[7] = Channel_Acceptance_m1200;
  Y[8] = Channel_Acceptance_m1300;
  Y[9] = Channel_Acceptance_m1400;
  Y[10] = Channel_Acceptance_m1500;

  TCanvas *c_chan_acc = new TCanvas("c_chan_acc","Channel Acceptances",200,10,500,500);
  TGraph * Channel_Accept = new TGraph(n_sig_masses,x,Y);


  TF1* f1_acc_pol_fit = new TF1("f1_acc_pol_fit","pol3(0)",400,900);//[0]+[1]*x+[2]*x^2+[3]*x^3
  TF1* f1_acc_expo_fit = new TF1("f1_acc_expo_fit","expo(0)",895,1500);//
  //   f1_acc_fit->SetParameter(0,0.3);
  // f1_acc_fit->SetParameter(1,850);
  // f1_acc_fit->SetParameter(2,400);


  TFitResultPtr Channel_acc_pol_result = Channel_Accept->Fit(f1_acc_pol_fit, "SR0");
  // Double_t chn_acc_pol_p0 = Channel_acc_pol_result->Value(0);
  // Double_t chn_acc_pol_p1 = Channel_acc_pol_result->Value(1);
  // Double_t chn_acc_pol_p2 = Channel_acc_pol_result->Value(2);
  // Double_t chn_acc_pol_p3 = Channel_acc_pol_result->Value(3);
  // cout<<"expo fit"<<endl;
  TFitResultPtr Channel_acc_expo_result = Channel_Accept->Fit(f1_acc_expo_fit, "SR0");
  // Double_t chn_acc_expo_p0 = Channel_acc_expo_result->Value(0);
  //Double_t chn_acc_expo_p1 = Channel_acc_expo_result->Value(1);
  //Double_t chn_acc_expo_p2 = Channel_acc_expo_result->Value(2);

  Channel_Accept->SetTitle("");
  Channel_Accept->GetXaxis()->SetTitle("W' Mass [GeV]");
  Channel_Accept->GetYaxis()->SetTitle("Acceptance");
  Channel_Accept->Draw("A*");
  f1_acc_pol_fit->Draw("same");
  f1_acc_expo_fit->Draw("same");
  Channel_Accept->SetLineColor(4);
  Channel_Accept->SetLineWidth(2);
  Channel_Accept->SetMarkerColor(4);
  Channel_Accept->SetMarkerStyle(22);
  string chan_acc_saveas = "../wprime_plots/"+channel+"_"+cur_sys+"_signal_channel_acceptances.pdf";
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
  Mean[5] = cb_mean6.getVal();
  Mean[6] = cb_mean7.getVal();
  Mean[7] = cb_mean8.getVal();
  Mean[8] = cb_mean9.getVal();
  Mean[9] = cb_mean10.getVal();
  Mean[10] = cb_mean11.getVal();
  //cout << "Mean[0] " << Mean[0] << endl;

  Sigma[0] = cb_sigma1.getVal();
  Sigma[1] = cb_sigma2.getVal();
  Sigma[2] = cb_sigma3.getVal();
  Sigma[3] = cb_sigma4.getVal();
  Sigma[4] = cb_sigma5.getVal();
  Sigma[5] = cb_sigma6.getVal();
  Sigma[6] = cb_sigma7.getVal();
  Sigma[7] = cb_sigma8.getVal();
  Sigma[8] = cb_sigma9.getVal();
  Sigma[9] = cb_sigma10.getVal();
  Sigma[10] = cb_sigma11.getVal();
  //cout << "Sigma[0] " << Sigma[0] << endl;

  A[0] = cb_a1.getVal();
  A[1] = cb_a2.getVal();
  A[2] = cb_a3.getVal();
  A[3] = cb_a4.getVal();
  A[4] = cb_a5.getVal();
  A[5] = cb_a6.getVal();
  A[6] = cb_a7.getVal();
  A[7] = cb_a8.getVal();
  A[8] = cb_a9.getVal();
  A[9] = cb_a10.getVal();
  A[10] = cb_a11.getVal();
  // cout << "A[0] " << A[0] << ", "<<cb_a1.getVal()<<endl;
  // cout << "A[1] " << A[1] << ", "<<cb_a2.getVal()<<endl;
  
  N[0] = cb_n1.getVal();
  N[1] = cb_n2.getVal();
  N[2] = cb_n3.getVal();
  N[3] = cb_n4.getVal();
  N[4] = cb_n5.getVal();
  N[5] = cb_n6.getVal();
  N[6] = cb_n7.getVal();
  N[7] = cb_n8.getVal();
  N[8] = cb_n9.getVal();
  N[9] = cb_n10.getVal();
  N[10] = cb_n11.getVal();
  //cout << "N[0] " << N[0] << endl;

  Double_t xx[n_sig_masses]; 
  xx[0] = 500.;
  xx[1] = 600.;
  xx[2] = 700.;
  xx[3] = 800.;
  xx[4] = 900.;
  xx[5] = 1000.0;
  xx[6] = 1100.0;
  xx[7] = 1200.0;
  xx[8] = 1300.0;
  xx[9] = 1400.0;
  xx[10] = 1500.0;

  TGraph * gr_parameter_Mean = new TGraph(n_sig_masses,xx,Mean);
  TGraph * gr_parameter_Sigma = new TGraph(n_sig_masses,xx,Sigma);
  TGraph * gr_parameter_A = new TGraph(n_sig_masses,xx,A);
  TGraph * gr_parameter_N = new TGraph(n_sig_masses,xx,N);

  TF1 * sigma_fit = new TF1("sigma_fit", "[0]*sqrt([1]*(x-[2]))");
  sigma_fit->SetParameter(0,1);
  sigma_fit->SetParameter(1,1);
  sigma_fit->SetParameter(2,0);

  // TF1 * sigma_fit = new TF1("sigma_fit", "[0]+[1]*x");
  // sigma_fit->SetParameter(0,0);
  // sigma_fit->SetParameter(1,0.1);

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

  TFitResultPtr MEAN = gr_parameter_Mean->Fit("mean_fit", "S");
  TFitResultPtr SIGMA = gr_parameter_Sigma->Fit("sigma_fit", "S");
  TFitResultPtr A_res = gr_parameter_A->Fit("a_fit", "S");
  TFitResultPtr N_res =  gr_parameter_N->Fit("n_fit", "S");
  

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
  
  Double_t mass;
  const int n_template_masses=31;
  double template_masses[n_template_masses] =
    {500,550,600,650,700,750,800,850,900,950,
     1000,1050,1100,1150,1200,1250,1300,1350,1400,1450,1500,
     1550,1600,1650,1700,1750,1800,1850,1900,1950,2000};

  Double_t mean_template[n_template_masses]={0.};
  Double_t sigma_template[n_template_masses]={0.};
  Double_t a_template[n_template_masses]={0.};

  for(int i=0;i<n_template_masses;i++){
    mass = template_masses[i];
    mean_template[i]=(mean_p0 + mean_p1*mass);
    //sigma_template[i]=(sigma_p0 + sigma_p1*mass);
    sigma_template[i]=sigma_p0*sqrt(sigma_p1*(mass-sigma_p2));
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


  TH1 * Hist_m550 = MASS.createHistogram("Signal m550",Binning(n_bins)) ;
  string hist_m550_name = "cb_wprime_m550";
  Hist_m550->SetName(hist_m550_name.c_str());

  TH1 * Hist_m650 = MASS.createHistogram("Signal m650",Binning(n_bins)) ;
  string hist_m650_name = "cb_wprime_m650";
  Hist_m650->SetName(hist_m650_name.c_str());

  TH1 * Hist_m750 = MASS.createHistogram("Signal m750",Binning(n_bins)) ;
  string hist_m750_name = "cb_wprime_m750";
  Hist_m750->SetName(hist_m750_name.c_str());

  TH1 * Hist_m850 = MASS.createHistogram("Signal m850",Binning(n_bins)) ;
  string hist_m850_name = "cb_wprime_m850";
  Hist_m850->SetName(hist_m850_name.c_str());

  TH1 * Hist_m950 = MASS.createHistogram("Signal m950",Binning(n_bins)) ;
  string hist_m950_name = "cb_wprime_m950";
  Hist_m950->SetName(hist_m950_name.c_str());

  TH1 * Hist_m1050 = MASS.createHistogram("Signal m1050",Binning(n_bins)) ;
  string hist_m1050_name = "cb_wprime_m1050";
  Hist_m1050->SetName(hist_m1050_name.c_str());

  TH1 * Hist_m1150 = MASS.createHistogram("Signal m1150",Binning(n_bins)) ;
  string hist_m1150_name = "cb_wprime_m1150";
  Hist_m1150->SetName(hist_m1150_name.c_str());

  TH1 * Hist_m1250 = MASS.createHistogram("Signal m1250",Binning(n_bins)) ;
  string hist_m1250_name = "cb_wprime_m1250";
  Hist_m1250->SetName(hist_m1250_name.c_str());

  TH1 * Hist_m1350 = MASS.createHistogram("Signal m1350",Binning(n_bins)) ;
  string hist_m1350_name = "cb_wprime_m1350";
  Hist_m1350->SetName(hist_m1350_name.c_str());

  TH1 * Hist_m1450 = MASS.createHistogram("Signal m1450",Binning(n_bins)) ;
  string hist_m1450_name = "cb_wprime_m1450";
  Hist_m1450->SetName(hist_m1450_name.c_str());

  TH1 * Hist_m1550 = MASS.createHistogram("Signal m1550",Binning(n_bins)) ;
  string hist_m1550_name = "cb_wprime_m1550";
  Hist_m1550->SetName(hist_m1550_name.c_str());

  TH1 * Hist_m1600 = MASS.createHistogram("Signal m1600",Binning(n_bins)) ;
  string hist_m1600_name = "cb_wprime_m1600";
  Hist_m1600->SetName(hist_m1600_name.c_str());

  TH1 * Hist_m1650 = MASS.createHistogram("Signal m1650",Binning(n_bins)) ;
  string hist_m1650_name = "cb_wprime_m1650";
  Hist_m1650->SetName(hist_m1650_name.c_str());

  TH1 * Hist_m1700 = MASS.createHistogram("Signal m1700",Binning(n_bins)) ;
  string hist_m1700_name = "cb_wprime_m1700";
  Hist_m1700->SetName(hist_m1700_name.c_str());

  TH1 * Hist_m1750 = MASS.createHistogram("Signal m1750",Binning(n_bins)) ;
  string hist_m1750_name = "cb_wprime_m1750";
  Hist_m1750->SetName(hist_m1750_name.c_str());

  TH1 * Hist_m1800 = MASS.createHistogram("Signal m1800",Binning(n_bins)) ;
  string hist_m1800_name = "cb_wprime_m1800";
  Hist_m1800->SetName(hist_m1800_name.c_str());

  TH1 * Hist_m1850 = MASS.createHistogram("Signal m1850",Binning(n_bins)) ;
  string hist_m1850_name = "cb_wprime_m1850";
  Hist_m1850->SetName(hist_m1850_name.c_str());

  TH1 * Hist_m1900 = MASS.createHistogram("Signal m1900",Binning(n_bins)) ;
  string hist_m1900_name = "cb_wprime_m1900";
  Hist_m1900->SetName(hist_m1900_name.c_str());

  TH1 * Hist_m1950 = MASS.createHistogram("Signal m1950",Binning(n_bins)) ;
  string hist_m1950_name = "cb_wprime_m1950";
  Hist_m1950->SetName(hist_m1950_name.c_str());

  TH1 * Hist_m2000 = MASS.createHistogram("Signal m2000",Binning(n_bins)) ;
  string hist_m2000_name = "cb_wprime_m2000";
  Hist_m2000->SetName(hist_m2000_name.c_str());
  
  CrystalBall_m550.fillHistogram(Hist_m550,RooArgList(MASS));
  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m550->Integral(1,i)/Hist_m550->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m550->SetBinContent(i,0.);
  }
  Hist_m550->Scale(1./Hist_m550->Integral());

  CrystalBall_m650.fillHistogram(Hist_m650,RooArgList(MASS));
  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m650->Integral(1,i)/Hist_m650->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m650->SetBinContent(i,0.);
  }
  Hist_m650->Scale(1./Hist_m650->Integral());

  CrystalBall_m750.fillHistogram(Hist_m750,RooArgList(MASS));
  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m750->Integral(1,i)/Hist_m750->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m750->SetBinContent(i,0.);
  }
  Hist_m750->Scale(1./Hist_m750->Integral());

  CrystalBall_m850.fillHistogram(Hist_m850,RooArgList(MASS));
  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m850->Integral(1,i)/Hist_m850->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m850->SetBinContent(i,0.);
  }
  Hist_m850->Scale(1./Hist_m850->Integral());

  CrystalBall_m950.fillHistogram(Hist_m950,RooArgList(MASS));
  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m950->Integral(1,i)/Hist_m950->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m950->SetBinContent(i,0.);
  }
  Hist_m950->Scale(1./Hist_m950->Integral());

  CrystalBall_m1050.fillHistogram(Hist_m1050,RooArgList(MASS));
  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m1050->Integral(1,i)/Hist_m1050->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m1050->SetBinContent(i,0.);
  }
  Hist_m1050->Scale(1./Hist_m1050->Integral());

  CrystalBall_m1150.fillHistogram(Hist_m1150,RooArgList(MASS));
  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m1150->Integral(1,i)/Hist_m1150->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m1150->SetBinContent(i,0.);
  }
  Hist_m1150->Scale(1./Hist_m1150->Integral());

  CrystalBall_m1250.fillHistogram(Hist_m1250,RooArgList(MASS));
  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m1250->Integral(1,i)/Hist_m1250->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m1250->SetBinContent(i,0.);
  }
  Hist_m1250->Scale(1./Hist_m1250->Integral());

  CrystalBall_m1350.fillHistogram(Hist_m1350,RooArgList(MASS));
  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m1350->Integral(1,i)/Hist_m1350->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m1350->SetBinContent(i,0.);
  }
  Hist_m1350->Scale(1./Hist_m1350->Integral());

  CrystalBall_m1450.fillHistogram(Hist_m1450,RooArgList(MASS));
  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m1450->Integral(1,i)/Hist_m1450->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m1450->SetBinContent(i,0.);
  }
  Hist_m1450->Scale(1./Hist_m1450->Integral());

  CrystalBall_m1550.fillHistogram(Hist_m1550,RooArgList(MASS));
  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m1550->Integral(1,i)/Hist_m1550->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m1550->SetBinContent(i,0.);
  }
  Hist_m1550->Scale(1./Hist_m1550->Integral());

  CrystalBall_m1600.fillHistogram(Hist_m1600,RooArgList(MASS));
  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m1600->Integral(1,i)/Hist_m1600->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m1600->SetBinContent(i,0.);
  }
  Hist_m1600->Scale(1./Hist_m1600->Integral());

  CrystalBall_m1650.fillHistogram(Hist_m1650,RooArgList(MASS));
  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m1650->Integral(1,i)/Hist_m1650->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m1650->SetBinContent(i,0.);
  }
  Hist_m1650->Scale(1./Hist_m1650->Integral());

  CrystalBall_m1700.fillHistogram(Hist_m1700,RooArgList(MASS));
  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m1700->Integral(1,i)/Hist_m1700->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m1700->SetBinContent(i,0.);
  }
  Hist_m1700->Scale(1./Hist_m1700->Integral());

  CrystalBall_m1750.fillHistogram(Hist_m1750,RooArgList(MASS));
  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m1750->Integral(1,i)/Hist_m1750->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m1750->SetBinContent(i,0.);
  }
  Hist_m1750->Scale(1./Hist_m1750->Integral());

  CrystalBall_m1800.fillHistogram(Hist_m1800,RooArgList(MASS));
  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m1800->Integral(1,i)/Hist_m1800->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m1800->SetBinContent(i,0.);
  }
  Hist_m1800->Scale(1./Hist_m1800->Integral());

  CrystalBall_m1850.fillHistogram(Hist_m1850,RooArgList(MASS));
  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m1850->Integral(1,i)/Hist_m1850->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m1850->SetBinContent(i,0.);
  }
  Hist_m1850->Scale(1./Hist_m1850->Integral());

  CrystalBall_m1900.fillHistogram(Hist_m1900,RooArgList(MASS));
  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m1900->Integral(1,i)/Hist_m1900->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m1900->SetBinContent(i,0.);
  }
  Hist_m1900->Scale(1./Hist_m1900->Integral());

  CrystalBall_m1950.fillHistogram(Hist_m1950,RooArgList(MASS));
  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m1950->Integral(1,i)/Hist_m1950->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m1950->SetBinContent(i,0.);
  }
  Hist_m1950->Scale(1./Hist_m1950->Integral());

  CrystalBall_m2000.fillHistogram(Hist_m2000,RooArgList(MASS));
  for(int i=1;i<n_bins;i++){
    double cur_int_frac = Hist_m2000->Integral(1,i)/Hist_m2000->Integral();
    if(cur_int_frac>integral_frac_cut) break;
    Hist_m2000->SetBinContent(i,0.);
  }
  Hist_m2000->Scale(1./Hist_m2000->Integral());
  
  Double_t Xmass = 550;
  Double_t Channel_Acceptance_m550 = f1_acc_pol_fit->Eval(Xmass);
  
  Xmass = 650.;
  Double_t Channel_Acceptance_m650 = f1_acc_pol_fit->Eval(Xmass);
    
  Xmass = 750.;
  Double_t Channel_Acceptance_m750 = f1_acc_pol_fit->Eval(Xmass);
  
  Xmass = 850.;
  Double_t Channel_Acceptance_m850 = f1_acc_pol_fit->Eval(Xmass);

  Xmass=950;
  Double_t Channel_Acceptance_m950 = f1_acc_expo_fit->Eval(Xmass);
  Xmass = 1050;
  Double_t Channel_Acceptance_m1050 = f1_acc_expo_fit->Eval(Xmass);
  Xmass = 1150;
  Double_t Channel_Acceptance_m1150 = f1_acc_expo_fit->Eval(Xmass);
  Xmass = 1250;
  Double_t Channel_Acceptance_m1250 = f1_acc_expo_fit->Eval(Xmass);
  Xmass = 1350;
  Double_t Channel_Acceptance_m1350 = f1_acc_expo_fit->Eval(Xmass);
  Xmass = 1450;
  Double_t Channel_Acceptance_m1450 = f1_acc_expo_fit->Eval(Xmass);
  Xmass = 1550;
  Double_t Channel_Acceptance_m1550 = f1_acc_expo_fit->Eval(Xmass);
  Xmass = 1600;
  Double_t Channel_Acceptance_m1600 = f1_acc_expo_fit->Eval(Xmass);
  Xmass = 1650;
  Double_t Channel_Acceptance_m1650 = f1_acc_expo_fit->Eval(Xmass);
  Xmass = 1700;
  Double_t Channel_Acceptance_m1700 = f1_acc_expo_fit->Eval(Xmass);
  Xmass = 1750;
  Double_t Channel_Acceptance_m1750 = f1_acc_expo_fit->Eval(Xmass);
  Xmass = 1800;
  Double_t Channel_Acceptance_m1800 = f1_acc_expo_fit->Eval(Xmass);
  Xmass = 1850;
  Double_t Channel_Acceptance_m1850 = f1_acc_expo_fit->Eval(Xmass);
  Xmass = 1900;
  Double_t Channel_Acceptance_m1900 = f1_acc_expo_fit->Eval(Xmass);
  Xmass = 1950;
  Double_t Channel_Acceptance_m1950 = f1_acc_expo_fit->Eval(Xmass);
  Xmass = 2000;
  Double_t Channel_Acceptance_m2000 = f1_acc_expo_fit->Eval(Xmass);

					 
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
  Hist_m1050->Scale(3333*Channel_Acceptance_m1050*2);
  Hist_m1100->Scale(3333*Channel_Acceptance_m1100*2);
  Hist_m1150->Scale(3333*Channel_Acceptance_m1150*2);
  Hist_m1200->Scale(3333*Channel_Acceptance_m1200*2);
  Hist_m1250->Scale(3333*Channel_Acceptance_m1250*2);
  Hist_m1300->Scale(3333*Channel_Acceptance_m1300*2);
  Hist_m1350->Scale(3333*Channel_Acceptance_m1350*2);
  Hist_m1400->Scale(3333*Channel_Acceptance_m1400*2);
  Hist_m1450->Scale(3333*Channel_Acceptance_m1450*2);
  Hist_m1500->Scale(3333*Channel_Acceptance_m1500*2);
  Hist_m1550->Scale(3333*Channel_Acceptance_m1550*2);
  Hist_m1600->Scale(3333*Channel_Acceptance_m1600*2);
  Hist_m1650->Scale(3333*Channel_Acceptance_m1650*2);
  Hist_m1700->Scale(3333*Channel_Acceptance_m1700*2);
  Hist_m1750->Scale(3333*Channel_Acceptance_m1750*2);
  Hist_m1800->Scale(3333*Channel_Acceptance_m1800*2);
  Hist_m1850->Scale(3333*Channel_Acceptance_m1850*2);
  Hist_m1900->Scale(3333*Channel_Acceptance_m1900*2);
  Hist_m1950->Scale(3333*Channel_Acceptance_m1950*2);
  Hist_m2000->Scale(3333*Channel_Acceptance_m2000*2);
  

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
  Hist_m1050->Scale(Scale_m1050/(3333*Channel_Acceptance_m1050*2));
  Hist_m1100->Scale(Scale_m1100/(3333*Channel_Acceptance_m1100*2));
  Hist_m1150->Scale(Scale_m1150/(3333*Channel_Acceptance_m1150*2));
  Hist_m1200->Scale(Scale_m1200/(3333*Channel_Acceptance_m1200*2));
  Hist_m1250->Scale(Scale_m1250/(3333*Channel_Acceptance_m1250*2));
  Hist_m1300->Scale(Scale_m1300/(3333*Channel_Acceptance_m1300*2));
  Hist_m1350->Scale(Scale_m1350/(3333*Channel_Acceptance_m1350*2));
  Hist_m1400->Scale(Scale_m1400/(3333*Channel_Acceptance_m1400*2));
  Hist_m1450->Scale(Scale_m1450/(3333*Channel_Acceptance_m1450*2));
  Hist_m1500->Scale(Scale_m1500/(3333*Channel_Acceptance_m1500*2));
  Hist_m1550->Scale(Scale_m1550/(3333*Channel_Acceptance_m1550*2));
  Hist_m1600->Scale(Scale_m1600/(3333*Channel_Acceptance_m1600*2));
  Hist_m1650->Scale(Scale_m1650/(3333*Channel_Acceptance_m1650*2));
  Hist_m1700->Scale(Scale_m1700/(3333*Channel_Acceptance_m1700*2));
  Hist_m1750->Scale(Scale_m1750/(3333*Channel_Acceptance_m1750*2));
  Hist_m1800->Scale(Scale_m1800/(3333*Channel_Acceptance_m1800*2));
  Hist_m1850->Scale(Scale_m1850/(3333*Channel_Acceptance_m1850*2));
  Hist_m1900->Scale(Scale_m1900/(3333*Channel_Acceptance_m1900*2));
  Hist_m1950->Scale(Scale_m1950/(3333*Channel_Acceptance_m1950*2));
  Hist_m2000->Scale(Scale_m2000/(3333*Channel_Acceptance_m2000*2));
  

  // TODO 
  //Int_t nBins = 200;
  Hist_m500->Rebin(rebin_n);
  Hist_m550->Rebin(rebin_n);
  Hist_m600->Rebin(rebin_n);
  Hist_m650->Rebin(rebin_n);
  Hist_m700->Rebin(rebin_n);
  Hist_m750->Rebin(rebin_n);
  Hist_m800->Rebin(rebin_n);
  Hist_m850->Rebin(rebin_n);
  Hist_m900->Rebin(rebin_n);
  Hist_m950->Rebin(rebin_n);
  Hist_m1000->Rebin(rebin_n);
  Hist_m1050->Rebin(rebin_n);
  Hist_m1100->Rebin(rebin_n);
  Hist_m1150->Rebin(rebin_n);
  Hist_m1200->Rebin(rebin_n);
  Hist_m1250->Rebin(rebin_n);
  Hist_m1300->Rebin(rebin_n);
  Hist_m1350->Rebin(rebin_n);
  Hist_m1400->Rebin(rebin_n);
  Hist_m1450->Rebin(rebin_n);
  Hist_m1500->Rebin(rebin_n);
  Hist_m1550->Rebin(rebin_n);
  Hist_m1600->Rebin(rebin_n);
  Hist_m1650->Rebin(rebin_n);
  Hist_m1700->Rebin(rebin_n);
  Hist_m1750->Rebin(rebin_n);
  Hist_m1800->Rebin(rebin_n);
  Hist_m1850->Rebin(rebin_n);
  Hist_m1900->Rebin(rebin_n);
  Hist_m1950->Rebin(rebin_n);
  Hist_m2000->Rebin(rebin_n);
  

  
  cout << "=====================================" << endl;
  cout << "Integral_m500 " << Integral_m500 << endl;   
  cout << "Integral_m600 " << Integral_m600 << endl;   
  cout << "Integral_m1000 " << Integral_m1000 << endl;   
  cout << "Integral_m1200 " << Integral_m1200 << endl;   
  cout << "Integral_m1500 " << Integral_m1500 << endl;   
  Integral_m500 = Hist_m500->Integral(0,n_bins);
  Double_t Integral_m550 = Hist_m550->Integral(0,n_bins);
  Integral_m600 = Hist_m600->Integral(0,n_bins);
  Double_t Integral_m650 = Hist_m650->Integral(0,n_bins);
  Integral_m700 = Hist_m700->Integral(0,n_bins);
  Double_t Integral_m750 = Hist_m750->Integral(0,n_bins);
  Integral_m800 = Hist_m800->Integral(0,n_bins);
  Double_t Integral_m850 = Hist_m850->Integral(0,n_bins);
  Integral_m900 = Hist_m900->Integral(0,n_bins);
  Double_t Integral_m950 = Hist_m950->Integral(0,n_bins);
  Integral_m1000 = Hist_m1000->Integral(0,n_bins);
  Double_t Integral_m1050 = Hist_m1050->Integral(0,n_bins);
  Integral_m1100 = Hist_m1100->Integral(0,n_bins);
  Double_t Integral_m1150 = Hist_m1150->Integral(0,n_bins);
  Integral_m1200 = Hist_m1200->Integral(0,n_bins);
  Double_t Integral_m1250 = Hist_m1250->Integral(0,n_bins);
  Integral_m1300 = Hist_m1300->Integral(0,n_bins);
  Double_t Integral_m1350 = Hist_m1350->Integral(0,n_bins);
  Integral_m1400 = Hist_m1400->Integral(0,n_bins);
  Double_t Integral_m1450 = Hist_m1450->Integral(0,n_bins);
  Integral_m1500 = Hist_m1500->Integral(0,n_bins);
  Double_t Integral_m1550 = Hist_m1550->Integral(0,n_bins);
  Double_t Integral_m1600 = Hist_m1600->Integral(0,n_bins);
  Double_t Integral_m1650 = Hist_m1650->Integral(0,n_bins);
  Double_t Integral_m1700 = Hist_m1700->Integral(0,n_bins);
  Double_t Integral_m1750 = Hist_m1750->Integral(0,n_bins);
  Double_t Integral_m1800 = Hist_m1800->Integral(0,n_bins);
  Double_t Integral_m1850 = Hist_m1850->Integral(0,n_bins);
  Double_t Integral_m1900 = Hist_m1900->Integral(0,n_bins);
  Double_t Integral_m1950 = Hist_m1950->Integral(0,n_bins);
  Double_t Integral_m2000 = Hist_m2000->Integral(0,n_bins);


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
  cout << "Total_Channel_m600 " << Total_Channel_m600 << endl;
  cout << "Total_Channel_m700 " << Total_Channel_m700 << endl;
  cout << "Total_Channel_m800 " << Total_Channel_m800 << endl;
  cout << "Total_Channel_m900 " << Total_Channel_m900 << endl;
  cout << "Total_Channel_m1000 " << Total_Channel_m1000 << endl;
  cout << "Total_Channel_m1100 " << Total_Channel_m1100 << endl;
  cout << "Total_Channel_m1200 " << Total_Channel_m1200 << endl;
  cout << "Total_Channel_m1300 " << Total_Channel_m1300 << endl;
  cout << "Total_Channel_m1400 " << Total_Channel_m1400 << endl;
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
  CrystalBall1.plotOn(m500frame, LineColor(kBlue),LineStyle(2),Name("cb"),Range(400,700));

  signal_m600.plotOn(m600frame,LineColor(1),MarkerColor(1),MarkerSize(1.0),Name("data"));
  CrystalBall2.plotOn(m600frame, LineColor(kBlue),LineStyle(2),Name("cb"),Range(450,800));
    
  signal_m700.plotOn(m700frame,LineColor(1),MarkerColor(1),MarkerSize(1.0),Name("data"));
  CrystalBall3.plotOn(m700frame, LineColor(kBlue),LineStyle(2),Name("cb"),Range(500,900));
    
  signal_m800.plotOn(m800frame,LineColor(1),MarkerColor(1),MarkerSize(1.0),Name("data"));
  CrystalBall4.plotOn(m800frame, LineColor(kBlue),LineStyle(2),Name("cb"),Range(600,950));
    
  signal_m900.plotOn(m900frame,LineColor(1),MarkerColor(1),MarkerSize(1.0),Name("data"));
  CrystalBall5.plotOn(m900frame, LineColor(kBlue),LineStyle(2),Name("cb"),Range(600,1100));
    
  signal_m1000.plotOn(m1000frame,LineColor(1),MarkerColor(1),MarkerSize(1.0),Name("data"));
  CrystalBall6.plotOn(m1000frame, LineColor(kBlue),LineStyle(2),Name("cb"),Range(650,1200));

  signal_m1100.plotOn(m1100frame,LineColor(1),MarkerColor(1),MarkerSize(1.0),Name("data"));
  CrystalBall7.plotOn(m1100frame, LineColor(kBlue),LineStyle(2),Name("cb"),Range(650,1300));
    
  signal_m1200.plotOn(m1200frame,LineColor(1),MarkerColor(1),MarkerSize(1.0),Name("data"));
  CrystalBall8.plotOn(m1200frame, LineColor(kBlue),LineStyle(2),Name("cb"),Range(700,1400));
    
  signal_m1300.plotOn(m1300frame,LineColor(1),MarkerColor(1),MarkerSize(1.0),Name("data"));
  CrystalBall9.plotOn(m1300frame, LineColor(kBlue),LineStyle(2),Name("cb"),Range(800,1500));
  
  signal_m1400.plotOn(m1400frame,LineColor(1),MarkerColor(1),MarkerSize(1.0),Name("data"));
  CrystalBall10.plotOn(m1400frame, LineColor(kBlue),LineStyle(2),Name("cb"),Range(800,1600));

  signal_m1500.plotOn(m1500frame,LineColor(1),MarkerColor(1),MarkerSize(1.0),Name("data"));
  CrystalBall11.plotOn(m1500frame, LineColor(kBlue),LineStyle(2),Name("cb"),Range(900,1800));
  // // //CrystalBall_m1500.plotOn(m1500frame,LineColor(4),LineWidth(3));
  
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
  
  string tmp_saveas = "../wprime_plots/"+channel+"_"+cur_sys+"_m500_fit_templates.pdf";
  c_m500_fit_templates->SaveAs(tmp_saveas.c_str());


  // string tc_m500_fit_templates_with_template_name = channel+"_"+cur_sys+"_m500_fit_templates_with_template";  
  // TCanvas* c_m500_fit_templates_with_template =
  //   new TCanvas(tc_m500_fit_templates_with_template_name.c_str(),"Template distributions",200,10,700,500);
  // c_m500_fit_templates_with_template->cd();

  // m500frame->Draw();

    
  string tc_m600_fit_templates_name = channel+"_"+cur_sys+"_m600_fit_templates";
  TCanvas* c_m600_fit_templates =
    new TCanvas(tc_m600_fit_templates_name.c_str(),"Template distributions",200,10,700,500);
  c_m600_fit_templates->cd();
  
  m600frame->Draw();

  TLegend *lgnd_m600 = new TLegend(0.25,0.73,0.46,0.87);
  lgnd_m600->SetFillColor(kWhite);
  lgnd_m600->SetLineColor(kWhite);
  lgnd_m600->AddEntry("data","Signal", "P");
  lgnd_m600->AddEntry("cb","Crystal Ball","L");
  lgnd_m600->Draw();
  
  tmp_saveas = "../wprime_plots/"+channel+"_"+cur_sys+"_m600_fit_templates.pdf";
  c_m600_fit_templates->SaveAs(tmp_saveas.c_str());
    
  string tc_m700_fit_templates_name = channel+"_"+cur_sys+"_m700_fit_templates";
  TCanvas* c_m700_fit_templates =
    new TCanvas(tc_m700_fit_templates_name.c_str(),"Template distributions",200,10,700,500);
  c_m700_fit_templates->cd();
  
  m700frame->Draw();

  TLegend *lgnd_m700 = new TLegend(0.25,0.73,0.46,0.87);
  lgnd_m700->SetFillColor(kWhite);
  lgnd_m700->SetLineColor(kWhite);
  lgnd_m700->AddEntry("data","Signal", "P");
  lgnd_m700->AddEntry("cb","Crystal Ball","L");
  lgnd_m700->Draw();
  
  tmp_saveas = "../wprime_plots/"+channel+"_"+cur_sys+"_m700_fit_templates.pdf";
  c_m700_fit_templates->SaveAs(tmp_saveas.c_str());

  
  string tc_m800_fit_templates_name = channel+"_"+cur_sys+"_m800_fit_templates";
  TCanvas* c_m800_fit_templates =
    new TCanvas(tc_m800_fit_templates_name.c_str(),"Template distributions",200,10,700,500);
  c_m800_fit_templates->cd();
  
  m800frame->Draw();

  TLegend *lgnd_m800 = new TLegend(0.25,0.73,0.46,0.87);
  lgnd_m800->SetFillColor(kWhite);
  lgnd_m800->SetLineColor(kWhite);
  lgnd_m800->AddEntry("data","Signal", "P");
  lgnd_m800->AddEntry("cb","Crystal Ball","L");
  lgnd_m800->Draw();
  
  tmp_saveas = "../wprime_plots/"+channel+"_"+cur_sys+"_m800_fit_templates.pdf";
  c_m800_fit_templates->SaveAs(tmp_saveas.c_str());

  //900
  string tc_m900_fit_templates_name = channel+"_"+cur_sys+"_m900_fit_templates";
  TCanvas* c_m900_fit_templates =
    new TCanvas(tc_m900_fit_templates_name.c_str(),"Template distributions",200,10,700,500);
  c_m900_fit_templates->cd();
  
  m900frame->Draw();

  TLegend *lgnd_m900 = new TLegend(0.25,0.73,0.46,0.87);
  lgnd_m900->SetFillColor(kWhite);
  lgnd_m900->SetLineColor(kWhite);
  lgnd_m900->AddEntry("data","Signal", "P");
  lgnd_m900->AddEntry("cb","Crystal Ball","L");
  lgnd_m900->Draw();
  
  tmp_saveas = "../wprime_plots/"+channel+"_"+cur_sys+"_m900_fit_templates.pdf";
  c_m900_fit_templates->SaveAs(tmp_saveas.c_str());


  //1000
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
  
  tmp_saveas = "../wprime_plots/"+channel+"_"+cur_sys+"_m1000_fit_templates.pdf";
  c_m1000_fit_templates->SaveAs(tmp_saveas.c_str());

  //1100
  string tc_m1100_fit_templates_name = channel+"_"+cur_sys+"_m1100_fit_templates";
  TCanvas* c_m1100_fit_templates =
    new TCanvas(tc_m1100_fit_templates_name.c_str(),"Template distributions",200,10,700,500);
  c_m1100_fit_templates->cd();
  
  m1100frame->Draw();

  TLegend *lgnd_m1100 = new TLegend(0.25,0.73,0.46,0.87);
  lgnd_m1100->SetFillColor(kWhite);
  lgnd_m1100->SetLineColor(kWhite);
  lgnd_m1100->AddEntry("data","Signal", "P");
  lgnd_m1100->AddEntry("cb","Crystal Ball","L");
  lgnd_m1100->Draw();
  
  tmp_saveas = "../wprime_plots/"+channel+"_"+cur_sys+"_m1100_fit_templates.pdf";
  c_m1100_fit_templates->SaveAs(tmp_saveas.c_str());

  //1200
  string tc_m1200_fit_templates_name = channel+"_"+cur_sys+"_m1200_fit_templates";
  TCanvas* c_m1200_fit_templates =
    new TCanvas(tc_m1200_fit_templates_name.c_str(),"Template distributions",200,10,700,500);
  c_m1200_fit_templates->cd();
  
  m1200frame->Draw();

  TLegend *lgnd_m1200 = new TLegend(0.25,0.73,0.46,0.87);
  lgnd_m1200->SetFillColor(kWhite);
  lgnd_m1200->SetLineColor(kWhite);
  lgnd_m1200->AddEntry("data","Signal", "P");
  lgnd_m1200->AddEntry("cb","Crystal Ball","L");
  lgnd_m1200->Draw();
  
  tmp_saveas = "../wprime_plots/"+channel+"_"+cur_sys+"_m1200_fit_templates.pdf";
  c_m1200_fit_templates->SaveAs(tmp_saveas.c_str());

  //1300
  string tc_m1300_fit_templates_name = channel+"_"+cur_sys+"_m1300_fit_templates";
  TCanvas* c_m1300_fit_templates =
    new TCanvas(tc_m1300_fit_templates_name.c_str(),"Template distributions",200,10,700,500);
  c_m1300_fit_templates->cd();
  
  m1300frame->Draw();

  TLegend *lgnd_m1300 = new TLegend(0.25,0.73,0.46,0.87);
  lgnd_m1300->SetFillColor(kWhite);
  lgnd_m1300->SetLineColor(kWhite);
  lgnd_m1300->AddEntry("data","Signal", "P");
  lgnd_m1300->AddEntry("cb","Crystal Ball","L");
  lgnd_m1300->Draw();
  
  tmp_saveas = "../wprime_plots/"+channel+"_"+cur_sys+"_m1300_fit_templates.pdf";
  c_m1300_fit_templates->SaveAs(tmp_saveas.c_str());


  //1400
  string tc_m1400_fit_templates_name = channel+"_"+cur_sys+"_m1400_fit_templates";
  TCanvas* c_m1400_fit_templates =
    new TCanvas(tc_m1400_fit_templates_name.c_str(),"Template distributions",200,10,700,500);
  c_m1400_fit_templates->cd();
  
  m1400frame->Draw();

  TLegend *lgnd_m1400 = new TLegend(0.25,0.73,0.46,0.87);
  lgnd_m1400->SetFillColor(kWhite);
  lgnd_m1400->SetLineColor(kWhite);
  lgnd_m1400->AddEntry("data","Signal", "P");
  lgnd_m1400->AddEntry("cb","Crystal Ball","L");
  lgnd_m1400->Draw();
  
  tmp_saveas = "../wprime_plots/"+channel+"_"+cur_sys+"_m1400_fit_templates.pdf";
  c_m1400_fit_templates->SaveAs(tmp_saveas.c_str());

  //1500
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

  tmp_saveas = "../wprime_plots/"+channel+"_"+cur_sys+"_m1500_fit_templates.pdf";
  c_m1500_fit_templates->SaveAs(tmp_saveas.c_str());


  string tc_c_parm_name = channel+"_"+cur_sys+"_c_parm";
  TCanvas *c_parm = new TCanvas(tc_c_parm_name.c_str(),"Parameter fits",200,10,700,500);
  c_parm->Divide(2,2);

  c_parm->cd(1);
  gr_parameter_Mean->SetTitle("");
  gr_parameter_Mean->GetYaxis()->SetTitle("Crystal Ball Mean");
  gr_parameter_Mean->SetMarkerColor(2);
  gr_parameter_Mean->Draw("A*");
  gr_parameter_Mean->SetMarkerStyle(22);
  gr_parameter_Mean->GetXaxis()->SetTitle("W' Mass [GeV]");
  c_parm->cd(2);
  gr_parameter_Sigma->SetTitle("");
  gr_parameter_Sigma->GetYaxis()->SetTitle("Crystal Ball Sigma");
  gr_parameter_Sigma->SetMarkerColor(2);
  gr_parameter_Sigma->Draw("A*");
  gr_parameter_Sigma->SetMarkerStyle(22);
  gr_parameter_Sigma->GetXaxis()->SetTitle("W' Mass [GeV]");
  c_parm->cd(3);
  gr_parameter_A->SetTitle("");
  gr_parameter_A->GetYaxis()->SetTitle("Crystal Ball a");
  gr_parameter_A->SetMarkerColor(2);
  gr_parameter_A->Draw("A*");
  gr_parameter_A->SetMarkerStyle(22);
  gr_parameter_A->GetXaxis()->SetTitle("W' Mass [GeV]");
  
  c_parm->cd(4);
  gr_parameter_N->SetTitle("");
  gr_parameter_N->GetYaxis()->SetTitle("Crystal Ball n");
  gr_parameter_N->SetMarkerColor(2);
  gr_parameter_N->Draw("A*");
  gr_parameter_N->SetMarkerStyle(22);
  gr_parameter_N->GetXaxis()->SetTitle("W' Mass [GeV]");

  string cur_saveas = "../wprime_plots/"+channel+"_"+cur_sys+"_fit_parameters.pdf";
  c_parm->SaveAs(cur_saveas.c_str());
  
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
  if(c_m600_fit_templates) delete c_m600_fit_templates;
  if(lgnd_m600) delete lgnd_m600;
  if(c_m700_fit_templates) delete c_m700_fit_templates;
  if(lgnd_m700) delete lgnd_m700;
  if(c_m800_fit_templates) delete c_m800_fit_templates;
  if(lgnd_m800) delete lgnd_m800;
  if(c_m900_fit_templates) delete c_m900_fit_templates;
  if(lgnd_m900) delete lgnd_m900;
  if(c_m1000_fit_templates) delete c_m1000_fit_templates;
  if(lgnd_m1000) delete lgnd_m1000;
  if(c_m1100_fit_templates) delete c_m1100_fit_templates;
  if(lgnd_m1100) delete lgnd_m1100;
  if(c_m1200_fit_templates) delete c_m1200_fit_templates;
  if(lgnd_m1200) delete lgnd_m1200;
  if(c_m1300_fit_templates) delete c_m1300_fit_templates;
  if(lgnd_m1300) delete lgnd_m1300;
  if(c_m1400_fit_templates) delete c_m1400_fit_templates;
  if(lgnd_m1400) delete lgnd_m1400;
  if(c_m1500_fit_templates) delete c_m1500_fit_templates;
  if(lgnd_m1500) delete lgnd_m1500;
  
  cout<<"okay"<<endl;
  return;
}

void signalShapesWprime::makeClosurePlots(string channel/*="evjj"*/,string cur_sys/*="jes_nom"*/){

  //gROOT->SetBatch();

  
  // Plot simulated variables against template histograms
  // compare normalization, shape etc.

  
  
   // Get Template histograms
  string cb_file_name = "../wprime_files/"+channel+"_cb_"+cur_sys+"_lep_nu_dijet_m.root";
  TFile* cur_cb_file = TFile::Open(cb_file_name.c_str(),"READ");

  TH1F* cb_hists[NGmass];
  char cb_name[200];
  string cb_string = "cb_wprime_m%i";
  for(int i=0;i<NGmass;i++){
    sprintf(cb_name,cb_string.c_str(),GmassInt[i]);
    cb_hists[i] = (TH1F*) cur_cb_file->Get(cb_name);
    cb_hists[i]->SetDirectory(0);
  }
  cur_cb_file->Close();
  

  // Get Signal histograms
  //m500
  string signal_m500_file_name =
    "../../plots/systematics_plots/merged/mc.wprime.wz.m500.systematics.plot.root";
  TFile* cur_signal_m500_file = TFile::Open(signal_m500_file_name.c_str(),"READ");
  
  string signal_m500_hist_name = (channel=="evjj") ?
    "h_el_"+cur_sys+"_highm_lep_nu_dijet_m" :
    "h_mu_"+cur_sys+"_highm_lep_nu_dijet_m";
  
  TH1F* signal_m500_hist = (TH1F*) cur_signal_m500_file->Get(signal_m500_hist_name.c_str());
  signal_m500_hist->SetDirectory(0);
  cur_signal_m500_file->Close();

  //m600
  string signal_m600_file_name =
    "../../plots/systematics_plots/merged/mc.wprime.wz.m600.systematics.plot.root";
  TFile* cur_signal_m600_file = TFile::Open(signal_m600_file_name.c_str(),"READ");
  
  string signal_m600_hist_name = (channel=="evjj") ?
    "h_el_"+cur_sys+"_highm_lep_nu_dijet_m" :
    "h_mu_"+cur_sys+"_highm_lep_nu_dijet_m";
  
  TH1F* signal_m600_hist = (TH1F*) cur_signal_m600_file->Get(signal_m600_hist_name.c_str());
  signal_m600_hist->SetDirectory(0);
  cur_signal_m600_file->Close();

  //m700
  string signal_m700_file_name =
    "../../plots/systematics_plots/merged/mc.wprime.wz.m700.systematics.plot.root";
  TFile* cur_signal_m700_file = TFile::Open(signal_m700_file_name.c_str(),"READ");
  
  string signal_m700_hist_name = (channel=="evjj") ?
    "h_el_"+cur_sys+"_highm_lep_nu_dijet_m" :
    "h_mu_"+cur_sys+"_highm_lep_nu_dijet_m";
  
  TH1F* signal_m700_hist = (TH1F*) cur_signal_m700_file->Get(signal_m700_hist_name.c_str());
  signal_m700_hist->SetDirectory(0);
  cur_signal_m700_file->Close();

  //m800
  string signal_m800_file_name =
    "../../plots/systematics_plots/merged/mc.wprime.wz.m800.systematics.plot.root";
  TFile* cur_signal_m800_file = TFile::Open(signal_m800_file_name.c_str(),"READ");
  
  string signal_m800_hist_name = (channel=="evjj") ?
    "h_el_"+cur_sys+"_highm_lep_nu_dijet_m" :
    "h_mu_"+cur_sys+"_highm_lep_nu_dijet_m";
  
  TH1F* signal_m800_hist = (TH1F*) cur_signal_m800_file->Get(signal_m800_hist_name.c_str());
  signal_m800_hist->SetDirectory(0);
  cur_signal_m800_file->Close();


  //m900
  string signal_m900_file_name =
    "../../plots/systematics_plots/merged/mc.wprime.wz.m900.systematics.plot.root";
  TFile* cur_signal_m900_file = TFile::Open(signal_m900_file_name.c_str(),"READ");
  
  string signal_m900_hist_name = (channel=="evjj") ?
    "h_el_"+cur_sys+"_highm_lep_nu_dijet_m" :
    "h_mu_"+cur_sys+"_highm_lep_nu_dijet_m";
  
  TH1F* signal_m900_hist = (TH1F*) cur_signal_m900_file->Get(signal_m900_hist_name.c_str());
  signal_m900_hist->SetDirectory(0);
  cur_signal_m900_file->Close();


  //m1000
  string signal_m1000_file_name =
    "../../plots/systematics_plots/merged/mc.wprime.wz.m1000.systematics.plot.root";
  TFile* cur_signal_m1000_file = TFile::Open(signal_m1000_file_name.c_str(),"READ");
  
  string signal_m1000_hist_name = (channel=="evjj") ?
    "h_el_"+cur_sys+"_highm_lep_nu_dijet_m" :
    "h_mu_"+cur_sys+"_highm_lep_nu_dijet_m";
  
  TH1F* signal_m1000_hist = (TH1F*) cur_signal_m1000_file->Get(signal_m1000_hist_name.c_str());
  signal_m1000_hist->SetDirectory(0);
  cur_signal_m1000_file->Close();

  //m1100
  string signal_m1100_file_name =
    "../../plots/systematics_plots/merged/mc.wprime.wz.m1100.systematics.plot.root";
  TFile* cur_signal_m1100_file = TFile::Open(signal_m1100_file_name.c_str(),"READ");
  
  string signal_m1100_hist_name = (channel=="evjj") ?
    "h_el_"+cur_sys+"_highm_lep_nu_dijet_m" :
    "h_mu_"+cur_sys+"_highm_lep_nu_dijet_m";
  
  TH1F* signal_m1100_hist = (TH1F*) cur_signal_m1100_file->Get(signal_m1100_hist_name.c_str());
  signal_m1100_hist->SetDirectory(0);
  cur_signal_m1100_file->Close();

  //m1200
  string signal_m1200_file_name =
    "../../plots/systematics_plots/merged/mc.wprime.wz.m1200.systematics.plot.root";
  TFile* cur_signal_m1200_file = TFile::Open(signal_m1200_file_name.c_str(),"READ");
  
  string signal_m1200_hist_name = (channel=="evjj") ?
    "h_el_"+cur_sys+"_highm_lep_nu_dijet_m" :
    "h_mu_"+cur_sys+"_highm_lep_nu_dijet_m";
  
  TH1F* signal_m1200_hist = (TH1F*) cur_signal_m1200_file->Get(signal_m1200_hist_name.c_str());
  signal_m1200_hist->SetDirectory(0);
  cur_signal_m1200_file->Close();

  //m1300
  string signal_m1300_file_name =
    "../../plots/systematics_plots/merged/mc.wprime.wz.m1300.systematics.plot.root";
  TFile* cur_signal_m1300_file = TFile::Open(signal_m1300_file_name.c_str(),"READ");
  
  string signal_m1300_hist_name = (channel=="evjj") ?
    "h_el_"+cur_sys+"_highm_lep_nu_dijet_m" :
    "h_mu_"+cur_sys+"_highm_lep_nu_dijet_m";
  
  TH1F* signal_m1300_hist = (TH1F*) cur_signal_m1300_file->Get(signal_m1300_hist_name.c_str());
  signal_m1300_hist->SetDirectory(0);
  cur_signal_m1300_file->Close();

  //m1400
  string signal_m1400_file_name =
    "../../plots/systematics_plots/merged/mc.wprime.wz.m1400.systematics.plot.root";
  TFile* cur_signal_m1400_file = TFile::Open(signal_m1400_file_name.c_str(),"READ");
  
  string signal_m1400_hist_name = (channel=="evjj") ?
    "h_el_"+cur_sys+"_highm_lep_nu_dijet_m" :
    "h_mu_"+cur_sys+"_highm_lep_nu_dijet_m";
  
  TH1F* signal_m1400_hist = (TH1F*) cur_signal_m1400_file->Get(signal_m1400_hist_name.c_str());
  signal_m1400_hist->SetDirectory(0);
  cur_signal_m1400_file->Close();


  //m1500
  string signal_m1500_file_name =
    "../../plots/systematics_plots/merged/mc.wprime.wz.m1500.systematics.plot.root";
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

  signal_m500_hist->Rebin(rebin_n/4);
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

  string tmp_saveas = "../wprime_plots/closure_plots/"+channel+"_"+cur_sys+"_m500_closure.pdf";
  c_m500_closure->SaveAs(tmp_saveas.c_str());

  //m600
  string tc_m600_closure_name = channel+"_"+cur_sys+"_m600_closure";
  TCanvas* c_m600_closure =
    new TCanvas(tc_m600_closure_name.c_str(),"m600 Signal and Template histos",200,10,700,500);
  c_m600_closure->cd();

  signal_m600_hist->Rebin(rebin_n/4);
  signal_m600_hist->GetXaxis()->SetRangeUser(200,800);
  signal_m600_hist->SetMarkerSize(0.8);
  signal_m600_hist->Draw();

  cb_hists[2]->SetMarkerSize(0.8);
  cb_hists[2]->SetMarkerColor(kBlue);
  cb_hists[2]->SetLineColor(kBlue);
  cb_hists[2]->Draw("same");

  //c_m600_closure->SetLogy();
  c_m600_closure->Update();
  
  TLegend *lgnd_m600 = new TLegend(0.69,0.73,0.9,0.87);
  lgnd_m600->SetFillColor(kWhite);
  lgnd_m600->SetLineColor(kWhite);
  lgnd_m600->AddEntry(signal_m600_hist,"Signal", "P");
  lgnd_m600->AddEntry(cb_hists[2],"Crystal Ball","P");
  lgnd_m600->Draw();

  tmp_saveas = "../wprime_plots/closure_plots/"+channel+"_"+cur_sys+"_m600_closure.pdf";
  c_m600_closure->SaveAs(tmp_saveas.c_str());


  //m700
  string tc_m700_closure_name = channel+"_"+cur_sys+"_m700_closure";
  TCanvas* c_m700_closure =
    new TCanvas(tc_m700_closure_name.c_str(),"m700 Signal and Template histos",200,10,700,500);
  c_m700_closure->cd();

  signal_m700_hist->Rebin(rebin_n/4);
  signal_m700_hist->GetXaxis()->SetRangeUser(400,1200);
  signal_m700_hist->SetMarkerSize(0.8);
  signal_m700_hist->Draw();

  cb_hists[4]->SetMarkerSize(0.8);
  cb_hists[4]->SetMarkerColor(kBlue);
  cb_hists[4]->SetLineColor(kBlue);
  cb_hists[4]->Draw("same");

  c_m700_closure->Update();
  
  TLegend *lgnd_m700 = new TLegend(0.25,0.73,0.46,0.87);
  lgnd_m700->SetFillColor(kWhite);
  lgnd_m700->SetLineColor(kWhite);
  lgnd_m700->AddEntry(signal_m700_hist,"Signal", "P");
  lgnd_m700->AddEntry(cb_hists[4],"Crystal Ball","P");
  lgnd_m700->Draw();

  tmp_saveas = "../wprime_plots/closure_plots/"+channel+"_"+cur_sys+"_m700_closure.pdf";
  c_m700_closure->SaveAs(tmp_saveas.c_str());


  //m800
  string tc_m800_closure_name = channel+"_"+cur_sys+"_m800_closure";
  TCanvas* c_m800_closure =
    new TCanvas(tc_m800_closure_name.c_str(),"m800 Signal and Template histos",200,10,700,500);
  c_m800_closure->cd();

  signal_m800_hist->Rebin(rebin_n/4);
  signal_m800_hist->GetXaxis()->SetRangeUser(400,1200);
  signal_m800_hist->SetMarkerSize(0.8);
  signal_m800_hist->Draw();

  cb_hists[6]->SetMarkerSize(0.8);
  cb_hists[6]->SetMarkerColor(kBlue);
  cb_hists[6]->SetLineColor(kBlue);
  cb_hists[6]->Draw("same");

  c_m800_closure->Update();
  
  TLegend *lgnd_m800 = new TLegend(0.25,0.73,0.46,0.87);
  lgnd_m800->SetFillColor(kWhite);
  lgnd_m800->SetLineColor(kWhite);
  lgnd_m800->AddEntry(signal_m800_hist,"Signal", "P");
  lgnd_m800->AddEntry(cb_hists[6],"Crystal Ball","P");
  lgnd_m800->Draw();

  tmp_saveas = "../wprime_plots/closure_plots/"+channel+"_"+cur_sys+"_m800_closure.pdf";
  c_m800_closure->SaveAs(tmp_saveas.c_str());
  //m900
  string tc_m900_closure_name = channel+"_"+cur_sys+"_m900_closure";
  TCanvas* c_m900_closure =
    new TCanvas(tc_m900_closure_name.c_str(),"m900 Signal and Template histos",200,10,700,500);
  c_m900_closure->cd();

  signal_m900_hist->Rebin(rebin_n/4);
  signal_m900_hist->GetXaxis()->SetRangeUser(400,1200);
  signal_m900_hist->SetMarkerSize(0.8);
  signal_m900_hist->Draw();

  cb_hists[8]->SetMarkerSize(0.8);
  cb_hists[8]->SetMarkerColor(kBlue);
  cb_hists[8]->SetLineColor(kBlue);
  cb_hists[8]->Draw("same");

  c_m900_closure->Update();
  
  TLegend *lgnd_m900 = new TLegend(0.25,0.73,0.46,0.87);
  lgnd_m900->SetFillColor(kWhite);
  lgnd_m900->SetLineColor(kWhite);
  lgnd_m900->AddEntry(signal_m900_hist,"Signal", "P");
  lgnd_m900->AddEntry(cb_hists[8],"Crystal Ball","P");
  lgnd_m900->Draw();

  tmp_saveas = "../wprime_plots/closure_plots/"+channel+"_"+cur_sys+"_m900_closure.pdf";
  c_m900_closure->SaveAs(tmp_saveas.c_str());


  //m1000
  string tc_m1000_closure_name = channel+"_"+cur_sys+"_m1000_closure";
  TCanvas* c_m1000_closure =
    new TCanvas(tc_m1000_closure_name.c_str(),"m1000 Signal and Template histos",200,10,700,500);
  c_m1000_closure->cd();

  signal_m1000_hist->Rebin(rebin_n/4);
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

  tmp_saveas = "../wprime_plots/closure_plots/"+channel+"_"+cur_sys+"_m1000_closure.pdf";
  c_m1000_closure->SaveAs(tmp_saveas.c_str());

  //m1100
  string tc_m1100_closure_name = channel+"_"+cur_sys+"_m1100_closure";
  TCanvas* c_m1100_closure =
    new TCanvas(tc_m1100_closure_name.c_str(),"m1100 Signal and Template histos",200,10,700,500);
  c_m1100_closure->cd();

  signal_m1100_hist->Rebin(rebin_n/4);
  signal_m1100_hist->GetXaxis()->SetRangeUser(400,1600);
  signal_m1100_hist->SetMarkerSize(0.8);
  signal_m1100_hist->Draw();

  cb_hists[12]->SetMarkerSize(0.8);
  cb_hists[12]->SetMarkerColor(kBlue);
  cb_hists[12]->SetLineColor(kBlue);
  cb_hists[12]->Draw("same");

  c_m1100_closure->Update();
  
  TLegend *lgnd_m1100 = new TLegend(0.25,0.73,0.46,0.87);
  lgnd_m1100->SetFillColor(kWhite);
  lgnd_m1100->SetLineColor(kWhite);
  lgnd_m1100->AddEntry(signal_m1100_hist,"Signal", "P");
  lgnd_m1100->AddEntry(cb_hists[12],"Crystal Ball","P");
  lgnd_m1100->Draw();

  tmp_saveas = "../wprime_plots/closure_plots/"+channel+"_"+cur_sys+"_m1100_closure.pdf";
  c_m1100_closure->SaveAs(tmp_saveas.c_str());


  //m1200
  string tc_m1200_closure_name = channel+"_"+cur_sys+"_m1200_closure";
  TCanvas* c_m1200_closure =
    new TCanvas(tc_m1200_closure_name.c_str(),"m1200 Signal and Template histos",200,10,700,500);
  c_m1200_closure->cd();

  signal_m1200_hist->Rebin(rebin_n/4);
  signal_m1200_hist->GetXaxis()->SetRangeUser(400,2000);
  signal_m1200_hist->SetMarkerSize(0.8);
  signal_m1200_hist->Draw();

  cb_hists[14]->SetMarkerSize(0.8);
  cb_hists[14]->SetMarkerColor(kBlue);
  cb_hists[14]->SetLineColor(kBlue);
  cb_hists[14]->Draw("same");

  c_m1200_closure->Update();
  
  TLegend *lgnd_m1200 = new TLegend(0.25,0.73,0.46,0.87);
  lgnd_m1200->SetFillColor(kWhite);
  lgnd_m1200->SetLineColor(kWhite);
  lgnd_m1200->AddEntry(signal_m1200_hist,"Signal", "P");
  lgnd_m1200->AddEntry(cb_hists[14],"Crystal Ball","P");
  lgnd_m1200->Draw();

  tmp_saveas = "../wprime_plots/closure_plots/"+channel+"_"+cur_sys+"_m1200_closure.pdf";
  c_m1200_closure->SaveAs(tmp_saveas.c_str());

  //m1300
  string tc_m1300_closure_name = channel+"_"+cur_sys+"_m1300_closure";
  TCanvas* c_m1300_closure =
    new TCanvas(tc_m1300_closure_name.c_str(),"m1300 Signal and Template histos",200,10,700,500);
  c_m1300_closure->cd();

  signal_m1300_hist->Rebin(rebin_n/4);
  signal_m1300_hist->GetXaxis()->SetRangeUser(400,2000);
  signal_m1300_hist->SetMarkerSize(0.8);
  signal_m1300_hist->Draw();

  cb_hists[16]->SetMarkerSize(0.8);
  cb_hists[16]->SetMarkerColor(kBlue);
  cb_hists[16]->SetLineColor(kBlue);
  cb_hists[16]->Draw("same");

  c_m1300_closure->Update();
  
  TLegend *lgnd_m1300 = new TLegend(0.25,0.73,0.46,0.87);
  lgnd_m1300->SetFillColor(kWhite);
  lgnd_m1300->SetLineColor(kWhite);
  lgnd_m1300->AddEntry(signal_m1300_hist,"Signal", "P");
  lgnd_m1300->AddEntry(cb_hists[16],"Crystal Ball","P");
  lgnd_m1300->Draw();

  tmp_saveas = "../wprime_plots/closure_plots/"+channel+"_"+cur_sys+"_m1300_closure.pdf";
  c_m1300_closure->SaveAs(tmp_saveas.c_str());


  //m1400
  string tc_m1400_closure_name = channel+"_"+cur_sys+"_m1400_closure";
  TCanvas* c_m1400_closure =
    new TCanvas(tc_m1400_closure_name.c_str(),"m1400 Signal and Template histos",200,10,700,500);
  c_m1400_closure->cd();

  signal_m1400_hist->Rebin(rebin_n/4);
  signal_m1400_hist->GetXaxis()->SetRangeUser(400,2000);
  signal_m1400_hist->SetMarkerSize(0.8);
  signal_m1400_hist->Draw();

  cb_hists[18]->SetMarkerSize(0.8);
  cb_hists[18]->SetMarkerColor(kBlue);
  cb_hists[18]->SetLineColor(kBlue);
  cb_hists[18]->Draw("same");

  c_m1400_closure->Update();
  
  TLegend *lgnd_m1400 = new TLegend(0.25,0.73,0.46,0.87);
  lgnd_m1400->SetFillColor(kWhite);
  lgnd_m1400->SetLineColor(kWhite);
  lgnd_m1400->AddEntry(signal_m1400_hist,"Signal", "P");
  lgnd_m1400->AddEntry(cb_hists[18],"Crystal Ball","P");
  lgnd_m1400->Draw();

  tmp_saveas = "../wprime_plots/closure_plots/"+channel+"_"+cur_sys+"_m1400_closure.pdf";
  c_m1400_closure->SaveAs(tmp_saveas.c_str());


  //m1500
  string tc_m1500_closure_name = channel+"_"+cur_sys+"_m1500_closure";
  TCanvas* c_m1500_closure =
    new TCanvas(tc_m1500_closure_name.c_str(),"m1500 Signal and Template histos",200,10,700,500);
  c_m1500_closure->cd();

  signal_m1500_hist->Rebin(rebin_n/4);
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

  tmp_saveas = "../wprime_plots/closure_plots/"+channel+"_"+cur_sys+"_m1500_closure.pdf";
  c_m1500_closure->SaveAs(tmp_saveas.c_str());


  string c_template_plots_name = "c_"+channel+"_"+cur_sys+"_template_plots";
  TCanvas* c_template_plots =
    new TCanvas(c_template_plots_name.c_str(),"Template histos",200,10,700,500);
  //c_template_plots->cd();
  c_template_plots->Divide(6,5);

  for(int i=1;i<NGmass+1;i++){
    c_template_plots->cd(i);

    cb_hists[i-1]->SetLineColor(kBlack);
    cb_hists[i-1]->Draw("hist");

  }
  c_template_plots->Update();
  
  tmp_saveas = "../wprime_plots/template_plots/"+channel+"_"+cur_sys+"_template_plots.pdf";
  c_template_plots->SaveAs(tmp_saveas.c_str());
  

  if(cur_cb_file) delete cur_cb_file;  
  if(cur_signal_m500_file) delete cur_signal_m500_file;
  if(cur_signal_m600_file) delete cur_signal_m600_file;
  if(cur_signal_m700_file) delete cur_signal_m700_file;
  if(cur_signal_m800_file) delete cur_signal_m800_file;
  if(cur_signal_m900_file) delete cur_signal_m900_file;
  if(cur_signal_m1000_file) delete cur_signal_m1000_file;
  if(cur_signal_m1100_file) delete cur_signal_m1100_file;
  if(cur_signal_m1200_file) delete cur_signal_m1200_file;
  if(cur_signal_m1300_file) delete cur_signal_m1300_file;
  if(cur_signal_m1400_file) delete cur_signal_m1400_file;
  if(cur_signal_m1500_file) delete cur_signal_m1500_file;

  
}
