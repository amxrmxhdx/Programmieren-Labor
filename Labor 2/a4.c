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

    if (bmi <= 18.40) {
        printf("Untergewicht %.1f", bmi);
        return 0;
    } else if (bmi == 24.9f || bmi > 24.90) {
        printf("Uebergewicht %.1f", bmi);
        return 0;
    } else if (18.40 < bmi && bmi < 24.90) {
        printf("Normalgewicht %.1f", bmi);
        return 0;
    }

    return 0;
}
