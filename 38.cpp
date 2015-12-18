#include <string>
using std::string;
#pragma warning(disable:4996)

extern "C" string countAndSay(int n);

string countAndSay(int n) {
	string str = "1";
	for (int i = 0; i < n - 1; i++) {
		string str_new = "";
		int j = 0;
		int cnt = 1;
		char cnt_str[10 + 1] = { 0 };
		char num_str[2] = { 0 };
		while (j < str.length() - 1) {
			if (str[j] == str[j + 1]) {
				cnt++;
				j++;
			}
			else {
				sprintf(cnt_str, "%d", cnt);
				str_new += cnt_str + str[j];
				cnt = 1;
				j++;
			}
		}
		sprintf(cnt_str, "%d", cnt);
		num_str[0] = str[j];
		
		str = str_new;
	}
	return str;
}