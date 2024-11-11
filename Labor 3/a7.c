#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Fahrenheit      Celsius\n");
    for (int i = -20; i < 301; i += 20) {
        float c = 5.0 * (i - 32) / 9.0;
        printf("%10d      %7.2f\n", i, c);
    }
    return 0;
}
