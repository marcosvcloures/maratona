#include <bits/stdc++.h>
using namespace std;

int pd[31][1001];
int custos[31];
int lucros[31];
pair<int, int> coords[31];

int mochila(int bau, int tempo){
	if(pd[bau][tempo] == -1){
		if(tempo - custos[bau] < 0){
			pd[bau][tempo] = mochila(bau - 1, tempo);
		} else {
			pd[bau][tempo] = max(mochila(bau - 1, tempo), mochila(bau - 1, tempo - custos[bau]) + lucros[bau]);
		}
	}
	return pd[bau][tempo];
}

void printM(int bau, int tempo, int acm){
	if(bau <= 0 or tempo <= 0){
		cout << acm << endl;
		return;
	}
	
	if(pd[bau][tempo] == pd[bau - 1][tempo]){
		printM(bau - 1, tempo, acm);
	} else {
		printM(bau - 1, tempo - custos[bau], acm + 1);
		cout << coords[bau].first << " " << coords[bau].second << endl;
	}
	return;
}

int main(){
	
	int t, w, n;
	int prim = 1;
	
	while(cin >> t >> w >> n){
		
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= t; j++){
				pd[i][j] = -1;
				if(j == 0 or i == 0){
					pd[i][j] = 0;
				}
			}
		}
		pd[1][1] = 1;
		
		
		for(int i = 1; i <= n; i++){
			cin >> coords[i].first;
			cin >> coords[i].second;
			
			custos[i] = 3 * w * coords[i].first;
			lucros[i] = coords[i].second;
			pd[i][0] = 0;
		}
		if(!prim){
			cout << endl;
		} else {
			prim = 0;
		}
		cout << mochila(n , t) << endl;	
		
		int u = 0;
		
		printM(n, t, u);
	}
	
	return 0;
}
