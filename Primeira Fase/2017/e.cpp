#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define D(x) cout << #x " = " << (x) << endl

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef pair<int, int> ii;
typedef vector<ii> vii;

typedef set<int> si;

si escalas[12];

int main() {
    int n, e, i;

    si musica;

    for(i = 0; i < 12; i++) {
        escalas[i].insert(i % 12);
        escalas[i].insert((i + 2) % 12);
        escalas[i].insert((i + 4) % 12);
        escalas[i].insert((i + 5) % 12);
        escalas[i].insert((i + 7) % 12);
        escalas[i].insert((i + 9) % 12);
        escalas[i].insert((i + 11) % 12);
    }

    scanf("%d", &n);

    while(n--)
        scanf("%d", &e), musica.insert((e - 1) % 12);

    for(i = 0; i < 12; i++) {
        for(auto &it : musica)
            if(escalas[i].count(it) == 0)
                goto proximo;
        
        break;

        proximo:;
    }

    if(i == 0)
        puts("do");
    else if(i == 1)
        puts("do#");
    else if(i == 2)
        puts("re");
    else if(i == 3)
        puts("re#");
    else if(i == 4)
        puts("mi");
    else if(i == 5)
        puts("fa");
    else if(i == 6)
        puts("fa#");
    else if(i == 7)
        puts("sol");
    else if(i == 8)
        puts("sol#");
    else if(i == 9)
        puts("la");
    else if(i == 10)
        puts("la#");
    else if(i == 11)
        puts("si");
    else
        puts("desafinado");
}