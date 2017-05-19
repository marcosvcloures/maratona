#include <stdio.h>

int main() {
	double a, b;
	
	scanf("%lf %lf", &a, &b);
	
	printf("%.02lf%%\n", 100.0*(b-a)/a);
}