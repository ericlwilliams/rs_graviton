//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Jan 24 11:56:48 2012 by ROOT version 5.28/00b
// from TTree analysisTree/analysisTree
// found on file: mc.alpgen.wenu.np0.pu.skim.root
//////////////////////////////////////////////////////////

#ifndef mc11c_h
#define mc11c_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

class mc11c : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   Float_t         evt_pu_weight;
   Float_t         trig_sf;
   Float_t         TriggerWeight;
   Float_t         lep_id_sf;
   Float_t         LeptonRecoSF;
   Float_t         evt_weight_trig_sf_up;
   Float_t         evt_weight_trig_sf_down;
   Float_t         evt_weight_id_sf_up;
   Float_t         evt_weight_id_sf_down;
   Float_t         evt_weight_reco_sf_up;
   Float_t         evt_weight_reco_sf_down;
   Int_t           nGoodElectrons;
   Int_t           nGoodMuons;
   Int_t           nGoodJets;
   Int_t           nGoodVxp;
   Float_t         avgIntPerXing;
   Int_t           RunNum;
   Int_t           EvtNum;
   Float_t         RunLumi;
   Int_t           goodLeptonIndex;
   Int_t           goodNeutrinoSolution;
   Float_t         lnuj_lep_pt;
   Float_t         lnuj_lep_les_up;
   Float_t         lnuj_lep_les_down;
   Float_t         lnuj_lep_ler_up;
   Float_t         lnuj_lep_ler_down;
   Float_t         lnuj_lep_eta;
   Float_t         lnuj_lep_phi;
   Float_t         lead_jet_m;
   Float_t         lead_jet_pt;
   Float_t         lead_jet_jer_scale;
   Float_t         lead_jet_jer_syst;
   Float_t         lead_jet_rel_up_jes;
   Float_t         lead_jet_rel_down_jes;
   Float_t         lead_jet_eta;
   Float_t         lead_jet_phi;
   Float_t         second_jet_m;
   Float_t         second_jet_pt;
   Float_t         second_jet_jer_scale;
   Float_t         second_jet_jer_syst;
   Float_t         second_jet_rel_up_jes;
   Float_t         second_jet_rel_down_jes;
   Float_t         second_jet_eta;
   Float_t         second_jet_phi;
   Float_t         third_jet_m;
   Float_t         third_jet_pt;
   Float_t         third_jet_jer_scale;
   Float_t         third_jet_jer_syst;
   Float_t         third_jet_rel_up_jes;
   Float_t         third_jet_rel_down_jes;
   Float_t         third_jet_eta;
   Float_t         third_jet_phi;
   Float_t         fourth_jet_m;
   Float_t         fourth_jet_pt;
   Float_t         fourth_jet_jer_scale;
   Float_t         fourth_jet_jer_syst;
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
   Float_t         ww_met_phi;
   Float_t         ww_met_et;
   Float_t         ww_met_set;
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
   Float_t         ww_jer_up_met_phi;
   Float_t         ww_jer_up_met_et;
   Float_t         ww_jer_down_met_phi;
   Float_t         ww_jer_down_met_et;
   Float_t         ww_jes_up_met_phi;
   Float_t         ww_jes_up_met_et;
   Float_t         ww_jes_down_met_phi;
   Float_t         ww_jes_down_met_et;
   Float_t         ww_coef_up_met_phi;
   Float_t         ww_coef_up_met_et;
   Float_t         ww_coef_down_met_phi;
   Float_t         ww_coef_down_met_et;
   Float_t         ww_sjets_up_met_phi;
   Float_t         ww_sjets_up_met_et;
   Float_t         ww_sjets_down_met_phi;
   Float_t         ww_sjets_down_met_et;
   Float_t         ww_les_down_met_phi;
   Float_t         ww_les_down_met_et;
   Float_t         ww_les_up_met_phi;
   Float_t         ww_les_up_met_et;
   Float_t         ww_ler_down_met_phi;
   Float_t         ww_ler_down_met_et;
   Float_t         ww_ler_up_met_phi;
   Float_t         ww_ler_up_met_et;
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
   TBranch        *b_evt_pu_weight;   //!
   TBranch        *b_trig_sf;   //!
   TBranch        *b_TriggerWeight;   //!
   TBranch        *b_lep_id_sf;   //!
   TBranch        *b_LeptonRecoSF;   //!
   TBranch        *b_evt_weight_trig_sf_up;   //!
   TBranch        *b_evt_weight_trig_sf_down;   //!
   TBranch        *b_evt_weight_id_sf_up;   //!
   TBranch        *b_evt_weight_id_sf_down;   //!
   TBranch        *b_evt_weight_reco_sf_up;   //!
   TBranch        *b_evt_weight_reco_sf_down;   //!
   TBranch        *b_nGoodElectrons;   //!
   TBranch        *b_nGoodMuons;   //!
   TBranch        *b_nGoodJets;   //!
   TBranch        *b_nGoodVxp;   //!
   TBranch        *b_avgIntPerXing;   //!
   TBranch        *b_RunNum;   //!
   TBranch        *b_EvtNum;   //!
   TBranch        *b_RunLumi;   //!
   TBranch        *b_goodLeptonIndex;   //!
   TBranch        *b_goodNeutrinoSolution;   //!
   TBranch        *b_lnuj_lep_pt;   //!
   TBranch        *b_lnuj_lep_les_up;   //!
   TBranch        *b_lnuj_lep_les_down;   //!
   TBranch        *b_lnuj_lep_ler_up;   //!
   TBranch        *b_lnuj_lep_ler_down;   //!
   TBranch        *b_lnuj_lep_eta;   //!
   TBranch        *b_lnuj_lep_phi;   //!
   TBranch        *b_lead_jet_m;   //!
   TBranch        *b_lead_jet_pt;   //!
   TBranch        *b_lead_jet_jer_scale;   //!
   TBranch        *b_lead_jet_jer_syst;   //!
   TBranch        *b_lead_jet_rel_up_jes;   //!
   TBranch        *b_lead_jet_rel_down_jes;   //!
   TBranch        *b_lead_jet_eta;   //!
   TBranch        *b_lead_jet_phi;   //!
   TBranch        *b_second_jet_m;   //!
   TBranch        *b_second_jet_pt;   //!
   TBranch        *b_second_jet_jer_scale;   //!
   TBranch        *b_second_jet_jer_syst;   //!
   TBranch        *b_second_jet_rel_up_jes;   //!
   TBranch        *b_second_jet_rel_down_jes;   //!
   TBranch        *b_second_jet_eta;   //!
   TBranch        *b_second_jet_phi;   //!
   TBranch        *b_third_jet_m;   //!
   TBranch        *b_third_jet_pt;   //!
   TBranch        *b_third_jet_jer_scale;   //!
   TBranch        *b_third_jet_jer_syst;   //!
   TBranch        *b_third_jet_rel_up_jes;   //!
   TBranch        *b_third_jet_rel_down_jes;   //!
   TBranch        *b_third_jet_eta;   //!
   TBranch        *b_third_jet_phi;   //!
   TBranch        *b_fourth_jet_m;   //!
   TBranch        *b_fourth_jet_pt;   //!
   TBranch        *b_fourth_jet_jer_scale;   //!
   TBranch        *b_fourth_jet_jer_syst;   //!
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
   TBranch        *b_ww_met_phi;   //!
   TBranch        *b_ww_met_et;   //!
   TBranch        *b_ww_met_set;   //!
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
   TBranch        *b_ww_jer_up_met_phi;   //!
   TBranch        *b_ww_jer_up_met_et;   //!
   TBranch        *b_ww_jer_down_met_phi;   //!
   TBranch        *b_ww_jer_down_met_et;   //!
   TBranch        *b_ww_jes_up_met_phi;   //!
   TBranch        *b_ww_jes_up_met_et;   //!
   TBranch        *b_ww_jes_down_met_phi;   //!
   TBranch        *b_ww_jes_down_met_et;   //!
   TBranch        *b_ww_coef_up_met_phi;   //!
   TBranch        *b_ww_coef_up_met_et;   //!
   TBranch        *b_ww_coef_down_met_phi;   //!
   TBranch        *b_ww_coef_down_met_et;   //!
   TBranch        *b_ww_sjets_up_met_phi;   //!
   TBranch        *b_ww_sjets_up_met_et;   //!
   TBranch        *b_ww_sjets_down_met_phi;   //!
   TBranch        *b_ww_sjets_down_met_et;   //!
   TBranch        *b_ww_les_down_met_phi;   //!
   TBranch        *b_ww_les_down_met_et;   //!
   TBranch        *b_ww_les_up_met_phi;   //!
   TBranch        *b_ww_les_up_met_et;   //!
   TBranch        *b_ww_ler_down_met_phi;   //!
   TBranch        *b_ww_ler_down_met_et;   //!
   TBranch        *b_ww_ler_up_met_phi;   //!
   TBranch        *b_ww_ler_up_met_et;   //!
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

   mc11c(TTree * /*tree*/ =0) { }
   virtual ~mc11c() { }
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

   ClassDef(mc11c,0);
};

