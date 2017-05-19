#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, v[1000], i, sum, maximo;

    scanf("%d", &t);

    while (t--)
    {
        sum = maximo = 0;
        scanf("%d", &n);

        for (i = 0; i < n; i++)
            scanf("%d", &v[i]);

        sort(v, v + n);

        for (i = 0; i < n; i++)
            maximo = max(maximo, (n-i) * v[i]);

        printf("%d\n", maximo);
    }
}