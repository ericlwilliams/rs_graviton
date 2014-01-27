#include <TCanvas.h>
#include <TConfidenceLevel.h>
#include <TCut.h>
#include <TFile.h>
#include <TH1.h>
#include <THStack.h>
#include <TLegend.h>
#include <TLegendEntry.h>
#include <TLimit.h>
#include <TLimitDataSource.h>
#include <TLine.h>
#include <TObjArray.h>
#include <TObjString.h>
#include <TROOT.h>
#include <TString.h>
#include <TStyle.h>
#include <TTree.h>
#include <TVectorD.h>
#include <fstream>
#include <algorithm>
#include <iostream>

#define maxchan 20
#define maxmass 20
#define precision 50000
using namespace std;

double* ConfidenceLevels( double xsec_factor = 1., int mass = 1000, int rebin = 1, TString ListFile = "channels.list", Bool_t doSyst = true, Bool_t doDraw = false )
{
  static double CL[12];
  TLimitDataSource* datasource;
  TConfidenceLevel *confidence;

  // first open the ListFile to get the list of channels
  ifstream infile1((const char*)ListFile);
  if (!infile1) { cerr << "Fichier channels non existant" << endl; return CL; }
  std::string filelist[maxchan];
  Int_t line = 0;
  while(infile1 >> filelist[line++]){
    if(line>=maxchan) { cout << "Too many channels, using only " << maxchan << endl; break; 
    }
  }
  infile1.close();
  Int_t nch = line-1;

  for(Int_t j = 0; j< nch; j++) { // loop over channels

    // parse for systematics
    int n_systematics = std::count(filelist[j].begin(), filelist[j].end(), ';');
    cout << n_systematics << endl;
    TObjArray* names = new TObjArray();
    TVectorD errorb(n_systematics);
    TVectorD errors(n_systematics);
    std::string filename;
  
    int i_syst = 0;  
    for (size_t i=0,n; i <= filelist[j].length(); i=n+1) {
      n = filelist[j].find_first_of(';',i);
      if (n == string::npos)      
	n = filelist[j].length();
      std::string tmp_syst = filelist[j].substr(i,n-i);
      std::cout << tmp_syst << endl;
      std::vector<std::string> systList;
      int i_element = 0;  
      for (size_t i_char=0,n_chars; i_char <= tmp_syst.length(); i_char=n_chars+1) {
	n_chars = tmp_syst.find_first_of(',',i_char);
	if (n_chars == string::npos)
	  n_chars = tmp_syst.length();
	std::string tmp_element = tmp_syst.substr(i_char,n_chars-i_char);
	if (i_syst==0) {
	  filename = tmp_element;
	} else {
	  if (i_element==0) {
	    TObjString *name = new TObjString(tmp_element.c_str());
	    names->AddLast(name); 
	  } else if (i_element==1) {
	    errors[i_syst-1] = atof(tmp_element.c_str());
	    cout << "asdf " << tmp_element << endl;
	  } else if (i_element==2) {
	    errorb[i_syst-1] = atof(tmp_element.c_str());
	  }
	}
	std::cout << tmp_element << endl;
	i_element++;
      }
      i_syst++;
    }
    
    cout << "debug" << endl;      
    names->Print("all");
    for (size_t ii=0; ii < n_systematics; ii++) {
      cout << errors[ii] << " ";
      cout << errorb[ii] << " ";
      cout << endl;
    }

    TFile* infile=new TFile(filename.c_str(),"READ");
    infile->cd();
    
    /////////////////////////////////////////////
    // GET HISTOGRAMS
    
    TH1* sh=(TH1*)infile->Get(Form("signal%i",mass));
    TH1* bh=(TH1*)infile->Get("background");
    TH1* dh=(TH1*)infile->Get("data");
    
    bh->SetDirectory(0);
    sh->SetDirectory(0);
    dh->SetDirectory(0);

    bh->ResetBit(TH1::kCanRebin);
    sh->ResetBit(TH1::kCanRebin);
    dh->ResetBit(TH1::kCanRebin);
    
    bh->Rebin(rebin);
    sh->Rebin(rebin);
    dh->Rebin(rebin);
    
    bh->SetFillColor(19);
    bh->SetFillStyle(1001);
    sh->SetFillColor(0);
    sh->SetFillStyle(1001);
    dh->SetMarkerStyle(20);
    dh->SetMarkerColor(1);
    
    sh->Scale(xsec_factor);
    
    if (doDraw) {
      THStack *hs = new THStack("hs","");
      cout << bh->GetNbinsX() << endl;
      cout << sh->GetNbinsX() << endl;
      cout << dh->GetNbinsX() << endl;
      hs->Add(bh,"hist");
      hs->Add(sh,"hist");
      hs->SetMaximum(100*rebin);
      hs->SetMinimum(2e-2*rebin);
      hs->SetTitle(";m_{eej} [GeV];Events");
      //  hs->GetXaxis()->SetTitleSize(0.05)

      TCanvas *c_data = new TCanvas("c_data","c_data",700,500);
      c_data->SetBottomMargin(1.2);
      hs->Print();
      hs->Draw();
      //   sbh->Draw();
      //   bh->Draw("same");
      hs->GetXaxis()->SetRangeUser(100,1000);
      dh->Draw("samee1");
      //  c_data->SetLogy();
      TLegend *leg = new TLegend(0.5,0.67,0.88,0.88,NULL,"brNDC");
      leg->SetBorderSize(1);
      leg->SetTextFont(62);
      leg->SetLineColor(1);
      leg->SetLineStyle(1);
      leg->SetLineWidth(1);
      leg->SetFillColor(0);
      leg->SetFillStyle(1001);
      TLegendEntry *entry=leg->AddEntry("background","backgrounds (PythiaZee)","f");
      entry->SetFillColor(19);
      entry->SetFillStyle(1001);
      entry->SetLineColor(1);
      entry->SetLineStyle(1);
      entry->SetLineWidth(1);
      entry->SetMarkerColor(1);
      entry->SetMarkerStyle(20);
      entry->SetMarkerSize(0.2);
      entry=leg->AddEntry("signal1000",Form("vector-like quark %i GeV",mass),"lpf");
      entry->SetFillStyle(1001);
      entry->SetLineColor(1);
      entry->SetLineStyle(1);
      entry->SetLineWidth(3);
      entry->SetMarkerColor(1);
      entry->SetMarkerStyle(20);
      entry->SetMarkerSize(0.2);
      entry=leg->AddEntry("data","data","lpf");
      entry->SetFillStyle(1001);
      entry->SetLineColor(1);
      entry->SetLineStyle(1);
      entry->SetLineWidth(1);
      entry->SetMarkerColor(1);
      entry->SetMarkerStyle(20);
      entry->SetMarkerSize(0.8);
      leg->Draw();
      string plotname = filename;
      plotname= plotname.substr(plotname.find("gww_"));
      plotname= plotname.substr(0,plotname.find(".root"));
      plotname="./plots/latest/"+plotname;
      plotname+=Form("_m%i_%.2fxXsec_%irebin.png",mass,xsec_factor,rebin);

      c_data->SaveAs(plotname.c_str());


      gStyle->SetOptStat(0);
    
      TCanvas *c_LLR = new TCanvas("c_LLR","c_LLR",0,500,700,500);
      confidence->Draw();
      TH1F* b_hist = (TH1F*)gDirectory->Get("b_hist");
      TH1F* sb_hist = (TH1F*)gDirectory->Get("sb_hist");
      cout << "b: " << b_hist->GetMean() << " sb: " << sb_hist->GetMean() << endl;
      b_hist->SetFillColor(19);
      b_hist->SetTitle(";LLR;Number of pseudo-experiments");
      double max= b_hist->GetBinContent(b_hist->GetMaximumBin());
      max *= 2;
      double  LLRobs = confidence->GetStatistic();
      b_hist->SetMaximum(max);
      b_hist->SetMinimum(0.8);
      TLine *line = new TLine(LLRobs,0.8,LLRobs,max);
      line->SetLineWidth(3);
      line->Draw();
      c_LLR->SetLogy();
      leg = new TLegend(0.112069,0.6758475,0.4913793,0.8855932,NULL,"brNDC");
      leg->SetBorderSize(1);
      leg->SetTextFont(62);
      leg->SetLineColor(1);
      leg->SetLineStyle(1);
      leg->SetLineWidth(1);
      leg->SetFillColor(0);
      leg->SetFillStyle(1001);
      entry=leg->AddEntry("b_hist","B-only LLR","f");
      entry->SetFillColor(19);
      entry->SetFillStyle(1001);
      entry->SetLineColor(1);
      entry->SetLineStyle(1);
      entry->SetLineWidth(1);
      entry->SetMarkerColor(1);
      entry->SetMarkerStyle(1);
      entry->SetMarkerSize(1);
      entry=leg->AddEntry("sb_hist","B+S LLR","f");
      entry->SetFillStyle(1001);
      entry->SetLineColor(1);
      entry->SetLineStyle(3);
      entry->SetLineWidth(1);
      entry->SetMarkerColor(1);
      entry->SetMarkerStyle(1);
      entry->SetMarkerSize(1);
      entry=leg->AddEntry("TLine","Observed LLR","l");
      entry->SetLineColor(1);
      entry->SetLineStyle(1);
      entry->SetLineWidth(3);
      entry->SetMarkerColor(1);
      entry->SetMarkerStyle(21);
      entry->SetMarkerSize(1);
      leg->Draw();

      string LLRname = filename;
      LLRname= LLRname.substr(LLRname.find("gww_"));
      LLRname= LLRname.substr(0,LLRname.find(".root"));
      LLRname="./plots/latest/"+LLRname;

      LLRname+=Form("_LLR_m%i_%.2fxXsec_%irebin.png",mass,xsec_factor,rebin);
      c_LLR->SaveAs(LLRname.c_str());

    }    

    datasource  = new TLimitDataSource();
    if (n_systematics == 0) datasource->AddChannel(sh,bh,dh);
    else datasource->AddChannel(sh,bh,dh,&errors,&errorb,names);    
    infile->Close();
  } // end of channel loop
  confidence = TLimit::ComputeLimit(datasource,precision);
  
    
  CL[0] = confidence->CLs();
  CL[1] = confidence->GetExpectedCLs_b(-2); 
  CL[2] = confidence->GetExpectedCLs_b(-1);
  CL[3] = confidence->GetExpectedCLs_b(0); 
  CL[4] = confidence->GetExpectedCLs_b(1);
  CL[5] = confidence->GetExpectedCLs_b(2);

  CL[6] = confidence->CLsb();
  CL[7] = confidence->GetExpectedCLsb_b(-2); 
  CL[8] = confidence->GetExpectedCLsb_b(-1);
  CL[9] = confidence->GetExpectedCLsb_b(0); 
  CL[10] = confidence->GetExpectedCLsb_b(1);
  CL[11] = confidence->GetExpectedCLsb_b(2);
  
  delete confidence;
  delete datasource;
  return CL;
}

