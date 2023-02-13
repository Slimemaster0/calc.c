#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* appendMode() {
    static char buffer[1000000] = { 0 };
    printf("input mode\n");

    while (0 == 0) {
	char inputBuffer[100];
	fgets(inputBuffer, sizeof(inputBuffer), stdin);

	if (strcmp(inputBuffer, ".\n") == 0) { break; }

	strcat(buffer, inputBuffer);
    }
    printf("exiting input mode\n");
    return buffer;
}

int main(int argc, char *argv[]) {

    char buffer[100000] = "";
    char buffer2[100000] = "";
    
    FILE *fileW = fopen(argv[1], "w");
    
    int result = 1;

    while (fileW != NULL) {
	char inputBuffer[10];
	scanf("%s", inputBuffer);
	
	if (strcmp(inputBuffer, "q") == 0) { result = 0; break; };
	if (strcmp(inputBuffer, "w") == 0) { fprintf(fileW, "%s", buffer); strcpy(buffer, ""); };
	if (strcmp(inputBuffer, "wq") == 0) { fprintf(fileW, "%s", buffer); strcpy(buffer, ""); result = 0; break; };

	if (strcmp(inputBuffer, "a") == 0) {
	    char *inputBuffer = appendMode();
	    strcat(buffer, inputBuffer);
	    strcat(buffer2, buffer);
	};
	    
	if (strcmp(inputBuffer, "p") == 0) {
	    printf("%s", buffer2);
	};
    }

    fclose(fileW);
    return result;
}
