//Min Stack

class MinStack {
private:
	stack<int> stk;
	stack<int> minstk;
public:
	void push(int x) {
		if (minstk.empty() || x <= minstk.top())
			minstk.push(x);
		stk.push(x);
	}

	void pop() {
		if (!stk.empty()) {
			if (stk.top() == minstk.top())
				minstk.pop();
			stk.pop();
		}
	}

	int top() {
		return stk.top();
	}

	int getMin() {
		return minstk.top();
	}
};