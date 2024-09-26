#include <stdio.h>
#include <stdlib.h>

void reverse(int *arr, int size) {

	if (arr == NULL || size <= 0) {
		return;
	}

	for (int i = 0, j = size - 1; i < size / 2; ++i, --j) {
		arr[i] ^= arr[j];
		arr[j] ^= arr[i];
		arr[i] ^= arr[j];
	}
}

int main() {
	int size = 5;
	int *arr = (int*)malloc(size * sizeof(int));

	for (int i = 0; i < size; ++i) {
		arr[i] = i + 1;
	}

	reverse(arr, size);

	for (int i = 0; i < size; ++i) {
		printf("%d ",arr[i]);
	}

	putchar(10);
	free(arr);
}
