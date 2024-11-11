#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char *argv[]) {
    int x, y;

    scanf("%d %d", &y, &x);

    for (int i = 0; i < y; i++) {
        for (int f = 0; f < x; f++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
