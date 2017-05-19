#include <stdio.h>

bool primos[101] = {0}, qse[1001] = {0};

int main() {
	int n, i, j;
	
	for(i = 2; i < 101; i++)
		primos[i] = 1;
	
	for(i = 2; i < 101; i++)
		if(primos[i])
			for(j = i*2; j < 101; j += i)
				primos[j] = 0;
			
	for(i = 2; i < 101; i++) 
		if(primos[i])
			qse[i*i] = 1;
	
	scanf("%d", &n);
	
	printf("%c\n", qse[n] ? 'S' : 'N');
}