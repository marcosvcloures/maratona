#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vvii grafo;
vi desejados, bifurcacao;

int marcaBifurcacoes(int atual)
{
    for (auto &it : grafo[atual])
        desejados[atual] += marcaBifurcacoes(it.first);

    if (desejados[atual] > 1)
        bifurcacao[atual] = desejados[atual] = 1;

    return desejados[atual];
}

int dfs(int atual)
{
    if (bifurcacao[atual])
    {
        int resp_interna = 0;

        for (auto &it : grafo[atual])
            if (desejados[it.first])
                resp_interna += it.second + dfs(it.first);

        return resp_interna;
    }
    else
        for (auto &it : grafo[atual])
            if (desejados[it.first])
                return it.second + dfs(it.first);

    return 0;
}

int dfs2(int atual)
{
    if (bifurcacao[atual])
    {
        int resp = 0;

        for (auto &it : grafo[atual])
            if (desejados[it.first])
                resp = max(resp, it.second + dfs2(it.first));

        return resp;
    }
    else
        for (auto &it : grafo[atual])
            if (desejados[it.first])
                return it.second + dfs2(it.first);

    return 0;
}

int main()
{
    int n, m, i, a, b, c;

    while (scanf("%d %d", &n, &m) > 0)
    {
        grafo = vvii(n);

        for (i = 0; i < n - 1; i++)
        {
            scanf("%d %d %d", &a, &b, &c);

            grafo[a - 1].push_back({b - 1, c});
        }

        desejados = vi(n, 0);
        bifurcacao = vi(n, 0);

        for (i = 0; i < m; i++)
        {
            scanf("%d", &a);
            desejados[a - 1] = 1;
        }

        marcaBifurcacoes(0);

        dfs(0);

        dfs2(0);

        printf("%d\n", dfs(0) - dfs2(0));
    }
}
