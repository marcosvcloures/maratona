#include <bits/stdc++.h>

using namespace std;

#define D(x) cout << #x << " = " << x << endl
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi grafo;
vi pais, ranking, visitado;

int rankeia(int pai, int rank)
{
    visitado[pai] = 1;

    for (auto &it : grafo[pai])
    {
        if (!visitado[it])
        {
            pais[it] = pai;
            ranking[it] = rank + 1;

            rankeia(it, rank + 1);
        }
    }
}

int acha(int b, int c)
{
    int temp;

    temp = b;

    while (temp != pais[temp])
    {
        temp = pais[temp];

        if (temp == c)
            return 2;
    }

    temp = c;

    while (temp != pais[temp])
    {
        temp = pais[temp];

        if (temp == b)
            return 1;
    }
}

int achaAnciao(int b, int c)
{
    int rank_b = ranking[b], rank_c = ranking[c];

    while (rank_b != rank_c)
    {
        if (rank_b > rank_c)
        {
            rank_b--;
            b = pais[b];
        }
        else
        {
            rank_c--;
            c = pais[c];
        }
    }

    while (b != c)
    {
        b = pais[b];
        c = pais[c];
    }

    return b;
}

long long busca(int atual, int fim, long long prob)
{
    visitado[atual] = 1;

    if (atual == fim)
        return prob;

    long long resp = 0;

    for (auto &it : grafo[atual])
        if (!visitado[it])
            resp = max(resp, busca(it, fim, prob + 1));

    return resp;
}

int main()
{
    int n, a, b, c, x, y, aux, i;

    while (scanf("%d %d %d %d", &n, &a, &b, &c) > 0)
    {
        a--, b--, c--;

        grafo = vvi(n);
        pais = vi(n);
        ranking = vi(n);
        visitado = vi(n, 0);

        for (i = 0; i < n - 1; i++)
            scanf("%d %d", &x, &y),
                grafo[x - 1].pb(y - 1),
                grafo[y - 1].pb(x - 1);

        pais[a] = a;

        rankeia(a, 0);

        aux = acha(b, c);

        int anciao = achaAnciao(b, c);

        visitado = vi(n, 0);
        long long caminhos_b = busca(anciao, c, 0);

        visitado = vi(n, 0);
        long long caminhos_c = busca(b, c, 0);

        printf("%.6lf\n", caminhos_b * 1.0 / caminhos_c);
    }
}
