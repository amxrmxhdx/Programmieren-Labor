#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    char input[41];
    int length = 0;

    scanf("%40s", input);
    
    while (input[length] != '\0') {
        length++;
    }
    
    for (int i = length - 1; i >= 0; i--) {
        putchar(input[i]);
    }
    printf("\n");

    return 0;
}
