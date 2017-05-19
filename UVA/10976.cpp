#include <bits/stdc++.h>
using namespace std;

long long mdc(long long a, long long b) {
 long long remainder;
 while (b != 0) {
  remainder = a % b;
  a = b;
  b = remainder;
 }
 return a;
}

long long mmc(long long a, long long b) {
    long long temp = mdc(a, b);

    return temp ? (a / temp * b) : 0;
}

int main(){
	long long n, i, vi, count;
	long long a, b, c;

	while(scanf("%lld", &vi) > 0) {
		count = 0;
		i = vi + 1;
		n = vi * 2 + 1;

		while(i != n) {
			a = mmc(i, vi);

			c = a / vi - a / i;

			b = mdc(c, a);

			if(c / b == 1)
				count++;

			i++;
		}

		printf("%lld\n", count);

		i = vi + 1;
		n = vi * 2 + 1;

		while(i != n) {
			a = mmc(i, vi);

			c = a / vi - a / i;

			b = mdc(c, a);

			if(c / b == 1)
				printf("1/%lld = 1/%lld + 1/%lld\n", vi, a / b, i);

			i++;
		}

	}
	return 0;
}
