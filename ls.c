#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "colors.h"

#define BUF_SIZE 256

int main(int argc, char *argv[]) {
    char showHidden = 0;
    for (int i = 1; i < argc; i++) {
	if (strcmp(argv[i], "-a") == 0) {
	    showHidden = 1;
	}
    }

    struct dirent *pDirent;
    char path[BUF_SIZE] = "\0";

    if (path[0] == '\0') {
	getcwd(path, BUF_SIZE);
    }

    DIR *dirP = opendir(path);
    if (dirP == NULL) { // test if the directory exists
	printf("%sERR:%s Couldn't open directory %s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET, path);
	return 1;
    }

    while ((pDirent = readdir(dirP)) != NULL) { // Print the files
	char *fname = strdup(pDirent->d_name);
	if (fname[0] != '.' || showHidden >= 1) {
		printf("%s\n", fname);
	}
    }

    return 0;
}
