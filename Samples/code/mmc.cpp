int mmc(int a, int b)
{
    int temp = mdc(a, b);

    return temp ? (a / temp * b) : 0;
}