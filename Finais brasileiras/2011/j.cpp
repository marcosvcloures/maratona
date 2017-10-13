#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000 // O valor aqui tem que ser >= 2 * tamanho do maior n

#define D(x) //cout << #x " = " << x << endl;

// Não necessáriamente é um int, pode ser uma segtree de struct etc;
long long init[MAX], B, p;
pair<long long, int> tree[MAX], lazy[MAX];

int modPow(long long a, long long b, long long m)
{
    long long res = 1;
    for (; b > 0; b >>= 1)
    {
        if (b & 1)
            res = (long long)res * a % m;
        a = (long long)a * a % m;
    }
    return res;
}

void build_tree(int node, int a, int b)
{
	if (a > b)
		return;

	// Se folha
	if (a == b)
	{
		tree[node] = { init[a], 1 };
		return;
	}

	build_tree(node * 2, a, (a + b) / 2);
	build_tree(node * 2 + 1, 1 + (a + b) / 2, b);

	// Se nó
	tree[node] = { 
		(tree[node * 2 + 1].first + (modPow(B, tree[node * 2 + 1].second, p) * tree[node * 2].first) % p) % p, 
		tree[node * 2].second + tree[node * 2 + 1].second 
	};
}

void update_tree(int node, int a, int b, int i, int j, long long value)
{
	// Se fora do intervalo - retorna
	if (a > b || a > j || b < i)
		return;

	// Se o nó atual cobre todo o intervalo
	if (a >= i && b <= j)
	{
		tree[node] = { value, 1 };

		return;
	}

	update_tree(node * 2, a, (a + b) / 2, i, j, value);
	update_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j, value);

	// Atualiza o pai.
	tree[node] = { 
		(tree[node * 2 + 1].first + (modPow(B, tree[node * 2 + 1].second, p) * tree[node * 2].first) % p) % p, 
		tree[node * 2].second + tree[node * 2 + 1].second 
	};
	
	D(a);
	D(b);
	D(tree[node * 2 + 1].first);
	D(tree[node * 2 + 1].second);
	D(tree[node * 2].first);
	D(tree[node].first);
	D(tree[node].second);
}

pair<long long, int> query_tree(int node, int a, int b, int i, int j)
{
	// Se fora do intervalo
	if (a > b || a > j || b < i)
	{
		//Aqui deverá ser retornado o elemento neutro para a operação desejada
		return { 0, 0 };
	}

	// Se o nó cobre o intervalo
	if (a >= i && b <= j) {
		D(a);
		D(b);
		D(tree[node].first);
		D(tree[node].second);
		return tree[node];
	}
	
	// Se o intervalo está um pedaço em cada filho.
	auto q1 = query_tree(node * 2, a, (a + b) / 2, i, j);
	auto q2 = query_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j);

	// Retorna a combinação dos intervalos.
	return { 
		(q2.first + (modPow(B, q2.second, p) * q1.first) % p) % p, 
		q1.second + q2.second 
	};
}

int main() {
	long long n, q, ini, fim;
	char op;
	
	while(scanf("%lld %lld %lld %lld", &B, &p, &n, &q) && B) {
		fill(init, init + n + 100, 0);
		
		build_tree(1, 0, n-1);
		
		while(q--) {
			scanf(" %c %lld %lld", &op, &ini, &fim);
			
			if(op == 'E') 
				update_tree(1, 0, n-1, ini - 1, ini - 1, fim);
			else
				printf("%lld\n", query_tree(1, 0, n-1, ini-1, fim-1).first);
		}
		
		puts("-");
	}
}
