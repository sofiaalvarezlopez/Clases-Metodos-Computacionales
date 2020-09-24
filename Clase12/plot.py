import numpy as np
import matplotlib.pyplot as plt
import os

data = np.loadtxt("energy.txt", skiprows=7)
x = data[:,0]
y = data[:,1]

plt.plot(x,y)
plt.show()
