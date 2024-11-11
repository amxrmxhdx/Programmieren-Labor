#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int zahl1 = 1;
    int zahl2 = 2;
    int zahl3 = 3;
    scanf("%i", &zahl1);
    scanf("%i", &zahl2);
    scanf("%i", &zahl3);
    printf("Zahl 3: %4.i \n", zahl3);
    printf("Zahl 2: %4.i \n", zahl2);
    printf("Zahl 1: %4.i \n", zahl1);
    return 0;
}
