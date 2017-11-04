#define pb push_back

typedef vector<int> vi;

bool crivo[100000] = {0};
vi primos;

int main()
{
    int i, j, n, resp;

    for(i = 2; i < 100000; i++)
        if(!crivo[i])
        {
            primos.pb(i);
            for(j = i + i; j < 100000; j += i)
                crivo[j] = 1;
        }

    while(scanf("%d", &n) > 0)
    {
        resp = n;

        for(auto &it : primos)
        {
            if(it * it > n)
            {
                if(n != 1)
                    resp -= resp / n;

                break;
            }

            if(n % it == 0)
            {
                resp -= resp / it;

                while(n % it == 0)
                    n /= it;
            }
        }

        printf("%d\n", resp / 2);
    }
}
