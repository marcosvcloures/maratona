#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, i, j;
    char resp[100000];
    
    cin >> a;

    while(cin >> a >> b) {
        for(i = a; i <= b; i++)
            printf("%d", i);

        for(i = b; i >= a; i--) {
            j = i;
            
            while(j)
                printf("%d", j % 10), j /= 10;
        }

        puts("");
    }
}