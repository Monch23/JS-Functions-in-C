#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *trimEnd(const char *str) {
	if (str == NULL) {
		return NULL;
	}

	int length = strlen(str);
	int rightSpaces = 0;

	for (int i = length - 1; str[i] == ' '; --i) {
		++rightSpaces;
	}

	int tmpSize = length - rightSpaces;
	char *tmpStr = (char*)malloc(tmpSize * sizeof(char));

	for (int i = 0; i < tmpSize; ++i) {
		tmpStr[i] = str[i];
	}

	return tmpStr;
}

int main() {
	char *str = (char*)malloc(50 * sizeof(char));

	fgets(str, 50, stdin);

	str = trimEnd(str);

	printf("%s", str);
	free(str);

	return 0;
}
