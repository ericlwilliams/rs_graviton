//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Nov 12 10:51:53 2011 by ROOT version 5.28/00b
// from TTree analysisTree/analysisTree
// found on file: mc.mcatnlo.t1.pu.skim.root
//////////////////////////////////////////////////////////

#ifndef verificationPlots_h
#define verificationPlots_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

class verificationPlots : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   Float_t         EventWJetsScaleIQOPT3;
   Float_t         EventWJetsScalePTJMIN10;
   Float_t         EventPileUpReWeight;
   Float_t         EventWeightUpTrigSF;
   Float_t         EventWeightDownTrigSF;
   Float_t         EventWeightUpLepIDSF;
   Float_t         EventWeightDownLepIDSF;
   Float_t         EventWeightUpLepRecoSF;
   Float_t         EventWeightDownLepRecoSF;
   Int_t           nGoodElectrons;
   Int_t           nGoodMuons;
   Int_t           nGoodJets;
   Int_t           nGoodVxp;
   Int_t           RunNum;
   Float_t         RunLumi;
   Int_t           goodLeptonIndex;
   Int_t           goodNeutrinoSolution;
   Float_t         lnuj_lep_pt;
   Float_t         lnuj_lep_energyLossPar;
   Float_t         lnuj_lep_mspt_down;
   Float_t         lnuj_lep_mspt_up;
   Float_t         lnuj_lep_idpt_down;
   Float_t         lnuj_lep_idpt_up;
   Float_t         lnuj_lep_les_up;
   Float_t         lnuj_lep_les_down;
   Float_t         lnuj_lep_ler_up;
   Float_t         lnuj_lep_ler_down;
   Float_t         lnuj_lep_eta;
   Float_t         lnuj_lep_phi;
   Float_t         lead_jet_m;
   Float_t         lead_jet_pt;
   Float_t         lead_jet_jer_scale;
   Float_t         lead_jet_rel_up_jes;
   Float_t         lead_jet_rel_down_jes;
   Float_t         lead_jet_eta;
   Float_t         lead_jet_phi;
   Float_t         second_jet_m;
   Float_t         second_jet_pt;
   Float_t         second_jet_jer_scale;
   Float_t         second_jet_rel_up_jes;
   Float_t         second_jet_rel_down_jes;
   Float_t         second_jet_eta;
   Float_t         second_jet_phi;
   Float_t         third_jet_m;
   Float_t         third_jet_pt;
   Float_t         third_jet_jer_scale;
   Float_t         third_jet_rel_up_jes;
   Float_t         third_jet_rel_down_jes;
   Float_t         third_jet_eta;
   Float_t         third_jet_phi;
   Float_t         fourth_jet_m;
   Float_t         fourth_jet_pt;
   Float_t         fourth_jet_jer_scale;
   Float_t         fourth_jet_rel_up_jes;
   Float_t         fourth_jet_rel_down_jes;
   Float_t         fourth_jet_eta;
   Float_t         fourth_jet_phi;
   Int_t           ctrl_ewk;
   Int_t           ctrl_all;
   Int_t           ctrl_boost1;
   Int_t           ctrl_boost2;
   Int_t           ctrl_ttbar;
   Int_t           ctrl_sig_lowm;
   Int_t           ctrl_sig_highm;
   Float_t         ww_met_etx;
   Float_t         ww_met_ety;
   Float_t         ww_met_et;
   Float_t         ww_ootpu_up_met_etx;
   Float_t         ww_ootpu_up_met_ety;
   Float_t         ww_ootpu_up_met_et;
   Float_t         ww_ootpu_down_met_etx;
   Float_t         ww_ootpu_down_met_ety;
   Float_t         ww_ootpu_down_met_et;
   Float_t         ww_intpu_up_met_etx;
   Float_t         ww_intpu_up_met_ety;
   Float_t         ww_intpu_up_met_et;
   Float_t         ww_intpu_down_met_etx;
   Float_t         ww_intpu_down_met_ety;
   Float_t         ww_intpu_down_met_et;
   Float_t         ww_refutrk_up_met_etx;
   Float_t         ww_refutrk_up_met_ety;
   Float_t         ww_refutrk_up_met_et;
   Float_t         ww_refutrk_down_met_etx;
   Float_t         ww_refutrk_down_met_ety;
   Float_t         ww_refutrk_down_met_et;
   Float_t         ww_uboy_up_met_etx;
   Float_t         ww_uboy_up_met_ety;
   Float_t         ww_uboy_up_met_et;
   Float_t         ww_uboy_down_met_etx;
   Float_t         ww_uboy_down_met_ety;
   Float_t         ww_uboy_down_met_et;
   Float_t         ww_lhco_up_met_etx;
   Float_t         ww_lhco_up_met_ety;
   Float_t         ww_lhco_up_met_et;
   Float_t         ww_lhco_down_met_etx;
   Float_t         ww_lhco_down_met_ety;
   Float_t         ww_lhco_down_met_et;
   Float_t         ww_em_met_etx;
   Float_t         ww_em_met_ety;
   Float_t         ww_em_met_et;
   Float_t         ww_lc_met_etx;
   Float_t         ww_lc_met_ety;
   Float_t         ww_lc_met_et;
   Float_t         ww_lc_topo_met_etx;
   Float_t         ww_lc_topo_met_ety;
   Float_t         ww_lc_topo_met_et;
   Float_t         ww_lc_topo_up_met_etx;
   Float_t         ww_lc_topo_up_met_ety;
   Float_t         ww_lc_topo_up_met_et;
   Float_t         ww_lc_topo_down_met_etx;
   Float_t         ww_lc_topo_down_met_ety;
   Float_t         ww_lc_topo_down_met_et;
   Float_t         ww_jer_met_etx;
   Float_t         ww_jer_met_ety;
   Float_t         ww_jer_met_et;
   Float_t         ww_corr_up_met_etx;
   Float_t         ww_corr_up_met_ety;
   Float_t         ww_corr_up_met_et;
   Float_t         ww_corr_down_met_etx;
   Float_t         ww_corr_down_met_ety;
   Float_t         ww_corr_down_met_et;
   Float_t         lep_met_pt;
   Float_t         lep_met_mt;
   Float_t         lep_nu_m;
   Float_t         lep_met_jet_mt;
   Float_t         lep_nu_jet_m;
   Float_t         lep_nu_dijet_m;
   Float_t         lep_met_dijet_mt;
   Float_t         dijet_m;
   Float_t         dijet_pt;
   Float_t         dijet_dr;
   Float_t         sig_jet_m;
   Float_t         lep_nu_sig_jet_m;
   Float_t         lep_met_sig_jet_mt;
   Float_t         ww_lt;
   Float_t         ww_ht;
   Float_t         ww_st;

   // List of branches
   TBranch        *b_EventWJetsScaleIQOPT3;   //!
   TBranch        *b_EventWJetsScalePTJMIN10;   //!
   TBranch        *b_EventPileUpReWeight;   //!
   TBranch        *b_EventWeightUpTrigSF;   //!
   TBranch        *b_EventWeightDownTrigSF;   //!
   TBranch        *b_EventWeightUpLepIDSF;   //!
   TBranch        *b_EventWeightDownLepIDSF;   //!
   TBranch        *b_EventWeightUpLepRecoSF;   //!
   TBranch        *b_EventWeightDownLepRecoSF;   //!
   TBranch        *b_nGoodElectrons;   //!
   TBranch        *b_nGoodMuons;   //!
   TBranch        *b_nGoodJets;   //!
   TBranch        *b_nGoodVxp;   //!
   TBranch        *b_RunNum;   //!
   TBranch        *b_RunLumi;   //!
   TBranch        *b_goodLeptonIndex;   //!
   TBranch        *b_goodNeutrinoSolution;   //!
   TBranch        *b_lnuj_lep_pt;   //!
   TBranch        *b_lnuj_lep_energyLossPar;   //!
   TBranch        *b_lnuj_lep_mspt_down;   //!
   TBranch        *b_lnuj_lep_mspt_up;   //!
   TBranch        *b_lnuj_lep_idpt_down;   //!
   TBranch        *b_lnuj_lep_idpt_up;   //!
   TBranch        *b_lnuj_lep_les_up;   //!
   TBranch        *b_lnuj_lep_les_down;   //!
   TBranch        *b_lnuj_lep_ler_up;   //!
   TBranch        *b_lnuj_lep_ler_down;   //!
   TBranch        *b_lnuj_lep_eta;   //!
   TBranch        *b_lnuj_lep_phi;   //!
   TBranch        *b_lead_jet_m;   //!
   TBranch        *b_lead_jet_pt;   //!
   TBranch        *b_lead_jet_jer_scale;   //!
   TBranch        *b_lead_jet_rel_up_jes;   //!
   TBranch        *b_lead_jet_rel_down_jes;   //!
   TBranch        *b_lead_jet_eta;   //!
   TBranch        *b_lead_jet_phi;   //!
   TBranch        *b_second_jet_m;   //!
   TBranch        *b_second_jet_pt;   //!
   TBranch        *b_second_jet_jer_scale;   //!
   TBranch        *b_second_jet_rel_up_jes;   //!
   TBranch        *b_second_jet_rel_down_jes;   //!
   TBranch        *b_second_jet_eta;   //!
   TBranch        *b_second_jet_phi;   //!
   TBranch        *b_third_jet_m;   //!
   TBranch        *b_third_jet_pt;   //!
   TBranch        *b_third_jet_jer_scale;   //!
   TBranch        *b_third_jet_rel_up_jes;   //!
   TBranch        *b_third_jet_rel_down_jes;   //!
   TBranch        *b_third_jet_eta;   //!
   TBranch        *b_third_jet_phi;   //!
   TBranch        *b_fourth_jet_m;   //!
   TBranch        *b_fourth_jet_pt;   //!
   TBranch        *b_fourth_jet_jer_scale;   //!
   TBranch        *b_fourth_jet_rel_up_jes;   //!
   TBranch        *b_fourth_jet_rel_down_jes;   //!
   TBranch        *b_fourth_jet_eta;   //!
   TBranch        *b_fourth_jet_phi;   //!
   TBranch        *b_ctrl_ewk;   //!
   TBranch        *b_ctrl_all;   //!
   TBranch        *b_ctrl_boost1;   //!
   TBranch        *b_ctrl_boost2;   //!
   TBranch        *b_ctrl_ttbar;   //!
   TBranch        *b_ctrl_sig_lowm;   //!
   TBranch        *b_ctrl_sig_highm;   //!
   TBranch        *b_ww_met_etx;   //!
   TBranch        *b_ww_met_ety;   //!
   TBranch        *b_ww_met_et;   //!
   TBranch        *b_ww_ootpu_up_met_etx;   //!
   TBranch        *b_ww_ootpu_up_met_ety;   //!
   TBranch        *b_ww_ootpu_up_met_et;   //!
   TBranch        *b_ww_ootpu_down_met_etx;   //!
   TBranch        *b_ww_ootpu_down_met_ety;   //!
   TBranch        *b_ww_ootpu_down_met_et;   //!
   TBranch        *b_ww_intpu_up_met_etx;   //!
   TBranch        *b_ww_intpu_up_met_ety;   //!
   TBranch        *b_ww_intpu_up_met_et;   //!
   TBranch        *b_ww_intpu_down_met_etx;   //!
   TBranch        *b_ww_intpu_down_met_ety;   //!
   TBranch        *b_ww_intpu_down_met_et;   //!
   TBranch        *b_ww_refutrk_up_met_etx;   //!
   TBranch        *b_ww_refutrk_up_met_ety;   //!
   TBranch        *b_ww_refutrk_up_met_et;   //!
   TBranch        *b_ww_refutrk_down_met_etx;   //!
   TBranch        *b_ww_refutrk_down_met_ety;   //!
   TBranch        *b_ww_refutrk_down_met_et;   //!
   TBranch        *b_ww_uboy_up_met_etx;   //!
   TBranch        *b_ww_uboy_up_met_ety;   //!
   TBranch        *b_ww_uboy_up_met_et;   //!
   TBranch        *b_ww_uboy_down_met_etx;   //!
   TBranch        *b_ww_uboy_down_met_ety;   //!
   TBranch        *b_ww_uboy_down_met_et;   //!
   TBranch        *b_ww_lhco_up_met_etx;   //!
   TBranch        *b_ww_lhco_up_met_ety;   //!
   TBranch        *b_ww_lhco_up_met_et;   //!
   TBranch        *b_ww_lhco_down_met_etx;   //!
   TBranch        *b_ww_lhco_down_met_ety;   //!
   TBranch        *b_ww_lhco_down_met_et;   //!
   TBranch        *b_ww_em_met_etx;   //!
   TBranch        *b_ww_em_met_ety;   //!
   TBranch        *b_ww_em_met_et;   //!
   TBranch        *b_ww_lc_met_etx;   //!
   TBranch        *b_ww_lc_met_ety;   //!
   TBranch        *b_ww_lc_met_et;   //!
   TBranch        *b_ww_lc_topo_met_etx;   //!
   TBranch        *b_ww_lc_topo_met_ety;   //!
   TBranch        *b_ww_lc_topo_met_et;   //!
   TBranch        *b_ww_lc_topo_up_met_etx;   //!
   TBranch        *b_ww_lc_topo_up_met_ety;   //!
   TBranch        *b_ww_lc_topo_up_met_et;   //!
   TBranch        *b_ww_lc_topo_down_met_etx;   //!
   TBranch        *b_ww_lc_topo_down_met_ety;   //!
   TBranch        *b_ww_lc_topo_down_met_et;   //!
   TBranch        *b_ww_jer_met_etx;   //!
   TBranch        *b_ww_jer_met_ety;   //!
   TBranch        *b_ww_jer_met_et;   //!
   TBranch        *b_ww_corr_up_met_etx;   //!
   TBranch        *b_ww_corr_up_met_ety;   //!
   TBranch        *b_ww_corr_up_met_et;   //!
   TBranch        *b_ww_corr_down_met_etx;   //!
   TBranch        *b_ww_corr_down_met_ety;   //!
   TBranch        *b_ww_corr_down_met_et;   //!
   TBranch        *b_lep_met_pt;   //!
   TBranch        *b_lep_met_mt;   //!
   TBranch        *b_lep_nu_m;   //!
   TBranch        *b_lep_met_jet_mt;   //!
   TBranch        *b_lep_nu_jet_m;   //!
   TBranch        *b_lep_nu_dijet_m;   //!
   TBranch        *b_lep_met_dijet_mt;   //!
   TBranch        *b_dijet_m;   //!
   TBranch        *b_dijet_pt;   //!
   TBranch        *b_dijet_dr;   //!
   TBranch        *b_sig_jet_m;   //!
   TBranch        *b_lep_nu_sig_jet_m;   //!
   TBranch        *b_lep_met_sig_jet_mt;   //!
   TBranch        *b_ww_lt;   //!
   TBranch        *b_ww_ht;   //!
   TBranch        *b_ww_st;   //!

   verificationPlots(TTree * /*tree*/ =0) { }
   virtual ~verificationPlots() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(verificationPlots,0);
};

