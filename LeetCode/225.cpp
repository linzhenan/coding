#include <queue>
#include <iostream>

using namespace std;

class Stack {
private:
    queue<int> q1;
    queue<int> q2;
public:
    // Push element x onto stack.
    void push(int x) {
        if (q1.empty())
            q2.push(x);
        else
            q1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if (q1.empty()) {
            int n = q2.size();
            for (int i = 0; i < n - 1; i++) {
            //for (int i = 0; i < q2.size() - 1; i++) {
                q1.push(q2.front());
                q2.pop();
            }
            q2.pop();
        }
        else {
            int n = q1.size();
            for (int i = 0; i < n - 1; i++) {
            //for (int i = 0; i < q1.size() - 1; i++) {
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
        }
    }

    // Get the top element.
    int top() {
        int ret;
        if (q1.empty()) {
            int n = q2.size();
            for (int i = 0; i < n - 1; i++) {
            //for (int i = 0; i < q2.size() - 1; i++) {
                q1.push(q2.front());
                q2.pop();
            }
            ret = q2.front();
            q1.push(q2.front());
            q2.pop();
        }
        else {
            int n = q1.size();
            for (int i = 0; i < n - 1; i++) {
            //for (int i = 0; i < q1.size() - 1; i++) {
                q2.push(q1.front());
                q1.pop();
            }
            ret = q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        return ret;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

void main() {
	Stack stk;
	stk.push(1);
	stk.push(2);
	stk.push(3);
	cout << stk.top();
}