#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(int argc, char *argv[])
{
    float fah, cel;

    scanf("%f", &fah);
    cel = (5 * (fah - 32)) / 9;
    printf("%.1f Grad Fahrenheit = %.1f Grad Celsius", fah, cel);
    return 0;
}
