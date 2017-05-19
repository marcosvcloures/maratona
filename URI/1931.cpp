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
	int n, m, a, b, v, i, j, k;
	
	scanf("%d %d", &n, &m);
	
	tGrafo G(n);
	tGrafo G2(n);
	
	while(m--) {
		scanf("%d %d %d", &a, &b, &v);
		G.addAresta(a-1, b-1, v);
		G.addAresta(b-1, a-1, v);
	}
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < G.Grafo[i].size(); j++) 
			for(k = 0; k < G.Grafo[G.Grafo[i][j].id].size(); k++) 
				G2.addAresta(i, G.Grafo[G.Grafo[i][j].id][k].id, G.Grafo[G.Grafo[i][j].id][k].dist + G.Grafo[i][j].dist);
	}
	
	printf("%d\n", G2.dijkstra(0, n-1));

	return 0;
}