#include <bits/stdc++.h>

using namespace std;

#define D(x) //cout << #x " = " << x << endl

const int MAX = 101000;
char txt[MAX]; //input

#define MAX_DIST 1<<24

typedef complex<double> cpx;
const double pi = acos(-1.0);

int p[MAX_DIST];
int maxDist;
cpx in[MAX_DIST], out[MAX_DIST], in_dir[MAX_DIST], out_dir[MAX_DIST];

// in:     vector de entrada
// out:    vector de saida
// n:      Tamanho do input/output {DEVE SER DA ORDEM DE 2}
// type:   1 = Transformada, -1 = Transformada inversa
void FFT(cpx v[], cpx ans[], int n, int type)
{
	assert(!(n & (n - 1)));
	int i, sz, o;
	p[0] = 0;
	for (i = 1; i < n; i++)
		p[i] = (p[i >> 1] >> 1) | ((i & 1) ? (n >> 1) : 0);
	for (i = 0; i < n; i++)
		ans[i] = v[p[i]];
	for (sz = 1; sz < n; sz <<= 1)
	{
		const cpx wn(cos(type * pi / sz), sin(type * pi / sz));
		for (o = 0; o < n; o += (sz << 1))
		{
			cpx w = 1;
			for (i = 0; i < sz; i++)
			{
				const cpx u = ans[o + i], t = w * ans[o + sz + i];
				ans[o + i] = u + t;
				ans[o + i + sz] = u - t;
				w *= wn;
			}
		}
	}

	if (type == -1)
		for (i = 0; i < n; i++)
			ans[i] /= n;
}

int main()
{
	int tam, i, j, r = 0, sum = 0, count, val;

	tam = strlen(fgets(txt, sizeof(txt), stdin)) - 1;

	for (i = 0; i < tam; i++)
		txt[i] = txt[i] - 'a' + 1;

	for (i = 0; i < tam; i++)
		sum += txt[i];

	in[1] = in_dir[2 * sum + 1] = cpx(1, 0);

	count = 0;
	for (i = 0; i < tam; i++)
	{
		count += txt[i];

		in[2 * count + 1] = in_dir[2 * (sum - count) + 1] = cpx(1, 0);
	}

	maxDist = 0;

	for (i = 0; i < 30; i++)
		if (count & (1 << i))
			maxDist = i;

	maxDist = 1 << (maxDist + 2);

	FFT(in, out, maxDist * 2, 1);
	FFT(in_dir, out_dir, maxDist * 2, 1);

	for (i = 0; i < maxDist; i++)
		out[i] = out[i] * out_dir[i];

	FFT(out, in, maxDist, -1);

	maxDist = sum * 2 + 1;

	for (i = sum + 1; i < maxDist; i++)
		r += in[i].real() > 0.1;

	printf("%d\n", r);
}