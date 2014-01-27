#include "../include/lnuj_bkgd_list.h"
#include "../include/wwFileInfo.h"
#include <iostream>
#include <iomanip>
#include <TGraphErrors>

TString proc_type="lnuj";

const int nCuts=3;
string cuts[nCuts] = {"lt","ht","st"};

const int nVals=25;
string vals[nVals] = {"100","125","150","175","200","225","250",
		      "275","300","325","350","375","400","425",
		      "450","475","500","525","550","575","600",
		      "625","650","675","700"};
double values[nVals] =  {100,125,150,175,200,225,250,
			 275,300,325,350,375,400,425,
			 450,475,500,525,550,575,600,
			 625,650,675,700};


void printSigEff(){

  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In printSigEff.C"<<endl;

  TObjArray* files=new TObjArray();

  string file_loc = "../plots/merged/";

  vector<int>* v_signals = new vector<int>;
  for(int s=0;s<nBkgds;s++){

    string cur_file = file_loc+bkgd_list[s];
    cur_file+=".sig.eff.root";

    v_signals->push_back(cur_file.find("gww")!=string::npos);

    cout<<cur_file<<endl;

    TFile* curFile = TFile::Open(cur_file.c_str());
    
    files->Add(curFile);
  }

  int file_info_n = files->GetEntries();




  
  


  //////////////////////////////////////////////////
  // Count all background events
  // evt_n: before MET cut
  // cut_n: after any nCut/nVal cut (e.g. Lt > 150)
  //////////////////////////////////////////////////
  double tot_bkgd_evt_n=0.;
  double tot_bkgd_cut_n[nCuts][nVals]={0};


  //////////////////////////////////////////////////
  // Count all signal events
  // vector so that multiple signal points can be run at same time (e.g. gww.m500, gww.m1250, etc
  //////////////////////////////////////////////////
  vector<double> tot_sig_evt_n;
  vector<double> tot_sig_cut_n[nCuts][nVals];


  //Store name of Signal (e.g. gww.m500) to print later
  vector<string>* sig_name = new vector<string>;

  //Loop over all background and signal files to count events
  for(int f=0;f<file_info_n;f++){

    bool isSignal = (v_signals->at(f)) ? true : false;
    TFile* curFile = (TFile*) files->At(f);

    //Total Events before any cuts
    TH1F* h_evt_n = (TH1F*) curFile->Get("h_evt_n");

    if(isSignal){

      sig_name->push_back(curFile->GetName());
      tot_sig_evt_n.push_back(h_evt_n->Integral());

    } else {

      tot_bkgd_evt_n+=h_evt_n->Integral();

    }

    //Loop over all cut histograms made
    for(int c=0;c<nCuts;c++){

      string cur_name = "h_"+cuts[c]+"_";

      for(int v=0;v<nVals;v++){

	string hist_name = cur_name+vals[v]+"_cuts_n";
	TH1F* cur_cut_hist = (TH1F*) curFile->Get(hist_name.c_str());

	if(!cur_cut_hist) cout<<"Can not find hist: "<<hist_name<<", in "<<curFile->GetName()<<endl;

	if(isSignal){
	  tot_sig_cut_n[c][v].push_back(cur_cut_hist->Integral());
	}else{
	  tot_bkgd_cut_n[c][v]+=cur_cut_hist->Integral();
	}
      }
    }
  }	


  //////////////////////////////////////////////////
  // Graphs of S/B vs Sig Accep
  //////////////////////////////////////////////////
  int n_tge_bins = nVals;
  double tge_sig_to_bkgd[nCuts][nVals]={0.};
  double tge_sig_eff[nCuts][nVals]={0.};
  double tge_sig_to_bkgd_eff[nCuts][nVals]={0.};
  
  TMultiGraph* mg_sig = new TMultiGraph();
  mg_sig->SetTitle("S/B vs Sig Eff");


  TMultiGraph* mg_sig_to_bkgd = new TMultiGraph();
  mg_sig_to_bkgd->SetTitle("S/B vs Cut Value");
  TLegend* lgnd_sig_to_bkgd = new TLegend(0.12,0.88,0.22,.78);
  lgnd_sig_to_bkgd->SetFillColor(0);
  lgnd_sig_to_bkgd->SetTextSize(0.04);

  TMultiGraph* mg_sig_eff = new TMultiGraph();
  mg_sig_eff->SetTitle("Signal Efficiency vs Cut Value");
  TLegend* lgnd_sig_eff = new TLegend(0.12,0.28,0.22,.18);
  lgnd_sig_eff->SetFillColor(0);
  lgnd_sig_eff->SetTextSize(0.04);

  TMultiGraph* mg_sig_to_bkgd_eff = new TMultiGraph();
  mg_sig_to_bkgd_eff->SetTitle("S/B*Eff vs Cut Value");
  TLegend* lgnd_sig_to_bkgd_eff = new TLegend(0.12,0.88,0.22,.78);
  lgnd_sig_to_bkgd_eff->SetFillColor(0);
  lgnd_sig_to_bkgd_eff->SetTextSize(0.04);


  //////////////////////////////////////////////////
  // Print Results
  //////////////////////////////////////////////////
  
  for(int s=0;s<tot_sig_evt_n.size();s++){//Each signal point, eg. m500,m1000

    cout<<"Signal "<<sig_name->at(s)<<endl;//FIXME: replace with string
    cout<<endl;
    cout<<"Initial S/B : "<<tot_sig_evt_n.at(s)/tot_bkgd_evt_n<<endl;
    cout<<"--"<<endl;
    cout<<"(Var>Cut)\tSig/Bkgd\tSignal Acceptance %\tS/B*Eff"<<endl;
    cout<<"--"<<endl;

    for(int c=0;c<nCuts;c++){
      for(int v=0;v<nVals;v++){

	double sig_to_bkgd = (tot_sig_cut_n[c][v].at(s)/tot_bkgd_cut_n[c][v]);
	double sig_eff = tot_sig_cut_n[c][v].at(s)/tot_sig_evt_n.at(s);
	double sig_to_bkgd_eff = sig_to_bkgd*sig_eff;
	
	//TMP, expand to make TGE for each signal 
	if(!s){
	  tge_sig_to_bkgd[c][v]= sig_to_bkgd;
	  tge_sig_eff[c][v] = sig_eff;
	  tge_sig_to_bkgd_eff[c][v]= sig_to_bkgd_eff;
	}
	
	cout<<"("<<cuts[c]<<">"<<values[v]<<" GeV)\t";
	//cout<<cut_hist[c][v]<<" S/B: ";

	cout<<sig_to_bkgd;
	cout<<"\t"<<100*sig_eff<<" %";
	cout<<"\t"<<sig_to_bkgd_eff;
	cout<<endl;
	//cout<<"\t"<<tot_sig_cut_n[c][v].at(s)<<", "<<tot_bkgd_cut_n[c][v]<<endl;
	
      }
    
      cout<<endl;
      TGraphErrors* cur_tge_sig =  new TGraphErrors(nVals,tge_sig_to_bkgd[c],tge_sig_eff[c]);
      cur_tge_sig->SetMarkerColor(c+2);
      cur_tge_sig->SetLineColor(c+2);
      mg_sig->Add(cur_tge_sig);

      //Cut Values vs. Signal to Background
      TGraphErrors* cur_tge_sig_to_bkgd =  new TGraphErrors(nVals,values,tge_sig_to_bkgd[c]);
      cur_tge_sig_to_bkgd->SetMarkerColor(c+2);
      cur_tge_sig_to_bkgd->SetLineColor(c+2);

      lgnd_sig_to_bkgd->AddEntry(cur_tge_sig_to_bkgd,cuts[c].c_str());	    
      mg_sig_to_bkgd->Add(cur_tge_sig_to_bkgd);

      //Cut Values vs. Signal Efficiency
      TGraphErrors* cur_tge_sig_eff =  new TGraphErrors(nVals,values,tge_sig_eff[c]);
      cur_tge_sig_eff->SetMarkerColor(c+2);
      cur_tge_sig_eff->SetLineColor(c+2);

      lgnd_sig_eff->AddEntry(cur_tge_sig_eff,cuts[c].c_str());	    
      mg_sig_eff->Add(cur_tge_sig_eff);

      //Cut Values vs. S/B*Signal Efficiency
      TGraphErrors* cur_tge_sig_to_bkgd_eff =  new TGraphErrors(nVals,values,tge_sig_to_bkgd_eff[c]);
      cur_tge_sig_to_bkgd_eff->SetMarkerColor(c+2);
      cur_tge_sig_to_bkgd_eff->SetLineColor(c+2);

      lgnd_sig_to_bkgd_eff->AddEntry(cur_tge_sig_to_bkgd_eff,cuts[c].c_str());	    
      mg_sig_to_bkgd_eff->Add(cur_tge_sig_to_bkgd_eff);

    }
  }


  
  // mg_sig->Draw("AL*");
  // mg_sig->GetXaxis()->SetTitle("S/B");
  // mg_sig->GetYaxis()->SetTitle("Sig Eff % [GeV]");
  // mg_sig->Draw("AL*");


  TCanvas* tc_sig_to_bkgd = new TCanvas("tc_sig_to_bkgd","S/B",0,0,1280,800);
  tc_sig_to_bkgd->cd();


  mg_sig_to_bkgd->Draw("AL*");
  mg_sig_to_bkgd->GetXaxis()->SetTitle("Cut Value");
  mg_sig_to_bkgd->GetYaxis()->SetTitle("S/B");
  mg_sig_to_bkgd->Draw("AL*");
  lgnd_sig_to_bkgd->Draw();


  TCanvas* tc_sig_eff = new TCanvas("tc_sig_eff","Signal Efficiency",0,0,1280,800);
  tc_sig_eff->cd();


  mg_sig_eff->Draw("AL*");
  mg_sig_eff->GetXaxis()->SetTitle("Cut Value");
  mg_sig_eff->GetYaxis()->SetTitle("Signal Efficiency %");
  mg_sig_eff->Draw("AL*");
  lgnd_sig_eff->Draw();


  TCanvas* tc_sig_to_bkgd_eff = new TCanvas("tc_sig_to_bkgd_eff","S/B*Signal Efficiency",0,0,1280,800);
  tc_sig_to_bkgd_eff->cd();


  mg_sig_to_bkgd_eff->Draw("AL*");
  mg_sig_to_bkgd_eff->GetXaxis()->SetTitle("Cut Value");
  mg_sig_to_bkgd_eff->GetYaxis()->SetTitle("S/B*Signal Efficiency");
  mg_sig_to_bkgd_eff->Draw("AL*");
  lgnd_sig_to_bkgd_eff->Draw();

}
