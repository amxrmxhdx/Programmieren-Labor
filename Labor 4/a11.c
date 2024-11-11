int weekday(int d, int m, int y) {
    if (m < 3) {
        m += 12;
        y -= 1;
    }
    int k = y % 100;
    int j = y / 100;
    
    int w = (d + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
    int tag  = ((w + 5) % 7) + 1;
    return tag;
}
