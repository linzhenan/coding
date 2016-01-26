/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int cflag = 1;
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] == 9 && cflag == 1) {
            digits[i] = 0;
            cflag = 1;
        }
        else {
            digits[i] += cflag;
            cflag = 0;
            break;
        }
    }
    int *result;
    if (cflag) {
        result = malloc(sizeof(int) * (digitsSize + 1));
        memcpy(result + 1, digits, sizeof(int) * digitsSize);
        result[0] = cflag;
        *returnSize = digitsSize + 1;
    }
    else {
        result = digits;
        *returnSize = digitsSize;
    }
    return result;
}