#include <string>
#include <TString.h>
#include <TFile.h>
#include <TObjArray.h>
#include <TH1.h>
#include "wwXSec.h"

class wwFileInfo : public TObject {

  int nFiles;
  bool merge_loaded;
  string analy;
  TString procs;
  TString proc_type;//e.g. lnuj,...
  TObjArray *fileList;
  TObjArray *plotList;
  TObjArray *xsecs;
  TFile *merged;
  int color;
  string fname;
  string process;
  string proc; 
  string color_scheme;
  bool is_sig;
  double line_width;
  int fill_style;
  int line_style;
  
  double tot_evt_n;
  double tot_ewk_evt_n;
  double tot_jetm_evt_n;
  double tot_ttbar_evt_n;
  double tot_sow_n;
  double tot_one_jet_n;

  double scaled_evt_n;
  double scaled_ewk_evt_n;
  double scaled_ttbar_evt_n;
  double scaled_jetm_evt_n;
  double scaled_sow_n;
  double scaled_met_clean_n;
  double scaled_vxp_sel_n;
  double scaled_trig_n;
  double scaled_lep_sel_n;
  double scaled_met_n;
  double scaled_one_jet_n;
  double scaled_full_elec_n;
  double scaled_full_muon_n;

  
 public:
  wwFileInfo(TString filename, string analyType="gww", bool loadMerged=false, bool loadFile=true,string colorScheme="conf");
  int NumberOfFiles();
  TObjArray* FileList();
  TObjArray* PlotsList();
  TObjArray* XSecs();
  TFile* MergedFile();
  int GetColor();
  void MergeAndWrite();
  string GetFileName();
  bool isSignal();
  double GetLineWidth();
  int GetLineStyle();
  int GetFillStyle();
  string GetProcess();
  string GetShortProc();
  void PrintInfo();
  double TotalNEvents();
  double TotalNEventsEwk();
  double TotalNEventsTTBar();
  double TotalNEventsJetM();  

  double ScaledNEvents();
  double ScaledNEventsEwk();
  double ScaledNEventsTTBar();
  double ScaledNEventsJetM();  

  double TotalSumOfWeights();  
  double ScaledSumOfWeights();
  double TotalAtLeastOneJetN();
  double ScaledNAtLeastOneJet();  
  double ScaledMetCleaningN();
  double ScaledVxpSelectionN();
  double ScaledTriggerN();
  double ScaledLeptonSelectionN();
  double ScaledMetCutN();
  double ScaledOneJetN();
  double ScaledNElectronEvents();
  double ScaledNMuonEvents();
  double ScaledAtLeastOneJetN();

  
  bool IsSignal();
  
  
};


