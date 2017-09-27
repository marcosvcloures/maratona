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
    
    ll busca(int s)
    {
        queue<Vertice> fila;
        bool visitados[n];
        
        ll resp = 0;

        fill(visitados, visitados+n, 0);
        fill(pais.begin(), pais.end(), -1);

        fila.push(Vertice(s, 0));

        auto top = fila.front();

        while (true)
        {
            if (!visitados[top.id])
            {
				resp ++;
				
                for (auto &it : g[top.id])
                    if (!visitados[it.id])
                        fila.push(Vertice(it.id, it.dist + 1, top.id));

                visitados[top.id] = 1;
                pais[top.id] = top.pai;
            }

            fila.pop();

            if (fila.empty())
                return resp;

            top = fila.front();
        }
    }
};

int main()
{
	int n, m, a, b, c;
	
	while(scanf("%d %d", &n, &m) && (n || m)) {
		Grafo g(n);

		while(m--) {
			scanf("%d %d %d", &a, &b, &c);
			
			a--, b--;
			
			g.addAresta(a, b);
			
			if(c == 2)
				g.addAresta(b, a);
		}

		int resp = 1;
		
		for(int i = 0; i < n; i++) {
			resp = g.busca(i) == n;
			
			if(!resp)
				break;
		}
		
		printf("%d\n", resp);
	}
}
