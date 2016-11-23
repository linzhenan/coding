#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include<functional>
using namespace std;

class MedianFinder {
private:
	priority_queue<int> left;
	priority_queue<int, vector<int>, greater<int>> right;
public:

	// Adds a number into the data structure.
	void addNum(int num) {
		if (left.empty()) {
			left.push(num);
			return;
		}
		if (num <= left.top()) {
			left.push(num);
			if (left.size() > right.size() + 1) {
				right.push(left.top());
				left.pop();
			}
		}
		else {
			right.push(num);
			if (right.size() > left.size() + 1) {
				left.push(right.top());
				right.pop();
			}
		}
	}

	// Returns the median of current data stream
	double findMedian() {
		if (left.size() == right.size())
			return (left.top() + right.top()) / 2.0;
		else if (left.size() > right.size())
			return (double)left.top();
		else
			return (double)right.top();
	}
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

int main() {
	MedianFinder mf;
	mf.addNum(1);
	mf.addNum(2);
	mf.addNum(3);
	cout << mf.findMedian() << endl;
	mf.addNum(4);
	cout << mf.findMedian() << endl;
}