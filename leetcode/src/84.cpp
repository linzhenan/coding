class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        height.push_back(0);
        stack<int> stk;
        int result = 0;
        for (int i = 0; i < height.size(); ) {
            if (stk.empty() || height[i] > height[stk.top()]) {
                stk.push(i++);
            }
            else {
                int tmp = stk.top();
                stk.pop();
                result =
                stk.empty() ? 
                max(result, height[tmp] * i) ://在栈底元素之前出栈的一定比栈底高
                max(result, height[tmp] * (i - stk.top() - 1));//递增栈中栈顶元素一定不小于下一个元素
            }
        }
        return result;
    }
};