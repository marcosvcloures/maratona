vector<int> divisores(int n)
{
    vector<int> div;
    sqrtn = sqrt(n);

    while(sqrtn * sqrtn < n)
        sqrtn++;

    for (i = 1; i < sqrtn; i++)
        if (!(n % i))
            div.push_back(i), div.push_back(n / i);

    if(sqrtn * sqrtn == n)
        div.push_back(sqrtn);

    return div;
}