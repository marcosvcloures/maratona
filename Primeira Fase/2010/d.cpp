#include <stdio.h>
#include <stdlib.h>
#include <queue>

#define MAX 500

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

vector<tVertice> Grafo[MAX];

long long int dijkstra(int inicio, int fim) {
	priority_queue<tVertice> fila;
	bool visitados[MAX] = {0};
	int i;
	
	fila.push(tVertice(inicio, 0));
	
	while(fila.top().id != fim && !fila.empty()) {
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

void aresta(int a, int b, long long int v) {
	Grafo[a].push_back(tVertice(b, v));
}

int main() {
	int n, m, c, k, i, j, a, b, v;
	
	scanf("%d %d %d %d", &n, &m, &c, &k);
	
	while(n != 0) {
		for(i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &v);
			
			aresta(a, b, v);
			aresta(b, a, v);
		}
		
		for(i = 0; i < c; i++) {
			for(j = 0; j < Grafo[i].size(); j++) {
				if(Grafo[i][j].id != i+1)
					Grafo[i][j].dist = 10000000;
			}
		}
		
		printf("%d\n", dijkstra(k, c-1));	
		
		for(i = 0; i < n; i++)
			Grafo[i].clear();
		
		scanf("%d %d %d %d", &n, &m, &c, &k);
	}

	return 0;
}