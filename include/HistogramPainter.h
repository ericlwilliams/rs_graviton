#ifndef HistogramPainter_h
#define HistogramPainter_h

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <TObjArray.h>
#include <THStack.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TLegend.h>
#include <TList.h>
#include <TBox.h>
#include <TLine.h>
#include <TPad.h>
#include "wwFileInfo.h"
//#include "wwXSec.h"
#include "wwVarInfo.h"
#include "TH1.h"
#include "atlasstyle-00-03-04/AtlasLabels.C"
#include "../src/lvjjHelper.h"

bool neglectUncertainty = true;

//////////////////////////////////////////////////
// in lvjjHelper
////////////////////////////////////////////////// 
// bool doPartialUnblind = true;


string data_file_name="../plots/";
string procs[] = {"ee","uu","eu"};
string save_loc="../canvases/latest/";

double lumi_uncert=0.039;//0.1 low value for vjets uncert

class HistogramPainter : public TObject {

  // HistogramPainter class
  // input: histogram (e.g. "MET_proj"), files, wwFileInfos
  // returns: TCanvas to print
  // needs: Histogram Sorter to arrange order of printing
  // Methods
  // GetHistogram(string proc);
  // Draw:
  // - Called with "{proc}_{var}" eg "ee_met_proj"
  // - if {proc} left out, eg "met_proj", will draw all three channels
  
 private:
  int file_n;
  int sig_n;

  bool is_sideband_scaled;  
  TObjArray* files;
  TObjArray* file_infos;
  TObjArray* sig_files;
  TObjArray* sig_file_infos;
  string proc_type;
  string sample;

  
  TFile* data_file;



  int max_find(vector<double>& max_vals);

 public:
  HistogramPainter(TString procType,TObjArray *toj_file_infos,bool isSidebandScaled=false);
  ~HistogramPainter(){};
  THStack* BuildStack(string hist_name,string dir_name="");

  TLegend* BuildLegend(THStack* stk,TH1F* data_hist=0,TObjArray* sig_hists=0,string location="upper-right",bool drawdata);

  TObjArray* GetHistograms(string hist_name,string type,string dir_name="",bool is_lowm,bool is_highm);
  TObjArray* SortHistograms(string hist_name,TObjArray* toj_hists,vector<int>& inds);
  
  TH1F* GetDataHistogram(string hist_name,string dir_name="");
  TH1F* MakeRatio(string ratio_name,TPad* pad,THStack* stk, TH1F* data);
  double pValuePoisson(unsigned nObs,double nExp);
  double pValuePoissonError(unsigned nObs,double E,double V);
  double pValueToSignificance(double p,bool excess);
  TH1F* MakeSignificanceRatio(string ratio_name,TPad* pad,THStack* stk, TH1F* data,bool isSidebandScaled);
  void SetStackLimits(THStack* stk,TH1F* data_hist=0,bool do_logy,float& cur_ymax);

  void Draw(string todraw,string draw_dir="all",string save_ext=".gif",string proc="gww",bool draw_data=true,bool draw_text=true,bool draw_cuts=false);
  //TObjArray* GetCanvases(string todraw,string gen,string draw_dir="all",string save_ext=".gif",string proc="gww",bool draw_data=true);
  void PrintInfo();
  
  ClassDef(HistogramPainter,0);
};


HistogramPainter::HistogramPainter(TString procType,TObjArray *toj_file_infos,bool isSidebandScaled){

  //file_infos=toj_file_infos;
  file_n=0;
  sig_n=0;
  is_sideband_scaled=isSidebandScaled;
  
  
  files = new TObjArray();
  file_infos= new TObjArray();

  sig_files = new TObjArray();
  sig_file_infos = new TObjArray();

  proc_type=procType;

  
  for(int f=0;f<toj_file_infos->GetEntries();f++){

    wwFileInfo* curFileInfo = (wwFileInfo*) toj_file_infos->At(f);
    TFile* cur_file = (TFile*) curFileInfo->MergedFile();
    
    if(curFileInfo->IsSignal()){
      sig_files->Add(cur_file);
      sig_file_infos->Add(curFileInfo);
      ++sig_n;
    }else{
      ++file_n;
      files->Add(cur_file);
      file_infos->Add(curFileInfo);
    }
  }

  string cur_data_file_name = data_file_name;
  if(proc_type=="ctrl"){
    cur_data_file_name+=proc_type+"_plots/merged/data.lnuj.ctrl.plot.root";
  }else if(proc_type=="jvf"){
    cur_data_file_name+=proc_type+"_plots/merged/data.lnuj.plot.jvf.root";
  }else if(proc_type=="nojvf"){
    cur_data_file_name+=proc_type+"_plots/merged/data.lnuj.plot.nojvf.root";
  }else{
    cur_data_file_name+=proc_type+"_plots/merged/data.lnuj.plot.root";
  }

  data_file = (TFile*) TFile::Open(cur_data_file_name.c_str());

  if(!data_file) cout<<cur_data_file_name<<" could not be found!"<<endl;
  
  
}


int HistogramPainter::max_find(vector<double>& max_vals)
  {
    double max = 0; // This may need to be initalised different base on your data
    int max_ind = 0;
    for (int i = 0; i < max_vals.size(); i++)
      {
	if (max < max_vals.at(i)){
	  max = max_vals.at(i);
	  max_ind = i;
	}
      }

    max_vals.erase(max_vals.begin()+max_ind);
    return max;
  }
  

TObjArray* HistogramPainter::SortHistograms(string hist_name,TObjArray* toj_hists,vector<int>& inds){


  vector<double> maxs;
  vector<double> maxs_copy;

  for(int h=0;h<toj_hists->GetEntries();h++){
    TH1F* cur_hist = (TH1F*) toj_hists->At(h);

    //cout<<"check: "<<((wwFileInfo*) files->At(h))->GetShortProc()<<endl;
    //Ordering Determinator
    double cur_max = cur_hist->Integral();
    
    maxs.push_back(cur_max);
    maxs_copy.push_back(cur_max);
  }

  vector<double> max_sorted;
  
  bool sorted=false;

  while(!sorted){
    double cur_max = max_find(maxs_copy);
    max_sorted.push_back(cur_max);
    if(!maxs_copy.size()) sorted=true;
  }

  TObjArray* toj_sorted_hists = new TObjArray();

  //to list from small to big, rather than big to small
  reverse(max_sorted.begin(),max_sorted.end());

  vector<int> found_inds;

  for(int j=0;j<max_sorted.size();j++){

    double cur_sorted_max = max_sorted.at(j);
    
    bool found=false;
    for(int i=0;i<maxs.size();i++){
      if(cur_sorted_max==maxs.at(i)){

	//check that it hasn't already been loaded (repeat maxs[j]);
	for(int k=0;k<found_inds.size();k++){
	  if(i==found_inds.at(k)) found=true;
	  break;
	}

	if(!found){
	  //i is index in maxs and toj_hists of current max.
	  toj_sorted_hists->Add((TH1F*) toj_hists->At(i));
	  inds.push_back(i);
	  found_inds.push_back(i);
	}
      }
    }
  }

  return toj_sorted_hists;
}

TObjArray* HistogramPainter::GetHistograms(string hist_name,string type,string dir_name,bool is_lowm,bool is_highm){

  TObjArray* cur_hists = new TObjArray();
  //string cur_hist_name = "h_"+hist_name;
  string get_hist_name = (dir_name!="") ? dir_name+"/h_" : "h_";
  get_hist_name += hist_name;

  bool isSig = (type=="sig");
  
  TObjArray* cur_files = new TObjArray();
  cur_files = (isSig) ? sig_files : files;
  int cur_file_n = 0;
  cur_file_n = (isSig) ? sig_n : file_n;

  TObjArray* cur_file_infos = new TObjArray();
  cur_file_infos = (isSig) ? sig_file_infos : file_infos;

  for(int f=0;f<cur_file_n;f++){

    wwFileInfo* cur_file_info = (wwFileInfo*) cur_file_infos->At(f);
    string cur_file_name = ((wwFileInfo*) cur_file_info)->GetFileName();

    TFile* cur_file = (TFile*) cur_files->At(f);

    cur_file->cd(dir_name.c_str());

    TH1F* cur_hist = (TH1F*) cur_file->Get(get_hist_name.c_str());

    if(!cur_hist){
      cout<<"No histogram "<<get_hist_name<<" in "<<cur_file->GetName()<<":~/"<<dir_name<<endl;
      return 0;
    }

    string cur_hist_name = "h_";
    string cur_proc_name = cur_file_info->GetFileName();
    cur_hist_name+=cur_proc_name+"_";
    cur_hist_name+=hist_name;
    cur_hist->SetName(cur_hist_name.c_str());

    double cur_line_width = cur_file_info->GetLineWidth();
    cur_hist->SetLineWidth(cur_line_width);

    int f_style = cur_file_info->GetFillStyle();
    if(f_style<0 || isSig){//wjets, sig
      cur_hist->SetLineColor(cur_file_info->GetColor());
    }else{
      cur_hist->SetFillColor(cur_file_info->GetColor());
      //tmp
      //cur_hist->SetLineColor(cur_file_info->GetColor());
      cur_hist->SetFillStyle(f_style);
      
    }
      
    //cur_hist->SetFillStyle(cur_file_info->GetFillStyle());
    cur_hist->SetLineStyle(cur_file_info->GetLineStyle());
    cur_hists->Add(cur_hist);
    //cout<<"Adding: "<<cur_hist_name<<endl;
  }

  return cur_hists;

}


