#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class MyPriorityQueue {
private:
	vector<int> data;
public:
	void push(int val) {
		data.push_back(val);
		make_heap(data.begin(), data.end());
	}
	void pop() {
		pop_heap(data.begin(), data.end());
		data.pop_back();
	}
	int top() {
		return data.front();
	}
	int size() {
		return data.size();
	}
	int empty() {
		return data.empty();
	}
};
struct cmp {
	bool operator() (int a, int b) {
		return a > b;//MinHeap
	}
};
void main() {
	MyPriorityQueue myQ;
	myQ.push(3);
	myQ.push(5);
	myQ.push(2);
	myQ.push(4);

	while (!myQ.empty()) {
		cout << myQ.top() << endl;
		myQ.pop();
	}

	priority_queue<int, vector<int>, cmp> q;
	q.push(3);
	q.push(5);
	q.push(2);
	q.push(4);

	while (!q.empty()) {
		cout << q.top() << endl;
		q.pop();
	}

	
}