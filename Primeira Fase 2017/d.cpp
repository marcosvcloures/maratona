#include <bits/stdc++.h>

#define LIM 1100000
#define pb push_back
#define D(x) cout << #x << " " << x << endl;

using namespace std;

typedef vector<long long> vi;

int main() {
    long long i, j, n, qtd = 0, resp = 0;
    bool crivo[LIM] = {0};
    vi primos;

    for(i = 2; i < LIM; i++) 
        if(!crivo[i]) {
            primos.pb(i);

            for(j = i + i; j < LIM; j += i)
                crivo[j] = 1;
        }

    scanf("%lld", &n);

    for(auto it : primos) 
        if(n % it == 0) {
            qtd++;

            n /= it;

            while(n % it == 0) 
                n /= it;
        }
        else if(it > n) 
            break;
    
    long long pascal[qtd+3][qtd+3];

    fill(pascal[0], pascal[0] + (qtd+3) * (qtd+3), 0);
    
    pascal[1][1] = 1;

    for(i = 2; i <= qtd+2; i++) 
        for(j = 1; j <= qtd+2; j++) 
            pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];

    for(i = 3; i <= qtd + 2; i++)
        resp += pascal[qtd+1][i];

    printf("%lld\n", resp);
}