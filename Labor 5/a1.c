#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int a = 0;
    double s;
    int iX;
    
    double ar[4];
    
    scanf("%lf %lf %lf %lf", &ar[0], &ar[1], &ar[2], &ar[3]);
    
    for (int i = 0; i < 4; i++) {
        double t = ar[i];
        
        if (!a) {
            a++;
            s = t;
        }
        
        if (t < s) {
            s = t;
            iX = i;
        }
    }
    
    printf("Kleinste Zahl: %.1lf an Index %i", s, iX);
    
    return 0;
}
