#include <bits/stdc++.h>

using namespace std;

int permutacoes (int *sol, int n, int max) {
	int sum = 0, i;
	
	for(i = 0; i < n; i++)
		sum += sol[i];
		
	if(sum > max)
		return 0;
	else if(sum == max) 
		return 1;
	else if(n == 3)
		return 0;
		
	int total = 0;
	
	for(i = 0; i <= 20; i++) {
		sol[n] = i;
		total += permutacoes(sol, n+1, max);
	}
	
	for(i = 22; i <= 40; i += 2) {
		sol[n] = i;
		total += permutacoes(sol, n+1, max);
	}
	
	for(i = 21; i <= 60; i += 3) {
		if(i < 40 && i % 2 == 0)
			continue;
			
		sol[n] = i;
		total += permutacoes(sol, n+1, max);
	}
	
	sol[n] = 50;
	total += permutacoes(sol, n+1, max);
	
	return total;
}

int combinacoes (int *sol, int n, int max) {
	int sum = 0, i;
	
	for(i = 0; i < n; i++)
		sum += sol[i];
		
	if(sum > max)
		return 0;
	else if(sum == max) 
		return 1;
	else if(n == 3)
		return 0;
		
	int total = 0;
	
	for(i = 1; i <= 20; i++) {
		if(n > 0 && i < sol[n-1])
			continue;
		
		sol[n] = i;
		total += combinacoes(sol, n+1, max);
	}
	
	for(i = 22; i <= 40; i += 2) {
		if(n > 0 && i < sol[n-1])
			continue;
		
		sol[n] = i;
		total += combinacoes(sol, n+1, max);
	}
	
	for(i = 21; i <= 60; i += 3) {
		if(n > 0 && i < sol[n-1])
			continue;
			
		if(i < 40 && i % 2 == 0)
			continue;
			
		sol[n] = i;
		total += combinacoes(sol, n+1, max);
	}
	
	if(n == 0 || 50 >= sol[n-1]) {
		sol[n] = 50;
		total += combinacoes(sol, n+1, max);
	}
	
	return total;
}

int main () {
	int max, sol[3] = {0}, comb;
	bool primeiro = true;
	
	scanf("%d", &max);
	
	while(1) {
		if(!primeiro)
			puts("**********************************************************************");
		
		primeiro = false;
		
		if(max <= 0) {
			puts("END OF OUTPUT");
			return 0;
		}
	
		comb = combinacoes(sol, 0, max);
		
		if(!comb)
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", max);
		else
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n"
				   "NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", max, comb, max, permutacoes(sol, 0, max)); 
		
		scanf("%d", &max);
	}
}