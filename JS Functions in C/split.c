#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

char **split(const char *str, const char separator, size_t *newSize) {
	if (str == NULL) {
		return NULL;
	}

	int length = strlen(str);
	int newCharStrSize = 0;
	int back = 0;
	int index = 0;
	int j = 0;
	int k = 0;
	int flag = 0;

	for (int i = 0; i < length; ++i) {
		if (str[i] == separator) {
			++newCharStrSize;
		}
	}
	*newSize = newCharStrSize;

	char **newStr = (char**)malloc(newCharStrSize * sizeof(char*));	

	for (int i = 0; i < length; ++i) {
		++back;
		if (str[i] == separator || (str[i + 1]  == '\0')) {
			newStr[index] = (char*)malloc(back * sizeof(char));
		
			while (--back) {
				if (k == length - 2) {
					++back;
				}

				newStr[index][j++] = str[k++];
			}

			j = 0;
			++k;
			++index;
		}
	}
	return newStr;
}

int main() {
	size_t newSize = 0;
	char **splitedStr = split("Hello My Name Is Johnny ", ' ', &newSize);

	for (int i = 0; i < newSize; ++i) {
		printf("%s \n", splitedStr[i]);
	}

	for (int i = 0; i < newSize; ++i) {
		free(splitedStr[i]);
	}

	free(splitedStr);
	
	return 0;
}
