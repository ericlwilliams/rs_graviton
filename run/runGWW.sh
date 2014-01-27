#!/bin/zsh -

src create_wjets_qcd_contamination_files.sh 

r runPS.C

cp ../plots/gww_plots/qcd.elec.pu.plot.root ../plots/gww_plots/qcd.elec.alpgen.pu.plot.root
cp ../plots/gww_plots/qcd.muon.pu.plot.root ../plots/gww_plots/qcd.muon.alpgen.pu.plot.root

cp ../plots/gww_plots/qcd.elec.pu.plot.root ../plots/gww_plots/qcd.elec.sherpa.pu.plot.root
cp ../plots/gww_plots/qcd.muon.pu.plot.root ../plots/gww_plots/qcd.muon.sherpa.pu.plot.root

## qcd.elec/muon.pu.plot.root saved to use in ../qcd/subtractWjetsContamination.C

#hadd -f ../plots/gww_plots/qcd.alpgen.pu.plot.root ../plots/gww_plots/qcd.elec.alpgen.pu.plot.root ../plots/gww_plots/qcd.muon.alpgen.pu.plot.root