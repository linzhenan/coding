class Solution {
public:
	int hIndex(vector<int>& citations) {
		int n = citations.size();
		vector<int> h(n + 1, 0);
		for (int i = 0; i < citations.size(); i++) {
			int cite = citations[i];
			if (cite > n)
				h[n]++;
			else
				h[cite]++;
		}
		int at_least_i_cites = 0;
		for (int i = n; i >= 0; i--) {
			at_least_i_cites += h[i];
			if (at_least_i_cites >= i)
				return i;
		}
		return 0;
	}
};