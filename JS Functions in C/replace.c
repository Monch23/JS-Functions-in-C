#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replace(char *str, char *specVal, char *anotherVal) {

	if (str == NULL || specVal == NULL || anotherVal == NULL) {
		return 0;
	}	

	int stringLen = strlen(str);
	int specLen = strlen(specVal);
	int anotherLen = strlen(anotherVal);
	int tmpStrSize = stringLen - specLen + anotherLen;
	int back = 0;
	int index = 0;

	char *tmpStr = (char*)malloc(tmpStrSize * sizeof(char));

	for (int i = 0; i < stringLen; ++i) {
		if (str[i] == *specVal) {
			++specVal;
			++back;
		} else {
			specVal -= back;
			back = 0;
			continue;
		} 
		if (back == specLen) {
			index = i - specLen + 1;
			break;
		}
	}

	for (int i = 0; i < index; ++i) {
		tmpStr[i] = str[i];
	}
	str += index + anotherLen;

	while (*anotherVal) {
		tmpStr[index++] = *anotherVal++;
	}
	
	while (*str && index < tmpStrSize) {
		tmpStr[index++] = *str++;
	}

	return tmpStr;
}

int main() {

	char *res = replace("Hello World", "Hello World", "barev aper");

	printf("%s \n", res);
}
