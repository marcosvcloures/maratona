double gss(double a, double b, double (*f)(double), double e = 1e-6)
{
    double r = (sqrt(5) - 1) / 2; //=.618...=golden ratio-1
    double x1 = b - r * (b - a), x2 = a + r * (b - a);
    double f1 = f(x1), f2 = f(x2);
    while (b - a > e)
    {
        if (f1 < f2)
        { //change to > to find maximum
            b = x2;
            x2 = x1;
            f2 = f1;
            x1 = b - r * (b - a);
            f1 = f(x1);
        }
        else
        {
            a = x1;
            x1 = x2;
            f1 = f2;
            x2 = a + r * (b - a);
            f2 = f(x2);
        }
    }
    return (b + a) / 2;
}