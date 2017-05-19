#include <stdio.h>

long long int dest, val[10], usados[10];
int n, respi;
char resp[10][1000];

int bk(long long int v, int atual) {
	int i;
	
	if(v == dest) {
		respi = atual;
		return 1;
	}
	if(atual == n)
		return 0;
	
	if(atual == 0) {
		for(i = 0; i < n; i++) {
			usados[i] = 1;
			
			if(bk(val[i], atual + 1)) 
				return 1;
			
			usados[i] = 0;
		}
	}
	else {
		for(i = 0; i < n; i++) {
			if(!usados[i]) {
				usados[i] = 1;
				
					if(bk(v+val[i], atual+1)) {
						sprintf(resp[atual], "%lld + %lld = %lld", v, val[i], v+val[i]);
						return 1;
					}
					if(bk(v*val[i], atual+1)) {
						sprintf(resp[atual], "%lld x %lld = %lld", v, val[i], v*val[i]);
						return 1;
					}
					if(v-val[i] > 0 && bk(v-val[i], atual+1)) {
						sprintf(resp[atual], "%lld - %lld = %lld", v, val[i], v-val[i]);
						return 1;
					}
					if(val[i] != 0 && v%val[i] == 0 && bk(v/val[i], atual+1)) {
						sprintf(resp[atual], "%lld / %lld = %lld", v, val[i], v/val[i]);
						return 1;
					}
				
				usados[i] = 0;
			}
		}
	}
	
	return 0;
}
	
int main() {
	int i;
	
	scanf("%lld", &dest);
	while(dest) {
		scanf("%d", &n);
		
		for(i = 0; i < n; i++) {
			scanf("%lld", &val[i]);
			usados[i] = 0;
		}
		
		if(bk(0, 0)) {
			for(i = 1; i < respi-1; i++)
				puts(resp[i]);
			printf("%s <-\n", resp[i]);
		}
		
		scanf("%lld", &dest);
	}
}