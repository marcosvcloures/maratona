#include <bits/stdc++.h>

using namespace std;



int main() {
	int n, m, aux;
	int mat[350][350];
while(cin >> n >> m) {
	
	int linha;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			scanf("%d", &aux);
			if(aux == 1)
				linha = i;
			mat[i][j] = aux;
		}
	}
	
	int cont = 0;
	
	int menor = 15613265;
	int pos = 0;
	
	for(int i=0; i<m; i++) {
		menor = 15613265;
		
		for(int j=i; j < m; j++) {
			if(mat[0][j] < menor) {
				menor = mat[0][j];
				pos = j;
			}
		}
		
		if(i != pos) {
			cont++;
			for(int x=0; x<n; x++)
				swap(mat[x][i], mat[x][pos]);
		}
	}
	
	pos = 0;
	
	for(int i=0; i<n; i++) {
		menor = 15613265;
		
		for(int j=i; j<n; j++) {
			if(mat[j][0] < menor) {
				menor = mat[j][0];
				pos = j;
			}
		}
		
		if(i != pos) {
			cont++;
			for(int x=0; x<m; x++)
				swap(mat[i][x], mat[pos][x]);
		}
	}
	
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(mat[i][j] != i * m + j + 1) {
				puts("*");
				goto fim;
			}
		}
	}
	
	cout << cont << endl;
	fim:;
}

	return 0;
}
