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

    void addAresta(int a, int b, ll d = 0)
    {
        g[a].pb(Vertice(b, d));
    }

    ll dijkstra(int s, int d)
    {
        priority_queue<Vertice> fila;
        bool visitados[n];

        fill(visitados, visitados + n, 0);
        fill(pais.begin(), pais.end(), -1);

        fila.push(Vertice(s, 0, -1));

        auto top = fila.top();

        while (top.id != d)
        {
            if (!visitados[top.id])
            {
                for (auto &filho : g[top.id])
                    for (auto &it : g[filho.id])
                        if (!visitados[it.id])
                            fila.push(Vertice(it.id, it.dist + top.dist + filho.dist, top.id));

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
};

int main()
{
    int c, v, aux1, aux2, aux3;

    scanf("%d %d", &c, &v);

    Grafo g(c + 1);

    for (int i = 0; i < v; i++)
    {
        scanf("%d %d %d", &aux1, &aux2, &aux3);
        g.addAresta(aux1, aux2, aux3);
        g.addAresta(aux2, aux1, aux3);
    }

    printf("%lld\n", g.dijkstra(1, c));
}
