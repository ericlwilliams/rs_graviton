from ROOT import *
import SetAtlasStyle
import sys

gROOT.SetBatch()

if(len(sys.argv)>1): # run over file specified by runExclusionPlot.sh
    filename = sys.argv[1]
else: # run over file specified below
    filename = "./exclusion_limits/gww_met30_ptlv150_ptjj250_lep_met_sig_jet_m.limits";

print filename

masses = map( int, open("gww.mass.list","r").readlines() )

ge2=dict()
ge1=dict()
ge=dict()
g=dict()

found_cls=dict()
found_ecls2hi=dict()
found_ecls1hi=dict()
found_ecls=dict()
found_ecls1lo=dict()
found_ecls2lo=dict()

found_clsb=dict()
found_eclsb2hi=dict()
found_eclsb1hi=dict()
found_eclsb=dict()
found_eclsb1lo=dict()
found_eclsb2lo=dict()

graphsN=dict()
graphs=dict()

model_xsec_high=dict()

model_xsec_high[500]=5.693
model_xsec_high[750]=0.6145
model_xsec_high[1000]=0.111
model_xsec_high[1250]=0.02656

model_xsec_low=dict()
model_xsec_low[500]=0.05735
model_xsec_low[750]=0.006252
model_xsec_low[1000]=0.00114
model_xsec_low[1250]=0.000271

model_xsec_mid=dict()
model_xsec_mid[500]=0.5155
model_xsec_mid[750]=0.05646
model_xsec_mid[1000]=0.01010
model_xsec_mid[1250]=0.002422

for mass in masses: 
    ge2[mass]=TGraphAsymmErrors()
    ge2[mass].SetFillColor(3)
    ge2[mass].SetFillStyle(1001)
    ge1[mass]=TGraphAsymmErrors()
    ge1[mass].SetFillColor(5)
    ge1[mass].SetFillStyle(1001)
    ge[mass]=TGraph()
    ge[mass].SetLineColor(2) ##?? ecls cls??
    ge[mass].SetLineWidth(2)
    ge[mass].SetLineStyle(1)
    g[mass]=TGraph()
    g[mass].SetLineColor(1)
    g[mass].SetLineWidth(2)
    g[mass].SetLineStyle(2)

    found_cls[mass]=False
    found_ecls2hi[mass]=False
    found_ecls1hi[mass]=False
    found_ecls[mass]=False
    found_ecls1lo[mass]=False
    found_ecls2lo[mass]=False

    found_clsb[mass]=False
    found_eclsb2hi[mass]=False
    found_eclsb1hi[mass]=False
    found_eclsb[mass]=False
    found_eclsb1lo[mass]=False
    found_eclsb2lo[mass]=False

    graphsN[mass]=0
    graphs[mass]=TGraph()
    graphs[mass].SetLineWidth(3)
#    graphs[mass].SetLineColor(mass_colors[mass])
    


#t=hwwlimits
## entries are in order of mass/xsec_factor/channel
for mass,xsec,cls,ecls2lo,ecls1lo,ecls,ecls1hi,ecls2hi,clsb,eclsb2lo,eclsb1lo,eclsb,eclsb1hi,eclsb2hi  in [map(float, i.split()) for i in open(filename,"r").readlines()]:
#for i in range(t.GetEntries()):
#    entry=t.GetEntry(i)
    ge2[mass].SetPoint( graphsN[mass], xsec, 1-cls)
    ge2[mass].SetPointError(  graphsN[mass], 0., 0., ecls2lo-ecls, ecls-ecls2hi)

    ge1[mass].SetPoint( graphsN[mass], xsec, 1-cls)
    ge1[mass].SetPointError( graphsN[mass], 0., 0., ecls1lo-ecls, ecls-ecls1hi)

    ge[mass].SetPoint( graphsN[mass], xsec, 1-ecls)

    g[mass].SetPoint( graphsN[mass], xsec, 1-cls)

    graphsN[mass]+=1
#     entry=t.GetEntry(i)
#     ge2[t.mass].SetPoint( graphsN[t.mass], t.xsec_factor*xsec[t.mass], 1-t.cls)
#     ge2[t.mass].SetPointError(  graphsN[t.mass], 0., 0., t.ecls2lo-t.ecls, t.ecls-t.ecls2hi)

#     ge1[t.mass].SetPoint( graphsN[t.mass], t.xsec_factor*xsec[t.mass], 1-t.cls)
#     ge1[t.mass].SetPointError( graphsN[t.mass], 0., 0., t.ecls1lo-t.ecls, t.ecls-t.ecls1hi)

#     ge[t.mass].SetPoint( graphsN[t.mass], t.xsec_factor*xsec[t.mass], 1-t.ecls)