THStack* HistogramPainter::BuildStack(string hist_name,string dir_name){

  TObjArray* cur_hists = (TObjArray*) GetHistograms(hist_name,"bkgd",dir_name,false,false);

  if(cur_hists->GetEntries()==0){
    cout<<"No entries in histogram "<<hist_name<<" found!"<<endl;
    return 0;
  }
  string cur_stack_name = "stk_"+hist_name;
  string cur_canvas_name = "tc_"+hist_name;

  vector<int> sorted_inds;//indicies after sorting
  
  TObjArray* toj_sorted_hists = (TObjArray*) SortHistograms(hist_name,cur_hists,sorted_inds);


  THStack* hist_stack = new THStack(cur_stack_name.c_str(),hist_name.c_str());

  for(int i=0;i<toj_sorted_hists->GetEntries();i++){

    TH1F* cur_hist =(TH1F*) toj_sorted_hists->At(i);

    //////////////////////////////////////////////////
    // TMP, moving lumi and systemtaic errors to MakeSignificance */
    //////////////////////////////////////////////////

  /*   string cur_hist_name=cur_hist->GetName(); */
  /*   if(/\*cur_hist_name.find("qcd")==string::npos && *\/// TMP including lumi uncertainty on QCD */
  /*      cur_hist_name.find("data")==string::npos){// useless, data not passed to this function */

  /*     float cur_uncert = lumi_uncert; */
  /*     //float cur_uncert = 0; */

  /*     if(is_sideband_scaled && */
  /*     	 (cur_hist_name.find("ctrl_highm")!=string::npos || */
  /*     	   cur_hist_name.find("sig_highm")!=string::npos || */
  /*     	   cur_hist_name.find("lowsb_highm")!=string::npos || */
  /*     	  cur_hist_name.find("highsb_highm")!=string::npos)) */
  /*   	cur_uncert+=0.06; */

  /*     // Loop over Bins, set errors */
  /*     int bin_n = cur_hist->GetXaxis()->GetNbins(); */
  /*     for(int b=1;b<bin_n+1;b++){ */
  /*   	double cur_err = cur_hist->GetBinError(b); */
  /*   	double cur_val = cur_hist->GetBinContent(b); */

  /*   	// Luminosity err */
  /*   	double lumi_err = cur_val*cur_uncert; */
    	
		
  /*    	double bin_err = sqrt(pow(lumi_err,2.)+pow(cur_err,2.)); */
  /*   	cur_hist->SetBinError(b,bin_err); */
  /*     } */
  /*   } */
    
    cur_hist->SetMarkerSize(0);
    hist_stack->Add(cur_hist,"hist");
  }


  return hist_stack;
}

