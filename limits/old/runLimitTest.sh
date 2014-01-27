#!/bin/bash -

echo
echo 'running: gww_met30_ptlv150_ptjj250_lep_met_sig_jet_mt'
echo '--'
root 'doLimit.C+("gww.mass.list","gww.xsec.list","./limit_lists/gww_met30_ptlv150_ptjj250_lep_met_sig_jet_mt.list",0.1,50,0.1,1,"gww_met30_ptlv150_ptjj250_lep_met_sig_jet_mt")' -q | grep ' GeV '
