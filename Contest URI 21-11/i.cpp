#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000;
int Rank[maxn], p[maxn], n;

void init(int _n) {
    n = _n;
    fill(Rank, Rank + n, 0);
    for (int i = 0; i < n; i++) p[i] = i;
}

int find(int x) {
    return x == p[x] ? x : (p[x] = find(p[x]));
}

void unir(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (Rank[a] < Rank[b]) swap(a, b);
    if (Rank[a] == Rank[b]) ++Rank[a];
    p[b] = a;
}

typedef struct tAresta {
	int ori, dest, d;
	
	bool operator<(tAresta a) const {
		return d < a.d;
	}
} tAresta;

int main() {
	int n, f, r, i, ini, j, d, custo = 0;
	tAresta fer[10000], rod[10000];
	
	scanf("%d %d %d", &n, &f, &r);
	
	init(n);
	
	for(i = 0; i < f; i++)
		scanf("%d %d %d", &fer[i].ori, &fer[i].dest, &fer[i].d);
	
	sort(fer, fer+f);
	
	for(i = 0; i < f; i++)
		if(find(fer[i].ori) != find(fer[i].dest))
			custo += fer[i].d, unir(fer[i].ori, fer[i].dest);
	
	for(i = 0; i < r; i++)
		scanf("%d %d %d", &rod[i].ori, &rod[i].dest, &rod[i].d);
	
	sort(rod, rod+r);
	
	for(i = 0; i < r; i++)
		if(find(rod[i].ori) != find(rod[i].dest))
			custo += rod[i].d, unir(rod[i].ori, rod[i].dest);
		
	printf("%d\n", custo);
	
	//printf("%d\n", grafo.Prim(0));
}