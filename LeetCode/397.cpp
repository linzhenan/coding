class Solution {
public:
	int integerReplacement(int n) {
		queue<long long> pos;
		queue<long long> stp;
		pos.push(n);
		stp.push(0);
		while (!pos.empty()) {
			long long p = pos.front();
			long long s = stp.front();
			pos.pop();
			stp.pop();
			if (p == 1)
				return s;
			if (p & 1) {
				pos.push(p + 1);
				stp.push(s + 1);
				pos.push(p - 1);
				stp.push(s + 1);
			}
			else {
				pos.push(p / 2);
				stp.push(s + 1);
			}
		}
		return -1;
	}
};