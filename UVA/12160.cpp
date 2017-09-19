#include <bits/stdc++.h>

using namespace std;

int main(){
	int l, u, r;
	int caso = 1;
	while(true){
		cin >> l >> u >> r;
		if(l == 0 & u == 0 && r == 0){
			break;
		}
		
		int botoes[r];
		
		for(int i = 0; i < r; i++){
			cin >> botoes[i];
		}
		
		queue<pair<int, int> > estados;
		set<int> visitados;
		
		estados.push(make_pair(l, 0));
		visitados.insert(l);
		pair<set<int>::iterator, bool> it;
		int prox;
		bool solucao = false;
		pair<int, int> atual;
		
		while(!estados.empty()){
			atual = estados.front();
			estados.pop();
			if(atual.first == u){
				solucao = true;
				break;
			}
			for(int i = 0; i < r; i++){
				prox = (atual.first + botoes[i]) % 10000;
				it = visitados.insert(prox);
				if(it.second){
					estados.push(make_pair(prox, atual.second + 1));
				}
			}
		}
		
		cout << "Case " << caso << ": ";
		
		if(solucao){
			cout << atual.second << endl;
		} else {
			cout << "Permanently Locked" << endl;
		}
		caso++;
		
	}

	return 0;
}
