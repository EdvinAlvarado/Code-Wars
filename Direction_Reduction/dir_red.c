#include <string.h>
// FIXME
// arr: directions to reduce, sz: size of arr, lg size of returned array
// function result will be freed
char** dirReduc(char** arr, int sz, int* lg) {
	*lg = 0;
	char** stack = calloc(sz, sizeof(char*));

	for (int i = 0; i < sz; i++) {
		if (
			*lg > 0 &&
			(
				(stack[(*lg)-1][0] == 'N' && arr[i][0] == 'S') ||
				(stack[(*lg)-1][0] == 'S' && arr[i][0] == 'N') ||
				(stack[(*lg)-1][0] == 'E' && arr[i][0] == 'W') ||
				(stack[(*lg)-1][0] == 'W' && arr[i][0] == 'E')
			)
		) {(*lg)--;}
		else {strcpy(stack[(*lg)++], arr[i]);}
	}

	return stack;
}
