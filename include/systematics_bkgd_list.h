#include <string>
string systematics_bkgd_list[] = {

  "mc.alpgen.wjets",
  "mc.alpgen.cont.wjets",
  //"qcd.alpgen",

  "mc.herwig.vv",
  "mc.herwig.wz",
  "mc.herwig.zz",
  "mc.herwig.ww",

  "mc.alpgen.zjets",
  
  "mc.mcatnlo.ttbar",
  "mc.mcatnlo.singletop",
  "mc.mcatnlo.top",
  
  "mc.rsg.m500.kmpl0_1",
  "mc.rsg.m750.kmpl0_1",
  "mc.rsg.m1000.kmpl0_1",
  "mc.rsg.m1250.kmpl0_1",
  "mc.rsg.m1500.kmpl0_1",

  "mc.afii.kkg.lvjj.m500",
  "mc.afii.kkg.lvjj.m600",
  "mc.afii.kkg.lvjj.m700",
  "mc.afii.kkg.lvjj.m800",
  "mc.afii.kkg.lvjj.m900",
  "mc.afii.kkg.lvjj.m1000",
  "mc.afii.kkg.lvjj.m1100",
  "mc.afii.kkg.lvjj.m1200",
  "mc.afii.kkg.lvjj.m1300",
  "mc.afii.kkg.lvjj.m1400",
  "mc.afii.kkg.lvjj.m1500",

  "mc.wprime.wz.m500",
  "mc.wprime.wz.m600",
  "mc.wprime.wz.m700",
  "mc.wprime.wz.m800",
  "mc.wprime.wz.m900",
  "mc.wprime.wz.m1000",
  "mc.wprime.wz.m1100",
  "mc.wprime.wz.m1200",
  "mc.wprime.wz.m1300",
  "mc.wprime.wz.m1400",
  "mc.wprime.wz.m1500"

  /* "mc.wprime.wz.lvqq.m500", */
  /* "mc.wprime.wz.lvqq.m600", */
  /* "mc.wprime.wz.lvqq.m700", */
  /* "mc.wprime.wz.lvqq.m800", */
  /* "mc.wprime.wz.lvqq.m900", */
  /* "mc.wprime.wz.lvqq.m1000", */
  /* "mc.wprime.wz.lvqq.m1100", */
  /* "mc.wprime.wz.lvqq.m1200", */
  /* "mc.wprime.wz.lvqq.m1300", */
  /* "mc.wprime.wz.lvqq.m1400", */
  /* "mc.wprime.wz.lvqq.m1500" */

    
  
};

int systematics_nBkgds = sizeof(systematics_bkgd_list)/sizeof(systematics_bkgd_list[0]);