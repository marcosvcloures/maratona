#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

typedef vector<int> vi;

struct Vertice
{
    int id, pai;
    ll dist;

    Vertice(int id, ll dist = 1, int pai = -1) : id(id), dist(dist), pai(pai) {}

    bool operator<(Vertice a) const
    {
        return a.dist < dist;
    }
};

typedef vector<Vertice> vv;
typedef vector<vv> vvv;

struct Grafo
{
    vvv g;
    vi pais;
    int n;

    Grafo(int n) : n(n)
    {
        g = vvv(n, vv());
        pais = vi(n);
    }

    void operator=(Grafo const &a)
    {
        g = a.g;
        pais = a.pais;
        n = a.n;
    }

    void addAresta(int a, int b, ll d = 0)
    {
        g[a].pb(Vertice(b, d));
    }

    void removeAresta(int a, int b)
    {
        g[a].erase(remove_if(g[a].begin(), g[a].end(), [b](Vertice v) { return v.id == b; }));
    }

    ll valAresta(int a, int b)
    {
        for (auto it : g[a])
            if (it.id == b)
                return it.dist;

        return 0;
    }

    void modificaAresta(int a, int b, ll dif)
    {
        for (auto &it : g[a])
            if (it.id == b)
            {
                it.dist += dif;
                break;
            }

        g[a].erase(remove_if(g[a].begin(), g[a].end(), [b](Vertice v) { return v.dist == 0; }));
    }

    ll dijkstra(int s, int d)
    {
        priority_queue<Vertice> fila;
        bool visitados[n];

        fill(visitados, visitados + n, 0);
        fill(pais.begin(), pais.end(), -1);

        fila.push(Vertice(s, 0));

        auto top = fila.top();

        while (top.id != d)
        {
            if (!visitados[top.id])
            {
                for (auto &it : g[top.id])
                    if (!visitados[it.id])
                        fila.push(Vertice(it.id, it.dist + top.dist, top.id));

                visitados[top.id] = 1;
                pais[top.id] = top.pai;
            }

            fila.pop();

            if (fila.empty())
                return -1;

            top = fila.top();
        }

        pais[top.id] = top.pai;

        return top.dist;
    }

    ll busca(int s, int d)
    {
        queue<Vertice> fila;
        bool visitados[n];

        fill(visitados, visitados + n, 0);
        fill(pais.begin(), pais.end(), -1);

        fila.push(Vertice(s, 0));

        auto top = fila.front();

        while (top.id != d)
        {
            if (!visitados[top.id])
            {
                for (auto &it : g[top.id])
                    if (!visitados[it.id])
                        fila.push(Vertice(it.id, it.dist + 1, top.id));

                visitados[top.id] = 1;
                pais[top.id] = top.pai;
            }

            fila.pop();

            if (fila.empty())
                return -1;

            top = fila.front();
        }

        pais[top.id] = top.pai;

        return top.dist;
    }

    ll fluxo_maximo(int s, int d)
    {
        int u, v;
        ll flow = 0;

        Grafo g2 = *this;

        while (g2.busca(s, d) >= 0)
        {
            ll path = 1ll << 50;

            for (v = d; v != s; v = u)
            {
                u = g2.pais[v];
                path = min(path, valAresta(u, v));
            }

            for (v = d; v != s; v = u)
            {
                u = g2.pais[v];
                g2.modificaAresta(u, v, -path);
                g2.modificaAresta(v, u, path);
            }

            flow += path;
        }

        return flow;
    }

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
};

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

    for(i = 0; i < arvores.size(); i++) {
        for(j = i + 1; j < arvores.size(); j++) {
            if(arvores[i].isomorfismo(arvores[j]))
                break;
        }
        
        if(j == arvores.size())
            resp++;
    }

    printf("%d\n", resp);
}