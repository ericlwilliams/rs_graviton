void runTruthSignalPlots(){

  // kkg m1000
  TChain*  kkg_m1000_chain =new TChain("physics");
  string kkg_m1000_toload = "../files/mc11_7TeV.145614.CalchepPythia_KKGravitonWW_lvjj_m1000.merge.NTUP_SMWZ.e1131_a131_s1353_a145_r2993_p833/NTUP_SMWZ.751205._00000%i.root.1";

  for(int i=1;i<3;i++){
    string cur_kkg_m1000_toload = Form(kkg_m1000_toload.c_str(),i);
    kkg_m1000_chain->Add(cur_kkg_m1000_toload.c_str());
  }
  string kkg_m1000_out_name = "kkg_m1000_truth_plots.root";
  cout<<"-"<<endl;
  cout<<"Running kkG M=1000 GeV"<<endl;
  cout<<"-"<<endl;
  kkg_m1000_chain->Process("../src/makeTruthSignalPlots.C+",kkg_m1000_out_name.c_str());


  // kkg m500
  TChain*  kkg_m500_chain =new TChain("physics");
  string kkg_m500_toload = "../files/mc11_7TeV.145609.CalchepPythia_KKGravitonWW_lvjj_m500.merge.NTUP_SMWZ.e1131_a131_s1353_a145_r2993_p833/NTUP_SMWZ.752115._00000%i.root.1";

  for(int i=1;i<3;i++){
    string cur_kkg_m500_toload = Form(kkg_m500_toload.c_str(),i);
    kkg_m500_chain->Add(cur_kkg_m500_toload.c_str());
  }
  string kkg_m500_out_name = "kkg_m500_truth_plots.root";
  cout<<"-"<<endl;
  cout<<"Running kkG M=500 GeV"<<endl;
  cout<<"-"<<endl;
  kkg_m500_chain->Process("../src/makeTruthSignalPlots.C+",kkg_m500_out_name.c_str());


  
  // m500
  TChain*  rsg_m500_chain =new TChain("physics");
  string rsg_m500_toload = "../files/mc11_7TeV.115724.PythiaGravitonWW_lvjj_m500_kMpl0_1.merge.NTUP_SMWZ.e972_s1310_s1300_r3043_r2993_p833/NTUP_SMWZ.653971._00000%i.root.1";

  for(int i=1;i<4;i++){
    string cur_rsg_m500_toload = Form(rsg_m500_toload.c_str(),i);
    rsg_m500_chain->Add(cur_rsg_m500_toload.c_str());
  }
  string rsg_m500_out_name = "rsg_m500_truth_plots.root";
  cout<<"-"<<endl;
  cout<<"Running G* M=500 GeV"<<endl;
  cout<<"-"<<endl;
  rsg_m500_chain->Process("../src/makeTruthSignalPlots.C+",rsg_m500_out_name.c_str());

  // m1000
  TChain*  rsg_m1000_chain =new TChain("physics");
  string rsg_m1000_toload = "../files/mc11_7TeV.115726.PythiaGravitonWW_lvjj_m1000_kMpl0_1.merge.NTUP_SMWZ.e972_s1310_s1300_r3043_r2993_p833/NTUP_SMWZ.650893._00000%i.root.1";

  for(int i=1;i<4;i++){
    string cur_rsg_m1000_toload = Form(rsg_m1000_toload.c_str(),i);
    rsg_m1000_chain->Add(cur_rsg_m1000_toload.c_str());
  }
  string rsg_m1000_out_name = "rsg_m1000_truth_plots.root";
  cout<<"-"<<endl;
  cout<<"Running G* M=1000 GeV"<<endl;
  cout<<"-"<<endl;
  rsg_m1000_chain->Process("../src/makeTruthSignalPlots.C+",rsg_m1000_out_name.c_str());


  // wprime_m500
  TChain*  wprime_m500_chain =new TChain("physics");
  string wprime_m500_toload = "../files/mc11_7TeV.105708.PythiaWprime500_WZ_lvqq.merge.NTUP_SMWZ.e972_s1310_s1300_r3043_r2993_p833/NTUP_SMWZ.661477._000001.root.1";

  wprime_m500_chain->Add(wprime_m500_toload.c_str());

  string wprime_m500_out_name = "wprime_m500_truth_plots.root";
  cout<<"-"<<endl;
  cout<<"Running W' M=500 GeV"<<endl;
  cout<<"-"<<endl;
  wprime_m500_chain->Process("../src/makeTruthSignalPlots.C+",wprime_m500_out_name.c_str());



  // wprime_m1000
  TChain*  wprime_m1000_chain =new TChain("physics");
  string wprime_m1000_toload = "../files/mc11_7TeV.105709.PythiaWprime1000_WZ_lvqq.merge.NTUP_SMWZ.e1006_s1372_s1370_r3043_r2993_p833/NTUP_SMWZ.653962._000001.root.1";

  wprime_m1000_chain->Add(wprime_m1000_toload.c_str());

  string wprime_m1000_out_name = "wprime_m1000_truth_plots.root";
  cout<<"-"<<endl;
  cout<<"Running W' M=1000 GeV"<<endl;
  cout<<"-"<<endl;
  wprime_m1000_chain->Process("../src/makeTruthSignalPlots.C+",wprime_m1000_out_name.c_str());







  gROOT->ProcessLine(".q");
  return;


}
