#include <stdio.h>
#include <stdlib.h>

void fill(int *arr, int size, int fElem) {
	for (int i = 0; i < size; ++i) {
		arr[i] = fElem;
	}
}

int main() {
	int size = 5;
	int *arr = (int*)malloc(size * sizeof(int));

	for (int i = 0; i < size; ++i) {
		arr[i] = i + 1;
	}

	fill(arr, size, 99);

	for (int i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}

	putchar(10);
	free(arr);

	return 0;
}
