int pollard(int number)
{
    x_fixed = 2, cycle_size = 2, x = 2, factor = 1;

    while (factor == 1)
    {
        for (int count = 1; count <= cycle_size && factor <= 1; count++)
        {
            x = (x * x + 1) % number;
            factor = mdc(x - x_fixed, number);
        }

        cycle_size *= 2;
        x_fixed = x;
    }
    return factor;
}