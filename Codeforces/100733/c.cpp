#include <bits/stdc++.h>

using namespace std;

unsigned long long int mdc(unsigned long long int a, unsigned long long int b) {
	unsigned long long int remainder;
	while (b != 0) {
		remainder = a % b;
		a = b;
		b = remainder;
	}
	return a;
}

int main() {
	unsigned long long int dezena, dizima = 0, c = 100, i;
	char b, entrada[50];
	
	scanf(" %s", entrada);
	sscanf(entrada, "%I64u", &dezena);
	
	for(i = 0; i < strlen(entrada); i++)
		if(entrada[i] == '.')
			break;
		
	for(i++; i < strlen(entrada); i++)
		c *= 10, dezena *= 10, dezena += entrada[i] - '0';

	printf("%I64u\n", c/mdc(dezena, c));
}