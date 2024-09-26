#include <stdio.h>
#include <string.h>

int startsWith(const char *str, const char *substr) {
	
	if (str == NULL || substr == NULL) {
		return -1;
	}

	int substrLen = strlen(substr);

	while (substrLen) {
		if (*str++ != *substr++) {
			return 0;
		}
		--substrLen;
	}

	return 1;
}

int main() {

	int res = startsWith("Hello World", "Hello");

	printf("%d \n", res);

	return 0;
}
