#include <stdio.h>
#include <stdlib.h>

int acc(int defVal, int comparable) {
	return defVal + comparable;
}

int reduce(int *arr, int size, int (*act)(int, int), int in) {
	int sum = 0;

	for (int i = 0; i < size; ++i) {
		sum += act(arr[i], in);
	}

	return sum;
}

int main() {
	int size = 5;
	int *arr = (int*)malloc(size * sizeof(int));

	for (int i = 0; i < size; ++i) {
		arr[i] = i + 1;
	}

	int res = reduce(arr, size, acc, 2);

	printf("%d \n", res);

	free(arr);
}
