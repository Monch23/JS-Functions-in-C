#include <stdio.h>
#include <stdlib.h>

int *slice(int *arr, int *size, int index1, int index2) {

	if (*size <= 0) {
		return NULL;
	}

	int *tmpArr = (int*)malloc((index2 - index1) * sizeof(int));
	int index = 0;
	
	for (int i = index1; i < index2; ++i) {
			tmpArr[index++] = arr[i];
	}

	*size -= index2 - index1;
	free(arr);
	return tmpArr;
}

int main() {
	int size = 5;
	int *arr = (int*)malloc(size * sizeof(int));

	for (int i = 0; i < size; ++i) {
		arr[i] = i + 1;
	}

	arr = slice(arr, &size, 1, 3);

	for (int i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}

	putchar(10);

	free(arr);

	return 0;
}