int doLimit(TString MassFile="mass.list", TString XsecFile="xsec.list", TString ListFile="channels.list", Float_t xsfl=1., Float_t xsfh=1., Float_t xsfs=1., Int_t rebin = 1, TString outname = "hwwcombined")
{
  TString outtxtfile = "./exclusion_limits/"+outname+".limits";

  // then open the MassFile to get the list of masses
  ifstream infile2((const char*)MassFile);
  if (!infile2) { cerr << "Fichier mass non existant" << endl; return -1; }
  TString mass[maxmass];
  int line = 0;
  while(infile2 >> mass[line++]){
    if(line>=maxmass) { cout << "Too many masses, using only " << maxmass << endl; break; 
    }
  }
  infile2.close();
  Int_t nma = line -1;

  // then open the XsecFile to get the list of xseces
  ifstream infile3((const char*)XsecFile);
  if (!infile3) { cerr << "Fichier xsec non existant" << endl; return -1; }
  TString xsec[maxmass];
  line = 0;
  while(infile3 >> xsec[line++]){
    if(line>=maxmass) { cout << "Too many xsecs, using only " << maxmass << endl; break; 
    }
  }
  infile3.close();
  //  Int_t nxsec = line -1;

  // open the output text file
  ofstream outfile(outtxtfile);

  // big loop over the masses
  for(Int_t midx=0;midx<nma;midx++)
    {
      // big loop over the cross-sections
      for(Float_t xsec_fact=xsfl;xsec_fact<=xsfh;xsec_fact+=xsfs)
	{
	  int amass = mass[midx].Atoi();
	  double axsec = xsec[midx].Atof();
	  
	  double* CL = ConfidenceLevels(xsec_fact,amass,rebin,ListFile);
	  cout << amass << " GeV " << xsec_fact * axsec << " pb - 1-CLs: " << 1 - CL[0] << endl;
	  outfile << amass << " ";
	  outfile << xsec_fact*axsec << " ";
	  for(Int_t i_CL = 0; i_CL<12; i_CL++) outfile << CL[i_CL] << " ";
	  outfile << endl;
	  if ( 
	      CL[0] < 0.04 && // cls
	      CL[1] < 0.04 && // ecls-2
	      CL[6] < 0.04 && // clsb
	      CL[7] < 0.04   // eclsb-2
	      ) break;
	}
    }

  // conclusion (close all what remains open)
  outfile.close();
  return 0;
}
