//Signal Cuts

const double sig_m_min = 65.0;
const double sig_m_max = 115.0;

const double GeV=1000.;

const int nProcs=2;
string procs[nProcs] = {"elec","muon"};

const int nCuts=2;
string cuts[nCuts] = {"lep_met_pt","dijet_pt"};

const int nVals=25;
string vals[nVals] = {"200","225","250",
		      "275","300","325","350","375","400","425",
		      "450","475","500","525","550","575","600",
		      "625","650","675","700"};
double values[nVals] =  {100,125,150,175,200,225,250,
			 275,300,325,350,375,400,425,
			 450,475,500,525,550,575,600,
			 625,650,675,700};

