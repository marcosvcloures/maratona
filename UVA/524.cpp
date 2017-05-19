#include <bits/stdc++.h>
using namespace std;

int usados[17], valores[16];
int primos[] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0};

void bk(int pos, int tam, bool impar) {
	if(pos == 0) {
		valores[pos] = 1, usados[1] = 1;
		return bk(pos + 1, tam, !impar);
	}
	
	if(pos == tam && primos[valores[tam-1] + valores[0]]) {
		printf("%d", valores[0]);
		for(int i = 1; i < tam; i++)
			printf(" %d", valores[i]);
		printf("\n");
		return;
	}
	
	for(int i = 2 + impar; i <= tam; i += 2) {
		if(!usados[i] && primos[valores[pos-1] + i]) {
			valores[pos] = i;
			usados[i] = 1;
			
			bk(pos + 1, tam, !impar);
			
			usados[i] = 0;
		}
	}
}

int main(){
	int n, c;
	
	for(c = 1; scanf("%d", &n) > 0; c++) {
		memset(usados, 0, sizeof(int) * 17);
		
		if(c != 1)
			printf("\n");
			
		printf("Case %d:\n", c);
		
		bk(0, n, true);
	}
	
	return 0;
}
