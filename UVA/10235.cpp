#include <bits/stdc++.h>
using namespace std;

char primos[1000000] = {0};

int main(){
	int e, i, j;
	char numa[200], numb[200];
	
	for(i = 2; i < 1000000; i++)
		if(!primos[i])
			for(j = 2 * i; j < 1000000; j += i)
				primos[j] = 1;
	
	while(scanf("%d", &e) > 0) {
		if(primos[e]) {
			printf("%d is not prime.\n", e);
			continue;
		}
		
		sprintf(numa, "%d", e);
		sprintf(numb, "%d", e);
		
		reverse(numb, numb + strlen(numb));
		sscanf(numb, "%d", &i);
		
		if(!strcmp(numa, numb) || primos[i]) 
			printf("%d is prime.\n", e);
		else
			printf("%d is emirp.\n", e);
	}
	
	return 0;
}
