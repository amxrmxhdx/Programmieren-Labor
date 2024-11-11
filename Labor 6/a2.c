void toUpper(char *arr) {
    int i = 0;
    while(arr[i] != '\0') {
        char c = arr[i];
        if (c >= 'a' && c <= 'z') {
            arr[i] = (~0x20) & c;
        }
        i++;
    }
}
