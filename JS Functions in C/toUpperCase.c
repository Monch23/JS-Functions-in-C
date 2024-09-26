#include <stdio.h>
#include <stdlib.h>

void toUpperCase(char *str) {
	while (*str) {
		if (*str >= 'a' && *str <= 'z') {
			*str ^= 32;
		}
		++str;
	}
}

int main() {
	char *str = (char*)malloc(50 * sizeof(char));

	fgets(str, 50, stdin);
	printf("new string is %s", str);

	free(str);

	return 0;
}
