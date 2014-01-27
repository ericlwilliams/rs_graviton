#!/bin/bash -

#echo
#echo 'running: gww_met30_ptlv150_ptjj250_lep_met_dijet_mt'
#echo '--'
#root 'doLimit.C+("gww.mass.list","gww.xsec.list","./limit_lists/gww_met30_ptlv150_ptjj250_lep_met_dijet_mt.list",0.1,50,0.1,1,"gww_met30_ptlv150_ptjj250_lep_met_dijet_mt")' -q | grep ' GeV '
echo
echo 'running: gww_met30_ptlv150_ptjj250_lep_met_sig_jet_m'
echo '--'
root 'doLimit.C+("gww.mass.list","gww.xsec.list","./limit_lists/gww_met30_ptlv150_ptjj250_lep_met_sig_jet_m.list",0.1,50,0.1,1,"gww_met30_ptlv150_ptjj250_lep_met_sig_jet_m")' -q | grep ' GeV '

#echo 
#echo 'running: gww_met25_ptlv150_ptjj250_lep_met_dijet_mt'
#echo '--'.
#root 'doLimit.C+("gww.mass.list","gww.xsec.list","./limit_lists/gww_met25_ptlv150_ptjj250_lep_met_dijet_mt.list",0.1,50,0.1,1,"gww_met25_ptlv150_ptjj250_lep_met_dijet_mt")' -q | grep ' GeV '

