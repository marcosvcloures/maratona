#include <stdio.h>

int main() {
	int n, max, qtd[300], entrada, i;
	
	while(scanf("%d", &n) > 0 && n) {
		for(i = 0; i < 201; i++)
			qtd[i] = 0;
		
		while(n--) {
			scanf("%d", &entrada);
			
			for(i = 0; i <= entrada; i++)
				qtd[i]++;
		}
		
		for(i = 0; i < 201; i++) {
			if(qtd[i] >= i)
				max = i;
		}
		
		printf("%d\n", max);
	}
}