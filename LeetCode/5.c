char* longestPalindrome(char* s) {
    int len = strlen(s);
    int i, j, k;
    int p_len_max = 0;
    int start = 0, end = 0;
    char *p = malloc(sizeof(char) * 1001);
    
    for (i = 0; i < len; i++)
    {
        int p_len;
        
        //odd
        j = i;
        k = i;
        while (0 <= j && k <= len - 1)
        {
            if (s[j] == s[k])
            {
                j--;
                k++;
            }
            else
            {
                break;
            }
        }
        p_len = (k - 1) - (j + 1) + 1;
        if (p_len > p_len_max)
        {
            p_len_max = p_len;
            start = j + 1;
            end = k - 1;
        }
        
        //even
        j = i;
        k = i + 1;
        while (0 <= j && k <= len - 1)
        {
            if (s[j] == s[k])
            {
                j--;
                k++;
            }
            else
            {
                break;
            }
        }
        p_len = k - j - 1;
        if (p_len > p_len_max)
        {
            p_len_max = p_len;
            start = j + 1;
            end = k - 1;
        }
    }
    
    memcpy(p, s + start, end - start + 1);
    p[end - start + 1] = '\0';
    return p;
}