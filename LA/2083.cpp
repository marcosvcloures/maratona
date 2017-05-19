#include <bits/stdc++.h>
using namespace std;

int main(){
	int i, fat[10] = {1};
	double val;
	
	printf("n e\n");
	printf("- -----------\n");
	puts("0 1");
	puts("1 2");
	puts("2 2.5");
	
	val = 2.5;
	
	for(i = 1; i <= 9; i++)
		fat[i] = i * fat[i-1];
		
	for(i = 3; i <= 9; i++) {
		val += 1.0 / fat[i];
			
		printf("%d %.9lf\n", i, val);
	}
	return 0;
}
