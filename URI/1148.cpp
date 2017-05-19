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

void aresta(int a, int b, long long int v) {
	Grafo[a].push_back(tVertice(b, v));
}

int main() {
	int n, m, c, k, i, j, a, b, v;
	
	scanf("%d %d", &n, &m);
	
	while(n != 0) {
		for(i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &v);
			aresta(a-1, b-1, v);
			
			for(j = 0; j < Grafo[b-1].size(); j++)
				if(Grafo[b-1][j].id == a-1) {
					Grafo[b-1][j].dist = 0;
					
					for(j = 0; j < Grafo[a-1].size(); j++)
						if(Grafo[a-1][j].id == b-1) {
							Grafo[a-1][j].dist = 0;
							break;
						}
					break;
				}
		}
		
		scanf("%d", &m);
		
		while(m--) {		
			scanf("%d %d", &k, &c);
			k--;
			c--;
			
			v = dijkstra(k, c);
			
			if(v >= 0)
				printf("%d\n", v);	
			else
				puts("Nao e possivel entregar a carta");
		}
		
		for(i = 0; i < n; i++) 
			Grafo[i].clear();
		
		printf("\n");
		
		scanf("%d %d", &n, &m);
	}

	return 0;
}