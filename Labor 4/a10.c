int prime(int a) {
    if (a == 1) return 0;
    int i = 2;
    while (i <= a / 2) {
        int rem = a % i;
        if (rem != 0)
            i++;
        else return 0;
    }
    return 1;
}
