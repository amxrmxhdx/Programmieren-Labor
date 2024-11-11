int minimum(int numbers[], int l) {
    int m = numbers[0];
    for (int i = 0; i < l; i++) {
        if (numbers[i] < m) m = numbers[i];
    }
    return m;
}
