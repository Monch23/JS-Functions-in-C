#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strConcat(char *str, char *str2, char separator) {
	int length = strlen(str);
	int length2 = strlen(str2);

	if (str == NULL || str2 == NULL) {
		return NULL;
	}

	char *tmpStr = (char*)malloc((length + length2 + 2) * sizeof(char));
	int i = 0;

	while (*str) {
		tmpStr[i++] = *str;
		str++;
	}

	tmpStr[i++] = separator;

	while (*str2) {
		tmpStr[i++] = *str2;
		str2++;
	}
	
	str -= length;
	str2 -= length2;
	free(str);
	free(str2);

	return tmpStr;
}

int main() {
	char *str = (char*)malloc(6 * sizeof(char));
	char *str2 = (char*)malloc(6 * sizeof(char));

	scanf("%s", str);	
	scanf("%s", str2);	
	
	char *concated = strConcat(str, str2, '%');

	printf("%s \n", concated);
	free(concated);

	return 0;
}
