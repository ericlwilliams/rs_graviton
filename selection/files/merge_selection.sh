#!/bin/zsh -

## Merges selection plot files without any xsec info
## Results should only be plotted with ->Scale(1)

echo "Merging sel.alpgen.wjets"

hadd -f ../../plots/selection_plots/merged/sel.bkgd.selection.root ./mc.sel.alpgen.w* ./mc.sel.alpgen.z* ./mc.sel.mcatnlo.* ./mc.sel.herwig.* ./mc.sel.pythia*
#hadd -f ../../plots/selection_plots/merged/sel.bkgd.selection.root ./mc.sel.alpgen.w* ./mc.sel.alpgen.z* ./mc.sel.mcatnlo.* ./mc.sel.herwig.*

hadd -f ../../plots/selection_plots/merged/sel.qcd.selection.root ./mc.sel.pythia*
hadd -f ../../plots/selection_plots/merged/sel.nonqcd.selection.root ./mc.sel.alpgen.w* ./mc.sel.alpgen.z* ./mc.sel.mcatnlo.* ./mc.sel.herwig.*

echo "Merging data"
hadd -f ../../plots/selection_plots/merged/sel.data.selection.root ../files/data.sel.*

