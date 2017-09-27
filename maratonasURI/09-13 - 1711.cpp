#include <bits/stdc++.h>

#define pb push_back

using namespace std;

typedef pair<int, int> ii;

typedef vector<ii> vii;

int ciclos[10000], visitados[10000], pais[10000], n;
vector<vii> grafo;

void calcCiclo(int atual, int custo) 
{
	visitados[atual] = custo;
	
	for(auto &it : grafo[atual]) 
	{
		if(it.second != pais[atual] && visitados[it.second] && !ciclos[atual]) 
		{
			int temp = atual;
			ciclos[it.second] = custo - visitados[it.second] + it.first;
			
			while(temp != it.second) 
			{
				ciclos[temp] = ciclos[it.second];
				temp = pais[temp];
			}
		}
		else if(!visitados[it.second])
		{
			pais[it.second] = atual;
			
			calcCiclo(it.second, custo + it.first);
		}
	}
}

struct pode {
	int vertice, custo, contaCiclo;
	
	pode(int a, int b, int c) : vertice(a), custo(b), contaCiclo(c) {
	}
	
	bool operator<(const pode &a) const {
		return a.custo < custo;
	}
};

int dijkstra(int ini, int tam) 
{
	priority_queue<pode> fila;
	fill(visitados, visitados + n, 0);
	
	fila.push(pode(ini, 0, false));
	
	if(ciclos[ini] >= tam)
		fila.push(pode(ini, ciclos[ini], true));
		
	pode topo = fila.top();
	
	while(!topo.contaCiclo) {
		if(!visitados[topo.vertice]) {
			visitados[topo.vertice] = topo.custo;
			
			for(auto &it : grafo[topo.vertice])
			{
				if(!visitados[it.second])
					fila.push(pode(it.second, topo.custo + it.first, false));
				if(ciclos[it.second] >= tam)
					fila.push(pode(it.second, 2 * (topo.custo + it.first) + ciclos[it.second], true));
			}
		}
		
		fila.pop();
		topo = fila.top();
	}
	
	return topo.custo;
}

int main() {
	int m, i, a, b, c, d, q, resp, ini, tam, maximo;
	
	while(scanf("%d %d", &n, &m) > 0) {
		fill(visitados, visitados + n, 0);
		fill(ciclos, ciclos + n, 0);
		grafo = vector<vii>(n);
		
		for(i = 0; i < m; i++)
			scanf("%d %d %d", &a, &b, &c),
			grafo[a-1].pb(ii(c, b-1)),
			grafo[b-1].pb(ii(c, a-1));
			
		calcCiclo(0, 1);
			
		scanf("%d", &q);
		
		maximo = 0;
		for(i = 0; i < n; i++)
			maximo = max(maximo, ciclos[i]);
		
		while(q--) 
		{
			scanf("%d %d", &ini, &tam);
			
			if(tam <= maximo)
				printf("%d\n", dijkstra(ini - 1, tam));
			else
				puts("-1");
		}
	}
}
