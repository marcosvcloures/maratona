bool isomorfismo(Grafo &grafo)
{
    if (this->n != grafo.n)
        return false;

    map<multiset<int>, int> mapa;
    vi valores_esq(n), valores_dir(n), pais_esq(n, -1), pais_dir(n, -1);
    set<int> centros_esq, centros_dir;
    int atual = 0, count = 0, i;

    for (i = 0; i < n; i++)
        centros_esq.insert(i), centros_dir.insert(i);

    while (centros_esq.size() > 2)
    {
        vi a_remover;

        for (auto &linha : centros_esq)
        {
            int count = 0, pai;

            for (auto &it : this->g[linha])
                if (centros_esq.count(it.id))
                    count++, pai = it.id;

            if (count == 1)
            {
                pais_esq[linha] = pai;
                a_remover.pb(linha);
            }
        }

        for (auto &it : a_remover)
        {
            multiset<int> valores;

            for (auto &it2 : this->g[it])
                if (pais_esq[it2.id] == it)
                    valores.insert(valores_esq[it2.id]);

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

        for (auto &it2 : this->g[it])
            if (pais_esq[it2.id] == it)
                valores.insert(valores_esq[it2.id]);

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

            for (auto &it : grafo.g[linha])
                if (centros_dir.count(it.id))
                    count++, pai = it.id;

            if (count == 1)
            {
                pais_dir[linha] = pai;
                a_remover.pb(linha);
            }
        }

        for (auto &it : a_remover)
        {
            multiset<int> valores;

            for (auto &it2 : grafo.g[it])
                if (pais_dir[it2.id] == it)
                    valores.insert(valores_dir[it2.id]);

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

        for (auto &it2 : grafo.g[it])
            if (pais_dir[it2.id] == it)
                valores.insert(valores_dir[it2.id]);

        if (mapa.count(valores))
            valores_dir[it] = mapa[valores];
        else
            valores_dir[it] = mapa[valores] = atual++;
    }

    sort(valores_dir.begin(), valores_dir.end());
    sort(valores_esq.begin(), valores_esq.end());

    for (i = 0; i < valores_dir.size(); i++)
        if (valores_esq[i] != valores_dir[i])
            return false;

    return true;
}

int main()
{
    int n, a, i, j, resp = 0;

    scanf("%*d");

    vector<Grafo> arvores;

    while (scanf("%d", &n) > 0)
    {
        Grafo g(n);

        for (int i = 1; i < n; i++)
            scanf("%d", &a),
                  g.addAresta(i, a - 1),
                  g.addAresta(a - 1, i);

        arvores.push_back(g);
    }

    for(i = 0; i < arvores.size(); i++)
    {
        for(j = i + 1; j < arvores.size(); j++)
        {
            if(arvores[i].isomorfismo(arvores[j]))
                break;
        }

        if(j == arvores.size())
            resp++;
    }

    printf("%d\n", resp);
}