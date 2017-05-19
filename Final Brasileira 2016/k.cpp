#include <bits/stdc++.h>

using namespace std;

struct tVertice {
	int id, pai;
	long long int cap;
	
	tVertice(int a, long long int b, int p = -1) {
		id = a;
		cap = b;
		pai = p;
	}
};

struct tGrafo {
	vector<tVertice> *Grafo;
	int n, *pais;
	
	tGrafo(int a) {
		Grafo = new vector<tVertice>[a];
		pais = new int[a];
		n = a;
	}
	
	~tGrafo() {
		limpa();
		delete [] pais;
		delete [] Grafo;
	}
	
	void operator=(tGrafo const &a) {
		limpa();
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < a.Grafo[i].size(); j++) 
				Grafo[i].push_back(a.Grafo[i][j]);
	}
	
	void limpa() {
		for(int i = 0; i < n; i++)
			Grafo[i].clear();
	}
	
	long long int buscaLargura(int inicio, int fim) {
		queue<tVertice> fila;
		bool visitados[n];
		int i;
		
		for(i = 0; i < n; i++)
			visitados[i] = pais[i] = 0;
		
		fila.push(tVertice(inicio, 0));
		
		while(fila.front().id != fim && !fila.empty()) {
			if(!visitados[fila.front().id]) {
				for(i = 0; i < Grafo[fila.front().id].size(); i++)
					if(!visitados[Grafo[fila.front().id][i].id])
						fila.push(tVertice(Grafo[fila.front().id][i].id, fila.front().cap + 1, fila.front().id));
					
				visitados[fila.front().id] = 1;
				pais[fila.front().id] = fila.front().pai;
			}
			
			fila.pop();
		}
		
		if(fila.empty())
			return -1;
		
		pais[fila.front().id] = fila.front().pai;
		
		return fila.front().cap;
	}
	
	long long int edmondsKarp(int s, int t) {
		int u, v;
		long long int max_flow = 0;
		tGrafo G2(n);
		G2 = *this;
	 
		while (G2.buscaLargura(s, t) >= 0) {
			long long int path_flow = 10000000000;
			
			for (v = t; v != s; v = G2.pais[v]) {
				u = G2.pais[v];
				path_flow = min(path_flow, G2.valAresta(u, v));
			}
			
			for (v = t; v != s; v = G2.pais[v]) {
				u = G2.pais[v];
				G2.modificaAresta(u, v, -path_flow);
				G2.modificaAresta(v, u, path_flow);
			}
	 
			max_flow += path_flow;
		}
	 
		return max_flow;
	}

	void addAresta(int a, int b, long long int v = 0) {
		Grafo[a].push_back(tVertice(b, v));
	}
	
	long long int valAresta(int a, int b) {
		for(int i = 0; i < Grafo[a].size(); i++)
			if(Grafo[a][i].id == b)
				return Grafo[a][i].cap;
		return 0;
	}
	
	void modificaAresta(int a, int b, long long int v) {
		for(int i = 0; i < Grafo[a].size(); i++)
			if(Grafo[a][i].id == b) {
				Grafo[a][i].cap += v;
				
				if(Grafo[a][i].cap == 0)
					Grafo[a].erase(Grafo[a].begin() + i);
				
				return;
			}
		addAresta(a, b, v);
	}
};

int main() {
	tGrafo grafo(102);
	int n, i, v1, v2, lob, k, resp = 0;
	
	scanf("%d", &n);
	
	for(i = 1; i <= n; i++) {
		scanf("%d %d", &v1, &v2);
		grafo.addAresta(i, v1 + 50, 1);
		grafo.addAresta(i, v2 + 50, 1);
		grafo.addAresta(0, i, 1);
		grafo.addAresta(i + 50, 101, 0);
	}
	
	for(lob = 1; lob <= n; lob++) {
		k = 0;
		
		grafo.modificaAresta(0, lob, 1);
		
		for(i = 1; i <= n; i++)
			if(grafo.existeAresta(i, lob + 50))
				k++, grafo.modificaAresta(0, i, -1);
		
		
		for(i = 1; i <= n; i++)
			grafo.modificaAresta(i + 50, 101, k - 1); 
		
		resp += grafo.edmondsKarp(0, 101) != n - k + 1;
		
		for(i = 1; i <= n; i++)
			if(grafo.existeAresta(i, lob + 50))
				grafo.modificaAresta(0, i, 1);
			
		for(i = 1; i <= n; i++)
			grafo.modificaAresta(i + 50, 101, 1 - k);
		
		grafo.modificaAresta(0, lob, -1);
	}
	
	printf("%d\n", resp);
}