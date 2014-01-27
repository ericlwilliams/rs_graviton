#include <TFile.h>
#include <TH1.h>
#include <TGraph.h>
void cutFlowElec(){

  gROOT->LoadMacro("../../include/atlasstyle-00-03-04/AtlasStyle.C");
  SetAtlasStyle();
  gROOT->LoadMacro("../../include/atlasstyle-00-03-04/AtlasUtils.C");
  gROOT->LoadMacro("../../include/atlasstyle-00-03-04/AtlasLabels.C");
  
  gROOT->SetBatch();
  
  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In cutFlowElec.C"<<endl;


  TFile* data_sel_plots =
    (TFile*) TFile::Open("../../plots/selection_plots/merged/sel.data.selection.root");
  TFile* mc_bkgd_sel_plots = 
      (TFile*) TFile::Open("../../plots/selection_plots/merged/sel.bkgd.selection.root");

  TDirectory* dir_data_elec = (TDirectory*) data_sel_plots->GetDirectory("elec");
  TDirectory* dir_bkgd_elec = (TDirectory*) mc_bkgd_sel_plots->GetDirectory("elec");

  // (! bug in author mc, can divide by #h_all_author_evt_n) 
  //nocut,author,eta,pt,d0_sig,abs_z0,tight,etiso30,ptiso30,ptiso20

  const int nCuts = 10;
  string cuts[nCuts] = {"nocut","author","eta","pt","d0_sig","abs_z0","tight","rel_etiso30","rel_ptiso30","rel_ptiso20"};

  float n_all_data_el[nCuts] ={0.};
  float n_all_bkgd_el[nCuts] ={0.};
  float n_hpt_data_el[nCuts] ={0.};
  float n_hpt_bkgd_el[nCuts] ={0.};

  float n_tot_data_evt_n=0.;
  float n_tot_bkgd_evt_n=0.;

  for(int i=0;i<nCuts;i++){
    string cur_all_hist_name = "h_elec_all_"+cuts[i]+"_evt_n";
    string cur_hpt_hist_name = "h_elec_hpt_"+cuts[i]+"_evt_n";

    TH1I* cur_data_all_hist = (TH1I*) dir_data_elec->Get(cur_all_hist_name.c_str());
    TH1I* cur_data_hpt_hist = (TH1I*) dir_data_elec->Get(cur_hpt_hist_name.c_str());    

    TH1I* cur_bkgd_all_hist = (TH1I*) dir_bkgd_elec->Get(cur_all_hist_name.c_str());
    TH1I* cur_bkgd_hpt_hist = (TH1I*) dir_bkgd_elec->Get(cur_hpt_hist_name.c_str());    

    if(!i){
      n_tot_data_evt_n = (float) 1.0*cur_data_all_hist->GetEntries(); //nocut
      n_tot_bkgd_evt_n = (float) 1.0*cur_bkgd_all_hist->GetEntries(); //nocut
    }


    float cur_data_all_evt_n = (float) 1.*cur_data_all_hist->Integral();
    float cur_bkgd_all_evt_n = (float) 1.*cur_bkgd_all_hist->Integral(); 
    
    float cur_data_hpt_evt_n = (float) 1.*cur_data_hpt_hist->Integral();
    float cur_bkgd_hpt_evt_n = (float) 1.*cur_bkgd_hpt_hist->Integral(); 

    n_all_data_el[i] = cur_data_all_evt_n/n_tot_data_evt_n;
    n_all_bkgd_el[i] = cur_bkgd_all_evt_n/n_tot_data_evt_n;

    n_hpt_data_el[i] = cur_data_hpt_evt_n/n_tot_bkgd_evt_n;
    n_hpt_bkgd_el[i] = cur_bkgd_hpt_evt_n/n_tot_bkgd_evt_n;

  }

  float x_axis[nCuts] = {1,2,3,4,5,6,7,8,9,10};
  
  TCanvas* tc_all_elec_cut_flow = new TCanvas("tc_all_elec_cut_flow","all_elec_cut_flow",200,10,700,500);
  tc_all_elec_cut_flow->SetGrid();
  tc_all_elec_cut_flow->SetFillColor(0);
  tc_all_elec_cut_flow->SetLogy();

  TH1F *frame_all_elec_cut_flow = tc_all_elec_cut_flow->DrawFrame(0,0.001,11,1.3);
  frame_all_elec_cut_flow->GetYaxis()->SetTitleSize(0.05);
  frame_all_elec_cut_flow->GetYaxis()->SetTitleOffset(0.8);
  frame_all_elec_cut_flow->GetXaxis()->SetTitleSize(0.05);
  frame_all_elec_cut_flow->GetXaxis()->SetTitleOffset(0.8);
  frame_all_elec_cut_flow->SetXTitle("Electron object cuts");
  frame_all_elec_cut_flow->SetYTitle("Fractional acceptance");
  
  TGraph* gr_all_elec_cut_flow_data = new TGraph(nCuts,x_axis,n_all_data_el);
  gr_all_elec_cut_flow_data->SetTitle("Cut flow elec data");
  gr_all_elec_cut_flow_data->SetMarkerColor(kRed);
  gr_all_elec_cut_flow_data->SetMarkerStyle(20);
  gr_all_elec_cut_flow_data->Draw("P");

  TGraph* gr_all_elec_cut_flow_bkgd = new TGraph(nCuts,x_axis,n_all_bkgd_el);
  gr_all_elec_cut_flow_bkgd->SetTitle("Cut flow elec bkgd");
  gr_all_elec_cut_flow_bkgd->SetMarkerColor(kBlue);
  gr_all_elec_cut_flow_bkgd->SetMarkerStyle(20);
  gr_all_elec_cut_flow_bkgd->Draw("p");


  tc_all_elec_cut_flow->cd();
  tc_all_elec_cut_flow->SetLogy();
  tc_all_elec_cut_flow->SaveAs("../canvases/latest/gr_all_elec_cut_flow.pdf");

  
  TCanvas* tc_hpt_elec_cut_flow = new TCanvas("tc_hpt_elec_cut_flow","hpt_elec_cut_flow",200,10,700,500);
  tc_hpt_elec_cut_flow->SetGrid();
  tc_hpt_elec_cut_flow->SetFillColor(0);
  tc_hpt_elec_cut_flow->SetLogy();

  TH1F *frame_hpt_elec_cut_flow = tc_hpt_elec_cut_flow->DrawFrame(0,0.0001,11,1.3);
  frame_hpt_elec_cut_flow->GetYaxis()->SetTitleSize(0.05);
  frame_hpt_elec_cut_flow->GetYaxis()->SetTitleOffset(0.8);
  frame_hpt_elec_cut_flow->GetXaxis()->SetTitleSize(0.05);
  frame_hpt_elec_cut_flow->GetXaxis()->SetTitleOffset(0.8);
  frame_hpt_elec_cut_flow->SetXTitle("Electron object cuts");
  frame_hpt_elec_cut_flow->SetYTitle("Fractional acceptance");
  
  TGraph* gr_hpt_elec_cut_flow_data = new TGraph(nCuts,x_axis,n_hpt_data_el);
  gr_hpt_elec_cut_flow_data->SetTitle("Cut flow elec data");
  gr_hpt_elec_cut_flow_data->SetMarkerColor(kRed);
  gr_hpt_elec_cut_flow_data->SetMarkerStyle(20);
  gr_hpt_elec_cut_flow_data->Draw("P");

  TGraph* gr_hpt_elec_cut_flow_bkgd = new TGraph(nCuts,x_axis,n_hpt_bkgd_el);
  gr_hpt_elec_cut_flow_bkgd->SetTitle("Cut flow elec bkgd");
  gr_hpt_elec_cut_flow_bkgd->SetMarkerColor(kBlue);
  gr_hpt_elec_cut_flow_bkgd->SetMarkerStyle(20);
  gr_hpt_elec_cut_flow_bkgd->Draw("p");


  tc_hpt_elec_cut_flow->cd();
  tc_hpt_elec_cut_flow->SetLogy();
  tc_hpt_elec_cut_flow->SaveAs("../canvases/latest/gr_hpt_elec_cut_flow.pdf");

  
  return;
}
