#include "../../include/systematics_defs.h"
void runMakeSignalParameterFitsWprime(string sys="jes_nom"){

  string cur_sys = sys;

  gROOT->ProcessLine(".L ../src/signalShapesWprime.C+");
  signalShapesWprime* sigShape = new signalShapesWprime();


  string cur_channel;
  
    if(cur_sys=="all"){

      for(int p=0;p<nProcs;p++){

	cur_channel = (procs[p]=="el") ? "evjj" : "uvjj";

	for(int i=0;i<nSys;i++){
	  cur_sys = systs[i];
	  bool do_nom = (cur_sys.find("jes")!=string::npos);
	  
	  for(int j=0;j<nMods;j++){
	    if(!do_nom && j==0) continue;
	    string run_cur_sys = cur_sys+"_"+modulations[j];
	    cout<<"sigShape::makeSignalParameterFits: "<<cur_channel<<", "<<run_cur_sys<<endl;
	    sigShape->makeSignalParameterFits(cur_channel.c_str(),run_cur_sys.c_str());
	    cout<<"sigShape::makeClosurePlots: "<<cur_channel<<", "<<run_cur_sys<<endl;
	    sigShape->makeClosurePlots(cur_channel.c_str(),run_cur_sys.c_str());
	  }
	}
      }
    }else{

      for(int p=0;p<nProcs;p++){

	cur_channel = (procs[p]=="el") ? "evjj" : "uvjj";

	cout<<"sigShape::makeSignalParameterFits: "<<cur_channel<<", "<<cur_sys<<endl;
	sigShape->makeSignalParameterFits(cur_channel.c_str(),cur_sys.c_str());
	cout<<"sigShape::makeClosurePlots: "<<cur_channel<<", "<<cur_sys<<endl;
	sigShape->makeClosurePlots(cur_channel.c_str(),cur_sys.c_str());

      }
    }

    gROOT->ProcessLine(".q");
    return;
}
