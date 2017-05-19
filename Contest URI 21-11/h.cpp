#include <stdio.h>

int marcar(char matriz[][500], int i, int j, int n) {
	if(i < 0 || j < 0 || i >= n || j >= n || matriz[i][j] == 'X')
		return 0;

	if(matriz[i][j] == '<' && (matriz[i][j-1] == 'X' || j == 0)) {
		matriz[i][j] = 'X';
		return 1 + marcar(matriz, i-1, j, n) + marcar(matriz, i+1, j, n) + marcar(matriz, i, j-1, n) + marcar(matriz, i, j+1, n);
	}
	
	if(matriz[i][j] == 'A' && (matriz[i-1][j] == 'X' || i == 0)) {
		matriz[i][j] = 'X';
		return 1 + marcar(matriz, i-1, j, n) + marcar(matriz, i+1, j, n) + marcar(matriz, i, j-1, n) + marcar(matriz, i, j+1, n);
	}
	
	if(matriz[i][j] == '>' && (matriz[i][j+1] == 'X' || j == n-1)) { 
		matriz[i][j] = 'X';
		return 1 + marcar(matriz, i-1, j, n) + marcar(matriz, i+1, j, n) + marcar(matriz, i, j-1, n) + marcar(matriz, i, j+1, n);
	}
	
	if(matriz[i][j] == 'V' && (matriz[i+1][j] == 'X' || i == n-1)) {
		matriz[i][j] = 'X';
		return 1 + marcar(matriz, i-1, j, n) + marcar(matriz, i+1, j, n) + marcar(matriz, i, j-1, n) + marcar(matriz, i, j+1, n);
	}
	
	return 0;
}

int main () {
	int n, i, j, marcadas = 0;
	char matriz[500][500];
	
	scanf("%d%*c", &n);
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++)
			scanf("%c", &matriz[i][j]);
		scanf("%*c");
	}
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			marcadas += marcar(matriz, i, j, n);
		}
	}
	
	printf("%d\n", n*n-marcadas);
	
	return 0;
}