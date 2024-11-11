#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    char input[40];
    int count = 0;

    fgets(input, sizeof(input), stdin);

    for (int i = 0; input[i]; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            count++;
        }
    }

    printf("%d Kleinbuchstaben", count);

    return 0;
}
