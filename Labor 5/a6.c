#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    char input[41];
    int start, end;
    
    scanf("%40s %d %d", input, &start, &end);
    
    printf("%s %d-%d: ", input, start, end);
    
    for (int i = start; i <= end && input[i] != '\0'; i++) {
        putchar(input[i]);
    }
    printf("\n");

    return 0;
}
