import numpy as np
import matplotlib.pyplot as plt

x1, y1, x2, y2, x3, y3 = np.loadtxt("dataPositions.txt", unpack = True)

for k in np.arange(len(x1)):
    #plot every 25th line of data, skip first 100 points
    if(k%25 == 0 and k >= 100):
        plt.ioff()    
        plt.plot(x1[0:6300], y1[0:6300], "k--")        
        plt.plot(x1[k-100:k], y1[k-100:k],linewidth = 3, label = "1")
        plt.plot(x2[k-100:k], y2[k-100:k],linewidth = 3, label = "2")
        plt.plot(x3[k-100:k], y3[k-100:k],linewidth = 3, label = "3")
        plt.xlabel("x")
        plt.ylabel("y")
        plt.legend()
        plt.savefig("Plots/" + str(k).rjust(5, "0") + "_3BodyPositions.png")
        plt.close()