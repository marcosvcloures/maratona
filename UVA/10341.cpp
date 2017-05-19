#include <bits/stdc++.h>

int main() {
	double resposta, p, q, r, s, t, u;
	int i;

	while (scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u) > 0) {
		if (p*pow(M_E, -0) + q*sin(0) + r*cos(0) + s * tan(0) + u == 0)
			printf("0.0000\n");
		else if ((p*pow(M_E, -0) + q*sin(0) + r*cos(0) + s * tan(0) + u) * (p*pow(M_E, -1) + q*sin(1) + r*cos(1) + s * tan(1) + t + u) > 0)
			puts("No solution");
		else {
			resposta = 0.5;

			for (i = 0; i < 20; i++)
				resposta = resposta - (p*pow(M_E, -resposta) + q*sin(resposta) + r*cos(resposta) + s * tan(resposta) + t*resposta*resposta + u) / (-p*pow(M_E, -resposta) + q*cos(resposta) - r*sin(resposta) + s*pow(1 / cos(resposta), 2) + 2 * t*resposta);

			if (resposta >= 0 && resposta <= 1)
				printf("%.4lf\n", resposta);
			else
				puts("No solution");
		}
	}
}