#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vi grafo[100000];
int n, m, vis[100000] = {0}, r = 0, a, b;

void visita(int n) {
	if(vis[n])
		return;
	
	vis[n] = 1;
	
	for(int i = 0; i < grafo[n].size(); i++)
		visita(grafo[n][i]);
}

int main() {
	scanf("%d %d", &n, &m);
	
	while(m--) 
		scanf("%d %d", &a, &b), grafo[a-1].push_back(b-1), grafo[b-1].push_back(a-1);
	
	while(n--)
		if(!vis[n])
			r++, visita(n);

	printf("%d\n", r);
}