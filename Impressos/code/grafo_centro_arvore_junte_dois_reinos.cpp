#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi a_esq, a_dir;
vi grau_esq, grau_dir, tam_esq, tam_dir, dist_esq, dist_dir;
int centro_esq, centro_dir;

int dfs_esq(int atual, int pai) {
	int r = 0;
	
	for(auto &it : a_esq[atual])
		if(it != pai)
			r = max(r, dfs_esq(it, atual));
		
	return tam_esq[atual] = r + 1;
}

int dfs_dir(int atual, int pai) {
	int r = 0;
	
	for(auto &it : a_dir[atual])
		if(it != pai)
			r = max(r, dfs_dir(it, atual));
		
	return tam_dir[atual] = r + 1;
}

void calc_dist_esq(int atual, int maior) {
	dist_esq[atual] = maior;
	
	for(auto &it : a_esq[atual])
		if(dist_esq[it] == -1 && it != centro_esq)
			calc_dist_esq(it, maior + 1);
}

void calc_dist_dir(int atual, int maior) {
	dist_dir[atual] = maior;
	
	for(auto &it : a_dir[atual])
		if(dist_dir[it] == -1 && it != centro_dir)
			calc_dist_dir(it, maior + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	long long soma;
	int n, q, i, a, b, maxi, max_dir, max_esq;
	
	while(cin >> n >> q) {	
		multiset<int> valores_esq, valores_dir;
		
		a_esq = vvi(n);
		a_dir = vvi(q);
		
		grau_esq = vi(n);
		grau_dir = vi(q);
		
		tam_esq = vi(n);
		tam_dir = vi(q);
		
		dist_esq = vi(n, -1);
		dist_dir = vi(q, -1);
		
		for(i = 1; i < n; i++)
			cin >> a >> b, 
			a--, 
			b--,
			a_esq[a].pb(b),
			grau_esq[a]++,
			a_esq[b].pb(a),
			grau_esq[b]++;
			
		for(i = 1; i < q; i++)
			cin >> a >> b, 
			a--, 
			b--,
			a_dir[a].pb(b),
			grau_dir[a]++,
			a_dir[b].pb(a),
			grau_dir[b]++;
		
		queue<int> fila;
		
	// Centro da arvore esquerda
		for(i = 0; i < n; i++) 
			if(a_esq[i].size() <= 1) // <= por árvore vazia!
				fila.push(i);
				
		while(fila.size() > 1) {
			for(auto &it : a_esq[fila.front()]) {
				grau_esq[it]--;
				
				if(grau_esq[it] == 1)
					fila.push(it);
			}
			
			fila.pop();
		}
		
		centro_esq = fila.front();
		fila.pop();

	// Centro da arvore direita
		for(i = 0; i < q; i++) 
			if(a_dir[i].size() <= 1) // <= por árvore vazia!
				fila.push(i);
				
		while(fila.size() > 1) {
			for(auto &it : a_dir[fila.front()]) {
				grau_dir[it]--;
				
				if(grau_dir[it] == 1)
					fila.push(it);
			}
			
			fila.pop();
		}
		
		centro_dir = fila.front();
		fila.pop();
		
		dfs_esq(centro_esq, -1);
		dfs_dir(centro_dir, -1);
		
		valores_esq.insert(0);
		for(auto &it : a_esq[centro_esq])
			valores_esq.insert(-tam_esq[it]);
			
		for(auto &it : a_esq[centro_esq]) {
			valores_esq.erase(valores_esq.find(-tam_esq[it]));
			
			calc_dist_esq(it, -(*valores_esq.begin()) + 1);
			
			valores_esq.insert(-tam_esq[it]);
		}
		
		dist_esq[centro_esq] = -(*valores_esq.begin());
			
		valores_dir.insert(0);
		for(auto &it : a_dir[centro_dir])
			valores_dir.insert(-tam_dir[it]);
			
		for(auto &it : a_dir[centro_dir]) {
			valores_dir.erase(valores_dir.find(-tam_dir[it]));
			
			calc_dist_dir(it, -(*valores_dir.begin()) + 1);
			
			valores_dir.insert(-tam_dir[it]);
		}
		
		dist_dir[centro_dir] = -(*valores_dir.begin());
		
		soma = maxi = max_esq = max_dir = 0;
		
		for(auto &it : dist_esq)
			max_esq = max(max_esq, it);
			
		for(auto &it : dist_dir)
			max_dir = max(max_dir, it);
			
		maxi = max(max_esq, max_dir);
			
		vi v_esq(max_esq + 1, 0), v_dir(max_dir + 1, 0);
		
		for(auto &i : dist_esq)
			v_esq[i]++;
			
		for(auto &i : dist_dir)
			v_dir[i]++;
		
		for(int i = 0; i <= max_esq; i++)
			for(int j = 0; j <= max_dir; j++)
				if(v_esq[i] && v_dir[j])
					soma += v_esq[i] * v_dir[j] * max(i + j + 1, maxi);
		
		printf("%.3lf\n", 1.0 * soma / (q * n));
	}
}
