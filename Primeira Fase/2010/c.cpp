#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define D(x) cout << #x " = " << (x) << endl

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int fluxo;
int valores[50];

vector<set<int> > dir, esq;

int main() {
	int n, i;
	
	while(scanf("%d %d", &n, &fluxo) && (n || fluxo)) {
		esq = vector<set<int> >(n+2);
		dir = vector<set<int> >(n+2);
		
		for(i = 0; i < n; i++)
			scanf("%d", &valores[i]);
			
		dir[n].insert(fluxo);
		esq[0].insert(fluxo);
		
		for(i = 1; i <= n; i++) {
			for(auto &it : esq[i - 1])
				esq[i].insert(it + valores[i - 1]),
				esq[i].insert(it - valores[i - 1]);
				
			for(auto &it : dir[n - i + 1])
				dir[n - i].insert(it + valores[n - i]),
				dir[n - i].insert(it - valores[n - i]);
		}
		
		vi val;
		vi resp(n, 0);
		
		if(esq[n].count(0) == 0) {
			puts("*");
			goto prox;
		}
		
		val.pb(0);
		
		for(i = 0; i <= n / 2; i++) {
			vi nval;
			
			for(auto &it : val) {
				if(dir[i + 1].count(it - valores[i])) {
					nval.pb(it - valores[i]);
					resp[i] |= 1;
				}
				if(dir[i + 1].count(it + valores[i])) {
					nval.pb(it + valores[i]);
					resp[i] |= 2;
				}
			}
			
			val = nval;
		}
		
		val.clear();
		
		val.pb(0);
		
		for(i = 0; i <= n / 2; i++) {
			vi nval;
			
			for(auto &it : val) {
				if(esq[n - i - 1].count(it - valores[n - i - 1])) {
					nval.pb(it - valores[n - i - 1]);
					resp[n - i - 1] |= 1;
				}
				if(esq[n - i - 1].count(it + valores[n - i - 1])) {
					nval.pb(it + valores[n - i - 1]);
					resp[n - i - 1] |= 2;
				}
			}
			
			val = nval;
		}
		
		for(i = 0; i < n; i++)
			printf("%c", resp[i] == 1 ? '-' : resp[i] == 2 ? '+' : '?');
		printf("\n");
		
		prox:;
	}
}
