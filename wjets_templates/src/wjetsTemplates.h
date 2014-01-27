#ifndef wjetsTemplates_h
#define wjetsTemplates_h

#include <string>


class wjetsTemplates : public TObject {



 public:

  
  wjetsTemplates();
  virtual ~wjetsTemplates(){};

  virtual void makeSignalParameterFits(string channel="evjj",string sys="jes_nom");
  virtual void makeClosurePlots(string channel="evjj",string sys="jes_nom");
  ClassDef(wjetsTemplates,0);
};
#endif
