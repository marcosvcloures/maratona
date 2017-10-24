#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vl;
typedef vector<vl> vvl;

vvl pd;
int k, tam;

vvl pascal(101, vl(101, 0));

long long conta(int n, int m)
{
    if (n == 0)
        return 0;

    if (m == 1)
        return n;
    if (n == 1 && m < k || m == 0)
        return 1;

    if (pd[n][m] != -1)
        return pd[n][m];

    long long resp = 0;

    for (int i = 0; i < min(k, m + 1); i++)
        resp = (resp + (conta(n - 1, m - i) * pascal[m][i]) % 1000000007) % 1000000007;

    return pd[n][m] = resp;
}

int main()
{
    int i, j;

    pascal[0][0] = 1;

    for (i = 0; i < 101; i++)
        pascal[i][0] = 1;

    for (i = 1; i < 101; i++)
        for (j = 1; j < 101; j++)
            pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % 1000000007;

    scanf("%d %d", &tam, &k);

    pd = vvl(tam + 1, vl(tam + 1, -1));

    printf("%d\n", conta(tam, tam - 2));
}