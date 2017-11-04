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
        map<multiset<int>, int> mapa;
        vvi grafo_esq(n), grafo_dir(n);
        vi valores_esq(n), valores_dir(n), pais_esq(n, -1), pais_dir(n, -1);
        set<int> centros_esq, centros_dir;

        for (i = 0; i < n - 1; i++)
            scanf("%d %d", &a, &b), grafo_esq[a - 1].pb(b - 1), grafo_esq[b - 1].pb(a - 1),
                  centros_esq.insert(i);
        centros_esq.insert(i);

        for (i = 0; i < n - 1; i++)
            scanf("%d %d", &a, &b), grafo_dir[a - 1].pb(b - 1), grafo_dir[b - 1].pb(a - 1),
                  centros_dir.insert(i);
        centros_dir.insert(i);

        atual = count = 0;

        while (centros_esq.size() > 2)
        {
            vi a_remover;

            for (auto &linha : centros_esq)
            {
                int count = 0, pai;

                for (auto &it : grafo_esq[linha])
                    if (centros_esq.count(it))
                        count++, pai = it;

                if (count == 1)
                {
                    pais_esq[linha] = pai;
                    a_remover.pb(linha);
                }
            }

            for (auto &it : a_remover)
            {
                multiset<int> valores;

                for (auto &it2 : grafo_esq[it])
                    if (pais_esq[it2] == it)
                        valores.insert(valores_esq[it2]);

                if (mapa.count(valores))
                    valores_esq[it] = mapa[valores];
                else
                    valores_esq[it] = mapa[valores] = atual++;

                centros_esq.erase(it);
            }
        }

        for (auto &it : centros_esq)
        {
            multiset<int> valores;

            for (auto &it2 : grafo_esq[it])
                if (pais_esq[it2] == it)
                    valores.insert(valores_esq[it2]);

            if (mapa.count(valores))
                valores_esq[it] = mapa[valores];
            else
                valores_esq[it] = mapa[valores] = atual++;
        }

        while (centros_dir.size() > 2)
        {
            vi a_remover;

            for (auto &linha : centros_dir)
            {
                int count = 0, pai;

                for (auto &it : grafo_dir[linha])
                    if (centros_dir.count(it))
                        count++, pai = it;

                if (count == 1)
                {
                    pais_dir[linha] = pai;
                    a_remover.pb(linha);
                }
            }

            for (auto &it : a_remover)
            {
                multiset<int> valores;

                for (auto &it2 : grafo_dir[it])
                    if (pais_dir[it2] == it)
                        valores.insert(valores_dir[it2]);

                if (mapa.count(valores))
                    valores_dir[it] = mapa[valores];
                else
                    valores_dir[it] = mapa[valores] = atual++;

                centros_dir.erase(it);
            }
        }

        for (auto &it : centros_dir)
        {
            multiset<int> valores;

            for (auto &it2 : grafo_dir[it])
                if (pais_dir[it2] == it)
                    valores.insert(valores_dir[it2]);

            if (mapa.count(valores))
                valores_dir[it] = mapa[valores];
            else
                valores_dir[it] = mapa[valores] = atual++;
        }

        sort(valores_dir.begin(), valores_dir.end());
        sort(valores_esq.begin(), valores_esq.end());

        for(i = 0; i < valores_dir.size(); i++)
            if(valores_esq[i] != valores_dir[i])
            {
                puts("N");
                goto proximo;
            }

        puts("S");

proximo:
        ;
    }
}
