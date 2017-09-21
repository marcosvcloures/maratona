int modPow(int a, int b, int m)
{
    int res = 1;
    for (; b > 0; b >>= 1)
    {
        if (b & 1)
            res = (long long)res * a % m;
        a = (long long)a * a % m;
    }
    return res;
}