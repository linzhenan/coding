#include <vector>
#include <string>
#include <iostream>

#pragma warning(disable:4996)

using namespace std;

#define N_MAX 1000
struct FileContext {
	int inDegree;
	int outDegree;
	FileContext **outEdge;
	char fileName[11];
	bool isOutput;
};

void main(void) {
	FileContext *fctx;
	FileContext **pctx;
	vector<char*> res;
	int T, N;

	fctx = (FileContext*)malloc(sizeof(FileContext) * N_MAX);
	pctx = (FileContext **)malloc(sizeof(FileContext*) * N_MAX);
	for (int i = 0; i < N_MAX; i++)
		fctx[i].outEdge = (FileContext **)malloc(sizeof(FileContext*) * N_MAX);

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		for (int i = 0; i < N_MAX; i++) {
			fctx[i].isOutput = false;
			fctx[i].inDegree = 0;
			fctx[i].outDegree = 0;
		}
		res.clear();
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			int m;
			scanf("%s %d", fctx[j].fileName, &m);
			fctx[j].inDegree = m;
			for (int k = 0; k < m; k++) {
				int idx;
				scanf("%d", &idx);
				fctx[idx].outEdge[fctx[idx].outDegree++] = &fctx[j];
			}
			pctx[j] = &fctx[j];
		}
		for (int j = 0; j < N - 1; j++)
			for (int k = 0; k < N - 1 - j; k++) {
				if (strcmp(pctx[k]->fileName, pctx[k + 1]->fileName) > 0) {
					FileContext *tmp = pctx[k];
					pctx[k] = pctx[k + 1];
					pctx[k + 1] = tmp;
				}
			}
		int cnt = 0;
		int cnt_last = -1;
		while (cnt_last != cnt) {
			cnt_last = cnt;
			for (int j = 0; j < N; j++) {
				if (pctx[j]->isOutput || pctx[j]->inDegree != 0)
					continue;
				for (int k = 0; k < pctx[j]->outDegree; k++)
					pctx[j]->outEdge[k]->inDegree--;
				res.push_back(pctx[j]->fileName);
				pctx[j]->isOutput = true;
				cnt++;
				break;
			}
		}
		if (cnt == N) {
			for (int j = 0; j < N; j++)
				printf("%s\n", res[j]);
		}
		else {
			printf("ERROR\n");
		}
	}

	for (int i = 0; i < N_MAX; i++)
		free(fctx[i].outEdge);
	free(fctx);
	free(pctx);
}