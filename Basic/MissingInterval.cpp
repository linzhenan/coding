#include <vector>
#include <sstream>
#include <iostream>
#include <stdint.h>

using namespace std;

class solution {
public:
	vector<string> missingInterval(vector<int> num) {
		vector<string> res;
		vector<bool> exist = vector<bool>(100, false);
		for (int i = 0; i < num.size(); i++)
			exist[num[i]] = true;
		int missPos = 0, apprPos = 0;
		while (apprPos < 100) {
			for (; missPos < 100; missPos++)
				if (!exist[missPos])
					break;
			for (apprPos = missPos + 1; apprPos < 100; apprPos++)
				if (exist[apprPos])
					break;
			if (missPos < 100) {
				stringstream ss;
				if (missPos == apprPos - 1) {
					ss << missPos;
				}
				else {
					ss << missPos;
					ss << '-';
					ss << apprPos - 1;
				}
				res.push_back(ss.str());
			}
			missPos = apprPos + 1;
		}
		return res;
	}
};

void main() {
	solution slu;
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(98);
	num.push_back(99);
	vector<string> res = slu.missingInterval(num);
	for (auto str : res)
		cout << str << endl;
}