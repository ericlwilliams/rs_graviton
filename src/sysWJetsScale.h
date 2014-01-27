//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jul  6 10:34:59 2011 by ROOT version 5.28/00b
// from TTree analysisTree/analysisTree
// found on file: merged/data11.lnuj.skim.root
//////////////////////////////////////////////////////////

#ifndef sysWJetsScale_h
#define sysWJetsScale_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

class sysWJetsScale : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   Float_t         EventWJetsScaleIQOPT3;
   Float_t         EventWJetsScalePTJMIN10;
   Float_t         evt_pu_weight;
   Int_t           nGoodElectrons;
   Int_t           nGoodMuons;
   Int_t           nGoodJets;
   Int_t           nGoodVxp;
   Int_t           goodLeptonIndex;
   Int_t           goodNeutrinoSolution;
   Float_t         lnuj_lep_pt;
   Float_t         lnuj_lep_eta;
   Float_t         lnuj_lep_phi;
   Float_t         lead_jet_m;
   Float_t         lead_jet_pt;
   Float_t         lead_jet_rel_uncert;
   Float_t         lead_jet_eta;
   Float_t         lead_jet_phi;
   Float_t         second_jet_m;
   Float_t         second_jet_pt;
   Float_t         second_jet_rel_uncert;
   Float_t         second_jet_eta;
   Float_t         second_jet_phi;
   Float_t         third_jet_m;
   Float_t         third_jet_pt;
   Float_t         third_jet_rel_uncert;
   Float_t         third_jet_eta;
   Float_t         third_jet_phi;
   Float_t         fourth_jet_m;
   Float_t         fourth_jet_pt;
   Float_t         fourth_jet_rel_uncert;
   Float_t         fourth_jet_eta;
   Float_t         fourth_jet_phi;
   Int_t           ctrl_ewk;
   Int_t           ctrl_ttbar;
   Int_t           ctrl_jetm;
   Float_t         ww_met_etx;
   Float_t         ww_met_ety;
   Float_t         ww_met_et;
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
   TBranch        *b_evt_pu_weight;   //!
   TBranch        *b_nGoodElectrons;   //!
   TBranch        *b_nGoodMuons;   //!
   TBranch        *b_nGoodJets;   //!
   TBranch        *b_nGoodVxp;   //!
   TBranch        *b_goodLeptonIndex;   //!
   TBranch        *b_goodNeutrinoSolution;   //!
   TBranch        *b_lnuj_lep_pt;   //!
   TBranch        *b_lnuj_lep_eta;   //!
   TBranch        *b_lnuj_lep_phi;   //!
   TBranch        *b_lead_jet_m;   //!
   TBranch        *b_lead_jet_pt;   //!
   TBranch        *b_lead_jet_rel_uncert;   //!
   TBranch        *b_lead_jet_eta;   //!
   TBranch        *b_lead_jet_phi;   //!
   TBranch        *b_second_jet_m;   //!
   TBranch        *b_second_jet_pt;   //!
   TBranch        *b_second_jet_rel_uncert;   //!
   TBranch        *b_second_jet_eta;   //!
   TBranch        *b_second_jet_phi;   //!
   TBranch        *b_third_jet_m;   //!
   TBranch        *b_third_jet_pt;   //!
   TBranch        *b_third_jet_rel_uncert;   //!
   TBranch        *b_third_jet_eta;   //!
   TBranch        *b_third_jet_phi;   //!
   TBranch        *b_fourth_jet_m;   //!
   TBranch        *b_fourth_jet_pt;   //!
   TBranch        *b_fourth_jet_rel_uncert;   //!
   TBranch        *b_fourth_jet_eta;   //!
   TBranch        *b_fourth_jet_phi;   //!
   TBranch        *b_ctrl_ewk;   //!
   TBranch        *b_ctrl_ttbar;   //!
   TBranch        *b_ctrl_jetm;   //!
   TBranch        *b_ww_met_etx;   //!
   TBranch        *b_ww_met_ety;   //!
   TBranch        *b_ww_met_et;   //!
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

   sysWJetsScale(TTree * /*tree*/ =0) { }
   virtual ~sysWJetsScale() { }
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

   ClassDef(sysWJetsScale,0);
};

#endif

