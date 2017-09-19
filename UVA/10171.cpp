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



 long long int Dijkstra(int inicio, int * visitados) {
  priority_queue<tVertice> fila;
  int i;
  
  for(i = 0; i < n; i++)
   pais[i] = 0, visitados[i] = -1;
  
  fila.push(tVertice(inicio, 0));
  
  while(!fila.empty()) {
   if(visitados[fila.top().id] == -1) {
    for(i = 0; i < Grafo[fila.top().id].size(); i++)
     if(visitados[Grafo[fila.top().id][i].id] ==-1)
      fila.push(tVertice(Grafo[fila.top().id][i].id, fila.top().dist + Grafo[fila.top().id][i].dist, fila.top().id));
      
    visitados[fila.top().id] = fila.top().dist;
    pais[fila.top().id] = fila.top().pai;
   }
   
   fila.pop();
  }
  
  if(fila.empty())
   return -1;
  
  pais[fila.top().id] = fila.top().pai;
  
  return 0;
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
	int n, custo;
	char g, d, ori, dest, J, V;
	
	while(true){
		cin >> n;
		if(n == 0){
			break;
		}
		
		tGrafo jovem(26);
		tGrafo outros(26);
		
		for(int i = 0; i < n; i++){
			cin >> g >> d >> ori >> dest >> custo;
			
			if(g == 'Y'){
				jovem.addAresta((int)ori - 65, (int)dest - 65, custo);
				if(d == 'B'){
					jovem.addAresta((int)dest - 65, (int)ori-65, custo);
				}
			} else {
				outros.addAresta((int)ori - 65, (int)dest - 65, custo);
				if(d == 'B'){
					outros.addAresta((int)dest - 65, (int)ori - 65, custo);
				}
			}
		}
		
		cin >> J >> V;
		
		int * distJ = new int[26], *distO = new int[26];
		
		jovem.Dijkstra((int)J - 65, distJ);
		outros.Dijkstra((int)V - 65, distO);
		
		long long int menor = -1;
		int atual = -1;
		
		for(int i = 0; i < 26; i++){
			if(distJ[i] == -1 or distO[i] == -1){
				continue;
			}
			
			if(atual == -1){
				menor = distJ[i] + distO[i];
				atual = i;
			} else {
				if(menor > distJ[i] + distO[i]){
					menor = distJ[i] + distO[i];
					atual = i;
				}
			}
		}
		
		if(atual == -1){
			cout << "You will never meet." << endl;
		} else {
			cout << menor;
			for(int i = 0; i < 26; i++){
				if(distJ[i] + distO[i] == menor){
					cout << " " <<(char)(i + 65);
				}
			}
			cout << endl;
		}
		
		
		delete [] distJ;
		delete [] distO;
	}

	return 0;
}
