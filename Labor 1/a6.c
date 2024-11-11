#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    long ganz = 1;
    float gleit = 1.0;
    char zeichen = 'c';

    scanf("%li", &ganz);
    printf("Ganzzahlen    : %.10li \n", ganz);

    scanf("%f", &gleit);
    printf("Gleitkommazahl: %.5f \n", gleit);

    scanf("%s", &zeichen);
    printf("Zeichen       : %c \n", zeichen);
    return 0;
}
