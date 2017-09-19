#include <bits/stdc++.h>

using namespace std;

struct tVertice {
 int id, pai;
 long long int dist;
 
 tVertice(int a, long long int b, int p = -1) {
  id = a;
  dist = b;
  pai = p;
 }
 
 bool operator<(tVertice a) const {
  return a.dist < dist;
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
 
 void addAresta(int a, int b, long long int v = 0) {
  Grafo[a].push_back(tVertice(b, v));
 }
 
 void removeAresta(int a, int b) {
  for(int i = 0; i < Grafo[a].size(); i++)
   if(Grafo[a][i].id == b) {
    Grafo[a].erase(Grafo[a].begin() + i);
    return;
   }
 }



 long long int Dijkstra(int inicio, int fim) {
  priority_queue<tVertice> fila;
  bool visitados[n];
  int i;
  
  for(i = 0; i < n; i++)
   pais[i] = visitados[i] = 0;
  
  fila.push(tVertice(inicio, 0));
  
  while(fila.top().id != fim && !fila.empty()) {
   if(!visitados[fila.top().id]) {
    for(i = 0; i < Grafo[fila.top().id].size(); i++)
     if(!visitados[Grafo[fila.top().id][i].id])
      fila.push(tVertice(Grafo[fila.top().id][i].id, fila.top().dist + Grafo[fila.top().id][i].dist, fila.top().id));
      
    visitados[fila.top().id] = 1;
    pais[fila.top().id] = fila.top().pai;
   }
   
   fila.pop();
  }
  
  if(fila.empty())
   return -1;
  
  pais[fila.top().id] = fila.top().pai;
  
  return fila.top().dist;
 }

// Retorna a MST, caso queira retornar o custo, basta retornar a variável custo.
 tGrafo Prim(int inicio) {
  priority_queue<tVertice> fila;
  tGrafo G2(n);
  bool visitados[n];
  int i, custo = 0;
  
  fila.push(tVertice(inicio, 0));
  
  while(!fila.empty()) {
   if(!visitados[fila.top().id]) {
    for(i = 0; i < Grafo[fila.top().id].size(); i++)
     if(!visitados[Grafo[fila.top().id][i].id])
      fila.push(tVertice(Grafo[fila.top().id][i].id, Grafo[fila.top().id][i].dist, fila.top().id));
    
    custo += fila.top().dist;  
    visitados[fila.top().id] = 1;
    G2.addAresta(fila.top().pai, fila.top().id);
   }
   
   fila.pop();
  }
  
  return G2;
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
      fila.push(tVertice(Grafo[fila.front().id][i].id, fila.front().dist + 1, fila.front().id));
     
    visitados[fila.front().id] = 1;
    pais[fila.front().id] = fila.front().pai;
   }
   
   fila.pop();
  }
  
  if(fila.empty())
   return -1;
  
  pais[fila.front().id] = fila.front().pai;
  
  return fila.front().dist;
 }

 long long int fordFulkerson(int s, int t) {
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


 long long int valAresta(int a, int b) {
  for(int i = 0; i < Grafo[a].size(); i++)
   if(Grafo[a][i].id == b)
    return Grafo[a][i].dist;
  return -1;
 }
 
 void modificaAresta(int a, int b, long long int v) {
  for(int i = 0; i < Grafo[a].size(); i++)
   if(Grafo[a][i].id == b) {
    Grafo[a][i].dist += v;
    
    if(Grafo[a][i].dist == 0)
     Grafo[a].erase(Grafo[a].begin() + i);
    
    return;
   }
  addAresta(a, b, v);
 }

 bool existeAresta(int a, int b) {
  for(int i = 0; i < Grafo[a].size(); i++)
   if(Grafo[a][i].id == b)
    return true;
  return false;
 }
};

int main(){
	int n, m, t, inicio;
	cin >> t;
	
	while(t--){
		cin >> n >> m;
		int aux;
		
		tGrafo grafo(n*m);
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> aux;
				
				if(i == 0 && i == j)
					inicio = aux;
					
				if(i != 0)
					grafo.addAresta((i-1)*m + j, i*m + j, aux);
				if(i != (n - 1))
					grafo.addAresta((i+1)*m + j, i*m + j, aux);
				if(j != 0)
					grafo.addAresta(i*m + (j-1), i *m + j, aux);
				if(j != (m - 1))
					grafo.addAresta(i*m + j + 1, i * m + j, aux);
			}
		}
		
		cout << inicio + grafo.Dijkstra(0, (n - 1) * m + (m - 1)) << endl;
	}

	return 0;
}
