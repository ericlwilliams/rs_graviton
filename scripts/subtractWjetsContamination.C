#include "neg_hadd.C"

// replaces qcd plot files in /plots/gww_plots/ with files with wjets contamination removed

void subtractWjetsContamination(string proc="gww"){

  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"Subtracting W+jets contamination from QCD"<<endl;
  // string qcd_elec_loc = "../plots/gww_plots/qcd.elec.pu.plot.root";
  // string new_qcd_elec_loc = "../plots/gww_plots/qcd.elec.alpgen.pu.plot.root";//write to this folder

  // string qcd_muon_loc = "../plots/gww_plots/qcd.muon.pu.plot.root";
  // string new_qcd_muon_loc = "../plots/gww_plots/qcd.muon.alpgen.pu.plot.root";//write to this folder

  // string wjets_cont_loc = "../plots/gww_plots/merged/mc.alpgen.cont.wjets.plot.root";

  string plot_loc = "../plots/";
  string qcd_elec_loc = plot_loc;
  string new_qcd_elec_loc = plot_loc;

  string qcd_muon_loc = plot_loc;
  string new_qcd_muon_loc = plot_loc;

  string wjets_cont_loc = plot_loc;
  
  if(proc=="gww"){
    qcd_elec_loc+="gww_plots/qcd.elec.pu.plot.root";
    new_qcd_elec_loc+="gww_plots/qcd.elec.alpgen.pu.plot.root";
    qcd_muon_loc+="gww_plots/qcd.muon.pu.plot.root";
    new_qcd_muon_loc+="gww_plots/qcd.muon.alpgen.pu.plot.root";

    wjets_cont_loc+="gww_plots/merged/mc.alpgen.cont.wjets.plot.root";

  }else if(proc=="ctrl"){
    qcd_elec_loc+="ctrl_plots/qcd.elec.pu.ctrl.plot.root";
    new_qcd_elec_loc+="ctrl_plots/qcd.elec.alpgen.pu.ctrl.plot.root";
    qcd_muon_loc+="ctrl_plots/qcd.muon.pu.ctrl.plot.root";
    new_qcd_muon_loc+="ctrl_plots/qcd.muon.alpgen.pu.ctrl.plot.root";

    wjets_cont_loc+="ctrl_plots/merged/mc.alpgen.cont.wjets.ctrl.plot.root";

  }else if(proc=="systematics"){

    qcd_elec_loc+="systematics_plots/qcd.elec.pu.plot.root";
    new_qcd_elec_loc+="systematics_plots/qcd.elec.alpgen.pu.plot.root";
    qcd_muon_loc+="systematics_plots/qcd.muon.pu.plot.root";
    new_qcd_muon_loc+="systematics_plots/qcd.muon.alpgen.pu.plot.root";

    wjets_cont_loc+="systematics_plots/merged/mc.alpgen.cont.wjets.systematics.plot.root";

  }else{
    cout<<"!! Unknown process to subtract QCD: "<<proc<<endl;
  }
  //elec
  neg_hadd(qcd_elec_loc.c_str(),wjets_cont_loc.c_str(),new_qcd_elec_loc.c_str());
  neg_hadd(qcd_muon_loc.c_str(),wjets_cont_loc.c_str(),new_qcd_muon_loc.c_str());


  //gROOT->ProcessLine(".q");
}
