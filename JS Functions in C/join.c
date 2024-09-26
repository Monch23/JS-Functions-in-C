#include <stdio.h>
#include <stdlib.h>

char *join(int *arr, int *size, char sym) {

	if (*size <= 0 || arr == NULL) {
		return NULL;
	}

	char *tmpArr = (char*)malloc((*size * 2 - 1) * sizeof(char));
	int k = 0;
	for (int i = 0; i < *size * 2; ++i) {

		if (i == *size * 2 - 1) {
			tmpArr[*size * 2 - 1] = '\0';
			break;
		}
		if (i % 2) {
			tmpArr[i] = sym;
			continue;
		}
		tmpArr[i] = arr[k++] + 48;
	}

	free(arr);
	*size *= 2;
	return tmpArr;
}

int main() {
	int size = 5;
	int *arr = (int*)malloc(size * sizeof(int));

	for (int i = 0; i < size; ++i) {
		scanf("%d", &arr[i]);
	}

	char *joinedArr = join(arr, &size, '-');
	
	printf("%s \n", joinedArr);
	
	free(joinedArr);
}
