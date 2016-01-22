//Largest Number

class Solution {
public:
	static int cmp(string a, string b) {
		if (a + b > b + a)
			return 1;
		else
			return 0;
	}
	string largestNumber(vector<int>& nums) {
		vector<string> numstr;
		for (int i = 0; i < nums.size(); i++) {
			stringstream ss;
			ss << nums[i];
			numstr.push_back(ss.str());
		}
		sort(numstr.begin(), numstr.end(), cmp);//must re-define sorting
		string res;
		for (int i = 0; i < numstr.size(); i++)
			res += numstr[i];
		int start = 0;
		while (res[start] == '0' && start < res.size() - 1)//for the case [0, 0]
			start++;
		return res.substr(start);
	}
};