//Range Sum Query - Immutable

class NumArray {
public:
	vector<int> nums;
	NumArray(vector<int> &nums) {
		this->nums = vector<int>(nums);
		for (int i = 1; i < this->nums.size(); i++)
			this->nums[i] = this->nums[i] + this->nums[i - 1];
	}

	int sumRange(int i, int j) {
		if (i == 0)
			return nums[j];
		else
			return nums[j] - nums[i - 1];
	}
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);