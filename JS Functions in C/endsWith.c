#include <stdio.h>
#include <string.h>

int endsWith(const char *str, const char *substr) {
	
	if (str == NULL || substr == NULL) {
		return -1;
	}
	
	str += strlen(str) - 1;
	substr += strlen(substr) - 1;

	while (substrLen) {
		if (*str-- != *substr--) {
			return 0;
		}
		--substrLen;
	}
	
	return 1;
}

int main() {

	int res = endsWith("Hello world", "ld");

	printf("%d \n", res);
	
	return 0;
}
