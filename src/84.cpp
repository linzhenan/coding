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
                max(result, height[tmp] * i) ://��ջ��Ԫ��֮ǰ��ջ��һ����ջ�׸�
                max(result, height[tmp] * (i - stk.top() - 1));//����ջ��ջ��Ԫ��һ����С����һ��Ԫ��
            }
        }
        return result;
    }
};