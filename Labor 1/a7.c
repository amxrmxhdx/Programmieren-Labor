#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int zahl1;
    int zahl2;

    scanf("%d", &zahl1);
    scanf("%d", &zahl2);

    printf("1. Zahl: 0x%x\n", zahl1);
    printf("2. Zahl: 0x%X\n", zahl2);

    return 0;
}