TLegend* HistogramPainter::BuildLegend(THStack* stk,TH1F* data_hist,TObjArray* sig_hists, string location,bool drawdata){
  //Builds TLegened with histograms
  //Default location now, FIXME: position as argument (e.g. "upper-left","upper-right", etc)


  TObjArray* tmp_histos = (TObjArray*) stk->GetHists();
  TObjArray* histos = (TObjArray*) tmp_histos->Clone();
  if(data_hist) histos->Add(data_hist);

  for(int i=0;i<sig_hists->GetEntries();i++) 
    histos->AddFirst((TH1F*) sig_hists->At(i)); 

  /* int nHistos = histos->GetEntries(); */
  /* cout<<nHistos<<endl; */

  double x0,x1,y0,y1;

  if(location=="upper-right"){
    x0=0.76;
    x1=0.88;
    y0=0.50;
    y1=0.92;
  }else if (location=="lower-right"){
    x0=0.65;
    x1=0.9;
    y0=0.05;
    y1=0.45;
  }else if (location=="upper-left"){
    x0=0.18;
    x1=0.48;
    y0=0.65;
    y1=0.92;
  }else if (location=="lower-left"){
    x0=0.22;
    x1=0.52;
    y0=0.10;
    y1=0.37;
  }else{
    cout<<"Invalid Legend location: "<<location<<endl;
    return 0;
  }

  TLegend* return_legend = new TLegend(x0,y0,x1,y1);  
  return_legend->SetFillStyle(0);
  if(drawdata){
    return_legend->SetTextSize(0.05);
  }else{
    return_legend->SetTextSize(0.04);
  }
  return_legend->SetBorderSize(0);
  //for(int h=0;h<histos->GetEntries();h++){
  int cur_ind=0;

  float bkgd_n=0.;
  float data_n=0.;
  float wj_n=0.;
  float non_wj_n=0.;
  for(int h=histos->GetEntries()-1;h>=0;h--){

    TH1F* hist = (TH1F*) histos->At(h);

    //Find FileInfo Location
    //char* char_hist_name = hist->GetName();
    string char_hist_name = hist->GetName();


    string cur_hist_name = char_hist_name;
    string sub_hist_name = cur_hist_name.substr(2);
    
    //FIXME: Edit for legend entry!
    string proc_name = sub_hist_name.substr(0,sub_hist_name.find_first_of("_"));

    if(proc_name.find("data")!=string::npos){
      data_n+=hist->Integral();
    }else if(proc_name.find("lvjj")==string::npos){//don't add signal to background count
      bkgd_n+=hist->Integral();
    }
    if(proc_name.find("wjets")!=string::npos){
      wj_n+=hist->Integral();
    }else if(proc_name.find("data")==string::npos && proc_name.find("lvjj")==string::npos){
      non_wj_n+=hist->Integral();
    }

    string lgnd_proc_name = proc_name;
    string lgnd_proc_option="F";
    if(proc_name.find("data")!=string::npos){
      lgnd_proc_name="Data";
      lgnd_proc_option="P";
    }else if(proc_name.find("alpgen.wjets")!=string::npos){
      lgnd_proc_name="W+jets";
    }else if(proc_name.find("sherpa.wjets")!=string::npos){
      lgnd_proc_name="W+jets (SHERPA)";
    }else if(proc_name.find("alpgen.zjets")!=string::npos){
      lgnd_proc_name="Z+jets";
    }else if(proc_name.find("sherpa.zjets")!=string::npos){
      lgnd_proc_name="Z+jets (SHERPA)";
    }else if(proc_name.find("top")!=string::npos){
      lgnd_proc_name="Top";
    }else if(proc_name.find("ttbar")!=string::npos){
      lgnd_proc_name="ttbar";
    }else if(proc_name.find("st")!=string::npos){
      lgnd_proc_name="single top";
    }else if(proc_name.find("herwig.ww")!=string::npos){
      lgnd_proc_name="WW";
    }else if(proc_name.find("herwig.wz")!=string::npos){
      lgnd_proc_name="WZ";
    }else if(proc_name.find("herwig.zz")!=string::npos){
      lgnd_proc_name="ZZ";
    }else if(proc_name.find("herwig.vv")!=string::npos){
      lgnd_proc_name="Diboson";
    }else if(proc_name.find("qcd")!=string::npos){
      lgnd_proc_name="QCD";
    }else if(proc_name.find("rsg.m500")!=string::npos){
      lgnd_proc_name="G*(500GeV)";
      lgnd_proc_option="L";
    }else if(proc_name.find("rsg.m750")!=string::npos){
      lgnd_proc_name="G*(750GeV)";
      lgnd_proc_option="L";
    }else if(proc_name.find("rsg.m1000")!=string::npos){
      lgnd_proc_name="G*(1000GeV)";
      lgnd_proc_option="L";
    }else if(proc_name.find("rsg.m1250")!=string::npos){
      lgnd_proc_name="G*(1250GeV)";
      lgnd_proc_option="L";
    }else if(proc_name.find("rsg.m1500")!=string::npos){
      lgnd_proc_name="G*(1500GeV)";
      lgnd_proc_option="L";
    }else if(proc_name.find("wprime.wz.m500")!=string::npos){
      lgnd_proc_name="W'(500GeV)";
      lgnd_proc_option="L";
    }else if(proc_name.find("wprime.wz.m600")!=string::npos){
      lgnd_proc_name="W'(600GeV)";
      lgnd_proc_option="L";
    }else if(proc_name.find("wprime.wz.m700")!=string::npos){
      lgnd_proc_name="W'(700GeV)";
      lgnd_proc_option="L";
    }else if(proc_name.find("wprime.wz.m800")!=string::npos){
      lgnd_proc_name="W'(800GeV)";
      lgnd_proc_option="L";
    }else if(proc_name.find("wprime.wz.m900")!=string::npos){
      lgnd_proc_name="W'(900GeV)";
      lgnd_proc_option="L";
    }else if(proc_name.find("wprime.wz.m1000")!=string::npos){
      lgnd_proc_name="W'(1000GeV)";
      lgnd_proc_option="L";
    }else if(proc_name.find("wprime.wz.m1100")!=string::npos){
      lgnd_proc_name="W'(1100GeV)";
      lgnd_proc_option="L";
    }else if(proc_name.find("wprime.wz.m1200")!=string::npos){
      lgnd_proc_name="W'(1200GeV)";
      lgnd_proc_option="L";
    }else if(proc_name.find("wprime.wz.m1300")!=string::npos){
      lgnd_proc_name="W'(1300GeV)";
      lgnd_proc_option="L";
    }else if(proc_name.find("wprime.wz.m1400")!=string::npos){
      lgnd_proc_name="W'(1400GeV)";
      lgnd_proc_option="L";
    }else if(proc_name.find("wprime.wz.m1500")!=string::npos){
      lgnd_proc_name="W'(1500GeV)";
      lgnd_proc_option="L";
    }else if(proc_name.find("afii.kkg.lvjj.m500")!=string::npos){
      lgnd_proc_name="G_{kk}(500GeV)";
      lgnd_proc_option="L";
    }else if(proc_name.find("afii.kkg.lvjj.m600")!=string::npos){
      lgnd_proc_name="G_{kk}(600GeV)";
      lgnd_proc_option="L";
    }else if(proc_name.find("afii.kkg.lvjj.m700")!=string::npos){
      lgnd_proc_name="G_{kk}(700GeV)";
      lgnd_proc_option="L";
    }else if(proc_name.find("afii.kkg.lvjj.m800")!=string::npos){
      lgnd_proc_name="G_{kk}(800GeV)";
      lgnd_proc_option="L";
    }else if(proc_name.find("afii.kkg.lvjj.m900")!=string::npos){
      lgnd_proc_name="G_{kk}(900GeV)";
      lgnd_proc_option="L";
    }else if(proc_name.find("afii.kkg.lvjj.m1000")!=string::npos){
      lgnd_proc_name="G_{kk}(1000GeV)";
      lgnd_proc_option="L";
    }else if(proc_name.find("afii.kkg.lvjj.m1100")!=string::npos){
      lgnd_proc_name="G_{kk}(1100GeV)";
      lgnd_proc_option="L";
    }else if(proc_name.find("afii.kkg.lvjj.m1200")!=string::npos){
      lgnd_proc_name="G_{kk}(1200GeV)";
      lgnd_proc_option="L";
    }else if(proc_name.find("afii.kkg.lvjj.m1300")!=string::npos){
      lgnd_proc_name="G_{kk}(1300GeV)";
      lgnd_proc_option="L";
    }else if(proc_name.find("afii.kkg.lvjj.m1400")!=string::npos){
      lgnd_proc_name="G_{kk}(1400GeV)";
      lgnd_proc_option="L";
    }else if(proc_name.find("afii.kkg.lvjj.m1500")!=string::npos){
      lgnd_proc_name="G_{kk}(1500GeV)";
      lgnd_proc_option="L";
    }

    //Get Entries
    char lgndName[150];

    //sprintf(lgndName,"%s,  %.2f",proc_name.c_str(),hist->Integral());
    //return_legend->AddEntry(hist,lgndName,lgnd_proc_option.c_str());
    return_legend->AddEntry(hist,lgnd_proc_name.c_str(),lgnd_proc_option.c_str());
    ++cur_ind;
  }


  float data_mc_ratio = (data_n) ? data_n/bkgd_n : 1.;

  float data_stat_err = sqrt(data_n);

  float bkgd_stat_err = sqrt(bkgd_n);
  //float data_mc_stat_err = data_mc_ratio*sqrt((pow((data_stat_err/data_n),2.)+pow((bkgd_stat_err/bkgd_n),2.)));
  float data_mc_stat_err = (data_n) ? data_mc_ratio*((data_stat_err/data_n) + (bkgd_stat_err/bkgd_n)) : 0;

  float wj_sf = (data_n-non_wj_n)/wj_n;
  float wj_sf_err = ((data_stat_err+sqrt(non_wj_n))/(data_n-non_wj_n))+(sqrt(wj_n)/wj_n);
      
  /* char headerName[150]; */
  /* sprintf(headerName,"(%s  %.3f +- %.3f)  (%s %.3f +- %.3f)", */
  /* 	  "data/mc:",data_mc_ratio,data_mc_stat_err,"wjets_sf:",wj_sf,wj_sf_err); */
  /* return_legend->SetHeader(headerName); */
  
  return return_legend;
}

TH1F* HistogramPainter::GetDataHistogram(string hist_name,string dir_name){

  char char_hist_name[150];
  sprintf(char_hist_name,"h_%s",hist_name.c_str());
  string get_hist_name = char_hist_name;
  
  //string get_hist_name = "h_"+hist_name;
  string data_hist_name = "h_data_"+hist_name;

  if(!data_file->cd(dir_name.c_str())){
    cout<<"No directory: "<<dir_name<<" located in: "<<data_file->GetName()<<endl;
    return 0;
  }


  //TH1F* cur_data_hist = (TH1F*) data_file->Get(get_hist_name.c_str());
  TH1F* cur_data_hist = (TH1F*) gDirectory->Get(get_hist_name.c_str());
  if(!cur_data_hist){
    cout<<get_hist_name<<" could not be found in "
	<<data_file->GetName()<<":~/"<<dir_name<<endl;
    return 0;
  }else{

    cur_data_hist->SetName(data_hist_name.c_str());
    cur_data_hist->SetMarkerStyle(20);
    cur_data_hist->SetMarkerSize(2);
    return cur_data_hist;
  }
}



void HistogramPainter::SetStackLimits(THStack* stk,TH1F* data_hist,bool do_logy, float& cur_ymax){

  TObjArray* stk_histos = (TObjArray*) stk->GetHists();

  double maxy = (data_hist) ? data_hist->GetMaximum() : -1.;


  bool gotName=false;
  string hist_name="";
  for(int i=0;i<stk_histos->GetEntries();i++){

    TH1F* cur_stk_hist = (TH1F*) stk_histos->At(i);
    if(!gotName){
      hist_name = cur_stk_hist->GetName();
      gotName=true;
    }
    double cur_maxy = cur_stk_hist->GetMaximum();
    if(cur_maxy>maxy) maxy=cur_maxy;
  }

  if(!data_hist) maxy*=3.5;

  if(!do_logy) maxy*=1.1;
  //tmp, for thesis preselection plots
  //if(!do_logy) maxy*=0.45;

  /* if(!data_hist && (hist_name.find("lep_eta")!=string::npos || */
  /* 		    hist_name.find("jet_eta")!=string::npos)){ */
  /*   maxy*=5; */
  /* } */
      
  cur_ymax=maxy;
  stk->SetMaximum(maxy);
  stk->SetMinimum(0.1);

  return;
}



