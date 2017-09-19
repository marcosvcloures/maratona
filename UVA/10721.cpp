#include <bits/stdc++.h>
using namespace std;

long long pd[51][51][51] = {0};

long long m;

long long chama(int u, int b, int a){
	if(pd[u][b][a] == -1){
		if(a == m - 1){
			pd[u][b][a] = chama(u - 1, b - 1, 0);
		} else {
			pd[u][b][a] = chama(u - 1, b, a + 1) + chama(u - 1, b - 1, 0);
		}
	}
	return pd[u][b][a];
}

int main(){
	long long n, k;
	
	while(cin >> n >> k >> m){
		for(int i = 0; i < 51; i++){
			for(int j = 0; j < 51; j++){
				for(int k = 0; k < 51; k++){
					if(i == 0 and j == 0){
						pd[i][j][k] = 1;
					} else if(i == 0 or j == 0){
						pd[i][j][k] = 0;
					} else {
						pd[i][j][k] = -1;
					}
				}
			}
		}
		
		cout << chama(n, k, 0) << endl;
	}

	return 0;
}
