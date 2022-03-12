import csv
import random
import pandas as pd
nodes=["A","B","C","G","H","I"]
f = [(open('results/results-'+node+'.csv','r'),node) for node in nodes]
for file,node in f:
    reader = csv.reader(file)
    lines=[]
    for row in reader:
        row[0]=row[0].replace("\t",",").replace("\\t",",")
        row[0]=row[0].replace(" ","")
        lines.append(row[0][:len(row[0])-1].split(","))
    df = pd.DataFrame(lines,columns=["Node","Load","Algorithm","Time"])
    file.close()
    df.to_csv('results/results-'+node+'.csv',index=False)
        
