#include <bits/stdc++.h>

using namespace std;

#define D(x) cout << #x << " = " << x << endl;

typedef pair<int, int> Ponto;

//O dobro da área definida pelo triangulo de pontos pontos a, b e c (com sinal).
long long area2(Ponto &a, Ponto &b, Ponto &c) {
    return (long long) (b.first - a.first) * (c.second - a.second) - (long long) (b.second - a.second) * (c.first - a.first);
}

//Retorna a área do polígono p definido pelos pontos p[i, f]
long long polygonArea2(vector<Ponto> &p, int i, int f) {
    long long s = 0.0;

    Ponto& primeiro = p[i];
    Ponto origem = Ponto(0, 0);

    for (; i != f; i = (i + 1) % p.size())
        s += area2(origem, p[i], p[(i + 1) % p.size()]);

    s += area2(origem, p[i], primeiro);

    return s;
}

long long corta(vector<Ponto> &p, long long &areaTot) {
    int atual = 0;
    int k = 0;
    int m = p.size();

    long long area = 0, areaVelha = 0;
    long long resp = 1ll<<62;

    for (atual = 0; atual < m; atual++) {
        while (true) {
            if (2 * area > areaTot) {
                areaVelha = area - area2(p[atual], p[(m + k - 1) % m], p[k]);

                resp = min(resp, max(areaTot - area, min(areaVelha, areaTot - areaVelha)));

                break;
            }

            k = (k + 1) % m;

            area += area2(p[atual], p[(m + k - 1) % m], p[k]);
        }

        area -= area2(p[atual], p[(atual + 1) % m], p[k]);
    }

    return resp;
}

int main() {
    int n;

    scanf("%d", &n);

    vector<Ponto> pontos(n);

    for (auto &it : pontos)
        scanf("%d %d", &it.first, &it.second);

    auto area = polygonArea2(pontos, 0, pontos.size() - 1);
    auto resp = corta(pontos, area);

    printf("%lld %lld\n", area - resp, resp);

    return 0;
}