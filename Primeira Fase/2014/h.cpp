#include <bits/stdc++.h>

#define D(x) cout << #x << " " << x << endl

using namespace std;

int main() {
    int resp = 0, n, m, t, e, i;

    scanf("%d %d", &n, &m);
    
    while(n--) {
        t = 1;

        for(i = 0; i < m; i++) {
            scanf("%d", &e);
            
            if(e == 0)
                t = 0;
        }

        resp += t;
    }

    printf("%d\n", resp);
}
