#include <stdio.h>
#include <math.h>

long int probPerder[4][4][4] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 21, 0, 0, 55, 161, 0, 0, 55, 1241, 0, 0, 0, 0, 0, 0, 125, 91, 0, 0, 370, 290, 636, 0, 370, 1250, 6156, 0, 0, 0, 0, 0, 1025, 271, 0, 0, 4030, 2090, 1656, 0, 3123, 11104, 10663, 21766};
double probs[4][4][4] = {0}, chances[10002][10002] = {0};

inline int max(int a, int b) {
	return a > b ? a : b;
}

inline int min(int a, int b) {
	return a < b ? a : b;
}

inline double dmax(double a, double b) {
	return a > b ? a : b;
}

inline double dmin(double a, double b) {
	return a < b ? a : b;
}

double chance(int atk, int def) {		
	if(def <= 0)
		return 1;
	if(atk <= 0)
		return 0;
	
	return chances[atk][def];
}

double calc(int atk, int def, int da, int dd) {
	int i, j, qtd = min(da, dd);
	double prob = 0;

	for(i = 0; i <= qtd; i++) 
		prob += probs[da][dd][i] * chance(atk-i, def-qtd+i);
	
	return prob;
}

double minimo(int atk, int def, int da) {
	int i, j, qtd = min(def, 3);
	double r = 2;
	
	for(i = 1; i <= qtd; i++)
		r = dmin(r, calc(atk, def, da, i));
		
	return r;
}

double maximo(int atk, int def) {
	int i, j, qtd = min(atk, 3);
	double r = 0;
	
	for(i = 1; i <= qtd; i++)
		r = dmax(r, minimo(atk, def, i));
		
	return r;
} 

int main() {
	int i, j, k, a, b;
	
	for(i = 1; i <= 3; i++)
		for(j = 1; j <= 3; j++)
			for(k = 0; k < 4; k++) 
				probs[i][j][k] = probPerder[i][j][k]/(pow(6, i+j));
			
	scanf("%d %d", &a, &b);
	a--;
	
// min-max para atk <= 3 || def <= 3
	for(i = 1; i <= 50; i++)
		for(j = 1; j <= 3; j++) {
			chances[i][j] = maximo(i, j);
			chances[j][i] = maximo(j, i);
		} 
		
	for(i = 51; i <= max(a, b); i++) 
		chances[i][1] = chances[i][2] = chances[i][3] = 1;
	
// guloso para atk > 3 && def > 3
	for(i = 4; i <= a; i++) 
		for(j = (a+b)%3-(i%3); j <= b; j+=3) {
			if(j <= 3)
				continue;
	
			chances[i][j] = probs[3][3][0] * chances[i][j-3] + probs[3][3][1] * chances[i-1][j-2] + probs[3][3][2] * chances[i-2][j-1] + probs[3][3][3] * chances[i-3][j];
			
			if(chances[i][j] < 0.000001)
				break;
		}
		
	printf("%.04lf\n", chances[a][b]);
}