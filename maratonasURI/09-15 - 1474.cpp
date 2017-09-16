#include <bits/stdc++.h>

#define ll long long
#define pb push_back

#define D(x) cout << #x << " = " << x << endl;

using namespace std;

typedef vector<long long> vi;
typedef vector<vi> vvi;
const int mod = 1000000;

// Retorna a matriz I_n
vvi matrixUnit(int n) {
    vvi res(n, vi(n));
    for (int i = 0; i < n; i++)
        res[i][i] = 1;
    return res;
}

// Retorna a+b
vvi matrixAdd(const vvi &a, const vvi &b) {
    int n = a.size();
    int m = a[0].size();
    vvi res(n, vi(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res[i][j] = (a[i][j] + b[i][j]) % mod;
    return res;
}

// Retorna a*b
vvi matrixMul(const vvi &a, const vvi &b) {
    int n = a.size();
    int m = a[0].size();
    int k = b[0].size();
    vvi res(n, vi(k));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            for (int p = 0; p < m; p++)
               res[i][j] = (res[i][j] + (long long) (a[i][p] % mod) * (b[p][j] % mod)) % mod;
    return res;
}

// Retorna a matriz a^p
vvi matrixPow(const vvi &a, long long p) {
    if (p == 0)
        return matrixUnit(a.size());
    if (p & 1)
        return matrixMul(a, matrixPow(a, p - 1));
    return matrixPow(matrixMul(a, a), p / 2);
}

// Retorna ?_(i=1)^p¦?a^i  ?  
vvi matrixPowSum(const vvi &a, long long p) {
    long long n = a.size();
    if (p == 0)
        return vvi(n, vi(n));
    if (p % 2 == 0)
        return matrixMul(matrixPowSum(a, p / 2), matrixAdd(matrixUnit(n),  matrixPow(a, p / 2)));
    return matrixAdd(a, matrixMul(matrixPowSum(a, p - 1), a));
}

int main() {
	long long n, l, k, i;
	
	while(scanf("%lld %lld %lld", &n, &l, &k) > 0) {
		vvi matriz = vvi(2, vi(2));
		
		matriz[0][0] = l;
		matriz[0][1] = k;
		matriz[1][0] = 1;
		matriz[1][1] = 0;
		
		matriz = matrixPow(matriz, n / 5);
		
		printf("%06lld\n", matriz[0][0]);
	}
}
