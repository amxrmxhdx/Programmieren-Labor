#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    char gesch;
    float weight;
    float V;
    float e;
    float phi = 0.8;

    scanf("%c %f %f %f", &gesch, &weight, &V, &e);

    float A = V * (e / 100) * phi;

    float r;

    switch (gesch) {
        case 'm':
            r = 0.7;
            break;
        case 'w':
            r = 0.60;
            break;
        case 'k':
            r = 0.80;
            break;
    }

    float W = A / (weight * r);

    printf("%.2f Promille", W);


    return 0;
}
