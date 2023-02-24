#include <stdio.h>
#include <stdlib.h>
#include "colors.h"

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
	FILE *fp = fopen(argv[i], "r");

	if (fp == NULL) {
	    printf("%sERR: %scan't find file: %s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET, argv[i]);
	    exit(1);
	}

	char ch;
	while (ch != EOF) {
	    ch = fgetc(fp);
	    printf("%c", ch);
	}
    }
    return 0;
}
