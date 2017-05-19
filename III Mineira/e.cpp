#include <stdio.h>

struct tHotel {
	char nome[30];
	int d, p, q, listado;
};

int main() {
	tHotel hoteis[1000];
	int n, i, j;
	
	while(scanf("%d", &n) > 0 && n) {
		for(i = 0; i < n; i++) {
			scanf(" %s %d %d %d", hoteis[i].nome, &hoteis[i].d, &hoteis[i].p, &hoteis[i].q);
			hoteis[i].listado = 1;
		}
		
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++) 
				if(i != j) {
					if ((hoteis[i].d < hoteis[j].d && hoteis[i].p <= hoteis[j].p && hoteis[i].q >= hoteis[j].q) ||
						(hoteis[i].d <= hoteis[j].d && hoteis[i].p < hoteis[j].p && hoteis[i].q >= hoteis[j].q) ||
						(hoteis[i].d <= hoteis[j].d && hoteis[i].p <= hoteis[j].p && hoteis[i].q > hoteis[j].q)) {
							
						hoteis[j].listado = 0;
					}
				}
				
		for(i = 0; i < n; i++)
			if(hoteis[i].listado)
				printf("%s\n", hoteis[i].nome);
		puts("*");
	}
}