#include <vector>
#include <TH1.h>
#include <string>
#include <map>
#include "../include/wwXSec.h"

using std;

const double intLumi = 1.14824; //pb^-1

TFile* merge;

void hmerge(string proc="zuu"){

  string cur_merge=proc+".root";
  merge = TFile::Open(cur_merge.c_str(),"RECREATE");
    

  if(proc=="none"){
    cout<<"No process specified to merge"<<endl;
    return;
  }
  
  const int nmult=5;//zuu

  TFile* files[nmult+1];
  wwXSec* xsecs[nmult+1];
  
  string cur_file;
  string cur_proc;
  char cur_nmult[10];

  
  //loop/load multiplicity files
  for(int i=0;i<nmult+1;i++){

    sprintf(cur_nmult,"Np%d",i);
    cur_file=proc+cur_nmult;
    cur_proc=cur_file;
    cur_file+=".root";

    
    cout<<"Loading "<<cur_file<<endl;

    //open current file and load cross section info
    TFile* file = TFile::Open(cur_file.c_str());
    merge->cd();
    wwXSec* xsec = new wwXSec(cur_proc.c_str());

    
    int nkeys = file->GetNkeys();
    TList* keys = file->GetListOfKeys();

    //Loop over top directory
    for(int k=0;k<nkeys;k++){

      string cur_key = ((TObject*) keys->At(k))->GetName();

      //only merge histograms in top directory
      //no scaling!
      if(cur_key.find("h_")==0){

	TH1F* cur_hist = (TH1F*) keys->At(k);

	//if first 
	if(!merge->FindKey(cur_key.c_str())){

	  cout<<"Setting "<<cur_key<<" in merge.root, nevts:"<</*((TH1F*) cur_hist)->GetEntries()<<*/endl;
	  ((TH1F*) cur_hist)->Write();

	}else{

	  TH1F* merge_hist = (TH1F*) merge->Get(cur_key.c_str());
	  ((TH1F*) merge_hist)->Add((TH1F*) cur_hist);

	  //cout<<"Adding "<<cur_key<<" in merge.root, nevts: "<<merge_hist->Add(cur_hist)<<endl;

	  ((TH1F*) merge_hist)->Write("",TObject::kOverwrite);

	}
      }
      
    }
      
    files[i] = file;
    xsecs[i] = xsec;
  }


  
  int nchan=4;
  string channels[] = {"ee","uu","eu","comb"};

  
  
  
  gROOT->ProcessLine(".q");
  return;
}
