// TEOREMA DA CONVOLUÇÃO:
// Podemos fazer a convolução de 2 polinomios utilizando a FFT
// Reduzindo a complexidade de n^2 para n log n
// Definimos a convolução como h[i] = sum(a[j] * b[j-i]) para todo j de 0 a i.
// Segundo o teorema da convolução
// h(f . g) = transformada inversa de (transformada (f) * transformada (g))
// onde . é o operador de convolução.
// e * é o operador de multiplicação termo a termo.

// we use the nearest upper power of 2 to 200k
#define MAX_DIST (262144*2)

struct cpx
{
	cpx() {}
	cpx(double aa) :a(aa) {}
	cpx(double aa, double bb) :a(aa), b(bb) {}
	double a;
	double b;
	double modsq(void) const
	{
		return a * a + b * b;
	}
	cpx bar(void) const
	{
		return cpx(a, -b);
	}
};

cpx operator +(cpx a, cpx b)
{
	return cpx(a.a + b.a, a.b + b.b);
}

cpx operator *(cpx a, cpx b)
{
	return cpx(a.a * b.a - a.b * b.b, a.a * b.b + a.b * b.a);
}

cpx operator /(cpx a, cpx b)
{
	cpx r = a * b.bar();
	return cpx(r.a / b.modsq(), r.b / b.modsq());
}

cpx EXP(double theta)
{
	return cpx(cos(theta), sin(theta));
}

const double two_pi = 4 * acos(0);

cpx distances[MAX_DIST];
cpx fftOut[MAX_DIST];
int maxDist;

// from Stanford's notebook: https://web.stanford.edu/~liszt90/acm/notebook.html
// in:     input array
// out:    output array
// step:   {SET TO 1} (used internally)
// size:   Tamanho do input/output {DEVE SER DA ORDEM DE 2}
// dir:    1 = Transformada, -1 = Transformada inversa
// RESULT: out[k] = \sum_{j=0}^{size - 1} in[j] * exp(dir * 2pi * i * j * k / size)
void FFT(cpx *in, cpx *out, int step, int size, int dir)
{
	if (size < 1) return;
	if (size == 1)
	{
		out[0] = in[0];
		return;
	}
	FFT(in, out, step * 2, size / 2, dir);
	FFT(in + step, out + size / 2, step * 2, size / 2, dir);
	for (int i = 0; i < size / 2; i++)
	{
		cpx even = out[i];
		cpx odd = out[i + size / 2];
		out[i] = even + EXP(dir * two_pi * i / size) * odd;
		out[i + size / 2] = even + EXP(dir * two_pi * (i + size / 2) / size) * odd;
	}
}

// Exemplo:
// Há um robo que pode disparar bolas em N distâncias diferentes.
// Queremos saber se ele alcança uma distância M com 1 ou 2 tacadas.
// Resolução:
// Podemos definir um vetor distances[MAX_DIST],
// onde a distances[i] = 1 se ele pode tacar até a distancia i
// e distances[i] = 0 caso contrario
// Para ver se o robo acerta com 1 tacada, é trivial.
// Para ver se o robo acerta com 2 tacadas, podemos fazer a convolução de distances com distances.
// E verificar então a posição distances[m]

int main()
{
	int N, d;
	cpx cpx_1(1);

	while (cin >> N) {
		maxDist = 0;
		memset(distances, 0, MAX_DIST * sizeof(cpx));

		distances[0] = cpx_1; // permit one shots

		for (int i = 0; i < N; i++) {
			cin >> d;
			if (d > maxDist)
				maxDist = d;
			distances[d] = cpx_1;
		}

		// Find (nearest upper power of 2) * 2. O(log 200k)
		int shiftAmount;
		for (shiftAmount = 0; (maxDist >> shiftAmount) != 0; shiftAmount++);
		maxDist = 1 << (shiftAmount + 1);

		// Aplicaremos o teorema da convolução.

		// fftOut <= transformada de distances
		FFT(distances, fftOut, 1, maxDist, 1);

		// Multiplicação termo a termo de f e g, no caso, f = g = fftOut
		// fftOut *= fftOut
		for (int i = 0; i < maxDist; i++)
			fftOut[i] = fftOut[i] * fftOut[i];

		// transformada inversa da multiplcação termo a termo.
		FFT(fftOut, distances, 1, maxDist, -1);


		cin >> N;
		int total = 0;
		for (int i = 0; i < N; i++) {
			cin >> d;

			// Entra a distancia d
			// e verifica se a parte real da distância é != 0
			if (distances[d].a > 0.01)
				total++;
		}
		cout << total << endl;
	}
	return 0;
}