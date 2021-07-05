import random as rd
from math import log

def particion(A, p, r):
    contador = 0
    i = (p-1)         
    pivot = A[r]   
  
    for j in range(p, r):
        if A[j] <= pivot:
            contador +=5
            i = i+1
            A[i], A[j] = A[j], A[i]
  
    A[i+1], A[r] = A[r], A[i+1]
    return ((i+1), contador)


def quickSort(A, p, r):
    contador = 0
    if len(A) == 1:
        return A
    if p < r:
        particion_ = particion(A, p, r)
        pi = particion_[0]
        contador += particion_[1]
        quickSort(A, p, pi-1)
        quickSort(A, pi+1, r)
    return contador 


def Generador(n):
    A = []
    for k in range(n):
        A.append(rd.randint(-20*n, 20*n))
    return A

lista = [2**k for k in range(8, 21)]

for n in lista:
    contador = 0
    for k in range(200):
        A  = Generador(n)
        contador += quickSort(A, 0, n-1)
    print("n:        ", n)
    print("Promedio: ", contador/200)
    print("n*log(n):  ", round(n*log(n), 3))
    print()
