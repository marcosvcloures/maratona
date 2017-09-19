#include <bits/stdc++.h>

using namespace std;

typedef struct tPalavra {
	char palavra[20];
} tPalavra;

int qtdLetrasDiferentes(tPalavra a, tPalavra b) {
	int qtdDiferentes = 0, max = strlen(a.palavra) > strlen(b.palavra) ? strlen(a.palavra) : strlen(b.palavra);
	
	for(int i = 0; i < max; i++)
		if(a.palavra[i] != b.palavra[i])
			qtdDiferentes++;
			
	return qtdDiferentes;
}

int main() {
	int t, i, j, k, primeiro = 1, matrizAdj[200][200], qtdPalavras, a, b;
	char linha[200], origem[20], destino[20];
	tPalavra dicionario[200];
	
	scanf("%d", &t);
	
	while(t--) {
		qtdPalavras = 0;
		
		while(scanf("%s", dicionario[qtdPalavras].palavra) && strcmp(dicionario[qtdPalavras].palavra, "*"))
			qtdPalavras++;
		
		
		for(i = 0; i < qtdPalavras; i++)
			for(j = 0; j < qtdPalavras; j++) 
				matrizAdj[i][j] = matrizAdj[j][i] = 100000;
		
		for(i = 0; i < qtdPalavras; i++)
			for(j = 0; j < qtdPalavras; j++) {
				
				if(i == j)
					matrizAdj[i][i] = 0;
					
				if(qtdLetrasDiferentes(dicionario[i], dicionario[j]) == 1) 
					matrizAdj[i][j] = matrizAdj[j][i] = 1;
			}
			
		for(i = 0; i < qtdPalavras; i++)
			for(j = 0; j < qtdPalavras; j++)
				for(k = 0; k < qtdPalavras; k++)
					if(matrizAdj[i][k] + matrizAdj[k][j] < matrizAdj[i][j])
						matrizAdj[i][j] = matrizAdj[i][k] + matrizAdj[k][j];
		
		for(i = 0; i < qtdPalavras; i++)
			for(j = 0; j < qtdPalavras; j++)
				for(k = 0; k < qtdPalavras; k++)
					if(matrizAdj[i][k] + matrizAdj[k][j] < matrizAdj[i][j])
						matrizAdj[i][j] = matrizAdj[i][k] + matrizAdj[k][j];
			
		printf("%s", primeiro ? "" : "\n");
		
		scanf("%*c");
		while(scanf("%[^\n]%*c", linha) > 0 && strcmp(linha, "")) {
			sscanf(linha, "%s %s", origem, destino);
			
			for(i = 0; i < qtdPalavras; i++) {
				if(!strcmp(dicionario[i].palavra, origem))
					a = i;
				else if(!strcmp(dicionario[i].palavra, destino))
					b = i;
			}
			
			printf("%s %s %d\n", origem, destino, matrizAdj[a][b]);
		}
		
		primeiro = 0;
	}
}