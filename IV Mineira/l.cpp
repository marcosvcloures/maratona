#include <stdio.h>

int main() {
	int n, m;
	double c, p;
	
	scanf("%d %d %lf %lf", &n, &m, &c, &p);
	
	printf("%.02lf\n", (c-(m*p))/(n-m));
}