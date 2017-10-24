#include <bits/stdc++.h>

using namespace std;

struct No {
	map<char, No> filhos;
};

int dfs(No &atual, int nivel, char v) {
	int resp = 0;
	
	for(auto &it : atual.filhos) {
		if(it.first == '$')
			resp += nivel;
		
		resp += dfs(it.second, nivel + (atual.filhos.size() > 1), it.first);
	}
	
	return resp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, i;
	string pal;
	
	while(cin >> n) {
		No inicio, *atual;
			
		inicio.filhos['-'] = No();
			
		for(i = 0; i < n; i++)
		{
			atual = &inicio;
			
			cin >> pal;
			
			for(auto &it : pal) {
				if(atual->filhos.count(it))
					atual = &(atual->filhos[it]);
				else {
					atual->filhos[it] = No();
					atual = &(atual->filhos[it]);
				}
			}
			
			atual->filhos['$'] = No();
		}
		
		printf("%.2lf\n", dfs(inicio, 0, '-') * 1.0 / n);
	}
}
