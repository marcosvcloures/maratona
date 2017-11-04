#include <bits/stdc++.h>

using namespace std;

struct No
{
    char c;
    map<char, No> filhos;
};

void imprime(No &atual)
{
    cout << atual.c << ": ";

    for(auto it : atual.filhos)
        cout << it.first << " ";
    cout << endl;

    for(auto it : atual.filhos)
        imprime(it.second);
}

int main()
{
    int n, i;
    string pal;

    // Lê n palavras e monta a arvore de todas as palavras, adicionando $ a cada fim de palavra
    while(cin >> n)
    {
        No inicio, *atual;
        inicio.c = '-';

        for(i = 0; i < n; i++)
        {
            atual = &inicio;

            cin >> pal;

            for(auto &it : pal)
            {
                if(atual->filhos.count(it))
                    atual = &(atual->filhos[it]);
                else
                {
                    atual->filhos[it] = No();
                    atual = &(atual->filhos[it]);
                    atual->c = it;
                }
            }

            atual->filhos['$'] = No();
            atual->filhos['$'].c = '$';
        }

        imprime(inicio);
    }
}