#include <bits/stdc++.h>
using namespace std;


int main(){
	int n, aux;
	cin >> n;
	
	while(n--){
		int a;
		vector<int> moedas;
		cin >> a;
		for(int i = 0; i < a; i++){
			cin >> aux;
			moedas.push_back(aux);
		}
		
		long long int soma = 1;
		int cc = 1;
		
		for(int i = 1; i < moedas.size(); i++){
			bool cont = true;
			for(int j = i + 1; j < moedas.size(); j++){
				if(soma + moedas[i] >= moedas[j]){
					cont = false;
					break;
				}
			}
			if(cont){
				soma += moedas[i];
				cc++;
			}
		}
		
		cout << cc << endl;
		
	}
}
