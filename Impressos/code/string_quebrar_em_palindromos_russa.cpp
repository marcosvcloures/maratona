#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

#define D(x) cout << #x << " = " << x << endl

int main() {
	ios::sync_with_stdio(false);
	
	int n;
	string entrada;
	
	cin >> n;
	cin >> entrada;
	
	vi apareceu(255);
	
	for(auto &it : entrada)
		apareceu[it]++;
		
	int impares = 0, palindromos = 1, tamanho;
	
	vi usaveis;
	
	for(int i = 0; i < 255; i++)
		if(apareceu[i] % 2)
			usaveis.push_back(i), impares++, apareceu[i]--;
	
	palindromos = max(impares, palindromos);
	
	if(palindromos > 1)
		while(palindromos < entrada.size()) {
			if((entrada.size() % palindromos) == 0 && (entrada.size() / palindromos) % 2 == 1)
				break;
			else
				palindromos += 2;
		}
	
	if(entrada.size() % palindromos)
		palindromos = entrada.size();
	
	cout << palindromos << endl;
	
	tamanho = entrada.size() / palindromos;
	int j = 0;
	
	for(int i = 0; i < palindromos; i++) {
		string resposta;
		
		if(tamanho % 2) {
			if(usaveis.size())
				resposta = usaveis.back(), usaveis.pop_back();
			else {
				for(int k = 0; k < 255; k++)
					if(apareceu[k]) {
						usaveis.push_back(k);
						
						resposta = k;
						
						apareceu[k] -= 2;
						
						break;
					}
			}
		}
		
		for(; j < 255; j++) {
			while(apareceu[j]) {
				resposta += ((char) j);
				
				apareceu[j] -= 2;
				
				if(tamanho <= resposta.size() * 2)
					break;
			}
			
			if(tamanho <= resposta.size() * 2)
				break;
		}
		
		reverse(resposta.begin(), resposta.end());
		cout << resposta;
		
		if(tamanho % 2) 
			resposta.erase(resposta.end() - 1, resposta.end());
		
		reverse(resposta.begin(), resposta.end());
		cout << resposta;
		
		cout << " \n"[i == palindromos-1];
	}
}