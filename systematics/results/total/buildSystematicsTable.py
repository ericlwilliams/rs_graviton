#! /usr/bin/python
import math
import systematics_info

out_file = open("index.csv","w")

## needs to match order of ../../../include/systematics_defs
samples = ["herwig.ww","herwig.wz","herwig.zz","mcatnlo.ttbar",
           "mcatnlo.singletop","alpgen.wjets","alpgen.zjets","qcd.alpgen",
           "rsg.m500","rsg.m750","rsg.m1000","rsg.m1250","rsg.m1500",
           "wprime.wz.m500","wprime.wz.m600","wprime.wz.m700",
           "wprime.wz.m800","wprime.wz.m900","wprime.wz.m1000",
           "wprime.wz.m1100","wprime.wz.m1200","wprime.wz.m1300",
           "wprime.wz.m1400","wprime.wz.m1500"]

systematics = systematics_info.systematics
systematics_files = systematics_info.systematics_files


systematics_logs = [open("../../logs/"+sys) for sys in systematics_files]

## Write header
out_file.write("systematic,")
for idx,samp in enumerate(samples):
    if idx==len(samples)-1:
        out_file.write(samp)
    else:
        out_file.write(samp+",")
out_file.write("\n")
    
## Print each systematic for given sample

for ldx,log in enumerate(systematics_logs):
    out_file.write(systematics[ldx]+",")
    cur_log = log.readlines()
    found_sys=0
    for line in cur_log:
        for samp in samples:
            if line.find(samp)==0:
                out_file.write(line[line.find(",")+1:line.rfind(",")]+"|"+line[line.rfind(",")+1:].rstrip("\n"))
                if(samp=="rsg.m1000"):
                    towrite = line[line.find(",")+1:line.rfind(",")]+","+line[line.rfind(",")+1:].rstrip("\n")
                found_sys+=1
                if found_sys!=len(samples):
                    out_file.write(",")
    out_file.write("\n")
    
    
out_file.write("\n")
out_file.close()


