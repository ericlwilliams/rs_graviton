#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <TString.h>
#include "../src/lvjjHelper.h"

using namespace lvjjHelper;

class wwXSec : public TObject {

  int rnum;//106050


  string proc;//sig,bkgd
  string prod_tag;//sig,bkgd
  string sb;
  string rdir;
  double xsec;
  double high_met;
  double eff;
  double kfac;
  double tot_nevts;
  double dpd_nevts;
  double evt_weight;

  // qcd scale stuff
  bool is_vjets;

  bool is_wjets;
  bool use_wjets_sf;
  double wjets_sf;

  bool is_qcd;  
  bool use_qcd_sf;
  double qcd_scale;

  
  // wjets scale stuff
  // derived from ../wjets/wjetsScaleFactor.C('ctrl_wjets')
  // see ../src/controlPlots.C for details on 'ctrl_wjets' (or ctrl_wjets_lowpt) and 'sidebands'
  // wjets scaling comes from low qcd region
  // FIRST scaling in chain (qcd scaling follows)


  bool use_sideband_sf;
  //////////////////////////////////////////////////
  // sideband_low(high)m_sf
  // - to be applied to ctrl_sig and sig regions
  //////////////////////////////////////////////////
  double sideband_lowm_sf;
  double sideband_highm_sf;

  //////////////////////////////////////////////////
  // sideband_low(high)sb_low(high)m_sf
  // - to be applied to sideband regions (for consitency plots)
  //////////////////////////////////////////////////
  double sideband_lowsb_lowm_sf;
  double sideband_highsb_lowm_sf;
  double sideband_lowsb_highm_sf;
  double sideband_highsb_highm_sf;


  
  //boosted w+jets scale stuff: NOT USED ANYMORE
  float boost_elec_sf;
  float boost_muon_sf;  
  double boost_sf;
  
 public:
  wwXSec(TString runNum);
  
  int RunNum();
  string RunDir();
  string SigOrBkgd();
  //double Nexp(double invPB,bool isSigCtrl,bool isLowM);
  double Nevt();//returns number of expected events for given integrated luminosity.
  double GenNevt();//returns number of expected events for given integrated luminosity.  
  string Proc();
  string ProductionTag();
  double HighMET();
  double Efficiency();
  double Filter_Efficiency();
  double Scale();
  double Sow();
  double GetScale(float lumi, string hist_name,bool is_sys);
  double GetLocalScale(float lumi,float local_sf,string hist_name,bool is_sys);
  double XSec();
  double KFactor();
  double Nexp(double invPB,string hist_name,bool is_sys);//returns number of expected events for given integrated luminosity.
  bool IsQCD();
  bool IsWJets();
  bool IsVJets();
  bool DoScale(); 
};

