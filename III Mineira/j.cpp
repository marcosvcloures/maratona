#include <stdio.h>
#include <string.h>

int palindromo(char palavra[]) {
	int tam = strlen(palavra);
	
	for(int i = 0; i < tam/2; i++) 
		if(palavra[i] != palavra[tam-i-1])
			return 0;
	
	return 1;
}

void add(char palavra[], int t, int n) {
	int tam = strlen(palavra);
	
	for(int i = tam+1; i > t; i--)
		palavra[i] = palavra[i-1];
	
	palavra[t] = palavra[n];
}

int main() {
	int n, tam;
	char palavra[101];
	
	while(scanf(" %s", palavra) > 0) {
		tam = strlen(palavra);
		n = 0;
		
		while(!palindromo(palavra)) {
			add(palavra, tam, n);
			n++;
		}
		
		printf("%d\n", n);
	}
}