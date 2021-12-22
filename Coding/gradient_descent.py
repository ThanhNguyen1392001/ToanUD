from __future__ import division, print_function, unicode_literals
import math
import numpy as np
import matplotlib.pyplot as plt


def cost(x):
    x = np.array(x, dtype=np.float64)
    return (1 - 2/exp(x))**2


def grad(x):
    return (1 - 2 / exp(x)) * 4/exp(x)


def myGD1(eta, x0):
    x = [x0]
    for it in range(100):
        x_new = x[-1] - eta*grad(x[-1])
        if abs(grad(x_new)) < 1e-3:
            break
        x.append(x_new)
    return (x, it)


if __name__ == '__main__':
    X = np.linspace(-5, 5, 100)
    Y = cost(X)
    (x1, i1) = myGD1(.01, 5)
    (x2, i2) = myGD1(.01, -5)
    (x3, i3) = myGD1(.01, 3)
    print('Solution x1=%f,cost=%f,obtained after %d iterations' %
          (x1[-1], cost(x1[-1]), i1))
    print('Solution x2=%f,cost=%f,obtained after %d iterations' %
          (x2[-1], cost(x2[-1]), i2))
    print('Solution x2=%f,cost=%f,obtained after %d iterations' %
          (x3[-1], cost(x3[-1]), i3))
