#include <stdio.h>
#include <algorithm>

int abs(int a) {
	return a >= 0 ? a : -a;
}

bool cmp(int a, int b) {
	if(a < b)
		return abs(a) > abs(b);
	return abs(a) >= abs(b);
}

bool rev(int a, int b) {
	return a >= b;
}

int poderes[200000];
int usados[200000];

int main() {
	int n, m, i, menorPositivo, menorNegativo, maiorPositivo, maiorNegativo, positivo;
	long long int p1, p2, n1, n2;
	
	while(scanf("%d %d", &n, &m) > 0 && (n || m)) {
		for(i = 0; i < n; i++)
			scanf("%d", &poderes[i]);
		
		std::sort(poderes, poderes+n, rev);
		
		menorPositivo = menorNegativo = -100000;
		
		if(m == 1)
			usados[0] = poderes[0];
		else {
			if(poderes[0] <= 0 && m % 2) 
				for(i = 0; i < m; i++)
					usados[i] = poderes[i];
			else {
				std::sort(poderes, poderes+n, cmp);
				
				positivo = 1;
				
				for(i = 0; i < m; i++) {
					usados[i] = poderes[i];
					
					if(poderes[i] < 0) {
						positivo = !positivo;
						menorNegativo = i;
					}
					else
						menorPositivo = i;
				}
				
				if(!positivo) {
					if(menorPositivo >= 0) {
						maiorPositivo = maiorNegativo = -10000;
						
						for(i = m; i < n; i++)  {
							if(poderes[i] >= 0 && maiorPositivo < 0)
								maiorPositivo = i;
							else if(poderes[i] < 0 && maiorNegativo < 0)
								maiorNegativo = i;
						}
						
						if(maiorPositivo >= 0 && maiorNegativo >= 0) {
							p1 = poderes[menorPositivo];
							p2 = poderes[maiorPositivo];
							n1 = poderes[menorNegativo];
							n2 = poderes[maiorNegativo];
							
							if(p1*p2 >= n1*n2) 
								usados[menorNegativo] = poderes[maiorPositivo];
							else
								usados[menorPositivo] = poderes[maiorNegativo];
						}
						else if(maiorNegativo < 0 && maiorPositivo >= 0)
							usados[menorNegativo] = poderes[maiorPositivo];
						else if(maiorPositivo < 0 && maiorNegativo >= 0)
							usados[menorPositivo] = poderes[maiorNegativo];
					}
					else {
						maiorPositivo = -10000;
						
						for(i = m; i < n; i++)  {
							if(poderes[i] >= 0 && maiorPositivo < 0) {
								maiorPositivo = i;
								break;
							}
						}
					
						if(maiorPositivo >= 0) 
							usados[menorNegativo] = poderes[maiorPositivo];
						else {
							std::sort(poderes, poderes+n, rev);
							
							for(i = 0; i < m; i++)
								usados[i] = poderes[i];
						}
					}
				}
			}
		}
		
		std::sort(usados, usados+m);
		
		printf("%d", usados[0]);
		for(i = 1; i < m; i++)
			printf(" %d", usados[i]);
		printf("\n");
	}
}