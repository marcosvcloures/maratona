#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct tVertice {
	int id;
	long long int dist;
	
	tVertice(int a, long long int b) {
		id = a;
		dist = b;
	}
	
	bool operator<(tVertice a) const {
		return a.dist < dist;
	}
};

struct tGrafo {
	vector<tVertice> *Grafo;
	int *dists;
	int n;
	
	tGrafo(int a) {
		Grafo = new vector<tVertice>[a];
		dists = new int[a];
		n = a;
	}
	
	~tGrafo() {
		delete[] Grafo;
		delete[] dists;
	}

	long long int dijkstra(int inicio, int fim) {
		priority_queue<tVertice> fila;
		bool visitados[n];
		int i;
		
		for(i = 0; i < n; i++)
			visitados[i] = 0;
		
		fila.push(tVertice(inicio, 0));
		
		while(!fila.empty()) {
			if(!visitados[fila.top().id]) {
				for(i = 0; i < Grafo[fila.top().id].size(); i++) {
					if(!visitados[Grafo[fila.top().id][i].id])
						fila.push(tVertice(Grafo[fila.top().id][i].id, fila.top().dist + Grafo[fila.top().id][i].dist));
				}
				dists[fila.top().id] = fila.top().dist;
			}
			visitados[fila.top().id] = 1;
			fila.pop();
		}
		
		if(fila.empty())
			return -1;
		
		return fila.top().dist;
	}

	void addAresta(int a, int b, long long int v) {
		Grafo[a].push_back(tVertice(b, v));
	}
};

int main() {
	vector<int> pais;
	queue<int> fila;
	bool marcados[10000] = {0};
	int n, a, b, v, o, d, i,  atual;
	
	scanf("%d %d %d", &n, &o, &d);
	
	tGrafo g(n);
	
	scanf("%d %d %d", &a, &b, &v);
	
	while(a) {
		a--;
		b--;
		
		g.addAresta(a, b, v);
		g.addAresta(b, a, v);
		
		scanf("%d %d %d", &a, &b, &v);
	}
	
	g.dijkstra(o-1, d-1);
	
	pais.push_back(d);
	
	fila.push(d-1);
	
	while(!fila.empty()) {
		atual = fila.front();
		marcados[atual] = 1;
		
		for(i = 0; i < g.Grafo[atual].size(); i++) {
			if(g.dists[atual] == g.dists[g.Grafo[atual][i].id] + g.Grafo[atual][i].dist) {
				if(!marcados[g.Grafo[atual][i].id]) {
					pais.push_back(g.Grafo[atual][i].id + 1);
					fila.push(g.Grafo[atual][i].id);
					marcados[g.Grafo[atual][i].id] = 1;
				}
			}
		}

		fila.pop();
	}
	
	sort(pais.begin(), pais.end());
	
	for(i = 0; i < pais.size(); i++)
		printf("%d\n", pais[i]);

	return 0;
}