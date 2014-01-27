#include "../include/lnuj_skim_list.h"
//#include "../include/kkg_skim_list.h"
#include "../src/defs.h"
#include <TDirectory.h>


void runPS(){

  //string skim_dir="skims_etcone_lt_0p14/";
  string skim_dir="skims/";
  
  cout<<"RUN rmGWWPlots.sh FIRST!"<<endl;

  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In runGWW.C"<<endl;
  cout<<"Running over "<<nSkims<<" skims"<<endl;
  cout<<endl;

  TChain *skimChain;
  string file;
  for(int s=0;s<nSkims;s++){

    skimChain=new TChain("analysisTree");
    //tmp

    string load_skim = skim_list[s];

    string cur_skim = "../files/"+skim_dir+load_skim;
    cur_skim+=".skim.root";
    cout<<"skimChain->Add("<<cur_skim.c_str()<<")"<<endl;;
    skimChain->Add(cur_skim.c_str());

    file=skim_list[s];
    skimChain->Process("../src/skimmedGWW.C+",file.c_str());


    TDirectory* dirs[nCtrls];

    string plot_file = "../plots/gww_plots/"+load_skim;
    plot_file+=".plot.root";

    TFile* plotFile = (TFile*) TFile::Open(plot_file.c_str());


    if(!plotFile) continue;//No events in file
    
    for(int i=0;i<nCtrls;i++){

      bool has_dir = plotFile->cd(ctrls[i].c_str());
      if(!has_dir){
    	cout<<"No directory "<<ctrls[i]<<endl;
    	continue;
      }
      dirs[i] = gDirectory;
      dirs[i]->ReadAll();
    }

    TFile* newFile = (TFile*) TFile::Open(plot_file.c_str(),"recreate");    
    for(int j=0;j<nCtrls;j++){

      newFile->mkdir(ctrls[j].c_str());
      newFile->cd(ctrls[j].c_str());
      dirs[j]->GetList()->Write();


    }
      newFile->Close();
      plotFile->Close();
      
    

    // TDirectory* evt_dir=0;
    // TDirectory* ps_dir=0;
    // TDirectory* sig_lowm_dir=0;
    // TDirectory* sig_higm_dir=0;
    // TDirectory* ewk_dir=0;
    // //TDirectory* ttbar_dir=0;
    // TDirectory* boost1_dir=0;    
    
    // //TFile* skimFile = (TFile*) TFile::Open(cur_skim.c_str());


    // string plot_file = "../plots/gww_plots/"+skim_list[s];
    // plot_file+=".plot.root";

    // TFile* plotFile = (TFile*) TFile::Open(plot_file.c_str());

    // if(!plotFile) continue;//No events in file

    // bool has_dir_ps=plotFile->cd("ps");
    // if(has_dir_ps){
    //   ps_dir = gDirectory;
    //   ps_dir->ReadAll();
    // }else{
    //   cout<<"No directory ps"<<endl;
    // }

    // bool has_dir_sig_lowm=plotFile->cd("sig_lowm");
    // if(has_dir_sig_lowm){
    //   sig_lowm_dir = gDirectory;
    //   sig_lowm_dir->ReadAll();
    // }else{
    //   cout<<"No directory sig_lowm"<<endl;
    // }
  
    // bool has_dir_sig_highm=plotFile->cd("sig_highm");
    // if(has_dir_sig_highm){
    //   sig_highm_dir = gDirectory;
    //   sig_highm_dir->ReadAll();
    // }else{
    //   cout<<"No directory sig_highm"<<endl;
    // }

    // bool has_dir_ewk=plotFile->cd("ewk");
    // if(has_dir_ewk) {
    //   ewk_dir = gDirectory;
    //   ewk_dir->ReadAll();
    // }else{
    //   cout<<"No directory all"<<endl;
    // }

    // bool has_dir_boost1=plotFile->cd("boost1");
    // if(has_dir_boost1) {
    //   boost1_dir = gDirectory;
    //   boost1_dir->ReadAll();
    // }else{
    //   cout<<"No directory boost1"<<endl;
    // }

    // //plotFile->Close();

    // TFile* newFile = (TFile*) TFile::Open(plot_file.c_str(),"recreate");


    // if(has_dir_ps){
    //   newFile->mkdir("ps");
    //   newFile->cd("ps");
    //   ps_dir->GetList()->Write();
    // }

    // if(has_dir_sig_lowm){
    //   newFile->mkdir("sig_lowm");
    //   newFile->cd("sig_lowm");
    //   sig_lowm_dir->GetList()->Write();
    // }

    // if(has_dir_sig_highm){
    // newFile->mkdir("sig_highm");
    // newFile->cd("sig_highm");
    // sig_highm_dir->GetList()->Write();
    // }
    // if(has_dir_ewk){
    // newFile->mkdir("ewk");
    // newFile->cd("ewk");
    // ewk_dir->GetList()->Write();
    // }

    // // newFile->mkdir("ttbar");
    // // newFile->cd("ttbar");
    // // ttbar_dir->GetList()->Write();
    // if(has_dir_boost1){
    //   newFile->mkdir("boost1");
    //   newFile->cd("boost1");
    //   boost1_dir->GetList()->Write();
    // }

    
    // //skimFile->Close();
    // plotFile->Close();
    // newFile->Close();
    
  }
  
  delete skimChain;
  cout<<"Histogram files written to ../plots"<<endl;
  cout<<"Don't forget to merge histograms!"<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  gROOT->ProcessLine(".q");
  return;
}
