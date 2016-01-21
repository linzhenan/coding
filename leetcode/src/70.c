int f(int n) {
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
        return f(n - 1) + f(n - 2);
}
int climbStairs(int n) {
    //return f(n); //DFS time out!
    int *step = malloc(sizeof(int) * n);
    step[0] = 1;
    step[1] = 2;
    for (int i = 2; i < n; i++) {
        step[i] = step[i - 1] + step[i - 2];
    }
    int ans = step[n - 1];
    free(step);
    return ans;
}