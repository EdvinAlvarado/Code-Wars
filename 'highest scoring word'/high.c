#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/*
** @param str: a C-string containing only lowercase letters and spaces (' ')
** @return:    a C-string allocated on the heap containing the highest scoring word of str
*/
char* highestScoringWord(char* str) {
	char* ret = malloc(strlen(str) * sizeof(char));
	int n = 0;

	char* pch = strtok(str, " ");
	while (pch != NULL) {
		int word_val = 0;
		for (int i = 0; i < strlen(pch); i++) {
			word_val += (int)pch[i] - 96;
		}
		if (word_val > n) {
			*ret = *pch;
			n = word_val;
		}
		pch = strtok(NULL, " ");
	}
	return ret;
}

// Doesnt work
int main() {
	char* p = "aa b";
	char* ret = highestScoringWord(p);
	for (int i = 0; i < strlen(ret); i++) {
		printf("%c", ret[i]);
	}
	return 0;
}
