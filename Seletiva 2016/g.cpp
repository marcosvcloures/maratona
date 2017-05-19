#include <stdio.h>
#include <string.h>

int bk(char atual[], char desejada[], int n) {
	if(n == 0)
		return 1;
	
	if(atual[n-1] == desejada[0])
		if(bk(atual, desejada+1, n-1))
			return 1;
	if(atual[n-1] == desejada[n-1])
		if(bk(atual, desejada, n-1))
			return 1;
		
	return 0;
}

int main() {
	char palavra[200] = {0}, desejada[200] = {0};
	
	gets(palavra);
	gets(desejada);
	
	printf("%c\n", bk(palavra, desejada, strlen(palavra)) ? 'S' : 'N');
}