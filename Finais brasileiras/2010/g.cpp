#include <bits/stdc++.h>

using namespace std;

#define PB push_back

typedef vector<int> vi;

const int MAX = 1005000;

bool comp(string a, string b)
{
    return a.size() < b.size();
}

vi txt;                  //input
int iSA[MAX], SA[MAX];   //output
int cnt[MAX], prox[MAX]; //internal
bool bh[MAX], b2h[MAX];

// Compares two suffixes according to their first characters
bool smaller_first_char(int a, int b)
{
    return txt[a] < txt[b];
}

void suffixSort(int n)
{
    for (int i = 0; i < n; ++i)
        SA[i] = i;

    sort(SA, SA + n, smaller_first_char);

    for (int i = 0; i < n; ++i)
    {
        bh[i] = i == 0 || txt[SA[i]] != txt[SA[i - 1]];
        b2h[i] = false;
    }

    for (int h = 1; h < n; h <<= 1)
    {
        int buckets = 0;

        for (int i = 0, j; i < n; i = j)
        {
            j = i + 1;

            while (j < n && !bh[j])
                j++;

            prox[i] = j;
            buckets++;
        }

        if (buckets == n)
            break;

        for (int i = 0; i < n; i = prox[i])
        {
            cnt[i] = 0;

            for (int j = i; j < prox[i]; ++j)
                iSA[SA[j]] = i;
        }

        cnt[iSA[n - h]]++;
        b2h[iSA[n - h]] = true;

        for (int i = 0; i < n; i = prox[i])
        {
            for (int j = i; j < prox[i]; ++j)
            {
                int s = SA[j] - h;

                if (s >= 0)
                {
                    int head = iSA[s];
                    iSA[s] = head + cnt[head]++;
                    b2h[iSA[s]] = true;
                }
            }
            for (int j = i; j < prox[i]; ++j)
            {
                int s = SA[j] - h;

                if (s >= 0 && b2h[iSA[s]])
                    for (int k = iSA[s] + 1; !bh[k] && b2h[k]; k++)
                        b2h[k] = false;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            SA[iSA[i]] = i;
            bh[i] |= b2h[i];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        iSA[SA[i]] = i;
    }
}

int lcp[MAX];
void getlcp(int n)
{
    for (int i = 0; i < n; ++i)
        iSA[SA[i]] = i;

    lcp[0] = 0;

    for (int i = 0, h = 0; i < n; ++i)
    {
        if (iSA[i] > 0)
        {
            int j = SA[iSA[i] - 1];

            while (i + h < n && j + h < n && txt[i + h] == txt[j + h])
                h++;

            lcp[iSA[i]] = h;

            if (h > 0)
                h--;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, resp;

    while (cin >> n && n)
    {
        txt.clear();
        
        map<int, int> posicoesIniciais, posicoesFinais, aVisitar;
        vi pd(n, 1);
        vector<string> palavras(n);
        resp = 0;

        for (auto &it : palavras)
            cin >> it;

        sort(palavras.begin(), palavras.end(), comp);

        for (int i = 0; i < n; i++)
        {
            posicoesIniciais[txt.size()] = i;

            for (auto &it : palavras[i])
                txt.PB(it + 20000);

            // Fim de palavra (menor que todas as letras e crescente)
            // pra ordernar certo;
            txt.PB(1 + i);

            posicoesFinais[txt.size()] = i;
        }

        suffixSort(txt.size());

        getlcp(txt.size());

        for (int i = 0; i < txt.size() - 1; i++)
        {
            auto inicial = posicoesIniciais.find(SA[i]);

            if (inicial != posicoesIniciais.end() && lcp[i + 1] == palavras[inicial->second].size())
                aVisitar[inicial->second] = i;
        }

        for (auto &it : aVisitar)
        {
            for (int j = it.second + 1; j < txt.size(); j++)
                if (lcp[j] < palavras[it.first].size())
                    break;
                else
                {
                    auto atual = posicoesFinais.upper_bound(SA[j])->second;

                    pd[atual] = max(pd[atual], pd[it.first] + 1);
                }
        }

        for (auto &it : pd)
            resp = max(resp, it);

        cout << resp << "\n";
    }
}