void HistogramPainter::Draw(string todraw,string draw_dir,string save_ext, string proc,bool draw_data,bool draw_text, bool draw_cuts){


  //cout<<"HistogramPainter::Draw("<<todraw<<","<<draw_dir<<","<<save_ext<<","<< proc<<","<< draw_data<<")"<<endl;
  string cur_draw_dir = draw_dir;
  string cur_todraw = todraw;
      
  if(todraw.find('\/')<todraw.size()){
    cur_todraw = todraw.substr(todraw.find_first_of("/")+1);
  }

  string cur_proc = cur_todraw.substr(0,cur_todraw.find_first_of("_"));
  string cur_var = cur_todraw.substr(cur_todraw.find_first_of("_")+1);

  //drop 'wjets_lowpt_(elec/muon)_'
  if(cur_var.find("wjets_lowpt")!=string::npos)
    cur_var = cur_var.substr(cur_var.find_first_of("wjets_lowpt")+17);

  bool isLowM=false;
  if(cur_var.find("lowm")!=string::npos){
    cur_var = cur_var.substr(cur_var.find_first_of("lowm")+10);
    isLowM=true;
  }

  bool isHighM=false;
  if(cur_var.find("highm")!=string::npos){
    cur_var = cur_var.substr(cur_var.find_first_of("highm")+11);
    isHighM=true;
  }

  wwVarInfo* cur_ww_var_info = new wwVarInfo(cur_var.c_str());
  
  int tmpProcs = (cur_proc=="ee" || cur_proc=="uu" || cur_proc=="eu" || cur_proc=="lep"
		  || cur_proc=="lnuj" || cur_proc=="elec" || cur_proc=="muon"
		  || cur_proc=="ttbar" || cur_proc=="ewk" || cur_proc=="sig"
		  || cur_proc == "el" || cur_proc=="mu"
		  || cur_proc=="boost" || cur_proc=="boost1" || cur_proc=="boost2"
		  || cur_proc=="lowsb" || cur_proc=="highsb" || cur_proc=="ctrl") ? 1 : 3;
		  

  const int nProcs= tmpProcs;
    
  string curProcs[nProcs];

  if(nProcs==1){
    curProcs[0]="";
  }else{
    for(int j=0;j<nProcs;j++) curProcs[j]=procs[j]+"_";
  }


  //all three
  TH1F* data_hists[nProcs];
  TH1F* ratio_hists[nProcs];
  TObjArray* sig_hists[nProcs];
  THStack* stks[nProcs];
  TLegend* lgnds[nProcs];
  TCanvas* canvases[nProcs];
  TPad* plot_pads[nProcs];
  TPad* ratio_pads[nProcs];
  double ratio_split= (draw_data) ? 0.35 : 0.1;
  for(int i=0;i<nProcs;i++){

   string cur_hist_name = curProcs[i]+cur_todraw;

   bool use_significance_ratio = (cur_hist_name.find("ctrl_highm")!=string::npos ||
				  cur_hist_name.find("lowsb_highm")!=string::npos ||
				  cur_hist_name.find("highsb_highm")!=string::npos ||
				  cur_hist_name.find("sig_highm")!=string::npos);
  
   stks[i] = (THStack*) this->BuildStack(cur_hist_name.c_str(),cur_draw_dir.c_str());
   data_hists[i] = (draw_data) ? (TH1F*) this->GetDataHistogram(cur_hist_name.c_str(),cur_draw_dir.c_str()) : 0;

   sig_hists[i] = (TObjArray*) this->GetHistograms(cur_hist_name,"sig",cur_draw_dir.c_str(),isLowM,isHighM);    
   
   if(use_significance_ratio){
     ratio_hists[i] =  (draw_data) ? this->MakeSignificanceRatio(cur_hist_name.c_str(),ratio_pads[i],stks[i],data_hists[i],is_sideband_scaled) : 0;
   }else{
     ratio_hists[i] =  (draw_data) ? this->MakeRatio(cur_hist_name.c_str(),ratio_pads[i],stks[i],data_hists[i]) : 0;
   }

   string leg_loc =
     (cur_hist_name.find("lep_phi")!=string::npos ||
      cur_hist_name.find("lep_eta")!=string::npos ||
      cur_hist_name.find("jet_eta")!=string::npos ||
      cur_hist_name.find("evt_n")!=string::npos)?
     //cur_hist_name.find("vxp_n")!=string::npos) ?
     "lower-right" :
     "upper-right";

   if(!draw_text && (cur_hist_name.find("lep_eta")!=string::npos ||
		     cur_hist_name.find("jet_eta")!=string::npos))
     leg_loc="upper-right";
      
   
   /* if(cur_hist_name.find("zoom_dijet_m")!=string::npos) */
   /*   leg_loc="upper-left"; */

   /* if(cur_hist_name.find("dijet_dr")!=string::npos) */
   /*   leg_loc="lower-left"; */
   
 //string leg_loc = (cur_hist_name.find("_eta")!=string::npos || */
   /* 		     //(cur_hist_name.find("_dijet_m")!=string::npos && */
   /* 		     cur_hist_name.find("sig")==string::npos)) ? "lower-right" : "upper-right"; */

   lgnds[i] = (TLegend*) this->BuildLegend(stks[i],data_hists[i],sig_hists[i],leg_loc.c_str(),draw_data);
   //string cur_save_name = saveas+"/"+cur_hist_name;
  
   string cur_tc_title = draw_dir+"_"+cur_hist_name;
   string cur_tc_name = "tc_"+cur_tc_title;
    
   //canvases[i] = new TCanvas(cur_tc_name.c_str(),cur_tc_title.c_str(),0,0,1024,640);
   canvases[i] = new TCanvas(cur_tc_name.c_str(),cur_tc_title.c_str(),0,0,1920,1200);
   canvases[i]->cd();

   if(draw_data){
     ratio_pads[i] = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,ratio_split);
     ratio_pads[i]->SetTopMargin(0.05);
     ratio_pads[i]->SetBottomMargin(0.31);
     ratio_pads[i]->Draw();
     //ratio_pads[i]->cd();
   }

   plot_pads[i] = new TPad("plot_pad","plot_pad",0.01,ratio_split,0.99,0.99);

   bool do_log_y = cur_ww_var_info->DoLogy();
   
   if(draw_data) {plot_pads[i]->SetBottomMargin(0);}
   else {plot_pads[i]->SetBottomMargin(0.14);}
   //else {plot_pads[i]->SetBottomMargin(0.14);}

   

   plot_pads[i]->Draw();
   plot_pads[i]->cd();
   plot_pads[i]->Update();  

   float ymax=0.;
   this->SetStackLimits(stks[i],data_hists[i],do_log_y,ymax);

   //
   /* bool draw_stk_sum=true; */
   /* ((TH1F*) stks[i]->GetStack()->Last())->Draw(""); */

   //tmp!
   //stks[i]->GetYaxis()->SetRangeUser(

   stks[i]->Draw("");
  
   if(!i){

     stks[i]->SetTitle("");
     if(draw_data){
       stks[i]->GetXaxis()->SetLabelSize(0);
       stks[i]->GetYaxis()->SetLabelSize(0.06);
       stks[i]->GetYaxis()->SetTitle("Events");
       stks[i]->GetYaxis()->SetTitleSize(0.07);
       stks[i]->GetYaxis()->SetTitleOffset(0.5);

     }else{
       string cur_stk_var = cur_ww_var_info->GetXLabel();
       stks[i]->GetXaxis()->SetTitle(cur_stk_var.c_str());
       stks[i]->GetXaxis()->SetTitle(cur_stk_var.c_str());
       stks[i]->GetXaxis()->SetTitleSize(0.065);
       stks[i]->GetXaxis()->SetTitleOffset(0.9);

       stks[i]->GetYaxis()->SetLabelSize(0.05);
       stks[i]->GetYaxis()->SetTitle("Events");
       stks[i]->GetYaxis()->SetTitleOffset(0.8);

     }
  

   }

   
   //////////////////////////////////////////////////
   // Get background Error Hist
   // Could move to MakeRatio bc it has loops over 
   // stack hists and bins already, but this works for now
   // Problem: GetHistogram only works after stks[i]->Draw
   //////////////////////////////////////////////////
    
   TH1F* stck_hist =  (TH1F*) stks[i]->GetHistogram()->Clone();

   /* if(!draw_data){//else print on ratio plot (below) */
   /*   string cur_stk_var = cur_ww_var_info->GetXLabel(); */
   /*   stck_hist->GetXaxis()->SetTitle(cur_stk_var.c_str()); */

   /* } */
   

   stck_hist->SetLineWidth(0);
   stck_hist->SetMarkerSize(0);
   stck_hist->SetLineColor(kWhite);

   //Fill stck_hist
   TObjArray* stacks = (TObjArray*) stks[i]->GetHists()->Clone();
   for(int s=0;s<stacks->GetEntries();s++){
     stck_hist->Add((TH1F*) stacks->At(s));
   }
   // Loop over Bins, set errors
   /* int bin_n = stck_hist->GetXaxis()->GetNbins(); */
 
   /* for(int b=1;b<bin_n+1;b++){ */
   /*   double cur_err = stck_hist->GetBinError(b); */
   /*   double cur_val = stck_hist->GetBinContent(b); */
   /*   // Luminosity err */
   /*   double lumi_err = cur_val*lumi_uncert; */
   /*   cur_err = sqrt(pow(lumi_err,2.)+pow(cur_err,2.)); */
   /*   stck_hist->SetBinError(b,cur_err); */

   /* } */


   stck_hist->SetFillColor(kBlack);
   stck_hist->SetFillStyle(3444);
   stck_hist->Draw("E2 same");

   lgnds[i]->Draw();
   if(data_hists[i]) data_hists[i]->Draw("PE sames");

   for(int s=0;s<sig_n;s++)
     sig_hists[i]->At(s)->Draw("HIST sames");

   if(do_log_y) plot_pads[i]->SetLogy();
 
   canvases[i]->Update();

   //////////////////////////////////////////////////
   // Make Ratio
   /////////////////////////////////////////////////// 

   if(draw_data){
     ratio_pads[i]->cd();
     ratio_pads[i]->SetGrid();
  
     TAxis* ratio_xaxis= ratio_hists[i]->GetXaxis();
     TAxis* ratio_yaxis= ratio_hists[i]->GetYaxis();
     ratio_hists[i]->SetMarkerStyle(20);
     ratio_hists[i]->SetMarkerSize(2);
     //ratio_hists[i]->GetYaxis()->SetTicks();
     if(!i){
       ratio_xaxis->SetLabelSize(0.1);
       //ratio_yaxis->SetLabelSize(0.08);

       string cur_xlabel = cur_ww_var_info->GetXLabel();
       //string xlabel = (cur_xlabel=="") ? cur_ww_var_info->GetVariableName() : cur_xlabel;
       ratio_xaxis->SetTitle(cur_xlabel.c_str());
       ratio_xaxis->SetTitleSize(0.16);
       ratio_xaxis->SetTitleOffset(0.8);
       ratio_yaxis->SetNdivisions(4,4,4);
       ratio_yaxis->SetLabelSize(0.1);


     }

     if(use_significance_ratio){
       ratio_yaxis->SetTitle("significance");
       ratio_yaxis->SetTitleSize(0.1);
       ratio_yaxis->SetTitleOffset(0.3);
       ratio_yaxis->SetRangeUser(-3,3);
       ratio_hists[i]->SetFillColor(kGreen-9);
       ratio_hists[i]->Draw("HIST");

     }else{
       ratio_yaxis->SetTitle("(data-MC)/MC");
       ratio_yaxis->SetTitleSize(0.11);
       ratio_yaxis->SetTitleOffset(0.3);
       ratio_yaxis->SetRangeUser(-0.5,0.5);
       ratio_hists[i]->Draw("PE");
     }
     canvases[i]->Update();
   }

   
   
   // CAll this
   plot_pads[i]->cd();
   canvases[i]->RedrawAxis();

   TLine cut_line;
   TBox cut_box;

   if(draw_cuts){// only use with sig_highm for now
   //if(true){
   // find cut coordinates based on name
     
     string tmp_cut = cur_hist_name.substr(15,cur_hist_name.size());
     //string tmp_cut = cur_hist_name;
     if(do_log_y) ymax*=2;
       
     double xmax = stck_hist->GetXaxis()->GetXmax();
     double xmin = stck_hist->GetXaxis()->GetXmin();
     // ymax set in SetStackLimits
     double ymin = stck_hist->GetYaxis()->GetXmin();

     double cut_x1=0;
     double cut_x2=0;
     double cut_y1=0;
     double cut_y2=0;

     bool good_cut=true;
     bool do_window=false;
     if(tmp_cut.find("nocut_dijet_pt")!=string::npos ||
	tmp_cut.find("nocut_lep_met_pt")!=string::npos ||
	tmp_cut.find("dijet_pt")!=string::npos ||
	tmp_cut.find("lep_met_pt")!=string::npos){


       cut_x1=200;
       cut_x2=200;
       cut_y1=ymin;
       cut_y2=ymax;

     }else if(tmp_cut.find("dijet_pt_frths_dijet_m")!=string::npos){
       do_window=true;

       cut_x1=65;
       cut_x2=115;
       cut_y1=ymin;
       cut_y2=ymax;

     }else{
       good_cut=false;
     }

     if(good_cut){
     
       cut_line=TLine(cut_x1,ymin,cut_x1,ymax);
       cut_line.SetLineWidth(2);
       cut_line.DrawClone();

       double range = xmax-xmin;
       cut_box = TBox(cut_x1-(range/30.),ymin,cut_x1,ymax);
       cut_box.SetFillStyle(3345);
       cut_box.SetFillColor(1);
       cut_box.DrawClone();

     if(do_window){

       cut_line=TLine(cut_x2,ymin,cut_x2,ymax);
       cut_line.SetLineWidth(2);
       cut_line.DrawClone();

       cut_box = TBox(cut_x2,ymin,cut_x2+(range/30.),ymax);
       cut_box.SetFillStyle(3345);
       cut_box.SetFillColor(1);
       cut_box.DrawClone();

     }
     }
   }





   string text_loc = "left";

   if(cur_var.find("_dphi")!=string::npos ||
      cur_var.find("_dr")!=string::npos){
     text_loc = "below";
   }
   
  
   double leg_x1 = lgnds[i]->GetX1NDC();
   double leg_y1 =  lgnds[i]->GetY1NDC();
   double leg_y2 = lgnds[i]->GetY2NDC();
   //double offset_x1 = -0.02;
   //double offset_y1 = 0.08;
   double offset_x1 = (text_loc == "left") ? 0.18 : 0.03;
   if(!draw_data) offset_x1+=0.03;
   double offset_x2 = (!draw_data) ? 0.09 : 0.07;
   
   //double offset_y1 = (text_loc == "left") ? 0.05: 0.5;
   double offset_y2 = (text_loc == "left") ? 0.05: leg_y1-0.01;
   // If you want to write text on the plot (e.g. integrated luminosity)
   //string atlas_text    = "ATLAS pre-approval";

   string sqrts_text    = "#sqrt{s}= 7 TeV";

   string lumi_text     = (lvjjHelper::doPartialUnblind) ?
     "#int Ldt = 1.0 fb^{-1}" :
     "#int Ldt = 4.701 fb^{-1}";
   //string lumi_text     = "#int Ldt = 1.0 fb^{-1}";

   if(draw_text){
     ATLASLabel(leg_x1-offset_x1,leg_y2-offset_y2);
     myText(leg_x1-offset_x1+offset_x2,leg_y2-offset_y2,1,"Internal");

     if(cur_todraw.find("elec")!=string::npos){
       myText(leg_x1-offset_x1 + 0.04,leg_y2-offset_y2-0.07,1,"X #rightarrow e#nu jj");
     }else if(cur_todraw.find("muon")!=string::npos){
       myText(leg_x1-offset_x1 + 0.04,leg_y2-offset_y2-0.07,1,"X #rightarrow #mu#nu jj");
     }else if(cur_todraw.find("comb")!=string::npos){
       myText(leg_x1-offset_x1 + 0.04,leg_y2-offset_y2-0.07,1,"X #rightarrow l#nu jj");
     }
     myText(leg_x1-offset_x1 + 0.04, leg_y2-offset_y2-0.14, 1, sqrts_text.c_str());
     myText(leg_x1-offset_x1 + 0.02, leg_y2-offset_y2-0.22,1, lumi_text.c_str());
   }


   string cur_saveas="";
   string cur_save_loc=save_loc;
    
   if(proc_type=="sys_wjets") cur_save_loc+="sys_wjets/";

   if(save_ext!=""){
     cur_saveas = cur_save_loc+"h_"+draw_dir;
     if(draw_dir!=""){
       cur_saveas+="_"+cur_hist_name;
     }else{
       cur_saveas+=cur_hist_name;
     }
     cur_saveas+=save_ext;
     canvases[i]->SaveAs(cur_saveas.c_str());
   }
  }

  if(cur_ww_var_info) delete cur_ww_var_info;

  return;
}


