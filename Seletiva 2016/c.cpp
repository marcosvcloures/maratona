#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>

int grausEntrada[200000] = {0}, grausSaida[200000] = {0};

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

	long long int banana() {
		priority_queue<tVertice> fila;
		priority_queue<tVertice> saidas;
		priority_queue<tVertice> entradas;
		bool visitados[n];
		int i, resp = 0;
		
		for(i = 0; i < n; i++) {
			visitados[i] = 0;
			
			if(grausEntrada[i] == 0)
				entradas.push(tVertice(i, 2));
			saidas.push(tVertice(i, 110000-grausSaida[i]+grausEntrada[i]));
		}
		
		while(!entradas.empty()) {
			fila.push(entradas.top());
			entradas.pop();
			
			while(!fila.empty()) {
			//	printf("visitei o %d, resp: %d\n", fila.top().id+1, resp);
				
				if(!visitados[fila.top().id])
					for(i = 0; i < Grafo[fila.top().id].size(); i++) {
						if(!visitados[Grafo[fila.top().id][i].id]) {
							fila.push(tVertice(Grafo[fila.top().id][i].id, 10));
					//		printf("add fila: %d\n", (Grafo[fila.top().id][i].id+1));
						}
					}
				visitados[fila.top().id] = 1;
				fila.pop();
			}
			
			resp++;
		}
		
		while(!saidas.empty()) {
			while(visitados[saidas.top().id]) {
				saidas.pop();
				
				if(saidas.empty())
					return resp;
			}
			
			fila.push(saidas.top());
			
			while(!fila.empty()) {
			//	printf("visitei o %d, resp: %d\n", fila.top().id+1, resp);
				
				if(!visitados[fila.top().id])
					for(i = 0; i < Grafo[fila.top().id].size(); i++) {
						if(!visitados[Grafo[fila.top().id][i].id]) {
							fila.push(tVertice(Grafo[fila.top().id][i].id, 2000000));
					//		printf("add fila: %d\n", (Grafo[fila.top().id][i].id+1));
						}
					}
				visitados[fila.top().id] = 1;
				fila.pop();
			}
			
			saidas.pop();
			
			resp++;
		}
		
		return resp;
	}

	void addAresta(int a, int b) {
		Grafo[a].push_back(tVertice(b, 1));
	}
};

int main() {
	int n, m, a, b, v, i, j, k;
	
	scanf("%d %d", &n, &m);
	
	tGrafo G(n);
	
	while(m--) {
		scanf("%d %d", &a, &b);
		
		G.addAresta(a-1, b-1);
		grausEntrada[b-1]++;
		grausSaida[a-1]++;
	}
	
	printf("%d\n", G.banana());

	return 0;
}