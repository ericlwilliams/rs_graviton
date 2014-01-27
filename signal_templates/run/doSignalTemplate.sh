#!/bin/zsh -

echo "Making signal templates for G*, Gkk and W' samples"


r 'runMakeSignalParameterFits.C("all")'
r 'runMakeSignalParameterFitsKKG.C("all")'
r 'runMakeSignalParameterFitsWprime.C("all")'

echo "done"