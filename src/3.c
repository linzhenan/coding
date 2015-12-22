int lengthOfLongestSubstring(char* s) {
    
    int i, j;
    int len = strlen(s);
    
    int *last_pos = malloc(sizeof(int) * len);
    int last_pos_hash[256];
    
    int max = 0;
    int distance = 0;
    
    for (i = 0; i < 256; i++)
        last_pos_hash[i] = -1;
        
    for (i = 0; i < len; i++) {
        last_pos[i] = last_pos_hash[s[i]];
        last_pos_hash[s[i]] = i;
    }
        
    i = 0;
    j = 0;
    while (j < len) {
        if (last_pos[j] < i)
            j++;
        else
            i++;
        distance = j - i;
        if (distance > max)
            max = distance;
    }
        
    free(last_pos);
    return max;
}