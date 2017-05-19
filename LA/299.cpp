#include <bits/stdc++.h>

int main() {
	int i, j, n, r, entrada[50], count;
	
	scanf("%d", &n);
	
	while(n--) {
		scanf("%d", &r);
		
		count = 0;
		
		for(i = 0; i < r; i++)
			scanf("%d", &entrada[i]);
		
		for(i = 0; i < r-1; i++)
			for(j = i+1; j < r; j++)
				if(entrada[i] > entrada[j])
					count++;
				
		printf("Optimal train swapping takes %d swaps.\n", count);
	}
}