import random as rd
import numpy as np
from math import log

def MAX(A):
	contador = 0
	mmax = A[0]
	for i in range(l, len(A)):
		if A[i] > mmax:
			mmax = A[i]
			contador += 1
	return contador


def Generar(n):
	A = [0]*n
	for i in range(n):
		A[i] = rd.randint(-n, n)
	return A


def main():
    for i in [256,512,1024,2048,5096,10192]:
        contador = 0
        for j in range(200):
            X  = Generar(i)
            contador += MAX(X)
        print(i,"",contador/200,"",log(i))
	
main()


