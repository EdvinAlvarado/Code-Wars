#include <stdlib.h>
#include <stdbool.h>
//  return a dynamically allocated array
//  assign the length of this array to *z
//  memory will be freed by the test suite

int *array_diff(const int *arr1, size_t n1, const int *arr2, size_t n2, size_t *z) {
	int* ret = malloc(n1*sizeof(int));
	size_t index = 0;

	for (size_t i = 0; i < n1; i++) {
		bool test = true;
		for (size_t j = 0; j < n2; j++) {
			test = test && (arr1[i] != arr2[j]);
		}
		if (test) {
			ret[index++] = arr1[i];
		}
	}
	*z = index;
	return ret;
}
