#include <bits/stdc++.h>

int main() {
	std::vector<unsigned int> quadrados;
	unsigned int e, i;

	for (i = 1; i < 65536; i++)
		quadrados.push_back(i * i);

	while (scanf("%ud", &e) > 0 && e) {
		
		if (std::binary_search(quadrados.begin(), quadrados.end(), e) > 0)
			puts("yes");
		else
			puts("no");
	}
}