#include <TF1.h>
#include <TVector2.h>
namespace lvjjHelper {

  // Unblind 1fb-1 of randomly selected data:
  bool doPartialUnblind = false;

  bool doAlpgenReweighting = true;
  //////////////////////////////////////////////////
  // QCD scaling
  //////////////////////////////////////////////////
  namespace qcdHelper {
    bool useQCDScale=true;

    /* // without Alpgen Reweighting */
    /* float elec_qcd_sf = (!useQCDScale) ? 1. : 0.38056;//0.338894; */
    /* float muon_qcd_sf = (!useQCDScale) ? 1. : 0.1;//0.165414; */
    /* float elec_vjets_sf = (!useQCDScale) ?  1. : 1.05835;//0.999361;//1.0799; */
    /* float muon_vjets_sf = (!useQCDScale) ? 1. : 1.05096;//0.999129;//1.08539; */

    // with Alpgen Reweighting && WJETs contamination subtracted from electron channel!
    float elec_qcd_sf = (!useQCDScale) ? 1. : 0.316994;
    float muon_qcd_sf = (!useQCDScale) ? 1. : 0.249578;
    float elec_vjets_sf = (!useQCDScale) ?  1. : 1.08812;//1.10277;
    float muon_vjets_sf = (!useQCDScale) ? 1. : 1.08373;//1.08588;

    // no Alpgen Reweighting
    /* float elec_qcd_sf = (!useQCDScale) ? 1. : 0.153332; */
    /* float muon_qcd_sf = (!useQCDScale) ? 1. : 0.25; */
    /* float elec_vjets_sf = (!useQCDScale) ?  1. : 1.05722; */
    /* float muon_vjets_sf = (!useQCDScale) ? 1. : 1.04885; */
    
  }

  bool useSidebandScale=true;
  double avg_alpgen_comb_sf = 1.019;
  
  bool passTriangle(int is_elec, float lepton_met_dphi, float rf_met){

    bool pass_tri = true;
    
    float tri_x1=40.;
    float tri_x2=75.;

    //lower triangle first
    float tri_y1 = 1.5;
    float tri_y2 = 0.0;

    float lower_slope = (tri_y2-tri_y1) / (tri_x2-tri_x1);
    
    bool pass_lower_tri = (lepton_met_dphi > lower_slope*(rf_met-tri_x1)+tri_y1);

    pass_tri = (pass_tri && pass_lower_tri);

    if(is_elec!=0 && pass_tri){//upper triangle

      tri_y1=2.0;
      tri_y2=TMath::Pi();

      float upper_slope = (tri_y2-tri_y1) / (tri_x2-tri_x1);

      pass_tri = (lepton_met_dphi < upper_slope*(rf_met-tri_x1)+tri_y1);

    }

    return pass_tri;
  }
  
  
  bool passElecTri(int is_elec, float lepton_met_dphi, float rf_met){

    float elec_x1=40.0;
    float elec_y1=2.0;
    float elec_x2=75.;
    float elec_y2=TMath::Pi();
    float elec_slope = (elec_y2-elec_y1) / (elec_x2-elec_x1);

    bool pass_elec_tri = (is_elec!=0) ?  (lepton_met_dphi < elec_slope*(rf_met-elec_x1)+elec_y1) : true;

    return pass_elec_tri;

  }
  bool passTri(float lepton_met_dphi, float rf_met){

    float x1=40.0;
    float y1=1.5;
    float x2=75.;
    float y2=0.0;
    float slope = (y2-y1) / (x2-x1);

    bool pass_tri= (lepton_met_dphi > slope*(rf_met-x1)+y1);
    return pass_tri;
  }

  //////////////////////////////////////////////////
  // getDeltaPhi
  // - returns dphi between phi1 and phi2
  //////////////////////////////////////////////////
  float getDeltaPhi(float phi1, float phi2){

    float dphi = fabs(TVector2::Phi_mpi_pi(phi1-phi2));

    return dphi;
  }// end getDeltaPhi()

  //////////////////////////////////////////////////
  // G->WW Signal Template cross section
  // Use with:
  // lvjjHelper::csHelper* gww_cs_helper = new lvjjHelper::csHelper();
  ////////////////////////////////////////////////// 

  class csHelper
  {

    TF1 *cs_BulkRSGravitonWW_log;
    TF1 *cs_BulkRSGravitonWW;
    
    
  public:
    csHelper(){
      cs_BulkRSGravitonWW_log = new TF1("bulkrs_gww", "pol4", 0, 2000);
      cs_BulkRSGravitonWW_log->SetParameters(11.31, -0.02937, 2.219e-05, -9.445e-09, 1.551e-12);// nom
      //cs_BulkRSGravitonWW_log->SetParameters(11.23, -0.0285, 2.193e-05, -9.443e-09, 1.563e-12);// -1sig
      //cs_BulkRSGravitonWW_log->SetParameters(11.39, -0.03025, 2.245e-05, -9.447e-09, 1.539e-12);// +1sig
      cs_BulkRSGravitonWW = ConvertLogToExp(cs_BulkRSGravitonWW_log);
    }

