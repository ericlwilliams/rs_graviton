#ifndef signalShapesKKG_h
#define signalShapesKKG_h

#include <string>


class signalShapesKKG : public TObject {



 public:

  
  signalShapesKKG();
  virtual ~signalShapesKKG(){};

  virtual void makeSignalParameterFits(string channel="evjj",string sys="jes_nom");
  virtual void makeClosurePlots(string channel="evjj",string sys="jes_nom");
  ClassDef(signalShapesKKG,0);
};
#endif
