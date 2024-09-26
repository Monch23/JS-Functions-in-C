#include <stdio.h>
#include <stdlib.h>

int *splice(int *arr, int *size, int from, int remsCnt) {

	if (*size <= 0 || remsCnt <= 0) {
		return NULL;
	}
	if ((remsCnt + from) >= *size) {
		remsCnt = *size - from;
	}

	int *tmpArr = (int*)malloc((*size - remsCnt) * sizeof(int));
	int index = 0;

	for (int i = 0; i < *size; ++i) {
		if (i == from) {
			i = from + remsCnt;
			tmpArr[index++] = arr[i];
		} else {
			tmpArr[index++] = arr[i];
		}
	}
	
	*size -= remsCnt;
	free(arr);
	return tmpArr;
}

int main() {
	int size = 8;
	int *arr = (int*)malloc(size * sizeof(int));

	for (int i = 0; i < size; ++i) {
		arr[i] = i + 1;
	}

	arr = splice(arr, &size, 2, 67);

	for (int i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}

	putchar(10);

	free(arr);
}
