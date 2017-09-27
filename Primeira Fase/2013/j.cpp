#include <bits/stdc++.h>

#define ll long long
#define pb push_back

#define D(x) //cout << #x << " = " << x << endl;

using namespace std;

typedef vector<long long> vi;

const int maxn = 200000;
int Rank[maxn], p[maxn], n;

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

vi dist;

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
    
    ll valAresta(int a, int b)
    {
        for (auto it : g[a])
            if (it.id == b)
                return it.dist;

        return 0;
    }
    
    void def_raiz(int s) 
    {
		queue<Vertice> fila;
        bool visitados[n];

		fill(visitados, visitados + n, 0);
		
        fill(pais.begin(), pais.end(), -1);

        fila.push(Vertice(s, 1));

        auto top = fila.front();

        while (true)
        {
            if (!visitados[top.id])
            {
				Rank[top.id] = top.dist;
				
                for (auto &it : g[top.id])
                    if (!visitados[it.id])
                        fila.push(Vertice(it.id, top.dist + 1, top.id));

                visitados[top.id] = 1;
                
                pais[top.id] = top.pai;
            }

            fila.pop();

            if (fila.empty())
                return;

            top = fila.front();
        }
	}
    
    ll busca(int ss, int dd)
    {
		int s = ss, d = dd;
		int rank_s = Rank[ss], rank_d = Rank[dd];
		ll resp = 1<<29;
		
		D(rank_s);
		D(rank_d);
		
		while(rank_s != rank_d) {
			if(rank_s > rank_d) {
				resp = min(resp, valAresta(s, pais[s]));
				s = pais[s];
				rank_s--;
			}
			else {
				resp = min(resp, valAresta(d, pais[d]));
				d = pais[d];
				rank_d--;
			}
		}
		
		while(s != d) {
			D(s);
			D(pais[s]);
			D(d);
			D(pais[d]);
			if(pais[s] != -1) {
				resp = min(resp, valAresta(s, pais[s]));
				s = pais[s];
			}
			if(pais[d] != -1) {
				resp = min(resp, valAresta(d, pais[d]));
				d = pais[d];
			}
		}
		
		return resp;
    }
};

struct aresta {
	int a, b, p;
	
	aresta(int a, int b, int p) : a(a), b(b), p(p) { }
	
	aresta() { }
	
	bool operator <(const aresta &a) const {
		return a.p < p;
	}
};

void init(int _n) {
    n = _n;
    fill(Rank, Rank + n, 0);
    for (int i = 0; i < n; i++) p[i] = i;
}

int find(int x) {
    return x == p[x] ? x : (p[x] = find(p[x]));
}

bool unir(int a, int b) {
    a = find(a);
    b = find(b);
    
    if (a == b) return false;
    
    if (Rank[a] < Rank[b]) swap(a, b);
    if (Rank[a] == Rank[b]) ++Rank[a];
    p[b] = a;
    
    return true;
}

int main() {
	int n, m, s, a ,b, p, i;
	
	while(scanf("%d %d %d", &n, &m, &s) > 0) {
		vector<aresta> arestas;
		
		dist = vi(n, -1);
		
		init(n);
		
		Grafo g(n+100);
		
		for(i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &p);
			arestas.pb(aresta(a-1, b-1, p));
		}
		
		sort(arestas.begin(), arestas.end());
		
		for(auto &it : arestas)
			if(unir(it.a, it.b)) {
				g.addAresta(it.a, it.b, it.p);
				g.addAresta(it.b, it.a, it.p);
			}
			
		int raiz = 0;
		
		for(i = 0; i < n; i++) {
			D(Rank[i]);
			D(find(i));
			if(Rank[i] > Rank[raiz])
				raiz = i;
			}
				
		g.def_raiz(raiz);
			
		while(s--) {
			scanf("%d %d", &a, &b);
			
			printf("%lld\n", g.busca(a-1, b-1));
		}
	}
}
