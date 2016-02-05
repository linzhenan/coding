#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
	static bool cmp(int a, int b) {
		return a > b;
	}
public:
	vector<int> topK(vector<int> rec, int k) {
		vector<int> topk = vector<int>(k);
		for (int i = 0; i < k; i++)
			topk[i] = rec[i];
		make_heap(topk.begin(), topk.end(), cmp);
		for (int i = k; i < rec.size(); i++) {
			if (rec[i] > topk[0]) {
				pop_heap(topk.begin(), topk.end(), cmp);
				topk[k - 1] = rec[i];
				push_heap(topk.begin(), topk.end(), cmp);
			}
		}
		return topk;
	}
};

void main() {
	vector<int> rec;
	rec.push_back(98);
	rec.push_back(78);
	rec.push_back(57);
	rec.push_back(65);
	rec.push_back(76);
	rec.push_back(87);
	Solution slu;
	vector<int> topk = slu.topK(rec, 3);
	for (auto mark : topk)
		cout << mark << endl;
}