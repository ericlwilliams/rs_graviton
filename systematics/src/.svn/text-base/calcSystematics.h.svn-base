#ifndef calcSystematics_h
#define calcSystematics_h

#include <TROOT.h>
#include <TFile.h>
#include <TObject.h>
#include <TCanvas.h>
#include <TObjArray.h>
#include <TH1F.h>
#include <vector>

string file_loc = "../../plots/systematics_plots/merged/";

const int nMods=3;
string mods[nMods]={"nom","up","down"};
int nNom=0;
int nUp=1;
int nDown=2;

class calcSystematics : public TObject {

  
  TObjArray* systematics_files;
  vector<string>* systematics_names;
  int nSysFiles;

 public:
  calcSystematics();
  virtual ~calcSystematics(){};
  virtual bool LoadSystematicsFiles(TObjArray* sys_files,vector<string>* sys_names);
  virtual double GetUncertainty(string sample,string sys,string proc,string region,string comb);
  virtual double GetSmearUncertainty(string smear,string sample,string proc,string region);
  virtual TFile* GetSystematicsFile(string name);
  virtual void MakePlot(string sample_name,string systematic_name,string var_name,string proc_name);
  virtual void MakeSmearPlot(string smear,string sample_name,string var_name,string proc_name);
  virtual void PlotBackgrounds(string cur_sys,string cur_proc,string var_name,int n_bkgds,string bkgds[]);
  virtual void PlotSmearBackgrounds(string smear,string cur_proc,string var_name,int n_bkgds,string bkgds[]);
  ClassDef(calcSystematics,0);


};

#endif

