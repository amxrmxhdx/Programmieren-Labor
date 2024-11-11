#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char *argv[]) {
    int s;
    scanf("%d", &s);

    for (int i = 0; i < s; i++) {
        for (int f = 0; f < s; f++) {
            if (i == 0 || i == s-1 || f == 0 || f == s-1 || i == f || i + f == s - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
