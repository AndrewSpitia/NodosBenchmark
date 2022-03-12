import csv
import pandas as pd
nodes=["C"]
f = [(open('results/results-'+node+'.csv','r'),node) for node in nodes]
for file,node in f:
    reader = csv.reader(file)
    lines=[]
    for row in reader:
        row[0]=row[0].replace("\t",",").replace("\\t",",")
        row[0]=row[0].replace(" ","")
        lines.append(row[0][:len(row[0])-1].split(","))
    df = pd.DataFrame(lines,columns=["Node","Load","Algorithm","Time"])
    df['Load'] = df['Load'].astype('float64')
    df['Time'] = df['Time'].astype('float64')
    grouped=df.groupby(["Node","Load","Algorithm"])
    info = grouped["Time"].describe()
    info.to_csv("results/info-"+node+".csv")
    to_filter_info = pd.read_csv("results/info-"+node+".csv")
    print(to_filter_info)

    #df.to_csv('results/results-copy-'+node+'.csv',index=False)
        
