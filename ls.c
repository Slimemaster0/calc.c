#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include "colors.h"

#define BUF_SIZE 256

int main(int argc, char *argv[]) {
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
	printf("%s\n", pDirent->d_name);
    }

    return 0;
}
