import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

df = pd.read_csv('result.csv')


fig = plt.figure()

ax1 = fig.add_subplot(3,1,1)

ax1.set_title('runtime')
mean_values = df.groupby(['NumThreads','Dim'], as_index = False).mean()
for i in sorted(set(mean_values['Dim'])):
	a = mean_values.loc[mean_values.Dim == i]
	ax1.plot(a['NumThreads'], a['Runtime'], marker = "o", label = "{dim}x{dim}".format(dim = i))
ax1.legend()

ax2 = fig.add_subplot(3,1,2)
accelerations = dict()
ax2.set_title('Acceleration')
for i in sorted(set(mean_values['Dim'])):
    x = mean_values.loc[mean_values.Dim == i]
    one_thread_t = float(x[x.NumThreads == 1]['Runtime'])
    accelerations[i] = one_thread_t / x['Runtime']
    ax2.plot(x['NumThreads'], accelerations[i], marker=".", label="{dim}x{dim}".format(dim = i))
ax2.legend()

ax3 = fig.add_subplot(3,1,3)

ax3.set_title('efficiency')
for i in sorted(set(mean_values['Dim'])):
    x = mean_values.loc[mean_values.Dim == i]
    ax3.plot(x['NumThreads'], accelerations[i] / x['NumThreads'].astype(float), marker=".", label="{dim}x{dim}".format(dim = i))
ax3.legend()



plt.show()