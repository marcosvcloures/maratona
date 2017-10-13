#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    string entrada;

    cin >> n;

    getline(cin, entrada);
    getline(cin, entrada);

    while (n--)
    {
        map<string, int> mapa;
        m = 0;

        while (getline(cin, entrada) && entrada != "")
        {
            if (mapa.count(entrada))
                mapa[entrada]++;
            else
                mapa[entrada] = 1;

            m++;
        }

        for (auto &it : mapa)
            printf("%s %.4lf\n", it.first.c_str(), it.second * 100.0 / m);

        if (n > 0)
            puts("");
    }
}