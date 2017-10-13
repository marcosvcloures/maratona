#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> Ponto;

bool cw(Ponto a, Ponto b, Ponto c)
{
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first) < 0;
}

vector<Ponto> convexHull(vector<Ponto> p)
{
    int n = p.size();

    if (n <= 1)
        return p;

    int k = 0;

    sort(p.begin(), p.end());

    vector<Ponto> q(n * 2);

    for (int i = 0; i < n; q[k++] = p[i++])
        for (; k >= 2 && cw(q[k - 2], q[k - 1], p[i]); --k)
            ;

    for (int i = n - 2, t = k; i >= 0; q[k++] = p[i--])
        for (; k > t && cw(q[k - 2], q[k - 1], p[i]); --k)
            ;

    q.resize(k - 1 - (q[0] == q[1]));

    return q;
}

int main()
{
    int n;
    double resp;

    while (scanf("%d", &n) && n)
    {
        vector<Ponto> entrada(n);

        for (auto &it : entrada)
            scanf("%lf %lf", &it.first, &it.second);

        auto casco = convexHull(entrada);

        resp = hypot(casco.rbegin()->first - casco.begin()->first, casco.rbegin()->second - casco.begin()->second);

        for(int i = 1; i < casco.size(); i++)
            resp += hypot(casco[i].first - casco[i-1].first, casco[i].second - casco[i-1].second);

        printf("Tera que comprar uma fita de tamanho %.2lf.\n", resp);
    }
}