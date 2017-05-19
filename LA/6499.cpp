#include <bits/stdc++.h>

using namespace std;

char valores[256];

struct palavra {
    string original;
    string alterada;
    
    bool operator <(palavra a) const {
        return alterada < a.alterada;        
    }
};

int main() {
    int n, ano = 0, i, j;
    char caractere, entrada[200];
    palavra temp;
    string alterada;
    vector<palavra> palavras;
        
    while(scanf("%d", &n) && n) {
        ano++;
        palavras.clear();
        
        for(i = 0; i < 26; i++)
            scanf(" %c", &caractere), valores[caractere] = i + 'a';
        
        
        for(i = 0; i < n; i++) {
            scanf(" %s", entrada);
        
            alterada = "";
            
            for(j = 0; j < strlen(entrada); j++)
                alterada += valores[entrada[j]];
            
            temp.original = entrada;
            temp.alterada = alterada;
            
            palavras.push_back(temp);
        }
        
        printf("year %d\n", ano);
        
        sort(palavras.begin(), palavras.end());
        
        for(i = 0; i < palavras.size(); i++)
            puts(palavras[i].original.c_str());
    }
}