#endif

#ifdef mc11c_cxx
void mc11c::Init(TTree *tree)
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

   fChain->SetBranchAddress("evt_pu_weight", &evt_pu_weight, &b_evt_pu_weight);
   fChain->SetBranchAddress("trig_sf", &trig_sf, &b_trig_sf);
   fChain->SetBranchAddress("TriggerWeight", &TriggerWeight, &b_TriggerWeight);
   fChain->SetBranchAddress("lep_id_sf", &lep_id_sf, &b_lep_id_sf);
   fChain->SetBranchAddress("LeptonRecoSF", lep_reco_sf, &b_LeptonRecoSF);
   fChain->SetBranchAddress("evt_weight_trig_sf_up", &evt_weight_trig_sf_up, &b_evt_weight_trig_sf_up);
   fChain->SetBranchAddress("evt_weight_trig_sf_down", &evt_weight_trig_sf_down, &b_evt_weight_trig_sf_down);
   fChain->SetBranchAddress("evt_weight_id_sf_up", &evt_weight_id_sf_up, &b_evt_weight_id_sf_up);
   fChain->SetBranchAddress("evt_weight_id_sf_down", &evt_weight_id_sf_down, &b_evt_weight_id_sf_down);
   fChain->SetBranchAddress("evt_weight_reco_sf_up", &evt_weight_reco_sf_up, &b_evt_weight_reco_sf_up);
   fChain->SetBranchAddress("evt_weight_reco_sf_down", &evt_weight_reco_sf_down, &b_evt_weight_reco_sf_down);
   fChain->SetBranchAddress("nGoodElectrons", &nGoodElectrons, &b_nGoodElectrons);
   fChain->SetBranchAddress("nGoodMuons", &nGoodMuons, &b_nGoodMuons);
   fChain->SetBranchAddress("nGoodJets", &nGoodJets, &b_nGoodJets);
   fChain->SetBranchAddress("nGoodVxp", &nGoodVxp, &b_nGoodVxp);
   fChain->SetBranchAddress("avgIntPerXing", &avgIntPerXing, &b_avgIntPerXing);
   fChain->SetBranchAddress("RunNum", &RunNum, &b_RunNum);
   fChain->SetBranchAddress("EvtNum", &EvtNum, &b_EvtNum);
   fChain->SetBranchAddress("RunLumi", &RunLumi, &b_RunLumi);
   fChain->SetBranchAddress("goodLeptonIndex", &goodLeptonIndex, &b_goodLeptonIndex);
   fChain->SetBranchAddress("goodNeutrinoSolution", &goodNeutrinoSolution, &b_goodNeutrinoSolution);
   fChain->SetBranchAddress("lnuj_lep_pt", &lnuj_lep_pt, &b_lnuj_lep_pt);
   fChain->SetBranchAddress("lnuj_lep_les_up", &lnuj_lep_les_up, &b_lnuj_lep_les_up);
   fChain->SetBranchAddress("lnuj_lep_les_down", &lnuj_lep_les_down, &b_lnuj_lep_les_down);
   fChain->SetBranchAddress("lnuj_lep_ler_up", &lnuj_lep_ler_up, &b_lnuj_lep_ler_up);
   fChain->SetBranchAddress("lnuj_lep_ler_down", &lnuj_lep_ler_down, &b_lnuj_lep_ler_down);
   fChain->SetBranchAddress("lnuj_lep_eta", &lnuj_lep_eta, &b_lnuj_lep_eta);
   fChain->SetBranchAddress("lnuj_lep_phi", &lnuj_lep_phi, &b_lnuj_lep_phi);
   fChain->SetBranchAddress("lead_jet_m", &lead_jet_m, &b_lead_jet_m);
   fChain->SetBranchAddress("lead_jet_pt", &lead_jet_pt, &b_lead_jet_pt);
   fChain->SetBranchAddress("lead_jet_jer_scale", &lead_jet_jer_scale, &b_lead_jet_jer_scale);
   fChain->SetBranchAddress("lead_jet_jer_syst", &lead_jet_jer_syst, &b_lead_jet_jer_syst);
   fChain->SetBranchAddress("lead_jet_rel_up_jes", &lead_jet_rel_up_jes, &b_lead_jet_rel_up_jes);
   fChain->SetBranchAddress("lead_jet_rel_down_jes", &lead_jet_rel_down_jes, &b_lead_jet_rel_down_jes);
   fChain->SetBranchAddress("lead_jet_eta", &lead_jet_eta, &b_lead_jet_eta);
   fChain->SetBranchAddress("lead_jet_phi", &lead_jet_phi, &b_lead_jet_phi);
   fChain->SetBranchAddress("second_jet_m", &second_jet_m, &b_second_jet_m);
   fChain->SetBranchAddress("second_jet_pt", &second_jet_pt, &b_second_jet_pt);
   fChain->SetBranchAddress("second_jet_jer_scale", &second_jet_jer_scale, &b_second_jet_jer_scale);
   fChain->SetBranchAddress("second_jet_jer_syst", &second_jet_jer_syst, &b_second_jet_jer_syst);
   fChain->SetBranchAddress("second_jet_rel_up_jes", &second_jet_rel_up_jes, &b_second_jet_rel_up_jes);
   fChain->SetBranchAddress("second_jet_rel_down_jes", &second_jet_rel_down_jes, &b_second_jet_rel_down_jes);
   fChain->SetBranchAddress("second_jet_eta", &second_jet_eta, &b_second_jet_eta);
   fChain->SetBranchAddress("second_jet_phi", &second_jet_phi, &b_second_jet_phi);
   fChain->SetBranchAddress("third_jet_m", &third_jet_m, &b_third_jet_m);
   fChain->SetBranchAddress("third_jet_pt", &third_jet_pt, &b_third_jet_pt);
   fChain->SetBranchAddress("third_jet_jer_scale", &third_jet_jer_scale, &b_third_jet_jer_scale);
   fChain->SetBranchAddress("third_jet_jer_syst", &third_jet_jer_syst, &b_third_jet_jer_syst);
   fChain->SetBranchAddress("third_jet_rel_up_jes", &third_jet_rel_up_jes, &b_third_jet_rel_up_jes);
   fChain->SetBranchAddress("third_jet_rel_down_jes", &third_jet_rel_down_jes, &b_third_jet_rel_down_jes);
   fChain->SetBranchAddress("third_jet_eta", &third_jet_eta, &b_third_jet_eta);
   fChain->SetBranchAddress("third_jet_phi", &third_jet_phi, &b_third_jet_phi);
   fChain->SetBranchAddress("fourth_jet_m", &fourth_jet_m, &b_fourth_jet_m);
   fChain->SetBranchAddress("fourth_jet_pt", &fourth_jet_pt, &b_fourth_jet_pt);
   fChain->SetBranchAddress("fourth_jet_jer_scale", &fourth_jet_jer_scale, &b_fourth_jet_jer_scale);
   fChain->SetBranchAddress("fourth_jet_jer_syst", &fourth_jet_jer_syst, &b_fourth_jet_jer_syst);
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
   fChain->SetBranchAddress("ww_met_phi", &ww_met_phi, &b_ww_met_phi);
   fChain->SetBranchAddress("ww_met_et", &ww_met_et, &b_ww_met_et);
   fChain->SetBranchAddress("ww_met_set", &ww_met_set, &b_ww_met_set);
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
   fChain->SetBranchAddress("ww_jer_up_met_phi", &ww_jer_up_met_phi, &b_ww_jer_up_met_phi);
   fChain->SetBranchAddress("ww_jer_up_met_et", &ww_jer_up_met_et, &b_ww_jer_up_met_et);
   fChain->SetBranchAddress("ww_jer_down_met_phi", &ww_jer_down_met_phi, &b_ww_jer_down_met_phi);
   fChain->SetBranchAddress("ww_jer_down_met_et", &ww_jer_down_met_et, &b_ww_jer_down_met_et);
   fChain->SetBranchAddress("ww_jes_up_met_phi", &ww_jes_up_met_phi, &b_ww_jes_up_met_phi);
   fChain->SetBranchAddress("ww_jes_up_met_et", &ww_jes_up_met_et, &b_ww_jes_up_met_et);
   fChain->SetBranchAddress("ww_jes_down_met_phi", &ww_jes_down_met_phi, &b_ww_jes_down_met_phi);
   fChain->SetBranchAddress("ww_jes_down_met_et", &ww_jes_down_met_et, &b_ww_jes_down_met_et);
   fChain->SetBranchAddress("ww_coef_up_met_phi", &ww_coef_up_met_phi, &b_ww_coef_up_met_phi);
   fChain->SetBranchAddress("ww_coef_up_met_et", &ww_coef_up_met_et, &b_ww_coef_up_met_et);
   fChain->SetBranchAddress("ww_coef_down_met_phi", &ww_coef_down_met_phi, &b_ww_coef_down_met_phi);
   fChain->SetBranchAddress("ww_coef_down_met_et", &ww_coef_down_met_et, &b_ww_coef_down_met_et);
   fChain->SetBranchAddress("ww_sjets_up_met_phi", &ww_sjets_up_met_phi, &b_ww_sjets_up_met_phi);
   fChain->SetBranchAddress("ww_sjets_up_met_et", &ww_sjets_up_met_et, &b_ww_sjets_up_met_et);
   fChain->SetBranchAddress("ww_sjets_down_met_phi", &ww_sjets_down_met_phi, &b_ww_sjets_down_met_phi);
   fChain->SetBranchAddress("ww_sjets_down_met_et", &ww_sjets_down_met_et, &b_ww_sjets_down_met_et);
   fChain->SetBranchAddress("ww_les_down_met_phi", &ww_les_down_met_phi, &b_ww_les_down_met_phi);
   fChain->SetBranchAddress("ww_les_down_met_et", &ww_les_down_met_et, &b_ww_les_down_met_et);
   fChain->SetBranchAddress("ww_les_up_met_phi", &ww_les_up_met_phi, &b_ww_les_up_met_phi);
   fChain->SetBranchAddress("ww_les_up_met_et", &ww_les_up_met_et, &b_ww_les_up_met_et);
   fChain->SetBranchAddress("ww_ler_down_met_phi", &ww_ler_down_met_phi, &b_ww_ler_down_met_phi);
   fChain->SetBranchAddress("ww_ler_down_met_et", &ww_ler_down_met_et, &b_ww_ler_down_met_et);
   fChain->SetBranchAddress("ww_ler_up_met_phi", &ww_ler_up_met_phi, &b_ww_ler_up_met_phi);
   fChain->SetBranchAddress("ww_ler_up_met_et", &ww_ler_up_met_et, &b_ww_ler_up_met_et);
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

Bool_t mc11c::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef mc11c_cxx
