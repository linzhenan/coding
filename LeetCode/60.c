void swap(char *ch1, char *ch2) { 
    if (ch1 != ch2) { 
        *ch1 ^= *ch2; 
        *ch2 ^= *ch1; 
        *ch1 ^= *ch2; 
    } 
} 
void cmp(const void *a, const void *b) { 
    return *(char *)a - *(char *)b; 
} 
void sort(char *ch1, char *ch2) {
    
}
char* getPermutation(int n, int k) { 
    char* result = malloc(sizeof(char) * (n + 1)); 
    int i; 
    for (i = 0; i < n; i++) 
        result[i] = i + '1'; 
    result[i] = '\0'; 
    
    int factorial[9]; 
    factorial[0] = 1; 
    factorial[1] = 1; 
    for (i = 2; i < 9; i++) 
        factorial[i] = factorial[i - 1] * i; 
    
    k--; 
    //qsort(&result[0], n, sizeof(char), cmp); 
    for (int pos = 0; pos < n - 1; pos++) { 
        swap(&result[pos], &result[pos + k / factorial[n - 1 - pos]]); 
        qsort(&result[pos + 1], n - pos - 1, sizeof(char), cmp); 
        k = k % factorial[n - 1 -pos]; 
    } 
    
    return result; 
}