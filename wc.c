#include <stdio.h>
#include <string.h>
#include "colors.h"

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
	if (strcmp(argv[i], "-c") == 0) {
	    printf("%sERR:%s the argument \"-c\" is not implemented yet", ANSI_COLOR_RED, ANSI_COLOR_RESET);
	    break;
	} else if (strcmp(argv[i], "-l") == 0) {
	    printf("%sERR:%s the argument \"-l\" is not implemented yet", ANSI_COLOR_RED, ANSI_COLOR_RESET);
	    break;
	} else if (strcmp(argv[i], "-w") == 0) {
	    printf("%sERR:%s the argument \"-w\" is not implemented yet", ANSI_COLOR_RED, ANSI_COLOR_RESET);
	    break;
	}
    }

    FILE *fptr;

    for (int i = 1; argc > i; i++) {
	fptr = fopen(argv[i], "r");

	fseek(fptr, 0l, SEEK_END); // Preparation for getting the size of the file.
	size_t len = ftell(fptr); // get the length of the input file.
	fclose(fptr);
	fptr = fopen(argv[i], "r");
	
	char ch;
	int lineCount = 0l;
	while (ch != EOF) {
	    ch = fgetc(fptr);
	    if (ch == '\n') {
		lineCount++;
	    }
	}
	fclose(fptr);
	fptr = fopen(argv[i], "r");

	ch = 69;
	int wordCount = lineCount;
	while (ch != EOF) {
	    ch = fgetc(fptr);
	    if (ch == ' ') {
		wordCount++;
	    }
	}

	printf("Charactor count: %ld\nLine count: %d\nWord count: %d\n", len, lineCount, wordCount);
	fclose(fptr);
    }
    
    return 0;
}
