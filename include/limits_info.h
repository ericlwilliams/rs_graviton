const int nLimitCuts=2;
const int ptlv_cut[nLimitCuts] = {50,200};
const int ptjj_cut[nLimitCuts] = {50,220};
const int min_mjj_cut = 65;
const int max_mjj_cut = 115;

/* const int nLimitCuts=4; */
/* const int ptlv_cut[nLimitCuts] = {100,100,150,150}; */
/* const int ptjj_cut[nLimitCuts] = {200,250,200,250}; */

//string limit_cuts = "met25_ptlv150_ptjj250,met30_ptlv150_ptjj250";


/* const int nLimitVars=2; */
/* const string limit_vars[nLimitVars] = {"lep_met_dijet_mt","lep_met_dijet_m"/\*,"lep_met_sig_jet_mt"*\/}; */
/* const int lv_bins[nLimitVars] = {26,26/\*,26*\/};// 36 -> 50 GeV bins; 26->  */
/* const double lv_xmin[nLimitVars] = {0,0/\*,0*\/}; */
/* const double lv_xmax[nLimitVars] = {1800,1800/\*,1800*\/}; */

const int nLimitVars=1;
const string limit_vars[nLimitVars] = {"lep_met_dijet_mt"};
				       /* "lep_met_sig_jet_mt","lep_nu_sig_jet_m", */
				       //"lep_met_jet_mt","lep_nu_jet_m"};


/* const int lv_bins[nLimitVars] = {30,30};// 60 GeV bins */
/* const double lv_xmin[nLimitVars] = {0,0}; */
/* const double lv_xmax[nLimitVars] = {1800,1800}; */
/* const int lv_bins[nLimitVars] = {26,26,26,26,26,26};// 36 -> 50 GeV bins; 26->  */
/* const double lv_xmin[nLimitVars] = {0,0,0,0,0,0}; */
/* const double lv_xmax[nLimitVars] = {1800,1800,1800,1800,1800,1800}; */
