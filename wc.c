#include <stdio.h>
#include <string.h>
#include "colors.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char mode = 0;
    char ignoreLine = 0;

    for (int i = 1; i < argc; i++) {
	if (strcmp(argv[i], "-c") == 0) {
	    mode = 1;
	    ignoreLine = i;
	    break;
	} else if (strcmp(argv[i], "-l") == 0) {
	    mode = 2;
	    ignoreLine = i;
	    break;
	} else if (strcmp(argv[i], "-w") == 0) {
	    mode = 3;
	    ignoreLine = i;
	    break;
	}
    }

    FILE *fptr;

    for (int i = 1; argc > i; i++) {
	if (ignoreLine == i) { continue; }

	fptr = fopen(argv[i], "r");

	size_t len;
	if (mode == 0 | mode == 1) {
	    fseek(fptr, 0l, SEEK_END); // Preparation for getting the size of the file.
	    len = ftell(fptr); // get the length of the input file.
	    fclose(fptr);
	    fptr = fopen(argv[i], "r");
	}
	
	int lineCount = 0l;
	char ch;
	if (mode != 1) {
	    while (ch != EOF) {
		ch = fgetc(fptr);
		if (ch == '\n') {
		    lineCount++;
		}
	    }
	    fclose(fptr);
	    fptr = fopen(argv[i], "r");
	}

	int wordCount = lineCount;
	ch = 69;
	if (mode == 0 | mode == 3) {
	    while (ch != EOF) {
		ch = fgetc(fptr);
		if (ch == ' ') {
		    wordCount++;
		}
	    }
	}

	switch (mode) {
	    case 0: 
		printf("Charactor count: %ld\nLine count: %d\nWord count: %d\n", len, lineCount, wordCount);
		break;
	    case 1:
		printf("%ld\n", len);
		break;
	    case 2: 
		printf("%d\n", lineCount);
		break;
	    case 3:
		printf("%d\n", wordCount);
	}
	fclose(fptr);
    }
    
    return 0;
}
