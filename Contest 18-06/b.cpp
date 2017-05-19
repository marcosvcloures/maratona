#include <bits/stdc++.h>

enum { BAIXO, CIMA, DIREITA, ESQUERDA };

int altura, largura;

char mapa[30][30];

void andar(int i, int j, int dir) {
	if(i < 0 || j < 0 || i == altura || j == largura) {
		if(dir == BAIXO)
			i--;
		else if(dir == CIMA)
			i++;
		else if(dir == DIREITA)
			j--;
		else
			j++;
		
		mapa[i][j] = '&';
		
		return;
	}
	
	if(mapa[i][j] == '/') {
		if(dir == BAIXO)
			dir = ESQUERDA;
		else if(dir == CIMA)
			dir = DIREITA;
		else if(dir == DIREITA)
			dir = CIMA;
		else
			dir = BAIXO;
	}
	
	if(mapa[i][j] == '\\') {
		if(dir == BAIXO)
			dir = DIREITA;
		else if(dir == CIMA)
			dir = ESQUERDA;
		else if(dir == DIREITA)
			dir = BAIXO;
		else
			dir = CIMA;
	}
	
	if(dir == BAIXO)
		return andar(i+1, j, dir);
	if(dir == CIMA)
		return andar(i-1, j, dir);
	if(dir == DIREITA)
		return andar(i, j+1, dir);
	if(dir == ESQUERDA)
		return andar(i, j-1, dir);
}

int main() {
	int i, j, entrada_i, entrada_j, dir, c = 1;
	
	while(scanf("%d %d", &largura, &altura) > 0 && (altura || largura)) {
		for(i = 0; i < altura; i++)
			for(j = 0; j < largura; j++) {
				scanf(" %c", &mapa[i][j]);
				
				if(mapa[i][j] == '*') {
					entrada_i = i;
					entrada_j = j;
				}
			}
			
		if(entrada_i == 0)
			dir = BAIXO;
		else if(entrada_i == altura-1)
			dir = CIMA;
		else if(entrada_j == 0)
			dir = DIREITA;
		else
			dir = ESQUERDA;
		
		andar(entrada_i, entrada_j, dir);
	
		printf("HOUSE %d\n", c);
		
		for(i = 0; i < altura; i++) {
			for(j = 0; j < largura; j++)
				printf("%c", mapa[i][j]);
			
			printf("\n");
		}
		
		c++;
	}
}