#     g[t.mass].SetPoint( graphsN[t.mass], t.xsec_factor*xsec[t.mass], 1-t.cls)

#     ge2[t.mass].SetPoint( graphsN[t.mass], t.xsec_factor, 1-t.cls)
#     ge2[t.mass].SetPointError(  graphsN[t.mass], 0., 0., t.ecls2lo-t.ecls, t.ecls-t.ecls2hi)

#     ge1[t.mass].SetPoint( graphsN[t.mass], t.xsec_factor, 1-t.cls)
#     ge1[t.mass].SetPointError( graphsN[t.mass], 0., 0., t.ecls1lo-t.ecls, t.ecls-t.ecls1hi)

#     ge[t.mass].SetPoint( graphsN[t.mass], t.xsec_factor, 1-t.ecls)

#     g[t.mass].SetPoint( graphsN[t.mass], t.xsec_factor, 1-t.cls)

#    print t.ecls-t.ecls2hi, t.ecls2lo-t.ecls

#    graphsN[t.mass]+=1


    if 1-cls > 0.95 and not found_cls[mass]:
        #print "cls", mass, xsec, 1-cls 
        found_cls[mass] = xsec

    if 1-ecls > 0.95 and not found_ecls[mass]:
        #print "ecls", mass, xsec, 1-ecls 
        found_ecls[mass] = xsec

    if 1-ecls1hi > 0.95 and not found_ecls1hi[mass]:
        #print "ecls1hi", mass, xsec, 1-ecls1hi 
        found_ecls1hi[mass] = xsec

    if 1-ecls1lo > 0.95 and not found_ecls1lo[mass]:
        #print "ecls1lo", mass, xsec, 1-ecls1lo 
        found_ecls1lo[mass] = xsec

    if 1-ecls2hi > 0.95 and not found_ecls2hi[mass]:
        #print "ecls2hi", mass, xsec, 1-ecls2hi 
        found_ecls2hi[mass] = xsec

    if 1-ecls2lo > 0.95 and not found_ecls2lo[mass]:
        #print "ecls2lo", mass, xsec, 1-ecls2lo 
        found_ecls2lo[mass] = xsec

    if 1-clsb > 0.95 and not found_clsb[mass]:
        #print "clsb", mass, xsec, 1-clsb 
        found_clsb[mass] = xsec

    if 1-eclsb > 0.95 and not found_eclsb[mass]:
        #print "eclsb", mass, xsec, 1-eclsb 
        found_eclsb[mass] = xsec

    if 1-eclsb1hi > 0.95 and not found_eclsb1hi[mass]:
        #print "eclsb1hi", mass, xsec, 1-eclsb1hi 
        found_eclsb1hi[mass] = xsec

    if 1-eclsb1lo > 0.95 and not found_eclsb1lo[mass]:
        #print "eclsb1lo", mass, xsec, 1-eclsb1lo 
        found_eclsb1lo[mass] = xsec

    if 1-eclsb2hi > 0.95 and not found_eclsb2hi[mass]:
        #print "eclsb2hi", mass, xsec, 1-eclsb2hi 
        found_eclsb2hi[mass] = xsec

    if 1-eclsb2lo > 0.95 and not found_eclsb2lo[mass]:
        #print "eclsb2lo", mass, xsec, 1-eclsb2lo 
        found_eclsb2lo[mass] = xsec

print str("mass").ljust(10),
print str("cls").ljust(10),
print str("ecls2hi").ljust(10),
print str("ecls1hi").ljust(10),
print str("ecls").ljust(10),
print str("ecls1lo").ljust(10),
print str("ecls2lo").ljust(10),

print str("clsb").ljust(10),
print str("eclsb2hi").ljust(10),
print str("eclsb1hi").ljust(10),
print str("eclsb").ljust(10),
print str("eclsb1lo").ljust(10),
print str("eclsb2lo").ljust(10)

#for mass in masses[0:-2]:
for mass in masses:
    
    print str(mass).ljust(10),
    print str(found_cls[mass]).ljust(10),
    print str(found_ecls2hi[mass]).ljust(10),
    print str(found_ecls1hi[mass]).ljust(10),
    print str(found_ecls[mass]).ljust(10),
    print str(found_ecls1lo[mass]).ljust(10),
    print str(found_ecls2lo[mass]).ljust(10),

    print str(found_clsb[mass]).ljust(10),
    print str(found_eclsb2hi[mass]).ljust(10),
    print str(found_eclsb1hi[mass]).ljust(10),
    print str(found_eclsb[mass]).ljust(10),
    print str(found_eclsb1lo[mass]).ljust(10),
    print str(found_eclsb2lo[mass]).ljust(10)

