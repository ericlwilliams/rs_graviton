//////////////////////////////////////////////////
// wjetsPrintSignal
// Prints MT(lvjj) plots comparing ALPGEN and SHERPA
// NO DATA
// based off of wjetsPrint
////////////////////////////////////////////////// 
#include "../include/wwFileInfo.h"
#include "../include/HistogramPainter.h"
#include <TCanvas.h>
#include <TPad.h>
#include <TLegend.h>
#include <THStack.h>
#include <TH1F.h>
//#include <TIter.h>
#include <TObject.h>
#include <string>


string plot_loc = "../canvases/latest/";
string save_ext = ".pdf";

int alpgen_color = 6;
int sherpa_color = 7;
float ratio_split=0.35;

void wjetsBackgroundSystematics(){

  gROOT->LoadMacro("../include/atlasstyle-00-03-04/AtlasStyle.C");
  SetAtlasStyle();
  gROOT->LoadMacro("../include/atlasstyle-00-03-04/AtlasUtils.C");
  gROOT->LoadMacro("../include/atlasstyle-00-03-04/AtlasLabels.C");
  
  gROOT->SetBatch();

  TH1::SetDefaultSumw2(kTRUE);

  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In wjetsPrintSignal.C"<<endl;

  string var = "lep_met_dijet_mt";
  string plot_var = "Mt(lep,MET,dijet)";
  string file_loc = "/Users/elw/analy/lvjj/plots/ctrl_plots/";
  string file_end = ".ctrl.plot.root";

    //////////////////////////////////////////////////
  // Load Scaled Backgrounds
  //////////////////////////////////////////////////
  
  string sherpa_wjets_loc = file_loc+"merged/mc.sherpa.wjets"+file_end;
  string alpgen_wjets_loc = file_loc+"merged/mc.alpgen.wjets"+file_end;
  string vv_loc = file_loc+"merged/mc.herwig.vv"+file_end;
  string alpgen_qcd_loc = file_loc+"merged/qcd.alpgen"+file_end;
  string sherpa_qcd_loc = file_loc+"merged/qcd.sherpa"+file_end;
  string top_loc = file_loc+"merged/mc.mcatnlo.top"+file_end;  
  string alpgen_zjets_loc = file_loc+"merged/mc.alpgen.zjets"+file_end;
  string sherpa_zjets_loc = file_loc+"merged/mc.sherpa.zjets"+file_end;

  string hist_name = "h_sig_highm_comb_dijet_m_lep_met_dijet_mt";
  
  TFile* sherpa_wjets = (TFile*) TFile::Open(sherpa_wjets_loc.c_str(),"READ");  
  TH1F* h_sherpa_wjets = (TH1F*) sherpa_wjets->Get(hist_name.c_str());
  h_sherpa_wjets->SetDirectory(0);
  sherpa_wjets->Close();

  TFile* sherpa_zjets = (TFile*) TFile::Open(sherpa_zjets_loc.c_str(),"READ");
  TH1F* h_sherpa_zjets = (TH1F*) sherpa_zjets->Get(hist_name.c_str());
  h_sherpa_zjets->SetDirectory(0);
  sherpa_zjets->Close();

  TFile* sherpa_qcd = (TFile*) TFile::Open(sherpa_qcd_loc.c_str(),"READ");
  TH1F* h_sherpa_qcd = (TH1F*) sherpa_qcd->Get(hist_name.c_str());
  h_sherpa_qcd->SetDirectory(0);
  sherpa_qcd->Close();
  
  TFile* alpgen_wjets = (TFile*) TFile::Open(alpgen_wjets_loc.c_str(),"READ");  
  TH1F* h_alpgen_wjets = (TH1F*) alpgen_wjets->Get(hist_name.c_str());
  h_alpgen_wjets->SetDirectory(0);
  alpgen_wjets->Close();

  TFile* alpgen_zjets = (TFile*) TFile::Open(alpgen_zjets_loc.c_str(),"READ");
  TH1F* h_alpgen_zjets = (TH1F*) alpgen_zjets->Get(hist_name.c_str());
  h_alpgen_zjets->SetDirectory(0);
  alpgen_zjets->Close();

  TFile* alpgen_qcd = (TFile*) TFile::Open(alpgen_qcd_loc.c_str(),"READ");
  TH1F* h_alpgen_qcd = (TH1F*) alpgen_qcd->Get(hist_name.c_str());
  h_alpgen_qcd->SetDirectory(0);
  alpgen_qcd->Close();
  
  TFile* top = (TFile*) TFile::Open(top_loc.c_str(),"READ");
  TH1F* h_top = (TH1F*) top->Get(hist_name.c_str());
  h_top->SetDirectory(0);
  top->Close();

  TFile* vv = (TFile*) TFile::Open(vv_loc.c_str(),"READ");
  TH1F* h_vv = (TH1F*) vv->Get(hist_name.c_str());
  h_vv->SetDirectory(0);
  vv->Close();

  // const int nBkgds = 2;
  // TFile* bkgd_files[nBkgds] = {vv,top};

  //////////////////////////////////////////////////
  // Histogram selection
  ////////////////////////////////////////////////// 



  //SHERPA
  TH1F* h_sherpa_bkgd = ((TH1F*) h_sherpa_wjets->Clone());
  h_sherpa_bkgd->Add(h_sherpa_zjets);
  h_sherpa_bkgd->Add(h_sherpa_qcd);
  h_sherpa_bkgd->SetLineColor(sherpa_color);
  
  //ALPGEN
  TH1F* h_alpgen_bkgd = (TH1F*) h_alpgen_wjets->Clone();
  h_alpgen_bkgd->Add(h_alpgen_zjets);
  h_alpgen_bkgd->Add(h_alpgen_qcd);
  h_alpgen_bkgd->SetLineColor(alpgen_color);
  
      
  
  h_vv->SetFillColor(kYellow-4);
  h_vv->SetLineWidth(1);
    
  h_top->SetFillColor(kAzure+1);
  h_top->SetLineWidth(1);

  //////////////////////////////////////////////////
  // Alpgen printed as stack, to see other backgrounds
  // Sherpa background added
  ////////////////////////////////////////////////// 
  string stack_name = "stk_comb_"+var;
  THStack* stk_alpgen_bkgd = new THStack(stack_name.c_str(),hist_name.c_str());
  stk_alpgen_bkgd->Add((TH1F*) h_vv->Clone());
  stk_alpgen_bkgd->Add((TH1F*) h_top->Clone());
  stk_alpgen_bkgd->Add((TH1F*) h_alpgen_bkgd->Clone());

  h_sherpa_bkgd->Add((TH1F*) h_vv->Clone());
  h_sherpa_bkgd->Add((TH1F*) h_top->Clone());

  h_alpgen_bkgd->Add((TH1F*) h_vv->Clone());
  h_alpgen_bkgd->Add((TH1F*) h_top->Clone());

  //////////////////////////////////////////////////
  // make ratio histogram
  //////////////////////////////////////////////////
	
  int n_bins = ((TAxis*) h_alpgen_bkgd->GetXaxis())->GetNbins();
  float x_min = ((TAxis*) h_alpgen_bkgd->GetXaxis())->GetXmin();
  float x_max = ((TAxis*) h_alpgen_bkgd->GetXaxis())->GetXmax();


  float alpgen_sherpa_avg_fractional_difference=0.;
  float alpgen_sherpa_mc_stat_uncert=0.;
  float total_avg_bkgd_count=0.;
  
  string alpgen_sherpa_ratio_name = "h_alpgen_sherpa_ratio_comb_"+var;
  TH1F* h_alpgen_sherpa_ratio = new TH1F(alpgen_sherpa_ratio_name.c_str(),"",n_bins,x_min,x_max);
  float sum_wgt=0;
  float sum_err=0;
  int cur_bin_ctr=0;
  for(int i=0;i<n_bins;i++){ //loop over bins

    // sherpa
    float sherpa_bkgd_count= h_sherpa_bkgd->GetBinContent(i);
    float sherpa_bkgd_err=h_sherpa_bkgd->GetBinError(i);

    // alpgen
    float alpgen_bkgd_count= h_alpgen_bkgd->GetBinContent(i);
    float alpgen_bkgd_err=h_alpgen_bkgd->GetBinError(i);

    if(alpgen_bkgd_count && sherpa_bkgd_count) {

      // float avg_bkgd_err =
      // 	((alpgen_bkgd_err+sherpa_bkgd_err)/2)*
      // 	((alpgen_bkgd_count+sherpa_bkgd_count)/2);

      total_avg_bkgd_count += ((alpgen_bkgd_count+sherpa_bkgd_count)/2.);


      float alpgen_rel_error = alpgen_bkgd_err/alpgen_bkgd_count;
      float sherpa_rel_error = sherpa_bkgd_err/sherpa_bkgd_count;

      double cur_alpgen_ratio = alpgen_bkgd_count/sherpa_bkgd_count;
	  
      double cur_alpgen_ratio_err =
	sqrt(pow(alpgen_rel_error,2.)+pow(sherpa_rel_error,2.));
	  
      h_alpgen_sherpa_ratio->SetBinContent(i,cur_alpgen_ratio);
      h_alpgen_sherpa_ratio->SetBinError(i,cur_alpgen_ratio_err);

      float cur_fractional_diff =
	fabs(alpgen_bkgd_count-sherpa_bkgd_count)/alpgen_bkgd_count;

      //weight by avg number of events in bin      
      cur_fractional_diff*=((alpgen_bkgd_count+sherpa_bkgd_count)/2.);
      cur_alpgen_ratio_err*=((alpgen_bkgd_count+sherpa_bkgd_count)/2.);
      
      alpgen_sherpa_avg_fractional_difference+=cur_fractional_diff;
      alpgen_sherpa_mc_stat_uncert+=cur_alpgen_ratio_err;

      //sum_wgt+=(1/cur_alpgen_ratio_err);
      //weight error by (avg bin count)
      //cur_alpgen_ratio_err*=((alpgen_bkgd_count+sherpa_bkgd_count)/2.);
      //sum_err+=cur_alpgen_ratio_err;
      //++cur_bin_ctr;
    }

  }
  //if(sum_wgt) alpgen_sherpa_avg_fractional_difference/=sum_wgt;
  if(total_avg_bkgd_count){
    alpgen_sherpa_avg_fractional_difference/=total_avg_bkgd_count;
    alpgen_sherpa_mc_stat_uncert/=total_avg_bkgd_count;
  }

  // Get Statistical uncertainties
      
  // float sherpa_sow = h_sherpa_bkgd->Integral();
  // float sherpa_nentries = h_sherpa_bkgd->GetEntries();

  // float sherpa_abs_err = sqrt(sherpa_sow)*sherpa_nentries/sherpa_sow;

  // float sherpa_rel_err = sherpa_abs_err/sherpa_sow;

  // if(sherpa_rel_err) alpgen_sherpa_mc_stat_uncert = sherpa_rel_err;
	
  //TH1F* h_alpgen_sherpa_ratio = (TH1F*) alpgen_sherpa_ratio;


  //////////////////////////////////////////////////
  // Plotting Loop
  ////////////////////////////////////////////////// 

  TCanvas* canvas;
  TPad* ratio_pad;
  TPad* plot_pad;

  string canvas_name = "tc_sig_highm_vjets_comb_"+var;
  string hist_name = "h_sig_highm_vjets_comb_"+var;

    //////////////////////////////////////////////////
    // make canvas
    ////////////////////////////////////////////////// 

    canvas =  new TCanvas(canvas_name.c_str(),canvas_name.c_str(),0,0,1920,1200);
    canvas->cd();

	
    ratio_pad = new TPad("ratio_pad","ratio_pad",0.01,0.01,0.99,ratio_split);
    ratio_pad->SetTopMargin(0.05);
    ratio_pad->SetBottomMargin(0.31);
    ratio_pad->Draw();

    plot_pad = new TPad("plot_pad","plot_pad",0.01,ratio_split,0.99,0.99);
    plot_pad->SetBottomMargin(0);
    plot_pad->Draw();
    plot_pad->cd();
    plot_pad->Update();  
     
	
    stk_alpgen_bkgd->Draw("HIST");
    stk_alpgen_bkgd->SetMinimum(0.1);
    stk_alpgen_bkgd->Draw("HIST");

    h_sherpa_bkgd->SetLineWidth(1);
    h_sherpa_bkgd->GetXaxis()->SetTitle(plot_var.c_str());
    h_sherpa_bkgd->Draw("sames HIST");

    plot_pad->SetLogy();
    canvas->Update();

    //////////////////////////////////////////////////
    // make legend
    ////////////////////////////////////////////////// 

    TLegend* lgnd = new TLegend(0.63,0.7,0.9,0.9);
    lgnd->SetFillColor(0);
    lgnd->SetTextSize(0.045);
    lgnd->AddEntry(h_sherpa_bkgd,"SHERPA (qcd,v+jets)","F");
    lgnd->AddEntry(h_alpgen_bkgd,"ALPGEN (qcd,v+jets)","F");
    lgnd->AddEntry(h_top,"mc.mcatnlo.top","F");
    lgnd->AddEntry(h_vv,"mc.herwig.vv","F");
    lgnd->Draw();
	
    //////////////////////////////////////////////////
    // Do ratio
    ////////////////////////////////////////////////// 

    ratio_pad->cd();
    ratio_pad->SetGrid();
  
    TAxis* alpgen_sherpa_ratio_xaxis= h_alpgen_sherpa_ratio->GetXaxis();
    TAxis* alpgen_sherpa_ratio_yaxis= h_alpgen_sherpa_ratio->GetYaxis();

    h_alpgen_sherpa_ratio->SetMarkerStyle(20);
    h_alpgen_sherpa_ratio->SetMarkerSize(2);
    h_alpgen_sherpa_ratio->SetLineWidth(1);
    //h_alpgen_sherpa_ratio->SetLineColor(alpgen_color);

    alpgen_sherpa_ratio_xaxis->SetLabelSize(0.08);
    alpgen_sherpa_ratio_yaxis->SetLabelSize(0.08);
    
    alpgen_sherpa_ratio_xaxis->SetTitle(plot_var.c_str());
    alpgen_sherpa_ratio_xaxis->SetTitleSize(0.16);
    alpgen_sherpa_ratio_xaxis->SetTitleOffset(0.7);
    alpgen_sherpa_ratio_yaxis->SetNdivisions(4,4,4);
    alpgen_sherpa_ratio_yaxis->SetTitle("ALPGEN/SHERPA");
    alpgen_sherpa_ratio_yaxis->SetTitleSize(0.07);
    alpgen_sherpa_ratio_yaxis->SetTitleOffset(0.36);

    alpgen_sherpa_ratio_yaxis->SetRangeUser(0,2);
    h_alpgen_sherpa_ratio->Draw("HIST PE");
    canvas->Update();
	

    plot_pad->cd();
    canvas->RedrawAxis();
    double leg_x1 = lgnd->GetX1NDC();
    double leg_y1 = lgnd->GetY1NDC();
    double offset_x1 = -0.02;
    double offset_y1 = 0.08;
    // If you want to write text on the plot (e.g. integrated luminosity)
    //string atlas_text    = "ATLAS pre-approval";

    string sqrts_text    = "#sqrt{s}= 7 TeV";
    string lumi_text     = "#int Ldt = 4.701 fb^{-1}";
    myText(leg_x1-offset_x1, leg_y1-offset_y1, 1, sqrts_text.c_str());
    myText(leg_x1-offset_x1 + 0.1, leg_y1-offset_y1,1,  lumi_text.c_str());

    string cur_saveas = plot_loc+hist_name+save_ext;
    canvas->SaveAs(cur_saveas.c_str());
	

  //////////////////////////////////////////////////
  // make logs/vjets_bkgd_systematics.csv
  ////////////////////////////////////////////////// 
  // uncert,evjj,uvjj
  // |ALGPEN-SHERPA/ALPGEN|, {weighted bin average uncert}, {...}
  // MC stat. uncert, {weighted bin average uncert}, {...}

  //TODO
  cout<<"Average Fractional difference / MC stat. uncertainty"<<endl;
  cout<<"comb: "<<alpgen_sherpa_avg_fractional_difference
      <<" / "<<alpgen_sherpa_mc_stat_uncert<<endl;

  string sys_out_file_name = "./logs/vjets_bkgd_systematics.csv";
  std::ofstream sys_out_file(sys_out_file_name.c_str());
  sys_out_file.precision(1);
  sys_out_file.setf(ios::fixed,ios::floatfield);
  sys_out_file<<"uncert,comb"<<endl;
  sys_out_file<<"\\textvertline{\\tt ALPGEN}-{\\tt SHERPA}\\textvertline/{\\tt ALPGEN},"
	      <<alpgen_sherpa_avg_fractional_difference*100<<"\\%"<<endl;
  sys_out_file<<"MC stat. uncertainty,"<<alpgen_sherpa_mc_stat_uncert[0]*100<<"\\%"<<endl;

  sys_out_file.close();
  gROOT->ProcessLine(".q");
  return;
}
