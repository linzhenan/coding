char* addBinary(char* a, char* b) {
    int alen = strlen(a);
    int blen = strlen(b);
    if (blen > alen) {
        char *t = a;
        a = b;
        b = t;
        int len = alen;
        alen = blen;
        blen = len;
    }
    int cflag = 0;
    int j = blen - 1;
    for (int i = alen - 1; i >= 0; i--, j--) {
        if (j >= 0) {
            int sum = a[i] - '0' + b[j] - '0' + cflag;
            if (sum >= 2) {
                cflag = 1;
                a[i] = sum - 2 + '0';
            }
            else {
                cflag = 0;
                a[i] = sum + '0';
            }
        }
        else {
            int sum = a[i] - '0' + cflag;
            if (sum >= 2) {
                cflag = 1;
                a[i] = sum - 2 + '0';
            }
            else {
                cflag = 0;
                a[i] = sum + '0';
            }
        }
    }
    char *c;
    if (cflag) {
        c = malloc(sizeof(char) * (alen + 1 + 1));
        memcpy(c + 1, a, sizeof(char) * alen);
        c[0] = '1';
        c[alen + 1] = '\0';
    }
    else {
        c = a;
    }
    return c;
}