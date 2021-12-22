import numpy as np

from math import sqrt

from numpy import linalg

check = True

def isPositiveDefiniteMatrix(arr): 
    w, v = linalg.eig(arr) 
    for i in range(0, len(w)):
        if(w[i] < 0): return False
    return True

def cholesky_decomposition(arr):
    global check
    if (isPositiveDefiniteMatrix(arr) == False): 
        print('Error!! Ma tran nay khong phai la ma tran duong\n')
        check = False
        return;
    arr = np.array(arr, float)
    L = np.zeros_like(arr)
    n,_ = np.shape(arr)
    for j in range(n):
        for i in range(j, n):
            if i == j:
                sum = 0
                for k in range(j):
                    sum += L[i, j]**2
                L[i, j] = np.sqrt(arr[i, j] - sum)
            else:
                sum = 0
                for k in range(j):
                    sum += L[i, k]*L[j, k]
                L[i, j] = (arr[i,j] - sum) / L[j, j]
    return L


# main 
#a = [[5, 1.5, 10], [21, 0, 4.5], [10, 2.5, 3]] #Truong hop khong phai ma tran duong
a = [[7.5, 1.5, 0], [1.5, 20, 4.5], [0, 2.5, 3]] 
arr = np.array(a)
print('----Matran A: ----\n' + str(a) + '\n')
L = cholesky_decomposition(arr)
if check == True:
    print('----Ma tran A sau khi phan ra cholesky: ----\n' + str(L) + '\n')
    LL = np.dot(L, np.transpose(L))
    print('----Ma tran chuyen vi L: ----\n' + str(LL) + '\n')
