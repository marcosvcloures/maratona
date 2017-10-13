#include <bits/stdc++.h>

using namespace std;

int main()
{
    double a, b, c;

    cin >> a >> b >> c;

    if(a < b && a < c) 
        puts("Otavio");
    else if(b < a && b < c)
        puts("Bruno");
    else if(c < a && c < b)
        puts("Ian");
    else
        puts("Empate");
}