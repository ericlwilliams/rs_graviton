// Only to be run AFTER makeLimitWithSystmatics.C (true ??)
// Open envelope function files
// Open nominal w/z+jets signal lep_nu_dijet_m
// Scale v_jets lep_nu_dijet_m up/down by envelope functions
#include <TFile>
#include <TF1>

const int nProcs=2;
void makeVjetsSystematics(string cur_file_name){

  string cur_file_loc = "../plots/systematics_plots/merged/"+cur_file_name+".systematics.plot.root";

  bool isVjets = (cur_file_name.find("wjets")!=string::npos ||
		  cur_file_name.find("zjets")!=string::npos);

  if(isVjets){
  
    //string wjets_file_loc = "../plots/systematics_plots/merged/mc.alpgen.wjets.systematics.plot.root";
    string wjets_file_loc = cur_file_loc;
    TFile* wjets_file = (TFile*) TFile::Open(wjets_file_loc.c_str(),"R");


    TH1F* h_wjets_lep_nu_dijet_m[nProcs];
    h_wjets_lep_nu_dijet_m[0] = (TH1F*) wjets_file->Get("h_el_jes_nom_highm_lep_nu_dijet_m");
    h_wjets_lep_nu_dijet_m[0]->SetDirectory(0);

    h_wjets_lep_nu_dijet_m[1] = (TH1F*) wjets_file->Get("h_mu_jes_nom_highm_lep_nu_dijet_m");
    h_wjets_lep_nu_dijet_m[1]->SetDirectory(0);

    wjets_file->Close();
  

    string vjets_sys_fn_file_loc = "../wjets/files/vjets_systematics_functions.root";
    TFile* vjets_sys_fn_file = (TFile*) TFile::Open(vjets_sys_fn_file_loc.c_str(),"R");
    TF1* fn_up = (TF1*) vjets_sys_fn_file->Get("fn_lowsb");
    TF1* fn_down = (TF1*) vjets_sys_fn_file->Get("fn_highsb");
    TH1F* h_avg_sf = (TH1F*) vjets_sys_fn_file->Get("h_avg_varbin_sf");

    TH1F* h_wjets_vjets_up_lep_nu_dijet_m[nProcs];
    h_wjets_vjets_up_lep_nu_dijet_m[0] =
      (TH1F*) ((TH1F*) h_wjets_lep_nu_dijet_m[0])->Clone("h_el_vjets_up_highm_lep_nu_dijet_m");
    h_wjets_vjets_up_lep_nu_dijet_m[1] =
      (TH1F*) ((TH1F*) h_wjets_lep_nu_dijet_m[1])->Clone("h_mu_vjets_up_highm_lep_nu_dijet_m");

    TH1F* h_wjets_vjets_down_lep_nu_dijet_m[nProcs];
    h_wjets_vjets_down_lep_nu_dijet_m[0] =
      (TH1F*) ((TH1F*) h_wjets_lep_nu_dijet_m[0])->Clone("h_el_vjets_down_highm_lep_nu_dijet_m");
    h_wjets_vjets_down_lep_nu_dijet_m[1] =
      (TH1F*) ((TH1F*) h_wjets_lep_nu_dijet_m[1])->Clone("h_mu_vjets_down_highm_lep_nu_dijet_m");

    
    TH1F* h_wjets_vjets_nom_lep_nu_dijet_m[nProcs];
    h_wjets_vjets_nom_lep_nu_dijet_m[0] =
      (TH1F*) ((TH1F*) h_wjets_lep_nu_dijet_m[0])->Clone("h_el_vjets_nom_highm_lep_nu_dijet_m");
    h_wjets_vjets_nom_lep_nu_dijet_m[1] =
      (TH1F*) ((TH1F*) h_wjets_lep_nu_dijet_m[1])->Clone("h_mu_vjets_nom_highm_lep_nu_dijet_m");

    
    //TH1F* h_wjets_el_vjets_down_lep_nu_dijet_m = (TH1F*) h_wjets_el_lep_nu_dijet_m->Clone();
    //TH1F* h_wjets_el_vjets_down_lep_nu_dijet_m = (TH1F*) h_wjets_el_lep_nu_dijet_m->Clone();

    //wjets

    for(int i=0;i<nProcs;i++){
      for(int j=1; j<=((TH1F*) h_wjets_vjets_up_lep_nu_dijet_m[i])->GetNbinsX();j++){
	
	float cur_bin_center = ((TH1F*) h_wjets_vjets_up_lep_nu_dijet_m[i])->GetBinCenter(j);

	int cur_avg_bin = h_avg_sf->GetXaxis()->FindBin(cur_bin_center);
	cur_avg_bin = (cur_avg_bin) ? cur_avg_bin : 1;
	float cur_avg  = h_avg_sf->GetBinContent(cur_avg_bin);
	
	float cur_down = fn_down->Eval(cur_bin_center);
	float cur_up = fn_up->Eval(cur_bin_center);
	float cur_el_up_content = ((TH1F*) h_wjets_vjets_up_lep_nu_dijet_m[i])->GetBinContent(j);

	h_wjets_vjets_up_lep_nu_dijet_m[i]->SetBinContent(j,cur_el_up_content*(cur_up/cur_avg));

	float cur_el_down_content = ((TH1F*) h_wjets_vjets_down_lep_nu_dijet_m[i])->GetBinContent(j);
	// cout<<endl;
	// cout<<"x: "<<cur_bin_center<<" bin: "<<cur_avg_bin<<endl;
	// cout<<"cur_avg: "<<cur_avg<<", cur_down: "<<cur_down<<endl;
	// if(cur_avg)  cout<<"rel: "<<cur_down/cur_avg<<endl;

	//cout<<"down: "<<cur_el_down_content<<" -> "<<cur_el_down_content*cur_down<<endl;
	h_wjets_vjets_down_lep_nu_dijet_m[i]->SetBinContent(j,cur_el_down_content*(cur_down/cur_avg));

      }
    }

  
    string wjets_file_loc = cur_file_loc;
    TFile* wjets_file = (TFile*) TFile::Open(wjets_file_loc.c_str(),"UPDATE");
    wjets_file->cd();

    //up
    ((TH1F*) h_wjets_vjets_up_lep_nu_dijet_m[0])->SetTitle("h_el_vjets_up_highm_lep_nu_dijet_m");
    ((TH1F*) h_wjets_vjets_up_lep_nu_dijet_m[0])->Write("h_el_vjets_up_highm_lep_nu_dijet_m",TObject::kOverwrite);
    //down
    ((TH1F*) h_wjets_vjets_down_lep_nu_dijet_m[0])->SetTitle("h_el_vjets_down_highm_lep_nu_dijet_m");
    ((TH1F*) h_wjets_vjets_down_lep_nu_dijet_m[0])->Write("h_el_vjets_down_highm_lep_nu_dijet_m",TObject::kOverwrite);
    //nominal
    ((TH1F*) h_wjets_vjets_nom_lep_nu_dijet_m[0])->SetTitle("h_el_vjets_nom_highm_lep_nu_dijet_m");
    ((TH1F*) h_wjets_vjets_nom_lep_nu_dijet_m[0])->Write("h_el_vjets_nom_highm_lep_nu_dijet_m",TObject::kOverwrite);


    //up
    ((TH1F*) h_wjets_vjets_up_lep_nu_dijet_m[1])->SetTitle("h_mu_vjets_up_highm_lep_nu_dijet_m");
    ((TH1F*) h_wjets_vjets_up_lep_nu_dijet_m[1])->Write("h_mu_vjets_up_highm_lep_nu_dijet_m",TObject::kOverwrite);
    //down
    ((TH1F*) h_wjets_vjets_down_lep_nu_dijet_m[1])->SetTitle("h_mu_vjets_down_highm_lep_nu_dijet_m");
    ((TH1F*) h_wjets_vjets_down_lep_nu_dijet_m[1])->Write("h_mu_vjets_down_highm_lep_nu_dijet_m",TObject::kOverwrite);

    //nom
    ((TH1F*) h_wjets_vjets_nom_lep_nu_dijet_m[1])->SetTitle("h_mu_vjets_nom_highm_lep_nu_dijet_m");
    ((TH1F*) h_wjets_vjets_nom_lep_nu_dijet_m[1])->Write("h_mu_vjets_nom_highm_lep_nu_dijet_m",TObject::kOverwrite);

    wjets_file->Close();
    
  }else{ // not w/z jets, 

    TFile* cur_file = (TFile*) TFile::Open(cur_file_loc.c_str(),"R");


    TH1F* h_cur_lep_nu_dijet_m[nProcs];
    h_cur_lep_nu_dijet_m[0] = (TH1F*) cur_file->Get("h_el_jes_nom_highm_lep_nu_dijet_m");
    h_cur_lep_nu_dijet_m[0]->SetDirectory(0);

    h_cur_lep_nu_dijet_m[1] = (TH1F*) cur_file->Get("h_mu_jes_nom_highm_lep_nu_dijet_m");
    h_cur_lep_nu_dijet_m[1]->SetDirectory(0);

    cur_file->Close();

    TH1F* h_cur_vjets_up_lep_nu_dijet_m[nProcs];
    h_cur_vjets_up_lep_nu_dijet_m[0] =
      (TH1F*) ((TH1F*) h_cur_lep_nu_dijet_m[0])->Clone("h_el_vjets_up_highm_lep_nu_dijet_m");
    h_cur_vjets_up_lep_nu_dijet_m[1] =
      (TH1F*) ((TH1F*) h_cur_lep_nu_dijet_m[1])->Clone("h_mu_vjets_up_highm_lep_nu_dijet_m");

    TH1F* h_cur_vjets_down_lep_nu_dijet_m[nProcs];
    h_cur_vjets_down_lep_nu_dijet_m[0] =
      (TH1F*) ((TH1F*) h_cur_lep_nu_dijet_m[0])->Clone("h_el_vjets_down_highm_lep_nu_dijet_m");
    h_cur_vjets_down_lep_nu_dijet_m[1] =
      (TH1F*) ((TH1F*) h_cur_lep_nu_dijet_m[1])->Clone("h_mu_vjets_down_highm_lep_nu_dijet_m");
  
    TH1F* h_cur_vjets_nom_lep_nu_dijet_m[nProcs];
    h_cur_vjets_nom_lep_nu_dijet_m[0] =
      (TH1F*) ((TH1F*) h_cur_lep_nu_dijet_m[0])->Clone("h_el_vjets_nom_highm_lep_nu_dijet_m");
    h_cur_vjets_nom_lep_nu_dijet_m[1] =
      (TH1F*) ((TH1F*) h_cur_lep_nu_dijet_m[1])->Clone("h_mu_vjets_nom_highm_lep_nu_dijet_m");
  

    string write_file_loc = cur_file_loc;
    TFile* write_file = (TFile*) TFile::Open(write_file_loc.c_str(),"UPDATE");
    write_file->cd();

    //up
    ((TH1F*) h_cur_vjets_up_lep_nu_dijet_m[0])->SetTitle("h_el_vjets_up_highm_lep_nu_dijet_m");
    ((TH1F*) h_cur_vjets_up_lep_nu_dijet_m[0])->Write("h_el_vjets_up_highm_lep_nu_dijet_m",TObject::kOverwrite);
    //down
    ((TH1F*) h_cur_vjets_down_lep_nu_dijet_m[0])->SetTitle("h_el_vjets_down_highm_lep_nu_dijet_m");
    ((TH1F*) h_cur_vjets_down_lep_nu_dijet_m[0])->Write("h_el_vjets_down_highm_lep_nu_dijet_m",TObject::kOverwrite);
    //nom
    ((TH1F*) h_cur_vjets_nom_lep_nu_dijet_m[0])->SetTitle("h_el_vjets_nom_highm_lep_nu_dijet_m");
    ((TH1F*) h_cur_vjets_nom_lep_nu_dijet_m[0])->Write("h_el_vjets_nom_highm_lep_nu_dijet_m",TObject::kOverwrite);


    //up
    ((TH1F*) h_cur_vjets_up_lep_nu_dijet_m[1])->SetTitle("h_mu_vjets_up_highm_lep_nu_dijet_m");
    ((TH1F*) h_cur_vjets_up_lep_nu_dijet_m[1])->Write("h_mu_vjets_up_highm_lep_nu_dijet_m",TObject::kOverwrite);
    //down
    ((TH1F*) h_cur_vjets_down_lep_nu_dijet_m[1])->SetTitle("h_mu_vjets_down_highm_lep_nu_dijet_m");
    ((TH1F*) h_cur_vjets_down_lep_nu_dijet_m[1])->Write("h_mu_vjets_down_highm_lep_nu_dijet_m",TObject::kOverwrite);
    //nom
    ((TH1F*) h_cur_vjets_nom_lep_nu_dijet_m[1])->SetTitle("h_mu_vjets_nom_highm_lep_nu_dijet_m");
    ((TH1F*) h_cur_vjets_nom_lep_nu_dijet_m[1])->Write("h_mu_vjets_nom_highm_lep_nu_dijet_m",TObject::kOverwrite);

    write_file->Close();

  }

  
  //gROOT->ProcessLine(".q");
  return;
}
