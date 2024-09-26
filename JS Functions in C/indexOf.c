#include <stdio.h>
#include <stdlib.h>

int indexOf(int *arr, int size, int index) {

	if (size <= 0 || index <= 0) {
		return -1;
	}	

	for (int i = 0; i < size; ++i) {
		if (i == index) {
			return 1;
		}
	}

	return -1;
}

int main() {
	int size = 5;
	int *arr = (int*)malloc(size * sizeof(int));

	for (int i = 0; i < size; ++i) {
		arr[i] = i + 1;
	}

	int res = indexOf(arr, size, 5);

	printf("%d \n", res);

	free(arr);
}