wwFileInfo::wwFileInfo(TString fileName,string analyType,bool loadMerged, bool loadFile,string colorScheme){

  is_sig=false;
  merge_loaded=loadMerged;
  analy=analyType;

  color_scheme=colorScheme;
  
  tot_evt_n =0;
  tot_ewk_evt_n =0;
  tot_jetm_evt_n =0;
  tot_ttbar_evt_n =0;
  tot_sow_n =0;
  tot_one_jet_n =0;

  scaled_evt_n =0;
  scaled_ewk_evt_n =0;
  scaled_jetm_evt_n =0;
  scaled_ttbar_evt_n =0;
  scaled_sow_n = 0;
  scaled_met_clean_n = 0;
  scaled_vxp_sel_n = 0;  
  scaled_trig_n = 0;
  scaled_lep_sel_n = 0;
  scaled_met_n = 0;
  scaled_one_jet_n = 0;
  scaled_full_elec_n = 0;  
  scaled_full_muon_n = 0;  
  
  line_width=1;
  fill_style=-1;
  line_style=1;
  
  fileList = new TObjArray();
  plotList=new TObjArray();
  proc_type="lnuj";
  xsecs=new TObjArray();
  fname=fileName;
  process=fname;
  proc=fname;
  
  if(fileName=="data.lnuj" || fileName=="dataAE"){

    procs="data.lnuj";
    proc="data";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="data.lnuj"){

    procs="data.lnuj";
    proc="data";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;


  }else if(fileName=="mc.afii.kkg.lvjj.m500"){

    is_sig=true;

    line_width=4;
    fill_style=3344;
    line_style=4;
    procs="mc.afii.kkg.lvjj.m500.pu";
    proc="mc.afii.kkg.lvjj.m500";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.afii.kkg.lvjj.m600"){

    is_sig=true;

    line_width=4;
    fill_style=3344;
    line_style=4;
    procs="mc.afii.kkg.lvjj.m600.pu";
    proc="mc.afii.kkg.lvjj.m600";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.afii.kkg.lvjj.m700"){

    is_sig=true;
    line_width=3;
    fill_style=3004;
    line_style=1;
    procs="mc.afii.kkg.lvjj.m700.pu";
    proc="mc.afii.kkg.lvjj.m700";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.afii.kkg.lvjj.m800"){

    is_sig=true;

    line_width=3.5;
    fill_style=3004;
    line_style=1;
    procs="mc.afii.kkg.lvjj.m800.pu";
    proc="mc.afii.kkg.lvjj.m800";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kMagenta;

  }else if(fileName=="mc.afii.kkg.lvjj.m900"){

    is_sig=true;

    line_width=4;
    fill_style=3344;
    line_style=4;
    procs="mc.afii.kkg.lvjj.m900.pu";
    proc="mc.afii.kkg.lvjj.m900";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.afii.kkg.lvjj.m1000"){

    is_sig=true;
    line_width=3.5;
    fill_style=3844;
    line_style=1;
    procs="mc.afii.kkg.lvjj.m1000.pu";
    proc="mc.afii.kkg.lvjj.m1000";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kRed;

  }else if(fileName=="mc.afii.kkg.lvjj.m1100"){

    is_sig=true;

    line_width=4;
    fill_style=3344;
    line_style=4;
    procs="mc.afii.kkg.lvjj.m1100.pu";
    proc="mc.afii.kkg.lvjj.m1100";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kRed;

  }else if(fileName=="mc.afii.kkg.lvjj.m1200"){

    is_sig=true;

    line_width=3;
    fill_style=3344;
    line_style=1;
    procs="mc.afii.kkg.lvjj.m1200.pu";
    proc="mc.afii.kkg.lvjj.m1200";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.afii.kkg.lvjj.m1300"){

    is_sig=true;

    line_width=4;
    fill_style=3344;
    line_style=4;
    procs="mc.afii.kkg.lvjj.m1300.pu";
    proc="mc.afii.kkg.lvjj.m1300";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kRed;

  }else if(fileName=="mc.afii.kkg.lvjj.m1400"){

    is_sig=true;

    line_width=4;
    fill_style=3344;
    line_style=4;
    procs="mc.afii.kkg.lvjj.m1400.pu";
    proc="mc.afii.kkg.lvjj.m1400";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kRed;


  }else if(fileName=="mc.afii.kkg.lvjj.m1500"){

    is_sig=true;

    line_width=4;
    fill_style=3344;
    line_style=4;
    procs="mc.afii.kkg.lvjj.m1500.pu";
    proc="mc.afii.kkg.lvjj.m1500";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.fs.kkg.m1500"){

    is_sig=true;

    line_width=4;
    fill_style=3344;
    line_style=4;
    procs="mc.fs.kkg.m1500.pu";
    proc="mc.fs.kkg.m1500";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.gww.lvjj.m200.kmpl0_1"){

    is_sig=true;

    line_width=4;
    fill_style=3344;
    line_style=4;
    procs="mc.gww.lvjj.m200.kmpl0_1.pu";
    proc="gww.lvjj.m200.kmpl0_1";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;


  }else if(fileName=="mc.gww.lvjj.m350.kmpl0_1"){

    is_sig=true;

    line_width=3;
    fill_style=3344;
    line_style=1;
    procs="mc.gww.lvjj.m350.kmpl0_1.pu";
    proc="gww.lvjj.m350.kmpl0_1";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kRed;

  }else if(fileName=="mc.gww.lvjj.m500.kmpl0_1"){

    is_sig=true;

    line_width=3;
    fill_style=3344;
    line_style=1;
    procs="mc.gww.lvjj.m500.kmpl0_1.pu";
    proc="gww.lvjj.m500.kmpl0_1";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kRed;

  }else if(fileName=="mc.gww.lvjj.m750.kmpl0_1"){

    is_sig=true;
    line_width=3;
    //fill_style=3305;
    fill_style=3004;
    line_style=1;
    procs="mc.gww.lvjj.m750.kmpl0_1.pu";
    proc="gww.lvjj.m750.kmpl0_1";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.gww.lvjj.m1000.kmpl0_1"){

    is_sig=true;
    line_width=3;
    fill_style=3844;
    line_style=1;
    procs="mc.gww.lvjj.m1000.kmpl0_1.pu";
    proc="gww.lvjj.m1000.kmpl0_1";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.gww.lvjj.m1250.kmpl0_1"){

    is_sig=true;
    line_width=3;
    fill_style=3004;
    line_style=1;
    procs="mc.gww.lvjj.m1250.kmpl0_1.pu";
    proc="gww.lvjj.m1250.kmpl0_1";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;
    
  }else if(fileName=="mc.gww.lvjj.m1500.kmpl0_1"){

    is_sig=true;
    line_width=3;
    fill_style=3004;
    line_style=1;
    procs="mc.gww.lvjj.m1500.kmpl0_1.pu";
    proc="gww.lvjj.m1500.kmpl0_1";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;
    
  }else if(fileName=="mc.gzz.lljj.m500.kmpl0_1"){

    is_sig=true;

    line_width=3;
    fill_style=3344;
    line_style=1;
    procs="mc.gzz.lljj.m500.kmpl0_1.pu";
    proc="gzz.lljj.m500.kmpl0_1";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kRed;

  }else if(fileName=="mc.gzz.lljj.m750.kmpl0_1"){

    is_sig=true;
    line_width=3;
    //fill_style=3305;
    fill_style=3004;
    line_style=1;
    procs="mc.gzz.lljj.m750.kmpl0_1.pu";
    proc="gzz.lljj.m750.kmpl0_1";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kMagenta;

  }else if(fileName=="mc.gzz.lljj.m1000.kmpl0_1"){

    is_sig=true;
    line_width=3;
    fill_style=3844;
    line_style=1;
    procs="mc.gzz.lljj.m1000.kmpl0_1.pu";
    proc="gzz.lljj.m1000.kmpl0_1";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.gzz.lljj.m1250.kmpl0_1"){

    is_sig=true;
    line_width=3;
    fill_style=3004;
    line_style=1;
    procs="mc.gzz.lljj.m1250.kmpl0_1.pu";
    proc="gzz.lljj.m1250.kmpl0_1";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;
    
  }else if(fileName=="mc.gzz.lljj.m1500.kmpl0_1"){

    is_sig=true;
    line_width=3;
    fill_style=3004;
    line_style=1;
    procs="mc.gzz.lljj.m1500.kmpl0_1.pu";
    proc="gzz.lljj.m1500.kmpl0_1";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;
    
  }else if(fileName=="mc.rsg.m500.kmpl0_1"){

    is_sig=true;

    line_width=3;
    fill_style=3344;
    line_style=1;
    procs="mc.gww.lvjj.m500.kmpl0_1.pu,mc.gzz.lljj.m500.kmpl0_1.pu";
    //procs="mc.gww.lvjj.m500.kmpl0_1.pu";
    proc="rsG.m500.kmpl0_1";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.rsg.m750.kmpl0_1"){

    is_sig=true;
    line_width=3;
    //fill_style=3305;
    fill_style=3004;
    line_style=1;
    procs="mc.gww.lvjj.m750.kmpl0_1.pu,mc.gzz.lljj.m750.kmpl0_1.pu";
    //procs="mc.gww.lvjj.m750.kmpl0_1.pu";
    proc="rsG.m750.kmpl0_1";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.rsg.m1000.kmpl0_1"){

    is_sig=true;
    line_width=3;
    fill_style=3844;
    line_style=1;
    procs="mc.gww.lvjj.m1000.kmpl0_1.pu,mc.gzz.lljj.m1000.kmpl0_1.pu";
    //procs="mc.gww.lvjj.m1000.kmpl0_1.pu";
    proc="rsG.m1000.kmpl0_1";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kRed;

  }else if(fileName=="mc.rsg.m1250.kmpl0_1"){

    is_sig=true;
    line_width=3;
    fill_style=3004;
    line_style=1;
    procs="mc.gww.lvjj.m1250.kmpl0_1.pu,mc.gzz.lljj.m1250.kmpl0_1.pu";
    //procs="mc.gww.lvjj.m1250.kmpl0_1.pu";
    proc="rsG.m1250.kmpl0_1";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;
    
  }else if(fileName=="mc.rsg.m1500.kmpl0_1"){

    is_sig=true;
    line_width=3;
    fill_style=3004;
    line_style=1;
    procs="mc.gww.lvjj.m1500.kmpl0_1.pu,mc.gzz.lljj.m1500.kmpl0_1.pu";
    //procs="mc.gww.lvjj.m1500.kmpl0_1.pu";
    proc="rsG.m1500.kmpl0_1";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kMagenta;
    
  }else if(fileName=="mc.gww.lvjj.m200.kmpl0_01"){

    is_sig=true;

    line_width=4;
    fill_style=3344;
    line_style=4;
    procs="mc.gww.lvjj.m200.kmpl0_01.pu";
    proc="gww.lvjj.m200.kmpl0_01";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;


  }else if(fileName=="mc.gww.lvjj.m350.kmpl0_01"){

    is_sig=true;

    line_width=4;
    fill_style=3344;
    line_style=4;
    procs="mc.gww.lvjj.m350.kmpl0_01.pu";
    proc="gww.lvjj.m350.kmpl0_01";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.gww.lvjj.m500.kmpl0_01"){

    is_sig=true;

    line_width=4;
    fill_style=3344;
    line_style=4;
    procs="mc.gww.lvjj.m500.kmpl0_01.pu";
    proc="gww.lvjj.m500.kmpl0_01";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.gww.lvjj.m750.kmpl0_01"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.gww.lvjj.m750.kmpl0_01.pu";
    proc="gww.lvjj.m750.kmpl0_01";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;


  }else if(fileName=="mc.wprime.wz.lvqq.m500"){

    is_sig=true;
    line_width=3;
    fill_style=3344;
    line_style=1;
    procs="mc.wprime.wz.lvqq.m500.pu";
    proc="wprime.wz.lvqq.m500";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kRed;


  }else if(fileName=="mc.wprime.wz.lvqq.m600"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.lvqq.m600.pu";
    proc="wprime.wz.lvqq.m600";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.lvqq.m700"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.lvqq.m700.pu";
    proc="wprime.wz.lvqq.m700";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.lvqq.m800"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.lvqq.m800.pu";
    proc="wprime.wz.lvqq.m800";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.lvqq.m900"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.lvqq.m900.pu";
    proc="wprime.wz.lvqq.m900";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.lvqq.m1000"){

    is_sig=true;
    line_width=3;
    fill_style=3844;
    line_style=1;
    procs="mc.wprime.wz.lvqq.m1000.pu";
    proc="wprime.wz.lvqq.m1000";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kCyan;

  }else if(fileName=="mc.wprime.wz.lvqq.m1100"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.lvqq.m1100.pu";
    proc="wprime.wz.lvqq.m1100";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.lvqq.m1200"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.lvqq.m1200.pu";
    proc="wprime.wz.lvqq.m1200";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.lvqq.m1300"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.lvqq.m1300.pu";
    proc="wprime.wz.lvqq.m1300";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.lvqq.m1400"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.lvqq.m1400.pu";
    proc="wprime.wz.lvqq.m1400";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.lvqq.m1500"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.lvqq.m1500.pu";
    proc="wprime.wz.lvqq.m1500";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.qqee.m500"){

    is_sig=true;
    line_width=3;
    fill_style=3344;
    line_style=1;
    procs="mc.wprime.wz.qqee.m500.pu";
    proc="wprime.wz.qqee.m500";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kRed;


  }else if(fileName=="mc.wprime.wz.qqee.m600"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.qqee.m600.pu";
    proc="wprime.wz.qqee.m600";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.qqee.m700"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.qqee.m700.pu";
    proc="wprime.wz.qqee.m700";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.qqee.m800"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.qqee.m800.pu";
    proc="wprime.wz.qqee.m800";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.qqee.m900"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.qqee.m900.pu";
    proc="wprime.wz.qqee.m900";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.qqee.m1100"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.qqee.m1100.pu";
    proc="wprime.wz.qqee.m1100";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.qqee.m1200"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.qqee.m1200.pu";
    proc="wprime.wz.qqee.m1200";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.qqee.m1300"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.qqee.m1300.pu";
    proc="wprime.wz.qqee.m1300";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.qqee.m1400"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.qqee.m1400.pu";
    proc="wprime.wz.qqee.m1400";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.qquu.m500"){

    is_sig=true;
    line_width=3;
    fill_style=3344;
    line_style=1;
    procs="mc.wprime.wz.qquu.m500.pu";
    proc="wprime.wz.qquu.m500";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kRed;


  }else if(fileName=="mc.wprime.wz.qquu.m600"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.qquu.m600.pu";
    proc="wprime.wz.qquu.m600";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.qquu.m700"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.qquu.m700.pu";
    proc="wprime.wz.qquu.m700";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.qquu.m800"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.qquu.m800.pu";
    proc="wprime.wz.qquu.m800";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.qquu.m900"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.qquu.m900.pu";
    proc="wprime.wz.qquu.m900";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.qquu.m1100"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.qquu.m1100.pu";
    proc="wprime.wz.qquu.m1100";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.qquu.m1200"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.qquu.m1200.pu";
    proc="wprime.wz.qquu.m1200";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.qquu.m1300"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.qquu.m1300.pu";
    proc="wprime.wz.qquu.m1300";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.qquu.m1400"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.qquu.m1400.pu";
    proc="wprime.wz.qquu.m1400";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;


  }else if(fileName=="mc.wprime.wz.m500"){

    is_sig=true;
    line_width=3;
    fill_style=3344;
    line_style=1;
    procs="mc.wprime.wz.lvqq.m500.pu,mc.wprime.wz.qqee.m500.pu,mc.wprime.wz.qquu.m500.pu";
    proc="wprime.wz.m500";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kRed;


  }else if(fileName=="mc.wprime.wz.m600"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.lvqq.m600.pu,mc.wprime.wz.qqee.m600.pu,mc.wprime.wz.qquu.m600.pu";
    proc="wprime.wz.m600";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.m700"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.lvqq.m700.pu,mc.wprime.wz.qqee.m700.pu,mc.wprime.wz.qquu.m700.pu";
    proc="wprime.wz.m700";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.m800"){

    is_sig=true;
    line_width=3;
    fill_style=3004;
    line_style=1;
    procs="mc.wprime.wz.lvqq.m800.pu,mc.wprime.wz.qqee.m800.pu,mc.wprime.wz.qquu.m800.pu";
    proc="wprime.wz.m800";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kRed;

  }else if(fileName=="mc.wprime.wz.m900"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.lvqq.m900.pu,mc.wprime.wz.qqee.m900.pu,mc.wprime.wz.qquu.m900.pu";
    proc="wprime.wz.m900";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.m1000"){

    is_sig=true;
    line_width=3.5;
    fill_style=3844;
    line_style=1;
    procs="mc.wprime.wz.lvqq.m1000.pu";
    proc="wprime.wz.m1000";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kMagenta;

  }else if(fileName=="mc.wprime.wz.m1100"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.lvqq.m1100.pu,mc.wprime.wz.qqee.m1100.pu,mc.wprime.wz.qquu.m1100.pu";
    proc="wprime.wz.m1100";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.m1200"){

    is_sig=true;
    line_width=3;
    fill_style=3344;
    line_style=1;
    procs="mc.wprime.wz.lvqq.m1200.pu,mc.wprime.wz.qqee.m1200.pu,mc.wprime.wz.qquu.m1200.pu";
    proc="wprime.wz.m1200";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.m1300"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.lvqq.m1300.pu,mc.wprime.wz.qqee.m1300.pu,mc.wprime.wz.qquu.m1300.pu";
    proc="wprime.wz.m1300";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.m1400"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.lvqq.m1400.pu,mc.wprime.wz.qqee.m1400.pu,mc.wprime.wz.qquu.m1400.pu";
    proc="wprime.wz.m1400";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.wprime.wz.m1500"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.wprime.wz.lvqq.m1500.pu";
    proc="wprime.wz.m1500";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="mc.gzz.m500"){

    is_sig=true;
    line_width=4;
    fill_style=3344;
    line_style=4;
    procs="mc.gzz.m500.pu";
    proc="gzz.m500";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlue;

  }else if(fileName=="mc.gzz.m750"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="mc.gzz.m750.pu";
    proc="gzz.m750";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlue;

  }else if(fileName=="mc.gzz.m1000"){

    is_sig=true;    
    line_width=3;
    fill_style=3844;
    line_style=2;
    procs="mc.gzz.m1000.pu";
    proc="gzz.m1000";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlue;

  }else if(fileName=="mc.gzz.m1250"){

    is_sig=true;
    line_width=3;
    fill_style=3004;
    line_style=1;
    procs="mc.gzz.m1250.pu";
    proc="gzz.m1250";    
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlue;


  }else if(fileName=="qcd"){

    procs="qcd.elec.pu,qcd.muon.pu";
    nFiles = procs.Tokenize(",")->GetEntries();
    proc="qcd";
    //color=30;

    color=1;
    fill_style=3003;

    if(color_scheme=="conf"){
      color=kGreen-8;
      fill_style=1;
    }
    
  }else if(fileName=="qcd.alpgen"){

    procs="qcd.elec.alpgen.pu,qcd.muon.alpgen.pu";
    nFiles = procs.Tokenize(",")->GetEntries();
    proc="qcd";
    color=1;
    fill_style=3003;
    
    if(color_scheme=="conf"){
      color=kGreen-8;
      fill_style=1001;
    }
  }else if(fileName=="qcd.sherpa"){

    procs="qcd.elec.sherpa.pu,qcd.muon.sherpa.pu";
    nFiles = procs.Tokenize(",")->GetEntries();
    proc="qcd";
    color=1;
    fill_style=3003;

    if(color_scheme=="conf"){
      //color=kMagenta-8;
      color=kGreen-8;
      fill_style=1001;
    }
  }else if(fileName=="qcd.pythia"){

    procs="qcd.elec.pythia.pu,qcd.muon.pythia.pu";
    nFiles = procs.Tokenize(",")->GetEntries();
    proc="qcd";
    color=1;
    fill_style=3003;

    if(color_scheme=="conf"){
      color=kMagenta-8;
      fill_style=1001;
    }
  }else if(fileName=="mc.pythia.jj"){
    
    procs="mc.pythia.jj1e.j0.pu,mc.pythia.jj1e.j1.pu,mc.pythia.jj1e.j2.pu,mc.pythia.jj1e.j3.pu,";
    procs+="mc.pythia.jj1u.j0.pu,mc.pythia.jj1u.j1.pu,mc.pythia.jj1u.j2.pu,mc.pythia.jj1u.j3.pu";
    nFiles = procs.Tokenize(",")->GetEntries();
    proc="jj";
    color=1;
    fill_style=3003;

    if(color_scheme=="conf"){
      color=1;
      fill_style=3003;
    }

  }else if(fileName=="mc.alpgen.wenu"){

    procs="mc.alpgen.wenu.np0.pu,mc.alpgen.wenu.np1.pu,mc.alpgen.wenu.np2.pu,mc.alpgen.wenu.np3.pu,mc.alpgen.wenu.np4.pu,mc.alpgen.wenu.np5.pu,";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlue;

    if(color_scheme=="conf"){
      color=kBlue;
    }

  }else if(fileName=="mc.alpgen.wunu"){

    procs="mc.alpgen.wunu.np0.pu,mc.alpgen.wunu.np1.pu,mc.alpgen.wunu.np2.pu,mc.alpgen.wunu.np3.pu,mc.alpgen.wunu.np4.pu,mc.alpgen.wunu.np5.pu,";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlue-9;

    if(color_scheme=="conf"){
      color=kBlue;
    }
  }else if(fileName=="mc.alpgen.wunu.np0"){

    procs="mc.alpgen.wunu.np0.pu";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kYellow;

    if(color_scheme=="conf"){
      color=kYellow;
    }
  }else if(fileName=="mc.alpgen.wunu.np1"){

    procs="mc.alpgen.wunu.np1.pu";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlue;

    if(color_scheme=="conf"){
      color=kBlue;
    }
  }else if(fileName=="mc.alpgen.wunu.np2"){

    procs="mc.alpgen.wunu.np2.pu";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kGreen;

    if(color_scheme=="conf"){
      color=kGreen;
    }
  }else if(fileName=="mc.alpgen.wunu.np3"){

    procs="mc.alpgen.wunu.np3.pu";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kOrange;

    if(color_scheme=="conf"){
      color=kOrange;
    }
  }else if(fileName=="mc.alpgen.wunu.np4"){

    procs="mc.alpgen.wunu.np4.pu";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kRed;

    if(color_scheme=="conf"){
      color=kRed;
    }
  }else if(fileName=="mc.alpgen.wunu.np5"){

    procs="mc.alpgen.wunu.np5.pu";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kMagenta;

    if(color_scheme=="conf"){
      color=kMagenta;
    }
      }else if(fileName=="mc.alpgen.wenu.np0"){

    procs="mc.alpgen.wenu.np0.pu";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kYellow;

    if(color_scheme=="conf"){
      color=kYellow;
    }
  }else if(fileName=="mc.alpgen.wenu.np1"){

    procs="mc.alpgen.wenu.np1.pu";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlue;

    if(color_scheme=="conf"){
      color=kBlue;
    }
  }else if(fileName=="mc.alpgen.wenu.np2"){

    procs="mc.alpgen.wenu.np2.pu";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kGreen;

    if(color_scheme=="conf"){
      color=kGreen;
    }
  }else if(fileName=="mc.alpgen.wenu.np3"){

    procs="mc.alpgen.wenu.np3.pu";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kOrange;

    if(color_scheme=="conf"){
      color=kOrange;
    }
  }else if(fileName=="mc.alpgen.wenu.np4"){

    procs="mc.alpgen.wenu.np4.pu";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kRed;

    if(color_scheme=="conf"){
      color=kRed;
    }
  }else if(fileName=="mc.alpgen.wenu.np5"){

    procs="mc.alpgen.wenu.np5.pu";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kMagenta;

    if(color_scheme=="conf"){
      color=kMagenta;
    }
    
}else if(fileName=="mc.alpgen.wtnu"){

    procs="mc.alpgen.wtnu.np0.pu,mc.alpgen.wtnu.np1.pu,mc.alpgen.wtnu.np2.pu,mc.alpgen.wtnu.np3.pu,mc.alpgen.wtnu.np4.pu,mc.alpgen.wtnu.np5.pu,";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlue-5;

    if(color_scheme=="conf"){
      color=kBlue;
    }

  }else if(fileName=="mc.alpgen.wjets"){

    procs="mc.alpgen.wenu.np0.pu,mc.alpgen.wenu.np1.pu,mc.alpgen.wenu.np2.pu,mc.alpgen.wenu.np3.pu,mc.alpgen.wenu.np4.pu,mc.alpgen.wenu.np5.pu,";
    procs+="mc.alpgen.wunu.np0.pu,mc.alpgen.wunu.np1.pu,mc.alpgen.wunu.np2.pu,mc.alpgen.wunu.np3.pu,mc.alpgen.wunu.np4.pu,mc.alpgen.wunu.np5.pu,";
    procs+="mc.alpgen.wtnu.np0.pu,mc.alpgen.wtnu.np1.pu,mc.alpgen.wtnu.np2.pu,mc.alpgen.wtnu.np3.pu,mc.alpgen.wtnu.np4.pu,mc.alpgen.wtnu.np5.pu";
    // Optional heavy flavor
    /* procs+="mc.alpgen.wbb.np0.pu,mc.alpgen.wbb.np1.pu,mc.alpgen.wbb.np2.pu,mc.alpgen.wbb.np3.pu,"; */
    /* procs+="mc.alpgen.wcc.np0.pu,mc.alpgen.wcc.np1.pu,mc.alpgen.wcc.np2.pu,mc.alpgen.wcc.np3.pu,"; */
    /* procs+="mc.alpgen.wc.np0.pu,mc.alpgen.wc.np1.pu,mc.alpgen.wc.np2.pu,mc.alpgen.wc.np3.pu,mc.alpgen.wc.np4.pu"; */
    
    proc="alpgen.wjets";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=6;
    
    if(color_scheme=="conf"){
      color=6;
    }

  }else if(fileName=="mc.alpgen.cont.wjets"){

    procs="mc.alpgen.cont.wenu.np0.pu,mc.alpgen.cont.wenu.np1.pu,mc.alpgen.cont.wenu.np2.pu,mc.alpgen.cont.wenu.np3.pu,mc.alpgen.cont.wenu.np4.pu,mc.alpgen.cont.wenu.np5.pu,";
    procs+="mc.alpgen.cont.wunu.np0.pu,mc.alpgen.cont.wunu.np1.pu,mc.alpgen.cont.wunu.np2.pu,mc.alpgen.cont.wunu.np3.pu,mc.alpgen.cont.wunu.np4.pu,mc.alpgen.cont.wunu.np5.pu";
    //procs+="mc.alpgen.cont.wtnu.np0.pu,mc.alpgen.cont.wtnu.np1.pu,mc.alpgen.cont.wtnu.np2.pu,mc.alpgen.cont.wtnu.np3.pu,mc.alpgen.cont.wtnu.np4.pu,mc.alpgen.cont.wtnu.np5.pu";
    // Optional heavy flavor
    /* procs+="mc.alpgen.wbb.np0.pu,mc.alpgen.wbb.np1.pu,mc.alpgen.wbb.np2.pu,mc.alpgen.wbb.np3.pu,"; */
    /* procs+="mc.alpgen.wcc.np0.pu,mc.alpgen.wcc.np1.pu,mc.alpgen.wcc.np2.pu,mc.alpgen.wcc.np3.pu,"; */
    /* procs+="mc.alpgen.wc.np0.pu,mc.alpgen.wc.np1.pu,mc.alpgen.wc.np2.pu,mc.alpgen.wc.np3.pu,mc.alpgen.wc.np4.pu"; */
    
    proc="alpgen.cont.wjets";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=6;
    
    if(color_scheme=="conf"){
      color=6;
    }

  
  }else if(fileName=="sel.alpgen.wjets"){

    procs="sel.alpgen.wenu.np0.pu,sel.alpgen.wenu.np1.pu,sel.alpgen.wenu.np2.pu,sel.alpgen.wenu.np3.pu,sel.alpgen.wenu.np4.pu,sel.alpgen.wenu.np5.pu,";
    procs+="sel.alpgen.wunu.np0.pu,sel.alpgen.wunu.np1.pu,sel.alpgen.wunu.np2.pu,sel.alpgen.wunu.np3.pu,sel.alpgen.wunu.np4.pu,sel.alpgen.wunu.np5.pu,";
    procs+="sel.alpgen.wtnu.np0.pu,sel.alpgen.wtnu.np1.pu,sel.alpgen.wtnu.np2.pu,sel.alpgen.wtnu.np3.pu,sel.alpgen.wtnu.np4.pu,sel.alpgen.wtnu.np5.pu";

    proc="alpgen.wjets";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=6;
    
    if(color_scheme=="conf"){
      color=6;
    }

  }else if(fileName=="mc.sherpa.wjets"){

    procs="mc.sherpa.wenu.pu,mc.sherpa.wunu.pu,mc.sherpa.wtnu.pu";
    proc="sherpa.wjets";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=7;

    if(color_scheme=="conf"){
      color=7;
    }

  }else if(fileName=="mc.sherpa.zjets"){

    procs="mc.sherpa.zee.pu,mc.sherpa.zuu.pu,mc.sherpa.ztt.pu";
    proc="sherpa.zjets";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=7;
    fill_style=3003;
    if(color_scheme=="conf"){
      color=kGreen;
      fill_style=1001;
    }

  }else if(fileName=="mc.pythia.wjets"){

    //tmp
    procs="mc.pythia.wenu.pu,mc.pythia.wunu.pu,mc.pythia.wtnu.pu";
    proc="pythia.wjets";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=6;

    if(color_scheme=="conf"){
      color=6;
    }

  }else if(fileName=="mc.pythia.zjets"){

    procs="mc.pythia.zee.pu,mc.pythia.zuu.pu,mc.pythia.ztt.pu";
    proc="pythia.zjets";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=6;
    fill_style=3003;
    if(color_scheme=="conf"){
      color=kGreen;
      fill_style=1001;
    }

  }else if(fileName=="mc.alpgen.wbb"){

    procs="mc.alpgen.wbb.np0.pu,mc.alpgen.wbb.np1.pu,mc.alpgen.wbb.np2.pu,mc.alpgen.wbb.np3.pu";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=6;

    if(color_scheme=="conf"){
      color=6;
    }

    
  }else if(fileName=="mc.alpgen.zjets"){

    procs="mc.alpgen.zee.np0.pu,mc.alpgen.zee.np1.pu,mc.alpgen.zee.np2.pu,mc.alpgen.zee.np3.pu,mc.alpgen.zee.np4.pu,mc.alpgen.zee.np5.pu,";
    procs+="mc.alpgen.zuu.np0.pu,mc.alpgen.zuu.np1.pu,mc.alpgen.zuu.np2.pu,mc.alpgen.zuu.np3.pu,mc.alpgen.zuu.np4.pu,mc.alpgen.zuu.np5.pu,";
    procs+="mc.alpgen.ztt.np0.pu,mc.alpgen.ztt.np1.pu,mc.alpgen.ztt.np2.pu,mc.alpgen.ztt.np3.pu,mc.alpgen.ztt.np4.pu,mc.alpgen.ztt.np5.pu";
    //procs+="mc.alpgen.zee.lowm.np0.pu,mc.alpgen.zee.lowm.np1.pu,mc.alpgen.zee.lowm.np2.pu,mc.alpgen.zee.lowm.np3.pu,mc.alpgen.zee.lowm.np4.pu,mc.alpgen.zee.lowm.np5.pu,";
    //procs+="mc.alpgen.zuu.lowm.np0.pu,mc.alpgen.zuu.lowm.np1.pu,mc.alpgen.zuu.lowm.np2.pu,mc.alpgen.zuu.lowm.np3.pu,mc.alpgen.zuu.lowm.np4.pu,mc.alpgen.zuu.lowm.np5.pu,";
    //procs+="mc.alpgen.ztt.lowm.np0.pu,mc.alpgen.ztt.lowm.np1.pu,mc.alpgen.ztt.lowm.np2.pu,mc.alpgen.ztt.lowm.np3.pu,mc.alpgen.ztt.lowm.np4.pu,mc.alpgen.ztt.lowm.np5.pu";

    proc="zjets";
    nFiles = procs.Tokenize(",")->GetEntries();

    color=4;
    fill_style=3003;

    if(color_scheme=="conf"){
      color=kGreen;
      fill_style=1001;
    }
    
  }else if(fileName=="sel.alpgen.zjets"){

    procs="sel.alpgen.zee.np0.pu,sel.alpgen.zee.np1.pu,sel.alpgen.zee.np2.pu,sel.alpgen.zee.np3.pu,sel.alpgen.zee.np4.pu,sel.alpgen.zee.np5.pu,";
    procs+="sel.alpgen.zuu.np0.pu,sel.alpgen.zuu.np1.pu,sel.alpgen.zuu.np2.pu,sel.alpgen.zuu.np3.pu,sel.alpgen.zuu.np4.pu,sel.alpgen.zuu.np5.pu,";
    procs+="sel.alpgen.ztt.np0.pu,sel.alpgen.ztt.np1.pu,sel.alpgen.ztt.np2.pu,sel.alpgen.ztt.np3.pu,sel.alpgen.ztt.np4.pu,sel.alpgen.ztt.np5.pu";

    proc="zjets";
    nFiles = procs.Tokenize(",")->GetEntries();

    color=4;
    fill_style=3003;

    if(color_scheme=="conf"){
      color=kGreen;
      fill_style=1001;
    }
    
  }else if(fileName=="sel.herwig.vv"){

    procs="sel.herwig.ww.pu,sel.herwig.wz.pu,sel.herwig.zz.pu";
    proc="vv";
    nFiles = procs.Tokenize(",")->GetEntries();

    color=46;
    fill_style=3003;

    if(color_scheme=="conf"){
      color=kYellow-4;
      fill_style=1001;
    }
    
  }else if(fileName=="mc.herwig.vv"){

    procs="mc.herwig.ww.pu,mc.herwig.wz.pu,mc.herwig.zz.pu";
    proc="vv";
    nFiles = procs.Tokenize(",")->GetEntries();

    color=46;
    fill_style=3003;

    if(color_scheme=="conf"){
      color=kYellow-4;
      fill_style=1001;
    }
    
  }else if(fileName=="mc.herwig.ww"){
    
    procs="mc.herwig.ww.pu";
    proc="ww";
    nFiles = procs.Tokenize(",")->GetEntries();

    color=38; 
    fill_style=3003;

    if(color_scheme=="conf"){
      color=38; 
      fill_style=3003;
    }
    
  }else if(fileName=="mc.herwig.wz"){
    
    procs="mc.herwig.wz.pu";
    proc="wz";
    nFiles = procs.Tokenize(",")->GetEntries();

    color=31;
    fill_style=3003;

    if(color_scheme=="conf"){
      color=31;
      fill_style=3003;
    }
    
  }else if(fileName=="mc.herwig.zz"){
    
    procs="mc.herwig.zz.pu";
    proc="zz";
    nFiles = procs.Tokenize(",")->GetEntries();

    color=46;
    fill_style=3003;

    if(color_scheme=="conf"){
      color=46;
      fill_style=3003;
    }
    
  }else if(fileName=="sel.herwig.ww"){
    
    procs="sel.herwig.ww.pu";
    proc="ww";
    nFiles = procs.Tokenize(",")->GetEntries();

    color=38; 
    fill_style=3003;

    if(color_scheme=="conf"){
      color=38; 
      fill_style=3003;
    }
    
  }else if(fileName=="sel.herwig.wz"){
    
    procs="sel.herwig.wz.pu";
    proc="wz";
    nFiles = procs.Tokenize(",")->GetEntries();

    color=31;
    fill_style=3003;

    if(color_scheme=="conf"){
      color=31;
      fill_style=3003;
    }
    
  }else if(fileName=="sel.herwig.zz"){
    
    procs="sel.herwig.zz.pu";
    proc="zz";
    nFiles = procs.Tokenize(",")->GetEntries();

    color=46;
    fill_style=3003;

    if(color_scheme=="conf"){
      color=46;
      fill_style=3003;
    }
    
  }else if(fileName=="mc.alpgen.zjets.lowm"){

    procs="mc.alpgen.zee.lowm.np0.pu,mc.alpgen.zee.lowm.np1.pu,mc.alpgen.zee.lowm.np2.pu,mc.alpgen.zee.lowm.np3.pu,mc.alpgen.zee.lowm.np4.pu,mc.alpgen.zee.lowm.np5.pu,";
    procs+="mc.alpgen.zuu.lowm.np0.pu,mc.alpgen.zuu.lowm.np1.pu,mc.alpgen.zuu.lowm.np2.pu,mc.alpgen.zuu.lowm.np3.pu,mc.alpgen.zuu.lowm.np4.pu,mc.alpgen.zuu.lowm.np5.pu,";
    procs+="mc.alpgen.ztt.lowm.np0.pu,mc.alpgen.ztt.lowm.np1.pu,mc.alpgen.ztt.lowm.np2.pu,mc.alpgen.ztt.lowm.np3.pu,mc.alpgen.ztt.lowm.np4.pu,mc.alpgen.ztt.lowm.np5.pu";
    nFiles = procs.Tokenize(",")->GetEntries();

    color=kRed;

    if(color_scheme=="conf"){
      color=kRed;
    }
    
  }else if(fileName=="mc.mcatnlo.top"){

    procs="mc.mcatnlo.t1.pu,";
    procs+="mc.mcatnlo.st.tchan.enu.pu,mc.mcatnlo.st.tchan.unu.pu,mc.mcatnlo.st.tchan.tnu.pu,";
    procs+="mc.mcatnlo.st.schan.enu.pu,mc.mcatnlo.st.schan.unu.pu,mc.mcatnlo.st.schan.tnu.pu,";
    procs+="mc.mcatnlo.st.wt.pu";
    proc="top";
    nFiles = procs.Tokenize(",")->GetEntries();

    color=8;
    fill_style=3003;

    if(color_scheme=="conf"){
      color=kAzure+1;
      fill_style=1001;
    }
  }else if(fileName=="mc.acer.ttbar"){

    //procs="mc.mcatnlo.t1.pu,";
    procs="mc.acer.ttbar.pu";
    //procs+="mc.mcatnlo.st.tchan.enu.pu,mc.mcatnlo.st.tchan.unu.pu,mc.mcatnlo.st.tchan.tnu.pu,";
    //procs+="mc.mcatnlo.st.schan.enu.pu,mc.mcatnlo.st.schan.unu.pu,mc.mcatnlo.st.schan.tnu.pu,";
    //procs+="mc.mcatnlo.st.wt.pu";
    proc="top";
    nFiles = procs.Tokenize(",")->GetEntries();

    color=8;
    fill_style=3003;

    if(color_scheme=="conf"){
      color=kAzure+1;
      fill_style=1001;
    }
  }else if(fileName=="mc.acer.lessps.ttbar"){

    //procs="mc.mcatnlo.t1.pu,";
    procs="mc.acer.ttbar.lessps.pu";
    //procs+="mc.mcatnlo.st.tchan.enu.pu,mc.mcatnlo.st.tchan.unu.pu,mc.mcatnlo.st.tchan.tnu.pu,";
    //procs+="mc.mcatnlo.st.schan.enu.pu,mc.mcatnlo.st.schan.unu.pu,mc.mcatnlo.st.schan.tnu.pu,";
    //procs+="mc.mcatnlo.st.wt.pu";
    proc="top";
    nFiles = procs.Tokenize(",")->GetEntries();

    color=8;
    fill_style=3003;

    if(color_scheme=="conf"){
      color=kAzure+1;
      fill_style=1001;
    }
  }else if(fileName=="mc.acer.moreps.ttbar"){

    //procs="mc.mcatnlo.t1.pu,";
    procs="mc.acer.ttbar.moreps.pu";
    //procs+="mc.mcatnlo.st.tchan.enu.pu,mc.mcatnlo.st.tchan.unu.pu,mc.mcatnlo.st.tchan.tnu.pu,";
    //procs+="mc.mcatnlo.st.schan.enu.pu,mc.mcatnlo.st.schan.unu.pu,mc.mcatnlo.st.schan.tnu.pu,";
    //procs+="mc.mcatnlo.st.wt.pu";
    proc="top";
    nFiles = procs.Tokenize(",")->GetEntries();

    color=8;
    fill_style=3003;

    if(color_scheme=="conf"){
      color=kAzure+1;
      fill_style=1001;
    }
  }else if(fileName=="sel.mcatnlo.top"){

    procs="sel.mcatnlo.t1.pu,";
    procs+="sel.mcatnlo.st.tchan.enu.pu,sel.mcatnlo.st.tchan.unu.pu,sel.mcatnlo.st.tchan.tnu.pu,";
    procs+="sel.mcatnlo.st.schan.enu.pu,sel.mcatnlo.st.schan.unu.pu,sel.mcatnlo.st.schan.tnu.pu,";
    procs+="sel.mcatnlo.st.wt.pu";
    proc="top";
    nFiles = procs.Tokenize(",")->GetEntries();

    color=8;
    fill_style=3003;

    if(color_scheme=="conf"){
      color=kAzure+1;
      fill_style=1001;
    }
        
  }else if(fileName=="mc.mcatnlo.ttbar"){

    procs="mc.mcatnlo.t1.pu";
    proc="ttbar";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kAzure+1;

    if(color_scheme=="conf"){
      color=kAzure+1;
      fill_style=1001;
    }
  }else if(fileName=="sel.mcatnlo.ttbar"){

    procs="sel.mcatnlo.t1.pu";
    proc="ttbar";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kAzure+1;

    if(color_scheme=="conf"){
      color=kAzure+1;
      fill_style=1001;
    }
    
  }else if(fileName=="mc.mcatnlo.singletop"){

    procs="mc.mcatnlo.st.tchan.enu.pu,mc.mcatnlo.st.tchan.unu.pu,mc.mcatnlo.st.tchan.tnu.pu,";
    procs+="mc.mcatnlo.st.schan.enu.pu,mc.mcatnlo.st.schan.unu.pu,mc.mcatnlo.st.schan.tnu.pu,";
    procs+="mc.mcatnlo.st.wt.pu";
    proc="singletop";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlue-9;

    if(color_scheme=="conf"){
      color=kBlue-9;
    }

  }else if(fileName=="sel.gww.lvjj.m200.kmpl0_1"){

    is_sig=true;

    line_width=4;
    fill_style=3344;
    line_style=4;
    procs="sel.gww.lvjj.m200.kmpl0_1.pu";
    proc="gww.lvjj.m200.kmpl0_1";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;


  }else if(fileName=="sel.gww.lvjj.m350.kmpl0_1"){

    is_sig=true;

    line_width=3;
    fill_style=3344;
    line_style=1;
    procs="sel.gww.lvjj.m350.kmpl0_1.pu";
    proc="gww.lvjj.m350.kmpl0_1";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kRed;

  }else if(fileName=="sel.gww.lvjj.m500.kmpl0_1"){

    is_sig=true;

    line_width=3;
    fill_style=3344;
    line_style=1;
    procs="sel.gww.lvjj.m500.kmpl0_1.pu";
    proc="gww.lvjj.m500.kmpl0_1";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kOrange;

  }else if(fileName=="sel.gww.lvjj.m750.kmpl0_1"){

    is_sig=true;
    line_width=3;
    //fill_style=3305;
    fill_style=3004;
    line_style=1;
    procs="sel.gww.lvjj.m750.kmpl0_1.pu";
    proc="gww.lvjj.m750.kmpl0_1";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kMagenta;

  }else if(fileName=="sel.gww.lvjj.m1000.kmpl0_1"){

    is_sig=true;
    line_width=3;
    fill_style=3844;
    line_style=1;
    procs="sel.gww.lvjj.m1000.kmpl0_1.pu";
    proc="gww.lvjj.m1000.kmpl0_1";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kCyan;

  }else if(fileName=="sel.gww.lvjj.m1250.kmpl0_1"){

    is_sig=true;
    line_width=3;
    fill_style=3004;
    line_style=1;
    procs="sel.gww.lvjj.m1250.kmpl0_1.pu";
    proc="gww.lvjj.m1250.kmpl0_1";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;
    
  }else if(fileName=="sel.gww.lvjj.m1500.kmpl0_1"){

    is_sig=true;
    line_width=3;
    fill_style=3004;
    line_style=1;
    procs="sel.gww.lvjj.m1500.kmpl0_1.pu";
    proc="gww.lvjj.m1500.kmpl0_1";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;
    
  }else if(fileName=="sel.gww.lvjj.m200.kmpl0_01"){

    is_sig=true;

    line_width=4;
    fill_style=3344;
    line_style=4;
    procs="sel.gww.lvjj.m200.kmpl0_01.pu";
    proc="gww.lvjj.m200.kmpl0_01";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;


  }else if(fileName=="sel.gww.lvjj.m350.kmpl0_01"){

    is_sig=true;

    line_width=4;
    fill_style=3344;
    line_style=4;
    procs="sel.gww.lvjj.m350.kmpl0_01.pu";
    proc="gww.lvjj.m350.kmpl0_01";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="sel.gww.lvjj.m500.kmpl0_01"){

    is_sig=true;

    line_width=4;
    fill_style=3344;
    line_style=4;
    procs="sel.gww.lvjj.m500.kmpl0_01.pu";
    proc="gww.lvjj.m500.kmpl0_01";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="sel.gww.lvjj.m750.kmpl0_01"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="sel.gww.lvjj.m750.kmpl0_01.pu";
    proc="gww.lvjj.m750.kmpl0_01";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;


  }else if(fileName=="sel.wprime.wz.lvqq.m500"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="sel.wprime.wz.lvqq.m500.pu";
    proc="wprime.wz.lvqq.m500";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;


  }else if(fileName=="sel.wprime.wz.lvqq.m600"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="sel.wprime.wz.lvqq.m600.pu";
    proc="wprime.wz.lvqq.m600";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="sel.wprime.wz.lvqq.m700"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="sel.wprime.wz.lvqq.m700.pu";
    proc="wprime.wz.lvqq.m700";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="sel.wprime.wz.lvqq.m800"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="sel.wprime.wz.lvqq.m800.pu";
    proc="wprime.wz.lvqq.m800";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="sel.wprime.wz.lvqq.m900"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="sel.wprime.wz.lvqq.m900.pu";
    proc="wprime.wz.lvqq.m900";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="sel.wprime.wz.lvqq.m1000"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="sel.wprime.wz.lvqq.m1000.pu";
    proc="wprime.wz.lvqq.m1000";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="sel.wprime.wz.lvqq.m1100"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="sel.wprime.wz.lvqq.m1100.pu";
    proc="wprime.wz.lvqq.m1100";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="sel.wprime.wz.lvqq.m1200"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="sel.wprime.wz.lvqq.m1200.pu";
    proc="wprime.wz.lvqq.m1200";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="sel.wprime.wz.lvqq.m1300"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="sel.wprime.wz.lvqq.m1300.pu";
    proc="wprime.wz.lvqq.m1300";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="sel.wprime.wz.lvqq.m1400"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="sel.wprime.wz.lvqq.m1400.pu";
    proc="wprime.wz.lvqq.m1400";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;

  }else if(fileName=="sel.wprime.wz.lvqq.m1500"){

    is_sig=true;
    line_width=4;
    fill_style=3305;
    line_style=3;
    procs="sel.wprime.wz.lvqq.m1500.pu";
    proc="wprime.wz.lvqq.m1500";
    nFiles = procs.Tokenize(",")->GetEntries();
    color=kBlack;
    
  }else{
    std::cout<<"Invalid merge name ("<<fileName<<") for wwFileInfo!"<<std::endl;
    return;
  }

  if(merge_loaded){

    string curMerged = "../plots/"+analy+"_plots/merged/";
    curMerged+=fileName;
    if(analy=="ctrl"){
      curMerged+=".ctrl.plot.root";
    }else if(analy=="sys_wjets"){
      curMerged+=".sys.wjets.plot.root";
    }else if(analy=="systematics"){
      curMerged+=".systematics.plot.root";
    }else if(analy=="jvf"){
      curMerged+=".jvf.root";
    }else if(analy=="nojvf"){
      curMerged+=".nojvf.root";
    }else{
      curMerged+=".plot.root";
    }
    //std::cout<<"wwFileInfo adding "<<curMerged<<std::endl;    
    merged = (TFile*) TFile::Open(curMerged.c_str());
  }

  
  if(loadFile && !merge_loaded){
    //Load File List and XSec list
    for(int i=0;i<nFiles;i++){

      
      TObjArray* curProcs = (TObjArray*) procs.Tokenize(",");
      string curProc = ((TObject*) curProcs->At(i))->GetName();
      string curFile = "../";
      string curPlots = "../plots/";
      curPlots+=analy;
      curPlots+="_plots/";
      
      if(analy=="gww"){
	curPlots+=curProc+".plot.root";
      }else if(analy=="ctrl"){
	curPlots+=curProc+".ctrl.plot.root";
      }else if(analy=="sys_wjets"){
	curPlots+=curProc+".plot.root";
      }else if(analy=="systematics"){
	curPlots+=curProc+".plot.root";
      }else if(analy=="limit"){
	curPlots+=curProc+".limit.plot.root";
      }else if(analy=="selection"){
	curPlots+=curProc+".skim.root";
      }else if(analy=="jvf"){
	curPlots+=curProc+".plot.jvf.root";
      }else if(analy=="nojvf"){
	curPlots+=curProc+".plot.nojvf.root";
      }else{
	cout<<"Can't load "<<curPlots<<"for analy: "<<analy<<endl;
      }


      TFile* curPlotFile = TFile::Open(curPlots.c_str());

      if(curPlotFile) {

	//std::cout<<"wwFileInfo adding "<<curFile<<std::endl;
	std::cout<<"wwFileInfo adding "<<curPlots<<std::endl; 

	
	plotList->Add(curPlotFile);
	//fileList->Add( TFile::Open(curFile.c_str()) );
	xsecs->Add(new wwXSec(curProc.c_str()));

      }
      
    }
  }else if(loadMerged){

    TDirectory* evt_dir = (TDirectory*) merged->GetDirectory("evt_sel");
    if(evt_dir) {
      TH1F* h_evt_n = (TH1F*) evt_dir->Get("h_evt_n");
      TH1F* h_sow_n = (TH1F*) evt_dir->Get("h_sow_n");
      TH1F* h_met_clean_n = (TH1F*) evt_dir->Get("h_met_clean_n");
      TH1F* h_vxp_sel_n = (TH1F*) evt_dir->Get("h_vxp_sel_n");
      TH1F* h_trig_n = (TH1F*) evt_dir->Get("h_trig_n");
      TH1F* h_lep_sel_n = (TH1F*) evt_dir->Get("h_lep_sel_n");
      TH1F* h_met_n = (TH1F*) evt_dir->Get("h_met_n");
      TH1F* h_one_jet_n = (TH1F*) evt_dir->Get("h_at_least_one_jet_n");
      TH1F* h_full_elec_n = (TH1F*) evt_dir->Get("h_full_elec_n");
      TH1F* h_full_muon_n = (TH1F*) evt_dir->Get("h_full_muon_n");                              

      if(!h_evt_n || !h_sow_n || !h_met_clean_n || !h_vxp_sel_n || !h_lep_sel_n ||
	 !h_trig_n || !h_met_n || !h_one_jet_n || !h_full_elec_n || !h_full_muon_n){
	cout<<"Error loading evt_dir histograms in "<<fileName<<endl;
	return;
      }
	 
      tot_evt_n = h_evt_n->GetEntries();
      tot_sow_n = h_sow_n->GetEntries();
      tot_one_jet_n = h_one_jet_n->GetEntries();

      scaled_evt_n = h_evt_n->Integral();
      scaled_sow_n = h_sow_n->Integral();
      scaled_met_clean_n = h_met_clean_n->Integral();      
      scaled_vxp_sel_n = h_vxp_sel_n->Integral();      
      scaled_trig_n = h_trig_n->Integral();
      scaled_lep_sel_n = h_lep_sel_n->Integral();
      scaled_met_n = h_met_n->Integral();
      scaled_one_jet_n = h_one_jet_n->Integral();
      scaled_full_elec_n = h_full_elec_n->Integral();
      scaled_full_muon_n = h_full_muon_n->Integral();            
      
    }

    TDirectory* ewk_dir = (TDirectory*) merged->GetDirectory("ewk");
    if(ewk_dir) {
      TH1F* h_ewk_evt_n = (TH1F*) ewk_dir->Get("h_ewk_evt_n");
      tot_ewk_evt_n = h_ewk_evt_n->GetEntries();
      scaled_ewk_evt_n = h_ewk_evt_n->Integral();      
    }

    
    TDirectory* ttbar_dir = (TDirectory*) merged->GetDirectory("ttbar");
    if(ttbar_dir) {
      TH1F* h_ttbar_evt_n = (TH1F*) ttbar_dir->Get("h_ttbar_evt_n");
      tot_ttbar_evt_n = h_ttbar_evt_n->GetEntries();
      scaled_ttbar_evt_n = h_ttbar_evt_n->Integral();      
    }
    
    TDirectory* jetm_dir = (TDirectory*) merged->GetDirectory("jetm");
    if(jetm_dir) {
      TH1F* h_jetm_evt_n = (TH1F*) jetm_dir->Get("h_jetm_evt_n");
      tot_jetm_evt_n = h_jetm_evt_n->GetEntries();
      scaled_jetm_evt_n = h_jetm_evt_n->Integral();      
    }
    
    
  }else{
    merged=0;
  }
}

