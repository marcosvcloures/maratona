#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
    int n, k, matriz[10000][50], linha, coluna, rank, i, j, e;

    scanf("%d %d", &n, &k);

    for (i = 0; i < n; i++)
        for (j = 0; j < k; j++)
            scanf("%d", &e), matriz[i][j] = e & 1;

    linha = coluna = rank = 0;

    while (linha < n && coluna < k)
    {
        for (i = linha; i < n; i++)
            if (matriz[i][coluna] == 1)
                break;

        if (i == n || matriz[i][coluna] == 0)
        {
            puts("S");

            return 0;
        }

        for (j = 0; j < k; j++)
            swap(matriz[linha][j], matriz[i][j]);

        for (i = 0; i < n; i++)
        {
            if (i == linha || matriz[i][coluna] == 0)
                continue;

            for (j = 0; j < k; j++)
                matriz[i][j] ^= matriz[linha][j];
        }

        linha++, coluna++;
    }

    if(linha >= k && n > linha) {
        puts("N");
        
        return 0;
    }
    
    puts("S");
}