    void WjetsScale(TH1* hist,TF1* sf_fn,string hist_name,double scale);

    double BulkRSGravitonWWCS(int mass)
    {

      return( cs_BulkRSGravitonWW->Eval(mass) );
    }
    
    
    static Double_t fcn(Double_t *x, Double_t *params)
    {
      TF1 *pol1 = new TF1("p1", "pol1", -10, 10);
      pol1->SetParameters(params);
      double cs = TMath::Exp(pol1->Eval(TMath::Log(*x)));
      delete pol1;  
      return( cs );
    }

    static Double_t fcn2(Double_t *x, Double_t *params)
    {
      TF1 *pol2 = new TF1("p2", "pol2", 0, 2500);
      pol2->SetParameters(params);
      double cs = TMath::Exp(pol2->Eval(*x));
      delete pol2;
      return( cs );
    }

    static Double_t fcn4(Double_t *x, Double_t *params)
    {
      TF1 *pol4 = new TF1("p4", "pol4", 0, 4500);
      pol4->SetParameters(params);
      double cs = TMath::Exp(pol4->Eval(*x));
      delete pol4;
      return( cs );
    }

  private:

    TF1* ConvertLogToExp(TF1* fit)
    {
      if ( fit == NULL ) { cout << "Fit is NULL!" << endl; exit(1); }

      TString name = fit->GetName();

      double xmin = fit->GetXmin();
      double xmax = fit->GetXmax();
 
      if ( fit->GetNumberFreeParameters() == 2 ) {
	TF1* newfit = new TF1("temp", &lvjjHelper::csHelper::fcn, TMath::Exp(xmin), TMath::Exp(xmax), 2);
	newfit->SetParameters(fit->GetParameters());
	newfit->SetName(name);
	return( newfit );
      }
 
      if ( fit->GetNumberFreeParameters() == 3 ) {
	TF1 *newfit = new TF1("temp", &lvjjHelper::csHelper::fcn2, xmin, xmax, 3);
	newfit->SetParameters(fit->GetParameters());
	newfit->SetName(name);
	return( newfit );
      }
 
      if ( fit->GetNumberFreeParameters() == 5 ) {
	TF1 *newfit = new TF1("temp", &lvjjHelper::csHelper::fcn4, xmin, xmax, 5);
	newfit->SetParameters(fit->GetParameters());
	newfit->SetName(name);
	return( newfit );
      }
      return NULL;
    }

    
  };

  void WjetsScale(TH1* hist,TF1* sf_fn,string hist_name,double scale){

      float vjets_factor = 1;

      if((hist_name.find("dijet_m_dijet_pt")!=string::npos) ||
	 (hist_name.find("dijet_m_lep_met_pt")!=string::npos)){
	vjets_factor = 0.5;
      }else if((hist_name.find("dijet_m_lep_pt")!=string::npos) ||
	       (hist_name.find("dijet_m_lead_jet_pt")!=string::npos) ||
	       (hist_name.find("dijet_m_second_jet_pt")!=string::npos) ||
	       (hist_name.find("dijet_m_met")!=string::npos)){
	vjets_factor = 0.25;
      }


      int Nbins = hist->GetNbinsX();
      //cout<<hist_name<<": "<<Nbins<<endl;
      for(int i=1;i<=Nbins;i++){
	if (hist->GetBinContent(i)<=0) continue;

	double bin_value = hist->GetBinCenter(i);
	double sf_value = sf_fn->Eval(bin_value/vjets_factor);

	double bin_content = hist->GetBinContent(i);
	double new_bin_content = bin_content*sf_value;
	/* if(hist_name.find("dijet_m_dijet_pt")!=string::npos && */
	/*    bin_value<400){ */
	/*   cout<<"bin: "<<i<<" x_val: "<<bin_value<<" sf_val: "<<sf_value<<endl; */
	/*   cout<<"content: "<<bin_content<<" new content: "<<new_bin_content<<endl; */
	/* } */

	
	//cout<<"bin: "<<i<<" x_val: "<<bin_value<<" sf_val: "<<sf_value<<endl;
	//cout<<"content: "<<bin_content<<" new content: "<<new_bin_content<<endl;

	hist->SetBinContent(i,new_bin_content);
	
      }

      hist->Scale(scale); //double scaling as is

      //cout<<endl;
      return;
    }
    


}


