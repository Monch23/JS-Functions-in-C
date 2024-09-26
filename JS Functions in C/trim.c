#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *trim(const char *str) {
	if (str == NULL) {
		return NULL;
	}
	
	int length = strlen(str);
	int leftSpaces = 0;
	int rightSpaces = 0;

	for (int i = 0; str[i] == ' '; ++i) {
		++leftSpaces;
	}
	for (int i = length - 1; str[i] == ' '; --i) {
		++rightSpaces;
	}
	
	int tmpSize = length - leftSpaces - rightSpaces + 1;
	char *tmpStr = (char*)malloc(tmpSize * sizeof(char));
	
	for (int i = 0; i < tmpSize; ++i) {
		tmpStr[i] = str[i + leftSpaces];
	}
	
	return tmpStr;
}

int main() {
	char *str = (char*)malloc(50 * sizeof(char));
	
	fgets(str, 50, stdin);
	str = trim(str);
	
	printf("%s \n", str);

	free(str);
	return 0;
}
