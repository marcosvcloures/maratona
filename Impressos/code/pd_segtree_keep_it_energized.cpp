#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000 // O valor aqui tem que ser >= 2 * tamanho do maior n

#define D(x) cout << #x << " = " << x << endl

int init[MAX], tree[MAX], lazy[MAX];

typedef vector<int> vi;

struct Loja {
	int l, s, c;
};

void build_tree(int node, int a, int b)
{
	if (a > b)
		return;

	// Se folha
	if (a == b)
	{
		tree[node] = 1 << 30;
		
		return;
	}

	build_tree(node * 2, a, (a + b) / 2);
	build_tree(node * 2 + 1, 1 + (a + b) / 2, b);

	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

void update_tree(int node, int a, int b, int i, int j, int value)
{
	// Se fora do intervalo - retorna
	if (a > b || a > j || b < i)
		return;

	if (a >= i && b <= j)
	{
		tree[node] = value;

		return;
	}


	// Atualiza os filhos.
	update_tree(node * 2, a, (a + b) / 2, i, j, value);
	update_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j, value);

	// Atualiza o pai.
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int query_tree(int node, int a, int b, int i, int j)
{
	// Se fora do intervalo
	if (a > b || a > j || b < i)
	{
		return 1<<30;
	}
	
	if (a >= i && b <= j)
		return tree[node];
	
	int q1 = query_tree(node * 2, a, (a + b) / 2, i, j);
	int q2 = query_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j);

	return min(q1, q2);
}

int main() {
	int n, m;
	
	scanf("%d %d", &n, &m);
	
	build_tree(1, 0, n);
	
	auto custos = vi(n);
	auto acumulado = vi(n + 1);
	
	for(auto &it : custos)
		scanf("%d", &it);
		
	acumulado[n] = 0;
	
	for(int i = n - 1; i >= 0; i--)
		acumulado[i] = acumulado[i + 1] + custos[i];
		
	auto lojas =  vector<Loja>(m);
	auto pacotes = vector<vector<pair<int, int> > >(n);
	auto alcance = vi(m);
	auto count = 0;
	
	for(auto &it : lojas) {
		scanf("%d %d %d", &it.l, &it.s, &it.c);
		
		pacotes[it.l - 1].push_back({count, it.c});
		
		auto eu = lower_bound(acumulado.rbegin(), acumulado.rend(), acumulado[it.l - 1] - it.s);
		
		alcance[count++] = distance(eu, acumulado.rend()) - 1;
	}
	
	auto pd = vi(n + 1, 1 << 30);
	
	pd[n] = 0;
	
	update_tree(1, 0, n, n, n, 0);
		
	for(int i = n - 1; i >= 0; i--) {
		for(auto pacote : pacotes[i])
			pd[i] = min(pd[i], query_tree(1, 0, n, i, alcance[pacote.first]) + pacote.second);
			
		update_tree(1, 0, n, i, i, pd[i]);
	}
	
	if(pd[0] != 1 << 30)
		cout << pd[0] << endl;
	else
		puts("-1");
}
