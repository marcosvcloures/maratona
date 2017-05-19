#include <stdio.h>
#include <string.h>

int main() {
	char entrada[99];
	int i;
	
	scanf("%s", entrada);
	
	for(i = strlen(entrada)-1; i >= 0; i--)
		printf("%c", entrada[i]);
	printf("\n");
}