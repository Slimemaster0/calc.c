#include <stdio.h>

float str2Num(char str[]) {
    float num = 0;
    int size = 0;

    while (str[size] != '\0') { // get the size of a string.
	size++;
    }
    size--;

    int point = 0;
    for (int i = 0; i <= size; i++) {
	float carrentNum = str[i];
	carrentNum -= 48;

	if (str[i] == '.') {
	    point++;
	    for (int j = 0; j <= size - i; j++) {
		num /= 10;
	    }
	    continue;
	}

	if (str[i] == '-') {
	    continue;
	}

	if (point == 0) {
	    for (int j = 0; j < size - i; j++) {
		carrentNum *= 10;
	    }
	} else {
	    for (int j = 0; j < point; j++) {
		carrentNum /= 10;
	    }
	    point++;
	}

	if (str[0] !='-') {
	    num += carrentNum;
	} else {
	    num -= carrentNum;
	}
    }

    return num;
}

int main(int argc, char *argv[]) {
    switch (*argv[2]) {
	case '+': {
	    float result = str2Num(argv[1]) + str2Num(argv[3]);
	    if (result != (int)result) {
		printf("%.4f\n", result);
	    } else {
		printf("%.0f\n", result);
	    }
	    break;
	}
	case '-': {
	    float result = str2Num(argv[1]) - str2Num(argv[3]);
	    if (result != (int)result) {
		printf("%.4f\n", result);
	    } else {
		printf("%.0f\n", result);
	    }
	    break;
	}
	case '*': {
	    float result = str2Num(argv[1]) * str2Num(argv[3]);
	    if (result != (int)result) {
		printf("%.4f\n", result);
	    } else {
		printf("%.0f\n", result);
	    }
	    break;
	}
	case '/': {
	    float result = str2Num(argv[1]) / str2Num(argv[3]);
	    if (result != (int)result) {
		printf("%.4f\n", result);
	    } else {
		printf("%.0f\n", result);
	    }
	    break;
	}
    }

    return 0;
}
