#include <iostream>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <memory.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <math.h>
#include <set>
#include <stack>
using namespace::std;

#pragma warning(disable:4996)

int main() {

	//fstream Fout("d:\\try.txt", ios::out);
	//fstream Fin("d:\\C-small-attempt3.in", ios::in);

	int T = 0;
	int N = 0;
	string statement;

	map<int, set<string>> inSets;
	map<string, set<int>> outSets;
	vector<string> LL;
	queue<int> validPars;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		inSets.clear();
		outSets.clear();
		LL.clear();
		while (!validPars.empty()) {
			validPars.pop();
		}

		for (int j = 0; j < N; j++) {
			cin >> statement;
			int mark1 = 0;
			string retPar = "";
			string temp = "";
			for (int x = 0; x < statement.size(); x++) {
				if (statement[x] == '=') {
					retPar = statement.substr(0, x);
					LL.push_back(retPar);
					if (inSets.find(j) == inSets.end()) {
						inSets[j] = set<string>();
					}
				}
				else if (statement[x] == '(') {
					mark1 = x + 1;
				}
				else if ((statement[x] == ',' || statement[x] == ')') && x > mark1) {
					temp = statement.substr(mark1, x - mark1);
					inSets[j].insert(temp);
					outSets[temp].insert(j);
					mark1 = x + 1;
				}
			}
		}
		for (auto s : inSets) {
			if (s.second.size() == 0) {
				validPars.push(s.first);
			}
		}

		while (!validPars.empty()) {
			int temp = validPars.front();
			validPars.pop();
			if (outSets.find(LL[temp]) != outSets.end()) {
				for (auto s : outSets[LL[temp]]) {
					if (inSets.find(s) != inSets.end()) {
						inSets[s].erase(LL[temp]);
						if (inSets[s].size() == 0) {
							validPars.push(s);
						}
					}
				}
			}
			inSets.erase(temp);
		}
		if (inSets.empty()) cout << "Case #" << i + 1 << ": GOOD\n";
		else cout << "Case #" << i + 1 << ": BAD\n";
	}
	//cout.close();
}