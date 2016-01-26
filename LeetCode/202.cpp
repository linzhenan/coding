//Happy Number

class Solution {
public:
	bool isHappy(int n) {
		unordered_map<int, bool> map;
		while (true) {
			if (n == 1)
				return true;
			else if (map.find(n) == map.end())
				map[n] = true;
			else
				return false;
			int sum = 0;
			while (n) {
				int r = n % 10;
				sum += r * r;
				n = n / 10;
			}
			n = sum;
		}
	}
};