import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import sys

file = "surface"

if len(sys.argv) > 1:
	file = sys.argv[1]

df = pd.read_csv("surface.csv", header=None, sep=" ")

details = df.tail(1)[0].values[0].split(",")

Z=np.array(df[:-1].astype(float))

X = np.arange(0, Z.shape[0], 1)
Y = np.arange(0, Z.shape[1], 1)

X2D,Y2D = np.meshgrid(X,Y)

fig = plt.figure()
ax = Axes3D(fig)

ax.plot_surface(X2D,Y2D, Z)

plt.suptitle("threads: {}, iterations: {}, runtime: {}s, dim: {}, eps: {}".format(details[0], details[1], details[2], details[3], details[4]))
plt.savefig("{}_plot.pdf".format(file))
plt.show()