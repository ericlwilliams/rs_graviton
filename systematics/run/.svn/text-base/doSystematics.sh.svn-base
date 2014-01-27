#!/bin/zsh -

echo "Running systematics"
echo

echo "Writing and plotting\t\t - JES systematics"
r 'runSystematics.C("jes")'
r 'plotSystematics.C("jes")'

echo "Writing and plotting\t\t - JER systematics"
r 'runSystematics.C("jer")'
r 'plotSystematics.C("jer")'

echo "Writing and plotting\t\t - LES systematics"
r 'runSystematics.C("les")'
r 'plotSystematics.C("les")'

echo "Writing and plotting\t\t - LER systematics"
r 'runSystematics.C("ler")'
r 'plotSystematics.C("ler")'

echo "Writing and plotting\t\t - COEF systematics"
r 'runSystematics.C("coef")'
r 'plotSystematics.C("coef")'

echo "Writing and plotting\t\t - SJETS systematics"
r 'runSystematics.C("sjets")'
r 'plotSystematics.C("sjets")'

echo "Writing and plotting\t\t - IDSF systematics"
r 'runSystematics.C("idsf")'
r 'plotSystematics.C("idsf")'

echo "Writing and plotting\t\t - ISOSF systematics"
r 'runSystematics.C("isosf")'
r 'plotSystematics.C("isosf")'

echo "Writing and plotting\t\t - RECOSF systematics"
r 'runSystematics.C("recosf")'
r 'plotSystematics.C("recosf")'

echo "Writing and plotting\t\t - TRIGSF systematics"
r 'runSystematics.C("trigsf")'
r 'plotSystematics.C("trigsf")'

echo "Writing and plotting\t\t - ALLCL systematics"
r 'runSystematics.C("allcl")'
r 'plotSystematics.C("allcl")'

echo "Writing and plotting\t\t - METPU systematics"
r 'runSystematics.C("metpu")'
r 'plotSystematics.C("metpu")'

echo "Writing and plotting\t\t - VJETS systematics"
r 'runSystematics.C("vjets")'
r 'plotSystematics.C("vjets")'


echo "Making Systematic PDFs"

cd ../results/jes
pdfl jes.tex

cd ../jer
pdfl jer.tex

cd ../les
pdfl les.tex

cd ../ler
pdfl ler.tex

cd ../coef
pdfl coef.tex

cd ../sjets
pdfl sjets.tex

cd ../idsf
pdfl idsf.tex

cd ../isosf
pdfl isosf.tex

cd ../recosf
pdfl recosf.tex

cd ../trigsf
pdfl trigsf.tex

cd ../allcl
pdfl allcl.tex

cd ../metpu
pdfl metpu.tex

cd ../vjets
pdfl vjets.tex

cd ../total
#./joinPDF.py -o systematics.pdf ../jes/jes.pdf ../jer/jer.pdf
src joinSystematics.sh
src makeSystematicsTable.sh


cd ../../run

echo "Done, see ../results/total/systematics.pdf for results"
echo "and ../results/total/lvjj_systematics.pdf for complete list"