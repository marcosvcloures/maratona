#include <stdio.h>
#include <string.h>

#define A 0
#define B 1
#define O 2
#define AB 3

int tipo(char* palavra) {
	if(!strcmp(palavra, "A"))
		return A;
	if(!strcmp(palavra, "B"))
		return B;
	if(!strcmp(palavra, "O"))
		return O;
	return AB;
}

int main() {
	char avos[4][4];
	double mae[3] = {0}, pai[3] = {0};
	int i;
	
	for(i = 0; i < 4; i++)
		scanf(" %s", avos[i]);
	
	for(i = 0; i < 2; i++) {
		if(tipo(avos[i]) == A) {
			mae[A] += 0.75;
			mae[O] += 0.25;
		}
		else if(tipo(avos[i]) == B) {
			mae[B] += 0.75;
			mae[O] += 0.25;
		}
		else if(tipo(avos[i]) == AB) {
			mae[A] += 0.5;
			mae[B] += 0.5;
		}
		else {
			mae[O] += 1;
		}
	}
	
	for(i = 2; i < 4; i++) {
		if(tipo(avos[i]) == A) {
			pai[A] += 0.75;
			pai[O] += 0.25;
		}
		else if(tipo(avos[i]) == B) {
			pai[B] += 0.75;
			pai[O] += 0.25;
		}
		else if(tipo(avos[i]) == AB) {
			pai[A] += 0.5;
			pai[B] += 0.5;
		}
		else {
			pai[O] += 1;
		}
	}
	
	printf("%.02lf %.02lf %.02lf %.02lf\n", (mae[A]*(pai[A]+pai[O]) + mae[O]*pai[A])*0.25, (mae[B]*(pai[B]+pai[O]) + mae[O]*pai[B])*0.25, (mae[A]*pai[B] + mae[B]*pai[A])*0.25, (mae[O]*pai[O])*0.25);
}