bool isPalindrome(int x) {
    int tmp = x;
    int len = 0, high = 1;
    int i;
    
    if (x < 0)
        return false;

    len++;
    tmp = tmp / 10;
    while (tmp > 0)
    {
        len++;
        tmp = tmp / 10;
        high = high * 10; 
    }
    
    for (i = 0; i < len / 2; i++)
    {
        if (x / high != x % 10)
            return false;
        x = x % high;
        x = x / 10;
        high = high / 100;
    }
    
    return true;
}