/* TObjArray* HistogramPainter::GetCanvases(string todraw,string gen,string draw_dir,string save_ext, string proc,bool draw_data){ */

/*   TObjArray* return_canvases = new TObjArray(); */

/*   string cur_draw_dir = draw_dir; */
/*   string cur_todraw = todraw; */
      
/*   if(todraw.find('\/')<todraw.size()){ */
/*     cur_todraw = todraw.substr(todraw.find_first_of("/")+1); */
/*   } */

/*   string cur_proc = cur_todraw.substr(0,cur_todraw.find_first_of("_")); */
/*   string cur_var = cur_todraw.substr(cur_todraw.find_first_of("_")+1); */

/*   //drop 'wjets_lowpt_(elec/muon)_' */
/*   if(cur_var.find("wjets_lowpt")!=string::npos) */
/*     cur_var = cur_var.substr(cur_var.find_first_of("wjets_lowpt")+17); */

/*   bool isLowM=false; */
/*   if(cur_var.find("lowm")!=string::npos){ */
/*     cur_var = cur_var.substr(cur_var.find_first_of("lowm")+10); */
/*     isLowM=true; */
/*   } */

/*   bool isHighM=false; */
/*   if(cur_var.find("highm")!=string::npos){ */
/*     cur_var = cur_var.substr(cur_var.find_first_of("highm")+11); */
/*     isHighM=true; */
/*   } */
/*   wwVarInfo* cur_ww_var_info = new wwVarInfo(cur_var.c_str()); */
  
