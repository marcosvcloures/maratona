#include <bits/stdc++.h>

using namespace std;

int strToNum(char *s) {
	int resp = 0;

	for(; *s != 0; s++)
		resp <<= 2, resp += *s == 'U' ? 1 : *s == 'C' ? 2 : *s == 'D' ? 3 : 0;

	return resp;
}

int main() {
	int num1, num2, n, i;
	char entrada[20], op;

	scanf("%d", &n);

	puts("COWCULATIONS OUTPUT");
	while (n--) {
		scanf(" %s", entrada);
		num1 = strToNum(entrada);

		scanf(" %s", entrada);
		num2 = strToNum(entrada);

		for (i = 0; i < 3; i++) {
			scanf(" %c", &op);
			
			if (op == 'A')
				num2 += num1;
			else if (op == 'L')
				num2 <<= 2;
			else if (op == 'R')
				num2 >>= 2;
		}

		scanf(" %s", entrada);
		num1 = strToNum(entrada);
	
		printf("%s\n", num1 == num2 ? "YES" : "NO");
	}
	puts("END OF OUTPUT");
}