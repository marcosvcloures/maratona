#include <algorithm>

using namespace std;

#define MAX 1000000 // O valor aqui tem que ser >= 2 * tamanho do maior n
#define INF 1 << 28

// Não necessáriamente é um int, pode ser uma segtree de struct etc;
int init[MAX], tree[MAX], lazy[MAX];

void build_tree(int node, int a, int b)
{
    if (a > b)
        return;

    // Se folha
    if (a == b)
    {
        tree[node] = init[a];
        lazy[node] = 0;
        return;
    }

    build_tree(node * 2, a, (a + b) / 2);
    build_tree(node * 2 + 1, 1 + (a + b) / 2, b);

    // Se nó
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
    lazy[node] = 0;
}

void update_tree(int node, int a, int b, int i, int j, int value)
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

int query_tree(int node, int a, int b, int i, int j)
{
    // Se fora do intervalo
    if (a > b || a > j || b < i)
    {
        //Aqui deverá ser retornado o elemento neutro para a operação desejada
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
    if (a >= i && b <= j)
        return tree[node];


    // Se o intervalo está um pedaço em cada filho.
    int q1 = query_tree(node * 2, a, (a + b) / 2, i, j);
    int q2 = query_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j);

    // Retorna a combinação dos intervalos.
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