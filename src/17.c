/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int DigitToNumOfChars(char digit) {
    if ('2' <= digit && digit <= '9') {
        if (digit == '7' || digit == '9')
            return 4;
        else
            return 3;
    }
    else {
        return 0;
    }
}
char mapping[10][4] = {
    {' ', ' ', ' ', ' ', },
    {' ', ' ', ' ', ' ', },
    {'a', 'b', 'c', ' ', },
    {'d', 'e', 'f', ' ', },
    {'g', 'h', 'i', ' ', },
    {'j', 'k', 'l', ' ', },
    {'m', 'n', 'o', ' ', },
    {'p', 'q', 'r', 's', },
    {'t', 'u', 'v', ' ', },
    {'w', 'x', 'y', 'z', },
};
void letterComb(char *digits, int pos, char **combinations, int segmentSize) {
    int subSegmentNum = DigitToNumOfChars(digits[pos]);
    if (subSegmentNum == 0)
        return;
    int subSegmentSize = segmentSize / subSegmentNum;

    for (int i = 0; i < subSegmentNum; i++, combinations += subSegmentSize) {
        for (int j = 0; j < subSegmentSize; j++)
            combinations[j][pos] = mapping[digits[pos] - '0'][i];
        letterComb(digits, pos + 1, combinations, subSegmentSize);
    }
}
char** letterCombinations(char* digits, int* returnSize) {
    int len = strlen(digits);
    if (len == 0)
        return NULL;
    int size = 1;
    for (int i = 0; i < len; i++)
        size *= DigitToNumOfChars(digits[i]);
    if (size == 0)
        return NULL;
    *returnSize = size;
    char **combinations = malloc(sizeof(char *) * size);
    for (int i = 0; i < size; i++) {
        combinations[i] = malloc(sizeof(char) * (len + 1));
        combinations[i][len] = '\0';
    }
    letterComb(digits, 0, combinations, size);
    return combinations;
}