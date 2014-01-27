#include <TObjArray.h>

void runIDUPSystematics(){

  cout.setf(ios::fixed,ios::floatfield); 
  cout.precision(5);
  
  gROOT->ProcessLine(".L calcSystematics.C+");

  calcSystematics* sysCalc = new calcSystematics();;

  

  const int nSamples =11;
  string samples[nSamples] = {"mcatnlo.top","alpgen.wjets","alpgen.zjets","herwig.vv","qcd",
			      "gww.lvjj.m200.kmpl0_1","gww.lvjj.m350.kmpl0_1","gww.lvjj.m500.kmpl0_1",
			      "gww.lvjj.m750.kmpl0_1","gww.lvjj.m1000.kmpl0_1","gww.lvjj.m1250.kmpl0_1"};


  
  const int nProcs=2;
  string procs[nProcs] = {"el","mu"};

  const int nRegions =2;
  string regions[nRegions] = {"lowm","highm"};

  float uncertainties[nSamples][nProcs][nRegions]={0};

  string cur_smear = "idup";

  for(int s=0;s<nSamples;s++){
    string cur_sample = samples[s];
    for(int p=0;p<nProcs;p++){
      string cur_proc = procs[p];
      for(int r=0;r<nRegions;r++){
	string cur_region = regions[r];

	  uncertainties[s][p][r]=
	    sysCalc->GetSmearUncertainty(cur_smear.c_str(),cur_sample.c_str(),cur_proc.c_str(),cur_region.c_str());

      }
    }
  }

  
  cout<<"== IDUP =="<<endl;
  //cout<<"sample\tfluc\tsig"<<endl;

  for(int s=0;s<nSamples;s++){
    string cur_sample = samples[s];
    cout<<cur_sample<<endl;
    for(int p=0;p<nProcs;p++){
      string cur_proc = procs[p];
      cout<<"\t"<<cur_proc;
      for(int r=0;r<nRegions;r++){
	if(s>4 && s<8 && r) continue;//don't print highm for lowm signals
	if(s>7 && !r) continue;//don't print highm for lowm signals	
	string cur_region = regions[r];
	string cur_tab = (r) ? "\t\t" : "\t";
	cout<<cur_tab+cur_region;
	cout<<"\t";
	cout<<uncertainties[s][p][r];
	cout<<"\t";
	cout<<endl;
      }
      cout<<endl;
    }
  }
  cout<<endl;

}
  
