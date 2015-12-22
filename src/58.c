int lengthOfLastWord(char* s) {
    int slen = strlen(s);
    int wlen = 0;
    for (int i = 0; i < slen; i++) {
        if (i > 0 && s[i - 1] == ' ' && s[i] != ' ')
            wlen = 0;
        if (s[i] != ' ')
            wlen++;
    }
    return wlen;
}