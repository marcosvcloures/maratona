#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	while(n--){
		vector<int> lista;
		int m, aux;
		cin >> m;
		for(int i = 0; i < m; i++){
			cin >> aux;
			lista.push_back(aux);
		}
		
		sort(lista.rbegin(), lista.rend());
		
		int desconto = 0;
		
		for(int i = 0; i < lista.size(); i += 3){
			if(i + 2 >= lista.size()){
				break;
			}
			desconto += lista[i + 2];
		}
		
		cout << desconto << endl;
	}
	return 0;
}
