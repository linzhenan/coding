#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> noDuplicatedElements(vector<int> l1, vector<int> l2) {
		int i = 0;
		int j = 0;
		vector<int> l;
		while (i < l1.size() || j < l2.size()) {
			if (i < l1.size() && j < l2.size()) {
				if (l1[i] == l2[j]) {
					i++;
					j++;
				}
				else if (l1[i] < l2[j]) {
					l.push_back(l1[i++]);
				}
				else if (l1[i] > l2[j]) {
					l.push_back(l2[j++]);
				}
			}
			else if (i < l1.size()) {
				l.push_back(l1[i++]);
			}
			else if (j < l2.size()) {
				l.push_back(l2[j++]);
			}
		}
		return l;
	}
};

void main() {
	vector<int> l1;
	vector<int> l2;

	l1.push_back(1);
	l1.push_back(3);
	l1.push_back(7);

	l2.push_back(2);
	l2.push_back(3);
	l2.push_back(4);
	l2.push_back(7);

	Solution slu;
	vector<int> l = slu.noDuplicatedElements(l1, l2);
	for (auto e : l)
		cout << e << " ";
	cout << endl;
}