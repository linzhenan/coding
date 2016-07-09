#include <cstdint>
#include <stdio.h>

#define MAXN 100000

const int root = 1;
struct Node {
	int flag;
	int pri;
	int next[2];
}node[MAXN * 32] = { 0 };

int priCnt = 0;
int nodeCnt = 2;
void add(int ip, int mask, int flag) {
	int p = root;
	int i;
	int k = 31;
	while (mask--) {
		i = (ip >> k) & 1;
		if (!node[p].next[i])
			node[p].next[i] = nodeCnt++;
		p = node[p].next[i];
		k--;
	}

	if (!node[p].flag) {
		node[p].flag = flag;
		node[p].pri = priCnt++;
	}
}

int query(int ip) {
	int p, mask;
	int minpri = 1000000;
	int flag = 1;
	mask = 32;
	p = root;

	while (mask >= 0 && p) {
		if (node[p].flag && node[p].pri < minpri) {
			minpri = node[p].pri;
			flag = node[p].flag;
		}
		mask--;
		p = node[p].next[(ip >> mask) & 1];
	}

	return flag;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	char msg[16], msk[16];
	int a[4], mask, ip, flag;

	while (n--) {
		scanf("%s%d.%d.%d.%d%s", msg, &a[0], &a[1], &a[2], &a[3], msk);
		ip = (a[0] << 24) | (a[1] << 16) | (a[2] << 8) | (a[3]);
		mask = 32;
		if (msk[0] == '/') sscanf(&msk[1], "%d", &mask);
		if (msg[0] == 'a') flag = 1;
		else if (msg[0] == 'd') flag = 2;
		else flag = 0;
		add(ip, mask, flag);
	}

	while (m--) {
		scanf("%d.%d.%d.%d", &a[0], &a[1], &a[2], &a[3]);
		ip = (a[0] << 24) | (a[1] << 16) | (a[2] << 8) | (a[3]);
		if (query(ip) <= 1)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;

}