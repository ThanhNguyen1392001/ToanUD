import numpy as np

from math import sqrt

from numpy import linalg

def findD(w, A):
    n = len(w)
    D = np.zeros_like(A)
    for i in range(n):
        D[i, i] = sqrt(w[i])
    return D

# main
arr = [[7.5, 1.5, 10, 8], [1.5, 20, 4.5, 7], [10, 2.5, 3, 4]] 
A = np.array(arr)
At = np.transpose(A) # Ma tran chuyen vi
print('----Matrix A: ----\n' + str(A) + '\n')
AtA = np.dot(At, A) # Ma tran chuyen vi At * A
AAt = np.dot(A, At) # Ma tran A * At

w, U = linalg.eig(AAt) # U : vecto rieng ma tran AAt,w la gia tri rieng ->> de tim D
_, V = linalg.eig(AtA) # V : vecto rieng ma tran AtA
Vt = np.transpose(V)
D = findD(w, A) # tim ma tran cheo D tu gia tri rieng landa_i

print('----Matrix U: ----\n' + str(U) + '\n')
print('----Matrix Vt: ----\n' + str(Vt) + '\n')
print('----Matrix D: ----\n' + str(D) + '\n')

K = np.dot(np.dot(U, D), Vt)
print('----Matrix K: ----\n' + str(K) + '\n')