#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <queue>

#define MAX 10000

using namespace std;

bool visitados[MAX][26];

struct tVertice {
	int id;
	char letra;
	long long int dist;
	
	tVertice(int a, long long int b) {
		id = a;
		dist = b;
	}
	
	tVertice(int a, long long int b, char p) {
		id = a;
		letra = p;
		dist = b;
	}
	
	bool operator<(tVertice a) const {
		return a.dist < dist;
	}
};

vector<tVertice> Grafo[MAX];

long long int dijkstra(int inicio, int fim) {
	priority_queue<tVertice> fila;
	int i,j;
	for(i = 0; i < MAX; i++)
		for(j = 0; j < 26; j++)
			visitados[i][j] = 0;
	fila.push(tVertice(inicio, 0));
	
	
	
	while(fila.top().id != fim && !fila.empty()) {
		if(!visitados[fila.top().id][fila.top().letra])
			for(i = 0; i < Grafo[fila.top().id].size(); i++) {
				if(!visitados[Grafo[fila.top().id][i].id][Grafo[fila.top().id][i].letra] && fila.top().letra != Grafo[fila.top().id][i].letra)
					fila.push(tVertice(Grafo[fila.top().id][i].id, fila.top().dist + Grafo[fila.top().id][i].dist, Grafo[fila.top().id][i].letra));
			}
		visitados[fila.top().id][fila.top().letra] = 1;
		fila.pop();
	}
	
	if(fila.empty())
		return -1;
	
	return fila.top().dist;
}

void aresta(int a, int b, long long int v, char p) {
	Grafo[a].push_back(tVertice(b, v, p));
}

int main() {
	int n, qtd, ia, ib, i;
	char a[100], b[100], c[100], mapa[20000][100];
	
	scanf("%d", &n);
	
	while(n != 0) {
		scanf(" %s %s", mapa[0], mapa[1]);
		qtd = 2;
		
		while(n--) {
			scanf(" %s %s %s", a, b, c);
			
			ia = ib = -1;
			
			for(i = 0; i < qtd; i++)
				if(!strcmp(mapa[i], a))
					ia = i;
				else if(!strcmp(mapa[i], b))
					ib = i;
				
			if(ia == -1) {
				ia = qtd;
				strcpy(mapa[qtd], a);
				qtd++;
			}
			
			if(ib == -1) {
				ib = qtd;
				strcpy(mapa[qtd], b);
				qtd++;
			}
			
			aresta(ia, ib, strlen(c), c[0]);
			aresta(ib, ia, strlen(c), c[0]);
		}
		
		n = dijkstra(0, 1);
		
		if(n >= 0)
			printf("%d\n", n);
		else
			puts("impossivel");
		
		for(i = 0; i < qtd; i++)
			Grafo[i].clear();
		
		scanf("%d", &n);
	}

	return 0;
}