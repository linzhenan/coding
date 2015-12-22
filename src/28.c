int strStr(char* haystack, char* needle) {
    int len1 = strlen(haystack);
    int len2 = strlen(needle);
    if (len1 < len2)
        return -1;
    else if (len1 == 0 && len2 == 0)
        return 0;
    for (int i = 0; i < len1; i++) {
        int j = 0;
        while (haystack[i + j] == needle[j] && j < len2)
            j++;
        if (j == len2)
            return i;
    }
    return -1;
}