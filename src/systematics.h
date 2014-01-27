//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Jan 24 11:56:48 2012 by ROOT version 5.28/00b
// from TTree analysisTree/analysisTree
// found on file: mc.alpgen.wenu.np0.pu.skim.root
//////////////////////////////////////////////////////////

#ifndef systematics_h
#define systematics_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TLorentzVector.h>

class systematics : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   Float_t         evt_pu_weight;
   Float_t         evt_alpgen_weight;
   Float_t         trig_sf;
   Float_t         TriggerWeight;
   Float_t         lep_id_sf;
   Float_t         lep_reco_sf;
   Float_t         evt_weight_trig_sf_up;
   Float_t         evt_weight_trig_sf_down;
   Float_t         evt_weight_iso_sf_up;
   Float_t         evt_weight_iso_sf_down;
   Float_t         evt_weight_id_sf_up;
   Float_t         evt_weight_id_sf_down;
   Float_t         evt_weight_reco_sf_up;
   Float_t         evt_weight_reco_sf_down;
   Int_t           nGoodElectrons;
   Int_t           nGoodMuons;
   Int_t           nGoodJets;
   Int_t           nGoodVxp;
   Int_t           qcd_event;
   Float_t         avgIntPerXing;
   Int_t           RunNum;
   Int_t           EvtNum;
   Float_t         RunLumi;
   Int_t           goodLeptonIndex;
   Int_t           goodNeutrinoSolution;
   Float_t         nu_pt;
   Float_t         nu_eta;
   Float_t         nu_phi;
   Float_t         nu_e;
   Float_t         nu_jes_up_pt;
   Float_t         nu_jes_up_eta;
   Float_t         nu_jes_up_phi;
   Float_t         nu_jes_up_e;
   Float_t         nu_jes_down_pt;
   Float_t         nu_jes_down_eta;
   Float_t         nu_jes_down_phi;
   Float_t         nu_jes_down_e;
   Float_t         lvjj_lep_pt;
   Float_t         lvjj_lep_d0sig;
   Float_t         lvjj_lep_calo_iso;
   Float_t         lvjj_lep_sig_diff_qoverp;
   Float_t         lvjj_lep_les_up;
   Float_t         lvjj_lep_les_down;
   Float_t         lvjj_lep_ler_up;
   Float_t         lvjj_lep_ler_down;
   Float_t         lvjj_lep_eta;
   Float_t         lvjj_lep_phi;
   Float_t         lead_jet_m;
   Float_t         lead_jet_pt;
   Float_t         lead_jet_jer_scale;
   Float_t         lead_jet_jer_up;
   Float_t         lead_jet_jer_down;
   Float_t         lead_jet_jes_up;
   Float_t         lead_jet_jes_down;
   Float_t         lead_jet_eta;
   Float_t         lead_jet_phi;
   Float_t         second_jet_m;
   Float_t         second_jet_pt;
   Float_t         second_jet_jer_scale;
   Float_t         second_jet_jer_up;
   Float_t         second_jet_jer_down;
   Float_t         second_jet_jes_up;
   Float_t         second_jet_jes_down;
   Float_t         second_jet_eta;
   Float_t         second_jet_phi;
   Float_t         third_jet_m;
   Float_t         third_jet_pt;
   Float_t         third_jet_jer_scale;
   Float_t         third_jet_jer_up;
   Float_t         third_jet_jer_down;
   Float_t         third_jet_jes_up;
   Float_t         third_jet_jes_down;
   Float_t         third_jet_eta;
   Float_t         third_jet_phi;
   Float_t         fourth_jet_m;
   Float_t         fourth_jet_pt;
   Float_t         fourth_jet_jer_scale;
   Float_t         fourth_jet_jer_up;
   Float_t         fourth_jet_jer_down;
   Float_t         fourth_jet_jes_up;
   Float_t         fourth_jet_jes_down;
   Float_t         fourth_jet_eta;
   Float_t         fourth_jet_phi;
   Int_t           ctrl_ewk;
   Int_t           ctrl_all;
   Int_t           ctrl_boost1;
   Int_t           ctrl_boost2;
   Int_t           ctrl_ttbar;
   Int_t           ctrl_sig_lowm;
   Int_t           ctrl_sig_highm;
   Float_t         lvjj_met_phi;
   Float_t         lvjj_met_et;
   Float_t         lvjj_met_set;
   Float_t         rf_met_phi;
   Float_t         rf_met_et;
   Float_t         rf_met_set;
   Float_t         lvjj_ootpu_up_met_etx;
   Float_t         lvjj_ootpu_up_met_ety;
   Float_t         lvjj_ootpu_up_met_et;
   Float_t         lvjj_ootpu_down_met_etx;
   Float_t         lvjj_ootpu_down_met_ety;
   Float_t         lvjj_ootpu_down_met_et;
   Float_t         lvjj_intpu_up_met_etx;
   Float_t         lvjj_intpu_up_met_ety;
   Float_t         lvjj_intpu_up_met_et;
   Float_t         lvjj_intpu_down_met_etx;
   Float_t         lvjj_intpu_down_met_ety;
   Float_t         lvjj_intpu_down_met_et;
   Float_t         lvjj_jer_up_met_phi;
   Float_t         lvjj_jer_up_met_et;
   Float_t         lvjj_jer_down_met_phi;
   Float_t         lvjj_jer_down_met_et;
   Float_t         lvjj_jes_up_met_phi;
   Float_t         lvjj_jes_up_met_et;
   Float_t         lvjj_jes_down_met_phi;
   Float_t         lvjj_jes_down_met_et;
   Float_t         lvjj_coef_up_met_phi;
   Float_t         lvjj_coef_up_met_et;
   Float_t         lvjj_coef_down_met_phi;
   Float_t         lvjj_coef_down_met_et;
   Float_t         lvjj_allcl_up_met_phi;
   Float_t         lvjj_allcl_up_met_et;
   Float_t         lvjj_allcl_down_met_phi;
   Float_t         lvjj_allcl_down_met_et;
   Float_t         lvjj_sjets_up_met_phi;
   Float_t         lvjj_sjets_up_met_et;
   Float_t         lvjj_sjets_down_met_phi;
   Float_t         lvjj_sjets_down_met_et;
   Float_t         lvjj_metpu_up_met_phi;
   Float_t         lvjj_metpu_up_met_et;
   Float_t         lvjj_metpu_down_met_phi;
   Float_t         lvjj_metpu_down_met_et;
   Float_t         lvjj_les_down_met_phi;
   Float_t         lvjj_les_down_met_et;
   Float_t         lvjj_les_up_met_phi;
   Float_t         lvjj_les_up_met_et;
   Float_t         lvjj_ler_down_met_phi;
   Float_t         lvjj_ler_down_met_et;
   Float_t         lvjj_ler_up_met_phi;
   Float_t         lvjj_ler_up_met_et;
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
   Float_t         lvjj_lt;
   Float_t         lvjj_ht;
   Float_t         lvjj_st;

   // List of branches
   TBranch        *b_evt_pu_weight;   //!
   TBranch        *b_evt_alpgen_weight;   //!
   TBranch        *b_trig_sf;   //!
   TBranch        *b_TriggerWeight;   //!
   TBranch        *b_lep_id_sf;   //!
   TBranch        *b_lep_reco_sf;   //!
   TBranch        *b_evt_weight_trig_sf_up;   //!
   TBranch        *b_evt_weight_trig_sf_down;   //!
   TBranch        *b_evt_weight_id_sf_up;   //!
   TBranch        *b_evt_weight_id_sf_down;   //!
   TBranch        *b_evt_weight_iso_sf_up;   //!
   TBranch        *b_evt_weight_iso_sf_down;   //!
   TBranch        *b_evt_weight_reco_sf_up;   //!
   TBranch        *b_evt_weight_reco_sf_down;   //!
   TBranch        *b_nGoodElectrons;   //!
   TBranch        *b_nGoodMuons;   //!
   TBranch        *b_nGoodJets;   //!
   TBranch        *b_nGoodVxp;   //!
   TBranch        *b_qcd_event;   //!
   TBranch        *b_avgIntPerXing;   //!
   TBranch        *b_RunNum;   //!
   TBranch        *b_EvtNum;   //!
   TBranch        *b_RunLumi;   //!
   TBranch        *b_goodLeptonIndex;   //!
   TBranch        *b_goodNeutrinoSolution;   //!
   TBranch        *b_lvjj_lep_pt;   //!
   TBranch        *b_lvjj_lep_d0sig;   //!
   TBranch        *b_lvjj_lep_calo_iso;   //!
   TBranch        *b_lvjj_lep_sig_diff_qoverp;   //!
   TBranch        *b_lvjj_lep_les_up;   //!
   TBranch        *b_lvjj_lep_les_down;   //!
   TBranch        *b_lvjj_lep_ler_up;   //!
   TBranch        *b_lvjj_lep_ler_down;   //!
   TBranch        *b_lvjj_lep_eta;   //!
   TBranch        *b_lvjj_lep_phi;   //!
   TBranch        *b_lead_jet_m;   //!
   TBranch        *b_lead_jet_pt;   //!
   TBranch        *b_lead_jet_jer_scale;   //!
   TBranch        *b_lead_jet_jer_up;   //!
   TBranch        *b_lead_jet_jer_down;   //!
   TBranch        *b_lead_jet_jes_up;   //!
   TBranch        *b_lead_jet_jes_down;   //!
   TBranch        *b_lead_jet_eta;   //!
   TBranch        *b_lead_jet_phi;   //!
   TBranch        *b_second_jet_m;   //!
   TBranch        *b_second_jet_pt;   //!
   TBranch        *b_second_jet_jer_scale;   //!
   TBranch        *b_second_jet_jer_up;   //!
   TBranch        *b_second_jet_jer_down;   //!
   TBranch        *b_second_jet_jes_up;   //!
   TBranch        *b_second_jet_jes_down;   //!
   TBranch        *b_second_jet_eta;   //!
   TBranch        *b_second_jet_phi;   //!
   TBranch        *b_third_jet_m;   //!
   TBranch        *b_third_jet_pt;   //!
   TBranch        *b_third_jet_jer_scale;   //!
   TBranch        *b_third_jet_jer_up;   //!
   TBranch        *b_third_jet_jer_down;   //!
   TBranch        *b_third_jet_jes_up;   //!
   TBranch        *b_third_jet_jes_down;   //!
   TBranch        *b_third_jet_eta;   //!
   TBranch        *b_third_jet_phi;   //!
   TBranch        *b_fourth_jet_m;   //!
   TBranch        *b_fourth_jet_pt;   //!
   TBranch        *b_fourth_jet_jer_scale;   //!
   TBranch        *b_fourth_jet_jer_up;   //!
   TBranch        *b_fourth_jet_jer_down;   //!
   TBranch        *b_fourth_jet_jes_up;   //!
   TBranch        *b_fourth_jet_jes_down;   //!
   TBranch        *b_fourth_jet_eta;   //!
   TBranch        *b_fourth_jet_phi;   //!
   TBranch        *b_ctrl_ewk;   //!
   TBranch        *b_ctrl_all;   //!
   TBranch        *b_ctrl_boost1;   //!
   TBranch        *b_ctrl_boost2;   //!
   TBranch        *b_ctrl_ttbar;   //!
   TBranch        *b_ctrl_sig_lowm;   //!
   TBranch        *b_ctrl_sig_highm;   //!
   TBranch        *b_lvjj_met_phi;   //!
   TBranch        *b_lvjj_met_et;   //!
   TBranch        *b_lvjj_met_set;   //!
   TBranch        *b_rf_met_phi;   //!
   TBranch        *b_rf_met_et;   //!
   TBranch        *b_rf_met_set;   //!
   TBranch        *b_lvjj_ootpu_up_met_etx;   //!
   TBranch        *b_lvjj_ootpu_up_met_ety;   //!
   TBranch        *b_lvjj_ootpu_up_met_et;   //!
   TBranch        *b_lvjj_ootpu_down_met_etx;   //!
   TBranch        *b_lvjj_ootpu_down_met_ety;   //!
   TBranch        *b_lvjj_ootpu_down_met_et;   //!
   TBranch        *b_lvjj_intpu_up_met_etx;   //!
   TBranch        *b_lvjj_intpu_up_met_ety;   //!
   TBranch        *b_lvjj_intpu_up_met_et;   //!
   TBranch        *b_lvjj_intpu_down_met_etx;   //!
   TBranch        *b_lvjj_intpu_down_met_ety;   //!
   TBranch        *b_lvjj_intpu_down_met_et;   //!
   TBranch        *b_lvjj_jer_up_met_phi;   //!
   TBranch        *b_lvjj_jer_up_met_et;   //!
   TBranch        *b_lvjj_jer_down_met_phi;   //!
   TBranch        *b_lvjj_jer_down_met_et;   //!
   TBranch        *b_lvjj_jes_up_met_phi;   //!
   TBranch        *b_lvjj_jes_up_met_et;   //!
   TBranch        *b_lvjj_jes_down_met_phi;   //!
   TBranch        *b_lvjj_jes_down_met_et;   //!
   TBranch        *b_lvjj_coef_up_met_phi;   //!
   TBranch        *b_lvjj_coef_up_met_et;   //!
   TBranch        *b_lvjj_coef_down_met_phi;   //!
   TBranch        *b_lvjj_coef_down_met_et;   //!
   TBranch        *b_lvjj_allcl_up_met_phi;   //!
   TBranch        *b_lvjj_allcl_up_met_et;   //!
   TBranch        *b_lvjj_allcl_down_met_phi;   //!
   TBranch        *b_lvjj_allcl_down_met_et;   //!
   TBranch        *b_lvjj_sjets_up_met_phi;   //!
   TBranch        *b_lvjj_sjets_up_met_et;   //!
   TBranch        *b_lvjj_sjets_down_met_phi;   //!
   TBranch        *b_lvjj_sjets_down_met_et;   //!
   TBranch        *b_lvjj_metpu_up_met_phi;   //!
   TBranch        *b_lvjj_metpu_up_met_et;   //!
   TBranch        *b_lvjj_metpu_down_met_phi;   //!
   TBranch        *b_lvjj_metpu_down_met_et;   //!
   TBranch        *b_lvjj_les_down_met_phi;   //!
   TBranch        *b_lvjj_les_down_met_et;   //!
   TBranch        *b_lvjj_les_up_met_phi;   //!
   TBranch        *b_lvjj_les_up_met_et;   //!
   TBranch        *b_lvjj_ler_down_met_phi;   //!
   TBranch        *b_lvjj_ler_down_met_et;   //!
   TBranch        *b_lvjj_ler_up_met_phi;   //!
   TBranch        *b_lvjj_ler_up_met_et;   //!
   TBranch        *b_nu_pt;   //!
   TBranch        *b_nu_eta;   //!
   TBranch        *b_nu_phi;   //!
   TBranch        *b_nu_e;   //!
   TBranch        *b_nu_jes_up_pt;   //!
   TBranch        *b_nu_jes_up_eta;   //!
   TBranch        *b_nu_jes_up_phi;   //!
   TBranch        *b_nu_jes_up_e;   //!
   TBranch        *b_nu_jes_down_pt;   //!
   TBranch        *b_nu_jes_down_eta;   //!
   TBranch        *b_nu_jes_down_phi;   //!
   TBranch        *b_nu_jes_down_e;   //!
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
   TBranch        *b_lvjj_lt;   //!
   TBranch        *b_lvjj_ht;   //!
   TBranch        *b_lvjj_st;   //!

   systematics(TTree * /*tree*/ =0) { }
   virtual ~systematics() { }
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
   virtual bool    PassSigWW(float cur_lep_met_pt, TLorentzVector tlv_lead_jet, TLorentzVector tlv_second_jet);
   virtual bool    PassSigWZ(float cur_lep_met_pt, TLorentzVector tlv_lead_jet, TLorentzVector tlv_second_jet);
   virtual bool    PassHighM(float cur_lep_met_pt, TLorentzVector tlv_lead_jet, TLorentzVector tlv_second_jet);
   virtual bool    PassHighMnm1(float cur_lep_met_pt, TLorentzVector tlv_lead_jet, TLorentzVector tlv_second_jet);

   ClassDef(systematics,0);
};

