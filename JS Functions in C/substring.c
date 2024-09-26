#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *substring(const char *str, size_t from, size_t to) {
	int length = strlen(str);	

	if (str == NULL || from > to || from > length || to > length) {
		return NULL;
	}

	char *tmpStr = (char*)malloc((to - from) * sizeof(char) + 1);
	int sIndex = 0;
	
	for (int i = from; i < to; ++i) {
		tmpStr[sIndex++] = str[i];
	}
	
	return tmpStr;
}

int main() {
	char *str = substring("Hello World", 0, 9);

	printf("%s \n", str);

	return 0;
}
