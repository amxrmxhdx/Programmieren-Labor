#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    float note, sum = 0;
    int count = 0;

    while (count < 10) {
        if (scanf("%f", &note) != 1 || note < 1.0 || note > 6.0) {
            break;
        }
        sum += note;
        count++;
    }

    if (count > 0) {
        printf("Durchschnitt (N=%d): %.2f\n", count, sum / count);
    } else {
        printf("Durchschnitt (N=0): 0.00\n");
    }
    return 0;
}