#ifdef sysWJetsScale_cxx
void sysWJetsScale::Init(TTree *tree)
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
   fChain->SetBranchAddress("evt_pu_weight", &evt_pu_weight, &b_evt_pu_weight);
   fChain->SetBranchAddress("nGoodElectrons", &nGoodElectrons, &b_nGoodElectrons);
   fChain->SetBranchAddress("nGoodMuons", &nGoodMuons, &b_nGoodMuons);
   fChain->SetBranchAddress("nGoodJets", &nGoodJets, &b_nGoodJets);
   fChain->SetBranchAddress("nGoodVxp", &nGoodVxp, &b_nGoodVxp);
   fChain->SetBranchAddress("goodLeptonIndex", &goodLeptonIndex, &b_goodLeptonIndex);
   fChain->SetBranchAddress("goodNeutrinoSolution", &goodNeutrinoSolution, &b_goodNeutrinoSolution);
   fChain->SetBranchAddress("lnuj_lep_pt", &lnuj_lep_pt, &b_lnuj_lep_pt);
   fChain->SetBranchAddress("lnuj_lep_eta", &lnuj_lep_eta, &b_lnuj_lep_eta);
   fChain->SetBranchAddress("lnuj_lep_phi", &lnuj_lep_phi, &b_lnuj_lep_phi);
   fChain->SetBranchAddress("lead_jet_m", &lead_jet_m, &b_lead_jet_m);
   fChain->SetBranchAddress("lead_jet_pt", &lead_jet_pt, &b_lead_jet_pt);
   fChain->SetBranchAddress("lead_jet_rel_uncert", &lead_jet_rel_uncert, &b_lead_jet_rel_uncert);
   fChain->SetBranchAddress("lead_jet_eta", &lead_jet_eta, &b_lead_jet_eta);
   fChain->SetBranchAddress("lead_jet_phi", &lead_jet_phi, &b_lead_jet_phi);
   fChain->SetBranchAddress("second_jet_m", &second_jet_m, &b_second_jet_m);
   fChain->SetBranchAddress("second_jet_pt", &second_jet_pt, &b_second_jet_pt);
   fChain->SetBranchAddress("second_jet_rel_uncert", &second_jet_rel_uncert, &b_second_jet_rel_uncert);
   fChain->SetBranchAddress("second_jet_eta", &second_jet_eta, &b_second_jet_eta);
   fChain->SetBranchAddress("second_jet_phi", &second_jet_phi, &b_second_jet_phi);
   fChain->SetBranchAddress("third_jet_m", &third_jet_m, &b_third_jet_m);
   fChain->SetBranchAddress("third_jet_pt", &third_jet_pt, &b_third_jet_pt);
   fChain->SetBranchAddress("third_jet_rel_uncert", &third_jet_rel_uncert, &b_third_jet_rel_uncert);
   fChain->SetBranchAddress("third_jet_eta", &third_jet_eta, &b_third_jet_eta);
   fChain->SetBranchAddress("third_jet_phi", &third_jet_phi, &b_third_jet_phi);
   fChain->SetBranchAddress("fourth_jet_m", &fourth_jet_m, &b_fourth_jet_m);
   fChain->SetBranchAddress("fourth_jet_pt", &fourth_jet_pt, &b_fourth_jet_pt);
   fChain->SetBranchAddress("fourth_jet_rel_uncert", &fourth_jet_rel_uncert, &b_fourth_jet_rel_uncert);
   fChain->SetBranchAddress("fourth_jet_eta", &fourth_jet_eta, &b_fourth_jet_eta);
   fChain->SetBranchAddress("fourth_jet_phi", &fourth_jet_phi, &b_fourth_jet_phi);
   fChain->SetBranchAddress("ctrl_ewk", &ctrl_ewk, &b_ctrl_ewk);
   fChain->SetBranchAddress("ctrl_ttbar", &ctrl_ttbar, &b_ctrl_ttbar);
   fChain->SetBranchAddress("ctrl_jetm", &ctrl_jetm, &b_ctrl_jetm);
   fChain->SetBranchAddress("ww_met_etx", &ww_met_etx, &b_ww_met_etx);
   fChain->SetBranchAddress("ww_met_ety", &ww_met_ety, &b_ww_met_ety);
   fChain->SetBranchAddress("ww_met_et", &ww_met_et, &b_ww_met_et);
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

Bool_t sysWJetsScale::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef sysWJetsScale_cxx
