#include <stdio.h>
#include <stdlib.h>

int greatE(int defVal, int comparable) {
	return (defVal > comparable);
}

int lowE(int defVal, int comparable) {
	return (defVal < comparable);
}

int every(int *arr, int size, int (*expression)(int, int), int in) {

	if (arr == NULL || size <= 0) {
		return -1;
	}

	for (int i = 0; i < size; ++i) {
		if (!(expression(arr[i], in))) {
			return 0;
		}
	}

	return 1;
}

int main() {
	int size = 5;
	int *arr = (int*)malloc(size * sizeof(int));

	for (int i = 0; i < size; ++i) {
		arr[i] = i + 1;
	}

	int res = every(arr, size, greatE, 3);

	printf("%d \n", res);
	free(arr);

	return 0;
}