int wwFileInfo::NumberOfFiles(){
  return nFiles;
}

TObjArray* wwFileInfo::FileList(){
  return fileList;
}

TObjArray* wwFileInfo::PlotsList(){
  return plotList;
}

TObjArray* wwFileInfo::XSecs(){
  return xsecs;
}
  
int wwFileInfo::GetColor(){
  return color;
}

void wwFileInfo::MergeAndWrite(){
  //FIXME, move to?
  /* string merge_name = fname+".root"; */
  /* TFile* merged_file = TFile::Open(merge_name.c_str(),"RECREATE"); */
  /* merged_file->cd(); */

  /* for(int f=0;f<nFiles;f++){ */
  /*   TFile* curFile = (TFile*) fileList->At(f); */
  /*   wwXSec* curXSec = (wwXSec*) xsecs->At(f); */
  /* } */

  
  return;
}

TFile* wwFileInfo::MergedFile(){
  if(merge_loaded){
    return merged;
  }else{
    cout<<"Merged files not loaded"<<endl;
    return 0;
  }
}

string wwFileInfo::GetFileName(){

  return fname;

}

bool wwFileInfo::IsSignal(){
  return is_sig;
}
double wwFileInfo::GetLineWidth(){
  return line_width;
}
int wwFileInfo::GetFillStyle(){
  return fill_style;
}
int wwFileInfo::GetLineStyle(){
  return line_style;
}
string wwFileInfo::GetProcess(){
  return process;
}

