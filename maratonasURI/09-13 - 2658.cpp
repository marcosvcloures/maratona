#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000 // O valor aqui tem que ser >= 4 * tamanho do maior n
#define ELEMENTO_NEUTRO 0

vector<int> freq(9);

struct No
{
    int F[9] = {0};

    No(int a)
    {
        F[a] = 1;
    }

    No() {}

    No operator+(const No &a) const
    {
        No novo;

        for (int i = 0; i < 9; i++)
            novo.F[i] = F[i] + a.F[i];

        return novo;
    }

    No operator=(const No &a)
    {
        for (int i = 0; i < 9; i++)
            this->F[i] = a.F[i];

        return *this;
    }

    void update(int max)
    {
        int temp[9];

        for (int i = 0; i < 9; i++)
            temp[i] = F[i];

        for (int i = 0; i < 9; i++)
            F[(i + max) % 9] = temp[i];
    }

    int val()
    {
        int max = 0;

        for (int i = 1; i < 9; i++)
            if (F[i] >= F[max])
                max = i;

        return max;
    }
};

int init[MAX], lazy[MAX];
No tree[MAX];

void build_tree(int node, int a, int b)
{
    if (a > b)
        return;

    if (a == b)
    {
        tree[node] = No(init[a]);
        lazy[node] = 0;
        return;
    }

    build_tree(node * 2, a, (a + b) / 2);
    build_tree(node * 2 + 1, 1 + (a + b) / 2, b);

    //Atualização do pai - verificar operação
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
    lazy[node] = 0;
}

void update_tree(int node, int a, int b, int i, int j, int val)
{
    //Atualização atrasada - verificar operação
    if (lazy[node] != 0)
    {
        tree[node].update(lazy[node]);

        if (a != b)
        {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }

        lazy[node] = 0;

        return;
    }

    if (a > b || a > j || b < i)
        return;

    //Atualização do nó - verificar operação
    if (a >= i && b <= j)
    {
        tree[node].update(val);

        if (a != b)
        {
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }

        return;
    }

    update_tree(node * 2, a, (a + b) / 2, i, j, val);
    update_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j, val);

    //Atualização do pai - verificar operação
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query_tree(int node, int a, int b, int i, int j)
{
    if (a > b || a > j || b < i)
    {
        return 0;
    }

    //Atualização atrasada - verificar operação
    if (lazy[node] != 0)
    {
        tree[node].update(lazy[node]);

        if (a != b)
        {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }

        lazy[node] = 0;
    }

    if (a == i && b == j && a == b)
        return tree[node].val();

    int q1 = query_tree(node * 2, a, (a + b) / 2, i, j);
    int q2 = query_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j);

    //Retorno da arvore - verificar operação
    return q1 + q2;
}

void most_freq(int node, int a, int b, int i, int j)
{
    if (a > b || a > j || b < i)
    {
        return;
    }

    //Atualização atrasada - verificar operação
    if (lazy[node] != 0)
    {
        tree[node].update(lazy[node]);

        if (a != b)
        {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }

        lazy[node] = 0;
    }

    if (a >= i && b <= j)
    {
        for (int i = 0; i < 9; i++)
            freq[i] += tree[node].F[i];

        return;
    }

    most_freq(node * 2, a, (a + b) / 2, i, j);
    most_freq(1 + node * 2, 1 + (a + b) / 2, b, i, j);
}

int main()
{
    int n, q, a, b;

    scanf("%d %d", &n, &q);

    fill(init, init + n, 1);

    build_tree(1, 0, n - 1);

    while (q--)
    {
        scanf("%d %d", &a, &b);

        int most = 0;

        for (auto &it : freq)
            it = 0;

        most_freq(1, 0, n - 1, a, b);

        for (int i = 1; i < 9; i++)
            if (freq[i] >= freq[most])
                most = i;

        update_tree(1, 0, n - 1, a, b, most);
    }

    for (int i = 0; i < n; i++)
        printf("%d\n", query_tree(1, 0, n - 1, i, i));
}
