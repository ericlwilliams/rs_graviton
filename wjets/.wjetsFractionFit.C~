#include <algorithm>
#include <TFractionFitter>
#include <TObjArray>
#include <TH1>
#include <vector>
#include <utility>
#include <iostream>

vector<std::pair<float,float>>* qcdFractionFit(string generator="alpgen",string template_distribution="lep_met_mt"){

  
  string data_loc = "../plots/gww_plots/merged/data.lnuj.plot.root";
  TFile* data_file = (TFile*) TFile::Open(data_loc.c_str());

  string data_elec_hist = "all/h_elec_"+template_distribution;
  TH1F* data_elec = (TH1F*) data_file->Get(data_elec_hist.c_str());
  string data_muon_hist = "all/h_muon_"+template_distribution;
  TH1F* data_muon = (TH1F*) data_file->Get(data_muon_hist.c_str());


  const int nBkgds = 6;
  string bkgd_list[nBkgds] = {"qcd.elec."+generator,
			      "qcd.muon."+generator,
			      "mc."+generator+".wjets",
			      "mc."+generator+".zjets",
			      "mc.herwig.vv","mc.mcatnlo.top"};
  // const int nBkgds = 14;
  // string bkgd_list[nBkgds] = {"qcd.elec.alpgen","qcd.elec.sherpa","qcd.elec.pythia",
  // 			      "qcd.muon.alpgen","qcd.muon.sherpa","qcd.muon.pythia",
  // 			      "mc.alpgen.wjets","mc.sherpa.wjets","mc.pythia.wjets",
  // 			      "mc.alpgen.zjets","mc.sherpa.zjets","mc.pythia.zjets",
  // 			      "mc.herwig.vv","mc.mcatnlo.top"};


  TH1F* elec_wjets;
  TH1F* elec_zjets;
  TH1F* elec_qcd;
  TH1F* elec_backgrounds;

  TH1F* muon_wjets;
  TH1F* muon_zjets;
  TH1F* muon_qcd;
  TH1F* muon_backgrounds;

  bool background_init=false;
  for(int s=0;s<nBkgds;s++){

    string cur_bkgd = bkgd_list[s];

    string cur_file;
    if(cur_bkgd.find("qcd")!=string::npos){
      cur_file = "../plots/gww_plots/"+cur_bkgd;
      cur_file+=".pu.plot.root";
    }else{
      cur_file = "../plots/gww_plots/merged/"+bkgd_list[s];
      cur_file+=".plot.root";
    }
    cout<<"Loading :"<<cur_file<<endl;
    TFile* tmpFile= (TFile*) TFile::Open(cur_file.c_str());

    string elec_hist_name = "all/h_elec_"+template_distribution;
    TH1F* elec_hist = (TH1F*) tmpFile->Get(elec_hist_name.c_str());
    elec_hist->SetDirectory(0);
    string muon_hist_name = "all/h_muon_"+template_distribution;
    TH1F* muon_hist = (TH1F*) tmpFile->Get(muon_hist_name.c_str());
    muon_hist->SetDirectory(0);
    tmpFile->Close();

    if(!elec_hist || !muon_hist){
      cout<<"No histogram "<<elec_hist_name<<", in "<<cur_file<<endl;
      cout<<"No histogram "<<muon_hist_name<<", in "<<cur_file<<endl;
      exit(-143);
    }
    cout<<"adding " <<cur_bkgd<<endl;

    if(cur_bkgd.find("qcd")!=string::npos){

      if(cur_bkgd.find("elec")!=string::npos){
	elec_qcd = elec_hist;
	//elec_qcd->Add(muon_hist);//for qcd.elec... add h_all_elec + h_all_muon
      }else if(cur_bkgd.find("muon")!=string::npos){
	muon_qcd = muon_hist;
	//muon_qcd->Add(elec_hist);
      }

    }else if(cur_bkgd.find("wjets")!=string::npos){

	elec_wjets = elec_hist;
	muon_wjets = muon_hist;

    }else if(cur_bkgd.find("zjets")!=string::npos){
	elec_zjets = elec_hist;
	muon_zjets = muon_hist;
    }else{

      if(background_init){
	elec_backgrounds->Add((TH1F*) elec_hist);
	muon_backgrounds->Add((TH1F*) muon_hist);
      }else{
	elec_backgrounds= elec_hist;
	muon_backgrounds= muon_hist;
	background_init=true;
      }
    }
    //delete elec_hist;
    //delete muon_hist;
  }

  // elec
  TH1F* elec_vjets = (TH1F*) elec_wjets;
  elec_vjets->Add(elec_zjets);

  // Get relative fraction of non-vjets background (to fix in fit)

  float n_data_elec = data_elec->Integral();
  float n_elec_vjets = elec_vjets->Integral();
  float rel_error_elec_vjets = 1./sqrt(n_elec_vjets);
  float n_elec_qcd = elec_qcd->Integral();
  float rel_error_elec_qcd = 1./sqrt(n_elec_qcd);
  float n_elec_other = elec_backgrounds->Integral();

  float fraction_elec_other = n_elec_other / n_data_elec;
  float fraction_elec_vjets = n_elec_vjets / n_data_elec;
  float fraction_elec_qcd = n_elec_qcd / n_data_elec;
  
  
  TObjArray *mc_elec = new TObjArray();
  mc_elec->Add(elec_qcd); // qcd - 0
  mc_elec->Add(elec_vjets); // vjets - 1
  //elec_backgrounds->Scale(9999999999);//to reduce bin fluctuations
  mc_elec->Add(elec_backgrounds); // other backgrounds -2
  
  
  TFractionFitter* fit_elec = new TFractionFitter(data_elec,mc_elec);
  fit_elec->Constrain(1,0.0,1.0);
  fit_elec->Constrain(2,0.0,2.0);
  fit_elec->Constrain(3,fraction_elec_other-0.00001,fraction_elec_other+0.00001);

  
  Int_t status_elec = fit_elec->Fit();


  double qcd_elec_fit_value=1.;
  double qcd_elec_fit_error=0.;
  double vjets_elec_fit_value=1;
  double vjets_elec_fit_error=0.;
  double other_elec_fit_value=1;
  double other_elec_fit_error=0.;    
  double qcd_elec_rel_error=0.;
  double vjets_elec_rel_error=0;
  float qcd_comb_elec_rel_error=0;
  float vjets_comb_elec_rel_error=0;
  
  if(status_elec == 0){

    // TH1F* result_elec = (TH1F*) fit_elec->GetPlot();
    // data_elec->Draw("Ep");
    // result_elec->Draw("same");
    
    fit_elec->GetResult(0,qcd_elec_fit_value,qcd_elec_fit_error);
    fit_elec->GetResult(1,vjets_elec_fit_value,vjets_elec_fit_error);
    fit_elec->GetResult(2,other_elec_fit_value,other_elec_fit_error);

    //////////////////////////////////////////////////
    // Calculate scale factors
    ////////////////////////////////////////////////// 

    // Relative Errors
    qcd_elec_rel_error = qcd_elec_fit_error/qcd_elec_fit_value;
    vjets_elec_rel_error = vjets_elec_fit_error/vjets_elec_fit_value;

    //Combining errors
    qcd_comb_elec_rel_error = sqrt(pow(qcd_elec_rel_error,2.)+pow(rel_error_elec_qcd,2.));
    vjets_comb_elec_rel_error = sqrt(pow(vjets_elec_rel_error,2.)+pow(rel_error_elec_vjets,2.));
    
    cout<<"-- from fit --"<<endl;
    cout<<"qcd "<<qcd_elec_fit_value<<" #pm "<<qcd_elec_fit_error<<endl;
    cout<<"vjets "<<vjets_elec_fit_value<<" #pm "<<vjets_elec_fit_error<<endl;
    cout<<"other "<<other_elec_fit_value<<" #pm "<<other_elec_fit_error<<endl;
    cout<<endl;
    cout<<"-- scale factors --"<<endl;
    cout<<"elec_qcd_sf: "<<(qcd_elec_fit_value/fraction_elec_qcd)
	<<" #pm (1+-"<<qcd_comb_elec_rel_error<<") "<<endl;
    cout<<"elec_vjets_sf: "<<vjets_elec_fit_value/fraction_elec_vjets
	<<" #pm (1+-"<<vjets_comb_elec_rel_error<<") "<<endl;
        
  }else{
    cout<<"fit no good status_elec: "<<status_elec<<endl;
  }

  // muon  
  TH1F* muon_vjets = muon_wjets;
  muon_vjets->Add(muon_zjets);

  // Get relative fraction of non-vjets background (to fix in fit)

  float n_data_muon = data_muon->Integral();
  float n_muon_vjets = muon_vjets->Integral();
  float rel_error_muon_vjets = 1./sqrt(n_muon_vjets);
  float n_muon_qcd = muon_qcd->Integral();
  float rel_error_muon_qcd = 1./sqrt(n_muon_qcd);
  float n_muon_other = muon_backgrounds->Integral();

  float fraction_muon_other = n_muon_other / n_data_muon;
  float fraction_muon_vjets = n_muon_vjets / n_data_muon;
  float fraction_muon_qcd = n_muon_qcd / n_data_muon;
  
  
  TObjArray *mc_muon = new TObjArray();
  mc_muon->Add(muon_qcd); // qcd - 0
  mc_muon->Add(muon_vjets); // vjets - 1
  //muon_backgrounds->Scale(9999999999);//to reduce bin fluctuations
  mc_muon->Add(muon_backgrounds); // other backgrounds -2
  
  
  TFractionFitter* fit_muon = new TFractionFitter(data_muon,mc_muon);
  fit_muon->Constrain(1,0.0,1.0);
  fit_muon->Constrain(2,0.0,2.0);
  fit_muon->Constrain(3,fraction_muon_other-0.00001,fraction_muon_other+0.00001);

  
  Int_t status_muon = fit_muon->Fit();

  double qcd_muon_fit_value=1.;
  double qcd_muon_fit_error=0.;
  double vjets_muon_fit_value=1;
  double vjets_muon_fit_error=0.;
  double other_muon_fit_value=1;
  double other_muon_fit_error=0.;    
  double qcd_muon_rel_error=0.;
  double vjets_muon_rel_error=0;
  float qcd_comb_muon_rel_error=0;
  float vjets_comb_muon_rel_error=0;
  
  if(status_muon == 0){

    // TH1F* result_muon = (TH1F*) fit_muon->GetPlot();
    // data_muon->Draw("Ep");
    // result_muon->Draw("same");

    fit_muon->GetResult(0,qcd_muon_fit_value,qcd_muon_fit_error);
    fit_muon->GetResult(1,vjets_muon_fit_value,vjets_muon_fit_error);
    fit_muon->GetResult(2,other_muon_fit_value,other_muon_fit_error);

    //////////////////////////////////////////////////
    // Calculate scale factors
    ////////////////////////////////////////////////// 

    // Relative Errors
    qcd_muon_rel_error = qcd_muon_fit_error/qcd_muon_fit_value;
    vjets_muon_rel_error = vjets_muon_fit_error/vjets_muon_fit_value;

    //Combining errors
    qcd_comb_muon_rel_error = sqrt(pow(qcd_muon_rel_error,2.)+pow(rel_error_muon_qcd,2.));
    vjets_comb_muon_rel_error = sqrt(pow(vjets_muon_rel_error,2.)+pow(rel_error_muon_vjets,2.));
    
    cout<<"-- from fit --"<<endl;
    cout<<"qcd "<<qcd_muon_fit_value<<" #pm "<<qcd_muon_fit_error<<endl;
    cout<<"vjets "<<vjets_muon_fit_value<<" #pm "<<vjets_muon_fit_error<<endl;
    cout<<"other "<<other_muon_fit_value<<" #pm "<<other_muon_fit_error<<endl;
    cout<<endl;
    cout<<"-- scale factors --"<<endl;
    cout<<"muon_qcd_sf: "<<(qcd_muon_fit_value/fraction_muon_qcd)
	<<" #pm (1+-"<<qcd_comb_muon_rel_error<<") "<<endl;
    cout<<"muon_vjets_sf: "<<vjets_muon_fit_value/fraction_muon_vjets
	<<" #pm (1+-"<<vjets_comb_muon_rel_error<<") "<<endl;
        
  }else{
    cout<<"fit no good status_muon: "<<status_muon<<endl;
  }

  if(status_muon == 0 && status_elec == 0){
    cout<<endl;
    cout<<endl;
    cout<<"-- scale factors --"<<endl;
    cout<<"elec_qcd_sf: "<<(qcd_elec_fit_value/fraction_elec_qcd)
	<<" #pm (1+-"<<qcd_comb_elec_rel_error<<") "<<endl;
    cout<<"elec_vjets_sf: "<<vjets_elec_fit_value/fraction_elec_vjets
	<<" #pm (1+-"<<vjets_comb_elec_rel_error<<") "<<endl;
    cout<<"muon_qcd_sf: "<<(qcd_muon_fit_value/fraction_muon_qcd)
	<<" #pm (1+-"<<qcd_comb_muon_rel_error<<") "<<endl;
    cout<<"muon_vjets_sf: "<<vjets_muon_fit_value/fraction_muon_vjets
	<<" #pm (1+-"<<vjets_comb_muon_rel_error<<") "<<endl;
    
  }

  vector<std::pair<float,float> >*  return_vector = new vector<std::pair<float,float> >;
  pair <float,float> elec_qcd_sf((qcd_elec_fit_value/fraction_elec_qcd),qcd_comb_elec_rel_error);
  return_vector->push_back(elec_qcd_sf);
  pair <float,float> muon_qcd_sf((qcd_muon_fit_value/fraction_muon_qcd),qcd_comb_muon_rel_error);
  return_vector->push_back(muon_qcd_sf);
  pair <float,float> elec_vjets_sf((vjets_elec_fit_value/fraction_elec_vjets),vjets_comb_elec_rel_error);
  return_vector->push_back(elec_vjets_sf);
  pair <float,float> muon_vjets_sf((vjets_muon_fit_value/fraction_muon_vjets),vjets_comb_muon_rel_error);
  return_vector->push_back(muon_vjets_sf);

  data_file->Close();
  return return_vector;
}
