#include <vector>
#include <TGraph>
void runSignalAcceptance(){

  gStyle->SetPadTopMargin(0.05);
  gStyle->SetPadRightMargin(0.05);
  
  const int nProcs=2;
  const string procs[nProcs] = {"elec","muon"};
  
  string file_loc = "/Users/elw/analy/lvjj/plots/ctrl_plots/";
  string file_end = ".ctrl.plot.root";

  //////////////////////////////////////////////////
  // Load Scaled Backgrounds
  //////////////////////////////////////////////////
  
  string alpgen_wjets_loc = file_loc+"merged/mc.alpgen.wjets"+file_end;
  string vv_loc = file_loc+"merged/mc.herwig.vv"+file_end;
  string alpgen_qcd_loc = file_loc+"merged/qcd.alpgen"+file_end;
  string top_loc = file_loc+"merged/mc.mcatnlo.top"+file_end;  
  string alpgen_zjets_loc = file_loc+"merged/mc.alpgen.zjets"+file_end;

  TFile* alpgen_wjets = (TFile*) TFile::Open(alpgen_wjets_loc.c_str(),"READ");
  TFile* top = (TFile*) TFile::Open(top_loc.c_str(),"READ");
  TFile* alpgen_qcd = (TFile*) TFile::Open(alpgen_qcd_loc.c_str(),"READ");
  TFile* vv = (TFile*) TFile::Open(vv_loc.c_str(),"READ");
  TFile* alpgen_zjets = (TFile*) TFile::Open(alpgen_zjets_loc.c_str(),"READ");

  //////////////////////////////////////////////////
  // Signals
  ////////////////////////////////////////////////// 

  // RSG
  const int n_rsg_samples=5;
  TFile* rsg_samples[n_rsg_samples];
  string rsg_masses[n_rsg_samples] = {"m500","m750","m1000","m1250","m1500"};
  float v_rsg_masses[n_rsg_samples] = {500.,750.,1000.,1250.,1500};
  for(int r=0;r<n_rsg_samples;r++){
    string rsg_loc = file_loc+"merged/mc.rsg."+rsg_masses[r]+".kmpl0_1"+file_end;
    rsg_samples[r] = (TFile*) TFile::Open(rsg_loc.c_str(),"READ");
  }

  //  wprime
  const int n_wprime_samples=11;
  TFile* wprime_samples[n_wprime_samples];
  string wprime_masses[n_wprime_samples] =
    {"m500","m600","m700","m800","m900","m1000",
     "m1100","m1200","m1300","m1400","m1500"};
  float v_wprime_masses[n_wprime_samples] =
    {500.,600.,700.,800.,900.,1000.,1100.,1200.,1300.,1400.,1500.};

  for(int r=0;r<n_wprime_samples;r++){
    string wprime_loc = file_loc+"merged/mc.wprime.wz."+wprime_masses[r]+file_end;
    wprime_samples[r] = (TFile*) TFile::Open(wprime_loc.c_str(),"READ");
  }

  TH1F* h_rsg_ps[n_rsg_samples][nProcs];
  TH1F* h_rsg_highpt[n_rsg_samples][nProcs];
  TH1F* h_rsg_sig[n_rsg_samples][nProcs];
  TH1F* h_rsg_jet_boost[n_rsg_samples][nProcs];
  
  TH1F* h_wprime_ps[n_wprime_samples][nProcs];
  TH1F* h_wprime_highpt[n_wprime_samples][nProcs];
  TH1F* h_wprime_sig[n_wprime_samples][nProcs];
  TH1F* h_wprime_jet_boost[n_wprime_samples][nProcs];

  TH1F* h_bkgd_ps[nProcs];// preselected
  TH1F* h_bkgd_highpt[nProcs];// pt bosons > 200
  TH1F* h_bkgd_sig[nProcs]; // w/ dijet mass
  TH1F* h_bkgd_jet_boost[nProcs]; // w/ dijet mass
  
  for(int p=0;p<nProcs;p++){
    string ps_name = "h_sig_highm_"+procs[p]+"_nocut_evt_n";
    h_bkgd_ps[p] = (TH1F*) alpgen_wjets->Get(ps_name.c_str());
    ((TH1F*) h_bkgd_ps[p])->Add((TH1F*) alpgen_qcd->Get(ps_name.c_str()));
    ((TH1F*) h_bkgd_ps[p])->Add((TH1F*) alpgen_zjets->Get(ps_name.c_str()));
    ((TH1F*) h_bkgd_ps[p])->Add((TH1F*) top->Get(ps_name.c_str()));
    ((TH1F*) h_bkgd_ps[p])->Add((TH1F*) vv->Get(ps_name.c_str()));

    
    string highpt_name = "h_sig_highm_"+procs[p]+"_dijet_pt_evt_n";
    h_bkgd_highpt[p] = (TH1F*) alpgen_wjets->Get(highpt_name.c_str());
    ((TH1F*) h_bkgd_highpt[p])->Add((TH1F*) alpgen_qcd->Get(highpt_name.c_str()));
    ((TH1F*) h_bkgd_highpt[p])->Add((TH1F*) alpgen_zjets->Get(highpt_name.c_str()));
    ((TH1F*) h_bkgd_highpt[p])->Add((TH1F*) top->Get(highpt_name.c_str()));
    ((TH1F*) h_bkgd_highpt[p])->Add((TH1F*) vv->Get(highpt_name.c_str()));

    string sig_name = "h_sig_highm_"+procs[p]+"_dijet_m_evt_n";
    h_bkgd_sig[p] = (TH1F*) alpgen_wjets->Get(sig_name.c_str());
    ((TH1F*) h_bkgd_sig[p])->Add((TH1F*) alpgen_qcd->Get(sig_name.c_str()));
    ((TH1F*) h_bkgd_sig[p])->Add((TH1F*) alpgen_zjets->Get(sig_name.c_str()));
    ((TH1F*) h_bkgd_sig[p])->Add((TH1F*) top->Get(sig_name.c_str()));
    ((TH1F*) h_bkgd_sig[p])->Add((TH1F*) vv->Get(sig_name.c_str()));

    string jet_boost_name = "h_sig_jet_boost_"+procs[p]+"_lep_met_jet_mt_evt_n";
    h_bkgd_jet_boost[p] = (TH1F*) alpgen_wjets->Get(jet_boost_name.c_str());
    ((TH1F*) h_bkgd_jet_boost[p])->Add((TH1F*) alpgen_qcd->Get(jet_boost_name.c_str()));
    ((TH1F*) h_bkgd_jet_boost[p])->Add((TH1F*) alpgen_zjets->Get(jet_boost_name.c_str()));
    ((TH1F*) h_bkgd_jet_boost[p])->Add((TH1F*) top->Get(jet_boost_name.c_str()));
    ((TH1F*) h_bkgd_jet_boost[p])->Add((TH1F*) vv->Get(jet_boost_name.c_str()));


    //rsg
    for(int r=0;r<n_rsg_samples;r++){
      h_rsg_ps[r][p] = (TH1F*) ((TFile*) rsg_samples[r])->Get(ps_name.c_str());
      h_rsg_highpt[r][p] = (TH1F*) ((TFile*) rsg_samples[r])->Get(highpt_name.c_str());
      h_rsg_sig[r][p] = (TH1F*) ((TFile*) rsg_samples[r])->Get(sig_name.c_str());
      h_rsg_jet_boost[r][p] = (TH1F*) ((TFile*) rsg_samples[r])->Get(jet_boost_name.c_str());
    }

    //wprime
    for(int r=0;r<n_wprime_samples;r++){
      h_wprime_ps[r][p] = (TH1F*) ((TFile*) wprime_samples[r])->Get(ps_name.c_str());
      h_wprime_highpt[r][p] = (TH1F*) ((TFile*) wprime_samples[r])->Get(highpt_name.c_str());
      h_wprime_sig[r][p] = (TH1F*) ((TFile*) wprime_samples[r])->Get(sig_name.c_str());
      h_wprime_jet_boost[r][p] = (TH1F*) ((TFile*) wprime_samples[r])->Get(jet_boost_name.c_str());
    }
  }// background and signals loaded


  // rsg
  float rsg_comb_ps_acceptances[n_rsg_samples]={0.};
  float rsg_comb_highpt_acceptances[n_rsg_samples]={0.};
  float rsg_comb_sig_acceptances[n_rsg_samples]={0.};
  float rsg_comb_jet_boost_acceptances[n_rsg_samples]={0.};
  
  float rsg_comb_ps_sig_to_bkgd[n_rsg_samples]={0.};
  float rsg_comb_highpt_sig_to_bkgd[n_rsg_samples]={0.};
  float rsg_comb_sig_sig_to_bkgd[n_rsg_samples]={0.};
  float rsg_comb_jet_boost_sig_to_bkgd[n_rsg_samples]={0.};
  
  for(int r=0;r<n_rsg_samples;r++){

    float cur_rsg_ps_acceptance =
      ((((TH1F*) h_rsg_ps[r][0])->Integral()/h_rsg_ps[r][0]->Integral()) +
       ((TH1F*) h_rsg_ps[r][1])->Integral()/h_rsg_ps[r][1]->Integral())/2.;

    rsg_comb_ps_acceptances[r]=(cur_rsg_ps_acceptance);

    float cur_rsg_highpt_acceptance =
      ((((TH1F*) h_rsg_highpt[r][0])->Integral()/h_rsg_ps[r][0]->Integral()) +
       ((TH1F*) h_rsg_highpt[r][1])->Integral()/h_rsg_ps[r][1]->Integral())/2.;

    rsg_comb_highpt_acceptances[r]=(cur_rsg_highpt_acceptance);

    float cur_rsg_sig_acceptance =
      ((((TH1F*) h_rsg_sig[r][0])->Integral()/h_rsg_ps[r][0]->Integral()) +
       ((TH1F*) h_rsg_sig[r][1])->Integral()/h_rsg_ps[r][1]->Integral())/2.;
    rsg_comb_sig_acceptances[r]=(cur_rsg_sig_acceptance);

    float cur_rsg_jet_boost_acceptance =
      ((((TH1F*) h_rsg_jet_boost[r][0])->Integral()/h_rsg_ps[r][0]->Integral()) +
       ((TH1F*) h_rsg_jet_boost[r][1])->Integral()/h_rsg_ps[r][1]->Integral())/2.;
    rsg_comb_jet_boost_acceptances[r]=(cur_rsg_jet_boost_acceptance);

    float cur_rsg_ps_sig_to_bkgd =
      ((((TH1F*) h_rsg_ps[r][0])->Integral()/sqrt(h_bkgd_ps[0]->Integral())) +
       ((TH1F*) h_rsg_ps[r][1])->Integral()/sqrt(h_bkgd_ps[1]->Integral()))/2.;
    rsg_comb_ps_sig_to_bkgd[r]=(cur_rsg_ps_sig_to_bkgd);
    float cur_rsg_highpt_sig_to_bkgd =
      ((((TH1F*) h_rsg_highpt[r][0])->Integral()/sqrt(h_bkgd_highpt[0]->Integral())) +
       ((TH1F*) h_rsg_highpt[r][1])->Integral()/sqrt(h_bkgd_highpt[1]->Integral()))/2.;
    rsg_comb_highpt_sig_to_bkgd[r]=(cur_rsg_highpt_sig_to_bkgd);
    float cur_rsg_sig_sig_to_bkgd =
      ((((TH1F*) h_rsg_sig[r][0])->Integral()/sqrt(h_bkgd_sig[0]->Integral())) +
       ((TH1F*) h_rsg_sig[r][1])->Integral()/sqrt(h_bkgd_sig[1]->Integral()))/2.;
    rsg_comb_sig_sig_to_bkgd[r]=(cur_rsg_sig_sig_to_bkgd);
    float cur_rsg_jet_boost_sig_to_bkgd =
      ((((TH1F*) h_rsg_jet_boost[r][0])->Integral()/sqrt(h_bkgd_jet_boost[0]->Integral())) +
       ((TH1F*) h_rsg_jet_boost[r][1])->Integral()/sqrt(h_bkgd_jet_boost[1]->Integral()))/2.;
    rsg_comb_jet_boost_sig_to_bkgd[r]=(cur_rsg_jet_boost_sig_to_bkgd);

  }

  // wprime
  float wprime_comb_ps_acceptances[n_wprime_samples]={0.};
  float wprime_comb_highpt_acceptances[n_wprime_samples]={0.};
  float wprime_comb_sig_acceptances[n_wprime_samples]={0.};
  float wprime_comb_jet_boost_acceptances[n_wprime_samples]={0.};
  
  float wprime_comb_ps_sig_to_bkgd[n_wprime_samples]={0.};
  float wprime_comb_highpt_sig_to_bkgd[n_wprime_samples]={0.};
  float wprime_comb_sig_sig_to_bkgd[n_wprime_samples]={0.};
  float wprime_comb_jet_boost_sig_to_bkgd[n_wprime_samples]={0.};
  for(int r=0;r<n_wprime_samples;r++){

    float cur_wprime_ps_acceptance =
      ((((TH1F*) h_wprime_ps[r][0])->Integral()/h_wprime_ps[r][0]->Integral()) +
       ((TH1F*) h_wprime_ps[r][1])->Integral()/h_wprime_ps[r][1]->Integral())/2.;

    wprime_comb_ps_acceptances[r]=(cur_wprime_ps_acceptance);

    float cur_wprime_highpt_acceptance =
      ((((TH1F*) h_wprime_highpt[r][0])->Integral()/h_wprime_ps[r][0]->Integral()) +
       ((TH1F*) h_wprime_highpt[r][1])->Integral()/h_wprime_ps[r][1]->Integral())/2.;

    wprime_comb_highpt_acceptances[r]=(cur_wprime_highpt_acceptance);

    float cur_wprime_sig_acceptance =
      ((((TH1F*) h_wprime_sig[r][0])->Integral()/h_wprime_ps[r][0]->Integral()) +
       ((TH1F*) h_wprime_sig[r][1])->Integral()/h_wprime_ps[r][1]->Integral())/2.;
    wprime_comb_sig_acceptances[r]=(cur_wprime_sig_acceptance);

    float cur_wprime_jet_boost_acceptance =
      ((((TH1F*) h_wprime_jet_boost[r][0])->Integral()/h_wprime_ps[r][0]->Integral()) +
       ((TH1F*) h_wprime_jet_boost[r][1])->Integral()/h_wprime_ps[r][1]->Integral())/2.;
    wprime_comb_jet_boost_acceptances[r]=(cur_wprime_jet_boost_acceptance);


    float cur_wprime_ps_sig_to_bkgd =
      ((((TH1F*) h_wprime_ps[r][0])->Integral()/sqrt(h_bkgd_ps[0]->Integral())) +
       ((TH1F*) h_wprime_ps[r][1])->Integral()/sqrt(h_bkgd_ps[1]->Integral()))/2.;
    wprime_comb_ps_sig_to_bkgd[r]=(cur_wprime_ps_sig_to_bkgd);
    float cur_wprime_highpt_sig_to_bkgd =
      ((((TH1F*) h_wprime_highpt[r][0])->Integral()/sqrt(h_bkgd_highpt[0]->Integral())) +
       ((TH1F*) h_wprime_highpt[r][1])->Integral()/sqrt(h_bkgd_highpt[1]->Integral()))/2.;
    wprime_comb_highpt_sig_to_bkgd[r]=(cur_wprime_highpt_sig_to_bkgd);
    float cur_wprime_sig_sig_to_bkgd =
      ((((TH1F*) h_wprime_sig[r][0])->Integral()/sqrt(h_bkgd_sig[0]->Integral())) +
       ((TH1F*) h_wprime_sig[r][1])->Integral()/sqrt(h_bkgd_sig[1]->Integral()))/2.;
    wprime_comb_sig_sig_to_bkgd[r]=(cur_wprime_sig_sig_to_bkgd);
    float cur_wprime_jet_boost_sig_to_bkgd =
      ((((TH1F*) h_wprime_jet_boost[r][0])->Integral()/sqrt(h_bkgd_jet_boost[0]->Integral())) +
       ((TH1F*) h_wprime_jet_boost[r][1])->Integral()/sqrt(h_bkgd_jet_boost[1]->Integral()))/2.;
    wprime_comb_jet_boost_sig_to_bkgd[r]=(cur_wprime_jet_boost_sig_to_bkgd);

  }


  // rsg
  TCanvas *tc_rsg_acceptances =
    new TCanvas("tc_rsg_acceptances","RSG Acceptances",200,10,700,500);
  tc_rsg_acceptances->SetGrid();
  tc_rsg_acceptances->SetFillColor(0);

  TH1F *frame_rsg_acceptances = tc_rsg_acceptances->DrawFrame(450,0,1550,1.3);
  frame_rsg_acceptances->GetYaxis()->SetTitleSize(0.05);
  frame_rsg_acceptances->GetYaxis()->SetTitleOffset(0.8);
  frame_rsg_acceptances->GetXaxis()->SetTitleSize(0.05);
  frame_rsg_acceptances->GetXaxis()->SetTitleOffset(0.8);
  frame_rsg_acceptances->SetXTitle("G* Mass");
  frame_rsg_acceptances->SetYTitle("Acceptance");


  TGraph* gr_rsg_ps_acceptances =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_ps_acceptances);
  gr_rsg_ps_acceptances->SetTitle("RSG Acceptances");

  gr_rsg_ps_acceptances->SetLineColor(kGreen);
  gr_rsg_ps_acceptances->Draw("C*");

  TGraph* gr_rsg_highpt_acceptances =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_highpt_acceptances);
  //gr_rsg_highpt_acceptances->SetTitle("RSG Acceptances");
  gr_rsg_highpt_acceptances->SetLineColor(kRed);
  gr_rsg_highpt_acceptances->Draw("C*");

  TGraph* gr_rsg_sig_acceptances =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_sig_acceptances);
  gr_rsg_sig_acceptances->SetLineColor(kBlue);
  gr_rsg_sig_acceptances->Draw("C* sames");

  TGraph* gr_rsg_jet_boost_acceptances =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_jet_boost_acceptances);
  //gr_rsg_jet_boost_acceptances->SetLineColor(kBlue);
  gr_rsg_jet_boost_acceptances->Draw("C* sames");

  TLegend* lgnd_rsg_sig_acceptances = new TLegend(0.5,0.80,0.9,0.95);
  lgnd_rsg_sig_acceptances->SetTextSize(0.04);
  lgnd_rsg_sig_acceptances->SetFillColor(0);
  lgnd_rsg_sig_acceptances->AddEntry(gr_rsg_ps_acceptances,"preselection","L");
  lgnd_rsg_sig_acceptances->AddEntry(gr_rsg_highpt_acceptances,"pt(lv)>200 && pt(jj)>200","L");
  lgnd_rsg_sig_acceptances->AddEntry(gr_rsg_sig_acceptances,"w/ dijet_m cut","L");
  lgnd_rsg_sig_acceptances->AddEntry(gr_rsg_jet_boost_acceptances,"boosted jet","L");
  lgnd_rsg_sig_acceptances->Draw();


  tc_rsg_acceptances->cd();
  tc_rsg_acceptances->SaveAs("./graphs/rsg_acceptances.pdf");

  
  TCanvas *tc_rsg_sig_to_bkgd =
    new TCanvas("tc_rsg_sig_to_bkgd","RSG signal to background",200,10,700,500);

  tc_rsg_sig_to_bkgd->SetGrid();
  tc_rsg_sig_to_bkgd->SetLogy();
  tc_rsg_sig_to_bkgd->SetFillColor(0);
  
  TH1F *frame_rsg_sig_to_bkgd = tc_rsg_sig_to_bkgd->DrawFrame(450,0.001,1550,30);
  frame_rsg_sig_to_bkgd->GetYaxis()->SetTitleSize(0.05);
  frame_rsg_sig_to_bkgd->GetYaxis()->SetTitleOffset(0.8);
  frame_rsg_sig_to_bkgd->GetXaxis()->SetTitleSize(0.05);
  frame_rsg_sig_to_bkgd->GetXaxis()->SetTitleOffset(0.8);
  frame_rsg_sig_to_bkgd->SetXTitle("G* Mass");
  frame_rsg_sig_to_bkgd->SetYTitle("#frac{S}{#sqrt{B}}");

  TGraph* gr_rsg_highpt_sig_to_bkgd =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_highpt_sig_to_bkgd);
  gr_rsg_highpt_sig_to_bkgd->SetTitle("RSG signal to background");
  gr_rsg_highpt_sig_to_bkgd->SetLineColor(kRed);
  gr_rsg_highpt_sig_to_bkgd->Draw("C* sames");

  TGraph* gr_rsg_sig_sig_to_bkgd =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_sig_sig_to_bkgd);
  gr_rsg_sig_sig_to_bkgd->SetLineColor(kBlue);
  gr_rsg_sig_sig_to_bkgd->Draw("C* sames");

  TGraph* gr_rsg_ps_sig_to_bkgd =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_ps_sig_to_bkgd);
  gr_rsg_ps_sig_to_bkgd->SetLineColor(kGreen);
  gr_rsg_ps_sig_to_bkgd->Draw("C* sames");

  TGraph* gr_rsg_jet_boost_sig_to_bkgd =
    new TGraph(n_rsg_samples, v_rsg_masses, rsg_comb_jet_boost_sig_to_bkgd);
  //gr_rsg_jet_boost_sig_to_bkgd->SetLineColor(kGreen);
  gr_rsg_jet_boost_sig_to_bkgd->Draw("C* sames");

  TLegend* lgnd_rsg_sig_sig_to_bkgd = new TLegend(0.5,0.75,0.9,0.95);
  lgnd_rsg_sig_sig_to_bkgd->SetTextSize(0.04);
  lgnd_rsg_sig_sig_to_bkgd->SetFillColor(0);
  lgnd_rsg_sig_sig_to_bkgd->AddEntry(gr_rsg_ps_sig_to_bkgd,"preselection","L");
  lgnd_rsg_sig_sig_to_bkgd->AddEntry(gr_rsg_highpt_sig_to_bkgd,"pt(lv)>200 && pt(jj)>200","L");
  lgnd_rsg_sig_sig_to_bkgd->AddEntry(gr_rsg_sig_sig_to_bkgd,"w/ dijet_m cut","L");
  lgnd_rsg_sig_sig_to_bkgd->AddEntry(gr_rsg_jet_boost_sig_to_bkgd,"boosted jet","L");
  lgnd_rsg_sig_sig_to_bkgd->Draw();

  tc_rsg_sig_to_bkgd->SaveAs("./graphs/rsg_sig_to_bkgd.pdf");

  // wprime
  TCanvas *tc_wprime_acceptances =
    new TCanvas("tc_wprime_acceptances","wprime Acceptances",200,10,700,500);

  tc_wprime_acceptances->SetGrid();
  tc_wprime_acceptances->SetFillColor(0);
  
  TH1F *frame_wprime_acceptances = tc_wprime_acceptances->DrawFrame(450,0,1550,1.3);
  frame_wprime_acceptances->GetYaxis()->SetTitleSize(0.05);
  frame_wprime_acceptances->GetYaxis()->SetTitleOffset(0.8);
  frame_wprime_acceptances->GetXaxis()->SetTitleSize(0.05);
  frame_wprime_acceptances->GetXaxis()->SetTitleOffset(0.8);
  frame_wprime_acceptances->SetXTitle("W' Mass");
  frame_wprime_acceptances->SetYTitle("Acceptance");

  TGraph* gr_wprime_ps_acceptances =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_ps_acceptances);
  gr_wprime_ps_acceptances->SetTitle("wprime Acceptances");
  gr_wprime_ps_acceptances->SetLineColor(kGreen);
  gr_wprime_ps_acceptances->Draw("C*");

  TGraph* gr_wprime_highpt_acceptances =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_highpt_acceptances);
  gr_wprime_highpt_acceptances->SetLineColor(kRed);
  gr_wprime_highpt_acceptances->Draw("C*");

  TGraph* gr_wprime_sig_acceptances =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_sig_acceptances);
  gr_wprime_sig_acceptances->SetLineColor(kBlue);
  gr_wprime_sig_acceptances->Draw("C* sames");

  TGraph* gr_wprime_jet_boost_acceptances =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_jet_boost_acceptances);
  //gr_wprime_jet_boost_acceptances->SetLineColor(kBlue);
  gr_wprime_jet_boost_acceptances->Draw("C* sames");

  TLegend* lgnd_wprime_sig_acceptances = new TLegend(0.5,0.80,0.9,0.95);
  lgnd_wprime_sig_acceptances->SetTextSize(0.04);
  lgnd_wprime_sig_acceptances->SetFillColor(0);
  lgnd_wprime_sig_acceptances->AddEntry(gr_wprime_ps_acceptances,"preselection","L");
  lgnd_wprime_sig_acceptances->AddEntry(gr_wprime_highpt_acceptances,"pt(lv)>200 && pt(jj)>200","L");
  lgnd_wprime_sig_acceptances->AddEntry(gr_wprime_sig_acceptances,"w/ dijet_m cut","L");
  lgnd_wprime_sig_acceptances->AddEntry(gr_wprime_jet_boost_acceptances,"boosted jet","L");
  lgnd_wprime_sig_acceptances->Draw();

  tc_wprime_acceptances->cd();
  tc_wprime_acceptances->SaveAs("./graphs/wprime_acceptances.pdf");

  TCanvas *tc_wprime_sig_to_bkgd =
    new TCanvas("tc_wprime_sig_to_bkgd","wprime signal to background",200,10,700,500);

  tc_wprime_sig_to_bkgd->SetGrid();
  tc_wprime_sig_to_bkgd->SetLogy();
  tc_wprime_sig_to_bkgd->SetFillColor(0);
  
  TH1F *frame_wprime_sig_to_bkgd = tc_wprime_sig_to_bkgd->DrawFrame(450,0.001,1550,30);
  frame_wprime_sig_to_bkgd->GetYaxis()->SetTitleSize(0.05);
  frame_wprime_sig_to_bkgd->GetYaxis()->SetTitleOffset(0.8);
  frame_wprime_sig_to_bkgd->GetXaxis()->SetTitleSize(0.05);
  frame_wprime_sig_to_bkgd->GetXaxis()->SetTitleOffset(0.8);
  frame_wprime_sig_to_bkgd->SetXTitle("W' Mass");
  frame_wprime_sig_to_bkgd->SetYTitle("#frac{S}{#sqrt{B}}");

  TGraph* gr_wprime_highpt_sig_to_bkgd =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_highpt_sig_to_bkgd);
  gr_wprime_highpt_sig_to_bkgd->SetTitle("wprime signal to background");
  gr_wprime_highpt_sig_to_bkgd->SetLineColor(kRed);
  gr_wprime_highpt_sig_to_bkgd->Draw("C* sames");

  TGraph* gr_wprime_sig_sig_to_bkgd =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_sig_sig_to_bkgd);
  gr_wprime_sig_sig_to_bkgd->SetLineColor(kBlue);
  gr_wprime_sig_sig_to_bkgd->Draw("C* sames");

  TGraph* gr_wprime_ps_sig_to_bkgd =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_ps_sig_to_bkgd);
  gr_wprime_ps_sig_to_bkgd->SetLineColor(kGreen);
  gr_wprime_ps_sig_to_bkgd->Draw("C* sames");

  TGraph* gr_wprime_jet_boost_sig_to_bkgd =
    new TGraph(n_wprime_samples, v_wprime_masses, wprime_comb_jet_boost_sig_to_bkgd);
  //gr_wprime_jet_boost_sig_to_bkgd->SetLineColor(kGreen);
  gr_wprime_jet_boost_sig_to_bkgd->Draw("C* sames");

  TLegend* lgnd_wprime_sig_sig_to_bkgd = new TLegend(0.5,0.75,0.9,0.95);
  lgnd_wprime_sig_sig_to_bkgd->SetTextSize(0.04);
  lgnd_wprime_sig_sig_to_bkgd->SetFillColor(0);
  lgnd_wprime_sig_sig_to_bkgd->AddEntry(gr_wprime_ps_sig_to_bkgd,"preselection","L");
  lgnd_wprime_sig_sig_to_bkgd->AddEntry(gr_wprime_highpt_sig_to_bkgd,"pt(lv)>200 && pt(jj)>200","L");
  lgnd_wprime_sig_sig_to_bkgd->AddEntry(gr_wprime_sig_sig_to_bkgd,"w/ dijet_m cut","L");
  lgnd_wprime_sig_sig_to_bkgd->AddEntry(gr_wprime_jet_boost_sig_to_bkgd,"boosted jet","L");
  lgnd_wprime_sig_sig_to_bkgd->Draw();

  tc_wprime_sig_to_bkgd->SaveAs("./graphs/wprime_sig_to_bkgd.pdf");

  
  
  return;
}
