#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define D(x) //cout << #x " = " << (x) << endl

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
	int g, p, s, k, e, i, j, qtd;
	
	while(scanf("%d %d", &g, &p) && (g || p)) {
		vvi gps(g, vi(p));
		
		for(auto &it : gps) 
			for(auto &it2 : it)
				cin >> it2;
				
		scanf("%d", &k);
		
		for(i = 0; i < k; i++) {
			scanf("%d", &qtd);
			
			vi pontos = vi(p, 0);
			
			for(j = 0; j < qtd; j++)
				scanf("%d", &pontos[j]);
				
			vii totais;
			
			for(j = 0; j < p; j++)
				totais.pb(ii(0, j));
			
			for(auto &it : gps) {
				for(j = 0; j < p; j++) {
					D(it[j]);
					D(totais[it[j] - 1].second);
					totais[j].first -= pontos[it[j] - 1];
				}
			}
			
			D("CAPETA");
			
			sort(totais.begin(), totais.end());
			
			D("cacetes");
			
			printf("%d", totais[0].second + 1);
			
			//for(auto &it : totais) 
			//	printf("%d -> %d\n", it.second + 1, -it.first);
			
			for(auto &it : totais) 
				if(it.second != totais[0].second && it.first == totais[0].first)
					printf(" %d", it.second + 1);	
					
			printf("\n");		
		}
	}
}
