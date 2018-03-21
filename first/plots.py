import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

df = pd.read_csv('result.csv')
mean_values = df.groupby(['NumThreads','Dim'], as_index = False).mean()

for i in sorted(set(mean_values['Dim'])):
    a = mean_values.loc[mean_values.Dim == i]
    plt.plot(a['NumThreads'], a['Runtime'], marker = "o", label = "{dim}x{dim}".format(dim = i))
plt.legend()
plt.xlabel('threads')
plt.ylabel('runtime (s)')
plt.show()
