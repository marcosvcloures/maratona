#include <bits/stdc++.h>

using namespace std;

#define D(x) //cout << #x " = " << x << endl

const int MAX = 101000;
char txt[MAX];           //input
int iSA[MAX], SA[MAX], sum[MAX];   //output
int cnt[MAX], prox[MAX]; //internal
bool bh[MAX], b2h[MAX], possiveis[2600100] = {0};

// Compares two suffixes according to their first characters
inline bool smaller_first_char(int a, int b)
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
// End of suffix array algorithm

// Begin of the O(n) longest common prefix algorithm
int lcp[MAX];
// lcp[i] = length of the longest common prefix of suffix SA[i] and suffix SA[i-1]
// lcp[0] = 0
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
    int tam, i, j, r = 0, count, val;

    tam = strlen(fgets(txt, sizeof(txt), stdin)) - 1;

    suffixSort(tam);

    for (i = 0; i < tam; i++)
        txt[i] = txt[i] - 'a' + 1;

    getlcp(tam);

    sum[0] = 0;

    for (i = 0; i < tam; i++)
    {
        count = lcp[i];

        for (j = SA[i] + lcp[i]; j < tam; j++)
        {
            count++;
            
            val = sum[count] = sum[count - 1] + txt[j];

            if (!possiveis[val])
            {
                r++;
                possiveis[val] = 1;
            }
        }
    }

    printf("%d\n", r);
}