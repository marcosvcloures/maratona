#include <bits/stdc++.h>
using namespace std;

const int N = 10000;

struct KthSmallest
{
    struct Seg
    {
        int l, r, mid;

        void set(int _l, int _r)
        {
            l = _l;
            r = _r;
            mid = l + r >> 1;
        }
    } seg[N << 2];

    int b[25][N], left[25][N], sorted[N];

    void init(int *a, int n)
    {
        for (int i = 0; i < n; i++)
            b[0][i] = sorted[i] = a[i];

        sort(sorted, sorted + n);
        build(0, n, 0, 1);
    }

    void build(int l, int r, int d, int idx)
    {
        seg[idx].set(l, r);

        if (l + 1 == r)
            return;

        int mid = seg[idx].mid;
        int lsame = mid - l;

        for (int i = l; i < r; i++)
            if (b[d][i] < sorted[mid])
                lsame--;

        int lpos = l, rpos = mid, same = 0;

        for (int i = l; i < r; ++i)
        {
            left[d][i] = (i != l ? left[d][i - 1] : 0);

            if (b[d][i] < sorted[mid])
            {
                left[d][i]++;
                b[d + 1][lpos++] = b[d][i];
            }
            else if (b[d][i] > sorted[mid])
                b[d + 1][rpos++] = b[d][i];
            else
            {
                if (same < lsame)
                {
                    same++;
                    left[d][i]++;
                    b[d + 1][lpos++] = b[d][i];
                }
                else
                {
                    b[d + 1][rpos++] = b[d][i];
                }
            }
        }

        build(l, mid, d + 1, idx << 1);
        build(mid, r, d + 1, idx << 1 | 1);
    }

    //Quando ordernarmos [l, r), qual é o k-ésimo termo?
    int kth(int l, int r, int k, int d = 0, int idx = 1)
    {
        // k : 1-origin!!!
        if (l + 1 == r)
            return b[d][l];

        int ltl = (l != seg[idx].l ? left[d][l - 1] : 0);
        int tl = left[d][r - 1] - ltl;

        if (tl >= k)
        {
            int newl = seg[idx].l + ltl;
            int newr = seg[idx].l + ltl + tl;

            return kth(newl, newr, k, d + 1, idx << 1);
        }
        else
        {
            int mid = seg[idx].mid;
            int tr = r - l - tl;
            int ltr = l - seg[idx].l - ltl;
            int newl = mid + ltr;
            int newr = mid + ltr + tr;

            return kth(newl, newr, k - tl, d + 1, idx << 1 | 1);
        }
    }

    //When sorting [l, r), what number will x come in?
    //If there are two or more x's, return the rank of the last one.
    //If there is no x, return the rank of the largest but less than x.
    //When there is no less than x, 0 is returned.
    int rank(int l, int r, int x, int d = 0, int idx = 1)
    {
        if (seg[idx].l + 1 == seg[idx].r)
            return l + 1 == r && sorted[l] <= x;

        int ltl = (l != seg[idx].l ? left[d][l - 1] : 0);
        int tl = left[d][r - 1] - ltl;
        int mid = seg[idx].mid;

        if (x < sorted[mid])
        {
            int newl = seg[idx].l + ltl;
            int newr = seg[idx].l + ltl + tl;

            return rank(newl, newr, x, d + 1, idx << 1);
        }
        else
        {
            int tr = r - l - tl;
            int ltr = l - seg[idx].l - ltl;
            int newl = mid + ltr;
            int newr = mid + ltr + tr;

            return tl + rank(newl, newr, x, d + 1, idx << 1 | 1);
        }
    }

    // Quantos x existem entre [l,r)
    int freq(int l, int r, int x)
    {
        return rank(l, r, x) - rank(l, r, x - 1);
    }
} kth;

int main()
{
    int a[8] = {6, 12, 5, 17, 10, 2, 7, 3};

    kth.init(a, 8);

    cout << kth.kth(2, 7, 3) << endl;  // 7
    cout << kth.rank(2, 7, 7) << endl; // 3
}