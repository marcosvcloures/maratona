#include<bits/stdc++.h>

using namespace std;

typedef vector<long long> vi;
typedef vector<vi> vvi;
const long long mod = 1000000007;

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
               res[i][j] = (res[i][j] + a[i][p] * b[p][j]) % mod;
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

int main() {
	long long t;
	
	vvi a(2, vi(2));
	
	a[0][0] = 5;
	a[0][1] = -2;
	a[1][0] = 1; 
	a[1][1] = 0;
	
	scanf("%lld", &t);
	
	a = matrixPow(a, t - 1);
	
	printf("%lld\n", ((12 * a[0][0] + (3 * a[0][1])) % 1000000007 + 1000000007) % 1000000007);
	//printf("%lld\n", tb[t-1]);
	
	return 0;
}