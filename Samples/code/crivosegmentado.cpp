char nprimo[100001] = {0}; // tamanho = sqrt(maximo)
std::vector<int> primos;

int main()
{
    int n, a, b, i, j;

    nprimo[1] = 1;
    nprimo[0] = 1;

    for (i = 2; i < 320; i++) // i [2, sqrt(sqrt(maximo))]
        if (!nprimo[i])
            for (j = i * i; j < 100001; j += i) // j [i^2, sqrt(maximo)]
                nprimo[j] = 1;

    for (i = 2; i < 100001; i++)
        if (!nprimo[i])
            primos.push_back(i);

    scanf("%d", &n);

    while (n--)
    {
        scanf("%d %d", &a, &b);

        if (a > 100000 && b > 100000)
        {
            // (a > sqrt(N) && b > sqrt(N))
            for (i = a; i <= b; i++)
            {
                for (j = 0; j < primos.size(); j++)
                    if (i % primos[j] == 0)
                        goto ab;

                printf("%d\n", i);
ab:
                ;
            }
        }
        else if (a < 100001 && b < 100001)
        {
            // (a < sqrt(N) && b < sqrt(N))
            for (i = a; i <= b; i++)
                if (!nprimo[i])
                    printf("%d\n", i);
        }
        else
        {
            for (i = 0; i < primos.size(); i++)
                if (primos[i] >= a)
                    break;

            for (; i < primos.size(); i++)
                printf("%d\n", primos[i]);

            for (; i <= b; i++)
            {
                for (j = 0; j < primos.size(); j++)
                    if (i % primos[j] == 0)
                        goto ac;

                printf("%d\n", i);
ac:
                ;
            }
        }
    }
}