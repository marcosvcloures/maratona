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

    vector<Ponto> q(n * 2);

    for (int i = 0; i < n; q[k++] = p[i++])
        for (; k >= 2 && cw(q[k - 2], q[k - 1], p[i]); --k)
            ;

    for (int i = n - 2, t = k; i >= 0; q[k++] = p[i--])
        for (; k > t && cw(q[k - 2], q[k - 1], p[i]); --k)
            ;

    q.resize(k - 1 - (q[0] == q[1]));

    sort(q.begin(), q.end());

    return q;
}

int main()
{
    int n, a, b, count;

    while (scanf("%d", &n) && n)
    {
        count = 0;

        set<Ponto> entrada;

        for (int i = 0; i < n; i++)
            scanf("%d %d", &a, &b),
            entrada.insert({a, b});

        vector<Ponto> cebola;

        for(auto &it : entrada)
            cebola.push_back(it);

        while(cebola.size()) 
        {
            auto casco = convexHull(cebola);

            auto fim = set_difference(cebola.begin(), cebola.end(), casco.begin(), casco.end(), cebola.begin());

            cebola.resize(fim - cebola.begin());

            count++;
        }

        cout << (count % 2 ? "Take this onion to the lab!" : "Do not take this onion to the lab!") << endl;
    }
}