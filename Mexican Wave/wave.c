#include <stdlib.h> // size_t
#include <string.h> // strlen
#include <ctype.h> // toupper
/* you don't have to allocate memory, use target */
/* y string is always null terminated */
/* each string in target has length strlen(y) + 1 */
void wave(const char *y, char **target)
{
	for (size_t i = 0, c = 0; i < strlen(y); i++) {
		if (y[i] != ' ') {
			strcpy(target[c], y);
			target[c++][i] = toupper(y[i]);
		}
	}
}
