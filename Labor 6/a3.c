void ownStrcpy(char *cS, char *oS) {
    int o_size = sizeof(oS);
    int i = 0;
    while (oS[i] != '\0') {
        cS[i] = oS[i];
        i++;
    }
    if (o_size - 1 > i) {
        for (int j = i; j < o_size; j++) {
            cS[j] = '\0';
        }
    }
}
