#include <bits/stdc++.h>
using namespace std;

int main() {
	int val[3], trinca, par, ini;
	
	while(scanf("%d %d %d", &val[0], &val[1], &val[2]) && val[0]) {
		sort(val, val + 3);
		
		if(val[0] == 12 && val[1] == 13 && val[2] == 13)
			puts("1 1 1");
		else if(val[0] == 13 && val[1] == 13 && val[2] == 13)
			puts("*");
		else {
			trinca = val[0] == val[1] && val[1] == val[2];
			par = val[0] == val[1] || val[1] == val[2];
			
			if(trinca)
				printf("%d %d %d\n", val[0] + 1, val[0] + 1, val[0] + 1);
			else if(par) {
				ini = val[0] == val[1];
				
				if(ini) {
					if(val[2] == 13) {
						val[1]++;
						val[2] = val[1];
						val[0] = 1;
					}
					else
						val[2]++;
				}
				else {
					val[0]++;
					
					if(val[0] == val[1])
						val[2]++;
				}
				
				printf("%d %d %d\n", val[0], val[1], val[2]);
			}
			else
				puts("1 1 2");
		}
	}
}
