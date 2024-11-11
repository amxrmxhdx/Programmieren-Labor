#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Celsius Fahrenheit\n");
    for (int i = -20; i < 301; i += 20) {
        int f = (i * 9) / 5 + 32;
        printf("%7d %10d\n", i, f);
    }
    return 0;
}
