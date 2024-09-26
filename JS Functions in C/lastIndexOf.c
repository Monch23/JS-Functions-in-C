#include <stdio.h>
#include <string.h>

int lastIndexOf(const char *str, const char soughtFor) {
	
	if (str == NULL) {
		return -1;
	}

	int index = strlen(str) - 1;
	str += strlen(str) - 1;
	
	while (index > -1) {
		if (*str-- == soughtFor) {
			return index;
		}
		--index;
	}

	return -1;
}

int main() {

	int res = lastIndexOf("Hello World", ' ');

	printf("%d \n", res);

	return 0;
}
