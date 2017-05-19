#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, i, prim, e;
	vector<pair<int, int> > fila;
	map<int, int> pos;
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++)
		scanf("%d", &e), pos[e] = i, fila.push_back(make_pair(e, 1));
	
	scanf("%d", &m);
	
	while(m--) 
		scanf("%d", &e), fila[pos[e]].second = 0;
	
	for(i = 0, prim = 1; i < n; i++)
		if(fila[i].second) {
			if(prim)
				printf("%d", fila[i].first), prim = 0;
			else
				printf(" %d", fila[i].first);
		}
	
	printf("\n");
}