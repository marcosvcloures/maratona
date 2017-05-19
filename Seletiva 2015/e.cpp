#include <stdio.h>

int tabuleiro[4][4];

void shift() {
	int i, j, k, temp;
	
	for(k = 0; k < 4; k++)
		for(j = 0; j < 4; j++)
			for(i = 0; i < 3; i++) {
				if(tabuleiro[i][j] == 0) {
					temp = tabuleiro[i][j];
					tabuleiro[i][j] = tabuleiro[i+1][j];
					tabuleiro[i+1][j] = temp;
				}
			}
}

void merge() {
	int i, j, k;
	
		for(i = 0; i < 3; i++) 
			for(j = 0; j < 4; j++)
				if(tabuleiro[i][j] == tabuleiro[i+1][j] && tabuleiro[i][j] != 0) {
					tabuleiro[i][j] *= 2;
					tabuleiro[i+1][j] = 0;
				}
}

int main() {
	int i, j, k, temp;
	
	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)
			scanf("%d", &tabuleiro[i][j]);
		
	shift();
	
	merge();
	
	shift();
	
	for(i = 0; i < 4; i++) {
		for(j = 0; j < 4; j++)
			printf("%d ", tabuleiro[i][j]);
		printf("\n");
	}
}