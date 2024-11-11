#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char *argv[]) {
    int x, y;

    scanf("%d %d", &y, &x);

    for (int i = 0; i < y; i++) {
        for (int f = 0; f < x; f++) {
            if (i == 0 || i == y - 1 || f == 0 || f == x - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
