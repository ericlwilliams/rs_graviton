//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Mar 23 10:51:56 2012 by ROOT version 5.28/00b
// from TTree physics/physics
// found on file: NTUP_SMWZ.670486._000001.root
//////////////////////////////////////////////////////////

#ifndef makeTruthSignalPlotsConstituents_h
#define makeTruthSignalPlotsConstituents_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

class makeTruthSignalPlotsConstituents : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   Int_t           mc_n;
   vector<float>   *mc_pt;
   vector<float>   *mc_m;
   vector<float>   *mc_eta;
   vector<float>   *mc_phi;
   vector<int>     *mc_status;
   vector<int>     *mc_barcode;
   Int_t           jet_AntiKt4Truth_n;
   vector<float>   *jet_AntiKt4Truth_pt;
   vector<float>   *jet_AntiKt4Truth_eta;
   vector<float>   *jet_AntiKt4Truth_phi;

   vector<vector<int> > *mc_parents;
   vector<vector<int> > *mc_children;
   vector<int>     *mc_pdgId;
   vector<float>   *mc_charge;
   vector<float>   *mc_vx_x;
   vector<float>   *mc_vx_y;
   vector<float>   *mc_vx_z;
   vector<int>     *mc_vx_barcode;
   vector<vector<int> > *mc_child_index;
   vector<vector<int> > *mc_parent_index;
   TBranch        *b_mc_n;   //!
   TBranch        *b_mc_pt;   //!
   TBranch        *b_jet_AntiKt4Truth_n;   //!
   TBranch        *b_jet_AntiKt4Truth_pt;   //!
   TBranch        *b_jet_AntiKt4Truth_eta;   //!
   TBranch        *b_jet_AntiKt4Truth_phi;   //!
   TBranch        *b_mc_m;   //!
   TBranch        *b_mc_eta;   //!
   TBranch        *b_mc_phi;   //!
   TBranch        *b_mc_status;   //!
   TBranch        *b_mc_barcode;   //!
   TBranch        *b_mc_parents;   //!
   TBranch        *b_mc_children;   //!
   TBranch        *b_mc_pdgId;   //!
   TBranch        *b_mc_charge;   //!
   TBranch        *b_mc_vx_x;   //!
   TBranch        *b_mc_vx_y;   //!
   TBranch        *b_mc_vx_z;   //!
   TBranch        *b_mc_vx_barcode;   //!
   TBranch        *b_mc_child_index;   //!
   TBranch        *b_mc_parent_index;   //!

   makeTruthSignalPlotsConstituents(TTree * /*tree*/ =0) { }
   virtual ~makeTruthSignalPlotsConstituents() { }
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

   ClassDef(makeTruthSignalPlotsConstituents,0);
};

#endif

#ifdef makeTruthSignalPlotsConstituents_cxx
void makeTruthSignalPlotsConstituents::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   mc_pt = 0;
   mc_m = 0;
   mc_eta = 0;
   mc_phi = 0;
   mc_status = 0;
   mc_barcode = 0;
   mc_parents = 0;
   mc_children = 0;
   mc_pdgId = 0;
   mc_charge = 0;
   mc_vx_x = 0;
   mc_vx_y = 0;
   mc_vx_z = 0;
   mc_vx_barcode = 0;
   mc_child_index = 0;
   mc_parent_index = 0;
   jet_AntiKt4Truth_pt = 0;
   jet_AntiKt4Truth_eta = 0;
   jet_AntiKt4Truth_phi = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("jet_AntiKt4Truth_n", &jet_AntiKt4Truth_n, &b_jet_AntiKt4Truth_n);
   fChain->SetBranchAddress("jet_AntiKt4Truth_pt", &jet_AntiKt4Truth_pt, &b_jet_AntiKt4Truth_pt);
   fChain->SetBranchAddress("jet_AntiKt4Truth_eta", &jet_AntiKt4Truth_eta, &b_jet_AntiKt4Truth_eta);
   fChain->SetBranchAddress("jet_AntiKt4Truth_phi", &jet_AntiKt4Truth_phi, &b_jet_AntiKt4Truth_phi);
   fChain->SetBranchAddress("mc_n", &mc_n, &b_mc_n);
   fChain->SetBranchAddress("mc_pt", &mc_pt, &b_mc_pt);
   fChain->SetBranchAddress("mc_m", &mc_m, &b_mc_m);
   fChain->SetBranchAddress("mc_eta", &mc_eta, &b_mc_eta);
   fChain->SetBranchAddress("mc_phi", &mc_phi, &b_mc_phi);
   fChain->SetBranchAddress("mc_status", &mc_status, &b_mc_status);
   fChain->SetBranchAddress("mc_barcode", &mc_barcode, &b_mc_barcode);
   fChain->SetBranchAddress("mc_parents", &mc_parents, &b_mc_parents);
   fChain->SetBranchAddress("mc_children", &mc_children, &b_mc_children);
   fChain->SetBranchAddress("mc_pdgId", &mc_pdgId, &b_mc_pdgId);
   fChain->SetBranchAddress("mc_charge", &mc_charge, &b_mc_charge);
   fChain->SetBranchAddress("mc_vx_x", &mc_vx_x, &b_mc_vx_x);
   fChain->SetBranchAddress("mc_vx_y", &mc_vx_y, &b_mc_vx_y);
   fChain->SetBranchAddress("mc_vx_z", &mc_vx_z, &b_mc_vx_z);
   fChain->SetBranchAddress("mc_vx_barcode", &mc_vx_barcode, &b_mc_vx_barcode);
   fChain->SetBranchAddress("mc_child_index", &mc_child_index, &b_mc_child_index);
   fChain->SetBranchAddress("mc_parent_index", &mc_parent_index, &b_mc_parent_index);
}

Bool_t makeTruthSignalPlotsConstituents::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef makeTruthSignalPlotsConstituents_cxx
