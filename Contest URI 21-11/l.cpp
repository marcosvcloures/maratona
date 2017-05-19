#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b;
	
	scanf("%d %d", &a, &b);
	
	if(a == 0)
		puts("C");
	else {
		if(b == 1)
			puts("A");
		else
			puts("B");
	}
}