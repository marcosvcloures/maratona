#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
   int n, i, j, caso = 1;
   
   while(scanf("%d", &n) > 0) {
       vi numeros;
       
       numeros.push_back(0);
       
       for(i = 1; i <= n; i++)
           for(j = 0; j < i; j++)
               numeros.push_back(i);
       
       printf("Caso %d: %d numero%s\n", caso, numeros.size(), numeros.size() > 1 ? "s" : "");
       
       printf("%d", numeros[0]);
       for(i = 1; i < numeros.size(); i++)
           printf(" %d", numeros[i]);
           
       printf("\n\n");
       
       caso++;
   }

   return 0;
}