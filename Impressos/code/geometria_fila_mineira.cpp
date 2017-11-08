#include <bits/stdc++.h>

#define D(x) cout << #x << " = " << x << endl

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

#define pb push_back

vii pontos;

double f(double theta) 
{
    double y_max = -1e100, y_min = 1e100, y;
    double sint = sin(theta), cost = cos(theta);

    for(auto &it : pontos) {
        y = -sint * it.first + cost * it.second;

        y_max = max(y, y_max);
        y_min = min(y, y_min);
    }

    return (y_max - y_min) / 2;
}

double gss(double a, double b)
{
    double r = (sqrt(5) - 1) / 2; //=.618...=golden ratio-1
    double x1 = b - r * (b - a), x2 = a + r * (b - a);
    double f1 = f(x1), f2 = f(x2);

    // while(fabs(f1 - f2) > e)
    for(int it = 0; it < 100; it++)
    {
        //change to > to find maximum
        if (f1 < f2)
        {
            b = x2;
            x2 = x1;
            f2 = f1;
            x1 = b - r * (b - a);
            f1 = f(x1);
        }
        else
        {
            a = x1;
            x1 = x2;
            f1 = f2;
            x2 = a + r * (b - a);
            f2 = f(x2);
        }
    }

    // return f1;
    return (f2 + f1) / 2;
}

int main()
{
    int n;

    cin >> n;
    
    pontos = vii(n);

    for(auto &it : pontos)
        cin >> it.first >> it.second;

    auto resp = gss(0, 90);
    resp = min(resp, gss(90, 180));
    resp = min(resp, gss(180, 270));
    resp = min(resp, gss(270, 360));

    printf("%.2lf\n", resp);
}