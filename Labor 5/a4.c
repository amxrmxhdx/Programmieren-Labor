#include <stdio.h>

int main() {
    char vowel, str[40];
    scanf("%c %s", &vowel, str);

    for (int i = 0; str[i]; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
            str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            str[i] = vowel;
        }
    }

    printf("%s\n", str);

    return 0;
}
