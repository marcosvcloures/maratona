#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    while (cin >> n)
    {
        int xabla[5000];

        int a;

        for (int i = 0; i < n; i++)
            cin >> xabla[i];

        sort(xabla, xabla + n);

        xabla[n] = xabla[0] + 24;

        int cont = 0;
        int cont2 = 0;
        for (int i = 0; i < n - 1; i += 2)
        {
            cont += (xabla[i + 1] + 20) - (xabla[i] + 20);
            cont2 += (xabla[i + 2] + 20) - (xabla[i + 1] + 20);
        }

        cout << min(cont, cont2) << endl;
    }
}
