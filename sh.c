#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    while (0 == 0) {
	char command[100] = "";

	char *pwd = getenv("PWD");
	printf("%s $ ", pwd);
	fgets(command, sizeof(command), stdin);

	if (strcmp(command, "exit\n") == 0) { break; }

	system(command);
    }
    return 0;
}
