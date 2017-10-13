#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int a, b;
    string s;

    while (cin >> a >> b >> s)
    {
        b = a - b;

        long long int cont = 0;
        long long int aux = 0;
        for (long long int i = s.size() - 1; i > 0; i--)
        {
            if (s[i] == 'B')
            {
                for (long long int j = aux; j <= i; j++)
                {
                    if (j == i)
                    {
                        goto fim;
                    }

                    if (s[j] == 'W')
                    {
                        cont += min(a, b * (i - j));
                        aux = j + 1;
                        break;
                    }
                }
            }
        }

    fim:
        cout << cont << endl;
    }
}
