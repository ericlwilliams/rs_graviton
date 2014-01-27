#include <TMultiGraph.h>
#include <TGraphErrors.h>

void printJetM(bool drawData=true){

  gROOT->LoadMacro("../../include/atlasstyle-00-03-04/AtlasStyle.C");
  SetAtlasStyle();
  gROOT->LoadMacro("../../include/atlasstyle-00-03-04/AtlasUtils.C");
  gROOT->LoadMacro("../../include/atlasstyle-00-03-04/AtlasLabels.C");
  
  gROOT->SetBatch();
  
  cout<<endl;
  cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
  cout<<"In printJetM.C"<<endl;

  // Copy info from ../logs/*

  const int nMasses=7;
  float jetm_xaxis[nMasses] = {200,350,500,750,1000,1250,1500};
  float err_jetm_xaxis[nMasses] = {0,0,0,0,0,0,0};

  //jpt30_kt6
  float jpt30_kt6_one_jet[nMasses] =
    {0.225894,0.108684,0.108947,0.162067,0.186015,0.198191,0.209415};
  float err_jpt30_kt6_one_jet[nMasses] =
    {0.0121,0.0175,0.0175,0.0143,0.01339,0.013,0.0126};
  
  float jpt30_kt6_merged[nMasses] =
    {0.00220059,0.0150737,0.0883648,0.445116,0.651202,0.728201,0.785807};
  float err_jpt30_kt6_merged[nMasses] =
    {0.123,0.047036,0.0194294,0.00865,0.00715,0.00677,0.0065};
  
  float jpt30_kt6_unmerged[nMasses] =
    {0.216524,0.248116,0.230669,0.0828689,0.0432577,0.0227333,0.0166383};
  float err_jpt30_kt6_unmerged[nMasses] =
    {0.012,0.012,0.012,0.02,0.028,0.038,0.045};

  
  TCanvas* tc_jpt30_kt6 = new TCanvas("tc_jpt30_kt6","jpt30_kt6",0,0,1280,800);
  tc_jpt30_kt6->cd();
  
  TGraphErrors* jetm_jpt30_kt6_one_jet =
    new TGraphErrors(nMasses,jetm_xaxis,jpt30_kt6_one_jet,err_jetm_xaxis,err_jpt30_kt6_one_jet);
  jetm_jpt30_kt6_one_jet->SetMarkerColor(kGreen);
  jetm_jpt30_kt6_one_jet->SetMarkerStyle(8);
  jetm_jpt30_kt6_one_jet->SetMarkerSize(2);
  TGraphErrors* jetm_jpt30_kt6_merged = 
    new TGraphErrors(nMasses,jetm_xaxis,jpt30_kt6_merged,err_jetm_xaxis,err_jpt30_kt6_merged);
  jetm_jpt30_kt6_merged->SetMarkerColor(kRed);
  jetm_jpt30_kt6_merged->SetMarkerStyle(8);
  jetm_jpt30_kt6_merged->SetMarkerSize(2);
  TGraphErrors* jetm_jpt30_kt6_unmerged = 
    new TGraphErrors(nMasses,jetm_xaxis,jpt30_kt6_unmerged,err_jetm_xaxis,err_jpt30_kt6_unmerged);
  jetm_jpt30_kt6_unmerged->SetMarkerColor(kBlue);
  jetm_jpt30_kt6_unmerged->SetMarkerStyle(8);
  jetm_jpt30_kt6_unmerged->SetMarkerSize(2);

  TMultiGraph* mgraph_jpt30_kt6 = new TMultiGraph();
  mgraph_jpt30_kt6->Add(jetm_jpt30_kt6_one_jet);
  mgraph_jpt30_kt6->Add(jetm_jpt30_kt6_merged);
  mgraph_jpt30_kt6->Add(jetm_jpt30_kt6_unmerged);
  mgraph_jpt30_kt6->Draw("AP");

  mgraph_jpt30_kt6->GetXaxis()->SetTitle("Graviton Mass [GeV]");
  mgraph_jpt30_kt6->GetYaxis()->SetTitle("Fraction of Events");


  
  TLegend* lgnd_jpt30_kt6 = (TLegend*) new TLegend(0.2,0.67,0.5,0.88);
  lgnd_jpt30_kt6->SetFillStyle(1);
  lgnd_jpt30_kt6->SetTextSize(0.035);
  lgnd_jpt30_kt6->AddEntry(jetm_jpt30_kt6_one_jet,"One Jet","P");
  lgnd_jpt30_kt6->AddEntry(jetm_jpt30_kt6_merged,"Jet_M > 60 GeV","P");
  lgnd_jpt30_kt6->AddEntry(jetm_jpt30_kt6_unmerged,"60 < Dijet_M < 105 GeV","P");
  lgnd_jpt30_kt6->Draw();
  

  tc_jpt30_kt6->Update();
  tc_jpt30_kt6->SetGrid();
  tc_jpt30_kt6->SaveAs("../canvases/latest/jpt30_kt6.png");


  //jpt20_kt6
  float jpt20_kt6_one_jet[nMasses] =
    {0.0765871,0.0310145,0.0408299,0.0723559,0.0843124,0.0990,0.10828};
  float err_jpt20_kt6_one_jet[nMasses] =
    {0.0208651,0.0327913,0.0285831,0.0214768,0.0198968,0.0183556,0.0175655};
  
  float jpt20_kt6_merged[nMasses] =
    {0.0022,0.01507,0.0883548,0.445116,0.651202,0.7282,0.785807};
  float err_jpt20_kt6_merged[nMasses] =
    {0.123091,0.047036,0.0194294,0.00865906,0.00715931,0.00677068,0.00652051};
  
  float jpt20_kt6_unmerged[nMasses] =
    {0.305948,0.281198,0.254086,0.098388,0.0514686,0.0294766,0.0215496};
  float err_jpt20_kt6_unmerged[nMasses] =
    {0.104393,0.0108902,0.011458,0.0184177,0.0254658,0.0336527,0.039375};

  
  TCanvas* tc_jpt20_kt6 = new TCanvas("tc_jpt20_kt6","jpt20_kt6",0,0,1280,800);
  tc_jpt20_kt6->cd();
  
  TGraphErrors* jetm_jpt20_kt6_one_jet =
    new TGraphErrors(nMasses,jetm_xaxis,jpt20_kt6_one_jet,err_jetm_xaxis,err_jpt20_kt6_one_jet);
  jetm_jpt20_kt6_one_jet->SetMarkerColor(kGreen);
  jetm_jpt20_kt6_one_jet->SetMarkerStyle(8);
  jetm_jpt20_kt6_one_jet->SetMarkerSize(2);
  TGraphErrors* jetm_jpt20_kt6_merged = 
    new TGraphErrors(nMasses,jetm_xaxis,jpt20_kt6_merged,err_jetm_xaxis,err_jpt20_kt6_merged);
  jetm_jpt20_kt6_merged->SetMarkerColor(kRed);
  jetm_jpt20_kt6_merged->SetMarkerStyle(8);
  jetm_jpt20_kt6_merged->SetMarkerSize(2);
  TGraphErrors* jetm_jpt20_kt6_unmerged = 
    new TGraphErrors(nMasses,jetm_xaxis,jpt20_kt6_unmerged,err_jetm_xaxis,err_jpt20_kt6_unmerged);
  jetm_jpt20_kt6_unmerged->SetMarkerColor(kBlue);
  jetm_jpt20_kt6_unmerged->SetMarkerStyle(8);
  jetm_jpt20_kt6_unmerged->SetMarkerSize(2);

  TMultiGraph* mgraph_jpt20_kt6 = new TMultiGraph();
  mgraph_jpt20_kt6->Add(jetm_jpt20_kt6_one_jet);
  mgraph_jpt20_kt6->Add(jetm_jpt20_kt6_merged);
  mgraph_jpt20_kt6->Add(jetm_jpt20_kt6_unmerged);
  mgraph_jpt20_kt6->Draw("AP");

  mgraph_jpt20_kt6->GetXaxis()->SetTitle("Graviton Mass [GeV]");
  mgraph_jpt20_kt6->GetYaxis()->SetTitle("Fraction of Events");


  
  TLegend* lgnd_jpt20_kt6 = (TLegend*) new TLegend(0.2,0.67,0.5,0.88);
  lgnd_jpt20_kt6->SetFillStyle(1);
  lgnd_jpt20_kt6->SetTextSize(0.035);
  lgnd_jpt20_kt6->AddEntry(jetm_jpt20_kt6_one_jet,"One Jet","P");
  lgnd_jpt20_kt6->AddEntry(jetm_jpt20_kt6_merged,"Jet_M > 60 GeV","P");
  lgnd_jpt20_kt6->AddEntry(jetm_jpt20_kt6_unmerged,"60 < Dijet_M < 105 GeV","P");
  lgnd_jpt20_kt6->Draw();
  

  tc_jpt20_kt6->Update();
  tc_jpt20_kt6->SetGrid();
  tc_jpt20_kt6->SaveAs("../canvases/latest/jpt20_kt6.png");


  //jpt20_kt4
  float jpt20_kt4_one_jet[nMasses] =
    {0.146472,0.0632962,0.0606111,0.0535661,0.08251,0.114034,0.133507};
  float err_jpt20_kt4_one_jet[nMasses] =
    {0.015876,0.0229537,0.0234597,0.024961,0.0201129,0.0171096,0.0158193};
  
  float jpt20_kt4_merged[nMasses] =
    {0.000566818,0.00166744,0.00687171,0.0855388,0.354172,0.50938,0.617854};
  float err_jpt20_kt4_merged[nMasses] =
    {0.242536,0.141421,0.0696733,0.0197527,0.00970782,0.00809537,0.00735354};
  
  float jpt20_kt4_unmerged[nMasses] =
    {0.327687,0.29984,0.320068,0.319494,0.213485,0.120977,0.0817213};
  float err_jpt20_kt4_unmerged[nMasses] =
    {0.0100871,0.0105462,0.0102089,0.0102206,0.0125039,0.0166114,0.0202196};

  
  TCanvas* tc_jpt20_kt4 = new TCanvas("tc_jpt20_kt4","jpt20_kt4",0,0,1280,800);
  tc_jpt20_kt4->cd();
  
  TGraphErrors* jetm_jpt20_kt4_one_jet =
    new TGraphErrors(nMasses,jetm_xaxis,jpt20_kt4_one_jet,err_jetm_xaxis,err_jpt20_kt4_one_jet);
  jetm_jpt20_kt4_one_jet->SetMarkerColor(kGreen);
  jetm_jpt20_kt4_one_jet->SetMarkerStyle(8);
  jetm_jpt20_kt4_one_jet->SetMarkerSize(2);
  TGraphErrors* jetm_jpt20_kt4_merged = 
    new TGraphErrors(nMasses,jetm_xaxis,jpt20_kt4_merged,err_jetm_xaxis,err_jpt20_kt4_merged);
  jetm_jpt20_kt4_merged->SetMarkerColor(kRed);
  jetm_jpt20_kt4_merged->SetMarkerStyle(8);
  jetm_jpt20_kt4_merged->SetMarkerSize(2);
  TGraphErrors* jetm_jpt20_kt4_unmerged = 
    new TGraphErrors(nMasses,jetm_xaxis,jpt20_kt4_unmerged,err_jetm_xaxis,err_jpt20_kt4_unmerged);
  jetm_jpt20_kt4_unmerged->SetMarkerColor(kBlue);
  jetm_jpt20_kt4_unmerged->SetMarkerStyle(8);
  jetm_jpt20_kt4_unmerged->SetMarkerSize(2);

  TMultiGraph* mgraph_jpt20_kt4 = new TMultiGraph();
  mgraph_jpt20_kt4->Add(jetm_jpt20_kt4_one_jet);
  mgraph_jpt20_kt4->Add(jetm_jpt20_kt4_merged);
  mgraph_jpt20_kt4->Add(jetm_jpt20_kt4_unmerged);
  mgraph_jpt20_kt4->Draw("AP");

  mgraph_jpt20_kt4->GetXaxis()->SetTitle("Graviton Mass [GeV]");
  mgraph_jpt20_kt4->GetYaxis()->SetTitle("Fraction of Events");


  
  TLegend* lgnd_jpt20_kt4 = (TLegend*) new TLegend(0.2,0.72,0.5,0.93);
  lgnd_jpt20_kt4->SetFillStyle(1);
  lgnd_jpt20_kt4->SetTextSize(0.035);
  lgnd_jpt20_kt4->AddEntry(jetm_jpt20_kt4_one_jet,"One Jet","P");
  lgnd_jpt20_kt4->AddEntry(jetm_jpt20_kt4_merged,"Jet_M > 60 GeV","P");
  lgnd_jpt20_kt4->AddEntry(jetm_jpt20_kt4_unmerged,"60 < Dijet_M < 105 GeV","P");
  lgnd_jpt20_kt4->Draw();
  

  tc_jpt20_kt4->Update();
  tc_jpt20_kt4->SetGrid();
  tc_jpt20_kt4->SaveAs("../canvases/latest/jpt20_kt4.png");


  //jpt30_kt4
  float jpt30_kt4_one_jet[nMasses] =
    {0.307649,0.155006,0.121789,0.101091,0.147697,0.188476,0.21466};
  float err_jpt30_kt4_one_jet[nMasses] =
    {0.0104105,0.0146679,0.0165499,0.0181698,0.0150329,0.0133085,0.0124757};
  
  float jpt30_kt4_merged[nMasses] =
    {0.000566818,0.00166744,0.00687171,0.0855388,0.354172,0.50938,0.617854};
  float err_jpt30_kt4_merged[nMasses] =
    {0.242536,0.141421,0.0696733,0.0197527,0.00970782,0.00809537,0.00735354};
  
  float jpt30_kt4_unmerged[nMasses] =
    {0.212757,0.255486,0.294316,0.2999,0.19496,0.103118,0.0675554};
  float err_jpt30_kt4_unmerged[nMasses] =
    {0.0125186,0.011425,0.0106461,0.0105491,0.0130845,0.0179925,0.0222387};

  
  TCanvas* tc_jpt30_kt4 = new TCanvas("tc_jpt30_kt4","jpt30_kt4",0,0,1280,800);
  tc_jpt30_kt4->cd();
  
  TGraphErrors* jetm_jpt30_kt4_one_jet =
    new TGraphErrors(nMasses,jetm_xaxis,jpt30_kt4_one_jet,err_jetm_xaxis,err_jpt30_kt4_one_jet);
  jetm_jpt30_kt4_one_jet->SetMarkerColor(kGreen);
  jetm_jpt30_kt4_one_jet->SetMarkerStyle(8);
  jetm_jpt30_kt4_one_jet->SetMarkerSize(2);
  TGraphErrors* jetm_jpt30_kt4_merged = 
    new TGraphErrors(nMasses,jetm_xaxis,jpt30_kt4_merged,err_jetm_xaxis,err_jpt30_kt4_merged);
  jetm_jpt30_kt4_merged->SetMarkerColor(kRed);
  jetm_jpt30_kt4_merged->SetMarkerStyle(8);
  jetm_jpt30_kt4_merged->SetMarkerSize(2);
  TGraphErrors* jetm_jpt30_kt4_unmerged = 
    new TGraphErrors(nMasses,jetm_xaxis,jpt30_kt4_unmerged,err_jetm_xaxis,err_jpt30_kt4_unmerged);
  jetm_jpt30_kt4_unmerged->SetMarkerColor(kBlue);
  jetm_jpt30_kt4_unmerged->SetMarkerStyle(8);
  jetm_jpt30_kt4_unmerged->SetMarkerSize(2);

  TMultiGraph* mgraph_jpt30_kt4 = new TMultiGraph();
  mgraph_jpt30_kt4->SetTitle("AntiKt4 Jet Pt > 30 GeV");
  mgraph_jpt30_kt4->Add(jetm_jpt30_kt4_one_jet);
  mgraph_jpt30_kt4->Add(jetm_jpt30_kt4_merged);
  mgraph_jpt30_kt4->Add(jetm_jpt30_kt4_unmerged);
  mgraph_jpt30_kt4->Draw("AP");

  mgraph_jpt30_kt4->GetXaxis()->SetTitle("Graviton Mass [GeV]");
  mgraph_jpt30_kt4->GetYaxis()->SetTitle("Fraction of Events");


  
  TLegend* lgnd_jpt30_kt4 = (TLegend*) new TLegend(0.2,0.72,0.5,0.93);
  lgnd_jpt30_kt4->SetFillStyle(1);
  lgnd_jpt30_kt4->SetTextSize(0.035);
  lgnd_jpt30_kt4->AddEntry(jetm_jpt30_kt4_one_jet,"One Jet","P");
  lgnd_jpt30_kt4->AddEntry(jetm_jpt30_kt4_merged,"Jet_M > 60 GeV","P");
  lgnd_jpt30_kt4->AddEntry(jetm_jpt30_kt4_unmerged,"60 < Dijet_M < 105 GeV","P");
  lgnd_jpt30_kt4->Draw();
  

  tc_jpt30_kt4->Update();
  tc_jpt30_kt4->SetGrid();
  tc_jpt30_kt4->SaveAs("../canvases/latest/jpt30_kt4.png");

}
