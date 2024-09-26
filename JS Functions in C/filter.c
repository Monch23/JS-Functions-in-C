#include <stdio.h>
#include <stdlib.h>

int great(int val, int arg) {
	if (val > arg) {
		return 1;
	}
	
	return 0;
}

int low(int val, int arg) {
	if (val < arg) {
		return 1;
	}
	
	return 0;
}

int *filter(int *arr, int *size, int (*check)(int, int), int val) {
	int tmpSize = 0;
	int k = 0;
	
	for (int i = 0; i < *size; ++i) {
		if (check(arr[i], val)) {
			tmpSize++;
		}
	}

	int *tmpArr = (int*)malloc(tmpSize * sizeof(int));

	for (int i = 0; i < *size; ++i) {
		if (check(arr[i], val)) {
			tmpArr[k++] = arr[i];
		}
	}

	free(arr);
	*size = tmpSize;
	return tmpArr;
}

int main() {
	int size = 5;
	int *arr = (int*)malloc(size * sizeof(int));

	for (int i = 0; i < size; ++i) {
		arr[i] = i + 1;
	}

	arr = filter(arr, &size, low, 4);

	for (int i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}

	putchar(10);
	free(arr);
}
