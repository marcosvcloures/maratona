#include <bits/stdc++.h>

using namespace std;

typedef struct tAresta {
	int a, b, c;
} tAresta;

int comp(tAresta a, tAresta b) {
	return a.c < b.c;
}

vector<int> conjuntos;

int find(int i) {
    if(conjuntos[i] == i) 
		return conjuntos[i];
		
    return conjuntos[i] = find(conjuntos[i]);
}

bool mesmoconjunto(int i, int j) {
	return find(i) == find(j); 
}

void unir(int i,int j) { 
	conjuntos[find(i)] = find(j); 
}

int main() {
	vector<tAresta> arestas;
	int n, m, i, j, custoTotal;
	tAresta aresta;
	
	while(scanf("%d %d", &n, &m) > 0 && (n || m)) {			
		arestas.clear();
		
		conjuntos.assign(n, 0);
    
		for(i = 0 ; i < n; i++) 
			conjuntos[i] = i;
			
		for(i = custoTotal = 0; i < m; i++, arestas.push_back(aresta), custoTotal += aresta.c)
			scanf("%d %d %d", &aresta.a, &aresta.b, &aresta.c);
		
		sort(arestas.begin(), arestas.end(), comp);
		
		for(i = 0;i < arestas.size();i++) {
            if(!mesmoconjunto(arestas[i].a, arestas[i].b)){
                custoTotal -= arestas[i].c;
                unir(arestas[i].a, arestas[i].b);
            }
        }
		
		printf("%d\n", custoTotal);
	}
}