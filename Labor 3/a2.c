#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char *argv[]) {
    int n, m = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        switch (m) {
            case 0:
                printf("*");
                m = 1;
                break;
            case 1:
                printf("_");
                m = 0;
                break;
        }
    }

    return 0;
}
