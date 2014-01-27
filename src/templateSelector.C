#define templateSelector_cxx


#include "templateSelector.h"
#include <TH2.h>
#include <TStyle.h>


void templateSelector::Begin(TTree * /*tree*/)
{
   TString option = GetOption();

}

void templateSelector::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();

}

Bool_t templateSelector::Process(Long64_t entry)
{


   return kTRUE;
}

void templateSelector::SlaveTerminate()
{

}

void templateSelector::Terminate()
{

}
