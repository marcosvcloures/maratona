#include <bits/stdc++.h>

using namespace std;

typedef struct tPonto {
	double x, y;
} tPonto;

double dist(tPonto a, tPonto b) {
	return sqrt(pow(b.x-a.x, 2) + pow(b.y-a.y, 2));
}

int main () {
	int t, n, conectados[200], nConectados, i, proximo, primeiro = 1;
	tPonto pontos[200];
	double distancias[200], distMinima;
	
	scanf("%d", &t);
	
	while(t--) {
		scanf("%d", &n);
		
		distMinima = 0;
		
		for(i = 0; i < n; i++, conectados[i] = 0, distancias[i] = 1000000)
			scanf("%lf %lf", &pontos[i].x, &pontos[i].y);		
		
		for(proximo = nConectados = distancias[0] = 0; nConectados < n; nConectados++) {
			conectados[proximo] = 1;
			distMinima += distancias[proximo];
			
			for(i = 0; i < n; i++) {
				if(conectados[i] || i == proximo)
					continue;
					
				if(dist(pontos[proximo], pontos[i]) < distancias[i])
					distancias[i] = dist(pontos[proximo], pontos[i]);
			}
			
			proximo = -1;
			
			for(i = 0; i < n; i++) {
				if(conectados[i] || i == proximo)
					continue;
				
				if(proximo < 0 || distancias[i] < distancias[proximo])
					proximo = i;
			}
		}
		
		printf("%s%.2lf\n", primeiro ? "" : "\n", distMinima);
		
		primeiro = 0;
	}
}