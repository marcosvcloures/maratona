#define pb push_back

typedef vector<int> vi;

int main()
{
    long long i, j, n, qtd = 0, resp = 0;
    bool crivo[LIM] = {0};
    vi primos;

    for (i = 2; i < LIM; i++)
        if (!crivo[i])
        {
            primos.pb(i);

            for (j = i + i; j < LIM; j += i)
                crivo[j] = 1;
        }

    scanf("%lld", &n);

    for (auto it : primos)
        if (n % it == 0)
        {
            qtd++;

            n /= it;

            while (n % it == 0)
                n /= it;
        }
        else if (it > n)
            break;

    if (n != 1)
        qtd++;

    printf("%d\n", qtd);
}