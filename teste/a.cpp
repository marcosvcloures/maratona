#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 20000000 // O valor aqui tem que ser >= 2 * tamanho do maior n

ll tree[MAX], lazy[MAX];

void build_tree(int node, int a, int b)
{
	if (a > b)
		return;

	// Se folha
	if (a == b)
	{
		tree[node] = 0;
		lazy[node] = 0;
		return;
	}

	build_tree(node * 2, a, (a + b) / 2);
	build_tree(node * 2 + 1, 1 + (a + b) / 2, b);

	// Se nó
	tree[node] = 0;
	lazy[node] = 0;
}

void update_tree(int node, int a, int b, int i, int j, ll value)
{
	// Se fora do intervalo - retorna
	if (a > b || a > j || b < i)
		return;

	if (lazy[node] != 0)
	{
		//Atualização atrasada.
		tree[node] += lazy[node];

		// Passa lazy para filhos
		if (a != b)
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}

		//Reseta o nó
		lazy[node] = 0;
	}

	// Se o nó atual cobre todo o intervalo
	if (a >= i && b <= j)
	{
		tree[node] += value;

		if (a != b)
		{
			lazy[node * 2] += value;
			lazy[node * 2 + 1] += value;
		}

		return;
	}

	// Se tem um pedaço em cada filho.

	// Atualiza os filhos.
	update_tree(node * 2, a, (a + b) / 2, i, j, value);
	update_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j, value);

	// Atualiza o pai.
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query_tree(int node, int a, int b, int i, int j)
{
	// Se fora do intervalo
	if (a > b || a > j || b < i)
	{
		return 0;
	}

	if (lazy[node] != 0)
	{
		//Atualização atrasada.
		tree[node] += lazy[node];

		//Se não folha, passa lazy pros filhos
		if (a != b)
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}

		//Reseta o nó
		lazy[node] = 0;
	}

	// Se o nó cobre o intervalo
	if (a == b)
		return tree[node];
	
	// Se o intervalo está um pedaço em cada filho.
	int q1 = query_tree(node * 2, a, (a + b) / 2, i, j);
	int q2 = query_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j);

	// Retorna a combinação dos intervalos.
	return q1 + q2;
}

int main()
{
    ll n, m, a, b, k;

    scanf("%lld %lld", &n, &m);

    build_tree(1, 0, n - 1);

    while (m--)
        scanf("%lld %lld %lld", &a, &b, &k),
        update_tree(1, 0, n - 1, a - 1, b - 1, k);

    printf("%lld\n", query_tree(1, 0, n-1, 0, n-1));
    cout << query_tree(1, 0, n-1, 0, n-1) << endl;
}
