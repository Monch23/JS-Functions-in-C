#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *trimStart(const char *str) {
	if (str == NULL) {
		return NULL;
	}
	int length = strlen(str);
	int leftSpaces = 0;

	for (int i = 0; str[i] == ' '; ++i) {
		++leftSpaces;
	}
	
	int tmpSize = length - leftSpaces;
	char *tmpStr = (char*)malloc(tmpSize * sizeof(char));

	for (int i = 0; i < tmpSize; ++i) {
		tmpStr[i] = str[i + leftSpaces];
	}

	return tmpStr;
}

int main() {
	char *str = (char*)malloc(50 * sizeof(char));

	fgets(str, 50, stdin);

	str = trimStart(str);

	printf("%s", str);
	free(str);

	return 0;
}
