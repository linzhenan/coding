int min(int a, int b) {
    return a < b ? a : b;
}
int max(int a, int b) {
    return a > b ? a : b;
}
int maxArea(int* height, int heightSize) {
    int i = 0;
    int j = heightSize - 1;
    int result = 0;
    while (i < j) {
        int area = min(height[j], height[i]) * (j - i);
        result = max(result, area);
        if (height[i] <= height[j])
            i++;
        else
            j--;
    }
    return result;
}