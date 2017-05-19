#include <stdio.h>

int main() {
	char entrada[2000000];
	int n, pos[26], tam = 0, maior = 0, comeco = 0, i, j;
	
	scanf("%d %s", &n, entrada);
	
	for(j = 0; j < 26; j++)
		pos[j] = -1;
	
	for(i = 0; i < n; i++) {
		if(tam > maior)
			maior = tam;
		
		if(entrada[i] >= '0' && entrada[i] <= '9') {
			tam = 0;
			comeco = i+1;
			
			for(j = 0; j < 26; j++)
				pos[j] = -1;
		}
		else {
			if(pos[entrada[i]-'a'] > -1) {				
				for(j = comeco; j < pos[entrada[i]-'a']; j++) {
					pos[entrada[j]-'a'] = -1;
				}		
				
				tam -= pos[entrada[i]-'a']-comeco+1;
				
				comeco = pos[entrada[i]-'a']+1;		
			}
			
			pos[entrada[i]-'a'] = i;
			tam++;
		}
	}
	
	if(tam > maior)
		maior = tam;
	
	printf("%d\n", maior);
}