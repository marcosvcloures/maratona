#include <bits/stdc++.h>

using namespace std;

bool estacionado[10100];
int estacionamento[1100];

int c, n;

#define D(x) cout << #x << " = " << x << endl;
	
bool estaciona(int tam, int placa) {
	int cont;
	int ini;
	for(int i=0; i<c; i++) {
		if(estacionamento[i] == -1) {
			cont = 0;
			ini = i;
			while(cont < tam && i<c && estacionamento[i] == -1) {
				cont++;
				i++;
			}
			
			if(cont == tam) {
				fill(estacionamento+ini, estacionamento+ini+tam, placa);
				return true;
			}
			
			i--;
		}
	}
	
	return false;
}

bool desentaciona(int placa) {
	if(!estacionado[placa])
		return false;
	
	for(int i=0; i<c; i++) {
		if(estacionamento[i] == placa) {
			while(i<c && estacionamento[i] == placa)
				estacionamento[i] = -1, i++;
			
			return true;
		}
	}
	
	return true;
}	

int main() {
	char letra;
	int placa, tam;
	
	while(cin >> c >> n) {
		fill(estacionado, estacionado+10010, false);
		fill(estacionamento, estacionamento+1010, -1);
		
		int cont = 0;
		for(int i=0; i<n; i++) {
			scanf(" %c", &letra);
			if(letra == 'C') {
				scanf("%d%d", &placa, &tam);
				
				if(estaciona(tam, placa)) {
					cont++;
					estacionado[placa] = true;
				}
			}
			else {
				scanf("%d", &placa);
				
				if(desentaciona(placa))
					estacionado[placa] = false;
			}
		}
		
		cout << cont*10 << endl;
	}

	return 0;
}
