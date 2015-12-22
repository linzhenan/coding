int reverse(int x) {
    int sign = 0;
    int y = 0;
    
    if (x < 0)
    {
        sign = 1;
        x = -x;
    }
    
    while (x > 0)
    {
        int max = 0x7FFFFFFF;
        if ((max - x % 10) / 10 >= y)
        {
            y = y * 10 + x % 10;
            x = x / 10;
        }
        else
        {
            y = 0;
            break;
        }
    }
    
    if (sign)
        y = -y;
    
    return y;
}