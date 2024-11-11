int stringlength(char in[]) {
    int p = 0, l = 0;
    while (in[p] != '\0') {
        l++;
        p++;
    }
    
    return l;
}