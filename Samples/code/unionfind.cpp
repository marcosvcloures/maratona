// Tamanho máximo de n
const int maxn = 200000;
int Rank[maxn], p[maxn], n;

void init(int _n)
{
    n = _n;
    fill(Rank, Rank + n, 0);
    for (int i = 0; i < n; i++)
        p[i] = i;
}

int find(int x)
{
    return x == p[x] ? x : (p[x] = find(p[x]));
}

void unir(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    if (Rank[a] < Rank[b])
        swap(a, b);
    if (Rank[a] == Rank[b])
        ++Rank[a];
    p[b] = a;
}