#include "../../include/systematics_defs.h"
#include <iomanip>

void runSystematics(string systematic="jes"){

  cout.setf(ios::fixed,ios::floatfield); 
  cout.precision(5);

  gROOT->ProcessLine(".L ../src/calcSystematics.C+");

  calcSystematics* sysCalc = new calcSystematics();

  float uncertainties[nSamples][nProcs][nRegions][nCombs]={0};

  string cur_sys=systematic;
  
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

  string out_file_name = "../logs/"+cur_sys+".csv";
  
  std::ofstream out_file(out_file_name.c_str());
  out_file<<setprecision(2)<<fixed;
  //out_file<<cur_sys<<endl;
  // out_file<<"sample"
  // 	 <<","
  // 	 <<"e$\\nu$jj"
  // 	 <<","
  // 	 <<"mu$\\nu$jj"
  // 	 <<endl;
  
  cout<<"== "<<cur_sys<<" =="<<endl;

  bool firstSignal=true;
  for(int s=0;s<nSamples;s++){
    string cur_sample = samples[s];

    // if(cur_sample.find("gww")!=string::npos && firstSignal){//first signal mc

    //   out_file<<"Backgrounds,=AVERAGE(B3:B6),=AVERAGE(C3:C6),=AVERAGE(D3:D6),=AVERAGE(E3:E6)"<<endl;
    //   firstSignal=false;
    // }

    if(cur_sample.find("_")!=string::npos)
      cur_sample.replace(cur_sample.find("_"),1,"\\_");

    
    out_file<<cur_sample<<",";

    for(int p=0;p<nProcs;p++){
      string cur_proc = procs[p];
      cout<<"\t"<<cur_proc;
      for(int r=0;r<nRegions;r++){
	if(uncertainties[s][p][r][nCombAvg]<0){
	  out_file<<"-";
	}else{
	  out_file<<uncertainties[s][p][r][nCombAvg];
	}
	if(p!=(nProcs-1))// not last
	  out_file<<",";

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

  cout<<"See systematics/results/"<<cur_sys<<"/"<<cur_sys<<".tex for tables"<<endl;
  gROOT->ProcessLine(".q");
  return;
}

