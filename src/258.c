int addDigits(int num) {
    if (num > 9)
    {
        int sum = 0;
        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        addDigits(sum);
    }
    else
    {
        return num;
    }
}