#include <bits/stdc++.h>

using namespace std;

const int MAX_DIST = 1 << 23;

typedef complex<double> cpx;
const double pi = acos(-1.0);

char txt[100000];
int maxDist;

// in:     vector de entrada
// type:   1 = Transformada, -1 = Transformada inversa
void fft (vector<cpx> &a, bool invert) {
	int n = (int) a.size();
 
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		
		if (i < j)
			swap (a[i], a[j]);
	}
 
	for (int len=2; len<=n; len<<=1) {
		double ang = 2*pi/len * (invert ? -1 : 1);
		cpx wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			cpx w (1);
			for (int j=0; j<len/2; ++j) {
				cpx u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}

	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}

int main()
{	
	int soma = 0, acc = 0, tam = 0, c;
    vector<cpx> fftEsq(MAX_DIST), fftDir(MAX_DIST);

	while((c = getchar()) >= 'a') {
		soma += txt[tam++] = c - 96;
		fftEsq[soma] = cpx(1, 0);
	}

	fftDir[soma] = cpx(1, 0);

	for(int i = 0; i < tam; i++) {
		acc += txt[i];

		fftDir[soma - acc] = cpx(1, 0);
	}

	int shiftAmount, lim = 2 * soma;

	for (shiftAmount = 0; (lim >> shiftAmount) != 0; shiftAmount++)
		;

	maxDist = 1 << shiftAmount;

	fftEsq.resize(maxDist);
	fftDir.resize(maxDist);

	fft(fftEsq, false);
	fft(fftDir, false);

	for (int i = 0; i < maxDist; i++)
		fftEsq[i] = fftDir[i] * fftEsq[i];

	fft(fftEsq, 1);

	int total = 0;

	assert(lim < maxDist);

	for (int i = soma + 1; i <= lim; i++)
	{
		if (fftEsq[i].real() > 0.01)
			total++;
	}

	printf("%d\n", total);
}