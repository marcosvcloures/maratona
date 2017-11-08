// Euclides extendido
int xmdc(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1, mdc = xmdc(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return mdc;
}

// Mod sempre positivo
int mod(long a, int m)
{
    int A = (int)(a % m);
    return A >= 0 ? A : A + m;
}

// Inverso modular
int modInverse(int a, int m)
{
    a = mod(a, m);
    return a == 0 ? 0 : mod((1 - (long long)modInverse(m % a, a) * m) / a, m);
}

int mdc(int a, int b)
{
    int remainder;
    while (b != 0)
    {
        remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int mmc(int a, int b)
{
    int temp = mdc(a, b);

    return temp ? (a / temp * b) : 0;
}

// Teorema de Lucas -> (nCk) % mod
int calc(int n, int k, int mod)
{
    int res = 1;
    while (n || k)
    {
        res = (res * c[n % mod][k % mod]) % mod;
        n /= mod;
        k /= mod;
    }
    return res;
}