#! /usr/bin/python
## only run after index.csv is built from buildSystematicsTable.py
import math
import systematics_info

elec_bkgd_file = open("elec_bkgd_index.csv","w")
muon_bkgd_file = open("muon_bkgd_index.csv","w")

samples = ["alpgen.wjets","alpgen.zjets","mcatnlo.ttbar","mcatnlo.singletop","herwig.ww","herwig.wz","herwig.zz","qcd.alpgen"]

systematics = systematics_info.systematics


index_file = open("index.csv","r")
systematics_data = index_file.readlines()
index_file.close()

systematics = systematics_data[0].split(",")

sample_inds =[]
elec_bkgd_file.write("systematic,")
muon_bkgd_file.write("systematic,")
for samp_ind,samp in enumerate(samples):
    if samp_ind==len(samples)-1:
        elec_bkgd_file.write(samp+"\n")
        muon_bkgd_file.write(samp+"\n")
    else: 
        elec_bkgd_file.write(samp+",")
        muon_bkgd_file.write(samp+",")
    for idx,sys in enumerate(systematics):
        if samp==sys:
            sample_inds.append(idx)

tot_evjj=[0 for sam in samples]
tot_uvjj=[0 for sam in samples]
for systematic in systematics_data[1:]:
    sys_vals = systematic.split(",")
    if sys_vals[0]=="Signal PDF": continue
    if len(sys_vals)==1: continue
    elec_bkgd_file.write(sys_vals[0]+",")
    muon_bkgd_file.write(sys_vals[0]+",")
    for sample_idx,ind in enumerate(sample_inds):

        elec_val = sys_vals[ind].split("|")[0]
        muon_val = sys_vals[ind].split("|")[1]        
        if elec_val != "-":
            if samples[sample_idx].find("alpgen")!=0:
                tot_evjj[sample_idx] += math.pow(float(elec_val),2)
            elif sys_vals[0]=="V+jets":
                tot_evjj[sample_idx] += math.pow(float(elec_val),2)
        if muon_val != "-":
            if samples[sample_idx].find("alpgen")!=0:
                tot_uvjj[sample_idx] += math.pow(float(muon_val),2)
            elif sys_vals[0]=="V+jets":
                tot_uvjj[sample_idx] += math.pow(float(muon_val),2)
        if sample_idx==len(sample_inds)-1:
            elec_bkgd_file.write(elec_val+"\n")
            muon_bkgd_file.write(muon_val+"\n")
        else:
            elec_bkgd_file.write(elec_val+",")
            muon_bkgd_file.write(muon_val+",")

tot_evjj = [math.sqrt(cur_tot_evjj) for cur_tot_evjj in tot_evjj]

elec_bkgd_file.write("Total,")
for evjj_idx,evjj_tot in enumerate(tot_evjj):
    val_len=5
    if str(evjj_tot).find(".")==1:
        val_len=4
    elec_bkgd_file.write(str(evjj_tot)[:val_len])
    if evjj_idx == len(tot_evjj)-1:
        elec_bkgd_file.write("\n")
    else:
        elec_bkgd_file.write(",")


tot_uvjj = [math.sqrt(cur_tot_uvjj) for cur_tot_uvjj in tot_uvjj]
muon_bkgd_file.write("Total,")
for uvjj_idx,uvjj_tot in enumerate(tot_uvjj):
    val_len=5
    if str(uvjj_tot).find(".")==1:
        val_len=4
    muon_bkgd_file.write(str(uvjj_tot)[:4])
    if uvjj_idx == len(tot_uvjj)-1:
        muon_bkgd_file.write("\n")
    else:
        muon_bkgd_file.write(",")
        

    
