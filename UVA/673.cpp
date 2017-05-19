#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i, tam;
    char entrada[2000];
    stack<char> pilha;
    
    while(scanf("%d%*c", &n) > 0) 
        while(n--) {
            while(!pilha.empty())
                pilha.pop();
            
            fgets(entrada, 2000, stdin);
            tam = strlen(entrada) - 1;
            
            if(tam & 1) 
                puts("No");
            else {
                for(i = 0; i < tam; i++) {
                    if(entrada[i] == '(' || entrada[i] == '[')
                        pilha.push(entrada[i]);
                
                    else if(entrada[i] == ')' && !pilha.empty() && pilha.top() == '(')
                        pilha.pop();
                    
                    else if(entrada[i] == ']' && !pilha.empty() && pilha.top() == '[')
                        pilha.pop();
                    
                    else {
                        puts("No");
                        goto a;                    
                    }
                }
                
                if(!pilha.empty())
                    puts("No");
                else
                    puts("Yes");
                a:;
            }
        }
}