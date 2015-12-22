int myAtoi(char* str) {
    int len = strlen(str);
    int i = 0;
    int val = 0;
    int sign = 0;
    int max = 0x7FFFFFFF;
    int min = 0x80000000;
    
    while (str[i] == ' ')
    {
        i++;
        continue;
    }

    if (str[i] == '-')
    {
        sign = 1;
        i++;
    }
    else if (str[i] == '+')
    {
        i++;
    }    
    
    for (; i < len; i++)
    {
        if ('0' <= str[i] && str[i] <= '9')
        {
            if (sign)//<0
            {
                if ((min + (str[i] - '0')) / 10 <= val)
                {
                    val = val * 10 - (str[i] - '0');
                }
                else
                {
                    val = min;//overflow
                    break;
                }
            }
            else//>=0
            {
                if ((max - (str[i] - '0')) / 10 >= val)
                {
                    val = val * 10 + str[i] - '0';
                }
                else
                {
                    val = max;//overflow
                    break;
                }
            }
        }
        else
        {
            break;//not a digit
        }
    }
        
    return val;
}