#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n, votos[30], i, melhor, winner, count;
    
    scanf("%d", &t);
    
    while(t--) {
        scanf("%d", &n);
        
        scanf("%d", &votos[0]);
        
        count = votos[0];
        
        for(i = winner = 1, melhor = 0; i < n; i++) {
            scanf("%d", &votos[i]);
            
            count += votos[i];
            
            if(votos[i] > votos[melhor])
                melhor = i, winner = 1;
            else if(votos[i] == votos[melhor])
                winner = 0;
        }
        
        if(winner && votos[melhor] * 2 > count)
            printf("majority winner %d\n", melhor + 1);
        else if(winner)
            printf("minority winner %d\n", melhor + 1);
        else
            puts("no winner");
    }
}