wwXSec::wwXSec(TString runNumStr){

  rdir = runNumStr;

  //////////////////////////////////////////////////
  // SET SCALING
  ////////////////////////////////////////////////// 
  use_wjets_sf=false; // inclusive scaling
  //use_qcd_sf=true; // inclusive scaling
  use_qcd_sf = (bool) qcdHelper::useQCDScale;
  use_sideband_sf= (bool) lvjjHelper::useSidebandScale; // signal region scaling (from sidebands), ALSO SCALES SIDEBANDS!


  // is_wjets: DON'T CHANGE. default is false, assigned dbelow
  is_wjets=false;
  is_vjets=false; 
  
  //Default Scale Factors 
  wjets_sf=1.;

  // scale factors from wjets/wjetsScaleFactors.C
  /* double wjets_alpgen_elec_sf = (!use_wjets_sf) ? 1. : 0.810116; */
  /* double wjets_sherpa_elec_sf = (!use_wjets_sf) ? 1. : 0.897609; */
  /* double wjets_alpgen_muon_sf = (!use_wjets_sf) ? 1. : 0.812428; */
  /* double wjets_sherpa_muon_sf = (!use_wjets_sf) ? 1. : 0.95702; */

  // Jet pt threshold -> 40
  /* double wjets_alpgen_elec_sf = (!use_wjets_sf) ? 1. : 0.802; */
  /* double wjets_alpgen_muon_sf = (!use_wjets_sf) ? 1. : 0.753; */

  double wjets_alpgen_elec_sf = (!use_wjets_sf) ? 1. : 0.933;
  double wjets_alpgen_muon_sf = (!use_wjets_sf) ? 1. : 1.040;
  
  double wjets_sherpa_elec_sf = (!use_wjets_sf) ? 1. : 0.897609;
  double wjets_sherpa_muon_sf = (!use_wjets_sf) ? 1. : 0.95702;


  //////////////////////////////////////////////////
  // QCD
  //////////////////////////////////////////////////
  
  // is_qcd: DON'T CHANGE. default is false, change dbelow
  is_qcd=false; 

  // Default QCD Scale: 
  qcd_scale=1.;

  // set QCD scale factors here
  // derived in qcd/runFractionFit.C
  // applied for each sample below, see qcd/logs/qcd_sf.csv


  /* /\* /\\* 1fb-1 unblind *\\/ *\/ */
  /* double qcd_alpgen_elec_sf = (!use_qcd_sf) ? 1. : 0.0905455; */
  /* double qcd_alpgen_muon_sf = (!use_qcd_sf) ? 1. : 0.0910775; */
  /* double vjets_qcd_alpgen_elec_sf = (!use_qcd_sf) ? 1. : 1.10014; */
  /* double vjets_qcd_alpgen_muon_sf = (!use_qcd_sf) ? 1. : 1.08642; */

  /* /\* /\\* // lep_met_mt , 5fb  *\\/ *\/ */
  /* double qcd_alpgen_elec_sf = (!use_qcd_sf) ? 1. : 0.42728; */
  /* double qcd_alpgen_muon_sf = (!use_qcd_sf) ? 1. : 0.461241; */
  /* double vjets_qcd_alpgen_elec_sf = (!use_qcd_sf) ? 1. : 1.1127; */
  /* double vjets_qcd_alpgen_muon_sf = (!use_qcd_sf) ? 1. : 1.08842; */

  /* /\* /\\* // lep_met_mt , 5fb  *\\/ *\/ */
  float qcd_alpgen_elec_sf = qcdHelper::elec_qcd_sf;
  float qcd_alpgen_muon_sf = qcdHelper::muon_qcd_sf;
  float vjets_qcd_alpgen_elec_sf = qcdHelper::elec_vjets_sf;
  float vjets_qcd_alpgen_muon_sf = qcdHelper::muon_vjets_sf;

  /* /\* /\\* // lep_met_mt_eq2j , 5fb  *\\/ *\/ */
  /* double qcd_alpgen_elec_sf = (!use_qcd_sf) ? 1. : 0.48586; */
  /* double qcd_alpgen_muon_sf = (!use_qcd_sf) ? 1. : 0.493187; */
  /* double vjets_qcd_alpgen_elec_sf = (!use_qcd_sf) ? 1. : 1.12289; */
  /* double vjets_qcd_alpgen_muon_sf = (!use_qcd_sf) ? 1. : 1.09716; */

  /* /\* /\\* // lep_met_mt_gt2j , 5fb  *\\/ *\/ */
  /* double qcd_alpgen_elec_sf = (!use_qcd_sf) ? 1. : 0.363631; */
  /* double qcd_alpgen_muon_sf = (!use_qcd_sf) ? 1. : 0.493187; */
  /* double vjets_qcd_alpgen_elec_sf = (!use_qcd_sf) ? 1. : 1.10597; */
  /* double vjets_qcd_alpgen_muon_sf = (!use_qcd_sf) ? 1. : 1.09716; */

  /* /\* /\\* // lep_pt , 5fb  *\\/ *\/ */
  /* double qcd_alpgen_elec_sf = (!use_qcd_sf) ? 1. : 0.74038; */
  /* double qcd_alpgen_muon_sf = (!use_qcd_sf) ? 1. : 0.493187; */
  /* double vjets_qcd_alpgen_elec_sf = (!use_qcd_sf) ? 1. : 1.00511; */
  /* double vjets_qcd_alpgen_muon_sf = (!use_qcd_sf) ? 1. : 1.09716; */

  /* /\* // met , 5fb  *\/ */
  /* double qcd_alpgen_elec_sf = (!use_qcd_sf) ? 1. : 0.794485; */
  /* double qcd_alpgen_muon_sf = (!use_qcd_sf) ? 1. : 0.493187; */
  /* double vjets_qcd_alpgen_elec_sf = (!use_qcd_sf) ? 1. : 0.985924; */
  /* double vjets_qcd_alpgen_muon_sf = (!use_qcd_sf) ? 1. : 1.09716; */


  double qcd_sherpa_elec_sf = (!use_qcd_sf) ? 1. : 0.232302;
  double qcd_sherpa_muon_sf = (!use_qcd_sf) ? 1. : 0.559759;
  double vjets_qcd_sherpa_elec_sf = (!use_qcd_sf) ? 1. : 1.39784;
  double vjets_qcd_sherpa_muon_sf = (!use_qcd_sf) ? 1. : 1.33636;

  double qcd_pythia_elec_sf = (!use_qcd_sf) ? 1. : 0.847954;
  double qcd_pythia_muon_sf = (!use_qcd_sf) ? 1. : 0.527247;
  double vjets_qcd_pythia_elec_sf = (!use_qcd_sf) ? 1. : 1.0;
  double vjets_qcd_pythia_muon_sf = (!use_qcd_sf) ? 1. : 1.0;


  
  sideband_lowm_sf=1.;
  sideband_highm_sf=1.;

  sideband_lowsb_lowm_sf=1.;
  sideband_highsb_lowm_sf=1.;
  sideband_lowsb_highm_sf=1.;
  sideband_highsb_highm_sf=1.;

  //////////////////////////////////////////////////
  // Sideband scale factors from lnuj/wjets/wjetsScaleFactors.C
  ////////////////////////////////////////////////// 
    
  // lowsb_lowm
  double sideband_alpgen_comb_lowsb_lowm_sf =
    (!use_sideband_sf) ? 1. : 0.985;
  double sideband_sherpa_comb_lowsb_lowm_sf =
    (!use_sideband_sf) ? 1. : 0.985;

  // highsb_lowm
  double sideband_alpgen_comb_highsb_lowm_sf =
    (!use_sideband_sf) ? 1. : 0.928;
  double sideband_sherpa_comb_highsb_lowm_sf =
    (!use_sideband_sf) ? 1. : 0.928;

  // lowm, weighted averages
  double sideband_alpgen_comb_lowm_sf =
    (!use_sideband_sf) ? 1. : 0.774;
  
  double sideband_sherpa_comb_lowm_sf =
    (!use_sideband_sf) ? 1. : 0.732;

  //////////////////////////////////////////////////
  // highm 
  //////////////////////////////////////////////////
  
  // lowsb_highm -> from wjets/logs/vjets_lowsb_highm_sf.csv, produced from wjetsScaleFactors.C
  double sideband_alpgen_comb_lowsb_highm_sf =
    (!use_sideband_sf) ? 1. : 1.174;//met>40
  double sideband_sherpa_comb_lowsb_highm_sf =
    (!use_sideband_sf) ? 1. : 0.661;

  // highsb_highm -> from wjets/logs/vjets_highsb_highm_sf.csv, produced from wjetsScaleFactors.C
  double sideband_alpgen_comb_highsb_highm_sf =
    (!use_sideband_sf) ? 1. : 1.015; //met>40

  double sideband_sherpa_comb_highsb_highm_sf =
    (!use_sideband_sf) ? 1. : 0.985;// 1fb-1 unblind


  //////////////////////////////////////////////////
  // highm, weighted averages -> from wjets/logs/vjets_avg_sf.csv, produced from wjetsScaleFactors.C
  //////////////////////////////////////////////////

  double sideband_alpgen_comb_highm_sf = (!use_sideband_sf) ?
    1. : lvjjHelper::avg_alpgen_comb_sf;
  //(!use_sideband_sf) ? 1. : 1.012;//008;
  //(!use_sideband_sf) ? 1. : 0.783;//no Wpt reweighting  

  double sideband_sherpa_comb_highm_sf =
    (!use_sideband_sf) ? 1. : 0.978;


    
  // set Alpgen/Sherpa Low/High Mass SFs here, propigated to samples below
  // scale factors from wjets/wjetsScaleFactors.C
  // Weighted averages
  
  // lowm
  double sideband_alpgen_elec_lowm_sf =
    (!use_sideband_sf) ? 1. :
    ((sideband_alpgen_comb_lowsb_lowm_sf+sideband_alpgen_comb_highsb_lowm_sf)/2);
  
  double sideband_sherpa_elec_lowm_sf =
    (!use_sideband_sf) ? 1. : 
    ((sideband_sherpa_comb_lowsb_lowm_sf+sideband_sherpa_comb_highsb_lowm_sf)/2);
  
  double sideband_alpgen_muon_lowm_sf =
    (!use_sideband_sf) ? 1. :
    ((sideband_alpgen_comb_lowsb_lowm_sf+sideband_alpgen_comb_highsb_lowm_sf)/2);;
  double sideband_sherpa_muon_lowm_sf =
    (!use_sideband_sf) ? 1. : 
    ((sideband_sherpa_comb_lowsb_lowm_sf+sideband_sherpa_comb_highsb_lowm_sf)/2);



  //////////////////////////////////////////////////
  // boost, applied but NOT IMPLEMENTED anymore
  ////////////////////////////////////////////////// 
  boost_elec_sf=0.602178;
  boost_muon_sf=0.699396;
  

  boost_sf=1.;
  TString runNum = runNumStr;
  
  if(runNum=="data.periodAI2.ww2lep"){

    sb = "sig";
    proc = "data";
    prod_tag="e906";
    xsec = 1;//7TeV, mc09, e521_s765_s767_r1207_r1210
    rnum = 1;
    high_met=150;
    tot_nevts=-1;
    dpd_nevts=-1;//valid
    evt_weight=1;
    kfac=1.;
    eff = 1.;


    
  }else if(runNum=="mc.afii.kkg.m300.pu"){
    rnum = 145607;
    sb = "sig";
    proc = "G->WW->lvjj";
    prod_tag="e1131";
    xsec = 34.23;
    high_met=150;
    tot_nevts=15000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=14995.3;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.fs.kkg.m300.pu"){
    rnum = 145607;
    sb = "sig";
    proc = "G->WW->lvjj (FS)";
    prod_tag="e1131";
    xsec = 34.23;
    high_met=150;
    tot_nevts=15000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=14996;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.fs.kkg.m900.pu"){
    rnum = 145613;
    sb = "sig";
    proc = "G->WW->lvjj (FS)";
    prod_tag="e1131";
    xsec = 0.03465;
    high_met=150;
    tot_nevts=15000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=14996;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.fs.kkg.m1500.pu"){
    rnum = 145613;
    sb = "sig";
    proc = "G->WW->lvjj (FS)";
    prod_tag="e1131";
    xsec = 0.000899;
    high_met=150;
    tot_nevts=15000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=14996;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.afii.kkg.lvjj.m500.pu"){
    rnum = 145609;
    sb = "sig";
    proc = "G^{*}_{\\rm{bulk}} \\rightarrow WW \\rightarrow \\ell\\nu jj $\\\\$ (M=500~\\rm{GeV})";
    prod_tag="e1131";
    xsec = 1.559;
    high_met=150;
    tot_nevts=15000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=14995.3;
    kfac=1;
    eff=0.796;
    //eff=1;

  }else if(runNum=="mc.afii.kkg.lvjj.m600.pu"){
    rnum = 145610;
    sb = "sig";
    proc = "G^{*}_{\\rm{bulk}} \\rightarrow WW \\rightarrow \\ell\\nu jj $\\\\$ (M=600~\\rm{GeV})";
    prod_tag="e1131";
    xsec = 0.4751;
    high_met=150;
    tot_nevts=15000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=14995.3;
    kfac=1;
    eff= 0.794;
    //eff= 1;

  }else if(runNum=="mc.afii.kkg.lvjj.m700.pu"){
    rnum = 145611;
    sb = "sig";
    proc = "G^{*}_{\\rm{bulk}} \\rightarrow WW \\rightarrow \\ell\\nu jj $\\\\$ (M=700~\\rm{GeV})";
    prod_tag="e1131";
    xsec = 0.1767;
    high_met=150;
    tot_nevts=15000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=14995.3;
    kfac=1;
    eff=0.795;
    //eff=1;

  }else if(runNum=="mc.afii.kkg.lvjj.m800.pu"){
    rnum = 145612;
    sb = "sig";
    proc = "G^{*}_{\\rm{bulk}} \\rightarrow WW \\rightarrow \\ell\\nu jj $\\\\$ (M=800~\\rm{GeV})";
    prod_tag="e1131";
    xsec = 0.07478;
    high_met=150;
    tot_nevts=15000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=14995.3;
    kfac=1;
    eff=0.804;
    //eff=1;

  }else if(runNum=="mc.afii.kkg.lvjj.m900.pu"){
    rnum = 145613;
    sb = "sig";
    proc = "G^{*}_{\\rm{bulk}} \\rightarrow WW \\rightarrow \\ell\\nu jj $\\\\$ (M=900~\\rm{GeV})";
    prod_tag="e1131";
    xsec = 0.03465;
    high_met=150;
    tot_nevts=15000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=14995.3;
    kfac=1;
    eff=0.799;
    //eff=1;

  }else if(runNum=="mc.afii.kkg.lvjj.m1000.pu"){
    rnum = 145614;
    sb = "sig";
    proc = "G^{*}_{\\rm{bulk}} \\rightarrow WW \\rightarrow \\ell\\nu jj $\\\\$ (M=1000~\\rm{GeV})";
    prod_tag="e1131";
    xsec = 0.01713;
    high_met=150;
    tot_nevts=15000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=14995.3;
    kfac=1;
    eff=0.811;
    //eff=1;

  }else if(runNum=="mc.afii.kkg.lvjj.m1100.pu"){
    rnum = 145615;
    sb = "sig";
    proc = "G^{*}_{\\rm{bulk}} \\rightarrow WW \\rightarrow \\ell\\nu jj $\\\\$ (M=1100~\\rm{GeV})";
    prod_tag="e1131";
    xsec = 0.008906;
    high_met=150;
    tot_nevts=15000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=14995.3;
    kfac=1;
    eff=0.8;
    //eff=1;

  }else if(runNum=="mc.afii.kkg.lvjj.m1200.pu"){
    rnum = 145616;
    sb = "sig";
    proc = "G^{*}_{\\rm{bulk}} \\rightarrow WW \\rightarrow \\ell\\nu jj $\\\\$ (M=1200~\\rm{GeV})";
    prod_tag="e1131";
    xsec = 0.004813;
    high_met=150;
    tot_nevts=15000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=14995.3;
    kfac=1;
    eff=0.8;
    //eff=1;

  }else if(runNum=="mc.afii.kkg.lvjj.m1300.pu"){
    rnum = 145617;
    sb = "sig";
    proc = "G^{*}_{\\rm{bulk}} \\rightarrow WW \\rightarrow \\ell\\nu jj $\\\\$ (M=1300~\\rm{GeV})";
    prod_tag="e1131";
    xsec = 0.002685;
    high_met=150;
    tot_nevts=15000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=14995.3;
    kfac=1;
    eff=0.8;
    //eff=1;

  }else if(runNum=="mc.afii.kkg.lvjj.m1400.pu"){
    rnum = 145618;
    sb = "sig";
    proc = "G^{*}_{\\rm{bulk}} \\rightarrow WW \\rightarrow \\ell\\nu jj $\\\\$ (M=1400~\\rm{GeV})";
    prod_tag="e1131";
    xsec = 0.001538;
    high_met=150;
    tot_nevts=15000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=14995.3;
    kfac=1;
    eff=0.8;
    //eff=1;
  }else if(runNum=="mc.afii.kkg.lvjj.m1500.pu"){
    rnum = 145619;
    sb = "sig";
    proc = "G^{*}_{\\rm{bulk}} \\rightarrow WW \\rightarrow \\ell\\nu jj $\\\\$ (M=1500~\\rm{GeV})";
    prod_tag="e1131";
    xsec = 0.000899;
    high_met=150;
    tot_nevts=15000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=14995.3;
    kfac=1;
    eff=0.814;
    //eff=1;

  }else if(runNum=="mc.gww.lvjj.m200.kmpl0_1.pu"){
    rnum = 115722;
    sb = "sig";
    proc = "G->WW->lvjj (mG=200,kMpl=0.1)";
    prod_tag="e906";
    //xsec = 452.2;
    xsec = 436;
    high_met=150;
    tot_nevts=29992;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=29891.;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.gww.lvjj.m350.kmpl0_1.pu"){
    rnum = 115723;
    sb = "sig";
    proc = "G->WW->lvjj (mG=350,kMpl=0.1)";
    //xsec = 37.1;
    prod_tag="e906";
    //xsec = 36.28;
    xsec = 35.3;
    high_met=150;
    tot_nevts=29986;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=29899.;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.gww.lvjj.m500.kmpl0_1.pu"){
    rnum = 115724;
    sb = "sig";
    proc = "G^{*} \\rightarrow WW \\rightarrow \\ell\\nu jj $\\\\$ (M=500~\\rm{GeV}; k/\\overline{M}_{pl}=0.1)";
    //proc = "G->WW->lvjj (mG=500,kMpl=0.1)";
    //xsec = 5.73;
    prod_tag="e972";
    //xsec = 5.593;
    xsec = 5.56;
    high_met=150;
    tot_nevts=30000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=29996.91;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.gww.lvjj.m750.kmpl0_1.pu"){
    rnum = 115725;
    sb = "sig";
    proc = "G^{*} \\rightarrow WW \\rightarrow \\ell\\nu jj $\\\\$ (M=750~\\rm{GeV}; k/\\overline{M}_{pl}=0.1)";
    //xsec = 0.615;
    prod_tag="e972";
    //xsec = 0.614;
    xsec = 0.56;
    high_met=150;
    tot_nevts=30000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=29996.47;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.gww.lvjj.m1000.kmpl0_1.pu"){
    rnum = 115726;
    sb = "sig";
    proc = "G^{*} \\rightarrow WW \\rightarrow \\ell\\nu jj $\\\\$ (M=1000~\\rm{GeV}; k/\\overline{M}_{pl}=0.1)";
    //xsec = 0.114;
    prod_tag="e972";
    //xsec = 0.112;
    xsec = 0.1;
    high_met=150;
    tot_nevts=30000; 
    dpd_nevts=tot_nevts;//valid2
    evt_weight=29996.55;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.gww.lvjj.m1250.kmpl0_1.pu"){
    rnum = 115727;
    sb = "sig";
    proc = "G^{*} \\rightarrow WW \\rightarrow \\ell\\nu jj $\\\\$ (M=1250~\\rm{GeV}; k/\\overline{M}_{pl}=0.1)";
    //xsec = 0.0259;
    prod_tag="e972";
    //xsec = 0.027;
    xsec = 0.026;
    high_met=150;
    tot_nevts=30000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=29996.62;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.gww.lvjj.m1500.kmpl0_1.pu"){
    rnum = 115728;
    sb = "sig";
    proc = "G^{*} \\rightarrow WW \\rightarrow \\ell\\nu jj $\\\\$ (M=1500~\\rm{GeV}; k/\\overline{M}_{pl}=0.1)";
    //xsec = 0.00732;
    prod_tag="e972";
    //xsec = 0.0077;
    xsec = 0.0074;
    high_met=150;
    //tot_nevts=29931;
    tot_nevts=30000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=29996.21;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.gzz.lljj.m500.kmpl0_1.pu"){
    rnum = 115724;
    sb = "sig";
    proc = "G->ZZ->lljj (mG=500,kMpl=0.1)";
    prod_tag="e972";
    xsec = 0.8807874;
    high_met=150;
    tot_nevts=29900;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=29866.7;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.gzz.lljj.m750.kmpl0_1.pu"){
    rnum = 115725;
    sb = "sig";
    proc = "G->ZZ->lljj (mG=750,kMpl=0.1)";
    //xsec = 0.614;
    prod_tag="e972";
    xsec = 0.096693;
    high_met=150;
    tot_nevts=29999.0;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=29995.69;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.gzz.lljj.m1000.kmpl0_1.pu"){
    rnum = 115726;
    sb = "sig";
    proc = "G->ZZ->lljj (mG=1000,kMpl=0.1)";
    //xsec = 0.112;
    prod_tag="e972";
    xsec = 0.0176378;
    high_met=150;
    tot_nevts=30000.0;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=29996.59;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.gzz.lljj.m1250.kmpl0_1.pu"){
    rnum = 115727;
    sb = "sig";
    proc = "G->ZZ->lljj (mG=1250,kMpl=0.1)";
    //xsec = 0.027;
    prod_tag="e972";
    xsec = 0.00425197;
    high_met=150;
    tot_nevts=30000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=29996.08;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.gzz.lljj.m1500.kmpl0_1.pu"){
    rnum = 115728;
    sb = "sig";
    proc = "G->ZZ->lljj (mG=1500,kMpl=0.1)";
    //xsec = 0.0077;
    prod_tag="e972";
    xsec = 0.001212598;
    high_met=150;
    //tot_nevts=29931;
    tot_nevts=30000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=29996.56;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.gww.lvjj.m200.kmpl0_01.pu"){
    rnum = 115729;
    sb = "sig";
    proc = "G->WW->lvjj (mG=200,kMpl=0.01)";
    prod_tag="e972";
    xsec = 4.53;
    high_met=150;
    tot_nevts=29984;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=29894.1;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.gww.lvjj.m350.kmpl0_01.pu"){
    rnum = 115730;
    sb = "sig";
    proc = "G->WW->lvjj (mG=350,kMpl=0.01)";
    prod_tag="e972";
    xsec = 0.371;
    high_met=150;
    tot_nevts=29987;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=29886.7;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.gww.lvjj.m500.kmpl0_01.pu"){
    rnum = 115731;
    sb = "sig";
    proc = "G->WW->lvjj (mG=500,kMpl=0.01)";
    prod_tag="e972";
    xsec = 0.0573;
    high_met=150;
    tot_nevts=29970;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=28556.5;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.gww.lvjj.m750.kmpl0_01.pu"){
    rnum = 115732;
    sb = "sig";
    proc = "G->WW->lvjj (mG=750,kMpl=0.01)";
    prod_tag="e972";
    xsec = 0.00615;
    high_met=150;
    tot_nevts=29959;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=29865.4;
    kfac=1;
    eff= 1;


  }else if(runNum=="mc.wprime.wz.lvqq.m500.pu"){
    rnum = 105708;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow \\ell\\nu jj $\\\\$ (M_{W'}=500~\\rm{GeV})";
    //xsec = 0.654;
    //xsec = 0.441;
    prod_tag="e972";
    xsec = 1.2;
    high_met=150;
    tot_nevts=10000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=9995.94;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.wprime.wz.lvqq.m600.pu"){
    rnum = 115640;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow \\ell\\nu jj $\\\\$ (M_{W'}=600~\\rm{GeV})";
    prod_tag="e972";
    xsec = 0.55;
    //xsec = 0.196;
    high_met=150;
    tot_nevts=10000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=9999.54;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.wprime.wz.lvqq.m700.pu"){
    rnum = 115641;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow \\ell\\nu jj $\\\\$ (M_{W'}=700~\\rm{GeV})";
    //xsec = 0.167;
    //xsec = 0.098;
    prod_tag="e972";
    xsec = 0.27;
    high_met=150;
    tot_nevts=10000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=9991.13;
    kfac=1;
    eff= 1;


  }else if(runNum=="mc.wprime.wz.lvqq.m800.pu"){
    rnum = 115642;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow \\ell\\nu jj $\\\\$ (M_{W'}=800~\\rm{GeV})";
    //xsec = 0.053;
    prod_tag="e1006";
    xsec = 0.15;
    high_met=150;
    tot_nevts=10000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=9997.91;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.wprime.wz.lvqq.m900.pu"){
    rnum = 115643;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow \\ell\\nu jj $\\\\$ (M_{W'}=900~\\rm{GeV})";
    //xsec = 0.030;
    prod_tag="e1006";
    xsec = 0.082;
    high_met=150;
    tot_nevts=10000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=9997.97;
    kfac=1;
    eff= 1;

    
  }else if(runNum=="mc.wprime.wz.lvqq.m1000.pu"){
    rnum = 105709;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow \\ell\\nu jj $\\\\$ (M_{W'}=1000~\\rm{GeV})";
    //xsec = 0.018;
    prod_tag="e1006";
    xsec = 0.048;
    high_met=150;
    tot_nevts=10000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=9999.29;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.wprime.wz.lvqq.m1100.pu"){
    rnum = 115644;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow \\ell\\nu jj $\\\\$ (M_{W'}=1100~\\rm{GeV})";
    //xsec = 0.011;
    prod_tag="e1006";
    xsec = 0.03;
    high_met=150;
    tot_nevts=10000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=9996.16;
    kfac=1;
    eff= 1;


  }else if(runNum=="mc.wprime.wz.lvqq.m1200.pu"){
    rnum = 115645;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow \\ell\\nu jj $\\\\$ (M_{W'}=1200~\\rm{GeV})";
    //xsec = 0.007;
    prod_tag="e1006";
    xsec = 0.019;
    high_met=150;
    tot_nevts=10000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=9992.55;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.wprime.wz.lvqq.m1300.pu"){
    rnum = 115646;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow \\ell\\nu jj $\\\\$ (M_{W'}=1300~\\rm{GeV})";
    //xsec = 0.0045;
    prod_tag="e1006";
    xsec = 0.012;
    high_met=150;
    tot_nevts=10000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=9997.71;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.wprime.wz.lvqq.m1400.pu"){
    rnum = 115647;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow \\ell\\nu jj $\\\\$ (M_{W'}=1400~\\rm{GeV})";
    //xsec = 0.0029;
    prod_tag="e1006";
    xsec = 0.008;
    high_met=150;
    tot_nevts=10000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=9992.13;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.wprime.wz.lvqq.m1500.pu"){
    rnum = 105710;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow \\ell\\nu jj $\\\\$ (M_{W'}=1500~\\rm{GeV})";
    //xsec = 0.0019;
    prod_tag="e1006";
    xsec = 0.0053;
    high_met=150;
    tot_nevts=10000;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=9997.59;
    kfac=1;
    eff= 1;


  }else if(runNum=="mc.wprime.wz.qqee.m500.pu"){
    rnum = 115622;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow ee jj $\\\\$ (M_{W'}=500~\\rm{GeV})";
    prod_tag="e972";
    xsec = 1.15/11.5;
    high_met=150;
    //tot_nevts=9996;
    tot_nevts=10000.0;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=9998.86;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.wprime.wz.qqee.m600.pu"){
    rnum = 115623;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow ee jj $\\\\$ (M_{W'}=600~\\rm{GeV})";
    prod_tag="e972";
    xsec = 0.538/11.5;
    high_met=150;
    tot_nevts=10000.0;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=9959.54;
    evt_weight=9999.01;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.wprime.wz.qqee.m700.pu"){
    rnum = 115624;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow ee jj $\\\\$ (M_{W'}=700~\\rm{GeV})";
    prod_tag="e972";
    xsec = 0.262/11.5;
    high_met=150;
    //tot_nevts=9996;
    tot_nevts=9998.0;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=9961.13;
    evt_weight=9996.93;
    kfac=1;
    eff= 1;


  }else if(runNum=="mc.wprime.wz.qqee.m800.pu"){
    rnum = 115625;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow ee jj $\\\\$ (M_{W'}=800~\\rm{GeV})";
    //xsec = 0.053;
    prod_tag="e972";
    xsec = 0.144/11.5;
    high_met=150;
    //tot_nevts=9990;
    tot_nevts=10000.0;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=9957.91;
    evt_weight=9998.83;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.wprime.wz.qqee.m900.pu"){
    rnum = 115626;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow ee jj $\\\\$ (M_{W'}=900~\\rm{GeV})";
    //xsec = 0.030;
    prod_tag="e972";
    xsec = 0.0825/11.5;
    high_met=150;
    //tot_nevts=9994;
    tot_nevts=9998.0;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=9957.97;
    evt_weight=9997.05;
    kfac=1;
    eff= 1;


  }else if(runNum=="mc.wprime.wz.qqee.m1100.pu"){
    rnum = 115627;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow ee jj $\\\\$ (M_{W'}=1100~\\rm{GeV})";
    //xsec = 0.011;
    prod_tag="e972";
    xsec = 0.02971/11.5;
    high_met=150;
    //tot_nevts=9982;
    tot_nevts=9998.0;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=9956.16;
    evt_weight=9997.22;
    kfac=1;
    eff= 1;


  }else if(runNum=="mc.wprime.wz.qqee.m1200.pu"){
    rnum = 115628;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow ee jj $\\\\$ (M_{W'}=1200~\\rm{GeV})";
    //xsec = 0.007;
    prod_tag="e972";
    xsec = 0.0188/11.5;
    high_met=150;
    //tot_nevts=9991;
    tot_nevts=10000.0;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=9962.55;
    evt_weight=9998.84;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.wprime.wz.qqee.m1300.pu"){
    rnum = 115629;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow ee jj $\\\\$ (M_{W'}=1300~\\rm{GeV})";
    //xsec = 0.0045;
    prod_tag="e972";
    xsec = 0.01159/11.5;
    high_met=150;
    //tot_nevts=9987;
    tot_nevts=10000.0;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=9957.71;
    evt_weight=9998.83;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.wprime.wz.qqee.m1400.pu"){
    rnum = 115630;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow ee jj $\\\\$ (M_{W'}=1400~\\rm{GeV})";
    //xsec = 0.0029;
    prod_tag="e972";
    xsec = 0.007775/11.5;
    high_met=150;
    //tot_nevts=9982;
    tot_nevts=10000.0;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=9932.13;
    evt_weight=9998.87;
    kfac=1;
    eff= 1;
    
  }else if(runNum=="mc.wprime.wz.qquu.m500.pu"){
    rnum = 115631;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow \\mu\\mu jj $\\\\$ (M_{W'}=500~\\rm{GeV})";
    prod_tag="e972";
    xsec = 1.15/11.5;
    high_met=150;
    //tot_nevts=9996;
    tot_nevts=10000.0;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=9965.94;
    evt_weight=9998.82;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.wprime.wz.qquu.m600.pu"){
    rnum = 115632;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow \\mu\\mu jj $\\\\$ (M_{W'}=600~\\rm{GeV})";
    prod_tag="e972";
    xsec = 0.538/11.5;
    //xsec = 0.196;
    high_met=150;
    //tot_nevts=9993;
    tot_nevts=10000.0;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=9959.54;
    evt_weight=9998.82;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.wprime.wz.qquu.m700.pu"){
    rnum = 115633;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow \\mu\\mu jj $\\\\$ (M_{W'}=700~\\rm{GeV})";
    //xsec = 0.167;
    //xsec = 0.098;
    prod_tag="e972";
    xsec = 0.262/11.5;
    high_met=150;
    //tot_nevts=9996;
    tot_nevts=10000.0;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=9961.13;
    evt_weight=9998.87;
    kfac=1;
    eff= 1;


  }else if(runNum=="mc.wprime.wz.qquu.m800.pu"){
    rnum = 115634;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow \\mu\\mu jj $\\\\$ (M_{W'}=800~\\rm{GeV})";
    //xsec = 0.053;
    prod_tag="e972";
    xsec = 0.144/11.5;
    high_met=150;
    //tot_nevts=9990;
    tot_nevts=10000.0;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=9957.91;
    evt_weight=9999.01;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.wprime.wz.qquu.m900.pu"){
    rnum = 115635;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow \\mu\\mu jj $\\\\$ (M_{W'}=900~\\rm{GeV})";
    //xsec = 0.030;
    prod_tag="e972";
    xsec = 0.0825/11.5;
    high_met=150;
    //tot_nevts=9994;
    tot_nevts=10000.0;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=9957.97;
    evt_weight=9999.05;
    kfac=1;
    eff= 1;


  }else if(runNum=="mc.wprime.wz.qquu.m1100.pu"){
    rnum = 115636;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow \\mu\\mu jj $\\\\$ (M_{W'}=1100~\\rm{GeV})";
    //xsec = 0.011;
    prod_tag="e972";
    xsec = 0.02971/11.5;
    high_met=150;
    //tot_nevts=9982;
    tot_nevts=10000.0;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=9956.16;
    evt_weight=9998.86;
    kfac=1;
    eff= 1;


  }else if(runNum=="mc.wprime.wz.qquu.m1200.pu"){
    rnum = 115637;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow \\mu\\mu jj $\\\\$ (M_{W'}=1200~\\rm{GeV})";
    //xsec = 0.007;
    prod_tag="e972";
    xsec = 0.0188/11.5;
    high_met=150;
    //tot_nevts=9991;
    tot_nevts=10000.0;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=9962.55;
    evt_weight=9998.83;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.wprime.wz.qquu.m1300.pu"){
    rnum = 115638;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow \\mu\\mu jj $\\\\$ (M_{W'}=1300~\\rm{GeV})";
    //xsec = 0.0045;
    prod_tag="e972";
    xsec = 0.01159/11.5;
    high_met=150;
    //tot_nevts=9987;
    tot_nevts=10000.0;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=9957.71;
    evt_weight=9998.86;
    kfac=1;
    eff= 1;

  }else if(runNum=="mc.wprime.wz.qquu.m1400.pu"){
    rnum = 115639;
    sb = "sig";
    proc = "W^{'} \\rightarrow WZ \\rightarrow \\mu\\mu jj $\\\\$ (M_{W'}=1400~\\rm{GeV})";
    //xsec = 0.0029;
    prod_tag="e972";
    xsec = 0.007775/11.5;
    high_met=150;
    //tot_nevts=9982;
    tot_nevts=10000.0;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=9932.13;
    evt_weight=9998.82;
    kfac=1;
    eff= 1;
    
    //////////////////////////////////////////////////
    // Add mc.gww....kmpl0_01 AND mc.wprime.wz...
    //////////////////////////////////////////////////
    

  }else if(runNum=="mc.gww.lvlv.m500.pu"){
    rnum = 100001;
    sb = "sig";
    proc = "G->WW->lvlv (mG=500)";
    prod_tag="e906";
    xsec = 5.693;
    high_met=150;
    tot_nevts=7709;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=-1;
    kfac=1.3;
    eff= 0.95;

  }else if(runNum=="mc.gww.lvlv.m750.pu"){
    rnum = 100002;
    sb = "sig";
    proc = "G->WW->lvlv (mG=750)";
    prod_tag="e906";
    xsec = .6145;
    high_met=150;
    tot_nevts=7381;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=-1;
    kfac=1.3;
    eff= 0.95;

  }else if(runNum=="mc.gww.lvlv.m1000.pu"){
    rnum = 100003;
    sb = "sig";
    proc = "G->WW->lvlv (mG=1000)";
    prod_tag="e906";
    xsec = .111;
    high_met=150;
    tot_nevts=7267;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=-1;
    kfac=1.3;
    eff= 0.95;

  }else if(runNum=="mc.gww.lvlv.m1250.pu"){
    rnum = 100004;
    sb = "sig";
    proc = "G->WW->lvlv (mG=1250)";
    prod_tag="e906";
    xsec = .0256;
    high_met=150;
    tot_nevts=7579;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=-1;
    kfac=1.3;
    eff= 0.95;

    
  }else if(runNum=="qcd.elec.alpgen.pu"){
    rnum = 111111;
    sb = "bkgd";
    proc = "qcd (elec)";
    prod_tag="e906";
    xsec = 0.0;
    high_met=150;
    tot_nevts=-1;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=-1;
    kfac=1;
    eff= 1;
    is_qcd=true;
    qcd_scale = qcd_alpgen_elec_sf; //set above

  }else if(runNum=="qcd.muon.alpgen.pu"){
    rnum = 111112;
    sb = "bkgd";
    proc = "qcd (muon)";
    prod_tag="e906";
    xsec = 0.0;
    high_met=150;
    tot_nevts=-1;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=-1;
    kfac=1;
    eff= 1;
    is_qcd=true;
    qcd_scale = qcd_alpgen_muon_sf; //set above
    
  }else if(runNum=="qcd.elec.sherpa.pu"){
    rnum = 111111;
    sb = "bkgd";
    proc = "qcd (elec)";
    prod_tag="e906";
    xsec = 0.0;
    high_met=150;
    tot_nevts=-1;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=-1;
    kfac=1;
    eff= 1;
    is_qcd=true;
    qcd_scale = qcd_sherpa_elec_sf; //set above

  }else if(runNum=="qcd.muon.sherpa.pu"){
    rnum = 111112;
    sb = "bkgd";
    proc = "qcd (muon)";
    prod_tag="e906";
    xsec = 0.0;
    high_met=150;
    tot_nevts=-1;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=-1;
    kfac=1;
    eff= 1;
    is_qcd=true;
    qcd_scale = qcd_sherpa_muon_sf; //set above
    
  }else if(runNum=="qcd.elec.pythia.pu"){
    rnum = 111111;
    sb = "bkgd";
    proc = "qcd (elec)";
    prod_tag="e906";
    xsec = 0.0;
    high_met=150;
    tot_nevts=-1;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=-1;
    kfac=1;
    eff= 1;
    is_qcd=true;
    qcd_scale = qcd_pythia_elec_sf; //set above

  }else if(runNum=="qcd.muon.pythia.pu"){
    rnum = 111112;
    sb = "bkgd";
    proc = "qcd (muon)";
    prod_tag="e906";
    xsec = 0.0;
    high_met=150;
    tot_nevts=-1;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=-1;
    kfac=1;
    eff= 1;
    is_qcd=true;
    qcd_scale = qcd_pythia_muon_sf; //set above
    
    
  }else if(runNum=="mc.pythia.jj1e.j0.pu"){
    rnum = 109270;
    sb = "bkgd";
    proc = "dijet 1e (J0)";

    xsec = 9.86e9;
    high_met=150;
    tot_nevts=999396;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=995992.12;
    kfac=1;
    eff= 6.8963e-5;

  }else if(runNum=="mc.pythia.jj1e.j1.pu"){
    rnum = 109271;
    sb = "bkgd";
    proc = "dijet 1e (J1)";
    prod_tag="e906";
    xsec = 6.7818e8;
    high_met=150;
    tot_nevts=989744;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=986527.28;
    kfac=1;
    eff= 1.2039e-3;


  }else if(runNum=="mc.pythia.jj1e.j2.pu"){
    rnum = 109272;
    sb = "bkgd";
    proc = "dijet 1e (J2)";
    prod_tag="e906";
    xsec = 4.0982e7;

    high_met=150;
    tot_nevts=499744;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=498091.14;
    kfac=1;
    eff= 5.9151e-3;

  }else if(runNum=="mc.pythia.jj1e.j3.pu"){
    rnum = 109273;
    sb = "bkgd";
    proc = "dijet 1e (J3)";
    prod_tag="e906";
    xsec = 2.1929e6;
    //xsec = 8.7701e4;
    high_met=150;
    tot_nevts=499743;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=497957.19;
    kfac=1;
    eff= 1.5915e-2;


  }else if(runNum=="mc.pythia.jj1u.j0.pu"){
    rnum = 109276;
    sb = "bkgd";
    proc = "dijet 1u (J0)";
    prod_tag="e906";
    xsec = 9.86e9;
    high_met=150;
    tot_nevts=967841;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=964775.9;
    kfac=1;
    eff= 6.8963e-5;

  }else if(runNum=="mc.pythia.jj1u.j1.pu"){
    rnum = 109277;
    sb = "bkgd";
    proc = "dijet 1u (J1)";
    prod_tag="e906";
    xsec = 6.7818e8;
    high_met=150;
    tot_nevts=999799;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=996583.04;
    kfac=1;
    eff= 1.1472e-3;


  }else if(runNum=="mc.pythia.jj1u.j2.pu"){
    rnum = 109278;
    sb = "bkgd";
    proc = "dijet 1u (J2)";
    prod_tag="e906";
    xsec = 4.0982e7;
    high_met=150;
    tot_nevts=499852;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=498294.89;
    kfac=1;
    eff= 5.555056e-3;

  }else if(runNum=="mc.pythia.jj1u.j3.pu"){
    rnum = 109279;
    sb = "bkgd";
    proc = "dijet 1u (J3)";
    prod_tag="e906";
    xsec = 2.1929e6;
    //xsec = 8.7701u4;
    high_met=150;
    tot_nevts=499804;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=498258.36;
    kfac=1;
    eff= 1.2951e-2;

    /////////
    /////////
    ///////// 
    

  }else if(runNum=="mc.alpgen.zee.np0.pu"){
    rnum = 107650;
    sb = "bkgd";
    proc = "Z \\rightarrow ee+0p";
    prod_tag="e835";
    xsec = 668.32;//ww
    high_met=150;
    tot_nevts = 6618284.0;
    dpd_nevts=tot_nevts;//mc10a
    evt_weight=6617088.28;
    kfac=1.25;
    eff= 1;

    // from floating fit
    is_vjets=true;
    qcd_scale = vjets_qcd_alpgen_elec_sf;
    
    
  }else if(runNum=="mc.alpgen.zee.np1.pu"){
    rnum = 107651;
    sb = "bkgd";
    proc = "Z \\rightarrow ee+1p";
    prod_tag="e835";
    xsec = 134.36;
    //xsec = 166.4;
    high_met=150;
    tot_nevts = 1334897.0;
    dpd_nevts=tot_nevts;//mc10a
    evt_weight=1335251.36;
    kfac=1.25;
    eff= 1;
    // from floating fit
    is_vjets=true;
    qcd_scale = vjets_qcd_alpgen_elec_sf;
    
  }else if(runNum=="mc.alpgen.zee.np2.pu"){
    rnum = 107652;
    sb = "bkgd";
    proc = "Z \\rightarrow ee+2p";
    prod_tag="e835";
    xsec = 40.54;
    high_met=150;
    tot_nevts = 2004195.0;
    dpd_nevts=tot_nevts;
    evt_weight=2004099.5;
    kfac=1.25;
    eff= 1;
    // from floating fit
    is_vjets=true;
    qcd_scale = vjets_qcd_alpgen_elec_sf;
    
  }else if(runNum=="mc.alpgen.zee.np3.pu"){

    rnum = 107653;
    sb = "bkgd";
    proc = "Z \\rightarrow ee+3p";
    prod_tag="e835";
    xsec = 11.16;
    //xsec = 14;
    high_met=150;
    tot_nevts = 549949.0;
    dpd_nevts=tot_nevts;
    evt_weight=549808.7;
    kfac=1.25;
    eff= 1;
    // from floating fit
    is_vjets=true;
    qcd_scale = vjets_qcd_alpgen_elec_sf;
    
  }else if(runNum=="mc.alpgen.zee.np4.pu"){
    rnum = 107654;
    sb = "bkgd";
    proc = "Z \\rightarrow ee+4p";
    prod_tag="e835";
    xsec = 2.88;
    high_met=150;
    tot_nevts = 149948.0;
    dpd_nevts=tot_nevts;
    evt_weight=149917.03;
    kfac=1.25;
    eff= 1;
    // from floating fit
    is_vjets=true;
    qcd_scale = vjets_qcd_alpgen_elec_sf;
    
  }else if(runNum=="mc.alpgen.zee.np5.pu"){
    rnum = 107655;
    sb = "bkgd";
    proc = "Z \\rightarrow ee+5p";
    prod_tag="e835";
    xsec = 0.83;
    high_met=150;

    tot_nevts = 50000.0;
    dpd_nevts=tot_nevts;//valid2
    evt_weight= 49989.42;
    kfac=1.25;
    eff= 1;
    // from floating fit
    is_vjets=true;
    qcd_scale = vjets_qcd_alpgen_elec_sf;
    
  }else if(runNum=="mc.alpgen.zuu.np0.pu"){

    rnum = 107660;
    sb = "bkgd";
    proc = "Z \\rightarrow \\mu\\mu+0p";
    prod_tag="e835";
    xsec = 668.68;//ww
    high_met=150;
    tot_nevts = 6615230.0;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=6613423.1;
    kfac=1.25;
    eff= 1;
    // from floating fit
    is_vjets=true;
    qcd_scale = vjets_qcd_alpgen_muon_sf;
    
  }else if(runNum=="mc.alpgen.zuu.np1.pu"){
    rnum = 107661;
    sb = "bkgd";
    proc = "Z \\rightarrow \\mu\\mu+1p";
    prod_tag="e835";
    xsec = 134.14;//ww
    high_met=150;
    tot_nevts = 1334296.0;
    dpd_nevts=tot_nevts;//valid2
    evt_weight= 1334004.0;
    kfac=1.25;
    eff= 1;
    // from floating fit
    is_vjets=true;
    qcd_scale = vjets_qcd_alpgen_muon_sf;
    
  }else if(runNum=="mc.alpgen.zuu.np2.pu"){
    rnum = 107662;
    sb = "bkgd";
    proc = "Z \\rightarrow \\mu\\mu+2p";
    prod_tag="e835";
    xsec = 40.33;//
    high_met=150;
    tot_nevts = 1999941.0;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=1999499.9;
    kfac=1.25;
    eff= 1;
    // from floating fit
    is_vjets=true;
    qcd_scale = vjets_qcd_alpgen_muon_sf;
    
  }else if(runNum=="mc.alpgen.zuu.np3.pu"){
    rnum = 107663;
    sb = "bkgd";
    proc = "Z \\rightarrow \\mu\\mu+3p";
    prod_tag="e835";
    //xsec = 11.161;//ww
    xsec = 11.19;//ww
    high_met=150;
    tot_nevts = 549896.0;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=549780.5;
    kfac=1.25;
    eff= 1;
    // from floating fit
    is_vjets=true;
    qcd_scale = vjets_qcd_alpgen_muon_sf;
    
  }else if(runNum=="mc.alpgen.zuu.np4.pu"){
    rnum = 107664;
    sb = "bkgd";
    proc = "Z \\rightarrow \\mu\\mu+4p";
    prod_tag="e835";
    xsec = 2.75;//ww
    high_met=150;
    tot_nevts = 150000.0;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=149968.26;
    kfac=1.25;
    eff= 1;
    // from floating fit
    is_vjets=true;
    qcd_scale = vjets_qcd_alpgen_muon_sf;
    
  }else if(runNum=="mc.alpgen.zuu.np5.pu"){
    rnum = 107665;
    sb = "bkgd";
    proc = "Z \\rightarrow \\mu\\mu+5p";
    prod_tag="e835";
    xsec = 0.77;//ww
    high_met=150;
    tot_nevts = 50000.0;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=49989.08;
    kfac=1.25;
    eff= 1;
    // from floating fit
    is_vjets=true;
    qcd_scale = vjets_qcd_alpgen_muon_sf;


  }else if(runNum=="mc.alpgen.ztt.np0.pu"){

    rnum = 107670;
    sb = "bkgd";
    proc = "Z \\rightarrow \\tau\\tau+0p";
    prod_tag="e835";
    xsec = 668.40;
    high_met=150;
    tot_nevts = 10613179.0;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=10611547.19;
    kfac=1.25;
    eff= 1;
    // from floating fit
    is_vjets=true;
    qcd_scale = (vjets_qcd_alpgen_muon_sf+vjets_qcd_alpgen_elec_sf)/2.;
    
  }else if(runNum=="mc.alpgen.ztt.np1.pu"){
    rnum = 107671;
    sb = "bkgd";
    proc = "Z \\rightarrow \\tau\\tau+1p";
    prod_tag="e835";
    xsec = 134.81;
    high_met=150;
    tot_nevts = 3334137.0;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=3333599.36;
    kfac=1.25;
    eff= 1;
    // from floating fit
    is_vjets=true;
    qcd_scale = (vjets_qcd_alpgen_muon_sf+vjets_qcd_alpgen_elec_sf)/2.;
    
  }else if(runNum=="mc.alpgen.ztt.np2.pu"){
    rnum = 107672;
    sb = "bkgd";
    proc = "Z \\rightarrow \\tau\\tau+2p";
    prod_tag="e835";
    xsec = 40.36;
    high_met=150;
    tot_nevts = 1004847.0;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=1004573.6;
    kfac=1.25;
    eff= 1;
    // from floating fit
    is_vjets=true;
    qcd_scale = (vjets_qcd_alpgen_muon_sf+vjets_qcd_alpgen_elec_sf)/2.;
    
  }else if(runNum=="mc.alpgen.ztt.np3.pu"){
    rnum = 107673;
    sb = "bkgd";
    proc = "Z \\rightarrow \\tau\\tau+3p";
    prod_tag="e835";
    xsec = 11.25;
    high_met=150;
    tot_nevts = 509847.0;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=509683.4;
    kfac=1.25;
    eff= 1;
    // from floating fit
    is_vjets=true;
    qcd_scale = (vjets_qcd_alpgen_muon_sf+vjets_qcd_alpgen_elec_sf)/2.;
    
  }else if(runNum=="mc.alpgen.ztt.np4.pu"){
    rnum = 107674;
    sb = "bkgd";
    proc = "Z \\rightarrow \\tau\\tau+4p";
    prod_tag="e835";
    xsec = 2.79;
    high_met=150;
    tot_nevts = 144999.0;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=144968.57;
    kfac=1.25;
    eff= 1;
    // from floating fit
    is_vjets=true;
    qcd_scale = (vjets_qcd_alpgen_muon_sf+vjets_qcd_alpgen_elec_sf)/2.;
    
  }else if(runNum=="mc.alpgen.ztt.np5.pu"){
    rnum = 107675;
    sb = "bkgd";
    proc = "Z \\rightarrow \\tau\\tau+5p";
    //xsec = .77;
    prod_tag="e835";
    xsec = 0.77;
    high_met=150;
    tot_nevts = 45000.0;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=44991.05;
    kfac=1.25;
    eff= 1;
    // from floating fit
    is_vjets=true;
    qcd_scale = (vjets_qcd_alpgen_muon_sf+vjets_qcd_alpgen_elec_sf)/2.;

  }else if(runNum=="mc.alpgen.zee.lowm.np0.pu"){

    rnum = 116250;
    sb = "bkgd";
    proc = "mc.alpgen.zee.lowm.np0.pu";
    prod_tag="e906";
    xsec = 3055.2;//top10
    high_met=150;
    tot_nevts=999859;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=986856.02;
    evt_weight=996511.69;
    kfac=1.25;
    eff= 1;
    // from floating fit
    is_vjets=true;
    qcd_scale = (vjets_qcd_alpgen_muon_sf+vjets_qcd_alpgen_elec_sf)/2.;
    
  }else if(runNum=="mc.alpgen.zee.lowm.np1.pu"){

    rnum = 116251;
    sb = "bkgd";
    proc = "mc.alpgen.zee.lowm.np1.pu";
    prod_tag="e906";
    xsec = 84.92;//top10
    high_met=150;
    tot_nevts=299940;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=283962.8;
    evt_weight=299745.1;
    kfac=1.25;
    eff= 1;
    // from floating fit
    is_vjets=true;
    qcd_scale = (vjets_qcd_alpgen_muon_sf+vjets_qcd_alpgen_elec_sf)/2.;
    
  }else if(runNum=="mc.alpgen.zee.lowm.np2.pu"){

    rnum = 116252;
    sb = "bkgd";
    proc = "mc.alpgen.zee.lowm.np2.pu";
    prod_tag="e906";
    xsec = 41.40;//top10
    high_met=150;
    tot_nevts=499880;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=491626.49;
    evt_weight=499329.91;
    kfac=1.25;
    eff= 1;
    // from floating fit
    is_vjets=true;
    qcd_scale = (vjets_qcd_alpgen_muon_sf+vjets_qcd_alpgen_elec_sf)/2.;
    
  }else if(runNum=="mc.alpgen.zee.lowm.np3.pu"){

    rnum = 116253;
    sb = "bkgd";
    proc = "mc.alpgen.zee.lowm.np3.pu";
    prod_tag="e906";
    xsec = 8.38;//top10
    high_met=150;
    tot_nevts=149940;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=146179.85;
    evt_weight=150009.28;
    kfac=1.25;
    eff= 1;
    // from floating fit
    is_vjets=true;
    qcd_scale = (vjets_qcd_alpgen_muon_sf+vjets_qcd_alpgen_elec_sf)/2.;
    
  }else if(runNum=="mc.alpgen.zee.lowm.np4.pu"){

    rnum = 116254;
    sb = "bkgd";
    proc = "mc.alpgen.zee.lowm.np4.pu";
    prod_tag="e906";
    xsec = 1.85;//top10
    high_met=150;
    tot_nevts=39973;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=38731.42;
    evt_weight=40036.8;
    kfac=1.25;
    eff= 1;
    // from floating fit
    is_vjets=true;
    qcd_scale = (vjets_qcd_alpgen_muon_sf+vjets_qcd_alpgen_elec_sf)/2.;


  }else if(runNum=="mc.alpgen.zee.lowm.np5.pu"){

    rnum = 116255;
    sb = "bkgd";
    proc = "mc.alpgen.zee.lowm.np5.pu";
    prod_tag="e906";
    xsec = 0.46;//top10
    high_met=150;
    tot_nevts=9995;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=9654.29;
    evt_weight=10012.5;
    kfac=1.25;
    eff= 1;
    // from floating fit
    is_vjets=true;
    qcd_scale = (vjets_qcd_alpgen_muon_sf+vjets_qcd_alpgen_elec_sf)/2.;

    
  }else if(runNum=="mc.alpgen.zuu.lowm.np0.pu"){

    rnum = 116260;
    sb = "bkgd";
    proc = "mc.alpgen.zuu.lowm.np0.pu";
    prod_tag="e906";
    xsec = 3054.9;//top10
    high_met=150;
    tot_nevts=999869;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=996855.75;
    evt_weight=996513.75;
    kfac=1.25;
    eff= 1;

  }else if(runNum=="mc.alpgen.zuu.lowm.np1.pu"){

    rnum = 116261;
    sb = "bkgd";
    proc = "mc.alpgen.zuu.lowm.np1.pu";
    prod_tag="e906";
    xsec = 84.87;//top10
    high_met=150;
    tot_nevts=299890;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=298771.8;
    evt_weight=298382.78;
    kfac=1.25;
    eff= 1;

  }else if(runNum=="mc.alpgen.zuu.lowm.np2.pu"){

    rnum = 116262;
    sb = "bkgd";
    proc = "mc.alpgen.zuu.lowm.np2.pu";
    prod_tag="e906";
    xsec = 41.45;//top10
    high_met=150;
    tot_nevts=499864;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=498055.01;
    evt_weight=497536.37;
    kfac=1.25;
    eff= 1;

  }else if(runNum=="mc.alpgen.zuu.lowm.np3.pu"){

    rnum = 116263;
    sb = "bkgd";
    proc = "mc.alpgen.zuu.lowm.np3.pu";
    prod_tag="e906";
    xsec = 8.38;//top10
    high_met=150;
    tot_nevts=149939;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=149354.18;
    evt_weight=149126.38;
    kfac=1.25;
    eff= 1;

  }else if(runNum=="mc.alpgen.zuu.lowm.np4.pu"){

    rnum = 116264;
    sb = "bkgd";
    proc = "mc.alpgen.zuu.lowm.np4.pu";
    prod_tag="e906";
    xsec = 1.85;//top10
    high_met=150;
    tot_nevts=39988;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=39814.51;
    evt_weight=39739.42;
    kfac=1.25;
    eff= 1;

  }else if(runNum=="mc.alpgen.zuu.lowm.np5.pu"){

    rnum = 116265;
    sb = "bkgd";
    proc = "mc.alpgen.zuu.lowm.np5.pu";
    prod_tag="e906";
    xsec = 0.46;//top10
    high_met=150;
    tot_nevts=9996;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=9954.08;
    evt_weight=9932.57;
    kfac=1.25;
    eff= 1;

    
  }else if(runNum=="mc.alpgen.ztt.lowm.np0.pu"){

    rnum = 116270;
    sb = "bkgd";
    proc = "mc.alpgen.ztt.lowm.np0.pu";
    prod_tag="e906";
    xsec = 3055.1;//top10
    high_met=150;
    tot_nevts=999865;
    dpd_nevts=tot_nevts;
    //evt_weight=996876.05;
    evt_weight=996529.84;
    kfac=1.25;
    eff= 1;

  }else if(runNum=="mc.alpgen.ztt.lowm.np1.pu"){

    rnum = 116271;
    sb = "bkgd";
    proc = "mc.alpgen.ztt.lowm.np1.pu";
    prod_tag="e906";
    xsec = 84.93;//top10
    high_met=150;
    tot_nevts=299937;
    dpd_nevts=tot_nevts;
    //evt_weight=298974.09;
    evt_weight=298955.28;// mc10a
    kfac=1.25;
    eff= 1;

  }else if(runNum=="mc.alpgen.ztt.lowm.np2.pu"){

    rnum = 116272;
    sb = "bkgd";
    proc = "mc.alpgen.ztt.lowm.np2.pu";
    prod_tag="e906";
    xsec = 41.47;//top10
    high_met=150;
    tot_nevts=499886;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=498253.87;
    evt_weight=498230.02;
    kfac=1.25;
    eff= 1;

  }else if(runNum=="mc.alpgen.ztt.lowm.np3.pu"){

    rnum = 116273;
    sb = "bkgd";
    proc = "mc.alpgen.ztt.lowm.np3.pu";
    prod_tag="e906";
    xsec = 8.36;//top10
    high_met=150;
    tot_nevts=149941;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=149408.27;
    evt_weight=149443.4;
    kfac=1.25;
    eff= 1;

  }else if(runNum=="mc.alpgen.ztt.lowm.np4.pu"){

    rnum = 116274;
    sb = "bkgd";
    proc = "mc.alpgen.ztt.lowm.np4.pu";
    prod_tag="e906";
    xsec = 1.85;//top10
    high_met=150;
    tot_nevts=39984;
    dpd_nevts=tot_nevts;//valid2
    //evt_weight=39824.78;
    evt_weight=39845.98;
    kfac=1.25;
    eff= 1;

  }else if(runNum=="mc.alpgen.ztt.lowm.np5.pu"){

    rnum = 116275;
    sb = "bkgd";
    proc = "mc.alpgen.ztt.lowm.np5.pu";
    prod_tag="e906";
    xsec = 0.46;//top10
    high_met=150;
    tot_nevts=9995;
    dpd_nevts=tot_nevts;//valid
    //evt_weight=9950.32;
    evt_weight=9954.82;
    kfac=1.25;
    eff= 1;


  }else if(runNum=="mc.sherpa.zee.pu"){

    rnum = 114609;
    sb = "bkgd";
    proc = "Z \\rightarrow ee";
    prod_tag="e931";
    xsec = 899.95;
    high_met=150;
    tot_nevts=1999196.0;
    dpd_nevts=tot_nevts;//valid
    evt_weight=1019521.83;
    kfac=1.1878;
    eff= 1;

    is_vjets=true;
    wjets_sf = wjets_sherpa_elec_sf;

    // from floating fit
    qcd_scale=vjets_qcd_sherpa_elec_sf;
    
    sideband_lowsb_lowm_sf = sideband_sherpa_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_sherpa_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_sherpa_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_sherpa_comb_highsb_highm_sf;
    
    sideband_lowm_sf = sideband_sherpa_comb_lowm_sf;
    sideband_highm_sf = sideband_sherpa_comb_highm_sf;    

  }else if(runNum=="mc.sherpa.zuu.pu"){

    rnum = 114610;
    sb = "bkgd";
    proc = "Z \\rightarrow \\mu\\mu";
    prod_tag="e931";
    xsec = 899.72;
    high_met=150;
    tot_nevts=1999294;
    dpd_nevts=tot_nevts;//valid
    evt_weight=1019880.1;
    kfac=1.1881;
    eff= 1;


    is_vjets=true;
    wjets_sf = wjets_sherpa_muon_sf;

    // from floating fit
    qcd_scale=vjets_qcd_sherpa_muon_sf;

    sideband_lowsb_lowm_sf = sideband_sherpa_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_sherpa_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_sherpa_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_sherpa_comb_highsb_highm_sf;
    
    sideband_lowm_sf = sideband_sherpa_comb_lowm_sf;
    sideband_highm_sf = sideband_sherpa_comb_highm_sf;    

  }else if(runNum=="mc.sherpa.ztt.pu"){

    rnum = 119931;
    sb = "bkgd";
    proc = "Z \\rightarrow \\tau\\tau";
    prod_tag="e931";
    xsec = 904.39; //sum alpgen xsec*kfac
    high_met=150;
    tot_nevts=159949;
    dpd_nevts=tot_nevts;//valid
    evt_weight=81643.88;
    kfac=1.182;
    eff= 1;

    is_vjets=true;
    wjets_sf = (wjets_sherpa_muon_sf+wjets_sherpa_elec_sf)/2.;

    // from floating fit
    qcd_scale=(vjets_qcd_sherpa_elec_sf+vjets_qcd_sherpa_muon_sf)/2.;

    sideband_lowsb_lowm_sf = sideband_sherpa_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_sherpa_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_sherpa_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_sherpa_comb_highsb_highm_sf;
    
    sideband_lowm_sf = sideband_sherpa_comb_lowm_sf;
    sideband_highm_sf = sideband_sherpa_comb_highm_sf;
    
  }else if(runNum=="mc.sherpa.wenu.pu"){

    rnum = 119128;
    sb = "bkgd";
    proc = "W \\rightarrow e\\nu";
    prod_tag="e931";
    xsec = 10460.0;//susy
    high_met=150;
    tot_nevts=1699846.0;
    dpd_nevts=tot_nevts;//valid
    evt_weight=864278.3;
    kfac=1;
    eff= 1.;

    is_wjets=true;
    is_vjets=true;

    // from floating fit
    qcd_scale=vjets_qcd_sherpa_elec_sf;

    wjets_sf = wjets_sherpa_elec_sf;
  
    sideband_lowsb_lowm_sf = sideband_sherpa_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_sherpa_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_sherpa_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_sherpa_comb_highsb_highm_sf;
    
    sideband_lowm_sf = sideband_sherpa_comb_lowm_sf;
    sideband_highm_sf = sideband_sherpa_comb_highm_sf;    

  }else if(runNum=="mc.sherpa.wtnu.pu"){

    rnum = 119930;
    sb = "bkgd";
    proc = "W \\rightarrow \\tau\\nu";
    prod_tag="e931";
    xsec = 10460; //sum alpgen xsec*kfac
    high_met=150;
    tot_nevts=1699496.0;
    dpd_nevts=tot_nevts;//valid
    evt_weight=863625.21;
    kfac=1.;
    eff= 1.;
    //eff= 0.9;

    is_wjets=true;
    is_vjets=true;
    // from floating fit
    qcd_scale=(vjets_qcd_sherpa_elec_sf+vjets_qcd_sherpa_muon_sf)/2.;

    wjets_sf = (wjets_sherpa_muon_sf+wjets_sherpa_elec_sf)/2.;

    sideband_lowsb_lowm_sf = sideband_sherpa_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_sherpa_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_sherpa_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_sherpa_comb_highsb_highm_sf;
    
    sideband_lowm_sf = sideband_sherpa_comb_lowm_sf;
    sideband_highm_sf =sideband_sherpa_comb_highm_sf;

    //////////////////////////////////////////////////
    // W
    // sum xsec(W) = 27809.4829 (note xsec(W) = 10.46) ??
    // sum xsec
    // - wenu: 8673.76 * 1.21 = 10495.2496
    // - wunu: 8675.72 * 1.21 = 10497.6212
    // - wtnu (xsec*kfac): 10460
    //////////////////////////////////////////////////
       
  }else if(runNum=="mc.sherpa.wunu.pu"){

    rnum = 114611;//119129;
    sb = "bkgd";
    proc = "W \\rightarrow \\mu\\nu";
    prod_tag="e931";
    xsec = 10460;
    high_met=150;
    tot_nevts=1699694.0;
    dpd_nevts=tot_nevts;//valid
    evt_weight=863506.08;
    kfac=1.;
    eff= 1.;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_sherpa_muon_sf;

    // from floating fit
    qcd_scale=vjets_qcd_sherpa_muon_sf;

    sideband_lowsb_lowm_sf = sideband_sherpa_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_sherpa_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_sherpa_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_sherpa_comb_highsb_highm_sf;
    
    sideband_lowm_sf = sideband_sherpa_comb_lowm_sf;
    sideband_highm_sf = sideband_sherpa_comb_highm_sf;    

  }else if(runNum=="mc.pythia.zee.pu"){

    rnum = 106046;
    sb = "bkgd";
    proc = "Z \\rightarrow ee";
    prod_tag="e931";
    //xsec = 1072.6125;//from sum alpgen
    xsec = 851.0; //https://svnweb.cern.ch/trac/atlasgrp/browser/Physics/StandardModel/Common/Winter2012/mc11c_p833_info.txt
    high_met=150;
    tot_nevts=9991125.0;
    dpd_nevts=tot_nevts;//valid
    evt_weight=9988279.07;
    //kfac=1;
    kfac=1.15;
    eff= 1;
    // from floating fit
    is_vjets=true;
    qcd_scale = vjets_qcd_pythia_elec_sf;

  }else if(runNum=="mc.pythia.ztt.pu"){

    rnum = 106052;
    sb = "bkgd";
    proc = "Z \\rightarrow \\tau\\tau";
    prod_tag="e931";
    xsec = 1072.975; //sum alpgen xsec*kfac
    high_met=150;
    tot_nevts=495347;
    dpd_nevts=tot_nevts;//valid
    evt_weight=495224.2;
    kfac=1.0;
    eff= 1;
    // from floating fit
    is_vjets=true;
    qcd_scale = (vjets_qcd_pythia_elec_sf+vjets_qcd_pythia_muon_sf)/2.;
       
  }else if(runNum=="mc.pythia.zuu.pu"){

    rnum = 106047;
    sb = "bkgd";
    proc = "Z \\rightarrow \\mu\\mu";
    prod_tag="e931";
    //xsec = 1071.3625;
    xsec = 851.0;
    high_met=150;
    //tot_nevts=899997.;
    tot_nevts=5896736.0;
    dpd_nevts=tot_nevts;//valid
    //evt_weight=899773.8;
    evt_weight=5895387.55;
    kfac=1.15;
    eff= 1;
    // from floating fit
    is_vjets=true;
    qcd_scale = vjets_qcd_pythia_muon_sf;
    
  }else if(runNum=="mc.pythia.wenu.pu"){

    rnum = 106043;
    sb = "bkgd";
    proc = "W \\rightarrow e\\nu";
    prod_tag="e931";
    xsec = 10463.15816;//from sum alpgen
    //xsec = 8700.2;//ami
    high_met=150;
    tot_nevts=7995623;
    dpd_nevts=tot_nevts;//valid
    evt_weight=7993848.68;
    kfac=1;
    eff= 1.;
    // from floating fit
    is_vjets=true;
    qcd_scale = vjets_qcd_pythia_elec_sf;

  }else if(runNum=="mc.pythia.wtnu.pu"){

    rnum = 106044;
    sb = "bkgd";
    proc = "W \\rightarrow \\tau\\nu";
    prod_tag="e931";
    xsec = 10460; //sum alpgen xsec*kfac
    high_met=150;
    tot_nevts=497000;
    dpd_nevts=tot_nevts;//valid
    evt_weight=496896.7;
    kfac=1.;
    eff= 1.;
    // from floating fit
    is_vjets=true;
    qcd_scale = (vjets_qcd_pythia_elec_sf+vjets_qcd_pythia_muon_sf)/2;
       
  }else if(runNum=="mc.pythia.wunu.pu"){

    rnum = 107054;
    sb = "bkgd";
    proc = "W \\rightarrow \\mu\\nu";
    prod_tag="e931";
    xsec = 10497.6212;
    high_met=150;
    tot_nevts=6996784;
    dpd_nevts=tot_nevts;//valid
    evt_weight=6994674.22;
    kfac=1.;
    eff= 1.;
    // from floating fit
    is_vjets=true;
    qcd_scale = vjets_qcd_pythia_muon_sf;

  }else if(runNum=="mc.alpgen.wbb.np0.pu"){

    sb = "bkgd";
    rnum = 107280;
    proc = "W \\rightarrow \\ell\\nu+bb+0p";
    prod_tag="e887";
    //xsec = 47.35;
    xsec = 45.6;
    high_met=150;
    tot_nevts=474997;
    dpd_nevts=tot_nevts;
    evt_weight=485274.2;
    //kfac=1.2;
    kfac=1.22;
    eff = 1.;    

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_elec_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_elec_sf;
    
    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;


    // wjets sideband scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;

    // boost scale factor
    boost_sf=boost_elec_sf;
    
  }else if(runNum=="mc.alpgen.wbb.np1.pu"){

    sb = "bkgd";
    rnum = 107281;
    proc = "W \\rightarrow \\ell\\nu+bb+1p";
    prod_tag="e887";
    //xsec = 35.76;
    xsec = 33.7;
    high_met=150;
    tot_nevts=205000;
    dpd_nevts=tot_nevts;
    evt_weight=220904.17;
    kfac=1.22;
    eff = 1.;    

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_elec_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_elec_sf;
    
    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;


    // wjets sideband scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;

    // boost scale factor
    boost_sf=boost_elec_sf;
    
  }else if(runNum=="mc.alpgen.wbb.np2.pu"){

    sb = "bkgd";
    rnum = 107282;
    proc = "W \\rightarrow \\ell\\nu+bb+2p";
    prod_tag="e887";
    //xsec = 17.33;
    xsec = 16.7;
    high_met=150;
    tot_nevts=174499.0;
    dpd_nevts=tot_nevts;
    evt_weight=221989.03;
    kfac=1.22;
    eff = 1.;    

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_elec_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_elec_sf;
    
    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;


    // wjets sideband scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;

    // boost scale factor
    boost_sf=boost_elec_sf;
    
  }else if(runNum=="mc.alpgen.wbb.np3.pu"){

    sb = "bkgd";
    rnum = 107283;
    proc = "W \\rightarrow \\ell\\nu+bb+3p";
    prod_tag="e887";
    //xsec = 7.61;
    xsec = 6.3;
    high_met=150;
    tot_nevts=69999.0;
    dpd_nevts=tot_nevts;
    evt_weight=76882.47;
    kfac=1.22;
    eff = 1.;    

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_elec_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_elec_sf;
    
    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;


    // wjets sideband scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;

    // boost scale factor
    boost_sf=boost_elec_sf;
    
  }else if(runNum=="mc.alpgen.wc.np0.pu"){

    sb = "bkgd";
    rnum = 117293;
    proc = "W \\rightarrow \\ell\\nu+c+0p";
    prod_tag="e887";
    //xsec = 644.4;
    xsec = 431.2;
    high_met=150;
    tot_nevts=6487837.0;
    dpd_nevts=tot_nevts;
    evt_weight=6496144.6;
    kfac=1.22;
    eff = 1.;    

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_elec_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_elec_sf;
    
    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;


    // wjets sideband scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;

    // boost scale factor
    boost_sf=boost_elec_sf;
    
  }else if(runNum=="mc.alpgen.wc.np1.pu"){

    sb = "bkgd";
    rnum = 117294;
    proc = "W \\rightarrow \\ell\\nu+c+1p";
    prod_tag="e887";
    //xsec = 205.0;
    xsec = 160.1;
    high_met=150;
    tot_nevts=2069646.0;
    dpd_nevts=tot_nevts;
    evt_weight=2069265.4;
    kfac=1.22;
    eff = 1.;    

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_elec_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_elec_sf;
    
    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;


    // wjets sideband scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;

    // boost scale factor
    boost_sf=boost_elec_sf;
    
  }else if(runNum=="mc.alpgen.wc.np2.pu"){

    sb = "bkgd";
    rnum = 117295;
    proc = "W \\rightarrow \\ell\\nu+c+2p";
    prod_tag="e887";
    //xsec = 50.8;
    xsec = 42.5;
    high_met=150;
    tot_nevts=519998.0;
    dpd_nevts=tot_nevts;
    evt_weight=519913.8;
    kfac=1.22;
    eff = 1.;    

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_elec_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_elec_sf;
    
    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;


    // wjets sideband scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;

    // boost scale factor
    boost_sf=boost_elec_sf;
    
  }else if(runNum=="mc.alpgen.wc.np3.pu"){

    sb = "bkgd";
    rnum = 117296;
    proc = "W \\rightarrow \\ell\\nu+c+3p";
    prod_tag="e887";
    //xsec = 11.4;
    xsec = 9.9;
    high_met=150;
    tot_nevts=115000.0;
    dpd_nevts=tot_nevts;
    evt_weight=114975.87;
    kfac=1.22;
    eff = 1.;    

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_elec_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_elec_sf;
    
    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;


    // wjets sideband scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;

    // boost scale factor
    boost_sf=boost_elec_sf;
    
  }else if(runNum=="mc.alpgen.wc.np4.pu"){

    sb = "bkgd";
    rnum = 117297;
    proc = "W \\rightarrow \\ell\\nu+c+4p";
    prod_tag="e887";
    //xsec = 2.8;
    xsec = 2.3;
    high_met=150;
    tot_nevts=30000.0;
    dpd_nevts=tot_nevts;
    evt_weight=29993.95;
    kfac=1.22;
    eff = 1.;    

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_elec_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_elec_sf;
    
    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;


    // wjets sideband scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;

    // boost scale factor
    boost_sf=boost_elec_sf;
    
  }else if(runNum=="mc.alpgen.wcc.np0.pu"){

    sb = "bkgd";
    rnum = 117284;
    proc = "W \\rightarrow \\ell\\nu+cc+0p";
    prod_tag="e887";
    //xsec = 127.53;
    xsec = 127.5;
    high_met=150;
    tot_nevts=1274846.0;
    dpd_nevts=tot_nevts;
    evt_weight=1274546.23;
    kfac=1.22;
    eff = 1.;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_elec_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_elec_sf;
    
    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;

    // wjets sideband scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;

    // boost scale factor
    boost_sf=boost_elec_sf;
    
  }else if(runNum=="mc.alpgen.wcc.np1.pu"){

    sb = "bkgd";
    rnum = 117285;
    proc = "W \\rightarrow \\ell\\nu+cc+1p";
    prod_tag="e887";
    //xsec = 104.68;
    xsec = 103.2;
    high_met=150;
    tot_nevts=1049847.0;
    dpd_nevts=tot_nevts;
    evt_weight=1049641.8;
    kfac=1.22;
    eff = 1.;    

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_elec_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_elec_sf;
    
    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;


    // wjets sideband scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;

    // boost scale factor
    boost_sf=boost_elec_sf;
    
  }else if(runNum=="mc.alpgen.wcc.np2.pu"){

    sb = "bkgd";
    rnum = 117286;
    proc = "W \\rightarrow \\ell\\nu+cc+2p";
    prod_tag="e887";
    //xsec = 52.08;
    xsec = 51.7;
    high_met=150;
    tot_nevts=524947.0;
    dpd_nevts=tot_nevts;
    evt_weight=524783.72;
    kfac=1.22;
    eff = 1.;    

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_elec_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_elec_sf;
    
    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;

    // wjets sideband scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;

    // boost scale factor
    boost_sf=boost_elec_sf;
    
  }else if(runNum=="mc.alpgen.wcc.np3.pu"){

    sb = "bkgd";
    rnum = 117287;
    proc = "W \\rightarrow \\ell\\nu+cc+3p";
    prod_tag="e887";
    //xsec = 16.96;
    xsec = 16.9;
    high_met=150;
    tot_nevts=170000.0;
    dpd_nevts=tot_nevts;
    evt_weight=169965.0;
    kfac=1.22;
    eff = 1.;    

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_elec_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_elec_sf;
    
    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;


    // wjets sideband scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;

    // boost scale factor
    boost_sf=boost_elec_sf;
    
 
  }else if(runNum=="mc.alpgen.wenu.np0.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow e\\nu+0p";
    prod_tag="e825";
    xsec = 6930.50;
    rnum = 107680;
    high_met=150;
    tot_nevts=6952874.0;//3458883.0;
    dpd_nevts=tot_nevts;
    evt_weight=6951424.98;
    //kfac=1.21;
    kfac=1.196;
    eff = 1.;    

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_elec_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_elec_sf;
    
    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;


    // wjets sideband scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;

    // boost scale factor
    boost_sf=boost_elec_sf;
    
  }else if(runNum=="mc.alpgen.wenu.np1.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow e\\nu+1p";
    prod_tag="e825";
    //xsec = 1293.0;
    xsec = 1305.30;
    rnum = 107681;
    high_met=150;
    tot_nevts = 4998487.0;
    dpd_nevts=tot_nevts;
    evt_weight = 4997213.03;
    //kfac=1.21;
    kfac=1.196;
    eff = 1.;
    boost_sf=boost_elec_sf;

    is_wjets=true;
    is_vjets=true;
    wjets_sf = wjets_alpgen_elec_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_elec_sf;

    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;
    
    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;

	
  }else if(runNum=="mc.alpgen.wenu.np2.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow e\\nu+2p";
    rnum = 107682;
    prod_tag="e825";
    //xsec = 376.6;//top
    xsec = 378.13;
    high_met=150;
    tot_nevts = 3768632.0;
    dpd_nevts=tot_nevts;
    evt_weight=3767710.5;
    //kfac=1.21;
    kfac=1.196;
    eff = 1.;
    //boost_sf=0.614929;
    boost_sf=boost_elec_sf;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_elec_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_elec_sf;


    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;
    
    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;


  }else if(runNum=="mc.alpgen.wenu.np3.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow e\\nu+3p";
    rnum = 107683;
    prod_tag="e825";
    xsec = 101.86;//ww
    //xsec = 122.1;//ww
    high_met=150;
    tot_nevts = 1008947.0;
    dpd_nevts=tot_nevts;
    evt_weight=1008668.1;
    //kfac=1.21;
    kfac=1.196;
    eff = 1.;
    //boost_sf=0.614929;
    boost_sf=boost_elec_sf;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_elec_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_elec_sf;


    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;

    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;
    
  }else if(runNum=="mc.alpgen.wenu.np4.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow e\\nu+4p";
    rnum = 107684;
    prod_tag="e825";
    xsec = 25.68;//ww
    high_met=150;
    tot_nevts = 250000.0;
    dpd_nevts=tot_nevts;
    evt_weight=249949.98;
    //kfac=1.21;
    kfac=1.196;
    eff = 1.;
    //boost_sf=0.614929;
    boost_sf=boost_elec_sf;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_elec_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_elec_sf;


    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;
    
    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;
    
  }else if(runNum=="mc.alpgen.wenu.np5.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow e\\nu+5p";
    rnum = 107685;
    prod_tag="e825";
    //xsec = 7.1239;//ww
    xsec = 6.99;//ww
    high_met=150;
    tot_nevts=69999;
    dpd_nevts=tot_nevts;
    evt_weight=69984.48;
    //kfac=1.21;
    kfac=1.196;
    eff = 1.;
    boost_sf=boost_elec_sf;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_elec_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_elec_sf;


    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;

    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;
    
  }else if(runNum=="mc.alpgen.wunu.np0.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow \\mu\\nu+0p";
    prod_tag="e825";
    xsec = 6932.40;
    rnum = 107690;
    high_met=150;
    tot_nevts = 6962239.0;//3462942.0;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=6960393.29;//3462000.75;
    //kfac=1.21;
    kfac=1.195;
    eff = 1.;
    boost_sf=boost_muon_sf;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_muon_sf;
    
    // from floating fit
    qcd_scale = vjets_qcd_alpgen_muon_sf;


    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;

    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;
    
    
  }else if(runNum=="mc.alpgen.wunu.np1.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow \\mu\\nu+1p";
    prod_tag="e825";
    xsec = 1305.90;//ww
    rnum = 107691;
    high_met=150;
    tot_nevts = 2498593.0;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=2497927.89;
    kfac=1.195;
    eff = 1.;
    boost_sf=boost_muon_sf;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_muon_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_muon_sf;
    
    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;

    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;
    
    
  }else if(runNum=="mc.alpgen.wunu.np2.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow \\mu\\nu+2p";
    rnum = 107692;
    prod_tag="e825";
    xsec = 378.07;
    high_met=150;
    tot_nevts = 3768737.0;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=3767819.31;
    kfac=1.195;
    eff = 1.;
    boost_sf=boost_muon_sf;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_muon_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_muon_sf;

    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;

    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;
    
    
  }else if(runNum=="mc.alpgen.wunu.np3.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow \\mu\\nu+3p";
    rnum = 107693;
    prod_tag="e825";
    xsec = 101.85;
    high_met=150;
    tot_nevts = 1008446.0;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=1008207.55;
    kfac=1.195;
    eff = 1.;
    boost_sf=boost_muon_sf;
    
    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_muon_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_muon_sf;

    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;
    
    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;
    
    
  }else if(runNum=="mc.alpgen.wunu.np4.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow \\mu\\nu+4p";
    rnum = 107694;
    prod_tag="e825";
    xsec = 25.72;
    high_met=150;
    tot_nevts = 254950.0;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=254907.59;
    kfac=1.195;
    eff = 1.;
    boost_sf=boost_muon_sf;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_muon_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_muon_sf;

    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;

    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;
        
  }else if(runNum=="mc.alpgen.wunu.np5.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow \\mu\\nu+5p";
    rnum = 107695;
    prod_tag="e825";
    xsec = 7.00;
    high_met=150;
    tot_nevts=70000;
    dpd_nevts=tot_nevts;//valid
    evt_weight=69985.41;
    kfac=1.195;
    eff = 1.;
    boost_sf=boost_muon_sf;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_muon_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_muon_sf;

    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;

    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;

  }else if(runNum=="mc.alpgen.wtnu.np0.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow \\tau\\nu+0p";
    //xsec = 6918.6;//ww
    prod_tag="e835";
    //xsec = 8285.4;
    xsec = 6931.80;
    rnum = 107700;
    high_met=150;
    tot_nevts = 3418296.0;
    dpd_nevts=tot_nevts;
    evt_weight=3417521.4;
    kfac=1.195;
    eff = 1.;
    //boost_sf=0.6634365;
    boost_sf=(boost_elec_sf+boost_muon_sf)/2;// avg elec/muon, checked mc.alpgen.wtnu.np2:~/boost1/h_elec|muon_dijet_pt, about 50%

    is_wjets=true;
    is_vjets=true;

    wjets_sf = (wjets_alpgen_muon_sf+wjets_alpgen_muon_sf)/2.;

    // from floating fit
    qcd_scale = (vjets_qcd_alpgen_muon_sf+vjets_qcd_alpgen_elec_sf)/2;
  
    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;

    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;
    
  }else if(runNum=="mc.alpgen.wtnu.np1.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow \\tau\\nu+1p";
    prod_tag="e835";
    xsec = 1304.90;
    rnum = 107701;
    high_met=150;
    tot_nevts = 2499194.0;
    dpd_nevts=tot_nevts;
    evt_weight=2498692.2;
    kfac=1.195;
    eff = 1.;

    boost_sf=(boost_elec_sf+boost_muon_sf)/2;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = (wjets_alpgen_muon_sf+wjets_alpgen_muon_sf)/2.;

    // from floating fit
    qcd_scale = (vjets_qcd_alpgen_muon_sf+vjets_qcd_alpgen_elec_sf)/2;

    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = (sideband_alpgen_comb_highsb_highm_sf+sideband_alpgen_comb_highsb_highm_sf)/2.;

    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;
    
  }else if(runNum=="mc.alpgen.wtnu.np2.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow \\tau\\nu+2p";
    rnum = 107702;
    prod_tag="e835";
    //xsec = 454.2;
    xsec = 377.93;
    high_met=150;
    tot_nevts=3750986.0;
    dpd_nevts=tot_nevts;
    evt_weight=3751431.3;
    kfac=1.195;
    eff = 1.;
    boost_sf=(boost_elec_sf+boost_muon_sf)/2;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = (wjets_alpgen_muon_sf+wjets_alpgen_muon_sf)/2.;

    // from floating fit
    qcd_scale = (vjets_qcd_alpgen_muon_sf+vjets_qcd_alpgen_elec_sf)/2;

    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = (sideband_alpgen_comb_highsb_highm_sf+sideband_alpgen_comb_highsb_highm_sf)/2.;

    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;
 
  }else if(runNum=="mc.alpgen.wtnu.np3.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow \\tau\\nu+3p";
    rnum = 107703;
    prod_tag="e835";
    //xsec = 122.1;
    xsec = 101.96;
    high_met=150;
    tot_nevts = 1009946.0;
    dpd_nevts=tot_nevts;
    evt_weight=1009715.4;
    kfac=1.195;
    eff = 1.;
    boost_sf=(boost_elec_sf+boost_muon_sf)/2;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = (wjets_alpgen_muon_sf+wjets_alpgen_muon_sf)/2.;

    // from floating fit
    qcd_scale = (vjets_qcd_alpgen_muon_sf+vjets_qcd_alpgen_elec_sf)/2;

    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = (sideband_alpgen_comb_highsb_highm_sf+sideband_alpgen_comb_highsb_highm_sf)/2.;

    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;
    
  }else if(runNum=="mc.alpgen.wtnu.np4.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow \\tau\\nu+4p";
    rnum = 107704;
    prod_tag="e835";
    xsec = 25.71;
    high_met=150;
    tot_nevts = 249998.0;
    dpd_nevts=tot_nevts;
    evt_weight=249950.57;
    kfac=1.195;
    eff = 1.;
    boost_sf=(boost_elec_sf+boost_muon_sf)/2;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = (wjets_alpgen_muon_sf+wjets_alpgen_muon_sf)/2.;

    // from floating fit
    qcd_scale = (vjets_qcd_alpgen_muon_sf+vjets_qcd_alpgen_elec_sf)/2;

    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = (sideband_alpgen_comb_highsb_highm_sf+sideband_alpgen_comb_highsb_highm_sf)/2.;

    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;
 
  }else if(runNum=="mc.alpgen.wtnu.np5.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow \\tau\\nu+5p";
    rnum = 107705;
    //xsec = 7.04;
    prod_tag="e835";
    xsec = 7.0;
    high_met=150;
    tot_nevts=65000.0;
    dpd_nevts=tot_nevts;//valid
    evt_weight=64986.44;
    kfac=1.195;
    eff = 1.;
    //boost_sf=0.6634365;
    boost_sf=(boost_elec_sf+boost_muon_sf)/2;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = (wjets_alpgen_muon_sf+wjets_alpgen_muon_sf)/2.;

    // from floating fit
    qcd_scale = (vjets_qcd_alpgen_muon_sf+vjets_qcd_alpgen_elec_sf)/2;
    
    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;

    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;


  }else if(runNum=="mc.alpgen.cont.wenu.np0.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow e\\nu+0p";
    prod_tag="e825";
    xsec = 6930.50;
    rnum = 107680;
    high_met=150;
    tot_nevts=6952874.0;//3458883.0;
    dpd_nevts=tot_nevts;
    evt_weight=6951424.98;//3458122.91;
    //kfac=1.21;
    kfac=1.196;
    eff = 1.;    

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_elec_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_elec_sf;
    
    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;


    // wjets sideband scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;

    // boost scale factor
    boost_sf=boost_elec_sf;
    
  }else if(runNum=="mc.alpgen.cont.wenu.np1.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow e\\nu+1p";
    prod_tag="e825";
    //xsec = 1293.0;
    xsec = 1305.30;
    rnum = 107681;
    high_met=150;
    tot_nevts = 4998487.0;
    dpd_nevts=tot_nevts;
    evt_weight = 4997213.03;
    //kfac=1.21;
    kfac=1.196;
    eff = 1.;
    boost_sf=boost_elec_sf;

    is_wjets=true;
    is_vjets=true;
    wjets_sf = wjets_alpgen_elec_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_elec_sf;

    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;
    
    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;

	
  }else if(runNum=="mc.alpgen.cont.wenu.np2.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow e\\nu+2p";
    rnum = 107682;
    prod_tag="e825";
    //xsec = 376.6;//top
    xsec = 378.13;
    high_met=150;
    tot_nevts = 3768632.0;
    dpd_nevts=tot_nevts;
    evt_weight=3767710.5;
    //kfac=1.21;
    kfac=1.196;
    eff = 1.;
    //boost_sf=0.614929;
    boost_sf=boost_elec_sf;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_elec_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_elec_sf;


    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;
    
    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;


  }else if(runNum=="mc.alpgen.cont.wenu.np3.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow e\\nu+3p";
    rnum = 107683;
    prod_tag="e825";
    xsec = 101.86;//ww
    //xsec = 122.1;//ww
    high_met=150;
    tot_nevts = 1008947.0;
    dpd_nevts=tot_nevts;
    evt_weight=1008668.1;
    //kfac=1.21;
    kfac=1.196;
    eff = 1.;
    //boost_sf=0.614929;
    boost_sf=boost_elec_sf;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_elec_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_elec_sf;


    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;

    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;
    
  }else if(runNum=="mc.alpgen.cont.wenu.np4.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow e\\nu+4p";
    rnum = 107684;
    prod_tag="e825";
    xsec = 25.68;//ww
    high_met=150;
    tot_nevts = 250000.0;
    dpd_nevts=tot_nevts;
    evt_weight=249949.98;
    //kfac=1.21;
    kfac=1.196;
    eff = 1.;
    //boost_sf=0.614929;
    boost_sf=boost_elec_sf;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_elec_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_elec_sf;


    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;
    
    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;
    
  }else if(runNum=="mc.alpgen.cont.wenu.np5.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow e\\nu+5p";
    rnum = 107685;
    prod_tag="e825";
    //xsec = 7.1239;//ww
    xsec = 6.99;//ww
    high_met=150;
    tot_nevts=69999;
    dpd_nevts=tot_nevts;
    evt_weight=69984.48;
    //kfac=1.21;
    kfac=1.196;
    eff = 1.;
    boost_sf=boost_elec_sf;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_elec_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_elec_sf;


    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;

    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;
    
  }else if(runNum=="mc.alpgen.cont.wunu.np0.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow \\mu\\nu+0p";
    prod_tag="e825";
    xsec = 6932.40;
    rnum = 107690;
    high_met=150;
    tot_nevts = 6962239.0;//3462942.0;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=6960393.29;//3462000.75;
    //kfac=1.21;
    kfac=1.195;
    eff = 1.;
    boost_sf=boost_muon_sf;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_muon_sf;
    
    // from floating fit
    qcd_scale = vjets_qcd_alpgen_muon_sf;


    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;

    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;
    
    
  }else if(runNum=="mc.alpgen.cont.wunu.np1.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow \\mu\\nu+1p";
    prod_tag="e825";
    xsec = 1305.90;//ww
    rnum = 107691;
    high_met=150;
    tot_nevts = 2498593.0;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=2497927.89;
    kfac=1.195;
    eff = 1.;
    boost_sf=boost_muon_sf;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_muon_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_muon_sf;
    
    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;

    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;
    
    
  }else if(runNum=="mc.alpgen.cont.wunu.np2.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow \\mu\\nu+2p";
    rnum = 107692;
    prod_tag="e825";
    xsec = 378.07;
    high_met=150;
    tot_nevts = 3768737.0;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=3767819.31;
    kfac=1.195;
    eff = 1.;
    boost_sf=boost_muon_sf;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_muon_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_muon_sf;

    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;

    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;
    
    
  }else if(runNum=="mc.alpgen.cont.wunu.np3.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow \\mu\\nu+3p";
    rnum = 107693;
    prod_tag="e825";
    xsec = 101.85;
    high_met=150;
    tot_nevts = 1008446.0;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=1008207.55;
    kfac=1.195;
    eff = 1.;
    boost_sf=boost_muon_sf;
    
    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_muon_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_muon_sf;

    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;
    
    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;
    
    
  }else if(runNum=="mc.alpgen.cont.wunu.np4.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow \\mu\\nu+4p";
    rnum = 107694;
    prod_tag="e825";
    xsec = 25.72;
    high_met=150;
    tot_nevts = 254950.0;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=254907.59;
    kfac=1.195;
    eff = 1.;
    boost_sf=boost_muon_sf;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_muon_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_muon_sf;

    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;

    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;
        
  }else if(runNum=="mc.alpgen.cont.wunu.np5.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow \\mu\\nu+5p";
    rnum = 107695;
    prod_tag="e825";
    xsec = 7.00;
    high_met=150;
    tot_nevts=70000;
    dpd_nevts=tot_nevts;//valid
    evt_weight=69985.41;
    kfac=1.195;
    eff = 1.;
    boost_sf=boost_muon_sf;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = wjets_alpgen_muon_sf;

    // from floating fit
    qcd_scale = vjets_qcd_alpgen_muon_sf;

    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;

    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;

  }else if(runNum=="mc.alpgen.cont.wtnu.np0.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow \\tau\\nu+0p";
    //xsec = 6918.6;//ww
    prod_tag="e835";
    //xsec = 8285.4;
    xsec = 6931.80;
    rnum = 107700;
    high_met=150;
    tot_nevts = 3418296.0;
    dpd_nevts=tot_nevts;
    evt_weight=3417521.4;
    kfac=1.195;
    eff = 1.;
    //boost_sf=0.6634365;
    boost_sf=(boost_elec_sf+boost_muon_sf)/2;// avg elec/muon, checked mc.alpgen.cont.wtnu.np2:~/boost1/h_elec|muon_dijet_pt, about 50%

    is_wjets=true;
    is_vjets=true;

    wjets_sf = (wjets_alpgen_muon_sf+wjets_alpgen_muon_sf)/2.;

    // from floating fit
    qcd_scale = (vjets_qcd_alpgen_muon_sf+vjets_qcd_alpgen_elec_sf)/2;
  
    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;

    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;
    
  }else if(runNum=="mc.alpgen.cont.wtnu.np1.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow \\tau\\nu+1p";
    prod_tag="e835";
    xsec = 1304.90;
    rnum = 107701;
    high_met=150;
    tot_nevts = 2499194.0;
    dpd_nevts=tot_nevts;
    evt_weight=2498692.2;
    kfac=1.195;
    eff = 1.;

    boost_sf=(boost_elec_sf+boost_muon_sf)/2;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = (wjets_alpgen_muon_sf+wjets_alpgen_muon_sf)/2.;

    // from floating fit
    qcd_scale = (vjets_qcd_alpgen_muon_sf+vjets_qcd_alpgen_elec_sf)/2;

    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = (sideband_alpgen_comb_highsb_highm_sf+sideband_alpgen_comb_highsb_highm_sf)/2.;

    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;
    
  }else if(runNum=="mc.alpgen.cont.wtnu.np2.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow \\tau\\nu+2p";
    rnum = 107702;
    prod_tag="e835";
    //xsec = 454.2;
    xsec = 377.93;
    high_met=150;
    tot_nevts=3750986.0;
    dpd_nevts=tot_nevts;
    evt_weight=3751431.3;
    kfac=1.195;
    eff = 1.;
    boost_sf=(boost_elec_sf+boost_muon_sf)/2;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = (wjets_alpgen_muon_sf+wjets_alpgen_muon_sf)/2.;

    // from floating fit
    qcd_scale = (vjets_qcd_alpgen_muon_sf+vjets_qcd_alpgen_elec_sf)/2;

    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = (sideband_alpgen_comb_highsb_highm_sf+sideband_alpgen_comb_highsb_highm_sf)/2.;

    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;
 
  }else if(runNum=="mc.alpgen.cont.wtnu.np3.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow \\tau\\nu+3p";
    rnum = 107703;
    prod_tag="e835";
    //xsec = 122.1;
    xsec = 101.96;
    high_met=150;
    tot_nevts = 1009946.0;
    dpd_nevts=tot_nevts;
    evt_weight=1009715.4;
    kfac=1.195;
    eff = 1.;
    boost_sf=(boost_elec_sf+boost_muon_sf)/2;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = (wjets_alpgen_muon_sf+wjets_alpgen_muon_sf)/2.;

    // from floating fit
    qcd_scale = (vjets_qcd_alpgen_muon_sf+vjets_qcd_alpgen_elec_sf)/2;

    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = (sideband_alpgen_comb_highsb_highm_sf+sideband_alpgen_comb_highsb_highm_sf)/2.;

    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;
    
  }else if(runNum=="mc.alpgen.cont.wtnu.np4.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow \\tau\\nu+4p";
    rnum = 107704;
    prod_tag="e835";
    xsec = 25.71;
    high_met=150;
    tot_nevts = 249998.0;
    dpd_nevts=tot_nevts;
    evt_weight=249950.57;
    kfac=1.195;
    eff = 1.;
    boost_sf=(boost_elec_sf+boost_muon_sf)/2;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = (wjets_alpgen_muon_sf+wjets_alpgen_muon_sf)/2.;

    // from floating fit
    qcd_scale = (vjets_qcd_alpgen_muon_sf+vjets_qcd_alpgen_elec_sf)/2;

    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = (sideband_alpgen_comb_highsb_highm_sf+sideband_alpgen_comb_highsb_highm_sf)/2.;

    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;
 
  }else if(runNum=="mc.alpgen.cont.wtnu.np5.pu"){

    sb = "bkgd";
    proc = "W \\rightarrow \\tau\\nu+5p";
    rnum = 107705;
    //xsec = 7.04;
    prod_tag="e835";
    xsec = 7.0;
    high_met=150;
    tot_nevts=65000.0;
    dpd_nevts=tot_nevts;//valid
    evt_weight=64986.44;
    kfac=1.195;
    eff = 1.;
    //boost_sf=0.6634365;
    boost_sf=(boost_elec_sf+boost_muon_sf)/2;

    is_wjets=true;
    is_vjets=true;

    wjets_sf = (wjets_alpgen_muon_sf+wjets_alpgen_muon_sf)/2.;

    // from floating fit
    qcd_scale = (vjets_qcd_alpgen_muon_sf+vjets_qcd_alpgen_elec_sf)/2;
    
    sideband_lowsb_lowm_sf = sideband_alpgen_comb_lowsb_lowm_sf;
    sideband_highsb_lowm_sf = sideband_alpgen_comb_highsb_lowm_sf;
    sideband_lowsb_highm_sf = sideband_alpgen_comb_lowsb_highm_sf;
    sideband_highsb_highm_sf = sideband_alpgen_comb_highsb_highm_sf;

    //wj scale factors
    sideband_lowm_sf = sideband_alpgen_comb_lowm_sf;
    sideband_highm_sf = sideband_alpgen_comb_highm_sf;



    //////////////////////////////////////////////////    
    //single-top
    //////////////////////////////////////////////////

  }else if(runNum=="mc.mcatnlo.st.tchan.enu.pu"){

    rnum=108340;
    sb = "bkgd";
    //proc = "st.tchan.enu.pu";
    proc = "tqb \\rightarrow e\\nu";
    prod_tag="e825";
    xsec = 7.12;//ww
    high_met=150;
    tot_nevts = 299998.0;
    dpd_nevts=tot_nevts;
    evt_weight=177148.92;
    kfac=0.979;
    eff = 1.;

  }else if(runNum=="mc.mcatnlo.st.tchan.tnu.pu"){

    rnum=108342;
    sb = "bkgd";
    proc = "tqb \\rightarrow \\tau\\nu";
    //proc = "st.tchan.tnu.pu";
    prod_tag="e825";
    xsec = 7.10;
    high_met=150;
    tot_nevts = 299999.0;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=176463.27;
    kfac=0.982;
    eff = 1.;

  }else if(runNum=="mc.mcatnlo.st.tchan.unu.pu"){

    rnum=108341;
    sb = "bkgd";
    proc = "tqb \\rightarrow \\mu\\nu";
    //proc = "st.tchan.unu.pu";
    prod_tag="e835";
    xsec = 7.12;
    high_met=150;
    tot_nevts = 299999.0;
    dpd_nevts=tot_nevts;
    evt_weight=176850.0;
    kfac=0.979;
    eff = 1.;


  }else if(runNum=="mc.mcatnlo.st.schan.enu.pu"){

    rnum=108343;
    sb = "bkgd";
    proc = "tb \\rightarrow e\\nu";
    //proc = "st.schan.enu.pu";
    prod_tag="e825";
    xsec = 0.47;//ww
    high_met=150;
    tot_nevts = 299948.0;
    dpd_nevts=tot_nevts;
    evt_weight=253351.72;
    kfac=1.064;
    eff = 1.;

  }else if(runNum=="mc.mcatnlo.st.schan.tnu.pu"){

    rnum=108345;
    sb = "bkgd";
    proc = "tb \\rightarrow \\tau\\nu";
    //proc = "st.schan.tnu.pu";
    prod_tag="e825";
    xsec = 0.47;//ww
    high_met=150;
    tot_nevts = 299899.0;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=253450.26;
    kfac=1.064;
    eff = 1.;

  }else if(runNum=="mc.mcatnlo.st.schan.unu.pu"){

    rnum=108344;
    sb = "bkgd";
    proc = "tb \\rightarrow \\mu\\nu";
    //proc = "st.schan.unu.pu";
    prod_tag="e835";
    xsec = 0.47;//ww
    high_met=150;
    tot_nevts = 299998.0;    
    dpd_nevts=tot_nevts;//valid2
    evt_weight=253534.73;
    kfac=1.064;
    eff = 1.;

  }else if(runNum=="mc.mcatnlo.st.wt.pu"){

    rnum=108346;
    sb = "bkgd";
    //proc = "st.wt.pu";
    proc = "tW \\rightarrow \\ell+X";
    prod_tag="e835";
    xsec = 14.59;//ww
    high_met=150;
    tot_nevts=899694.0;
    dpd_nevts=tot_nevts;
    evt_weight=796798.1;
    kfac=1.079;
    eff = 1.;


    
  }else if(runNum=="mc.alpgen.ww.lnulnu.np0.pu"){

    rnum = 107100;
    sb = "bkgd";
    proc = "pp->WW->l#nul#nu+0p";
    prod_tag="e906";
    xsec = 2.095;//top10
    high_met=150;
    tot_nevts=49992;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=-1;
    kfac=1.21;
    eff=1.;
    
  }else if(runNum=="mc.herwig.ww.pu"){

    rnum = 105985;
    sb = "bkgd";
    proc = "WW \\rightarrow \\ell+X";
    prod_tag="e825";
    xsec = 11.5003;
    high_met=150;
    tot_nevts = 2489244.0;
    dpd_nevts=tot_nevts;
    evt_weight=2488756.0;
    kfac=1.48;
    eff=1.;  //included in xsec (see top twiki)

  }else if(runNum=="mc.herwig.wz.pu"){

    rnum = 105987;
    sb = "bkgd";
    //proc = "pp->WZ->all";
    proc = "WZ \\rightarrow \\ell+X";
    prod_tag="e825";
    xsec = 3.4641;
    high_met=150;
    tot_nevts = 999896.0;
    dpd_nevts=tot_nevts;
    evt_weight=999623.22;
    kfac=1.60;
    eff=1;  //included in xsec (see top twiki)
    
  }else if(runNum=="mc.herwig.zz.pu"){

    rnum = 105986;
    sb = "bkgd";
    //proc = "pp->ZZ->all";
    proc = "ZZ \\rightarrow \\ell+X";
    //xsec = 0.9722;
    prod_tag="e825";
    xsec = 0.9722;
    high_met=150;
    tot_nevts = 249999.0;
    dpd_nevts=tot_nevts;
    evt_weight=249949.24;
    kfac=1.30;
    eff=1; //included in xsec (see top twiki)
    

  }else if(runNum=="mc.alpgen.ww.lnulnu.np1.pu"){

    rnum = 107101;
    sb = "bkgd";
    proc = "pp->WW->l#nul#nu+1p";
    prod_tag="e906";
    xsec = 0.987;//top10
    high_met=150;
    tot_nevts=24997;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=-1;
    kfac=1.21;
    eff=1.;
    

  }else if(runNum=="mc.alpgen.ww.lnulnu.np2.pu"){

    rnum = 107102;
    sb = "bkgd";
    proc = "pp->WW->l#nul#nu+2p";
    prod_tag="e906";
    xsec = 0.441;//top10
    high_met=150;
    tot_nevts=14996;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=-1;
    kfac=1.21;
    eff=1.;
    
  }else if(runNum=="mc.alpgen.ww.lnulnu.np3.pu"){

    rnum = 107103;
    sb = "bkgd";
    proc = "pp->WW->l#nul#nu+3p";
    prod_tag="e906";
    xsec = 0.178;//top10
    high_met=150;
    tot_nevts=9995;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=-1;
    kfac=1.21;
    eff=1.;
    
	
    //////////////////////////////////////////////////
    //Alpgen WZ
    //////////////////////////////////////////////////

    
  }else if(runNum=="mc.alpgen.wz.incl.np0.pu"){

    rnum = 107104;
    sb = "bkgd";
    proc = "pp->WZ->incl+0p";
    prod_tag="e906";
    xsec = 0.664;//top10
    high_met=150;
    tot_nevts=14994;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=-1;
    kfac=1.21;
    eff=1.;
    

  }else if(runNum=="mc.alpgen.wz.incl.np1.pu"){

    rnum = 107105;
    sb = "bkgd";
    proc = "pp->WZ->incl+1p";
    prod_tag="e906";
    xsec = 0.399;//top10
    high_met=150;
    tot_nevts=9998;
    dpd_nevts=tot_nevts;
    evt_weight=-1;//valid2
    kfac=1.21;
    eff=1.;
    

  }else if(runNum=="mc.alpgen.wz.incl.np2.pu"){

    rnum = 107106;
    sb = "bkgd";
    proc = "pp->WZ->incl+2p";
    prod_tag="e906";
    xsec = 0.221;//top10
    high_met=150;
    tot_nevts=4999;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=-1;
    kfac=1.21;
    eff=1.;
    
  }else if(runNum=="mc.alpgen.wz.incl.np3.pu"){

    rnum = 107107;
    sb = "bkgd";
    proc = "pp->WZ->incl+3p";
    prod_tag="e906";
    xsec = 0.093;//top10
    high_met=150;
    tot_nevts=4997;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=-1;
    kfac=1.21;
    eff=1.;

    //////////////////////////////////////////////////
    //Alpgen ZZ
    //////////////////////////////////////////////////  

  }else if(runNum=="mc.alpgen.zz.incl.np0.pu"){

    rnum = 107108;
    sb = "bkgd";
    proc = "pp->ZZ->incl+0p";
    prod_tag="e906";
    xsec = 0.494;//top10
    high_met=150;
    tot_nevts=9994;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=-1;
    kfac=1.21;
    eff=1.;
    

  }else if(runNum=="mc.alpgen.zz.incl.np1.pu"){

    rnum = 107109;
    sb = "bkgd";
    proc = "pp->ZZ->incl+1p";
    prod_tag="e906";
    xsec = 0.0225;//top10
    high_met=150;
    tot_nevts=4499;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=-1;
    kfac=1.21;
    eff=1.;
    

  }else if(runNum=="mc.alpgen.zz.incl.np2.pu"){

    rnum = 107110;
    sb = "bkgd";
    proc = "pp->ZZ->incl+2p";
    prod_tag="e906";
    xsec = 0.088;//top10
    high_met=150;
    tot_nevts=4993;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=-1;
    kfac=1.21;
    eff=1.;
    
  }else if(runNum=="mc.alpgen.zz.incl.np3.pu"){

    rnum = 107111;
    sb = "bkgd";
    proc = "pp->ZZ->incl+3p";
    prod_tag="e906";
    xsec = 0.028;//top10
    high_met=150;
    tot_nevts=2500;
    dpd_nevts=tot_nevts;//valid2
    evt_weight=-1;
    kfac=1.21;
    eff=1.;
    
  }else if(runNum=="mc.mcatnlo.t1.pu"){
    
    rnum = 105200;//tid199666
    sb = "bkgd";
    proc = "t\\bar{t} \\rightarrow \\ell+X";
    prod_tag="e835";
    xsec = 79.01;
    high_met=150;
    //tot_nevts = 7639186;
    //tot_nevts = 12614150.0;
    tot_nevts = 14943835.0;
    dpd_nevts=tot_nevts;
    //evt_weight= 5901485.5;
    //evt_weight= 9750144.36;
    evt_weight= 11550825.58;
    kfac=1.146;
    eff=1.;

  }else if(runNum=="mc.acer.ttbar.pu"){
    
    rnum = 105205;
    sb = "bkgd";
    proc = "t\\bar{t} \\rightarrow \\ell+X (less PS)";
    prod_tag="e1029";
    //xsec = 61.65; //AMI
    xsec = 79.01; //t1
    high_met=150;
    tot_nevts = 999792;//todo
    dpd_nevts=tot_nevts;
    evt_weight=563317.3;
    kfac=1.146;
    eff=1.;
    
  }else if(runNum=="mc.acer.ttbar.lessps.pu"){
    
    rnum = 117210;
    sb = "bkgd";
    proc = "t\\bar{t} \\rightarrow \\ell+X (less PS)";
    prod_tag="e1029";
    //xsec = 61.65; //AMI
    xsec = 79.01; //t1
    high_met=150;
    tot_nevts = 999998.0;
    dpd_nevts=tot_nevts;
    evt_weight=999781.9;
    kfac=1.146;
    eff=1.;

  }else if(runNum=="mc.acer.ttbar.moreps.pu"){
    
    rnum = 117209;
    sb = "bkgd";
    proc = "t\\bar{t} \\rightarrow \\ell+X (more PS)";
    prod_tag="e1029";
    //xsec = 61.96; //ami
    xsec = 79.01; //t1
    high_met=150;
    tot_nevts = 999998.0;
    dpd_nevts=tot_nevts;
    evt_weight=1000477.7;
    kfac=1.146;
    eff=1.;

  }else if(runNum=="mc.mcatnlo.ttbar.fullhad.pu"){//not used
    
    rnum = 105204;//tid199666
    sb = "bkgd";
    proc = "tT (full had))";
    prod_tag="e906";
    xsec = 160.79;//top10
    high_met=150;
    tot_nevts=1000000;
    dpd_nevts=1000000;//check
    evt_weight=-1;
    kfac=1.;
    eff=0.4;


    //////////////////////////////////////////////////
    //////////////////////////////////////////////////
    //////////////////////////////////////////////////
    //////////////////////////////////////////////////
    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

  }else{
    std::cout<<"UNKNOWN RUN ID"<<std::endl;
  }


  std::cout<<"wwXSec initialized for run #: "
	   <<rnum
	   <<", process: "
	   <<proc
	   <<std::endl;

}

int wwXSec::RunNum(){
  return rnum;
}

string wwXSec::SigOrBkgd(){
  return sb;
}

string wwXSec::Proc(){
  return proc;
}

string wwXSec::ProductionTag(){
  return prod_tag;
}

string wwXSec::RunDir(){
  return rdir;
}


// Nexp method that uses hist_name to determine control region and scaling
double wwXSec::Nexp(double invPB,string hist_name,bool is_sys){
  double cur_sf=1.;

  bool is_sig_ctrl = (hist_name.find("ctrl_lowm")!=string::npos ||
		      hist_name.find("ctrl_highm")!=string::npos ||

		      hist_name.find("sig_lowm")!=string::npos ||
		      hist_name.find("sig_highm")!=string::npos);

  bool is_sideband = (hist_name.find("lowsb")!=string::npos ||
		      hist_name.find("highsb")!=string::npos);


  //bool is_sig = (sb=="sig");
  
  if(is_sig_ctrl){// signal region or signal control region

    // is lowm/highm control region.
    // NOTE: if sample is not wjets, sideband_lowm_sf and sideband_highm_sf == 1
    // --> only scales for sig/ctrl_lowm/highm wjets samples
    
    if(hist_name.find("highm")!=string::npos){ // highm
      cur_sf=sideband_highm_sf;
    }else if(hist_name.find("lowm")!=string::npos){ //lowm
      cur_sf=sideband_lowm_sf;
    }

    
  }else if(is_sideband){

    // is either lowm/highm sideband

    if(hist_name.find("lowsb")!=string::npos){ // lowsb

      if(hist_name.find("lowm")!=string::npos){ // lowm
	cur_sf = sideband_lowsb_lowm_sf;
      }else{ // highm
	cur_sf = sideband_lowsb_highm_sf;
      }
    }else{ // highsb

      if(hist_name.find("lowm")!=string::npos){ // lowm
	cur_sf = sideband_highsb_lowm_sf;
      }else{ // highm
	cur_sf = sideband_highsb_highm_sf;
      }
    }
  }else if(is_sys){//all histos are either lowm or highm, apply sideband scales!

    //cout<<"Merging Systematic! "<<hist_name<<endl;
    if(hist_name.find("lowm")!=string::npos){ // lowm
      cur_sf = sideband_lowm_sf; 
    }else if(hist_name.find("highm")!=string::npos){ // highm
      cur_sf = sideband_highm_sf;
    }else{
      cur_sf=1.;
    }
  }
  //if(is_sig) cout<<"cur_sf: "<<cur_sf<<endl;
  return xsec*invPB*kfac*cur_sf*eff;
}
double wwXSec::GenNevt(){
  return tot_nevts;
}
double wwXSec::Nevt(){
  if(evt_weight<0){

    return tot_nevts;
  }else{

    return evt_weight;
  }
  
  //return dpd_nevts;
}

double wwXSec::HighMET(){
  return high_met;
}

double wwXSec::Efficiency(){
  return eff;
}
double wwXSec::Filter_Efficiency(){
  return (dpd_nevts*1.)/(tot_nevts*1.);
}

double wwXSec::Scale(){
  return qcd_scale;
}
double wwXSec::XSec(){
  return xsec;
}
double wwXSec::KFactor(){
  return kfac;
}
double wwXSec::Sow(){
  return evt_weight;
}
bool wwXSec::IsQCD(){
  return is_qcd;
}
bool wwXSec::IsWJets(){
  return is_wjets;
}
bool wwXSec::IsVJets(){
  return is_vjets;
}

double wwXSec::GetScale(float lumi, string hist_name,bool is_sys){

  double curScale = 1.;

  // QCD SCALING
  if((this->IsQCD() || this->IsVJets()) && use_qcd_sf){

    curScale *= qcd_scale;
  }

  // CROSS SECTION SCALING
  if(!this->IsQCD()){// !QCD

    // Nexp determines control region and scaling
    double curNexp = this->Nexp(lumi,hist_name,is_sys);

    //if(this->IsWJets()) cout<<this->Proc()<<", "<<curNexp<<endl;
    double curNevt = this->Nevt();

    double tmpScale = (curNexp>0 && curNevt>0) ? curNexp/curNevt : 1.;

    curScale*=tmpScale;
    
    if(this->IsWJets() && use_wjets_sf){
      curScale*=wjets_sf;

    }
    //if(this->IsWJets()) cout<<"nExp: "<<curNexp<<", nEvt: "<<curNevt<<" -> Scale: "<<curScale<<endl;
  }


  //cout<<"Scaling: "<<curScale<<endl;
  return curScale;
  
}
double wwXSec::GetLocalScale(float lumi,float local_sf,string hist_name,bool is_sys){

  double curScale = 1.;

  if(this->IsQCD() && use_qcd_sf){

    curScale = qcd_scale;


  }else{// !QCD

    // Nexp determines control region and scaling
    double curNexp = this->Nexp(lumi,hist_name,is_sys);
    //if(this->IsWJets()) cout<<this->Proc()<<", "<<curNexp<<endl;
    //double curNevt = this->Nevt();
    double curNevt = this->GenNevt()*local_sf;

    curScale = (curNexp>0 && curNevt>0) ? curNexp/curNevt : 1.;
    
    if(this->IsWJets() && use_wjets_sf){
      curScale*=wjets_sf;

    }
    //if(this->IsWJets()) cout<<"nExp: "<<curNexp<<", nEvt: "<<curNevt<<" -> Scale: "<<curScale<<endl;
  }
  return curScale;
  
}

