from __future__ import division,print_function,unicode_literals
import math
import numpy as np
import matplotlib.pyplot as plt

def cost(x):
    x = np.array(x,dtype=np.float64)
    return x**2 + 5*np.sin(x)

def  grad(x):
    return 2*x + 5*np.cos(x)

def myGD1(alpha,x0,gra = 1e-3 ,loop=1000):
    x = [x0]
    for i in range(loop):
        x_new = x[-1] - alpha*grad(x[-1])
        if abs(grad(x_new)) < gra:
            break
        x.append(x_new)
    return x,i

if __name__ == '__main__':
	X=np.linspace(-5,5,100)
	Y=cost(X)
	plt.plot(X.T,Y.T,'b. ')
	plt.plot(-5,5,-5,20)

	(x1,i1)= myGD1(.1,10)
	(x2,i2)=myGD1(.1,-10)
	print('Solution x1=%f,cost=%f,obtained after %d iterations'%(x1[-1],cost(x1[-1]),i1))
	print('Solution x1=%f,cost=%f,obtained after %d iterations'%(x2[-1],cost(x2[-1]),i2))
	plt.show()
