#include <stdio.h>
#include <stdlib.h>

void print(int elem) {

	printf("%d \n", elem);
}

void addPrint(int num) {

	printf("%d \n", num * 2);
}

void forEach(int *arr, int size, void (*fptr)(int)) {
	for (int i = 0; i < size; ++i) {
		fptr(arr[i]);
	}
}

int main() {
	int size = 8;
	int *arr = (int*)malloc(size * sizeof(int));

	for (int i = 0; i < size; ++i) {
		arr[i] = i + 1;
	}

	forEach(arr, size, addPrint);

	free(arr);
}
