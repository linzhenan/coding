class Solution {
private:
	vector<int> cpy;
	int myrand(int i, int j) {
		if (i == j)
			return i;
		int interval = RAND_MAX / (j - i);
		int r = rand();
		return i + r / interval;
	}
public:
	Solution(vector<int> nums) {
		srand(time(NULL));
		int n = nums.size();
		for (int i = 0; i < n; i++)
			cpy.push_back(nums[i]);
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return cpy;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		int n = cpy.size();
		vector<int> res(cpy);
		for (int i = 0; i < n; i++) {
			//int k = myrand(0, i);
			int k = rand() % n;
			int tmp = res[k];
			res[k] = res[i];
			res[i] = tmp;
		}
		return res;
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(nums);
* vector<int> param_1 = obj.reset();
* vector<int> param_2 = obj.shuffle();
*/