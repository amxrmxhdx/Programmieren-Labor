#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    float w, h;

    float bmi;

    scanf("%f %f", &w, &h);

    h = h / 10;
    w = w / 10;

    bmi = w / (h * h);

    printf("Der BMI liegt bei: %.2f!", bmi);

    return 0;
}
