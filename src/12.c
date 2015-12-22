// 1  5  10  50  100  500 1000
// I  V   X   L    C    D    M

void intTo5(char *str, int num) {
    int i = 0;
    if (num < 4) {//0~3
        int j;
        for (j = 0; j < num; j++)
            str[i++] = 'I';
    }
    else if (num < 5) {//4
        str[i++] = 'I';
        str[i++] = 'V';
    }
    else if (num < 9) {//5~8
        int j;
        str[i++] = 'V';
        for (j = 0; j < (num - 5); j++)
            str[i++] ='I';
    }
    else {//9
        str[i++] = 'I';
        str[i++] = 'X';
    }
    str[i++] = '\0';
}
void intTo50(char *str, int num) {
    int i = 0;
    if (num < 40) {//0~39
        int j;
        for (j = 0; j < num / 10; j++)
            str[i++] = 'X';
    }
    else if (num < 50) {//40~49
        str[i++] = 'X';
        str[i++] = 'L';
    }
    else if (num < 90) {//50~89
        int j;
        str[i++] = 'L';
        for (j = 0; j < (num - 50) / 10; j++)
            str[i++] ='X';
    }
    else {//90~99
        str[i++] = 'X';
        str[i++] = 'C';
    }
    num = num % 10;
    intTo5(str + i, num);//1~9    
}
void intTo500(char *str, int num) {
    int i = 0;
    if (num < 400) {//0~399
        int j;
        for (j = 0; j < num / 100; j++)
            str[i++] = 'C';
    }
    else if (num < 500) {//400~499
        str[i++] = 'C';
        str[i++] = 'D';
    }
    else if (num < 900) {//500~899
        int j;
        str[i++] = 'D';
        for (j = 0; j < (num - 500) / 100; j++)
            str[i++] ='C';
    }
    else {//900~999
        str[i++] = 'C';
        str[i++] = 'M';
    }
    num = num % 100;
    intTo50(str + i, num);//1~99
}
void intTo5000(char *str, int num) {
    int i = 0;
    if (num < 4000) {
        int j;
        for (j = 0; j < num / 1000; j++)
            str[i++] = 'M';
    }
    //else...
    num = num % 1000;
    intTo500(str + i, num);//0~999
}

char* intToRoman(int num) {
    char *str = malloc(sizeof(char) * 50);
    intTo5000(str, num);
    return str;
}