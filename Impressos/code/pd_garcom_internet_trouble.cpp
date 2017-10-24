#include <bits/stdc++.h>

using namespace std;

long long custo[6010][6010], pd[6010][6010], valores[6100], acumulado[6100];
int k_opt[6010][6010] = {0}, b, n;

/*
	PD Original
	
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 0; k < i; k++)
                if (b + pd[k][j - 1] + custo[k + 1][i] < pd[i][j])
                {
                    pd[i][j] = b + pd[k][j - 1] + custo[k + 1][i];
                    k_opt[i][j] = k;
                }
*/

void resolve(int i, int j, int opt_l, int opt_r)
{
    k_opt[i][j] = opt_l;

    for (int k = opt_l; k <= opt_r; k++)
        if (b + pd[k][j - 1] + custo[k + 1][i] < pd[i][j])
        {
            pd[i][j] = b + pd[k][j - 1] + custo[k + 1][i];
            k_opt[i][j] = k;
        }
}

void calcula(int i, int l, int r, int opt_l, int opt_r)
{
    if (l > r)
        return;

    int m = (l + r) / 2;

    resolve(i, m, opt_l, opt_r);

    calcula(i, l, m - 1, opt_l, k_opt[i][m]);
    calcula(i, m + 1, r, k_opt[i][m], opt_r);
}

int main()
{
    int c;

    while (scanf("%d %d %d", &n, &b, &c) > 0)
    {
        for (int i = 0; i <= n; i++)
        {
            fill(pd[i], pd[i] + n + 1, 0ll);
            fill(custo[i], custo[i] + n + 1, 0ll);
        }

        for (int i = 0; i < n; i++)
            scanf("%lld", &valores[i]);

        acumulado[0] = 0;

        for (int i = 0; i < n; i++)
            acumulado[i + 1] = valores[i] + acumulado[i];

        for (int i = 0; i < n; i++)
        {
            pd[i][0] = valores[0] * i;
            pd[i][n - 1] = valores[n - 1] * (n - 1 - i);

            for (int j = 1; j < i; j++)
                pd[i][j] = pd[i][j - 1] + valores[j] * (i - j);
            for (int j = n - 2; j > i; j--)
                pd[i][j] = pd[i][j + 1] + valores[j] * (j - i);

            if (i < n - 1)
                pd[i][i] += pd[i][i + 1];
            if (i)
                pd[i][i] += pd[i][i - 1];
        }

        for (int i = 0; i < n; i++)
        {
            custo[i][i] = 0;

            for (int j = 0; j < i; j++)
            {
                auto val_mediana = (acumulado[i + 1] - acumulado[j]) / 2 + acumulado[j];

                auto mediana = distance(acumulado, upper_bound(acumulado, acumulado + n, val_mediana)) - 1;

                auto val = pd[mediana][mediana];

                if (i < n - 1)
                    val -= pd[mediana][i + 1];

                if (j)
                    val -= pd[mediana][j - 1];

                custo[i + 1][j + 1] = c * val;
            }

            for (int j = i + 1; j < n; j++)
            {
                auto val_mediana = (acumulado[j + 1] - acumulado[i]) / 2 + acumulado[i];

                auto mediana = distance(acumulado, upper_bound(acumulado, acumulado + n, val_mediana)) - 1;

                auto val = pd[mediana][mediana];

                if (j < n - 1)
                    val -= pd[mediana][j + 1];

                if (i)
                    val -= pd[mediana][i - 1];

                custo[i + 1][j + 1] = c * val;
            }
        }

        for (int i = 0; i <= n; i++)
            fill(pd[i], pd[i] + n + 1, 1ll << 60);

        pd[0][0] = 0;

        for (int i = 1; i <= n; i++)
            calcula(i, 1, i + 1, 0, i - 1);

        for (int j = 1; j <= n; j++)
            cout << pd[n][j] << " \n"[j == n];
    }
}