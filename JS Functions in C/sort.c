#include <stdio.h>
#include <stdlib.h>

void sort(int *arr, int size) {

	if (arr == NULL || size <= 0) {
		return;
	}

	for (int i = 0; i < size - 1; ++i) {
		for (int j = i + 1; j < size; ++j) {
			if (arr[i] > arr[j]) {
				arr[i] ^= arr[j];
				arr[j] ^= arr[i];
				arr[i] ^= arr[j];
			}
		}
	}
}

int main() {
	int size = 5;
	int *arr = (int*)malloc(size * sizeof(int));

	for (int i = 0; i < size; ++i) {
		scanf("%d", &arr[i]);
	}

	sort(arr, size);

	for (int i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}
	putchar(10);
	free(arr);
}
