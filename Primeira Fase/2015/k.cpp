#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

char palavra[10000];
vvi pd;
vi marcado;

int conta(int i, int j) {
    if(i > j)
        return 0;

    if(i == j)
        return 1 + 10000 * marcado[i];

    if(pd[i][j] != -1)
        return pd[i][j];

    int resp = 0;
    
    if(palavra[i] == palavra[j]) 
        resp = 2 + 10000 * (marcado[i] + marcado[j]) + conta(i + 1, j - 1);
    
    return pd[i][j] = max(resp, max(conta(i + 1, j), conta(i, j - 1)));
}

int main() {
    int n, k, e;

    scanf(" %s", palavra);

    n = strlen(palavra);

    marcado = vi(n, 0);
    pd = vvi(n, vi(n, -1));

    scanf("%d", &k);

    while(k--)
        scanf("%d", &e), marcado[e-1] = 1;

    printf("%d\n", conta(0, n-1) % 10000);
}