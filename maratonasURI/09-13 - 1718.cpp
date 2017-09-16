#include <bits/stdc++.h>

using namespace std;

int main()
{
    int c, n, corte, atual, i, lim, azeitonas[20000];

    scanf("%d %d", &c, &n);

    lim = c / n;

    for(i = 0; i < n; i++)
        scanf("%d", &azeitonas[i]);

    for(corte = 0; corte <= lim; corte++) {
        atual = azeitonas[0] - corte;

        for(i = 0; i < n; i++) {
            if(!(azeitonas[i] >= atual && azeitonas[i] < atual + lim))
                goto a;

            atual += lim;
        }

        puts("S");

        return 0;

        a:;
    }

    puts("N");
}
