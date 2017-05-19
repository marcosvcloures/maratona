#include <stdio.h>
#include <ctype.h>
#include <string.h>

char produto[300], palavrasBoas[300][300], palavrasMas[300][300], entrada[400];
int nBoas, nMas;

int f(char* entrada) {
	char palavra[300];
	int score = 0, apareceu = 0;
	int i;
	
	while(entrada[0] != 0) {
		sscanf(entrada, " %s", palavra);
		
		for(i = 0; i < strlen(palavra); i++)
			palavra[i] = tolower(palavra[i]);
		
		if(!strcmp(palavra, produto)) {
			apareceu = 1;
		}
		else {
			for(i = 0; i < nBoas; i++)
				if(!strcmp(palavra, palavrasBoas[i]))
					score++;
			for(i = 0; i < nMas; i++)
				if(!strcmp(palavra, palavrasMas[i])) 
					score--;
		}
		
		entrada = entrada + strlen(palavra) + 1;
	}
	
	if(apareceu) {
		if(!score)
			return 2;
		else if(score > 0)
			return 1;
		return 3;
	}
	return 0;
}

int main() {
	int qtdBoas = 0, qtdMas = 0, qtdMeh = 0, m, i, j;
	scanf(" %s", produto);
	
	for(i = 0; i < strlen(produto); i++)
		produto[i] = tolower(produto[i]);
	
	scanf("%d", &nBoas);
	
	for(i = 0; i < nBoas; i++) {
		scanf(" %s", palavrasBoas[i]);
		
		for(j = 0; j < strlen(palavrasBoas[i]); j++)
			palavrasBoas[i][j] = tolower(palavrasBoas[i][j]);
	}
	scanf("%d", &nMas);
	
	for(i = 0; i < nMas; i++) {
		scanf(" %s", palavrasMas[i]);
	
		for(j = 0; j < strlen(palavrasMas[i]); j++)
			palavrasMas[i][j] = tolower(palavrasMas[i][j]);
	}
	scanf("%d%*c", &m);
	
	while(m--) {
		for(i = 0; i < 201; i++)
			entrada[i] = 0;

		gets(entrada);
		
		switch(f(entrada)) {
			case 1:
				qtdBoas++;
				break;
			case 2:
				qtdMeh++;
				break;
			case 3:
				qtdMas++;
				break;
		};
	}
	
	printf("%d %d %d\n", qtdBoas, qtdMeh, qtdMas);
}