#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    char input[40];
    int count = 0;

    fgets(input, sizeof(input), stdin);

    for (int i = 0; input[i]; i++) {
        if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' ||input[i] == 'o' ||input[i] == 'u' || input[i] == 'A' || input[i] == 'E' || input[i] == 'I' ||input[i] == 'O' ||input[i] == 'U') {
            count++;
        }
    }

    printf("%d Vokale", count);

    return 0;
}
