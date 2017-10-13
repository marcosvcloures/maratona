#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

#define D(x) cout << #x " = " << x << endl;

vvii grafo;

vi dfs_num, dfs_low, dfs_parent, S, visited, pontes;
int dfsNC, root, rootChildren;

void tarjan(int u) {
	dfs_low[u] = dfs_num[u] = dfsNC++;
	
	S.push_back(u);
	
	visited[u] = 1;
	
	for(auto &it : grafo[u]) {
		if(dfs_num[it.first] == -1) {
			dfs_parent[it.first] = u;
			
			if(u == root)
				rootChildren++;
			
			tarjan(it.first);
			
			if(dfs_low[it.first] > dfs_num[u])
				pontes[it.second] = 1;
				
			dfs_low[u] = min(dfs_low[u], dfs_low[it.first]);
		}
		else if(it.first != dfs_parent[u])
			dfs_low[u] = min(dfs_low[u], dfs_low[it.first]);
	}
}

int dfs1(int atual, int destino) {
	if(atual == destino)
		return 1;
		
	if(visited[atual])
		return 0;
		
	visited[atual] = 1;
		
	int r = 0;
	
	for(auto &it : grafo[atual])
		if(pontes[it.second])
			r += dfs1(it.first, destino);
		
	return r;
}

int main() 
{
	int r, c, q, a, b, i;
	
	while(scanf("%d %d %d", &r, &c, &q) && r) {
		grafo = vvii(r);
		
		pontes = vi(c + 1, 0);
		
		while(c--)
			scanf("%d %d", &a, &b),
			grafo[a-1].push_back({b-1, c}),
			grafo[b-1].push_back({a-1, c});
			
		dfs_num = vi(r, -1);
		dfs_parent = vi(r, -1);
		dfs_low = vi(r, 0);
		visited = vi(r, 0);
		dfsNC = 0;
			
		for(i = 0; i < r; i++)
			if(dfs_num[i] == -1) 
				root = i, rootChildren = 0, tarjan(i);
		
		while(q--) {
			visited = vi(r, 0);
			scanf("%d %d", &a, &b);
			printf("%c\n", dfs1(a - 1, b - 1) ? 'Y' : 'N');
		}
		puts("-");
	}
}
