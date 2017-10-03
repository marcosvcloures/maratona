#include <bits/stdc++.h>

#define pb push_back

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
    int n, i, a, b, count, atual;

    while (scanf("%d", &n) > 0)
    {
        vector<map<multiset<int>, int>> mapas(n);
        vector<vvi> grafos(n);
        vvi valores(n), pais(n);
        vector<set<int>> centros(n);

        for (i = 0; i < n; i++)
        {
            scanf("%d", &m);

            grafos[i] = vvi(m);
            valores[i] = vi(m);
            pais[i] = vi(m);

            while (--m)
                scanf("%d %d", &a, &b), grafo[i][a - 1].pb(b - 1), grafo[i][b - 1].pb(a - 1),
                    centros[i].insert(i);
            centros[i].insert(i);
        }

        for (i = 0; i < n; i++)
        {
            atual = count = 0;

            while (centros[i].size() > 2)
            {
                vi a_remover;

                for (auto &linha : centros[i])
                {
                    int count = 0, pai;

                    for (auto &it : grafo[i][linha])
                        if (centros[i].count(it))
                            count++, pai = it;

                    if (count == 1)
                    {
                        pais[i][linha] = pai;
                        a_remover.pb(linha);
                    }
                }

                for (auto &it : a_remover)
                {
                    multiset<int> valores;

                    for (auto &it2 : grafo[i][it])
                        if (pais[i][it2] == it)
                            valores.insert(valores[i][it2]);

                    if (mapa.count(valores))
                        valores[i][it] = mapa[valores];
                    else
                        valores[i][it] = mapa[valores] = atual++;

                    centros[i].erase(it);
                }
            }

            for (auto &it : centros[i])
            {
                multiset<int> valores;

                for (auto &it2 : grafo[i][it])
                    if (pais[i][it2] == it)
                        valores.insert(valores[i][it2]);

                if (mapa.count(valores))
                    valores[i][it] = mapa[valores];
                else
                    valores[i][it] = mapa[valores] = atual++;
            }
        }

        vi marcadas(n, 0);
        int resp = 0;
        for (i = 0; i < n; i++)
        {
            vi valor;

            if (marcada[i])
                continue;

            for (int j = i + 1; j < n; j++)
            {
                if (marcada[j])
                    continue;

                if (grafos[i].size() != grafos[j].size())
                    continue;

                set<int> centro;

                for (int k = 0; k < grafos[i].size(); k++)
                    centro.insert(k);

                atual = count = 0;

                while (centro.size() > 2)
                {
                    vi a_remover;

                    for (auto &linha : centro)
                    {
                        int count = 0, pai;

                        for (auto &it : grafo[i][linha])
                            if (centro.count(it))
                                count++, pai = it;

                        if (count == 1)
                        {
                            paes[linha] = pai;
                            a_remover.pb(linha);
                        }
                    }

                    for (auto &it : a_remover)
                    {
                        multiset<int> valores;

                        for (auto &it2 : grafo[i][it])
                            if (paes[it2] == it)
                                valores.insert(valores[i][it2]);

                        if (mapa.count(valores))
                            valores[i][it] = mapa[valores];
                        else
                            valores[i][it] = mapa[valores] = atual++;

                        centros[i].erase(it);
                    }
                }

                for (auto &it : centros[i])
                {
                    multiset<int> valores;

                    for (auto &it2 : grafo[i][it])
                        if (pais[i][it2] == it)
                            valores.insert(valores[i][it2]);

                    if (mapa.count(valores))
                        valores[i][it] = mapa[valores];
                    else
                        valores[i][it] = mapa[valores] = atual++;
                }
            }
        }
        sort(valores_dir.begin(), valores_dir.end());
        sort(valores_esq.begin(), valores_esq.end());

        for (i = 0; i < valores_dir.size(); i++)
            if (valores_esq[i] != valores_dir[i])
            {
                puts("N");
                goto proximo;
            }

        puts("S");

    proximo:;
    }
}