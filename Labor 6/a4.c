int amirStrlen(const char* in) {
    int len = 0;
    while (*in != '\0') {
        len++;
        in++;
    }
    return len;
}

void append(char *a, char *b) {
    int ia = amirStrlen(a);
    int ib = amirStrlen(b);
    
    int j = 0;
    for (int i = ia; i < ia + ib; i++) {
        a[i] = b[j];
        j++;
    }
}
