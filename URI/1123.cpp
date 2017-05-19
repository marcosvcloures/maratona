#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>

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
	int n;
	
	tGrafo(int a) {
		Grafo = new vector<tVertice>[a];
		n = a;
	}
	
	~tGrafo() {
		delete[] Grafo;
	}

	long long int dijkstra(int inicio, int fim) {
		priority_queue<tVertice> fila;
		bool visitados[n];
		int i;
		
		for(i = 0; i < n; i++)
			visitados[i] = 0;
		
		fila.push(tVertice(inicio, 0));
		
		while(fila.top().id != fim && !fila.empty()) {
			if(!visitados[fila.top().id])
				for(i = 0; i < Grafo[fila.top().id].size(); i++) {
					if(!visitados[Grafo[fila.top().id][i].id])
						fila.push(tVertice(Grafo[fila.top().id][i].id, fila.top().dist + Grafo[fila.top().id][i].dist));
				}
			visitados[fila.top().id] = 1;
			fila.pop();
		}
		
		if(fila.empty())
			return -1;
		
		return fila.top().dist;
	}
	
	long long int largura(int inicio, int fim) {
		stack<tVertice> pilha;
		bool visitados[n];
		int i;
		
		for(i = 0; i < n; i++)
			visitados[i] = 0;
		
		pilha.push(tVertice(inicio, 0));
		
		while(pilha.top().id != fim && !pilha.empty()) {
			for(i = 0; i < Grafo[pilha.top().id].size(); i++) {
				if(!visitados[Grafo[pilha.top().id][i].id])
					pilha.push(tVertice(Grafo[pilha.top().id][i].id, pilha.top().dist + 1));
			}
			visitados[pilha.top().id] = 1;
			pilha.pop();
		}
		
		if(pilha.empty())
			return -1;
		
		return pilha.top().dist;
	}

	void addAresta(int a, int b, long long int v) {
		Grafo[a].push_back(tVertice(b, v));
	}
	
	void removeAresta(int a, int b) {
		for(int i = 0; i < Grafo[a].size(); i++)
			if(Grafo[a][i].id == b) {
				Grafo[a].erase(Grafo[a].begin() + i);
				return;
			}
	}

	bool existeAresta(int a, int b) {
		for(int i = 0; i < Grafo[a].size(); i++)
			if(Grafo[a][i].id == b)
				return true;
		return false;
	}
};

int main() {
	int n, m, c, k, i, j, a, b, v;
	
	scanf("%d %d %d %d", &n, &m, &c, &k);
	
	while(n != 0) {
		tGrafo g(n);
		
		for(i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &v);
			
			g.addAresta(a, b, v);
			g.addAresta(b, a, v);
		}
		
		for(i = 0; i < c; i++) {
			for(j = 0; j < g.Grafo[i].size(); j++) {
				if(g.Grafo[i][j].id != i+1)
					g.Grafo[i][j].dist = 10000000;
			}
		}
		
		printf("%d\n", g.dijkstra(k, c-1));	
		
		scanf("%d %d %d %d", &n, &m, &c, &k);
	}

	return 0;
}