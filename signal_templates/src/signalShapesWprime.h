#ifndef signalShapesWprime_h
#define signalShapesWprime_h

#include <string>


class signalShapesWprime : public TObject {



 public:

  
  signalShapesWprime();
  virtual ~signalShapesWprime(){};

  virtual void makeSignalParameterFits(string channel="evjj",string sys="jes_nom");
  virtual void makeClosurePlots(string channel="evjj",string sys="jes_nom");
  ClassDef(signalShapesWprime,0);
};
#endif
