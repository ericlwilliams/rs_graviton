#!/bin/bash -


echo 'python ExclusionPlot.py ./exclusion_limits/gww_met30_ptlv100_ptjj200_lep_met_dijet_mt.limits'
py ExclusionPlot.py ./exclusion_limits/gww_met30_ptlv100_ptjj200_lep_met_dijet_mt.limits

echo 'python ExclusionPlot.py ./exclusion_limits/gww_met30_ptlv100_ptjj250_lep_met_dijet_mt.limits'
py ExclusionPlot.py ./exclusion_limits/gww_met30_ptlv100_ptjj250_lep_met_dijet_mt.limits

echo 'python ExclusionPlot.py ./exclusion_limits/gww_met30_ptlv150_ptjj200_lep_met_dijet_mt.limits'
py ExclusionPlot.py ./exclusion_limits/gww_met30_ptlv150_ptjj200_lep_met_dijet_mt.limits

echo 'python ExclusionPlot.py ./exclusion_limits/gww_met30_ptlv150_ptjj250_lep_met_dijet_mt.limits'
py ExclusionPlot.py ./exclusion_limits/gww_met30_ptlv150_ptjj250_lep_met_dijet_mt.limits

echo 'python ExclusionPlot.py ./exclusion_limits/gww_met30_ptlv150_ptjj250_lep_met_sig_jet_mt.limits'
py ExclusionPlot.py ./exclusion_limits/gww_met30_ptlv150_ptjj250_lep_met_sig_jet_mt.limits