#endif

#ifdef verificationPlots_cxx
void verificationPlots::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("EventWJetsScaleIQOPT3", &EventWJetsScaleIQOPT3, &b_EventWJetsScaleIQOPT3);
   fChain->SetBranchAddress("EventWJetsScalePTJMIN10", &EventWJetsScalePTJMIN10, &b_EventWJetsScalePTJMIN10);
   fChain->SetBranchAddress("EventPileUpReWeight", &EventPileUpReWeight, &b_EventPileUpReWeight);
   fChain->SetBranchAddress("EventWeightUpTrigSF", &EventWeightUpTrigSF, &b_EventWeightUpTrigSF);
   fChain->SetBranchAddress("EventWeightDownTrigSF", &EventWeightDownTrigSF, &b_EventWeightDownTrigSF);
   fChain->SetBranchAddress("EventWeightUpLepIDSF", &EventWeightUpLepIDSF, &b_EventWeightUpLepIDSF);
   fChain->SetBranchAddress("EventWeightDownLepIDSF", &EventWeightDownLepIDSF, &b_EventWeightDownLepIDSF);
   fChain->SetBranchAddress("EventWeightUpLepRecoSF", &EventWeightUpLepRecoSF, &b_EventWeightUpLepRecoSF);
   fChain->SetBranchAddress("EventWeightDownLepRecoSF", &EventWeightDownLepRecoSF, &b_EventWeightDownLepRecoSF);
   fChain->SetBranchAddress("nGoodElectrons", &nGoodElectrons, &b_nGoodElectrons);
   fChain->SetBranchAddress("nGoodMuons", &nGoodMuons, &b_nGoodMuons);
   fChain->SetBranchAddress("nGoodJets", &nGoodJets, &b_nGoodJets);
   fChain->SetBranchAddress("nGoodVxp", &nGoodVxp, &b_nGoodVxp);
   fChain->SetBranchAddress("RunNum", &RunNum, &b_RunNum);
   fChain->SetBranchAddress("RunLumi", &RunLumi, &b_RunLumi);
   fChain->SetBranchAddress("goodLeptonIndex", &goodLeptonIndex, &b_goodLeptonIndex);
   fChain->SetBranchAddress("goodNeutrinoSolution", &goodNeutrinoSolution, &b_goodNeutrinoSolution);
   fChain->SetBranchAddress("lnuj_lep_pt", &lnuj_lep_pt, &b_lnuj_lep_pt);
   fChain->SetBranchAddress("lnuj_lep_energyLossPar", &lnuj_lep_energyLossPar, &b_lnuj_lep_energyLossPar);
   fChain->SetBranchAddress("lnuj_lep_mspt_down", &lnuj_lep_mspt_down, &b_lnuj_lep_mspt_down);
   fChain->SetBranchAddress("lnuj_lep_mspt_up", &lnuj_lep_mspt_up, &b_lnuj_lep_mspt_up);
   fChain->SetBranchAddress("lnuj_lep_idpt_down", &lnuj_lep_idpt_down, &b_lnuj_lep_idpt_down);
   fChain->SetBranchAddress("lnuj_lep_idpt_up", &lnuj_lep_idpt_up, &b_lnuj_lep_idpt_up);
   fChain->SetBranchAddress("lnuj_lep_les_up", &lnuj_lep_les_up, &b_lnuj_lep_les_up);
   fChain->SetBranchAddress("lnuj_lep_les_down", &lnuj_lep_les_down, &b_lnuj_lep_les_down);
   fChain->SetBranchAddress("lnuj_lep_ler_up", &lnuj_lep_ler_up, &b_lnuj_lep_ler_up);
   fChain->SetBranchAddress("lnuj_lep_ler_down", &lnuj_lep_ler_down, &b_lnuj_lep_ler_down);
   fChain->SetBranchAddress("lnuj_lep_eta", &lnuj_lep_eta, &b_lnuj_lep_eta);
   fChain->SetBranchAddress("lnuj_lep_phi", &lnuj_lep_phi, &b_lnuj_lep_phi);
   fChain->SetBranchAddress("lead_jet_m", &lead_jet_m, &b_lead_jet_m);
   fChain->SetBranchAddress("lead_jet_pt", &lead_jet_pt, &b_lead_jet_pt);
   fChain->SetBranchAddress("lead_jet_jer_scale", &lead_jet_jer_scale, &b_lead_jet_jer_scale);
   fChain->SetBranchAddress("lead_jet_rel_up_jes", &lead_jet_rel_up_jes, &b_lead_jet_rel_up_jes);
   fChain->SetBranchAddress("lead_jet_rel_down_jes", &lead_jet_rel_down_jes, &b_lead_jet_rel_down_jes);
   fChain->SetBranchAddress("lead_jet_eta", &lead_jet_eta, &b_lead_jet_eta);
   fChain->SetBranchAddress("lead_jet_phi", &lead_jet_phi, &b_lead_jet_phi);
   fChain->SetBranchAddress("second_jet_m", &second_jet_m, &b_second_jet_m);
   fChain->SetBranchAddress("second_jet_pt", &second_jet_pt, &b_second_jet_pt);
   fChain->SetBranchAddress("second_jet_jer_scale", &second_jet_jer_scale, &b_second_jet_jer_scale);
   fChain->SetBranchAddress("second_jet_rel_up_jes", &second_jet_rel_up_jes, &b_second_jet_rel_up_jes);
   fChain->SetBranchAddress("second_jet_rel_down_jes", &second_jet_rel_down_jes, &b_second_jet_rel_down_jes);
   fChain->SetBranchAddress("second_jet_eta", &second_jet_eta, &b_second_jet_eta);
   fChain->SetBranchAddress("second_jet_phi", &second_jet_phi, &b_second_jet_phi);
   fChain->SetBranchAddress("third_jet_m", &third_jet_m, &b_third_jet_m);
   fChain->SetBranchAddress("third_jet_pt", &third_jet_pt, &b_third_jet_pt);
   fChain->SetBranchAddress("third_jet_jer_scale", &third_jet_jer_scale, &b_third_jet_jer_scale);
   fChain->SetBranchAddress("third_jet_rel_up_jes", &third_jet_rel_up_jes, &b_third_jet_rel_up_jes);
   fChain->SetBranchAddress("third_jet_rel_down_jes", &third_jet_rel_down_jes, &b_third_jet_rel_down_jes);
   fChain->SetBranchAddress("third_jet_eta", &third_jet_eta, &b_third_jet_eta);
   fChain->SetBranchAddress("third_jet_phi", &third_jet_phi, &b_third_jet_phi);
   fChain->SetBranchAddress("fourth_jet_m", &fourth_jet_m, &b_fourth_jet_m);
   fChain->SetBranchAddress("fourth_jet_pt", &fourth_jet_pt, &b_fourth_jet_pt);
   fChain->SetBranchAddress("fourth_jet_jer_scale", &fourth_jet_jer_scale, &b_fourth_jet_jer_scale);
   fChain->SetBranchAddress("fourth_jet_rel_up_jes", &fourth_jet_rel_up_jes, &b_fourth_jet_rel_up_jes);
   fChain->SetBranchAddress("fourth_jet_rel_down_jes", &fourth_jet_rel_down_jes, &b_fourth_jet_rel_down_jes);
   fChain->SetBranchAddress("fourth_jet_eta", &fourth_jet_eta, &b_fourth_jet_eta);
   fChain->SetBranchAddress("fourth_jet_phi", &fourth_jet_phi, &b_fourth_jet_phi);
   fChain->SetBranchAddress("ctrl_ewk", &ctrl_ewk, &b_ctrl_ewk);
   fChain->SetBranchAddress("ctrl_all", &ctrl_all, &b_ctrl_all);
   fChain->SetBranchAddress("ctrl_boost1", &ctrl_boost1, &b_ctrl_boost1);
   fChain->SetBranchAddress("ctrl_boost2", &ctrl_boost2, &b_ctrl_boost2);
   fChain->SetBranchAddress("ctrl_ttbar", &ctrl_ttbar, &b_ctrl_ttbar);
   fChain->SetBranchAddress("ctrl_sig_lowm", &ctrl_sig_lowm, &b_ctrl_sig_lowm);
   fChain->SetBranchAddress("ctrl_sig_highm", &ctrl_sig_highm, &b_ctrl_sig_highm);
   fChain->SetBranchAddress("ww_met_etx", &ww_met_etx, &b_ww_met_etx);
   fChain->SetBranchAddress("ww_met_ety", &ww_met_ety, &b_ww_met_ety);
   fChain->SetBranchAddress("ww_met_et", &ww_met_et, &b_ww_met_et);
   fChain->SetBranchAddress("ww_ootpu_up_met_etx", &ww_ootpu_up_met_etx, &b_ww_ootpu_up_met_etx);
   fChain->SetBranchAddress("ww_ootpu_up_met_ety", &ww_ootpu_up_met_ety, &b_ww_ootpu_up_met_ety);
   fChain->SetBranchAddress("ww_ootpu_up_met_et", &ww_ootpu_up_met_et, &b_ww_ootpu_up_met_et);
   fChain->SetBranchAddress("ww_ootpu_down_met_etx", &ww_ootpu_down_met_etx, &b_ww_ootpu_down_met_etx);
   fChain->SetBranchAddress("ww_ootpu_down_met_ety", &ww_ootpu_down_met_ety, &b_ww_ootpu_down_met_ety);
   fChain->SetBranchAddress("ww_ootpu_down_met_et", &ww_ootpu_down_met_et, &b_ww_ootpu_down_met_et);
   fChain->SetBranchAddress("ww_intpu_up_met_etx", &ww_intpu_up_met_etx, &b_ww_intpu_up_met_etx);
   fChain->SetBranchAddress("ww_intpu_up_met_ety", &ww_intpu_up_met_ety, &b_ww_intpu_up_met_ety);
   fChain->SetBranchAddress("ww_intpu_up_met_et", &ww_intpu_up_met_et, &b_ww_intpu_up_met_et);
   fChain->SetBranchAddress("ww_intpu_down_met_etx", &ww_intpu_down_met_etx, &b_ww_intpu_down_met_etx);
   fChain->SetBranchAddress("ww_intpu_down_met_ety", &ww_intpu_down_met_ety, &b_ww_intpu_down_met_ety);
   fChain->SetBranchAddress("ww_intpu_down_met_et", &ww_intpu_down_met_et, &b_ww_intpu_down_met_et);
   fChain->SetBranchAddress("ww_refutrk_up_met_etx", &ww_refutrk_up_met_etx, &b_ww_refutrk_up_met_etx);
   fChain->SetBranchAddress("ww_refutrk_up_met_ety", &ww_refutrk_up_met_ety, &b_ww_refutrk_up_met_ety);
   fChain->SetBranchAddress("ww_refutrk_up_met_et", &ww_refutrk_up_met_et, &b_ww_refutrk_up_met_et);
   fChain->SetBranchAddress("ww_refutrk_down_met_etx", &ww_refutrk_down_met_etx, &b_ww_refutrk_down_met_etx);
   fChain->SetBranchAddress("ww_refutrk_down_met_ety", &ww_refutrk_down_met_ety, &b_ww_refutrk_down_met_ety);
   fChain->SetBranchAddress("ww_refutrk_down_met_et", &ww_refutrk_down_met_et, &b_ww_refutrk_down_met_et);
   fChain->SetBranchAddress("ww_uboy_up_met_etx", &ww_uboy_up_met_etx, &b_ww_uboy_up_met_etx);
   fChain->SetBranchAddress("ww_uboy_up_met_ety", &ww_uboy_up_met_ety, &b_ww_uboy_up_met_ety);
   fChain->SetBranchAddress("ww_uboy_up_met_et", &ww_uboy_up_met_et, &b_ww_uboy_up_met_et);
   fChain->SetBranchAddress("ww_uboy_down_met_etx", &ww_uboy_down_met_etx, &b_ww_uboy_down_met_etx);
   fChain->SetBranchAddress("ww_uboy_down_met_ety", &ww_uboy_down_met_ety, &b_ww_uboy_down_met_ety);
   fChain->SetBranchAddress("ww_uboy_down_met_et", &ww_uboy_down_met_et, &b_ww_uboy_down_met_et);
   fChain->SetBranchAddress("ww_lhco_up_met_etx", &ww_lhco_up_met_etx, &b_ww_lhco_up_met_etx);
   fChain->SetBranchAddress("ww_lhco_up_met_ety", &ww_lhco_up_met_ety, &b_ww_lhco_up_met_ety);
   fChain->SetBranchAddress("ww_lhco_up_met_et", &ww_lhco_up_met_et, &b_ww_lhco_up_met_et);
   fChain->SetBranchAddress("ww_lhco_down_met_etx", &ww_lhco_down_met_etx, &b_ww_lhco_down_met_etx);
   fChain->SetBranchAddress("ww_lhco_down_met_ety", &ww_lhco_down_met_ety, &b_ww_lhco_down_met_ety);
   fChain->SetBranchAddress("ww_lhco_down_met_et", &ww_lhco_down_met_et, &b_ww_lhco_down_met_et);
   fChain->SetBranchAddress("ww_em_met_etx", &ww_em_met_etx, &b_ww_em_met_etx);
   fChain->SetBranchAddress("ww_em_met_ety", &ww_em_met_ety, &b_ww_em_met_ety);
   fChain->SetBranchAddress("ww_em_met_et", &ww_em_met_et, &b_ww_em_met_et);
   fChain->SetBranchAddress("ww_lc_met_etx", &ww_lc_met_etx, &b_ww_lc_met_etx);
   fChain->SetBranchAddress("ww_lc_met_ety", &ww_lc_met_ety, &b_ww_lc_met_ety);
   fChain->SetBranchAddress("ww_lc_met_et", &ww_lc_met_et, &b_ww_lc_met_et);
   fChain->SetBranchAddress("ww_lc_topo_met_etx", &ww_lc_topo_met_etx, &b_ww_lc_topo_met_etx);
   fChain->SetBranchAddress("ww_lc_topo_met_ety", &ww_lc_topo_met_ety, &b_ww_lc_topo_met_ety);
   fChain->SetBranchAddress("ww_lc_topo_met_et", &ww_lc_topo_met_et, &b_ww_lc_topo_met_et);
   fChain->SetBranchAddress("ww_lc_topo_up_met_etx", &ww_lc_topo_up_met_etx, &b_ww_lc_topo_up_met_etx);
   fChain->SetBranchAddress("ww_lc_topo_up_met_ety", &ww_lc_topo_up_met_ety, &b_ww_lc_topo_up_met_ety);
   fChain->SetBranchAddress("ww_lc_topo_up_met_et", &ww_lc_topo_up_met_et, &b_ww_lc_topo_up_met_et);
   fChain->SetBranchAddress("ww_lc_topo_down_met_etx", &ww_lc_topo_down_met_etx, &b_ww_lc_topo_down_met_etx);
   fChain->SetBranchAddress("ww_lc_topo_down_met_ety", &ww_lc_topo_down_met_ety, &b_ww_lc_topo_down_met_ety);
   fChain->SetBranchAddress("ww_lc_topo_down_met_et", &ww_lc_topo_down_met_et, &b_ww_lc_topo_down_met_et);
   fChain->SetBranchAddress("ww_jer_met_etx", &ww_jer_met_etx, &b_ww_jer_met_etx);
   fChain->SetBranchAddress("ww_jer_met_ety", &ww_jer_met_ety, &b_ww_jer_met_ety);
   fChain->SetBranchAddress("ww_jer_met_et", &ww_jer_met_et, &b_ww_jer_met_et);
   fChain->SetBranchAddress("ww_corr_up_met_etx", &ww_corr_up_met_etx, &b_ww_corr_up_met_etx);
   fChain->SetBranchAddress("ww_corr_up_met_ety", &ww_corr_up_met_ety, &b_ww_corr_up_met_ety);
   fChain->SetBranchAddress("ww_corr_up_met_et", &ww_corr_up_met_et, &b_ww_corr_up_met_et);
   fChain->SetBranchAddress("ww_corr_down_met_etx", &ww_corr_down_met_etx, &b_ww_corr_down_met_etx);
   fChain->SetBranchAddress("ww_corr_down_met_ety", &ww_corr_down_met_ety, &b_ww_corr_down_met_ety);
   fChain->SetBranchAddress("ww_corr_down_met_et", &ww_corr_down_met_et, &b_ww_corr_down_met_et);
   fChain->SetBranchAddress("lep_met_pt", &lep_met_pt, &b_lep_met_pt);
   fChain->SetBranchAddress("lep_met_mt", &lep_met_mt, &b_lep_met_mt);
   fChain->SetBranchAddress("lep_nu_m", &lep_nu_m, &b_lep_nu_m);
   fChain->SetBranchAddress("lep_met_jet_mt", &lep_met_jet_mt, &b_lep_met_jet_mt);
   fChain->SetBranchAddress("lep_nu_jet_m", &lep_nu_jet_m, &b_lep_nu_jet_m);
   fChain->SetBranchAddress("lep_nu_dijet_m", &lep_nu_dijet_m, &b_lep_nu_dijet_m);
   fChain->SetBranchAddress("lep_met_dijet_mt", &lep_met_dijet_mt, &b_lep_met_dijet_mt);
   fChain->SetBranchAddress("dijet_m", &dijet_m, &b_dijet_m);
   fChain->SetBranchAddress("dijet_pt", &dijet_pt, &b_dijet_pt);
   fChain->SetBranchAddress("dijet_dr", &dijet_dr, &b_dijet_dr);
   fChain->SetBranchAddress("sig_jet_m", &sig_jet_m, &b_sig_jet_m);
   fChain->SetBranchAddress("lep_nu_sig_jet_m", &lep_nu_sig_jet_m, &b_lep_nu_sig_jet_m);
   fChain->SetBranchAddress("lep_met_sig_jet_mt", &lep_met_sig_jet_mt, &b_lep_met_sig_jet_mt);
   fChain->SetBranchAddress("ww_lt", &ww_lt, &b_ww_lt);
   fChain->SetBranchAddress("ww_ht", &ww_ht, &b_ww_ht);
   fChain->SetBranchAddress("ww_st", &ww_st, &b_ww_st);
}

Bool_t verificationPlots::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef verificationPlots_cxx
