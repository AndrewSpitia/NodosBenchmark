import pandas as pd

nodes = ["A","B","C","G","H","I"]
dfs = [pd.read_csv("results/results-"+node+".csv") for node in nodes]
for df in dfs:
    df.sort_values(by=["Load","Algorithm"],inplace=True)
    df.to_csv("results/results-"+df["Node"].iloc[0]+".csv",index=False)