string wwFileInfo::GetShortProc(){
  return proc;
}

void wwFileInfo::PrintInfo(){

  //cout<<"wwFileInfo::PrintInfo() for process: "<<this->GetProcess()<<endl;
  cout<<this->GetProcess()<<":"<<endl;
  cout<<"(";
  cout<<"evt_n: "<<scaled_evt_n<<",\t";
  cout<<"sow_n: "<<scaled_sow_n<<",\t";
  cout<<"met_clean_n: "<<scaled_met_clean_n<<",\t";
  cout<<"vxp_sel_n: "<<scaled_vxp_sel_n<<",\t";
  cout<<"trig_n: "<<scaled_trig_n<<",\t";
  cout<<"lep_sel_n: "<<scaled_lep_sel_n<<",\t";  
  cout<<"met_n: "<<scaled_met_n<<",\t";
  cout<<"one_jet: "<<scaled_one_jet_n<<",\t";
  cout<<"full_elec: "<<scaled_full_elec_n<<",\t";
  cout<<"full_muon: "<<scaled_full_muon_n<<")"<<endl;

  
  //cout<<"=\t evt_n \t\t=\t sow_n   \t\t=\t met_clean_n \t\t=\t vxp_sel_n \t\t=\t trig_n \t\t="<<endl;
  /* cout<<"=\t "<<scaled_evt_n<<"\t\t"; */
  /* cout<<"=\t "<<scaled_sow_n<<"\t\t"; */
  /* cout<<"=\t "<<scaled_met_clean_n<<"\t\t"; */
  /* cout<<"=\t "<<scaled_vxp_sel_n<<"\t\t"; */
  /* cout<<"=\t "<<scaled_trig_n<<"\t\t";     */
  /* cout<<"= "<<endl; */
  
  return;

}

