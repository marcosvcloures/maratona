#include <bits/stdc++.h>

using namespace std;

int main() {
    char senha[300], palavra[300];
    string pal, senh;
    int usados[256], fail, i, j, qtd;
    
    while(scanf(" %s %s", senha, palavra) > 0) {
        memset(usados, 0, sizeof(int) * 256);
        senh = senha;
        pal = "";
        qtd = 0;
        
        for(i = 0; i < strlen(senha); i++)
            usados[senha[i]] = 1;
                
        for(j = 0; j < strlen(palavra); j++)                
                if(usados[palavra[j]]) {
                    memset(usados, 0, sizeof(int) * 256);
                    pal += palavra[j], qtd++;
                    
                    for(i = qtd; i < strlen(senha); i++) 
                        usados[senha[i]] = 1;
                }
            
        if(pal == senh)
            puts("PASS");
        else
            puts("FAIL");
    }
}