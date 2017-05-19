#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, val, pode, i;
	
	while (scanf(" %d", &n) > 0 && n) {
		while(scanf("%d", &val) > 0 && val) {
			stack<int> estacao, linha;
			pode = 1;

			for (i = n; i > 0; i--)
				linha.push(i);
	
			for (i = 0; i < n; i++) {			
				while (pode) {
					if (!linha.empty() && linha.top() == val) {
						linha.pop();
						break;
					}
					else if (!estacao.empty() && estacao.top() == val) {
						estacao.pop();
						break;
					}
					else if (!linha.empty()) {
						estacao.push(linha.top()),
						linha.pop();
					}
					else
						pode = 0;
				}

				if (i != n - 1)
					scanf("%d", &val);
			}

			if(val)
				printf("%s\n", pode ? "Yes" : "No");
		}

		printf("\n");
	}
}