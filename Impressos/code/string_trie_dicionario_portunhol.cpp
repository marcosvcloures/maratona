#include <bits/stdc++.h>

using namespace std;

long long sss1, sss2;
long long tot_pt[256];
long long tot_es[256];

struct No
{
    char c;
    vector<No> filhos;
};


void conta_pt(No &atual, long long qt) {
    if(atual.filhos.size() == 0) {
        sss1 += qt;
        return;
    }

    bool soma = true;
    
    for(auto &it : atual.filhos) {
        if(soma)
            conta_pt(it, qt+1);
        else
            conta_pt(it, 1);
            
        soma = false;
    }
}

void conta_es(No &atual, long long qt) {
    if(atual.filhos.size() == 0) {
        sss2 += qt;
        return;
    }

    bool soma = true;
    
    for(auto &it : atual.filhos) {
        if(soma)
            conta_es(it, qt+1);
        else
            conta_es(it, 1);
            
        soma = false;
    }
}

void total_pt(No &atual, bool faz) {
    if(faz)
        tot_pt[atual.c]++;

    for(auto &it : atual.filhos) 
       total_pt(it, true);
}

void total_es(No &atual, bool faz) {
    if(faz)
        tot_es[atual.c]++;

    for(auto &it : atual.filhos)
       total_es(it, true);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, i, m;
    string pal;

    No pt;
    No es;
    
    pt.c = es.c = '-';

    // Lê n palavras e monta a arvore de todas as palavras, adicionando $ a cada fim de palavra
    while(cin >> n >> m)
    {
        if(n+m == 0)
            return 0;

        sss1 = sss2 = 0;
        
        fill(tot_es + 'a', tot_es + 'z' + 1, 0);
        fill(tot_pt + 'a', tot_pt + 'z' + 1, 0);
        
        pt.filhos.clear();
        es.filhos.clear();

        No *atual;

        for(i = 0; i < n; i++)
        {
            atual = &pt;

            cin >> pal;

            for(auto &it : pal)
            {
                for(auto &it2 : atual->filhos) {
                    if(it2.c == it) {
                        atual = &it2;
                        goto prox1;
                    }
                }
                
                atual->filhos.push_back(No());
                atual = &(atual->filhos.back());
                atual->c = it;
                
                prox1:;
            }
        }

        for(i = 0; i < m; i++)
        {
            atual = &es;

            cin >> pal;

            for(int j=pal.size()-1; j >= 0; j--)
            {
                for(auto &it2 : atual->filhos) {
                    if(it2.c == pal[j]) {
                        atual = &it2;
                        goto prox2;
                    }
                }
                
                atual->filhos.push_back(No());
                atual = &(atual->filhos.back());
                atual->c = pal[j];
                
                prox2:;
            }
        }
        
        for(auto it : pt.filhos) {
            conta_pt(it, 1);
            total_pt(it, false);
        }
        
        for(auto it : es.filhos) {
            conta_es(it, 1);
            total_es(it, false);
        }

        long long soma_tot = 0;
        
        for(int j = 'a'; j <= 'z'; j++)
            soma_tot -= tot_pt[j] * tot_es[j];
            
        soma_tot += sss1 * sss2;
        
        cout << soma_tot << '\n';
    }
}