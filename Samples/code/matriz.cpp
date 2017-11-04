#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef vector<ll> vl;
typedef vector<vl> vvl;
const int mod = 1000000;

// Retorna a matriz I_n
vvl matrixUnit(int n)
{
    vvl res(n, vl(n));
    for (int i = 0; i < n; i++)
        res[i][i] = 1;
    return res;
}

// Retorna a+b
vvl matrixAdd(const vvl &a, const vvl &b)
{
    int n = a.size();
    int m = a[0].size();
    vvl res(n, vl(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res[i][j] = (a[i][j] + b[i][j]) % mod;
    return res;
}

// Retorna a*b
vvl matrixMul(const vvl &a, const vvl &b)
{
    int n = a.size();
    int m = a[0].size();
    int k = b[0].size();
    vvl res(n, vl(k));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            for (int p = 0; p < m; p++)
                res[i][j] = (res[i][j] + ((a[i][p] % mod) * (b[p][j] % mod) % mod)) % mod;
    return res;
}

// Retorna a matriz a^p
vvl matrixPow(const vvl &a, long long p)
{
    if (p == 0)
        return matrixUnit(a.size());
    if (p & 1)
        return matrixMul(a, matrixPow(a, p - 1));
    return matrixPow(matrixMul(a, a), p / 2);
}

// Retorna sum^p_i=0 (a^i)
vvl matrixPowSum(const vvl &a, long long p)
{
    long long n = a.size();
    if (p == 0)
        return vvl(n, vl(n));
    if (p % 2 == 0)
        return matrixMul(matrixPowSum(a, p / 2), matrixAdd(matrixUnit(n),  matrixPow(a, p / 2)));
    return matrixAdd(a, matrixMul(matrixPowSum(a, p - 1), a));
}

int main()
{
    long long n, l, k, i;

    while(scanf("%lld %lld %lld", &n, &l, &k) > 0)
    {
        vvl matriz = vvl(2, vl(2));

        matriz[0][0] = l;
        matriz[0][1] = k;
        matriz[1][0] = 1;
        matriz[1][1] = 0;

        matriz = matrixPow(matriz, n / 5);

        printf("%06lld\n", matriz[0][0]);
    }
}
