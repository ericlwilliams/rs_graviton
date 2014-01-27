#!/bin/zsh -

hadd -f ../plots/jvf_plots/merged/mc.mcatnlo.top.jvf.root ../plots/jvf_plots/mc.mcatnlo.*
hadd -f ../plots/jvf_plots/merged/mc.herwig.vv.jvf.root ../plots/jvf_plots/mc.herwig.*
hadd -f ../plots/jvf_plots/merged/mc.alpgen.wjets.jvf.root ../plots/jvf_plots/mc.alpgen.w*
hadd -f ../plots/jvf_plots/merged/mc.alpgen.zjets.jvf.root ../plots/jvf_plots/mc.alpgen.z*
hadd -f ../plots/jvf_plots/merged/qcd.alpgen.jvf.root ../plots/jvf_plots/qcd.*

hadd -f ../plots/nojvf_plots/merged/mc.mcatnlo.top.nojvf.root ../plots/nojvf_plots/mc.mcatnlo.*
hadd -f ../plots/nojvf_plots/merged/mc.herwig.vv.nojvf.root ../plots/nojvf_plots/mc.herwig.*
hadd -f ../plots/nojvf_plots/merged/mc.alpgen.wjets.nojvf.root ../plots/nojvf_plots/mc.alpgen.w*
hadd -f ../plots/nojvf_plots/merged/mc.alpgen.zjets.nojvf.root ../plots/nojvf_plots/mc.alpgen.z*
hadd -f ../plots/nojvf_plots/merged/qcd.alpgen.nojvf.root ../plots/nojvf_plots/qcd.*
#r 'merge.C("jvf")'
#r 'merge.C("nojvf")'