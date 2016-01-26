#include <string>
#include <list>
#include <iostream>

using namespace std;

class solution {
public:
	string list2str(list<string> list) {
		string str = "";
		for (auto substr : list) {
			for (int i = 0; i < substr.size(); i++) {
				if (substr[i] == '\\')
					str += "\\\\";
				else if (substr[i] == '#')
					str += "\\#";
				else
					str += substr[i];
			}
			str += '#';
		}
		return str;
	}
	list<string> str2list(string str) {
		list<string> list;
		string substr = "";
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '\\') {
				i++;
				substr += str[i];
			}
			else if (str[i] == '#') {
				list.push_back(substr);
				substr.clear();
			}
			else {
				substr += str[i];
			}
		}
		return list;
	}
};


void main() {
	list<string> list1, list2;
	string str;
	solution slu;

	for (int i = 0; i < 256; i++)
		str += (char)i;
	list1.push_back(str);
	list1.push_back(str + '#');
	cout << "list1: " << endl;
	for (auto substr : list1)
		cout << substr << endl;

	str = slu.list2str(list1);
	cout << "serialize: " << endl;
	cout << str << endl;

	list2 = slu.str2list(str);
	cout << "list2: " << endl;
	for (auto substr : list2)
		cout << substr << endl;
}