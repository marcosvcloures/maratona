#include <bits/stdc++.h>

int main() {
	int a, b, c, d, sqrtc, i;
	std::vector<int> div;
	
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	sqrtc = sqrt(c) + 2;
	
	for(i = 1; i < sqrtc; i++)
		if(c % i == 0) 
			div.push_back(i), div.push_back(c / i);
		
	std::sort(div.begin(), div.end());	
	
	for(i = 0; i < div.size(); i++)
		if(div[i] % a == 0 && div[i] % b && d % div[i]) {
			printf("%d\n", div[i]);
			
			return 0;
		}
	
	puts("-1");
}