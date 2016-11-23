#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

enum Status
{
	UP = 0,
	STAY = 1,
	DOWN = 2,
};

struct User
{
	int id;//idx
	int t;//time
	int s;//start
	int e;//end
	int r;//reach
};

class cmp {
	public operator()(const User* &u1, const User* &u2) {

	}
};
int main()
{
	Status curStat = STAY;
	priority_queue<User*, vector<User*>> up;
	priority_queue<User*, vector<User*>> down;
	priority_queue<User*, vector<User*>> wait;

	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			
		}
	}

	return 0;
}