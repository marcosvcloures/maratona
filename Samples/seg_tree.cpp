#include <algorithm>

using namespace std;

#define MAX 1000000 // O valor aqui tem que ser >= 2 * tamanho do maior n
#define INF 0x7fffffff

int init[MAX], tree[MAX]; // Não necessáriamente é um int, pode ser uma segtree de struct etc;
int lazy[MAX]; // Marca se o nó deve ser atualizado ou não, pode ser um struct, dependendo da operação de atualização.
 
void build_tree(int node, int a, int b) {
    if(a > b) 
		return;
     
    if(a == b) {
        tree[node] = init[a];
		// Reseta o nó.
		lazy[node] = 0;
        return;
    }
     
    build_tree(node*2, a, (a+b)/2);
    build_tree(node*2+1, 1+(a+b)/2, b);
     
	//Atualização do pai
	//
    //tree[node] = {Maximo: max(x, y); Minimo: min(x, y); Multiplicação: x * y; Soma: x + y; Diferença: x - y};
	//onde x = tree[node*2] e y = tree[node*2+1]
	
    tree[node] = tree[node*2] + tree[node*2+1];
	// Reseta o nó.
	lazy[node] = 0;
}

void update_tree(int node, int a, int b, int i, int j, int value) {
	// Operação de atualização:
	// O modo de atualização depende do modo das queries
	// Caso as queries adicionem "value" ao valor atual, use tree[node] += lazy[node];
	// Caso as queries mudem o valor atual para "value", lazy deverá ser um struct, com o proximo valor e uma flag identificando se é lazy ou não.
	// Cuidado para a operação de atualização não botar o valor de lazy como 0, pois caso isso aconteça, lazy também deverá ser um struct.
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

/* 

Uso:

Assumindo que "n" é o numero de termos que o segmento tem
Inicialize "init" com os valores iniciais:

*	for(i = 0; i < n; scanf("%d", val), i++)
*      init[i] = val;

E mande construir a arvore:

*   build_tree(1, 0, n-1);

Para atualizar a arvore:
 
*   update_tree(1, 0, n-1, inicio, fim, val);
*   Onde inicio é a posição inicial do segmento desejado e fim é a posição final do mesmo
*	e val é o quanto você quer alterar os valores desse seguimento

Para fazer queries

*   query_tree(1, 0, n-1, inicio, fim);
*	Onde inicio é a posição inicial do segmento desejado e fim é a posição final do mesmo
*	o retorno terá o mesmo tipo que os dados guardados na arvore e será o resultado do segmento pesquisado

*/