/*   int tmpProcs = (cur_proc=="ee" || cur_proc=="uu" || cur_proc=="eu" || cur_proc=="lep" */
/* 		  || cur_proc=="lnuj" || cur_proc=="elec" || cur_proc=="muon" */
/* 		  || cur_proc=="ttbar" || cur_proc=="ewk" || cur_proc=="sig" */
/* 		  || cur_proc == "el" || cur_proc=="mu" */
/* 		  || cur_proc=="boost" || cur_proc=="boost1" || cur_proc=="boost2" */
/* 		  || cur_proc=="lowsb" || cur_proc=="highsb" || cur_proc=="ctrl") ? 1 : 3; */
		  

/*   const int nProcs= tmpProcs; */
    
/*   string curProcs[nProcs]; */

/*   if(nProcs==1){ */
/*     curProcs[0]=""; */
/*   }else{ */
/*     for(int j=0;j<nProcs;j++) curProcs[j]=procs[j]+"_"; */
/*   } */


/*   //all three */
/*   TH1F* data_hists[nProcs]; */
/*   TH1F* ratio_hists[nProcs]; */
/*   TObjArray* sig_hists[nProcs]; */
/*   THStack* stks[nProcs]; */
/*   TLegend* lgnds[nProcs]; */
/*   TCanvas* canvases[nProcs]; */
/*   TPad* plot_pads[nProcs]; */
/*   TPad* ratio_pads[nProcs]; */
/*   double ratio_split=0.35; */
/*   for(int i=0;i<nProcs;i++){ */

/*     string cur_hist_name = curProcs[i]+cur_todraw; */

  

/*     stks[i] = (THStack*) this->BuildStack(cur_hist_name.c_str(),cur_draw_dir.c_str()); */

  
/*     data_hists[i] = (draw_data) ? (TH1F*) this->GetDataHistogram(cur_hist_name.c_str(),cur_draw_dir.c_str()) : 0; */
/*     sig_hists[i] = (TObjArray*) this->GetHistograms(cur_hist_name,"sig",cur_draw_dir.c_str(),isLowM,isHighM);     */
/*     ratio_hists[i] =  (draw_data) ? this->MakeRatio(cur_hist_name.c_str(),ratio_pads[i],stks[i],data_hists[i]) : 0; */

   
/*     //   string leg_loc = "upper-right"; */

/*     string leg_loc = */
/*       (cur_hist_name.find("lep_phi")!=string::npos || */
/*        cur_hist_name.find("evt_n")!=string::npos ||  */
/*        cur_hist_name.find("vxp_n")!=string::npos) ? */
/*       "lower-right" : */
/*       "upper-right"; */

/*     if(cur_hist_name.find("zoom_dijet_m")!=string::npos) */
/*       leg_loc="upper-left"; */

/*     /\* if(cur_hist_name.find("zoom_dijet_m")!=string::npos){ *\/ */
/*     /\*   leg_loc="upper-left"; *\/ */
/*     /\* } *\/ */
     
/*     //string leg_loc = (cur_hist_name.find("_eta")!=string::npos || *\/ */
/*     /\* 		     //(cur_hist_name.find("_dijet_m")!=string::npos && *\/ */
/*     /\* 		     cur_hist_name.find("sig")==string::npos)) ? "lower-right" : "upper-right"; *\/ */
  
/*     lgnds[i] = (TLegend*) this->BuildLegend(stks[i],data_hists[i],sig_hists[i],leg_loc.c_str()); */
/*     //string cur_save_name = saveas+"/"+cur_hist_name; */
  
/*     string cur_tc_title = draw_dir+"_"+cur_hist_name; */
/*     string cur_tc_name = "tc_"+gen+"_"+cur_tc_title; */
    
/*     //canvases[i] = new TCanvas(cur_tc_name.c_str(),cur_tc_title.c_str(),0,0,1024,640); */
/*     canvases[i] = new TCanvas(cur_tc_name.c_str(),cur_tc_title.c_str(),0,0,1920,1200); */
/*     canvases[i]->cd(); */

/*     if(draw_data){ */
/*       ratio_pads[i] = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,ratio_split); */
/*       ratio_pads[i]->SetTopMargin(0.05); */
/*       ratio_pads[i]->SetBottomMargin(0.31); */
/*       ratio_pads[i]->Draw(); */
/*       //ratio_pads[i]->cd(); */
/*     } */
/*     plot_pads[i] = new TPad("plot_pad","plot_pad",0.01,ratio_split,0.99,0.99); */
/*     plot_pads[i]->SetBottomMargin(0); */

/*     plot_pads[i]->Draw(); */
/*     plot_pads[i]->cd(); */
/*     plot_pads[i]->Update();   */

/*     this->SetStackLimits(stks[i],data_hists[i]); */

/*     stks[i]->Draw(""); */
  

/*     if(!i){ */
/*       stks[i]->SetTitle(""); */
/*       if(draw_data) stks[i]->GetXaxis()->SetLabelSize(0); */
/*       stks[i]->GetYaxis()->SetLabelSize(0.04); */
/*       stks[i]->GetYaxis()->SetTitle("Events"); */
/*       stks[i]->GetYaxis()->SetTitleOffset(0.7); */
/*     } */

   
/*     ////////////////////////////////////////////////// */
/*     // Get background Error Hist */
/*     // Could move to MakeRatio bc it has loops over  */
/*     // stack hists and bins already, but this works for now */
/*     // Problem: GetHistogram only works after stks[i]->Draw */
/*     ////////////////////////////////////////////////// */
    
/*     TH1F* stck_hist = (TH1F*) stks[i]->GetHistogram()->Clone(); */
/*     stck_hist->SetLineWidth(0); */
/*     stck_hist->SetMarkerSize(0); */
/*     stck_hist->SetLineColor(kWhite); */

/*     //Fill stck_hist */
/*     TObjArray* stacks = (TObjArray*) stks[i]->GetHists()->Clone(); */
/*     for(int s=0;s<stacks->GetEntries();s++) */
/*       stck_hist->Add((TH1F*) stacks->At(s)); */

/*     // Loop over Bins, set errors */
/*     int bin_n = stck_hist->GetXaxis()->GetNbins(); */
/*     for(int b=1;b<bin_n+1;b++){ */
/*       double cur_err = stck_hist->GetBinError(b); */
/*       double cur_val = stck_hist->GetBinContent(b); */

/*       // Luminosity err */
/*       double lumi_err = cur_val*lumi_uncert; */

/*       cur_err = sqrt(pow(lumi_err,2.)+pow(cur_err,2.)); */
/*       stck_hist->SetBinError(b,cur_err); */

/*       /\* double rat_err = ratio_hists[i]->GetBinError(b); *\/ */
/*       /\* double rat_val = ratio_hists[i]->GetBinContent(b); *\/ */
/*       /\* double rat_rel_err = rat_err/rat_val; *\/ */
/*       /\* //double cur_lumi_rel_err = lumi_err/cur_val; *\/ */
     
/*       /\* double rat_err_with_lumi = sqrt(pow(rat_rel_err,2.)+pow(lumi_uncert,2.)); *\/ */
/*       /\* ratio_hists[i]->SetBinError(b,rat_err_with_lumi*rat_val); *\/ */
     
/*     } */
    
