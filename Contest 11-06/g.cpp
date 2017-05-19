#include <bits/stdc++.h>

using namespace std;

#define MAX 3000000 // O valor aqui tem que ser >= 2 * tamanho do maior n
#define INF 0x7fffffff

int init[MAX] = {0}, tree[MAX], truncate[MAX], lazy[MAX];

void build_tree(int node, int a, int b) {
    if(a > b)
		return;

    if(a == b) {
        tree[node] = init[a];
		truncate[node] = 0;
		lazy[node] = 0;
        return;
    }

    build_tree(node*2, a, (a+b)/2);
    build_tree(node*2+1, 1+(a+b)/2, b);

    tree[node] = tree[node*2] + tree[node*2+1];
	lazy[node] = 0;
	truncate[node] = 0;
}

void update_tree(int node, int a, int b, int i, int j, int value) {
	// Operação de atualização:
	// O modo de atualização depende do modo das queries
	// Caso as queries adicionem "value" ao valor atual, use tree[node] += lazy[node];
	// Caso as queries mudem o valor atual para "value", lazy deverá ser um struct, com o proximo valor e uma flag identificando se é lazy ou não.
	// Cuidado para a operação de atualização não botar o valor de lazy como 0, pois caso isso aconteça, lazy também deverá ser um struct.
    //printf("update:\nn: %d, a: %d, b: %d, value: %d, trun: %d, lazy: %d, tree: %d\n", node, a, b, value, truncate[node], lazy[node], tree[node]);
	
	if(truncate[node] != 0) {
		//Atualização atrasada.
		tree[node] = 0;

		if(a != b) {
			//Atualização atrasada dos filhos.
			truncate[node*2] = 1;
			truncate[node*2+1] = 1;
			lazy[node*2] = 0;
			lazy[node*2+1] = 0;
		}

		//Reseta o nó
		truncate[node] = 0;
	}
	
	if(lazy[node] != 0) {
		//Atualização atrasada.
		tree[node] += lazy[node];

		if(a != b) {
			//Atualização atrasada dos filhos.
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}

		//Reseta o nó
		lazy[node] = 0;
	}

    if(a > b || a > j || b < i)
        return;

    if(a >= i && b <= j) {
		tree[node] += value;

		if(a != b) {
			//Marca filhos para futura atualização atrasada.
			lazy[node*2] += value;
			lazy[node*2+1] += value;
		}

        return;
    }

    update_tree(node*2, a, (a+b)/2, i, j, value);
    update_tree(1+node*2, 1+(a+b)/2, b, i, j, value);

	//Atualização do pai
	//
	//Operações comuns:
	//tree[node] = {Maximo: max(x, y); Minimo: min(x, y); Multiplicação: x * y; Soma: x + y; Diferença: x - y};
	//onde x = tree[node*2] e y = tree[node*2+1]

    tree[node] = tree[node*2] + tree[node*2+1];
}

// Caso não seja uma segtree de inteiros, o valor de retorno deverá ser mudado aqui!
int query_tree(int node, int a, int b, int i, int j) {
    if(a > b || a > j || b < i) {
		//Aqui deverá ser retornado o elemento neutro para a operação desejada
		//
		//Operações comuns:
		//Maximo: -INF, Minimo: INF, Multiplicação: 1, Soma/Diferença: 0
		//Lembrando que, caso não seja uma segtree de inteiros, o retorno deverá ser o elemento neutro do tipo utilizado
		return 0;
	}

//	printf("query:\nn: %d, a: %d, b: %d, trun: %d, lazy: %d, tree: %d\n", node, a, b, truncate[node], lazy[node], tree[node]);
	
	if(truncate[node] != 0) {
		//Atualização atrasada.
		tree[node] = 0;

		if(a != b) {
			//Atualização atrasada dos filhos.
			truncate[node*2] = 1;
			truncate[node*2+1] = 1;
			lazy[node*2] = 0;
			lazy[node*2+1] = 0;
		}

		//Reseta o nó
		truncate[node] = 0;
	}
	
	if(lazy[node] != 0) {
		//Atualização atrasada.
		tree[node] += lazy[node];

		if(a != b) {
			//Atualização atrasada dos filhos.
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}

		//Reseta o nó
		lazy[node] = 0;
	}


    if(a >= i && b <= j)
        return tree[node];

	//Lembrando que, caso não seja uma segtree de inteiros, "q1" e "q2" deverá ser do tipo utilizado
    int q1 = query_tree(node*2, a, (a+b)/2, i, j);
    int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j);

	//Retorno da arvore
	//A operação deverá ser a mesma da atualização do pai
	//
	//Operações comuns:
	//return {Maximo: max(q1, q2); Minimo: min(q1, q2); Multiplicação: q1 * q2; Soma: q1 + q2; Diferença: q1 - q2};
    return q1 + q2;
}

int main() {
	long long int t, n, k, qtd, i, j, entrada, atual, possivel, a, b;
	vector<int> vetores[100001];

	build_tree(1, 0, 1000001);

	scanf("%lld", &t);

	while(t--) {
		qtd = 0;
		possivel = 1;

		scanf("%lld %lld", &n, &k);

		for(i = 0, atual = 0; i < n; i++, atual++, atual %= k) {
			scanf("%lld", &entrada);

			vetores[atual].push_back(entrada);
		}

		for(i = 0; i < k; i++) {
			truncate[1] = 1;
			lazy[1] = 0;
			
			for(j = 0; j < vetores[i].size(); j++) {
				//printf("query_tree(%d, %d) = %d\n", vetores[i][j], vetores[i][j], query_tree(1, 0, vetores[i].size(), vetores[i][j], vetores[i][j]));
				qtd += query_tree(1, 0, vetores[i][j]+1, vetores[i][j], vetores[i][j]);
				//printf("qtd = %d\n", qtd);
				//printf("update_tree(0, %d) +1\n", vetores[i][j]);
				update_tree(1, 0, vetores[i][j], 0, vetores[i][j]-1, 1);
			}

			sort(vetores[i].begin(), vetores[i].end());
		}

		a = vetores[0][0];
		for(i = 1, atual = 1%k; i < n; i++, atual++, atual %= k) {
			b = vetores[atual][i/k];

			if(b < a) {
				possivel = 0;
				break;
			}
		}

		if(possivel)
			printf("%lld\n", qtd);
		else
			puts("impossivel");

		for(i = 0; i < k; i++)
			vetores[i].clear();
	}
}
