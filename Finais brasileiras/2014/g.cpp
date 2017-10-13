#include <bits/stdc++.h>

using namespace std;

const int MAXN1 = 60000, MAXN2 = 60000, MAXM = 200000;
int n1, n2, edges, last[MAXN1], prevs[MAXM], head[MAXM], matching[MAXN2], dist[MAXN1], Q[MAXN1], used[MAXN1], vis[MAXN1];

typedef pair<int, int> ii;

void init(int _n1, int _n2)
{
    n1 = _n1;
    n2 = _n2;
    edges = 0;
    fill(last, last + n1, -1);
}

void addAresta(int u, int v)
{
    head[edges] = v;
    prevs[edges] = last[u];
    last[u] = edges++;
}

void bfs()
{
    fill(dist, dist + n1, -1);
    int sizeQ = 0;
    for (int u = 0; u < n1; ++u)
    {
        if (!used[u])
        {
            Q[sizeQ++] = u;
            dist[u] = 0;
        }
    }
    for (int i = 0; i < sizeQ; i++)
    {
        int u1 = Q[i];
        for (int e = last[u1]; e >= 0; e = prevs[e])
        {
            int u2 = matching[head[e]];
            if (u2 >= 0 && dist[u2] < 0)
            {
                dist[u2] = dist[u1] + 1;
                Q[sizeQ++] = u2;
            }
        }
    }
}

bool dfs(int u1)
{
    vis[u1] = true;
    for (int e = last[u1]; e >= 0; e = prevs[e])
    {
        int v = head[e];
        int u2 = matching[v];
        if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2))
        {
            matching[v] = u1;
            used[u1] = true;
            return true;
        }
    }
    return false;
}

int maxMatching()
{
    fill(used, used + n1, false);
    fill(matching, matching + n2, -1);
    for (int res = 0;;)
    {
        bfs();
        fill(vis, vis + n1, false);
        int f = 0;
        for (int u = 0; u < n1; ++u)
            if (!used[u] && dfs(u))
                ++f;
        if (!f)
            return res;
        res += f;
    }
}

int main() {
	int n, i, j, a, b;
	map<ii, int> pontos;
	
	vector<ii> validos;
	
	for(i = -5; i <= 5; i++)
		for(j = -5; j <= 5; j++)
			if(hypot(i, j) <= 5 && (i || j))
				validos.push_back(ii(i, j));
	
	while(scanf("%d", &n) > 0) {
		pontos.clear();
		
		for(i = 0; i < n; i++) 
			scanf("%d %d", &a, &b), pontos[ii(a, b)] = i;
			
		init(n + 1, n + 1);
		
		for(auto &it : pontos)
			for(auto &dif : validos) {
				auto x = it.first.first + dif.first;
				auto y = it.first.second + dif.second;
				
				if(pontos.count(ii(x, y)))
					addAresta(it.second, pontos[ii(x, y)]);	
			}
			
		printf("%d\n", maxMatching() / 2);
	}
}
