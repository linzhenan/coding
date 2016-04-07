#include <iostream>

using namespace std;

struct Candidate {
	int id;
	char gender;
	int value;
	int salary;
	double ratio
};

#define N 100
Candidate cand[N];

int main() {
	int n, males, females, barget;
	cin >> n >> males >> females >> barget;
	for (int i = 0; i < n; i++) {
		cand[i].id = i;
		cin >> cand[i].gender >> cand[i].value >> cand[i].salary;
		cand[i].ratio = 1.0 * cand[i].value / cand[i].salary;
	}


	return 0;
}