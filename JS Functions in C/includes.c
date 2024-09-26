#include <stdio.h>
#include <stdlib.h>

int includes(int *arr, int size, int target) {

	if (arr[0] == target || arr[size - 1] == target || arr[size / 2] == target) {
		return 1;
	}

	int start = 0;
	int end = size - 1;
	int mid = start + ((end - start) / 2);
	
	if (arr[mid] == target) {
		return 1;
	}

	while (start <= end) {
		if (target > arr[mid]) {
			start = mid + 1;
			mid = start + ((end - start) / 2);
		} else {
			end = mid - 1;
			mid = start + ((end - start) / 2);
		}
	}

	if (arr[mid] == target) {
		return 1;
	}

	return -1;
}

int main() {
	int size = 8;
	int *arr = (int*)malloc(size * sizeof(int));

	for (int i = 0; i < size; ++i) {
		arr[i] = i + 1;
	}

	int res = includes(arr, size, 8);

	printf("%d \n", res);
	free(arr);
}


