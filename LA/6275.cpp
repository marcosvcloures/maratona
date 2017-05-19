#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int n, x, i, j, valores[1000000], pode;
    
    while(scanf("%lld %lld", &x, &n) > 0) {
        pode = false;
        
        for(i = 0; i < n; i++)
            scanf("%lld", &valores[i]);
        
        sort(valores, valores + n);
        
        x *= (long long int) 10000000;
        
        i = 0;
        j = n-1;
        
        while(i < j) {
            if(valores[i] + valores[j] == x) {
                printf("yes %lld %lld\n", valores[i], valores[j]);
                pode = true;
                break;
            }
            else if(valores[i] + valores[j] > x)
                j--;
            else
                i++;
        }
        
        if(!pode)
            puts("danger");
    }
}