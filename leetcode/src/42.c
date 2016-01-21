int min(int a, int b) {
    return a < b ? a : b;
}
int max(int a, int b) {
    return a > b ? a : b;
}
int trap(int* height, int heightSize) {
    int *max_left = malloc(sizeof(int) * heightSize);
    int *max_right = malloc(sizeof(int) * heightSize);
    int result = 0;
    max_left[0] = 0;
    max_right[heightSize - 1] = 0;
    for (int i = 1; i < heightSize; i++) {
        max_left[i] = max(max_left[i - 1], height[i - 1]);
        max_right[heightSize - i - 1] = max(max_right[heightSize - i], height[heightSize - i]);
    }
    for (int i = 0; i < heightSize; i++)
        result += max(min(max_left[i], max_right[i]) - height[i], 0);
	free(max_left);
	free(max_right);
    return result;
}