g_cls_e2=TGraphAsymmErrors()
g_cls_e2.SetFillColor(3)
g_cls_e2.SetFillStyle(1001)
g_cls_e1=TGraphAsymmErrors()
g_cls_e1.SetFillColor(5)
g_cls_e1.SetFillStyle(1001)
g_cls_e=TGraph()
g_cls_e.SetLineColor(1)
g_cls_e.SetLineWidth(2)
g_cls_e.SetLineStyle(2)
g_cls=TGraph()
g_cls.SetLineColor(2)
g_cls.SetLineWidth(2)
g_cls.SetLineStyle(1)

g_clsb_e2=TGraphAsymmErrors()
g_clsb_e2.SetFillColor(3)
g_clsb_e2.SetFillStyle(1001)
g_clsb_e2hi=TGraphAsymmErrors()
g_clsb_e2hi.SetFillColor(3)
g_clsb_e2hi.SetFillStyle(1001)
g_clsb_e1=TGraphAsymmErrors()
g_clsb_e1.SetFillColor(5)
g_clsb_e1.SetFillStyle(1001)
g_clsb_e=TGraph()
g_clsb_e.SetLineColor(1)
g_clsb_e.SetLineWidth(2)
g_clsb_e.SetLineStyle(2)
g_clsb=TGraph()
g_clsb.SetLineColor(2)
g_clsb.SetLineWidth(2)
g_clsb.SetLineStyle(1)

g_xsec_high=TGraph()
g_xsec_high.SetLineColor(6)
g_xsec_high.SetLineWidth(1)
g_xsec_high.SetLineStyle(1)

g_xsec_low=TGraph()
g_xsec_low.SetLineColor(8)
g_xsec_low.SetLineWidth(1)
g_xsec_low.SetLineStyle(1)

g_xsec_mid=TGraph()
g_xsec_mid.SetLineColor(7)
g_xsec_mid.SetLineWidth(1)
g_xsec_mid.SetLineStyle(1)

#for i,mass in enumerate(masses[0:-2]):
for i,mass in enumerate(masses):
    
    g_cls_e2.SetPoint( i, mass, found_ecls[mass])
    g_cls_e2.SetPointError(  i, 0., 0., found_ecls[mass]-found_ecls2hi[mass], found_ecls2lo[mass]-found_ecls[mass])
    g_cls_e1.SetPoint( i, mass, found_ecls[mass])
    g_cls_e1.SetPointError( i, 0., 0., found_ecls[mass]-found_ecls1hi[mass],  found_ecls1lo[mass]-found_ecls[mass])
    g_cls_e.SetPoint( i, mass, found_ecls[mass])
    g_cls.SetPoint( i, mass, found_cls[mass])

    g_clsb_e2.SetPoint( i, mass, found_eclsb[mass])
    g_clsb_e2.SetPointError(  i, 0., 0., found_eclsb[mass]-found_eclsb2hi[mass], found_eclsb2lo[mass]-found_eclsb[mass])
    g_clsb_e2hi.SetPoint( i, mass, found_eclsb[mass])
    g_clsb_e2hi.SetPointError(  i, 0., 0., 0., found_eclsb2lo[mass]-found_eclsb[mass])
    g_clsb_e1.SetPoint( i, mass, found_eclsb[mass])
    g_clsb_e1.SetPointError( i, 0., 0., found_eclsb[mass]-found_eclsb1hi[mass],  found_eclsb1lo[mass]-found_eclsb[mass])
    g_clsb_e.SetPoint( i, mass, found_eclsb[mass])
    g_clsb.SetPoint( i, mass, found_clsb[mass])

    g_xsec_high.SetPoint( i, mass, model_xsec_high[mass])
    g_xsec_mid.SetPoint( i, mass, model_xsec_mid[mass])
    g_xsec_low.SetPoint( i, mass, model_xsec_low[mass])


xmin=450.
xmax=1350.
ymin=0.001
ymax=50.
frame=TH1F("frame","",100,xmin,xmax)
frame.SetMinimum(ymin)
frame.SetMaximum(ymax)
frame.SetDirectory(0)
frame.SetStats(0)
frame.GetXaxis().SetTitle("G* mass [GeV]")
frame.GetYaxis().SetTitle("95% CL #sigma(pp#rightarrowG*) #times BR(G*#rightarrowWW#rightarrowl#nujj) [pb]")
#frame.GetYaxis().SetNdivisions(5)
frame.GetXaxis().SetRangeUser(xmin,xmax)

