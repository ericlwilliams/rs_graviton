//Signal Cuts

double sig_lt=125.0;

const double GeV=1000.;
const float EL_MASS = 0.000511;
const float MU_MASS = .105658;
const float W_MASS = 80.398;



const int nProcs=2;
string procs[nProcs] = {"elec","muon"};

/* const int nCtrls=5; */
/* enum { ALL, EWK, BOOST1,SIG_LOWM,SIG_HIGHM}; */
/* string ctrls[nCtrls] = {"all","ewk","boost1","sig_lowm","sig_highm"}; */
const int nCtrls=3;
enum { LOOSE, PS, OPTION };
string ctrls[nCtrls] = {"loose","ps","opt"};

const int nVars = 2;
enum {LEP_PT,JET_M};
string vars[nVars] = {"pt","jet_m"};


bool isElec=true;
int procIndex=0;