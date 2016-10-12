#include <vector>
#include <set>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;


class Event {
public:
	int index;
	long long studentNumber;
	int arriveTime;
	int step;
	Event(int idx, long long stuNum, int arrTime) {
		index = idx;
		studentNumber = stuNum;
		arriveTime = arrTime;
		step = 0;
	}
};

struct cmp
{
	bool operator()(Event a, Event b) {
		if (a.arriveTime > b.arriveTime)
			return true;
		else if (a.arriveTime < b.arriveTime)
			return false;
		else {
			if (a.studentNumber > b.studentNumber)
				return true;
			else
				return false;
		}
	}
};

#define MAXN 10000
#define MAXM 100
#define MAXK 1000

long long S[MAXN + 1];
int T[MAXN + 1];
int P[MAXN + 1];

int N, M, K;
int W[MAXN + 1][MAXM + 1];
int O[MAXN + 1][MAXM + 1];

int earliest[MAXM + 1] = { 0 };
int finished[MAXN + 1] = { 0 };

int main() {

	priority_queue<Event, vector<Event>, cmp> q;

	/*
	Event e1(1, 1);
	Event e2(2, 0);
	Event e3(2, 1);
	Event e4(3, 3);
	Event e5(3, 2);
	
	q.push(e5);
	q.push(e1);
	q.push(e2);
	q.push(e4);
	q.push(e3);

	while (!q.empty()) {
		Event e = q.top();
		cout << e.arriveTime << " : " << e.studentNumber << endl;
		q.pop();
	}
	*/

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		cin >> S[i] >> T[i] >> P[i];
		q.push(Event(i, S[i], T[i]));
		for (int j = 1; j <= P[i]; j++)
			cin >> O[i][j] >> W[i][j];
	}

	while (!q.empty()) {
		Event e = q.top();
		q.pop();

		//cout << e.studentNumber << " : " << e.arriveTime << endl;

		if (!e.step) {
			e.arriveTime += K;
			e.step++;
			q.push(e);
		}
		else {
			int office = O[e.index][e.step];
			if (earliest[office] <= e.arriveTime)
				earliest[office] = e.arriveTime + W[e.index][e.step];
			else
				earliest[office] += W[e.index][e.step];
			if (e.step == P[e.index]) {
				finished[e.index] = earliest[office];
			}
			else {
				e.arriveTime = earliest[office] + K;
				e.step++;
				q.push(e);
			}
		}
	}

	for (int i = 1; i <= N; i++)
		cout << finished[i] << endl;

	return 0;
}