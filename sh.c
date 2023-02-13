#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char changeDir(char cmd[100]) {
    char command[100] = "";
    strcpy(command, cmd);
    strtok(command, " ");
    
    if (strcmp(command, "cd") == 0) {
	char *pathPtr = command;
	pathPtr += 3;
	char path[97];
	strcpy(path, pathPtr);
	strtok(path, "\n");

	int success = chdir(path);
	char s[100];
	setenv("PWD", getcwd(s, 100), 1);

	return 0;
    } else {
	return 1;
    }
}

int main() {
    while (0 == 0) {
	char s[100];
	char command[100] = "";

	printf("%s $ ", getcwd(s, 100));
	fgets(command, sizeof(command), stdin);

	if (strcmp(command, "exit\n") == 0) { break; }
	if (changeDir(command) == 0) { continue; }

	system(command);
    }
    return 0;
}
