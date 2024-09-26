#include <stdio.h>
#include <stdlib.h>

int greateE(int defVal, int comparable) {
	return (defVal > comparable);
}

int find(int *arr, int size, int (*check)(int, int), int in) {

	if (arr == NULL || size <= 0) {
		return -1;
	}

	for (int i = 0; i < size; ++i) {
		if (check(arr[i], in)) {
			return arr[i];
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

	int res = find(arr, size, greateE, 3);

	printf("%d \n", res);

	free(arr);
}
