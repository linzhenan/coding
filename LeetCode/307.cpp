//Range Sum Query - Mutable
//http://baike.baidu.com/view/1420784.htm
//Binary Indexed Tree(BIT)

class NumArray {
private:
	vector<int> c;
	vector<int> a;
	int lowbit(int k) {
		k++;
		return k & -k;
	}
	int sum(int k) {
		int num = 0;
		k++;
		while (k) {
			num += c[k - 1];//BIT's index is one-based.
			k -= k & -k;
		}
		return num;
	}
public:
	NumArray(vector<int> &nums) {
		this->c = vector<int>(nums.size(), 0);
		this->a = vector<int>(nums.size(), 0);
		for (int i = 0; i < nums.size(); i++)
			update(i, nums[i]);
	}

	void update(int i, int val) {
		int diff = val - this->a[i];//update diff rather than val
		this->a[i] = val;
		while (i < c.size()) {
			c[i] += diff;
			i += lowbit(i);
		}
	}

	int sumRange(int i, int j) {
		int sum1 = 0;
		if (i > 0)
			sum1 = sum(i - 1);
		int sum2 = sum(j);
		return sum2 - sum1;
	}
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);