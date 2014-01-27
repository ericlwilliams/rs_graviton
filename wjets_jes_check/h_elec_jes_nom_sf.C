{
//========= Macro generated from object: h_elec_data_jes_nom_rebin_dijet_m/h_el_jes_nom_highm_jes_dijet_m
//========= by ROOT version5.28/00b
   Double_t xAxis1[4] = {0, 65, 115, 300}; 
   
   TH1F *h_elec_data_jes_nom_rebin_dijet_m = new TH1F("h_elec_data_jes_nom_rebin_dijet_m","h_el_jes_nom_highm_jes_dijet_m",3, xAxis1);
   h_elec_data_jes_nom_rebin_dijet_m->SetBinContent(1,1.26594);
   h_elec_data_jes_nom_rebin_dijet_m->SetBinContent(2,1.04252);
   h_elec_data_jes_nom_rebin_dijet_m->SetBinContent(3,0.980339);
   h_elec_data_jes_nom_rebin_dijet_m->SetBinContent(4,1.0109);
   h_elec_data_jes_nom_rebin_dijet_m->SetBinError(1,0.134359);
   h_elec_data_jes_nom_rebin_dijet_m->SetBinError(2,0.061713);
   h_elec_data_jes_nom_rebin_dijet_m->SetBinError(3,0.029047);
   h_elec_data_jes_nom_rebin_dijet_m->SetBinError(4,0.0308658);
   h_elec_data_jes_nom_rebin_dijet_m->SetEntries(476.389);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#000099");
   h_elec_data_jes_nom_rebin_dijet_m->SetLineColor(ci);
   h_elec_data_jes_nom_rebin_dijet_m->GetXaxis()->SetLabelFont(42);
   h_elec_data_jes_nom_rebin_dijet_m->GetXaxis()->SetLabelSize(0.035);
   h_elec_data_jes_nom_rebin_dijet_m->GetXaxis()->SetTitleSize(0.035);
   h_elec_data_jes_nom_rebin_dijet_m->GetXaxis()->SetTitleFont(42);
   h_elec_data_jes_nom_rebin_dijet_m->GetYaxis()->SetLabelFont(42);
   h_elec_data_jes_nom_rebin_dijet_m->GetYaxis()->SetLabelSize(0.035);
   h_elec_data_jes_nom_rebin_dijet_m->GetYaxis()->SetTitleSize(0.035);
   h_elec_data_jes_nom_rebin_dijet_m->GetYaxis()->SetTitleFont(42);
   h_elec_data_jes_nom_rebin_dijet_m->GetZaxis()->SetLabelFont(42);
   h_elec_data_jes_nom_rebin_dijet_m->GetZaxis()->SetLabelSize(0.035);
   h_elec_data_jes_nom_rebin_dijet_m->GetZaxis()->SetTitleSize(0.035);
   h_elec_data_jes_nom_rebin_dijet_m->GetZaxis()->SetTitleFont(42);
   h_elec_data_jes_nom_rebin_dijet_m->Draw("");
}
