def matrixUnit(n):
    return [[1 if i == j else 0 for j in range(n)] for i in range(n)]

# Retorna a+b
def matrixAdd(a, b):
    return [[a[i][j] + b[i][j] for i in range(len(a[0]))] for j in range(len(a))]

# Retorna a*b
def matrixMul(a, b):
    n = len(a)
    m = len(a[0])
    k = len(b[0])
    
    res = [[0 for j in range(k)] for i in range(n)]

    for i in range(n):
        for j in range(k):
            for p in range(m):
               res[i][j] = res[i][j] + a[i][p] * b[p][j]

    return res

# Retorna a matriz a^p
def matrixPow(a, p):
    if (p == 0):
        return matrixUnit(len(a))

    if (p % 2 == 1):
        return matrixMul(a, matrixPow(a, p - 1))

    return matrixPow(matrixMul(a, a), p >> 1)

# Retorna sum^p_i=0 (a^i)
def matrixPowSum(a, p):
    n = len(a)

    if (p == 0):
        return [[0 for j in range(n)] for i in range(n)]

    if (p % 2 == 0):
        return matrixMul(matrixPowSum(a, p >> 1), matrixAdd(matrixUnit(n),  matrixPow(a, p >> 1)))

    return matrixAdd(a, matrixMul(matrixPowSum(a, p - 1), a))

def main():
    x, mf = map(int, input().split(' '))

    while x != 0 and mf != 0:
        matriz = [[0 for x in range(2)] for y in range(2)]

        matriz[0][0] = 1
        matriz[0][1] = 1
        matriz[1][0] = 1
        matriz[1][1] = 0

        matriz = matrixPow(matriz, mf + 1)

        print(x * matriz[0][0])

        x, mf = map(int, input().split(' '))

main()