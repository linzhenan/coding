char* longestCommonPrefix(char** strs, int strsSize) {
    char* prefix;
    char ch;
    int i, j;
    int len, len_max, len_min;
    
    if (strsSize == 0)
        return "";

    len_max = strlen(strs[0]);
    len_min = strlen(strs[0]);
    for (i = 1; i < strsSize; i++) {
        len = strlen(strs[i]);
        if (len > len_max)
            len_max = len;
        if (len < len_min)
            len_min = len;
    }
    
    prefix = malloc(sizeof(char) * (len_min + 1));
    
    for (j = 0; j < len_min; j++)
    {
        ch = strs[0][j];
        int same = 1;
        for (i = 1; i < strsSize; i++) {
            if (ch == strs[i][j]) {
                continue;
            }
            else {
                same = 0;
                break;
            }
        }
        if (same == 0)
            break;
        else
            prefix[j] = ch;
    }
    prefix[j++] = '\0';
    
    return prefix;
}