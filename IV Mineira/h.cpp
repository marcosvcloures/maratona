#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>

using namespace std;

struct tPonto {
	int x, y, parede;
	
	tPonto(int a, int b) {
		x = a;
		y = b;
	}
	
	tPonto(int a, int b, int c) {
		x = a;
		y = b;
		parede = c;
	}
	
	tPonto() {}
};


struct tParede {
	tPonto inicio, fim;
	
	bool operator<(tParede a) const {
		return inicio.x < a.inicio.x;
	}
};

struct tVertice {
	int id;
	double dist;
	
	tVertice(int a, double b) {
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

	double dijkstra(int inicio, int fim) {
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
	
	void addAresta(int a, int b, double v) {
		Grafo[a].push_back(tVertice(b, v));
	}
};

tParede paredes[100];

int lado(tPonto A, tPonto B, tPonto C) {
	return (C.y-A.y) * (B.x-A.x) > (B.y-A.y) * (C.x-A.x);
}

double dist(tPonto a, tPonto b) {
	return sqrt(pow((a.x-b.x), 2)+pow((a.y-b.y), 2));
}

int main() {
	int n, i, j, foi, visitado[202] = {0};
	tPonto inicio, fim, a, b, pontos[202], p1, p2, p3, p4;
	queue<int> fila;
	tGrafo g(40000);
	
	scanf("%d %d %d %d %d", &inicio.x, &inicio.y, &fim.x, &fim.y, &n);
	pontos[0] = inicio;
	pontos[0].parede = -1;
	pontos[1] = fim;
	pontos[1].parede = -2;
	
	fila.push(0);
	for(i = 2; i < 2*n+2; i++)
		fila.push(i);
	
	for(i = 0; i < n; i++) {
		scanf("%d %d %d %d", &a.x, &a.y, &b.x, &b.y);
		
		pontos[i*2+2] = a;
		pontos[i*2+2].parede = i;
		pontos[i*2+3] = b;
		pontos[i*2+3].parede = i;
		
		paredes[i].inicio = a;
		paredes[i].fim = b;
	}
	
	while(!fila.empty()) {
		visitado[fila.front()] = 1;
		
		p1 = pontos[fila.front()];
		
		for(i = 0; i < 2*n+2; i++) {			
			if(pontos[i].parede == pontos[fila.front()].parede || i == fila.front()) {
				continue;
			}
			
			p2 = pontos[i];
			foi = 1;
			
			for(j = 0; j < n; j++) {					
				if(pontos[i].parede == j || pontos[fila.front()].parede == j) {
					continue;
				}
				
				p3 = paredes[j].inicio;
				p4 = paredes[j].fim;
				
				if(lado(p1, p2, p3) != lado(p1, p2, p4) && lado(p1, p3, p4) != lado(p2, p3, p4)) {
					foi = 0;
					
				//	printf("(%d %d) -> (%d %d) | (%d %d) -> (%d %d) | %.02lf\n", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, p4.x, p4.y, dist(pontos[fila.front()], pontos[i]));
					j = n;
				}
			}
			
			if(foi) {
			//	printf("(%d %d) -> (%d %d) - %.02lf\n", pontos[fila.front()].x, pontos[fila.front()].y, pontos[i].x, pontos[i].y, dist(pontos[fila.front()], pontos[i])); 
				g.addAresta(fila.front(), i, dist(pontos[fila.front()], pontos[i]));
			}
		}
		
		fila.pop();
	}
	
	printf("%.02lf\n", g.dijkstra(0, 1));
}