char* convert(char* s, int numRows) {
    int len = strlen(s);
    char *p = malloc(sizeof(char) * (len + 1));
    int i, j = 0;
    
    if (numRows == 0 || numRows == 1)
        return s;
    
    int row;    
    for (row = 0; row < numRows; row++)
    {
        int step = 2 * (numRows - 1);
        if (row == 0 || row == numRows - 1)
        {
            for (i = row; i < len; i += step)
                p[j++] = s[i];
        }
        else
        {
            int delta = 2 * (numRows - row - 1);
            for (i = row; i < len; i += step)
            {
                p[j++] = s[i];
                if (i + delta < len)
                    p[j++] = s[i + delta];
            }
        }
    }
    p[j++] = '\0';
    
    return p;
}