#include <TObjArray.h>

void runJESSystematics(){

  cout.setf(ios::fixed,ios::floatfield); 
  cout.precision(5);
  
  gROOT->ProcessLine(".L calcSystematics.C+");

  calcSystematics* sysCalc = new calcSystematics();;

  
  // TObjArray* background_files = sysCalc.LoadBackgroundFiles();
  // TObjArray* signal_files = sysCalc.LoadSignalFiles();
  // cout<<"bkgds: "<<background_files->GetEntries()<<", sigs:"<<signal_files->GetEntries()<<endl;

  const int nSamples =11;
  string samples[nSamples] = {"mcatnlo.top","alpgen.wjets","alpgen.zjets","herwig.vv","qcd",
			      "gww.lvjj.m200.kmpl0_1","gww.lvjj.m350.kmpl0_1","gww.lvjj.m500.kmpl0_1",
			      "gww.lvjj.m750.kmpl0_1","gww.lvjj.m1000.kmpl0_1","gww.lvjj.m1250.kmpl0_1"};

  const int nProcs=2;
  string procs[nProcs] = {"el","mu"};

  const int nRegions =2;
  string regions[nRegions] = {"lowm","highm"};

  const int nCombs=3;
  string combs[nCombs] = {"up","down","avg"};
  int nUp=0;
  int nDown=1;
  int nAvg=1;


  float uncertainties[nSamples][nProcs][nRegions][nCombs]={0};

  string cur_sys="jes";
  
  for(int s=0;s<nSamples;s++){
    string cur_sample = samples[s];
    for(int p=0;p<nProcs;p++){
      string cur_proc = procs[p];
      for(int r=0;r<nRegions;r++){
	string cur_region = regions[r];
	for(int c=0;c<nCombs;c++){
	  string cur_comb=combs[c];

	  uncertainties[s][p][r][c]=
	    sysCalc->GetUncertainty(cur_sample.c_str(),cur_sys.c_str(),cur_proc.c_str(),cur_region.c_str(),cur_comb.c_str());

	}
      }
    }
  }
  
  std::ofstream out_file("./logs/jes.csv");
  out_file<<"JES"<<endl;
  out_file<<"sample"
	 <<","
	 <<"el_lowm"
	 <<","
	 <<"el_highm"
	 <<","
	 <<"mu_lowm"
	 <<","
	 <<"mu_highm"
	 <<endl;
  
  cout<<"== JES =="<<endl;
  //cout<<"sample\tfluc\tsig"<<endl;

  for(int s=0;s<nSamples;s++){
    string cur_sample = samples[s];
    cout<<cur_sample<<endl;
    out_file<<cur_sample<<",";
    
    for(int p=0;p<nProcs;p++){
      string cur_proc = procs[p];
      cout<<"\t"<<cur_proc;
      for(int r=0;r<nRegions;r++){

	out_file<<uncertainties[s][p][r][nAvg]<<",";
	
	if(s>4 && s<8 && r) continue;//don't print highm for lowm signals
	if(s>7 && !r) continue;//don't print highm for lowm signals	
	string cur_region = regions[r];
	string cur_tab = (r) ? "\t\t" : "\t";
	cout<<cur_tab+cur_region;
	for(int c=0;c<nCombs;c++){
	  string cur_comb=combs[c];
	  cout<<"\t"<<cur_comb<<": ";
	  cout<<uncertainties[s][p][r][c];
	  cout<<"\t";
	}
	cout<<endl;
      }
      cout<<endl;
    }

    out_file<<endl;
  }
  cout<<endl;
  

  return;
}