#endif

#ifdef systematics_cxx
void systematics::Init(TTree *tree)
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
   fChain->SetBranchAddress("evt_alpgen_weight", &evt_alpgen_weight, &b_evt_alpgen_weight);
   fChain->SetBranchAddress("trig_sf", &trig_sf, &b_trig_sf);
   fChain->SetBranchAddress("TriggerWeight", &TriggerWeight, &b_TriggerWeight);
   fChain->SetBranchAddress("lep_id_sf", &lep_id_sf, &b_lep_id_sf);
   fChain->SetBranchAddress("lep_reco_sf", &lep_reco_sf, &b_lep_reco_sf);
   fChain->SetBranchAddress("evt_weight_trig_sf_up", &evt_weight_trig_sf_up, &b_evt_weight_trig_sf_up);
   fChain->SetBranchAddress("evt_weight_trig_sf_down", &evt_weight_trig_sf_down, &b_evt_weight_trig_sf_down);
   fChain->SetBranchAddress("evt_weight_id_sf_up", &evt_weight_id_sf_up, &b_evt_weight_id_sf_up);
   fChain->SetBranchAddress("evt_weight_id_sf_down", &evt_weight_id_sf_down, &b_evt_weight_id_sf_down);
   fChain->SetBranchAddress("evt_weight_iso_sf_up", &evt_weight_iso_sf_up, &b_evt_weight_iso_sf_up);
   fChain->SetBranchAddress("evt_weight_iso_sf_down", &evt_weight_iso_sf_down, &b_evt_weight_iso_sf_down);
   fChain->SetBranchAddress("evt_weight_reco_sf_up", &evt_weight_reco_sf_up, &b_evt_weight_reco_sf_up);
   fChain->SetBranchAddress("evt_weight_reco_sf_down", &evt_weight_reco_sf_down, &b_evt_weight_reco_sf_down);
   fChain->SetBranchAddress("nGoodElectrons", &nGoodElectrons, &b_nGoodElectrons);
   fChain->SetBranchAddress("nGoodMuons", &nGoodMuons, &b_nGoodMuons);
   fChain->SetBranchAddress("nGoodJets", &nGoodJets, &b_nGoodJets);
   fChain->SetBranchAddress("nGoodVxp", &nGoodVxp, &b_nGoodVxp);
   fChain->SetBranchAddress("qcd_event", &qcd_event, &b_qcd_event);
   fChain->SetBranchAddress("avgIntPerXing", &avgIntPerXing, &b_avgIntPerXing);
   fChain->SetBranchAddress("RunNum", &RunNum, &b_RunNum);
   fChain->SetBranchAddress("EvtNum", &EvtNum, &b_EvtNum);
   fChain->SetBranchAddress("RunLumi", &RunLumi, &b_RunLumi);
   fChain->SetBranchAddress("goodLeptonIndex", &goodLeptonIndex, &b_goodLeptonIndex);
   fChain->SetBranchAddress("goodNeutrinoSolution", &goodNeutrinoSolution, &b_goodNeutrinoSolution);
   fChain->SetBranchAddress("lvjj_lep_pt", &lvjj_lep_pt, &b_lvjj_lep_pt);
   fChain->SetBranchAddress("lvjj_lep_d0sig", &lvjj_lep_d0sig, &b_lvjj_lep_d0sig);
   fChain->SetBranchAddress("lvjj_lep_calo_iso", &lvjj_lep_calo_iso, &b_lvjj_lep_calo_iso);
   fChain->SetBranchAddress("lvjj_lep_sig_diff_qoverp", &lvjj_lep_sig_diff_qoverp, &b_lvjj_lep_sig_diff_qoverp);
   fChain->SetBranchAddress("lvjj_lep_les_up", &lvjj_lep_les_up, &b_lvjj_lep_les_up);
   fChain->SetBranchAddress("lvjj_lep_les_down", &lvjj_lep_les_down, &b_lvjj_lep_les_down);
   fChain->SetBranchAddress("lvjj_lep_ler_up", &lvjj_lep_ler_up, &b_lvjj_lep_ler_up);
   fChain->SetBranchAddress("lvjj_lep_ler_down", &lvjj_lep_ler_down, &b_lvjj_lep_ler_down);
   fChain->SetBranchAddress("lvjj_lep_eta", &lvjj_lep_eta, &b_lvjj_lep_eta);
   fChain->SetBranchAddress("lvjj_lep_phi", &lvjj_lep_phi, &b_lvjj_lep_phi);
   fChain->SetBranchAddress("lead_jet_m", &lead_jet_m, &b_lead_jet_m);
   fChain->SetBranchAddress("lead_jet_pt", &lead_jet_pt, &b_lead_jet_pt);
   fChain->SetBranchAddress("lead_jet_jer_scale", &lead_jet_jer_scale, &b_lead_jet_jer_scale);
   fChain->SetBranchAddress("lead_jet_jer_up", &lead_jet_jer_up, &b_lead_jet_jer_up);
   fChain->SetBranchAddress("lead_jet_jer_down", &lead_jet_jer_down, &b_lead_jet_jer_down);   
   fChain->SetBranchAddress("lead_jet_jes_up", &lead_jet_jes_up, &b_lead_jet_jes_up);
   fChain->SetBranchAddress("lead_jet_jes_down", &lead_jet_jes_down, &b_lead_jet_jes_down);
   fChain->SetBranchAddress("lead_jet_eta", &lead_jet_eta, &b_lead_jet_eta);
   fChain->SetBranchAddress("lead_jet_phi", &lead_jet_phi, &b_lead_jet_phi);
   fChain->SetBranchAddress("second_jet_m", &second_jet_m, &b_second_jet_m);
   fChain->SetBranchAddress("second_jet_pt", &second_jet_pt, &b_second_jet_pt);
   fChain->SetBranchAddress("second_jet_jer_scale", &second_jet_jer_scale, &b_second_jet_jer_scale);
   fChain->SetBranchAddress("second_jet_jer_up", &second_jet_jer_up, &b_second_jet_jer_up);
   fChain->SetBranchAddress("second_jet_jer_down", &second_jet_jer_down, &b_second_jet_jer_down);
   fChain->SetBranchAddress("second_jet_jes_up", &second_jet_jes_up, &b_second_jet_jes_up);
   fChain->SetBranchAddress("second_jet_jes_down", &second_jet_jes_down, &b_second_jet_jes_down);
   fChain->SetBranchAddress("second_jet_eta", &second_jet_eta, &b_second_jet_eta);
   fChain->SetBranchAddress("second_jet_phi", &second_jet_phi, &b_second_jet_phi);
   fChain->SetBranchAddress("third_jet_m", &third_jet_m, &b_third_jet_m);
   fChain->SetBranchAddress("third_jet_pt", &third_jet_pt, &b_third_jet_pt);
   fChain->SetBranchAddress("third_jet_jer_scale", &third_jet_jer_scale, &b_third_jet_jer_scale);
   fChain->SetBranchAddress("third_jet_jer_up", &third_jet_jer_up, &b_third_jet_jer_up);
   fChain->SetBranchAddress("third_jet_jer_down", &third_jet_jer_down, &b_third_jet_jer_down);
   fChain->SetBranchAddress("third_jet_jes_up", &third_jet_jes_up, &b_third_jet_jes_up);
   fChain->SetBranchAddress("third_jet_jes_down", &third_jet_jes_down, &b_third_jet_jes_down);
   fChain->SetBranchAddress("third_jet_eta", &third_jet_eta, &b_third_jet_eta);
   fChain->SetBranchAddress("third_jet_phi", &third_jet_phi, &b_third_jet_phi);
   fChain->SetBranchAddress("fourth_jet_m", &fourth_jet_m, &b_fourth_jet_m);
   fChain->SetBranchAddress("fourth_jet_pt", &fourth_jet_pt, &b_fourth_jet_pt);
   fChain->SetBranchAddress("fourth_jet_jer_scale", &fourth_jet_jer_scale, &b_fourth_jet_jer_scale);
   fChain->SetBranchAddress("fourth_jet_jer_up", &fourth_jet_jer_up, &b_fourth_jet_jer_up);
   fChain->SetBranchAddress("fourth_jet_jer_down", &fourth_jet_jer_down, &b_fourth_jet_jer_down);
   fChain->SetBranchAddress("fourth_jet_jes_up", &fourth_jet_jes_up, &b_fourth_jet_jes_up);
   fChain->SetBranchAddress("fourth_jet_jes_down", &fourth_jet_jes_down, &b_fourth_jet_jes_down);
   fChain->SetBranchAddress("fourth_jet_eta", &fourth_jet_eta, &b_fourth_jet_eta);
   fChain->SetBranchAddress("fourth_jet_phi", &fourth_jet_phi, &b_fourth_jet_phi);
   fChain->SetBranchAddress("ctrl_ewk", &ctrl_ewk, &b_ctrl_ewk);
   fChain->SetBranchAddress("ctrl_all", &ctrl_all, &b_ctrl_all);
   fChain->SetBranchAddress("ctrl_boost1", &ctrl_boost1, &b_ctrl_boost1);
   fChain->SetBranchAddress("ctrl_boost2", &ctrl_boost2, &b_ctrl_boost2);
   fChain->SetBranchAddress("ctrl_ttbar", &ctrl_ttbar, &b_ctrl_ttbar);
   fChain->SetBranchAddress("ctrl_sig_lowm", &ctrl_sig_lowm, &b_ctrl_sig_lowm);
   fChain->SetBranchAddress("ctrl_sig_highm", &ctrl_sig_highm, &b_ctrl_sig_highm);
   fChain->SetBranchAddress("lvjj_met_phi", &lvjj_met_phi, &b_lvjj_met_phi);
   fChain->SetBranchAddress("lvjj_met_et", &lvjj_met_et, &b_lvjj_met_et);
   fChain->SetBranchAddress("lvjj_met_set", &lvjj_met_set, &b_lvjj_met_set);
   fChain->SetBranchAddress("rf_met_phi", &rf_met_phi, &b_rf_met_phi);
   fChain->SetBranchAddress("rf_met_et", &rf_met_et, &b_rf_met_et);
   fChain->SetBranchAddress("rf_met_set", &rf_met_set, &b_rf_met_set);
   fChain->SetBranchAddress("lvjj_ootpu_up_met_etx", &lvjj_ootpu_up_met_etx, &b_lvjj_ootpu_up_met_etx);
   fChain->SetBranchAddress("lvjj_ootpu_up_met_ety", &lvjj_ootpu_up_met_ety, &b_lvjj_ootpu_up_met_ety);
   fChain->SetBranchAddress("lvjj_ootpu_up_met_et", &lvjj_ootpu_up_met_et, &b_lvjj_ootpu_up_met_et);
   fChain->SetBranchAddress("lvjj_ootpu_down_met_etx", &lvjj_ootpu_down_met_etx, &b_lvjj_ootpu_down_met_etx);
   fChain->SetBranchAddress("lvjj_ootpu_down_met_ety", &lvjj_ootpu_down_met_ety, &b_lvjj_ootpu_down_met_ety);
   fChain->SetBranchAddress("lvjj_ootpu_down_met_et", &lvjj_ootpu_down_met_et, &b_lvjj_ootpu_down_met_et);
   fChain->SetBranchAddress("lvjj_intpu_up_met_etx", &lvjj_intpu_up_met_etx, &b_lvjj_intpu_up_met_etx);
   fChain->SetBranchAddress("lvjj_intpu_up_met_ety", &lvjj_intpu_up_met_ety, &b_lvjj_intpu_up_met_ety);
   fChain->SetBranchAddress("lvjj_intpu_up_met_et", &lvjj_intpu_up_met_et, &b_lvjj_intpu_up_met_et);
   fChain->SetBranchAddress("lvjj_intpu_down_met_etx", &lvjj_intpu_down_met_etx, &b_lvjj_intpu_down_met_etx);
   fChain->SetBranchAddress("lvjj_intpu_down_met_ety", &lvjj_intpu_down_met_ety, &b_lvjj_intpu_down_met_ety);
   fChain->SetBranchAddress("lvjj_intpu_down_met_et", &lvjj_intpu_down_met_et, &b_lvjj_intpu_down_met_et);
   fChain->SetBranchAddress("lvjj_jer_up_met_phi", &lvjj_jer_up_met_phi, &b_lvjj_jer_up_met_phi);
   fChain->SetBranchAddress("lvjj_jer_up_met_et", &lvjj_jer_up_met_et, &b_lvjj_jer_up_met_et);
   fChain->SetBranchAddress("lvjj_jer_down_met_phi", &lvjj_jer_down_met_phi, &b_lvjj_jer_down_met_phi);
   fChain->SetBranchAddress("lvjj_jer_down_met_et", &lvjj_jer_down_met_et, &b_lvjj_jer_down_met_et);
   fChain->SetBranchAddress("lvjj_jes_up_met_phi", &lvjj_jes_up_met_phi, &b_lvjj_jes_up_met_phi);
   fChain->SetBranchAddress("lvjj_jes_up_met_et", &lvjj_jes_up_met_et, &b_lvjj_jes_up_met_et);
   fChain->SetBranchAddress("lvjj_jes_down_met_phi", &lvjj_jes_down_met_phi, &b_lvjj_jes_down_met_phi);
   fChain->SetBranchAddress("lvjj_jes_down_met_et", &lvjj_jes_down_met_et, &b_lvjj_jes_down_met_et);
   fChain->SetBranchAddress("lvjj_coef_up_met_phi", &lvjj_coef_up_met_phi, &b_lvjj_coef_up_met_phi);
   fChain->SetBranchAddress("lvjj_coef_up_met_et", &lvjj_coef_up_met_et, &b_lvjj_coef_up_met_et);
   fChain->SetBranchAddress("lvjj_coef_down_met_phi", &lvjj_coef_down_met_phi, &b_lvjj_coef_down_met_phi);
   fChain->SetBranchAddress("lvjj_coef_down_met_et", &lvjj_coef_down_met_et, &b_lvjj_coef_down_met_et);
   fChain->SetBranchAddress("lvjj_allcl_up_met_phi", &lvjj_allcl_up_met_phi, &b_lvjj_allcl_up_met_phi);
   fChain->SetBranchAddress("lvjj_allcl_up_met_et", &lvjj_allcl_up_met_et, &b_lvjj_allcl_up_met_et);
   fChain->SetBranchAddress("lvjj_allcl_down_met_phi", &lvjj_allcl_down_met_phi, &b_lvjj_allcl_down_met_phi);
   fChain->SetBranchAddress("lvjj_allcl_down_met_et", &lvjj_allcl_down_met_et, &b_lvjj_allcl_down_met_et);
   fChain->SetBranchAddress("lvjj_sjets_up_met_phi", &lvjj_sjets_up_met_phi, &b_lvjj_sjets_up_met_phi);
   fChain->SetBranchAddress("lvjj_sjets_up_met_et", &lvjj_sjets_up_met_et, &b_lvjj_sjets_up_met_et);
   fChain->SetBranchAddress("lvjj_sjets_down_met_phi", &lvjj_sjets_down_met_phi, &b_lvjj_sjets_down_met_phi);
   fChain->SetBranchAddress("lvjj_sjets_down_met_et", &lvjj_sjets_down_met_et, &b_lvjj_sjets_down_met_et);
   fChain->SetBranchAddress("lvjj_metpu_up_met_phi", &lvjj_metpu_up_met_phi, &b_lvjj_metpu_up_met_phi);
   fChain->SetBranchAddress("lvjj_metpu_up_met_et", &lvjj_metpu_up_met_et, &b_lvjj_metpu_up_met_et);
   fChain->SetBranchAddress("lvjj_metpu_down_met_phi", &lvjj_metpu_down_met_phi, &b_lvjj_metpu_down_met_phi);
   fChain->SetBranchAddress("lvjj_metpu_down_met_et", &lvjj_metpu_down_met_et, &b_lvjj_metpu_down_met_et);
   fChain->SetBranchAddress("lvjj_les_down_met_phi", &lvjj_les_down_met_phi, &b_lvjj_les_down_met_phi);
   fChain->SetBranchAddress("lvjj_les_down_met_et", &lvjj_les_down_met_et, &b_lvjj_les_down_met_et);
   fChain->SetBranchAddress("lvjj_les_up_met_phi", &lvjj_les_up_met_phi, &b_lvjj_les_up_met_phi);
   fChain->SetBranchAddress("lvjj_les_up_met_et", &lvjj_les_up_met_et, &b_lvjj_les_up_met_et);
   fChain->SetBranchAddress("lvjj_ler_down_met_phi", &lvjj_ler_down_met_phi, &b_lvjj_ler_down_met_phi);
   fChain->SetBranchAddress("lvjj_ler_down_met_et", &lvjj_ler_down_met_et, &b_lvjj_ler_down_met_et);
   fChain->SetBranchAddress("lvjj_ler_up_met_phi", &lvjj_ler_up_met_phi, &b_lvjj_ler_up_met_phi);
   fChain->SetBranchAddress("lvjj_ler_up_met_et", &lvjj_ler_up_met_et, &b_lvjj_ler_up_met_et);
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
   fChain->SetBranchAddress("lvjj_lt", &lvjj_lt, &b_lvjj_lt);
   fChain->SetBranchAddress("lvjj_ht", &lvjj_ht, &b_lvjj_ht);
   fChain->SetBranchAddress("lvjj_st", &lvjj_st, &b_lvjj_st);
   fChain->SetBranchAddress("nu_pt", &nu_pt, &b_nu_pt);
   fChain->SetBranchAddress("nu_eta", &nu_eta, &b_nu_eta);
   fChain->SetBranchAddress("nu_phi", &nu_phi, &b_nu_phi);
   fChain->SetBranchAddress("nu_e", &nu_e, &b_nu_e);
   fChain->SetBranchAddress("nu_jes_up_pt", &nu_jes_up_pt, &b_nu_jes_up_pt);
   fChain->SetBranchAddress("nu_jes_up_eta", &nu_jes_up_eta, &b_nu_jes_up_eta);
   fChain->SetBranchAddress("nu_jes_up_phi", &nu_jes_up_phi, &b_nu_jes_up_phi);
   fChain->SetBranchAddress("nu_jes_up_e", &nu_jes_up_e, &b_nu_jes_up_e);
   fChain->SetBranchAddress("nu_jes_down_pt", &nu_jes_down_pt, &b_nu_jes_down_pt);
   fChain->SetBranchAddress("nu_jes_down_eta", &nu_jes_down_eta, &b_nu_jes_down_eta);
   fChain->SetBranchAddress("nu_jes_down_phi", &nu_jes_down_phi, &b_nu_jes_down_phi);
   fChain->SetBranchAddress("nu_jes_down_e", &nu_jes_down_e, &b_nu_jes_down_e);

}

Bool_t systematics::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef systematics_cxx
