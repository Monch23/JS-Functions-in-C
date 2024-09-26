#include <stdio.h>
#include <stdlib.h>

void toLowerCase(char *str) {
	while (*str) {
		if (*str >= 'A' && *str <= 'Z') {
			*str ^= 32;
		}
		++str;
	}
}

int main() {
	char *str = (char*)malloc(50 * sizeof(int));

	fgets(str, 50, stdin);
	
	toLowerCase(str);
	printf("new string is %s", str);

	free(str);

	return 0;
}
