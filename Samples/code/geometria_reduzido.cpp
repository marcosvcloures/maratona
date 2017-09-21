typedef pair<double, double> Ponto;

bool cw(Ponto a, Ponto b, Ponto c)
{
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first) < 0;
}

// Retorna o casco convexo do conjunto de pontos p
vector<Ponto> convexHull(vector<Ponto> p)
{
    int n = p.size();
    if (n <= 1)
        return p;
    int k = 0;
    sort(p.begin(), p.end());
    vector<Ponto> q(n * 2);
    for (int i = 0; i < n; q[k++] = p[i++])
        for (; k >= 2 && !cw(q[k - 2], q[k - 1], p[i]); --k)
            ;
    for (int i = n - 2, t = k; i >= 0; q[k++] = p[i--])
        for (; k > t && !cw(q[k - 2], q[k - 1], p[i]); --k)
            ;
    q.resize(k - 1 - (q[0] == q[1]));
    return q;
}

//O dobro da área definida pelo triangulo de pontos pontos a, b e c (sem sinal).
double uArea2(Ponto a, Ponto b, Ponto c)
{
    return abs((b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first));
}

//O dobro da área definida pelo triangulo de pontos pontos a, b e c (com sinal).
double area2(Ponto a, Ponto b, Ponto c)
{
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
}

//Distância entre os pontos a e b
double dist(Ponto a, Ponto b)
{
    return hypot(a.first - b.first, a.second - b.second);
}

//Interseção de semi-retas (p1 -> p2), (p3 -> p4)
bool segIntercept(Ponto p1, Ponto p2, Ponto p3, Ponto p4)
{
    return cw(p1, p2, p3) != cw(p1, p2, p4) && cw(p3, p4, p1) != cw(p3, p4, p2);
}

//Retorna a área do polígono p
double polygonArea(vector<Ponto> p)
{
    double s = 0.0;
    for (int i = 0; i < p.size(); i++)
        s += area2(Ponto(0, 0), p[i], p[(i + 1) % p.size()]);
    return fabs(s / 2.0);
}

//Retorna a área do polígono p definido pelos pontos p[i, f]
double polygonArea2(vector<Ponto> p, int i, int f)
{
    double s = 0.0;
    Ponto primeiro = p[i];
    for (; i != f; i++)
        s += area2(Ponto(0, 0), p[i], p[(i + 1)]);
    s += area2(Ponto(0, 0), p[i], primeiro);
    return fabs(s / 2.0);
}

//Retorna a menor largura do conjunto de pontos p
double raio(vector<Ponto> p)
{
    vector<Ponto> h = convexHull(p);
    int m = h.size();
    if (m == 1)
        return 0;
    if (m == 2)
        return 0;
    int k = 1;
    while (uArea2(h[m - 1], h[0], h[(k + 1) % m]) > uArea2(h[m - 1], h[0], h[k]))
        ++k;
    double res = 10000000;
    for (int i = 0, j = k; i <= k && j < m; i++)
    {
        res = min(res, dist(h[i], h[j]));
        while (j < m && uArea2(h[i], h[(i + 1) % m], h[(j + 1) % m]) > uArea2(h[i], h[(i + 1) % m], h[j]))
        {
            res = min(res, dist(h[i], h[(j + 1) % m]));
            ++j;
        }
    }
    return res;
}

//Retorna a maior largura do conjunto de pontos p
double diametro(vector<Ponto> p)
{
    vector<Ponto> h = convexHull(p);
    int m = h.size();
    if (m == 1)
        return 0;
    if (m == 2)
        return dist(h[0], h[1]);
    int k = 1;
    while (uArea2(h[m - 1], h[0], h[(k + 1) % m]) > uArea2(h[m - 1], h[0], h[k]))
        ++k;
    double res = 0;
    for (int i = 0, j = k; i <= k && j < m; i++)
    {
        res = max(res, dist(h[i], h[j]));
        while (j < m && uArea2(h[i], h[(i + 1) % m], h[(j + 1) % m]) > uArea2(h[i], h[(i + 1) % m], h[j]))
        {
            res = max(res, dist(h[i], h[(j + 1) % m]));
            ++j;
        }
    }
    return res;
}