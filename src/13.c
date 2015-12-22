//£É¡¢£Ö¡¢£Ø¡¢£Ì¡¢£Ã¡¢£ÄºÍ£Í
//1  5    10   50 100 500 1000

int charToWeight(char ch) {
    int w = 0;
    switch (ch) {
        case 'I': w = 1; break;
        case 'V': w = 5; break;
        case 'X': w = 10; break;
        case 'L': w = 50; break;
        case 'C': w = 100; break;
        case 'D': w = 500; break;
        case 'M': w = 1000; break;
    }
    return w;
}

int romanToInt(char* s) {
    int len = strlen(s);
    char last_diff_ch = s[len - 1];
    int num = charToWeight(s[len - 1]);
    for (int i = len - 2; i >= 0; i--) {
        int wL = charToWeight(s[i]);
        int wR = charToWeight(last_diff_ch);
        if (wL < wR) {
            num -= wL;
        }
        else {
            num += wL;
            if (wL > wR)
                last_diff_ch = s[i];
        }
    }
    return num;
}