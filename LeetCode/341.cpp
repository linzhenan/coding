/**
* // This is the interface that allows for creating nested lists.
* // You should not implement it, or speculate about its implementation
* class NestedInteger {
*   public:
*     // Return true if this NestedInteger holds a single integer, rather than a nested list.
*     bool isInteger() const;
*
*     // Return the single integer that this NestedInteger holds, if it holds a single integer
*     // The result is undefined if this NestedInteger holds a nested list
*     int getInteger() const;
*
*     // Return the nested list that this NestedInteger holds, if it holds a nested list
*     // The result is undefined if this NestedInteger holds a single integer
*     const vector<NestedInteger> &getList() const;
* };
*/
class NestedIterator {
private:
	vector<int> v;
	int pos;
public:
	void myhelper(vector<int>& v, vector<NestedInteger> &list) {
		for (auto e : list) {
			if (e.isInteger()) v.push_back(e.getInteger());
			else myhelper(v, e.getList());
		}
	}
	NestedIterator(vector<NestedInteger> &nestedList) {
		pos = 0;
		v.clear();
		myhelper(v, nestedList);
	}

	int next() {
		return v[pos++];
	}

	bool hasNext() {
		return pos < v.size();
	}
};

/**
* Your NestedIterator object will be instantiated and called as such:
* NestedIterator i(nestedList);
* while (i.hasNext()) cout << i.next();
*/