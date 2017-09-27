#include <bits/stdc++.h>

int main() {
    long long int r, g, b;
    
    scanf("%llx %llx %llx", &r, &g, &b);
    
    printf("%llx\n", (r/g)*(r/g) + (r/g)*(r/g)*((g/b)*(g/b)) + 1);
 
    return 0;
}