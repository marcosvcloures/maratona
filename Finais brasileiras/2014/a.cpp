#include <bits/stdc++.h>

using namespace std;

int main()
{

    bool pri[5];
    bool seg[5];

    while (cin >> pri[0])
    {
        for (int i = 1; i < 5; i++)
            cin >> pri[i];

        for (int i = 0; i < 5; i++)
            cin >> seg[i];

        for (int i = 0; i < 5; i++)
            if (pri[i] == seg[i])
            {
                puts("N");
                goto prox;
            }

        puts("Y");
    prox:;
    }
}