double wwFileInfo::TotalNEvents(){
  return tot_evt_n;
}
double wwFileInfo::ScaledNEvents(){
  return scaled_evt_n;
}
double wwFileInfo::TotalNEventsEwk(){
  return tot_ewk_evt_n;
}
double wwFileInfo::TotalNEventsJetM(){
  return tot_jetm_evt_n;
}
double wwFileInfo::TotalNEventsTTBar(){
  return tot_ttbar_evt_n;
}
double wwFileInfo::TotalSumOfWeights(){
  return tot_sow_n;
}

double wwFileInfo::ScaledNEventsEwk(){
  return scaled_ewk_evt_n;
}
double wwFileInfo::ScaledNEventsTTBar(){
  return scaled_ttbar_evt_n;
}
double wwFileInfo::ScaledNEventsJetM(){
  return scaled_jetm_evt_n;
}

double wwFileInfo::ScaledSumOfWeights(){
  return scaled_sow_n;
}
double wwFileInfo::TotalAtLeastOneJetN(){
  return tot_one_jet_n;
}
double wwFileInfo::ScaledAtLeastOneJetN(){
  return scaled_one_jet_n;
}
double wwFileInfo::ScaledMetCleaningN(){
  return scaled_met_clean_n;
}
double wwFileInfo::ScaledVxpSelectionN(){
  return scaled_vxp_sel_n;
}
double wwFileInfo::ScaledTriggerN(){
  return scaled_trig_n;
}
double wwFileInfo::ScaledLeptonSelectionN(){
  return scaled_lep_sel_n;
}
double wwFileInfo::ScaledMetCutN(){
  return scaled_met_n;
}
double wwFileInfo::ScaledOneJetN(){
  return scaled_one_jet_n;
}
double wwFileInfo::ScaledNElectronEvents(){
  return scaled_full_elec_n;
}
double wwFileInfo::ScaledNMuonEvents(){
  return scaled_full_muon_n;
}
