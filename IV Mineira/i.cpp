#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

typedef pair<double, double> Ponto;

bool cw(const Ponto &a, const Ponto &b, const Ponto &c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) < 0;
}

vector<Ponto> convexHull(vector<Ponto> p) {
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

double area(const Ponto &a, const Ponto &b, const Ponto &c) {
    return abs((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x));
}

double dist(const Ponto &a, const Ponto &b) {
    return hypot(a.x - b.x, a.y - b.y);
}

double raio(const vector<Ponto> &p) {
    vector<Ponto> h = convexHull(p);
    int m = h.size();
    if (m == 1)
        return 0;
    if (m == 2)
        return 0;
    int k = 1;
    while (area(h[m - 1], h[0], h[(k + 1) % m]) > area(h[m - 1], h[0], h[k]))
        ++k;
    double res = 10000000;
    for (int i = 0, j = k; i <= k && j < m; i++) {
        res = min(res, dist(h[i], h[j]));
        while (j < m && area(h[i], h[(i + 1) % m], h[(j + 1) % m]) > area(h[i], h[(i + 1) % m], h[j])) {
            res = min(res, dist(h[i], h[(j + 1) % m]));
            ++j;
        }
    }
    return res;
}

int main() {
    vector<Ponto> p;
    int n, i;
	double x, y;
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++) {
		scanf("%lf %lf", &x, &y);
		
		p.push_back(Ponto(x, y));
	}
	
    printf("%.2lf\n", raio(p)/2.0);
}