class Solution {
public:
    int countOne(int num) {
        int count = 0;
        while (num) {
            if (num % 10 == 1)
                count++;
            num = num / 10;
        }
        return count;
    }
    int countDigitOneNative(int n) {
        if (n <= 0)
            return 0;
        int count = 0;
        for (int i = 1; i <= n; i++)
            count += countOne(i);
        return count;
    }
    int countDigitOne(int n) {
        if (n <= 0)
            return 0;
        int count = 0;
        for (long w = 1; w <= n; w *= 10) {
            int a = n / w;
            int b = a % 10;
            a = a / 10;
            int c = n % w;
            count += (a + (b + 8) / 10) * w + (b == 1) * (c + 1);
        }
        return count;
    }
};