#! /usr/bin/python
import math
import systematics_info

kkg_file = open("kkg_index.csv","w")

## needs to match order of ../../../include/systematics_defs
samples = ["afii.kkg.lvjj.m700"]

systematics = systematics_info.systematics
systematics_files = systematics_info.systematics_files

systematics_logs = [open("../../logs/"+sys) for sys in systematics_files]

## Write header
kkg_file.write("systematic,evjj,uvjj\n")
    
## Print each systematic for given sample
tot_evjj=0
tot_uvjj=0
for ldx,log in enumerate(systematics_logs):
    if(systematics_files[ldx]=="qcd_norm.csv"): continue
    if(systematics_files[ldx]=="vjets_norm.csv"): continue
    kkg_file.write(systematics[ldx]+",")
    cur_log = log.readlines()
    found_sys=0
    for line in cur_log:
        for samp in samples:
            if line.find(samp)==0:
                evjj = float(line[line.find(",")+1:line.rfind(",")])
                uvjj = float(line[line.rfind(",")+1:])
                tot_evjj += math.pow(evjj,2)
                tot_uvjj += math.pow(uvjj,2)
                towrite = line[line.find(",")+1:line.rfind(",")]+","+line[line.rfind(",")+1:].rstrip("\n")
                kkg_file.write(towrite)
    kkg_file.write("\n")


tot_evjj = math.sqrt(tot_evjj)
tot_uvjj = math.sqrt(tot_uvjj)
kkg_file.write("Total,"+str(tot_evjj)[:4]+","+str(tot_uvjj)[:4])

kkg_file.write("\n")
kkg_file.close()

