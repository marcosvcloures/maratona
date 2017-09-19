#include <bits/stdc++.h>

#define LIM 1100000
#define pb push_back
#define D(x) cout << #x << " " << x << endl;

using namespace std;

typedef vector<int> vi;

vi primos;

int pd[LIM] = {0};

int despojado(long long e)
{
    int count = 0;

    if (e < LIM && pd[e] != -1)
        return 1;

    for (auto &it : primos)
    {
        if (e % it == 0)
        {
            e /= it;

            if (e < LIM && pd[e] == 0)
                return 0;

            count++;

            if (e % it == 0) {
                if(e * it < LIM)
                    pd[e * it] = 0;

                return 0;
            }
            if (e < LIM && pd[e] == 1)
                return 1;
        }
    }

    return count >= 2;
}

int main()
{
    long long i, j, n, qtd = 0, resp = 0;
    bool crivo[LIM] = {0};
    set<long long> divisores;

    fill(pd, pd + LIM, -1);

    for (i = 2; i < LIM; i++)
        if (!crivo[i])
        {
            primos.pb(i);

            for (j = i + i; j < LIM; j += i)
                crivo[j] = 1;
        }

    scanf("%lld", &n);

    int sqrtn = sqrt(n) + 200;

    for (i = 1; i < sqrtn; i++)
    {
        if (n % i == 0)
            divisores.insert(i), divisores.insert(n / i);
    }

    for (auto &it : divisores)
    {
        //D(it);
        //D(despojado(it));
        resp += despojado(it);
    }

    printf("%lld\n", resp);
}