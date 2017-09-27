#include <cstdio>

int main()
{
    int n = 0;
    char c;

    while (scanf(" %c", &c) > 0)
        if (c >= '0' && c <= '9')
            n += c - '0';

    printf("%d\n", n % 3);
}