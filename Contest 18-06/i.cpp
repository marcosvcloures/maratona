#include <bits/stdc++.h>
#define PAREDE 1000000

using namespace std;

typedef pair<int, int> ii;

int largura, altura, tempo, mapa[1001][1001];

int fill(int i, int j, int t) {
	if((mapa[i][j] && mapa[i][j] < t) || mapa[i][j] == PAREDE || t > tempo || i == 0 || j == 0 || i > altura || j > largura)
		return 0;
	
	if(mapa[i][j]) {
		mapa[i][j] = t;
		
		return fill(i+1, j, t+1) + fill(i-1, j, t+1) + fill(i, j+1, t+1) + fill(i, j-1, t+1);
	}
	
	mapa[i][j] = t;
	
	return 1 + fill(i+1, j, t+1) + fill(i-1, j, t+1) + fill(i, j+1, t+1) + fill(i, j-1, t+1);
}

int incremento(int dif) {
	if(dif == 0)
		return 0;
	return dif/abs(dif);
}

void parede(ii inicio, ii fim) {
	int inc_x = incremento(fim.first - inicio.first);
	int inc_y = incremento(fim.second - inicio.second);
	
	while(inicio.first != fim.first || inicio.second != fim.second) {
		mapa[inicio.second][inicio.first] = PAREDE;
		
		inicio.first += inc_x;
		inicio.second += inc_y;
	}
	
	mapa[inicio.second][inicio.first] = PAREDE;
}

int main() {
	int l, w, x, y, inicio_x, inicio_y, fim_x, fim_y, i, j, resp;
	queue<ii> vazamentos;
	
	while(scanf("%d", &largura) > 0 && largura != -1) {
		memset(mapa, 0, altura*largura*sizeof(int));
		
		resp = 0;
		
		scanf("%d %d %d %d", &altura, &tempo, &l, &w);
		
		while(l--) {
			scanf("%d %d", &x, &y);
			
			vazamentos.push(make_pair(x, y));
		}
		
		while(w--) {
			scanf("%d %d %d %d", &inicio_x, &inicio_y, &fim_x, &fim_y);
			
			parede(make_pair(inicio_x, inicio_y), make_pair(fim_x, fim_y));
		}
		
		while(vazamentos.size()) {
			resp += fill(vazamentos.front().second, vazamentos.front().first, 1);
			
			vazamentos.pop();
		}
		
		printf("%d\n", resp);
	}
}