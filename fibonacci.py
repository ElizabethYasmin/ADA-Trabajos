
def fibonacci(n):
    a = 1
    b = 1

    for k in range(2, n+1):
        aux = b
        b = a+b
        a = aux
    return a


n =int( input("Limite ->"))
for k in range(1, n+1):
    print("fibonacci[", k , "] ->", fibonacci(k), "\n")
input()
