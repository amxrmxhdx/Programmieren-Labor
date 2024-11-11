#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char *argv[]) {
    int x, y, m = 0;

    scanf("%d %d", &y, &x);

    for (int i = 0; i < y; i++) {
        for (int f = 0; f < x; f++) {
            char c = m ? '-' : '+';
            printf("%c", c);
            m = m ? 0 : 1;
        }
        printf("\n");
        if (x % 2 == 0) {
            m = m ? 0 : 1;
        }
    }

    return 0;
}
