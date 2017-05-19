#include <stdio.h>

typedef struct tPeca {
	int alturas[4][4], nConfigs, configs[4];
} tPeca;

tPeca peca[8];

int main() {
	peca[1].nConfigs = 2;
	peca[1].configs[0] = 1;
	peca[1].alturas[0][0] = 4;
	peca[1].configs[1] = 4;
	peca[1].alturas[1][0] = peca[1].alturas[1][1] = peca[1].alturas[1][2] = peca[1].alturas[1][3] = 1;

	peca[2].nConfigs = 4;
	peca[2].configs[0] = 2;
	peca[2].alturas[0][0] = 1;
	peca[2].alturas[0][1] = 3;
	peca[2].configs[1] = 3;
	peca[2].alturas[1][0] = 2;
	peca[2].alturas[1][1] = 1;
	peca[2].alturas[1][2] = 1;
	peca[2].configs[2] = 2;
	peca[2].alturas[2][0] = 3;
	peca[2].alturas[2][1] = 1;
	peca[2].configs[3] = 3;
	peca[2].alturas[3][0] = 1;
	peca[2].alturas[3][1] = 1;
	peca[2].alturas[3][2] = 2;

	peca[3].nConfigs = 4;
	peca[3].configs[0] = 2;
	peca[3].alturas[0][0] = 1;
	peca[3].alturas[0][1] = 3;
	peca[3].configs[1] = 3;
	peca[3].alturas[1][0] = 1;
	peca[3].alturas[1][1] = 1;
	peca[3].alturas[1][2] = 2;
	peca[3].configs[2] = 2;
	peca[3].alturas[2][0] = 3;
	peca[3].alturas[2][1] = 1;
	peca[3].configs[3] = 3;
	peca[3].alturas[3][0] = 2;
	peca[3].alturas[3][1] = 1;
	peca[3].alturas[3][2] = 1;

	peca[4].nConfigs = 1;
	peca[4].configs[0] = 2;
	peca[4].alturas[0][0] = 2;
	peca[4].alturas[0][1] = 2;

	peca[5].nConfigs = 2;
	peca[5].configs[0] = 2;
	peca[5].alturas[0][0] = 2;
	peca[5].alturas[0][1] = 2;
	peca[5].configs[1] = 3;
	peca[5].alturas[1][0] = 1;
	peca[5].alturas[1][1] = 2;
	peca[5].alturas[1][2] = 1;

	peca[6].nConfigs = 3;
	peca[6].configs[0] = 2;
	peca[6].alturas[0][0] = 1;
	peca[6].alturas[0][1] = 3;
	peca[6].configs[1] = 3;
	peca[6].alturas[1][0] = 1;
	peca[6].alturas[1][1] = 2;
	peca[6].alturas[1][2] = 1;
	peca[6].configs[2] = 2;
	peca[6].alturas[2][0] = 3;
	peca[6].alturas[2][1] = 1;

	peca[7].nConfigs = 2;
	peca[7].configs[0] = 2;
	peca[7].alturas[0][0] = 2;
	peca[7].alturas[0][1] = 2;
	peca[7].configs[1] = 3;
	peca[7].alturas[1][0] = 1;
	peca[7].alturas[1][1] = 2;
	peca[7].alturas[1][2] = 1;
	
	int a, l, p, alturas[200000], i, j, menor, maior, menor2, ci, cj, k;
	char e;
	
	while(scanf("%d %d %d", &a, &l, &p) > 0 && (a || l || p)) {
		for(i = 0; i < l+10; i++)
			alturas[i] = 0;
		
		for(i = 0; i < a; i++)
			for(j = 0; j < l; j++) {
				scanf(" %c", &e);
				
				if(e == '#')
					alturas[j]++;
			}
			
		menor = 0;
		for(i = 0; i < l; i++)
			if(alturas[i] < alturas[menor])
				menor = i;
			
		maior = 0;
		for(i = 0; i < peca[p].nConfigs; i++) {
			for(j = menor-peca[p].configs[i]; j <= menor; j++) {
				if(j < 0)
					continue;
				if(j + peca[p].configs[i] > l)
					break;
				
				for(k = 0; k < peca[p].configs[i]; k++) 
					alturas[k+j] += peca[p].alturas[i][k];
				
				menor2 = 10000;
				
				for(k = -4; k < peca[p].configs[i]+4; k++) {
					if(k+j < 0)
						continue;
					if(k+j >= l)
						break;
					
					if(alturas[k+j] < menor2)
						menor2 = alturas[k+j];
				}
				
				for(k = 0; k < peca[p].configs[i]; k++) 
					alturas[k+j] -= peca[p].alturas[i][k];
				
				if(menor2 > maior) {
					maior = menor2;
					ci = i;
					cj = j;
				}
			}
		}
		
		for(k = 0; k < peca[p].configs[ci]; k++)
			alturas[k+cj] += peca[p].alturas[ci][k];
		
		menor = 0;
		for(i = 0; i < l; i++) 
			if(alturas[i] < alturas[menor])
				menor = i;
			
		printf("%d\n", alturas[menor]);
	}
}