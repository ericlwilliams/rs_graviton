void testRooFit(){

  gSystem->Load("libRooFit");
  using namespace RooFit;

  RooRealVar x("x","x",-10,10);
  RooRealVar mean("mean","mean of gaussian",0,-10,10);
  RooRealVar sigma("sigma","width of bw",0.5);

  RooBreitWigner bw("bw","Breit Wigner PDF",x,mean,sigma);

  RooPlot* xframe = x.frame();
  bw.plotOn(xframe);
  xframe->Draw();


  return;
}
