vector<int> primeFactors(int n)
{
    vector<int> v;
    int sqrtn = sqrt(n);

    while (n % 2 == 0)
    {
        v.push_back(2);
        n = n / 2;
    }

    for (int i = 3; i <= sqrtn; i = i + 2)
    {
        while (n % i == 0)
        {
            v.push_back(i);
            n = n / i;
        }
    }

    if (n > 2)
        v.push_back(n);

    return v;
}