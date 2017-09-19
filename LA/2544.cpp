#include <bits/stdc++.h>

using namespace std;

int bGanhou, nAltura, nLargura;

char matriz_round[20][20][4];

void jogar(char matriz[][20], int posI, int posJ, int round) {
	int i;

	if(bGanhou)
		return;
	
	if(matriz[posI][posJ] != 'O' && matriz[posI][posJ] != 'L' && matriz[posI][posJ] != 'G')
		return;
		
	if(matriz_round[posI][posJ][round] == 'S')
		return;
	
	if(matriz[posI][posJ] == 'G') {
		bGanhou = 1;
		return;
	}
	
	if(matriz_round[posI+1][posJ-1][round] != 'S')
		jogar(matriz, posI+1, posJ-1, (round + 1) % 4);
		
	jogar(matriz, posI+1, posJ, (round + 1) % 4);
	
	if(matriz_round[posI+1][posJ+1][round] != 'S')
		jogar(matriz, posI+1, posJ+1, (round + 1) % 4);
}

int main () {
	int i, j, k, posI, posJ;
	char matriz[20][20], sCoringa[50];

	scanf("%s", sCoringa);
	
	while(!strcmp(sCoringa, "START")) {
		scanf("%d %d", &nLargura, &nAltura);
		
		bGanhou = 0;
		
		for(i = 0; i <= nAltura+1; i++)
			matriz[i][0] = matriz[i][nLargura+1] = 'P';
		for(j = 0; j <= nLargura+1; j++)
			matriz[0][j] = matriz[nAltura+1][j] = 'P';
			
		for(k = 0; k < 4; k++) 
			for(i = 1; i <= nAltura; i++) 
				for(j = 1; j <= nLargura; j++)
					matriz_round[i][j][k] = 'O';
		
		for(i = 1; i <= nAltura; i++)
			for(j = 1; j <= nLargura; j++) {
				scanf(" %c", &matriz[i][j]);
				if(matriz[i][j] == 'S') {
					for(k = i; k <= nAltura; k++)
						matriz_round[k][j][2] = 'S';
					for(k = j; k <= nLargura; k++)
						matriz_round[i][k][1] = 'S';
					for(k = i; k > 0; k--)
						matriz_round[k][j][0] = 'S';
					for(k = j; k > 0; k--)
						matriz_round[i][k][3] = 'S';
				}
			}
		
		for(j = 1; j <= nLargura; j++)
			if(matriz[1][j] == 'L')
				posJ = j;
				
		jogar(matriz, 1, posJ, 0);
		
		printf("%s\n", bGanhou ? "FERRET" : "GARRET");
	
		scanf(" %*s %s", sCoringa);
	}
}