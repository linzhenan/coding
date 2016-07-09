#include <vector>
#include <unordered_map>
#include <iostream>

#pragma warning(disable:4996)
using namespace std;

void dfs(int sig, unordered_map<int, vector<int>> &module_sig, unordered_map<int, int> &module_cnt) {
	if (module_sig.find(sig) == module_sig.end())
		return;
	module_cnt[sig]++;
	if (module_cnt[sig] == 142857)
		module_cnt[sig] = 0;
	for (auto subsig : module_sig[sig])
		dfs(subsig, module_sig, module_cnt);
}

int main() {
	int T, N, M;
	vector<int> sig;
	vector<int> module_idx;
	unordered_map<int, vector<int>> module_sig;
	unordered_map<int, int> module_cnt;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {//������������
		module_idx.clear();
		module_cnt.clear();
		module_sig.clear();
		scanf("%d", &N);//ģ������
		scanf("%d", &M);//��ʼ�ź�����
		for (int j = 0; j < M; j++) {//��ʼ�ź�
			int tmp;
			scanf("%d", &tmp);
			sig.push_back(tmp);
		}
		int S, K;
		for (int j = 0; j < N; j++) {//ģ������
			scanf("%d", &S);//�����ź�
			scanf("%d", &K);//�����ź�����
			module_idx.push_back(S);
			int tmp;
			for (int k = 0; k < K; k++) {
				scanf("%d", &tmp);
				module_sig[S].push_back(tmp);
			}
		}
		for (auto subsig : sig) {
			dfs(subsig, module_sig, module_cnt);
		}
		for (int j = 0; j < N - 1; j++)
			printf("%d ", module_cnt[module_idx[j]]);
		printf("%d\n", module_cnt[module_idx[N - 1]]);
	}
	return 0;
}