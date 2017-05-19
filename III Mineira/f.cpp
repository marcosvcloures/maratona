#include <stdio.h>
#include <queue>

using namespace std;

int main() {
	vector<int> arestas[20];
	vector<int> vertices[110000];
	queue<int> avisitar;
	int n, l, m, entrada, i, j, k, visitados[110000], arestasVisitadas[20], nvisitados;
	
	while(scanf("%d %d", &n, &l) > 0 && (n || l)) {
		for(i = 0; i < n; i++) {
			scanf("%d", &m);
			
			while(m--) {
				scanf("%d", &entrada);
				
				if(i == 0) {
					avisitar.push(entrada);
					arestasVisitadas[entrada] = 1;
				}
				
				vertices[i].push_back(entrada);
				arestas[entrada].push_back(i);
			}
		}
		
		nvisitados = 1;
		visitados[0] = 1;
		
		while(!avisitar.empty()) {
			for(i = 0; i < arestas[avisitar.front()].size(); i++) {
				if(!visitados[arestas[avisitar.front()][i]]) {
					visitados[arestas[avisitar.front()][i]] = 1;
					nvisitados++;
					
					for(j = 0; j < vertices[arestas[avisitar.front()][i]].size(); j++) {
						if(!arestasVisitadas[vertices[arestas[avisitar.front()][i]][j]]) {
							avisitar.push(vertices[arestas[avisitar.front()][i]][j]);
							arestasVisitadas[vertices[arestas[avisitar.front()][i]][j]] = 1;
						}
					}
				}
			}
			
			avisitar.pop();
		}
		
		printf("%c\n", nvisitados == n ? 'S' : 'N');
		
		for(i = 0; i <= 20; i++) {
			arestas[i].clear();
			arestasVisitadas[i] = 0;
		}
		for(i = 0; i < n; i++) {
			visitados[i] = 0;
			vertices[i].clear();
		}
	}
}