/*     stck_hist->SetFillColor(kBlack); */
/*     stck_hist->SetFillStyle(3244); */
/*     stck_hist->Draw("E2 SAME"); */

/*     lgnds[i]->Draw(); */
/*     if(data_hists[i]) data_hists[i]->Draw("PE sames"); */

/*     for(int s=0;s<sig_n;s++) */
/*       sig_hists[i]->At(s)->Draw("HIST sames"); */

/*     if(cur_ww_var_info->DoLogy()) plot_pads[i]->SetLogy(); */
 

/*     canvases[i]->Update(); */

/*     ////////////////////////////////////////////////// */
/*     // Make Ratio */
/*     ///////////////////////////////////////////////////  */
/*     if(draw_data){ */
/*       ratio_pads[i]->cd(); */
/*       ratio_pads[i]->SetGrid(); */
  
/*       TAxis* ratio_xaxis= ratio_hists[i]->GetXaxis(); */
/*       TAxis* ratio_yaxis= ratio_hists[i]->GetYaxis(); */
/*       ratio_hists[i]->SetMarkerStyle(20); */
/*       ratio_hists[i]->SetMarkerSize(2); */
/*       //ratio_hists[i]->GetYaxis()->SetTicks(); */
/*       if(!i){ */
/* 	ratio_xaxis->SetLabelSize(0.08); */
/* 	ratio_yaxis->SetLabelSize(0.08); */

/* 	ratio_xaxis->SetTitle(cur_ww_var_info->GetXLabel().c_str()); */
/* 	ratio_xaxis->SetTitleSize(0.16); */
/* 	ratio_xaxis->SetTitleOffset(0.7); */
/* 	ratio_yaxis->SetNdivisions(4,4,4); */
/* 	ratio_yaxis->SetTitle("(data-MC)/MC"); */
/* 	ratio_yaxis->SetTitleSize(0.07); */
/* 	ratio_yaxis->SetTitleOffset(0.36); */
/*       } */

/*       ratio_yaxis->SetRangeUser(-0.5,0.5); */
/*       ratio_hists[i]->Draw("PE"); */
/*       canvases[i]->Update(); */
/*     } */
/*     // CAll this */
/*     plot_pads[i]->cd(); */
/*     canvases[i]->RedrawAxis(); */
/*     double leg_x1 = lgnds[i]->GetX1NDC(); */
/*     double leg_y1 = lgnds[i]->GetY1NDC(); */
/*     double offset_x1 = -0.02; */
/*     double offset_y1 = 0.08; */
/*     // If you want to write text on the plot (e.g. integrated luminosity) */
/*     //string atlas_text    = "ATLAS pre-approval"; */

/*     string sqrts_text    = "#sqrt{s}= 7 TeV"; */
/*     string lumi_text     = "#int Ldt = 4.701 fb^{-1}"; */
/*     myTextSize(leg_x1-offset_x1, leg_y1-offset_y1, 1,0.04, sqrts_text.c_str()); */
/*     myTextSize(leg_x1-offset_x1 + 0.1, leg_y1-offset_y1,1,0.04,  lumi_text.c_str()); */
/*     //myText(leg_x1-offset_x1, leg_y1-offset_y1, 1, analysis_text.c_str()); */

  
/*    return_canvases->Add((TCanvas*) canvases[i]); */
  
   
/*   } */

/*   if(cur_ww_var_info) delete cur_ww_var_info; */

/*   return return_canvases; */
/* } */



void HistogramPainter::PrintInfo(){
  //Must print sig, background, and data
  cout<<"In HistogramPainter::PrintInfo()"<<endl;
  
  for(int s=0;s<sig_n;s++){

    TFile* cur_file = (TFile*) sig_files->At(0);
    TDirectory* evt_dir = cur_file->GetDirectory("evt_sel");
    if(!evt_dir) {
      cout<<"No evt_sel in "<<cur_file->GetName()<<endl;
      return;
    }
    evt_dir->ls();
    /* double evt_n = ((TH1F*) evt_dir->Get("h_evt_n"))->Integral(); */
    /* double sow_n = ((TH1F*) evt_dir->Get("h_sow_n"))->Integral(); */

    /* cout<<cur_file->GetName()<<endl; */
    /* cout<<"evt_n: "<<evt_n<<endl; */
    /* cout<<"sow_n: "<<sow_n<<endl;     */
    
  }

}
double HistogramPainter::pValueToSignificance(double p,     // p-value
					      bool excess)  // false if deficit
{
  if (p<0 || p>1) {
    cerr << "ERROR: p-value must belong to [0,1] but input value is " << p << endl;
    return 0;
  }

  if (excess) 
    return ROOT::Math::normal_quantile(1-p,1);
  else
    return ROOT::Math::normal_quantile(p,1);

}

double HistogramPainter::pValuePoissonError(unsigned nObs, // observed counts
			  double E,      // expected counts
			  double V)      // variance of expectation
{
  if (E<=0 || V<=0) {
    cerr << "ERROR in pValuePoissonError(): expectation and variance must be positive" << endl;
    cerr << "Nobs = " << nObs << endl;
    cerr << "Exp  = " << E << endl;
    cerr << "Var  = " << V << endl;
    return 0;
  }
  double B = E/V;
  double A = E*B;
  
  // relative syst = sqrt(V)/E = 1/sqrt(A)
  // relative stat = 1/sqrt(nObs)
  // if syst < 0.1*stat there is no need for syst:
  // save a bit of CPU time :-)
  if (A>100*nObs) return pValuePoisson(nObs,E);
  
  // explicit treatment for systematics:
  unsigned stop=nObs;
  if (nObs>E) --stop;
  
  /// NB: must work in log-scale otherwise troubles!
  double logProb = A*log(B/(1+B));
  double sum=exp(logProb); // P(n=0)
  for (unsigned u=1; u<stop; ++u) {
    logProb += log((A+u-1)/(u*(1+B)));
    sum += exp(logProb);
  }
  if (nObs>E)  // excess
    return 1-sum;
  else  // deficit
    return sum;
}
double HistogramPainter::pValuePoisson(unsigned nObs,    // observed counts
				       double nExp)      // Poisson parameter
{
  if (nObs>nExp) // excess
    return 1-ROOT::Math::inc_gamma_c(nObs,nExp);
  else // deficit
    return ROOT::Math::inc_gamma_c(nObs+1,nExp);
  /*
    double fact=1;
    double sum=1;
    double pwr=1;
    unsigned stop=nObs;
    if (nObs<nExp) ++stop;
    for (unsigned u=1; u<stop; ++u) {
    fact *= u;
    pwr *= nExp;
    sum += pwr/fact;
    }
    if (nObs<nExp) return sum*exp(-nExp);
    return 1 - sum*exp(-nExp);
  */
}

