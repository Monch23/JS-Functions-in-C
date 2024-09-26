#include <stdio.h>
#include <stdlib.h>

void doubleElem(int *element) {
	*element *= 2;
}

void map(int *arr, int size, void (*action)(int*)) {
	for (int i = 0; i < size; ++i) {
		action(&arr[i]);
	}
}

int main() {
	int size = 5;
	int *arr = (int*)malloc(size * sizeof(int));

	for (int i = 0; i < size; ++i) {
		arr[i] = i + 1;
	}

	map(arr, size, doubleElem);

	for (int i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}
	putchar(10);
	free(arr);
}
