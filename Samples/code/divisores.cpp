vector<int> divisores(int n)
{
    vector<int> divis;
    int sqrtn = sqrt(n);

    while(sqrtn * sqrtn < n)
        sqrtn++;

    for (i = 1; i < sqrtn; i++)
        if (!(n % i))
            divis.push_back(i), divis.push_back(n / i);

    if(sqrtn * sqrtn == n)
        divis.push_back(sqrtn);

    return divis;
}