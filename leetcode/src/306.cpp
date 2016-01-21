//Additive Number

#include <vector>
#include <string>
#include <limits>

using namespace std;

class Solution {
public:
	int max(int a, int b) {
		if (a > b)
			return a;
		else
			return b;
	}
	string getSum(string s1, string s2) {
		string s;
		int i = s1.size() - 1;
		int j = s2.size() - 1;
		int c = 0;
		while (i >= 0 || j >= 0 || c) {
			int num1 = i >= 0 ? s1[i] - '0' : 0;
			int num2 = j >= 0 ? s2[j] - '0' : 0;
			c = c + num1 + num2;
			s = (char)(c % 10 + '0') + s;
			c = c / 10;
			i--;
			j--;
		}
		return s;
	}
	bool isAdditiveNumber(string& num, int pos, int len1, int len2) {
		int len3max = num.size() - (pos + len1 + len2);
		if (len3max < max(len1, len2))
			return false;
		int pos1 = pos;
		int pos2 = pos1 + len1;
		int pos3 = pos2 + len2;
		string s1 = num.substr(pos1, len1);
		string s2 = num.substr(pos2, len2);
		if (len1 > 1 && s1[0] == '0' ||
			len2 > 1 && s2[0] == '0')
			return false;
		string s3 = getSum(s1, s2);
		int len3 = s3.size();
		if (len3max < len3)
			return false;
		string s = num.substr(pos3, len3);
		if (len3 > 1 && s[0] == '0' || s != s3)
			return false;
		if (pos3 + len3 == num.size())
			return true;
		return isAdditiveNumber(num, pos2, len2, len3);
	}
	bool isAdditiveNumber(string num) {
		for (int len1 = 1; len1 <= num.size() / 2; len1++)
			for (int len2 = 1; len2 < num.size() - len1; len2++)
				if (isAdditiveNumber(num, 0, len1, len2))
					return true;
		return false;
	}
};

void main() {
	Solution slu;
	slu.isAdditiveNumber("112358");
}