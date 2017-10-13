#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q, i;
    
    while(cin >> n >> q) 
    {
        vi valores(n);

        for(auto &it : valores)
            cin >> it;

        sort(valores.rbegin(), valores.rend());

        while(q--)
            cin >> i, printf("%d\n", valores[i - 1]);
    }
}