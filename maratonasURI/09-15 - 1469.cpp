#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

typedef vector<int> vi;

struct Vertice
{
    int id, pai;
    int dist;

    Vertice(int id, int dist = 1, int pai = -1) : id(id), dist(dist), pai(pai) {}

    bool operator<(Vertice a) const
    {
        return a.dist < dist;
    }
};

typedef vector<Vertice> vv;
typedef vector<vv> vvv;

struct Grafo
{
	vi idades;
    vvv g;
    vi pais;
    int n;

    Grafo(int n) : n(n)
    {
        g = vvv(n, vv());
        pais = vi(n);
        idades = vi(n);
    }

    void operator=(Grafo const &a)
    {
        g = a.g;
        pais = a.pais;
        n = a.n;
    }

    void addAresta(int a, int b, int d = 0)
    {
        g[a].pb(Vertice(b, d));
    }


    int busca(int s)
    {
		int melhor = 1 << 29;
        queue<Vertice> fila;
        bool visitados[n];
        
        fill(visitados, visitados + n, 0);

        fill(pais.begin(), pais.end(), -1);

        fila.push(Vertice(s, 0));

        auto top = fila.front();
	int primeiro = 1;
        while (!fila.empty())
        {
			if(!primeiro)
			melhor = min(melhor, idades[top.id]);
			else
			primeiro = 0;
            if (!visitados[top.id])
            {
                for (auto &it : g[top.id])
                    if (!visitados[it.id])
                        fila.push(Vertice(it.id, it.dist + 1, top.id));

                visitados[top.id] = 1;
            }

            fila.pop();

            if (fila.empty())
                return melhor;

            top = fila.front();
        }
    }
};

int main()
{
	char c;
	int n, m, I, a, b;
	int val[591];
	while(cin >> n >> m >> I > 0) {
	
    Grafo g(n+1);
    
    for(int i=0; i<n; i++) {
		scanf("%d", &a);
		g.idades[i + 1] = a;
		val[i + 1] = i + 1;
	}
	
	for(int i=0; i<m; i++) {
		scanf(" %d %d", &a, &b);
		g.addAresta(b, a, 1);
	}
	
	for(int i=0; i<I; i++) {
		scanf(" %c", &c);
		if(c == 'P') {
			scanf("%d", &a);
			if(g.g[val[a]].size() == 0)
				puts("*");
			else
				cout << g.busca(val[a]) << endl;
		}
		else {
			scanf("%d%d", &a, &b);
			
			swap(g.idades[val[a]], g.idades[val[b]]);
			
			swap(val[a], val[b]);
		}
	}
}
}