leg=TLegend(0.58,0.7,0.99,0.99)
leg.SetFillColor(0)
leg.SetFillStyle(1001)
leg.SetBorderSize(0)
leg.AddEntry(g_cls,"Observed limit","l")
leg.AddEntry(g_cls_e,"Expected limit","l")
leg.AddEntry(g_cls_e1,"Expected limit #pm 1#sigma","f")
leg.AddEntry(g_cls_e2,"Expected limit #pm 2#sigma","f")
leg.AddEntry(g_xsec_high,"k/{M_{pl}}=0.1","l")
leg.AddEntry(g_xsec_mid,"k/{M_{pl}}=0.03","l")
leg.AddEntry(g_xsec_low,"k/{M_{pl}}=0.01","l")


c_cls=TCanvas()
c_cls.SetLogy()
frame.Draw(" ")
g_cls_e2.Draw("3")
g_cls_e1.Draw("3same")
g_cls_e.Draw("lsame")
g_cls.Draw("lsame")
g_xsec_high.Draw("csame")
g_xsec_mid.Draw("csame")
g_xsec_low.Draw("csame")
c_cls.RedrawAxis()
frame.Draw("same")
leg.Draw()
c_cls.SaveAs("./plots/latest/lim_cls_"+filename[filename.find("gww"):len(filename)-7]+".png")

c_clsb=TCanvas()
c_clsb.SetLogy()
frame.Draw(" ")
g_clsb_e2.Draw("3")
g_clsb_e1.Draw("3same")
g_clsb_e.Draw("lsame")
g_clsb.Draw("lsame")
g_xsec_high.Draw("csame")
g_xsec_mid.Draw("csame")
g_xsec_low.Draw("csame")
c_clsb.RedrawAxis()
frame.Draw("same")
leg.Draw()
c_clsb.SaveAs("./plots/latest/lim_clsb_"+filename[filename.find("gww"):len(filename)-7]+".png")

c_pcl=TCanvas()
c_pcl.SetLogy()
frame.Draw(" ")
g_clsb_e2hi.Draw("3")
g_clsb_e1.Draw("3same")
g_clsb_e.Draw("lsame")
g_clsb.Draw("lsame")
g_xsec_high.Draw("csame")
g_xsec_mid.Draw("csame")
g_xsec_low.Draw("csame")
c_pcl.RedrawAxis()
frame.Draw("same")
leg.Draw()
c_pcl.SaveAs("./plots/latest/lim_pcl_"+filename[filename.find("gww"):len(filename)-7]+".png")

# for mass in masses: 
#     c_mass=TCanvas()
#     xmin=0.
#     xmax=2.05
#     ymin=0.7
#     ymax=1.
# #     frame=TH1F("frame","",100,xmin,xmax)
# #     frame.SetMinimum(ymin)
# #     frame.SetMaximum(ymax)
# #     frame.SetDirectory(0)
# #     frame.SetStats(0)
# #     frame.GetXaxis().SetTitle("cross section [pb]")
# #     frame.GetYaxis().SetTitle("confidence level (1 - CLs)")
# #     #frame.GetYaxis().SetNdivisions(5)
# #     frame.GetXaxis().SetRangeUser(xmin,xmax)
# #     frame.Draw(" ")
#     ge2[mass].Draw("3a")
#     ge1[mass].Draw("3same")
#     ge[mass].Draw("lsame")
#     g[mass].Draw("lsame")
#     line95=TLine(xmin,0.95,xmax,0.95)
#     line95.Draw()
#     line_xsec=TLine(xsec[mass],ymin,xsec[mass],ymax)
#     line_xsec.Draw()
#     c_mass.RedrawAxis()
#     c_mass.SaveAs("CL"+str(mass)+".pdf")
    
# # for mass in masses:
# #     c_mass=TCanvas()
# #     xmin=0
# # #    xmin=xsec[mass]
# #     xmax=1+xsec[mass]*2
# #     frame=TH1F("frame","",100,xmin,xmax)
# #     frame.SetMinimum(0.7)
# #     frame.SetMaximum(1)
# #     frame.SetDirectory(0)
# #     frame.SetStats(0)
# #     frame.GetXaxis().SetTitle("cross section [pb]")
# #     frame.GetYaxis().SetTitle("confidence level (1 - CLs)")
# #     #frame.GetYaxis().SetNdivisions(5)
# #     frame.GetXaxis().SetRangeUser(xmin,xmax)
# #     frame.Draw(" ")
# #     ge2[mass].Draw("3")
# #     ge1[mass].Draw("3same")
# #     ge[mass].Draw("lsame")
# #     g[mass].Draw("lsame")
# #     line.Draw()
# #     xsec.Draw()
# #     c_mass.RedrawAxis()
# #     c_mass.SaveAs("CL"+str(mass)+".pdf")
    