TH1F* HistogramPainter::MakeSignificanceRatio(string ratio_name,TPad* pad,THStack* stk, TH1F* data,bool isSidebandScaled){

  //////////////////////////////////////////////////
  // code below controls adding vjets uncertainty
  // to control region plots
  ////////////////////////////////////////////////// 
  bool doVJets = (isSidebandScaled &&
		  (ratio_name.find("ctrl_highm")!=string::npos || //need to add check for if already sideband scaled
		  ratio_name.find("sig_highm")!=string::npos ||
		  ratio_name.find("lowsb_highm")!=string::npos ||
		   ratio_name.find("highsb_highm")!=string::npos));

  //if(doVJets) cout<<"Adding VJets uncertainty to histogram"<<endl;

  //////////////////////////////////////////////////
  // if lep_nu_dijet_m, scale by M(lvjj) 
  // if dijet_pt or lep_met_pt, scale by uncertainty from 0.5 M(lvjj)
  // if lep_pt, scale by 1/3 M(lvjj)
  // otherwise scale by 10%
  ////////////////////////////////////////////////// 

  float vjets_uncertainty = 0.0;

  TFile* vjets_sf;
  TFile* vjets_fn;
  TF1* fn_lowsb_sf;
  TF1* fn_highsb_sf;
  TH1F* h_vjets_sf;
  TAxis* h_vjets_sf_x;
  float vjets_factor = 0.0;
  bool getBinValue=false;
  if(doVJets){

    /* vjets_sf = (TFile*) TFile::Open("../wjets/files/wjets_sf.root","READ"); */
    /* h_vjets_sf = (TH1F*) vjets_sf->Get("h_avg_sf"); */
    /* h_vjets_sf_x = (TAxis) h_vjets_sf->GetXaxis(); */
    //h_vjets_sf->SetDirectory(0);
    //vjets_sf->Close();

    vjets_fn = (TFile*) TFile::Open("../wjets/files/vjets_systematics_functions.root","READ");
    fn_lowsb_sf = (TF1*) vjets_fn->Get("fn_lowsb");
    fn_highsb_sf = (TF1*) vjets_fn->Get("fn_highsb");

    if(ratio_name.find("dijet_m_dijet_pt")!=string::npos ||
       ratio_name.find("dijet_m_lep_met_pt")!=string::npos){
      vjets_factor=0.5;
      getBinValue=true;
    }else if(ratio_name.find("dijet_m_lep_pt")!=string::npos ||
	     ratio_name.find("dijet_m_lead_jet_pt")!=string::npos){
        vjets_factor=1./3.;
	getBinValue=true;
    }else if(ratio_name.find("dijet_m_lep_nu_dijet_m")!=string::npos){
      vjets_factor=1.0;
      getBinValue=true;
    }else{
      vjets_factor=0.1;
    }
  }
  //cout<<"!! vjets_factor: "<<vjets_factor<<endl;
  
  string cur_ratio_name = "h_ratio_"+ratio_name;
  THStack* tmp_stk = (THStack*) stk->Clone();
  TObjArray* bkgd_hists = (TObjArray*) tmp_stk->GetHists();

  int n_bins = ((TAxis*) data->GetXaxis())->GetNbins();
  double x_min = ((TAxis*) data->GetXaxis())->GetXmin();
  double x_max = ((TAxis*) data->GetXaxis())->GetXmax();
  //pad->cd();
  TH1F* h_ratio = new TH1F(cur_ratio_name.c_str(),"",n_bins,x_min,x_max);

  TH1F* tmp_bkgd;
  for(int j=0;j<bkgd_hists->GetEntries();j++){
    if(j==0){
      tmp_bkgd=(TH1F*) bkgd_hists->At(j);
    }else{
      tmp_bkgd->Add((TH1F*) bkgd_hists->At(j));
    }
  }

    
  int Nbins = h_ratio->GetNbinsX();
  for (int i=1; i<= Nbins; ++i) { // SKIP UNDER- AND OVER-FLOWS

    if (data->GetBinContent(i)<=0) continue;

    double sf_uncert= (doVJets) ? 0.1 : 0.0;

    if(doVJets && getBinValue){
      
      double bin_value = data->GetBinCenter(i);
      //double sf_value = h_vjets_sf->GetBinContent(h_vjets_sf_x->FindBin(bin_value));
      double sf_value = 1.;
      double lowsb_value = fn_lowsb_sf->Eval(bin_value/vjets_factor);
      double highsb_value = fn_highsb_sf->Eval(bin_value/vjets_factor);
      double avg_value = (lowsb_value+highsb_value)/2.;
    
      sf_uncert = fabs(lowsb_value-highsb_value)/avg_value;
    
    }
    
    unsigned nObs = (int) data->GetBinContent(i);
    float nExp = tmp_bkgd->GetBinContent(i);
    if ( nExp < 0.1 ) { h_ratio->SetBinContent(i, 0.0); continue; }
    float vrnc = tmp_bkgd->GetBinError(i);
  
    double fracsys_lumi = 0.039;
    //  double fracsys_lumi = 0.0;
    double var_sys_lumi = nExp * fracsys_lumi;

    //double fracsys = 0.06;
    //double fracsys = 0.0;

    // negelctUncertainty = true -> don't propigate vjets uncertainty
    // to ratio calculation

    double fracsys = (neglectUncertainty) ? 0.06 : sf_uncert;
    //if(ratio_name.find("dijet_m_zoom_dijet_m")!=string::npos && neglectUncertainty) fracsys=0.2;
    
    //double fracsys = (neglectUncertainty) ? 0.0 : sf_uncert;

    
    //cout<<ratio_name<<", "<<bin_value<<", "<<fracsys<<endl;
    double var_sys = nExp * fracsys;
      
    //cout << vrnc/nExp << "\t" << var_sys/nExp << "\t" << nExp << endl;

    vrnc *= vrnc; // variance
    var_sys *= var_sys;
    var_sys_lumi *= var_sys_lumi;

    float sig_sys = 0;
    float sig = 0;
    float pValue_sys = 0.0;
    float pValue = 0.0;

    
    if (vrnc + var_sys + var_sys_lumi > 0 ) {
      // account for systematic uncertainty
      /* cout<<"!! nExp: "<<nExp<<" vrnc: "<<vrnc */
      /* 	  <<", var_sys: "<<var_sys<<", var_sys_lumi: "<<var_sys_lumi<<endl; */

      pValue_sys = pValuePoissonError(nObs, nExp, vrnc + var_sys + var_sys_lumi);

      if ( pValue_sys <= 0.0 ) { sig_sys = 0.0; }
      else { if (pValue_sys<0.5) sig_sys = pValueToSignificance(pValue_sys, (nObs>nExp)); }
      
      pValue = pValuePoissonError(nObs, nExp, vrnc+var_sys_lumi);
      if ( pValue <= 0.0 ) { sig = 0.0; }
      else { if (pValue<0.5) sig = pValueToSignificance(pValue, (nObs>nExp));
      }
    }
    else {
      // assume perfect knowledge of Poisson parameter
      pValue_sys = pValuePoisson(nObs,nExp);
      if ( pValue_sys <= 0.0 ) { sig_sys = 0.0; }
      else { if (pValue_sys<0.5) sig_sys = pValueToSignificance(pValue_sys, (nObs>nExp)); }
      
      pValue = pValuePoisson(nObs,nExp);
      if ( pValue <= 0.0 ) { sig = 0.0; }
      else { if (pValue<0.5)  sig = pValueToSignificance(pValue, (nObs>nExp)); 

      }
    }

    //h_ratio->SetBinContent(i, sig);
    //cout<<"--> "<<sig_sys<<endl;
    h_ratio->SetBinContent(i, sig_sys);
    //h_ratio_sys->SetBinContent(i, sig_sys);
  }

  if(tmp_bkgd) delete tmp_bkgd;
  return h_ratio;
}
   
TH1F* HistogramPainter::MakeRatio(string ratio_name,TPad* pad,THStack* stk, TH1F* data){

  //Returns histogram of
  
  string cur_ratio_name = "h_ratio_"+ratio_name;
  THStack* tmp_stk = (THStack*) stk->Clone();
  TObjArray* bkgd_hists = (TObjArray*) tmp_stk->GetHists();
  int n_bins = ((TAxis*) data->GetXaxis())->GetNbins();
  double x_min = ((TAxis*) data->GetXaxis())->GetXmin();
  double x_max = ((TAxis*) data->GetXaxis())->GetXmax();
  //pad->cd();
  TH1F* h_ratio = new TH1F(cur_ratio_name.c_str(),"",n_bins,x_min,x_max);

  TH1F* tmp_bkgd;
  for(int j=0;j<bkgd_hists->GetEntries();j++){
    if(!j){
      tmp_bkgd=(TH1F*) bkgd_hists->At(j);
    }else{
      tmp_bkgd->Add((TH1F*) bkgd_hists->At(j));
    }
  }

  
  //TH1F* tmp_ratio = (TH1F*) data->Clone();
  h_ratio->Add(data);
  //////////////////////////////////////////////////
  // Error propigaion
  // Want Err{(data-bkgd)/bkgd}
  // - Err{bkgd} = Sqrt(Sum(Err{bkgd_i}^2)) = cur_bkgd_err
  // - RelErr{bkgd} = Err{bkgd}/bkgd = rel_bkgd_err;
  // - Err{data-bkgd} = Sqrt((Err{data}^2+Err{bkgd}^2)) = comb_bkgd_data_err
  // - RelErr{data-bkgd} = Err{data-bkgd}/(data+bkgd) = rel_bkgd_data_err;
    // - RelErr{(data-bkgd)/bkgd} = Sqrt(RelErr{data-bkgd}^2+RelErr{bkgd}^2) = rel_ratio_err
    //
    // - Err{(data-bkgd)/bkgd} = RelErr{(data-bkgd)/bkgd}*((data-bkgd)/bkgd) = cur_ratio_err
    //////////////////////////////////////////////////
  
  h_ratio->Add(tmp_bkgd,-1);
  h_ratio->Divide(h_ratio,tmp_bkgd,1,1,"B");
    
  if(tmp_bkgd) delete tmp_bkgd;  
  return h_ratio;

}


#endif
